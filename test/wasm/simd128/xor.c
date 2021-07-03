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

#define SIMDE_TEST_WASM_SIMD128_INSN xor
#include "../../../simde/wasm/simd128.h"
#include "test-simd128.h"

static int
test_simde_wasm_v128_xor(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int32_t a[sizeof(simde_v128_t) / sizeof(int32_t)];
      int32_t b[sizeof(simde_v128_t) / sizeof(int32_t)];
      int32_t r[sizeof(simde_v128_t) / sizeof(int32_t)];
    } test_vec[8] = {
      { {  INT32_C(  2051961404), -INT32_C(  1205924268), -INT32_C(  1669288674),  INT32_C(   789613412) },
        {  INT32_C(  1417428958), -INT32_C(  1175813869),  INT32_C(  2138231816),  INT32_C(   631328573) },
        {  INT32_C(   775048674),  INT32_C(    32870215), -INT32_C(   470648554),  INT32_C(   179422297) } },
      { { -INT32_C(   688329886), -INT32_C(   757214396), -INT32_C(   975112267), -INT32_C(  1588423127) },
        { -INT32_C(  2104873782), -INT32_C(  1272155320),  INT32_C(   602242502),  INT32_C(  1748462057) },
        {  INT32_C(  1416808360),  INT32_C(  1727111180), -INT32_C(   435844493), -INT32_C(   916062272) } },
      { { -INT32_C(  1354983450),  INT32_C(   844799082), -INT32_C(  1514664849), -INT32_C(  2085559560) },
        { -INT32_C(  1333968989),  INT32_C(   849386353), -INT32_C(  1055649982),  INT32_C(  1007619838) },
        {  INT32_C(   524396613),  INT32_C(    16385819),  INT32_C(  1688994605), -INT32_C(  1077941242) } },
      { {  INT32_C(   531923759),  INT32_C(   498117089),  INT32_C(  1105672326),  INT32_C(  1633757880) },
        { -INT32_C(   690053785),  INT32_C(  1482350699), -INT32_C(  1682738275),  INT32_C(  1489874131) },
        { -INT32_C(   915792312),  INT32_C(  1172982154), -INT32_C(   632009957),  INT32_C(   967607915) } },
      { {  INT32_C(    60776722),  INT32_C(  1116587528),  INT32_C(   775213818),  INT32_C(  1729341480) },
        { -INT32_C(   380129426),  INT32_C(  1010165569), -INT32_C(   423237345), -INT32_C(   743633422) },
        { -INT32_C(   355938692),  INT32_C(  2125996361), -INT32_C(   923714587), -INT32_C(  1262574118) } },
      { { -INT32_C(   978050421),  INT32_C(   830148909), -INT32_C(  1057018831),  INT32_C(  1007301230) },
        {  INT32_C(  1547923948),  INT32_C(   668833940), -INT32_C(  1122585195), -INT32_C(  1066910362) },
        { -INT32_C(  1711844505),  INT32_C(   380012985),  INT32_C(  2112461220), -INT32_C(    60682488) } },
      { { -INT32_C(  1434778367),  INT32_C(  1487420865), -INT32_C(  1300559335),  INT32_C(  1691213612) },
        {  INT32_C(   919357929),  INT32_C(  1280385419), -INT32_C(  2043653071),  INT32_C(  1184622470) },
        { -INT32_C(  1665708824),  INT32_C(   351870026),  INT32_C(   877354536),  INT32_C(   576075946) } },
      { { -INT32_C(  1742394622),  INT32_C(  2099926273),  INT32_C(  1348833472),  INT32_C(   306653958) },
        { -INT32_C(  1803527991),  INT32_C(    49379912), -INT32_C(   523226647),  INT32_C(  1051476044) },
        {  INT32_C(   212169675),  INT32_C(  2145070921), -INT32_C(  1330274007),  INT32_C(   753625930) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_v128_xor(a, b);
      simde_test_wasm_i32x4_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      simde_v128_t a = simde_test_wasm_i32x4_random();
      simde_v128_t b = simde_test_wasm_i32x4_random();
      simde_v128_t r = simde_wasm_v128_xor(a, b);

      simde_test_wasm_i32x4_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_i32x4_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_i32x4_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_v128_xor)
SIMDE_TEST_FUNC_LIST_END

#include "test-simd128-footer.h"
