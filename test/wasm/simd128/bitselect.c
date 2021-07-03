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

#define SIMDE_TEST_WASM_SIMD128_INSN bitselect
#include "../../../simde/wasm/simd128.h"
#include "test-simd128.h"

static int
test_simde_wasm_v128_bitselect(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int32_t a[sizeof(simde_v128_t) / sizeof(int32_t)];
      int32_t b[sizeof(simde_v128_t) / sizeof(int32_t)];
      int32_t mask[sizeof(simde_v128_t) / sizeof(int32_t)];
      int32_t r[sizeof(simde_v128_t) / sizeof(int32_t)];
    } test_vec[8] = {
      { {  INT32_C(   227297322),  INT32_C(   232401041),  INT32_C(  1772200295), -INT32_C(   969785133) },
        { -INT32_C(  1626973313), -INT32_C(  1203040342),  INT32_C(   251444033), -INT32_C(    21331767) },
        {  INT32_C(  1114449749),  INT32_C(   523277373),  INT32_C(  1685743617), -INT32_C(   732331740) },
        { -INT32_C(  1660004310), -INT32_C(  1386542189),  INT32_C(  1789178689), -INT32_C(   290324279) } },
      { { -INT32_C(  1089957040),  INT32_C(   705424626), -INT32_C(  1913946071), -INT32_C(   369980461) },
        { -INT32_C(  1889257757),  INT32_C(  1740476822),  INT32_C(  1565060785),  INT32_C(  2041896052) },
        { -INT32_C(  1186414306),  INT32_C(  1703090405), -INT32_C(  1854437432),  INT32_C(  1188532357) },
        { -INT32_C(  1087588367),  INT32_C(   574589426), -INT32_C(   848566215),  INT32_C(  2045955313) } },
      { { -INT32_C(  1070556089), -INT32_C(  1872980726), -INT32_C(   380184789), -INT32_C(   847122679) },
        {  INT32_C(  1270627530),  INT32_C(   440802631), -INT32_C(  1401529211),  INT32_C(   927038490) },
        { -INT32_C(   425544974),  INT32_C(  1641798736),  INT32_C(   254000993), -INT32_C(  1632735512) },
        { -INT32_C(   918774710),  INT32_C(   442275079), -INT32_C(  1453926491), -INT32_C(  1379828198) } },
      { {  INT32_C(  1873077993),  INT32_C(  1691238607),  INT32_C(   119440421),  INT32_C(   211809191) },
        { -INT32_C(  1510729833), -INT32_C(  1228688232), -INT32_C(   140859231), -INT32_C(   930821656) },
        {  INT32_C(  1671889598),  INT32_C(  2131002129), -INT32_C(   755254615),  INT32_C(  1700509159) },
        { -INT32_C(   403433559), -INT32_C(   456706935),  INT32_C(   656048161), -INT32_C(  1935672913) } },
      { { -INT32_C(    73578260), -INT32_C(    73582535),  INT32_C(   348646968),  INT32_C(   382224701) },
        {  INT32_C(   946309052),  INT32_C(    88550129),  INT32_C(   761633965), -INT32_C(   876445557) },
        { -INT32_C(  1917867293),  INT32_C(   666735584), -INT32_C(   854671990), -INT32_C(  1805076598) },
        { -INT32_C(  1177743876),  INT32_C(   601831473),  INT32_C(   610774061),  INT32_C(  1607074057) } },
      { { -INT32_C(   593890937), -INT32_C(  1410351727), -INT32_C(  1820533432), -INT32_C(   932417013) },
        {  INT32_C(  1957111661),  INT32_C(   948422972), -INT32_C(  1411252042),  INT32_C(  1939898221) },
        { -INT32_C(  1533503123),  INT32_C(  1985645245), -INT32_C(   946405782), -INT32_C(  1994265358) },
        { -INT32_C(   725633275),  INT32_C(   718260625), -INT32_C(  1418404644), -INT32_C(    90148081) } },
      { { -INT32_C(  2067318343),  INT32_C(   791868726),  INT32_C(   100587703),  INT32_C(  1604211346) },
        {  INT32_C(  1468301677),  INT32_C(  2121378529),  INT32_C(   977173693), -INT32_C(   264177745) },
        {  INT32_C(   468746737), -INT32_C(  2062020716),  INT32_C(   605784572),  INT32_C(  1538148415) },
        {  INT32_C(  1153696189),  INT32_C(  2138154357),  INT32_C(   507444405), -INT32_C(    70322286) } },
      { { -INT32_C(  1160598355),  INT32_C(   581665646), -INT32_C(    56065281),  INT32_C(   917186017) },
        {  INT32_C(  1743902844),  INT32_C(   812853810), -INT32_C(   148441715),  INT32_C(   484214627) },
        { -INT32_C(  1687883391), -INT32_C(   929379885),  INT32_C(   614998761),  INT32_C(    86308397) },
        { -INT32_C(    19814147),  INT32_C(   820749154), -INT32_C(   139536403),  INT32_C(   486024547) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t mask = simde_wasm_v128_load(test_vec[i].mask);
      simde_v128_t r = simde_wasm_v128_bitselect(a, b, mask);
      simde_test_wasm_i32x4_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      simde_v128_t a = simde_test_wasm_i32x4_random();
      simde_v128_t b = simde_test_wasm_i32x4_random();
      simde_v128_t mask = simde_test_wasm_i32x4_random();
      simde_v128_t r = simde_wasm_v128_bitselect(a, b, mask);

      simde_test_wasm_i32x4_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_i32x4_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_i32x4_write(3, mask, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_i32x4_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_v128_bitselect)
SIMDE_TEST_FUNC_LIST_END

#include "test-simd128-footer.h"
