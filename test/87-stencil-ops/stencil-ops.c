#include <mulle-aex-gl/gl_es2_impl.h>

#include <stdio.h>


#define W        64
#define H        64


static const float   quad[ 8] =
   { -1.0f, -1.0f,  1.0f, -1.0f,  -1.0f, 1.0f,  1.0f, 1.0f };
static const float   front_triangle[ 6] =
   { -0.8f, -0.8f,  0.8f, -0.8f,  0.0f, 0.8f };
static const float   back_triangle[ 6] =
   { 0.0f, 0.8f,  0.8f, -0.8f,  -0.8f, -0.8f };

static gl_es2_int   g_color_location;
static gl_es2_int   g_z_location;


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


static void   draw( const float *positions, gl_es2_int count, float z)
{
   aex_gl_es2_Uniform1f( g_z_location, z);
   aex_gl_es2_VertexAttribPointer( 0, 2, GL_ES2_FLOAT, GL_ES2_FALSE, 0,
                                   positions);
   aex_gl_es2_DrawArrays( GL_ES2_TRIANGLE_STRIP, 0, count);
}


static void   draw_triangle( const float *positions, float z)
{
   aex_gl_es2_Uniform1f( g_z_location, z);
   aex_gl_es2_VertexAttribPointer( 0, 2, GL_ES2_FLOAT, GL_ES2_FALSE, 0,
                                   positions);
   aex_gl_es2_DrawArrays( GL_ES2_TRIANGLES, 0, 3);
}


static void   begin_ops( void)
{
   aex_gl_es2_Disable( GL_ES2_DEPTH_TEST);
   aex_gl_es2_Enable( GL_ES2_STENCIL_TEST);
   aex_gl_es2_ColorMask( GL_ES2_FALSE, GL_ES2_FALSE,
                         GL_ES2_FALSE, GL_ES2_FALSE);
   aex_gl_es2_StencilMask( 0xffff);
   aex_gl_es2_StencilFunc( GL_ES2_ALWAYS, 0, 0xffff);
   aex_gl_es2_StencilOp( GL_ES2_KEEP, GL_ES2_KEEP, GL_ES2_KEEP);
}


static void   set_stencil( unsigned int value)
{
   aex_gl_es2_StencilMask( 0xffff);
   aex_gl_es2_ClearStencil( (gl_es2_int) value);
   aex_gl_es2_Clear( GL_ES2_STENCIL_BUFFER_BIT);
}


/* Paints the full viewport white where the stencil buffer equals value. */
static int   probe( unsigned int value, int x, int y)
{
   unsigned char   pixel[ 4];

   aex_gl_es2_Disable( GL_ES2_DEPTH_TEST);
   aex_gl_es2_ColorMask( GL_ES2_TRUE, GL_ES2_TRUE, GL_ES2_TRUE, GL_ES2_TRUE);
   aex_gl_es2_StencilFunc( GL_ES2_EQUAL, (gl_es2_int) value, 0xffff);
   aex_gl_es2_StencilOp( GL_ES2_KEEP, GL_ES2_KEEP, GL_ES2_KEEP);

   aex_gl_es2_ClearColor( 0.0f, 0.0f, 0.0f, 1.0f);
   aex_gl_es2_Clear( GL_ES2_COLOR_BUFFER_BIT);

   aex_gl_es2_Uniform4f( g_color_location, 1.0f, 1.0f, 1.0f, 1.0f);
   draw( quad, 4, 1.0f);

   aex_gl_es2_ReadPixels( x, y, 1, 1, GL_ES2_RGBA, GL_ES2_UNSIGNED_BYTE,
                          pixel);
   return( pixel[ 0] >= 128);
}


static int   expect_stencil( unsigned int value, int x, int y,
                             const char *label)
{
   unsigned int   other;

   if( ! probe( value, x, y))
   {
      fprintf( stderr, "%s: expected stencil 0x%04x at %d,%d\n",
               label, value, x, y);
      return( 1);
   }

   other = (value == 0) ? 1 : 0;
   if( probe( other, x, y))
   {
      fprintf( stderr, "%s: probe cannot tell 0x%04x from 0x%04x at %d,%d\n",
               label, value, other, x, y);
      return( 1);
   }
   return( 0);
}


static int   depth_prepass( void)
{
   aex_gl_es2_Enable( GL_ES2_DEPTH_TEST);
   aex_gl_es2_DepthFunc( GL_ES2_LESS);
   aex_gl_es2_ClearDepthf( 1.0f);
   aex_gl_es2_Clear( GL_ES2_DEPTH_BUFFER_BIT);

   aex_gl_es2_Uniform4f( g_color_location, 0.0f, 0.0f, 0.0f, 1.0f);
   draw( quad, 4, 0.5f);
   return( 0);
}


int   main( int argc, char *argv[])
{
   static const char   *vertex_source =
      "#version 100\n"
      "attribute vec2 aPos;\n"
      "uniform float uZ;\n"
      "void main()\n"
      "{\n"
      "   gl_Position = vec4( aPos, uZ, 1.0);\n"
      "}\n";
   static const char   *fragment_source =
      "#version 100\n"
      "precision mediump float;\n"
      "uniform vec4 uColor;\n"
      "void main()\n"
      "{\n"
      "   gl_FragColor = uColor;\n"
      "}\n";
   gl_es2_uint     fragment_shader;
   gl_es2_uint     program;
   gl_es2_uint     vertex_shader;
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
   aex_gl_es2_LinkProgram( program);
   if( check_program( program))
      return( 1);

   aex_gl_es2_UseProgram( program);
   g_color_location = aex_gl_es2_GetUniformLocation( program, "uColor");
   g_z_location     = aex_gl_es2_GetUniformLocation( program, "uZ");
   if( g_color_location < 0 || g_z_location < 0)
   {
      fprintf( stderr, "uniform not found\n");
      return( 1);
   }

   aex_gl_es2_Viewport( 0, 0, W, H);
   aex_gl_es2_ClearColor( 0.0f, 0.0f, 0.0f, 1.0f);
   aex_gl_es2_EnableVertexAttribArray( 0);

   /* GL_INCR saturates at the maximum stencil value. */
   begin_ops();
   set_stencil( 0xffff);
   aex_gl_es2_StencilFunc( GL_ES2_ALWAYS, 0, 0xffff);
   aex_gl_es2_StencilOpSeparate( GL_ES2_FRONT,
                                 GL_ES2_KEEP, GL_ES2_KEEP, GL_ES2_INCR);
   aex_gl_es2_StencilOpSeparate( GL_ES2_BACK,
                                 GL_ES2_KEEP, GL_ES2_KEEP, GL_ES2_DECR);
   draw_triangle( front_triangle, 0.0f);
   if( expect_stencil( 0xffff, 32, 32, "INCR at max"))
      return( 1);

   /* GL_INCR_WRAP wraps around to zero. */
   begin_ops();
   set_stencil( 0xffff);
   aex_gl_es2_StencilFunc( GL_ES2_ALWAYS, 0, 0xffff);
   aex_gl_es2_StencilOpSeparate( GL_ES2_FRONT,
                                 GL_ES2_KEEP, GL_ES2_KEEP, GL_ES2_INCR_WRAP);
   aex_gl_es2_StencilOpSeparate( GL_ES2_BACK,
                                 GL_ES2_KEEP, GL_ES2_KEEP, GL_ES2_DECR);
   draw_triangle( front_triangle, 0.0f);
   if( expect_stencil( 0x0000, 32, 32, "INCR_WRAP at max"))
      return( 1);

   /* GL_DECR saturates at zero, GL_DECR_WRAP wraps to the maximum. */
   begin_ops();
   set_stencil( 0x0000);
   aex_gl_es2_StencilFunc( GL_ES2_ALWAYS, 0, 0xffff);
   aex_gl_es2_StencilOpSeparate( GL_ES2_FRONT,
                                 GL_ES2_KEEP, GL_ES2_KEEP, GL_ES2_INCR);
   aex_gl_es2_StencilOpSeparate( GL_ES2_BACK,
                                 GL_ES2_KEEP, GL_ES2_KEEP, GL_ES2_DECR);
   draw_triangle( back_triangle, 0.0f);
   if( expect_stencil( 0x0000, 32, 32, "DECR at zero"))
      return( 1);

   begin_ops();
   set_stencil( 0x0000);
   aex_gl_es2_StencilFunc( GL_ES2_ALWAYS, 0, 0xffff);
   aex_gl_es2_StencilOpSeparate( GL_ES2_FRONT,
                                 GL_ES2_KEEP, GL_ES2_KEEP, GL_ES2_INCR);
   aex_gl_es2_StencilOpSeparate( GL_ES2_BACK,
                                 GL_ES2_KEEP, GL_ES2_KEEP, GL_ES2_DECR_WRAP);
   draw_triangle( back_triangle, 0.0f);
   if( expect_stencil( 0xffff, 32, 32, "DECR_WRAP at zero"))
      return( 1);

   /* Front and back faces must select different operations. */
   begin_ops();
   set_stencil( 0x0000);
   aex_gl_es2_StencilFunc( GL_ES2_ALWAYS, 0, 0xffff);
   aex_gl_es2_StencilOpSeparate( GL_ES2_FRONT,
                                 GL_ES2_KEEP, GL_ES2_KEEP, GL_ES2_INCR_WRAP);
   aex_gl_es2_StencilOpSeparate( GL_ES2_BACK,
                                 GL_ES2_KEEP, GL_ES2_KEEP, GL_ES2_DECR_WRAP);
   draw_triangle( front_triangle, 0.0f);
   if( expect_stencil( 0x0001, 32, 32, "front INCR_WRAP"))
      return( 1);

   begin_ops();
   set_stencil( 0x0000);
   aex_gl_es2_StencilFunc( GL_ES2_ALWAYS, 0, 0xffff);
   aex_gl_es2_StencilOpSeparate( GL_ES2_FRONT,
                                 GL_ES2_KEEP, GL_ES2_KEEP, GL_ES2_INCR_WRAP);
   aex_gl_es2_StencilOpSeparate( GL_ES2_BACK,
                                 GL_ES2_KEEP, GL_ES2_KEEP, GL_ES2_DECR_WRAP);
   draw_triangle( back_triangle, 0.0f);
   if( expect_stencil( 0xffff, 32, 32, "back DECR_WRAP"))
      return( 1);

   /* REPLACE only touches the bits selected by the stencil write mask. */
   begin_ops();
   set_stencil( 0x00f0);
   aex_gl_es2_StencilMask( 0x000f);
   aex_gl_es2_StencilFunc( GL_ES2_ALWAYS, 0x00aa, 0xffff);
   aex_gl_es2_StencilOp( GL_ES2_REPLACE, GL_ES2_REPLACE, GL_ES2_REPLACE);
   draw_triangle( front_triangle, 0.0f);
   if( expect_stencil( 0x00fa, 32, 32, "REPLACE with mask"))
      return( 1);

   /* ZERO only clears the bits selected by the stencil write mask. */
   begin_ops();
   set_stencil( 0xffff);
   aex_gl_es2_StencilMask( 0x00ff);
   aex_gl_es2_StencilFunc( GL_ES2_ALWAYS, 0, 0xffff);
   aex_gl_es2_StencilOp( GL_ES2_ZERO, GL_ES2_ZERO, GL_ES2_ZERO);
   draw_triangle( front_triangle, 0.0f);
   if( expect_stencil( 0xff00, 32, 32, "ZERO with mask"))
      return( 1);

   /* A zero stencil write mask must suppress every write. */
   begin_ops();
   set_stencil( 0x1234);
   aex_gl_es2_StencilMask( 0x0000);
   aex_gl_es2_StencilFunc( GL_ES2_ALWAYS, 0, 0xffff);
   aex_gl_es2_StencilOp( GL_ES2_ZERO, GL_ES2_ZERO, GL_ES2_ZERO);
   draw_triangle( front_triangle, 0.0f);
   if( expect_stencil( 0x1234, 32, 32, "mask 0 suppresses writes"))
      return( 1);

   /* Failing the stencil test selects the sfail operation. */
   begin_ops();
   set_stencil( 0x0000);
   aex_gl_es2_StencilMask( 0xffff);
   aex_gl_es2_StencilFunc( GL_ES2_NEVER, 0x0011, 0xffff);
   aex_gl_es2_StencilOp( GL_ES2_REPLACE, GL_ES2_REPLACE, GL_ES2_REPLACE);
   draw_triangle( front_triangle, 0.0f);
   if( expect_stencil( 0x0011, 32, 32, "sfail operation"))
      return( 1);

   /* Failing the depth test selects the zfail operation. */
   begin_ops();
   set_stencil( 0x0000);
   depth_prepass();
   aex_gl_es2_StencilMask( 0xffff);
   aex_gl_es2_StencilFunc( GL_ES2_ALWAYS, 0x0022, 0xffff);
   aex_gl_es2_StencilOp( GL_ES2_REPLACE, GL_ES2_REPLACE, GL_ES2_REPLACE);
   draw_triangle( front_triangle, 0.9f);
   if( expect_stencil( 0x0022, 32, 32, "zfail operation"))
      return( 1);

   /* Passing both tests selects the zpass operation. */
   begin_ops();
   set_stencil( 0x0000);
   depth_prepass();
   aex_gl_es2_StencilMask( 0xffff);
   aex_gl_es2_StencilFunc( GL_ES2_ALWAYS, 0x0033, 0xffff);
   aex_gl_es2_StencilOp( GL_ES2_REPLACE, GL_ES2_REPLACE, GL_ES2_REPLACE);
   draw_triangle( front_triangle, 0.4f);
   if( expect_stencil( 0x0033, 32, 32, "zpass operation"))
      return( 1);

   /* Nothing outside the triangle was written. */
   if( expect_stencil( 0x0000, 2, 2, "outside the triangle"))
      return( 1);

   aex_gl_es2_Disable( GL_ES2_STENCIL_TEST);

   if( aex_gl_es2_GetError() != GL_ES2_NO_ERROR)
   {
      fprintf( stderr, "glGetError reported an error\n");
      return( 1);
   }

   aex_gl_es2_DeleteShader( vertex_shader);
   aex_gl_es2_DeleteShader( fragment_shader);
   aex_gl_es2_DeleteProgram( program);

   printf( "headless GLES2 stencil ops OK\n");
   return( 0);
}
