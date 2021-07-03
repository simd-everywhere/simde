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

#define SIMDE_TEST_WASM_SIMD128_INSN or
#include "../../../simde/wasm/simd128.h"
#include "test-simd128.h"

static int
test_simde_wasm_v128_or(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int32_t a[sizeof(simde_v128_t) / sizeof(int32_t)];
      int32_t b[sizeof(simde_v128_t) / sizeof(int32_t)];
      int32_t r[sizeof(simde_v128_t) / sizeof(int32_t)];
    } test_vec[8] = {
      { { -INT32_C(   831128329), -INT32_C(   763070371), -INT32_C(   843818562), -INT32_C(  1818645949) },
        {  INT32_C(    15406501),  INT32_C(  1951768686), -INT32_C(   329708067), -INT32_C(  2121071881) },
        { -INT32_C(   822084105), -INT32_C(   153749377), -INT32_C(   302162433), -INT32_C(  1818514697) } },
      { { -INT32_C(   872345894), -INT32_C(  2079242106),  INT32_C(  1799320677),  INT32_C(  1925061086) },
        {  INT32_C(    97632876), -INT32_C(  1103251685), -INT32_C(   888121609),  INT32_C(  1380725632) },
        { -INT32_C(   841888002), -INT32_C(  1103233121), -INT32_C(   348162313),  INT32_C(  1929264094) } },
      { { -INT32_C(   318914417),  INT32_C(  1453760906), -INT32_C(  1919121875),  INT32_C(  1203884254) },
        {  INT32_C(  1224775634),  INT32_C(  1103327873),  INT32_C(  1564543379), -INT32_C(  1143341880) },
        { -INT32_C(   302131233),  INT32_C(  1474818955), -INT32_C(   572682305), -INT32_C(     2491170) } },
      { { -INT32_C(   142008072),  INT32_C(  1610479896),  INT32_C(  1663103299), -INT32_C(    65160278) },
        {  INT32_C(  1751932724), -INT32_C(   160432335),  INT32_C(  1386057888), -INT32_C(   140106925) },
        { -INT32_C(     1212420), -INT32_C(         199),  INT32_C(  1941828067), -INT32_C(     4211717) } },
      { { -INT32_C(  1634183619),  INT32_C(    93208719), -INT32_C(  1380557145), -INT32_C(  2121492156) },
        {  INT32_C(   379678406), -INT32_C(   348107212), -INT32_C(  1046726297), -INT32_C(  1132022539) },
        { -INT32_C(  1632010497), -INT32_C(   271692097), -INT32_C(   306282521), -INT32_C(  1114718731) } },
      { {  INT32_C(   827514578), -INT32_C(   421407886), -INT32_C(   752658670),  INT32_C(   288769948) },
        { -INT32_C(  1948673184), -INT32_C(   424034236),  INT32_C(    92115245),  INT32_C(  1017319664) },
        { -INT32_C(  1143218190), -INT32_C(   419835018), -INT32_C(   679487681),  INT32_C(  1035425788) } },
      { { -INT32_C(   839890687),  INT32_C(   945479520),  INT32_C(  1942053217), -INT32_C(   178090391) },
        {  INT32_C(  1990507712), -INT32_C(  2039198843),  INT32_C(   113589344), -INT32_C(  1477739644) },
        { -INT32_C(      721471), -INT32_C(  1098981403),  INT32_C(  2009431393), -INT32_C(   135528467) } },
      { {  INT32_C(   320697071), -INT32_C(  1383379060),  INT32_C(  2025822585), -INT32_C(   979407747) },
        {  INT32_C(  1962975057), -INT32_C(   399693130),  INT32_C(   322786360),  INT32_C(   821894924) },
        {  INT32_C(  1998454783), -INT32_C(   307269698),  INT32_C(  2076171641), -INT32_C(   167805059) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_v128_or(a, b);
      simde_test_wasm_i32x4_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      simde_v128_t a = simde_test_wasm_i32x4_random();
      simde_v128_t b = simde_test_wasm_i32x4_random();
      simde_v128_t r = simde_wasm_v128_or(a, b);

      simde_test_wasm_i32x4_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_i32x4_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_i32x4_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_v128_or)
SIMDE_TEST_FUNC_LIST_END

#include "test-simd128-footer.h"
