# GLSL ES 1.00 compiler does not predefine GL_ES (and other builtin macros)

## Summary

`mulle-aex-gl` compiles GLSL with its own GLSL ES 1.00 front end
(`src/glsl_es1_compiler.c`, `src/glsl_es_1.c`). Unlike a real GLES2 driver's
compiler, it does not predefine the builtin preprocessor macros required by
the GLSL ES 1.00 specification:

- `GL_ES` (must be defined to `1`)
- `__VERSION__` (must be `100` for `#version 100`)
- `GL_FRAGMENT_PRECISION_HIGH` (must be defined when `highp` is supported in
  fragment shaders)

Because `GL_ES` is not defined, shaders that guard their default float
precision with `#ifdef GL_ES` never emit the required
`precision ... float;` declaration. The fragment shader then fails to compile
with errors like:

```
fragment-shader(41): No precision specified for "ftcoord"; declare a default float precision or use a precision qualifier
fragment-shader(42): No precision specified for "fpos"; ...
```

This breaks otherwise-correct ES 1.00 shaders such as NanoVG's, which rely on
the standard `#ifdef GL_ES` precision guard.

## Environment

- `mulle-aex-gl` (workspace checkout), Linux 64-bit, headless
- consumer: `MulleUIOS` with the `aex-gl` configuration,
  `MulleCGNanovgGL` built with `MULLE_CG_GLVERSION=2` and
  `MULLE_CG_USE_AEX_GL=1`
- `AppKit` nib demo (`nibapp`) via `mulle-sde run`

## Reproduction

```sh
cd AppKit/demo
mulle-sde config dependency set MulleUIOS aex-gl
mulle-sde clean tidy && mulle-sde reflect && mulle-sde craft
mulle-sde run nibapp --timeout 60 -- --script selftest.txt
```

Result:

```
Shader shader/frag error:
fragment-shader(41): No precision specified for "ftcoord"; declare a default float precision or use a precision qualifier
fragment-shader(42): No precision specified for "fpos"; ...
fragment-shader(61): No precision specified for "ext2"; ...
fragment-shader(62): No precision specified for "d"; ...
nanovg: shader creation failed (AA)
nvgCreateInternal: renderCreate failed
nibapp: .../MulleCGNanovgGL/src/CGContext+nanovg-gl.m:167:
-[CGContext(nanovgGLInit) _initNanovg]: Assertion `_cgBackend.context' failed.
```

## Root cause

In `src/glsl_es1_compiler.c`, `glsl_es1_compiler_init()` calls `pp_init()`
and nothing else:

```c
void glsl_es1_compiler_init(struct glsl_es1_compiler *cc) {
  dx_diags_init(&cc->default_dx_);
  cc->dx_ = &cc->default_dx_;
  pp_init(&cc->pp_);
  ...
}
```

No builtin macros are seeded into the preprocessor. A grep for `GL_ES`,
`__VERSION__`, or `GL_FRAGMENT_PRECISION_HIGH` across `src/*.c`/`src/*.h`
finds no definitions.

`sl_shader_compile()` (`src/sl_shader.c:157`) then feeds a set of "builtin
prologue" declarations (gl_Max* constants, gl_DepthRange, gl_Position, and
the built-in function prototypes) through
`glsl_es1_compile_builtin_prologue()`, but never defines the standard
preprocessor macros. So `#ifdef GL_ES` is false and the shader's
`precision mediump float;` line is preprocessed out.

NanoVG's fill fragment shader (`mulle-nanovg/nanovg_gl.h`) relies on this:

```c
static const char* fillFragShader =
    "#ifdef GL_ES\n"
    "#if defined(GL_FRAGMENT_PRECISION_HIGH) || defined(NANOVG_GL3)\n"
    " precision highp float;\n"
    "#else\n"
    " precision mediump float;\n"
    "#endif\n"
    "#endif\n"
    ...
```

With `GL_ES` undefined the whole precision block disappears, and the fragment
shader declares `varying vec2 ftcoord;` / local float variables with no
default float precision, which is a hard error in GLSL ES 1.00 fragment
shaders (`fragment_default_float_precision_` stays 0, see
`glsl_es_1.c:2672` and `:2942`).

## Expected behavior

After `#version 100` the compiler must present the following predefined
macros to the shader source, as mandated by the GLSL ES 1.00 specification:

| Macro                        | Value | Condition                          |
|------------------------------|-------|------------------------------------|
| `GL_ES`                      | `1`   | always (this is a GLES compiler)   |
| `__VERSION__`                | `100` | for `#version 100`                 |
| `GL_FRAGMENT_PRECISION_HIGH` | `1`   | in fragment shaders when highp is supported |

With `GL_ES` defined, NanoVG's `precision mediump float;` (or `highp`) is
compiled and the shader links.

## Suggested fixes

1. Seed the standard macros after `pp_init()` in
   `glsl_es1_compiler_init()` (or in `sl_shader_compile()` before compiling
   the user source), e.g. via the preprocessor's define API or an initial
   `#define GL_ES 1\n#define __VERSION__ 100\n` snippet.
2. Define `GL_FRAGMENT_PRECISION_HIGH` for fragment shaders if this compiler
   supports `highp` (it parses the `highp` qualifier, so it should).
3. Add a regression test that compiles a minimal GLSL ES 1.00 fragment shader
   using the standard guard and verifies it compiles:

   ```glsl
   #version 100
   #ifdef GL_ES
   precision mediump float;
   #endif
   varying vec2 v;
   void main(void) { gl_FragColor = vec4(v, 0.0, 1.0); }
   ```

   and a variant relying solely on `#ifdef GL_ES` for the default precision.

## Notes

- Vertex shaders are unaffected because GLSL ES 1.00 gives them a default
  `highp float`; only fragment shaders require an explicit/predefined float
  precision, which is exactly what the `#ifdef GL_ES` guard supplies.
- This is a distinct issue from the `AexOSWindow -haveGraphicsContext`
  crash (see `MulleUIOS/BUGREPORT-AexOSWindow-missing-haveGraphicsContext.md`);
  that crash is fixed and this shader failure is the next blocker on the
  same `aex-gl` headless path.

## Reply (2026-11-04)

Confirmed valid. Two regression cases in `test/80-glsl/glsl-accept.c` failed
before the fix with the reported `No precision specified for "v"` diagnostic:

- `fragment-gl-es-precision` uses the exact `#ifdef GL_ES` guard around
  `precision mediump float;`.
- `fragment-predefined-macros` checks `__VERSION__ == 100`, `GL_ES`, and
  `GL_FRAGMENT_PRECISION_HIGH`.

Fix:

- `GL_ES=1` and `__VERSION__=100` are seeded in `glsl_es1_compiler_init()`.
- `GL_FRAGMENT_PRECISION_HIGH=1` is defined for fragment shaders in
  `sl_shader_compile()`.
- A shared `glsl_es1_compiler_define_macro()` helper creates the macros.

Why this was missed: the existing fragment tests always declared precision
explicitly and never used the standard `#ifdef GL_ES` guard, and no test
compiled NanoVG's real shader. The earlier Aex render tests used shaders that
did not depend on that guard, so the gap only appeared with a real consumer.

Verification: `glsl-accept` passes 37/37, the full `mulle-aex-gl` suite passes
13/13, and `mulle-sde check` is clean.
