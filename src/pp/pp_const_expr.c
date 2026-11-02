#line 1 "grammar/pp/pp_const_expr.cbrt"
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

#ifndef ASSERT_H_INCLUDED
#define ASSERT_H_INCLUDED
#include <assert.h>
#endif

#ifndef PP_H_INCLUDED
#define PP_H_INCLUDED
#include "pp.h"
#endif

#ifndef PP_TOKENS_H_INCLUDED
#define PP_TOKENS_H_INCLUDED
#include "pp_tokens.h"
#endif

#line 69 "grammar/pp/pp_const_expr.cbrt"
struct aex_ppce_value {
  int is_unsigned_:1; 
  union { 
    uint64_t u_; 
    int64_t i_;
  } v_;
};
#line 245 "grammar/pp/pp_const_expr.cbrt"
static int aex_ppce_int_const_expr_to_value(struct preprocessor *pp, struct aex_ppce_value *v, struct pptk *tk) {
  switch (tk->v_type_) {
    case PPVT_SHORT:
    case PPVT_INT:
    case PPVT_LONG_INT:
    case PPVT_LONG_LONG_INT:
      v->is_unsigned_ = 0;
      v->v_.i_ = tk->v_.i64_;
      break;
    case PPVT_UNSIGNED_SHORT:
    case PPVT_UNSIGNED_INT:
    case PPVT_UNSIGNED_LONG_INT:
    case PPVT_UNSIGNED_LONG_LONG_INT:
      v->is_unsigned_ = 1;
      v->v_.u_ = tk->v_.u64_;
      break;
    default:
      dx_fatal_loc(pp->dx_, &tk->situs_, "Error during preprocessor constant expression evaluation: unable to determine integer literal type\n");
      return -1;
  }
  return 0;
}
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
struct aex_ppce_sym_data {
  #ifdef __cplusplus
  // clear destructor in case C++ symbol types have non-trivial destructors
  // (we invoke their destructors explicitly)
  ~aex_ppce_sym_data() = delete;
  #endif
  int state_;
  union {
    struct pptk * uv0_;
    struct aex_ppce_value uv1_;
  } v_;
};
static const int aex_ppce_minimum_sym = 3;
static const size_t aex_ppce_num_columns = 51;
static const int aex_ppce_parse_table[] = {
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 71, 72,  0,  0,  0,68,75,78,  0,69,70, 0, 0,76,77, 0, 0, 0,  0, 1, 7,11,14,17,20,23,28,37,42,47,54,55,60,73,74, 0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  -44,-44,-44,-44,-44,-44,-44,-44,-44,-44,-44,-44,-44,-44,-44,-44,-44,-44,-44,-44, 0, 0, 0,-44, 0, 0, 0, 0, 0, 0, 0, 0, 0,-44, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 0, 0, 0,  2, 0, 0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, -3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 0, 0, 0, -3, 0, 0, 0, 0, 0, 0, 0, 0, 0, -3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 71, 72,  0,  0,  0,68,75,78,  0,69,70, 0, 0,76,77, 0, 0, 0,  0, 0, 4,11,14,17,20,23,28,37,42,47,54,55,60,73,74, 0,
    0,  5,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, -2,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 0, 0, 0, -2, 0, 0, 0, 0, 0, 0, 0, 0, 0, -2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 71, 72,  0,  0,  0,68,75,78,  0,69,70, 0, 0,76,77, 0, 0, 0,  0, 6, 7,11,14,17,20,23,28,37,42,47,54,55,60,73,74, 0,
   -5, -5, -5, 13,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 0, 0, 0, -5, 0, 0, 0, 0, 0, 0, 0, 0, 0, -5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 71, 72,  0,  0,  0,68,75,78,  0,69,70, 0, 0,76,77, 0, 0, 0,  0, 0, 0, 0, 9,17,20,23,28,37,42,47,54,55,60,73,74, 0,
    8, -4, 10,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 0, 0, 0, -4, 0, 0, 0, 0, 0, 0, 0, 0, 0, -4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   -7, -7, -7, -7, 16,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 0, 0, 0, -7, 0, 0, 0, 0, 0, 0, 0, 0, 0, -7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 71, 72,  0,  0,  0,68,75,78,  0,69,70, 0, 0,76,77, 0, 0, 0,  0, 0, 0, 0, 0,12,20,23,28,37,42,47,54,55,60,73,74, 0,
   -6, -6, -6, 13,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 0, 0, 0, -6, 0, 0, 0, 0, 0, 0, 0, 0, 0, -6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   -9, -9, -9, -9, -9, 19,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 0, 0, 0, -9, 0, 0, 0, 0, 0, 0, 0, 0, 0, -9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 71, 72,  0,  0,  0,68,75,78,  0,69,70, 0, 0,76,77, 0, 0, 0,  0, 0, 0, 0, 0, 0,15,23,28,37,42,47,54,55,60,73,74, 0,
   -8, -8, -8, -8, 16,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 0, 0, 0, -8, 0, 0, 0, 0, 0, 0, 0, 0, 0, -8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  -11,-11,-11,-11,-11,-11, 22,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 0, 0, 0,-11, 0, 0, 0, 0, 0, 0, 0, 0, 0,-11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 71, 72,  0,  0,  0,68,75,78,  0,69,70, 0, 0,76,77, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0,18,28,37,42,47,54,55,60,73,74, 0,
  -10,-10,-10,-10,-10, 19,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 0, 0, 0,-10, 0, 0, 0, 0, 0, 0, 0, 0, 0,-10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  -13,-13,-13,-13,-13,-13,-13, 25, 27,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 0, 0, 0,-13, 0, 0, 0, 0, 0, 0, 0, 0, 0,-13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 71, 72,  0,  0,  0,68,75,78,  0,69,70, 0, 0,76,77, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0,21,37,42,47,54,55,60,73,74, 0,
  -12,-12,-12,-12,-12,-12, 22,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 0, 0, 0,-12, 0, 0, 0, 0, 0, 0, 0, 0, 0,-12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  -15,-15,-15,-15,-15,-15,-15,-15,-15, 30, 32, 34, 36,  0,  0,  0,  0,  0,  0,  0, 0, 0, 0,-15, 0, 0, 0, 0, 0, 0, 0, 0, 0,-15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 71, 72,  0,  0,  0,68,75,78,  0,69,70, 0, 0,76,77, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0,24,42,47,54,55,60,73,74, 0,
  -16,-16,-16,-16,-16,-16,-16,-16,-16, 30, 32, 34, 36,  0,  0,  0,  0,  0,  0,  0, 0, 0, 0,-16, 0, 0, 0, 0, 0, 0, 0, 0, 0,-16, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 71, 72,  0,  0,  0,68,75,78,  0,69,70, 0, 0,76,77, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0,26,42,47,54,55,60,73,74, 0,
  -14,-14,-14,-14,-14,-14,-14, 25, 27,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 0, 0, 0,-14, 0, 0, 0, 0, 0, 0, 0, 0, 0,-14, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  -18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18, 39, 41,  0,  0,  0,  0,  0, 0, 0, 0,-18, 0, 0, 0, 0, 0, 0, 0, 0, 0,-18, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 71, 72,  0,  0,  0,68,75,78,  0,69,70, 0, 0,76,77, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,29,47,54,55,60,73,74, 0,
  -19,-19,-19,-19,-19,-19,-19,-19,-19,-19,-19,-19,-19, 39, 41,  0,  0,  0,  0,  0, 0, 0, 0,-19, 0, 0, 0, 0, 0, 0, 0, 0, 0,-19, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 71, 72,  0,  0,  0,68,75,78,  0,69,70, 0, 0,76,77, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,31,47,54,55,60,73,74, 0,
  -20,-20,-20,-20,-20,-20,-20,-20,-20,-20,-20,-20,-20, 39, 41,  0,  0,  0,  0,  0, 0, 0, 0,-20, 0, 0, 0, 0, 0, 0, 0, 0, 0,-20, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 71, 72,  0,  0,  0,68,75,78,  0,69,70, 0, 0,76,77, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,33,47,54,55,60,73,74, 0,
  -21,-21,-21,-21,-21,-21,-21,-21,-21,-21,-21,-21,-21, 39, 41,  0,  0,  0,  0,  0, 0, 0, 0,-21, 0, 0, 0, 0, 0, 0, 0, 0, 0,-21, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 71, 72,  0,  0,  0,68,75,78,  0,69,70, 0, 0,76,77, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,35,47,54,55,60,73,74, 0,
  -17,-17,-17,-17,-17,-17,-17,-17,-17, 30, 32, 34, 36,  0,  0,  0,  0,  0,  0,  0, 0, 0, 0,-17, 0, 0, 0, 0, 0, 0, 0, 0, 0,-17, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  -23,-23,-23,-23,-23,-23,-23,-23,-23,-23,-23,-23,-23,-23,-23, 44, 46,  0,  0,  0, 0, 0, 0,-23, 0, 0, 0, 0, 0, 0, 0, 0, 0,-23, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 71, 72,  0,  0,  0,68,75,78,  0,69,70, 0, 0,76,77, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,38,54,55,60,73,74, 0,
  -24,-24,-24,-24,-24,-24,-24,-24,-24,-24,-24,-24,-24,-24,-24, 44, 46,  0,  0,  0, 0, 0, 0,-24, 0, 0, 0, 0, 0, 0, 0, 0, 0,-24, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 71, 72,  0,  0,  0,68,75,78,  0,69,70, 0, 0,76,77, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,40,54,55,60,73,74, 0,
  -22,-22,-22,-22,-22,-22,-22,-22,-22,-22,-22,-22,-22, 39, 41,  0,  0,  0,  0,  0, 0, 0, 0,-22, 0, 0, 0, 0, 0, 0, 0, 0, 0,-22, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  -26,-26,-26,-26,-26,-26,-26,-26,-26,-26,-26,-26,-26,-26,-26,-26,-26, 49, 51, 53, 0, 0, 0,-26, 0, 0, 0, 0, 0, 0, 0, 0, 0,-26, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 71, 72,  0,  0,  0,68,75,78,  0,69,70, 0, 0,76,77, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,43,55,60,73,74, 0,
  -27,-27,-27,-27,-27,-27,-27,-27,-27,-27,-27,-27,-27,-27,-27,-27,-27, 49, 51, 53, 0, 0, 0,-27, 0, 0, 0, 0, 0, 0, 0, 0, 0,-27, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 71, 72,  0,  0,  0,68,75,78,  0,69,70, 0, 0,76,77, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,45,55,60,73,74, 0,
  -25,-25,-25,-25,-25,-25,-25,-25,-25,-25,-25,-25,-25,-25,-25, 44, 46,  0,  0,  0, 0, 0, 0,-25, 0, 0, 0, 0, 0, 0, 0, 0, 0,-25, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  -29,-29,-29,-29,-29,-29,-29,-29,-29,-29,-29,-29,-29,-29,-29,-29,-29,-29,-29,-29, 0, 0, 0,-29, 0, 0, 0, 0, 0, 0, 0, 0, 0,-29, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 71, 72,  0,  0,  0,68,75,78,  0,69,70, 0, 0,76,77, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,48,60,73,74, 0,
  -30,-30,-30,-30,-30,-30,-30,-30,-30,-30,-30,-30,-30,-30,-30,-30,-30,-30,-30,-30, 0, 0, 0,-30, 0, 0, 0, 0, 0, 0, 0, 0, 0,-30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 71, 72,  0,  0,  0,68,75,78,  0,69,70, 0, 0,76,77, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,50,60,73,74, 0,
  -31,-31,-31,-31,-31,-31,-31,-31,-31,-31,-31,-31,-31,-31,-31,-31,-31,-31,-31,-31, 0, 0, 0,-31, 0, 0, 0, 0, 0, 0, 0, 0, 0,-31, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 71, 72,  0,  0,  0,68,75,78,  0,69,70, 0, 0,76,77, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,52,60,73,74, 0,
  -28,-28,-28,-28,-28,-28,-28,-28,-28,-28,-28,-28,-28,-28,-28,-28,-28, 49, 51, 53, 0, 0, 0,-28, 0, 0, 0, 0, 0, 0, 0, 0, 0,-28, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  -32,-32,-32,-32,-32,-32,-32,-32,-32,-32,-32,-32,-32,-32,-32,-32,-32,-32,-32,-32, 0, 0, 0,-32, 0, 0, 0, 0, 0, 0, 0, 0, 0,-32, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  -41,-41,-41,-41,-41,-41,-41,-41,-41,-41,-41,-41,-41,-41,-41,-41,-41,-41,-41,-41, 0, 0, 0,-41, 0, 0, 0, 0, 0, 0, 0, 0, 0,-41, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  -40,-40,-40,-40,-40,-40,-40,-40,-40,-40,-40,-40,-40,-40,-40,-40,-40,-40,-40,-40, 0, 0, 0,-40, 0, 0, 0, 0, 0, 0, 0, 0, 0,-40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  -39,-39,-39,-39,-39,-39,-39,-39,-39,-39,-39,-39,-39,-39,-39,-39,-39,-39,-39,-39, 0, 0, 0,-39, 0, 0, 0, 0, 0, 0, 0, 0, 0,-39, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  -38,-38,-38,-38,-38,-38,-38,-38,-38,-38,-38,-38,-38,-38,-38,-38,-38,-38,-38,-38, 0, 0, 0,-38, 0, 0, 0, 0, 0, 0, 0, 0, 0,-38, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  -33,-33,-33,-33,-33,-33,-33,-33,-33,-33,-33,-33,-33,-33,-33,-33,-33,-33,-33,-33, 0, 0, 0,-33, 0, 0, 0, 0, 0, 0, 0, 0, 0,-33, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  -34,-34,-34,-34,-34,-34,-34,-34,-34,-34,-34,-34,-34,-34,-34,-34,-34,-34,-34,-34, 0, 0, 0,-34, 0, 0, 0, 0, 0, 0, 0, 0, 0,-34, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 0, 0, 0, 61, 0, 0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  -35,-35,-35,-35,-35,-35,-35,-35,-35,-35,-35,-35,-35,-35,-35,-35,-35,-35,-35,-35, 0, 0, 0,-35, 0, 0, 0, 0, 0, 0, 0, 0, 0,-35, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 0, 0, 0, 63, 0, 0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,64, 0,62,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  -36,-36,-36,-36,-36,-36,-36,-36,-36,-36,-36,-36,-36,-36,-36,-36,-36,-36,-36,-36, 0, 0, 0,-36, 0, 0, 0, 0, 0, 0, 0, 0, 0,-36, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  -37,-37,-37,-37,-37,-37,-37,-37,-37,-37,-37,-37,-37,-37,-37,-37,-37,-37,-37,-37, 0, 0, 0,-37, 0, 0, 0, 0, 0, 0, 0, 0, 0,-37, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,67,65,66,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 71, 72,  0,  0,  0,68,75,78,  0,69,70, 0, 0,76,77, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,59,60,73,74, 0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 71, 72,  0,  0,  0,68,75,78,  0,69,70, 0, 0,76,77, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,58,60,73,74, 0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 71, 72,  0,  0,  0,68,75,78,  0,69,70, 0, 0,76,77, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,57,60,73,74, 0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 71, 72,  0,  0,  0,68,75,78,  0,69,70, 0, 0,76,77, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,56,60,73,74, 0,
  -42,-42,-42,-42,-42,-42,-42,-42,-42,-42,-42,-42,-42,-42,-42,-42,-42,-42,-42,-42, 0, 0, 0,-42, 0, 0, 0, 0, 0, 0, 0, 0, 0,-42, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  -43,-43,-43,-43,-43,-43,-43,-43,-43,-43,-43,-43,-43,-43,-43,-43,-43,-43,-43,-43, 0, 0, 0,-43, 0, 0, 0, 0, 0, 0, 0, 0, 0,-43, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 71, 72,  0,  0,  0,68,75,78,  0,69,70, 0, 0,76,77, 0, 0, 0,  0, 3, 7,11,14,17,20,23,28,37,42,47,54,55,60,73,74, 0,
  -45,-45,-45,-45,-45,-45,-45,-45,-45,-45,-45,-45,-45,-45,-45,-45,-45,-45,-45,-45, 0, 0, 0,-45, 0, 0, 0, 0, 0, 0, 0, 0, 0,-45, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  -46,-46,-46,-46,-46,-46,-46,-46,-46,-46,-46,-46,-46,-46,-46,-46,-46,-46,-46,-46, 0, 0, 0,-46, 0, 0, 0, 0, 0, 0, 0, 0, 0,-46, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  -47,-47,-47,-47,-47,-47,-47,-47,-47,-47,-47,-47,-47,-47,-47,-47,-47,-47,-47,-47, 0, 0, 0,-47, 0, 0, 0, 0, 0, 0, 0, 0, 0,-47, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};
static const size_t aex_ppce_production_lengths[] = {
  1,
  1,
  5,
  1,
  3,
  1,
  3,
  1,
  3,
  1,
  3,
  1,
  3,
  1,
  3,
  3,
  1,
  3,
  3,
  3,
  3,
  1,
  3,
  3,
  1,
  3,
  3,
  1,
  3,
  3,
  3,
  1,
  1,
  4,
  4,
  2,
  2,
  2,
  2,
  2,
  2,
  1,
  1,
  3,
  1,
  1,
  1
};
static const int aex_ppce_production_syms[] = {
  53,
  37,
  38,
  38,
  39,
  39,
  40,
  40,
  41,
  41,
  42,
  42,
  43,
  43,
  44,
  44,
  44,
  45,
  45,
  45,
  45,
  45,
  46,
  46,
  46,
  47,
  47,
  47,
  48,
  48,
  48,
  48,
  49,
  50,
  50,
  50,
  50,
  50,
  50,
  50,
  50,
  50,
  51,
  52,
  52,
  52,
  52
};

#ifndef CARB_AEX_PPCE_SRCPPPP_CONST_EXPR_H_INCLUDED
struct aex_ppce_stack {
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
  struct aex_ppce_sym_data *stack_;
  struct aex_ppce_sym_data *sym_data_;
  struct aex_ppce_sym_data *new_buf_;
  size_t new_buf_num_allocated_;
  size_t new_buf_sym_partial_pos_;
  size_t current_production_length_;
  int current_production_nonterminal_;
  size_t sym_idx_;
};
#define _AEX_PPCE_FINISH 0
#define _AEX_PPCE_MATCH 1
#define _AEX_PPCE_OVERFLOW 2
#define _AEX_PPCE_NO_MEMORY 3
#define _AEX_PPCE_FEED_ME 4
#define _AEX_PPCE_END_OF_INPUT 5
#define _AEX_PPCE_SYNTAX_ERROR 6
#define _AEX_PPCE_LEXICAL_ERROR 7
#define _AEX_PPCE_INTERNAL_ERROR 8

#define AEX_PPCE_QUESTION_MARK 3
#define AEX_PPCE_COLON 4
#define AEX_PPCE_BAR_BAR 5
#define AEX_PPCE_AMPERSAND_AMPERSAND 6
#define AEX_PPCE_BAR 7
#define AEX_PPCE_CARET 8
#define AEX_PPCE_AMPERSAND 9
#define AEX_PPCE_BANG_EQUALS 10
#define AEX_PPCE_EQUALS_EQUALS 11
#define AEX_PPCE_GT_EQUALS 12
#define AEX_PPCE_LT_EQUALS 13
#define AEX_PPCE_GT 14
#define AEX_PPCE_LT 15
#define AEX_PPCE_GT_GT 16
#define AEX_PPCE_LT_LT 17
#define AEX_PPCE_MINUS 18
#define AEX_PPCE_PLUS 19
#define AEX_PPCE_PERCENT 20
#define AEX_PPCE_SLASH 21
#define AEX_PPCE_ASTERISK 22
#define AEX_PPCE_DEFINED 23
#define AEX_PPCE_PAR_OPEN 24
#define AEX_PPCE_IDENT 25
#define AEX_PPCE_PAR_CLOSE 26
#define AEX_PPCE_BANG 27
#define AEX_PPCE_TILDE 28
#define AEX_PPCE_MINUS_MINUS 29
#define AEX_PPCE_PLUS_PLUS 30
#define AEX_PPCE_CHAR_LIT 31
#define AEX_PPCE_INTEGER_LIT 32
#define AEX_PPCE_WS 33
#define AEX_PPCE_OTHER 34
#define AEX_PPCE_ERROR 35
#define AEX_PPCE_INPUT_END 36

#define AEX_PPCE_CONSTANT_EXP 37
#define AEX_PPCE_COND_EXP 38
#define AEX_PPCE_LOG_OR_EXP 39
#define AEX_PPCE_LOG_AND_EXP 40
#define AEX_PPCE_OR_EXP 41
#define AEX_PPCE_XOR_EXP 42
#define AEX_PPCE_AND_EXP 43
#define AEX_PPCE_EQU_EXP 44
#define AEX_PPCE_REL_EXP 45
#define AEX_PPCE_SHIFT_EXP 46
#define AEX_PPCE_ADD_EXP 47
#define AEX_PPCE_MUL_EXP 48
#define AEX_PPCE_CAST_EXP 49
#define AEX_PPCE_UNARY_EXP 50
#define AEX_PPCE_POSTFIX_EXP 51
#define AEX_PPCE_PRIMARY_EXP 52


#endif /* CARB_AEX_PPCE_SRCPPPP_CONST_EXPR_H_INCLUDED */

void aex_ppce_stack_init(struct aex_ppce_stack *stack) {
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

void aex_ppce_stack_cleanup(struct aex_ppce_stack *stack) {
  if (stack->stack_) free(stack->stack_);
}

int aex_ppce_stack_reset(struct aex_ppce_stack *stack) {
  stack->pending_reset_ = 0;
  stack->discard_remaining_actions_ = 0;
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
        return _AEX_PPCE_OVERFLOW;
      }
    }
    else {
      new_num_allocated = 16;
    }
    
    if (new_num_allocated > (SIZE_MAX / sizeof(struct aex_ppce_sym_data))) {
      /* Overflow in allocation */
      stack->continue_at_ = 0;
      return _AEX_PPCE_OVERFLOW;
    }
    
    void *p = realloc(stack->stack_, new_num_allocated * sizeof(struct aex_ppce_sym_data));
    if (!p) {
      /* Out of memory */
      stack->continue_at_ = 0;
      return _AEX_PPCE_NO_MEMORY;
    }
    stack->stack_ = (struct aex_ppce_sym_data *)p;
    stack->num_stack_allocated_ = new_num_allocated;
  }
  stack->stack_[0].state_ = 0;
  stack->stack_[1].state_ = 0;
  stack->pos_ = 2;
  return 0;
}

int aex_ppce_stack_can_recover(struct aex_ppce_stack *stack) {
  return !!stack->error_recovery_;
}

int aex_ppce_stack_accepts(struct aex_ppce_stack *stack, int sym) {
  if (!stack->pos_) return 0;
  return 0 != aex_ppce_parse_table[aex_ppce_num_columns * stack->stack_[stack->pos_ - 1].state_ + (sym - aex_ppce_minimum_sym)];}

int aex_ppce_parse(struct aex_ppce_stack *stack, int sym, struct preprocessor *pp, struct pptk **pp_current_tk, struct pptk *input_chain, int is_final, int64_t *presult, int *pis_unsigned) {
  if (stack->pending_reset_) {
    int r;
    r = aex_ppce_stack_reset(stack);
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
  } /* continuation switch */
if (stack->mute_error_turns_) stack->mute_error_turns_--;
  for (;;) {
    if (!stack->error_recovery_) {
      int action;
      action = aex_ppce_parse_table[aex_ppce_num_columns * stack->stack_[stack->pos_ - 1].state_ + (sym - aex_ppce_minimum_sym)];
      if (action > 0) {
        if (stack->num_stack_allocated_ == stack->pos_) {
          stack->action_preservation_ = action;
          size_t new_num_allocated;
          if (stack->num_stack_allocated_) {
            new_num_allocated = stack->num_stack_allocated_ * 2;
            if (new_num_allocated <= stack->num_stack_allocated_) {
              /* Overflow in allocation */
              return _AEX_PPCE_OVERFLOW;
            }
          }
          else {
            new_num_allocated = 16;
          }
          
          if (new_num_allocated > (SIZE_MAX / sizeof(struct aex_ppce_sym_data))) {
            /* Overflow in allocation */
            return _AEX_PPCE_OVERFLOW;
          }
          
          stack->new_buf_ = (struct aex_ppce_sym_data *)malloc(new_num_allocated * sizeof(struct aex_ppce_sym_data));
          if (!stack->new_buf_) {
            /* Out of memory */
            return _AEX_PPCE_NO_MEMORY;
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
                  case AEX_PPCE_QUESTION_MARK:
                  case AEX_PPCE_COLON:
                  case AEX_PPCE_BAR_BAR:
                  case AEX_PPCE_AMPERSAND_AMPERSAND:
                  case AEX_PPCE_BAR:
                  case AEX_PPCE_CARET:
                  case AEX_PPCE_AMPERSAND:
                  case AEX_PPCE_BANG_EQUALS:
                  case AEX_PPCE_EQUALS_EQUALS:
                  case AEX_PPCE_GT_EQUALS:
                  case AEX_PPCE_LT_EQUALS:
                  case AEX_PPCE_GT:
                  case AEX_PPCE_LT:
                  case AEX_PPCE_GT_GT:
                  case AEX_PPCE_LT_LT:
                  case AEX_PPCE_MINUS:
                  case AEX_PPCE_PLUS:
                  case AEX_PPCE_PERCENT:
                  case AEX_PPCE_SLASH:
                  case AEX_PPCE_ASTERISK:
                  case AEX_PPCE_DEFINED:
                  case AEX_PPCE_PAR_OPEN:
                  case AEX_PPCE_IDENT:
                  case AEX_PPCE_PAR_CLOSE:
                  case AEX_PPCE_BANG:
                  case AEX_PPCE_TILDE:
                  case AEX_PPCE_MINUS_MINUS:
                  case AEX_PPCE_PLUS_PLUS:
                  case AEX_PPCE_CHAR_LIT:
                  case AEX_PPCE_INTEGER_LIT:
                  case AEX_PPCE_WS:
                  case AEX_PPCE_OTHER:
                  stack->newbuf_pos_has_sym_data_ = 1;
                  stack->continue_at_ = 1;
                  {
#line 65 "grammar/pp/pp_const_expr.cbrt"
                    stack->new_buf_[stack->new_buf_sym_partial_pos_].v_.uv0_ = NULL;
#line 612 "src/pp/pp_const_expr.c"
                  }
                  C1:;
                  memcpy(&stack->new_buf_[stack->new_buf_sym_partial_pos_].v_, &stack->stack_[stack->new_buf_sym_partial_pos_].v_, sizeof(stack->stack_->v_));
                  stack->stack_newbuf_pos_has_sym_data_ = 0;
                  
                  break;
                  case AEX_PPCE_PRIMARY_EXP:
                  case AEX_PPCE_CONSTANT_EXP:
                  case AEX_PPCE_COND_EXP:
                  case AEX_PPCE_LOG_OR_EXP:
                  case AEX_PPCE_LOG_AND_EXP:
                  case AEX_PPCE_OR_EXP:
                  case AEX_PPCE_XOR_EXP:
                  case AEX_PPCE_AND_EXP:
                  case AEX_PPCE_EQU_EXP:
                  case AEX_PPCE_REL_EXP:
                  case AEX_PPCE_SHIFT_EXP:
                  case AEX_PPCE_ADD_EXP:
                  case AEX_PPCE_MUL_EXP:
                  case AEX_PPCE_CAST_EXP:
                  case AEX_PPCE_UNARY_EXP:
                  case AEX_PPCE_POSTFIX_EXP:
                  stack->newbuf_pos_has_sym_data_ = 1;
                  memcpy(&stack->new_buf_[stack->new_buf_sym_partial_pos_].v_, &stack->stack_[stack->new_buf_sym_partial_pos_].v_, sizeof(stack->stack_->v_));
                  stack->stack_newbuf_pos_has_sym_data_ = 0;
                  
                  break;
                }
              }
            }
            else /* not 0 or 1, but >= 2 state derived sym */ {
              switch (stack->stack_[stack->new_buf_sym_partial_pos_].state_) {
                case 2: /* PAR_CLOSE */
                case 5: /* COLON */
                case 8: /* QUESTION_MARK */
                case 10: /* BAR_BAR */
                case 13: /* AMPERSAND_AMPERSAND */
                case 16: /* BAR */
                case 19: /* CARET */
                case 22: /* AMPERSAND */
                case 25: /* BANG_EQUALS */
                case 27: /* EQUALS_EQUALS */
                case 30: /* GT_EQUALS */
                case 32: /* LT_EQUALS */
                case 34: /* GT */
                case 36: /* LT */
                case 39: /* GT_GT */
                case 41: /* LT_LT */
                case 44: /* MINUS */
                case 46: /* PLUS */
                case 49: /* PERCENT */
                case 51: /* SLASH */
                case 53: /* ASTERISK */
                case 61: /* PAR_CLOSE */
                case 62: /* IDENT */
                case 63: /* PAR_CLOSE */
                case 64: /* DEFINED */
                case 65: /* PAR_OPEN */
                case 66: /* IDENT */
                case 67: /* DEFINED */
                case 68: /* DEFINED */
                case 69: /* BANG */
                case 70: /* TILDE */
                case 71: /* MINUS */
                case 72: /* PLUS */
                case 75: /* PAR_OPEN */
                case 76: /* CHAR_LIT */
                case 77: /* INTEGER_LIT */
                case 78: /* IDENT */
                stack->newbuf_pos_has_sym_data_ = 1;
                stack->continue_at_ = 2;
                {
#line 65 "grammar/pp/pp_const_expr.cbrt"
                  stack->new_buf_[stack->new_buf_sym_partial_pos_].v_.uv0_ = NULL;
#line 687 "src/pp/pp_const_expr.c"
                }
                C2:;
                memcpy(&stack->new_buf_[stack->new_buf_sym_partial_pos_].v_, &stack->stack_[stack->new_buf_sym_partial_pos_].v_, sizeof(stack->stack_->v_));
                stack->stack_newbuf_pos_has_sym_data_ = 0;
                break;
                
                case 1: /* constant-exp */
                case 3: /* constant-exp */
                case 4: /* cond-exp */
                case 6: /* constant-exp */
                case 7: /* cond-exp */
                case 9: /* log-and-exp */
                case 11: /* log-or-exp */
                case 12: /* or-exp */
                case 14: /* log-and-exp */
                case 15: /* xor-exp */
                case 17: /* or-exp */
                case 18: /* and-exp */
                case 20: /* xor-exp */
                case 21: /* equ-exp */
                case 23: /* and-exp */
                case 24: /* rel-exp */
                case 26: /* rel-exp */
                case 28: /* equ-exp */
                case 29: /* shift-exp */
                case 31: /* shift-exp */
                case 33: /* shift-exp */
                case 35: /* shift-exp */
                case 37: /* rel-exp */
                case 38: /* add-exp */
                case 40: /* add-exp */
                case 42: /* shift-exp */
                case 43: /* mul-exp */
                case 45: /* mul-exp */
                case 47: /* add-exp */
                case 48: /* cast-exp */
                case 50: /* cast-exp */
                case 52: /* cast-exp */
                case 54: /* mul-exp */
                case 55: /* cast-exp */
                case 56: /* cast-exp */
                case 57: /* cast-exp */
                case 58: /* cast-exp */
                case 59: /* cast-exp */
                case 60: /* unary-exp */
                case 73: /* postfix-exp */
                case 74: /* primary-exp */
                memcpy(&stack->new_buf_[stack->new_buf_sym_partial_pos_].v_, &stack->stack_[stack->new_buf_sym_partial_pos_].v_, sizeof(stack->stack_->v_));
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
          case AEX_PPCE_QUESTION_MARK:
          case AEX_PPCE_COLON:
          case AEX_PPCE_BAR_BAR:
          case AEX_PPCE_AMPERSAND_AMPERSAND:
          case AEX_PPCE_BAR:
          case AEX_PPCE_CARET:
          case AEX_PPCE_AMPERSAND:
          case AEX_PPCE_BANG_EQUALS:
          case AEX_PPCE_EQUALS_EQUALS:
          case AEX_PPCE_GT_EQUALS:
          case AEX_PPCE_LT_EQUALS:
          case AEX_PPCE_GT:
          case AEX_PPCE_LT:
          case AEX_PPCE_GT_GT:
          case AEX_PPCE_LT_LT:
          case AEX_PPCE_MINUS:
          case AEX_PPCE_PLUS:
          case AEX_PPCE_PERCENT:
          case AEX_PPCE_SLASH:
          case AEX_PPCE_ASTERISK:
          case AEX_PPCE_DEFINED:
          case AEX_PPCE_PAR_OPEN:
          case AEX_PPCE_IDENT:
          case AEX_PPCE_PAR_CLOSE:
          case AEX_PPCE_BANG:
          case AEX_PPCE_TILDE:
          case AEX_PPCE_MINUS_MINUS:
          case AEX_PPCE_PLUS_PLUS:
          case AEX_PPCE_CHAR_LIT:
          case AEX_PPCE_INTEGER_LIT:
          case AEX_PPCE_WS:
          case AEX_PPCE_OTHER:
          stack->top_of_stack_has_sym_data_ = 1;
          stack->continue_at_ = 3;
          {
#line 65 "grammar/pp/pp_const_expr.cbrt"
            (stack->sym_data_->v_.uv0_) = NULL;
#line 792 "src/pp/pp_const_expr.c"
          }
          C3:;
          stack->continue_at_ = 4;
          {
#line 66 "grammar/pp/pp_const_expr.cbrt"
            (stack->sym_data_->v_.uv0_) = *pp_current_tk;
#line 799 "src/pp/pp_const_expr.c"
          }
          C4:;
          break;
        } /* switch */
        stack->continue_at_ = 0;
        {
          do {                                               \
            (*pp_current_tk) = (*pp_current_tk)->next_;      \
            if ((*pp_current_tk) != input_chain) {           \
              sym = g_aex_pptk_to_ppce_[(*pp_current_tk)->tok_]; \
              }                                                \
            else {                                           \
              if (is_final) {                                \
                sym = AEX_PPCE_INPUT_END;                        \
                }                                              \
              else {                                         \
                return _AEX_PPCE_FEED_ME;                        \
                }                                              \
              }                                                \
            } while (sym == AEX_PPCE_WS);
          
        }
      } /* action > 0 */
      else if (action < 0) {
        int production;
        production = -action - 1;
        stack->discard_remaining_actions_ = 0;
        stack->current_production_length_ = aex_ppce_production_lengths[production];
        stack->current_production_nonterminal_ = aex_ppce_production_syms[production];
        if (0 == production) {
          stack->pending_reset_ = 1;
          /* Synth S we're done */
          return _AEX_PPCE_FINISH;
        }
        
        memset(&stack->stack_[1], 0, sizeof(struct aex_ppce_sym_data));
        { /* scope guard */
          stack->sym_data_ = stack->stack_ + stack->pos_ - stack->current_production_length_;
          switch (production) {
            /* constant-exp: cond-exp */
            case 1: {
              stack->slot_1_has_sym_data_ = 1;
              stack->slot_1_sym_ = AEX_PPCE_CONSTANT_EXP;
              stack->continue_at_ = 5;
              {
#line 82 "grammar/pp/pp_const_expr.cbrt"
                { 
  (stack->stack_[1].v_.uv1_) = (stack->sym_data_[0].v_.uv1_);
  *pis_unsigned = !!(stack->sym_data_[0].v_.uv1_).is_unsigned_;
  *presult = (stack->sym_data_[0].v_.uv1_).v_.i_;
}
#line 851 "src/pp/pp_const_expr.c"
              }
              C5:;
            }
            break;
            /* cond-exp: log-or-exp QUESTION_MARK constant-exp COLON cond-exp */
            case 2: {
              stack->slot_1_has_sym_data_ = 1;
              stack->slot_1_sym_ = AEX_PPCE_COND_EXP;
              stack->continue_at_ = 6;
              {
#line 88 "grammar/pp/pp_const_expr.cbrt"
                {
  /* The signed'ness depends on the expression branch selected, that's curious, but it's the way MSVC seems to be doing, so we'll copy its behavior.. */
  if ((stack->sym_data_[0].v_.uv1_).v_.u_) {
    (stack->stack_[1].v_.uv1_) = (stack->sym_data_[2].v_.uv1_);
  }
  else {
    (stack->stack_[1].v_.uv1_) = (stack->sym_data_[4].v_.uv1_);
  }
}
#line 872 "src/pp/pp_const_expr.c"
              }
              C6:;
            }
            break;
            /* cond-exp: log-or-exp */
            case 3: {
              stack->slot_1_has_sym_data_ = 1;
              stack->slot_1_sym_ = AEX_PPCE_COND_EXP;
              stack->continue_at_ = 7;
              {
#line 97 "grammar/pp/pp_const_expr.cbrt"
                { (stack->stack_[1].v_.uv1_) = (stack->sym_data_[0].v_.uv1_); }
#line 885 "src/pp/pp_const_expr.c"
              }
              C7:;
            }
            break;
            /* log-or-exp: log-or-exp BAR_BAR log-and-exp */
            case 4: {
              stack->slot_1_has_sym_data_ = 1;
              stack->slot_1_sym_ = AEX_PPCE_LOG_OR_EXP;
              stack->continue_at_ = 8;
              {
#line 99 "grammar/pp/pp_const_expr.cbrt"
                { (stack->stack_[1].v_.uv1_).is_unsigned_ = 0; (stack->stack_[1].v_.uv1_).v_.u_ = ((stack->sym_data_[0].v_.uv1_).v_.u_ || (stack->sym_data_[2].v_.uv1_).v_.u_);}
#line 898 "src/pp/pp_const_expr.c"
              }
              C8:;
            }
            break;
            /* log-or-exp: log-and-exp */
            case 5: {
              stack->slot_1_has_sym_data_ = 1;
              stack->slot_1_sym_ = AEX_PPCE_LOG_OR_EXP;
              stack->continue_at_ = 9;
              {
#line 100 "grammar/pp/pp_const_expr.cbrt"
                { (stack->stack_[1].v_.uv1_) = (stack->sym_data_[0].v_.uv1_); }
#line 911 "src/pp/pp_const_expr.c"
              }
              C9:;
            }
            break;
            /* log-and-exp: log-and-exp AMPERSAND_AMPERSAND or-exp */
            case 6: {
              stack->slot_1_has_sym_data_ = 1;
              stack->slot_1_sym_ = AEX_PPCE_LOG_AND_EXP;
              stack->continue_at_ = 10;
              {
#line 102 "grammar/pp/pp_const_expr.cbrt"
                { (stack->stack_[1].v_.uv1_).is_unsigned_ = 0; (stack->stack_[1].v_.uv1_).v_.u_ = ((stack->sym_data_[0].v_.uv1_).v_.u_ && (stack->sym_data_[2].v_.uv1_).v_.u_);}
#line 924 "src/pp/pp_const_expr.c"
              }
              C10:;
            }
            break;
            /* log-and-exp: or-exp */
            case 7: {
              stack->slot_1_has_sym_data_ = 1;
              stack->slot_1_sym_ = AEX_PPCE_LOG_AND_EXP;
              stack->continue_at_ = 11;
              {
#line 103 "grammar/pp/pp_const_expr.cbrt"
                { (stack->stack_[1].v_.uv1_) = (stack->sym_data_[0].v_.uv1_); }
#line 937 "src/pp/pp_const_expr.c"
              }
              C11:;
            }
            break;
            /* or-exp: or-exp BAR xor-exp */
            case 8: {
              stack->slot_1_has_sym_data_ = 1;
              stack->slot_1_sym_ = AEX_PPCE_OR_EXP;
              stack->continue_at_ = 12;
              {
#line 105 "grammar/pp/pp_const_expr.cbrt"
                { (stack->stack_[1].v_.uv1_).is_unsigned_ = (stack->sym_data_[0].v_.uv1_).is_unsigned_ || (stack->sym_data_[2].v_.uv1_).is_unsigned_; (stack->stack_[1].v_.uv1_).v_.u_ = (stack->sym_data_[0].v_.uv1_).v_.u_ | (stack->sym_data_[2].v_.uv1_).v_.u_; }
#line 950 "src/pp/pp_const_expr.c"
              }
              C12:;
            }
            break;
            /* or-exp: xor-exp */
            case 9: {
              stack->slot_1_has_sym_data_ = 1;
              stack->slot_1_sym_ = AEX_PPCE_OR_EXP;
              stack->continue_at_ = 13;
              {
#line 106 "grammar/pp/pp_const_expr.cbrt"
                { (stack->stack_[1].v_.uv1_) = (stack->sym_data_[0].v_.uv1_); }
#line 963 "src/pp/pp_const_expr.c"
              }
              C13:;
            }
            break;
            /* xor-exp: xor-exp CARET and-exp */
            case 10: {
              stack->slot_1_has_sym_data_ = 1;
              stack->slot_1_sym_ = AEX_PPCE_XOR_EXP;
              stack->continue_at_ = 14;
              {
#line 108 "grammar/pp/pp_const_expr.cbrt"
                { (stack->stack_[1].v_.uv1_).is_unsigned_ = (stack->sym_data_[0].v_.uv1_).is_unsigned_ || (stack->sym_data_[2].v_.uv1_).is_unsigned_; (stack->stack_[1].v_.uv1_).v_.u_ = (stack->sym_data_[0].v_.uv1_).v_.u_ ^ (stack->sym_data_[2].v_.uv1_).v_.u_; }
#line 976 "src/pp/pp_const_expr.c"
              }
              C14:;
            }
            break;
            /* xor-exp: and-exp */
            case 11: {
              stack->slot_1_has_sym_data_ = 1;
              stack->slot_1_sym_ = AEX_PPCE_XOR_EXP;
              stack->continue_at_ = 15;
              {
#line 109 "grammar/pp/pp_const_expr.cbrt"
                { (stack->stack_[1].v_.uv1_) = (stack->sym_data_[0].v_.uv1_); }
#line 989 "src/pp/pp_const_expr.c"
              }
              C15:;
            }
            break;
            /* and-exp: and-exp AMPERSAND equ-exp */
            case 12: {
              stack->slot_1_has_sym_data_ = 1;
              stack->slot_1_sym_ = AEX_PPCE_AND_EXP;
              stack->continue_at_ = 16;
              {
#line 111 "grammar/pp/pp_const_expr.cbrt"
                { (stack->stack_[1].v_.uv1_).is_unsigned_ = (stack->sym_data_[0].v_.uv1_).is_unsigned_ || (stack->sym_data_[2].v_.uv1_).is_unsigned_; (stack->stack_[1].v_.uv1_).v_.u_ = (stack->sym_data_[0].v_.uv1_).v_.u_ & (stack->sym_data_[2].v_.uv1_).v_.u_; }
#line 1002 "src/pp/pp_const_expr.c"
              }
              C16:;
            }
            break;
            /* and-exp: equ-exp */
            case 13: {
              stack->slot_1_has_sym_data_ = 1;
              stack->slot_1_sym_ = AEX_PPCE_AND_EXP;
              stack->continue_at_ = 17;
              {
#line 112 "grammar/pp/pp_const_expr.cbrt"
                { (stack->stack_[1].v_.uv1_) = (stack->sym_data_[0].v_.uv1_); }
#line 1015 "src/pp/pp_const_expr.c"
              }
              C17:;
            }
            break;
            /* equ-exp: equ-exp BANG_EQUALS rel-exp */
            case 14: {
              stack->slot_1_has_sym_data_ = 1;
              stack->slot_1_sym_ = AEX_PPCE_EQU_EXP;
              stack->continue_at_ = 18;
              {
#line 114 "grammar/pp/pp_const_expr.cbrt"
                { (stack->stack_[1].v_.uv1_).is_unsigned_ = 0; (stack->stack_[1].v_.uv1_).v_.u_ = ((stack->sym_data_[0].v_.uv1_).v_.u_ != (stack->sym_data_[2].v_.uv1_).v_.u_);}
#line 1028 "src/pp/pp_const_expr.c"
              }
              C18:;
            }
            break;
            /* equ-exp: equ-exp EQUALS_EQUALS rel-exp */
            case 15: {
              stack->slot_1_has_sym_data_ = 1;
              stack->slot_1_sym_ = AEX_PPCE_EQU_EXP;
              stack->continue_at_ = 19;
              {
#line 115 "grammar/pp/pp_const_expr.cbrt"
                { (stack->stack_[1].v_.uv1_).is_unsigned_ = 0; (stack->stack_[1].v_.uv1_).v_.u_ = ((stack->sym_data_[0].v_.uv1_).v_.u_ == (stack->sym_data_[2].v_.uv1_).v_.u_);}
#line 1041 "src/pp/pp_const_expr.c"
              }
              C19:;
            }
            break;
            /* equ-exp: rel-exp */
            case 16: {
              stack->slot_1_has_sym_data_ = 1;
              stack->slot_1_sym_ = AEX_PPCE_EQU_EXP;
              stack->continue_at_ = 20;
              {
#line 116 "grammar/pp/pp_const_expr.cbrt"
                { (stack->stack_[1].v_.uv1_) = (stack->sym_data_[0].v_.uv1_); }
#line 1054 "src/pp/pp_const_expr.c"
              }
              C20:;
            }
            break;
            /* rel-exp: rel-exp GT_EQUALS shift-exp */
            case 17: {
              stack->slot_1_has_sym_data_ = 1;
              stack->slot_1_sym_ = AEX_PPCE_REL_EXP;
              stack->continue_at_ = 21;
              {
#line 118 "grammar/pp/pp_const_expr.cbrt"
                {
  (stack->stack_[1].v_.uv1_).is_unsigned_ = 0;
  if ((stack->sym_data_[0].v_.uv1_).is_unsigned_ || (stack->sym_data_[2].v_.uv1_).is_unsigned_) {
    (stack->stack_[1].v_.uv1_).v_.i_ = (stack->sym_data_[0].v_.uv1_).v_.u_ >= (stack->sym_data_[2].v_.uv1_).v_.u_;
  }
  else {
    (stack->stack_[1].v_.uv1_).v_.i_ = (stack->sym_data_[0].v_.uv1_).v_.i_ >= (stack->sym_data_[2].v_.uv1_).v_.i_;
  }
}
#line 1075 "src/pp/pp_const_expr.c"
              }
              C21:;
            }
            break;
            /* rel-exp: rel-exp LT_EQUALS shift-exp */
            case 18: {
              stack->slot_1_has_sym_data_ = 1;
              stack->slot_1_sym_ = AEX_PPCE_REL_EXP;
              stack->continue_at_ = 22;
              {
#line 127 "grammar/pp/pp_const_expr.cbrt"
                {
  (stack->stack_[1].v_.uv1_).is_unsigned_ = 0;
  if ((stack->sym_data_[0].v_.uv1_).is_unsigned_ || (stack->sym_data_[2].v_.uv1_).is_unsigned_) {
    (stack->stack_[1].v_.uv1_).v_.i_ = (stack->sym_data_[0].v_.uv1_).v_.u_ <= (stack->sym_data_[2].v_.uv1_).v_.u_;
  }
  else {
    (stack->stack_[1].v_.uv1_).v_.i_ = (stack->sym_data_[0].v_.uv1_).v_.i_ <= (stack->sym_data_[2].v_.uv1_).v_.i_;
  }
}
#line 1096 "src/pp/pp_const_expr.c"
              }
              C22:;
            }
            break;
            /* rel-exp: rel-exp GT shift-exp */
            case 19: {
              stack->slot_1_has_sym_data_ = 1;
              stack->slot_1_sym_ = AEX_PPCE_REL_EXP;
              stack->continue_at_ = 23;
              {
#line 136 "grammar/pp/pp_const_expr.cbrt"
                {
  (stack->stack_[1].v_.uv1_).is_unsigned_ = 0;
  if ((stack->sym_data_[0].v_.uv1_).is_unsigned_ || (stack->sym_data_[2].v_.uv1_).is_unsigned_) {
    (stack->stack_[1].v_.uv1_).v_.i_ = (stack->sym_data_[0].v_.uv1_).v_.u_ > (stack->sym_data_[2].v_.uv1_).v_.u_;
  }
  else {
    (stack->stack_[1].v_.uv1_).v_.i_ = (stack->sym_data_[0].v_.uv1_).v_.i_ > (stack->sym_data_[2].v_.uv1_).v_.i_;
  }
}
#line 1117 "src/pp/pp_const_expr.c"
              }
              C23:;
            }
            break;
            /* rel-exp: rel-exp LT shift-exp */
            case 20: {
              stack->slot_1_has_sym_data_ = 1;
              stack->slot_1_sym_ = AEX_PPCE_REL_EXP;
              stack->continue_at_ = 24;
              {
#line 145 "grammar/pp/pp_const_expr.cbrt"
                {
  (stack->stack_[1].v_.uv1_).is_unsigned_ = 0;
  if ((stack->sym_data_[0].v_.uv1_).is_unsigned_ || (stack->sym_data_[2].v_.uv1_).is_unsigned_) {
    (stack->stack_[1].v_.uv1_).v_.i_ = (stack->sym_data_[0].v_.uv1_).v_.u_ < (stack->sym_data_[2].v_.uv1_).v_.u_;
  }
  else {
    (stack->stack_[1].v_.uv1_).v_.i_ = (stack->sym_data_[0].v_.uv1_).v_.i_ < (stack->sym_data_[2].v_.uv1_).v_.i_;
  }
}
#line 1138 "src/pp/pp_const_expr.c"
              }
              C24:;
            }
            break;
            /* rel-exp: shift-exp */
            case 21: {
              stack->slot_1_has_sym_data_ = 1;
              stack->slot_1_sym_ = AEX_PPCE_REL_EXP;
              stack->continue_at_ = 25;
              {
#line 154 "grammar/pp/pp_const_expr.cbrt"
                { (stack->stack_[1].v_.uv1_) = (stack->sym_data_[0].v_.uv1_); }
#line 1151 "src/pp/pp_const_expr.c"
              }
              C25:;
            }
            break;
            /* shift-exp: shift-exp GT_GT add-exp */
            case 22: {
              stack->slot_1_has_sym_data_ = 1;
              stack->slot_1_sym_ = AEX_PPCE_SHIFT_EXP;
              stack->continue_at_ = 26;
              {
#line 156 "grammar/pp/pp_const_expr.cbrt"
                { (stack->stack_[1].v_.uv1_).is_unsigned_ = (stack->sym_data_[0].v_.uv1_).is_unsigned_; (stack->stack_[1].v_.uv1_).v_.u_ = (stack->sym_data_[0].v_.uv1_).v_.u_ >> (stack->sym_data_[2].v_.uv1_).v_.u_; }
#line 1164 "src/pp/pp_const_expr.c"
              }
              C26:;
            }
            break;
            /* shift-exp: shift-exp LT_LT add-exp */
            case 23: {
              stack->slot_1_has_sym_data_ = 1;
              stack->slot_1_sym_ = AEX_PPCE_SHIFT_EXP;
              stack->continue_at_ = 27;
              {
#line 157 "grammar/pp/pp_const_expr.cbrt"
                { (stack->stack_[1].v_.uv1_).is_unsigned_ = (stack->sym_data_[0].v_.uv1_).is_unsigned_; (stack->stack_[1].v_.uv1_).v_.u_ = (stack->sym_data_[0].v_.uv1_).v_.u_ << (stack->sym_data_[2].v_.uv1_).v_.u_; }
#line 1177 "src/pp/pp_const_expr.c"
              }
              C27:;
            }
            break;
            /* shift-exp: add-exp */
            case 24: {
              stack->slot_1_has_sym_data_ = 1;
              stack->slot_1_sym_ = AEX_PPCE_SHIFT_EXP;
              stack->continue_at_ = 28;
              {
#line 158 "grammar/pp/pp_const_expr.cbrt"
                { (stack->stack_[1].v_.uv1_) = (stack->sym_data_[0].v_.uv1_); }
#line 1190 "src/pp/pp_const_expr.c"
              }
              C28:;
            }
            break;
            /* add-exp: add-exp MINUS mul-exp */
            case 25: {
              stack->slot_1_has_sym_data_ = 1;
              stack->slot_1_sym_ = AEX_PPCE_ADD_EXP;
              stack->continue_at_ = 29;
              {
#line 160 "grammar/pp/pp_const_expr.cbrt"
                { (stack->stack_[1].v_.uv1_).is_unsigned_ = (stack->sym_data_[0].v_.uv1_).is_unsigned_ || (stack->sym_data_[2].v_.uv1_).is_unsigned_; (stack->stack_[1].v_.uv1_).v_.u_ = (stack->sym_data_[0].v_.uv1_).v_.u_ - (stack->sym_data_[2].v_.uv1_).v_.u_; }
#line 1203 "src/pp/pp_const_expr.c"
              }
              C29:;
            }
            break;
            /* add-exp: add-exp PLUS mul-exp */
            case 26: {
              stack->slot_1_has_sym_data_ = 1;
              stack->slot_1_sym_ = AEX_PPCE_ADD_EXP;
              stack->continue_at_ = 30;
              {
#line 161 "grammar/pp/pp_const_expr.cbrt"
                { (stack->stack_[1].v_.uv1_).is_unsigned_ = (stack->sym_data_[0].v_.uv1_).is_unsigned_ || (stack->sym_data_[2].v_.uv1_).is_unsigned_; (stack->stack_[1].v_.uv1_).v_.u_ = (stack->sym_data_[0].v_.uv1_).v_.u_ + (stack->sym_data_[2].v_.uv1_).v_.u_; }
#line 1216 "src/pp/pp_const_expr.c"
              }
              C30:;
            }
            break;
            /* add-exp: mul-exp */
            case 27: {
              stack->slot_1_has_sym_data_ = 1;
              stack->slot_1_sym_ = AEX_PPCE_ADD_EXP;
              stack->continue_at_ = 31;
              {
#line 162 "grammar/pp/pp_const_expr.cbrt"
                { (stack->stack_[1].v_.uv1_) = (stack->sym_data_[0].v_.uv1_); }
#line 1229 "src/pp/pp_const_expr.c"
              }
              C31:;
            }
            break;
            /* mul-exp: mul-exp PERCENT cast-exp */
            case 28: {
              stack->slot_1_has_sym_data_ = 1;
              stack->slot_1_sym_ = AEX_PPCE_MUL_EXP;
              stack->continue_at_ = 32;
              {
#line 164 "grammar/pp/pp_const_expr.cbrt"
                {
  int divzero = 0;
  if ((stack->sym_data_[0].v_.uv1_).is_unsigned_ || (stack->sym_data_[2].v_.uv1_).is_unsigned_) {
    (stack->stack_[1].v_.uv1_).is_unsigned_ = 1;
    if ((stack->sym_data_[2].v_.uv1_).v_.u_) {
      (stack->stack_[1].v_.uv1_).v_.u_ = (stack->sym_data_[0].v_.uv1_).v_.u_ % (stack->sym_data_[2].v_.uv1_).v_.u_;
    }
    divzero = !(stack->sym_data_[2].v_.uv1_).v_.u_;
  }
  else {
    (stack->stack_[1].v_.uv1_).is_unsigned_ = 0;
    if ((stack->sym_data_[2].v_.uv1_).v_.i_) {
      (stack->stack_[1].v_.uv1_).v_.i_ = (stack->sym_data_[0].v_.uv1_).v_.i_ % (stack->sym_data_[2].v_.uv1_).v_.i_;
    }
    divzero = !(stack->sym_data_[2].v_.uv1_).v_.i_;
  }
  if (divzero) {
    dx_error_loc(pp->dx_, &(stack->sym_data_[1].v_.uv0_)->situs_, "Error during preprocessor constant expression evaluation: division by zero\n");
    (stack->stack_[1].v_.uv1_).v_.u_ = 0;
  }
}
#line 1262 "src/pp/pp_const_expr.c"
              }
              C32:;
            }
            break;
            /* mul-exp: mul-exp SLASH cast-exp */
            case 29: {
              stack->slot_1_has_sym_data_ = 1;
              stack->slot_1_sym_ = AEX_PPCE_MUL_EXP;
              stack->continue_at_ = 33;
              {
#line 185 "grammar/pp/pp_const_expr.cbrt"
                {
  int divzero = 0;
  if ((stack->sym_data_[0].v_.uv1_).is_unsigned_ || (stack->sym_data_[2].v_.uv1_).is_unsigned_) {
    (stack->stack_[1].v_.uv1_).is_unsigned_ = 1;
    if ((stack->sym_data_[2].v_.uv1_).v_.u_) {
      (stack->stack_[1].v_.uv1_).v_.u_ = (stack->sym_data_[0].v_.uv1_).v_.u_ / (stack->sym_data_[2].v_.uv1_).v_.u_;
    }
    divzero = !(stack->sym_data_[2].v_.uv1_).v_.u_;
  }
  else {
    (stack->stack_[1].v_.uv1_).is_unsigned_ = 0;
    if ((stack->sym_data_[2].v_.uv1_).v_.i_) {
      (stack->stack_[1].v_.uv1_).v_.i_ = (stack->sym_data_[0].v_.uv1_).v_.i_ / (stack->sym_data_[2].v_.uv1_).v_.i_;
    }
    divzero = !(stack->sym_data_[2].v_.uv1_).v_.i_;
  }
  if (divzero) {
    dx_error_loc(pp->dx_, &(stack->sym_data_[1].v_.uv0_)->situs_, "Error during preprocessor constant expression evaluation: division by zero\n");
    (stack->stack_[1].v_.uv1_).v_.u_ = 0;
  }
}
#line 1295 "src/pp/pp_const_expr.c"
              }
              C33:;
            }
            break;
            /* mul-exp: mul-exp ASTERISK cast-exp */
            case 30: {
              stack->slot_1_has_sym_data_ = 1;
              stack->slot_1_sym_ = AEX_PPCE_MUL_EXP;
              stack->continue_at_ = 34;
              {
#line 206 "grammar/pp/pp_const_expr.cbrt"
                { (stack->stack_[1].v_.uv1_).is_unsigned_ = (stack->sym_data_[0].v_.uv1_).is_unsigned_ || (stack->sym_data_[2].v_.uv1_).is_unsigned_; (stack->stack_[1].v_.uv1_).v_.u_ = (stack->sym_data_[0].v_.uv1_).v_.u_ * (stack->sym_data_[2].v_.uv1_).v_.u_; }
#line 1308 "src/pp/pp_const_expr.c"
              }
              C34:;
            }
            break;
            /* mul-exp: cast-exp */
            case 31: {
              stack->slot_1_has_sym_data_ = 1;
              stack->slot_1_sym_ = AEX_PPCE_MUL_EXP;
              stack->continue_at_ = 35;
              {
#line 207 "grammar/pp/pp_const_expr.cbrt"
                { (stack->stack_[1].v_.uv1_) = (stack->sym_data_[0].v_.uv1_); }
#line 1321 "src/pp/pp_const_expr.c"
              }
              C35:;
            }
            break;
            /* cast-exp: unary-exp */
            case 32: {
              stack->slot_1_has_sym_data_ = 1;
              stack->slot_1_sym_ = AEX_PPCE_CAST_EXP;
              stack->continue_at_ = 36;
              {
#line 209 "grammar/pp/pp_const_expr.cbrt"
                { (stack->stack_[1].v_.uv1_) = (stack->sym_data_[0].v_.uv1_); }
#line 1334 "src/pp/pp_const_expr.c"
              }
              C36:;
            }
            break;
            /* unary-exp: DEFINED PAR_OPEN IDENT PAR_CLOSE */
            case 33: {
              stack->slot_1_has_sym_data_ = 1;
              stack->slot_1_sym_ = AEX_PPCE_UNARY_EXP;
              stack->continue_at_ = 37;
              {
#line 211 "grammar/pp/pp_const_expr.cbrt"
                {
  struct macro *m = mt_find(&pp->macro_table_, (stack->sym_data_[2].v_.uv0_)->text_, (stack->sym_data_[2].v_.uv0_)->text_len_);
  (stack->stack_[1].v_.uv1_).is_unsigned_ = 1;
  (stack->stack_[1].v_.uv1_).v_.u_ = !!m;
}
#line 1351 "src/pp/pp_const_expr.c"
              }
              C37:;
            }
            break;
            /* unary-exp: DEFINED PAR_OPEN DEFINED PAR_CLOSE */
            case 34: {
              stack->slot_1_has_sym_data_ = 1;
              stack->slot_1_sym_ = AEX_PPCE_UNARY_EXP;
              stack->continue_at_ = 38;
              {
#line 216 "grammar/pp/pp_const_expr.cbrt"
                {
  /* edge case, is the word "defined" a macro */
  struct macro *m = mt_find(&pp->macro_table_, (stack->sym_data_[2].v_.uv0_)->text_, (stack->sym_data_[2].v_.uv0_)->text_len_);
  (stack->stack_[1].v_.uv1_).is_unsigned_ = 1;
  (stack->stack_[1].v_.uv1_).v_.u_ = !!m;
}
#line 1369 "src/pp/pp_const_expr.c"
              }
              C38:;
            }
            break;
            /* unary-exp: DEFINED IDENT */
            case 35: {
              stack->slot_1_has_sym_data_ = 1;
              stack->slot_1_sym_ = AEX_PPCE_UNARY_EXP;
              stack->continue_at_ = 39;
              {
#line 222 "grammar/pp/pp_const_expr.cbrt"
                {
  struct macro *m = mt_find(&pp->macro_table_, (stack->sym_data_[1].v_.uv0_)->text_, (stack->sym_data_[1].v_.uv0_)->text_len_);
  (stack->stack_[1].v_.uv1_).is_unsigned_ = 1;
  (stack->stack_[1].v_.uv1_).v_.u_ = !!m;
}
#line 1386 "src/pp/pp_const_expr.c"
              }
              C39:;
            }
            break;
            /* unary-exp: DEFINED DEFINED */
            case 36: {
              stack->slot_1_has_sym_data_ = 1;
              stack->slot_1_sym_ = AEX_PPCE_UNARY_EXP;
              stack->continue_at_ = 40;
              {
#line 227 "grammar/pp/pp_const_expr.cbrt"
                {
  /* edge case, is the word "defined" a macro */
  struct macro *m = mt_find(&pp->macro_table_, (stack->sym_data_[1].v_.uv0_)->text_, (stack->sym_data_[1].v_.uv0_)->text_len_);
  (stack->stack_[1].v_.uv1_).is_unsigned_ = 1;
  (stack->stack_[1].v_.uv1_).v_.u_ = !!m;
}
#line 1404 "src/pp/pp_const_expr.c"
              }
              C40:;
            }
            break;
            /* unary-exp: BANG cast-exp */
            case 37: {
              stack->slot_1_has_sym_data_ = 1;
              stack->slot_1_sym_ = AEX_PPCE_UNARY_EXP;
              stack->continue_at_ = 41;
              {
#line 234 "grammar/pp/pp_const_expr.cbrt"
                { (stack->stack_[1].v_.uv1_) = (stack->sym_data_[1].v_.uv1_); (stack->stack_[1].v_.uv1_).v_.u_ = !(stack->stack_[1].v_.uv1_).v_.u_; }
#line 1417 "src/pp/pp_const_expr.c"
              }
              C41:;
            }
            break;
            /* unary-exp: TILDE cast-exp */
            case 38: {
              stack->slot_1_has_sym_data_ = 1;
              stack->slot_1_sym_ = AEX_PPCE_UNARY_EXP;
              stack->continue_at_ = 42;
              {
#line 235 "grammar/pp/pp_const_expr.cbrt"
                { (stack->stack_[1].v_.uv1_) = (stack->sym_data_[1].v_.uv1_); (stack->stack_[1].v_.uv1_).v_.u_ = ~(stack->stack_[1].v_.uv1_).v_.u_; }
#line 1430 "src/pp/pp_const_expr.c"
              }
              C42:;
            }
            break;
            /* unary-exp: MINUS cast-exp */
            case 39: {
              stack->slot_1_has_sym_data_ = 1;
              stack->slot_1_sym_ = AEX_PPCE_UNARY_EXP;
              stack->continue_at_ = 43;
              {
#line 236 "grammar/pp/pp_const_expr.cbrt"
                { (stack->stack_[1].v_.uv1_) = (stack->sym_data_[1].v_.uv1_); (stack->stack_[1].v_.uv1_).v_.i_ = -(stack->stack_[1].v_.uv1_).v_.i_; }
#line 1443 "src/pp/pp_const_expr.c"
              }
              C43:;
            }
            break;
            /* unary-exp: PLUS cast-exp */
            case 40: {
              stack->slot_1_has_sym_data_ = 1;
              stack->slot_1_sym_ = AEX_PPCE_UNARY_EXP;
              stack->continue_at_ = 44;
              {
#line 237 "grammar/pp/pp_const_expr.cbrt"
                { (stack->stack_[1].v_.uv1_) = (stack->sym_data_[1].v_.uv1_); }
#line 1456 "src/pp/pp_const_expr.c"
              }
              C44:;
            }
            break;
            /* unary-exp: postfix-exp */
            case 41: {
              stack->slot_1_has_sym_data_ = 1;
              stack->slot_1_sym_ = AEX_PPCE_UNARY_EXP;
              stack->continue_at_ = 45;
              {
#line 238 "grammar/pp/pp_const_expr.cbrt"
                { (stack->stack_[1].v_.uv1_) = (stack->sym_data_[0].v_.uv1_); }
#line 1469 "src/pp/pp_const_expr.c"
              }
              C45:;
            }
            break;
            /* postfix-exp: primary-exp */
            case 42: {
              stack->slot_1_has_sym_data_ = 1;
              stack->slot_1_sym_ = AEX_PPCE_POSTFIX_EXP;
              stack->continue_at_ = 46;
              {
#line 240 "grammar/pp/pp_const_expr.cbrt"
                { (stack->stack_[1].v_.uv1_) = (stack->sym_data_[0].v_.uv1_); }
#line 1482 "src/pp/pp_const_expr.c"
              }
              C46:;
            }
            break;
            /* primary-exp: PAR_OPEN constant-exp PAR_CLOSE */
            case 43: {
              stack->slot_1_has_sym_data_ = 1;
              stack->slot_1_sym_ = AEX_PPCE_PRIMARY_EXP;
              stack->continue_at_ = 47;
              {
#line 242 "grammar/pp/pp_const_expr.cbrt"
                { (stack->stack_[1].v_.uv1_) = (stack->sym_data_[1].v_.uv1_); }
#line 1495 "src/pp/pp_const_expr.c"
              }
              C47:;
            }
            break;
            /* primary-exp: CHAR_LIT */
            case 44: {
              stack->slot_1_has_sym_data_ = 1;
              stack->slot_1_sym_ = AEX_PPCE_PRIMARY_EXP;
              stack->continue_at_ = 48;
              {
#line 269 "grammar/pp/pp_const_expr.cbrt"
                { 
  if (aex_ppce_int_const_expr_to_value(pp, &(stack->stack_[1].v_.uv1_), (stack->sym_data_[0].v_.uv0_))) {
    /* XXX: handle failure.. */
  } 
}
#line 1512 "src/pp/pp_const_expr.c"
              }
              C48:;
            }
            break;
            /* primary-exp: INTEGER_LIT */
            case 45: {
              stack->slot_1_has_sym_data_ = 1;
              stack->slot_1_sym_ = AEX_PPCE_PRIMARY_EXP;
              stack->continue_at_ = 49;
              {
#line 274 "grammar/pp/pp_const_expr.cbrt"
                {
  if (aex_ppce_int_const_expr_to_value(pp, &(stack->stack_[1].v_.uv1_), (stack->sym_data_[0].v_.uv0_))) {
    /* XXX: handle failure.. */
  }
}
#line 1529 "src/pp/pp_const_expr.c"
              }
              C49:;
            }
            break;
            /* primary-exp: IDENT */
            case 46: {
              stack->slot_1_has_sym_data_ = 1;
              stack->slot_1_sym_ = AEX_PPCE_PRIMARY_EXP;
              stack->continue_at_ = 50;
              {
#line 279 "grammar/pp/pp_const_expr.cbrt"
                {
  (stack->stack_[1].v_.uv1_).is_unsigned_ = 0;
  (stack->stack_[1].v_.uv1_).v_.i_ = 0;
}
#line 1545 "src/pp/pp_const_expr.c"
              }
              C50:;
            }
            break;
          } /* switch */
        } /* scope guard */
        
        stack->pos_ -= stack->current_production_length_;
        stack->top_of_stack_has_sym_data_ = stack->top_of_stack_has_common_data_ = 1;
        action = aex_ppce_parse_table[aex_ppce_num_columns * stack->stack_[stack->pos_ - 1].state_ + (stack->current_production_nonterminal_ - aex_ppce_minimum_sym)];
        if (action <= 0) {
          stack->continue_at_ = 0;
          /* Internal error */
          return _AEX_PPCE_INTERNAL_ERROR;
        }
        if (stack->num_stack_allocated_ == stack->pos_) {
          stack->action_preservation_ = action /* action for a "goto" shift is the ordinal */;
          size_t new_num_allocated;
          if (stack->num_stack_allocated_) {
            new_num_allocated = stack->num_stack_allocated_ * 2;
            if (new_num_allocated <= stack->num_stack_allocated_) {
              /* Overflow in allocation */
              return _AEX_PPCE_OVERFLOW;
            }
          }
          else {
            new_num_allocated = 16;
          }
          
          if (new_num_allocated > (SIZE_MAX / sizeof(struct aex_ppce_sym_data))) {
            /* Overflow in allocation */
            return _AEX_PPCE_OVERFLOW;
          }
          
          stack->new_buf_ = (struct aex_ppce_sym_data *)malloc(new_num_allocated * sizeof(struct aex_ppce_sym_data));
          if (!stack->new_buf_) {
            /* Out of memory */
            return _AEX_PPCE_NO_MEMORY;
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
                  case AEX_PPCE_QUESTION_MARK:
                  case AEX_PPCE_COLON:
                  case AEX_PPCE_BAR_BAR:
                  case AEX_PPCE_AMPERSAND_AMPERSAND:
                  case AEX_PPCE_BAR:
                  case AEX_PPCE_CARET:
                  case AEX_PPCE_AMPERSAND:
                  case AEX_PPCE_BANG_EQUALS:
                  case AEX_PPCE_EQUALS_EQUALS:
                  case AEX_PPCE_GT_EQUALS:
                  case AEX_PPCE_LT_EQUALS:
                  case AEX_PPCE_GT:
                  case AEX_PPCE_LT:
                  case AEX_PPCE_GT_GT:
                  case AEX_PPCE_LT_LT:
                  case AEX_PPCE_MINUS:
                  case AEX_PPCE_PLUS:
                  case AEX_PPCE_PERCENT:
                  case AEX_PPCE_SLASH:
                  case AEX_PPCE_ASTERISK:
                  case AEX_PPCE_DEFINED:
                  case AEX_PPCE_PAR_OPEN:
                  case AEX_PPCE_IDENT:
                  case AEX_PPCE_PAR_CLOSE:
                  case AEX_PPCE_BANG:
                  case AEX_PPCE_TILDE:
                  case AEX_PPCE_MINUS_MINUS:
                  case AEX_PPCE_PLUS_PLUS:
                  case AEX_PPCE_CHAR_LIT:
                  case AEX_PPCE_INTEGER_LIT:
                  case AEX_PPCE_WS:
                  case AEX_PPCE_OTHER:
                  stack->newbuf_pos_has_sym_data_ = 1;
                  stack->continue_at_ = 51;
                  {
#line 65 "grammar/pp/pp_const_expr.cbrt"
                    stack->new_buf_[stack->new_buf_sym_partial_pos_].v_.uv0_ = NULL;
#line 1642 "src/pp/pp_const_expr.c"
                  }
                  C51:;
                  memcpy(&stack->new_buf_[stack->new_buf_sym_partial_pos_].v_, &stack->stack_[stack->new_buf_sym_partial_pos_].v_, sizeof(stack->stack_->v_));
                  stack->stack_newbuf_pos_has_sym_data_ = 0;
                  
                  break;
                  case AEX_PPCE_PRIMARY_EXP:
                  case AEX_PPCE_CONSTANT_EXP:
                  case AEX_PPCE_COND_EXP:
                  case AEX_PPCE_LOG_OR_EXP:
                  case AEX_PPCE_LOG_AND_EXP:
                  case AEX_PPCE_OR_EXP:
                  case AEX_PPCE_XOR_EXP:
                  case AEX_PPCE_AND_EXP:
                  case AEX_PPCE_EQU_EXP:
                  case AEX_PPCE_REL_EXP:
                  case AEX_PPCE_SHIFT_EXP:
                  case AEX_PPCE_ADD_EXP:
                  case AEX_PPCE_MUL_EXP:
                  case AEX_PPCE_CAST_EXP:
                  case AEX_PPCE_UNARY_EXP:
                  case AEX_PPCE_POSTFIX_EXP:
                  stack->newbuf_pos_has_sym_data_ = 1;
                  memcpy(&stack->new_buf_[stack->new_buf_sym_partial_pos_].v_, &stack->stack_[stack->new_buf_sym_partial_pos_].v_, sizeof(stack->stack_->v_));
                  stack->stack_newbuf_pos_has_sym_data_ = 0;
                  
                  break;
                }
              }
            }
            else /* not 0 or 1, but >= 2 state derived sym */ {
              switch (stack->stack_[stack->new_buf_sym_partial_pos_].state_) {
                case 2: /* PAR_CLOSE */
                case 5: /* COLON */
                case 8: /* QUESTION_MARK */
                case 10: /* BAR_BAR */
                case 13: /* AMPERSAND_AMPERSAND */
                case 16: /* BAR */
                case 19: /* CARET */
                case 22: /* AMPERSAND */
                case 25: /* BANG_EQUALS */
                case 27: /* EQUALS_EQUALS */
                case 30: /* GT_EQUALS */
                case 32: /* LT_EQUALS */
                case 34: /* GT */
                case 36: /* LT */
                case 39: /* GT_GT */
                case 41: /* LT_LT */
                case 44: /* MINUS */
                case 46: /* PLUS */
                case 49: /* PERCENT */
                case 51: /* SLASH */
                case 53: /* ASTERISK */
                case 61: /* PAR_CLOSE */
                case 62: /* IDENT */
                case 63: /* PAR_CLOSE */
                case 64: /* DEFINED */
                case 65: /* PAR_OPEN */
                case 66: /* IDENT */
                case 67: /* DEFINED */
                case 68: /* DEFINED */
                case 69: /* BANG */
                case 70: /* TILDE */
                case 71: /* MINUS */
                case 72: /* PLUS */
                case 75: /* PAR_OPEN */
                case 76: /* CHAR_LIT */
                case 77: /* INTEGER_LIT */
                case 78: /* IDENT */
                stack->newbuf_pos_has_sym_data_ = 1;
                stack->continue_at_ = 52;
                {
#line 65 "grammar/pp/pp_const_expr.cbrt"
                  stack->new_buf_[stack->new_buf_sym_partial_pos_].v_.uv0_ = NULL;
#line 1717 "src/pp/pp_const_expr.c"
                }
                C52:;
                memcpy(&stack->new_buf_[stack->new_buf_sym_partial_pos_].v_, &stack->stack_[stack->new_buf_sym_partial_pos_].v_, sizeof(stack->stack_->v_));
                stack->stack_newbuf_pos_has_sym_data_ = 0;
                break;
                
                case 1: /* constant-exp */
                case 3: /* constant-exp */
                case 4: /* cond-exp */
                case 6: /* constant-exp */
                case 7: /* cond-exp */
                case 9: /* log-and-exp */
                case 11: /* log-or-exp */
                case 12: /* or-exp */
                case 14: /* log-and-exp */
                case 15: /* xor-exp */
                case 17: /* or-exp */
                case 18: /* and-exp */
                case 20: /* xor-exp */
                case 21: /* equ-exp */
                case 23: /* and-exp */
                case 24: /* rel-exp */
                case 26: /* rel-exp */
                case 28: /* equ-exp */
                case 29: /* shift-exp */
                case 31: /* shift-exp */
                case 33: /* shift-exp */
                case 35: /* shift-exp */
                case 37: /* rel-exp */
                case 38: /* add-exp */
                case 40: /* add-exp */
                case 42: /* shift-exp */
                case 43: /* mul-exp */
                case 45: /* mul-exp */
                case 47: /* add-exp */
                case 48: /* cast-exp */
                case 50: /* cast-exp */
                case 52: /* cast-exp */
                case 54: /* mul-exp */
                case 55: /* cast-exp */
                case 56: /* cast-exp */
                case 57: /* cast-exp */
                case 58: /* cast-exp */
                case 59: /* cast-exp */
                case 60: /* unary-exp */
                case 73: /* postfix-exp */
                case 74: /* primary-exp */
                memcpy(&stack->new_buf_[stack->new_buf_sym_partial_pos_].v_, &stack->stack_[stack->new_buf_sym_partial_pos_].v_, sizeof(stack->stack_->v_));
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
          case 2: /* PAR_CLOSE */
          case 5: /* COLON */
          case 8: /* QUESTION_MARK */
          case 10: /* BAR_BAR */
          case 13: /* AMPERSAND_AMPERSAND */
          case 16: /* BAR */
          case 19: /* CARET */
          case 22: /* AMPERSAND */
          case 25: /* BANG_EQUALS */
          case 27: /* EQUALS_EQUALS */
          case 30: /* GT_EQUALS */
          case 32: /* LT_EQUALS */
          case 34: /* GT */
          case 36: /* LT */
          case 39: /* GT_GT */
          case 41: /* LT_LT */
          case 44: /* MINUS */
          case 46: /* PLUS */
          case 49: /* PERCENT */
          case 51: /* SLASH */
          case 53: /* ASTERISK */
          case 61: /* PAR_CLOSE */
          case 62: /* IDENT */
          case 63: /* PAR_CLOSE */
          case 64: /* DEFINED */
          case 65: /* PAR_OPEN */
          case 66: /* IDENT */
          case 67: /* DEFINED */
          case 68: /* DEFINED */
          case 69: /* BANG */
          case 70: /* TILDE */
          case 71: /* MINUS */
          case 72: /* PLUS */
          case 75: /* PAR_OPEN */
          case 76: /* CHAR_LIT */
          case 77: /* INTEGER_LIT */
          case 78: /* IDENT */
          stack->top_of_stack_has_sym_data_ = 1;
          stack->continue_at_ = 53;
          {
#line 65 "grammar/pp/pp_const_expr.cbrt"
            ((stack->stack_ + stack->pos_ - 1)->v_.uv0_) = NULL;
#line 1824 "src/pp/pp_const_expr.c"
          }
          C53:;
          memcpy(&stack->stack_[stack->pos_ - 1].v_, &stack->stack_[1].v_, sizeof(stack->stack_->v_));
          break;
          case 1: /* constant-exp */
          case 3: /* constant-exp */
          case 4: /* cond-exp */
          case 6: /* constant-exp */
          case 7: /* cond-exp */
          case 9: /* log-and-exp */
          case 11: /* log-or-exp */
          case 12: /* or-exp */
          case 14: /* log-and-exp */
          case 15: /* xor-exp */
          case 17: /* or-exp */
          case 18: /* and-exp */
          case 20: /* xor-exp */
          case 21: /* equ-exp */
          case 23: /* and-exp */
          case 24: /* rel-exp */
          case 26: /* rel-exp */
          case 28: /* equ-exp */
          case 29: /* shift-exp */
          case 31: /* shift-exp */
          case 33: /* shift-exp */
          case 35: /* shift-exp */
          case 37: /* rel-exp */
          case 38: /* add-exp */
          case 40: /* add-exp */
          case 42: /* shift-exp */
          case 43: /* mul-exp */
          case 45: /* mul-exp */
          case 47: /* add-exp */
          case 48: /* cast-exp */
          case 50: /* cast-exp */
          case 52: /* cast-exp */
          case 54: /* mul-exp */
          case 55: /* cast-exp */
          case 56: /* cast-exp */
          case 57: /* cast-exp */
          case 58: /* cast-exp */
          case 59: /* cast-exp */
          case 60: /* unary-exp */
          case 73: /* postfix-exp */
          case 74: /* primary-exp */
          memcpy(&stack->stack_[stack->pos_ - 1].v_, &stack->stack_[1].v_, sizeof(stack->stack_->v_));
          break;
        } /* switch (top of stack state) */
        stack->slot_1_has_sym_data_ = 0;
      } /* action < 0 */
      else /* action == 0 */ {
        /* check if we can recover using an error token. */
        size_t n;
        for (n = 0; n < stack->pos_; ++n) {
          stack->current_err_action_ = aex_ppce_parse_table[aex_ppce_num_columns * stack->stack_[n].state_ + (35 /* error token */ - aex_ppce_minimum_sym)];
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
          return _AEX_PPCE_SYNTAX_ERROR;
        }
        else {
          stack->mute_error_turns_--;
          if (sym == AEX_PPCE_INPUT_END) {
            /* EOF means we cannot shift to recover, and errors are muted, so return completion */
            stack->pending_reset_ = 1;
            return _AEX_PPCE_FINISH;
          }
          /* Retain EOF but discard any other sym so we make progress */
          stack->continue_at_ = 0;
          {
            do {                                               \
              (*pp_current_tk) = (*pp_current_tk)->next_;      \
              if ((*pp_current_tk) != input_chain) {           \
                sym = g_aex_pptk_to_ppce_[(*pp_current_tk)->tok_]; \
                }                                                \
              else {                                           \
                if (is_final) {                                \
                  sym = AEX_PPCE_INPUT_END;                        \
                  }                                              \
                else {                                         \
                  return _AEX_PPCE_FEED_ME;                        \
                  }                                              \
                }                                                \
              } while (sym == AEX_PPCE_WS);
            
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
          stack->current_err_action_ = aex_ppce_parse_table[aex_ppce_num_columns * stack->stack_[n].state_ + (35 /* error token */ - aex_ppce_minimum_sym)];
          if (stack->current_err_action_ > 0) {
            /* Does the resulting state accept the current symbol? */
            int err_sym_action;
            err_sym_action = aex_ppce_parse_table[aex_ppce_num_columns * stack->current_err_action_ + (sym - aex_ppce_minimum_sym)];
            if (err_sym_action) {
              /* Current symbol is accepted, recover error condition by shifting the error token and then process the symbol as usual */
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
                    return _AEX_PPCE_OVERFLOW;
                  }
                }
                else {
                  new_num_allocated = 16;
                }
                
                if (new_num_allocated > (SIZE_MAX / sizeof(struct aex_ppce_sym_data))) {
                  /* Overflow in allocation */
                  return _AEX_PPCE_OVERFLOW;
                }
                
                stack->new_buf_ = (struct aex_ppce_sym_data *)malloc(new_num_allocated * sizeof(struct aex_ppce_sym_data));
                if (!stack->new_buf_) {
                  /* Out of memory */
                  return _AEX_PPCE_NO_MEMORY;
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
                        case AEX_PPCE_QUESTION_MARK:
                        case AEX_PPCE_COLON:
                        case AEX_PPCE_BAR_BAR:
                        case AEX_PPCE_AMPERSAND_AMPERSAND:
                        case AEX_PPCE_BAR:
                        case AEX_PPCE_CARET:
                        case AEX_PPCE_AMPERSAND:
                        case AEX_PPCE_BANG_EQUALS:
                        case AEX_PPCE_EQUALS_EQUALS:
                        case AEX_PPCE_GT_EQUALS:
                        case AEX_PPCE_LT_EQUALS:
                        case AEX_PPCE_GT:
                        case AEX_PPCE_LT:
                        case AEX_PPCE_GT_GT:
                        case AEX_PPCE_LT_LT:
                        case AEX_PPCE_MINUS:
                        case AEX_PPCE_PLUS:
                        case AEX_PPCE_PERCENT:
                        case AEX_PPCE_SLASH:
                        case AEX_PPCE_ASTERISK:
                        case AEX_PPCE_DEFINED:
                        case AEX_PPCE_PAR_OPEN:
                        case AEX_PPCE_IDENT:
                        case AEX_PPCE_PAR_CLOSE:
                        case AEX_PPCE_BANG:
                        case AEX_PPCE_TILDE:
                        case AEX_PPCE_MINUS_MINUS:
                        case AEX_PPCE_PLUS_PLUS:
                        case AEX_PPCE_CHAR_LIT:
                        case AEX_PPCE_INTEGER_LIT:
                        case AEX_PPCE_WS:
                        case AEX_PPCE_OTHER:
                        stack->newbuf_pos_has_sym_data_ = 1;
                        stack->continue_at_ = 54;
                        {
#line 65 "grammar/pp/pp_const_expr.cbrt"
                          stack->new_buf_[stack->new_buf_sym_partial_pos_].v_.uv0_ = NULL;
#line 2021 "src/pp/pp_const_expr.c"
                        }
                        C54:;
                        memcpy(&stack->new_buf_[stack->new_buf_sym_partial_pos_].v_, &stack->stack_[stack->new_buf_sym_partial_pos_].v_, sizeof(stack->stack_->v_));
                        stack->stack_newbuf_pos_has_sym_data_ = 0;
                        
                        break;
                        case AEX_PPCE_PRIMARY_EXP:
                        case AEX_PPCE_CONSTANT_EXP:
                        case AEX_PPCE_COND_EXP:
                        case AEX_PPCE_LOG_OR_EXP:
                        case AEX_PPCE_LOG_AND_EXP:
                        case AEX_PPCE_OR_EXP:
                        case AEX_PPCE_XOR_EXP:
                        case AEX_PPCE_AND_EXP:
                        case AEX_PPCE_EQU_EXP:
                        case AEX_PPCE_REL_EXP:
                        case AEX_PPCE_SHIFT_EXP:
                        case AEX_PPCE_ADD_EXP:
                        case AEX_PPCE_MUL_EXP:
                        case AEX_PPCE_CAST_EXP:
                        case AEX_PPCE_UNARY_EXP:
                        case AEX_PPCE_POSTFIX_EXP:
                        stack->newbuf_pos_has_sym_data_ = 1;
                        memcpy(&stack->new_buf_[stack->new_buf_sym_partial_pos_].v_, &stack->stack_[stack->new_buf_sym_partial_pos_].v_, sizeof(stack->stack_->v_));
                        stack->stack_newbuf_pos_has_sym_data_ = 0;
                        
                        break;
                      }
                    }
                  }
                  else /* not 0 or 1, but >= 2 state derived sym */ {
                    switch (stack->stack_[stack->new_buf_sym_partial_pos_].state_) {
                      case 2: /* PAR_CLOSE */
                      case 5: /* COLON */
                      case 8: /* QUESTION_MARK */
                      case 10: /* BAR_BAR */
                      case 13: /* AMPERSAND_AMPERSAND */
                      case 16: /* BAR */
                      case 19: /* CARET */
                      case 22: /* AMPERSAND */
                      case 25: /* BANG_EQUALS */
                      case 27: /* EQUALS_EQUALS */
                      case 30: /* GT_EQUALS */
                      case 32: /* LT_EQUALS */
                      case 34: /* GT */
                      case 36: /* LT */
                      case 39: /* GT_GT */
                      case 41: /* LT_LT */
                      case 44: /* MINUS */
                      case 46: /* PLUS */
                      case 49: /* PERCENT */
                      case 51: /* SLASH */
                      case 53: /* ASTERISK */
                      case 61: /* PAR_CLOSE */
                      case 62: /* IDENT */
                      case 63: /* PAR_CLOSE */
                      case 64: /* DEFINED */
                      case 65: /* PAR_OPEN */
                      case 66: /* IDENT */
                      case 67: /* DEFINED */
                      case 68: /* DEFINED */
                      case 69: /* BANG */
                      case 70: /* TILDE */
                      case 71: /* MINUS */
                      case 72: /* PLUS */
                      case 75: /* PAR_OPEN */
                      case 76: /* CHAR_LIT */
                      case 77: /* INTEGER_LIT */
                      case 78: /* IDENT */
                      stack->newbuf_pos_has_sym_data_ = 1;
                      stack->continue_at_ = 55;
                      {
#line 65 "grammar/pp/pp_const_expr.cbrt"
                        stack->new_buf_[stack->new_buf_sym_partial_pos_].v_.uv0_ = NULL;
#line 2096 "src/pp/pp_const_expr.c"
                      }
                      C55:;
                      memcpy(&stack->new_buf_[stack->new_buf_sym_partial_pos_].v_, &stack->stack_[stack->new_buf_sym_partial_pos_].v_, sizeof(stack->stack_->v_));
                      stack->stack_newbuf_pos_has_sym_data_ = 0;
                      break;
                      
                      case 1: /* constant-exp */
                      case 3: /* constant-exp */
                      case 4: /* cond-exp */
                      case 6: /* constant-exp */
                      case 7: /* cond-exp */
                      case 9: /* log-and-exp */
                      case 11: /* log-or-exp */
                      case 12: /* or-exp */
                      case 14: /* log-and-exp */
                      case 15: /* xor-exp */
                      case 17: /* or-exp */
                      case 18: /* and-exp */
                      case 20: /* xor-exp */
                      case 21: /* equ-exp */
                      case 23: /* and-exp */
                      case 24: /* rel-exp */
                      case 26: /* rel-exp */
                      case 28: /* equ-exp */
                      case 29: /* shift-exp */
                      case 31: /* shift-exp */
                      case 33: /* shift-exp */
                      case 35: /* shift-exp */
                      case 37: /* rel-exp */
                      case 38: /* add-exp */
                      case 40: /* add-exp */
                      case 42: /* shift-exp */
                      case 43: /* mul-exp */
                      case 45: /* mul-exp */
                      case 47: /* add-exp */
                      case 48: /* cast-exp */
                      case 50: /* cast-exp */
                      case 52: /* cast-exp */
                      case 54: /* mul-exp */
                      case 55: /* cast-exp */
                      case 56: /* cast-exp */
                      case 57: /* cast-exp */
                      case 58: /* cast-exp */
                      case 59: /* cast-exp */
                      case 60: /* unary-exp */
                      case 73: /* postfix-exp */
                      case 74: /* primary-exp */
                      memcpy(&stack->new_buf_[stack->new_buf_sym_partial_pos_].v_, &stack->stack_[stack->new_buf_sym_partial_pos_].v_, sizeof(stack->stack_->v_));
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
        if (sym == AEX_PPCE_INPUT_END) {
          /* EOF means we cannot shift to recover, so return completion */
          stack->pending_reset_ = 1;
          return _AEX_PPCE_FINISH;
        }
        stack->continue_at_ = 0;
        {
          do {                                               \
            (*pp_current_tk) = (*pp_current_tk)->next_;      \
            if ((*pp_current_tk) != input_chain) {           \
              sym = g_aex_pptk_to_ppce_[(*pp_current_tk)->tok_]; \
              }                                                \
            else {                                           \
              if (is_final) {                                \
                sym = AEX_PPCE_INPUT_END;                        \
                }                                              \
              else {                                         \
                return _AEX_PPCE_FEED_ME;                        \
                }                                              \
              }                                                \
            } while (sym == AEX_PPCE_WS);
          
        }
      }
    } /* stack->error_recovery_ */
  } /* for (;;) */
}
/* --------- END OF GENERATED CODE ------------ */
