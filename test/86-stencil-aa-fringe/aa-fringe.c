#include <mulle-aex-gl/gl_es2_impl.h>

#include <math.h>
#include <stdio.h>


#define W          64
#define H          64
#define SEGMENTS   48
#define DISCS      2
#define FILL_VERTS (DISCS * SEGMENTS * 3)


static const float   disc_x[ DISCS] = { 24.0f, 40.0f };
static const float   disc_y[ DISCS] = { 32.0f, 32.0f };


static float   to_ndc( float v, float half)
{
   return( v / half - 1.0f);
}


static void   build_disc( float *outline, float *verts, float cx, float cy,
                          float radius)
{
   float   angle;
   float   ax, ay;
   float   bx, by;
   int     i;
   int     j;

   for( i = 0; i < SEGMENTS; i++)
   {
      angle = (float) i * (6.2831853f / (float) SEGMENTS);
      outline[ (i * 2) + 0] = cx + radius * cosf( angle);
      outline[ (i * 2) + 1] = cy + radius * sinf( angle);
   }

   for( i = 0; i < SEGMENTS; i++)
   {
      j = (i + 1) % SEGMENTS;
      ax = outline[ (i * 2) + 0];
      ay = outline[ (i * 2) + 1];
      bx = outline[ (j * 2) + 0];
      by = outline[ (j * 2) + 1];

      verts[ 0] = to_ndc( cx, W / 2);
      verts[ 1] = to_ndc( cy, H / 2);
      verts[ 2] = to_ndc( ax, W / 2);
      verts[ 3] = to_ndc( ay, H / 2);
      verts[ 4] = to_ndc( bx, W / 2);
      verts[ 5] = to_ndc( by, H / 2);
      verts  += 6;
   }
}


/* Distance from a point to the convex outline (window coordinates, y up). */
static float   distance_to_outline( const float *outline, float px, float py)
{
   float   ax, ay, bx, by;
   float   dx, dy;
   float   t;
   float   ex, ey;
   float   d;
   float   best;
   int     i;
   int     j;

   best = 1e9f;
   for( i = 0; i < SEGMENTS; i++)
   {
      j = (i + 1) % SEGMENTS;
      ax = outline[ (i * 2) + 0];
      ay = outline[ (i * 2) + 1];
      bx = outline[ (j * 2) + 0];
      by = outline[ (j * 2) + 1];

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


static int   inside_outline( const float *outline, float px, float py)
{
   float   ax, ay, bx, by;
   int     i;
   int     j;

   for( i = 0; i < SEGMENTS; i++)
   {
      j = (i + 1) % SEGMENTS;
      ax = outline[ (i * 2) + 0];
      ay = outline[ (i * 2) + 1];
      bx = outline[ (j * 2) + 0];
      by = outline[ (j * 2) + 1];
      if( (bx - ax) * (py - ay) - (by - ay) * (px - ax) < 0.f)
         return( 0);
    }
   return( 1);
}


/* Negative inside the union of both discs, positive outside. */
static float   signed_distance( const float *outline, float px, float py)
{
   const float   *second;
   float         d0;
   float         d1;
   float         d;

   second = outline + SEGMENTS * 2;
   d0 = distance_to_outline( outline, px, py);
   d1 = distance_to_outline( second, px, py);
   d = (d0 < d1) ? d0 : d1;

   if( inside_outline( outline, px, py) ||
       inside_outline( second, px, py))
      d = -d;
   return( d);
}


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
   static const float   quad[ 8] =
      { -1.0f, -1.0f,  1.0f, -1.0f,  -1.0f, 1.0f,  1.0f, 1.0f };
   unsigned char     pixels[ W * H * 4];
   float             outline[ DISCS * SEGMENTS * 2];
   float             fringe_outline[ DISCS * SEGMENTS * 2];
   float             fill[ FILL_VERTS * 2];
   float             fringe[ FILL_VERTS * 2];
   unsigned char     *p;
   gl_es2_int        color_location;
   gl_es2_uint       fragment_shader;
   gl_es2_uint       program;
   gl_es2_uint       vertex_shader;
   float             px;
   float             py;
   float             d;
   int               failures;
   int               fringe_bad;
   int               holes;
   int               left_over;
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

   /* Two subpaths in one fill: two overlapping discs, tessellated into one
    * triangle list so both subpaths share the same fragment batches. */
   build_disc( outline,
               fill,
               disc_x[ 0], disc_y[ 0], 12.0f);
   build_disc( outline + SEGMENTS * 2,
               fill + SEGMENTS * 3 * 2,
               disc_x[ 1], disc_y[ 1], 12.0f);

   /* The fringe pass covers three pixels outside the outline. The expanded
    * discs must not overwrite the reference outline used for the checks. */
   build_disc( fringe_outline,
               fringe,
               disc_x[ 0], disc_y[ 0], 15.0f);
   build_disc( fringe_outline + SEGMENTS * 2,
               fringe + SEGMENTS * 3 * 2,
               disc_x[ 1], disc_y[ 1], 15.0f);

   aex_gl_es2_Viewport( 0, 0, W, H);
   aex_gl_es2_ClearColor( 0.0f, 0.0f, 0.0f, 1.0f);
   aex_gl_es2_StencilMask( 0xffff);
   aex_gl_es2_ClearStencil( 0);
   aex_gl_es2_Clear( GL_ES2_COLOR_BUFFER_BIT | GL_ES2_STENCIL_BUFFER_BIT);

   aex_gl_es2_EnableVertexAttribArray( 0);
   aex_gl_es2_Enable( GL_ES2_STENCIL_TEST);

   /* Pass 1: winding mask. */
   aex_gl_es2_StencilMask( 0xffff);
   aex_gl_es2_StencilFunc( GL_ES2_ALWAYS, 0, 0xffff);
   aex_gl_es2_StencilOpSeparate( GL_ES2_FRONT,
                                 GL_ES2_KEEP, GL_ES2_KEEP, GL_ES2_INCR_WRAP);
   aex_gl_es2_StencilOpSeparate( GL_ES2_BACK,
                                 GL_ES2_KEEP, GL_ES2_KEEP, GL_ES2_DECR_WRAP);
   aex_gl_es2_ColorMask( GL_ES2_FALSE, GL_ES2_FALSE,
                         GL_ES2_FALSE, GL_ES2_FALSE);
   aex_gl_es2_VertexAttribPointer( 0, 2, GL_ES2_FLOAT, GL_ES2_FALSE, 0, fill);
   aex_gl_es2_DrawArrays( GL_ES2_TRIANGLES, 0, FILL_VERTS);

   /* Pass 2: fringe where the winding mask is zero. */
   aex_gl_es2_ColorMask( GL_ES2_TRUE, GL_ES2_TRUE,
                         GL_ES2_TRUE, GL_ES2_TRUE);
   aex_gl_es2_StencilFunc( GL_ES2_EQUAL, 0, 0xffff);
   aex_gl_es2_StencilOp( GL_ES2_KEEP, GL_ES2_KEEP, GL_ES2_KEEP);
   aex_gl_es2_Uniform4f( color_location, 0.0f, 1.0f, 0.0f, 1.0f);
   aex_gl_es2_VertexAttribPointer( 0, 2, GL_ES2_FLOAT, GL_ES2_FALSE, 0,
                                   fringe);
   aex_gl_es2_DrawArrays( GL_ES2_TRIANGLES, 0, FILL_VERTS);

   /* Pass 3: interior where the winding mask is non-zero. */
   aex_gl_es2_StencilFunc( GL_ES2_NOTEQUAL, 0, 0xffff);
   aex_gl_es2_StencilOp( GL_ES2_KEEP, GL_ES2_KEEP, GL_ES2_ZERO);
   aex_gl_es2_Uniform4f( color_location, 1.0f, 0.0f, 0.0f, 1.0f);
   aex_gl_es2_VertexAttribPointer( 0, 2, GL_ES2_FLOAT, GL_ES2_FALSE, 0, quad);
   aex_gl_es2_DrawArrays( GL_ES2_TRIANGLE_STRIP, 0, 4);

   aex_gl_es2_ReadPixels( 0, 0, W, H, GL_ES2_RGBA, GL_ES2_UNSIGNED_BYTE,
                          pixels);

   holes       = 0;
   fringe_bad  = 0;
   left_over   = 0;
   for( y = 0; y < H; y++)
      for( x = 0; x < W; x++)
      {
         px = (float) x + 0.5f;
         py = (float) y + 0.5f;
         d  = signed_distance( outline, px, py);
         p  = &pixels[ (y * W + x) * 4];

         /* Interior, away from the outline. */
         if( d <= -2.0f)
         {
            if( p[ 0] < 128 || p[ 1] >= 64)
            {
               holes++;
               if( holes <= 10)
                  fprintf( stderr, "hole %d,%d sd %g %u,%u,%u\n",
                           x, y, (double) d, p[ 0], p[ 1], p[ 2]);
            }
            continue;
         }

         /* Just outside the outline: the fringe must be present and
          * continuous, otherwise the edge is dotted. */
         if( d >= 1.0f && d <= 2.5f)
         {
            if( p[ 1] < 128 || p[ 0] >= 64)
            {
               fringe_bad++;
               if( fringe_bad <= 10)
                  fprintf( stderr, "fringe gap %d,%d sd %g %u,%u,%u\n",
                           x, y, (double) d, p[ 0], p[ 1], p[ 2]);
            }
            continue;
         }

         /* Far outside: nothing may have painted there. */
         if( d >= 6.0f)
         {
            if( p[ 0] >= 32 || p[ 1] >= 32 || p[ 2] >= 32)
            {
               left_over++;
               if( left_over <= 10)
                  fprintf( stderr, "outside paint %d,%d sd %g %u,%u,%u\n",
                           x, y, (double) d, p[ 0], p[ 1], p[ 2]);
            }
         }
      }

   failures = holes + fringe_bad + left_over;
   if( failures)
   {
      fprintf( stderr, "holes=%d fringe gaps=%d outside paint=%d\n",
               holes, fringe_bad, left_over);
      return( 1);
   }

   if( aex_gl_es2_GetError() != GL_ES2_NO_ERROR)
   {
      fprintf( stderr, "glGetError reported an error\n");
      return( 1);
   }

   aex_gl_es2_DeleteShader( vertex_shader);
   aex_gl_es2_DeleteShader( fragment_shader);
   aex_gl_es2_DeleteProgram( program);

   printf( "headless GLES2 stencil AA fringe OK\n");
   return( 0);
}
