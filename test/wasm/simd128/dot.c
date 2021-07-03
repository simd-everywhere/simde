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

#define SIMDE_TEST_WASM_SIMD128_INSN dot
#include "../../../simde/wasm/simd128.h"
#include "test-simd128.h"

static int
test_simde_wasm_i32x4_dot_i16x8(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int16_t a[sizeof(simde_v128_t) / sizeof(int16_t)];
      int16_t b[sizeof(simde_v128_t) / sizeof(int16_t)];
      int32_t r[sizeof(simde_v128_t) / sizeof(int32_t)];
    } test_vec[] = {
      { {  INT16_C( 23410),  INT16_C( 13252), -INT16_C(  8673), -INT16_C( 10531),  INT16_C( 12591), -INT16_C( 20710), -INT16_C(  3546), -INT16_C(  6181) },
        { -INT16_C( 15539), -INT16_C( 27063),  INT16_C( 32058), -INT16_C( 23735),  INT16_C( 22888), -INT16_C( 13917), -INT16_C( 13656),  INT16_C(  7160) },
        { -INT32_C(   722406866), -INT32_C(    28085749),  INT32_C(   576403878),  INT32_C(     4168216) } },
      { { -INT16_C( 17115),  INT16_C( 17486),  INT16_C( 11419), -INT16_C( 13798),  INT16_C( 13661), -INT16_C( 31879),  INT16_C( 21799),  INT16_C( 29803) },
        { -INT16_C( 19432),  INT16_C( 21003),  INT16_C( 21554), -INT16_C( 25866), -INT16_C( 26194),  INT16_C( 22115),  INT16_C( 23651), -INT16_C( 30351) },
        {  INT32_C(   699837138),  INT32_C(   603024194), -INT32_C(  1062840319), -INT32_C(   388982704) } },
      { { -INT16_C( 16359), -INT16_C( 19251), -INT16_C(  5908),  INT16_C( 18814), -INT16_C(  2019),  INT16_C( 17612),  INT16_C( 14157),  INT16_C( 26040) },
        { -INT16_C( 15380),  INT16_C(  7864), -INT16_C( 20968), -INT16_C( 14664),  INT16_C(  6983), -INT16_C( 21732), -INT16_C( 29065), -INT16_C( 28620) },
        {  INT32_C(   100211556), -INT32_C(   152009552), -INT32_C(   396842661), -INT32_C(  1156738005) } },
      { {  INT16_C(   334),  INT16_C( 14916), -INT16_C( 15383),  INT16_C(  1667),  INT16_C( 20411),  INT16_C(  2122),  INT16_C(   903),  INT16_C( 29549) },
        {  INT16_C(  9670), -INT16_C(  8559),  INT16_C( 18899),  INT16_C(  7076), -INT16_C( 16028), -INT16_C(  9018), -INT16_C(  1457), -INT16_C( 25236) },
        { -INT32_C(   124436264), -INT32_C(   278927625), -INT32_C(   346283704), -INT32_C(   747014235) } },
      { { -INT16_C( 19973), -INT16_C(  6697),  INT16_C( 23156),  INT16_C( 12267),  INT16_C( 13993),  INT16_C( 12343), -INT16_C( 23495), -INT16_C(    93) },
        {  INT16_C( 13514), -INT16_C( 25122), -INT16_C( 32131), -INT16_C(  7496),  INT16_C( 32323), -INT16_C( 27970),  INT16_C( 10872),  INT16_C( 29743) },
        { -INT32_C(   101673088), -INT32_C(   835978868),  INT32_C(   107062029), -INT32_C(   258203739) } },
      { {  INT16_C(  1755),  INT16_C( 20313),  INT16_C( 17504),  INT16_C(  2686), -INT16_C( 19078), -INT16_C( 19654), -INT16_C(  8614),  INT16_C(  9395) },
        { -INT16_C( 28398), -INT16_C( 28479),  INT16_C( 31251),  INT16_C( 22386),  INT16_C( 12536),  INT16_C( 29161),  INT16_C(  6490),  INT16_C( 14053) },
        { -INT32_C(   628332417),  INT32_C(   607146300), -INT32_C(   812292102),  INT32_C(    76123075) } },
      { {  INT16_C( 15903), -INT16_C( 32635),  INT16_C(  1154), -INT16_C(   630), -INT16_C( 15175),  INT16_C(  5040),  INT16_C( 25506), -INT16_C( 19145) },
        { -INT16_C(  1548),  INT16_C(  2117), -INT16_C( 18573),  INT16_C( 27487),  INT16_C( 18663),  INT16_C( 16860), -INT16_C( 16031), -INT16_C( 32393) },
        { -INT32_C(    93706139), -INT32_C(    38750052), -INT32_C(   198236625),  INT32_C(   211277299) } },
      { { -INT16_C(   513), -INT16_C( 32255), -INT16_C( 29951), -INT16_C( 17793),  INT16_C( 12111), -INT16_C(  3378),  INT16_C(  1427), -INT16_C( 30809) },
        { -INT16_C(  4866),  INT16_C( 29071), -INT16_C(  4445), -INT16_C( 29987), -INT16_C( 18121), -INT16_C( 26421),  INT16_C( 17275),  INT16_C( 31257) },
        { -INT32_C(   935188847),  INT32_C(   666690886), -INT32_C(   130213293), -INT32_C(   938345488) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_i32x4_dot_i16x8(a, b);
      simde_test_wasm_i32x4_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      simde_v128_t
        a = simde_test_wasm_i16x8_random(),
        b = simde_test_wasm_i16x8_random(),
        r;

      r = simde_wasm_i32x4_dot_i16x8(a, b);

      simde_test_wasm_i16x8_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_i16x8_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_i32x4_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i32x4_dot_i16x8)
SIMDE_TEST_FUNC_LIST_END

#include "test-simd128-footer.h"
