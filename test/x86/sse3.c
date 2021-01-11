/* Copyright (c) 2017 Evan Nemerson <evan@nemerson.com>
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

#define SIMDE_TESTS_CURRENT_ISAX sse3
#include <simde/x86/sse3.h>
#include <test/x86/test-sse2.h>

static int
test_simde_x_mm_deinterleaveeven_epi16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const int16_t a[8];
    const int16_t b[8];
    const int16_t r[8];
  } test_vec[] = {
    { { -INT16_C( 21262), -INT16_C( 27496),  INT16_C(  1829),  INT16_C(  1406),  INT16_C( 23866), -INT16_C(  9078), -INT16_C( 20232), -INT16_C(  6581) },
      { -INT16_C( 22365),  INT16_C( 30750), -INT16_C( 18380),  INT16_C( 19916),  INT16_C( 20867), -INT16_C(    24), -INT16_C( 27548),  INT16_C( 22045) },
      { -INT16_C( 21262),  INT16_C(  1829),  INT16_C( 23866), -INT16_C( 20232), -INT16_C( 22365), -INT16_C( 18380),  INT16_C( 20867), -INT16_C( 27548) } },
    { { -INT16_C( 19136),  INT16_C( 26090),  INT16_C( 27069), -INT16_C(  2197), -INT16_C(  2618), -INT16_C( 16429),  INT16_C(  7845),  INT16_C( 18597) },
      { -INT16_C( 15418), -INT16_C(  1344), -INT16_C( 29317), -INT16_C(   441),  INT16_C( 12254),  INT16_C( 17150),  INT16_C(  7107),  INT16_C(   920) },
      { -INT16_C( 19136),  INT16_C( 27069), -INT16_C(  2618),  INT16_C(  7845), -INT16_C( 15418), -INT16_C( 29317),  INT16_C( 12254),  INT16_C(  7107) } },
    { { -INT16_C( 31792), -INT16_C( 29335), -INT16_C( 11028), -INT16_C( 19836),  INT16_C( 22473),  INT16_C( 28273),  INT16_C(  5749),  INT16_C( 15286) },
      {  INT16_C( 30425),  INT16_C( 21558),  INT16_C( 32003), -INT16_C(  7853),  INT16_C( 20909),  INT16_C( 28707), -INT16_C( 17300),  INT16_C( 15476) },
      { -INT16_C( 31792), -INT16_C( 11028),  INT16_C( 22473),  INT16_C(  5749),  INT16_C( 30425),  INT16_C( 32003),  INT16_C( 20909), -INT16_C( 17300) } },
    { { -INT16_C(  8897),  INT16_C( 11210),  INT16_C( 20145),  INT16_C( 31453),  INT16_C( 20390),  INT16_C(  7144), -INT16_C( 24987),  INT16_C( 16215) },
      { -INT16_C( 29420),  INT16_C(  6291), -INT16_C(  6646), -INT16_C( 18439),  INT16_C(  7479), -INT16_C( 23768), -INT16_C( 25383),  INT16_C(  6368) },
      { -INT16_C(  8897),  INT16_C( 20145),  INT16_C( 20390), -INT16_C( 24987), -INT16_C( 29420), -INT16_C(  6646),  INT16_C(  7479), -INT16_C( 25383) } },
    { { -INT16_C( 21895),  INT16_C( 10819),  INT16_C(  8440), -INT16_C( 24924), -INT16_C( 29585), -INT16_C( 10822),  INT16_C(  4394),  INT16_C( 15892) },
      { -INT16_C( 22626), -INT16_C( 22442),  INT16_C( 20622), -INT16_C( 15008), -INT16_C( 30611),  INT16_C( 18025),  INT16_C( 18724), -INT16_C( 25250) },
      { -INT16_C( 21895),  INT16_C(  8440), -INT16_C( 29585),  INT16_C(  4394), -INT16_C( 22626),  INT16_C( 20622), -INT16_C( 30611),  INT16_C( 18724) } },
    { { -INT16_C( 24077), -INT16_C(  5177),  INT16_C( 27585),  INT16_C( 12682),  INT16_C( 17655),  INT16_C(  8454),  INT16_C(  6741), -INT16_C(  3233) },
      { -INT16_C( 18751),  INT16_C( 20379), -INT16_C(  1274),  INT16_C( 29461),  INT16_C( 32387), -INT16_C( 22599),  INT16_C(  6087), -INT16_C( 17852) },
      { -INT16_C( 24077),  INT16_C( 27585),  INT16_C( 17655),  INT16_C(  6741), -INT16_C( 18751), -INT16_C(  1274),  INT16_C( 32387),  INT16_C(  6087) } },
    { {  INT16_C(  3000),  INT16_C( 31141),  INT16_C( 12150),  INT16_C( 28074), -INT16_C( 20365), -INT16_C( 14194), -INT16_C(  4406), -INT16_C( 29509) },
      {  INT16_C( 22436), -INT16_C( 21797), -INT16_C(  4014), -INT16_C( 10723), -INT16_C( 10642),  INT16_C( 13693), -INT16_C( 15635), -INT16_C( 23057) },
      {  INT16_C(  3000),  INT16_C( 12150), -INT16_C( 20365), -INT16_C(  4406),  INT16_C( 22436), -INT16_C(  4014), -INT16_C( 10642), -INT16_C( 15635) } },
    { { -INT16_C( 27187),  INT16_C( 17438), -INT16_C( 13884),  INT16_C( 14513),  INT16_C( 16505),  INT16_C( 17408), -INT16_C( 17362), -INT16_C( 11568) },
      { -INT16_C( 21741),  INT16_C( 25980), -INT16_C( 26212),  INT16_C(  2619), -INT16_C( 18065),  INT16_C( 23616),  INT16_C( 12155),  INT16_C( 18433) },
      { -INT16_C( 27187), -INT16_C( 13884),  INT16_C( 16505), -INT16_C( 17362), -INT16_C( 21741), -INT16_C( 26212), -INT16_C( 18065),  INT16_C( 12155) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_x_mm_loadu_epi16(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epi16(test_vec[i].b);
    simde__m128i r = simde_x_mm_deinterleaveeven_epi16(a, b);
    simde_test_x86_assert_equal_i16x8(r, simde_x_mm_loadu_epi16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_x_mm_deinterleaveodd_epi16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const int16_t a[8];
    const int16_t b[8];
    const int16_t r[8];
  } test_vec[] = {
    { { -INT16_C( 10387),  INT16_C( 10281),  INT16_C(  8337),  INT16_C( 25558),  INT16_C(  3361), -INT16_C( 20206),  INT16_C( 23483), -INT16_C( 23483) },
      {  INT16_C( 32228), -INT16_C( 11156), -INT16_C( 32507),  INT16_C( 22207), -INT16_C(  8391), -INT16_C( 22722), -INT16_C(  8534),  INT16_C(  6015) },
      {  INT16_C( 10281),  INT16_C( 25558), -INT16_C( 20206), -INT16_C( 23483), -INT16_C( 11156),  INT16_C( 22207), -INT16_C( 22722),  INT16_C(  6015) } },
    { { -INT16_C( 22347),  INT16_C( 17983),  INT16_C(  5833), -INT16_C(  5463), -INT16_C( 17373), -INT16_C(  8548), -INT16_C(  7913), -INT16_C(  1150) },
      { -INT16_C(  4514),  INT16_C( 25551), -INT16_C( 29073), -INT16_C( 22342), -INT16_C(  1939),  INT16_C(  6223), -INT16_C( 12330), -INT16_C( 29905) },
      {  INT16_C( 17983), -INT16_C(  5463), -INT16_C(  8548), -INT16_C(  1150),  INT16_C( 25551), -INT16_C( 22342),  INT16_C(  6223), -INT16_C( 29905) } },
    { {  INT16_C( 28535),  INT16_C( 16593),  INT16_C( 31621), -INT16_C( 22485), -INT16_C( 14537),  INT16_C( 20102),  INT16_C(  2216),  INT16_C(  1609) },
      {  INT16_C(  6646),  INT16_C( 26218),  INT16_C(  9383),  INT16_C(  5390),  INT16_C( 24092), -INT16_C(  3283),  INT16_C( 23597), -INT16_C( 23426) },
      {  INT16_C( 16593), -INT16_C( 22485),  INT16_C( 20102),  INT16_C(  1609),  INT16_C( 26218),  INT16_C(  5390), -INT16_C(  3283), -INT16_C( 23426) } },
    { {  INT16_C( 20683),  INT16_C( 20709),  INT16_C(  4299),  INT16_C(   760),  INT16_C( 32471),  INT16_C( 32592), -INT16_C( 26234),  INT16_C( 32133) },
      { -INT16_C(  4174),  INT16_C( 23267), -INT16_C(  3821),  INT16_C( 12399), -INT16_C( 25521),  INT16_C( 31779), -INT16_C( 24072), -INT16_C( 15327) },
      {  INT16_C( 20709),  INT16_C(   760),  INT16_C( 32592),  INT16_C( 32133),  INT16_C( 23267),  INT16_C( 12399),  INT16_C( 31779), -INT16_C( 15327) } },
    { {  INT16_C(  1777), -INT16_C( 17388),  INT16_C(  3350), -INT16_C(  4674),  INT16_C(  3723),  INT16_C(  4716), -INT16_C(  3672),  INT16_C( 23183) },
      {  INT16_C( 29409), -INT16_C(  2892),  INT16_C(  9059), -INT16_C( 19676),  INT16_C( 18367), -INT16_C( 18385),  INT16_C( 20713), -INT16_C(  9604) },
      { -INT16_C( 17388), -INT16_C(  4674),  INT16_C(  4716),  INT16_C( 23183), -INT16_C(  2892), -INT16_C( 19676), -INT16_C( 18385), -INT16_C(  9604) } },
    { { -INT16_C( 28586),  INT16_C( 27799),  INT16_C( 21917),  INT16_C( 10585), -INT16_C( 15004),  INT16_C(  3131), -INT16_C( 13641), -INT16_C( 26522) },
      {  INT16_C(  6972), -INT16_C( 24692), -INT16_C( 20162), -INT16_C(   430), -INT16_C( 32008), -INT16_C(  7754),  INT16_C( 13010),  INT16_C( 10684) },
      {  INT16_C( 27799),  INT16_C( 10585),  INT16_C(  3131), -INT16_C( 26522), -INT16_C( 24692), -INT16_C(   430), -INT16_C(  7754),  INT16_C( 10684) } },
    { {  INT16_C( 21442),  INT16_C( 24725), -INT16_C(  4184),  INT16_C(  3209), -INT16_C( 15180),  INT16_C( 27416),  INT16_C( 32654), -INT16_C( 13821) },
      { -INT16_C( 28518), -INT16_C( 10135), -INT16_C( 17343),  INT16_C( 14806), -INT16_C( 29634),  INT16_C(  4123), -INT16_C( 10306), -INT16_C( 32455) },
      {  INT16_C( 24725),  INT16_C(  3209),  INT16_C( 27416), -INT16_C( 13821), -INT16_C( 10135),  INT16_C( 14806),  INT16_C(  4123), -INT16_C( 32455) } },
    { { -INT16_C( 12502), -INT16_C( 11551),  INT16_C( 27326),  INT16_C( 29407), -INT16_C(  2258), -INT16_C( 17186), -INT16_C(  7818),  INT16_C(  4230) },
      { -INT16_C(  4239), -INT16_C( 19735), -INT16_C( 16469), -INT16_C(  5652),  INT16_C(  1868),  INT16_C(  2810),  INT16_C( 13278),  INT16_C(  2187) },
      { -INT16_C( 11551),  INT16_C( 29407), -INT16_C( 17186),  INT16_C(  4230), -INT16_C( 19735), -INT16_C(  5652),  INT16_C(  2810),  INT16_C(  2187) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_x_mm_loadu_epi16(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epi16(test_vec[i].b);
    simde__m128i r = simde_x_mm_deinterleaveodd_epi16(a, b);
    simde_test_x86_assert_equal_i16x8(r, simde_x_mm_loadu_epi16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_x_mm_deinterleaveeven_epi32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const int32_t a[4];
    const int32_t b[4];
    const int32_t r[4];
  } test_vec[] = {
    { { -INT32_C(   495461067),  INT32_C(   380891071), -INT32_C(  1359195410), -INT32_C(  1086867746) },
      {  INT32_C(  1697186048),  INT32_C(   908310888), -INT32_C(  1885575044),  INT32_C(  1608021034) },
      { -INT32_C(   495461067), -INT32_C(  1359195410),  INT32_C(  1697186048), -INT32_C(  1885575044) } },
    { {  INT32_C(   289558610),  INT32_C(   757593407),  INT32_C(   635118407), -INT32_C(   622587174) },
      {  INT32_C(  2084572435),  INT32_C(  1118987206), -INT32_C(   153989429),  INT32_C(   341158594) },
      {  INT32_C(   289558610),  INT32_C(   635118407),  INT32_C(  2084572435), -INT32_C(   153989429) } },
    { {  INT32_C(   958830586), -INT32_C(   748270196),  INT32_C(  1274560881),  INT32_C(  1730534740) },
      { -INT32_C(  1310497302), -INT32_C(  1795975736), -INT32_C(  1500854813),  INT32_C(  1790631792) },
      {  INT32_C(   958830586),  INT32_C(  1274560881), -INT32_C(  1310497302), -INT32_C(  1500854813) } },
    { {  INT32_C(    61137015), -INT32_C(  1613297106), -INT32_C(  1595224244), -INT32_C(  1761144916) },
      {  INT32_C(  1028189045),  INT32_C(  1691433856),  INT32_C(  1896504065), -INT32_C(  1294220229) },
      {  INT32_C(    61137015), -INT32_C(  1595224244),  INT32_C(  1028189045),  INT32_C(  1896504065) } },
    { { -INT32_C(   743080027), -INT32_C(   697135990),  INT32_C(   141974620), -INT32_C(   526418581) },
      { -INT32_C(   383850648),  INT32_C(   609087267), -INT32_C(  2037033141), -INT32_C(  1070043109) },
      { -INT32_C(   743080027),  INT32_C(   141974620), -INT32_C(   383850648), -INT32_C(  2037033141) } },
    { {  INT32_C(  2056515056), -INT32_C(   699398790), -INT32_C(   841038239), -INT32_C(  1397916093) },
      { -INT32_C(  2003448987),  INT32_C(   111993531),  INT32_C(  1418477881), -INT32_C(  1575631694) },
      {  INT32_C(  2056515056), -INT32_C(   841038239), -INT32_C(  2003448987),  INT32_C(  1418477881) } },
    { {  INT32_C(   723298481),  INT32_C(   251751598),  INT32_C(  1977409586), -INT32_C(  1021212066) },
      {  INT32_C(   273462869), -INT32_C(   787023720), -INT32_C(   333012422),  INT32_C(   411974502) },
      {  INT32_C(   723298481),  INT32_C(  1977409586),  INT32_C(   273462869), -INT32_C(   333012422) } },
    { { -INT32_C(  1857836317),  INT32_C(  1218528534), -INT32_C(  2084733659),  INT32_C(  1564925703) },
      {  INT32_C(   778932885), -INT32_C(   973110133), -INT32_C(  1917770458),  INT32_C(  1151680352) },
      { -INT32_C(  1857836317), -INT32_C(  2084733659),  INT32_C(   778932885), -INT32_C(  1917770458) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_x_mm_loadu_epi32(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epi32(test_vec[i].b);
    simde__m128i r = simde_x_mm_deinterleaveeven_epi32(a, b);
    simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_x_mm_deinterleaveodd_epi32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const int32_t a[4];
    const int32_t b[4];
    const int32_t r[4];
  } test_vec[] = {
    { { -INT32_C(  1143416908), -INT32_C(   314874252), -INT32_C(   564427947),  INT32_C(   935545972) },
      {  INT32_C(  1975807146),  INT32_C(  1788688421), -INT32_C(   540372237),  INT32_C(  1581754026) },
      { -INT32_C(   314874252),  INT32_C(   935545972),  INT32_C(  1788688421),  INT32_C(  1581754026) } },
    { { -INT32_C(   250011523), -INT32_C(   606186362),  INT32_C(  1270430167),  INT32_C(   813857926) },
      {  INT32_C(   228935656),  INT32_C(  1937261439),  INT32_C(  2136097493),  INT32_C(  1709021928) },
      { -INT32_C(   606186362),  INT32_C(   813857926),  INT32_C(  1937261439),  INT32_C(  1709021928) } },
    { {  INT32_C(  1079441082),  INT32_C(   555430986), -INT32_C(   210906003),  INT32_C(   958656337) },
      { -INT32_C(  1236809418), -INT32_C(   517357812), -INT32_C(   379553023), -INT32_C(   816956139) },
      {  INT32_C(   555430986),  INT32_C(   958656337), -INT32_C(   517357812), -INT32_C(   816956139) } },
    { {  INT32_C(  2098177075),  INT32_C(  1167993560),  INT32_C(  1345915903),  INT32_C(   831085819) },
      {  INT32_C(   837275685), -INT32_C(  1877864305), -INT32_C(  1585876340), -INT32_C(   495859793) },
      {  INT32_C(  1167993560),  INT32_C(   831085819), -INT32_C(  1877864305), -INT32_C(   495859793) } },
    { {  INT32_C(  1130332267), -INT32_C(  1433796949),  INT32_C(    83542537),  INT32_C(  1144423198) },
      { -INT32_C(   478864044), -INT32_C(  1166768082), -INT32_C(  1436815878),  INT32_C(   546098357) },
      { -INT32_C(  1433796949),  INT32_C(  1144423198), -INT32_C(  1166768082),  INT32_C(   546098357) } },
    { { -INT32_C(   127603635), -INT32_C(   207426070), -INT32_C(   839344977),  INT32_C(  1930505759) },
      {  INT32_C(  2035779403),  INT32_C(   154389263),  INT32_C(  1840484280), -INT32_C(  1467072421) },
      { -INT32_C(   207426070),  INT32_C(  1930505759),  INT32_C(   154389263), -INT32_C(  1467072421) } },
    { {  INT32_C(   379646508), -INT32_C(  1911995681), -INT32_C(    27590178),  INT32_C(  2071031087) },
      {  INT32_C(    66373876),  INT32_C(  1275865235),  INT32_C(   314163383),  INT32_C(   750470912) },
      { -INT32_C(  1911995681),  INT32_C(  2071031087),  INT32_C(  1275865235),  INT32_C(   750470912) } },
    { {  INT32_C(   407001913),  INT32_C(  2091273118),  INT32_C(  2088370765),  INT32_C(  1677192303) },
      {  INT32_C(  1214704820), -INT32_C(   879463916),  INT32_C(   853364018), -INT32_C(   832661355) },
      {  INT32_C(  2091273118),  INT32_C(  1677192303), -INT32_C(   879463916), -INT32_C(   832661355) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_x_mm_loadu_epi32(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epi32(test_vec[i].b);
    simde__m128i r = simde_x_mm_deinterleaveodd_epi32(a, b);
    simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_x_mm_deinterleaveeven_ps (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const simde_float32 a[4];
    const simde_float32 b[4];
    const simde_float32 r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -473.93), SIMDE_FLOAT32_C(  -118.41), SIMDE_FLOAT32_C(   999.42), SIMDE_FLOAT32_C(   207.80) },
      { SIMDE_FLOAT32_C(  -240.27), SIMDE_FLOAT32_C(   -38.87), SIMDE_FLOAT32_C(  -206.60), SIMDE_FLOAT32_C(  -674.33) },
      { SIMDE_FLOAT32_C(  -473.93), SIMDE_FLOAT32_C(   999.42), SIMDE_FLOAT32_C(  -240.27), SIMDE_FLOAT32_C(  -206.60) } },
    { { SIMDE_FLOAT32_C(   142.19), SIMDE_FLOAT32_C(   224.84), SIMDE_FLOAT32_C(   333.30), SIMDE_FLOAT32_C(  -971.97) },
      { SIMDE_FLOAT32_C(  -728.25), SIMDE_FLOAT32_C(   611.12), SIMDE_FLOAT32_C(   607.96), SIMDE_FLOAT32_C(  -422.86) },
      { SIMDE_FLOAT32_C(   142.19), SIMDE_FLOAT32_C(   333.30), SIMDE_FLOAT32_C(  -728.25), SIMDE_FLOAT32_C(   607.96) } },
    { { SIMDE_FLOAT32_C(  -141.30), SIMDE_FLOAT32_C(  -687.40), SIMDE_FLOAT32_C(   669.82), SIMDE_FLOAT32_C(   768.18) },
      { SIMDE_FLOAT32_C(   291.84), SIMDE_FLOAT32_C(   -70.28), SIMDE_FLOAT32_C(  -453.11), SIMDE_FLOAT32_C(   157.28) },
      { SIMDE_FLOAT32_C(  -141.30), SIMDE_FLOAT32_C(   669.82), SIMDE_FLOAT32_C(   291.84), SIMDE_FLOAT32_C(  -453.11) } },
    { { SIMDE_FLOAT32_C(   -84.06), SIMDE_FLOAT32_C(  -175.69), SIMDE_FLOAT32_C(  -309.30), SIMDE_FLOAT32_C(   582.27) },
      { SIMDE_FLOAT32_C(  -646.52), SIMDE_FLOAT32_C(  -858.00), SIMDE_FLOAT32_C(  -765.38), SIMDE_FLOAT32_C(  -120.45) },
      { SIMDE_FLOAT32_C(   -84.06), SIMDE_FLOAT32_C(  -309.30), SIMDE_FLOAT32_C(  -646.52), SIMDE_FLOAT32_C(  -765.38) } },
    { { SIMDE_FLOAT32_C(    23.59), SIMDE_FLOAT32_C(  -765.97), SIMDE_FLOAT32_C(  -912.65), SIMDE_FLOAT32_C(   783.32) },
      { SIMDE_FLOAT32_C(   195.16), SIMDE_FLOAT32_C(  -119.25), SIMDE_FLOAT32_C(  -891.01), SIMDE_FLOAT32_C(  -662.65) },
      { SIMDE_FLOAT32_C(    23.59), SIMDE_FLOAT32_C(  -912.65), SIMDE_FLOAT32_C(   195.16), SIMDE_FLOAT32_C(  -891.01) } },
    { { SIMDE_FLOAT32_C(  -894.42), SIMDE_FLOAT32_C(   442.29), SIMDE_FLOAT32_C(  -634.62), SIMDE_FLOAT32_C(  -622.67) },
      { SIMDE_FLOAT32_C(    53.41), SIMDE_FLOAT32_C(   973.34), SIMDE_FLOAT32_C(   -45.53), SIMDE_FLOAT32_C(   912.11) },
      { SIMDE_FLOAT32_C(  -894.42), SIMDE_FLOAT32_C(  -634.62), SIMDE_FLOAT32_C(    53.41), SIMDE_FLOAT32_C(   -45.53) } },
    { { SIMDE_FLOAT32_C(  -714.06), SIMDE_FLOAT32_C(  -375.71), SIMDE_FLOAT32_C(   680.29), SIMDE_FLOAT32_C(   577.78) },
      { SIMDE_FLOAT32_C(   554.02), SIMDE_FLOAT32_C(  -772.82), SIMDE_FLOAT32_C(  -264.94), SIMDE_FLOAT32_C(  -530.04) },
      { SIMDE_FLOAT32_C(  -714.06), SIMDE_FLOAT32_C(   680.29), SIMDE_FLOAT32_C(   554.02), SIMDE_FLOAT32_C(  -264.94) } },
    { { SIMDE_FLOAT32_C(    51.48), SIMDE_FLOAT32_C(   425.76), SIMDE_FLOAT32_C(  -947.77), SIMDE_FLOAT32_C(   404.96) },
      { SIMDE_FLOAT32_C(   567.76), SIMDE_FLOAT32_C(  -713.15), SIMDE_FLOAT32_C(  -715.49), SIMDE_FLOAT32_C(  -408.66) },
      { SIMDE_FLOAT32_C(    51.48), SIMDE_FLOAT32_C(  -947.77), SIMDE_FLOAT32_C(   567.76), SIMDE_FLOAT32_C(  -715.49) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128 a = simde_mm_loadu_ps(test_vec[i].a);
    simde__m128 b = simde_mm_loadu_ps(test_vec[i].b);
    simde__m128 r = simde_x_mm_deinterleaveeven_ps(a, b);
    simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_x_mm_deinterleaveodd_ps (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const simde_float32 a[4];
    const simde_float32 b[4];
    const simde_float32 r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   319.96), SIMDE_FLOAT32_C(   735.94), SIMDE_FLOAT32_C(  -176.73), SIMDE_FLOAT32_C(    47.10) },
      { SIMDE_FLOAT32_C(  -358.23), SIMDE_FLOAT32_C(  -903.77), SIMDE_FLOAT32_C(   728.83), SIMDE_FLOAT32_C(  -988.23) },
      { SIMDE_FLOAT32_C(   735.94), SIMDE_FLOAT32_C(    47.10), SIMDE_FLOAT32_C(  -903.77), SIMDE_FLOAT32_C(  -988.23) } },
    { { SIMDE_FLOAT32_C(   660.33), SIMDE_FLOAT32_C(   459.02), SIMDE_FLOAT32_C(   713.57), SIMDE_FLOAT32_C(   687.45) },
      { SIMDE_FLOAT32_C(   238.78), SIMDE_FLOAT32_C(  -573.22), SIMDE_FLOAT32_C(  -177.47), SIMDE_FLOAT32_C(   830.16) },
      { SIMDE_FLOAT32_C(   459.02), SIMDE_FLOAT32_C(   687.45), SIMDE_FLOAT32_C(  -573.22), SIMDE_FLOAT32_C(   830.16) } },
    { { SIMDE_FLOAT32_C(   997.19), SIMDE_FLOAT32_C(   897.57), SIMDE_FLOAT32_C(   555.92), SIMDE_FLOAT32_C(  -485.67) },
      { SIMDE_FLOAT32_C(   759.77), SIMDE_FLOAT32_C(   769.53), SIMDE_FLOAT32_C(  -961.37), SIMDE_FLOAT32_C(   332.86) },
      { SIMDE_FLOAT32_C(   897.57), SIMDE_FLOAT32_C(  -485.67), SIMDE_FLOAT32_C(   769.53), SIMDE_FLOAT32_C(   332.86) } },
    { { SIMDE_FLOAT32_C(   -40.50), SIMDE_FLOAT32_C(   339.87), SIMDE_FLOAT32_C(  -944.60), SIMDE_FLOAT32_C(   161.91) },
      { SIMDE_FLOAT32_C(  -435.47), SIMDE_FLOAT32_C(   115.93), SIMDE_FLOAT32_C(  -481.55), SIMDE_FLOAT32_C(   884.50) },
      { SIMDE_FLOAT32_C(   339.87), SIMDE_FLOAT32_C(   161.91), SIMDE_FLOAT32_C(   115.93), SIMDE_FLOAT32_C(   884.50) } },
    { { SIMDE_FLOAT32_C(  -148.13), SIMDE_FLOAT32_C(   341.72), SIMDE_FLOAT32_C(   -68.40), SIMDE_FLOAT32_C(   493.64) },
      { SIMDE_FLOAT32_C(   437.94), SIMDE_FLOAT32_C(  -339.57), SIMDE_FLOAT32_C(   505.41), SIMDE_FLOAT32_C(    98.27) },
      { SIMDE_FLOAT32_C(   341.72), SIMDE_FLOAT32_C(   493.64), SIMDE_FLOAT32_C(  -339.57), SIMDE_FLOAT32_C(    98.27) } },
    { { SIMDE_FLOAT32_C(  -880.55), SIMDE_FLOAT32_C(   218.98), SIMDE_FLOAT32_C(  -214.27), SIMDE_FLOAT32_C(   358.22) },
      { SIMDE_FLOAT32_C(   645.75), SIMDE_FLOAT32_C(   608.25), SIMDE_FLOAT32_C(   188.38), SIMDE_FLOAT32_C(   642.94) },
      { SIMDE_FLOAT32_C(   218.98), SIMDE_FLOAT32_C(   358.22), SIMDE_FLOAT32_C(   608.25), SIMDE_FLOAT32_C(   642.94) } },
    { { SIMDE_FLOAT32_C(   505.82), SIMDE_FLOAT32_C(  -255.70), SIMDE_FLOAT32_C(  -842.73), SIMDE_FLOAT32_C(   265.59) },
      { SIMDE_FLOAT32_C(  -486.16), SIMDE_FLOAT32_C(  -804.10), SIMDE_FLOAT32_C(  -401.56), SIMDE_FLOAT32_C(   473.34) },
      { SIMDE_FLOAT32_C(  -255.70), SIMDE_FLOAT32_C(   265.59), SIMDE_FLOAT32_C(  -804.10), SIMDE_FLOAT32_C(   473.34) } },
    { { SIMDE_FLOAT32_C(   535.77), SIMDE_FLOAT32_C(  -346.16), SIMDE_FLOAT32_C(  -364.75), SIMDE_FLOAT32_C(  -899.70) },
      { SIMDE_FLOAT32_C(   769.77), SIMDE_FLOAT32_C(   153.70), SIMDE_FLOAT32_C(   984.80), SIMDE_FLOAT32_C(  -378.36) },
      { SIMDE_FLOAT32_C(  -346.16), SIMDE_FLOAT32_C(  -899.70), SIMDE_FLOAT32_C(   153.70), SIMDE_FLOAT32_C(  -378.36) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128 a = simde_mm_loadu_ps(test_vec[i].a);
    simde__m128 b = simde_mm_loadu_ps(test_vec[i].b);
    simde__m128 r = simde_x_mm_deinterleaveodd_ps(a, b);
    simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_x_mm_deinterleaveeven_pd (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const simde_float64 a[2];
    const simde_float64 b[2];
    const simde_float64 r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(  -213.92), SIMDE_FLOAT64_C(  -523.36) },
      { SIMDE_FLOAT64_C(   418.53), SIMDE_FLOAT64_C(  -506.43) },
      { SIMDE_FLOAT64_C(  -213.92), SIMDE_FLOAT64_C(   418.53) } },
    { { SIMDE_FLOAT64_C(   210.38), SIMDE_FLOAT64_C(   323.18) },
      { SIMDE_FLOAT64_C(     0.07), SIMDE_FLOAT64_C(  -306.56) },
      { SIMDE_FLOAT64_C(   210.38), SIMDE_FLOAT64_C(     0.07) } },
    { { SIMDE_FLOAT64_C(  -309.86), SIMDE_FLOAT64_C(  -739.34) },
      { SIMDE_FLOAT64_C(  -573.79), SIMDE_FLOAT64_C(   274.99) },
      { SIMDE_FLOAT64_C(  -309.86), SIMDE_FLOAT64_C(  -573.79) } },
    { { SIMDE_FLOAT64_C(  -805.36), SIMDE_FLOAT64_C(  -193.80) },
      { SIMDE_FLOAT64_C(   247.86), SIMDE_FLOAT64_C(   790.63) },
      { SIMDE_FLOAT64_C(  -805.36), SIMDE_FLOAT64_C(   247.86) } },
    { { SIMDE_FLOAT64_C(  -820.99), SIMDE_FLOAT64_C(  -241.09) },
      { SIMDE_FLOAT64_C(  -102.54), SIMDE_FLOAT64_C(  -138.57) },
      { SIMDE_FLOAT64_C(  -820.99), SIMDE_FLOAT64_C(  -102.54) } },
    { { SIMDE_FLOAT64_C(  -904.58), SIMDE_FLOAT64_C(  -997.56) },
      { SIMDE_FLOAT64_C(  -833.83), SIMDE_FLOAT64_C(  -291.82) },
      { SIMDE_FLOAT64_C(  -904.58), SIMDE_FLOAT64_C(  -833.83) } },
    { { SIMDE_FLOAT64_C(   823.76), SIMDE_FLOAT64_C(    62.64) },
      { SIMDE_FLOAT64_C(   610.28), SIMDE_FLOAT64_C(  -602.78) },
      { SIMDE_FLOAT64_C(   823.76), SIMDE_FLOAT64_C(   610.28) } },
    { { SIMDE_FLOAT64_C(  -320.72), SIMDE_FLOAT64_C(   398.57) },
      { SIMDE_FLOAT64_C(   140.12), SIMDE_FLOAT64_C(   465.37) },
      { SIMDE_FLOAT64_C(  -320.72), SIMDE_FLOAT64_C(   140.12) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128d a = simde_mm_loadu_pd(test_vec[i].a);
    simde__m128d b = simde_mm_loadu_pd(test_vec[i].b);
    simde__m128d r = simde_x_mm_deinterleaveeven_pd(a, b);
    simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_x_mm_deinterleaveodd_pd (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const simde_float64 a[2];
    const simde_float64 b[2];
    const simde_float64 r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(   240.55), SIMDE_FLOAT64_C(   268.44) },
      { SIMDE_FLOAT64_C(   124.13), SIMDE_FLOAT64_C(  -764.47) },
      { SIMDE_FLOAT64_C(   268.44), SIMDE_FLOAT64_C(  -764.47) } },
    { { SIMDE_FLOAT64_C(   714.48), SIMDE_FLOAT64_C(  -430.05) },
      { SIMDE_FLOAT64_C(   521.54), SIMDE_FLOAT64_C(  -498.21) },
      { SIMDE_FLOAT64_C(  -430.05), SIMDE_FLOAT64_C(  -498.21) } },
    { { SIMDE_FLOAT64_C(   -36.38), SIMDE_FLOAT64_C(   808.25) },
      { SIMDE_FLOAT64_C(   307.62), SIMDE_FLOAT64_C(   363.39) },
      { SIMDE_FLOAT64_C(   808.25), SIMDE_FLOAT64_C(   363.39) } },
    { { SIMDE_FLOAT64_C(   592.99), SIMDE_FLOAT64_C(   317.46) },
      { SIMDE_FLOAT64_C(  -310.83), SIMDE_FLOAT64_C(   683.24) },
      { SIMDE_FLOAT64_C(   317.46), SIMDE_FLOAT64_C(   683.24) } },
    { { SIMDE_FLOAT64_C(   702.91), SIMDE_FLOAT64_C(  -799.29) },
      { SIMDE_FLOAT64_C(    54.16), SIMDE_FLOAT64_C(   571.93) },
      { SIMDE_FLOAT64_C(  -799.29), SIMDE_FLOAT64_C(   571.93) } },
    { { SIMDE_FLOAT64_C(   355.14), SIMDE_FLOAT64_C(   815.61) },
      { SIMDE_FLOAT64_C(  -221.09), SIMDE_FLOAT64_C(  -615.38) },
      { SIMDE_FLOAT64_C(   815.61), SIMDE_FLOAT64_C(  -615.38) } },
    { { SIMDE_FLOAT64_C(  -761.33), SIMDE_FLOAT64_C(   300.07) },
      { SIMDE_FLOAT64_C(    74.48), SIMDE_FLOAT64_C(  -935.14) },
      { SIMDE_FLOAT64_C(   300.07), SIMDE_FLOAT64_C(  -935.14) } },
    { { SIMDE_FLOAT64_C(  -919.14), SIMDE_FLOAT64_C(   156.94) },
      { SIMDE_FLOAT64_C(   625.78), SIMDE_FLOAT64_C(   321.42) },
      { SIMDE_FLOAT64_C(   156.94), SIMDE_FLOAT64_C(   321.42) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128d a = simde_mm_loadu_pd(test_vec[i].a);
    simde__m128d b = simde_mm_loadu_pd(test_vec[i].b);
    simde__m128d r = simde_x_mm_deinterleaveodd_pd(a, b);
    simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_mm_addsub_pd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128d a;
    simde__m128d b;
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd(  476.02,  -639.97),
      simde_mm_set_pd(  710.19,   -41.14),
      simde_mm_set_pd( 1186.21,  -598.83) },
    { simde_mm_set_pd(  650.79,  -848.27),
      simde_mm_set_pd(  773.15,   711.98),
      simde_mm_set_pd( 1423.94, -1560.25) },
    { simde_mm_set_pd( -904.77,  -447.30),
      simde_mm_set_pd( -414.59,  -690.17),
      simde_mm_set_pd(-1319.36,   242.87) },
    { simde_mm_set_pd(  727.10,   -46.44),
      simde_mm_set_pd( -635.38,    20.27),
      simde_mm_set_pd(   91.72,   -66.71) },
    { simde_mm_set_pd(   74.87,  -444.69),
      simde_mm_set_pd( -222.00,   809.16),
      simde_mm_set_pd( -147.13, -1253.85) },
    { simde_mm_set_pd(  468.30,  -546.58),
      simde_mm_set_pd(  629.89,   504.95),
      simde_mm_set_pd( 1098.19, -1051.53) },
    { simde_mm_set_pd(  908.04,  -977.41),
      simde_mm_set_pd(  521.23,  -249.10),
      simde_mm_set_pd( 1429.27,  -728.31) },
    { simde_mm_set_pd(  107.41,  -431.12),
      simde_mm_set_pd(   91.73,   142.37),
      simde_mm_set_pd(  199.14,  -573.49) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_addsub_pd(test_vec[i].a, test_vec[i].b);
    simde_assert_m128d_close(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm_addsub_ps(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128 a;
    simde__m128 b;
    simde__m128 r;
  } test_vec[8] = {
    { simde_mm_set_ps(  827.09f,   888.55f,   270.24f,   512.98f),
      simde_mm_set_ps(  691.09f,   805.07f,   343.35f,   695.79f),
      simde_mm_set_ps( 1518.18f,    83.48f,   613.59f,  -182.81f) },
    { simde_mm_set_ps( -122.09f,   678.17f,  -910.24f,  -995.98f),
      simde_mm_set_ps( -197.90f,   177.04f,  -469.81f,  -451.24f),
      simde_mm_set_ps( -319.99f,   501.13f, -1380.05f,  -544.74f) },
    { simde_mm_set_ps(  589.86f,  -922.72f,   221.54f,  -598.55f),
      simde_mm_set_ps( -751.93f,   480.30f,   218.06f,   103.71f),
      simde_mm_set_ps( -162.07f, -1403.02f,   439.60f,  -702.26f) },
    { simde_mm_set_ps( -375.10f,   590.75f,   672.39f,   216.94f),
      simde_mm_set_ps(  184.12f,   575.54f,  -189.52f,   591.53f),
      simde_mm_set_ps( -190.98f,    15.21f,   482.87f,  -374.59f) },
    { simde_mm_set_ps(  838.92f,  -777.48f,  -357.82f,   473.60f),
      simde_mm_set_ps(  655.27f,  -960.61f,   194.84f,   470.24f),
      simde_mm_set_ps( 1494.19f,   183.13f,  -162.98f,     3.36f) },
    { simde_mm_set_ps(  141.50f,   865.93f,   836.92f,   780.12f),
      simde_mm_set_ps(  237.78f,  -664.15f,   934.51f,   175.34f),
      simde_mm_set_ps(  379.28f,  1530.08f,  1771.43f,   604.78f) },
    { simde_mm_set_ps( -146.63f,   845.58f,  -575.02f,  -435.05f),
      simde_mm_set_ps(   46.98f,   315.33f,  -622.74f,  -392.97f),
      simde_mm_set_ps(  -99.65f,   530.25f, -1197.76f,   -42.08f) },
    { simde_mm_set_ps( -588.54f,   208.80f,    44.42f,  -534.81f),
      simde_mm_set_ps(  849.82f,  -315.73f,  -758.03f,   754.33f),
      simde_mm_set_ps(  261.28f,   524.53f,  -713.61f, -1289.14f) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128 r = simde_mm_addsub_ps(test_vec[i].a, test_vec[i].b);
    simde_assert_m128_close(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm_hadd_pd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128d a;
    simde__m128d b;
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd(   44.10,  -542.35),
      simde_mm_set_pd( -346.60,  -427.89),
      simde_mm_set_pd( -774.49,  -498.25) },
    { simde_mm_set_pd(  716.10,   840.74),
      simde_mm_set_pd( -654.24,  -672.74),
      simde_mm_set_pd(-1326.98,  1556.84) },
    { simde_mm_set_pd( -397.69,   265.98),
      simde_mm_set_pd( -595.53,   562.15),
      simde_mm_set_pd(  -33.38,  -131.71) },
    { simde_mm_set_pd(  416.44,   929.19),
      simde_mm_set_pd( -225.30,  -546.63),
      simde_mm_set_pd( -771.93,  1345.63) },
    { simde_mm_set_pd(  506.73,   886.11),
      simde_mm_set_pd(  344.49,   957.84),
      simde_mm_set_pd( 1302.33,  1392.84) },
    { simde_mm_set_pd(  886.60,  -404.84),
      simde_mm_set_pd(  386.06,  -275.34),
      simde_mm_set_pd(  110.72,   481.76) },
    { simde_mm_set_pd(    4.86,   401.30),
      simde_mm_set_pd(  316.75,   350.77),
      simde_mm_set_pd(  667.52,   406.16) },
    { simde_mm_set_pd( -409.95,   357.27),
      simde_mm_set_pd( -949.43,  -786.56),
      simde_mm_set_pd(-1735.99,   -52.68) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_hadd_pd(test_vec[i].a, test_vec[i].b);
    simde_assert_m128d_close(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm_hadd_ps(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128 a;
    simde__m128 b;
    simde__m128 r;
  } test_vec[8] = {
    { simde_mm_set_ps(  732.68f,  -915.27f,  -191.77f,  -862.58f),
      simde_mm_set_ps(   81.80f,   547.56f,   259.82f,    55.94f),
      simde_mm_set_ps(  629.36f,   315.76f,  -182.59f, -1054.35f) },
    { simde_mm_set_ps(  429.35f,  -314.15f,  -691.69f,  -113.96f),
      simde_mm_set_ps( -636.15f,   881.85f,   515.05f,  -694.57f),
      simde_mm_set_ps(  245.70f,  -179.52f,   115.20f,  -805.65f) },
    { simde_mm_set_ps(  163.17f,   585.35f,   889.94f,   989.94f),
      simde_mm_set_ps(  558.88f,  -287.71f,   978.54f,  -729.07f),
      simde_mm_set_ps(  271.17f,   249.47f,   748.52f,  1879.88f) },
    { simde_mm_set_ps(  396.52f,   255.51f,   531.47f,  -510.49f),
      simde_mm_set_ps( -162.17f,   929.03f,  -176.85f,   827.75f),
      simde_mm_set_ps(  766.86f,   650.90f,   652.03f,    20.98f) },
    { simde_mm_set_ps(  348.14f,  -946.97f,  -177.74f,   520.68f),
      simde_mm_set_ps(  339.94f,   653.25f,   168.00f,   216.81f),
      simde_mm_set_ps(  993.19f,   384.81f,  -598.83f,   342.94f) },
    { simde_mm_set_ps( -341.20f,  -395.72f,  -751.71f,   483.71f),
      simde_mm_set_ps(  214.25f,   187.29f,   627.65f,  -993.70f),
      simde_mm_set_ps(  401.54f,  -366.05f,  -736.92f,  -268.00f) },
    { simde_mm_set_ps( -117.08f,  -155.79f,   327.94f,  -604.45f),
      simde_mm_set_ps( -924.11f,    -3.93f,  -496.48f,  -281.24f),
      simde_mm_set_ps( -928.04f,  -777.72f,  -272.87f,  -276.51f) },
    { simde_mm_set_ps( -207.92f,   955.09f,   949.83f,  -476.81f),
      simde_mm_set_ps( -883.98f,   810.86f,   947.09f,  -558.58f),
      simde_mm_set_ps(  -73.12f,   388.51f,   747.17f,   473.02f) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128 r = simde_mm_hadd_ps(test_vec[i].a, test_vec[i].b);
    simde_assert_m128_close(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm_hsub_pd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128d a;
    simde__m128d b;
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd(  -15.50,   258.33),
      simde_mm_set_pd(  484.94,  -432.56),
      simde_mm_set_pd( -917.50,   273.83) },
    { simde_mm_set_pd(   50.11,  -735.38),
      simde_mm_set_pd(   70.36,   538.50),
      simde_mm_set_pd(  468.14,  -785.49) },
    { simde_mm_set_pd(  140.13,  -672.00),
      simde_mm_set_pd( -602.17,  -745.12),
      simde_mm_set_pd( -142.95,  -812.13) },
    { simde_mm_set_pd(    1.89,  -114.93),
      simde_mm_set_pd(  125.81,   137.32),
      simde_mm_set_pd(   11.51,  -116.82) },
    { simde_mm_set_pd( -579.13,  -899.36),
      simde_mm_set_pd(  893.51,   328.15),
      simde_mm_set_pd( -565.36,  -320.23) },
    { simde_mm_set_pd( -275.68,  -217.61),
      simde_mm_set_pd(  167.25,   -93.39),
      simde_mm_set_pd( -260.64,    58.07) },
    { simde_mm_set_pd(  312.59,   137.63),
      simde_mm_set_pd(  589.59,   751.69),
      simde_mm_set_pd(  162.10,  -174.96) },
    { simde_mm_set_pd(  359.94,  -880.43),
      simde_mm_set_pd(  239.69,  -581.16),
      simde_mm_set_pd( -820.85, -1240.37) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_hsub_pd(test_vec[i].a, test_vec[i].b);
    simde_assert_m128d_close(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm_hsub_ps(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128 a;
    simde__m128 b;
    simde__m128 r;
  } test_vec[8] = {
    { simde_mm_set_ps(   50.11f,  -735.38f,   -15.50f,   258.33f),
      simde_mm_set_ps(   70.36f,   538.50f,   484.94f,  -432.56f),
      simde_mm_set_ps(  468.14f,  -917.50f,  -785.49f,   273.83f) },
    { simde_mm_set_ps(    1.89f,  -114.93f,   140.13f,  -672.00f),
      simde_mm_set_ps(  125.81f,   137.32f,  -602.17f,  -745.12f),
      simde_mm_set_ps(   11.51f,  -142.95f,  -116.82f,  -812.13f) },
    { simde_mm_set_ps( -275.68f,  -217.61f,  -579.13f,  -899.36f),
      simde_mm_set_ps(  167.25f,   -93.39f,   893.51f,   328.15f),
      simde_mm_set_ps( -260.64f,  -565.36f,    58.07f,  -320.23f) },
    { simde_mm_set_ps(  359.94f,  -880.43f,   312.59f,   137.63f),
      simde_mm_set_ps(  239.69f,  -581.16f,   589.59f,   751.69f),
      simde_mm_set_ps( -820.85f,   162.10f, -1240.37f,  -174.96f) },
    { simde_mm_set_ps(  923.43f,   905.56f,  -615.92f,   454.60f),
      simde_mm_set_ps(  375.63f,   326.29f,  -819.79f,  -550.42f),
      simde_mm_set_ps(  -49.34f,   269.37f,   -17.87f,  1070.52f) },
    { simde_mm_set_ps(  344.96f,   -84.73f,  -925.77f,   984.26f),
      simde_mm_set_ps(  584.98f,   981.58f,  -824.48f,   268.25f),
      simde_mm_set_ps(  396.60f,  1092.73f,  -429.69f,  1910.03f) },
    { simde_mm_set_ps(  405.32f,   -74.19f,   712.30f,   820.93f),
      simde_mm_set_ps( -939.26f,  -768.80f,  -854.21f,   -69.68f),
      simde_mm_set_ps(  170.46f,   784.53f,  -479.51f,   108.63f) },
    { simde_mm_set_ps( -199.94f,   783.57f,   779.03f,   578.25f),
      simde_mm_set_ps(  177.19f,  -819.96f,   -14.40f,   361.82f),
      simde_mm_set_ps( -997.15f,   376.22f,   983.51f,  -200.78f) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128 r = simde_mm_hsub_ps(test_vec[i].a, test_vec[i].b);
    simde_assert_m128_close(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm_lddqu_si128(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128i a;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm_set_epi8(INT8_C(-112), INT8_C( 117), INT8_C( -34), INT8_C(  65), INT8_C(  -1), INT8_C(  38), INT8_C(  89), INT8_C(-126),
                        INT8_C(  67), INT8_C( -47), INT8_C( -14), INT8_C( -14), INT8_C( -36), INT8_C(  93), INT8_C(  67), INT8_C( -57)),
      simde_mm_set_epi8(INT8_C(-112), INT8_C( 117), INT8_C( -34), INT8_C(  65), INT8_C(  -1), INT8_C(  38), INT8_C(  89), INT8_C(-126),
                        INT8_C(  67), INT8_C( -47), INT8_C( -14), INT8_C( -14), INT8_C( -36), INT8_C(  93), INT8_C(  67), INT8_C( -57)) },
    { simde_mm_set_epi8(INT8_C(  35), INT8_C( -25), INT8_C(  29), INT8_C(-117), INT8_C( -37), INT8_C( 120), INT8_C(-105), INT8_C( 106),
                        INT8_C(   4), INT8_C(  73), INT8_C( -55), INT8_C( -70), INT8_C(  11), INT8_C( -15), INT8_C( -35), INT8_C(-116)),
      simde_mm_set_epi8(INT8_C(  35), INT8_C( -25), INT8_C(  29), INT8_C(-117), INT8_C( -37), INT8_C( 120), INT8_C(-105), INT8_C( 106),
                        INT8_C(   4), INT8_C(  73), INT8_C( -55), INT8_C( -70), INT8_C(  11), INT8_C( -15), INT8_C( -35), INT8_C(-116)) },
    { simde_mm_set_epi8(INT8_C(-101), INT8_C(-119), INT8_C(  63), INT8_C(-115), INT8_C( -96), INT8_C( -31), INT8_C( -21), INT8_C(  40),
                        INT8_C(  85), INT8_C( 109), INT8_C(-125), INT8_C( -15), INT8_C(  21), INT8_C( -59), INT8_C( -50), INT8_C( 101)),
      simde_mm_set_epi8(INT8_C(-101), INT8_C(-119), INT8_C(  63), INT8_C(-115), INT8_C( -96), INT8_C( -31), INT8_C( -21), INT8_C(  40),
                        INT8_C(  85), INT8_C( 109), INT8_C(-125), INT8_C( -15), INT8_C(  21), INT8_C( -59), INT8_C( -50), INT8_C( 101)) },
    { simde_mm_set_epi8(INT8_C( -59), INT8_C( 124), INT8_C(  14), INT8_C( -11), INT8_C(   3), INT8_C( -21), INT8_C(  36), INT8_C(-103),
                        INT8_C( -34), INT8_C( -66), INT8_C(  35), INT8_C(  90), INT8_C(  43), INT8_C( -21), INT8_C( -53), INT8_C( -61)),
      simde_mm_set_epi8(INT8_C( -59), INT8_C( 124), INT8_C(  14), INT8_C( -11), INT8_C(   3), INT8_C( -21), INT8_C(  36), INT8_C(-103),
                        INT8_C( -34), INT8_C( -66), INT8_C(  35), INT8_C(  90), INT8_C(  43), INT8_C( -21), INT8_C( -53), INT8_C( -61)) },
    { simde_mm_set_epi8(INT8_C( -66), INT8_C( -33), INT8_C(  33), INT8_C( -43), INT8_C(  92), INT8_C( -19), INT8_C( -42), INT8_C(-112),
                        INT8_C( -49), INT8_C(  23), INT8_C(  30), INT8_C(  67), INT8_C( -77), INT8_C( 104), INT8_C(  55), INT8_C( -77)),
      simde_mm_set_epi8(INT8_C( -66), INT8_C( -33), INT8_C(  33), INT8_C( -43), INT8_C(  92), INT8_C( -19), INT8_C( -42), INT8_C(-112),
                        INT8_C( -49), INT8_C(  23), INT8_C(  30), INT8_C(  67), INT8_C( -77), INT8_C( 104), INT8_C(  55), INT8_C( -77)) },
    { simde_mm_set_epi8(INT8_C(-109), INT8_C( -50), INT8_C(-103), INT8_C( -95), INT8_C(  10), INT8_C(  39), INT8_C( -20), INT8_C( -38),
                        INT8_C( -87), INT8_C( -89), INT8_C(-100), INT8_C( -30), INT8_C(   0), INT8_C(  13), INT8_C(  36), INT8_C(-101)),
      simde_mm_set_epi8(INT8_C(-109), INT8_C( -50), INT8_C(-103), INT8_C( -95), INT8_C(  10), INT8_C(  39), INT8_C( -20), INT8_C( -38),
                        INT8_C( -87), INT8_C( -89), INT8_C(-100), INT8_C( -30), INT8_C(   0), INT8_C(  13), INT8_C(  36), INT8_C(-101)) },
    { simde_mm_set_epi8(INT8_C( 112), INT8_C( 112), INT8_C( -55), INT8_C( -93), INT8_C( -81), INT8_C(  57), INT8_C(  84), INT8_C(  -3),
                        INT8_C( -51), INT8_C(  -7), INT8_C(   0), INT8_C(-102), INT8_C(  82), INT8_C( -68), INT8_C( 109), INT8_C( 126)),
      simde_mm_set_epi8(INT8_C( 112), INT8_C( 112), INT8_C( -55), INT8_C( -93), INT8_C( -81), INT8_C(  57), INT8_C(  84), INT8_C(  -3),
                        INT8_C( -51), INT8_C(  -7), INT8_C(   0), INT8_C(-102), INT8_C(  82), INT8_C( -68), INT8_C( 109), INT8_C( 126)) },
    { simde_mm_set_epi8(INT8_C(  85), INT8_C(  18), INT8_C(  96), INT8_C( -54), INT8_C( -78), INT8_C( 122), INT8_C(-109), INT8_C(  31),
                        INT8_C( 104), INT8_C( -42), INT8_C(  93), INT8_C( -40), INT8_C( -73), INT8_C( 110), INT8_C( -72), INT8_C( -16)),
      simde_mm_set_epi8(INT8_C(  85), INT8_C(  18), INT8_C(  96), INT8_C( -54), INT8_C( -78), INT8_C( 122), INT8_C(-109), INT8_C(  31),
                        INT8_C( 104), INT8_C( -42), INT8_C(  93), INT8_C( -40), INT8_C( -73), INT8_C( 110), INT8_C( -72), INT8_C( -16)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_lddqu_si128(&test_vec[i].a);
    simde_assert_m128i_i8(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm_loaddup_pd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde_float64 a;
    simde__m128d r;
  } test_vec[8] = {
    {SIMDE_FLOAT64_C( -639.28), simde_mm_set_pd(SIMDE_FLOAT64_C(-639.28), SIMDE_FLOAT64_C(-639.28)) },
    {SIMDE_FLOAT64_C(  754.31), simde_mm_set_pd(SIMDE_FLOAT64_C( 754.31), SIMDE_FLOAT64_C( 754.31)) },
    {SIMDE_FLOAT64_C( -143.09), simde_mm_set_pd(SIMDE_FLOAT64_C(-143.09), SIMDE_FLOAT64_C(-143.09)) },
    {SIMDE_FLOAT64_C( -509.95), simde_mm_set_pd(SIMDE_FLOAT64_C(-509.95), SIMDE_FLOAT64_C(-509.95)) },
    {SIMDE_FLOAT64_C(  357.11), simde_mm_set_pd(SIMDE_FLOAT64_C( 357.11), SIMDE_FLOAT64_C( 357.11)) },
    {SIMDE_FLOAT64_C(  414.83), simde_mm_set_pd(SIMDE_FLOAT64_C( 414.83), SIMDE_FLOAT64_C( 414.83)) },
    {SIMDE_FLOAT64_C(  416.46), simde_mm_set_pd(SIMDE_FLOAT64_C( 416.46), SIMDE_FLOAT64_C( 416.46)) },
    {SIMDE_FLOAT64_C(  167.42), simde_mm_set_pd(SIMDE_FLOAT64_C( 167.42), SIMDE_FLOAT64_C( 167.42)) }
  };

 for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_loaddup_pd(&test_vec[i].a);
    simde_assert_m128d_close(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm_movedup_pd(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128d a;
    simde__m128d r;
  } test_vec[8] = {
   { simde_mm_set_pd(  850.06,   701.47),
      simde_mm_set_pd(  701.47,   701.47) },
    { simde_mm_set_pd( -959.23,   823.21),
      simde_mm_set_pd(  823.21,   823.21) },
    { simde_mm_set_pd(   37.96,   501.12),
      simde_mm_set_pd(  501.12,   501.12) },
    { simde_mm_set_pd(  288.76,  -831.45),
      simde_mm_set_pd( -831.45,  -831.45) },
    { simde_mm_set_pd(  -93.81,   587.70),
      simde_mm_set_pd(  587.70,   587.70) },
    { simde_mm_set_pd(  524.72,   282.96),
      simde_mm_set_pd(  282.96,   282.96) },
    { simde_mm_set_pd( -824.72,   818.07),
      simde_mm_set_pd(  818.07,   818.07) },
    { simde_mm_set_pd(  136.95,  -565.46),
      simde_mm_set_pd( -565.46,  -565.46) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_movedup_pd(test_vec[i].a);
    simde_assert_m128d_close(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm_movehdup_ps(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128 a;
    simde__m128 r;
  } test_vec[8] = {
    { simde_mm_set_ps( -122.14f,   610.86f,  -649.87f,   155.05f),
      simde_mm_set_ps( -122.14f,  -122.14f,  -649.87f,  -649.87f) },
    { simde_mm_set_ps(  559.30f,   847.22f,   946.27f,   786.62f),
      simde_mm_set_ps(  559.30f,   559.30f,   946.27f,   946.27f) },
    { simde_mm_set_ps( -110.32f,    87.26f,   -69.05f,   -39.46f),
      simde_mm_set_ps( -110.32f,  -110.32f,   -69.05f,   -69.05f) },
    { simde_mm_set_ps(  -91.69f,  -770.73f,   838.47f,   700.02f),
      simde_mm_set_ps(  -91.69f,   -91.69f,   838.47f,   838.47f) },
    { simde_mm_set_ps(   54.77f,  -632.77f,    -6.45f,  -696.48f),
      simde_mm_set_ps(   54.77f,    54.77f,    -6.45f,    -6.45f) },
    { simde_mm_set_ps( -313.08f,   792.67f,  -389.34f,  -153.47f),
      simde_mm_set_ps( -313.08f,  -313.08f,  -389.34f,  -389.34f) },
    { simde_mm_set_ps( -873.54f,   935.41f,  -178.48f,   320.54f),
      simde_mm_set_ps( -873.54f,  -873.54f,  -178.48f,  -178.48f) },
    { simde_mm_set_ps(  886.69f,  -558.71f,   768.00f,   565.76f),
      simde_mm_set_ps(  886.69f,   886.69f,   768.00f,   768.00f) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128 r = simde_mm_movehdup_ps(test_vec[i].a);
    simde_assert_m128_close(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_mm_moveldup_ps(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m128 a;
    simde__m128 r;
  } test_vec[8] = {
    { simde_mm_set_ps( -122.14f,   610.86f,  -649.87f,   155.05f),
      simde_mm_set_ps(  610.86f,   610.86f,   155.05f,   155.05f) },
    { simde_mm_set_ps(  559.30f,   847.22f,   946.27f,   786.62f),
      simde_mm_set_ps(  847.22f,   847.22f,   786.62f,   786.62f) },
    { simde_mm_set_ps( -110.32f,    87.26f,   -69.05f,   -39.46f),
      simde_mm_set_ps(   87.26f,    87.26f,   -39.46f,   -39.46f) },
    { simde_mm_set_ps(  -91.69f,  -770.73f,   838.47f,   700.02f),
      simde_mm_set_ps( -770.73f,  -770.73f,   700.02f,   700.02f) },
    { simde_mm_set_ps(   54.77f,  -632.77f,    -6.45f,  -696.48f),
      simde_mm_set_ps( -632.77f,  -632.77f,  -696.48f,  -696.48f) },
    { simde_mm_set_ps( -313.08f,   792.67f,  -389.34f,  -153.47f),
      simde_mm_set_ps(  792.67f,   792.67f,  -153.47f,  -153.47f) },
    { simde_mm_set_ps( -873.54f,   935.41f,  -178.48f,   320.54f),
      simde_mm_set_ps(  935.41f,   935.41f,   320.54f,   320.54f) },
    { simde_mm_set_ps(  886.69f,  -558.71f,   768.00f,   565.76f),
      simde_mm_set_ps( -558.71f,  -558.71f,   565.76f,   565.76f) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128 r = simde_mm_moveldup_ps(test_vec[i].a);
    simde_assert_m128_close(r, test_vec[i].r, 1);
  }

  return 0;
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(x_mm_deinterleaveeven_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(x_mm_deinterleaveodd_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(x_mm_deinterleaveeven_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(x_mm_deinterleaveodd_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(x_mm_deinterleaveeven_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(x_mm_deinterleaveodd_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(x_mm_deinterleaveeven_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(x_mm_deinterleaveodd_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_addsub_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_addsub_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_hadd_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_hadd_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_hsub_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_hsub_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_lddqu_si128)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_loaddup_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_movedup_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_movehdup_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_moveldup_ps)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/test-x86-footer.h>
