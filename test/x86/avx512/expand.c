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
 *   2021      Evan Nemerson <evan@nemerson.com>
 */

#define SIMDE_TEST_X86_AVX512_INSN expand

#include <test/x86/avx512/test-avx512.h>
#include <simde/x86/avx512/set.h>
#include <simde/x86/avx512/expand.h>

static int
test_simde_mm256_mask_expand_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t src[8];
    const simde__mmask8 k;
    const int32_t a[8];
    const int32_t r[8];
  } test_vec[] = {
    { { -INT32_C(  1807377691), -INT32_C(  1704232880), -INT32_C(  1778826755), -INT32_C(    21052482),  INT32_C(   806970891),  INT32_C(   545047790),  INT32_C(   398939030), -INT32_C(  1548893250) },
      UINT8_C( 93),
      {  INT32_C(  1806579955), -INT32_C(   462927709),  INT32_C(    94567746),  INT32_C(   571515067),  INT32_C(  2098217401),  INT32_C(   269693117), -INT32_C(  1160827913), -INT32_C(   887655720) },
      {  INT32_C(  1806579955), -INT32_C(  1704232880), -INT32_C(   462927709),  INT32_C(    94567746),  INT32_C(   571515067),  INT32_C(   545047790),  INT32_C(  2098217401), -INT32_C(  1548893250) } },
    { {  INT32_C(  1295500714),  INT32_C(  1345429262),  INT32_C(  1482019997),  INT32_C(   779773556),  INT32_C(  1688963751), -INT32_C(  1317748806), -INT32_C(  1033157654),  INT32_C(  1619952566) },
      UINT8_C( 72),
      {  INT32_C(  1683402437), -INT32_C(  1291737377),  INT32_C(  1646811900),  INT32_C(  1594447572), -INT32_C(  1072075519),  INT32_C(   631950305), -INT32_C(  1176801994), -INT32_C(  1073595397) },
      {  INT32_C(  1295500714),  INT32_C(  1345429262),  INT32_C(  1482019997),  INT32_C(  1683402437),  INT32_C(  1688963751), -INT32_C(  1317748806), -INT32_C(  1291737377),  INT32_C(  1619952566) } },
    { { -INT32_C(   920364823), -INT32_C(    75749633),  INT32_C(  1415423104), -INT32_C(    55351558), -INT32_C(  1262694957), -INT32_C(   824612968), -INT32_C(   813124396), -INT32_C(   644904208) },
      UINT8_C(226),
      { -INT32_C(   639524173), -INT32_C(  1017521121), -INT32_C(  1614893511),  INT32_C(   779270753), -INT32_C(   574216330), -INT32_C(  1246653184), -INT32_C(  1482325987), -INT32_C(  1014399473) },
      { -INT32_C(   920364823), -INT32_C(   639524173),  INT32_C(  1415423104), -INT32_C(    55351558), -INT32_C(  1262694957), -INT32_C(  1017521121), -INT32_C(  1614893511),  INT32_C(   779270753) } },
    { {  INT32_C(  1083992865), -INT32_C(  2130446777),  INT32_C(    86032804), -INT32_C(   231435397), -INT32_C(  1160774982), -INT32_C(  1401978481),  INT32_C(   290657281), -INT32_C(  1261118061) },
      UINT8_C( 72),
      {  INT32_C(  1720710256), -INT32_C(  1190522633), -INT32_C(  1003220943),  INT32_C(  1048454724),  INT32_C(  2010003702), -INT32_C(  1132954968), -INT32_C(  1420850738), -INT32_C(   822934691) },
      {  INT32_C(  1083992865), -INT32_C(  2130446777),  INT32_C(    86032804),  INT32_C(  1720710256), -INT32_C(  1160774982), -INT32_C(  1401978481), -INT32_C(  1190522633), -INT32_C(  1261118061) } },
    { { -INT32_C(   281771273), -INT32_C(   995606637), -INT32_C(  1819747249), -INT32_C(   103741949), -INT32_C(   428826818), -INT32_C(   391911398), -INT32_C(   812387726), -INT32_C(   308443402) },
      UINT8_C(  8),
      {  INT32_C(   295427282),  INT32_C(  1633705860), -INT32_C(   312151065),  INT32_C(  1680629188), -INT32_C(  1250028851), -INT32_C(  1473812811),  INT32_C(  2141124601),  INT32_C(  1720159124) },
      { -INT32_C(   281771273), -INT32_C(   995606637), -INT32_C(  1819747249),  INT32_C(   295427282), -INT32_C(   428826818), -INT32_C(   391911398), -INT32_C(   812387726), -INT32_C(   308443402) } },
    { { -INT32_C(   327736472),  INT32_C(  1783486338), -INT32_C(  1890078262), -INT32_C(   604798194),  INT32_C(  1267822998), -INT32_C(   789333801),  INT32_C(  1146065327), -INT32_C(  2052401635) },
      UINT8_C(249),
      { -INT32_C(   109285086),  INT32_C(  1891952319), -INT32_C(  1048620227), -INT32_C(  1219012026), -INT32_C(  1534156053),  INT32_C(   659775126), -INT32_C(  2092656723),  INT32_C(  1685965122) },
      { -INT32_C(   109285086),  INT32_C(  1783486338), -INT32_C(  1890078262),  INT32_C(  1891952319), -INT32_C(  1048620227), -INT32_C(  1219012026), -INT32_C(  1534156053),  INT32_C(   659775126) } },
    { { -INT32_C(    94504645),  INT32_C(   476717535), -INT32_C(  1159861900),  INT32_C(   795948100),  INT32_C(  1842610135),  INT32_C(   177481565),  INT32_C(     9361854), -INT32_C(   580645982) },
      UINT8_C(  4),
      { -INT32_C(   471607358),  INT32_C(   727252802),  INT32_C(   292491997), -INT32_C(  2081906812), -INT32_C(  1713285774), -INT32_C(  1017582614), -INT32_C(  2073732999),  INT32_C(  2139636669) },
      { -INT32_C(    94504645),  INT32_C(   476717535), -INT32_C(   471607358),  INT32_C(   795948100),  INT32_C(  1842610135),  INT32_C(   177481565),  INT32_C(     9361854), -INT32_C(   580645982) } },
    { {  INT32_C(  1549953818),  INT32_C(  1216920171),  INT32_C(  1364850637),  INT32_C(   164905622), -INT32_C(  2120043113),  INT32_C(   440728225),  INT32_C(   278899283),  INT32_C(   126822381) },
      UINT8_C(147),
      { -INT32_C(  1392614159), -INT32_C(   478591252), -INT32_C(   512046433),  INT32_C(  1417249694),  INT32_C(   552991269), -INT32_C(   378335425), -INT32_C(   690584658),  INT32_C(    57269522) },
      { -INT32_C(  1392614159), -INT32_C(   478591252),  INT32_C(  1364850637),  INT32_C(   164905622), -INT32_C(   512046433),  INT32_C(   440728225),  INT32_C(   278899283),  INT32_C(  1417249694) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i src = simde_x_mm256_loadu_epi32(test_vec[i].src);
    simde__mmask8 k = test_vec[i].k;
    simde__m256i a = simde_x_mm256_loadu_epi32(test_vec[i].a);
    simde__m256i r = simde_mm256_mask_expand_epi32(src, k, a);
    simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256i src = simde_test_x86_random_i32x8();
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256i a = simde_test_x86_random_i32x8();
    simde__m256i r = simde_mm256_mask_expand_epi32(src, k, a);

    simde_test_x86_write_i32x8(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_maskz_expand_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const int32_t a[8];
    const int32_t r[8];
  } test_vec[] = {
    { UINT8_C(166),
      {  INT32_C(   153778204), -INT32_C(   592711181),  INT32_C(   298932777),  INT32_C(   778264931), -INT32_C(   278534587),  INT32_C(  2090262096), -INT32_C(   140643639),  INT32_C(   949866012) },
      {  INT32_C(           0),  INT32_C(   153778204), -INT32_C(   592711181),  INT32_C(           0),  INT32_C(           0),  INT32_C(   298932777),  INT32_C(           0),  INT32_C(   778264931) } },
    { UINT8_C( 70),
      { -INT32_C(  1187429945),  INT32_C(  1205999085),  INT32_C(  1219228646),  INT32_C(  1015929174),  INT32_C(   495746367),  INT32_C(    98961427),  INT32_C(  1948442277),  INT32_C(  1136286331) },
      {  INT32_C(           0), -INT32_C(  1187429945),  INT32_C(  1205999085),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(  1219228646),  INT32_C(           0) } },
    { UINT8_C(156),
      {  INT32_C(   160038132), -INT32_C(   772747042),  INT32_C(  1428633723),  INT32_C(  1117021381), -INT32_C(   111758864),  INT32_C(  1973312407), -INT32_C(   655289731), -INT32_C(  1049348915) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(   160038132), -INT32_C(   772747042),  INT32_C(  1428633723),  INT32_C(           0),  INT32_C(           0),  INT32_C(  1117021381) } },
    { UINT8_C( 48),
      { -INT32_C(   854668547), -INT32_C(   230039622),  INT32_C(  1790483974), -INT32_C(   480511438), -INT32_C(  1401269168),  INT32_C(    86634738),  INT32_C(   366084577),  INT32_C(  1917162357) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(   854668547), -INT32_C(   230039622),  INT32_C(           0),  INT32_C(           0) } },
    { UINT8_C( 93),
      {  INT32_C(   840450131),  INT32_C(   657984137), -INT32_C(  1118198846),  INT32_C(  1376599294), -INT32_C(  1505445450), -INT32_C(   460895773), -INT32_C(  1369793509),  INT32_C(   873254113) },
      {  INT32_C(   840450131),  INT32_C(           0),  INT32_C(   657984137), -INT32_C(  1118198846),  INT32_C(  1376599294),  INT32_C(           0), -INT32_C(  1505445450),  INT32_C(           0) } },
    { UINT8_C( 12),
      {  INT32_C(   781542948),  INT32_C(  1123138719),  INT32_C(  1363193365),  INT32_C(  1963496123),  INT32_C(   542682838), -INT32_C(   767869898),  INT32_C(  1672800918),  INT32_C(   443541750) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(   781542948),  INT32_C(  1123138719),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { UINT8_C( 79),
      { -INT32_C(  1041348603), -INT32_C(   405327815),  INT32_C(    44247152), -INT32_C(   539486160), -INT32_C(  1407846288),  INT32_C(   507766580), -INT32_C(  2079021413),  INT32_C(   450047509) },
      { -INT32_C(  1041348603), -INT32_C(   405327815),  INT32_C(    44247152), -INT32_C(   539486160),  INT32_C(           0),  INT32_C(           0), -INT32_C(  1407846288),  INT32_C(           0) } },
    { UINT8_C(118),
      { -INT32_C(   240067391), -INT32_C(   614361165),  INT32_C(  1376543546),  INT32_C(   885189435), -INT32_C(   412586240),  INT32_C(  1485014706), -INT32_C(   932378726), -INT32_C(  1690400550) },
      {  INT32_C(           0), -INT32_C(   240067391), -INT32_C(   614361165),  INT32_C(           0),  INT32_C(  1376543546),  INT32_C(   885189435), -INT32_C(   412586240),  INT32_C(           0) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__mmask8 k = test_vec[i].k;
    simde__m256i a = simde_x_mm256_loadu_epi32(test_vec[i].a);
    simde__m256i r = simde_mm256_maskz_expand_epi32(k, a);
    simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256i a = simde_test_x86_random_i32x8();
    simde__m256i r = simde_mm256_maskz_expand_epi32(k, a);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_expand_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_maskz_expand_epi32)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/avx512/test-avx512-footer.h>
