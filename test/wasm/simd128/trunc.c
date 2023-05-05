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

#define SIMDE_TEST_WASM_SIMD128_INSN trunc
#include "../../../simde/wasm/simd128.h"
#include "test-simd128.h"

static int
test_simde_wasm_f32x4_trunc(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      simde_float32 a[sizeof(simde_v128_t) / sizeof(simde_float32)];
      simde_float32 r[sizeof(simde_v128_t) / sizeof(simde_float32)];
    } test_vec[8] = {
      #if !defined(SIMDE_FAST_MATH)
      { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   178.44),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   961.65) },
        {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   178.00),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   961.00) } },
      { { SIMDE_FLOAT32_C(  -592.60),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   961.65) },
        { SIMDE_FLOAT32_C(  -592.00),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   961.00) } },
      #endif
      { { SIMDE_FLOAT32_C(   -58.22), SIMDE_FLOAT32_C(  -216.54), SIMDE_FLOAT32_C(  -107.96), SIMDE_FLOAT32_C(   575.04) },
        { SIMDE_FLOAT32_C(   -58.00), SIMDE_FLOAT32_C(  -216.00), SIMDE_FLOAT32_C(  -107.00), SIMDE_FLOAT32_C(   575.00) } },
      { { SIMDE_FLOAT32_C(   582.49), SIMDE_FLOAT32_C(   675.51), SIMDE_FLOAT32_C(   386.09), SIMDE_FLOAT32_C(   311.18) },
        { SIMDE_FLOAT32_C(   582.00), SIMDE_FLOAT32_C(   675.00), SIMDE_FLOAT32_C(   386.00), SIMDE_FLOAT32_C(   311.00) } },
      { { SIMDE_FLOAT32_C(   234.64), SIMDE_FLOAT32_C(  -555.27), SIMDE_FLOAT32_C(  -984.65), SIMDE_FLOAT32_C(  -538.41) },
        { SIMDE_FLOAT32_C(   234.00), SIMDE_FLOAT32_C(  -555.00), SIMDE_FLOAT32_C(  -984.00), SIMDE_FLOAT32_C(  -538.00) } },
      { { SIMDE_FLOAT32_C(  -347.32), SIMDE_FLOAT32_C(   147.79), SIMDE_FLOAT32_C(   695.55), SIMDE_FLOAT32_C(   708.13) },
        { SIMDE_FLOAT32_C(  -347.00), SIMDE_FLOAT32_C(   147.00), SIMDE_FLOAT32_C(   695.00), SIMDE_FLOAT32_C(   708.00) } },
      { { SIMDE_FLOAT32_C(   640.90), SIMDE_FLOAT32_C(   320.51), SIMDE_FLOAT32_C(   799.81), SIMDE_FLOAT32_C(   865.49) },
        { SIMDE_FLOAT32_C(   640.00), SIMDE_FLOAT32_C(   320.00), SIMDE_FLOAT32_C(   799.00), SIMDE_FLOAT32_C(   865.00) } },
      { { SIMDE_FLOAT32_C(  -533.80), SIMDE_FLOAT32_C(   779.92), SIMDE_FLOAT32_C(  -479.71), SIMDE_FLOAT32_C(  -466.23) },
        { SIMDE_FLOAT32_C(  -533.00), SIMDE_FLOAT32_C(   779.00), SIMDE_FLOAT32_C(  -479.00), SIMDE_FLOAT32_C(  -466.00) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t r = simde_wasm_f32x4_trunc(a);
      simde_test_wasm_f32x4_assert_equal(r, simde_wasm_v128_load(test_vec[i].r), INT_MAX);
    }
    return 0;
  #else
    fputc('\n', stdout);
    simde_float32 inputs[8 * 1 * (sizeof(simde_v128_t) / sizeof(simde_float32))];
    simde_test_wasm_f32x4_random_full(8, 1, inputs, -SIMDE_FLOAT32_C(1000.0), SIMDE_FLOAT32_C(1000.0), HEDLEY_STATIC_CAST(SimdeTestVecFloatType, SIMDE_TEST_VEC_FLOAT_NAN | SIMDE_TEST_VEC_FLOAT_EQUAL));
    for (size_t i = 0 ; i < 8 ; i++) {
      simde_v128_t
        a = simde_test_wasm_f32x4_random_full_extract(1, inputs, i, 0),
        r;

      r = simde_wasm_f32x4_trunc(a);

      simde_test_wasm_f32x4_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_f32x4_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_f64x2_trunc(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      simde_float64 a[sizeof(simde_v128_t) / sizeof(simde_float32)];
      simde_float64 r[sizeof(simde_v128_t) / sizeof(simde_float32)];
    } test_vec[8] = {
      #if !defined(SIMDE_FAST_MATH)
      { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   814.26) },
        {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   814.00) } },
      { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   403.23) },
        {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   403.00) } },
      { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   403.23) },
        {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   403.00) } },
      #endif
      { { SIMDE_FLOAT64_C(  -911.39), SIMDE_FLOAT64_C(  -448.17) },
        { SIMDE_FLOAT64_C(  -911.00), SIMDE_FLOAT64_C(  -448.00) } },
      { { SIMDE_FLOAT64_C(  -194.81), SIMDE_FLOAT64_C(   412.40) },
        { SIMDE_FLOAT64_C(  -194.00), SIMDE_FLOAT64_C(   412.00) } },
      { { SIMDE_FLOAT64_C(   649.79), SIMDE_FLOAT64_C(   190.09) },
        { SIMDE_FLOAT64_C(   649.00), SIMDE_FLOAT64_C(   190.00) } },
      { { SIMDE_FLOAT64_C(  -362.00), SIMDE_FLOAT64_C(  -908.25) },
        { SIMDE_FLOAT64_C(  -362.00), SIMDE_FLOAT64_C(  -908.00) } },
      { { SIMDE_FLOAT64_C(   297.27), SIMDE_FLOAT64_C(  -545.73) },
        { SIMDE_FLOAT64_C(   297.00), SIMDE_FLOAT64_C(  -545.00) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t r = simde_wasm_f64x2_trunc(a);
      simde_test_wasm_f64x2_assert_equal(r, simde_wasm_v128_load(test_vec[i].r), INT_MAX);
    }
    return 0;
  #else
    fputc('\n', stdout);
    simde_float64 inputs[8 * 1 * (sizeof(simde_v128_t) / sizeof(simde_float32))];
    simde_test_wasm_f64x2_random_full(8, 1, inputs, -SIMDE_FLOAT64_C(1000.0), SIMDE_FLOAT64_C(1000.0), HEDLEY_STATIC_CAST(SimdeTestVecFloatType, SIMDE_TEST_VEC_FLOAT_NAN | SIMDE_TEST_VEC_FLOAT_EQUAL));
    for (size_t i = 0 ; i < 8 ; i++) {
      simde_v128_t
        a = simde_test_wasm_f64x2_random_full_extract(1, inputs, i, 0),
        r;

      r = simde_wasm_f64x2_trunc(a);

      simde_test_wasm_f64x2_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_f64x2_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_f32x4_trunc)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_f64x2_trunc)
SIMDE_TEST_FUNC_LIST_END

#include "test-simd128-footer.h"
