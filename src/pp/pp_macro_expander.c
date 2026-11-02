#line 1 "grammar/pp/pp_macro_expander.cbrt"
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

#ifndef STDINT_H_INCLUDED
#define STDINT_H_INCLUDED
#include <stdint.h>
#endif

#ifndef PP_H_INCLUDED
#define PP_H_INCLUDED
#include "pp.h"
#endif

#ifndef PP_TOKENS_H_INCLUDED
#define PP_TOKENS_H_INCLUDED
#include "pp_tokens.h"
#endif

/* --------- START OF GENERATED CODE ------------ */
#if defined(__clang__)
#elif defined(__GNUC__) && defined(__cplusplus)
/* don't warn on realloc, memcpy, memset on C++ classes */
#pragma GCC diagnostic ignored "-Wclass-memaccess"
#endif
#include <stdlib.h> /* realloc(), free(), NULL, size_t */
#include <string.h> /* memcpy() */
#include <stddef.h> /* size_t */
#include <stdint.h> /* SIZE_MAX */
struct aex_ppme_sym_data {
  #ifdef __cplusplus
  // clear destructor in case C++ symbol types have non-trivial destructors
  // (we invoke their destructors explicitly)
  ~aex_ppme_sym_data() = delete;
  #endif
  int state_;
  union {
    struct pptk * uv0_;
    struct { struct pptk *tk_; struct macro *m_; } uv1_;
    struct pptk * uv2_;
    struct macro_arg_inst * uv3_;
  } v_;
};
static const int aex_ppme_minimum_sym = 3;
static const size_t aex_ppme_num_columns = 21;
static const int aex_ppme_parse_table[] = {
   -3, -3, -3, -3, -3, -3, -3, -3, -3, 0, -3, 0,57, 1, 0, 0, 0, 0, 0, 0, 0,
    0,  0,  0,  0,  0,  0,  0,  0,  0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   -4, -4, -4, -4, -4, -4, -4, -4, -4, 0, -4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   -5, -5, -5, -5, -5, -5, -5, -5, -5, 0, -5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   -7, -7, -7, -7, -7, -7, -7, -7, -7, 0, -7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   -8, -8, -8, -8, -8, -8, -8, -8, -8, 0, -8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   -9, -9, -9, -9, -9, -9, -9, -9, -9, 0, -9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   10, 12, 11,  0, 26,-22,-22, 13, 14, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  -23,-23,-23,  0,-23,-23,-23,-23,-23, 0,  0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0,
    0,  0,  0,  0,  0,  6,  8,  0,  0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  -24,-24,-24,  0,-24,-24,-24,-24,-24, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  -25,-25,-25,  0,-25,-25,-25,-25,-25, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  -26,-26,-26,  0,-26,-26,-26,-26,-26, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  -27,-27,-27,  0,-27,-27,-27,-27,-27, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  -28,-28,-28,  0,-28,-28,-28,-28,-28, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  -29,-29,-29,  0,-29,-29,-29,-29,-29, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  -31,-31,-31,  0,-31,-31,-31,-31,-31, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  -32,-32,-32,  0,-32,-32,-32,-32,-32, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  -33,-33,-33,  0,-33,-33,-33,-33,-33, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  -34,-34,-34,  0,-34,-34,-34,-34,-34, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  -35,-35,-35,  0,-35,-35,-35,-35,-35, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  -36,-36,-36,  0,-36,-36,-36,-36,-36, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  -37,-37,-37,  0,-37,-37,-37,-37,-37, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   16, 18, 17,  0, 24, 22, 19, 20, 21, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  -30,-30,-30,  0,-30,-30,-30,-30,-30, 0,  0, 0, 0, 0, 0, 0, 0,23, 0, 0, 0,
   16, 18, 17,  0, 24, 15, 19, 20, 21, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  -30,-30,-30,  0,-30,-30,-30,-30,-30, 0,  0, 0, 0, 0, 0, 0, 0,25, 0, 0, 0,
   10, 12, 11,  0, 26,-21,-21, 13, 14, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  -23,-23,-23,  0,-23,-23,-23,-23,-23, 0,  0, 0, 0, 0, 0, 0, 0, 0,27, 9, 0,
  -20,-20,-20,-20, 28,-20,-20, 50,-20, 0,-20, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  -40,-40,-40,-40,-40,-40,-40,-40,-40, 0,-40, 0, 0, 0, 0,29, 0, 0, 0, 0, 0,
  -10,-10,-10,-10,-10,-10,-10,-10,-10, 0,-10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  -11,-11,-11,-11,-11,-11,-11,-11,-11, 0,-11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0,  0,  0,  0,  0, 32,  0, 50,  0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0,  0,  0,  0,  0,-40,  0,-40,  0, 0,  0, 0, 0, 0, 0,33, 0, 0, 0, 0, 0,
  -12,-12,-12,-12,-12,-12,-12,-12,-12, 0,-12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0,  0,  0,  0,  0, 35,  0, 50,  0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0,  0,  0,  0,  0,-40,  0,-40,  0, 0,  0, 0, 0, 0, 0,36, 0, 0, 0, 0, 0,
  -13,-13,-13,-13,-13,-13,-13,-13,-13, 0,-13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0,  0,  0,  0,  0, 38,  0, 50,  0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0,  0,  0,  0,  0,-40,  0,-40,  0, 0,  0, 0, 0, 0, 0,39, 0, 0, 0, 0, 0,
  -14,-14,-14,-14,-14,-14,-14,-14,-14, 0,-14, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0,  0,  0,  0,  0, 41,  0, 50,  0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0,  0,  0,  0,  0,-40,  0,-40,  0, 0,  0, 0, 0, 0, 0,42, 0, 0, 0, 0, 0,
   34, 40, 37, 43,  0,  0,  0, 50,  0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  -40,-40,-40,-40,  0,  0,  0,-40,  0, 0,  0, 0, 0, 0, 0,44, 0, 0, 0, 0, 0,
  -15,-15,-15,-15,-15,-15,-15,-15,-15, 0,-15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  -16,-16,-16,-16,-16,-16,-16,-16,-16, 0,-16, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  -17,-17,-17,-17,-17,-17,-17,-17,-17, 0,-17, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  -18,-18,-18,-18,-18,-18,-18,-18,-18, 0,-18, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  -41,-41,-41,-41,-41,-41,-41,-41,-41, 0,-41, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   46, 48, 47, 49, 45,  0,  0, 50,  0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  -40,-40,-40,-40,-40,  0,  0,-40,  0, 0,  0, 0, 0, 0, 0,51, 0, 0, 0, 0, 0,
    2, 31, 30, 52,  0,  4,  3,  0,  5, 0, -2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   -6, -6, -6, -6, -6, -6, -6, -6, -6, 0, -6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  -39,-39,-39,-39,-39,-39,-39,-39,-39, 0,-39, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  -19,-19,-19,-19, 54,-19,-19, 55,-19, 0,-19, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  -38,-38,-38,-38,-38,-38,-38,-38,-38, 0,-38,53, 0, 0, 0, 0,56, 0, 0, 0, 0,
};
static const size_t aex_ppme_production_lengths[] = {
  1,
  2,
  0,
  3,
  3,
  3,
  3,
  3,
  7,
  3,
  9,
  9,
  9,
  9,
  5,
  5,
  5,
  5,
  1,
  3,
  1,
  3,
  0,
  2,
  2,
  2,
  2,
  2,
  4,
  0,
  2,
  2,
  2,
  2,
  2,
  2,
  4,
  0,
  2,
  0,
  2
};
static const int aex_ppme_production_syms[] = {
  23,
  16,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  15,
  14,
  14,
  22,
  22,
  21,
  21,
  21,
  21,
  21,
  21,
  21,
  20,
  20,
  20,
  20,
  20,
  20,
  20,
  20,
  19,
  19,
  18,
  18
};

#ifndef CARB_AEX_PPME_SRCPPPP_MACRO_EXPANDER_H_INCLUDED
struct aex_ppme_stack {
  int error_recovery_:1;
  int pending_reset_:1;
  int discard_remaining_actions_:1;
  int slot_1_has_sym_data_:1;
  int slot_1_has_common_data_:1;
  int top_of_stack_has_sym_data_:1;
  int top_of_stack_has_common_data_:1;
  int newbuf_pos_has_common_data_:1;
  int newbuf_pos_has_sym_data_:1;
  int stack_newbuf_pos_has_common_data_:1;
  int stack_newbuf_pos_has_sym_data_:1;
  int action_preservation_;
  int current_err_action_;
  int slot_1_sym_;
  int continue_at_;
  int mute_error_turns_;
  size_t pos_, num_stack_allocated_;
  struct aex_ppme_sym_data *stack_;
  struct aex_ppme_sym_data *sym_data_;
  struct aex_ppme_sym_data *new_buf_;
  size_t new_buf_num_allocated_;
  size_t new_buf_sym_partial_pos_;
  size_t current_production_length_;
  int current_production_nonterminal_;
  size_t sym_idx_;
};
#define _AEX_PPME_FINISH 0
#define _AEX_PPME_MATCH 1
#define _AEX_PPME_OVERFLOW 2
#define _AEX_PPME_NO_MEMORY 3
#define _AEX_PPME_FEED_ME 4
#define _AEX_PPME_END_OF_INPUT 5
#define _AEX_PPME_SYNTAX_ERROR 6
#define _AEX_PPME_LEXICAL_ERROR 7
#define _AEX_PPME_INTERNAL_ERROR 8

#define AEX_PPME_IDENT 3
#define AEX_PPME_OBJECT 4
#define AEX_PPME_FUNCTION 5
#define AEX_PPME_DEFINED 6
#define AEX_PPME_PAR_OPEN 7
#define AEX_PPME_PAR_CLOSE 8
#define AEX_PPME_COMMA 9
#define AEX_PPME_WS_TOK 10
#define AEX_PPME_OTHER 11
#define AEX_PPME_ERROR 12
#define AEX_PPME_INPUT_END 13

#define AEX_PPME_OPT_FUNCTION_SEQ 14
#define AEX_PPME_TOP_STREAM 15
#define AEX_PPME_TOTAL 16
#define AEX_PPME_NON_FUNCTION 17
#define AEX_PPME_WS_OPT 18
#define AEX_PPME_WS_OPT_EMIT 19
#define AEX_PPME_PAR_SPAN 20
#define AEX_PPME_ARG 21
#define AEX_PPME_ARGS 22


#endif /* CARB_AEX_PPME_SRCPPPP_MACRO_EXPANDER_H_INCLUDED */

void aex_ppme_stack_init(struct aex_ppme_stack *stack) {
  stack->error_recovery_ = 0;
  stack->pending_reset_ = 1;
  stack->discard_remaining_actions_ = 0;
  stack->slot_1_has_sym_data_ = stack->slot_1_has_common_data_ = 0;
  stack->slot_1_sym_ = 0;
  stack->top_of_stack_has_sym_data_ = stack->top_of_stack_has_common_data_ = 0;
  stack->newbuf_pos_has_common_data_ = stack->newbuf_pos_has_sym_data_ = 0;
  stack->stack_newbuf_pos_has_common_data_ = stack->stack_newbuf_pos_has_sym_data_ = 0;
  stack->continue_at_ = 0;
  stack->mute_error_turns_ = 0;
  stack->pos_ = 0;
  stack->num_stack_allocated_ = 0;
  stack->stack_ = NULL;
  stack->sym_data_ = NULL;
  stack->new_buf_ = NULL;
  stack->new_buf_num_allocated_ = 0;
  stack->new_buf_sym_partial_pos_ = 0;
  stack->current_production_length_ = 0;
  stack->current_production_nonterminal_ = 0;
  stack->sym_idx_ = 0;
}

void aex_ppme_stack_cleanup(struct aex_ppme_stack *stack) {
  size_t n;
  if (!stack->new_buf_) n = 0;
  else {
    n = stack->new_buf_sym_partial_pos_;
  }
  for (; n < stack->pos_; ++n) {
    int need_state_deconstruct = 0;
    if ((n == 0) || (n == 1)) {
      int need_sym_deconstruct = 0;
      int sym_to_deconstruct;
      need_state_deconstruct = 0;
      if (n == 0) {
        /* slot 0 goes unused in scannerless operation */
        need_sym_deconstruct = 0;
      }
      else if (n == 1) {
        sym_to_deconstruct = stack->slot_1_sym_;
        need_sym_deconstruct = stack->slot_1_has_sym_data_;
      }
      if (stack->new_buf_ && (n == stack->new_buf_sym_partial_pos_)) {
        need_sym_deconstruct = need_sym_deconstruct && stack->stack_newbuf_pos_has_sym_data_;
      }
      if (need_sym_deconstruct) {
        switch (sym_to_deconstruct) {
          case AEX_PPME_IDENT:
          case AEX_PPME_DEFINED:
          case AEX_PPME_PAR_OPEN:
          case AEX_PPME_PAR_CLOSE:
          case AEX_PPME_COMMA:
          case AEX_PPME_WS_TOK:
          case AEX_PPME_OTHER:
          {
            {
#line 70 "grammar/pp/pp_macro_expander.cbrt"
              aex_pptk_free(((stack->stack_ + n)->v_.uv0_));
#line 333 "src/pp/pp_macro_expander.c"
            }
            
          }
          break;
          case AEX_PPME_OBJECT:
          case AEX_PPME_FUNCTION:
          {
            {
#line 77 "grammar/pp/pp_macro_expander.cbrt"
              aex_pptk_free(((stack->stack_ + n)->v_.uv1_).tk_); aex_macro_free(((stack->stack_ + n)->v_.uv1_).m_); /* Reduction of OBJECT drops a reference and might free the macro */
#line 344 "src/pp/pp_macro_expander.c"
            }
            
          }
          break;
          case AEX_PPME_NON_FUNCTION:
          case AEX_PPME_WS_OPT:
          case AEX_PPME_PAR_SPAN:
          case AEX_PPME_ARG:
          {
            {
#line 97 "grammar/pp/pp_macro_expander.cbrt"
              aex_pptk_free(((stack->stack_ + n)->v_.uv2_));
#line 357 "src/pp/pp_macro_expander.c"
            }
            
          }
          break;
          case AEX_PPME_ARGS:
          {
            {
#line 103 "grammar/pp/pp_macro_expander.cbrt"
              aex_macro_arg_inst_free(((stack->stack_ + n)->v_.uv3_));
#line 367 "src/pp/pp_macro_expander.c"
            }
            
          }
          break;
        }
      }
    }
    else if (n == (stack->pos_ - 1)) {
      need_state_deconstruct = stack->top_of_stack_has_sym_data_;
      if (n == stack->new_buf_sym_partial_pos_) {
        need_state_deconstruct = need_state_deconstruct && stack->stack_newbuf_pos_has_sym_data_;
      }
    }
    else if (stack->new_buf_ && (n == stack->new_buf_sym_partial_pos_)) {
      need_state_deconstruct = stack->stack_newbuf_pos_has_sym_data_;
    }
    else {
      need_state_deconstruct = 1;
    }
    if (need_state_deconstruct) {
      switch (stack->stack_[n].state_) {
        case 2: /* IDENT */
        case 3: /* COMMA */
        case 4: /* PAR_CLOSE */
        case 5: /* OTHER */
        case 6: /* PAR_CLOSE */
        case 8: /* COMMA */
        case 10: /* IDENT */
        case 13: /* WS_TOK */
        case 14: /* OTHER */
        case 15: /* PAR_CLOSE */
        case 16: /* IDENT */
        case 19: /* COMMA */
        case 20: /* WS_TOK */
        case 21: /* OTHER */
        case 22: /* PAR_CLOSE */
        case 24: /* PAR_OPEN */
        case 26: /* PAR_OPEN */
        case 28: /* PAR_OPEN */
        case 32: /* PAR_CLOSE */
        case 34: /* IDENT */
        case 35: /* PAR_CLOSE */
        case 38: /* PAR_CLOSE */
        case 41: /* PAR_CLOSE */
        case 43: /* DEFINED */
        case 45: /* PAR_OPEN */
        case 46: /* IDENT */
        case 49: /* DEFINED */
        case 50: /* WS_TOK */
        case 52: /* DEFINED */
        case 54: /* PAR_OPEN */
        case 55: /* WS_TOK */
        {
          {
#line 70 "grammar/pp/pp_macro_expander.cbrt"
            aex_pptk_free(((stack->stack_ + n)->v_.uv0_));
#line 424 "src/pp/pp_macro_expander.c"
          }
          
        }
        break;
        case 11: /* FUNCTION */
        case 12: /* OBJECT */
        case 17: /* FUNCTION */
        case 18: /* OBJECT */
        case 30: /* FUNCTION */
        case 31: /* OBJECT */
        case 37: /* FUNCTION */
        case 40: /* OBJECT */
        case 47: /* FUNCTION */
        case 48: /* OBJECT */
        {
          {
#line 77 "grammar/pp/pp_macro_expander.cbrt"
            aex_pptk_free(((stack->stack_ + n)->v_.uv1_).tk_); aex_macro_free(((stack->stack_ + n)->v_.uv1_).m_); /* Reduction of OBJECT drops a reference and might free the macro */
#line 443 "src/pp/pp_macro_expander.c"
          }
          
        }
        break;
        case 7: /* arg */
        case 23: /* par-span */
        case 25: /* par-span */
        case 27: /* arg */
        case 29: /* ws-opt */
        case 33: /* ws-opt */
        case 36: /* ws-opt */
        case 39: /* ws-opt */
        case 42: /* ws-opt */
        case 44: /* ws-opt */
        case 51: /* ws-opt */
        {
          {
#line 97 "grammar/pp/pp_macro_expander.cbrt"
            aex_pptk_free(((stack->stack_ + n)->v_.uv2_));
#line 463 "src/pp/pp_macro_expander.c"
          }
          
        }
        break;
        case 9: /* args */
        {
          {
#line 103 "grammar/pp/pp_macro_expander.cbrt"
            aex_macro_arg_inst_free(((stack->stack_ + n)->v_.uv3_));
#line 473 "src/pp/pp_macro_expander.c"
          }
          
        }
        break;
      } /* switch */
    }
  }
  if (stack->new_buf_) {
    /* same deconstructors as above, but now for stack->new_buf_ -- stack->new_buf_ only
    * exists for a brief period time when we resize stack->stack_, however, because
    * constructors and moves are allowed to throw, or otherwise return and fail, it is
    * required that we deconstruct the stack->new_buf_ elements cleanly. */
    for (n = 0; n <= stack->new_buf_sym_partial_pos_; ++n) {
      int need_state_deconstruct = 0;
      if ((n == 0) || (n == 1)) {
        int need_sym_deconstruct = 0;
        int sym_to_deconstruct;
        need_state_deconstruct = 0;
        if (n == 0) {
          /* slot 0 goes unused in scannerless operation */
          need_sym_deconstruct = 0;
        }
        else if (n == 1) {
          sym_to_deconstruct = stack->slot_1_sym_;
          need_sym_deconstruct = stack->slot_1_has_sym_data_;
        }
        if (n == stack->new_buf_sym_partial_pos_) {
          need_sym_deconstruct = need_sym_deconstruct && stack->newbuf_pos_has_sym_data_;
        }
        if (need_sym_deconstruct) {
          switch (sym_to_deconstruct) {
            case AEX_PPME_IDENT:
            case AEX_PPME_DEFINED:
            case AEX_PPME_PAR_OPEN:
            case AEX_PPME_PAR_CLOSE:
            case AEX_PPME_COMMA:
            case AEX_PPME_WS_TOK:
            case AEX_PPME_OTHER:
            {
              {
#line 70 "grammar/pp/pp_macro_expander.cbrt"
                aex_pptk_free(((stack->new_buf_ + n)->v_.uv0_));
#line 516 "src/pp/pp_macro_expander.c"
              }
              
            }
            break;
            case AEX_PPME_OBJECT:
            case AEX_PPME_FUNCTION:
            {
              {
#line 77 "grammar/pp/pp_macro_expander.cbrt"
                aex_pptk_free(((stack->new_buf_ + n)->v_.uv1_).tk_); aex_macro_free(((stack->new_buf_ + n)->v_.uv1_).m_); /* Reduction of OBJECT drops a reference and might free the macro */
#line 527 "src/pp/pp_macro_expander.c"
              }
              
            }
            break;
            case AEX_PPME_NON_FUNCTION:
            case AEX_PPME_WS_OPT:
            case AEX_PPME_PAR_SPAN:
            case AEX_PPME_ARG:
            {
              {
#line 97 "grammar/pp/pp_macro_expander.cbrt"
                aex_pptk_free(((stack->new_buf_ + n)->v_.uv2_));
#line 540 "src/pp/pp_macro_expander.c"
              }
              
            }
            break;
            case AEX_PPME_ARGS:
            {
              {
#line 103 "grammar/pp/pp_macro_expander.cbrt"
                aex_macro_arg_inst_free(((stack->new_buf_ + n)->v_.uv3_));
#line 550 "src/pp/pp_macro_expander.c"
              }
              
            }
            break;
          }
        }
      }
      else if (n == (stack->pos_ - 1)) {
        need_state_deconstruct = stack->top_of_stack_has_sym_data_;
        if (n == stack->new_buf_sym_partial_pos_) {
          need_state_deconstruct = need_state_deconstruct && stack->newbuf_pos_has_sym_data_;
        }
      }
      else if (n == stack->new_buf_sym_partial_pos_) {
        need_state_deconstruct = stack->newbuf_pos_has_sym_data_;
      }
      else {
        need_state_deconstruct = 1;
      }
      if (need_state_deconstruct) {
        switch (stack->stack_[n].state_) {
          case 2: /* IDENT */
          case 3: /* COMMA */
          case 4: /* PAR_CLOSE */
          case 5: /* OTHER */
          case 6: /* PAR_CLOSE */
          case 8: /* COMMA */
          case 10: /* IDENT */
          case 13: /* WS_TOK */
          case 14: /* OTHER */
          case 15: /* PAR_CLOSE */
          case 16: /* IDENT */
          case 19: /* COMMA */
          case 20: /* WS_TOK */
          case 21: /* OTHER */
          case 22: /* PAR_CLOSE */
          case 24: /* PAR_OPEN */
          case 26: /* PAR_OPEN */
          case 28: /* PAR_OPEN */
          case 32: /* PAR_CLOSE */
          case 34: /* IDENT */
          case 35: /* PAR_CLOSE */
          case 38: /* PAR_CLOSE */
          case 41: /* PAR_CLOSE */
          case 43: /* DEFINED */
          case 45: /* PAR_OPEN */
          case 46: /* IDENT */
          case 49: /* DEFINED */
          case 50: /* WS_TOK */
          case 52: /* DEFINED */
          case 54: /* PAR_OPEN */
          case 55: /* WS_TOK */
          {
            {
#line 70 "grammar/pp/pp_macro_expander.cbrt"
              aex_pptk_free(((stack->new_buf_ + n)->v_.uv0_));
#line 607 "src/pp/pp_macro_expander.c"
            }
            
          }
          break;
          case 11: /* FUNCTION */
          case 12: /* OBJECT */
          case 17: /* FUNCTION */
          case 18: /* OBJECT */
          case 30: /* FUNCTION */
          case 31: /* OBJECT */
          case 37: /* FUNCTION */
          case 40: /* OBJECT */
          case 47: /* FUNCTION */
          case 48: /* OBJECT */
          {
            {
#line 77 "grammar/pp/pp_macro_expander.cbrt"
              aex_pptk_free(((stack->new_buf_ + n)->v_.uv1_).tk_); aex_macro_free(((stack->new_buf_ + n)->v_.uv1_).m_); /* Reduction of OBJECT drops a reference and might free the macro */
#line 626 "src/pp/pp_macro_expander.c"
            }
            
          }
          break;
          case 7: /* arg */
          case 23: /* par-span */
          case 25: /* par-span */
          case 27: /* arg */
          case 29: /* ws-opt */
          case 33: /* ws-opt */
          case 36: /* ws-opt */
          case 39: /* ws-opt */
          case 42: /* ws-opt */
          case 44: /* ws-opt */
          case 51: /* ws-opt */
          {
            {
#line 97 "grammar/pp/pp_macro_expander.cbrt"
              aex_pptk_free(((stack->new_buf_ + n)->v_.uv2_));
#line 646 "src/pp/pp_macro_expander.c"
            }
            
          }
          break;
          case 9: /* args */
          {
            {
#line 103 "grammar/pp/pp_macro_expander.cbrt"
              aex_macro_arg_inst_free(((stack->new_buf_ + n)->v_.uv3_));
#line 656 "src/pp/pp_macro_expander.c"
            }
            
          }
          break;
        } /* switch */
      }
    }
    free(stack->new_buf_);
    stack->new_buf_ = NULL;
  }
  if (stack->stack_) free(stack->stack_);
}

int aex_ppme_stack_reset(struct aex_ppme_stack *stack) {
  stack->pending_reset_ = 0;
  stack->discard_remaining_actions_ = 0;
  size_t n;
  if (!stack->new_buf_) n = 0;
  else {
    n = stack->new_buf_sym_partial_pos_;
  }
  for (; n < stack->pos_; ++n) {
    int need_state_deconstruct = 0;
    if ((n == 0) || (n == 1)) {
      int need_sym_deconstruct = 0;
      int sym_to_deconstruct;
      need_state_deconstruct = 0;
      if (n == 0) {
        /* slot 0 goes unused in scannerless operation */
        need_sym_deconstruct = 0;
      }
      else if (n == 1) {
        sym_to_deconstruct = stack->slot_1_sym_;
        need_sym_deconstruct = stack->slot_1_has_sym_data_;
      }
      if (stack->new_buf_ && (n == stack->new_buf_sym_partial_pos_)) {
        need_sym_deconstruct = need_sym_deconstruct && stack->stack_newbuf_pos_has_sym_data_;
      }
      if (need_sym_deconstruct) {
        switch (sym_to_deconstruct) {
          case AEX_PPME_IDENT:
          case AEX_PPME_DEFINED:
          case AEX_PPME_PAR_OPEN:
          case AEX_PPME_PAR_CLOSE:
          case AEX_PPME_COMMA:
          case AEX_PPME_WS_TOK:
          case AEX_PPME_OTHER:
          {
            {
#line 70 "grammar/pp/pp_macro_expander.cbrt"
              aex_pptk_free(((stack->stack_ + n)->v_.uv0_));
#line 708 "src/pp/pp_macro_expander.c"
            }
            
          }
          break;
          case AEX_PPME_OBJECT:
          case AEX_PPME_FUNCTION:
          {
            {
#line 77 "grammar/pp/pp_macro_expander.cbrt"
              aex_pptk_free(((stack->stack_ + n)->v_.uv1_).tk_); aex_macro_free(((stack->stack_ + n)->v_.uv1_).m_); /* Reduction of OBJECT drops a reference and might free the macro */
#line 719 "src/pp/pp_macro_expander.c"
            }
            
          }
          break;
          case AEX_PPME_NON_FUNCTION:
          case AEX_PPME_WS_OPT:
          case AEX_PPME_PAR_SPAN:
          case AEX_PPME_ARG:
          {
            {
#line 97 "grammar/pp/pp_macro_expander.cbrt"
              aex_pptk_free(((stack->stack_ + n)->v_.uv2_));
#line 732 "src/pp/pp_macro_expander.c"
            }
            
          }
          break;
          case AEX_PPME_ARGS:
          {
            {
#line 103 "grammar/pp/pp_macro_expander.cbrt"
              aex_macro_arg_inst_free(((stack->stack_ + n)->v_.uv3_));
#line 742 "src/pp/pp_macro_expander.c"
            }
            
          }
          break;
        }
      }
    }
    else if (n == (stack->pos_ - 1)) {
      need_state_deconstruct = stack->top_of_stack_has_sym_data_;
      if (n == stack->new_buf_sym_partial_pos_) {
        need_state_deconstruct = need_state_deconstruct && stack->stack_newbuf_pos_has_sym_data_;
      }
    }
    else if (stack->new_buf_ && (n == stack->new_buf_sym_partial_pos_)) {
      need_state_deconstruct = stack->stack_newbuf_pos_has_sym_data_;
    }
    else {
      need_state_deconstruct = 1;
    }
    if (need_state_deconstruct) {
      switch (stack->stack_[n].state_) {
        case 2: /* IDENT */
        case 3: /* COMMA */
        case 4: /* PAR_CLOSE */
        case 5: /* OTHER */
        case 6: /* PAR_CLOSE */
        case 8: /* COMMA */
        case 10: /* IDENT */
        case 13: /* WS_TOK */
        case 14: /* OTHER */
        case 15: /* PAR_CLOSE */
        case 16: /* IDENT */
        case 19: /* COMMA */
        case 20: /* WS_TOK */
        case 21: /* OTHER */
        case 22: /* PAR_CLOSE */
        case 24: /* PAR_OPEN */
        case 26: /* PAR_OPEN */
        case 28: /* PAR_OPEN */
        case 32: /* PAR_CLOSE */
        case 34: /* IDENT */
        case 35: /* PAR_CLOSE */
        case 38: /* PAR_CLOSE */
        case 41: /* PAR_CLOSE */
        case 43: /* DEFINED */
        case 45: /* PAR_OPEN */
        case 46: /* IDENT */
        case 49: /* DEFINED */
        case 50: /* WS_TOK */
        case 52: /* DEFINED */
        case 54: /* PAR_OPEN */
        case 55: /* WS_TOK */
        {
          {
#line 70 "grammar/pp/pp_macro_expander.cbrt"
            aex_pptk_free(((stack->stack_ + n)->v_.uv0_));
#line 799 "src/pp/pp_macro_expander.c"
          }
          
        }
        break;
        case 11: /* FUNCTION */
        case 12: /* OBJECT */
        case 17: /* FUNCTION */
        case 18: /* OBJECT */
        case 30: /* FUNCTION */
        case 31: /* OBJECT */
        case 37: /* FUNCTION */
        case 40: /* OBJECT */
        case 47: /* FUNCTION */
        case 48: /* OBJECT */
        {
          {
#line 77 "grammar/pp/pp_macro_expander.cbrt"
            aex_pptk_free(((stack->stack_ + n)->v_.uv1_).tk_); aex_macro_free(((stack->stack_ + n)->v_.uv1_).m_); /* Reduction of OBJECT drops a reference and might free the macro */
#line 818 "src/pp/pp_macro_expander.c"
          }
          
        }
        break;
        case 7: /* arg */
        case 23: /* par-span */
        case 25: /* par-span */
        case 27: /* arg */
        case 29: /* ws-opt */
        case 33: /* ws-opt */
        case 36: /* ws-opt */
        case 39: /* ws-opt */
        case 42: /* ws-opt */
        case 44: /* ws-opt */
        case 51: /* ws-opt */
        {
          {
#line 97 "grammar/pp/pp_macro_expander.cbrt"
            aex_pptk_free(((stack->stack_ + n)->v_.uv2_));
#line 838 "src/pp/pp_macro_expander.c"
          }
          
        }
        break;
        case 9: /* args */
        {
          {
#line 103 "grammar/pp/pp_macro_expander.cbrt"
            aex_macro_arg_inst_free(((stack->stack_ + n)->v_.uv3_));
#line 848 "src/pp/pp_macro_expander.c"
          }
          
        }
        break;
      } /* switch */
    }
  }
  if (stack->new_buf_) {
    /* same deconstructors as above, but now for stack->new_buf_ -- stack->new_buf_ only
    * exists for a brief period time when we resize stack->stack_, however, because
    * constructors and moves are allowed to throw, or otherwise return and fail, it is
    * required that we deconstruct the stack->new_buf_ elements cleanly. */
    for (n = 0; n <= stack->new_buf_sym_partial_pos_; ++n) {
      int need_state_deconstruct = 0;
      if ((n == 0) || (n == 1)) {
        int need_sym_deconstruct = 0;
        int sym_to_deconstruct;
        need_state_deconstruct = 0;
        if (n == 0) {
          /* slot 0 goes unused in scannerless operation */
          need_sym_deconstruct = 0;
        }
        else if (n == 1) {
          sym_to_deconstruct = stack->slot_1_sym_;
          need_sym_deconstruct = stack->slot_1_has_sym_data_;
        }
        if (n == stack->new_buf_sym_partial_pos_) {
          need_sym_deconstruct = need_sym_deconstruct && stack->newbuf_pos_has_sym_data_;
        }
        if (need_sym_deconstruct) {
          switch (sym_to_deconstruct) {
            case AEX_PPME_IDENT:
            case AEX_PPME_DEFINED:
            case AEX_PPME_PAR_OPEN:
            case AEX_PPME_PAR_CLOSE:
            case AEX_PPME_COMMA:
            case AEX_PPME_WS_TOK:
            case AEX_PPME_OTHER:
            {
              {
#line 70 "grammar/pp/pp_macro_expander.cbrt"
                aex_pptk_free(((stack->new_buf_ + n)->v_.uv0_));
#line 891 "src/pp/pp_macro_expander.c"
              }
              
            }
            break;
            case AEX_PPME_OBJECT:
            case AEX_PPME_FUNCTION:
            {
              {
#line 77 "grammar/pp/pp_macro_expander.cbrt"
                aex_pptk_free(((stack->new_buf_ + n)->v_.uv1_).tk_); aex_macro_free(((stack->new_buf_ + n)->v_.uv1_).m_); /* Reduction of OBJECT drops a reference and might free the macro */
#line 902 "src/pp/pp_macro_expander.c"
              }
              
            }
            break;
            case AEX_PPME_NON_FUNCTION:
            case AEX_PPME_WS_OPT:
            case AEX_PPME_PAR_SPAN:
            case AEX_PPME_ARG:
            {
              {
#line 97 "grammar/pp/pp_macro_expander.cbrt"
                aex_pptk_free(((stack->new_buf_ + n)->v_.uv2_));
#line 915 "src/pp/pp_macro_expander.c"
              }
              
            }
            break;
            case AEX_PPME_ARGS:
            {
              {
#line 103 "grammar/pp/pp_macro_expander.cbrt"
                aex_macro_arg_inst_free(((stack->new_buf_ + n)->v_.uv3_));
#line 925 "src/pp/pp_macro_expander.c"
              }
              
            }
            break;
          }
        }
      }
      else if (n == (stack->pos_ - 1)) {
        need_state_deconstruct = stack->top_of_stack_has_sym_data_;
        if (n == stack->new_buf_sym_partial_pos_) {
          need_state_deconstruct = need_state_deconstruct && stack->newbuf_pos_has_sym_data_;
        }
      }
      else if (n == stack->new_buf_sym_partial_pos_) {
        need_state_deconstruct = stack->newbuf_pos_has_sym_data_;
      }
      else {
        need_state_deconstruct = 1;
      }
      if (need_state_deconstruct) {
        switch (stack->stack_[n].state_) {
          case 2: /* IDENT */
          case 3: /* COMMA */
          case 4: /* PAR_CLOSE */
          case 5: /* OTHER */
          case 6: /* PAR_CLOSE */
          case 8: /* COMMA */
          case 10: /* IDENT */
          case 13: /* WS_TOK */
          case 14: /* OTHER */
          case 15: /* PAR_CLOSE */
          case 16: /* IDENT */
          case 19: /* COMMA */
          case 20: /* WS_TOK */
          case 21: /* OTHER */
          case 22: /* PAR_CLOSE */
          case 24: /* PAR_OPEN */
          case 26: /* PAR_OPEN */
          case 28: /* PAR_OPEN */
          case 32: /* PAR_CLOSE */
          case 34: /* IDENT */
          case 35: /* PAR_CLOSE */
          case 38: /* PAR_CLOSE */
          case 41: /* PAR_CLOSE */
          case 43: /* DEFINED */
          case 45: /* PAR_OPEN */
          case 46: /* IDENT */
          case 49: /* DEFINED */
          case 50: /* WS_TOK */
          case 52: /* DEFINED */
          case 54: /* PAR_OPEN */
          case 55: /* WS_TOK */
          {
            {
#line 70 "grammar/pp/pp_macro_expander.cbrt"
              aex_pptk_free(((stack->new_buf_ + n)->v_.uv0_));
#line 982 "src/pp/pp_macro_expander.c"
            }
            
          }
          break;
          case 11: /* FUNCTION */
          case 12: /* OBJECT */
          case 17: /* FUNCTION */
          case 18: /* OBJECT */
          case 30: /* FUNCTION */
          case 31: /* OBJECT */
          case 37: /* FUNCTION */
          case 40: /* OBJECT */
          case 47: /* FUNCTION */
          case 48: /* OBJECT */
          {
            {
#line 77 "grammar/pp/pp_macro_expander.cbrt"
              aex_pptk_free(((stack->new_buf_ + n)->v_.uv1_).tk_); aex_macro_free(((stack->new_buf_ + n)->v_.uv1_).m_); /* Reduction of OBJECT drops a reference and might free the macro */
#line 1001 "src/pp/pp_macro_expander.c"
            }
            
          }
          break;
          case 7: /* arg */
          case 23: /* par-span */
          case 25: /* par-span */
          case 27: /* arg */
          case 29: /* ws-opt */
          case 33: /* ws-opt */
          case 36: /* ws-opt */
          case 39: /* ws-opt */
          case 42: /* ws-opt */
          case 44: /* ws-opt */
          case 51: /* ws-opt */
          {
            {
#line 97 "grammar/pp/pp_macro_expander.cbrt"
              aex_pptk_free(((stack->new_buf_ + n)->v_.uv2_));
#line 1021 "src/pp/pp_macro_expander.c"
            }
            
          }
          break;
          case 9: /* args */
          {
            {
#line 103 "grammar/pp/pp_macro_expander.cbrt"
              aex_macro_arg_inst_free(((stack->new_buf_ + n)->v_.uv3_));
#line 1031 "src/pp/pp_macro_expander.c"
            }
            
          }
          break;
        } /* switch */
      }
    }
    free(stack->new_buf_);
    stack->new_buf_ = NULL;
  }
  stack->slot_1_has_sym_data_ = stack->slot_1_has_common_data_ = 0;
  stack->slot_1_sym_ = 0;
  stack->top_of_stack_has_sym_data_ = 0;
  stack->top_of_stack_has_common_data_ = 0;
  stack->newbuf_pos_has_common_data_ = stack->newbuf_pos_has_sym_data_ = 0;
  stack->stack_newbuf_pos_has_common_data_ = stack->stack_newbuf_pos_has_sym_data_ = 0;
  stack->sym_data_ = NULL;
  stack->current_production_length_ = 0;
  stack->current_production_nonterminal_ = 0;
  stack->sym_idx_ = 0;
  stack->pos_ = 0;
  stack->error_recovery_ = 0;
  stack->continue_at_ = 0;
  stack->mute_error_turns_ = 0;
  /* reserve slots [0] and [1] for temporary storage of inflight syms and tokens.
  * note that initialization and lifetime of these slots is controlled by
  * flags, so no sym data constructors are called here. */
  if (stack->num_stack_allocated_ <= (stack->pos_ + 1)) {
    size_t new_num_allocated;
    if (stack->num_stack_allocated_) {
      new_num_allocated = stack->num_stack_allocated_ * 2;
      if (new_num_allocated <= stack->num_stack_allocated_) {
        /* Overflow in allocation */
        stack->continue_at_ = 0;
        return _AEX_PPME_OVERFLOW;
      }
    }
    else {
      new_num_allocated = 16;
    }
    
    if (new_num_allocated > (SIZE_MAX / sizeof(struct aex_ppme_sym_data))) {
      /* Overflow in allocation */
      stack->continue_at_ = 0;
      return _AEX_PPME_OVERFLOW;
    }
    
    void *p = realloc(stack->stack_, new_num_allocated * sizeof(struct aex_ppme_sym_data));
    if (!p) {
      /* Out of memory */
      stack->continue_at_ = 0;
      return _AEX_PPME_NO_MEMORY;
    }
    stack->stack_ = (struct aex_ppme_sym_data *)p;
    stack->num_stack_allocated_ = new_num_allocated;
  }
  stack->stack_[0].state_ = 0;
  stack->stack_[1].state_ = 0;
  stack->pos_ = 2;
  return 0;
}

int aex_ppme_stack_can_recover(struct aex_ppme_stack *stack) {
  return !!stack->error_recovery_;
}

int aex_ppme_stack_accepts(struct aex_ppme_stack *stack, int sym) {
  if (!stack->pos_) return 0;
  return 0 != aex_ppme_parse_table[aex_ppme_num_columns * stack->stack_[stack->pos_ - 1].state_ + (sym - aex_ppme_minimum_sym)];}

int aex_ppme_parse(struct aex_ppme_stack *stack, int sym, struct preprocessor *pp, struct pptk **pp_input_chain, int is_final, struct pptk **pp_output_chain, int keep_defined) {
  if (stack->pending_reset_) {
    int r;
    r = aex_ppme_stack_reset(stack);
    if (r) return r;
  }
    switch (stack->continue_at_) {
    case 0: break; /* fall through to regular code path */
    case 1: goto C1;
    case 2: goto C2;
    case 3: goto C3;
    case 4: goto C4;
    case 5: goto C5;
    case 6: goto C6;
    case 7: goto C7;
    case 8: goto C8;
    case 9: goto C9;
    case 10: goto C10;
    case 11: goto C11;
    case 12: goto C12;
    case 13: goto C13;
    case 14: goto C14;
    case 15: goto C15;
    case 16: goto C16;
    case 17: goto C17;
    case 18: goto C18;
    case 19: goto C19;
    case 20: goto C20;
    case 21: goto C21;
    case 22: goto C22;
    case 23: goto C23;
    case 24: goto C24;
    case 25: goto C25;
    case 26: goto C26;
    case 27: goto C27;
    case 28: goto C28;
    case 29: goto C29;
    case 30: goto C30;
    case 31: goto C31;
    case 32: goto C32;
    case 33: goto C33;
    case 34: goto C34;
    case 35: goto C35;
    case 36: goto C36;
    case 37: goto C37;
    case 38: goto C38;
    case 39: goto C39;
    case 40: goto C40;
    case 41: goto C41;
    case 42: goto C42;
    case 43: goto C43;
    case 44: goto C44;
    case 45: goto C45;
    case 46: goto C46;
    case 47: goto C47;
    case 48: goto C48;
    case 49: goto C49;
    case 50: goto C50;
    case 51: goto C51;
    case 52: goto C52;
    case 53: goto C53;
    case 54: goto C54;
    case 55: goto C55;
    case 56: goto C56;
    case 57: goto C57;
    case 58: goto C58;
    case 59: goto C59;
    case 60: goto C60;
    case 61: goto C61;
    case 62: goto C62;
    case 63: goto C63;
    case 64: goto C64;
    case 65: goto C65;
    case 66: goto C66;
    case 67: goto C67;
    case 68: goto C68;
    case 69: goto C69;
    case 70: goto C70;
    case 71: goto C71;
    case 72: goto C72;
    case 73: goto C73;
    case 74: goto C74;
    case 75: goto C75;
    case 76: goto C76;
    case 77: goto C77;
    case 78: goto C78;
    case 79: goto C79;
    case 80: goto C80;
    case 81: goto C81;
    case 82: goto C82;
    case 83: goto C83;
    case 84: goto C84;
    case 85: goto C85;
    case 86: goto C86;
    case 87: goto C87;
    case 88: goto C88;
    case 89: goto C89;
    case 90: goto C90;
    case 91: goto C91;
    case 92: goto C92;
    case 93: goto C93;
    case 94: goto C94;
    case 95: goto C95;
    case 96: goto C96;
    case 97: goto C97;
    case 98: goto C98;
    case 99: goto C99;
    case 100: goto C100;
    case 101: goto C101;
    case 102: goto C102;
    case 103: goto C103;
    case 104: goto C104;
    case 105: goto C105;
    case 106: goto C106;
    case 107: goto C107;
    case 108: goto C108;
    case 109: goto C109;
    case 110: goto C110;
    case 111: goto C111;
    case 112: goto C112;
  } /* continuation switch */
if (stack->mute_error_turns_) stack->mute_error_turns_--;
  for (;;) {
    if (!stack->error_recovery_) {
      int action;
      action = aex_ppme_parse_table[aex_ppme_num_columns * stack->stack_[stack->pos_ - 1].state_ + (sym - aex_ppme_minimum_sym)];
      if (action > 0) {
        if (stack->num_stack_allocated_ == stack->pos_) {
          stack->action_preservation_ = action;
          size_t new_num_allocated;
          if (stack->num_stack_allocated_) {
            new_num_allocated = stack->num_stack_allocated_ * 2;
            if (new_num_allocated <= stack->num_stack_allocated_) {
              /* Overflow in allocation */
              return _AEX_PPME_OVERFLOW;
            }
          }
          else {
            new_num_allocated = 16;
          }
          
          if (new_num_allocated > (SIZE_MAX / sizeof(struct aex_ppme_sym_data))) {
            /* Overflow in allocation */
            return _AEX_PPME_OVERFLOW;
          }
          
          stack->new_buf_ = (struct aex_ppme_sym_data *)malloc(new_num_allocated * sizeof(struct aex_ppme_sym_data));
          if (!stack->new_buf_) {
            /* Out of memory */
            return _AEX_PPME_NO_MEMORY;
          }
          stack->new_buf_num_allocated_ = new_num_allocated;
          for (stack->new_buf_sym_partial_pos_ = 0; stack->new_buf_sym_partial_pos_ < stack->pos_; ++stack->new_buf_sym_partial_pos_) {
            stack->new_buf_[stack->new_buf_sym_partial_pos_].state_ = stack->stack_[stack->new_buf_sym_partial_pos_].state_;
            stack->newbuf_pos_has_common_data_ = stack->newbuf_pos_has_sym_data_ = 0;
            stack->stack_newbuf_pos_has_common_data_ = stack->stack_newbuf_pos_has_sym_data_ = 1;
            if ((stack->new_buf_sym_partial_pos_ == 0) || (stack->new_buf_sym_partial_pos_ == 1)) {
              int need_sym_move;
              int sym_to_move;
              sym_to_move = 0; /* silence a waring with this explicit initialization */
              need_sym_move = 0;
              if (stack->new_buf_sym_partial_pos_ == 0) {
                /* slot 0 goes unused in scannerless operation */
                need_sym_move = 0;
              }
              else if (stack->new_buf_sym_partial_pos_ == 1) {
                need_sym_move = stack->slot_1_has_sym_data_;
                sym_to_move = stack->slot_1_sym_;
              }
              if (need_sym_move) {
                switch (sym_to_move) {
                  case AEX_PPME_IDENT:
                  case AEX_PPME_DEFINED:
                  case AEX_PPME_PAR_OPEN:
                  case AEX_PPME_PAR_CLOSE:
                  case AEX_PPME_COMMA:
                  case AEX_PPME_WS_TOK:
                  case AEX_PPME_OTHER:
                  stack->newbuf_pos_has_sym_data_ = 1;
                  stack->continue_at_ = 1;
                  {
#line 68 "grammar/pp/pp_macro_expander.cbrt"
                    stack->new_buf_[stack->new_buf_sym_partial_pos_].v_.uv0_ = NULL;
#line 1285 "src/pp/pp_macro_expander.c"
                  }
                  C1:;
                  stack->continue_at_ = 2;
                  {
#line 69 "grammar/pp/pp_macro_expander.cbrt"
                    stack->new_buf_[stack->new_buf_sym_partial_pos_].v_.uv0_ = (stack->stack_[stack->new_buf_sym_partial_pos_].v_.uv0_); (stack->stack_[stack->new_buf_sym_partial_pos_].v_.uv0_) = NULL;
#line 1292 "src/pp/pp_macro_expander.c"
                  }
                  C2:;
                  {
#line 70 "grammar/pp/pp_macro_expander.cbrt"
                    aex_pptk_free(((stack->stack_ + stack->new_buf_sym_partial_pos_)->v_.uv0_));
#line 1298 "src/pp/pp_macro_expander.c"
                  }
                  stack->stack_newbuf_pos_has_sym_data_ = 0;
                  
                  break;
                  case AEX_PPME_OBJECT:
                  case AEX_PPME_FUNCTION:
                  stack->newbuf_pos_has_sym_data_ = 1;
                  stack->continue_at_ = 3;
                  {
#line 75 "grammar/pp/pp_macro_expander.cbrt"
                    stack->new_buf_[stack->new_buf_sym_partial_pos_].v_.uv1_.tk_ = NULL; stack->new_buf_[stack->new_buf_sym_partial_pos_].v_.uv1_.m_ = NULL;
#line 1310 "src/pp/pp_macro_expander.c"
                  }
                  C3:;
                  stack->continue_at_ = 4;
                  {
#line 76 "grammar/pp/pp_macro_expander.cbrt"
                    stack->new_buf_[stack->new_buf_sym_partial_pos_].v_.uv1_.tk_ = (stack->stack_[stack->new_buf_sym_partial_pos_].v_.uv1_).tk_; stack->new_buf_[stack->new_buf_sym_partial_pos_].v_.uv1_.m_ = (stack->stack_[stack->new_buf_sym_partial_pos_].v_.uv1_).m_;
#line 1317 "src/pp/pp_macro_expander.c"
                  }
                  C4:;
                  {
#line 77 "grammar/pp/pp_macro_expander.cbrt"
                    aex_pptk_free(((stack->stack_ + stack->new_buf_sym_partial_pos_)->v_.uv1_).tk_); aex_macro_free(((stack->stack_ + stack->new_buf_sym_partial_pos_)->v_.uv1_).m_); /* Reduction of OBJECT drops a reference and might free the macro */
#line 1323 "src/pp/pp_macro_expander.c"
                  }
                  stack->stack_newbuf_pos_has_sym_data_ = 0;
                  
                  break;
                  case AEX_PPME_NON_FUNCTION:
                  case AEX_PPME_WS_OPT:
                  case AEX_PPME_PAR_SPAN:
                  case AEX_PPME_ARG:
                  stack->newbuf_pos_has_sym_data_ = 1;
                  stack->continue_at_ = 5;
                  {
#line 95 "grammar/pp/pp_macro_expander.cbrt"
                    stack->new_buf_[stack->new_buf_sym_partial_pos_].v_.uv2_ = NULL;
#line 1337 "src/pp/pp_macro_expander.c"
                  }
                  C5:;
                  stack->continue_at_ = 6;
                  {
#line 96 "grammar/pp/pp_macro_expander.cbrt"
                    stack->new_buf_[stack->new_buf_sym_partial_pos_].v_.uv2_ = (stack->stack_[stack->new_buf_sym_partial_pos_].v_.uv2_); (stack->stack_[stack->new_buf_sym_partial_pos_].v_.uv2_) = NULL;
#line 1344 "src/pp/pp_macro_expander.c"
                  }
                  C6:;
                  {
#line 97 "grammar/pp/pp_macro_expander.cbrt"
                    aex_pptk_free(((stack->stack_ + stack->new_buf_sym_partial_pos_)->v_.uv2_));
#line 1350 "src/pp/pp_macro_expander.c"
                  }
                  stack->stack_newbuf_pos_has_sym_data_ = 0;
                  
                  break;
                  case AEX_PPME_ARGS:
                  stack->newbuf_pos_has_sym_data_ = 1;
                  stack->continue_at_ = 7;
                  {
#line 101 "grammar/pp/pp_macro_expander.cbrt"
                    stack->new_buf_[stack->new_buf_sym_partial_pos_].v_.uv3_ = NULL;
#line 1361 "src/pp/pp_macro_expander.c"
                  }
                  C7:;
                  stack->continue_at_ = 8;
                  {
#line 102 "grammar/pp/pp_macro_expander.cbrt"
                    stack->new_buf_[stack->new_buf_sym_partial_pos_].v_.uv3_ = (stack->stack_[stack->new_buf_sym_partial_pos_].v_.uv3_); (stack->stack_[stack->new_buf_sym_partial_pos_].v_.uv3_) = NULL;
#line 1368 "src/pp/pp_macro_expander.c"
                  }
                  C8:;
                  {
#line 103 "grammar/pp/pp_macro_expander.cbrt"
                    aex_macro_arg_inst_free(((stack->stack_ + stack->new_buf_sym_partial_pos_)->v_.uv3_));
#line 1374 "src/pp/pp_macro_expander.c"
                  }
                  stack->stack_newbuf_pos_has_sym_data_ = 0;
                  
                  break;
                }
              }
            }
            else /* not 0 or 1, but >= 2 state derived sym */ {
              switch (stack->stack_[stack->new_buf_sym_partial_pos_].state_) {
                case 2: /* IDENT */
                case 3: /* COMMA */
                case 4: /* PAR_CLOSE */
                case 5: /* OTHER */
                case 6: /* PAR_CLOSE */
                case 8: /* COMMA */
                case 10: /* IDENT */
                case 13: /* WS_TOK */
                case 14: /* OTHER */
                case 15: /* PAR_CLOSE */
                case 16: /* IDENT */
                case 19: /* COMMA */
                case 20: /* WS_TOK */
                case 21: /* OTHER */
                case 22: /* PAR_CLOSE */
                case 24: /* PAR_OPEN */
                case 26: /* PAR_OPEN */
                case 28: /* PAR_OPEN */
                case 32: /* PAR_CLOSE */
                case 34: /* IDENT */
                case 35: /* PAR_CLOSE */
                case 38: /* PAR_CLOSE */
                case 41: /* PAR_CLOSE */
                case 43: /* DEFINED */
                case 45: /* PAR_OPEN */
                case 46: /* IDENT */
                case 49: /* DEFINED */
                case 50: /* WS_TOK */
                case 52: /* DEFINED */
                case 54: /* PAR_OPEN */
                case 55: /* WS_TOK */
                stack->newbuf_pos_has_sym_data_ = 1;
                stack->continue_at_ = 9;
                {
#line 68 "grammar/pp/pp_macro_expander.cbrt"
                  stack->new_buf_[stack->new_buf_sym_partial_pos_].v_.uv0_ = NULL;
#line 1420 "src/pp/pp_macro_expander.c"
                }
                C9:;
                stack->continue_at_ = 10;
                {
#line 69 "grammar/pp/pp_macro_expander.cbrt"
                  stack->new_buf_[stack->new_buf_sym_partial_pos_].v_.uv0_ = (stack->stack_[stack->new_buf_sym_partial_pos_].v_.uv0_); (stack->stack_[stack->new_buf_sym_partial_pos_].v_.uv0_) = NULL;
#line 1427 "src/pp/pp_macro_expander.c"
                }
                C10:;
                {
#line 70 "grammar/pp/pp_macro_expander.cbrt"
                  aex_pptk_free(((stack->stack_ + stack->new_buf_sym_partial_pos_)->v_.uv0_));
#line 1433 "src/pp/pp_macro_expander.c"
                }
                stack->stack_newbuf_pos_has_sym_data_ = 0;
                break;
                
                case 11: /* FUNCTION */
                case 12: /* OBJECT */
                case 17: /* FUNCTION */
                case 18: /* OBJECT */
                case 30: /* FUNCTION */
                case 31: /* OBJECT */
                case 37: /* FUNCTION */
                case 40: /* OBJECT */
                case 47: /* FUNCTION */
                case 48: /* OBJECT */
                stack->newbuf_pos_has_sym_data_ = 1;
                stack->continue_at_ = 11;
                {
#line 75 "grammar/pp/pp_macro_expander.cbrt"
                  stack->new_buf_[stack->new_buf_sym_partial_pos_].v_.uv1_.tk_ = NULL; stack->new_buf_[stack->new_buf_sym_partial_pos_].v_.uv1_.m_ = NULL;
#line 1453 "src/pp/pp_macro_expander.c"
                }
                C11:;
                stack->continue_at_ = 12;
                {
#line 76 "grammar/pp/pp_macro_expander.cbrt"
                  stack->new_buf_[stack->new_buf_sym_partial_pos_].v_.uv1_.tk_ = (stack->stack_[stack->new_buf_sym_partial_pos_].v_.uv1_).tk_; stack->new_buf_[stack->new_buf_sym_partial_pos_].v_.uv1_.m_ = (stack->stack_[stack->new_buf_sym_partial_pos_].v_.uv1_).m_;
#line 1460 "src/pp/pp_macro_expander.c"
                }
                C12:;
                {
#line 77 "grammar/pp/pp_macro_expander.cbrt"
                  aex_pptk_free(((stack->stack_ + stack->new_buf_sym_partial_pos_)->v_.uv1_).tk_); aex_macro_free(((stack->stack_ + stack->new_buf_sym_partial_pos_)->v_.uv1_).m_); /* Reduction of OBJECT drops a reference and might free the macro */
#line 1466 "src/pp/pp_macro_expander.c"
                }
                stack->stack_newbuf_pos_has_sym_data_ = 0;
                break;
                
                case 7: /* arg */
                case 23: /* par-span */
                case 25: /* par-span */
                case 27: /* arg */
                case 29: /* ws-opt */
                case 33: /* ws-opt */
                case 36: /* ws-opt */
                case 39: /* ws-opt */
                case 42: /* ws-opt */
                case 44: /* ws-opt */
                case 51: /* ws-opt */
                stack->newbuf_pos_has_sym_data_ = 1;
                stack->continue_at_ = 13;
                {
#line 95 "grammar/pp/pp_macro_expander.cbrt"
                  stack->new_buf_[stack->new_buf_sym_partial_pos_].v_.uv2_ = NULL;
#line 1487 "src/pp/pp_macro_expander.c"
                }
                C13:;
                stack->continue_at_ = 14;
                {
#line 96 "grammar/pp/pp_macro_expander.cbrt"
                  stack->new_buf_[stack->new_buf_sym_partial_pos_].v_.uv2_ = (stack->stack_[stack->new_buf_sym_partial_pos_].v_.uv2_); (stack->stack_[stack->new_buf_sym_partial_pos_].v_.uv2_) = NULL;
#line 1494 "src/pp/pp_macro_expander.c"
                }
                C14:;
                {
#line 97 "grammar/pp/pp_macro_expander.cbrt"
                  aex_pptk_free(((stack->stack_ + stack->new_buf_sym_partial_pos_)->v_.uv2_));
#line 1500 "src/pp/pp_macro_expander.c"
                }
                stack->stack_newbuf_pos_has_sym_data_ = 0;
                break;
                
                case 9: /* args */
                stack->newbuf_pos_has_sym_data_ = 1;
                stack->continue_at_ = 15;
                {
#line 101 "grammar/pp/pp_macro_expander.cbrt"
                  stack->new_buf_[stack->new_buf_sym_partial_pos_].v_.uv3_ = NULL;
#line 1511 "src/pp/pp_macro_expander.c"
                }
                C15:;
                stack->continue_at_ = 16;
                {
#line 102 "grammar/pp/pp_macro_expander.cbrt"
                  stack->new_buf_[stack->new_buf_sym_partial_pos_].v_.uv3_ = (stack->stack_[stack->new_buf_sym_partial_pos_].v_.uv3_); (stack->stack_[stack->new_buf_sym_partial_pos_].v_.uv3_) = NULL;
#line 1518 "src/pp/pp_macro_expander.c"
                }
                C16:;
                {
#line 103 "grammar/pp/pp_macro_expander.cbrt"
                  aex_macro_arg_inst_free(((stack->stack_ + stack->new_buf_sym_partial_pos_)->v_.uv3_));
#line 1524 "src/pp/pp_macro_expander.c"
                }
                stack->stack_newbuf_pos_has_sym_data_ = 0;
                break;
                
              } /* switch */
            }
          }
          if (stack->stack_) free(stack->stack_);
          stack->stack_ = stack->new_buf_;
          stack->new_buf_sym_partial_pos_ = 0;
          stack->new_buf_ = NULL;
          stack->num_stack_allocated_ = stack->new_buf_num_allocated_;
          action = stack->action_preservation_;
        }
        stack->stack_[stack->pos_++].state_ = action;
        stack->top_of_stack_has_sym_data_ = 0;
        stack->top_of_stack_has_common_data_ = 0;
        
        stack->sym_data_ = stack->stack_ + stack->pos_ - 1;
        stack->top_of_stack_has_sym_data_ = 0;
        switch (sym) {
          case AEX_PPME_IDENT:
          case AEX_PPME_DEFINED:
          case AEX_PPME_PAR_OPEN:
          case AEX_PPME_PAR_CLOSE:
          case AEX_PPME_COMMA:
          case AEX_PPME_WS_TOK:
          case AEX_PPME_OTHER:
          stack->top_of_stack_has_sym_data_ = 1;
          stack->continue_at_ = 17;
          {
#line 68 "grammar/pp/pp_macro_expander.cbrt"
            (stack->sym_data_->v_.uv0_) = NULL;
#line 1558 "src/pp/pp_macro_expander.c"
          }
          C17:;
          stack->continue_at_ = 18;
          {
#line 71 "grammar/pp/pp_macro_expander.cbrt"
            (stack->sym_data_->v_.uv0_) = aex_pptk_pop_front(pp_input_chain);
#line 1565 "src/pp/pp_macro_expander.c"
          }
          C18:;
          break;
          case AEX_PPME_OBJECT:
          case AEX_PPME_FUNCTION:
          stack->top_of_stack_has_sym_data_ = 1;
          stack->continue_at_ = 19;
          {
#line 75 "grammar/pp/pp_macro_expander.cbrt"
            (stack->sym_data_->v_.uv1_).tk_ = NULL; (stack->sym_data_->v_.uv1_).m_ = NULL;
#line 1576 "src/pp/pp_macro_expander.c"
          }
          C19:;
          stack->continue_at_ = 20;
          {
#line 79 "grammar/pp/pp_macro_expander.cbrt"
            (stack->sym_data_->v_.uv1_).tk_ = aex_pptk_pop_front(pp_input_chain); \
  struct macro *m = mt_find(&pp->macro_table_, (stack->sym_data_->v_.uv1_).tk_->text_, (stack->sym_data_->v_.uv1_).tk_->text_len_); \
  if (!m) { \
    /* In-between %on_next_token and actually shifting the same token, we lost the macro.
     * This should never happen as the only thing happening between %on_next_token and
     * %token_action are reductions in the current grammar (e.g. no #undef can be processed,)
     * cannot recover */ \
    dx_printf(pp->dx_, "Internal error, lost macro definition\n"); \
    return _AEX_PPME_INTERNAL_ERROR; \
  } \
  m->refcount_++; \
  (stack->sym_data_->v_.uv1_).m_ = m;
#line 1594 "src/pp/pp_macro_expander.c"
          }
          C20:;
          break;
        } /* switch */
        stack->continue_at_ = 0;
        {
          if (*pp_input_chain) {                                                                \
            sym = g_aex_pptk_to_ppme_[(*pp_input_chain)->tok_];                                     \
            if ((!keep_defined) && (sym == AEX_PPME_DEFINED)) {                                     \
              sym = AEX_PPME_IDENT;                                                                 \
              }                                                                                   \
            if (sym == AEX_PPME_IDENT) {                                                            \
              struct macro *m = NULL;                                                           \
              m = mt_find(&pp->macro_table_, (*pp_input_chain)->text_, (*pp_input_chain)->text_len_); \
              if (m && !m->nested_invocation_) {                                                \
                if (m->is_function_style_) {                                                    \
                  sym = AEX_PPME_FUNCTION;                                                          \
                  }                                                                               \
                else {                                                                          \
                  sym = AEX_PPME_OBJECT;                                                            \
                  }                                                                               \
                }                                                                                 \
              }                                                                                   \
            }                                                                                     \
          else {                                                                                \
            if (!is_final) return _AEX_PPME_FEED_ME;                                                \
            sym = AEX_PPME_INPUT_END;                                                               \
            }
          
        }
      } /* action > 0 */
      else if (action < 0) {
        int production;
        production = -action - 1;
        stack->discard_remaining_actions_ = 0;
        stack->current_production_length_ = aex_ppme_production_lengths[production];
        stack->current_production_nonterminal_ = aex_ppme_production_syms[production];
        if (0 == production) {
          stack->pending_reset_ = 1;
          /* Synth S we're done */
          return _AEX_PPME_FINISH;
        }
        
        memset(&stack->stack_[1], 0, sizeof(struct aex_ppme_sym_data));
        { /* scope guard */
          stack->sym_data_ = stack->stack_ + stack->pos_ - stack->current_production_length_;
          switch (production) {
            /* total: top-stream opt-function-seq */
            case 1: {
            }
            break;
            /* top-stream: */
            case 2: {
            }
            break;
            /* top-stream: top-stream opt-function-seq IDENT */
            case 3: {
              stack->continue_at_ = 21;
              {
#line 108 "grammar/pp/pp_macro_expander.cbrt"
                {
    *pp_output_chain = aex_pptk_join(*pp_output_chain, (stack->sym_data_[2].v_.uv0_));
    (stack->sym_data_[2].v_.uv0_) = NULL;
}
#line 1659 "src/pp/pp_macro_expander.c"
              }
              C21:;
            }
            break;
            /* top-stream: top-stream opt-function-seq COMMA */
            case 4: {
              stack->continue_at_ = 22;
              {
#line 112 "grammar/pp/pp_macro_expander.cbrt"
                {
    *pp_output_chain = aex_pptk_join(*pp_output_chain, (stack->sym_data_[2].v_.uv0_));
    (stack->sym_data_[2].v_.uv0_) = NULL;
}
#line 1673 "src/pp/pp_macro_expander.c"
              }
              C22:;
            }
            break;
            /* top-stream: top-stream ws-opt-emit PAR_OPEN */
            case 5: {
              stack->continue_at_ = 23;
              {
#line 116 "grammar/pp/pp_macro_expander.cbrt"
                {
    *pp_output_chain = aex_pptk_join(*pp_output_chain, (stack->sym_data_[2].v_.uv0_));
    (stack->sym_data_[2].v_.uv0_) = NULL;
}
#line 1687 "src/pp/pp_macro_expander.c"
              }
              C23:;
            }
            break;
            /* top-stream: top-stream opt-function-seq PAR_CLOSE */
            case 6: {
              stack->continue_at_ = 24;
              {
#line 120 "grammar/pp/pp_macro_expander.cbrt"
                {
    *pp_output_chain = aex_pptk_join(*pp_output_chain, (stack->sym_data_[2].v_.uv0_));
    (stack->sym_data_[2].v_.uv0_) = NULL;
}
#line 1701 "src/pp/pp_macro_expander.c"
              }
              C24:;
            }
            break;
            /* top-stream: top-stream opt-function-seq OTHER */
            case 7: {
              stack->continue_at_ = 25;
              {
#line 124 "grammar/pp/pp_macro_expander.cbrt"
                {
    *pp_output_chain = aex_pptk_join(*pp_output_chain, (stack->sym_data_[2].v_.uv0_));
    (stack->sym_data_[2].v_.uv0_) = NULL;
}
#line 1715 "src/pp/pp_macro_expander.c"
              }
              C25:;
            }
            break;
            /* top-stream: top-stream opt-function-seq FUNCTION ws-opt PAR_OPEN args PAR_CLOSE */
            case 8: {
              stack->continue_at_ = 26;
              {
#line 128 "grammar/pp/pp_macro_expander.cbrt"
                {
  /* Insert FUNCTION expansion */
  int r = aex_macro_expand(pp, (stack->sym_data_[2].v_.uv1_).tk_, (stack->sym_data_[2].v_.uv1_).m_, (stack->sym_data_[5].v_.uv3_), pp_output_chain);
  if (r) {
    return _AEX_PPME_INTERNAL_ERROR;
  }
}
#line 1732 "src/pp/pp_macro_expander.c"
              }
              C26:;
            }
            break;
            /* top-stream: top-stream opt-function-seq OBJECT */
            case 9: {
              stack->continue_at_ = 27;
              {
#line 135 "grammar/pp/pp_macro_expander.cbrt"
                {
  /* Insert OBJECT expansion */
  int r = aex_macro_expand(pp, (stack->sym_data_[2].v_.uv1_).tk_, (stack->sym_data_[2].v_.uv1_).m_, NULL, pp_output_chain);
  if (r) {
    return _AEX_PPME_INTERNAL_ERROR;
  }
}
#line 1749 "src/pp/pp_macro_expander.c"
              }
              C27:;
            }
            break;
            /* top-stream: top-stream opt-function-seq DEFINED ws-opt PAR_OPEN ws-opt IDENT ws-opt PAR_CLOSE */
            case 10: {
              stack->continue_at_ = 28;
              {
#line 150 "grammar/pp/pp_macro_expander.cbrt"
                {
  /* Insert "DEFINED (ID)" expansion; this is a straight up copy to preserve it for
   * preprocessor constant expression evaluation. */
  *pp_output_chain = aex_pptk_join(*pp_output_chain, (stack->sym_data_[2].v_.uv0_)); /* DEFINED */
  *pp_output_chain = aex_pptk_join(*pp_output_chain, (stack->sym_data_[3].v_.uv2_)); /* ws-opt */
  *pp_output_chain = aex_pptk_join(*pp_output_chain, (stack->sym_data_[4].v_.uv0_)); /* PAR_OPEN */
  *pp_output_chain = aex_pptk_join(*pp_output_chain, (stack->sym_data_[5].v_.uv2_)); /* ws-opt */
  *pp_output_chain = aex_pptk_join(*pp_output_chain, (stack->sym_data_[6].v_.uv0_)); /* IDENT */
  *pp_output_chain = aex_pptk_join(*pp_output_chain, (stack->sym_data_[7].v_.uv2_)); /* ws-opt */
  *pp_output_chain = aex_pptk_join(*pp_output_chain, (stack->sym_data_[8].v_.uv0_)); /* PAR_CLOSE */
  (stack->sym_data_[2].v_.uv0_) = (stack->sym_data_[3].v_.uv2_) = (stack->sym_data_[4].v_.uv0_) = (stack->sym_data_[5].v_.uv2_) = (stack->sym_data_[6].v_.uv0_) = (stack->sym_data_[7].v_.uv2_) = (stack->sym_data_[8].v_.uv0_) = NULL;
}
#line 1771 "src/pp/pp_macro_expander.c"
              }
              C28:;
            }
            break;
            /* top-stream: top-stream opt-function-seq DEFINED ws-opt PAR_OPEN ws-opt FUNCTION ws-opt PAR_CLOSE */
            case 11: {
              stack->continue_at_ = 29;
              {
#line 163 "grammar/pp/pp_macro_expander.cbrt"
                {
  *pp_output_chain = aex_pptk_join(*pp_output_chain, (stack->sym_data_[2].v_.uv0_)); /* DEFINED */
  *pp_output_chain = aex_pptk_join(*pp_output_chain, (stack->sym_data_[3].v_.uv2_)); /* ws-opt */
  *pp_output_chain = aex_pptk_join(*pp_output_chain, (stack->sym_data_[4].v_.uv0_)); /* PAR_OPEN */
  *pp_output_chain = aex_pptk_join(*pp_output_chain, (stack->sym_data_[5].v_.uv2_)); /* ws-opt */
  *pp_output_chain = aex_pptk_join(*pp_output_chain, (stack->sym_data_[6].v_.uv1_).tk_); /* FUNCTION */
  *pp_output_chain = aex_pptk_join(*pp_output_chain, (stack->sym_data_[7].v_.uv2_)); /* ws-opt */
  *pp_output_chain = aex_pptk_join(*pp_output_chain, (stack->sym_data_[8].v_.uv0_)); /* PAR_CLOSE */
  (stack->sym_data_[2].v_.uv0_) = (stack->sym_data_[3].v_.uv2_) = (stack->sym_data_[4].v_.uv0_) = (stack->sym_data_[5].v_.uv2_) = (stack->sym_data_[6].v_.uv1_).tk_ =(stack->sym_data_[7].v_.uv2_) = (stack->sym_data_[8].v_.uv0_) = NULL;
}
#line 1791 "src/pp/pp_macro_expander.c"
              }
              C29:;
            }
            break;
            /* top-stream: top-stream opt-function-seq DEFINED ws-opt PAR_OPEN ws-opt OBJECT ws-opt PAR_CLOSE */
            case 12: {
              stack->continue_at_ = 30;
              {
#line 174 "grammar/pp/pp_macro_expander.cbrt"
                {
  /* Insert "DEFINED (ID)" expansion; this is a straight up copy to preserve it for
   * preprocessor constant expression evaluation. */
  *pp_output_chain = aex_pptk_join(*pp_output_chain, (stack->sym_data_[2].v_.uv0_)); /* DEFINED */
  *pp_output_chain = aex_pptk_join(*pp_output_chain, (stack->sym_data_[3].v_.uv2_)); /* ws-opt */
  *pp_output_chain = aex_pptk_join(*pp_output_chain, (stack->sym_data_[4].v_.uv0_)); /* PAR_OPEN */
  *pp_output_chain = aex_pptk_join(*pp_output_chain, (stack->sym_data_[5].v_.uv2_)); /* ws-opt */
  *pp_output_chain = aex_pptk_join(*pp_output_chain, (stack->sym_data_[6].v_.uv1_).tk_); /* OBJECT */
  *pp_output_chain = aex_pptk_join(*pp_output_chain, (stack->sym_data_[7].v_.uv2_)); /* ws-opt */
  *pp_output_chain = aex_pptk_join(*pp_output_chain, (stack->sym_data_[8].v_.uv0_)); /* PAR_CLOSE */
  (stack->sym_data_[2].v_.uv0_) = (stack->sym_data_[3].v_.uv2_) = (stack->sym_data_[4].v_.uv0_) = (stack->sym_data_[5].v_.uv2_) = (stack->sym_data_[6].v_.uv1_).tk_ =(stack->sym_data_[7].v_.uv2_) = (stack->sym_data_[8].v_.uv0_) = NULL;
}
#line 1813 "src/pp/pp_macro_expander.c"
              }
              C30:;
            }
            break;
            /* top-stream: top-stream opt-function-seq DEFINED ws-opt PAR_OPEN ws-opt DEFINED ws-opt PAR_CLOSE */
            case 13: {
              stack->continue_at_ = 31;
              {
#line 187 "grammar/pp/pp_macro_expander.cbrt"
                {
  /* Insert "DEFINED (ID)" expansion; this is a straight up copy to preserve it for
   * preprocessor constant expression evaluation. */
  *pp_output_chain = aex_pptk_join(*pp_output_chain, (stack->sym_data_[2].v_.uv0_)); /* DEFINED */
  *pp_output_chain = aex_pptk_join(*pp_output_chain, (stack->sym_data_[3].v_.uv2_)); /* ws-opt */
  *pp_output_chain = aex_pptk_join(*pp_output_chain, (stack->sym_data_[4].v_.uv0_)); /* PAR_OPEN */
  *pp_output_chain = aex_pptk_join(*pp_output_chain, (stack->sym_data_[5].v_.uv2_)); /* ws-opt */
  *pp_output_chain = aex_pptk_join(*pp_output_chain, (stack->sym_data_[6].v_.uv0_)); /* DEFINED */
  *pp_output_chain = aex_pptk_join(*pp_output_chain, (stack->sym_data_[7].v_.uv2_)); /* ws-opt */
  *pp_output_chain = aex_pptk_join(*pp_output_chain, (stack->sym_data_[8].v_.uv0_)); /* PAR_CLOSE */
  (stack->sym_data_[2].v_.uv0_) = (stack->sym_data_[3].v_.uv2_) = (stack->sym_data_[4].v_.uv0_) = (stack->sym_data_[5].v_.uv2_) = (stack->sym_data_[6].v_.uv0_) =(stack->sym_data_[7].v_.uv2_) = (stack->sym_data_[8].v_.uv0_) = NULL;
}
#line 1835 "src/pp/pp_macro_expander.c"
              }
              C31:;
            }
            break;
            /* top-stream: top-stream opt-function-seq DEFINED ws-opt IDENT */
            case 14: {
              stack->continue_at_ = 32;
              {
#line 200 "grammar/pp/pp_macro_expander.cbrt"
                {
  /* Insert "DEFINED ID" expansion; this is a straight up copy to preserve it for
   * preprocessor constant expression evaluation. */
  *pp_output_chain = aex_pptk_join(*pp_output_chain, (stack->sym_data_[2].v_.uv0_)); /* DEFINED */
  *pp_output_chain = aex_pptk_join(*pp_output_chain, (stack->sym_data_[3].v_.uv2_)); /* ws-opt */
  *pp_output_chain = aex_pptk_join(*pp_output_chain, (stack->sym_data_[4].v_.uv0_)); /* IDENT */
  (stack->sym_data_[2].v_.uv0_) = (stack->sym_data_[3].v_.uv2_) = (stack->sym_data_[4].v_.uv0_) = NULL;
}
#line 1853 "src/pp/pp_macro_expander.c"
              }
              C32:;
            }
            break;
            /* top-stream: top-stream opt-function-seq DEFINED ws-opt FUNCTION */
            case 15: {
              stack->continue_at_ = 33;
              {
#line 209 "grammar/pp/pp_macro_expander.cbrt"
                {
  /* Insert "DEFINED ID" expansion; this is a straight up copy to preserve it for
   * preprocessor constant expression evaluation. */
  *pp_output_chain = aex_pptk_join(*pp_output_chain, (stack->sym_data_[2].v_.uv0_)); /* DEFINED */
  *pp_output_chain = aex_pptk_join(*pp_output_chain, (stack->sym_data_[3].v_.uv2_)); /* ws-opt */
  *pp_output_chain = aex_pptk_join(*pp_output_chain, (stack->sym_data_[4].v_.uv1_).tk_); /* FUNCTION */
  (stack->sym_data_[2].v_.uv0_) = (stack->sym_data_[3].v_.uv2_) = (stack->sym_data_[4].v_.uv1_).tk_ = NULL;
}
#line 1871 "src/pp/pp_macro_expander.c"
              }
              C33:;
            }
            break;
            /* top-stream: top-stream opt-function-seq DEFINED ws-opt OBJECT */
            case 16: {
              stack->continue_at_ = 34;
              {
#line 218 "grammar/pp/pp_macro_expander.cbrt"
                {
  /* Insert "DEFINED ID" expansion; this is a straight up copy to preserve it for
   * preprocessor constant expression evaluation. */
  *pp_output_chain = aex_pptk_join(*pp_output_chain, (stack->sym_data_[2].v_.uv0_)); /* DEFINED */
  *pp_output_chain = aex_pptk_join(*pp_output_chain, (stack->sym_data_[3].v_.uv2_)); /* ws-opt */
  *pp_output_chain = aex_pptk_join(*pp_output_chain, (stack->sym_data_[4].v_.uv1_).tk_); /* OBJECT */
  (stack->sym_data_[2].v_.uv0_) = (stack->sym_data_[3].v_.uv2_) = (stack->sym_data_[4].v_.uv1_).tk_ = NULL;
}
#line 1889 "src/pp/pp_macro_expander.c"
              }
              C34:;
            }
            break;
            /* top-stream: top-stream opt-function-seq DEFINED ws-opt DEFINED */
            case 17: {
              stack->continue_at_ = 35;
              {
#line 227 "grammar/pp/pp_macro_expander.cbrt"
                {
  /* Insert "DEFINED ID" expansion; this is a straight up copy to preserve it for
   * preprocessor constant expression evaluation. */
  *pp_output_chain = aex_pptk_join(*pp_output_chain, (stack->sym_data_[2].v_.uv0_)); /* DEFINED */
  *pp_output_chain = aex_pptk_join(*pp_output_chain, (stack->sym_data_[3].v_.uv2_)); /* ws-opt */
  *pp_output_chain = aex_pptk_join(*pp_output_chain, (stack->sym_data_[4].v_.uv0_)); /* DEFINED */
  (stack->sym_data_[2].v_.uv0_) = (stack->sym_data_[3].v_.uv2_) = (stack->sym_data_[4].v_.uv0_) = NULL;
}
#line 1907 "src/pp/pp_macro_expander.c"
              }
              C35:;
            }
            break;
            /* opt-function-seq: ws-opt-emit */
            case 18: {
            }
            break;
            /* opt-function-seq: opt-function-seq FUNCTION ws-opt */
            case 19: {
              stack->continue_at_ = 36;
              {
#line 237 "grammar/pp/pp_macro_expander.cbrt"
                {
  /* Emit optional function sequences direct to output, they handle the edge case of a function-like
   * macro with no arguments (which should not result in an expansion, but a literal copy of the
   * macro identifier.) */
  *pp_output_chain = aex_pptk_join(*pp_output_chain, (stack->sym_data_[1].v_.uv1_).tk_);
  *pp_output_chain = aex_pptk_join(*pp_output_chain, (stack->sym_data_[2].v_.uv2_));
  (stack->sym_data_[1].v_.uv1_).tk_ = (stack->sym_data_[2].v_.uv2_) = NULL;
}
#line 1929 "src/pp/pp_macro_expander.c"
              }
              C36:;
            }
            break;
            /* args: arg */
            case 20: {
              stack->slot_1_has_sym_data_ = 1;
              stack->slot_1_sym_ = AEX_PPME_ARGS;
              stack->continue_at_ = 37;
              {
#line 101 "grammar/pp/pp_macro_expander.cbrt"
                (stack->stack_[1].v_.uv3_) = NULL;
#line 1942 "src/pp/pp_macro_expander.c"
              }
              C37:;
              stack->continue_at_ = 38;
              {
#line 246 "grammar/pp/pp_macro_expander.cbrt"
                { 
  struct macro_arg_inst *mai;
  mai = aex_macro_arg_inst_alloc((stack->sym_data_[0].v_.uv2_));
  if (!mai) {
    dx_no_memory(pp->dx_);
    return _AEX_PPME_NO_MEMORY;
  }
  (stack->stack_[1].v_.uv3_) = mai; (stack->sym_data_[0].v_.uv2_) = NULL;
}
#line 1957 "src/pp/pp_macro_expander.c"
              }
              C38:;
            }
            break;
            /* args: args COMMA arg */
            case 21: {
              stack->slot_1_has_sym_data_ = 1;
              stack->slot_1_sym_ = AEX_PPME_ARGS;
              stack->continue_at_ = 39;
              {
#line 101 "grammar/pp/pp_macro_expander.cbrt"
                (stack->stack_[1].v_.uv3_) = NULL;
#line 1970 "src/pp/pp_macro_expander.c"
              }
              C39:;
              stack->continue_at_ = 40;
              {
#line 255 "grammar/pp/pp_macro_expander.cbrt"
                {
  struct macro_arg_inst *mai;
  mai = aex_macro_arg_inst_alloc((stack->sym_data_[2].v_.uv2_));
  if (!mai) {
    dx_no_memory(pp->dx_);
    return _AEX_PPME_NO_MEMORY;
  }
  (stack->sym_data_[2].v_.uv2_) = NULL;
  (stack->stack_[1].v_.uv3_) = aex_macro_arg_inst_join((stack->sym_data_[0].v_.uv3_), mai);
  (stack->sym_data_[0].v_.uv3_) = NULL;
}
#line 1987 "src/pp/pp_macro_expander.c"
              }
              C40:;
            }
            break;
            /* arg: */
            case 22: {
              stack->slot_1_has_sym_data_ = 1;
              stack->slot_1_sym_ = AEX_PPME_ARG;
              stack->continue_at_ = 41;
              {
#line 95 "grammar/pp/pp_macro_expander.cbrt"
                (stack->stack_[1].v_.uv2_) = NULL;
#line 2000 "src/pp/pp_macro_expander.c"
              }
              C41:;
            }
            break;
            /* arg: arg IDENT */
            case 23: {
              stack->slot_1_has_sym_data_ = 1;
              stack->slot_1_sym_ = AEX_PPME_ARG;
              stack->continue_at_ = 42;
              {
#line 95 "grammar/pp/pp_macro_expander.cbrt"
                (stack->stack_[1].v_.uv2_) = NULL;
#line 2013 "src/pp/pp_macro_expander.c"
              }
              C42:;
              stack->continue_at_ = 43;
              {
#line 268 "grammar/pp/pp_macro_expander.cbrt"
                { (stack->stack_[1].v_.uv2_) = aex_pptk_join((stack->sym_data_[0].v_.uv2_), (stack->sym_data_[1].v_.uv0_)); (stack->sym_data_[0].v_.uv2_) = (stack->sym_data_[1].v_.uv0_) = NULL; }
#line 2020 "src/pp/pp_macro_expander.c"
              }
              C43:;
            }
            break;
            /* arg: arg FUNCTION */
            case 24: {
              stack->slot_1_has_sym_data_ = 1;
              stack->slot_1_sym_ = AEX_PPME_ARG;
              stack->continue_at_ = 44;
              {
#line 95 "grammar/pp/pp_macro_expander.cbrt"
                (stack->stack_[1].v_.uv2_) = NULL;
#line 2033 "src/pp/pp_macro_expander.c"
              }
              C44:;
              stack->continue_at_ = 45;
              {
#line 269 "grammar/pp/pp_macro_expander.cbrt"
                { (stack->stack_[1].v_.uv2_) = aex_pptk_join((stack->sym_data_[0].v_.uv2_), (stack->sym_data_[1].v_.uv1_).tk_); (stack->sym_data_[0].v_.uv2_) = (stack->sym_data_[1].v_.uv1_).tk_ = NULL; }
#line 2040 "src/pp/pp_macro_expander.c"
              }
              C45:;
            }
            break;
            /* arg: arg OBJECT */
            case 25: {
              stack->slot_1_has_sym_data_ = 1;
              stack->slot_1_sym_ = AEX_PPME_ARG;
              stack->continue_at_ = 46;
              {
#line 95 "grammar/pp/pp_macro_expander.cbrt"
                (stack->stack_[1].v_.uv2_) = NULL;
#line 2053 "src/pp/pp_macro_expander.c"
              }
              C46:;
              stack->continue_at_ = 47;
              {
#line 270 "grammar/pp/pp_macro_expander.cbrt"
                { (stack->stack_[1].v_.uv2_) = aex_pptk_join((stack->sym_data_[0].v_.uv2_), (stack->sym_data_[1].v_.uv1_).tk_); (stack->sym_data_[0].v_.uv2_) = (stack->sym_data_[1].v_.uv1_).tk_ = NULL; }
#line 2060 "src/pp/pp_macro_expander.c"
              }
              C47:;
            }
            break;
            /* arg: arg WS_TOK */
            case 26: {
              stack->slot_1_has_sym_data_ = 1;
              stack->slot_1_sym_ = AEX_PPME_ARG;
              stack->continue_at_ = 48;
              {
#line 95 "grammar/pp/pp_macro_expander.cbrt"
                (stack->stack_[1].v_.uv2_) = NULL;
#line 2073 "src/pp/pp_macro_expander.c"
              }
              C48:;
              stack->continue_at_ = 49;
              {
#line 271 "grammar/pp/pp_macro_expander.cbrt"
                { (stack->stack_[1].v_.uv2_) = aex_pptk_join((stack->sym_data_[0].v_.uv2_), (stack->sym_data_[1].v_.uv0_)); (stack->sym_data_[0].v_.uv2_) = (stack->sym_data_[1].v_.uv0_) = NULL; }
#line 2080 "src/pp/pp_macro_expander.c"
              }
              C49:;
            }
            break;
            /* arg: arg OTHER */
            case 27: {
              stack->slot_1_has_sym_data_ = 1;
              stack->slot_1_sym_ = AEX_PPME_ARG;
              stack->continue_at_ = 50;
              {
#line 95 "grammar/pp/pp_macro_expander.cbrt"
                (stack->stack_[1].v_.uv2_) = NULL;
#line 2093 "src/pp/pp_macro_expander.c"
              }
              C50:;
              stack->continue_at_ = 51;
              {
#line 272 "grammar/pp/pp_macro_expander.cbrt"
                { (stack->stack_[1].v_.uv2_) = aex_pptk_join((stack->sym_data_[0].v_.uv2_), (stack->sym_data_[1].v_.uv0_)); (stack->sym_data_[0].v_.uv2_) = (stack->sym_data_[1].v_.uv0_) = NULL; }
#line 2100 "src/pp/pp_macro_expander.c"
              }
              C51:;
            }
            break;
            /* arg: arg PAR_OPEN par-span PAR_CLOSE */
            case 28: {
              stack->slot_1_has_sym_data_ = 1;
              stack->slot_1_sym_ = AEX_PPME_ARG;
              stack->continue_at_ = 52;
              {
#line 95 "grammar/pp/pp_macro_expander.cbrt"
                (stack->stack_[1].v_.uv2_) = NULL;
#line 2113 "src/pp/pp_macro_expander.c"
              }
              C52:;
              stack->continue_at_ = 53;
              {
#line 273 "grammar/pp/pp_macro_expander.cbrt"
                {
  (stack->stack_[1].v_.uv2_) = aex_pptk_join((stack->sym_data_[0].v_.uv2_), (stack->sym_data_[1].v_.uv0_));
  (stack->stack_[1].v_.uv2_) = aex_pptk_join((stack->stack_[1].v_.uv2_), (stack->sym_data_[2].v_.uv2_));
  (stack->stack_[1].v_.uv2_) = aex_pptk_join((stack->stack_[1].v_.uv2_), (stack->sym_data_[3].v_.uv0_));
  (stack->sym_data_[0].v_.uv2_) = (stack->sym_data_[1].v_.uv0_) = (stack->sym_data_[2].v_.uv2_) = (stack->sym_data_[3].v_.uv0_) = NULL;
}
#line 2125 "src/pp/pp_macro_expander.c"
              }
              C53:;
            }
            break;
            /* par-span: */
            case 29: {
              stack->slot_1_has_sym_data_ = 1;
              stack->slot_1_sym_ = AEX_PPME_PAR_SPAN;
              stack->continue_at_ = 54;
              {
#line 95 "grammar/pp/pp_macro_expander.cbrt"
                (stack->stack_[1].v_.uv2_) = NULL;
#line 2138 "src/pp/pp_macro_expander.c"
              }
              C54:;
            }
            break;
            /* par-span: par-span IDENT */
            case 30: {
              stack->slot_1_has_sym_data_ = 1;
              stack->slot_1_sym_ = AEX_PPME_PAR_SPAN;
              stack->continue_at_ = 55;
              {
#line 95 "grammar/pp/pp_macro_expander.cbrt"
                (stack->stack_[1].v_.uv2_) = NULL;
#line 2151 "src/pp/pp_macro_expander.c"
              }
              C55:;
              stack->continue_at_ = 56;
              {
#line 282 "grammar/pp/pp_macro_expander.cbrt"
                { (stack->stack_[1].v_.uv2_) = aex_pptk_join((stack->sym_data_[0].v_.uv2_), (stack->sym_data_[1].v_.uv0_)); (stack->sym_data_[0].v_.uv2_) = (stack->sym_data_[1].v_.uv0_) = NULL; }
#line 2158 "src/pp/pp_macro_expander.c"
              }
              C56:;
            }
            break;
            /* par-span: par-span FUNCTION */
            case 31: {
              stack->slot_1_has_sym_data_ = 1;
              stack->slot_1_sym_ = AEX_PPME_PAR_SPAN;
              stack->continue_at_ = 57;
              {
#line 95 "grammar/pp/pp_macro_expander.cbrt"
                (stack->stack_[1].v_.uv2_) = NULL;
#line 2171 "src/pp/pp_macro_expander.c"
              }
              C57:;
              stack->continue_at_ = 58;
              {
#line 283 "grammar/pp/pp_macro_expander.cbrt"
                { (stack->stack_[1].v_.uv2_) = aex_pptk_join((stack->sym_data_[0].v_.uv2_), (stack->sym_data_[1].v_.uv1_).tk_); (stack->sym_data_[0].v_.uv2_) = (stack->sym_data_[1].v_.uv1_).tk_ = NULL; }
#line 2178 "src/pp/pp_macro_expander.c"
              }
              C58:;
            }
            break;
            /* par-span: par-span OBJECT */
            case 32: {
              stack->slot_1_has_sym_data_ = 1;
              stack->slot_1_sym_ = AEX_PPME_PAR_SPAN;
              stack->continue_at_ = 59;
              {
#line 95 "grammar/pp/pp_macro_expander.cbrt"
                (stack->stack_[1].v_.uv2_) = NULL;
#line 2191 "src/pp/pp_macro_expander.c"
              }
              C59:;
              stack->continue_at_ = 60;
              {
#line 284 "grammar/pp/pp_macro_expander.cbrt"
                { (stack->stack_[1].v_.uv2_) = aex_pptk_join((stack->sym_data_[0].v_.uv2_), (stack->sym_data_[1].v_.uv1_).tk_); (stack->sym_data_[0].v_.uv2_) = (stack->sym_data_[1].v_.uv1_).tk_ = NULL; }
#line 2198 "src/pp/pp_macro_expander.c"
              }
              C60:;
            }
            break;
            /* par-span: par-span COMMA */
            case 33: {
              stack->slot_1_has_sym_data_ = 1;
              stack->slot_1_sym_ = AEX_PPME_PAR_SPAN;
              stack->continue_at_ = 61;
              {
#line 95 "grammar/pp/pp_macro_expander.cbrt"
                (stack->stack_[1].v_.uv2_) = NULL;
#line 2211 "src/pp/pp_macro_expander.c"
              }
              C61:;
              stack->continue_at_ = 62;
              {
#line 285 "grammar/pp/pp_macro_expander.cbrt"
                { (stack->stack_[1].v_.uv2_) = aex_pptk_join((stack->sym_data_[0].v_.uv2_), (stack->sym_data_[1].v_.uv0_)); (stack->sym_data_[0].v_.uv2_) = (stack->sym_data_[1].v_.uv0_) = NULL; }
#line 2218 "src/pp/pp_macro_expander.c"
              }
              C62:;
            }
            break;
            /* par-span: par-span WS_TOK */
            case 34: {
              stack->slot_1_has_sym_data_ = 1;
              stack->slot_1_sym_ = AEX_PPME_PAR_SPAN;
              stack->continue_at_ = 63;
              {
#line 95 "grammar/pp/pp_macro_expander.cbrt"
                (stack->stack_[1].v_.uv2_) = NULL;
#line 2231 "src/pp/pp_macro_expander.c"
              }
              C63:;
              stack->continue_at_ = 64;
              {
#line 286 "grammar/pp/pp_macro_expander.cbrt"
                { (stack->stack_[1].v_.uv2_) = aex_pptk_join((stack->sym_data_[0].v_.uv2_), (stack->sym_data_[1].v_.uv0_)); (stack->sym_data_[0].v_.uv2_) = (stack->sym_data_[1].v_.uv0_) = NULL; }
#line 2238 "src/pp/pp_macro_expander.c"
              }
              C64:;
            }
            break;
            /* par-span: par-span OTHER */
            case 35: {
              stack->slot_1_has_sym_data_ = 1;
              stack->slot_1_sym_ = AEX_PPME_PAR_SPAN;
              stack->continue_at_ = 65;
              {
#line 95 "grammar/pp/pp_macro_expander.cbrt"
                (stack->stack_[1].v_.uv2_) = NULL;
#line 2251 "src/pp/pp_macro_expander.c"
              }
              C65:;
              stack->continue_at_ = 66;
              {
#line 287 "grammar/pp/pp_macro_expander.cbrt"
                { (stack->stack_[1].v_.uv2_) = aex_pptk_join((stack->sym_data_[0].v_.uv2_), (stack->sym_data_[1].v_.uv0_)); (stack->sym_data_[0].v_.uv2_) = (stack->sym_data_[1].v_.uv0_) = NULL; }
#line 2258 "src/pp/pp_macro_expander.c"
              }
              C66:;
            }
            break;
            /* par-span: par-span PAR_OPEN par-span PAR_CLOSE */
            case 36: {
              stack->slot_1_has_sym_data_ = 1;
              stack->slot_1_sym_ = AEX_PPME_PAR_SPAN;
              stack->continue_at_ = 67;
              {
#line 95 "grammar/pp/pp_macro_expander.cbrt"
                (stack->stack_[1].v_.uv2_) = NULL;
#line 2271 "src/pp/pp_macro_expander.c"
              }
              C67:;
              stack->continue_at_ = 68;
              {
#line 288 "grammar/pp/pp_macro_expander.cbrt"
                {
  (stack->stack_[1].v_.uv2_) = aex_pptk_join((stack->sym_data_[0].v_.uv2_), (stack->sym_data_[1].v_.uv0_));
  (stack->stack_[1].v_.uv2_) = aex_pptk_join((stack->stack_[1].v_.uv2_), (stack->sym_data_[2].v_.uv2_));
  (stack->stack_[1].v_.uv2_) = aex_pptk_join((stack->stack_[1].v_.uv2_), (stack->sym_data_[3].v_.uv0_));
  (stack->sym_data_[0].v_.uv2_) = (stack->sym_data_[1].v_.uv0_) = (stack->sym_data_[2].v_.uv2_) = (stack->sym_data_[3].v_.uv0_) = NULL;
}
#line 2283 "src/pp/pp_macro_expander.c"
              }
              C68:;
            }
            break;
            /* ws-opt-emit: */
            case 37: {
            }
            break;
            /* ws-opt-emit: ws-opt-emit WS_TOK */
            case 38: {
              stack->continue_at_ = 69;
              {
#line 297 "grammar/pp/pp_macro_expander.cbrt"
                {
  *pp_output_chain = aex_pptk_join(*pp_output_chain, (stack->sym_data_[1].v_.uv0_));
  (stack->sym_data_[1].v_.uv0_) = NULL;
}
#line 2301 "src/pp/pp_macro_expander.c"
              }
              C69:;
            }
            break;
            /* ws-opt: */
            case 39: {
              stack->slot_1_has_sym_data_ = 1;
              stack->slot_1_sym_ = AEX_PPME_WS_OPT;
              stack->continue_at_ = 70;
              {
#line 95 "grammar/pp/pp_macro_expander.cbrt"
                (stack->stack_[1].v_.uv2_) = NULL;
#line 2314 "src/pp/pp_macro_expander.c"
              }
              C70:;
            }
            break;
            /* ws-opt: ws-opt WS_TOK */
            case 40: {
              stack->slot_1_has_sym_data_ = 1;
              stack->slot_1_sym_ = AEX_PPME_WS_OPT;
              stack->continue_at_ = 71;
              {
#line 95 "grammar/pp/pp_macro_expander.cbrt"
                (stack->stack_[1].v_.uv2_) = NULL;
#line 2327 "src/pp/pp_macro_expander.c"
              }
              C71:;
              stack->continue_at_ = 72;
              {
#line 304 "grammar/pp/pp_macro_expander.cbrt"
                { 
  (stack->stack_[1].v_.uv2_) = aex_pptk_join((stack->sym_data_[0].v_.uv2_), (stack->sym_data_[1].v_.uv0_));
  (stack->sym_data_[0].v_.uv2_) = (stack->sym_data_[1].v_.uv0_) = NULL;
}
#line 2337 "src/pp/pp_macro_expander.c"
              }
              C72:;
            }
            break;
          } /* switch */
        } /* scope guard */
        
        /* Free symdata for every symbol in the production, including the first slot where we will soon
        * push nonterminal_data_reduced_to */
        for (stack->sym_idx_ = stack->pos_ - stack->current_production_length_; stack->sym_idx_ < stack->pos_; ++stack->sym_idx_) {
          switch (stack->stack_[stack->sym_idx_].state_) {
            case 2: /* IDENT */
            case 3: /* COMMA */
            case 4: /* PAR_CLOSE */
            case 5: /* OTHER */
            case 6: /* PAR_CLOSE */
            case 8: /* COMMA */
            case 10: /* IDENT */
            case 13: /* WS_TOK */
            case 14: /* OTHER */
            case 15: /* PAR_CLOSE */
            case 16: /* IDENT */
            case 19: /* COMMA */
            case 20: /* WS_TOK */
            case 21: /* OTHER */
            case 22: /* PAR_CLOSE */
            case 24: /* PAR_OPEN */
            case 26: /* PAR_OPEN */
            case 28: /* PAR_OPEN */
            case 32: /* PAR_CLOSE */
            case 34: /* IDENT */
            case 35: /* PAR_CLOSE */
            case 38: /* PAR_CLOSE */
            case 41: /* PAR_CLOSE */
            case 43: /* DEFINED */
            case 45: /* PAR_OPEN */
            case 46: /* IDENT */
            case 49: /* DEFINED */
            case 50: /* WS_TOK */
            case 52: /* DEFINED */
            case 54: /* PAR_OPEN */
            case 55: /* WS_TOK */
            {
              {
#line 70 "grammar/pp/pp_macro_expander.cbrt"
                aex_pptk_free(((stack->stack_ + stack->sym_idx_)->v_.uv0_));
#line 2384 "src/pp/pp_macro_expander.c"
              }
              
            }
            break;
            case 11: /* FUNCTION */
            case 12: /* OBJECT */
            case 17: /* FUNCTION */
            case 18: /* OBJECT */
            case 30: /* FUNCTION */
            case 31: /* OBJECT */
            case 37: /* FUNCTION */
            case 40: /* OBJECT */
            case 47: /* FUNCTION */
            case 48: /* OBJECT */
            {
              {
#line 77 "grammar/pp/pp_macro_expander.cbrt"
                aex_pptk_free(((stack->stack_ + stack->sym_idx_)->v_.uv1_).tk_); aex_macro_free(((stack->stack_ + stack->sym_idx_)->v_.uv1_).m_); /* Reduction of OBJECT drops a reference and might free the macro */
#line 2403 "src/pp/pp_macro_expander.c"
              }
              
            }
            break;
            case 7: /* arg */
            case 23: /* par-span */
            case 25: /* par-span */
            case 27: /* arg */
            case 29: /* ws-opt */
            case 33: /* ws-opt */
            case 36: /* ws-opt */
            case 39: /* ws-opt */
            case 42: /* ws-opt */
            case 44: /* ws-opt */
            case 51: /* ws-opt */
            {
              {
#line 97 "grammar/pp/pp_macro_expander.cbrt"
                aex_pptk_free(((stack->stack_ + stack->sym_idx_)->v_.uv2_));
#line 2423 "src/pp/pp_macro_expander.c"
              }
              
            }
            break;
            case 9: /* args */
            {
              {
#line 103 "grammar/pp/pp_macro_expander.cbrt"
                aex_macro_arg_inst_free(((stack->stack_ + stack->sym_idx_)->v_.uv3_));
#line 2433 "src/pp/pp_macro_expander.c"
              }
              
            }
            break;
          } /* switch */
        } /* for */
        stack->pos_ -= stack->current_production_length_;
        stack->top_of_stack_has_sym_data_ = stack->top_of_stack_has_common_data_ = 1;
        action = aex_ppme_parse_table[aex_ppme_num_columns * stack->stack_[stack->pos_ - 1].state_ + (stack->current_production_nonterminal_ - aex_ppme_minimum_sym)];
        if (action <= 0) {
          stack->continue_at_ = 0;
          /* Internal error */
          return _AEX_PPME_INTERNAL_ERROR;
        }
        if (stack->num_stack_allocated_ == stack->pos_) {
          stack->action_preservation_ = action /* action for a "goto" shift is the ordinal */;
          size_t new_num_allocated;
          if (stack->num_stack_allocated_) {
            new_num_allocated = stack->num_stack_allocated_ * 2;
            if (new_num_allocated <= stack->num_stack_allocated_) {
              /* Overflow in allocation */
              return _AEX_PPME_OVERFLOW;
            }
          }
          else {
            new_num_allocated = 16;
          }
          
          if (new_num_allocated > (SIZE_MAX / sizeof(struct aex_ppme_sym_data))) {
            /* Overflow in allocation */
            return _AEX_PPME_OVERFLOW;
          }
          
          stack->new_buf_ = (struct aex_ppme_sym_data *)malloc(new_num_allocated * sizeof(struct aex_ppme_sym_data));
          if (!stack->new_buf_) {
            /* Out of memory */
            return _AEX_PPME_NO_MEMORY;
          }
          stack->new_buf_num_allocated_ = new_num_allocated;
          for (stack->new_buf_sym_partial_pos_ = 0; stack->new_buf_sym_partial_pos_ < stack->pos_; ++stack->new_buf_sym_partial_pos_) {
            stack->new_buf_[stack->new_buf_sym_partial_pos_].state_ = stack->stack_[stack->new_buf_sym_partial_pos_].state_;
            stack->newbuf_pos_has_common_data_ = stack->newbuf_pos_has_sym_data_ = 0;
            stack->stack_newbuf_pos_has_common_data_ = stack->stack_newbuf_pos_has_sym_data_ = 1;
            if ((stack->new_buf_sym_partial_pos_ == 0) || (stack->new_buf_sym_partial_pos_ == 1)) {
              int need_sym_move;
              int sym_to_move;
              sym_to_move = 0; /* silence a waring with this explicit initialization */
              need_sym_move = 0;
              if (stack->new_buf_sym_partial_pos_ == 0) {
                /* slot 0 goes unused in scannerless operation */
                need_sym_move = 0;
              }
              else if (stack->new_buf_sym_partial_pos_ == 1) {
                need_sym_move = stack->slot_1_has_sym_data_;
                sym_to_move = stack->slot_1_sym_;
              }
              if (need_sym_move) {
                switch (sym_to_move) {
                  case AEX_PPME_IDENT:
                  case AEX_PPME_DEFINED:
                  case AEX_PPME_PAR_OPEN:
                  case AEX_PPME_PAR_CLOSE:
                  case AEX_PPME_COMMA:
                  case AEX_PPME_WS_TOK:
                  case AEX_PPME_OTHER:
                  stack->newbuf_pos_has_sym_data_ = 1;
                  stack->continue_at_ = 73;
                  {
#line 68 "grammar/pp/pp_macro_expander.cbrt"
                    stack->new_buf_[stack->new_buf_sym_partial_pos_].v_.uv0_ = NULL;
#line 2504 "src/pp/pp_macro_expander.c"
                  }
                  C73:;
                  stack->continue_at_ = 74;
                  {
#line 69 "grammar/pp/pp_macro_expander.cbrt"
                    stack->new_buf_[stack->new_buf_sym_partial_pos_].v_.uv0_ = (stack->stack_[stack->new_buf_sym_partial_pos_].v_.uv0_); (stack->stack_[stack->new_buf_sym_partial_pos_].v_.uv0_) = NULL;
#line 2511 "src/pp/pp_macro_expander.c"
                  }
                  C74:;
                  {
#line 70 "grammar/pp/pp_macro_expander.cbrt"
                    aex_pptk_free(((stack->stack_ + stack->new_buf_sym_partial_pos_)->v_.uv0_));
#line 2517 "src/pp/pp_macro_expander.c"
                  }
                  stack->stack_newbuf_pos_has_sym_data_ = 0;
                  
                  break;
                  case AEX_PPME_OBJECT:
                  case AEX_PPME_FUNCTION:
                  stack->newbuf_pos_has_sym_data_ = 1;
                  stack->continue_at_ = 75;
                  {
#line 75 "grammar/pp/pp_macro_expander.cbrt"
                    stack->new_buf_[stack->new_buf_sym_partial_pos_].v_.uv1_.tk_ = NULL; stack->new_buf_[stack->new_buf_sym_partial_pos_].v_.uv1_.m_ = NULL;
#line 2529 "src/pp/pp_macro_expander.c"
                  }
                  C75:;
                  stack->continue_at_ = 76;
                  {
#line 76 "grammar/pp/pp_macro_expander.cbrt"
                    stack->new_buf_[stack->new_buf_sym_partial_pos_].v_.uv1_.tk_ = (stack->stack_[stack->new_buf_sym_partial_pos_].v_.uv1_).tk_; stack->new_buf_[stack->new_buf_sym_partial_pos_].v_.uv1_.m_ = (stack->stack_[stack->new_buf_sym_partial_pos_].v_.uv1_).m_;
#line 2536 "src/pp/pp_macro_expander.c"
                  }
                  C76:;
                  {
#line 77 "grammar/pp/pp_macro_expander.cbrt"
                    aex_pptk_free(((stack->stack_ + stack->new_buf_sym_partial_pos_)->v_.uv1_).tk_); aex_macro_free(((stack->stack_ + stack->new_buf_sym_partial_pos_)->v_.uv1_).m_); /* Reduction of OBJECT drops a reference and might free the macro */
#line 2542 "src/pp/pp_macro_expander.c"
                  }
                  stack->stack_newbuf_pos_has_sym_data_ = 0;
                  
                  break;
                  case AEX_PPME_NON_FUNCTION:
                  case AEX_PPME_WS_OPT:
                  case AEX_PPME_PAR_SPAN:
                  case AEX_PPME_ARG:
                  stack->newbuf_pos_has_sym_data_ = 1;
                  stack->continue_at_ = 77;
                  {
#line 95 "grammar/pp/pp_macro_expander.cbrt"
                    stack->new_buf_[stack->new_buf_sym_partial_pos_].v_.uv2_ = NULL;
#line 2556 "src/pp/pp_macro_expander.c"
                  }
                  C77:;
                  stack->continue_at_ = 78;
                  {
#line 96 "grammar/pp/pp_macro_expander.cbrt"
                    stack->new_buf_[stack->new_buf_sym_partial_pos_].v_.uv2_ = (stack->stack_[stack->new_buf_sym_partial_pos_].v_.uv2_); (stack->stack_[stack->new_buf_sym_partial_pos_].v_.uv2_) = NULL;
#line 2563 "src/pp/pp_macro_expander.c"
                  }
                  C78:;
                  {
#line 97 "grammar/pp/pp_macro_expander.cbrt"
                    aex_pptk_free(((stack->stack_ + stack->new_buf_sym_partial_pos_)->v_.uv2_));
#line 2569 "src/pp/pp_macro_expander.c"
                  }
                  stack->stack_newbuf_pos_has_sym_data_ = 0;
                  
                  break;
                  case AEX_PPME_ARGS:
                  stack->newbuf_pos_has_sym_data_ = 1;
                  stack->continue_at_ = 79;
                  {
#line 101 "grammar/pp/pp_macro_expander.cbrt"
                    stack->new_buf_[stack->new_buf_sym_partial_pos_].v_.uv3_ = NULL;
#line 2580 "src/pp/pp_macro_expander.c"
                  }
                  C79:;
                  stack->continue_at_ = 80;
                  {
#line 102 "grammar/pp/pp_macro_expander.cbrt"
                    stack->new_buf_[stack->new_buf_sym_partial_pos_].v_.uv3_ = (stack->stack_[stack->new_buf_sym_partial_pos_].v_.uv3_); (stack->stack_[stack->new_buf_sym_partial_pos_].v_.uv3_) = NULL;
#line 2587 "src/pp/pp_macro_expander.c"
                  }
                  C80:;
                  {
#line 103 "grammar/pp/pp_macro_expander.cbrt"
                    aex_macro_arg_inst_free(((stack->stack_ + stack->new_buf_sym_partial_pos_)->v_.uv3_));
#line 2593 "src/pp/pp_macro_expander.c"
                  }
                  stack->stack_newbuf_pos_has_sym_data_ = 0;
                  
                  break;
                }
              }
            }
            else /* not 0 or 1, but >= 2 state derived sym */ {
              switch (stack->stack_[stack->new_buf_sym_partial_pos_].state_) {
                case 2: /* IDENT */
                case 3: /* COMMA */
                case 4: /* PAR_CLOSE */
                case 5: /* OTHER */
                case 6: /* PAR_CLOSE */
                case 8: /* COMMA */
                case 10: /* IDENT */
                case 13: /* WS_TOK */
                case 14: /* OTHER */
                case 15: /* PAR_CLOSE */
                case 16: /* IDENT */
                case 19: /* COMMA */
                case 20: /* WS_TOK */
                case 21: /* OTHER */
                case 22: /* PAR_CLOSE */
                case 24: /* PAR_OPEN */
                case 26: /* PAR_OPEN */
                case 28: /* PAR_OPEN */
                case 32: /* PAR_CLOSE */
                case 34: /* IDENT */
                case 35: /* PAR_CLOSE */
                case 38: /* PAR_CLOSE */
                case 41: /* PAR_CLOSE */
                case 43: /* DEFINED */
                case 45: /* PAR_OPEN */
                case 46: /* IDENT */
                case 49: /* DEFINED */
                case 50: /* WS_TOK */
                case 52: /* DEFINED */
                case 54: /* PAR_OPEN */
                case 55: /* WS_TOK */
                stack->newbuf_pos_has_sym_data_ = 1;
                stack->continue_at_ = 81;
                {
#line 68 "grammar/pp/pp_macro_expander.cbrt"
                  stack->new_buf_[stack->new_buf_sym_partial_pos_].v_.uv0_ = NULL;
#line 2639 "src/pp/pp_macro_expander.c"
                }
                C81:;
                stack->continue_at_ = 82;
                {
#line 69 "grammar/pp/pp_macro_expander.cbrt"
                  stack->new_buf_[stack->new_buf_sym_partial_pos_].v_.uv0_ = (stack->stack_[stack->new_buf_sym_partial_pos_].v_.uv0_); (stack->stack_[stack->new_buf_sym_partial_pos_].v_.uv0_) = NULL;
#line 2646 "src/pp/pp_macro_expander.c"
                }
                C82:;
                {
#line 70 "grammar/pp/pp_macro_expander.cbrt"
                  aex_pptk_free(((stack->stack_ + stack->new_buf_sym_partial_pos_)->v_.uv0_));
#line 2652 "src/pp/pp_macro_expander.c"
                }
                stack->stack_newbuf_pos_has_sym_data_ = 0;
                break;
                
                case 11: /* FUNCTION */
                case 12: /* OBJECT */
                case 17: /* FUNCTION */
                case 18: /* OBJECT */
                case 30: /* FUNCTION */
                case 31: /* OBJECT */
                case 37: /* FUNCTION */
                case 40: /* OBJECT */
                case 47: /* FUNCTION */
                case 48: /* OBJECT */
                stack->newbuf_pos_has_sym_data_ = 1;
                stack->continue_at_ = 83;
                {
#line 75 "grammar/pp/pp_macro_expander.cbrt"
                  stack->new_buf_[stack->new_buf_sym_partial_pos_].v_.uv1_.tk_ = NULL; stack->new_buf_[stack->new_buf_sym_partial_pos_].v_.uv1_.m_ = NULL;
#line 2672 "src/pp/pp_macro_expander.c"
                }
                C83:;
                stack->continue_at_ = 84;
                {
#line 76 "grammar/pp/pp_macro_expander.cbrt"
                  stack->new_buf_[stack->new_buf_sym_partial_pos_].v_.uv1_.tk_ = (stack->stack_[stack->new_buf_sym_partial_pos_].v_.uv1_).tk_; stack->new_buf_[stack->new_buf_sym_partial_pos_].v_.uv1_.m_ = (stack->stack_[stack->new_buf_sym_partial_pos_].v_.uv1_).m_;
#line 2679 "src/pp/pp_macro_expander.c"
                }
                C84:;
                {
#line 77 "grammar/pp/pp_macro_expander.cbrt"
                  aex_pptk_free(((stack->stack_ + stack->new_buf_sym_partial_pos_)->v_.uv1_).tk_); aex_macro_free(((stack->stack_ + stack->new_buf_sym_partial_pos_)->v_.uv1_).m_); /* Reduction of OBJECT drops a reference and might free the macro */
#line 2685 "src/pp/pp_macro_expander.c"
                }
                stack->stack_newbuf_pos_has_sym_data_ = 0;
                break;
                
                case 7: /* arg */
                case 23: /* par-span */
                case 25: /* par-span */
                case 27: /* arg */
                case 29: /* ws-opt */
                case 33: /* ws-opt */
                case 36: /* ws-opt */
                case 39: /* ws-opt */
                case 42: /* ws-opt */
                case 44: /* ws-opt */
                case 51: /* ws-opt */
                stack->newbuf_pos_has_sym_data_ = 1;
                stack->continue_at_ = 85;
                {
#line 95 "grammar/pp/pp_macro_expander.cbrt"
                  stack->new_buf_[stack->new_buf_sym_partial_pos_].v_.uv2_ = NULL;
#line 2706 "src/pp/pp_macro_expander.c"
                }
                C85:;
                stack->continue_at_ = 86;
                {
#line 96 "grammar/pp/pp_macro_expander.cbrt"
                  stack->new_buf_[stack->new_buf_sym_partial_pos_].v_.uv2_ = (stack->stack_[stack->new_buf_sym_partial_pos_].v_.uv2_); (stack->stack_[stack->new_buf_sym_partial_pos_].v_.uv2_) = NULL;
#line 2713 "src/pp/pp_macro_expander.c"
                }
                C86:;
                {
#line 97 "grammar/pp/pp_macro_expander.cbrt"
                  aex_pptk_free(((stack->stack_ + stack->new_buf_sym_partial_pos_)->v_.uv2_));
#line 2719 "src/pp/pp_macro_expander.c"
                }
                stack->stack_newbuf_pos_has_sym_data_ = 0;
                break;
                
                case 9: /* args */
                stack->newbuf_pos_has_sym_data_ = 1;
                stack->continue_at_ = 87;
                {
#line 101 "grammar/pp/pp_macro_expander.cbrt"
                  stack->new_buf_[stack->new_buf_sym_partial_pos_].v_.uv3_ = NULL;
#line 2730 "src/pp/pp_macro_expander.c"
                }
                C87:;
                stack->continue_at_ = 88;
                {
#line 102 "grammar/pp/pp_macro_expander.cbrt"
                  stack->new_buf_[stack->new_buf_sym_partial_pos_].v_.uv3_ = (stack->stack_[stack->new_buf_sym_partial_pos_].v_.uv3_); (stack->stack_[stack->new_buf_sym_partial_pos_].v_.uv3_) = NULL;
#line 2737 "src/pp/pp_macro_expander.c"
                }
                C88:;
                {
#line 103 "grammar/pp/pp_macro_expander.cbrt"
                  aex_macro_arg_inst_free(((stack->stack_ + stack->new_buf_sym_partial_pos_)->v_.uv3_));
#line 2743 "src/pp/pp_macro_expander.c"
                }
                stack->stack_newbuf_pos_has_sym_data_ = 0;
                break;
                
              } /* switch */
            }
          }
          if (stack->stack_) free(stack->stack_);
          stack->stack_ = stack->new_buf_;
          stack->new_buf_sym_partial_pos_ = 0;
          stack->new_buf_ = NULL;
          stack->num_stack_allocated_ = stack->new_buf_num_allocated_;
          action /* action for a "goto" shift is the ordinal */ = stack->action_preservation_;
        }
        stack->stack_[stack->pos_++].state_ = action /* action for a "goto" shift is the ordinal */;
        stack->top_of_stack_has_sym_data_ = 0;
        stack->top_of_stack_has_common_data_ = 0;
        switch(stack->stack_[stack->pos_ - 1].state_) {
          case 2: /* IDENT */
          case 3: /* COMMA */
          case 4: /* PAR_CLOSE */
          case 5: /* OTHER */
          case 6: /* PAR_CLOSE */
          case 8: /* COMMA */
          case 10: /* IDENT */
          case 13: /* WS_TOK */
          case 14: /* OTHER */
          case 15: /* PAR_CLOSE */
          case 16: /* IDENT */
          case 19: /* COMMA */
          case 20: /* WS_TOK */
          case 21: /* OTHER */
          case 22: /* PAR_CLOSE */
          case 24: /* PAR_OPEN */
          case 26: /* PAR_OPEN */
          case 28: /* PAR_OPEN */
          case 32: /* PAR_CLOSE */
          case 34: /* IDENT */
          case 35: /* PAR_CLOSE */
          case 38: /* PAR_CLOSE */
          case 41: /* PAR_CLOSE */
          case 43: /* DEFINED */
          case 45: /* PAR_OPEN */
          case 46: /* IDENT */
          case 49: /* DEFINED */
          case 50: /* WS_TOK */
          case 52: /* DEFINED */
          case 54: /* PAR_OPEN */
          case 55: /* WS_TOK */
          stack->top_of_stack_has_sym_data_ = 1;
          stack->continue_at_ = 89;
          {
#line 68 "grammar/pp/pp_macro_expander.cbrt"
            ((stack->stack_ + stack->pos_ - 1)->v_.uv0_) = NULL;
#line 2798 "src/pp/pp_macro_expander.c"
          }
          C89:;
          stack->continue_at_ = 90;
          {
#line 69 "grammar/pp/pp_macro_expander.cbrt"
            stack->stack_[stack->pos_ - 1].v_.uv0_ = (stack->stack_[1].v_.uv0_); (stack->stack_[1].v_.uv0_) = NULL;
#line 2805 "src/pp/pp_macro_expander.c"
          }
          C90:;
          {
#line 70 "grammar/pp/pp_macro_expander.cbrt"
            aex_pptk_free((stack->stack_[1].v_.uv0_));
#line 2811 "src/pp/pp_macro_expander.c"
          }
          break;
          case 11: /* FUNCTION */
          case 12: /* OBJECT */
          case 17: /* FUNCTION */
          case 18: /* OBJECT */
          case 30: /* FUNCTION */
          case 31: /* OBJECT */
          case 37: /* FUNCTION */
          case 40: /* OBJECT */
          case 47: /* FUNCTION */
          case 48: /* OBJECT */
          stack->top_of_stack_has_sym_data_ = 1;
          stack->continue_at_ = 91;
          {
#line 75 "grammar/pp/pp_macro_expander.cbrt"
            ((stack->stack_ + stack->pos_ - 1)->v_.uv1_).tk_ = NULL; ((stack->stack_ + stack->pos_ - 1)->v_.uv1_).m_ = NULL;
#line 2829 "src/pp/pp_macro_expander.c"
          }
          C91:;
          stack->continue_at_ = 92;
          {
#line 76 "grammar/pp/pp_macro_expander.cbrt"
            stack->stack_[stack->pos_ - 1].v_.uv1_.tk_ = (stack->stack_[1].v_.uv1_).tk_; stack->stack_[stack->pos_ - 1].v_.uv1_.m_ = (stack->stack_[1].v_.uv1_).m_;
#line 2836 "src/pp/pp_macro_expander.c"
          }
          C92:;
          {
#line 77 "grammar/pp/pp_macro_expander.cbrt"
            aex_pptk_free((stack->stack_[1].v_.uv1_).tk_); aex_macro_free((stack->stack_[1].v_.uv1_).m_); /* Reduction of OBJECT drops a reference and might free the macro */
#line 2842 "src/pp/pp_macro_expander.c"
          }
          break;
          case 7: /* arg */
          case 23: /* par-span */
          case 25: /* par-span */
          case 27: /* arg */
          case 29: /* ws-opt */
          case 33: /* ws-opt */
          case 36: /* ws-opt */
          case 39: /* ws-opt */
          case 42: /* ws-opt */
          case 44: /* ws-opt */
          case 51: /* ws-opt */
          stack->top_of_stack_has_sym_data_ = 1;
          stack->continue_at_ = 93;
          {
#line 95 "grammar/pp/pp_macro_expander.cbrt"
            ((stack->stack_ + stack->pos_ - 1)->v_.uv2_) = NULL;
#line 2861 "src/pp/pp_macro_expander.c"
          }
          C93:;
          stack->continue_at_ = 94;
          {
#line 96 "grammar/pp/pp_macro_expander.cbrt"
            stack->stack_[stack->pos_ - 1].v_.uv2_ = (stack->stack_[1].v_.uv2_); (stack->stack_[1].v_.uv2_) = NULL;
#line 2868 "src/pp/pp_macro_expander.c"
          }
          C94:;
          {
#line 97 "grammar/pp/pp_macro_expander.cbrt"
            aex_pptk_free((stack->stack_[1].v_.uv2_));
#line 2874 "src/pp/pp_macro_expander.c"
          }
          break;
          case 9: /* args */
          stack->top_of_stack_has_sym_data_ = 1;
          stack->continue_at_ = 95;
          {
#line 101 "grammar/pp/pp_macro_expander.cbrt"
            ((stack->stack_ + stack->pos_ - 1)->v_.uv3_) = NULL;
#line 2883 "src/pp/pp_macro_expander.c"
          }
          C95:;
          stack->continue_at_ = 96;
          {
#line 102 "grammar/pp/pp_macro_expander.cbrt"
            stack->stack_[stack->pos_ - 1].v_.uv3_ = (stack->stack_[1].v_.uv3_); (stack->stack_[1].v_.uv3_) = NULL;
#line 2890 "src/pp/pp_macro_expander.c"
          }
          C96:;
          {
#line 103 "grammar/pp/pp_macro_expander.cbrt"
            aex_macro_arg_inst_free((stack->stack_[1].v_.uv3_));
#line 2896 "src/pp/pp_macro_expander.c"
          }
          break;
        } /* switch (top of stack state) */
        stack->slot_1_has_sym_data_ = 0;
      } /* action < 0 */
      else /* action == 0 */ {
        /* check if we can recover using an error token. */
        size_t n;
        for (n = 0; n < stack->pos_; ++n) {
          stack->current_err_action_ = aex_ppme_parse_table[aex_ppme_num_columns * stack->stack_[n].state_ + (12 /* error token */ - aex_ppme_minimum_sym)];
          if (stack->current_err_action_ > 0) {
            /* we can transition on the error token somewhere on the stack */
            break;
          }
        }
        /* Enter error-token recovery mode given that such a recovery is possible */
        stack->error_recovery_ = (n != stack->pos_);
        /* Issue the error here */
        if (!stack->mute_error_turns_) {
          stack->mute_error_turns_ = 3;
          stack->continue_at_ = 0;
          /* Syntax error */
          return _AEX_PPME_SYNTAX_ERROR;
        }
        else {
          stack->mute_error_turns_--;
          if (sym == AEX_PPME_INPUT_END) {
            /* EOF means we cannot shift to recover, and errors are muted, so return completion */
            stack->pending_reset_ = 1;
            return _AEX_PPME_FINISH;
          }
          /* Retain EOF but discard any other sym so we make progress */
          stack->continue_at_ = 0;
          {
            if (*pp_input_chain) {                                                                \
              sym = g_aex_pptk_to_ppme_[(*pp_input_chain)->tok_];                                     \
              if ((!keep_defined) && (sym == AEX_PPME_DEFINED)) {                                     \
                sym = AEX_PPME_IDENT;                                                                 \
                }                                                                                   \
              if (sym == AEX_PPME_IDENT) {                                                            \
                struct macro *m = NULL;                                                           \
                m = mt_find(&pp->macro_table_, (*pp_input_chain)->text_, (*pp_input_chain)->text_len_); \
                if (m && !m->nested_invocation_) {                                                \
                  if (m->is_function_style_) {                                                    \
                    sym = AEX_PPME_FUNCTION;                                                          \
                    }                                                                               \
                  else {                                                                          \
                    sym = AEX_PPME_OBJECT;                                                            \
                    }                                                                               \
                  }                                                                                 \
                }                                                                                   \
              }                                                                                     \
            else {                                                                                \
              if (!is_final) return _AEX_PPME_FEED_ME;                                                \
              sym = AEX_PPME_INPUT_END;                                                               \
              }
            
          }
        }
      }
    } /* !stack->error_recovery_ */
    if (stack->error_recovery_) {
      size_t n;
      n = stack->pos_;
      if (n) {
        do {
          --n;
          /* Can we shift an error token? */
          stack->current_err_action_ = aex_ppme_parse_table[aex_ppme_num_columns * stack->stack_[n].state_ + (12 /* error token */ - aex_ppme_minimum_sym)];
          if (stack->current_err_action_ > 0) {
            /* Does the resulting state accept the current symbol? */
            int err_sym_action;
            err_sym_action = aex_ppme_parse_table[aex_ppme_num_columns * stack->current_err_action_ + (sym - aex_ppme_minimum_sym)];
            if (err_sym_action) {
              /* Current symbol is accepted, recover error condition by shifting the error token and then process the symbol as usual */
              /* Free symdata for every symbol up to the state where we will shift the error token */
              for (stack->sym_idx_ = n + 1; stack->sym_idx_ < stack->pos_; ++stack->sym_idx_) {
                switch (stack->stack_[stack->sym_idx_].state_) {
                  case 2: /* IDENT */
                  case 3: /* COMMA */
                  case 4: /* PAR_CLOSE */
                  case 5: /* OTHER */
                  case 6: /* PAR_CLOSE */
                  case 8: /* COMMA */
                  case 10: /* IDENT */
                  case 13: /* WS_TOK */
                  case 14: /* OTHER */
                  case 15: /* PAR_CLOSE */
                  case 16: /* IDENT */
                  case 19: /* COMMA */
                  case 20: /* WS_TOK */
                  case 21: /* OTHER */
                  case 22: /* PAR_CLOSE */
                  case 24: /* PAR_OPEN */
                  case 26: /* PAR_OPEN */
                  case 28: /* PAR_OPEN */
                  case 32: /* PAR_CLOSE */
                  case 34: /* IDENT */
                  case 35: /* PAR_CLOSE */
                  case 38: /* PAR_CLOSE */
                  case 41: /* PAR_CLOSE */
                  case 43: /* DEFINED */
                  case 45: /* PAR_OPEN */
                  case 46: /* IDENT */
                  case 49: /* DEFINED */
                  case 50: /* WS_TOK */
                  case 52: /* DEFINED */
                  case 54: /* PAR_OPEN */
                  case 55: /* WS_TOK */
                  {
#line 70 "grammar/pp/pp_macro_expander.cbrt"
                    aex_pptk_free(((stack->stack_ + stack->sym_idx_)->v_.uv0_));
#line 3009 "src/pp/pp_macro_expander.c"
                  }
                  break;
                  case 11: /* FUNCTION */
                  case 12: /* OBJECT */
                  case 17: /* FUNCTION */
                  case 18: /* OBJECT */
                  case 30: /* FUNCTION */
                  case 31: /* OBJECT */
                  case 37: /* FUNCTION */
                  case 40: /* OBJECT */
                  case 47: /* FUNCTION */
                  case 48: /* OBJECT */
                  {
#line 77 "grammar/pp/pp_macro_expander.cbrt"
                    aex_pptk_free(((stack->stack_ + stack->sym_idx_)->v_.uv1_).tk_); aex_macro_free(((stack->stack_ + stack->sym_idx_)->v_.uv1_).m_); /* Reduction of OBJECT drops a reference and might free the macro */
#line 3025 "src/pp/pp_macro_expander.c"
                  }
                  break;
                  case 7: /* arg */
                  case 23: /* par-span */
                  case 25: /* par-span */
                  case 27: /* arg */
                  case 29: /* ws-opt */
                  case 33: /* ws-opt */
                  case 36: /* ws-opt */
                  case 39: /* ws-opt */
                  case 42: /* ws-opt */
                  case 44: /* ws-opt */
                  case 51: /* ws-opt */
                  {
#line 97 "grammar/pp/pp_macro_expander.cbrt"
                    aex_pptk_free(((stack->stack_ + stack->sym_idx_)->v_.uv2_));
#line 3042 "src/pp/pp_macro_expander.c"
                  }
                  break;
                  case 9: /* args */
                  {
#line 103 "grammar/pp/pp_macro_expander.cbrt"
                    aex_macro_arg_inst_free(((stack->stack_ + stack->sym_idx_)->v_.uv3_));
#line 3049 "src/pp/pp_macro_expander.c"
                  }
                  break;
                } /* switch */
              } /* for */
              stack->pos_ = n + 1;
              stack->top_of_stack_has_sym_data_ = stack->top_of_stack_has_common_data_ = 1;
              /* Push the state of the error transition */
              if (stack->num_stack_allocated_ == stack->pos_) {
                stack->action_preservation_ = stack->current_err_action_;
                size_t new_num_allocated;
                if (stack->num_stack_allocated_) {
                  new_num_allocated = stack->num_stack_allocated_ * 2;
                  if (new_num_allocated <= stack->num_stack_allocated_) {
                    /* Overflow in allocation */
                    return _AEX_PPME_OVERFLOW;
                  }
                }
                else {
                  new_num_allocated = 16;
                }
                
                if (new_num_allocated > (SIZE_MAX / sizeof(struct aex_ppme_sym_data))) {
                  /* Overflow in allocation */
                  return _AEX_PPME_OVERFLOW;
                }
                
                stack->new_buf_ = (struct aex_ppme_sym_data *)malloc(new_num_allocated * sizeof(struct aex_ppme_sym_data));
                if (!stack->new_buf_) {
                  /* Out of memory */
                  return _AEX_PPME_NO_MEMORY;
                }
                stack->new_buf_num_allocated_ = new_num_allocated;
                for (stack->new_buf_sym_partial_pos_ = 0; stack->new_buf_sym_partial_pos_ < stack->pos_; ++stack->new_buf_sym_partial_pos_) {
                  stack->new_buf_[stack->new_buf_sym_partial_pos_].state_ = stack->stack_[stack->new_buf_sym_partial_pos_].state_;
                  stack->newbuf_pos_has_common_data_ = stack->newbuf_pos_has_sym_data_ = 0;
                  stack->stack_newbuf_pos_has_common_data_ = stack->stack_newbuf_pos_has_sym_data_ = 1;
                  if ((stack->new_buf_sym_partial_pos_ == 0) || (stack->new_buf_sym_partial_pos_ == 1)) {
                    int need_sym_move;
                    int sym_to_move;
                    sym_to_move = 0; /* silence a waring with this explicit initialization */
                    need_sym_move = 0;
                    if (stack->new_buf_sym_partial_pos_ == 0) {
                      /* slot 0 goes unused in scannerless operation */
                      need_sym_move = 0;
                    }
                    else if (stack->new_buf_sym_partial_pos_ == 1) {
                      need_sym_move = stack->slot_1_has_sym_data_;
                      sym_to_move = stack->slot_1_sym_;
                    }
                    if (need_sym_move) {
                      switch (sym_to_move) {
                        case AEX_PPME_IDENT:
                        case AEX_PPME_DEFINED:
                        case AEX_PPME_PAR_OPEN:
                        case AEX_PPME_PAR_CLOSE:
                        case AEX_PPME_COMMA:
                        case AEX_PPME_WS_TOK:
                        case AEX_PPME_OTHER:
                        stack->newbuf_pos_has_sym_data_ = 1;
                        stack->continue_at_ = 97;
                        {
#line 68 "grammar/pp/pp_macro_expander.cbrt"
                          stack->new_buf_[stack->new_buf_sym_partial_pos_].v_.uv0_ = NULL;
#line 3113 "src/pp/pp_macro_expander.c"
                        }
                        C97:;
                        stack->continue_at_ = 98;
                        {
#line 69 "grammar/pp/pp_macro_expander.cbrt"
                          stack->new_buf_[stack->new_buf_sym_partial_pos_].v_.uv0_ = (stack->stack_[stack->new_buf_sym_partial_pos_].v_.uv0_); (stack->stack_[stack->new_buf_sym_partial_pos_].v_.uv0_) = NULL;
#line 3120 "src/pp/pp_macro_expander.c"
                        }
                        C98:;
                        {
#line 70 "grammar/pp/pp_macro_expander.cbrt"
                          aex_pptk_free(((stack->stack_ + stack->new_buf_sym_partial_pos_)->v_.uv0_));
#line 3126 "src/pp/pp_macro_expander.c"
                        }
                        stack->stack_newbuf_pos_has_sym_data_ = 0;
                        
                        break;
                        case AEX_PPME_OBJECT:
                        case AEX_PPME_FUNCTION:
                        stack->newbuf_pos_has_sym_data_ = 1;
                        stack->continue_at_ = 99;
                        {
#line 75 "grammar/pp/pp_macro_expander.cbrt"
                          stack->new_buf_[stack->new_buf_sym_partial_pos_].v_.uv1_.tk_ = NULL; stack->new_buf_[stack->new_buf_sym_partial_pos_].v_.uv1_.m_ = NULL;
#line 3138 "src/pp/pp_macro_expander.c"
                        }
                        C99:;
                        stack->continue_at_ = 100;
                        {
#line 76 "grammar/pp/pp_macro_expander.cbrt"
                          stack->new_buf_[stack->new_buf_sym_partial_pos_].v_.uv1_.tk_ = (stack->stack_[stack->new_buf_sym_partial_pos_].v_.uv1_).tk_; stack->new_buf_[stack->new_buf_sym_partial_pos_].v_.uv1_.m_ = (stack->stack_[stack->new_buf_sym_partial_pos_].v_.uv1_).m_;
#line 3145 "src/pp/pp_macro_expander.c"
                        }
                        C100:;
                        {
#line 77 "grammar/pp/pp_macro_expander.cbrt"
                          aex_pptk_free(((stack->stack_ + stack->new_buf_sym_partial_pos_)->v_.uv1_).tk_); aex_macro_free(((stack->stack_ + stack->new_buf_sym_partial_pos_)->v_.uv1_).m_); /* Reduction of OBJECT drops a reference and might free the macro */
#line 3151 "src/pp/pp_macro_expander.c"
                        }
                        stack->stack_newbuf_pos_has_sym_data_ = 0;
                        
                        break;
                        case AEX_PPME_NON_FUNCTION:
                        case AEX_PPME_WS_OPT:
                        case AEX_PPME_PAR_SPAN:
                        case AEX_PPME_ARG:
                        stack->newbuf_pos_has_sym_data_ = 1;
                        stack->continue_at_ = 101;
                        {
#line 95 "grammar/pp/pp_macro_expander.cbrt"
                          stack->new_buf_[stack->new_buf_sym_partial_pos_].v_.uv2_ = NULL;
#line 3165 "src/pp/pp_macro_expander.c"
                        }
                        C101:;
                        stack->continue_at_ = 102;
                        {
#line 96 "grammar/pp/pp_macro_expander.cbrt"
                          stack->new_buf_[stack->new_buf_sym_partial_pos_].v_.uv2_ = (stack->stack_[stack->new_buf_sym_partial_pos_].v_.uv2_); (stack->stack_[stack->new_buf_sym_partial_pos_].v_.uv2_) = NULL;
#line 3172 "src/pp/pp_macro_expander.c"
                        }
                        C102:;
                        {
#line 97 "grammar/pp/pp_macro_expander.cbrt"
                          aex_pptk_free(((stack->stack_ + stack->new_buf_sym_partial_pos_)->v_.uv2_));
#line 3178 "src/pp/pp_macro_expander.c"
                        }
                        stack->stack_newbuf_pos_has_sym_data_ = 0;
                        
                        break;
                        case AEX_PPME_ARGS:
                        stack->newbuf_pos_has_sym_data_ = 1;
                        stack->continue_at_ = 103;
                        {
#line 101 "grammar/pp/pp_macro_expander.cbrt"
                          stack->new_buf_[stack->new_buf_sym_partial_pos_].v_.uv3_ = NULL;
#line 3189 "src/pp/pp_macro_expander.c"
                        }
                        C103:;
                        stack->continue_at_ = 104;
                        {
#line 102 "grammar/pp/pp_macro_expander.cbrt"
                          stack->new_buf_[stack->new_buf_sym_partial_pos_].v_.uv3_ = (stack->stack_[stack->new_buf_sym_partial_pos_].v_.uv3_); (stack->stack_[stack->new_buf_sym_partial_pos_].v_.uv3_) = NULL;
#line 3196 "src/pp/pp_macro_expander.c"
                        }
                        C104:;
                        {
#line 103 "grammar/pp/pp_macro_expander.cbrt"
                          aex_macro_arg_inst_free(((stack->stack_ + stack->new_buf_sym_partial_pos_)->v_.uv3_));
#line 3202 "src/pp/pp_macro_expander.c"
                        }
                        stack->stack_newbuf_pos_has_sym_data_ = 0;
                        
                        break;
                      }
                    }
                  }
                  else /* not 0 or 1, but >= 2 state derived sym */ {
                    switch (stack->stack_[stack->new_buf_sym_partial_pos_].state_) {
                      case 2: /* IDENT */
                      case 3: /* COMMA */
                      case 4: /* PAR_CLOSE */
                      case 5: /* OTHER */
                      case 6: /* PAR_CLOSE */
                      case 8: /* COMMA */
                      case 10: /* IDENT */
                      case 13: /* WS_TOK */
                      case 14: /* OTHER */
                      case 15: /* PAR_CLOSE */
                      case 16: /* IDENT */
                      case 19: /* COMMA */
                      case 20: /* WS_TOK */
                      case 21: /* OTHER */
                      case 22: /* PAR_CLOSE */
                      case 24: /* PAR_OPEN */
                      case 26: /* PAR_OPEN */
                      case 28: /* PAR_OPEN */
                      case 32: /* PAR_CLOSE */
                      case 34: /* IDENT */
                      case 35: /* PAR_CLOSE */
                      case 38: /* PAR_CLOSE */
                      case 41: /* PAR_CLOSE */
                      case 43: /* DEFINED */
                      case 45: /* PAR_OPEN */
                      case 46: /* IDENT */
                      case 49: /* DEFINED */
                      case 50: /* WS_TOK */
                      case 52: /* DEFINED */
                      case 54: /* PAR_OPEN */
                      case 55: /* WS_TOK */
                      stack->newbuf_pos_has_sym_data_ = 1;
                      stack->continue_at_ = 105;
                      {
#line 68 "grammar/pp/pp_macro_expander.cbrt"
                        stack->new_buf_[stack->new_buf_sym_partial_pos_].v_.uv0_ = NULL;
#line 3248 "src/pp/pp_macro_expander.c"
                      }
                      C105:;
                      stack->continue_at_ = 106;
                      {
#line 69 "grammar/pp/pp_macro_expander.cbrt"
                        stack->new_buf_[stack->new_buf_sym_partial_pos_].v_.uv0_ = (stack->stack_[stack->new_buf_sym_partial_pos_].v_.uv0_); (stack->stack_[stack->new_buf_sym_partial_pos_].v_.uv0_) = NULL;
#line 3255 "src/pp/pp_macro_expander.c"
                      }
                      C106:;
                      {
#line 70 "grammar/pp/pp_macro_expander.cbrt"
                        aex_pptk_free(((stack->stack_ + stack->new_buf_sym_partial_pos_)->v_.uv0_));
#line 3261 "src/pp/pp_macro_expander.c"
                      }
                      stack->stack_newbuf_pos_has_sym_data_ = 0;
                      break;
                      
                      case 11: /* FUNCTION */
                      case 12: /* OBJECT */
                      case 17: /* FUNCTION */
                      case 18: /* OBJECT */
                      case 30: /* FUNCTION */
                      case 31: /* OBJECT */
                      case 37: /* FUNCTION */
                      case 40: /* OBJECT */
                      case 47: /* FUNCTION */
                      case 48: /* OBJECT */
                      stack->newbuf_pos_has_sym_data_ = 1;
                      stack->continue_at_ = 107;
                      {
#line 75 "grammar/pp/pp_macro_expander.cbrt"
                        stack->new_buf_[stack->new_buf_sym_partial_pos_].v_.uv1_.tk_ = NULL; stack->new_buf_[stack->new_buf_sym_partial_pos_].v_.uv1_.m_ = NULL;
#line 3281 "src/pp/pp_macro_expander.c"
                      }
                      C107:;
                      stack->continue_at_ = 108;
                      {
#line 76 "grammar/pp/pp_macro_expander.cbrt"
                        stack->new_buf_[stack->new_buf_sym_partial_pos_].v_.uv1_.tk_ = (stack->stack_[stack->new_buf_sym_partial_pos_].v_.uv1_).tk_; stack->new_buf_[stack->new_buf_sym_partial_pos_].v_.uv1_.m_ = (stack->stack_[stack->new_buf_sym_partial_pos_].v_.uv1_).m_;
#line 3288 "src/pp/pp_macro_expander.c"
                      }
                      C108:;
                      {
#line 77 "grammar/pp/pp_macro_expander.cbrt"
                        aex_pptk_free(((stack->stack_ + stack->new_buf_sym_partial_pos_)->v_.uv1_).tk_); aex_macro_free(((stack->stack_ + stack->new_buf_sym_partial_pos_)->v_.uv1_).m_); /* Reduction of OBJECT drops a reference and might free the macro */
#line 3294 "src/pp/pp_macro_expander.c"
                      }
                      stack->stack_newbuf_pos_has_sym_data_ = 0;
                      break;
                      
                      case 7: /* arg */
                      case 23: /* par-span */
                      case 25: /* par-span */
                      case 27: /* arg */
                      case 29: /* ws-opt */
                      case 33: /* ws-opt */
                      case 36: /* ws-opt */
                      case 39: /* ws-opt */
                      case 42: /* ws-opt */
                      case 44: /* ws-opt */
                      case 51: /* ws-opt */
                      stack->newbuf_pos_has_sym_data_ = 1;
                      stack->continue_at_ = 109;
                      {
#line 95 "grammar/pp/pp_macro_expander.cbrt"
                        stack->new_buf_[stack->new_buf_sym_partial_pos_].v_.uv2_ = NULL;
#line 3315 "src/pp/pp_macro_expander.c"
                      }
                      C109:;
                      stack->continue_at_ = 110;
                      {
#line 96 "grammar/pp/pp_macro_expander.cbrt"
                        stack->new_buf_[stack->new_buf_sym_partial_pos_].v_.uv2_ = (stack->stack_[stack->new_buf_sym_partial_pos_].v_.uv2_); (stack->stack_[stack->new_buf_sym_partial_pos_].v_.uv2_) = NULL;
#line 3322 "src/pp/pp_macro_expander.c"
                      }
                      C110:;
                      {
#line 97 "grammar/pp/pp_macro_expander.cbrt"
                        aex_pptk_free(((stack->stack_ + stack->new_buf_sym_partial_pos_)->v_.uv2_));
#line 3328 "src/pp/pp_macro_expander.c"
                      }
                      stack->stack_newbuf_pos_has_sym_data_ = 0;
                      break;
                      
                      case 9: /* args */
                      stack->newbuf_pos_has_sym_data_ = 1;
                      stack->continue_at_ = 111;
                      {
#line 101 "grammar/pp/pp_macro_expander.cbrt"
                        stack->new_buf_[stack->new_buf_sym_partial_pos_].v_.uv3_ = NULL;
#line 3339 "src/pp/pp_macro_expander.c"
                      }
                      C111:;
                      stack->continue_at_ = 112;
                      {
#line 102 "grammar/pp/pp_macro_expander.cbrt"
                        stack->new_buf_[stack->new_buf_sym_partial_pos_].v_.uv3_ = (stack->stack_[stack->new_buf_sym_partial_pos_].v_.uv3_); (stack->stack_[stack->new_buf_sym_partial_pos_].v_.uv3_) = NULL;
#line 3346 "src/pp/pp_macro_expander.c"
                      }
                      C112:;
                      {
#line 103 "grammar/pp/pp_macro_expander.cbrt"
                        aex_macro_arg_inst_free(((stack->stack_ + stack->new_buf_sym_partial_pos_)->v_.uv3_));
#line 3352 "src/pp/pp_macro_expander.c"
                      }
                      stack->stack_newbuf_pos_has_sym_data_ = 0;
                      break;
                      
                    } /* switch */
                  }
                }
                if (stack->stack_) free(stack->stack_);
                stack->stack_ = stack->new_buf_;
                stack->new_buf_sym_partial_pos_ = 0;
                stack->new_buf_ = NULL;
                stack->num_stack_allocated_ = stack->new_buf_num_allocated_;
                stack->current_err_action_ = stack->action_preservation_;
              }
              stack->stack_[stack->pos_++].state_ = stack->current_err_action_;
              stack->top_of_stack_has_sym_data_ = 0;
              stack->top_of_stack_has_common_data_ = 0;
              stack->error_recovery_ = 0;
              /* Break out of do { .. } while loop, we've recovered */
              break;
            } /* if (err_sym_action) (if the current sym can continue after an error transition) */
          } /* if (stack->current_err_action_) (if the state at position 'n' can accept an error transition) */
        } while (n);
      }
      if (stack->error_recovery_) {
        /* Did not yet recover, discard current sym and get next */
        if (sym == AEX_PPME_INPUT_END) {
          /* EOF means we cannot shift to recover, so return completion */
          stack->pending_reset_ = 1;
          return _AEX_PPME_FINISH;
        }
        stack->continue_at_ = 0;
        {
          if (*pp_input_chain) {                                                                \
            sym = g_aex_pptk_to_ppme_[(*pp_input_chain)->tok_];                                     \
            if ((!keep_defined) && (sym == AEX_PPME_DEFINED)) {                                     \
              sym = AEX_PPME_IDENT;                                                                 \
              }                                                                                   \
            if (sym == AEX_PPME_IDENT) {                                                            \
              struct macro *m = NULL;                                                           \
              m = mt_find(&pp->macro_table_, (*pp_input_chain)->text_, (*pp_input_chain)->text_len_); \
              if (m && !m->nested_invocation_) {                                                \
                if (m->is_function_style_) {                                                    \
                  sym = AEX_PPME_FUNCTION;                                                          \
                  }                                                                               \
                else {                                                                          \
                  sym = AEX_PPME_OBJECT;                                                            \
                  }                                                                               \
                }                                                                                 \
              }                                                                                   \
            }                                                                                     \
          else {                                                                                \
            if (!is_final) return _AEX_PPME_FEED_ME;                                                \
            sym = AEX_PPME_INPUT_END;                                                               \
            }
          
        }
      }
    } /* stack->error_recovery_ */
  } /* for (;;) */
}
/* --------- END OF GENERATED CODE ------------ */
