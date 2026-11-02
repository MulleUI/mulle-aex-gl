#include <stdint.h>
#include <stdlib.h>

#include <mulle-core/mulle-core.h>

#include "thread_context.h"
#include "sl_defs.h"
#include "gl_es2_context.h"


static mulle_thread_once_t      g_default_context_initialization_ = MULLE_THREAD_ONCE_INIT;
static struct gl_es2_context    g_default_context_;

static mulle_thread_once_t   g_tls_keys_initialization_ = MULLE_THREAD_ONCE_INIT;
static mulle_thread_tss_t    g_context_tls_key_;
static mulle_thread_tss_t    g_api_tls_key_;
static int                   g_tls_keys_valid_;


static void   tc_default_context_at_exit_cleanup( void)
{
   gl_es2_ctx_cleanup( &g_default_context_);
}


static void   tc_initialize_default_context( void)
{
   /* Fixed initialization to known-good state */
   gl_es2_ctx_init( &g_default_context_);

   /* Complete initialization with may-fail allocations */
   if( SL_ERR_OK != gl_es2_ctx_complete_initialization( &g_default_context_))
   {
      /* Failed allocations -- error will have been set. We're better off
       * returning a context in failed state than not completing the
       * initialization (which would cause us to return NULL and crash
       * without diagnostics. */
   }
   atexit( tc_default_context_at_exit_cleanup);
}


static void   tc_initialize_tls_keys( void)
{
   if( mulle_thread_tss_create( NULL, &g_context_tls_key_))
      return;
   if( mulle_thread_tss_create( NULL, &g_api_tls_key_))
   {
      mulle_thread_tss_free( g_context_tls_key_);
      return;
   }
   g_tls_keys_valid_ = 1;
}


struct gl_es2_context   *tc_get_default_context( void)
{
   mulle_thread_once( &g_default_context_initialization_,
                      tc_initialize_default_context);
   return( &g_default_context_);
}


struct gl_es2_context   *tc_get_context( void)
{
   mulle_thread_once( &g_tls_keys_initialization_, tc_initialize_tls_keys);
   if( ! g_tls_keys_valid_)
      return( NULL);
   return( (struct gl_es2_context *) mulle_thread_tss_get( g_context_tls_key_));
}


void   tc_set_context( struct gl_es2_context *pctx)
{
   mulle_thread_once( &g_tls_keys_initialization_, tc_initialize_tls_keys);
   if( ! g_tls_keys_valid_)
      return;
   mulle_thread_tss_set( g_context_tls_key_, (void *) pctx);
}


int   tc_get_api( void)
{
   mulle_thread_once( &g_tls_keys_initialization_, tc_initialize_tls_keys);
   if( ! g_tls_keys_valid_)
      return( 0);
   return( (int) (intptr_t) mulle_thread_tss_get( g_api_tls_key_));
}


void   tc_set_api( int api)
{
   mulle_thread_once( &g_tls_keys_initialization_, tc_initialize_tls_keys);
   if( ! g_tls_keys_valid_)
      return;
   mulle_thread_tss_set( g_api_tls_key_, (void *) (intptr_t) api);
}
