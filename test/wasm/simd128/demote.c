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

#define SIMDE_TEST_WASM_SIMD128_INSN demote
#include "../../../simde/wasm/simd128.h"
#include "test-simd128.h"

static int
test_simde_wasm_f32x4_demote_f64x2_zero(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      simde_float64 a[sizeof(simde_v128_t) / sizeof(simde_float64)];
      simde_float32 r[sizeof(simde_v128_t) / sizeof(simde_float32)];
    } test_vec[8] = {
      #if !defined(SIMDE_FAST_MATH)
      { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   575.91) },
        {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   575.91), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
      { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   868.19) },
        {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   868.19), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
      { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   868.19) },
        {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   868.19), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
      #endif
      { { SIMDE_FLOAT64_C(  -691.35), SIMDE_FLOAT64_C(  -314.36) },
        { SIMDE_FLOAT32_C(  -691.35), SIMDE_FLOAT32_C(  -314.36), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
      { { SIMDE_FLOAT64_C(   441.95), SIMDE_FLOAT64_C(   489.50) },
        { SIMDE_FLOAT32_C(   441.95), SIMDE_FLOAT32_C(   489.50), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
      { { SIMDE_FLOAT64_C(  -973.56), SIMDE_FLOAT64_C(  -824.04) },
        { SIMDE_FLOAT32_C(  -973.56), SIMDE_FLOAT32_C(  -824.04), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
      { { SIMDE_FLOAT64_C(  -557.79), SIMDE_FLOAT64_C(  -602.44) },
        { SIMDE_FLOAT32_C(  -557.79), SIMDE_FLOAT32_C(  -602.44), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
      { { SIMDE_FLOAT64_C(   771.16), SIMDE_FLOAT64_C(   -75.58) },
        { SIMDE_FLOAT32_C(   771.16), SIMDE_FLOAT32_C(   -75.58), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t r = simde_wasm_f32x4_demote_f64x2_zero(a);
      simde_test_wasm_f32x4_assert_equal(r, simde_wasm_v128_load(test_vec[i].r), INT_MAX);
    }
    return 0;
  #else
    fputc('\n', stdout);
    simde_float64 inputs[8 * 1 * (sizeof(simde_v128_t) / sizeof(simde_float64))];
    simde_test_wasm_f64x2_random_full(8, 1, inputs, -SIMDE_FLOAT64_C(1000.0), SIMDE_FLOAT64_C(1000.0), HEDLEY_STATIC_CAST(SimdeTestVecFloatType, SIMDE_TEST_VEC_FLOAT_NAN | SIMDE_TEST_VEC_FLOAT_EQUAL));
    for (size_t i = 0 ; i < 8 ; i++) {
      simde_v128_t
        a = simde_test_wasm_f64x2_random_full_extract(1, inputs, i, 0),
        r;

      r = simde_wasm_f32x4_demote_f64x2_zero(a);

      simde_test_wasm_f64x2_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_f32x4_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_f32x4_demote_f64x2_zero)
SIMDE_TEST_FUNC_LIST_END

#include "test-simd128-footer.h"
