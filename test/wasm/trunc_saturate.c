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

#define SIMDE_TESTS_CURRENT_ISAX simd128
#include <simde/wasm/simd128.h>
#include <test/wasm/test-simd128.h>

static int
test_simde_wasm_i32x4_trunc_saturate_f32x4(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      simde_float32 a[sizeof(simde_v128_t) / sizeof(simde_float32)];
      int32_t r[sizeof(simde_v128_t) / sizeof(simde_float32)];
    } test_vec[8] = {
      { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   453.46),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   490.85) },
        {  INT32_C(           0),  INT32_C(         453),  INT32_C(           0),  INT32_C(         490) } },
      { { SIMDE_FLOAT32_C(   719.41),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   490.85) },
        {  INT32_C(         719),  INT32_C(           0),  INT32_C(           0),  INT32_C(         490) } },
      { { SIMDE_FLOAT32_C(  -351.14), SIMDE_FLOAT32_C(   190.81), SIMDE_FLOAT32_C(  -720.98), SIMDE_FLOAT32_C(  -330.86) },
        { -INT32_C(         351),  INT32_C(         190), -INT32_C(         720), -INT32_C(         330) } },
      { { SIMDE_FLOAT32_C(   716.24), SIMDE_FLOAT32_C(   -48.69), SIMDE_FLOAT32_C(    87.44), SIMDE_FLOAT32_C(    75.52) },
        {  INT32_C(         716), -INT32_C(          48),  INT32_C(          87),  INT32_C(          75) } },
      { { SIMDE_FLOAT32_C(    80.24), SIMDE_FLOAT32_C(  -488.47), SIMDE_FLOAT32_C(   618.16), SIMDE_FLOAT32_C(  -784.57) },
        {  INT32_C(          80), -INT32_C(         488),  INT32_C(         618), -INT32_C(         784) } },
      { { SIMDE_FLOAT32_C(  -200.62), SIMDE_FLOAT32_C(   528.90), SIMDE_FLOAT32_C(  -662.39), SIMDE_FLOAT32_C(  -502.51) },
        { -INT32_C(         200),  INT32_C(         528), -INT32_C(         662), -INT32_C(         502) } },
      { { SIMDE_FLOAT32_C(  -651.38), SIMDE_FLOAT32_C(  -493.23), SIMDE_FLOAT32_C(  -320.95), SIMDE_FLOAT32_C(   381.42) },
        { -INT32_C(         651), -INT32_C(         493), -INT32_C(         320),  INT32_C(         381) } },
      { { SIMDE_FLOAT32_C(   837.54), SIMDE_FLOAT32_C(   708.11), SIMDE_FLOAT32_C(   -48.60), SIMDE_FLOAT32_C(   490.27) },
        {  INT32_C(         837),  INT32_C(         708), -INT32_C(          48),  INT32_C(         490) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t r = simde_wasm_i32x4_trunc_saturate_f32x4(a);
      simde_test_wasm_i32x4_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
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

      r = simde_wasm_i32x4_trunc_saturate_f32x4(a);

      simde_test_wasm_f32x4_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_i32x4_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_u32x4_trunc_saturate_f32x4(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      simde_float32 a[sizeof(simde_v128_t) / sizeof(simde_float32)];
      uint32_t r[sizeof(simde_v128_t) / sizeof(simde_float32)];
    } test_vec[8] = {
      { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   -10.72),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -998.02) },
        { UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0) } },
      { { SIMDE_FLOAT32_C(  -998.33),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -998.02) },
        { UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0) } },
      { { SIMDE_FLOAT32_C(    -4.97), SIMDE_FLOAT32_C(   621.77), SIMDE_FLOAT32_C(    94.46), SIMDE_FLOAT32_C(    95.10) },
        { UINT32_C(         0), UINT32_C(       621), UINT32_C(        94), UINT32_C(        95) } },
      { { SIMDE_FLOAT32_C(   810.83), SIMDE_FLOAT32_C(   118.78), SIMDE_FLOAT32_C(   987.72), SIMDE_FLOAT32_C(   434.26) },
        { UINT32_C(       810), UINT32_C(       118), UINT32_C(       987), UINT32_C(       434) } },
      { { SIMDE_FLOAT32_C(    33.41), SIMDE_FLOAT32_C(  -506.54), SIMDE_FLOAT32_C(   981.74), SIMDE_FLOAT32_C(  -200.69) },
        { UINT32_C(        33), UINT32_C(         0), UINT32_C(       981), UINT32_C(         0) } },
      { { SIMDE_FLOAT32_C(  -666.90), SIMDE_FLOAT32_C(   528.46), SIMDE_FLOAT32_C(   616.44), SIMDE_FLOAT32_C(    37.26) },
        { UINT32_C(         0), UINT32_C(       528), UINT32_C(       616), UINT32_C(        37) } },
      { { SIMDE_FLOAT32_C(  -199.83), SIMDE_FLOAT32_C(  -481.79), SIMDE_FLOAT32_C(  -335.36), SIMDE_FLOAT32_C(   -83.68) },
        { UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0) } },
      { { SIMDE_FLOAT32_C(  -844.61), SIMDE_FLOAT32_C(  -368.47), SIMDE_FLOAT32_C(  -388.53), SIMDE_FLOAT32_C(  -334.94) },
        { UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t r = simde_wasm_u32x4_trunc_saturate_f32x4(a);
      simde_test_wasm_u32x4_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
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

      r = simde_wasm_u32x4_trunc_saturate_f32x4(a);

      simde_test_wasm_f32x4_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_u32x4_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i32x4_trunc_saturate_f32x4)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_u32x4_trunc_saturate_f32x4)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/test-x86-footer.h>
