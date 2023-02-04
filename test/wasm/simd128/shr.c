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

#define SIMDE_TEST_WASM_SIMD128_INSN shr
#include "../../../simde/wasm/simd128.h"
#include "test-simd128.h"

static int
test_simde_wasm_i8x16_shr(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int8_t a[sizeof(simde_v128_t) / sizeof(int8_t)];
      uint32_t count;
      int8_t r[sizeof(simde_v128_t) / sizeof(int8_t)];
    } test_vec[] = {
      { {  INT8_C(  29), -INT8_C(  34), -INT8_C(   5), -INT8_C(  35), -INT8_C(  99),  INT8_C( 126), -INT8_C(   5),  INT8_C( 106),
          -INT8_C(  37),  INT8_C(  83),  INT8_C(  21),  INT8_C(  84),  INT8_C(   8),  INT8_C( 102),  INT8_C(  95), -INT8_C(  44) },
        UINT32_C(           7),
        {  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
          -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1) } },
      { { -INT8_C(  96), -INT8_C( 116),  INT8_C( 122),  INT8_C( 116),  INT8_C(  12),  INT8_C(  73), -INT8_C(   7),  INT8_C(  49),
           INT8_C( 106), -INT8_C(  47), -INT8_C(  54),  INT8_C(  22),  INT8_C(  54), -INT8_C( 104),  INT8_C(  53),  INT8_C( 107) },
        UINT32_C(           5),
        { -INT8_C(   3), -INT8_C(   4),  INT8_C(   3),  INT8_C(   3),  INT8_C(   0),  INT8_C(   2), -INT8_C(   1),  INT8_C(   1),
           INT8_C(   3), -INT8_C(   2), -INT8_C(   2),  INT8_C(   0),  INT8_C(   1), -INT8_C(   4),  INT8_C(   1),  INT8_C(   3) } },
      { { -INT8_C(  65),  INT8_C(  15), -INT8_C(  74),  INT8_C( 101),  INT8_C(  56),  INT8_C(  31), -INT8_C(   7),  INT8_C( 108),
          -INT8_C(  68),  INT8_C(  54),  INT8_C(  70), -INT8_C(  68), -INT8_C(  69),  INT8_C(  78), -INT8_C(  54), -INT8_C(  20) },
        UINT32_C(           2),
        { -INT8_C(  17),  INT8_C(   3), -INT8_C(  19),  INT8_C(  25),  INT8_C(  14),  INT8_C(   7), -INT8_C(   2),  INT8_C(  27),
          -INT8_C(  17),  INT8_C(  13),  INT8_C(  17), -INT8_C(  17), -INT8_C(  18),  INT8_C(  19), -INT8_C(  14), -INT8_C(   5) } },
      { { -INT8_C(  43), -INT8_C(  21),  INT8_C(  46), -INT8_C( 127),  INT8_C(  30), -INT8_C(  43),  INT8_C(  30),  INT8_C(  11),
          -INT8_C(  12),  INT8_C(  11),  INT8_C(  74),  INT8_C(  31),  INT8_C(  12), -INT8_C(  71), -INT8_C(  55), -INT8_C(  13) },
        UINT32_C(           5),
        { -INT8_C(   2), -INT8_C(   1),  INT8_C(   1), -INT8_C(   4),  INT8_C(   0), -INT8_C(   2),  INT8_C(   0),  INT8_C(   0),
          -INT8_C(   1),  INT8_C(   0),  INT8_C(   2),  INT8_C(   0),  INT8_C(   0), -INT8_C(   3), -INT8_C(   2), -INT8_C(   1) } },
      { {  INT8_C( 104),      INT8_MIN, -INT8_C(  16), -INT8_C(  38),  INT8_C(   3), -INT8_C(  31),  INT8_C(   8),  INT8_C(  13),
          -INT8_C(  11),  INT8_C(  75),  INT8_C(  49),  INT8_C(  45), -INT8_C( 107), -INT8_C(  85), -INT8_C(  50),  INT8_C(  50) },
        UINT32_C(           1),
        {  INT8_C(  52), -INT8_C(  64), -INT8_C(   8), -INT8_C(  19),  INT8_C(   1), -INT8_C(  16),  INT8_C(   4),  INT8_C(   6),
          -INT8_C(   6),  INT8_C(  37),  INT8_C(  24),  INT8_C(  22), -INT8_C(  54), -INT8_C(  43), -INT8_C(  25),  INT8_C(  25) } },
      { {  INT8_C( 123), -INT8_C(  40), -INT8_C(  53),  INT8_C(  19),  INT8_C(  18),  INT8_C(  26),  INT8_C(   5),  INT8_C(  35),
          -INT8_C( 102),  INT8_C(  12), -INT8_C( 100), -INT8_C(   5), -INT8_C( 110), -INT8_C(   6),  INT8_C( 103), -INT8_C(  38) },
        UINT32_C(           1),
        {  INT8_C(  61), -INT8_C(  20), -INT8_C(  27),  INT8_C(   9),  INT8_C(   9),  INT8_C(  13),  INT8_C(   2),  INT8_C(  17),
          -INT8_C(  51),  INT8_C(   6), -INT8_C(  50), -INT8_C(   3), -INT8_C(  55), -INT8_C(   3),  INT8_C(  51), -INT8_C(  19) } },
      { {  INT8_C(  66),  INT8_C( 123), -INT8_C(  89),  INT8_C(  37), -INT8_C(  33), -INT8_C(  11), -INT8_C(  45),  INT8_C( 100),
           INT8_C(  24), -INT8_C(  11),  INT8_C(  72),  INT8_C(  73),  INT8_C( 109), -INT8_C(  12), -INT8_C(   7),  INT8_C(  59) },
        UINT32_C(           7),
        {  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
           INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0) } },
      { { -INT8_C(  41), -INT8_C(  47),  INT8_C( 102),  INT8_C( 114), -INT8_C(  67), -INT8_C(  99), -INT8_C( 118),      INT8_MAX,
           INT8_C(  88),  INT8_C(  76), -INT8_C(  43),  INT8_C(  32),  INT8_C(   9), -INT8_C(  36),  INT8_C(  63), -INT8_C(  83) },
        UINT32_C(           1),
        { -INT8_C(  21), -INT8_C(  24),  INT8_C(  51),  INT8_C(  57), -INT8_C(  34), -INT8_C(  50), -INT8_C(  59),  INT8_C(  63),
           INT8_C(  44),  INT8_C(  38), -INT8_C(  22),  INT8_C(  16),  INT8_C(   4), -INT8_C(  18),  INT8_C(  31), -INT8_C(  42) } },
      { { -INT8_C(  41), -INT8_C(  47),  INT8_C( 102),  INT8_C( 114), -INT8_C(  67), -INT8_C(  99), -INT8_C( 118),      INT8_MAX,
           INT8_C(  88),  INT8_C(  76), -INT8_C(  43),  INT8_C(  32),  INT8_C(   9), -INT8_C(  36),  INT8_C(  63), -INT8_C(  83) },
        UINT32_C(           8),
        { -INT8_C(  41), -INT8_C(  47),  INT8_C( 102),  INT8_C( 114), -INT8_C(  67), -INT8_C(  99), -INT8_C( 118),      INT8_MAX,
           INT8_C(  88),  INT8_C(  76), -INT8_C(  43),  INT8_C(  32),  INT8_C(   9), -INT8_C(  36),  INT8_C(  63), -INT8_C(  83) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t r = simde_wasm_i8x16_shr(a, test_vec[i].count);
      simde_test_wasm_i8x16_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      simde_v128_t a = simde_test_wasm_i8x16_random();
      uint32_t count = simde_test_codegen_random_u32() & 7;
      simde_v128_t r;

      r = simde_wasm_i8x16_shr(a, count);

      simde_test_wasm_i8x16_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_codegen_write_u32(3, count, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_i8x16_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_i16x8_shr(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int16_t a[sizeof(simde_v128_t) / sizeof(int16_t)];
      uint32_t count;
      int16_t r[sizeof(simde_v128_t) / sizeof(int16_t)];
    } test_vec[] = {
      { { -INT16_C(  6963), -INT16_C( 25844),  INT16_C( 30046),  INT16_C( 11028),  INT16_C(  9142), -INT16_C( 29228), -INT16_C( 30687),  INT16_C(   459) },
        UINT32_C(           0),
        { -INT16_C(  6963), -INT16_C( 25844),  INT16_C( 30046),  INT16_C( 11028),  INT16_C(  9142), -INT16_C( 29228), -INT16_C( 30687),  INT16_C(   459) } },
      { {  INT16_C( 30431),  INT16_C( 22986), -INT16_C( 14061), -INT16_C(  8281),  INT16_C( 19927), -INT16_C( 22236),  INT16_C( 15707), -INT16_C(  6979) },
        UINT32_C(          10),
        {  INT16_C(    29),  INT16_C(    22), -INT16_C(    14), -INT16_C(     9),  INT16_C(    19), -INT16_C(    22),  INT16_C(    15), -INT16_C(     7) } },
      { {  INT16_C( 29617), -INT16_C( 15225), -INT16_C(  2102), -INT16_C( 27651), -INT16_C( 12828), -INT16_C( 23441),  INT16_C( 16941), -INT16_C( 22127) },
        UINT32_C(          11),
        {  INT16_C(    14), -INT16_C(     8), -INT16_C(     2), -INT16_C(    14), -INT16_C(     7), -INT16_C(    12),  INT16_C(     8), -INT16_C(    11) } },
      { {  INT16_C( 25907), -INT16_C( 14290), -INT16_C(  3663), -INT16_C( 14444), -INT16_C( 26998), -INT16_C( 17249),  INT16_C( 22181), -INT16_C( 11113) },
        UINT32_C(          14),
        {  INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     2), -INT16_C(     2),  INT16_C(     1), -INT16_C(     1) } },
      { {  INT16_C(  3016), -INT16_C( 13733), -INT16_C( 30223), -INT16_C( 22894),  INT16_C( 22318),  INT16_C( 13471),  INT16_C(  2523),  INT16_C(  7921) },
        UINT32_C(           8),
        {  INT16_C(    11), -INT16_C(    54), -INT16_C(   119), -INT16_C(    90),  INT16_C(    87),  INT16_C(    52),  INT16_C(     9),  INT16_C(    30) } },
      { { -INT16_C( 17178), -INT16_C( 10829),  INT16_C( 21810),  INT16_C( 20559), -INT16_C( 18419), -INT16_C(  6812),  INT16_C(  8391), -INT16_C(  7679) },
        UINT32_C(           2),
        { -INT16_C(  4295), -INT16_C(  2708),  INT16_C(  5452),  INT16_C(  5139), -INT16_C(  4605), -INT16_C(  1703),  INT16_C(  2097), -INT16_C(  1920) } },
      { { -INT16_C( 21309),  INT16_C( 30322),  INT16_C( 11130),  INT16_C( 22147), -INT16_C( 25324),  INT16_C( 29729),  INT16_C(   937),  INT16_C(   662) },
        UINT32_C(           8),
        { -INT16_C(    84),  INT16_C(   118),  INT16_C(    43),  INT16_C(    86), -INT16_C(    99),  INT16_C(   116),  INT16_C(     3),  INT16_C(     2) } },
      { {  INT16_C(  7545),  INT16_C( 22543), -INT16_C( 20715), -INT16_C( 14130), -INT16_C( 20940), -INT16_C( 18619),  INT16_C(   420),  INT16_C( 23316) },
        UINT32_C(           7),
        {  INT16_C(    58),  INT16_C(   176), -INT16_C(   162), -INT16_C(   111), -INT16_C(   164), -INT16_C(   146),  INT16_C(     3),  INT16_C(   182) } },
      { {  INT16_C(  7545),  INT16_C( 22543), -INT16_C( 20715), -INT16_C( 14130), -INT16_C( 20940), -INT16_C( 18619),  INT16_C(   420),  INT16_C( 23316) },
        UINT32_C(           16),
        {  INT16_C(  7545),  INT16_C( 22543), -INT16_C( 20715), -INT16_C( 14130), -INT16_C( 20940), -INT16_C( 18619),  INT16_C(   420),  INT16_C( 23316) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t r = simde_wasm_i16x8_shr(a, test_vec[i].count);
      simde_test_wasm_i16x8_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      simde_v128_t a = simde_test_wasm_i16x8_random();
      uint32_t count = simde_test_codegen_random_u32() & 15;
      simde_v128_t r;

      r = simde_wasm_i16x8_shr(a, count);

      simde_test_wasm_i16x8_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_codegen_write_u32(3, count, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_i16x8_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_i32x4_shr(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int32_t a[sizeof(simde_v128_t) / sizeof(int32_t)];
      uint32_t count;
      int32_t r[sizeof(simde_v128_t) / sizeof(int32_t)];
    } test_vec[] = {
      { { -INT32_C(  1940238330),  INT32_C(  1047389908), -INT32_C(  1213826148),  INT32_C(  1472843720) },
        UINT32_C(          11),
        { -INT32_C(      947382),  INT32_C(      511420), -INT32_C(      592689),  INT32_C(      719161) } },
      { {  INT32_C(  1023674345),  INT32_C(   561633439), -INT32_C(   477711001),  INT32_C(  1459201617) },
        UINT32_C(          16),
        {  INT32_C(       15620),  INT32_C(        8569), -INT32_C(        7290),  INT32_C(       22265) } },
      { {  INT32_C(  1154349256),  INT32_C(    98198317),  INT32_C(   190731743),  INT32_C(   808386598) },
        UINT32_C(          27),
        {  INT32_C(           8),  INT32_C(           0),  INT32_C(           1),  INT32_C(           6) } },
      { {  INT32_C(   331294980), -INT32_C(   102117059), -INT32_C(  1482571902), -INT32_C(  1062810451) },
        UINT32_C(           6),
        {  INT32_C(     5176484), -INT32_C(     1595580), -INT32_C(    23165186), -INT32_C(    16606414) } },
      { {  INT32_C(  1854864081),  INT32_C(   128762980), -INT32_C(   723898408),  INT32_C(  1932206236) },
        UINT32_C(          24),
        {  INT32_C(         110),  INT32_C(           7), -INT32_C(          44),  INT32_C(         115) } },
      { {  INT32_C(  1803437469), -INT32_C(   229544053), -INT32_C(  1688448370), -INT32_C(  1350924728) },
        UINT32_C(           6),
        {  INT32_C(    28178710), -INT32_C(     3586626), -INT32_C(    26382006), -INT32_C(    21108199) } },
      { { -INT32_C(  1398366029),  INT32_C(   251559432),  INT32_C(  1129488410), -INT32_C(   857525386) },
        UINT32_C(          16),
        { -INT32_C(       21338),  INT32_C(        3838),  INT32_C(       17234), -INT32_C(       13085) } },
      { {  INT32_C(  1566637974), -INT32_C(   280703145), -INT32_C(  1998214584), -INT32_C(   145914645) },
        UINT32_C(          26),
        {  INT32_C(          23), -INT32_C(           5), -INT32_C(          30), -INT32_C(           3) } },
      { {  INT32_C(  1566637974), -INT32_C(   280703145), -INT32_C(  1998214584), -INT32_C(   145914645) },
        UINT32_C(          32),
        {  INT32_C(  1566637974), -INT32_C(   280703145), -INT32_C(  1998214584), -INT32_C(   145914645) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t r = simde_wasm_i32x4_shr(a, test_vec[i].count);
      simde_test_wasm_i32x4_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      simde_v128_t a = simde_test_wasm_i32x4_random();
      uint32_t count = simde_test_codegen_random_u32() & 31;
      simde_v128_t r;

      r = simde_wasm_i32x4_shr(a, count);

      simde_test_wasm_i32x4_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_codegen_write_u32(3, count, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_i32x4_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_i64x2_shr(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int64_t a[sizeof(simde_v128_t) / sizeof(int64_t)];
      uint32_t count;
      int64_t r[sizeof(simde_v128_t) / sizeof(int64_t)];
    } test_vec[] = {
      { { -INT64_C( 9156196170801492343), -INT64_C( 7047109005769514117) },
        UINT32_C(          62),
        { -INT64_C(                   2), -INT64_C(                   2) } },
      { { -INT64_C( 7274310232271294954), -INT64_C( 4614585031359736425) },
        UINT32_C(          18),
        { -INT64_C(      27749291352354), -INT64_C(      17603244901123) } },
      { {  INT64_C( 7792712180344461281), -INT64_C( 4454496693616041709) },
        UINT32_C(          31),
        {  INT64_C(          3628764385), -INT64_C(          2074286665) } },
      { { -INT64_C( 6272652142179116639), -INT64_C( 2546379397434493039) },
        UINT32_C(           7),
        { -INT64_C(   49005094860774349), -INT64_C(   19893589042456977) } },
      { { -INT64_C( 3875428605410068837), -INT64_C( 5740040367474874283) },
        UINT32_C(           8),
        { -INT64_C(   15138392989883082), -INT64_C(   22422032685448728) } },
      { { -INT64_C( 2558740817525283281),  INT64_C( 9003099967527583503) },
        UINT32_C(          51),
        { -INT64_C(                1137),  INT64_C(                3998) } },
      { { -INT64_C(  753631609393252319), -INT64_C( 7212524405143718280) },
        UINT32_C(          56),
        { -INT64_C(                  11), -INT64_C(                 101) } },
      { {  INT64_C( 1277309269344741295), -INT64_C( 7545149157369986290) },
        UINT32_C(          40),
        {  INT64_C(             1161706), -INT64_C(             6862274) } },
      { {  INT64_C( 1277309269344741295), -INT64_C( 7545149157369986290) },
        UINT32_C(          64),
        {  INT64_C( 1277309269344741295), -INT64_C( 7545149157369986290) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t r = simde_wasm_i64x2_shr(a, test_vec[i].count);
      simde_test_wasm_i64x2_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      simde_v128_t a = simde_test_wasm_i64x2_random();
      uint32_t count = simde_test_codegen_random_u32() & 63;
      simde_v128_t r;

      r = simde_wasm_i64x2_shr(a, count);

      simde_test_wasm_i64x2_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_codegen_write_u32(3, count, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_i64x2_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_u8x16_shr(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      uint8_t a[sizeof(simde_v128_t) / sizeof(uint8_t)];
      uint32_t count;
      uint8_t r[sizeof(simde_v128_t) / sizeof(uint8_t)];
    } test_vec[] = {
      { { UINT8_C(131), UINT8_C(117), UINT8_C(139), UINT8_C(157),    UINT8_MAX, UINT8_C(235), UINT8_C(147), UINT8_C(122),
          UINT8_C(162), UINT8_C( 74), UINT8_C( 56), UINT8_C(151), UINT8_C( 83), UINT8_C(222), UINT8_C(  3), UINT8_C(215) },
        UINT32_C(           5),
        { UINT8_C(  4), UINT8_C(  3), UINT8_C(  4), UINT8_C(  4), UINT8_C(  7), UINT8_C(  7), UINT8_C(  4), UINT8_C(  3),
          UINT8_C(  5), UINT8_C(  2), UINT8_C(  1), UINT8_C(  4), UINT8_C(  2), UINT8_C(  6), UINT8_C(  0), UINT8_C(  6) } },
      { { UINT8_C(216), UINT8_C(213), UINT8_C(205), UINT8_C(110), UINT8_C(229), UINT8_C(218), UINT8_C( 88), UINT8_C( 25),
          UINT8_C(179), UINT8_C(121), UINT8_C( 12), UINT8_C(  4), UINT8_C( 27), UINT8_C(101), UINT8_C(  6), UINT8_C(120) },
        UINT32_C(           3),
        { UINT8_C( 27), UINT8_C( 26), UINT8_C( 25), UINT8_C( 13), UINT8_C( 28), UINT8_C( 27), UINT8_C( 11), UINT8_C(  3),
          UINT8_C( 22), UINT8_C( 15), UINT8_C(  1), UINT8_C(  0), UINT8_C(  3), UINT8_C( 12), UINT8_C(  0), UINT8_C( 15) } },
      { { UINT8_C(144), UINT8_C( 72), UINT8_C(142), UINT8_C(104), UINT8_C(225), UINT8_C(249), UINT8_C(206), UINT8_C( 17),
          UINT8_C(198), UINT8_C( 83), UINT8_C(168), UINT8_C( 54), UINT8_C(127), UINT8_C(103), UINT8_C(  2), UINT8_C(224) },
        UINT32_C(           3),
        { UINT8_C( 18), UINT8_C(  9), UINT8_C( 17), UINT8_C( 13), UINT8_C( 28), UINT8_C( 31), UINT8_C( 25), UINT8_C(  2),
          UINT8_C( 24), UINT8_C( 10), UINT8_C( 21), UINT8_C(  6), UINT8_C( 15), UINT8_C( 12), UINT8_C(  0), UINT8_C( 28) } },
      { { UINT8_C(117), UINT8_C(225), UINT8_C(230), UINT8_C(140), UINT8_C(119), UINT8_C(165), UINT8_C(124), UINT8_C( 76),
          UINT8_C(239), UINT8_C(211), UINT8_C(219), UINT8_C(181), UINT8_C(181), UINT8_C(175), UINT8_C( 46), UINT8_C(140) },
        UINT32_C(           4),
        { UINT8_C(  7), UINT8_C( 14), UINT8_C( 14), UINT8_C(  8), UINT8_C(  7), UINT8_C( 10), UINT8_C(  7), UINT8_C(  4),
          UINT8_C( 14), UINT8_C( 13), UINT8_C( 13), UINT8_C( 11), UINT8_C( 11), UINT8_C( 10), UINT8_C(  2), UINT8_C(  8) } },
      { { UINT8_C( 84), UINT8_C(105), UINT8_C( 22), UINT8_C(248), UINT8_C(164), UINT8_C(202), UINT8_C( 22), UINT8_C(137),
          UINT8_C(136), UINT8_C(  4), UINT8_C(169), UINT8_C( 65), UINT8_C(206), UINT8_C(225), UINT8_C( 89), UINT8_C( 18) },
        UINT32_C(           3),
        { UINT8_C( 10), UINT8_C( 13), UINT8_C(  2), UINT8_C( 31), UINT8_C( 20), UINT8_C( 25), UINT8_C(  2), UINT8_C( 17),
          UINT8_C( 17), UINT8_C(  0), UINT8_C( 21), UINT8_C(  8), UINT8_C( 25), UINT8_C( 28), UINT8_C( 11), UINT8_C(  2) } },
      { { UINT8_C(204), UINT8_C( 98), UINT8_C(158), UINT8_C(117), UINT8_C(108), UINT8_C( 97), UINT8_C(175), UINT8_C(140),
          UINT8_C( 74), UINT8_C(237), UINT8_C( 89), UINT8_C( 17), UINT8_C(128), UINT8_C( 92), UINT8_C(199), UINT8_C(151) },
        UINT32_C(           0),
        { UINT8_C(204), UINT8_C( 98), UINT8_C(158), UINT8_C(117), UINT8_C(108), UINT8_C( 97), UINT8_C(175), UINT8_C(140),
          UINT8_C( 74), UINT8_C(237), UINT8_C( 89), UINT8_C( 17), UINT8_C(128), UINT8_C( 92), UINT8_C(199), UINT8_C(151) } },
      { { UINT8_C(174), UINT8_C( 26), UINT8_C(105), UINT8_C( 20), UINT8_C( 34), UINT8_C(218), UINT8_C(110), UINT8_C( 73),
          UINT8_C(178), UINT8_C(224), UINT8_C(102), UINT8_C(135), UINT8_C(196), UINT8_C(184), UINT8_C( 35), UINT8_C( 30) },
        UINT32_C(           4),
        { UINT8_C( 10), UINT8_C(  1), UINT8_C(  6), UINT8_C(  1), UINT8_C(  2), UINT8_C( 13), UINT8_C(  6), UINT8_C(  4),
          UINT8_C( 11), UINT8_C( 14), UINT8_C(  6), UINT8_C(  8), UINT8_C( 12), UINT8_C( 11), UINT8_C(  2), UINT8_C(  1) } },
      { { UINT8_C( 13), UINT8_C(212), UINT8_C( 19), UINT8_C(194), UINT8_C(153), UINT8_C( 33), UINT8_C(172), UINT8_C( 50),
          UINT8_C(163), UINT8_C( 20), UINT8_C( 26), UINT8_C(111), UINT8_C(108), UINT8_C(165), UINT8_C(247), UINT8_C( 55) },
        UINT32_C(           1),
        { UINT8_C(  6), UINT8_C(106), UINT8_C(  9), UINT8_C( 97), UINT8_C( 76), UINT8_C( 16), UINT8_C( 86), UINT8_C( 25),
          UINT8_C( 81), UINT8_C( 10), UINT8_C( 13), UINT8_C( 55), UINT8_C( 54), UINT8_C( 82), UINT8_C(123), UINT8_C( 27) } },
      { { UINT8_C( 13), UINT8_C(212), UINT8_C( 19), UINT8_C(194), UINT8_C(153), UINT8_C( 33), UINT8_C(172), UINT8_C( 50),
          UINT8_C(163), UINT8_C( 20), UINT8_C( 26), UINT8_C(111), UINT8_C(108), UINT8_C(165), UINT8_C(247), UINT8_C( 55) },
        UINT32_C(           8),
        { UINT8_C( 13), UINT8_C(212), UINT8_C( 19), UINT8_C(194), UINT8_C(153), UINT8_C( 33), UINT8_C(172), UINT8_C( 50),
          UINT8_C(163), UINT8_C( 20), UINT8_C( 26), UINT8_C(111), UINT8_C(108), UINT8_C(165), UINT8_C(247), UINT8_C( 55) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t r = simde_wasm_u8x16_shr(a, test_vec[i].count);
      simde_test_wasm_u8x16_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      simde_v128_t a = simde_test_wasm_u8x16_random();
      uint32_t count = simde_test_codegen_random_u32() & 7;
      simde_v128_t r;

      r = simde_wasm_u8x16_shr(a, count);

      simde_test_wasm_u8x16_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_codegen_write_u32(3, count, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_u8x16_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_u16x8_shr(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      uint16_t a[sizeof(simde_v128_t) / sizeof(uint16_t)];
      uint32_t count;
      uint16_t r[sizeof(simde_v128_t) / sizeof(uint16_t)];
    } test_vec[] = {
      { { UINT16_C(22852), UINT16_C(56322), UINT16_C(63429), UINT16_C(58796), UINT16_C(62558), UINT16_C(  188), UINT16_C(59500), UINT16_C( 7550) },
        UINT32_C(           8),
        { UINT16_C(   89), UINT16_C(  220), UINT16_C(  247), UINT16_C(  229), UINT16_C(  244), UINT16_C(    0), UINT16_C(  232), UINT16_C(   29) } },
      { { UINT16_C(59178), UINT16_C(44528), UINT16_C(14573), UINT16_C(30760), UINT16_C(21542), UINT16_C(55508), UINT16_C(61637), UINT16_C(34340) },
        UINT32_C(          15),
        { UINT16_C(    1), UINT16_C(    1), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    1), UINT16_C(    1), UINT16_C(    1) } },
      { { UINT16_C(28221), UINT16_C(23092), UINT16_C(60446), UINT16_C(13006), UINT16_C(44326), UINT16_C(23680), UINT16_C(37681), UINT16_C( 1675) },
        UINT32_C(          13),
        { UINT16_C(    3), UINT16_C(    2), UINT16_C(    7), UINT16_C(    1), UINT16_C(    5), UINT16_C(    2), UINT16_C(    4), UINT16_C(    0) } },
      { { UINT16_C(22477), UINT16_C( 1129), UINT16_C(28675), UINT16_C(38173), UINT16_C(21245), UINT16_C(61856), UINT16_C(62330), UINT16_C(39769) },
        UINT32_C(           0),
        { UINT16_C(22477), UINT16_C( 1129), UINT16_C(28675), UINT16_C(38173), UINT16_C(21245), UINT16_C(61856), UINT16_C(62330), UINT16_C(39769) } },
      { { UINT16_C(21952), UINT16_C(59981), UINT16_C(15286), UINT16_C( 6459), UINT16_C(10290), UINT16_C(14285), UINT16_C(18372), UINT16_C(10242) },
        UINT32_C(           2),
        { UINT16_C( 5488), UINT16_C(14995), UINT16_C( 3821), UINT16_C( 1614), UINT16_C( 2572), UINT16_C( 3571), UINT16_C( 4593), UINT16_C( 2560) } },
      { { UINT16_C( 2935), UINT16_C(17406), UINT16_C(58608), UINT16_C(55394), UINT16_C(60622), UINT16_C( 7058), UINT16_C(56534), UINT16_C(28351) },
        UINT32_C(          11),
        { UINT16_C(    1), UINT16_C(    8), UINT16_C(   28), UINT16_C(   27), UINT16_C(   29), UINT16_C(    3), UINT16_C(   27), UINT16_C(   13) } },
      { { UINT16_C(26476), UINT16_C(23004), UINT16_C( 4305), UINT16_C(15964), UINT16_C(62524), UINT16_C(17138), UINT16_C(38559), UINT16_C(11226) },
        UINT32_C(           4),
        { UINT16_C( 1654), UINT16_C( 1437), UINT16_C(  269), UINT16_C(  997), UINT16_C( 3907), UINT16_C( 1071), UINT16_C( 2409), UINT16_C(  701) } },
      { { UINT16_C(28498), UINT16_C(50767), UINT16_C( 6421), UINT16_C(49379), UINT16_C(53821), UINT16_C( 1724), UINT16_C(32088), UINT16_C(40508) },
        UINT32_C(          15),
        { UINT16_C(    0), UINT16_C(    1), UINT16_C(    0), UINT16_C(    1), UINT16_C(    1), UINT16_C(    0), UINT16_C(    0), UINT16_C(    1) } },
      { { UINT16_C(28498), UINT16_C(50767), UINT16_C( 6421), UINT16_C(49379), UINT16_C(53821), UINT16_C( 1724), UINT16_C(32088), UINT16_C(40508) },
        UINT32_C(          16),
        { UINT16_C(28498), UINT16_C(50767), UINT16_C( 6421), UINT16_C(49379), UINT16_C(53821), UINT16_C( 1724), UINT16_C(32088), UINT16_C(40508) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t r = simde_wasm_u16x8_shr(a, test_vec[i].count);
      simde_test_wasm_u16x8_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      simde_v128_t a = simde_test_wasm_u16x8_random();
      uint32_t count = simde_test_codegen_random_u32() & 15;
      simde_v128_t r;

      r = simde_wasm_u16x8_shr(a, count);

      simde_test_wasm_u16x8_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_codegen_write_u32(3, count, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_u16x8_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_u32x4_shr(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      uint32_t a[sizeof(simde_v128_t) / sizeof(uint32_t)];
      uint32_t count;
      uint32_t r[sizeof(simde_v128_t) / sizeof(uint32_t)];
    } test_vec[] = {
      { { UINT32_C(2702155907), UINT32_C(2644998205), UINT32_C(2596925724), UINT32_C(4242169881) },
        UINT32_C(           1),
        { UINT32_C(1351077953), UINT32_C(1322499102), UINT32_C(1298462862), UINT32_C(2121084940) } },
      { { UINT32_C(3316961153), UINT32_C( 303358547), UINT32_C(3795541832), UINT32_C(1673417450) },
        UINT32_C(          28),
        { UINT32_C(        12), UINT32_C(         1), UINT32_C(        14), UINT32_C(         6) } },
      { { UINT32_C(3784691390), UINT32_C(3762867621), UINT32_C(1573250240), UINT32_C(3810792300) },
        UINT32_C(          15),
        { UINT32_C(    115499), UINT32_C(    114833), UINT32_C(     48011), UINT32_C(    116296) } },
      { { UINT32_C(3383058725), UINT32_C(3063042370), UINT32_C( 523936127), UINT32_C(3927254519) },
        UINT32_C(           0),
        { UINT32_C(3383058725), UINT32_C(3063042370), UINT32_C( 523936127), UINT32_C(3927254519) } },
      { { UINT32_C(1035774265), UINT32_C(1059328563), UINT32_C(1867140051), UINT32_C(4067763037) },
        UINT32_C(          31),
        { UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         1) } },
      { { UINT32_C( 342132657), UINT32_C( 459473257), UINT32_C(3174471568), UINT32_C( 428728119) },
        UINT32_C(          16),
        { UINT32_C(      5220), UINT32_C(      7011), UINT32_C(     48438), UINT32_C(      6541) } },
      { { UINT32_C(  15328576), UINT32_C(2538798801), UINT32_C(1129822908), UINT32_C(3185487263) },
        UINT32_C(           5),
        { UINT32_C(    479018), UINT32_C(  79337462), UINT32_C(  35306965), UINT32_C(  99546476) } },
      { { UINT32_C(1806939018), UINT32_C(2793787884), UINT32_C(3442626836), UINT32_C(3455519635) },
        UINT32_C(          23),
        { UINT32_C(       215), UINT32_C(       333), UINT32_C(       410), UINT32_C(       411) } },
       { { UINT32_C(1806939018), UINT32_C(2793787884), UINT32_C(3442626836), UINT32_C(3455519635) },
        UINT32_C(          32),
        { UINT32_C(1806939018), UINT32_C(2793787884), UINT32_C(3442626836), UINT32_C(3455519635) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t r = simde_wasm_u32x4_shr(a, test_vec[i].count);
      simde_test_wasm_u32x4_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      simde_v128_t a = simde_test_wasm_u32x4_random();
      uint32_t count = simde_test_codegen_random_u32() & 31;
      simde_v128_t r;

      r = simde_wasm_u32x4_shr(a, count);

      simde_test_wasm_u32x4_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_codegen_write_u32(3, count, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_u32x4_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_u64x2_shr(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      uint64_t a[sizeof(simde_v128_t) / sizeof(uint64_t)];
      uint32_t count;
      uint64_t r[sizeof(simde_v128_t) / sizeof(uint64_t)];
    } test_vec[] = {
      { { UINT64_C( 2619749740852089630), UINT64_C( 5720480145779657735) },
        UINT32_C(          56),
        { UINT64_C(                  36), UINT64_C(                  79) } },
      { { UINT64_C(12317353138943901497), UINT64_C( 5266505343314411439) },
        UINT32_C(          27),
        { UINT64_C(         91771432302), UINT64_C(         39238522524) } },
      { { UINT64_C( 6138449044562838140), UINT64_C( 1883474370774266500) },
        UINT32_C(           5),
        { UINT64_C(  191826532642588691), UINT64_C(   58858574086695828) } },
      { { UINT64_C( 3499498395270404089), UINT64_C(10795856492300180543) },
        UINT32_C(          59),
        { UINT64_C(                   6), UINT64_C(                  18) } },
      { { UINT64_C(17576893026892467502), UINT64_C( 8868536150060591623) },
        UINT32_C(          47),
        { UINT64_C(              124891), UINT64_C(               63014) } },
      { { UINT64_C(15713109265867543213), UINT64_C( 7274027422302270714) },
        UINT32_C(          63),
        { UINT64_C(                   1), UINT64_C(                   0) } },
      { { UINT64_C(13837017272807882174), UINT64_C( 7551644180343518924) },
        UINT32_C(          26),
        { UINT64_C(        206187624824), UINT64_C(        112528267209) } },
      { { UINT64_C(15181337001227423157), UINT64_C(16894634851380593877) },
        UINT32_C(          37),
        { UINT64_C(           110458764), UINT64_C(           122924647) } },
      { { UINT64_C(15181337001227423157), UINT64_C(16894634851380593877) },
        UINT32_C(          64),
        { UINT64_C(15181337001227423157), UINT64_C(16894634851380593877) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t r = simde_wasm_u64x2_shr(a, test_vec[i].count);
      simde_test_wasm_u64x2_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      simde_v128_t a = simde_test_wasm_u64x2_random();
      uint32_t count = simde_test_codegen_random_u32() & 63;
      simde_v128_t r;

      r = simde_wasm_u64x2_shr(a, count);

      simde_test_wasm_u64x2_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_codegen_write_u32(3, count, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_u64x2_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i8x16_shr)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i16x8_shr)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i32x4_shr)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i64x2_shr)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_u8x16_shr)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_u16x8_shr)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_u32x4_shr)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_u64x2_shr)
SIMDE_TEST_FUNC_LIST_END

#include "test-simd128-footer.h"
