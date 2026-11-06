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


int   main( int argc, char *argv[])
{
   static const char   *vertex_source =
      "#version 100\n"
      "attribute vec2 aPos;\n"
      "attribute vec2 aUV;\n"
      "varying vec2 vUV;\n"
      "void main()\n"
      "{\n"
      "   vUV = aUV * 256.0;\n"
      "   gl_Position = vec4( aPos, 0.0, 1.0);\n"
      "}\n";
   static const char   *fragment_source =
      "#version 100\n"
      "precision mediump float;\n"
      "uniform sampler2D uSampler;\n"
      "varying vec2 vUV;\n"
      "void main()\n"
      "{\n"
      "   gl_FragColor = texture2D( uSampler, vUV);\n"
      "}\n";
   static const float   positions[ 8] =
      { -1.0f, -1.0f,  1.0f, -1.0f,  -1.0f, 1.0f,  1.0f, 1.0f };
   static const float   uvs[ 8] =
      { 0.0f, 0.0f,  1.0f, 0.0f,  0.0f, 1.0f,  1.0f, 1.0f };
   static const unsigned char   level0[ 2 * 2 * 3] =
      { 255, 0, 0,   255, 0, 0,
        255, 0, 0,   255, 0, 0 };
   static const unsigned char   level1[ 1 * 1 * 3] =
      { 0, 255, 0 };
   unsigned char   pixel[ 4];
   gl_es2_int      sampler_location;
   gl_es2_uint     fragment_shader;
   gl_es2_uint     program;
   gl_es2_uint     texture;
   gl_es2_uint     vertex_shader;
   int             r;

   r = aex_gl_es2_context_init( 32, 0, 0, 64, 64);
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
   aex_gl_es2_BindAttribLocation( program, 1, "aUV");
   aex_gl_es2_LinkProgram( program);
   if( check_program( program))
      return( 1);

   aex_gl_es2_UseProgram( program);

   sampler_location = aex_gl_es2_GetUniformLocation( program, "uSampler");
   if( sampler_location < 0)
   {
      fprintf( stderr, "uSampler uniform not found\n");
      return( 1);
   }
   aex_gl_es2_Uniform1i( sampler_location, 0);

   aex_gl_es2_PixelStorei( GL_ES2_UNPACK_ALIGNMENT, 1);
   aex_gl_es2_GenTextures( 1, &texture);
   aex_gl_es2_BindTexture( GL_ES2_TEXTURE_2D, texture);
   aex_gl_es2_TexParameteri( GL_ES2_TEXTURE_2D,
                             GL_ES2_TEXTURE_MIN_FILTER,
                             GL_ES2_LINEAR_MIPMAP_LINEAR);
   aex_gl_es2_TexParameteri( GL_ES2_TEXTURE_2D,
                             GL_ES2_TEXTURE_MAG_FILTER,
                             GL_ES2_NEAREST);
   aex_gl_es2_TexParameteri( GL_ES2_TEXTURE_2D,
                             GL_ES2_TEXTURE_WRAP_S,
                             GL_ES2_CLAMP_TO_EDGE);
   aex_gl_es2_TexParameteri( GL_ES2_TEXTURE_2D,
                             GL_ES2_TEXTURE_WRAP_T,
                             GL_ES2_CLAMP_TO_EDGE);
   aex_gl_es2_TexImage2D( GL_ES2_TEXTURE_2D, 0, GL_ES2_RGB, 2, 2, 0,
                          GL_ES2_RGB, GL_ES2_UNSIGNED_BYTE, level0);
   aex_gl_es2_TexImage2D( GL_ES2_TEXTURE_2D, 1, GL_ES2_RGB, 1, 1, 0,
                          GL_ES2_RGB, GL_ES2_UNSIGNED_BYTE, level1);

   aex_gl_es2_EnableVertexAttribArray( 0);
   aex_gl_es2_VertexAttribPointer( 0,
                                   2,
                                   GL_ES2_FLOAT,
                                   GL_ES2_FALSE,
                                   0,
                                   positions);
   aex_gl_es2_EnableVertexAttribArray( 1);
   aex_gl_es2_VertexAttribPointer( 1,
                                   2,
                                   GL_ES2_FLOAT,
                                   GL_ES2_FALSE,
                                   0,
                                   uvs);

   aex_gl_es2_Viewport( 0, 0, 64, 64);
   aex_gl_es2_ClearColor( 0.0f, 0.0f, 0.0f, 1.0f);
   aex_gl_es2_Clear( GL_ES2_COLOR_BUFFER_BIT);
   aex_gl_es2_DrawArrays( GL_ES2_TRIANGLE_STRIP, 0, 4);

   aex_gl_es2_ReadPixels( 32, 32, 1, 1, GL_ES2_RGBA, GL_ES2_UNSIGNED_BYTE,
                          pixel);
   if( pixel[ 0] != 0 || pixel[ 1] != 255 ||
       pixel[ 2] != 0 || pixel[ 3] != 255)
   {
      fprintf( stderr, "mipmapped sample gave %u,%u,%u,%u\n",
               (unsigned int) pixel[ 0], (unsigned int) pixel[ 1],
               (unsigned int) pixel[ 2], (unsigned int) pixel[ 3]);
      return( 1);
   }

   if( aex_gl_es2_GetError() != GL_ES2_NO_ERROR)
   {
      fprintf( stderr, "glGetError reported an error\n");
      return( 1);
   }

   aex_gl_es2_DeleteTextures( 1, &texture);
   aex_gl_es2_DeleteShader( vertex_shader);
   aex_gl_es2_DeleteShader( fragment_shader);
   aex_gl_es2_DeleteProgram( program);

   printf( "headless GLES2 mipmap sampling OK\n");
   return( 0);
}
