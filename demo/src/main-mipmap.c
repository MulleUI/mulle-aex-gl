#include <SDL3/SDL.h>

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "demo-common.h"
#include "gl_es2_impl.h"

#include "../../renderbmp/smiley.h"


#define WINDOW_WIDTH  800
#define WINDOW_HEIGHT 600


static const char   *vertex_source =
   "#version 100\n"
   "attribute vec4 a_position;\n"
   "attribute vec2 a_texcoord;\n"
   "varying vec2 v_texcoord;\n"
   "void main()\n"
   "{\n"
   "   v_texcoord = a_texcoord;\n"
   "   gl_Position = a_position;\n"
   "   gl_Position.x *= gl_Position.w;\n"
   "   gl_Position.y *= gl_Position.w;\n"
   "}\n";

static const char   *fragment_source =
   "#version 100\n"
   "precision highp float;\n"
   "varying vec2 v_texcoord;\n"
   "uniform sampler2D u_texture;\n"
   "void main()\n"
   "{\n"
   "   gl_FragColor = vec4( texture2D( u_texture, v_texcoord).xyz, 1.0);\n"
   "}\n";

static const float   vertices[] =
{
   -1.0f + 2.0f * (  8.0f / 256.0f), 1.0f - 2.0f * (  8.0f / 256.0f), -1.0f, 9.0f,
   -1.0f + 2.0f * (128.0f / 256.0f), 1.0f - 2.0f * ( 16.0f / 256.0f), -1.0f, 9.0f,
   -1.0f + 2.0f * ( 16.0f / 256.0f), 1.0f - 2.0f * (248.0f / 256.0f), -1.0f, 1.0f,
   -1.0f + 2.0f * (136.0f / 256.0f), 1.0f - 2.0f * (256.0f / 256.0f), -1.0f, 1.0f
};

static const float   texcoords[] =
{
   0.0f, 10.0f,
   10.0f, 10.0f,
   0.0f, 0.0f,
   10.0f, 0.0f
};

static const uint32_t   indices[] =
{
   0, 1, 2
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


static int   upload_smiley( gl_es2_uint *texture)
{
   static unsigned char   mipmap_smiley[256 * 256 * 3];
   static unsigned char   smiley[256 * 256 * 3];

   static uint8_t   color_cycle[] =
   {
      0xFF, 0x00, 0x00,
      0xFF, 0xFF, 0x00,
      0x00, 0xFF, 0x00,
      0x00, 0xFF, 0xFF,
      0x00, 0x00, 0xFF,
      0xFF, 0x00, 0xFF
   };

   int   level;
   size_t   num_colors_in_cycle;
   size_t   smiley_column;
   size_t   smiley_row;

   num_colors_in_cycle = sizeof( color_cycle) / 3;

   for( smiley_row = 0; smiley_row < 256; ++smiley_row)
   {
      for( smiley_column = 0; smiley_column < 256; ++smiley_column)
      {
         size_t   source_index;
         size_t   target_index;

         source_index = smiley_row * 256 + smiley_column;
         target_index = (256 - smiley_row - 1) * 256 * 3 + smiley_column * 3;
         smiley[target_index + 0] = g_smiley_256x256_luminance_data_[source_index];
         smiley[target_index + 1] = g_smiley_256x256_luminance_data_[source_index];
         smiley[target_index + 2] = g_smiley_256x256_luminance_data_[source_index];
      }
   }

   aex_gl_es2_ActiveTexture( GL_ES2_TEXTURE0);
   aex_gl_es2_GenTextures( 1, texture);
   aex_gl_es2_BindTexture( GL_ES2_TEXTURE_2D, *texture);

   aex_gl_es2_TexImage2D( GL_ES2_TEXTURE_2D,
                          0,
                          GL_ES2_RGB,
                          256,
                          256,
                          0,
                          GL_ES2_RGB,
                          GL_ES2_UNSIGNED_BYTE,
                          smiley);

   for( level = 1; level < 9; ++level)
   {
      size_t   smiley_dst_height;
      size_t   smiley_dst_stride;
      size_t   smiley_dst_width;
      size_t   smiley_src_stride;
      size_t   smiley_src_width;

      smiley_src_width = 256 >> (level - 1);
      smiley_dst_width = smiley_src_width / 2;
      smiley_dst_height = smiley_dst_width;
      smiley_src_stride = (smiley_src_width * 3 + 4 - 1) & ~(4 - 1);
      smiley_dst_stride = (smiley_dst_width * 3 + 4 - 1) & ~(4 - 1);

      for( smiley_row = 0; smiley_row < smiley_dst_height; ++smiley_row)
      {
         for( smiley_column = 0; smiley_column < smiley_dst_width; ++smiley_column)
         {
            unsigned char   *dst;
            unsigned char   *dst_shaded;
            unsigned char   *src_bl;
            unsigned char   *src_br;
            unsigned char   *src_tl;
            unsigned char   *src_tr;
            size_t   component;

            dst = smiley + smiley_row * smiley_dst_stride + 3 * smiley_column;
            dst_shaded = mipmap_smiley + smiley_row * smiley_dst_stride + 3 * smiley_column;
            src_tl = smiley + smiley_row * 2 * smiley_src_stride + 3 * 2 * smiley_column;
            src_tr = src_tl + 3;
            src_bl = src_tl + smiley_src_stride;
            src_br = src_bl + 3;

            for( component = 0; component < 3; ++component)
            {
               unsigned char   color_cycle_component;
               unsigned char   result;

               result = (unsigned char) ((((uint32_t) src_tl[component])
                                          + ((uint32_t) src_tr[component])
                                          + ((uint32_t) src_bl[component])
                                          + ((uint32_t) src_br[component])) / 4);
               color_cycle_component = color_cycle[((level - 1) % num_colors_in_cycle) * 3 + component];
               dst[component] = result;
               dst_shaded[component] = result + ((((uint32_t) (0xFF - result)) * color_cycle_component) >> 8);
            }
         }
      }

      aex_gl_es2_TexImage2D( GL_ES2_TEXTURE_2D,
                             level,
                             GL_ES2_RGB,
                             (gl_es2_sizei) smiley_dst_width,
                             (gl_es2_sizei) smiley_dst_height,
                             0,
                             GL_ES2_RGB,
                             GL_ES2_UNSIGNED_BYTE,
                             mipmap_smiley);
   }

   aex_gl_es2_TexParameteri( GL_ES2_TEXTURE_2D, GL_ES2_TEXTURE_MIN_FILTER, GL_ES2_LINEAR_MIPMAP_LINEAR);
   aex_gl_es2_TexParameteri( GL_ES2_TEXTURE_2D, GL_ES2_TEXTURE_MAG_FILTER, GL_ES2_LINEAR);
   aex_gl_es2_TexParameteri( GL_ES2_TEXTURE_2D, GL_ES2_TEXTURE_WRAP_S, GL_ES2_REPEAT);
   aex_gl_es2_TexParameteri( GL_ES2_TEXTURE_2D, GL_ES2_TEXTURE_WRAP_T, GL_ES2_REPEAT);
   return( 0);
}


static int   init_gl( gl_es2_uint *program, gl_es2_uint *texture)
{
   gl_es2_int   texture_location;
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
   aex_gl_es2_BindAttribLocation( *program, 1, "a_texcoord");
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
                                   2,
                                   GL_ES2_FLOAT,
                                   GL_ES2_FALSE,
                                   0,
                                   texcoords);

   if( upload_smiley( texture))
      return( 1);

   texture_location = aex_gl_es2_GetUniformLocation( *program, "u_texture");
   aex_gl_es2_Uniform1i( texture_location, 0);
   return( 0);
}


int   main( int argc, char *argv[])
{
   gl_es2_uint   program;
   gl_es2_uint   texture;
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

   window = SDL_CreateWindow( "mulle-aex-gl Mipmap Triangle",
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

   if( init_gl( &program, &texture))
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
      aex_gl_es2_BindTexture( GL_ES2_TEXTURE_2D, texture);
      aex_gl_es2_DrawElements( GL_ES2_TRIANGLES, 3, GL_ES2_UNSIGNED_INT, indices);

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
   aex_gl_es2_DeleteTextures( 1, &texture);
   aex_gl_es2_DeleteProgram( program);
   SDL_DestroyWindow( window);
   SDL_Quit();
   return( 0);
}
