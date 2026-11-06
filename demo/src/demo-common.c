#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "demo-common.h"


int   demo_check_shader( gl_es2_uint shader)
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


int   demo_check_program( gl_es2_uint program)
{
   char   log[ 256];
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


static const uint8_t   fps_font[ 14][ 7] =
{
   { 0x0E, 0x11, 0x13, 0x15, 0x19, 0x11, 0x0E }, /* 0 */
   { 0x04, 0x0C, 0x04, 0x04, 0x04, 0x04, 0x0E }, /* 1 */
   { 0x0E, 0x11, 0x01, 0x02, 0x04, 0x08, 0x1F }, /* 2 */
   { 0x1F, 0x02, 0x04, 0x02, 0x01, 0x11, 0x0E }, /* 3 */
   { 0x02, 0x06, 0x0A, 0x12, 0x1F, 0x02, 0x02 }, /* 4 */
   { 0x1F, 0x10, 0x1E, 0x01, 0x01, 0x11, 0x0E }, /* 5 */
   { 0x06, 0x08, 0x10, 0x1E, 0x11, 0x11, 0x0E }, /* 6 */
   { 0x1F, 0x01, 0x02, 0x04, 0x08, 0x08, 0x08 }, /* 7 */
   { 0x0E, 0x11, 0x11, 0x0E, 0x11, 0x11, 0x0E }, /* 8 */
   { 0x0E, 0x11, 0x11, 0x0F, 0x01, 0x02, 0x0C }, /* 9 */
   { 0x1F, 0x10, 0x10, 0x1E, 0x10, 0x10, 0x10 }, /* F */
   { 0x1E, 0x11, 0x11, 0x1E, 0x10, 0x10, 0x10 }, /* P */
   { 0x0F, 0x10, 0x10, 0x0E, 0x01, 0x01, 0x1E }, /* S */
   { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }  /* space */
};


static int   fps_glyph_index( char c)
{
   if( c >= '0' && c <= '9')
      return( c - '0');

   switch( c)
   {
      case 'F' : return( 10);
      case 'P' : return( 11);
      case 'S' : return( 12);
      default  : return( 13);
   }
}


static void   draw_fps_character( unsigned char *pixels,
                                  int width,
                                  int height,
                                  int x,
                                  int y,
                                  int scale,
                                  char c)
{
   const uint8_t   *glyph;
   int   column;
   int   row;
   int   sx;
   int   sy;

   glyph = fps_font[ fps_glyph_index( c)];
   for( row = 0; row < 7; row++)
   {
      for( column = 0; column < 5; column++)
      {
         if( ! (glyph[ row] & (1 << (4 - column))))
            continue;

         for( sy = 0; sy < scale; sy++)
         {
            for( sx = 0; sx < scale; sx++)
            {
               int   px;
               int   py;
               unsigned char   *pixel;

               px = x + column * scale + sx;
               py = y + row * scale + sy;
               if( px < 0 || px >= width || py < 0 || py >= height)
                  continue;

               pixel = pixels + (py * width + px) * 4;
               pixel[ 0] = 0xFF;
               pixel[ 1] = 0xFF;
               pixel[ 2] = 0xFF;
               pixel[ 3] = 0xFF;
            }
         }
      }
   }
}


static void   draw_fps( unsigned char *pixels,
                        int width,
                        int height,
                        unsigned int fps)
{
   char   text[ 16];
   int   length;
   int   scale;
   int   text_height;
   int   text_width;
   int   x;
   int   y;
   int   row;
   int   column;

   snprintf( text, sizeof( text), "FPS %u", fps);
   length = (int) strlen( text);
   scale = 2;
   text_width = length * 6 * scale - scale;
   text_height = 7 * scale;

   x = 8;
   y = 8;

   for( row = y - 4; row < y + text_height + 4; row++)
   {
      for( column = x - 4; column < x + text_width + 4; column++)
      {
         unsigned char   *pixel;

         if( column < 0 || column >= width || row < 0 || row >= height)
            continue;

         pixel = pixels + (row * width + column) * 4;
         pixel[ 0] = (unsigned char) (pixel[ 0] / 3);
         pixel[ 1] = (unsigned char) (pixel[ 1] / 3);
         pixel[ 2] = (unsigned char) (pixel[ 2] / 3);
         pixel[ 3] = 0xFF;
      }
   }

   for( length = 0; text[ length]; length++)
      draw_fps_character( pixels,
                          width,
                          height,
                          x + length * 6 * scale,
                          y,
                          scale,
                          text[ length]);
}


int   demo_present( SDL_Window *window, unsigned char *pixels)
{
   static Uint64   fps_last_ticks;
   static unsigned int   fps_frames;
   static unsigned int   fps_value;
   SDL_Surface   *destination;
   SDL_Surface   *source;
   int   height;
   int   width;
   Uint64   now;

   now = SDL_GetTicks();
   if( ! fps_last_ticks)
      fps_last_ticks = now;
   fps_frames++;
   if( now - fps_last_ticks >= 500)
   {
      fps_value = (unsigned int) (((Uint64) fps_frames * 1000 +
                                  (now - fps_last_ticks) / 2) /
                                 (now - fps_last_ticks));
      fps_frames = 0;
      fps_last_ticks = now;
   }

   destination = SDL_GetWindowSurface( window);
   if( ! destination)
   {
      fprintf( stderr, "SDL_GetWindowSurface failed: %s\n", SDL_GetError());
      return( 1);
   }

   SDL_GetWindowSize( window, &width, &height);
   source = SDL_CreateSurfaceFrom( width,
                                   height,
                                   SDL_PIXELFORMAT_RGBA32,
                                   pixels,
                                   width * 4);
   if( ! source)
   {
      fprintf( stderr, "SDL_CreateSurfaceFrom failed: %s\n", SDL_GetError());
      return( 1);
   }

   if( ! SDL_SetSurfaceBlendMode( source, SDL_BLENDMODE_NONE))
   {
      fprintf( stderr, "SDL_SetSurfaceBlendMode failed: %s\n", SDL_GetError());
      SDL_DestroySurface( source);
      return( 1);
   }

   if( ! SDL_FlipSurface( source, SDL_FLIP_VERTICAL))
   {
      fprintf( stderr, "SDL_FlipSurface failed: %s\n", SDL_GetError());
      SDL_DestroySurface( source);
      return( 1);
   }

   draw_fps( pixels, width, height, fps_value);

   if( ! SDL_BlitSurface( source, NULL, destination, NULL))
   {
      fprintf( stderr, "SDL_BlitSurface failed: %s\n", SDL_GetError());
      SDL_DestroySurface( source);
      return( 1);
   }

   SDL_DestroySurface( source);

   if( ! SDL_UpdateWindowSurface( window))
   {
      fprintf( stderr, "SDL_UpdateWindowSurface failed: %s\n", SDL_GetError());
      return( 1);
   }

   return( 0);
}


void  demo_gradient_background( int width, int height)
{
   int   row;

   for( row = 0; row < height; row++)
   {
      uint8_t   rgba[4];

      rgba[0] = (uint8_t) ((row * 256) / (2 * height));
      rgba[1] = 0;
      rgba[2] = (uint8_t) ((row * 256) / (4 * height) + 64);
      rgba[3] = 255;

      aex_gl_es2_ClearColor( rgba[0] / 255.0f,
                             rgba[1] / 255.0f,
                             rgba[2] / 255.0f,
                             rgba[3] / 255.0f);
      aex_gl_es2_Scissor( 0, height - row - 1, width, 1);
      aex_gl_es2_Enable( GL_ES2_SCISSOR_TEST);
      aex_gl_es2_Clear( GL_ES2_COLOR_BUFFER_BIT);
   }

   aex_gl_es2_Scissor( 0, 0, width, height);
   aex_gl_es2_Disable( GL_ES2_SCISSOR_TEST);
}
