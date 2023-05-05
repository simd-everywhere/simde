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

#define SIMDE_TEST_WASM_SIMD128_INSN all_true
#include "../../../simde/wasm/simd128.h"
#include "test-simd128.h"

static int
test_simde_wasm_i8x16_all_true(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int8_t a[sizeof(simde_v128_t) / sizeof(int8_t)];
      simde_bool r;
    } test_vec[8] = {
      { { -INT8_C( 118),  INT8_C( 120), -INT8_C(  21), -INT8_C( 102),  INT8_C(  33),  INT8_C( 108), -INT8_C( 116), -INT8_C( 119),
           INT8_C(  67), -INT8_C( 124), -INT8_C(  20),  INT8_C( 126), -INT8_C(  97), -INT8_C(  33), -INT8_C(  31), -INT8_C( 127) },
         INT8_C(   1) },
      { { -INT8_C( 101),  INT8_C(   0),  INT8_C(  41), -INT8_C( 109), -INT8_C(  60),  INT8_C(   0), -INT8_C(  42),  INT8_C( 100),
           INT8_C(  95),  INT8_C(  94), -INT8_C( 116), -INT8_C( 127), -INT8_C(  86), -INT8_C( 126), -INT8_C(  49),  INT8_C(  19) },
         INT8_C(   0) },
      { {  INT8_C(  48), -INT8_C(  61), -INT8_C(  85), -INT8_C(   9), -INT8_C(  19),  INT8_C(  15), -INT8_C(  20),  INT8_C(  21),
          -INT8_C(  12),  INT8_C(  63), -INT8_C(  91), -INT8_C(  84), -INT8_C(  82),  INT8_C(  31),  INT8_C( 103),  INT8_C( 109) },
         INT8_C(   1) },
      { {  INT8_C(  69),  INT8_C(  24), -INT8_C(  99), -INT8_C(  46),  INT8_C(  14),  INT8_C(  58),  INT8_C(  78),  INT8_C(  54),
          -INT8_C( 100), -INT8_C(  48), -INT8_C(  88),  INT8_C(  70),  INT8_C( 126), -INT8_C(  99), -INT8_C(  78),  INT8_C(  84) },
         INT8_C(   1) },
      { { -INT8_C(  94),  INT8_C( 119),  INT8_C(  65),      INT8_MIN, -INT8_C(  43),  INT8_C(   0),  INT8_C(  36), -INT8_C(  18),
          -INT8_C( 105),  INT8_C(  89),  INT8_C( 100),  INT8_C( 115), -INT8_C(  38),  INT8_C(  69), -INT8_C(  26),  INT8_C(  57) },
         INT8_C(   0) },
      { {  INT8_C(   6),  INT8_C( 105),  INT8_C( 112),  INT8_C(   0), -INT8_C(  64),  INT8_C(  12), -INT8_C(  88),  INT8_C( 115),
          -INT8_C(  47),  INT8_C(   1),  INT8_C( 109), -INT8_C(  20), -INT8_C(  27), -INT8_C(  80), -INT8_C(  75),  INT8_C(  21) },
         INT8_C(   0) },
      { { -INT8_C(  52),      INT8_MAX, -INT8_C( 104), -INT8_C(  69),  INT8_C(  52), -INT8_C(  62),  INT8_C(  25),  INT8_C(  13),
           INT8_C( 103), -INT8_C( 127), -INT8_C(  10),  INT8_C(  44),  INT8_C(  29),  INT8_C(  47),  INT8_C(  30), -INT8_C(  45) },
         INT8_C(   1) },
      { {  INT8_C(  20),  INT8_C(  39),  INT8_C(  56), -INT8_C(  12),  INT8_C(  25),  INT8_C(  96),  INT8_C(  40), -INT8_C( 105),
          -INT8_C(  81),  INT8_C( 105),  INT8_C(  49),  INT8_C(  40), -INT8_C(  47), -INT8_C(  72), -INT8_C(  71),  INT8_C(  46) },
         INT8_C(   1) }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_bool r = simde_wasm_i8x16_all_true(a);
      simde_assert_equal_i(r, test_vec[i].r);
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      int8_t a_[sizeof(simde_v128_t) / sizeof(int8_t)];
      simde_v128_t a;
      simde_bool r;

      simde_test_codegen_random_memory(sizeof(a_), HEDLEY_REINTERPRET_CAST(uint8_t*, a_));
      for (size_t j = 0 ; j < (sizeof(a_) / sizeof(a_[0])) ; j++)
        if ((simde_test_codegen_random_i8() & 15) == 0)
          a_[j] = INT8_C(0);

      a = simde_wasm_v128_load(a_);
      r = simde_wasm_i8x16_all_true(a);

      simde_test_wasm_i8x16_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_codegen_write_i8(3, HEDLEY_STATIC_CAST(int8_t, r), SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_i16x8_all_true(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int16_t a[sizeof(simde_v128_t) / sizeof(int16_t)];
      simde_bool r;
    } test_vec[8] = {
      { { -INT16_C( 25421),  INT16_C(  3773), -INT16_C(   372), -INT16_C( 24078),  INT16_C(  2299), -INT16_C(   967), -INT16_C( 11237),  INT16_C( 15736) },
         INT8_C(   1) },
      { { -INT16_C(  4671),  INT16_C( 27223),  INT16_C( 17840),  INT16_C( 10235),  INT16_C( 30072), -INT16_C(   492),  INT16_C( 30279),  INT16_C(   802) },
         INT8_C(   1) },
      { {  INT16_C(     0),  INT16_C( 19217), -INT16_C(  5540), -INT16_C( 10003), -INT16_C(  9351),  INT16_C( 21231), -INT16_C( 32084), -INT16_C(  1419) },
         INT8_C(   0) },
      { {  INT16_C( 23173), -INT16_C( 20216),  INT16_C(     0),  INT16_C(     0), -INT16_C( 32684),  INT16_C(     0), -INT16_C(  9847),  INT16_C( 22408) },
         INT8_C(   0) },
      { {  INT16_C( 19486), -INT16_C( 15797), -INT16_C(  2693), -INT16_C( 14488),  INT16_C( 17845),  INT16_C(     0), -INT16_C( 23611),  INT16_C(     0) },
         INT8_C(   0) },
      { { -INT16_C(  5256), -INT16_C( 24366),  INT16_C( 17454),  INT16_C(     0),  INT16_C(  9444),  INT16_C(     0), -INT16_C(  8128),  INT16_C( 24841) },
         INT8_C(   0) },
      { {  INT16_C( 16646),  INT16_C( 16503),  INT16_C(  1445),  INT16_C(  4280), -INT16_C(  9873), -INT16_C( 30842),  INT16_C(  8276),  INT16_C(  9109) },
         INT8_C(   1) },
      { { -INT16_C( 24237), -INT16_C( 23231),  INT16_C( 12106), -INT16_C( 19662),  INT16_C(  4558), -INT16_C( 26545),  INT16_C( 28975), -INT16_C(  3033) },
         INT8_C(   1) }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_bool r = simde_wasm_i16x8_all_true(a);
      simde_assert_equal_i(r, test_vec[i].r);
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      int16_t a_[sizeof(simde_v128_t) / sizeof(int16_t)];
      simde_v128_t a;
      simde_bool r;

      simde_test_codegen_random_memory(sizeof(a_), HEDLEY_REINTERPRET_CAST(uint8_t*, a_));
      for (size_t j = 0 ; j < (sizeof(a_) / sizeof(a_[0])) ; j++)
        if ((simde_test_codegen_random_i8() & 7) == 0)
          a_[j] = INT8_C(0);

      a = simde_wasm_v128_load(a_);
      r = simde_wasm_i16x8_all_true(a);

      simde_test_wasm_i16x8_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_codegen_write_i8(3, HEDLEY_STATIC_CAST(int8_t, r), SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_i32x4_all_true(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int32_t a[sizeof(simde_v128_t) / sizeof(int32_t)];
      simde_bool r;
    } test_vec[8] = {
      { {  INT32_C(           0),  INT32_C(   633966131),  INT32_C(  2103201033),  INT32_C(           0) },
         INT8_C(   0) },
      { {  INT32_C(  2100723142),  INT32_C(   549532161), -INT32_C(  1764921796),  INT32_C(  2019079093) },
         INT8_C(   1) },
      { { -INT32_C(  1697466700),  INT32_C(   362260685),  INT32_C(           0),  INT32_C(  2071406208) },
         INT8_C(   0) },
      { { -INT32_C(   456478402),  INT32_C(           0),  INT32_C(  1351629541), -INT32_C(   900975230) },
         INT8_C(   0) },
      { {  INT32_C(  1463556673),  INT32_C(  1744127960),  INT32_C(           0),  INT32_C(   115136429) },
         INT8_C(   0) },
      { { -INT32_C(  1255673427), -INT32_C(   671908381), -INT32_C(  1411019791), -INT32_C(   493737069) },
         INT8_C(   1) },
      { { -INT32_C(  2033632984), -INT32_C(   917615446), -INT32_C(   808488282),  INT32_C(           0) },
         INT8_C(   0) },
      { {  INT32_C(           0),  INT32_C(   337202970), -INT32_C(  1182353517),  INT32_C(           0) },
         INT8_C(   0) }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_bool r = simde_wasm_i32x4_all_true(a);
      simde_assert_equal_i(r, test_vec[i].r);
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      int32_t a_[sizeof(simde_v128_t) / sizeof(int32_t)];
      simde_v128_t a;
      simde_bool r;

      simde_test_codegen_random_memory(sizeof(a_), HEDLEY_REINTERPRET_CAST(uint8_t*, a_));
      for (size_t j = 0 ; j < (sizeof(a_) / sizeof(a_[0])) ; j++)
        if ((simde_test_codegen_random_i32() & 3) == 0)
          a_[j] = INT8_C(0);

      a = simde_wasm_v128_load(a_);
      r = simde_wasm_i32x4_all_true(a);

      simde_test_wasm_i32x4_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_codegen_write_i8(3, HEDLEY_STATIC_CAST(int8_t, r), SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

#if !defined(SIMDE_FAST_MATH)
// TODO: This fails with -ffast-math ; but there are no NANs involved??
static int
test_simde_wasm_i64x2_all_true(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int64_t a[sizeof(simde_v128_t) / sizeof(int64_t)];
      simde_bool r;
    } test_vec[8] = {
      { {  INT64_C( 4627191103769018368), -INT64_C( 6533839992563695616) },
         INT8_C(   1) },
      { { -INT64_C( 2356159122894565910), -INT64_C( 7636474394341444928) },
         INT8_C(   1) },
      { { -INT64_C( 5614692162571868031),  INT64_C( 1687979966696920052) },
         INT8_C(   1) },
      { {  INT64_C(  222243027358750925),  INT64_C(                   0) },
         INT8_C(   0) },
      { {  INT64_C(          4083780179),  INT64_C( 6996765384397661295) },
         INT8_C(   1) },
      { {  INT64_C( 6728759044367151320), -INT64_C( 2257984121953607472) },
         INT8_C(   1) },
      { {  INT64_C(                   0), -INT64_C( 1209425168241270568) },
         INT8_C(   0) },
      { { -INT64_C( 7853513116650955838), -INT64_C( 4468347172671650195) },
         INT8_C(   1) }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_bool r = simde_wasm_i64x2_all_true(a);
      simde_assert_equal_i(r, test_vec[i].r);
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      int64_t a_[sizeof(simde_v128_t) / sizeof(int64_t)];
      simde_v128_t a;
      simde_bool r;

      simde_test_codegen_random_memory(sizeof(a_), HEDLEY_REINTERPRET_CAST(uint8_t*, a_));
      for (size_t j = 0 ; j < (sizeof(a_) / sizeof(a_[0])) ; j++)
        if ((simde_test_codegen_random_i32() & 3) == 0)
          a_[j] = INT8_C(0);

      a = simde_wasm_v128_load(a_);
      r = simde_wasm_i64x2_all_true(a);

      simde_test_wasm_i64x2_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_codegen_write_i8(3, HEDLEY_STATIC_CAST(int8_t, r), SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}
#endif

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i8x16_all_true)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i16x8_all_true)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i32x4_all_true)
  #if !defined(SIMDE_FAST_MATH)
    SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i64x2_all_true)
  #endif
SIMDE_TEST_FUNC_LIST_END

#include "test-simd128-footer.h"
