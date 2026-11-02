#line 1 "grammar/pp/pp_trigraphs.cbrt"
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
struct aex_pptg_sym_data {
  #ifdef __cplusplus
  // clear destructor in case C++ symbol types have non-trivial destructors
  // (we invoke their destructors explicitly)
  ~aex_pptg_sym_data() = delete;
  #endif
  int state_;
  struct   situs common_;
};
static const int aex_pptg_scan_table_grouped_rex_[] = {
  /*
   00  01  02  03  04  05  06  07  08  09  0A  0B  0C  0D  0E  0F */
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  3,  1,  1,  1,  1,
    0,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  4,  2,  2,  2,  2,
    0,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  6,  3,  3,  3,  3,
    0,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  7,  4,  4,  4,  4,
    0,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  4,  5,  5,  5,  5,
    0,  8,  9, 10, 11, 12, 13, 14, 15, 16, 17, 18,  6,  6,  6,  6,
    0,  8,  0,  0,  0,  0,  0,  0,  0,  0,  0, 18,  7,  7,  7,  7,
    0,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  4,  8,  8,  8,  8,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  9,  9,  9,  9,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 10, 10, 10, 10,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 11, 11, 11, 11,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 12, 12, 12, 12,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 13, 13, 13, 13,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 14, 14, 14, 14,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 15, 15, 15, 15,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 16, 16, 16, 16,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 17, 17, 17, 17,
    0, 19,  2,  2,  2,  2,  2,  2,  2,  2,  2, 20, 18, 18, 18, 18,
    0,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  4, 19, 19, 19, 19,
    0, 21, 22, 22, 22, 22, 22, 22, 22, 22, 22, 20, 20, 20, 20, 20,
    0,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  4, 21, 21, 21, 21,
    0,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  4, 22, 22, 22, 22
};
static const size_t aex_pptg_num_scan_table_grouped_columns_ = 16;
static const int aex_pptg_utf8_decoder_[] = {
  /*
   00  01  02  03  04  05  06  07  08  09  0A  0B  0C  0D  0E  0F  10  11  12  13  14  15  16  17  18  19  1A  1B  1C  1D  1E  1F  20  21  22  23  24  25  26  27  28  29  2A  2B  2C  2D  2E  2F  30  31  32  33  34  35  36  37  38  39  3A  3B  3C  3D  3E  3F  40  41  42  43  44  45  46  47  48  49  4A  4B  4C  4D  4E  4F  50  51  52  53  54  55  56  57  58  59  5A  5B  5C  5D  5E  5F  60  61  62  63  64  65  66  67  68  69  6A  6B  6C  6D  6E  6F  70  71  72  73  74  75  76  77  78  79  7A  7B  7C  7D  7E  7F  80  81  82  83  84  85  86  87  88  89  8A  8B  8C  8D  8E  8F  90  91  92  93  94  95  96  97  98  99  9A  9B  9C  9D  9E  9F  A0  A1  A2  A3  A4  A5  A6  A7  A8  A9  AA  AB  AC  AD  AE  AF  B0  B1  B2  B3  B4  B5  B6  B7  B8  B9  BA  BB  BC  BD  BE  BF  C0  C1  C2  C3  C4  C5  C6  C7  C8  C9  CA  CB  CC  CD  CE  CF  D0  D1  D2  D3  D4  D5  D6  D7  D8  D9  DA  DB  DC  DD  DE  DF  E0  E1  E2  E3  E4  E5  E6  E7  E8  E9  EA  EB  EC  ED  EE  EF  F0  F1  F2  F3  F4  F5  F6  F7  F8  F9  FA  FB  FC  FD  FE  FF */
    1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  2,  1,  1,  1,  1,  1,  3,  4,  5,  1,  1,  1,  6,  1,  7,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  8,  9, 10, 11,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -2, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -4, -5, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -7, -8, -9, -9, -9,-10, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
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
static const size_t aex_pptg_scan_actions_rex[] = { 0, 0, 10, 0, 0, 10, 0, 0, 10, 7, 5, 2, 4, 9, 3, 6, 1, 8, 10, 10, 10, 10, 10 };
static const int aex_pptg_minimum_sym = 4;
static const size_t aex_pptg_num_columns = 2;
static const int aex_pptg_parse_table[] = {
  -1, 0,
};
static const size_t aex_pptg_production_lengths[] = {
  0
};
static const int aex_pptg_production_syms[] = {
  5
};

#ifndef CARB_AEX_PPTG_SRCPPPP_TRIGRAPHS_H_INCLUDED
struct aex_pptg_stack {
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
  struct aex_pptg_sym_data *stack_;
  struct aex_pptg_sym_data *sym_data_;
  struct aex_pptg_sym_data *new_buf_;
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
#define _AEX_PPTG_FINISH 0
#define _AEX_PPTG_MATCH 1
#define _AEX_PPTG_OVERFLOW 2
#define _AEX_PPTG_NO_MEMORY 3
#define _AEX_PPTG_FEED_ME 4
#define _AEX_PPTG_END_OF_INPUT 5
#define _AEX_PPTG_SYNTAX_ERROR 6
#define _AEX_PPTG_LEXICAL_ERROR 7
#define _AEX_PPTG_INTERNAL_ERROR 8

#define AEX_PPTG_ERROR 3
#define AEX_PPTG_INPUT_END 4


#define M_AEX_PPTG_DEFAULT 1

#endif /* CARB_AEX_PPTG_SRCPPPP_TRIGRAPHS_H_INCLUDED */

void aex_pptg_stack_init(struct aex_pptg_stack *stack) {
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
  stack->current_mode_start_state_ = M_AEX_PPTG_DEFAULT;
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

void aex_pptg_stack_cleanup(struct aex_pptg_stack *stack) {
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
#line 44 "grammar/pp/pp_trigraphs.cbrt"
        aex_situs_cleanup(&((stack->stack_ + n)->common_));
#line 290 "src/pp/pp_trigraphs.c"
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
#line 44 "grammar/pp/pp_trigraphs.cbrt"
          aex_situs_cleanup(&((stack->new_buf_ + n)->common_));
#line 331 "src/pp/pp_trigraphs.c"
        }
        
      }
    }
    free(stack->new_buf_);
    stack->new_buf_ = NULL;
  }
  if (stack->stack_) free(stack->stack_);
  if (stack->match_buffer_) free(stack->match_buffer_);
}

int aex_pptg_stack_reset(struct aex_pptg_stack *stack) {
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
#line 44 "grammar/pp/pp_trigraphs.cbrt"
        aex_situs_cleanup(&((stack->stack_ + n)->common_));
#line 382 "src/pp/pp_trigraphs.c"
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
#line 44 "grammar/pp/pp_trigraphs.cbrt"
          aex_situs_cleanup(&((stack->new_buf_ + n)->common_));
#line 423 "src/pp/pp_trigraphs.c"
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
        return _AEX_PPTG_OVERFLOW;
      }
    }
    else {
      new_num_allocated = 16;
    }
    
    if (new_num_allocated > (SIZE_MAX / sizeof(struct aex_pptg_sym_data))) {
      /* Overflow in allocation */
      stack->continue_at_ = 0;
      return _AEX_PPTG_OVERFLOW;
    }
    
    void *p = realloc(stack->stack_, new_num_allocated * sizeof(struct aex_pptg_sym_data));
    if (!p) {
      /* Out of memory */
      stack->continue_at_ = 0;
      return _AEX_PPTG_NO_MEMORY;
    }
    stack->stack_ = (struct aex_pptg_sym_data *)p;
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

int aex_pptg_stack_can_recover(struct aex_pptg_stack *stack) {
  return !!stack->error_recovery_;
}

int aex_pptg_stack_accepts(struct aex_pptg_stack *stack, int sym) {
  if (!stack->pos_) return 0;
  return 0 != aex_pptg_parse_table[aex_pptg_num_columns * stack->stack_[stack->pos_ - 1].state_ + (sym - aex_pptg_minimum_sym)];}

void aex_pptg_set_mode(struct aex_pptg_stack *stack, int mode) {
  if (stack->current_mode_start_state_ == stack->scan_state_) {
    stack->scan_state_ = mode;
  }
  stack->current_mode_start_state_ = mode;
}

int aex_pptg_mode(struct aex_pptg_stack *stack) {
  return (int)stack->current_mode_start_state_;
}

static int aex_pptg_append_match_buffer(struct aex_pptg_stack *stack, const char *s, size_t len) {
  size_t size_needed = len;
  size_needed += stack->match_buffer_size_;
  if (size_needed < stack->match_buffer_size_) {
    return _AEX_PPTG_OVERFLOW;
  }
  if (size_needed == SIZE_MAX) {
    /* cannot fit null terminator */
    return _AEX_PPTG_OVERFLOW;
  }
  size_needed++; /* null terminator */
  if (size_needed < 128) {
    size_needed = 128;
  }
  if (size_needed > stack->match_buffer_size_allocated_) {
    /* intent of code: grow buffer size by powers of 2-1, unless our needs require more now. */
    size_t size_to_allocate = stack->match_buffer_size_allocated_ * 2 + 1;
    if (size_to_allocate <= stack->match_buffer_size_allocated_) {
      return _AEX_PPTG_OVERFLOW;
    }
    if (size_to_allocate < size_needed) {
      size_to_allocate = size_needed;
    }
    void *buf = realloc(stack->match_buffer_, size_to_allocate);
    if (!buf) {
      return _AEX_PPTG_NO_MEMORY;
    }
    stack->match_buffer_ = (char *)buf;
    stack->match_buffer_size_allocated_ = size_to_allocate;
  }
  
  memcpy(stack->match_buffer_ + stack->match_buffer_size_, s, len);
  stack->match_buffer_size_ += len;
  stack->match_buffer_[stack->match_buffer_size_] = '\0';
  return 0;
}

void aex_pptg_set_input(struct aex_pptg_stack *stack, const char *input, size_t input_size, int is_final_input) {
  stack->input_ = input;
  stack->input_size_ = input_size;
  stack->is_final_input_ = is_final_input;
  stack->input_index_ = 0;
}

void aex_pptg_set_location(struct aex_pptg_stack *stack, int line, int col, size_t offset) {
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

const char *aex_pptg_text(struct aex_pptg_stack *stack) {
  return stack->match_buffer_;
}

size_t aex_pptg_len(struct aex_pptg_stack *stack) {
  return stack->token_size_;
}

int aex_pptg_line(struct aex_pptg_stack *stack) {
  return stack->match_line_;
}

int aex_pptg_column(struct aex_pptg_stack *stack) {
  return stack->match_col_;
}

size_t aex_pptg_offset(struct aex_pptg_stack *stack) {
  return stack->match_offset_;
}

int aex_pptg_endline(struct aex_pptg_stack *stack) {
  return stack->best_match_line_;
}

int aex_pptg_endcolumn(struct aex_pptg_stack *stack) {
  return stack->best_match_col_;
}

size_t aex_pptg_endoffset(struct aex_pptg_stack *stack) {
  return stack->best_match_offset_;
}

void *aex_pptg_token_common_data(struct aex_pptg_stack *stack) {
  return stack->slot_0_has_common_data_ ? &stack->stack_[0].common_ : NULL;
}
int aex_pptg_lex(struct aex_pptg_stack *stack) {
  int r;
  unsigned char c;
  const char *input = stack->input_;
  size_t input_size = stack->input_size_;
  int is_final_input = !!stack->is_final_input_;
  size_t scan_state = stack->scan_state_;
  const int *transition_table = aex_pptg_scan_table_grouped_rex_;
  const size_t *actions = aex_pptg_scan_actions_rex;
  const size_t row_size = aex_pptg_num_scan_table_grouped_columns_;
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
    int next_sg = aex_pptg_utf8_decoder_[256 * symgrp + c];
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
        
        return _AEX_PPTG_MATCH;
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
    int next_sg = aex_pptg_utf8_decoder_[256 * symgrp + c];
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
        r = aex_pptg_append_match_buffer(stack, input + stack->input_index_, input_index - stack->input_index_);
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
        
        return _AEX_PPTG_MATCH;
      }
    }
    else /* (next_sg < 0) */ {
      /* Partial analysis of codepoint; keep going */
      *cp++ = c;
      input_index++;
      symgrp = ~next_sg;
    }
  }
  
  r = aex_pptg_append_match_buffer(stack, input + stack->input_index_, input_index - stack->input_index_);
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
    
    return _AEX_PPTG_FEED_ME;
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
    
    return _AEX_PPTG_END_OF_INPUT;
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
  
  return _AEX_PPTG_MATCH;
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
      r = aex_pptg_append_match_buffer(stack, input + stack->input_index_, cp_len);
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
    
    return _AEX_PPTG_LEXICAL_ERROR;
  }
}

int aex_pptg_scan(struct aex_pptg_stack *stack, struct preprocessor *pp, const char *filename, char **output_buf, size_t *output_end, size_t *output_buf_alloc_size, struct situs *output_situs) {
  if (stack->pending_reset_) {
    int r;
    r = aex_pptg_stack_reset(stack);
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
    case 24: goto C24;
    case 25: goto C25;
    case 26: goto C26;
    case 27: goto C27;
    case 28: goto C28;
    case 29: goto C29;
    case 30: goto C30;
    case 31: goto C31;
    case 32: goto C32;
    case 33: goto C33;
    case 34: goto C34;
    case 35: goto C35;
    case 36: goto C36;
    case 37: goto C37;
  } /* continuation switch */
for (;;) {
    stack->continue_at_ = 0;
    if (stack->need_sym_) {
      switch (aex_pptg_lex(stack)) {
        case _AEX_PPTG_MATCH:
        stack->need_sym_ = 0;
        stack->discard_remaining_actions_ = 0;
        stack->current_sym_ = AEX_PPTG_INPUT_END; /* no sym specific type associated, changed when we successfully construct it below */
        if (stack->mute_error_turns_) stack->mute_error_turns_--;
        stack->slot_0_has_common_data_ = 1;
        stack->continue_at_ = 1;
        {
#line 42 "grammar/pp/pp_trigraphs.cbrt"
          aex_situs_init(&(stack->stack_[0].common_));
#line 1105 "src/pp/pp_trigraphs.c"
        }
        C1:;
        { /* scope guard */
          switch (stack->best_match_action_) {
            case 1: /* \?\?= */
            /* Pattern does not have a symbol */
            stack->current_sym_ = AEX_PPTG_INPUT_END;
            stack->need_sym_ = 1; /* keep scanning */
            if (!stack->discard_remaining_actions_) {
              stack->continue_at_ = 2;
              {
#line 48 "grammar/pp/pp_trigraphs.cbrt"
                
  (stack->stack_[0].common_).num_spans_ = 1;
  (stack->stack_[0].common_).u_.one_.filename_ = filename;
  (stack->stack_[0].common_).u_.one_.is_substitution_ = 0;
  (stack->stack_[0].common_).u_.one_.num_bytes_ = (stack->token_size_);
  (stack->stack_[0].common_).u_.one_.start_ = (stack->match_offset_);
  (stack->stack_[0].common_).u_.one_.end_ = (stack->best_match_offset_);
  (stack->stack_[0].common_).u_.one_.start_line_ = (stack->match_line_);
  (stack->stack_[0].common_).u_.one_.start_col_ = (stack->match_col_);
  (stack->stack_[0].common_).u_.one_.end_line_ = (stack->best_match_line_);
  (stack->stack_[0].common_).u_.one_.end_col_ = (stack->best_match_col_);

#line 1130 "src/pp/pp_trigraphs.c"
              }
              C2:;
            }
            if (!stack->discard_remaining_actions_) {
              stack->continue_at_ = 3;
              {
#line 61 "grammar/pp/pp_trigraphs.cbrt"
                
  (stack->stack_[0].common_).u_.one_.end_ = (stack->stack_[0].common_).u_.one_.start_ + 1;
  aex_pptg_set_location(stack, (stack->stack_[0].common_).u_.one_.end_line_, (stack->stack_[0].common_).u_.one_.end_col_, (stack->stack_[0].common_).u_.one_.end_);
  if (pp_concat_sub_output(pp, output_situs, output_buf, output_end, output_buf_alloc_size, &(stack->stack_[0].common_), "#")) {
    return _AEX_PPTG_NO_MEMORY;
  }

#line 1145 "src/pp/pp_trigraphs.c"
              }
              C3:;
            }
            if (stack->need_sym_) {
                        stack->slot_0_has_common_data_ = 0;
              {
#line 44 "grammar/pp/pp_trigraphs.cbrt"
                aex_situs_cleanup(&(stack->stack_[0].common_));
#line 1154 "src/pp/pp_trigraphs.c"
              }
            }
            break;
            case 2: /* \?\?\( */
            /* Pattern does not have a symbol */
            stack->current_sym_ = AEX_PPTG_INPUT_END;
            stack->need_sym_ = 1; /* keep scanning */
            if (!stack->discard_remaining_actions_) {
              stack->continue_at_ = 4;
              {
#line 48 "grammar/pp/pp_trigraphs.cbrt"
                
  (stack->stack_[0].common_).num_spans_ = 1;
  (stack->stack_[0].common_).u_.one_.filename_ = filename;
  (stack->stack_[0].common_).u_.one_.is_substitution_ = 0;
  (stack->stack_[0].common_).u_.one_.num_bytes_ = (stack->token_size_);
  (stack->stack_[0].common_).u_.one_.start_ = (stack->match_offset_);
  (stack->stack_[0].common_).u_.one_.end_ = (stack->best_match_offset_);
  (stack->stack_[0].common_).u_.one_.start_line_ = (stack->match_line_);
  (stack->stack_[0].common_).u_.one_.start_col_ = (stack->match_col_);
  (stack->stack_[0].common_).u_.one_.end_line_ = (stack->best_match_line_);
  (stack->stack_[0].common_).u_.one_.end_col_ = (stack->best_match_col_);

#line 1178 "src/pp/pp_trigraphs.c"
              }
              C4:;
            }
            if (!stack->discard_remaining_actions_) {
              stack->continue_at_ = 5;
              {
#line 68 "grammar/pp/pp_trigraphs.cbrt"
                 
  (stack->stack_[0].common_).u_.one_.end_ = (stack->stack_[0].common_).u_.one_.start_ + 1;
  aex_pptg_set_location(stack, (stack->stack_[0].common_).u_.one_.end_line_, (stack->stack_[0].common_).u_.one_.end_col_, (stack->stack_[0].common_).u_.one_.end_);
  if (pp_concat_sub_output(pp, output_situs, output_buf, output_end, output_buf_alloc_size, &(stack->stack_[0].common_), "[")) {
    return _AEX_PPTG_NO_MEMORY;
  }

#line 1193 "src/pp/pp_trigraphs.c"
              }
              C5:;
            }
            if (stack->need_sym_) {
                        stack->slot_0_has_common_data_ = 0;
              {
#line 44 "grammar/pp/pp_trigraphs.cbrt"
                aex_situs_cleanup(&(stack->stack_[0].common_));
#line 1202 "src/pp/pp_trigraphs.c"
              }
            }
            break;
            case 3: /* \?\?/ */
            /* Pattern does not have a symbol */
            stack->current_sym_ = AEX_PPTG_INPUT_END;
            stack->need_sym_ = 1; /* keep scanning */
            if (!stack->discard_remaining_actions_) {
              stack->continue_at_ = 6;
              {
#line 48 "grammar/pp/pp_trigraphs.cbrt"
                
  (stack->stack_[0].common_).num_spans_ = 1;
  (stack->stack_[0].common_).u_.one_.filename_ = filename;
  (stack->stack_[0].common_).u_.one_.is_substitution_ = 0;
  (stack->stack_[0].common_).u_.one_.num_bytes_ = (stack->token_size_);
  (stack->stack_[0].common_).u_.one_.start_ = (stack->match_offset_);
  (stack->stack_[0].common_).u_.one_.end_ = (stack->best_match_offset_);
  (stack->stack_[0].common_).u_.one_.start_line_ = (stack->match_line_);
  (stack->stack_[0].common_).u_.one_.start_col_ = (stack->match_col_);
  (stack->stack_[0].common_).u_.one_.end_line_ = (stack->best_match_line_);
  (stack->stack_[0].common_).u_.one_.end_col_ = (stack->best_match_col_);

#line 1226 "src/pp/pp_trigraphs.c"
              }
              C6:;
            }
            if (!stack->discard_remaining_actions_) {
              stack->continue_at_ = 7;
              {
#line 75 "grammar/pp/pp_trigraphs.cbrt"
                 
  (stack->stack_[0].common_).u_.one_.end_ = (stack->stack_[0].common_).u_.one_.start_ + 1;
  aex_pptg_set_location(stack, (stack->stack_[0].common_).u_.one_.end_line_, (stack->stack_[0].common_).u_.one_.end_col_, (stack->stack_[0].common_).u_.one_.end_);
  if (pp_concat_sub_output(pp, output_situs, output_buf, output_end, output_buf_alloc_size, &(stack->stack_[0].common_), "\\")) {
    return _AEX_PPTG_NO_MEMORY;
  }

#line 1241 "src/pp/pp_trigraphs.c"
              }
              C7:;
            }
            if (stack->need_sym_) {
                        stack->slot_0_has_common_data_ = 0;
              {
#line 44 "grammar/pp/pp_trigraphs.cbrt"
                aex_situs_cleanup(&(stack->stack_[0].common_));
#line 1250 "src/pp/pp_trigraphs.c"
              }
            }
            break;
            case 4: /* \?\?\) */
            /* Pattern does not have a symbol */
            stack->current_sym_ = AEX_PPTG_INPUT_END;
            stack->need_sym_ = 1; /* keep scanning */
            if (!stack->discard_remaining_actions_) {
              stack->continue_at_ = 8;
              {
#line 48 "grammar/pp/pp_trigraphs.cbrt"
                
  (stack->stack_[0].common_).num_spans_ = 1;
  (stack->stack_[0].common_).u_.one_.filename_ = filename;
  (stack->stack_[0].common_).u_.one_.is_substitution_ = 0;
  (stack->stack_[0].common_).u_.one_.num_bytes_ = (stack->token_size_);
  (stack->stack_[0].common_).u_.one_.start_ = (stack->match_offset_);
  (stack->stack_[0].common_).u_.one_.end_ = (stack->best_match_offset_);
  (stack->stack_[0].common_).u_.one_.start_line_ = (stack->match_line_);
  (stack->stack_[0].common_).u_.one_.start_col_ = (stack->match_col_);
  (stack->stack_[0].common_).u_.one_.end_line_ = (stack->best_match_line_);
  (stack->stack_[0].common_).u_.one_.end_col_ = (stack->best_match_col_);

#line 1274 "src/pp/pp_trigraphs.c"
              }
              C8:;
            }
            if (!stack->discard_remaining_actions_) {
              stack->continue_at_ = 9;
              {
#line 82 "grammar/pp/pp_trigraphs.cbrt"
                 
  (stack->stack_[0].common_).u_.one_.end_ = (stack->stack_[0].common_).u_.one_.start_ + 1;
  aex_pptg_set_location(stack, (stack->stack_[0].common_).u_.one_.end_line_, (stack->stack_[0].common_).u_.one_.end_col_, (stack->stack_[0].common_).u_.one_.end_);
  if (pp_concat_sub_output(pp, output_situs, output_buf, output_end, output_buf_alloc_size, &(stack->stack_[0].common_), "]")) {
    return _AEX_PPTG_NO_MEMORY;
  }

#line 1289 "src/pp/pp_trigraphs.c"
              }
              C9:;
            }
            if (stack->need_sym_) {
                        stack->slot_0_has_common_data_ = 0;
              {
#line 44 "grammar/pp/pp_trigraphs.cbrt"
                aex_situs_cleanup(&(stack->stack_[0].common_));
#line 1298 "src/pp/pp_trigraphs.c"
              }
            }
            break;
            case 5: /* \?\?\' */
            /* Pattern does not have a symbol */
            stack->current_sym_ = AEX_PPTG_INPUT_END;
            stack->need_sym_ = 1; /* keep scanning */
            if (!stack->discard_remaining_actions_) {
              stack->continue_at_ = 10;
              {
#line 48 "grammar/pp/pp_trigraphs.cbrt"
                
  (stack->stack_[0].common_).num_spans_ = 1;
  (stack->stack_[0].common_).u_.one_.filename_ = filename;
  (stack->stack_[0].common_).u_.one_.is_substitution_ = 0;
  (stack->stack_[0].common_).u_.one_.num_bytes_ = (stack->token_size_);
  (stack->stack_[0].common_).u_.one_.start_ = (stack->match_offset_);
  (stack->stack_[0].common_).u_.one_.end_ = (stack->best_match_offset_);
  (stack->stack_[0].common_).u_.one_.start_line_ = (stack->match_line_);
  (stack->stack_[0].common_).u_.one_.start_col_ = (stack->match_col_);
  (stack->stack_[0].common_).u_.one_.end_line_ = (stack->best_match_line_);
  (stack->stack_[0].common_).u_.one_.end_col_ = (stack->best_match_col_);

#line 1322 "src/pp/pp_trigraphs.c"
              }
              C10:;
            }
            if (!stack->discard_remaining_actions_) {
              stack->continue_at_ = 11;
              {
#line 89 "grammar/pp/pp_trigraphs.cbrt"
                 
  (stack->stack_[0].common_).u_.one_.end_ = (stack->stack_[0].common_).u_.one_.start_ + 1;
  aex_pptg_set_location(stack, (stack->stack_[0].common_).u_.one_.end_line_, (stack->stack_[0].common_).u_.one_.end_col_, (stack->stack_[0].common_).u_.one_.end_);
  if (pp_concat_sub_output(pp, output_situs, output_buf, output_end, output_buf_alloc_size, &(stack->stack_[0].common_), "^")) {
    return _AEX_PPTG_NO_MEMORY;
  }

#line 1337 "src/pp/pp_trigraphs.c"
              }
              C11:;
            }
            if (stack->need_sym_) {
                        stack->slot_0_has_common_data_ = 0;
              {
#line 44 "grammar/pp/pp_trigraphs.cbrt"
                aex_situs_cleanup(&(stack->stack_[0].common_));
#line 1346 "src/pp/pp_trigraphs.c"
              }
            }
            break;
            case 6: /* \?\?< */
            /* Pattern does not have a symbol */
            stack->current_sym_ = AEX_PPTG_INPUT_END;
            stack->need_sym_ = 1; /* keep scanning */
            if (!stack->discard_remaining_actions_) {
              stack->continue_at_ = 12;
              {
#line 48 "grammar/pp/pp_trigraphs.cbrt"
                
  (stack->stack_[0].common_).num_spans_ = 1;
  (stack->stack_[0].common_).u_.one_.filename_ = filename;
  (stack->stack_[0].common_).u_.one_.is_substitution_ = 0;
  (stack->stack_[0].common_).u_.one_.num_bytes_ = (stack->token_size_);
  (stack->stack_[0].common_).u_.one_.start_ = (stack->match_offset_);
  (stack->stack_[0].common_).u_.one_.end_ = (stack->best_match_offset_);
  (stack->stack_[0].common_).u_.one_.start_line_ = (stack->match_line_);
  (stack->stack_[0].common_).u_.one_.start_col_ = (stack->match_col_);
  (stack->stack_[0].common_).u_.one_.end_line_ = (stack->best_match_line_);
  (stack->stack_[0].common_).u_.one_.end_col_ = (stack->best_match_col_);

#line 1370 "src/pp/pp_trigraphs.c"
              }
              C12:;
            }
            if (!stack->discard_remaining_actions_) {
              stack->continue_at_ = 13;
              {
#line 96 "grammar/pp/pp_trigraphs.cbrt"
                 
  (stack->stack_[0].common_).u_.one_.end_ = (stack->stack_[0].common_).u_.one_.start_ + 1;
  aex_pptg_set_location(stack, (stack->stack_[0].common_).u_.one_.end_line_, (stack->stack_[0].common_).u_.one_.end_col_, (stack->stack_[0].common_).u_.one_.end_);
  if (pp_concat_sub_output(pp, output_situs, output_buf, output_end, output_buf_alloc_size, &(stack->stack_[0].common_), "{")) {
    return _AEX_PPTG_NO_MEMORY;
  }

#line 1385 "src/pp/pp_trigraphs.c"
              }
              C13:;
            }
            if (stack->need_sym_) {
                        stack->slot_0_has_common_data_ = 0;
              {
#line 44 "grammar/pp/pp_trigraphs.cbrt"
                aex_situs_cleanup(&(stack->stack_[0].common_));
#line 1394 "src/pp/pp_trigraphs.c"
              }
            }
            break;
            case 7: /* \?\?! */
            /* Pattern does not have a symbol */
            stack->current_sym_ = AEX_PPTG_INPUT_END;
            stack->need_sym_ = 1; /* keep scanning */
            if (!stack->discard_remaining_actions_) {
              stack->continue_at_ = 14;
              {
#line 48 "grammar/pp/pp_trigraphs.cbrt"
                
  (stack->stack_[0].common_).num_spans_ = 1;
  (stack->stack_[0].common_).u_.one_.filename_ = filename;
  (stack->stack_[0].common_).u_.one_.is_substitution_ = 0;
  (stack->stack_[0].common_).u_.one_.num_bytes_ = (stack->token_size_);
  (stack->stack_[0].common_).u_.one_.start_ = (stack->match_offset_);
  (stack->stack_[0].common_).u_.one_.end_ = (stack->best_match_offset_);
  (stack->stack_[0].common_).u_.one_.start_line_ = (stack->match_line_);
  (stack->stack_[0].common_).u_.one_.start_col_ = (stack->match_col_);
  (stack->stack_[0].common_).u_.one_.end_line_ = (stack->best_match_line_);
  (stack->stack_[0].common_).u_.one_.end_col_ = (stack->best_match_col_);

#line 1418 "src/pp/pp_trigraphs.c"
              }
              C14:;
            }
            if (!stack->discard_remaining_actions_) {
              stack->continue_at_ = 15;
              {
#line 103 "grammar/pp/pp_trigraphs.cbrt"
                 
  (stack->stack_[0].common_).u_.one_.end_ = (stack->stack_[0].common_).u_.one_.start_ + 1;
  aex_pptg_set_location(stack, (stack->stack_[0].common_).u_.one_.end_line_, (stack->stack_[0].common_).u_.one_.end_col_, (stack->stack_[0].common_).u_.one_.end_);
  if (pp_concat_sub_output(pp, output_situs, output_buf, output_end, output_buf_alloc_size, &(stack->stack_[0].common_), "|")) {
    return _AEX_PPTG_NO_MEMORY;
  }

#line 1433 "src/pp/pp_trigraphs.c"
              }
              C15:;
            }
            if (stack->need_sym_) {
                        stack->slot_0_has_common_data_ = 0;
              {
#line 44 "grammar/pp/pp_trigraphs.cbrt"
                aex_situs_cleanup(&(stack->stack_[0].common_));
#line 1442 "src/pp/pp_trigraphs.c"
              }
            }
            break;
            case 8: /* \?\?> */
            /* Pattern does not have a symbol */
            stack->current_sym_ = AEX_PPTG_INPUT_END;
            stack->need_sym_ = 1; /* keep scanning */
            if (!stack->discard_remaining_actions_) {
              stack->continue_at_ = 16;
              {
#line 48 "grammar/pp/pp_trigraphs.cbrt"
                
  (stack->stack_[0].common_).num_spans_ = 1;
  (stack->stack_[0].common_).u_.one_.filename_ = filename;
  (stack->stack_[0].common_).u_.one_.is_substitution_ = 0;
  (stack->stack_[0].common_).u_.one_.num_bytes_ = (stack->token_size_);
  (stack->stack_[0].common_).u_.one_.start_ = (stack->match_offset_);
  (stack->stack_[0].common_).u_.one_.end_ = (stack->best_match_offset_);
  (stack->stack_[0].common_).u_.one_.start_line_ = (stack->match_line_);
  (stack->stack_[0].common_).u_.one_.start_col_ = (stack->match_col_);
  (stack->stack_[0].common_).u_.one_.end_line_ = (stack->best_match_line_);
  (stack->stack_[0].common_).u_.one_.end_col_ = (stack->best_match_col_);

#line 1466 "src/pp/pp_trigraphs.c"
              }
              C16:;
            }
            if (!stack->discard_remaining_actions_) {
              stack->continue_at_ = 17;
              {
#line 110 "grammar/pp/pp_trigraphs.cbrt"
                
  (stack->stack_[0].common_).u_.one_.end_ = (stack->stack_[0].common_).u_.one_.start_ + 1;
  aex_pptg_set_location(stack, (stack->stack_[0].common_).u_.one_.end_line_, (stack->stack_[0].common_).u_.one_.end_col_, (stack->stack_[0].common_).u_.one_.end_);
  if (pp_concat_sub_output(pp, output_situs, output_buf, output_end, output_buf_alloc_size, &(stack->stack_[0].common_), "}")) {
    return _AEX_PPTG_NO_MEMORY;
  }

#line 1481 "src/pp/pp_trigraphs.c"
              }
              C17:;
            }
            if (stack->need_sym_) {
                        stack->slot_0_has_common_data_ = 0;
              {
#line 44 "grammar/pp/pp_trigraphs.cbrt"
                aex_situs_cleanup(&(stack->stack_[0].common_));
#line 1490 "src/pp/pp_trigraphs.c"
              }
            }
            break;
            case 9: /* \?\?\- */
            /* Pattern does not have a symbol */
            stack->current_sym_ = AEX_PPTG_INPUT_END;
            stack->need_sym_ = 1; /* keep scanning */
            if (!stack->discard_remaining_actions_) {
              stack->continue_at_ = 18;
              {
#line 48 "grammar/pp/pp_trigraphs.cbrt"
                
  (stack->stack_[0].common_).num_spans_ = 1;
  (stack->stack_[0].common_).u_.one_.filename_ = filename;
  (stack->stack_[0].common_).u_.one_.is_substitution_ = 0;
  (stack->stack_[0].common_).u_.one_.num_bytes_ = (stack->token_size_);
  (stack->stack_[0].common_).u_.one_.start_ = (stack->match_offset_);
  (stack->stack_[0].common_).u_.one_.end_ = (stack->best_match_offset_);
  (stack->stack_[0].common_).u_.one_.start_line_ = (stack->match_line_);
  (stack->stack_[0].common_).u_.one_.start_col_ = (stack->match_col_);
  (stack->stack_[0].common_).u_.one_.end_line_ = (stack->best_match_line_);
  (stack->stack_[0].common_).u_.one_.end_col_ = (stack->best_match_col_);

#line 1514 "src/pp/pp_trigraphs.c"
              }
              C18:;
            }
            if (!stack->discard_remaining_actions_) {
              stack->continue_at_ = 19;
              {
#line 117 "grammar/pp/pp_trigraphs.cbrt"
                
  (stack->stack_[0].common_).u_.one_.end_ = (stack->stack_[0].common_).u_.one_.start_ + 1;
  aex_pptg_set_location(stack, (stack->stack_[0].common_).u_.one_.end_line_, (stack->stack_[0].common_).u_.one_.end_col_, (stack->stack_[0].common_).u_.one_.end_);
  if (pp_concat_sub_output(pp, output_situs, output_buf, output_end, output_buf_alloc_size, &(stack->stack_[0].common_), "~")) {
    return _AEX_PPTG_NO_MEMORY;
  }

#line 1529 "src/pp/pp_trigraphs.c"
              }
              C19:;
            }
            if (stack->need_sym_) {
                        stack->slot_0_has_common_data_ = 0;
              {
#line 44 "grammar/pp/pp_trigraphs.cbrt"
                aex_situs_cleanup(&(stack->stack_[0].common_));
#line 1538 "src/pp/pp_trigraphs.c"
              }
            }
            break;
            case 10: /* ([^\?]+|\?[^\?]|\?\?+[^=\(/\)\'<!>\-])+ */
            /* Pattern does not have a symbol */
            stack->current_sym_ = AEX_PPTG_INPUT_END;
            stack->need_sym_ = 1; /* keep scanning */
            if (!stack->discard_remaining_actions_) {
              stack->continue_at_ = 20;
              {
#line 48 "grammar/pp/pp_trigraphs.cbrt"
                
  (stack->stack_[0].common_).num_spans_ = 1;
  (stack->stack_[0].common_).u_.one_.filename_ = filename;
  (stack->stack_[0].common_).u_.one_.is_substitution_ = 0;
  (stack->stack_[0].common_).u_.one_.num_bytes_ = (stack->token_size_);
  (stack->stack_[0].common_).u_.one_.start_ = (stack->match_offset_);
  (stack->stack_[0].common_).u_.one_.end_ = (stack->best_match_offset_);
  (stack->stack_[0].common_).u_.one_.start_line_ = (stack->match_line_);
  (stack->stack_[0].common_).u_.one_.start_col_ = (stack->match_col_);
  (stack->stack_[0].common_).u_.one_.end_line_ = (stack->best_match_line_);
  (stack->stack_[0].common_).u_.one_.end_col_ = (stack->best_match_col_);

#line 1562 "src/pp/pp_trigraphs.c"
              }
              C20:;
            }
            if (!stack->discard_remaining_actions_) {
              stack->continue_at_ = 21;
              {
#line 125 "grammar/pp/pp_trigraphs.cbrt"
                 
  if (pp_concat_output(pp, output_situs, output_buf, output_end, output_buf_alloc_size, &(stack->stack_[0].common_), (stack->match_buffer_))) {
    return _AEX_PPTG_NO_MEMORY;
  }

#line 1575 "src/pp/pp_trigraphs.c"
              }
              C21:;
            }
            if (stack->need_sym_) {
                        stack->slot_0_has_common_data_ = 0;
              {
#line 44 "grammar/pp/pp_trigraphs.cbrt"
                aex_situs_cleanup(&(stack->stack_[0].common_));
#line 1584 "src/pp/pp_trigraphs.c"
              }
            }
            break;
          } /* switch */
        } /* scope guard */
        break;
        case _AEX_PPTG_OVERFLOW:
        stack->continue_at_ = 0;
        return _AEX_PPTG_OVERFLOW;
        case _AEX_PPTG_NO_MEMORY:
        stack->continue_at_ = 0;
        return _AEX_PPTG_NO_MEMORY;
        case _AEX_PPTG_FEED_ME:
        stack->continue_at_ = 0;
        /* Need more input */
        return _AEX_PPTG_FEED_ME;
        case _AEX_PPTG_END_OF_INPUT:
        stack->current_sym_ = AEX_PPTG_INPUT_END;
        stack->need_sym_ = 0;
        if (stack->mute_error_turns_) stack->mute_error_turns_--;
        break;
        case _AEX_PPTG_LEXICAL_ERROR:
        stack->continue_at_ = 0;
        /* Lexical error */
        return _AEX_PPTG_LEXICAL_ERROR;
      } /* switch */
    } /* if (need_sym_) */
    else {
      int sym;
      sym = stack->current_sym_;
      if (!stack->error_recovery_) {
        int action;
        action = aex_pptg_parse_table[aex_pptg_num_columns * stack->stack_[stack->pos_ - 1].state_ + (sym - aex_pptg_minimum_sym)];
        if (action > 0) {
          if (stack->num_stack_allocated_ == stack->pos_) {
            stack->action_preservation_ = action;
            size_t new_num_allocated;
            if (stack->num_stack_allocated_) {
              new_num_allocated = stack->num_stack_allocated_ * 2;
              if (new_num_allocated <= stack->num_stack_allocated_) {
                /* Overflow in allocation */
                return _AEX_PPTG_OVERFLOW;
              }
            }
            else {
              new_num_allocated = 16;
            }
            
            if (new_num_allocated > (SIZE_MAX / sizeof(struct aex_pptg_sym_data))) {
              /* Overflow in allocation */
              return _AEX_PPTG_OVERFLOW;
            }
            
            stack->new_buf_ = (struct aex_pptg_sym_data *)malloc(new_num_allocated * sizeof(struct aex_pptg_sym_data));
            if (!stack->new_buf_) {
              /* Out of memory */
              return _AEX_PPTG_NO_MEMORY;
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
#line 42 "grammar/pp/pp_trigraphs.cbrt"
                    aex_situs_init(&((stack->new_buf_ + stack->new_buf_sym_partial_pos_)->common_));
#line 1665 "src/pp/pp_trigraphs.c"
                  }
                  C22:;
                  stack->continue_at_ = 23;
                  {
#line 43 "grammar/pp/pp_trigraphs.cbrt"
                    aex_situs_swap(&stack->new_buf_[stack->new_buf_sym_partial_pos_].common_, &(stack->stack_[stack->new_buf_sym_partial_pos_].common_));
#line 1672 "src/pp/pp_trigraphs.c"
                  }
                  C23:;
                  {
#line 44 "grammar/pp/pp_trigraphs.cbrt"
                    aex_situs_cleanup(&((stack->stack_ + stack->new_buf_sym_partial_pos_)->common_));
#line 1678 "src/pp/pp_trigraphs.c"
                  }
                  stack->stack_newbuf_pos_has_common_data_ = 0;
                }
              }
              else /* not 0 or 1, but >= 2 state derived sym */ {
                stack->newbuf_pos_has_common_data_ = 1;
                stack->continue_at_ = 24;
                {
#line 42 "grammar/pp/pp_trigraphs.cbrt"
                  aex_situs_init(&((stack->new_buf_ + stack->new_buf_sym_partial_pos_)->common_));
#line 1689 "src/pp/pp_trigraphs.c"
                }
                C24:;
                stack->continue_at_ = 25;
                {
#line 43 "grammar/pp/pp_trigraphs.cbrt"
                  aex_situs_swap(&stack->new_buf_[stack->new_buf_sym_partial_pos_].common_, &(stack->stack_[stack->new_buf_sym_partial_pos_].common_));
#line 1696 "src/pp/pp_trigraphs.c"
                }
                C25:;
                {
#line 44 "grammar/pp/pp_trigraphs.cbrt"
                  aex_situs_cleanup(&((stack->stack_ + stack->new_buf_sym_partial_pos_)->common_));
#line 1702 "src/pp/pp_trigraphs.c"
                }
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
          stack->continue_at_ = 26;
          {
#line 42 "grammar/pp/pp_trigraphs.cbrt"
            aex_situs_init(&((stack->stack_ + stack->pos_ - 1)->common_));
#line 1725 "src/pp/pp_trigraphs.c"
          }
          C26:;
          stack->continue_at_ = 27;
          {
#line 43 "grammar/pp/pp_trigraphs.cbrt"
            aex_situs_swap(&stack->stack_[stack->pos_ - 1].common_, &(stack->stack_[0].common_));
#line 1732 "src/pp/pp_trigraphs.c"
          }
          C27:;
          {
#line 44 "grammar/pp/pp_trigraphs.cbrt"
            aex_situs_cleanup(&(stack->stack_[0].common_));
#line 1738 "src/pp/pp_trigraphs.c"
          }
          stack->slot_0_has_common_data_ = 0;
          stack->slot_0_has_current_sym_data_ = 0;
        } /* action > 0 */
        else if (action < 0) {
          int production;
          production = -action - 1;
          stack->discard_remaining_actions_ = 0;
          stack->current_production_length_ = aex_pptg_production_lengths[production];
          stack->current_production_nonterminal_ = aex_pptg_production_syms[production];
          if (0 == production) {
            stack->pending_reset_ = 1;
            return _AEX_PPTG_FINISH;
          }
          
          memset(&stack->stack_[1], 0, sizeof(struct aex_pptg_sym_data));
          { /* scope guard */
            stack->sym_data_ = stack->stack_ + stack->pos_ - stack->current_production_length_;
            /* Note: no productions to process */
          } /* scope guard */
          
          /* Free symdata for every symbol in the production, including the first slot where we will soon
          * push nonterminal_data_reduced_to */
          for (stack->sym_idx_ = stack->pos_ - stack->current_production_length_; stack->sym_idx_ < stack->pos_; ++stack->sym_idx_) {
            {
#line 44 "grammar/pp/pp_trigraphs.cbrt"
              aex_situs_cleanup(&((stack->stack_ + stack->sym_idx_)->common_));
#line 1766 "src/pp/pp_trigraphs.c"
            }
          } /* for */
          stack->pos_ -= stack->current_production_length_;
          stack->top_of_stack_has_sym_data_ = stack->top_of_stack_has_common_data_ = 1;
          action = aex_pptg_parse_table[aex_pptg_num_columns * stack->stack_[stack->pos_ - 1].state_ + (stack->current_production_nonterminal_ - aex_pptg_minimum_sym)];
          if (action <= 0) {
            stack->continue_at_ = 0;
            /* Internal error */
            return _AEX_PPTG_INTERNAL_ERROR;
          }
          if (stack->num_stack_allocated_ == stack->pos_) {
            stack->action_preservation_ = action /* action for a "goto" shift is the ordinal */;
            size_t new_num_allocated;
            if (stack->num_stack_allocated_) {
              new_num_allocated = stack->num_stack_allocated_ * 2;
              if (new_num_allocated <= stack->num_stack_allocated_) {
                /* Overflow in allocation */
                return _AEX_PPTG_OVERFLOW;
              }
            }
            else {
              new_num_allocated = 16;
            }
            
            if (new_num_allocated > (SIZE_MAX / sizeof(struct aex_pptg_sym_data))) {
              /* Overflow in allocation */
              return _AEX_PPTG_OVERFLOW;
            }
            
            stack->new_buf_ = (struct aex_pptg_sym_data *)malloc(new_num_allocated * sizeof(struct aex_pptg_sym_data));
            if (!stack->new_buf_) {
              /* Out of memory */
              return _AEX_PPTG_NO_MEMORY;
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
                  stack->continue_at_ = 28;
                  {
#line 42 "grammar/pp/pp_trigraphs.cbrt"
                    aex_situs_init(&((stack->new_buf_ + stack->new_buf_sym_partial_pos_)->common_));
#line 1823 "src/pp/pp_trigraphs.c"
                  }
                  C28:;
                  stack->continue_at_ = 29;
                  {
#line 43 "grammar/pp/pp_trigraphs.cbrt"
                    aex_situs_swap(&stack->new_buf_[stack->new_buf_sym_partial_pos_].common_, &(stack->stack_[stack->new_buf_sym_partial_pos_].common_));
#line 1830 "src/pp/pp_trigraphs.c"
                  }
                  C29:;
                  {
#line 44 "grammar/pp/pp_trigraphs.cbrt"
                    aex_situs_cleanup(&((stack->stack_ + stack->new_buf_sym_partial_pos_)->common_));
#line 1836 "src/pp/pp_trigraphs.c"
                  }
                  stack->stack_newbuf_pos_has_common_data_ = 0;
                }
              }
              else /* not 0 or 1, but >= 2 state derived sym */ {
                stack->newbuf_pos_has_common_data_ = 1;
                stack->continue_at_ = 30;
                {
#line 42 "grammar/pp/pp_trigraphs.cbrt"
                  aex_situs_init(&((stack->new_buf_ + stack->new_buf_sym_partial_pos_)->common_));
#line 1847 "src/pp/pp_trigraphs.c"
                }
                C30:;
                stack->continue_at_ = 31;
                {
#line 43 "grammar/pp/pp_trigraphs.cbrt"
                  aex_situs_swap(&stack->new_buf_[stack->new_buf_sym_partial_pos_].common_, &(stack->stack_[stack->new_buf_sym_partial_pos_].common_));
#line 1854 "src/pp/pp_trigraphs.c"
                }
                C31:;
                {
#line 44 "grammar/pp/pp_trigraphs.cbrt"
                  aex_situs_cleanup(&((stack->stack_ + stack->new_buf_sym_partial_pos_)->common_));
#line 1860 "src/pp/pp_trigraphs.c"
                }
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
          stack->continue_at_ = 32;
          {
#line 42 "grammar/pp/pp_trigraphs.cbrt"
            aex_situs_init(&((stack->stack_ + stack->pos_ - 1)->common_));
#line 1880 "src/pp/pp_trigraphs.c"
          }
          C32:;
          stack->continue_at_ = 33;
          {
#line 43 "grammar/pp/pp_trigraphs.cbrt"
            aex_situs_swap(&stack->stack_[stack->pos_ - 1].common_, &(stack->stack_[1].common_));
#line 1887 "src/pp/pp_trigraphs.c"
          }
          C33:;
          {
#line 44 "grammar/pp/pp_trigraphs.cbrt"
            aex_situs_cleanup(&(stack->stack_[1].common_));
#line 1893 "src/pp/pp_trigraphs.c"
          }
          stack->slot_1_has_common_data_ = 0;
          stack->slot_1_has_sym_data_ = 0;
        } /* action < 0 */
        else /* action == 0 */ {
          /* check if we can recover using an error token. */
          size_t n;
          for (n = 0; n < stack->pos_; ++n) {
            stack->current_err_action_ = aex_pptg_parse_table[aex_pptg_num_columns * stack->stack_[n].state_ + (3 /* error token */ - aex_pptg_minimum_sym)];
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
            if (sym != AEX_PPTG_INPUT_END) {
              /* Retain EOF but discard any other sym so we make progress */
              stack->need_sym_ = 1;
              {
#line 44 "grammar/pp/pp_trigraphs.cbrt"
                aex_situs_cleanup(&(stack->stack_[0].common_));
#line 1919 "src/pp/pp_trigraphs.c"
              }
            }
          }
          /* Issue the error here */
          if (!stack->mute_error_turns_) {
            stack->mute_error_turns_ = 3;
            stack->continue_at_ = 0;
            /* Syntax error */
            return _AEX_PPTG_SYNTAX_ERROR;
          }
          else {
            stack->mute_error_turns_--;
            if (sym == AEX_PPTG_INPUT_END) {
              /* EOF means we cannot shift to recover, and errors are muted, so return completion */
              stack->pending_reset_ = 1;
              return _AEX_PPTG_FINISH;
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
            stack->current_err_action_ = aex_pptg_parse_table[aex_pptg_num_columns * stack->stack_[n].state_ + (3 /* error token */ - aex_pptg_minimum_sym)];
            if (stack->current_err_action_ > 0) {
              /* Does the resulting state accept the current symbol? */
              int err_sym_action;
              sym = stack->current_sym_; /* recover on the edge case we exited while moving data */
              err_sym_action = aex_pptg_parse_table[aex_pptg_num_columns * stack->current_err_action_ + (sym - aex_pptg_minimum_sym)];
              if (err_sym_action) {
                /* Current symbol is accepted, recover error condition by shifting the error token and then process the symbol as usual */
                /* Free symdata for every symbol up to the state where we will shift the error token */
                for (stack->sym_idx_ = n + 1; stack->sym_idx_ < stack->pos_; ++stack->sym_idx_) {
                  {
#line 44 "grammar/pp/pp_trigraphs.cbrt"
                    aex_situs_cleanup(&((stack->stack_ + stack->sym_idx_)->common_));
#line 1960 "src/pp/pp_trigraphs.c"
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
                      return _AEX_PPTG_OVERFLOW;
                    }
                  }
                  else {
                    new_num_allocated = 16;
                  }
                  
                  if (new_num_allocated > (SIZE_MAX / sizeof(struct aex_pptg_sym_data))) {
                    /* Overflow in allocation */
                    return _AEX_PPTG_OVERFLOW;
                  }
                  
                  stack->new_buf_ = (struct aex_pptg_sym_data *)malloc(new_num_allocated * sizeof(struct aex_pptg_sym_data));
                  if (!stack->new_buf_) {
                    /* Out of memory */
                    return _AEX_PPTG_NO_MEMORY;
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
                        stack->continue_at_ = 34;
                        {
#line 42 "grammar/pp/pp_trigraphs.cbrt"
                          aex_situs_init(&((stack->new_buf_ + stack->new_buf_sym_partial_pos_)->common_));
#line 2011 "src/pp/pp_trigraphs.c"
                        }
                        C34:;
                        stack->continue_at_ = 35;
                        {
#line 43 "grammar/pp/pp_trigraphs.cbrt"
                          aex_situs_swap(&stack->new_buf_[stack->new_buf_sym_partial_pos_].common_, &(stack->stack_[stack->new_buf_sym_partial_pos_].common_));
#line 2018 "src/pp/pp_trigraphs.c"
                        }
                        C35:;
                        {
#line 44 "grammar/pp/pp_trigraphs.cbrt"
                          aex_situs_cleanup(&((stack->stack_ + stack->new_buf_sym_partial_pos_)->common_));
#line 2024 "src/pp/pp_trigraphs.c"
                        }
                        stack->stack_newbuf_pos_has_common_data_ = 0;
                      }
                    }
                    else /* not 0 or 1, but >= 2 state derived sym */ {
                      stack->newbuf_pos_has_common_data_ = 1;
                      stack->continue_at_ = 36;
                      {
#line 42 "grammar/pp/pp_trigraphs.cbrt"
                        aex_situs_init(&((stack->new_buf_ + stack->new_buf_sym_partial_pos_)->common_));
#line 2035 "src/pp/pp_trigraphs.c"
                      }
                      C36:;
                      stack->continue_at_ = 37;
                      {
#line 43 "grammar/pp/pp_trigraphs.cbrt"
                        aex_situs_swap(&stack->new_buf_[stack->new_buf_sym_partial_pos_].common_, &(stack->stack_[stack->new_buf_sym_partial_pos_].common_));
#line 2042 "src/pp/pp_trigraphs.c"
                      }
                      C37:;
                      {
#line 44 "grammar/pp/pp_trigraphs.cbrt"
                        aex_situs_cleanup(&((stack->stack_ + stack->new_buf_sym_partial_pos_)->common_));
#line 2048 "src/pp/pp_trigraphs.c"
                      }
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
          if (stack->current_sym_ == AEX_PPTG_INPUT_END) {
            /* EOF means we cannot shift to recover, so return completion */
            stack->pending_reset_ = 1;
            return _AEX_PPTG_FINISH;
          }
          stack->need_sym_ = 1;
          {
#line 44 "grammar/pp/pp_trigraphs.cbrt"
            aex_situs_cleanup(&(stack->stack_[0].common_));
#line 2081 "src/pp/pp_trigraphs.c"
          }
        }
      } /* stack->error_recovery_ */
    }
  } /* for (;;) */
}

int aex_pptg_parse(struct aex_pptg_stack *stack, int sym, struct preprocessor *pp, const char *filename, char **output_buf, size_t *output_end, size_t *output_buf_alloc_size, struct situs *output_situs) {
  if (stack->pending_reset_) {
    int r;
    r = aex_pptg_stack_reset(stack);
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
  } /* continuation switch */
if (stack->mute_error_turns_) stack->mute_error_turns_--;
  for (;;) {
    if (!stack->error_recovery_) {
      int action;
      action = aex_pptg_parse_table[aex_pptg_num_columns * stack->stack_[stack->pos_ - 1].state_ + (sym - aex_pptg_minimum_sym)];
      if (action > 0) {
        if (stack->num_stack_allocated_ == stack->pos_) {
          stack->action_preservation_ = action;
          size_t new_num_allocated;
          if (stack->num_stack_allocated_) {
            new_num_allocated = stack->num_stack_allocated_ * 2;
            if (new_num_allocated <= stack->num_stack_allocated_) {
              /* Overflow in allocation */
              return _AEX_PPTG_OVERFLOW;
            }
          }
          else {
            new_num_allocated = 16;
          }
          
          if (new_num_allocated > (SIZE_MAX / sizeof(struct aex_pptg_sym_data))) {
            /* Overflow in allocation */
            return _AEX_PPTG_OVERFLOW;
          }
          
          stack->new_buf_ = (struct aex_pptg_sym_data *)malloc(new_num_allocated * sizeof(struct aex_pptg_sym_data));
          if (!stack->new_buf_) {
            /* Out of memory */
            return _AEX_PPTG_NO_MEMORY;
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
#line 42 "grammar/pp/pp_trigraphs.cbrt"
                  aex_situs_init(&((stack->new_buf_ + stack->new_buf_sym_partial_pos_)->common_));
#line 2165 "src/pp/pp_trigraphs.c"
                }
                C1:;
                stack->continue_at_ = 2;
                {
#line 43 "grammar/pp/pp_trigraphs.cbrt"
                  aex_situs_swap(&stack->new_buf_[stack->new_buf_sym_partial_pos_].common_, &(stack->stack_[stack->new_buf_sym_partial_pos_].common_));
#line 2172 "src/pp/pp_trigraphs.c"
                }
                C2:;
                {
#line 44 "grammar/pp/pp_trigraphs.cbrt"
                  aex_situs_cleanup(&((stack->stack_ + stack->new_buf_sym_partial_pos_)->common_));
#line 2178 "src/pp/pp_trigraphs.c"
                }
                stack->stack_newbuf_pos_has_common_data_ = 0;
              }
            }
            else /* not 0 or 1, but >= 2 state derived sym */ {
              stack->newbuf_pos_has_common_data_ = 1;
              stack->continue_at_ = 3;
              {
#line 42 "grammar/pp/pp_trigraphs.cbrt"
                aex_situs_init(&((stack->new_buf_ + stack->new_buf_sym_partial_pos_)->common_));
#line 2189 "src/pp/pp_trigraphs.c"
              }
              C3:;
              stack->continue_at_ = 4;
              {
#line 43 "grammar/pp/pp_trigraphs.cbrt"
                aex_situs_swap(&stack->new_buf_[stack->new_buf_sym_partial_pos_].common_, &(stack->stack_[stack->new_buf_sym_partial_pos_].common_));
#line 2196 "src/pp/pp_trigraphs.c"
              }
              C4:;
              {
#line 44 "grammar/pp/pp_trigraphs.cbrt"
                aex_situs_cleanup(&((stack->stack_ + stack->new_buf_sym_partial_pos_)->common_));
#line 2202 "src/pp/pp_trigraphs.c"
              }
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
        stack->continue_at_ = 5;
        {
#line 42 "grammar/pp/pp_trigraphs.cbrt"
          aex_situs_init(&(stack->sym_data_->common_));
#line 2225 "src/pp/pp_trigraphs.c"
        }
        C5:;
        stack->continue_at_ = 0;
        /* Next token */
        return _AEX_PPTG_FEED_ME;
      } /* action > 0 */
      else if (action < 0) {
        int production;
        production = -action - 1;
        stack->discard_remaining_actions_ = 0;
        stack->current_production_length_ = aex_pptg_production_lengths[production];
        stack->current_production_nonterminal_ = aex_pptg_production_syms[production];
        if (0 == production) {
          stack->pending_reset_ = 1;
          /* Synth S we're done */
          return _AEX_PPTG_FINISH;
        }
        
        memset(&stack->stack_[1], 0, sizeof(struct aex_pptg_sym_data));
        { /* scope guard */
          stack->sym_data_ = stack->stack_ + stack->pos_ - stack->current_production_length_;
          /* Note: no productions to process */
        } /* scope guard */
        
        /* Free symdata for every symbol in the production, including the first slot where we will soon
        * push nonterminal_data_reduced_to */
        for (stack->sym_idx_ = stack->pos_ - stack->current_production_length_; stack->sym_idx_ < stack->pos_; ++stack->sym_idx_) {
          {
#line 44 "grammar/pp/pp_trigraphs.cbrt"
            aex_situs_cleanup(&((stack->stack_ + stack->sym_idx_)->common_));
#line 2256 "src/pp/pp_trigraphs.c"
          }
        } /* for */
        stack->pos_ -= stack->current_production_length_;
        stack->top_of_stack_has_sym_data_ = stack->top_of_stack_has_common_data_ = 1;
        action = aex_pptg_parse_table[aex_pptg_num_columns * stack->stack_[stack->pos_ - 1].state_ + (stack->current_production_nonterminal_ - aex_pptg_minimum_sym)];
        if (action <= 0) {
          stack->continue_at_ = 0;
          /* Internal error */
          return _AEX_PPTG_INTERNAL_ERROR;
        }
        if (stack->num_stack_allocated_ == stack->pos_) {
          stack->action_preservation_ = action /* action for a "goto" shift is the ordinal */;
          size_t new_num_allocated;
          if (stack->num_stack_allocated_) {
            new_num_allocated = stack->num_stack_allocated_ * 2;
            if (new_num_allocated <= stack->num_stack_allocated_) {
              /* Overflow in allocation */
              return _AEX_PPTG_OVERFLOW;
            }
          }
          else {
            new_num_allocated = 16;
          }
          
          if (new_num_allocated > (SIZE_MAX / sizeof(struct aex_pptg_sym_data))) {
            /* Overflow in allocation */
            return _AEX_PPTG_OVERFLOW;
          }
          
          stack->new_buf_ = (struct aex_pptg_sym_data *)malloc(new_num_allocated * sizeof(struct aex_pptg_sym_data));
          if (!stack->new_buf_) {
            /* Out of memory */
            return _AEX_PPTG_NO_MEMORY;
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
                stack->continue_at_ = 6;
                {
#line 42 "grammar/pp/pp_trigraphs.cbrt"
                  aex_situs_init(&((stack->new_buf_ + stack->new_buf_sym_partial_pos_)->common_));
#line 2313 "src/pp/pp_trigraphs.c"
                }
                C6:;
                stack->continue_at_ = 7;
                {
#line 43 "grammar/pp/pp_trigraphs.cbrt"
                  aex_situs_swap(&stack->new_buf_[stack->new_buf_sym_partial_pos_].common_, &(stack->stack_[stack->new_buf_sym_partial_pos_].common_));
#line 2320 "src/pp/pp_trigraphs.c"
                }
                C7:;
                {
#line 44 "grammar/pp/pp_trigraphs.cbrt"
                  aex_situs_cleanup(&((stack->stack_ + stack->new_buf_sym_partial_pos_)->common_));
#line 2326 "src/pp/pp_trigraphs.c"
                }
                stack->stack_newbuf_pos_has_common_data_ = 0;
              }
            }
            else /* not 0 or 1, but >= 2 state derived sym */ {
              stack->newbuf_pos_has_common_data_ = 1;
              stack->continue_at_ = 8;
              {
#line 42 "grammar/pp/pp_trigraphs.cbrt"
                aex_situs_init(&((stack->new_buf_ + stack->new_buf_sym_partial_pos_)->common_));
#line 2337 "src/pp/pp_trigraphs.c"
              }
              C8:;
              stack->continue_at_ = 9;
              {
#line 43 "grammar/pp/pp_trigraphs.cbrt"
                aex_situs_swap(&stack->new_buf_[stack->new_buf_sym_partial_pos_].common_, &(stack->stack_[stack->new_buf_sym_partial_pos_].common_));
#line 2344 "src/pp/pp_trigraphs.c"
              }
              C9:;
              {
#line 44 "grammar/pp/pp_trigraphs.cbrt"
                aex_situs_cleanup(&((stack->stack_ + stack->new_buf_sym_partial_pos_)->common_));
#line 2350 "src/pp/pp_trigraphs.c"
              }
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
        stack->continue_at_ = 10;
        {
#line 42 "grammar/pp/pp_trigraphs.cbrt"
          aex_situs_init(&((stack->stack_ + stack->pos_ - 1)->common_));
#line 2370 "src/pp/pp_trigraphs.c"
        }
        C10:;
        stack->continue_at_ = 11;
        {
#line 43 "grammar/pp/pp_trigraphs.cbrt"
          aex_situs_swap(&stack->stack_[stack->pos_ - 1].common_, &(stack->stack_[1].common_));
#line 2377 "src/pp/pp_trigraphs.c"
        }
        C11:;
        {
#line 44 "grammar/pp/pp_trigraphs.cbrt"
          aex_situs_cleanup(&(stack->stack_[1].common_));
#line 2383 "src/pp/pp_trigraphs.c"
        }
        stack->slot_1_has_common_data_ = 0;
        stack->slot_1_has_sym_data_ = 0;
      } /* action < 0 */
      else /* action == 0 */ {
        /* check if we can recover using an error token. */
        size_t n;
        for (n = 0; n < stack->pos_; ++n) {
          stack->current_err_action_ = aex_pptg_parse_table[aex_pptg_num_columns * stack->stack_[n].state_ + (3 /* error token */ - aex_pptg_minimum_sym)];
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
          return _AEX_PPTG_SYNTAX_ERROR;
        }
        else {
          stack->mute_error_turns_--;
          if (sym == AEX_PPTG_INPUT_END) {
            /* EOF means we cannot shift to recover, and errors are muted, so return completion */
            stack->pending_reset_ = 1;
            return _AEX_PPTG_FINISH;
          }
          /* Retain EOF but discard any other sym so we make progress */
          stack->continue_at_ = 0;
          /* Next token */
          return _AEX_PPTG_FEED_ME;
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
          stack->current_err_action_ = aex_pptg_parse_table[aex_pptg_num_columns * stack->stack_[n].state_ + (3 /* error token */ - aex_pptg_minimum_sym)];
          if (stack->current_err_action_ > 0) {
            /* Does the resulting state accept the current symbol? */
            int err_sym_action;
            err_sym_action = aex_pptg_parse_table[aex_pptg_num_columns * stack->current_err_action_ + (sym - aex_pptg_minimum_sym)];
            if (err_sym_action) {
              /* Current symbol is accepted, recover error condition by shifting the error token and then process the symbol as usual */
              /* Free symdata for every symbol up to the state where we will shift the error token */
              for (stack->sym_idx_ = n + 1; stack->sym_idx_ < stack->pos_; ++stack->sym_idx_) {
                {
#line 44 "grammar/pp/pp_trigraphs.cbrt"
                  aex_situs_cleanup(&((stack->stack_ + stack->sym_idx_)->common_));
#line 2440 "src/pp/pp_trigraphs.c"
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
                    return _AEX_PPTG_OVERFLOW;
                  }
                }
                else {
                  new_num_allocated = 16;
                }
                
                if (new_num_allocated > (SIZE_MAX / sizeof(struct aex_pptg_sym_data))) {
                  /* Overflow in allocation */
                  return _AEX_PPTG_OVERFLOW;
                }
                
                stack->new_buf_ = (struct aex_pptg_sym_data *)malloc(new_num_allocated * sizeof(struct aex_pptg_sym_data));
                if (!stack->new_buf_) {
                  /* Out of memory */
                  return _AEX_PPTG_NO_MEMORY;
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
                      stack->continue_at_ = 12;
                      {
#line 42 "grammar/pp/pp_trigraphs.cbrt"
                        aex_situs_init(&((stack->new_buf_ + stack->new_buf_sym_partial_pos_)->common_));
#line 2492 "src/pp/pp_trigraphs.c"
                      }
                      C12:;
                      stack->continue_at_ = 13;
                      {
#line 43 "grammar/pp/pp_trigraphs.cbrt"
                        aex_situs_swap(&stack->new_buf_[stack->new_buf_sym_partial_pos_].common_, &(stack->stack_[stack->new_buf_sym_partial_pos_].common_));
#line 2499 "src/pp/pp_trigraphs.c"
                      }
                      C13:;
                      {
#line 44 "grammar/pp/pp_trigraphs.cbrt"
                        aex_situs_cleanup(&((stack->stack_ + stack->new_buf_sym_partial_pos_)->common_));
#line 2505 "src/pp/pp_trigraphs.c"
                      }
                      stack->stack_newbuf_pos_has_common_data_ = 0;
                    }
                  }
                  else /* not 0 or 1, but >= 2 state derived sym */ {
                    stack->newbuf_pos_has_common_data_ = 1;
                    stack->continue_at_ = 14;
                    {
#line 42 "grammar/pp/pp_trigraphs.cbrt"
                      aex_situs_init(&((stack->new_buf_ + stack->new_buf_sym_partial_pos_)->common_));
#line 2516 "src/pp/pp_trigraphs.c"
                    }
                    C14:;
                    stack->continue_at_ = 15;
                    {
#line 43 "grammar/pp/pp_trigraphs.cbrt"
                      aex_situs_swap(&stack->new_buf_[stack->new_buf_sym_partial_pos_].common_, &(stack->stack_[stack->new_buf_sym_partial_pos_].common_));
#line 2523 "src/pp/pp_trigraphs.c"
                    }
                    C15:;
                    {
#line 44 "grammar/pp/pp_trigraphs.cbrt"
                      aex_situs_cleanup(&((stack->stack_ + stack->new_buf_sym_partial_pos_)->common_));
#line 2529 "src/pp/pp_trigraphs.c"
                    }
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
        if (sym == AEX_PPTG_INPUT_END) {
          /* EOF means we cannot shift to recover, so return completion */
          stack->pending_reset_ = 1;
          return _AEX_PPTG_FINISH;
        }
        stack->continue_at_ = 0;
        /* Next token */
        return _AEX_PPTG_FEED_ME;
      }
    } /* stack->error_recovery_ */
  } /* for (;;) */
}
/* --------- END OF GENERATED CODE ------------ */
