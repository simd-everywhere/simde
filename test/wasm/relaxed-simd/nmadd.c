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

#define SIMDE_TEST_WASM_RELAXED_SIMD_INSN nmadd
#include "../../../simde/wasm/relaxed-simd.h"
#include "test-relaxed-simd.h"

static int
test_simde_wasm_f32x4_relaxed_nmadd(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      simde_float32 a[sizeof(simde_v128_t) / sizeof(simde_float32)];
      simde_float32 b[sizeof(simde_v128_t) / sizeof(simde_float32)];
      simde_float32 c[sizeof(simde_v128_t) / sizeof(simde_float32)];
      simde_float32 r[sizeof(simde_v128_t) / sizeof(simde_float32)];
    } test_vec[] = {
      #if !defined(SIMDE_FAST_MATH)
      { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   545.32),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   291.74) },
        { SIMDE_FLOAT32_C(  -401.62),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   291.74) },
        { SIMDE_FLOAT32_C(  -401.62),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   291.74) },
        {            SIMDE_MATH_NANF,            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(-84820.48) } },
      #endif
      { { SIMDE_FLOAT32_C(   173.47), SIMDE_FLOAT32_C(    46.49), SIMDE_FLOAT32_C(  -845.82), SIMDE_FLOAT32_C(    -7.33) },
        { SIMDE_FLOAT32_C(  -984.71), SIMDE_FLOAT32_C(   707.30), SIMDE_FLOAT32_C(   807.44), SIMDE_FLOAT32_C(  -705.38) },
        { SIMDE_FLOAT32_C(  -984.71), SIMDE_FLOAT32_C(   707.30), SIMDE_FLOAT32_C(   807.44), SIMDE_FLOAT32_C(  -705.38) },
        { SIMDE_FLOAT32_C(169832.94), SIMDE_FLOAT32_C(-32175.08), SIMDE_FLOAT32_C(683756.38), SIMDE_FLOAT32_C( -5875.82) } },
      { { SIMDE_FLOAT32_C(  -897.96), SIMDE_FLOAT32_C(  -320.99), SIMDE_FLOAT32_C(   222.19), SIMDE_FLOAT32_C(   329.67) },
        { SIMDE_FLOAT32_C(   480.55), SIMDE_FLOAT32_C(  -189.47), SIMDE_FLOAT32_C(   641.89), SIMDE_FLOAT32_C(   962.95) },
        { SIMDE_FLOAT32_C(   480.55), SIMDE_FLOAT32_C(  -189.47), SIMDE_FLOAT32_C(   641.89), SIMDE_FLOAT32_C(   962.95) },
        { SIMDE_FLOAT32_C(431995.22), SIMDE_FLOAT32_C(-61007.45), SIMDE_FLOAT32_C(-141979.66), SIMDE_FLOAT32_C(-316492.78) } },
      { { SIMDE_FLOAT32_C(   364.91), SIMDE_FLOAT32_C(  -180.05), SIMDE_FLOAT32_C(   832.13), SIMDE_FLOAT32_C(   436.64) },
        { SIMDE_FLOAT32_C(  -923.59), SIMDE_FLOAT32_C(  -999.35), SIMDE_FLOAT32_C(  -851.40), SIMDE_FLOAT32_C(   622.08) },
        { SIMDE_FLOAT32_C(  -923.59), SIMDE_FLOAT32_C(  -999.35), SIMDE_FLOAT32_C(  -851.40), SIMDE_FLOAT32_C(   622.08) },
        { SIMDE_FLOAT32_C(336103.66), SIMDE_FLOAT32_C(-180932.31), SIMDE_FLOAT32_C(707624.12), SIMDE_FLOAT32_C(-271002.94) } },
      { { SIMDE_FLOAT32_C(  -647.47), SIMDE_FLOAT32_C(  -384.76), SIMDE_FLOAT32_C(   680.63), SIMDE_FLOAT32_C(   383.43) },
        { SIMDE_FLOAT32_C(  -623.98), SIMDE_FLOAT32_C(  -691.43), SIMDE_FLOAT32_C(   -32.70), SIMDE_FLOAT32_C(   -59.91) },
        { SIMDE_FLOAT32_C(  -623.98), SIMDE_FLOAT32_C(  -691.43), SIMDE_FLOAT32_C(   -32.70), SIMDE_FLOAT32_C(   -59.91) },
        { SIMDE_FLOAT32_C(-404632.28), SIMDE_FLOAT32_C(-266726.03), SIMDE_FLOAT32_C( 22223.90), SIMDE_FLOAT32_C( 22911.38) } },
      { { SIMDE_FLOAT32_C(   460.16), SIMDE_FLOAT32_C(   699.08), SIMDE_FLOAT32_C(    46.84), SIMDE_FLOAT32_C(  -276.12) },
        { SIMDE_FLOAT32_C(   209.70), SIMDE_FLOAT32_C(    62.34), SIMDE_FLOAT32_C(  -423.14), SIMDE_FLOAT32_C(  -232.76) },
        { SIMDE_FLOAT32_C(   209.70), SIMDE_FLOAT32_C(    62.34), SIMDE_FLOAT32_C(  -423.14), SIMDE_FLOAT32_C(  -232.76) },
        { SIMDE_FLOAT32_C(-96285.85), SIMDE_FLOAT32_C(-43518.31), SIMDE_FLOAT32_C( 19396.74), SIMDE_FLOAT32_C(-64502.45) } },
      { { SIMDE_FLOAT32_C(  -628.34), SIMDE_FLOAT32_C(   631.71), SIMDE_FLOAT32_C(   358.07), SIMDE_FLOAT32_C(  -740.27) },
        { SIMDE_FLOAT32_C(  -615.72), SIMDE_FLOAT32_C(   348.27), SIMDE_FLOAT32_C(   757.89), SIMDE_FLOAT32_C(  -603.25) },
        { SIMDE_FLOAT32_C(  -615.72), SIMDE_FLOAT32_C(   348.27), SIMDE_FLOAT32_C(   757.89), SIMDE_FLOAT32_C(  -603.25) },
        { SIMDE_FLOAT32_C(-387497.22), SIMDE_FLOAT32_C(-219657.38), SIMDE_FLOAT32_C(-270619.78), SIMDE_FLOAT32_C(-447171.12) } },
      { { SIMDE_FLOAT32_C(  -516.74), SIMDE_FLOAT32_C(  -975.11), SIMDE_FLOAT32_C(  -307.68), SIMDE_FLOAT32_C(   814.78) },
        { SIMDE_FLOAT32_C(  -592.82), SIMDE_FLOAT32_C(   636.65), SIMDE_FLOAT32_C(  -416.13), SIMDE_FLOAT32_C(  -499.03) },
        { SIMDE_FLOAT32_C(  -592.82), SIMDE_FLOAT32_C(   636.65), SIMDE_FLOAT32_C(  -416.13), SIMDE_FLOAT32_C(  -499.03) },
        { SIMDE_FLOAT32_C(-306926.62), SIMDE_FLOAT32_C(621440.44), SIMDE_FLOAT32_C(-128451.01), SIMDE_FLOAT32_C(406100.66) } },
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t c = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_f32x4_relaxed_nmadd(a, b, c);
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

      r = simde_wasm_f32x4_relaxed_nmadd(a, b, c);

      simde_test_wasm_f32x4_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_f32x4_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_f32x4_write(3, c, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_f32x4_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_f64x2_relaxed_nmadd(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      simde_float64 a[sizeof(simde_v128_t) / sizeof(simde_float64)];
      simde_float64 b[sizeof(simde_v128_t) / sizeof(simde_float64)];
      simde_float64 c[sizeof(simde_v128_t) / sizeof(simde_float64)];
      simde_float64 r[sizeof(simde_v128_t) / sizeof(simde_float64)];
    } test_vec[] = {
      #if !defined(SIMDE_FAST_MATH)
      { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   947.03) },
        { SIMDE_FLOAT64_C(    46.26),             SIMDE_MATH_NAN },
        { SIMDE_FLOAT64_C(    46.26),             SIMDE_MATH_NAN },
        {             SIMDE_MATH_NAN,             SIMDE_MATH_NAN } },
      { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   395.95) },
        {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   410.70) },
        {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   410.70) },
        {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(-162205.96) } },
      #endif
      { { SIMDE_FLOAT64_C(  -705.54), SIMDE_FLOAT64_C(   240.18) },
        { SIMDE_FLOAT64_C(   850.34), SIMDE_FLOAT64_C(  -268.62) },
        { SIMDE_FLOAT64_C(   850.34), SIMDE_FLOAT64_C(  -268.62) },
        { SIMDE_FLOAT64_C(600799.22), SIMDE_FLOAT64_C( 64248.53) } },
      { { SIMDE_FLOAT64_C(  -540.18), SIMDE_FLOAT64_C(  -439.41) },
        { SIMDE_FLOAT64_C(  -815.99), SIMDE_FLOAT64_C(   725.32) },
        { SIMDE_FLOAT64_C(  -815.99), SIMDE_FLOAT64_C(   725.32) },
        { SIMDE_FLOAT64_C(-441597.47), SIMDE_FLOAT64_C(319438.18) } },
      { { SIMDE_FLOAT64_C(  -121.51), SIMDE_FLOAT64_C(  -187.20) },
        { SIMDE_FLOAT64_C(   834.54), SIMDE_FLOAT64_C(   779.49) },
        { SIMDE_FLOAT64_C(   834.54), SIMDE_FLOAT64_C(   779.49) },
        { SIMDE_FLOAT64_C(102239.50), SIMDE_FLOAT64_C(146700.02) } },
      { { SIMDE_FLOAT64_C(  -553.07), SIMDE_FLOAT64_C(  -219.01) },
        { SIMDE_FLOAT64_C(  -682.33), SIMDE_FLOAT64_C(   -81.13) },
        { SIMDE_FLOAT64_C(  -682.33), SIMDE_FLOAT64_C(   -81.13) },
        { SIMDE_FLOAT64_C(-378058.58), SIMDE_FLOAT64_C(-17849.41) } },
      { { SIMDE_FLOAT64_C(   223.30), SIMDE_FLOAT64_C(   664.04) },
        { SIMDE_FLOAT64_C(  -188.97), SIMDE_FLOAT64_C(   941.25) },
        { SIMDE_FLOAT64_C(  -188.97), SIMDE_FLOAT64_C(   941.25) },
        { SIMDE_FLOAT64_C( 42008.03), SIMDE_FLOAT64_C(-624086.40) } },
      { { SIMDE_FLOAT64_C(  -463.27), SIMDE_FLOAT64_C(   754.60) },
        { SIMDE_FLOAT64_C(   261.15), SIMDE_FLOAT64_C(  -326.00) },
        { SIMDE_FLOAT64_C(   261.15), SIMDE_FLOAT64_C(  -326.00) },
        { SIMDE_FLOAT64_C(121244.11), SIMDE_FLOAT64_C(245673.60) } },
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t c = simde_wasm_v128_load(test_vec[i].c);
      simde_v128_t r = simde_wasm_f64x2_relaxed_nmadd(a, b, c);
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

      r = simde_wasm_f64x2_relaxed_nmadd(a, b, c);

      simde_test_wasm_f64x2_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_f64x2_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_f64x2_write(3, c, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_f64x2_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_f32x4_relaxed_nmadd)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_f64x2_relaxed_nmadd)
SIMDE_TEST_FUNC_LIST_END

#include "test-relaxed-simd-footer.h"
