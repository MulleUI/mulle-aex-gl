#ifndef CARB_AEX_PPCE_SRCPPPP_CONST_EXPR_H_INCLUDED
#define CARB_AEX_PPCE_SRCPPPP_CONST_EXPR_H_INCLUDED

#include <stddef.h> /* size_t */

#ifdef __cplusplus
extern "C" {
  #endif

  struct pptk;
  struct preprocessor;
  struct situs;
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
  
  void aex_ppce_stack_init(struct aex_ppce_stack *stack);
  void aex_ppce_stack_cleanup(struct aex_ppce_stack *stack);
  int aex_ppce_stack_reset(struct aex_ppce_stack *stack);
  int aex_ppce_stack_can_recover(struct aex_ppce_stack *stack);
  int aex_ppce_stack_accepts(struct aex_ppce_stack *stack, int sym);
  int aex_ppce_parse(struct aex_ppce_stack *stack, int sym, struct preprocessor *pp, struct pptk **pp_current_tk, struct pptk *input_chain, int is_final, int64_t *presult, int *pis_unsigned);
  
  #ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* CARB_AEX_PPCE_SRCPPPP_CONST_EXPR_H_INCLUDED */
