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

#define SIMDE_TEST_WASM_RELAXED_SIMD_INSN min
#include "../../../simde/wasm/relaxed-simd.h"
#include "test-relaxed-simd.h"

static int
test_simde_wasm_f32x4_relaxed_min(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      simde_float32 a[sizeof(simde_v128_t) / sizeof(simde_float32)];
      simde_float32 b[sizeof(simde_v128_t) / sizeof(simde_float32)];
      simde_float32 r[sizeof(simde_v128_t) / sizeof(simde_float32)];
    } test_vec[] = {
      { { SIMDE_FLOAT32_C(  -384.73), SIMDE_FLOAT32_C(  -820.97), SIMDE_FLOAT32_C(   258.75), SIMDE_FLOAT32_C(   -90.51) },
        { SIMDE_FLOAT32_C(   635.11), SIMDE_FLOAT32_C(   -21.53), SIMDE_FLOAT32_C(  -197.11), SIMDE_FLOAT32_C(   959.39) },
        { SIMDE_FLOAT32_C(  -384.73), SIMDE_FLOAT32_C(  -820.97), SIMDE_FLOAT32_C(  -197.11), SIMDE_FLOAT32_C(   -90.51) } },
      { { SIMDE_FLOAT32_C(   756.93), SIMDE_FLOAT32_C(  -403.83), SIMDE_FLOAT32_C(  -535.40), SIMDE_FLOAT32_C(   581.16) },
        { SIMDE_FLOAT32_C(   575.10), SIMDE_FLOAT32_C(  -784.62), SIMDE_FLOAT32_C(   826.27), SIMDE_FLOAT32_C(  -290.44) },
        { SIMDE_FLOAT32_C(   575.10), SIMDE_FLOAT32_C(  -784.62), SIMDE_FLOAT32_C(  -535.40), SIMDE_FLOAT32_C(  -290.44) } },
      { { SIMDE_FLOAT32_C(  -580.63), SIMDE_FLOAT32_C(   400.60), SIMDE_FLOAT32_C(  -825.33), SIMDE_FLOAT32_C(   395.98) },
        { SIMDE_FLOAT32_C(   903.08), SIMDE_FLOAT32_C(   523.68), SIMDE_FLOAT32_C(  -270.81), SIMDE_FLOAT32_C(  -996.64) },
        { SIMDE_FLOAT32_C(  -580.63), SIMDE_FLOAT32_C(   400.60), SIMDE_FLOAT32_C(  -825.33), SIMDE_FLOAT32_C(  -996.64) } },
      { { SIMDE_FLOAT32_C(  -450.06), SIMDE_FLOAT32_C(  -799.96), SIMDE_FLOAT32_C(    54.34), SIMDE_FLOAT32_C(   646.36) },
        { SIMDE_FLOAT32_C(  -396.89), SIMDE_FLOAT32_C(   -93.21), SIMDE_FLOAT32_C(  -282.13), SIMDE_FLOAT32_C(  -348.89) },
        { SIMDE_FLOAT32_C(  -450.06), SIMDE_FLOAT32_C(  -799.96), SIMDE_FLOAT32_C(  -282.13), SIMDE_FLOAT32_C(  -348.89) } },
      { { SIMDE_FLOAT32_C(   449.36), SIMDE_FLOAT32_C(  -932.70), SIMDE_FLOAT32_C(   504.25), SIMDE_FLOAT32_C(   630.70) },
        { SIMDE_FLOAT32_C(     6.05), SIMDE_FLOAT32_C(   284.22), SIMDE_FLOAT32_C(  -492.84), SIMDE_FLOAT32_C(  -857.28) },
        { SIMDE_FLOAT32_C(     6.05), SIMDE_FLOAT32_C(  -932.70), SIMDE_FLOAT32_C(  -492.84), SIMDE_FLOAT32_C(  -857.28) } },
      { { SIMDE_FLOAT32_C(  -734.85), SIMDE_FLOAT32_C(   291.38), SIMDE_FLOAT32_C(   910.86), SIMDE_FLOAT32_C(  -655.45) },
        { SIMDE_FLOAT32_C(   848.95), SIMDE_FLOAT32_C(  -550.13), SIMDE_FLOAT32_C(    91.62), SIMDE_FLOAT32_C(    71.10) },
        { SIMDE_FLOAT32_C(  -734.85), SIMDE_FLOAT32_C(  -550.13), SIMDE_FLOAT32_C(    91.62), SIMDE_FLOAT32_C(  -655.45) } },
      { { SIMDE_FLOAT32_C(   983.19), SIMDE_FLOAT32_C(   944.04), SIMDE_FLOAT32_C(  -663.05), SIMDE_FLOAT32_C(   678.96) },
        { SIMDE_FLOAT32_C(  -656.24), SIMDE_FLOAT32_C(  -618.32), SIMDE_FLOAT32_C(   677.11), SIMDE_FLOAT32_C(  -741.86) },
        { SIMDE_FLOAT32_C(  -656.24), SIMDE_FLOAT32_C(  -618.32), SIMDE_FLOAT32_C(  -663.05), SIMDE_FLOAT32_C(  -741.86) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_f32x4_relaxed_min(a, b);
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

      r = simde_wasm_f32x4_relaxed_min(a, b);

      simde_test_wasm_f32x4_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_f32x4_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_f32x4_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_f64x2_relaxed_min(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      simde_float64 a[sizeof(simde_v128_t) / sizeof(simde_float64)];
      simde_float64 b[sizeof(simde_v128_t) / sizeof(simde_float64)];
      simde_float64 r[sizeof(simde_v128_t) / sizeof(simde_float64)];
    } test_vec[] = {
      { { SIMDE_FLOAT64_C(   -79.92), SIMDE_FLOAT64_C(   907.35) },
        { SIMDE_FLOAT64_C(  -343.94), SIMDE_FLOAT64_C(   358.40) },
        { SIMDE_FLOAT64_C(  -343.94), SIMDE_FLOAT64_C(   358.40) } },
      { { SIMDE_FLOAT64_C(   906.87), SIMDE_FLOAT64_C(   964.34) },
        { SIMDE_FLOAT64_C(   672.12), SIMDE_FLOAT64_C(    69.90) },
        { SIMDE_FLOAT64_C(   672.12), SIMDE_FLOAT64_C(    69.90) } },
      { { SIMDE_FLOAT64_C(   891.24), SIMDE_FLOAT64_C(    43.61) },
        { SIMDE_FLOAT64_C(   586.69), SIMDE_FLOAT64_C(   866.82) },
        { SIMDE_FLOAT64_C(   586.69), SIMDE_FLOAT64_C(    43.61) } },
      { { SIMDE_FLOAT64_C(   147.11), SIMDE_FLOAT64_C(  -721.67) },
        { SIMDE_FLOAT64_C(    40.13), SIMDE_FLOAT64_C(   931.62) },
        { SIMDE_FLOAT64_C(    40.13), SIMDE_FLOAT64_C(  -721.67) } },
      { { SIMDE_FLOAT64_C(   114.93), SIMDE_FLOAT64_C(  -695.95) },
        { SIMDE_FLOAT64_C(  -532.17), SIMDE_FLOAT64_C(  -145.28) },
        { SIMDE_FLOAT64_C(  -532.17), SIMDE_FLOAT64_C(  -695.95) } },
      { { SIMDE_FLOAT64_C(   230.71), SIMDE_FLOAT64_C(  -792.59) },
        { SIMDE_FLOAT64_C(   541.02), SIMDE_FLOAT64_C(   155.01) },
        { SIMDE_FLOAT64_C(   230.71), SIMDE_FLOAT64_C(  -792.59) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_f64x2_relaxed_min(a, b);
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

      r = simde_wasm_f64x2_relaxed_min(a, b);

      simde_test_wasm_f64x2_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_f64x2_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_f64x2_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_f32x4_relaxed_min)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_f64x2_relaxed_min)
SIMDE_TEST_FUNC_LIST_END

#include "test-relaxed-simd-footer.h"
