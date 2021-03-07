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

#define SIMDE_TESTS_CURRENT_ISAX simd128
#include <simde/wasm/simd128.h>
#include <test/wasm/test-simd128.h>

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
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_f32x4_lt)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_f64x2_lt)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/test-x86-footer.h>
