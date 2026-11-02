# Carburetta grammars (archived)

These `.cbrt` files are the upstream Aex-GL grammar sources for the GLSL ES
1.00 preprocessor and parser. They are **archived for provenance only** and
are not part of the normal build.

The generated C is checked into the source tree:

| Grammar | Generated |
|---|---|
| `glsl_es_1.cbrt` | `src/glsl_es_1.c`, `src/glsl_es_1.h` |
| `pp/pp_const_expr.cbrt` | `src/pp/pp_const_expr.c`, `.h` |
| `pp/pp_line_continuations.cbrt` | `src/pp/pp_line_continuations.c`, `.h` |
| `pp/pp_line_directives.cbrt` | `src/pp/pp_line_directives.c`, `.h` |
| `pp/pp_macro_expander.cbrt` | `src/pp/pp_macro_expander.c`, `.h` |
| `pp/pp_tokenizer.cbrt` | `src/pp/pp_tokenizer.c`, `.h` |
| `pp/pp_trigraphs.cbrt` | `src/pp/pp_trigraphs.c`, `.h` |

Carburetta is therefore **not** a build or runtime dependency.

## Local patches to generated files

The vendored generated headers are not byte-identical to a fresh Carburetta
run. They carry forward declarations needed by clang:

- `src/glsl_es_1.h`: `struct glsl_es1_compiler;`, `struct pptk;`
- `src/pp/pp_line_directives.h`, `pp_macro_expander.h`, `pp_const_expr.h`,
  `pp_tokenizer.h`, `pp_line_continuations.h`, `pp_trigraphs.h`:
  `struct pptk;`, `struct preprocessor;`, `struct situs;`

Keep these patches when regenerating, or move them into a shared predef
header that each generated header includes.

## Regenerating (only when a grammar changes)

The archiver used these versions:

- Carburetta 0.8.29 (development)
- commit `3b759f63d497705c33342f9989dc7d7e0fda48f9`
- `https://github.com/kingletbv/carburetta`

Build the host tool:

```sh
git clone https://github.com/kingletbv/carburetta.git
cd carburetta
make build/carburetta
```

From the project root:

```sh
CB=/path/to/carburetta/build/carburetta
$CB grammar/glsl_es_1.cbrt --c src/glsl_es_1.c --h
for f in pp_trigraphs pp_line_continuations pp_tokenizer \
         pp_const_expr pp_line_directives pp_macro_expander; do
   $CB "grammar/pp/$f.cbrt" --c "src/pp/$f.c" --h
done
```

Generation is deterministic for a given input and output path. The output
contains `#line` references back to these grammar files; keep the `grammar/`
directory if you want those references to resolve.
