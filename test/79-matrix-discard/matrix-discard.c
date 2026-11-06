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


static int   check_color( unsigned char *pixel, int r, int g, int b,
                          const char *what)
{
   if( pixel[ 0] != r || pixel[ 1] != g ||
       pixel[ 2] != b || pixel[ 3] != 255)
   {
      fprintf( stderr, "%s gave %u,%u,%u,%u\n", what,
               (unsigned int) pixel[ 0], (unsigned int) pixel[ 1],
               (unsigned int) pixel[ 2], (unsigned int) pixel[ 3]);
      return( 1);
   }
   return( 0);
}


int   main( int argc, char *argv[])
{
   static const char   *vertex_source =
      "#version 100\n"
      "attribute vec2 aPos;\n"
      "uniform mat4 uMatrix;\n"
      "void main()\n"
      "{\n"
      "   gl_Position = uMatrix * vec4( aPos, 0.0, 1.0);\n"
      "}\n";
   static const char   *fragment_source =
      "#version 100\n"
      "precision mediump float;\n"
      "uniform vec4 uColor;\n"
      "uniform int uDiscard;\n"
      "void main()\n"
      "{\n"
      "   if( uDiscard != 0 && gl_FragCoord.x < 32.0)\n"
      "      discard;\n"
      "   gl_FragColor = uColor;\n"
      "}\n";
   static const float   positions[ 8] =
      { -1.0f, -1.0f,  1.0f, -1.0f,  -1.0f, 1.0f,  1.0f, 1.0f };
   static const float   scaled[ 16] =
      { 0.5f, 0.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f };
   static const float   identity[ 16] =
      { 1.0f, 0.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f };
   static const float   green[ 4] = { 0.0f, 1.0f, 0.0f, 1.0f };
   unsigned char   pixel[ 4];
   gl_es2_int      color_location;
   gl_es2_int      discard_location;
   gl_es2_int      matrix_location;
   gl_es2_uint     fragment_shader;
   gl_es2_uint     program;
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
   aex_gl_es2_LinkProgram( program);
   if( check_program( program))
      return( 1);

   aex_gl_es2_UseProgram( program);

   matrix_location = aex_gl_es2_GetUniformLocation( program, "uMatrix");
   color_location = aex_gl_es2_GetUniformLocation( program, "uColor");
   discard_location = aex_gl_es2_GetUniformLocation( program, "uDiscard");
   if( matrix_location < 0 || color_location < 0 || discard_location < 0)
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
   aex_gl_es2_ClearColor( 0.0f, 0.0f, 0.0f, 1.0f);
   aex_gl_es2_Clear( GL_ES2_COLOR_BUFFER_BIT);

   aex_gl_es2_Uniform4fv( color_location, 1, green);
   aex_gl_es2_Uniform1i( discard_location, 0);
   aex_gl_es2_UniformMatrix4fv( matrix_location, 1, GL_ES2_FALSE, scaled);
   aex_gl_es2_DrawArrays( GL_ES2_TRIANGLE_STRIP, 0, 4);

   aex_gl_es2_ReadPixels( 32, 32, 1, 1, GL_ES2_RGBA, GL_ES2_UNSIGNED_BYTE,
                          pixel);
   if( check_color( pixel, 0, 255, 0, "matrix center"))
      return( 1);

   aex_gl_es2_ReadPixels( 8, 32, 1, 1, GL_ES2_RGBA, GL_ES2_UNSIGNED_BYTE,
                          pixel);
   if( check_color( pixel, 0, 0, 0, "matrix left"))
      return( 1);

   aex_gl_es2_ReadPixels( 56, 32, 1, 1, GL_ES2_RGBA, GL_ES2_UNSIGNED_BYTE,
                          pixel);
   if( check_color( pixel, 0, 0, 0, "matrix right"))
      return( 1);

   aex_gl_es2_Clear( GL_ES2_COLOR_BUFFER_BIT);

   aex_gl_es2_Uniform1i( discard_location, 1);
   aex_gl_es2_UniformMatrix4fv( matrix_location, 1, GL_ES2_FALSE, identity);
   aex_gl_es2_DrawArrays( GL_ES2_TRIANGLE_STRIP, 0, 4);

   aex_gl_es2_ReadPixels( 8, 32, 1, 1, GL_ES2_RGBA, GL_ES2_UNSIGNED_BYTE,
                          pixel);
   if( check_color( pixel, 0, 0, 0, "discard left"))
      return( 1);

   aex_gl_es2_ReadPixels( 56, 32, 1, 1, GL_ES2_RGBA, GL_ES2_UNSIGNED_BYTE,
                          pixel);
   if( check_color( pixel, 0, 255, 0, "discard right"))
      return( 1);

   if( aex_gl_es2_GetError() != GL_ES2_NO_ERROR)
   {
      fprintf( stderr, "glGetError reported an error\n");
      return( 1);
   }

   aex_gl_es2_DeleteShader( vertex_shader);
   aex_gl_es2_DeleteShader( fragment_shader);
   aex_gl_es2_DeleteProgram( program);

   printf( "headless GLES2 matrix and discard OK\n");
   return( 0);
}
