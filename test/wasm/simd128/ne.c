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

#define SIMDE_TEST_WASM_SIMD128_INSN ne
#include "../../../simde/wasm/simd128.h"
#include "test-simd128.h"

static int
test_simde_wasm_i8x16_ne(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int8_t a[sizeof(simde_v128_t) / sizeof(int8_t)];
      int8_t b[sizeof(simde_v128_t) / sizeof(int8_t)];
      int8_t r[sizeof(simde_v128_t) / sizeof(int8_t)];
    } test_vec[8] = {
      { {  INT8_C(  57), -INT8_C(   8),  INT8_C(  95), -INT8_C( 111), -INT8_C(  26), -INT8_C( 122),  INT8_C( 101), -INT8_C(  91),
          -INT8_C( 125),  INT8_C( 118),  INT8_C(  84),  INT8_C(  86), -INT8_C(  17),  INT8_C(  30),  INT8_C( 112),  INT8_C(  95) },
        { -INT8_C(  31), -INT8_C(   8),  INT8_C( 109), -INT8_C( 111), -INT8_C(  26),  INT8_C(   1), -INT8_C( 101),  INT8_C( 121),
          -INT8_C(  59),  INT8_C(  25),  INT8_C(  47), -INT8_C(  42), -INT8_C(  17), -INT8_C(  90),  INT8_C(  36), -INT8_C( 117) },
        { -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
          -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1) } },
      { { -INT8_C(   5),  INT8_C(  56),  INT8_C(  78), -INT8_C(  94), -INT8_C(  79), -INT8_C(   5),  INT8_C( 111),  INT8_C(  39),
           INT8_C( 117),  INT8_C(  80),  INT8_C(  56), -INT8_C(  98),  INT8_C(  29),  INT8_C(  18),  INT8_C( 118),  INT8_C(  27) },
        { -INT8_C( 126), -INT8_C(  87),  INT8_C(  18),  INT8_C(  16),  INT8_C(  70), -INT8_C(  21),  INT8_C(   7),  INT8_C(  39),
           INT8_C( 117), -INT8_C(  59), -INT8_C(  46), -INT8_C( 108), -INT8_C(  27), -INT8_C(  99), -INT8_C(  26), -INT8_C(  44) },
        { -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
           INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1) } },
      { {  INT8_C(  92), -INT8_C(   2),  INT8_C(  48), -INT8_C( 109),  INT8_C(  86),  INT8_C(  93),      INT8_MIN,  INT8_C( 124),
           INT8_C(  54),  INT8_C(  53),  INT8_C(  71), -INT8_C(  61),      INT8_MAX, -INT8_C(  63),  INT8_C(  59), -INT8_C(  71) },
        { -INT8_C( 117),  INT8_C( 119),      INT8_MIN, -INT8_C( 109),  INT8_C(  86),  INT8_C(  18), -INT8_C(  29),  INT8_C( 124),
          -INT8_C(  34),  INT8_C(  49),  INT8_C(   7), -INT8_C(  61),  INT8_C(  57), -INT8_C(  63),  INT8_C(  48), -INT8_C( 109) },
        { -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
          -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1) } },
      { {  INT8_C(  36), -INT8_C(  46), -INT8_C(  79),  INT8_C(  37), -INT8_C(  27), -INT8_C(  38),  INT8_C(  92), -INT8_C(  26),
           INT8_C(   3),  INT8_C(  22), -INT8_C( 127), -INT8_C(  11), -INT8_C(  70), -INT8_C(  89), -INT8_C( 110),  INT8_C(  56) },
        {  INT8_C(  31), -INT8_C(  45), -INT8_C(  44),  INT8_C(  24), -INT8_C(  27), -INT8_C( 106), -INT8_C(  77), -INT8_C(  26),
           INT8_C(  38),  INT8_C(  22), -INT8_C( 127), -INT8_C(  32), -INT8_C(  30),  INT8_C( 119), -INT8_C(   3),  INT8_C( 120) },
        { -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
          -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1) } },
      { { -INT8_C(  24),  INT8_C(  62),  INT8_C(  97), -INT8_C( 118), -INT8_C(  62), -INT8_C( 127), -INT8_C(  95),  INT8_C(  96),
          -INT8_C(  98), -INT8_C(  53),  INT8_C(  98),  INT8_C(  84), -INT8_C(  17),  INT8_C(  22),  INT8_C(  28), -INT8_C(  71) },
        { -INT8_C(  24), -INT8_C(  67),  INT8_C(  97), -INT8_C(  95),  INT8_C(  28),  INT8_C(  28),  INT8_C( 118), -INT8_C( 127),
          -INT8_C(  85), -INT8_C(  57), -INT8_C( 117),  INT8_C(  84),  INT8_C(   1),  INT8_C(  22), -INT8_C(  20), -INT8_C( 105) },
        {  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
          -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1) } },
      { { -INT8_C( 121),  INT8_C(  28),  INT8_C(  91),  INT8_C(   5),  INT8_C( 107), -INT8_C( 115), -INT8_C( 116),  INT8_C( 120),
           INT8_C(  45),  INT8_C( 109), -INT8_C(  51),  INT8_C( 102), -INT8_C(  10),  INT8_C(  99), -INT8_C(  31),  INT8_C( 119) },
        {  INT8_C(  47), -INT8_C(  57),  INT8_C(  10),  INT8_C( 117),  INT8_C( 107),  INT8_C( 115),  INT8_C(  71),  INT8_C( 120),
           INT8_C(  71),  INT8_C( 108),  INT8_C( 108),  INT8_C(   3), -INT8_C(  10), -INT8_C( 113), -INT8_C(  11), -INT8_C( 108) },
        { -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
          -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1) } },
      { { -INT8_C(  48), -INT8_C( 101),  INT8_C( 125), -INT8_C(  17), -INT8_C(  52),  INT8_C(  58), -INT8_C(  79),  INT8_C( 100),
          -INT8_C(   3),  INT8_C(  42),  INT8_C(  78), -INT8_C(  86), -INT8_C(  35),  INT8_C(  76), -INT8_C(  89), -INT8_C(  58) },
        {  INT8_C( 112),  INT8_C(  87),  INT8_C( 125), -INT8_C(   3),  INT8_C(  12),  INT8_C(  64),  INT8_C(  93), -INT8_C(  74),
          -INT8_C(  84),  INT8_C( 109),  INT8_C(  78),  INT8_C(  87), -INT8_C(  35),  INT8_C(   6),  INT8_C(  67),  INT8_C(  64) },
        { -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
          -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1) } },
      { { -INT8_C(  57),  INT8_C( 110), -INT8_C(  72), -INT8_C( 118), -INT8_C( 106), -INT8_C(  95),  INT8_C(  44), -INT8_C(  44),
          -INT8_C(  79), -INT8_C(   2),  INT8_C(  49), -INT8_C(  53),  INT8_C(  51),  INT8_C(  67),  INT8_C( 119), -INT8_C( 120) },
        { -INT8_C(   8), -INT8_C( 115),  INT8_C(  11), -INT8_C(  73),  INT8_C(  87),  INT8_C(  61),  INT8_C(  22), -INT8_C(  44),
          -INT8_C(  83), -INT8_C( 105),  INT8_C( 114), -INT8_C(  53),  INT8_C(  51), -INT8_C( 109), -INT8_C(  38),  INT8_C(  67) },
        { -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
          -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_i8x16_ne(a, b);
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
      r = simde_wasm_i8x16_ne(a, b);

      simde_test_wasm_i8x16_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_i8x16_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_i8x16_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_i16x8_ne(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int16_t a[sizeof(simde_v128_t) / sizeof(int16_t)];
      int16_t b[sizeof(simde_v128_t) / sizeof(int16_t)];
      int16_t r[sizeof(simde_v128_t) / sizeof(int16_t)];
    } test_vec[8] = {
      { { -INT16_C( 21735),  INT16_C( 17652),  INT16_C( 12565),  INT16_C(   199), -INT16_C(  7345), -INT16_C(  4880), -INT16_C(  3180), -INT16_C( 23328) },
        {  INT16_C( 23802),  INT16_C( 17652), -INT16_C( 32523),  INT16_C(   199), -INT16_C(  7345), -INT16_C(  4880), -INT16_C( 25822), -INT16_C( 23328) },
        { -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0) } },
      { {  INT16_C( 28596), -INT16_C( 19266),  INT16_C( 16983), -INT16_C(  1019), -INT16_C( 10446), -INT16_C( 14068),  INT16_C(  9753),  INT16_C( 32146) },
        {  INT16_C( 28596), -INT16_C( 25733), -INT16_C( 24071), -INT16_C(  1948),  INT16_C( 20916), -INT16_C( 14068),  INT16_C( 22895),  INT16_C( 32344) },
        {  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1) } },
      { { -INT16_C( 25912),  INT16_C( 12383),  INT16_C( 32078), -INT16_C( 12318),  INT16_C(  4201), -INT16_C( 19275), -INT16_C( 24573),  INT16_C(  8721) },
        { -INT16_C( 24460),  INT16_C( 32349), -INT16_C( 25251),  INT16_C( 17785), -INT16_C( 21503), -INT16_C( 10805), -INT16_C( 11432),  INT16_C( 20652) },
        { -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1) } },
      { { -INT16_C( 16352),  INT16_C(  6854),  INT16_C(   622),  INT16_C( 11088), -INT16_C(  7773), -INT16_C( 28797), -INT16_C( 32618),  INT16_C( 30601) },
        {  INT16_C(  3563),  INT16_C( 18135),  INT16_C(   622),  INT16_C( 11088), -INT16_C(  7773), -INT16_C( 28797), -INT16_C( 32618), -INT16_C( 31672) },
        { -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1) } },
      { {  INT16_C( 18479),  INT16_C( 19758),  INT16_C(  3532),  INT16_C(  5243), -INT16_C(  8605),  INT16_C(   260),  INT16_C(  6148),  INT16_C(  9095) },
        {  INT16_C( 18479),  INT16_C( 10708),  INT16_C( 24675), -INT16_C(  6484),  INT16_C( 25453),  INT16_C( 21747),  INT16_C(  6148),  INT16_C(  9095) },
        {  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0) } },
      { {  INT16_C( 25903),  INT16_C( 17373),  INT16_C( 16432),  INT16_C( 23747), -INT16_C(  8113), -INT16_C( 13608), -INT16_C(  1588),  INT16_C( 13606) },
        { -INT16_C(  4649),  INT16_C( 17950),  INT16_C(  2132), -INT16_C( 25772), -INT16_C(  8113),  INT16_C(  5486),  INT16_C( 29572), -INT16_C( 19692) },
        { -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1) } },
      { {  INT16_C( 10693),  INT16_C( 24663), -INT16_C( 23092),  INT16_C(   418),  INT16_C( 30513), -INT16_C( 16653),  INT16_C(  2726), -INT16_C( 25090) },
        {  INT16_C(  5854), -INT16_C( 21081),  INT16_C( 12372),  INT16_C(  3055),  INT16_C(  5053), -INT16_C( 18531), -INT16_C(  1894), -INT16_C( 25090) },
        { -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0) } },
      { {  INT16_C( 22029),  INT16_C( 32577), -INT16_C( 20270), -INT16_C( 15206), -INT16_C(  5752), -INT16_C( 13277),  INT16_C( 18721),  INT16_C(  5862) },
        {  INT16_C( 22029),  INT16_C( 16133), -INT16_C(  4820), -INT16_C( 15206), -INT16_C(  8469), -INT16_C( 13277),  INT16_C( 11858), -INT16_C( 29171) },
        {  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_i16x8_ne(a, b);
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
      r = simde_wasm_i16x8_ne(a, b);

      simde_test_wasm_i16x8_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_i16x8_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_i16x8_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_i32x4_ne(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int32_t a[sizeof(simde_v128_t) / sizeof(int32_t)];
      int32_t b[sizeof(simde_v128_t) / sizeof(int32_t)];
      int32_t r[sizeof(simde_v128_t) / sizeof(int32_t)];
    } test_vec[8] = {
      { { -INT32_C(  1332386211),  INT32_C(   129852344),  INT32_C(  2052355777),  INT32_C(   133416079) },
        { -INT32_C(    58058350),  INT32_C(   129852344), -INT32_C(   921206091),  INT32_C(   886985248) },
        { -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1) } },
      { {  INT32_C(  1585275692), -INT32_C(   115268516),  INT32_C(    13544496), -INT32_C(   310396762) },
        { -INT32_C(   997574601),  INT32_C(  1973832054), -INT32_C(  1549521581), -INT32_C(   441076395) },
        { -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1) } },
      { { -INT32_C(  1880844134),  INT32_C(  2113226032), -INT32_C(   860286849),  INT32_C(   724428372) },
        { -INT32_C(  1368348694),  INT32_C(  1672321832), -INT32_C(  1261931383), -INT32_C(  1162556039) },
        { -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1) } },
      { {  INT32_C(   592329903), -INT32_C(  1196426489),  INT32_C(  1600123300), -INT32_C(   858740154) },
        {  INT32_C(   592329903),  INT32_C(    34784530),  INT32_C(  1578616410),  INT32_C(    70060094) },
        {  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1) } },
      { { -INT32_C(   624598342), -INT32_C(   856517143), -INT32_C(  1208632717),  INT32_C(  1045772150) },
        {  INT32_C(  1218879758),  INT32_C(  1158721420), -INT32_C(  1208632717), -INT32_C(   384484292) },
        { -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1) } },
      { { -INT32_C(  2116920827),  INT32_C(   595362284), -INT32_C(  1328972567),  INT32_C(  1785521670) },
        {  INT32_C(  1728511029), -INT32_C(   780746863), -INT32_C(  1839716726),  INT32_C(  1346708496) },
        { -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1) } },
      { {  INT32_C(  1401639204),  INT32_C(    21147288),  INT32_C(  1402315184), -INT32_C(   417059852) },
        { -INT32_C(  1198252965), -INT32_C(   804265981),  INT32_C(    43142059), -INT32_C(   417059852) },
        { -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0) } },
      { { -INT32_C(   756190095),  INT32_C(   328979245),  INT32_C(   520683345), -INT32_C(  1178272306) },
        { -INT32_C(   756190095), -INT32_C(   490991382),  INT32_C(   133685831), -INT32_C(  1178272306) },
        {  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_i32x4_ne(a, b);
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
      r = simde_wasm_i32x4_ne(a, b);

      simde_test_wasm_i32x4_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_i32x4_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_i32x4_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_i64x2_ne(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int64_t a[sizeof(simde_v128_t) / sizeof(int64_t)];
      int64_t b[sizeof(simde_v128_t) / sizeof(int64_t)];
      int64_t r[sizeof(simde_v128_t) / sizeof(int64_t)];
    } test_vec[8] = {
      { { -INT64_C( 1350094839477747171),  INT64_C( 7925583182050078455) },
        { -INT64_C( 2337679111426762169),  INT64_C( 8111312041999164104) },
        { -INT64_C(                   1), -INT64_C(                   1) } },
      { {  INT64_C( 5461114905027863141), -INT64_C(  443634293651531327) },
        {  INT64_C( 6688915848558570786), -INT64_C( 2093051465318155250) },
        { -INT64_C(                   1), -INT64_C(                   1) } },
      { { -INT64_C( 5085986335617666082), -INT64_C( 1488428445255380847) },
        { -INT64_C( 8952782485157104989), -INT64_C( 1488428445255380847) },
        { -INT64_C(                   1),  INT64_C(                   0) } },
      { {  INT64_C( 5170167725455297862), -INT64_C(  847619482028380689) },
        {  INT64_C( 6529534479080051004), -INT64_C( 4668290175005396338) },
        { -INT64_C(                   1), -INT64_C(                   1) } },
      { {  INT64_C( 2564674951809913974),  INT64_C( 2794281088365751006) },
        { -INT64_C( 5036793425468626870), -INT64_C( 1925892921978114420) },
        { -INT64_C(                   1), -INT64_C(                   1) } },
      { {  INT64_C( 2939833066600089031), -INT64_C( 6013955683902438180) },
        {  INT64_C( 2939833066600089031),  INT64_C( 1083447182079438939) },
        {  INT64_C(                   0), -INT64_C(                   1) } },
      { { -INT64_C( 3987705703364188387),  INT64_C( 4796844519760073713) },
        { -INT64_C( 3987705703364188387),  INT64_C( 8734034422227344683) },
        {  INT64_C(                   0), -INT64_C(                   1) } },
      { { -INT64_C( 3403010988225605065),  INT64_C( 6513680396060463408) },
        {  INT64_C( 6856869571806035003), -INT64_C( 2638795055631861296) },
        { -INT64_C(                   1), -INT64_C(                   1) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_i64x2_ne(a, b);
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
      r = simde_wasm_i64x2_ne(a, b);

      simde_test_wasm_i64x2_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_i64x2_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_i64x2_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_f32x4_ne(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      simde_float32 a[sizeof(simde_v128_t) / sizeof(simde_float32)];
      simde_float32 b[sizeof(simde_v128_t) / sizeof(simde_float32)];
      int32_t r[sizeof(simde_v128_t) / sizeof(simde_float32)];
    } test_vec[8] = {
      { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -838.97),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   249.46) },
        { SIMDE_FLOAT32_C(   260.38),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   249.46) },
        { -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0) } },
      { { SIMDE_FLOAT32_C(  -323.53), SIMDE_FLOAT32_C(  -181.07), SIMDE_FLOAT32_C(   762.06), SIMDE_FLOAT32_C(   435.85) },
        { SIMDE_FLOAT32_C(   359.88), SIMDE_FLOAT32_C(   469.16), SIMDE_FLOAT32_C(  -281.64), SIMDE_FLOAT32_C(   136.71) },
        { -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1) } },
      { { SIMDE_FLOAT32_C(   415.66), SIMDE_FLOAT32_C(   808.63), SIMDE_FLOAT32_C(  -254.13), SIMDE_FLOAT32_C(  -273.54) },
        { SIMDE_FLOAT32_C(   583.19), SIMDE_FLOAT32_C(  -708.41), SIMDE_FLOAT32_C(   583.07), SIMDE_FLOAT32_C(  -249.25) },
        { -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1) } },
      { { SIMDE_FLOAT32_C(  -607.27), SIMDE_FLOAT32_C(  -921.51), SIMDE_FLOAT32_C(  -345.30), SIMDE_FLOAT32_C(   802.53) },
        { SIMDE_FLOAT32_C(  -771.01), SIMDE_FLOAT32_C(   984.67), SIMDE_FLOAT32_C(  -354.73), SIMDE_FLOAT32_C(   414.55) },
        { -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1) } },
      { { SIMDE_FLOAT32_C(   962.54), SIMDE_FLOAT32_C(   267.58), SIMDE_FLOAT32_C(   360.88), SIMDE_FLOAT32_C(  -170.66) },
        { SIMDE_FLOAT32_C(   686.65), SIMDE_FLOAT32_C(   146.14), SIMDE_FLOAT32_C(   476.70), SIMDE_FLOAT32_C(  -499.23) },
        { -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1) } },
      { { SIMDE_FLOAT32_C(  -853.92), SIMDE_FLOAT32_C(  -904.44), SIMDE_FLOAT32_C(   319.15), SIMDE_FLOAT32_C(  -995.87) },
        { SIMDE_FLOAT32_C(   531.45), SIMDE_FLOAT32_C(  -340.89), SIMDE_FLOAT32_C(  -881.02), SIMDE_FLOAT32_C(    95.40) },
        { -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1) } },
      { { SIMDE_FLOAT32_C(   538.02), SIMDE_FLOAT32_C(  -597.98), SIMDE_FLOAT32_C(  -991.14), SIMDE_FLOAT32_C(  -618.72) },
        { SIMDE_FLOAT32_C(  -328.31), SIMDE_FLOAT32_C(    81.46), SIMDE_FLOAT32_C(  -801.91), SIMDE_FLOAT32_C(  -662.49) },
        { -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1) } },
      { { SIMDE_FLOAT32_C(  -476.19), SIMDE_FLOAT32_C(   721.77), SIMDE_FLOAT32_C(   430.56), SIMDE_FLOAT32_C(   779.36) },
        { SIMDE_FLOAT32_C(   774.56), SIMDE_FLOAT32_C(  -573.80), SIMDE_FLOAT32_C(  -702.29), SIMDE_FLOAT32_C(   627.19) },
        { -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_f32x4_ne(a, b);
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

      r = simde_wasm_f32x4_ne(a, b);

      simde_test_wasm_f32x4_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_f32x4_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_i32x4_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_f64x2_ne(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      simde_float64 a[sizeof(simde_v128_t) / sizeof(simde_float64)];
      simde_float64 b[sizeof(simde_v128_t) / sizeof(simde_float64)];
      int64_t r[sizeof(simde_v128_t) / sizeof(simde_float64)];
    } test_vec[8] = {
      { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -706.23) },
        { SIMDE_FLOAT64_C(   737.45),             SIMDE_MATH_NAN },
        { -INT64_C(                   1), -INT64_C(                   1) } },
      { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   920.30) },
        {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   920.30) },
        { -INT64_C(                   1),  INT64_C(                   0) } },
      { { SIMDE_FLOAT64_C(   505.63), SIMDE_FLOAT64_C(   547.66) },
        { SIMDE_FLOAT64_C(   791.76), SIMDE_FLOAT64_C(  -983.23) },
        { -INT64_C(                   1), -INT64_C(                   1) } },
      { { SIMDE_FLOAT64_C(   912.37), SIMDE_FLOAT64_C(  -777.60) },
        { SIMDE_FLOAT64_C(   932.73), SIMDE_FLOAT64_C(  -223.94) },
        { -INT64_C(                   1), -INT64_C(                   1) } },
      { { SIMDE_FLOAT64_C(  -863.48), SIMDE_FLOAT64_C(   402.55) },
        { SIMDE_FLOAT64_C(  -997.12), SIMDE_FLOAT64_C(  -378.98) },
        { -INT64_C(                   1), -INT64_C(                   1) } },
      { { SIMDE_FLOAT64_C(   922.92), SIMDE_FLOAT64_C(   332.53) },
        { SIMDE_FLOAT64_C(   384.67), SIMDE_FLOAT64_C(  -464.92) },
        { -INT64_C(                   1), -INT64_C(                   1) } },
      { { SIMDE_FLOAT64_C(   863.09), SIMDE_FLOAT64_C(  -464.16) },
        { SIMDE_FLOAT64_C(  -471.49), SIMDE_FLOAT64_C(  -365.52) },
        { -INT64_C(                   1), -INT64_C(                   1) } },
      { { SIMDE_FLOAT64_C(   879.13), SIMDE_FLOAT64_C(  -641.91) },
        { SIMDE_FLOAT64_C(  -480.02), SIMDE_FLOAT64_C(   151.79) },
        { -INT64_C(                   1), -INT64_C(                   1) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_f64x2_ne(a, b);
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

      r = simde_wasm_f64x2_ne(a, b);

      simde_test_wasm_f64x2_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_f64x2_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_i64x2_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i8x16_ne)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i16x8_ne)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i32x4_ne)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i64x2_ne)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_f32x4_ne)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_f64x2_ne)
SIMDE_TEST_FUNC_LIST_END

#include "test-simd128-footer.h"
