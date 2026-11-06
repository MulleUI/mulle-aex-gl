/* Copyright 2020-2024 Kinglet B.V.
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

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <mulle-cpp-engine/mulle-cpp-engine.h>

#include "pp.h"
#include "pp_input_file.h"
#include "pp_tokens.h"

static void pp_diagnostic_callback(void *baton, const char *file, size_t line,
                                   size_t column, int severity,
                                   const char *message) {
  struct preprocessor *pp;
  struct situs sit;

  pp = (struct preprocessor *) baton;
  aex_situs_init(&sit);
  sit.num_spans_ = 1;
  sit.u_.one_.filename_ = file ? file : "";
  sit.u_.one_.start_line_ = sit.u_.one_.end_line_ = (int) line;
  sit.u_.one_.start_col_ = sit.u_.one_.end_col_ = (int) (column ? column : 1);
  sit.u_.one_.num_bytes_ = 0;

  if (severity > 1) {
    dx_error_loc(pp->dx_, &sit, "%s", message);
  }
  else {
    dx_warn_loc(pp->dx_, &sit, "%s", message);
  }
}

struct pp_keyword {
  const char *name_;
  enum pptoken token_;
};

static const struct pp_keyword pp_keywords[] = {
  { "attribute", PPTK_ATTRIBUTE },
  { "const", PPTK_CONST },
  { "bool", PPTK_BOOL_ID },
  { "float", PPTK_FLOAT },
  { "int", PPTK_INT },
  { "break", PPTK_BREAK },
  { "continue", PPTK_CONTINUE },
  { "do", PPTK_DO },
  { "else", PPTK_ELSE },
  { "for", PPTK_FOR },
  { "if", PPTK_IF },
  { "discard", PPTK_DISCARD },
  { "return", PPTK_RETURN },
  { "in", PPTK_IN },
  { "out", PPTK_OUT },
  { "inout", PPTK_INOUT },
  { "uniform", PPTK_UNIFORM },
  { "varying", PPTK_VARYING },
  { "sampler2D", PPTK_SAMPLER2D },
  { "samplerCube", PPTK_SAMPLERCUBE },
  { "struct", PPTK_STRUCT },
  { "void", PPTK_VOID },
  { "while", PPTK_WHILE },
  { "precision", PPTK_PRECISION },
  { "highp", PPTK_HIGH_PRECISION },
  { "mediump", PPTK_MEDIUM_PRECISION },
  { "lowp", PPTK_LOW_PRECISION },
  { "invariant", PPTK_INVARIANT },
  { "bvec2", PPTK_BVEC2 },
  { "bvec3", PPTK_BVEC3 },
  { "bvec4", PPTK_BVEC4 },
  { "ivec2", PPTK_IVEC2 },
  { "ivec3", PPTK_IVEC3 },
  { "ivec4", PPTK_IVEC4 },
  { "vec2", PPTK_VEC2 },
  { "vec3", PPTK_VEC3 },
  { "vec4", PPTK_VEC4 },
  { "mat2", PPTK_MAT2 },
  { "mat3", PPTK_MAT3 },
  { "mat4", PPTK_MAT4 },

  /* Reserved for future GLSL versions. */
  { "asm", PPTK_ASM },
  { "class", PPTK_CLASS },
  { "template", PPTK_TEMPLATE },
  { "this", PPTK_THIS },
  { "packed", PPTK_PACKED },
  { "noinline", PPTK_NOINLINE },
  { "public", PPTK_PUBLIC },
  { "external", PPTK_EXTERNAL },
  { "interface", PPTK_INTERFACE },
  { "flat", PPTK_FLAT },
  { "half", PPTK_HALF },
  { "fixed", PPTK_FIXED },
  { "superp", PPTK_SUPERP },
  { "input", PPTK_INPUT },
  { "output", PPTK_OUTPUT },
  { "hvec2", PPTK_HVEC2 },
  { "hvec3", PPTK_HVEC3 },
  { "hvec4", PPTK_HVEC4 },
  { "dvec2", PPTK_DVEC2 },
  { "dvec3", PPTK_DVEC3 },
  { "dvec4", PPTK_DVEC4 },
  { "fvec2", PPTK_FVEC2 },
  { "fvec3", PPTK_FVEC3 },
  { "fvec4", PPTK_FVEC4 },
  { "sampler1D", PPTK_SAMPLER1D },
  { "sampler3D", PPTK_SAMPLER3D },
  { "sampler1DShadow", PPTK_SAMPLER1DSHADOW },
  { "sampler2DShadow", PPTK_SAMPLER2DSHADOW },
  { "sampler2DRect", PPTK_SAMPLER2DRECT },
  { "sampler3DRect", PPTK_SAMPLER3DRECT },
  { "sampler2DRectShadow", PPTK_SAMPLER2DRECTSHADOW },
  { "cast", PPTK_CAST },
  { "namespace", PPTK_NAMESPACE },
  { "using", PPTK_USING },
  { NULL, PPTK_INVALID }
};

struct pp_operator {
  const char *text_;
  enum pptoken token_;
};

static const struct pp_operator pp_operators[] = {
  { "(", PPTK_PAR_OPEN },
  { ")", PPTK_PAR_CLOSE },
  { "[", PPTK_SQBRACE_OPEN },
  { "]", PPTK_SQBRACE_CLOSE },
  { "{", PPTK_CUBRACE_OPEN },
  { "}", PPTK_CUBRACE_CLOSE },
  { ".", PPTK_DOT },
  { "...", PPTK_DOT_DOT_DOT },
  { ",", PPTK_COMMA },
  { ":", PPTK_COLON },
  { ";", PPTK_SEMICOLON },
  { "?", PPTK_QUESTION_MARK },
  { "+", PPTK_PLUS },
  { "-", PPTK_MINUS },
  { "*", PPTK_ASTERISK },
  { "/", PPTK_SLASH },
  { "%", PPTK_PERCENT },
  { "<<", PPTK_LT_LT },
  { ">>", PPTK_GT_GT },
  { "<", PPTK_LT },
  { ">", PPTK_GT },
  { "<=", PPTK_LT_EQUALS },
  { ">=", PPTK_GT_EQUALS },
  { "==", PPTK_EQUALS_EQUALS },
  { "!=", PPTK_BANG_EQUALS },
  { "&", PPTK_AMPERSAND },
  { "|", PPTK_BAR },
  { "^", PPTK_CARET },
  { "&&", PPTK_AMPERSAND_AMPERSAND },
  { "||", PPTK_BAR_BAR },
  { "^^", PPTK_CARET_CARET },
  { "!", PPTK_BANG },
  { "~", PPTK_TILDE },
  { "++", PPTK_PLUS_PLUS },
  { "--", PPTK_MINUS_MINUS },
  { "=", PPTK_EQUALS },
  { "+=", PPTK_PLUS_EQUALS },
  { "-=", PPTK_MINUS_EQUALS },
  { "*=", PPTK_ASTERISK_EQUALS },
  { "/=", PPTK_SLASH_EQUALS },
  { "%=", PPTK_PERCENT_EQUALS },
  { "<<=", PPTK_LT_LT_EQUALS },
  { ">>=", PPTK_GT_GT_EQUALS },
  { "&=", PPTK_AMPERSAND_EQUALS },
  { "|=", PPTK_BAR_EQUALS },
  { "^=", PPTK_CARET_EQUALS },
  { "->", PPTK_ARROW },
  { "#", PPTK_HASH_MARK },
  { "##", PPTK_HASH_HASH_MARK },
  { NULL, PPTK_INVALID }
};

static int pp_token_column(struct preprocessor *pp,
                           struct mulle_cpp_token *token) {
  struct mulle_cpp_lexer_range *range;
  const char *p;

  if (!pp->source_start_ || !mulle_cpp_token_get_nranges(token)) {
    return 1;
  }
  range = mulle_cpp_token_get_range(token, 0);
  if (!range || !range->start || range->start < pp->source_start_ ||
      range->start >= pp->source_end_) {
    return 1;
  }
  p = range->start;
  while (p > pp->source_start_ && p[-1] != '\n') {
    --p;
  }
  return (int) (range->start - p) + 1;
}

static size_t pp_token_offset(struct preprocessor *pp,
                              struct mulle_cpp_token *token) {
  struct mulle_cpp_lexer_range *range;

  if (!pp->source_start_ || !mulle_cpp_token_get_nranges(token)) {
    return 0;
  }
  range = mulle_cpp_token_get_range(token, 0);
  if (!range || !range->start || range->start < pp->source_start_ ||
      range->start > pp->source_end_) {
    return 0;
  }
  return (size_t) (range->start - pp->source_start_);
}

static int pp_number_is_float(const char *text, size_t len) {
  size_t i;

  if (len > 2 && text[0] == '0' && (text[1] == 'x' || text[1] == 'X')) {
    return 0;
  }
  for (i = 0; i < len; ++i) {
    if (text[i] == '.' || text[i] == 'e' || text[i] == 'E') {
      return 1;
    }
  }
  return 0;
}

static size_t pp_number_second_dot(const char *text, size_t len) {
  size_t i;
  int dots;

  dots = 0;
  for (i = 0; i < len; ++i) {
    if (text[i] == '.') {
      if (++dots == 2) {
        return i;
      }
    }
  }
  return 0;
}

static struct pptk *pp_convert_token(struct preprocessor *pp,
                                     struct mulle_cpp_token *token) {
  struct mulle_cpp_lexer_range *range;
  struct pptk *out;
  struct situs sit;
  char *text;
  size_t len;
  size_t offset;
  int column;
  int bool_value;
  int i;
  enum pptoken tok;

  switch (token->kind) {
    case mulle_cpp_token_whitespace:
    case mulle_cpp_token_newline:
    case mulle_cpp_token_directive:
    case mulle_cpp_token_eof:
    case mulle_cpp_token_unknown:
      return NULL;
    default:
      break;
  }

  len = mulle_cpp_token_get_length(token);
  text = (char *) malloc(len + 1);
  if (!text) {
    dx_no_memory(pp->dx_);
    return NULL;
  }
  mulle_cpp_token_get_bytes(token, text, len);
  text[len] = '\0';

  tok = PPTK_INVALID;
  bool_value = 0;
  switch (token->kind) {
    case mulle_cpp_token_identifier:
      tok = PPTK_IDENT;
      for (i = 0; pp_keywords[i].name_; ++i) {
        if (!strcmp(text, pp_keywords[i].name_)) {
          tok = pp_keywords[i].token_;
          break;
        }
      }
      if (!strcmp(text, "true")) {
        tok = PPTK_BOOL_CONSTANT;
        bool_value = 1;
      }
      else if (!strcmp(text, "false")) {
        tok = PPTK_BOOL_CONSTANT;
        bool_value = 0;
      }
      break;

    case mulle_cpp_token_number:
      if (pp_number_is_float(text, len)) {
        tok = PPTK_FLOAT_LIT;
      }
      else {
        tok = PPTK_INTEGER_LIT;
      }
      break;

    case mulle_cpp_token_string:
      tok = PPTK_STRING_LIT;
      break;

    case mulle_cpp_token_characters:
      tok = PPTK_CHAR_LIT;
      break;

    case mulle_cpp_token_operator:
      for (i = 0; pp_operators[i].text_; ++i) {
        if (!strcmp(text, pp_operators[i].text_)) {
          tok = pp_operators[i].token_;
          break;
        }
      }
      break;

    default:
      break;
  }

  range = mulle_cpp_token_get_nranges(token) ?
          mulle_cpp_token_get_range(token, 0) : NULL;
  offset = pp_token_offset(pp, token);

  column = pp_token_column(pp, token);

  aex_situs_init(&sit);
  sit.num_spans_ = 1;
  sit.u_.one_.filename_ = token->file ? token->file :
                          (pp->input_file_ ? pp->input_file_->filename_ : "");
  sit.u_.one_.start_ = offset;
  sit.u_.one_.end_ = offset + len;
  sit.u_.one_.start_line_ = sit.u_.one_.end_line_ = (int) token->line;
  sit.u_.one_.start_col_ = column;
  sit.u_.one_.end_col_ = column + (int) len;
  sit.u_.one_.is_substitution_ = 0;
  sit.u_.one_.is_aux_ = 0;
  sit.u_.one_.num_bytes_ = len;
  if (!range) {
    sit.u_.one_.start_ = sit.u_.one_.end_ = 0;
  }

  if (tok == PPTK_FLOAT_LIT) {
    size_t split;

    split = pp_number_second_dot(text, len);
    if (split) {
      struct situs second_sit;
      struct pptk *second;

      second_sit = sit;
      second_sit.u_.one_.start_ += split;
      second_sit.u_.one_.start_col_ += (int) split;
      second_sit.u_.one_.num_bytes_ = len - split;
      second = aex_pptk_alloc_len(pp, NULL, text + split, len - split,
                                  PPTK_FLOAT_LIT, &second_sit);
      if (second) {
        second->v_type_ = PPVT_FLOAT;
        second->v_.f_ = (float) strtod(second->text_, NULL);
        if (pp->pending_token_) {
          aex_pptk_free(pp->pending_token_);
        }
        pp->pending_token_ = second;
      }
      len = split;
      sit.u_.one_.end_ = offset + len;
      sit.u_.one_.end_col_ = column + (int) len;
      sit.u_.one_.num_bytes_ = len;
    }
  }

  out = aex_pptk_alloc_len(pp, &pp->pp_output_, text, len, tok, &sit);
  free(text);
  if (!out) {
    return NULL;
  }
  if (token->kind == mulle_cpp_token_operator &&
      mulle_cpp_lexer_code_is_operator(token->code)) {
    out->prec_ = mulle_cpp_lexer_code_get_glsl_precedence(token->code);
  }

  switch (tok) {
    case PPTK_INTEGER_LIT:
      out->v_type_ = PPVT_INT;
      out->v_.i64_ = (int64_t) strtoll(out->text_, NULL, 0);
      break;
    case PPTK_FLOAT_LIT:
      out->v_type_ = PPVT_FLOAT;
      out->v_.f_ = (float) strtod(out->text_, NULL);
      break;
    case PPTK_BOOL_CONSTANT:
      out->v_type_ = PPVT_UNSIGNED_INT;
      out->v_.u64_ = (uint64_t) bool_value;
      break;
    default:
      out->v_type_ = PPVT_NO_VALUE;
      break;
  }

  return out;
}

void aex_if_set_input(struct pp_input_file *ifile, const void *input_buf,
                      size_t input_buf_size, int is_final) {
  ifile->input_ = input_buf;
  ifile->input_size_ = input_buf_size;
  ifile->input_final_ = is_final;
  ifile->have_input_ = 1;
}

void pp_init(struct preprocessor *pp) {
  struct mulle_cpp_config config;

  memset(pp, 0, sizeof(*pp));
  dx_diags_init(&pp->default_dx_);
  pp->dx_ = &pp->default_dx_;

  memset(&config, 0, sizeof(config));
  mulle_cpp_dialect_init(&config.dialect,
                         mulle_cpp_dialect_glsl_es_100_strict);
  config.callbacks.diagnostic = pp_diagnostic_callback;
  config.callbacks.baton = pp;
  /* We copy each token into the parser representation immediately, so the
   * engine can recycle its token arena between calls. */
  config.reclaim_tokens = 1;
  pp->cpp_ = mulle_cpp_create(config);
}

void pp_cleanup(struct preprocessor *pp) {
  if (pp->cpp_) {
    mulle_cpp_destroy(pp->cpp_);
    pp->cpp_ = NULL;
  }
  if (pp->pp_output_) {
    aex_pptk_free(pp->pp_output_);
    pp->pp_output_ = NULL;
  }
  if (pp->pending_token_) {
    aex_pptk_free(pp->pending_token_);
    pp->pending_token_ = NULL;
  }
  if (pp->input_file_) {
    free((void *) pp->input_file_->filename_);
    free(pp->input_file_);
    pp->input_file_ = NULL;
  }
  dx_diags_cleanup(&pp->default_dx_);
}

int pp_define_macro(struct preprocessor *pp, const char *name,
                    const char *replacement) {
  char *definition;
  size_t name_len;
  size_t replacement_len;
  int r;

  name_len = strlen(name);
  replacement_len = replacement ? strlen(replacement) : 0;
  definition = (char *) malloc(name_len + replacement_len + 2);
  if (!definition) {
    dx_no_memory(pp->dx_);
    return -1;
  }
  memcpy(definition, name, name_len);
  definition[name_len] = '=';
  if (replacement_len) {
    memcpy(&definition[name_len + 1], replacement, replacement_len);
  }
  definition[name_len + 1 + replacement_len] = '\0';

  r = mulle_cpp_define_macro(pp->cpp_, definition);
  free(definition);
  return (r == mulle_cpp_ok) ? 0 : -1;
}

struct pp_input_file *pp_push_input_file(struct preprocessor *pp,
                                        const char *filename,
                                        size_t aux_data) {
  struct pp_input_file *ifile;

  if (pp->source_started_) {
    mulle_cpp_pop_source(pp->cpp_);
    pp->source_started_ = 0;
  }
  if (pp->input_file_) {
    free((void *) pp->input_file_->filename_);
    free(pp->input_file_);
  }

  ifile = (struct pp_input_file *) calloc(1, sizeof(*ifile) + aux_data);
  if (!ifile) {
    dx_no_memory(pp->dx_);
    return NULL;
  }
  ifile->filename_ = (const char *) malloc(strlen(filename) + 1);
  if (!ifile->filename_) {
    free(ifile);
    dx_no_memory(pp->dx_);
    return NULL;
  }
  strcpy((char *) ifile->filename_, filename);
  ifile->baton_ = ifile;
  pp->input_file_ = ifile;
  return ifile;
}

enum preprocessor_result pp_preprocessor_stage(struct preprocessor *pp) {
  if (pp->pending_token_) {
    struct pptk *token = pp->pending_token_;
    pp->pending_token_ = NULL;
    pp->pp_output_ = aex_pptk_join(pp->pp_output_, token);
    return PPR_SUCCESS;
  }
  if (pp->pp_output_final_) {
    return PPR_SUCCESS;
  }

  if (!pp->source_started_) {
    struct pp_input_file *ifile;

    ifile = pp->input_file_;
    if (!ifile) {
      return PPR_NEED_INPUT;
    }
    if (ifile->input_request_fn_) {
      if (ifile->input_request_fn_(ifile->baton_, ifile)) {
        return PPR_FAILED;
      }
    }
    if (!ifile->have_input_) {
      return PPR_NEED_INPUT;
    }

    pp->source_start_ = (const char *) ifile->input_;
    pp->source_end_ = (const char *) ifile->input_ + ifile->input_size_;
    pp->source_unpoppable_ = ifile->unpoppable_;
    if (mulle_cpp_push_source(pp->cpp_, ifile->filename_, ifile->input_,
                              ifile->input_size_) != mulle_cpp_ok) {
      return PPR_FAILED;
    }
    pp->source_started_ = 1;
  }

  for (;;) {
    struct mulle_cpp_token *token;
    struct pptk *out;
    int r;

    r = mulle_cpp_next_token(pp->cpp_, &token);
    if (r == mulle_cpp_ok) {
      out = pp_convert_token(pp, token);
      if (out) {
        return PPR_SUCCESS;
      }
      continue;
    }

    if (r == mulle_cpp_need_input || r == mulle_cpp_eof) {
      if (!pp->source_unpoppable_) {
        pp->source_started_ = 0;
        if (pp->input_file_) {
          free((void *) pp->input_file_->filename_);
          free(pp->input_file_);
          pp->input_file_ = NULL;
        }
        return PPR_OLD_INCLUDE;
      }
      pp->pp_output_final_ = 1;
      return PPR_SUCCESS;
    }

    return PPR_FAILED;
  }
}
