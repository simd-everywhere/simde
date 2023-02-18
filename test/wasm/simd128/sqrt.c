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

#define SIMDE_TEST_WASM_SIMD128_INSN sqrt
#include "../../../simde/wasm/simd128.h"
#include "test-simd128.h"

#if !defined(SIMDE_FAST_MATH)
static int
test_simde_wasm_f32x4_sqrt(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      simde_float32 a[sizeof(simde_v128_t) / sizeof(simde_float32)];
      simde_float32 r[sizeof(simde_v128_t) / sizeof(simde_float32)];
    } test_vec[8] = {
      { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -535.11),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -461.56) },
        {            SIMDE_MATH_NANF,            SIMDE_MATH_NANF,            SIMDE_MATH_NANF,            SIMDE_MATH_NANF } },
      { { SIMDE_FLOAT32_C(  -912.22),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -461.56) },
        {            SIMDE_MATH_NANF,            SIMDE_MATH_NANF,            SIMDE_MATH_NANF,            SIMDE_MATH_NANF } },
      { { SIMDE_FLOAT32_C(  -323.47), SIMDE_FLOAT32_C(  -632.61), SIMDE_FLOAT32_C(  -654.45), SIMDE_FLOAT32_C(  -156.47) },
        {            SIMDE_MATH_NANF,            SIMDE_MATH_NANF,            SIMDE_MATH_NANF,            SIMDE_MATH_NANF } },
      { { SIMDE_FLOAT32_C(   377.85), SIMDE_FLOAT32_C(   566.01), SIMDE_FLOAT32_C(   762.66), SIMDE_FLOAT32_C(  -297.76) },
        { SIMDE_FLOAT32_C(    19.44), SIMDE_FLOAT32_C(    23.79), SIMDE_FLOAT32_C(    27.62),            SIMDE_MATH_NANF } },
      { { SIMDE_FLOAT32_C(   618.27), SIMDE_FLOAT32_C(  -845.05), SIMDE_FLOAT32_C(  -519.37), SIMDE_FLOAT32_C(   863.47) },
        { SIMDE_FLOAT32_C(    24.87),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(    29.38) } },
      { { SIMDE_FLOAT32_C(  -208.55), SIMDE_FLOAT32_C(   290.20), SIMDE_FLOAT32_C(   208.11), SIMDE_FLOAT32_C(   288.32) },
        {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(    17.04), SIMDE_FLOAT32_C(    14.43), SIMDE_FLOAT32_C(    16.98) } },
      { { SIMDE_FLOAT32_C(  -113.12), SIMDE_FLOAT32_C(  -686.61), SIMDE_FLOAT32_C(  -683.66), SIMDE_FLOAT32_C(  -156.75) },
        {            SIMDE_MATH_NANF,            SIMDE_MATH_NANF,            SIMDE_MATH_NANF,            SIMDE_MATH_NANF } },
      { { SIMDE_FLOAT32_C(   888.36), SIMDE_FLOAT32_C(  -712.39), SIMDE_FLOAT32_C(   554.00), SIMDE_FLOAT32_C(  -810.32) },
        { SIMDE_FLOAT32_C(    29.81),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(    23.54),            SIMDE_MATH_NANF } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t r = simde_wasm_f32x4_sqrt(a);
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

      r = simde_wasm_f32x4_sqrt(a);

      simde_test_wasm_f32x4_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_f32x4_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}
#endif

static int
test_simde_wasm_f64x2_sqrt(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      simde_float64 a[sizeof(simde_v128_t) / sizeof(simde_float32)];
      simde_float64 r[sizeof(simde_v128_t) / sizeof(simde_float32)];
    } test_vec[8] = {
      #if !defined(SIMDE_FAST_MATH)
      { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   558.45) },
        {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(    23.63) } },
      { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   191.40) },
        {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(    13.83) } },
      { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   191.40) },
        {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(    13.83) } },
      { { SIMDE_FLOAT64_C(  -677.40), SIMDE_FLOAT64_C(  -306.34) },
        {             SIMDE_MATH_NAN,             SIMDE_MATH_NAN } },
      { { SIMDE_FLOAT64_C(  -896.18), SIMDE_FLOAT64_C(   904.07) },
        {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(    30.07) } },
      { { SIMDE_FLOAT64_C(  -197.48), SIMDE_FLOAT64_C(  -839.74) },
        {             SIMDE_MATH_NAN,             SIMDE_MATH_NAN } },
      { { SIMDE_FLOAT64_C(  -744.46), SIMDE_FLOAT64_C(   -29.22) },
        {             SIMDE_MATH_NAN,             SIMDE_MATH_NAN } },
      #endif
      { { SIMDE_FLOAT64_C(   611.51), SIMDE_FLOAT64_C(    40.74) },
        { SIMDE_FLOAT64_C(    24.73), SIMDE_FLOAT64_C(     6.38) } },
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t r = simde_wasm_f64x2_sqrt(a);
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

      r = simde_wasm_f64x2_sqrt(a);

      simde_test_wasm_f64x2_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_f64x2_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
#if !defined(SIMDE_FAST_MATH)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_f32x4_sqrt)
#endif
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_f64x2_sqrt)
SIMDE_TEST_FUNC_LIST_END

#include "test-simd128-footer.h"
