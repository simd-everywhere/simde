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

#define SIMDE_TEST_WASM_SIMD128_INSN not
#include "../../../simde/wasm/simd128.h"
#include "test-simd128.h"

static int
test_simde_wasm_v128_not(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int32_t a[sizeof(simde_v128_t) / sizeof(int32_t)];
      int32_t r[sizeof(simde_v128_t) / sizeof(int32_t)];
    } test_vec[8] = {
      { {  INT32_C(   515932598),  INT32_C(   746408309),  INT32_C(  1779638880), -INT32_C(  1101043863) },
        { -INT32_C(   515932599), -INT32_C(   746408310), -INT32_C(  1779638881),  INT32_C(  1101043862) } },
      { {  INT32_C(   428213695), -INT32_C(   295692393),  INT32_C(   489934202), -INT32_C(  1819386681) },
        { -INT32_C(   428213696),  INT32_C(   295692392), -INT32_C(   489934203),  INT32_C(  1819386680) } },
      { {  INT32_C(  1738041066),  INT32_C(  1467279200), -INT32_C(   329975811), -INT32_C(  2059954510) },
        { -INT32_C(  1738041067), -INT32_C(  1467279201),  INT32_C(   329975810),  INT32_C(  2059954509) } },
      { {  INT32_C(  1581727137), -INT32_C(   875786051), -INT32_C(   652953493),  INT32_C(   870510671) },
        { -INT32_C(  1581727138),  INT32_C(   875786050),  INT32_C(   652953492), -INT32_C(   870510672) } },
      { { -INT32_C(  1019211883),  INT32_C(  1903541445), -INT32_C(   660613200), -INT32_C(  1989421816) },
        {  INT32_C(  1019211882), -INT32_C(  1903541446),  INT32_C(   660613199),  INT32_C(  1989421815) } },
      { {  INT32_C(  1780735486), -INT32_C(  1544197940), -INT32_C(  1855592312), -INT32_C(   741523336) },
        { -INT32_C(  1780735487),  INT32_C(  1544197939),  INT32_C(  1855592311),  INT32_C(   741523335) } },
      { {  INT32_C(    12893586),  INT32_C(  1976518778),  INT32_C(   356463971), -INT32_C(  1832821729) },
        { -INT32_C(    12893587), -INT32_C(  1976518779), -INT32_C(   356463972),  INT32_C(  1832821728) } },
      { { -INT32_C(  2070944084), -INT32_C(  1081049468), -INT32_C(    75899586), -INT32_C(  1583988878) },
        {  INT32_C(  2070944083),  INT32_C(  1081049467),  INT32_C(    75899585),  INT32_C(  1583988877) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t r = simde_wasm_v128_not(a);
      simde_test_wasm_i32x4_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      simde_v128_t a = simde_test_wasm_i32x4_random();
      simde_v128_t r = simde_wasm_v128_not(a);

      simde_test_wasm_i32x4_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_i32x4_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_v128_not)
SIMDE_TEST_FUNC_LIST_END

#include "test-simd128-footer.h"
