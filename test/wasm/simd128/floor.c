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

#define SIMDE_TEST_WASM_SIMD128_INSN floor
#include "../../../simde/wasm/simd128.h"
#include "test-simd128.h"

static int
test_simde_wasm_f32x4_floor(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      simde_float32 a[sizeof(simde_v128_t) / sizeof(simde_float32)];
      simde_float32 r[sizeof(simde_v128_t) / sizeof(simde_float32)];
    } test_vec[] = {
      #if !defined(SIMDE_FAST_MATH)
      { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -629.23),            SIMDE_MATH_NANF, HEDLEY_STATIC_CAST(simde_float32, INT_MAX) * SIMDE_FLOAT32_C(2.0) },
        {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -630.00),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(4294967296.0) } },
      { { SIMDE_FLOAT32_C(   674.73),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, HEDLEY_STATIC_CAST(simde_float32, INT_MIN) * SIMDE_FLOAT32_C(2.0) },
        { SIMDE_FLOAT32_C(   674.00),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(-4294967296.0) } },
      #endif
      { { SIMDE_FLOAT32_C(   897.35), SIMDE_FLOAT32_C(   -88.15), SIMDE_FLOAT32_C(  -740.68), SIMDE_FLOAT32_C(   750.88) },
        { SIMDE_FLOAT32_C(   897.00), SIMDE_FLOAT32_C(   -89.00), SIMDE_FLOAT32_C(  -741.00), SIMDE_FLOAT32_C(   750.00) } },
      { { SIMDE_FLOAT32_C(   582.09), SIMDE_FLOAT32_C(  -164.27), SIMDE_FLOAT32_C(  -308.47), SIMDE_FLOAT32_C(  -126.99) },
        { SIMDE_FLOAT32_C(   582.00), SIMDE_FLOAT32_C(  -165.00), SIMDE_FLOAT32_C(  -309.00), SIMDE_FLOAT32_C(  -127.00) } },
      { { SIMDE_FLOAT32_C(  -259.41), SIMDE_FLOAT32_C(  -157.31), SIMDE_FLOAT32_C(  -740.24), SIMDE_FLOAT32_C(   437.40) },
        { SIMDE_FLOAT32_C(  -260.00), SIMDE_FLOAT32_C(  -158.00), SIMDE_FLOAT32_C(  -741.00), SIMDE_FLOAT32_C(   437.00) } },
      { { SIMDE_FLOAT32_C(   303.98), SIMDE_FLOAT32_C(   280.69), SIMDE_FLOAT32_C(   654.52), SIMDE_FLOAT32_C(   406.53) },
        { SIMDE_FLOAT32_C(   303.00), SIMDE_FLOAT32_C(   280.00), SIMDE_FLOAT32_C(   654.00), SIMDE_FLOAT32_C(   406.00) } },
      { { SIMDE_FLOAT32_C(   278.15), SIMDE_FLOAT32_C(  -477.89), SIMDE_FLOAT32_C(  -605.23), SIMDE_FLOAT32_C(   594.72) },
        { SIMDE_FLOAT32_C(   278.00), SIMDE_FLOAT32_C(  -478.00), SIMDE_FLOAT32_C(  -606.00), SIMDE_FLOAT32_C(   594.00) } },
      { { SIMDE_FLOAT32_C(  -605.22), SIMDE_FLOAT32_C(   887.13), SIMDE_FLOAT32_C(  -486.19), SIMDE_FLOAT32_C(   800.15) },
        { SIMDE_FLOAT32_C(  -606.00), SIMDE_FLOAT32_C(   887.00), SIMDE_FLOAT32_C(  -487.00), SIMDE_FLOAT32_C(   800.00) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t r = simde_wasm_f32x4_floor(a);
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

      r = simde_wasm_f32x4_floor(a);

      simde_test_wasm_f32x4_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_f32x4_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_f64x2_floor(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      simde_float64 a[sizeof(simde_v128_t) / sizeof(simde_float32)];
      simde_float64 r[sizeof(simde_v128_t) / sizeof(simde_float32)];
    } test_vec[] = {
      #if !defined(SIMDE_FAST_MATH)
      { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -258.38) },
        {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -259.00) } },
      { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   985.95) },
        {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   985.00) } },
      { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   985.95) },
        {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   985.00) } },
      #endif
      { { SIMDE_FLOAT64_C(  -728.40), SIMDE_FLOAT64_C(  -108.62) },
        { SIMDE_FLOAT64_C(  -729.00), SIMDE_FLOAT64_C(  -109.00) } },
      { { SIMDE_FLOAT64_C(   142.37), SIMDE_FLOAT64_C(   553.12) },
        { SIMDE_FLOAT64_C(   142.00), SIMDE_FLOAT64_C(   553.00) } },
      { { SIMDE_FLOAT64_C(  -680.26), SIMDE_FLOAT64_C(   145.23) },
        { SIMDE_FLOAT64_C(  -681.00), SIMDE_FLOAT64_C(   145.00) } },
      { { SIMDE_FLOAT64_C(   557.25), SIMDE_FLOAT64_C(    88.19) },
        { SIMDE_FLOAT64_C(   557.00), SIMDE_FLOAT64_C(    88.00) } },
      { { SIMDE_FLOAT64_C(   186.49), SIMDE_FLOAT64_C(   -53.85) },
        { SIMDE_FLOAT64_C(   186.00), SIMDE_FLOAT64_C(   -54.00) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t r = simde_wasm_f64x2_floor(a);
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

      r = simde_wasm_f64x2_floor(a);

      simde_test_wasm_f64x2_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_f64x2_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_f32x4_floor)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_f64x2_floor)
SIMDE_TEST_FUNC_LIST_END

#include "test-simd128-footer.h"
