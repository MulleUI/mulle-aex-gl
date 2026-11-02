# mulle-aex-gl

`mulle-aex-gl` is a [mulle-sde](//github.com/mulle-sde) C library fork of
[Aex-GL](https://github.com/kingletbv/aex-gl), a dependency-free software
implementation of OpenGL ES 2.0.

The purpose of the fork is to provide MulleUI with a self-contained software
GLES2 backend for headless rendering, without Carburetta at build or run time
and without EGL, X11, Wayland or a GPU.

- upstream: `kingletbv/aex-gl`, Apache-2.0
- fork base: see [UPSTREAM.md](UPSTREAM.md)
- plan: [MATCHPLAN.md](MATCHPLAN.md)

## Status

This is a work in progress. The imported upstream sources are still in their
original layout; the mulle-sde build integration and the Carburetta-generated
parsers are being added.

Upstream implements:

- vertex and fragment shader compilation and execution at GLSL ES 1.00 level,
- 32-bit RGBA framebuffer,
- 16-bit stencil buffering,
- 16- and 32-bit depth buffering,
- all blending modes,
- lines and triangles,
- `dFdx()`, `dFdy()` and `fwidth()`.

Missing upstream: points and MSAA.

## Build

This is a [mulle-sde](//github.com/mulle-sde) project. mulle-sde combines
recursive package management with cross-platform builds via **cmake**:

| Action  | Command                               | Description               |
|---------|---------------------------------------|---------------------------|
| Build   | `mulle-sde craft [--release/--debug]` | Builds into local `kitchen` folder |
| Check   | `mulle-sde check`                     | Fast syntax check |
| Reflect | `mulle-sde reflect`                   | Regenerate CMake file lists |

The headless smoke test is `renderbmp`, which renders the upstream demos into
BMP files without a display server.

## License

Apache License 2.0. See [LICENSE](LICENSE). This fork preserves the upstream
license and attribution.
