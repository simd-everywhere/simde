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

#define SIMDE_TEST_WASM_SIMD128_INSN le
#include "../../../simde/wasm/simd128.h"
#include "test-simd128.h"

static int
test_simde_wasm_i8x16_le(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int8_t a[sizeof(simde_v128_t) / sizeof(int8_t)];
      int8_t b[sizeof(simde_v128_t) / sizeof(int8_t)];
      int8_t r[sizeof(simde_v128_t) / sizeof(int8_t)];
    } test_vec[8] = {
      { { -INT8_C(  64), -INT8_C(  98), -INT8_C(  86), -INT8_C(  77), -INT8_C(  92),  INT8_C(  39), -INT8_C(  58),  INT8_C(  44),
           INT8_C(   2),  INT8_C(  62), -INT8_C(  35),  INT8_C(   4),  INT8_C(  73), -INT8_C(  42),  INT8_C(  69),  INT8_C( 121) },
        { -INT8_C( 102), -INT8_C(  33), -INT8_C(  74),  INT8_C( 106), -INT8_C(  92),  INT8_C(  39), -INT8_C(  58),  INT8_C(   9),
           INT8_C(  35), -INT8_C(  13), -INT8_C( 117), -INT8_C( 127),  INT8_C(  80), -INT8_C(   9),  INT8_C(  39),  INT8_C( 121) },
        {  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
          -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1) } },
      { {  INT8_C(  60),  INT8_C( 103), -INT8_C(  98), -INT8_C(  99), -INT8_C(  90), -INT8_C(  58), -INT8_C(  53), -INT8_C( 112),
          -INT8_C(  26), -INT8_C( 113), -INT8_C(  34),  INT8_C(  18), -INT8_C(  67),  INT8_C(  19), -INT8_C(  35), -INT8_C( 123) },
        {  INT8_C( 122),  INT8_C( 103), -INT8_C( 121),  INT8_C(  78), -INT8_C(  96),  INT8_C(  51), -INT8_C(  10),  INT8_C(  47),
          -INT8_C(  35),  INT8_C(  85),  INT8_C(  54),  INT8_C(  52), -INT8_C(  87),  INT8_C(  19),  INT8_C(  34), -INT8_C(  99) },
        { -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
           INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1) } },
      { { -INT8_C(  53),  INT8_C( 104), -INT8_C(  63),      INT8_MAX,  INT8_C(  30),  INT8_C(  26),  INT8_C(  92),  INT8_C( 117),
          -INT8_C(  29), -INT8_C(  17),  INT8_C(   3),  INT8_C(  31),  INT8_C(  34), -INT8_C(  39),  INT8_C(   0),  INT8_C(  50) },
        { -INT8_C(  60),  INT8_C(   6), -INT8_C(  64),  INT8_C(  73), -INT8_C(   7),  INT8_C(  26),  INT8_C(  92), -INT8_C( 105),
           INT8_C(  97), -INT8_C(  17), -INT8_C(  88), -INT8_C(  99),  INT8_C(  85), -INT8_C( 127),  INT8_C(  80),  INT8_C(  50) },
        {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
          -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1) } },
      { {  INT8_C(  40), -INT8_C(  45),  INT8_C(  83),  INT8_C( 101), -INT8_C(   2), -INT8_C(  50),  INT8_C(  65),  INT8_C( 105),
          -INT8_C(  95),  INT8_C( 114),  INT8_C(  94), -INT8_C(  31), -INT8_C( 126), -INT8_C(  21),  INT8_C(  77),  INT8_C(  42) },
        { -INT8_C(  36), -INT8_C(  11), -INT8_C( 125),  INT8_C(  20), -INT8_C(  36),  INT8_C( 102),  INT8_C(  65),  INT8_C( 105),
           INT8_C( 111),  INT8_C(  41), -INT8_C(  88), -INT8_C(  23), -INT8_C(  12), -INT8_C(  37),  INT8_C(  72), -INT8_C(  36) },
        {  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
          -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0) } },
      { { -INT8_C(  22), -INT8_C(  39),  INT8_C(  82), -INT8_C(  50), -INT8_C(  43),  INT8_C(  88), -INT8_C(   2), -INT8_C(  86),
           INT8_C(  20),  INT8_C(  11),  INT8_C( 116), -INT8_C( 117),  INT8_C(  15),  INT8_C(  46), -INT8_C(  87),  INT8_C(  70) },
        { -INT8_C(  22), -INT8_C( 115),  INT8_C( 126), -INT8_C(  50),  INT8_C(  24), -INT8_C( 122),  INT8_C(  63), -INT8_C( 113),
           INT8_C(  40),  INT8_C(  40), -INT8_C(  10), -INT8_C(   3),  INT8_C(  15),  INT8_C(  43), -INT8_C(  70),  INT8_C(  84) },
        { -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
          -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1) } },
      { { -INT8_C(  72), -INT8_C( 108),  INT8_C(  79), -INT8_C( 126), -INT8_C(  68),  INT8_C(  38), -INT8_C(  23),  INT8_C( 116),
          -INT8_C(  53), -INT8_C( 120),  INT8_C( 118),  INT8_C(  95), -INT8_C(   3),      INT8_MAX,  INT8_C(   6), -INT8_C(  79) },
        { -INT8_C(  92), -INT8_C(  90),  INT8_C(  38),  INT8_C(   9), -INT8_C(  68),  INT8_C(  27), -INT8_C(  70), -INT8_C(  72),
          -INT8_C(  53),  INT8_C(  66),  INT8_C(  43), -INT8_C(  21),  INT8_C( 119),      INT8_MAX,  INT8_C(   6), -INT8_C(  79) },
        {  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
          -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1) } },
      { { -INT8_C( 121),  INT8_C(  93), -INT8_C(   8), -INT8_C(  65),  INT8_C(  45), -INT8_C(  95), -INT8_C(  43),  INT8_C(  19),
           INT8_C(   8), -INT8_C(  56), -INT8_C(  17),  INT8_C( 104),  INT8_C(   3),  INT8_C(  34), -INT8_C( 124), -INT8_C( 119) },
        {  INT8_C( 105),  INT8_C(  92), -INT8_C(   8), -INT8_C(  21),  INT8_C( 113), -INT8_C(  41), -INT8_C( 101), -INT8_C(  73),
          -INT8_C(  89), -INT8_C(  56), -INT8_C(  17),  INT8_C( 104),  INT8_C( 102), -INT8_C(  58), -INT8_C( 111),  INT8_C( 123) },
        { -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
           INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1) } },
      { {  INT8_C( 103),  INT8_C(  34), -INT8_C(  26),  INT8_C(  98),  INT8_C(  74), -INT8_C( 120), -INT8_C(  36),  INT8_C(  61),
           INT8_C(  44), -INT8_C(  92),  INT8_C( 125), -INT8_C(  46),  INT8_C(  22),  INT8_C(  67),  INT8_C( 117), -INT8_C( 115) },
        {  INT8_C( 100), -INT8_C(  79), -INT8_C(  56),  INT8_C(  98),  INT8_C(  46), -INT8_C( 127), -INT8_C(  36),  INT8_C(  30),
           INT8_C(  44),  INT8_C(  60),  INT8_C( 125),  INT8_C(  53), -INT8_C( 115),  INT8_C(  41),  INT8_C(  58), -INT8_C( 115) },
        {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
          -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_i8x16_le(a, b);
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
      r = simde_wasm_i8x16_le(a, b);

      simde_test_wasm_i8x16_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_i8x16_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_i8x16_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_i16x8_le(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int16_t a[sizeof(simde_v128_t) / sizeof(int16_t)];
      int16_t b[sizeof(simde_v128_t) / sizeof(int16_t)];
      int16_t r[sizeof(simde_v128_t) / sizeof(int16_t)];
    } test_vec[8] = {
      { {  INT16_C( 10843),  INT16_C( 24616),  INT16_C(  8210),  INT16_C( 12745),  INT16_C(  4847),  INT16_C( 30202),  INT16_C(  3782),  INT16_C( 19128) },
        {  INT16_C( 10843), -INT16_C(   764),  INT16_C(  8210), -INT16_C(  6598),  INT16_C(  2333), -INT16_C( 19223),  INT16_C(  3782),  INT16_C( 11865) },
        { -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0) } },
      { { -INT16_C( 31392), -INT16_C(   698),  INT16_C( 28075), -INT16_C( 25575), -INT16_C( 11323),  INT16_C( 12816), -INT16_C( 17913),  INT16_C(  7841) },
        { -INT16_C( 31392), -INT16_C(  1104), -INT16_C(  6958),  INT16_C( 21492), -INT16_C( 16441),  INT16_C( 29979), -INT16_C( 13337), -INT16_C( 26062) },
        { -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0) } },
      { {  INT16_C(  6178), -INT16_C( 11657),  INT16_C( 19606), -INT16_C( 12027),  INT16_C(  1387),  INT16_C( 23347),  INT16_C( 32544),  INT16_C( 15553) },
        { -INT16_C( 13348), -INT16_C( 22862),  INT16_C( 19606), -INT16_C( 12027),  INT16_C( 17361),  INT16_C( 11520),  INT16_C( 32544), -INT16_C(  1222) },
        {  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0) } },
      { {  INT16_C( 13366), -INT16_C( 11779),  INT16_C( 26597),  INT16_C( 31520),  INT16_C( 14392),  INT16_C(  8361), -INT16_C( 13250),  INT16_C( 25423) },
        {  INT16_C( 17855), -INT16_C( 19612),  INT16_C( 29996), -INT16_C( 25646),  INT16_C( 12464), -INT16_C( 28240), -INT16_C(  2861),  INT16_C( 25423) },
        { -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1) } },
      { {  INT16_C(  1029),  INT16_C(  5542), -INT16_C( 12748),  INT16_C( 10727),  INT16_C( 26722),  INT16_C( 15729), -INT16_C(  6239), -INT16_C(  5953) },
        {  INT16_C(  5751),  INT16_C( 11201), -INT16_C(  4443),  INT16_C( 21256),  INT16_C( 18749), -INT16_C(  6968),  INT16_C( 30952), -INT16_C( 10763) },
        { -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0) } },
      { {  INT16_C( 20514),  INT16_C( 23531),  INT16_C( 29185),  INT16_C( 22844), -INT16_C( 29707), -INT16_C(  4788), -INT16_C( 11126),  INT16_C( 10538) },
        {  INT16_C( 20514),  INT16_C( 23531), -INT16_C(  5609), -INT16_C( 17625), -INT16_C(  9976),  INT16_C(  7594),  INT16_C( 19518), -INT16_C(  7306) },
        { -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0) } },
      { { -INT16_C( 16383), -INT16_C( 13236), -INT16_C( 17645), -INT16_C(  5430),  INT16_C( 16433),  INT16_C( 31415),  INT16_C( 12589),  INT16_C( 29599) },
        {  INT16_C( 21211), -INT16_C( 22585),  INT16_C( 10428),  INT16_C(  7059),  INT16_C( 16433),  INT16_C( 29593), -INT16_C( 20533),  INT16_C( 24730) },
        { -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
      { {  INT16_C( 30755), -INT16_C( 31235),  INT16_C(  5547), -INT16_C(  5774),  INT16_C( 24521), -INT16_C(  8650), -INT16_C( 17195),  INT16_C( 12559) },
        {  INT16_C( 31701),  INT16_C( 14151),  INT16_C(  8791),  INT16_C(  5915),  INT16_C( 14178), -INT16_C( 28456), -INT16_C( 20776), -INT16_C( 15776) },
        { -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_i16x8_le(a, b);
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
      r = simde_wasm_i16x8_le(a, b);

      simde_test_wasm_i16x8_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_i16x8_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_i16x8_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_i32x4_le(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int32_t a[sizeof(simde_v128_t) / sizeof(int32_t)];
      int32_t b[sizeof(simde_v128_t) / sizeof(int32_t)];
      int32_t r[sizeof(simde_v128_t) / sizeof(int32_t)];
    } test_vec[8] = {
      { { -INT32_C(   641633138),  INT32_C(   334085400),  INT32_C(   657825868), -INT32_C(  1691769315) },
        { -INT32_C(  1689493301), -INT32_C(  1217968335), -INT32_C(   439877935), -INT32_C(  1130597332) },
        {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1) } },
      { { -INT32_C(  1623139800), -INT32_C(  1867235984), -INT32_C(   916104663), -INT32_C(   693703464) },
        {  INT32_C(  2005871924),  INT32_C(    72961779), -INT32_C(  1881388774),  INT32_C(   166608131) },
        { -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1) } },
      { { -INT32_C(    86408461),  INT32_C(    63388036), -INT32_C(   995289970),  INT32_C(  2084470228) },
        { -INT32_C(  1152435154), -INT32_C(   242849587), -INT32_C(  1415166194), -INT32_C(   429306762) },
        {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
      { { -INT32_C(  1463872260),  INT32_C(  1370885641),  INT32_C(  1894277289),  INT32_C(  1639250188) },
        {  INT32_C(   489112665),  INT32_C(   818306833),  INT32_C(  1894277289),  INT32_C(  1639250188) },
        { -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1) } },
      { { -INT32_C(   114540755), -INT32_C(  2104889067),  INT32_C(  2144905466),  INT32_C(  1199960527) },
        { -INT32_C(  1107924493),  INT32_C(  1402864621),  INT32_C(  2144905466),  INT32_C(  1199960527) },
        {  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1) } },
      { {  INT32_C(  1000772071), -INT32_C(   750424987), -INT32_C(   847782199),  INT32_C(   265880717) },
        { -INT32_C(  1151121416), -INT32_C(   750424987), -INT32_C(   989857803),  INT32_C(   265880717) },
        {  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1) } },
      { { -INT32_C(   701697974), -INT32_C(   431485077),  INT32_C(  1399159320),  INT32_C(   612801417) },
        { -INT32_C(   796164479), -INT32_C(   265544834),  INT32_C(  1399159320),  INT32_C(   612801417) },
        {  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1) } },
      { { -INT32_C(   577250832), -INT32_C(  1800788178),  INT32_C(   668441341),  INT32_C(  1410154748) },
        { -INT32_C(  1303493147),  INT32_C(  1517263426),  INT32_C(   668441341), -INT32_C(   109290649) },
        {  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_i32x4_le(a, b);
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
      r = simde_wasm_i32x4_le(a, b);

      simde_test_wasm_i32x4_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_i32x4_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_i32x4_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_i64x2_le(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int64_t a[sizeof(simde_v128_t) / sizeof(int64_t)];
      int64_t b[sizeof(simde_v128_t) / sizeof(int64_t)];
      int64_t r[sizeof(simde_v128_t) / sizeof(int64_t)];
    } test_vec[8] = {
      { { -INT64_C( 6633089975700672431),  INT64_C( 7170540665161578421) },
        { -INT64_C( 3109489700142018317), -INT64_C( 3315151605662476068) },
        { -INT64_C(                   1),  INT64_C(                   0) } },
      { { -INT64_C(  472591423130714161),  INT64_C( 3102183106887713991) },
        { -INT64_C(  472591423130714161), -INT64_C( 8970371345102058981) },
        { -INT64_C(                   1),  INT64_C(                   0) } },
      { { -INT64_C( 4016917703477408448), -INT64_C( 2177289370860448508) },
        {  INT64_C( 1831486116139945838), -INT64_C( 3946742373130816284) },
        { -INT64_C(                   1),  INT64_C(                   0) } },
      { {  INT64_C( 8480562224831486336),  INT64_C( 4816880470374300202) },
        { -INT64_C( 2276525409649774322),  INT64_C( 4816880470374300202) },
        {  INT64_C(                   0), -INT64_C(                   1) } },
      { {  INT64_C( 1396051664902563135),  INT64_C( 4090809949497806591) },
        {  INT64_C( 8415361665117139932),  INT64_C( 3528439114023175681) },
        { -INT64_C(                   1),  INT64_C(                   0) } },
      { { -INT64_C( 4473895998062527835), -INT64_C( 3263834742461239708) },
        {  INT64_C( 1677403283843169179),  INT64_C( 8653051872818405392) },
        { -INT64_C(                   1), -INT64_C(                   1) } },
      { { -INT64_C( 2412608752326095955),  INT64_C( 7812242071035783472) },
        { -INT64_C( 2412608752326095955),  INT64_C( 7812242071035783472) },
        { -INT64_C(                   1), -INT64_C(                   1) } },
      { {  INT64_C( 4964283526157337441),  INT64_C( 1741316602639400055) },
        { -INT64_C( 3494601185675255505),  INT64_C( 7127513578599432169) },
        {  INT64_C(                   0), -INT64_C(                   1) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_i64x2_le(a, b);
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
      r = simde_wasm_i64x2_le(a, b);

      simde_test_wasm_i64x2_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_i64x2_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_i64x2_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_u8x16_le(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      uint8_t a[sizeof(simde_v128_t) / sizeof(uint8_t)];
      uint8_t b[sizeof(simde_v128_t) / sizeof(uint8_t)];
      uint8_t r[sizeof(simde_v128_t) / sizeof(uint8_t)];
    } test_vec[8] = {
      { { UINT8_C(212), UINT8_C(221), UINT8_C(239), UINT8_C( 25), UINT8_C(114), UINT8_C(159), UINT8_C(212), UINT8_C(154),
          UINT8_C(178), UINT8_C( 14), UINT8_C(  1), UINT8_C(195), UINT8_C(192), UINT8_C(142), UINT8_C( 88), UINT8_C(166) },
        { UINT8_C(147), UINT8_C(221), UINT8_C(145), UINT8_C(223), UINT8_C( 17), UINT8_C(159), UINT8_C(212), UINT8_C(154),
          UINT8_C(  1), UINT8_C(180), UINT8_C(151), UINT8_C( 14), UINT8_C(192), UINT8_C( 72), UINT8_C( 88), UINT8_C(166) },
        { UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
          UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX } },
      { { UINT8_C(161), UINT8_C( 33), UINT8_C( 22), UINT8_C( 14), UINT8_C( 27), UINT8_C( 89), UINT8_C( 33), UINT8_C(137),
          UINT8_C( 52), UINT8_C(250), UINT8_C(  5), UINT8_C( 52), UINT8_C( 87), UINT8_C( 12), UINT8_C( 71), UINT8_C( 50) },
        { UINT8_C(161), UINT8_C(134), UINT8_C( 22), UINT8_C(178), UINT8_C( 57), UINT8_C( 78), UINT8_C( 33), UINT8_C(122),
          UINT8_C(188), UINT8_C(250), UINT8_C( 44), UINT8_C( 19), UINT8_C(219), UINT8_C(215), UINT8_C( 71), UINT8_C( 78) },
        {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),
             UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX } },
      { { UINT8_C( 96), UINT8_C(134), UINT8_C( 45), UINT8_C( 64), UINT8_C(150), UINT8_C(161), UINT8_C(191), UINT8_C(184),
          UINT8_C( 52), UINT8_C( 11), UINT8_C( 19), UINT8_C( 85), UINT8_C(246), UINT8_C( 81), UINT8_C(212), UINT8_C(236) },
        { UINT8_C( 48), UINT8_C( 18), UINT8_C( 33), UINT8_C(253), UINT8_C(210), UINT8_C(231), UINT8_C(122), UINT8_C( 21),
          UINT8_C(158), UINT8_C(114), UINT8_C(222), UINT8_C( 85), UINT8_C(246), UINT8_C(126), UINT8_C(196), UINT8_C(180) },
        { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),
             UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0) } },
      { { UINT8_C(138), UINT8_C(160), UINT8_C(144), UINT8_C( 17), UINT8_C( 55), UINT8_C(123), UINT8_C( 74), UINT8_C(213),
          UINT8_C(101), UINT8_C( 44), UINT8_C(110), UINT8_C(124), UINT8_C(215), UINT8_C(231), UINT8_C( 27), UINT8_C( 51) },
        { UINT8_C(151), UINT8_C( 26), UINT8_C( 88), UINT8_C(242), UINT8_C(228), UINT8_C(228), UINT8_C( 56), UINT8_C( 22),
          UINT8_C( 44), UINT8_C( 44), UINT8_C(173), UINT8_C( 34), UINT8_C(209), UINT8_C(142), UINT8_C(174), UINT8_C( 51) },
        {    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),
          UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX } },
      { { UINT8_C( 87), UINT8_C( 45), UINT8_C(245), UINT8_C( 57), UINT8_C(  1), UINT8_C(242), UINT8_C(248), UINT8_C( 90),
          UINT8_C(122), UINT8_C(212), UINT8_C(122), UINT8_C(212), UINT8_C(101), UINT8_C( 60), UINT8_C(215), UINT8_C(114) },
        { UINT8_C(136), UINT8_C(223), UINT8_C(245), UINT8_C( 36), UINT8_C(  1), UINT8_C( 67), UINT8_C(229), UINT8_C( 74),
          UINT8_C( 13), UINT8_C( 70), UINT8_C( 90), UINT8_C(212), UINT8_C(145), UINT8_C( 12), UINT8_C( 55), UINT8_C( 67) },
        {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
          UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) } },
      { { UINT8_C( 17), UINT8_C(114), UINT8_C(109), UINT8_C( 68), UINT8_C(160), UINT8_C(232), UINT8_C( 74), UINT8_C( 53),
          UINT8_C(115), UINT8_C(217), UINT8_C(  8), UINT8_C(252), UINT8_C( 11), UINT8_C(125), UINT8_C(170), UINT8_C(246) },
        { UINT8_C( 86), UINT8_C(171), UINT8_C(140), UINT8_C(101), UINT8_C(189), UINT8_C(151), UINT8_C(197), UINT8_C(211),
          UINT8_C( 54), UINT8_C(166), UINT8_C( 29), UINT8_C( 40), UINT8_C( 70), UINT8_C(252), UINT8_C( 41), UINT8_C(246) },
        {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,
          UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX } },
      { { UINT8_C(171), UINT8_C( 75), UINT8_C(109), UINT8_C(182), UINT8_C(142), UINT8_C(249), UINT8_C(165), UINT8_C(122),
          UINT8_C(247), UINT8_C(179), UINT8_C( 99), UINT8_C(  7), UINT8_C(223), UINT8_C( 73), UINT8_C( 11), UINT8_C(144) },
        { UINT8_C(160), UINT8_C(108), UINT8_C( 41), UINT8_C(200), UINT8_C( 13), UINT8_C(157), UINT8_C( 14), UINT8_C(226),
          UINT8_C(247), UINT8_C( 99), UINT8_C( 99), UINT8_C(210), UINT8_C(233), UINT8_C(  5), UINT8_C(118), UINT8_C(170) },
        { UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,
             UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX } },
      { { UINT8_C( 53), UINT8_C(107), UINT8_C( 80), UINT8_C( 80), UINT8_C(237), UINT8_C(  0), UINT8_C( 67), UINT8_C(145),
          UINT8_C( 59), UINT8_C(189), UINT8_C(151), UINT8_C(105), UINT8_C(205), UINT8_C(179), UINT8_C( 79), UINT8_C(123) },
        { UINT8_C( 80), UINT8_C( 12), UINT8_C(184), UINT8_C( 80), UINT8_C(217), UINT8_C(238), UINT8_C(162), UINT8_C( 98),
          UINT8_C(254), UINT8_C(118), UINT8_C(151), UINT8_C(175), UINT8_C( 75), UINT8_C(228), UINT8_C( 79), UINT8_C( 62) },
        {    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),
             UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_u8x16_le(a, b);
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
      r = simde_wasm_u8x16_le(a, b);

      simde_test_wasm_u8x16_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_u8x16_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_u8x16_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_u16x8_le(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      uint16_t a[sizeof(simde_v128_t) / sizeof(uint16_t)];
      uint16_t b[sizeof(simde_v128_t) / sizeof(uint16_t)];
      uint16_t r[sizeof(simde_v128_t) / sizeof(uint16_t)];
    } test_vec[8] = {
      { { UINT16_C(23438), UINT16_C(64989), UINT16_C(41609), UINT16_C(30211), UINT16_C(59388), UINT16_C(16247), UINT16_C( 9122), UINT16_C( 1093) },
        { UINT16_C(23438), UINT16_C(45779), UINT16_C(41609), UINT16_C(30211), UINT16_C(12327), UINT16_C(57614), UINT16_C(16678), UINT16_C(64823) },
        {      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX } },
      { { UINT16_C(56045), UINT16_C(10778), UINT16_C(23916), UINT16_C(17266), UINT16_C(42738), UINT16_C(59969), UINT16_C(31881), UINT16_C(30360) },
        { UINT16_C(25090), UINT16_C(36069), UINT16_C(23916), UINT16_C(32518), UINT16_C(32857), UINT16_C(58779), UINT16_C(52906), UINT16_C(39434) },
        { UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX } },
      { { UINT16_C(35861), UINT16_C(17507), UINT16_C( 3761), UINT16_C( 9506), UINT16_C(64810), UINT16_C(56830), UINT16_C(11160), UINT16_C(14734) },
        { UINT16_C(50379), UINT16_C(17507), UINT16_C(25172), UINT16_C(63124), UINT16_C(48050), UINT16_C(56830), UINT16_C(17309), UINT16_C(64587) },
        {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX } },
      { { UINT16_C(39480), UINT16_C(26631), UINT16_C(48867), UINT16_C( 3759), UINT16_C(52903), UINT16_C( 7877), UINT16_C(35934), UINT16_C(15296) },
        { UINT16_C(39480), UINT16_C(56461), UINT16_C(50625), UINT16_C(29873), UINT16_C(52903), UINT16_C(61126), UINT16_C(12313), UINT16_C(49108) },
        {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX } },
      { { UINT16_C(45294), UINT16_C(45879), UINT16_C(31402), UINT16_C(25883), UINT16_C(60094), UINT16_C(14463), UINT16_C(41500), UINT16_C( 1723) },
        { UINT16_C(14813), UINT16_C(45879), UINT16_C(60513), UINT16_C(36523), UINT16_C(60094), UINT16_C(19788), UINT16_C(52171), UINT16_C(53791) },
        { UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX } },
      { { UINT16_C( 4747), UINT16_C(65414), UINT16_C(38200), UINT16_C(39973), UINT16_C( 7424), UINT16_C(23872), UINT16_C(53210), UINT16_C(65461) },
        { UINT16_C(59341), UINT16_C(65414), UINT16_C(32656), UINT16_C(14616), UINT16_C(25529), UINT16_C(51910), UINT16_C(53210), UINT16_C(65461) },
        {      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX } },
      { { UINT16_C(19226), UINT16_C(62595), UINT16_C(18273), UINT16_C(49183), UINT16_C(38271), UINT16_C(24574), UINT16_C(51640), UINT16_C(54139) },
        { UINT16_C( 6660), UINT16_C(26791), UINT16_C( 5246), UINT16_C(49183), UINT16_C(11965), UINT16_C( 5736), UINT16_C(22053), UINT16_C(54139) },
        { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX } },
      { { UINT16_C(   33), UINT16_C(33667), UINT16_C( 1835), UINT16_C(41870), UINT16_C( 3314), UINT16_C(28969), UINT16_C(12990), UINT16_C(33849) },
        { UINT16_C(31545), UINT16_C(37776), UINT16_C(38291), UINT16_C( 2796), UINT16_C( 3314), UINT16_C(21588), UINT16_C(15493), UINT16_C(57998) },
        {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_u16x8_le(a, b);
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
      r = simde_wasm_u16x8_le(a, b);

      simde_test_wasm_u16x8_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_u16x8_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_u16x8_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_u32x4_le(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      uint32_t a[sizeof(simde_v128_t) / sizeof(uint32_t)];
      uint32_t b[sizeof(simde_v128_t) / sizeof(uint32_t)];
      uint32_t r[sizeof(simde_v128_t) / sizeof(uint32_t)];
    } test_vec[8] = {
      { { UINT32_C(1839976530), UINT32_C(2430376345), UINT32_C( 528978983), UINT32_C(4039738696) },
        { UINT32_C(1834484139), UINT32_C(2430376345), UINT32_C(2359698870), UINT32_C(4039738696) },
        { UINT32_C(         0),           UINT32_MAX,           UINT32_MAX,           UINT32_MAX } },
      { { UINT32_C(2561384856), UINT32_C(2602083315), UINT32_C(3876192835), UINT32_C(1284316678) },
        { UINT32_C(  82349048), UINT32_C(2897259425), UINT32_C(  28893300), UINT32_C(1886641253) },
        { UINT32_C(         0),           UINT32_MAX, UINT32_C(         0),           UINT32_MAX } },
      { { UINT32_C(3076505891), UINT32_C(4145147984), UINT32_C(2951152866), UINT32_C(1434387015) },
        { UINT32_C(1231707229), UINT32_C( 984333349), UINT32_C(2951152866), UINT32_C( 173992790) },
        { UINT32_C(         0), UINT32_C(         0),           UINT32_MAX, UINT32_C(         0) } },
      { { UINT32_C(2570672496), UINT32_C( 989556944), UINT32_C(  58203811), UINT32_C(1606786521) },
        { UINT32_C(3148487129), UINT32_C(2730158196), UINT32_C(1399490402), UINT32_C(1606786521) },
        {           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX } },
      { { UINT32_C(3140362154), UINT32_C(2524311068), UINT32_C(2107188243), UINT32_C(3858085352) },
        { UINT32_C(2810464111), UINT32_C(1076980926), UINT32_C(2093415768), UINT32_C(3858085352) },
        { UINT32_C(         0), UINT32_C(         0), UINT32_C(         0),           UINT32_MAX } },
      { { UINT32_C(3972751880), UINT32_C(4029750996), UINT32_C(2288928303), UINT32_C(3299227114) },
        { UINT32_C( 274038743), UINT32_C(1092055900), UINT32_C(2288928303), UINT32_C(3299227114) },
        { UINT32_C(         0), UINT32_C(         0),           UINT32_MAX,           UINT32_MAX } },
      { { UINT32_C(1616763872), UINT32_C(3164526518), UINT32_C(4042026396), UINT32_C(2552859869) },
        { UINT32_C(1328402938), UINT32_C( 285653331), UINT32_C( 457320238), UINT32_C(1468771624) },
        { UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0) } },
      { { UINT32_C( 774939868), UINT32_C(2259024971), UINT32_C(4144857288), UINT32_C(3548653064) },
        { UINT32_C(1952036121), UINT32_C( 122643566), UINT32_C(1957694958), UINT32_C(4246280627) },
        {           UINT32_MAX, UINT32_C(         0), UINT32_C(         0),           UINT32_MAX } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_u32x4_le(a, b);
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
      r = simde_wasm_u32x4_le(a, b);

      simde_test_wasm_u32x4_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_u32x4_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_u32x4_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_f32x4_le(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      simde_float32 a[sizeof(simde_v128_t) / sizeof(simde_float32)];
      simde_float32 b[sizeof(simde_v128_t) / sizeof(simde_float32)];
      int32_t r[sizeof(simde_v128_t) / sizeof(simde_float32)];
    } test_vec[8] = {
      { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   596.13),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -156.80) },
        { SIMDE_FLOAT32_C(   -52.46),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -156.80) },
        {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1) } },
      { { SIMDE_FLOAT32_C(   594.48), SIMDE_FLOAT32_C(   999.36), SIMDE_FLOAT32_C(   488.76), SIMDE_FLOAT32_C(  -599.82) },
        { SIMDE_FLOAT32_C(   782.70), SIMDE_FLOAT32_C(   654.77), SIMDE_FLOAT32_C(   255.45), SIMDE_FLOAT32_C(  -254.66) },
        { -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1) } },
      { { SIMDE_FLOAT32_C(  -610.80), SIMDE_FLOAT32_C(  -546.57), SIMDE_FLOAT32_C(   214.74), SIMDE_FLOAT32_C(    76.59) },
        { SIMDE_FLOAT32_C(  -667.19), SIMDE_FLOAT32_C(   -34.87), SIMDE_FLOAT32_C(   397.15), SIMDE_FLOAT32_C(   232.80) },
        {  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1) } },
      { { SIMDE_FLOAT32_C(  -134.57), SIMDE_FLOAT32_C(   654.38), SIMDE_FLOAT32_C(  -977.28), SIMDE_FLOAT32_C(  -316.23) },
        { SIMDE_FLOAT32_C(   233.56), SIMDE_FLOAT32_C(    28.39), SIMDE_FLOAT32_C(   885.83), SIMDE_FLOAT32_C(  -149.65) },
        { -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1) } },
      { { SIMDE_FLOAT32_C(  -559.65), SIMDE_FLOAT32_C(  -876.35), SIMDE_FLOAT32_C(  -884.33), SIMDE_FLOAT32_C(   408.39) },
        { SIMDE_FLOAT32_C(   883.88), SIMDE_FLOAT32_C(   567.51), SIMDE_FLOAT32_C(  -381.66), SIMDE_FLOAT32_C(   732.76) },
        { -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1) } },
      { { SIMDE_FLOAT32_C(  -660.21), SIMDE_FLOAT32_C(   225.34), SIMDE_FLOAT32_C(   -95.54), SIMDE_FLOAT32_C(  -193.72) },
        { SIMDE_FLOAT32_C(   491.41), SIMDE_FLOAT32_C(  -241.15), SIMDE_FLOAT32_C(   955.83), SIMDE_FLOAT32_C(   969.26) },
        { -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1) } },
      { { SIMDE_FLOAT32_C(   519.45), SIMDE_FLOAT32_C(  -338.94), SIMDE_FLOAT32_C(   969.80), SIMDE_FLOAT32_C(  -786.28) },
        { SIMDE_FLOAT32_C(   535.81), SIMDE_FLOAT32_C(  -553.15), SIMDE_FLOAT32_C(  -744.66), SIMDE_FLOAT32_C(   853.04) },
        { -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1) } },
      { { SIMDE_FLOAT32_C(   163.48), SIMDE_FLOAT32_C(    95.07), SIMDE_FLOAT32_C(  -367.03), SIMDE_FLOAT32_C(   165.43) },
        { SIMDE_FLOAT32_C(   909.52), SIMDE_FLOAT32_C(  -313.29), SIMDE_FLOAT32_C(  -787.27), SIMDE_FLOAT32_C(  -509.65) },
        { -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_f32x4_le(a, b);
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

      r = simde_wasm_f32x4_le(a, b);

      simde_test_wasm_f32x4_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_f32x4_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_i32x4_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_f64x2_le(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      simde_float64 a[sizeof(simde_v128_t) / sizeof(simde_float64)];
      simde_float64 b[sizeof(simde_v128_t) / sizeof(simde_float64)];
      int64_t r[sizeof(simde_v128_t) / sizeof(simde_float64)];
    } test_vec[8] = {
      { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   -51.61) },
        { SIMDE_FLOAT64_C(   -42.09),             SIMDE_MATH_NAN },
        {  INT64_C(                   0),  INT64_C(                   0) } },
      { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -616.38) },
        {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -616.38) },
        {  INT64_C(                   0), -INT64_C(                   1) } },
      { { SIMDE_FLOAT64_C(  -847.29), SIMDE_FLOAT64_C(   500.18) },
        { SIMDE_FLOAT64_C(   799.57), SIMDE_FLOAT64_C(  -342.32) },
        { -INT64_C(                   1),  INT64_C(                   0) } },
      { { SIMDE_FLOAT64_C(   104.50), SIMDE_FLOAT64_C(   659.51) },
        { SIMDE_FLOAT64_C(  -937.48), SIMDE_FLOAT64_C(  -387.72) },
        {  INT64_C(                   0),  INT64_C(                   0) } },
      { { SIMDE_FLOAT64_C(  -508.44), SIMDE_FLOAT64_C(  -454.16) },
        { SIMDE_FLOAT64_C(  -179.28), SIMDE_FLOAT64_C(  -191.13) },
        { -INT64_C(                   1), -INT64_C(                   1) } },
      { { SIMDE_FLOAT64_C(  -392.97), SIMDE_FLOAT64_C(  -529.31) },
        { SIMDE_FLOAT64_C(  -798.86), SIMDE_FLOAT64_C(   177.61) },
        {  INT64_C(                   0), -INT64_C(                   1) } },
      { { SIMDE_FLOAT64_C(    31.47), SIMDE_FLOAT64_C(  -733.24) },
        { SIMDE_FLOAT64_C(   172.97), SIMDE_FLOAT64_C(   807.31) },
        { -INT64_C(                   1), -INT64_C(                   1) } },
      { { SIMDE_FLOAT64_C(  -765.08), SIMDE_FLOAT64_C(  -609.00) },
        { SIMDE_FLOAT64_C(   150.06), SIMDE_FLOAT64_C(  -941.14) },
        { -INT64_C(                   1),  INT64_C(                   0) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_f64x2_le(a, b);
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

      r = simde_wasm_f64x2_le(a, b);

      simde_test_wasm_f64x2_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_f64x2_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_i64x2_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i8x16_le)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i16x8_le)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i32x4_le)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i64x2_le)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_u8x16_le)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_u16x8_le)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_u32x4_le)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_f32x4_le)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_f64x2_le)
SIMDE_TEST_FUNC_LIST_END

#include "test-simd128-footer.h"
