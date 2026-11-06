#include "glsl-test.h"


struct accept_case
{
   const char   *name_;
   int           type_;
   int           gap_;
   const char   *source_;
};


static struct accept_case   accept_cases[] =
{
   {
      "minimal-vertex",
      GL_ES2_VERTEX_SHADER,
      0,
      "void main(void)\n"
      "{\n"
      "   gl_Position = vec4( 0.0, 0.0, 0.0, 1.0);\n"
      "}\n"
   },
   {
      "version-100",
      GL_ES2_VERTEX_SHADER,
      0,
      "#version 100\n"
      "void main(void)\n"
      "{\n"
      "   gl_Position = vec4( 0.0);\n"
      "}\n"
   },
   {
      "fragment-precision",
      GL_ES2_FRAGMENT_SHADER,
      0,
      "precision mediump float;\n"
      "void main(void)\n"
      "{\n"
      "   gl_FragColor = vec4( 1.0, 0.0, 0.0, 1.0);\n"
      "}\n"
   },
   {
      "attributes-uniforms-varyings",
      GL_ES2_VERTEX_SHADER,
      0,
      "attribute vec3 a_position;\n"
      "attribute vec2 a_uv;\n"
      "uniform mat4 u_mvp;\n"
      "varying vec2 v_uv;\n"
      "void main(void)\n"
      "{\n"
      "   v_uv = a_uv;\n"
      "   gl_Position = u_mvp * vec4( a_position, 1.0);\n"
      "}\n"
   },
   {
      "varying-fragment",
      GL_ES2_FRAGMENT_SHADER,
      0,
      "precision mediump float;\n"
      "varying vec2 v_uv;\n"
      "void main(void)\n"
      "{\n"
      "   gl_FragColor = vec4( v_uv, 0.0, 1.0);\n"
      "}\n"
   },
   {
      "struct",
      GL_ES2_VERTEX_SHADER,
      0,
      "struct Light\n"
      "{\n"
      "   vec3 color;\n"
      "   float intensity;\n"
      "};\n"
      "uniform Light u_light;\n"
      "void main(void)\n"
      "{\n"
      "   Light l;\n"
      "   l.color = u_light.color;\n"
      "   l.intensity = u_light.intensity;\n"
      "   gl_Position = vec4( l.color * l.intensity, 1.0);\n"
      "}\n"
   },
   {
      "struct-constructor",
      GL_ES2_VERTEX_SHADER,
      0,
      "struct Light\n"
      "{\n"
      "   vec3 color;\n"
      "   float intensity;\n"
      "};\n"
      "void main(void)\n"
      "{\n"
      "   Light l = Light( vec3( 1.0), 0.5);\n"
      "   gl_Position = vec4( l.color * l.intensity, 1.0);\n"
      "}\n"
   },
   {
      "return-paths",
      GL_ES2_VERTEX_SHADER,
      0,
      "float pick( float x)\n"
      "{\n"
      "   if( x > 0.0)\n"
      "      return 1.0;\n"
      "   else\n"
      "      return 2.0;\n"
      "}\n"
      "float spin(void)\n"
      "{\n"
      "   while( 1)\n"
      "      return 1.0;\n"
      "}\n"
      "void main(void)\n"
      "{\n"
      "   gl_Position = vec4( pick( 1.0), spin(), 0.0, 1.0);\n"
      "}\n"
   },
   {
      "nested-struct",
      GL_ES2_VERTEX_SHADER,
      0,
      "struct A\n"
      "{\n"
      "   vec3 v;\n"
      "};\n"
      "struct B\n"
      "{\n"
      "   A a;\n"
      "   float f;\n"
      "};\n"
      "void main(void)\n"
      "{\n"
      "   B b;\n"
      "   b.a.v = vec3( 1.0);\n"
      "   b.f = 2.0;\n"
      "   gl_Position = vec4( b.a.v * b.f, 1.0);\n"
      "}\n"
   },
   {
      "arrays",
      GL_ES2_VERTEX_SHADER,
      0,
      "uniform vec4 u_colors[ 4];\n"
      "void main(void)\n"
      "{\n"
      "   gl_Position = u_colors[ 2];\n"
      "}\n"
   },
   {
      "control-flow",
      GL_ES2_VERTEX_SHADER,
      0,
      "void main(void)\n"
      "{\n"
      "   int i;\n"
      "   float f = 0.0;\n"
      "   for( i = 0; i < 4; ++i)\n"
      "   {\n"
      "      f += 1.0;\n"
      "      if( f > 2.0)\n"
      "         break;\n"
      "   }\n"
      "   while( f < 3.0)\n"
      "   {\n"
      "      f += 0.5;\n"
      "      if( f == 2.5)\n"
      "         continue;\n"
      "   }\n"
      "   do\n"
      "   {\n"
      "      f -= 0.25;\n"
      "   } while( f > 0.0);\n"
      "   gl_Position = vec4( f);\n"
      "}\n"
   },
   {
      "for-declaration",
      GL_ES2_VERTEX_SHADER,
      0,
      "void main(void)\n"
      "{\n"
      "   float f = 0.0;\n"
      "   for( int i = 0; i < 4; ++i)\n"
      "      f += 1.0;\n"
      "   gl_Position = vec4( f);\n"
      "}\n"
   },
   {
      "empty-for-clauses",
      GL_ES2_VERTEX_SHADER,
      0,
      "void main(void)\n"
      "{\n"
      "   int i = 0;\n"
      "   for(;;)\n"
      "   {\n"
      "      if( i > 3)\n"
      "         break;\n"
      "      ++i;\n"
      "   }\n"
      "   gl_Position = vec4( float( i));\n"
      "}\n"
   },
   {
      "expressions",
      GL_ES2_VERTEX_SHADER,
      0,
      "void main(void)\n"
      "{\n"
      "   int a = 1 + 2 * 3 - 4 / 2;\n"
      "   bool b = (a > 1) && (a < 10) || false;\n"
      "   bool c = true ^^ false;\n"
      "   a = (a, 5);\n"
      "   gl_Position = vec4( float( a), float( b), float( c), 1.0);\n"
      "}\n"
   },
   {
      "ternary-scalar",
      GL_ES2_VERTEX_SHADER,
      0,
      "void main(void)\n"
      "{\n"
      "   float f = (1.0 > 0.0) ? 1.0 : 2.0;\n"
      "   gl_Position = vec4( f);\n"
      "}\n"
   },
   {
      "ternary-vector",
      GL_ES2_VERTEX_SHADER,
      0,
      "void main(void)\n"
      "{\n"
      "   vec3 v = (1.0 > 0.0) ? vec3( 1.0) : vec3( 2.0);\n"
      "   gl_Position = vec4( v, 1.0);\n"
      "}\n"
   },
   {
      "ternary-nested",
      GL_ES2_VERTEX_SHADER,
      0,
      "void main(void)\n"
      "{\n"
      "   float f = (1.0 > 0.0) ? ((2.0 > 1.0) ? 3.0 : 4.0) : 5.0;\n"
      "   gl_Position = vec4( f);\n"
      "}\n"
   },
   {
      "constructors",
      GL_ES2_VERTEX_SHADER,
      0,
      "void main(void)\n"
      "{\n"
      "   vec2 v2 = vec2( 1.0);\n"
      "   vec3 v3 = vec3( v2, 2.0);\n"
      "   vec4 v4 = vec4( v3, 3.0);\n"
      "   ivec4 i4 = ivec4( 1, 2, 3, 4);\n"
      "   bvec2 b2 = bvec2( true, false);\n"
      "   mat2 m2 = mat2( 1.0, 2.0, 3.0, 4.0);\n"
      "   mat3 m3 = mat3( m2);\n"
      "   gl_Position = v4 * float( i4.x) * float( b2.x) * m3[ 0].x;\n"
      "}\n"
   },
   {
      "swizzle",
      GL_ES2_VERTEX_SHADER,
      0,
      "void main(void)\n"
      "{\n"
      "   vec4 v = vec4( 1.0, 2.0, 3.0, 4.0);\n"
      "   v.xyzw = v.wzyx;\n"
      "   v.rg = v.ba;\n"
      "   v.st = v.pq;\n"
      "   gl_Position = v;\n"
      "}\n"
   },
   {
      "swizzle-index",
      GL_ES2_VERTEX_SHADER,
      0,
      "void main(void)\n"
      "{\n"
      "   vec4 v = vec4( 1.0, 2.0, 3.0, 4.0);\n"
      "   float f = v.wzyx[ 2];\n"
      "   gl_Position = vec4( f);\n"
      "}\n"
   },
   {
      "function-prototype-definition",
      GL_ES2_VERTEX_SHADER,
      0,
      "float square( float x);\n"
      "void main(void)\n"
      "{\n"
      "   gl_Position = vec4( square( 2.0));\n"
      "}\n"
      "float square( float x)\n"
      "{\n"
      "   return x * x;\n"
      "}\n"
   },
   {
      "function-overload",
      GL_ES2_VERTEX_SHADER,
      0,
      "float f( float x)\n"
      "{\n"
      "   return x;\n"
      "}\n"
      "int f( int x)\n"
      "{\n"
      "   return x;\n"
      "}\n"
      "void main(void)\n"
      "{\n"
      "   gl_Position = vec4( f( 1.0), float( f( 2)), 0.0, 1.0);\n"
      "}\n"
   },
   {
      "parameter-qualifiers",
      GL_ES2_VERTEX_SHADER,
      0,
      "void adjust( in float a, out float b, inout float c, const float d)\n"
      "{\n"
      "   b = a + d;\n"
      "   c += a;\n"
      "}\n"
      "void main(void)\n"
      "{\n"
      "   float b = 0.0;\n"
      "   float c = 1.0;\n"
      "   adjust( 2.0, b, c, 3.0);\n"
      "   gl_Position = vec4( b, c, 0.0, 1.0);\n"
      "}\n"
   },
   {
      "macros",
      GL_ES2_VERTEX_SHADER,
      0,
      "#define SCALE 2.0\n"
      "#define MUL(a, b) ((a) * (b))\n"
      "#define ENABLED 1\n"
      "#if ENABLED\n"
      "#define OFFSET 1.0\n"
      "#else\n"
      "#define OFFSET 2.0\n"
      "#endif\n"
      "void main(void)\n"
      "{\n"
      "   gl_Position = vec4( MUL( SCALE, OFFSET));\n"
      "}\n"
   },
   {
      "macro-continuation",
      GL_ES2_VERTEX_SHADER,
      0,
      "#define ADD(a, b) \\\n"
      "   ((a) + (b))\n"
      "void main(void)\n"
      "{\n"
      "   gl_Position = vec4( ADD( 1.0, 2.0));\n"
      "}\n"
   },
   {
      "ifdef-nested",
      GL_ES2_VERTEX_SHADER,
      0,
      "#define A\n"
      "#ifdef A\n"
      "#ifndef B\n"
      "#define C 1\n"
      "#endif\n"
      "#endif\n"
      "void main(void)\n"
      "{\n"
      "   gl_Position = vec4( float( C));\n"
      "}\n"
   },
   {
      "extension",
      GL_ES2_VERTEX_SHADER,
      0,
      "#version 100\n"
      "#extension GL_OES_standard_derivatives : enable\n"
      "void main(void)\n"
      "{\n"
      "   gl_Position = vec4( 0.0);\n"
      "}\n"
   },
   {
      "pragma",
      GL_ES2_VERTEX_SHADER,
      0,
      "#pragma optimize(on)\n"
      "void main(void)\n"
      "{\n"
      "   gl_Position = vec4( 0.0);\n"
      "}\n"
   },
   {
      "precision-qualifiers",
      GL_ES2_VERTEX_SHADER,
      0,
      "precision highp float;\n"
      "precision mediump int;\n"
      "uniform highp vec3 p;\n"
      "void main(void)\n"
      "{\n"
      "   gl_Position = vec4( p, 1.0);\n"
      "}\n"
   },
   {
      "invariant",
      GL_ES2_VERTEX_SHADER,
      0,
      "invariant gl_Position;\n"
      "void main(void)\n"
      "{\n"
      "   gl_Position = vec4( 0.0);\n"
      "}\n"
   },
   {
      "constant-literals",
      GL_ES2_VERTEX_SHADER,
      0,
      "const int I = 0x10 + 010;\n"
      "const float F = 1.0e2 + 0.5;\n"
      "void main(void)\n"
      "{\n"
      "   gl_Position = vec4( float( I), F, 0.0, 1.0);\n"
      "}\n"
   },
   {
      "empty-and-nested-scopes",
      GL_ES2_VERTEX_SHADER,
      0,
      "void main(void)\n"
      "{\n"
      "   ;\n"
      "   {\n"
      "      int x = 1;\n"
      "      {\n"
      "         float y = 2.0;\n"
      "      }\n"
      "   }\n"
      "   gl_Position = vec4( 0.0);\n"
      "}\n"
   },
   {
      "discard-fragment",
      GL_ES2_FRAGMENT_SHADER,
      0,
      "precision mediump float;\n"
      "void main(void)\n"
      "{\n"
      "   if( gl_FragCoord.x < 1.0)\n"
      "      discard;\n"
      "   gl_FragColor = vec4( 1.0);\n"
      "}\n"
   },
   {
      "matrices",
      GL_ES2_VERTEX_SHADER,
      0,
      "uniform mat4 u_mvp;\n"
      "uniform mat3 u_rot;\n"
      "void main(void)\n"
      "{\n"
      "   vec3 p = u_rot * vec3( 1.0, 2.0, 3.0);\n"
      "   gl_Position = u_mvp * vec4( p, 1.0);\n"
      "}\n"
   },
   {
      "fragment-gl-es-precision",
      GL_ES2_FRAGMENT_SHADER,
      0,
      "#version 100\n"
      "#ifdef GL_ES\n"
      "precision mediump float;\n"
      "#endif\n"
      "varying vec2 v;\n"
      "void main(void)\n"
      "{\n"
      "   gl_FragColor = vec4( v, 0.0, 1.0);\n"
      "}\n"
   },
   {
      "fragment-predefined-macros",
      GL_ES2_FRAGMENT_SHADER,
      0,
      "#version 100\n"
      "#if __VERSION__ == 100\n"
      "#ifdef GL_ES\n"
      "#ifdef GL_FRAGMENT_PRECISION_HIGH\n"
      "precision highp float;\n"
      "#endif\n"
      "#endif\n"
      "#endif\n"
      "varying vec2 v;\n"
      "void main(void)\n"
      "{\n"
      "   gl_FragColor = vec4( v, 0.0, 1.0);\n"
      "}\n"
   },
   {
      "comments",
      GL_ES2_VERTEX_SHADER,
      0,
      "// line comment\n"
      "/* block\n"
      "   comment */\n"
      "void main(void)\n"
      "{\n"
      "   gl_Position = vec4( 0.0); // trailing\n"
      "}\n"
   }
};


int   main( int argc, char *argv[])
{
   size_t   i;
   size_t   count;
   size_t   passed;
   size_t   gaps;
   int      logs;

   logs = (argc > 1) && ! strcmp( argv[ 1], "--logs");

   if( ! glsl_test_init())
      return( 1);

   count = sizeof( accept_cases) / sizeof( *accept_cases);
   passed = 0;
   gaps = 0;
   for( i = 0; i < count; ++i)
   {
      struct accept_case           *c;
      struct glsl_compile_result   r;

      c = &accept_cases[ i];
      glsl_test_compile( c->type_, c->source_, &r);
      if( r.ok_)
      {
         ++passed;
         glsl_test_result( c->name_, 1, r.log_);
      }
      else if( c->gap_)
      {
         ++gaps;
         glsl_test_gap( c->name_, r.log_);
      }
      else
         glsl_test_result( c->name_, 0, r.log_);
      if( logs)
         fprintf( stderr, "--- %s ---\n%s\n", c->name_, r.log_);
      glsl_test_delete( &r);
   }

   printf( "%zu/%zu shaders accepted, %zu gaps\n", passed, count - gaps, gaps);
   return( passed == count - gaps ? 0 : 1);
}
