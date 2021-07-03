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

#define SIMDE_TEST_WASM_SIMD128_INSN lt
#include "../../../simde/wasm/simd128.h"
#include "test-simd128.h"

static int
test_simde_wasm_i8x16_lt(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int8_t a[sizeof(simde_v128_t) / sizeof(int8_t)];
      int8_t b[sizeof(simde_v128_t) / sizeof(int8_t)];
      int8_t r[sizeof(simde_v128_t) / sizeof(int8_t)];
    } test_vec[8] = {
      { {  INT8_C(  38),  INT8_C(  86),  INT8_C(  94), -INT8_C(   2),  INT8_C(  24), -INT8_C( 101), -INT8_C(  83),  INT8_C(  97),
           INT8_C(  78),  INT8_C(  89),  INT8_C(   5),  INT8_C(   5), -INT8_C( 119),  INT8_C( 104), -INT8_C(  99),  INT8_C( 104) },
        {  INT8_C(  38), -INT8_C(   2),  INT8_C(  97), -INT8_C(   2), -INT8_C(  94), -INT8_C( 101),  INT8_C(  86), -INT8_C( 121),
           INT8_C(   3),  INT8_C(  56), -INT8_C(  26), -INT8_C(  54), -INT8_C(  51),  INT8_C(  56), -INT8_C(  57),  INT8_C(  68) },
        {  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
           INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0) } },
      { {  INT8_C( 102), -INT8_C(  25), -INT8_C(  52),  INT8_C(  71),  INT8_C(  73),  INT8_C(   3),  INT8_C(   0), -INT8_C(  10),
          -INT8_C(  86),  INT8_C(  94), -INT8_C(  17), -INT8_C(  50), -INT8_C(  69),  INT8_C(  16), -INT8_C(  94),  INT8_C( 111) },
        {  INT8_C( 107),  INT8_C( 117), -INT8_C(  52), -INT8_C(   6), -INT8_C(  15),  INT8_C(   3), -INT8_C(  14), -INT8_C(  41),
          -INT8_C(  86),  INT8_C( 100), -INT8_C(  17),  INT8_C( 122), -INT8_C(  69), -INT8_C(  52), -INT8_C(  65),  INT8_C(  23) },
        { -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
           INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0) } },
      { {  INT8_C(  17),  INT8_C(  39),  INT8_C(  78), -INT8_C(  57), -INT8_C( 111),  INT8_C(  92),  INT8_C(  94), -INT8_C( 120),
          -INT8_C(  34), -INT8_C(  39), -INT8_C( 108), -INT8_C(  91), -INT8_C(  72), -INT8_C( 120), -INT8_C(  66),  INT8_C(  34) },
        {  INT8_C(  94), -INT8_C(  29),  INT8_C(  78), -INT8_C(  57), -INT8_C( 111), -INT8_C(  58), -INT8_C(  84), -INT8_C( 103),
          -INT8_C(  34), -INT8_C( 111),  INT8_C(  75), -INT8_C( 101), -INT8_C(  92), -INT8_C( 120), -INT8_C(  13), -INT8_C(  87) },
        { -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
           INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0) } },
      { { -INT8_C(  38),  INT8_C(  72), -INT8_C(  72),  INT8_C( 123),  INT8_C(  57),  INT8_C(  26), -INT8_C( 115),  INT8_C(  46),
          -INT8_C(  74),  INT8_C(  89), -INT8_C( 113),  INT8_C(  54),  INT8_C(  40),  INT8_C(  60), -INT8_C( 105), -INT8_C(  22) },
        { -INT8_C(  38), -INT8_C(  79), -INT8_C(  72),  INT8_C( 123), -INT8_C(  84), -INT8_C(  75), -INT8_C(  60),  INT8_C(  22),
           INT8_C(  86), -INT8_C(  18),  INT8_C( 113),  INT8_C(  15),  INT8_C(  92), -INT8_C(  95), -INT8_C(  84),  INT8_C(  52) },
        {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
          -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1) } },
      { { -INT8_C(  10), -INT8_C(  17), -INT8_C( 122),  INT8_C(  11), -INT8_C(  14), -INT8_C(  93), -INT8_C( 103), -INT8_C( 124),
           INT8_C(   0), -INT8_C(   5),  INT8_C(  74), -INT8_C(  97), -INT8_C(  86), -INT8_C( 101), -INT8_C(  29), -INT8_C(  34) },
        { -INT8_C(  10), -INT8_C(  54), -INT8_C( 122),  INT8_C(  28),  INT8_C(  38), -INT8_C(  93), -INT8_C(  52),  INT8_C(  47),
           INT8_C(  44), -INT8_C(  87), -INT8_C( 117), -INT8_C(  97), -INT8_C(  86), -INT8_C(  48), -INT8_C(  29),  INT8_C( 124) },
        {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
          -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1) } },
      { { -INT8_C(  67),  INT8_C(  87), -INT8_C( 112),  INT8_C(  62),  INT8_C(  61),  INT8_C(  40),  INT8_C(  18),  INT8_C(  76),
          -INT8_C(  31), -INT8_C(   5),  INT8_C(  43),      INT8_MAX, -INT8_C(  76), -INT8_C(  18),  INT8_C( 106), -INT8_C(   4) },
        {  INT8_C(  55),  INT8_C(  87), -INT8_C(  39),  INT8_C(  62), -INT8_C( 122),  INT8_C(  40),  INT8_C(   5),  INT8_C( 101),
           INT8_C(  89), -INT8_C(  68), -INT8_C(  89),  INT8_C(  61),  INT8_C(  42), -INT8_C(  19), -INT8_C(  36), -INT8_C(  78) },
        { -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
          -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0) } },
      { { -INT8_C(  73), -INT8_C(  41), -INT8_C(  33), -INT8_C(  67),  INT8_C(  20),  INT8_C(  55),  INT8_C(  71), -INT8_C(  76),
           INT8_C(  75),  INT8_C(  93), -INT8_C(  97),  INT8_C(  11), -INT8_C( 127), -INT8_C(  96), -INT8_C(  57), -INT8_C(  42) },
        {  INT8_C(  86), -INT8_C( 106), -INT8_C(  33),  INT8_C(  30),  INT8_C(  72),  INT8_C(  55),  INT8_C(  71), -INT8_C(   6),
           INT8_C(  48),  INT8_C(  65),  INT8_C(  92), -INT8_C(  86),  INT8_C(  61),  INT8_C(  82),  INT8_C( 117), -INT8_C(  42) },
        { -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
           INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0) } },
      { { -INT8_C(  98),  INT8_C(  61),  INT8_C(  31), -INT8_C(  99),  INT8_C( 116), -INT8_C( 119), -INT8_C(   5), -INT8_C(  62),
           INT8_C(  45),  INT8_C(  51),  INT8_C( 120), -INT8_C(  93), -INT8_C( 113), -INT8_C( 123),  INT8_C(  96),  INT8_C(  25) },
        { -INT8_C(  98),  INT8_C(  96),  INT8_C(  31), -INT8_C(  16),  INT8_C( 120),      INT8_MIN, -INT8_C(  16), -INT8_C(  59),
           INT8_C(  45),  INT8_C(  51),  INT8_C( 120), -INT8_C(  93), -INT8_C(  65),  INT8_C(  96), -INT8_C(  30), -INT8_C(  36) },
        {  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
           INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_i8x16_lt(a, b);
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
      r = simde_wasm_i8x16_lt(a, b);

      simde_test_wasm_i8x16_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_i8x16_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_i8x16_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_i16x8_lt(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int16_t a[sizeof(simde_v128_t) / sizeof(int16_t)];
      int16_t b[sizeof(simde_v128_t) / sizeof(int16_t)];
      int16_t r[sizeof(simde_v128_t) / sizeof(int16_t)];
    } test_vec[8] = {
      { {  INT16_C( 29893),  INT16_C( 11051),  INT16_C( 31778),  INT16_C( 25375), -INT16_C(  3385),  INT16_C( 28732), -INT16_C( 29142), -INT16_C( 31194) },
        {  INT16_C(  3050),  INT16_C( 11051),  INT16_C( 31778),  INT16_C( 25375),  INT16_C(  5919), -INT16_C( 23494), -INT16_C( 29142), -INT16_C( 31194) },
        {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
      { { -INT16_C( 20120),  INT16_C(  3081), -INT16_C( 25553),  INT16_C(  9175),  INT16_C(  4209),  INT16_C( 32061), -INT16_C( 14261), -INT16_C( 22271) },
        {  INT16_C( 24499), -INT16_C( 29506),  INT16_C( 30596), -INT16_C( 14964),  INT16_C(   731),  INT16_C(  4596),  INT16_C(  2266), -INT16_C( 30643) },
        { -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0) } },
      { { -INT16_C( 27888), -INT16_C(  8451),  INT16_C( 13629),  INT16_C( 24292), -INT16_C(  8157), -INT16_C(  3336),  INT16_C(  6681), -INT16_C(  1193) },
        {  INT16_C(  9380),  INT16_C( 20028), -INT16_C(  5780), -INT16_C( 24191), -INT16_C(  8157),  INT16_C( 10406), -INT16_C(  5157), -INT16_C( 22213) },
        { -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0) } },
      { { -INT16_C( 21705), -INT16_C( 22698), -INT16_C(  8576),  INT16_C(  2891),  INT16_C( 26712), -INT16_C(  7965),  INT16_C( 17463), -INT16_C( 30642) },
        {  INT16_C( 26885), -INT16_C( 30599),  INT16_C(  1671),  INT16_C( 16268), -INT16_C(  2866), -INT16_C( 25186), -INT16_C( 15347),  INT16_C( 23744) },
        { -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1) } },
      { { -INT16_C(  9320), -INT16_C(  4186),  INT16_C(  6966),  INT16_C( 10571),  INT16_C( 27476), -INT16_C( 17374),  INT16_C(  2883),  INT16_C( 27044) },
        { -INT16_C(  9320),  INT16_C( 16312),  INT16_C(  6966),  INT16_C( 14624), -INT16_C(  5848), -INT16_C( 31131), -INT16_C( 12230), -INT16_C( 32462) },
        {  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
      { { -INT16_C(  8176),  INT16_C( 19562), -INT16_C(  9727), -INT16_C( 21322), -INT16_C( 21727),  INT16_C( 23732), -INT16_C( 21452),  INT16_C( 29233) },
        { -INT16_C( 32733),  INT16_C( 19562), -INT16_C(  9727), -INT16_C(  5153), -INT16_C( 31215),  INT16_C(  7681), -INT16_C( 21452), -INT16_C( 26256) },
        {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
      { { -INT16_C( 16962),  INT16_C(  9244),  INT16_C( 27389), -INT16_C( 29218),  INT16_C(  7180), -INT16_C( 31661),  INT16_C(  2218),  INT16_C(   708) },
        { -INT16_C(  5296),  INT16_C(  1183),  INT16_C( 27389), -INT16_C( 22821),  INT16_C(  7180), -INT16_C( 31661),  INT16_C( 24786), -INT16_C( 10900) },
        { -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0) } },
      { {  INT16_C( 13155), -INT16_C(  5869),  INT16_C(  5196), -INT16_C( 29770),  INT16_C(  4085),  INT16_C(  6114), -INT16_C( 28099),  INT16_C( 26712) },
        { -INT16_C(  3342), -INT16_C(  5869), -INT16_C( 22090), -INT16_C( 20928), -INT16_C(  4204),  INT16_C( 20657),  INT16_C( 20191), -INT16_C( 28417) },
        {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_i16x8_lt(a, b);
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
      r = simde_wasm_i16x8_lt(a, b);

      simde_test_wasm_i16x8_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_i16x8_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_i16x8_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_i32x4_lt(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int32_t a[sizeof(simde_v128_t) / sizeof(int32_t)];
      int32_t b[sizeof(simde_v128_t) / sizeof(int32_t)];
      int32_t r[sizeof(simde_v128_t) / sizeof(int32_t)];
    } test_vec[8] = {
      { {  INT32_C(  1703851729), -INT32_C(   995254126),  INT32_C(  1528608698), -INT32_C(   829868629) },
        {  INT32_C(  1703851729), -INT32_C(   492968726),  INT32_C(   242370304), -INT32_C(   829868629) },
        {  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0) } },
      { {  INT32_C(  1502780055),  INT32_C(   236830763),  INT32_C(  1922873560),  INT32_C(   873709004) },
        {  INT32_C(  1502780055),  INT32_C(  1603779136),  INT32_C(   452639231), -INT32_C(  1985382776) },
        {  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0) } },
      { { -INT32_C(   386911489), -INT32_C(   193467716), -INT32_C(  1402024302), -INT32_C(  1592048603) },
        { -INT32_C(  2064577806),  INT32_C(   767443390), -INT32_C(  1402024302), -INT32_C(   524858099) },
        {  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1) } },
      { { -INT32_C(  1391560799), -INT32_C(  1293028697),  INT32_C(   201475906),  INT32_C(   612997818) },
        {  INT32_C(   156325347), -INT32_C(  1293028697),  INT32_C(  1375770424), -INT32_C(  1954316404) },
        { -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0) } },
      { {  INT32_C(  1726143668),  INT32_C(   133291215), -INT32_C(  1558195892),  INT32_C(   873891925) },
        {  INT32_C(  1726143668), -INT32_C(  2142664396),  INT32_C(  2072897953), -INT32_C(   462881559) },
        {  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0) } },
      { { -INT32_C(  2007980991), -INT32_C(  1689315018),  INT32_C(  2004367423), -INT32_C(   151344547) },
        { -INT32_C(  2007980991), -INT32_C(   918564769),  INT32_C(    11090962), -INT32_C(   730852168) },
        {  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0) } },
      { { -INT32_C(   869574880),  INT32_C(   125877453), -INT32_C(   625323563),  INT32_C(   747742520) },
        { -INT32_C(  1652916465), -INT32_C(   708854472),  INT32_C(  2103235091),  INT32_C(  2107389960) },
        {  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1) } },
      { {  INT32_C(   551553884), -INT32_C(  1750409023),  INT32_C(  2037839869), -INT32_C(    15317994) },
        {  INT32_C(   551553884), -INT32_C(  1750409023), -INT32_C(  1341941969), -INT32_C(    15317994) },
        {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_i32x4_lt(a, b);
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
      r = simde_wasm_i32x4_lt(a, b);

      simde_test_wasm_i32x4_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_i32x4_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_i32x4_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_i64x2_lt(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int64_t a[sizeof(simde_v128_t) / sizeof(int64_t)];
      int64_t b[sizeof(simde_v128_t) / sizeof(int64_t)];
      int64_t r[sizeof(simde_v128_t) / sizeof(int64_t)];
    } test_vec[8] = {
      { { -INT64_C( 6493416597433039942), -INT64_C( 6910421484870465262) },
        {  INT64_C( 3724638633197878307), -INT64_C( 6910421484870465262) },
        { -INT64_C(                   1),  INT64_C(                   0) } },
      { { -INT64_C( 8240141219440043774), -INT64_C( 6474019568254786975) },
        { -INT64_C( 2895402831679084373), -INT64_C( 5610551340326387239) },
        { -INT64_C(                   1), -INT64_C(                   1) } },
      { {  INT64_C( 4234262475826220098), -INT64_C( 3479090803758075041) },
        {  INT64_C( 4234262475826220098),  INT64_C( 7217615262623733439) },
        {  INT64_C(                   0), -INT64_C(                   1) } },
      { { -INT64_C( 6863505383544903178),  INT64_C( 6367181532929242217) },
        {  INT64_C( 8508865757697824325),  INT64_C( 4552351285663343600) },
        { -INT64_C(                   1),  INT64_C(                   0) } },
      { { -INT64_C( 2414269759605395696),  INT64_C( 2946828110503415696) },
        { -INT64_C( 2414269759605395696),  INT64_C( 4046270029682012979) },
        {  INT64_C(                   0), -INT64_C(                   1) } },
      { {  INT64_C( 6360415346208719906), -INT64_C( 7649844558741394131) },
        {  INT64_C( 6360415346208719906), -INT64_C( 1570614915355538684) },
        {  INT64_C(                   0), -INT64_C(                   1) } },
      { { -INT64_C( 1057097116959392339), -INT64_C( 7877457193685363561) },
        {  INT64_C( 4737033175081123638),  INT64_C( 7860424165550284748) },
        { -INT64_C(                   1), -INT64_C(                   1) } },
      { { -INT64_C( 1252379724283661282),  INT64_C( 6700101521805292888) },
        { -INT64_C( 5249289792429265963),  INT64_C( 6289708410360431622) },
        {  INT64_C(                   0),  INT64_C(                   0) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_i64x2_lt(a, b);
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
      r = simde_wasm_i64x2_lt(a, b);

      simde_test_wasm_i64x2_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_i64x2_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_i64x2_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_u8x16_lt(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      uint8_t a[sizeof(simde_v128_t) / sizeof(uint8_t)];
      uint8_t b[sizeof(simde_v128_t) / sizeof(uint8_t)];
      uint8_t r[sizeof(simde_v128_t) / sizeof(uint8_t)];
    } test_vec[8] = {
      { { UINT8_C(103), UINT8_C(198), UINT8_C(235), UINT8_C( 79), UINT8_C( 64), UINT8_C(  4), UINT8_C(199), UINT8_C(243),
          UINT8_C( 32), UINT8_C( 44), UINT8_C(175), UINT8_C(229), UINT8_C(225), UINT8_C(240), UINT8_C( 47), UINT8_C( 31) },
        { UINT8_C(250), UINT8_C(198), UINT8_C( 50), UINT8_C(134), UINT8_C(101), UINT8_C(113), UINT8_C(199), UINT8_C(243),
          UINT8_C( 32), UINT8_C(144), UINT8_C( 99), UINT8_C(229), UINT8_C(162), UINT8_C(240), UINT8_C( 47), UINT8_C( 31) },
        {    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),
          UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) } },
      { { UINT8_C( 85), UINT8_C( 53), UINT8_C( 84), UINT8_C(250), UINT8_C( 35), UINT8_C(161), UINT8_C(221), UINT8_C( 57),
          UINT8_C(188), UINT8_C( 32), UINT8_C( 76), UINT8_C(177), UINT8_C( 74), UINT8_C(241), UINT8_C( 79), UINT8_C( 74) },
        { UINT8_C(116), UINT8_C(168), UINT8_C(222), UINT8_C( 30), UINT8_C(106), UINT8_C( 54), UINT8_C(221), UINT8_C( 57),
          UINT8_C(  0), UINT8_C( 56), UINT8_C( 73), UINT8_C(106), UINT8_C(181), UINT8_C(231), UINT8_C(203), UINT8_C( 74) },
        {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
          UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0) } },
      { { UINT8_C( 16),    UINT8_MAX, UINT8_C(126), UINT8_C( 48), UINT8_C( 93), UINT8_C(154), UINT8_C(162), UINT8_C( 30),
          UINT8_C(  0), UINT8_C( 86), UINT8_C(187), UINT8_C(240), UINT8_C( 11), UINT8_C( 23), UINT8_C( 53), UINT8_C(232) },
        { UINT8_C(232), UINT8_C( 77), UINT8_C(207), UINT8_C( 48), UINT8_C(157), UINT8_C(154), UINT8_C(162), UINT8_C( 41),
          UINT8_C(148), UINT8_C(  1), UINT8_C(195), UINT8_C(251), UINT8_C(240), UINT8_C( 23), UINT8_C(217), UINT8_C(185) },
        {    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,
             UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0) } },
      { { UINT8_C(166), UINT8_C( 93), UINT8_C(160), UINT8_C(129), UINT8_C(163), UINT8_C( 64), UINT8_C(112), UINT8_C( 11),
          UINT8_C(130), UINT8_C(106), UINT8_C( 43), UINT8_C(151), UINT8_C( 66), UINT8_C(251), UINT8_C(117), UINT8_C( 38) },
        { UINT8_C(247), UINT8_C( 93), UINT8_C(211), UINT8_C(107), UINT8_C(233), UINT8_C(204), UINT8_C(112), UINT8_C(174),
          UINT8_C(252), UINT8_C(248), UINT8_C( 95), UINT8_C(192), UINT8_C( 99), UINT8_C(236), UINT8_C(214), UINT8_C(203) },
        {    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,
             UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX } },
      { { UINT8_C( 71), UINT8_C(186), UINT8_C(112), UINT8_C(199), UINT8_C(159), UINT8_C( 31), UINT8_C(173), UINT8_C(228),
          UINT8_C( 49), UINT8_C(138), UINT8_C( 62), UINT8_C(186), UINT8_C(245), UINT8_C( 98), UINT8_C(164), UINT8_C( 88) },
        { UINT8_C( 67), UINT8_C(119), UINT8_C(130), UINT8_C( 66), UINT8_C( 51), UINT8_C(239), UINT8_C( 44), UINT8_C(160),
          UINT8_C( 49), UINT8_C(225), UINT8_C( 62), UINT8_C( 85), UINT8_C( 71), UINT8_C(180), UINT8_C(169), UINT8_C(216) },
        { UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),
          UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX } },
      { { UINT8_C(178), UINT8_C(175), UINT8_C(221), UINT8_C( 22), UINT8_C(113), UINT8_C(118), UINT8_C(129), UINT8_C(118),
          UINT8_C( 91), UINT8_C(170), UINT8_C(113), UINT8_C( 17), UINT8_C(119), UINT8_C(243), UINT8_C(132), UINT8_C(149) },
        { UINT8_C(170), UINT8_C(243), UINT8_C(214), UINT8_C( 70), UINT8_C( 79), UINT8_C(172), UINT8_C(229), UINT8_C( 95),
          UINT8_C( 91), UINT8_C( 44), UINT8_C(113), UINT8_C(137), UINT8_C(119), UINT8_C(141), UINT8_C(241), UINT8_C(148) },
        { UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),
          UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0) } },
      { { UINT8_C(128), UINT8_C( 14), UINT8_C(232), UINT8_C( 21), UINT8_C(247), UINT8_C( 13), UINT8_C(138), UINT8_C(195),
          UINT8_C( 79), UINT8_C(120), UINT8_C( 66), UINT8_C(175), UINT8_C( 84), UINT8_C( 15), UINT8_C(221), UINT8_C(227) },
        { UINT8_C(214), UINT8_C(208), UINT8_C( 97), UINT8_C(195), UINT8_C(247), UINT8_C(114), UINT8_C(235), UINT8_C(195),
          UINT8_C(118), UINT8_C( 46), UINT8_C( 66), UINT8_C( 32), UINT8_C(117), UINT8_C( 44), UINT8_C( 21), UINT8_C(129) },
        {    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),
             UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0) } },
      { { UINT8_C(209), UINT8_C(108), UINT8_C(  6), UINT8_C( 87), UINT8_C( 72), UINT8_C(252), UINT8_C(244), UINT8_C(155),
          UINT8_C( 27), UINT8_C(156), UINT8_C(182), UINT8_C(110), UINT8_C( 55), UINT8_C( 87), UINT8_C(133), UINT8_C(135) },
        { UINT8_C(209), UINT8_C(208), UINT8_C(125), UINT8_C( 87), UINT8_C( 72), UINT8_C(252), UINT8_C( 86), UINT8_C(127),
          UINT8_C( 25), UINT8_C( 31), UINT8_C(226), UINT8_C(219), UINT8_C( 21), UINT8_C( 87), UINT8_C(133), UINT8_C(237) },
        { UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
          UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_u8x16_lt(a, b);
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
      r = simde_wasm_u8x16_lt(a, b);

      simde_test_wasm_u8x16_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_u8x16_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_u8x16_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_u16x8_lt(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      uint16_t a[sizeof(simde_v128_t) / sizeof(uint16_t)];
      uint16_t b[sizeof(simde_v128_t) / sizeof(uint16_t)];
      uint16_t r[sizeof(simde_v128_t) / sizeof(uint16_t)];
    } test_vec[8] = {
      { { UINT16_C(46289), UINT16_C(10121), UINT16_C(52473), UINT16_C( 6017), UINT16_C(47594), UINT16_C(39327), UINT16_C(21324), UINT16_C(55830) },
        { UINT16_C(15714), UINT16_C(10121), UINT16_C(41702), UINT16_C(55421), UINT16_C(25065), UINT16_C(39327), UINT16_C(21324), UINT16_C(64078) },
        { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX } },
      { { UINT16_C(45406), UINT16_C(35146), UINT16_C(29597), UINT16_C(63527), UINT16_C(16546), UINT16_C(17824), UINT16_C(34196), UINT16_C(23300) },
        { UINT16_C(47487), UINT16_C(16699), UINT16_C(48545), UINT16_C(16598), UINT16_C(34204), UINT16_C(59816), UINT16_C(63765), UINT16_C(37869) },
        {      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX } },
      { { UINT16_C( 8051), UINT16_C( 7273), UINT16_C(36221), UINT16_C(34784), UINT16_C(55750), UINT16_C(23796), UINT16_C(43659), UINT16_C(30749) },
        { UINT16_C( 8051), UINT16_C( 9314), UINT16_C( 9433), UINT16_C(16068), UINT16_C(55119), UINT16_C(23796), UINT16_C(63754), UINT16_C(30749) },
        { UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0) } },
      { { UINT16_C(46299), UINT16_C( 2790), UINT16_C(14785), UINT16_C(43469), UINT16_C(64416), UINT16_C(56939), UINT16_C( 6230), UINT16_C(16800) },
        { UINT16_C(24137), UINT16_C(18977), UINT16_C(42242), UINT16_C( 1867), UINT16_C(59131), UINT16_C( 4966), UINT16_C(61488), UINT16_C(14925) },
        { UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0) } },
      { { UINT16_C(50729), UINT16_C(  882), UINT16_C(24039), UINT16_C(47349), UINT16_C(39391), UINT16_C(19357), UINT16_C(41132), UINT16_C(33628) },
        { UINT16_C(50729), UINT16_C(34577), UINT16_C(54148), UINT16_C(41026), UINT16_C(32689), UINT16_C(17260), UINT16_C( 1805), UINT16_C(39819) },
        { UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX } },
      { { UINT16_C(54999), UINT16_C(60893), UINT16_C(31463), UINT16_C(46462), UINT16_C( 1116), UINT16_C(37604), UINT16_C(46017), UINT16_C(41760) },
        { UINT16_C(60785), UINT16_C(61978), UINT16_C( 6352), UINT16_C( 8440), UINT16_C(10608), UINT16_C(38021), UINT16_C( 7296), UINT16_C(62775) },
        {      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX } },
      { { UINT16_C(21585), UINT16_C(31109), UINT16_C( 1953), UINT16_C(48971), UINT16_C(13690), UINT16_C( 5599), UINT16_C(61844), UINT16_C( 7703) },
        { UINT16_C(21585), UINT16_C(61866), UINT16_C(28667), UINT16_C(17433), UINT16_C(32664), UINT16_C( 5599), UINT16_C(33611), UINT16_C(48868) },
        { UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX } },
      { { UINT16_C(21289), UINT16_C(  334), UINT16_C(29713), UINT16_C(12870), UINT16_C( 2518), UINT16_C(61039), UINT16_C( 3725), UINT16_C(53679) },
        { UINT16_C(21289), UINT16_C(  334), UINT16_C(37885), UINT16_C(25057), UINT16_C(46210), UINT16_C(49092), UINT16_C(47263), UINT16_C(50196) },
        { UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_u16x8_lt(a, b);
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
      r = simde_wasm_u16x8_lt(a, b);

      simde_test_wasm_u16x8_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_u16x8_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_u16x8_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_u32x4_lt(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      uint32_t a[sizeof(simde_v128_t) / sizeof(uint32_t)];
      uint32_t b[sizeof(simde_v128_t) / sizeof(uint32_t)];
      uint32_t r[sizeof(simde_v128_t) / sizeof(uint32_t)];
    } test_vec[8] = {
      { { UINT32_C(2441611464), UINT32_C( 727981481), UINT32_C(1273969625), UINT32_C(3362605614) },
        { UINT32_C(2236375723), UINT32_C(1415821013), UINT32_C(1273969625), UINT32_C(3738895134) },
        { UINT32_C(         0),           UINT32_MAX, UINT32_C(         0),           UINT32_MAX } },
      { { UINT32_C(3835981515), UINT32_C( 907965326), UINT32_C(2372340768), UINT32_C(3345436828) },
        { UINT32_C(2100245115), UINT32_C(2025898773), UINT32_C( 732784254), UINT32_C( 730815145) },
        { UINT32_C(         0),           UINT32_MAX, UINT32_C(         0), UINT32_C(         0) } },
      { { UINT32_C( 245668412), UINT32_C( 217473613), UINT32_C( 723843692), UINT32_C( 238004170) },
        { UINT32_C(1411980158), UINT32_C( 217473613), UINT32_C(3066636076), UINT32_C(3781058989) },
        {           UINT32_MAX, UINT32_C(         0),           UINT32_MAX,           UINT32_MAX } },
      { { UINT32_C(3654926364), UINT32_C(3949262092), UINT32_C(2842150239), UINT32_C(3554602687) },
        { UINT32_C(3654926364), UINT32_C(3949262092), UINT32_C(1112378855), UINT32_C( 585908116) },
        { UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0) } },
      { { UINT32_C(2165791086), UINT32_C( 618010436), UINT32_C( 288415782), UINT32_C(4106863134) },
        { UINT32_C(3576466210), UINT32_C(4093728570), UINT32_C(3031931576), UINT32_C( 865730133) },
        {           UINT32_MAX,           UINT32_MAX,           UINT32_MAX, UINT32_C(         0) } },
      { { UINT32_C(1536893571), UINT32_C( 403400656), UINT32_C( 755027178), UINT32_C(2625825461) },
        { UINT32_C(2741979645), UINT32_C(4095229897), UINT32_C(1649619005), UINT32_C(3632571232) },
        {           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX } },
      { { UINT32_C(4027556265), UINT32_C(3095565934), UINT32_C(3708779269), UINT32_C( 594963949) },
        { UINT32_C(4027556265), UINT32_C(2502234271), UINT32_C(3476975833), UINT32_C( 594963949) },
        { UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0) } },
      { { UINT32_C(4234917236), UINT32_C( 459261778), UINT32_C(  79901306), UINT32_C(1659404467) },
        { UINT32_C( 962235951), UINT32_C( 459261778), UINT32_C(3273951338), UINT32_C(1659404467) },
        { UINT32_C(         0), UINT32_C(         0),           UINT32_MAX, UINT32_C(         0) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_u32x4_lt(a, b);
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
      r = simde_wasm_u32x4_lt(a, b);

      simde_test_wasm_u32x4_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_u32x4_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_u32x4_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_f32x4_lt(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      simde_float32 a[sizeof(simde_v128_t) / sizeof(simde_float32)];
      simde_float32 b[sizeof(simde_v128_t) / sizeof(simde_float32)];
      int32_t r[sizeof(simde_v128_t) / sizeof(simde_float32)];
    } test_vec[8] = {
      { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -654.22),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -360.31) },
        { SIMDE_FLOAT32_C(  -138.65),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -360.31) },
        {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
      { { SIMDE_FLOAT32_C(  -794.47), SIMDE_FLOAT32_C(  -667.47), SIMDE_FLOAT32_C(  -174.22), SIMDE_FLOAT32_C(   450.86) },
        { SIMDE_FLOAT32_C(  -468.21), SIMDE_FLOAT32_C(   619.55), SIMDE_FLOAT32_C(  -139.41), SIMDE_FLOAT32_C(  -256.51) },
        { -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0) } },
      { { SIMDE_FLOAT32_C(   249.87), SIMDE_FLOAT32_C(   192.87), SIMDE_FLOAT32_C(   255.81), SIMDE_FLOAT32_C(   283.08) },
        { SIMDE_FLOAT32_C(   649.19), SIMDE_FLOAT32_C(     7.98), SIMDE_FLOAT32_C(   275.08), SIMDE_FLOAT32_C(  -284.14) },
        { -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0) } },
      { { SIMDE_FLOAT32_C(   512.56), SIMDE_FLOAT32_C(   414.97), SIMDE_FLOAT32_C(  -319.16), SIMDE_FLOAT32_C(   408.96) },
        { SIMDE_FLOAT32_C(  -773.09), SIMDE_FLOAT32_C(  -622.47), SIMDE_FLOAT32_C(  -249.25), SIMDE_FLOAT32_C(  -251.00) },
        {  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0) } },
      { { SIMDE_FLOAT32_C(   552.08), SIMDE_FLOAT32_C(   701.68), SIMDE_FLOAT32_C(   795.67), SIMDE_FLOAT32_C(   301.61) },
        { SIMDE_FLOAT32_C(  -207.74), SIMDE_FLOAT32_C(  -405.28), SIMDE_FLOAT32_C(   247.43), SIMDE_FLOAT32_C(   847.61) },
        {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1) } },
      { { SIMDE_FLOAT32_C(   382.92), SIMDE_FLOAT32_C(  -705.28), SIMDE_FLOAT32_C(  -153.83), SIMDE_FLOAT32_C(   912.94) },
        { SIMDE_FLOAT32_C(  -385.25), SIMDE_FLOAT32_C(  -709.37), SIMDE_FLOAT32_C(   277.16), SIMDE_FLOAT32_C(   829.68) },
        {  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0) } },
      { { SIMDE_FLOAT32_C(   370.93), SIMDE_FLOAT32_C(  -511.82), SIMDE_FLOAT32_C(   781.77), SIMDE_FLOAT32_C(   903.19) },
        { SIMDE_FLOAT32_C(  -864.23), SIMDE_FLOAT32_C(   251.32), SIMDE_FLOAT32_C(   704.11), SIMDE_FLOAT32_C(  -617.37) },
        {  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0) } },
      { { SIMDE_FLOAT32_C(   233.43), SIMDE_FLOAT32_C(   -10.18), SIMDE_FLOAT32_C(   345.19), SIMDE_FLOAT32_C(   329.32) },
        { SIMDE_FLOAT32_C(  -631.51), SIMDE_FLOAT32_C(  -991.46), SIMDE_FLOAT32_C(   176.63), SIMDE_FLOAT32_C(    77.26) },
        {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_f32x4_lt(a, b);
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

      r = simde_wasm_f32x4_lt(a, b);

      simde_test_wasm_f32x4_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_f32x4_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_i32x4_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_f64x2_lt(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      simde_float64 a[sizeof(simde_v128_t) / sizeof(simde_float64)];
      simde_float64 b[sizeof(simde_v128_t) / sizeof(simde_float64)];
      int64_t r[sizeof(simde_v128_t) / sizeof(simde_float64)];
    } test_vec[8] = {
      { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -373.94) },
        { SIMDE_FLOAT64_C(   563.44),             SIMDE_MATH_NAN },
        {  INT64_C(                   0),  INT64_C(                   0) } },
      { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   387.11) },
        {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   387.11) },
        {  INT64_C(                   0),  INT64_C(                   0) } },
      { { SIMDE_FLOAT64_C(   114.14), SIMDE_FLOAT64_C(  -142.49) },
        { SIMDE_FLOAT64_C(   950.02), SIMDE_FLOAT64_C(  -629.11) },
        { -INT64_C(                   1),  INT64_C(                   0) } },
      { { SIMDE_FLOAT64_C(  -425.74), SIMDE_FLOAT64_C(   764.13) },
        { SIMDE_FLOAT64_C(   356.10), SIMDE_FLOAT64_C(  -448.52) },
        { -INT64_C(                   1),  INT64_C(                   0) } },
      { { SIMDE_FLOAT64_C(    88.47), SIMDE_FLOAT64_C(  -619.96) },
        { SIMDE_FLOAT64_C(  -480.72), SIMDE_FLOAT64_C(   401.00) },
        {  INT64_C(                   0), -INT64_C(                   1) } },
      { { SIMDE_FLOAT64_C(   -56.52), SIMDE_FLOAT64_C(   886.33) },
        { SIMDE_FLOAT64_C(   754.63), SIMDE_FLOAT64_C(   418.89) },
        { -INT64_C(                   1),  INT64_C(                   0) } },
      { { SIMDE_FLOAT64_C(   191.78), SIMDE_FLOAT64_C(   332.21) },
        { SIMDE_FLOAT64_C(   389.88), SIMDE_FLOAT64_C(  -968.47) },
        { -INT64_C(                   1),  INT64_C(                   0) } },
      { { SIMDE_FLOAT64_C(  -858.83), SIMDE_FLOAT64_C(   648.55) },
        { SIMDE_FLOAT64_C(  -366.40), SIMDE_FLOAT64_C(    23.80) },
        { -INT64_C(                   1),  INT64_C(                   0) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_f64x2_lt(a, b);
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

      r = simde_wasm_f64x2_lt(a, b);

      simde_test_wasm_f64x2_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_f64x2_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_i64x2_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i8x16_lt)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i16x8_lt)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i32x4_lt)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i64x2_lt)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_u8x16_lt)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_u16x8_lt)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_u32x4_lt)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_f32x4_lt)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_f64x2_lt)
SIMDE_TEST_FUNC_LIST_END

#include "test-simd128-footer.h"
