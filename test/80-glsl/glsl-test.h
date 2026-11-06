#ifndef glsl_test_h__
#define glsl_test_h__

#include <mulle-aex-gl/gl_es2_impl.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define GLSL_TEST_LOG_SIZE 8192


struct glsl_compile_result
{
   gl_es2_uint   shader_;
   int           ok_;
   char          log_[ GLSL_TEST_LOG_SIZE];
};


static int   glsl_test_init( void)
{
   static int   state;

   if( ! state)
   {
      state = (aex_gl_es2_context_init( 32, 16, 32, 64, 64) == 0) ? 1 : -1;
      if( state == -1)
         fprintf( stderr, "aex_gl_es2_context_init failed\n");
   }
   return( state == 1);
}


static void   glsl_test_compile( int type,
                                 const char *source,
                                 struct glsl_compile_result *r)
{
   gl_es2_int     status;
   gl_es2_sizei   length;

   memset( r, 0, sizeof( *r));
   r->shader_ = aex_gl_es2_CreateShader( type);
   aex_gl_es2_ShaderSource( r->shader_, 1, &source, NULL);
   aex_gl_es2_CompileShader( r->shader_);

   status = 0;
   aex_gl_es2_GetShaderiv( r->shader_, GL_ES2_COMPILE_STATUS, &status);
   r->ok_ = !! status;

   length = 0;
   r->log_[ 0] = 0;
   aex_gl_es2_GetShaderInfoLog( r->shader_,
                                (gl_es2_sizei) sizeof( r->log_),
                                &length,
                                r->log_);
   if( length >= sizeof( r->log_))
      length = sizeof( r->log_) - 1;
   r->log_[ length] = 0;
}


static void   glsl_test_delete( struct glsl_compile_result *r)
{
   if( r->shader_)
      aex_gl_es2_DeleteShader( r->shader_);
   r->shader_ = 0;
}


static int   glsl_test_log_contains( const char *log, const char *needle)
{
   return( strstr( log, needle) != NULL);
}


static int   glsl_test_log_line( const char *log)
{
   const char   *p;
   const char   *q;
   int           value;
   int           digits;

   p = log;
   while( (p = strchr( p, '(')) != NULL)
   {
      q = p + 1;
      value = 0;
      digits = 0;
      while( *q >= '0' && *q <= '9')
      {
         value = value * 10 + (*q - '0');
         ++q;
         ++digits;
      }
      if( digits && *q == ')')
         return( value);
      ++p;
   }
   return( -1);
}


static void   glsl_test_result( const char *name, int passed, const char *log)
{
   printf( "%s: %s\n", name, passed ? "OK" : "FAIL");
   if( ! passed && log && *log)
      fprintf( stderr, "%s\n", log);
}


static void   glsl_test_gap( const char *name, const char *log)
{
   printf( "%s: GAP\n", name);
   if( log && *log)
      fprintf( stderr, "%s\n", log);
}


#endif
