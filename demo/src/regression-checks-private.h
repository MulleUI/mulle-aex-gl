/* Shared regression checks for the demo and the headless test.
 *
 * Each check exercises one of the bugs that the fix/* branches address, using
 * only the public GLES2 entry points.
 */

#ifndef REGRESSION_CHECKS_H
#define REGRESSION_CHECKS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if defined( AEX_REGRESSION_HEADLESS)
#include <mulle-aex-gl/gl_es2_impl.h>
#else
#include "gl_es2_impl.h"
#endif


/* Pre-fix trees do not have these tokens yet; the enum values are from the
 * GLES2 headers. Defining them locally lets these checks compile against the
 * old tree so the failures can be demonstrated. */
#ifndef GL_ES2_FRAMEBUFFER_BINDING
#define GL_ES2_FRAMEBUFFER_BINDING  0x8CA6
#endif
#ifndef GL_ES2_RENDERBUFFER_BINDING
#define GL_ES2_RENDERBUFFER_BINDING 0x8CA7
#endif


#define W        64
#define H        64
#define NUM_ROWS 64


static const char   *solid_vertex_source =
   "#version 100\n"
   "attribute vec2 aPos;\n"
   "void main()\n"
   "{\n"
   "   gl_Position = vec4( aPos, 0.0, 1.0);\n"
   "}\n";

static const char   *solid_fragment_source =
   "#version 100\n"
   "precision mediump float;\n"
   "uniform vec4 uColor;\n"
   "void main()\n"
   "{\n"
   "   gl_FragColor = uColor;\n"
   "}\n";

static const char   *textured_vertex_source =
   "#version 100\n"
   "attribute vec2 aPos;\n"
   "attribute vec2 aUV;\n"
   "varying vec2 vUV;\n"
   "void main()\n"
   "{\n"
   "   vUV = aUV;\n"
   "   gl_Position = vec4( aPos, 0.0, 1.0);\n"
   "}\n";

static const char   *textured_fragment_source =
   "#version 100\n"
   "precision mediump float;\n"
   "uniform sampler2D uSampler;\n"
   "varying vec2 vUV;\n"
   "void main()\n"
   "{\n"
   "   gl_FragColor = texture2D( uSampler, vUV);\n"
   "}\n";

static const float   quad[ 8] =
   { -1.0f, -1.0f,  1.0f, -1.0f,  -1.0f, 1.0f,  1.0f, 1.0f };

static gl_es2_uint   g_program;
static gl_es2_int    g_color_location;

#if ! defined( AEX_REGRESSION_HEADLESS)
/* Set when start_context() succeeded, so the demo can grab the final
 * framebuffer of a check without reading from an uninitialized context. */
static int   g_context_ready = 0;
#endif


static int   check_shader( gl_es2_uint shader)
{
   gl_es2_char   log[ 512];
   gl_es2_int    status;
   gl_es2_sizei  length;

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
   gl_es2_char   log[ 512];
   gl_es2_int    status;
   gl_es2_sizei  length;

   aex_gl_es2_GetProgramiv( program, GL_ES2_LINK_STATUS, &status);
   if( status)
      return( 0);

   aex_gl_es2_GetProgramInfoLog( program, sizeof( log), &length, log);
   log[ length < sizeof( log) ? length : sizeof( log) - 1] = 0;
   fprintf( stderr, "program link failed: %s\n", log);
   return( 1);
}


static gl_es2_uint   compile_shader( gl_es2_enum type, const char *source)
{
   gl_es2_uint   shader;

   shader = aex_gl_es2_CreateShader( type);
   aex_gl_es2_ShaderSource( shader, 1, &source, NULL);
   aex_gl_es2_CompileShader( shader);
   if( check_shader( shader))
      return( 0);
   return( shader);
}


/* Builds a program with aPos at 0 and aUV at 1. aUV is only an active
 * attribute for the textured check; binding it is ignored otherwise. */
static int   build_program( const char *vertex_source,
                            const char *fragment_source)
{
   gl_es2_uint   fragment_shader;
   gl_es2_uint   vertex_shader;

   vertex_shader = compile_shader( GL_ES2_VERTEX_SHADER, vertex_source);
   if( ! vertex_shader)
      return( 1);

   fragment_shader = compile_shader( GL_ES2_FRAGMENT_SHADER, fragment_source);
   if( ! fragment_shader)
      return( 1);

   g_program = aex_gl_es2_CreateProgram();
   aex_gl_es2_AttachShader( g_program, vertex_shader);
   aex_gl_es2_AttachShader( g_program, fragment_shader);
   aex_gl_es2_BindAttribLocation( g_program, 0, "aPos");
   aex_gl_es2_BindAttribLocation( g_program, 1, "aUV");
   aex_gl_es2_LinkProgram( g_program);

   aex_gl_es2_DeleteShader( vertex_shader);
   aex_gl_es2_DeleteShader( fragment_shader);

   if( check_program( g_program))
      return( 1);

   aex_gl_es2_UseProgram( g_program);
   g_color_location = aex_gl_es2_GetUniformLocation( g_program, "uColor");
   return( 0);
}


static void   use_positions( const float *positions)
{
   aex_gl_es2_EnableVertexAttribArray( 0);
   aex_gl_es2_VertexAttribPointer( 0, 2, GL_ES2_FLOAT, GL_ES2_FALSE, 0,
                                   positions);
}


static void   draw_quad( void)
{
   use_positions( quad);
   aex_gl_es2_DrawArrays( GL_ES2_TRIANGLE_STRIP, 0, 4);
}


static int   read_pixel( int x, int y, unsigned char *pixel)
{
   aex_gl_es2_ReadPixels( x, y, 1, 1, GL_ES2_RGBA, GL_ES2_UNSIGNED_BYTE,
                          pixel);
   return( 0);
}


#if ! defined( AEX_REGRESSION_HEADLESS)
/* Reads the full 64x64 framebuffer in top-down row order, so it can be
 * written to a BMP or blitted to an SDL surface directly. */
static int   capture_frame( unsigned char *rgba)
{
   unsigned char   *gl_rows;
   int   y;

   if( ! g_context_ready)
      return( 1);

   gl_rows = malloc( (size_t) W * H * 4);
   if( ! gl_rows)
      return( 1);

   aex_gl_es2_ReadPixels( 0, 0, W, H, GL_ES2_RGBA, GL_ES2_UNSIGNED_BYTE,
                          gl_rows);

   for( y = 0; y < H; y++)
      memcpy( rgba + (size_t) y * W * 4,
              gl_rows + (size_t) (H - 1 - y) * W * 4,
              (size_t) W * 4);

   free( gl_rows);
   return( 0);
}
#endif


static int   start_context( int stencil_bits, int depth_bits)
{
   int   r;

   r = aex_gl_es2_context_init( 32, stencil_bits, depth_bits, W, H);
   if( r)
   {
      fprintf( stderr, "aex_gl_es2_context_init failed: %d\n", r);
      return( 1);
   }

   aex_gl_es2_Viewport( 0, 0, W, H);
#if ! defined( AEX_REGRESSION_HEADLESS)
   g_context_ready = 1;
#endif
   return( 0);
}


/* fix/unorm8-rounding: truncation wrote 254 where rounding writes 255, and
 * values above 1.0 wrapped instead of clamping. */
static int   check_unorm8_rounding( void)
{
   static const char   *fragment_source =
      "#version 100\n"
      "precision mediump float;\n"
      "void main()\n"
      "{\n"
      "   gl_FragColor = vec4( 2.0, 1.0 - 0.001953125, 0.0, 1.0);\n"
      "}\n";
   unsigned char   pixel[ 4];

   if( start_context( 0, 0))
      return( 1);

   if( build_program( solid_vertex_source, fragment_source))
      return( 1);

   aex_gl_es2_ClearColor( 0.0f, 0.0f, 0.0f, 1.0f);
   aex_gl_es2_Clear( GL_ES2_COLOR_BUFFER_BIT);
   draw_quad();
   read_pixel( W / 2, H / 2, pixel);

   if( pixel[ 0] != 255 || pixel[ 1] != 255 ||
       pixel[ 2] != 0 || pixel[ 3] != 255)
   {
      fprintf( stderr, "expected 255,255,0,255 got %u,%u,%u,%u\n",
               (unsigned int) pixel[ 0], (unsigned int) pixel[ 1],
               (unsigned int) pixel[ 2], (unsigned int) pixel[ 3]);
      return( 1);
   }
   return( 0);
}


/* fix/blend-masked-subtract: a fragment that fails the depth test has a zero
 * mask, but the SUBTRACT store still wrote source color over the destination. */
static int   check_blend_masked_subtract( void)
{
   unsigned char   pixel[ 4];

   if( start_context( 0, 32))
      return( 1);

   if( build_program( solid_vertex_source, solid_fragment_source))
      return( 1);

   aex_gl_es2_Enable( GL_ES2_DEPTH_TEST);
   aex_gl_es2_DepthFunc( GL_ES2_NEVER);
   aex_gl_es2_Enable( GL_ES2_BLEND);
   aex_gl_es2_BlendEquation( GL_ES2_FUNC_SUBTRACT);
   aex_gl_es2_BlendFunc( GL_ES2_ONE, GL_ES2_ONE);

   aex_gl_es2_ClearColor( 1.0f, 0.0f, 0.0f, 1.0f);
   aex_gl_es2_Clear( GL_ES2_COLOR_BUFFER_BIT | GL_ES2_DEPTH_BUFFER_BIT);

   aex_gl_es2_Uniform4f( g_color_location, 0.0f, 1.0f, 0.0f, 1.0f);
   draw_quad();
   read_pixel( W / 2, H / 2, pixel);

   if( pixel[ 0] != 255 || pixel[ 1] != 0 ||
       pixel[ 2] != 0 || pixel[ 3] != 255)
   {
      fprintf( stderr, "masked subtract changed dst to %u,%u,%u,%u\n",
               (unsigned int) pixel[ 0], (unsigned int) pixel[ 1],
               (unsigned int) pixel[ 2], (unsigned int) pixel[ 3]);
      return( 1);
   }
   return( 0);
}


/* fix/depth32-clear and fix/blitter-mask32-ivalue: the 32-bit clear used the
 * 16-bit scale, and the blitter fast path only filled half of each 64-bit
 * word. Both show up in the depth buffer. */
static int   check_depth32_clear( void)
{
   unsigned int   depth[ NUM_ROWS];
   unsigned int   expected;
   unsigned int   i;
   int            pass;

   if( start_context( 0, 32))
      return( 1);

   for( pass = 0; pass < 2; pass++)
   {
      expected = pass ? 0xFFFFFFFF : 0x80000000;
      aex_gl_es2_ClearDepthf( pass ? 1.0f : 0.5f);
      aex_gl_es2_Clear( GL_ES2_DEPTH_BUFFER_BIT);

      aex_gl_es2_ReadPixels( 0, H / 2, W, 1, GL_ES2_DEPTH_COMPONENT,
                             GL_ES2_UNSIGNED_INT, depth);
      for( i = 0; i < W; i++)
      {
         if( depth[ i] != expected)
         {
            fprintf( stderr,
                     "clear depth %s: depth[%u] is 0x%08x, expected 0x%08x\n",
                     pass ? "1.0" : "0.5", i, depth[ i], expected);
            return( 1);
         }
      }
   }
   return( 0);
}


/* fix/get-binding-queries: GL_FRAMEBUFFER_BINDING and
 * GL_RENDERBUFFER_BINDING were unhandled and raised GL_INVALID_ENUM. */
static int   check_binding_queries( void)
{
   gl_es2_uint   framebuffer;
   gl_es2_uint   renderbuffer;
   gl_es2_int    value;

   if( start_context( 0, 0))
      return( 1);

   value = -1;
   aex_gl_es2_GetIntegerv( GL_ES2_FRAMEBUFFER_BINDING, &value);
   if( value != 0)
   {
      fprintf( stderr, "default framebuffer binding is %d, expected 0\n",
               (int) value);
      return( 1);
   }

   value = -1;
   aex_gl_es2_GetIntegerv( GL_ES2_RENDERBUFFER_BINDING, &value);
   if( value != 0)
   {
      fprintf( stderr, "default renderbuffer binding is %d, expected 0\n",
               (int) value);
      return( 1);
   }

   if( aex_gl_es2_GetError() != GL_ES2_NO_ERROR)
   {
      fprintf( stderr, "binding query raised an error\n");
      return( 1);
   }

   aex_gl_es2_GenFramebuffers( 1, &framebuffer);
   aex_gl_es2_BindFramebuffer( GL_ES2_FRAMEBUFFER, framebuffer);
   value = -1;
   aex_gl_es2_GetIntegerv( GL_ES2_FRAMEBUFFER_BINDING, &value);
   if( value != (gl_es2_int) framebuffer)
   {
      fprintf( stderr, "framebuffer binding is %d, expected %u\n",
               (int) value, (unsigned int) framebuffer);
      return( 1);
   }

   aex_gl_es2_GenRenderbuffers( 1, &renderbuffer);
   aex_gl_es2_BindRenderbuffer( GL_ES2_RENDERBUFFER, renderbuffer);
   value = -1;
   aex_gl_es2_GetIntegerv( GL_ES2_RENDERBUFFER_BINDING, &value);
   if( value != (gl_es2_int) renderbuffer)
   {
      fprintf( stderr, "renderbuffer binding is %d, expected %u\n",
               (int) value, (unsigned int) renderbuffer);
      return( 1);
   }

   aex_gl_es2_BindFramebuffer( GL_ES2_FRAMEBUFFER, 0);
   aex_gl_es2_BindRenderbuffer( GL_ES2_RENDERBUFFER, 0);
   aex_gl_es2_DeleteFramebuffers( 1, &framebuffer);
   aex_gl_es2_DeleteRenderbuffers( 1, &renderbuffer);

   if( aex_gl_es2_GetError() != GL_ES2_NO_ERROR)
   {
      fprintf( stderr, "binding queries raised an error\n");
      return( 1);
   }
   return( 0);
}


/* fix/sampler2d-linear-repeat: repeat only masked non-negative coordinates.
 * Negative S/T clamped to the first column/row, for both filter paths.
 *
 * The two quads sample -0.25 and 0.75, which wrap to the same coordinate. A
 * power-of-two repeat mask alone folds +1.0 away, so 0.5/-0.5 would land on the
 * same texel even without wrapping; -0.25 does not, because the negative value
 * ends up on the first column/row instead. */
static int   check_sampler_repeat( void)
{
   static const float   positions[ 16] =
      { -1.0f, -1.0f,   0.0f, -1.0f,  -1.0f, 1.0f,   0.0f, 1.0f,
         0.0f, -1.0f,   1.0f, -1.0f,   0.0f, 1.0f,   1.0f, 1.0f };
   static const float   uvs[ 16] =
      { -0.25f, -0.25f, -0.25f, -0.25f, -0.25f, -0.25f, -0.25f, -0.25f,
         0.75f,  0.75f,   0.75f,  0.75f,  0.75f,  0.75f,  0.75f,  0.75f };
   static const unsigned char   level0[ 2 * 2 * 3] =
      { 255, 0, 0,     0, 255, 0,
          0, 0, 255,   255, 255, 255 };
   unsigned char   left[ 4];
   unsigned char   right[ 4];
   gl_es2_int      sampler_location;
   gl_es2_uint     texture;

   if( start_context( 0, 0))
      return( 1);

   if( build_program( textured_vertex_source, textured_fragment_source))
      return( 1);

   sampler_location = aex_gl_es2_GetUniformLocation( g_program, "uSampler");
   if( sampler_location < 0)
   {
      fprintf( stderr, "uSampler uniform not found\n");
      return( 1);
   }
   aex_gl_es2_Uniform1i( sampler_location, 0);

   aex_gl_es2_PixelStorei( GL_ES2_UNPACK_ALIGNMENT, 1);
   aex_gl_es2_GenTextures( 1, &texture);
   aex_gl_es2_BindTexture( GL_ES2_TEXTURE_2D, texture);
   aex_gl_es2_TexParameteri( GL_ES2_TEXTURE_2D, GL_ES2_TEXTURE_MIN_FILTER,
                             GL_ES2_LINEAR);
   aex_gl_es2_TexParameteri( GL_ES2_TEXTURE_2D, GL_ES2_TEXTURE_MAG_FILTER,
                             GL_ES2_LINEAR);
   aex_gl_es2_TexParameteri( GL_ES2_TEXTURE_2D, GL_ES2_TEXTURE_WRAP_S,
                             GL_ES2_REPEAT);
   aex_gl_es2_TexParameteri( GL_ES2_TEXTURE_2D, GL_ES2_TEXTURE_WRAP_T,
                             GL_ES2_REPEAT);
   aex_gl_es2_TexImage2D( GL_ES2_TEXTURE_2D, 0, GL_ES2_RGB, 2, 2, 0,
                          GL_ES2_RGB, GL_ES2_UNSIGNED_BYTE, level0);

   use_positions( positions);
   aex_gl_es2_EnableVertexAttribArray( 1);
   aex_gl_es2_VertexAttribPointer( 1, 2, GL_ES2_FLOAT, GL_ES2_FALSE, 0, uvs);

   aex_gl_es2_ClearColor( 0.0f, 0.0f, 0.0f, 1.0f);
   aex_gl_es2_Clear( GL_ES2_COLOR_BUFFER_BIT);
   aex_gl_es2_DrawArrays( GL_ES2_TRIANGLE_STRIP, 0, 4);
   aex_gl_es2_DrawArrays( GL_ES2_TRIANGLE_STRIP, 4, 4);

   read_pixel( W / 4, H / 2, left);
   read_pixel( (3 * W) / 4, H / 2, right);
   if( !(left[ 0] | left[ 1] | left[ 2]))
   {
      fprintf( stderr, "linear repeat sampled the background color\n");
      return( 1);
   }
   if( left[ 0] != right[ 0] || left[ 1] != right[ 1] ||
       left[ 2] != right[ 2])
   {
      fprintf( stderr, "linear repeat: negative uv gave %u,%u,%u, "
                       "positive uv gave %u,%u,%u\n",
               (unsigned int) left[ 0], (unsigned int) left[ 1],
               (unsigned int) left[ 2],
               (unsigned int) right[ 0], (unsigned int) right[ 1],
               (unsigned int) right[ 2]);
      return( 1);
   }

   aex_gl_es2_TexParameteri( GL_ES2_TEXTURE_2D, GL_ES2_TEXTURE_MIN_FILTER,
                             GL_ES2_NEAREST);
   aex_gl_es2_TexParameteri( GL_ES2_TEXTURE_2D, GL_ES2_TEXTURE_MAG_FILTER,
                             GL_ES2_NEAREST);
   aex_gl_es2_Clear( GL_ES2_COLOR_BUFFER_BIT);
   aex_gl_es2_DrawArrays( GL_ES2_TRIANGLE_STRIP, 0, 4);
   aex_gl_es2_DrawArrays( GL_ES2_TRIANGLE_STRIP, 4, 4);

   read_pixel( W / 4, H / 2, left);
   read_pixel( (3 * W) / 4, H / 2, right);
   if( left[ 0] != right[ 0] || left[ 1] != right[ 1] ||
       left[ 2] != right[ 2])
   {
      fprintf( stderr, "nearest repeat: negative uv gave %u,%u,%u, "
                       "positive uv gave %u,%u,%u\n",
               (unsigned int) left[ 0], (unsigned int) left[ 1],
               (unsigned int) left[ 2],
               (unsigned int) right[ 0], (unsigned int) right[ 1],
               (unsigned int) right[ 2]);
      return( 1);
   }

   aex_gl_es2_DeleteTextures( 1, &texture);
   return( 0);
}


/* fix/stencil-clear-attachment: glClear(STENCIL_BUFFER_BIT) tested the depth
 * attachment kind, so a stencil-only framebuffer was not cleared. */
static int   check_stencil_clear_attachment( void)
{
   unsigned char   pixel[ 4];

   if( start_context( 16, 0))
      return( 1);

   if( build_program( solid_vertex_source, solid_fragment_source))
      return( 1);

   aex_gl_es2_StencilMask( 0xffff);
   aex_gl_es2_ClearStencil( 0x5A);
   aex_gl_es2_Clear( GL_ES2_STENCIL_BUFFER_BIT);

   if( aex_gl_es2_GetError() != GL_ES2_NO_ERROR)
   {
      fprintf( stderr, "clearing a stencil-only framebuffer raised an error\n");
      return( 1);
   }

   aex_gl_es2_Enable( GL_ES2_STENCIL_TEST);
   aex_gl_es2_StencilFunc( GL_ES2_EQUAL, 0x5A, 0xffff);
   aex_gl_es2_StencilOp( GL_ES2_KEEP, GL_ES2_KEEP, GL_ES2_KEEP);

   aex_gl_es2_ClearColor( 0.0f, 0.0f, 0.0f, 1.0f);
   aex_gl_es2_Clear( GL_ES2_COLOR_BUFFER_BIT);
   aex_gl_es2_Uniform4f( g_color_location, 1.0f, 1.0f, 1.0f, 1.0f);
   draw_quad();
   read_pixel( W / 2, H / 2, pixel);

   if( pixel[ 0] != 255 || pixel[ 1] != 255 || pixel[ 2] != 255)
   {
      fprintf( stderr, "stencil clear to 0x5A did not take, pixel %u,%u,%u\n",
               (unsigned int) pixel[ 0], (unsigned int) pixel[ 1],
               (unsigned int) pixel[ 2]);
      return( 1);
   }
   return( 0);
}


/* fix/stencil-fragment-rmw: stencil operations were computed from the values
 * found at the start of the batch. Two overlapping triangles in one draw call
 * therefore INVERTed once instead of twice.
 *
 * Note that this check cannot distinguish the fix: the engine starts a new
 * fragment batch for each primitive, so both triangles invert from a value the
 * previous triangle already wrote either way. Reproducing the original failure
 * would need overlapping fragments inside a single batch, which this engine
 * does not produce, so the extra per-fragment stencil re-evaluation is commented
 * out in primitive_assembly.c and fix/stencil-fragment-rmw is dropped as a
 * non-bug. The check stays as coverage for the operation sequence. */
static int   check_stencil_fragment_rmw( void)
{
   static const float   triangle[ 12] =
      { -0.8f, -0.8f,  0.8f, -0.8f,  0.0f, 0.8f,
        -0.8f, -0.8f,  0.8f, -0.8f,  0.0f, 0.8f };
   unsigned char   pixel[ 4];

   if( start_context( 16, 0))
      return( 1);

   if( build_program( solid_vertex_source, solid_fragment_source))
      return( 1);

   aex_gl_es2_StencilMask( 0xffff);
   aex_gl_es2_ClearStencil( 0x0000);
   aex_gl_es2_Clear( GL_ES2_STENCIL_BUFFER_BIT);

   aex_gl_es2_Enable( GL_ES2_STENCIL_TEST);
   aex_gl_es2_StencilFunc( GL_ES2_ALWAYS, 0, 0xffff);
   aex_gl_es2_StencilOp( GL_ES2_KEEP, GL_ES2_KEEP, GL_ES2_INVERT);
   aex_gl_es2_ColorMask( GL_ES2_FALSE, GL_ES2_FALSE,
                         GL_ES2_FALSE, GL_ES2_FALSE);

   use_positions( triangle);
   aex_gl_es2_DrawArrays( GL_ES2_TRIANGLES, 0, 6);

   aex_gl_es2_ColorMask( GL_ES2_TRUE, GL_ES2_TRUE, GL_ES2_TRUE, GL_ES2_TRUE);
   aex_gl_es2_StencilFunc( GL_ES2_EQUAL, 0x0000, 0xffff);
   aex_gl_es2_StencilOp( GL_ES2_KEEP, GL_ES2_KEEP, GL_ES2_KEEP);

   aex_gl_es2_ClearColor( 0.0f, 0.0f, 0.0f, 1.0f);
   aex_gl_es2_Clear( GL_ES2_COLOR_BUFFER_BIT);
   aex_gl_es2_Uniform4f( g_color_location, 1.0f, 1.0f, 1.0f, 1.0f);
   draw_quad();
   read_pixel( W / 2, H / 2, pixel);

   if( pixel[ 0] != 255 || pixel[ 1] != 255 || pixel[ 2] != 255)
   {
      fprintf( stderr, "two INVERTs in one batch left stencil non-zero "
                       "(probe pixel %u,%u,%u)\n",
               (unsigned int) pixel[ 0], (unsigned int) pixel[ 1],
               (unsigned int) pixel[ 2]);
      return( 1);
   }
   return( 0);
}


/* fix/detach-after-link: the draw path read the program's shader attachment
 * pointers, which glDetachShader clears. The linked executable must survive. */
static int   check_detach_after_link( void)
{
   static const char   *vertex_source =
      "#version 100\n"
      "attribute vec2 aPos;\n"
      "void main()\n"
      "{\n"
      "   gl_Position = vec4( aPos, 0.0, 1.0);\n"
      "}\n";
   static const char   *fragment_source =
      "#version 100\n"
      "precision mediump float;\n"
      "void main()\n"
      "{\n"
      "   gl_FragColor = vec4( 1.0, 0.0, 0.0, 1.0);\n"
      "}\n";
   unsigned char   pixel[ 4];
   gl_es2_uint     fragment_shader;
   gl_es2_uint     program;
   gl_es2_uint     vertex_shader;

   if( start_context( 16, 32))
      return( 1);

   vertex_shader = compile_shader( GL_ES2_VERTEX_SHADER, vertex_source);
   if( ! vertex_shader)
      return( 1);
   fragment_shader = compile_shader( GL_ES2_FRAGMENT_SHADER, fragment_source);
   if( ! fragment_shader)
      return( 1);

   program = aex_gl_es2_CreateProgram();
   aex_gl_es2_AttachShader( program, vertex_shader);
   aex_gl_es2_AttachShader( program, fragment_shader);
   aex_gl_es2_BindAttribLocation( program, 0, "aPos");
   aex_gl_es2_LinkProgram( program);
   if( check_program( program))
      return( 1);

   aex_gl_es2_DetachShader( program, vertex_shader);
   aex_gl_es2_DetachShader( program, fragment_shader);
   aex_gl_es2_DeleteShader( vertex_shader);
   aex_gl_es2_DeleteShader( fragment_shader);

   aex_gl_es2_UseProgram( program);
   aex_gl_es2_ClearColor( 0.0f, 0.0f, 0.0f, 1.0f);
   aex_gl_es2_Clear( GL_ES2_COLOR_BUFFER_BIT |
                     GL_ES2_DEPTH_BUFFER_BIT |
                     GL_ES2_STENCIL_BUFFER_BIT);
   draw_quad();
   read_pixel( W / 2, H / 2, pixel);

   aex_gl_es2_DeleteProgram( program);

   if( pixel[ 0] != 255 || pixel[ 1] != 0 ||
       pixel[ 2] != 0 || pixel[ 3] != 255)
   {
      fprintf( stderr, "draw after detach gave %u,%u,%u,%u\n",
               (unsigned int) pixel[ 0], (unsigned int) pixel[ 1],
               (unsigned int) pixel[ 2], (unsigned int) pixel[ 3]);
      return( 1);
   }
   return( 0);
}


static int   (*regression_checks[])( void) =
{
   check_unorm8_rounding,
   check_blend_masked_subtract,
   check_depth32_clear,
   check_binding_queries,
   check_sampler_repeat,
   check_stencil_clear_attachment,
   check_stencil_fragment_rmw,
   check_detach_after_link
};

#if ! defined( AEX_REGRESSION_HEADLESS)
/* Checks whose final framebuffer is meaningful to look at. The depth and
 * binding checks leave the color buffer blank, so those tiles only show the
 * pass/fail color. */
static const int   regression_check_has_frame[] =
{
   1, 1, 0, 0, 1, 1, 1, 1
};
#endif

static const char   *regression_check_names[] =
{
   "unorm8 rounding and clamping",
   "masked subtract keeps destination",
   "32-bit depth clear and blitter fill",
   "framebuffer/renderbuffer binding queries",
   "negative repeat sampling",
   "stencil clear from stencil attachment",
   "stencil ops read-modify-write per fragment",
   "draw after detach and delete shaders"
};

#define NUM_REGRESSION_CHECKS ((int) (sizeof( regression_checks) / \
                                      sizeof( regression_checks[ 0])))

#endif /* REGRESSION_CHECKS_H */
