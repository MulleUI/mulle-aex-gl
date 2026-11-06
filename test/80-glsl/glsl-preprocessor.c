#include "glsl-test.h"


struct pp_case
{
   const char   *name_;
   int           type_;
   int           expect_ok_;
   int           gap_;
   int           line_;
   const char   *needles_[ 6];
   const char   *source_;
};


static struct pp_case   pp_cases[] =
{
   {
      "object-macro",
      GL_ES2_VERTEX_SHADER,
      1,
      0,
      0,
      { NULL },
      "#define FOO 1\n"
      "void main(void)\n"
      "{\n"
      "   gl_Position = vec4( float( FOO));\n"
      "}\n"
   },
   {
      "function-macro",
      GL_ES2_VERTEX_SHADER,
      1,
      0,
      0,
      { NULL },
      "#define ADD(a, b) ((a) + (b))\n"
      "void main(void)\n"
      "{\n"
      "   gl_Position = vec4( ADD( 1.0, 2.0));\n"
      "}\n"
   },
   {
      "nested-macro",
      GL_ES2_VERTEX_SHADER,
      1,
      0,
      0,
      { NULL },
      "#define A B\n"
      "#define B 1\n"
      "void main(void)\n"
      "{\n"
      "   gl_Position = vec4( float( A));\n"
      "}\n"
   },
   {
      "undef",
      GL_ES2_VERTEX_SHADER,
      0,
      0,
      5,
      { "undeclared", "not declared", "not found", NULL },
      "#define A 1\n"
      "#undef A\n"
      "void main(void)\n"
      "{\n"
      "   gl_Position = vec4( float( A));\n"
      "}\n"
   },
   {
      "if-else",
      GL_ES2_VERTEX_SHADER,
      1,
      0,
      0,
      { NULL },
      "#if 0\n"
      "#error \"wrong branch\"\n"
      "#else\n"
      "#define A 1\n"
      "#endif\n"
      "void main(void)\n"
      "{\n"
      "   gl_Position = vec4( float( A));\n"
      "}\n"
   },
   {
      "elif",
      GL_ES2_VERTEX_SHADER,
      1,
      0,
      0,
      { NULL },
      "#if 0\n"
      "#define A 1\n"
      "#elif 1\n"
      "#define A 2\n"
      "#else\n"
      "#define A 3\n"
      "#endif\n"
      "void main(void)\n"
      "{\n"
      "   gl_Position = vec4( float( A));\n"
      "}\n"
   },
   {
      "ifdef",
      GL_ES2_VERTEX_SHADER,
      1,
      0,
      0,
      { NULL },
      "#define A\n"
      "#ifdef A\n"
      "#define B 1\n"
      "#else\n"
      "#define B 2\n"
      "#endif\n"
      "void main(void)\n"
      "{\n"
      "   gl_Position = vec4( float( B));\n"
      "}\n"
   },
   {
      "ifndef",
      GL_ES2_VERTEX_SHADER,
      1,
      0,
      0,
      { NULL },
      "#ifndef A\n"
      "#define B 1\n"
      "#else\n"
      "#define B 2\n"
      "#endif\n"
      "void main(void)\n"
      "{\n"
      "   gl_Position = vec4( float( B));\n"
      "}\n"
   },
   {
      "defined",
      GL_ES2_VERTEX_SHADER,
      1,
      0,
      0,
      { NULL },
      "#define A\n"
      "#if defined( A) && defined A\n"
      "#define B 1\n"
      "#else\n"
      "#define B 2\n"
      "#endif\n"
      "void main(void)\n"
      "{\n"
      "   gl_Position = vec4( float( B));\n"
      "}\n"
   },
   {
      "skipped-garbage",
      GL_ES2_VERTEX_SHADER,
      1,
      0,
      0,
      { NULL },
      "#if 0\n"
      "this is not glsl at all !!!\n"
      "#endif\n"
      "void main(void)\n"
      "{\n"
      "   gl_Position = vec4( 0.0);\n"
      "}\n"
   },
   {
      "line-directive",
      GL_ES2_VERTEX_SHADER,
      0,
      0,
      42,
      { "boom", NULL },
      "#line 42\n"
      "#error \"boom\"\n"
      "void main(void)\n"
      "{\n"
      "   gl_Position = vec4( 0.0);\n"
      "}\n"
   },
   {
      "line-directive-syntax",
      GL_ES2_VERTEX_SHADER,
      0,
      0,
      100,
      { "syntax error", NULL },
      "#line 100\n"
      "void main(void) { gl_Position = ; }\n"
   },
   {
      "line-directive-semantic",
      GL_ES2_VERTEX_SHADER,
      0,
      0,
      202,
      { "undeclared", "not declared", NULL },
      "#line 200\n"
      "void main(void)\n"
      "{\n"
      "   gl_Position = foo;\n"
      "}\n"
   },
   {
      "error-directive",
      GL_ES2_VERTEX_SHADER,
      0,
      0,
      1,
      { "nope", NULL },
      "#error \"nope\"\n"
      "void main(void)\n"
      "{\n"
      "   gl_Position = vec4( 0.0);\n"
      "}\n"
   },
   {
      "pragma",
      GL_ES2_VERTEX_SHADER,
      1,
      0,
      0,
      { NULL },
      "#pragma STDGL invariant(all)\n"
      "void main(void)\n"
      "{\n"
      "   gl_Position = vec4( 0.0);\n"
      "}\n"
   },
   {
      "version-after-comment",
      GL_ES2_VERTEX_SHADER,
      1,
      0,
      0,
      { NULL },
      "// leading comment\n"
      "#version 100\n"
      "void main(void)\n"
      "{\n"
      "   gl_Position = vec4( 0.0);\n"
      "}\n"
   },
   {
      "extension",
      GL_ES2_VERTEX_SHADER,
      1,
      0,
      0,
      { NULL },
      "#version 100\n"
      "#extension GL_OES_standard_derivatives : enable\n"
      "void main(void)\n"
      "{\n"
      "   gl_Position = vec4( 0.0);\n"
      "}\n"
   },
   {
      "macro-redefinition",
      GL_ES2_VERTEX_SHADER,
      0,
      0,
      2,
      { "already", "redefinition", NULL },
      "#define A 1\n"
      "#define A 2\n"
      "void main(void)\n"
      "{\n"
      "   gl_Position = vec4( float( A));\n"
      "}\n"
   },
   {
      "if-not-integer",
      GL_ES2_VERTEX_SHADER,
      0,
      0,
      1,
      { "Syntax error", "const expr", "integer", "constant", NULL },
      "#if 1.0\n"
      "#define A 1\n"
      "#endif\n"
      "void main(void)\n"
      "{\n"
      "   gl_Position = vec4( 0.0);\n"
      "}\n"
   },
   {
      "unterminated-if",
      GL_ES2_VERTEX_SHADER,
      0,
      0,
      1,
      { "unterminated", "#if", "endif", NULL },
      "#if 1\n"
      "void main(void)\n"
      "{\n"
      "   gl_Position = vec4( 0.0);\n"
      "}\n"
   },
   {
      "variadic-macro",
      GL_ES2_VERTEX_SHADER,
      0,
      0,
      1,
      { "variadic", NULL },
      "#define FIRST(a, ...) a\n"
      "void main(void)\n"
      "{\n"
      "   gl_Position = vec4( float( FIRST( 1, 2, 3)));\n"
      "}\n"
   },
   {
      "stringize",
      GL_ES2_VERTEX_SHADER,
      0,
      0,
      1,
      { "'#'", NULL },
      "#define S(x) #x\n"
      "void main(void)\n"
      "{\n"
      "   gl_Position = vec4( 0.0);\n"
      "}\n"
   },
   {
      "token-paste",
      GL_ES2_VERTEX_SHADER,
      0,
      0,
      1,
      { "not supported", NULL },
      "#define CAT(a, b) a ## b\n"
      "void main(void)\n"
      "{\n"
      "   float xy = 1.0;\n"
      "   gl_Position = vec4( CAT( x, y));\n"
      "}\n"
   }
};


static int   pp_matches( struct pp_case *c, struct glsl_compile_result *r)
{
   size_t   i;

   if( c->expect_ok_)
      return( r->ok_);

   if( r->ok_)
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

   count = sizeof( pp_cases) / sizeof( *pp_cases);
   passed = 0;
   gaps = 0;
   for( i = 0; i < count; ++i)
   {
      struct pp_case               *c;
      struct glsl_compile_result   r;
      int                          matched;

      c = &pp_cases[ i];
      glsl_test_compile( c->type_, c->source_, &r);
      matched = pp_matches( c, &r);
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

   printf( "%zu/%zu preprocessor tests passed, %zu gaps\n",
           passed, count - gaps, gaps);
   return( passed == count - gaps ? 0 : 1);
}
