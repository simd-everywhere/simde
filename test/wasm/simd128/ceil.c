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

#define SIMDE_TEST_WASM_SIMD128_INSN ceil
#include "../../../simde/wasm/simd128.h"
#include "test-simd128.h"

static int
test_simde_wasm_f32x4_ceil(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      simde_float32 a[sizeof(simde_v128_t) / sizeof(simde_float32)];
      simde_float32 r[sizeof(simde_v128_t) / sizeof(simde_float32)];
    } test_vec[8] = {
      #if !defined(SIMDE_FAST_MATH)
      { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   967.55),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   -75.07) },
        {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   968.00),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   -75.00) } },
      { { SIMDE_FLOAT32_C(  -267.65),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   -75.07) },
        { SIMDE_FLOAT32_C(  -267.00),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   -75.00) } },
      #endif
      { { SIMDE_FLOAT32_C(   -94.64), SIMDE_FLOAT32_C(  -954.54), SIMDE_FLOAT32_C(  -214.03), SIMDE_FLOAT32_C(   659.13) },
        { SIMDE_FLOAT32_C(   -94.00), SIMDE_FLOAT32_C(  -954.00), SIMDE_FLOAT32_C(  -214.00), SIMDE_FLOAT32_C(   660.00) } },
      { { SIMDE_FLOAT32_C(   631.62), SIMDE_FLOAT32_C(  -350.98), SIMDE_FLOAT32_C(  -517.69), SIMDE_FLOAT32_C(  -532.20) },
        { SIMDE_FLOAT32_C(   632.00), SIMDE_FLOAT32_C(  -350.00), SIMDE_FLOAT32_C(  -517.00), SIMDE_FLOAT32_C(  -532.00) } },
      { { SIMDE_FLOAT32_C(  -143.29), SIMDE_FLOAT32_C(  -443.27), SIMDE_FLOAT32_C(   651.65), SIMDE_FLOAT32_C(   612.16) },
        { SIMDE_FLOAT32_C(  -143.00), SIMDE_FLOAT32_C(  -443.00), SIMDE_FLOAT32_C(   652.00), SIMDE_FLOAT32_C(   613.00) } },
      { { SIMDE_FLOAT32_C(  -294.11), SIMDE_FLOAT32_C(  -206.67), SIMDE_FLOAT32_C(  -142.88), SIMDE_FLOAT32_C(  -982.62) },
        { SIMDE_FLOAT32_C(  -294.00), SIMDE_FLOAT32_C(  -206.00), SIMDE_FLOAT32_C(  -142.00), SIMDE_FLOAT32_C(  -982.00) } },
      { { SIMDE_FLOAT32_C(   720.33), SIMDE_FLOAT32_C(   -19.51), SIMDE_FLOAT32_C(  -530.16), SIMDE_FLOAT32_C(   983.33) },
        { SIMDE_FLOAT32_C(   721.00), SIMDE_FLOAT32_C(   -19.00), SIMDE_FLOAT32_C(  -530.00), SIMDE_FLOAT32_C(   984.00) } },
      { { SIMDE_FLOAT32_C(  -255.40), SIMDE_FLOAT32_C(   952.47), SIMDE_FLOAT32_C(  -771.36), SIMDE_FLOAT32_C(   109.98) },
        { SIMDE_FLOAT32_C(  -255.00), SIMDE_FLOAT32_C(   953.00), SIMDE_FLOAT32_C(  -771.00), SIMDE_FLOAT32_C(   110.00) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t r = simde_wasm_f32x4_ceil(a);
      simde_test_wasm_f32x4_assert_equal(r, simde_wasm_v128_load(test_vec[i].r), 1);
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

      r = simde_wasm_f32x4_ceil(a);

      simde_test_wasm_f32x4_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_f32x4_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_f64x2_ceil(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      simde_float64 a[sizeof(simde_v128_t) / sizeof(simde_float32)];
      simde_float64 r[sizeof(simde_v128_t) / sizeof(simde_float32)];
    } test_vec[8] = {
      #if !defined(SIMDE_FAST_MATH)
      { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   880.91) },
        {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   881.00) } },
      { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   442.61) },
        {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   443.00) } },
      { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   442.61) },
        {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   443.00) } },
      #endif
      { { SIMDE_FLOAT64_C(  -532.09), SIMDE_FLOAT64_C(  -243.41) },
        { SIMDE_FLOAT64_C(  -532.00), SIMDE_FLOAT64_C(  -243.00) } },
      { { SIMDE_FLOAT64_C(   458.58), SIMDE_FLOAT64_C(   510.66) },
        { SIMDE_FLOAT64_C(   459.00), SIMDE_FLOAT64_C(   511.00) } },
      { { SIMDE_FLOAT64_C(   342.86), SIMDE_FLOAT64_C(    -2.47) },
        { SIMDE_FLOAT64_C(   343.00), SIMDE_FLOAT64_C(    -2.00) } },
      { { SIMDE_FLOAT64_C(  -441.97), SIMDE_FLOAT64_C(  -568.59) },
        { SIMDE_FLOAT64_C(  -441.00), SIMDE_FLOAT64_C(  -568.00) } },
      { { SIMDE_FLOAT64_C(  -510.02), SIMDE_FLOAT64_C(   846.02) },
        { SIMDE_FLOAT64_C(  -510.00), SIMDE_FLOAT64_C(   847.00) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t r = simde_wasm_f64x2_ceil(a);
      simde_test_wasm_f64x2_assert_equal(r, simde_wasm_v128_load(test_vec[i].r), 1);
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

      r = simde_wasm_f64x2_ceil(a);

      simde_test_wasm_f64x2_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_f64x2_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_f32x4_ceil)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_f64x2_ceil)
SIMDE_TEST_FUNC_LIST_END

#include "test-simd128-footer.h"
