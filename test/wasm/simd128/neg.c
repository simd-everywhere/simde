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

#define SIMDE_TEST_WASM_SIMD128_INSN neg
#include "../../../simde/wasm/simd128.h"
#include "test-simd128.h"

static int
test_simde_wasm_i8x16_neg(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int8_t a[sizeof(simde_v128_t) / sizeof(int8_t)];
      int8_t r[sizeof(simde_v128_t) / sizeof(int8_t)];
    } test_vec[8] = {
      { {      INT8_MIN,      INT8_MAX,  INT8_C( 117), -INT8_C(  19), -INT8_C(  51), -INT8_C(  35), -INT8_C(   9),  INT8_C(  37),
           INT8_C( 126),  INT8_C(   8),  INT8_C(  36),  INT8_C(  78),  INT8_C( 111), -INT8_C(  59), -INT8_C(  30), -INT8_C(  56) },
        {      INT8_MIN, -INT8_C( 127), -INT8_C( 117),  INT8_C(  19),  INT8_C(  51),  INT8_C(  35),  INT8_C(   9), -INT8_C(  37),
          -INT8_C( 126), -INT8_C(   8), -INT8_C(  36), -INT8_C(  78), -INT8_C( 111),  INT8_C(  59),  INT8_C(  30),  INT8_C(  56) } },
      { { -INT8_C(  52),  INT8_C(  54), -INT8_C( 119),  INT8_C( 114),  INT8_C( 112), -INT8_C(  84),  INT8_C( 112), -INT8_C(  17),
          -INT8_C(  65),  INT8_C(  89), -INT8_C(  66), -INT8_C( 109), -INT8_C(   2), -INT8_C(  17),  INT8_C(  59),  INT8_C(  30) },
        {  INT8_C(  52), -INT8_C(  54),  INT8_C( 119), -INT8_C( 114), -INT8_C( 112),  INT8_C(  84), -INT8_C( 112),  INT8_C(  17),
           INT8_C(  65), -INT8_C(  89),  INT8_C(  66),  INT8_C( 109),  INT8_C(   2),  INT8_C(  17), -INT8_C(  59), -INT8_C(  30) } },
      { {  INT8_C(  77), -INT8_C( 116), -INT8_C(  84), -INT8_C(  25),  INT8_C( 104),  INT8_C(   0), -INT8_C(  93), -INT8_C(  86),
          -INT8_C(  47),  INT8_C(  55), -INT8_C( 118), -INT8_C(  10),  INT8_C(  80),  INT8_C(  94), -INT8_C(  61), -INT8_C(  44) },
        { -INT8_C(  77),  INT8_C( 116),  INT8_C(  84),  INT8_C(  25), -INT8_C( 104),  INT8_C(   0),  INT8_C(  93),  INT8_C(  86),
           INT8_C(  47), -INT8_C(  55),  INT8_C( 118),  INT8_C(  10), -INT8_C(  80), -INT8_C(  94),  INT8_C(  61),  INT8_C(  44) } },
      { {  INT8_C( 111),  INT8_C(   0),  INT8_C(  14), -INT8_C(  40), -INT8_C(  72), -INT8_C(  63), -INT8_C(  79), -INT8_C(  28),
          -INT8_C(  78), -INT8_C( 116),  INT8_C(  61), -INT8_C(  27),  INT8_C(  71), -INT8_C( 100), -INT8_C(  52), -INT8_C(  32) },
        { -INT8_C( 111),  INT8_C(   0), -INT8_C(  14),  INT8_C(  40),  INT8_C(  72),  INT8_C(  63),  INT8_C(  79),  INT8_C(  28),
           INT8_C(  78),  INT8_C( 116), -INT8_C(  61),  INT8_C(  27), -INT8_C(  71),  INT8_C( 100),  INT8_C(  52),  INT8_C(  32) } },
      { {  INT8_C(  94), -INT8_C(  73),  INT8_C( 108),  INT8_C( 122),  INT8_C(  30),  INT8_C( 117), -INT8_C(  84), -INT8_C(  65),
           INT8_C(  20), -INT8_C( 117),  INT8_C(  20),  INT8_C(   6),  INT8_C(  75), -INT8_C(  26),  INT8_C(  68),      INT8_MIN },
        { -INT8_C(  94),  INT8_C(  73), -INT8_C( 108), -INT8_C( 122), -INT8_C(  30), -INT8_C( 117),  INT8_C(  84),  INT8_C(  65),
          -INT8_C(  20),  INT8_C( 117), -INT8_C(  20), -INT8_C(   6), -INT8_C(  75),  INT8_C(  26), -INT8_C(  68),      INT8_MIN } },
      { {  INT8_C( 116),  INT8_C( 106), -INT8_C(  32), -INT8_C(  33), -INT8_C(  13), -INT8_C( 124),      INT8_MIN, -INT8_C(  61),
           INT8_C(  25),  INT8_C( 107),  INT8_C(  72), -INT8_C(  65),  INT8_C(  29),  INT8_C(  73), -INT8_C(  76),  INT8_C(  16) },
        { -INT8_C( 116), -INT8_C( 106),  INT8_C(  32),  INT8_C(  33),  INT8_C(  13),  INT8_C( 124),      INT8_MIN,  INT8_C(  61),
          -INT8_C(  25), -INT8_C( 107), -INT8_C(  72),  INT8_C(  65), -INT8_C(  29), -INT8_C(  73),  INT8_C(  76), -INT8_C(  16) } },
      { { -INT8_C(  25),  INT8_C(  36), -INT8_C(  30),  INT8_C(  50), -INT8_C(  46),  INT8_C( 126), -INT8_C(  24),  INT8_C(  33),
          -INT8_C(  60), -INT8_C( 109),  INT8_C( 122), -INT8_C( 110),  INT8_C(  77),  INT8_C( 120),  INT8_C(  13),  INT8_C(  31) },
        {  INT8_C(  25), -INT8_C(  36),  INT8_C(  30), -INT8_C(  50),  INT8_C(  46), -INT8_C( 126),  INT8_C(  24), -INT8_C(  33),
           INT8_C(  60),  INT8_C( 109), -INT8_C( 122),  INT8_C( 110), -INT8_C(  77), -INT8_C( 120), -INT8_C(  13), -INT8_C(  31) } },
      { { -INT8_C(  22),  INT8_C(  51), -INT8_C(  17), -INT8_C( 106), -INT8_C(  77), -INT8_C(  19), -INT8_C(  13), -INT8_C(  17),
          -INT8_C(  76), -INT8_C(  93), -INT8_C( 127), -INT8_C(  42), -INT8_C(  57), -INT8_C(  15), -INT8_C(  61),  INT8_C(  47) },
        {  INT8_C(  22), -INT8_C(  51),  INT8_C(  17),  INT8_C( 106),  INT8_C(  77),  INT8_C(  19),  INT8_C(  13),  INT8_C(  17),
           INT8_C(  76),  INT8_C(  93),      INT8_MAX,  INT8_C(  42),  INT8_C(  57),  INT8_C(  15),  INT8_C(  61), -INT8_C(  47) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t r = simde_wasm_i8x16_neg(a);
      simde_test_wasm_i32x4_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      int8_t a_[sizeof(simde_v128_t) / sizeof(int8_t)];
      simde_v128_t a, r;

      simde_test_codegen_random_memory(sizeof(a_), HEDLEY_REINTERPRET_CAST(uint8_t*, a_));
      if (i == 0) {
        a_[0] = INT8_MIN;
        a_[1] = INT8_MAX;
      }

      a = simde_wasm_v128_load(a_);
      r = simde_wasm_i8x16_neg(a);

      simde_test_wasm_i8x16_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_i8x16_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_i16x8_neg(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int16_t a[sizeof(simde_v128_t) / sizeof(int16_t)];
      int16_t r[sizeof(simde_v128_t) / sizeof(int16_t)];
    } test_vec[8] = {
      { {       INT16_MIN,       INT16_MAX,  INT16_C(  9940), -INT16_C( 10858), -INT16_C(  5742),  INT16_C( 15660), -INT16_C(  6911), -INT16_C( 19019) },
        {       INT16_MIN, -INT16_C( 32767), -INT16_C(  9940),  INT16_C( 10858),  INT16_C(  5742), -INT16_C( 15660),  INT16_C(  6911),  INT16_C( 19019) } },
      { {  INT16_C( 16063),  INT16_C(  4383), -INT16_C( 22007), -INT16_C( 17973), -INT16_C( 19004), -INT16_C( 19083),  INT16_C( 24906), -INT16_C( 14491) },
        { -INT16_C( 16063), -INT16_C(  4383),  INT16_C( 22007),  INT16_C( 17973),  INT16_C( 19004),  INT16_C( 19083), -INT16_C( 24906),  INT16_C( 14491) } },
      { {  INT16_C( 22314),  INT16_C(  3325),  INT16_C( 32743), -INT16_C( 10048),  INT16_C(  7642),  INT16_C(  7835),  INT16_C( 19376),  INT16_C(  2046) },
        { -INT16_C( 22314), -INT16_C(  3325), -INT16_C( 32743),  INT16_C( 10048), -INT16_C(  7642), -INT16_C(  7835), -INT16_C( 19376), -INT16_C(  2046) } },
      { { -INT16_C(  9450), -INT16_C( 21128),  INT16_C(  7244), -INT16_C(  9839), -INT16_C( 25538),  INT16_C( 22958), -INT16_C( 28401),  INT16_C( 16292) },
        {  INT16_C(  9450),  INT16_C( 21128), -INT16_C(  7244),  INT16_C(  9839),  INT16_C( 25538), -INT16_C( 22958),  INT16_C( 28401), -INT16_C( 16292) } },
      { {  INT16_C( 12064),  INT16_C(  6431),  INT16_C( 21960),  INT16_C( 22294),  INT16_C(  8090),  INT16_C(  9227),  INT16_C( 13229),  INT16_C( 13208) },
        { -INT16_C( 12064), -INT16_C(  6431), -INT16_C( 21960), -INT16_C( 22294), -INT16_C(  8090), -INT16_C(  9227), -INT16_C( 13229), -INT16_C( 13208) } },
      { { -INT16_C( 28643), -INT16_C( 11817), -INT16_C( 12703),  INT16_C( 24119), -INT16_C(  1914),  INT16_C( 22593), -INT16_C( 32502),  INT16_C( 11941) },
        {  INT16_C( 28643),  INT16_C( 11817),  INT16_C( 12703), -INT16_C( 24119),  INT16_C(  1914), -INT16_C( 22593),  INT16_C( 32502), -INT16_C( 11941) } },
      { {  INT16_C(   433), -INT16_C( 23473),  INT16_C( 29239),  INT16_C( 24403),  INT16_C( 12010), -INT16_C(  2841),  INT16_C( 10809), -INT16_C( 17058) },
        { -INT16_C(   433),  INT16_C( 23473), -INT16_C( 29239), -INT16_C( 24403), -INT16_C( 12010),  INT16_C(  2841), -INT16_C( 10809),  INT16_C( 17058) } },
      { {  INT16_C( 26725),  INT16_C( 13593),  INT16_C( 29827),  INT16_C(  7477), -INT16_C( 16474), -INT16_C( 31523), -INT16_C( 28315),  INT16_C( 11177) },
        { -INT16_C( 26725), -INT16_C( 13593), -INT16_C( 29827), -INT16_C(  7477),  INT16_C( 16474),  INT16_C( 31523),  INT16_C( 28315), -INT16_C( 11177) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t r = simde_wasm_i16x8_neg(a);
      simde_test_wasm_i32x4_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      int16_t a_[sizeof(simde_v128_t) / sizeof(int16_t)];
      simde_v128_t a, r;

      simde_test_codegen_random_memory(sizeof(a_), HEDLEY_REINTERPRET_CAST(uint8_t*, a_));
      if (i == 0) {
        a_[0] = INT16_MIN;
        a_[1] = INT16_MAX;
      }

      a = simde_wasm_v128_load(a_);
      r = simde_wasm_i16x8_neg(a);

      simde_test_wasm_i16x8_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_i16x8_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_i32x4_neg(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int32_t a[sizeof(simde_v128_t) / sizeof(int32_t)];
      int32_t r[sizeof(simde_v128_t) / sizeof(int32_t)];
    } test_vec[8] = {
      { {            INT32_MIN,            INT32_MAX,  INT32_C(  1434796018),  INT32_C(   655744747) },
        {            INT32_MIN, -INT32_C(  2147483647), -INT32_C(  1434796018), -INT32_C(   655744747) } },
      { { -INT32_C(  1597195333), -INT32_C(  1389796217),  INT32_C(   223961346),  INT32_C(   663249310) },
        {  INT32_C(  1597195333),  INT32_C(  1389796217), -INT32_C(   223961346), -INT32_C(   663249310) } },
      { { -INT32_C(   153889653),  INT32_C(  1262642280),  INT32_C(   176154465),  INT32_C(    44807575) },
        {  INT32_C(   153889653), -INT32_C(  1262642280), -INT32_C(   176154465), -INT32_C(    44807575) } },
      { {  INT32_C(   794851961), -INT32_C(   772304475),  INT32_C(   616854928),  INT32_C(   968173367) },
        { -INT32_C(   794851961),  INT32_C(   772304475), -INT32_C(   616854928), -INT32_C(   968173367) } },
      { { -INT32_C(  1494177278), -INT32_C(   152911892),  INT32_C(   981453666),  INT32_C(  2146888885) },
        {  INT32_C(  1494177278),  INT32_C(   152911892), -INT32_C(   981453666), -INT32_C(  2146888885) } },
      { {  INT32_C(   366213988),  INT32_C(  1885669056),  INT32_C(   502523793), -INT32_C(   222654759) },
        { -INT32_C(   366213988), -INT32_C(  1885669056), -INT32_C(   502523793),  INT32_C(   222654759) } },
      { {  INT32_C(   789363487), -INT32_C(  1719508463),  INT32_C(  1351321881), -INT32_C(  2014039735) },
        { -INT32_C(   789363487),  INT32_C(  1719508463), -INT32_C(  1351321881),  INT32_C(  2014039735) } },
      { { -INT32_C(   522239233),  INT32_C(   138339371),  INT32_C(   378839239),  INT32_C(   892866299) },
        {  INT32_C(   522239233), -INT32_C(   138339371), -INT32_C(   378839239), -INT32_C(   892866299) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t r = simde_wasm_i32x4_neg(a);
      simde_test_wasm_i32x4_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      int32_t a_[sizeof(simde_v128_t) / sizeof(int32_t)];
      simde_v128_t a, r;

      simde_test_codegen_random_memory(sizeof(a_), HEDLEY_REINTERPRET_CAST(uint8_t*, a_));
      if (i == 0) {
        a_[0] = INT32_MIN;
        a_[1] = INT32_MAX;
      }

      a = simde_wasm_v128_load(a_);
      r = simde_wasm_i32x4_neg(a);

      simde_test_wasm_i32x4_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_i32x4_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_i64x2_neg(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int64_t a[sizeof(simde_v128_t) / sizeof(int64_t)];
      int64_t r[sizeof(simde_v128_t) / sizeof(int64_t)];
    } test_vec[8] = {
      { {                     INT64_MIN,                     INT64_MAX },
        {                     INT64_MIN, -INT64_C( 9223372036854775807) } },
      { { -INT64_C( 7066472238942270110), -INT64_C( 8906491638592458199) },
        {  INT64_C( 7066472238942270110),  INT64_C( 8906491638592458199) } },
      { {  INT64_C(  667612053118532615),  INT64_C( 6033684943821200704) },
        { -INT64_C(  667612053118532615), -INT64_C( 6033684943821200704) } },
      { {  INT64_C( 3720563284232364179), -INT64_C( 2878677500498804448) },
        { -INT64_C( 3720563284232364179),  INT64_C( 2878677500498804448) } },
      { { -INT64_C( 7609619990515637037),  INT64_C( 1907963809931249902) },
        {  INT64_C( 7609619990515637037), -INT64_C( 1907963809931249902) } },
      { { -INT64_C( 5051103143195619749), -INT64_C( 1221494921759788232) },
        {  INT64_C( 5051103143195619749),  INT64_C( 1221494921759788232) } },
      { { -INT64_C( 9022709836808859402),  INT64_C( 1933373486800932408) },
        {  INT64_C( 9022709836808859402), -INT64_C( 1933373486800932408) } },
      { { -INT64_C( 9095465444696275297),  INT64_C( 2546366233258398811) },
        {  INT64_C( 9095465444696275297), -INT64_C( 2546366233258398811) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t r = simde_wasm_i64x2_neg(a);
      simde_test_wasm_i32x4_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      int64_t a_[sizeof(simde_v128_t) / sizeof(int64_t)];
      simde_v128_t a, r;

      simde_test_codegen_random_memory(sizeof(a_), HEDLEY_REINTERPRET_CAST(uint8_t*, a_));
      if (i == 0) {
        a_[0] = INT64_MIN;
        a_[1] = INT64_MAX;
      }

      a = simde_wasm_v128_load(a_);
      r = simde_wasm_i64x2_neg(a);

      simde_test_wasm_i64x2_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_i64x2_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_f32x4_neg(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      simde_float32 a[sizeof(simde_v128_t) / sizeof(simde_float32)];
      simde_float32 r[sizeof(simde_v128_t) / sizeof(simde_float32)];
    } test_vec[8] = {
      { { SIMDE_FLOAT32_C(  -830.22), SIMDE_FLOAT32_C(   910.65), SIMDE_FLOAT32_C(  -578.70), SIMDE_FLOAT32_C(    20.57) },
        { SIMDE_FLOAT32_C(   830.22), SIMDE_FLOAT32_C(  -910.65), SIMDE_FLOAT32_C(   578.70), SIMDE_FLOAT32_C(   -20.57) } },
      { { SIMDE_FLOAT32_C(   397.22), SIMDE_FLOAT32_C(  -225.00), SIMDE_FLOAT32_C(  -374.17), SIMDE_FLOAT32_C(  -715.55) },
        { SIMDE_FLOAT32_C(  -397.22), SIMDE_FLOAT32_C(   225.00), SIMDE_FLOAT32_C(   374.17), SIMDE_FLOAT32_C(   715.55) } },
      { { SIMDE_FLOAT32_C(   529.04), SIMDE_FLOAT32_C(  -202.04), SIMDE_FLOAT32_C(  -690.70), SIMDE_FLOAT32_C(   632.23) },
        { SIMDE_FLOAT32_C(  -529.04), SIMDE_FLOAT32_C(   202.04), SIMDE_FLOAT32_C(   690.70), SIMDE_FLOAT32_C(  -632.23) } },
      { { SIMDE_FLOAT32_C(   697.62), SIMDE_FLOAT32_C(   284.19), SIMDE_FLOAT32_C(  -506.98), SIMDE_FLOAT32_C(    11.41) },
        { SIMDE_FLOAT32_C(  -697.62), SIMDE_FLOAT32_C(  -284.19), SIMDE_FLOAT32_C(   506.98), SIMDE_FLOAT32_C(   -11.41) } },
      { { SIMDE_FLOAT32_C(   683.94), SIMDE_FLOAT32_C(   226.87), SIMDE_FLOAT32_C(  -776.20), SIMDE_FLOAT32_C(   771.77) },
        { SIMDE_FLOAT32_C(  -683.94), SIMDE_FLOAT32_C(  -226.87), SIMDE_FLOAT32_C(   776.20), SIMDE_FLOAT32_C(  -771.77) } },
      { { SIMDE_FLOAT32_C(   -45.49), SIMDE_FLOAT32_C(    87.23), SIMDE_FLOAT32_C(  -229.38), SIMDE_FLOAT32_C(  -239.89) },
        { SIMDE_FLOAT32_C(    45.49), SIMDE_FLOAT32_C(   -87.23), SIMDE_FLOAT32_C(   229.38), SIMDE_FLOAT32_C(   239.89) } },
      { { SIMDE_FLOAT32_C(  -991.00), SIMDE_FLOAT32_C(  -725.90), SIMDE_FLOAT32_C(   911.63), SIMDE_FLOAT32_C(   730.82) },
        { SIMDE_FLOAT32_C(   991.00), SIMDE_FLOAT32_C(   725.90), SIMDE_FLOAT32_C(  -911.63), SIMDE_FLOAT32_C(  -730.82) } },
      { { SIMDE_FLOAT32_C(   -83.27), SIMDE_FLOAT32_C(  -570.74), SIMDE_FLOAT32_C(  -447.68), SIMDE_FLOAT32_C(    26.74) },
        { SIMDE_FLOAT32_C(    83.27), SIMDE_FLOAT32_C(   570.74), SIMDE_FLOAT32_C(   447.68), SIMDE_FLOAT32_C(   -26.74) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t r = simde_wasm_f32x4_neg(a);
      simde_test_wasm_f32x4_assert_equal(r, simde_wasm_v128_load(test_vec[i].r), INT_MAX);
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      simde_v128_t a = simde_test_wasm_f32x4_random(-SIMDE_FLOAT32_C(1000.0), SIMDE_FLOAT32_C(1000.0));
      simde_v128_t r;

      r = simde_wasm_f32x4_neg(a);

      simde_test_wasm_f32x4_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_f32x4_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_f64x2_neg(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      simde_float64 a[sizeof(simde_v128_t) / sizeof(simde_float64)];
      simde_float64 r[sizeof(simde_v128_t) / sizeof(simde_float64)];
    } test_vec[8] = {
      { { SIMDE_FLOAT64_C(   861.81), SIMDE_FLOAT64_C(  -575.46) },
        { SIMDE_FLOAT64_C(  -861.81), SIMDE_FLOAT64_C(   575.46) } },
      { { SIMDE_FLOAT64_C(   300.15), SIMDE_FLOAT64_C(  -152.70) },
        { SIMDE_FLOAT64_C(  -300.15), SIMDE_FLOAT64_C(   152.70) } },
      { { SIMDE_FLOAT64_C(  -645.73), SIMDE_FLOAT64_C(   571.64) },
        { SIMDE_FLOAT64_C(   645.73), SIMDE_FLOAT64_C(  -571.64) } },
      { { SIMDE_FLOAT64_C(   219.59), SIMDE_FLOAT64_C(  -436.61) },
        { SIMDE_FLOAT64_C(  -219.59), SIMDE_FLOAT64_C(   436.61) } },
      { { SIMDE_FLOAT64_C(  -650.15), SIMDE_FLOAT64_C(  -314.72) },
        { SIMDE_FLOAT64_C(   650.15), SIMDE_FLOAT64_C(   314.72) } },
      { { SIMDE_FLOAT64_C(    98.04), SIMDE_FLOAT64_C(   706.90) },
        { SIMDE_FLOAT64_C(   -98.04), SIMDE_FLOAT64_C(  -706.90) } },
      { { SIMDE_FLOAT64_C(   -37.99), SIMDE_FLOAT64_C(    65.04) },
        { SIMDE_FLOAT64_C(    37.99), SIMDE_FLOAT64_C(   -65.04) } },
      { { SIMDE_FLOAT64_C(  -988.70), SIMDE_FLOAT64_C(   808.21) },
        { SIMDE_FLOAT64_C(   988.70), SIMDE_FLOAT64_C(  -808.21) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t r = simde_wasm_f64x2_neg(a);
      simde_test_wasm_f64x2_assert_equal(r, simde_wasm_v128_load(test_vec[i].r), INT_MAX);
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      simde_v128_t a = simde_test_wasm_f64x2_random(-SIMDE_FLOAT64_C(1000.0), SIMDE_FLOAT64_C(1000.0));
      simde_v128_t r;

      r = simde_wasm_f64x2_neg(a);

      simde_test_wasm_f64x2_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_f64x2_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i8x16_neg)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i16x8_neg)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i32x4_neg)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i64x2_neg)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_f32x4_neg)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_f64x2_neg)
SIMDE_TEST_FUNC_LIST_END

#include "test-simd128-footer.h"
