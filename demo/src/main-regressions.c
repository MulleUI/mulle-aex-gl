/* Regression scene:
 *
 * Each check exercises one of the bugs that the fix/* branches address, using
 * only the public GLES2 entry points. Run it against the current tree to see
 * everything pass, or against a pre-fix tree to see the original failures.
 *
 * From the mulle-aex-gl directory:
 *
 *   mulle-sde -d demo -DCFLAGS="-DAEX_SHOW_ORIGINAL_BUG" run regressions
 *
 * The current tree prints PASS for every check; the pre-fix tree prints the
 * original failures. Rebuild without the define to restore the fixed code.
 *
 * Every check runs in its own re-executed process. That keeps a crash (the
 * glDetachShader-after-link bug used to crash the draw path) from hiding the
 * results of the other checks.
 */

#include <SDL3/SDL.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#include "demo-common.h"

#include "regression-checks-private.h"


static const char   *self_path( const char *argv0)
{
#ifdef __linux__
   static char   path[ 4096];
   ssize_t       length;

   length = readlink( "/proc/self/exe", path, sizeof( path) - 1);
   if( length > 0)
   {
      path[ length] = 0;
      return( path);
   }
#endif
   return( argv0);
}


/* Writes the check's final framebuffer as raw top-down RGBA, so the parent can
 * show what was actually rendered. */
static int   write_frame( const char *path, const unsigned char *rgba)
{
   FILE   *fp;

   fp = fopen( path, "wb");
   if( ! fp)
      return( 1);
   fwrite( rgba, 1, (size_t) W * H * 4, fp);
   fclose( fp);
   return( 0);
}


static unsigned char   *read_frame( const char *path)
{
   FILE   *fp;
   size_t   count;
   unsigned char   *rgba;

   fp = fopen( path, "rb");
   if( ! fp)
      return( NULL);
   rgba = malloc( (size_t) W * H * 4);
   if( ! rgba)
   {
      fclose( fp);
      return( NULL);
   }
   count = fread( rgba, 1, (size_t) W * H * 4, fp);
   fclose( fp);
   if( count != (size_t) W * H * 4)
   {
      free( rgba);
      return( NULL);
   }
   return( rgba);
}


/* Re-exec the demo with a single check selected, so a crash in one check does
 * not abort the others. The child writes the final framebuffer to frame_path,
 * so the parent can show what the check actually rendered. */
static int   run_check( const char *argv0, int index, const char *frame_path)
{
   char   index_text[ 16];
   char   *args[ 5];
   pid_t  pid;
   int    status;

   snprintf( index_text, sizeof( index_text), "%d", index);
   args[ 0] = (char *) self_path( argv0);
   args[ 1] = (char *) "--run-check";
   args[ 2] = index_text;
   args[ 3] = (char *) frame_path;
   args[ 4] = NULL;

   pid = fork();
   if( pid == 0)
   {
      execv( args[ 0], args);
      _exit( 127);
   }
   if( pid < 0)
   {
      fprintf( stderr, "fork failed\n");
      return( 1);
   }

   if( waitpid( pid, &status, 0) < 0)
   {
      fprintf( stderr, "waitpid failed\n");
      return( 1);
   }

   if( WIFEXITED( status))
   {
      if( WEXITSTATUS( status) == 0)
         return( 0);
      if( WEXITSTATUS( status) == 127)
         fprintf( stderr, "could not re-exec %s\n", args[ 0]);
      return( 1);
   }

   if( WIFSIGNALED( status))
      fprintf( stderr, "check crashed with signal %d\n", WTERMSIG( status));
   return( 1);
}


/* Paints the framebuffer each check rendered into its tile. A failed check
 * still shows its frame; the status bar at the bottom turns red. Checks whose
 * frame is not meaningful only get a pass/fail colored tile. */
static void   paint_results( SDL_Window *window,
                             const int *results,
                             unsigned char *const *frames)
{
   SDL_Surface   *frame_surface;
   SDL_Surface   *surface;
   SDL_Rect      dst_rect;
   SDL_Rect      src_rect;
   SDL_Rect      status_rect;
   Uint32        green;
   Uint32        red;
   Uint32        dark;
   int           frame_height;
   int           i;
   int           status_height;
   int           tile_width;

   surface = SDL_GetWindowSurface( window);
   if( ! surface)
      return;

   green = SDL_MapSurfaceRGB( surface, 0x40, 0xC0, 0x40);
   red   = SDL_MapSurfaceRGB( surface, 0xC0, 0x40, 0x40);
   dark  = SDL_MapSurfaceRGB( surface, 0x20, 0x20, 0x20);
   SDL_FillSurfaceRect( surface, NULL, dark);

   status_height = 32;
   frame_height = surface->h - status_height;

   src_rect.x = 0;
   src_rect.y = 0;
   src_rect.w = W;
   src_rect.h = H;

   for( i = 0; i < NUM_REGRESSION_CHECKS; i++)
   {
      dst_rect.x = (i * surface->w) / NUM_REGRESSION_CHECKS;
      dst_rect.w = ((i + 1) * surface->w) / NUM_REGRESSION_CHECKS - dst_rect.x;
      tile_width = dst_rect.w;
      dst_rect.y = 0;
      dst_rect.h = frame_height;

      if( frames[ i])
      {
         frame_surface = SDL_CreateSurfaceFrom( W, H, SDL_PIXELFORMAT_RGBA32,
                                                frames[ i], W * 4);
         if( frame_surface)
         {
            SDL_BlitSurfaceScaled( frame_surface, &src_rect, surface, &dst_rect,
                                   SDL_SCALEMODE_NEAREST);
            SDL_DestroySurface( frame_surface);
         }
      }

      status_rect.x = dst_rect.x;
      status_rect.y = frame_height;
      status_rect.w = tile_width;
      status_rect.h = status_height;
      SDL_FillSurfaceRect( surface, &status_rect, results[ i] ? red : green);
   }

   SDL_UpdateWindowSurface( window);
}


int   main( int argc, char *argv[])
{
   SDL_Event   event;
   SDL_Window  *window;
   char        frame_path[ 256];
   char        title[ 128];
   unsigned char   *frames[ NUM_REGRESSION_CHECKS];
   int         i;
   int         passed;
   int         failed;
   int         result;
   int         results[ NUM_REGRESSION_CHECKS];
   int         wait_for_user;

   if( argc >= 4 && ! strcmp( argv[ 1], "--run-check"))
   {
      unsigned char   *rgba;

      i = atoi( argv[ 2]);
      if( i < 0 || i >= NUM_REGRESSION_CHECKS)
         return( 2);

      result = regression_checks[ i]();
      if( regression_check_has_frame[ i])
      {
         rgba = malloc( (size_t) W * H * 4);
         if( rgba)
         {
            if( ! capture_frame( rgba))
               write_frame( argv[ 3], rgba);
            free( rgba);
         }
      }
      return( result);
   }

   wait_for_user = 1;
   for( i = 1; i < argc; i++)
      if( ! strcmp( argv[ i], "--exit"))
         wait_for_user = 0;

   if( ! SDL_Init( SDL_INIT_VIDEO))
   {
      fprintf( stderr, "SDL_Init failed: %s\n", SDL_GetError());
      return( 1);
   }

   window = SDL_CreateWindow( "mulle-aex-gl regressions", 1024, 160, 0);
   if( ! window)
   {
      fprintf( stderr, "SDL_CreateWindow failed: %s\n", SDL_GetError());
      SDL_Quit();
      return( 1);
   }

   passed = 0;
   failed = 0;
   for( i = 0; i < NUM_REGRESSION_CHECKS; i++)
   {
      snprintf( frame_path, sizeof( frame_path),
                "/tmp/mulle-aex-gl-regression-%ld-%d.rgba",
                (long) getpid(), i);
      result = run_check( argv[ 0], i, frame_path);
      results[ i] = result;
      frames[ i] = regression_check_has_frame[ i] ? read_frame( frame_path)
                                                  : NULL;
      remove( frame_path);
      if( result)
         failed++;
      else
         passed++;
      printf( "[%s] %s\n", result ? "FAIL" : "PASS",
              regression_check_names[ i]);
      fflush( stdout);
   }

   printf( "%d passed, %d failed\n", passed, failed);
   fflush( stdout);

   snprintf( title, sizeof( title),
             "mulle-aex-gl regressions%s: %d passed, %d failed",
#if defined( AEX_SHOW_ORIGINAL_BUG)
             " (original bug build)",
#else
             "",
#endif
             passed, failed);
   SDL_SetWindowTitle( window, title);
   paint_results( window, results, frames);

   while( wait_for_user)
   {
      while( SDL_PollEvent( &event))
      {
         if( event.type == SDL_EVENT_QUIT)
            wait_for_user = 0;
         else if( event.type == SDL_EVENT_KEY_DOWN &&
                  event.key.key == SDLK_ESCAPE)
            wait_for_user = 0;
      }
      SDL_Delay( 16);
   }

   for( i = 0; i < NUM_REGRESSION_CHECKS; i++)
      free( frames[ i]);

   SDL_DestroyWindow( window);
   SDL_Quit();

   return( failed ? 1 : 0);
}
