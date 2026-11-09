/* Copyright 2023-2024 Kinglet B.V.
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

#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED
#include <string.h>
#endif

#ifndef STDARG_H_INCLUDED
#define STDARG_H_INCLUDED
#include <stdarg.h>
#endif

#ifndef ASSERT_H_INCLUDED
#define ASSERT_H_INCLUDED
#include <assert.h>
#endif

#ifndef GLSL_ES1_COMPILER_H_INCLUDED
#define GLSL_ES1_COMPILER_H_INCLUDED
#include "glsl_es1_compiler.h"
#endif

#ifndef PP_TOKENS_H_INCLUDED
#define PP_TOKENS_H_INCLUDED
#include "pp/pp_tokens.h"
#endif

#ifndef PP_INPUT_FILE_H_INCLUDED
#define PP_INPUT_FILE_H_INCLUDED
#include "pp_input_file.h"
#endif

#ifndef SL_EXECUTION_H_INCLUDED
#define SL_EXECUTION_H_INCLUDED
#include "sl_execution.h"
#endif

#ifndef SL_COMPILATION_UNIT_H_INCLUDED
#define SL_COMPILATION_UNIT_H_INCLUDED
#include "sl_compilation_unit.h"
#endif

#ifndef SAMPLER_2D_H_INCLUDED
#define SAMPLER_2D_H_INCLUDED
#include "sampler_2d.h"
#endif

int glsl_es1_compiler_define_macro(struct glsl_es1_compiler *cc, const char *name, const char *replacement) {
  return(pp_define_macro(&cc->pp_, name, replacement));
}

void glsl_es1_compiler_init(struct glsl_es1_compiler *cc) {
  dx_diags_init(&cc->default_dx_);
  cc->dx_ = &cc->default_dx_;
  pp_init(&cc->pp_);
  cc->pp_.dx_ = cc->dx_; /* override pp diags to share cc one */
  glsl_es1_stack_init(&cc->parser_);
  sl_type_base_init(&cc->cc_tb_);
  cc->tb_ = &cc->cc_tb_;
  cc->all_done_ = 0;
  cc->shader_is_vertex_ = 0;
  cc->shader_is_fragment_ = 0;
  cc->fragment_default_float_precision_ = 0;
  cc->last_type_specifier_ = NULL;
  cc->current_function_prototype_ = NULL;
  cc->cu_ = NULL;
  cc->current_scope_ = NULL;
  cc->current_frame_ = NULL;
}

void glsl_es1_compiler_cleanup(struct glsl_es1_compiler *cc) {
  sl_type_base_cleanup(&cc->cc_tb_);
  /* input_file_ borrows a filename owned by the preprocessor, and dx_ may
   * outlive us; drop it before pp_cleanup frees the buffer. */
  if (cc->dx_) cc->dx_->input_file_ = "";
  pp_cleanup(&cc->pp_);
  glsl_es1_stack_cleanup(&cc->parser_);
  dx_diags_cleanup(&cc->default_dx_);
  if (cc->cu_) {
    sl_compilation_unit_cleanup(cc->cu_);
    free(cc->cu_);
  }
}


static void glsl_es1_compiler_skip_template_cruft(struct glsl_es1_compiler *cc) {
  while ((cc->pp_.pp_output_) &&
          ((cc->pp_.pp_output_->tok_ == PPTK_TEMPLATE_DOUBLE_CURLY_OPEN) ||
          (cc->pp_.pp_output_->tok_ == PPTK_TEMPLATE_DOUBLE_CURLY_CLOSE) ||
          ((cc->pp_.pp_output_->tok_ == PPTK_TEMPLATE_LIT) && !cc->pp_.pp_output_->text_len_))) {
    aex_pptk_free(aex_pptk_pop_front(&cc->pp_.pp_output_));
  }
}

enum glsl_es1_compiler_result glsl_es1_compiler_stage(struct glsl_es1_compiler *cc) {
  int r;

  if (cc->all_done_) {
    return GLSL_ES1_R_SUCCESS;
  }
  if (cc->dx_->fatal_error_) {
    return GLSL_ES1_R_FAILED;
  }

  for (;;) {
    struct pptk *tk = cc->pp_.pp_output_;
    if (tk) {
      if ((tk->tok_ == PPTK_TEMPLATE_DOUBLE_CURLY_OPEN) ||
          (tk->tok_ == PPTK_TEMPLATE_DOUBLE_CURLY_CLOSE) ||
          ((tk->tok_ == PPTK_TEMPLATE_LIT) && !tk->text_len_)) {
        tk = aex_pptk_pop_front(&cc->pp_.pp_output_);
        aex_pptk_free(tk);
        continue;
      }
      if ((tk->tok_ == PPTK_WHITESPACE) ||
          (tk->tok_ == PPTK_NEWLINE_WHITESPACE)) {
        tk = aex_pptk_pop_front(&cc->pp_.pp_output_);
        aex_pptk_free(tk);
        continue;
      }
      cc->dx_->input_file_ = aex_situs_filename(&tk->situs_);
      cc->dx_->input_line_ = aex_situs_line(&tk->situs_);
      tk = aex_pptk_pop_front(&cc->pp_.pp_output_);
      r = glsl_es1_parser_push(&cc->parser_, cc, tk);
      if (r) {
        aex_pptk_free(tk);
        return GLSL_ES1_R_FAILED;
      }
      continue;
    }
    if (cc->pp_.pp_output_final_) {
      r = glsl_es1_parser_finish(&cc->parser_, cc);
      cc->all_done_ = 1;
      if (r == _GLSL_ES1_FINISH) {
        return GLSL_ES1_R_SUCCESS;
      }
      return (r == _GLSL_ES1_NO_MEMORY) ? GLSL_ES1_R_FAILED : GLSL_ES1_R_HAVE_ERRORS;
    }
    return GLSL_ES1_R_NEED_INPUT;
  }
}


enum glsl_es1_compiler_result glsl_es1_compile(struct glsl_es1_compiler *cc) {
  enum glsl_es1_compiler_result cr;

  if (!cc->cu_) {
    struct sl_compilation_unit *cu = (struct sl_compilation_unit *)malloc(sizeof(struct sl_compilation_unit));
    if (!cu) {
      dx_no_memory(cc->dx_);
      return GLSL_ES1_R_FAILED;
    }
    sl_compilation_unit_init(cu);
    cc->cu_ = cu;
  }

  cc->current_scope_ = &cc->cu_->global_scope_;
  cc->current_frame_ = &cc->cu_->global_frame_;
  cc->cu_->global_frame_.ract_.local_frame_ = 0;

  do {
    glsl_es1_compiler_skip_template_cruft(cc);

    cr = glsl_es1_compiler_stage(cc);
    if (cr != GLSL_ES1_R_NEED_INPUT) {
      return cr;
    }

    cr = pp_preprocessor_stage(&cc->pp_);
    if (cr == GLSL_ES1_R_OLD_INCLUDE) {
      int r = glsl_es1_parser_finish(&cc->parser_, cc);
      if (r == _GLSL_ES1_NO_MEMORY) {
        return GLSL_ES1_R_FAILED;
      }
      if (r != _GLSL_ES1_FINISH) {
        return GLSL_ES1_R_HAVE_ERRORS;
      }
      return GLSL_ES1_R_OLD_INCLUDE;
    }
  } while (cr == GLSL_ES1_R_SUCCESS);

  return cr;
}

struct glsl_es1_compiler_mem_input_file {
  struct pp_input_file if_;
  const void *mem_;
  size_t memsize_;
};

static int glsl_es1_compiler_file_mem_input_request_callback(void *baton, struct pp_input_file *ifile) {
  struct glsl_es1_compiler_mem_input_file *mif = (struct glsl_es1_compiler_mem_input_file *)ifile;
  aex_if_set_input(ifile, mif->mem_, mif->memsize_, 1);
  return 0;
}

static struct pp_input_file *glsl_es1_compiler_push_input_file_mem(struct glsl_es1_compiler *cc, const char *filename, const void *mem, size_t memsize) {
  struct glsl_es1_compiler_mem_input_file *ifile;
  ifile = (struct glsl_es1_compiler_mem_input_file *)pp_push_input_file(&cc->pp_, filename, sizeof(struct glsl_es1_compiler_mem_input_file) - sizeof(struct pp_input_file));
  ifile->if_.input_request_fn_ = glsl_es1_compiler_file_mem_input_request_callback;
  ifile->mem_ = mem;
  ifile->memsize_ = memsize;
  return &ifile->if_;
}

static int glsl_es1_compiler_file_mem_snippet_input_request_callback(void *baton, struct pp_input_file *ifile) {
  struct glsl_es1_compiler_mem_input_file *mif = (struct glsl_es1_compiler_mem_input_file *)ifile;
  aex_if_set_input(ifile, mif->mem_, mif->memsize_, 1);
  return 0;
}

static struct pp_input_file *glsl_es1_compiler_push_input_file_mem_snippet(struct glsl_es1_compiler *cc, const char *filename, const void *mem, size_t memsize) {
  struct glsl_es1_compiler_mem_input_file *ifile;
  ifile = (struct glsl_es1_compiler_mem_input_file *)pp_push_input_file(&cc->pp_, filename, sizeof(struct glsl_es1_compiler_mem_input_file) - sizeof(struct pp_input_file));
  ifile->if_.input_request_fn_ = glsl_es1_compiler_file_mem_snippet_input_request_callback;
  ifile->mem_ = mem;
  ifile->memsize_ = memsize;
  return &ifile->if_;
}

enum glsl_es1_compiler_result glsl_es1_compile_builtin_prologue(struct glsl_es1_compiler *cc, const char *glsl_input_text) {
  enum glsl_es1_compiler_result cr;
  (void) glsl_es1_compiler_push_input_file_mem_snippet(cc, "(builtins)", glsl_input_text, strlen(glsl_input_text));
  cr = glsl_es1_compile(cc);
  if (cr != GLSL_ES1_R_OLD_INCLUDE) {
    dx_error(cc->dx_, "Failed parsing builtin: %s\n", glsl_input_text);
    return cr;
  }
  return GLSL_ES1_R_SUCCESS;
}

enum glsl_es1_compiler_result glsl_es1_compiler_compile_mem(struct glsl_es1_compiler *cc, const char *glsl_input_filename, const char *glsl_input_text, size_t glsl_input_text_len) {
  enum glsl_es1_compiler_result cr;

  /* Parse each of the builtin function prototypes */
  /* Notice that we rely on C string concatenation to append a little space, that space is important, the macro-expander
   * phase of the preprocessor will latch a token as a lookahead, consequently, we would not see the semicolon that ends the
   * prototype as a lookahead in the GLSL parser, and because of that, not reduce the function-prototype-decl non-terminal
   * in the grammar. Appending the space causes a whitespace token to be latched in the macro-expander, which is harmless and
   * helps flush through the semicolon so the behavior is as expected (we complete parsing the prototype and can rely on it
   * being the last function prototype parsed.) */
#define xx(proto, runtime_fn, eval_fn) , { proto " ", runtime_fn, eval_fn }
  struct {
    const char *prototype_;
    builtin_runtime_fn runtime_fn_;
    builtin_eval_fn eval_fn_;
  } proto_snippets[] = {
    { NULL }
#include "builtins_binding_inc.h"
  };
#undef xx

  size_t builtin_idx;
  int error_initializing = 0;;
  for (builtin_idx = 1; builtin_idx < (sizeof(proto_snippets)/sizeof(*proto_snippets)); ++builtin_idx) {
    (void) glsl_es1_compiler_push_input_file_mem_snippet(cc, "(builtins)", proto_snippets[builtin_idx].prototype_, strlen(proto_snippets[builtin_idx].prototype_));
    cr = glsl_es1_compile(cc);
    if (cr != GLSL_ES1_R_OLD_INCLUDE) {
      dx_error(cc->dx_, "Failed parsing builtin: %s\n", proto_snippets[builtin_idx]);
      return cr;
    }
    else if (cc->dx_->have_error_) {
      dx_error(cc->dx_, "Failed parsing builtin: %s\n", proto_snippets[builtin_idx]);
      /* Reset error to try and keep going and get a complete list of builtin parsing failures. */
      cc->dx_->have_error_ = 0;
      error_initializing = 1;
    }
    else {
      /* Last declaration emited is our function; attach the hardwired builtin functions to it */
      assert(cc->cu_->global_scope_.seq_);
      assert(cc->cu_->global_scope_.seq_->prev_->kind_ == SK_FUNCTION);
      struct sl_function *f = cc->cu_->global_scope_.seq_->prev_->v_.function_;
      assert(f);
      assert(!f->builtin_eval_fn_ && !f->builtin_runtime_fn_ && "builtins already set??");
      f->builtin_eval_fn_ = proto_snippets[builtin_idx].eval_fn_;
      f->builtin_runtime_fn_ = proto_snippets[builtin_idx].runtime_fn_;
    }
  }

  if (error_initializing) {
    /* Restore error flag */
    cc->dx_->have_error_ = 1;
    cc->dx_->fatal_error_ = 1;
    return GLSL_ES1_R_FAILED;
  }

  struct pp_input_file *ifile = glsl_es1_compiler_push_input_file_mem(cc, glsl_input_filename, glsl_input_text, glsl_input_text_len);
  if (!ifile) {
    dx_no_memory(cc->dx_);
    return GLSL_ES1_R_FAILED;
  }
  ifile->unpoppable_ = 1; /* never pop beyond toplevel input */

  cr = glsl_es1_compile(cc);
  if (cr != GLSL_ES1_R_SUCCESS) return cr;

  /* validate the call graph */
  int r = 0;
  struct sym *s = cc->cu_->global_scope_.seq_;
  if (s) {
    do {
      if (s->kind_ == SK_FUNCTION) {
        /* Keep going on error, we'd like to find all recursion problems */
        int rv = sl_function_call_graph_validation(cc->dx_, s->v_.function_);
        if (rv) r = rv;
      }

      s = s->next_;
    } while (s != cc->cu_->global_scope_.seq_);
    if (r) return GLSL_ES1_R_HAVE_ERRORS;
  }

  /* allocate registers for each individual frame (global and each function) */
  r = sl_frame_alloc_registers(&cc->cu_->global_frame_);
  if (r) return GLSL_ES1_R_FAILED;

  s = cc->cu_->global_scope_.seq_;
  if (s) {
    do {
      if (s->kind_ == SK_FUNCTION) {
        /* A symbol holds every overload of the name on a tail-cyclic chain;
         * each needs its own registers, not just the one the symbol points at. */
        struct sl_function *f = s->v_.function_;
        if (f) {
          do {
            f = f->overload_chain_;

            r = sl_function_alloc_registers(cc->tb_, f);
            if (r) return GLSL_ES1_R_FAILED;
          } while (f != s->v_.function_);
        }
      }

      s = s->next_;
    } while (s != cc->cu_->global_scope_.seq_);
  }

  struct sl_exec_call_graph_results cgr;
  sl_exec_call_graph_results_init(&cgr);

  s = cc->cu_->global_scope_.seq_;
  if (s) {
    do {
      if (s->kind_ == SK_FUNCTION) {
        /* As above: every overload on the chain contributes to the counts. */
        struct sl_function *f = s->v_.function_;
        if (f) {
          do {
            struct sl_exec_call_graph_results lcgr;
            f = f->overload_chain_;

            sl_exec_call_graph_results_init(&lcgr);

            r = sl_exec_call_graph_analysis(&lcgr, f);

            if (r) {
              sl_exec_call_graph_results_cleanup(&lcgr);
              sl_exec_call_graph_results_cleanup(&cgr);
              return GLSL_ES1_R_FAILED;
            }

            lcgr.num_float_regs_ += cc->cu_->global_frame_.ract_.rra_floats_.watermark_;
            lcgr.num_int_regs_ += cc->cu_->global_frame_.ract_.rra_ints_.watermark_;
            lcgr.num_bool_regs_ += cc->cu_->global_frame_.ract_.rra_bools_.watermark_;
            lcgr.num_sampler2D_regs_ += cc->cu_->global_frame_.ract_.rra_sampler2D_.watermark_;
            lcgr.num_samplerCube_regs_ += cc->cu_->global_frame_.ract_.rra_samplerCube_.watermark_;

            sl_exec_cgr_max(&cgr, &lcgr);
            sl_exec_call_graph_results_cleanup(&lcgr);
          } while (f != s->v_.function_);
        }
      }

      s = s->next_;
    } while (s != cc->cu_->global_scope_.seq_);
  }

  sl_exec_cgr_swap(&cc->cu_->register_counts_, &cgr);

  sl_exec_call_graph_results_cleanup(&cgr);
   

  return cc->dx_->have_error_ ? GLSL_ES1_R_HAVE_ERRORS : GLSL_ES1_R_SUCCESS;
}
