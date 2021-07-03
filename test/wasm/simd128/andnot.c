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

#define SIMDE_TEST_WASM_SIMD128_INSN andnot
#include "../../../simde/wasm/simd128.h"
#include "test-simd128.h"

static int
test_simde_wasm_v128_andnot(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int32_t a[sizeof(simde_v128_t) / sizeof(int32_t)];
      int32_t b[sizeof(simde_v128_t) / sizeof(int32_t)];
      int32_t r[sizeof(simde_v128_t) / sizeof(int32_t)];
    } test_vec[8] = {
      { { -INT32_C(  1727715029), -INT32_C(  2075220586),  INT32_C(  1901056913),  INT32_C(  1543642372) },
        {  INT32_C(   291497278), -INT32_C(    97942033),  INT32_C(  1935930168),  INT32_C(  1180386558) },
        { -INT32_C(  2013263871),  INT32_C(    71704592),  INT32_C(      786561),  INT32_C(   402659584) } },
      { { -INT32_C(  1841624229), -INT32_C(   357952261), -INT32_C(   541090575),  INT32_C(  1226144617) },
        {  INT32_C(  1001232110), -INT32_C(   844917971),  INT32_C(  1508017574),  INT32_C(  1824625812) },
        { -INT32_C(  2146301679),  INT32_C(   570950866), -INT32_C(  2044913583),  INT32_C(    18115433) } },
      { { -INT32_C(  1819748162), -INT32_C(  1050998051), -INT32_C(   980754462),  INT32_C(  1863705931) },
        {  INT32_C(    95316415), -INT32_C(   706147665), -INT32_C(  2021044584), -INT32_C(  1875423967) },
        { -INT32_C(  1845456896),  INT32_C(     1179728),  INT32_C(  1073910114),  INT32_C(  1862312010) } },
      { {  INT32_C(  1044942500), -INT32_C(  1705358941),  INT32_C(  1431245148),  INT32_C(   966244383) },
        { -INT32_C(   797476445),  INT32_C(  1461811261),  INT32_C(   462930847),  INT32_C(   702393670) },
        {  INT32_C(   772310532), -INT32_C(  2007367294),  INT32_C(  1145573440),  INT32_C(   268570649) } },
      { { -INT32_C(  1175588088), -INT32_C(  2057772217),  INT32_C(  2043431532), -INT32_C(  1822596236) },
        {  INT32_C(   988869115), -INT32_C(   246195529),  INT32_C(  1485991195), -INT32_C(  1281239764) },
        { -INT32_C(  2129853952),  INT32_C(    67674432),  INT32_C(   558629476),  INT32_C(     6038096) } },
      { { -INT32_C(  2024307961),  INT32_C(   569956661),  INT32_C(   252218251),  INT32_C(  1484416690) },
        { -INT32_C(   924600357),  INT32_C(  1768716982), -INT32_C(  1473316270), -INT32_C(   433945842) },
        {  INT32_C(   118751236),  INT32_C(     9470209),  INT32_C(   117440905),  INT32_C(   408446128) } },
      { { -INT32_C(   174204972),  INT32_C(   881733820), -INT32_C(  1375564686),  INT32_C(  1273941351) },
        {  INT32_C(    76190903),  INT32_C(   112903092),  INT32_C(   549633542),  INT32_C(  1779059775) },
        { -INT32_C(   250264768),  INT32_C(   805580808), -INT32_C(  1912602512),  INT32_C(    31752512) } },
      { { -INT32_C(   228486349), -INT32_C(  1201564435), -INT32_C(   337508749), -INT32_C(  2084166389) },
        {  INT32_C(   530637470),  INT32_C(  1592435891), -INT32_C(  2060269424),  INT32_C(   133192109) },
        { -INT32_C(   532606687), -INT32_C(  1610543028),  INT32_C(  1790969443), -INT32_C(  2147081214) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_v128_andnot(a, b);
      simde_test_wasm_i32x4_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      simde_v128_t a = simde_test_wasm_i32x4_random();
      simde_v128_t b = simde_test_wasm_i32x4_random();
      simde_v128_t r = simde_wasm_v128_andnot(a, b);

      simde_test_wasm_i32x4_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_i32x4_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_i32x4_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_v128_andnot)
SIMDE_TEST_FUNC_LIST_END

#include "test-simd128-footer.h"
