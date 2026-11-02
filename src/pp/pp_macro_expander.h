#ifndef CARB_AEX_PPME_SRCPPPP_MACRO_EXPANDER_H_INCLUDED
#define CARB_AEX_PPME_SRCPPPP_MACRO_EXPANDER_H_INCLUDED

#include <stddef.h> /* size_t */

#ifdef __cplusplus
extern "C" {
  #endif

  struct pptk;
  struct preprocessor;
  struct situs;
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
  
  void aex_ppme_stack_init(struct aex_ppme_stack *stack);
  void aex_ppme_stack_cleanup(struct aex_ppme_stack *stack);
  int aex_ppme_stack_reset(struct aex_ppme_stack *stack);
  int aex_ppme_stack_can_recover(struct aex_ppme_stack *stack);
  int aex_ppme_stack_accepts(struct aex_ppme_stack *stack, int sym);
  int aex_ppme_parse(struct aex_ppme_stack *stack, int sym, struct preprocessor *pp, struct pptk **pp_input_chain, int is_final, struct pptk **pp_output_chain, int keep_defined);
  
  #ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* CARB_AEX_PPME_SRCPPPP_MACRO_EXPANDER_H_INCLUDED */
