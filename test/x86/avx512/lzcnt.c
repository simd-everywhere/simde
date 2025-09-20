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
    { {  INT64_C( 1247850566362023372), -INT64_C( 2330351344987946039) },
      {  INT64_C(                   0),  INT64_C(                   1) } },
    { { -INT64_C( 3927234642518028804), -INT64_C( 6608417995571032031) },
      {  INT64_C(                   1),  INT64_C(                   0) } },
    { {  INT64_C( 2089249474608107891),  INT64_C(  860237071569461829) },
      {  INT64_C(                   0),  INT64_C(                   3) } },
    { { -INT64_C( 3122699111737717766), -INT64_C(  360942697799591551) },
      {  INT64_C(                   0),  INT64_C(                   1) } },
    { { -INT64_C(  851771114909127234), -INT64_C( 2728346981913742840) },
      {  INT64_C(                   3),  INT64_C(                   3) } },
    { {  INT64_C(  542794284818732033),  INT64_C( 6143013895530474174) },
      {  INT64_C(                   0),  INT64_C(                   1) } },
    { {  INT64_C( 1526600483742295948),  INT64_C( 3098562486566925382) },
      {  INT64_C(                   2),  INT64_C(                   2) } },
    { { -INT64_C( 2418319610985071645), -INT64_C( 4882355884302020270) },
      {  INT64_C(                   1),  INT64_C(                   0) } },
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
    { {  INT64_C( 9056217920920069259),  INT64_C(  914411222598933082) },
      UINT8_C( 95),
      { -INT64_C( 5239553449187641968),  INT64_C( 1472575308445463169) },
      {  INT64_C(                   0),  INT64_C(                   0) } },
    { { -INT64_C( 8062910396106012518), -INT64_C( 2274100864136667283) },
      UINT8_C( 58),
      {  INT64_C( 6039000688378304496),  INT64_C( 3097306810928116670) },
      { -INT64_C( 8062910396106012518),  INT64_C(                   1) } },
    { {  INT64_C( 8456477888967916324), -INT64_C( 3734990572599546838) },
      UINT8_C(124),
      { -INT64_C( 7214782098725594550), -INT64_C(  670218052046012235) },
      {  INT64_C( 8456477888967916324), -INT64_C( 3734990572599546838) } },
    { {  INT64_C( 7450152230856728777), -INT64_C( 3952172007474113530) },
      UINT8_C( 42),
      {  INT64_C(  822943542586567621),  INT64_C( 5340492534898948204) },
      {  INT64_C( 7450152230856728777),  INT64_C(                   1) } },
    { {  INT64_C( 1175629427443586825), -INT64_C( 1789519899353154576) },
      UINT8_C( 68),
      {  INT64_C(   96291968112303420),  INT64_C( 2352839196846828384) },
      {  INT64_C( 1175629427443586825), -INT64_C( 1789519899353154576) } },
    { {  INT64_C( 4312456406736105531),  INT64_C( 4474683583241246844) },
      UINT8_C(226),
      {  INT64_C( 3071996452154321191), -INT64_C( 3113935794994987369) },
      {  INT64_C( 4312456406736105531),  INT64_C(                   0) } },
    { {  INT64_C( 7014162398157517295),  INT64_C( 7914127766971428012) },
      UINT8_C(202),
      { -INT64_C( 8267918080373772609),  INT64_C( 5361893356847878247) },
      {  INT64_C( 7014162398157517295),  INT64_C(                   1) } },
    { { -INT64_C( 3939465926590380711), -INT64_C( 2809266390009231721) },
      UINT8_C( 41),
      { -INT64_C( 7626558142767659955),  INT64_C( 5914485310526301046) },
      {  INT64_C(                   0), -INT64_C( 2809266390009231721) } },
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
    { UINT8_C( 76),
      { -INT64_C( 4154826056185876804), -INT64_C( 3557725738654142128) },
      {  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C(227),
      {  INT64_C( 6498235952961000545),  INT64_C( 8929547951933766427) },
      {  INT64_C(                   0),  INT64_C(                   2) } },
    { UINT8_C(161),
      {  INT64_C( 4234800891573056509),  INT64_C( 8168836885622624091) },
      {  INT64_C(                   1),  INT64_C(                   0) } },
    { UINT8_C(114),
      { -INT64_C( 3796273939906192153), -INT64_C( 8357119219486434020) },
      {  INT64_C(                   0),  INT64_C(                   4) } },
    { UINT8_C( 69),
      {  INT64_C( 7290670010094945625),  INT64_C( 1795072007913474724) },
      {  INT64_C(                   3),  INT64_C(                   0) } },
    { UINT8_C( 49),
      { -INT64_C( 4238948439957827586), -INT64_C( 7592902871279827646) },
      {  INT64_C(                   1),  INT64_C(                   0) } },
    { UINT8_C(228),
      { -INT64_C( 6199993529313438018), -INT64_C( 7558383193350901709) },
      {  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C( 88),
      { -INT64_C( 8566739055951056534),  INT64_C( 1907561160167664923) },
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
    { { -INT64_C( 9017044824592955967), -INT64_C( 2817044033896341143),  INT64_C( 7978905102576174103), -INT64_C(  981522823615160725) },
      {  INT64_C(                   0),  INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   2) } },
    { {  INT64_C( 3150111543288708531), -INT64_C( 6824231572845187054),  INT64_C( 1410483925088855354), -INT64_C( 5904875540941500950) },
      {  INT64_C(                   2),  INT64_C(                   1),  INT64_C(                   2),  INT64_C(                   3) } },
    { {  INT64_C( 2690225759521579367), -INT64_C( 7892871326256798902), -INT64_C( 4862960904935323704), -INT64_C( 2377649397814538921) },
      {  INT64_C(                   2),  INT64_C(                   0),  INT64_C(                   1),  INT64_C(                   1) } },
    { { -INT64_C( 3981641127017454714),  INT64_C(  228577723983615809), -INT64_C( 8905596487586290727), -INT64_C( 6188836336786063164) },
      {  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   2) } },
    { { -INT64_C( 4251676760623340102), -INT64_C( 8604538655155053479), -INT64_C( 4243063743233914260), -INT64_C( 8886975586736344100) },
      {  INT64_C(                   2),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   7) } },
    { {  INT64_C( 5371312152688455491), -INT64_C( 2482199790832720041),  INT64_C( 4198643886202536318), -INT64_C( 6352635806297143672) },
      {  INT64_C(                   0),  INT64_C(                   5),  INT64_C(                   1),  INT64_C(                   1) } },
    { { -INT64_C( 6696299261787794986), -INT64_C( 2293116839373705505), -INT64_C( 4498915461573925640), -INT64_C( 8505353889907487510) },
      {  INT64_C(                   0),  INT64_C(                   1),  INT64_C(                   1),  INT64_C(                   1) } },
    { {  INT64_C( 4209283848545002618),  INT64_C( 4797099184065483599), -INT64_C( 9199120561637625252), -INT64_C( 3661208438747207180) },
      {  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0) } },
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
    { {  INT64_C( 3585145547949113386),  INT64_C( 6890073132932221458),  INT64_C( 6016329023573210727),  INT64_C( 4455233292114480564) },
      UINT8_C(102),
      {  INT64_C( 8700536006614673579),  INT64_C( 9092611615002763725),  INT64_C( 2547622790198666152),  INT64_C( 3141540563017946183) },
      {  INT64_C( 3585145547949113386),  INT64_C(                   0),  INT64_C(                   5),  INT64_C( 4455233292114480564) } },
    { {  INT64_C( 1705533260736280667), -INT64_C( 3588054254122861799), -INT64_C( 1556170052137632985), -INT64_C( 5337446866824346999) },
      UINT8_C(135),
      {  INT64_C( 1790531595058526796), -INT64_C( 2795933058427779142),  INT64_C( 6382834112150531860), -INT64_C( 2435658419393266397) },
      {  INT64_C(                   0),  INT64_C(                   1),  INT64_C(                   0), -INT64_C( 5337446866824346999) } },
    { { -INT64_C( 9097659950342692411), -INT64_C( 4309930184197004733),  INT64_C( 7821884412774242823),  INT64_C(  152801590183332554) },
      UINT8_C(159),
      { -INT64_C( 8828809802575076227), -INT64_C( 4395563009689145882),  INT64_C( 5082233547682189996), -INT64_C( 2377624204945291838) },
      {  INT64_C(                   0),  INT64_C(                   2),  INT64_C(                   3),  INT64_C(                   0) } },
    { { -INT64_C(   94180520499161338),  INT64_C( 9117392227863751689), -INT64_C( 5899362390918913369),  INT64_C( 2790524365287989022) },
      UINT8_C(193),
      {  INT64_C(  870498762142882758), -INT64_C( 1082994448508924530),  INT64_C( 5974429750302602001), -INT64_C( 5848444285276587633) },
      {  INT64_C(                   3),  INT64_C( 9117392227863751689), -INT64_C( 5899362390918913369),  INT64_C( 2790524365287989022) } },
    { { -INT64_C( 6415429511964998457),  INT64_C( 6717083016259138231),  INT64_C( 5993979231935230254),  INT64_C( 8807046028315057488) },
      UINT8_C(134),
      { -INT64_C( 8922233610956440402),  INT64_C( 3104635993671212365), -INT64_C( 2665577329433401773), -INT64_C( 3169538914149909291) },
      { -INT64_C( 6415429511964998457),  INT64_C(                   0),  INT64_C(                   0),  INT64_C( 8807046028315057488) } },
    { { -INT64_C( 6553063425418503194), -INT64_C( 9099859654902364542), -INT64_C( 6817350987547908970), -INT64_C( 3078038895535330504) },
      UINT8_C(152),
      { -INT64_C(  854376118108120074),  INT64_C( 3082448495661598315), -INT64_C(  902659761013992590), -INT64_C( 3257512254992203770) },
      { -INT64_C( 6553063425418503194), -INT64_C( 9099859654902364542), -INT64_C( 6817350987547908970),  INT64_C(                   0) } },
    { {  INT64_C( 4355261722023055712),  INT64_C( 5897739132822664791),  INT64_C( 7625719144772317106), -INT64_C(  916175130386380620) },
      UINT8_C(251),
      { -INT64_C( 6261295052262714519), -INT64_C( 7498519881179993313), -INT64_C( 5897401062437618794), -INT64_C( 1331191352479748864) },
      {  INT64_C(                   0),  INT64_C(                   0),  INT64_C( 7625719144772317106),  INT64_C(                   0) } },
    { { -INT64_C( 3240348827184608130), -INT64_C( 8177322427119197178), -INT64_C( 2815534354862160971), -INT64_C( 8846958602332897131) },
      UINT8_C(140),
      { -INT64_C( 8803847332284299498), -INT64_C( 8053853560264029416), -INT64_C( 8179544103260929479),  INT64_C( 4140784034345966059) },
      { -INT64_C( 3240348827184608130), -INT64_C( 8177322427119197178),  INT64_C(                   0),  INT64_C(                   0) } },
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
    { UINT8_C(192),
      { -INT64_C( 7678761565070673693),  INT64_C( 1671399876164852226),  INT64_C( 3230662390937867902),  INT64_C( 2448700624142845802) },
      {  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C(173),
      {  INT64_C(  186723357814323206), -INT64_C( 7471632573281169200), -INT64_C( 3060733547369514627), -INT64_C(  599202011714161050) },
      {  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   3),  INT64_C(                   0) } },
    { UINT8_C(230),
      { -INT64_C( 5428642790805041798),  INT64_C(  276988738858810093),  INT64_C( 8104480941416772858), -INT64_C( 7936933437206534151) },
      {  INT64_C(                   0),  INT64_C(                   1),  INT64_C(                   3),  INT64_C(                   0) } },
    { UINT8_C( 68),
      { -INT64_C( 8146238683254920593),  INT64_C( 1819272990116302134),  INT64_C( 3551937998127059308), -INT64_C( 4420607030502852250) },
      {  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   1),  INT64_C(                   0) } },
    { UINT8_C(252),
      {  INT64_C(  551381692822636721),  INT64_C( 8937188039112583999),  INT64_C( 2180719298354764249),  INT64_C( 6475671212955599552) },
      {  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C(247),
      {  INT64_C( 6655122263097395766),  INT64_C( 6199490748028024554),  INT64_C( 3135095957758928458),  INT64_C( 3511450889448856715) },
      {  INT64_C(                   3),  INT64_C(                   2),  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C(113),
      { -INT64_C( 7054109639693546127),  INT64_C( 4150333496236919371), -INT64_C(  463151831214564627),  INT64_C( 9044956537993580897) },
      {  INT64_C(                   2),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C( 84),
      {  INT64_C( 1296395435578666478),  INT64_C( 4554157251960786004),  INT64_C( 2156685239825218303), -INT64_C(  963868163132785399) },
      {  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0) } },
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
    { { -INT64_C( 1241255571083254599),  INT64_C( 8803430334651829392),  INT64_C( 2543518554813544493), -INT64_C( 3204283534539261299),
         INT64_C( 6867157992094409661),  INT64_C( 6904502225797390359),  INT64_C(  665387582412167025),  INT64_C( 4059650347906196073) },
      {  INT64_C(                   1),  INT64_C(                   2),  INT64_C(                   1),  INT64_C(                   2),
         INT64_C(                   1),  INT64_C(                   1),  INT64_C(                   3),  INT64_C(                   0) } },
    { { -INT64_C( 4640706909616694167),  INT64_C( 5662968518762964229), -INT64_C( 8105457717702412034), -INT64_C( 1101577032483815421),
         INT64_C( 4137613114640780805),  INT64_C( 7427005782529442278),  INT64_C( 2086402587625617470),  INT64_C( 8474456668184905508) },
      {  INT64_C(                   2),  INT64_C(                   2),  INT64_C(                   1),  INT64_C(                   1),
         INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   1),  INT64_C(                   0) } },
    { {  INT64_C( 7786034936705827999), -INT64_C( 4405010248818983666),  INT64_C( 5183955586288959419),  INT64_C( 8937549439031216931),
        -INT64_C( 4232437284432041647),  INT64_C( 8079487097775092698), -INT64_C( 8700050247792637735),  INT64_C( 1520566047757448897) },
      {  INT64_C(                   0),  INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
         INT64_C(                   0),  INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0) } },
    { { -INT64_C( 6861462979776583349), -INT64_C(  664247833657998430),  INT64_C(  311088414549216614), -INT64_C( 2790898554487280789),
         INT64_C(  111642623656800294),  INT64_C( 1132691215470856869),  INT64_C( 5437300363790756397), -INT64_C(  360922576765446250) },
      {  INT64_C(                   6),  INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   2),
         INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   1),  INT64_C(                   2) } },
    { {  INT64_C( 2255866332977748206), -INT64_C(  814138024880134404),  INT64_C( 5651413591805758787), -INT64_C( 7800393271809480719),
         INT64_C( 1432195361075668295), -INT64_C( 7093051376187948587), -INT64_C( 4467801935281326600),  INT64_C( 2904336745011507477) },
      {  INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   2),  INT64_C(                   0),
         INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0) } },
    { {  INT64_C( 3609294652230479595),  INT64_C( 3640138005895630476), -INT64_C( 8726601202375900076), -INT64_C( 7179424239710016685),
        -INT64_C( 7112109526947510339), -INT64_C( 3607092507566663036),  INT64_C(  667893625605117004), -INT64_C( 3346848433817352896) },
      {  INT64_C(                   6),  INT64_C(                   0),  INT64_C(                   2),  INT64_C(                   2),
         INT64_C(                   3),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0) } },
    { {  INT64_C( 7462808609230695906),  INT64_C( 7609138462165701971), -INT64_C( 7013676515012998677),  INT64_C( 7337803616407775471),
         INT64_C( 5518293799364313418), -INT64_C( 4862284710998918401),  INT64_C(  376059462040791867),  INT64_C( 3375974468471605232) },
      {  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   6),
         INT64_C(                   2),  INT64_C(                   3),  INT64_C(                   0),  INT64_C(                   1) } },
    { {  INT64_C( 2010276814296658591), -INT64_C( 1569297008249274966), -INT64_C( 8177486208972908952),  INT64_C(  690981942400814211),
        -INT64_C( 8338828258860404466), -INT64_C( 6765180446532141436), -INT64_C( 2376875461329247786), -INT64_C( 1106515647383796432) },
      {  INT64_C(                   0),  INT64_C(                   1),  INT64_C(                   1),  INT64_C(                   1),
         INT64_C(                   2),  INT64_C(                   2),  INT64_C(                   1),  INT64_C(                   0) } },
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
    { { -INT64_C( 8106140183373119426),  INT64_C( 1779751973330355443), -INT64_C( 6949732193011172451),  INT64_C( 7096744082956575864),
         INT64_C( 3041744177389961779),  INT64_C( 7893503722748698230),  INT64_C( 1394218791972701014), -INT64_C( 5031297555271396186) },
      UINT8_C(176),
      {  INT64_C(  549605801256361536), -INT64_C(  381954240786314891),  INT64_C( 5816133569842866185), -INT64_C(  782139016272447261),
        -INT64_C( 7855108852236384666), -INT64_C( 8650136706309719979), -INT64_C( 7282915744161224206), -INT64_C( 5330808060568598438) },
      { -INT64_C( 8106140183373119426),  INT64_C( 1779751973330355443), -INT64_C( 6949732193011172451),  INT64_C( 7096744082956575864),
         INT64_C(                   0),  INT64_C(                   0),  INT64_C( 1394218791972701014),  INT64_C(                   3) } },
    { {  INT64_C( 2509454603251985521),  INT64_C( 7688532701982281014),  INT64_C( 5012713356333764691),  INT64_C( 1701036460256633025),
        -INT64_C(  161169955036501769), -INT64_C( 2422810654059633867), -INT64_C(   52737804658834750),  INT64_C( 1945701432613853507) },
      UINT8_C(234),
      {  INT64_C( 3724900193959515629), -INT64_C( 6607472373150420764),  INT64_C( 5136890855610867724), -INT64_C( 6485411367729744960),
         INT64_C( 2447154707909164229), -INT64_C( 5404075833372434566),  INT64_C( 5370903789265986365), -INT64_C( 5775814938686736005) },
      {  INT64_C( 2509454603251985521),  INT64_C(                   1),  INT64_C( 5012713356333764691),  INT64_C(                   0),
        -INT64_C(  161169955036501769),  INT64_C(                   1),  INT64_C(                   1),  INT64_C(                   2) } },
    { { -INT64_C( 8595603226266996175), -INT64_C( 5191551873597762600),  INT64_C( 8622859180723746022), -INT64_C( 1669972659055501638),
         INT64_C( 1978164646588512899),  INT64_C( 8266573221643527661),  INT64_C( 4624436529557797368),  INT64_C( 2434472258377911850) },
      UINT8_C(153),
      { -INT64_C( 5452591655694766858), -INT64_C( 2151473871500008155),  INT64_C( 4263999627987567975),  INT64_C( 5049630643506140499),
        -INT64_C( 4157714569751486255), -INT64_C( 2970797474321071367),  INT64_C( 8479978079618555233),  INT64_C( 9213091253454293572) },
      {  INT64_C(                   2), -INT64_C( 5191551873597762600),  INT64_C( 8622859180723746022),  INT64_C(                   0),
         INT64_C(                   0),  INT64_C( 8266573221643527661),  INT64_C( 4624436529557797368),  INT64_C(                   0) } },
    { {  INT64_C( 7361134021226141531),  INT64_C( 3275432838691097463),  INT64_C( 6819510402285561455),  INT64_C( 7943940808712730667),
        -INT64_C( 1193798632363689820),  INT64_C( 6831809931331650513),  INT64_C( 1031430846797389661), -INT64_C( 8279038979056902760) },
      UINT8_C( 84),
      {  INT64_C( 5751100563342604137), -INT64_C( 6443032271196662969),  INT64_C( 5391346083422556895), -INT64_C( 2397023905694514107),
        -INT64_C( 7164223886316318265),  INT64_C( 2617549357382272099),  INT64_C( 1780533545394498489), -INT64_C( 9110497570298877123) },
      {  INT64_C( 7361134021226141531),  INT64_C( 3275432838691097463),  INT64_C(                   0),  INT64_C( 7943940808712730667),
         INT64_C(                   1),  INT64_C( 6831809931331650513),  INT64_C(                   1), -INT64_C( 8279038979056902760) } },
    { { -INT64_C( 2430741646532819375),  INT64_C( 3330490279661924375),  INT64_C(  298672824225211439), -INT64_C( 4920674717188237216),
        -INT64_C( 4882217949422919930), -INT64_C( 2935656841361006128), -INT64_C( 4794674038762945513),  INT64_C( 8926933210057684157) },
      UINT8_C( 21),
      {  INT64_C( 3428956061478649398),  INT64_C( 6699813927657918842),  INT64_C( 6693549297026054857),  INT64_C( 1254365590974628983),
        -INT64_C( 2922129871126969371),  INT64_C(  357461381764265299),  INT64_C( 9055067615754175151),  INT64_C( 8791256914524188180) },
      {  INT64_C(                   0),  INT64_C( 3330490279661924375),  INT64_C(                   2), -INT64_C( 4920674717188237216),
         INT64_C(                   1), -INT64_C( 2935656841361006128), -INT64_C( 4794674038762945513),  INT64_C( 8926933210057684157) } },
    { { -INT64_C( 1891149896158626324),  INT64_C( 1290322315432712772),  INT64_C( 1113960174249784912),  INT64_C( 5900874834386380029),
        -INT64_C( 2021693337127397669), -INT64_C( 8702357224298901030), -INT64_C( 2077746134697684422), -INT64_C( 4073621396927623487) },
      UINT8_C(189),
      { -INT64_C( 7966932927469373716), -INT64_C( 3777405663396066091), -INT64_C( 7489186188966331833),  INT64_C( 5084904118342829022),
        -INT64_C(   93939902087797653), -INT64_C( 6185239567406567986), -INT64_C(  178199911385854185), -INT64_C( 1996122158492334932) },
      {  INT64_C(                   0),  INT64_C( 1290322315432712772),  INT64_C(                   2),  INT64_C(                   0),
         INT64_C(                   2),  INT64_C(                   1), -INT64_C( 2077746134697684422),  INT64_C(                   5) } },
    { {  INT64_C( 2679611783876314655), -INT64_C( 4133685744071307794),  INT64_C( 6674021389808603401),  INT64_C( 1135394121110103211),
         INT64_C( 8763617346279483328),  INT64_C( 7037621367944259117),  INT64_C( 2282183118042665016), -INT64_C(  318097254355074667) },
      UINT8_C( 23),
      { -INT64_C( 3273816053360949620),  INT64_C( 8426623290523948343), -INT64_C( 3781775507658095375),  INT64_C( 1740332895233484784),
        -INT64_C( 2061029411327599891),  INT64_C( 7928415055693093718),  INT64_C( 3146142824564771752), -INT64_C( 3484803274700817409) },
      {  INT64_C(                   3),  INT64_C(                   0),  INT64_C(                   1),  INT64_C( 1135394121110103211),
         INT64_C(                   0),  INT64_C( 7037621367944259117),  INT64_C( 2282183118042665016), -INT64_C(  318097254355074667) } },
    { { -INT64_C( 2095961879263157805),  INT64_C( 5630568824225823768), -INT64_C( 6415461592975539808), -INT64_C(  459834288950967542),
         INT64_C( 2189160664160624824),  INT64_C( 3225630169093488626),  INT64_C(  652771254786608318), -INT64_C( 6359594020748879970) },
      UINT8_C( 10),
      { -INT64_C( 5425843856255595633), -INT64_C( 3963469995602981818), -INT64_C( 2575424301399203271), -INT64_C( 8039382724049251368),
         INT64_C( 6999394383194068139),  INT64_C( 8355921379802237989),  INT64_C( 4715249472096708693),  INT64_C( 2041105287104434625) },
      { -INT64_C( 2095961879263157805),  INT64_C(                   0), -INT64_C( 6415461592975539808),  INT64_C(                   0),
         INT64_C( 2189160664160624824),  INT64_C( 3225630169093488626),  INT64_C(  652771254786608318), -INT64_C( 6359594020748879970) } },
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
    { UINT8_C(110),
      { -INT64_C(  543097530886026631), -INT64_C( 4376754898244360773),  INT64_C( 6197074330953504080), -INT64_C( 8000676521087351946),
         INT64_C( 6850353970039299437),  INT64_C( 4061279188836697085),  INT64_C( 7926185770484205668),  INT64_C( 1721027799576921659) },
      {  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   2),  INT64_C(                   0),
         INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C(  2),
      { -INT64_C( 8856204138488122941), -INT64_C( 7660160014628310594),  INT64_C( 2436158615871839004), -INT64_C( 4173743928659730349),
         INT64_C( 6186814041028109587),  INT64_C(  670284200018069675),  INT64_C( 2678071478273825198), -INT64_C( 1489321658869418612) },
      {  INT64_C(                   0),  INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
         INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C(166),
      {  INT64_C( 7339721822572200246), -INT64_C( 5002834115082153072), -INT64_C( 4976281027379160071),  INT64_C(  674270915916365692),
         INT64_C( 8376436800783775166), -INT64_C( 1782604192274672985), -INT64_C(  286475004574708090), -INT64_C( 3199612829106333509) },
      {  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   1),  INT64_C(                   0),
         INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C(169),
      {  INT64_C( 9191281612749909457),  INT64_C( 2794013352549750101), -INT64_C( 5794264547700895329), -INT64_C( 8192162356310825480),
         INT64_C( 3220358327539390789),  INT64_C( 1266974337251679767), -INT64_C( 2951401614739686589), -INT64_C( 6055986460698292312) },
      {  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
         INT64_C(                   0),  INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   1) } },
    { UINT8_C(102),
      { -INT64_C( 6016057524053090968), -INT64_C( 4499887099362741993), -INT64_C( 4518948867128891363),  INT64_C(  824391427888295671),
        -INT64_C( 5481734400260050767),  INT64_C( 6282672364244962024),  INT64_C( 4478057179382337649), -INT64_C( 3270327867845227025) },
      {  INT64_C(                   0),  INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
         INT64_C(                   0),  INT64_C(                   1),  INT64_C(                   1),  INT64_C(                   0) } },
    { UINT8_C(198),
      {  INT64_C(  644777795066663186),  INT64_C( 7038170266228384177), -INT64_C( 8952339986105495406),  INT64_C(  344937625601463532),
         INT64_C( 3642568225600752520), -INT64_C(  264840005960216479), -INT64_C( 3538824480710198486), -INT64_C( 8729106380776961818) },
      {  INT64_C(                   0),  INT64_C(                   2),  INT64_C(                   0),  INT64_C(                   0),
         INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   1),  INT64_C(                   0) } },
    { UINT8_C(114),
      {  INT64_C( 7587291699203214569), -INT64_C( 8274854614347333914), -INT64_C(  786373545756227170), -INT64_C( 5606846530574881425),
        -INT64_C( 2987600759763470458), -INT64_C( 3871689212103861210),  INT64_C( 6983694278584873865), -INT64_C( 2415624465891533058) },
      {  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
         INT64_C(                   3),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C(  3),
      { -INT64_C( 2079473871687057898), -INT64_C( 3199849179013719281),  INT64_C( 6332945602682588628),  INT64_C( 4133053367938165486),
         INT64_C(  429631926902963596), -INT64_C( 5464366217838721481),  INT64_C(  146503411915419449), -INT64_C( 3277698836076971994) },
      {  INT64_C(                   0),  INT64_C(                   4),  INT64_C(                   0),  INT64_C(                   0),
         INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0) } },  };

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
