# GLSL conformance notes

There are currently no known gaps. Every case in the accept, reject, IR,
diagnostics, and preprocessor suites is expected to pass without a `GAP`
marker. This file records deliberate policy decisions and fixes so they are
not accidentally undone.

## Deliberate behavior

- Array constructors are rejected with a specific diagnostic. GLSL ES 1.00 has
  no array constructors (only scalar, vector/matrix, and structure
  constructors).
- Variadic macros, stringize (`#`), and token paste (`##`) are rejected.
  GLSL ES 1.00 has no number-sign based preprocessor operators.
- `#version 300 es` is rejected; only version 100 is supported.

## Fixed by the recursive descent parser

- Ternary `?:` now compiles and validates; the old grammar passed
  `exop_logical_or` instead of `exop_conditional`.
- Structure fields are attached to the struct type (`t->fields_` was missing in
  the first port), so field selection works.
- Function calls with an invalid argument no longer crash; the error is
  reported and the call expression becomes NULL.
- `#line` is applied before the next line is tokenized, so token, parser, and
  semantic diagnostics use the adjusted line.
- Errors inside a macro expansion are reported at the invocation site rather
  than at the `#define`.
- `#include` reports a clear "not supported" diagnostic at the directive line
  instead of an internal error.
- Semantic errors now affect `GL_COMPILE_STATUS`: `main` signature errors,
  recursion, constant array subscript out of bounds, and preprocessor
  constant-expression errors.
- `break`/`continue` outside a loop, `return value` in a `void` function,
  `void` variables/parameters, and `discard` in a vertex shader are rejected
  with correct line numbers.
- `#version` must appear before any other non-comment content; an unterminated
  `#if` is reported at the `#if` line.
- Structure constructors are implemented end to end (parser, register
  allocation, IR, execution); arguments are matched to fields in declaration
  order.
- Non-void functions that can fall through are rejected (`missing-return`).
  The analysis is conservative around loops, so it may miss some paths but
  does not reject valid infinite loops.
- Fragment float/vector/matrix variable declarations without a precision
  qualifier are rejected unless a default float precision was declared first
  (`precision-missing-fragment`). The check currently covers variable
  declarations; function return/parameter precision is not checked.
- GLSL ES 1.00 predefined macros are seeded before user source: `GL_ES` is
  `1`, `__VERSION__` is `100`, and `GL_FRAGMENT_PRECISION_HIGH` is `1` for
  fragment shaders. Standard `#ifdef GL_ES` precision guards therefore work.
- Variadic macros, `#`, and `##` are rejected at the `#define` line.
