#include <SDL3/SDL.h>

#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "demo-common.h"
#include "gl_es2_impl.h"

#include "../../3rdparty/world/world.h"


#define WINDOW_WIDTH  800
#define WINDOW_HEIGHT 600
#define PI            3.14159265358979323846f


static const char   *vertex_source =
   "#version 100\n"
   "attribute vec3 a_position;\n"
   "uniform mat4 u_matrix;\n"
   "void main()\n"
   "{\n"
   "   gl_Position = u_matrix * vec4( a_position, 1.0);\n"
   "}\n";

static const char   *fragment_source =
   "#version 100\n"
   "precision highp float;\n"
   "void main()\n"
   "{\n"
   "   float z = 1.0 / gl_FragCoord.w;\n"
   "   if( z >= 200.0)\n"
   "      discard;\n"
   "   gl_FragColor = mix( vec4( 222.0 / 255.0, 124.0 / 255.0, 8.0 / 255.0, 0.8),\n"
   "                       vec4( 95.0 / 255.0, 2.0 / 255.0, 31.0 / 255.0, 1.0),\n"
   "                       (z - 120.0) / (200.0 - 120.0));\n"
   "}\n";


static void   rotn( float *m, float nx, float ny, float nz, float ang)
{
   float   c;
   float   s;

   c = cosf( ang);
   s = sinf( ang);
   m[0]  = nx * nx + (ny * ny + nz * nz) * c;
   m[1]  = nx * ny * (1.0f - c) + nz * s;
   m[2]  = nx * nz * (1.0f - c) - ny * s;
   m[3]  = 0.0f;
   m[4]  = nx * ny * (1.0f - c) - nz * s;
   m[5]  = ny * ny + (nx * nx + nz * nz) * c;
   m[6]  = ny * nz * (1.0f - c) + nx * s;
   m[7]  = 0.0f;
   m[8]  = nx * nz * (1.0f - c) + ny * s;
   m[9]  = ny * nz * (1.0f - c) - nx * s;
   m[10] = nz * nz + (nx * nx + ny * ny) * c;
   m[11] = 0.0f;
   m[12] = 0.0f;
   m[13] = 0.0f;
   m[14] = 0.0f;
   m[15] = 1.0f;
}


static void   persp_fovy( float *m, float near, float far, float width, float height, float fovy)
{
   float   h;
   float   q;
   float   range;
   float   w;

   range = height / (2.0f * tanf( fovy / 2.0f));
   q = far / (far - near);
   w = range / (width / 2.0f);
   h = range / (height / 2.0f);
   m[0]  = w;
   m[1]  = 0.0f;
   m[2]  = 0.0f;
   m[3]  = 0.0f;
   m[4]  = 0.0f;
   m[5]  = h;
   m[6]  = 0.0f;
   m[7]  = 0.0f;
   m[8]  = 0.0f;
   m[9]  = 0.0f;
   m[10] = q;
   m[11] = 1.0f;
   m[12] = 0.0f;
   m[13] = 0.0f;
   m[14] = -q * near;
   m[15] = 0.0f;
}


static void   trln( float *m, float x, float y, float z)
{
   m[0]  = 1.0f;
   m[1]  = 0.0f;
   m[2]  = 0.0f;
   m[3]  = 0.0f;
   m[4]  = 0.0f;
   m[5]  = 1.0f;
   m[6]  = 0.0f;
   m[7]  = 0.0f;
   m[8]  = 0.0f;
   m[9]  = 0.0f;
   m[10] = 1.0f;
   m[11] = 0.0f;
   m[12] = x;
   m[13] = y;
   m[14] = z;
   m[15] = 1.0f;
}


static void   unitm( float *m)
{
   m[0]  = 1.0f;
   m[1]  = 0.0f;
   m[2]  = 0.0f;
   m[3]  = 0.0f;
   m[4]  = 0.0f;
   m[5]  = 1.0f;
   m[6]  = 0.0f;
   m[7]  = 0.0f;
   m[8]  = 0.0f;
   m[9]  = 0.0f;
   m[10] = 1.0f;
   m[11] = 0.0f;
   m[12] = 0.0f;
   m[13] = 0.0f;
   m[14] = 0.0f;
   m[15] = 1.0f;
}


static void   mul_pair( float *r, float *a, float *b)
{
   size_t   col;
   size_t   row;

   for( col = 0; col < 4; ++col)
   {
      for( row = 0; row < 4; ++row)
      {
         r[col * 4 + row] = a[0 + row] * b[col * 4 + 0] +
                            a[4 + row] * b[col * 4 + 1] +
                            a[8 + row] * b[col * 4 + 2] +
                            a[12 + row] * b[col * 4 + 3];
      }
   }
}


static void   mulm( float *m, ...)
{
   va_list   ap;
   float   *accumulator;
   float   *next;

   va_start( ap, m);
   accumulator = m;
   unitm( m);
   while( (next = va_arg( ap, float *)))
   {
      float   new_accumulator[16];

      mul_pair( new_accumulator, accumulator, next);
      memcpy( accumulator, new_accumulator, sizeof( new_accumulator));
   }
   va_end( ap);
}


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


static int   init_gl( gl_es2_uint *program, gl_es2_uint *buffer, gl_es2_int *matrix_location)
{
   float   *world;
   gl_es2_uint   fragment_shader;
   gl_es2_uint   vertex_shader;
   size_t   coord;

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
   aex_gl_es2_BindAttribLocation( *program, 0, "a_position");
   aex_gl_es2_LinkProgram( *program);
   if( check_program( *program))
      return( 1);

   aex_gl_es2_DeleteShader( vertex_shader);
   aex_gl_es2_DeleteShader( fragment_shader);

   aex_gl_es2_UseProgram( *program);

   world = (float *) malloc( sizeof( float) * g_num_world_coords_ * 3);
   if( ! world)
   {
      fprintf( stderr, "out of memory\n");
      return( 1);
   }

   for( coord = 0; coord < g_num_world_coords_; ++coord)
   {
      float   latitude;
      float   longitude;
      float   *xyz;

      longitude = g_world_coords_[coord * 2 + 0];
      latitude  = g_world_coords_[coord * 2 + 1];
      xyz = world + coord * 3;

      xyz[0] = 180.0f * sinf( PI * longitude / 180.0f) * cosf( PI * latitude / 180.0f);
      xyz[1] = 180.0f * sinf( PI * latitude / 180.0f);
      xyz[2] = -180.0f * cosf( PI * longitude / 180.0f) * cosf( PI * latitude / 180.0f);
   }

   aex_gl_es2_GenBuffers( 1, buffer);
   aex_gl_es2_BindBuffer( GL_ES2_ARRAY_BUFFER, *buffer);
   aex_gl_es2_BufferData( GL_ES2_ARRAY_BUFFER,
                          sizeof( float) * g_num_world_coords_ * 3,
                          world,
                          GL_ES2_STATIC_DRAW);
   free( world);

   aex_gl_es2_EnableVertexAttribArray( 0);
   aex_gl_es2_VertexAttribPointer( 0,
                                   3,
                                   GL_ES2_FLOAT,
                                   GL_ES2_FALSE,
                                   0,
                                   (void *) 0);

   *matrix_location = aex_gl_es2_GetUniformLocation( *program, "u_matrix");
   return( 0);
}


int   main( int argc, char *argv[])
{
   float   angle;
   float   pitch_matrix[16];
   float   projection_matrix[16];
   float   roll_matrix[16];
   float   rotation_matrix[16];
   float   transformation_matrix[16];
   float   translation_matrix[16];
   gl_es2_int   matrix_location;
   gl_es2_uint   buffer;
   gl_es2_uint   program;
   int   running;
   SDL_Event   event;
   SDL_Window   *window;
   Uint64   started;
   unsigned char   *pixels;

   (void) argc;
   (void) argv;

   if( ! SDL_Init( SDL_INIT_VIDEO))
   {
      fprintf( stderr, "SDL_Init failed: %s\n", SDL_GetError());
      return( 1);
   }

   window = SDL_CreateWindow( "mulle-aex-gl World is Yours",
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

   if( init_gl( &program, &buffer, &matrix_location))
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

      angle = (float) (SDL_GetTicks() - started) / 1000.0f;
      angle = angle * PI * 2.0f / 60.0f;

      persp_fovy( projection_matrix, 0.1f, 4000.0f, WINDOW_WIDTH, WINDOW_HEIGHT, 0.5f * PI);
      trln( translation_matrix, 0.0f, 0.0f, 300.0f);
      rotn( rotation_matrix, 0.0f, 1.0f, 0.0f, angle);
      rotn( pitch_matrix, 1.0f, 0.0f, 0.0f, PI * -40.0f / 180.0f);
      rotn( roll_matrix, 0.0f, 0.0f, 1.0f, PI * -10.0f / 180.0f);
      mulm( transformation_matrix,
            projection_matrix,
            translation_matrix,
            roll_matrix,
            pitch_matrix,
            rotation_matrix,
            NULL);

      aex_gl_es2_Viewport( 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
      aex_gl_es2_ClearColor( 0.10f, 0.0f, 0.28f, 1.0f);
      aex_gl_es2_Clear( GL_ES2_COLOR_BUFFER_BIT);

      aex_gl_es2_UseProgram( program);
      aex_gl_es2_UniformMatrix4fv( matrix_location, 1, GL_ES2_FALSE, transformation_matrix);
      aex_gl_es2_BindBuffer( GL_ES2_ARRAY_BUFFER, buffer);
      aex_gl_es2_DrawArrays( GL_ES2_LINES, 0, (gl_es2_sizei) g_num_world_coords_);

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
