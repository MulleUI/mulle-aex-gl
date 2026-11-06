#include "glsl-test.h"


struct diag_case
{
   const char   *name_;
   int           type_;
   const char   *source_;
};


static struct diag_case   diag_cases[] =
{
   {
      "missing-semicolon",
      GL_ES2_VERTEX_SHADER,
      "void main(void)\n"
      "{\n"
      "   gl_Position = vec4( 0.0)\n"
      "}\n"
   },
   {
      "invalid-number",
      GL_ES2_VERTEX_SHADER,
      "void main(void)\n"
      "{\n"
      "   float x = 1.2.3;\n"
      "   gl_Position = vec4( x);\n"
      "}\n"
   },
   {
      "swizzle-out-of-range",
      GL_ES2_VERTEX_SHADER,
      "void main(void)\n"
      "{\n"
      "   vec2 v = vec2( 0.0);\n"
      "   float f = v.z;\n"
      "   gl_Position = vec4( f);\n"
      "}\n"
   },
   {
      "ternary-type-mismatch",
      GL_ES2_VERTEX_SHADER,
      "void main(void)\n"
      "{\n"
      "   int x = true ? 1.0 : 2;\n"
      "   gl_Position = vec4( float( x));\n"
      "}\n"
   },
   {
      "reserved-class",
      GL_ES2_VERTEX_SHADER,
      "class Foo\n"
      "{\n"
      "};\n"
      "void main(void)\n"
      "{\n"
      "   gl_Position = vec4( 0.0);\n"
      "}\n"
   },
   {
      "unterminated-comment",
      GL_ES2_VERTEX_SHADER,
      "/* never closed\n"
      "void main(void)\n"
      "{\n"
      "   gl_Position = vec4( 0.0);\n"
      "}\n"
   },
   {
      "redeclaration",
      GL_ES2_VERTEX_SHADER,
      "void main(void)\n"
      "{\n"
      "   float x = 1.0;\n"
      "   float x = 2.0;\n"
      "   gl_Position = vec4( x);\n"
      "}\n"
   },
   {
      "macro-expansion",
      GL_ES2_VERTEX_SHADER,
      "#define BAD foo\n"
      "void main(void)\n"
      "{\n"
      "   gl_Position = vec4( BAD);\n"
      "}\n"
   },
   {
      "include",
      GL_ES2_VERTEX_SHADER,
      "#include \"foo.glsl\"\n"
      "void main(void)\n"
      "{\n"
      "   gl_Position = vec4( 0.0);\n"
      "}\n"
   },
   {
      "missing-brace",
      GL_ES2_VERTEX_SHADER,
      "void main(void)\n"
      "{\n"
      "   gl_Position = vec4( 0.0);\n"
   }
};


int   main( int argc, char *argv[])
{
   size_t   i;
   size_t   count;
   size_t   failed;

   if( ! glsl_test_init())
      return( 1);

   count = sizeof( diag_cases) / sizeof( *diag_cases);
   failed = 0;
   for( i = 0; i < count; ++i)
   {
      struct glsl_compile_result   r;

      glsl_test_compile( diag_cases[ i].type_, diag_cases[ i].source_, &r);
      if( r.ok_)
      {
         printf( "%s:\n   (compiled)\n", diag_cases[ i].name_);
         ++failed;
      }
      else
         printf( "%s:\n%s\n", diag_cases[ i].name_, r.log_);
      glsl_test_delete( &r);
   }

   printf( "%zu/%zu diagnostics captured\n", count - failed, count);
   return( failed ? 1 : 0);
}
