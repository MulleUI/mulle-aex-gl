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

#ifndef PP_H
#define PP_H

#ifndef DIAGS_H_INCLUDED
#define DIAGS_H_INCLUDED
#include "diags.h"
#endif

#ifndef SITUS_H_INCLUDED
#define SITUS_H_INCLUDED
#include "situs.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

struct pptk;
struct mulle_cpp;
struct pp_input_file;

enum preprocessor_result {
  PPR_SUCCESS,
  PPR_NEED_INPUT,
  PPR_NEW_INCLUDE,
  PPR_OLD_INCLUDE,
  PPR_HAVE_ERRORS,
  PPR_FAILED
};

/* The GLSL preprocessor is a thin adapter over mulle-cpp-engine. It pulls
 * engine tokens, converts them to the parser's pptk representation, and
 * keeps the same stage/result protocol the compiler already uses. */
struct preprocessor {
  struct diags default_dx_;
  struct diags *dx_;

  struct mulle_cpp *cpp_;

  /* Tokens ready for the GLSL parser. */
  struct pptk *pp_output_;
  int pp_output_final_;

  /* A synthetic token left over from splitting a malformed number such as
   * 1.2.3 into the parser-visible pieces 1.2 and .3. */
  struct pptk *pending_token_;

  /* The currently pushed input source. */
  struct pp_input_file *input_file_;

  int source_started_ : 1;
  int source_unpoppable_ : 1;
  const char *source_start_;
  const char *source_end_;
};

void pp_init(struct preprocessor *pp);
void pp_cleanup(struct preprocessor *pp);

/* Defines a macro like "NAME=replacement" for the engine. */
int pp_define_macro(struct preprocessor *pp, const char *name,
                    const char *replacement);

struct pp_input_file *pp_push_input_file(struct preprocessor *pp,
                                        const char *filename,
                                        size_t aux_data);

enum preprocessor_result pp_preprocessor_stage(struct preprocessor *pp);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* PP_H */
