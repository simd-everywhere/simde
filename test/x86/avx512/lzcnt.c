/* SPDX-License-Identifier: MIT
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
 *
 * Copyright:
 *   2020      Evan Nemerson <evan@nemerson.com>
 */

#define SIMDE_TEST_X86_AVX512_INSN lzcnt

#include <test/x86/avx512/test-avx512.h>
#include <simde/x86/avx512/lzcnt.h>

static int
test_simde_mm_lzcnt_epi32(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi32(           INT32_MAX,            INT32_MIN,          ~INT32_C(0), INT32_C(          0)),
      simde_mm_set_epi32(INT32_C(          1), INT32_C(          0), INT32_C(          0), INT32_C(         32)) },
    { simde_mm_set_epi32(INT32_C(        179), INT32_C(     -17551), INT32_C(   -2202065), INT32_C(    -743837)),
      simde_mm_set_epi32(INT32_C(         24), INT32_C(          0), INT32_C(          0), INT32_C(          0)) },
    { simde_mm_set_epi32(INT32_C(      -2559), INT32_C(  388806146), INT32_C(    1927808), INT32_C(       -112)),
      simde_mm_set_epi32(INT32_C(          0), INT32_C(          3), INT32_C(         11), INT32_C(          0)) },
    { simde_mm_set_epi32(INT32_C(         22), INT32_C(    -189678), INT32_C(        252), INT32_C(      27703)),
      simde_mm_set_epi32(INT32_C(         27), INT32_C(          0), INT32_C(         24), INT32_C(         17)) },
    { simde_mm_set_epi32(INT32_C(   -9106380), INT32_C(    8952567), INT32_C(         -4), INT32_C(     685169)),
      simde_mm_set_epi32(INT32_C(          0), INT32_C(          8), INT32_C(          0), INT32_C(         12)) },
    { simde_mm_set_epi32(INT32_C(     267298), INT32_C(      -3422), INT32_C(          4), INT32_C(      31229)),
      simde_mm_set_epi32(INT32_C(         13), INT32_C(          0), INT32_C(         29), INT32_C(         17)) },
    { simde_mm_set_epi32(INT32_C(     167383), INT32_C(        214), INT32_C(          0), INT32_C(     -20257)),
      simde_mm_set_epi32(INT32_C(         14), INT32_C(         24), INT32_C(         32), INT32_C(          0)) },
    { simde_mm_set_epi32(INT32_C(       -147), INT32_C(   -1774263), INT32_C(     143922), INT32_C(    -914728)),
      simde_mm_set_epi32(INT32_C(          0), INT32_C(          0), INT32_C(         14), INT32_C(          0)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_lzcnt_epi32(test_vec[i].a);
    simde_assert_m128i_i32(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_mask_lzcnt_epi32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const int32_t src[4];
    const simde__mmask8 k;
    const int32_t a[4];
    const int32_t r[4];
  } test_vec[] = {
    { { -INT32_C(  1967906480),  INT32_C(   444241631),  INT32_C(  1751328815),  INT32_C(  1797987849) },
      UINT8_C( 10),
      {  INT32_C(     5428843),  INT32_C(   517032875),  INT32_C(   698580121),  INT32_C(   725459874) },
      { -INT32_C(  1967906480),  INT32_C(           3),  INT32_C(  1751328815),  INT32_C(           2) } },
    { { -INT32_C(    69694592),  INT32_C(   153290917), -INT32_C(  1675154320), -INT32_C(   246713960) },
      UINT8_C( 13),
      {  INT32_C(       18677),  INT32_C(       21570),  INT32_C(       30363),  INT32_C(        9014) },
      {  INT32_C(          17),  INT32_C(   153290917),  INT32_C(          17),  INT32_C(          18) } },
    { { -INT32_C(  1957041304),  INT32_C(   481872372), -INT32_C(  1332916123), -INT32_C(   503559615) },
      UINT8_C(  6),
      {  INT32_C(           0),  INT32_C(           6),  INT32_C(           6),  INT32_C(           0) },
      { -INT32_C(  1957041304),  INT32_C(          29),  INT32_C(          29), -INT32_C(   503559615) } },
    { { -INT32_C(  2084109621), -INT32_C(  1412223970), -INT32_C(   638184227), -INT32_C(   244896523) },
      UINT8_C(  2),
      {  INT32_C(      315764),  INT32_C(      402356),  INT32_C(      357196),  INT32_C(      345035) },
      { -INT32_C(  2084109621),  INT32_C(          13), -INT32_C(   638184227), -INT32_C(   244896523) } },
    { { -INT32_C(   816134404),  INT32_C(  1743009649),  INT32_C(  2022955280),  INT32_C(  1643201995) },
      UINT8_C(  4),
      {  INT32_C(        4198),  INT32_C(      523483),  INT32_C(      334642),  INT32_C(      359676) },
      { -INT32_C(   816134404),  INT32_C(  1743009649),  INT32_C(          13),  INT32_C(  1643201995) } },
    { {  INT32_C(  1394876527),  INT32_C(   455882120), -INT32_C(  1637746771),  INT32_C(   707450200) },
      UINT8_C(  1),
      {  INT32_C(      820684),  INT32_C(      155800),  INT32_C(      822191),  INT32_C(      791418) },
      {  INT32_C(          12),  INT32_C(   455882120), -INT32_C(  1637746771),  INT32_C(   707450200) } },
    { { -INT32_C(  1241429622), -INT32_C(   961630619),  INT32_C(  2006648396), -INT32_C(   224101327) },
      UINT8_C(  8),
      {  INT32_C(    15383396),  INT32_C(    19320589),  INT32_C(    17462288),  INT32_C(     2498061) },
      { -INT32_C(  1241429622), -INT32_C(   961630619),  INT32_C(  2006648396),  INT32_C(          10) } },
    { {  INT32_C(  1941272773), -INT32_C(   646315458),  INT32_C(   492153721),  INT32_C(  1334390173) },
      UINT8_C( 10),
      {  INT32_C(          50),  INT32_C(         123),  INT32_C(         121),  INT32_C(          96) },
      {  INT32_C(  1941272773),  INT32_C(          25),  INT32_C(   492153721),  INT32_C(          25) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i src = simde_x_mm_loadu_epi32(test_vec[i].src);
    simde__m128i a = simde_x_mm_loadu_epi32(test_vec[i].a);
    simde__m128i r = simde_mm_mask_lzcnt_epi32(src, test_vec[i].k, a);
    simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_mm_maskz_lzcnt_epi32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const simde__mmask8 k;
    const int32_t a[16];
    const int32_t r[16];
  } test_vec[] = {
    { UINT8_C( 11),
      {  INT32_C(           6),  INT32_C(           2),  INT32_C(           1),  INT32_C(           7) },
      {  INT32_C(          29),  INT32_C(          30),  INT32_C(           0),  INT32_C(          29) } },
    { UINT8_C(  1),
      {  INT32_C(    57768613),  INT32_C(    44212542),  INT32_C(   220122657),  INT32_C(   188272304) },
      {  INT32_C(           6),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { UINT8_C(  1),
      {  INT32_C(       15428),  INT32_C(        3147),  INT32_C(         201),  INT32_C(       13035) },
      {  INT32_C(          18),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { UINT8_C( 14),
      {  INT32_C(        7895),  INT32_C(        6520),  INT32_C(        2703),  INT32_C(        1256) },
      {  INT32_C(           0),  INT32_C(          19),  INT32_C(          20),  INT32_C(          21) } },
    { UINT8_C( 18),
      {  INT32_C(     3584232),  INT32_C(     3831674),  INT32_C(      372002),  INT32_C(     3456164) },
      {  INT32_C(           0),  INT32_C(          10),  INT32_C(           0),  INT32_C(           0) } },
    { UINT8_C( 16),
      {  INT32_C(        1915),  INT32_C(       47708),  INT32_C(       61410),  INT32_C(       63376) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { UINT8_C(  4),
      {  INT32_C(   576116464),  INT32_C(   682438940),  INT32_C(  1066509946),  INT32_C(  1013501310) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           2),  INT32_C(           0) } },
    { UINT8_C( 22),
      {  INT32_C(      121955),  INT32_C(      108474),  INT32_C(      112020),  INT32_C(      114447) },
      {  INT32_C(           0),  INT32_C(          15),  INT32_C(          15),  INT32_C(           0) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_x_mm_loadu_epi32(test_vec[i].a);
    simde__m128i r = simde_mm_maskz_lzcnt_epi32(test_vec[i].k, a);
    simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[i].r));
  }

  return 0;
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_lzcnt_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_lzcnt_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_maskz_lzcnt_epi32)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/avx512/test-avx512-footer.h>
