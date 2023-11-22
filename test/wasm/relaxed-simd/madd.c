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

#define SIMDE_TEST_WASM_RELAXED_SIMD_INSN madd
#include "../../../simde/wasm/relaxed-simd.h"
#include "test-relaxed-simd.h"

static int
test_simde_wasm_f32x4_relaxed_madd(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      simde_float32 a[sizeof(simde_v128_t) / sizeof(simde_float32)];
      simde_float32 b[sizeof(simde_v128_t) / sizeof(simde_float32)];
      simde_float32 c[sizeof(simde_v128_t) / sizeof(simde_float32)];
      simde_float32 r[sizeof(simde_v128_t) / sizeof(simde_float32)];
    } test_vec[] = {
      #if !defined(SIMDE_FAST_MATH)
      { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -939.85),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -336.73) },
        { SIMDE_FLOAT32_C(    40.12),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -336.73) },
        { SIMDE_FLOAT32_C(    40.12),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -336.73) },
        {            SIMDE_MATH_NANF,            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(113050.37) } },
      #endif
      { { SIMDE_FLOAT32_C(   279.46), SIMDE_FLOAT32_C(  -892.17), SIMDE_FLOAT32_C(   472.79), SIMDE_FLOAT32_C(    28.20) },
        { SIMDE_FLOAT32_C(   553.33), SIMDE_FLOAT32_C(   -43.23), SIMDE_FLOAT32_C(   213.29), SIMDE_FLOAT32_C(   976.59) },
        { SIMDE_FLOAT32_C(   553.33), SIMDE_FLOAT32_C(   -43.23), SIMDE_FLOAT32_C(   213.29), SIMDE_FLOAT32_C(   976.59) },
        { SIMDE_FLOAT32_C(155186.94), SIMDE_FLOAT32_C( 38525.28), SIMDE_FLOAT32_C(101054.66), SIMDE_FLOAT32_C( 28516.43) } },
      { { SIMDE_FLOAT32_C(  -199.25), SIMDE_FLOAT32_C(   569.13), SIMDE_FLOAT32_C(  -283.83), SIMDE_FLOAT32_C(   765.16) },
        { SIMDE_FLOAT32_C(   566.57), SIMDE_FLOAT32_C(  -354.03), SIMDE_FLOAT32_C(   136.16), SIMDE_FLOAT32_C(  -900.31) },
        { SIMDE_FLOAT32_C(   566.57), SIMDE_FLOAT32_C(  -354.03), SIMDE_FLOAT32_C(   136.16), SIMDE_FLOAT32_C(  -900.31) },
        { SIMDE_FLOAT32_C(-112322.51), SIMDE_FLOAT32_C(-201843.12), SIMDE_FLOAT32_C(-38510.13), SIMDE_FLOAT32_C(-689781.50) } },
      { { SIMDE_FLOAT32_C(  -487.28), SIMDE_FLOAT32_C(   960.14), SIMDE_FLOAT32_C(   549.78), SIMDE_FLOAT32_C(  -162.66) },
        { SIMDE_FLOAT32_C(   999.49), SIMDE_FLOAT32_C(   808.42), SIMDE_FLOAT32_C(  -550.69), SIMDE_FLOAT32_C(   755.10) },
        { SIMDE_FLOAT32_C(   999.49), SIMDE_FLOAT32_C(   808.42), SIMDE_FLOAT32_C(  -550.69), SIMDE_FLOAT32_C(   755.10) },
        { SIMDE_FLOAT32_C(-486032.00), SIMDE_FLOAT32_C(777004.81), SIMDE_FLOAT32_C(-303309.06), SIMDE_FLOAT32_C(-122069.46) } },
      { { SIMDE_FLOAT32_C(   316.95), SIMDE_FLOAT32_C(    30.33), SIMDE_FLOAT32_C(   448.55), SIMDE_FLOAT32_C(  -478.68) },
        { SIMDE_FLOAT32_C(  -465.32), SIMDE_FLOAT32_C(  -429.53), SIMDE_FLOAT32_C(   856.79), SIMDE_FLOAT32_C(  -324.39) },
        { SIMDE_FLOAT32_C(  -465.32), SIMDE_FLOAT32_C(  -429.53), SIMDE_FLOAT32_C(   856.79), SIMDE_FLOAT32_C(  -324.39) },
        { SIMDE_FLOAT32_C(-147948.50), SIMDE_FLOAT32_C(-13457.17), SIMDE_FLOAT32_C(385169.94), SIMDE_FLOAT32_C(154954.62) } },
      { { SIMDE_FLOAT32_C(  -404.93), SIMDE_FLOAT32_C(  -322.42), SIMDE_FLOAT32_C(   198.39), SIMDE_FLOAT32_C(   -16.18) },
        { SIMDE_FLOAT32_C(  -300.14), SIMDE_FLOAT32_C(   744.61), SIMDE_FLOAT32_C(   342.27), SIMDE_FLOAT32_C(  -505.90) },
        { SIMDE_FLOAT32_C(  -300.14), SIMDE_FLOAT32_C(   744.61), SIMDE_FLOAT32_C(   342.27), SIMDE_FLOAT32_C(  -505.90) },
        { SIMDE_FLOAT32_C(121235.55), SIMDE_FLOAT32_C(-239332.55), SIMDE_FLOAT32_C( 68245.21), SIMDE_FLOAT32_C(  7679.56) } },
      { { SIMDE_FLOAT32_C(  -560.16), SIMDE_FLOAT32_C(  -586.90), SIMDE_FLOAT32_C(   -54.15), SIMDE_FLOAT32_C(  -277.30) },
        { SIMDE_FLOAT32_C(  -912.30), SIMDE_FLOAT32_C(  -170.24), SIMDE_FLOAT32_C(  -166.55), SIMDE_FLOAT32_C(  -308.02) },
        { SIMDE_FLOAT32_C(  -912.30), SIMDE_FLOAT32_C(  -170.24), SIMDE_FLOAT32_C(  -166.55), SIMDE_FLOAT32_C(  -308.02) },
        { SIMDE_FLOAT32_C(510121.62), SIMDE_FLOAT32_C( 99743.62), SIMDE_FLOAT32_C(  8852.13), SIMDE_FLOAT32_C( 85105.92) } },
      { { SIMDE_FLOAT32_C(   547.49), SIMDE_FLOAT32_C(   -51.58), SIMDE_FLOAT32_C(  -417.07), SIMDE_FLOAT32_C(  -866.44) },
        { SIMDE_FLOAT32_C(   143.24), SIMDE_FLOAT32_C(   483.80), SIMDE_FLOAT32_C(  -548.74), SIMDE_FLOAT32_C(  -665.65) },
        { SIMDE_FLOAT32_C(   143.24), SIMDE_FLOAT32_C(   483.80), SIMDE_FLOAT32_C(  -548.74), SIMDE_FLOAT32_C(  -665.65) },
        { SIMDE_FLOAT32_C( 78565.71), SIMDE_FLOAT32_C(-24470.60), SIMDE_FLOAT32_C(228314.25), SIMDE_FLOAT32_C(576080.19) } },
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t c = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_f32x4_relaxed_madd(a, b, c);
      simde_test_wasm_f32x4_assert_equal(r, simde_wasm_v128_load(test_vec[i].r), 1);
    }
    return 0;
  #else
    simde_float32 inputs[8 * 2 * (sizeof(simde_v128_t) / sizeof(simde_float32))];
    simde_test_wasm_f32x4_random_full(8, 2, inputs, -SIMDE_FLOAT32_C(1000.0), SIMDE_FLOAT32_C(1000.0), HEDLEY_STATIC_CAST(SimdeTestVecFloatType, SIMDE_TEST_VEC_FLOAT_NAN | SIMDE_TEST_VEC_FLOAT_EQUAL));
    fputc('\n', stdout);
    for (size_t i = 0 ; i < 8 ; i++) {
      simde_v128_t
        a = simde_test_wasm_f32x4_random_full_extract(2, inputs, i, 0),
        b = simde_test_wasm_f32x4_random_full_extract(2, inputs, i, 1),
        c = simde_test_wasm_f32x4_random_full_extract(2, inputs, i, 1),
        r;

      r = simde_wasm_f32x4_relaxed_madd(a, b, c);

      simde_test_wasm_f32x4_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_f32x4_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_f32x4_write(3, c, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_f32x4_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_f64x2_relaxed_madd(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      simde_float64 a[sizeof(simde_v128_t) / sizeof(simde_float64)];
      simde_float64 b[sizeof(simde_v128_t) / sizeof(simde_float64)];
      simde_float64 c[sizeof(simde_v128_t) / sizeof(simde_float64)];
      simde_float64 r[sizeof(simde_v128_t) / sizeof(simde_float64)];
    } test_vec[] = {
      #if !defined(SIMDE_FAST_MATH)
      { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   695.24) },
        { SIMDE_FLOAT64_C(  -758.15),             SIMDE_MATH_NAN },
        { SIMDE_FLOAT64_C(  -758.15),             SIMDE_MATH_NAN },
        {             SIMDE_MATH_NAN,             SIMDE_MATH_NAN } },
      { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -844.22) },
        {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   363.37) },
        {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   363.37) },
        {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(-306400.85) } },
      #endif
      { { SIMDE_FLOAT64_C(   509.66), SIMDE_FLOAT64_C(  -400.49) },
        { SIMDE_FLOAT64_C(   163.04), SIMDE_FLOAT64_C(  -942.79) },
        { SIMDE_FLOAT64_C(   163.04), SIMDE_FLOAT64_C(  -942.79) },
        { SIMDE_FLOAT64_C( 83258.01), SIMDE_FLOAT64_C(376635.18) } },
      { { SIMDE_FLOAT64_C(   604.83), SIMDE_FLOAT64_C(   -31.05) },
        { SIMDE_FLOAT64_C(  -523.11), SIMDE_FLOAT64_C(   762.22) },
        { SIMDE_FLOAT64_C(  -523.11), SIMDE_FLOAT64_C(   762.22) },
        { SIMDE_FLOAT64_C(-316915.73), SIMDE_FLOAT64_C(-22904.71) } },
      { { SIMDE_FLOAT64_C(   387.14), SIMDE_FLOAT64_C(   293.35) },
        { SIMDE_FLOAT64_C(  -114.01), SIMDE_FLOAT64_C(    60.86) },
        { SIMDE_FLOAT64_C(  -114.01), SIMDE_FLOAT64_C(    60.86) },
        { SIMDE_FLOAT64_C(-44251.84), SIMDE_FLOAT64_C( 17914.14) } },
      { { SIMDE_FLOAT64_C(   711.99), SIMDE_FLOAT64_C(   494.07) },
        { SIMDE_FLOAT64_C(  -456.08), SIMDE_FLOAT64_C(  -781.46) },
        { SIMDE_FLOAT64_C(  -456.08), SIMDE_FLOAT64_C(  -781.46) },
        { SIMDE_FLOAT64_C(-325180.48), SIMDE_FLOAT64_C(-386877.40) } },
      { { SIMDE_FLOAT64_C(  -231.37), SIMDE_FLOAT64_C(  -589.48) },
        { SIMDE_FLOAT64_C(  -349.94), SIMDE_FLOAT64_C(  -420.17) },
        { SIMDE_FLOAT64_C(  -349.94), SIMDE_FLOAT64_C(  -420.17) },
        { SIMDE_FLOAT64_C( 80615.68), SIMDE_FLOAT64_C(247261.64) } },
      { { SIMDE_FLOAT64_C(  -293.55), SIMDE_FLOAT64_C(   337.68) },
        { SIMDE_FLOAT64_C(  -803.44), SIMDE_FLOAT64_C(  -266.96) },
        { SIMDE_FLOAT64_C(  -803.44), SIMDE_FLOAT64_C(  -266.96) },
        { SIMDE_FLOAT64_C(235046.37), SIMDE_FLOAT64_C(-90414.01) } },
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t c = simde_wasm_v128_load(test_vec[i].c);
      simde_v128_t r = simde_wasm_f64x2_relaxed_madd(a, b, c);
      simde_test_wasm_f64x2_assert_equal(r, simde_wasm_v128_load(test_vec[i].r), 1);
    }
    return 0;
  #else
    simde_float64 inputs[8 * 2 * (sizeof(simde_v128_t) / sizeof(simde_float64))];
    simde_test_wasm_f64x2_random_full(8, 2, inputs, -SIMDE_FLOAT64_C(1000.0), SIMDE_FLOAT64_C(1000.0), HEDLEY_STATIC_CAST(SimdeTestVecFloatType, SIMDE_TEST_VEC_FLOAT_NAN));
    fputc('\n', stdout);
    for (size_t i = 0 ; i < 8 ; i++) {
      simde_v128_t
        a = simde_test_wasm_f64x2_random_full_extract(2, inputs, i, 0),
        b = simde_test_wasm_f64x2_random_full_extract(2, inputs, i, 1),
        c = simde_test_wasm_f64x2_random_full_extract(2, inputs, i, 1),
        r;

      r = simde_wasm_f64x2_relaxed_madd(a, b, c);

      simde_test_wasm_f64x2_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_f64x2_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_f64x2_write(3, c, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_f64x2_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_f32x4_relaxed_madd)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_f64x2_relaxed_madd)
SIMDE_TEST_FUNC_LIST_END

#include "test-relaxed-simd-footer.h"
