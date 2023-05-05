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

#define SIMDE_TEST_WASM_SIMD128_INSN trunc_sat
#include "../../../simde/wasm/simd128.h"
#include "test-simd128.h"

static int
test_simde_wasm_i32x4_trunc_sat_f32x4(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      simde_float32 a[sizeof(simde_v128_t) / sizeof(simde_float32)];
      int32_t r[sizeof(simde_v128_t) / sizeof(int32_t)];
    } test_vec[] = {
      #if !defined(SIMDE_FAST_NANS) && !defined(SIMDE_FAST_MATH)
      { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   453.46),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   490.85) },
        {  INT32_C(           0),  INT32_C(         453),  INT32_C(           0),  INT32_C(         490) } },
      { { SIMDE_FLOAT32_C(   719.41),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   490.85) },
        {  INT32_C(         719),  INT32_C(           0),  INT32_C(           0),  INT32_C(         490) } },
      #endif

      #if !defined(SIMDE_FAST_CONVERSION_RANGE)
      { { SIMDE_FLOAT32_C(4974910976.00), SIMDE_FLOAT32_C(8101277696.00), SIMDE_FLOAT32_C(8545195520.00), SIMDE_FLOAT32_C(819185920.00) },
        {              INT32_MAX,              INT32_MAX,              INT32_MAX,  INT32_C(   819185920) } },
      { { SIMDE_FLOAT32_C(-1109826048.00), SIMDE_FLOAT32_C(-5749201920.00), SIMDE_FLOAT32_C(-7938377216.00), SIMDE_FLOAT32_C(670815424.00) },
        { -INT32_C(  1109826048),              INT32_MIN,              INT32_MIN,  INT32_C(   670815424) } },
      { { SIMDE_FLOAT32_C(-3934582016.00), SIMDE_FLOAT32_C(2603901952.00), SIMDE_FLOAT32_C(2227754496.00), SIMDE_FLOAT32_C(4481346560.00) },
        {              INT32_MIN,              INT32_MAX,              INT32_MAX,              INT32_MAX } },
      { { SIMDE_FLOAT32_C(5441999872.00), SIMDE_FLOAT32_C(-6778211840.00), SIMDE_FLOAT32_C(-8221154816.00), SIMDE_FLOAT32_C(9134978048.00) },
        {              INT32_MAX,              INT32_MIN,              INT32_MIN,              INT32_MAX } },
      #endif

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
      simde_v128_t r = simde_wasm_i32x4_trunc_sat_f32x4(a);
      simde_test_wasm_i32x4_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    simde_float32 inputs[8 * 1 * (sizeof(simde_v128_t) / sizeof(simde_float32))];
    simde_test_wasm_f32x4_random_full(8, 1, inputs, -SIMDE_FLOAT32_C(10000000000.0), SIMDE_FLOAT32_C(10000000000.0), HEDLEY_STATIC_CAST(SimdeTestVecFloatType, SIMDE_TEST_VEC_FLOAT_NAN | SIMDE_TEST_VEC_FLOAT_EQUAL));
    for (size_t i = 0 ; i < 8 ; i++) {
      simde_v128_t
        a = simde_test_wasm_f32x4_random_full_extract(1, inputs, i, 0),
        r;

      r = simde_wasm_i32x4_trunc_sat_f32x4(a);

      simde_test_wasm_f32x4_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_i32x4_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_u32x4_trunc_sat_f32x4(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      simde_float32 a[sizeof(simde_v128_t) / sizeof(simde_float32)];
      uint32_t r[sizeof(simde_v128_t) / sizeof(uint32_t)];
    } test_vec[] = {
      #if !defined(SIMDE_FAST_NANS) && !defined(SIMDE_FAST_CONVERSION_RANGE)
      { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   -10.72),       SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(4294977296.0) },
        { UINT32_C(         0), UINT32_C(         0), UINT32_C(4294967295), UINT32_C(4294967295) } },
      { { SIMDE_FLOAT32_C(  -998.33),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -998.02) },
        { UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0) } },
      #endif
      #if !defined(SIMDE_FAST_CONVERSION_RANGE)
      { { SIMDE_FLOAT32_C(  -199.83), SIMDE_FLOAT32_C(  -481.79), SIMDE_FLOAT32_C(  -335.36), SIMDE_FLOAT32_C(   -83.68) },
        { UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0) } },
      { { SIMDE_FLOAT32_C(    -4.97), SIMDE_FLOAT32_C(   621.77), SIMDE_FLOAT32_C(    94.46), SIMDE_FLOAT32_C(    95.10) },
        { UINT32_C(         0), UINT32_C(       621), UINT32_C(        94), UINT32_C(        95) } },
      { { SIMDE_FLOAT32_C(    33.41), SIMDE_FLOAT32_C(  -506.54), SIMDE_FLOAT32_C(   981.74), SIMDE_FLOAT32_C(  -200.69) },
        { UINT32_C(        33), UINT32_C(         0), UINT32_C(       981), UINT32_C(         0) } },
      { { SIMDE_FLOAT32_C(  -666.90), SIMDE_FLOAT32_C(   528.46), SIMDE_FLOAT32_C(   616.44), SIMDE_FLOAT32_C(    37.26) },
        { UINT32_C(         0), UINT32_C(       528), UINT32_C(       616), UINT32_C(        37) } },
      #endif
      { { SIMDE_FLOAT32_C(   810.83), SIMDE_FLOAT32_C(   118.78), SIMDE_FLOAT32_C(   987.72), SIMDE_FLOAT32_C(   434.26) },
        { UINT32_C(       810), UINT32_C(       118), UINT32_C(       987), UINT32_C(       434) } },
      { { SIMDE_FLOAT32_C(    84.45), SIMDE_FLOAT32_C(   929.49), SIMDE_FLOAT32_C(   931.91), SIMDE_FLOAT32_C(   202.01) },
        { UINT32_C(        84), UINT32_C(       929), UINT32_C(       931), UINT32_C(       202) } },
      { { SIMDE_FLOAT32_C(   823.82), SIMDE_FLOAT32_C(   606.62), SIMDE_FLOAT32_C(   954.90), SIMDE_FLOAT32_C(    91.10) },
        { UINT32_C(       823), UINT32_C(       606), UINT32_C(       954), UINT32_C(        91) } },
      { { SIMDE_FLOAT32_C(   397.15), SIMDE_FLOAT32_C(   429.48), SIMDE_FLOAT32_C(   743.81), SIMDE_FLOAT32_C(   882.99) },
        { UINT32_C(       397), UINT32_C(       429), UINT32_C(       743), UINT32_C(       882) } },
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t r = simde_wasm_u32x4_trunc_sat_f32x4(a);
      simde_test_wasm_u32x4_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    simde_float32 inputs[8 * 1 * (sizeof(simde_v128_t) / sizeof(simde_float32))];
    simde_test_wasm_f32x4_random_full(8, 1, inputs, SIMDE_FLOAT32_C(0.0), SIMDE_FLOAT32_C(1000.0), HEDLEY_STATIC_CAST(SimdeTestVecFloatType, SIMDE_TEST_VEC_FLOAT_NAN | SIMDE_TEST_VEC_FLOAT_EQUAL));
    for (size_t i = 0 ; i < 8 ; i++) {
      simde_v128_t
        a = simde_test_wasm_f32x4_random_full_extract(1, inputs, i, 0),
        r;

      r = simde_wasm_u32x4_trunc_sat_f32x4(a);

      simde_test_wasm_f32x4_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_u32x4_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_i32x4_trunc_sat_f64x2_zero(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      simde_float64 a[sizeof(simde_v128_t) / sizeof(simde_float64)];
      int32_t r[sizeof(simde_v128_t) / sizeof(int32_t)];
    } test_vec[] = {
      #if !defined(SIMDE_FAST_NANS)
      { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   908.74) },
        {  INT32_C(           0),  INT32_C(         908),  INT32_C(           0),  INT32_C(           0) } },
      { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(    72.59) },
        {  INT32_C(           0),  INT32_C(          72),  INT32_C(           0),  INT32_C(           0) } },
      #endif
      #if !defined(SIMDE_FAST_CONVERSION_RANGE)
      { { SIMDE_FLOAT64_C(2467989973.94), SIMDE_FLOAT64_C(9026336306.25) },
        {              INT32_MAX,              INT32_MAX,  INT32_C(           0),  INT32_C(           0) } },
      { { SIMDE_FLOAT64_C(3906371758.28), SIMDE_FLOAT64_C(-5314359485.78) },
        {              INT32_MAX,              INT32_MIN,  INT32_C(           0),  INT32_C(           0) } },
      { { SIMDE_FLOAT64_C(-3541575229.51), SIMDE_FLOAT64_C(4213050414.91) },
        {              INT32_MIN,              INT32_MAX,  INT32_C(           0),  INT32_C(           0) } },
      { { SIMDE_FLOAT64_C(-7124868676.59), SIMDE_FLOAT64_C(8385381185.63) },
        {              INT32_MIN,              INT32_MAX,  INT32_C(           0),  INT32_C(           0) } },
      #endif
      { { SIMDE_FLOAT64_C(  -387.80), SIMDE_FLOAT64_C(   -77.02) },
        { -INT32_C(         387), -INT32_C(          77),  INT32_C(           0),  INT32_C(           0) } },
      { { SIMDE_FLOAT64_C(   334.39), SIMDE_FLOAT64_C(  -308.23) },
        {  INT32_C(         334), -INT32_C(         308),  INT32_C(           0),  INT32_C(           0) } },
      { { SIMDE_FLOAT64_C(  -944.20), SIMDE_FLOAT64_C(   240.91) },
        { -INT32_C(         944),  INT32_C(         240),  INT32_C(           0),  INT32_C(           0) } },
      { { SIMDE_FLOAT64_C(   -63.87), SIMDE_FLOAT64_C(  -683.50) },
        { -INT32_C(          63), -INT32_C(         683),  INT32_C(           0),  INT32_C(           0) } },
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t r = simde_wasm_i32x4_trunc_sat_f64x2_zero(a);
      simde_test_wasm_i32x4_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
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

      r = simde_wasm_i32x4_trunc_sat_f64x2_zero(a);

      simde_test_wasm_f64x2_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_i32x4_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_u32x4_trunc_sat_f64x2_zero(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      simde_float64 a[sizeof(simde_v128_t) / sizeof(simde_float64)];
      uint32_t r[sizeof(simde_v128_t) / sizeof(uint32_t)];
    } test_vec[] = {
      #if !defined(SIMDE_FAST_NANS)
      { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(423661167.93) },
        { UINT32_C(         0), UINT32_C( 423661167), UINT32_C(         0), UINT32_C(         0) } },
      { { SIMDE_FLOAT64_C(3508164432.60) , SIMDE_MATH_NAN },
        { UINT32_C(3508164432), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0) } },
      #endif

      #if !defined(SIMDE_FAST_CONVERSION_RANGE)
      { { SIMDE_FLOAT64_C(3403022658.73), SIMDE_FLOAT64_C(-4813130849.42) },
        { UINT32_C(3403022658), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0) } },
      { { SIMDE_FLOAT64_C(7413432522.40), SIMDE_FLOAT64_C(-5380693988.59) },
        {           UINT32_MAX, UINT32_C(         0), UINT32_C(         0), UINT32_C(         0) } },
      { { SIMDE_FLOAT64_C(-6543147674.08), SIMDE_FLOAT64_C(1765141762.68) },
        { UINT32_C(         0), UINT32_C(1765141762), UINT32_C(         0), UINT32_C(         0) } },
      { { SIMDE_FLOAT64_C(4736220247.46), SIMDE_FLOAT64_C(-5257867414.16) },
        {           UINT32_MAX, UINT32_C(         0), UINT32_C(         0), UINT32_C(         0) } },
      #endif

      { { SIMDE_FLOAT64_C(   193.47), SIMDE_FLOAT64_C(   740.12) },
        { UINT32_C(       193), UINT32_C(       740), UINT32_C(         0), UINT32_C(         0) } },
      { { SIMDE_FLOAT64_C(   982.92), SIMDE_FLOAT64_C(   945.61) },
        { UINT32_C(       982), UINT32_C(       945), UINT32_C(         0), UINT32_C(         0) } },
      { { SIMDE_FLOAT64_C(   760.13), SIMDE_FLOAT64_C(   958.33) },
        { UINT32_C(       760), UINT32_C(       958), UINT32_C(         0), UINT32_C(         0) } },
      { { SIMDE_FLOAT64_C(   347.44), SIMDE_FLOAT64_C(   336.36) },
        { UINT32_C(       347), UINT32_C(       336), UINT32_C(         0), UINT32_C(         0) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t r = simde_wasm_u32x4_trunc_sat_f64x2_zero(a);
      simde_test_wasm_u32x4_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    simde_float64 inputs[8 * 1 * (sizeof(simde_v128_t) / sizeof(simde_float64))];
    simde_test_wasm_f64x2_random_full(8, 1, inputs, -SIMDE_FLOAT64_C(10000000000.0), SIMDE_FLOAT64_C(10000000000.0), HEDLEY_STATIC_CAST(SimdeTestVecFloatType, SIMDE_TEST_VEC_FLOAT_NAN | SIMDE_TEST_VEC_FLOAT_EQUAL));
    for (size_t i = 0 ; i < 8 ; i++) {
      simde_v128_t
        a = simde_test_wasm_f64x2_random_full_extract(1, inputs, i, 0),
        r;

      r = simde_wasm_u32x4_trunc_sat_f64x2_zero(a);

      simde_test_wasm_f64x2_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_u32x4_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i32x4_trunc_sat_f32x4)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_u32x4_trunc_sat_f32x4)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i32x4_trunc_sat_f64x2_zero)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_u32x4_trunc_sat_f64x2_zero)
SIMDE_TEST_FUNC_LIST_END

#include "test-simd128-footer.h"
