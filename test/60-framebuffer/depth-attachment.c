#include <mulle-aex-gl/gl_es2_impl.h>

#include <stdio.h>


int   main( int argc, char *argv[])
{
   gl_es2_uint     color_buffer;
   gl_es2_uint     depth_buffer;
   gl_es2_uint     framebuffer;
   gl_es2_enum     status;
   unsigned short  depth;
   int             r;

   r = aex_gl_es2_context_init( 32, 0, 32, 8, 8);
   if( r)
   {
      fprintf( stderr, "aex_gl_es2_context_init failed: %d\n", r);
      return( 1);
   }

   aex_gl_es2_GenFramebuffers( 1, &framebuffer);
   aex_gl_es2_BindFramebuffer( GL_ES2_FRAMEBUFFER, framebuffer);

   aex_gl_es2_GenRenderbuffers( 1, &color_buffer);
   aex_gl_es2_BindRenderbuffer( GL_ES2_RENDERBUFFER, color_buffer);
   aex_gl_es2_RenderbufferStorage( GL_ES2_RENDERBUFFER, GL_ES2_RGBA8, 8, 8);
   aex_gl_es2_FramebufferRenderbuffer( GL_ES2_FRAMEBUFFER,
                                       GL_ES2_COLOR_ATTACHMENT0,
                                       GL_ES2_RENDERBUFFER,
                                       color_buffer);

   aex_gl_es2_GenRenderbuffers( 1, &depth_buffer);
   aex_gl_es2_BindRenderbuffer( GL_ES2_RENDERBUFFER, depth_buffer);
   aex_gl_es2_RenderbufferStorage( GL_ES2_RENDERBUFFER, GL_ES2_DEPTH_COMPONENT16, 8, 8);
   aex_gl_es2_FramebufferRenderbuffer( GL_ES2_FRAMEBUFFER,
                                       GL_ES2_DEPTH_ATTACHMENT,
                                       GL_ES2_RENDERBUFFER,
                                       depth_buffer);

   status = aex_gl_es2_CheckFramebufferStatus( GL_ES2_FRAMEBUFFER);
   if( status != GL_ES2_FRAMEBUFFER_COMPLETE)
   {
      fprintf( stderr, "incomplete framebuffer: 0x%04x\n", (unsigned int) status);
      return( 1);
   }

   aex_gl_es2_ClearDepthf( 0.5f);
   aex_gl_es2_Clear( GL_ES2_DEPTH_BUFFER_BIT);

   depth = 0;
   aex_gl_es2_ReadPixels( 4, 4, 1, 1, GL_ES2_DEPTH_COMPONENT, GL_ES2_UNSIGNED_SHORT, &depth);
   if( depth != 0x8000)
   {
      fprintf( stderr, "unexpected depth: 0x%04x\n", (unsigned int) depth);
      return( 1);
   }

   if( aex_gl_es2_GetError() != GL_ES2_NO_ERROR)
   {
      fprintf( stderr, "glGetError reported an error\n");
      return( 1);
   }

   aex_gl_es2_DeleteRenderbuffers( 1, &depth_buffer);
   aex_gl_es2_DeleteRenderbuffers( 1, &color_buffer);
   aex_gl_es2_DeleteFramebuffers( 1, &framebuffer);

   printf( "headless GLES2 depth attachment OK\n");
   return( 0);
}
