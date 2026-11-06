/* Copyright 2024 Kinglet B.V.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*
 * Recursive descent parser for GLSL ES 1.00.
 *
 * The parser consumes a buffered sequence of preprocessed tokens. It replaces
 * the Carburetta-generated LALR parser; the semantic actions are ported from
 * grammar/glsl_es_1.cbrt.
 */

#ifndef STDLIB_H_INCLUDED
#define STDLIB_H_INCLUDED
#include <stdlib.h>
#endif

#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED
#include <string.h>
#endif

#ifndef GLSL_ES_1_H_INCLUDED
#define GLSL_ES_1_H_INCLUDED
#include "glsl_es_1.h"
#endif

#ifndef GLSL_ES1_COMPILER_H_INCLUDED
#define GLSL_ES1_COMPILER_H_INCLUDED
#include "glsl_es1_compiler.h"
#endif

#ifndef GLSL_ES1_ASSIST_H_INCLUDED
#define GLSL_ES1_ASSIST_H_INCLUDED
#include "glsl_es1_assist.h"
#endif

#ifndef PP_TOKENS_H_INCLUDED
#define PP_TOKENS_H_INCLUDED
#include "pp/pp_tokens.h"
#endif

#ifndef SITUS_H_INCLUDED
#define SITUS_H_INCLUDED
#include "pp/situs.h"
#endif

#ifndef DIAGS_H_INCLUDED
#define DIAGS_H_INCLUDED
#include "pp/diags.h"
#endif

#ifndef SL_EXPR_H_INCLUDED
#define SL_EXPR_H_INCLUDED
#include "sl_expr.h"
#endif

#ifndef SL_STMT_H_INCLUDED
#define SL_STMT_H_INCLUDED
#include "sl_stmt.h"
#endif

#ifndef SL_FRAME_H_INCLUDED
#define SL_FRAME_H_INCLUDED
#include "sl_frame.h"
#endif

#ifndef SL_TYPES_H_INCLUDED
#define SL_TYPES_H_INCLUDED
#include "sl_types.h"
#endif

#ifndef SL_COMPILATION_UNIT_H_INCLUDED
#define SL_COMPILATION_UNIT_H_INCLUDED
#include "sl_compilation_unit.h"
#endif

#ifndef SYM_TABLE_H_INCLUDED
#define SYM_TABLE_H_INCLUDED
#include "sym_table.h"
#endif


struct condition_value
{
   struct sl_stmt   *initializer_;
   struct sl_expr   *condition_;
};


static int   parse_external_declaration( struct glsl_es1_stack *p);
static int   parse_declaration( struct glsl_es1_stack *p, struct sl_stmt **out);
static int   parse_statement_no_new_scope( struct glsl_es1_stack *p, struct sl_stmt **out);
static int   parse_statement_with_scope( struct glsl_es1_stack *p, struct sl_stmt **out);
static int   parse_compound_statement( struct glsl_es1_stack *p, int with_scope, struct sl_stmt **out);
static int   parse_expression( struct glsl_es1_stack *p, struct sl_expr **out);
static int   parse_assignment_expression( struct glsl_es1_stack *p, struct sl_expr **out);
static int   parse_constant_expression( struct glsl_es1_stack *p, struct sl_expr **out);
static int   parse_condition( struct glsl_es1_stack *p, struct condition_value *out);
static int   parse_fully_specified_type( struct glsl_es1_stack *p, struct sl_type **out);
static int   parse_type_specifier( struct glsl_es1_stack *p, struct sl_type **out);
static int   parse_type_specifier_no_prec( struct glsl_es1_stack *p, struct sl_type **out);
static int   parse_struct_specifier( struct glsl_es1_stack *p, struct sl_type **out);
static int   parse_parameter_declaration( struct glsl_es1_stack *p);
static int   parse_function( struct glsl_es1_stack *p, struct sl_type *return_type, struct pptk *name_tk);
static int   parse_init_declarator_list( struct glsl_es1_stack *p, struct sl_type *base_type, struct sl_stmt **out);


static struct pptk   *peek_token( struct glsl_es1_stack *p, size_t offset)
{
   if( p->pos_ + offset >= p->count_)
      return( NULL);
   return( p->tokens_[ p->pos_ + offset]);
}


static int   token_is( struct glsl_es1_stack *p, int tok)
{
   struct pptk   *tk;

   tk = peek_token( p, 0);
   return( tk && ((int) tk->tok_ == tok));
}


static struct pptk   *advance_token( struct glsl_es1_stack *p)
{
   struct pptk   *tk;

   tk = peek_token( p, 0);
   if( tk)
      ++p->pos_;
   return( tk);
}


static int   accept_token( struct glsl_es1_stack *p, int tok)
{
   if( token_is( p, tok))
   {
      ++p->pos_;
      return( 1);
   }
   return( 0);
}


static void   parser_syntax_error( struct glsl_es1_stack *p)
{
   struct pptk   *tk;
   struct diags  *dx;

   tk = peek_token( p, 0);
   dx = p->cc_->dx_;
   if( tk)
      dx_error_loc( dx, &tk->situs_, "syntax error at column %d: \"%s\"",
                    aex_situs_col( &tk->situs_), tk->text_ ? tk->text_ : "");
   else
      dx_error_loc( dx, &p->tokens_[ p->count_ - 1]->situs_,
                    "syntax error, unexpected end of file");
   p->failed_ = 1;
   p->result_ = _GLSL_ES1_SYNTAX_ERROR;
}


static const char   *token_description( int tok)
{
   switch( tok)
   {
      case PPTK_SEMICOLON:      return( "';'");
      case PPTK_PAR_OPEN:       return( "'('");
      case PPTK_PAR_CLOSE:      return( "')'");
      case PPTK_SQBRACE_OPEN:   return( "'['");
      case PPTK_SQBRACE_CLOSE:  return( "']'");
      case PPTK_CUBRACE_OPEN:   return( "'{'");
      case PPTK_CUBRACE_CLOSE:  return( "'}'");
      case PPTK_COLON:          return( "':'");
      case PPTK_EQUALS:         return( "'='");
      case PPTK_COMMA:          return( "','");
      case PPTK_IDENT:          return( "identifier");
   }
   return( "token");
}


static void   parser_syntax_error_expected( struct glsl_es1_stack *p, int tok)
{
   struct pptk   *tk;
   struct diags  *dx;

   tk = peek_token( p, 0);
   dx = p->cc_->dx_;
   if( tk)
      dx_error_loc( dx, &tk->situs_,
                    "syntax error at column %d: expected %s, found \"%s\"",
                    aex_situs_col( &tk->situs_),
                    token_description( tok),
                    tk->text_ ? tk->text_ : "");
   else if( p->count_)
      dx_error_loc( dx, &p->tokens_[ p->count_ - 1]->situs_,
                    "syntax error: expected %s, unexpected end of file",
                    token_description( tok));
   else
      dx_error( dx, "syntax error: expected %s, unexpected end of file",
                token_description( tok));
   p->failed_ = 1;
   p->result_ = _GLSL_ES1_SYNTAX_ERROR;
}


static int   expect_token( struct glsl_es1_stack *p, int tok)
{
   if( accept_token( p, tok))
      return( 0);
   parser_syntax_error_expected( p, tok);
   return( _GLSL_ES1_SYNTAX_ERROR);
}


static int   parser_nomem( struct glsl_es1_stack *p)
{
   dx_no_memory( p->cc_->dx_);
   p->failed_ = 1;
   p->result_ = _GLSL_ES1_NO_MEMORY;
   return( _GLSL_ES1_NO_MEMORY);
}


static int   is_builtin_type( int tok)
{
   switch( tok)
   {
      case PPTK_VOID:
      case PPTK_FLOAT:
      case PPTK_INT:
      case PPTK_BOOL:
      case PPTK_BOOL_ID:
      case PPTK_VEC2:
      case PPTK_VEC3:
      case PPTK_VEC4:
      case PPTK_BVEC2:
      case PPTK_BVEC3:
      case PPTK_BVEC4:
      case PPTK_IVEC2:
      case PPTK_IVEC3:
      case PPTK_IVEC4:
      case PPTK_MAT2:
      case PPTK_MAT3:
      case PPTK_MAT4:
      case PPTK_SAMPLER2D:
      case PPTK_SAMPLERCUBE:
         return( 1);
   }
   return( 0);
}


static struct sl_type   *builtin_type( struct glsl_es1_compiler *cc, int tok)
{
   switch( tok)
   {
      case PPTK_VOID:        return( &cc->tb_->void_);
      case PPTK_FLOAT:       return( &cc->tb_->float_);
      case PPTK_INT:         return( &cc->tb_->int_);
      case PPTK_BOOL:
      case PPTK_BOOL_ID:     return( &cc->tb_->bool_);
      case PPTK_VEC2:        return( &cc->tb_->vec2_);
      case PPTK_VEC3:        return( &cc->tb_->vec3_);
      case PPTK_VEC4:        return( &cc->tb_->vec4_);
      case PPTK_BVEC2:       return( &cc->tb_->bvec2_);
      case PPTK_BVEC3:       return( &cc->tb_->bvec3_);
      case PPTK_BVEC4:       return( &cc->tb_->bvec4_);
      case PPTK_IVEC2:       return( &cc->tb_->ivec2_);
      case PPTK_IVEC3:       return( &cc->tb_->ivec3_);
      case PPTK_IVEC4:       return( &cc->tb_->ivec4_);
      case PPTK_MAT2:        return( &cc->tb_->mat2_);
      case PPTK_MAT3:        return( &cc->tb_->mat3_);
      case PPTK_MAT4:        return( &cc->tb_->mat4_);
      case PPTK_SAMPLER2D:   return( &cc->tb_->sampler2D_);
      case PPTK_SAMPLERCUBE: return( &cc->tb_->samplerCube_);
   }
   return( NULL);
}


static struct sl_type   *struct_type_for_token( struct glsl_es1_stack *p,
                                                struct pptk *tk)
{
   struct sym_table   *scope;
   struct sym         *s;

   if( ! tk || (tk->tok_ != PPTK_IDENT) || ! tk->text_)
      return( NULL);

   scope = p->cc_->current_scope_;
   while( scope)
   {
      s = aex_st_find( scope, tk->text_, tk->text_len_);
      if( s)
      {
         if( s->kind_ == SK_STRUCT)
            return( s->v_.type_);
         return( NULL);
      }
      scope = scope->parent_;
   }
   return( NULL);
}


static int   token_starts_type( struct glsl_es1_stack *p)
{
   struct pptk   *tk;
   struct pptk   *next;

   tk = peek_token( p, 0);
   if( ! tk)
      return( 0);

   switch( tk->tok_)
   {
      case PPTK_CONST:
      case PPTK_ATTRIBUTE:
      case PPTK_VARYING:
      case PPTK_UNIFORM:
      case PPTK_PRECISION:
      case PPTK_HIGH_PRECISION:
      case PPTK_MEDIUM_PRECISION:
      case PPTK_LOW_PRECISION:
      case PPTK_STRUCT:
         return( 1);

      case PPTK_INVARIANT:
         next = peek_token( p, 1);
         return( next && next->tok_ == PPTK_VARYING);
   }

   if( is_builtin_type( tk->tok_))
      return( 1);

   if( (tk->tok_ == PPTK_IDENT) && struct_type_for_token( p, tk))
   {
      next = peek_token( p, 1);
      return( next && (next->tok_ == PPTK_IDENT));
   }
   return( 0);
}


static int   parse_type_qualifier( struct glsl_es1_stack *p, int *qual)
{
   struct pptk   *tk;

   tk = peek_token( p, 0);
   if( ! tk)
      return( 0);

   switch( tk->tok_)
   {
      case PPTK_CONST:
         *qual = SL_TYPE_QUALIFIER_CONST;
         ++p->pos_;
         return( 1);
      case PPTK_ATTRIBUTE:
         *qual = SL_TYPE_QUALIFIER_ATTRIBUTE;
         ++p->pos_;
         return( 1);
      case PPTK_VARYING:
         *qual = SL_TYPE_QUALIFIER_VARYING;
         ++p->pos_;
         return( 1);
      case PPTK_UNIFORM:
         *qual = SL_TYPE_QUALIFIER_UNIFORM;
         ++p->pos_;
         return( 1);
      case PPTK_INVARIANT:
         if( peek_token( p, 1) && peek_token( p, 1)->tok_ == PPTK_VARYING)
         {
            *qual = SL_TYPE_QUALIFIER_INVARIANT | SL_TYPE_QUALIFIER_VARYING;
            p->pos_ += 2;
            return( 1);
         }
         return( 0);
   }
   return( 0);
}


static int   parse_precision_qualifier( struct glsl_es1_stack *p, int *qual)
{
   struct pptk   *tk;

   tk = peek_token( p, 0);
   if( ! tk)
      return( 0);

   switch( tk->tok_)
   {
      case PPTK_HIGH_PRECISION:
         *qual = SL_TYPE_QUALIFIER_HIGH_PRECISION;
         ++p->pos_;
         return( 1);
      case PPTK_MEDIUM_PRECISION:
         *qual = SL_TYPE_QUALIFIER_MEDIUM_PRECISION;
         ++p->pos_;
         return( 1);
      case PPTK_LOW_PRECISION:
         *qual = SL_TYPE_QUALIFIER_LOW_PRECISION;
         ++p->pos_;
         return( 1);
   }
   return( 0);
}


static int   parse_type_specifier_no_prec( struct glsl_es1_stack *p,
                                          struct sl_type **out)
{
   struct pptk      *tk;
   struct sl_type   *t;

   tk = peek_token( p, 0);
   if( ! tk)
   {
      parser_syntax_error( p);
      return( _GLSL_ES1_SYNTAX_ERROR);
   }

   if( is_builtin_type( tk->tok_))
   {
      ++p->pos_;
      *out = builtin_type( p->cc_, tk->tok_);
      return( 0);
   }

   if( tk->tok_ == PPTK_STRUCT)
      return( parse_struct_specifier( p, out));

   if( tk->tok_ == PPTK_TYPEDEF_NAME)
   {
      ++p->pos_;
      *out = tk->v_.type_;
      return( 0);
   }

   t = struct_type_for_token( p, tk);
   if( t)
   {
      ++p->pos_;
      *out = t;
      return( 0);
   }

   parser_syntax_error( p);
   return( _GLSL_ES1_SYNTAX_ERROR);
}


static int   parse_type_specifier( struct glsl_es1_stack *p,
                                  struct sl_type **out)
{
   struct sl_type   *t;
   int               precision;
   int               have_precision;
   int               r;

   precision = 0;
   have_precision = parse_precision_qualifier( p, &precision);
   r = parse_type_specifier_no_prec( p, &t);
   if( r)
      return( r);
   if( have_precision)
   {
      t = sl_type_base_qualified_type( p->cc_->tb_, t, precision);
      if( ! t)
         return( parser_nomem( p));
   }
   p->cc_->last_type_specifier_ = t;
   *out = t;
   return( 0);
}


static int   parse_fully_specified_type( struct glsl_es1_stack *p,
                                        struct sl_type **out)
{
   struct sl_type   *t;
   int               qualifier;
   int               r;

   qualifier = 0;
   parse_type_qualifier( p, &qualifier);
   r = parse_type_specifier( p, &t);
   if( r)
      return( r);
   if( qualifier)
   {
      t = sl_type_base_qualified_type( p->cc_->tb_, t, qualifier);
      if( ! t)
         return( parser_nomem( p));
   }
   p->cc_->last_type_specifier_ = t;
   *out = t;
   return( 0);
}


static int   parse_struct_declarator( struct glsl_es1_stack *p,
                                      struct sl_type_field **out)
{
   struct pptk            *name_tk;
   struct sl_type         *field_type;
   struct sl_type         *array_type;
   struct sl_expr         *size_expr;
   struct sl_type_field   *field;
   int                     r;

   name_tk = peek_token( p, 0);
   if( ! name_tk || (name_tk->tok_ != PPTK_IDENT))
   {
      parser_syntax_error( p);
      return( _GLSL_ES1_SYNTAX_ERROR);
   }
   ++p->pos_;

   field_type = p->cc_->last_type_specifier_;
   if( accept_token( p, PPTK_SQBRACE_OPEN))
   {
      r = parse_constant_expression( p, &size_expr);
      if( r)
         return( r);
      r = expect_token( p, PPTK_SQBRACE_CLOSE);
      if( r)
      {
         sl_expr_free( size_expr);
         return( r);
      }
      array_type = NULL;
      r = glsl_es1_build_array_type( p->cc_->dx_, p->cc_->tb_, field_type,
                                     size_expr, &name_tk->situs_, &array_type);
      sl_expr_free( size_expr);
      if( r)
         return( r);
      if( array_type)
         field_type = array_type;
   }

   field = sl_type_field_alloc( p->cc_->tb_, name_tk->text_,
                                &name_tk->situs_, field_type);
   if( ! field)
      return( parser_nomem( p));
   *out = field;
   return( 0);
}


static int   parse_struct_declarator_list( struct glsl_es1_stack *p,
                                          struct sl_type_field **out)
{
   struct sl_type_field   *list;
   struct sl_type_field   *field;
   int                     r;

   r = parse_struct_declarator( p, &list);
   if( r)
      return( r);
   while( accept_token( p, PPTK_COMMA))
   {
      r = parse_struct_declarator( p, &field);
      if( r)
      {
         sl_type_field_free_chain( list);
         return( r);
      }
      list = sl_type_field_join( list, field);
   }
   *out = list;
   return( 0);
}


static int   parse_struct_declaration( struct glsl_es1_stack *p,
                                       struct sl_type_field **out)
{
   struct sl_type   *type;
   int               r;

   r = parse_type_specifier( p, &type);
   if( r)
      return( r);
   r = parse_struct_declarator_list( p, out);
   if( r)
      return( r);
   return( expect_token( p, PPTK_SEMICOLON));
}


static int   parse_struct_declaration_list( struct glsl_es1_stack *p,
                                           struct sl_type_field **out)
{
   struct sl_type_field   *list;
   struct sl_type_field   *field;
   int                     r;

   list = NULL;
   while( ! token_is( p, PPTK_CUBRACE_CLOSE))
   {
      if( ! peek_token( p, 0))
      {
         parser_syntax_error( p);
         if( list)
            sl_type_field_free_chain( list);
         return( _GLSL_ES1_SYNTAX_ERROR);
      }
      r = parse_struct_declaration( p, &field);
      if( r)
      {
         if( list)
            sl_type_field_free_chain( list);
         return( r);
      }
      list = list ? sl_type_field_join( list, field) : field;
   }
   *out = list;
   return( 0);
}


static int   parse_struct_specifier( struct glsl_es1_stack *p,
                                    struct sl_type **out)
{
   struct pptk            *struct_tk;
   struct pptk            *tag_tk;
   struct sl_type_field   *fields;
   struct sl_type         *t;
   struct sym_table       *scope;
   struct sym             *s;
   sym_table_result_t      str;
   struct situs           *tag_loc;
   const char             *tag;
   int                     r;

   struct_tk = advance_token( p);
   tag_tk = NULL;
   if( token_is( p, PPTK_IDENT))
      tag_tk = advance_token( p);

   r = expect_token( p, PPTK_CUBRACE_OPEN);
   if( r)
      return( r);
   r = parse_struct_declaration_list( p, &fields);
   if( r)
      return( r);
   r = expect_token( p, PPTK_CUBRACE_CLOSE);
   if( r)
   {
      if( fields)
         sl_type_field_free_chain( fields);
      return( r);
   }

   tag = tag_tk ? tag_tk->text_ : NULL;
   tag_loc = tag_tk ? &tag_tk->situs_ : &struct_tk->situs_;

   scope = p->cc_->current_scope_;
   s = NULL;
   if( tag)
   {
      str = STR_OK;
   str = aex_st_find_or_insert( scope, SK_STRUCT, tag, strlen( tag),
                                   tag_loc, sizeof( struct sym), &s);
      if( str == STR_NOMEM)
      {
         if( fields)
            sl_type_field_free_chain( fields);
         return( parser_nomem( p));
      }
      if( str == STR_DUPLICATE)
      {
         dx_error_loc( p->cc_->dx_, tag_loc,
                       "Error: duplicate identifier \"%s\" declaration", tag);
         dx_error_loc( p->cc_->dx_, &s->loc_,
                       "See original use of \"%s\"", s->name_);
      }
   }

   t = sl_type_base_struct_type( p->cc_->tb_, tag, tag_loc, fields);
   if( ! t)
   {
      if( fields)
         sl_type_field_free_chain( fields);
      return( parser_nomem( p));
   }
   if( tag && (str == STR_OK))
      s->v_.type_ = t;
   t->fields_ = fields;
   *out = t;
   return( 0);
}


static int   parse_parameter_declaration( struct glsl_es1_stack *p)
{
   struct pptk        *tk;
   struct pptk        *type_tk;
   struct pptk        *name_tk;
   struct sl_type     *type;
   struct sl_type     *array_type;
   struct sl_expr     *size_expr;
   int                 type_qualifier;
   int                 parameter_qualifier;
   int                 qualifiers;
   int                 r;

   type_qualifier = 0;
   parameter_qualifier = 0;

   parse_type_qualifier( p, &type_qualifier);

   tk = peek_token( p, 0);
   if( tk)
   {
      switch( tk->tok_)
      {
         case PPTK_IN:
            parameter_qualifier = SL_PARAMETER_QUALIFIER_IN;
            ++p->pos_;
            break;
         case PPTK_OUT:
            parameter_qualifier = SL_PARAMETER_QUALIFIER_OUT;
            ++p->pos_;
            break;
         case PPTK_INOUT:
            parameter_qualifier = SL_PARAMETER_QUALIFIER_INOUT;
            ++p->pos_;
            break;
      }
   }

   type_tk = peek_token( p, 0);
   r = parse_type_specifier( p, &type);
   if( r)
      return( r);

   name_tk = NULL;
   if( token_is( p, PPTK_IDENT))
      name_tk = advance_token( p);

   if( name_tk && type &&
       (sl_type_unqualified( type)->kind_ == sltk_void))
   {
      dx_error_loc( p->cc_->dx_, &name_tk->situs_,
                    "parameter \"%s\" cannot have type void", name_tk->text_);
   }

   if( accept_token( p, PPTK_SQBRACE_OPEN))
   {
      r = parse_constant_expression( p, &size_expr);
      if( r)
         return( r);
      r = expect_token( p, PPTK_SQBRACE_CLOSE);
      if( r)
      {
         sl_expr_free( size_expr);
         return( r);
      }
      array_type = NULL;
      r = glsl_es1_build_array_type( p->cc_->dx_, p->cc_->tb_, type,
                                     size_expr,
                                     name_tk ? &name_tk->situs_ : &type_tk->situs_,
                                     &array_type);
      sl_expr_free( size_expr);
      if( r)
         return( r);
      if( array_type)
         type = array_type;
   }

   qualifiers = type_qualifier | parameter_qualifier;
   if( qualifiers)
   {
      type = sl_type_base_qualified_type( p->cc_->tb_, type, qualifiers);
      if( ! type)
         return( parser_nomem( p));
   }

   if( p->cc_->current_function_prototype_)
   {
      if( sl_function_append_parameter( p->cc_->current_function_prototype_,
                                        name_tk ? name_tk->text_ : NULL,
                                        name_tk ? &name_tk->situs_ : NULL,
                                        type) == SIZE_MAX)
         return( parser_nomem( p));
   }
   return( 0);
}


static int   parse_primary_expression( struct glsl_es1_stack *p,
                                      struct sl_expr **out)
{
   struct pptk                      *tk;
   struct pptk                      *next;
   struct pptk                      *name_tk;
   struct sl_type                   *type;
   struct sl_expr                   *expr;
   struct sl_expr                  **args;
   struct glsl_es1_function_call     fc;
   struct sym_table                 *scope;
   struct sym                       *s;
   size_t                            num_args;
   size_t                            args_allocated;
   int                               had_error;
   int                               r;

   tk = peek_token( p, 0);
   if( ! tk)
   {
      parser_syntax_error( p);
      return( _GLSL_ES1_SYNTAX_ERROR);
   }

   switch( tk->tok_)
   {
      case PPTK_INTEGER_LIT:
         ++p->pos_;
         expr = sl_expr_alloc_int_lit( tk->v_.i64_, &tk->situs_);
         if( ! expr)
            return( parser_nomem( p));
         *out = expr;
         return( 0);

      case PPTK_FLOAT_LIT:
         ++p->pos_;
         expr = sl_expr_alloc_float_lit( (tk->v_type_ == PPVT_FLOAT) ? tk->v_.f_ : (float) tk->v_.d_,
                                        &tk->situs_);
         if( ! expr)
            return( parser_nomem( p));
         *out = expr;
         return( 0);

      case PPTK_BOOL_CONSTANT:
         ++p->pos_;
         expr = sl_expr_alloc_bool_lit( !! tk->v_.u64_, &tk->situs_);
         if( ! expr)
            return( parser_nomem( p));
         *out = expr;
         return( 0);

      case PPTK_PAR_OPEN:
         ++p->pos_;
         r = parse_expression( p, &expr);
         if( r)
            return( r);
         r = expect_token( p, PPTK_PAR_CLOSE);
         if( r)
         {
            sl_expr_free( expr);
            return( r);
         }
         *out = expr;
         return( 0);
   }

   /* Constructor for a built-in type. */
   if( is_builtin_type( tk->tok_))
   {
      next = peek_token( p, 1);
      if( next && (next->tok_ == PPTK_SQBRACE_OPEN))
      {
         dx_error_loc( p->cc_->dx_, &next->situs_,
                       "array constructors are not supported in GLSL ES 1.00");
         return( _GLSL_ES1_SYNTAX_ERROR);
      }
      if( ! next || (next->tok_ != PPTK_PAR_OPEN))
      {
         parser_syntax_error( p);
         return( _GLSL_ES1_SYNTAX_ERROR);
      }
      type = builtin_type( p->cc_, tk->tok_);
      name_tk = tk;
      ++p->pos_; /* type */
      ++p->pos_; /* ( */
      goto parse_call_arguments;
   }

   if( tk->tok_ != PPTK_IDENT)
   {
      parser_syntax_error( p);
      return( _GLSL_ES1_SYNTAX_ERROR);
   }

   name_tk = tk;
   next = peek_token( p, 1);
   if( next && (next->tok_ == PPTK_SQBRACE_OPEN))
   {
      type = struct_type_for_token( p, name_tk);
      if( type)
      {
         dx_error_loc( p->cc_->dx_, &next->situs_,
                       "array constructors are not supported in GLSL ES 1.00");
         return( _GLSL_ES1_SYNTAX_ERROR);
      }
   }
   if( next && (next->tok_ == PPTK_PAR_OPEN))
   {
      type = struct_type_for_token( p, name_tk);
      ++p->pos_; /* identifier */
      ++p->pos_; /* ( */
      goto parse_call_arguments;
   }

   /* Plain variable reference. */
   ++p->pos_;
   s = NULL;
   scope = p->cc_->current_scope_;
   while( scope)
   {
      s = aex_st_find( scope, name_tk->text_, name_tk->text_len_);
      if( s)
         break;
      scope = scope->parent_;
   }
   if( s)
   {
      if( s->kind_ == SK_VARIABLE)
      {
         expr = sl_expr_alloc_variable( s->v_.variable_, &name_tk->situs_);
         if( ! expr)
            return( parser_nomem( p));
         *out = expr;
         return( 0);
      }
      dx_error_loc( p->cc_->dx_, &name_tk->situs_,
                    "Error: identifier \"%s\" is not a variable",
                    name_tk->text_);
   }
   else
      dx_error_loc( p->cc_->dx_, &name_tk->situs_,
                    "Error: identifier \"%s\" not declared", name_tk->text_);
   *out = NULL;
   return( 0);

parse_call_arguments:
   glsl_es1_function_call_init( &fc);
   fc.constructor_type_ = type;
   if( ! type)
   {
      fc.name_ = name_tk->text_;
      name_tk->text_ = NULL;
      aex_situs_clone( &fc.loc_, &name_tk->situs_);
   }
   else
      aex_situs_clone( &fc.loc_, &name_tk->situs_);

   args = NULL;
   num_args = 0;
   args_allocated = 0;
   had_error = 0;

   if( ! token_is( p, PPTK_PAR_CLOSE))
   {
      if( token_is( p, PPTK_VOID) && peek_token( p, 1) &&
          (peek_token( p, 1)->tok_ == PPTK_PAR_CLOSE))
         ++p->pos_;
      else
      {
         for(;;)
         {
            struct sl_expr   *arg;

            r = parse_assignment_expression( p, &arg);
            if( r)
               goto call_error;
            if( ! arg)
            {
               had_error = 1;
            }
            else
            {
               if( num_args == args_allocated)
               {
                  size_t                    new_allocated;
                  struct sl_expr          **new_args;

                  new_allocated = args_allocated + args_allocated + 1;
                  new_args = (struct sl_expr **) realloc( args, new_allocated * sizeof( *args));
                  if( ! new_args)
                  {
                     sl_expr_free( arg);
                     r = parser_nomem( p);
                     goto call_error;
                  }
                  args = new_args;
                  args_allocated = new_allocated;
               }
               args[ num_args++] = arg;
            }
            if( ! accept_token( p, PPTK_COMMA))
               break;
         }
      }
   }

   r = expect_token( p, PPTK_PAR_CLOSE);
   if( r)
      goto call_error;

   if( had_error)
   {
      size_t   n;

      for( n = 0; n < num_args; ++n)
         sl_expr_free( args[ n]);
      free( args);
      glsl_es1_function_call_cleanup( &fc);
      *out = NULL;
      return( 0);
   }

   {
      size_t   n;

      for( n = 0; n < num_args; ++n)
      {
         if( glsl_es1_function_call_append_parameter( &fc, args[ n], &args[ n]->op_loc_))
         {
            for( ; n < num_args; ++n)
               sl_expr_free( args[ n]);
            r = parser_nomem( p);
            goto call_error;
         }
         args[ n] = NULL;
      }
   }
   free( args);
   args = NULL;

   expr = glsl_es1_function_call_realize( p->cc_->dx_, p->cc_->current_scope_,
                                          p->cc_->tb_, &fc);
   glsl_es1_function_call_cleanup( &fc);
   *out = expr;
   return( 0);

call_error:
   free( args);
   glsl_es1_function_call_cleanup( &fc);
   return( r);
}


static int   parse_postfix_expression( struct glsl_es1_stack *p,
                                      struct sl_expr **out)
{
   struct sl_expr   *expr;
   struct sl_expr   *index;
   struct sl_expr   *result;
   struct pptk      *tk;
   struct pptk      *op_tk;
   int               r;

   r = parse_primary_expression( p, &expr);
   if( r)
      return( r);

   for(;;)
   {
      if( ! expr)
         break;

      tk = peek_token( p, 0);
      if( ! tk)
         break;

      if( tk->tok_ == PPTK_SQBRACE_OPEN)
      {
         op_tk = advance_token( p);
         r = parse_expression( p, &index);
         if( r)
         {
            sl_expr_free( expr);
            return( r);
         }
         r = expect_token( p, PPTK_SQBRACE_CLOSE);
         if( r)
         {
            sl_expr_free( expr);
            sl_expr_free( index);
            return( r);
         }
         result = sl_expr_alloc_binop( exop_array_subscript, &op_tk->situs_,
                                       &expr, &index);
         if( ! result)
         {
            sl_expr_free( expr);
            sl_expr_free( index);
            return( parser_nomem( p));
         }
         expr = result;
         continue;
      }

      if( tk->tok_ == PPTK_DOT)
      {
         struct pptk   *field_tk;

         advance_token( p);
         field_tk = peek_token( p, 0);
         if( ! field_tk || (field_tk->tok_ != PPTK_IDENT))
         {
            sl_expr_free( expr);
            parser_syntax_error( p);
            return( _GLSL_ES1_SYNTAX_ERROR);
         }
         ++p->pos_;
         result = glsl_es1_field_or_swizzle_selection( p->cc_->dx_, p->cc_->tb_,
                                                       expr, field_tk->text_,
                                                       &field_tk->situs_);
         if( result)
            expr = result;
         else
         {
            sl_expr_free( expr);
            expr = NULL;
         }
         continue;
      }

      if( tk->tok_ == PPTK_PLUS_PLUS)
      {
         ++p->pos_;
         result = sl_expr_alloc_unop( exop_post_inc, &tk->situs_, &expr);
         if( ! result)
         {
            sl_expr_free( expr);
            return( parser_nomem( p));
         }
         expr = result;
         continue;
      }

      if( tk->tok_ == PPTK_MINUS_MINUS)
      {
         ++p->pos_;
         result = sl_expr_alloc_unop( exop_post_dec, &tk->situs_, &expr);
         if( ! result)
         {
            sl_expr_free( expr);
            return( parser_nomem( p));
         }
         expr = result;
         continue;
      }

      break;
   }

   *out = expr;
   return( 0);
}


static int   parse_unary_expression( struct glsl_es1_stack *p,
                                    struct sl_expr **out)
{
   struct pptk      *tk;
   struct sl_expr   *operand;
   struct sl_expr   *result;
   expr_op_t         op;
   int               r;

   tk = peek_token( p, 0);
   if( ! tk)
   {
      parser_syntax_error( p);
      return( _GLSL_ES1_SYNTAX_ERROR);
   }

   switch( tk->tok_)
   {
      case PPTK_PLUS_PLUS:
         ++p->pos_;
         r = parse_unary_expression( p, &operand);
         if( r)
            return( r);
         result = sl_expr_alloc_unop( exop_pre_inc, &tk->situs_, &operand);
         if( ! result)
         {
            sl_expr_free( operand);
            return( parser_nomem( p));
         }
         *out = result;
         return( 0);

      case PPTK_MINUS_MINUS:
         ++p->pos_;
         r = parse_unary_expression( p, &operand);
         if( r)
            return( r);
         result = sl_expr_alloc_unop( exop_pre_dec, &tk->situs_, &operand);
         if( ! result)
         {
            sl_expr_free( operand);
            return( parser_nomem( p));
         }
         *out = result;
         return( 0);

      case PPTK_PLUS:
         ++p->pos_;
         return( parse_unary_expression( p, out));

      case PPTK_MINUS:
         op = exop_negate;
         goto unary_op;

      case PPTK_BANG:
         op = exop_logical_not;
         goto unary_op;

      case PPTK_TILDE:
         dx_error_loc( p->cc_->dx_, &tk->situs_,
                       "bitwise-not is reserved in GLSL 1");
         ++p->pos_;
         return( parse_unary_expression( p, out));
   }

   return( parse_postfix_expression( p, out));

unary_op:
   ++p->pos_;
   r = parse_unary_expression( p, &operand);
   if( r)
      return( r);
   result = sl_expr_alloc_unop( op, &tk->situs_, &operand);
   if( ! result)
   {
      sl_expr_free( operand);
      return( parser_nomem( p));
   }
   *out = result;
   return( 0);
}


/*
 * Binary operators are parsed by precedence climbing. The precedence comes
 * from mulle-cpp-lexer for the active dialect; lower numbers bind tighter.
 * This keeps GLSL's ^^ in the right place without a second precedence table.
 */
struct glsl_binary_operator {
  enum pptoken tok_;
  expr_op_t eop_;
  const char *reserved_;
};

static const struct glsl_binary_operator glsl_binary_operators[] = {
  { PPTK_ASTERISK,            exop_multiply,    NULL },
  { PPTK_SLASH,               exop_divide,      NULL },
  { PPTK_PERCENT,             exop_invalid,     "modulo is reserved in GLSL 1" },
  { PPTK_PLUS,                exop_add,         NULL },
  { PPTK_MINUS,               exop_subtract,    NULL },
  { PPTK_LT_LT,               exop_invalid,     "left shift is reserved in GLSL 1" },
  { PPTK_GT_GT,               exop_invalid,     "right shift is reserved in GLSL 1" },
  { PPTK_LT,                  exop_lt,          NULL },
  { PPTK_GT,                  exop_gt,          NULL },
  { PPTK_LT_EQUALS,           exop_le,          NULL },
  { PPTK_GT_EQUALS,           exop_ge,          NULL },
  { PPTK_EQUALS_EQUALS,       exop_eq,          NULL },
  { PPTK_BANG_EQUALS,         exop_ne,          NULL },
  { PPTK_AMPERSAND,           exop_invalid,     "bitwise-and is reserved in GLSL 1" },
  { PPTK_CARET,               exop_invalid,     "bitwise-exclusive-or is reserved in GLSL 1" },
  { PPTK_BAR,                 exop_invalid,     "bitwise-or is reserved in GLSL 1" },
  { PPTK_AMPERSAND_AMPERSAND, exop_logical_and, NULL },
  { PPTK_CARET_CARET,         exop_logical_xor, NULL },
  { PPTK_BAR_BAR,             exop_logical_or,  NULL },
  { PPTK_INVALID,             exop_invalid,     NULL }
};

static const struct glsl_binary_operator *
   glsl_binary_operator_for( enum pptoken tok)
{
  const struct glsl_binary_operator   *op;

  for( op = glsl_binary_operators; op->tok_ != PPTK_INVALID; ++op)
    if( op->tok_ == tok)
      return( op);
  return( NULL);
}


#define GLSL_BINARY_MAX_PRECEDENCE 100


/* max_precedence is an exclusive upper bound: an operator with the same
 * precedence as the caller's operator is left for the caller, which makes
 * all of these operators left-associative.
 */
static int   parse_binary_expression( struct glsl_es1_stack *p,
                                     struct sl_expr **out,
                                     int max_precedence)
{
  struct sl_expr                     *lhs;
  struct sl_expr                     *rhs;
  struct sl_expr                     *result;
  struct pptk                        *tk;
  const struct glsl_binary_operator  *op;
  int                                 r;

  r = parse_unary_expression( p, &lhs);
  if( r)
    return( r);

  for(;;)
  {
    tk = peek_token( p, 0);
    if( ! tk)
      break;
    op = glsl_binary_operator_for( tk->tok_);
    if( ! op)
      break;
    if( tk->prec_ <= 0 || tk->prec_ >= max_precedence)
      break;

    ++p->pos_;
    r = parse_binary_expression( p, &rhs, tk->prec_);
    if( r)
    {
      sl_expr_free( lhs);
      return( r);
    }
    if( op->reserved_)
    {
      dx_error_loc( p->cc_->dx_, &tk->situs_, "%s", op->reserved_);
      sl_expr_free( rhs);
      continue;
    }
    result = sl_expr_alloc_binop( op->eop_, &tk->situs_, &lhs, &rhs);
    if( ! result)
    {
      sl_expr_free( lhs);
      sl_expr_free( rhs);
      return( parser_nomem( p));
    }
    lhs = result;
  }
  *out = lhs;
  return( 0);
}


static int   parse_conditional_expression( struct glsl_es1_stack *p,
                                          struct sl_expr **out)
{
   struct sl_expr   *condition;
   struct sl_expr   *true_expr;
   struct sl_expr   *false_expr;
   struct sl_expr   *result;
   struct pptk      *question;
   int               r;

   r = parse_binary_expression( p, &condition, GLSL_BINARY_MAX_PRECEDENCE);
   if( r)
      return( r);
   question = peek_token( p, 0);
   if( ! question || (question->tok_ != PPTK_QUESTION_MARK))
   {
      *out = condition;
      return( 0);
   }
   ++p->pos_;
   r = parse_expression( p, &true_expr);
   if( r)
   {
      sl_expr_free( condition);
      return( r);
   }
   r = expect_token( p, PPTK_COLON);
   if( r)
   {
      sl_expr_free( condition);
      sl_expr_free( true_expr);
      return( r);
   }
   r = parse_assignment_expression( p, &false_expr);
   if( r)
   {
      sl_expr_free( condition);
      sl_expr_free( true_expr);
      return( r);
   }
   result = sl_expr_alloc_ternop( exop_conditional, &question->situs_,
                                  &condition, &true_expr, &false_expr);
   if( ! result)
   {
      sl_expr_free( condition);
      sl_expr_free( true_expr);
      sl_expr_free( false_expr);
      return( parser_nomem( p));
   }
   *out = result;
   return( 0);
}


static int   parse_assignment_expression( struct glsl_es1_stack *p,
                                         struct sl_expr **out)
{
   struct sl_expr   *lhs;
   struct sl_expr   *rhs;
   struct sl_expr   *result;
   struct pptk      *op;
   expr_op_t         eop;
   int               reserved;
   int               r;

   r = parse_conditional_expression( p, &lhs);
   if( r)
      return( r);

   op = peek_token( p, 0);
   if( ! op)
   {
      *out = lhs;
      return( 0);
   }

   reserved = 0;
   switch( op->tok_)
   {
      case PPTK_EQUALS:             eop = exop_assign; break;
      case PPTK_ASTERISK_EQUALS:    eop = exop_mul_assign; break;
      case PPTK_SLASH_EQUALS:       eop = exop_div_assign; break;
      case PPTK_PLUS_EQUALS:        eop = exop_add_assign; break;
      case PPTK_MINUS_EQUALS:       eop = exop_sub_assign; break;
      case PPTK_PERCENT_EQUALS:
         reserved = 1;
         eop = exop_invalid;
         break;
      case PPTK_LT_LT_EQUALS:
         reserved = 1;
         eop = exop_invalid;
         break;
      case PPTK_GT_GT_EQUALS:
         reserved = 1;
         eop = exop_invalid;
         break;
      case PPTK_AMPERSAND_EQUALS:
         reserved = 1;
         eop = exop_invalid;
         break;
      case PPTK_CARET_EQUALS:
         reserved = 1;
         eop = exop_invalid;
         break;
      case PPTK_BAR_EQUALS:
         reserved = 1;
         eop = exop_invalid;
         break;
      default:
         *out = lhs;
         return( 0);
   }

   ++p->pos_;
   r = parse_assignment_expression( p, &rhs);
   if( r)
   {
      sl_expr_free( lhs);
      return( r);
   }

   if( reserved)
   {
      switch( op->tok_)
      {
         case PPTK_PERCENT_EQUALS:
            dx_error_loc( p->cc_->dx_, &op->situs_,
                          "modulo-assignment is reserved in GLSL 1");
            break;
         case PPTK_LT_LT_EQUALS:
            dx_error_loc( p->cc_->dx_, &op->situs_,
                          "left-shift-assignment is reserved in GLSL 1");
            break;
         case PPTK_GT_GT_EQUALS:
            dx_error_loc( p->cc_->dx_, &op->situs_,
                          "right-shift-assignment is reserved in GLSL 1");
            break;
         case PPTK_AMPERSAND_EQUALS:
            dx_error_loc( p->cc_->dx_, &op->situs_,
                          "bitwise-and-assignment is reserved in GLSL 1");
            break;
         case PPTK_CARET_EQUALS:
            dx_error_loc( p->cc_->dx_, &op->situs_,
                          "bitwise-xor-assignment is reserved in GLSL 1");
            break;
         case PPTK_BAR_EQUALS:
            dx_error_loc( p->cc_->dx_, &op->situs_,
                          "bitwise-or-assignment is reserved in GLSL 1");
            break;
      }
      sl_expr_free( rhs);
      *out = lhs;
      return( 0);
   }

   result = sl_expr_alloc_binop( eop, &op->situs_, &lhs, &rhs);
   if( ! result)
   {
      sl_expr_free( lhs);
      sl_expr_free( rhs);
      return( parser_nomem( p));
   }
   *out = result;
   return( 0);
}


static int   parse_expression( struct glsl_es1_stack *p,
                              struct sl_expr **out)
{
   struct sl_expr   *lhs;
   struct sl_expr   *rhs;
   struct sl_expr   *result;
   struct pptk      *op;
   int               r;

   r = parse_assignment_expression( p, &lhs);
   if( r)
      return( r);
   while( (op = peek_token( p, 0)) && (op->tok_ == PPTK_COMMA))
   {
      ++p->pos_;
      r = parse_assignment_expression( p, &rhs);
      if( r)
      {
         sl_expr_free( lhs);
         return( r);
      }
      result = sl_expr_alloc_binop( exop_sequence, &op->situs_, &lhs, &rhs);
      if( ! result)
      {
         sl_expr_free( lhs);
         sl_expr_free( rhs);
         return( parser_nomem( p));
      }
      lhs = result;
   }
   *out = lhs;
   return( 0);
}


static int   parse_constant_expression( struct glsl_es1_stack *p,
                                       struct sl_expr **out)
{
   struct sl_expr   *expr;
   int               validation;
   int               r;

   r = parse_conditional_expression( p, &expr);
   if( r)
      return( r);
   if( ! expr)
   {
      *out = NULL;
      return( 0);
   }
   validation = sl_expr_validate( p->cc_->dx_, p->cc_->tb_, expr);
   if( validation & SLXV_INVALID)
   {
      sl_expr_free( expr);
      *out = NULL;
      return( 0);
   }
   if( validation & SLXV_NOT_CONSTANT)
   {
      dx_error_loc( p->cc_->dx_, &expr->op_loc_,
                    "Error: expression is not constant");
   }
   *out = expr;
   return( 0);
}


static int   parse_condition( struct glsl_es1_stack *p,
                             struct condition_value *out)
{
   struct sl_type      *type;
   struct pptk         *name_tk;
   struct sl_expr      *initializer;
   struct sl_expr      *condition;
   struct sl_variable  *var;
   struct sl_stmt      *stmt;
   int                  r;

   out->initializer_ = NULL;
   out->condition_ = NULL;

   if( token_starts_type( p))
   {
      r = parse_fully_specified_type( p, &type);
      if( r)
         return( r);
      name_tk = peek_token( p, 0);
      if( ! name_tk || (name_tk->tok_ != PPTK_IDENT))
      {
         parser_syntax_error( p);
         return( _GLSL_ES1_SYNTAX_ERROR);
      }
      ++p->pos_;
      r = expect_token( p, PPTK_EQUALS);
      if( r)
         return( r);
      r = parse_assignment_expression( p, &initializer);
      if( r)
         return( r);

      var = NULL;
      r = glsl_es1_declare_variable( p->cc_, name_tk->text_,
                                     &name_tk->situs_, type, &var);
      if( r)
      {
         sl_expr_free( initializer);
         return( r);
      }
      stmt = NULL;
      if( initializer)
         r = glsl_es1_process_initializer( p->cc_, var, &initializer,
                                           &initializer->op_loc_, &name_tk->situs_,
                                           &stmt);
      else
         r = 0;
      if( r)
      {
         sl_expr_free( initializer);
         sl_stmt_free_list( stmt);
         return( r);
      }
      sl_expr_free( initializer);
      condition = sl_expr_alloc_variable( var, &name_tk->situs_);
      if( ! condition)
      {
         sl_stmt_free_list( stmt);
         return( parser_nomem( p));
      }
      out->initializer_ = stmt;
      out->condition_ = condition;
      return( 0);
   }

   return( parse_expression( p, &out->condition_));
}


static int   parse_expression_statement( struct glsl_es1_stack *p,
                                        struct sl_stmt **out)
{
   struct sl_expr   *expr;
   struct sl_stmt   *stmt;
   int               validation;
   int               r;

   if( accept_token( p, PPTK_SEMICOLON))
   {
      stmt = sl_stmt_alloc();
      if( ! stmt)
         return( parser_nomem( p));
      stmt->kind_ = slsk_expression;
      stmt->expr_ = NULL;
      *out = stmt;
      return( 0);
   }

   r = parse_expression( p, &expr);
   if( r)
      return( r);
   r = expect_token( p, PPTK_SEMICOLON);
   if( r)
   {
      sl_expr_free( expr);
      return( r);
   }
   if( ! expr)
   {
      *out = NULL;
      return( 0);
   }
   validation = sl_expr_validate( p->cc_->dx_, p->cc_->tb_, expr);
   if( validation & SLXV_INVALID)
   {
      sl_expr_free( expr);
      *out = NULL;
      return( 0);
   }
   stmt = sl_stmt_alloc();
   if( ! stmt)
   {
      sl_expr_free( expr);
      return( parser_nomem( p));
   }
   stmt->kind_ = slsk_expression;
   stmt->expr_ = expr;
   *out = stmt;
   return( 0);
}


static struct sym_table   *push_scope( struct glsl_es1_stack *p)
{
   struct sym_table   *st;

   st = (struct sym_table *) malloc( sizeof( struct sym_table));
   if( ! st)
   {
      parser_nomem( p);
      return( NULL);
   }
   aex_st_init( st, p->cc_->current_scope_);
   p->cc_->current_scope_ = st;
   return( st);
}


static void   pop_scope( struct glsl_es1_stack *p, struct sym_table *st)
{
   p->cc_->current_scope_ = st->parent_;
}


static struct sl_stmt   *compound_with_scope( struct sym_table *st,
                                              struct sl_stmt *list)
{
   struct sl_stmt   *stmt;

   stmt = sl_stmt_alloc();
   if( ! stmt)
      return( NULL);
   stmt->kind_ = slsk_compound;
   stmt->scope_ = st;
   stmt->true_branch_ = list;
   sl_stmt_set_list_parent( list, stmt);
   return( stmt);
}


static int   parse_compound_statement( struct glsl_es1_stack *p,
                                      int with_scope,
                                      struct sl_stmt **out)
{
   struct sym_table   *st;
   struct sl_stmt     *list;
   struct sl_stmt     *stmt;
   struct sl_stmt     *compound;
   int                 r;

   r = expect_token( p, PPTK_CUBRACE_OPEN);
   if( r)
      return( r);

   if( with_scope && token_is( p, PPTK_CUBRACE_CLOSE))
   {
      ++p->pos_;
      *out = NULL;
      return( 0);
   }

   st = NULL;
   if( with_scope)
   {
      st = push_scope( p);
      if( ! st)
         return( _GLSL_ES1_NO_MEMORY);
   }

   list = NULL;
   while( ! token_is( p, PPTK_CUBRACE_CLOSE))
   {
      if( ! peek_token( p, 0))
      {
         parser_syntax_error( p);
         r = _GLSL_ES1_SYNTAX_ERROR;
         goto error;
      }
      r = parse_statement_no_new_scope( p, &stmt);
      if( r)
         goto error;
      if( ! stmt)
         continue;
      list = list ? sl_stmt_append_list( list, stmt) : stmt;
   }

   r = expect_token( p, PPTK_CUBRACE_CLOSE);
   if( r)
      goto error;

   if( with_scope)
   {
      compound = compound_with_scope( st, list);
      if( ! compound)
      {
         r = parser_nomem( p);
         goto error;
      }
      pop_scope( p, st);
      *out = compound;
      return( 0);
   }

   *out = list;
   return( 0);

error:
   if( with_scope)
   {
      pop_scope( p, st);
      aex_st_cleanup( st);
      free( st);
   }
   sl_stmt_free_list( list);
   return( r);
}


static int   parse_statement_with_scope( struct glsl_es1_stack *p,
                                        struct sl_stmt **out)
{
   struct sym_table   *st;
   struct sl_stmt     *stmt;
   struct sl_stmt     *compound;
   int                 r;

   st = push_scope( p);
   if( ! st)
      return( _GLSL_ES1_NO_MEMORY);
   if( token_is( p, PPTK_CUBRACE_OPEN))
      r = parse_compound_statement( p, 0, &stmt);
   else
      r = parse_statement_no_new_scope( p, &stmt);
   if( r)
   {
      pop_scope( p, st);
      aex_st_cleanup( st);
      free( st);
      sl_stmt_free_list( stmt);
      return( r);
   }
   pop_scope( p, st);
   compound = compound_with_scope( st, stmt);
   if( ! compound)
   {
      aex_st_cleanup( st);
      free( st);
      sl_stmt_free_list( stmt);
      return( parser_nomem( p));
   }
   *out = compound;
   return( 0);
}


static int   parse_jump_statement( struct glsl_es1_stack *p,
                                  struct sl_stmt **out)
{
   struct pptk      *tk;
   struct sl_expr   *expr;
   struct sl_stmt   *stmt;
   sl_stmt_kind_t    kind;
   int               r;

   tk = advance_token( p);
   expr = NULL;

   switch( tk->tok_)
   {
      case PPTK_BREAK:
         kind = slsk_break;
         if( ! p->loop_depth_)
            dx_error_loc( p->cc_->dx_, &tk->situs_,
                          "break statement outside of a loop");
         break;
      case PPTK_CONTINUE:
         kind = slsk_continue;
         if( ! p->loop_depth_)
            dx_error_loc( p->cc_->dx_, &tk->situs_,
                          "continue statement outside of a loop");
         break;
      case PPTK_DISCARD:
         kind = slsk_discard;
         if( p->cc_->shader_is_vertex_)
            dx_error_loc( p->cc_->dx_, &tk->situs_,
                          "discard statement is only allowed in fragment shaders");
         break;
      case PPTK_RETURN:
         kind = slsk_return;
         if( ! token_is( p, PPTK_SEMICOLON))
         {
            r = parse_expression( p, &expr);
            if( r)
               return( r);
         }
         if( p->current_return_type_)
         {
            int is_void = (sl_type_unqualified( p->current_return_type_)->kind_ == sltk_void);
            if( is_void && expr)
               dx_error_loc( p->cc_->dx_, &tk->situs_,
                             "void function cannot return a value");
            else if( ! is_void && ! expr)
               dx_error_loc( p->cc_->dx_, &tk->situs_,
                             "non-void function must return a value");
         }
         break;
      default:
         parser_syntax_error( p);
         return( _GLSL_ES1_SYNTAX_ERROR);
   }

   r = expect_token( p, PPTK_SEMICOLON);
   if( r)
   {
      sl_expr_free( expr);
      return( r);
   }
   stmt = sl_stmt_alloc();
   if( ! stmt)
   {
      sl_expr_free( expr);
      return( parser_nomem( p));
   }
   stmt->kind_ = kind;
   stmt->expr_ = expr;
   if( aex_situs_clone( &stmt->keyword_loc_, &tk->situs_))
   {
      sl_stmt_free( stmt);
      return( parser_nomem( p));
   }
   *out = stmt;
   return( 0);
}


static int   parse_selection_statement( struct glsl_es1_stack *p,
                                       struct sl_stmt **out)
{
   struct pptk      *if_tk;
   struct sl_expr   *condition;
   struct sl_stmt   *true_branch;
   struct sl_stmt   *false_branch;
   struct sl_stmt   *stmt;
   int               r;

   if_tk = advance_token( p);
   r = expect_token( p, PPTK_PAR_OPEN);
   if( r)
      return( r);
   r = parse_expression( p, &condition);
   if( r)
      return( r);
   r = expect_token( p, PPTK_PAR_CLOSE);
   if( r)
   {
      sl_expr_free( condition);
      return( r);
   }
   r = parse_statement_with_scope( p, &true_branch);
   if( r)
   {
      sl_expr_free( condition);
      return( r);
   }
   false_branch = NULL;
   if( accept_token( p, PPTK_ELSE))
   {
      r = parse_statement_with_scope( p, &false_branch);
      if( r)
      {
         sl_expr_free( condition);
         sl_stmt_free_list( true_branch);
         return( r);
      }
   }
   stmt = sl_stmt_alloc();
   if( ! stmt)
   {
      sl_expr_free( condition);
      sl_stmt_free_list( true_branch);
      sl_stmt_free_list( false_branch);
      return( parser_nomem( p));
   }
   stmt->kind_ = slsk_if;
   stmt->condition_ = condition;
   stmt->true_branch_ = true_branch;
   stmt->false_branch_ = false_branch;
   sl_stmt_set_list_parent( true_branch, stmt);
   sl_stmt_set_list_parent( false_branch, stmt);
   if( aex_situs_clone( &stmt->keyword_loc_, &if_tk->situs_))
   {
      sl_stmt_free( stmt);
      return( parser_nomem( p));
   }
   *out = stmt;
   return( 0);
}


static int   parse_while_statement( struct glsl_es1_stack *p,
                                   struct sl_stmt **out)
{
   struct pptk             *while_tk;
   struct sym_table        *st;
   struct condition_value   cv;
   struct sl_stmt          *body;
   struct sl_stmt          *stmt;
   int                      r;

   while_tk = advance_token( p);
   st = push_scope( p);
   if( ! st)
      return( _GLSL_ES1_NO_MEMORY);

   r = expect_token( p, PPTK_PAR_OPEN);
   if( r)
      goto error;
   r = parse_condition( p, &cv);
   if( r)
      goto error;
   r = expect_token( p, PPTK_PAR_CLOSE);
   if( r)
      goto error_condition;
   ++p->loop_depth_;
   r = parse_statement_no_new_scope( p, &body);
   --p->loop_depth_;
   if( r)
      goto error_condition;

   pop_scope( p, st);
   stmt = sl_stmt_alloc();
   if( ! stmt)
   {
      sl_expr_free( cv.condition_);
      sl_stmt_free_list( cv.initializer_);
      sl_stmt_free_list( body);
      aex_st_cleanup( st);
      free( st);
      return( parser_nomem( p));
   }
   stmt->kind_ = slsk_while;
   stmt->scope_ = st;
   stmt->condition_ = cv.condition_;
   stmt->prep_cond_ = cv.initializer_;
   stmt->true_branch_ = body;
   sl_stmt_set_list_parent( cv.initializer_, stmt);
   sl_stmt_set_list_parent( body, stmt);
   if( aex_situs_clone( &stmt->keyword_loc_, &while_tk->situs_))
   {
      sl_stmt_free( stmt);
      return( parser_nomem( p));
   }
   *out = stmt;
   return( 0);

error_condition:
   sl_expr_free( cv.condition_);
   sl_stmt_free_list( cv.initializer_);
error:
   pop_scope( p, st);
   aex_st_cleanup( st);
   free( st);
   return( r);
}


static int   parse_do_statement( struct glsl_es1_stack *p,
                                struct sl_stmt **out)
{
   struct pptk      *do_tk;
   struct pptk      *while_tk;
   struct sl_stmt   *body;
   struct sl_expr   *condition;
   struct sl_stmt   *stmt;
   int               r;

   do_tk = advance_token( p);
   ++p->loop_depth_;
   r = parse_statement_with_scope( p, &body);
   --p->loop_depth_;
   if( r)
      return( r);
   while_tk = peek_token( p, 0);
   if( ! while_tk || (while_tk->tok_ != PPTK_WHILE))
   {
      sl_stmt_free_list( body);
      parser_syntax_error( p);
      return( _GLSL_ES1_SYNTAX_ERROR);
   }
   ++p->pos_;
   r = expect_token( p, PPTK_PAR_OPEN);
   if( r)
   {
      sl_stmt_free_list( body);
      return( r);
   }
   r = parse_expression( p, &condition);
   if( r)
   {
      sl_stmt_free_list( body);
      return( r);
   }
   r = expect_token( p, PPTK_PAR_CLOSE);
   if( r)
   {
      sl_stmt_free_list( body);
      sl_expr_free( condition);
      return( r);
   }
   r = expect_token( p, PPTK_SEMICOLON);
   if( r)
   {
      sl_stmt_free_list( body);
      sl_expr_free( condition);
      return( r);
   }
   stmt = sl_stmt_alloc();
   if( ! stmt)
   {
      sl_stmt_free_list( body);
      sl_expr_free( condition);
      return( parser_nomem( p));
   }
   stmt->kind_ = slsk_do;
   stmt->condition_ = condition;
   stmt->true_branch_ = body;
   sl_stmt_set_list_parent( body, stmt);
   if( aex_situs_clone( &stmt->keyword_loc_, &do_tk->situs_))
   {
      sl_stmt_free( stmt);
      return( parser_nomem( p));
   }
   *out = stmt;
   return( 0);
}


static int   parse_for_statement( struct glsl_es1_stack *p,
                                 struct sl_stmt **out)
{
   struct pptk             *for_tk;
   struct sym_table        *st;
   struct sl_stmt          *init;
   struct sl_stmt          *body;
   struct condition_value   cv;
   struct sl_expr          *post;
   struct sl_stmt          *stmt;
   int                      r;

   for_tk = advance_token( p);
   st = push_scope( p);
   if( ! st)
      return( _GLSL_ES1_NO_MEMORY);

   r = expect_token( p, PPTK_PAR_OPEN);
   if( r)
      goto error;

   init = NULL;
   if( token_is( p, PPTK_SEMICOLON))
   {
      ++p->pos_;
   }
   else if( token_starts_type( p))
   {
      r = parse_declaration( p, &init);
      if( r)
         goto error;
   }
   else
   {
      r = parse_expression_statement( p, &init);
      if( r)
         goto error;
   }

   cv.initializer_ = NULL;
   cv.condition_ = NULL;
   post = NULL;

   if( token_is( p, PPTK_SEMICOLON))
   {
      ++p->pos_;
   }
   else
   {
      r = parse_condition( p, &cv);
      if( r)
         goto error_init;
      r = expect_token( p, PPTK_SEMICOLON);
      if( r)
         goto error_condition;
   }

   if( ! token_is( p, PPTK_PAR_CLOSE))
   {
      r = parse_expression( p, &post);
      if( r)
         goto error_condition;
   }

   r = expect_token( p, PPTK_PAR_CLOSE);
   if( r)
      goto error_post;

   ++p->loop_depth_;
   r = parse_statement_no_new_scope( p, &body);
   --p->loop_depth_;
   if( r)
      goto error_post;

   pop_scope( p, st);
   stmt = sl_stmt_alloc();
   if( ! stmt)
   {
      sl_stmt_free_list( init);
      sl_stmt_free_list( cv.initializer_);
      sl_expr_free( cv.condition_);
      sl_expr_free( post);
      sl_stmt_free_list( body);
      aex_st_cleanup( st);
      free( st);
      return( parser_nomem( p));
   }
   stmt->kind_ = slsk_for;
   stmt->scope_ = st;
   stmt->prep_ = init;
   stmt->prep_cond_ = cv.initializer_;
   stmt->condition_ = cv.condition_;
   stmt->post_ = post;
   stmt->true_branch_ = body;
   sl_stmt_set_list_parent( init, stmt);
   sl_stmt_set_list_parent( cv.initializer_, stmt);
   sl_stmt_set_list_parent( body, stmt);
   if( aex_situs_clone( &stmt->keyword_loc_, &for_tk->situs_))
   {
      sl_stmt_free( stmt);
      return( parser_nomem( p));
   }
   *out = stmt;
   return( 0);

error_post:
   sl_expr_free( post);
error_condition:
   sl_expr_free( cv.condition_);
   sl_stmt_free_list( cv.initializer_);
error_init:
   sl_stmt_free_list( init);
error:
   pop_scope( p, st);
   aex_st_cleanup( st);
   free( st);
   return( r);
}


static int   parse_statement_no_new_scope( struct glsl_es1_stack *p,
                                          struct sl_stmt **out)
{
   struct pptk   *tk;

   tk = peek_token( p, 0);
   if( ! tk)
   {
      parser_syntax_error( p);
      return( _GLSL_ES1_SYNTAX_ERROR);
   }

   if( tk->tok_ == PPTK_CUBRACE_OPEN)
      return( parse_compound_statement( p, 1, out));

   if( token_starts_type( p))
      return( parse_declaration( p, out));

   switch( tk->tok_)
   {
      case PPTK_IF:       return( parse_selection_statement( p, out));
      case PPTK_WHILE:    return( parse_while_statement( p, out));
      case PPTK_DO:       return( parse_do_statement( p, out));
      case PPTK_FOR:      return( parse_for_statement( p, out));
      case PPTK_BREAK:
      case PPTK_CONTINUE:
      case PPTK_RETURN:
      case PPTK_DISCARD:  return( parse_jump_statement( p, out));
   }

   return( parse_expression_statement( p, out));
}


static int   type_is_float_precision_kind( struct sl_type *t)
{
   t = sl_type_unqualified( t);
   if( ! t)
      return( 0);

   switch( t->kind_)
   {
      case sltk_float:
      case sltk_vec2:
      case sltk_vec3:
      case sltk_vec4:
      case sltk_mat2:
      case sltk_mat3:
      case sltk_mat4:
         return( 1);
      default:
         return( 0);
   }
}


static int   type_requires_float_precision( struct sl_type *t)
{
   int   qualifiers;

   while( t && (t->kind_ == sltk_array))
      t = t->derived_type_;
   if( ! t)
      return( 0);

   qualifiers = sl_type_qualifiers( t);
   if( qualifiers & (SL_TYPE_QUALIFIER_HIGH_PRECISION |
                     SL_TYPE_QUALIFIER_MEDIUM_PRECISION |
                     SL_TYPE_QUALIFIER_LOW_PRECISION))
      return( 0);

   return( type_is_float_precision_kind( t));
}


static int   parse_init_declarator_list( struct glsl_es1_stack *p,
                                         struct sl_type *base_type,
                                         struct sl_stmt **out)
{
   struct sl_stmt      *list;
   struct sl_stmt      *stmt;
   struct pptk         *name_tk;
   struct sl_type      *type;
   struct sl_type      *array_type;
   struct sl_expr      *size_expr;
   struct sl_expr      *initializer;
   struct sl_variable  *var;
   struct situs         equal_loc;
   int                  have_initializer;
   int                  r;

   list = NULL;

   if( ! token_is( p, PPTK_IDENT))
   {
      *out = NULL;
      return( 0);
   }

   for(;;)
   {
      name_tk = advance_token( p);
      type = base_type;

      if( accept_token( p, PPTK_SQBRACE_OPEN))
      {
         r = parse_constant_expression( p, &size_expr);
         if( r)
            goto error;
         r = expect_token( p, PPTK_SQBRACE_CLOSE);
         if( r)
         {
            sl_expr_free( size_expr);
            goto error;
         }
         array_type = NULL;
         r = glsl_es1_build_array_type( p->cc_->dx_, p->cc_->tb_, base_type,
                                        size_expr, &name_tk->situs_, &array_type);
         sl_expr_free( size_expr);
         if( r)
            goto error;
         if( array_type)
            type = array_type;
      }

      if( p->cc_->shader_is_fragment_ &&
          ! p->cc_->fragment_default_float_precision_ &&
          type_requires_float_precision( type))
         dx_error_loc( p->cc_->dx_, &name_tk->situs_,
                       "No precision specified for \"%s\"; declare a default float precision or use a precision qualifier",
                       name_tk->text_);

      have_initializer = 0;
      initializer = NULL;
      aex_situs_init( &equal_loc);
      if( accept_token( p, PPTK_EQUALS))
      {
         have_initializer = 1;
         if( aex_situs_clone( &equal_loc, &p->tokens_[ p->pos_ - 1]->situs_))
         {
            r = parser_nomem( p);
            goto error;
         }
         r = parse_assignment_expression( p, &initializer);
         if( r)
         {
            aex_situs_cleanup( &equal_loc);
            goto error;
         }
      }

      var = NULL;
      r = glsl_es1_declare_variable( p->cc_, name_tk->text_,
                                     &name_tk->situs_, type, &var);
      if( r)
      {
         sl_expr_free( initializer);
         aex_situs_cleanup( &equal_loc);
         goto error;
      }

      if( have_initializer && initializer)
      {
         stmt = NULL;
         r = glsl_es1_process_initializer( p->cc_, var, &initializer,
                                           &initializer->op_loc_, &equal_loc,
                                           &stmt);
         if( r)
         {
            sl_expr_free( initializer);
            aex_situs_cleanup( &equal_loc);
            goto error;
         }
         sl_expr_free( initializer);
         if( stmt)
            list = list ? sl_stmt_append_list( list, stmt) : stmt;
      }
      aex_situs_cleanup( &equal_loc);

      if( ! accept_token( p, PPTK_COMMA))
         break;
   }

   *out = list;
   return( 0);

error:
   sl_stmt_free_list( list);
   return( r);
}


static int   stmt_list_may_fall_through( struct sl_stmt *s);

static int   stmt_may_fall_through( struct sl_stmt *s)
{
   if( ! s)
      return( 1);

   switch( s->kind_)
   {
      case slsk_return:
      case slsk_discard:
      case slsk_break:
      case slsk_continue:
         return( 0);

      case slsk_compound:
         return( stmt_list_may_fall_through( s->true_branch_));

      case slsk_if:
         if( ! s->false_branch_)
            return( 1);
         return( stmt_may_fall_through( s->true_branch_) ||
                 stmt_may_fall_through( s->false_branch_));

      /* Loops may be infinite. Claiming they fall through would reject valid
       * shaders such as "while (1) return x;", so stay conservative. */
      case slsk_while:
      case slsk_for:
      case slsk_do:
         return( 0);

      default:
         return( 1);
   }
}


static int   stmt_list_may_fall_through( struct sl_stmt *s)
{
   struct sl_stmt   *head;

   if( ! s)
      return( 1);

   head = s;
   do
   {
      if( ! stmt_may_fall_through( s))
         return( 0);
      s = s->next_;
   }
   while( s && (s != head));
   return( 1);
}


static int   parse_function( struct glsl_es1_stack *p,
                            struct sl_type *return_type,
                            struct pptk *name_tk)
{
   struct sl_function   *f;
   struct sl_function   *f_keep;
   struct sl_stmt       *body;
   struct sl_stmt       *compound;
   int                   is_definition;
   int                   r;

   f = sl_frame_alloc_function( name_tk->text_, &name_tk->situs_, return_type);
   if( ! f)
      return( parser_nomem( p));
   p->cc_->current_function_prototype_ = f;

   r = expect_token( p, PPTK_PAR_OPEN);
   if( r)
      goto error;

   if( ! token_is( p, PPTK_PAR_CLOSE))
   {
      for(;;)
      {
         r = parse_parameter_declaration( p);
         if( r)
            goto error;
         if( ! accept_token( p, PPTK_COMMA))
            break;
      }
   }
   r = expect_token( p, PPTK_PAR_CLOSE);
   if( r)
      goto error;

   if( sl_function_post_process_parameters( p->cc_->tb_, f))
   {
      p->cc_->current_function_prototype_ = NULL;
      sl_frame_free_function( f);
      return( parser_nomem( p));
   }
   p->cc_->current_function_prototype_ = NULL;
   f_keep = f;

   is_definition = token_is( p, PPTK_CUBRACE_OPEN);
   if( is_definition)
   {
      r = glsl_es1_process_function_prototype( p->cc_, &f, 1);
   }
   else
   {
      r = glsl_es1_process_function_prototype( p->cc_, &f, 0);
   }
   if( r == _GLSL_ES1_NO_MEMORY)
      return( r);

   if( r)
   {
      if( f)
         sl_frame_free_function( f);
      f = NULL;
      f_keep = NULL;
   }

   if( ! is_definition)
   {
      r = expect_token( p, PPTK_SEMICOLON);
      if( r)
         return( r);
      return( 0);
   }

   /* Function definition: the body scope is the parameter scope created by
    * glsl_es1_process_function_prototype(is_definition = 1). */
   {
      struct sl_type *saved_return_type = p->current_return_type_;
      if( f_keep)
         p->current_return_type_ = f_keep->return_type_;
      r = parse_compound_statement( p, 0, &body);
      p->current_return_type_ = saved_return_type;
   }
   if( r)
   {
      if( f_keep && f_keep->body_ && f_keep->body_->scope_)
         p->cc_->current_scope_ = f_keep->body_->scope_->parent_;
      p->cc_->current_frame_ = &p->cc_->cu_->global_frame_;
      return( r);
   }
   if( f_keep && f_keep->body_)
   {
      struct sl_type   *rt;

      sl_stmt_set_list_parent( body, f_keep->body_);
      f_keep->body_->true_branch_ = sl_stmt_append_list( f_keep->body_->true_branch_, body);

      rt = sl_type_unqualified( f_keep->return_type_);
      if( rt && (rt->kind_ != sltk_void) &&
          stmt_list_may_fall_through( body))
         dx_error_loc( p->cc_->dx_, &f_keep->location_,
                       "Function \"%s\" may reach the end without returning a value",
                       f_keep->name_);
   }
   if( f_keep && f_keep->body_ && f_keep->body_->scope_)
      p->cc_->current_scope_ = f_keep->body_->scope_->parent_;
   p->cc_->current_frame_ = &p->cc_->cu_->global_frame_;
   return( 0);

error:
   p->cc_->current_function_prototype_ = NULL;
   if( f)
      sl_frame_free_function( f);
   return( r);
}


static int   parse_declaration( struct glsl_es1_stack *p,
                                struct sl_stmt **out)
{
   struct pptk        *tk;
   struct pptk        *name_tk;
   struct sl_type     *type;
   struct sl_stmt     *list;
   int                 precision;
   int                 r;

   *out = NULL;

   tk = peek_token( p, 0);
   if( ! tk)
   {
      parser_syntax_error( p);
      return( _GLSL_ES1_SYNTAX_ERROR);
   }

   if( tk->tok_ == PPTK_PRECISION)
   {
      ++p->pos_;
      precision = 0;
      if( ! parse_precision_qualifier( p, &precision))
      {
         parser_syntax_error( p);
         return( _GLSL_ES1_SYNTAX_ERROR);
      }
      r = parse_type_specifier_no_prec( p, &type);
      if( r)
         return( r);
      if( p->cc_->shader_is_fragment_ && precision &&
          type_is_float_precision_kind( type))
         p->cc_->fragment_default_float_precision_ = 1;
      if( precision)
      {
         type = sl_type_base_qualified_type( p->cc_->tb_, type, precision);
         if( ! type)
            return( parser_nomem( p));
      }
      return( expect_token( p, PPTK_SEMICOLON));
   }

   if( tk->tok_ == PPTK_INVARIANT)
   {
      struct pptk   *next;

      next = peek_token( p, 1);
      if( ! next || (next->tok_ != PPTK_VARYING))
      {
         ++p->pos_;
         name_tk = peek_token( p, 0);
         if( ! name_tk || (name_tk->tok_ != PPTK_IDENT))
         {
            parser_syntax_error( p);
            return( _GLSL_ES1_SYNTAX_ERROR);
         }
         ++p->pos_;
         return( expect_token( p, PPTK_SEMICOLON));
      }
   }

   r = parse_fully_specified_type( p, &type);
   if( r)
      return( r);

   name_tk = peek_token( p, 0);
   if( name_tk && (name_tk->tok_ == PPTK_IDENT) &&
       peek_token( p, 1) && (peek_token( p, 1)->tok_ == PPTK_PAR_OPEN))
   {
      ++p->pos_;
      return( parse_function( p, type, name_tk));
   }

   r = parse_init_declarator_list( p, type, &list);
   if( r)
      return( r);
   r = expect_token( p, PPTK_SEMICOLON);
   if( r)
   {
      sl_stmt_free_list( list);
      return( r);
   }
   *out = list;
   return( 0);
}


static int   parse_external_declaration( struct glsl_es1_stack *p)
{
   struct sl_stmt   *stmt;
   int               r;

   r = parse_declaration( p, &stmt);
   if( r)
      return( r);
   /* Global initializers are handled at compile time and do not generate
    * executable statements. */
   sl_stmt_free_list( stmt);
   return( 0);
}


void   glsl_es1_stack_init( struct glsl_es1_stack *stack)
{
   memset( stack, 0, sizeof( *stack));
}


static void   glsl_es1_stack_free_tokens( struct glsl_es1_stack *stack)
{
   size_t   n;
   size_t   count;

   count = stack->count_;
   for( n = 0; n < count; ++n)
      aex_pptk_free( stack->tokens_[ n]);
   free( stack->tokens_);
   stack->tokens_ = NULL;
   stack->count_ = 0;
   stack->allocated_ = 0;
   stack->pos_ = 0;
}


void   glsl_es1_stack_cleanup( struct glsl_es1_stack *stack)
{
   glsl_es1_stack_free_tokens( stack);
}


int   glsl_es1_stack_reset( struct glsl_es1_stack *stack)
{
   glsl_es1_stack_free_tokens( stack);
   stack->cc_ = NULL;
   stack->failed_ = 0;
   stack->result_ = 0;
   return( 0);
}


int   glsl_es1_parser_push( struct glsl_es1_stack *stack,
                            struct glsl_es1_compiler *cc,
                            struct pptk *token)
{
   if( stack->count_ == stack->allocated_)
   {
      size_t          new_allocated;
      struct pptk   **new_tokens;

      new_allocated = stack->allocated_ + stack->allocated_ + 16;
      new_tokens = (struct pptk **) realloc( stack->tokens_,
                                             new_allocated * sizeof( *new_tokens));
      if( ! new_tokens)
      {
         dx_no_memory( cc->dx_);
         return( _GLSL_ES1_NO_MEMORY);
      }
      stack->tokens_ = new_tokens;
      stack->allocated_ = new_allocated;
   }
   stack->cc_ = cc;
   stack->tokens_[ stack->count_++] = token;
   return( 0);
}


int   glsl_es1_parser_finish( struct glsl_es1_stack *stack,
                              struct glsl_es1_compiler *cc)
{
   stack->cc_ = cc;
   stack->pos_ = 0;
   stack->failed_ = 0;
   stack->result_ = _GLSL_ES1_FINISH;
   stack->loop_depth_ = 0;
   stack->current_return_type_ = NULL;

   while( (stack->pos_ < stack->count_) && ! stack->failed_)
   {
      if( parse_external_declaration( stack))
         break;
   }

   glsl_es1_stack_free_tokens( stack);
   return( stack->failed_ ? stack->result_ : _GLSL_ES1_FINISH);
}
