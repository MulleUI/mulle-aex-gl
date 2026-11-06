#include "glsl-test.h"


struct reject_case
{
   const char   *name_;
   int           type_;
   int           gap_;
   int           line_;
   const char   *needles_[ 6];
   const char   *source_;
   const char   *forbidden_;
};


static struct reject_case   reject_cases[] =
{
   {
      "missing-semicolon",
      GL_ES2_VERTEX_SHADER,
      0,
      4,
      { "syntax error", "expected", NULL },
      "void main(void)\n"
      "{\n"
      "   gl_Position = vec4( 0.0)\n"
      "}\n"
   },
   {
      "missing-brace",
      GL_ES2_VERTEX_SHADER,
      0,
      0,
      { "syntax error", "end of file", NULL },
      "void main(void)\n"
      "{\n"
      "   gl_Position = vec4( 0.0);\n"
   },
   {
      "undeclared-identifier",
      GL_ES2_VERTEX_SHADER,
      0,
      3,
      { "undeclared", "not declared", "unknown", "not found", NULL },
      "void main(void)\n"
      "{\n"
      "   gl_Position = foo;\n"
      "}\n"
   },
   {
      "redeclaration",
      GL_ES2_VERTEX_SHADER,
      0,
      4,
      { "redefinition", "already", "redeclaration", "duplicate", NULL },
      "void main(void)\n"
      "{\n"
      "   float x = 1.0;\n"
      "   float x = 2.0;\n"
      "   gl_Position = vec4( x);\n"
      "}\n"
   },
   {
      "duplicate-function",
      GL_ES2_VERTEX_SHADER,
      0,
      4,
      { "definition", "redefinition", "already", NULL },
      "void f(void)\n"
      "{\n"
      "}\n"
      "void f(void)\n"
      "{\n"
      "}\n"
      "void main(void)\n"
      "{\n"
      "   gl_Position = vec4( 0.0);\n"
      "}\n"
   },
   {
      "type-mismatch",
      GL_ES2_VERTEX_SHADER,
      0,
      3,
      { "incompatible", "cannot convert", "type", NULL },
      "void main(void)\n"
      "{\n"
      "   int x = vec2( 1.0);\n"
      "   gl_Position = vec4( float( x));\n"
      "}\n"
   },
   {
      "swizzle-too-many",
      GL_ES2_VERTEX_SHADER,
      0,
      4,
      { "swizzle", "component", "large", NULL },
      "void main(void)\n"
      "{\n"
      "   vec4 v = vec4( 0.0);\n"
      "   float f = v.xyzwx;\n"
      "   gl_Position = vec4( f);\n"
      "}\n"
   },
   {
      "swizzle-mixed-sets",
      GL_ES2_VERTEX_SHADER,
      0,
      4,
      { "swizzle", "component", NULL },
      "void main(void)\n"
      "{\n"
      "   vec4 v = vec4( 0.0);\n"
      "   float f = v.xg;\n"
      "   gl_Position = vec4( f);\n"
      "}\n"
   },
   {
      "swizzle-out-of-range",
      GL_ES2_VERTEX_SHADER,
      0,
      4,
      { "swizzle", "component", "large", NULL },
      "void main(void)\n"
      "{\n"
      "   vec2 v = vec2( 0.0);\n"
      "   float f = v.z;\n"
      "   gl_Position = vec4( f);\n"
      "}\n",
      "see line -"
   },
   {
      "array-size-not-constant",
      GL_ES2_VERTEX_SHADER,
      0,
      4,
      { "constant", "array", "size", NULL },
      "uniform int n;\n"
      "void main(void)\n"
      "{\n"
      "   float a[ n];\n"
      "   a[ 0] = 1.0;\n"
      "   gl_Position = vec4( a[ 0]);\n"
      "}\n"
   },
   {
      "undeclared-function",
      GL_ES2_VERTEX_SHADER,
      0,
      3,
      { "undeclared", "not declared", "unknown", "not a function", "not found", NULL },
      "void main(void)\n"
      "{\n"
      "   foo();\n"
      "   gl_Position = vec4( 0.0);\n"
      "}\n"
   },
   {
      "wrong-argument-count",
      GL_ES2_VERTEX_SHADER,
      0,
      7,
      { "argument", "parameter", "not found", NULL },
      "float f( float x)\n"
      "{\n"
      "   return x;\n"
      "}\n"
      "void main(void)\n"
      "{\n"
      "   float y = f( 1.0, 2.0);\n"
      "   gl_Position = vec4( y);\n"
      "}\n"
   },
   {
      "wrong-argument-type",
      GL_ES2_VERTEX_SHADER,
      0,
      7,
      { "incompatible", "type", "argument", "not found", NULL },
      "float f( float x)\n"
      "{\n"
      "   return x;\n"
      "}\n"
      "void main(void)\n"
      "{\n"
      "   float y = f( vec2( 1.0));\n"
      "   gl_Position = vec4( y);\n"
      "}\n"
   },
   {
      "break-outside-loop",
      GL_ES2_VERTEX_SHADER,
      0,
      3,
      { "break", "loop", NULL },
      "void main(void)\n"
      "{\n"
      "   break;\n"
      "   gl_Position = vec4( 0.0);\n"
      "}\n"
   },
   {
      "continue-outside-loop",
      GL_ES2_VERTEX_SHADER,
      0,
      3,
      { "continue", "loop", NULL },
      "void main(void)\n"
      "{\n"
      "   continue;\n"
      "   gl_Position = vec4( 0.0);\n"
      "}\n"
   },
   {
      "return-value-from-void",
      GL_ES2_VERTEX_SHADER,
      0,
      3,
      { "return", "void", NULL },
      "void main(void)\n"
      "{\n"
      "   return 1.0;\n"
      "}\n"
   },
   {
      "reserved-shift",
      GL_ES2_VERTEX_SHADER,
      0,
      3,
      { "reserved", NULL },
      "void main(void)\n"
      "{\n"
      "   int x = 1 << 2;\n"
      "   gl_Position = vec4( float( x));\n"
      "}\n"
   },
   {
      "reserved-mod-assign",
      GL_ES2_VERTEX_SHADER,
      0,
      4,
      { "reserved", NULL },
      "void main(void)\n"
      "{\n"
      "   int x = 1;\n"
      "   x %= 2;\n"
      "   gl_Position = vec4( float( x));\n"
      "}\n"
   },
   {
      "reserved-asm",
      GL_ES2_VERTEX_SHADER,
      0,
      3,
      { "syntax error", "reserved", NULL },
      "void main(void)\n"
      "{\n"
      "   int asm;\n"
      "   gl_Position = vec4( float( asm));\n"
      "}\n"
   },
   {
      "reserved-class",
      GL_ES2_VERTEX_SHADER,
      0,
      1,
      { "syntax error", "reserved", NULL },
      "class Foo\n"
      "{\n"
      "};\n"
      "void main(void)\n"
      "{\n"
      "   gl_Position = vec4( 0.0);\n"
      "}\n"
   },
   {
      "include",
      GL_ES2_VERTEX_SHADER,
      0,
      1,
      { "not supported", "include", NULL },
      "#include \"foo.glsl\"\n"
      "void main(void)\n"
      "{\n"
      "   gl_Position = vec4( 0.0);\n"
      "}\n"
   },
   {
      "version-300",
      GL_ES2_VERTEX_SHADER,
      0,
      1,
      { "version", NULL },
      "#version 300 es\n"
      "void main(void)\n"
      "{\n"
      "   gl_Position = vec4( 0.0);\n"
      "}\n"
   },
   {
      "version-not-first",
      GL_ES2_VERTEX_SHADER,
      0,
      5,
      { "version", "before", "first", NULL },
      "void main(void)\n"
      "{\n"
      "   gl_Position = vec4( 0.0);\n"
      "}\n"
      "#version 100\n"
   },
   {
      "version-after-define",
      GL_ES2_VERTEX_SHADER,
      0,
      2,
      { "version", "before", "first", NULL },
      "#define A 1\n"
      "#version 100\n"
      "void main(void)\n"
      "{\n"
      "   gl_Position = vec4( float( A));\n"
      "}\n"
   },
   {
      "void-parameter",
      GL_ES2_VERTEX_SHADER,
      0,
      1,
      { "void", "parameter", NULL },
      "void f( void x)\n"
      "{\n"
      "}\n"
      "void main(void)\n"
      "{\n"
      "   gl_Position = vec4( 0.0);\n"
      "}\n"
   },
   {
      "unknown-directive",
      GL_ES2_VERTEX_SHADER,
      0,
      1,
      { "directive", "syntax", "error", NULL },
      "#foo\n"
      "void main(void)\n"
      "{\n"
      "   gl_Position = vec4( 0.0);\n"
      "}\n"
   },
   {
      "elif-without-if",
      GL_ES2_VERTEX_SHADER,
      0,
      1,
      { "elif", "without", "syntax", NULL },
      "#elif 1\n"
      "void main(void)\n"
      "{\n"
      "   gl_Position = vec4( 0.0);\n"
      "}\n"
   },
   {
      "endif-without-if",
      GL_ES2_VERTEX_SHADER,
      0,
      1,
      { "endif", "without", "syntax", NULL },
      "#endif\n"
      "void main(void)\n"
      "{\n"
      "   gl_Position = vec4( 0.0);\n"
      "}\n"
   },
   {
      "unterminated-comment",
      GL_ES2_VERTEX_SHADER,
      0,
      0,
      { "comment", "unterminated", "end of file", "syntax", NULL },
      "/* never closed\n"
      "void main(void)\n"
      "{\n"
      "   gl_Position = vec4( 0.0);\n"
      "}\n"
   },
   {
      "invalid-number",
      GL_ES2_VERTEX_SHADER,
      0,
      3,
      { "syntax", NULL },
      "void main(void)\n"
      "{\n"
      "   float x = 1.2.3;\n"
      "   gl_Position = vec4( x);\n"
      "}\n"
   },
   {
      "discard-in-vertex",
      GL_ES2_VERTEX_SHADER,
      0,
      3,
      { "discard", "fragment", NULL },
      "void main(void)\n"
      "{\n"
      "   discard;\n"
      "   gl_Position = vec4( 0.0);\n"
      "}\n"
   },
   {
      "assign-to-const",
      GL_ES2_VERTEX_SHADER,
      0,
      4,
      { "const", "assign", "read-only", "lvalue", NULL },
      "const float x = 1.0;\n"
      "void main(void)\n"
      "{\n"
      "   x = 2.0;\n"
      "   gl_Position = vec4( x);\n"
      "}\n"
   },
   {
      "main-with-arguments",
      GL_ES2_VERTEX_SHADER,
      0,
      1,
      { "main", "argument", "parameter", NULL },
      "void main( int x)\n"
      "{\n"
      "   gl_Position = vec4( float( x));\n"
      "}\n"
   },
   {
      "fragcolor-in-vertex",
      GL_ES2_VERTEX_SHADER,
      0,
      3,
      { "undeclared", "gl_FragColor", "not declared", NULL },
      "void main(void)\n"
      "{\n"
      "   gl_FragColor = vec4( 1.0);\n"
      "}\n"
   },
   {
      "void-variable",
      GL_ES2_VERTEX_SHADER,
      0,
      1,
      { "void", "syntax", NULL },
      "void v;\n"
      "void main(void)\n"
      "{\n"
      "   gl_Position = vec4( 0.0);\n"
      "}\n"
   },
   {
      "struct-redefinition",
      GL_ES2_VERTEX_SHADER,
      0,
      5,
      { "redefinition", "already", "redeclaration", "duplicate", NULL },
      "struct S\n"
      "{\n"
      "   float f;\n"
      "};\n"
      "struct S\n"
      "{\n"
      "   float f;\n"
      "};\n"
      "void main(void)\n"
      "{\n"
      "   gl_Position = vec4( 0.0);\n"
      "}\n"
   },
   {
      "precision-missing-fragment",
      GL_ES2_FRAGMENT_SHADER,
      0,
      3,
      { "precision", NULL },
      "void main(void)\n"
      "{\n"
      "   float f = 1.0;\n"
      "   gl_FragColor = vec4( f);\n"
      "}\n"
   },
   {
      "array-constructor",
      GL_ES2_VERTEX_SHADER,
      0,
      3,
      { "array constructor", NULL },
      "void main(void)\n"
      "{\n"
      "   float a[ 2] = float[ 2]( 1.0, 2.0);\n"
      "   gl_Position = vec4( a[ 0], a[ 1], 0.0, 1.0);\n"
      "}\n"
   },
   {
      "recursion",
      GL_ES2_VERTEX_SHADER,
      0,
      3,
      { "recursion", "recursive", NULL },
      "float f( float x)\n"
      "{\n"
      "   return f( x);\n"
      "}\n"
      "void main(void)\n"
      "{\n"
      "   gl_Position = vec4( f( 1.0));\n"
      "}\n"
   },
   {
      "missing-return",
      GL_ES2_VERTEX_SHADER,
      0,
      1,
      { "return", NULL },
      "float f(void)\n"
      "{\n"
      "}\n"
      "void main(void)\n"
      "{\n"
      "   gl_Position = vec4( f());\n"
      "}\n"
   },
   {
      "missing-return-if",
      GL_ES2_VERTEX_SHADER,
      0,
      1,
      { "return", NULL },
      "float f( float x)\n"
      "{\n"
      "   if( x > 0.0)\n"
      "      return 1.0;\n"
      "}\n"
      "void main(void)\n"
      "{\n"
      "   gl_Position = vec4( f( 1.0));\n"
      "}\n"
   },
   {
      "array-out-of-bounds",
      GL_ES2_VERTEX_SHADER,
      0,
      4,
      { "bounds", "index", "array", "subscript", NULL },
      "void main(void)\n"
      "{\n"
      "   float a[ 2];\n"
      "   float f = a[ 3];\n"
      "   gl_Position = vec4( f);\n"
      "}\n"
   },
   {
      "ternary-type-mismatch",
      GL_ES2_VERTEX_SHADER,
      0,
      3,
      { "type", "incompatible", "conditional", NULL },
      "void main(void)\n"
      "{\n"
      "   int x = true ? 1.0 : 2;\n"
      "   gl_Position = vec4( float( x));\n"
      "}\n",
      "Logical not"
   },
   {
      "macro-unmatched-paren",
      GL_ES2_VERTEX_SHADER,
      0,
      1,
      { "syntax", "macro", "paren", "error", NULL },
      "#define FOO(a (a)\n"
      "void main(void)\n"
      "{\n"
      "   gl_Position = vec4( 0.0);\n"
      "}\n"
   }
};


static int   reject_matches( struct reject_case *c,
                             struct glsl_compile_result *r)
{
   size_t   i;

   if( r->ok_)
      return( 0);
   if( c->forbidden_ && glsl_test_log_contains( r->log_, c->forbidden_))
      return( 0);
   if( c->line_ && (glsl_test_log_line( r->log_) != c->line_))
      return( 0);
   for( i = 0; i < sizeof( c->needles_) / sizeof( *c->needles_); ++i)
   {
      if( ! c->needles_[ i])
         break;
      if( glsl_test_log_contains( r->log_, c->needles_[ i]))
         return( 1);
   }
   return( 0);
}


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

   count = sizeof( reject_cases) / sizeof( *reject_cases);
   passed = 0;
   gaps = 0;
   for( i = 0; i < count; ++i)
   {
      struct reject_case           *c;
      struct glsl_compile_result   r;
      int                          matched;

      c = &reject_cases[ i];
      glsl_test_compile( c->type_, c->source_, &r);
      matched = reject_matches( c, &r);
      if( c->gap_)
      {
         ++gaps;
         glsl_test_gap( c->name_, r.log_);
      }
      else if( matched)
      {
         ++passed;
         glsl_test_result( c->name_, 1, r.log_);
      }
      else
         glsl_test_result( c->name_, 0, r.log_);
      if( logs)
         fprintf( stderr, "--- %s (ok=%d line=%d) ---\n%s\n",
                  c->name_, r.ok_, glsl_test_log_line( r.log_), r.log_);
      glsl_test_delete( &r);
   }

   printf( "%zu/%zu shaders rejected, %zu gaps\n", passed, count - gaps, gaps);
   return( passed == count - gaps ? 0 : 1);
}
