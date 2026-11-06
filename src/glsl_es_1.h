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

#ifndef GLSL_ES_1_H
#define GLSL_ES_1_H

#include <stddef.h> /* size_t */

#ifdef __cplusplus
extern "C" {
  #endif

  struct glsl_es1_compiler;
  struct pptk;
  struct sl_type;

  #define _GLSL_ES1_FINISH 0
  #define _GLSL_ES1_MATCH 1
  #define _GLSL_ES1_OVERFLOW 2
  #define _GLSL_ES1_NO_MEMORY 3
  #define _GLSL_ES1_FEED_ME 4
  #define _GLSL_ES1_END_OF_INPUT 5
  #define _GLSL_ES1_SYNTAX_ERROR 6
  #define _GLSL_ES1_LEXICAL_ERROR 7
  #define _GLSL_ES1_INTERNAL_ERROR 8

  /* A chunk of preprocessed tokens waiting for the recursive descent parser.
   * Tokens are owned by the stack until glsl_es1_parser_finish() succeeds or
   * fails, at which point they are released. */
  struct glsl_es1_stack {
    struct pptk **tokens_;
    size_t count_;
    size_t allocated_;
    size_t pos_;
    struct glsl_es1_compiler *cc_;
    int failed_;
    int result_;
    int loop_depth_;
    struct sl_type *current_return_type_;
  };

  void glsl_es1_stack_init(struct glsl_es1_stack *stack);
  void glsl_es1_stack_cleanup(struct glsl_es1_stack *stack);
  int glsl_es1_stack_reset(struct glsl_es1_stack *stack);

  /* Appends a preprocessed token. Takes ownership of the token. */
  int glsl_es1_parser_push(struct glsl_es1_stack *stack, struct glsl_es1_compiler *cc, struct pptk *token);

  /* Parses all buffered tokens as a sequence of external declarations and
   * releases them. Returns _GLSL_ES1_FINISH or _GLSL_ES1_SYNTAX_ERROR. */
  int glsl_es1_parser_finish(struct glsl_es1_stack *stack, struct glsl_es1_compiler *cc);

  #ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* GLSL_ES_1_H */
