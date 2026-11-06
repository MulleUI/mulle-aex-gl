# GLSL tests

These tests compile GLSL ES 1.00 shader sources through the public GLES2 API
(`aex_gl_es2_ShaderSource` / `aex_gl_es2_CompileShader` /
`aex_gl_es2_GetShaderInfoLog`) and compare deterministic output.

## Files

| File | Purpose |
|---|---|
| `glsl-accept.c` | Shaders that must compile. |
| `glsl-reject.c` | Shaders that must fail, with diagnostic category and line checks. |
| `glsl-preprocessor.c` | Preprocessor directives, macros, conditionals. |
| `glsl-ir.c` | Debug-shader execution: compiles, links, runs, and compares `dump()` output. |
| `glsl-diagnostics.c` | Golden diagnostics for representative errors. |
| `glsl-test.h` | Shared compile/log/assert helpers. |

Run one test:

```sh
mulle-sde test run test/80-glsl/glsl-accept.c
```

## GAP convention

A case marked `gap_` is a known missing or broken behavior. It is executed but
reported as `GAP` instead of `OK`/`FAIL`, so the suite stays green while the
gap is visible. When a gap is fixed:

1. clear `gap_` on the case,
2. change `GAP` to `OK` in the corresponding `.stdout`,
3. update the summary counts.

The `.stdout` files are exact-match goldens. Failed cases print diagnostics to
stderr only, so the goldens remain stable.

## Debug-shader output

`glsl-ir.c` uses `AEX_GL_DEBUG_SHADER`, links a program, calls
`aex_gl_es2_run_debug_shader`, and compares
`aex_gl_es2_get_shader_debug_string`. This exercises parsing, semantics, and
execution rather than just compile status.

## Known gaps

See [GAPS.md](GAPS.md).
