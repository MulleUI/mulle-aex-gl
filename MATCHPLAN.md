# MATCHPLAN: mulle-aex-gl

Status: active
Date: 2026-11-02
Provenance: fork of `https://github.com/kingletbv/aex-gl` merged into a
mulle-sde C library with diverging histories.

## Goal

Turn the `aex-gl` software OpenGL ES 2.0 implementation into
`mulle-aex-gl`, a self-contained, permissively licensed, C-only software
GLES2 backend for MulleUI:

- no Carburetta at build or run time,
- no EGL/X11/Wayland requirement for the headless path,
- buildable on Linux, FreeBSD, macOS, Windows and Android,
- usable as the `CG_GLES2` backend of `MulleCGNanovgGL`,
- able to run user GLSL ES 1.00 shaders and a GLES2 `CAOpenGLLayer`
  surface.

The first deliverable is a Linux headless proof: a MulleCG/nanovg scene
renders through `mulle-aex-gl` with no GL, EGL, OSMesa or GPU.

## Upstream model

- Upstream: `kingletbv/aex-gl`, Apache-2.0, C.
- This project keeps upstream history and the mulle-sde scaffold as
  unrelated histories merged once with `--allow-unrelated-histories`.
- Upstream files are imported as-is. Adaptation happens in follow-up
  commits, so upstream diffs remain reviewable.
- License: keep upstream `LICENSE` and `NOTICE`; document the fork and the
  upstream commit in `UPSTREAM.md`.

## Locked decisions

- **C only.** No C++, no C++ runtime, no LLVM, no Carburetta at build time.
- **Vendored generated parsers.** The seven Carburetta outputs are checked
  in; the `.cbrt` grammars are archived under `grammar/` for provenance but
  are not part of the build.
- **Headless first.** The first target is `aex_gl_es2_context_init`, not
  EGL or a window system.
- **GLES2 surface only for now.** No GL3.2/VAO promise; `CAOpenGLLayer`
  uses its `#version 100` path.
- **Per-backend shaders.** Custom shaders are registered per
  `UIGraphicsBackend`, so a software backend gets GLSL ES 1.00 variants
  instead of pretending to be desktop GL.
- **mulle-core threading.** Use `mulle_thread_mutex_t`,
  `mulle_thread_once_t` and `mulle_thread_tss_t`; one cross-platform
  implementation, no per-platform thread shims.
- **No D3D11 or Skia work in this plan.**

## Phase 0 - Fork and scaffold

1. Create this mulle-sde project with
   `mulle-sde init -m mulle-core/c-developer -n mulle-aex-gl library`.
2. Initialize git on `main` and commit the scaffold plus this matchplan.
3. Add `aex-gl` as a remote, fetch it, and merge it with
   `--allow-unrelated-histories`.
4. Resolve scaffold conflicts in favour of the mulle-sde files
   (`CMakeLists.txt`, `README.md`, `.gitignore`), while importing all
   upstream source directories.
5. Record the upstream commit in `UPSTREAM.md`.

Acceptance: `git log --graph` shows two roots; the tree contains both the
mulle-sde scaffold and upstream `src/`, `renderbmp/`, `3rdparty/`,
`project/`, `docs/`.

## Phase 1 - Remove Carburetta from the build

1. Build Carburetta once from pinned source as a host tool.
   The `carburetta` target is pure C and needs no C++.
2. Generate the seven parser outputs with the same command the upstream
   Visual Studio project used:

   ```
   carburetta <in>.cbrt --c <out>.c --h
   ```

   - `src/glsl_es_1.c/.h`
   - `src/pp/pp_const_expr.c/.h`
   - `src/pp/pp_line_continuations.c/.h`
   - `src/pp/pp_line_directives.c/.h`
   - `src/pp/pp_macro_expander.c/.h`
   - `src/pp/pp_tokenizer.c/.h`
   - `src/pp/pp_trigraphs.c/.h`

3. Check reproducibility: generate twice, diff the outputs, confirm no
   absolute paths, timestamps or Carburetta runtime includes.
4. Commit the generated files. Remove the `.cbrt` custom-build steps from
   `project/Aex.vcxproj` (or replace them with a comment).
5. Move the `.cbrt` files to `grammar/` as reference, not built.
6. Document the Carburetta version and the exact commands in
   `grammar/README.md`.

Acceptance: a fresh clone builds with no Carburetta installed and no
`.cbrt` file in the include or source search path.

## Phase 2 - mulle-core threading and headless build

1. Use mulle-core's portable thread layer instead of raw pthreads:
   - `struct thread_mutex` wraps `mulle_thread_mutex_t`,
   - `thread_context.c` uses `mulle_thread_once_t` and
     `mulle_thread_tss_t`.
   This replaces both the Win32 and POSIX variants with one implementation.
2. Exclude non-library sources from the mulle-sde build:
   `egl_impl.c`, `src/AexGL-DLL/`, `src/tester/`.
3. Make the imported headers self-contained enough for clang:
   forward declarations for shared struct tags, and the missing
   `<limits.h>` / `<stddef.h>` / `<stdint.h>` includes.
4. Wire the core sources into the mulle-sde CMake library build
   (`mulle-sde reflect` after adding files).
5. Add the `m` system library for `libm` (`mulle-sde library add
   --no-header m`).
6. Add a headless smoke test under `test/` that initializes a context,
   clears, and reads back a pixel.

Acceptance: `mulle-sde craft` builds `libmulle-aex-gl` and
`mulle-sde test run` passes the headless clear/readpixels test with no
display, no EGL and no GPU.

## Phase 3 - MulleCG integration spike

1. Provide the GLES2 ABI to `MulleCGNanovgGL`:
   - preferred: a thin `GLES2/gl2.h` plus `gl*` wrappers that dispatch to
     `aex_gl_es2_*`,
   - fallback: reuse upstream's `gl_es2_aex_func_map.c` and bypass GLAD.
2. Build `MulleCGNanovgGL` with `MULLE_CG_GLVERSION=MULLE_CG_GLES2` and a
   new `MULLE_CG_USE_SOFTGLES2` define.
3. Add a demo-local software context adapter so
   `MulleUIOS/demo/src/main-offscreen-cg.m` can use
   `aex_gl_es2_context_init` instead of GLFW/OSMesa.
4. Render a solid rect and a triangle; compare against the OSMesa golden
   images.

Acceptance: a MulleCG/nanovg scene renders through `mulle-aex-gl` on Linux.

## Phase 4 - Evaluate and gate

1. Test nanovg's GLES2 shaders and `CGContext+ImageEffect` custom shaders.
2. Test a GLES2 `CAOpenGLLayer` triangle (`#version 100`, no VAO).
3. Benchmark; aex-gl executes shaders from the AST, without JIT.
4. Record bugs, missing features (no MSAA, no points) and API gaps.
5. Decide whether to continue to the multi-platform port.

Acceptance: a written report with pass/fail per scene, performance numbers
and an effort estimate for the remaining platforms.

## Phase 5 - Portability and productisation

Only after Phase 4 passes:

1. Threading is already handled by mulle-core on Linux, FreeBSD, macOS,
   Windows and Android; validate each target.
2. Add presentation through an FBO blit into `MulleGLFW`/`MulleSDL`, or
   an EGL surfaceless context.
3. Add a `softgles2` sourcetree config for `MulleUIOS` and a
   `mulle-aex-gl` craftinfo.
4. Add the CI matrix: Linux, Windows (mingw/clang), macOS, FreeBSD,
   Android.

Acceptance: the same tests pass on every target with no external GL
runtime.

## Progress (2026-11-02)

Done:

- Phase 0: mulle-sde C library scaffold created; upstream `aex-gl`
  merged as an unrelated-history fork; `MATCHPLAN.md` and `UPSTREAM.md`
  added.
- Phase 1: Carburetta 0.8.29 built once as a host tool; the seven parser
  `.c/.h` pairs were generated and checked in; `.cbrt` grammars moved to
  `grammar/` (not built); `project/Aex.vcxproj` no longer calls
  Carburetta.
- Phase 2: replaced the Win32/POSIX thread split with one mulle-core
  implementation (`src/thread_context.c`, `src/thread_mutex.c`); made the
  imported headers self-contained; excluded `egl_impl.c`,
  `src/AexGL-DLL/` and `src/tester/`; added the `m` system library.
- `mulle-sde craft` builds `libmulle-aex-gl.a`.
- `mulle-sde test run` passes:
  `test/10-first/gles2-headless` initializes a 16x16 context, clears to
  blue and reads back `0,0,255,255`.

Known porting compromises:

- `-Wno-incompatible-pointer-types` is set in `CFLAGS` because the
  imported code mixes `restrict`/`const`-qualified pointer-to-pointer
  types with unqualified ones. Qualifier-only; revisit before productising.
- The vendored generated headers carry local forward declarations
  (`struct pptk`, `struct preprocessor`, `struct situs`,
  `struct glsl_es1_compiler`) for clang. See `grammar/README.md`.

Next:

- Phase 3: wire `MulleCGNanovgGL` with `MULLE_CG_GLVERSION=MULLE_CG_GLES2`
  and render a MulleCG/nanovg scene through `mulle-aex-gl`.

## Risks

| Risk | Mitigation |
|---|---|
| Generated parser snapshot cannot be edited without Carburetta | archive `.cbrt` + pin Carburetta for offline regeneration |
| `MulleCGNanovgGL` uses GLAD today | experiment with the shim first; keep the func-map fallback |
| aex-gl is "under development" | gate at Phase 4; keep upstream diffs small |
| GLES2 only, no VAO/GL3.2 | `CAOpenGLLayer` `#version 100` path; document the limit |
| TLS/default-context semantics vs render thread | test with a dedicated render thread before Phase 5 |
| Apache-2.0 NOTICE/patent terms | ship `LICENSE`/`NOTICE`, record the fork in `UPSTREAM.md` |
| AST interpreter performance | benchmark early; no JIT promise |

## Key paths

- `src/gl_es2_context.c` - `aex_gl_es2_context_init`, framebuffer setup.
- `src/gl_es2_impl.c` - GLES2 entry points and state.
- `src/glsl_es1_compiler.c` - GLSL ES 1.00 compiler entry.
- `src/pp/` - preprocessor; generated parsers live here.
- `src/sl_*`, `src/ir*` - shader IR and execution.
- `src/rasterizer.c`, `src/sampler_2d.c`, `src/blitter.c` - raster path.
- `src/thread_context.c`, `src/thread_mutex.c` - mulle-core thread layer.
- `src/mulle-aex-gl.c`, `src/mulle-aex-gl.h` - mulle-sde envelope.
- `renderbmp/` - headless demos and aex-to-`gl*` name map.
- `project/Aex.vcxproj` - upstream build; Carburetta steps removed.
- `grammar/` - archived `.cbrt` grammars plus regeneration notes.
- `test/10-first/gles2-headless.c` - headless smoke test.

## Commands

With vibecoding enabled and a `test/` folder present, `mulle-sde craft` is
intentionally disabled. Use the test project:

```sh
cd /home/src/srcO/MulleUI/mulle-aex-gl
mulle-sde test craft
mulle-sde test run
mulle-sde check
mulle-sde reflect
mulle-sde log
```

The test project is a separate mulle-sde project; `mulle-sde test init` was
already run. `mulle-sde test run` builds the dependency and runs both the
scaffold `hello` test and the headless `gles2-headless` test.
