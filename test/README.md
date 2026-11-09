# Run tests

Run the tests from this `test` directory (the mulle-sde test project root).
The commands do not work from the repository root. From the repository root,
change into the test directory first:

``` sh
cd test
mulle-sde test run 88-regressions/regressions.c
```

Each test is specified by a file with file extension `.c`. This file is
compiled and linked with **mulle-aex-gl-test**.

To run the pre-fix code behind the `AEX_SHOW_ORIGINAL_BUG` switch, add the
define to `CFLAGS` for the same command:

``` sh
mulle-sde -DCFLAGS="-DAEX_SHOW_ORIGINAL_BUG" test run 88-regressions/regressions.c
```

The fixed build prints `headless GLES2 regressions OK`; the bug build prints
`8 of 8 regression checks failed`.

* run specific test with `mulle-sde test run <testfile>`
* rerun only failed tests with `mulle-sde test rerun`


Extension   | Description
------------|-------------------------
`.c`      | Test source
`.stdin`    | Command standard input
`.stdout`   | Expected command standard output


There are quite a few more options to tweak each test. 
See [mulle-test](//github.com/mulle-sde/mulle-test) for more info.
