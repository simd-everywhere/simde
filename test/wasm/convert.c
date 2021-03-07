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

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_f32x4_convert_i32x4)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_f32x4_convert_u32x4)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/test-x86-footer.h>
