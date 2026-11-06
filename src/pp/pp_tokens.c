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

#include <stdlib.h>
#include <string.h>

#include "pp_tokens.h"
#include "diags.h"
#include "pp.h"

struct pptk *aex_pptk_alloc_len(struct preprocessor *pp,
                                 struct pptk **pp_chain,
                                 const char *text, size_t text_len, int sym,
                                 struct situs *psit) {
  struct pptk *tk;

  tk = (struct pptk *) calloc(1, sizeof(*tk));
  if (!tk) {
    dx_no_memory(pp->dx_);
    return NULL;
  }
  tk->next_ = tk->prev_ = tk;
  tk->tok_ = (enum pptoken) sym;
  tk->text_len_ = text_len;
  tk->text_ = (char *) malloc(text_len + 1);
  if (!tk->text_) {
    free(tk);
    dx_no_memory(pp->dx_);
    return NULL;
  }
  if (text_len) {
    memcpy(tk->text_, text, text_len);
  }
  tk->text_[text_len] = '\0';
  aex_situs_init(&tk->situs_);
  if (aex_situs_clone(&tk->situs_, psit)) {
    free(tk->text_);
    free(tk);
    dx_no_memory(pp->dx_);
    return NULL;
  }

  if (pp_chain) {
    *pp_chain = aex_pptk_join(*pp_chain, tk);
  }
  return tk;
}

struct pptk *aex_pptk_alloc(struct preprocessor *pp, struct pptk **pp_chain,
                            const char *text, int sym, struct situs *psit) {
  return aex_pptk_alloc_len(pp, pp_chain, text, strlen(text), sym, psit);
}

void aex_pptk_free(struct pptk *tk_chain) {
  struct pptk *tk;
  struct pptk *next;

  tk = tk_chain;
  if (!tk) {
    return;
  }
  next = tk->next_;
  do {
    tk = next;
    next = tk->next_;

    free(tk->text_);
    if (tk->tok_ == PPTK_STRING_LIT) {
      free(tk->v_.string_.data_);
    }
    aex_situs_cleanup(&tk->situs_);
    free(tk);
  } while (tk != tk_chain);
}

struct pptk *aex_pptk_join(struct pptk *front, struct pptk *back) {
  struct pptk *front_head;
  struct pptk *front_tail;
  struct pptk *back_head;
  struct pptk *back_tail;

  if (!back) return front;
  if (!front) return back;

  front_head = front;
  front_tail = front->prev_;
  back_head = back;
  back_tail = back->prev_;

  back_tail->next_ = front_head;
  front_head->prev_ = back_tail;

  front_tail->next_ = back_head;
  back_head->prev_ = front_tail;

  return front_head;
}

struct pptk *aex_pptk_pop_front(struct pptk **pp_chain) {
  struct pptk *front;

  if (!*pp_chain) return NULL;
  front = *pp_chain;
  if (front->next_ != front) {
    *pp_chain = front->next_;
    front->next_->prev_ = front->prev_;
    front->prev_->next_ = front->next_;
  }
  else {
    *pp_chain = NULL;
  }
  front->next_ = front->prev_ = front;
  return front;
}

struct pptk *aex_pptk_pop_back(struct pptk **pp_chain) {
  struct pptk *back;

  if (!*pp_chain) return NULL;
  back = (*pp_chain)->prev_;
  if (back == *pp_chain) {
    *pp_chain = NULL;
  }
  else {
    back->next_->prev_ = back->prev_;
    back->prev_->next_ = back->next_;
  }
  back->next_ = back->prev_ = back;
  return back;
}
