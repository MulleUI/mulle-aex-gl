# Archived grammar

`glsl_es_1.cbrt` is the original grammar for the GLSL ES 1.00 parser. It is
kept for provenance and reference only and is not part of the build. The
parser is now hand-written in `src/glsl_es_1.c` / `src/glsl_es_1.h`.

The preprocessor is implemented by `mulle-cpp-engine`; there are no generated
preprocessor sources and no Carburetta build or runtime dependency anymore.
