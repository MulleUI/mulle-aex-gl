#include <mulle-aex-gl/gl_es2_impl.h>

#include <stdio.h>


int   main( int argc, char *argv[])
{
   gl_es2_int   bits;
   int          r;

   r = aex_gl_es2_context_init( 32, 16, 32, 16, 16);
   if( r)
   {
      fprintf( stderr, "aex_gl_es2_context_init failed: %d\n", r);
      return( 1);
   }

   bits = -1;
   aex_gl_es2_GetIntegerv( GL_ES2_STENCIL_BITS, &bits);
   if( bits != 16)
   {
      fprintf( stderr, "unexpected stencil bits %d\n", (int) bits);
      return( 1);
   }

   aex_gl_es2_ClearStencil( 0);
   aex_gl_es2_Clear( GL_ES2_STENCIL_BUFFER_BIT);

   if( aex_gl_es2_GetError() != GL_ES2_NO_ERROR)
   {
      fprintf( stderr, "glClear( GL_STENCIL_BUFFER_BIT) failed\n");
      return( 1);
   }

   return( 0);
}
