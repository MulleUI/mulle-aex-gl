#include <mulle-aex-gl/gl_es2_impl.h>

#include <stdio.h>


static char   *vertex_shader_source =
   "#version 100\n"
   "#extension GL_OES_standard_derivatives : enable\n"
   "attribute vec2 vertex;\n"
   "void main(void)\n"
   "{\n"
   "   gl_Position = vec4( vertex, 0.0, 1.0);\n"
   "}\n";


int   main( int argc, char *argv[])
{
   gl_es2_uint   shader;
   gl_es2_int    status;
   gl_es2_int    value;
   int           r;

   r = aex_gl_es2_context_init( 32, 16, 32, 16, 16);
   if( r)
   {
      fprintf( stderr, "aex_gl_es2_context_init failed: %d\n", r);
      return( 1);
   }

   value = -1;
   aex_gl_es2_GetIntegerv( GL_ES2_FRAMEBUFFER_BINDING, &value);
   if( value != 0)
   {
      fprintf( stderr, "unexpected framebuffer binding %d\n", (int) value);
      return( 1);
   }

   value = -1;
   aex_gl_es2_GetIntegerv( GL_ES2_RENDERBUFFER_BINDING, &value);
   if( value != 0)
   {
      fprintf( stderr, "unexpected renderbuffer binding %d\n", (int) value);
      return( 1);
   }

   shader = aex_gl_es2_CreateShader( GL_ES2_VERTEX_SHADER);
   {
      const gl_es2_char   *source;

      source = (const gl_es2_char *) vertex_shader_source;
      aex_gl_es2_ShaderSource( shader, 1, &source, NULL);
   }
   aex_gl_es2_CompileShader( shader);

   aex_gl_es2_GetShaderiv( shader, GL_ES2_COMPILE_STATUS, &status);
   if( ! status)
   {
      gl_es2_char   log[ 512];
      gl_es2_sizei  length;

      aex_gl_es2_GetShaderInfoLog( shader, sizeof( log), &length, log);
      log[ length < sizeof( log) ? length : sizeof( log) - 1] = 0;
      fprintf( stderr, "shader compile failed: %s\n", log);
      return( 1);
   }

   return( 0);
}
