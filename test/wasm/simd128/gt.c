/* Copyright (c) 2021 Evan Nemerson <evan@nemerson.com>
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#define SIMDE_TEST_WASM_SIMD128_INSN gt
#include "../../../simde/wasm/simd128.h"
#include "test-simd128.h"

static int
test_simde_wasm_i8x16_gt(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int8_t a[sizeof(simde_v128_t) / sizeof(int8_t)];
      int8_t b[sizeof(simde_v128_t) / sizeof(int8_t)];
      int8_t r[sizeof(simde_v128_t) / sizeof(int8_t)];
    } test_vec[8] = {
      { {  INT8_C( 120), -INT8_C( 104), -INT8_C(  37),  INT8_C(  28),  INT8_C(  93),  INT8_C( 123), -INT8_C(  70),  INT8_C(  51),
           INT8_C(  98), -INT8_C(  52), -INT8_C(   8),  INT8_C(  61), -INT8_C( 101), -INT8_C(  27), -INT8_C(  82), -INT8_C(  73) },
        { -INT8_C(  68),  INT8_C(  28),  INT8_C(  79),  INT8_C(  28), -INT8_C(  24), -INT8_C(  21),  INT8_C(  31), -INT8_C(  19),
          -INT8_C(  59), -INT8_C(  72), -INT8_C(  62),  INT8_C(  63), -INT8_C( 107),  INT8_C(  84), -INT8_C(  58), -INT8_C(  73) },
        { -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
          -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0) } },
      { { -INT8_C(  91),  INT8_C(  70),  INT8_C( 124), -INT8_C( 111), -INT8_C(  69),  INT8_C(  54),  INT8_C(   8),  INT8_C( 111),
          -INT8_C(  92),  INT8_C(  17),  INT8_C( 121), -INT8_C( 119), -INT8_C(  23),  INT8_C(  94),  INT8_C( 107),  INT8_C(  11) },
        { -INT8_C(  51),  INT8_C(  70),  INT8_C( 124), -INT8_C(  25),  INT8_C(  38),  INT8_C(  54),  INT8_C(  19), -INT8_C( 115),
          -INT8_C(  92), -INT8_C(  65),  INT8_C( 121), -INT8_C( 119), -INT8_C(  23),  INT8_C(  98),  INT8_C(   3),  INT8_C(  11) },
        {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
           INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0) } },
      { { -INT8_C(  77),  INT8_C(  37), -INT8_C(  23),  INT8_C(   1),  INT8_C( 124), -INT8_C(  96),  INT8_C(  41),  INT8_C(  85),
          -INT8_C(  89), -INT8_C(  25), -INT8_C(  24),  INT8_C(   0), -INT8_C(  28), -INT8_C(  10),  INT8_C(  98), -INT8_C( 106) },
        {  INT8_C(  45), -INT8_C(  24), -INT8_C(  23),  INT8_C(   1), -INT8_C(  52), -INT8_C(  96), -INT8_C( 125), -INT8_C(  44),
          -INT8_C(  89),  INT8_C(  65),  INT8_C(  32), -INT8_C(  42),  INT8_C(  97),  INT8_C( 102),  INT8_C(  41),  INT8_C(  22) },
        {  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
           INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0) } },
      { { -INT8_C( 112),  INT8_C(  42),  INT8_C(   2), -INT8_C( 105), -INT8_C(  89), -INT8_C(  10), -INT8_C(  56),  INT8_C(   0),
           INT8_C(  27), -INT8_C( 105), -INT8_C(  75),      INT8_MIN,  INT8_C(  51), -INT8_C(  98), -INT8_C(  59),  INT8_C(  63) },
        { -INT8_C(  69),  INT8_C(  42),  INT8_C(   2),  INT8_C(  48), -INT8_C( 104),  INT8_C( 116),  INT8_C(  37),  INT8_C( 112),
          -INT8_C(  44),  INT8_C(  79), -INT8_C(  59),  INT8_C(  75), -INT8_C(  12),  INT8_C(  20),  INT8_C(  81), -INT8_C(  15) },
        {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
          -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1) } },
      { { -INT8_C(  85),  INT8_C(  78), -INT8_C(  68),  INT8_C(  49),  INT8_C( 106), -INT8_C(  42), -INT8_C(  13), -INT8_C(  93),
           INT8_C(  61), -INT8_C(  18),  INT8_C(  83), -INT8_C(  84),  INT8_C(  45), -INT8_C(  69),  INT8_C(  49),  INT8_C(  99) },
        {  INT8_C(  75),  INT8_C(  77),  INT8_C(  41), -INT8_C(  64),  INT8_C( 121), -INT8_C(  20), -INT8_C(   5),  INT8_C(  85),
          -INT8_C(  90), -INT8_C(  18),  INT8_C(  83), -INT8_C(  92),  INT8_C(  36), -INT8_C(  15), -INT8_C(  41), -INT8_C(  52) },
        {  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
          -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1) } },
      { {  INT8_C(   8),  INT8_C(  33),  INT8_C(  55),  INT8_C(   7),  INT8_C(  14), -INT8_C(  42),  INT8_C(   6),  INT8_C(   4),
          -INT8_C(  88),  INT8_C(  53),  INT8_C(  60), -INT8_C(  24),  INT8_C(  28),  INT8_C(  94), -INT8_C( 106),      INT8_MIN },
        {  INT8_C( 110),  INT8_C(  80), -INT8_C( 104), -INT8_C(  95),  INT8_C(  82),  INT8_C(  27),  INT8_C( 102),  INT8_C(  50),
           INT8_C(  10),  INT8_C(  53),  INT8_C(  60), -INT8_C( 104), -INT8_C(  17),  INT8_C(  94), -INT8_C(  89),      INT8_MIN },
        {  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
           INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0) } },
      { { -INT8_C(  28), -INT8_C(  54),  INT8_C(  94), -INT8_C(  44), -INT8_C(  39),  INT8_C(  85),  INT8_C( 118),  INT8_C( 107),
          -INT8_C( 119),  INT8_C(  57),  INT8_C(  63), -INT8_C(  84),  INT8_C(  63),  INT8_C( 120), -INT8_C(  51),  INT8_C(  12) },
        { -INT8_C(  28), -INT8_C(  59),  INT8_C(  94),  INT8_C(  34),  INT8_C(  52), -INT8_C(  82), -INT8_C( 109), -INT8_C(  43),
          -INT8_C(  81),  INT8_C(  57),  INT8_C(  63),  INT8_C(  30), -INT8_C(  90),  INT8_C( 120), -INT8_C(  81), -INT8_C(  79) },
        {  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
           INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1) } },
      { {  INT8_C( 110), -INT8_C(  35), -INT8_C( 124),  INT8_C(  27),  INT8_C( 104),  INT8_C(   6),  INT8_C(  17),  INT8_C( 122),
          -INT8_C(  96), -INT8_C(   4), -INT8_C( 108), -INT8_C(  99),  INT8_C(   0), -INT8_C( 112),  INT8_C(  78), -INT8_C(   4) },
        { -INT8_C(  21),  INT8_C(  49),  INT8_C(  96), -INT8_C(   2), -INT8_C( 122), -INT8_C(  58), -INT8_C(  40),  INT8_C(   0),
           INT8_C(  39), -INT8_C(   4),  INT8_C( 121),  INT8_C(  30),  INT8_C(  55), -INT8_C(  57), -INT8_C(   3), -INT8_C( 107) },
        { -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
           INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_i8x16_gt(a, b);
      simde_test_wasm_i8x16_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      int8_t a_[sizeof(simde_v128_t) / sizeof(int8_t)];
      int8_t b_[sizeof(simde_v128_t) / sizeof(int8_t)];
      simde_v128_t a, b, r;

      simde_test_codegen_random_memory(sizeof(a_), HEDLEY_REINTERPRET_CAST(uint8_t*, a_));
      simde_test_codegen_random_memory(sizeof(b_), HEDLEY_REINTERPRET_CAST(uint8_t*, b_));
      for (size_t j = 0 ; j < (sizeof(a_) / sizeof(a_[0])) ; j++)
        if ((simde_test_codegen_random_i8() & 3) == 0)
          b_[j] = a_[j];

      a = simde_wasm_v128_load(a_);
      b = simde_wasm_v128_load(b_);
      r = simde_wasm_i8x16_gt(a, b);

      simde_test_wasm_i8x16_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_i8x16_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_i8x16_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_i16x8_gt(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int16_t a[sizeof(simde_v128_t) / sizeof(int16_t)];
      int16_t b[sizeof(simde_v128_t) / sizeof(int16_t)];
      int16_t r[sizeof(simde_v128_t) / sizeof(int16_t)];
    } test_vec[8] = {
      { { -INT16_C( 27878), -INT16_C(  3954), -INT16_C( 15609),  INT16_C( 29201), -INT16_C( 31843), -INT16_C(  2506),  INT16_C( 30424),  INT16_C( 30605) },
        { -INT16_C( 27878),  INT16_C(    14),  INT16_C( 14511),  INT16_C( 10099), -INT16_C( 32335), -INT16_C(  2156),  INT16_C( 30424),  INT16_C( 23803) },
        {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1) } },
      { {  INT16_C( 28754), -INT16_C( 29154), -INT16_C( 25464),  INT16_C( 16122), -INT16_C(  9208), -INT16_C( 10715),  INT16_C(  4466),  INT16_C( 27560) },
        {  INT16_C( 14667), -INT16_C( 16384),  INT16_C( 28791),  INT16_C( 14975), -INT16_C(  4668),  INT16_C( 15260), -INT16_C(  2134),  INT16_C( 27560) },
        { -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0) } },
      { {  INT16_C( 13086), -INT16_C( 21981), -INT16_C( 22291), -INT16_C(  5347),  INT16_C(  6252), -INT16_C( 16974),  INT16_C( 22019), -INT16_C( 13990) },
        {  INT16_C( 13086),  INT16_C(  9318), -INT16_C(  4202), -INT16_C(  2719),  INT16_C( 31514),  INT16_C( 22550),  INT16_C( 27029), -INT16_C( 13990) },
        {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
      { {  INT16_C(  4600), -INT16_C( 20613), -INT16_C( 23513),  INT16_C( 10764), -INT16_C( 23014), -INT16_C(  1008),  INT16_C(  6593),  INT16_C(  6963) },
        { -INT16_C( 29411),  INT16_C(  7887), -INT16_C(  4937),  INT16_C( 31470),  INT16_C(  4995),  INT16_C( 32412),  INT16_C( 23234), -INT16_C( 21517) },
        { -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1) } },
      { { -INT16_C(   297),  INT16_C( 12831),  INT16_C( 22603), -INT16_C( 26136), -INT16_C( 15500),  INT16_C( 32303), -INT16_C(  1014), -INT16_C( 21224) },
        {  INT16_C( 31604),  INT16_C( 12831), -INT16_C(  8216), -INT16_C( 18709),  INT16_C(  5697),  INT16_C( 27004),  INT16_C( 21187),  INT16_C( 11538) },
        {  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0) } },
      { { -INT16_C( 13425),  INT16_C( 20822),  INT16_C( 17768),  INT16_C( 23191),  INT16_C( 24498),  INT16_C(  5752),  INT16_C(  5811), -INT16_C(  8299) },
        { -INT16_C( 17421), -INT16_C( 21397), -INT16_C( 13326), -INT16_C( 22702),  INT16_C( 24498),  INT16_C(  5752),  INT16_C( 15910), -INT16_C(  8299) },
        { -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
      { {  INT16_C(  7160), -INT16_C( 29292),  INT16_C(  7127),  INT16_C(  8955), -INT16_C( 20557),  INT16_C(  2443), -INT16_C( 18112), -INT16_C( 19386) },
        { -INT16_C( 25710), -INT16_C( 11642), -INT16_C(  2212),  INT16_C( 32060),  INT16_C( 25931), -INT16_C( 14754),  INT16_C(  5644), -INT16_C( 10268) },
        { -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0) } },
      { { -INT16_C( 27468), -INT16_C( 14413), -INT16_C( 22324),  INT16_C( 13677),  INT16_C( 29560), -INT16_C(  2116), -INT16_C( 31338),  INT16_C( 26767) },
        { -INT16_C( 27468), -INT16_C( 14413), -INT16_C( 24954), -INT16_C( 17311),  INT16_C( 29560),  INT16_C( 24449), -INT16_C(  1834),  INT16_C(  2936) },
        {  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_i16x8_gt(a, b);
      simde_test_wasm_i16x8_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      int16_t a_[sizeof(simde_v128_t) / sizeof(int16_t)];
      int16_t b_[sizeof(simde_v128_t) / sizeof(int16_t)];
      simde_v128_t a, b, r;

      simde_test_codegen_random_memory(sizeof(a_), HEDLEY_REINTERPRET_CAST(uint8_t*, a_));
      simde_test_codegen_random_memory(sizeof(b_), HEDLEY_REINTERPRET_CAST(uint8_t*, b_));
      for (size_t j = 0 ; j < (sizeof(a_) / sizeof(a_[0])) ; j++)
        if ((simde_test_codegen_random_i8() & 3) == 0)
          b_[j] = a_[j];

      a = simde_wasm_v128_load(a_);
      b = simde_wasm_v128_load(b_);
      r = simde_wasm_i16x8_gt(a, b);

      simde_test_wasm_i16x8_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_i16x8_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_i16x8_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_i32x4_gt(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int32_t a[sizeof(simde_v128_t) / sizeof(int32_t)];
      int32_t b[sizeof(simde_v128_t) / sizeof(int32_t)];
      int32_t r[sizeof(simde_v128_t) / sizeof(int32_t)];
    } test_vec[8] = {
      { {  INT32_C(   585754791), -INT32_C(  1422463462),  INT32_C(   845196096), -INT32_C(   786973175) },
        {  INT32_C(   675930469), -INT32_C(  1968971350), -INT32_C(   231548217), -INT32_C(   786973175) },
        {  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0) } },
      { {  INT32_C(   623183880),  INT32_C(  1357702556),  INT32_C(  1005708208),  INT32_C(  1734772658) },
        {  INT32_C(   603577638), -INT32_C(   425140975),  INT32_C(  1005708208),  INT32_C(   489779981) },
        { -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1) } },
      { { -INT32_C(    15472369),  INT32_C(  2105574877), -INT32_C(  1420369661), -INT32_C(  1638450800) },
        {  INT32_C(  2013991617), -INT32_C(  1896741416), -INT32_C(  2057875434),  INT32_C(  1088390214) },
        {  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0) } },
      { {  INT32_C(   167974981),  INT32_C(   309776056), -INT32_C(  1121810496),  INT32_C(  1922200829) },
        {  INT32_C(   167974981),  INT32_C(   300946559),  INT32_C(   489429762),  INT32_C(   818103913) },
        {  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1) } },
      { { -INT32_C(   994859684),  INT32_C(   522775052), -INT32_C(   208693728),  INT32_C(   514465742) },
        { -INT32_C(   994859684),  INT32_C(  1988783829), -INT32_C(  1542162100),  INT32_C(    28632828) },
        {  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1) } },
      { { -INT32_C(  1442584401),  INT32_C(  1140942803),  INT32_C(  2007671099),  INT32_C(   639900796) },
        { -INT32_C(  1442584401),  INT32_C(  1001890932), -INT32_C(  1647814219),  INT32_C(   616201031) },
        {  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1) } },
      { {  INT32_C(   732197036),  INT32_C(  1518198776), -INT32_C(   342237284), -INT32_C(  1415389865) },
        { -INT32_C(  1219916322),  INT32_C(  1518198776),  INT32_C(  2138690440), -INT32_C(  1415389865) },
        { -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
      { {  INT32_C(   356302798),  INT32_C(  1033519531),  INT32_C(   256964056), -INT32_C(   309231831) },
        { -INT32_C(    50961522),  INT32_C(  1033519531), -INT32_C(   860135596), -INT32_C(   309231831) },
        { -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_i32x4_gt(a, b);
      simde_test_wasm_i32x4_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      int32_t a_[sizeof(simde_v128_t) / sizeof(int32_t)];
      int32_t b_[sizeof(simde_v128_t) / sizeof(int32_t)];
      simde_v128_t a, b, r;

      simde_test_codegen_random_memory(sizeof(a_), HEDLEY_REINTERPRET_CAST(uint8_t*, a_));
      simde_test_codegen_random_memory(sizeof(b_), HEDLEY_REINTERPRET_CAST(uint8_t*, b_));
      for (size_t j = 0 ; j < (sizeof(a_) / sizeof(a_[0])) ; j++)
        if ((simde_test_codegen_random_i8() & 3) == 0)
          b_[j] = a_[j];

      a = simde_wasm_v128_load(a_);
      b = simde_wasm_v128_load(b_);
      r = simde_wasm_i32x4_gt(a, b);

      simde_test_wasm_i32x4_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_i32x4_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_i32x4_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_i64x2_gt(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int64_t a[sizeof(simde_v128_t) / sizeof(int64_t)];
      int64_t b[sizeof(simde_v128_t) / sizeof(int64_t)];
      int64_t r[sizeof(simde_v128_t) / sizeof(int64_t)];
    } test_vec[8] = {
      { {  INT64_C( 2131478625892993833), -INT64_C(  712578540201732027) },
        {  INT64_C( 2131478625892993833), -INT64_C( 5943097491368088641) },
        {  INT64_C(                   0), -INT64_C(                   1) } },
      { { -INT64_C(  704814492408381186), -INT64_C( 5872335032925907771) },
        {  INT64_C( 6266363232300025114),  INT64_C( 3116386802555038556) },
        {  INT64_C(                   0),  INT64_C(                   0) } },
      { { -INT64_C( 7741416866796473784), -INT64_C( 5328464245603584993) },
        { -INT64_C( 7741416866796473784), -INT64_C( 5328464245603584993) },
        {  INT64_C(                   0),  INT64_C(                   0) } },
      { { -INT64_C( 7884841348396969547), -INT64_C( 7792206112914251394) },
        { -INT64_C( 6087611157645495993), -INT64_C( 2432932328815403322) },
        {  INT64_C(                   0),  INT64_C(                   0) } },
      { {  INT64_C( 3902550414608993856), -INT64_C( 1646551632425448733) },
        {  INT64_C( 3331779560192916812),  INT64_C( 1466377459891120423) },
        { -INT64_C(                   1),  INT64_C(                   0) } },
      { { -INT64_C( 3022346587661201127),  INT64_C( 1980810567952053976) },
        { -INT64_C( 3022346587661201127),  INT64_C( 3049077502695675204) },
        {  INT64_C(                   0),  INT64_C(                   0) } },
      { {  INT64_C( 1833955735272381432), -INT64_C( 1282193252917641726) },
        {  INT64_C( 1833955735272381432), -INT64_C( 1282193252917641726) },
        {  INT64_C(                   0),  INT64_C(                   0) } },
      { {  INT64_C( 1613927108009623988),  INT64_C( 6924391537313355291) },
        {  INT64_C(  701981918902777394), -INT64_C( 8806929960637183368) },
        { -INT64_C(                   1), -INT64_C(                   1) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_i64x2_gt(a, b);
      simde_test_wasm_i64x2_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      int64_t a_[sizeof(simde_v128_t) / sizeof(int64_t)];
      int64_t b_[sizeof(simde_v128_t) / sizeof(int64_t)];
      simde_v128_t a, b, r;

      simde_test_codegen_random_memory(sizeof(a_), HEDLEY_REINTERPRET_CAST(uint8_t*, a_));
      simde_test_codegen_random_memory(sizeof(b_), HEDLEY_REINTERPRET_CAST(uint8_t*, b_));
      for (size_t j = 0 ; j < (sizeof(a_) / sizeof(a_[0])) ; j++)
        if ((simde_test_codegen_random_i8() & 3) == 0)
          b_[j] = a_[j];

      a = simde_wasm_v128_load(a_);
      b = simde_wasm_v128_load(b_);
      r = simde_wasm_i64x2_gt(a, b);

      simde_test_wasm_i64x2_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_i64x2_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_i64x2_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_u8x16_gt(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      uint8_t a[sizeof(simde_v128_t) / sizeof(uint8_t)];
      uint8_t b[sizeof(simde_v128_t) / sizeof(uint8_t)];
      uint8_t r[sizeof(simde_v128_t) / sizeof(uint8_t)];
    } test_vec[8] = {
      { { UINT8_C(115), UINT8_C( 76), UINT8_C( 40), UINT8_C( 49), UINT8_C(175), UINT8_C(230), UINT8_C( 96), UINT8_C(133),
          UINT8_C( 99), UINT8_C(134), UINT8_C( 30), UINT8_C(180),    UINT8_MAX, UINT8_C( 59), UINT8_C(200), UINT8_C(212) },
        { UINT8_C( 69), UINT8_C(186), UINT8_C( 97), UINT8_C(226), UINT8_C( 59), UINT8_C(254), UINT8_C( 96), UINT8_C(195),
          UINT8_C(141), UINT8_C(134), UINT8_C(250), UINT8_C(193), UINT8_C( 68), UINT8_C( 59), UINT8_C(250), UINT8_C(126) },
        {    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
          UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX } },
      { { UINT8_C(180), UINT8_C(182), UINT8_C( 28), UINT8_C( 52), UINT8_C(127), UINT8_C(160), UINT8_C(174), UINT8_C(105),
          UINT8_C(180), UINT8_C(139), UINT8_C(143), UINT8_C(175), UINT8_C( 37), UINT8_C( 86), UINT8_C(217), UINT8_C(153) },
        { UINT8_C(131), UINT8_C( 65), UINT8_C(139), UINT8_C(246), UINT8_C(127), UINT8_C(225), UINT8_C( 55), UINT8_C( 18),
          UINT8_C(  8), UINT8_C(139),    UINT8_MAX, UINT8_C(175), UINT8_C(158), UINT8_C(130), UINT8_C( 45), UINT8_C(153) },
        {    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,
             UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0) } },
      { { UINT8_C(146), UINT8_C(222), UINT8_C(247), UINT8_C(235), UINT8_C(138), UINT8_C( 99), UINT8_C( 45), UINT8_C( 39),
          UINT8_C(190), UINT8_C( 44), UINT8_C(220), UINT8_C( 82), UINT8_C( 66), UINT8_C(170), UINT8_C( 97), UINT8_C( 20) },
        { UINT8_C(146), UINT8_C(222), UINT8_C( 37), UINT8_C( 39), UINT8_C(138), UINT8_C(236), UINT8_C( 45), UINT8_C(224),
          UINT8_C(190), UINT8_C(169), UINT8_C(220), UINT8_C( 82), UINT8_C( 66), UINT8_C(164), UINT8_C( 97), UINT8_C( 20) },
        { UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
          UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0) } },
      { { UINT8_C(178), UINT8_C(124), UINT8_C(215), UINT8_C(213), UINT8_C(203), UINT8_C(122), UINT8_C(130), UINT8_C(137),
          UINT8_C(138), UINT8_C( 27), UINT8_C(157), UINT8_C(227), UINT8_C(187), UINT8_C( 52), UINT8_C(141), UINT8_C(179) },
        { UINT8_C( 76), UINT8_C( 65), UINT8_C( 26), UINT8_C(213), UINT8_C(203), UINT8_C( 73), UINT8_C(130), UINT8_C(137),
          UINT8_C(138), UINT8_C(242), UINT8_C(126), UINT8_C( 82), UINT8_C(171), UINT8_C(203), UINT8_C(192), UINT8_C(188) },
        {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),
          UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) } },
      { { UINT8_C( 65), UINT8_C(212), UINT8_C(196), UINT8_C( 62), UINT8_C(116), UINT8_C(148), UINT8_C(222), UINT8_C(120),
          UINT8_C(169), UINT8_C(109), UINT8_C( 60), UINT8_C(131), UINT8_C(218), UINT8_C(115), UINT8_C( 35), UINT8_C(122) },
        { UINT8_C( 53), UINT8_C(138), UINT8_C(196), UINT8_C( 46), UINT8_C(166), UINT8_C( 64), UINT8_C(185), UINT8_C(237),
          UINT8_C(156), UINT8_C(100), UINT8_C( 79), UINT8_C( 46), UINT8_C(195), UINT8_C(137), UINT8_C(  8), UINT8_C(122) },
        {    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),
             UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0) } },
      { { UINT8_C( 78), UINT8_C(143), UINT8_C( 73), UINT8_C( 71), UINT8_C(179), UINT8_C(125), UINT8_C( 41), UINT8_C(  9),
          UINT8_C(233), UINT8_C( 34), UINT8_C(136), UINT8_C( 92), UINT8_C(117), UINT8_C( 24), UINT8_C(193), UINT8_C(  3) },
        { UINT8_C( 70), UINT8_C(135), UINT8_C( 73), UINT8_C( 53), UINT8_C(179), UINT8_C(122), UINT8_C( 41), UINT8_C( 31),
          UINT8_C( 37), UINT8_C( 26), UINT8_C(126), UINT8_C(239), UINT8_C(137), UINT8_C( 15), UINT8_C(193), UINT8_C(159) },
        {    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),
             UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0) } },
      { { UINT8_C( 26), UINT8_C(216), UINT8_C(234), UINT8_C( 87), UINT8_C(193), UINT8_C(243), UINT8_C(125), UINT8_C(201),
          UINT8_C(184), UINT8_C(155), UINT8_C(240), UINT8_C(  4), UINT8_C(173), UINT8_C(146), UINT8_C( 34), UINT8_C(152) },
        { UINT8_C( 61), UINT8_C(216), UINT8_C(234), UINT8_C(168), UINT8_C(193), UINT8_C(227), UINT8_C(178), UINT8_C(198),
          UINT8_C(134), UINT8_C(155), UINT8_C(244), UINT8_C( 69), UINT8_C(173), UINT8_C(  0), UINT8_C(192), UINT8_C(129) },
        { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,
             UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX } },
      { { UINT8_C(211), UINT8_C( 46), UINT8_C(  0), UINT8_C(124), UINT8_C(213), UINT8_C( 34), UINT8_C( 94), UINT8_C(236),
          UINT8_C(192), UINT8_C(157), UINT8_C(226), UINT8_C(137), UINT8_C( 69), UINT8_C(249), UINT8_C(235), UINT8_C(205) },
        { UINT8_C( 66), UINT8_C( 65), UINT8_C(148), UINT8_C(124), UINT8_C(135), UINT8_C( 34), UINT8_C(135), UINT8_C(100),
          UINT8_C(240), UINT8_C(157), UINT8_C( 77), UINT8_C(215), UINT8_C( 69), UINT8_C( 39), UINT8_C( 20), UINT8_C(205) },
        {    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,
          UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_u8x16_gt(a, b);
      simde_test_wasm_u8x16_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      uint8_t a_[sizeof(simde_v128_t) / sizeof(uint8_t)];
      uint8_t b_[sizeof(simde_v128_t) / sizeof(uint8_t)];
      simde_v128_t a, b, r;

      simde_test_codegen_random_memory(sizeof(a_), HEDLEY_REINTERPRET_CAST(uint8_t*, a_));
      simde_test_codegen_random_memory(sizeof(b_), HEDLEY_REINTERPRET_CAST(uint8_t*, b_));
      for (size_t j = 0 ; j < (sizeof(a_) / sizeof(a_[0])) ; j++)
        if ((simde_test_codegen_random_u8() & 3) == 0)
          b_[j] = a_[j];

      a = simde_wasm_v128_load(a_);
      b = simde_wasm_v128_load(b_);
      r = simde_wasm_u8x16_gt(a, b);

      simde_test_wasm_u8x16_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_u8x16_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_u8x16_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_u16x8_gt(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      uint16_t a[sizeof(simde_v128_t) / sizeof(uint16_t)];
      uint16_t b[sizeof(simde_v128_t) / sizeof(uint16_t)];
      uint16_t r[sizeof(simde_v128_t) / sizeof(uint16_t)];
    } test_vec[8] = {
      { { UINT16_C(31575), UINT16_C(15493), UINT16_C(12642), UINT16_C(46907), UINT16_C(18237), UINT16_C(45007), UINT16_C(54795), UINT16_C(12673) },
        { UINT16_C(31575), UINT16_C(15493), UINT16_C(12642), UINT16_C(46907), UINT16_C(18237), UINT16_C(16069), UINT16_C(35841), UINT16_C(37096) },
        { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0) } },
      { { UINT16_C(30240), UINT16_C(41641), UINT16_C(34895), UINT16_C(18101), UINT16_C(59484), UINT16_C(20790), UINT16_C(30509), UINT16_C(49079) },
        { UINT16_C(35459), UINT16_C(55386), UINT16_C(34895), UINT16_C(35418), UINT16_C(32611), UINT16_C(44690), UINT16_C(12594), UINT16_C(55657) },
        { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0) } },
      { { UINT16_C(24764), UINT16_C(37263), UINT16_C(38921), UINT16_C( 8980), UINT16_C(38687), UINT16_C(25787), UINT16_C(57898), UINT16_C(45697) },
        { UINT16_C(60318), UINT16_C(37263), UINT16_C(51138), UINT16_C(32311), UINT16_C(40765), UINT16_C( 7720), UINT16_C( 3502), UINT16_C( 8801) },
        { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX } },
      { { UINT16_C(59648), UINT16_C( 8837), UINT16_C(18119), UINT16_C(51290), UINT16_C( 8519), UINT16_C(10761), UINT16_C(59761), UINT16_C( 3699) },
        { UINT16_C(65368), UINT16_C(56478), UINT16_C(18925), UINT16_C(45804), UINT16_C( 6767), UINT16_C(22477), UINT16_C(25521), UINT16_C( 3699) },
        { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0) } },
      { { UINT16_C(61168), UINT16_C(32685), UINT16_C(   68), UINT16_C(51553), UINT16_C(40804), UINT16_C(43664), UINT16_C(38605), UINT16_C( 4427) },
        { UINT16_C(61168), UINT16_C(32685), UINT16_C( 1276), UINT16_C(62025), UINT16_C(62587), UINT16_C(23313), UINT16_C(38605), UINT16_C(52962) },
        { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    0) } },
      { { UINT16_C(18909), UINT16_C(54175), UINT16_C(45117), UINT16_C(57161), UINT16_C(59404), UINT16_C(56978), UINT16_C( 6539), UINT16_C( 9389) },
        { UINT16_C(18909), UINT16_C(52246), UINT16_C(52380), UINT16_C(64948), UINT16_C(  264), UINT16_C(56978), UINT16_C(27745), UINT16_C(22729) },
        { UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
      { { UINT16_C(61189), UINT16_C( 5830), UINT16_C(31861), UINT16_C(65327), UINT16_C(50674), UINT16_C(26897), UINT16_C(23721), UINT16_C(34532) },
        { UINT16_C( 6053), UINT16_C(50971), UINT16_C(49729), UINT16_C( 1328), UINT16_C(26502), UINT16_C( 1067), UINT16_C(  374), UINT16_C(34532) },
        {      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0) } },
      { { UINT16_C(11098), UINT16_C( 4536), UINT16_C(20185), UINT16_C(45518), UINT16_C(65134), UINT16_C(47030), UINT16_C(37030), UINT16_C(15944) },
        { UINT16_C(49491), UINT16_C(56197), UINT16_C( 4426), UINT16_C(45518), UINT16_C(65134), UINT16_C(55195), UINT16_C(50550), UINT16_C(31467) },
        { UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_u16x8_gt(a, b);
      simde_test_wasm_u16x8_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      uint16_t a_[sizeof(simde_v128_t) / sizeof(uint16_t)];
      uint16_t b_[sizeof(simde_v128_t) / sizeof(uint16_t)];
      simde_v128_t a, b, r;

      simde_test_codegen_random_memory(sizeof(a_), HEDLEY_REINTERPRET_CAST(uint8_t*, a_));
      simde_test_codegen_random_memory(sizeof(b_), HEDLEY_REINTERPRET_CAST(uint8_t*, b_));
      for (size_t j = 0 ; j < (sizeof(a_) / sizeof(a_[0])) ; j++)
        if ((simde_test_codegen_random_u8() & 3) == 0)
          b_[j] = a_[j];

      a = simde_wasm_v128_load(a_);
      b = simde_wasm_v128_load(b_);
      r = simde_wasm_u16x8_gt(a, b);

      simde_test_wasm_u16x8_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_u16x8_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_u16x8_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_u32x4_gt(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      uint32_t a[sizeof(simde_v128_t) / sizeof(uint32_t)];
      uint32_t b[sizeof(simde_v128_t) / sizeof(uint32_t)];
      uint32_t r[sizeof(simde_v128_t) / sizeof(uint32_t)];
    } test_vec[8] = {
      { { UINT32_C( 188912771), UINT32_C(2788026563), UINT32_C( 976899419), UINT32_C(3358646453) },
        { UINT32_C( 188912771), UINT32_C(1678920779), UINT32_C(2393342953), UINT32_C(2621714475) },
        { UINT32_C(         0),           UINT32_MAX, UINT32_C(         0),           UINT32_MAX } },
      { { UINT32_C( 916545409), UINT32_C(1326924160), UINT32_C(2110997944), UINT32_C(1665014436) },
        { UINT32_C(3118032046), UINT32_C(2204810359), UINT32_C(2490296476), UINT32_C(1521075650) },
        { UINT32_C(         0), UINT32_C(         0), UINT32_C(         0),           UINT32_MAX } },
      { { UINT32_C(4088411739), UINT32_C(2973173974), UINT32_C(2896602836), UINT32_C(2337001575) },
        { UINT32_C(3520380206), UINT32_C(2381336132), UINT32_C( 966249192), UINT32_C(2337001575) },
        {           UINT32_MAX,           UINT32_MAX,           UINT32_MAX, UINT32_C(         0) } },
      { { UINT32_C(3430399948), UINT32_C(3537080801), UINT32_C(1328948455), UINT32_C(3871165508) },
        { UINT32_C(1061153791), UINT32_C(3537080801), UINT32_C(3050244498), UINT32_C(1170442206) },
        {           UINT32_MAX, UINT32_C(         0), UINT32_C(         0),           UINT32_MAX } },
      { { UINT32_C(3698235557), UINT32_C( 843253984), UINT32_C( 915960719), UINT32_C( 482898893) },
        { UINT32_C(4013792471), UINT32_C(3183022437), UINT32_C( 819390500), UINT32_C(3002343505) },
        { UINT32_C(         0), UINT32_C(         0),           UINT32_MAX, UINT32_C(         0) } },
      { { UINT32_C(4018336100), UINT32_C(2335651664), UINT32_C( 132213328), UINT32_C(2832688568) },
        { UINT32_C( 645253727), UINT32_C(3042488051), UINT32_C( 132213328), UINT32_C(2832688568) },
        {           UINT32_MAX, UINT32_C(         0), UINT32_C(         0), UINT32_C(         0) } },
      { { UINT32_C(3289497728), UINT32_C(2336307909), UINT32_C(2346786183), UINT32_C(3723283992) },
        { UINT32_C(3823329554), UINT32_C(3982479683), UINT32_C(2346786183), UINT32_C(1239136578) },
        { UINT32_C(         0), UINT32_C(         0), UINT32_C(         0),           UINT32_MAX } },
      { { UINT32_C(2515262078), UINT32_C(2252629301), UINT32_C(3463789401), UINT32_C( 509870530) },
        { UINT32_C(2515262078), UINT32_C(1724831104), UINT32_C(3463789401), UINT32_C( 226959335) },
        { UINT32_C(         0),           UINT32_MAX, UINT32_C(         0),           UINT32_MAX } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_u32x4_gt(a, b);
      simde_test_wasm_u32x4_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      uint32_t a_[sizeof(simde_v128_t) / sizeof(uint32_t)];
      uint32_t b_[sizeof(simde_v128_t) / sizeof(uint32_t)];
      simde_v128_t a, b, r;

      simde_test_codegen_random_memory(sizeof(a_), HEDLEY_REINTERPRET_CAST(uint8_t*, a_));
      simde_test_codegen_random_memory(sizeof(b_), HEDLEY_REINTERPRET_CAST(uint8_t*, b_));
      for (size_t j = 0 ; j < (sizeof(a_) / sizeof(a_[0])) ; j++)
        if ((simde_test_codegen_random_u8() & 3) == 0)
          b_[j] = a_[j];

      a = simde_wasm_v128_load(a_);
      b = simde_wasm_v128_load(b_);
      r = simde_wasm_u32x4_gt(a, b);

      simde_test_wasm_u32x4_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_u32x4_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_u32x4_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_f32x4_gt(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      simde_float32 a[sizeof(simde_v128_t) / sizeof(simde_float32)];
      simde_float32 b[sizeof(simde_v128_t) / sizeof(simde_float32)];
      int32_t r[sizeof(simde_v128_t) / sizeof(simde_float32)];
    } test_vec[8] = {
      { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -919.54),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -471.64) },
        { SIMDE_FLOAT32_C(   508.37),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -471.64) },
        {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
      { { SIMDE_FLOAT32_C(   449.10), SIMDE_FLOAT32_C(   969.37), SIMDE_FLOAT32_C(  -434.52), SIMDE_FLOAT32_C(   387.61) },
        { SIMDE_FLOAT32_C(  -544.94), SIMDE_FLOAT32_C(    65.41), SIMDE_FLOAT32_C(   -23.24), SIMDE_FLOAT32_C(   972.81) },
        { -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0) } },
      { { SIMDE_FLOAT32_C(  -528.49), SIMDE_FLOAT32_C(    97.69), SIMDE_FLOAT32_C(   428.79), SIMDE_FLOAT32_C(  -755.67) },
        { SIMDE_FLOAT32_C(  -375.14), SIMDE_FLOAT32_C(  -313.14), SIMDE_FLOAT32_C(  -926.31), SIMDE_FLOAT32_C(  -684.00) },
        {  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0) } },
      { { SIMDE_FLOAT32_C(   321.01), SIMDE_FLOAT32_C(   291.68), SIMDE_FLOAT32_C(   429.59), SIMDE_FLOAT32_C(   962.87) },
        { SIMDE_FLOAT32_C(  -274.18), SIMDE_FLOAT32_C(  -215.26), SIMDE_FLOAT32_C(  -797.89), SIMDE_FLOAT32_C(   -24.82) },
        { -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1) } },
      { { SIMDE_FLOAT32_C(   768.64), SIMDE_FLOAT32_C(  -762.74), SIMDE_FLOAT32_C(   914.92), SIMDE_FLOAT32_C(   165.89) },
        { SIMDE_FLOAT32_C(  -132.13), SIMDE_FLOAT32_C(   495.38), SIMDE_FLOAT32_C(   384.80), SIMDE_FLOAT32_C(   625.12) },
        { -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0) } },
      { { SIMDE_FLOAT32_C(  -554.31), SIMDE_FLOAT32_C(   212.38), SIMDE_FLOAT32_C(  -323.57), SIMDE_FLOAT32_C(   317.38) },
        { SIMDE_FLOAT32_C(   188.95), SIMDE_FLOAT32_C(  -151.08), SIMDE_FLOAT32_C(  -685.80), SIMDE_FLOAT32_C(  -653.47) },
        {  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1) } },
      { { SIMDE_FLOAT32_C(    43.67), SIMDE_FLOAT32_C(   575.14), SIMDE_FLOAT32_C(  -368.30), SIMDE_FLOAT32_C(  -868.74) },
        { SIMDE_FLOAT32_C(  -536.03), SIMDE_FLOAT32_C(  -295.32), SIMDE_FLOAT32_C(   806.02), SIMDE_FLOAT32_C(  -500.26) },
        { -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0) } },
      { { SIMDE_FLOAT32_C(  -894.97), SIMDE_FLOAT32_C(   110.82), SIMDE_FLOAT32_C(   465.41), SIMDE_FLOAT32_C(  -715.46) },
        { SIMDE_FLOAT32_C(  -396.79), SIMDE_FLOAT32_C(   439.57), SIMDE_FLOAT32_C(  -202.11), SIMDE_FLOAT32_C(  -693.34) },
        {  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_f32x4_gt(a, b);
      simde_test_wasm_i32x4_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    simde_float32 inputs[8 * 2 * (sizeof(simde_v128_t) / sizeof(simde_float32))];
    simde_test_wasm_f32x4_random_full(8, 2, inputs, -SIMDE_FLOAT32_C(1000.0), SIMDE_FLOAT32_C(1000.0), HEDLEY_STATIC_CAST(SimdeTestVecFloatType, SIMDE_TEST_VEC_FLOAT_NAN | SIMDE_TEST_VEC_FLOAT_EQUAL));
    for (size_t i = 0 ; i < 8 ; i++) {
      simde_v128_t
        a = simde_test_wasm_f32x4_random_full_extract(2, inputs, i, 0),
        b = simde_test_wasm_f32x4_random_full_extract(2, inputs, i, 1),
        r;

      r = simde_wasm_f32x4_gt(a, b);

      simde_test_wasm_f32x4_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_f32x4_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_i32x4_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_f64x2_gt(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      simde_float64 a[sizeof(simde_v128_t) / sizeof(simde_float64)];
      simde_float64 b[sizeof(simde_v128_t) / sizeof(simde_float64)];
      int64_t r[sizeof(simde_v128_t) / sizeof(simde_float64)];
    } test_vec[8] = {
      { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   -31.51) },
        { SIMDE_FLOAT64_C(   753.52),             SIMDE_MATH_NAN },
        {  INT64_C(                   0),  INT64_C(                   0) } },
      { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   954.21) },
        {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   954.21) },
        {  INT64_C(                   0),  INT64_C(                   0) } },
      { { SIMDE_FLOAT64_C(  -779.71), SIMDE_FLOAT64_C(  -746.16) },
        { SIMDE_FLOAT64_C(  -771.36), SIMDE_FLOAT64_C(   720.67) },
        {  INT64_C(                   0),  INT64_C(                   0) } },
      { { SIMDE_FLOAT64_C(    81.89), SIMDE_FLOAT64_C(   330.16) },
        { SIMDE_FLOAT64_C(   189.62), SIMDE_FLOAT64_C(   559.77) },
        {  INT64_C(                   0),  INT64_C(                   0) } },
      { { SIMDE_FLOAT64_C(  -942.57), SIMDE_FLOAT64_C(  -166.72) },
        { SIMDE_FLOAT64_C(   890.50), SIMDE_FLOAT64_C(   821.01) },
        {  INT64_C(                   0),  INT64_C(                   0) } },
      { { SIMDE_FLOAT64_C(  -775.44), SIMDE_FLOAT64_C(  -913.65) },
        { SIMDE_FLOAT64_C(    87.66), SIMDE_FLOAT64_C(  -473.75) },
        {  INT64_C(                   0),  INT64_C(                   0) } },
      { { SIMDE_FLOAT64_C(   781.63), SIMDE_FLOAT64_C(   668.06) },
        { SIMDE_FLOAT64_C(    62.56), SIMDE_FLOAT64_C(   400.66) },
        { -INT64_C(                   1), -INT64_C(                   1) } },
      { { SIMDE_FLOAT64_C(  -213.51), SIMDE_FLOAT64_C(   315.94) },
        { SIMDE_FLOAT64_C(  -554.51), SIMDE_FLOAT64_C(   596.58) },
        { -INT64_C(                   1),  INT64_C(                   0) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_f64x2_gt(a, b);
      simde_test_wasm_i64x2_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    simde_float64 inputs[8 * 2 * (sizeof(simde_v128_t) / sizeof(simde_float64))];
    simde_test_wasm_f64x2_random_full(8, 2, inputs, -SIMDE_FLOAT64_C(1000.0), SIMDE_FLOAT64_C(1000.0), HEDLEY_STATIC_CAST(SimdeTestVecFloatType, SIMDE_TEST_VEC_FLOAT_NAN | SIMDE_TEST_VEC_FLOAT_EQUAL));
    for (size_t i = 0 ; i < 8 ; i++) {
      simde_v128_t
        a = simde_test_wasm_f64x2_random_full_extract(2, inputs, i, 0),
        b = simde_test_wasm_f64x2_random_full_extract(2, inputs, i, 1),
        r;

      r = simde_wasm_f64x2_gt(a, b);

      simde_test_wasm_f64x2_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_f64x2_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_i64x2_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i8x16_gt)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i16x8_gt)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i32x4_gt)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i64x2_gt)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_u8x16_gt)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_u16x8_gt)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_u32x4_gt)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_f32x4_gt)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_f64x2_gt)
SIMDE_TEST_FUNC_LIST_END

#include "test-simd128-footer.h"
