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

#define SIMDE_TEST_WASM_RELAXED_SIMD_INSN max
#include "../../../simde/wasm/relaxed-simd.h"
#include "test-relaxed-simd.h"

static int
test_simde_wasm_f32x4_relaxed_max(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      simde_float32 a[sizeof(simde_v128_t) / sizeof(simde_float32)];
      simde_float32 b[sizeof(simde_v128_t) / sizeof(simde_float32)];
      simde_float32 r[sizeof(simde_v128_t) / sizeof(simde_float32)];
    } test_vec[] = {
      { { SIMDE_FLOAT32_C(  -920.07), SIMDE_FLOAT32_C(   830.32), SIMDE_FLOAT32_C(  -196.85), SIMDE_FLOAT32_C(   291.81) },
        { SIMDE_FLOAT32_C(  -289.04), SIMDE_FLOAT32_C(    49.93), SIMDE_FLOAT32_C(  -928.55), SIMDE_FLOAT32_C(    69.77) },
        { SIMDE_FLOAT32_C(  -289.04), SIMDE_FLOAT32_C(   830.32), SIMDE_FLOAT32_C(  -196.85), SIMDE_FLOAT32_C(   291.81) } },
      { { SIMDE_FLOAT32_C(  -679.01), SIMDE_FLOAT32_C(   273.37), SIMDE_FLOAT32_C(  -532.77), SIMDE_FLOAT32_C(   127.55) },
        { SIMDE_FLOAT32_C(   100.92), SIMDE_FLOAT32_C(  -536.72), SIMDE_FLOAT32_C(  -535.51), SIMDE_FLOAT32_C(  -444.83) },
        { SIMDE_FLOAT32_C(   100.92), SIMDE_FLOAT32_C(   273.37), SIMDE_FLOAT32_C(  -532.77), SIMDE_FLOAT32_C(   127.55) } },
      { { SIMDE_FLOAT32_C(  -370.35), SIMDE_FLOAT32_C(   910.66), SIMDE_FLOAT32_C(  -449.76), SIMDE_FLOAT32_C(   756.97) },
        { SIMDE_FLOAT32_C(  -168.50), SIMDE_FLOAT32_C(   242.88), SIMDE_FLOAT32_C(  -696.72), SIMDE_FLOAT32_C(   663.79) },
        { SIMDE_FLOAT32_C(  -168.50), SIMDE_FLOAT32_C(   910.66), SIMDE_FLOAT32_C(  -449.76), SIMDE_FLOAT32_C(   756.97) } },
      { { SIMDE_FLOAT32_C(  -777.21), SIMDE_FLOAT32_C(  -561.66), SIMDE_FLOAT32_C(   225.28), SIMDE_FLOAT32_C(    30.10) },
        { SIMDE_FLOAT32_C(  -535.78), SIMDE_FLOAT32_C(  -546.75), SIMDE_FLOAT32_C(   345.48), SIMDE_FLOAT32_C(   708.52) },
        { SIMDE_FLOAT32_C(  -535.78), SIMDE_FLOAT32_C(  -546.75), SIMDE_FLOAT32_C(   345.48), SIMDE_FLOAT32_C(   708.52) } },
      { { SIMDE_FLOAT32_C(   940.56), SIMDE_FLOAT32_C(   303.87), SIMDE_FLOAT32_C(   810.53), SIMDE_FLOAT32_C(  -526.94) },
        { SIMDE_FLOAT32_C(   611.43), SIMDE_FLOAT32_C(   797.37), SIMDE_FLOAT32_C(   432.36), SIMDE_FLOAT32_C(   709.89) },
        { SIMDE_FLOAT32_C(   940.56), SIMDE_FLOAT32_C(   797.37), SIMDE_FLOAT32_C(   810.53), SIMDE_FLOAT32_C(   709.89) } },
      { { SIMDE_FLOAT32_C(  -157.18), SIMDE_FLOAT32_C(  -402.78), SIMDE_FLOAT32_C(  -362.67), SIMDE_FLOAT32_C(  -944.01) },
        { SIMDE_FLOAT32_C(   106.70), SIMDE_FLOAT32_C(  -208.07), SIMDE_FLOAT32_C(   277.04), SIMDE_FLOAT32_C(   374.11) },
        { SIMDE_FLOAT32_C(   106.70), SIMDE_FLOAT32_C(  -208.07), SIMDE_FLOAT32_C(   277.04), SIMDE_FLOAT32_C(   374.11) } },
      { { SIMDE_FLOAT32_C(  -402.16), SIMDE_FLOAT32_C(   227.84), SIMDE_FLOAT32_C(  -493.53), SIMDE_FLOAT32_C(   869.48) },
        { SIMDE_FLOAT32_C(   903.71), SIMDE_FLOAT32_C(  -712.51), SIMDE_FLOAT32_C(  -864.99), SIMDE_FLOAT32_C(  -151.96) },
        { SIMDE_FLOAT32_C(   903.71), SIMDE_FLOAT32_C(   227.84), SIMDE_FLOAT32_C(  -493.53), SIMDE_FLOAT32_C(   869.48) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_f32x4_relaxed_max(a, b);
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

      r = simde_wasm_f32x4_relaxed_max(a, b);

      simde_test_wasm_f32x4_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_f32x4_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_f32x4_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_f64x2_relaxed_max(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      simde_float64 a[sizeof(simde_v128_t) / sizeof(simde_float64)];
      simde_float64 b[sizeof(simde_v128_t) / sizeof(simde_float64)];
      simde_float64 r[sizeof(simde_v128_t) / sizeof(simde_float64)];
    } test_vec[] = {
      { { SIMDE_FLOAT64_C(   523.06), SIMDE_FLOAT64_C(  -600.30) },
        { SIMDE_FLOAT64_C(   212.57), SIMDE_FLOAT64_C(  -725.13) },
        { SIMDE_FLOAT64_C(   523.06), SIMDE_FLOAT64_C(  -600.30) } },
      { { SIMDE_FLOAT64_C(   630.42), SIMDE_FLOAT64_C(  -507.35) },
        { SIMDE_FLOAT64_C(    28.88), SIMDE_FLOAT64_C(  -240.00) },
        { SIMDE_FLOAT64_C(   630.42), SIMDE_FLOAT64_C(  -240.00) } },
      { { SIMDE_FLOAT64_C(   373.65), SIMDE_FLOAT64_C(   213.86) },
        { SIMDE_FLOAT64_C(  -611.53), SIMDE_FLOAT64_C(   707.90) },
        { SIMDE_FLOAT64_C(   373.65), SIMDE_FLOAT64_C(   707.90) } },
      { { SIMDE_FLOAT64_C(   339.86), SIMDE_FLOAT64_C(  -860.05) },
        { SIMDE_FLOAT64_C(   213.55), SIMDE_FLOAT64_C(  -405.72) },
        { SIMDE_FLOAT64_C(   339.86), SIMDE_FLOAT64_C(  -405.72) } },
      { { SIMDE_FLOAT64_C(  -478.66), SIMDE_FLOAT64_C(  -629.72) },
        { SIMDE_FLOAT64_C(   841.82), SIMDE_FLOAT64_C(   793.27) },
        { SIMDE_FLOAT64_C(   841.82), SIMDE_FLOAT64_C(   793.27) } },
      { { SIMDE_FLOAT64_C(  -262.99), SIMDE_FLOAT64_C(   802.55) },
        { SIMDE_FLOAT64_C(  -938.61), SIMDE_FLOAT64_C(   323.51) },
        { SIMDE_FLOAT64_C(  -262.99), SIMDE_FLOAT64_C(   802.55) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_f64x2_relaxed_max(a, b);
      simde_test_wasm_f64x2_assert_equal(r, simde_wasm_v128_load(test_vec[i].r), 3);
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

      r = simde_wasm_f64x2_relaxed_max(a, b);

      simde_test_wasm_f64x2_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_f64x2_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_f64x2_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_f32x4_relaxed_max)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_f64x2_relaxed_max)
SIMDE_TEST_FUNC_LIST_END

#include "test-relaxed-simd-footer.h"
