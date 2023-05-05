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

#define SIMDE_TEST_WASM_SIMD128_INSN abs
#include "../../../simde/wasm/simd128.h"
#include "test-simd128.h"

static int
test_simde_wasm_i8x16_abs(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int8_t a[sizeof(simde_v128_t) / sizeof(int8_t)];
      int8_t r[sizeof(simde_v128_t) / sizeof(int8_t)];
    } test_vec[8] = {
      { {      INT8_MIN,      INT8_MAX,  INT8_C(  95), -INT8_C(  10),  INT8_C(  20),  INT8_C( 125), -INT8_C( 112), -INT8_C( 105),
          -INT8_C(  18), -INT8_C(  37),  INT8_C(  84), -INT8_C(  88),  INT8_C(  23),  INT8_C(  27), -INT8_C(  53),  INT8_C(   0) },
        {      INT8_MIN,      INT8_MAX,  INT8_C(  95),  INT8_C(  10),  INT8_C(  20),  INT8_C( 125),  INT8_C( 112),  INT8_C( 105),
           INT8_C(  18),  INT8_C(  37),  INT8_C(  84),  INT8_C(  88),  INT8_C(  23),  INT8_C(  27),  INT8_C(  53),  INT8_C(   0) } },
      { {  INT8_C( 120), -INT8_C(  64),  INT8_C( 115),  INT8_C(  38), -INT8_C(  36), -INT8_C(  90),  INT8_C( 115), -INT8_C(  54),
          -INT8_C(  15), -INT8_C( 126), -INT8_C(  51), -INT8_C( 117), -INT8_C(  96),  INT8_C(   5), -INT8_C(  57), -INT8_C(  51) },
        {  INT8_C( 120),  INT8_C(  64),  INT8_C( 115),  INT8_C(  38),  INT8_C(  36),  INT8_C(  90),  INT8_C( 115),  INT8_C(  54),
           INT8_C(  15),  INT8_C( 126),  INT8_C(  51),  INT8_C( 117),  INT8_C(  96),  INT8_C(   5),  INT8_C(  57),  INT8_C(  51) } },
      { { -INT8_C(  82), -INT8_C(  69), -INT8_C(  16),  INT8_C(  67),  INT8_C(  49),  INT8_C(  26), -INT8_C(  32),  INT8_C(  62),
           INT8_C(  56), -INT8_C( 125),  INT8_C(  30), -INT8_C(  84),  INT8_C(  71),  INT8_C(  40),  INT8_C(  65), -INT8_C(  53) },
        {  INT8_C(  82),  INT8_C(  69),  INT8_C(  16),  INT8_C(  67),  INT8_C(  49),  INT8_C(  26),  INT8_C(  32),  INT8_C(  62),
           INT8_C(  56),  INT8_C( 125),  INT8_C(  30),  INT8_C(  84),  INT8_C(  71),  INT8_C(  40),  INT8_C(  65),  INT8_C(  53) } },
      { {  INT8_C(  44), -INT8_C(  69),  INT8_C(  32), -INT8_C(  48),  INT8_C(   4),  INT8_C(  14),  INT8_C(  12),  INT8_C(  17),
          -INT8_C(  20),  INT8_C(  13), -INT8_C(  43),  INT8_C(  92), -INT8_C( 102),  INT8_C(  95),  INT8_C( 111),  INT8_C(  54) },
        {  INT8_C(  44),  INT8_C(  69),  INT8_C(  32),  INT8_C(  48),  INT8_C(   4),  INT8_C(  14),  INT8_C(  12),  INT8_C(  17),
           INT8_C(  20),  INT8_C(  13),  INT8_C(  43),  INT8_C(  92),  INT8_C( 102),  INT8_C(  95),  INT8_C( 111),  INT8_C(  54) } },
      { { -INT8_C(   1), -INT8_C(  57),  INT8_C( 103),  INT8_C(  44), -INT8_C(  34), -INT8_C(  72), -INT8_C(  77), -INT8_C(  81),
          -INT8_C(  47),  INT8_C(  42),  INT8_C(  17),  INT8_C(  66),  INT8_C( 123),  INT8_C(  25),  INT8_C(  43), -INT8_C(  64) },
        {  INT8_C(   1),  INT8_C(  57),  INT8_C( 103),  INT8_C(  44),  INT8_C(  34),  INT8_C(  72),  INT8_C(  77),  INT8_C(  81),
           INT8_C(  47),  INT8_C(  42),  INT8_C(  17),  INT8_C(  66),  INT8_C( 123),  INT8_C(  25),  INT8_C(  43),  INT8_C(  64) } },
      { { -INT8_C( 120),  INT8_C(  35),  INT8_C(  23),  INT8_C(  77),  INT8_C(  74),  INT8_C(  97),  INT8_C(  46), -INT8_C( 126),
           INT8_C(  87), -INT8_C(  67), -INT8_C( 108),  INT8_C(  83),  INT8_C(  82),  INT8_C( 110),  INT8_C(  41), -INT8_C(  76) },
        {  INT8_C( 120),  INT8_C(  35),  INT8_C(  23),  INT8_C(  77),  INT8_C(  74),  INT8_C(  97),  INT8_C(  46),  INT8_C( 126),
           INT8_C(  87),  INT8_C(  67),  INT8_C( 108),  INT8_C(  83),  INT8_C(  82),  INT8_C( 110),  INT8_C(  41),  INT8_C(  76) } },
      { { -INT8_C(  62), -INT8_C(   5), -INT8_C( 110),  INT8_C(  94), -INT8_C(  87), -INT8_C(  50), -INT8_C(  91), -INT8_C(  23),
          -INT8_C(   2),  INT8_C(  59), -INT8_C(  60),  INT8_C( 126),  INT8_C( 112),  INT8_C(  58),  INT8_C(  12),  INT8_C(  27) },
        {  INT8_C(  62),  INT8_C(   5),  INT8_C( 110),  INT8_C(  94),  INT8_C(  87),  INT8_C(  50),  INT8_C(  91),  INT8_C(  23),
           INT8_C(   2),  INT8_C(  59),  INT8_C(  60),  INT8_C( 126),  INT8_C( 112),  INT8_C(  58),  INT8_C(  12),  INT8_C(  27) } },
      { { -INT8_C( 100), -INT8_C( 123),  INT8_C(  23), -INT8_C(  54), -INT8_C(   3),  INT8_C( 126), -INT8_C(  32), -INT8_C(  16),
           INT8_C( 123), -INT8_C(  96),  INT8_C(  52),  INT8_C( 108),  INT8_C(  21), -INT8_C(  36), -INT8_C(  45),  INT8_C( 114) },
        {  INT8_C( 100),  INT8_C( 123),  INT8_C(  23),  INT8_C(  54),  INT8_C(   3),  INT8_C( 126),  INT8_C(  32),  INT8_C(  16),
           INT8_C( 123),  INT8_C(  96),  INT8_C(  52),  INT8_C( 108),  INT8_C(  21),  INT8_C(  36),  INT8_C(  45),  INT8_C( 114) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t r = simde_wasm_i8x16_abs(a);
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
      r = simde_wasm_i8x16_abs(a);

      simde_test_wasm_i8x16_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_i8x16_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_i16x8_abs(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int16_t a[sizeof(simde_v128_t) / sizeof(int16_t)];
      int16_t r[sizeof(simde_v128_t) / sizeof(int16_t)];
    } test_vec[8] = {
      { {       INT16_MIN,       INT16_MAX,  INT16_C( 25808),  INT16_C(  4918), -INT16_C(   933),  INT16_C(  6060), -INT16_C( 18885),  INT16_C( 15452) },
        {       INT16_MIN,       INT16_MAX,  INT16_C( 25808),  INT16_C(  4918),  INT16_C(   933),  INT16_C(  6060),  INT16_C( 18885),  INT16_C( 15452) } },
      { {  INT16_C( 10640), -INT16_C(  2302),  INT16_C(  9340), -INT16_C( 19712),  INT16_C( 25950), -INT16_C( 22387),  INT16_C( 20743),  INT16_C( 21687) },
        {  INT16_C( 10640),  INT16_C(  2302),  INT16_C(  9340),  INT16_C( 19712),  INT16_C( 25950),  INT16_C( 22387),  INT16_C( 20743),  INT16_C( 21687) } },
      { { -INT16_C( 20837),  INT16_C( 27627),  INT16_C(  8722),  INT16_C( 28030),  INT16_C( 10782),  INT16_C( 22917), -INT16_C(  7712),  INT16_C( 29078) },
        {  INT16_C( 20837),  INT16_C( 27627),  INT16_C(  8722),  INT16_C( 28030),  INT16_C( 10782),  INT16_C( 22917),  INT16_C(  7712),  INT16_C( 29078) } },
      { { -INT16_C( 26614), -INT16_C( 30872),  INT16_C( 26813),  INT16_C(  6970), -INT16_C( 14387), -INT16_C( 11069),  INT16_C( 31257), -INT16_C( 19416) },
        {  INT16_C( 26614),  INT16_C( 30872),  INT16_C( 26813),  INT16_C(  6970),  INT16_C( 14387),  INT16_C( 11069),  INT16_C( 31257),  INT16_C( 19416) } },
      { {  INT16_C(  5161),  INT16_C( 15135), -INT16_C( 25290),  INT16_C( 21673),  INT16_C( 11975), -INT16_C( 22355),  INT16_C( 17167),  INT16_C(  6681) },
        {  INT16_C(  5161),  INT16_C( 15135),  INT16_C( 25290),  INT16_C( 21673),  INT16_C( 11975),  INT16_C( 22355),  INT16_C( 17167),  INT16_C(  6681) } },
      { { -INT16_C( 32292), -INT16_C( 26207), -INT16_C(  9239), -INT16_C( 18764),  INT16_C( 30627), -INT16_C( 17269), -INT16_C( 19470),  INT16_C(  7024) },
        {  INT16_C( 32292),  INT16_C( 26207),  INT16_C(  9239),  INT16_C( 18764),  INT16_C( 30627),  INT16_C( 17269),  INT16_C( 19470),  INT16_C(  7024) } },
      { { -INT16_C( 28729), -INT16_C(   682), -INT16_C(   212), -INT16_C(  3247), -INT16_C(   211),  INT16_C( 15771), -INT16_C( 19390),  INT16_C(  7767) },
        {  INT16_C( 28729),  INT16_C(   682),  INT16_C(   212),  INT16_C(  3247),  INT16_C(   211),  INT16_C( 15771),  INT16_C( 19390),  INT16_C(  7767) } },
      { { -INT16_C(  1995),  INT16_C(  7863),  INT16_C( 27603),  INT16_C( 30421),  INT16_C( 24803), -INT16_C( 10958), -INT16_C( 24045), -INT16_C(  9232) },
        {  INT16_C(  1995),  INT16_C(  7863),  INT16_C( 27603),  INT16_C( 30421),  INT16_C( 24803),  INT16_C( 10958),  INT16_C( 24045),  INT16_C(  9232) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t r = simde_wasm_i16x8_abs(a);
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
      r = simde_wasm_i16x8_abs(a);

      simde_test_wasm_i16x8_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_i16x8_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_i32x4_abs(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int32_t a[sizeof(simde_v128_t) / sizeof(int32_t)];
      int32_t r[sizeof(simde_v128_t) / sizeof(int32_t)];
    } test_vec[8] = {
      { {            INT32_MIN,            INT32_MAX,  INT32_C(  1806756905), -INT32_C(   695597151) },
        {            INT32_MIN,            INT32_MAX,  INT32_C(  1806756905),  INT32_C(   695597151) } },
      { { -INT32_C(   738901505), -INT32_C(  1874212179),  INT32_C(  1030061098),  INT32_C(  1343771934) },
        {  INT32_C(   738901505),  INT32_C(  1874212179),  INT32_C(  1030061098),  INT32_C(  1343771934) } },
      { { -INT32_C(   508694117),  INT32_C(  1146486299), -INT32_C(  1934686741),  INT32_C(   207763725) },
        {  INT32_C(   508694117),  INT32_C(  1146486299),  INT32_C(  1934686741),  INT32_C(   207763725) } },
      { {  INT32_C(   685725563),  INT32_C(  1270360353), -INT32_C(  1014424155),  INT32_C(   219390322) },
        {  INT32_C(   685725563),  INT32_C(  1270360353),  INT32_C(  1014424155),  INT32_C(   219390322) } },
      { { -INT32_C(  1376796270), -INT32_C(  1427028801),  INT32_C(  1446420809),  INT32_C(  1432590810) },
        {  INT32_C(  1376796270),  INT32_C(  1427028801),  INT32_C(  1446420809),  INT32_C(  1432590810) } },
      { {  INT32_C(   310199024),  INT32_C(   274543979), -INT32_C(   992680366),  INT32_C(   450029448) },
        {  INT32_C(   310199024),  INT32_C(   274543979),  INT32_C(   992680366),  INT32_C(   450029448) } },
      { {  INT32_C(  1757987240),  INT32_C(  1309849861),  INT32_C(   900024666), -INT32_C(   762705694) },
        {  INT32_C(  1757987240),  INT32_C(  1309849861),  INT32_C(   900024666),  INT32_C(   762705694) } },
      { { -INT32_C(  1226569654), -INT32_C(  1866055107), -INT32_C(  1336632792),  INT32_C(   717956738) },
        {  INT32_C(  1226569654),  INT32_C(  1866055107),  INT32_C(  1336632792),  INT32_C(   717956738) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t r = simde_wasm_i32x4_abs(a);
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
      r = simde_wasm_i32x4_abs(a);

      simde_test_wasm_i32x4_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_i32x4_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_i64x2_abs(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int64_t a[sizeof(simde_v128_t) / sizeof(int64_t)];
      int64_t r[sizeof(simde_v128_t) / sizeof(int64_t)];
    } test_vec[8] = {
      { {                      INT64_MIN,                      INT64_MAX },
        {                      INT64_MIN,                      INT64_MAX } },
      { { -INT64_C( 3990820588408151571), -INT64_C( 7145361428871900101) },
        {  INT64_C( 3990820588408151571),  INT64_C( 7145361428871900101) } },
      { { -INT64_C(     728576228772307),  INT64_C(  953648244202394898) },
        {  INT64_C(     728576228772307),  INT64_C(  953648244202394898) } },
      { { -INT64_C( 7171091141891152706),  INT64_C( 3692262152343940233) },
        {  INT64_C( 7171091141891152706),  INT64_C( 3692262152343940233) } },
      { {  INT64_C( 6268464755317943399),  INT64_C( 2598184867634338767) },
        {  INT64_C( 6268464755317943399),  INT64_C( 2598184867634338767) } },
      { { -INT64_C( 6291124728732486678), -INT64_C( 6254797187307178632) },
        {  INT64_C( 6291124728732486678),  INT64_C( 6254797187307178632) } },
      { {  INT64_C( 1549847767805873847), -INT64_C( 8808553472379222684) },
        {  INT64_C( 1549847767805873847),  INT64_C( 8808553472379222684) } },
      { { -INT64_C( 3669388762740366092), -INT64_C( 3683620901516788018) },
        {  INT64_C( 3669388762740366092),  INT64_C( 3683620901516788018) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t r = simde_wasm_i64x2_abs(a);
      simde_test_wasm_i64x2_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
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
      r = simde_wasm_i64x2_abs(a);

      simde_test_wasm_i64x2_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_i64x2_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_f32x4_abs(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      simde_float32 a[sizeof(simde_v128_t) / sizeof(simde_float32)];
      simde_float32 r[sizeof(simde_v128_t) / sizeof(simde_float32)];
    } test_vec[] = {
      #if !defined(SIMDE_FAST_MATH)
      { { SIMDE_FLOAT32_C(    -0.00), SIMDE_FLOAT32_C(    -0.00), SIMDE_FLOAT32_C(    -0.00), SIMDE_FLOAT32_C(    -0.00) },
        { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
      #endif
      { { SIMDE_FLOAT32_C(   394.19), SIMDE_FLOAT32_C(  -636.32), SIMDE_FLOAT32_C(  -182.62), SIMDE_FLOAT32_C(   658.49) },
        { SIMDE_FLOAT32_C(   394.19), SIMDE_FLOAT32_C(   636.32), SIMDE_FLOAT32_C(   182.62), SIMDE_FLOAT32_C(   658.49) } },
      { { SIMDE_FLOAT32_C(   649.33), SIMDE_FLOAT32_C(   338.36), SIMDE_FLOAT32_C(    58.28), SIMDE_FLOAT32_C(    54.16) },
        { SIMDE_FLOAT32_C(   649.33), SIMDE_FLOAT32_C(   338.36), SIMDE_FLOAT32_C(    58.28), SIMDE_FLOAT32_C(    54.16) } },
      { { SIMDE_FLOAT32_C(   522.97), SIMDE_FLOAT32_C(   -67.10), SIMDE_FLOAT32_C(  -874.32), SIMDE_FLOAT32_C(   -72.19) },
        { SIMDE_FLOAT32_C(   522.97), SIMDE_FLOAT32_C(    67.10), SIMDE_FLOAT32_C(   874.32), SIMDE_FLOAT32_C(    72.19) } },
      { { SIMDE_FLOAT32_C(  -463.03), SIMDE_FLOAT32_C(   139.81), SIMDE_FLOAT32_C(   113.33), SIMDE_FLOAT32_C(  -962.09) },
        { SIMDE_FLOAT32_C(   463.03), SIMDE_FLOAT32_C(   139.81), SIMDE_FLOAT32_C(   113.33), SIMDE_FLOAT32_C(   962.09) } },
      { { SIMDE_FLOAT32_C(    37.82), SIMDE_FLOAT32_C(   847.94), SIMDE_FLOAT32_C(   108.58), SIMDE_FLOAT32_C(   444.29) },
        { SIMDE_FLOAT32_C(    37.82), SIMDE_FLOAT32_C(   847.94), SIMDE_FLOAT32_C(   108.58), SIMDE_FLOAT32_C(   444.29) } },
      { { SIMDE_FLOAT32_C(  -301.21), SIMDE_FLOAT32_C(   571.45), SIMDE_FLOAT32_C(  -957.07), SIMDE_FLOAT32_C(   107.23) },
        { SIMDE_FLOAT32_C(   301.21), SIMDE_FLOAT32_C(   571.45), SIMDE_FLOAT32_C(   957.07), SIMDE_FLOAT32_C(   107.23) } },
      { { SIMDE_FLOAT32_C(    33.58), SIMDE_FLOAT32_C(  -231.69), SIMDE_FLOAT32_C(   681.12), SIMDE_FLOAT32_C(   426.38) },
        { SIMDE_FLOAT32_C(    33.58), SIMDE_FLOAT32_C(   231.69), SIMDE_FLOAT32_C(   681.12), SIMDE_FLOAT32_C(   426.38) } },
      { { SIMDE_FLOAT32_C(   182.06), SIMDE_FLOAT32_C(   295.23), SIMDE_FLOAT32_C(   366.40), SIMDE_FLOAT32_C(  -423.75) },
        { SIMDE_FLOAT32_C(   182.06), SIMDE_FLOAT32_C(   295.23), SIMDE_FLOAT32_C(   366.40), SIMDE_FLOAT32_C(   423.75) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t r = simde_wasm_f32x4_abs(a);
      simde_test_wasm_f32x4_assert_equal(r, simde_wasm_v128_load(test_vec[i].r), INT_MAX);
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      simde_v128_t a = simde_test_wasm_f32x4_random(-SIMDE_FLOAT32_C(1000.0), SIMDE_FLOAT32_C(1000.0));
      simde_v128_t r;

      r = simde_wasm_f32x4_abs(a);

      simde_test_wasm_f32x4_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_f32x4_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_f64x2_abs(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      simde_float64 a[sizeof(simde_v128_t) / sizeof(simde_float64)];
      simde_float64 r[sizeof(simde_v128_t) / sizeof(simde_float64)];
    } test_vec[] = {
      #if !defined(SIMDE_FAST_MATH)
      { { SIMDE_FLOAT64_C(    -0.00), SIMDE_FLOAT64_C(    -0.00) },
        { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00) } },
      #endif
      { { SIMDE_FLOAT64_C(   658.91), SIMDE_FLOAT64_C(  -816.22) },
        { SIMDE_FLOAT64_C(   658.91), SIMDE_FLOAT64_C(   816.22) } },
      { { SIMDE_FLOAT64_C(  -765.26), SIMDE_FLOAT64_C(   308.24) },
        { SIMDE_FLOAT64_C(   765.26), SIMDE_FLOAT64_C(   308.24) } },
      { { SIMDE_FLOAT64_C(   522.14), SIMDE_FLOAT64_C(   293.02) },
        { SIMDE_FLOAT64_C(   522.14), SIMDE_FLOAT64_C(   293.02) } },
      { { SIMDE_FLOAT64_C(  -637.60), SIMDE_FLOAT64_C(    45.11) },
        { SIMDE_FLOAT64_C(   637.60), SIMDE_FLOAT64_C(    45.11) } },
      { { SIMDE_FLOAT64_C(  -774.08), SIMDE_FLOAT64_C(  -511.92) },
        { SIMDE_FLOAT64_C(   774.08), SIMDE_FLOAT64_C(   511.92) } },
      { { SIMDE_FLOAT64_C(   972.92), SIMDE_FLOAT64_C(  -237.11) },
        { SIMDE_FLOAT64_C(   972.92), SIMDE_FLOAT64_C(   237.11) } },
      { { SIMDE_FLOAT64_C(   627.88), SIMDE_FLOAT64_C(    86.24) },
        { SIMDE_FLOAT64_C(   627.88), SIMDE_FLOAT64_C(    86.24) } },
      { { SIMDE_FLOAT64_C(  -199.20), SIMDE_FLOAT64_C(  -334.29) },
        { SIMDE_FLOAT64_C(   199.20), SIMDE_FLOAT64_C(   334.29) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t r = simde_wasm_f64x2_abs(a);
      simde_test_wasm_f64x2_assert_equal(r, simde_wasm_v128_load(test_vec[i].r), INT_MAX);
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      simde_v128_t a = simde_test_wasm_f64x2_random(-SIMDE_FLOAT64_C(1000.0), SIMDE_FLOAT64_C(1000.0));
      simde_v128_t r;

      r = simde_wasm_f64x2_abs(a);

      simde_test_wasm_f64x2_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_f64x2_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i8x16_abs)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i16x8_abs)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i32x4_abs)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i64x2_abs)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_f32x4_abs)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_f64x2_abs)
SIMDE_TEST_FUNC_LIST_END

#include "test-simd128-footer.h"
