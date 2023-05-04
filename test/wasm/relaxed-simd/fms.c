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

#define SIMDE_TEST_WASM_RELAXED_SIMD_INSN fms
#include "../../../simde/wasm/relaxed-simd.h"
#include "test-relaxed-simd.h"

static int
test_simde_wasm_f32x4_fms(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      simde_float32 a[sizeof(simde_v128_t) / sizeof(simde_float32)];
      simde_float32 b[sizeof(simde_v128_t) / sizeof(simde_float32)];
      simde_float32 c[sizeof(simde_v128_t) / sizeof(simde_float32)];
      simde_float32 r[sizeof(simde_v128_t) / sizeof(simde_float32)];
    } test_vec[] = {
      #if !defined(SIMDE_FAST_MATH)
      { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -993.27),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   417.41) },
        { SIMDE_FLOAT32_C(  -485.37),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   417.41) },
        { SIMDE_FLOAT32_C(  -485.37),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   417.41) },
        {            SIMDE_MATH_NANF,            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(-173813.70) } },
      #endif
      { { SIMDE_FLOAT32_C(  -135.40), SIMDE_FLOAT32_C(   -44.03), SIMDE_FLOAT32_C(   309.21), SIMDE_FLOAT32_C(   776.94) },
        { SIMDE_FLOAT32_C(   285.44), SIMDE_FLOAT32_C(   449.56), SIMDE_FLOAT32_C(   -32.12), SIMDE_FLOAT32_C(   455.56) },
        { SIMDE_FLOAT32_C(   285.44), SIMDE_FLOAT32_C(   449.56), SIMDE_FLOAT32_C(   -32.12), SIMDE_FLOAT32_C(   455.56) },
        { SIMDE_FLOAT32_C(-81611.39), SIMDE_FLOAT32_C(-202148.22), SIMDE_FLOAT32_C(  -722.48), SIMDE_FLOAT32_C(-206757.97) } },
      { { SIMDE_FLOAT32_C(  -255.61), SIMDE_FLOAT32_C(  -375.49), SIMDE_FLOAT32_C(  -500.83), SIMDE_FLOAT32_C(  -933.43) },
        { SIMDE_FLOAT32_C(   338.55), SIMDE_FLOAT32_C(   -93.11), SIMDE_FLOAT32_C(   370.59), SIMDE_FLOAT32_C(  -687.41) },
        { SIMDE_FLOAT32_C(   338.55), SIMDE_FLOAT32_C(   -93.11), SIMDE_FLOAT32_C(   370.59), SIMDE_FLOAT32_C(  -687.41) },
        { SIMDE_FLOAT32_C(-114871.70), SIMDE_FLOAT32_C( -9044.96), SIMDE_FLOAT32_C(-137837.78), SIMDE_FLOAT32_C(-473465.91) } },
      { { SIMDE_FLOAT32_C(   898.51), SIMDE_FLOAT32_C(   628.53), SIMDE_FLOAT32_C(   902.40), SIMDE_FLOAT32_C(    62.33) },
        { SIMDE_FLOAT32_C(  -446.25), SIMDE_FLOAT32_C(   645.33), SIMDE_FLOAT32_C(  -460.63), SIMDE_FLOAT32_C(   754.66) },
        { SIMDE_FLOAT32_C(  -446.25), SIMDE_FLOAT32_C(   645.33), SIMDE_FLOAT32_C(  -460.63), SIMDE_FLOAT32_C(   754.66) },
        { SIMDE_FLOAT32_C(-198240.55), SIMDE_FLOAT32_C(-415822.31), SIMDE_FLOAT32_C(-211277.59), SIMDE_FLOAT32_C(-569449.38) } },
      { { SIMDE_FLOAT32_C(   652.06), SIMDE_FLOAT32_C(   329.68), SIMDE_FLOAT32_C(  -821.45), SIMDE_FLOAT32_C(  -833.31) },
        { SIMDE_FLOAT32_C(  -319.39), SIMDE_FLOAT32_C(   484.50), SIMDE_FLOAT32_C(     1.43), SIMDE_FLOAT32_C(   545.21) },
        { SIMDE_FLOAT32_C(  -319.39), SIMDE_FLOAT32_C(   484.50), SIMDE_FLOAT32_C(     1.43), SIMDE_FLOAT32_C(   545.21) },
        { SIMDE_FLOAT32_C(-101357.92), SIMDE_FLOAT32_C(-234410.56), SIMDE_FLOAT32_C(  -823.49), SIMDE_FLOAT32_C(-298087.28) } },
      { { SIMDE_FLOAT32_C(  -559.53), SIMDE_FLOAT32_C(  -689.36), SIMDE_FLOAT32_C(   322.15), SIMDE_FLOAT32_C(   725.90) },
        { SIMDE_FLOAT32_C(   760.20), SIMDE_FLOAT32_C(  -709.97), SIMDE_FLOAT32_C(   181.46), SIMDE_FLOAT32_C(  -495.41) },
        { SIMDE_FLOAT32_C(   760.20), SIMDE_FLOAT32_C(  -709.97), SIMDE_FLOAT32_C(   181.46), SIMDE_FLOAT32_C(  -495.41) },
        { SIMDE_FLOAT32_C(-578463.56), SIMDE_FLOAT32_C(-504746.72), SIMDE_FLOAT32_C(-32605.58), SIMDE_FLOAT32_C(-244705.17) } },
      { { SIMDE_FLOAT32_C(   -85.45), SIMDE_FLOAT32_C(   680.63), SIMDE_FLOAT32_C(  -428.83), SIMDE_FLOAT32_C(  -746.90) },
        { SIMDE_FLOAT32_C(  -412.48), SIMDE_FLOAT32_C(   941.76), SIMDE_FLOAT32_C(  -434.31), SIMDE_FLOAT32_C(  -513.97) },
        { SIMDE_FLOAT32_C(  -412.48), SIMDE_FLOAT32_C(   941.76), SIMDE_FLOAT32_C(  -434.31), SIMDE_FLOAT32_C(  -513.97) },
        { SIMDE_FLOAT32_C(-170225.22), SIMDE_FLOAT32_C(-886231.31), SIMDE_FLOAT32_C(-189054.00), SIMDE_FLOAT32_C(-264912.03) } },
      { { SIMDE_FLOAT32_C(   570.28), SIMDE_FLOAT32_C(  -531.92), SIMDE_FLOAT32_C(   548.36), SIMDE_FLOAT32_C(  -875.96) },
        { SIMDE_FLOAT32_C(  -886.59), SIMDE_FLOAT32_C(  -912.27), SIMDE_FLOAT32_C(   878.70), SIMDE_FLOAT32_C(   765.47) },
        { SIMDE_FLOAT32_C(  -886.59), SIMDE_FLOAT32_C(  -912.27), SIMDE_FLOAT32_C(   878.70), SIMDE_FLOAT32_C(   765.47) },
        { SIMDE_FLOAT32_C(-785471.62), SIMDE_FLOAT32_C(-832768.50), SIMDE_FLOAT32_C(-771565.31), SIMDE_FLOAT32_C(-586820.19) } },
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t c = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_f32x4_fms(a, b, c);
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

      r = simde_wasm_f32x4_fms(a, b, c);

      simde_test_wasm_f32x4_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_f32x4_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_f32x4_write(3, c, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_f32x4_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_f64x2_fms(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      simde_float64 a[sizeof(simde_v128_t) / sizeof(simde_float64)];
      simde_float64 b[sizeof(simde_v128_t) / sizeof(simde_float64)];
      simde_float64 c[sizeof(simde_v128_t) / sizeof(simde_float64)];
      simde_float64 r[sizeof(simde_v128_t) / sizeof(simde_float64)];
    } test_vec[] = {
      #if !defined(SIMDE_FAST_MATH)
      { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   932.16) },
        { SIMDE_FLOAT64_C(  -901.98),             SIMDE_MATH_NAN },
        { SIMDE_FLOAT64_C(  -901.98),             SIMDE_MATH_NAN },
        {             SIMDE_MATH_NAN,             SIMDE_MATH_NAN } },
      { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   643.23) },
        {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   244.23) },
        {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   244.23) },
        {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(-59005.06) } },
      #endif
      { { SIMDE_FLOAT64_C(   -34.62), SIMDE_FLOAT64_C(   708.12) },
        { SIMDE_FLOAT64_C(     4.43), SIMDE_FLOAT64_C(   255.42) },
        { SIMDE_FLOAT64_C(     4.43), SIMDE_FLOAT64_C(   255.42) },
        { SIMDE_FLOAT64_C(   -54.24), SIMDE_FLOAT64_C(-64531.26) } },
      { { SIMDE_FLOAT64_C(  -110.42), SIMDE_FLOAT64_C(   509.02) },
        { SIMDE_FLOAT64_C(  -830.04), SIMDE_FLOAT64_C(  -429.79) },
        { SIMDE_FLOAT64_C(  -830.04), SIMDE_FLOAT64_C(  -429.79) },
        { SIMDE_FLOAT64_C(-689076.82), SIMDE_FLOAT64_C(-184210.42) } },
      { { SIMDE_FLOAT64_C(  -919.81), SIMDE_FLOAT64_C(  -576.94) },
        { SIMDE_FLOAT64_C(   157.73), SIMDE_FLOAT64_C(  -978.05) },
        { SIMDE_FLOAT64_C(   157.73), SIMDE_FLOAT64_C(  -978.05) },
        { SIMDE_FLOAT64_C(-25798.56), SIMDE_FLOAT64_C(-957158.74) } },
      { { SIMDE_FLOAT64_C(   -11.25), SIMDE_FLOAT64_C(   643.76) },
        { SIMDE_FLOAT64_C(   592.23), SIMDE_FLOAT64_C(   456.83) },
        { SIMDE_FLOAT64_C(   592.23), SIMDE_FLOAT64_C(   456.83) },
        { SIMDE_FLOAT64_C(-350747.62), SIMDE_FLOAT64_C(-208049.89) } },
      { { SIMDE_FLOAT64_C(   192.13), SIMDE_FLOAT64_C(   716.26) },
        { SIMDE_FLOAT64_C(   570.24), SIMDE_FLOAT64_C(   279.86) },
        { SIMDE_FLOAT64_C(   570.24), SIMDE_FLOAT64_C(   279.86) },
        { SIMDE_FLOAT64_C(-324981.53), SIMDE_FLOAT64_C(-77605.36) } },
      { { SIMDE_FLOAT64_C(   594.96), SIMDE_FLOAT64_C(   335.72) },
        { SIMDE_FLOAT64_C(  -302.73), SIMDE_FLOAT64_C(   652.21) },
        { SIMDE_FLOAT64_C(  -302.73), SIMDE_FLOAT64_C(   652.21) },
        { SIMDE_FLOAT64_C(-91050.49), SIMDE_FLOAT64_C(-425042.16) } },
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t c = simde_wasm_v128_load(test_vec[i].c);
      simde_v128_t r = simde_wasm_f64x2_fms(a, b, c);
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

      r = simde_wasm_f64x2_fms(a, b, c);

      simde_test_wasm_f64x2_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_f64x2_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_f64x2_write(3, c, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_f64x2_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_f32x4_fms)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_f64x2_fms)
SIMDE_TEST_FUNC_LIST_END

#include "test-relaxed-simd-footer.h"
