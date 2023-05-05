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

#define SIMDE_TEST_WASM_SIMD128_INSN pmax
#include "../../../simde/wasm/simd128.h"
#include "test-simd128.h"

static int
test_simde_wasm_f32x4_pmax(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      simde_float32 a[sizeof(simde_v128_t) / sizeof(simde_float32)];
      simde_float32 b[sizeof(simde_v128_t) / sizeof(simde_float32)];
      simde_float32 r[sizeof(simde_v128_t) / sizeof(simde_float32)];
    } test_vec[] = {
      #if !defined(SIMDE_FAST_MATH)
      { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -885.39),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   707.75) },
        { SIMDE_FLOAT32_C(   501.91),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   707.75) },
        {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -885.39),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   707.75) } },
      #endif
      { { SIMDE_FLOAT32_C(  -459.57), SIMDE_FLOAT32_C(   963.55), SIMDE_FLOAT32_C(   495.86), SIMDE_FLOAT32_C(    52.00) },
        { SIMDE_FLOAT32_C(   633.73), SIMDE_FLOAT32_C(   -93.23), SIMDE_FLOAT32_C(  -508.20), SIMDE_FLOAT32_C(   577.11) },
        { SIMDE_FLOAT32_C(   633.73), SIMDE_FLOAT32_C(   963.55), SIMDE_FLOAT32_C(   495.86), SIMDE_FLOAT32_C(   577.11) } },
      { { SIMDE_FLOAT32_C(   687.52), SIMDE_FLOAT32_C(  -449.26), SIMDE_FLOAT32_C(   179.94), SIMDE_FLOAT32_C(  -335.42) },
        { SIMDE_FLOAT32_C(   -32.35), SIMDE_FLOAT32_C(   726.31), SIMDE_FLOAT32_C(  -992.54), SIMDE_FLOAT32_C(   832.20) },
        { SIMDE_FLOAT32_C(   687.52), SIMDE_FLOAT32_C(   726.31), SIMDE_FLOAT32_C(   179.94), SIMDE_FLOAT32_C(   832.20) } },
      { { SIMDE_FLOAT32_C(  -135.22), SIMDE_FLOAT32_C(  -496.49), SIMDE_FLOAT32_C(   841.54), SIMDE_FLOAT32_C(  -404.92) },
        { SIMDE_FLOAT32_C(   647.00), SIMDE_FLOAT32_C(   673.27), SIMDE_FLOAT32_C(  -389.20), SIMDE_FLOAT32_C(   520.27) },
        { SIMDE_FLOAT32_C(   647.00), SIMDE_FLOAT32_C(   673.27), SIMDE_FLOAT32_C(   841.54), SIMDE_FLOAT32_C(   520.27) } },
      { { SIMDE_FLOAT32_C(   119.83), SIMDE_FLOAT32_C(   208.86), SIMDE_FLOAT32_C(     1.95), SIMDE_FLOAT32_C(  -406.07) },
        { SIMDE_FLOAT32_C(    30.97), SIMDE_FLOAT32_C(  -687.73), SIMDE_FLOAT32_C(  -133.28), SIMDE_FLOAT32_C(   173.81) },
        { SIMDE_FLOAT32_C(   119.83), SIMDE_FLOAT32_C(   208.86), SIMDE_FLOAT32_C(     1.95), SIMDE_FLOAT32_C(   173.81) } },
      { { SIMDE_FLOAT32_C(   374.67), SIMDE_FLOAT32_C(    12.15), SIMDE_FLOAT32_C(  -143.53), SIMDE_FLOAT32_C(  -662.06) },
        { SIMDE_FLOAT32_C(   870.79), SIMDE_FLOAT32_C(   -42.64), SIMDE_FLOAT32_C(    40.57), SIMDE_FLOAT32_C(  -642.17) },
        { SIMDE_FLOAT32_C(   870.79), SIMDE_FLOAT32_C(    12.15), SIMDE_FLOAT32_C(    40.57), SIMDE_FLOAT32_C(  -642.17) } },
      { { SIMDE_FLOAT32_C(   519.42), SIMDE_FLOAT32_C(  -525.62), SIMDE_FLOAT32_C(  -165.62), SIMDE_FLOAT32_C(   357.40) },
        { SIMDE_FLOAT32_C(   675.10), SIMDE_FLOAT32_C(   258.75), SIMDE_FLOAT32_C(   647.35), SIMDE_FLOAT32_C(  -789.86) },
        { SIMDE_FLOAT32_C(   675.10), SIMDE_FLOAT32_C(   258.75), SIMDE_FLOAT32_C(   647.35), SIMDE_FLOAT32_C(   357.40) } },
      { { SIMDE_FLOAT32_C(  -110.34), SIMDE_FLOAT32_C(   138.38), SIMDE_FLOAT32_C(   511.34), SIMDE_FLOAT32_C(   273.51) },
        { SIMDE_FLOAT32_C(   180.04), SIMDE_FLOAT32_C(   655.24), SIMDE_FLOAT32_C(   911.37), SIMDE_FLOAT32_C(  -134.01) },
        { SIMDE_FLOAT32_C(   180.04), SIMDE_FLOAT32_C(   655.24), SIMDE_FLOAT32_C(   911.37), SIMDE_FLOAT32_C(   273.51) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_f32x4_pmax(a, b);
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

      r = simde_wasm_f32x4_pmax(a, b);

      simde_test_wasm_f32x4_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_f32x4_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_f32x4_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_f64x2_pmax(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      simde_float64 a[sizeof(simde_v128_t) / sizeof(simde_float64)];
      simde_float64 b[sizeof(simde_v128_t) / sizeof(simde_float64)];
      simde_float64 r[sizeof(simde_v128_t) / sizeof(simde_float64)];
    } test_vec[] = {
      #if !defined(SIMDE_FAST_MATH)
      { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   532.24) },
        { SIMDE_FLOAT64_C(  -760.30),             SIMDE_MATH_NAN },
        {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   532.24) } },
      { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -933.07) },
        {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   612.03) },
        {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   612.03) } },
      #endif
      { { SIMDE_FLOAT64_C(   433.73), SIMDE_FLOAT64_C(  -170.33) },
        { SIMDE_FLOAT64_C(    49.15), SIMDE_FLOAT64_C(   237.35) },
        { SIMDE_FLOAT64_C(   433.73), SIMDE_FLOAT64_C(   237.35) } },
      { { SIMDE_FLOAT64_C(  -786.82), SIMDE_FLOAT64_C(   621.97) },
        { SIMDE_FLOAT64_C(   120.40), SIMDE_FLOAT64_C(  -455.15) },
        { SIMDE_FLOAT64_C(   120.40), SIMDE_FLOAT64_C(   621.97) } },
      { { SIMDE_FLOAT64_C(   364.97), SIMDE_FLOAT64_C(   895.21) },
        { SIMDE_FLOAT64_C(  -132.45), SIMDE_FLOAT64_C(  -994.86) },
        { SIMDE_FLOAT64_C(   364.97), SIMDE_FLOAT64_C(   895.21) } },
      { { SIMDE_FLOAT64_C(   618.82), SIMDE_FLOAT64_C(  -909.81) },
        { SIMDE_FLOAT64_C(  -266.98), SIMDE_FLOAT64_C(   -61.40) },
        { SIMDE_FLOAT64_C(   618.82), SIMDE_FLOAT64_C(   -61.40) } },
      { { SIMDE_FLOAT64_C(    99.95), SIMDE_FLOAT64_C(  -338.47) },
        { SIMDE_FLOAT64_C(  -400.77), SIMDE_FLOAT64_C(  -639.67) },
        { SIMDE_FLOAT64_C(    99.95), SIMDE_FLOAT64_C(  -338.47) } },
      { { SIMDE_FLOAT64_C(  -842.14), SIMDE_FLOAT64_C(   598.58) },
        { SIMDE_FLOAT64_C(  -227.00), SIMDE_FLOAT64_C(  -228.59) },
        { SIMDE_FLOAT64_C(  -227.00), SIMDE_FLOAT64_C(   598.58) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_f64x2_pmax(a, b);
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

      r = simde_wasm_f64x2_pmax(a, b);

      simde_test_wasm_f64x2_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_f64x2_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_f64x2_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_f32x4_pmax)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_f64x2_pmax)
SIMDE_TEST_FUNC_LIST_END

#include "test-simd128-footer.h"
