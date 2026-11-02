#ifndef CARB_AEX_PPTG_SRCPPPP_TRIGRAPHS_H_INCLUDED
#define CARB_AEX_PPTG_SRCPPPP_TRIGRAPHS_H_INCLUDED

#include <stddef.h> /* size_t */

#ifdef __cplusplus
extern "C" {
  #endif

  struct pptk;
  struct preprocessor;
  struct situs;
  #define _AEX_PPTG_FINISH 0
  #define _AEX_PPTG_MATCH 1
  #define _AEX_PPTG_OVERFLOW 2
  #define _AEX_PPTG_NO_MEMORY 3
  #define _AEX_PPTG_FEED_ME 4
  #define _AEX_PPTG_END_OF_INPUT 5
  #define _AEX_PPTG_SYNTAX_ERROR 6
  #define _AEX_PPTG_LEXICAL_ERROR 7
  #define _AEX_PPTG_INTERNAL_ERROR 8
  
  #define AEX_PPTG_ERROR 3
  #define AEX_PPTG_INPUT_END 4
  
  
  #define M_AEX_PPTG_DEFAULT 1
  
  struct aex_pptg_stack {
    int error_recovery_:1;
    int pending_reset_:1;
    int discard_remaining_actions_:1;
    int slot_1_has_sym_data_:1;
    int slot_1_has_common_data_:1;
    int top_of_stack_has_sym_data_:1;
    int top_of_stack_has_common_data_:1;
    int need_sym_:1;
    int is_final_input_:1;
    int slot_0_has_current_sym_data_:1;
    int slot_0_has_common_data_:1;
    int current_sym_;
    size_t input_size_;
    const char *input_;
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
    struct aex_pptg_sym_data *stack_;
    struct aex_pptg_sym_data *sym_data_;
    struct aex_pptg_sym_data *new_buf_;
    size_t new_buf_num_allocated_;
    size_t new_buf_sym_partial_pos_;
    size_t current_production_length_;
    int current_production_nonterminal_;
    size_t sym_idx_;
    size_t scan_state_;
    size_t current_mode_start_state_;
    size_t match_index_;
    size_t best_match_action_;
    size_t best_match_size_;
    size_t input_index_;
    size_t input_offset_;
    size_t match_buffer_size_;
    size_t match_buffer_size_allocated_;
    /* offset, line and column at the start of match_buffer_ */
    size_t match_offset_;
    int match_line_;
    int match_col_;
    /* offset, line and column at the zero-termination (best_match_size_) of a match 
    * in match_buffer_ (the actual buffer may well be longer.) */
    size_t best_match_offset_;
    int best_match_line_;
    int best_match_col_;
    size_t token_size_;
    char *match_buffer_;
    char terminator_repair_;
    int input_line_;
    int input_col_;
    int sym_grp_;
    char codepoint_[4];
    char *cp_;
  };
  
  void aex_pptg_stack_init(struct aex_pptg_stack *stack);
  void aex_pptg_stack_cleanup(struct aex_pptg_stack *stack);
  int aex_pptg_stack_reset(struct aex_pptg_stack *stack);
  int aex_pptg_stack_can_recover(struct aex_pptg_stack *stack);
  int aex_pptg_stack_accepts(struct aex_pptg_stack *stack, int sym);
  void aex_pptg_set_mode(struct aex_pptg_stack *stack, int mode);
  int aex_pptg_mode(struct aex_pptg_stack *stack);
  void aex_pptg_set_input(struct aex_pptg_stack *stack, const char *input, size_t input_size, int is_final_input);
  int aex_pptg_scan(struct aex_pptg_stack *stack, struct preprocessor *pp, const char *filename, char **output_buf, size_t *output_end, size_t *output_buf_alloc_size, struct situs *output_situs);
  void aex_pptg_set_location(struct aex_pptg_stack *stack, int line, int col, size_t offset);
  const char *aex_pptg_text(struct aex_pptg_stack *stack);
  size_t aex_pptg_len(struct aex_pptg_stack *stack);
  int aex_pptg_line(struct aex_pptg_stack *stack);
  int aex_pptg_column(struct aex_pptg_stack *stack);
  size_t aex_pptg_offset(struct aex_pptg_stack *stack);
  int aex_pptg_endline(struct aex_pptg_stack *stack);
  int aex_pptg_endcolumn(struct aex_pptg_stack *stack);
  size_t aex_pptg_endoffset(struct aex_pptg_stack *stack);
  void *aex_pptg_token_common_data(struct aex_pptg_stack *stack);
  int aex_pptg_lex(struct aex_pptg_stack *stack);
  int aex_pptg_parse(struct aex_pptg_stack *stack, int sym, struct preprocessor *pp, const char *filename, char **output_buf, size_t *output_end, size_t *output_buf_alloc_size, struct situs *output_situs);
  
  #ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* CARB_AEX_PPTG_SRCPPPP_TRIGRAPHS_H_INCLUDED */
