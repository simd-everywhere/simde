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

#define SIMDE_TEST_WASM_SIMD128_INSN pmin
#include "../../../simde/wasm/simd128.h"
#include "test-simd128.h"

static int
test_simde_wasm_f32x4_pmin(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      simde_float32 a[sizeof(simde_v128_t) / sizeof(simde_float32)];
      simde_float32 b[sizeof(simde_v128_t) / sizeof(simde_float32)];
      simde_float32 r[sizeof(simde_v128_t) / sizeof(simde_float32)];
    } test_vec[] = {
      #if !defined(SIMDE_FAST_MATH)
      { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   828.91),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   761.51) },
        { SIMDE_FLOAT32_C(  -227.99),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   761.51) },
        {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   828.91),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   761.51) } },
      #endif
      { { SIMDE_FLOAT32_C(   650.36), SIMDE_FLOAT32_C(   717.68), SIMDE_FLOAT32_C(   591.62), SIMDE_FLOAT32_C(  -644.46) },
        { SIMDE_FLOAT32_C(   828.08), SIMDE_FLOAT32_C(   182.00), SIMDE_FLOAT32_C(  -943.41), SIMDE_FLOAT32_C(  -206.34) },
        { SIMDE_FLOAT32_C(   650.36), SIMDE_FLOAT32_C(   182.00), SIMDE_FLOAT32_C(  -943.41), SIMDE_FLOAT32_C(  -644.46) } },
      { { SIMDE_FLOAT32_C(  -541.51), SIMDE_FLOAT32_C(   187.56), SIMDE_FLOAT32_C(    69.44), SIMDE_FLOAT32_C(  -366.17) },
        { SIMDE_FLOAT32_C(   762.62), SIMDE_FLOAT32_C(    39.47), SIMDE_FLOAT32_C(   428.07), SIMDE_FLOAT32_C(  -589.61) },
        { SIMDE_FLOAT32_C(  -541.51), SIMDE_FLOAT32_C(    39.47), SIMDE_FLOAT32_C(    69.44), SIMDE_FLOAT32_C(  -589.61) } },
      { { SIMDE_FLOAT32_C(  -812.58), SIMDE_FLOAT32_C(  -247.73), SIMDE_FLOAT32_C(  -206.07), SIMDE_FLOAT32_C(  -422.83) },
        { SIMDE_FLOAT32_C(  -632.28), SIMDE_FLOAT32_C(   953.16), SIMDE_FLOAT32_C(   408.52), SIMDE_FLOAT32_C(  -209.82) },
        { SIMDE_FLOAT32_C(  -812.58), SIMDE_FLOAT32_C(  -247.73), SIMDE_FLOAT32_C(  -206.07), SIMDE_FLOAT32_C(  -422.83) } },
      { { SIMDE_FLOAT32_C(  -887.28), SIMDE_FLOAT32_C(  -647.27), SIMDE_FLOAT32_C(   368.98), SIMDE_FLOAT32_C(  -191.55) },
        { SIMDE_FLOAT32_C(   -26.80), SIMDE_FLOAT32_C(   104.44), SIMDE_FLOAT32_C(  -417.04), SIMDE_FLOAT32_C(   697.41) },
        { SIMDE_FLOAT32_C(  -887.28), SIMDE_FLOAT32_C(  -647.27), SIMDE_FLOAT32_C(  -417.04), SIMDE_FLOAT32_C(  -191.55) } },
      { { SIMDE_FLOAT32_C(  -938.72), SIMDE_FLOAT32_C(  -519.77), SIMDE_FLOAT32_C(  -976.52), SIMDE_FLOAT32_C(   794.95) },
        { SIMDE_FLOAT32_C(  -146.14), SIMDE_FLOAT32_C(  -306.67), SIMDE_FLOAT32_C(  -120.29), SIMDE_FLOAT32_C(  -480.59) },
        { SIMDE_FLOAT32_C(  -938.72), SIMDE_FLOAT32_C(  -519.77), SIMDE_FLOAT32_C(  -976.52), SIMDE_FLOAT32_C(  -480.59) } },
      { { SIMDE_FLOAT32_C(   791.76), SIMDE_FLOAT32_C(   836.81), SIMDE_FLOAT32_C(   596.61), SIMDE_FLOAT32_C(  -573.55) },
        { SIMDE_FLOAT32_C(   577.09), SIMDE_FLOAT32_C(  -215.42), SIMDE_FLOAT32_C(   427.90), SIMDE_FLOAT32_C(  -702.09) },
        { SIMDE_FLOAT32_C(   577.09), SIMDE_FLOAT32_C(  -215.42), SIMDE_FLOAT32_C(   427.90), SIMDE_FLOAT32_C(  -702.09) } },
      { { SIMDE_FLOAT32_C(   -45.18), SIMDE_FLOAT32_C(   834.74), SIMDE_FLOAT32_C(  -898.81), SIMDE_FLOAT32_C(    75.84) },
        { SIMDE_FLOAT32_C(  -270.81), SIMDE_FLOAT32_C(   764.85), SIMDE_FLOAT32_C(  -371.88), SIMDE_FLOAT32_C(  -230.26) },
        { SIMDE_FLOAT32_C(  -270.81), SIMDE_FLOAT32_C(   764.85), SIMDE_FLOAT32_C(  -898.81), SIMDE_FLOAT32_C(  -230.26) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_f32x4_pmin(a, b);
      simde_test_wasm_f32x4_assert_equal(r, simde_wasm_v128_load(test_vec[i].r), INT_MAX);
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

      r = simde_wasm_f32x4_pmin(a, b);

      simde_test_wasm_f32x4_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_f32x4_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_f32x4_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_f64x2_pmin(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      simde_float64 a[sizeof(simde_v128_t) / sizeof(simde_float64)];
      simde_float64 b[sizeof(simde_v128_t) / sizeof(simde_float64)];
      simde_float64 r[sizeof(simde_v128_t) / sizeof(simde_float64)];
    } test_vec[] = {
      #if !defined(SIMDE_FAST_MATH)
      { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -417.99) },
        { SIMDE_FLOAT64_C(   -60.35),             SIMDE_MATH_NAN },
        {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -417.99) } },
      { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -870.89) },
        {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   -30.83) },
        {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -870.89) } },
      #endif
      { { SIMDE_FLOAT64_C(  -428.61), SIMDE_FLOAT64_C(  -289.77) },
        { SIMDE_FLOAT64_C(  -856.42), SIMDE_FLOAT64_C(   986.32) },
        { SIMDE_FLOAT64_C(  -856.42), SIMDE_FLOAT64_C(  -289.77) } },
      { { SIMDE_FLOAT64_C(   282.94), SIMDE_FLOAT64_C(   717.32) },
        { SIMDE_FLOAT64_C(  -484.84), SIMDE_FLOAT64_C(   658.43) },
        { SIMDE_FLOAT64_C(  -484.84), SIMDE_FLOAT64_C(   658.43) } },
      { { SIMDE_FLOAT64_C(  -813.80), SIMDE_FLOAT64_C(  -234.99) },
        { SIMDE_FLOAT64_C(  -908.46), SIMDE_FLOAT64_C(   322.95) },
        { SIMDE_FLOAT64_C(  -908.46), SIMDE_FLOAT64_C(  -234.99) } },
      { { SIMDE_FLOAT64_C(  -980.96), SIMDE_FLOAT64_C(  -804.82) },
        { SIMDE_FLOAT64_C(  -296.46), SIMDE_FLOAT64_C(  -634.49) },
        { SIMDE_FLOAT64_C(  -980.96), SIMDE_FLOAT64_C(  -804.82) } },
      { { SIMDE_FLOAT64_C(   529.25), SIMDE_FLOAT64_C(   760.48) },
        { SIMDE_FLOAT64_C(   196.32), SIMDE_FLOAT64_C(   844.49) },
        { SIMDE_FLOAT64_C(   196.32), SIMDE_FLOAT64_C(   760.48) } },
      { { SIMDE_FLOAT64_C(   271.96), SIMDE_FLOAT64_C(   393.85) },
        { SIMDE_FLOAT64_C(   496.42), SIMDE_FLOAT64_C(   430.15) },
        { SIMDE_FLOAT64_C(   271.96), SIMDE_FLOAT64_C(   393.85) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_f64x2_pmin(a, b);
      simde_test_wasm_f64x2_assert_equal(r, simde_wasm_v128_load(test_vec[i].r), INT_MAX);
    }
    return 0;
  #else
    fputc('\n', stdout);
    simde_float64 inputs[8 * 2 * (sizeof(simde_v128_t) / sizeof(simde_float64))];
    simde_test_wasm_f64x2_random_full(8, 2, inputs, -SIMDE_FLOAT64_C(1000.0), SIMDE_FLOAT64_C(1000.0), HEDLEY_STATIC_CAST(SimdeTestVecFloatType, SIMDE_TEST_VEC_FLOAT_NAN));
    for (size_t i = 0 ; i < 8 ; i++) {
      simde_v128_t
        a = simde_test_wasm_f64x2_random_full_extract(2, inputs, i, 0),
        b = simde_test_wasm_f64x2_random_full_extract(2, inputs, i, 1),
        r;

      r = simde_wasm_f64x2_pmin(a, b);

      simde_test_wasm_f64x2_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_f64x2_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_f64x2_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_f32x4_pmin)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_f64x2_pmin)
SIMDE_TEST_FUNC_LIST_END

#include "test-simd128-footer.h"
