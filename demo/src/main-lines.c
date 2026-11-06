#include <SDL3/SDL.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "demo-common.h"
#include "gl_es2_impl.h"


#define WINDOW_WIDTH  800
#define WINDOW_HEIGHT 600

#define PIX_COORD(x, y) \
   -1.0f + 2.0f * ((0.5f + 4.0f * ((float) (x) - 128.0f) + \
                    0.5f * (float) WINDOW_WIDTH) / (float) WINDOW_WIDTH), \
    1.0f - 2.0f * ((0.5f + 4.0f * ((float) (y) - 128.0f) + \
                    0.5f * (float) WINDOW_HEIGHT) / (float) WINDOW_HEIGHT), \
   -0.5f, 1.0f


static const char   *vertex_source =
   "#version 100\n"
   "attribute vec4 a_position;\n"
   "attribute vec4 a_color;\n"
   "varying vec4 v_color;\n"
   "void main()\n"
   "{\n"
   "   v_color = a_color;\n"
   "   gl_Position = a_position;\n"
   "}\n";

static const char   *fragment_source =
   "#version 100\n"
   "precision mediump float;\n"
   "varying vec4 v_color;\n"
   "void main()\n"
   "{\n"
   "   gl_FragColor = v_color;\n"
   "}\n";

static const float   vertices[] =
{
   PIX_COORD( 144, 128), PIX_COORD( 160, 128),
   PIX_COORD( 144, 136), PIX_COORD( 160, 144),
   PIX_COORD( 144, 144), PIX_COORD( 160, 160),
   PIX_COORD( 136, 144), PIX_COORD( 144, 160),
   PIX_COORD( 128, 144), PIX_COORD( 128, 160),
   PIX_COORD( 120, 144), PIX_COORD( 112, 160),
   PIX_COORD( 112, 144), PIX_COORD(  96, 160),
   PIX_COORD( 112, 136), PIX_COORD(  96, 144),

   PIX_COORD( 112, 128), PIX_COORD(  96, 128),
   PIX_COORD( 112, 120), PIX_COORD(  96, 112),
   PIX_COORD( 112, 112), PIX_COORD(  96,  96),
   PIX_COORD( 120, 112), PIX_COORD( 112,  96),
   PIX_COORD( 128, 112), PIX_COORD( 128,  96),
   PIX_COORD( 136, 112), PIX_COORD( 144,  96),
   PIX_COORD( 144, 112), PIX_COORD( 160,  96),
   PIX_COORD( 144, 120), PIX_COORD( 160, 112)
};

static const float   colors[] =
{
   0.0f, 0.0f, 0.0f, 1.0f,
   0.0f, 0.0f, 0.0f, 1.0f,
   0.6f, 0.0f, 0.0f, 1.0f,
   0.6f, 0.0f, 0.0f, 1.0f,
   0.0f, 0.6f, 0.0f, 1.0f,
   0.0f, 0.6f, 0.0f, 1.0f,
   0.6f, 0.6f, 0.0f, 1.0f,
   0.6f, 0.6f, 0.0f, 1.0f,
   0.0f, 0.0f, 0.6f, 1.0f,
   0.0f, 0.0f, 0.6f, 1.0f,
   0.6f, 0.0f, 0.6f, 1.0f,
   0.6f, 0.0f, 0.6f, 1.0f,
   0.0f, 0.6f, 0.6f, 1.0f,
   0.0f, 0.6f, 0.6f, 1.0f,
   0.6f, 0.6f, 0.6f, 1.0f,
   0.6f, 0.6f, 0.6f, 1.0f,

   1.0f, 1.0f, 1.0f, 1.0f,
   1.0f, 1.0f, 1.0f, 1.0f,
   1.0f, 0.0f, 0.0f, 1.0f,
   1.0f, 0.0f, 0.0f, 1.0f,
   0.0f, 1.0f, 0.0f, 1.0f,
   0.0f, 1.0f, 0.0f, 1.0f,
   1.0f, 1.0f, 0.0f, 1.0f,
   1.0f, 1.0f, 0.0f, 1.0f,
   0.0f, 0.0f, 1.0f, 1.0f,
   0.0f, 0.0f, 1.0f, 1.0f,
   1.0f, 0.0f, 1.0f, 1.0f,
   1.0f, 0.0f, 1.0f, 1.0f,
   0.0f, 1.0f, 1.0f, 1.0f,
   0.0f, 1.0f, 1.0f, 1.0f,
   1.0f, 1.0f, 1.0f, 1.0f,
   1.0f, 1.0f, 1.0f, 1.0f
};


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


static int   init_gl( gl_es2_uint *program)
{
   gl_es2_uint   fragment_shader;
   gl_es2_uint   vertex_shader;

   vertex_shader = aex_gl_es2_CreateShader( GL_ES2_VERTEX_SHADER);
   aex_gl_es2_ShaderSource( vertex_shader, 1, &vertex_source, NULL);
   aex_gl_es2_CompileShader( vertex_shader);
   if( demo_check_shader( vertex_shader))
      return( 1);

   fragment_shader = aex_gl_es2_CreateShader( GL_ES2_FRAGMENT_SHADER);
   aex_gl_es2_ShaderSource( fragment_shader, 1, &fragment_source, NULL);
   aex_gl_es2_CompileShader( fragment_shader);
   if( demo_check_shader( fragment_shader))
      return( 1);

   *program = aex_gl_es2_CreateProgram();
   aex_gl_es2_AttachShader( *program, vertex_shader);
   aex_gl_es2_AttachShader( *program, fragment_shader);
   aex_gl_es2_BindAttribLocation( *program, 0, "a_position");
   aex_gl_es2_BindAttribLocation( *program, 1, "a_color");
   aex_gl_es2_LinkProgram( *program);
   if( demo_check_program( *program))
      return( 1);

   aex_gl_es2_DeleteShader( vertex_shader);
   aex_gl_es2_DeleteShader( fragment_shader);

   aex_gl_es2_UseProgram( *program);

   aex_gl_es2_EnableVertexAttribArray( 0);
   aex_gl_es2_VertexAttribPointer( 0,
                                   4,
                                   GL_ES2_FLOAT,
                                   GL_ES2_FALSE,
                                   0,
                                   vertices);
   aex_gl_es2_EnableVertexAttribArray( 1);
   aex_gl_es2_VertexAttribPointer( 1,
                                   4,
                                   GL_ES2_FLOAT,
                                   GL_ES2_FALSE,
                                   0,
                                   colors);
   return( 0);
}


int   main( int argc, char *argv[])
{
   gl_es2_uint   program;
   int   running;
   SDL_Event   event;
   SDL_Window   *window;
   unsigned char   *pixels;

   (void) argc;
   (void) argv;

   if( ! SDL_Init( SDL_INIT_VIDEO))
   {
      fprintf( stderr, "SDL_Init failed: %s\n", SDL_GetError());
      return( 1);
   }

   window = SDL_CreateWindow( "mulle-aex-gl Sixteen Lines",
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

   if( init_gl( &program))
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
      demo_gradient_background( WINDOW_WIDTH, WINDOW_HEIGHT);
      aex_gl_es2_UseProgram( program);
      aex_gl_es2_LineWidth( 3.0f);
      aex_gl_es2_DrawArrays( GL_ES2_LINES, 0, 32);

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
   aex_gl_es2_DeleteProgram( program);
   SDL_DestroyWindow( window);
   SDL_Quit();
   return( 0);
}
