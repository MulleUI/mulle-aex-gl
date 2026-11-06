#include <mulle-aex-gl/gl_es2_impl.h>

#include <stdio.h>


int   main( int argc, char *argv[])
{
   unsigned int   depth[ 64];
   unsigned int   i;
   int            r;

   r = aex_gl_es2_context_init( 32, 0, 32, 64, 64);
   if( r)
   {
      fprintf( stderr, "aex_gl_es2_context_init failed: %d\n", r);
      return( 1);
   }

   aex_gl_es2_Viewport( 0, 0, 64, 64);
   aex_gl_es2_ClearDepthf( 1.0f);
   aex_gl_es2_Clear( GL_ES2_DEPTH_BUFFER_BIT);

   aex_gl_es2_ReadPixels( 0, 32, 64, 1, GL_ES2_DEPTH_COMPONENT,
                          GL_ES2_UNSIGNED_INT, depth);
   for( i = 0; i < 64; i++)
   {
      if( depth[ i] != 0xFFFFFFFF)
      {
         fprintf( stderr, "depth[%u] is 0x%08x\n", i, depth[ i]);
         return( 1);
      }
   }

   if( aex_gl_es2_GetError() != GL_ES2_NO_ERROR)
   {
      fprintf( stderr, "glGetError reported an error\n");
      return( 1);
   }

   printf( "headless GLES2 depth clear OK\n");
   return( 0);
}
