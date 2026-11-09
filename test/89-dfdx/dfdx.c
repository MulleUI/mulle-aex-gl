#include <mulle-aex-gl/gl_es2_impl.h>

#include <stdio.h>


#define W 64
#define H 64


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
      "precision mediump float;\n"
      "attribute vec2 aPos;\n"
      "varying vec4 vValue;\n"
      "void main()\n"
      "{\n"
      "   vValue = vec4( aPos.x, aPos.y, aPos.x + aPos.y, aPos.x);\n"
      "   gl_Position = vec4( aPos, 0.0, 1.0);\n"
      "}\n";
   static const char   *fragment_source =
      "#version 100\n"
      "precision mediump float;\n"
      "varying vec4 vValue;\n"
      "void main()\n"
      "{\n"
      "   gl_FragColor = dFdx( vValue) * 32.0;\n"
      "}\n";
   static const float   quad[ 8] =
      { -1.0f, -1.0f,  1.0f, -1.0f,  -1.0f, 1.0f,  1.0f, 1.0f };
   unsigned char   pixel[ 4];
   gl_es2_uint     fragment_shader;
   gl_es2_uint     program;
   gl_es2_uint     vertex_shader;
   int             r;

   r = aex_gl_es2_context_init( 32, 0, 0, W, H);
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
   aex_gl_es2_EnableVertexAttribArray( 0);
   aex_gl_es2_VertexAttribPointer( 0, 2, GL_ES2_FLOAT, GL_ES2_FALSE, 0,
                                   quad);

   aex_gl_es2_Viewport( 0, 0, W, H);
   aex_gl_es2_ClearColor( 0.0f, 0.0f, 0.0f, 1.0f);
   aex_gl_es2_Clear( GL_ES2_COLOR_BUFFER_BIT);
   aex_gl_es2_DrawArrays( GL_ES2_TRIANGLE_STRIP, 0, 4);

   /* dFdx is 2 / W = 1 / 32 across the viewport. Scaling by 32 makes the
    * x, z and w derivatives 1.0 and the y derivative 0.0. The alpha channel
    * is the component that the 8-fragment dFdx fast path used to skip. */
   aex_gl_es2_ReadPixels( W / 2, H / 2, 1, 1, GL_ES2_RGBA,
                          GL_ES2_UNSIGNED_BYTE, pixel);

   if( pixel[ 0] != 255 || pixel[ 1] != 0 ||
       pixel[ 2] != 255 || pixel[ 3] != 255)
   {
      fprintf( stderr, "dFdx(vec4) gave %u,%u,%u,%u, expected 255,0,255,255\n",
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

   printf( "headless GLES2 dFdx(vec4) OK\n");
   return( 0);
}
