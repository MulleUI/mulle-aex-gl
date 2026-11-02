#ifndef CARB_GLSL_ES1_SRCGLSL_ES_1_H_INCLUDED
#define CARB_GLSL_ES1_SRCGLSL_ES_1_H_INCLUDED

#include <stddef.h> /* size_t */

#ifdef __cplusplus
extern "C" {
  #endif

  struct glsl_es1_compiler;
  struct pptk;
  
  #define _GLSL_ES1_FINISH 0
  #define _GLSL_ES1_MATCH 1
  #define _GLSL_ES1_OVERFLOW 2
  #define _GLSL_ES1_NO_MEMORY 3
  #define _GLSL_ES1_FEED_ME 4
  #define _GLSL_ES1_END_OF_INPUT 5
  #define _GLSL_ES1_SYNTAX_ERROR 6
  #define _GLSL_ES1_LEXICAL_ERROR 7
  #define _GLSL_ES1_INTERNAL_ERROR 8
  
  #define GLSL_ES1_ATTRIBUTE 3
  #define GLSL_ES1_CONST 4
  #define GLSL_ES1_BOOL 5
  #define GLSL_ES1_FLOAT 6
  #define GLSL_ES1_INT 7
  #define GLSL_ES1_BREAK 8
  #define GLSL_ES1_CONTINUE 9
  #define GLSL_ES1_DO 10
  #define GLSL_ES1_ELSE 11
  #define GLSL_ES1_FOR 12
  #define GLSL_ES1_IF 13
  #define GLSL_ES1_DISCARD 14
  #define GLSL_ES1_RETURN 15
  #define GLSL_ES1_BVEC2 16
  #define GLSL_ES1_BVEC3 17
  #define GLSL_ES1_BVEC4 18
  #define GLSL_ES1_IVEC2 19
  #define GLSL_ES1_IVEC3 20
  #define GLSL_ES1_IVEC4 21
  #define GLSL_ES1_VEC2 22
  #define GLSL_ES1_VEC3 23
  #define GLSL_ES1_VEC4 24
  #define GLSL_ES1_MAT2 25
  #define GLSL_ES1_MAT3 26
  #define GLSL_ES1_MAT4 27
  #define GLSL_ES1_IN 28
  #define GLSL_ES1_OUT 29
  #define GLSL_ES1_INOUT 30
  #define GLSL_ES1_UNIFORM 31
  #define GLSL_ES1_VARYING 32
  #define GLSL_ES1_SAMPLER2D 33
  #define GLSL_ES1_SAMPLERCUBE 34
  #define GLSL_ES1_STRUCT 35
  #define GLSL_ES1_VOID 36
  #define GLSL_ES1_WHILE 37
  #define GLSL_ES1_IDENTIFIER 38
  #define GLSL_ES1_TYPE_NAME 39
  #define GLSL_ES1_FLOATCONSTANT 40
  #define GLSL_ES1_INTCONSTANT 41
  #define GLSL_ES1_BOOLCONSTANT 42
  #define GLSL_ES1_LEFT_OP 43
  #define GLSL_ES1_RIGHT_OP 44
  #define GLSL_ES1_INC_OP 45
  #define GLSL_ES1_DEC_OP 46
  #define GLSL_ES1_LE_OP 47
  #define GLSL_ES1_GE_OP 48
  #define GLSL_ES1_EQ_OP 49
  #define GLSL_ES1_NE_OP 50
  #define GLSL_ES1_AND_OP 51
  #define GLSL_ES1_OR_OP 52
  #define GLSL_ES1_XOR_OP 53
  #define GLSL_ES1_MUL_ASSIGN 54
  #define GLSL_ES1_DIV_ASSIGN 55
  #define GLSL_ES1_ADD_ASSIGN 56
  #define GLSL_ES1_MOD_ASSIGN 57
  #define GLSL_ES1_LEFT_ASSIGN 58
  #define GLSL_ES1_RIGHT_ASSIGN 59
  #define GLSL_ES1_AND_ASSIGN 60
  #define GLSL_ES1_XOR_ASSIGN 61
  #define GLSL_ES1_OR_ASSIGN 62
  #define GLSL_ES1_SUB_ASSIGN 63
  #define GLSL_ES1_LEFT_PAREN 64
  #define GLSL_ES1_RIGHT_PAREN 65
  #define GLSL_ES1_LEFT_BRACKET 66
  #define GLSL_ES1_RIGHT_BRACKET 67
  #define GLSL_ES1_LEFT_BRACE 68
  #define GLSL_ES1_RIGHT_BRACE 69
  #define GLSL_ES1_DOT 70
  #define GLSL_ES1_COMMA 71
  #define GLSL_ES1_COLON 72
  #define GLSL_ES1_SEMICOLON 73
  #define GLSL_ES1_EQUAL 74
  #define GLSL_ES1_BANG 75
  #define GLSL_ES1_DASH 76
  #define GLSL_ES1_TILDE 77
  #define GLSL_ES1_PLUS 78
  #define GLSL_ES1_STAR 79
  #define GLSL_ES1_SLASH 80
  #define GLSL_ES1_PERCENT 81
  #define GLSL_ES1_LEFT_ANGLE 82
  #define GLSL_ES1_RIGHT_ANGLE 83
  #define GLSL_ES1_VERTICAL_BAR 84
  #define GLSL_ES1_CARET 85
  #define GLSL_ES1_AMPERSAND 86
  #define GLSL_ES1_QUESTION 87
  #define GLSL_ES1_INVARIANT 88
  #define GLSL_ES1_HIGH_PRECISION 89
  #define GLSL_ES1_MEDIUM_PRECISION 90
  #define GLSL_ES1_LOW_PRECISION 91
  #define GLSL_ES1_PRECISION 92
  #define GLSL_ES1_OTHER 93
  #define GLSL_ES1_WHITESPACE 94
  #define GLSL_ES1_ERROR 95
  #define GLSL_ES1_INPUT_END 96
  
  #define GLSL_ES1_PRIMARY_EXPRESSION 97
  #define GLSL_ES1_POSTFIX_EXPRESSION 98
  #define GLSL_ES1_INTEGER_EXPRESSION 99
  #define GLSL_ES1_FUNCTION_CALL 100
  #define GLSL_ES1_FUNCTION_CALL_GENERIC 101
  #define GLSL_ES1_FUNCTION_CALL_HEADER_NO_PARAMETERS 102
  #define GLSL_ES1_FUNCTION_CALL_HEADER_WITH_PARAMETERS 103
  #define GLSL_ES1_FUNCTION_CALL_HEADER 104
  #define GLSL_ES1_FUNCTION_IDENTIFIER 105
  #define GLSL_ES1_CONSTRUCTOR_IDENTIFIER 106
  #define GLSL_ES1_UNARY_EXPRESSION 107
  #define GLSL_ES1_UNARY_OPERATOR 108
  #define GLSL_ES1_MULTIPLICATIVE_EXPRESSION 109
  #define GLSL_ES1_ADDITIVE_EXPRESSION 110
  #define GLSL_ES1_SHIFT_EXPRESSION 111
  #define GLSL_ES1_RELATIONAL_EXPRESSION 112
  #define GLSL_ES1_EQUALITY_EXPRESSION 113
  #define GLSL_ES1_AND_EXPRESSION 114
  #define GLSL_ES1_EXCLUSIVE_OR_EXPRESSION 115
  #define GLSL_ES1_INCLUSIVE_OR_EXPRESSION 116
  #define GLSL_ES1_LOGICAL_AND_EXPRESSION 117
  #define GLSL_ES1_LOGICAL_XOR_EXPRESSION 118
  #define GLSL_ES1_LOGICAL_OR_EXPRESSION 119
  #define GLSL_ES1_CONDITIONAL_EXPRESSION 120
  #define GLSL_ES1_ASSIGNMENT_EXPRESSION 121
  #define GLSL_ES1_ASSIGNMENT_OPERATOR 122
  #define GLSL_ES1_EXPRESSION 123
  #define GLSL_ES1_CONSTANT_EXPRESSION 124
  #define GLSL_ES1_DECLARATION 125
  #define GLSL_ES1_FUNCTION_PROTOTYPE_DECL 126
  #define GLSL_ES1_FUNCTION_PROTOTYPE 127
  #define GLSL_ES1_FUNCTION_DECLARATOR 128
  #define GLSL_ES1_FUNCTION_HEADER_WITH_PARAMETERS 129
  #define GLSL_ES1_FUNCTION_HEADER 130
  #define GLSL_ES1_PARAMETER_DECLARATOR 131
  #define GLSL_ES1_PARAMETER_DECLARATION 132
  #define GLSL_ES1_PARAMETER_QUALIFIER 133
  #define GLSL_ES1_PARAMETER_TYPE_SPECIFIER 134
  #define GLSL_ES1_INIT_DECLARATOR_LIST 135
  #define GLSL_ES1_SINGLE_DECLARATION 136
  #define GLSL_ES1_FULLY_SPECIFIED_TYPE 137
  #define GLSL_ES1_TYPE_QUALIFIER 138
  #define GLSL_ES1_TYPE_SPECIFIER 139
  #define GLSL_ES1_TYPE_SPECIFIER_NO_PREC 140
  #define GLSL_ES1_PRECISION_QUALIFIER 141
  #define GLSL_ES1_STRUCT_SPECIFIER 142
  #define GLSL_ES1_STRUCT_DECLARATION_LIST 143
  #define GLSL_ES1_STRUCT_DECLARATION 144
  #define GLSL_ES1_STRUCT_DECLARATOR_LIST 145
  #define GLSL_ES1_STRUCT_DECLARATOR 146
  #define GLSL_ES1_INITIALIZER 147
  #define GLSL_ES1_DECLARATION_STATEMENT 148
  #define GLSL_ES1_STATEMENT_NO_NEW_SCOPE 149
  #define GLSL_ES1_SIMPLE_STATEMENT 150
  #define GLSL_ES1_COMPOUND_STATEMENT_WITH_SCOPE 151
  #define GLSL_ES1_STATEMENT_WITH_SCOPE 152
  #define GLSL_ES1_COMPOUND_STATEMENT_NO_NEW_SCOPE 153
  #define GLSL_ES1_STATEMENT_LIST 154
  #define GLSL_ES1_EXPRESSION_STATEMENT 155
  #define GLSL_ES1_SELECTION_STATEMENT 156
  #define GLSL_ES1_SELECTION_REST_STATEMENT 157
  #define GLSL_ES1_CONDITION 158
  #define GLSL_ES1_ITERATION_STATEMENT 159
  #define GLSL_ES1_FOR_INIT_STATEMENT 160
  #define GLSL_ES1_FOR_REST_STATEMENT 161
  #define GLSL_ES1_JUMP_STATEMENT 162
  #define GLSL_ES1_TRANSLATION_UNIT 163
  #define GLSL_ES1_EXTERNAL_DECLARATION 164
  #define GLSL_ES1_FUNCTION_DEFINITION 165
  #define GLSL_ES1_START_SCOPE 166
  #define GLSL_ES1_FUNCTION_DEFINITION_SETUP 167
  #define GLSL_ES1_GRAMMAR 168
  
  
  struct glsl_es1_stack {
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
    struct glsl_es1_sym_data *stack_;
    struct glsl_es1_sym_data *sym_data_;
    struct glsl_es1_sym_data *new_buf_;
    size_t new_buf_num_allocated_;
    size_t new_buf_sym_partial_pos_;
    size_t current_production_length_;
    int current_production_nonterminal_;
    size_t sym_idx_;
  };
  
  void glsl_es1_stack_init(struct glsl_es1_stack *stack);
  void glsl_es1_stack_cleanup(struct glsl_es1_stack *stack);
  int glsl_es1_stack_reset(struct glsl_es1_stack *stack);
  int glsl_es1_stack_can_recover(struct glsl_es1_stack *stack);
  int glsl_es1_stack_accepts(struct glsl_es1_stack *stack, int sym);
  int glsl_es1_parse(struct glsl_es1_stack *stack, int sym, struct glsl_es1_compiler *cc, struct pptk *input_chain);
  
  #ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* CARB_GLSL_ES1_SRCGLSL_ES_1_H_INCLUDED */
