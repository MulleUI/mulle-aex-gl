#include <SDL3/SDL.h>

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "demo-common.h"
#include "gl_es2_impl.h"


#define WINDOW_WIDTH  800
#define WINDOW_HEIGHT 600


static const char   *vertex_source =
   "#version 100\n"
   "uniform float uAngle;\n"
   "uniform float uAspect;\n"
   "attribute vec2 aPos;\n"
   "attribute vec3 aColor;\n"
   "varying vec3 vColor;\n"
   "void main()\n"
   "{\n"
   "   float s = sin( uAngle);\n"
   "   float c = cos( uAngle);\n"
   "   vec2 p = vec2( aPos.x * c - aPos.y * s,\n"
   "                  aPos.x * s + aPos.y * c);\n"
   "   gl_Position = vec4( p.x / uAspect, p.y, 0.0, 1.0);\n"
   "   vColor = aColor;\n"
   "}\n";

static const char   *fragment_source =
   "#version 100\n"
   "precision mediump float;\n"
   "varying vec3 vColor;\n"
   "void main()\n"
   "{\n"
   "   gl_FragColor = vec4( vColor, 1.0);\n"
   "}\n";

static const float   vertices[] =
{
   -0.6f, -0.4f,   1.0f, 0.0f, 0.0f,
    0.6f, -0.4f,   0.0f, 1.0f, 0.0f,
    0.0f,  0.6f,   0.0f, 0.0f, 1.0f
};


static int   check_shader( gl_es2_uint shader)
{
   char   log[ 512];
   gl_es2_int  status;
   gl_es2_sizei length;

   aex_gl_es2_GetShaderiv( shader, GL_ES2_COMPILE_STATUS, &status);
   if( status)
      return( 0);

   aex_gl_es2_GetShaderInfoLog( shader, sizeof( log), &length, log);
   log[ length < sizeof( log) ? length : sizeof( log) - 1] = 0;
   fprintf( stderr, "shader compile failed: %s\n", log);
   return( 1);
}


static int   check_program( gl_es2_uint program)
{
   char   log[ 256 ];
   gl_es2_int  status;
   gl_es2_sizei length;

   aex_gl_es2_GetProgramiv( program, GL_ES2_LINK_STATUS, &status);
   if( status)
      return( 0);

   aex_gl_es2_GetProgramInfoLog( program, sizeof( log), &length, log);
   log[ length < sizeof( log) ? length : sizeof( log) - 1] = 0;
   fprintf( stderr, "shader link failed: %s\n", log);
   return( 1);
}


static int   init_aex( void)
{
   int   rc;

   rc = aex_gl_es2_context_init( 32, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
   if( rc)
   {
      fprintf( stderr, "aex_gl_es2_context_init failed: %d\n", rc);
      return( 1);
   }
   return( 0);
}


static int   init_gl( gl_es2_uint *program, gl_es2_uint *buffer, gl_es2_int *angle_location, gl_es2_int *aspect_location)
{
   gl_es2_uint   fragment_shader;
   gl_es2_uint   vertex_shader;

   vertex_shader = aex_gl_es2_CreateShader( GL_ES2_VERTEX_SHADER);
   aex_gl_es2_ShaderSource( vertex_shader, 1, &vertex_source, NULL);
   aex_gl_es2_CompileShader( vertex_shader);
   if( check_shader( vertex_shader))
      return( 1);

   fragment_shader = aex_gl_es2_CreateShader( GL_ES2_FRAGMENT_SHADER);
   aex_gl_es2_ShaderSource( fragment_shader, 1, &fragment_source, NULL);
   aex_gl_es2_CompileShader( fragment_shader);
   if( check_shader( fragment_shader))
      return( 1);

   *program = aex_gl_es2_CreateProgram();
   aex_gl_es2_AttachShader( *program, vertex_shader);
   aex_gl_es2_AttachShader( *program, fragment_shader);
   aex_gl_es2_BindAttribLocation( *program, 0, "aPos");
   aex_gl_es2_BindAttribLocation( *program, 1, "aColor");
   aex_gl_es2_LinkProgram( *program);
   if( check_program( *program))
      return( 1);

   aex_gl_es2_DeleteShader( vertex_shader);
   aex_gl_es2_DeleteShader( fragment_shader);

   aex_gl_es2_UseProgram( *program);

   aex_gl_es2_GenBuffers( 1, buffer);
   aex_gl_es2_BindBuffer( GL_ES2_ARRAY_BUFFER, *buffer);
   aex_gl_es2_BufferData( GL_ES2_ARRAY_BUFFER,
                          sizeof( vertices),
                          vertices,
                          GL_ES2_STATIC_DRAW);

   aex_gl_es2_EnableVertexAttribArray( 0);
   aex_gl_es2_VertexAttribPointer( 0,
                                   2,
                                   GL_ES2_FLOAT,
                                   GL_ES2_FALSE,
                                   5 * sizeof( float),
                                   (void *) 0);
   aex_gl_es2_EnableVertexAttribArray( 1);
   aex_gl_es2_VertexAttribPointer( 1,
                                   3,
                                   GL_ES2_FLOAT,
                                   GL_ES2_FALSE,
                                   5 * sizeof( float),
                                   (void *) (2 * sizeof( float)));

   *angle_location  = aex_gl_es2_GetUniformLocation( *program, "uAngle");
   *aspect_location = aex_gl_es2_GetUniformLocation( *program, "uAspect");
   return( 0);
}


int   main( int argc, char *argv[])
{
   SDL_Event   event;
   SDL_Window  *window;
   unsigned char *pixels;
   gl_es2_uint      buffer;
   gl_es2_uint      program;
   gl_es2_int       angle_location;
   gl_es2_int       aspect_location;
   Uint64      started;
   int         running;

   (void) argc;
   (void) argv;

   if( ! SDL_Init( SDL_INIT_VIDEO))
   {
      fprintf( stderr, "SDL_Init failed: %s\n", SDL_GetError());
      return( 1);
   }

   window = SDL_CreateWindow( "mulle-aex-gl SDL3 triangle",
                              WINDOW_WIDTH,
                              WINDOW_HEIGHT,
                              0);
   if( window == NULL)
   {
      fprintf( stderr, "SDL_CreateWindow failed: %s\n", SDL_GetError());
      SDL_Quit();
      return( 1);
   }

   if( init_aex())
   {
      SDL_DestroyWindow( window);
      SDL_Quit();
      return( 1);
   }

   if( init_gl( &program, &buffer, &angle_location, &aspect_location))
   {
      SDL_DestroyWindow( window);
      SDL_Quit();
      return( 1);
   }

   pixels = malloc( WINDOW_WIDTH * WINDOW_HEIGHT * 4);
   if( ! pixels)
   {
      fprintf( stderr, "out of memory\n");
      SDL_DestroyWindow( window);
      SDL_Quit();
      return( 1);
   }

   started = SDL_GetTicks();
   running = 1;

   while( running)
   {
      while( SDL_PollEvent( &event))
      {
         if( event.type == SDL_EVENT_QUIT)
            running = 0;
         else if( event.type == SDL_EVENT_KEY_DOWN &&
                  event.key.key == SDLK_ESCAPE)
            running = 0;
      }

      aex_gl_es2_Viewport( 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
      aex_gl_es2_ClearColor( 0.12f, 0.12f, 0.12f, 1.0f);
      aex_gl_es2_Clear( GL_ES2_COLOR_BUFFER_BIT | GL_ES2_DEPTH_BUFFER_BIT);

      aex_gl_es2_UseProgram( program);
      aex_gl_es2_Uniform1f( angle_location,
                            (float) (SDL_GetTicks() - started) / 1000.0f);
      aex_gl_es2_Uniform1f( aspect_location,
                            (float) WINDOW_WIDTH / (float) WINDOW_HEIGHT);
      aex_gl_es2_BindBuffer( GL_ES2_ARRAY_BUFFER, buffer);
      aex_gl_es2_DrawArrays( GL_ES2_TRIANGLES, 0, 3);

      aex_gl_es2_ReadPixels( 0,
                             0,
                             WINDOW_WIDTH,
                             WINDOW_HEIGHT,
                             GL_ES2_RGBA,
                             GL_ES2_UNSIGNED_BYTE,
                             pixels);

      if( demo_present( window, pixels))
         running = 0;

      SDL_Delay( 16);
   }

   free( pixels);
   aex_gl_es2_DeleteBuffers( 1, &buffer);
   aex_gl_es2_DeleteProgram( program);
   SDL_DestroyWindow( window);
   SDL_Quit();
   return( 0);
}
