#include "glsl-test.h"


struct ir_case
{
   const char   *name_;
   const char   *source_;
   const char   *expected_;
};


static struct ir_case   ir_cases[] =
{
   {
      "constructor-vec3",
      "void main(void)\n"
      "{\n"
      "   dump( vec3( 1, 2, 3));\n"
      "}\n",
      "vec3(1.000000, 2.000000, 3.000000)\n"
   },
   {
      "struct-constructor",
      "struct Light\n"
      "{\n"
      "   vec3 color;\n"
      "   float intensity;\n"
      "};\n"
      "void main(void)\n"
      "{\n"
      "   Light l = Light( vec3( 1.0, 2.0, 3.0), 0.5);\n"
      "   dump( l.color);\n"
      "   dump( l.intensity);\n"
      "}\n",
      "vec3(1.000000, 2.000000, 3.000000)\n"
      "0.500000\n"
   },
   {
      "add-integers",
      "void main(void)\n"
      "{\n"
      "   dump( 1 + 1);\n"
      "}\n",
      "2\n"
   },
   {
      "function-call",
      "void dump_arg( int arg)\n"
      "{\n"
      "   dump( arg);\n"
      "}\n"
      "void main(void)\n"
      "{\n"
      "   dump_arg( 1 + 1);\n"
      "}\n",
      "2\n"
   },
   {
      "swizzle-single",
      "void main(void)\n"
      "{\n"
      "   ivec4 v = ivec4( 1, 2, 3, 4);\n"
      "   dump( v.z);\n"
      "}\n",
      "3\n"
   },
   {
      "swizzle-paren",
      "void main(void)\n"
      "{\n"
      "   ivec4 v = ivec4( 1, 2, 3, 4);\n"
      "   dump( (v.zw).y);\n"
      "}\n",
      "4\n"
   },
   {
      "array-subscript",
      "void main(void)\n"
      "{\n"
      "   ivec4 v = ivec4( 1, 2, 3, 4);\n"
      "   dump( v[ 2]);\n"
      "}\n",
      "3\n"
   },
   {
      "swizzle-reverse-index",
      "void main(void)\n"
      "{\n"
      "   ivec4 v = ivec4( 0, 1, 2, 3);\n"
      "   dump( v.wzyx[ 0]);\n"
      "   dump( v.wzyx[ 1]);\n"
      "   dump( v.wzyx[ 2]);\n"
      "   dump( v.wzyx[ 3]);\n"
      "}\n",
      "3\n"
      "2\n"
      "1\n"
      "0\n"
   },
   {
      "swizzle-assignment",
      "void main(void)\n"
      "{\n"
      "   ivec4 v = ivec4( 0, 1, 2, 3);\n"
      "   v.xyzw = v.wzyx;\n"
      "   v.wzyx[ 2] = 6;\n"
      "   dump( v);\n"
      "}\n",
      "ivec4(3, 6, 1, 0)\n"
   },
   {
      "matrix-index",
      "void main(void)\n"
      "{\n"
      "   mat2 m = mat2( 0, 1, 2, 3);\n"
      "   dump( m[ 0]);\n"
      "   dump( m[ 1]);\n"
      "}\n",
      "vec2(0.000000, 1.000000)\n"
      "vec2(2.000000, 3.000000)\n"
   },
   {
      "matrix3-index",
      "void main(void)\n"
      "{\n"
      "   mat3 m = mat3( 0, 1, 2, 3, 4, 5, 6, 7, 8);\n"
      "   dump( m[ 0]);\n"
      "   dump( m[ 1]);\n"
      "}\n",
      "vec3(0.000000, 1.000000, 2.000000)\n"
      "vec3(3.000000, 4.000000, 5.000000)\n"
   },
   {
      "int-vector",
      "void main(void)\n"
      "{\n"
      "   dump( ivec2( 1, 2));\n"
      "}\n",
      "ivec2(1, 2)\n"
   },
   {
      "bool-vector",
      "void main(void)\n"
      "{\n"
      "   dump( bvec2( true, false));\n"
      "}\n",
      "bvec2(true, false)\n"
   },
   {
      "loop-sum",
      "void main(void)\n"
      "{\n"
      "   int sum = 0;\n"
      "   for( int i = 0; i < 4; ++i)\n"
      "      sum += i;\n"
      "   dump( sum);\n"
      "}\n",
      "6\n"
   },
   {
      "comma-operator",
      "void main(void)\n"
      "{\n"
      "   int a = (1, 2);\n"
      "   dump( a);\n"
      "}\n",
      "2\n"
   },
   {
      "conditional-operator",
      "void main(void)\n"
      "{\n"
      "   int a = (1 < 2) ? 10 : 20;\n"
      "   dump( a);\n"
      "}\n",
      "10\n"
   },
   {
      "logical-xor-precedence",
      "void main(void)\n"
      "{\n"
      "   int a = (true ^^ true && false) ? 1 : 0;\n"
      "   int b = (true ^^ true || true) ? 1 : 0;\n"
      "   dump( a);\n"
      "   dump( b);\n"
      "}\n",
      "1\n"
      "1\n"
   }
};


static int   ir_run( struct ir_case *c, char *log, size_t log_size)
{
   struct glsl_compile_result   r;
   gl_es2_uint                  program;
   gl_es2_int                   link_status;
   const char                  *dump;
   int                          result;

   result = 0;
   glsl_test_compile( AEX_GL_DEBUG_SHADER, c->source_, &r);
   if( ! r.ok_)
   {
      snprintf( log, log_size, "compile failed:\n%s", r.log_);
      glsl_test_delete( &r);
      return( 0);
   }

   program = aex_gl_es2_CreateProgram();
   aex_gl_es2_AttachShader( program, r.shader_);
   aex_gl_es2_LinkProgram( program);
   link_status = 0;
   aex_gl_es2_GetProgramiv( program, GL_ES2_LINK_STATUS, &link_status);
   if( ! link_status)
   {
      snprintf( log, log_size, "link failed");
   }
   else
   {
      aex_gl_es2_run_debug_shader( program);
      dump = aex_gl_es2_get_shader_debug_string( r.shader_);
      if( ! dump)
         dump = "";
      if( strcmp( dump, c->expected_))
      {
         snprintf( log, log_size, "expected:\n%sactual:\n%s",
                   c->expected_, dump);
      }
      else
         result = 1;
   }

   aex_gl_es2_DeleteProgram( program);
   glsl_test_delete( &r);
   return( result);
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

   count = sizeof( ir_cases) / sizeof( *ir_cases);
   passed = 0;
   gaps = 0;
   for( i = 0; i < count; ++i)
   {
      struct ir_case   *c;
      char              log[ GLSL_TEST_LOG_SIZE];

      c = &ir_cases[ i];
      log[ 0] = 0;
      if( ir_run( c, log, sizeof( log)))
      {
         ++passed;
         glsl_test_result( c->name_, 1, log);
      }
      else
         glsl_test_result( c->name_, 0, log);
      if( logs)
         fprintf( stderr, "--- %s ---\n%s\n", c->name_, log);
   }

   printf( "%zu/%zu IR tests passed, %zu gaps\n",
           passed, count - gaps, gaps);
   return( passed == count - gaps ? 0 : 1);
}
