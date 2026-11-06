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

#ifndef PP_INPUT_FILE_H
#define PP_INPUT_FILE_H

#include <stddef.h>

struct preprocessor;

struct pp_input_file {
  int unpoppable_ : 1;
  int have_input_ : 1;
  int input_final_ : 1;

  const void *input_;
  size_t input_size_;
  const char *filename_;

  int (*input_request_fn_)(void *baton, struct pp_input_file *ifile);
  void *baton_;

  /* Callers may allocate extra storage after the struct. */
  char aux_[1];
};

/* Supplies the source bytes for an input file. */
void aex_if_set_input(struct pp_input_file *ifile, const void *input_buf,
                      size_t input_buf_size, int is_final);

#endif /* PP_INPUT_FILE_H */
