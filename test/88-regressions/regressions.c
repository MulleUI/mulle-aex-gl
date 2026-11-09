/* Headless version of the demo regression scene.
 *
 * The checks live in demo/src/regression-checks-private.h so the SDL demo and this test
 * exercise exactly the same code. Each check runs in its own process so a
 * crash (the pre-fix detach-after-link bug) does not hide the other results.
 *
 * Reproducing the original bugs:
 *
 * The reviewed fixes stay behind the AEX_SHOW_ORIGINAL_BUG switch in src/
 * (blend.c, blitter.c, gl_es2_context.c, gl_es2_impl.c, primitive_assembly.c,
 * sampler_2d.c). Run the test with the define to build the pre-fix code
 * instead. From the "test" directory:
 *
 *    mulle-sde test run 88-regressions/regressions.c
 *    mulle-sde -DCFLAGS="-DAEX_SHOW_ORIGINAL_BUG" test run 88-regressions/regressions.c
 *
 * The first command prints "headless GLES2 regressions OK" for the fixed
 * tree. The second reports "8 of 8 regression checks failed" instead:
 * truncated unorm8 colours (254 instead of 255), masked subtract clobbering the
 * destination, the 32-bit depth clear writing 0x00008000, the binding queries
 * returning -1, negative repeat sampling landing on the first column, the
 * stencil-only clear raising an error, and the detach-after-link draw crashing
 * with SIGSEGV. The stencil read-modify-write check cannot distinguish the
 * switch, because a batch never contains overlapping fragments in this engine.
 * Rebuild without the define for the fixed behaviour; demo/README.md documents
 * the same switch for the SDL scene.
 */

#define AEX_REGRESSION_HEADLESS 1

#include "../../demo/src/regression-checks-private.h"

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>


static int   run_check( int index)
{
   pid_t  pid;
   int    status;

   pid = fork();
   if( pid == 0)
      _exit( regression_checks[ index]());

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
      return( WEXITSTATUS( status) != 0);

   if( WIFSIGNALED( status))
      fprintf( stderr, "check crashed with signal %d\n", WTERMSIG( status));
   return( 1);
}


int   main( int argc, char *argv[])
{
   int   failed;
   int   i;

   (void) argc;
   (void) argv;

   failed = 0;
   for( i = 0; i < NUM_REGRESSION_CHECKS; i++)
   {
      if( run_check( i))
      {
         fprintf( stderr, "[FAIL] %s\n", regression_check_names[ i]);
         failed++;
      }
   }

   if( failed)
   {
      fprintf( stderr, "%d of %d regression checks failed\n",
               failed, NUM_REGRESSION_CHECKS);
      return( 1);
   }

   printf( "headless GLES2 regressions OK\n");
   return( 0);
}
