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

#include "test/test.h"
#define SIMDE_TESTS_CURRENT_ISAX simd128
#include <simde/wasm/simd128.h>
#include <test/wasm/test-simd128.h>

static int
test_simde_wasm_i8x16_any_true(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int8_t a[sizeof(simde_v128_t) / sizeof(int8_t)];
      simde_bool r;
    } test_vec[8] = {
      { {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
           INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0) },
         INT8_C(   0) },
      { {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
           INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0) },
         INT8_C(   0) },
      { {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  56),  INT8_C(   0),  INT8_C(   0),  INT8_C(  97),
           INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0) },
         INT8_C(   1) },
      { {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
           INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0) },
         INT8_C(   0) },
      { {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
           INT8_C(   0),  INT8_C(  11),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0) },
         INT8_C(   1) },
      { {  INT8_C(   0),  INT8_C(   0), -INT8_C(  10),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
           INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  33),  INT8_C(   0) },
         INT8_C(   1) },
      { {  INT8_C(   0), -INT8_C( 122),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C( 104),  INT8_C(   0),
           INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  22),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0) },
         INT8_C(   1) },
      { {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
           INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0) },
         INT8_C(   0) }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_bool r = simde_wasm_i8x16_any_true(a);
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
        if ((simde_test_codegen_random_i8() & 15) != 0)
          a_[j] = INT8_C(0);

      a = simde_wasm_v128_load(a_);
      r = simde_wasm_i8x16_any_true(a);

      simde_test_wasm_i8x16_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_codegen_write_i8(3, HEDLEY_STATIC_CAST(int8_t, r), SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_i16x8_any_true(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int16_t a[sizeof(simde_v128_t) / sizeof(int16_t)];
      simde_bool r;
    } test_vec[8] = {
      { {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(  6992), -INT16_C( 23383) },
         INT8_C(   1) },
      { {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) },
         INT8_C(   0) },
      { {  INT16_C(     0),  INT16_C( 30380),  INT16_C(     0),  INT16_C( 16935),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C( 13207) },
         INT8_C(   1) },
      { {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) },
         INT8_C(   0) },
      { {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) },
         INT8_C(   0) },
      { {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(  1279),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) },
         INT8_C(   1) },
      { {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) },
         INT8_C(   0) },
      { {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) },
         INT8_C(   0) }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_bool r = simde_wasm_i16x8_any_true(a);
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
        if ((simde_test_codegen_random_i8() & 7) != 0)
          a_[j] = INT8_C(0);

      a = simde_wasm_v128_load(a_);
      r = simde_wasm_i16x8_any_true(a);

      simde_test_wasm_i16x8_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_codegen_write_i8(3, HEDLEY_STATIC_CAST(int8_t, r), SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_i32x4_any_true(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int32_t a[sizeof(simde_v128_t) / sizeof(int32_t)];
      simde_bool r;
    } test_vec[8] = {
      { {  INT32_C(  2062006595),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) },
         INT8_C(   1) },
      { { -INT32_C(  2005392228),  INT32_C(   630721280),  INT32_C(           0),  INT32_C(           0) },
         INT8_C(   1) },
      { {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) },
         INT8_C(   0) },
      { { -INT32_C(   944392518),  INT32_C(   167936229),  INT32_C(  2060914834),  INT32_C(           0) },
         INT8_C(   1) },
      { {  INT32_C(  1441687381),  INT32_C(   855409402),  INT32_C(           0),  INT32_C(           0) },
         INT8_C(   1) },
      { {  INT32_C(  1611107999),  INT32_C(           0), -INT32_C(   760070177),  INT32_C(           0) },
         INT8_C(   1) },
      { {  INT32_C(           0), -INT32_C(   188210492),  INT32_C(           0),  INT32_C(           0) },
         INT8_C(   1) },
      { {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) },
         INT8_C(   0) }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_bool r = simde_wasm_i32x4_any_true(a);
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
        if ((simde_test_codegen_random_i32() & 3) != 0)
          a_[j] = INT8_C(0);

      a = simde_wasm_v128_load(a_);
      r = simde_wasm_i32x4_any_true(a);

      simde_test_wasm_i32x4_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_codegen_write_i8(3, HEDLEY_STATIC_CAST(int8_t, r), SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_i64x2_any_true(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int64_t a[sizeof(simde_v128_t) / sizeof(int64_t)];
      simde_bool r;
    } test_vec[8] = {
      { {  INT64_C( 5173941518233846579),  INT64_C( 2734465705508048753) },
         INT8_C(   1) },
      { {  INT64_C(                   0), -INT64_C( 1018075744330418987) },
         INT8_C(   1) },
      { {  INT64_C(                   0),  INT64_C( 2410531038303081363) },
         INT8_C(   1) },
      { {  INT64_C(                   0),  INT64_C(                   0) },
         INT8_C(   0) },
      { {  INT64_C(                   0), -INT64_C( 2971519654279241984) },
         INT8_C(   1) },
      { {  INT64_C(                   0), -INT64_C(  411126145548787127) },
         INT8_C(   1) },
      { { -INT64_C( 8220201163245683340), -INT64_C( 5803111050133263312) },
         INT8_C(   1) },
      { {  INT64_C( 9030670128360120350),  INT64_C(                   0) },
         INT8_C(   1) }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_bool r = simde_wasm_i64x2_any_true(a);
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
        if ((simde_test_codegen_random_i64() & 1) != 0)
          a_[j] = INT8_C(0);

      a = simde_wasm_v128_load(a_);
      r = simde_wasm_i64x2_any_true(a);

      simde_test_wasm_i64x2_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_codegen_write_i8(3, HEDLEY_STATIC_CAST(int8_t, r), SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i8x16_any_true)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i16x8_any_true)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i32x4_any_true)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i64x2_any_true)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/test-x86-footer.h>
