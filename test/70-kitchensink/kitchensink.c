#include <mulle-aex-gl/gl_es2_impl.h>

#include <math.h>
#include <stdio.h>
#include <stdlib.h>


#define W        288
#define H         32
#define TILE      32
#define COLUMNS    9


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


static void   make_checker( unsigned char *data)
{
   unsigned char   *p;
   int             x;
   int             y;

   for( y = 0; y < 4; y++)
      for( x = 0; x < 4; x++)
      {
         p = &data[ (y * 4 + x) * 4];
         if( (x ^ y) & 1)
         {
            p[ 0] = 0;
            p[ 1] = 255;
            p[ 2] = 0;
         }
         else
         {
            p[ 0] = 255;
            p[ 1] = 0;
            p[ 2] = 0;
         }
         p[ 3] = 255;
      }
}


static float   to_ndc_x( float x)
{
   return( 2.0f * x / (float) W - 1.0f);
}


static float   to_ndc_y( float y)
{
   return( 2.0f * y / (float) H - 1.0f);
}


/*
 * Emits a quad as a triangle strip in pixel space. The corner order is
 * bottom-left, bottom-right, top-left, top-right, so the UVs run left to
 * right and bottom to top.
 */
static void   make_quad( float *pos,
                         float *uv,
                         float x0, float y0,
                         float x1, float y1,
                         float x2, float y2,
                         float x3, float y3)
{
   float   x[ 4];
   float   y[ 4];
   int     i;

   x[ 0] = x0; y[ 0] = y0;
   x[ 1] = x1; y[ 1] = y1;
   x[ 2] = x2; y[ 2] = y2;
   x[ 3] = x3; y[ 3] = y3;

   for( i = 0; i < 4; i++)
   {
      pos[ i * 2 + 0] = to_ndc_x( x[ i]);
      pos[ i * 2 + 1] = to_ndc_y( y[ i]);
      uv[ i * 2 + 0]  = (i == 1 || i == 3) ? 1.0f : 0.0f;
      uv[ i * 2 + 1]  = (i >= 2) ? 1.0f : 0.0f;
   }
}


static void   draw_quad( float *pos, float *uv)
{
   aex_gl_es2_VertexAttribPointer( 0, 2, GL_ES2_FLOAT, GL_ES2_FALSE, 0, pos);
   aex_gl_es2_VertexAttribPointer( 1, 2, GL_ES2_FLOAT, GL_ES2_FALSE, 0, uv);
   aex_gl_es2_EnableVertexAttribArray( 0);
   aex_gl_es2_EnableVertexAttribArray( 1);
   aex_gl_es2_DrawArrays( GL_ES2_TRIANGLE_STRIP, 0, 4);
}


static void   draw_tile( gl_es2_int mode,
                         gl_es2_int mode_loc,
                         gl_es2_int color_a_loc,
                         gl_es2_int color_b_loc,
                         gl_es2_int alpha_loc,
                         gl_es2_int sampler_loc,
                         int column,
                         int gradient,
                         float r0, float g0, float b0, float a0,
                         float r1, float g1, float b1)
{
   float   pos[ 8];
   float   uv[ 8];
   float   x;
   float   y;

   x = (float) column * TILE;
   y = 0.0f;

   make_quad( pos, uv, x, y, x + TILE, y, x, y + TILE, x + TILE, y + TILE);

   aex_gl_es2_Uniform1i( mode_loc, mode);
   aex_gl_es2_Uniform3f( color_a_loc, r0, g0, b0);
   aex_gl_es2_Uniform3f( color_b_loc, r1, g1, b1);
   aex_gl_es2_Uniform1f( alpha_loc, a0);
   aex_gl_es2_Uniform1i( sampler_loc, 0);
   (void) gradient;

   draw_quad( pos, uv);
}


static unsigned char   *pixel_at( unsigned char *pixels, int x, int y)
{
   return( &pixels[ (y * W + x) * 4]);
}


static int   check_solid( unsigned char *pixels, int column)
{
   unsigned char   *p;

   p = pixel_at( pixels, column * TILE + TILE / 2, H / 2);
   if( p[ 0] < 250 || p[ 1] > 5 || p[ 2] > 5)
   {
      fprintf( stderr, "solid is %u,%u,%u\n", p[ 0], p[ 1], p[ 2]);
      return( 1);
   }
   return( 0);
}


static int   check_alpha( unsigned char *pixels, int column)
{
   unsigned char   *p;

   p = pixel_at( pixels, column * TILE + TILE / 2, H / 2);
   if( p[ 0] < 250 || p[ 1] < 110 || p[ 1] > 145 || p[ 2] < 110 || p[ 2] > 145)
   {
      fprintf( stderr, "alpha is %u,%u,%u\n", p[ 0], p[ 1], p[ 2]);
      return( 1);
   }
   return( 0);
}


static int   check_linear( unsigned char *pixels, int column)
{
   unsigned char   *p;

   p = pixel_at( pixels, column * TILE + 4, H / 2);
   if( p[ 0] < 200 || p[ 1] > 60)
   {
      fprintf( stderr, "linear left is %u,%u,%u\n", p[ 0], p[ 1], p[ 2]);
      return( 1);
   }
   p = pixel_at( pixels, column * TILE + TILE - 5, H / 2);
   if( p[ 1] < 200 || p[ 0] > 60)
   {
      fprintf( stderr, "linear right is %u,%u,%u\n", p[ 0], p[ 1], p[ 2]);
      return( 1);
   }
   return( 0);
}


static int   check_radial( unsigned char *pixels, int column)
{
   unsigned char   *center;
   unsigned char   *edge;

   center = pixel_at( pixels, column * TILE + TILE / 2, H / 2);
   edge   = pixel_at( pixels, column * TILE + 2, H / 2);
   if( center[ 2] < 200 || center[ 0] > 60)
   {
      fprintf( stderr, "radial center is %u,%u,%u\n",
                       center[ 0], center[ 1], center[ 2]);
      return( 1);
   }
   if( edge[ 0] < 200 || edge[ 2] > 60)
   {
      fprintf( stderr, "radial edge is %u,%u,%u\n", edge[ 0], edge[ 1], edge[ 2]);
      return( 1);
   }
   return( 0);
}


static int   check_image( unsigned char *pixels, int column)
{
   unsigned char   *p;

   p = pixel_at( pixels, column * TILE + 4, 4);
   if( ! (p[ 0] > 200 && p[ 1] < 60) && ! (p[ 1] > 200 && p[ 0] < 60))
   {
      fprintf( stderr, "image is %u,%u,%u\n", p[ 0], p[ 1], p[ 2]);
      return( 1);
   }
   return( 0);
}


static int   check_scissor( unsigned char *pixels, int column)
{
   unsigned char   *left;
   unsigned char   *right;

   left  = pixel_at( pixels, column * TILE + 6, H / 2);
   right = pixel_at( pixels, column * TILE + TILE - 6, H / 2);
   if( left[ 0] < 200 || left[ 1] > 60)
   {
      fprintf( stderr, "scissor left is %u,%u,%u\n", left[ 0], left[ 1], left[ 2]);
      return( 1);
   }
   if( right[ 0] < 40 || right[ 0] > 60 ||
       right[ 1] < 40 || right[ 1] > 60 ||
       right[ 2] < 40 || right[ 2] > 60)
   {
      fprintf( stderr, "scissor right is %u,%u,%u\n",
                       right[ 0], right[ 1], right[ 2]);
      return( 1);
   }
   return( 0);
}


static int   check_transform( unsigned char *pixels, int column)
{
   unsigned char   *center;

   center = pixel_at( pixels, column * TILE + TILE / 2, H / 2);
   if( center[ 1] < 200 || center[ 0] > 60 || center[ 2] > 60)
   {
      fprintf( stderr, "transform center is %u,%u,%u\n",
                       center[ 0], center[ 1], center[ 2]);
      return( 1);
   }
   return( 0);
}


static int   check_stroke( unsigned char *pixels, int column)
{
   unsigned char   *center;
   unsigned char   *p;
   int             i;
   int             j;
   int             white;

   center = pixel_at( pixels, column * TILE + TILE / 2, H / 2);
   if( center[ 0] < 40 || center[ 0] > 60 ||
       center[ 1] < 40 || center[ 1] > 60 ||
       center[ 2] < 40 || center[ 2] > 60)
   {
      fprintf( stderr, "stroke center is %u,%u,%u\n",
                       center[ 0], center[ 1], center[ 2]);
      return( 1);
   }

   white = 0;
   for( j = 0; j < H; j++)
      for( i = 0; i < TILE; i++)
      {
         p = pixel_at( pixels, column * TILE + i, j);
         if( p[ 0] > 200 && p[ 1] > 200 && p[ 2] > 200)
            white++;
      }
   if( white < 20)
   {
      fprintf( stderr, "stroke white=%d\n", white);
      return( 1);
   }
   return( 0);
}


static int   check_copy( unsigned char *pixels, int column)
{
   unsigned char   *p;

   p = pixel_at( pixels, column * TILE + TILE / 2, H / 2);
   if( p[ 2] < 250 || p[ 0] > 5 || p[ 1] > 5)
   {
      fprintf( stderr, "copy is %u,%u,%u\n", p[ 0], p[ 1], p[ 2]);
      return( 1);
   }
   return( 0);
}


static int   check_pixels( unsigned char *pixels)
{
   int   rc;

   rc = 0;
   rc |= check_solid( pixels, 0);
   rc |= check_alpha( pixels, 1);
   rc |= check_linear( pixels, 2);
   rc |= check_radial( pixels, 3);
   rc |= check_image( pixels, 4);
   rc |= check_scissor( pixels, 5);
   rc |= check_transform( pixels, 6);
   rc |= check_stroke( pixels, 7);
   rc |= check_copy( pixels, 8);
   return( rc);
}


static int   write_ppm( unsigned char *pixels, char *filename)
{
   FILE            *fp;
   unsigned char   *p;
   int             x;
   int             y;

   fp = fopen( filename, "wb");
   if( ! fp)
      return( 1);

   fprintf( fp, "P6\n%d %d\n255\n", W, H);
   for( y = H; y > 0; y--)
      for( x = 0; x < W; x++)
      {
         p = pixel_at( pixels, x, y - 1);
         fwrite( p, 1, 3, fp);
      }
   fclose( fp);
   return( 0);
}


int   main( int argc, char *argv[])
{
   static const char   *vertex_source =
      "#version 100\n"
      "attribute vec2 aPos;\n"
      "attribute vec2 aUV;\n"
      "varying vec2 vUV;\n"
      "void main()\n"
      "{\n"
      "   vUV = aUV;\n"
      "   gl_Position = vec4( aPos, 0.0, 1.0);\n"
      "}\n";
   static const char   *fragment_source =
      "#version 100\n"
      "precision mediump float;\n"
      "varying vec2 vUV;\n"
      "uniform int uMode;\n"
      "uniform vec3 uColorA;\n"
      "uniform vec3 uColorB;\n"
      "uniform float uAlpha;\n"
      "uniform sampler2D uSampler;\n"
      "void main()\n"
      "{\n"
      "   if( uMode == 0)\n"
      "      gl_FragColor = vec4( uColorA, uAlpha);\n"
      "   else if( uMode == 1)\n"
      "      gl_FragColor = vec4( mix( uColorA, uColorB, vUV.x), 1.0);\n"
      "   else if( uMode == 2)\n"
      "   {\n"
      "      float d = distance( vUV, vec2( 0.5));\n"
      "      gl_FragColor = vec4( mix( uColorA, uColorB, clamp( d * 2.0, 0.0, 1.0)), 1.0);\n"
      "   }\n"
      "   else\n"
      "      gl_FragColor = texture2D( uSampler, vUV * 8.0);\n"
      "}\n";
   unsigned char   checker[ 4 * 4 * 4];
   unsigned char   pixels[ W * H * 4];
   float           pos[ 8];
   float           uv[ 8];
   float           line_pos[ 32 * 2];
   float           line_uv[ 32 * 2];
   float           x;
   float           y;
   float           angle;
   gl_es2_uint     fragment_shader;
   gl_es2_uint     program;
   gl_es2_uint     texture;
   gl_es2_uint     vertex_shader;
   gl_es2_int      alpha_loc;
   gl_es2_int      color_a_loc;
   gl_es2_int      color_b_loc;
   gl_es2_int      mode_loc;
   gl_es2_int      sampler_loc;
   int             i;
   int             r;

   r = aex_gl_es2_context_init( 32, 16, 32, W, H);
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
   aex_gl_es2_BindAttribLocation( program, 1, "aUV");
   aex_gl_es2_LinkProgram( program);
   if( check_program( program))
      return( 1);

   aex_gl_es2_UseProgram( program);

   mode_loc     = aex_gl_es2_GetUniformLocation( program, "uMode");
   color_a_loc  = aex_gl_es2_GetUniformLocation( program, "uColorA");
   color_b_loc  = aex_gl_es2_GetUniformLocation( program, "uColorB");
   alpha_loc    = aex_gl_es2_GetUniformLocation( program, "uAlpha");
   sampler_loc  = aex_gl_es2_GetUniformLocation( program, "uSampler");

   make_checker( checker);
   aex_gl_es2_GenTextures( 1, &texture);
   aex_gl_es2_BindTexture( GL_ES2_TEXTURE_2D, texture);
   aex_gl_es2_TexParameteri( GL_ES2_TEXTURE_2D, GL_ES2_TEXTURE_MIN_FILTER, GL_ES2_NEAREST);
   aex_gl_es2_TexParameteri( GL_ES2_TEXTURE_2D, GL_ES2_TEXTURE_MAG_FILTER, GL_ES2_NEAREST);
   aex_gl_es2_TexParameteri( GL_ES2_TEXTURE_2D, GL_ES2_TEXTURE_WRAP_S, GL_ES2_REPEAT);
   aex_gl_es2_TexParameteri( GL_ES2_TEXTURE_2D, GL_ES2_TEXTURE_WRAP_T, GL_ES2_REPEAT);
   aex_gl_es2_TexImage2D( GL_ES2_TEXTURE_2D, 0, GL_ES2_RGBA, 4, 4, 0,
                          GL_ES2_RGBA, GL_ES2_UNSIGNED_BYTE, checker);

   aex_gl_es2_Viewport( 0, 0, W, H);
   aex_gl_es2_ClearColor( 0.2f, 0.2f, 0.2f, 1.0f);
   aex_gl_es2_Clear( GL_ES2_COLOR_BUFFER_BIT |
                     GL_ES2_DEPTH_BUFFER_BIT |
                     GL_ES2_STENCIL_BUFFER_BIT);

   /* 0: solid */
   draw_tile( 0, mode_loc, color_a_loc, color_b_loc, alpha_loc, sampler_loc,
              0, 0, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f);

   /* 1: alpha blend, red underneath, white at 50% */
   draw_tile( 0, mode_loc, color_a_loc, color_b_loc, alpha_loc, sampler_loc,
              1, 0, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f);
   aex_gl_es2_Enable( GL_ES2_BLEND);
   aex_gl_es2_BlendFunc( GL_ES2_SRC_ALPHA, GL_ES2_ONE_MINUS_SRC_ALPHA);
   draw_tile( 0, mode_loc, color_a_loc, color_b_loc, alpha_loc, sampler_loc,
              1, 0, 1.0f, 1.0f, 1.0f, 0.5f, 0.0f, 0.0f, 0.0f);
   aex_gl_es2_Disable( GL_ES2_BLEND);

   /* 2: linear gradient */
   draw_tile( 1, mode_loc, color_a_loc, color_b_loc, alpha_loc, sampler_loc,
              2, 1, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f);

   /* 3: radial gradient */
   draw_tile( 2, mode_loc, color_a_loc, color_b_loc, alpha_loc, sampler_loc,
              3, 1, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f);

   /* 4: image pattern */
   draw_tile( 3, mode_loc, color_a_loc, color_b_loc, alpha_loc, sampler_loc,
              4, 0, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f);

   /* 5: scissor */
   aex_gl_es2_Enable( GL_ES2_SCISSOR_TEST);
   aex_gl_es2_Scissor( 5 * TILE, 0, TILE / 2, H);
   draw_tile( 0, mode_loc, color_a_loc, color_b_loc, alpha_loc, sampler_loc,
              5, 0, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f);
   aex_gl_es2_Disable( GL_ES2_SCISSOR_TEST);

   /* 6: transform, a rotated green quad */
   x     = (float) 6 * TILE + TILE / 2.0f;
   y     = H / 2.0f;
   angle = 0.7853981634f;
   make_quad( pos, uv,
              x - (float) 10.0 * (float) cos( angle),
              y - (float) 10.0 * (float) sin( angle),
              x + (float) 10.0 * (float) sin( angle),
              y - (float) 10.0 * (float) cos( angle),
              x - (float) 10.0 * (float) sin( angle),
              y + (float) 10.0 * (float) cos( angle),
              x + (float) 10.0 * (float) cos( angle),
              y + (float) 10.0 * (float) sin( angle));
   aex_gl_es2_Uniform1i( mode_loc, 0);
   aex_gl_es2_Uniform3f( color_a_loc, 0.0f, 1.0f, 0.0f);
   aex_gl_es2_Uniform1f( alpha_loc, 1.0f);
   draw_quad( pos, uv);

   /* 7: stroke, a white circle outline */
   for( i = 0; i < 32; i++)
   {
      angle = (float) i * 6.2831853072f / 32.0f;
      line_pos[ i * 2 + 0] = to_ndc_x( (float) 7 * TILE + TILE / 2.0f +
                                       (float) 14.0 * (float) cos( angle));
      line_pos[ i * 2 + 1] = to_ndc_y( H / 2.0f +
                                       (float) 14.0 * (float) sin( angle));
      line_uv[ i * 2 + 0]  = 0.0f;
      line_uv[ i * 2 + 1]  = 0.0f;
   }
   aex_gl_es2_Uniform1i( mode_loc, 0);
   aex_gl_es2_Uniform3f( color_a_loc, 1.0f, 1.0f, 1.0f);
   aex_gl_es2_Uniform1f( alpha_loc, 1.0f);
   aex_gl_es2_LineWidth( 3.0f);
   aex_gl_es2_VertexAttribPointer( 0, 2, GL_ES2_FLOAT, GL_ES2_FALSE, 0, line_pos);
   aex_gl_es2_VertexAttribPointer( 1, 2, GL_ES2_FLOAT, GL_ES2_FALSE, 0, line_uv);
   aex_gl_es2_EnableVertexAttribArray( 0);
   aex_gl_es2_EnableVertexAttribArray( 1);
   aex_gl_es2_DrawArrays( GL_ES2_LINE_LOOP, 0, 32);

   /* 8: copy composite, yellow then blue with copy blending */
   draw_tile( 0, mode_loc, color_a_loc, color_b_loc, alpha_loc, sampler_loc,
              8, 0, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f);
   aex_gl_es2_Enable( GL_ES2_BLEND);
   aex_gl_es2_BlendFunc( GL_ES2_ONE, GL_ES2_ZERO);
   draw_tile( 0, mode_loc, color_a_loc, color_b_loc, alpha_loc, sampler_loc,
              8, 0, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f);
   aex_gl_es2_Disable( GL_ES2_BLEND);

   aex_gl_es2_ReadPixels( 0, 0, W, H, GL_ES2_RGBA, GL_ES2_UNSIGNED_BYTE, pixels);

   {
      char   *ppm_filename;

      ppm_filename = getenv( "AEX_KITCHENSINK_PPM");
      if( ppm_filename && *ppm_filename)
         write_ppm( pixels, ppm_filename);
   }

   if( check_pixels( pixels))
      return( 1);

   if( aex_gl_es2_GetError() != GL_ES2_NO_ERROR)
   {
      fprintf( stderr, "glGetError reported an error\n");
      return( 1);
   }

   aex_gl_es2_DeleteTextures( 1, &texture);
   aex_gl_es2_DeleteShader( vertex_shader);
   aex_gl_es2_DeleteShader( fragment_shader);
   aex_gl_es2_DeleteProgram( program);

   printf( "headless GLES2 kitchensink OK\n");
   return( 0);
}
