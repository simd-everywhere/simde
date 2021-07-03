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

#define SIMDE_TEST_WASM_SIMD128_INSN and
#include "../../../simde/wasm/simd128.h"
#include "test-simd128.h"

static int
test_simde_wasm_v128_and(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int32_t a[sizeof(simde_v128_t) / sizeof(int32_t)];
      int32_t b[sizeof(simde_v128_t) / sizeof(int32_t)];
      int32_t r[sizeof(simde_v128_t) / sizeof(int32_t)];
    } test_vec[8] = {
      { { -INT32_C(   844888310),  INT32_C(  1482986139),  INT32_C(  1019108070),  INT32_C(   175191630) },
        { -INT32_C(  1700574470),  INT32_C(   554262183),  INT32_C(   993690639),  INT32_C(   572303215) },
        { -INT32_C(  2002779638),  INT32_C(        4739),  INT32_C(   943325190),  INT32_C(    34612814) } },
      { {  INT32_C(   658428573), -INT32_C(  1088616388), -INT32_C(     5148002),  INT32_C(   973898937) },
        {  INT32_C(  1009127521), -INT32_C(  1742849001), -INT32_C(    99578471),  INT32_C(   100659815) },
        {  INT32_C(   606474241), -INT32_C(  1742993388), -INT32_C(    99614568),  INT32_C(      819233) } },
      { {  INT32_C(    35150068),  INT32_C(  1338916990),  INT32_C(   175852869), -INT32_C(  1717414159) },
        { -INT32_C(  1707697859), -INT32_C(   330088299),  INT32_C(  1269524622), -INT32_C(  2026811717) },
        {  INT32_C(    34609204),  INT32_C(  1279410196),  INT32_C(   170608644), -INT32_C(  2128591183) } },
      { { -INT32_C(  1823115492),  INT32_C(  1193695323), -INT32_C(  1946339596), -INT32_C(   375966159) },
        { -INT32_C(  1313847460),  INT32_C(   441839800), -INT32_C(   944262799), -INT32_C(   374754631) },
        { -INT32_C(  1861204196),  INT32_C(    33837080), -INT32_C(  2085277584), -INT32_C(   377408975) } },
      { { -INT32_C(  1953399952),  INT32_C(  1435489330),  INT32_C(  1173135837),  INT32_C(   988396031) },
        { -INT32_C(  2141131677),  INT32_C(   595564477), -INT32_C(   912366249),  INT32_C(   123186731) },
        { -INT32_C(  2147456928),  INT32_C(    17798192),  INT32_C(  1099702613),  INT32_C(    37857323) } },
      { {  INT32_C(  2141883790),  INT32_C(   653573419),  INT32_C(  1350824479), -INT32_C(   590218644) },
        {  INT32_C(   697172358),  INT32_C(  1683628978), -INT32_C(   168204930),  INT32_C(    75802722) },
        {  INT32_C(   696910214),  INT32_C(   609231138),  INT32_C(  1350656030),  INT32_C(    75540576) } },
      { { -INT32_C(   988308274),  INT32_C(  2029861663),  INT32_C(  1555024669), -INT32_C(   706636571) },
        { -INT32_C(  1878178111),  INT32_C(  1704819990),  INT32_C(   980976998), -INT32_C(  2119069004) },
        { -INT32_C(  2147154752),  INT32_C(  1620916502),  INT32_C(   405307652), -INT32_C(  2120118108) } },
      { { -INT32_C(   626145730), -INT32_C(  1295077633),  INT32_C(  1959056984), -INT32_C(   794615182) },
        { -INT32_C(  2066877554),  INT32_C(   799564550),  INT32_C(  1364727652),  INT32_C(  1391995277) },
        { -INT32_C(  2138193394),  INT32_C(   579346950),  INT32_C(  1346377280),  INT32_C(  1352671232) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_v128_and(a, b);
      simde_test_wasm_i32x4_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      simde_v128_t a = simde_test_wasm_i32x4_random();
      simde_v128_t b = simde_test_wasm_i32x4_random();
      simde_v128_t r = simde_wasm_v128_and(a, b);

      simde_test_wasm_i32x4_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_i32x4_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_i32x4_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_v128_and)
SIMDE_TEST_FUNC_LIST_END

#include "test-simd128-footer.h"
