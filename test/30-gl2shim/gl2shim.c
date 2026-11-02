#include <GLES2/gl2.h>

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

   glClearColor( 0.0f, 1.0f, 0.0f, 1.0f);
   glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
   glReadPixels( 0, 0, 1, 1, GL_RGBA, GL_UNSIGNED_BYTE, pixel);

   if( pixel[0] != 0 || pixel[1] != 255 || pixel[2] != 0 || pixel[3] != 255)
   {
      fprintf( stderr, "unexpected pixel: %u %u %u %u\n",
               pixel[0], pixel[1], pixel[2], pixel[3]);
      return( 1);
   }

   printf( "GLES2 compatibility shim OK\n");
   return( 0);
}
