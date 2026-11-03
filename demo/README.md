# mulle-aex-gl SDL3 demo

A spinning GLES2 triangle rendered entirely by `mulle-aex-gl` and presented
through an SDL3 software window surface. There is no GL, EGL, or GPU context:
`aex_gl_es2_context_init` owns the framebuffer, `glReadPixels` copies it out,
and SDL converts/blob-copies the RGBA pixels into the window surface.

The demo is a `mulle-project-demo` project. It compiles the parent library
sources directly, so changes in `mulle-aex-gl/src` are picked up without
installing the library first.

## Build and run

From the `mulle-aex-gl` directory:

``` sh
mulle-sde -d demo craft
mulle-sde -d demo run sdl3-triangle
```

Close with Escape or the window close button.

The SDL3 dependency is `release-3.2.0` and is built from
`https://github.com/libsdl-org/SDL/archive/release-3.2.0.tar.gz` with the
`SDL-craftinfo` copied from `MulleSDL`.

## Headless verification

Run under Xvfb with a short timeout:

``` sh
xvfb-run -a mulle-sde -d demo run --timeout 2 sdl3-triangle
```

`mulle-sde` returns 124 for the intentional timeout. The demo was also
captured under Xvfb with ImageMagick `import`; the resulting frame contained
the three triangle vertex colors on the dark clear color.

The window is 800x600. The source is `src/main-sdl3-triangle.c`.
