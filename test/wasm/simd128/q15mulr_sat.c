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

#define SIMDE_TEST_WASM_SIMD128_INSN q15mulr_sat
#include "../../../simde/wasm/simd128.h"
#include "test-simd128.h"

static int
test_simde_wasm_i16x8_q15mulr_sat(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int16_t a[sizeof(simde_v128_t) / sizeof(int16_t)];
      int16_t b[sizeof(simde_v128_t) / sizeof(int16_t)];
      int16_t r[sizeof(simde_v128_t) / sizeof(int16_t)];
    } test_vec[] = {
      { {  INT16_C(   244),  INT16_C(  1170),  INT16_C( 13207),  INT16_C( 27867),  INT16_C( 15134),  INT16_C( 29681), -INT16_C(  2722), -INT16_C( 17090) },
        {  INT16_C( 26495), -INT16_C(  8524),  INT16_C( 22517),  INT16_C( 15291),  INT16_C(  2756), -INT16_C( 21989),  INT16_C( 20646),  INT16_C( 16883) },
        {  INT16_C(   197), -INT16_C(   304),  INT16_C(  9075),  INT16_C( 13004),  INT16_C(  1273), -INT16_C( 19917), -INT16_C(  1715), -INT16_C(  8805) } },
      { {  INT16_C( 29806),  INT16_C( 19127), -INT16_C( 26275),  INT16_C( 31142),  INT16_C(  3901),  INT16_C(  1689), -INT16_C( 29234),  INT16_C( 16801) },
        {  INT16_C( 17240),  INT16_C( 13635),  INT16_C(  5243),  INT16_C(   869), -INT16_C( 12185), -INT16_C( 16947), -INT16_C(  1005),  INT16_C( 19329) },
        {  INT16_C( 15682),  INT16_C(  7959), -INT16_C(  4204),  INT16_C(   826), -INT16_C(  1451), -INT16_C(   874),  INT16_C(   897),  INT16_C(  9910) } },
      { { -INT16_C( 32465),  INT16_C( 29941), -INT16_C(   550),  INT16_C( 12859), -INT16_C(  4953),  INT16_C(  1370), -INT16_C( 22705), -INT16_C( 22445) },
        { -INT16_C( 13100), -INT16_C( 15770),  INT16_C(  9856), -INT16_C(  4588), -INT16_C( 31449), -INT16_C( 20533), -INT16_C( 11267), -INT16_C( 29850) },
        {  INT16_C( 12979), -INT16_C( 14409), -INT16_C(   165), -INT16_C(  1800),  INT16_C(  4754), -INT16_C(   858),  INT16_C(  7807),  INT16_C( 20446) } },
      { {  INT16_C(  1634), -INT16_C(  2841),  INT16_C( 24487), -INT16_C( 11073),  INT16_C( 26249), -INT16_C( 13901),  INT16_C(  8959),  INT16_C(  2917) },
        {  INT16_C( 11687), -INT16_C( 12462),  INT16_C( 15869), -INT16_C(  4434),  INT16_C( 26517), -INT16_C( 26463), -INT16_C( 11578),  INT16_C( 30307) },
        {  INT16_C(   583),  INT16_C(  1080),  INT16_C( 11859),  INT16_C(  1498),  INT16_C( 21242),  INT16_C( 11226), -INT16_C(  3166),  INT16_C(  2698) } },
      { {  INT16_C( 12388),  INT16_C(  6289), -INT16_C( 19442),  INT16_C( 28857), -INT16_C( 28075), -INT16_C( 29304), -INT16_C( 24758),  INT16_C( 24507) },
        {  INT16_C( 15536),  INT16_C( 18237),  INT16_C(  5934),  INT16_C(  3178), -INT16_C( 32464), -INT16_C( 23033), -INT16_C( 17059),  INT16_C(  3365) },
        {  INT16_C(  5873),  INT16_C(  3500), -INT16_C(  3521),  INT16_C(  2799),  INT16_C( 27815),  INT16_C( 20598),  INT16_C( 12889),  INT16_C(  2517) } },
      { {  INT16_C(  4380),  INT16_C( 30188), -INT16_C(  3187),  INT16_C( 20048),  INT16_C( 32627), -INT16_C( 17902),  INT16_C( 28876), -INT16_C( 20574) },
        { -INT16_C( 13044), -INT16_C(  6237),  INT16_C( 18131), -INT16_C( 30512), -INT16_C(  7979),  INT16_C( 13197), -INT16_C( 14110), -INT16_C(  9567) },
        { -INT16_C(  1744), -INT16_C(  5746), -INT16_C(  1763), -INT16_C( 18668), -INT16_C(  7945), -INT16_C(  7210), -INT16_C( 12434),  INT16_C(  6007) } },
      { { -INT16_C( 18236), -INT16_C(  9747), -INT16_C( 26408), -INT16_C( 13561),  INT16_C(  9585), -INT16_C( 17596), -INT16_C(  2125), -INT16_C(  7697) },
        { -INT16_C( 28757), -INT16_C(  5865),  INT16_C( 29426),  INT16_C( 29228),  INT16_C( 19380),  INT16_C( 20169), -INT16_C( 15927),  INT16_C( 28400) },
        {  INT16_C( 16004),  INT16_C(  1745), -INT16_C( 23715), -INT16_C( 12096),  INT16_C(  5669), -INT16_C( 10830),  INT16_C(  1033), -INT16_C(  6671) } },
      { { -INT16_C( 14011), -INT16_C( 18667), -INT16_C( 21159), -INT16_C( 18954), -INT16_C(  6465),  INT16_C( 18108), -INT16_C( 27487), -INT16_C(  3690) },
        {  INT16_C( 24419),  INT16_C( 13705),  INT16_C( 10014), -INT16_C( 12144),  INT16_C( 30660), -INT16_C( 13574), -INT16_C( 19585),  INT16_C( 24488) },
        { -INT16_C( 10441), -INT16_C(  7807), -INT16_C(  6466),  INT16_C(  7024), -INT16_C(  6049), -INT16_C(  7501),  INT16_C( 16429), -INT16_C(  2758) } },
      { {  INT16_C(-32768),  INT16_C(-32768),  INT16_C(-32768),  INT16_C(-32768),  INT16_C(-32768),  INT16_C(-32768),  INT16_C(-32768),  INT16_C(-32768) },
        {  INT16_C(-32768),  INT16_C(-32768),  INT16_C(-32768),  INT16_C(-32768),  INT16_C(-32768),  INT16_C(-32768),  INT16_C(-32768),  INT16_C(-32768) },
        {  INT16_C( 32767),  INT16_C( 32767),  INT16_C( 32767),  INT16_C( 32767),  INT16_C( 32767),  INT16_C( 32767),  INT16_C( 32767),  INT16_C( 32767) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_i16x8_q15mulr_sat(a, b);
      simde_test_wasm_i16x8_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      simde_v128_t
        a = simde_test_wasm_i16x8_random(),
        b = simde_test_wasm_i16x8_random(),
        r;

      r = simde_wasm_i16x8_q15mulr_sat(a, b);

      simde_test_wasm_i16x8_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_i16x8_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_i16x8_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i16x8_q15mulr_sat)
SIMDE_TEST_FUNC_LIST_END

#include "test-simd128-footer.h"
