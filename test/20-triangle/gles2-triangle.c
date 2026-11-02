#include <mulle-aex-gl/gl_es2_impl.h>

#include <stdio.h>


static int   check_shader( gl_es2_uint shader)
{
   gl_es2_char   log[512];
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
   static const char   *vertex_source =
      "#version 100\n"
      "attribute vec2 aPos;\n"
      "void main()\n"
      "{\n"
      "   gl_Position = vec4( aPos, 0.0, 1.0);\n"
      "}\n";
   static const char   *fragment_source =
      "#version 100\n"
      "precision mediump float;\n"
      "void main()\n"
      "{\n"
      "   gl_FragColor = vec4( 1.0, 0.0, 0.0, 1.0);\n"
      "}\n";
   static const float   vertices[6] =
      { -1.0f, -1.0f,  1.0f, -1.0f,  0.0f, 1.0f };
   unsigned char   pixel[4];
   gl_es2_uint     program;
   gl_es2_uint     vertex_shader;
   gl_es2_uint     fragment_shader;
   gl_es2_uint     buffer;
   int             r;

   r = aex_gl_es2_context_init( 32, 16, 32, 64, 64);
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

   aex_gl_es2_GenBuffers( 1, &buffer);
   aex_gl_es2_BindBuffer( GL_ES2_ARRAY_BUFFER, buffer);
   aex_gl_es2_BufferData( GL_ES2_ARRAY_BUFFER,
                          sizeof( vertices),
                          vertices,
                          GL_ES2_STATIC_DRAW);

   aex_gl_es2_EnableVertexAttribArray( 0);
   aex_gl_es2_VertexAttribPointer( 0, 2, GL_ES2_FLOAT, GL_ES2_FALSE, 0, NULL);

   aex_gl_es2_Viewport( 0, 0, 64, 64);
   aex_gl_es2_ClearColor( 0.0f, 0.0f, 0.0f, 1.0f);
   aex_gl_es2_Clear( GL_ES2_COLOR_BUFFER_BIT |
                     GL_ES2_DEPTH_BUFFER_BIT |
                     GL_ES2_STENCIL_BUFFER_BIT);
   aex_gl_es2_DrawArrays( GL_ES2_TRIANGLES, 0, 3);

   aex_gl_es2_ReadPixels( 32, 32, 1, 1, GL_ES2_RGBA, GL_ES2_UNSIGNED_BYTE, pixel);

   if( pixel[0] != 255 || pixel[1] != 0 || pixel[2] != 0 || pixel[3] != 255)
   {
      fprintf( stderr, "unexpected pixel: %u %u %u %u\n",
               pixel[0], pixel[1], pixel[2], pixel[3]);
      return( 1);
   }

   printf( "headless GLES2 shader triangle OK\n");
   return( 0);
}
