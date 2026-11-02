#ifndef CARB_AEX_PPLD_SRCPPPP_LINE_DIRECTIVES_H_INCLUDED
#define CARB_AEX_PPLD_SRCPPPP_LINE_DIRECTIVES_H_INCLUDED

#include <stddef.h> /* size_t */

#ifdef __cplusplus
extern "C" {
  #endif

  struct pptk;
  struct preprocessor;
  struct situs;
  #define _AEX_PPLD_FINISH 0
  #define _AEX_PPLD_MATCH 1
  #define _AEX_PPLD_OVERFLOW 2
  #define _AEX_PPLD_NO_MEMORY 3
  #define _AEX_PPLD_FEED_ME 4
  #define _AEX_PPLD_END_OF_INPUT 5
  #define _AEX_PPLD_SYNTAX_ERROR 6
  #define _AEX_PPLD_LEXICAL_ERROR 7
  #define _AEX_PPLD_INTERNAL_ERROR 8
  
  #define AEX_PPLD_HASH_TOK 3
  #define AEX_PPLD_IF_TOK 4
  #define AEX_PPLD_IFDEF_TOK 5
  #define AEX_PPLD_IFNDEF_TOK 6
  #define AEX_PPLD_ELIF_TOK 7
  #define AEX_PPLD_ELSE_TOK 8
  #define AEX_PPLD_ENDIF_TOK 9
  #define AEX_PPLD_INCLUDE_TOK 10
  #define AEX_PPLD_DEFINE_TOK 11
  #define AEX_PPLD_UNDEF_TOK 12
  #define AEX_PPLD_LINE_TOK 13
  #define AEX_PPLD_ERROR_TOK 14
  #define AEX_PPLD_PRAGMA_TOK 15
  #define AEX_PPLD_PAR_OPEN_TOK 16
  #define AEX_PPLD_PAR_CLOSE_TOK 17
  #define AEX_PPLD_ELLIPSIS_TOK 18
  #define AEX_PPLD_COMMA_TOK 19
  #define AEX_PPLD_WS_TOK 20
  #define AEX_PPLD_NEWLINE_TOK 21
  #define AEX_PPLD_IDENTIFIER_TOK 22
  #define AEX_PPLD_OTHER_TOK 23
  #define AEX_PPLD_HEADER_NAME 24
  #define AEX_PPLD_VERSION_TOK 25
  #define AEX_PPLD_ERROR 26
  #define AEX_PPLD_INPUT_END 27
  
  #define AEX_PPLD_NON_DIRECTIVE 28
  #define AEX_PPLD_PP_TOKENS 29
  #define AEX_PPLD_PP_TOKENS_OPT 30
  #define AEX_PPLD_REPLACEMENT_LIST 31
  #define AEX_PPLD_PREPROCESSING_TOKEN 32
  #define AEX_PPLD_IDENTIFIER_LIST 33
  #define AEX_PPLD_IDENTIFIER_LIST_OPT 34
  #define AEX_PPLD_NON_DIR_TOKEN 35
  #define AEX_PPLD_NON_PAR_OPEN_TOKEN 36
  #define AEX_PPLD_NON_PAR_OPEN_REPLACEMENT_LIST 37
  #define AEX_PPLD_NON_HASH_PP_TOKENS 38
  #define AEX_PPLD_NON_HASH_PP_TOKENS_OPT 39
  #define AEX_PPLD_NON_HASH_TOKEN 40
  #define AEX_PPLD_PP_LINE 41
  #define AEX_PPLD_WS 42
  #define AEX_PPLD_WS_OPT 43
  #define AEX_PPLD_NEWLINE 44
  #define AEX_PPLD_NEWLINE_OPT 45
  #define AEX_PPLD_HASH 46
  #define AEX_PPLD_IF 47
  #define AEX_PPLD_IFDEF 48
  #define AEX_PPLD_IFNDEF 49
  #define AEX_PPLD_ELIF 50
  #define AEX_PPLD_ELSE 51
  #define AEX_PPLD_ENDIF 52
  #define AEX_PPLD_INCLUDE 53
  #define AEX_PPLD_DEFINE 54
  #define AEX_PPLD_UNDEF 55
  #define AEX_PPLD_LINE 56
  #define AEX_PPLD_ERROR_NT 57
  #define AEX_PPLD_PRAGMA 58
  #define AEX_PPLD_IDENTIFIER 59
  #define AEX_PPLD_IDENT 60
  #define AEX_PPLD_PAR_CLOSE 61
  #define AEX_PPLD_COMMA 62
  #define AEX_PPLD_ELLIPSIS 63
  #define AEX_PPLD_HEADER_PP_TOKENS 64
  #define AEX_PPLD_HDR_PREPROCESSING_TOKEN 65
  #define AEX_PPLD_VERSION 66
  
  
  struct aex_ppld_stack {
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
    struct aex_ppld_sym_data *stack_;
    struct aex_ppld_sym_data *sym_data_;
    struct aex_ppld_sym_data *new_buf_;
    size_t new_buf_num_allocated_;
    size_t new_buf_sym_partial_pos_;
    size_t current_production_length_;
    int current_production_nonterminal_;
    size_t sym_idx_;
  };
  
  void aex_ppld_stack_init(struct aex_ppld_stack *stack);
  void aex_ppld_stack_cleanup(struct aex_ppld_stack *stack);
  int aex_ppld_stack_reset(struct aex_ppld_stack *stack);
  int aex_ppld_stack_can_recover(struct aex_ppld_stack *stack);
  int aex_ppld_stack_accepts(struct aex_ppld_stack *stack, int sym);
  int aex_ppld_parse(struct aex_ppld_stack *stack, int sym, struct preprocessor *pp, struct pptk **pp_current, struct pptk **pp_input_chain, int is_final, struct pptk **pp_output_chain);
  
  #ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* CARB_AEX_PPLD_SRCPPPP_LINE_DIRECTIVES_H_INCLUDED */
