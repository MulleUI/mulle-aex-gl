#include <mulle-aex-gl/gl_es2_impl.h>

#include <stdio.h>


int   main( int argc, char *argv[])
{
   unsigned char   pixel[4];
   int             r;

   r = aex_gl_es2_context_init( 32, 16, 32, 16, 16);
   if( r)
   {
      fprintf( stderr, "aex_gl_es2_context_init failed: %d\n", r);
      return( 1);
   }

   aex_gl_es2_ClearColor( 0.0f, 0.0f, 1.0f, 1.0f);
   aex_gl_es2_Clear( GL_ES2_COLOR_BUFFER_BIT |
                     GL_ES2_DEPTH_BUFFER_BIT |
                     GL_ES2_STENCIL_BUFFER_BIT);
   aex_gl_es2_ReadPixels( 0, 0, 1, 1, GL_ES2_RGBA, GL_ES2_UNSIGNED_BYTE, pixel);

   if( pixel[0] != 0 || pixel[1] != 0 || pixel[2] != 255 || pixel[3] != 255)
   {
      fprintf( stderr, "unexpected pixel: %u %u %u %u\n",
               pixel[0], pixel[1], pixel[2], pixel[3]);
      return( 1);
   }

   printf( "headless GLES2 clear/readpixels OK\n");
   return( 0);
}
