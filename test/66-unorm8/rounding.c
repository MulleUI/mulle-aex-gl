#include <mulle-aex-gl/gl_es2_impl.h>

#include <stdio.h>


//
// The fragment shader output is a float, the framebuffer stores bytes. The
// conversion lives in aex_float_to_unorm8 (primitive_assembly.c) and must
// round to nearest, not truncate: 255 * 0.99999988f is 254.99997 as a float,
// which truncation turns into 254. Antialiased fills and interpolated colors
// land a hair below 1.0 all the time and then wrote 254/255 instead of 255/255.
//
// Run a full screen quad through the shader interpreter, so the real store
// path is exercised, and read the center pixel back.
//
struct probe
{
   float          r, g, b, a;
   unsigned char  expect_r, expect_g, expect_b, expect_a;
   const char    *what;
};


static int   check_program( gl_es2_uint program)
{
   gl_es2_char   log[512];
   gl_es2_int    status;
   gl_es2_sizei  length;

   aex_gl_es2_GetProgramiv( program, GL_ES2_LINK_STATUS, &status);
   if( status)
      return( 0);

   aex_gl_es2_GetProgramInfoLog( program, sizeof( log), &length, log);
   log[ length < sizeof( log) ? length : sizeof( log) - 1] = 0;
   fprintf( stderr, "program link failed: %s\n", log);
   return( 1);
}


int   main( int argc, char *argv[])
{
   static const struct probe   probes[] =
   {
      // the regression: truncation gives 254, rounding gives 255
      { 0.99999988f, 0.99999988f, 0.99999988f, 0.99999988f,
        255, 255, 255, 255, "just below 1.0" },
      // ordinary values that are not exact multiples of 1/255
      { 0.5f, 0.25f, 0.75f, 1.0f, 128, 64, 191, 255, "half steps" },
      { 0.0f, 1.0f, 0.0f, 1.0f, 0, 255, 0, 255, "bounds" },
      // ES 2.0 2.1.2: colors are clamped to [0,1], then converted
      { 1.25f, -0.5f, 0.6f, 2.0f, 255, 0, 153, 255, "out of range" }
   };
   static const char   *vertex_source =
      "#version 100\n"
      "attribute vec2 aPos;\n"
      "void main()\n"
      "{\n"
      "   gl_Position = vec4( aPos, 0.0, 1.0);\n"
      "}\n";
   static const char   *fragment_source =
      "#version 100\n"
      "precision highp float;\n"
      "uniform vec4 uColor;\n"
      "void main()\n"
      "{\n"
      "   gl_FragColor = uColor;\n"
      "}\n";
   static const float   vertices[12] =
      { -1.0f, -1.0f,  1.0f, -1.0f, -1.0f, 1.0f,
        -1.0f,  1.0f,  1.0f, -1.0f,  1.0f, 1.0f };
   unsigned char   pixel[4];
   gl_es2_int      location;
   gl_es2_uint     program;
   gl_es2_uint     vertex_shader;
   gl_es2_uint     fragment_shader;
   gl_es2_uint     buffer;
   size_t          i;
   int             r;

   r = aex_gl_es2_context_init( 32, 0, 32, 64, 64);
   if( r)
   {
      fprintf( stderr, "aex_gl_es2_context_init failed: %d\n", r);
      return( 1);
   }

   vertex_shader = aex_gl_es2_CreateShader( GL_ES2_VERTEX_SHADER);
   aex_gl_es2_ShaderSource( vertex_shader, 1, &vertex_source, NULL);
   aex_gl_es2_CompileShader( vertex_shader);

   fragment_shader = aex_gl_es2_CreateShader( GL_ES2_FRAGMENT_SHADER);
   aex_gl_es2_ShaderSource( fragment_shader, 1, &fragment_source, NULL);
   aex_gl_es2_CompileShader( fragment_shader);

   program = aex_gl_es2_CreateProgram();
   aex_gl_es2_AttachShader( program, vertex_shader);
   aex_gl_es2_AttachShader( program, fragment_shader);
   aex_gl_es2_BindAttribLocation( program, 0, "aPos");
   aex_gl_es2_LinkProgram( program);
   if( check_program( program))
      return( 1);

   aex_gl_es2_UseProgram( program);

   location = aex_gl_es2_GetUniformLocation( program, "uColor");
   if( location < 0)
   {
      fprintf( stderr, "uColor uniform not found\n");
      return( 1);
   }

   aex_gl_es2_GenBuffers( 1, &buffer);
   aex_gl_es2_BindBuffer( GL_ES2_ARRAY_BUFFER, buffer);
   aex_gl_es2_BufferData( GL_ES2_ARRAY_BUFFER,
                          sizeof( vertices),
                          vertices,
                          GL_ES2_STATIC_DRAW);

   aex_gl_es2_EnableVertexAttribArray( 0);
   aex_gl_es2_VertexAttribPointer( 0, 2, GL_ES2_FLOAT, GL_ES2_FALSE, 0, NULL);

   aex_gl_es2_Viewport( 0, 0, 64, 64);

   for( i = 0; i < sizeof( probes) / sizeof( probes[0]); ++i)
   {
      aex_gl_es2_ClearColor( 0.0f, 0.0f, 0.0f, 0.0f);
      aex_gl_es2_Clear( GL_ES2_COLOR_BUFFER_BIT |
                        GL_ES2_DEPTH_BUFFER_BIT |
                        GL_ES2_STENCIL_BUFFER_BIT);

      aex_gl_es2_Uniform4f( location, probes[i].r, probes[i].g,
                            probes[i].b, probes[i].a);
      aex_gl_es2_DrawArrays( GL_ES2_TRIANGLES, 0, 6);

      aex_gl_es2_ReadPixels( 32, 32, 1, 1, GL_ES2_RGBA, GL_ES2_UNSIGNED_BYTE, pixel);

      if( pixel[0] != probes[i].expect_r || pixel[1] != probes[i].expect_g ||
          pixel[2] != probes[i].expect_b || pixel[3] != probes[i].expect_a)
      {
         fprintf( stderr,
                  "%s: color %.8f,%.8f,%.8f,%.8f gave %u,%u,%u,%u, expected %u,%u,%u,%u\n",
                  probes[i].what,
                  (double) probes[i].r, (double) probes[i].g,
                  (double) probes[i].b, (double) probes[i].a,
                  (unsigned int) pixel[0], (unsigned int) pixel[1],
                  (unsigned int) pixel[2], (unsigned int) pixel[3],
                  (unsigned int) probes[i].expect_r, (unsigned int) probes[i].expect_g,
                  (unsigned int) probes[i].expect_b, (unsigned int) probes[i].expect_a);
         return( 1);
      }
   }

   printf( "headless GLES2 unorm8 rounding OK\n");
   return( 0);
}
