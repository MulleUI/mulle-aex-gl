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


static void   read_line_pixel( int x, unsigned char *pixel)
{
   unsigned char   rows[ 3 * 4];
   unsigned int    best;
   unsigned int    value;
   unsigned int    y;

   aex_gl_es2_ReadPixels( x, 31, 1, 3, GL_ES2_RGBA, GL_ES2_UNSIGNED_BYTE,
                          rows);
   best = 0;
   for( y = 0; y < 3; ++y)
   {
      value = rows[ y * 4 + 0] + rows[ y * 4 + 1] + rows[ y * 4 + 2];
      if( best < value)
      {
         best = value;
         pixel[ 0] = rows[ y * 4 + 0];
         pixel[ 1] = rows[ y * 4 + 1];
         pixel[ 2] = rows[ y * 4 + 2];
         pixel[ 3] = rows[ y * 4 + 3];
      }
   }
}


int   main( int argc, char *argv[])
{
   static const char   *vertex_source =
      "#version 100\n"
      "attribute vec2 aPos;\n"
      "attribute vec3 aColor;\n"
      "varying vec3 vColor;\n"
      "void main()\n"
      "{\n"
      "   vColor = aColor;\n"
      "   gl_Position = vec4( aPos, 0.0, 1.0);\n"
      "}\n";
   static const char   *fragment_source =
      "#version 100\n"
      "precision mediump float;\n"
      "varying vec3 vColor;\n"
      "void main()\n"
      "{\n"
      "   gl_FragColor = vec4( vColor, 1.0);\n"
      "}\n";
   static const float   positions[ 4] = { -1.0f, 0.0f,  1.0f, 0.0f };
   static const float   colors[ 6] =
      { 1.0f, 0.0f, 0.0f,  0.0f, 1.0f, 0.0f };
   unsigned char   pixel[ 4];
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
   aex_gl_es2_BindAttribLocation( program, 1, "aColor");
   aex_gl_es2_LinkProgram( program);
   if( check_program( program))
      return( 1);

   aex_gl_es2_UseProgram( program);

   aex_gl_es2_EnableVertexAttribArray( 0);
   aex_gl_es2_VertexAttribPointer( 0,
                                   2,
                                   GL_ES2_FLOAT,
                                   GL_ES2_FALSE,
                                   0,
                                   positions);
   aex_gl_es2_EnableVertexAttribArray( 1);
   aex_gl_es2_VertexAttribPointer( 1,
                                   3,
                                   GL_ES2_FLOAT,
                                   GL_ES2_FALSE,
                                   0,
                                   colors);

   aex_gl_es2_Viewport( 0, 0, 64, 64);
   aex_gl_es2_ClearColor( 0.0f, 0.0f, 0.0f, 1.0f);
   aex_gl_es2_Clear( GL_ES2_COLOR_BUFFER_BIT);
   aex_gl_es2_LineWidth( 3.0f);
   aex_gl_es2_DrawArrays( GL_ES2_LINES, 0, 2);

   read_line_pixel( 8, pixel);
   if( pixel[ 0] < 200 || pixel[ 1] > 60)
   {
      fprintf( stderr, "left line pixel is %u,%u,%u,%u\n",
               (unsigned int) pixel[ 0], (unsigned int) pixel[ 1],
               (unsigned int) pixel[ 2], (unsigned int) pixel[ 3]);
      return( 1);
   }

   read_line_pixel( 32, pixel);
   if( pixel[ 0] < 80 || pixel[ 0] > 180 ||
       pixel[ 1] < 80 || pixel[ 1] > 180)
   {
      fprintf( stderr, "center line pixel is %u,%u,%u,%u\n",
               (unsigned int) pixel[ 0], (unsigned int) pixel[ 1],
               (unsigned int) pixel[ 2], (unsigned int) pixel[ 3]);
      return( 1);
   }

   read_line_pixel( 56, pixel);
   if( pixel[ 1] < 200 || pixel[ 0] > 60)
   {
      fprintf( stderr, "right line pixel is %u,%u,%u,%u\n",
               (unsigned int) pixel[ 0], (unsigned int) pixel[ 1],
               (unsigned int) pixel[ 2], (unsigned int) pixel[ 3]);
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

   printf( "headless GLES2 lines OK\n");
   return( 0);
}
