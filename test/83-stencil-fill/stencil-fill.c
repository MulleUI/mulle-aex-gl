#include <mulle-aex-gl/gl_es2_impl.h>

#include <math.h>
#include <stdio.h>
#include <stdlib.h>


#define W        64
#define H        64


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


/* Non-zero winding test at a point in window coordinates (y up). */
static int   winding_at( const float *xy, int n, float px, float py)
{
   float   ax, ay, bx, by;
   float   cross;
   int     i;
   int     winding;

   winding = 0;
   for( i = 0; i < n; i++)
   {
      ax = xy[ (i * 2) + 0];
      ay = xy[ (i * 2) + 1];
      bx = xy[ (((i + 1) % n) * 2) + 0];
      by = xy[ (((i + 1) % n) * 2) + 1];

      cross = (bx - ax) * (py - ay) - (by - ay) * (px - ax);
      if( ay <= py)
      {
         if( by > py && cross > 0.f)
            winding++;
      }
      else
      {
         if( by <= py && cross < 0.f)
            winding--;
      }
   }
   return( winding);
}


/* Distance of the point to the closest polygon edge, to skip boundary pixels. */
static float   edge_distance( const float *xy, int n, float px, float py)
{
   float   ax, ay, bx, by;
   float   dx, dy;
   float   t;
   float   ex, ey;
   float   d;
   float   best;
   int     i;

   best = 1e9f;
   for( i = 0; i < n; i++)
   {
      ax = xy[ (i * 2) + 0];
      ay = xy[ (i * 2) + 1];
      bx = xy[ (((i + 1) % n) * 2) + 0];
      by = xy[ (((i + 1) % n) * 2) + 1];

      dx = bx - ax;
      dy = by - ay;
      t  = ((px - ax) * dx + (py - ay) * dy) / (dx * dx + dy * dy);
      if( t < 0.f)
         t = 0.f;
      else if( t > 1.f)
         t = 1.f;
      ex = ax + t * dx;
      ey = ay + t * dy;
      d  = sqrtf( (px - ex) * (px - ex) + (py - ey) * (py - ey));
      if( d < best)
         best = d;
   }
   return( best);
}


int   main( int argc, char *argv[])
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
      "uniform vec4 uColor;\n"
      "void main()\n"
      "{\n"
      "   gl_FragColor = uColor;\n"
      "}\n";
   /* Two overlapping counter-clockwise triangles; the overlap must see two
    * increments from the same draw call. */
   static const float  overlap[ 12] =
      { -0.9f, -0.9f,   0.6f, -0.9f,  -0.9f,  0.6f,
        -0.6f, -0.6f,   0.9f, -0.6f,  -0.6f,  0.9f };
   float             star[ 10 * 2];
   float             ndc[ 10 * 2];
   float             quad[ 8];
   unsigned char     pixels[ W * H * 4];
   unsigned char     *p;
   float             angle;
   float             radius;
   float             px;
   float             py;
   float             d;
   gl_es2_int        color_location;
   gl_es2_uint       fragment_shader;
   gl_es2_uint       program;
   gl_es2_uint       vertex_shader;
   int               filled;
   int               holes;
   int               extra;
   int               i;
   int               r;
   int               x;
   int               y;

   r = aex_gl_es2_context_init( 32, 16, 0, W, H);
   if( r)
   {
      fprintf( stderr, "aex_gl_es2_context_init failed: %d\n", r);
      return( 1);
   }

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

   program = aex_gl_es2_CreateProgram();
   aex_gl_es2_AttachShader( program, vertex_shader);
   aex_gl_es2_AttachShader( program, fragment_shader);
   aex_gl_es2_BindAttribLocation( program, 0, "aPos");
   aex_gl_es2_LinkProgram( program);
   if( check_program( program))
      return( 1);

   aex_gl_es2_UseProgram( program);
   color_location = aex_gl_es2_GetUniformLocation( program, "uColor");
   if( color_location < 0)
   {
      fprintf( stderr, "uColor uniform not found\n");
      return( 1);
   }
   aex_gl_es2_Uniform4f( color_location, 1.0f, 0.0f, 0.0f, 1.0f);

   /* Five point star around the center of the framebuffer. */
   for( i = 0; i < 10; i++)
   {
      angle  = -1.5707963f + (float) i * 0.6283185f;
      radius = (i & 1) ? 12.0f : 28.0f;
      star[ (i * 2) + 0] = (W / 2) + radius * cosf( angle);
      star[ (i * 2) + 1] = (H / 2) + radius * sinf( angle);
      ndc[ (i * 2) + 0]  = star[ (i * 2) + 0] / (W / 2) - 1.0f;
      ndc[ (i * 2) + 1]  = star[ (i * 2) + 1] / (H / 2) - 1.0f;
   }

   /* Bounding quad covering the full viewport. */
   quad[ 0] = -1.0f; quad[ 1] = -1.0f;
   quad[ 2] =  1.0f; quad[ 3] = -1.0f;
   quad[ 4] = -1.0f; quad[ 5] =  1.0f;
   quad[ 6] =  1.0f; quad[ 7] =  1.0f;

   aex_gl_es2_Viewport( 0, 0, W, H);
   aex_gl_es2_ClearColor( 0.0f, 0.0f, 0.0f, 1.0f);
   aex_gl_es2_ClearStencil( 0);
   aex_gl_es2_Clear( GL_ES2_COLOR_BUFFER_BIT | GL_ES2_STENCIL_BUFFER_BIT);

   aex_gl_es2_EnableVertexAttribArray( 0);
   aex_gl_es2_VertexAttribPointer( 0, 2, GL_ES2_FLOAT, GL_ES2_FALSE, 0, ndc);

   aex_gl_es2_Enable( GL_ES2_STENCIL_TEST);
   aex_gl_es2_StencilMask( 0xff);
   aex_gl_es2_StencilFunc( GL_ES2_ALWAYS, 0, 0xff);
   aex_gl_es2_StencilOpSeparate( GL_ES2_FRONT,
                                 GL_ES2_KEEP, GL_ES2_KEEP, GL_ES2_INCR_WRAP);
   aex_gl_es2_StencilOpSeparate( GL_ES2_BACK,
                                 GL_ES2_KEEP, GL_ES2_KEEP, GL_ES2_DECR_WRAP);
   aex_gl_es2_ColorMask( GL_ES2_FALSE, GL_ES2_FALSE,
                         GL_ES2_FALSE, GL_ES2_FALSE);

   aex_gl_es2_DrawArrays( GL_ES2_TRIANGLE_FAN, 0, 10);

   aex_gl_es2_ColorMask( GL_ES2_TRUE, GL_ES2_TRUE,
                         GL_ES2_TRUE, GL_ES2_TRUE);
   aex_gl_es2_StencilFunc( GL_ES2_NOTEQUAL, 0, 0xff);
   aex_gl_es2_StencilOp( GL_ES2_KEEP, GL_ES2_KEEP, GL_ES2_ZERO);

   aex_gl_es2_VertexAttribPointer( 0, 2, GL_ES2_FLOAT, GL_ES2_FALSE, 0, quad);
   aex_gl_es2_DrawArrays( GL_ES2_TRIANGLE_STRIP, 0, 4);

   aex_gl_es2_ReadPixels( 0, 0, W, H, GL_ES2_RGBA, GL_ES2_UNSIGNED_BYTE,
                          pixels);

   holes = 0;
   extra = 0;
   for( y = 0; y < H; y++)
      for( x = 0; x < W; x++)
      {
         px = (float) x + 0.5f;
         py = (float) y + 0.5f;

         /* The fill rule decides pixels on the outline; skip those. */
         if( edge_distance( star, 10, px, py) < 1.0f)
            continue;

         filled = (winding_at( star, 10, px, py) != 0);
         p = &pixels[ (y * W + x) * 4];

         if( filled && p[ 0] < 128)
         {
            holes++;
            if( holes <= 10)
               fprintf( stderr, "hole %d,%d %u,%u,%u\n",
                        x, y, p[ 0], p[ 1], p[ 2]);
         }
         if( ! filled && p[ 0] >= 128)
         {
            extra++;
            if( extra <= 10)
               fprintf( stderr, "extra %d,%d %u,%u,%u\n",
                        x, y, p[ 0], p[ 1], p[ 2]);
         }
      }

   if( holes || extra)
   {
      fprintf( stderr, "star holes=%d extra=%d\n", holes, extra);
      return( 1);
   }

   /* Overlapping triangles in a single draw call must both increment the
    * stencil value; the overlap has to hold 2. */
   aex_gl_es2_ClearStencil( 0);
   aex_gl_es2_Clear( GL_ES2_COLOR_BUFFER_BIT | GL_ES2_STENCIL_BUFFER_BIT);

   aex_gl_es2_StencilFunc( GL_ES2_ALWAYS, 0, 0xff);
   aex_gl_es2_StencilOpSeparate( GL_ES2_FRONT,
                                 GL_ES2_KEEP, GL_ES2_KEEP, GL_ES2_INCR_WRAP);
   aex_gl_es2_StencilOpSeparate( GL_ES2_BACK,
                                 GL_ES2_KEEP, GL_ES2_KEEP, GL_ES2_DECR_WRAP);
   aex_gl_es2_ColorMask( GL_ES2_FALSE, GL_ES2_FALSE,
                         GL_ES2_FALSE, GL_ES2_FALSE);

   aex_gl_es2_VertexAttribPointer( 0, 2, GL_ES2_FLOAT, GL_ES2_FALSE,
                                   0, overlap);
   aex_gl_es2_DrawArrays( GL_ES2_TRIANGLES, 0, 6);

   aex_gl_es2_ColorMask( GL_ES2_TRUE, GL_ES2_TRUE,
                         GL_ES2_TRUE, GL_ES2_TRUE);
   aex_gl_es2_StencilFunc( GL_ES2_EQUAL, 2, 0xff);
   aex_gl_es2_StencilOp( GL_ES2_KEEP, GL_ES2_KEEP, GL_ES2_KEEP);
   aex_gl_es2_VertexAttribPointer( 0, 2, GL_ES2_FLOAT, GL_ES2_FALSE, 0, quad);
   aex_gl_es2_DrawArrays( GL_ES2_TRIANGLE_STRIP, 0, 4);

   aex_gl_es2_ReadPixels( 20, 20, 1, 1, GL_ES2_RGBA, GL_ES2_UNSIGNED_BYTE,
                          pixels);
   if( pixels[ 0] < 128)
   {
      fprintf( stderr, "overlapping triangles did not accumulate stencil "
                       "value 2 (got %u,%u,%u)\n",
               pixels[ 0], pixels[ 1], pixels[ 2]);
      return( 1);
   }

   aex_gl_es2_Disable( GL_ES2_STENCIL_TEST);

   if( aex_gl_es2_GetError() != GL_ES2_NO_ERROR)
   {
      fprintf( stderr, "glGetError reported an error\n");
      return( 1);
   }

   aex_gl_es2_DeleteShader( vertex_shader);
   aex_gl_es2_DeleteShader( fragment_shader);
   aex_gl_es2_DeleteProgram( program);

   printf( "headless GLES2 stencil fill OK\n");
   return( 0);
}
