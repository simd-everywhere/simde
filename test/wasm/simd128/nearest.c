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

#define SIMDE_TEST_WASM_SIMD128_INSN nearest
#include "../../../simde/wasm/simd128.h"
#include "test-simd128.h"

static int
test_simde_wasm_f32x4_nearest(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      simde_float32 a[sizeof(simde_v128_t) / sizeof(simde_float32)];
      simde_float32 r[sizeof(simde_v128_t) / sizeof(simde_float32)];
    } test_vec[10] = {
      #if !defined(SIMDE_FAST_MATH)
      { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   645.22),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   412.81) },
        {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   645.00),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   413.00) } },
      { { SIMDE_FLOAT32_C(  -809.57),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   412.81) },
        { SIMDE_FLOAT32_C(  -810.00),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   413.00) } },
      #endif
      { { SIMDE_FLOAT32_C(   160.20), SIMDE_FLOAT32_C(   379.44), SIMDE_FLOAT32_C(  -119.78), SIMDE_FLOAT32_C(  -844.35) },
        { SIMDE_FLOAT32_C(   160.00), SIMDE_FLOAT32_C(   379.00), SIMDE_FLOAT32_C(  -120.00), SIMDE_FLOAT32_C(  -844.00) } },
      { { SIMDE_FLOAT32_C(  -203.57), SIMDE_FLOAT32_C(   993.31), SIMDE_FLOAT32_C(   160.15), SIMDE_FLOAT32_C(  -978.96) },
        { SIMDE_FLOAT32_C(  -204.00), SIMDE_FLOAT32_C(   993.00), SIMDE_FLOAT32_C(   160.00), SIMDE_FLOAT32_C(  -979.00) } },
      { { SIMDE_FLOAT32_C(  -145.49), SIMDE_FLOAT32_C(   625.61), SIMDE_FLOAT32_C(   130.28), SIMDE_FLOAT32_C(  -846.66) },
        { SIMDE_FLOAT32_C(  -145.00), SIMDE_FLOAT32_C(   626.00), SIMDE_FLOAT32_C(   130.00), SIMDE_FLOAT32_C(  -847.00) } },
      { { SIMDE_FLOAT32_C(    10.77), SIMDE_FLOAT32_C(   -96.94), SIMDE_FLOAT32_C(   159.50), SIMDE_FLOAT32_C(  -965.99) },
        { SIMDE_FLOAT32_C(    11.00), SIMDE_FLOAT32_C(   -97.00), SIMDE_FLOAT32_C(   160.00), SIMDE_FLOAT32_C(  -966.00) } },
      { { SIMDE_FLOAT32_C(  -564.06), SIMDE_FLOAT32_C(  -466.91), SIMDE_FLOAT32_C(  -957.42), SIMDE_FLOAT32_C(  -658.76) },
        { SIMDE_FLOAT32_C(  -564.00), SIMDE_FLOAT32_C(  -467.00), SIMDE_FLOAT32_C(  -957.00), SIMDE_FLOAT32_C(  -659.00) } },
      { { SIMDE_FLOAT32_C(   -40.51), SIMDE_FLOAT32_C(   330.54), SIMDE_FLOAT32_C(   789.68), SIMDE_FLOAT32_C(  -614.18) },
        { SIMDE_FLOAT32_C(   -41.00), SIMDE_FLOAT32_C(   331.00), SIMDE_FLOAT32_C(   790.00), SIMDE_FLOAT32_C(  -614.00) } },
      { { SIMDE_FLOAT32_C(      0.5), SIMDE_FLOAT32_C(      0.5), SIMDE_FLOAT32_C(      0.5), SIMDE_FLOAT32_C(      0.5) },
        { SIMDE_FLOAT32_C(      0.0), SIMDE_FLOAT32_C(      0.0), SIMDE_FLOAT32_C(      0.0), SIMDE_FLOAT32_C(      0.0) } },
      { { SIMDE_FLOAT32_C(     -0.5), SIMDE_FLOAT32_C(     -0.5), SIMDE_FLOAT32_C(     -0.5), SIMDE_FLOAT32_C(     -0.5) },
        { SIMDE_FLOAT32_C(     -0.0), SIMDE_FLOAT32_C(     -0.0), SIMDE_FLOAT32_C(     -0.0), SIMDE_FLOAT32_C(     -0.0) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t r = simde_wasm_f32x4_nearest(a);
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

      r = simde_wasm_f32x4_nearest(a);

      simde_test_wasm_f32x4_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_f32x4_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_f64x2_nearest(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      simde_float64 a[sizeof(simde_v128_t) / sizeof(simde_float32)];
      simde_float64 r[sizeof(simde_v128_t) / sizeof(simde_float32)];
    } test_vec[10] = {
      #if !defined(SIMDE_FAST_MATH)
      { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -212.99) },
        {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -213.00) } },
      { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -696.06) },
        {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -696.00) } },
      { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -696.06) },
        {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -696.00) } },
      #endif
      { { SIMDE_FLOAT64_C(   399.39), SIMDE_FLOAT64_C(  -184.62) },
        { SIMDE_FLOAT64_C(   399.00), SIMDE_FLOAT64_C(  -185.00) } },
      { { SIMDE_FLOAT64_C(  -339.89), SIMDE_FLOAT64_C(  -794.93) },
        { SIMDE_FLOAT64_C(  -340.00), SIMDE_FLOAT64_C(  -795.00) } },
      { { SIMDE_FLOAT64_C(  -594.63), SIMDE_FLOAT64_C(   101.10) },
        { SIMDE_FLOAT64_C(  -595.00), SIMDE_FLOAT64_C(   101.00) } },
      { { SIMDE_FLOAT64_C(  -477.73), SIMDE_FLOAT64_C(  -410.10) },
        { SIMDE_FLOAT64_C(  -478.00), SIMDE_FLOAT64_C(  -410.00) } },
      { { SIMDE_FLOAT64_C(  -481.69), SIMDE_FLOAT64_C(  -557.27) },
        { SIMDE_FLOAT64_C(  -482.00), SIMDE_FLOAT64_C(  -557.00) } },
      { { SIMDE_FLOAT64_C(      0.5), SIMDE_FLOAT64_C(      0.5) },
        { SIMDE_FLOAT64_C(      0.0), SIMDE_FLOAT64_C(      0.0) } },
      { { SIMDE_FLOAT64_C(     -0.5), SIMDE_FLOAT64_C(     -0.5) },
        { SIMDE_FLOAT64_C(     -0.0), SIMDE_FLOAT64_C(     -0.0) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t r = simde_wasm_f64x2_nearest(a);
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

      r = simde_wasm_f64x2_nearest(a);

      simde_test_wasm_f64x2_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_f64x2_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_f32x4_nearest)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_f64x2_nearest)
SIMDE_TEST_FUNC_LIST_END

#include "test-simd128-footer.h"
