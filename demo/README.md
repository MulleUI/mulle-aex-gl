# mulle-aex-gl SDL3 demos

GLES2 scenes rendered entirely by `mulle-aex-gl` and presented through an SDL3
software window surface. There is no GL, EGL, or GPU context:
`aex_gl_es2_context_init` owns the framebuffer, `glReadPixels` copies it out,
and SDL converts/blob-copies the RGBA pixels into the window surface.

The demos are a `mulle-project-demo` project. It compiles the parent library
sources directly, so changes in `mulle-aex-gl/src` are picked up without
installing the library first.

## Build and run

From the `mulle-aex-gl` directory:

``` sh
mulle-sde -d demo craft
mulle-sde -d demo run sdl3-triangle
```

Available scenes:

| Demo            | Source                       | Scene                                      |
| --------------- | ---------------------------- | ------------------------------------------ |
| `sdl3-triangle` | `src/main-sdl3-triangle.c`   | Spinning triangle                          |
| `coverage`      | `src/main-coverage.c`        | Triangle coverage grid                     |
| `lines`         | `src/main-lines.c`           | Sixteen colored line segments              |
| `z-triangles`   | `src/main-z-triangles.c`     | Depth-tested triangles                     |
| `mipmap`        | `src/main-mipmap.c`          | Trilinear mipmapped smiley triangle        |
| `world`         | `src/main-world.c`           | Rotating “World is Yours” line globe       |
| `pixi-filters`  | `src/main-pixi-filters.c`    | CRT, glitch, zoom blur, shockwave, ASCII   |

Close with Escape or the window close button. Every demo shows an FPS counter
in the top-left corner, updated every 500 ms. `pixi-filters` cycles through its
five PixiJS-derived filters every four seconds; keys `1`–`5` select one
directly, and `--filter N` pins one for headless capture. `--time SECONDS`
freezes the animation, and `--dump-scene PATH` writes the unfiltered 256x256
input as a BMP without opening a window.

PixiJS filter shaders are adapted from https://github.com/pixijs/filters
under the MIT license; see `LICENSES/PixiJS-Filters.txt`. The glitch filter
uses a `keep` multiplier for transparent fill instead of `discard` or an early
`return`; the AEX shader path mishandles those inside this branch and produces
black scanlines.

## Original PixiJS comparison

`compare/pixi-filters.html` runs the original `pixi-filters` shaders in a
browser as a visual reference. Generate the shared scene once, then serve the
comparison directory:

``` sh
mulle-sde -d demo run pixi-filters --dump-scene compare/pixi-scene.bmp
python3 -m http.server 8000 -d compare
```

Open `http://localhost:8000/pixi-filters.html?filter=crt&time=0.5`. `filter`
accepts `crt`, `glitch`, `zoom`, `shockwave`, or `ascii`; `time` freezes the
animation for reproducible screenshots; `size` sets the ASCII cell size and
defaults to `20`, matching the native demo. Keys `1`–`5` switch filters live.
The harness loads PixiJS 7 and pixi-filters 5.3.0 from jsDelivr. The native
demo still samples a 256x256 scene while PixiJS filters an 800x600 sprite, so
compare the filter character rather than expecting pixel-exact output.

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

Most demos use an 800x600 window. `coverage` uses its original 160x160 canvas
scaled 4x to 640x640 so the 16x16 pixel-coverage triangles stay legible.
