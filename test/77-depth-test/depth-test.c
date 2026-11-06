#include <mulle-aex-gl/gl_es2_impl.h>

#include <stdio.h>


static int   check_shader( gl_es2_uint shader)
{
   gl_es2_char   log[ 512];
   gl_es2_int    status;
   gl_es2_sizei  length;

   aex_gl_es2_GetShaderiv( shader, GL_ES2_COMPILE_STATUS, &status);
   if( status)
      return( 0);

   aex_gl_es2_GetShaderInfoLog( shader, sizeof( log), &length, log);
   log[ length < sizeof( log) ? length : sizeof( log) - 1] = 0;
   fprintf( stderr, "shader compile failed: %s\n", log);
   return( 1);
}


static int   check_program( gl_es2_uint program)
{
   gl_es2_char   log[ 512];
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


static int   check_pixel( unsigned char *pixel, const char *what)
{
   if( pixel[ 0] != 0 || pixel[ 1] != 255 ||
       pixel[ 2] != 0 || pixel[ 3] != 255)
   {
      fprintf( stderr, "%s gave %u,%u,%u,%u\n", what,
               (unsigned int) pixel[ 0], (unsigned int) pixel[ 1],
               (unsigned int) pixel[ 2], (unsigned int) pixel[ 3]);
      return( 1);
   }
   return( 0);
}


static int   check_depth( unsigned int depth, unsigned int lo,
                          unsigned int hi, const char *what)
{
   if( depth < lo || depth > hi)
   {
      fprintf( stderr, "%s depth is 0x%08x\n", what, depth);
      return( 1);
   }
   return( 0);
}


int   main( int argc, char *argv[])
{
   static const char   *vertex_source =
      "#version 100\n"
      "attribute vec2 aPos;\n"
      "uniform float uZ;\n"
      "void main()\n"
      "{\n"
      "   gl_Position = vec4( aPos, uZ, 1.0);\n"
      "}\n";
   static const char   *fragment_source =
      "#version 100\n"
      "precision mediump float;\n"
      "uniform vec4 uColor;\n"
      "void main()\n"
      "{\n"
      "   gl_FragColor = uColor;\n"
      "}\n";
   static const float   positions[ 8] =
      { -1.0f, -1.0f,  1.0f, -1.0f,  -1.0f, 1.0f,  1.0f, 1.0f };
   unsigned char   pixel[ 4];
   unsigned int    depth;
   unsigned int    far_depth;
   unsigned int    near_depth;
   gl_es2_int      color_location;
   gl_es2_int      z_location;
   gl_es2_uint     fragment_shader;
   gl_es2_uint     program;
   gl_es2_uint     vertex_shader;
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
   if( check_shader( vertex_shader))
      return( 1);

   fragment_shader = aex_gl_es2_CreateShader( GL_ES2_FRAGMENT_SHADER);
   aex_gl_es2_ShaderSource( fragment_shader, 1, &fragment_source, NULL);
   aex_gl_es2_CompileShader( fragment_shader);
   if( check_shader( fragment_shader))
      return( 1);

   program = aex_gl_es2_CreateProgram();
   aex_gl_es2_AttachShader( program, vertex_shader);
   aex_gl_es2_AttachShader( program, fragment_shader);
   aex_gl_es2_BindAttribLocation( program, 0, "aPos");
   aex_gl_es2_LinkProgram( program);
   if( check_program( program))
      return( 1);

   aex_gl_es2_UseProgram( program);

   z_location = aex_gl_es2_GetUniformLocation( program, "uZ");
   color_location = aex_gl_es2_GetUniformLocation( program, "uColor");
   if( z_location < 0 || color_location < 0)
   {
      fprintf( stderr, "uniform not found\n");
      return( 1);
   }

   aex_gl_es2_EnableVertexAttribArray( 0);
   aex_gl_es2_VertexAttribPointer( 0,
                                   2,
                                   GL_ES2_FLOAT,
                                   GL_ES2_FALSE,
                                   0,
                                   positions);

   aex_gl_es2_Viewport( 0, 0, 64, 64);
   aex_gl_es2_Enable( GL_ES2_DEPTH_TEST);
   aex_gl_es2_DepthFunc( GL_ES2_LESS);
   aex_gl_es2_ClearDepthf( 1.0f);

   aex_gl_es2_ClearColor( 0.0f, 0.0f, 0.0f, 1.0f);
   aex_gl_es2_Clear( GL_ES2_COLOR_BUFFER_BIT | GL_ES2_DEPTH_BUFFER_BIT);

   aex_gl_es2_Uniform1f( z_location, 0.5f);
   aex_gl_es2_Uniform4f( color_location, 1.0f, 0.0f, 0.0f, 1.0f);
   aex_gl_es2_DrawArrays( GL_ES2_TRIANGLE_STRIP, 0, 4);

   far_depth = 0;
   aex_gl_es2_ReadPixels( 32, 32, 1, 1, GL_ES2_DEPTH_COMPONENT,
                          GL_ES2_UNSIGNED_INT, &far_depth);
   if( check_depth( far_depth, 0xBF000000, 0xC1000000, "far"))
      return( 1);

   aex_gl_es2_Uniform1f( z_location, 0.0f);
   aex_gl_es2_Uniform4f( color_location, 0.0f, 1.0f, 0.0f, 1.0f);
   aex_gl_es2_DrawArrays( GL_ES2_TRIANGLE_STRIP, 0, 4);

   aex_gl_es2_ReadPixels( 32, 32, 1, 1, GL_ES2_RGBA, GL_ES2_UNSIGNED_BYTE,
                          pixel);
   if( check_pixel( pixel, "far then near"))
      return( 1);

   near_depth = 0;
   aex_gl_es2_ReadPixels( 32, 32, 1, 1, GL_ES2_DEPTH_COMPONENT,
                          GL_ES2_UNSIGNED_INT, &near_depth);
   if( check_depth( near_depth, 0x7F000000, 0x81000000, "far then near"))
      return( 1);
   if( ! (near_depth < far_depth))
   {
      fprintf( stderr, "near depth 0x%08x not less than far depth 0x%08x\n",
               near_depth, far_depth);
      return( 1);
   }

   aex_gl_es2_Clear( GL_ES2_COLOR_BUFFER_BIT | GL_ES2_DEPTH_BUFFER_BIT);

   aex_gl_es2_Uniform1f( z_location, 0.0f);
   aex_gl_es2_Uniform4f( color_location, 0.0f, 1.0f, 0.0f, 1.0f);
   aex_gl_es2_DrawArrays( GL_ES2_TRIANGLE_STRIP, 0, 4);

   near_depth = 0;
   aex_gl_es2_ReadPixels( 32, 32, 1, 1, GL_ES2_DEPTH_COMPONENT,
                          GL_ES2_UNSIGNED_INT, &near_depth);
   if( check_depth( near_depth, 0x7F000000, 0x81000000, "near"))
      return( 1);

   aex_gl_es2_Uniform1f( z_location, 0.5f);
   aex_gl_es2_Uniform4f( color_location, 1.0f, 0.0f, 0.0f, 1.0f);
   aex_gl_es2_DrawArrays( GL_ES2_TRIANGLE_STRIP, 0, 4);

   aex_gl_es2_ReadPixels( 32, 32, 1, 1, GL_ES2_RGBA, GL_ES2_UNSIGNED_BYTE,
                          pixel);
   if( check_pixel( pixel, "near then far"))
      return( 1);

   depth = 0;
   aex_gl_es2_ReadPixels( 32, 32, 1, 1, GL_ES2_DEPTH_COMPONENT,
                          GL_ES2_UNSIGNED_INT, &depth);
   if( check_depth( depth, 0x7F000000, 0x81000000, "near then far"))
      return( 1);
   if( depth != near_depth)
   {
      fprintf( stderr, "far overwrote near depth 0x%08x with 0x%08x\n",
               near_depth, depth);
      return( 1);
   }

   if( aex_gl_es2_GetError() != GL_ES2_NO_ERROR)
   {
      fprintf( stderr, "glGetError reported an error\n");
      return( 1);
   }

   aex_gl_es2_DeleteShader( vertex_shader);
   aex_gl_es2_DeleteShader( fragment_shader);
   aex_gl_es2_DeleteProgram( program);

   printf( "headless GLES2 depth test OK\n");
   return( 0);
}
