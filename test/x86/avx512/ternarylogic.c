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
 *   2021      Kunwar Maheep Singh <kunwar.maheep@students.iiit.ac.in>
 *   2021      Christopher Moore <moore@free.fr>
 */

#define SIMDE_TEST_X86_AVX512_INSN ternarylogic

#include <test/x86/avx512/test-avx512.h>
#include <simde/x86/avx512/set.h>
#include <simde/x86/avx512/ternarylogic.h>
#include <simde/x86/avx512/setzero.h>

static int
test_simde_mm_ternarylogic_epi32_1 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t a[4];
    const int32_t b[4];
    const int32_t c[4];
    const int32_t imm8;
    const int32_t r[4];
  } test_vec[] = {
    { { -INT32_C(  1299740253),  INT32_C(  1717826566),  INT32_C(   505579753), -INT32_C(  1475656667) },
      {  INT32_C(  1793365650),  INT32_C(   511782472), -INT32_C(  1565786475), -INT32_C(  1294346737) },
      {  INT32_C(  1701142623),  INT32_C(  1036765268),  INT32_C(  1968959056), -INT32_C(  1004640718) },
       INT32_C(           0),
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { {  INT32_C(  1143866108), -INT32_C(   966545616), -INT32_C(  1117253970),  INT32_C(  1148142052) },
      { -INT32_C(   173419359), -INT32_C(   332237412), -INT32_C(  1788703133), -INT32_C(   245792524) },
      { -INT32_C(  1288337278), -INT32_C(   445016009), -INT32_C(  1952259673), -INT32_C(   993062365) },
       INT32_C(           1),
      {  INT32_C(   138420480),  INT32_C(   277086272),  INT32_C(  1075122192),  INT32_C(   167783432) } },
    { { -INT32_C(  2084931098),  INT32_C(  1366289646),  INT32_C(  1877397882), -INT32_C(   731889839) },
      { -INT32_C(     7891513), -INT32_C(   706478034),  INT32_C(    73435105),  INT32_C(  2143891609) },
      { -INT32_C(  1761442903), -INT32_C(   353865105), -INT32_C(  1789276605), -INT32_C(   714491635) },
       INT32_C(           2),
      {  INT32_C(         520),  INT32_C(   704647681), -INT32_C(  1877407744),  INT32_C(       32772) } },
    { {  INT32_C(  2094329934), -INT32_C(   783173392), -INT32_C(   657018305), -INT32_C(  1957126174) },
      { -INT32_C(  1860019678),  INT32_C(   276499148), -INT32_C(   442116904), -INT32_C(   591786355) },
      { -INT32_C(   296186114), -INT32_C(  2034259385),  INT32_C(  1046451548),  INT32_C(  1456060212) },
       INT32_C(           3),
      {  INT32_C(    34145681),  INT32_C(   780420355),  INT32_C(    34081024),  INT32_C(   537223184) } },
    { { -INT32_C(   555160815), -INT32_C(   840014859), -INT32_C(   978152648), -INT32_C(  1616810591) },
      {  INT32_C(  1116601083),  INT32_C(    13192356),  INT32_C(   373172450), -INT32_C(   261290017) },
      { -INT32_C(   405907982), -INT32_C(   256590664), -INT32_C(   256481713), -INT32_C(   812689453) },
       INT32_C(           4),
      {  INT32_C(       65544),  INT32_C(       65536),  INT32_C(    34080896),  INT32_C(   541065228) } },
    { { -INT32_C(   183428015),  INT32_C(  1274403433), -INT32_C(   513723646),  INT32_C(   752012858) },
      { -INT32_C(   602693597), -INT32_C(  1395865763),  INT32_C(    27099694),  INT32_C(   735063258) },
      { -INT32_C(  1306402231), -INT32_C(  1073932612), -INT32_C(  2069864886),  INT32_C(  1353806381) },
       INT32_C(           5),
      {  INT32_C(   147718566),  INT32_C(      139522),  INT32_C(   438206645), -INT32_C(  2096365120) } },
    { {  INT32_C(  1881981971), -INT32_C(  1172506228),  INT32_C(  1438366075),  INT32_C(   797019366) },
      {  INT32_C(   719430254),  INT32_C(    48881336),  INT32_C(  1770490428),  INT32_C(   263862524) },
      { -INT32_C(  2004883716),  INT32_C(  1531092191),  INT32_C(  1001455189), -INT32_C(   127258230) },
       INT32_C(           6),
      { -INT32_C(  2104360832),  INT32_C(  1101202019),  INT32_C(    33833984), -INT32_C(   800063216) } },
    { { -INT32_C(  1943909421),  INT32_C(  1720585257), -INT32_C(  1831922282),  INT32_C(  1252165965) },
      {  INT32_C(  1339171184),  INT32_C(   329913789), -INT32_C(  1655809261),  INT32_C(  1620425100) },
      {  INT32_C(   787265284),  INT32_C(  1502902979), -INT32_C(   571710576),  INT32_C(  1562873581) },
       INT32_C(           7),
      {  INT32_C(  1897763884), -INT32_C(  2005802154),  INT32_C(  1613801577), -INT32_C(  1252493774) } },
  };

  simde__m128i a, b, c, r;

  a = simde_x_mm_loadu_epi32(test_vec[0].a);
  b = simde_x_mm_loadu_epi32(test_vec[0].b);
  c = simde_x_mm_loadu_epi32(test_vec[0].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(           0));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[0].r));

  a = simde_x_mm_loadu_epi32(test_vec[1].a);
  b = simde_x_mm_loadu_epi32(test_vec[1].b);
  c = simde_x_mm_loadu_epi32(test_vec[1].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(           1));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[1].r));

  a = simde_x_mm_loadu_epi32(test_vec[2].a);
  b = simde_x_mm_loadu_epi32(test_vec[2].b);
  c = simde_x_mm_loadu_epi32(test_vec[2].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(           2));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[2].r));

  a = simde_x_mm_loadu_epi32(test_vec[3].a);
  b = simde_x_mm_loadu_epi32(test_vec[3].b);
  c = simde_x_mm_loadu_epi32(test_vec[3].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(           3));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[3].r));

  a = simde_x_mm_loadu_epi32(test_vec[4].a);
  b = simde_x_mm_loadu_epi32(test_vec[4].b);
  c = simde_x_mm_loadu_epi32(test_vec[4].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(           4));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[4].r));

  a = simde_x_mm_loadu_epi32(test_vec[5].a);
  b = simde_x_mm_loadu_epi32(test_vec[5].b);
  c = simde_x_mm_loadu_epi32(test_vec[5].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(           5));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[5].r));

  a = simde_x_mm_loadu_epi32(test_vec[6].a);
  b = simde_x_mm_loadu_epi32(test_vec[6].b);
  c = simde_x_mm_loadu_epi32(test_vec[6].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(           6));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[6].r));

  a = simde_x_mm_loadu_epi32(test_vec[7].a);
  b = simde_x_mm_loadu_epi32(test_vec[7].b);
  c = simde_x_mm_loadu_epi32(test_vec[7].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(           7));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[7].r));

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 32 ; i++) {
    simde__m128i a = simde_test_x86_random_i32x4();
    simde__m128i b = simde_test_x86_random_i32x4();
    simde__m128i c = simde_test_x86_random_i32x4();
    simde__m128i r;
    SIMDE_CONSTIFY_32_(simde_mm_ternarylogic_epi32, r, simde_mm_setzero_si128(), i, a, b, c);

    simde_test_x86_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, i, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_ternarylogic_epi32_2 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t a[4];
    const int32_t b[4];
    const int32_t c[4];
    const int32_t imm8;
    const int32_t r[4];
  } test_vec[] = {
    { {  INT32_C(  1840052911),  INT32_C(   578836239),  INT32_C(  1052757682), -INT32_C(  1935780729) },
      { -INT32_C(   809858549), -INT32_C(  1792520699), -INT32_C(  1636690767),  INT32_C(  1392220834) },
      { -INT32_C(  1547720556), -INT32_C(  1312473089), -INT32_C(  1779465203), -INT32_C(   484340008) },
       INT32_C(           8),
      { -INT32_C(  2112749568), -INT32_C(  1862268928), -INT32_C(  2143289343),  INT32_C(  1109494272) } },
    { {  INT32_C(   498260760), -INT32_C(   625812695), -INT32_C(  1837554193),  INT32_C(  1407481023) },
      {  INT32_C(   469148444), -INT32_C(   271795230),  INT32_C(   394574911),  INT32_C(  1660593482) },
      { -INT32_C(  1451184768),  INT32_C(  2005152392),  INT32_C(   369753431), -INT32_C(  1905660559) },
       INT32_C(           9),
      {  INT32_C(  1074339939),  INT32_C(   621094036),  INT32_C(  1812109840),  INT32_C(      557888) } },
    { {  INT32_C(  1923702672),  INT32_C(  1499624986),  INT32_C(  2087773746),  INT32_C(   215903116) },
      { -INT32_C(  1598661096), -INT32_C(   401130863), -INT32_C(  1459674825), -INT32_C(  1623824370) },
      { -INT32_C(   502144824), -INT32_C(  2009304234), -INT32_C(   435901350),  INT32_C(   804446743) },
       INT32_C(          10),
      { -INT32_C(  2146394040), -INT32_C(  2145648316), -INT32_C(  2113664952),  INT32_C(   589332499) } },
    { { -INT32_C(   758142911),  INT32_C(   431679458),  INT32_C(   381860104), -INT32_C(   357173214) },
      {  INT32_C(   785172440), -INT32_C(  1800009670), -INT32_C(   864372043), -INT32_C(   553882211) },
      { -INT32_C(   122631403), -INT32_C(  1173263694),  INT32_C(  1188156196), -INT32_C(  1540323636) },
       INT32_C(          11),
      {  INT32_C(   691032886), -INT32_C(   499050475),  INT32_C(  1628784230),  INT32_C(    84018892) } },
    { { -INT32_C(  1999373235), -INT32_C(  1172535035), -INT32_C(   511273148),  INT32_C(   431981060) },
      {  INT32_C(     1142606), -INT32_C(    38067239), -INT32_C(  1035760394),  INT32_C(  1617392402) },
      {  INT32_C(  1978153584),  INT32_C(   120521923), -INT32_C(  1612139109), -INT32_C(  2034653384) },
       INT32_C(          12),
      {  INT32_C(         770),  INT32_C(  1168319192),  INT32_C(    37816498),  INT32_C(  1614835986) } },
    { { -INT32_C(   259601898), -INT32_C(   454213139), -INT32_C(   525979187),  INT32_C(   339742116) },
      {  INT32_C(   193538119), -INT32_C(   938297300), -INT32_C(  1503134866), -INT32_C(  1188290398) },
      { -INT32_C(   659967253), -INT32_C(  1044605196),  INT32_C(  1822516167), -INT32_C(  1199513232) },
       INT32_C(          13),
      {  INT32_C(   257500481),  INT32_C(   437434370),  INT32_C(   391761458), -INT32_C(   348179957) } },
    { {  INT32_C(   918751753),  INT32_C(   822007234),  INT32_C(  1943430608),  INT32_C(  1898709638) },
      { -INT32_C(  1454778955),  INT32_C(   862586475), -INT32_C(   643888023), -INT32_C(   141484051) },
      { -INT32_C(   332573655), -INT32_C(    98817238),  INT32_C(   376304528), -INT32_C(  1433953803) },
       INT32_C(          14),
      { -INT32_C(   919808588), -INT32_C(   889181655), -INT32_C(  1943430615), -INT32_C(  1902928519) } },
    { { -INT32_C(   632041106),  INT32_C(  1074642647), -INT32_C(  1223054134), -INT32_C(   173102133) },
      {  INT32_C(   702667775), -INT32_C(  1759183610), -INT32_C(   424832528), -INT32_C(  1718602453) },
      { -INT32_C(   579607546),  INT32_C(  1813872802), -INT32_C(   131910100), -INT32_C(   504507679) },
       INT32_C(          15),
      {  INT32_C(   632041105), -INT32_C(  1074642648),  INT32_C(  1223054133),  INT32_C(   173102132) } },
  };

  simde__m128i a, b, c, r;

  a = simde_x_mm_loadu_epi32(test_vec[0].a);
  b = simde_x_mm_loadu_epi32(test_vec[0].b);
  c = simde_x_mm_loadu_epi32(test_vec[0].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(           8));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[0].r));

  a = simde_x_mm_loadu_epi32(test_vec[1].a);
  b = simde_x_mm_loadu_epi32(test_vec[1].b);
  c = simde_x_mm_loadu_epi32(test_vec[1].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(           9));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[1].r));

  a = simde_x_mm_loadu_epi32(test_vec[2].a);
  b = simde_x_mm_loadu_epi32(test_vec[2].b);
  c = simde_x_mm_loadu_epi32(test_vec[2].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(          10));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[2].r));

  a = simde_x_mm_loadu_epi32(test_vec[3].a);
  b = simde_x_mm_loadu_epi32(test_vec[3].b);
  c = simde_x_mm_loadu_epi32(test_vec[3].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(          11));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[3].r));

  a = simde_x_mm_loadu_epi32(test_vec[4].a);
  b = simde_x_mm_loadu_epi32(test_vec[4].b);
  c = simde_x_mm_loadu_epi32(test_vec[4].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(          12));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[4].r));

  a = simde_x_mm_loadu_epi32(test_vec[5].a);
  b = simde_x_mm_loadu_epi32(test_vec[5].b);
  c = simde_x_mm_loadu_epi32(test_vec[5].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(          13));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[5].r));

  a = simde_x_mm_loadu_epi32(test_vec[6].a);
  b = simde_x_mm_loadu_epi32(test_vec[6].b);
  c = simde_x_mm_loadu_epi32(test_vec[6].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(          14));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[6].r));

  a = simde_x_mm_loadu_epi32(test_vec[7].a);
  b = simde_x_mm_loadu_epi32(test_vec[7].b);
  c = simde_x_mm_loadu_epi32(test_vec[7].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(          15));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[7].r));

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 32 ; i++) {
    simde__m128i a = simde_test_x86_random_i32x4();
    simde__m128i b = simde_test_x86_random_i32x4();
    simde__m128i c = simde_test_x86_random_i32x4();
    simde__m128i r;
    SIMDE_CONSTIFY_32_(simde_mm_ternarylogic_epi32, r, simde_mm_setzero_si128(), i, a, b, c);

    simde_test_x86_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, i, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_ternarylogic_epi32_3 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t a[4];
    const int32_t b[4];
    const int32_t c[4];
    const int32_t imm8;
    const int32_t r[4];
  } test_vec[] = {
    { { -INT32_C(  1274360147), -INT32_C(  1135923509), -INT32_C(   341641024),  INT32_C(   864301613) },
      { -INT32_C(  1206847466), -INT32_C(  1524355720),  INT32_C(  1167935588), -INT32_C(   953775590) },
      {  INT32_C(   595276120),  INT32_C(   534759007), -INT32_C(   334855745), -INT32_C(   903835724) },
       INT32_C(          16),
      {  INT32_C(    67110561),  INT32_C(         128),  INT32_C(    35663872),  INT32_C(   813707265) } },
    { { -INT32_C(     8179577), -INT32_C(  1029396642),  INT32_C(   151470575),  INT32_C(   600911563) },
      { -INT32_C(  1102623649), -INT32_C(   757193197),  INT32_C(  1556015272), -INT32_C(    31007113) },
      {  INT32_C(  1845405967),  INT32_C(  1076863569), -INT32_C(  1354090780), -INT32_C(  1009575068) },
       INT32_C(          17),
      {  INT32_C(        4768),  INT32_C(   754997676),  INT32_C(       65811),  INT32_C(      532616) } },
    { {  INT32_C(  2055346791), -INT32_C(   397647808), -INT32_C(  1069282488), -INT32_C(   121738263) },
      {  INT32_C(  1701166100),  INT32_C(  1134990431),  INT32_C(   804450507),  INT32_C(  1928578315) },
      {  INT32_C(   552433119),  INT32_C(   487078357),  INT32_C(   786255172), -INT32_C(   869884744) },
       INT32_C(          18),
      {  INT32_C(   436880296), -INT32_C(  1270855296), -INT32_C(  1073150460),  INT32_C(    67646032) } },
    { { -INT32_C(  1221424040), -INT32_C(   335882208), -INT32_C(   753144376), -INT32_C(  1840968014) },
      {  INT32_C(  1488073347), -INT32_C(  1334461844), -INT32_C(  1075948793),  INT32_C(  1200358895) },
      { -INT32_C(  1308639599),  INT32_C(  1587411350), -INT32_C(  1724794650),  INT32_C(  1227585222) },
       INT32_C(          19),
      {  INT32_C(   105726316),  INT32_C(    84018579),  INT32_C(  1075840056), -INT32_C(  1200424944) } },
    { {  INT32_C(   362929577), -INT32_C(  1614473577),  INT32_C(  1482597481),  INT32_C(   983624361) },
      {  INT32_C(  1055629224),  INT32_C(  2140965016),  INT32_C(   102288704), -INT32_C(   313572540) },
      { -INT32_C(  1224544224),  INT32_C(  1884735239),  INT32_C(   348763499),  INT32_C(  1213098399) },
       INT32_C(          20),
      {  INT32_C(   138936833), -INT32_C(  2146887672),  INT32_C(  1241925632), -INT32_C(  1751023520) } },
    { { -INT32_C(  1601816056),  INT32_C(    52372418),  INT32_C(   873019376), -INT32_C(  1709090438) },
      {  INT32_C(  1347560265),  INT32_C(  1455532267), -INT32_C(    43283875), -INT32_C(    79316493) },
      { -INT32_C(  1231303693), -INT32_C(   541475858),  INT32_C(  1830011634),  INT32_C(  1694971163) },
       INT32_C(          21),
      {  INT32_C(  1231295492),  INT32_C(   541475857), -INT32_C(  2098971379),  INT32_C(    16302724) } },
    { {  INT32_C(  1135958360),  INT32_C(  1603958274), -INT32_C(   212073216), -INT32_C(  1292983874) },
      {  INT32_C(  1533577837),  INT32_C(   926556485), -INT32_C(     6009117), -INT32_C(   614159229) },
      {  INT32_C(   119478533), -INT32_C(  1872250480),  INT32_C(  2089075646), -INT32_C(   768707995) },
       INT32_C(          22),
      {  INT32_C(   482525744), -INT32_C(   389689641),  INT32_C(     7899229),  INT32_C(   696278872) } },
    { {  INT32_C(  1093506812), -INT32_C(  1686542153),  INT32_C(   966401462), -INT32_C(   820707639) },
      { -INT32_C(  1479134441), -INT32_C(  1439154708),  INT32_C(  1713880065),  INT32_C(   725112110) },
      { -INT32_C(  1553177108), -INT32_C(  2093029939), -INT32_C(   860039165), -INT32_C(   291778090) },
       INT32_C(          23),
      {  INT32_C(  1553188867),  INT32_C(  1959236114), -INT32_C(  1824431108),  INT32_C(   283585073) } },
  };

  simde__m128i a, b, c, r;

  a = simde_x_mm_loadu_epi32(test_vec[0].a);
  b = simde_x_mm_loadu_epi32(test_vec[0].b);
  c = simde_x_mm_loadu_epi32(test_vec[0].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(          16));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[0].r));

  a = simde_x_mm_loadu_epi32(test_vec[1].a);
  b = simde_x_mm_loadu_epi32(test_vec[1].b);
  c = simde_x_mm_loadu_epi32(test_vec[1].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(          17));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[1].r));

  a = simde_x_mm_loadu_epi32(test_vec[2].a);
  b = simde_x_mm_loadu_epi32(test_vec[2].b);
  c = simde_x_mm_loadu_epi32(test_vec[2].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(          18));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[2].r));

  a = simde_x_mm_loadu_epi32(test_vec[3].a);
  b = simde_x_mm_loadu_epi32(test_vec[3].b);
  c = simde_x_mm_loadu_epi32(test_vec[3].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(          19));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[3].r));

  a = simde_x_mm_loadu_epi32(test_vec[4].a);
  b = simde_x_mm_loadu_epi32(test_vec[4].b);
  c = simde_x_mm_loadu_epi32(test_vec[4].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(          20));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[4].r));

  a = simde_x_mm_loadu_epi32(test_vec[5].a);
  b = simde_x_mm_loadu_epi32(test_vec[5].b);
  c = simde_x_mm_loadu_epi32(test_vec[5].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(          21));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[5].r));

  a = simde_x_mm_loadu_epi32(test_vec[6].a);
  b = simde_x_mm_loadu_epi32(test_vec[6].b);
  c = simde_x_mm_loadu_epi32(test_vec[6].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(          22));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[6].r));

  a = simde_x_mm_loadu_epi32(test_vec[7].a);
  b = simde_x_mm_loadu_epi32(test_vec[7].b);
  c = simde_x_mm_loadu_epi32(test_vec[7].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(          23));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[7].r));

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 32 ; i++) {
    simde__m128i a = simde_test_x86_random_i32x4();
    simde__m128i b = simde_test_x86_random_i32x4();
    simde__m128i c = simde_test_x86_random_i32x4();
    simde__m128i r;
    SIMDE_CONSTIFY_32_(simde_mm_ternarylogic_epi32, r, simde_mm_setzero_si128(), i, a, b, c);

    simde_test_x86_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, i, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_ternarylogic_epi32_4 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t a[4];
    const int32_t b[4];
    const int32_t c[4];
    const int32_t imm8;
    const int32_t r[4];
  } test_vec[] = {
    { { -INT32_C(   241864188), -INT32_C(  1331966545), -INT32_C(  1206467959),  INT32_C(    82005528) },
      { -INT32_C(  2119741516),  INT32_C(   939910709), -INT32_C(  1794850370), -INT32_C(  1752981358) },
      { -INT32_C(  1048045550),  INT32_C(  1869751270), -INT32_C(    30963482), -INT32_C(  1962800425) },
       INT32_C(          24),
      {  INT32_C(   806365200), -INT32_C(  2004342264),  INT32_C(    68157991), -INT32_C(  2090842998) } },
    { { -INT32_C(  1894995622),  INT32_C(  1321669007),  INT32_C(  1709427667),  INT32_C(  2113693291) },
      {  INT32_C(  1681884286), -INT32_C(  1898663512),  INT32_C(   277674809),  INT32_C(  1620807174) },
      { -INT32_C(   940595145), -INT32_C(  1944734023), -INT32_C(   302843775), -INT32_C(   596971938) },
       INT32_C(          25),
      {  INT32_C(  1478710180), -INT32_C(   247797658),  INT32_C(    33633350),  INT32_C(    50764197) } },
    { {  INT32_C(   457288051), -INT32_C(  1800858278),  INT32_C(   379860240), -INT32_C(    92913469) },
      { -INT32_C(  1581160984), -INT32_C(  1657874917),  INT32_C(   747249870), -INT32_C(  2130054130) },
      { -INT32_C(   123975010),  INT32_C(  1871463775),  INT32_C(  1032204666),  INT32_C(  1496906865) },
       INT32_C(          26),
      { -INT32_C(   493043059),  INT32_C(  1795506181),  INT32_C(   723649642),  INT32_C(   592362672) } },
    { {  INT32_C(  2113599842), -INT32_C(  1642452784),  INT32_C(  1472963656),  INT32_C(   936957081) },
      {  INT32_C(  2100262174),  INT32_C(   904707258),  INT32_C(  1584558829), -INT32_C(   776492433) },
      {  INT32_C(  1951314340),  INT32_C(   571632090), -INT32_C(  1501962995), -INT32_C(   807578959) },
       INT32_C(          27),
      { -INT32_C(  2104227131), -INT32_C(   402570481), -INT32_C(  1582016233), -INT32_C(   402323680) } },
    { { -INT32_C(  2125722169), -INT32_C(  1229571639),  INT32_C(   437529003),  INT32_C(  2011941843) },
      {  INT32_C(  1458256508), -INT32_C(  1334182237), -INT32_C(  1923616037),  INT32_C(   190592068) },
      {  INT32_C(   177056065), -INT32_C(  1916779550),  INT32_C(  1084806252),  INT32_C(   481792927) },
       INT32_C(          28),
      { -INT32_C(   677169478),  INT32_C(    38782506), -INT32_C(  1757160624),  INT32_C(  1746172932) } },
    { {  INT32_C(  1886561229),  INT32_C(  2082597793),  INT32_C(   571046110), -INT32_C(   298948948) },
      { -INT32_C(   235357425),  INT32_C(  1803467262),  INT32_C(   766191245), -INT32_C(  2025233734) },
      { -INT32_C(  1493648635), -INT32_C(  2061297241),  INT32_C(  1034366097), -INT32_C(  1590962798) },
       INT32_C(          29),
      { -INT32_C(  1987093262),  INT32_C(   333338206), -INT32_C(   806168733),  INT32_C(  1507133527) } },
    { { -INT32_C(  1886247792),  INT32_C(  1794773469), -INT32_C(   241720009),  INT32_C(   226091015) },
      {  INT32_C(  1135833500),  INT32_C(   466146954), -INT32_C(  1789366525), -INT32_C(   717781947) },
      { -INT32_C(  2056992344),  INT32_C(   317677274),  INT32_C(   184780547),  INT32_C(    51936359) },
       INT32_C(          30),
      {  INT32_C(  1214635308),  INT32_C(  1897254663),  INT32_C(  1858882100), -INT32_C(   632939424) } },
    { {  INT32_C(  2001128429), -INT32_C(  1517154654), -INT32_C(  1019548802),  INT32_C(   395866479) },
      {  INT32_C(   362609979),  INT32_C(  1596427099),  INT32_C(  2053778194), -INT32_C(  1786936665) },
      { -INT32_C(   284375987),  INT32_C(  1351917522), -INT32_C(   116142198),  INT32_C(  2064690240) },
       INT32_C(          31),
      { -INT32_C(  1996802414), -INT32_C(    93458051),  INT32_C(  1019548901), -INT32_C(   387457128) } },
  };

  simde__m128i a, b, c, r;

  a = simde_x_mm_loadu_epi32(test_vec[0].a);
  b = simde_x_mm_loadu_epi32(test_vec[0].b);
  c = simde_x_mm_loadu_epi32(test_vec[0].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(          24));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[0].r));

  a = simde_x_mm_loadu_epi32(test_vec[1].a);
  b = simde_x_mm_loadu_epi32(test_vec[1].b);
  c = simde_x_mm_loadu_epi32(test_vec[1].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(          25));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[1].r));

  a = simde_x_mm_loadu_epi32(test_vec[2].a);
  b = simde_x_mm_loadu_epi32(test_vec[2].b);
  c = simde_x_mm_loadu_epi32(test_vec[2].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(          26));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[2].r));

  a = simde_x_mm_loadu_epi32(test_vec[3].a);
  b = simde_x_mm_loadu_epi32(test_vec[3].b);
  c = simde_x_mm_loadu_epi32(test_vec[3].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(          27));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[3].r));

  a = simde_x_mm_loadu_epi32(test_vec[4].a);
  b = simde_x_mm_loadu_epi32(test_vec[4].b);
  c = simde_x_mm_loadu_epi32(test_vec[4].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(          28));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[4].r));

  a = simde_x_mm_loadu_epi32(test_vec[5].a);
  b = simde_x_mm_loadu_epi32(test_vec[5].b);
  c = simde_x_mm_loadu_epi32(test_vec[5].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(          29));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[5].r));

  a = simde_x_mm_loadu_epi32(test_vec[6].a);
  b = simde_x_mm_loadu_epi32(test_vec[6].b);
  c = simde_x_mm_loadu_epi32(test_vec[6].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(          30));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[6].r));

  a = simde_x_mm_loadu_epi32(test_vec[7].a);
  b = simde_x_mm_loadu_epi32(test_vec[7].b);
  c = simde_x_mm_loadu_epi32(test_vec[7].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(          31));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[7].r));

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 32 ; i++) {
    simde__m128i a = simde_test_x86_random_i32x4();
    simde__m128i b = simde_test_x86_random_i32x4();
    simde__m128i c = simde_test_x86_random_i32x4();
    simde__m128i r;
    SIMDE_CONSTIFY_32_(simde_mm_ternarylogic_epi32, r, simde_mm_setzero_si128(), i, a, b, c);

    simde_test_x86_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, i, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_ternarylogic_epi32_5 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t a[4];
    const int32_t b[4];
    const int32_t c[4];
    const int32_t imm8;
    const int32_t r[4];
  } test_vec[] = {
    { {  INT32_C(  1012020612), -INT32_C(  2059365601), -INT32_C(  1433117876),  INT32_C(  2048428691) },
      { -INT32_C(  1944738913),  INT32_C(     8137278),  INT32_C(  1100919444), -INT32_C(   976915135) },
      { -INT32_C(   905898069), -INT32_C(   162578006),  INT32_C(   799073180),  INT32_C(   212449389) },
       INT32_C(          32),
      {  INT32_C(        5120), -INT32_C(  2080374528),  INT32_C(   704659720),  INT32_C(   134776832) } },
    { { -INT32_C(  1701265828),  INT32_C(  2107315433),  INT32_C(   129907142),  INT32_C(  1506575278) },
      {  INT32_C(  1159974298), -INT32_C(  1422167538), -INT32_C(  1009066923), -INT32_C(   254835564) },
      {  INT32_C(   730556482),  INT32_C(  1135158908),  INT32_C(   222979935), -INT32_C(  2056841237) },
       INT32_C(          33),
      {  INT32_C(   181149793),  INT32_C(  1086623072),  INT32_C(   872489250),  INT32_C(    51407658) } },
    { { -INT32_C(   204829980),  INT32_C(  1386088189),  INT32_C(  1981118690),  INT32_C(  1063773692) },
      { -INT32_C(   915738035),  INT32_C(  1997280024),  INT32_C(  1719949179),  INT32_C(  1391192942) },
      {  INT32_C(  1933948534), -INT32_C(  1631198276),  INT32_C(  1477761884),  INT32_C(   228031424) },
       INT32_C(          34),
      {  INT32_C(   839189554), -INT32_C(  2000559964),  INT32_C(   403736580),  INT32_C(   219418752) } },
    { { -INT32_C(  2049572243), -INT32_C(  1862474987), -INT32_C(  1460240070), -INT32_C(   486874516) },
      {  INT32_C(  1414873240),  INT32_C(  2146573091), -INT32_C(  1227356426), -INT32_C(   272404606) },
      { -INT32_C(  2022336143), -INT32_C(  1239977604),  INT32_C(  1599999730), -INT32_C(  2008983056) },
       INT32_C(          35),
      { -INT32_C(  1423393437), -INT32_C(  2147130148),  INT32_C(  1225226241),  INT32_C(   268701809) } },
    { { -INT32_C(  1126393959), -INT32_C(  1472409934),  INT32_C(  1449006292), -INT32_C(   179953277) },
      {  INT32_C(   930921402),  INT32_C(   535663404), -INT32_C(  1853993823),  INT32_C(  1041874853) },
      {  INT32_C(   150664534), -INT32_C(  1733282109), -INT32_C(   823259574), -INT32_C(   356305873) },
       INT32_C(          36),
      {  INT32_C(   192941088), -INT32_C(  2024733298),  INT32_C(  1191198817), -INT32_C(  1067808254) } },
    { {  INT32_C(   471941103),  INT32_C(  1950027474), -INT32_C(    16402086), -INT32_C(   818077832) },
      { -INT32_C(   656984044), -INT32_C(  1183807378), -INT32_C(   964206954), -INT32_C(  2102375789) },
      {  INT32_C(  1537134985),  INT32_C(   986700255),  INT32_C(   188339602),  INT32_C(   148535284) },
       INT32_C(          37),
      { -INT32_C(  1606418023), -INT32_C(  2129977168),  INT32_C(   163742501),  INT32_C(   940086627) } },
    { {  INT32_C(   501264815), -INT32_C(   791261127),  INT32_C(  1117150639),  INT32_C(   818169511) },
      { -INT32_C(   158571753), -INT32_C(   818914500),  INT32_C(   618293808), -INT32_C(  1876052767) },
      { -INT32_C(  1616048795),  INT32_C(   225412190), -INT32_C(  1991309855),  INT32_C(  1656296267) },
       INT32_C(          38),
      {  INT32_C(  1763790448),  INT32_C(    38768450), -INT32_C(  1392171055), -INT32_C(   493837558) } },
    { { -INT32_C(  1286060682), -INT32_C(   779974239), -INT32_C(   722051853),  INT32_C(  1969496848) },
      { -INT32_C(  1911287504),  INT32_C(  2006680469), -INT32_C(   754914680),  INT32_C(  1949678078) },
      { -INT32_C(  1608020225),  INT32_C(   175221015),  INT32_C(   366896901), -INT32_C(  1148501366) },
       INT32_C(          39),
      {  INT32_C(  1822670543),  INT32_C(   745307722),  INT32_C(   786400525), -INT32_C(  1952784795) } },
  };

  simde__m128i a, b, c, r;

  a = simde_x_mm_loadu_epi32(test_vec[0].a);
  b = simde_x_mm_loadu_epi32(test_vec[0].b);
  c = simde_x_mm_loadu_epi32(test_vec[0].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(          32));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[0].r));

  a = simde_x_mm_loadu_epi32(test_vec[1].a);
  b = simde_x_mm_loadu_epi32(test_vec[1].b);
  c = simde_x_mm_loadu_epi32(test_vec[1].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(          33));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[1].r));

  a = simde_x_mm_loadu_epi32(test_vec[2].a);
  b = simde_x_mm_loadu_epi32(test_vec[2].b);
  c = simde_x_mm_loadu_epi32(test_vec[2].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(          34));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[2].r));

  a = simde_x_mm_loadu_epi32(test_vec[3].a);
  b = simde_x_mm_loadu_epi32(test_vec[3].b);
  c = simde_x_mm_loadu_epi32(test_vec[3].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(          35));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[3].r));

  a = simde_x_mm_loadu_epi32(test_vec[4].a);
  b = simde_x_mm_loadu_epi32(test_vec[4].b);
  c = simde_x_mm_loadu_epi32(test_vec[4].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(          36));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[4].r));

  a = simde_x_mm_loadu_epi32(test_vec[5].a);
  b = simde_x_mm_loadu_epi32(test_vec[5].b);
  c = simde_x_mm_loadu_epi32(test_vec[5].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(          37));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[5].r));

  a = simde_x_mm_loadu_epi32(test_vec[6].a);
  b = simde_x_mm_loadu_epi32(test_vec[6].b);
  c = simde_x_mm_loadu_epi32(test_vec[6].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(          38));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[6].r));

  a = simde_x_mm_loadu_epi32(test_vec[7].a);
  b = simde_x_mm_loadu_epi32(test_vec[7].b);
  c = simde_x_mm_loadu_epi32(test_vec[7].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(          39));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[7].r));

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 32 ; i < 64 ; i++) {
    simde__m128i a = simde_test_x86_random_i32x4();
    simde__m128i b = simde_test_x86_random_i32x4();
    simde__m128i c = simde_test_x86_random_i32x4();
    simde__m128i r;
    SIMDE_CONSTIFY_32_2(simde_mm_ternarylogic_epi32, r, simde_mm_setzero_si128(), i, a, b, c);

    simde_test_x86_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, i, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_ternarylogic_epi32_6 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t a[4];
    const int32_t b[4];
    const int32_t c[4];
    const int32_t imm8;
    const int32_t r[4];
  } test_vec[] = {
    { { -INT32_C(   381051053), -INT32_C(  1419713245), -INT32_C(   847290161),  INT32_C(   407024665) },
      {  INT32_C(  1505257794),  INT32_C(   409152019),  INT32_C(   472793489), -INT32_C(   673728125) },
      {  INT32_C(  2076188760), -INT32_C(   718856187), -INT32_C(  1717393792), -INT32_C(  1649220518) },
       INT32_C(          40),
      {  INT32_C(   817897488), -INT32_C(  1862074368), -INT32_C(  1862262784), -INT32_C(  1919941606) } },
    { {  INT32_C(  1643539022),  INT32_C(   645487252),  INT32_C(   524461979), -INT32_C(  1175053984) },
      {  INT32_C(  1060419129),  INT32_C(  1444174806),  INT32_C(  1559213569), -INT32_C(   369516133) },
      { -INT32_C(  1605701876), -INT32_C(   439958711), -INT32_C(   888928149),  INT32_C(  1535441441) },
       INT32_C(          41),
      {  INT32_C(     4443268),  INT32_C(  1749296480),  INT32_C(  1662271502),  INT32_C(  1409596453) } },
    { { -INT32_C(  2036680272),  INT32_C(   383561236), -INT32_C(     9254044),  INT32_C(  2045274989) },
      { -INT32_C(  1541852582),  INT32_C(  1636425974),  INT32_C(   170692072),  INT32_C(   929411463) },
      {  INT32_C(  2126380906),  INT32_C(   294951341), -INT32_C(   787413404), -INT32_C(   867501711) },
       INT32_C(          42),
      {  INT32_C(  2057686890),  INT32_C(   286529961), -INT32_C(   787413500), -INT32_C(   871704464) } },
    { {  INT32_C(   577791020),  INT32_C(   746846532),  INT32_C(   221687686), -INT32_C(   901473440) },
      {  INT32_C(  1195966874), -INT32_C(    27664998),  INT32_C(  1439722212), -INT32_C(  1893655965) },
      { -INT32_C(  1028550274),  INT32_C(   284112010),  INT32_C(  1142760932),  INT32_C(  1527734721) },
       INT32_C(          43),
      { -INT32_C(   659055753),  INT32_C(   300820139), -INT32_C(   502459015),  INT32_C(  1906271645) } },
    { { -INT32_C(    56403870),  INT32_C(   435944501), -INT32_C(   915420314),  INT32_C(  1683591397) },
      { -INT32_C(  1406793182),  INT32_C(   599594303), -INT32_C(    60302789), -INT32_C(  1638435268) },
      {  INT32_C(    77331150),  INT32_C(  1545443062),  INT32_C(  1176931425),  INT32_C(  1068138269) },
       INT32_C(          44),
      {  INT32_C(     8737344),  INT32_C(   973373706),  INT32_C(   872419417), -INT32_C(  1173461479) } },
    { { -INT32_C(   924069495),  INT32_C(   569092326), -INT32_C(  1088597117), -INT32_C(  1738705463) },
      {  INT32_C(  1721563247), -INT32_C(   272451186),  INT32_C(  1664542790), -INT32_C(   240983961) },
      { -INT32_C(  1732670031), -INT32_C(  1179015882), -INT32_C(  1049045000), -INT32_C(  1151740596) },
       INT32_C(          45),
      { -INT32_C(  1355469850), -INT32_C(   835890391), -INT32_C(  1062552636),  INT32_C(  1845206846) } },
    { {  INT32_C(  1545729486), -INT32_C(   179510097),  INT32_C(   878215884),  INT32_C(   338033250) },
      { -INT32_C(  1112744313),  INT32_C(  2071356803), -INT32_C(  2009207236), -INT32_C(  1840998716) },
      {  INT32_C(  1005479308),  INT32_C(   372259401),  INT32_C(   524978364),  INT32_C(   154365826) },
       INT32_C(          46),
      { -INT32_C(  1546769655),  INT32_C(   238164808), -INT32_C(  1620611920), -INT32_C(  1955369594) } },
    { { -INT32_C(   775430323), -INT32_C(  2125710012), -INT32_C(   267810516), -INT32_C(  1400746720) },
      { -INT32_C(    51941197),  INT32_C(  1729238955),  INT32_C(   562453663),  INT32_C(   422230475) },
      { -INT32_C(   571805288),  INT32_C(  1532900911), -INT32_C(   531929152),  INT32_C(  1754058165) },
       INT32_C(          47),
      {  INT32_C(   792240570),  INT32_C(  2130698943), -INT32_C(   805341229),  INT32_C(  1946023679) } },
  };

  simde__m128i a, b, c, r;

  a = simde_x_mm_loadu_epi32(test_vec[0].a);
  b = simde_x_mm_loadu_epi32(test_vec[0].b);
  c = simde_x_mm_loadu_epi32(test_vec[0].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(          40));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[0].r));

  a = simde_x_mm_loadu_epi32(test_vec[1].a);
  b = simde_x_mm_loadu_epi32(test_vec[1].b);
  c = simde_x_mm_loadu_epi32(test_vec[1].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(          41));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[1].r));

  a = simde_x_mm_loadu_epi32(test_vec[2].a);
  b = simde_x_mm_loadu_epi32(test_vec[2].b);
  c = simde_x_mm_loadu_epi32(test_vec[2].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(          42));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[2].r));

  a = simde_x_mm_loadu_epi32(test_vec[3].a);
  b = simde_x_mm_loadu_epi32(test_vec[3].b);
  c = simde_x_mm_loadu_epi32(test_vec[3].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(          43));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[3].r));

  a = simde_x_mm_loadu_epi32(test_vec[4].a);
  b = simde_x_mm_loadu_epi32(test_vec[4].b);
  c = simde_x_mm_loadu_epi32(test_vec[4].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(          44));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[4].r));

  a = simde_x_mm_loadu_epi32(test_vec[5].a);
  b = simde_x_mm_loadu_epi32(test_vec[5].b);
  c = simde_x_mm_loadu_epi32(test_vec[5].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(          45));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[5].r));

  a = simde_x_mm_loadu_epi32(test_vec[6].a);
  b = simde_x_mm_loadu_epi32(test_vec[6].b);
  c = simde_x_mm_loadu_epi32(test_vec[6].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(          46));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[6].r));

  a = simde_x_mm_loadu_epi32(test_vec[7].a);
  b = simde_x_mm_loadu_epi32(test_vec[7].b);
  c = simde_x_mm_loadu_epi32(test_vec[7].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(          47));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[7].r));

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 32 ; i < 64 ; i++) {
    simde__m128i a = simde_test_x86_random_i32x4();
    simde__m128i b = simde_test_x86_random_i32x4();
    simde__m128i c = simde_test_x86_random_i32x4();
    simde__m128i r;
    SIMDE_CONSTIFY_32_2(simde_mm_ternarylogic_epi32, r, simde_mm_setzero_si128(), i, a, b, c);

    simde_test_x86_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, i, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_ternarylogic_epi32_7 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t a[4];
    const int32_t b[4];
    const int32_t c[4];
    const int32_t imm8;
    const int32_t r[4];
  } test_vec[] = {
    { { -INT32_C(   396070083),  INT32_C(   693139338), -INT32_C(  1622485293),  INT32_C(   683177104) },
      { -INT32_C(  1794792858), -INT32_C(  1729076264), -INT32_C(  2139604021),  INT32_C(  1172833288) },
      {  INT32_C(    19811447), -INT32_C(  1758822717), -INT32_C(   466193324),  INT32_C(  1326313193) },
       INT32_C(          48),
      {  INT32_C(  1751142681),  INT32_C(   553653250),  INT32_C(   520274960),  INT32_C(   672166032) } },
    { {  INT32_C(  1759777424),  INT32_C(  1090638966),  INT32_C(   398555407), -INT32_C(   178476674) },
      { -INT32_C(  1174959371),  INT32_C(  1565532424),  INT32_C(  2135000726),  INT32_C(    80629364) },
      { -INT32_C(   680742303), -INT32_C(  1793561210),  INT32_C(  1705826791),  INT32_C(  2002389122) },
       INT32_C(          49),
      {  INT32_C(  1073763594),  INT32_C(   581424759), -INT32_C(  2137884407), -INT32_C(   114183925) } },
    { { -INT32_C(  1691332205),  INT32_C(   167280755),  INT32_C(  2055748102), -INT32_C(   377596280) },
      { -INT32_C(  1899959544),  INT32_C(  1059313752),  INT32_C(   866439089),  INT32_C(  1789657047) },
      { -INT32_C(  1022960816),  INT32_C(  1657601628), -INT32_C(  1042459592), -INT32_C(  1297458262) },
       INT32_C(          50),
      {  INT32_C(  1362497747),  INT32_C(  1088169511), -INT32_C(   933679090), -INT32_C(  1856765912) } },
    { { -INT32_C(  1623168186), -INT32_C(   169974973),  INT32_C(   170427186), -INT32_C(   764095614) },
      {  INT32_C(   194411183), -INT32_C(  1318231431),  INT32_C(  1634880183), -INT32_C(   334226010) },
      { -INT32_C(   880061304), -INT32_C(   356488520),  INT32_C(  1878321645),  INT32_C(  1799449020) },
       INT32_C(          51),
      { -INT32_C(   194411184),  INT32_C(  1318231430), -INT32_C(  1634880184),  INT32_C(   334226009) } },
    { {  INT32_C(  1551292387), -INT32_C(   250682310), -INT32_C(   732790738),  INT32_C(   633431709) },
      {  INT32_C(  1945193659), -INT32_C(  1554140746),  INT32_C(  1460818586), -INT32_C(  1631431493) },
      {  INT32_C(  1710962987),  INT32_C(  1263929629),  INT32_C(   656451977), -INT32_C(   900931313) },
       INT32_C(          52),
      {  INT32_C(   235311952),  INT32_C(  1342395528), -INT32_C(  2143235532),  INT32_C(   822293028) } },
    { { -INT32_C(   465748691), -INT32_C(  1987601425), -INT32_C(  1461675283),  INT32_C(   424059886) },
      { -INT32_C(   109100580), -INT32_C(   733686454), -INT32_C(  1896127362),  INT32_C(  1935165253) },
      {  INT32_C(  1951897221),  INT32_C(   519953969),  INT32_C(  1724309112),  INT32_C(  1568672897) },
       INT32_C(          53),
      {  INT32_C(   260078707),  INT32_C(  1770203813),  INT32_C(   823769987), -INT32_C(  1438650182) } },
    { { -INT32_C(  1739129010),  INT32_C(  1399626452),  INT32_C(  1155622911),  INT32_C(   884423087) },
      {  INT32_C(    11013839),  INT32_C(  1696507373),  INT32_C(    80536707),  INT32_C(  1063341297) },
      {  INT32_C(   534230859),  INT32_C(  1366443090),  INT32_C(  1519735723),  INT32_C(  1552829837) },
       INT32_C(          54),
      { -INT32_C(  1619005056),  INT32_C(   912292667),  INT32_C(  1513722748),  INT32_C(  1138635102) } },
    { {  INT32_C(  1214068315),  INT32_C(  1605270492),  INT32_C(  1365539424),  INT32_C(   294700486) },
      { -INT32_C(   818911363),  INT32_C(  1461756843), -INT32_C(  2085505546),  INT32_C(  1591754754) },
      {  INT32_C(  1386626422),  INT32_C(   414340280), -INT32_C(  1805052210),  INT32_C(  1487272411) },
       INT32_C(          55),
      { -INT32_C(  1244669822), -INT32_C(  1461724073),  INT32_C(  2128530201), -INT32_C(  1486897155) } },
  };

  simde__m128i a, b, c, r;

  a = simde_x_mm_loadu_epi32(test_vec[0].a);
  b = simde_x_mm_loadu_epi32(test_vec[0].b);
  c = simde_x_mm_loadu_epi32(test_vec[0].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(          48));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[0].r));

  a = simde_x_mm_loadu_epi32(test_vec[1].a);
  b = simde_x_mm_loadu_epi32(test_vec[1].b);
  c = simde_x_mm_loadu_epi32(test_vec[1].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(          49));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[1].r));

  a = simde_x_mm_loadu_epi32(test_vec[2].a);
  b = simde_x_mm_loadu_epi32(test_vec[2].b);
  c = simde_x_mm_loadu_epi32(test_vec[2].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(          50));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[2].r));

  a = simde_x_mm_loadu_epi32(test_vec[3].a);
  b = simde_x_mm_loadu_epi32(test_vec[3].b);
  c = simde_x_mm_loadu_epi32(test_vec[3].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(          51));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[3].r));

  a = simde_x_mm_loadu_epi32(test_vec[4].a);
  b = simde_x_mm_loadu_epi32(test_vec[4].b);
  c = simde_x_mm_loadu_epi32(test_vec[4].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(          52));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[4].r));

  a = simde_x_mm_loadu_epi32(test_vec[5].a);
  b = simde_x_mm_loadu_epi32(test_vec[5].b);
  c = simde_x_mm_loadu_epi32(test_vec[5].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(          53));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[5].r));

  a = simde_x_mm_loadu_epi32(test_vec[6].a);
  b = simde_x_mm_loadu_epi32(test_vec[6].b);
  c = simde_x_mm_loadu_epi32(test_vec[6].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(          54));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[6].r));

  a = simde_x_mm_loadu_epi32(test_vec[7].a);
  b = simde_x_mm_loadu_epi32(test_vec[7].b);
  c = simde_x_mm_loadu_epi32(test_vec[7].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(          55));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[7].r));

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 32 ; i < 64 ; i++) {
    simde__m128i a = simde_test_x86_random_i32x4();
    simde__m128i b = simde_test_x86_random_i32x4();
    simde__m128i c = simde_test_x86_random_i32x4();
    simde__m128i r;
    SIMDE_CONSTIFY_32_2(simde_mm_ternarylogic_epi32, r, simde_mm_setzero_si128(), i, a, b, c);

    simde_test_x86_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, i, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_ternarylogic_epi32_8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t a[4];
    const int32_t b[4];
    const int32_t c[4];
    const int32_t imm8;
    const int32_t r[4];
  } test_vec[] = {
    { {  INT32_C(   203937377),  INT32_C(  1868777337), -INT32_C(      846339), -INT32_C(   883043499) },
      { -INT32_C(   937556976),  INT32_C(   669110360), -INT32_C(  1044690202), -INT32_C(  1524997820) },
      { -INT32_C(  1330560713), -INT32_C(  2044783223),  INT32_C(  2139427370), -INT32_C(   179641371) },
       INT32_C(          56),
      { -INT32_C(  2077109647),  INT32_C(  1208096545),  INT32_C(  1044387611),  INT32_C(  1850192401) } },
    { {  INT32_C(  1069443303),  INT32_C(   510041912),  INT32_C(   769663721), -INT32_C(  1160578429) },
      { -INT32_C(   999652293), -INT32_C(  1018525287), -INT32_C(  2126327652), -INT32_C(  1703441229) },
      {  INT32_C(   769209845), -INT32_C(  1119076140), -INT32_C(   437572510),  INT32_C(  1637858598) },
       INT32_C(          57),
      {  INT32_C(  1003777748), -INT32_C(  1648544094), -INT32_C(  1095359647),  INT32_C(   612726376) } },
    { { -INT32_C(   635041471),  INT32_C(   782069906), -INT32_C(   206512320),  INT32_C(  1636640620) },
      {  INT32_C(   814638940),  INT32_C(   166582951),  INT32_C(   753850374), -INT32_C(   678523498) },
      {  INT32_C(   682800278),  INT32_C(  1700220708), -INT32_C(  1688729809), -INT32_C(  1963137490) },
       INT32_C(          58),
      { -INT32_C(   357516137),  INT32_C(  1733439284), -INT32_C(   614987921), -INT32_C(  1435377046) } },
    { { -INT32_C(   189101491),  INT32_C(  1811785573),  INT32_C(   379120512),  INT32_C(   250422904) },
      { -INT32_C(    29974566),  INT32_C(   509840879), -INT32_C(  1028014956), -INT32_C(   280185438) },
      { -INT32_C(  1528625601),  INT32_C(   772858030),  INT32_C(  1128573131), -INT32_C(  1471073842) },
       INT32_C(          59),
      {  INT32_C(    29975607), -INT32_C(   442731878),  INT32_C(  2101756779), -INT32_C(  1330422817) } },
    { { -INT32_C(  1062828079), -INT32_C(  1445066219),  INT32_C(  1751947206), -INT32_C(  1957185460) },
      {  INT32_C(  1831877311), -INT32_C(   442810342), -INT32_C(  1238835224), -INT32_C(   513902320) },
      {  INT32_C(   362873856), -INT32_C(   725647602),  INT32_C(  1648110358), -INT32_C(  1561422877) },
       INT32_C(          60),
      { -INT32_C(  1382630034),  INT32_C(  1279609359), -INT32_C(   565950418),  INT32_C(  1779024220) } },
    { { -INT32_C(   418439475),  INT32_C(  1187818078), -INT32_C(  1694698359),  INT32_C(  1853577837) },
      {  INT32_C(  1837309278), -INT32_C(  1287568740),  INT32_C(  1360363117), -INT32_C(   537722095) },
      {  INT32_C(  2143683361),  INT32_C(   935695277), -INT32_C(   170802809),  INT32_C(  2053327899) },
       INT32_C(          61),
      { -INT32_C(  1967332461), -INT32_C(    37753662), -INT32_C(   873755916), -INT32_C(  1316161028) } },
    { {  INT32_C(   115861097), -INT32_C(  1766250455), -INT32_C(  1192767834), -INT32_C(   208151598) },
      { -INT32_C(  1955373602),  INT32_C(  2025994480),  INT32_C(   359502842),  INT32_C(  1234161888) },
      { -INT32_C(   548440394),  INT32_C(  1165363359), -INT32_C(  1443013161),  INT32_C(   379360312) },
       INT32_C(          62),
      { -INT32_C(   576930889), -INT32_C(   276885281), -INT32_C(  1382392483), -INT32_C(  1105719494) } },
    { { -INT32_C(   492695566),  INT32_C(  1113220168), -INT32_C(   665335816),  INT32_C(  1310844823) },
      { -INT32_C(    64130723),  INT32_C(  1346544505),  INT32_C(   972635905), -INT32_C(   967797036) },
      { -INT32_C(   307694939),  INT32_C(  1311703894),  INT32_C(  1646692298), -INT32_C(   877639570) },
       INT32_C(          63),
      {  INT32_C(   534773423), -INT32_C(  1078075465), -INT32_C(   407963393), -INT32_C(  1174439573) } },
  };

  simde__m128i a, b, c, r;

  a = simde_x_mm_loadu_epi32(test_vec[0].a);
  b = simde_x_mm_loadu_epi32(test_vec[0].b);
  c = simde_x_mm_loadu_epi32(test_vec[0].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(          56));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[0].r));

  a = simde_x_mm_loadu_epi32(test_vec[1].a);
  b = simde_x_mm_loadu_epi32(test_vec[1].b);
  c = simde_x_mm_loadu_epi32(test_vec[1].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(          57));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[1].r));

  a = simde_x_mm_loadu_epi32(test_vec[2].a);
  b = simde_x_mm_loadu_epi32(test_vec[2].b);
  c = simde_x_mm_loadu_epi32(test_vec[2].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(          58));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[2].r));

  a = simde_x_mm_loadu_epi32(test_vec[3].a);
  b = simde_x_mm_loadu_epi32(test_vec[3].b);
  c = simde_x_mm_loadu_epi32(test_vec[3].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(          59));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[3].r));

  a = simde_x_mm_loadu_epi32(test_vec[4].a);
  b = simde_x_mm_loadu_epi32(test_vec[4].b);
  c = simde_x_mm_loadu_epi32(test_vec[4].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(          60));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[4].r));

  a = simde_x_mm_loadu_epi32(test_vec[5].a);
  b = simde_x_mm_loadu_epi32(test_vec[5].b);
  c = simde_x_mm_loadu_epi32(test_vec[5].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(          61));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[5].r));

  a = simde_x_mm_loadu_epi32(test_vec[6].a);
  b = simde_x_mm_loadu_epi32(test_vec[6].b);
  c = simde_x_mm_loadu_epi32(test_vec[6].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(          62));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[6].r));

  a = simde_x_mm_loadu_epi32(test_vec[7].a);
  b = simde_x_mm_loadu_epi32(test_vec[7].b);
  c = simde_x_mm_loadu_epi32(test_vec[7].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(          63));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[7].r));

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 32 ; i < 64 ; i++) {
    simde__m128i a = simde_test_x86_random_i32x4();
    simde__m128i b = simde_test_x86_random_i32x4();
    simde__m128i c = simde_test_x86_random_i32x4();
    simde__m128i r;
    SIMDE_CONSTIFY_32_2(simde_mm_ternarylogic_epi32, r, simde_mm_setzero_si128(), i, a, b, c);

    simde_test_x86_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, i, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_ternarylogic_epi32_9 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t a[4];
    const int32_t b[4];
    const int32_t c[4];
    const int32_t imm8;
    const int32_t r[4];
  } test_vec[] = {
    { { -INT32_C(   653516781), -INT32_C(  2028462226), -INT32_C(   904210250),  INT32_C(  1997269527) },
      {  INT32_C(  1743133132), -INT32_C(   341193863),  INT32_C(   176179706), -INT32_C(  1042130002) },
      { -INT32_C(   375722373), -INT32_C(   999247091), -INT32_C(  1567716725),  INT32_C(  1092262261) },
       INT32_C(          64),
      {  INT32_C(      262144),  INT32_C(    50858080),  INT32_C(   134234160),  INT32_C(       16898) } },
    { {  INT32_C(   749207731), -INT32_C(   971550260),  INT32_C(  1238407067),  INT32_C(  1829417714) },
      { -INT32_C(  1370053216), -INT32_C(   479017128), -INT32_C(   964362159),  INT32_C(  1292410778) },
      {  INT32_C(  1819914400), -INT32_C(  1657630718),  INT32_C(   434504231),  INT32_C(  1418129588) },
       INT32_C(          65),
      {  INT32_C(   285231692),  INT32_C(  1116236137),  INT32_C(  1611163664), -INT32_C(  1955003901) } },
    { { -INT32_C(   318579563), -INT32_C(   170888029),  INT32_C(   263935605), -INT32_C(  1789082635) },
      {  INT32_C(  1979831668), -INT32_C(  1944898715), -INT32_C(   374998731),  INT32_C(  2134780905) },
      { -INT32_C(  1418969081),  INT32_C(   715144629), -INT32_C(  2009506925), -INT32_C(  1826712289) },
       INT32_C(          66),
      {  INT32_C(  1147966482), -INT32_C(  2043672560),  INT32_C(    25165990),  INT32_C(    67114722) } },
    { { -INT32_C(   821485718), -INT32_C(  2007294893), -INT32_C(    26083307),  INT32_C(   847097899) },
      { -INT32_C(  1512183056), -INT32_C(  1160807129), -INT32_C(   129890087),  INT32_C(   126574749) },
      { -INT32_C(   740912000), -INT32_C(   983879248),  INT32_C(  1556335921),  INT32_C(  1854882173) },
       INT32_C(          67),
      {  INT32_C(   338365029),  INT32_C(  1293979275), -INT32_C(  1584531678), -INT32_C(   939512000) } },
    { {  INT32_C(  1377004587), -INT32_C(  1022565398), -INT32_C(  1984213269),  INT32_C(   797984431) },
      { -INT32_C(  1979553830), -INT32_C(   900768360), -INT32_C(  1473899989),  INT32_C(  2115417427) },
      {  INT32_C(   214968866), -INT32_C(   120595443), -INT32_C(   629044693), -INT32_C(  1442245936) },
       INT32_C(          68),
      { -INT32_C(  2113780264),  INT32_C(    33554832),  INT32_C(   539365376),  INT32_C(  1410770179) } },
    { {  INT32_C(   288623481), -INT32_C(  1814330520), -INT32_C(   381943147), -INT32_C(   647540041) },
      { -INT32_C(  1981466500),  INT32_C(  1065530388),  INT32_C(   236520254), -INT32_C(  1900535275) },
      { -INT32_C(  1767838675),  INT32_C(    86604655),  INT32_C(   904815997),  INT32_C(   873354680) },
       INT32_C(          69),
      {  INT32_C(  1766789330),  INT32_C(  2055636112),  INT32_C(   168925698), -INT32_C(  1968133563) } },
    { { -INT32_C(  1564543859), -INT32_C(   404668248),  INT32_C(  1509292867),  INT32_C(  1273474589) },
      {  INT32_C(   182552474), -INT32_C(  2146498045),  INT32_C(   683015536), -INT32_C(   530791342) },
      {  INT32_C(  1619139256), -INT32_C(  1639488678),  INT32_C(  2096577886), -INT32_C(  2050498837) },
       INT32_C(          70),
      {  INT32_C(  1247907106),  INT32_C(   403188049),  INT32_C(    67289132),  INT32_C(  1679298736) } },
    { {  INT32_C(  1771022438),  INT32_C(   585735858), -INT32_C(   297099365),  INT32_C(   466528099) },
      {  INT32_C(   477843649),  INT32_C(   314229683), -INT32_C(   342970112), -INT32_C(   177187441) },
      { -INT32_C(  1352793859),  INT32_C(   986859678),  INT32_C(  1244142823), -INT32_C(  2056915261) },
       INT32_C(          71),
      { -INT32_C(  1843308776), -INT32_C(   852712595), -INT32_C(  1313349276),  INT32_C(  1880164636) } },
  };

  simde__m128i a, b, c, r;

  a = simde_x_mm_loadu_epi32(test_vec[0].a);
  b = simde_x_mm_loadu_epi32(test_vec[0].b);
  c = simde_x_mm_loadu_epi32(test_vec[0].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(          64));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[0].r));

  a = simde_x_mm_loadu_epi32(test_vec[1].a);
  b = simde_x_mm_loadu_epi32(test_vec[1].b);
  c = simde_x_mm_loadu_epi32(test_vec[1].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(          65));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[1].r));

  a = simde_x_mm_loadu_epi32(test_vec[2].a);
  b = simde_x_mm_loadu_epi32(test_vec[2].b);
  c = simde_x_mm_loadu_epi32(test_vec[2].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(          66));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[2].r));

  a = simde_x_mm_loadu_epi32(test_vec[3].a);
  b = simde_x_mm_loadu_epi32(test_vec[3].b);
  c = simde_x_mm_loadu_epi32(test_vec[3].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(          67));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[3].r));

  a = simde_x_mm_loadu_epi32(test_vec[4].a);
  b = simde_x_mm_loadu_epi32(test_vec[4].b);
  c = simde_x_mm_loadu_epi32(test_vec[4].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(          68));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[4].r));

  a = simde_x_mm_loadu_epi32(test_vec[5].a);
  b = simde_x_mm_loadu_epi32(test_vec[5].b);
  c = simde_x_mm_loadu_epi32(test_vec[5].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(          69));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[5].r));

  a = simde_x_mm_loadu_epi32(test_vec[6].a);
  b = simde_x_mm_loadu_epi32(test_vec[6].b);
  c = simde_x_mm_loadu_epi32(test_vec[6].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(          70));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[6].r));

  a = simde_x_mm_loadu_epi32(test_vec[7].a);
  b = simde_x_mm_loadu_epi32(test_vec[7].b);
  c = simde_x_mm_loadu_epi32(test_vec[7].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(          71));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[7].r));

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 64 ; i < 96 ; i++) {
    simde__m128i a = simde_test_x86_random_i32x4();
    simde__m128i b = simde_test_x86_random_i32x4();
    simde__m128i c = simde_test_x86_random_i32x4();
    simde__m128i r;
    SIMDE_CONSTIFY_32_3(simde_mm_ternarylogic_epi32, r, simde_mm_setzero_si128(), i, a, b, c);

    simde_test_x86_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, i, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_ternarylogic_epi32_10 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t a[4];
    const int32_t b[4];
    const int32_t c[4];
    const int32_t imm8;
    const int32_t r[4];
  } test_vec[] = {
    { { -INT32_C(   106831802), -INT32_C(  1559536733), -INT32_C(  1685153524), -INT32_C(   342753298) },
      { -INT32_C(  1650724865),  INT32_C(   517434679),  INT32_C(  1298726793),  INT32_C(  1003671029) },
      {  INT32_C(  1362457518), -INT32_C(   621461298), -INT32_C(   931822630), -INT32_C(  2118908286) },
       INT32_C(          72),
      { -INT32_C(  2003794968),  INT32_C(   416680229),  INT32_C(  1097341568),  INT32_C(   704694628) } },
    { {  INT32_C(   757026806),  INT32_C(  1162671804), -INT32_C(   342706954),  INT32_C(   807888002) },
      { -INT32_C(  1518248745),  INT32_C(  1988064924),  INT32_C(  2084566522), -INT32_C(   234949637) },
      { -INT32_C(    31515326),  INT32_C(   155413267), -INT32_C(  1577724385),  INT32_C(   315694138) },
       INT32_C(          73),
      { -INT32_C(  2124353380), -INT32_C(   997255988),  INT32_C(  1210542312),  INT32_C(   754348220) } },
    { {  INT32_C(   347558776), -INT32_C(  1014286391),  INT32_C(   658557484), -INT32_C(    15122755) },
      {  INT32_C(  1862088795), -INT32_C(  1032306525),  INT32_C(  1365536022),  INT32_C(    23278985) },
      {  INT32_C(  1377114760),  INT32_C(  2098569297),  INT32_C(   665146730), -INT32_C(   299450733) },
       INT32_C(          74),
      {  INT32_C(  1184893136), -INT32_C(  1105428336),  INT32_C(    15015238),  INT32_C(    19365898) } },
    { { -INT32_C(  1721949194),  INT32_C(  2052838756), -INT32_C(   875839678),  INT32_C(  2110533365) },
      { -INT32_C(  1697652407), -INT32_C(   333912702), -INT32_C(   837501638),  INT32_C(  1908161147) },
      { -INT32_C(  1039525538),  INT32_C(   809264622),  INT32_C(   452659237),  INT32_C(  2140653366) },
       INT32_C(          75),
      {  INT32_C(  2120694792),  INT32_C(  1235528347), -INT32_C(   265226841), -INT32_C(  2112100029) } },
    { {  INT32_C(   723150761), -INT32_C(  2045300148),  INT32_C(  1783901167), -INT32_C(   992276122) },
      {  INT32_C(   428270890),  INT32_C(  1867104842),  INT32_C(    25773514), -INT32_C(  1249894132) },
      { -INT32_C(   723477880), -INT32_C(  1151665972), -INT32_C(  1994019037), -INT32_C(   364052288) },
       INT32_C(          76),
      {  INT32_C(   428270882),  INT32_C(  1833550338),  INT32_C(    25773256),  INT32_C(   897589516) } },
    { {  INT32_C(   805557221),  INT32_C(  1621052822), -INT32_C(  1637799534), -INT32_C(   766188982) },
      {  INT32_C(  1235629180),  INT32_C(  1342439468),  INT32_C(  1876503215),  INT32_C(   274343722) },
      { -INT32_C(  1874829830),  INT32_C(  1022484394),  INT32_C(  1390105096), -INT32_C(  1323028684) },
       INT32_C(          77),
      {  INT32_C(  1337861148), -INT32_C(   754704275),  INT32_C(  1838984943),  INT32_C(   215684523) } },
    { { -INT32_C(  1862612381),  INT32_C(  2061565643),  INT32_C(  1407891752), -INT32_C(   614251296) },
      {  INT32_C(  1282122657), -INT32_C(  1953997694), -INT32_C(   472030289), -INT32_C(   158072174) },
      { -INT32_C(  1752789300), -INT32_C(  1257085299),  INT32_C(      588831), -INT32_C(   505713856) },
       INT32_C(          78),
      {  INT32_C(  1332553133), -INT32_C(  1885726714), -INT32_C(   472561737),  INT32_C(   916204434) } },
    { { -INT32_C(  1859303922),  INT32_C(  1377613475), -INT32_C(  1405748967), -INT32_C(   928855301) },
      { -INT32_C(   446748584), -INT32_C(  1382321778), -INT32_C(  1381129363),  INT32_C(   495945743) },
      {  INT32_C(  1924054223), -INT32_C(  1933260174), -INT32_C(  1086785084),  INT32_C(   478665411) },
       INT32_C(          79),
      { -INT32_C(   271336975), -INT32_C(  1376028196),  INT32_C(  1406076655),  INT32_C(   928855308) } },
  };

  simde__m128i a, b, c, r;

  a = simde_x_mm_loadu_epi32(test_vec[0].a);
  b = simde_x_mm_loadu_epi32(test_vec[0].b);
  c = simde_x_mm_loadu_epi32(test_vec[0].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(          72));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[0].r));

  a = simde_x_mm_loadu_epi32(test_vec[1].a);
  b = simde_x_mm_loadu_epi32(test_vec[1].b);
  c = simde_x_mm_loadu_epi32(test_vec[1].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(          73));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[1].r));

  a = simde_x_mm_loadu_epi32(test_vec[2].a);
  b = simde_x_mm_loadu_epi32(test_vec[2].b);
  c = simde_x_mm_loadu_epi32(test_vec[2].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(          74));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[2].r));

  a = simde_x_mm_loadu_epi32(test_vec[3].a);
  b = simde_x_mm_loadu_epi32(test_vec[3].b);
  c = simde_x_mm_loadu_epi32(test_vec[3].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(          75));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[3].r));

  a = simde_x_mm_loadu_epi32(test_vec[4].a);
  b = simde_x_mm_loadu_epi32(test_vec[4].b);
  c = simde_x_mm_loadu_epi32(test_vec[4].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(          76));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[4].r));

  a = simde_x_mm_loadu_epi32(test_vec[5].a);
  b = simde_x_mm_loadu_epi32(test_vec[5].b);
  c = simde_x_mm_loadu_epi32(test_vec[5].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(          77));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[5].r));

  a = simde_x_mm_loadu_epi32(test_vec[6].a);
  b = simde_x_mm_loadu_epi32(test_vec[6].b);
  c = simde_x_mm_loadu_epi32(test_vec[6].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(          78));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[6].r));

  a = simde_x_mm_loadu_epi32(test_vec[7].a);
  b = simde_x_mm_loadu_epi32(test_vec[7].b);
  c = simde_x_mm_loadu_epi32(test_vec[7].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(          79));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[7].r));

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 64 ; i < 96 ; i++) {
    simde__m128i a = simde_test_x86_random_i32x4();
    simde__m128i b = simde_test_x86_random_i32x4();
    simde__m128i c = simde_test_x86_random_i32x4();
    simde__m128i r;
    SIMDE_CONSTIFY_32_3(simde_mm_ternarylogic_epi32, r, simde_mm_setzero_si128(), i, a, b, c);

    simde_test_x86_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, i, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_ternarylogic_epi32_11 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t a[4];
    const int32_t b[4];
    const int32_t c[4];
    const int32_t imm8;
    const int32_t r[4];
  } test_vec[] = {
    { { -INT32_C(  1878923518), -INT32_C(   969040808),  INT32_C(  1332996928),  INT32_C(  1114374771) },
      {  INT32_C(   833887167), -INT32_C(  1447200539),  INT32_C(   896136562), -INT32_C(   783159089) },
      {  INT32_C(   811684823),  INT32_C(   804691951), -INT32_C(    42047094),  INT32_C(   725674860) },
       INT32_C(          80),
      { -INT32_C(  2147441664), -INT32_C(  1073151984),  INT32_C(    33653312),  INT32_C(  1076625427) } },
    { { -INT32_C(   346229754), -INT32_C(   543876499), -INT32_C(   552272369), -INT32_C(   961517842) },
      { -INT32_C(  1460268359),  INT32_C(  1004072113), -INT32_C(  1053272491),  INT32_C(  1206679617) },
      { -INT32_C(   634173075),  INT32_C(  1924778083), -INT32_C(  1269707322), -INT32_C(   327548365) },
       INT32_C(          81),
      {  INT32_C(   625783810), -INT32_C(  1928981748),  INT32_C(  1267085865),  INT32_C(   310502860) } },
    { { -INT32_C(   980062188), -INT32_C(  1308594852),  INT32_C(    91437251),  INT32_C(   508321969) },
      {  INT32_C(   217612201),  INT32_C(   226406727), -INT32_C(  1295855490), -INT32_C(   425837358) },
      {  INT32_C(   162214829),  INT32_C(  1690020768), -INT32_C(  1805045789),  INT32_C(   951235983) },
       INT32_C(          82),
      { -INT32_C(  1005174768), -INT32_C(   763279620),  INT32_C(    18487040),  INT32_C(   107790652) } },
    { {  INT32_C(  2084874805), -INT32_C(   628440485),  INT32_C(  1686916242),  INT32_C(   894053000) },
      { -INT32_C(    29362850), -INT32_C(  2073888096), -INT32_C(  1206334679), -INT32_C(  1225733247) },
      { -INT32_C(   785238923), -INT32_C(  1985233673), -INT32_C(  1846659320), -INT32_C(  1077528479) },
       INT32_C(          83),
      {  INT32_C(   767855232),  INT32_C(  1930774284),  INT32_C(  1734572246),  INT32_C(  1208817406) } },
    { { -INT32_C(   826407634),  INT32_C(   693248000),  INT32_C(  1843555308), -INT32_C(  1423715786) },
      { -INT32_C(    25406201),  INT32_C(   445064978), -INT32_C(  1062505122), -INT32_C(   595627346) },
      {  INT32_C(  2007645559),  INT32_C(  1252130142), -INT32_C(  1632140440),  INT32_C(  1548343893) },
       INT32_C(          84),
      { -INT32_C(  2007744504),  INT32_C(   827720192),  INT32_C(  1632140438), -INT32_C(  1556733782) } },
    { {  INT32_C(  1096468015),  INT32_C(  1281155821),  INT32_C(    84674391), -INT32_C(   236876935) },
      {  INT32_C(   661163209), -INT32_C(   244250231), -INT32_C(   493934452),  INT32_C(   826202114) },
      { -INT32_C(  1938581090), -INT32_C(   757543045),  INT32_C(  1356391638),  INT32_C(   943831407) },
       INT32_C(          85),
      {  INT32_C(  1938581089),  INT32_C(   757543044), -INT32_C(  1356391639), -INT32_C(   943831408) } },
    { { -INT32_C(   832591547),  INT32_C(  1069535411), -INT32_C(    98480392), -INT32_C(   986947545) },
      {  INT32_C(  1951506425),  INT32_C(  1145448814),  INT32_C(  2106859021),  INT32_C(   498456024) },
      {  INT32_C(   854332799), -INT32_C(   562975771),  INT32_C(   567841786), -INT32_C(   320469773) },
       INT32_C(          86),
      { -INT32_C(   860640638), -INT32_C(  1584508390), -INT32_C(   563229433),  INT32_C(   828109068) } },
    { {  INT32_C(   291518627),  INT32_C(  1867949665), -INT32_C(  1645417787),  INT32_C(  1069195712) },
      { -INT32_C(  1670273354),  INT32_C(  1283121746),  INT32_C(  1751994997), -INT32_C(    95136937) },
      { -INT32_C(   317934453),  INT32_C(   542925403),  INT32_C(   213731404), -INT32_C(  1605666839) },
       INT32_C(          87),
      {  INT32_C(  1929333628), -INT32_C(   542925396), -INT32_C(   212682821),  INT32_C(  1605733438) } },
  };

  simde__m128i a, b, c, r;

  a = simde_x_mm_loadu_epi32(test_vec[0].a);
  b = simde_x_mm_loadu_epi32(test_vec[0].b);
  c = simde_x_mm_loadu_epi32(test_vec[0].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(          80));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[0].r));

  a = simde_x_mm_loadu_epi32(test_vec[1].a);
  b = simde_x_mm_loadu_epi32(test_vec[1].b);
  c = simde_x_mm_loadu_epi32(test_vec[1].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(          81));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[1].r));

  a = simde_x_mm_loadu_epi32(test_vec[2].a);
  b = simde_x_mm_loadu_epi32(test_vec[2].b);
  c = simde_x_mm_loadu_epi32(test_vec[2].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(          82));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[2].r));

  a = simde_x_mm_loadu_epi32(test_vec[3].a);
  b = simde_x_mm_loadu_epi32(test_vec[3].b);
  c = simde_x_mm_loadu_epi32(test_vec[3].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(          83));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[3].r));

  a = simde_x_mm_loadu_epi32(test_vec[4].a);
  b = simde_x_mm_loadu_epi32(test_vec[4].b);
  c = simde_x_mm_loadu_epi32(test_vec[4].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(          84));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[4].r));

  a = simde_x_mm_loadu_epi32(test_vec[5].a);
  b = simde_x_mm_loadu_epi32(test_vec[5].b);
  c = simde_x_mm_loadu_epi32(test_vec[5].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(          85));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[5].r));

  a = simde_x_mm_loadu_epi32(test_vec[6].a);
  b = simde_x_mm_loadu_epi32(test_vec[6].b);
  c = simde_x_mm_loadu_epi32(test_vec[6].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(          86));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[6].r));

  a = simde_x_mm_loadu_epi32(test_vec[7].a);
  b = simde_x_mm_loadu_epi32(test_vec[7].b);
  c = simde_x_mm_loadu_epi32(test_vec[7].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(          87));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[7].r));

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 64 ; i < 96 ; i++) {
    simde__m128i a = simde_test_x86_random_i32x4();
    simde__m128i b = simde_test_x86_random_i32x4();
    simde__m128i c = simde_test_x86_random_i32x4();
    simde__m128i r;
    SIMDE_CONSTIFY_32_3(simde_mm_ternarylogic_epi32, r, simde_mm_setzero_si128(), i, a, b, c);

    simde_test_x86_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, i, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_ternarylogic_epi32_12 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t a[4];
    const int32_t b[4];
    const int32_t c[4];
    const int32_t imm8;
    const int32_t r[4];
  } test_vec[] = {
    { {  INT32_C(  1883028510),  INT32_C(   347911839),  INT32_C(  1602038024),  INT32_C(   140169596) },
      { -INT32_C(   504011130),  INT32_C(   335630792), -INT32_C(  2111717735),  INT32_C(  1394764853) },
      { -INT32_C(   926720471),  INT32_C(   500989716),  INT32_C(   628906408), -INT32_C(  1322396117) },
       INT32_C(          88),
      { -INT32_C(  1325538794),  INT32_C(     2146699),  INT32_C(  1510027392),  INT32_C(   426902869) } },
    { {  INT32_C(    76685884),  INT32_C(   203002739), -INT32_C(  2037499311), -INT32_C(   807751258) },
      {  INT32_C(   613915919), -INT32_C(   985566179), -INT32_C(   118833715), -INT32_C(   794224748) },
      { -INT32_C(  1395311815),  INT32_C(   532213454), -INT32_C(   827963608),  INT32_C(   127828216) },
       INT32_C(          89),
      {  INT32_C(  1932483013),  INT32_C(   554136893),  INT32_C(  1228488027), -INT32_C(   398427881) } },
    { {  INT32_C(   975910173),  INT32_C(  1996516521), -INT32_C(  1099961814),  INT32_C(   999168258) },
      {  INT32_C(   602432340),  INT32_C(  2034409553), -INT32_C(   548869913), -INT32_C(  2031622552) },
      { -INT32_C(   977268197), -INT32_C(  1455636353), -INT32_C(  1385714773),  INT32_C(   434697668) },
       INT32_C(          90),
      { -INT32_C(     1366266), -INT32_C(   566448938),  INT32_C(   319308161),  INT32_C(   577170630) } },
    { { -INT32_C(  1438855079),  INT32_C(  1478786673), -INT32_C(   818385817),  INT32_C(  1834295122) },
      { -INT32_C(  1338894799), -INT32_C(  2124845354), -INT32_C(   567361510),  INT32_C(   267851702) },
      {  INT32_C(  1488532455),  INT32_C(   431087026), -INT32_C(  1679234743),  INT32_C(   956907016) },
       INT32_C(          91),
      { -INT32_C(   138024002),  INT32_C(  1737991115),  INT32_C(  1959892910), -INT32_C(   732110501) } },
    { {  INT32_C(   719993684), -INT32_C(   995343446), -INT32_C(  1163732476), -INT32_C(   641099023) },
      {  INT32_C(  2133951181), -INT32_C(  1449598368), -INT32_C(   750419509),  INT32_C(   319639231) },
      {  INT32_C(   859699081),  INT32_C(  1056434490), -INT32_C(  1241998652),  INT32_C(    26132788) },
       INT32_C(          92),
      {  INT32_C(  1574144221), -INT32_C(   384261440),  INT32_C(  1262961099), -INT32_C(   632987953) } },
    { { -INT32_C(  1535000508),  INT32_C(  1850546594),  INT32_C(  1497469594),  INT32_C(  1785482976) },
      { -INT32_C(  2137150907),  INT32_C(  1472107923),  INT32_C(  1661843247), -INT32_C(  1134257288) },
      { -INT32_C(    27204261), -INT32_C(  1720930561),  INT32_C(   569617728),  INT32_C(  1099653116) },
       INT32_C(          93),
      {  INT32_C(    27212453),  INT32_C(  2008274193), -INT32_C(    32737345), -INT32_C(  1099648741) } },
    { { -INT32_C(  1648285687), -INT32_C(   319520579), -INT32_C(  1353776841), -INT32_C(   127093603) },
      { -INT32_C(  1728656231), -INT32_C(  1154325894),  INT32_C(   215754000), -INT32_C(  1907529852) },
      {  INT32_C(  1294667663), -INT32_C(   969334897), -INT32_C(  1099593439), -INT32_C(   692657859) },
       INT32_C(          94),
      { -INT32_C(   788600938),  INT32_C(  1003487090),  INT32_C(   297446422),  INT32_C(   786126752) } },
    { {  INT32_C(   678407598),  INT32_C(   535011599),  INT32_C(  1244381126), -INT32_C(  1227327194) },
      {  INT32_C(   386073480),  INT32_C(  1155349539),  INT32_C(    33706693), -INT32_C(   489048012) },
      {  INT32_C(  1963608165), -INT32_C(  1349194007), -INT32_C(   721829715), -INT32_C(  1047866823) },
       INT32_C(          95),
      { -INT32_C(   537528357), -INT32_C(   260087818), -INT32_C(  1076461701),  INT32_C(  2138550239) } },
  };

  simde__m128i a, b, c, r;

  a = simde_x_mm_loadu_epi32(test_vec[0].a);
  b = simde_x_mm_loadu_epi32(test_vec[0].b);
  c = simde_x_mm_loadu_epi32(test_vec[0].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(          88));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[0].r));

  a = simde_x_mm_loadu_epi32(test_vec[1].a);
  b = simde_x_mm_loadu_epi32(test_vec[1].b);
  c = simde_x_mm_loadu_epi32(test_vec[1].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(          89));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[1].r));

  a = simde_x_mm_loadu_epi32(test_vec[2].a);
  b = simde_x_mm_loadu_epi32(test_vec[2].b);
  c = simde_x_mm_loadu_epi32(test_vec[2].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(          90));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[2].r));

  a = simde_x_mm_loadu_epi32(test_vec[3].a);
  b = simde_x_mm_loadu_epi32(test_vec[3].b);
  c = simde_x_mm_loadu_epi32(test_vec[3].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(          91));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[3].r));

  a = simde_x_mm_loadu_epi32(test_vec[4].a);
  b = simde_x_mm_loadu_epi32(test_vec[4].b);
  c = simde_x_mm_loadu_epi32(test_vec[4].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(          92));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[4].r));

  a = simde_x_mm_loadu_epi32(test_vec[5].a);
  b = simde_x_mm_loadu_epi32(test_vec[5].b);
  c = simde_x_mm_loadu_epi32(test_vec[5].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(          93));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[5].r));

  a = simde_x_mm_loadu_epi32(test_vec[6].a);
  b = simde_x_mm_loadu_epi32(test_vec[6].b);
  c = simde_x_mm_loadu_epi32(test_vec[6].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(          94));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[6].r));

  a = simde_x_mm_loadu_epi32(test_vec[7].a);
  b = simde_x_mm_loadu_epi32(test_vec[7].b);
  c = simde_x_mm_loadu_epi32(test_vec[7].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(          95));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[7].r));

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 64 ; i < 96 ; i++) {
    simde__m128i a = simde_test_x86_random_i32x4();
    simde__m128i b = simde_test_x86_random_i32x4();
    simde__m128i c = simde_test_x86_random_i32x4();
    simde__m128i r;
    SIMDE_CONSTIFY_32_3(simde_mm_ternarylogic_epi32, r, simde_mm_setzero_si128(), i, a, b, c);

    simde_test_x86_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, i, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_ternarylogic_epi32_13 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t a[4];
    const int32_t b[4];
    const int32_t c[4];
    const int32_t imm8;
    const int32_t r[4];
  } test_vec[] = {
    { { -INT32_C(  1311221607), -INT32_C(  1684475024), -INT32_C(    65511163),  INT32_C(   325617268) },
      {  INT32_C(   159352900),  INT32_C(  1615760846), -INT32_C(   218288201), -INT32_C(   444104116) },
      {  INT32_C(  1268211674),  INT32_C(  1491480402),  INT32_C(    72679312), -INT32_C(   904413819) },
       INT32_C(          96),
      {  INT32_C(    13127832),  INT32_C(   411607568), -INT32_C(   200785915),  INT32_C(    50333248) } },
    { {  INT32_C(   332633669), -INT32_C(   629923549), -INT32_C(  1664257712), -INT32_C(   830319373) },
      {  INT32_C(   102308276), -INT32_C(   664862904), -INT32_C(  2065845250), -INT32_C(  1253116816) },
      { -INT32_C(  1362615925), -INT32_C(  1836499902), -INT32_C(  1590798674),  INT32_C(  1584378026) },
       INT32_C(          97),
      {  INT32_C(  1089818629),  INT32_C(  1867776406),  INT32_C(  1187080529), -INT32_C(   904900650) } },
    { {  INT32_C(   291866825), -INT32_C(  2031434872), -INT32_C(   435501194),  INT32_C(  1184585915) },
      { -INT32_C(  1141545863),  INT32_C(  1313701536),  INT32_C(  2129689812), -INT32_C(   153264340) },
      {  INT32_C(  1879524072),  INT32_C(  2096558341),  INT32_C(  1952580024), -INT32_C(   742719911) },
       INT32_C(          98),
      {  INT32_C(  1096942209),  INT32_C(   851084165),  INT32_C(    33703276),  INT32_C(    86220913) } },
    { {  INT32_C(    42905442),  INT32_C(    22141997), -INT32_C(  2071969448), -INT32_C(  2005246560) },
      { -INT32_C(  1527217505),  INT32_C(   740355955),  INT32_C(  1235256304), -INT32_C(   484681087) },
      {  INT32_C(   937798410), -INT32_C(   549898617),  INT32_C(   409188727), -INT32_C(  1247748586) },
       INT32_C(          99),
      {  INT32_C(  1527609600), -INT32_C(   744499036),  INT32_C(   853490695),  INT32_C(   347710686) } },
    { { -INT32_C(   749102752),  INT32_C(  2030008968),  INT32_C(  2126618621),  INT32_C(    73522938) },
      {  INT32_C(   272320137), -INT32_C(   185633667),  INT32_C(  1124880941), -INT32_C(  1862750928) },
      { -INT32_C(   832286138), -INT32_C(   918133812), -INT32_C(    45676797),  INT32_C(  1845602533) },
       INT32_C(         100),
      { -INT32_C(   765782839),  INT32_C(  1017714353),  INT32_C(  1044993324), -INT32_C(  1795619376) } },
    { {  INT32_C(  1803435246), -INT32_C(   564105807), -INT32_C(   266179392),  INT32_C(  1602296345) },
      {  INT32_C(   942531948),  INT32_C(  1258386248),  INT32_C(  1615349883), -INT32_C(   540063248) },
      {  INT32_C(   927616390),  INT32_C(  2065017531),  INT32_C(   812332823), -INT32_C(  1097798574) },
       INT32_C(         101),
      { -INT32_C(  1947751685),  INT32_C(   277502453),  INT32_C(  1605823592),  INT32_C(  1097793956) } },
    { {  INT32_C(   452443601), -INT32_C(  1402603471),  INT32_C(   822914625),  INT32_C(  2098256887) },
      { -INT32_C(   457942231),  INT32_C(   476039685),  INT32_C(  1397606913), -INT32_C(  2012029513) },
      { -INT32_C(   878573158),  INT32_C(  1115097089), -INT32_C(  1384872778), -INT32_C(  2010413985) },
       INT32_C(         102),
      {  INT32_C(   789992115),  INT32_C(  1579729412), -INT32_C(    29798729),  INT32_C(     3758568) } },
    { { -INT32_C(   445849633), -INT32_C(  1425945687),  INT32_C(  1308511894), -INT32_C(   959115221) },
      {  INT32_C(   462518297),  INT32_C(   912066944), -INT32_C(   320614003),  INT32_C(   896863830) },
      { -INT32_C(  1759845906),  INT32_C(  1128406189), -INT32_C(  1768930966),  INT32_C(  1801217361) },
       INT32_C(         103),
      { -INT32_C(  1937008137),  INT32_C(  1975465343),  INT32_C(  2054402279),  INT32_C(  1579936647) } },
  };

  simde__m128i a, b, c, r;

  a = simde_x_mm_loadu_epi32(test_vec[0].a);
  b = simde_x_mm_loadu_epi32(test_vec[0].b);
  c = simde_x_mm_loadu_epi32(test_vec[0].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(          96));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[0].r));

  a = simde_x_mm_loadu_epi32(test_vec[1].a);
  b = simde_x_mm_loadu_epi32(test_vec[1].b);
  c = simde_x_mm_loadu_epi32(test_vec[1].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(          97));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[1].r));

  a = simde_x_mm_loadu_epi32(test_vec[2].a);
  b = simde_x_mm_loadu_epi32(test_vec[2].b);
  c = simde_x_mm_loadu_epi32(test_vec[2].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(          98));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[2].r));

  a = simde_x_mm_loadu_epi32(test_vec[3].a);
  b = simde_x_mm_loadu_epi32(test_vec[3].b);
  c = simde_x_mm_loadu_epi32(test_vec[3].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(          99));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[3].r));

  a = simde_x_mm_loadu_epi32(test_vec[4].a);
  b = simde_x_mm_loadu_epi32(test_vec[4].b);
  c = simde_x_mm_loadu_epi32(test_vec[4].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         100));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[4].r));

  a = simde_x_mm_loadu_epi32(test_vec[5].a);
  b = simde_x_mm_loadu_epi32(test_vec[5].b);
  c = simde_x_mm_loadu_epi32(test_vec[5].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         101));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[5].r));

  a = simde_x_mm_loadu_epi32(test_vec[6].a);
  b = simde_x_mm_loadu_epi32(test_vec[6].b);
  c = simde_x_mm_loadu_epi32(test_vec[6].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         102));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[6].r));

  a = simde_x_mm_loadu_epi32(test_vec[7].a);
  b = simde_x_mm_loadu_epi32(test_vec[7].b);
  c = simde_x_mm_loadu_epi32(test_vec[7].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         103));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[7].r));

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 96 ; i < 128 ; i++) {
    simde__m128i a = simde_test_x86_random_i32x4();
    simde__m128i b = simde_test_x86_random_i32x4();
    simde__m128i c = simde_test_x86_random_i32x4();
    simde__m128i r;
    SIMDE_CONSTIFY_32_4(simde_mm_ternarylogic_epi32, r, simde_mm_setzero_si128(), i, a, b, c);

    simde_test_x86_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, i, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_ternarylogic_epi32_14 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t a[4];
    const int32_t b[4];
    const int32_t c[4];
    const int32_t imm8;
    const int32_t r[4];
  } test_vec[] = {
    { {  INT32_C(  1569123805), -INT32_C(  2087459850),  INT32_C(   191920053),  INT32_C(  1933632901) },
      {  INT32_C(  1930124230), -INT32_C(   508146313), -INT32_C(   529054066), -INT32_C(  1991519316) },
      { -INT32_C(  1209544255),  INT32_C(  1765505716),  INT32_C(  2004134897),  INT32_C(  1458222480) },
       INT32_C(         104),
      {  INT32_C(  1720031237), -INT32_C(   526308414),  INT32_C(  1661232437),  INT32_C(  1393193988) } },
    { { -INT32_C(  2016742128), -INT32_C(   781680573),  INT32_C(  1941037255),  INT32_C(  1962736819) },
      { -INT32_C(  2110987315),  INT32_C(  1340827486), -INT32_C(  1564057582),  INT32_C(   637055253) },
      { -INT32_C(   374553946),  INT32_C(   180032579), -INT32_C(  1468175116),  INT32_C(   907835753) },
       INT32_C(         105),
      {  INT32_C(   330640260),  INT32_C(  1808207009), -INT32_C(  2030758946), -INT32_C(  1729639632) } },
    { { -INT32_C(  1145550755), -INT32_C(  1056267089),  INT32_C(   425971972),  INT32_C(   675175554) },
      {  INT32_C(  1628629534), -INT32_C(   211038722), -INT32_C(  1566840775), -INT32_C(  1076250782) },
      { -INT32_C(  1350921984),  INT32_C(   963740725), -INT32_C(   682437547),  INT32_C(  1325436976) },
       INT32_C(         106),
      { -INT32_C(  1905600228), -INT32_C(   126156645), -INT32_C(   682552235),  INT32_C(  1729659954) } },
    { {  INT32_C(  2041582202),  INT32_C(   409738463),  INT32_C(  1723533060), -INT32_C(  1104833346) },
      {  INT32_C(  1533976357),  INT32_C(  2039799588), -INT32_C(   464394317), -INT32_C(   231517833) },
      {  INT32_C(  1114366819),  INT32_C(    73062399), -INT32_C(  1670769186), -INT32_C(   816082775) },
       INT32_C(         107),
      { -INT32_C(  1622412861), -INT32_C(  1637880837), -INT32_C(   109110562),  INT32_C(  2113579679) } },
    { {  INT32_C(  1395312943),  INT32_C(  1540210344),  INT32_C(   490675877), -INT32_C(   770739601) },
      {  INT32_C(  1427405398),  INT32_C(   794390097),  INT32_C(   768328836), -INT32_C(  2080627116) },
      { -INT32_C(  1747507473), -INT32_C(  1963744027),  INT32_C(   833041090), -INT32_C(    83642715) },
       INT32_C(         108),
      {  INT32_C(  1175878265),  INT32_C(   630770417),  INT32_C(  1022154244),  INT32_C(  1375671409) } },
    { { -INT32_C(  2125457616),  INT32_C(   162572933), -INT32_C(  1036551058), -INT32_C(  1840958558) },
      {  INT32_C(  1059658842), -INT32_C(  2100749120), -INT32_C(   189566641),  INT32_C(  1492104743) },
      {  INT32_C(  1406746573),  INT32_C(  1465682665), -INT32_C(  1474718970),  INT32_C(   557473735) },
       INT32_C(         109),
      {  INT32_C(  1048562522), -INT32_C(  1545873581),  INT32_C(  1977770457),  INT32_C(  1559209405) } },
    { {  INT32_C(  1012950139), -INT32_C(   809621120), -INT32_C(  1027378534), -INT32_C(   166022616) },
      { -INT32_C(   615910414), -INT32_C(  2093767299),  INT32_C(     2903097),  INT32_C(   656500395) },
      {  INT32_C(  1264812490),  INT32_C(  1159340458), -INT32_C(  1140334957), -INT32_C(  2102255216) },
       INT32_C(         110),
      { -INT32_C(   752094280), -INT32_C(   970357505), -INT32_C(  1137729877), -INT32_C(  1514977349) } },
    { { -INT32_C(  1839269100), -INT32_C(   652897888), -INT32_C(  1982250531),  INT32_C(  1924201128) },
      {  INT32_C(   649925499), -INT32_C(   932456396),  INT32_C(  1183085238), -INT32_C(  1479985517) },
      { -INT32_C(   784783567), -INT32_C(  1783935048),  INT32_C(   941524112), -INT32_C(    89403777) },
       INT32_C(         111),
      { -INT32_C(     5950229),  INT32_C(  2146107359),  INT32_C(  2126446118), -INT32_C(   579863041) } },
  };

  simde__m128i a, b, c, r;

  a = simde_x_mm_loadu_epi32(test_vec[0].a);
  b = simde_x_mm_loadu_epi32(test_vec[0].b);
  c = simde_x_mm_loadu_epi32(test_vec[0].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         104));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[0].r));

  a = simde_x_mm_loadu_epi32(test_vec[1].a);
  b = simde_x_mm_loadu_epi32(test_vec[1].b);
  c = simde_x_mm_loadu_epi32(test_vec[1].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         105));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[1].r));

  a = simde_x_mm_loadu_epi32(test_vec[2].a);
  b = simde_x_mm_loadu_epi32(test_vec[2].b);
  c = simde_x_mm_loadu_epi32(test_vec[2].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         106));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[2].r));

  a = simde_x_mm_loadu_epi32(test_vec[3].a);
  b = simde_x_mm_loadu_epi32(test_vec[3].b);
  c = simde_x_mm_loadu_epi32(test_vec[3].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         107));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[3].r));

  a = simde_x_mm_loadu_epi32(test_vec[4].a);
  b = simde_x_mm_loadu_epi32(test_vec[4].b);
  c = simde_x_mm_loadu_epi32(test_vec[4].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         108));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[4].r));

  a = simde_x_mm_loadu_epi32(test_vec[5].a);
  b = simde_x_mm_loadu_epi32(test_vec[5].b);
  c = simde_x_mm_loadu_epi32(test_vec[5].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         109));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[5].r));

  a = simde_x_mm_loadu_epi32(test_vec[6].a);
  b = simde_x_mm_loadu_epi32(test_vec[6].b);
  c = simde_x_mm_loadu_epi32(test_vec[6].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         110));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[6].r));

  a = simde_x_mm_loadu_epi32(test_vec[7].a);
  b = simde_x_mm_loadu_epi32(test_vec[7].b);
  c = simde_x_mm_loadu_epi32(test_vec[7].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         111));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[7].r));

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 96 ; i < 128 ; i++) {
    simde__m128i a = simde_test_x86_random_i32x4();
    simde__m128i b = simde_test_x86_random_i32x4();
    simde__m128i c = simde_test_x86_random_i32x4();
    simde__m128i r;
    SIMDE_CONSTIFY_32_4(simde_mm_ternarylogic_epi32, r, simde_mm_setzero_si128(), i, a, b, c);

    simde_test_x86_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, i, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_ternarylogic_epi32_15 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t a[4];
    const int32_t b[4];
    const int32_t c[4];
    const int32_t imm8;
    const int32_t r[4];
  } test_vec[] = {
    { {  INT32_C(   371222753), -INT32_C(   153187520), -INT32_C(  1875025155), -INT32_C(   919075176) },
      { -INT32_C(   442863315),  INT32_C(  1366967744),  INT32_C(  1233754570),  INT32_C(  1229141095) },
      { -INT32_C(   580950883), -INT32_C(   304857617),  INT32_C(   930943391),  INT32_C(  1140897047) },
       INT32_C(         112),
      {  INT32_C(   304089312), -INT32_C(  1232172544), -INT32_C(  1875615115), -INT32_C(  1992818024) } },
    { { -INT32_C(   416703961), -INT32_C(  1439128608), -INT32_C(  1527528900), -INT32_C(  1813170442) },
      { -INT32_C(  1972286310),  INT32_C(   678905225),  INT32_C(  1835005014), -INT32_C(   776904790) },
      { -INT32_C(   642196743), -INT32_C(  1165758083), -INT32_C(  1453427021),  INT32_C(  1195199405) },
       INT32_C(         113),
      {  INT32_C(  1729082151), -INT32_C(   952587550), -INT32_C(  1767797972), -INT32_C(  1160858538) } },
    { {  INT32_C(   550612631),  INT32_C(  1229474035), -INT32_C(   407460035), -INT32_C(     4692218) },
      { -INT32_C(  1093046207),  INT32_C(   343432289), -INT32_C(  2134976813), -INT32_C(  1194853599) },
      { -INT32_C(  1663526487),  INT32_C(   518332641), -INT32_C(   855270457),  INT32_C(  1137556738) },
       INT32_C(         114),
      {  INT32_C(   536981438),  INT32_C(  1267558546),  INT32_C(  1874013500), -INT32_C(    13089274) } },
    { { -INT32_C(  1895717330), -INT32_C(   710641150),  INT32_C(  1918198352),  INT32_C(   103423325) },
      { -INT32_C(  1750989898), -INT32_C(   340359389),  INT32_C(   616086306), -INT32_C(  1486387847) },
      {  INT32_C(   775317547),  INT32_C(   855890658), -INT32_C(  1717216964),  INT32_C(   748670838) },
       INT32_C(         115),
      { -INT32_C(   379716019), -INT32_C(   722634532), -INT32_C(    78158115),  INT32_C(  1522039439) } },
    { { -INT32_C(   154975790), -INT32_C(   354321976), -INT32_C(  1374774987),  INT32_C(  1247114527) },
      { -INT32_C(  1065841698), -INT32_C(  1561101210),  INT32_C(  1262262485),  INT32_C(   980933480) },
      { -INT32_C(   449824227), -INT32_C(   372239948), -INT32_C(   896016725),  INT32_C(   840232020) },
       INT32_C(         116),
      {  INT32_C(   919323074),  INT32_C(  1243835850), -INT32_C(  1523973772),  INT32_C(  1214461759) } },
    { { -INT32_C(   571306633), -INT32_C(   561977847), -INT32_C(   433472386), -INT32_C(  1272864617) },
      { -INT32_C(  1902489126),  INT32_C(   242707043), -INT32_C(  1663562168),  INT32_C(  1926163706) },
      { -INT32_C(  2108702343),  INT32_C(   627101607),  INT32_C(   588024203),  INT32_C(    81210665) },
       INT32_C(         117),
      {  INT32_C(  2112929447), -INT32_C(   627067816), -INT32_C(    17566090), -INT32_C(    14036265) } },
    { { -INT32_C(   510496386),  INT32_C(   619645659),  INT32_C(   331400984),  INT32_C(   763727796) },
      { -INT32_C(   139406256),  INT32_C(   790368420), -INT32_C(  1018025830), -INT32_C(   725145003) },
      {  INT32_C(  2008373915),  INT32_C(  2090575204),  INT32_C(   546265964),  INT32_C(   978195690) },
       INT32_C(         118),
      { -INT32_C(  2146979857),  INT32_C(  1407696859), -INT32_C(   203556874), -INT32_C(   276185153) } },
    { { -INT32_C(  1926103319), -INT32_C(  1464054258), -INT32_C(   865333386), -INT32_C(   727698631) },
      { -INT32_C(   246721139),  INT32_C(  1735321338),  INT32_C(   747109698), -INT32_C(    77081326) },
      { -INT32_C(   494364461),  INT32_C(  1569342694), -INT32_C(  1943407021), -INT32_C(  1218328278) },
       INT32_C(         119),
      {  INT32_C(   536342398), -INT32_C(  1158300899), -INT32_C(   201454659),  INT32_C(  1285439229) } },
  };

  simde__m128i a, b, c, r;

  a = simde_x_mm_loadu_epi32(test_vec[0].a);
  b = simde_x_mm_loadu_epi32(test_vec[0].b);
  c = simde_x_mm_loadu_epi32(test_vec[0].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         112));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[0].r));

  a = simde_x_mm_loadu_epi32(test_vec[1].a);
  b = simde_x_mm_loadu_epi32(test_vec[1].b);
  c = simde_x_mm_loadu_epi32(test_vec[1].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         113));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[1].r));

  a = simde_x_mm_loadu_epi32(test_vec[2].a);
  b = simde_x_mm_loadu_epi32(test_vec[2].b);
  c = simde_x_mm_loadu_epi32(test_vec[2].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         114));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[2].r));

  a = simde_x_mm_loadu_epi32(test_vec[3].a);
  b = simde_x_mm_loadu_epi32(test_vec[3].b);
  c = simde_x_mm_loadu_epi32(test_vec[3].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         115));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[3].r));

  a = simde_x_mm_loadu_epi32(test_vec[4].a);
  b = simde_x_mm_loadu_epi32(test_vec[4].b);
  c = simde_x_mm_loadu_epi32(test_vec[4].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         116));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[4].r));

  a = simde_x_mm_loadu_epi32(test_vec[5].a);
  b = simde_x_mm_loadu_epi32(test_vec[5].b);
  c = simde_x_mm_loadu_epi32(test_vec[5].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         117));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[5].r));

  a = simde_x_mm_loadu_epi32(test_vec[6].a);
  b = simde_x_mm_loadu_epi32(test_vec[6].b);
  c = simde_x_mm_loadu_epi32(test_vec[6].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         118));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[6].r));

  a = simde_x_mm_loadu_epi32(test_vec[7].a);
  b = simde_x_mm_loadu_epi32(test_vec[7].b);
  c = simde_x_mm_loadu_epi32(test_vec[7].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         119));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[7].r));

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 96 ; i < 128 ; i++) {
    simde__m128i a = simde_test_x86_random_i32x4();
    simde__m128i b = simde_test_x86_random_i32x4();
    simde__m128i c = simde_test_x86_random_i32x4();
    simde__m128i r;
    SIMDE_CONSTIFY_32_4(simde_mm_ternarylogic_epi32, r, simde_mm_setzero_si128(), i, a, b, c);

    simde_test_x86_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, i, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_ternarylogic_epi32_16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t a[4];
    const int32_t b[4];
    const int32_t c[4];
    const int32_t imm8;
    const int32_t r[4];
  } test_vec[] = {
    { {  INT32_C(   430550046), -INT32_C(   713025645),  INT32_C(   637601556), -INT32_C(  1339987747) },
      { -INT32_C(   409818879),  INT32_C(  1094983150),  INT32_C(  1036938515),  INT32_C(  1442131766) },
      {  INT32_C(  1852743387), -INT32_C(   918294859), -INT32_C(   756005387), -INT32_C(  1367141971) },
       INT32_C(         120),
      {  INT32_C(  2141922335), -INT32_C(  1799349449),  INT32_C(   918635013), -INT32_C(  1264555527) } },
    { { -INT32_C(  1449781829),  INT32_C(  1189796402),  INT32_C(  2122561608), -INT32_C(  1009551129) },
      { -INT32_C(   885964522),  INT32_C(   630551855),  INT32_C(  1744274874),  INT32_C(  1360427670) },
      { -INT32_C(  1023759216), -INT32_C(   838277754), -INT32_C(  2058515299),  INT32_C(   457711620) },
       INT32_C(         121),
      {  INT32_C(  2141591531),  INT32_C(  1391116148),  INT32_C(  2076606160), -INT32_C(   151790101) } },
    { { -INT32_C(  1847166622), -INT32_C(  1464435730), -INT32_C(  1760514560), -INT32_C(  1192745432) },
      {  INT32_C(  1484514258),  INT32_C(  1697088456),  INT32_C(   350909455), -INT32_C(   164679020) },
      { -INT32_C(  1702357588), -INT32_C(  1857864047),  INT32_C(   354964460),  INT32_C(  1271730553) },
       INT32_C(         122),
      { -INT32_C(  1947304722), -INT32_C(  1175093889), -INT32_C(  2093416468), -INT32_C(    68864135) } },
    { { -INT32_C(  1130149644), -INT32_C(   618542388), -INT32_C(   739308482), -INT32_C(   355918274) },
      { -INT32_C(   981118668),  INT32_C(  2086062224), -INT32_C(  1802404069), -INT32_C(  2065735792) },
      {  INT32_C(  1933607591), -INT32_C(  1957732019), -INT32_C(  1403109779), -INT32_C(  1852430243) },
       INT32_C(         123),
      { -INT32_C(      266533), -INT32_C(   739262481),  INT32_C(  2147463927),  INT32_C(  2071967343) } },
    { {  INT32_C(   156638073), -INT32_C(    24728349), -INT32_C(  1148053717),  INT32_C(   507474294) },
      {  INT32_C(  1100054516),  INT32_C(  1322049761),  INT32_C(  2096769823), -INT32_C(   871526061) },
      { -INT32_C(  1864997972),  INT32_C(   999185423), -INT32_C(   352968333), -INT32_C(  2046282094) },
       INT32_C(         124),
      {  INT32_C(  1237810397), -INT32_C(   196416286), -INT32_C(   681034180), -INT32_C(   633872027) } },
    { { -INT32_C(  1765303883), -INT32_C(  1713007494),  INT32_C(   303423423),  INT32_C(   501097072) },
      { -INT32_C(  1800555387), -INT32_C(  2066793712), -INT32_C(   277952932), -INT32_C(  1317701892) },
      { -INT32_C(  1991754481), -INT32_C(  1876808239),  INT32_C(  2107782924), -INT32_C(   560299943) },
       INT32_C(         125),
      {  INT32_C(  1996484592),  INT32_C(  2147483502), -INT32_C(     8398349), -INT32_C(  1376813138) } },
    { {  INT32_C(  1165182773), -INT32_C(   540458366),  INT32_C(    80623368), -INT32_C(  1112128595) },
      {  INT32_C(  1363607168),  INT32_C(   937519403), -INT32_C(    88833120),  INT32_C(   970477060) },
      {  INT32_C(   410930069), -INT32_C(  1762178930),  INT32_C(   765183359), -INT32_C(  1981132536) },
       INT32_C(         126),
      {  INT32_C(  1564327349), -INT32_C(   381801555), -INT32_C(     8390913), -INT32_C(  1266802771) } },
    { {  INT32_C(  2061119567),  INT32_C(   984726681),  INT32_C(  1127507519),  INT32_C(  1249643700) },
      { -INT32_C(   429720744), -INT32_C(  1032038077),  INT32_C(   653203230), -INT32_C(  1213212312) },
      { -INT32_C(  1557034486), -INT32_C(  2049055930), -INT32_C(    37154487),  INT32_C(  1984382238) },
       INT32_C(         127),
      { -INT32_C(   570425353), -INT32_C(     1048577), -INT32_C(           9), -INT32_C(    33816577) } },
  };

  simde__m128i a, b, c, r;

  a = simde_x_mm_loadu_epi32(test_vec[0].a);
  b = simde_x_mm_loadu_epi32(test_vec[0].b);
  c = simde_x_mm_loadu_epi32(test_vec[0].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         120));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[0].r));

  a = simde_x_mm_loadu_epi32(test_vec[1].a);
  b = simde_x_mm_loadu_epi32(test_vec[1].b);
  c = simde_x_mm_loadu_epi32(test_vec[1].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         121));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[1].r));

  a = simde_x_mm_loadu_epi32(test_vec[2].a);
  b = simde_x_mm_loadu_epi32(test_vec[2].b);
  c = simde_x_mm_loadu_epi32(test_vec[2].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         122));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[2].r));

  a = simde_x_mm_loadu_epi32(test_vec[3].a);
  b = simde_x_mm_loadu_epi32(test_vec[3].b);
  c = simde_x_mm_loadu_epi32(test_vec[3].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         123));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[3].r));

  a = simde_x_mm_loadu_epi32(test_vec[4].a);
  b = simde_x_mm_loadu_epi32(test_vec[4].b);
  c = simde_x_mm_loadu_epi32(test_vec[4].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         124));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[4].r));

  a = simde_x_mm_loadu_epi32(test_vec[5].a);
  b = simde_x_mm_loadu_epi32(test_vec[5].b);
  c = simde_x_mm_loadu_epi32(test_vec[5].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         125));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[5].r));

  a = simde_x_mm_loadu_epi32(test_vec[6].a);
  b = simde_x_mm_loadu_epi32(test_vec[6].b);
  c = simde_x_mm_loadu_epi32(test_vec[6].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         126));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[6].r));

  a = simde_x_mm_loadu_epi32(test_vec[7].a);
  b = simde_x_mm_loadu_epi32(test_vec[7].b);
  c = simde_x_mm_loadu_epi32(test_vec[7].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         127));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[7].r));

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 96 ; i < 128 ; i++) {
    simde__m128i a = simde_test_x86_random_i32x4();
    simde__m128i b = simde_test_x86_random_i32x4();
    simde__m128i c = simde_test_x86_random_i32x4();
    simde__m128i r;
    SIMDE_CONSTIFY_32_4(simde_mm_ternarylogic_epi32, r, simde_mm_setzero_si128(), i, a, b, c);

    simde_test_x86_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, i, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_ternarylogic_epi32_17 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t a[4];
    const int32_t b[4];
    const int32_t c[4];
    const int32_t imm8;
    const int32_t r[4];
  } test_vec[] = {
    { { -INT32_C(  1087524476),  INT32_C(  1550836167), -INT32_C(  1227814976),  INT32_C(  1965603025) },
      { -INT32_C(   459809561), -INT32_C(   458867619), -INT32_C(   762545526), -INT32_C(  1790103535) },
      { -INT32_C(  1454081310),  INT32_C(   453362779), -INT32_C(  1647192117),  INT32_C(  1980955023) },
       INT32_C(         128),
      { -INT32_C(  1610346368),  INT32_C(      262209), -INT32_C(  1870658944),  INT32_C(   335556609) } },
    { {  INT32_C(   861579733),  INT32_C(  1880556005), -INT32_C(  1941789573), -INT32_C(  1239314476) },
      {  INT32_C(  1700820233),  INT32_C(    92300601), -INT32_C(   878554564),  INT32_C(   557954123) },
      {  INT32_C(  1112841309),  INT32_C(   414346141), -INT32_C(   458951409), -INT32_C(  1902459516) },
       INT32_C(         129),
      { -INT32_C(  2000616925), -INT32_C(  2109173501), -INT32_C(  1877407608),  INT32_C(  1074037792) } },
    { {  INT32_C(  1962146362), -INT32_C(  1669762208),  INT32_C(   292035525),  INT32_C(   741517775) },
      { -INT32_C(   496073147),  INT32_C(    33169905), -INT32_C(  1696227818), -INT32_C(  1641513117) },
      { -INT32_C(   636347526),  INT32_C(  1417055119),  INT32_C(  1969610406), -INT32_C(   845047928) },
       INT32_C(         130),
      {  INT32_C(  1208091392),  INT32_C(  1081379086),  INT32_C(  1952471588),  INT32_C(  1302397184) } },
    { {  INT32_C(   263196445),  INT32_C(  1175497264), -INT32_C(  1394477751), -INT32_C(   297137804) },
      { -INT32_C(  1261937627), -INT32_C(  1928839193), -INT32_C(  1526567395),  INT32_C(   594780933) },
      { -INT32_C(   483253325),  INT32_C(   371868365), -INT32_C(  1413280969),  INT32_C(   966397204) },
       INT32_C(         131),
      {  INT32_C(  1074241731),  INT32_C(   887570952), -INT32_C(   233045853),  INT32_C(   814110094) } },
    { {  INT32_C(  1374511722), -INT32_C(  1075841375),  INT32_C(  1768218980),  INT32_C(   948754309) },
      { -INT32_C(   937705734),  INT32_C(   937313536),  INT32_C(  1709416784),  INT32_C(   429817263) },
      { -INT32_C(  2123723553), -INT32_C(   431994494), -INT32_C(  1336957909),  INT32_C(  1994972284) },
       INT32_C(         132),
      {  INT32_C(   135794762),  INT32_C(   641744896),  INT32_C(   616603664),  INT32_C(   295334918) } },
    { { -INT32_C(  1690434662), -INT32_C(  1714283191),  INT32_C(  1845409214),  INT32_C(   310811954) },
      { -INT32_C(  1416367831),  INT32_C(  1704055610), -INT32_C(   216670089),  INT32_C(  1466629564) },
      {  INT32_C(  1257416705), -INT32_C(  2065447739), -INT32_C(  1393433990), -INT32_C(  1463912321) },
       INT32_C(         133),
      {  INT32_C(   773018724),  INT32_C(  1653350962),  INT32_C(   839952435),  INT32_C(  1162025648) } },
    { { -INT32_C(  1554820759), -INT32_C(  1677073372), -INT32_C(  2121326908),  INT32_C(   500758812) },
      {  INT32_C(  1734855330),  INT32_C(   149637774), -INT32_C(  1414144724), -INT32_C(  1101827243) },
      { -INT32_C(   379476283),  INT32_C(  1334143626), -INT32_C(  1513089655), -INT32_C(  1329420274) },
       INT32_C(         134),
      {  INT32_C(   759507974),  INT32_C(  1265057792), -INT32_C(  1881091039),  INT32_C(   306258503) } },
    { {  INT32_C(     1583474), -INT32_C(  1610022029),  INT32_C(   894156512), -INT32_C(   151806159) },
      { -INT32_C(   790604475),  INT32_C(  1210017215), -INT32_C(  1980895366),  INT32_C(   154775447) },
      {  INT32_C(  1275679192),  INT32_C(   904663637),  INT32_C(    40581072),  INT32_C(   486039254) },
       INT32_C(         135),
      { -INT32_C(  1075345459),  INT32_C(  1610284185), -INT32_C(   891460017),  INT32_C(    20213336) } },
  };

  simde__m128i a, b, c, r;

  a = simde_x_mm_loadu_epi32(test_vec[0].a);
  b = simde_x_mm_loadu_epi32(test_vec[0].b);
  c = simde_x_mm_loadu_epi32(test_vec[0].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         128));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[0].r));

  a = simde_x_mm_loadu_epi32(test_vec[1].a);
  b = simde_x_mm_loadu_epi32(test_vec[1].b);
  c = simde_x_mm_loadu_epi32(test_vec[1].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         129));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[1].r));

  a = simde_x_mm_loadu_epi32(test_vec[2].a);
  b = simde_x_mm_loadu_epi32(test_vec[2].b);
  c = simde_x_mm_loadu_epi32(test_vec[2].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         130));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[2].r));

  a = simde_x_mm_loadu_epi32(test_vec[3].a);
  b = simde_x_mm_loadu_epi32(test_vec[3].b);
  c = simde_x_mm_loadu_epi32(test_vec[3].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         131));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[3].r));

  a = simde_x_mm_loadu_epi32(test_vec[4].a);
  b = simde_x_mm_loadu_epi32(test_vec[4].b);
  c = simde_x_mm_loadu_epi32(test_vec[4].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         132));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[4].r));

  a = simde_x_mm_loadu_epi32(test_vec[5].a);
  b = simde_x_mm_loadu_epi32(test_vec[5].b);
  c = simde_x_mm_loadu_epi32(test_vec[5].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         133));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[5].r));

  a = simde_x_mm_loadu_epi32(test_vec[6].a);
  b = simde_x_mm_loadu_epi32(test_vec[6].b);
  c = simde_x_mm_loadu_epi32(test_vec[6].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         134));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[6].r));

  a = simde_x_mm_loadu_epi32(test_vec[7].a);
  b = simde_x_mm_loadu_epi32(test_vec[7].b);
  c = simde_x_mm_loadu_epi32(test_vec[7].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         135));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[7].r));

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 128 ; i < (128 + 32) ; i++) {
    simde__m128i a = simde_test_x86_random_i32x4();
    simde__m128i b = simde_test_x86_random_i32x4();
    simde__m128i c = simde_test_x86_random_i32x4();
    simde__m128i r;
    SIMDE_CONSTIFY_32_5(simde_mm_ternarylogic_epi32, r, simde_mm_setzero_si128(), i, a, b, c);

    simde_test_x86_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, i, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_ternarylogic_epi32_18 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t a[4];
    const int32_t b[4];
    const int32_t c[4];
    const int32_t imm8;
    const int32_t r[4];
  } test_vec[] = {
    { {  INT32_C(  1944901811), -INT32_C(  1195701442), -INT32_C(  1857967622),  INT32_C(   832207704) },
      {  INT32_C(   561882060), -INT32_C(  2041091658),  INT32_C(  2005451424), -INT32_C(   728530656) },
      { -INT32_C(  1756922023), -INT32_C(  2075131254),  INT32_C(    68522411), -INT32_C(   650793204) },
       INT32_C(         136),
      {  INT32_C(    21308232), -INT32_C(  2075131774),  INT32_C(    67141792), -INT32_C(   804159232) } },
    { {  INT32_C(   150647378), -INT32_C(  1148235493),  INT32_C(   875697939), -INT32_C(   234306152) },
      { -INT32_C(   829862076), -INT32_C(    44902063),  INT32_C(  1996580715),  INT32_C(  1766864406) },
      {  INT32_C(    57756648), -INT32_C(  1329725284), -INT32_C(  1327173352), -INT32_C(    73208650) },
       INT32_C(         137),
      {  INT32_C(   839207745), -INT32_C(  1340987856),  INT32_C(   940075404),  INT32_C(  1829053527) } },
    { { -INT32_C(  1932972997),  INT32_C(  1888033797), -INT32_C(  1696036221), -INT32_C(  1476183872) },
      {  INT32_C(   548107395), -INT32_C(  1915721099),  INT32_C(   289256539), -INT32_C(   619913056) },
      {  INT32_C(   292017676),  INT32_C(  1971515890),  INT32_C(  1007643259),  INT32_C(   652481186) },
       INT32_C(         138),
      {  INT32_C(   287823364),  INT32_C(    92463602),  INT32_C(   873422971),  INT32_C(   115606178) } },
    { { -INT32_C(    62484345),  INT32_C(  1435047674),  INT32_C(  1785120458), -INT32_C(  1304071258) },
      {  INT32_C(  1002744905),  INT32_C(   430982813),  INT32_C(  1381351600),  INT32_C(  1501051346) },
      { -INT32_C(  1017790775), -INT32_C(  1642537260),  INT32_C(  1258848165),  INT32_C(  1006521842) },
       INT32_C(         139),
      {  INT32_C(    58584953), -INT32_C(  1168707692), -INT32_C(   947357275),  INT32_C(   502959579) } },
    { { -INT32_C(  1753824518), -INT32_C(  1196415480), -INT32_C(  1190525466),  INT32_C(   135430975) },
      {  INT32_C(   382494785), -INT32_C(   340466618),  INT32_C(  1429716323),  INT32_C(    76559626) },
      { -INT32_C(     6551817),  INT32_C(   330779693), -INT32_C(  1848852142), -INT32_C(  2036736188) },
       INT32_C(         140),
      {  INT32_C(   378284097),  INT32_C(  1135920198),  INT32_C(  1429584195),  INT32_C(    76559616) } },
    { { -INT32_C(  1919130297), -INT32_C(  1384558518),  INT32_C(   402894861), -INT32_C(   602106907) },
      { -INT32_C(   941901670),  INT32_C(  1473942021), -INT32_C(  1729583277), -INT32_C(   853638778) },
      {  INT32_C(   828029671),  INT32_C(   417256202),  INT32_C(  1748033923),  INT32_C(   256134261) },
       INT32_C(         141),
      {  INT32_C(  1132181658),  INT32_C(  1390067381), -INT32_C(  1880313997),  INT32_C(   765927438) } },
    { {  INT32_C(   181804805),  INT32_C(    90288305), -INT32_C(   576894633), -INT32_C(  1314210870) },
      {  INT32_C(  2145518965),  INT32_C(  1553449432),  INT32_C(   398772130),  INT32_C(   421923092) },
      { -INT32_C(   635175896),  INT32_C(    81757357), -INT32_C(  1746764595), -INT32_C(  1404466121) },
       INT32_C(         142),
      { -INT32_C(    14424968),  INT32_C(  1553974732),  INT32_C(   400750248),  INT32_C(   205851701) } },
    { {  INT32_C(  1781214097), -INT32_C(  1882799124), -INT32_C(  1633252726), -INT32_C(  1128804973) },
      {  INT32_C(  1989597897),  INT32_C(   729511262),  INT32_C(   683892209),  INT32_C(  2077494505) },
      {  INT32_C(   619052855),  INT32_C(  1303620546), -INT32_C(   907323083), -INT32_C(   259677402) },
       INT32_C(         143),
      { -INT32_C(  1244340625),  INT32_C(  2033925459),  INT32_C(  1775992181),  INT32_C(  1942762092) } },
  };

  simde__m128i a, b, c, r;

  a = simde_x_mm_loadu_epi32(test_vec[0].a);
  b = simde_x_mm_loadu_epi32(test_vec[0].b);
  c = simde_x_mm_loadu_epi32(test_vec[0].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         136));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[0].r));

  a = simde_x_mm_loadu_epi32(test_vec[1].a);
  b = simde_x_mm_loadu_epi32(test_vec[1].b);
  c = simde_x_mm_loadu_epi32(test_vec[1].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         137));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[1].r));

  a = simde_x_mm_loadu_epi32(test_vec[2].a);
  b = simde_x_mm_loadu_epi32(test_vec[2].b);
  c = simde_x_mm_loadu_epi32(test_vec[2].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         138));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[2].r));

  a = simde_x_mm_loadu_epi32(test_vec[3].a);
  b = simde_x_mm_loadu_epi32(test_vec[3].b);
  c = simde_x_mm_loadu_epi32(test_vec[3].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         139));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[3].r));

  a = simde_x_mm_loadu_epi32(test_vec[4].a);
  b = simde_x_mm_loadu_epi32(test_vec[4].b);
  c = simde_x_mm_loadu_epi32(test_vec[4].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         140));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[4].r));

  a = simde_x_mm_loadu_epi32(test_vec[5].a);
  b = simde_x_mm_loadu_epi32(test_vec[5].b);
  c = simde_x_mm_loadu_epi32(test_vec[5].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         141));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[5].r));

  a = simde_x_mm_loadu_epi32(test_vec[6].a);
  b = simde_x_mm_loadu_epi32(test_vec[6].b);
  c = simde_x_mm_loadu_epi32(test_vec[6].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         142));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[6].r));

  a = simde_x_mm_loadu_epi32(test_vec[7].a);
  b = simde_x_mm_loadu_epi32(test_vec[7].b);
  c = simde_x_mm_loadu_epi32(test_vec[7].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         143));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[7].r));

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 128 ; i < (128 + 32) ; i++) {
    simde__m128i a = simde_test_x86_random_i32x4();
    simde__m128i b = simde_test_x86_random_i32x4();
    simde__m128i c = simde_test_x86_random_i32x4();
    simde__m128i r;
    SIMDE_CONSTIFY_32_5(simde_mm_ternarylogic_epi32, r, simde_mm_setzero_si128(), i, a, b, c);

    simde_test_x86_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, i, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_ternarylogic_epi32_19 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t a[4];
    const int32_t b[4];
    const int32_t c[4];
    const int32_t imm8;
    const int32_t r[4];
  } test_vec[] = {
    { { -INT32_C(   597288067), -INT32_C(  2130189936),  INT32_C(   682215998),  INT32_C(   245595606) },
      {  INT32_C(  1060276348),  INT32_C(  1754064179),  INT32_C(  1697740606), -INT32_C(  1739213286) },
      {  INT32_C(  1635040209), -INT32_C(   605914211),  INT32_C(   469994310), -INT32_C(  2060802552) },
       INT32_C(         144),
      { -INT32_C(  2145384368),  INT32_C(       90384),  INT32_C(     8978950),  INT32_C(    41971140) } },
    { {  INT32_C(  1640258606), -INT32_C(  2134224831), -INT32_C(   488244281), -INT32_C(  2089141582) },
      { -INT32_C(  1830424843), -INT32_C(  1351694487),  INT32_C(  1540125011),  INT32_C(  1189148184) },
      { -INT32_C(  1800887213), -INT32_C(  1139510540),  INT32_C(   530512237),  INT32_C(   698554419) },
       INT32_C(         145),
      {  INT32_C(  1771181320), -INT32_C(  1065269182), -INT32_C(  1566214207), -INT32_C(  1875111468) } },
    { {  INT32_C(  1874561030), -INT32_C(  1575016113), -INT32_C(  1275139173),  INT32_C(   888790753) },
      {  INT32_C(  2009702787), -INT32_C(  2127307501),  INT32_C(   178311639), -INT32_C(   281852951) },
      {  INT32_C(   459272139), -INT32_C(  1279427048),  INT32_C(  1248246633),  INT32_C(   494887066) },
       INT32_C(         146),
      {  INT32_C(    53331534), -INT32_C(  1869542844), -INT32_C(   214400735),  INT32_C(    79035538) } },
    { {  INT32_C(   362039297), -INT32_C(    57227227), -INT32_C(  2096679271),  INT32_C(  1165113978) },
      {  INT32_C(  1113641257), -INT32_C(  1191895473),  INT32_C(  1929600217), -INT32_C(  1114602820) },
      { -INT32_C(   271440438), -INT32_C(  2031326995),  INT32_C(   420082591),  INT32_C(  1465809965) },
       INT32_C(         147),
      { -INT32_C(  1206964522), -INT32_C(  1014060651), -INT32_C(  1912761921),  INT32_C(   121455979) } },
    { { -INT32_C(  1650868403), -INT32_C(  1235906851), -INT32_C(  1507174166), -INT32_C(  1536902438) },
      { -INT32_C(   862701857),  INT32_C(  1045659807), -INT32_C(  1604887437),  INT32_C(   653768152) },
      {  INT32_C(  1371770996),  INT32_C(   151525407),  INT32_C(  1269838449), -INT32_C(   856681236) },
       INT32_C(         148),
      {  INT32_C(     9181638), -INT32_C(  2147088803),  INT32_C(    72160488),  INT32_C(   107158474) } },
    { { -INT32_C(   375880630),  INT32_C(  1999104772),  INT32_C(   538410568), -INT32_C(  1471803596) },
      { -INT32_C(  1090909793), -INT32_C(  1815608798),  INT32_C(   551450676), -INT32_C(   689123700) },
      {  INT32_C(  1455457618), -INT32_C(  1194465424), -INT32_C(  1696995994), -INT32_C(  1824382988) },
       INT32_C(         149),
      {  INT32_C(    27753127),  INT32_C(  1412569743),  INT32_C(  1160798873), -INT32_C(   319164913) } },
    { {  INT32_C(  1263680553),  INT32_C(  1927158334),  INT32_C(   512998546), -INT32_C(   571179125) },
      {  INT32_C(  1966388228),  INT32_C(    36503964), -INT32_C(   627308826),  INT32_C(  1332665894) },
      {  INT32_C(  1503313947),  INT32_C(  1825339610), -INT32_C(  1081450700), -INT32_C(   476217634) },
       INT32_C(         150),
      {  INT32_C(  1744586806),  INT32_C(   473916280),  INT32_C(  2072372544),  INT32_C(  1896341363) } },
    { { -INT32_C(   816262861), -INT32_C(  1177451054), -INT32_C(  1298961012),  INT32_C(  1711341899) },
      { -INT32_C(  1681876031),  INT32_C(  1191676947), -INT32_C(   922250773),  INT32_C(  1135387664) },
      {  INT32_C(  1192363125),  INT32_C(   369157002), -INT32_C(  1681353648),  INT32_C(  1459800469) },
       INT32_C(         151),
      {  INT32_C(   867135119), -INT32_C(   385942929), -INT32_C(   461608393), -INT32_C(    83919122) } },
  };

  simde__m128i a, b, c, r;

  a = simde_x_mm_loadu_epi32(test_vec[0].a);
  b = simde_x_mm_loadu_epi32(test_vec[0].b);
  c = simde_x_mm_loadu_epi32(test_vec[0].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         144));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[0].r));

  a = simde_x_mm_loadu_epi32(test_vec[1].a);
  b = simde_x_mm_loadu_epi32(test_vec[1].b);
  c = simde_x_mm_loadu_epi32(test_vec[1].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         145));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[1].r));

  a = simde_x_mm_loadu_epi32(test_vec[2].a);
  b = simde_x_mm_loadu_epi32(test_vec[2].b);
  c = simde_x_mm_loadu_epi32(test_vec[2].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         146));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[2].r));

  a = simde_x_mm_loadu_epi32(test_vec[3].a);
  b = simde_x_mm_loadu_epi32(test_vec[3].b);
  c = simde_x_mm_loadu_epi32(test_vec[3].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         147));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[3].r));

  a = simde_x_mm_loadu_epi32(test_vec[4].a);
  b = simde_x_mm_loadu_epi32(test_vec[4].b);
  c = simde_x_mm_loadu_epi32(test_vec[4].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         148));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[4].r));

  a = simde_x_mm_loadu_epi32(test_vec[5].a);
  b = simde_x_mm_loadu_epi32(test_vec[5].b);
  c = simde_x_mm_loadu_epi32(test_vec[5].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         149));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[5].r));

  a = simde_x_mm_loadu_epi32(test_vec[6].a);
  b = simde_x_mm_loadu_epi32(test_vec[6].b);
  c = simde_x_mm_loadu_epi32(test_vec[6].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         150));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[6].r));

  a = simde_x_mm_loadu_epi32(test_vec[7].a);
  b = simde_x_mm_loadu_epi32(test_vec[7].b);
  c = simde_x_mm_loadu_epi32(test_vec[7].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         151));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[7].r));

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 128 ; i < (128 + 32) ; i++) {
    simde__m128i a = simde_test_x86_random_i32x4();
    simde__m128i b = simde_test_x86_random_i32x4();
    simde__m128i c = simde_test_x86_random_i32x4();
    simde__m128i r;
    SIMDE_CONSTIFY_32_5(simde_mm_ternarylogic_epi32, r, simde_mm_setzero_si128(), i, a, b, c);

    simde_test_x86_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, i, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_ternarylogic_epi32_20 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t a[4];
    const int32_t b[4];
    const int32_t c[4];
    const int32_t imm8;
    const int32_t r[4];
  } test_vec[] = {
    { {  INT32_C(  2012398180),  INT32_C(   968817230), -INT32_C(  1694317173), -INT32_C(   555831447) },
      {  INT32_C(  1025962163),  INT32_C(   592651987),  INT32_C(  1354701754),  INT32_C(  1218953700) },
      { -INT32_C(   775972477),  INT32_C(   520781459), -INT32_C(  1380316093),  INT32_C(  1871419835) },
       INT32_C(         152),
      {  INT32_C(   325489351),  INT32_C(    61253279),  INT32_C(    45795330), -INT32_C(   657217632) } },
    { {  INT32_C(  1571598729), -INT32_C(  1837104936),  INT32_C(    14827291), -INT32_C(  2092398336) },
      { -INT32_C(  1236006877), -INT32_C(   908763514),  INT32_C(   645304427), -INT32_C(  1298857431) },
      { -INT32_C(  1961934157),  INT32_C(  1562284098), -INT32_C(   799211313), -INT32_C(  1387026806) },
       INT32_C(         153),
      { -INT32_C(  1029393041),  INT32_C(  1798582587),  INT32_C(   164917083), -INT32_C(   533111972) } },
    { {  INT32_C(   878946478),  INT32_C(  1912420614), -INT32_C(   224889655),  INT32_C(   698625398) },
      { -INT32_C(  1313491857),  INT32_C(   319804228),  INT32_C(  1575185619), -INT32_C(  1073072366) },
      { -INT32_C(   436965665),  INT32_C(  1884811943), -INT32_C(   597495962), -INT32_C(  1945827812) },
       INT32_C(         154),
      { -INT32_C(   508139937),  INT32_C(   279435941),  INT32_C(  2121989998), -INT32_C(  1516171656) } },
    { { -INT32_C(    29508934),  INT32_C(  1628589197), -INT32_C(   876677703),  INT32_C(   193775916) },
      { -INT32_C(   554598345), -INT32_C(   665958286),  INT32_C(  1404350519),  INT32_C(  1910487734) },
      {  INT32_C(    40836468),  INT32_C(   576946537), -INT32_C(  1544674953),  INT32_C(   565148394) },
       INT32_C(         155),
      {  INT32_C(   593717244),  INT32_C(   133412836),  INT32_C(   803565311), -INT32_C(  1347469341) } },
    { {  INT32_C(  1845469434),  INT32_C(   524635624), -INT32_C(  1267533059),  INT32_C(   673534644) },
      { -INT32_C(   668298129), -INT32_C(  1912894186), -INT32_C(  1724847697),  INT32_C(  1572593507) },
      {  INT32_C(  1741339263),  INT32_C(    92672008), -INT32_C(  1095108342), -INT32_C(  1159274933) },
       INT32_C(         156),
      { -INT32_C(   803236625), -INT32_C(  1749368586), -INT32_C(  1720521894),  INT32_C(  1572528087) } },
    { { -INT32_C(  1986915981),  INT32_C(  1293323678), -INT32_C(   639154570), -INT32_C(  1523080666) },
      {  INT32_C(  1678573916),  INT32_C(   459969297), -INT32_C(   673635444),  INT32_C(  1972486146) },
      {  INT32_C(  1878926545),  INT32_C(   683480241), -INT32_C(  2147376038), -INT32_C(  1574553530) },
       INT32_C(         157),
      { -INT32_C(   200418690), -INT32_C(   563578273), -INT32_C(  1371571799),  INT32_C(  2026391483) } },
    { {  INT32_C(  1258763066),  INT32_C(  1399288262), -INT32_C(  1775615852), -INT32_C(   787760128) },
      { -INT32_C(  1858008608),  INT32_C(  2025455133), -INT32_C(   386352222),  INT32_C(   764026611) },
      {  INT32_C(   410620241), -INT32_C(  1754537982),  INT32_C(   556635424),  INT32_C(   837957969) },
       INT32_C(         158),
      { -INT32_C(   763384885), -INT32_C(  1128402983),  INT32_C(  2147483446), -INT32_C(   302801933) } },
    { {  INT32_C(  1623405378), -INT32_C(   740787151),  INT32_C(   733728823),  INT32_C(  1079527151) },
      { -INT32_C(   631713321), -INT32_C(   764296271), -INT32_C(  1426874791),  INT32_C(   450684375) },
      {  INT32_C(  1249550105),  INT32_C(  1394496027),  INT32_C(   293525794), -INT32_C(   145566177) },
       INT32_C(         159),
      { -INT32_C(      131651),  INT32_C(  2125983711), -INT32_C(   730415156), -INT32_C(  1074266825) } },
  };

  simde__m128i a, b, c, r;

  a = simde_x_mm_loadu_epi32(test_vec[0].a);
  b = simde_x_mm_loadu_epi32(test_vec[0].b);
  c = simde_x_mm_loadu_epi32(test_vec[0].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         152));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[0].r));

  a = simde_x_mm_loadu_epi32(test_vec[1].a);
  b = simde_x_mm_loadu_epi32(test_vec[1].b);
  c = simde_x_mm_loadu_epi32(test_vec[1].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         153));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[1].r));

  a = simde_x_mm_loadu_epi32(test_vec[2].a);
  b = simde_x_mm_loadu_epi32(test_vec[2].b);
  c = simde_x_mm_loadu_epi32(test_vec[2].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         154));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[2].r));

  a = simde_x_mm_loadu_epi32(test_vec[3].a);
  b = simde_x_mm_loadu_epi32(test_vec[3].b);
  c = simde_x_mm_loadu_epi32(test_vec[3].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         155));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[3].r));

  a = simde_x_mm_loadu_epi32(test_vec[4].a);
  b = simde_x_mm_loadu_epi32(test_vec[4].b);
  c = simde_x_mm_loadu_epi32(test_vec[4].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         156));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[4].r));

  a = simde_x_mm_loadu_epi32(test_vec[5].a);
  b = simde_x_mm_loadu_epi32(test_vec[5].b);
  c = simde_x_mm_loadu_epi32(test_vec[5].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         157));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[5].r));

  a = simde_x_mm_loadu_epi32(test_vec[6].a);
  b = simde_x_mm_loadu_epi32(test_vec[6].b);
  c = simde_x_mm_loadu_epi32(test_vec[6].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         158));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[6].r));

  a = simde_x_mm_loadu_epi32(test_vec[7].a);
  b = simde_x_mm_loadu_epi32(test_vec[7].b);
  c = simde_x_mm_loadu_epi32(test_vec[7].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         159));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[7].r));

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 128 ; i < (128 + 32) ; i++) {
    simde__m128i a = simde_test_x86_random_i32x4();
    simde__m128i b = simde_test_x86_random_i32x4();
    simde__m128i c = simde_test_x86_random_i32x4();
    simde__m128i r;
    SIMDE_CONSTIFY_32_5(simde_mm_ternarylogic_epi32, r, simde_mm_setzero_si128(), i, a, b, c);

    simde_test_x86_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, i, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_ternarylogic_epi32_21 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t a[4];
    const int32_t b[4];
    const int32_t c[4];
    const int32_t imm8;
    const int32_t r[4];
  } test_vec[] = {
    { {  INT32_C(  1050740016),  INT32_C(  1196908959),  INT32_C(  1206791218),  INT32_C(  1143400549) },
      {  INT32_C(   915646470), -INT32_C(  1757580098),  INT32_C(  1180550445),  INT32_C(   515907821) },
      { -INT32_C(  1000578779), -INT32_C(   183782461),  INT32_C(  1144912607), -INT32_C(   376871966) },
       INT32_C(         160),
      {  INT32_C(    67109152),  INT32_C(  1157833091),  INT32_C(  1143744530),  INT32_C(  1073766496) } },
    { { -INT32_C(   920708085), -INT32_C(  1117692528),  INT32_C(   251969058),  INT32_C(    70108382) },
      { -INT32_C(   389510875),  INT32_C(   467588156), -INT32_C(  1335878706), -INT32_C(  1986401922) },
      { -INT32_C(  1772963579),  INT32_C(   945009430),  INT32_C(  1346852722),  INT32_C(  1096054043) },
       INT32_C(         161),
      { -INT32_C(  2144183599),  INT32_C(  2017530193),  INT32_C(    10229283),  INT32_C(   839271962) } },
    { {  INT32_C(   992550398), -INT32_C(  1084880911), -INT32_C(  1603291614), -INT32_C(  1524037217) },
      { -INT32_C(   667190078), -INT32_C(  1592750545),  INT32_C(    32659430), -INT32_C(   884848948) },
      {  INT32_C(  1409707107), -INT32_C(  1777116045), -INT32_C(  1305050349),  INT32_C(  1314349196) },
       INT32_C(         162),
      {  INT32_C(   335809635), -INT32_C(  1777118095), -INT32_C(  1306099181),  INT32_C(    68493452) } },
    { {  INT32_C(   187077340),  INT32_C(   128792097),  INT32_C(  1510514573),  INT32_C(  1227181029) },
      {  INT32_C(   714943415), -INT32_C(  1698647673), -INT32_C(  1068632268),  INT32_C(   856597591) },
      {  INT32_C(  1480471607), -INT32_C(   144708758),  INT32_C(  1884383114),  INT32_C(  1773762226) },
       INT32_C(         163),
      { -INT32_C(   597273580),  INT32_C(  1730112120),  INT32_C(  1974601674), -INT32_C(   839822680) } },
    { {  INT32_C(   697587361),  INT32_C(  1002656775), -INT32_C(  1560604597), -INT32_C(   321582667) },
      { -INT32_C(  1488710595), -INT32_C(  1969249281), -INT32_C(  1107628022),  INT32_C(   136754023) },
      {  INT32_C(   288471561),  INT32_C(  1514992911), -INT32_C(  1157806075), -INT32_C(  1884892591) },
       INT32_C(         164),
      { -INT32_C(  2024795627), -INT32_C(  1706010889), -INT32_C(  1476812799), -INT32_C(  1937498093) } },
    { { -INT32_C(   432608538), -INT32_C(  1737435763),  INT32_C(   760572614),  INT32_C(   641039133) },
      {  INT32_C(  1161258806),  INT32_C(  1637844060),  INT32_C(   488414412),  INT32_C(  1437385327) },
      {  INT32_C(   977003437),  INT32_C(  2127735736),  INT32_C(   850077461), -INT32_C(   648420957) },
       INT32_C(         165),
      {  INT32_C(   603125428),  INT32_C(   425558474), -INT32_C(   536759764),  INT32_C(     9659713) } },
    { { -INT32_C(  1541500856), -INT32_C(   536494828), -INT32_C(   906092198), -INT32_C(  1860261148) },
      {  INT32_C(  1187732109),  INT32_C(   465870341),  INT32_C(  1749905605), -INT32_C(  1723750831) },
      {  INT32_C(  1262313271),  INT32_C(  1999389213),  INT32_C(  1212164708),  INT32_C(  1658412756) },
       INT32_C(         166),
      {  INT32_C(   167515570),  INT32_C(  1827422236),  INT32_C(  1749121761),  INT32_C(  1788369605) } },
    { { -INT32_C(  1096244040),  INT32_C(   148466754),  INT32_C(   762324700),  INT32_C(    80130765) },
      {  INT32_C(   776930065), -INT32_C(  1431995578),  INT32_C(  2062738853), -INT32_C(    52638908) },
      { -INT32_C(  1296399249), -INT32_C(   843410448), -INT32_C(  2013648198), -INT32_C(   292830756) },
       INT32_C(         167),
      { -INT32_C(   201466002),  INT32_C(  2141094141), -INT32_C(   713163877),  INT32_C(   397643006) } },
  };

  simde__m128i a, b, c, r;

  a = simde_x_mm_loadu_epi32(test_vec[0].a);
  b = simde_x_mm_loadu_epi32(test_vec[0].b);
  c = simde_x_mm_loadu_epi32(test_vec[0].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         160));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[0].r));

  a = simde_x_mm_loadu_epi32(test_vec[1].a);
  b = simde_x_mm_loadu_epi32(test_vec[1].b);
  c = simde_x_mm_loadu_epi32(test_vec[1].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         161));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[1].r));

  a = simde_x_mm_loadu_epi32(test_vec[2].a);
  b = simde_x_mm_loadu_epi32(test_vec[2].b);
  c = simde_x_mm_loadu_epi32(test_vec[2].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         162));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[2].r));

  a = simde_x_mm_loadu_epi32(test_vec[3].a);
  b = simde_x_mm_loadu_epi32(test_vec[3].b);
  c = simde_x_mm_loadu_epi32(test_vec[3].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         163));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[3].r));

  a = simde_x_mm_loadu_epi32(test_vec[4].a);
  b = simde_x_mm_loadu_epi32(test_vec[4].b);
  c = simde_x_mm_loadu_epi32(test_vec[4].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         164));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[4].r));

  a = simde_x_mm_loadu_epi32(test_vec[5].a);
  b = simde_x_mm_loadu_epi32(test_vec[5].b);
  c = simde_x_mm_loadu_epi32(test_vec[5].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         165));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[5].r));

  a = simde_x_mm_loadu_epi32(test_vec[6].a);
  b = simde_x_mm_loadu_epi32(test_vec[6].b);
  c = simde_x_mm_loadu_epi32(test_vec[6].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         166));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[6].r));

  a = simde_x_mm_loadu_epi32(test_vec[7].a);
  b = simde_x_mm_loadu_epi32(test_vec[7].b);
  c = simde_x_mm_loadu_epi32(test_vec[7].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         167));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[7].r));

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 160 ; i < 192 ; i++) {
    simde__m128i a = simde_test_x86_random_i32x4();
    simde__m128i b = simde_test_x86_random_i32x4();
    simde__m128i c = simde_test_x86_random_i32x4();
    simde__m128i r;
    SIMDE_CONSTIFY_32_6(simde_mm_ternarylogic_epi32, r, simde_mm_setzero_si128(), i, a, b, c);

    simde_test_x86_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, i, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_ternarylogic_epi32_22 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t a[4];
    const int32_t b[4];
    const int32_t c[4];
    const int32_t imm8;
    const int32_t r[4];
  } test_vec[] = {
    { {  INT32_C(   169663172), -INT32_C(    72039850), -INT32_C(   344611161), -INT32_C(   504868495) },
      { -INT32_C(   963403051), -INT32_C(   258781898),  INT32_C(  1417121143),  INT32_C(   323093070) },
      {  INT32_C(   840785628), -INT32_C(   936455648), -INT32_C(   357325960), -INT32_C(   892625931) },
       INT32_C(         168),
      {  INT32_C(    35478228), -INT32_C(   936984032), -INT32_C(   365714576), -INT32_C(  1026944139) } },
    { {  INT32_C(  1955618366),  INT32_C(   576988075), -INT32_C(     8987727), -INT32_C(  1189955363) },
      {  INT32_C(   938225687),  INT32_C(  2063538690), -INT32_C(  1302023235), -INT32_C(  1937952946) },
      {  INT32_C(   939527565), -INT32_C(   497327055),  INT32_C(   484561215), -INT32_C(  1579748214) },
       INT32_C(         169),
      { -INT32_C(  1341944755),  INT32_C(  1734058085),  INT32_C(   476632445), -INT32_C(   480856918) } },
    { {  INT32_C(   651739684), -INT32_C(  1717511972), -INT32_C(   649329269), -INT32_C(  1033451212) },
      {  INT32_C(   133850838),  INT32_C(   183064011), -INT32_C(  1322792153), -INT32_C(   481100353) },
      { -INT32_C(  1693898049), -INT32_C(  1925928702), -INT32_C(   479756114),  INT32_C(   547736905) },
       INT32_C(         170),
      { -INT32_C(  1693898049), -INT32_C(  1925928702), -INT32_C(   479756114),  INT32_C(   547736905) } },
    { { -INT32_C(    30957773),  INT32_C(   470356469), -INT32_C(  1681051428), -INT32_C(   327278803) },
      {  INT32_C(  1283950409), -INT32_C(   539378896), -INT32_C(  2050867140),  INT32_C(  1101358861) },
      { -INT32_C(    79704826), -INT32_C(  1172879138), -INT32_C(  1521097608),  INT32_C(  1301402371) },
       INT32_C(         171),
      { -INT32_C(    75502202), -INT32_C(  1170780962), -INT32_C(   445255813),  INT32_C(  1603392467) } },
    { { -INT32_C(  1969678246),  INT32_C(   275346132), -INT32_C(  1063965773), -INT32_C(  1727972462) },
      { -INT32_C(   426491640),  INT32_C(    44084361), -INT32_C(  1800931952),  INT32_C(   585185736) },
      {  INT32_C(   632060497), -INT32_C(  1623910676), -INT32_C(   731854015),  INT32_C(   242049286) },
       INT32_C(         172),
      {  INT32_C(  1686919504),  INT32_C(   312581837), -INT32_C(   735912191),  INT32_C(   719397194) } },
    { {  INT32_C(   754188706),  INT32_C(  1043240109),  INT32_C(  1372771721),  INT32_C(  1618195214) },
      {  INT32_C(   428154669),  INT32_C(  2008660789), -INT32_C(  1941235322),  INT32_C(   496679034) },
      {  INT32_C(  1732873913), -INT32_C(  1415219422),  INT32_C(  1543272268),  INT32_C(  1471901482) },
       INT32_C(         173),
      { -INT32_C(  1253867795),  INT32_C(  1811234672), -INT32_C(    36086466), -INT32_C(   574673925) } },
    { { -INT32_C(   999276402), -INT32_C(  2126829061), -INT32_C(  1123187134), -INT32_C(   136665282) },
      {  INT32_C(  1465787189), -INT32_C(   436075622), -INT32_C(  1539178886), -INT32_C(    50594707) },
      {  INT32_C(   952134717), -INT32_C(   658834539), -INT32_C(  1080703103), -INT32_C(  1531547793) },
       INT32_C(         174),
      {  INT32_C(  1003384637), -INT32_C(    21300331), -INT32_C(  1076494407), -INT32_C(  1397260433) } },
    { {  INT32_C(   754718098), -INT32_C(  1827471848),  INT32_C(  1782011133), -INT32_C(  1922682032) },
      {  INT32_C(   885401247), -INT32_C(  1576239071), -INT32_C(  1235115705), -INT32_C(  1571088368) },
      {  INT32_C(  1171150637),  INT32_C(  1389945173), -INT32_C(  2051207115), -INT32_C(   502062269) },
       INT32_C(         175),
      { -INT32_C(   674234515),  INT32_C(  2130567671), -INT32_C(  1778533577), -INT32_C(   224661521) } },
  };

  simde__m128i a, b, c, r;

  a = simde_x_mm_loadu_epi32(test_vec[0].a);
  b = simde_x_mm_loadu_epi32(test_vec[0].b);
  c = simde_x_mm_loadu_epi32(test_vec[0].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         168));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[0].r));

  a = simde_x_mm_loadu_epi32(test_vec[1].a);
  b = simde_x_mm_loadu_epi32(test_vec[1].b);
  c = simde_x_mm_loadu_epi32(test_vec[1].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         169));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[1].r));

  a = simde_x_mm_loadu_epi32(test_vec[2].a);
  b = simde_x_mm_loadu_epi32(test_vec[2].b);
  c = simde_x_mm_loadu_epi32(test_vec[2].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         170));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[2].r));

  a = simde_x_mm_loadu_epi32(test_vec[3].a);
  b = simde_x_mm_loadu_epi32(test_vec[3].b);
  c = simde_x_mm_loadu_epi32(test_vec[3].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         171));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[3].r));

  a = simde_x_mm_loadu_epi32(test_vec[4].a);
  b = simde_x_mm_loadu_epi32(test_vec[4].b);
  c = simde_x_mm_loadu_epi32(test_vec[4].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         172));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[4].r));

  a = simde_x_mm_loadu_epi32(test_vec[5].a);
  b = simde_x_mm_loadu_epi32(test_vec[5].b);
  c = simde_x_mm_loadu_epi32(test_vec[5].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         173));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[5].r));

  a = simde_x_mm_loadu_epi32(test_vec[6].a);
  b = simde_x_mm_loadu_epi32(test_vec[6].b);
  c = simde_x_mm_loadu_epi32(test_vec[6].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         174));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[6].r));

  a = simde_x_mm_loadu_epi32(test_vec[7].a);
  b = simde_x_mm_loadu_epi32(test_vec[7].b);
  c = simde_x_mm_loadu_epi32(test_vec[7].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         175));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[7].r));

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 160 ; i < 192 ; i++) {
    simde__m128i a = simde_test_x86_random_i32x4();
    simde__m128i b = simde_test_x86_random_i32x4();
    simde__m128i c = simde_test_x86_random_i32x4();
    simde__m128i r;
    SIMDE_CONSTIFY_32_6(simde_mm_ternarylogic_epi32, r, simde_mm_setzero_si128(), i, a, b, c);

    simde_test_x86_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, i, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_ternarylogic_epi32_23 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t a[4];
    const int32_t b[4];
    const int32_t c[4];
    const int32_t imm8;
    const int32_t r[4];
  } test_vec[] = {
    { {  INT32_C(  1796659530), -INT32_C(  1609686183), -INT32_C(   715690044), -INT32_C(  1267223929) },
      {  INT32_C(  1593460233),  INT32_C(  1555157543),  INT32_C(   635530978), -INT32_C(   620235631) },
      {  INT32_C(   642195149),  INT32_C(    96949569),  INT32_C(  1289363140), -INT32_C(   654290224) },
       INT32_C(         176),
      {  INT32_C(   587635018), -INT32_C(  1609686695), -INT32_C(   732557372), -INT32_C(  1267723642) } },
    { { -INT32_C(  1086850408), -INT32_C(  1357125427), -INT32_C(   388629418), -INT32_C(  1094460175) },
      {  INT32_C(  1004866298),  INT32_C(   608283743), -INT32_C(  1703928886),  INT32_C(    91451501) },
      {  INT32_C(   952412779), -INT32_C(   370679917), -INT32_C(   841892644), -INT32_C(  1819568743) },
       INT32_C(         177),
      { -INT32_C(    65077492), -INT32_C(  1155807071), -INT32_C(   387974027), -INT32_C(    91775341) } },
    { { -INT32_C(     3182433), -INT32_C(   433909732), -INT32_C(  1719626965),  INT32_C(  1855910659) },
      {  INT32_C(   832988062),  INT32_C(   505056834), -INT32_C(   471077814),  INT32_C(   544700289) },
      {  INT32_C(    69158631), -INT32_C(  2115354026), -INT32_C(   652579883), -INT32_C(    62408354) },
       INT32_C(         178),
      { -INT32_C(   832613145), -INT32_C(   505196516), -INT32_C(  1726999627), -INT32_C(    24200866) } },
    { {  INT32_C(  1580068380), -INT32_C(   964867972), -INT32_C(  1247123404), -INT32_C(   942333473) },
      { -INT32_C(  1110706841),  INT32_C(   222213431),  INT32_C(  2145802528),  INT32_C(   779824402) },
      { -INT32_C(  1752389349),  INT32_C(   626919921),  INT32_C(  1373243506), -INT32_C(  1877430487) },
       INT32_C(         179),
      {  INT32_C(  1446816408), -INT32_C(   153269512), -INT32_C(  1852068097), -INT32_C(   778767379) } },
    { { -INT32_C(   598875228), -INT32_C(  1175876711), -INT32_C(   164048924),  INT32_C(   405058812) },
      {  INT32_C(  1320137053),  INT32_C(   745737658),  INT32_C(  1048464661), -INT32_C(  1580296452) },
      {  INT32_C(   326966138), -INT32_C(  1949538649),  INT32_C(   830604597),  INT32_C(   373925561) },
       INT32_C(         180),
      { -INT32_C(  1865464927), -INT32_C(  1646624127), -INT32_C(   129726492), -INT32_C(  1180523336) } },
    { {  INT32_C(   308607319),  INT32_C(   473880326),  INT32_C(   542817316), -INT32_C(   842978989) },
      { -INT32_C(   337625532), -INT32_C(   646468444),  INT32_C(  1779169713), -INT32_C(   142584673) },
      {  INT32_C(  1409934413), -INT32_C(   546289733),  INT32_C(  1459669508),  INT32_C(   941933043) },
       INT32_C(         181),
      { -INT32_C(  1181293577),  INT32_C(  1018789698), -INT32_C(  1997173281),  INT32_C(   173752159) } },
    { { -INT32_C(  1541209088),  INT32_C(  1652464304),  INT32_C(   869042579),  INT32_C(   724192733) },
      { -INT32_C(   310430927),  INT32_C(  2127359866), -INT32_C(  1378497351), -INT32_C(  1897530994) },
      { -INT32_C(  1372452611),  INT32_C(   907063459),  INT32_C(   392813625),  INT32_C(  1531089705) },
       INT32_C(         182),
      { -INT32_C(   412205108),  INT32_C(   716363241), -INT32_C(  1686595309), -INT32_C(     7395461) } },
    { {  INT32_C(  1095287238),  INT32_C(  1774130352),  INT32_C(  1863751137), -INT32_C(  1929512050) },
      { -INT32_C(  1489359100),  INT32_C(   433933024),  INT32_C(  1345341222), -INT32_C(  1582599462) },
      { -INT32_C(   471665869), -INT32_C(   397565689), -INT32_C(   984128714),  INT32_C(  1666274399) },
       INT32_C(         183),
      {  INT32_C(  1574297083), -INT32_C(    30408865), -INT32_C(       17927),  INT32_C(  1582816559) } },
  };

  simde__m128i a, b, c, r;

  a = simde_x_mm_loadu_epi32(test_vec[0].a);
  b = simde_x_mm_loadu_epi32(test_vec[0].b);
  c = simde_x_mm_loadu_epi32(test_vec[0].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         176));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[0].r));

  a = simde_x_mm_loadu_epi32(test_vec[1].a);
  b = simde_x_mm_loadu_epi32(test_vec[1].b);
  c = simde_x_mm_loadu_epi32(test_vec[1].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         177));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[1].r));

  a = simde_x_mm_loadu_epi32(test_vec[2].a);
  b = simde_x_mm_loadu_epi32(test_vec[2].b);
  c = simde_x_mm_loadu_epi32(test_vec[2].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         178));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[2].r));

  a = simde_x_mm_loadu_epi32(test_vec[3].a);
  b = simde_x_mm_loadu_epi32(test_vec[3].b);
  c = simde_x_mm_loadu_epi32(test_vec[3].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         179));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[3].r));

  a = simde_x_mm_loadu_epi32(test_vec[4].a);
  b = simde_x_mm_loadu_epi32(test_vec[4].b);
  c = simde_x_mm_loadu_epi32(test_vec[4].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         180));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[4].r));

  a = simde_x_mm_loadu_epi32(test_vec[5].a);
  b = simde_x_mm_loadu_epi32(test_vec[5].b);
  c = simde_x_mm_loadu_epi32(test_vec[5].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         181));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[5].r));

  a = simde_x_mm_loadu_epi32(test_vec[6].a);
  b = simde_x_mm_loadu_epi32(test_vec[6].b);
  c = simde_x_mm_loadu_epi32(test_vec[6].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         182));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[6].r));

  a = simde_x_mm_loadu_epi32(test_vec[7].a);
  b = simde_x_mm_loadu_epi32(test_vec[7].b);
  c = simde_x_mm_loadu_epi32(test_vec[7].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         183));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[7].r));

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 160 ; i < 192 ; i++) {
    simde__m128i a = simde_test_x86_random_i32x4();
    simde__m128i b = simde_test_x86_random_i32x4();
    simde__m128i c = simde_test_x86_random_i32x4();
    simde__m128i r;
    SIMDE_CONSTIFY_32_6(simde_mm_ternarylogic_epi32, r, simde_mm_setzero_si128(), i, a, b, c);

    simde_test_x86_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, i, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_ternarylogic_epi32_24 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t a[4];
    const int32_t b[4];
    const int32_t c[4];
    const int32_t imm8;
    const int32_t r[4];
  } test_vec[] = {
    { {  INT32_C(  1678412676), -INT32_C(    75634731),  INT32_C(   155954734),  INT32_C(  1420490272) },
      { -INT32_C(   248017687),  INT32_C(  1691976749),  INT32_C(  1193882088),  INT32_C(   162167429) },
      { -INT32_C(   630344699), -INT32_C(   891950181), -INT32_C(  1177345639),  INT32_C(    17661207) },
       INT32_C(         184),
      { -INT32_C(   735213819), -INT32_C(   604642343),  INT32_C(   155430798),  INT32_C(  1426652197) } },
    { {  INT32_C(   921847049), -INT32_C(  1315255351), -INT32_C(  2097626116),  INT32_C(  1116447293) },
      { -INT32_C(   232982186),  INT32_C(  2109534948),  INT32_C(   708218643),  INT32_C(   355157004) },
      {  INT32_C(  1380654473), -INT32_C(   452663575), -INT32_C(   412615511), -INT32_C(   181800033) },
       INT32_C(         185),
      {  INT32_C(  1609178921), -INT32_C(   414716933), -INT32_C(  1292972819),  INT32_C(  1610476157) } },
    { { -INT32_C(   790149396),  INT32_C(  1263379256),  INT32_C(  1047888690),  INT32_C(  1347658183) },
      { -INT32_C(  1482448962),  INT32_C(   781035397),  INT32_C(  1108735139), -INT32_C(   751288345) },
      { -INT32_C(  1113383035), -INT32_C(   183963453),  INT32_C(   993295732), -INT32_C(   577992930) },
       INT32_C(         186),
      { -INT32_C(    35168315), -INT32_C(   179769093),  INT32_C(  1064599412), -INT32_C(   573602018) } },
    { { -INT32_C(  1417400538),  INT32_C(  2044334550), -INT32_C(   306385146), -INT32_C(  1279134674) },
      { -INT32_C(   697277421), -INT32_C(   909346731),  INT32_C(   335806710), -INT32_C(  1359900537) },
      { -INT32_C(  1789299009), -INT32_C(  1928383609),  INT32_C(  1367067427), -INT32_C(   771408705) },
       INT32_C(         187),
      { -INT32_C(  1109393409), -INT32_C(  1086343249), -INT32_C(    67371221), -INT32_C(   753958913) } },
    { { -INT32_C(   173443680), -INT32_C(   457280018), -INT32_C(    50805899),  INT32_C(   329968211) },
      { -INT32_C(   408419232),  INT32_C(  1517664055),  INT32_C(  1101852802), -INT32_C(   871059156) },
      {  INT32_C(   348306726), -INT32_C(  1476886478), -INT32_C(  1750863549),  INT32_C(  1001017051) },
       INT32_C(         188),
      {  INT32_C(   377583072), -INT32_C(  1090796805), -INT32_C(  1108020233), -INT32_C(   541172865) } },
    { { -INT32_C(  1994239406), -INT32_C(  1931176182), -INT32_C(  1278308217),  INT32_C(  1736499777) },
      { -INT32_C(   780385633),  INT32_C(   108557506),  INT32_C(  1084037989), -INT32_C(  1149548695) },
      { -INT32_C(  1555718503), -INT32_C(  1120917195), -INT32_C(    93258055),  INT32_C(  2137125088) },
       INT32_C(         189),
      { -INT32_C(   572640259), -INT32_C(   826285112), -INT32_C(   145515549), -INT32_C(        4738) } },
    { { -INT32_C(   179249870), -INT32_C(  1208235950),  INT32_C(  1308137699),  INT32_C(  2013819871) },
      {  INT32_C(  1193037073),  INT32_C(   788810870),  INT32_C(   707359818), -INT32_C(  1750496411) },
      { -INT32_C(  1165166232), -INT32_C(  1535998015), -INT32_C(    17733089), -INT32_C(   277349667) },
       INT32_C(         190),
      { -INT32_C(  1160971925), -INT32_C(  1124104219), -INT32_C(      921921), -INT32_C(   268961025) } },
    { { -INT32_C(  1103719609),  INT32_C(   703412959),  INT32_C(   324212654),  INT32_C(   179043490) },
      { -INT32_C(  1228589067), -INT32_C(   564512833),  INT32_C(  2128432289), -INT32_C(  1922214842) },
      { -INT32_C(   968121369), -INT32_C(  1930479139), -INT32_C(   224443824),  INT32_C(   872172094) },
       INT32_C(         191),
      { -INT32_C(   805572609), -INT32_C(         515), -INT32_C(     4195489), -INT32_C(   134288385) } },
  };

  simde__m128i a, b, c, r;

  a = simde_x_mm_loadu_epi32(test_vec[0].a);
  b = simde_x_mm_loadu_epi32(test_vec[0].b);
  c = simde_x_mm_loadu_epi32(test_vec[0].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         184));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[0].r));

  a = simde_x_mm_loadu_epi32(test_vec[1].a);
  b = simde_x_mm_loadu_epi32(test_vec[1].b);
  c = simde_x_mm_loadu_epi32(test_vec[1].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         185));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[1].r));

  a = simde_x_mm_loadu_epi32(test_vec[2].a);
  b = simde_x_mm_loadu_epi32(test_vec[2].b);
  c = simde_x_mm_loadu_epi32(test_vec[2].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         186));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[2].r));

  a = simde_x_mm_loadu_epi32(test_vec[3].a);
  b = simde_x_mm_loadu_epi32(test_vec[3].b);
  c = simde_x_mm_loadu_epi32(test_vec[3].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         187));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[3].r));

  a = simde_x_mm_loadu_epi32(test_vec[4].a);
  b = simde_x_mm_loadu_epi32(test_vec[4].b);
  c = simde_x_mm_loadu_epi32(test_vec[4].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         188));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[4].r));

  a = simde_x_mm_loadu_epi32(test_vec[5].a);
  b = simde_x_mm_loadu_epi32(test_vec[5].b);
  c = simde_x_mm_loadu_epi32(test_vec[5].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         189));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[5].r));

  a = simde_x_mm_loadu_epi32(test_vec[6].a);
  b = simde_x_mm_loadu_epi32(test_vec[6].b);
  c = simde_x_mm_loadu_epi32(test_vec[6].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         190));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[6].r));

  a = simde_x_mm_loadu_epi32(test_vec[7].a);
  b = simde_x_mm_loadu_epi32(test_vec[7].b);
  c = simde_x_mm_loadu_epi32(test_vec[7].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         191));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[7].r));

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 160 ; i < 192 ; i++) {
    simde__m128i a = simde_test_x86_random_i32x4();
    simde__m128i b = simde_test_x86_random_i32x4();
    simde__m128i c = simde_test_x86_random_i32x4();
    simde__m128i r;
    SIMDE_CONSTIFY_32_6(simde_mm_ternarylogic_epi32, r, simde_mm_setzero_si128(), i, a, b, c);

    simde_test_x86_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, i, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_ternarylogic_epi32_25 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t a[4];
    const int32_t b[4];
    const int32_t c[4];
    const int32_t imm8;
    const int32_t r[4];
  } test_vec[] = {
    { { -INT32_C(  1366470585),  INT32_C(  1129748341),  INT32_C(  1625817340),  INT32_C(   138071287) },
      { -INT32_C(  1343625536), -INT32_C(  1915514150), -INT32_C(  1551130456), -INT32_C(  1701156269) },
      {  INT32_C(   793258170), -INT32_C(  1150116161), -INT32_C(  1776591969), -INT32_C(   392276441) },
       INT32_C(         192),
      { -INT32_C(  1366736832),  INT32_C(    22188624),  INT32_C(   545783976),  INT32_C(   135940179) } },
    { {  INT32_C(   379029308), -INT32_C(  1029477606),  INT32_C(  1583689227),  INT32_C(  1408762009) },
      { -INT32_C(   410828504),  INT32_C(  2124674527),  INT32_C(  2014625360),  INT32_C(  1365291540) },
      {  INT32_C(  1416099642),  INT32_C(  1830161250), -INT32_C(   758416327), -INT32_C(  1540963204) },
       INT32_C(         193),
      {  INT32_C(   243993065),  INT32_C(  1122722074),  INT32_C(  1493446532),  INT32_C(  1499531538) } },
    { { -INT32_C(   460609275), -INT32_C(   278712674),  INT32_C(    23558125),  INT32_C(  1683146538) },
      {  INT32_C(   565754558), -INT32_C(    24195387), -INT32_C(   959358390),  INT32_C(   594212638) },
      {  INT32_C(  1040709280),  INT32_C(   288188964),  INT32_C(   202609890),  INT32_C(   443573595) },
       INT32_C(         194),
      {  INT32_C(   982313988), -INT32_C(   301855068),  INT32_C(   138531400),  INT32_C(   943900491) } },
    { { -INT32_C(   465885153),  INT32_C(  1105447414),  INT32_C(  1091023907),  INT32_C(  1264874155) },
      { -INT32_C(  1937150872), -INT32_C(  1197557802), -INT32_C(  1480281781),  INT32_C(   918631446) },
      {  INT32_C(  1394277468), -INT32_C(   376111675),  INT32_C(  1546296241),  INT32_C(  1973915405) },
       INT32_C(         195),
      { -INT32_C(  1756513400),  INT32_C(   109216223),  INT32_C(   423426711), -INT32_C(  2107983550) } },
    { { -INT32_C(   788385285),  INT32_C(   864723176),  INT32_C(  1742360145), -INT32_C(   543319165) },
      {  INT32_C(  1563605143),  INT32_C(  1732691637),  INT32_C(  1875079266), -INT32_C(    85627905) },
      { -INT32_C(  2066946148), -INT32_C(   659073401),  INT32_C(   658477732), -INT32_C(   989340371) },
       INT32_C(         196),
      {  INT32_C(  1496463507),  INT32_C(   658669744),  INT32_C(  1875009602), -INT32_C(    85644333) } },
    { {  INT32_C(  1243756949),  INT32_C(  1655793664), -INT32_C(   657361448),  INT32_C(  2094184160) },
      {  INT32_C(   604020381), -INT32_C(  1711491084),  INT32_C(  2009087049), -INT32_C(  1371748583) },
      {  INT32_C(    33054209), -INT32_C(  1637635386), -INT32_C(     9030625), -INT32_C(  2005186069) },
       INT32_C(         197),
      { -INT32_C(  1274701569),  INT32_C(    29111609),  INT32_C(  1355333224),  INT32_C(   789874196) } },
    { { -INT32_C(   592610329),  INT32_C(  2088085810), -INT32_C(    17615387), -INT32_C(    22269955) },
      {  INT32_C(  1409262989),  INT32_C(  1861313103), -INT32_C(  2123536234), -INT32_C(  1744115535) },
      { -INT32_C(  1787512989),  INT32_C(  1175578976),  INT32_C(   474219551), -INT32_C(  1071976141) },
       INT32_C(         198),
      {  INT32_C(  1387209101),  INT32_C(  1827742223), -INT32_C(  2123798388), -INT32_C(  1743243085) } },
    { { -INT32_C(   451733098),  INT32_C(   290653563),  INT32_C(   512999533),  INT32_C(   196517288) },
      { -INT32_C(  1264571564),  INT32_C(   872067604), -INT32_C(   363905098), -INT32_C(   961910480) },
      { -INT32_C(    39076222),  INT32_C(   806354627),  INT32_C(  1716429502), -INT32_C(  1821309889) },
       INT32_C(         199),
      { -INT32_C(  1370698371), -INT32_C(   537507692), -INT32_C(  1960633052),  INT32_C(  1995139943) } },
  };

  simde__m128i a, b, c, r;

  a = simde_x_mm_loadu_epi32(test_vec[0].a);
  b = simde_x_mm_loadu_epi32(test_vec[0].b);
  c = simde_x_mm_loadu_epi32(test_vec[0].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         192));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[0].r));

  a = simde_x_mm_loadu_epi32(test_vec[1].a);
  b = simde_x_mm_loadu_epi32(test_vec[1].b);
  c = simde_x_mm_loadu_epi32(test_vec[1].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         193));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[1].r));

  a = simde_x_mm_loadu_epi32(test_vec[2].a);
  b = simde_x_mm_loadu_epi32(test_vec[2].b);
  c = simde_x_mm_loadu_epi32(test_vec[2].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         194));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[2].r));

  a = simde_x_mm_loadu_epi32(test_vec[3].a);
  b = simde_x_mm_loadu_epi32(test_vec[3].b);
  c = simde_x_mm_loadu_epi32(test_vec[3].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         195));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[3].r));

  a = simde_x_mm_loadu_epi32(test_vec[4].a);
  b = simde_x_mm_loadu_epi32(test_vec[4].b);
  c = simde_x_mm_loadu_epi32(test_vec[4].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         196));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[4].r));

  a = simde_x_mm_loadu_epi32(test_vec[5].a);
  b = simde_x_mm_loadu_epi32(test_vec[5].b);
  c = simde_x_mm_loadu_epi32(test_vec[5].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         197));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[5].r));

  a = simde_x_mm_loadu_epi32(test_vec[6].a);
  b = simde_x_mm_loadu_epi32(test_vec[6].b);
  c = simde_x_mm_loadu_epi32(test_vec[6].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         198));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[6].r));

  a = simde_x_mm_loadu_epi32(test_vec[7].a);
  b = simde_x_mm_loadu_epi32(test_vec[7].b);
  c = simde_x_mm_loadu_epi32(test_vec[7].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         199));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[7].r));

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 192 ; i < (192 + 32) ; i++) {
    simde__m128i a = simde_test_x86_random_i32x4();
    simde__m128i b = simde_test_x86_random_i32x4();
    simde__m128i c = simde_test_x86_random_i32x4();
    simde__m128i r;
    SIMDE_CONSTIFY_32_7(simde_mm_ternarylogic_epi32, r, simde_mm_setzero_si128(), i, a, b, c);

    simde_test_x86_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, i, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_ternarylogic_epi32_26 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t a[4];
    const int32_t b[4];
    const int32_t c[4];
    const int32_t imm8;
    const int32_t r[4];
  } test_vec[] = {
    { {  INT32_C(  1145508143),  INT32_C(  2054636227), -INT32_C(  1318795391), -INT32_C(  1284043216) },
      { -INT32_C(  1884282164), -INT32_C(   557859040), -INT32_C(  1606152863),  INT32_C(  1093907730) },
      { -INT32_C(  1970963514),  INT32_C(  1040514493), -INT32_C(   185636668),  INT32_C(  1135044214) },
       INT32_C(         200),
      { -INT32_C(  1904205108),  INT32_C(  1580711712), -INT32_C(  1606152895),  INT32_C(  1093870610) } },
    { { -INT32_C(  1462609784),  INT32_C(  2038862359), -INT32_C(  1323709793),  INT32_C(  1173572991) },
      { -INT32_C(  2050000696),  INT32_C(   969134965), -INT32_C(  1305562565), -INT32_C(  1594501864) },
      {  INT32_C(  1162397485), -INT32_C(   104935847),  INT32_C(   397072280), -INT32_C(   329474780) },
       INT32_C(         201),
      { -INT32_C(  1746249574),  INT32_C(  1065546453), -INT32_C(    93679013), -INT32_C(  1292503144) } },
    { { -INT32_C(  1955517418),  INT32_C(  1002779903), -INT32_C(    17959962), -INT32_C(   157359416) },
      {  INT32_C(    54257321),  INT32_C(  1291647412), -INT32_C(   178018608),  INT32_C(  1524744260) },
      { -INT32_C(   337292308),  INT32_C(  1848027783),  INT32_C(  1718358941), -INT32_C(  1621357579) },
       INT32_C(         202),
      {  INT32_C(  1672837096),  INT32_C(  1290189492), -INT32_C(   194927911),  INT32_C(  1539361141) } },
    { { -INT32_C(  1499293711),  INT32_C(  1626513040), -INT32_C(  2007673276),  INT32_C(    48379670) },
      {  INT32_C(   300796042),  INT32_C(   276763762),  INT32_C(   494332967), -INT32_C(   390278409) },
      { -INT32_C(   108110231),  INT32_C(  1079607804), -INT32_C(   305549353),  INT32_C(  1894755302) },
       INT32_C(         203),
      {  INT32_C(  1505552524), -INT32_C(  1887734403),  INT32_C(  1876749727),  INT32_C(  1974311678) } },
    { { -INT32_C(   427697037),  INT32_C(   418775536), -INT32_C(   466260755), -INT32_C(  1479741122) },
      {  INT32_C(  1268800335), -INT32_C(  1282672164), -INT32_C(  1902095192),  INT32_C(  1946062592) },
      {  INT32_C(  1549369451),  INT32_C(  1853116289), -INT32_C(   112023109), -INT32_C(   375382374) },
       INT32_C(         204),
      {  INT32_C(  1268800335), -INT32_C(  1282672164), -INT32_C(  1902095192),  INT32_C(  1946062592) } },
    { {  INT32_C(  1429487737), -INT32_C(   502743238),  INT32_C(   342992916), -INT32_C(  1551405257) },
      {  INT32_C(  1895817711), -INT32_C(   320965840), -INT32_C(  1226493924), -INT32_C(   929069489) },
      {  INT32_C(     2020294), -INT32_C(  1495062894),  INT32_C(   112874703), -INT32_C(  1280752957) },
       INT32_C(         205),
      { -INT32_C(    83890705), -INT32_C(    35753099), -INT32_C(     1756356), -INT32_C(   857762225) } },
    { {  INT32_C(  1394845731),  INT32_C(   926876187), -INT32_C(  2115164878),  INT32_C(  1900711083) },
      { -INT32_C(   227383201),  INT32_C(  1570264462),  INT32_C(  1818514345), -INT32_C(  1205924459) },
      { -INT32_C(   787790922),  INT32_C(  1997097797),  INT32_C(   469366384), -INT32_C(   494124157) },
       INT32_C(         206),
      { -INT32_C(   226858017),  INT32_C(  1570266574),  INT32_C(  2121585641), -INT32_C(  1163964523) } },
    { {  INT32_C(   970260139), -INT32_C(    57184941),  INT32_C(  1433009088), -INT32_C(  1106409464) },
      {  INT32_C(   277878987), -INT32_C(   746022557),  INT32_C(   317620623),  INT32_C(  1878358980) },
      { -INT32_C(   844576391), -INT32_C(   154583242),  INT32_C(  1129001530), -INT32_C(  2046732101) },
       INT32_C(         207),
      { -INT32_C(   692381217), -INT32_C(   739730449), -INT32_C(  1157724737),  INT32_C(  1878491127) } },
  };

  simde__m128i a, b, c, r;

  a = simde_x_mm_loadu_epi32(test_vec[0].a);
  b = simde_x_mm_loadu_epi32(test_vec[0].b);
  c = simde_x_mm_loadu_epi32(test_vec[0].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         200));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[0].r));

  a = simde_x_mm_loadu_epi32(test_vec[1].a);
  b = simde_x_mm_loadu_epi32(test_vec[1].b);
  c = simde_x_mm_loadu_epi32(test_vec[1].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         201));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[1].r));

  a = simde_x_mm_loadu_epi32(test_vec[2].a);
  b = simde_x_mm_loadu_epi32(test_vec[2].b);
  c = simde_x_mm_loadu_epi32(test_vec[2].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         202));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[2].r));

  a = simde_x_mm_loadu_epi32(test_vec[3].a);
  b = simde_x_mm_loadu_epi32(test_vec[3].b);
  c = simde_x_mm_loadu_epi32(test_vec[3].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         203));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[3].r));

  a = simde_x_mm_loadu_epi32(test_vec[4].a);
  b = simde_x_mm_loadu_epi32(test_vec[4].b);
  c = simde_x_mm_loadu_epi32(test_vec[4].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         204));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[4].r));

  a = simde_x_mm_loadu_epi32(test_vec[5].a);
  b = simde_x_mm_loadu_epi32(test_vec[5].b);
  c = simde_x_mm_loadu_epi32(test_vec[5].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         205));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[5].r));

  a = simde_x_mm_loadu_epi32(test_vec[6].a);
  b = simde_x_mm_loadu_epi32(test_vec[6].b);
  c = simde_x_mm_loadu_epi32(test_vec[6].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         206));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[6].r));

  a = simde_x_mm_loadu_epi32(test_vec[7].a);
  b = simde_x_mm_loadu_epi32(test_vec[7].b);
  c = simde_x_mm_loadu_epi32(test_vec[7].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         207));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[7].r));

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 192 ; i < (192 + 32) ; i++) {
    simde__m128i a = simde_test_x86_random_i32x4();
    simde__m128i b = simde_test_x86_random_i32x4();
    simde__m128i c = simde_test_x86_random_i32x4();
    simde__m128i r;
    SIMDE_CONSTIFY_32_7(simde_mm_ternarylogic_epi32, r, simde_mm_setzero_si128(), i, a, b, c);

    simde_test_x86_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, i, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_ternarylogic_epi32_27 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t a[4];
    const int32_t b[4];
    const int32_t c[4];
    const int32_t imm8;
    const int32_t r[4];
  } test_vec[] = {
    { { -INT32_C(   728264335), -INT32_C(  1163387094),  INT32_C(  1691129504), -INT32_C(  1949056751) },
      { -INT32_C(  1051165813), -INT32_C(   172482117),  INT32_C(   255329108), -INT32_C(   845858212) },
      { -INT32_C(   157209397), -INT32_C(   340768437), -INT32_C(   246448928), -INT32_C(   914611650) },
       INT32_C(         208),
      { -INT32_C(  1072262863), -INT32_C(  1331161302),  INT32_C(    76055040), -INT32_C(  1953251055) } },
    { {  INT32_C(  1502270622),  INT32_C(  1246642934), -INT32_C(  1571190970), -INT32_C(  1938821439) },
      {  INT32_C(  1719799835),  INT32_C(   978465370), -INT32_C(   315907665),  INT32_C(  1656137924) },
      {  INT32_C(  1924874364), -INT32_C(   910423677),  INT32_C(  1365972368),  INT32_C(   534698500) },
       INT32_C(         209),
      { -INT32_C(   909721702),  INT32_C(   239322742), -INT32_C(  1566717114), -INT32_C(  2144883205) } },
    { {  INT32_C(  1149591786),  INT32_C(  1115608979),  INT32_C(  1026534009), -INT32_C(   828381870) },
      { -INT32_C(  1472112091), -INT32_C(   193856157),  INT32_C(   390454291), -INT32_C(  1590287434) },
      {  INT32_C(   400931716),  INT32_C(   207185043),  INT32_C(  1615431694), -INT32_C(  1842419603) },
       INT32_C(         210),
      {  INT32_C(  1394721130),  INT32_C(  1249302275),  INT32_C(  1562880629), -INT32_C(   594072293) } },
    { { -INT32_C(  1522831550), -INT32_C(  2137412499),  INT32_C(  1066917769), -INT32_C(  2032087806) },
      {  INT32_C(   463324808),  INT32_C(   942143018), -INT32_C(   342331266), -INT32_C(  1702967720) },
      { -INT32_C(  1556039370), -INT32_C(   299640475), -INT32_C(  1154565448),  INT32_C(   255921799) },
       INT32_C(         211),
      {  INT32_C(  1165710965),  INT32_C(  1205446072),  INT32_C(   804345097), -INT32_C(   471730779) } },
    { { -INT32_C(    30679084),  INT32_C(  1412846293),  INT32_C(   457166531), -INT32_C(   877216363) },
      { -INT32_C(   596707722), -INT32_C(  1999990321), -INT32_C(   767297461), -INT32_C(   605977593) },
      {  INT32_C(   970591331),  INT32_C(   579670111),  INT32_C(  1950207199),  INT32_C(     4191114) },
       INT32_C(         212),
      { -INT32_C(   567281708), -INT32_C(   596454459), -INT32_C(  1690043837), -INT32_C(   606041067) } },
    { { -INT32_C(  1176719895), -INT32_C(  1992186050), -INT32_C(  1503951713),  INT32_C(  1820474376) },
      { -INT32_C(  1465557943),  INT32_C(  1271542380), -INT32_C(  2000746498), -INT32_C(   460718341) },
      { -INT32_C(   375560789), -INT32_C(  1401758196),  INT32_C(  1800588642),  INT32_C(  1406653450) },
       INT32_C(         213),
      { -INT32_C(  1092182435),  INT32_C(  1540170751), -INT32_C(  1799407969), -INT32_C(   324517891) } },
    { { -INT32_C(  1644463056), -INT32_C(  1394031186), -INT32_C(   952784692),  INT32_C(  1387052710) },
      {  INT32_C(   809191715), -INT32_C(  1965248984), -INT32_C(  2047529349),  INT32_C(   869846019) },
      { -INT32_C(   154086584),  INT32_C(  1705228696),  INT32_C(   120379489), -INT32_C(  1185294186) },
       INT32_C(         214),
      {  INT32_C(  1530654331), -INT32_C(   874523074), -INT32_C(   973242658), -INT32_C(   626151885) } },
    { {  INT32_C(  1256822050), -INT32_C(  1093352125), -INT32_C(   146486540), -INT32_C(   550888298) },
      { -INT32_C(  1999242256),  INT32_C(   367884468), -INT32_C(   434365872),  INT32_C(   346060530) },
      {  INT32_C(  1314818315),  INT32_C(  1124873039), -INT32_C(  1824894723),  INT32_C(  1567777901) },
       INT32_C(         215),
      { -INT32_C(  1109133315), -INT32_C(    50868552), -INT32_C(   286806181), -INT32_C(  1224892517) } },
  };

  simde__m128i a, b, c, r;

  a = simde_x_mm_loadu_epi32(test_vec[0].a);
  b = simde_x_mm_loadu_epi32(test_vec[0].b);
  c = simde_x_mm_loadu_epi32(test_vec[0].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         208));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[0].r));

  a = simde_x_mm_loadu_epi32(test_vec[1].a);
  b = simde_x_mm_loadu_epi32(test_vec[1].b);
  c = simde_x_mm_loadu_epi32(test_vec[1].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         209));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[1].r));

  a = simde_x_mm_loadu_epi32(test_vec[2].a);
  b = simde_x_mm_loadu_epi32(test_vec[2].b);
  c = simde_x_mm_loadu_epi32(test_vec[2].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         210));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[2].r));

  a = simde_x_mm_loadu_epi32(test_vec[3].a);
  b = simde_x_mm_loadu_epi32(test_vec[3].b);
  c = simde_x_mm_loadu_epi32(test_vec[3].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         211));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[3].r));

  a = simde_x_mm_loadu_epi32(test_vec[4].a);
  b = simde_x_mm_loadu_epi32(test_vec[4].b);
  c = simde_x_mm_loadu_epi32(test_vec[4].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         212));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[4].r));

  a = simde_x_mm_loadu_epi32(test_vec[5].a);
  b = simde_x_mm_loadu_epi32(test_vec[5].b);
  c = simde_x_mm_loadu_epi32(test_vec[5].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         213));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[5].r));

  a = simde_x_mm_loadu_epi32(test_vec[6].a);
  b = simde_x_mm_loadu_epi32(test_vec[6].b);
  c = simde_x_mm_loadu_epi32(test_vec[6].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         214));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[6].r));

  a = simde_x_mm_loadu_epi32(test_vec[7].a);
  b = simde_x_mm_loadu_epi32(test_vec[7].b);
  c = simde_x_mm_loadu_epi32(test_vec[7].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         215));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[7].r));

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 192 ; i < (192 + 32) ; i++) {
    simde__m128i a = simde_test_x86_random_i32x4();
    simde__m128i b = simde_test_x86_random_i32x4();
    simde__m128i c = simde_test_x86_random_i32x4();
    simde__m128i r;
    SIMDE_CONSTIFY_32_7(simde_mm_ternarylogic_epi32, r, simde_mm_setzero_si128(), i, a, b, c);

    simde_test_x86_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, i, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_ternarylogic_epi32_28 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t a[4];
    const int32_t b[4];
    const int32_t c[4];
    const int32_t imm8;
    const int32_t r[4];
  } test_vec[] = {
    { {  INT32_C(   333793375),  INT32_C(   287888320), -INT32_C(   537442835), -INT32_C(   957048901) },
      {  INT32_C(  1880379937), -INT32_C(  2102189947), -INT32_C(   568922767), -INT32_C(  1321498543) },
      { -INT32_C(  1849417520), -INT32_C(   526193165), -INT32_C(   306144974),  INT32_C(  1387508785) },
       INT32_C(         216),
      {  INT32_C(   304433167), -INT32_C(  1851116927), -INT32_C(   566768131), -INT32_C(  1804106853) } },
    { { -INT32_C(  1933392122),  INT32_C(  1477342695), -INT32_C(  1288297374),  INT32_C(  2103734701) },
      { -INT32_C(  2062669422),  INT32_C(  1214689302),  INT32_C(  2067080778), -INT32_C(   523376422) },
      { -INT32_C(  1771270225),  INT32_C(  1726970628),  INT32_C(  1276716447),  INT32_C(   701136535) },
       INT32_C(         217),
      { -INT32_C(   325101118), -INT32_C(   646564625), -INT32_C(    67634070),  INT32_C(  1996253626) } },
    { { -INT32_C(  1112614745), -INT32_C(   754641783),  INT32_C(   340671034), -INT32_C(   772465886) },
      { -INT32_C(  1368956502),  INT32_C(  2081707740),  INT32_C(   331885948),  INT32_C(  1379701419) },
      { -INT32_C(   200283541),  INT32_C(   969348351),  INT32_C(  1884165454), -INT32_C(   633257168) },
       INT32_C(         218),
      { -INT32_C(   307793170), -INT32_C(    87681794),  INT32_C(  1950887804),  INT32_C(  1538546226) } },
    { { -INT32_C(  2121750108),  INT32_C(  2080218367),  INT32_C(  1972291017), -INT32_C(  1010316712) },
      { -INT32_C(  1263020107),  INT32_C(   988643051), -INT32_C(  1012253805),  INT32_C(   597552254) },
      { -INT32_C(  1801181803), -INT32_C(  1978621503), -INT32_C(  1090544026),  INT32_C(   511821673) },
       INT32_C(         219),
      { -INT32_C(   538145281), -INT32_C(     1098241), -INT32_C(   872719441), -INT32_C(   538452487) } },
    { { -INT32_C(  1982711650),  INT32_C(  1237565366),  INT32_C(  2030857979), -INT32_C(   274945702) },
      { -INT32_C(  1887223602),  INT32_C(  1209701345), -INT32_C(  1694099150),  INT32_C(  2126088416) },
      {  INT32_C(  1997048768),  INT32_C(  1170262858), -INT32_C(  1816146631),  INT32_C(  1166170998) },
       INT32_C(         220),
      { -INT32_C(  1881968418),  INT32_C(  1209776117), -INT32_C(    83477518), -INT32_C(    21124888) } },
    { {  INT32_C(  2111047324), -INT32_C(   876220775), -INT32_C(   395916280),  INT32_C(   342302548) },
      { -INT32_C(   175411286),  INT32_C(  1949977658), -INT32_C(  1895302887), -INT32_C(   237729195) },
      {  INT32_C(   695118224), -INT32_C(  1611320169),  INT32_C(  1418222336),  INT32_C(   627634043) },
       INT32_C(         221),
      { -INT32_C(   140804113),  INT32_C(  1950011258), -INT32_C(  1351090689), -INT32_C(    69756203) } },
    { { -INT32_C(  1743063970),  INT32_C(  1493980480), -INT32_C(  1545071538),  INT32_C(   781499806) },
      { -INT32_C(    44629146),  INT32_C(   933055543),  INT32_C(   596321704),  INT32_C(  1917383444) },
      {  INT32_C(   654992359),  INT32_C(   109057976), -INT32_C(   911578837), -INT32_C(  1929953754) },
       INT32_C(         222),
      { -INT32_C(    11036673),  INT32_C(  2141015807),  INT32_C(  1808498157), -INT32_C(   227806276) } },
    { {  INT32_C(  2022264385),  INT32_C(  1135552155),  INT32_C(  1600535115),  INT32_C(   366063150) },
      { -INT32_C(   918692847),  INT32_C(   516996595),  INT32_C(  1290238502), -INT32_C(    86450504) },
      { -INT32_C(   948805076), -INT32_C(   737533304), -INT32_C(  1976340388),  INT32_C(   815793439) },
       INT32_C(         223),
      { -INT32_C(         513), -INT32_C(  1074397705), -INT32_C(    33554505), -INT32_C(           7) } },
  };

  simde__m128i a, b, c, r;

  a = simde_x_mm_loadu_epi32(test_vec[0].a);
  b = simde_x_mm_loadu_epi32(test_vec[0].b);
  c = simde_x_mm_loadu_epi32(test_vec[0].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         216));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[0].r));

  a = simde_x_mm_loadu_epi32(test_vec[1].a);
  b = simde_x_mm_loadu_epi32(test_vec[1].b);
  c = simde_x_mm_loadu_epi32(test_vec[1].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         217));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[1].r));

  a = simde_x_mm_loadu_epi32(test_vec[2].a);
  b = simde_x_mm_loadu_epi32(test_vec[2].b);
  c = simde_x_mm_loadu_epi32(test_vec[2].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         218));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[2].r));

  a = simde_x_mm_loadu_epi32(test_vec[3].a);
  b = simde_x_mm_loadu_epi32(test_vec[3].b);
  c = simde_x_mm_loadu_epi32(test_vec[3].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         219));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[3].r));

  a = simde_x_mm_loadu_epi32(test_vec[4].a);
  b = simde_x_mm_loadu_epi32(test_vec[4].b);
  c = simde_x_mm_loadu_epi32(test_vec[4].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         220));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[4].r));

  a = simde_x_mm_loadu_epi32(test_vec[5].a);
  b = simde_x_mm_loadu_epi32(test_vec[5].b);
  c = simde_x_mm_loadu_epi32(test_vec[5].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         221));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[5].r));

  a = simde_x_mm_loadu_epi32(test_vec[6].a);
  b = simde_x_mm_loadu_epi32(test_vec[6].b);
  c = simde_x_mm_loadu_epi32(test_vec[6].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         222));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[6].r));

  a = simde_x_mm_loadu_epi32(test_vec[7].a);
  b = simde_x_mm_loadu_epi32(test_vec[7].b);
  c = simde_x_mm_loadu_epi32(test_vec[7].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         223));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[7].r));

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 192 ; i < (192 + 32) ; i++) {
    simde__m128i a = simde_test_x86_random_i32x4();
    simde__m128i b = simde_test_x86_random_i32x4();
    simde__m128i c = simde_test_x86_random_i32x4();
    simde__m128i r;
    SIMDE_CONSTIFY_32_7(simde_mm_ternarylogic_epi32, r, simde_mm_setzero_si128(), i, a, b, c);

    simde_test_x86_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, i, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_ternarylogic_epi32_29 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t a[4];
    const int32_t b[4];
    const int32_t c[4];
    const int32_t imm8;
    const int32_t r[4];
  } test_vec[] = {
    { {  INT32_C(   163837701), -INT32_C(   213132043), -INT32_C(   327423432),  INT32_C(  1532722496) },
      { -INT32_C(   873746774), -INT32_C(  1749054645), -INT32_C(  1959299981),  INT32_C(  1996657265) },
      {  INT32_C(  2122368393), -INT32_C(   646788191), -INT32_C(   154735178),  INT32_C(   340861290) },
       INT32_C(         224),
      {  INT32_C(   163833601), -INT32_C(   750008095), -INT32_C(   327948240),  INT32_C(  1397961024) } },
    { {  INT32_C(   450903247),  INT32_C(  1001562055), -INT32_C(  2050561773),  INT32_C(    83675515) },
      {  INT32_C(   813857934), -INT32_C(    32902072),  INT32_C(  1291112418), -INT32_C(  1084144144) },
      {  INT32_C(  1239040385), -INT32_C(   192639776), -INT32_C(   260486539), -INT32_C(  1561037549) },
       INT32_C(         225),
      { -INT32_C(  1664762177),  INT32_C(   985701584), -INT32_C(  2033919717),  INT32_C(  1156989815) } },
    { {  INT32_C(   970094321),  INT32_C(  1295506283), -INT32_C(  1684460629), -INT32_C(   228853136) },
      {  INT32_C(   473642299),  INT32_C(   907067329),  INT32_C(   489064713), -INT32_C(   272688386) },
      { -INT32_C(    81161840),  INT32_C(   390619244), -INT32_C(    55319924),  INT32_C(   418254556) },
       INT32_C(         226),
      { -INT32_C(    82660175),  INT32_C(    89709421), -INT32_C(   107910259), -INT32_C(   228909456) } },
    { {  INT32_C(    70527299), -INT32_C(   231062296), -INT32_C(   888184627),  INT32_C(   180014714) },
      { -INT32_C(   888741025), -INT32_C(   790409660),  INT32_C(   231511600), -INT32_C(   416957532) },
      { -INT32_C(   840214044),  INT32_C(  1790911901), -INT32_C(    13250939), -INT32_C(    83234916) },
       INT32_C(         227),
      {  INT32_C(   887963107), -INT32_C(    12651045), -INT32_C(    79869561),  INT32_C(   443076153) } },
    { {  INT32_C(   398856147), -INT32_C(  1897420450), -INT32_C(   476335297),  INT32_C(  1405796462) },
      { -INT32_C(  1239370471),  INT32_C(  1595989978),  INT32_C(  1230919085),  INT32_C(   407136325) },
      { -INT32_C(   718337417), -INT32_C(   211544396),  INT32_C(   953679817), -INT32_C(   645160512) },
       INT32_C(         228),
      {  INT32_C(   923189083), -INT32_C(  1905997474),  INT32_C(  1637593901),  INT32_C(  1372506181) } },
    { {  INT32_C(   831564631),  INT32_C(   932294794),  INT32_C(  1266740998), -INT32_C(   815545257) },
      { -INT32_C(  2103143730),  INT32_C(  1903560872), -INT32_C(   928428792),  INT32_C(  1168192750) },
      {  INT32_C(  1769419231), -INT32_C(   392165150),  INT32_C(  1328750839), -INT32_C(  1289840924) },
       INT32_C(         229),
      { -INT32_C(  1483151497),  INT32_C(   836650911), -INT32_C(    70484722), -INT32_C(   945574578) } },
    { { -INT32_C(   801783256), -INT32_C(   750670901), -INT32_C(   409211912), -INT32_C(    13878241) },
      {  INT32_C(  1349034862), -INT32_C(  1556608597),  INT32_C(   250768169),  INT32_C(   700518401) },
      { -INT32_C(  1644562734), -INT32_C(  1703920990),  INT32_C(  1166084901), -INT32_C(  1237012920) },
       INT32_C(         230),
      { -INT32_C(   575547460), -INT32_C(  1152894069),  INT32_C(  1341352748), -INT32_C(  1081754039) } },
    { { -INT32_C(    49894319), -INT32_C(   543146315), -INT32_C(  1427270999),  INT32_C(  1960029858) },
      {  INT32_C(  1175637156),  INT32_C(   752976390), -INT32_C(   697212274),  INT32_C(  1653388560) },
      {  INT32_C(   392139361),  INT32_C(  2046230480),  INT32_C(   857990033),  INT32_C(   900200081) },
       INT32_C(         231),
      {  INT32_C(  1441783759),  INT32_C(  1572831198), -INT32_C(   411856929), -INT32_C(     5511219) } },
  };

  simde__m128i a, b, c, r;

  a = simde_x_mm_loadu_epi32(test_vec[0].a);
  b = simde_x_mm_loadu_epi32(test_vec[0].b);
  c = simde_x_mm_loadu_epi32(test_vec[0].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         224));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[0].r));

  a = simde_x_mm_loadu_epi32(test_vec[1].a);
  b = simde_x_mm_loadu_epi32(test_vec[1].b);
  c = simde_x_mm_loadu_epi32(test_vec[1].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         225));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[1].r));

  a = simde_x_mm_loadu_epi32(test_vec[2].a);
  b = simde_x_mm_loadu_epi32(test_vec[2].b);
  c = simde_x_mm_loadu_epi32(test_vec[2].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         226));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[2].r));

  a = simde_x_mm_loadu_epi32(test_vec[3].a);
  b = simde_x_mm_loadu_epi32(test_vec[3].b);
  c = simde_x_mm_loadu_epi32(test_vec[3].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         227));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[3].r));

  a = simde_x_mm_loadu_epi32(test_vec[4].a);
  b = simde_x_mm_loadu_epi32(test_vec[4].b);
  c = simde_x_mm_loadu_epi32(test_vec[4].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         228));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[4].r));

  a = simde_x_mm_loadu_epi32(test_vec[5].a);
  b = simde_x_mm_loadu_epi32(test_vec[5].b);
  c = simde_x_mm_loadu_epi32(test_vec[5].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         229));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[5].r));

  a = simde_x_mm_loadu_epi32(test_vec[6].a);
  b = simde_x_mm_loadu_epi32(test_vec[6].b);
  c = simde_x_mm_loadu_epi32(test_vec[6].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         230));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[6].r));

  a = simde_x_mm_loadu_epi32(test_vec[7].a);
  b = simde_x_mm_loadu_epi32(test_vec[7].b);
  c = simde_x_mm_loadu_epi32(test_vec[7].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         231));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[7].r));

  return 0;
#else
  fputc('\n', stdout);
  for (int i = (192+32) ; i < 256 ; i++) {
    simde__m128i a = simde_test_x86_random_i32x4();
    simde__m128i b = simde_test_x86_random_i32x4();
    simde__m128i c = simde_test_x86_random_i32x4();
    simde__m128i r;
    SIMDE_CONSTIFY_32_8(simde_mm_ternarylogic_epi32, r, simde_mm_setzero_si128(), i, a, b, c);

    simde_test_x86_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, i, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_ternarylogic_epi32_30 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t a[4];
    const int32_t b[4];
    const int32_t c[4];
    const int32_t imm8;
    const int32_t r[4];
  } test_vec[] = {
    { { -INT32_C(   931350078), -INT32_C(   889955012), -INT32_C(   794794561),  INT32_C(  2083662874) },
      { -INT32_C(  1902931522),  INT32_C(   554142096), -INT32_C(    44815764), -INT32_C(   499975392) },
      { -INT32_C(   240472395), -INT32_C(   876896501),  INT32_C(   530275076),  INT32_C(  1167838599) },
       INT32_C(         232),
      { -INT32_C(   927286858), -INT32_C(   877159144), -INT32_C(   577737940),  INT32_C(  1681059074) } },
    { { -INT32_C(   288149922),  INT32_C(   588241591),  INT32_C(   606102276),  INT32_C(   319181406) },
      {  INT32_C(   201633793),  INT32_C(  1423425359), -INT32_C(  1586269670), -INT32_C(  1645867457) },
      { -INT32_C(   208946884), -INT32_C(  1760126317),  INT32_C(  1555773181), -INT32_C(  1989164664) },
       INT32_C(         233),
      { -INT32_C(   291243876),  INT32_C(   523737751),  INT32_C(   641202716), -INT32_C(   109682146) } },
    { { -INT32_C(  1047104398),  INT32_C(  1310027059),  INT32_C(   535791840), -INT32_C(   759310698) },
      {  INT32_C(   600131727), -INT32_C(   524624925), -INT32_C(  1707313647), -INT32_C(  1457279945) },
      {  INT32_C(  1399568672),  INT32_C(   128024615), -INT32_C(  1624862455), -INT32_C(   160242841) },
       INT32_C(         234),
      {  INT32_C(  1408235810),  INT32_C(  1202833703), -INT32_C(  1624338167), -INT32_C(   160176265) } },
    { {  INT32_C(   253310764),  INT32_C(   619697171), -INT32_C(  2118243254), -INT32_C(   131341608) },
      { -INT32_C(  1035233637),  INT32_C(   533327126), -INT32_C(   440405890), -INT32_C(     2412077) },
      {  INT32_C(  2064577896),  INT32_C(   329318089),  INT32_C(    43277866), -INT32_C(   587546816) },
       INT32_C(         235),
      {  INT32_C(  2075131752), -INT32_C(   671482117), -INT32_C(  1677819925), -INT32_C(    50348044) } },
    { {  INT32_C(  1822311765), -INT32_C(  1333041102),  INT32_C(   731204184), -INT32_C(   466914949) },
      {  INT32_C(   794769766),  INT32_C(  1631780663), -INT32_C(  1637624226), -INT32_C(   344302186) },
      { -INT32_C(   715712093), -INT32_C(   645471359), -INT32_C(  1459348691), -INT32_C(   225628276) },
       INT32_C(         236),
      {  INT32_C(  1868511591), -INT32_C(   238878921), -INT32_C(  1083711906), -INT32_C(   344228450) } },
    { { -INT32_C(  1608389527),  INT32_C(  1241670636), -INT32_C(   790076102),  INT32_C(  1723556803) },
      { -INT32_C(    46460036),  INT32_C(   601276918),  INT32_C(  1775033053),  INT32_C(  1935431946) },
      {  INT32_C(   840138054),  INT32_C(   461116897),  INT32_C(  1055614075),  INT32_C(  1134864071) },
       INT32_C(         237),
      { -INT32_C(    33587204), -INT32_C(  1344812554),  INT32_C(  2046623487), -INT32_C(    67339269) } },
    { { -INT32_C(  1354702919),  INT32_C(  2127763105), -INT32_C(    68706319),  INT32_C(  1064190969) },
      { -INT32_C(  1569619519),  INT32_C(   314437015),  INT32_C(   424716369),  INT32_C(   140309582) },
      {  INT32_C(  1958190547), -INT32_C(  1527608653),  INT32_C(   597678634), -INT32_C(   563999459) },
       INT32_C(         238),
      { -INT32_C(   151544365), -INT32_C(  1224740937),  INT32_C(  1004534395), -INT32_C(   562102945) } },
    { {  INT32_C(   645976975),  INT32_C(   288898496),  INT32_C(   875202789),  INT32_C(  1329366908) },
      { -INT32_C(   674958556), -INT32_C(  1468221826), -INT32_C(  1362420848), -INT32_C(  1198772951) },
      { -INT32_C(  1059189504),  INT32_C(   819009098),  INT32_C(   442825886), -INT32_C(  1486249853) },
       INT32_C(         239),
      { -INT32_C(   536871052), -INT32_C(    16779649), -INT32_C(          98), -INT32_C(  1074790997) } },
  };

  simde__m128i a, b, c, r;

  a = simde_x_mm_loadu_epi32(test_vec[0].a);
  b = simde_x_mm_loadu_epi32(test_vec[0].b);
  c = simde_x_mm_loadu_epi32(test_vec[0].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         232));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[0].r));

  a = simde_x_mm_loadu_epi32(test_vec[1].a);
  b = simde_x_mm_loadu_epi32(test_vec[1].b);
  c = simde_x_mm_loadu_epi32(test_vec[1].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         233));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[1].r));

  a = simde_x_mm_loadu_epi32(test_vec[2].a);
  b = simde_x_mm_loadu_epi32(test_vec[2].b);
  c = simde_x_mm_loadu_epi32(test_vec[2].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         234));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[2].r));

  a = simde_x_mm_loadu_epi32(test_vec[3].a);
  b = simde_x_mm_loadu_epi32(test_vec[3].b);
  c = simde_x_mm_loadu_epi32(test_vec[3].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         235));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[3].r));

  a = simde_x_mm_loadu_epi32(test_vec[4].a);
  b = simde_x_mm_loadu_epi32(test_vec[4].b);
  c = simde_x_mm_loadu_epi32(test_vec[4].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         236));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[4].r));

  a = simde_x_mm_loadu_epi32(test_vec[5].a);
  b = simde_x_mm_loadu_epi32(test_vec[5].b);
  c = simde_x_mm_loadu_epi32(test_vec[5].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         237));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[5].r));

  a = simde_x_mm_loadu_epi32(test_vec[6].a);
  b = simde_x_mm_loadu_epi32(test_vec[6].b);
  c = simde_x_mm_loadu_epi32(test_vec[6].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         238));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[6].r));

  a = simde_x_mm_loadu_epi32(test_vec[7].a);
  b = simde_x_mm_loadu_epi32(test_vec[7].b);
  c = simde_x_mm_loadu_epi32(test_vec[7].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         239));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[7].r));

  return 0;
#else
  fputc('\n', stdout);
  for (int i = (192+32) ; i < 256 ; i++) {
    simde__m128i a = simde_test_x86_random_i32x4();
    simde__m128i b = simde_test_x86_random_i32x4();
    simde__m128i c = simde_test_x86_random_i32x4();
    simde__m128i r;
    SIMDE_CONSTIFY_32_8(simde_mm_ternarylogic_epi32, r, simde_mm_setzero_si128(), i, a, b, c);

    simde_test_x86_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, i, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_ternarylogic_epi32_31 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t a[4];
    const int32_t b[4];
    const int32_t c[4];
    const int32_t imm8;
    const int32_t r[4];
  } test_vec[] = {
    { {  INT32_C(   293481875),  INT32_C(  1958345444),  INT32_C(  1059226646), -INT32_C(  1309167695) },
      {  INT32_C(   108123580), -INT32_C(  1992932373), -INT32_C(  1029465537), -INT32_C(   831976390) },
      {  INT32_C(   517990202), -INT32_C(   124610078), -INT32_C(   818432739),  INT32_C(   545271396) },
       INT32_C(         240),
      {  INT32_C(   293481875),  INT32_C(  1958345444),  INT32_C(  1059226646), -INT32_C(  1309167695) } },
    { { -INT32_C(   299437565),  INT32_C(  1953979701),  INT32_C(   842406647),  INT32_C(  1610653478) },
      {  INT32_C(  1753145222), -INT32_C(  1772088968),  INT32_C(   711301062), -INT32_C(   934615611) },
      {  INT32_C(   213283031), -INT32_C(   981455411),  INT32_C(  1861727815), -INT32_C(   590416043) },
       INT32_C(         241),
      { -INT32_C(    14159317),  INT32_C(  2088754999), -INT32_C(  1287759105),  INT32_C(  1664196398) } },
    { {  INT32_C(  1329876438),  INT32_C(   619029854),  INT32_C(    38685244),  INT32_C(   130717743) },
      { -INT32_C(   703364856), -INT32_C(   157576018), -INT32_C(  1604021686),  INT32_C(  1601974921) },
      { -INT32_C(   575750017), -INT32_C(  1576955035),  INT32_C(   228872157), -INT32_C(   267096345) },
       INT32_C(         242),
      {  INT32_C(  1340886519),  INT32_C(   619030367),  INT32_C(   265179069), -INT32_C(  1479877521) } },
    { { -INT32_C(  1631180817),  INT32_C(   110387643),  INT32_C(  2091317491), -INT32_C(  1428479446) },
      {  INT32_C(  1216842466), -INT32_C(    68515555), -INT32_C(  1073180968), -INT32_C(   324002564) },
      { -INT32_C(     7702973), -INT32_C(   905634089),  INT32_C(  1078373142), -INT32_C(  1343610419) },
       INT32_C(         243),
      { -INT32_C(  1073842177),  INT32_C(   110458875),  INT32_C(  2146957815), -INT32_C(  1142955221) } },
    { { -INT32_C(   906530133), -INT32_C(   742071813),  INT32_C(  1821625455),  INT32_C(   727204840) },
      { -INT32_C(  1876237639),  INT32_C(   375009024), -INT32_C(  1487494950),  INT32_C(  1834435010) },
      { -INT32_C(  1372172621), -INT32_C(  1618871760), -INT32_C(  1375005242),  INT32_C(   316302168) },
       INT32_C(         244),
      { -INT32_C(   637537621), -INT32_C(   740366853),  INT32_C(  1842867327),  INT32_C(  1868383210) } },
    { {  INT32_C(  1168245829),  INT32_C(   240909620),  INT32_C(  1605808797), -INT32_C(  1496510989) },
      { -INT32_C(  1957428389), -INT32_C(  1003760130),  INT32_C(  1131624170), -INT32_C(   548057702) },
      { -INT32_C(  2061109423), -INT32_C(  1835761420),  INT32_C(   636570162), -INT32_C(  1295270313) },
       INT32_C(         245),
      {  INT32_C(  2147093743),  INT32_C(  1870397247), -INT32_C(   541149219), -INT32_C(   268612101) } },
    { { -INT32_C(  1069670462), -INT32_C(   544970251),  INT32_C(   958592927), -INT32_C(  1776715964) },
      {  INT32_C(  1662729839), -INT32_C(   235556930),  INT32_C(  1343678457),  INT32_C(  1728307877) },
      { -INT32_C(   165199615),  INT32_C(  1238805674), -INT32_C(   394004317), -INT32_C(   545350544) },
       INT32_C(         246),
      { -INT32_C(   717324306), -INT32_C(     5805067), -INT32_C(  1179123745), -INT32_C(  1099071531) } },
    { { -INT32_C(  1740465702),  INT32_C(  1116289097), -INT32_C(   996958177), -INT32_C(  2094229886) },
      { -INT32_C(  2122689577), -INT32_C(  1547022081), -INT32_C(  1198830264), -INT32_C(  1013511703) },
      { -INT32_C(   346236254),  INT32_C(   825156882),  INT32_C(   133546373),  INT32_C(   780869975) },
       INT32_C(         247),
      { -INT32_C(    18366977), -INT32_C(   553795603), -INT32_C(       16641), -INT32_C(     8585538) } },
  };

  simde__m128i a, b, c, r;

  a = simde_x_mm_loadu_epi32(test_vec[0].a);
  b = simde_x_mm_loadu_epi32(test_vec[0].b);
  c = simde_x_mm_loadu_epi32(test_vec[0].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         240));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[0].r));

  a = simde_x_mm_loadu_epi32(test_vec[1].a);
  b = simde_x_mm_loadu_epi32(test_vec[1].b);
  c = simde_x_mm_loadu_epi32(test_vec[1].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         241));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[1].r));

  a = simde_x_mm_loadu_epi32(test_vec[2].a);
  b = simde_x_mm_loadu_epi32(test_vec[2].b);
  c = simde_x_mm_loadu_epi32(test_vec[2].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         242));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[2].r));

  a = simde_x_mm_loadu_epi32(test_vec[3].a);
  b = simde_x_mm_loadu_epi32(test_vec[3].b);
  c = simde_x_mm_loadu_epi32(test_vec[3].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         243));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[3].r));

  a = simde_x_mm_loadu_epi32(test_vec[4].a);
  b = simde_x_mm_loadu_epi32(test_vec[4].b);
  c = simde_x_mm_loadu_epi32(test_vec[4].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         244));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[4].r));

  a = simde_x_mm_loadu_epi32(test_vec[5].a);
  b = simde_x_mm_loadu_epi32(test_vec[5].b);
  c = simde_x_mm_loadu_epi32(test_vec[5].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         245));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[5].r));

  a = simde_x_mm_loadu_epi32(test_vec[6].a);
  b = simde_x_mm_loadu_epi32(test_vec[6].b);
  c = simde_x_mm_loadu_epi32(test_vec[6].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         246));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[6].r));

  a = simde_x_mm_loadu_epi32(test_vec[7].a);
  b = simde_x_mm_loadu_epi32(test_vec[7].b);
  c = simde_x_mm_loadu_epi32(test_vec[7].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         247));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[7].r));

  return 0;
#else
  fputc('\n', stdout);
  for (int i = (192+32) ; i < 256 ; i++) {
    simde__m128i a = simde_test_x86_random_i32x4();
    simde__m128i b = simde_test_x86_random_i32x4();
    simde__m128i c = simde_test_x86_random_i32x4();
    simde__m128i r;
    SIMDE_CONSTIFY_32_8(simde_mm_ternarylogic_epi32, r, simde_mm_setzero_si128(), i, a, b, c);

    simde_test_x86_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, i, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_ternarylogic_epi32_32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t a[4];
    const int32_t b[4];
    const int32_t c[4];
    const int32_t imm8;
    const int32_t r[4];
  } test_vec[] = {
    { {  INT32_C(  1957627253), -INT32_C(  1659405995), -INT32_C(  1336499513),  INT32_C(  1316285867) },
      { -INT32_C(   650522425),  INT32_C(   990537653),  INT32_C(  2135031848), -INT32_C(  1766994655) },
      {  INT32_C(   655056082), -INT32_C(  1648024874),  INT32_C(  1884101573), -INT32_C(   792805112) },
       INT32_C(         248),
      {  INT32_C(  1974425079), -INT32_C(  1659405355), -INT32_C(   262757689), -INT32_C(   553849429) } },
    { {  INT32_C(  1202321553), -INT32_C(  2004700065), -INT32_C(   720911180),  INT32_C(  1684845970) },
      { -INT32_C(   410224879),  INT32_C(  1585729945),  INT32_C(  1959776876),  INT32_C(   625249683) },
      { -INT32_C(   445845883),  INT32_C(  1450045090),  INT32_C(  1143698610),  INT32_C(  1000970025) },
       INT32_C(         249),
      { -INT32_C(     4194565), -INT32_C(     6884129), -INT32_C(   551559755), -INT32_C(   444664361) } },
    { { -INT32_C(  1474153202), -INT32_C(   234444922),  INT32_C(   208065913), -INT32_C(   399398045) },
      {  INT32_C(  1003330969),  INT32_C(  1049705099), -INT32_C(   662520657),  INT32_C(  1645423444) },
      { -INT32_C(   435538336),  INT32_C(  1457000925),  INT32_C(  1231175654), -INT32_C(  2093837078) },
       INT32_C(         250),
      { -INT32_C(   299223186), -INT32_C(   153176097),  INT32_C(  1298595839), -INT32_C(   348930069) } },
    { { -INT32_C(  1111556303), -INT32_C(   369406150),  INT32_C(  1606515979),  INT32_C(   163763625) },
      { -INT32_C(   386872309), -INT32_C(  1002518307), -INT32_C(   250765305),  INT32_C(  1718894388) },
      {  INT32_C(  2032349759), -INT32_C(  1922949503),  INT32_C(  1156326299),  INT32_C(    55488248) },
       INT32_C(         251),
      { -INT32_C(     4194305), -INT32_C(      294981),  INT32_C(  1610579963), -INT32_C(  1680867333) } },
    { {  INT32_C(  1491811963),  INT32_C(   236726534), -INT32_C(    16831798), -INT32_C(  1469811607) },
      {  INT32_C(   673286054),  INT32_C(  1102414757), -INT32_C(  1618632281), -INT32_C(   878455984) },
      {  INT32_C(   404983313), -INT32_C(  2111422280), -INT32_C(   746576534),  INT32_C(  1081927065) },
       INT32_C(         252),
      {  INT32_C(  2028716031),  INT32_C(  1337830311), -INT32_C(       21521), -INT32_C(   337119367) } },
    { {  INT32_C(   308845932), -INT32_C(   934077151),  INT32_C(   241686718), -INT32_C(  1109849428) },
      {  INT32_C(  1372978585), -INT32_C(  1479279811), -INT32_C(  1166388447), -INT32_C(  1510279624) },
      { -INT32_C(  1246272876),  INT32_C(  1048382079), -INT32_C(  1907563294), -INT32_C(  2008275217) },
       INT32_C(         253),
      {  INT32_C(  1543372287), -INT32_C(   271319107), -INT32_C(        9281), -INT32_C(      262212) } },
    { {  INT32_C(  1624842531),  INT32_C(  1040690205),  INT32_C(   955810303),  INT32_C(   215872376) },
      { -INT32_C(   708733867), -INT32_C(  2146222434),  INT32_C(   286220066), -INT32_C(  1466344571) },
      { -INT32_C(  1727499652),  INT32_C(   517410590),  INT32_C(   156684433),  INT32_C(   404042691) },
       INT32_C(         254),
      { -INT32_C(    36046977), -INT32_C(  1093156961),  INT32_C(   973070335), -INT32_C(  1126302721) } },
    { {  INT32_C(  1710085831),  INT32_C(   920977428), -INT32_C(   448203680), -INT32_C(   863051441) },
      {  INT32_C(  1919260244),  INT32_C(   932199846), -INT32_C(   801053171), -INT32_C(   521644775) },
      {  INT32_C(  1061541419),  INT32_C(   913648598),  INT32_C(  1864154399), -INT32_C(   214193505) },
       INT32_C(         255),
      { -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1) } },
  };

  simde__m128i a, b, c, r;

  a = simde_x_mm_loadu_epi32(test_vec[0].a);
  b = simde_x_mm_loadu_epi32(test_vec[0].b);
  c = simde_x_mm_loadu_epi32(test_vec[0].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         248));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[0].r));

  a = simde_x_mm_loadu_epi32(test_vec[1].a);
  b = simde_x_mm_loadu_epi32(test_vec[1].b);
  c = simde_x_mm_loadu_epi32(test_vec[1].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         249));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[1].r));

  a = simde_x_mm_loadu_epi32(test_vec[2].a);
  b = simde_x_mm_loadu_epi32(test_vec[2].b);
  c = simde_x_mm_loadu_epi32(test_vec[2].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         250));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[2].r));

  a = simde_x_mm_loadu_epi32(test_vec[3].a);
  b = simde_x_mm_loadu_epi32(test_vec[3].b);
  c = simde_x_mm_loadu_epi32(test_vec[3].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         251));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[3].r));

  a = simde_x_mm_loadu_epi32(test_vec[4].a);
  b = simde_x_mm_loadu_epi32(test_vec[4].b);
  c = simde_x_mm_loadu_epi32(test_vec[4].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         252));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[4].r));

  a = simde_x_mm_loadu_epi32(test_vec[5].a);
  b = simde_x_mm_loadu_epi32(test_vec[5].b);
  c = simde_x_mm_loadu_epi32(test_vec[5].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         253));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[5].r));

  a = simde_x_mm_loadu_epi32(test_vec[6].a);
  b = simde_x_mm_loadu_epi32(test_vec[6].b);
  c = simde_x_mm_loadu_epi32(test_vec[6].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         254));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[6].r));

  a = simde_x_mm_loadu_epi32(test_vec[7].a);
  b = simde_x_mm_loadu_epi32(test_vec[7].b);
  c = simde_x_mm_loadu_epi32(test_vec[7].c);
  r = simde_mm_ternarylogic_epi32(a, b, c, INT32_C(         255));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[7].r));

  return 0;
#else
  fputc('\n', stdout);
  for (int i = (192+32) ; i < 256 ; i++) {
    simde__m128i a = simde_test_x86_random_i32x4();
    simde__m128i b = simde_test_x86_random_i32x4();
    simde__m128i c = simde_test_x86_random_i32x4();
    simde__m128i r;
    SIMDE_CONSTIFY_32_8(simde_mm_ternarylogic_epi32, r, simde_mm_setzero_si128(), i, a, b, c);

    simde_test_x86_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, i, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_mask_ternarylogic_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t src[4];
    const simde__mmask8 k;
    const int32_t a[4];
    const int32_t b[4];
    const int32_t imm8;
    const int32_t r[4];
  } test_vec[] = {
    { { -INT32_C(   647521179), -INT32_C(   595294866),  INT32_C(  2095795047),  INT32_C(  1622757679) },
      UINT8_C(164),
      {  INT32_C(   234028808), -INT32_C(   552784754),  INT32_C(  2124080440), -INT32_C(   924597204) },
      { -INT32_C(  1321747412), -INT32_C(  1944513728),  INT32_C(  1337693694),  INT32_C(  1475550030) },
       INT32_C(          26),
      { -INT32_C(   647521179), -INT32_C(   595294866),  INT32_C(    55615129),  INT32_C(  1622757679) } },
    { {  INT32_C(  1250455826), -INT32_C(  2084036010),  INT32_C(   323726311), -INT32_C(  1463516568) },
      UINT8_C(149),
      {  INT32_C(  1922315485),  INT32_C(   180478959), -INT32_C(  1138485033), -INT32_C(   305214084) },
      {  INT32_C(  2000886101), -INT32_C(  1923168543), -INT32_C(  1795854062),  INT32_C(   321559862) },
       INT32_C(         210),
      {  INT32_C(  1338734610), -INT32_C(  2084036010),  INT32_C(   328911591), -INT32_C(  1463516568) } },
    { {  INT32_C(  2026653601), -INT32_C(   617222049),  INT32_C(   315098045), -INT32_C(    24507620) },
      UINT8_C(210),
      {  INT32_C(  1524927464),  INT32_C(   496007296),  INT32_C(  1626317730),  INT32_C(  1879224617) },
      {  INT32_C(  1842313853), -INT32_C(  1288983889),  INT32_C(  2127510898), -INT32_C(  1336881721) },
       INT32_C(          88),
      {  INT32_C(  2026653601),  INT32_C(  1209293008),  INT32_C(   315098045), -INT32_C(    24507620) } },
    { {  INT32_C(  1341561516),  INT32_C(  1739580733),  INT32_C(   332902806), -INT32_C(   612260052) },
      UINT8_C( 81),
      { -INT32_C(   372994388),  INT32_C(   733037150), -INT32_C(   964402798),  INT32_C(    91380843) },
      {  INT32_C(   943898962),  INT32_C(   583969137),  INT32_C(   676258433),  INT32_C(   259598947) },
       INT32_C(         184),
      {  INT32_C(   779259904),  INT32_C(  1739580733),  INT32_C(   332902806), -INT32_C(   612260052) } },
    { {  INT32_C(   289581439),  INT32_C(  1977075210),  INT32_C(  1970948642),  INT32_C(  2091760907) },
      UINT8_C(102),
      {  INT32_C(  1575460731),  INT32_C(   398462957), -INT32_C(   959393911),  INT32_C(  1900472008) },
      { -INT32_C(   293841112),  INT32_C(  2031218991),  INT32_C(   696551020), -INT32_C(  1366359757) },
       INT32_C(         160),
      {  INT32_C(   289581439),  INT32_C(  1896988682),  INT32_C(   553648672),  INT32_C(  2091760907) } },
    { {  INT32_C(   262524038),  INT32_C(  1691776412), -INT32_C(  2066408357), -INT32_C(  1569566349) },
      UINT8_C( 67),
      {  INT32_C(   162470787), -INT32_C(  1589847904), -INT32_C(   566105241), -INT32_C(  1016738057) },
      { -INT32_C(   396397453),  INT32_C(  1715782474), -INT32_C(   354760551), -INT32_C(  1104315334) },
       INT32_C(         152),
      {  INT32_C(   235900935),  INT32_C(   545711124), -INT32_C(  2066408357), -INT32_C(  1569566349) } },
    { {  INT32_C(   483984564), -INT32_C(   419816721),  INT32_C(  1554604008),  INT32_C(   507775444) },
      UINT8_C(204),
      {  INT32_C(  1348830600), -INT32_C(   611626913),  INT32_C(  1517504893),  INT32_C(   336505616) },
      { -INT32_C(  1643959676), -INT32_C(  2071467739), -INT32_C(  1671896173), -INT32_C(  1335331033) },
       INT32_C(         252),
      {  INT32_C(   483984564), -INT32_C(   419816721),  INT32_C(  1593532413),  INT32_C(   508472276) } },
    { { -INT32_C(  1690924258), -INT32_C(   436884780), -INT32_C(   621214635),  INT32_C(  1400438062) },
      UINT8_C(230),
      { -INT32_C(   495331073), -INT32_C(  1492511440),  INT32_C(  1285798526),  INT32_C(  1181417146) },
      { -INT32_C(   551942859), -INT32_C(    13303813), -INT32_C(   164819207), -INT32_C(  2032369273) },
       INT32_C(          89),
      { -INT32_C(  1690924258),  INT32_C(    46208292),  INT32_C(   231754540),  INT32_C(  1400438062) } },
  };

  simde__m128i src, a, b, r;

  src = simde_x_mm_loadu_epi32(test_vec[0].src);
  a = simde_x_mm_loadu_epi32(test_vec[0].a);
  b = simde_x_mm_loadu_epi32(test_vec[0].b);
  r = simde_mm_mask_ternarylogic_epi32(src, test_vec[0].k, a, b, INT32_C(          26));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[0].r));

  src = simde_x_mm_loadu_epi32(test_vec[1].src);
  a = simde_x_mm_loadu_epi32(test_vec[1].a);
  b = simde_x_mm_loadu_epi32(test_vec[1].b);
  r = simde_mm_mask_ternarylogic_epi32(src, test_vec[1].k, a, b, INT32_C(         210));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[1].r));

  src = simde_x_mm_loadu_epi32(test_vec[2].src);
  a = simde_x_mm_loadu_epi32(test_vec[2].a);
  b = simde_x_mm_loadu_epi32(test_vec[2].b);
  r = simde_mm_mask_ternarylogic_epi32(src, test_vec[2].k, a, b, INT32_C(          88));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[2].r));

  src = simde_x_mm_loadu_epi32(test_vec[3].src);
  a = simde_x_mm_loadu_epi32(test_vec[3].a);
  b = simde_x_mm_loadu_epi32(test_vec[3].b);
  r = simde_mm_mask_ternarylogic_epi32(src, test_vec[3].k, a, b, INT32_C(         184));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[3].r));

  src = simde_x_mm_loadu_epi32(test_vec[4].src);
  a = simde_x_mm_loadu_epi32(test_vec[4].a);
  b = simde_x_mm_loadu_epi32(test_vec[4].b);
  r = simde_mm_mask_ternarylogic_epi32(src, test_vec[4].k, a, b, INT32_C(         160));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[4].r));

  src = simde_x_mm_loadu_epi32(test_vec[5].src);
  a = simde_x_mm_loadu_epi32(test_vec[5].a);
  b = simde_x_mm_loadu_epi32(test_vec[5].b);
  r = simde_mm_mask_ternarylogic_epi32(src, test_vec[5].k, a, b, INT32_C(         152));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[5].r));

  src = simde_x_mm_loadu_epi32(test_vec[6].src);
  a = simde_x_mm_loadu_epi32(test_vec[6].a);
  b = simde_x_mm_loadu_epi32(test_vec[6].b);
  r = simde_mm_mask_ternarylogic_epi32(src, test_vec[6].k, a, b, INT32_C(         252));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[6].r));

  src = simde_x_mm_loadu_epi32(test_vec[7].src);
  a = simde_x_mm_loadu_epi32(test_vec[7].a);
  b = simde_x_mm_loadu_epi32(test_vec[7].b);
  r = simde_mm_mask_ternarylogic_epi32(src, test_vec[7].k, a, b, INT32_C(          89));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[7].r));

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i src = simde_test_x86_random_i32x4();
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128i a = simde_test_x86_random_i32x4();
    simde__m128i b = simde_test_x86_random_i32x4();
    int imm8 = simde_test_codegen_random_i32() & 255;
    simde__m128i r;
    SIMDE_CONSTIFY_256_(simde_mm_mask_ternarylogic_epi32, r, simde_mm_setzero_si128(), imm8, src, k, a, b);

    simde_test_x86_write_i32x4(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_maskz_ternarylogic_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const int32_t a[4];
    const int32_t b[4];
    const int32_t c[4];
    const int32_t imm8;
    const int32_t r[4];
  } test_vec[] = {
    { UINT8_C(107),
      {  INT32_C(   770257267), -INT32_C(   739822124), -INT32_C(  1526190689),  INT32_C(  1201727304) },
      {  INT32_C(   708878107),  INT32_C(  1303459532),  INT32_C(  1772500755),  INT32_C(   332673184) },
      {  INT32_C(   893435489), -INT32_C(  1828181773), -INT32_C(  1657270187),  INT32_C(   333830391) },
       INT32_C(         119),
      { -INT32_C(   541105666), -INT32_C(    16785601),  INT32_C(           0), -INT32_C(   331616417) } },
    { UINT8_C( 92),
      {  INT32_C(   628068846),  INT32_C(  1741084727),  INT32_C(  1791547820),  INT32_C(  1113521690) },
      {  INT32_C(   395833606),  INT32_C(    17708329),  INT32_C(  1064837402),  INT32_C(  1285274462) },
      { -INT32_C(  2072901044), -INT32_C(  1880409886),  INT32_C(   737784849), -INT32_C(  1200793678) },
       INT32_C(          72),
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(    19931416),  INT32_C(  1209248008) } },
    { UINT8_C( 58),
      { -INT32_C(    11242786), -INT32_C(  1503751190),  INT32_C(   972204591),  INT32_C(  1411151388) },
      {  INT32_C(   375827298), -INT32_C(    53964380),  INT32_C(    71598335),  INT32_C(   775861840) },
      {  INT32_C(   321753640),  INT32_C(  1421445925),  INT32_C(  1385081654), -INT32_C(  2069386718) },
       INT32_C(          85),
      {  INT32_C(           0), -INT32_C(  1421445926),  INT32_C(           0),  INT32_C(  2069386717) } },
    { UINT8_C(158),
      { -INT32_C(   492964510), -INT32_C(   265117382),  INT32_C(  1897423071),  INT32_C(   429337486) },
      { -INT32_C(  1873810460),  INT32_C(   598909561),  INT32_C(  1450718793),  INT32_C(   854880976) },
      { -INT32_C(  1592487321),  INT32_C(   328288051),  INT32_C(   897886887), -INT32_C(  1169220651) },
       INT32_C(           7),
      {  INT32_C(           0),  INT32_C(   206396612), -INT32_C(  1964532448), -INT32_C(  1003961311) } },
    { UINT8_C( 64),
      {  INT32_C(   847881468), -INT32_C(  1912414436),  INT32_C(  1727411412), -INT32_C(  1885759672) },
      { -INT32_C(   751326167),  INT32_C(  1286106161),  INT32_C(  1515414203), -INT32_C(  1466248020) },
      { -INT32_C(  1797643144), -INT32_C(   685515773),  INT32_C(  1497176336), -INT32_C(   639051856) },
       INT32_C(         131),
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { UINT8_C(140),
      { -INT32_C(  1220083371),  INT32_C(   677683540),  INT32_C(  1621101628), -INT32_C(  1016908313) },
      {  INT32_C(  1909734232),  INT32_C(  1327574392),  INT32_C(   903084821), -INT32_C(    54425689) },
      { -INT32_C(   575403896), -INT32_C(   435873622),  INT32_C(   189179428),  INT32_C(   869247451) },
       INT32_C(         228),
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(   881941813), -INT32_C(   817682457) } },
    { UINT8_C(208),
      { -INT32_C(  1058689851),  INT32_C(   124263039), -INT32_C(   460364581),  INT32_C(   814640152) },
      {  INT32_C(   408253554),  INT32_C(  1676894394), -INT32_C(   767023569), -INT32_C(  1885166134) },
      { -INT32_C(   783251375),  INT32_C(  2128132258),  INT32_C(   895641372),  INT32_C(  1181085908) },
       INT32_C(         100),
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { UINT8_C( 27),
      {  INT32_C(  2001371473),  INT32_C(  1849761225),  INT32_C(  1203818687), -INT32_C(   655716064) },
      { -INT32_C(   789223319), -INT32_C(  1163646262),  INT32_C(  1243540111), -INT32_C(  1721418680) },
      { -INT32_C(  2028949571), -INT32_C(  1930079796),  INT32_C(  1121170722), -INT32_C(  1357136570) },
       INT32_C(          37),
      {  INT32_C(   262525202),  INT32_C(   357282610),  INT32_C(           0),  INT32_C(      967577) } },
  };

  simde__m128i a, b, c, r;

  a = simde_x_mm_loadu_epi32(test_vec[0].a);
  b = simde_x_mm_loadu_epi32(test_vec[0].b);
  c = simde_x_mm_loadu_epi32(test_vec[0].c);
  r = simde_mm_maskz_ternarylogic_epi32(test_vec[0].k, a, b, c, INT32_C(         119));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[0].r));

  a = simde_x_mm_loadu_epi32(test_vec[1].a);
  b = simde_x_mm_loadu_epi32(test_vec[1].b);
  c = simde_x_mm_loadu_epi32(test_vec[1].c);
  r = simde_mm_maskz_ternarylogic_epi32(test_vec[1].k, a, b, c, INT32_C(          72));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[1].r));

  a = simde_x_mm_loadu_epi32(test_vec[2].a);
  b = simde_x_mm_loadu_epi32(test_vec[2].b);
  c = simde_x_mm_loadu_epi32(test_vec[2].c);
  r = simde_mm_maskz_ternarylogic_epi32(test_vec[2].k, a, b, c, INT32_C(          85));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[2].r));

  a = simde_x_mm_loadu_epi32(test_vec[3].a);
  b = simde_x_mm_loadu_epi32(test_vec[3].b);
  c = simde_x_mm_loadu_epi32(test_vec[3].c);
  r = simde_mm_maskz_ternarylogic_epi32(test_vec[3].k, a, b, c, INT32_C(           7));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[3].r));

  a = simde_x_mm_loadu_epi32(test_vec[4].a);
  b = simde_x_mm_loadu_epi32(test_vec[4].b);
  c = simde_x_mm_loadu_epi32(test_vec[4].c);
  r = simde_mm_maskz_ternarylogic_epi32(test_vec[4].k, a, b, c, INT32_C(         131));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[4].r));

  a = simde_x_mm_loadu_epi32(test_vec[5].a);
  b = simde_x_mm_loadu_epi32(test_vec[5].b);
  c = simde_x_mm_loadu_epi32(test_vec[5].c);
  r = simde_mm_maskz_ternarylogic_epi32(test_vec[5].k, a, b, c, INT32_C(         228));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[5].r));

  a = simde_x_mm_loadu_epi32(test_vec[6].a);
  b = simde_x_mm_loadu_epi32(test_vec[6].b);
  c = simde_x_mm_loadu_epi32(test_vec[6].c);
  r = simde_mm_maskz_ternarylogic_epi32(test_vec[6].k, a, b, c, INT32_C(         100));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[6].r));

  a = simde_x_mm_loadu_epi32(test_vec[7].a);
  b = simde_x_mm_loadu_epi32(test_vec[7].b);
  c = simde_x_mm_loadu_epi32(test_vec[7].c);
  r = simde_mm_maskz_ternarylogic_epi32(test_vec[7].k, a, b, c, INT32_C(          37));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[7].r));

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128i a = simde_test_x86_random_i32x4();
    simde__m128i b = simde_test_x86_random_i32x4();
    simde__m128i c = simde_test_x86_random_i32x4();
    int imm8 = simde_test_codegen_random_i32() & 255;
    simde__m128i r;
    SIMDE_CONSTIFY_256_(simde_mm_maskz_ternarylogic_epi32, r, simde_mm_setzero_si128(), imm8, k, a, b, c);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_ternarylogic_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t a[8];
    const int32_t b[8];
    const int32_t c[8];
    const int imm8;
    const int32_t r[8];
  } test_vec[] = {
    { { -INT32_C(   778161431),  INT32_C(   708955983), -INT32_C(  1946055234), -INT32_C(   778468953), -INT32_C(   483092156),  INT32_C(  1446277692),  INT32_C(    10996751), -INT32_C(    31586283) },
      { -INT32_C(  1966097094),  INT32_C(  1253314700),  INT32_C(  1154987421),  INT32_C(  2065002550),  INT32_C(  1163806985), -INT32_C(   878996548),  INT32_C(  1959543647), -INT32_C(  2056066485) },
      {  INT32_C(   873415335), -INT32_C(   260127662), -INT32_C(  1338747527), -INT32_C(   819246395),  INT32_C(  1326746003),  INT32_C(  2082189340),  INT32_C(  1055975411),  INT32_C(  2042848209) },
       INT32_C(         165),
      {  INT32_C(   443453361),  INT32_C(   633402594), -INT32_C(  1010161864), -INT32_C(   515033955),  INT32_C(  1407184680), -INT32_C(   707772961), -INT32_C(  1045900285),  INT32_C(  2015532091) } },
    { {  INT32_C(   283585431),  INT32_C(  1186995329), -INT32_C(   116003994), -INT32_C(  1857475979), -INT32_C(   854760230),  INT32_C(   470548043),  INT32_C(   110480993),  INT32_C(   956121761) },
      { -INT32_C(   280369810),  INT32_C(  1731528961),  INT32_C(  1784695797),  INT32_C(  1341892981),  INT32_C(  1478232333),  INT32_C(  1752508167), -INT32_C(  1754395915), -INT32_C(  1144034483) },
      {  INT32_C(  1370101840),  INT32_C(   397991714), -INT32_C(  1618929366), -INT32_C(   789676862), -INT32_C(  1943532923),  INT32_C(   670342449), -INT32_C(   172072280),  INT32_C(   514887118) },
       INT32_C(         166),
      { -INT32_C(  1096623048),  INT32_C(   915267106), -INT32_C(  1646192197), -INT32_C(  1638072894), -INT32_C(  1674050688),  INT32_C(  1199610933),  INT32_C(  1691640380), -INT32_C(  1649236862) } },
    { {  INT32_C(  1692346425),  INT32_C(    67330113),  INT32_C(  1658122972),  INT32_C(   787414268),  INT32_C(  1112925082),  INT32_C(   322376517),  INT32_C(  1177741216),  INT32_C(  2047779393) },
      {  INT32_C(   215936458),  INT32_C(   705749581), -INT32_C(   796072748),  INT32_C(  2063497952), -INT32_C(  1547938979),  INT32_C(   129430374),  INT32_C(   458090714),  INT32_C(  1435917450) },
      { -INT32_C(  1755220919),  INT32_C(   717320534),  INT32_C(   905661781),  INT32_C(   632355271), -INT32_C(  1278710707),  INT32_C(   985300576), -INT32_C(   246019993), -INT32_C(  1387860892) },
       INT32_C(          96),
      {  INT32_C(    10422273),  INT32_C(       65537),  INT32_C(  1616158848),  INT32_C(   240025636),  INT32_C(     5514000),  INT32_C(   285475076),  INT32_C(  1108533408),  INT32_C(  2013306944) } },
    { {  INT32_C(  1843463448),  INT32_C(   446946386),  INT32_C(   591352790),  INT32_C(   534120383), -INT32_C(   329608827), -INT32_C(    35737447), -INT32_C(    55958372), -INT32_C(   457969716) },
      {  INT32_C(  1196594676),  INT32_C(  1197602161),  INT32_C(   124428360),  INT32_C(   740770215),  INT32_C(  1796833746), -INT32_C(   848758991), -INT32_C(   406253029), -INT32_C(   154370815) },
      { -INT32_C(  2093146606),  INT32_C(  1540070931), -INT32_C(   446548674),  INT32_C(  1209108854),  INT32_C(  1001597450),  INT32_C(  1023941409),  INT32_C(   790942254),  INT32_C(  1629876303) },
       INT32_C(          14),
      { -INT32_C(  2111923482),  INT32_C(  1162355489), -INT32_C(  1002396632),  INT32_C(  1612826688),  INT32_C(   329329242),  INT32_C(     2117408),  INT32_C(    54907427),  INT32_C(   323751939) } },
    { {  INT32_C(  1048358656),  INT32_C(  1529077733),  INT32_C(  1940141416), -INT32_C(  2119280801), -INT32_C(  1581336717), -INT32_C(   657399159), -INT32_C(   516294957),  INT32_C(  1493376344) },
      { -INT32_C(  1298694195), -INT32_C(   955401378),  INT32_C(  1329246704),  INT32_C(  2094065673),  INT32_C(   673025695),  INT32_C(  1140911473),  INT32_C(  1009072611),  INT32_C(   613754967) },
      {  INT32_C(   114699432), -INT32_C(   674372633), -INT32_C(  1641609323), -INT32_C(  1894058000), -INT32_C(   138922106),  INT32_C(   138131492),  INT32_C(  1229218034),  INT32_C(   829282697) },
       INT32_C(           5),
      { -INT32_C(  1056878505),  INT32_C(   537919512),  INT32_C(     5818370),  INT32_C(  1883310080),  INT32_C(   138496008),  INT32_C(   654574930),  INT32_C(   377620748), -INT32_C(  2037374426) } },
    { { -INT32_C(  1144781530), -INT32_C(    61215988),  INT32_C(  1770812387), -INT32_C(   815774550), -INT32_C(   287859716), -INT32_C(  2076763141), -INT32_C(   105536268),  INT32_C(   250015207) },
      { -INT32_C(    20337678),  INT32_C(  2046501782),  INT32_C(  1105364886), -INT32_C(   955235637), -INT32_C(   642324515), -INT32_C(   161616638),  INT32_C(  2045711250), -INT32_C(   225978880) },
      {  INT32_C(   401625473),  INT32_C(   177335156),  INT32_C(  1028354930), -INT32_C(  1828365386),  INT32_C(  1147976514),  INT32_C(   976931496), -INT32_C(   575395107), -INT32_C(  2117125376) },
       INT32_C(         140),
      {  INT32_C(  1456057296),  INT32_C(   162734998),  INT32_C(    23234326), -INT32_C(  2096086333),  INT32_C(  1361372993),  INT32_C(  1918430208),  INT32_C(  1508774802), -INT32_C(   259583488) } },
    { {  INT32_C(   487270827),  INT32_C(  1398494877), -INT32_C(   186228558), -INT32_C(  1019653349), -INT32_C(    83987683), -INT32_C(  1646808419),  INT32_C(  2048829165),  INT32_C(   276477797) },
      {  INT32_C(  2100200928), -INT32_C(  1898935844),  INT32_C(    75675625),  INT32_C(   667400970), -INT32_C(   870202065),  INT32_C(  1701509239),  INT32_C(    64981150),  INT32_C(   538204479) },
      { -INT32_C(  1147321633), -INT32_C(  1270255925),  INT32_C(   800639781), -INT32_C(  1235845241), -INT32_C(  1132300475),  INT32_C(   220327023), -INT32_C(  1274019723),  INT32_C(   970204250) },
       INT32_C(         102),
      { -INT32_C(   961296577),  INT32_C(   983164695),  INT32_C(   725253324), -INT32_C(  1852717939),  INT32_C(  1889776234),  INT32_C(  1749750808), -INT32_C(  1211135765),  INT32_C(   432045413) } },
    { {  INT32_C(    98909664), -INT32_C(  1892377336),  INT32_C(  1648724509),  INT32_C(  1881065473),  INT32_C(   696074420), -INT32_C(  1696690880),  INT32_C(   416527026),  INT32_C(    72009508) },
      {  INT32_C(   218705668), -INT32_C(   358859315), -INT32_C(   934485305),  INT32_C(  1580755626), -INT32_C(   343362134), -INT32_C(   175806909),  INT32_C(  1024284952),  INT32_C(   625039136) },
      {  INT32_C(  1412582279),  INT32_C(  1346293384),  INT32_C(  1511557808), -INT32_C(  1615244812),  INT32_C(  1233797382), -INT32_C(  1086451801), -INT32_C(  1979954072),  INT32_C(   716062371) },
       INT32_C(         137),
      { -INT32_C(  1509913828),  INT32_C(  1079839930),  INT32_C(  1303025536),  INT32_C(   511198368),  INT32_C(  1569196867), -INT32_C(  1258023397),  INT32_C(  1259096077), -INT32_C(   267381128) } },
  };

  simde__m256i a, b, c, r;

  a = simde_x_mm256_loadu_epi32(test_vec[0].a);
  b = simde_x_mm256_loadu_epi32(test_vec[0].b);
  c = simde_x_mm256_loadu_epi32(test_vec[0].c);
  r = simde_mm256_ternarylogic_epi32(a, b, c, INT32_C(         165));
  simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[0].r));

  a = simde_x_mm256_loadu_epi32(test_vec[1].a);
  b = simde_x_mm256_loadu_epi32(test_vec[1].b);
  c = simde_x_mm256_loadu_epi32(test_vec[1].c);
  r = simde_mm256_ternarylogic_epi32(a, b, c, INT32_C(         166));
  simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[1].r));

  a = simde_x_mm256_loadu_epi32(test_vec[2].a);
  b = simde_x_mm256_loadu_epi32(test_vec[2].b);
  c = simde_x_mm256_loadu_epi32(test_vec[2].c);
  r = simde_mm256_ternarylogic_epi32(a, b, c, INT32_C(          96));
  simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[2].r));

  a = simde_x_mm256_loadu_epi32(test_vec[3].a);
  b = simde_x_mm256_loadu_epi32(test_vec[3].b);
  c = simde_x_mm256_loadu_epi32(test_vec[3].c);
  r = simde_mm256_ternarylogic_epi32(a, b, c, INT32_C(          14));
  simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[3].r));

  a = simde_x_mm256_loadu_epi32(test_vec[4].a);
  b = simde_x_mm256_loadu_epi32(test_vec[4].b);
  c = simde_x_mm256_loadu_epi32(test_vec[4].c);
  r = simde_mm256_ternarylogic_epi32(a, b, c, INT32_C(           5));
  simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[4].r));

  a = simde_x_mm256_loadu_epi32(test_vec[5].a);
  b = simde_x_mm256_loadu_epi32(test_vec[5].b);
  c = simde_x_mm256_loadu_epi32(test_vec[5].c);
  r = simde_mm256_ternarylogic_epi32(a, b, c, INT32_C(         140));
  simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[5].r));

  a = simde_x_mm256_loadu_epi32(test_vec[6].a);
  b = simde_x_mm256_loadu_epi32(test_vec[6].b);
  c = simde_x_mm256_loadu_epi32(test_vec[6].c);
  r = simde_mm256_ternarylogic_epi32(a, b, c, INT32_C(         102));
  simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[6].r));

  a = simde_x_mm256_loadu_epi32(test_vec[7].a);
  b = simde_x_mm256_loadu_epi32(test_vec[7].b);
  c = simde_x_mm256_loadu_epi32(test_vec[7].c);
  r = simde_mm256_ternarylogic_epi32(a, b, c, INT32_C(         137));
  simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[7].r));

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256i a = simde_test_x86_random_i32x8();
    simde__m256i b = simde_test_x86_random_i32x8();
    simde__m256i c = simde_test_x86_random_i32x8();
    int imm8 = simde_test_codegen_random_i32() & 255;
    simde__m256i r;
    SIMDE_CONSTIFY_256_(simde_mm256_ternarylogic_epi32, r, simde_mm256_setzero_si256(), imm8, a, b, c);

    simde_test_x86_write_i32x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x8(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_mask_ternarylogic_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t src[8];
    const simde__mmask8 k;
    const int32_t a[8];
    const int32_t b[8];
    const int imm8;
    const int32_t r[8];
  } test_vec[] = {
    { {  INT32_C(    28489634), -INT32_C(   923935123),  INT32_C(  1861593042),  INT32_C(  1431001874), -INT32_C(   442290738), -INT32_C(   696135909),  INT32_C(   486912740),  INT32_C(   991035545) },
      UINT8_C(183),
      { -INT32_C(  1557905979), -INT32_C(   763957974),  INT32_C(  1038410978),  INT32_C(  1544239663), -INT32_C(  1401359907),  INT32_C(   613502578),  INT32_C(  1421717076), -INT32_C(  2062747456) },
      {  INT32_C(  1613312053),  INT32_C(     3317533), -INT32_C(  1304619389),  INT32_C(   772688208), -INT32_C(  1394964934),  INT32_C(   701524949), -INT32_C(   629306087), -INT32_C(  1151366779) },
       INT32_C(         186),
      {  INT32_C(  1622913591),  INT32_C(   146513757), -INT32_C(   230877293),  INT32_C(  1431001874), -INT32_C(   304378310), -INT32_C(    70194211),  INT32_C(   486912740), -INT32_C(  1151366755) } },
    { { -INT32_C(  1428730585), -INT32_C(  1269033629), -INT32_C(  1729991842), -INT32_C(   968573711),  INT32_C(  1106187304),  INT32_C(   639331745), -INT32_C(  1327399946),  INT32_C(   730397699) },
      UINT8_C( 73),
      {  INT32_C(  1957549407), -INT32_C(  1647156942), -INT32_C(     7443901), -INT32_C(  1037609554), -INT32_C(  1318885052), -INT32_C(     5731708),  INT32_C(  1745049707),  INT32_C(  1085353696) },
      {  INT32_C(   901012995),  INT32_C(    47351743), -INT32_C(  1610456591), -INT32_C(    94230090),  INT32_C(   397198994), -INT32_C(  1156164528), -INT32_C(  1927079508),  INT32_C(  1271780679) },
       INT32_C(          51),
      { -INT32_C(  1957549408), -INT32_C(  1269033629), -INT32_C(  1729991842),  INT32_C(  1037609553),  INT32_C(  1106187304),  INT32_C(   639331745), -INT32_C(  1745049708),  INT32_C(   730397699) } },
    { { -INT32_C(    84585720),  INT32_C(  1788540852), -INT32_C(  1285227487),  INT32_C(   315232450),  INT32_C(   298770788),  INT32_C(  1117712890), -INT32_C(    91395130), -INT32_C(   169013780) },
      UINT8_C( 96),
      { -INT32_C(   636162078), -INT32_C(  2047115639), -INT32_C(   213340445),  INT32_C(  1515739769),  INT32_C(   441739560),  INT32_C(  1927321095),  INT32_C(   828299811), -INT32_C(  1433316409) },
      { -INT32_C(   880499134),  INT32_C(   122781476), -INT32_C(  1493460691),  INT32_C(   469783539), -INT32_C(  1019849284),  INT32_C(   255137515), -INT32_C(  1203727375),  INT32_C(   694342119) },
       INT32_C(         119),
      { -INT32_C(    84585720),  INT32_C(  1788540852), -INT32_C(  1285227487),  INT32_C(   315232450),  INT32_C(   298770788), -INT32_C(    35657220), -INT32_C(   809538082), -INT32_C(   169013780) } },
    { { -INT32_C(  1818016155), -INT32_C(   767975713), -INT32_C(  1376896271),  INT32_C(  2054169743),  INT32_C(   747218235),  INT32_C(   551864633),  INT32_C(   306792347), -INT32_C(  1817297363) },
      UINT8_C(132),
      { -INT32_C(   261937582), -INT32_C(  1713228193),  INT32_C(  1227394852), -INT32_C(  1518034176), -INT32_C(   153178068), -INT32_C(   611189100), -INT32_C(  2046188728), -INT32_C(  1542742958) },
      {  INT32_C(   563375810), -INT32_C(   910461276),  INT32_C(   101901062), -INT32_C(  1280600442), -INT32_C(   626423226), -INT32_C(   793363832),  INT32_C(   794279901),  INT32_C(   500392539) },
       INT32_C(         208),
      { -INT32_C(  1818016155), -INT32_C(   767975713), -INT32_C(  1444144399),  INT32_C(  2054169743),  INT32_C(   747218235),  INT32_C(   551864633),  INT32_C(   306792347), -INT32_C(  2110907356) } },
    { { -INT32_C(   465634850),  INT32_C(  1676300509),  INT32_C(   739677926), -INT32_C(  1475952864), -INT32_C(   679887623), -INT32_C(   704196485),  INT32_C(    49535538),  INT32_C(   544682562) },
      UINT8_C( 43),
      {  INT32_C(    84411829), -INT32_C(  2048168721),  INT32_C(  1118115714), -INT32_C(   633647586), -INT32_C(  1755966777), -INT32_C(   204919783),  INT32_C(  1379257120), -INT32_C(   126003901) },
      {  INT32_C(  1258194522),  INT32_C(  1959782898),  INT32_C(   532051201), -INT32_C(  1963330877),  INT32_C(   488722180), -INT32_C(  1676612996), -INT32_C(   118602315), -INT32_C(   168727653) },
       INT32_C(         241),
      { -INT32_C(   197133858),  INT32_C(  1811567325),  INT32_C(   739677926), -INT32_C(  1392066784), -INT32_C(   679887623), -INT32_C(   702098949),  INT32_C(    49535538),  INT32_C(   544682562) } },
    { { -INT32_C(   648540200),  INT32_C(  1207438980),  INT32_C(    97645056), -INT32_C(  1121783231), -INT32_C(  1856424996),  INT32_C(   327829368), -INT32_C(  1542882381),  INT32_C(  1116227690) },
      UINT8_C( 87),
      { -INT32_C(   287630112),  INT32_C(   116335124), -INT32_C(   448203533),  INT32_C(  1237386518), -INT32_C(  1497214113),  INT32_C(  1482282461),  INT32_C(   667090654),  INT32_C(  1719534726) },
      {  INT32_C(   894720544),  INT32_C(  1882932092),  INT32_C(  1314226999), -INT32_C(   392751223),  INT32_C(  1200511338),  INT32_C(   228583471),  INT32_C(  1815372262), -INT32_C(  2033011867) },
       INT32_C(          13),
      {  INT32_C(   648261671), -INT32_C(  2012762093), -INT32_C(   265679621), -INT32_C(  1121783231),  INT32_C(   782418947),  INT32_C(   327829368),  INT32_C(   331514956),  INT32_C(  1116227690) } },
    { { -INT32_C(  1577453974),  INT32_C(    66015098), -INT32_C(   789870746),  INT32_C(   253196768),  INT32_C(  1193129569),  INT32_C(  2092126487),  INT32_C(   285377796),  INT32_C(   379305388) },
      UINT8_C(180),
      { -INT32_C(   483477612),  INT32_C(   776548775), -INT32_C(  1794238180), -INT32_C(   420012496), -INT32_C(  1929560517),  INT32_C(  2006022898),  INT32_C(   975413884), -INT32_C(   756139715) },
      { -INT32_C(  1732961039),  INT32_C(  1774649165),  INT32_C(  1241437208),  INT32_C(   758117874),  INT32_C(   649735476),  INT32_C(   597511079),  INT32_C(   727564781), -INT32_C(   335721478) },
       INT32_C(         103),
      { -INT32_C(  1577453974),  INT32_C(    66015098), -INT32_C(    17764987),  INT32_C(   253196768), -INT32_C(  1169730673), -INT32_C(   733170339),  INT32_C(   285377796),  INT32_C(   957575879) } },
    { { -INT32_C(   904050255),  INT32_C(   269687838),  INT32_C(  1161708049),  INT32_C(   376174703),  INT32_C(   809109827), -INT32_C(  1000630326),  INT32_C(  1253071075), -INT32_C(  1124125941) },
      UINT8_C(125),
      {  INT32_C(   949716508), -INT32_C(   599086183), -INT32_C(   515141655),  INT32_C(    69493499),  INT32_C(   869160348),  INT32_C(   152474288),  INT32_C(  1981047106),  INT32_C(  2096353376) },
      { -INT32_C(   256537001),  INT32_C(   600637241), -INT32_C(  1996220274),  INT32_C(   378349946),  INT32_C(   776559486),  INT32_C(   808935662),  INT32_C(   564546497),  INT32_C(  1939708188) },
       INT32_C(          39),
      { -INT32_C(   983156661),  INT32_C(   269687838),  INT32_C(   986035558), -INT32_C(    73855104), -INT32_C(   846876958),  INT32_C(  1000433759), -INT32_C(  1779716451), -INT32_C(  1124125941) } },
  };

  simde__m256i src, a, b, r;

  src = simde_x_mm256_loadu_epi32(test_vec[0].src);
  a = simde_x_mm256_loadu_epi32(test_vec[0].a);
  b = simde_x_mm256_loadu_epi32(test_vec[0].b);
  r = simde_mm256_mask_ternarylogic_epi32(src, test_vec[0].k, a, b, INT32_C(         186));
  simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[0].r));

  src = simde_x_mm256_loadu_epi32(test_vec[1].src);
  a = simde_x_mm256_loadu_epi32(test_vec[1].a);
  b = simde_x_mm256_loadu_epi32(test_vec[1].b);
  r = simde_mm256_mask_ternarylogic_epi32(src, test_vec[1].k, a, b, INT32_C(          51));
  simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[1].r));

  src = simde_x_mm256_loadu_epi32(test_vec[2].src);
  a = simde_x_mm256_loadu_epi32(test_vec[2].a);
  b = simde_x_mm256_loadu_epi32(test_vec[2].b);
  r = simde_mm256_mask_ternarylogic_epi32(src, test_vec[2].k, a, b, INT32_C(         119));
  simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[2].r));

  src = simde_x_mm256_loadu_epi32(test_vec[3].src);
  a = simde_x_mm256_loadu_epi32(test_vec[3].a);
  b = simde_x_mm256_loadu_epi32(test_vec[3].b);
  r = simde_mm256_mask_ternarylogic_epi32(src, test_vec[3].k, a, b, INT32_C(         208));
  simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[3].r));

  src = simde_x_mm256_loadu_epi32(test_vec[4].src);
  a = simde_x_mm256_loadu_epi32(test_vec[4].a);
  b = simde_x_mm256_loadu_epi32(test_vec[4].b);
  r = simde_mm256_mask_ternarylogic_epi32(src, test_vec[4].k, a, b, INT32_C(         241));
  simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[4].r));

  src = simde_x_mm256_loadu_epi32(test_vec[5].src);
  a = simde_x_mm256_loadu_epi32(test_vec[5].a);
  b = simde_x_mm256_loadu_epi32(test_vec[5].b);
  r = simde_mm256_mask_ternarylogic_epi32(src, test_vec[5].k, a, b, INT32_C(          13));
  simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[5].r));

  src = simde_x_mm256_loadu_epi32(test_vec[6].src);
  a = simde_x_mm256_loadu_epi32(test_vec[6].a);
  b = simde_x_mm256_loadu_epi32(test_vec[6].b);
  r = simde_mm256_mask_ternarylogic_epi32(src, test_vec[6].k, a, b, INT32_C(         103));
  simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[6].r));

  src = simde_x_mm256_loadu_epi32(test_vec[7].src);
  a = simde_x_mm256_loadu_epi32(test_vec[7].a);
  b = simde_x_mm256_loadu_epi32(test_vec[7].b);
  r = simde_mm256_mask_ternarylogic_epi32(src, test_vec[7].k, a, b, INT32_C(          39));
  simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[7].r));

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256i src = simde_test_x86_random_i32x8();
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256i a = simde_test_x86_random_i32x8();
    simde__m256i b = simde_test_x86_random_i32x8();
    int imm8 = simde_test_codegen_random_i32() & 255;
    simde__m256i r;
    SIMDE_CONSTIFY_256_(simde_mm256_mask_ternarylogic_epi32, r, simde_mm256_setzero_si256(), imm8, src, k, a, b);

    simde_test_x86_write_i32x8(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_maskz_ternarylogic_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const int32_t a[8];
    const int32_t b[8];
    const int32_t c[8];
    const int imm8;
    const int32_t r[8];
  } test_vec[] = {
    { UINT8_C( 81),
      {  INT32_C(  1222673456), -INT32_C(  1312659064),  INT32_C(  1378867447), -INT32_C(  2126488031), -INT32_C(   515739243), -INT32_C(  1308794089),  INT32_C(  1406693377),  INT32_C(    61159891) },
      {  INT32_C(  1179354557), -INT32_C(   436793874),  INT32_C(   121120741),  INT32_C(   445151365),  INT32_C(    33278953),  INT32_C(   800258094),  INT32_C(  1015253608), -INT32_C(  2126567228) },
      { -INT32_C(  1681421395),  INT32_C(  2122432408),  INT32_C(  1803925990),  INT32_C(   461704497),  INT32_C(   119308760), -INT32_C(   499724679),  INT32_C(   471775576), -INT32_C(  1902223903) },
       INT32_C(         232),
      {  INT32_C(  1254327741),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(    22725081),  INT32_C(           0),  INT32_C(   479901768),  INT32_C(           0) } },
    { UINT8_C( 36),
      {  INT32_C(  1678442411), -INT32_C(  1852476028),  INT32_C(  2087366907), -INT32_C(  1695190580),  INT32_C(  1643370407),  INT32_C(  1396838389),  INT32_C(   322687405), -INT32_C(  1506296581) },
      {  INT32_C(  1057637051), -INT32_C(  1294884937),  INT32_C(   472791888),  INT32_C(  1404511404), -INT32_C(   239817989),  INT32_C(  1732573113), -INT32_C(  1015382072), -INT32_C(   144068292) },
      { -INT32_C(  1422429197),  INT32_C(  1650264082), -INT32_C(   276853693), -INT32_C(  1421723984), -INT32_C(  1717766176), -INT32_C(  1241456402), -INT32_C(  1669760416),  INT32_C(   529785388) },
       INT32_C(          85),
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(   276853692),  INT32_C(           0),  INT32_C(           0),  INT32_C(  1241456401),  INT32_C(           0),  INT32_C(           0) } },
    { UINT8_C(210),
      { -INT32_C(  1273640408),  INT32_C(  2137261129),  INT32_C(  1046417223), -INT32_C(  1943209812),  INT32_C(  1944904441),  INT32_C(  1033865307), -INT32_C(   426590436), -INT32_C(  1313212023) },
      {  INT32_C(   207998659),  INT32_C(   445368787), -INT32_C(  2057770279), -INT32_C(   602831645), -INT32_C(  1051722138), -INT32_C(  1560350842),  INT32_C(   931762350),  INT32_C(  1307132553) },
      { -INT32_C(   480686576), -INT32_C(   235018984), -INT32_C(  1300867633),  INT32_C(  1066305497),  INT32_C(   201383557),  INT32_C(  2075066061),  INT32_C(   414332814), -INT32_C(  1973052551) },
       INT32_C(         234),
      {  INT32_C(           0), -INT32_C(    67246759),  INT32_C(           0),  INT32_C(           0),  INT32_C(  1296891621),  INT32_C(           0),  INT32_C(  1051899790), -INT32_C(  1947345927) } },
    { UINT8_C(163),
      { -INT32_C(  1066142869), -INT32_C(   258333335), -INT32_C(  1837704780), -INT32_C(   664829222),  INT32_C(  1751636528),  INT32_C(   685866892), -INT32_C(  1575851036),  INT32_C(  1145443545) },
      {  INT32_C(  1879357703), -INT32_C(  1839161634),  INT32_C(  1378145912), -INT32_C(  1993702568), -INT32_C(   353267363), -INT32_C(   200093168),  INT32_C(   395781182),  INT32_C(  1062985016) },
      {  INT32_C(  1957650326),  INT32_C(  1980174334),  INT32_C(  1053305830),  INT32_C(   214430383), -INT32_C(  1795770236), -INT32_C(   913766261),  INT32_C(  1692409900), -INT32_C(  1818018819) },
       INT32_C(         154),
      { -INT32_C(   186900994),  INT32_C(   379399903),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(  1050139385),  INT32_C(           0), -INT32_C(   744015044) } },
    { UINT8_C( 98),
      {  INT32_C(   977800718), -INT32_C(   907442474),  INT32_C(   105772366), -INT32_C(   191766036), -INT32_C(  1977525654),  INT32_C(  1971815738),  INT32_C(  2064652841),  INT32_C(   819832866) },
      { -INT32_C(  1922423369), -INT32_C(    95005780),  INT32_C(   889234249), -INT32_C(   282488187),  INT32_C(   662325996), -INT32_C(   107216432),  INT32_C(  1047833628),  INT32_C(   208556629) },
      {  INT32_C(   597285239),  INT32_C(  1964896300),  INT32_C(   413802131), -INT32_C(  1677142864), -INT32_C(   289177058), -INT32_C(  1612226429),  INT32_C(  1641896972),  INT32_C(   627920046) },
       INT32_C(          37),
      {  INT32_C(           0),  INT32_C(    51087617),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(    68885062), -INT32_C(   987581998),  INT32_C(           0) } },
    { UINT8_C(247),
      { -INT32_C(  2071279770),  INT32_C(  1161077617),  INT32_C(   761581995), -INT32_C(   189771116), -INT32_C(  1778298822),  INT32_C(  2034524717), -INT32_C(   677484080),  INT32_C(   432992434) },
      {  INT32_C(   681400503), -INT32_C(  1502686469),  INT32_C(   936628899),  INT32_C(  1579975716),  INT32_C(    32779732),  INT32_C(  1601910927),  INT32_C(  1412831650), -INT32_C(  1066597367) },
      {  INT32_C(  1491667805), -INT32_C(  2130749475),  INT32_C(  1303892521),  INT32_C(   715973462), -INT32_C(  1607688176),  INT32_C(  2080352217), -INT32_C(   892389696), -INT32_C(  1752548038) },
       INT32_C(          72),
      {  INT32_C(   134301747), -INT32_C(  2075471704),  INT32_C(   550699650),  INT32_C(           0),  INT32_C(     2367488),  INT32_C(    37421188),  INT32_C(   336599296), -INT32_C(  2143026168) } },
    { UINT8_C(202),
      { -INT32_C(  1040996881),  INT32_C(  1075331420), -INT32_C(  1924119827),  INT32_C(   359067758),  INT32_C(   651616752), -INT32_C(   295657295), -INT32_C(  1640564694), -INT32_C(   681026584) },
      {  INT32_C(  1553488896), -INT32_C(  1969442659),  INT32_C(  1628958195), -INT32_C(   847806755),  INT32_C(   284380511),  INT32_C(   402543853),  INT32_C(   884290636), -INT32_C(  1895096689) },
      {  INT32_C(   401384314),  INT32_C(  1201768532),  INT32_C(  1403566197), -INT32_C(  1776279754),  INT32_C(  1504056428), -INT32_C(  1267620504),  INT32_C(  1776821977), -INT32_C(  1090981052) },
       INT32_C(         150),
      {  INT32_C(           0), -INT32_C(  1926923883),  INT32_C(           0),  INT32_C(  1311871365),  INT32_C(           0),  INT32_C(           0), -INT32_C(  1016337729), -INT32_C(   426002909) } },
    { UINT8_C(109),
      {  INT32_C(   803352950), -INT32_C(   110807590),  INT32_C(  1785133910),  INT32_C(  1204993954),  INT32_C(  1461749296),  INT32_C(  1637583214),  INT32_C(  1727486594), -INT32_C(  1496063441) },
      { -INT32_C(   304761325),  INT32_C(  1105672939), -INT32_C(   659862218),  INT32_C(  1025473804),  INT32_C(  1905540867),  INT32_C(  1272065993), -INT32_C(  1179530615), -INT32_C(  1084258900) },
      {  INT32_C(   648885307), -INT32_C(  1536650130), -INT32_C(   310635551), -INT32_C(  1809146991), -INT32_C(  1543061797),  INT32_C(  2012207342),  INT32_C(  1311809698),  INT32_C(  1611566885) },
       INT32_C(         195),
      {  INT32_C(  1036548250),  INT32_C(           0),  INT32_C(  1295141279), -INT32_C(  2060305071),  INT32_C(           0), -INT32_C(   709469864),  INT32_C(   549023732),  INT32_C(           0) } },
  };

  simde__m256i a, b, c, r;

  a = simde_x_mm256_loadu_epi32(test_vec[0].a);
  b = simde_x_mm256_loadu_epi32(test_vec[0].b);
  c = simde_x_mm256_loadu_epi32(test_vec[0].c);
  r = simde_mm256_maskz_ternarylogic_epi32(test_vec[0].k, a, b, c, INT32_C(         232));
  simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[0].r));

  a = simde_x_mm256_loadu_epi32(test_vec[1].a);
  b = simde_x_mm256_loadu_epi32(test_vec[1].b);
  c = simde_x_mm256_loadu_epi32(test_vec[1].c);
  r = simde_mm256_maskz_ternarylogic_epi32(test_vec[1].k, a, b, c, INT32_C(          85));
  simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[1].r));

  a = simde_x_mm256_loadu_epi32(test_vec[2].a);
  b = simde_x_mm256_loadu_epi32(test_vec[2].b);
  c = simde_x_mm256_loadu_epi32(test_vec[2].c);
  r = simde_mm256_maskz_ternarylogic_epi32(test_vec[2].k, a, b, c, INT32_C(         234));
  simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[2].r));

  a = simde_x_mm256_loadu_epi32(test_vec[3].a);
  b = simde_x_mm256_loadu_epi32(test_vec[3].b);
  c = simde_x_mm256_loadu_epi32(test_vec[3].c);
  r = simde_mm256_maskz_ternarylogic_epi32(test_vec[3].k, a, b, c, INT32_C(         154));
  simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[3].r));

  a = simde_x_mm256_loadu_epi32(test_vec[4].a);
  b = simde_x_mm256_loadu_epi32(test_vec[4].b);
  c = simde_x_mm256_loadu_epi32(test_vec[4].c);
  r = simde_mm256_maskz_ternarylogic_epi32(test_vec[4].k, a, b, c, INT32_C(          37));
  simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[4].r));

  a = simde_x_mm256_loadu_epi32(test_vec[5].a);
  b = simde_x_mm256_loadu_epi32(test_vec[5].b);
  c = simde_x_mm256_loadu_epi32(test_vec[5].c);
  r = simde_mm256_maskz_ternarylogic_epi32(test_vec[5].k, a, b, c, INT32_C(          72));
  simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[5].r));

  a = simde_x_mm256_loadu_epi32(test_vec[6].a);
  b = simde_x_mm256_loadu_epi32(test_vec[6].b);
  c = simde_x_mm256_loadu_epi32(test_vec[6].c);
  r = simde_mm256_maskz_ternarylogic_epi32(test_vec[6].k, a, b, c, INT32_C(         150));
  simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[6].r));

  a = simde_x_mm256_loadu_epi32(test_vec[7].a);
  b = simde_x_mm256_loadu_epi32(test_vec[7].b);
  c = simde_x_mm256_loadu_epi32(test_vec[7].c);
  r = simde_mm256_maskz_ternarylogic_epi32(test_vec[7].k, a, b, c, INT32_C(         195));
  simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[7].r));

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256i a = simde_test_x86_random_i32x8();
    simde__m256i b = simde_test_x86_random_i32x8();
    simde__m256i c = simde_test_x86_random_i32x8();
    int imm8 = simde_test_codegen_random_i32() & 255;
    simde__m256i r;
    SIMDE_CONSTIFY_256_(simde_mm256_maskz_ternarylogic_epi32, r, simde_mm256_setzero_si256(), imm8, k, a, b, c);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x8(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_ternarylogic_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t a[16];
    const int32_t b[16];
    const int32_t c[16];
    const int imm8;
    const int32_t r[16];
  } test_vec[] = {
    { {  INT32_C(  2034695690), -INT32_C(   116811682),  INT32_C(   179095093),  INT32_C(   524545334), -INT32_C(    77934622), -INT32_C(  1153832616),  INT32_C(   202552038), -INT32_C(  1233945428),
        -INT32_C(   651118213), -INT32_C(  2016265902),  INT32_C(   898727679),  INT32_C(  1314182508), -INT32_C(    62214492),  INT32_C(  2125955992), -INT32_C(   510997963), -INT32_C(  1047003834) },
      {  INT32_C(   161138615),  INT32_C(     9464833),  INT32_C(  1463165419), -INT32_C(  1683649802), -INT32_C(   778571975), -INT32_C(  1487974542),  INT32_C(  1602804249), -INT32_C(  1910431529),
        -INT32_C(   392709145),  INT32_C(   334047016),  INT32_C(  1063919433), -INT32_C(   489025623),  INT32_C(  1907585791), -INT32_C(   635894847), -INT32_C(  1271291427), -INT32_C(  1455203647) },
      {  INT32_C(  1049745942),  INT32_C(  1263630850),  INT32_C(  1133165465), -INT32_C(   920295990), -INT32_C(  1740908073), -INT32_C(  1183689508), -INT32_C(  1217549323),  INT32_C(   476098566),
        -INT32_C(  1923419765),  INT32_C(    98085740),  INT32_C(   810050150), -INT32_C(  1627754809),  INT32_C(   590755143),  INT32_C(  2128390281),  INT32_C(  1513441620), -INT32_C(  2055825926) },
       INT32_C(         135),
      { -INT32_C(  1909865501),  INT32_C(   115740577), -INT32_C(  1236199357),  INT32_C(  1771639307), -INT32_C(  1799948020), -INT32_C(   444312841), -INT32_C(   454703352),  INT32_C(  1168941909),
        -INT32_C(  1361185017),  INT32_C(  2045109637), -INT32_C(    98139328),  INT32_C(   863052818),  INT32_C(   579297564), -INT32_C(   615482138),  INT32_C(   239350942), -INT32_C(  1087761799) } },
    { { -INT32_C(   503780741),  INT32_C(   336675148), -INT32_C(   156103761), -INT32_C(   921048768), -INT32_C(   448203375),  INT32_C(   943684926), -INT32_C(  1698843373),  INT32_C(     9293701),
         INT32_C(   115443129),  INT32_C(  1964700614),  INT32_C(  1064029438),  INT32_C(  1191740597), -INT32_C(  1205055367), -INT32_C(   504337202), -INT32_C(  1485066719),  INT32_C(   933693565) },
      {  INT32_C(  1413319053),  INT32_C(  2060015484), -INT32_C(   642173661),  INT32_C(   857785017), -INT32_C(   521450478), -INT32_C(   624829512),  INT32_C(   125910153), -INT32_C(   767678396),
         INT32_C(   757496753), -INT32_C(   173477934), -INT32_C(   556900060),  INT32_C(   907144739), -INT32_C(   216597445),  INT32_C(  1640880343),  INT32_C(  1500007956),  INT32_C(   673949303) },
      { -INT32_C(   212446943),  INT32_C(  1709768256), -INT32_C(  2092714145), -INT32_C(   524725083),  INT32_C(   668258128), -INT32_C(  1131896409),  INT32_C(  1729491184), -INT32_C(  1215348586),
        -INT32_C(   777329263),  INT32_C(  1127650275), -INT32_C(   272205494),  INT32_C(   500203469), -INT32_C(   163208114),  INT32_C(   900910405),  INT32_C(  1419560894), -INT32_C(  1744032761) },
       INT32_C(          17),
      {  INT32_C(   142616146), -INT32_C(  2146041725),  INT32_C(   604260480),  INT32_C(   205924674),  INT32_C(   402665645),  INT32_C(    20317248), -INT32_C(  1737882874),  INT32_C(   138450729),
         INT32_C(    38862926),  INT32_C(   138477580),  INT32_C(     3245713), -INT32_C(  1070727152),  INT32_C(   145228672), -INT32_C(  1979702744), -INT32_C(  1576849343),  INT32_C(  1204834696) } },
    { { -INT32_C(  1825005495), -INT32_C(   410780135), -INT32_C(   888908931),  INT32_C(  1019300343), -INT32_C(   713919721),  INT32_C(  1093209658),  INT32_C(  1289303354),  INT32_C(   893469676),
        -INT32_C(    53904925), -INT32_C(   186430345), -INT32_C(  1765807969),  INT32_C(  1221755185),  INT32_C(   790447348), -INT32_C(  1922021549),  INT32_C(  1759070844),  INT32_C(  1889409677) },
      {  INT32_C(   174876563),  INT32_C(  1392398515),  INT32_C(  1776860728),  INT32_C(   867351103),  INT32_C(  1382207487), -INT32_C(  1814047978), -INT32_C(  1426343651),  INT32_C(  1729796563),
        -INT32_C(  1284405760),  INT32_C(   235237590),  INT32_C(  1836641582), -INT32_C(  1482675544),  INT32_C(   284754937), -INT32_C(   207365930),  INT32_C(  1704828561),  INT32_C(   952940344) },
      {  INT32_C(   351026493), -INT32_C(   618466899), -INT32_C(  2025284897), -INT32_C(  1104221756), -INT32_C(  1026676756), -INT32_C(  1850379777),  INT32_C(  1207325199),  INT32_C(  1182843401),
        -INT32_C(  1386582785),  INT32_C(  1015577949), -INT32_C(   591146729), -INT32_C(  1499795014),  INT32_C(   409495576), -INT32_C(   391569959),  INT32_C(  2016452463),  INT32_C(  1623109729) },
       INT32_C(          28),
      { -INT32_C(  1990932526),  INT32_C(   880610978),  INT32_C(   552398080),  INT32_C(    57913864),  INT32_C(   118529256), -INT32_C(   757670652), -INT32_C(  1574794203),  INT32_C(  1381734455),
         INT32_C(  1135646464), -INT32_C(   899272544),  INT32_C(  1799620000), -INT32_C(   278910327),  INT32_C(   937690893),  INT32_C(  1993579140),  INT32_C(    88396929),  INT32_C(   138456500) } },
    { { -INT32_C(  1380542826),  INT32_C(   562657639), -INT32_C(  2084101269),  INT32_C(  1687891851), -INT32_C(  1152564148),  INT32_C(  1144225251),  INT32_C(  1235611949), -INT32_C(  1597853174),
        -INT32_C(  1353811896),  INT32_C(  1573967858), -INT32_C(  2032101381),  INT32_C(   317422790), -INT32_C(  1530054464), -INT32_C(   488111947), -INT32_C(    64254478), -INT32_C(  2002916032) },
      {  INT32_C(  1480125286), -INT32_C(  1112209214),  INT32_C(  1715770784), -INT32_C(   763810031),  INT32_C(   477513319),  INT32_C(   972971591),  INT32_C(   741681644),  INT32_C(  2092225046),
        -INT32_C(  2133529411), -INT32_C(  1791129099),  INT32_C(   821788959),  INT32_C(   386036912),  INT32_C(    36927675), -INT32_C(  1019530793),  INT32_C(  1911517274),  INT32_C(    15573827) },
      { -INT32_C(  2055159152),  INT32_C(  1780137547), -INT32_C(   258271937),  INT32_C(  1158126986), -INT32_C(   314098922), -INT32_C(   944733588),  INT32_C(   892903410), -INT32_C(   768203454),
         INT32_C(   861386471), -INT32_C(  1264750220),  INT32_C(   295975047), -INT32_C(   329864234),  INT32_C(  1406770662),  INT32_C(   286951711),  INT32_C(  1783058984),  INT32_C(  1597865335) },
       INT32_C(          51),
      { -INT32_C(  1480125287),  INT32_C(  1112209213), -INT32_C(  1715770785),  INT32_C(   763810030), -INT32_C(   477513320), -INT32_C(   972971592), -INT32_C(   741681645), -INT32_C(  2092225047),
         INT32_C(  2133529410),  INT32_C(  1791129098), -INT32_C(   821788960), -INT32_C(   386036913), -INT32_C(    36927676),  INT32_C(  1019530792), -INT32_C(  1911517275), -INT32_C(    15573828) } },
    { { -INT32_C(  1923338490),  INT32_C(  1050542184), -INT32_C(  1842678613), -INT32_C(  1327168623), -INT32_C(  1262354548), -INT32_C(   937555887), -INT32_C(  1188603003), -INT32_C(   161367568),
         INT32_C(  1367588329),  INT32_C(  1754210749), -INT32_C(  1493518059),  INT32_C(  1213652924),  INT32_C(   805050334), -INT32_C(  1510467040),  INT32_C(  1717444470), -INT32_C(  1034108967) },
      {  INT32_C(   957603708),  INT32_C(   362979840),  INT32_C(   398171227),  INT32_C(  1516179836),  INT32_C(  1217026856), -INT32_C(   336690571),  INT32_C(  2052148385), -INT32_C(  2009289460),
        -INT32_C(  1933422708),  INT32_C(  1285645553),  INT32_C(  2086886400), -INT32_C(  1764244883), -INT32_C(  1814142691), -INT32_C(  2072064797),  INT32_C(   637521945),  INT32_C(   179125117) },
      {  INT32_C(  2090233739), -INT32_C(   725010221),  INT32_C(    38808724),  INT32_C(   211298287),  INT32_C(  1805612680),  INT32_C(  1559240259),  INT32_C(  1803677678), -INT32_C(  1250611670),
         INT32_C(  1899105438), -INT32_C(   666502332),  INT32_C(   383424039),  INT32_C(  1176728253),  INT32_C(   749847273), -INT32_C(   829906464), -INT32_C(  1153824368), -INT32_C(   714035401) },
       INT32_C(         187),
      { -INT32_C(    16879733), -INT32_C(    19038721), -INT32_C(   363565132), -INT32_C(  1380388881), -INT32_C(        2337),  INT32_C(  1559330763), -INT32_C(   273678338), -INT32_C(   134775045),
         INT32_C(  1933556991), -INT32_C(    77595826), -INT32_C(  1747011585),  INT32_C(  1865121727),  INT32_C(  1823596267), -INT32_C(     7752708), -INT32_C(    80072714), -INT32_C(   177016905) } },
    { { -INT32_C(   975663971), -INT32_C(   522472926),  INT32_C(   237436453), -INT32_C(  1589979199),  INT32_C(   158384761),  INT32_C(    46443211),  INT32_C(   366490969),  INT32_C(  1964253143),
        -INT32_C(   834999125), -INT32_C(   995224161), -INT32_C(   707603436),  INT32_C(   611716267), -INT32_C(  1724979506), -INT32_C(   358878576), -INT32_C(       36057),  INT32_C(  1047794578) },
      { -INT32_C(  1626558976), -INT32_C(   681329981),  INT32_C(   967587214),  INT32_C(   257827649), -INT32_C(  1700230135), -INT32_C(  1501281410),  INT32_C(  1235583927), -INT32_C(  1769530986),
        -INT32_C(  1976200249), -INT32_C(   614295475),  INT32_C(   236261069),  INT32_C(   991785777),  INT32_C(  2111161855), -INT32_C(  1071425271),  INT32_C(  1913243868), -INT32_C(  1475767839) },
      {  INT32_C(  1915960868), -INT32_C(  1538419241), -INT32_C(   709664093), -INT32_C(   737095467), -INT32_C(  1621957226),  INT32_C(   442463550),  INT32_C(   529295422),  INT32_C(   516462073),
        -INT32_C(  1416561708),  INT32_C(   860872080),  INT32_C(   352846400),  INT32_C(  1776949459),  INT32_C(   990395645), -INT32_C(   279615567), -INT32_C(   921705777),  INT32_C(  1273485175) },
       INT32_C(         210),
      { -INT32_C(  1511285575), -INT32_C(  1059604682), -INT32_C(   902448124),  INT32_C(  1899628373),  INT32_C(   203596783),  INT32_C(   446668491),  INT32_C(    63987025),  INT32_C(  2103221182),
        -INT32_C(   272988997), -INT32_C(   459059185), -INT32_C(   992291820),  INT32_C(  1687422057), -INT32_C(  1691951410), -INT32_C(   976235488),  INT32_C(  1996050724),  INT32_C(  2106742148) } },
    { { -INT32_C(  1802156460),  INT32_C(   464166472), -INT32_C(  1266379594), -INT32_C(  2115007280), -INT32_C(  1015986701), -INT32_C(  1634959321),  INT32_C(   703230807),  INT32_C(  1049354474),
         INT32_C(  1876107302),  INT32_C(  1972010430), -INT32_C(   517402863), -INT32_C(  1889396581), -INT32_C(  2074946723), -INT32_C(  1440489901),  INT32_C(  1003687249),  INT32_C(   343498477) },
      {  INT32_C(  1032014975), -INT32_C(   625865271), -INT32_C(  1195648228),  INT32_C(  1363615476),  INT32_C(  1171692017), -INT32_C(   923797129), -INT32_C(   217857274), -INT32_C(  1610122207),
        -INT32_C(  1830909239), -INT32_C(  1267887976),  INT32_C(  1617700972),  INT32_C(   951169862), -INT32_C(  1015183540), -INT32_C(  2037683072),  INT32_C(  1366986287), -INT32_C(   722370293) },
      { -INT32_C(  1536766196), -INT32_C(   866593952),  INT32_C(  1110230524), -INT32_C(   981803656), -INT32_C(   444008603), -INT32_C(  1821633436), -INT32_C(  1377507678),  INT32_C(  1937888871),
         INT32_C(    85452965), -INT32_C(  1211010885), -INT32_C(  1376060107),  INT32_C(  1081242843), -INT32_C(   802817172), -INT32_C(  1318874865), -INT32_C(   547403657), -INT32_C(  1017978850) },
       INT32_C(         200),
      {  INT32_C(   881019996), -INT32_C(   625865400), -INT32_C(  1331113700),  INT32_C(  1095179504),  INT32_C(  1171296753), -INT32_C(  1997762457), -INT32_C(  1593654522),  INT32_C(   537097249),
         INT32_C(    47614081), -INT32_C(  1270280040),  INT32_C(  1617438756),  INT32_C(   137375810), -INT32_C(  1066040500), -INT32_C(  2113713152),  INT32_C(  1364855847), -INT32_C(   730759157) } },
    { {  INT32_C(   255564506),  INT32_C(  1941714328),  INT32_C(   380841898),  INT32_C(   971429930), -INT32_C(   504739478), -INT32_C(  1346352751), -INT32_C(   227339478),  INT32_C(  1467366525),
         INT32_C(  1852224214), -INT32_C(  1847516441),  INT32_C(  2074580049), -INT32_C(   676033171),  INT32_C(  1756930007),  INT32_C(   303593960),  INT32_C(   151358348), -INT32_C(  1654621241) },
      {  INT32_C(   353158701),  INT32_C(   984018408), -INT32_C(   273330558), -INT32_C(  1295619365), -INT32_C(   249856503), -INT32_C(  2096876553), -INT32_C(  2054420034), -INT32_C(  1306334076),
        -INT32_C(  1681445198), -INT32_C(  1630180068), -INT32_C(  1752331589), -INT32_C(    45526028), -INT32_C(   907057967),  INT32_C(  1431106455), -INT32_C(  2133140996),  INT32_C(  2016607685) },
      {  INT32_C(  1192491307),  INT32_C(   585492583),  INT32_C(  1740206706), -INT32_C(  1755053115), -INT32_C(    10464409),  INT32_C(  1112845382),  INT32_C(  1271082885),  INT32_C(  1472460076),
         INT32_C(  1453315823),  INT32_C(   813204670), -INT32_C(  1130941705), -INT32_C(  1672217547), -INT32_C(  1768180913), -INT32_C(   438767520),  INT32_C(  1261476639), -INT32_C(  2136804463) },
       INT32_C(         201),
      { -INT32_C(  1513569751), -INT32_C(  1230704664),  INT32_C(  1743900295), -INT32_C(   220246325), -INT32_C(   250684775), -INT32_C(  1825627681), -INT32_C(  2122266130),  INT32_C(   439021062),
         INT32_C(   449259442), -INT32_C(   791464932), -INT32_C(  1748646989), -INT32_C(   582921866), -INT32_C(   928307983),  INT32_C(  1567356288),  INT32_C(   873512348),  INT32_C(   439351789) } },
  };

  simde__m512i a, b, c, r;

  a = simde_mm512_loadu_epi32(test_vec[0].a);
  b = simde_mm512_loadu_epi32(test_vec[0].b);
  c = simde_mm512_loadu_epi32(test_vec[0].c);
  r = simde_mm512_ternarylogic_epi32(a, b, c, INT32_C(         135));
  simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[0].r));

  a = simde_mm512_loadu_epi32(test_vec[1].a);
  b = simde_mm512_loadu_epi32(test_vec[1].b);
  c = simde_mm512_loadu_epi32(test_vec[1].c);
  r = simde_mm512_ternarylogic_epi32(a, b, c, INT32_C(          17));
  simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[1].r));

  a = simde_mm512_loadu_epi32(test_vec[2].a);
  b = simde_mm512_loadu_epi32(test_vec[2].b);
  c = simde_mm512_loadu_epi32(test_vec[2].c);
  r = simde_mm512_ternarylogic_epi32(a, b, c, INT32_C(          28));
  simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[2].r));

  a = simde_mm512_loadu_epi32(test_vec[3].a);
  b = simde_mm512_loadu_epi32(test_vec[3].b);
  c = simde_mm512_loadu_epi32(test_vec[3].c);
  r = simde_mm512_ternarylogic_epi32(a, b, c, INT32_C(          51));
  simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[3].r));

  a = simde_mm512_loadu_epi32(test_vec[4].a);
  b = simde_mm512_loadu_epi32(test_vec[4].b);
  c = simde_mm512_loadu_epi32(test_vec[4].c);
  r = simde_mm512_ternarylogic_epi32(a, b, c, INT32_C(         187));
  simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[4].r));

  a = simde_mm512_loadu_epi32(test_vec[5].a);
  b = simde_mm512_loadu_epi32(test_vec[5].b);
  c = simde_mm512_loadu_epi32(test_vec[5].c);
  r = simde_mm512_ternarylogic_epi32(a, b, c, INT32_C(         210));
  simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[5].r));

  a = simde_mm512_loadu_epi32(test_vec[6].a);
  b = simde_mm512_loadu_epi32(test_vec[6].b);
  c = simde_mm512_loadu_epi32(test_vec[6].c);
  r = simde_mm512_ternarylogic_epi32(a, b, c, INT32_C(         200));
  simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[6].r));

  a = simde_mm512_loadu_epi32(test_vec[7].a);
  b = simde_mm512_loadu_epi32(test_vec[7].b);
  c = simde_mm512_loadu_epi32(test_vec[7].c);
  r = simde_mm512_ternarylogic_epi32(a, b, c, INT32_C(         201));
  simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[7].r));

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512i a = simde_test_x86_random_i32x16();
    simde__m512i b = simde_test_x86_random_i32x16();
    simde__m512i c = simde_test_x86_random_i32x16();
    int imm8 = simde_test_codegen_random_i32() & 255;
    simde__m512i r;
    SIMDE_CONSTIFY_256_(simde_mm512_ternarylogic_epi32, r, simde_mm512_setzero_si512(), imm8, a, b, c);

    simde_test_x86_write_i32x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x16(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_mask_ternarylogic_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t src[16];
    const simde__mmask16 k;
    const int32_t a[16];
    const int32_t b[16];
    const int imm8;
    const int32_t r[16];
  } test_vec[] = {
    { { -INT32_C(  1111994682), -INT32_C(  1250340992), -INT32_C(  1689072309), -INT32_C(   533598848), -INT32_C(    54130211),  INT32_C(   910685861), -INT32_C(  1279857942), -INT32_C(   247755733),
         INT32_C(  1538192346), -INT32_C(  1911543742),  INT32_C(  1965646581),  INT32_C(   760633936),  INT32_C(   136977507), -INT32_C(    63016686), -INT32_C(  2018446245),  INT32_C(  1534651264) },
      UINT16_C(10206),
      { -INT32_C(   967892810), -INT32_C(   685161298),  INT32_C(   254900665), -INT32_C(   802450010), -INT32_C(   599638371), -INT32_C(   355427014), -INT32_C(  1646964444),  INT32_C(  1657058220),
        -INT32_C(  2111302700),  INT32_C(   274354519),  INT32_C(  1897958346), -INT32_C(  1103017184), -INT32_C(   996506743),  INT32_C(  1169058337),  INT32_C(  1742898363),  INT32_C(   197764663) },
      {  INT32_C(   277803705),  INT32_C(   237103171), -INT32_C(  1803599501),  INT32_C(   374521996),  INT32_C(  1708846148),  INT32_C(   313165910),  INT32_C(  1148816652), -INT32_C(   313572557),
         INT32_C(  2029903157),  INT32_C(   965091013), -INT32_C(   322108065),  INT32_C(   167911366),  INT32_C(  1634720779),  INT32_C(  1903368548), -INT32_C(   625611354),  INT32_C(  1707541552) },
       INT32_C(         226),
      { -INT32_C(  1111994682), -INT32_C(  1658196799), -INT32_C(  1688319669), -INT32_C(   965622392), -INT32_C(    35993379),  INT32_C(   910685861), -INT32_C(   776156120), -INT32_C(   317996997),
         INT32_C(  2063458289),  INT32_C(   697568962), -INT32_C(    34797867),  INT32_C(   760633936),  INT32_C(   136977507),  INT32_C(  1954509124), -INT32_C(  2018446245),  INT32_C(  1534651264) } },
    { {  INT32_C(  1122002147),  INT32_C(   791588201), -INT32_C(   684117812),  INT32_C(  1899603980),  INT32_C(  1759685826), -INT32_C(   918382695),  INT32_C(  2100169115), -INT32_C(  1322971954),
        -INT32_C(   638384784),  INT32_C(  2131305139),  INT32_C(  1599554130), -INT32_C(  1378840341), -INT32_C(   703221188), -INT32_C(   459319223),  INT32_C(   795004513),  INT32_C(  1256228826) },
      UINT16_C(54412),
      {  INT32_C(   754335523),  INT32_C(   376391871),  INT32_C(  2007390887),  INT32_C(   472506887),  INT32_C(  1484026552), -INT32_C(  1188637097), -INT32_C(   432013307),  INT32_C(  1840958538),
        -INT32_C(   879054836), -INT32_C(  1595864584),  INT32_C(  1779926883),  INT32_C(   579223913),  INT32_C(   175831987), -INT32_C(   691822383), -INT32_C(   356777056), -INT32_C(   598247728) },
      {  INT32_C(   531099942),  INT32_C(  1572833530),  INT32_C(  2026362383), -INT32_C(   879079913),  INT32_C(   450171977),  INT32_C(  1425054132),  INT32_C(  1816047004),  INT32_C(  1246271011),
        -INT32_C(  2106986617), -INT32_C(  2032195465),  INT32_C(   385853438),  INT32_C(  1054972405),  INT32_C(  1649981102), -INT32_C(   323532721),  INT32_C(   425260533),  INT32_C(   325296523) },
       INT32_C(         144),
      {  INT32_C(  1122002147),  INT32_C(   791588201), -INT32_C(   803721148),  INT32_C(   537395212),  INT32_C(  1759685826), -INT32_C(   918382695),  INT32_C(  2100169115), -INT32_C(  1878719354),
        -INT32_C(   638384784),  INT32_C(  2131305139),  INT32_C(    51855938), -INT32_C(  1378840341), -INT32_C(  1776963040), -INT32_C(   459319223),  INT32_C(   201459744),  INT32_C(    12583040) } },
    { { -INT32_C(   225544972),  INT32_C(   268995867), -INT32_C(   716248793), -INT32_C(   281565536), -INT32_C(   455348497),  INT32_C(  1878865124),  INT32_C(  1703043285),  INT32_C(   544020268),
        -INT32_C(  1491862388), -INT32_C(  1330111607), -INT32_C(  1518008827), -INT32_C(  1667973715), -INT32_C(  1887407957),  INT32_C(  2046787236),  INT32_C(   199131614),  INT32_C(   623594649) },
      UINT16_C(15944),
      { -INT32_C(  2074422836),  INT32_C(   126574466), -INT32_C(  1731971068),  INT32_C(  1409839316), -INT32_C(    19747585),  INT32_C(    75542821), -INT32_C(   414180932),  INT32_C(   170301502),
        -INT32_C(   342917015), -INT32_C(   470607137),  INT32_C(   645642066),  INT32_C(   662340647),  INT32_C(  1445285168), -INT32_C(  1168464386), -INT32_C(    56513858), -INT32_C(  1425553598) },
      {  INT32_C(   647468615),  INT32_C(    34179760),  INT32_C(  1764263233),  INT32_C(   965779977), -INT32_C(   309348881),  INT32_C(   430434651), -INT32_C(   719959661),  INT32_C(  1484856592),
         INT32_C(  1669208243), -INT32_C(   479885150),  INT32_C(   374115597),  INT32_C(   525327407), -INT32_C(   317923438),  INT32_C(  1543943368),  INT32_C(   221322493), -INT32_C(   328879559) },
       INT32_C(         202),
      { -INT32_C(   225544972),  INT32_C(   268995867), -INT32_C(   716248793),  INT32_C(  1417683081), -INT32_C(   455348497),  INT32_C(  1878865124), -INT32_C(   183236202),  INT32_C(   544020268),
        -INT32_C(  1491862388), -INT32_C(   470443349),  INT32_C(   910790408),  INT32_C(   123454503),  INT32_C(  1712115504),  INT32_C(  1012573420),  INT32_C(   199131614),  INT32_C(   623594649) } },
    { {  INT32_C(  2035332204),  INT32_C(  1905237057),  INT32_C(   194043513), -INT32_C(  2030527299),  INT32_C(  1306721872),  INT32_C(  1415254811), -INT32_C(  1874739002),  INT32_C(   285053092),
        -INT32_C(  2037822139),  INT32_C(  1660360937), -INT32_C(  1267890185),  INT32_C(  1949984036),  INT32_C(  2143427684), -INT32_C(   153936592), -INT32_C(  2105142051), -INT32_C(   359496795) },
      UINT16_C( 7376),
      {  INT32_C(  1748286064), -INT32_C(  1964037348),  INT32_C(   451875808),  INT32_C(  1245139848), -INT32_C(  1503172654), -INT32_C(   474332067),  INT32_C(  1499946950), -INT32_C(  1166723255),
         INT32_C(   237152753), -INT32_C(  1248325163), -INT32_C(  1378908379), -INT32_C(  1376319781), -INT32_C(   900506003),  INT32_C(  1773014690), -INT32_C(  1212017299),  INT32_C(  1047607116) },
      { -INT32_C(  1253272608), -INT32_C(   915741532),  INT32_C(  1182153323), -INT32_C(  1359712960),  INT32_C(  1853376459), -INT32_C(  1009310123), -INT32_C(  2005231301), -INT32_C(  1329140784),
         INT32_C(   577114750),  INT32_C(  1642909942),  INT32_C(  1269326346), -INT32_C(  1678140208),  INT32_C(   956920291), -INT32_C(   738402152),  INT32_C(  1230730873), -INT32_C(   537255583) },
       INT32_C(          51),
      {  INT32_C(  2035332204),  INT32_C(  1905237057),  INT32_C(   194043513), -INT32_C(  2030527299),  INT32_C(  1503172653),  INT32_C(  1415254811), -INT32_C(  1499946951),  INT32_C(  1166723254),
        -INT32_C(  2037822139),  INT32_C(  1660360937),  INT32_C(  1378908378),  INT32_C(  1376319780),  INT32_C(   900506002), -INT32_C(   153936592), -INT32_C(  2105142051), -INT32_C(   359496795) } },
    { {  INT32_C(   999025968),  INT32_C(   545665872), -INT32_C(  1296334897), -INT32_C(  1997814288),  INT32_C(   526182309), -INT32_C(  1100433571),  INT32_C(   211641049), -INT32_C(   214523966),
        -INT32_C(   600915572), -INT32_C(  1006848780),  INT32_C(   594917427),  INT32_C(   581722493), -INT32_C(  1505687480), -INT32_C(  1738233153), -INT32_C(   811269620),  INT32_C(   767744929) },
      UINT16_C(61596),
      {  INT32_C(   111448074), -INT32_C(   927017133), -INT32_C(  1507247110), -INT32_C(  1615957410),  INT32_C(  2085187096), -INT32_C(  1417783802), -INT32_C(   410640603),  INT32_C(  1473716813),
         INT32_C(    90012594),  INT32_C(  1288576082), -INT32_C(  1242302633), -INT32_C(  2125094551),  INT32_C(   385785359),  INT32_C(   432110836), -INT32_C(   385857380),  INT32_C(   490788714) },
      { -INT32_C(  1541235374),  INT32_C(   301068473),  INT32_C(  1371989224), -INT32_C(  1781326971), -INT32_C(  1364471366), -INT32_C(   372741043),  INT32_C(   533907636), -INT32_C(   230944096),
         INT32_C(  1771527856),  INT32_C(   930777167), -INT32_C(   242728596),  INT32_C(   377903964),  INT32_C(  2059743532),  INT32_C(  1382256030), -INT32_C(   177129899), -INT32_C(   118969016) },
       INT32_C(          12),
      {  INT32_C(   999025968),  INT32_C(   545665872),  INT32_C(    67108912),  INT32_C(   386150926),  INT32_C(  1610680344), -INT32_C(  1100433571),  INT32_C(   211641049),  INT32_C(    79765517),
        -INT32_C(   600915572), -INT32_C(  1006848780),  INT32_C(   594917427),  INT32_C(   581722493),  INT32_C(   280925703),  INT32_C(    25252928),  INT32_C(   536889488),  INT32_C(   268436554) } },
    { {  INT32_C(  1939004423),  INT32_C(  2053380637), -INT32_C(  1567560842), -INT32_C(  1172548324),  INT32_C(   940409058), -INT32_C(    30572874),  INT32_C(   955716908), -INT32_C(  1684842092),
         INT32_C(  1393435957), -INT32_C(  1244826817),  INT32_C(  2052611422), -INT32_C(  1791658829), -INT32_C(  1429388556), -INT32_C(   324404288), -INT32_C(  1524326384),  INT32_C(   775993337) },
      UINT16_C(20444),
      {  INT32_C(  1321344129),  INT32_C(   699146449), -INT32_C(   811704422), -INT32_C(  1039035660), -INT32_C(   423767491), -INT32_C(   477704770), -INT32_C(  1281720462),  INT32_C(   788690861),
         INT32_C(  1685963923),  INT32_C(  2123246052),  INT32_C(  2102275208), -INT32_C(    79732802), -INT32_C(   253625295),  INT32_C(  1020487625), -INT32_C(  1796248090),  INT32_C(  2009330148) },
      { -INT32_C(  1713618763), -INT32_C(   233346454),  INT32_C(  1416586646), -INT32_C(   162484539),  INT32_C(  1961243050),  INT32_C(  2142288281),  INT32_C(   185835303),  INT32_C(  1166268048),
        -INT32_C(  2116133097),  INT32_C(  1601435081),  INT32_C(   548660059),  INT32_C(  1008075665), -INT32_C(   827261643), -INT32_C(   582131530), -INT32_C(  1880530433),  INT32_C(  1322544183) },
       INT32_C(         203),
      {  INT32_C(  1939004423),  INT32_C(  2053380637), -INT32_C(   687911021), -INT32_C(   940393769),  INT32_C(  1710210344), -INT32_C(    30572874),  INT32_C(  2006097827),  INT32_C(  1332664262),
        -INT32_C(   925082021),  INT32_C(  2126423524), -INT32_C(   118772183), -INT32_C(  1174939662), -INT32_C(  1429388556), -INT32_C(   324404288), -INT32_C(   822250513),  INT32_C(   775993337) } },
    { {  INT32_C(    49496999), -INT32_C(  1222466010), -INT32_C(   537708118), -INT32_C(   324164810),  INT32_C(    46856707), -INT32_C(  1819167909), -INT32_C(   354327265), -INT32_C(  1082216169),
         INT32_C(   448885236), -INT32_C(  1043209193),  INT32_C(  1403045149),  INT32_C(  1816087912), -INT32_C(  1553069752), -INT32_C(   617217860),  INT32_C(  2110068837), -INT32_C(  1120123959) },
      UINT16_C(64948),
      { -INT32_C(  1461596969),  INT32_C(   778960525), -INT32_C(  1854155183), -INT32_C(  1332034750), -INT32_C(  1649387673), -INT32_C(   122350030), -INT32_C(   818184557),  INT32_C(   315420731),
         INT32_C(  1237036732), -INT32_C(    25745236),  INT32_C(  1083175934),  INT32_C(   502344118), -INT32_C(  1279549056),  INT32_C(  1252749495),  INT32_C(   706340591), -INT32_C(  1841436970) },
      {  INT32_C(  1088223380),  INT32_C(   524178208), -INT32_C(    44053178),  INT32_C(  1998213367), -INT32_C(  1456810510),  INT32_C(   905237830), -INT32_C(  1839264324), -INT32_C(  2027578125),
        -INT32_C(  1245183596), -INT32_C(  1680603564), -INT32_C(   879217708),  INT32_C(  1984082564), -INT32_C(   836801144), -INT32_C(    33352894),  INT32_C(   345072161), -INT32_C(  1818446081) },
       INT32_C(         183),
      {  INT32_C(    49496999), -INT32_C(  1222466010), -INT32_C(     2675777), -INT32_C(   324164810),  INT32_C(  1986001054),  INT32_C(  1608186351), -INT32_C(   354327265), -INT32_C(   273162273),
        -INT32_C(   151592993), -INT32_C(  1043209193), -INT32_C(      586441), -INT32_C(   410069413), -INT32_C(   556867713), -INT32_C(     2166967), -INT32_C(   672162373), -INT32_C(    35709975) } },
    { {  INT32_C(  1051073642), -INT32_C(   737591728),  INT32_C(  2034912497), -INT32_C(    79205959), -INT32_C(  1627764099), -INT32_C(  1414362196), -INT32_C(   130068927),  INT32_C(   486770610),
        -INT32_C(   195319132), -INT32_C(   641178136),  INT32_C(  1783763633), -INT32_C(   127559301), -INT32_C(  1869193245),  INT32_C(   725305834),  INT32_C(  1243839127), -INT32_C(  1503189246) },
      UINT16_C(49873),
      {  INT32_C(  1646770586), -INT32_C(   445327213), -INT32_C(  1468010686),  INT32_C(  2114413288),  INT32_C(   784855794),  INT32_C(  1101553437),  INT32_C(   275294889), -INT32_C(   355321520),
        -INT32_C(  2058552590),  INT32_C(   359383250), -INT32_C(  1732384080),  INT32_C(  1058456652), -INT32_C(   730997066), -INT32_C(   434825923),  INT32_C(   284589504), -INT32_C(  1459894090) },
      { -INT32_C(  1792129086), -INT32_C(  1196779256), -INT32_C(   816814205), -INT32_C(   502372821), -INT32_C(  2118747324),  INT32_C(  1365756817), -INT32_C(    27173560), -INT32_C(   391750618),
        -INT32_C(  1401039708), -INT32_C(   261871763), -INT32_C(  1161775986),  INT32_C(  1604111898), -INT32_C(   606055862),  INT32_C(  1697400861), -INT32_C(   882668123), -INT32_C(  1900803606) },
       INT32_C(         222),
      { -INT32_C(   340788294), -INT32_C(   737591728),  INT32_C(  2034912497), -INT32_C(    79205959),  INT32_C(  1070593019), -INT32_C(  1414362196),  INT32_C(   377404329), -INT32_C(      525356),
        -INT32_C(   195319132),  INT32_C(  1039123159),  INT32_C(  1783763633), -INT32_C(   127559301), -INT32_C(  1869193245),  INT32_C(   725305834), -INT32_C(  1846083598), -INT32_C(  1459884290) } },
  };

  simde__m512i src, a, b, r;

  src = simde_mm512_loadu_epi32(test_vec[0].src);
  a = simde_mm512_loadu_epi32(test_vec[0].a);
  b = simde_mm512_loadu_epi32(test_vec[0].b);
  r = simde_mm512_mask_ternarylogic_epi32(src, test_vec[0].k, a, b, INT32_C(         226));
  simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[0].r));

  src = simde_mm512_loadu_epi32(test_vec[1].src);
  a = simde_mm512_loadu_epi32(test_vec[1].a);
  b = simde_mm512_loadu_epi32(test_vec[1].b);
  r = simde_mm512_mask_ternarylogic_epi32(src, test_vec[1].k, a, b, INT32_C(         144));
  simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[1].r));

  src = simde_mm512_loadu_epi32(test_vec[2].src);
  a = simde_mm512_loadu_epi32(test_vec[2].a);
  b = simde_mm512_loadu_epi32(test_vec[2].b);
  r = simde_mm512_mask_ternarylogic_epi32(src, test_vec[2].k, a, b, INT32_C(         202));
  simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[2].r));

  src = simde_mm512_loadu_epi32(test_vec[3].src);
  a = simde_mm512_loadu_epi32(test_vec[3].a);
  b = simde_mm512_loadu_epi32(test_vec[3].b);
  r = simde_mm512_mask_ternarylogic_epi32(src, test_vec[3].k, a, b, INT32_C(          51));
  simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[3].r));

  src = simde_mm512_loadu_epi32(test_vec[4].src);
  a = simde_mm512_loadu_epi32(test_vec[4].a);
  b = simde_mm512_loadu_epi32(test_vec[4].b);
  r = simde_mm512_mask_ternarylogic_epi32(src, test_vec[4].k, a, b, INT32_C(          12));
  simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[4].r));

  src = simde_mm512_loadu_epi32(test_vec[5].src);
  a = simde_mm512_loadu_epi32(test_vec[5].a);
  b = simde_mm512_loadu_epi32(test_vec[5].b);
  r = simde_mm512_mask_ternarylogic_epi32(src, test_vec[5].k, a, b, INT32_C(         203));
  simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[5].r));

  src = simde_mm512_loadu_epi32(test_vec[6].src);
  a = simde_mm512_loadu_epi32(test_vec[6].a);
  b = simde_mm512_loadu_epi32(test_vec[6].b);
  r = simde_mm512_mask_ternarylogic_epi32(src, test_vec[6].k, a, b, INT32_C(         183));
  simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[6].r));

  src = simde_mm512_loadu_epi32(test_vec[7].src);
  a = simde_mm512_loadu_epi32(test_vec[7].a);
  b = simde_mm512_loadu_epi32(test_vec[7].b);
  r = simde_mm512_mask_ternarylogic_epi32(src, test_vec[7].k, a, b, INT32_C(         222));
  simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[7].r));

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512i src = simde_test_x86_random_i32x16();
    simde__mmask16 k = simde_test_x86_random_mmask16();
    simde__m512i a = simde_test_x86_random_i32x16();
    simde__m512i b = simde_test_x86_random_i32x16();
    int imm8 = simde_test_codegen_random_i32() & 255;
    simde__m512i r;
    SIMDE_CONSTIFY_256_(simde_mm512_mask_ternarylogic_epi32, r, simde_mm512_setzero_si512(), imm8, src, k, a, b);

    simde_test_x86_write_i32x16(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask16(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_maskz_ternarylogic_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask16 k;
    const int32_t a[16];
    const int32_t b[16];
    const int32_t c[16];
    const int imm8;
    const int32_t r[16];
  } test_vec[] = {
    { UINT16_C(40537),
      { -INT32_C(    61675716),  INT32_C(  1036676257), -INT32_C(  1399909173),  INT32_C(   469019887),  INT32_C(  1957271825),  INT32_C(   427725669),  INT32_C(  1531599905), -INT32_C(   470178905),
         INT32_C(   752831371), -INT32_C(  2090161481), -INT32_C(  1372587586), -INT32_C(  1211554906),  INT32_C(   556561084),  INT32_C(   641378821), -INT32_C(  1384020730), -INT32_C(  1282311640) },
      {  INT32_C(  2111860933), -INT32_C(   654292454), -INT32_C(   377016509),  INT32_C(   245452882), -INT32_C(   936325693),  INT32_C(  2112842359),  INT32_C(   405434607), -INT32_C(  1328825365),
         INT32_C(  1177398060),  INT32_C(   958344693), -INT32_C(  1373460900), -INT32_C(  1161968649),  INT32_C(   126021008),  INT32_C(  1199862103), -INT32_C(   849367070), -INT32_C(  1770182038) },
      { -INT32_C(   874665002),  INT32_C(   889519320), -INT32_C(  1696389213),  INT32_C(  2069143786), -INT32_C(   444410227),  INT32_C(   707528520),  INT32_C(   553094070), -INT32_C(  1950911307),
        -INT32_C(   128478177),  INT32_C(   858610576),  INT32_C(  1842155650),  INT32_C(  1055400369),  INT32_C(  1076062968),  INT32_C(   661278577), -INT32_C(  1874304550), -INT32_C(   182714411) },
       INT32_C(         147),
      {  INT32_C(  1246702638),  INT32_C(           0),  INT32_C(           0), -INT32_C(   368439481),  INT32_C(  1397727805),  INT32_C(           0), -INT32_C(   409499856),  INT32_C(           0),
         INT32_C(           0), -INT32_C(   976693094),  INT32_C(  2110802209),  INT32_C(  1938431400), -INT32_C(   128093993),  INT32_C(           0),  INT32_C(           0), -INT32_C(   661409899) } },
    { UINT16_C( 6862),
      {  INT32_C(   606752855), -INT32_C(  1522082883),  INT32_C(  1024474650), -INT32_C(   393379458), -INT32_C(   246847575),  INT32_C(   334503671),  INT32_C(     8749843), -INT32_C(    48606298),
         INT32_C(  1629636004),  INT32_C(   973563936),  INT32_C(   611850150),  INT32_C(  1091306904),  INT32_C(  1681020268), -INT32_C(  2022235533),  INT32_C(  1283980453), -INT32_C(   196500912) },
      {  INT32_C(   123038695),  INT32_C(  2034392275),  INT32_C(   211663475),  INT32_C(   726510015),  INT32_C(  1922007294),  INT32_C(  1224279714),  INT32_C(  1402241027),  INT32_C(   155704610),
         INT32_C(   470916169),  INT32_C(  1821791225), -INT32_C(   864537843), -INT32_C(   604518691), -INT32_C(   397572282), -INT32_C(  1875884403), -INT32_C(   370948921), -INT32_C(   336385374) },
      { -INT32_C(  1073281849),  INT32_C(  1680645463), -INT32_C(  1372543535), -INT32_C(  1316411541),  INT32_C(  1016715182), -INT32_C(   456340963),  INT32_C(   818851982), -INT32_C(  1592016422),
         INT32_C(   476128197), -INT32_C(  1853845824), -INT32_C(  1639993293), -INT32_C(  2041591337), -INT32_C(  1111299936),  INT32_C(  1101172402),  INT32_C(   426864702), -INT32_C(   155546319) },
       INT32_C(         176),
      {  INT32_C(           0), -INT32_C(  1543201987),  INT32_C(  1024467992), -INT32_C(   527892118),  INT32_C(           0),  INT32_C(           0),  INT32_C(     8749842), -INT32_C(   182828154),
         INT32_C(           0),  INT32_C(   302065664),  INT32_C(           0),  INT32_C(      786832),  INT32_C(   607277096),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { UINT16_C(37546),
      {  INT32_C(  1094900994), -INT32_C(   905307781),  INT32_C(  1639099039),  INT32_C(   183526760),  INT32_C(   393883302),  INT32_C(    44346183), -INT32_C(  1289857887), -INT32_C(   951727931),
         INT32_C(   537429925),  INT32_C(  1089082272),  INT32_C(   631348413), -INT32_C(  1490054911),  INT32_C(   130001344), -INT32_C(   183934124),  INT32_C(  2108172216), -INT32_C(  1807421969) },
      {  INT32_C(   364137588),  INT32_C(   492150367),  INT32_C(  1011021371),  INT32_C(  1222931080),  INT32_C(  1884267291), -INT32_C(  1100654330),  INT32_C(  1882918528),  INT32_C(  1879343099),
         INT32_C(   730184140), -INT32_C(  1840719273),  INT32_C(  1489996752),  INT32_C(   413185021),  INT32_C(  1552478294), -INT32_C(   920916407), -INT32_C(   147237124), -INT32_C(  1570292010) },
      {  INT32_C(  1322118391), -INT32_C(  1746856250), -INT32_C(  1628458847), -INT32_C(  1179217821), -INT32_C(   921354368),  INT32_C(   697446445),  INT32_C(  1562430599),  INT32_C(    33523722),
         INT32_C(   995085428), -INT32_C(  2083376926),  INT32_C(  1126285792), -INT32_C(   771958703),  INT32_C(  1150947863), -INT32_C(   915591870),  INT32_C(    52858361), -INT32_C(  1979439851) },
       INT32_C(         242),
      {  INT32_C(           0), -INT32_C(   894821893),  INT32_C(           0), -INT32_C(  1141709461),  INT32_C(           0),  INT32_C(    62303087),  INT32_C(           0), -INT32_C(   939538235),
         INT32_C(           0),  INT32_C(  1106916256),  INT32_C(           0),  INT32_C(           0),  INT32_C(   130001857),  INT32_C(           0),  INT32_C(           0), -INT32_C(  1673204241) } },
    { UINT16_C(38788),
      {  INT32_C(  2035835992), -INT32_C(  1538151768),  INT32_C(   381053051),  INT32_C(   423885228), -INT32_C(   374915902),  INT32_C(  1125039167),  INT32_C(   194379846),  INT32_C(   765598421),
         INT32_C(   665254783),  INT32_C(   550238373),  INT32_C(   221676128),  INT32_C(  1025931643), -INT32_C(   198783563), -INT32_C(   801688182),  INT32_C(   182242869),  INT32_C(  1731690216) },
      {  INT32_C(   512679545),  INT32_C(   910121686),  INT32_C(  1464038876), -INT32_C(  1533777169), -INT32_C(  1046889673),  INT32_C(   630378736), -INT32_C(  2026869090),  INT32_C(  1726900204),
         INT32_C(   461667653), -INT32_C(  1286421545),  INT32_C(   671782201),  INT32_C(   936156927),  INT32_C(  1241015641), -INT32_C(   730887626), -INT32_C(   446980104),  INT32_C(  1280002566) },
      { -INT32_C(  1637363769), -INT32_C(   867059309),  INT32_C(  1324637007),  INT32_C(  1401274617),  INT32_C(  1553759782),  INT32_C(    19925768), -INT32_C(  1310290774), -INT32_C(  1644351018),
        -INT32_C(  1824824320),  INT32_C(  1834978334), -INT32_C(   524594201),  INT32_C(   976437524), -INT32_C(   946417473), -INT32_C(  2033662245),  INT32_C(   674737746), -INT32_C(   523946785) },
       INT32_C(         152),
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(  1178620268),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(    82586053),
         INT32_C(   922805818),  INT32_C(   567455798),  INT32_C(   621678881),  INT32_C(           0),  INT32_C(  1905281049),  INT32_C(           0),  INT32_C(           0),  INT32_C(  1131479078) } },
    { UINT16_C(54156),
      { -INT32_C(   551128285), -INT32_C(  2027931052),  INT32_C(   173530996),  INT32_C(  1875981222), -INT32_C(   266525767),  INT32_C(   287636812),  INT32_C(  1343405277), -INT32_C(  1776050573),
         INT32_C(  1718962706), -INT32_C(   101870204),  INT32_C(   453199220),  INT32_C(   831181944),  INT32_C(  1143056376), -INT32_C(  2125118044),  INT32_C(  1959945985),  INT32_C(   403436806) },
      { -INT32_C(   998342593), -INT32_C(  1967297770),  INT32_C(   681951408), -INT32_C(  1923534955),  INT32_C(  2077326039), -INT32_C(  1040374081), -INT32_C(  1808412786),  INT32_C(    78397636),
        -INT32_C(   674747711),  INT32_C(  1180796309), -INT32_C(   630323387),  INT32_C(   224905270),  INT32_C(    42547266), -INT32_C(   305953185),  INT32_C(   427948117), -INT32_C(    98751175) },
      { -INT32_C(   321788585), -INT32_C(  1338887574),  INT32_C(  1888133433), -INT32_C(  1417809303), -INT32_C(  1985149398), -INT32_C(   512331636), -INT32_C(  1560545431),  INT32_C(  2073827364),
         INT32_C(  1751674366), -INT32_C(   652698977), -INT32_C(  1538677957), -INT32_C(  1085225323),  INT32_C(  1498021325), -INT32_C(   683950226), -INT32_C(   612813129),  INT32_C(  1280775502) },
       INT32_C(         130),
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(  1342742585),  INT32_C(   158720584),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(  1762656256),
         INT32_C(  1212157228),  INT32_C(  1074825870),  INT32_C(           0),  INT32_C(           0),  INT32_C(   423714885),  INT32_C(           0), -INT32_C(  1842863965),  INT32_C(   205587776) } },
    { UINT16_C(52569),
      {  INT32_C(  1131451898), -INT32_C(  1995832007),  INT32_C(   243783621),  INT32_C(  1808659760),  INT32_C(  1168213196), -INT32_C(  1218776992), -INT32_C(   243868612), -INT32_C(   121647107),
        -INT32_C(  1640288412), -INT32_C(    98089675),  INT32_C(  1292414492),  INT32_C(  1874384291), -INT32_C(  1162585510), -INT32_C(  2039411126), -INT32_C(   394729494),  INT32_C(   467679158) },
      { -INT32_C(  1682367642),  INT32_C(  2106974305),  INT32_C(   852139407), -INT32_C(   844987533),  INT32_C(   663181021),  INT32_C(  1336801381), -INT32_C(  1791547937), -INT32_C(  1011869860),
        -INT32_C(  1805752013), -INT32_C(   653134774),  INT32_C(    67886225),  INT32_C(  1020374367),  INT32_C(  1768118276),  INT32_C(   800591952), -INT32_C(  1832521674),  INT32_C(   978679047) },
      {  INT32_C(   701412575),  INT32_C(   956489896),  INT32_C(   457051580), -INT32_C(  1084813381), -INT32_C(  1205290392),  INT32_C(    15261898), -INT32_C(   661410352),  INT32_C(    18016290),
         INT32_C(  1143660956),  INT32_C(  2105420993), -INT32_C(   174539718),  INT32_C(   867495883),  INT32_C(  1944902825), -INT32_C(  1921723204), -INT32_C(  1553660031), -INT32_C(  1935312913) },
       INT32_C(          88),
      {  INT32_C(  1253572900),  INT32_C(           0),  INT32_C(           0), -INT32_C(   997527037),  INT32_C(  1702958724),  INT32_C(           0),  INT32_C(   560296428),  INT32_C(           0),
        -INT32_C(  1710141840),  INT32_C(           0),  INT32_C(   134222340),  INT32_C(  1544042600),  INT32_C(           0),  INT32_C(           0),  INT32_C(  1243471978),  INT32_C(   323305489) } },
    { UINT16_C(20220),
      {  INT32_C(   772421270), -INT32_C(   551692757), -INT32_C(   172243447), -INT32_C(  1362528454),  INT32_C(  1773488644), -INT32_C(  1813928722),  INT32_C(    23214384), -INT32_C(   380674477),
        -INT32_C(  1088922988),  INT32_C(   966669616),  INT32_C(   909072892), -INT32_C(   706414383),  INT32_C(   826251587),  INT32_C(  1858347069), -INT32_C(  1402001831),  INT32_C(   429309573) },
      {  INT32_C(  1222225432), -INT32_C(   545097757), -INT32_C(  1575636527), -INT32_C(   327681623), -INT32_C(   803359086),  INT32_C(   809427414), -INT32_C(  1914917624), -INT32_C(  2069466517),
         INT32_C(    80510752), -INT32_C(   924627209), -INT32_C(  1452606977), -INT32_C(  2053774862),  INT32_C(  1851110296), -INT32_C(  1667329132), -INT32_C(  1423344832),  INT32_C(   238014701) },
      {  INT32_C(  1175649359),  INT32_C(  1242494282), -INT32_C(   504137490), -INT32_C(   228161446), -INT32_C(   798966981), -INT32_C(  1905459378),  INT32_C(  1731827322), -INT32_C(  1250596506),
        -INT32_C(  1342404763),  INT32_C(  1811483261), -INT32_C(   582161277), -INT32_C(  1328565643), -INT32_C(  1149227155), -INT32_C(  1471550162), -INT32_C(   384793725),  INT32_C(  1369343468) },
       INT32_C(          13),
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(   168047056),  INT32_C(  1094092933), -INT32_C(  1777683246),  INT32_C(  1612595473), -INT32_C(  1667447667),  INT32_C(   111190184),
         INT32_C(           0), -INT32_C(  1000224057), -INT32_C(  1982815741),  INT32_C(   168887594),  INT32_C(           0),  INT32_C(           0),  INT32_C(   327178532),  INT32_C(           0) } },
    { UINT16_C(64165),
      {  INT32_C(  1122380021), -INT32_C(   722183419), -INT32_C(  1945935348),  INT32_C(  1735995933), -INT32_C(   353698598), -INT32_C(  2072979739),  INT32_C(   656309543), -INT32_C(    64896249),
        -INT32_C(   264369941),  INT32_C(  1875129187), -INT32_C(  1292056427), -INT32_C(   736528902),  INT32_C(  1472136050),  INT32_C(    14364633), -INT32_C(  1289160020), -INT32_C(  1448130115) },
      { -INT32_C(  1248203183), -INT32_C(  1239130591),  INT32_C(   543694886),  INT32_C(   150241942),  INT32_C(  1600107397), -INT32_C(  1906361374), -INT32_C(   230586571),  INT32_C(   580645329),
         INT32_C(    14104031), -INT32_C(  1179190125), -INT32_C(  1294393828),  INT32_C(   649776544),  INT32_C(  1669667457), -INT32_C(  1963793323),  INT32_C(  1031549804),  INT32_C(    56563748) },
      { -INT32_C(   536660147),  INT32_C(  1335474483),  INT32_C(  2013426392), -INT32_C(  1063338945),  INT32_C(   723788758),  INT32_C(  1958024712),  INT32_C(  1857106505), -INT32_C(  1754197942),
         INT32_C(  2054649159),  INT32_C(   113905710), -INT32_C(  1048589182),  INT32_C(  1602362760),  INT32_C(  1233823297),  INT32_C(    96288956), -INT32_C(  1133285774), -INT32_C(   967580290) },
       INT32_C(          90),
      { -INT32_C(  1562042440),  INT32_C(           0), -INT32_C(   201256748),  INT32_C(           0),  INT32_C(           0), -INT32_C(   255475475),  INT32_C(           0),  INT32_C(  1800459085),
         INT32_C(           0),  INT32_C(  1762534221),  INT32_C(           0), -INT32_C(  1952749454),  INT32_C(   506832179),  INT32_C(    90599269),  INT32_C(   257660126),  INT32_C(  1878830275) } },
  };

  simde__m512i a, b, c, r;

  a = simde_mm512_loadu_epi32(test_vec[0].a);
  b = simde_mm512_loadu_epi32(test_vec[0].b);
  c = simde_mm512_loadu_epi32(test_vec[0].c);
  r = simde_mm512_maskz_ternarylogic_epi32(test_vec[0].k, a, b, c, INT32_C(         147));
  simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[0].r));

  a = simde_mm512_loadu_epi32(test_vec[1].a);
  b = simde_mm512_loadu_epi32(test_vec[1].b);
  c = simde_mm512_loadu_epi32(test_vec[1].c);
  r = simde_mm512_maskz_ternarylogic_epi32(test_vec[1].k, a, b, c, INT32_C(         176));
  simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[1].r));

  a = simde_mm512_loadu_epi32(test_vec[2].a);
  b = simde_mm512_loadu_epi32(test_vec[2].b);
  c = simde_mm512_loadu_epi32(test_vec[2].c);
  r = simde_mm512_maskz_ternarylogic_epi32(test_vec[2].k, a, b, c, INT32_C(         242));
  simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[2].r));

  a = simde_mm512_loadu_epi32(test_vec[3].a);
  b = simde_mm512_loadu_epi32(test_vec[3].b);
  c = simde_mm512_loadu_epi32(test_vec[3].c);
  r = simde_mm512_maskz_ternarylogic_epi32(test_vec[3].k, a, b, c, INT32_C(         152));
  simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[3].r));

  a = simde_mm512_loadu_epi32(test_vec[4].a);
  b = simde_mm512_loadu_epi32(test_vec[4].b);
  c = simde_mm512_loadu_epi32(test_vec[4].c);
  r = simde_mm512_maskz_ternarylogic_epi32(test_vec[4].k, a, b, c, INT32_C(         130));
  simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[4].r));

  a = simde_mm512_loadu_epi32(test_vec[5].a);
  b = simde_mm512_loadu_epi32(test_vec[5].b);
  c = simde_mm512_loadu_epi32(test_vec[5].c);
  r = simde_mm512_maskz_ternarylogic_epi32(test_vec[5].k, a, b, c, INT32_C(          88));
  simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[5].r));

  a = simde_mm512_loadu_epi32(test_vec[6].a);
  b = simde_mm512_loadu_epi32(test_vec[6].b);
  c = simde_mm512_loadu_epi32(test_vec[6].c);
  r = simde_mm512_maskz_ternarylogic_epi32(test_vec[6].k, a, b, c, INT32_C(          13));
  simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[6].r));

  a = simde_mm512_loadu_epi32(test_vec[7].a);
  b = simde_mm512_loadu_epi32(test_vec[7].b);
  c = simde_mm512_loadu_epi32(test_vec[7].c);
  r = simde_mm512_maskz_ternarylogic_epi32(test_vec[7].k, a, b, c, INT32_C(          90));
  simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[7].r));

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask16 k = simde_test_x86_random_mmask16();
    simde__m512i a = simde_test_x86_random_i32x16();
    simde__m512i b = simde_test_x86_random_i32x16();
    simde__m512i c = simde_test_x86_random_i32x16();
    int imm8 = simde_test_codegen_random_i32() & 255;
    simde__m512i r;
    SIMDE_CONSTIFY_256_(simde_mm512_maskz_ternarylogic_epi32, r, simde_mm512_setzero_si512(), imm8, k, a, b, c);

    simde_test_x86_write_mmask16(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x16(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_ternarylogic_epi64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int64_t a[2];
    const int64_t b[2];
    const int64_t c[2];
    const int imm8;
    const int64_t r[2];
  } test_vec[] = {
    { {  INT64_C( 3593338318455995178), -INT64_C( 4218279493250952836) },
      {  INT64_C( 1225020802220563216), -INT64_C( 2742210933595917303) },
      { -INT64_C( 1834014625161064655), -INT64_C( 4863090809230130537) },
       INT32_C(         239),
      { -INT64_C(   23109535409905675), -INT64_C(    1134696001978721) } },
    { { -INT64_C(   85638424426538374),  INT64_C( 8791376188843475061) },
      {  INT64_C( 4312407264567790980),  INT64_C( 3053319259678006163) },
      { -INT64_C( 8973284760689423060),  INT64_C( 1353378478709887038) },
       INT32_C(         183),
      { -INT64_C( 4148023077831214341), -INT64_C( 2902869647641939972) } },
    { {  INT64_C( 1296045351861618407), -INT64_C( 5209843806417232885) },
      {  INT64_C(  717026144091253351), -INT64_C( 3851622340842767474) },
      { -INT64_C( 7727823425967485105),  INT64_C( 5691845031561591965) },
       INT32_C(         168),
      {  INT64_C( 1207317684975308359),  INT64_C( 5673527150650129549) } },
    { { -INT64_C( 8759985463387953253), -INT64_C( 7813862954535683184) },
      {  INT64_C( 3727277680595783894), -INT64_C( 8557554051426699407) },
      {  INT64_C( 4720935353462188380),  INT64_C( 4663952859071567132) },
       INT32_C(           0),
      {  INT64_C(                   0),  INT64_C(                   0) } },
    { {  INT64_C( 1323779165983435988), -INT64_C( 5273066426765435785) },
      { -INT64_C( 7660316015381227921),  INT64_C( 2167788650427148999) },
      {  INT64_C( 1164958515935352565), -INT64_C( 8999399231644711328) },
       INT32_C(          12),
      { -INT64_C( 8818024943964515797),  INT64_C(  578009182641611392) } },
    { {  INT64_C( 8338875585598963498), -INT64_C(  127800200204726485) },
      {  INT64_C( 4431527916195505081), -INT64_C( 2887424540600657239) },
      { -INT64_C( 8562888398186431603),  INT64_C( 7761359889551244369) },
       INT32_C(          70),
      { -INT64_C( 5452327017694937036), -INT64_C( 7761939530920746248) } },
    { {  INT64_C( 5410352153861358775),  INT64_C( 2053900634748486460) },
      {  INT64_C( 1762120656912493165), -INT64_C( 6563704066365183694) },
      {  INT64_C( 4753296539064243725),  INT64_C( 8212185298504456477) },
       INT32_C(          54),
      {  INT64_C( 6017708469745368274), -INT64_C( 2801553069338316273) } },
    { { -INT64_C( 4929407713987418900),  INT64_C( 2016033834480402498) },
      {  INT64_C( 1114191257369637246), -INT64_C(  736989410607665677) },
      { -INT64_C(  730238778704889260),  INT64_C( 2188256426504502316) },
       INT32_C(          48),
      { -INT64_C( 5728270020868242304),  INT64_C(  736976351489064960) } },
  };

  simde__m128i a, b, c, r;

  a = simde_x_mm_loadu_epi64(test_vec[0].a);
  b = simde_x_mm_loadu_epi64(test_vec[0].b);
  c = simde_x_mm_loadu_epi64(test_vec[0].c);
  r = simde_mm_ternarylogic_epi64(a, b, c, INT32_C(         239));
  simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[0].r));

  a = simde_x_mm_loadu_epi64(test_vec[1].a);
  b = simde_x_mm_loadu_epi64(test_vec[1].b);
  c = simde_x_mm_loadu_epi64(test_vec[1].c);
  r = simde_mm_ternarylogic_epi64(a, b, c, INT32_C(         183));
  simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[1].r));

  a = simde_x_mm_loadu_epi64(test_vec[2].a);
  b = simde_x_mm_loadu_epi64(test_vec[2].b);
  c = simde_x_mm_loadu_epi64(test_vec[2].c);
  r = simde_mm_ternarylogic_epi64(a, b, c, INT32_C(         168));
  simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[2].r));

  a = simde_x_mm_loadu_epi64(test_vec[3].a);
  b = simde_x_mm_loadu_epi64(test_vec[3].b);
  c = simde_x_mm_loadu_epi64(test_vec[3].c);
  r = simde_mm_ternarylogic_epi64(a, b, c, INT32_C(           0));
  simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[3].r));

  a = simde_x_mm_loadu_epi64(test_vec[4].a);
  b = simde_x_mm_loadu_epi64(test_vec[4].b);
  c = simde_x_mm_loadu_epi64(test_vec[4].c);
  r = simde_mm_ternarylogic_epi64(a, b, c, INT32_C(          12));
  simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[4].r));

  a = simde_x_mm_loadu_epi64(test_vec[5].a);
  b = simde_x_mm_loadu_epi64(test_vec[5].b);
  c = simde_x_mm_loadu_epi64(test_vec[5].c);
  r = simde_mm_ternarylogic_epi64(a, b, c, INT32_C(          70));
  simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[5].r));

  a = simde_x_mm_loadu_epi64(test_vec[6].a);
  b = simde_x_mm_loadu_epi64(test_vec[6].b);
  c = simde_x_mm_loadu_epi64(test_vec[6].c);
  r = simde_mm_ternarylogic_epi64(a, b, c, INT32_C(          54));
  simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[6].r));

  a = simde_x_mm_loadu_epi64(test_vec[7].a);
  b = simde_x_mm_loadu_epi64(test_vec[7].b);
  c = simde_x_mm_loadu_epi64(test_vec[7].c);
  r = simde_mm_ternarylogic_epi64(a, b, c, INT32_C(          48));
  simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[7].r));

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i64x2();
    simde__m128i b = simde_test_x86_random_i64x2();
    simde__m128i c = simde_test_x86_random_i64x2();
    int imm8 = simde_test_codegen_random_i32() & 255;
    simde__m128i r;
    SIMDE_CONSTIFY_256_(simde_mm_ternarylogic_epi64, r, simde_mm_setzero_si128(), imm8, a, b, c);

    simde_test_x86_write_i64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x2(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_mask_ternarylogic_epi64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int64_t src[2];
    const simde__mmask8 k;
    const int64_t a[2];
    const int64_t b[2];
    const int imm8;
    const int64_t r[2];
  } test_vec[] = {
    { { -INT64_C( 6467507044113240286),  INT64_C( 3671471080454423676) },
      UINT8_C( 91),
      { -INT64_C( 6075977756837468208), -INT64_C( 5474662433201337560) },
      {  INT64_C( 6821536552302222178),  INT64_C( 4511778268426042258) },
       INT32_C(          54),
      {  INT64_C( 6130302557271890098), -INT64_C( 8432505438292626218) } },
    { {  INT64_C( 5258560333266417902),  INT64_C( 8489089703205470271) },
      UINT8_C( 69),
      { -INT64_C( 4727625461002677382), -INT64_C( 1889094095357041994) },
      { -INT64_C( 2788869629703233565),  INT64_C( 3927537706752863726) },
       INT32_C(          61),
      { -INT64_C(  676041905999828076),  INT64_C( 8489089703205470271) } },
    { {  INT64_C( 2306863571451809906), -INT64_C( 8924253561688830921) },
      UINT8_C(160),
      { -INT64_C( 4964150613889884814),  INT64_C( 1015815147596894796) },
      {  INT64_C( 1182863698172068242),  INT64_C( 2140405726927619174) },
       INT32_C(         156),
      {  INT64_C( 2306863571451809906), -INT64_C( 8924253561688830921) } },
    { {  INT64_C( 7422111309038720782), -INT64_C( 7111546267742431095) },
      UINT8_C( 22),
      { -INT64_C( 6203548605513683272),  INT64_C( 1771660134846891333) },
      {  INT64_C(  650886632093970909),  INT64_C( 3146889632246015199) },
       INT32_C(         173),
      {  INT64_C( 7422111309038720782),  INT64_C( 5303753636401694701) } },
    { { -INT64_C( 2988413960832659271), -INT64_C(   29853879203128007) },
      UINT8_C( 90),
      {  INT64_C( 7652968624729688222),  INT64_C( 1682708845712334713) },
      { -INT64_C(  203432874220955154),  INT64_C( 8537430541506200369) },
       INT32_C(          20),
      { -INT64_C( 2988413960832659271), -INT64_C( 8609523484333113280) } },
    { { -INT64_C( 7738027704336224894),  INT64_C( 3535633919131777070) },
      UINT8_C( 90),
      {  INT64_C( 5069273322375294526),  INT64_C( 8457716157810135080) },
      { -INT64_C( 1013355022957519935),  INT64_C( 6626047522731330689) },
       INT32_C(         161),
      { -INT64_C( 7738027704336224894), -INT64_C( 7993866578560677040) } },
    { {  INT64_C( 1023016432006477356), -INT64_C( 1813043078399487660) },
      UINT8_C(156),
      { -INT64_C( 8290925592461846586),  INT64_C( 6797912230650006443) },
      {  INT64_C( 8069450932957785131), -INT64_C( 5883879345799556618) },
       INT32_C(          25),
      {  INT64_C( 1023016432006477356), -INT64_C( 1813043078399487660) } },
    { { -INT64_C( 2016789387274194899), -INT64_C( 2033192690794735115) },
      UINT8_C( 24),
      { -INT64_C(  955102114884922428),  INT64_C( 6757438951810362404) },
      { -INT64_C(  297521653534318596), -INT64_C( 8287216192100171969) },
       INT32_C(          55),
      { -INT64_C( 2016789387274194899), -INT64_C( 2033192690794735115) } },
  };

  simde__m128i src, a, b, r;

  src = simde_x_mm_loadu_epi64(test_vec[0].src);
  a = simde_x_mm_loadu_epi64(test_vec[0].a);
  b = simde_x_mm_loadu_epi64(test_vec[0].b);
  r = simde_mm_mask_ternarylogic_epi64(src, test_vec[0].k, a, b, INT32_C(          54));
  simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[0].r));

  src = simde_x_mm_loadu_epi64(test_vec[1].src);
  a = simde_x_mm_loadu_epi64(test_vec[1].a);
  b = simde_x_mm_loadu_epi64(test_vec[1].b);
  r = simde_mm_mask_ternarylogic_epi64(src, test_vec[1].k, a, b, INT32_C(          61));
  simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[1].r));

  src = simde_x_mm_loadu_epi64(test_vec[2].src);
  a = simde_x_mm_loadu_epi64(test_vec[2].a);
  b = simde_x_mm_loadu_epi64(test_vec[2].b);
  r = simde_mm_mask_ternarylogic_epi64(src, test_vec[2].k, a, b, INT32_C(         156));
  simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[2].r));

  src = simde_x_mm_loadu_epi64(test_vec[3].src);
  a = simde_x_mm_loadu_epi64(test_vec[3].a);
  b = simde_x_mm_loadu_epi64(test_vec[3].b);
  r = simde_mm_mask_ternarylogic_epi64(src, test_vec[3].k, a, b, INT32_C(         173));
  simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[3].r));

  src = simde_x_mm_loadu_epi64(test_vec[4].src);
  a = simde_x_mm_loadu_epi64(test_vec[4].a);
  b = simde_x_mm_loadu_epi64(test_vec[4].b);
  r = simde_mm_mask_ternarylogic_epi64(src, test_vec[4].k, a, b, INT32_C(          20));
  simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[4].r));

  src = simde_x_mm_loadu_epi64(test_vec[5].src);
  a = simde_x_mm_loadu_epi64(test_vec[5].a);
  b = simde_x_mm_loadu_epi64(test_vec[5].b);
  r = simde_mm_mask_ternarylogic_epi64(src, test_vec[5].k, a, b, INT32_C(         161));
  simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[5].r));

  src = simde_x_mm_loadu_epi64(test_vec[6].src);
  a = simde_x_mm_loadu_epi64(test_vec[6].a);
  b = simde_x_mm_loadu_epi64(test_vec[6].b);
  r = simde_mm_mask_ternarylogic_epi64(src, test_vec[6].k, a, b, INT32_C(          25));
  simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[6].r));

  src = simde_x_mm_loadu_epi64(test_vec[7].src);
  a = simde_x_mm_loadu_epi64(test_vec[7].a);
  b = simde_x_mm_loadu_epi64(test_vec[7].b);
  r = simde_mm_mask_ternarylogic_epi64(src, test_vec[7].k, a, b, INT32_C(          55));
  simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[7].r));

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i src = simde_test_x86_random_i64x2();
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128i a = simde_test_x86_random_i64x2();
    simde__m128i b = simde_test_x86_random_i64x2();
    int imm8 = simde_test_codegen_random_i32() & 255;
    simde__m128i r;
    SIMDE_CONSTIFY_256_(simde_mm_mask_ternarylogic_epi64, r, simde_mm_setzero_si128(), imm8, src, k, a, b);

    simde_test_x86_write_i64x2(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x2(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_maskz_ternarylogic_epi64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const int64_t a[2];
    const int64_t b[2];
    const int64_t c[2];
    const int imm8;
    const int64_t r[2];
  } test_vec[] = {
    { UINT8_C(216),
      {  INT64_C( 2483901102856919072), -INT64_C( 1469009180439423651) },
      {  INT64_C( 9055348629390924005), -INT64_C( 5048083724953700595) },
      { -INT64_C( 2271575065717510797), -INT64_C( 8976383661060614253) },
       INT32_C(          18),
      {  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C(167),
      {  INT64_C( 8639257430744901651), -INT64_C( 6831888188589826625) },
      {  INT64_C( 7489687310703006138), -INT64_C( 1269129044298140892) },
      { -INT64_C( 6511891811324651442), -INT64_C( 8773430109235147846) },
       INT32_C(         148),
      {  INT64_C( 3869828846105665955), -INT64_C( 3935752515516996319) } },
    { UINT8_C( 41),
      { -INT64_C( 8640708513262343736),  INT64_C( 6442963580640167020) },
      { -INT64_C( 1874992359120105310),  INT64_C( 2417020511343706606) },
      {  INT64_C( 5534769874168764388),  INT64_C( 5264210605921904247) },
       INT32_C(          75),
      { -INT64_C( 2965208454698822091),  INT64_C(                   0) } },
    { UINT8_C(210),
      {  INT64_C(  597889194341208946),  INT64_C( 4351097130571296171) },
      { -INT64_C( 4949622563661369598), -INT64_C( 9049221418372851338) },
      { -INT64_C(  622128639911843256),  INT64_C( 9166193570908621102) },
       INT32_C(         139),
      {  INT64_C(                   0),  INT64_C( 4879047900057963302) } },
    { UINT8_C( 81),
      { -INT64_C( 8998086716836821129), -INT64_C( 2720137783861861431) },
      { -INT64_C( 8195424658342267010),  INT64_C( 7092648154890879797) },
      {  INT64_C( 6862802578958333676), -INT64_C( 6329647470652225483) },
       INT32_C(         202),
      { -INT64_C( 2441654059851040770),  INT64_C(                   0) } },
    { UINT8_C( 49),
      {  INT64_C( 5216156981792213684), -INT64_C( 3909706980822563342) },
      {  INT64_C(  170377500935789611),  INT64_C( 3086735364250731893) },
      { -INT64_C( 5566724290224440237),  INT64_C(  993773664738145226) },
       INT32_C(         180),
      {  INT64_C( 5198221649332865692),  INT64_C(                   0) } },
    { UINT8_C( 22),
      {  INT64_C( 4330828914177549983), -INT64_C( 1512077088338787321) },
      {  INT64_C( 2853794046583092932), -INT64_C( 8619608309338757248) },
      {  INT64_C( 2617794374182693925), -INT64_C( 5955046336693214326) },
       INT32_C(          34),
      {  INT64_C(                   0),  INT64_C( 2673730804581941258) } },
    { UINT8_C(198),
      { -INT64_C( 5435966015848064257), -INT64_C( 8432162074215770127) },
      { -INT64_C(  859759238311502011),  INT64_C( 2501970749210148577) },
      { -INT64_C( 9147557891131506781),  INT64_C( 2107220462913185391) },
       INT32_C(         120),
      {  INT64_C(                   0), -INT64_C( 8447987346970791536) } },
  };

  simde__m128i a, b, c, r;

  a = simde_x_mm_loadu_epi64(test_vec[0].a);
  b = simde_x_mm_loadu_epi64(test_vec[0].b);
  c = simde_x_mm_loadu_epi64(test_vec[0].c);
  r = simde_mm_maskz_ternarylogic_epi64(test_vec[0].k, a, b, c, INT32_C(          18));
  simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[0].r));

  a = simde_x_mm_loadu_epi64(test_vec[1].a);
  b = simde_x_mm_loadu_epi64(test_vec[1].b);
  c = simde_x_mm_loadu_epi64(test_vec[1].c);
  r = simde_mm_maskz_ternarylogic_epi64(test_vec[1].k, a, b, c, INT32_C(         148));
  simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[1].r));

  a = simde_x_mm_loadu_epi64(test_vec[2].a);
  b = simde_x_mm_loadu_epi64(test_vec[2].b);
  c = simde_x_mm_loadu_epi64(test_vec[2].c);
  r = simde_mm_maskz_ternarylogic_epi64(test_vec[2].k, a, b, c, INT32_C(          75));
  simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[2].r));

  a = simde_x_mm_loadu_epi64(test_vec[3].a);
  b = simde_x_mm_loadu_epi64(test_vec[3].b);
  c = simde_x_mm_loadu_epi64(test_vec[3].c);
  r = simde_mm_maskz_ternarylogic_epi64(test_vec[3].k, a, b, c, INT32_C(         139));
  simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[3].r));

  a = simde_x_mm_loadu_epi64(test_vec[4].a);
  b = simde_x_mm_loadu_epi64(test_vec[4].b);
  c = simde_x_mm_loadu_epi64(test_vec[4].c);
  r = simde_mm_maskz_ternarylogic_epi64(test_vec[4].k, a, b, c, INT32_C(         202));
  simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[4].r));

  a = simde_x_mm_loadu_epi64(test_vec[5].a);
  b = simde_x_mm_loadu_epi64(test_vec[5].b);
  c = simde_x_mm_loadu_epi64(test_vec[5].c);
  r = simde_mm_maskz_ternarylogic_epi64(test_vec[5].k, a, b, c, INT32_C(         180));
  simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[5].r));

  a = simde_x_mm_loadu_epi64(test_vec[6].a);
  b = simde_x_mm_loadu_epi64(test_vec[6].b);
  c = simde_x_mm_loadu_epi64(test_vec[6].c);
  r = simde_mm_maskz_ternarylogic_epi64(test_vec[6].k, a, b, c, INT32_C(          34));
  simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[6].r));

  a = simde_x_mm_loadu_epi64(test_vec[7].a);
  b = simde_x_mm_loadu_epi64(test_vec[7].b);
  c = simde_x_mm_loadu_epi64(test_vec[7].c);
  r = simde_mm_maskz_ternarylogic_epi64(test_vec[7].k, a, b, c, INT32_C(         120));
  simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[7].r));

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128i a = simde_test_x86_random_i64x2();
    simde__m128i b = simde_test_x86_random_i64x2();
    simde__m128i c = simde_test_x86_random_i64x2();
    int imm8 = simde_test_codegen_random_i32() & 255;
    simde__m128i r;
    SIMDE_CONSTIFY_256_(simde_mm_maskz_ternarylogic_epi64, r, simde_mm_setzero_si128(), imm8, k, a, b, c);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x2(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x2(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_ternarylogic_epi64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int64_t a[4];
    const int64_t b[4];
    const int64_t c[4];
    const int imm8;
    const int64_t r[4];
  } test_vec[] = {
    { {  INT64_C( 4672784183482302238), -INT64_C( 1848234369605930829), -INT64_C( 9213680585050418790),  INT64_C( 3928946576953237789) },
      { -INT64_C( 3467446134668063700),  INT64_C( 3756356794401282457), -INT64_C( 3087696138570413485), -INT64_C( 8756193556550783443) },
      { -INT64_C( 8306878569491412276),  INT64_C( 4013244811024245219),  INT64_C( 6106603089716697906), -INT64_C( 8803951535469233679) },
       INT32_C(         223),
      { -INT64_C(    6755816187134465), -INT64_C(  148759662630543395), -INT64_C(       2208686936321), -INT64_C(   36033195073863953) } },
    { { -INT64_C( 6024648856709486844),  INT64_C( 1669359849519191309), -INT64_C( 7205191077774759227), -INT64_C( 3185856038509095656) },
      {  INT64_C( 6497601676298037175), -INT64_C( 7621563016846634957), -INT64_C( 4454816866693700178), -INT64_C( 7581946449748209884) },
      { -INT64_C( 3147662504959311190),  INT64_C( 6825542438060813137),  INT64_C( 8809917553451140823),  INT64_C( 3089810739707182188) },
       INT32_C(         184),
      { -INT64_C(  846639892156644702),  INT64_C( 1673089054246569245),  INT64_C( 6774272844423450311),  INT64_C( 4884455471217957948) } },
    { {  INT64_C(  913144808601317944), -INT64_C( 4418494763738962346),  INT64_C( 7867414641565888887),  INT64_C( 4463832514868744161) },
      { -INT64_C( 7452204753808318934), -INT64_C( 3528442385551393063), -INT64_C( 3260077328126818970),  INT64_C( 4337632822336182767) },
      {  INT64_C( 5068616034509126012), -INT64_C(  540830448011698858),  INT64_C(   44487416396656858), -INT64_C( 1966902708083029402) },
       INT32_C(          33),
      {  INT64_C( 2666285517830643857),  INT64_C(   10977529327845414),  INT64_C(    3968139663260176),  INT64_C(  182714102291997200) } },
    { { -INT64_C( 6137455110833964081), -INT64_C( 7810105408137047562), -INT64_C( 5991325427458426116), -INT64_C( 3071116266982764879) },
      { -INT64_C( 8146222726311692753),  INT64_C( 9166227684372485407),  INT64_C(   83242171974731574),  INT64_C( 2028367971278436427) },
      {  INT64_C(  905319101048823915),  INT64_C( 2445140049015992299), -INT64_C( 2811439627328827223),  INT64_C( 8035353040488353658) },
       INT32_C(         111),
      { -INT64_C( 2923223186881505676),  INT64_C( 9149937295627910909), -INT64_C( 2594778173937952865),  INT64_C( 8917122835156006783) } },
    { { -INT64_C( 2551263963867708867), -INT64_C( 1974096884989589768),  INT64_C( 7511411974786028891), -INT64_C( 1945755529643573196) },
      {  INT64_C( 8582072530818132043),  INT64_C(  821821923906819628),  INT64_C( 4329399639395607368), -INT64_C( 9193572842839479074) },
      {  INT64_C( 5205552163391895367),  INT64_C( 5739611258383717868), -INT64_C( 8892056583027259307), -INT64_C( 7011134476041750275) },
       INT32_C(         233),
      {  INT64_C( 6655087134819476175),  INT64_C( 6892748267891277551),  INT64_C( 3413470363655258617), -INT64_C( 8792334616921904132) } },
    { { -INT64_C(  157877817209609914), -INT64_C( 6557441174434646452),  INT64_C( 7532887277277059418), -INT64_C(  751139414917890397) },
      {  INT64_C( 5260195547220336907), -INT64_C( 1220500146024199059),  INT64_C(  863795475642726274),  INT64_C( 8769119174776062735) },
      {  INT64_C( 4490222767185779213), -INT64_C( 6464433323834262843),  INT64_C( 8098377446157095151),  INT64_C( 3756248550140148538) },
       INT32_C(         186),
      { -INT64_C( 4661091657612076467), -INT64_C( 6414893407957861691),  INT64_C( 8098377514876573951), -INT64_C( 5466841461981970502) } },
    { { -INT64_C( 1498444374289511148),  INT64_C( 8030986921512697388), -INT64_C(  439931291478010365), -INT64_C( 5389848190311922196) },
      { -INT64_C( 7013860051357008394),  INT64_C(  846163293712825153), -INT64_C( 7579788336566788860),  INT64_C( 6667984305953569843) },
      {  INT64_C( 2125069948297025646),  INT64_C( 7571161636479449087), -INT64_C( 4825309542260712504),  INT64_C( 2723299774828725770) },
       INT32_C(          50),
      {  INT64_C( 7013288305308467208),  INT64_C( 7224269025189315774),  INT64_C( 7575054921829335755), -INT64_C( 6813370563835198516) } },
    { {  INT64_C( 2211152765708305065), -INT64_C( 6413752464125214270),  INT64_C(  238396441282938580), -INT64_C( 6319062652837947122) },
      { -INT64_C( 3348427356286977873), -INT64_C( 6231757209297219904), -INT64_C( 1535772704651024545), -INT64_C( 5506080432331171857) },
      { -INT64_C( 6425893514342766863), -INT64_C( 1859978367445291343),  INT64_C( 9058218307082172655),  INT64_C( 5462868929769431064) },
       INT32_C(         233),
      { -INT64_C( 7599903891456924759), -INT64_C( 5280919483028398388),  INT64_C( 7759663596862613215), -INT64_C( 5766954579640397554) } },
  };

  simde__m256i a, b, c, r;

  a = simde_x_mm256_loadu_epi64(test_vec[0].a);
  b = simde_x_mm256_loadu_epi64(test_vec[0].b);
  c = simde_x_mm256_loadu_epi64(test_vec[0].c);
  r = simde_mm256_ternarylogic_epi64(a, b, c, INT32_C(         223));
  simde_test_x86_assert_equal_i64x4(r, simde_x_mm256_loadu_epi64(test_vec[0].r));

  a = simde_x_mm256_loadu_epi64(test_vec[1].a);
  b = simde_x_mm256_loadu_epi64(test_vec[1].b);
  c = simde_x_mm256_loadu_epi64(test_vec[1].c);
  r = simde_mm256_ternarylogic_epi64(a, b, c, INT32_C(         184));
  simde_test_x86_assert_equal_i64x4(r, simde_x_mm256_loadu_epi64(test_vec[1].r));

  a = simde_x_mm256_loadu_epi64(test_vec[2].a);
  b = simde_x_mm256_loadu_epi64(test_vec[2].b);
  c = simde_x_mm256_loadu_epi64(test_vec[2].c);
  r = simde_mm256_ternarylogic_epi64(a, b, c, INT32_C(          33));
  simde_test_x86_assert_equal_i64x4(r, simde_x_mm256_loadu_epi64(test_vec[2].r));

  a = simde_x_mm256_loadu_epi64(test_vec[3].a);
  b = simde_x_mm256_loadu_epi64(test_vec[3].b);
  c = simde_x_mm256_loadu_epi64(test_vec[3].c);
  r = simde_mm256_ternarylogic_epi64(a, b, c, INT32_C(         111));
  simde_test_x86_assert_equal_i64x4(r, simde_x_mm256_loadu_epi64(test_vec[3].r));

  a = simde_x_mm256_loadu_epi64(test_vec[4].a);
  b = simde_x_mm256_loadu_epi64(test_vec[4].b);
  c = simde_x_mm256_loadu_epi64(test_vec[4].c);
  r = simde_mm256_ternarylogic_epi64(a, b, c, INT32_C(         233));
  simde_test_x86_assert_equal_i64x4(r, simde_x_mm256_loadu_epi64(test_vec[4].r));

  a = simde_x_mm256_loadu_epi64(test_vec[5].a);
  b = simde_x_mm256_loadu_epi64(test_vec[5].b);
  c = simde_x_mm256_loadu_epi64(test_vec[5].c);
  r = simde_mm256_ternarylogic_epi64(a, b, c, INT32_C(         186));
  simde_test_x86_assert_equal_i64x4(r, simde_x_mm256_loadu_epi64(test_vec[5].r));

  a = simde_x_mm256_loadu_epi64(test_vec[6].a);
  b = simde_x_mm256_loadu_epi64(test_vec[6].b);
  c = simde_x_mm256_loadu_epi64(test_vec[6].c);
  r = simde_mm256_ternarylogic_epi64(a, b, c, INT32_C(          50));
  simde_test_x86_assert_equal_i64x4(r, simde_x_mm256_loadu_epi64(test_vec[6].r));

  a = simde_x_mm256_loadu_epi64(test_vec[7].a);
  b = simde_x_mm256_loadu_epi64(test_vec[7].b);
  c = simde_x_mm256_loadu_epi64(test_vec[7].c);
  r = simde_mm256_ternarylogic_epi64(a, b, c, INT32_C(         233));
  simde_test_x86_assert_equal_i64x4(r, simde_x_mm256_loadu_epi64(test_vec[7].r));

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256i a = simde_test_x86_random_i64x4();
    simde__m256i b = simde_test_x86_random_i64x4();
    simde__m256i c = simde_test_x86_random_i64x4();
    int imm8 = simde_test_codegen_random_i32() & 255;
    simde__m256i r;
    SIMDE_CONSTIFY_256_(simde_mm256_ternarylogic_epi64, r, simde_mm256_setzero_si256(), imm8, a, b, c);

    simde_test_x86_write_i64x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x4(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_mask_ternarylogic_epi64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int64_t src[4];
    const simde__mmask8 k;
    const int64_t a[4];
    const int64_t b[4];
    const int imm8;
    const int64_t r[4];
  } test_vec[] = {
    { { -INT64_C( 3114247606609109361),  INT64_C( 4447671525024987135), -INT64_C( 6214079837787951218),  INT64_C( 1216324293184754729) },
      UINT8_C( 94),
      {  INT64_C( 1174735919684211029),  INT64_C( 7212231084283476795),  INT64_C( 1443505389150911672),  INT64_C( 5904119041170348880) },
      {  INT64_C( 6133599339183839989), -INT64_C( 7890038429040386777), -INT64_C( 2214510357052836688),  INT64_C( 8278285157487728789) },
       INT32_C(         251),
      { -INT64_C( 3114247606609109361), -INT64_C( 4613374868287651841), -INT64_C( 1443403681797013505), -INT64_C(   75580429293323073) } },
    { {  INT64_C( 6246853858059591277), -INT64_C(  712595242923511236), -INT64_C( 5333870302024212268), -INT64_C( 3694455419869536855) },
      UINT8_C( 71),
      {  INT64_C( 4947513232584827173),  INT64_C( 1238949155656340738),  INT64_C( 8244964561489927032), -INT64_C( 1290389278101008601) },
      { -INT64_C(  696644025849160962),  INT64_C( 1828044322769207195), -INT64_C( 3519767997153892321), -INT64_C( 7850417823856723883) },
       INT32_C(         144),
      {  INT64_C( 4900268360712848420), -INT64_C(  715972942659317724),  INT64_C(   50174048625705104), -INT64_C( 3694455419869536855) } },
    { { -INT64_C( 7397499972226516626),  INT64_C(  226741684907717713), -INT64_C( 2646584664175522350),  INT64_C( 3043046570664546855) },
      UINT8_C( 11),
      {  INT64_C( 4454796195323458484), -INT64_C( 5355451308187237809),  INT64_C( 7784706267347080303), -INT64_C( 5808989329918738364) },
      {  INT64_C( 5930117021503088261), -INT64_C(  980980410220681659),  INT64_C( 8518237855910419631),  INT64_C( 3838807068375801500) },
       INT32_C(         148),
      { -INT64_C( 5422244407706539938),  INT64_C(  335667929192468571), -INT64_C( 2646584664175522350), -INT64_C( 6909855602729893785) } },
    { { -INT64_C(  402201938648002183),  INT64_C( 6659627763335220722), -INT64_C( 5778224977885879908),  INT64_C(  502478516343018957) },
      UINT8_C(186),
      { -INT64_C(  149978673247566622), -INT64_C( 7389417458800030441), -INT64_C( 8016047268327543979), -INT64_C(  140137037631315413) },
      { -INT64_C( 9073377304436588569),  INT64_C( 1513717171746323568),  INT64_C(  829729823865280888), -INT64_C( 6267200051796205588) },
       INT32_C(         174),
      { -INT64_C(  402201938648002183), -INT64_C( 7705148791210689419), -INT64_C( 5778224977885879908), -INT64_C(  502592455410401298) } },
    { { -INT64_C( 3406704767196801824),  INT64_C( 3615526637797751233),  INT64_C( 1273566859534184376), -INT64_C( 8010924412696350196) },
      UINT8_C( 78),
      {  INT64_C( 5990402790166356333),  INT64_C( 4087817690463689748), -INT64_C( 4773648428971893226), -INT64_C( 4964376024831919278) },
      { -INT64_C( 4842706981504583201),  INT64_C( 6871499387004940699), -INT64_C( 3629950245609937961), -INT64_C( 1560300408430588594) },
       INT32_C(          45),
      { -INT64_C( 3406704767196801824), -INT64_C( 8460238481518467147), -INT64_C( 5887292404417826426),  INT64_C( 3417251689249720831) } },
    { { -INT64_C( 1696642514430054732),  INT64_C( 3351340800251777225),  INT64_C( 4114201186989187373), -INT64_C( 7328897123537948601) },
      UINT8_C(180),
      {  INT64_C( 3383675970695457500),  INT64_C( 4109832730116724098),  INT64_C( 1073441788832220426), -INT64_C( 9151720556486960444) },
      {  INT64_C( 1010110942218572152), -INT64_C(  105565261093214921),  INT64_C( 6135733998210314105),  INT64_C( 2377793574807739099) },
       INT32_C(         239),
      { -INT64_C( 1696642514430054732),  INT64_C( 3351340800251777225), -INT64_C( 2312620537936871429), -INT64_C( 7328897123537948601) } },
    { { -INT64_C( 3182789433765463474), -INT64_C( 2523584464197428119), -INT64_C( 2140950097407434514),  INT64_C( 4889494078191978863) },
      UINT8_C(242),
      { -INT64_C(  485363336937879451),  INT64_C( 4598212739880789365),  INT64_C( 3284069588705843795),  INT64_C( 3550918759481012829) },
      {  INT64_C( 3586077776044300333),  INT64_C( 9210956538705021300),  INT64_C(  400600088208166014),  INT64_C( 4911072138160222505) },
       INT32_C(         187),
      { -INT64_C( 3182789433765463474), -INT64_C(       2286537679874), -INT64_C( 2140950097407434514),  INT64_C( 4889494078191978863) } },
    { {  INT64_C(  542891412298519169),  INT64_C( 5800964696601680800), -INT64_C( 2774304495845961375),  INT64_C( 6522667846560753235) },
      UINT8_C(254),
      {  INT64_C( 3714310635188277038),  INT64_C( 4463959126096718440), -INT64_C( 6663962970919305856),  INT64_C( 5052992701767389941) },
      {  INT64_C( 4769238179128670501), -INT64_C( 5273496130723509657), -INT64_C( 7069407144660447420),  INT64_C( 6582817029701394685) },
       INT32_C(         214),
      {  INT64_C(  542891412298519169), -INT64_C( 2619988079350645841), -INT64_C( 1792551575137438811),  INT64_C( 5171578200951608923) } },
  };

  simde__m256i src, a, b, r;

  src = simde_x_mm256_loadu_epi64(test_vec[0].src);
  a = simde_x_mm256_loadu_epi64(test_vec[0].a);
  b = simde_x_mm256_loadu_epi64(test_vec[0].b);
  r = simde_mm256_mask_ternarylogic_epi64(src, test_vec[0].k, a, b, INT32_C(         251));
  simde_test_x86_assert_equal_i64x4(r, simde_x_mm256_loadu_epi64(test_vec[0].r));

  src = simde_x_mm256_loadu_epi64(test_vec[1].src);
  a = simde_x_mm256_loadu_epi64(test_vec[1].a);
  b = simde_x_mm256_loadu_epi64(test_vec[1].b);
  r = simde_mm256_mask_ternarylogic_epi64(src, test_vec[1].k, a, b, INT32_C(         144));
  simde_test_x86_assert_equal_i64x4(r, simde_x_mm256_loadu_epi64(test_vec[1].r));

  src = simde_x_mm256_loadu_epi64(test_vec[2].src);
  a = simde_x_mm256_loadu_epi64(test_vec[2].a);
  b = simde_x_mm256_loadu_epi64(test_vec[2].b);
  r = simde_mm256_mask_ternarylogic_epi64(src, test_vec[2].k, a, b, INT32_C(         148));
  simde_test_x86_assert_equal_i64x4(r, simde_x_mm256_loadu_epi64(test_vec[2].r));

  src = simde_x_mm256_loadu_epi64(test_vec[3].src);
  a = simde_x_mm256_loadu_epi64(test_vec[3].a);
  b = simde_x_mm256_loadu_epi64(test_vec[3].b);
  r = simde_mm256_mask_ternarylogic_epi64(src, test_vec[3].k, a, b, INT32_C(         174));
  simde_test_x86_assert_equal_i64x4(r, simde_x_mm256_loadu_epi64(test_vec[3].r));

  src = simde_x_mm256_loadu_epi64(test_vec[4].src);
  a = simde_x_mm256_loadu_epi64(test_vec[4].a);
  b = simde_x_mm256_loadu_epi64(test_vec[4].b);
  r = simde_mm256_mask_ternarylogic_epi64(src, test_vec[4].k, a, b, INT32_C(          45));
  simde_test_x86_assert_equal_i64x4(r, simde_x_mm256_loadu_epi64(test_vec[4].r));

  src = simde_x_mm256_loadu_epi64(test_vec[5].src);
  a = simde_x_mm256_loadu_epi64(test_vec[5].a);
  b = simde_x_mm256_loadu_epi64(test_vec[5].b);
  r = simde_mm256_mask_ternarylogic_epi64(src, test_vec[5].k, a, b, INT32_C(         239));
  simde_test_x86_assert_equal_i64x4(r, simde_x_mm256_loadu_epi64(test_vec[5].r));

  src = simde_x_mm256_loadu_epi64(test_vec[6].src);
  a = simde_x_mm256_loadu_epi64(test_vec[6].a);
  b = simde_x_mm256_loadu_epi64(test_vec[6].b);
  r = simde_mm256_mask_ternarylogic_epi64(src, test_vec[6].k, a, b, INT32_C(         187));
  simde_test_x86_assert_equal_i64x4(r, simde_x_mm256_loadu_epi64(test_vec[6].r));

  src = simde_x_mm256_loadu_epi64(test_vec[7].src);
  a = simde_x_mm256_loadu_epi64(test_vec[7].a);
  b = simde_x_mm256_loadu_epi64(test_vec[7].b);
  r = simde_mm256_mask_ternarylogic_epi64(src, test_vec[7].k, a, b, INT32_C(         214));
  simde_test_x86_assert_equal_i64x4(r, simde_x_mm256_loadu_epi64(test_vec[7].r));

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256i src = simde_test_x86_random_i64x4();
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256i a = simde_test_x86_random_i64x4();
    simde__m256i b = simde_test_x86_random_i64x4();
    int imm8 = simde_test_codegen_random_i32() & 255;
    simde__m256i r;
    SIMDE_CONSTIFY_256_(simde_mm256_mask_ternarylogic_epi64, r, simde_mm256_setzero_si256(), imm8, src, k, a, b);

    simde_test_x86_write_i64x4(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_maskz_ternarylogic_epi64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const int64_t a[4];
    const int64_t b[4];
    const int64_t c[4];
    const int imm8;
    const int64_t r[4];
  } test_vec[] = {
    { UINT8_C( 72),
      { -INT64_C( 8086421176715316345), -INT64_C( 3492236513019396846), -INT64_C( 4355015038985295879), -INT64_C( 4031202970084709829) },
      {  INT64_C( 1266956249381649726),  INT64_C( 8633818841303181726), -INT64_C( 5166649679713100381),  INT64_C( 7949853006877418825) },
      {  INT64_C( 7808126635570670923),  INT64_C( 8028017955926069107), -INT64_C( 2156585846110144036),  INT64_C( 7694330828774281513) },
       INT32_C(         110),
      {  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C( 2798368417629238624) } },
    { UINT8_C( 69),
      {  INT64_C( 6281300027448535312), -INT64_C( 2961804420931347950), -INT64_C(  697678382241953888), -INT64_C( 9177877065940813024) },
      {  INT64_C( 1565574825846462795),  INT64_C( 2093125426122714788), -INT64_C( 8847145111204721651), -INT64_C( 8553881336033469093) },
      { -INT64_C( 2741663902618342693), -INT64_C( 6399865097416649579),  INT64_C( 8724072942795390504),  INT64_C( 5946878474689180863) },
       INT32_C(         184),
      {  INT64_C( 6031343651046336603),  INT64_C(                   0),  INT64_C( 8309555915103326120),  INT64_C(                   0) } },
    { UINT8_C( 27),
      { -INT64_C( 1075864613872941789), -INT64_C( 4211526859942676239), -INT64_C( 2872308880098720072), -INT64_C( 3992022544452389622) },
      { -INT64_C(  213832969440245438),  INT64_C( 9183115375689933064), -INT64_C( 9141375444851035135),  INT64_C( 8156467729553929156) },
      { -INT64_C( 3968919488303697695),  INT64_C( 6050836042719910065),  INT64_C( 4021927168243016920),  INT64_C( 5194287988315574132) },
       INT32_C(          65),
      {  INT64_C( 3676183206126682910),  INT64_C(  288793910279939590),  INT64_C(                   0),  INT64_C(  450933977735245825) } },
    { UINT8_C( 46),
      {  INT64_C( 2363079450546981153),  INT64_C( 9216414041473818448), -INT64_C( 8120667706904863209), -INT64_C( 1334805139163146579) },
      {  INT64_C(  213975626504624539),  INT64_C( 5804399089604358480), -INT64_C( 4194113388357975939),  INT64_C(  636003077493660442) },
      { -INT64_C( 4929233314841085469), -INT64_C( 1562091094545985847),  INT64_C( 2788836532598180054),  INT64_C( 3459291514781090700) },
       INT32_C(          24),
      {  INT64_C(                   0),  INT64_C(  369314412810534912),  INT64_C(  614182393649337920), -INT64_C( 4240129696328579807) } },
    { UINT8_C(185),
      {  INT64_C( 6762301107411828316), -INT64_C( 2851866086902349097),  INT64_C( 9144099033477059285),  INT64_C( 4033002995277305438) },
      { -INT64_C( 2901309917910369448), -INT64_C( 1730328862799696068),  INT64_C( 1969030427591073845),  INT64_C( 6669358276781206140) },
      { -INT64_C( 1682525830984814130), -INT64_C( 5377570082194137754), -INT64_C( 4521370736827637912), -INT64_C( 5032870522613359929) },
       INT32_C(         215),
      {  INT64_C( 8636647330551889659),  INT64_C(                   0),  INT64_C(                   0), -INT64_C( 3037115876089829379) } },
    { UINT8_C( 89),
      {  INT64_C( 9190781924010847023), -INT64_C( 6288699861673492074),  INT64_C( 4238514606209727308),  INT64_C( 5016046908319305057) },
      {  INT64_C( 3095623944302058751),  INT64_C( 3788190192987266078), -INT64_C( 7015502950795967787),  INT64_C( 5248239795198604410) },
      {  INT64_C( 2420601251554076378),  INT64_C( 7399025585454528401),  INT64_C( 3421172992360564896), -INT64_C( 5424422085252391897) },
       INT32_C(         186),
      {  INT64_C( 8475693579073693658),  INT64_C(                   0),  INT64_C(                   0), -INT64_C( 5352364473984262873) } },
    { UINT8_C( 44),
      { -INT64_C( 8610540629866455111),  INT64_C( 2981952189714982884), -INT64_C( 1822339016397122945),  INT64_C( 4907901649057507705) },
      { -INT64_C(  814952451572180675),  INT64_C( 6736545966253529244),  INT64_C(  562367826023206294),  INT64_C(  659237265670106711) },
      { -INT64_C( 5984474595545031955),  INT64_C( 3311127141562684345),  INT64_C( 8205525651014626378), -INT64_C( 2871754041462565296) },
       INT32_C(         213),
      {  INT64_C(                   0),  INT64_C(                   0), -INT64_C( 8167878369657302089),  INT64_C( 2872898117671021055) } },
    { UINT8_C( 54),
      {  INT64_C(  932956027394953415),  INT64_C( 1711137191366107257), -INT64_C(   13928038237982451),  INT64_C( 4843262391524566698) },
      {  INT64_C( 2731030395618207305),  INT64_C( 8718276649697361073), -INT64_C( 7764157472484596293),  INT64_C( 1698361517614044369) },
      {  INT64_C( 8197350394522775536), -INT64_C( 3173255328043660013),  INT64_C( 5708404331075818426), -INT64_C( 8697525553384797080) },
       INT32_C(          93),
      {  INT64_C(                   0),  INT64_C( 7802955754677829356), -INT64_C( 5708400577273336585),  INT64_C(                   0) } },
  };

  simde__m256i a, b, c, r;

  a = simde_x_mm256_loadu_epi64(test_vec[0].a);
  b = simde_x_mm256_loadu_epi64(test_vec[0].b);
  c = simde_x_mm256_loadu_epi64(test_vec[0].c);
  r = simde_mm256_maskz_ternarylogic_epi64(test_vec[0].k, a, b, c, INT32_C(         110));
  simde_test_x86_assert_equal_i64x4(r, simde_x_mm256_loadu_epi64(test_vec[0].r));

  a = simde_x_mm256_loadu_epi64(test_vec[1].a);
  b = simde_x_mm256_loadu_epi64(test_vec[1].b);
  c = simde_x_mm256_loadu_epi64(test_vec[1].c);
  r = simde_mm256_maskz_ternarylogic_epi64(test_vec[1].k, a, b, c, INT32_C(         184));
  simde_test_x86_assert_equal_i64x4(r, simde_x_mm256_loadu_epi64(test_vec[1].r));

  a = simde_x_mm256_loadu_epi64(test_vec[2].a);
  b = simde_x_mm256_loadu_epi64(test_vec[2].b);
  c = simde_x_mm256_loadu_epi64(test_vec[2].c);
  r = simde_mm256_maskz_ternarylogic_epi64(test_vec[2].k, a, b, c, INT32_C(          65));
  simde_test_x86_assert_equal_i64x4(r, simde_x_mm256_loadu_epi64(test_vec[2].r));

  a = simde_x_mm256_loadu_epi64(test_vec[3].a);
  b = simde_x_mm256_loadu_epi64(test_vec[3].b);
  c = simde_x_mm256_loadu_epi64(test_vec[3].c);
  r = simde_mm256_maskz_ternarylogic_epi64(test_vec[3].k, a, b, c, INT32_C(          24));
  simde_test_x86_assert_equal_i64x4(r, simde_x_mm256_loadu_epi64(test_vec[3].r));

  a = simde_x_mm256_loadu_epi64(test_vec[4].a);
  b = simde_x_mm256_loadu_epi64(test_vec[4].b);
  c = simde_x_mm256_loadu_epi64(test_vec[4].c);
  r = simde_mm256_maskz_ternarylogic_epi64(test_vec[4].k, a, b, c, INT32_C(         215));
  simde_test_x86_assert_equal_i64x4(r, simde_x_mm256_loadu_epi64(test_vec[4].r));

  a = simde_x_mm256_loadu_epi64(test_vec[5].a);
  b = simde_x_mm256_loadu_epi64(test_vec[5].b);
  c = simde_x_mm256_loadu_epi64(test_vec[5].c);
  r = simde_mm256_maskz_ternarylogic_epi64(test_vec[5].k, a, b, c, INT32_C(         186));
  simde_test_x86_assert_equal_i64x4(r, simde_x_mm256_loadu_epi64(test_vec[5].r));

  a = simde_x_mm256_loadu_epi64(test_vec[6].a);
  b = simde_x_mm256_loadu_epi64(test_vec[6].b);
  c = simde_x_mm256_loadu_epi64(test_vec[6].c);
  r = simde_mm256_maskz_ternarylogic_epi64(test_vec[6].k, a, b, c, INT32_C(         213));
  simde_test_x86_assert_equal_i64x4(r, simde_x_mm256_loadu_epi64(test_vec[6].r));

  a = simde_x_mm256_loadu_epi64(test_vec[7].a);
  b = simde_x_mm256_loadu_epi64(test_vec[7].b);
  c = simde_x_mm256_loadu_epi64(test_vec[7].c);
  r = simde_mm256_maskz_ternarylogic_epi64(test_vec[7].k, a, b, c, INT32_C(          93));
  simde_test_x86_assert_equal_i64x4(r, simde_x_mm256_loadu_epi64(test_vec[7].r));

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256i a = simde_test_x86_random_i64x4();
    simde__m256i b = simde_test_x86_random_i64x4();
    simde__m256i c = simde_test_x86_random_i64x4();
    int imm8 = simde_test_codegen_random_i32() & 255;
    simde__m256i r;
    SIMDE_CONSTIFY_256_(simde_mm256_maskz_ternarylogic_epi64, r, simde_mm256_setzero_si256(), imm8, k, a, b, c);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x4(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_ternarylogic_epi64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int64_t a[8];
    const int64_t b[8];
    const int64_t c[8];
    const int imm8;
    const int64_t r[8];
  } test_vec[] = {
    { { -INT64_C( 2741766021644581929),  INT64_C( 1635423456298325696), -INT64_C( 6113626840324263533), -INT64_C( 6605856180556407916),
         INT64_C(  142151735707956939), -INT64_C( 4761803260812330532), -INT64_C( 5417379413892130978), -INT64_C( 9086117018539823499) },
      { -INT64_C( 2533386936980997482), -INT64_C( 2415447272890248557), -INT64_C(  322054073307829070),  INT64_C(  755238546859545667),
         INT64_C( 5403115270319381535), -INT64_C(  438677346580976502),  INT64_C(  427371111425830253),  INT64_C( 8117029493844945959) },
      { -INT64_C( 3992287974236650089), -INT64_C( 8252922043892064457), -INT64_C( 4796212010838637656), -INT64_C( 9052800490515435621),
        -INT64_C( 5870327250732127101), -INT64_C( 4632897701603943673),  INT64_C( 4412289183119914215),  INT64_C( 1474233513953367049) },
       INT32_C(         115),
      {  INT64_C( 3705167265029556073),  INT64_C( 3712484517476265452),  INT64_C(  466169263799907167), -INT64_C(  754675579457520708),
        -INT64_C( 5371308597430979608),  INT64_C(  458944648710976509), -INT64_C(  373325716853156966), -INT64_C( 8080965512449360900) } },
    { { -INT64_C( 3468960591352603219),  INT64_C( 7408341961562558314),  INT64_C( 3480664171331390289), -INT64_C( 5281849312953384108),
         INT64_C( 9006994823699909751), -INT64_C( 7638213525033284139), -INT64_C( 4289611092617878872),  INT64_C( 5674042773327363328) },
      {  INT64_C( 4907654137304197516),  INT64_C( 3451125683896314122),  INT64_C( 1275624880275379327),  INT64_C(  851699846704873643),
        -INT64_C( 2903478373597950207), -INT64_C( 1341215696077024594),  INT64_C( 8359121576085215967), -INT64_C(  910914656074851632) },
      {  INT64_C( 8699574364890400023), -INT64_C( 3745287429604711766),  INT64_C( 4766705555940893418), -INT64_C(  306827632684425769),
        -INT64_C( 2074862856026775054), -INT64_C( 2722986792600215427), -INT64_C( 8747763235537685788),  INT64_C(  770131035564288976) },
       INT32_C(          47),
      {  INT64_C( 4081450690967742035), -INT64_C( 2796092713740438859), -INT64_C( 3479537163046160722), -INT64_C(  473751009618149889),
        -INT64_C( 6701149546739289094),  INT64_C( 8796764529321669243), -INT64_C( 4926969123372434057), -INT64_C( 5052537228657204225) } },
    { { -INT64_C( 3813908029489022421), -INT64_C( 1620677690461435832),  INT64_C( 6803743072014244838), -INT64_C( 2925881062386557746),
         INT64_C( 4525715161360609320), -INT64_C( 8287487916722457639), -INT64_C(  455516486257972472),  INT64_C( 7876051672952608458) },
      {  INT64_C( 3909193045751417867), -INT64_C( 6853557687325971535), -INT64_C( 7001516508112279888),  INT64_C( 3703191617882344627),
        -INT64_C( 4269283724258585555), -INT64_C(  118783201587295968), -INT64_C( 7451292556675364827),  INT64_C( 4167786840298924924) },
      { -INT64_C( 6800572318545146935), -INT64_C( 2316904393173451892), -INT64_C( 2343719656288111621), -INT64_C( 4080443789271758566),
         INT64_C( 3568894510004052580), -INT64_C( 8100036651913584131), -INT64_C(  587461512278282602),  INT64_C( 1781310769206221811) },
       INT32_C(         158),
      {  INT64_C( 8993120040357740009), -INT64_C( 7567800438100132875), -INT64_C( 6928999193946575171),  INT64_C( 2548570608539457911),
        -INT64_C( 3780237241378912667), -INT64_C(   57434653161972956), -INT64_C( 7569718815106773569),  INT64_C( 6679955336800759669) } },
    { { -INT64_C(  409406012459285091),  INT64_C( 3671271893426104162), -INT64_C( 2681534970489877532),  INT64_C( 8765114129103094210),
        -INT64_C(  516395983180720267),  INT64_C( 4454874055026237259),  INT64_C(  265674177855683503),  INT64_C(  555357354181501279) },
      {  INT64_C( 8695527486976673821),  INT64_C( 3507718625955519767), -INT64_C(  131531693436321049), -INT64_C( 5480898790066319530),
        -INT64_C( 6747215175177743689),  INT64_C( 5215942842132952752),  INT64_C( 8223745663741028482),  INT64_C(  105353321943554604) },
      { -INT64_C( 6896626277988049636), -INT64_C( 6889886080803119688), -INT64_C( 7121067936998829155), -INT64_C( 1330860073280371139),
         INT64_C( 7513093449312398770), -INT64_C( 1731101573766834885), -INT64_C( 2682511928154014792), -INT64_C( 5975739069494123181) },
       INT32_C(          85),
      {  INT64_C( 6896626277988049635),  INT64_C( 6889886080803119687),  INT64_C( 7121067936998829154),  INT64_C( 1330860073280371138),
        -INT64_C( 7513093449312398771),  INT64_C( 1731101573766834884),  INT64_C( 2682511928154014791),  INT64_C( 5975739069494123180) } },
    { { -INT64_C( 1001787409044761980),  INT64_C( 7688906582278148563), -INT64_C( 7367988364726470328), -INT64_C(  366879031778946930),
         INT64_C( 1784219595393553704),  INT64_C( 6852885542257007843), -INT64_C( 7923879016137007407),  INT64_C(  935445680979529355) },
      {  INT64_C( 7642782870185751731), -INT64_C( 2543913616284142789), -INT64_C(  997454513582658158), -INT64_C( 5795307002109124958),
         INT64_C( 5229724859468574371),  INT64_C( 8381846387731115371), -INT64_C( 7758800621221011975), -INT64_C( 2847210417819072559) },
      {  INT64_C( 5075721548548154395),  INT64_C( 5879465080973429571), -INT64_C( 6399327176189893716),  INT64_C( 1466749583088700492),
         INT64_C( 3834443391676800020), -INT64_C( 5953211146023865416),  INT64_C( 7283019991732654997), -INT64_C( 8370430879106365752) },
       INT32_C(         158),
      { -INT64_C( 2415911856516159937), -INT64_C(  603968798105752661), -INT64_C( 1250043086474577930),  INT64_C( 4986307204613213792),
         INT64_C( 7311573908164407199), -INT64_C( 6455371340194454728),  INT64_C( 7447816877469520317), -INT64_C( 2353777628222418990) } },
    { { -INT64_C( 6446587699837685312),  INT64_C( 1517887886661511696),  INT64_C( 2280336164331856411),  INT64_C( 5679361898008181667),
        -INT64_C( 4242020637905283370),  INT64_C( 3336458221415724090), -INT64_C( 3718365628938991715),  INT64_C(  724760908178198321) },
      {  INT64_C( 6984421279940334964),  INT64_C( 8096598925287905307),  INT64_C( 6170242809492565420),  INT64_C(   29593958335491626),
        -INT64_C( 5728835371279978760), -INT64_C( 6290900874371917970), -INT64_C( 5899399381668435801),  INT64_C( 5862409466087814862) },
      {  INT64_C(  696351066294355044),  INT64_C( 7614176025920571142),  INT64_C( 1627863561956239461),  INT64_C( 9166737407921398923),
        -INT64_C( 7209380551210785201), -INT64_C( 6929835610377208407), -INT64_C( 1599306325986637712),  INT64_C( 6439307486943919812) },
       INT32_C(         170),
      {  INT64_C(  696351066294355044),  INT64_C( 7614176025920571142),  INT64_C( 1627863561956239461),  INT64_C( 9166737407921398923),
        -INT64_C( 7209380551210785201), -INT64_C( 6929835610377208407), -INT64_C( 1599306325986637712),  INT64_C( 6439307486943919812) } },
    { { -INT64_C( 5905213668574218504),  INT64_C( 5181063618817286334), -INT64_C(  173389737909766924), -INT64_C( 4401254015559076862),
        -INT64_C(  292047621677857328),  INT64_C(  684846297398198097), -INT64_C( 5569729323130048060),  INT64_C( 8492182120282655565) },
      { -INT64_C(   51883006079910384),  INT64_C( 4974712326624735724),  INT64_C( 8128629141818690412), -INT64_C( 8586285895386649156),
         INT64_C( 2976347453379613088), -INT64_C( 5885303929244579955), -INT64_C( 4714538724962447106),  INT64_C( 2073616791440988870) },
      {  INT64_C( 4895335514622368392),  INT64_C( 5418012099749157184),  INT64_C( 6464635326113381109),  INT64_C( 6175382651631293978),
         INT64_C( 1725170954203176695), -INT64_C( 2469438346005691614),  INT64_C( 4661660086120556485), -INT64_C( 7168733739783600031) },
       INT32_C(         168),
      {  INT64_C( 4850299518348565128),  INT64_C( 4837047728491008320),  INT64_C( 6455628125734566644),  INT64_C( 4662167657499776026),
         INT64_C( 1436657167654458608), -INT64_C( 8245525493088386304),  INT64_C(   49689275792433604),  INT64_C( 2054356822086060097) } },
    { {  INT64_C( 7437748110003420327),  INT64_C( 4618469016259064571), -INT64_C( 5317811004376036956), -INT64_C(  357863183969241375),
        -INT64_C( 3837069290507034663), -INT64_C( 4518902505491790865),  INT64_C(  158463958645721451), -INT64_C(  360125096346745423) },
      { -INT64_C( 5634826938576813005),  INT64_C( 7418558859313829909),  INT64_C( 7417452457403530188),  INT64_C( 4951544034941959322),
         INT64_C( 3576443168625199664),  INT64_C( 3228333674674281580),  INT64_C( 6786653904245993235),  INT64_C( 3952701449189366405) },
      { -INT64_C( 6761651032391474725), -INT64_C(  526121925164298970),  INT64_C( 6532734958862125957),  INT64_C( 8126405317072307082),
        -INT64_C( 2394911460617097749),  INT64_C( 2880639796737526813),  INT64_C( 3751809285084003297), -INT64_C( 5196719884322209315) },
       INT32_C(         120),
      { -INT64_C( 4093435066157024076),  INT64_C( 2353161564821715711), -INT64_C(  823223578693451232), -INT64_C( 4931767854443596181),
        -INT64_C( 2720757072969623559), -INT64_C( 1909048920614481949),  INT64_C( 1599889070192222826), -INT64_C( 3620871946603035340) } },
  };

  simde__m512i a, b, c, r;

  a = simde_mm512_loadu_epi64(test_vec[0].a);
  b = simde_mm512_loadu_epi64(test_vec[0].b);
  c = simde_mm512_loadu_epi64(test_vec[0].c);
  r = simde_mm512_ternarylogic_epi64(a, b, c, INT32_C(         115));
  simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[0].r));

  a = simde_mm512_loadu_epi64(test_vec[1].a);
  b = simde_mm512_loadu_epi64(test_vec[1].b);
  c = simde_mm512_loadu_epi64(test_vec[1].c);
  r = simde_mm512_ternarylogic_epi64(a, b, c, INT32_C(          47));
  simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[1].r));

  a = simde_mm512_loadu_epi64(test_vec[2].a);
  b = simde_mm512_loadu_epi64(test_vec[2].b);
  c = simde_mm512_loadu_epi64(test_vec[2].c);
  r = simde_mm512_ternarylogic_epi64(a, b, c, INT32_C(         158));
  simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[2].r));

  a = simde_mm512_loadu_epi64(test_vec[3].a);
  b = simde_mm512_loadu_epi64(test_vec[3].b);
  c = simde_mm512_loadu_epi64(test_vec[3].c);
  r = simde_mm512_ternarylogic_epi64(a, b, c, INT32_C(          85));
  simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[3].r));

  a = simde_mm512_loadu_epi64(test_vec[4].a);
  b = simde_mm512_loadu_epi64(test_vec[4].b);
  c = simde_mm512_loadu_epi64(test_vec[4].c);
  r = simde_mm512_ternarylogic_epi64(a, b, c, INT32_C(         158));
  simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[4].r));

  a = simde_mm512_loadu_epi64(test_vec[5].a);
  b = simde_mm512_loadu_epi64(test_vec[5].b);
  c = simde_mm512_loadu_epi64(test_vec[5].c);
  r = simde_mm512_ternarylogic_epi64(a, b, c, INT32_C(         170));
  simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[5].r));

  a = simde_mm512_loadu_epi64(test_vec[6].a);
  b = simde_mm512_loadu_epi64(test_vec[6].b);
  c = simde_mm512_loadu_epi64(test_vec[6].c);
  r = simde_mm512_ternarylogic_epi64(a, b, c, INT32_C(         168));
  simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[6].r));

  a = simde_mm512_loadu_epi64(test_vec[7].a);
  b = simde_mm512_loadu_epi64(test_vec[7].b);
  c = simde_mm512_loadu_epi64(test_vec[7].c);
  r = simde_mm512_ternarylogic_epi64(a, b, c, INT32_C(         120));
  simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[7].r));

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512i a = simde_test_x86_random_i64x8();
    simde__m512i b = simde_test_x86_random_i64x8();
    simde__m512i c = simde_test_x86_random_i64x8();
    int imm8 = simde_test_codegen_random_i32() & 255;
    simde__m512i r;
    SIMDE_CONSTIFY_256_(simde_mm512_ternarylogic_epi64, r, simde_mm512_setzero_si512(), imm8, a, b, c);

    simde_test_x86_write_i64x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x8(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_mask_ternarylogic_epi64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int64_t src[8];
    const simde__mmask8 k;
    const int64_t a[8];
    const int64_t b[8];
    const int imm8;
    const int64_t r[8];
  } test_vec[] = {
    { {  INT64_C(  718730306882739161),  INT64_C( 6422030467921474695), -INT64_C(  140928586053963588),  INT64_C( 1118174967217122525),
        -INT64_C( 8387110965241015767),  INT64_C( 3097372009625340915), -INT64_C( 5083209533602100668), -INT64_C( 2233622996943230533) },
      UINT8_C( 37),
      { -INT64_C( 2812019628108647930),  INT64_C( 2449800519297178535),  INT64_C( 1351000624656708916), -INT64_C( 5296607337832075066),
         INT64_C(   72537368354858525), -INT64_C( 1438412203131910320), -INT64_C( 8922563530713987280), -INT64_C( 4700249888777177505) },
      { -INT64_C( 8836650478429831166),  INT64_C(  492429295854819888), -INT64_C( 3188747048574794372), -INT64_C(  387124880553632447),
        -INT64_C( 6781941164869777369),  INT64_C( 4659360583358500558),  INT64_C( 6227134769901848868),  INT64_C( 2002652629808205271) },
       INT32_C(          97),
      {  INT64_C( 3144168541685388832),  INT64_C( 6422030467921474695), -INT64_C( 4593583588716299765),  INT64_C( 1118174967217122525),
        -INT64_C( 8387110965241015767),  INT64_C( 4152882262061693330), -INT64_C( 5083209533602100668), -INT64_C( 2233622996943230533) } },
    { {  INT64_C( 7730144706871646677), -INT64_C( 3668139318323711908), -INT64_C( 4321101793097186464), -INT64_C( 4005854065314442699),
         INT64_C( 3874418226023357361), -INT64_C(  781147394464649310), -INT64_C( 2456936075463144366), -INT64_C( 3403354487976114424) },
      UINT8_C(182),
      {  INT64_C( 6666389498920642863),  INT64_C( 6024662945029545595),  INT64_C( 7805539308625706516),  INT64_C( 4745768236560895307),
        -INT64_C( 5994389847708373883), -INT64_C( 4837268800955629436), -INT64_C(  261111257060943537), -INT64_C( 3748966010600625243) },
      {  INT64_C( 4992255307846392427),  INT64_C( 2103655802233437645),  INT64_C( 3762319398683096968), -INT64_C( 4364301019028694692),
        -INT64_C( 8717940037454418690),  INT64_C(  851230373256680676), -INT64_C( 5753493298936946076), -INT64_C(  796923870978042923) },
       INT32_C(         110),
      {  INT64_C( 7730144706871646677),  INT64_C( 6821767953582780343),  INT64_C( 8680311353060801948), -INT64_C( 4005854065314442699),
        -INT64_C( 6066623949930896257), -INT64_C( 4621048193637313436), -INT64_C( 2456936075463144366),  INT64_C( 4555460226256599285) } },
    { {  INT64_C(  976624207560357622), -INT64_C( 7841226271243018537),  INT64_C( 6907561309135656666),  INT64_C( 1291696483998157912),
         INT64_C( 2185786536936381629), -INT64_C( 6364843233916653865), -INT64_C( 2475234297672896802), -INT64_C( 4670918904080238080) },
      UINT8_C( 44),
      { -INT64_C( 3789056309698820327),  INT64_C( 1968142497294615018),  INT64_C( 4092220920060483478),  INT64_C( 3160956372145333536),
        -INT64_C( 3808030011529736192), -INT64_C( 7642169863208779863),  INT64_C( 3358604563901813030), -INT64_C( 3508942036350872049) },
      { -INT64_C( 2542190507179898101), -INT64_C( 6149766978506394093),  INT64_C( 4571341845536048948),  INT64_C( 1594465627427393409),
        -INT64_C( 5491934545261212487),  INT64_C( 6043668101961448368),  INT64_C( 1937399521660497523), -INT64_C( 6091807948337888171) },
       INT32_C(         216),
      {  INT64_C(  976624207560357622), -INT64_C( 7841226271243018537),  INT64_C( 8704399773714700254),  INT64_C(  274061053928981848),
         INT64_C( 2185786536936381629), -INT64_C( 5336329193680781337), -INT64_C( 2475234297672896802), -INT64_C( 4670918904080238080) } },
    { { -INT64_C(  497382931624665038),  INT64_C( 9112157422747449181), -INT64_C( 8098592960824125208), -INT64_C( 4836353032906468720),
         INT64_C( 6487074610756914482),  INT64_C( 2095193304125363119),  INT64_C( 4693866474913836279),  INT64_C( 7011976181279513864) },
      UINT8_C(152),
      { -INT64_C( 4011035505006842130), -INT64_C( 6290936056695101157), -INT64_C( 4074743460293687692),  INT64_C( 4857229319408584004),
         INT64_C(  721489558237740742), -INT64_C( 8157013870905065433),  INT64_C(  283283394836112830),  INT64_C(  218771193418999153) },
      {  INT64_C( 6282875729742918201),  INT64_C( 3237041871024551491), -INT64_C( 4453987115049163411),  INT64_C( 8604005310275257127),
         INT64_C( 3173860064572188291),  INT64_C( 4350888243538527943),  INT64_C( 2120801759254918234),  INT64_C(  816252731491743389) },
       INT32_C(         143),
      { -INT64_C(  497382931624665038),  INT64_C( 9112157422747449181), -INT64_C( 8098592960824125208),  INT64_C( 4863392223930477935),
        -INT64_C( 5910032319855855921),  INT64_C( 2095193304125363119),  INT64_C( 4693866474913836279), -INT64_C( 6939627180111042825) } },
    { {  INT64_C( 2287316584192330434), -INT64_C( 3843324387904512093), -INT64_C( 7577753809944307875), -INT64_C( 2496577370540922542),
        -INT64_C( 3415376490132930774),  INT64_C( 1649294624945009989), -INT64_C( 8704359437322564721),  INT64_C( 6919996560095434000) },
      UINT8_C(195),
      {  INT64_C( 7699678124202580847), -INT64_C( 6731129001653046385),  INT64_C( 4341855313072698442), -INT64_C( 1995144707592524600),
        -INT64_C( 8175066868324155475),  INT64_C( 3728748391926443846), -INT64_C( 4898606924424767904), -INT64_C(  762067899169343982) },
      {  INT64_C( 9179641409288267222), -INT64_C( 8760245480415495598), -INT64_C( 8457107570546584847),  INT64_C( 6414390866346175431),
         INT64_C( 1160965250828147555),  INT64_C(  376534442909087885), -INT64_C( 6877683997511809142), -INT64_C( 9199530097941438599) },
       INT32_C(         207),
      { -INT64_C( 1523393151627427969), -INT64_C( 5199902753221512225), -INT64_C( 7577753809944307875), -INT64_C( 2496577370540922542),
        -INT64_C( 3415376490132930774),  INT64_C( 1649294624945009989), -INT64_C(  230599478880586128), -INT64_C(      70597050728705) } },
    { {  INT64_C(  385314992198400279), -INT64_C( 1067364002984914526),  INT64_C( 8717069317592693892), -INT64_C( 1706277318123041292),
         INT64_C( 8954815060133081166), -INT64_C( 3783068459631882122),  INT64_C( 5000898093395808403), -INT64_C( 4339117683438428401) },
      UINT8_C( 76),
      { -INT64_C( 7372495633902075051), -INT64_C( 3551743902289478070),  INT64_C( 7585860617372673140),  INT64_C( 4906005420346058350),
         INT64_C( 2919790364598287268), -INT64_C( 8793560773238823573), -INT64_C( 1722905606505097821),  INT64_C( 4205174124537050408) },
      {  INT64_C( 8144949071630031106), -INT64_C(  745187060165815790), -INT64_C( 8140332853668649819), -INT64_C( 9042943826818844240),
         INT64_C( 7373072452750059739),  INT64_C( 2378800532288039868),  INT64_C( 1192407582749271702),  INT64_C( 1081946055518925313) },
       INT32_C(         128),
      {  INT64_C(  385314992198400279), -INT64_C( 1067364002984914526),  INT64_C(  576460761228977156),  INT64_C(        550837944352),
         INT64_C( 8954815060133081166), -INT64_C( 3783068459631882122),  INT64_C(    1126177670430850), -INT64_C( 4339117683438428401) } },
    { { -INT64_C( 6225166355692567856), -INT64_C( 6590442715638751498),  INT64_C( 9067166929578694227),  INT64_C( 1096764216193112292),
         INT64_C( 3357212764872143807), -INT64_C( 4630468511276506667),  INT64_C( 7071188520564650587), -INT64_C( 1581045859015545407) },
      UINT8_C(114),
      { -INT64_C( 3407296997803501654), -INT64_C(   56861734090256492), -INT64_C( 6288748036130678513),  INT64_C( 8149471091410253991),
         INT64_C( 3517884824588370836),  INT64_C( 1901996835334655961),  INT64_C( 7763303900690703129), -INT64_C( 2324937904271290748) },
      { -INT64_C(  956535424075886612),  INT64_C( 2155180245741257667),  INT64_C( 5391070190319565729), -INT64_C(  601984768949231237),
        -INT64_C(  113654062481701023),  INT64_C( 2530095565405734140), -INT64_C( 5278121755158229585),  INT64_C(  664882001072641593) },
       INT32_C(         169),
      { -INT64_C( 6225166355692567856),  INT64_C( 2137166045337215946),  INT64_C( 9067166929578694227),  INT64_C( 1096764216193112292),
         INT64_C( 4559041918870194977),  INT64_C( 7142161531668026590),  INT64_C( 2486633761578696971), -INT64_C( 1581045859015545407) } },
    { {  INT64_C( 4030350812963336434), -INT64_C( 7887805879446533534),  INT64_C( 5095477312745916474), -INT64_C( 7100816879130709529),
         INT64_C( 7399548347407423172),  INT64_C( 2769433313167280772),  INT64_C( 7146738156075333449),  INT64_C( 1623942746504134209) },
      UINT8_C(189),
      {  INT64_C( 5409993310133653525),  INT64_C( 1723293572242337952),  INT64_C( 9045752527363232247),  INT64_C( 1373570391356699882),
        -INT64_C( 7421448427790937738), -INT64_C( 8206081239942547033), -INT64_C( 7821804048040414730), -INT64_C( 6997199464869575981) },
      { -INT64_C( 1848632819554351163), -INT64_C( 5929820453103365489), -INT64_C( 4830086508178142276), -INT64_C( 7557195405573890728),
         INT64_C( 6493818796754957561), -INT64_C( 3268429056806220992), -INT64_C( 5447614624218790208),  INT64_C( 6878495707158082572) },
       INT32_C(         199),
      { -INT64_C( 8429197766137438440), -INT64_C( 7887805879446533534), -INT64_C( 4196809912439441805),  INT64_C( 8179888972556827378),
        -INT64_C( 9129022721962608305),  INT64_C( 6890185844817132799),  INT64_C( 7146738156075333449), -INT64_C(  607162906120174593) } },
  };

  simde__m512i src, a, b, r;

  src = simde_mm512_loadu_epi64(test_vec[0].src);
  a = simde_mm512_loadu_epi64(test_vec[0].a);
  b = simde_mm512_loadu_epi64(test_vec[0].b);
  r = simde_mm512_mask_ternarylogic_epi64(src, test_vec[0].k, a, b, INT32_C(          97));
  simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[0].r));

  src = simde_mm512_loadu_epi64(test_vec[1].src);
  a = simde_mm512_loadu_epi64(test_vec[1].a);
  b = simde_mm512_loadu_epi64(test_vec[1].b);
  r = simde_mm512_mask_ternarylogic_epi64(src, test_vec[1].k, a, b, INT32_C(         110));
  simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[1].r));

  src = simde_mm512_loadu_epi64(test_vec[2].src);
  a = simde_mm512_loadu_epi64(test_vec[2].a);
  b = simde_mm512_loadu_epi64(test_vec[2].b);
  r = simde_mm512_mask_ternarylogic_epi64(src, test_vec[2].k, a, b, INT32_C(         216));
  simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[2].r));

  src = simde_mm512_loadu_epi64(test_vec[3].src);
  a = simde_mm512_loadu_epi64(test_vec[3].a);
  b = simde_mm512_loadu_epi64(test_vec[3].b);
  r = simde_mm512_mask_ternarylogic_epi64(src, test_vec[3].k, a, b, INT32_C(         143));
  simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[3].r));

  src = simde_mm512_loadu_epi64(test_vec[4].src);
  a = simde_mm512_loadu_epi64(test_vec[4].a);
  b = simde_mm512_loadu_epi64(test_vec[4].b);
  r = simde_mm512_mask_ternarylogic_epi64(src, test_vec[4].k, a, b, INT32_C(         207));
  simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[4].r));

  src = simde_mm512_loadu_epi64(test_vec[5].src);
  a = simde_mm512_loadu_epi64(test_vec[5].a);
  b = simde_mm512_loadu_epi64(test_vec[5].b);
  r = simde_mm512_mask_ternarylogic_epi64(src, test_vec[5].k, a, b, INT32_C(         128));
  simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[5].r));

  src = simde_mm512_loadu_epi64(test_vec[6].src);
  a = simde_mm512_loadu_epi64(test_vec[6].a);
  b = simde_mm512_loadu_epi64(test_vec[6].b);
  r = simde_mm512_mask_ternarylogic_epi64(src, test_vec[6].k, a, b, INT32_C(         169));
  simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[6].r));

  src = simde_mm512_loadu_epi64(test_vec[7].src);
  a = simde_mm512_loadu_epi64(test_vec[7].a);
  b = simde_mm512_loadu_epi64(test_vec[7].b);
  r = simde_mm512_mask_ternarylogic_epi64(src, test_vec[7].k, a, b, INT32_C(         199));
  simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[7].r));

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512i src = simde_test_x86_random_i64x8();
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m512i a = simde_test_x86_random_i64x8();
    simde__m512i b = simde_test_x86_random_i64x8();
    int imm8 = simde_test_codegen_random_i32() & 255;
    simde__m512i r;
    SIMDE_CONSTIFY_256_(simde_mm512_mask_ternarylogic_epi64, r, simde_mm512_setzero_si512(), imm8, src, k, a, b);

    simde_test_x86_write_i64x8(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_maskz_ternarylogic_epi64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const int64_t a[8];
    const int64_t b[8];
    const int64_t c[8];
    const int imm8;
    const int64_t r[8];
  } test_vec[] = {
    { UINT8_C(120),
      { -INT64_C( 6712985312924472139),  INT64_C( 1221897032686545235),  INT64_C( 3588800311203768691),  INT64_C( 8769225099363036271),
         INT64_C( 7819674031371217527),  INT64_C( 7470059959922059449),  INT64_C( 3509601265054041764), -INT64_C( 5835226712989061688) },
      {  INT64_C(  651641305638780806), -INT64_C( 5738627107137580800), -INT64_C( 8212903504273790444),  INT64_C( 1403750398436208788),
         INT64_C( 2718131444188843359), -INT64_C( 4788603306880901937),  INT64_C( 4176130590637211296), -INT64_C( 8239476055710822904) },
      { -INT64_C( 1740091394078516594),  INT64_C(  700113384653386576), -INT64_C( 1519009524505097716), -INT64_C(   59067475626626957),
        -INT64_C( 5800764556624893312), -INT64_C( 7281932955593129602),  INT64_C( 4068500634977722794), -INT64_C( 7235306461237480153) },
       INT32_C(         113),
      {  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C( 7534744029819375471),
         INT64_C( 6378593066966446711),  INT64_C( 7435050957760998065), -INT64_C( 4140554792501000619),  INT64_C(                   0) } },
    { UINT8_C(213),
      { -INT64_C( 8610535965488545870), -INT64_C( 6966013742845584340),  INT64_C( 7802028292596730678), -INT64_C( 4172956602701258250),
        -INT64_C( 3252378874109400531),  INT64_C(  458719346678501462),  INT64_C( 8723322410502267966), -INT64_C( 4020922151325733544) },
      {  INT64_C( 8985238871656491834),  INT64_C(  135557430761885963), -INT64_C( 2181795517889768772),  INT64_C( 8936688958059672225),
         INT64_C( 2957753480197710698), -INT64_C( 7285725927206205922), -INT64_C( 2493707505065424647), -INT64_C( 7222893981353725692) },
      {  INT64_C( 5443223767673937731),  INT64_C( 8067936457507835774),  INT64_C( 7472128614745624729),  INT64_C( 3518280997578657031),
        -INT64_C( 5473813950152704111), -INT64_C( 2193243912643987541), -INT64_C( 2404243977433349672),  INT64_C( 5932060674910212149) },
       INT32_C(         232),
      {  INT64_C( 5224522111264849714),  INT64_C(                   0),  INT64_C( 7328013419857351356),  INT64_C(                   0),
        -INT64_C( 5760918427101730007),  INT64_C(                   0), -INT64_C( 2511193746600525576), -INT64_C( 2714860710263066348) } },
    {    UINT8_MAX,
      { -INT64_C( 1397862027838696678), -INT64_C( 7443605549250938277), -INT64_C( 7947744313254964830),  INT64_C( 3469346308861003331),
        -INT64_C(  775434310759886996), -INT64_C( 6602975231716752748),  INT64_C( 6795730746235824919), -INT64_C( 3632528714119132849) },
      { -INT64_C( 4104367839750776710),  INT64_C( 8648011214393957469),  INT64_C( 3642715979625502995),  INT64_C( 3998684911414809167),
         INT64_C( 6070946819075710022), -INT64_C( 4103985748729672911),  INT64_C( 1757675754259628623),  INT64_C( 8181431019703499926) },
      {  INT64_C( 6714913412287747812), -INT64_C( 1553183754771438347), -INT64_C( 9070389377575917762),  INT64_C( 1519789165629532540),
         INT64_C( 2431418418548769078), -INT64_C( 1690473106096083450), -INT64_C( 6768894681168238941),  INT64_C( 8952698963699033847) },
       INT32_C(          98),
      { -INT64_C( 7478120486595934562), -INT64_C( 7894225503141152600), -INT64_C( 8029355146455878100),  INT64_C( 2315210865567984435),
         INT64_C( 8484274376709016944),  INT64_C( 3206999484296340502), -INT64_C( 5020376484475722588),  INT64_C(  987458630049598049) } },
    { UINT8_C( 81),
      { -INT64_C( 5407424052743131492), -INT64_C( 2715698290034746238), -INT64_C( 7267971713607798026),  INT64_C( 1781608494038621752),
        -INT64_C( 8401650884972244935), -INT64_C( 7216732920684954061), -INT64_C( 2536482460137968907), -INT64_C( 8156866284831323848) },
      { -INT64_C( 5070587511101706483),  INT64_C( 5667095513438639462), -INT64_C( 1171698174440628932),  INT64_C(  862000616667611412),
         INT64_C( 4962899573747038111),  INT64_C( 7331565702220846871), -INT64_C( 7226022819912139759),  INT64_C( 7786155084890725379) },
      {  INT64_C(  600228830997720625), -INT64_C( 6226729411795180792), -INT64_C( 2191799605984633997), -INT64_C( 4341768479492040571),
        -INT64_C( 4028426160830197986),  INT64_C( 4182313290471936202),  INT64_C( 3110520204370934890),  INT64_C( 1997130921676705121) },
       INT32_C(         138),
      {  INT64_C(  576496486557167137),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
         INT64_C( 4618479626125135646),  INT64_C(                   0),  INT64_C( 3110370533347458058),  INT64_C(                   0) } },
    { UINT8_C(177),
      { -INT64_C( 7306284402592771517), -INT64_C( 3384088946575813401), -INT64_C( 1404797965382241161),  INT64_C(  800164950318685662),
         INT64_C( 6519375474179610323),  INT64_C( 4839056005075467853),  INT64_C( 6960394045399522043), -INT64_C( 6649032893705679130) },
      {  INT64_C( 6793674617312680057), -INT64_C( 4068478018434890374), -INT64_C( 9144546279933390538),  INT64_C( 4507234359026180377),
        -INT64_C( 8939239499432849791), -INT64_C( 5185521681304017546), -INT64_C( 6790996648631698268),  INT64_C( 6659441600320172393) },
      {  INT64_C( 9129323141585081892),  INT64_C( 8268268947829193349),  INT64_C( 2265155267067981382),  INT64_C( 3718486817957083491),
        -INT64_C( 1309402451834533810), -INT64_C( 6499905518873373556),  INT64_C( 6032258269575347680),  INT64_C(  728786805093106651) },
       INT32_C(         179),
      { -INT64_C( 4919938574008223866),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
         INT64_C( 8961776189569364350),  INT64_C( 5185805356386115213),  INT64_C(                   0), -INT64_C( 6656905541711491370) } },
    { UINT8_C(143),
      { -INT64_C( 5897616557963802572),  INT64_C( 2426355254939274304), -INT64_C( 4928091857319297060),  INT64_C( 4256053408411133443),
        -INT64_C( 2360682665373062253), -INT64_C( 3649804722638107656),  INT64_C( 4581366147129824584),  INT64_C( 2391359239567180782) },
      {  INT64_C( 6303611623348122619), -INT64_C( 6307599825738262600),  INT64_C( 6464941915946165053),  INT64_C( 5028406739252115737),
         INT64_C( 2190537658866890928),  INT64_C( 1835848916240168305),  INT64_C( 3108973657587907425), -INT64_C( 6894276628519423292) },
      { -INT64_C(  101587669704822253), -INT64_C(  215809269372527093), -INT64_C( 6736559453869862075),  INT64_C(  283730003398513761),
        -INT64_C( 4485563553193091019),  INT64_C( 2309125987971403889),  INT64_C( 2647828247315207485), -INT64_C( 6539115126200111539) },
       INT32_C(           5),
      {  INT64_C(   92474434148943304),  INT64_C(  167354740720607668),  INT64_C( 4928082726218760226), -INT64_C( 4319104805273335396),
         INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C( 6525726859505340432) } },
    { UINT8_C(207),
      { -INT64_C( 3561416956407940056),  INT64_C( 2590175797822862170), -INT64_C( 1025785471903459355), -INT64_C(  542487145823639059),
         INT64_C( 6999231569163565359),  INT64_C( 4198625154274701047),  INT64_C( 5699112235944490138), -INT64_C( 1116204681560256839) },
      {  INT64_C( 7967824827879011114),  INT64_C( 4693827954781660308), -INT64_C( 5027848962289717112), -INT64_C( 3585208744838679923),
         INT64_C( 9070413375590138618), -INT64_C( 3773864465768484680),  INT64_C( 1366542892464932666), -INT64_C(  246398349154960863) },
      { -INT64_C( 2268039428470565856), -INT64_C( 5634601860833743682), -INT64_C( 7818562921987013658), -INT64_C( 7054064744686559459),
        -INT64_C( 7671268610967893887), -INT64_C( 8052042879811991015),  INT64_C( 3309435511851724264), -INT64_C( 5371274607728048551) },
       INT32_C(         238),
      { -INT64_C( 1254412478462380246), -INT64_C( 1013345135229932354), -INT64_C( 4935946892691393554), -INT64_C( 2432242877244506211),
         INT64_C(                   0),  INT64_C(                   0),  INT64_C( 4611685560946077690), -INT64_C(  146931914208739719) } },
    { UINT8_C( 73),
      {  INT64_C( 6295454978339396585),  INT64_C( 7165677709761178931),  INT64_C( 5692995135873064583), -INT64_C(  113149551283620343),
        -INT64_C(  673270812728176546),  INT64_C(  596947410850670844), -INT64_C( 6728422264782060186),  INT64_C( 4584723663878086029) },
      {  INT64_C( 6755181058235322886),  INT64_C( 5092317596288685857), -INT64_C( 1888075490987179632), -INT64_C( 3516423135701789677),
         INT64_C( 2177869742144537722), -INT64_C( 7524271402594043025),  INT64_C( 8298319233016736492),  INT64_C( 5961247313231327265) },
      {  INT64_C( 1907668803323253598), -INT64_C( 7890309133119243550), -INT64_C( 1154609467424882649),  INT64_C( 6546709920196747696),
         INT64_C( 5813354845976266984),  INT64_C( 4224860313154557289),  INT64_C( 2933739429916932089),  INT64_C( 1041610409585447197) },
       INT32_C(         147),
      { -INT64_C( 5757390070385475919),  INT64_C(                   0),  INT64_C(                   0),  INT64_C( 7676061355142695916),
         INT64_C(                   0),  INT64_C(                   0), -INT64_C( 6034569998888939405),  INT64_C(                   0) } },
  };

  simde__m512i a, b, c, r;

  a = simde_mm512_loadu_epi64(test_vec[0].a);
  b = simde_mm512_loadu_epi64(test_vec[0].b);
  c = simde_mm512_loadu_epi64(test_vec[0].c);
  r = simde_mm512_maskz_ternarylogic_epi64(test_vec[0].k, a, b, c, INT32_C(         113));
  simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[0].r));

  a = simde_mm512_loadu_epi64(test_vec[1].a);
  b = simde_mm512_loadu_epi64(test_vec[1].b);
  c = simde_mm512_loadu_epi64(test_vec[1].c);
  r = simde_mm512_maskz_ternarylogic_epi64(test_vec[1].k, a, b, c, INT32_C(         232));
  simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[1].r));

  a = simde_mm512_loadu_epi64(test_vec[2].a);
  b = simde_mm512_loadu_epi64(test_vec[2].b);
  c = simde_mm512_loadu_epi64(test_vec[2].c);
  r = simde_mm512_maskz_ternarylogic_epi64(test_vec[2].k, a, b, c, INT32_C(          98));
  simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[2].r));

  a = simde_mm512_loadu_epi64(test_vec[3].a);
  b = simde_mm512_loadu_epi64(test_vec[3].b);
  c = simde_mm512_loadu_epi64(test_vec[3].c);
  r = simde_mm512_maskz_ternarylogic_epi64(test_vec[3].k, a, b, c, INT32_C(         138));
  simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[3].r));

  a = simde_mm512_loadu_epi64(test_vec[4].a);
  b = simde_mm512_loadu_epi64(test_vec[4].b);
  c = simde_mm512_loadu_epi64(test_vec[4].c);
  r = simde_mm512_maskz_ternarylogic_epi64(test_vec[4].k, a, b, c, INT32_C(         179));
  simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[4].r));

  a = simde_mm512_loadu_epi64(test_vec[5].a);
  b = simde_mm512_loadu_epi64(test_vec[5].b);
  c = simde_mm512_loadu_epi64(test_vec[5].c);
  r = simde_mm512_maskz_ternarylogic_epi64(test_vec[5].k, a, b, c, INT32_C(           5));
  simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[5].r));

  a = simde_mm512_loadu_epi64(test_vec[6].a);
  b = simde_mm512_loadu_epi64(test_vec[6].b);
  c = simde_mm512_loadu_epi64(test_vec[6].c);
  r = simde_mm512_maskz_ternarylogic_epi64(test_vec[6].k, a, b, c, INT32_C(         238));
  simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[6].r));

  a = simde_mm512_loadu_epi64(test_vec[7].a);
  b = simde_mm512_loadu_epi64(test_vec[7].b);
  c = simde_mm512_loadu_epi64(test_vec[7].c);
  r = simde_mm512_maskz_ternarylogic_epi64(test_vec[7].k, a, b, c, INT32_C(         147));
  simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[7].r));

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m512i a = simde_test_x86_random_i64x8();
    simde__m512i b = simde_test_x86_random_i64x8();
    simde__m512i c = simde_test_x86_random_i64x8();
    int imm8 = simde_test_codegen_random_i32() & 255;
    simde__m512i r;
    SIMDE_CONSTIFY_256_(simde_mm512_maskz_ternarylogic_epi64, r, simde_mm512_setzero_si512(), imm8, k, a, b, c);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x8(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_ternarylogic_epi32_1)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_ternarylogic_epi32_2)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_ternarylogic_epi32_3)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_ternarylogic_epi32_4)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_ternarylogic_epi32_5)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_ternarylogic_epi32_6)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_ternarylogic_epi32_7)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_ternarylogic_epi32_8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_ternarylogic_epi32_9)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_ternarylogic_epi32_10)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_ternarylogic_epi32_11)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_ternarylogic_epi32_12)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_ternarylogic_epi32_13)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_ternarylogic_epi32_14)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_ternarylogic_epi32_15)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_ternarylogic_epi32_16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_ternarylogic_epi32_17)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_ternarylogic_epi32_18)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_ternarylogic_epi32_19)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_ternarylogic_epi32_20)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_ternarylogic_epi32_21)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_ternarylogic_epi32_22)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_ternarylogic_epi32_23)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_ternarylogic_epi32_24)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_ternarylogic_epi32_25)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_ternarylogic_epi32_26)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_ternarylogic_epi32_27)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_ternarylogic_epi32_28)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_ternarylogic_epi32_29)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_ternarylogic_epi32_30)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_ternarylogic_epi32_31)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_ternarylogic_epi32_32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_ternarylogic_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_maskz_ternarylogic_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_ternarylogic_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_ternarylogic_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_maskz_ternarylogic_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_ternarylogic_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_ternarylogic_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_maskz_ternarylogic_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_ternarylogic_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_ternarylogic_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_maskz_ternarylogic_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_ternarylogic_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_ternarylogic_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_maskz_ternarylogic_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_ternarylogic_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_ternarylogic_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_maskz_ternarylogic_epi64)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/avx512/test-avx512-footer.h>
