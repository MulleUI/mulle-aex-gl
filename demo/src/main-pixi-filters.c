/*
 * Fragment shaders adapted from PixiJS Filters, MIT licensed.
 * Copyright (c) 2013-2025 Mathew Groves, Chad Engler.
 * Source: https://github.com/pixijs/filters
 * See ../LICENSES/PixiJS-Filters.txt.
 */

#include <SDL3/SDL.h>

#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "demo-common.h"
#include "gl_es2_impl.h"

#include "../../renderbmp/smiley.h"


#define WINDOW_WIDTH   800
#define WINDOW_HEIGHT  600

#define TEXTURE_WIDTH  256
#define TEXTURE_HEIGHT 256

#define DISPLACEMENT_WIDTH  4
#define DISPLACEMENT_HEIGHT 512

#define FILTER_TEXTURE_UNIT (GL_ES2_TEXTURE0 + 1)


enum
{
   FILTER_CRT,
   FILTER_GLITCH,
   FILTER_ZOOM_BLUR,
   FILTER_SHOCKWAVE,
   FILTER_ASCII,
   FILTER_COUNT
};


static const char   *filter_names[ FILTER_COUNT] =
{
   "CRT",
   "Glitch",
   "Zoom Blur",
   "Shockwave",
   "ASCII"
};


static const char   *vertex_source =
   "#version 100\n"
   "attribute vec2 a_position;\n"
   "attribute vec2 a_texcoord;\n"
   "varying vec2 vTextureCoord;\n"
   "void main()\n"
   "{\n"
   "   vTextureCoord = a_texcoord;\n"
   "   gl_Position = vec4( a_position, 0.0, 1.0);\n"
   "}\n";


static const char   crt_fragment[] =
   "#version 100\n"
   "precision highp float;\n"
   "varying vec2 vTextureCoord;\n"
   "uniform sampler2D uTexture;\n"
   "uniform vec4 uLine;\n"
   "uniform vec2 uNoise;\n"
   "uniform vec3 uVignette;\n"
   "uniform float uSeed;\n"
   "uniform float uTime;\n"
   "uniform vec2 uDimensions;\n"
   "uniform vec4 uInputSize;\n"
   "const float SQRT_2 = 1.414213;\n"
   "float rand(vec2 co)\n"
   "{\n"
   "   return fract(sin(dot(co.xy, vec2(12.9898, 78.233))) * 43758.5453);\n"
   "}\n"
   "float vignette(vec3 co, vec2 coord)\n"
   "{\n"
   "   float outter = SQRT_2 - uVignette[0] * SQRT_2;\n"
   "   vec2 dir = vec2(0.5) - coord;\n"
   "   dir.y *= uDimensions.y / uDimensions.x;\n"
   "   float darker = clamp((outter - length(dir) * SQRT_2) / (0.00001 + uVignette[2] * SQRT_2), 0.0, 1.0);\n"
   "   return darker + (1.0 - darker) * (1.0 - uVignette[1]);\n"
   "}\n"
   "float noise(vec2 coord)\n"
   "{\n"
   "   vec2 pixelCoord = coord * uInputSize.xy;\n"
   "   pixelCoord.x = floor(pixelCoord.x / uNoise[1]);\n"
   "   pixelCoord.y = floor(pixelCoord.y / uNoise[1]);\n"
   "   return (rand(pixelCoord * uNoise[1] * uSeed) - 0.5) * uNoise[0];\n"
   "}\n"
   "vec3 interlaceLines(vec3 co, vec2 coord)\n"
   "{\n"
   "   vec3 color = co;\n"
   "   float curvature = uLine[0];\n"
   "   float lineWidth = uLine[1];\n"
   "   float lineContrast = uLine[2];\n"
   "   float verticalLine = uLine[3];\n"
   "   vec2 dir = vec2(coord * uInputSize.xy / uDimensions - 0.5);\n"
   "   float _c = curvature > 0. ? curvature : 1.;\n"
   "   float k = curvature > 0. ? (length(dir * dir) * 0.25 * _c * _c + 0.935 * _c) : 1.;\n"
   "   vec2 uv = dir * k;\n"
   "   float v = verticalLine > 0.5 ? uv.x * uDimensions.x : uv.y * uDimensions.y;\n"
   "   v *= min(1.0, 2.0 / lineWidth) / _c;\n"
   "   float j = 1. + cos(v * 1.2 - uTime) * 0.5 * lineContrast;\n"
   "   color *= j;\n"
   "   float segment = verticalLine > 0.5 ? mod((dir.x + .5) * uDimensions.x, 4.) : mod((dir.y + .5) * uDimensions.y, 4.);\n"
   "   color *= 0.99 + ceil(segment) * 0.015;\n"
   "   return color;\n"
   "}\n"
   "void main(void)\n"
   "{\n"
   "   vec4 finalColor = texture2D(uTexture, vTextureCoord);\n"
   "   vec2 coord = vTextureCoord * uInputSize.xy / uDimensions;\n"
   "   if (uNoise[0] > 0.0 && uNoise[1] > 0.0)\n"
   "   {\n"
   "      float n = noise(vTextureCoord);\n"
   "      finalColor += vec4(n, n, n, finalColor.a);\n"
   "   }\n"
   "   if (uVignette[0] > 0.)\n"
   "   {\n"
   "      float v = vignette(finalColor.rgb, coord);\n"
   "      finalColor *= vec4(v, v, v, finalColor.a);\n"
   "   }\n"
   "   if (uLine[1] > 0.0)\n"
   "   {\n"
   "      finalColor = vec4(interlaceLines(finalColor.rgb, vTextureCoord), finalColor.a);\n"
   "   }\n"
   "   gl_FragColor = finalColor;\n"
   "}\n";


static const char   glitch_fragment[] =
   "#version 100\n"
   "precision highp float;\n"
   "varying vec2 vTextureCoord;\n"
   "uniform sampler2D uTexture;\n"
   "uniform sampler2D uDisplacementMap;\n"
   "uniform float uSeed;\n"
   "uniform vec2 uDimensions;\n"
   "uniform float uAspect;\n"
   "uniform float uFillMode;\n"
   "uniform float uOffset;\n"
   "uniform float uDirection;\n"
   "uniform vec2 uRed;\n"
   "uniform vec2 uGreen;\n"
   "uniform vec2 uBlue;\n"
   "uniform vec4 uInputSize;\n"
   "uniform vec4 uInputClamp;\n"
   "const int TRANSPARENT = 0;\n"
   "const int ORIGINAL = 1;\n"
   "const int LOOP = 2;\n"
   "const int CLAMP = 3;\n"
   "const int MIRROR = 4;\n"
   "void main(void)\n"
   "{\n"
   "   vec4 finalColor;\n"
   "   vec2 coord = (vTextureCoord * uInputSize.xy) / uDimensions;\n"
   "   float sinDir = sin(uDirection);\n"
   "   float cosDir = cos(uDirection);\n"
   "   float cx = coord.x - 0.5;\n"
   "   float cy = (coord.y - 0.5) * uAspect;\n"
   "   float ny = (-sinDir * cx + cosDir * cy) / uAspect + 0.5;\n"
   "   ny = ny > 1.0 ? 2.0 - ny : (ny < 0.0 ? -ny : ny);\n"
   "   vec4 dc = texture2D(uDisplacementMap, vec2(0.5, ny));\n"
   "   float displacement = (dc.r - dc.g) * (uOffset / uInputSize.x);\n"
   "   coord = vTextureCoord + vec2(cosDir * displacement, sinDir * displacement * uAspect);\n"
   "   int fillMode = int(uFillMode);\n"
   "   float keep = 1.0;\n"
   "   if (fillMode == CLAMP)\n"
   "   {\n"
   "      coord = clamp(coord, uInputClamp.xy, uInputClamp.zw);\n"
   "   }\n"
   "   else\n"
   "   {\n"
   "      if (coord.x > uInputClamp.z)\n"
   "      {\n"
   "         if (fillMode == TRANSPARENT) keep = 0.0;\n"
   "         else if (fillMode == LOOP) coord.x -= uInputClamp.z;\n"
   "         else if (fillMode == MIRROR) coord.x = uInputClamp.z * 2.0 - coord.x;\n"
   "      }\n"
   "      else if (coord.x < uInputClamp.x)\n"
   "      {\n"
   "         if (fillMode == TRANSPARENT) keep = 0.0;\n"
   "         else if (fillMode == LOOP) coord.x += uInputClamp.z;\n"
   "         else if (fillMode == MIRROR) coord.x *= -uInputClamp.z;\n"
   "      }\n"
   "      if (coord.y > uInputClamp.w)\n"
   "      {\n"
   "         if (fillMode == TRANSPARENT) keep = 0.0;\n"
   "         else if (fillMode == LOOP) coord.y -= uInputClamp.w;\n"
   "         else if (fillMode == MIRROR) coord.y = uInputClamp.w * 2.0 - coord.y;\n"
   "      }\n"
   "      else if (coord.y < uInputClamp.y)\n"
   "      {\n"
   "         if (fillMode == TRANSPARENT) keep = 0.0;\n"
   "         else if (fillMode == LOOP) coord.y += uInputClamp.w;\n"
   "         else if (fillMode == MIRROR) coord.y *= -uInputClamp.w;\n"
   "      }\n"
   "   }\n"
   "   finalColor.r = texture2D(uTexture, coord + uRed * (1.0 - uSeed * 0.4) / uInputSize.xy).r;\n"
   "   finalColor.g = texture2D(uTexture, coord + uGreen * (1.0 - uSeed * 0.3) / uInputSize.xy).g;\n"
   "   finalColor.b = texture2D(uTexture, coord + uBlue * (1.0 - uSeed * 0.2) / uInputSize.xy).b;\n"
   "   finalColor.a = texture2D(uTexture, coord).a;\n"
   "   gl_FragColor = finalColor * keep;\n"
   "}\n";


static const char   zoom_blur_fragment[] =
   "#version 100\n"
   "precision highp float;\n"
   "varying vec2 vTextureCoord;\n"
   "uniform sampler2D uTexture;\n"
   "uniform float uStrength;\n"
   "uniform vec2 uCenter;\n"
   "uniform vec2 uRadii;\n"
   "uniform vec4 uInputSize;\n"
   "const int MAX_KERNEL_SIZE = " "8" ";\n"
   "float rand(vec2 co, float seed)\n"
   "{\n"
   "   const float a = 12.9898;\n"
   "   const float b = 78.233;\n"
   "   const float c = 43758.5453;\n"
   "   float dt = dot(co + seed, vec2(a, b));\n"
   "   float sn = mod(dt, 3.14159);\n"
   "   return fract(sin(sn) * c + seed);\n"
   "}\n"
   "void main(void)\n"
   "{\n"
   "   float minGradient = uRadii[0] * 0.3;\n"
   "   float innerRadius = (uRadii[0] + minGradient * 0.5) / uInputSize.x;\n"
   "   float gradient = uRadii[1] * 0.3;\n"
   "   float radius = (uRadii[1] - gradient * 0.5) / uInputSize.x;\n"
   "   float countLimit = float(MAX_KERNEL_SIZE);\n"
   "   vec2 dir = vec2(uCenter.xy / uInputSize.xy - vTextureCoord);\n"
   "   float dist = length(vec2(dir.x, dir.y * uInputSize.y / uInputSize.x));\n"
   "   float strength = uStrength;\n"
   "   float delta = 0.0;\n"
   "   float gap;\n"
   "   if (dist < innerRadius)\n"
   "   {\n"
   "      delta = innerRadius - dist;\n"
   "      gap = minGradient;\n"
   "   }\n"
   "   else if (radius >= 0.0 && dist > radius)\n"
   "   {\n"
   "      delta = dist - radius;\n"
   "      gap = gradient;\n"
   "   }\n"
   "   if (delta > 0.0)\n"
   "   {\n"
   "      float normalCount = gap / uInputSize.x;\n"
   "      delta = (normalCount - delta) / normalCount;\n"
   "      countLimit *= delta;\n"
   "      strength *= delta;\n"
   "      if (countLimit < 1.0)\n"
   "      {\n"
   "         gl_FragColor = texture2D(uTexture, vTextureCoord);\n"
   "         return;\n"
   "      }\n"
   "   }\n"
   "   float offset = rand(vTextureCoord, 0.0);\n"
   "   float total = 0.0;\n"
   "   vec4 color = vec4(0.0);\n"
   "   dir *= strength;\n"
   "   for (int i = 0; i < MAX_KERNEL_SIZE; i++)\n"
   "   {\n"
   "      float t = float(i);\n"
   "      float percent = (t + offset) / float(MAX_KERNEL_SIZE);\n"
   "      float weight = 4.0 * (percent - percent * percent);\n"
   "      vec2 p = vTextureCoord + dir * percent;\n"
   "      vec4 sample = texture2D(uTexture, p);\n"
   "      color += sample * weight;\n"
   "      total += weight;\n"
   "      if (t > countLimit) break;\n"
   "   }\n"
   "   color /= total;\n"
   "   gl_FragColor = color;\n"
   "}\n";


static const char   shockwave_fragment[] =
   "#version 100\n"
   "precision highp float;\n"
   "varying vec2 vTextureCoord;\n"
   "uniform sampler2D uTexture;\n"
   "uniform vec2 uCenter;\n"
   "uniform float uTime;\n"
   "uniform float uSpeed;\n"
   "uniform vec4 uWave;\n"
   "uniform vec4 uInputSize;\n"
   "uniform vec4 uInputClamp;\n"
   "const float PI = 3.14159;\n"
   "void main(void)\n"
   "{\n"
   "   float uAmplitude = uWave[0];\n"
   "   float uWavelength = uWave[1];\n"
   "   float uBrightness = uWave[2];\n"
   "   float uRadius = uWave[3];\n"
   "   float halfWavelength = uWavelength * 0.5 / uInputSize.x;\n"
   "   float maxRadius = uRadius / uInputSize.x;\n"
   "   float currentRadius = uTime * uSpeed / uInputSize.x;\n"
   "   float valid = (maxRadius <= 0.0 || currentRadius <= maxRadius) ? 1.0 : 0.0;\n"
   "   float fade = (maxRadius > 0.0) ? 1.0 - (currentRadius / maxRadius) * (currentRadius / maxRadius) : 1.0;\n"
   "   vec2 dir = vec2(vTextureCoord - uCenter / uInputSize.xy);\n"
   "   dir.y *= uInputSize.y / uInputSize.x;\n"
   "   float dist = length(dir);\n"
   "   vec2 diffUV = dir / max(dist, 0.00001);\n"
   "   float diff = (dist - currentRadius) / halfWavelength;\n"
   "   float p = 1.0 - diff * diff;\n"
   "   float active = step(currentRadius - halfWavelength, dist) * step(dist, currentRadius + halfWavelength) * step(0.0, dist) * valid;\n"
   "   float powDiff = 1.25 * sin(diff * PI) * p * (uAmplitude * fade) * active;\n"
   "   vec2 offset = diffUV * powDiff / uInputSize.xy;\n"
   "   vec4 color = texture2D(uTexture, vTextureCoord + offset);\n"
   "   color.rgb *= 1.0 + (uBrightness - 1.0) * p * fade * active;\n"
   "   gl_FragColor = color;\n"
   "}\n";


static const char   ascii_fragment[] =
   "#version 100\n"
   "precision highp float;\n"
   "varying vec2 vTextureCoord;\n"
   "uniform sampler2D uTexture;\n"
   "uniform float uSize;\n"
   "uniform vec3 uColor;\n"
   "uniform float uReplaceColor;\n"
   "uniform vec4 uInputSize;\n"
   "vec2 mapCoord(vec2 coord)\n"
   "{\n"
   "   coord *= uInputSize.xy;\n"
   "   coord += uInputSize.zw;\n"
   "   return coord;\n"
   "}\n"
   "vec2 unmapCoord(vec2 coord)\n"
   "{\n"
   "   coord -= uInputSize.zw;\n"
   "   coord /= uInputSize.xy;\n"
   "   return coord;\n"
   "}\n"
   "vec2 pixelate(vec2 coord, vec2 size)\n"
   "{\n"
   "   return floor(coord / size) * size;\n"
   "}\n"
   "vec2 getMod(vec2 coord, vec2 size)\n"
   "{\n"
   "   return mod(coord, size) / size;\n"
   "}\n"
   "float character(float n, vec2 p)\n"
   "{\n"
   "   p = floor(p * vec2(4.0, 4.0) + 2.5);\n"
   "   if (clamp(p.x, 0.0, 4.0) == p.x)\n"
   "   {\n"
   "      if (clamp(p.y, 0.0, 4.0) == p.y)\n"
   "      {\n"
   "         if (int(mod(n / exp2(p.x + 5.0 * p.y), 2.0)) == 1) return 1.0;\n"
   "      }\n"
   "   }\n"
   "   return 0.0;\n"
   "}\n"
   "void main(void)\n"
   "{\n"
   "   vec2 coord = mapCoord(vTextureCoord);\n"
   "   vec2 pixCoord = pixelate(coord, vec2(uSize));\n"
   "   pixCoord = unmapCoord(pixCoord);\n"
   "   vec4 color = texture2D(uTexture, pixCoord);\n"
   "   float gray = 0.3 * color.r + 0.59 * color.g + 0.11 * color.b;\n"
   "   float n = 65536.0;\n"
   "   if (gray > 0.2) n = 65600.0;\n"
   "   if (gray > 0.3) n = 332772.0;\n"
   "   if (gray > 0.4) n = 15255086.0;\n"
   "   if (gray > 0.5) n = 23385164.0;\n"
   "   if (gray > 0.6) n = 15252014.0;\n"
   "   if (gray > 0.7) n = 13199452.0;\n"
   "   if (gray > 0.8) n = 11512810.0;\n"
   "   vec2 modd = getMod(coord, vec2(uSize));\n"
   "   vec4 finalColor = (uReplaceColor > 0.5 ? vec4(uColor, 1.0) : color) * character(n, vec2(-1.0) + modd * 2.0);\n"
   "   gl_FragColor = finalColor;\n"
   "}\n";


static const char   *fragment_sources[ FILTER_COUNT] =
{
   crt_fragment,
   glitch_fragment,
   zoom_blur_fragment,
   shockwave_fragment,
   ascii_fragment
};


static const float   vertices[] =
{
   -1.0f, -1.0f,   0.0f, 0.0f,
    1.0f, -1.0f,   1.0f, 0.0f,
   -1.0f,  1.0f,   0.0f, 1.0f,
    1.0f,  1.0f,   1.0f, 1.0f
};


static gl_es2_uint   programs[ FILTER_COUNT];
static gl_es2_uint   scene_texture;
static gl_es2_uint   displacement_texture;
static unsigned char   scene_rgb[ TEXTURE_WIDTH * TEXTURE_HEIGHT * 3];
static unsigned char   displacement_rgba[ DISPLACEMENT_WIDTH * DISPLACEMENT_HEIGHT * 3];
static unsigned int   displacement_seed;


static void   set_1f( gl_es2_uint program, const char *name, float value)
{
   gl_es2_int   location;

   location = aex_gl_es2_GetUniformLocation( program, name);
   if( location >= 0)
      aex_gl_es2_Uniform1f( location, value);
}


static void   set_1i( gl_es2_uint program, const char *name, gl_es2_int value)
{
   gl_es2_int   location;

   location = aex_gl_es2_GetUniformLocation( program, name);
   if( location >= 0)
      aex_gl_es2_Uniform1i( location, value);
}


static void   set_2f( gl_es2_uint program, const char *name, float x, float y)
{
   gl_es2_int   location;

   location = aex_gl_es2_GetUniformLocation( program, name);
   if( location >= 0)
      aex_gl_es2_Uniform2f( location, x, y);
}


static void   set_3f( gl_es2_uint program, const char *name, float x, float y, float z)
{
   gl_es2_int   location;

   location = aex_gl_es2_GetUniformLocation( program, name);
   if( location >= 0)
      aex_gl_es2_Uniform3f( location, x, y, z);
}


static void   set_4f( gl_es2_uint program, const char *name, float x, float y, float z, float w)
{
   gl_es2_int   location;

   location = aex_gl_es2_GetUniformLocation( program, name);
   if( location >= 0)
      aex_gl_es2_Uniform4f( location, x, y, z, w);
}


static gl_es2_uint   compile_program( const char *fragment_source)
{
   gl_es2_uint   fragment_shader;
   gl_es2_uint   program;
   gl_es2_uint   vertex_shader;

   vertex_shader = aex_gl_es2_CreateShader( GL_ES2_VERTEX_SHADER);
   aex_gl_es2_ShaderSource( vertex_shader, 1, &vertex_source, NULL);
   aex_gl_es2_CompileShader( vertex_shader);
   if( demo_check_shader( vertex_shader))
      return( 0);

   fragment_shader = aex_gl_es2_CreateShader( GL_ES2_FRAGMENT_SHADER);
   aex_gl_es2_ShaderSource( fragment_shader, 1, &fragment_source, NULL);
   aex_gl_es2_CompileShader( fragment_shader);
   if( demo_check_shader( fragment_shader))
      return( 0);

   program = aex_gl_es2_CreateProgram();
   aex_gl_es2_AttachShader( program, vertex_shader);
   aex_gl_es2_AttachShader( program, fragment_shader);
   aex_gl_es2_BindAttribLocation( program, 0, "a_position");
   aex_gl_es2_BindAttribLocation( program, 1, "a_texcoord");
   aex_gl_es2_LinkProgram( program);
   if( demo_check_program( program))
      return( 0);

   aex_gl_es2_DeleteShader( vertex_shader);
   aex_gl_es2_DeleteShader( fragment_shader);
   return( program);
}


static unsigned int   next_random( void)
{
   displacement_seed = displacement_seed * 1664525u + 1013904223u;
   return( displacement_seed);
}


static void   make_scene_texture( unsigned char *rgb)
{
   int   s;
   int   source_row;
   int   x;
   int   y;

   for( y = 0; y < TEXTURE_HEIGHT; y++)
   {
      source_row = TEXTURE_HEIGHT - y - 1;
      for( x = 0; x < TEXTURE_WIDTH; x++)
      {
         int   b;
         int   g;
         int   r;
         int   stripe;

         s = g_smiley_256x256_luminance_data_[ source_row * TEXTURE_WIDTH + x];
         stripe = (((x / 16) ^ (source_row / 16)) & 1) ? 40 : 0;
         r = 20 + stripe + (x * 20) / 255;
         g = 10 + stripe / 2 + ((255 - source_row) * 16) / 255;
         b = 55 + stripe + (source_row * 50) / 255;

         r += s;
         g += (s * 3) / 4;
         b += s / 6;

         if( r > 255) r = 255;
         if( g > 255) g = 255;
         if( b > 255) b = 255;

         rgb[ (y * TEXTURE_WIDTH + x) * 3 + 0] = (unsigned char) r;
         rgb[ (y * TEXTURE_WIDTH + x) * 3 + 1] = (unsigned char) g;
         rgb[ (y * TEXTURE_WIDTH + x) * 3 + 2] = (unsigned char) b;
      }
   }
}


static void   write_u16_le( FILE *fp, unsigned int value)
{
   unsigned char   bytes[ 2];

   bytes[ 0] = (unsigned char) value;
   bytes[ 1] = (unsigned char) (value >> 8);
   fwrite( bytes, 1, 2, fp);
}


static void   write_u32_le( FILE *fp, unsigned int value)
{
   unsigned char   bytes[ 4];

   bytes[ 0] = (unsigned char) value;
   bytes[ 1] = (unsigned char) (value >> 8);
   bytes[ 2] = (unsigned char) (value >> 16);
   bytes[ 3] = (unsigned char) (value >> 24);
   fwrite( bytes, 1, 4, fp);
}


static int   write_rgb_bmp( const char *path,
                            const unsigned char *rgb,
                            int width,
                            int height)
{
   FILE   *fp;
   unsigned char   *row;
   unsigned int   data_size;
   unsigned int   file_size;
   int   padding;
   int   x;
   int   y;

   data_size = (unsigned int) (((width * 3 + 3) & ~3) * height);
   file_size = 54 + data_size;
   padding = (4 - (width * 3) % 4) % 4;

   fp = fopen( path, "wb");
   if( fp == NULL)
   {
      fprintf( stderr, "cannot open scene dump '%s'\n", path);
      return( 1);
   }

   fwrite( "BM", 1, 2, fp);
   write_u32_le( fp, file_size);
   write_u16_le( fp, 0);
   write_u16_le( fp, 0);
   write_u32_le( fp, 54);
   write_u32_le( fp, 40);
   write_u32_le( fp, (unsigned int) width);
   write_u32_le( fp, (unsigned int) height);
   write_u16_le( fp, 1);
   write_u16_le( fp, 24);
   write_u32_le( fp, 0);
   write_u32_le( fp, data_size);
   write_u32_le( fp, 0);
   write_u32_le( fp, 0);
   write_u32_le( fp, 0);
   write_u32_le( fp, 0);

   row = malloc( (size_t) width * 3);
   if( row == NULL)
   {
      fprintf( stderr, "out of memory\n");
      fclose( fp);
      return( 1);
   }

   for( y = 0; y < height; y++)
   {
      for( x = 0; x < width; x++)
      {
         row[ x * 3 + 0] = rgb[ (y * width + x) * 3 + 2];
         row[ x * 3 + 1] = rgb[ (y * width + x) * 3 + 1];
         row[ x * 3 + 2] = rgb[ (y * width + x) * 3 + 0];
      }

      if( fwrite( row, 1, (size_t) width * 3, fp) != (size_t) width * 3)
      {
         fprintf( stderr, "cannot write scene dump '%s'\n", path);
         free( row);
         fclose( fp);
         return( 1);
      }

      if( padding)
      {
         static const unsigned char   zeros[ 3] = { 0, 0, 0};
         fwrite( zeros, 1, (size_t) padding, fp);
      }
   }

   free( row);
   if( fclose( fp))
   {
      fprintf( stderr, "cannot close scene dump '%s'\n", path);
      return( 1);
   }
   return( 0);
}


static void   make_displacement_texture( void)
{
   int   height;
   int   i;
   int   offset;
   int   red;
   int   green;
   int   row;
   int   slice_height[ 8];
   int   slice_offset[ 8];
   int   remaining;
   int   x;

   displacement_seed = displacement_seed * 1664525u + 1013904223u;

   remaining = DISPLACEMENT_HEIGHT;
   for( i = 0; i < 8; i++)
   {
      if( i == 7)
         height = remaining;
      else
      {
         height = 24 + (int) (next_random() % 80u);
         if( height > remaining - (8 - i - 1))
            height = remaining - (8 - i - 1);
         if( height < 1)
            height = 1;
      }
      slice_height[ i] = height;
      remaining -= height;

      offset = (int) (next_random() % 512u) - 256;
      slice_offset[ i] = offset;
   }

   row = 0;
   for( i = 0; i < 8; i++)
   {
      offset = slice_offset[ i];
      red = offset > 0 ? offset : 0;
      green = offset < 0 ? -offset : 0;

      for( height = 0; height < slice_height[ i]; height++, row++)
      {
         for( x = 0; x < DISPLACEMENT_WIDTH; x++)
         {
            displacement_rgba[ (row * DISPLACEMENT_WIDTH + x) * 3 + 0] = (unsigned char) red;
            displacement_rgba[ (row * DISPLACEMENT_WIDTH + x) * 3 + 1] = (unsigned char) green;
            displacement_rgba[ (row * DISPLACEMENT_WIDTH + x) * 3 + 2] = 0;
         }
      }
   }
}


static void   upload_displacement_texture( void)
{
   aex_gl_es2_ActiveTexture( FILTER_TEXTURE_UNIT);
   aex_gl_es2_BindTexture( GL_ES2_TEXTURE_2D, displacement_texture);
   aex_gl_es2_TexImage2D( GL_ES2_TEXTURE_2D,
                          0,
                          GL_ES2_RGB,
                          DISPLACEMENT_WIDTH,
                          DISPLACEMENT_HEIGHT,
                          0,
                          GL_ES2_RGB,
                          GL_ES2_UNSIGNED_BYTE,
                          displacement_rgba);
   aex_gl_es2_TexParameteri( GL_ES2_TEXTURE_2D,
                             GL_ES2_TEXTURE_MIN_FILTER,
                             GL_ES2_NEAREST);
   aex_gl_es2_TexParameteri( GL_ES2_TEXTURE_2D,
                             GL_ES2_TEXTURE_MAG_FILTER,
                             GL_ES2_NEAREST);
   aex_gl_es2_TexParameteri( GL_ES2_TEXTURE_2D,
                             GL_ES2_TEXTURE_WRAP_S,
                             GL_ES2_CLAMP_TO_EDGE);
   aex_gl_es2_TexParameteri( GL_ES2_TEXTURE_2D,
                             GL_ES2_TEXTURE_WRAP_T,
                             GL_ES2_CLAMP_TO_EDGE);
   aex_gl_es2_ActiveTexture( GL_ES2_TEXTURE0);
}


static int   init_textures( void)
{
   make_scene_texture( scene_rgb);

   aex_gl_es2_PixelStorei( GL_ES2_UNPACK_ALIGNMENT, 1);

   aex_gl_es2_ActiveTexture( GL_ES2_TEXTURE0);
   aex_gl_es2_GenTextures( 1, &scene_texture);
   aex_gl_es2_BindTexture( GL_ES2_TEXTURE_2D, scene_texture);
   aex_gl_es2_TexImage2D( GL_ES2_TEXTURE_2D,
                          0,
                          GL_ES2_RGB,
                          TEXTURE_WIDTH,
                          TEXTURE_HEIGHT,
                          0,
                          GL_ES2_RGB,
                          GL_ES2_UNSIGNED_BYTE,
                          scene_rgb);
   aex_gl_es2_TexParameteri( GL_ES2_TEXTURE_2D,
                             GL_ES2_TEXTURE_MIN_FILTER,
                             GL_ES2_LINEAR);
   aex_gl_es2_TexParameteri( GL_ES2_TEXTURE_2D,
                             GL_ES2_TEXTURE_MAG_FILTER,
                             GL_ES2_LINEAR);
   aex_gl_es2_TexParameteri( GL_ES2_TEXTURE_2D,
                             GL_ES2_TEXTURE_WRAP_S,
                             GL_ES2_CLAMP_TO_EDGE);
   aex_gl_es2_TexParameteri( GL_ES2_TEXTURE_2D,
                             GL_ES2_TEXTURE_WRAP_T,
                             GL_ES2_CLAMP_TO_EDGE);

   aex_gl_es2_GenTextures( 1, &displacement_texture);
   displacement_seed = 1u;
   make_displacement_texture();
   upload_displacement_texture();
   return( 0);
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


static int   init_gl( void)
{
   int   i;

   for( i = 0; i < FILTER_COUNT; i++)
   {
      programs[ i] = compile_program( fragment_sources[ i]);
      if( ! programs[ i])
         return( 1);
   }

   if( init_textures())
      return( 1);

   aex_gl_es2_EnableVertexAttribArray( 0);
   aex_gl_es2_VertexAttribPointer( 0,
                                   2,
                                   GL_ES2_FLOAT,
                                   GL_ES2_FALSE,
                                   4 * sizeof( float),
                                   vertices);
   aex_gl_es2_EnableVertexAttribArray( 1);
   aex_gl_es2_VertexAttribPointer( 1,
                                   2,
                                   GL_ES2_FLOAT,
                                   GL_ES2_FALSE,
                                   4 * sizeof( float),
                                   vertices + 2);
   return( 0);
}


static void   draw_filter( int filter, float elapsed)
{
   gl_es2_uint   program;

   program = programs[ filter];
   aex_gl_es2_UseProgram( program);

   aex_gl_es2_ActiveTexture( GL_ES2_TEXTURE0);
   aex_gl_es2_BindTexture( GL_ES2_TEXTURE_2D, scene_texture);
   set_1i( program, "uTexture", 0);
   set_4f( program, "uInputSize", WINDOW_WIDTH, WINDOW_HEIGHT, 0.0f, 0.0f);
   set_4f( program, "uInputClamp", 0.0f, 0.0f, 1.0f, 1.0f);
   set_2f( program, "uDimensions", WINDOW_WIDTH, WINDOW_HEIGHT);

   switch( filter)
   {
      case FILTER_CRT :
         set_4f( program, "uLine", 1.0f, 1.0f, 0.25f, 0.0f);
         set_2f( program, "uNoise", 0.15f, 1.0f);
         set_3f( program, "uVignette", 0.3f, 1.0f, 0.3f);
         set_1f( program, "uSeed", fmodf( elapsed * 13.0f, 100.0f));
         set_1f( program, "uTime", elapsed);
         break;

      case FILTER_GLITCH :
         aex_gl_es2_ActiveTexture( FILTER_TEXTURE_UNIT);
         aex_gl_es2_BindTexture( GL_ES2_TEXTURE_2D, displacement_texture);
         set_1i( program, "uDisplacementMap", 1);
         set_1f( program, "uSeed", fmodf( elapsed * 0.37f, 1.0f));
         set_1f( program, "uAspect", (float) WINDOW_HEIGHT / WINDOW_WIDTH);
         set_1f( program, "uFillMode", 0.0f);
         set_1f( program, "uOffset", 100.0f);
         set_1f( program, "uDirection", 0.0f);
         set_2f( program, "uRed", 2.0f, 0.0f);
         set_2f( program, "uGreen", 0.0f, 0.0f);
         set_2f( program, "uBlue", -2.0f, 0.0f);
         break;

      case FILTER_ZOOM_BLUR :
         set_1f( program, "uStrength", 0.22f + 0.06f * sinf( elapsed * 1.3f));
         set_2f( program, "uCenter", WINDOW_WIDTH * 0.5f, WINDOW_HEIGHT * 0.5f);
         set_2f( program, "uRadii", 0.0f, -1.0f);
         break;

      case FILTER_SHOCKWAVE :
         set_1f( program, "uTime",
                 (0.15f + 0.45f * (0.5f + 0.5f * sinf( elapsed * 2.0f))) *
                 WINDOW_WIDTH / 500.0f);
         set_1f( program, "uSpeed", 500.0f);
         set_2f( program, "uCenter", WINDOW_WIDTH * 0.5f, WINDOW_HEIGHT * 0.5f);
         set_4f( program, "uWave", 50.0f, 80.0f, 1.0f, -1.0f);
         break;

      case FILTER_ASCII :
         set_1f( program, "uSize", 20.0f);
         set_3f( program, "uColor", 1.0f, 1.0f, 1.0f);
         set_1f( program, "uReplaceColor", 0.0f);
         break;
   }

   aex_gl_es2_DrawArrays( GL_ES2_TRIANGLE_STRIP, 0, 4);
}


static void   usage( const char *program)
{
   fprintf( stderr,
            "usage: %s [--filter N] [--time SECONDS] [--dump-scene PATH]\n",
            program);
}


int   main( int argc, char *argv[])
{
   const char   *dump_scene_path;
   SDL_Event   event;
   SDL_Window   *window;
   unsigned char   *pixels;
   unsigned int   current_filter;
   unsigned int   last_glitch_update;
   unsigned int   last_switch;
   unsigned int   requested_filter;
   unsigned int   start;
   unsigned int   now;
   float   elapsed;
   float   fixed_time;
   int   i;
   int   running;

   dump_scene_path = NULL;
   fixed_time = -1.0f;
   requested_filter = FILTER_COUNT;
   for( i = 1; i < argc; i++)
   {
      if( ! strcmp( argv[ i], "--filter") && i + 1 < argc)
      {
         requested_filter = (unsigned int) atoi( argv[ ++i]);
         if( requested_filter >= FILTER_COUNT)
            requested_filter = FILTER_COUNT;
      }
      else if( ! strcmp( argv[ i], "--time") && i + 1 < argc)
      {
         fixed_time = (float) atof( argv[ ++i]);
         if( fixed_time < 0.0f)
            fixed_time = 0.0f;
      }
      else if( ! strcmp( argv[ i], "--dump-scene") && i + 1 < argc)
         dump_scene_path = argv[ ++i];
      else
      {
         usage( argv[ 0]);
         return( 2);
      }
   }

   if( dump_scene_path)
   {
      make_scene_texture( scene_rgb);
      return( write_rgb_bmp( dump_scene_path,
                             scene_rgb,
                             TEXTURE_WIDTH,
                             TEXTURE_HEIGHT));
   }

   if( ! SDL_Init( SDL_INIT_VIDEO))
   {
      fprintf( stderr, "SDL_Init failed: %s\n", SDL_GetError());
      return( 1);
   }

   window = SDL_CreateWindow( "mulle-aex-gl PixiJS Filters",
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

   if( init_gl())
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

   current_filter = requested_filter < FILTER_COUNT ? requested_filter : FILTER_CRT;
   start = SDL_GetTicks();
   last_switch = start;
   last_glitch_update = 0;
   printf( "filter: %s\n", filter_names[ current_filter]);
   fflush( stdout);

   running = 1;
   while( running)
   {
      while( SDL_PollEvent( &event))
      {
         if( event.type == SDL_EVENT_QUIT)
            running = 0;
         else if( event.type == SDL_EVENT_KEY_DOWN)
         {
            if( event.key.key == SDLK_ESCAPE)
               running = 0;
            else if( event.key.key >= SDLK_1 && event.key.key <= SDLK_5)
            {
               current_filter = (unsigned int) (event.key.key - SDLK_1);
               if( current_filter < FILTER_COUNT)
               {
                  last_switch = SDL_GetTicks();
                  printf( "filter: %s\n", filter_names[ current_filter]);
                  fflush( stdout);
               }
            }
         }
      }

      now = SDL_GetTicks();
      if( requested_filter >= FILTER_COUNT &&
          fixed_time < 0.0f &&
          (now - last_switch) > 4000)
      {
         current_filter = (current_filter + 1) % FILTER_COUNT;
         last_switch = now;
         printf( "filter: %s\n", filter_names[ current_filter]);
         fflush( stdout);
      }

      if( current_filter == FILTER_GLITCH &&
          fixed_time < 0.0f &&
          (now - last_glitch_update) > 250)
      {
         make_displacement_texture();
         upload_displacement_texture();
         last_glitch_update = now;
      }

      elapsed = fixed_time >= 0.0f ? fixed_time : (now - start) / 1000.0f;

      aex_gl_es2_Viewport( 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
      aex_gl_es2_ClearColor( 0.0f, 0.0f, 0.0f, 1.0f);
      aex_gl_es2_Clear( GL_ES2_COLOR_BUFFER_BIT);
      draw_filter( (int) current_filter, elapsed);

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
   aex_gl_es2_DeleteTextures( 1, &scene_texture);
   aex_gl_es2_DeleteTextures( 1, &displacement_texture);
   for( i = 0; i < FILTER_COUNT; i++)
      aex_gl_es2_DeleteProgram( programs[ i]);
   SDL_DestroyWindow( window);
   SDL_Quit();
   return( 0);
}
