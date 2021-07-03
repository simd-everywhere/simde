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

#define SIMDE_TEST_WASM_SIMD128_INSN eq
#include "../../../simde/wasm/simd128.h"
#include "test-simd128.h"

static int
test_simde_wasm_i8x16_eq(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int8_t a[sizeof(simde_v128_t) / sizeof(int8_t)];
      int8_t b[sizeof(simde_v128_t) / sizeof(int8_t)];
      int8_t r[sizeof(simde_v128_t) / sizeof(int8_t)];
    } test_vec[8] = {
      { { -INT8_C(   6),  INT8_C(  47), -INT8_C(  11),  INT8_C(  98),  INT8_C(  78), -INT8_C( 123),  INT8_C(   4), -INT8_C(  48),
          -INT8_C(  58),  INT8_C( 109),  INT8_C(   5),  INT8_C(  38), -INT8_C( 119),  INT8_C( 102),  INT8_C(  16),  INT8_C(  89) },
        {  INT8_C(  35),  INT8_C(  97), -INT8_C( 108),  INT8_C(  92), -INT8_C(  84), -INT8_C(  76),  INT8_C(  49), -INT8_C(  39),
          -INT8_C(  99),  INT8_C(  20), -INT8_C(  41),  INT8_C( 119),  INT8_C(   8), -INT8_C(  10), -INT8_C(  80),  INT8_C(  70) },
        {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
           INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0) } },
      { {  INT8_C(  62), -INT8_C(  48),  INT8_C( 112),  INT8_C(   3),  INT8_C(  15), -INT8_C(  53),  INT8_C( 108),  INT8_C(   6),
          -INT8_C( 106),  INT8_C(  89),  INT8_C(   7),  INT8_C(  83),  INT8_C(  31), -INT8_C(  92),  INT8_C(  22),  INT8_C(  98) },
        {  INT8_C(  62), -INT8_C( 109),  INT8_C( 112), -INT8_C( 115),  INT8_C(  15), -INT8_C( 109),  INT8_C( 108), -INT8_C( 120),
          -INT8_C( 106), -INT8_C(  91), -INT8_C(  65), -INT8_C( 113), -INT8_C(  85),  INT8_C( 114), -INT8_C(  71),  INT8_C(  98) },
        { -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
          -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1) } },
      { {  INT8_C(   5), -INT8_C(  86), -INT8_C(  60),  INT8_C(   7), -INT8_C(  69),  INT8_C(  87), -INT8_C(  12),  INT8_C(  96),
          -INT8_C(  53), -INT8_C(  81),  INT8_C( 104), -INT8_C( 116), -INT8_C(  35),  INT8_C(  26),  INT8_C(  85), -INT8_C(   9) },
        {  INT8_C(   5), -INT8_C(  27),  INT8_C(  70),  INT8_C(   7),  INT8_C( 102),  INT8_C(  87),  INT8_C( 118),  INT8_C(  96),
           INT8_C(  54), -INT8_C(  58),  INT8_C( 104), -INT8_C( 116),  INT8_C( 105),  INT8_C(  26),  INT8_C(  85),  INT8_C( 125) },
        { -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
           INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0) } },
      { {  INT8_C( 122), -INT8_C(  92),  INT8_C(  25), -INT8_C(  42), -INT8_C(  86),  INT8_C(  13), -INT8_C( 107),  INT8_C(  64),
           INT8_C( 107), -INT8_C( 112),  INT8_C(  94),  INT8_C( 114),  INT8_C(  10), -INT8_C( 103), -INT8_C(  11),  INT8_C( 114) },
        { -INT8_C(  79), -INT8_C(  55),  INT8_C( 124), -INT8_C(  11), -INT8_C(  86),  INT8_C(  13),      INT8_MIN, -INT8_C(   5),
           INT8_C(  48),  INT8_C(  15),  INT8_C(  94),  INT8_C(  79), -INT8_C(  49),  INT8_C(  29), -INT8_C(  11), -INT8_C( 101) },
        {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
           INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0) } },
      { {  INT8_C(  60), -INT8_C(   8), -INT8_C(  75),  INT8_C(  32), -INT8_C(  26), -INT8_C(  91), -INT8_C( 118),  INT8_C(  18),
          -INT8_C(  27), -INT8_C(  48),  INT8_C(  44),  INT8_C(  58), -INT8_C(  23),  INT8_C(   1), -INT8_C(  33),  INT8_C( 114) },
        {  INT8_C(  60), -INT8_C(   8), -INT8_C( 107),  INT8_C(  32), -INT8_C(  26), -INT8_C(  31),  INT8_C(  90), -INT8_C(  29),
          -INT8_C(  73), -INT8_C(  48),  INT8_C(  44),  INT8_C(  58), -INT8_C(  10),  INT8_C(   1), -INT8_C(  33),  INT8_C(  93) },
        { -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
           INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0) } },
      { {  INT8_C(   1),  INT8_C(  95),  INT8_C(  22), -INT8_C(  51), -INT8_C( 124),  INT8_C( 119), -INT8_C( 121), -INT8_C(  98),
          -INT8_C(   8), -INT8_C( 113),  INT8_C( 112), -INT8_C(  41),  INT8_C( 109),  INT8_C(  78), -INT8_C(  88), -INT8_C(  72) },
        { -INT8_C(  53),  INT8_C(  95),  INT8_C(  31),  INT8_C(  60),  INT8_C(  37),  INT8_C( 119), -INT8_C( 121), -INT8_C(  86),
          -INT8_C(   8),  INT8_C( 110), -INT8_C(  75),  INT8_C(  36),  INT8_C( 109),  INT8_C(  89), -INT8_C(  17),  INT8_C(  46) },
        {  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
          -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0) } },
      { { -INT8_C(  95),  INT8_C(  46), -INT8_C(  18), -INT8_C( 110), -INT8_C(  49),  INT8_C(  34),  INT8_C(  28), -INT8_C(  26),
          -INT8_C(  69), -INT8_C( 121),  INT8_C(   5),  INT8_C( 126),  INT8_C( 112),  INT8_C(  51),  INT8_C( 113),  INT8_C(  67) },
        {  INT8_C(  67), -INT8_C(  48),  INT8_C(  36), -INT8_C(  59), -INT8_C( 121), -INT8_C(  39),  INT8_C(  69),  INT8_C(  99),
          -INT8_C( 118), -INT8_C(  39),  INT8_C( 111), -INT8_C(  24),  INT8_C( 112),  INT8_C( 116), -INT8_C(  93),  INT8_C(  67) },
        {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
           INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1) } },
      { {  INT8_C(   7), -INT8_C(  31),  INT8_C( 113), -INT8_C(  99), -INT8_C(  74),  INT8_C( 115), -INT8_C(  38), -INT8_C(  10),
           INT8_C(  86),      INT8_MIN, -INT8_C(  12),  INT8_C(  17), -INT8_C(  14), -INT8_C(  58),  INT8_C(  67),  INT8_C(  47) },
        {  INT8_C(  31), -INT8_C(  15), -INT8_C(  18), -INT8_C(  99),  INT8_C(  81),  INT8_C( 115),  INT8_C(  14),  INT8_C(  56),
           INT8_C(  94),      INT8_MIN, -INT8_C(  56),  INT8_C(  17), -INT8_C(  95),  INT8_C(  17),  INT8_C(  67), -INT8_C( 122) },
        {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
           INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_i8x16_eq(a, b);
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
      r = simde_wasm_i8x16_eq(a, b);

      simde_test_wasm_i8x16_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_i8x16_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_i8x16_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_i16x8_eq(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int16_t a[sizeof(simde_v128_t) / sizeof(int16_t)];
      int16_t b[sizeof(simde_v128_t) / sizeof(int16_t)];
      int16_t r[sizeof(simde_v128_t) / sizeof(int16_t)];
    } test_vec[8] = {
      { {  INT16_C( 25227),  INT16_C(  4185), -INT16_C( 15684), -INT16_C( 27802), -INT16_C( 29611), -INT16_C( 29142), -INT16_C( 32050), -INT16_C( 32679) },
        {  INT16_C( 17074),  INT16_C(  3209), -INT16_C( 16843),  INT16_C( 11313),  INT16_C( 26395),  INT16_C( 26497),  INT16_C( 23360), -INT16_C( 32679) },
        {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1) } },
      { { -INT16_C(  2214),  INT16_C( 14214),  INT16_C( 26606), -INT16_C( 26033), -INT16_C( 12730), -INT16_C( 12981),  INT16_C( 13071), -INT16_C( 13485) },
        {  INT16_C( 26294),  INT16_C( 13737), -INT16_C( 12374), -INT16_C( 20063), -INT16_C( 13842), -INT16_C(    85), -INT16_C( 20566), -INT16_C( 10942) },
        {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
      { { -INT16_C( 29230),  INT16_C( 15785),  INT16_C( 14580),  INT16_C( 10427), -INT16_C( 32180), -INT16_C( 14431), -INT16_C( 24300), -INT16_C( 18457) },
        { -INT16_C( 27843),  INT16_C( 15785),  INT16_C( 14580),  INT16_C(  3284), -INT16_C( 32180), -INT16_C(    57),  INT16_C(  4295),  INT16_C(  4591) },
        {  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
      { { -INT16_C(  8024),  INT16_C(  9600),  INT16_C( 25076), -INT16_C( 29804), -INT16_C( 30625),  INT16_C( 20459), -INT16_C( 13889), -INT16_C(  9383) },
        { -INT16_C(  8024),  INT16_C(  2098), -INT16_C(  6922), -INT16_C( 22699),  INT16_C( 26439),  INT16_C( 20459),  INT16_C( 29636), -INT16_C( 22120) },
        { -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0) } },
      { {  INT16_C( 32457),  INT16_C( 20015), -INT16_C( 27247),  INT16_C(  8294), -INT16_C( 23132), -INT16_C( 29379), -INT16_C( 22351), -INT16_C( 22089) },
        {  INT16_C( 32457),  INT16_C( 23168), -INT16_C( 27247), -INT16_C( 10923),  INT16_C(  5117),  INT16_C( 23536), -INT16_C( 22351),  INT16_C(  6556) },
        { -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0) } },
      { { -INT16_C(  7018),  INT16_C( 26367),  INT16_C( 32151), -INT16_C( 22632),  INT16_C(  9881), -INT16_C( 25507),  INT16_C(  2895),  INT16_C( 15819) },
        { -INT16_C( 18713),  INT16_C( 26367),  INT16_C(  7861), -INT16_C( 26672),  INT16_C(  9881), -INT16_C( 14619),  INT16_C( 23647),  INT16_C( 15819) },
        {  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1) } },
      { {  INT16_C( 28452), -INT16_C( 10019),  INT16_C( 17369), -INT16_C( 17301),  INT16_C( 23250),  INT16_C(  6416), -INT16_C(  1134), -INT16_C( 27196) },
        { -INT16_C( 25067),  INT16_C( 25801),  INT16_C( 17369), -INT16_C( 17301),  INT16_C( 25633),  INT16_C(  6416),  INT16_C(   947), -INT16_C( 27196) },
        {  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1) } },
      { {  INT16_C(   997),  INT16_C( 29297),  INT16_C( 20322), -INT16_C( 16615),  INT16_C(  9332), -INT16_C( 27099),  INT16_C(  8405), -INT16_C(  3130) },
        {  INT16_C(   997), -INT16_C( 13359),  INT16_C( 20322),  INT16_C( 14549), -INT16_C( 22137),  INT16_C(  8404), -INT16_C( 18753), -INT16_C( 15220) },
        { -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_i16x8_eq(a, b);
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
      r = simde_wasm_i16x8_eq(a, b);

      simde_test_wasm_i16x8_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_i16x8_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_i16x8_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_i32x4_eq(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int32_t a[sizeof(simde_v128_t) / sizeof(int32_t)];
      int32_t b[sizeof(simde_v128_t) / sizeof(int32_t)];
      int32_t r[sizeof(simde_v128_t) / sizeof(int32_t)];
    } test_vec[8] = {
      { { -INT32_C(  1340985785),  INT32_C(  1505566635), -INT32_C(   615524867), -INT32_C(   638285045) },
        { -INT32_C(   437450106),  INT32_C(  1059138205), -INT32_C(  1249394512),  INT32_C(   965228899) },
        {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
      { {  INT32_C(  1384823564),  INT32_C(    21652354), -INT32_C(  1590422314), -INT32_C(  1602992058) },
        {  INT32_C(   619903821),  INT32_C(    21652354), -INT32_C(   566244807),  INT32_C(   694241571) },
        {  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0) } },
      { { -INT32_C(  1492573048), -INT32_C(   353889600),  INT32_C(  1357306077), -INT32_C(   749408967) },
        {  INT32_C(  1698110742), -INT32_C(  2059874564),  INT32_C(  1251746551), -INT32_C(   897604990) },
        {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
      { { -INT32_C(   779125982), -INT32_C(   130405620), -INT32_C(   964834621), -INT32_C(   453089962) },
        { -INT32_C(   779125982), -INT32_C(   501223960), -INT32_C(   964834621), -INT32_C(  2070677027) },
        { -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0) } },
      { {  INT32_C(   518757708), -INT32_C(  2051455742),  INT32_C(   745372918), -INT32_C(   509229560) },
        { -INT32_C(  2000901430),  INT32_C(   233884283),  INT32_C(  1727198724), -INT32_C(   509229560) },
        {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1) } },
      { {  INT32_C(   571823357), -INT32_C(  1810682425),  INT32_C(    16781594),  INT32_C(   916077063) },
        {  INT32_C(   571823357), -INT32_C(   284714445),  INT32_C(    16781594),  INT32_C(  1633020996) },
        { -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0) } },
      { {  INT32_C(   400643239),  INT32_C(   672037471), -INT32_C(  1846080145), -INT32_C(  2047375518) },
        { -INT32_C(   898536688),  INT32_C(  1532900411), -INT32_C(  1846080145),  INT32_C(   621027288) },
        {  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0) } },
      { {  INT32_C(  2049003617), -INT32_C(  1368764288),  INT32_C(   816228920),  INT32_C(  1872152637) },
        { -INT32_C(  1149192688), -INT32_C(  1881288413), -INT32_C(  2132706423),  INT32_C(  1853100625) },
        {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_i32x4_eq(a, b);
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
      r = simde_wasm_i32x4_eq(a, b);

      simde_test_wasm_i32x4_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_i32x4_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_i32x4_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_i64x2_eq(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int64_t a[sizeof(simde_v128_t) / sizeof(int64_t)];
      int64_t b[sizeof(simde_v128_t) / sizeof(int64_t)];
      int64_t r[sizeof(simde_v128_t) / sizeof(int64_t)];
    } test_vec[8] = {
      { { -INT64_C( 1350094839477747171),  INT64_C( 7925583182050078455) },
        { -INT64_C( 2337679111426762169),  INT64_C( 8111312041999164104) },
        {  INT64_C(                   0),  INT64_C(                   0) } },
      { {  INT64_C( 5461114905027863141), -INT64_C(  443634293651531327) },
        {  INT64_C( 6688915848558570786), -INT64_C( 2093051465318155250) },
        {  INT64_C(                   0),  INT64_C(                   0) } },
      { { -INT64_C( 5085986335617666082), -INT64_C( 1488428445255380847) },
        { -INT64_C( 8952782485157104989), -INT64_C( 1488428445255380847) },
        {  INT64_C(                   0), -INT64_C(                   1) } },
      { {  INT64_C( 5170167725455297862), -INT64_C(  847619482028380689) },
        {  INT64_C( 6529534479080051004), -INT64_C( 4668290175005396338) },
        {  INT64_C(                   0),  INT64_C(                   0) } },
      { {  INT64_C( 2564674951809913974),  INT64_C( 2794281088365751006) },
        { -INT64_C( 5036793425468626870), -INT64_C( 1925892921978114420) },
        {  INT64_C(                   0),  INT64_C(                   0) } },
      { {  INT64_C( 2939833066600089031), -INT64_C( 6013955683902438180) },
        {  INT64_C( 2939833066600089031),  INT64_C( 1083447182079438939) },
        { -INT64_C(                   1),  INT64_C(                   0) } },
      { { -INT64_C( 3987705703364188387),  INT64_C( 4796844519760073713) },
        { -INT64_C( 3987705703364188387),  INT64_C( 8734034422227344683) },
        { -INT64_C(                   1),  INT64_C(                   0) } },
      { { -INT64_C( 3403010988225605065),  INT64_C( 6513680396060463408) },
        {  INT64_C( 6856869571806035003), -INT64_C( 2638795055631861296) },
        {  INT64_C(                   0),  INT64_C(                   0) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_i64x2_eq(a, b);
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
      r = simde_wasm_i64x2_eq(a, b);

      simde_test_wasm_i64x2_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_i64x2_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_i64x2_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_f32x4_eq(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      simde_float32 a[sizeof(simde_v128_t) / sizeof(simde_float32)];
      simde_float32 b[sizeof(simde_v128_t) / sizeof(simde_float32)];
      int32_t r[sizeof(simde_v128_t) / sizeof(simde_float32)];
    } test_vec[8] = {
      { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   418.88),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   867.96) },
        { SIMDE_FLOAT32_C(  -956.57),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   867.96) },
        {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1) } },
      { { SIMDE_FLOAT32_C(   869.67), SIMDE_FLOAT32_C(   399.06), SIMDE_FLOAT32_C(  -931.64), SIMDE_FLOAT32_C(  -120.21) },
        { SIMDE_FLOAT32_C(  -810.87), SIMDE_FLOAT32_C(   838.24), SIMDE_FLOAT32_C(  -242.09), SIMDE_FLOAT32_C(  -761.58) },
        {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
      { { SIMDE_FLOAT32_C(  -606.46), SIMDE_FLOAT32_C(  -158.05), SIMDE_FLOAT32_C(  -497.48), SIMDE_FLOAT32_C(  -977.23) },
        { SIMDE_FLOAT32_C(   130.22), SIMDE_FLOAT32_C(   581.61), SIMDE_FLOAT32_C(  -304.33), SIMDE_FLOAT32_C(  -416.06) },
        {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
      { { SIMDE_FLOAT32_C(   688.10), SIMDE_FLOAT32_C(  -516.70), SIMDE_FLOAT32_C(   -95.67), SIMDE_FLOAT32_C(  -200.92) },
        { SIMDE_FLOAT32_C(   -67.30), SIMDE_FLOAT32_C(  -903.95), SIMDE_FLOAT32_C(  -534.29), SIMDE_FLOAT32_C(   573.74) },
        {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
      { { SIMDE_FLOAT32_C(  -223.09), SIMDE_FLOAT32_C(  -872.36), SIMDE_FLOAT32_C(   735.73), SIMDE_FLOAT32_C(   895.46) },
        { SIMDE_FLOAT32_C(  -765.76), SIMDE_FLOAT32_C(   -38.29), SIMDE_FLOAT32_C(  -224.53), SIMDE_FLOAT32_C(   612.03) },
        {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
      { { SIMDE_FLOAT32_C(   381.75), SIMDE_FLOAT32_C(  -802.22), SIMDE_FLOAT32_C(   650.04), SIMDE_FLOAT32_C(   -68.77) },
        { SIMDE_FLOAT32_C(  -946.44), SIMDE_FLOAT32_C(   -97.29), SIMDE_FLOAT32_C(   370.93), SIMDE_FLOAT32_C(  -988.37) },
        {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
      { { SIMDE_FLOAT32_C(  -318.88), SIMDE_FLOAT32_C(   592.64), SIMDE_FLOAT32_C(   264.87), SIMDE_FLOAT32_C(  -456.41) },
        { SIMDE_FLOAT32_C(   586.41), SIMDE_FLOAT32_C(  -373.99), SIMDE_FLOAT32_C(  -944.74), SIMDE_FLOAT32_C(   -84.39) },
        {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
      { { SIMDE_FLOAT32_C(   980.33), SIMDE_FLOAT32_C(   125.98), SIMDE_FLOAT32_C(   694.73), SIMDE_FLOAT32_C(   773.01) },
        { SIMDE_FLOAT32_C(   396.03), SIMDE_FLOAT32_C(   603.69), SIMDE_FLOAT32_C(   957.60), SIMDE_FLOAT32_C(  -932.44) },
        {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_f32x4_eq(a, b);
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

      r = simde_wasm_f32x4_eq(a, b);

      simde_test_wasm_f32x4_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_f32x4_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_i32x4_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_f64x2_eq(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      simde_float64 a[sizeof(simde_v128_t) / sizeof(simde_float64)];
      simde_float64 b[sizeof(simde_v128_t) / sizeof(simde_float64)];
      int64_t r[sizeof(simde_v128_t) / sizeof(simde_float64)];
    } test_vec[8] = {
      { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -290.41) },
        { SIMDE_FLOAT64_C(  -326.23),             SIMDE_MATH_NAN },
        {  INT64_C(                   0),  INT64_C(                   0) } },
      { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   157.77) },
        {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   157.77) },
        {  INT64_C(                   0), -INT64_C(                   1) } },
      { { SIMDE_FLOAT64_C(  -593.11), SIMDE_FLOAT64_C(  -532.78) },
        { SIMDE_FLOAT64_C(  -237.73), SIMDE_FLOAT64_C(  -504.96) },
        {  INT64_C(                   0),  INT64_C(                   0) } },
      { { SIMDE_FLOAT64_C(    95.82), SIMDE_FLOAT64_C(  -138.06) },
        { SIMDE_FLOAT64_C(    75.91), SIMDE_FLOAT64_C(   206.24) },
        {  INT64_C(                   0),  INT64_C(                   0) } },
      { { SIMDE_FLOAT64_C(   718.32), SIMDE_FLOAT64_C(   886.64) },
        { SIMDE_FLOAT64_C(   498.68), SIMDE_FLOAT64_C(   549.19) },
        {  INT64_C(                   0),  INT64_C(                   0) } },
      { { SIMDE_FLOAT64_C(  -315.07), SIMDE_FLOAT64_C(   650.18) },
        { SIMDE_FLOAT64_C(  -102.30), SIMDE_FLOAT64_C(  -446.08) },
        {  INT64_C(                   0),  INT64_C(                   0) } },
      { { SIMDE_FLOAT64_C(   580.05), SIMDE_FLOAT64_C(  -413.60) },
        { SIMDE_FLOAT64_C(  -131.89), SIMDE_FLOAT64_C(    38.38) },
        {  INT64_C(                   0),  INT64_C(                   0) } },
      { { SIMDE_FLOAT64_C(   505.66), SIMDE_FLOAT64_C(   -11.38) },
        { SIMDE_FLOAT64_C(   280.80), SIMDE_FLOAT64_C(   859.45) },
        {  INT64_C(                   0),  INT64_C(                   0) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_f64x2_eq(a, b);
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

      r = simde_wasm_f64x2_eq(a, b);

      simde_test_wasm_f64x2_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_f64x2_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_i64x2_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i8x16_eq)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i16x8_eq)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i32x4_eq)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i64x2_eq)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_f32x4_eq)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_f64x2_eq)
SIMDE_TEST_FUNC_LIST_END

#include "test-simd128-footer.h"
