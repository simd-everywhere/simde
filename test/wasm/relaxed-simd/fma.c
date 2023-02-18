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

#define SIMDE_TEST_WASM_RELAXED_SIMD_INSN fma
#include "../../../simde/wasm/relaxed-simd.h"
#include "test-relaxed-simd.h"

static int
test_simde_wasm_f32x4_fma(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      simde_float32 a[sizeof(simde_v128_t) / sizeof(simde_float32)];
      simde_float32 b[sizeof(simde_v128_t) / sizeof(simde_float32)];
      simde_float32 c[sizeof(simde_v128_t) / sizeof(simde_float32)];
      simde_float32 r[sizeof(simde_v128_t) / sizeof(simde_float32)];
    } test_vec[] = {
      #if !defined(SIMDE_FAST_MATH)
      { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(    35.68),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -774.53) },
        { SIMDE_FLOAT32_C(   759.66),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -774.53) },
        { SIMDE_FLOAT32_C(   759.66),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -774.53) },
        {            SIMDE_MATH_NANF,            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(599122.25) } },
      #endif
      { { SIMDE_FLOAT32_C(   718.59), SIMDE_FLOAT32_C(  -622.20), SIMDE_FLOAT32_C(   -12.71), SIMDE_FLOAT32_C(   145.90) },
        { SIMDE_FLOAT32_C(   493.69), SIMDE_FLOAT32_C(  -413.24), SIMDE_FLOAT32_C(  -414.24), SIMDE_FLOAT32_C(   394.66) },
        { SIMDE_FLOAT32_C(   493.69), SIMDE_FLOAT32_C(  -413.24), SIMDE_FLOAT32_C(  -414.24), SIMDE_FLOAT32_C(   394.66) },
        { SIMDE_FLOAT32_C(244448.41), SIMDE_FLOAT32_C(170145.09), SIMDE_FLOAT32_C(171582.06), SIMDE_FLOAT32_C(155902.42) } },
      { { SIMDE_FLOAT32_C(   308.42), SIMDE_FLOAT32_C(    86.05), SIMDE_FLOAT32_C(   150.72), SIMDE_FLOAT32_C(  -861.13) },
        { SIMDE_FLOAT32_C(  -705.94), SIMDE_FLOAT32_C(   541.94), SIMDE_FLOAT32_C(  -888.14), SIMDE_FLOAT32_C(   233.26) },
        { SIMDE_FLOAT32_C(  -705.94), SIMDE_FLOAT32_C(   541.94), SIMDE_FLOAT32_C(  -888.14), SIMDE_FLOAT32_C(   233.26) },
        { SIMDE_FLOAT32_C(498659.69), SIMDE_FLOAT32_C(293785.03), SIMDE_FLOAT32_C(788943.44), SIMDE_FLOAT32_C( 53549.10) } },
      { { SIMDE_FLOAT32_C(  -756.83), SIMDE_FLOAT32_C(   995.47), SIMDE_FLOAT32_C(   603.58), SIMDE_FLOAT32_C(  -894.80) },
        { SIMDE_FLOAT32_C(  -794.79), SIMDE_FLOAT32_C(    27.52), SIMDE_FLOAT32_C(  -472.09), SIMDE_FLOAT32_C(  -978.18) },
        { SIMDE_FLOAT32_C(  -794.79), SIMDE_FLOAT32_C(    27.52), SIMDE_FLOAT32_C(  -472.09), SIMDE_FLOAT32_C(  -978.18) },
        { SIMDE_FLOAT32_C(630934.31), SIMDE_FLOAT32_C(  1752.82), SIMDE_FLOAT32_C(223472.55), SIMDE_FLOAT32_C(955941.31) } },
      { { SIMDE_FLOAT32_C(  -936.80), SIMDE_FLOAT32_C(  -668.74), SIMDE_FLOAT32_C(   863.15), SIMDE_FLOAT32_C(   822.85) },
        { SIMDE_FLOAT32_C(   593.95), SIMDE_FLOAT32_C(    59.13), SIMDE_FLOAT32_C(   718.77), SIMDE_FLOAT32_C(   312.54) },
        { SIMDE_FLOAT32_C(   593.95), SIMDE_FLOAT32_C(    59.13), SIMDE_FLOAT32_C(   718.77), SIMDE_FLOAT32_C(   312.54) },
        { SIMDE_FLOAT32_C(351839.81), SIMDE_FLOAT32_C(  2827.62), SIMDE_FLOAT32_C(517493.50), SIMDE_FLOAT32_C( 98504.11) } },
      { { SIMDE_FLOAT32_C(   436.93), SIMDE_FLOAT32_C(  -293.94), SIMDE_FLOAT32_C(  -541.56), SIMDE_FLOAT32_C(   -69.39) },
        { SIMDE_FLOAT32_C(   292.82), SIMDE_FLOAT32_C(    44.21), SIMDE_FLOAT32_C(  -674.72), SIMDE_FLOAT32_C(  -398.76) },
        { SIMDE_FLOAT32_C(   292.82), SIMDE_FLOAT32_C(    44.21), SIMDE_FLOAT32_C(  -674.72), SIMDE_FLOAT32_C(  -398.76) },
        { SIMDE_FLOAT32_C( 86180.48), SIMDE_FLOAT32_C(  1660.58), SIMDE_FLOAT32_C(454705.47), SIMDE_FLOAT32_C(158940.16) } },
      { { SIMDE_FLOAT32_C(  -869.74), SIMDE_FLOAT32_C(   475.99), SIMDE_FLOAT32_C(  -259.88), SIMDE_FLOAT32_C(  -575.68) },
        { SIMDE_FLOAT32_C(    17.93), SIMDE_FLOAT32_C(  -148.02), SIMDE_FLOAT32_C(   657.58), SIMDE_FLOAT32_C(   261.10) },
        { SIMDE_FLOAT32_C(    17.93), SIMDE_FLOAT32_C(  -148.02), SIMDE_FLOAT32_C(   657.58), SIMDE_FLOAT32_C(   261.10) },
        { SIMDE_FLOAT32_C(  -548.26), SIMDE_FLOAT32_C( 22385.91), SIMDE_FLOAT32_C(432151.59), SIMDE_FLOAT32_C( 67597.53) } },
      { { SIMDE_FLOAT32_C(  -152.55), SIMDE_FLOAT32_C(   261.17), SIMDE_FLOAT32_C(   366.30), SIMDE_FLOAT32_C(    52.65) },
        { SIMDE_FLOAT32_C(  -711.32), SIMDE_FLOAT32_C(   894.21), SIMDE_FLOAT32_C(    74.47), SIMDE_FLOAT32_C(  -648.12) },
        { SIMDE_FLOAT32_C(  -711.32), SIMDE_FLOAT32_C(   894.21), SIMDE_FLOAT32_C(    74.47), SIMDE_FLOAT32_C(  -648.12) },
        { SIMDE_FLOAT32_C(505823.59), SIMDE_FLOAT32_C(799872.75), SIMDE_FLOAT32_C(  5912.08), SIMDE_FLOAT32_C(420112.19) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t c = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_f32x4_fma(a, b, c);
      simde_test_wasm_f32x4_assert_equal(r, simde_wasm_v128_load(test_vec[i].r), 1);
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
        c = simde_test_wasm_f32x4_random_full_extract(2, inputs, i, 1),
        r;

      r = simde_wasm_f32x4_fma(a, b, c);

      simde_test_wasm_f32x4_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_f32x4_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_f32x4_write(3, c, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_f32x4_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_f64x2_fma(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      simde_float64 a[sizeof(simde_v128_t) / sizeof(simde_float64)];
      simde_float64 b[sizeof(simde_v128_t) / sizeof(simde_float64)];
      simde_float64 c[sizeof(simde_v128_t) / sizeof(simde_float64)];
      simde_float64 r[sizeof(simde_v128_t) / sizeof(simde_float64)];
    } test_vec[] = {
      #if !defined(SIMDE_FAST_MATH)
      { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -621.40) },
        { SIMDE_FLOAT64_C(    52.22),             SIMDE_MATH_NAN },
        { SIMDE_FLOAT64_C(    52.22),             SIMDE_MATH_NAN },
        {             SIMDE_MATH_NAN,             SIMDE_MATH_NAN } },
      { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -435.92) },
        {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   407.34) },
        {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   407.34) },
        {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(165489.96) } },
      #endif
      { { SIMDE_FLOAT64_C(  -930.00), SIMDE_FLOAT64_C(  -720.45) },
        { SIMDE_FLOAT64_C(    96.66), SIMDE_FLOAT64_C(   326.47) },
        { SIMDE_FLOAT64_C(    96.66), SIMDE_FLOAT64_C(   326.47) },
        { SIMDE_FLOAT64_C(  8413.16), SIMDE_FLOAT64_C(105862.21) } },
      { { SIMDE_FLOAT64_C(   -52.84), SIMDE_FLOAT64_C(   875.57) },
        { SIMDE_FLOAT64_C(  -832.42), SIMDE_FLOAT64_C(  -266.54) },
        { SIMDE_FLOAT64_C(  -832.42), SIMDE_FLOAT64_C(  -266.54) },
        { SIMDE_FLOAT64_C(692870.22), SIMDE_FLOAT64_C( 71919.14) } },
      { { SIMDE_FLOAT64_C(   582.06), SIMDE_FLOAT64_C(   390.67) },
        { SIMDE_FLOAT64_C(   713.92), SIMDE_FLOAT64_C(  -481.53) },
        { SIMDE_FLOAT64_C(   713.92), SIMDE_FLOAT64_C(  -481.53) },
        { SIMDE_FLOAT64_C(510263.83), SIMDE_FLOAT64_C(232261.81) } },
      { { SIMDE_FLOAT64_C(   246.83), SIMDE_FLOAT64_C(  -742.77) },
        { SIMDE_FLOAT64_C(   332.12), SIMDE_FLOAT64_C(  -798.45) },
        { SIMDE_FLOAT64_C(   332.12), SIMDE_FLOAT64_C(  -798.45) },
        { SIMDE_FLOAT64_C(110550.52), SIMDE_FLOAT64_C(636779.63) } },
      { { SIMDE_FLOAT64_C(   180.40), SIMDE_FLOAT64_C(  -132.97) },
        { SIMDE_FLOAT64_C(   916.06), SIMDE_FLOAT64_C(   698.44) },
        { SIMDE_FLOAT64_C(   916.06), SIMDE_FLOAT64_C(   698.44) },
        { SIMDE_FLOAT64_C(839346.32), SIMDE_FLOAT64_C(487685.46) } },
      { { SIMDE_FLOAT64_C(   -79.04), SIMDE_FLOAT64_C(   600.83) },
        { SIMDE_FLOAT64_C(  -871.27), SIMDE_FLOAT64_C(   389.47) },
        { SIMDE_FLOAT64_C(  -871.27), SIMDE_FLOAT64_C(   389.47) },
        { SIMDE_FLOAT64_C(759032.37), SIMDE_FLOAT64_C(152287.71) } },
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t c = simde_wasm_v128_load(test_vec[i].c);
      simde_v128_t r = simde_wasm_f64x2_fma(a, b, c);
      simde_test_wasm_f64x2_assert_equal(r, simde_wasm_v128_load(test_vec[i].r), 1);
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
        c = simde_test_wasm_f64x2_random_full_extract(2, inputs, i, 1),
        r;

      r = simde_wasm_f64x2_fma(a, b, c);

      simde_test_wasm_f64x2_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_f64x2_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_f64x2_write(3, c, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_f64x2_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_f32x4_fma)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_f64x2_fma)
SIMDE_TEST_FUNC_LIST_END

#include "test-relaxed-simd-footer.h"
