#line 1 "grammar/pp/pp_line_continuations.cbrt"
/* Copyright 2020-2024 Kinglet B.V.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


#ifndef STDLIB_H_INCLUDED
#define STDLIB_H_INCLUDED
#include <stdlib.h>
#endif

#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED
#include <string.h>
#endif

#ifndef PP_H_INCLUDED
#define PP_H_INCLUDED
#include "pp.h"
#endif

#ifndef SITUS_H_INCLUDED
#define SITUS_H_INCLUDED
#include "situs.h"
#endif

/* --------- START OF GENERATED CODE ------------ */
#if defined(__clang__)
#elif defined(__GNUC__) && defined(__cplusplus)
/* don't warn on realloc, memcpy, memset on C++ classes */
#pragma GCC diagnostic ignored "-Wclass-memaccess"
#endif
#include <stdlib.h> /* realloc(), free(), NULL, size_t */
#include <string.h> /* memcpy() */
#include <stddef.h> /* size_t */
#include <stdint.h> /* SIZE_MAX */
struct aex_pplc_sym_data {
  #ifdef __cplusplus
  // clear destructor in case C++ symbol types have non-trivial destructors
  // (we invoke their destructors explicitly)
  ~aex_pplc_sym_data() = delete;
  #endif
  int state_;
  struct   situs common_;
};
static const int aex_pplc_scan_table_grouped_rex_[] = {
  /*
   00  01  02  03  04  05  06  07 */
    0,  0,  0,  0,  0,  0,  0,  0,
    0,  3,  4,  5,  1,  1,  1,  2,
    0,  3,  4,  5,  2,  2,  2,  2,
    0,  3,  7,  8,  3,  3,  3,  6,
    0,  0,  0,  0,  4,  4,  4,  4,
    0,  3, 10,  8,  5,  5,  5,  9,
    0,  3,  7,  8,  6,  6,  6,  6,
    0,  0,  0,  0,  7,  7,  7,  7,
    0,  3,  0,  8,  8,  8,  8, 11,
    0,  3, 10,  8,  9,  9,  9,  9,
    0,  0,  0,  0, 10, 10, 10, 10,
    0,  3,  0,  8, 11, 11, 11, 11
};
static const size_t aex_pplc_num_scan_table_grouped_columns_ = 8;
static const int aex_pplc_utf8_decoder_[] = {
  /*
   00  01  02  03  04  05  06  07  08  09  0A  0B  0C  0D  0E  0F  10  11  12  13  14  15  16  17  18  19  1A  1B  1C  1D  1E  1F  20  21  22  23  24  25  26  27  28  29  2A  2B  2C  2D  2E  2F  30  31  32  33  34  35  36  37  38  39  3A  3B  3C  3D  3E  3F  40  41  42  43  44  45  46  47  48  49  4A  4B  4C  4D  4E  4F  50  51  52  53  54  55  56  57  58  59  5A  5B  5C  5D  5E  5F  60  61  62  63  64  65  66  67  68  69  6A  6B  6C  6D  6E  6F  70  71  72  73  74  75  76  77  78  79  7A  7B  7C  7D  7E  7F  80  81  82  83  84  85  86  87  88  89  8A  8B  8C  8D  8E  8F  90  91  92  93  94  95  96  97  98  99  9A  9B  9C  9D  9E  9F  A0  A1  A2  A3  A4  A5  A6  A7  A8  A9  AA  AB  AC  AD  AE  AF  B0  B1  B2  B3  B4  B5  B6  B7  B8  B9  BA  BB  BC  BD  BE  BF  C0  C1  C2  C3  C4  C5  C6  C7  C8  C9  CA  CB  CC  CD  CE  CF  D0  D1  D2  D3  D4  D5  D6  D7  D8  D9  DA  DB  DC  DD  DE  DF  E0  E1  E2  E3  E4  E5  E6  E7  E8  E9  EA  EB  EC  ED  EE  EF  F0  F1  F2  F3  F4  F5  F6  F7  F8  F9  FA  FB  FC  FD  FE  FF */
    1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  2,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  3,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -2, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -4, -5, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -7, -8, -9, -9, -9,-10, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
   -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
   -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
   -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
   -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,-11,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
   -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
   -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-13, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
   -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,-14,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
   -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
   -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-15,-16, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
   -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
   -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
   -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
   -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,-17,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
   -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
   -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-18,-19, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
   -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
   -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
   -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1
};
static const size_t aex_pplc_scan_actions_rex[] = { 0, 0, 3, 7, 1, 0, 2, 1, 0, 6, 5, 6 };
static const int aex_pplc_minimum_sym = 4;
static const size_t aex_pplc_num_columns = 2;
static const int aex_pplc_parse_table[] = {
  -1, 0,
};
static const size_t aex_pplc_production_lengths[] = {
  0
};
static const int aex_pplc_production_syms[] = {
  5
};

#ifndef CARB_AEX_PPLC_SRCPPPP_LINE_CONTINUATIONS_H_INCLUDED
struct aex_pplc_stack {
  int error_recovery_:1;
  int pending_reset_:1;
  int discard_remaining_actions_:1;
  int slot_1_has_sym_data_:1;
  int slot_1_has_common_data_:1;
  int top_of_stack_has_sym_data_:1;
  int top_of_stack_has_common_data_:1;
  int need_sym_:1;
  int is_final_input_:1;
  int slot_0_has_current_sym_data_:1;
  int slot_0_has_common_data_:1;
  int current_sym_;
  size_t input_size_;
  const char *input_;
  int newbuf_pos_has_common_data_:1;
  int newbuf_pos_has_sym_data_:1;
  int stack_newbuf_pos_has_common_data_:1;
  int stack_newbuf_pos_has_sym_data_:1;
  int action_preservation_;
  int current_err_action_;
  int slot_1_sym_;
  int continue_at_;
  int mute_error_turns_;
  size_t pos_, num_stack_allocated_;
  struct aex_pplc_sym_data *stack_;
  struct aex_pplc_sym_data *sym_data_;
  struct aex_pplc_sym_data *new_buf_;
  size_t new_buf_num_allocated_;
  size_t new_buf_sym_partial_pos_;
  size_t current_production_length_;
  int current_production_nonterminal_;
  size_t sym_idx_;
  size_t scan_state_;
  size_t current_mode_start_state_;
  size_t match_index_;
  size_t best_match_action_;
  size_t best_match_size_;
  size_t input_index_;
  size_t input_offset_;
  size_t match_buffer_size_;
  size_t match_buffer_size_allocated_;
  /* offset, line and column at the start of match_buffer_ */
  size_t match_offset_;
  int match_line_;
  int match_col_;
  /* offset, line and column at the zero-termination (best_match_size_) of a match 
  * in match_buffer_ (the actual buffer may well be longer.) */
  size_t best_match_offset_;
  int best_match_line_;
  int best_match_col_;
  size_t token_size_;
  char *match_buffer_;
  char terminator_repair_;
  int input_line_;
  int input_col_;
  int sym_grp_;
  char codepoint_[4];
  char *cp_;
};
#define _AEX_PPLC_FINISH 0
#define _AEX_PPLC_MATCH 1
#define _AEX_PPLC_OVERFLOW 2
#define _AEX_PPLC_NO_MEMORY 3
#define _AEX_PPLC_FEED_ME 4
#define _AEX_PPLC_END_OF_INPUT 5
#define _AEX_PPLC_SYNTAX_ERROR 6
#define _AEX_PPLC_LEXICAL_ERROR 7
#define _AEX_PPLC_INTERNAL_ERROR 8

#define AEX_PPLC_ERROR 3
#define AEX_PPLC_INPUT_END 4


#define M_AEX_PPLC_DEFAULT 1

#endif /* CARB_AEX_PPLC_SRCPPPP_LINE_CONTINUATIONS_H_INCLUDED */

void aex_pplc_stack_init(struct aex_pplc_stack *stack) {
  stack->error_recovery_ = 0;
  stack->pending_reset_ = 1;
  stack->discard_remaining_actions_ = 0;
  stack->need_sym_ = 1;
  stack->current_sym_ = 0;
  stack->current_err_action_ = 0;
  stack->input_ = NULL;
  stack->input_size_ = 0;
  stack->is_final_input_ = 0;
  stack->slot_1_has_sym_data_ = stack->slot_1_has_common_data_ = 0;
  stack->slot_1_sym_ = 0;
  stack->top_of_stack_has_sym_data_ = stack->top_of_stack_has_common_data_ = 0;
  stack->newbuf_pos_has_common_data_ = stack->newbuf_pos_has_sym_data_ = 0;
  stack->stack_newbuf_pos_has_common_data_ = stack->stack_newbuf_pos_has_sym_data_ = 0;
  stack->continue_at_ = 0;
  stack->mute_error_turns_ = 0;
  stack->pos_ = 0;
  stack->num_stack_allocated_ = 0;
  stack->stack_ = NULL;
  stack->sym_data_ = NULL;
  stack->new_buf_ = NULL;
  stack->new_buf_num_allocated_ = 0;
  stack->new_buf_sym_partial_pos_ = 0;
  stack->current_production_length_ = 0;
  stack->current_production_nonterminal_ = 0;
  stack->sym_idx_ = 0;
  stack->slot_0_has_current_sym_data_ = stack->slot_0_has_common_data_ = 0;
  stack->current_mode_start_state_ = M_AEX_PPLC_DEFAULT;
  stack->scan_state_ = stack->current_mode_start_state_;
  stack->input_index_ = 0;
  stack->input_offset_ = 0;
  stack->input_line_ = 1;
  stack->input_col_ = 1;
  stack->sym_grp_ = 0;
  stack->cp_ = stack->codepoint_;
  stack->match_index_ = 0;
  stack->match_buffer_ = NULL;
  stack->match_buffer_size_ = 0;
  stack->match_buffer_size_allocated_ = 0;
  stack->terminator_repair_ = '\0';
  stack->token_size_ = 0;
  stack->match_offset_ = 0;
  stack->match_line_ = 1;
  stack->match_col_ = 1;
  stack->best_match_action_ = 0;
  stack->best_match_size_ = 0;
  stack->best_match_offset_ = 0;
  stack->best_match_line_ = 1;
  stack->best_match_col_ = 1;
}

void aex_pplc_stack_cleanup(struct aex_pplc_stack *stack) {
  size_t n;
  if (!stack->new_buf_) n = 0;
  else {
    n = stack->new_buf_sym_partial_pos_;
  }
  for (; n < stack->pos_; ++n) {
    int need_common_deconstruct = 0;
    if ((n == 0) || (n == 1)) {
      if (n == 0) {
        /* slot 0 is used for pattern matching; stack->current_sym_ describes its
        * contents, not stack->stack_[0].state_ */
        need_common_deconstruct = stack->slot_0_has_common_data_;
      }
      else if (n == 1) {
        need_common_deconstruct = stack->slot_1_has_common_data_;
      }
      if (stack->new_buf_ && (n == stack->new_buf_sym_partial_pos_)) {
        need_common_deconstruct = need_common_deconstruct && stack->stack_newbuf_pos_has_common_data_;
      }
    }
    else if (n == (stack->pos_ - 1)) {
      need_common_deconstruct = stack->top_of_stack_has_common_data_;
      if (n == stack->new_buf_sym_partial_pos_) {
        need_common_deconstruct = need_common_deconstruct && stack->stack_newbuf_pos_has_common_data_;
      }
    }
    else if (stack->new_buf_ && (n == stack->new_buf_sym_partial_pos_)) {
      need_common_deconstruct = stack->stack_newbuf_pos_has_common_data_;
    }
    else {
      need_common_deconstruct = 1;
    }
    if (need_common_deconstruct) {
      {
#line 43 "grammar/pp/pp_line_continuations.cbrt"
        aex_situs_cleanup(&((stack->stack_ + n)->common_));
#line 279 "src/pp/pp_line_continuations.c"
      }
      
    }
  }
  if (stack->new_buf_) {
    /* same deconstructors as above, but now for stack->new_buf_ -- stack->new_buf_ only
    * exists for a brief period time when we resize stack->stack_, however, because
    * constructors and moves are allowed to throw, or otherwise return and fail, it is
    * required that we deconstruct the stack->new_buf_ elements cleanly. */
    for (n = 0; n <= stack->new_buf_sym_partial_pos_; ++n) {
      int need_common_deconstruct = 0;
      if ((n == 0) || (n == 1)) {
        if (n == 0) {
          /* slot 0 is used for pattern matching; stack->current_sym_ describes its
          * contents, not stack->stack_[0].state_ */
          need_common_deconstruct = stack->slot_0_has_common_data_;
        }
        else if (n == 1) {
          need_common_deconstruct = stack->slot_1_has_common_data_;
        }
        if (n == stack->new_buf_sym_partial_pos_) {
          need_common_deconstruct = need_common_deconstruct && stack->newbuf_pos_has_common_data_;
        }
      }
      else if (n == (stack->pos_ - 1)) {
        need_common_deconstruct = stack->top_of_stack_has_common_data_;
        if (n == stack->new_buf_sym_partial_pos_) {
          need_common_deconstruct = need_common_deconstruct && stack->newbuf_pos_has_common_data_;
        }
      }
      else if (n == stack->new_buf_sym_partial_pos_) {
        need_common_deconstruct = stack->newbuf_pos_has_common_data_;
      }
      else {
        need_common_deconstruct = 1;
      }
      if (need_common_deconstruct) {
        {
#line 43 "grammar/pp/pp_line_continuations.cbrt"
          aex_situs_cleanup(&((stack->new_buf_ + n)->common_));
#line 320 "src/pp/pp_line_continuations.c"
        }
        
      }
    }
    free(stack->new_buf_);
    stack->new_buf_ = NULL;
  }
  if (stack->stack_) free(stack->stack_);
  if (stack->match_buffer_) free(stack->match_buffer_);
}

int aex_pplc_stack_reset(struct aex_pplc_stack *stack) {
  stack->pending_reset_ = 0;
  stack->discard_remaining_actions_ = 0;
  size_t n;
  if (!stack->new_buf_) n = 0;
  else {
    n = stack->new_buf_sym_partial_pos_;
  }
  for (; n < stack->pos_; ++n) {
    int need_common_deconstruct = 0;
    if ((n == 0) || (n == 1)) {
      if (n == 0) {
        /* slot 0 is used for pattern matching; stack->current_sym_ describes its
        * contents, not stack->stack_[0].state_ */
        need_common_deconstruct = stack->slot_0_has_common_data_;
      }
      else if (n == 1) {
        need_common_deconstruct = stack->slot_1_has_common_data_;
      }
      if (stack->new_buf_ && (n == stack->new_buf_sym_partial_pos_)) {
        need_common_deconstruct = need_common_deconstruct && stack->stack_newbuf_pos_has_common_data_;
      }
    }
    else if (n == (stack->pos_ - 1)) {
      need_common_deconstruct = stack->top_of_stack_has_common_data_;
      if (n == stack->new_buf_sym_partial_pos_) {
        need_common_deconstruct = need_common_deconstruct && stack->stack_newbuf_pos_has_common_data_;
      }
    }
    else if (stack->new_buf_ && (n == stack->new_buf_sym_partial_pos_)) {
      need_common_deconstruct = stack->stack_newbuf_pos_has_common_data_;
    }
    else {
      need_common_deconstruct = 1;
    }
    if (need_common_deconstruct) {
      {
#line 43 "grammar/pp/pp_line_continuations.cbrt"
        aex_situs_cleanup(&((stack->stack_ + n)->common_));
#line 371 "src/pp/pp_line_continuations.c"
      }
      
    }
  }
  if (stack->new_buf_) {
    /* same deconstructors as above, but now for stack->new_buf_ -- stack->new_buf_ only
    * exists for a brief period time when we resize stack->stack_, however, because
    * constructors and moves are allowed to throw, or otherwise return and fail, it is
    * required that we deconstruct the stack->new_buf_ elements cleanly. */
    for (n = 0; n <= stack->new_buf_sym_partial_pos_; ++n) {
      int need_common_deconstruct = 0;
      if ((n == 0) || (n == 1)) {
        if (n == 0) {
          /* slot 0 is used for pattern matching; stack->current_sym_ describes its
          * contents, not stack->stack_[0].state_ */
          need_common_deconstruct = stack->slot_0_has_common_data_;
        }
        else if (n == 1) {
          need_common_deconstruct = stack->slot_1_has_common_data_;
        }
        if (n == stack->new_buf_sym_partial_pos_) {
          need_common_deconstruct = need_common_deconstruct && stack->newbuf_pos_has_common_data_;
        }
      }
      else if (n == (stack->pos_ - 1)) {
        need_common_deconstruct = stack->top_of_stack_has_common_data_;
        if (n == stack->new_buf_sym_partial_pos_) {
          need_common_deconstruct = need_common_deconstruct && stack->newbuf_pos_has_common_data_;
        }
      }
      else if (n == stack->new_buf_sym_partial_pos_) {
        need_common_deconstruct = stack->newbuf_pos_has_common_data_;
      }
      else {
        need_common_deconstruct = 1;
      }
      if (need_common_deconstruct) {
        {
#line 43 "grammar/pp/pp_line_continuations.cbrt"
          aex_situs_cleanup(&((stack->new_buf_ + n)->common_));
#line 412 "src/pp/pp_line_continuations.c"
        }
        
      }
    }
    free(stack->new_buf_);
    stack->new_buf_ = NULL;
  }
  stack->slot_0_has_current_sym_data_ = stack->slot_0_has_common_data_ = 0;
  stack->slot_1_has_sym_data_ = stack->slot_1_has_common_data_ = 0;
  stack->slot_1_sym_ = 0;
  stack->top_of_stack_has_sym_data_ = 0;
  stack->top_of_stack_has_common_data_ = 0;
  stack->newbuf_pos_has_common_data_ = stack->newbuf_pos_has_sym_data_ = 0;
  stack->stack_newbuf_pos_has_common_data_ = stack->stack_newbuf_pos_has_sym_data_ = 0;
  stack->sym_data_ = NULL;
  stack->current_production_length_ = 0;
  stack->current_production_nonterminal_ = 0;
  stack->sym_idx_ = 0;
  stack->pos_ = 0;
  stack->error_recovery_ = 0;
  stack->need_sym_ = 1;
  stack->current_sym_ = 0;
  stack->current_err_action_ = 0;
  stack->action_preservation_ = 0;
  stack->continue_at_ = 0;
  stack->mute_error_turns_ = 0;
  /* reserve slots [0] and [1] for temporary storage of inflight syms and tokens.
  * note that initialization and lifetime of these slots is controlled by
  * flags, so no sym data constructors are called here. */
  if (stack->num_stack_allocated_ <= (stack->pos_ + 1)) {
    size_t new_num_allocated;
    if (stack->num_stack_allocated_) {
      new_num_allocated = stack->num_stack_allocated_ * 2;
      if (new_num_allocated <= stack->num_stack_allocated_) {
        /* Overflow in allocation */
        stack->continue_at_ = 0;
        return _AEX_PPLC_OVERFLOW;
      }
    }
    else {
      new_num_allocated = 16;
    }
    
    if (new_num_allocated > (SIZE_MAX / sizeof(struct aex_pplc_sym_data))) {
      /* Overflow in allocation */
      stack->continue_at_ = 0;
      return _AEX_PPLC_OVERFLOW;
    }
    
    void *p = realloc(stack->stack_, new_num_allocated * sizeof(struct aex_pplc_sym_data));
    if (!p) {
      /* Out of memory */
      stack->continue_at_ = 0;
      return _AEX_PPLC_NO_MEMORY;
    }
    stack->stack_ = (struct aex_pplc_sym_data *)p;
    stack->num_stack_allocated_ = new_num_allocated;
  }
  stack->stack_[0].state_ = 0;
  stack->stack_[1].state_ = 0;
  stack->pos_ = 2;
  stack->scan_state_ = stack->current_mode_start_state_;
  stack->input_offset_ = 0;
  stack->input_line_ = 1;
  stack->input_col_ = 1;
  stack->match_index_ = 0;
  stack->match_buffer_size_ = 0;
  stack->terminator_repair_ = '\0';
  stack->token_size_ = 0;
  stack->match_offset_ = 0;
  stack->match_line_ = 1;
  stack->match_col_ = 1;
  stack->best_match_action_ = 0;
  stack->best_match_size_ = 0;
  stack->best_match_offset_ = 0;
  stack->best_match_line_ = 1;
  stack->best_match_col_ = 1;
  stack->sym_grp_ = 0;
  stack->cp_ = stack->codepoint_;
  return 0;
}

int aex_pplc_stack_can_recover(struct aex_pplc_stack *stack) {
  return !!stack->error_recovery_;
}

int aex_pplc_stack_accepts(struct aex_pplc_stack *stack, int sym) {
  if (!stack->pos_) return 0;
  return 0 != aex_pplc_parse_table[aex_pplc_num_columns * stack->stack_[stack->pos_ - 1].state_ + (sym - aex_pplc_minimum_sym)];}

void aex_pplc_set_mode(struct aex_pplc_stack *stack, int mode) {
  if (stack->current_mode_start_state_ == stack->scan_state_) {
    stack->scan_state_ = mode;
  }
  stack->current_mode_start_state_ = mode;
}

int aex_pplc_mode(struct aex_pplc_stack *stack) {
  return (int)stack->current_mode_start_state_;
}

static int aex_pplc_append_match_buffer(struct aex_pplc_stack *stack, const char *s, size_t len) {
  size_t size_needed = len;
  size_needed += stack->match_buffer_size_;
  if (size_needed < stack->match_buffer_size_) {
    return _AEX_PPLC_OVERFLOW;
  }
  if (size_needed == SIZE_MAX) {
    /* cannot fit null terminator */
    return _AEX_PPLC_OVERFLOW;
  }
  size_needed++; /* null terminator */
  if (size_needed < 128) {
    size_needed = 128;
  }
  if (size_needed > stack->match_buffer_size_allocated_) {
    /* intent of code: grow buffer size by powers of 2-1, unless our needs require more now. */
    size_t size_to_allocate = stack->match_buffer_size_allocated_ * 2 + 1;
    if (size_to_allocate <= stack->match_buffer_size_allocated_) {
      return _AEX_PPLC_OVERFLOW;
    }
    if (size_to_allocate < size_needed) {
      size_to_allocate = size_needed;
    }
    void *buf = realloc(stack->match_buffer_, size_to_allocate);
    if (!buf) {
      return _AEX_PPLC_NO_MEMORY;
    }
    stack->match_buffer_ = (char *)buf;
    stack->match_buffer_size_allocated_ = size_to_allocate;
  }
  
  memcpy(stack->match_buffer_ + stack->match_buffer_size_, s, len);
  stack->match_buffer_size_ += len;
  stack->match_buffer_[stack->match_buffer_size_] = '\0';
  return 0;
}

void aex_pplc_set_input(struct aex_pplc_stack *stack, const char *input, size_t input_size, int is_final_input) {
  stack->input_ = input;
  stack->input_size_ = input_size;
  stack->is_final_input_ = is_final_input;
  stack->input_index_ = 0;
}

void aex_pplc_set_location(struct aex_pplc_stack *stack, int line, int col, size_t offset) {
  if (stack->token_size_) {
    /* Parsing of next token not in progress, set end location of this token as
    ** it will be the start of the next token. */
    stack->input_line_ = stack->input_line_ - stack->best_match_line_ + line;
    stack->input_col_ = stack->input_col_ - stack->best_match_col_ + col;
    stack->input_offset_ = stack->input_offset_ - stack->best_match_offset_ + offset;
    
    stack->best_match_line_ = line;
    stack->best_match_col_ = col;
    stack->best_match_offset_ = offset;
    return;
  }
  /* Parsing of token in progress, dynamically move the start of the token, as
  ** well as the relative current partial end of the token, to the desired location. */
  stack->input_line_ = stack->input_line_ - stack->match_line_ + line;
  stack->input_col_ = stack->input_col_ - stack->match_col_ + col;
  stack->input_offset_ = stack->input_offset_ - stack->match_offset_ + offset;
  
  stack->best_match_line_ = stack->best_match_line_ - stack->match_line_ + line;
  stack->best_match_col_ = stack->best_match_col_ - stack->match_col_ + col;
  stack->best_match_offset_ = stack->best_match_offset_ - stack->match_offset_ + offset;
  stack->match_line_ = line;
  stack->match_col_ = col;
  stack->match_offset_ = offset;
}

const char *aex_pplc_text(struct aex_pplc_stack *stack) {
  return stack->match_buffer_;
}

size_t aex_pplc_len(struct aex_pplc_stack *stack) {
  return stack->token_size_;
}

int aex_pplc_line(struct aex_pplc_stack *stack) {
  return stack->match_line_;
}

int aex_pplc_column(struct aex_pplc_stack *stack) {
  return stack->match_col_;
}

size_t aex_pplc_offset(struct aex_pplc_stack *stack) {
  return stack->match_offset_;
}

int aex_pplc_endline(struct aex_pplc_stack *stack) {
  return stack->best_match_line_;
}

int aex_pplc_endcolumn(struct aex_pplc_stack *stack) {
  return stack->best_match_col_;
}

size_t aex_pplc_endoffset(struct aex_pplc_stack *stack) {
  return stack->best_match_offset_;
}

void *aex_pplc_token_common_data(struct aex_pplc_stack *stack) {
  return stack->slot_0_has_common_data_ ? &stack->stack_[0].common_ : NULL;
}
int aex_pplc_lex(struct aex_pplc_stack *stack) {
  int r;
  unsigned char c;
  const char *input = stack->input_;
  size_t input_size = stack->input_size_;
  int is_final_input = !!stack->is_final_input_;
  size_t scan_state = stack->scan_state_;
  const int *transition_table = aex_pplc_scan_table_grouped_rex_;
  const size_t *actions = aex_pplc_scan_actions_rex;
  const size_t row_size = aex_pplc_num_scan_table_grouped_columns_;
  const size_t default_action = 0;
  const size_t start_action = 0;
  char *cp = stack->cp_;
  
  size_t match_index = stack->match_index_;
  
  size_t best_match_action = stack->best_match_action_;
  size_t best_match_size = stack->best_match_size_;
  size_t best_match_offset = stack->best_match_offset_;
  int best_match_line = stack->best_match_line_;
  int best_match_col = stack->best_match_col_;
  
  size_t input_index = stack->input_index_;
  size_t input_offset = stack->input_offset_;
  int input_line = stack->input_line_;
  int input_col = stack->input_col_;
  
  int symgrp;
  symgrp = stack->sym_grp_;
  
  /* Move any prior token out of the way */
  if (stack->token_size_) {
    stack->match_buffer_[stack->token_size_] = stack->terminator_repair_;
    
    memcpy(stack->match_buffer_, stack->match_buffer_ + stack->token_size_, stack->match_buffer_size_ - stack->token_size_);
    stack->match_buffer_size_ -= stack->token_size_;
    stack->match_offset_ = stack->best_match_offset_;
    stack->match_line_ = stack->best_match_line_;
    stack->match_col_ = stack->best_match_col_;
    
    /* Reset scanner to get ready for next token */
    stack->match_index_ = match_index = 0;
    stack->best_match_action_ = best_match_action = start_action;
    stack->best_match_size_ = best_match_size = 0;
    stack->scan_state_ = scan_state = stack->current_mode_start_state_;
    stack->token_size_ = 0;
    
  }
  
  size_t at_match_index_offset = stack->match_offset_;
  int at_match_index_line = stack->match_line_;
  int at_match_index_col = stack->match_col_;
  while (match_index < stack->match_buffer_size_) {
    c = (unsigned char)stack->match_buffer_[match_index];
    int next_sg = aex_pplc_utf8_decoder_[256 * symgrp + c];
    if (next_sg >= 0 || !~next_sg) {
      if (next_sg >= 0) {
        /* Use next_sg as the new symgroup */
        match_index++;
        symgrp = next_sg;
        *cp++ = c;
      }
      else /* (!~next_sg) */ {
        /* Invalid encoding, set next_sg to the unused codepoint group, this will 
        * induce a syntax error in the transition_table. */
        next_sg = 0;
        if (!symgrp) {
          /* Eat at least 1 byte of input, otherwise we will not make progress; but
          * the byte that triggered an encoding error on a multi-byte codepoint should
          * be reconsidered as the starting byte on a new codepoint. */
          match_index++;
          *cp++ = c;
        }
      }
      
      for (;;) {
        /* Check for start of input */
        if ((((size_t)transition_table[row_size * (1 + scan_state) - 4]) != scan_state) && (!at_match_index_offset)) {
          scan_state = (size_t)transition_table[row_size * (1 + scan_state) - 4];
        }
        /* Check for start of line */
        else if ((((size_t)transition_table[row_size * (1 + scan_state) - 3]) != scan_state) && (at_match_index_col == 1)) {
          scan_state = (size_t)transition_table[row_size * (1 + scan_state) - 3];
        }
        /* Check for end of line */
        else if ((((size_t)transition_table[row_size * (1 + scan_state) - 2]) != scan_state) && ('\n' == stack->codepoint_[0])) {
          scan_state = (size_t)transition_table[row_size * (1 + scan_state) - 2];
        }
        /* (No need to check for end of input; we have at least 1 character ahead) */
        else {
          break;
        }
      }
      size_t state_action;
      state_action = actions[scan_state];
      ptrdiff_t cp_len = cp - stack->codepoint_;
      if (state_action != default_action) /* replace with actual */ {
        best_match_action = state_action;
        best_match_size = match_index - cp_len;
        best_match_offset = at_match_index_offset;
        best_match_line = at_match_index_line;
        best_match_col = at_match_index_col;
      }
      scan_state = transition_table[row_size * scan_state + symgrp];
      /* reset decoder */
      symgrp = 0;
      cp = stack->codepoint_;
      if (scan_state) {
        at_match_index_offset += (size_t)cp_len;
        if (stack->codepoint_[0] != '\n') {
          at_match_index_col++;
        }
        else {
          at_match_index_col = 1;
          at_match_index_line++;
        }
      }
      else {
        /* error, or, end of token, depending on whether we have a match before */
        if (best_match_action == default_action) {
          goto syntax_error;
        }
        
        /* Ensure token match is null terminated */
        stack->terminator_repair_ = stack->match_buffer_[best_match_size];
        stack->match_buffer_[best_match_size] = '\0';
        stack->token_size_ = best_match_size;
        stack->best_match_action_ = best_match_action;
        stack->best_match_size_ = best_match_size;
        stack->best_match_offset_ = best_match_offset;
        stack->best_match_line_ = best_match_line;
        stack->best_match_col_ = best_match_col;
        
        stack->input_index_ = input_index;
        stack->input_offset_ = input_offset;
        stack->input_line_ = input_line;
        stack->input_col_ = input_col;
        
        stack->cp_ = cp;
        stack->sym_grp_ = symgrp;
        
        return _AEX_PPLC_MATCH;
      }
    }
    else /* (next_sg < 0) */ {
      /* Partial analysis of codepoint; keep going */
      *cp++ = c;
      match_index++;
      symgrp = ~next_sg;
    }
  }
  while (input_index < input_size) {
    c = (unsigned char)input[input_index];
    int next_sg = aex_pplc_utf8_decoder_[256 * symgrp + c];
    if ((next_sg >= 0) || !~next_sg) {
      if (next_sg >= 0) {
        /* Use next_sg as the new symgroup */
        input_index++;
        symgrp = next_sg;
        *cp++ = c;
      }
      else /* (!~next_sg) */ {
        /* Invalid encoding, set next_sg to the unused codepoint group, this will 
        * induce a syntax error in the transition_table. */
        next_sg = 0;
        if (!symgrp) {
          /* Eat at least 1 byte of input, otherwise we will not make progress; but
          * the byte that triggered an encoding error on a multi-byte codepoint should
          * be reconsidered as the starting byte on a new codepoint. */
          input_index++;
          *cp++ = c;
        }
      }
      
      for (;;) {
        /* Check for start of input */
        if ((((size_t)transition_table[row_size * (1 + scan_state) - 4]) != scan_state) && (!input_offset)) {
          scan_state = (size_t)transition_table[row_size * (1 + scan_state) - 4];
        }
        /* Check for start of line */
        else if ((((size_t)transition_table[row_size * (1 + scan_state) - 3]) != scan_state) && (input_col == 1)) {
          scan_state = (size_t)transition_table[row_size * (1 + scan_state) - 3];
        }
        /* Check for end of line */
        else if ((((size_t)transition_table[row_size * (1 + scan_state) - 2]) != scan_state) && ('\n' == stack->codepoint_[0])) {
          scan_state = (size_t)transition_table[row_size * (1 + scan_state) - 2];
        }
        /* (No need to check for end of input; we have at least 1 character ahead) */
        else {
          break;
        }
      }
      size_t state_action;
      state_action = actions[scan_state];
      ptrdiff_t cp_len = cp - stack->codepoint_;
      if (state_action != default_action) /* replace with actual */ {
        best_match_action = state_action;
        best_match_size = stack->match_buffer_size_ + input_index - stack->input_index_ - cp_len;
        best_match_offset = input_offset;
        best_match_col = input_col;
        best_match_line = input_line;
      }
      scan_state = transition_table[row_size * scan_state + symgrp];
      /* Reset decoder */
      symgrp = 0;
      cp = stack->codepoint_;
      /* We advanced input_index by a codepoint and so must process line and col to keep them in sync. */
      input_offset += (size_t)cp_len;
      if (stack->codepoint_[0] != '\n') {
        input_col++;
      }
      else {
        input_col = 1;
        input_line++;
      }
      if (!scan_state) {
        /* Append from stack->input_index_ to input_index, excluding input_index itself */
        r = aex_pplc_append_match_buffer(stack, input + stack->input_index_, input_index - stack->input_index_);
        if (r) return r;
        
        if (best_match_action == default_action) {
          goto syntax_error;
        }
        
        /* Ensure token match is null terminated, note that the size we just appended may
        * (likely) be longer than the last section we matched. */
        stack->terminator_repair_ = stack->match_buffer_[best_match_size];
        stack->match_buffer_[best_match_size] = '\0';
        stack->token_size_ = best_match_size;
        stack->best_match_action_ = best_match_action;
        stack->best_match_size_ = best_match_size;
        stack->best_match_offset_ = best_match_offset;
        stack->best_match_line_ = best_match_line;
        stack->best_match_col_ = best_match_col;
        
        stack->input_index_ = input_index;
        stack->input_offset_ = input_offset;
        stack->input_line_ = input_line;
        stack->input_col_ = input_col;
        
        stack->cp_ = cp;
        stack->sym_grp_ = symgrp;
        
        return _AEX_PPLC_MATCH;
      }
    }
    else /* (next_sg < 0) */ {
      /* Partial analysis of codepoint; keep going */
      *cp++ = c;
      input_index++;
      symgrp = ~next_sg;
    }
  }
  
  r = aex_pplc_append_match_buffer(stack, input + stack->input_index_, input_index - stack->input_index_);
  if (r) return r;
  
  /* Resume scanning after the input already processed. */
  match_index = stack->match_buffer_size_;
  
  if (!is_final_input) {
    /* Need more input */
    stack->scan_state_ = scan_state;
    stack->token_size_ = 0; /* no match yet */
    stack->input_index_ = input_index;
    stack->input_offset_ = input_offset;
    stack->input_line_ = input_line;
    stack->input_col_ = input_col;
    
    stack->best_match_action_ = best_match_action;
    stack->best_match_size_ = best_match_size;
    stack->best_match_offset_ = best_match_offset;
    stack->best_match_line_ = best_match_line;
    stack->best_match_col_ = best_match_col;
    
    stack->match_index_ = match_index;
    
    stack->cp_ = cp;
    stack->sym_grp_ = symgrp;
    
    return _AEX_PPLC_FEED_ME;
  }
  for (;;) {
    /* Check for start of input */
    if ((((size_t)transition_table[row_size * (1 + scan_state) - 4]) != scan_state) && (!input_offset)) {
      scan_state = (size_t)transition_table[row_size * (1 + scan_state) - 4];
    }
    /* Check for start of line */
    else if ((((size_t)transition_table[row_size * (1 + scan_state) - 3]) != scan_state) && (input_col == 1)) {
      scan_state = (size_t)transition_table[row_size * (1 + scan_state) - 3];
    }
    /* Check for end of line (always true at end of input) */
    else if (((size_t)transition_table[row_size * (1 + scan_state) - 2]) != scan_state) {
      scan_state = (size_t)transition_table[row_size * (1 + scan_state) - 2];
    }
    /* Check for end of input (always true) */
    else if (((size_t)transition_table[row_size * (1 + scan_state) - 1]) != scan_state) {
      scan_state = (size_t)transition_table[row_size * (1 + scan_state) - 1];
    }
    /* (No need to check for end of input; we have at least 1 character ahead) */
    else {
      break;
    }
  }
  size_t state_action;
  state_action = actions[scan_state];
  if (state_action != default_action) /* replace with actual */ {
    best_match_action = state_action;
    best_match_size = stack->match_buffer_size_;
    best_match_offset = input_offset;
    best_match_col = input_col;
    best_match_line = input_line;
  }
  
  if (!stack->match_buffer_size_ && (stack->input_index_ == input_size)) {
    /* Exhausted all input - leave stack in a state where we can
    * immediately re-use it in its initial state */
    stack->match_index_ = 0;
    stack->best_match_action_ = best_match_action = start_action;
    stack->best_match_size_ = best_match_size;
    stack->best_match_offset_ = best_match_offset;
    stack->best_match_line_ = best_match_line;
    stack->best_match_col_ = best_match_col;
    stack->scan_state_ = scan_state = stack->current_mode_start_state_;
    
    stack->token_size_ = 0;
    stack->input_offset_ = input_offset;
    stack->input_line_ = input_line;
    stack->input_col_ = input_col;
    stack->cp_ = cp;
    stack->sym_grp_ = symgrp;
    
    return _AEX_PPLC_END_OF_INPUT;
  }
  
  if (best_match_action == default_action) {
    goto syntax_error;
  }
  
  /* Ensure token match is null terminated */
  stack->terminator_repair_ = stack->match_buffer_[best_match_size];
  stack->match_buffer_[best_match_size] = '\0';
  stack->token_size_ = best_match_size;
  stack->best_match_action_ = best_match_action;
  stack->best_match_size_ = best_match_size;
  stack->best_match_offset_ = best_match_offset;
  stack->best_match_line_ = best_match_line;
  stack->best_match_col_ = best_match_col;
  
  stack->input_index_ = input_index;
  stack->input_offset_ = input_offset;
  stack->input_line_ = input_line;
  stack->input_col_ = input_col;
  stack->cp_ = cp;
  stack->sym_grp_ = symgrp;
  
  return _AEX_PPLC_MATCH;
  syntax_error: {
    /* compute length of first codepoint in the match; this is not necessarily the
    * codepoint where we discovered the error. */
    size_t cp_len;
    static size_t utf8_cp_len[] = { /* 0xxxx */ 1, 1, 1, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1, 1, 1, 
      /* 10xxx */ 1, 1, 1, 1, 1, 1, 1, 1, /* lead byte as continuation byte is invalid encoding */
      /* 110xx */ 2, 2, 2, 2, 
      /* 1110x */ 3, 3, 
    /* 11110 */ 4 };
    if (stack->match_buffer_size_) {
      cp_len = utf8_cp_len[((unsigned char)stack->match_buffer_[0]) >> 3];
      stack->best_match_offset_ = stack->match_offset_ + cp_len;
      if (stack->match_buffer_[0] != '\n') {
        stack->best_match_line_ = stack->match_line_;
        stack->best_match_col_ = stack->match_col_ + 1;
      }
      else {
        stack->best_match_line_ = stack->match_line_ + 1;
        stack->best_match_col_ = 1;
      }
    }
    else {
      cp_len = utf8_cp_len[((unsigned char)input[stack->input_index_]) >> 3];
      /* Append the single codepoint causing the syntax error */
      r = aex_pplc_append_match_buffer(stack, input + stack->input_index_, cp_len);
      if (r) return r;
      
      input_offset++;
      if (input[stack->input_index_] != '\n') {
        input_col++;
      }
      else {
        input_col = 1;
        input_line++;
      }
      input_index = stack->input_index_ + cp_len;
      stack->best_match_offset_ = input_offset;
      stack->best_match_line_ = input_line;
      stack->best_match_col_ = input_col;
    }
    
    /* Reset scanner to get ready for next token */
    stack->token_size_ = cp_len;
    stack->terminator_repair_ = stack->match_buffer_[cp_len];
    stack->match_buffer_[cp_len] = '\0';
    
    stack->input_index_ = input_index;
    stack->input_offset_ = input_offset;
    stack->input_line_ = input_line;
    stack->input_col_ = input_col;
    stack->cp_ = cp;
    stack->sym_grp_ = symgrp;
    
    return _AEX_PPLC_LEXICAL_ERROR;
  }
}

int aex_pplc_scan(struct aex_pplc_stack *stack, struct preprocessor *pp, char **output_buf, size_t *output_end, size_t *output_buf_alloc_size, struct situs *output_situs, struct situs *input_situs) {
  if (stack->pending_reset_) {
    int r;
    r = aex_pplc_stack_reset(stack);
    if (r) return r;
  }
    switch (stack->continue_at_) {
    case 0: break; /* fall through to regular code path */
    case 1: goto C1;
    case 2: goto C2;
    case 3: goto C3;
    case 4: goto C4;
    case 5: goto C5;
    case 6: goto C6;
    case 7: goto C7;
    case 8: goto C8;
    case 9: goto C9;
    case 10: goto C10;
    case 11: goto C11;
    case 12: goto C12;
    case 13: goto C13;
    case 14: goto C14;
    case 15: goto C15;
    case 16: goto C16;
    case 17: goto C17;
    case 18: goto C18;
    case 19: goto C19;
    case 20: goto C20;
    case 21: goto C21;
    case 22: goto C22;
    case 23: goto C23;
  } /* continuation switch */
for (;;) {
    stack->continue_at_ = 0;
    if (stack->need_sym_) {
      switch (aex_pplc_lex(stack)) {
        case _AEX_PPLC_MATCH:
        stack->need_sym_ = 0;
        stack->discard_remaining_actions_ = 0;
        stack->current_sym_ = AEX_PPLC_INPUT_END; /* no sym specific type associated, changed when we successfully construct it below */
        if (stack->mute_error_turns_) stack->mute_error_turns_--;
        stack->slot_0_has_common_data_ = 1;
        stack->continue_at_ = 1;
        {
#line 42 "grammar/pp/pp_line_continuations.cbrt"
          aex_situs_init(&(stack->stack_[0].common_));
#line 1080 "src/pp/pp_line_continuations.c"
        }
        C1:;
        { /* scope guard */
          switch (stack->best_match_action_) {
            case 1: /* \n|[^\n]*[^\\\n]\n */
            /* Pattern does not have a symbol */
            stack->current_sym_ = AEX_PPLC_INPUT_END;
            stack->need_sym_ = 1; /* keep scanning */
            if (!stack->discard_remaining_actions_) {
              stack->continue_at_ = 2;
              {
#line 47 "grammar/pp/pp_line_continuations.cbrt"
                
  aex_situs_move_range(&(stack->stack_[0].common_), input_situs, (stack->best_match_offset_) - (stack->match_offset_), (stack->match_buffer_));

#line 1096 "src/pp/pp_line_continuations.c"
              }
              C2:;
            }
            if (!stack->discard_remaining_actions_) {
              stack->continue_at_ = 3;
              {
#line 51 "grammar/pp/pp_line_continuations.cbrt"
                
  /* Any line that does not end in a continuation (no \ at the end) */
  if (pp_concat_output_b(pp, output_situs, output_buf, output_end, output_buf_alloc_size, &(stack->stack_[0].common_), (stack->match_buffer_), (stack->token_size_))) {
    return _AEX_PPLC_NO_MEMORY;
  }

#line 1110 "src/pp/pp_line_continuations.c"
              }
              C3:;
            }
            if (stack->need_sym_) {
                        stack->slot_0_has_common_data_ = 0;
              {
#line 43 "grammar/pp/pp_line_continuations.cbrt"
                aex_situs_cleanup(&(stack->stack_[0].common_));
#line 1119 "src/pp/pp_line_continuations.c"
              }
            }
            break;
            case 2: /* [^\n]*[^\\\n]\Z */
            /* Pattern does not have a symbol */
            stack->current_sym_ = AEX_PPLC_INPUT_END;
            stack->need_sym_ = 1; /* keep scanning */
            if (!stack->discard_remaining_actions_) {
              stack->continue_at_ = 4;
              {
#line 47 "grammar/pp/pp_line_continuations.cbrt"
                
  aex_situs_move_range(&(stack->stack_[0].common_), input_situs, (stack->best_match_offset_) - (stack->match_offset_), (stack->match_buffer_));

#line 1134 "src/pp/pp_line_continuations.c"
              }
              C4:;
            }
            if (!stack->discard_remaining_actions_) {
              stack->continue_at_ = 5;
              {
#line 58 "grammar/pp/pp_line_continuations.cbrt"
                
  /* Any line that ends at the end of input. */
  if (pp_concat_output_b(pp, output_situs, output_buf, output_end, output_buf_alloc_size, &(stack->stack_[0].common_), (stack->match_buffer_), (stack->token_size_))) {
    return _AEX_PPLC_NO_MEMORY;
  }

#line 1148 "src/pp/pp_line_continuations.c"
              }
              C5:;
            }
            if (stack->need_sym_) {
                        stack->slot_0_has_common_data_ = 0;
              {
#line 43 "grammar/pp/pp_line_continuations.cbrt"
                aex_situs_cleanup(&(stack->stack_[0].common_));
#line 1157 "src/pp/pp_line_continuations.c"
              }
            }
            break;
            case 3: /* \Z */
            /* Pattern does not have a symbol */
            stack->current_sym_ = AEX_PPLC_INPUT_END;
            stack->need_sym_ = 1; /* keep scanning */
            if (!stack->discard_remaining_actions_) {
              stack->continue_at_ = 6;
              {
#line 47 "grammar/pp/pp_line_continuations.cbrt"
                
  aex_situs_move_range(&(stack->stack_[0].common_), input_situs, (stack->best_match_offset_) - (stack->match_offset_), (stack->match_buffer_));

#line 1172 "src/pp/pp_line_continuations.c"
              }
              C6:;
            }
            if (!stack->discard_remaining_actions_) {
              stack->continue_at_ = 7;
              {
#line 65 "grammar/pp/pp_line_continuations.cbrt"
                
  /* An empty line at the end of input */

#line 1183 "src/pp/pp_line_continuations.c"
              }
              C7:;
            }
            if (stack->need_sym_) {
                        stack->slot_0_has_common_data_ = 0;
              {
#line 43 "grammar/pp/pp_line_continuations.cbrt"
                aex_situs_cleanup(&(stack->stack_[0].common_));
#line 1192 "src/pp/pp_line_continuations.c"
              }
            }
            break;
            case 4: /* \n */
            /* Pattern does not have a symbol */
            stack->current_sym_ = AEX_PPLC_INPUT_END;
            stack->need_sym_ = 1; /* keep scanning */
            if (!stack->discard_remaining_actions_) {
              stack->continue_at_ = 8;
              {
#line 47 "grammar/pp/pp_line_continuations.cbrt"
                
  aex_situs_move_range(&(stack->stack_[0].common_), input_situs, (stack->best_match_offset_) - (stack->match_offset_), (stack->match_buffer_));

#line 1207 "src/pp/pp_line_continuations.c"
              }
              C8:;
            }
            if (!stack->discard_remaining_actions_) {
              stack->continue_at_ = 9;
              {
#line 69 "grammar/pp/pp_line_continuations.cbrt"
                
  /* A regular newline */
  if (pp_concat_output_b(pp, output_situs, output_buf, output_end, output_buf_alloc_size, &(stack->stack_[0].common_), (stack->match_buffer_), (stack->token_size_))) {
    return _AEX_PPLC_NO_MEMORY;
  }

#line 1221 "src/pp/pp_line_continuations.c"
              }
              C9:;
            }
            if (stack->need_sym_) {
                        stack->slot_0_has_common_data_ = 0;
              {
#line 43 "grammar/pp/pp_line_continuations.cbrt"
                aex_situs_cleanup(&(stack->stack_[0].common_));
#line 1230 "src/pp/pp_line_continuations.c"
              }
            }
            break;
            case 5: /* \\\n */
            /* Pattern does not have a symbol */
            stack->current_sym_ = AEX_PPLC_INPUT_END;
            stack->need_sym_ = 1; /* keep scanning */
            if (!stack->discard_remaining_actions_) {
              stack->continue_at_ = 10;
              {
#line 47 "grammar/pp/pp_line_continuations.cbrt"
                
  aex_situs_move_range(&(stack->stack_[0].common_), input_situs, (stack->best_match_offset_) - (stack->match_offset_), (stack->match_buffer_));

#line 1245 "src/pp/pp_line_continuations.c"
              }
              C10:;
            }
            if (!stack->discard_remaining_actions_) {
              stack->continue_at_ = 11;
              {
#line 76 "grammar/pp/pp_line_continuations.cbrt"
                
  /* A line continuation - we eat these */

#line 1256 "src/pp/pp_line_continuations.c"
              }
              C11:;
            }
            if (stack->need_sym_) {
                        stack->slot_0_has_common_data_ = 0;
              {
#line 43 "grammar/pp/pp_line_continuations.cbrt"
                aex_situs_cleanup(&(stack->stack_[0].common_));
#line 1265 "src/pp/pp_line_continuations.c"
              }
            }
            break;
            case 6: /* [^\n]*\\\Z */
            /* Pattern does not have a symbol */
            stack->current_sym_ = AEX_PPLC_INPUT_END;
            stack->need_sym_ = 1; /* keep scanning */
            if (!stack->discard_remaining_actions_) {
              stack->continue_at_ = 12;
              {
#line 47 "grammar/pp/pp_line_continuations.cbrt"
                
  aex_situs_move_range(&(stack->stack_[0].common_), input_situs, (stack->best_match_offset_) - (stack->match_offset_), (stack->match_buffer_));

#line 1280 "src/pp/pp_line_continuations.c"
              }
              C12:;
            }
            if (!stack->discard_remaining_actions_) {
              stack->continue_at_ = 13;
              {
#line 80 "grammar/pp/pp_line_continuations.cbrt"
                
  /* Line at the end of input ending with a line continuation */
  if (pp_concat_output_b(pp, output_situs, output_buf, output_end, output_buf_alloc_size, &(stack->stack_[0].common_), (stack->match_buffer_), (stack->token_size_))) {
    return _AEX_PPLC_NO_MEMORY;
  }

#line 1294 "src/pp/pp_line_continuations.c"
              }
              C13:;
            }
            if (stack->need_sym_) {
                        stack->slot_0_has_common_data_ = 0;
              {
#line 43 "grammar/pp/pp_line_continuations.cbrt"
                aex_situs_cleanup(&(stack->stack_[0].common_));
#line 1303 "src/pp/pp_line_continuations.c"
              }
            }
            break;
            case 7: /* [^\n]*[^\\\n] */
            /* Pattern does not have a symbol */
            stack->current_sym_ = AEX_PPLC_INPUT_END;
            stack->need_sym_ = 1; /* keep scanning */
            if (!stack->discard_remaining_actions_) {
              stack->continue_at_ = 14;
              {
#line 47 "grammar/pp/pp_line_continuations.cbrt"
                
  aex_situs_move_range(&(stack->stack_[0].common_), input_situs, (stack->best_match_offset_) - (stack->match_offset_), (stack->match_buffer_));

#line 1318 "src/pp/pp_line_continuations.c"
              }
              C14:;
            }
            if (!stack->discard_remaining_actions_) {
              stack->continue_at_ = 15;
              {
#line 87 "grammar/pp/pp_line_continuations.cbrt"
                
  /* Any line that does not end on a backslash or a newline. Given that other patterns will include the newline
   * or the end of file (and are therefore longer), this can only match lines that are part of linecontinuations. */
  /* A line that ends in a line continuation */
  if (pp_concat_output_b(pp, output_situs, output_buf, output_end, output_buf_alloc_size, &(stack->stack_[0].common_), (stack->match_buffer_), (stack->token_size_))) {
    return _AEX_PPLC_NO_MEMORY;
  }

#line 1334 "src/pp/pp_line_continuations.c"
              }
              C15:;
            }
            if (stack->need_sym_) {
                        stack->slot_0_has_common_data_ = 0;
              {
#line 43 "grammar/pp/pp_line_continuations.cbrt"
                aex_situs_cleanup(&(stack->stack_[0].common_));
#line 1343 "src/pp/pp_line_continuations.c"
              }
            }
            break;
          } /* switch */
        } /* scope guard */
        break;
        case _AEX_PPLC_OVERFLOW:
        stack->continue_at_ = 0;
        return _AEX_PPLC_OVERFLOW;
        case _AEX_PPLC_NO_MEMORY:
        stack->continue_at_ = 0;
        return _AEX_PPLC_NO_MEMORY;
        case _AEX_PPLC_FEED_ME:
        stack->continue_at_ = 0;
        /* Need more input */
        return _AEX_PPLC_FEED_ME;
        case _AEX_PPLC_END_OF_INPUT:
        stack->current_sym_ = AEX_PPLC_INPUT_END;
        stack->need_sym_ = 0;
        if (stack->mute_error_turns_) stack->mute_error_turns_--;
        break;
        case _AEX_PPLC_LEXICAL_ERROR:
        stack->continue_at_ = 0;
        /* Lexical error */
        return _AEX_PPLC_LEXICAL_ERROR;
      } /* switch */
    } /* if (need_sym_) */
    else {
      int sym;
      sym = stack->current_sym_;
      if (!stack->error_recovery_) {
        int action;
        action = aex_pplc_parse_table[aex_pplc_num_columns * stack->stack_[stack->pos_ - 1].state_ + (sym - aex_pplc_minimum_sym)];
        if (action > 0) {
          if (stack->num_stack_allocated_ == stack->pos_) {
            stack->action_preservation_ = action;
            size_t new_num_allocated;
            if (stack->num_stack_allocated_) {
              new_num_allocated = stack->num_stack_allocated_ * 2;
              if (new_num_allocated <= stack->num_stack_allocated_) {
                /* Overflow in allocation */
                return _AEX_PPLC_OVERFLOW;
              }
            }
            else {
              new_num_allocated = 16;
            }
            
            if (new_num_allocated > (SIZE_MAX / sizeof(struct aex_pplc_sym_data))) {
              /* Overflow in allocation */
              return _AEX_PPLC_OVERFLOW;
            }
            
            stack->new_buf_ = (struct aex_pplc_sym_data *)malloc(new_num_allocated * sizeof(struct aex_pplc_sym_data));
            if (!stack->new_buf_) {
              /* Out of memory */
              return _AEX_PPLC_NO_MEMORY;
            }
            stack->new_buf_num_allocated_ = new_num_allocated;
            for (stack->new_buf_sym_partial_pos_ = 0; stack->new_buf_sym_partial_pos_ < stack->pos_; ++stack->new_buf_sym_partial_pos_) {
              stack->new_buf_[stack->new_buf_sym_partial_pos_].state_ = stack->stack_[stack->new_buf_sym_partial_pos_].state_;
              stack->newbuf_pos_has_common_data_ = stack->newbuf_pos_has_sym_data_ = 0;
              stack->stack_newbuf_pos_has_common_data_ = stack->stack_newbuf_pos_has_sym_data_ = 1;
              if ((stack->new_buf_sym_partial_pos_ == 0) || (stack->new_buf_sym_partial_pos_ == 1)) {
                int need_common_move;
                need_common_move = 0;
                if (stack->new_buf_sym_partial_pos_ == 0) {
                  /* slot 0 is used for pattern matching; stack->current_sym_ describes its
                  * contents, not stack->stack_[0].state_ */
                  need_common_move = stack->slot_0_has_common_data_;
                }
                else if (stack->new_buf_sym_partial_pos_ == 1) {
                  need_common_move = stack->slot_1_has_common_data_;
                }
                if (need_common_move) {
                  stack->newbuf_pos_has_common_data_ = 1;
                  stack->continue_at_ = 16;
                  {
#line 42 "grammar/pp/pp_line_continuations.cbrt"
                    aex_situs_init(&((stack->new_buf_ + stack->new_buf_sym_partial_pos_)->common_));
#line 1424 "src/pp/pp_line_continuations.c"
                  }
                  C16:;
                  memcpy(&stack->new_buf_[stack->new_buf_sym_partial_pos_].common_, &stack->stack_[stack->new_buf_sym_partial_pos_].common_, sizeof(stack->stack_->common_));
                  stack->stack_newbuf_pos_has_common_data_ = 0;
                }
              }
              else /* not 0 or 1, but >= 2 state derived sym */ {
                stack->newbuf_pos_has_common_data_ = 1;
                stack->continue_at_ = 17;
                {
#line 42 "grammar/pp/pp_line_continuations.cbrt"
                  aex_situs_init(&((stack->new_buf_ + stack->new_buf_sym_partial_pos_)->common_));
#line 1437 "src/pp/pp_line_continuations.c"
                }
                C17:;
                memcpy(&stack->new_buf_[stack->new_buf_sym_partial_pos_].common_, &stack->stack_[stack->new_buf_sym_partial_pos_].common_, sizeof(stack->stack_->common_));
                stack->stack_newbuf_pos_has_common_data_ = 0;
              }
            }
            if (stack->stack_) free(stack->stack_);
            stack->stack_ = stack->new_buf_;
            stack->new_buf_sym_partial_pos_ = 0;
            stack->new_buf_ = NULL;
            stack->num_stack_allocated_ = stack->new_buf_num_allocated_;
            action = stack->action_preservation_;
          }
          stack->stack_[stack->pos_++].state_ = action;
          stack->top_of_stack_has_sym_data_ = 0;
          stack->top_of_stack_has_common_data_ = 0;
          
          /* Fill in the sym from the tokenizer */
          stack->need_sym_ = 1;
          stack->top_of_stack_has_common_data_ = 1;
          stack->continue_at_ = 18;
          {
#line 42 "grammar/pp/pp_line_continuations.cbrt"
            aex_situs_init(&((stack->stack_ + stack->pos_ - 1)->common_));
#line 1462 "src/pp/pp_line_continuations.c"
          }
          C18:;
          memcpy(&stack->stack_[stack->pos_ - 1].common_, &stack->stack_[0].common_, sizeof(stack->stack_[0].common_)); /*1*/
          stack->slot_0_has_common_data_ = 0;
          stack->slot_0_has_current_sym_data_ = 0;
        } /* action > 0 */
        else if (action < 0) {
          int production;
          production = -action - 1;
          stack->discard_remaining_actions_ = 0;
          stack->current_production_length_ = aex_pplc_production_lengths[production];
          stack->current_production_nonterminal_ = aex_pplc_production_syms[production];
          if (0 == production) {
            stack->pending_reset_ = 1;
            return _AEX_PPLC_FINISH;
          }
          
          memset(&stack->stack_[1], 0, sizeof(struct aex_pplc_sym_data));
          { /* scope guard */
            stack->sym_data_ = stack->stack_ + stack->pos_ - stack->current_production_length_;
            /* Note: no productions to process */
          } /* scope guard */
          
          /* Free symdata for every symbol in the production, including the first slot where we will soon
          * push nonterminal_data_reduced_to */
          for (stack->sym_idx_ = stack->pos_ - stack->current_production_length_; stack->sym_idx_ < stack->pos_; ++stack->sym_idx_) {
            {
#line 43 "grammar/pp/pp_line_continuations.cbrt"
              aex_situs_cleanup(&((stack->stack_ + stack->sym_idx_)->common_));
#line 1492 "src/pp/pp_line_continuations.c"
            }
          } /* for */
          stack->pos_ -= stack->current_production_length_;
          stack->top_of_stack_has_sym_data_ = stack->top_of_stack_has_common_data_ = 1;
          action = aex_pplc_parse_table[aex_pplc_num_columns * stack->stack_[stack->pos_ - 1].state_ + (stack->current_production_nonterminal_ - aex_pplc_minimum_sym)];
          if (action <= 0) {
            stack->continue_at_ = 0;
            /* Internal error */
            return _AEX_PPLC_INTERNAL_ERROR;
          }
          if (stack->num_stack_allocated_ == stack->pos_) {
            stack->action_preservation_ = action /* action for a "goto" shift is the ordinal */;
            size_t new_num_allocated;
            if (stack->num_stack_allocated_) {
              new_num_allocated = stack->num_stack_allocated_ * 2;
              if (new_num_allocated <= stack->num_stack_allocated_) {
                /* Overflow in allocation */
                return _AEX_PPLC_OVERFLOW;
              }
            }
            else {
              new_num_allocated = 16;
            }
            
            if (new_num_allocated > (SIZE_MAX / sizeof(struct aex_pplc_sym_data))) {
              /* Overflow in allocation */
              return _AEX_PPLC_OVERFLOW;
            }
            
            stack->new_buf_ = (struct aex_pplc_sym_data *)malloc(new_num_allocated * sizeof(struct aex_pplc_sym_data));
            if (!stack->new_buf_) {
              /* Out of memory */
              return _AEX_PPLC_NO_MEMORY;
            }
            stack->new_buf_num_allocated_ = new_num_allocated;
            for (stack->new_buf_sym_partial_pos_ = 0; stack->new_buf_sym_partial_pos_ < stack->pos_; ++stack->new_buf_sym_partial_pos_) {
              stack->new_buf_[stack->new_buf_sym_partial_pos_].state_ = stack->stack_[stack->new_buf_sym_partial_pos_].state_;
              stack->newbuf_pos_has_common_data_ = stack->newbuf_pos_has_sym_data_ = 0;
              stack->stack_newbuf_pos_has_common_data_ = stack->stack_newbuf_pos_has_sym_data_ = 1;
              if ((stack->new_buf_sym_partial_pos_ == 0) || (stack->new_buf_sym_partial_pos_ == 1)) {
                int need_common_move;
                need_common_move = 0;
                if (stack->new_buf_sym_partial_pos_ == 0) {
                  /* slot 0 is used for pattern matching; stack->current_sym_ describes its
                  * contents, not stack->stack_[0].state_ */
                  need_common_move = stack->slot_0_has_common_data_;
                }
                else if (stack->new_buf_sym_partial_pos_ == 1) {
                  need_common_move = stack->slot_1_has_common_data_;
                }
                if (need_common_move) {
                  stack->newbuf_pos_has_common_data_ = 1;
                  stack->continue_at_ = 19;
                  {
#line 42 "grammar/pp/pp_line_continuations.cbrt"
                    aex_situs_init(&((stack->new_buf_ + stack->new_buf_sym_partial_pos_)->common_));
#line 1549 "src/pp/pp_line_continuations.c"
                  }
                  C19:;
                  memcpy(&stack->new_buf_[stack->new_buf_sym_partial_pos_].common_, &stack->stack_[stack->new_buf_sym_partial_pos_].common_, sizeof(stack->stack_->common_));
                  stack->stack_newbuf_pos_has_common_data_ = 0;
                }
              }
              else /* not 0 or 1, but >= 2 state derived sym */ {
                stack->newbuf_pos_has_common_data_ = 1;
                stack->continue_at_ = 20;
                {
#line 42 "grammar/pp/pp_line_continuations.cbrt"
                  aex_situs_init(&((stack->new_buf_ + stack->new_buf_sym_partial_pos_)->common_));
#line 1562 "src/pp/pp_line_continuations.c"
                }
                C20:;
                memcpy(&stack->new_buf_[stack->new_buf_sym_partial_pos_].common_, &stack->stack_[stack->new_buf_sym_partial_pos_].common_, sizeof(stack->stack_->common_));
                stack->stack_newbuf_pos_has_common_data_ = 0;
              }
            }
            if (stack->stack_) free(stack->stack_);
            stack->stack_ = stack->new_buf_;
            stack->new_buf_sym_partial_pos_ = 0;
            stack->new_buf_ = NULL;
            stack->num_stack_allocated_ = stack->new_buf_num_allocated_;
            action /* action for a "goto" shift is the ordinal */ = stack->action_preservation_;
          }
          stack->stack_[stack->pos_++].state_ = action /* action for a "goto" shift is the ordinal */;
          stack->top_of_stack_has_sym_data_ = 0;
          stack->top_of_stack_has_common_data_ = 0;
          stack->top_of_stack_has_common_data_ = 1;
          stack->continue_at_ = 21;
          {
#line 42 "grammar/pp/pp_line_continuations.cbrt"
            aex_situs_init(&((stack->stack_ + stack->pos_ - 1)->common_));
#line 1584 "src/pp/pp_line_continuations.c"
          }
          C21:;
          memcpy(&stack->stack_[stack->pos_ - 1].common_, &stack->stack_[1].common_, sizeof(stack->stack_->common_));
          stack->slot_1_has_common_data_ = 0;
          stack->slot_1_has_sym_data_ = 0;
        } /* action < 0 */
        else /* action == 0 */ {
          /* check if we can recover using an error token. */
          size_t n;
          for (n = 0; n < stack->pos_; ++n) {
            stack->current_err_action_ = aex_pplc_parse_table[aex_pplc_num_columns * stack->stack_[n].state_ + (3 /* error token */ - aex_pplc_minimum_sym)];
            if (stack->current_err_action_ > 0) {
              /* we can transition on the error token somewhere on the stack */
              break;
            }
          }
          if (n != stack->pos_) {
            /* Enter error-token recovery mode given that such a recovery is possible */
            stack->error_recovery_ = (n != stack->pos_);
          }
          else {
            if (sym != AEX_PPLC_INPUT_END) {
              /* Retain EOF but discard any other sym so we make progress */
              stack->need_sym_ = 1;
              {
#line 43 "grammar/pp/pp_line_continuations.cbrt"
                aex_situs_cleanup(&(stack->stack_[0].common_));
#line 1612 "src/pp/pp_line_continuations.c"
              }
            }
          }
          /* Issue the error here */
          if (!stack->mute_error_turns_) {
            stack->mute_error_turns_ = 3;
            stack->continue_at_ = 0;
            /* Syntax error */
            return _AEX_PPLC_SYNTAX_ERROR;
          }
          else {
            stack->mute_error_turns_--;
            if (sym == AEX_PPLC_INPUT_END) {
              /* EOF means we cannot shift to recover, and errors are muted, so return completion */
              stack->pending_reset_ = 1;
              return _AEX_PPLC_FINISH;
            }
          }
        }
      } /* !stack->error_recovery_ */
      if (stack->error_recovery_) {
        size_t n;
        n = stack->pos_;
        if (n) {
          do {
            --n;
            /* Can we shift an error token? */
            stack->current_err_action_ = aex_pplc_parse_table[aex_pplc_num_columns * stack->stack_[n].state_ + (3 /* error token */ - aex_pplc_minimum_sym)];
            if (stack->current_err_action_ > 0) {
              /* Does the resulting state accept the current symbol? */
              int err_sym_action;
              sym = stack->current_sym_; /* recover on the edge case we exited while moving data */
              err_sym_action = aex_pplc_parse_table[aex_pplc_num_columns * stack->current_err_action_ + (sym - aex_pplc_minimum_sym)];
              if (err_sym_action) {
                /* Current symbol is accepted, recover error condition by shifting the error token and then process the symbol as usual */
                /* Free symdata for every symbol up to the state where we will shift the error token */
                for (stack->sym_idx_ = n + 1; stack->sym_idx_ < stack->pos_; ++stack->sym_idx_) {
                  {
#line 43 "grammar/pp/pp_line_continuations.cbrt"
                    aex_situs_cleanup(&((stack->stack_ + stack->sym_idx_)->common_));
#line 1653 "src/pp/pp_line_continuations.c"
                  }
                } /* for */
                stack->pos_ = n + 1;
                stack->top_of_stack_has_sym_data_ = stack->top_of_stack_has_common_data_ = 1;
                if (stack->num_stack_allocated_ == stack->pos_) {
                  stack->action_preservation_ = stack->current_err_action_;
                  size_t new_num_allocated;
                  if (stack->num_stack_allocated_) {
                    new_num_allocated = stack->num_stack_allocated_ * 2;
                    if (new_num_allocated <= stack->num_stack_allocated_) {
                      /* Overflow in allocation */
                      return _AEX_PPLC_OVERFLOW;
                    }
                  }
                  else {
                    new_num_allocated = 16;
                  }
                  
                  if (new_num_allocated > (SIZE_MAX / sizeof(struct aex_pplc_sym_data))) {
                    /* Overflow in allocation */
                    return _AEX_PPLC_OVERFLOW;
                  }
                  
                  stack->new_buf_ = (struct aex_pplc_sym_data *)malloc(new_num_allocated * sizeof(struct aex_pplc_sym_data));
                  if (!stack->new_buf_) {
                    /* Out of memory */
                    return _AEX_PPLC_NO_MEMORY;
                  }
                  stack->new_buf_num_allocated_ = new_num_allocated;
                  for (stack->new_buf_sym_partial_pos_ = 0; stack->new_buf_sym_partial_pos_ < stack->pos_; ++stack->new_buf_sym_partial_pos_) {
                    stack->new_buf_[stack->new_buf_sym_partial_pos_].state_ = stack->stack_[stack->new_buf_sym_partial_pos_].state_;
                    stack->newbuf_pos_has_common_data_ = stack->newbuf_pos_has_sym_data_ = 0;
                    stack->stack_newbuf_pos_has_common_data_ = stack->stack_newbuf_pos_has_sym_data_ = 1;
                    if ((stack->new_buf_sym_partial_pos_ == 0) || (stack->new_buf_sym_partial_pos_ == 1)) {
                      int need_common_move;
                      need_common_move = 0;
                      if (stack->new_buf_sym_partial_pos_ == 0) {
                        /* slot 0 is used for pattern matching; stack->current_sym_ describes its
                        * contents, not stack->stack_[0].state_ */
                        need_common_move = stack->slot_0_has_common_data_;
                      }
                      else if (stack->new_buf_sym_partial_pos_ == 1) {
                        need_common_move = stack->slot_1_has_common_data_;
                      }
                      if (need_common_move) {
                        stack->newbuf_pos_has_common_data_ = 1;
                        stack->continue_at_ = 22;
                        {
#line 42 "grammar/pp/pp_line_continuations.cbrt"
                          aex_situs_init(&((stack->new_buf_ + stack->new_buf_sym_partial_pos_)->common_));
#line 1704 "src/pp/pp_line_continuations.c"
                        }
                        C22:;
                        memcpy(&stack->new_buf_[stack->new_buf_sym_partial_pos_].common_, &stack->stack_[stack->new_buf_sym_partial_pos_].common_, sizeof(stack->stack_->common_));
                        stack->stack_newbuf_pos_has_common_data_ = 0;
                      }
                    }
                    else /* not 0 or 1, but >= 2 state derived sym */ {
                      stack->newbuf_pos_has_common_data_ = 1;
                      stack->continue_at_ = 23;
                      {
#line 42 "grammar/pp/pp_line_continuations.cbrt"
                        aex_situs_init(&((stack->new_buf_ + stack->new_buf_sym_partial_pos_)->common_));
#line 1717 "src/pp/pp_line_continuations.c"
                      }
                      C23:;
                      memcpy(&stack->new_buf_[stack->new_buf_sym_partial_pos_].common_, &stack->stack_[stack->new_buf_sym_partial_pos_].common_, sizeof(stack->stack_->common_));
                      stack->stack_newbuf_pos_has_common_data_ = 0;
                    }
                  }
                  if (stack->stack_) free(stack->stack_);
                  stack->stack_ = stack->new_buf_;
                  stack->new_buf_sym_partial_pos_ = 0;
                  stack->new_buf_ = NULL;
                  stack->num_stack_allocated_ = stack->new_buf_num_allocated_;
                  stack->current_err_action_ = stack->action_preservation_;
                }
                stack->stack_[stack->pos_++].state_ = stack->current_err_action_;
                stack->top_of_stack_has_sym_data_ = 0;
                stack->top_of_stack_has_common_data_ = 0;
                stack->error_recovery_ = 0;
                /* Break out of do { .. } while loop, we've recovered */
                break;
              } /* if (err_sym_action) (if the current sym can continue after an error transition) */
            } /* if (stack->current_err_action_) (if the state at position 'n' can accept an error transition) */
          } while (n);
        }
        if (stack->error_recovery_) {
          /* Did not yet recover, discard current sym and get next */
          if (stack->current_sym_ == AEX_PPLC_INPUT_END) {
            /* EOF means we cannot shift to recover, so return completion */
            stack->pending_reset_ = 1;
            return _AEX_PPLC_FINISH;
          }
          stack->need_sym_ = 1;
          {
#line 43 "grammar/pp/pp_line_continuations.cbrt"
            aex_situs_cleanup(&(stack->stack_[0].common_));
#line 1752 "src/pp/pp_line_continuations.c"
          }
        }
      } /* stack->error_recovery_ */
    }
  } /* for (;;) */
}

int aex_pplc_parse(struct aex_pplc_stack *stack, int sym, struct preprocessor *pp, char **output_buf, size_t *output_end, size_t *output_buf_alloc_size, struct situs *output_situs, struct situs *input_situs) {
  if (stack->pending_reset_) {
    int r;
    r = aex_pplc_stack_reset(stack);
    if (r) return r;
  }
    switch (stack->continue_at_) {
    case 0: break; /* fall through to regular code path */
    case 1: goto C1;
    case 2: goto C2;
    case 3: goto C3;
    case 4: goto C4;
    case 5: goto C5;
    case 6: goto C6;
    case 7: goto C7;
    case 8: goto C8;
  } /* continuation switch */
if (stack->mute_error_turns_) stack->mute_error_turns_--;
  for (;;) {
    if (!stack->error_recovery_) {
      int action;
      action = aex_pplc_parse_table[aex_pplc_num_columns * stack->stack_[stack->pos_ - 1].state_ + (sym - aex_pplc_minimum_sym)];
      if (action > 0) {
        if (stack->num_stack_allocated_ == stack->pos_) {
          stack->action_preservation_ = action;
          size_t new_num_allocated;
          if (stack->num_stack_allocated_) {
            new_num_allocated = stack->num_stack_allocated_ * 2;
            if (new_num_allocated <= stack->num_stack_allocated_) {
              /* Overflow in allocation */
              return _AEX_PPLC_OVERFLOW;
            }
          }
          else {
            new_num_allocated = 16;
          }
          
          if (new_num_allocated > (SIZE_MAX / sizeof(struct aex_pplc_sym_data))) {
            /* Overflow in allocation */
            return _AEX_PPLC_OVERFLOW;
          }
          
          stack->new_buf_ = (struct aex_pplc_sym_data *)malloc(new_num_allocated * sizeof(struct aex_pplc_sym_data));
          if (!stack->new_buf_) {
            /* Out of memory */
            return _AEX_PPLC_NO_MEMORY;
          }
          stack->new_buf_num_allocated_ = new_num_allocated;
          for (stack->new_buf_sym_partial_pos_ = 0; stack->new_buf_sym_partial_pos_ < stack->pos_; ++stack->new_buf_sym_partial_pos_) {
            stack->new_buf_[stack->new_buf_sym_partial_pos_].state_ = stack->stack_[stack->new_buf_sym_partial_pos_].state_;
            stack->newbuf_pos_has_common_data_ = stack->newbuf_pos_has_sym_data_ = 0;
            stack->stack_newbuf_pos_has_common_data_ = stack->stack_newbuf_pos_has_sym_data_ = 1;
            if ((stack->new_buf_sym_partial_pos_ == 0) || (stack->new_buf_sym_partial_pos_ == 1)) {
              int need_common_move;
              need_common_move = 0;
              if (stack->new_buf_sym_partial_pos_ == 0) {
                /* slot 0 is used for pattern matching; stack->current_sym_ describes its
                * contents, not stack->stack_[0].state_ */
                need_common_move = stack->slot_0_has_common_data_;
              }
              else if (stack->new_buf_sym_partial_pos_ == 1) {
                need_common_move = stack->slot_1_has_common_data_;
              }
              if (need_common_move) {
                stack->newbuf_pos_has_common_data_ = 1;
                stack->continue_at_ = 1;
                {
#line 42 "grammar/pp/pp_line_continuations.cbrt"
                  aex_situs_init(&((stack->new_buf_ + stack->new_buf_sym_partial_pos_)->common_));
#line 1829 "src/pp/pp_line_continuations.c"
                }
                C1:;
                memcpy(&stack->new_buf_[stack->new_buf_sym_partial_pos_].common_, &stack->stack_[stack->new_buf_sym_partial_pos_].common_, sizeof(stack->stack_->common_));
                stack->stack_newbuf_pos_has_common_data_ = 0;
              }
            }
            else /* not 0 or 1, but >= 2 state derived sym */ {
              stack->newbuf_pos_has_common_data_ = 1;
              stack->continue_at_ = 2;
              {
#line 42 "grammar/pp/pp_line_continuations.cbrt"
                aex_situs_init(&((stack->new_buf_ + stack->new_buf_sym_partial_pos_)->common_));
#line 1842 "src/pp/pp_line_continuations.c"
              }
              C2:;
              memcpy(&stack->new_buf_[stack->new_buf_sym_partial_pos_].common_, &stack->stack_[stack->new_buf_sym_partial_pos_].common_, sizeof(stack->stack_->common_));
              stack->stack_newbuf_pos_has_common_data_ = 0;
            }
          }
          if (stack->stack_) free(stack->stack_);
          stack->stack_ = stack->new_buf_;
          stack->new_buf_sym_partial_pos_ = 0;
          stack->new_buf_ = NULL;
          stack->num_stack_allocated_ = stack->new_buf_num_allocated_;
          action = stack->action_preservation_;
        }
        stack->stack_[stack->pos_++].state_ = action;
        stack->top_of_stack_has_sym_data_ = 0;
        stack->top_of_stack_has_common_data_ = 0;
        
        stack->sym_data_ = stack->stack_ + stack->pos_ - 1;
        stack->top_of_stack_has_sym_data_ = 0;
        stack->top_of_stack_has_common_data_ = 1;
        stack->continue_at_ = 3;
        {
#line 42 "grammar/pp/pp_line_continuations.cbrt"
          aex_situs_init(&(stack->sym_data_->common_));
#line 1867 "src/pp/pp_line_continuations.c"
        }
        C3:;
        stack->continue_at_ = 0;
        /* Next token */
        return _AEX_PPLC_FEED_ME;
      } /* action > 0 */
      else if (action < 0) {
        int production;
        production = -action - 1;
        stack->discard_remaining_actions_ = 0;
        stack->current_production_length_ = aex_pplc_production_lengths[production];
        stack->current_production_nonterminal_ = aex_pplc_production_syms[production];
        if (0 == production) {
          stack->pending_reset_ = 1;
          /* Synth S we're done */
          return _AEX_PPLC_FINISH;
        }
        
        memset(&stack->stack_[1], 0, sizeof(struct aex_pplc_sym_data));
        { /* scope guard */
          stack->sym_data_ = stack->stack_ + stack->pos_ - stack->current_production_length_;
          /* Note: no productions to process */
        } /* scope guard */
        
        /* Free symdata for every symbol in the production, including the first slot where we will soon
        * push nonterminal_data_reduced_to */
        for (stack->sym_idx_ = stack->pos_ - stack->current_production_length_; stack->sym_idx_ < stack->pos_; ++stack->sym_idx_) {
          {
#line 43 "grammar/pp/pp_line_continuations.cbrt"
            aex_situs_cleanup(&((stack->stack_ + stack->sym_idx_)->common_));
#line 1898 "src/pp/pp_line_continuations.c"
          }
        } /* for */
        stack->pos_ -= stack->current_production_length_;
        stack->top_of_stack_has_sym_data_ = stack->top_of_stack_has_common_data_ = 1;
        action = aex_pplc_parse_table[aex_pplc_num_columns * stack->stack_[stack->pos_ - 1].state_ + (stack->current_production_nonterminal_ - aex_pplc_minimum_sym)];
        if (action <= 0) {
          stack->continue_at_ = 0;
          /* Internal error */
          return _AEX_PPLC_INTERNAL_ERROR;
        }
        if (stack->num_stack_allocated_ == stack->pos_) {
          stack->action_preservation_ = action /* action for a "goto" shift is the ordinal */;
          size_t new_num_allocated;
          if (stack->num_stack_allocated_) {
            new_num_allocated = stack->num_stack_allocated_ * 2;
            if (new_num_allocated <= stack->num_stack_allocated_) {
              /* Overflow in allocation */
              return _AEX_PPLC_OVERFLOW;
            }
          }
          else {
            new_num_allocated = 16;
          }
          
          if (new_num_allocated > (SIZE_MAX / sizeof(struct aex_pplc_sym_data))) {
            /* Overflow in allocation */
            return _AEX_PPLC_OVERFLOW;
          }
          
          stack->new_buf_ = (struct aex_pplc_sym_data *)malloc(new_num_allocated * sizeof(struct aex_pplc_sym_data));
          if (!stack->new_buf_) {
            /* Out of memory */
            return _AEX_PPLC_NO_MEMORY;
          }
          stack->new_buf_num_allocated_ = new_num_allocated;
          for (stack->new_buf_sym_partial_pos_ = 0; stack->new_buf_sym_partial_pos_ < stack->pos_; ++stack->new_buf_sym_partial_pos_) {
            stack->new_buf_[stack->new_buf_sym_partial_pos_].state_ = stack->stack_[stack->new_buf_sym_partial_pos_].state_;
            stack->newbuf_pos_has_common_data_ = stack->newbuf_pos_has_sym_data_ = 0;
            stack->stack_newbuf_pos_has_common_data_ = stack->stack_newbuf_pos_has_sym_data_ = 1;
            if ((stack->new_buf_sym_partial_pos_ == 0) || (stack->new_buf_sym_partial_pos_ == 1)) {
              int need_common_move;
              need_common_move = 0;
              if (stack->new_buf_sym_partial_pos_ == 0) {
                /* slot 0 is used for pattern matching; stack->current_sym_ describes its
                * contents, not stack->stack_[0].state_ */
                need_common_move = stack->slot_0_has_common_data_;
              }
              else if (stack->new_buf_sym_partial_pos_ == 1) {
                need_common_move = stack->slot_1_has_common_data_;
              }
              if (need_common_move) {
                stack->newbuf_pos_has_common_data_ = 1;
                stack->continue_at_ = 4;
                {
#line 42 "grammar/pp/pp_line_continuations.cbrt"
                  aex_situs_init(&((stack->new_buf_ + stack->new_buf_sym_partial_pos_)->common_));
#line 1955 "src/pp/pp_line_continuations.c"
                }
                C4:;
                memcpy(&stack->new_buf_[stack->new_buf_sym_partial_pos_].common_, &stack->stack_[stack->new_buf_sym_partial_pos_].common_, sizeof(stack->stack_->common_));
                stack->stack_newbuf_pos_has_common_data_ = 0;
              }
            }
            else /* not 0 or 1, but >= 2 state derived sym */ {
              stack->newbuf_pos_has_common_data_ = 1;
              stack->continue_at_ = 5;
              {
#line 42 "grammar/pp/pp_line_continuations.cbrt"
                aex_situs_init(&((stack->new_buf_ + stack->new_buf_sym_partial_pos_)->common_));
#line 1968 "src/pp/pp_line_continuations.c"
              }
              C5:;
              memcpy(&stack->new_buf_[stack->new_buf_sym_partial_pos_].common_, &stack->stack_[stack->new_buf_sym_partial_pos_].common_, sizeof(stack->stack_->common_));
              stack->stack_newbuf_pos_has_common_data_ = 0;
            }
          }
          if (stack->stack_) free(stack->stack_);
          stack->stack_ = stack->new_buf_;
          stack->new_buf_sym_partial_pos_ = 0;
          stack->new_buf_ = NULL;
          stack->num_stack_allocated_ = stack->new_buf_num_allocated_;
          action /* action for a "goto" shift is the ordinal */ = stack->action_preservation_;
        }
        stack->stack_[stack->pos_++].state_ = action /* action for a "goto" shift is the ordinal */;
        stack->top_of_stack_has_sym_data_ = 0;
        stack->top_of_stack_has_common_data_ = 0;
        stack->top_of_stack_has_common_data_ = 1;
        stack->continue_at_ = 6;
        {
#line 42 "grammar/pp/pp_line_continuations.cbrt"
          aex_situs_init(&((stack->stack_ + stack->pos_ - 1)->common_));
#line 1990 "src/pp/pp_line_continuations.c"
        }
        C6:;
        memcpy(&stack->stack_[stack->pos_ - 1].common_, &stack->stack_[1].common_, sizeof(stack->stack_->common_));
        stack->slot_1_has_common_data_ = 0;
        stack->slot_1_has_sym_data_ = 0;
      } /* action < 0 */
      else /* action == 0 */ {
        /* check if we can recover using an error token. */
        size_t n;
        for (n = 0; n < stack->pos_; ++n) {
          stack->current_err_action_ = aex_pplc_parse_table[aex_pplc_num_columns * stack->stack_[n].state_ + (3 /* error token */ - aex_pplc_minimum_sym)];
          if (stack->current_err_action_ > 0) {
            /* we can transition on the error token somewhere on the stack */
            break;
          }
        }
        /* Enter error-token recovery mode given that such a recovery is possible */
        stack->error_recovery_ = (n != stack->pos_);
        /* Issue the error here */
        if (!stack->mute_error_turns_) {
          stack->mute_error_turns_ = 3;
          stack->continue_at_ = 0;
          /* Syntax error */
          return _AEX_PPLC_SYNTAX_ERROR;
        }
        else {
          stack->mute_error_turns_--;
          if (sym == AEX_PPLC_INPUT_END) {
            /* EOF means we cannot shift to recover, and errors are muted, so return completion */
            stack->pending_reset_ = 1;
            return _AEX_PPLC_FINISH;
          }
          /* Retain EOF but discard any other sym so we make progress */
          stack->continue_at_ = 0;
          /* Next token */
          return _AEX_PPLC_FEED_ME;
        }
      }
    } /* !stack->error_recovery_ */
    if (stack->error_recovery_) {
      size_t n;
      n = stack->pos_;
      if (n) {
        do {
          --n;
          /* Can we shift an error token? */
          stack->current_err_action_ = aex_pplc_parse_table[aex_pplc_num_columns * stack->stack_[n].state_ + (3 /* error token */ - aex_pplc_minimum_sym)];
          if (stack->current_err_action_ > 0) {
            /* Does the resulting state accept the current symbol? */
            int err_sym_action;
            err_sym_action = aex_pplc_parse_table[aex_pplc_num_columns * stack->current_err_action_ + (sym - aex_pplc_minimum_sym)];
            if (err_sym_action) {
              /* Current symbol is accepted, recover error condition by shifting the error token and then process the symbol as usual */
              /* Free symdata for every symbol up to the state where we will shift the error token */
              for (stack->sym_idx_ = n + 1; stack->sym_idx_ < stack->pos_; ++stack->sym_idx_) {
                {
#line 43 "grammar/pp/pp_line_continuations.cbrt"
                  aex_situs_cleanup(&((stack->stack_ + stack->sym_idx_)->common_));
#line 2049 "src/pp/pp_line_continuations.c"
                }
              } /* for */
              stack->pos_ = n + 1;
              stack->top_of_stack_has_sym_data_ = stack->top_of_stack_has_common_data_ = 1;
              /* Push the state of the error transition */
              if (stack->num_stack_allocated_ == stack->pos_) {
                stack->action_preservation_ = stack->current_err_action_;
                size_t new_num_allocated;
                if (stack->num_stack_allocated_) {
                  new_num_allocated = stack->num_stack_allocated_ * 2;
                  if (new_num_allocated <= stack->num_stack_allocated_) {
                    /* Overflow in allocation */
                    return _AEX_PPLC_OVERFLOW;
                  }
                }
                else {
                  new_num_allocated = 16;
                }
                
                if (new_num_allocated > (SIZE_MAX / sizeof(struct aex_pplc_sym_data))) {
                  /* Overflow in allocation */
                  return _AEX_PPLC_OVERFLOW;
                }
                
                stack->new_buf_ = (struct aex_pplc_sym_data *)malloc(new_num_allocated * sizeof(struct aex_pplc_sym_data));
                if (!stack->new_buf_) {
                  /* Out of memory */
                  return _AEX_PPLC_NO_MEMORY;
                }
                stack->new_buf_num_allocated_ = new_num_allocated;
                for (stack->new_buf_sym_partial_pos_ = 0; stack->new_buf_sym_partial_pos_ < stack->pos_; ++stack->new_buf_sym_partial_pos_) {
                  stack->new_buf_[stack->new_buf_sym_partial_pos_].state_ = stack->stack_[stack->new_buf_sym_partial_pos_].state_;
                  stack->newbuf_pos_has_common_data_ = stack->newbuf_pos_has_sym_data_ = 0;
                  stack->stack_newbuf_pos_has_common_data_ = stack->stack_newbuf_pos_has_sym_data_ = 1;
                  if ((stack->new_buf_sym_partial_pos_ == 0) || (stack->new_buf_sym_partial_pos_ == 1)) {
                    int need_common_move;
                    need_common_move = 0;
                    if (stack->new_buf_sym_partial_pos_ == 0) {
                      /* slot 0 is used for pattern matching; stack->current_sym_ describes its
                      * contents, not stack->stack_[0].state_ */
                      need_common_move = stack->slot_0_has_common_data_;
                    }
                    else if (stack->new_buf_sym_partial_pos_ == 1) {
                      need_common_move = stack->slot_1_has_common_data_;
                    }
                    if (need_common_move) {
                      stack->newbuf_pos_has_common_data_ = 1;
                      stack->continue_at_ = 7;
                      {
#line 42 "grammar/pp/pp_line_continuations.cbrt"
                        aex_situs_init(&((stack->new_buf_ + stack->new_buf_sym_partial_pos_)->common_));
#line 2101 "src/pp/pp_line_continuations.c"
                      }
                      C7:;
                      memcpy(&stack->new_buf_[stack->new_buf_sym_partial_pos_].common_, &stack->stack_[stack->new_buf_sym_partial_pos_].common_, sizeof(stack->stack_->common_));
                      stack->stack_newbuf_pos_has_common_data_ = 0;
                    }
                  }
                  else /* not 0 or 1, but >= 2 state derived sym */ {
                    stack->newbuf_pos_has_common_data_ = 1;
                    stack->continue_at_ = 8;
                    {
#line 42 "grammar/pp/pp_line_continuations.cbrt"
                      aex_situs_init(&((stack->new_buf_ + stack->new_buf_sym_partial_pos_)->common_));
#line 2114 "src/pp/pp_line_continuations.c"
                    }
                    C8:;
                    memcpy(&stack->new_buf_[stack->new_buf_sym_partial_pos_].common_, &stack->stack_[stack->new_buf_sym_partial_pos_].common_, sizeof(stack->stack_->common_));
                    stack->stack_newbuf_pos_has_common_data_ = 0;
                  }
                }
                if (stack->stack_) free(stack->stack_);
                stack->stack_ = stack->new_buf_;
                stack->new_buf_sym_partial_pos_ = 0;
                stack->new_buf_ = NULL;
                stack->num_stack_allocated_ = stack->new_buf_num_allocated_;
                stack->current_err_action_ = stack->action_preservation_;
              }
              stack->stack_[stack->pos_++].state_ = stack->current_err_action_;
              stack->top_of_stack_has_sym_data_ = 0;
              stack->top_of_stack_has_common_data_ = 0;
              stack->error_recovery_ = 0;
              /* Break out of do { .. } while loop, we've recovered */
              break;
            } /* if (err_sym_action) (if the current sym can continue after an error transition) */
          } /* if (stack->current_err_action_) (if the state at position 'n' can accept an error transition) */
        } while (n);
      }
      if (stack->error_recovery_) {
        /* Did not yet recover, discard current sym and get next */
        if (sym == AEX_PPLC_INPUT_END) {
          /* EOF means we cannot shift to recover, so return completion */
          stack->pending_reset_ = 1;
          return _AEX_PPLC_FINISH;
        }
        stack->continue_at_ = 0;
        /* Next token */
        return _AEX_PPLC_FEED_ME;
      }
    } /* stack->error_recovery_ */
  } /* for (;;) */
}
/* --------- END OF GENERATED CODE ------------ */
