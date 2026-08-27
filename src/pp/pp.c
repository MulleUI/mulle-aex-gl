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

#ifndef STDLIB_H_INCLUDED
#define STDLIB_H_INCLUDED
#include <stdlib.h>
#endif

#ifndef STDIO_H_INCLUDED
#define STDIO_H_INCLUDED
#include <stdio.h>
#endif

#ifndef STDARG_H_INCLUDED
#define STDARG_H_INCLUDED
#include <stdarg.h>
#endif

#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED
#include <string.h>
#endif

#ifndef ASSERT_H_INCLUDED
#define ASSERT_H_INCLUDED
#include <assert.h>
#endif

#ifndef PP_H_INCLUDED
#define PP_H_INCLUDED
#include "pp.h"
#endif

#ifndef PP_MACRO_TABLE_H_INCLUDED
#define PP_MACRO_TABLE_H_INCLUDED
#include "pp_macro_table.h"
#endif

#ifndef PP_TOKENS_H_INCLUDED
#define PP_TOKENS_H_INCLUDED
#include "pp_tokens.h"
#endif

#ifndef PP_TOKENIZER_H_INCLUDED
#define PP_TOKENIZER_H_INCLUDED
#include "pp_tokenizer.h"
#endif

#ifndef PP_LINE_DIRECTIVES_H_INCLUDED
#define PP_LINE_DIRECTIVES_H_INCLUDED
#include "pp_line_directives.h"
#endif

#ifndef PP_MACRO_EXPANDER_H_INCLUDED
#define PP_MACRO_EXPANDER_H_INCLUDED
#include "pp_macro_expander.h"
#endif

#ifndef PP_CONST_EXPR_H_INCLUDED
#define PP_CONST_EXPR_H_INCLUDED
#include "pp_const_expr.h"
#endif

#ifndef PP_LINE_CONTINUATIONS_H_INCLUDED
#define PP_LINE_CONTINUATIONS_H_INCLUDED
#include "pp_line_continuations.h"
#endif

#ifndef PP_TRIGRAPHS_H_INCLUDED
#define PP_TRIGRAPHS_H_INCLUDED
#include "pp_trigraphs.h"
#endif

#ifndef PP_INPUT_FILE_H_INCLUDED
#define PP_INPUT_FILE_H_INCLUDED
#include "pp_input_file.h"
#endif

static int pp_stderr_vprintf_handler(void *baton, const char *file, int line_num, const char *fmt, va_list args);

struct pp_input_file *pp_push_input_file(struct preprocessor *pp, const char *filename, size_t aux_data) {
  char *sf = pp_preserve_filename(pp, filename);
  if (!sf) return NULL;
  struct pp_input_file *ifile = (struct pp_input_file *)malloc(sizeof(struct pp_input_file) + aux_data);
  if (!ifile) {
    free(sf);
    return NULL;
  }
  aex_if_init(ifile, pp);
  ifile->filename_ = sf;
  ifile->ppld_input_line_ = 0;
  ifile->ppld_input_line_filename_ = NULL;
  ifile->pptk_input_line_ = 1;
  ifile->pptk_input_line_filename_ = sf;
  return ifile;
}

static void pp_pop_input_file(struct preprocessor *pp) {
  struct pp_input_file *ifile = pp->input_stack_;
  if (ifile) {
    aex_if_cleanup(ifile);
    free(ifile);
  }
}

void pp_init(struct preprocessor *pp) {
  dx_diags_init(&pp->default_dx_);
  pp->dx_ = &pp->default_dx_; /* caller may set this somewhere else */

  mt_init(&pp->macro_table_);
  pp->if_section_stack_ = NULL;

  pp->ppme_input_final_ = 0;
  pp->ppme_input_ = NULL;
  pp->ppme_input_file_ = NULL;
  pp->ppme_input_line_ = 0;
  aex_ppme_stack_init(&pp->ppme_);

  pp->ppld_input_final_ = 0;
  pp->have_ppld_input_line_ = 0;
  pp->ppld_input_ = NULL;

  pp->input_stack_ = NULL;

  pp->pp_output_ = NULL;
  pp->pp_output_final_ = 0;

  pp->filename_buffers_ = NULL;

  pp->bits_per_char_ = 8;
  pp->bits_per_short_ = 16;
  pp->bits_per_int_ = 32;
  pp->bits_per_long_ = 32;
  pp->bits_per_long_long_ = 64;

  pp->include_is_system_include_ = 0;
  pp->include_is_template_emit_ = 0;
  pp->include_file_arg_ = NULL;

  pp->vprintf_handler = pp_stderr_vprintf_handler;
  pp->vprintf_baton_ = NULL;
}

void pp_cleanup(struct preprocessor *pp) {
  mt_cleanup(&pp->macro_table_);

  while (pp->if_section_stack_) pp_if_pop(pp);

  aex_ppme_stack_cleanup(&pp->ppme_);
  aex_pptk_free(pp->ppme_input_);

  aex_pptk_free(pp->ppld_input_);

  while (pp->input_stack_) pp_pop_input_file(pp);

  aex_pptk_free(pp->pp_output_);

  while (pp->filename_buffers_) {
    struct pp_filename_buffer *fb = pp->filename_buffers_;
    pp->filename_buffers_ = fb->next_;
    free(fb);
  }

  if (pp->include_file_arg_) {
    free(pp->include_file_arg_);
  }

  dx_diags_cleanup(&pp->default_dx_);
}

struct pp_if_section *pp_if_push(struct preprocessor *pp) {
  struct pp_if_section *ldifs = (struct pp_if_section *)malloc(sizeof(struct pp_if_section));
  if (!ldifs) return NULL;
  ldifs->parent_ = pp->if_section_stack_;
  pp->if_section_stack_ = ldifs;
  ldifs->state_ = PP_IFSS_SKIP;
  return ldifs;
}

void pp_if_pop(struct preprocessor *pp) {
  struct pp_if_section *ldifs = pp->if_section_stack_;
  pp->if_section_stack_ = ldifs->parent_;
  free(ldifs);
}

int pp_concat_sub_output(struct preprocessor *pp, struct situs *output_situs, char **output_buf, size_t *output_pos, size_t *output_buf_size, struct situs *span_situs, const char *span_text) {
  size_t span_text_len = strlen(span_text);
  return pp_concat_sub_output_b(pp, output_situs, output_buf, output_pos, output_buf_size, span_situs, span_text, span_text_len);
}

int pp_concat_sub_output_b(struct preprocessor *pp, struct situs *output_situs, char **output_buf, size_t *output_pos, size_t *output_buf_size, struct situs *span_situs, const char *span_text, size_t span_text_len) {
  size_t buf_size_needed = (*output_pos) + span_text_len;
  if (buf_size_needed > *output_buf_size) {
    char *newbuf = (char *)realloc(*output_buf, buf_size_needed + 1);
    if (!newbuf) {
      dx_no_memory(pp->dx_);
      return -1;
    }
    *output_buf = newbuf;
    *output_buf_size = buf_size_needed;
  }
  memcpy((*output_buf) + *output_pos, span_text, span_text_len);
  (*output_buf)[(*output_pos) + span_text_len] = '\0';
  struct situs substitution;
  aex_situs_init(&substitution);
  if (aex_situs_clone(&substitution, span_situs)) {
    dx_no_memory(pp->dx_);
    return -1;
  }

  struct situs_span *sss = (substitution.num_spans_ > 1) ? substitution.u_.many_.spans_ : &substitution.u_.one_;
  /* Mark all of the situs a substitution */
  size_t n;
  sss->is_substitution_ = 1;
  for (n = 1; n < substitution.num_spans_; ++n) {
    sss[n].is_aux_ = 1;
    sss[n].num_bytes_ = 0;
  }
  sss[0].num_bytes_ = span_text_len;
  if (aex_situs_concat(output_situs, &substitution)) {
    aex_situs_cleanup(&substitution);
    dx_no_memory(pp->dx_);
    return -1;
  }
  aex_situs_cleanup(&substitution);
  (*output_pos) += span_text_len;
  return 0;
}

int pp_concat_output(struct preprocessor *pp, struct situs *output_situs, char **output_buf, size_t *output_pos, size_t *output_buf_size, struct situs *span_situs, const char *span_text) {
  size_t span_text_len = aex_situs_len(span_situs);
  return pp_concat_output_b(pp, output_situs, output_buf, output_pos, output_buf_size, span_situs, span_text, span_text_len);
}

int pp_concat_output_b(struct preprocessor *pp, struct situs *output_situs, char **output_buf, size_t *output_pos, size_t *output_buf_size, struct situs *span_situs, const char *span_text, size_t span_text_len) {
  size_t buf_size_needed = (*output_pos) + span_text_len;
  if (buf_size_needed > *output_buf_size) {
    char *newbuf = (char *)realloc(*output_buf, buf_size_needed + 1);
    if (!newbuf) {
      dx_no_memory(pp->dx_);
      return -1;
    }
    *output_buf = newbuf;
    *output_buf_size = buf_size_needed;
  }
  memcpy((*output_buf) + *output_pos, span_text, span_text_len);
  (*output_buf)[(*output_pos) + span_text_len] = '\0';
  if (aex_situs_concat(output_situs, span_situs)) {
    dx_no_memory(pp->dx_);
    return -1;
  }
  (*output_pos) += span_text_len;
  return 0;
}

char *pp_preserve_filename(struct preprocessor *pp, const char *filename) {
  size_t len = strlen(filename);
  size_t size_needed = len + sizeof(struct pp_filename_buffer /* includes 1 byte sized array, hence len does not need to include null-terminator */);
  if (size_needed <= len) {
    return NULL; /* overflow */
  }
  struct pp_filename_buffer *fb = (struct pp_filename_buffer *)malloc(size_needed);
  if (!fb) return NULL;
  fb->next_ = pp->filename_buffers_;
  pp->filename_buffers_ = fb;
  memcpy(fb->filename_, filename, len);
  fb->filename_[len] = '\0';
  return fb->filename_;
}


static int pp_stderr_vprintf_handler(void *baton, const char *file, int line_num, const char *fmt, va_list args) {
  if (file) {
    fprintf(stderr, "%s(%d): ", file, line_num);
  }

  int r;
  r = vfprintf(stderr, fmt, args);

  return r < 0;
}

enum preprocessor_result pp_preprocessor_stage(struct preprocessor *pp) {
macro_expander:
  if (pp->ppme_input_ || pp->ppme_input_final_) {
    int r;
    int next_sym;
    if (pp->ppme_input_) {
      next_sym = g_aex_pptk_to_ppme_[pp->ppme_input_->tok_];
    }
    else {
      next_sym = AEX_PPME_INPUT_END;
    }
    /* "defined" token (therefore operator) always disabled on body text macro expansion; in other words,
     * you could #define defined, and that would work everywhere except in an #if clause. */
    if (next_sym == AEX_PPME_DEFINED) next_sym = AEX_PPME_IDENT;

    if (next_sym == AEX_PPME_IDENT) {
      struct macro *m = mt_find(&pp->macro_table_, pp->ppme_input_->text_, pp->ppme_input_->text_len_);

      if (m && !m->nested_invocation_) {
        if (m->is_function_style_) {
          next_sym = AEX_PPME_FUNCTION;
        }
        else {
          next_sym = AEX_PPME_OBJECT;
        }
      }
    }
    r = aex_ppme_parse(&pp->ppme_, next_sym, pp, &pp->ppme_input_, pp->ppme_input_final_, &pp->pp_output_, 0);
    switch (r) {
      case _AEX_PPME_FINISH:
        pp->pp_output_final_ = 1;
        /* Preprocessor is done */
        return PPR_SUCCESS;

      case _AEX_PPME_FEED_ME:
        /* Need more input; however, if we have a bit of output ready for the C parser, process that first so
         * we minimize the number of tokens concurrently in-flight. */
        if (pp->pp_output_) {
          return PPR_SUCCESS;
        }
        break; /* get more input .. */

      case _AEX_PPME_SYNTAX_ERROR:
        if (pp->ppme_input_) {
          dx_error_loc(pp->dx_, &pp->ppme_input_->situs_, "syntax error: \"%s\"\n", pp->ppme_input_->text_);
        }
        else {
          dx_printf(pp->dx_, "%s(%d): syntax error at end of file\n", pp->ppme_input_file_, pp->ppme_input_line_);
          pp->dx_->have_error_ = 1;
        }
        /* keep going */
        goto macro_expander;

      case _AEX_PPME_MATCH:
      case _AEX_PPME_OVERFLOW:
      case _AEX_PPME_NO_MEMORY:
      case _AEX_PPME_END_OF_INPUT:
      case _AEX_PPME_LEXICAL_ERROR:
      case _AEX_PPME_INTERNAL_ERROR:
      default:
        if (pp->ppme_input_) {
          dx_error_loc(pp->dx_, &pp->ppme_input_->situs_, "internal error (%d) from aex_ppme_parse: \"%s\"\n", r, pp->ppme_input_->text_);
        }
        else {
          dx_printf(pp->dx_, "%s(%d): internal error (%d) from aex_ppme_parse at end of file\n", pp->ppme_input_file_, pp->ppme_input_line_, r);
          pp->dx_->have_error_ = 1;
        }
        return PPR_FAILED;
    }
  }

line_directives:
  if (!pp->input_stack_) {
    pp->ppme_input_final_ = 1;
    goto macro_expander;
  }

  if (pp->input_stack_->ppld_end_processed_pop_now_) {
    /* Current input file has finished; so there is no sense in requesting more input.
     * Pop to parent if possible. */
    if (!pp->input_stack_->unpoppable_) {
      pp->ppld_input_final_ = 0;
      pp_pop_input_file(pp);
      return PPR_OLD_INCLUDE;
    }
    else {
      pp->ppme_input_final_ = 1;
      goto macro_expander;
    }
  }

  if (!pp->ppld_input_ && !pp->have_ppld_input_line_ && pp->ppld_input_final_) {
    pp->input_stack_->ppld_end_processed_pop_now_ = 1;
    goto macro_expander;
  }

  if (pp->ppld_input_ || pp->have_ppld_input_line_ || pp->input_stack_->ppld_input_not_finished_) {
    for (;;) {
      int ppld_r;
      /* Single lines are always final from the perspective of the ppld parser (hence we pass 1 for is_final),
       * whether the total file is final (ppld_input_final_) determines if it is the last line of the file,
       * this line might be empty. */
      if (!pp->input_stack_->ppld_input_not_finished_) {
        struct pptk *pp_current = pp->ppld_input_ ? aex_pptk_pop_front(&pp->ppld_input_) : NULL;
        ppld_r = aex_ppld_parse(&pp->input_stack_->ppld_, pp_current ? g_aex_pptk_to_ppld_[pp_current->tok_] : /* have_ppld_input_line_ == true */ AEX_PPLD_INPUT_END, pp, &pp_current, &pp->ppld_input_, pp->have_ppld_input_line_, &pp->ppme_input_);
        if (pp_current) {
          /* Front (in current) was not processed, recombine */
          pp->ppld_input_ = aex_pptk_join(pp_current, pp->ppld_input_);
        }
      }
      else {
        // Finish up last line before processing tokens for a new one.
        ppld_r = aex_ppld_parse(&pp->input_stack_->ppld_, AEX_PPLD_INPUT_END, pp, NULL, NULL, 0, &pp->ppme_input_);
        pp->input_stack_->ppld_input_not_finished_ = 0;
      }
      switch (ppld_r) {
        case PPLD_INCLUDE_FILE:
          pp->input_stack_->ppld_input_not_finished_ = 1;
          pp->have_ppld_input_line_ = 0;
          return PPR_NEW_INCLUDE;
        case _AEX_PPLD_FINISH:
          pp->ppme_input_file_ = pp->input_stack_->ppld_input_line_filename_;
          pp->ppme_input_line_ = pp->input_stack_->ppld_input_line_;
          pp->have_ppld_input_line_ = 0;
          goto macro_expander;
        case _AEX_PPLD_SYNTAX_ERROR:
          if (pp->ppld_input_) {
            dx_error_loc(pp->dx_, &pp->ppld_input_->situs_, "syntax error: \"%s\"\n", pp->ppld_input_->text_);
          }
          else {
            dx_printf(pp->dx_, "%s(%d): syntax error at end of file\n", pp->input_stack_->ppld_input_line_filename_, pp->input_stack_->ppld_input_line_);
            pp->dx_->have_error_ = 1;
          }
          break;
        case _AEX_PPLD_MATCH:
        case _AEX_PPLD_END_OF_INPUT:
          /* Should not reach here - lexer internal codes */
          assert(0 && "Should never return lexer internal codes");
          return PPR_FAILED;
        case _AEX_PPLD_LEXICAL_ERROR:
          /* Not lexing, should not return lexer errors */
          assert(0 && "Should never return lexer codes");
          return PPR_FAILED;
        case _AEX_PPLD_FEED_ME:
          /* Needs more input */
          /* If we have input for the macro-expander, process it first before creating more tokens */
          if (pp->ppme_input_) {
            pp->ppme_input_file_ = pp->input_stack_->ppld_input_line_filename_;
            pp->ppme_input_line_ = pp->input_stack_->ppld_input_line_;
            goto macro_expander;
          }
          goto tokenizer;
        case _AEX_PPLD_OVERFLOW:
          dx_printf(pp->dx_, "Overflow while parsing line directives\n");
          pp->dx_->have_error_ = 1;
          return PPR_FAILED;
        case _AEX_PPLD_NO_MEMORY:
          dx_printf(pp->dx_, "No memory while parsing line directives\n");
          pp->dx_->have_error_ = 1;
          return PPR_FAILED;
        case _AEX_PPLD_INTERNAL_ERROR:
          dx_printf(pp->dx_, "Internal error while parsing line directives\n");
          pp->dx_->have_error_ = 1;
          return PPR_FAILED;
        default:
          dx_printf(pp->dx_, "Unexpected returncode while parsing line directives\n");
          return PPR_FAILED;
      }
    }
  }

tokenizer:;
  int pptk_r;
  do {
    int break_out = 0;
    if (aex_ppld_stack_accepts(&pp->input_stack_->ppld_, AEX_PPLD_HEADER_NAME)) {
      switch (aex_pptk_mode(&pp->input_stack_->pptk_)) {
        case M_AEX_PPTK_DEFAULT:
        case M_AEX_PPTK_HEADER_NAME_POSSIBLE:
          aex_pptk_set_mode(&pp->input_stack_->pptk_, M_AEX_PPTK_HEADER_NAME_POSSIBLE);
          break;
        case M_AEX_PPTK_TEMPLATE_DEFAULT:
        case M_AEX_PPTK_TEMPLATE_HEADER_NAME_POSSIBLE:
        case M_AEX_PPTK_TEMPLATE_START:
          aex_pptk_set_mode(&pp->input_stack_->pptk_, M_AEX_PPTK_TEMPLATE_HEADER_NAME_POSSIBLE);
          break;
      }

    }
    else {
      switch (aex_pptk_mode(&pp->input_stack_->pptk_)) {
        case M_AEX_PPTK_DEFAULT:
        case M_AEX_PPTK_HEADER_NAME_POSSIBLE:
          aex_pptk_set_mode(&pp->input_stack_->pptk_, M_AEX_PPTK_DEFAULT);
          break;
        case M_AEX_PPTK_TEMPLATE_DEFAULT:
        case M_AEX_PPTK_TEMPLATE_HEADER_NAME_POSSIBLE:
          aex_pptk_set_mode(&pp->input_stack_->pptk_, M_AEX_PPTK_TEMPLATE_DEFAULT);
          break;
        case M_AEX_PPTK_TEMPLATE_START:
          /* Keep as is; the pptk tokenizer itself will change in due course */
          break;
      }
    }

    pptk_r = aex_pptk_scan(&pp->input_stack_->pptk_, pp, &pp->ppld_input_, &pp->input_stack_->post_line_continuation_situs_);
    switch (pptk_r) {
      case PPTK_TOKENIZER_LINE_READY:
        pp->have_ppld_input_line_ = 1;
        pp->input_stack_->ppld_input_line_ = pp->input_stack_->pptk_input_line_;
        pp->input_stack_->ppld_input_line_filename_ = pp->input_stack_->pptk_input_line_filename_;
        int current_line = aex_pptk_endline(&pp->input_stack_->pptk_);
        pp->input_stack_->pptk_input_line_ += current_line - pp->input_stack_->pptk_true_input_line_number_at_start_;
        pp->input_stack_->pptk_true_input_line_number_at_start_ = current_line;
        goto line_directives;
      case _AEX_PPTK_FINISH:
        break;
      case _AEX_PPTK_MATCH:
      case _AEX_PPTK_END_OF_INPUT:
        assert(0); /* lexer internal code */
        break;
      case _AEX_PPTK_SYNTAX_ERROR: {
        struct situs *situs = (struct situs *)aex_pptk_token_common_data(&pp->input_stack_->pptk_);
        if (situs) {
          dx_error_loc(pp->dx_, situs, "syntax error: \"%s\"\n", aex_pptk_text(&pp->input_stack_->pptk_));
        }
        else {
          dx_printf(pp->dx_, "%s(%d): syntax error at column %d: \"%s\"\n", pp->input_stack_->pptk_input_line_filename_, aex_pptk_line(&pp->input_stack_->pptk_), aex_pptk_column(&pp->input_stack_->pptk_), aex_pptk_text(&pp->input_stack_->pptk_));
          pp->dx_->have_error_ = 1;
        }
        break;
      }
      case _AEX_PPTK_LEXICAL_ERROR:
        dx_printf(pp->dx_, "%s(%d): lexical error at column %d: \"%s\"\n", pp->input_stack_->pptk_input_line_filename_, aex_pptk_line(&pp->input_stack_->pptk_), aex_pptk_column(&pp->input_stack_->pptk_), aex_pptk_text(&pp->input_stack_->pptk_));
        pp->dx_->have_error_ = 1;
        break;
      case _AEX_PPTK_INTERNAL_ERROR:
        dx_printf(pp->dx_, "%s(%d): internal error at column %d: \"%s\"\n", pp->input_stack_->pptk_input_line_filename_, aex_pptk_line(&pp->input_stack_->pptk_), aex_pptk_column(&pp->input_stack_->pptk_), aex_pptk_text(&pp->input_stack_->pptk_));
        pp->dx_->have_error_ = 1;
        break;
      case PPTK_TOKENIZER_HEADERNAME_CHECK:
        /* Scanner thinks we should check if a headername is acceptable, this depends on whether the line directive parser can handle it. */
        /* Go to the line directives parser, parse to the extent input is available, and then come back here (via _AEX_PPLD_FEED_ME) to
         * check aex_ppld_stack_accepts(AEX_PPLD_HEADER_NAME) and set the pptk mode appropriately. */
        goto line_directives;
      case _AEX_PPTK_FEED_ME:
        if (pp->ppld_input_) {
          /* Process input first; this is not a complete line but ensures we push as much as possible prior to asking
           * for more input. */
          goto line_directives;
        }
        break;
    }
  } while ((pptk_r != _AEX_PPTK_FEED_ME) && (pptk_r != _AEX_PPTK_FINISH));

  if ((pptk_r == _AEX_PPTK_FINISH) && !pp->input_stack_->pptk_pushed_final_source_line_) {
    /* Complete last line directive, the last line never ends with a newline. */
    pp->have_ppld_input_line_ = 1;
    pp->input_stack_->ppld_input_line_ = pp->input_stack_->pptk_input_line_;
    pp->input_stack_->ppld_input_line_filename_ = pp->input_stack_->pptk_input_line_filename_;
    pp->input_stack_->pptk_pushed_final_source_line_ = 1;
    goto line_directives;
  }

  if (pp->ppld_input_) {
    /* Process input first; this is not a complete line but ensures we push as much as possible prior to asking
     * for more input. */
    goto line_directives;
  }

  if (pptk_r == _AEX_PPTK_FINISH) {
    /* we only get here if trigraphs has depleted its input (or pptk
     * would not return _AEX_PPTK_FINISH but _AEX_PPTK_FEED_ME) */
    /* Cannot pop current input source, we've reached the end; bubble
     * any remaining input up through the stages until we ultimately
     * set all_done_ at the top... */
    pp->ppld_input_final_ = 1;
    goto line_directives;
  }
line_continuations:;
  int pplc_r;
  do {
    pplc_r = aex_pplc_scan(&pp->input_stack_->pplc_, pp, &pp->input_stack_->post_line_continuation_, &pp->input_stack_->post_line_continuation_size_, &pp->input_stack_->post_line_continuation_size_allocated_, &pp->input_stack_->post_line_continuation_situs_, &pp->input_stack_->post_trigraph_situs_);
    switch (pplc_r) {
      case _AEX_PPLC_FINISH:
        break;
      case _AEX_PPLC_MATCH:
      case _AEX_PPLC_END_OF_INPUT:
        assert(0); /* lexer internal code */
        break;
      case _AEX_PPLC_SYNTAX_ERROR: {
        struct situs *situs = (struct situs *)aex_pplc_token_common_data(&pp->input_stack_->pplc_);
        if (situs) {
          dx_error_loc(pp->dx_, situs, "syntax error: \"%s\"\n", aex_pplc_text(&pp->input_stack_->pplc_));
        }
        else {
          dx_printf(pp->dx_, "%s(%d): syntax error at column %d: \"%s\"\n", pp->input_stack_->ppld_input_line_filename_, aex_pplc_line(&pp->input_stack_->pplc_), aex_pplc_column(&pp->input_stack_->pplc_), aex_pplc_text(&pp->input_stack_->pplc_));
          pp->dx_->have_error_ = 1;
        }
        break;
      }
      case _AEX_PPLC_LEXICAL_ERROR:
        dx_printf(pp->dx_, "(%d): lexical error at column %d: \"%s\"\n", aex_pplc_line(&pp->input_stack_->pplc_), aex_pplc_column(&pp->input_stack_->pplc_), aex_pplc_text(&pp->input_stack_->pplc_));
        pp->dx_->have_error_ = 1;
        break;
      case _AEX_PPLC_INTERNAL_ERROR:
        dx_printf(pp->dx_, "(%d): internal error at column %d: \"%s\"\n", aex_pplc_line(&pp->input_stack_->pplc_), aex_pplc_column(&pp->input_stack_->pplc_), aex_pplc_text(&pp->input_stack_->pplc_));
        pp->dx_->have_error_ = 1;
        break;
      case _AEX_PPLC_FEED_ME:
        break;
    }
  } while ((pplc_r != _AEX_PPLC_FEED_ME) && (pplc_r != _AEX_PPLC_FINISH));

  if (pp->input_stack_->post_line_continuation_size_ || (pplc_r == _AEX_PPLC_FINISH)) {
    /* Process output of line continuation translation phase first, to ensure we push as much as possible before asking
     * more input. */
    aex_pptk_set_input(&pp->input_stack_->pptk_, pp->input_stack_->post_line_continuation_, pp->input_stack_->post_line_continuation_size_, pplc_r == _AEX_PPLC_FINISH);
    pp->input_stack_->post_line_continuation_size_ = 0;
    goto tokenizer;
  }

trigraphs:;
  int pptg_r;
  do {
    pptg_r = aex_pptg_scan(&pp->input_stack_->pptg_, pp, pp->input_stack_->filename_, &pp->input_stack_->post_trigraph_, &pp->input_stack_->post_trigraph_size_, &pp->input_stack_->post_trigraph_size_allocated_, &pp->input_stack_->post_trigraph_situs_);
    switch (pptg_r) {
      case _AEX_PPTG_FINISH:
        break;
      case _AEX_PPTG_MATCH:
      case _AEX_PPTG_END_OF_INPUT:
        assert(0); /* lexer internal code */
        break;
      case _AEX_PPTG_SYNTAX_ERROR: {
        struct situs *situs = (struct situs *)aex_pptg_token_common_data(&pp->input_stack_->pptg_);
        if (situs) {
          dx_error_loc(pp->dx_, situs, "syntax error: \"%s\"\n", aex_pptg_text(&pp->input_stack_->pptg_));
        }
        else {
          dx_printf(pp->dx_, "%s(%d): syntax error at column %d: \"%s\"\n", pp->input_stack_->ppld_input_line_filename_, aex_pptg_line(&pp->input_stack_->pptg_), aex_pptg_column(&pp->input_stack_->pptg_), aex_pptg_text(&pp->input_stack_->pptg_));
          pp->dx_->have_error_ = 1;
        }
        break;
      }
      case _AEX_PPTG_LEXICAL_ERROR:
        dx_printf(pp->dx_, "(%d): lexical error at column %d: \"%s\"\n", aex_pptg_line(&pp->input_stack_->pptg_), aex_pptg_column(&pp->input_stack_->pptg_), aex_pptg_text(&pp->input_stack_->pptg_));
        pp->dx_->have_error_ = 1;
        break;
      case _AEX_PPTG_INTERNAL_ERROR:
        dx_printf(pp->dx_, "(%d): internal error at column %d: \"%s\"\n", aex_pptg_line(&pp->input_stack_->pptg_), aex_pptg_column(&pp->input_stack_->pptg_), aex_pptg_text(&pp->input_stack_->pptg_));
        pp->dx_->have_error_ = 1;
        break;
      case _AEX_PPTG_FEED_ME:
        break;
    }
  } while ((pptg_r != _AEX_PPTG_FEED_ME) && (pptg_r != _AEX_PPTG_FINISH));

  if (pp->input_stack_->post_trigraph_size_ || (pptg_r == _AEX_PPTG_FINISH)) {
    /* Process output of trigraph translation phase first, to ensure we push as much as possible before asking
     * more input. */
    aex_pplc_set_input(&pp->input_stack_->pplc_, pp->input_stack_->post_trigraph_, pp->input_stack_->post_trigraph_size_, pptg_r == _AEX_PPTG_FINISH);
    pp->input_stack_->post_trigraph_size_ = 0;
    goto line_continuations;
  }

  /* Get more input from the current file. */
  if (!pp->input_stack_->input_request_fn_) {
    return PPR_NEED_INPUT;
  }

  /* Call for more input */
  int ir = pp->input_stack_->input_request_fn_(pp->input_stack_->baton_, pp->input_stack_);
  if (ir) {
    return ir;
  }
  /* And jump to trigraphs to process what we got. If we got nothing, and the caller or input_request_fn_
   * did not mark it as the end of the file, then we might loop infinitely here, but that'd be a bug in
   * the calling code (for not setting is_final() when calling aex_if_set_input(), or not calling aex_if_set_input()
   * at all.) */
  goto trigraphs;

}
