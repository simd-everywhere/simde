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
 *   2025      Michael R. Crusoe <crusoe@debian.org>
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

static int
test_simde_mm256_lzcnt_epi32(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  const struct {
    const int32_t a[8];
    const int32_t r[8];
  } test_vec[] = {
    { { -INT32_C(  1470193164), -INT32_C(  1522785582),  INT32_C(  1783650673), -INT32_C(  1717921740), -INT32_C(   164695212),  INT32_C(  1974442982),  INT32_C(   947532375),  INT32_C(   319981342) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           1),  INT32_C(           2),  INT32_C(           3) } },
    { { -INT32_C(    71602136),  INT32_C(    77658002), -INT32_C(  2056327088), -INT32_C(   585234295), -INT32_C(   506245893),  INT32_C(  1062699751), -INT32_C(   747122252), -INT32_C(  2115597992) },
      {  INT32_C(           0),  INT32_C(           5),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           2),  INT32_C(           0),  INT32_C(           0) } },
    { { -INT32_C(  1954766343), -INT32_C(   376496999), -INT32_C(  1787888372),  INT32_C(    24284421), -INT32_C(  1042135335),  INT32_C(  2097166792),  INT32_C(  1666217739), -INT32_C(   102484480) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           7),  INT32_C(           0),  INT32_C(           1),  INT32_C(           1),  INT32_C(           0) } },
    { {  INT32_C(  1887723735), -INT32_C(  1990585220),  INT32_C(   387893265),  INT32_C(   790139221), -INT32_C(  1611597097),  INT32_C(  1058861108),  INT32_C(  1738697831),  INT32_C(  2053146530) },
      {  INT32_C(           1),  INT32_C(           0),  INT32_C(           3),  INT32_C(           2),  INT32_C(           0),  INT32_C(           2),  INT32_C(           1),  INT32_C(           1) } },
    { {  INT32_C(  1693115623),  INT32_C(   183321848),  INT32_C(  1646332685),  INT32_C(  1938897308),  INT32_C(  1729331507), -INT32_C(   660197519),  INT32_C(  1044335004), -INT32_C(  1212637232) },
      {  INT32_C(           1),  INT32_C(           4),  INT32_C(           1),  INT32_C(           1),  INT32_C(           1),  INT32_C(           0),  INT32_C(           2),  INT32_C(           0) } },
    { {  INT32_C(  2082186116), -INT32_C(   192542489), -INT32_C(  1336432876),  INT32_C(   337963232), -INT32_C(   612681878),  INT32_C(    45359718),  INT32_C(   994177899),  INT32_C(   401799571) },
      {  INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           3),  INT32_C(           0),  INT32_C(           6),  INT32_C(           2),  INT32_C(           3) } },
    { { -INT32_C(  2070737252),  INT32_C(   712514070), -INT32_C(  1562652735),  INT32_C(   582418360), -INT32_C(  1661128394), -INT32_C(  1096830637),  INT32_C(   955900069),  INT32_C(  1984949465) },
      {  INT32_C(           0),  INT32_C(           2),  INT32_C(           0),  INT32_C(           2),  INT32_C(           0),  INT32_C(           0),  INT32_C(           2),  INT32_C(           1) } },
    { {  INT32_C(   284877562), -INT32_C(  1103400196), -INT32_C(    94366142),  INT32_C(  1260131861), -INT32_C(  1679353529),  INT32_C(  1884915403),  INT32_C(  1084773222),  INT32_C(   968292159) },
      {  INT32_C(           3),  INT32_C(           0),  INT32_C(           0),  INT32_C(           1),  INT32_C(           0),  INT32_C(           1),  INT32_C(           1),  INT32_C(           2) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i a = simde_mm256_loadu_epi32(test_vec[i].a);
    simde__m256i r = simde_mm256_lzcnt_epi32(a);
    simde_test_x86_assert_equal_i32x8(r, simde_mm256_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256i a = simde_test_x86_random_i32x8();
    simde__m256i r = simde_mm256_lzcnt_epi32(a);

    simde_test_x86_write_i32x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_mask_lzcnt_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  const struct {
    const int32_t src[8];
    const simde__mmask8 k;
    const int32_t a[8];
    const int32_t r[8];
  } test_vec[] = {
    { { -INT32_C(   699813671),  INT32_C(  1687454754), -INT32_C(  1352731494),  INT32_C(  1375369738),  INT32_C(  1609360020), -INT32_C(   808499608), -INT32_C(   670074983),  INT32_C(  1192346990) },
      UINT8_C( 16),
      { -INT32_C(  1759683979),  INT32_C(  2046603743), -INT32_C(  1356244315),  INT32_C(  1761682389),  INT32_C(  1858661637), -INT32_C(   868378829),  INT32_C(  2091142158), -INT32_C(  2033994479) },
      { -INT32_C(   699813671),  INT32_C(  1687454754), -INT32_C(  1352731494),  INT32_C(  1375369738),  INT32_C(           1), -INT32_C(   808499608), -INT32_C(   670074983),  INT32_C(  1192346990) } },
    { { -INT32_C(  1829823007),  INT32_C(  1949853721), -INT32_C(  1253447791), -INT32_C(   692407576),  INT32_C(   285812858), -INT32_C(  1323313563),  INT32_C(   818060154),  INT32_C(  1061177438) },
      UINT8_C(169),
      {  INT32_C(  2144481126),  INT32_C(   703793815), -INT32_C(   622969615),  INT32_C(  1756403950),  INT32_C(   645511617),  INT32_C(   181966991), -INT32_C(  1841653197),  INT32_C(  1238465251) },
      {  INT32_C(           1),  INT32_C(  1949853721), -INT32_C(  1253447791),  INT32_C(           1),  INT32_C(   285812858),  INT32_C(           4),  INT32_C(   818060154),  INT32_C(           1) } },
    { { -INT32_C(  1388263261), -INT32_C(   123770436), -INT32_C(   521701049), -INT32_C(   492744919),  INT32_C(  1634912201),  INT32_C(   982875295),  INT32_C(   807217078), -INT32_C(  1663473928) },
      UINT8_C( 51),
      { -INT32_C(   364308178), -INT32_C(   891033469), -INT32_C(  1968518559), -INT32_C(   496153831), -INT32_C(  1304109293),  INT32_C(   300734811), -INT32_C(   129955584), -INT32_C(  1634461073) },
      {  INT32_C(           0),  INT32_C(           0), -INT32_C(   521701049), -INT32_C(   492744919),  INT32_C(           0),  INT32_C(           3),  INT32_C(   807217078), -INT32_C(  1663473928) } },
    { { -INT32_C(   961115938),  INT32_C(   891847019),  INT32_C(  2001711659), -INT32_C(    24497889),  INT32_C(  1314471029),  INT32_C(   843999785), -INT32_C(   979220565), -INT32_C(  1174847269) },
      UINT8_C( 86),
      {  INT32_C(   880848840),  INT32_C(  1550428208),  INT32_C(  2060695642),  INT32_C(  1601723882), -INT32_C(  1028730215), -INT32_C(   386532292),  INT32_C(   531470147), -INT32_C(  1613191465) },
      { -INT32_C(   961115938),  INT32_C(           1),  INT32_C(           1), -INT32_C(    24497889),  INT32_C(           0),  INT32_C(   843999785),  INT32_C(           3), -INT32_C(  1174847269) } },
    { {  INT32_C(     8835928), -INT32_C(   178527683),  INT32_C(   316659125),  INT32_C(   531382093), -INT32_C(   379818259), -INT32_C(    97696669), -INT32_C(  1731113743),  INT32_C(  2112778532) },
      UINT8_C(166),
      { -INT32_C(  2122484668),  INT32_C(   209180759), -INT32_C(    81832275), -INT32_C(  2112173163), -INT32_C(  1653836231), -INT32_C(  1399350854),  INT32_C(   155478501),  INT32_C(   512111322) },
      {  INT32_C(     8835928),  INT32_C(           4),  INT32_C(           0),  INT32_C(   531382093), -INT32_C(   379818259),  INT32_C(           0), -INT32_C(  1731113743),  INT32_C(           3) } },
    { { -INT32_C(   587358204),  INT32_C(  1837763095), -INT32_C(   201095895),  INT32_C(   372082079), -INT32_C(  1966028047), -INT32_C(   881886110), -INT32_C(   224036416),  INT32_C(    60408831) },
      UINT8_C(212),
      {  INT32_C(  2061538915), -INT32_C(   907515232), -INT32_C(  1900155921),  INT32_C(  1654975344),  INT32_C(   401372597), -INT32_C(  1293787919), -INT32_C(   727414827), -INT32_C(  1361560245) },
      { -INT32_C(   587358204),  INT32_C(  1837763095),  INT32_C(           0),  INT32_C(   372082079),  INT32_C(           3), -INT32_C(   881886110),  INT32_C(           0),  INT32_C(           0) } },
    { {  INT32_C(   578038200), -INT32_C(    65978863), -INT32_C(   429088773), -INT32_C(  1180905916),  INT32_C(   397063099),  INT32_C(   502029462),  INT32_C(  1047052289),  INT32_C(  1343362968) },
      UINT8_C(  0),
      {  INT32_C(  1366460224), -INT32_C(  1068661819),  INT32_C(  1739045155),  INT32_C(  1126187912), -INT32_C(  1940206858),  INT32_C(   682247719), -INT32_C(  1620700666),  INT32_C(  1777301801) },
      {  INT32_C(   578038200), -INT32_C(    65978863), -INT32_C(   429088773), -INT32_C(  1180905916),  INT32_C(   397063099),  INT32_C(   502029462),  INT32_C(  1047052289),  INT32_C(  1343362968) } },
    { { -INT32_C(   440026526), -INT32_C(  1056406265),  INT32_C(  1867083564),  INT32_C(  1516670095),  INT32_C(   746713830), -INT32_C(  1355634276), -INT32_C(  1999056625),  INT32_C(   596132545) },
      UINT8_C(  2),
      {  INT32_C(    67653116), -INT32_C(     3862061),  INT32_C(   275713664), -INT32_C(  2140482150),  INT32_C(  1689054151), -INT32_C(  1558978924),  INT32_C(  1898769328),  INT32_C(   714388525) },
      { -INT32_C(   440026526),  INT32_C(           0),  INT32_C(  1867083564),  INT32_C(  1516670095),  INT32_C(   746713830), -INT32_C(  1355634276), -INT32_C(  1999056625),  INT32_C(   596132545) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i src = simde_mm256_loadu_epi32(test_vec[i].src);
    simde__m256i a = simde_mm256_loadu_epi32(test_vec[i].a);
    simde__m256i r = simde_mm256_mask_lzcnt_epi32(src, test_vec[i].k, a);
    simde_test_x86_assert_equal_i32x8(r, simde_mm256_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256i src = simde_test_x86_random_i32x8();
    simde__m256i a = simde_test_x86_random_i32x8();
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256i r = simde_mm256_mask_lzcnt_epi32(src, k, a);

    simde_test_x86_write_i32x8(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_maskz_lzcnt_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  const struct {
    const simde__mmask8 k;
    const int32_t a[8];
    const int32_t r[8];
  } test_vec[] = {
    { UINT8_C(200),
      { -INT32_C(  1378537828),  INT32_C(    19846387),  INT32_C(   412827203), -INT32_C(  1814029400), -INT32_C(  1524153145),  INT32_C(  1112918615), -INT32_C(  1418672394), -INT32_C(   139617702) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { UINT8_C(240),
      {  INT32_C(  1455137922),  INT32_C(   278576338),  INT32_C(  1924706903), -INT32_C(   700888174),  INT32_C(  1026416242), -INT32_C(    97292236),  INT32_C(  2052447968),  INT32_C(   222448779) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           2),  INT32_C(           0),  INT32_C(           1),  INT32_C(           4) } },
    { UINT8_C(150),
      { -INT32_C(  1178376963), -INT32_C(  1341074434), -INT32_C(   683441524), -INT32_C(  1723196997), -INT32_C(  1211267257), -INT32_C(  1718105926),  INT32_C(  1763971357),  INT32_C(  1348022867) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           1) } },
    { UINT8_C(243),
      { -INT32_C(   258733796), -INT32_C(  1686354919), -INT32_C(  1588178041),  INT32_C(   619245469), -INT32_C(  2048942147),  INT32_C(  1201829942), -INT32_C(   828765284), -INT32_C(  2124092828) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           1),  INT32_C(           0),  INT32_C(           0) } },
    { UINT8_C( 50),
      {  INT32_C(  1024225784),  INT32_C(  1086629869), -INT32_C(   320969219), -INT32_C(   324468147),  INT32_C(  1495412449), -INT32_C(   604608048), -INT32_C(   314522621),  INT32_C(   568377641) },
      {  INT32_C(           0),  INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { UINT8_C(222),
      { -INT32_C(  1826660628), -INT32_C(  2003804381),  INT32_C(  1087798589),  INT32_C(  1428275750),  INT32_C(  1311079397),  INT32_C(   894566769),  INT32_C(    39731009),  INT32_C(   204767264) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           1),  INT32_C(           1),  INT32_C(           1),  INT32_C(           0),  INT32_C(           6),  INT32_C(           4) } },
    { UINT8_C(180),
      { -INT32_C(  1308516269), -INT32_C(  1376744912),  INT32_C(   584331360), -INT32_C(   871945903),  INT32_C(  1329419854), -INT32_C(   409963608),  INT32_C(  1359450833),  INT32_C(   422581446) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           2),  INT32_C(           0),  INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           3) } },
    { UINT8_C(252),
      { -INT32_C(  1142633423), -INT32_C(   333737284), -INT32_C(  1891811738), -INT32_C(  1680012731), -INT32_C(  1170002617),  INT32_C(  1351363517),  INT32_C(  1175903538),  INT32_C(  1073360909) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           1),  INT32_C(           1),  INT32_C(           2) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i a = simde_mm256_loadu_epi32(test_vec[i].a);
    simde__m256i r = simde_mm256_maskz_lzcnt_epi32(test_vec[i].k, a);
    simde_test_x86_assert_equal_i32x8(r, simde_mm256_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256i a = simde_test_x86_random_i32x8();
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256i r = simde_mm256_maskz_lzcnt_epi32( k, a);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_lzcnt_epi32(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  const struct {
    const int32_t a[16];
    const int32_t r[16];
  } test_vec[] = {
    { {  INT32_C(  1907948255),  INT32_C(  1423418390), -INT32_C(   342268191),  INT32_C(  1882404163), -INT32_C(  1557205640),  INT32_C(  1473674873), -INT32_C(  1000072044), -INT32_C(   155147497),
        -INT32_C(  1268287330), -INT32_C(    33014244), -INT32_C(   404119132),  INT32_C(  1331174614), -INT32_C(  2081257974), -INT32_C(  1730492412), -INT32_C(    60997659), -INT32_C(  2131616286) },
      {  INT32_C(           1),  INT32_C(           1),  INT32_C(           0),  INT32_C(           1),  INT32_C(           0),  INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
         INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { { -INT32_C(  1305192042),  INT32_C(  1001405591), -INT32_C(  1272800546), -INT32_C(  1073513802),  INT32_C(    71628288), -INT32_C(  1549984066),  INT32_C(  1084226141), -INT32_C(  1379888873),
        -INT32_C(  2124352022),  INT32_C(   263983153),  INT32_C(  1640292266),  INT32_C(  1512163161),  INT32_C(  2086561213), -INT32_C(   517997692),  INT32_C(   220315637),  INT32_C(  1002103376) },
      {  INT32_C(           0),  INT32_C(           2),  INT32_C(           0),  INT32_C(           0),  INT32_C(           5),  INT32_C(           0),  INT32_C(           1),  INT32_C(           0),
         INT32_C(           0),  INT32_C(           4),  INT32_C(           1),  INT32_C(           1),  INT32_C(           1),  INT32_C(           0),  INT32_C(           4),  INT32_C(           2) } },
    { {  INT32_C(   146545367), -INT32_C(   719816405), -INT32_C(  1321804712),  INT32_C(  1628133539),  INT32_C(  1105029821),  INT32_C(  1529085029),  INT32_C(   208159931), -INT32_C(    45669850),
         INT32_C(  1745224509), -INT32_C(   734192004), -INT32_C(  1652132614), -INT32_C(  1979805236),  INT32_C(  1640750075), -INT32_C(  1816334632),  INT32_C(  1503601714), -INT32_C(  2091456954) },
      {  INT32_C(           4),  INT32_C(           0),  INT32_C(           0),  INT32_C(           1),  INT32_C(           1),  INT32_C(           1),  INT32_C(           4),  INT32_C(           0),
         INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           1),  INT32_C(           0),  INT32_C(           1),  INT32_C(           0) } },
    { {  INT32_C(  1726700778),  INT32_C(  1950034298),  INT32_C(  1762836893),  INT32_C(  1324486738), -INT32_C(   995115540), -INT32_C(   564696149), -INT32_C(   717752433), -INT32_C(   950432291),
         INT32_C(  1680753898),  INT32_C(   182020461),  INT32_C(  2087971626), -INT32_C(   406165765), -INT32_C(   810845917),  INT32_C(  1940718564), -INT32_C(   683023110),  INT32_C(  1537188465) },
      {  INT32_C(           1),  INT32_C(           1),  INT32_C(           1),  INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
         INT32_C(           1),  INT32_C(           4),  INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           1),  INT32_C(           0),  INT32_C(           1) } },
    { {  INT32_C(  1421921766),  INT32_C(  1616812342),  INT32_C(  2145178244),  INT32_C(  1533519672),  INT32_C(    86643232),  INT32_C(   259577621),  INT32_C(   770163131),  INT32_C(  1250461283),
        -INT32_C(  1986115501),  INT32_C(  1709833441),  INT32_C(   115721678), -INT32_C(  1922937748),  INT32_C(  1955761246),  INT32_C(   528681572),  INT32_C(   793537228),  INT32_C(  1132058096) },
      {  INT32_C(           1),  INT32_C(           1),  INT32_C(           1),  INT32_C(           1),  INT32_C(           5),  INT32_C(           4),  INT32_C(           2),  INT32_C(           1),
         INT32_C(           0),  INT32_C(           1),  INT32_C(           5),  INT32_C(           0),  INT32_C(           1),  INT32_C(           3),  INT32_C(           2),  INT32_C(           1) } },
    { { -INT32_C(     3401955), -INT32_C(   496716524), -INT32_C(   404141701), -INT32_C(   193705067),  INT32_C(   996673239), -INT32_C(   581178607),  INT32_C(  1175234390), -INT32_C(  1702197636),
        -INT32_C(  1315350883), -INT32_C(  2020279028), -INT32_C(   596738745), -INT32_C(  1613700152), -INT32_C(    86296343),  INT32_C(  2060924452),  INT32_C(  1522590941),  INT32_C(   133450346) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           2),  INT32_C(           0),  INT32_C(           1),  INT32_C(           0),
         INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           1),  INT32_C(           1),  INT32_C(           5) } },
    { { -INT32_C(  1380348511), -INT32_C(   785101430), -INT32_C(  1834048822),  INT32_C(  1865514629), -INT32_C(   613872457),  INT32_C(   542458178), -INT32_C(  1887824603),  INT32_C(    26635872),
        -INT32_C(  2052173829),  INT32_C(  1717035676),  INT32_C(   184026500),  INT32_C(   981019267),  INT32_C(  2031477302),  INT32_C(  1218013731), -INT32_C(   522775680),  INT32_C(  2095148673) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           1),  INT32_C(           0),  INT32_C(           2),  INT32_C(           0),  INT32_C(           7),
         INT32_C(           0),  INT32_C(           1),  INT32_C(           4),  INT32_C(           2),  INT32_C(           1),  INT32_C(           1),  INT32_C(           0),  INT32_C(           1) } },
    { {  INT32_C(  1510051773), -INT32_C(   171943823), -INT32_C(   503334563),  INT32_C(   421230819),  INT32_C(  2123510107),  INT32_C(   466037659), -INT32_C(  1074028994), -INT32_C(   902046708),
        -INT32_C(   601604757), -INT32_C(   204282731), -INT32_C(  2133536355), -INT32_C(  1516572854), -INT32_C(  1138545632), -INT32_C(  1764234664), -INT32_C(  1789471863),  INT32_C(   459248047) },
      {  INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           3),  INT32_C(           1),  INT32_C(           3),  INT32_C(           0),  INT32_C(           0),
         INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           3) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i a = simde_mm512_loadu_epi32(test_vec[i].a);
    simde__m512i r = simde_mm512_lzcnt_epi32(a);
    simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512i a = simde_test_x86_random_i32x16();
    simde__m512i r = simde_mm512_lzcnt_epi32(a);

    simde_test_x86_write_i32x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_mask_lzcnt_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  const struct {
    const int32_t src[16];
    const simde__mmask16 k;
    const int32_t a[16];
    const int32_t r[16];
  } test_vec[] = {
    { {  INT32_C(  1693942734),  INT32_C(    89639272), -INT32_C(   444191845),  INT32_C(   998907930), -INT32_C(  1527272116),  INT32_C(   557567640),  INT32_C(  1370919329), -INT32_C(   244574686),
         INT32_C(    22373273), -INT32_C(   939021267), -INT32_C(   240284201), -INT32_C(   114542675),  INT32_C(  2090738660), -INT32_C(  1818371598), -INT32_C(  1931193238),  INT32_C(    58544234) },
      UINT16_C( 1573),
      { -INT32_C(   519712076),  INT32_C(  1437142142),  INT32_C(  1179080345),  INT32_C(  1899983757), -INT32_C(  1980834409),  INT32_C(   538741686),  INT32_C(  1236074975),  INT32_C(    88943185),
         INT32_C(  2078692093), -INT32_C(   137261218),  INT32_C(  1916606693),  INT32_C(   585399435),  INT32_C(   279695962),  INT32_C(  1026672733),  INT32_C(   445046473),  INT32_C(    86037256) },
      {  INT32_C(           0),  INT32_C(    89639272),  INT32_C(           1),  INT32_C(   998907930), -INT32_C(  1527272116),  INT32_C(           2),  INT32_C(  1370919329), -INT32_C(   244574686),
         INT32_C(    22373273),  INT32_C(           0),  INT32_C(           1), -INT32_C(   114542675),  INT32_C(  2090738660), -INT32_C(  1818371598), -INT32_C(  1931193238),  INT32_C(    58544234) } },
    { {  INT32_C(  1385595777), -INT32_C(  1217758342), -INT32_C(   768281106), -INT32_C(  1012625896), -INT32_C(   812973666), -INT32_C(   978496450), -INT32_C(  1885817233),  INT32_C(  1016446651),
        -INT32_C(  1131533503), -INT32_C(  1787561817),  INT32_C(   107456494), -INT32_C(   725021899),  INT32_C(  1268995340),  INT32_C(   403722665), -INT32_C(  1029199865), -INT32_C(  1459667610) },
      UINT16_C(24334),
      {  INT32_C(   258248040),  INT32_C(  1956960134), -INT32_C(  1267070081),  INT32_C(   596132630),  INT32_C(  1114516632), -INT32_C(  2074444163), -INT32_C(  1924791770), -INT32_C(  1489681089),
         INT32_C(  1505204691), -INT32_C(   271754384),  INT32_C(  2107918183),  INT32_C(   597699722), -INT32_C(   714797480), -INT32_C(  1285963892),  INT32_C(     4235457), -INT32_C(  1196919323) },
      {  INT32_C(  1385595777),  INT32_C(           1),  INT32_C(           0),  INT32_C(           2), -INT32_C(   812973666), -INT32_C(   978496450), -INT32_C(  1885817233),  INT32_C(  1016446651),
         INT32_C(           1),  INT32_C(           0),  INT32_C(           1),  INT32_C(           2),  INT32_C(           0),  INT32_C(   403722665),  INT32_C(           9), -INT32_C(  1459667610) } },
    { { -INT32_C(   558203375),  INT32_C(   304423278),  INT32_C(  1061073055),  INT32_C(   944674771), -INT32_C(   956835220), -INT32_C(   848905843),  INT32_C(  1631734713),  INT32_C(   364924932),
         INT32_C(  1039432655),  INT32_C(   995039644), -INT32_C(  1669624375), -INT32_C(  1848325852),  INT32_C(   827837603),  INT32_C(  1056882053),  INT32_C(   211829000),  INT32_C(  1612865681) },
      UINT16_C(22937),
      {  INT32_C(  2023560923), -INT32_C(   105649105), -INT32_C(  1634390406), -INT32_C(  1691391241), -INT32_C(  1144224202),  INT32_C(  1291438659), -INT32_C(  1655138037), -INT32_C(   704808198),
        -INT32_C(  1068655728),  INT32_C(    28901767),  INT32_C(   664817199), -INT32_C(   289222728), -INT32_C(  1716941226),  INT32_C(  1692771160),  INT32_C(   906051132),  INT32_C(  1225588408) },
      {  INT32_C(           1),  INT32_C(   304423278),  INT32_C(  1061073055),  INT32_C(           0),  INT32_C(           0), -INT32_C(   848905843),  INT32_C(  1631734713),  INT32_C(           0),
         INT32_C(           0),  INT32_C(   995039644), -INT32_C(  1669624375),  INT32_C(           0),  INT32_C(           0),  INT32_C(  1056882053),  INT32_C(           2),  INT32_C(  1612865681) } },
    { { -INT32_C(  1034280695), -INT32_C(  1039103454),  INT32_C(  1938999729),  INT32_C(  1627515063),  INT32_C(  1728338305), -INT32_C(  1096466243), -INT32_C(  2084741769), -INT32_C(  1344514394),
        -INT32_C(  1703856265),  INT32_C(  1918665409),  INT32_C(    48623179),  INT32_C(  1482942166), -INT32_C(    37787841),  INT32_C(   532374696),  INT32_C(  1755478209),  INT32_C(  1175944911) },
      UINT16_C( 9625),
      {  INT32_C(  1994426805),  INT32_C(  1458060555),  INT32_C(    39374123), -INT32_C(   212157261), -INT32_C(   873457373),  INT32_C(  1055566717), -INT32_C(   207188956), -INT32_C(  1069957621),
         INT32_C(  1379342919), -INT32_C(  2102911145), -INT32_C(  1601961747), -INT32_C(   527180100),  INT32_C(  1957397495),  INT32_C(  1404278319),  INT32_C(   759585058),  INT32_C(  1592688407) },
      {  INT32_C(           1), -INT32_C(  1039103454),  INT32_C(  1938999729),  INT32_C(           0),  INT32_C(           0), -INT32_C(  1096466243), -INT32_C(  2084741769),  INT32_C(           0),
         INT32_C(           1),  INT32_C(  1918665409),  INT32_C(           0),  INT32_C(  1482942166), -INT32_C(    37787841),  INT32_C(           1),  INT32_C(  1755478209),  INT32_C(  1175944911) } },
    { {  INT32_C(  1480913072), -INT32_C(   145149581),  INT32_C(  1708529106), -INT32_C(  1578512907), -INT32_C(   180938686), -INT32_C(  1320265365),  INT32_C(  1966106247),  INT32_C(  1973078724),
         INT32_C(   768466618), -INT32_C(   500881904),  INT32_C(   826800956),  INT32_C(   181547208), -INT32_C(  1275131576), -INT32_C(   362525085),  INT32_C(  2019530164),  INT32_C(   435026271) },
      UINT16_C(55943),
      { -INT32_C(   414729257),  INT32_C(   499739873),  INT32_C(   793710951), -INT32_C(  1975901887), -INT32_C(  1908590293),  INT32_C(   997761671), -INT32_C(  1766533321), -INT32_C(  1481662000),
         INT32_C(  1049622108), -INT32_C(   916760478), -INT32_C(  1409701271), -INT32_C(   147508276), -INT32_C(   192581012),  INT32_C(  1261436180), -INT32_C(  1528699948), -INT32_C(   515141243) },
      {  INT32_C(           0),  INT32_C(           3),  INT32_C(           2), -INT32_C(  1578512907), -INT32_C(   180938686), -INT32_C(  1320265365),  INT32_C(  1966106247),  INT32_C(           0),
         INT32_C(   768466618),  INT32_C(           0),  INT32_C(   826800956),  INT32_C(           0),  INT32_C(           0), -INT32_C(   362525085),  INT32_C(           0),  INT32_C(           0) } },
    { {  INT32_C(  2066999839), -INT32_C(  1406821197),  INT32_C(  2095051079),  INT32_C(  1844399336),  INT32_C(  1869218624),  INT32_C(   810761807),  INT32_C(   784455906), -INT32_C(   653768263),
        -INT32_C(   430687437),  INT32_C(   529758680),  INT32_C(  1402761835), -INT32_C(    20870210), -INT32_C(   579982450),  INT32_C(  1276035434),  INT32_C(  1383780249),  INT32_C(  1261142808) },
      UINT16_C(17482),
      { -INT32_C(  1775075394),  INT32_C(  1689699833), -INT32_C(   155758025),  INT32_C(  1811183837),  INT32_C(   239690404), -INT32_C(  1134930141),  INT32_C(  1058002214),  INT32_C(   378157656),
        -INT32_C(  1280459590), -INT32_C(  1189649535), -INT32_C(  1833972043), -INT32_C(   335699129),  INT32_C(   704202246), -INT32_C(   991538275), -INT32_C(  2147224280), -INT32_C(   375943889) },
      {  INT32_C(  2066999839),  INT32_C(           1),  INT32_C(  2095051079),  INT32_C(           1),  INT32_C(  1869218624),  INT32_C(   810761807),  INT32_C(           2), -INT32_C(   653768263),
        -INT32_C(   430687437),  INT32_C(   529758680),  INT32_C(           0), -INT32_C(    20870210), -INT32_C(   579982450),  INT32_C(  1276035434),  INT32_C(           0),  INT32_C(  1261142808) } },
    { { -INT32_C(  1280848996),  INT32_C(   864181380), -INT32_C(   338179602), -INT32_C(  1389175372), -INT32_C(   335491322), -INT32_C(  1763628653),  INT32_C(  1076105641), -INT32_C(  1752928518),
        -INT32_C(  1102435527),  INT32_C(  1978780807),  INT32_C(  1231145109), -INT32_C(  1393126491), -INT32_C(   157747358), -INT32_C(   913540576), -INT32_C(  2062897013),  INT32_C(  1478266398) },
      UINT16_C( 6332),
      {  INT32_C(  1091987386), -INT32_C(   910751949),  INT32_C(  1964120272),  INT32_C(   220268971),  INT32_C(   537115136), -INT32_C(  1075212236),  INT32_C(  1598354240),  INT32_C(  1018651010),
        -INT32_C(    75641400), -INT32_C(  1530645292), -INT32_C(   149235892), -INT32_C(   536527904),  INT32_C(   687868149), -INT32_C(   639047272),  INT32_C(  1597517277),  INT32_C(  1453059982) },
      { -INT32_C(  1280848996),  INT32_C(   864181380),  INT32_C(           1),  INT32_C(           4),  INT32_C(           2),  INT32_C(           0),  INT32_C(  1076105641),  INT32_C(           2),
        -INT32_C(  1102435527),  INT32_C(  1978780807),  INT32_C(  1231145109),  INT32_C(           0),  INT32_C(           2), -INT32_C(   913540576), -INT32_C(  2062897013),  INT32_C(  1478266398) } },
    { {  INT32_C(   374181969),  INT32_C(  1340971317), -INT32_C(  1769288303), -INT32_C(  1382121299), -INT32_C(  1835649111),  INT32_C(  1220506384),  INT32_C(  1832340946), -INT32_C(   192482397),
        -INT32_C(  1207250045), -INT32_C(    49809556),  INT32_C(  1905496772), -INT32_C(  1155649006),  INT32_C(  2035135849), -INT32_C(    71234520), -INT32_C(    60229543),  INT32_C(  1861349099) },
      UINT16_C( 9720),
      {  INT32_C(   774372289), -INT32_C(  1221906701), -INT32_C(   769015872),  INT32_C(  1519273969),  INT32_C(   634641404),  INT32_C(  1092654312),  INT32_C(  2000586892),  INT32_C(   954543991),
         INT32_C(   493227050), -INT32_C(    69889477),  INT32_C(  1120861777),  INT32_C(  1117543493),  INT32_C(   526872375), -INT32_C(  1889433853), -INT32_C(  2046386417), -INT32_C(   121639986) },
      {  INT32_C(   374181969),  INT32_C(  1340971317), -INT32_C(  1769288303),  INT32_C(           1),  INT32_C(           2),  INT32_C(           1),  INT32_C(           1),  INT32_C(           2),
         INT32_C(           3), -INT32_C(    49809556),  INT32_C(           1), -INT32_C(  1155649006),  INT32_C(  2035135849),  INT32_C(           0), -INT32_C(    60229543),  INT32_C(  1861349099) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i src = simde_mm512_loadu_epi32(test_vec[i].src);
    simde__m512i a = simde_mm512_loadu_epi32(test_vec[i].a);
    simde__m512i r = simde_mm512_mask_lzcnt_epi32(src, test_vec[i].k, a);
    simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512i src = simde_test_x86_random_i32x16();
    simde__m512i a = simde_test_x86_random_i32x16();
    simde__mmask16 k = simde_test_x86_random_mmask16();
    simde__m512i r = simde_mm512_mask_lzcnt_epi32(src, k, a);

    simde_test_x86_write_i32x16(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask16(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_maskz_lzcnt_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  const struct {
    const simde__mmask16 k;
    const int32_t a[16];
    const int32_t r[16];
  } test_vec[] = {
    { UINT16_C(32180),
      { -INT32_C(   340315370), -INT32_C(    51836882), -INT32_C(   430428598), -INT32_C(   682258320),  INT32_C(   274618543), -INT32_C(   307269913), -INT32_C(  1277592076), -INT32_C(  1931882122),
         INT32_C(   846696452), -INT32_C(   483434343), -INT32_C(     3504242), -INT32_C(   942268649),  INT32_C(  1607939448), -INT32_C(  1756526685),  INT32_C(  2051745284), -INT32_C(    83483401) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           3),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
         INT32_C(           2),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           1),  INT32_C(           0),  INT32_C(           1),  INT32_C(           0) } },
    { UINT16_C(43471),
      {  INT32_C(  1558007085), -INT32_C(    68916175),  INT32_C(  1092287339), -INT32_C(  1703505214),  INT32_C(  1059133938), -INT32_C(    60480079), -INT32_C(  1507828576), -INT32_C(  2077961129),
         INT32_C(  1407254818), -INT32_C(   665926291), -INT32_C(  2095421248), -INT32_C(   316829445),  INT32_C(  1529626282),  INT32_C(    56070499),  INT32_C(  1152022509),  INT32_C(  1841876555) },
      {  INT32_C(           1),  INT32_C(           0),  INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
         INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           6),  INT32_C(           0),  INT32_C(           1) } },
    { UINT16_C(11618),
      {  INT32_C(   242105792),  INT32_C(   796339989), -INT32_C(   809471310), -INT32_C(  1962055073),  INT32_C(   471625925),  INT32_C(   512952692),  INT32_C(   367844941),  INT32_C(   213891916),
         INT32_C(   236662264),  INT32_C(   238916188),  INT32_C(  1675492612),  INT32_C(   753855079), -INT32_C(   817362341),  INT32_C(  1626200851),  INT32_C(   108386746), -INT32_C(  1928186732) },
      {  INT32_C(           0),  INT32_C(           2),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           3),  INT32_C(           3),  INT32_C(           0),
         INT32_C(           4),  INT32_C(           0),  INT32_C(           1),  INT32_C(           2),  INT32_C(           0),  INT32_C(           1),  INT32_C(           0),  INT32_C(           0) } },
    { UINT16_C(25770),
      { -INT32_C(   658522469), -INT32_C(  1428765747),  INT32_C(   345324838), -INT32_C(  1306595222), -INT32_C(  1399967297),  INT32_C(   126175377),  INT32_C(  1614485838),  INT32_C(  1099865510),
         INT32_C(   689589596),  INT32_C(   936636433), -INT32_C(  1756600275),  INT32_C(   390752856),  INT32_C(   767809692),  INT32_C(  1848920096),  INT32_C(   147746914),  INT32_C(  1766480909) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           5),  INT32_C(           0),  INT32_C(           1),
         INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           1),  INT32_C(           4),  INT32_C(           0) } },
    { UINT16_C(  641),
      {  INT32_C(  1716829074),  INT32_C(  1053721074),  INT32_C(  1672029977),  INT32_C(    37438782), -INT32_C(  1488299150), -INT32_C(  1760056119), -INT32_C(      777035),  INT32_C(   543399566),
         INT32_C(  1267119961),  INT32_C(  1368020280), -INT32_C(  1162595460), -INT32_C(   356716680),  INT32_C(   328271690),  INT32_C(  1756080307),  INT32_C(  1533517773), -INT32_C(  1770272195) },
      {  INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           2),
         INT32_C(           0),  INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { UINT16_C(44892),
      {  INT32_C(  1800911585), -INT32_C(  1063333109),  INT32_C(  1252988557), -INT32_C(  1840121343), -INT32_C(  1204091891), -INT32_C(   732493715), -INT32_C(   559967133),  INT32_C(   216014890),
        -INT32_C(   428394534), -INT32_C(  1733945846),  INT32_C(   769807660),  INT32_C(  1572877135), -INT32_C(  1542063305),  INT32_C(  1719233795),  INT32_C(   742660097),  INT32_C(   322446648) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
         INT32_C(           0),  INT32_C(           0),  INT32_C(           2),  INT32_C(           1),  INT32_C(           0),  INT32_C(           1),  INT32_C(           0),  INT32_C(           3) } },
    { UINT16_C(14925),
      { -INT32_C(  1614452743), -INT32_C(   504040705), -INT32_C(   552319969), -INT32_C(  1227207775),  INT32_C(  1763958256), -INT32_C(  2004802237), -INT32_C(  1985103535), -INT32_C(   986183220),
         INT32_C(  1868889712),  INT32_C(   256924144),  INT32_C(  1055876253), -INT32_C(  1594570320), -INT32_C(   368502617), -INT32_C(  1905096131),  INT32_C(   269950787), -INT32_C(  1714073815) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
         INT32_C(           0),  INT32_C(           4),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { UINT16_C(47998),
      {  INT32_C(  1502821641),  INT32_C(  1019097165),  INT32_C(  1644523118),  INT32_C(   393915406),  INT32_C(   161593239),  INT32_C(  1546249285), -INT32_C(   894676236), -INT32_C(   201000469),
        -INT32_C(  2075224265),  INT32_C(   901778631), -INT32_C(  2003319430),  INT32_C(   161419890),  INT32_C(   252854473),  INT32_C(   426457892),  INT32_C(  2044925837),  INT32_C(  1215162129) },
      {  INT32_C(           0),  INT32_C(           2),  INT32_C(           1),  INT32_C(           3),  INT32_C(           4),  INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
         INT32_C(           0),  INT32_C(           2),  INT32_C(           0),  INT32_C(           4),  INT32_C(           4),  INT32_C(           3),  INT32_C(           0),  INT32_C(           1) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i a = simde_mm512_loadu_epi32(test_vec[i].a);
    simde__m512i r = simde_mm512_maskz_lzcnt_epi32(test_vec[i].k, a);
    simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512i a = simde_test_x86_random_i32x16();
    simde__mmask16 k = simde_test_x86_random_mmask16();
    simde__m512i r = simde_mm512_maskz_lzcnt_epi32( k, a);

    simde_test_x86_write_mmask16(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_lzcnt_epi64(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  const struct {
    const int64_t a[2];
    const int64_t r[2];
  } test_vec[] = {
    { { -INT64_C( 6529594626662716867), -INT64_C( 7658553195463780411) },
      {  INT64_C(                   0),  INT64_C(                   0) } },
    { { -INT64_C( 6291287510471174369),  INT64_C( 6115642105530605060) },
      {  INT64_C(                   0),  INT64_C(                   1) } },
    { {  INT64_C( 6140654314808039498), -INT64_C( 6639968843737323053) },
      {  INT64_C(                   1),  INT64_C(                   0) } },
    { {  INT64_C( 4372390747386240430), -INT64_C( 6258906857456910408) },
      {  INT64_C(                   2),  INT64_C(                   0) } },
    { { -INT64_C( 8204586849977778627),  INT64_C( 5243226368188318620) },
      {  INT64_C(                   0),  INT64_C(                   1) } },
    { {  INT64_C( 9187618973587205387), -INT64_C( 6250027146617649606) },
      {  INT64_C(                   1),  INT64_C(                   0) } },
    { { -INT64_C( 8180617259795382737),  INT64_C(  360695862053980958) },
      {  INT64_C(                   0),  INT64_C(                   5) } },
    { { -INT64_C( 8960534567571599521), -INT64_C( 7753685197679365296) },
      {  INT64_C(                   0),  INT64_C(                   0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i a = simde_mm_loadu_epi64(test_vec[i].a);
    simde__m128i r = simde_mm_lzcnt_epi64(a);
    simde_test_x86_assert_equal_i64x2(r, simde_mm_loadu_epi64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i64x2();
    simde__m128i r = simde_mm_lzcnt_epi64(a);

    simde_test_x86_write_i64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_mask_lzcnt_epi64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  const struct {
    const int64_t src[2];
    const simde__mmask8 k;
    const int64_t a[2];
    const int64_t r[2];
  } test_vec[] = {
    { { -INT64_C( 7611375321455075874), -INT64_C( 2503911790215230399) },
      UINT8_C(160),
      { -INT64_C( 7232097481890659447), -INT64_C( 6789012864800629110) },
      { -INT64_C( 7611375321455075874), -INT64_C( 2503911790215230399) } },
    { {  INT64_C(  236913926646372370),  INT64_C( 5616094032099902719) },
      UINT8_C( 98),
      { -INT64_C( 6786741834874117927),  INT64_C( 1966954297944292006) },
      {  INT64_C(  236913926646372370),  INT64_C(                   3) } },
    { {  INT64_C( 2507684339321558047), -INT64_C( 1776612818432877162) },
      UINT8_C(212),
      { -INT64_C( 5138403773616018077), -INT64_C( 8412065259648718307) },
      {  INT64_C( 2507684339321558047), -INT64_C( 1776612818432877162) } },
    { { -INT64_C(  354573952172355479), -INT64_C( 4234245244209001933) },
      UINT8_C( 29),
      {  INT64_C( 7577540010868198995), -INT64_C( 7075388603263595761) },
      {  INT64_C(                   1), -INT64_C( 4234245244209001933) } },
    { {  INT64_C( 7842024116658589013), -INT64_C( 3851259965128950912) },
      UINT8_C( 97),
      {  INT64_C( 5227634620557743529),  INT64_C( 1182603654571881449) },
      {  INT64_C(                   1), -INT64_C( 3851259965128950912) } },
    { {  INT64_C( 1938200261418945262), -INT64_C( 8313542781032114772) },
      UINT8_C( 49),
      { -INT64_C( 8596677253487720064),  INT64_C( 4300474959128151885) },
      {  INT64_C(                   0), -INT64_C( 8313542781032114772) } },
    { {  INT64_C( 5717095399380554957), -INT64_C( 5236914276983990587) },
      UINT8_C(199),
      { -INT64_C(  412390304468139903), -INT64_C( 4010343642070120912) },
      {  INT64_C(                   0),  INT64_C(                   0) } },
    { { -INT64_C( 1119406901134490753),  INT64_C( 7838759152844707907) },
      UINT8_C( 94),
      { -INT64_C( 5676352288607607516),  INT64_C( 2277183259842888885) },
      { -INT64_C( 1119406901134490753),  INT64_C(                   3) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i src = simde_mm_loadu_epi64(test_vec[i].src);
    simde__m128i a = simde_mm_loadu_epi64(test_vec[i].a);
    simde__m128i r = simde_mm_mask_lzcnt_epi64(src, test_vec[i].k, a);
    simde_test_x86_assert_equal_i64x2(r, simde_mm_loadu_epi64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i src = simde_test_x86_random_i64x2();
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128i a = simde_test_x86_random_i64x2();
    simde__m128i r = simde_mm_mask_lzcnt_epi64(src, k, a);

    simde_test_x86_write_i64x2(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x2(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_maskz_lzcnt_epi64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  const struct {
    const simde__mmask8 k;
    const int64_t a[2];
    const int64_t r[2];
  } test_vec[] = {
    { UINT8_C(240),
      { -INT64_C( 8044479613339862708),  INT64_C( 1815737573963548485) },
      {  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C( 92),
      { -INT64_C( 2577856179583072965), -INT64_C( 1180229571018271048) },
      {  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C(253),
      {  INT64_C( 6198791370832959586), -INT64_C( 7421229783630890348) },
      {  INT64_C(                   1),  INT64_C(                   0) } },
    { UINT8_C(101),
      { -INT64_C(  646623970753114249), -INT64_C( 4391590815891031028) },
      {  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C( 49),
      {  INT64_C( 2561787338069421260),  INT64_C(  759991207804887315) },
      {  INT64_C(                   2),  INT64_C(                   0) } },
    { UINT8_C(  9),
      { -INT64_C( 2323909165237078468), -INT64_C( 7398005792666867077) },
      {  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C(184),
      {  INT64_C( 6924029064265374504),  INT64_C( 1366122430143599148) },
      {  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C( 53),
      { -INT64_C( 5971348836289478856),  INT64_C( 4866251171207908874) },
      {  INT64_C(                   0),  INT64_C(                   0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i a = simde_mm_loadu_epi64(test_vec[i].a);
    simde__m128i r = simde_mm_maskz_lzcnt_epi64(test_vec[i].k, a);
    simde_test_x86_assert_equal_i64x2(r, simde_mm_loadu_epi64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128i a = simde_test_x86_random_i64x2();
    simde__m128i r = simde_mm_maskz_lzcnt_epi64( k, a);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x2(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_lzcnt_epi64(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  const struct {
    const int64_t a[4];
    const int64_t r[4];
  } test_vec[] = {
    { {  INT64_C( 7471018050742009450), -INT64_C( 7822588333669521718),  INT64_C(   81253872576394900), -INT64_C( 7087003131206119750) },
      {  INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   7),  INT64_C(                   0) } },
    { { -INT64_C( 3034356274706798554), -INT64_C( 7988679867269814477),  INT64_C( 1364349176485555703),  INT64_C( 6900387882527379698) },
      {  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   3),  INT64_C(                   1) } },
    { { -INT64_C( 2043861618590489918),  INT64_C( 3221081114432156453), -INT64_C( 3554454067602540735), -INT64_C(  147854371236601510) },
      {  INT64_C(                   0),  INT64_C(                   2),  INT64_C(                   0),  INT64_C(                   0) } },
    { { -INT64_C( 5680045684526756454),  INT64_C( 8395138735436701216),  INT64_C(  137003165018922045),  INT64_C( 3176311599222020828) },
      {  INT64_C(                   0),  INT64_C(                   1),  INT64_C(                   7),  INT64_C(                   2) } },
    { {  INT64_C( 7678815807127019091),  INT64_C( 2803563238963241792), -INT64_C( 8248864223124326691), -INT64_C(  811289353784124673) },
      {  INT64_C(                   1),  INT64_C(                   2),  INT64_C(                   0),  INT64_C(                   0) } },
    { {  INT64_C( 1534429868317684630),  INT64_C( 3014440099770862534),  INT64_C( 4082007532106552423), -INT64_C( 7285549846200956082) },
      {  INT64_C(                   3),  INT64_C(                   2),  INT64_C(                   2),  INT64_C(                   0) } },
    { { -INT64_C( 2187124222344841286),  INT64_C(  452443121155911377),  INT64_C( 8641499667418314106), -INT64_C(  527401380648339951) },
      {  INT64_C(                   0),  INT64_C(                   5),  INT64_C(                   1),  INT64_C(                   0) } },
    { { -INT64_C( 4467802895529072382),  INT64_C( 8142550968481845338), -INT64_C(  667921542857613541),  INT64_C( 8141586104249426630) },
      {  INT64_C(                   0),  INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   1) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i a = simde_mm256_loadu_epi64(test_vec[i].a);
    simde__m256i r = simde_mm256_lzcnt_epi64(a);
    simde_test_x86_assert_equal_i64x4(r, simde_mm256_loadu_epi64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256i a = simde_test_x86_random_i64x4();
    simde__m256i r = simde_mm256_lzcnt_epi64(a);

    simde_test_x86_write_i64x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_mask_lzcnt_epi64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  const struct {
    const int64_t src[4];
    const simde__mmask8 k;
    const int64_t a[4];
    const int64_t r[4];
  } test_vec[] = {
    { {  INT64_C(  762388928023856099), -INT64_C( 5439217394461150436),  INT64_C( 9223289268707305507), -INT64_C( 6362319892627911978) },
      UINT8_C(140),
      { -INT64_C( 1532052017298915069), -INT64_C( 1598635184138370686),  INT64_C( 6008630371568240682),  INT64_C( 7523064602940663548) },
      {  INT64_C(  762388928023856099), -INT64_C( 5439217394461150436),  INT64_C(                   1),  INT64_C(                   1) } },
    { { -INT64_C( 7317991117174465567),  INT64_C( 2733202690935917890),  INT64_C( 1812968450157629755),  INT64_C( 3486884866618812556) },
      UINT8_C(188),
      {  INT64_C( 5005347481632947715),  INT64_C( 6530772649244218910), -INT64_C( 4317352008474999864),  INT64_C( 9158349654673036440) },
      { -INT64_C( 7317991117174465567),  INT64_C( 2733202690935917890),  INT64_C(                   0),  INT64_C(                   1) } },
    { { -INT64_C( 6275759682149721288),  INT64_C( 5174110422584222478),  INT64_C( 8426309533646703273),  INT64_C( 2925492513260230878) },
      UINT8_C(250),
      {  INT64_C( 7801599454895757770), -INT64_C( 2987785215156286659),  INT64_C( 3053474962580899851), -INT64_C( 8498396121943027465) },
      { -INT64_C( 6275759682149721288),  INT64_C(                   0),  INT64_C( 8426309533646703273),  INT64_C(                   0) } },
    { {  INT64_C( 8509485984148628993), -INT64_C( 1548258733780149961),  INT64_C( 2287936155749347241), -INT64_C( 5187185011423467672) },
      UINT8_C( 56),
      {  INT64_C( 6301004412304382864),  INT64_C( 4021523765959529475), -INT64_C( 3481070960927308095), -INT64_C( 8442317488936874137) },
      {  INT64_C( 8509485984148628993), -INT64_C( 1548258733780149961),  INT64_C( 2287936155749347241),  INT64_C(                   0) } },
    { {  INT64_C(  726961861288297833), -INT64_C( 3417439597719061634),  INT64_C( 7131458610885239504),  INT64_C( 6265885790809298656) },
      UINT8_C( 49),
      {  INT64_C( 8749227418728352874), -INT64_C( 6551087278703639430),  INT64_C( 3689342357762034942), -INT64_C( 2411707887728423356) },
      {  INT64_C(                   1), -INT64_C( 3417439597719061634),  INT64_C( 7131458610885239504),  INT64_C( 6265885790809298656) } },
    { { -INT64_C( 5842955790596685840), -INT64_C( 8085607013137895952),  INT64_C( 6759365167078873949),  INT64_C( 8510588914846793478) },
      UINT8_C( 26),
      { -INT64_C( 2430027424757102354),  INT64_C( 5606265686338488828), -INT64_C( 3730204493273845744), -INT64_C( 6150840960412152666) },
      { -INT64_C( 5842955790596685840),  INT64_C(                   1),  INT64_C( 6759365167078873949),  INT64_C(                   0) } },
    { {  INT64_C( 5932338611722142600),  INT64_C( 1086652147870962064),  INT64_C( 4302522238228624232),  INT64_C(  955785134944543063) },
      UINT8_C( 60),
      { -INT64_C( 4485383805927666716), -INT64_C(  236761598385585336), -INT64_C( 8919449237544268851), -INT64_C( 5461756051060871518) },
      {  INT64_C( 5932338611722142600),  INT64_C( 1086652147870962064),  INT64_C(                   0),  INT64_C(                   0) } },
    { { -INT64_C( 1830942074477862249), -INT64_C( 9179049667374465291), -INT64_C(   79884122844194430), -INT64_C( 3022898043586475042) },
      UINT8_C(129),
      { -INT64_C( 6958980987419854172), -INT64_C( 2346643283248158982),  INT64_C( 3203473639708105894),  INT64_C( 7576470492152546065) },
      {  INT64_C(                   0), -INT64_C( 9179049667374465291), -INT64_C(   79884122844194430), -INT64_C( 3022898043586475042) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i src = simde_mm256_loadu_epi64(test_vec[i].src);
    simde__m256i a = simde_mm256_loadu_epi64(test_vec[i].a);
    simde__m256i r = simde_mm256_mask_lzcnt_epi64(src, test_vec[i].k, a);
    simde_test_x86_assert_equal_i64x4(r, simde_mm256_loadu_epi64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256i src = simde_test_x86_random_i64x4();
    simde__m256i a = simde_test_x86_random_i64x4();
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256i r = simde_mm256_mask_lzcnt_epi64(src, k, a);

    simde_test_x86_write_i64x4(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_maskz_lzcnt_epi64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  const struct {
    const simde__mmask8 k;
    const int64_t a[4];
    const int64_t r[4];
  } test_vec[] = {
    { UINT8_C( 55),
      {  INT64_C( 4827799822137028426),  INT64_C( 8857312035514347065),  INT64_C( 1925276572777472672),  INT64_C( 8536652451655124719) },
      {  INT64_C(                   1),  INT64_C(                   1),  INT64_C(                   3),  INT64_C(                   0) } },
    { UINT8_C( 21),
      {  INT64_C( 7613008045724105635),  INT64_C( 4149014652007214197), -INT64_C(  581761558022964726),  INT64_C(   38730697881674761) },
      {  INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C(168),
      {  INT64_C(   29547265942122012),  INT64_C( 3030097846844546241), -INT64_C( 2497788085692331230),  INT64_C( 5612675016920049462) },
      {  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   1) } },
    { UINT8_C(208),
      {  INT64_C(  229610632834269044),  INT64_C( 5388870588363387541),  INT64_C( 1405439104400889144), -INT64_C( 6251963622901985191) },
      {  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C(215),
      {  INT64_C( 8668438926437324793), -INT64_C( 3259478320983051410), -INT64_C( 2180498063506993340), -INT64_C( 8650078371355143788) },
      {  INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C( 87),
      {  INT64_C( 9103347745126432364), -INT64_C( 5362928822834765491),  INT64_C(  301221877421373002), -INT64_C( 5489015723863682243) },
      {  INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   5),  INT64_C(                   0) } },
    { UINT8_C(162),
      { -INT64_C( 3326928738043454735), -INT64_C( 5913176048237337702),  INT64_C(  925320096281299827), -INT64_C( 7464989443228380169) },
      {  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C( 29),
      {  INT64_C( 1676011909491597128),  INT64_C( 7240515898502408411), -INT64_C( 4668215294569933349), -INT64_C(  709318390771726466) },
      {  INT64_C(                   3),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i a = simde_mm256_loadu_epi64(test_vec[i].a);
    simde__m256i r = simde_mm256_maskz_lzcnt_epi64(test_vec[i].k, a);
    simde_test_x86_assert_equal_i64x4(r, simde_mm256_loadu_epi64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256i a = simde_test_x86_random_i64x4();
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256i r = simde_mm256_maskz_lzcnt_epi64( k, a);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_lzcnt_epi64(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  const struct {
    const int64_t a[16];
    const int64_t r[16];
  } test_vec[] = {
    { { -INT64_C( 3893316934836314439), -INT64_C( 8049332781754220299),  INT64_C(  705723472323316515),  INT64_C( 3656550681075470754),
        -INT64_C( 1372111384538525876), -INT64_C( 4516363180286634169), -INT64_C( 6053442587831906766), -INT64_C( 5848757122307935189) },
      {  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   4),  INT64_C(                   2),
         INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0) } },
    { { -INT64_C( 5567345877852740391), -INT64_C(  880798149076838041), -INT64_C( 2789445956026248044),  INT64_C( 8694571402688042393),
        -INT64_C( 4930028354955344777),  INT64_C( 7264735905573767454),  INT64_C( 4027146733439072603),  INT64_C( 3024691283985916129) },
      {  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   1),
         INT64_C(                   0),  INT64_C(                   1),  INT64_C(                   2),  INT64_C(                   2) } },
    { {  INT64_C( 7309519524557767264),  INT64_C( 1359829490263601322),  INT64_C( 1127023802813505998),  INT64_C( 1385571237556704862),
        -INT64_C( 7892777256839788853), -INT64_C( 7047592662751462552), -INT64_C( 6194229270642274867), -INT64_C( 1275938012798412412) },
      {  INT64_C(                   1),  INT64_C(                   3),  INT64_C(                   4),  INT64_C(                   3),
         INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0) } },
    { { -INT64_C( 5497355510325636548),  INT64_C( 8836349085017621043), -INT64_C( 2502173619615585455),  INT64_C( 3686582185920561432),
        -INT64_C( 2995442804792612239), -INT64_C( 7568726585388678706),  INT64_C(   98368810657147687),  INT64_C( 4657960955751985530) },
      {  INT64_C(                   0),  INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   2),
         INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   7),  INT64_C(                   1) } },
    { { -INT64_C( 3095545214694261872), -INT64_C( 8753231447880309589), -INT64_C( 6008818733818660431), -INT64_C( 3466432234576225836),
        -INT64_C(  677495649880252227), -INT64_C( 2101090646861813007),  INT64_C( 1514644618128252198), -INT64_C( 6700900063331671054) },
      {  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
         INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   3),  INT64_C(                   0) } },
    { {  INT64_C(  198159559509345406),  INT64_C( 4322656383680030699), -INT64_C( 8764681537152910841),  INT64_C( 3694281784104064955),
        -INT64_C( 7507292028921861187),  INT64_C( 6031358168468234852), -INT64_C( 7258121584561666261),  INT64_C( 8356570631050689807) },
      {  INT64_C(                   6),  INT64_C(                   2),  INT64_C(                   0),  INT64_C(                   2),
         INT64_C(                   0),  INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   1) } },
    { {  INT64_C( 1616530251079349547), -INT64_C(   84650491827576268),  INT64_C( 8503643160272793225), -INT64_C( 1501331726797226240),
        -INT64_C( 5625221893456696537),  INT64_C( 5270905637238308437), -INT64_C( 1923399992052948110), -INT64_C( 2044697196311574028) },
      {  INT64_C(                   3),  INT64_C(                   0),  INT64_C(                   1),  INT64_C(                   0),
         INT64_C(                   0),  INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0) } },
    { { -INT64_C( 1630394785498111439),  INT64_C(  446761900761518122), -INT64_C( 8150057815489125350),  INT64_C( 8743141948585574838),
        -INT64_C( 1746965931014811325),  INT64_C( 2644180375115518487),  INT64_C( 8435253919703405033),  INT64_C( 8524254388001657483) },
      {  INT64_C(                   0),  INT64_C(                   5),  INT64_C(                   0),  INT64_C(                   1),
         INT64_C(                   0),  INT64_C(                   2),  INT64_C(                   1),  INT64_C(                   1) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i a = simde_mm512_loadu_epi64(test_vec[i].a);
    simde__m512i r = simde_mm512_lzcnt_epi64(a);
    simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512i a = simde_test_x86_random_i64x8();
    simde__m512i r = simde_mm512_lzcnt_epi64(a);

    simde_test_x86_write_i64x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_mask_lzcnt_epi64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  const struct {
    const int64_t src[16];
    const simde__mmask8 k;
    const int64_t a[16];
    const int64_t r[16];
  } test_vec[] = {
    { {  INT64_C( 1365452678629323598), -INT64_C( 5615864722785123103), -INT64_C( 3875834293474020350), -INT64_C( 6322515825679065449),
        -INT64_C( 9193632865782034596), -INT64_C( 7357057051913410709), -INT64_C(  596567105124820048), -INT64_C( 7227709787478010449) },
      UINT8_C(100),
      {  INT64_C( 8697113942653298323),  INT64_C( 5310750671370001794),  INT64_C( 5550388152414703022),  INT64_C( 6926265525917435973),
        -INT64_C( 1228281565628198545), -INT64_C( 2070606662669459103), -INT64_C( 5713668887053960248), -INT64_C( 8940398337527116864) },
      {  INT64_C( 1365452678629323598), -INT64_C( 5615864722785123103),  INT64_C(                   1), -INT64_C( 6322515825679065449),
        -INT64_C( 9193632865782034596),  INT64_C(                   0),  INT64_C(                   0), -INT64_C( 7227709787478010449) } },
    { { -INT64_C( 7699819508725121153), -INT64_C( 2501558954425180218),  INT64_C( 7951379348257812383),  INT64_C( 5901129288413013293),
         INT64_C( 4218809025952003588), -INT64_C( 6658850205196396969),  INT64_C(  469381346750095538),  INT64_C( 1052554828888606072) },
      UINT8_C( 46),
      {  INT64_C( 4598899692867596067),  INT64_C( 4868550149329751529), -INT64_C( 3003658653940528272),  INT64_C( 7492506834777987041),
         INT64_C( 8976185963008950378), -INT64_C( 8416672334514386338),  INT64_C( 5186497941976943301),  INT64_C( 4659025312249748220) },
      { -INT64_C( 7699819508725121153),  INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   1),
         INT64_C( 4218809025952003588),  INT64_C(                   0),  INT64_C(  469381346750095538),  INT64_C( 1052554828888606072) } },
    { { -INT64_C( 5920477437572836697), -INT64_C( 9194850745482427226), -INT64_C( 7113385573772523481), -INT64_C( 2900965563810215839),
         INT64_C( 7140217225370107718),  INT64_C( 6440262034855813098), -INT64_C( 3165769457924225296),  INT64_C( 8970644026372096886) },
      UINT8_C( 38),
      { -INT64_C( 2467974849098232416),  INT64_C( 1974579028098400988),  INT64_C( 8118757553444097379), -INT64_C( 3470985382238679519),
        -INT64_C( 7839944828658075038),  INT64_C( 8066800208817811374),  INT64_C( 4647979931165688085), -INT64_C( 8070894545168459777) },
      { -INT64_C( 5920477437572836697),  INT64_C(                   3),  INT64_C(                   1), -INT64_C( 2900965563810215839),
         INT64_C( 7140217225370107718),  INT64_C(                   1), -INT64_C( 3165769457924225296),  INT64_C( 8970644026372096886) } },
    { {  INT64_C(  487637904133055530),  INT64_C( 1238351977957792785),  INT64_C( 6321208620250906568),  INT64_C( 1268628501058283529),
        -INT64_C(  498514276828874505),  INT64_C( 8226179492667926407), -INT64_C( 3055721161029821823),  INT64_C( 2649495564756589517) },
      UINT8_C( 30),
      {  INT64_C( 6791507223717800798),  INT64_C( 1624566453794853742),  INT64_C( 7609375402495555576),  INT64_C( 2908166238727103241),
         INT64_C( 4828333607622774476),  INT64_C(  986260923353953795), -INT64_C(   98117169680677218),  INT64_C( 7872169690925481806) },
      {  INT64_C(  487637904133055530),  INT64_C(                   3),  INT64_C(                   1),  INT64_C(                   2),
         INT64_C(                   1),  INT64_C( 8226179492667926407), -INT64_C( 3055721161029821823),  INT64_C( 2649495564756589517) } },
    { { -INT64_C( 8691605258101387090), -INT64_C( 5901779671080699501), -INT64_C( 5461562370585046405),  INT64_C( 4144932936037518294),
         INT64_C( 4785910988355893458),  INT64_C( 3191315670239021042),  INT64_C( 7192326176769240102), -INT64_C( 5091795574151633518) },
      UINT8_C(133),
      { -INT64_C( 2830223303923405113),  INT64_C( 8136804180983772429), -INT64_C( 2983533305106989656),  INT64_C( 8584223386768728449),
        -INT64_C( 3317280718544061129), -INT64_C( 3614567349865191140),  INT64_C( 4580893914977952376),  INT64_C(  442417978397918716) },
      {  INT64_C(                   0), -INT64_C( 5901779671080699501),  INT64_C(                   0),  INT64_C( 4144932936037518294),
         INT64_C( 4785910988355893458),  INT64_C( 3191315670239021042),  INT64_C( 7192326176769240102),  INT64_C(                   5) } },
    { { -INT64_C( 8875721738570619888),  INT64_C( 8258606723613931945),  INT64_C( 8003020688500742265), -INT64_C( 1196475497178088425),
         INT64_C( 8216388472276430439), -INT64_C( 6902837186797326414), -INT64_C( 1377040644275149686), -INT64_C( 3797043128653045632) },
      UINT8_C( 32),
      {  INT64_C( 2385310687381288416),  INT64_C( 7838822886547894275), -INT64_C( 4522525240489640581),  INT64_C( 1806910167319578852),
        -INT64_C( 5191563276239871644),  INT64_C( 7628159805619820173),  INT64_C( 7218132759669750824),  INT64_C( 2184456625776774141) },
      { -INT64_C( 8875721738570619888),  INT64_C( 8258606723613931945),  INT64_C( 8003020688500742265), -INT64_C( 1196475497178088425),
         INT64_C( 8216388472276430439),  INT64_C(                   1), -INT64_C( 1377040644275149686), -INT64_C( 3797043128653045632) } },
    { { -INT64_C( 4937197651594186478), -INT64_C( 8989165309421622419),  INT64_C( 2358874468270713290),  INT64_C( 6193567982277030675),
        -INT64_C( 4428798383288497942),  INT64_C( 1077515087823647402),  INT64_C( 8338566853266634948),  INT64_C( 8508770347670475645) },
      UINT8_C(245),
      { -INT64_C( 4532364950328027134), -INT64_C( 3291806910420683776),  INT64_C( 2806063253705924383),  INT64_C( 8338691173948733366),
        -INT64_C( 3806417122208580269), -INT64_C( 6505343529235095593), -INT64_C(  194194338570099841), -INT64_C( 9065473165974555572) },
      {  INT64_C(                   0), -INT64_C( 8989165309421622419),  INT64_C(                   2),  INT64_C( 6193567982277030675),
         INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0) } },
    { {  INT64_C( 8770068796896505338),  INT64_C( 8609092847590677402),  INT64_C( 2533764003759301063),  INT64_C( 1291077442543478524),
        -INT64_C( 3434657485746623806), -INT64_C( 4680291177817549760), -INT64_C( 9009796821641540892), -INT64_C( 2390178726077314901) },
      UINT8_C( 12),
      { -INT64_C( 6264208666241875189),  INT64_C(  151795407175670627),  INT64_C( 2818632677837879060),  INT64_C(    4150609970893843),
         INT64_C( 4364924654960429441),  INT64_C( 3337363149922226223),  INT64_C(  292142377953928553),  INT64_C( 3922428246980097913) },
      {  INT64_C( 8770068796896505338),  INT64_C( 8609092847590677402),  INT64_C(                   2),  INT64_C(                  12),
        -INT64_C( 3434657485746623806), -INT64_C( 4680291177817549760), -INT64_C( 9009796821641540892), -INT64_C( 2390178726077314901) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i src = simde_mm512_loadu_epi64(test_vec[i].src);
    simde__m512i a = simde_mm512_loadu_epi64(test_vec[i].a);
    simde__m512i r = simde_mm512_mask_lzcnt_epi64(src, test_vec[i].k, a);
    simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512i src = simde_test_x86_random_i64x8();
    simde__m512i a = simde_test_x86_random_i64x8();
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m512i r = simde_mm512_mask_lzcnt_epi64(src, k, a);

    simde_test_x86_write_i64x8(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_maskz_lzcnt_epi64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  const struct {
    const simde__mmask8 k;
    const int64_t a[16];
    const int64_t r[16];
  } test_vec[] = {
    { UINT8_C( 29),
      { -INT64_C( 8920750483637526351), -INT64_C(  660678045507616328), -INT64_C( 4759200043990795884), -INT64_C( 9047826409582337504),
         INT64_C( 3171020622130468041), -INT64_C(   71376536567570629), -INT64_C(  673167374450824668), -INT64_C( 8276831318812517425) },
      {  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
         INT64_C(                   2),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C( 10),
      { -INT64_C( 6152552559810573656), -INT64_C( 7573623366652417707), -INT64_C( 7797311533084782450),  INT64_C( 3865185296926075580),
         INT64_C( 5306707062235280879),  INT64_C( 6782684717768162270), -INT64_C( 6067715463107146561), -INT64_C(  625766121706806641) },
      {  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   2),
         INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C(216),
      {  INT64_C( 5979452744144974568),  INT64_C( 3675079846991660626),  INT64_C( 2706325838850308059), -INT64_C( 2099200816099579137),
         INT64_C( 8646905948826230037),  INT64_C( 9104792607568437889),  INT64_C( 5266691805268507887),  INT64_C( 8976794905034441654) },
      {  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
         INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   1),  INT64_C(                   1) } },
    { UINT8_C(125),
      {  INT64_C( 5408387924343204242),  INT64_C(  996540787127629356),  INT64_C( 2354152105395603177), -INT64_C( 9110495143554229059),
         INT64_C( 3432056291198996013), -INT64_C( 1877463401075798189), -INT64_C( 6508960503097046866),  INT64_C( 7229102275386225634) },
      {  INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   2),  INT64_C(                   0),
         INT64_C(                   2),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C( 52),
      { -INT64_C( 1381849323838325919), -INT64_C( 1199702805201832253), -INT64_C( 4391154152976685913), -INT64_C( 7762694810489921318),
         INT64_C( 4063062106496550169), -INT64_C( 4813436410891318884),  INT64_C( 7022793555171740194), -INT64_C( 1756562403204960295) },
      {  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
         INT64_C(                   2),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C(234),
      {  INT64_C(  591346763620244914), -INT64_C( 5393663455463049274), -INT64_C( 4929298314198984763), -INT64_C(  762673757217512506),
        -INT64_C( 4930102431694646323),  INT64_C( 6095873398003446584),  INT64_C( 4018524169964803260), -INT64_C( 8465404190394593971) },
      {  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
         INT64_C(                   0),  INT64_C(                   1),  INT64_C(                   2),  INT64_C(                   0) } },
    { UINT8_C(224),
      {  INT64_C( 6704623628255761937),  INT64_C( 6555904627910176346),  INT64_C( 1461702612021347154),  INT64_C( 8012285668247066991),
         INT64_C(  538545932539597169), -INT64_C(  569070222757698246),  INT64_C( 6278087046925182276), -INT64_C( 4619620861175991785) },
      {  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
         INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   1),  INT64_C(                   0) } },
    { UINT8_C(125),
      { -INT64_C( 4995455895769130203),  INT64_C( 7809056516658392281),  INT64_C( 9052706441312627532),  INT64_C( 2231967892823020874),
        -INT64_C(  976371712535853723),  INT64_C( 8546543646299509672), -INT64_C( 1810269357171740457), -INT64_C( 7291617837179753545) },
      {  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   1),  INT64_C(                   3),
         INT64_C(                   0),  INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0) } },  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i a = simde_mm512_loadu_epi64(test_vec[i].a);
    simde__m512i r = simde_mm512_maskz_lzcnt_epi64(test_vec[i].k, a);
    simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512i a = simde_test_x86_random_i64x8();
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m512i r = simde_mm512_maskz_lzcnt_epi64(k, a);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}


SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_lzcnt_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_lzcnt_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_maskz_lzcnt_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_lzcnt_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_lzcnt_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_maskz_lzcnt_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_lzcnt_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_lzcnt_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_maskz_lzcnt_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_lzcnt_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_lzcnt_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_maskz_lzcnt_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_lzcnt_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_lzcnt_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_maskz_lzcnt_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_lzcnt_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_lzcnt_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_maskz_lzcnt_epi64)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/avx512/test-avx512-footer.h>
