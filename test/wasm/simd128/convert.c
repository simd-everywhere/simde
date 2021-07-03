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

#define SIMDE_TEST_WASM_SIMD128_INSN convert
#include "../../../simde/wasm/simd128.h"
#include "test-simd128.h"

static int
test_simde_wasm_f32x4_convert_i32x4(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int32_t a[sizeof(simde_v128_t) / sizeof(simde_float32)];
      simde_float32 r[sizeof(simde_v128_t) / sizeof(simde_float32)];
    } test_vec[8] = {
      { { -INT32_C(         313),  INT32_C(         975), -INT32_C(         337),  INT32_C(         213) },
        { SIMDE_FLOAT32_C(  -313.00), SIMDE_FLOAT32_C(   975.00), SIMDE_FLOAT32_C(  -337.00), SIMDE_FLOAT32_C(   213.00) } },
      { { -INT32_C(         109), -INT32_C(         602), -INT32_C(         161), -INT32_C(          66) },
        { SIMDE_FLOAT32_C(  -109.00), SIMDE_FLOAT32_C(  -602.00), SIMDE_FLOAT32_C(  -161.00), SIMDE_FLOAT32_C(   -66.00) } },
      { {  INT32_C(         446),  INT32_C(         567),  INT32_C(         325),  INT32_C(        1023) },
        { SIMDE_FLOAT32_C(   446.00), SIMDE_FLOAT32_C(   567.00), SIMDE_FLOAT32_C(   325.00), SIMDE_FLOAT32_C(  1023.00) } },
      { {  INT32_C(         971), -INT32_C(          64), -INT32_C(         593),  INT32_C(         630) },
        { SIMDE_FLOAT32_C(   971.00), SIMDE_FLOAT32_C(   -64.00), SIMDE_FLOAT32_C(  -593.00), SIMDE_FLOAT32_C(   630.00) } },
      { {  INT32_C(         550),  INT32_C(         239),  INT32_C(         847), -INT32_C(         179) },
        { SIMDE_FLOAT32_C(   550.00), SIMDE_FLOAT32_C(   239.00), SIMDE_FLOAT32_C(   847.00), SIMDE_FLOAT32_C(  -179.00) } },
      { { -INT32_C(         730),  INT32_C(         125), -INT32_C(         994), -INT32_C(         320) },
        { SIMDE_FLOAT32_C(  -730.00), SIMDE_FLOAT32_C(   125.00), SIMDE_FLOAT32_C(  -994.00), SIMDE_FLOAT32_C(  -320.00) } },
      { {  INT32_C(         352),  INT32_C(         439),  INT32_C(         669),  INT32_C(          76) },
        { SIMDE_FLOAT32_C(   352.00), SIMDE_FLOAT32_C(   439.00), SIMDE_FLOAT32_C(   669.00), SIMDE_FLOAT32_C(    76.00) } },
      { { -INT32_C(         650),  INT32_C(         381),  INT32_C(         792),  INT32_C(         120) },
        { SIMDE_FLOAT32_C(  -650.00), SIMDE_FLOAT32_C(   381.00), SIMDE_FLOAT32_C(   792.00), SIMDE_FLOAT32_C(   120.00) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t r = simde_wasm_f32x4_convert_i32x4(a);
      simde_test_wasm_f32x4_assert_equal(r, simde_wasm_v128_load(test_vec[i].r), 3);
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      simde_v128_t a = simde_wasm_i32x4_shr(simde_test_wasm_i32x4_random(), 21);
      simde_v128_t r;

      r = simde_wasm_f32x4_convert_i32x4(a);

      simde_test_wasm_i32x4_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_f32x4_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_f32x4_convert_u32x4(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      uint32_t a[sizeof(simde_v128_t) / sizeof(simde_float32)];
      simde_float32 r[sizeof(simde_v128_t) / sizeof(simde_float32)];
    } test_vec[8] = {
      { { UINT32_C(      1048), UINT32_C(       717), UINT32_C(       532), UINT32_C(      1192) },
        { SIMDE_FLOAT32_C(  1048.00), SIMDE_FLOAT32_C(   717.00), SIMDE_FLOAT32_C(   532.00), SIMDE_FLOAT32_C(  1192.00) } },
      { { UINT32_C(       863), UINT32_C(      1695), UINT32_C(      2024), UINT32_C(       308) },
        { SIMDE_FLOAT32_C(   863.00), SIMDE_FLOAT32_C(  1695.00), SIMDE_FLOAT32_C(  2024.00), SIMDE_FLOAT32_C(   308.00) } },
      { { UINT32_C(      1034), UINT32_C(       548), UINT32_C(       297), UINT32_C(      1936) },
        { SIMDE_FLOAT32_C(  1034.00), SIMDE_FLOAT32_C(   548.00), SIMDE_FLOAT32_C(   297.00), SIMDE_FLOAT32_C(  1936.00) } },
      { { UINT32_C(       813), UINT32_C(      1131), UINT32_C(      1081), UINT32_C(      1627) },
        { SIMDE_FLOAT32_C(   813.00), SIMDE_FLOAT32_C(  1131.00), SIMDE_FLOAT32_C(  1081.00), SIMDE_FLOAT32_C(  1627.00) } },
      { { UINT32_C(      2035), UINT32_C(      1675), UINT32_C(      1499), UINT32_C(      1117) },
        { SIMDE_FLOAT32_C(  2035.00), SIMDE_FLOAT32_C(  1675.00), SIMDE_FLOAT32_C(  1499.00), SIMDE_FLOAT32_C(  1117.00) } },
      { { UINT32_C(       602), UINT32_C(       107), UINT32_C(      1011), UINT32_C(      1471) },
        { SIMDE_FLOAT32_C(   602.00), SIMDE_FLOAT32_C(   107.00), SIMDE_FLOAT32_C(  1011.00), SIMDE_FLOAT32_C(  1471.00) } },
      { { UINT32_C(       457), UINT32_C(      1316), UINT32_C(      1876), UINT32_C(      1674) },
        { SIMDE_FLOAT32_C(   457.00), SIMDE_FLOAT32_C(  1316.00), SIMDE_FLOAT32_C(  1876.00), SIMDE_FLOAT32_C(  1674.00) } },
      { { UINT32_C(       118), UINT32_C(       700), UINT32_C(      1929), UINT32_C(      1696) },
        { SIMDE_FLOAT32_C(   118.00), SIMDE_FLOAT32_C(   700.00), SIMDE_FLOAT32_C(  1929.00), SIMDE_FLOAT32_C(  1696.00) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t r = simde_wasm_f32x4_convert_u32x4(a);
      simde_test_wasm_f32x4_assert_equal(r, simde_wasm_v128_load(test_vec[i].r), 3);
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      simde_v128_t a = simde_wasm_u32x4_shr(simde_test_wasm_u32x4_random(), 21);
      simde_v128_t r;

      r = simde_wasm_f32x4_convert_u32x4(a);

      simde_test_wasm_u32x4_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_f32x4_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_f64x2_convert_low_i32x4(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int32_t a[sizeof(simde_v128_t) / sizeof(simde_float32)];
      simde_float64 r[sizeof(simde_v128_t) / sizeof(simde_float64)];
    } test_vec[8] = {
      { {  INT32_C(  1611388214), -INT32_C(  1113510886), -INT32_C(   936119586),  INT32_C(  1007886067) },
        { SIMDE_FLOAT64_C(1611388214.00), SIMDE_FLOAT64_C(-1113510886.00) } },
      { {  INT32_C(   773736979), -INT32_C(  1979875352), -INT32_C(    25812060),  INT32_C(  1678789003) },
        { SIMDE_FLOAT64_C(773736979.00), SIMDE_FLOAT64_C(-1979875352.00) } },
      { { -INT32_C(   389448082), -INT32_C(  1316288772),  INT32_C(   624371831),  INT32_C(  1197575151) },
        { SIMDE_FLOAT64_C(-389448082.00), SIMDE_FLOAT64_C(-1316288772.00) } },
      { { -INT32_C(    96152577), -INT32_C(  1785397828), -INT32_C(   419417322),  INT32_C(  1772721216) },
        { SIMDE_FLOAT64_C(-96152577.00), SIMDE_FLOAT64_C(-1785397828.00) } },
      { { -INT32_C(  1540025711),  INT32_C(   227900302),  INT32_C(   646060200), -INT32_C(  1095695639) },
        { SIMDE_FLOAT64_C(-1540025711.00), SIMDE_FLOAT64_C(227900302.00) } },
      { { -INT32_C(  1597639206),  INT32_C(  1994338276),  INT32_C(  1452897048), -INT32_C(   684739379) },
        { SIMDE_FLOAT64_C(-1597639206.00), SIMDE_FLOAT64_C(1994338276.00) } },
      { {  INT32_C(   384945833), -INT32_C(   555607301), -INT32_C(   463753869), -INT32_C(   101723402) },
        { SIMDE_FLOAT64_C(384945833.00), SIMDE_FLOAT64_C(-555607301.00) } },
      { {  INT32_C(  1572260835), -INT32_C(   426455351),  INT32_C(   900360167), -INT32_C(  1461513427) },
        { SIMDE_FLOAT64_C(1572260835.00), SIMDE_FLOAT64_C(-426455351.00) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t r = simde_wasm_f64x2_convert_low_i32x4(a);
      simde_test_wasm_f64x2_assert_equal(r, simde_wasm_v128_load(test_vec[i].r), 3);
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      simde_v128_t a = simde_test_wasm_i32x4_random();
      simde_v128_t r;

      r = simde_wasm_f64x2_convert_low_i32x4(a);

      simde_test_wasm_i32x4_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_f64x2_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_f64x2_convert_low_u32x4(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      uint32_t a[sizeof(simde_v128_t) / sizeof(simde_float32)];
      simde_float64 r[sizeof(simde_v128_t) / sizeof(simde_float64)];
    } test_vec[8] = {
      { { UINT32_C(1084561901), UINT32_C( 772036979), UINT32_C(1220837470), UINT32_C( 703522408) },
        { SIMDE_FLOAT64_C(1084561901.00), SIMDE_FLOAT64_C(772036979.00) } },
      { { UINT32_C(1644971870), UINT32_C(4178379582), UINT32_C( 831217659), UINT32_C(2681601791) },
        { SIMDE_FLOAT64_C(1644971870.00), SIMDE_FLOAT64_C(4178379582.00) } },
      { { UINT32_C(2594276455), UINT32_C(3877562428), UINT32_C(2020596256), UINT32_C(3353226095) },
        { SIMDE_FLOAT64_C(2594276455.00), SIMDE_FLOAT64_C(3877562428.00) } },
      { { UINT32_C(3418266555), UINT32_C(2298252744), UINT32_C(3287719020), UINT32_C( 666510597) },
        { SIMDE_FLOAT64_C(3418266555.00), SIMDE_FLOAT64_C(2298252744.00) } },
      { { UINT32_C(1113653601), UINT32_C(3540530899), UINT32_C(4279935173), UINT32_C(3789434620) },
        { SIMDE_FLOAT64_C(1113653601.00), SIMDE_FLOAT64_C(3540530899.00) } },
      { { UINT32_C(2998344259), UINT32_C(3066136244), UINT32_C( 514329509), UINT32_C(3343742971) },
        { SIMDE_FLOAT64_C(2998344259.00), SIMDE_FLOAT64_C(3066136244.00) } },
      { { UINT32_C( 708639512), UINT32_C(  95159601), UINT32_C(2650161282), UINT32_C(2072584590) },
        { SIMDE_FLOAT64_C(708639512.00), SIMDE_FLOAT64_C(95159601.00) } },
      { { UINT32_C(2044934440), UINT32_C(1043334735), UINT32_C( 862177235), UINT32_C( 875589411) },
        { SIMDE_FLOAT64_C(2044934440.00), SIMDE_FLOAT64_C(1043334735.00) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t r = simde_wasm_f64x2_convert_low_u32x4(a);
      simde_test_wasm_f64x2_assert_equal(r, simde_wasm_v128_load(test_vec[i].r), 3);
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      simde_v128_t a = simde_test_wasm_u32x4_random();
      simde_v128_t r;

      r = simde_wasm_f64x2_convert_low_u32x4(a);

      simde_test_wasm_u32x4_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_f64x2_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_f32x4_convert_i32x4)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_f32x4_convert_u32x4)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_f64x2_convert_low_i32x4)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_f64x2_convert_low_u32x4)
SIMDE_TEST_FUNC_LIST_END

#include "test-simd128-footer.h"
