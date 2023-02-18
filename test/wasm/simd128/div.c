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

#define SIMDE_TEST_WASM_SIMD128_INSN div
#include "../../../simde/wasm/simd128.h"
#include "test-simd128.h"

static int
test_simde_wasm_f32x4_div(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      simde_float32 a[sizeof(simde_v128_t) / sizeof(simde_float32)];
      simde_float32 b[sizeof(simde_v128_t) / sizeof(simde_float32)];
      simde_float32 r[sizeof(simde_v128_t) / sizeof(simde_float32)];
    } test_vec[] = {
      #if !defined(SIMDE_FAST_MATH)
      { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -917.17),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   294.64) },
        { SIMDE_FLOAT32_C(    81.58),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   294.64) },
        {            SIMDE_MATH_NANF,            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(     1.00) } },
      #endif
      { { SIMDE_FLOAT32_C(   927.21), SIMDE_FLOAT32_C(  -901.25), SIMDE_FLOAT32_C(  -761.56), SIMDE_FLOAT32_C(  -192.43) },
        { SIMDE_FLOAT32_C(     1.99), SIMDE_FLOAT32_C(   841.22), SIMDE_FLOAT32_C(  -290.62), SIMDE_FLOAT32_C(  -575.21) },
        { SIMDE_FLOAT32_C(   465.93), SIMDE_FLOAT32_C(    -1.07), SIMDE_FLOAT32_C(     2.62), SIMDE_FLOAT32_C(     0.33) } },
      { { SIMDE_FLOAT32_C(   819.53), SIMDE_FLOAT32_C(   103.28), SIMDE_FLOAT32_C(   -73.47), SIMDE_FLOAT32_C(  -268.67) },
        { SIMDE_FLOAT32_C(    87.65), SIMDE_FLOAT32_C(  -907.65), SIMDE_FLOAT32_C(  -325.82), SIMDE_FLOAT32_C(   363.84) },
        { SIMDE_FLOAT32_C(     9.35), SIMDE_FLOAT32_C(    -0.11), SIMDE_FLOAT32_C(     0.23), SIMDE_FLOAT32_C(    -0.74) } },
      { { SIMDE_FLOAT32_C(   246.17), SIMDE_FLOAT32_C(  -331.98), SIMDE_FLOAT32_C(  -317.38), SIMDE_FLOAT32_C(   162.90) },
        { SIMDE_FLOAT32_C(  -774.56), SIMDE_FLOAT32_C(  -134.71), SIMDE_FLOAT32_C(   118.69), SIMDE_FLOAT32_C(   -60.67) },
        { SIMDE_FLOAT32_C(    -0.32), SIMDE_FLOAT32_C(     2.46), SIMDE_FLOAT32_C(    -2.67), SIMDE_FLOAT32_C(    -2.69) } },
      { { SIMDE_FLOAT32_C(   288.95), SIMDE_FLOAT32_C(  -490.46), SIMDE_FLOAT32_C(   -54.08), SIMDE_FLOAT32_C(  -483.59) },
        { SIMDE_FLOAT32_C(  -174.00), SIMDE_FLOAT32_C(  -199.54), SIMDE_FLOAT32_C(  -230.44), SIMDE_FLOAT32_C(  -579.74) },
        { SIMDE_FLOAT32_C(    -1.66), SIMDE_FLOAT32_C(     2.46), SIMDE_FLOAT32_C(     0.23), SIMDE_FLOAT32_C(     0.83) } },
      { { SIMDE_FLOAT32_C(  -689.71), SIMDE_FLOAT32_C(   926.59), SIMDE_FLOAT32_C(   481.36), SIMDE_FLOAT32_C(   448.58) },
        { SIMDE_FLOAT32_C(   989.13), SIMDE_FLOAT32_C(   514.84), SIMDE_FLOAT32_C(  -880.11), SIMDE_FLOAT32_C(    95.57) },
        { SIMDE_FLOAT32_C(    -0.70), SIMDE_FLOAT32_C(     1.80), SIMDE_FLOAT32_C(    -0.55), SIMDE_FLOAT32_C(     4.69) } },
      { { SIMDE_FLOAT32_C(    75.26), SIMDE_FLOAT32_C(   295.69), SIMDE_FLOAT32_C(   917.57), SIMDE_FLOAT32_C(   860.41) },
        { SIMDE_FLOAT32_C(     9.23), SIMDE_FLOAT32_C(   519.17), SIMDE_FLOAT32_C(   868.89), SIMDE_FLOAT32_C(   965.66) },
        { SIMDE_FLOAT32_C(     8.15), SIMDE_FLOAT32_C(     0.57), SIMDE_FLOAT32_C(     1.06), SIMDE_FLOAT32_C(     0.89) } },
      { { SIMDE_FLOAT32_C(   226.19), SIMDE_FLOAT32_C(  -581.57), SIMDE_FLOAT32_C(    11.43), SIMDE_FLOAT32_C(  -242.13) },
        { SIMDE_FLOAT32_C(  -697.46), SIMDE_FLOAT32_C(  -832.47), SIMDE_FLOAT32_C(  -929.05), SIMDE_FLOAT32_C(  -407.23) },
        { SIMDE_FLOAT32_C(    -0.32), SIMDE_FLOAT32_C(     0.70), SIMDE_FLOAT32_C(    -0.01), SIMDE_FLOAT32_C(     0.59) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_f32x4_div(a, b);
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
        r;

      r = simde_wasm_f32x4_div(a, b);

      simde_test_wasm_f32x4_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_f32x4_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_f32x4_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_f64x2_div(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      simde_float64 a[sizeof(simde_v128_t) / sizeof(simde_float64)];
      simde_float64 b[sizeof(simde_v128_t) / sizeof(simde_float64)];
      simde_float64 r[sizeof(simde_v128_t) / sizeof(simde_float64)];
    } test_vec[] = {
      #if !defined(SIMDE_FAST_MATH)
      { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -937.38) },
        { SIMDE_FLOAT64_C(  -198.93),             SIMDE_MATH_NAN },
        {             SIMDE_MATH_NAN,             SIMDE_MATH_NAN } },
      { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(    97.31) },
        {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -384.64) },
        {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(    -0.25) } },
      #endif
      { { SIMDE_FLOAT64_C(  -371.51), SIMDE_FLOAT64_C(  -417.16) },
        { SIMDE_FLOAT64_C(   949.16), SIMDE_FLOAT64_C(   232.52) },
        { SIMDE_FLOAT64_C(    -0.39), SIMDE_FLOAT64_C(    -1.79) } },
      { { SIMDE_FLOAT64_C(   977.00), SIMDE_FLOAT64_C(  -609.69) },
        { SIMDE_FLOAT64_C(   864.19), SIMDE_FLOAT64_C(   235.23) },
        { SIMDE_FLOAT64_C(     1.13), SIMDE_FLOAT64_C(    -2.59) } },
      { { SIMDE_FLOAT64_C(   226.53), SIMDE_FLOAT64_C(  -219.44) },
        { SIMDE_FLOAT64_C(   667.35), SIMDE_FLOAT64_C(  -972.04) },
        { SIMDE_FLOAT64_C(     0.34), SIMDE_FLOAT64_C(     0.23) } },
      { { SIMDE_FLOAT64_C(   225.46), SIMDE_FLOAT64_C(  -531.78) },
        { SIMDE_FLOAT64_C(    -6.75), SIMDE_FLOAT64_C(   538.69) },
        { SIMDE_FLOAT64_C(   -33.40), SIMDE_FLOAT64_C(    -0.99) } },
      { { SIMDE_FLOAT64_C(   960.43), SIMDE_FLOAT64_C(   904.13) },
        { SIMDE_FLOAT64_C(  -885.50), SIMDE_FLOAT64_C(   832.71) },
        { SIMDE_FLOAT64_C(    -1.08), SIMDE_FLOAT64_C(     1.09) } },
      { { SIMDE_FLOAT64_C(   354.55), SIMDE_FLOAT64_C(   846.41) },
        { SIMDE_FLOAT64_C(  -309.44), SIMDE_FLOAT64_C(  -828.00) },
        { SIMDE_FLOAT64_C(    -1.15), SIMDE_FLOAT64_C(    -1.02) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_f64x2_div(a, b);
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
        r;

      r = simde_wasm_f64x2_div(a, b);

      simde_test_wasm_f64x2_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_f64x2_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_f64x2_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_f32x4_div)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_f64x2_div)
SIMDE_TEST_FUNC_LIST_END

#include "test-simd128-footer.h"
