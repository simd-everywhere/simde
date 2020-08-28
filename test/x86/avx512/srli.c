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
 *   2020      Hidayat Khan <huk2209@gmail.com>
 */

#define SIMDE_TEST_X86_AVX512_INSN srli

#include <test/x86/avx512/test-avx512.h>
#include <simde/x86/avx512/set.h>
#include <simde/x86/avx512/srli.h>

static int
test_simde_mm512_srli_epi16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const int16_t a[32];
    const int16_t r[32];
  } test_vec[] = {
    { {  INT16_C(  5064), -INT16_C( 13372), -INT16_C( 27857), -INT16_C( 22226),  INT16_C( 15192),  INT16_C( 15375), -INT16_C(  9626), -INT16_C( 29567),
        -INT16_C( 11953), -INT16_C(  3869), -INT16_C( 31356),  INT16_C( 27097), -INT16_C( 12959),  INT16_C( 26598), -INT16_C( 26711),  INT16_C( 28952),
        -INT16_C(  8790), -INT16_C(  9924),  INT16_C( 27504), -INT16_C( 14205), -INT16_C( 27994),  INT16_C(  3076), -INT16_C( 31124), -INT16_C( 17511),
         INT16_C( 31831), -INT16_C(  9045), -INT16_C( 31743),  INT16_C( 25157),  INT16_C( 11345), -INT16_C(  1335), -INT16_C(  7485),  INT16_C( 28011) },
      {  INT16_C(    39),  INT16_C(   407),  INT16_C(   294),  INT16_C(   338),  INT16_C(   118),  INT16_C(   120),  INT16_C(   436),  INT16_C(   281),
         INT16_C(   418),  INT16_C(   481),  INT16_C(   267),  INT16_C(   211),  INT16_C(   410),  INT16_C(   207),  INT16_C(   303),  INT16_C(   226),
         INT16_C(   443),  INT16_C(   434),  INT16_C(   214),  INT16_C(   401),  INT16_C(   293),  INT16_C(    24),  INT16_C(   268),  INT16_C(   375),
         INT16_C(   248),  INT16_C(   441),  INT16_C(   264),  INT16_C(   196),  INT16_C(    88),  INT16_C(   501),  INT16_C(   453),  INT16_C(   218) } },
    { { -INT16_C( 22593),  INT16_C( 12102), -INT16_C( 14062), -INT16_C( 17928), -INT16_C(   933), -INT16_C( 14395),  INT16_C( 24194), -INT16_C(  9598),
         INT16_C( 11738), -INT16_C(  9290), -INT16_C(  1103),  INT16_C(   574),  INT16_C(  1831), -INT16_C(  5380),  INT16_C( 26601), -INT16_C( 22441),
        -INT16_C( 25073),  INT16_C(  8664), -INT16_C( 12185), -INT16_C( 15398), -INT16_C( 24372),  INT16_C( 20362),  INT16_C(  3582), -INT16_C(  9943),
        -INT16_C(  8390), -INT16_C(  4940), -INT16_C(  3366),  INT16_C(   750), -INT16_C(  5126), -INT16_C(  7188),  INT16_C( 17490),  INT16_C( 24972) },
      {  INT16_C(   335),  INT16_C(    94),  INT16_C(   402),  INT16_C(   371),  INT16_C(   504),  INT16_C(   399),  INT16_C(   189),  INT16_C(   437),
         INT16_C(    91),  INT16_C(   439),  INT16_C(   503),  INT16_C(     4),  INT16_C(    14),  INT16_C(   469),  INT16_C(   207),  INT16_C(   336),
         INT16_C(   316),  INT16_C(    67),  INT16_C(   416),  INT16_C(   391),  INT16_C(   321),  INT16_C(   159),  INT16_C(    27),  INT16_C(   434),
         INT16_C(   446),  INT16_C(   473),  INT16_C(   485),  INT16_C(     5),  INT16_C(   471),  INT16_C(   455),  INT16_C(   136),  INT16_C(   195) } },
    { {  INT16_C( 25826),  INT16_C( 18819),  INT16_C( 23860),  INT16_C(    12), -INT16_C( 26627), -INT16_C(   945),  INT16_C( 30884), -INT16_C(  8491),
        -INT16_C( 30377),  INT16_C( 13002), -INT16_C( 18052),  INT16_C( 30260),  INT16_C(  8356), -INT16_C(  2471), -INT16_C(  6812),  INT16_C( 18008),
        -INT16_C(  9399),  INT16_C( 32144), -INT16_C( 25544),  INT16_C( 13950), -INT16_C( 13005), -INT16_C( 10446),  INT16_C(  1862), -INT16_C( 25162),
        -INT16_C( 32624),  INT16_C(  3279),  INT16_C(   825), -INT16_C(  8830), -INT16_C(  9180), -INT16_C( 30508),  INT16_C( 11457),  INT16_C(  3023) },
      {  INT16_C(   201),  INT16_C(   147),  INT16_C(   186),  INT16_C(     0),  INT16_C(   303),  INT16_C(   504),  INT16_C(   241),  INT16_C(   445),
         INT16_C(   274),  INT16_C(   101),  INT16_C(   370),  INT16_C(   236),  INT16_C(    65),  INT16_C(   492),  INT16_C(   458),  INT16_C(   140),
         INT16_C(   438),  INT16_C(   251),  INT16_C(   312),  INT16_C(   108),  INT16_C(   410),  INT16_C(   430),  INT16_C(    14),  INT16_C(   315),
         INT16_C(   257),  INT16_C(    25),  INT16_C(     6),  INT16_C(   443),  INT16_C(   440),  INT16_C(   273),  INT16_C(    89),  INT16_C(    23) } },
    { {  INT16_C( 24327),  INT16_C( 16264),  INT16_C(  1787),  INT16_C( 12149), -INT16_C( 22572),  INT16_C(  6662), -INT16_C( 17234),  INT16_C( 16311),
        -INT16_C( 30915),  INT16_C( 30283), -INT16_C( 12662), -INT16_C( 20908),  INT16_C( 10410),  INT16_C( 27447),  INT16_C(  1620),  INT16_C( 23414),
        -INT16_C(   155),  INT16_C( 24730),  INT16_C(  4101), -INT16_C(  9841), -INT16_C( 26953),  INT16_C( 26355), -INT16_C( 21678), -INT16_C( 28763),
        -INT16_C(  4046), -INT16_C( 17402),  INT16_C( 23230),  INT16_C( 26731), -INT16_C( 23934), -INT16_C( 10540),  INT16_C( 19112),  INT16_C(  3377) },
      {  INT16_C(   190),  INT16_C(   127),  INT16_C(    13),  INT16_C(    94),  INT16_C(   335),  INT16_C(    52),  INT16_C(   377),  INT16_C(   127),
         INT16_C(   270),  INT16_C(   236),  INT16_C(   413),  INT16_C(   348),  INT16_C(    81),  INT16_C(   214),  INT16_C(    12),  INT16_C(   182),
         INT16_C(   510),  INT16_C(   193),  INT16_C(    32),  INT16_C(   435),  INT16_C(   301),  INT16_C(   205),  INT16_C(   342),  INT16_C(   287),
         INT16_C(   480),  INT16_C(   376),  INT16_C(   181),  INT16_C(   208),  INT16_C(   325),  INT16_C(   429),  INT16_C(   149),  INT16_C(    26) } },
    { { -INT16_C( 13495),  INT16_C( 20333), -INT16_C(   549), -INT16_C( 27864),  INT16_C(  7315), -INT16_C(  6663), -INT16_C( 24889), -INT16_C(  1675),
         INT16_C( 31630),  INT16_C( 19893),  INT16_C(  8405),  INT16_C( 22453), -INT16_C( 30270),  INT16_C( 27181),  INT16_C( 24276),  INT16_C(  7543),
        -INT16_C(  6871),  INT16_C(  1388), -INT16_C( 27166),  INT16_C( 30104), -INT16_C( 28239),  INT16_C( 30810), -INT16_C( 12497), -INT16_C( 17039),
         INT16_C(  9802),  INT16_C(  7946), -INT16_C( 16313),  INT16_C(  2422), -INT16_C( 23735),  INT16_C(  7540), -INT16_C(  5375),  INT16_C( 11067) },
      {  INT16_C(   406),  INT16_C(   158),  INT16_C(   507),  INT16_C(   294),  INT16_C(    57),  INT16_C(   459),  INT16_C(   317),  INT16_C(   498),
         INT16_C(   247),  INT16_C(   155),  INT16_C(    65),  INT16_C(   175),  INT16_C(   275),  INT16_C(   212),  INT16_C(   189),  INT16_C(    58),
         INT16_C(   458),  INT16_C(    10),  INT16_C(   299),  INT16_C(   235),  INT16_C(   291),  INT16_C(   240),  INT16_C(   414),  INT16_C(   378),
         INT16_C(    76),  INT16_C(    62),  INT16_C(   384),  INT16_C(    18),  INT16_C(   326),  INT16_C(    58),  INT16_C(   470),  INT16_C(    86) } },
    { { -INT16_C( 22576), -INT16_C( 19920), -INT16_C( 14276), -INT16_C(  4825), -INT16_C( 32167), -INT16_C( 30619), -INT16_C( 10671), -INT16_C( 25531),
         INT16_C( 20733),  INT16_C( 17595),  INT16_C( 12816),  INT16_C( 22861), -INT16_C( 15915), -INT16_C( 10377), -INT16_C( 19795),  INT16_C( 32002),
         INT16_C( 12889), -INT16_C( 27088),  INT16_C( 22522),  INT16_C( 21379), -INT16_C(  5671),  INT16_C( 11227),  INT16_C(  8383), -INT16_C( 17209),
        -INT16_C( 32144),       INT16_MIN,  INT16_C( 20148), -INT16_C( 29990),  INT16_C( 20751), -INT16_C( 17311),  INT16_C( 25347),  INT16_C( 23610) },
      {  INT16_C(   335),  INT16_C(   356),  INT16_C(   400),  INT16_C(   474),  INT16_C(   260),  INT16_C(   272),  INT16_C(   428),  INT16_C(   312),
         INT16_C(   161),  INT16_C(   137),  INT16_C(   100),  INT16_C(   178),  INT16_C(   387),  INT16_C(   430),  INT16_C(   357),  INT16_C(   250),
         INT16_C(   100),  INT16_C(   300),  INT16_C(   175),  INT16_C(   167),  INT16_C(   467),  INT16_C(    87),  INT16_C(    65),  INT16_C(   377),
         INT16_C(   260),  INT16_C(   256),  INT16_C(   157),  INT16_C(   277),  INT16_C(   162),  INT16_C(   376),  INT16_C(   198),  INT16_C(   184) } },
    { {  INT16_C( 27285), -INT16_C( 28686),  INT16_C( 30401), -INT16_C( 25630), -INT16_C( 17057),  INT16_C(  7878), -INT16_C( 29219),  INT16_C( 20187),
        -INT16_C(  9457), -INT16_C( 15154), -INT16_C( 22487),  INT16_C( 14670), -INT16_C( 20487), -INT16_C(   779),  INT16_C( 12050), -INT16_C( 22695),
         INT16_C( 19353),  INT16_C( 23350),  INT16_C(  6337),  INT16_C(  8438), -INT16_C( 17195), -INT16_C( 19905),  INT16_C(  6729),  INT16_C( 22528),
        -INT16_C( 12299),  INT16_C(  7964),  INT16_C( 27255),  INT16_C( 29016),  INT16_C( 19737),  INT16_C( 11117), -INT16_C( 14723),  INT16_C(  5842) },
      {  INT16_C(   213),  INT16_C(   287),  INT16_C(   237),  INT16_C(   311),  INT16_C(   378),  INT16_C(    61),  INT16_C(   283),  INT16_C(   157),
         INT16_C(   438),  INT16_C(   393),  INT16_C(   336),  INT16_C(   114),  INT16_C(   351),  INT16_C(   505),  INT16_C(    94),  INT16_C(   334),
         INT16_C(   151),  INT16_C(   182),  INT16_C(    49),  INT16_C(    65),  INT16_C(   377),  INT16_C(   356),  INT16_C(    52),  INT16_C(   176),
         INT16_C(   415),  INT16_C(    62),  INT16_C(   212),  INT16_C(   226),  INT16_C(   154),  INT16_C(    86),  INT16_C(   396),  INT16_C(    45) } },
    { {  INT16_C(  2066), -INT16_C( 11407),  INT16_C( 26400), -INT16_C(  2572),  INT16_C( 13091),  INT16_C( 27816), -INT16_C( 22451),  INT16_C( 17093),
        -INT16_C(  7817), -INT16_C(  4255), -INT16_C( 18100),  INT16_C( 25952), -INT16_C( 13049), -INT16_C( 31599),  INT16_C( 25492), -INT16_C( 22886),
         INT16_C(  3180), -INT16_C( 29575),  INT16_C( 28019), -INT16_C( 26750),  INT16_C( 10912), -INT16_C(  4861), -INT16_C( 14126),  INT16_C( 18992),
        -INT16_C( 28246), -INT16_C(  2503), -INT16_C( 26293),  INT16_C( 21083), -INT16_C(  5018), -INT16_C(  1322),  INT16_C( 28752), -INT16_C( 17248) },
      {  INT16_C(    16),  INT16_C(   422),  INT16_C(   206),  INT16_C(   491),  INT16_C(   102),  INT16_C(   217),  INT16_C(   336),  INT16_C(   133),
         INT16_C(   450),  INT16_C(   478),  INT16_C(   370),  INT16_C(   202),  INT16_C(   410),  INT16_C(   265),  INT16_C(   199),  INT16_C(   333),
         INT16_C(    24),  INT16_C(   280),  INT16_C(   218),  INT16_C(   303),  INT16_C(    85),  INT16_C(   474),  INT16_C(   401),  INT16_C(   148),
         INT16_C(   291),  INT16_C(   492),  INT16_C(   306),  INT16_C(   164),  INT16_C(   472),  INT16_C(   501),  INT16_C(   224),  INT16_C(   377) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_epi16(test_vec[i].a);
    simde__m512i r = simde_mm512_srli_epi16(a, 7);
    simde_test_x86_assert_equal_i16x32(r, simde_mm512_loadu_epi16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_mm512_srli_epi32(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m512i a;
    unsigned int imm8;
    simde__m512i r;
  } test_vec[8] = {
     { simde_mm512_set_epi32(INT32_C(-2020822652), INT32_C( -257395769), INT32_C(  499270536), INT32_C( 1400500940),
                            INT32_C( 1373098033), INT32_C( 1102869287), INT32_C( 1033807112), INT32_C(-1561080563),
                            INT32_C( 1506432231), INT32_C(-1063413574), INT32_C(  341686905), INT32_C( -287206476),
                            INT32_C(  265122437), INT32_C( 1398620072), INT32_C( -665611582), INT32_C(-1504345300)),
      22,
      simde_mm512_set_epi32(INT32_C(        542), INT32_C(        962), INT32_C(        119), INT32_C(        333),
                            INT32_C(        327), INT32_C(        262), INT32_C(        246), INT32_C(        651),
                            INT32_C(        359), INT32_C(        770), INT32_C(         81), INT32_C(        955),
                            INT32_C(         63), INT32_C(        333), INT32_C(        865), INT32_C(        665)) },
    { simde_mm512_set_epi32(INT32_C( -819412546), INT32_C(-1796000475), INT32_C(-1622143581), INT32_C(-1041781306),
                            INT32_C( -155789533), INT32_C( -151174821), INT32_C( 1958936143), INT32_C( -107637458),
                            INT32_C(-1381646204), INT32_C( 1022043250), INT32_C( -104481290), INT32_C(-1025833596),
                            INT32_C( 1618482767), INT32_C( 1888220027), INT32_C(-1169248526), INT32_C( -703447035)),
      11,
      simde_mm512_set_epi32(INT32_C(    1697048), INT32_C(    1220198), INT32_C(    1305089), INT32_C(    1588469),
                            INT32_C(    2021082), INT32_C(    2023336), INT32_C(     956511), INT32_C(    2044594),
                            INT32_C(    1422520), INT32_C(     499044), INT32_C(    2046135), INT32_C(    1596256),
                            INT32_C(     790274), INT32_C(     921982), INT32_C(    1526229), INT32_C(    1753672)) },
    { simde_mm512_set_epi32(INT32_C(-1594292345), INT32_C( -684588879), INT32_C( 1676697175), INT32_C( -659819552),
                            INT32_C( 1894934939), INT32_C(  577900071), INT32_C(  818876053), INT32_C(  557599341),
                            INT32_C( -791753790), INT32_C(  286117889), INT32_C( 1667395914), INT32_C( -574374162),
                            INT32_C(  516383634), INT32_C( 1867216785), INT32_C( 1360165420), INT32_C(-1026060155)),
      3,
      simde_mm512_set_epi32(INT32_C(  337584368), INT32_C(  451297302), INT32_C(  209587146), INT32_C(  454393468),
                            INT32_C(  236866867), INT32_C(   72237508), INT32_C(  102359506), INT32_C(   69699917),
                            INT32_C(  437901688), INT32_C(   35764736), INT32_C(  208424489), INT32_C(  465074141),
                            INT32_C(   64547954), INT32_C(  233402098), INT32_C(  170020677), INT32_C(  408613392)) },
    { simde_mm512_set_epi32(INT32_C(  563818649), INT32_C( 1327166173), INT32_C( 1236848070), INT32_C( -448866475),
                            INT32_C( -173418493), INT32_C(-1571972356), INT32_C( 1881284471), INT32_C(  439987043),
                            INT32_C(  508631938), INT32_C(  763400402), INT32_C( 2004762594), INT32_C(-1789579909),
                            INT32_C( -823229171), INT32_C(-1537029967), INT32_C(-2094893814), INT32_C( 1910734558)),
      0,
      simde_mm512_set_epi32(INT32_C(  563818649), INT32_C( 1327166173), INT32_C( 1236848070), INT32_C( -448866475),
                            INT32_C( -173418493), INT32_C(-1571972356), INT32_C( 1881284471), INT32_C(  439987043),
                            INT32_C(  508631938), INT32_C(  763400402), INT32_C( 2004762594), INT32_C(-1789579909),
                            INT32_C( -823229171), INT32_C(-1537029967), INT32_C(-2094893814), INT32_C( 1910734558)) },
    { simde_mm512_set_epi32(INT32_C( 1331571680), INT32_C(-1968130549), INT32_C(-1401578233), INT32_C(-1310278942),
                            INT32_C( -553135974), INT32_C(  390049321), INT32_C( -502176380), INT32_C( -721913400),
                            INT32_C(  297997941), INT32_C(  812527594), INT32_C(-1593317379), INT32_C( -643296593),
                            INT32_C(-1978632480), INT32_C(-2010319907), INT32_C(-1081044111), INT32_C(  223565748)),
      26,
      simde_mm512_set_epi32(INT32_C(         19), INT32_C(         34), INT32_C(         43), INT32_C(         44),
                            INT32_C(         55), INT32_C(          5), INT32_C(         56), INT32_C(         53),
                            INT32_C(          4), INT32_C(         12), INT32_C(         40), INT32_C(         54),
                            INT32_C(         34), INT32_C(         34), INT32_C(         47), INT32_C(          3)) },
    { simde_mm512_set_epi32(INT32_C(   69766264), INT32_C( 1121309360), INT32_C( -164257344), INT32_C( 1544624998),
                            INT32_C(-1638151086), INT32_C(  617641637), INT32_C(-2109782153), INT32_C( -381251627),
                            INT32_C(  648330089), INT32_C( -370018417), INT32_C(-1896387892), INT32_C(-1167774485),
                            INT32_C( -297453838), INT32_C( -617551956), INT32_C(  863958459), INT32_C( 1052098740)),
      1,
      simde_mm512_set_epi32(INT32_C(   34883132), INT32_C(  560654680), INT32_C( 2065354976), INT32_C(  772312499),
                            INT32_C( 1328408105), INT32_C(  308820818), INT32_C( 1092592571), INT32_C( 1956857834),
                            INT32_C(  324165044), INT32_C( 1962474439), INT32_C( 1199289702), INT32_C( 1563596405),
                            INT32_C( 1998756729), INT32_C( 1838707670), INT32_C(  431979229), INT32_C(  526049370)) },
    { simde_mm512_set_epi32(INT32_C( -185630809), INT32_C( -795283306), INT32_C( 1353888329), INT32_C( 1750377549),
                            INT32_C( -609950002), INT32_C(-2070799804), INT32_C( -717783400), INT32_C( -489437394),
                            INT32_C(  782151967), INT32_C( -135381456), INT32_C(-1044185983), INT32_C(-1168288861),
                            INT32_C( 1570077349), INT32_C(-1514349775), INT32_C(-1300428717), INT32_C(-1070450073)),
      14,
      simde_mm512_set_epi32(INT32_C(     250813), INT32_C(     213603), INT32_C(      82634), INT32_C(     106834),
                            INT32_C(     224915), INT32_C(     135752), INT32_C(     218333), INT32_C(     232271),
                            INT32_C(      47738), INT32_C(     253880), INT32_C(     198411), INT32_C(     190837),
                            INT32_C(      95829), INT32_C(     169715), INT32_C(     182772), INT32_C(     196808)) },
    { simde_mm512_set_epi32(INT32_C(  858780966), INT32_C(  471539970), INT32_C(  308326365), INT32_C(  897623009),
                            INT32_C(  274412137), INT32_C(-1363032868), INT32_C( 2080428503), INT32_C( 1048755350),
                            INT32_C( -342337536), INT32_C( 1475004820), INT32_C( 1074270282), INT32_C( -894671787),
                            INT32_C(-2107817427), INT32_C( -444084191), INT32_C(  851286899), INT32_C( 1423269304)),
      1,
      simde_mm512_set_epi32(INT32_C(  429390483), INT32_C(  235769985), INT32_C(  154163182), INT32_C(  448811504),
                            INT32_C(  137206068), INT32_C( 1465967214), INT32_C( 1040214251), INT32_C(  524377675),
                            INT32_C( 1976314880), INT32_C(  737502410), INT32_C(  537135141), INT32_C( 1700147754),
                            INT32_C( 1093574934), INT32_C( 1925441552), INT32_C(  425643449), INT32_C(  711634652)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i r = simde_mm512_srli_epi32(test_vec[i].a,test_vec[i].imm8);
    simde_assert_m512i_i32(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm512_srli_epi64(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m512i a;
    unsigned int b;
    simde__m512i r;
  } test_vec[8] = {
    { simde_mm512_set_epi64(INT64_C( 7973262903512536694), INT64_C( -756652926976123625),
                            INT64_C(-7907329678808178856), INT64_C(-4613066309848201378),
                            INT64_C(  911796452309072772), INT64_C(-7947449538018331043),
                            INT64_C(-4094891379879736374), INT64_C( 2567785713935265105)),
      0xab,
      simde_mm512_set_epi64(INT64_C(                   0), INT64_C(                   0),
                            INT64_C(                   0), INT64_C(                   0),
                            INT64_C(                   0), INT64_C(                   0),
                            INT64_C(                   0), INT64_C(                   0)) },
    { simde_mm512_set_epi64(INT64_C(-8733599303468285770), INT64_C(-1221042997940104437),
                            INT64_C( 1700326984023276146), INT64_C(  299160601816116482),
                            INT64_C(-8645581509002533463), INT64_C(-8083364442012234823),
                            INT64_C(-5545717914343726512), INT64_C(  419833451025710133)),
      0x8029,
      simde_mm512_set_epi64(INT64_C(                   0), INT64_C(                   0),
                            INT64_C(                   0), INT64_C(                   0),
                            INT64_C(                   0), INT64_C(                   0),
                            INT64_C(                   0), INT64_C(                   0)) },
    { simde_mm512_set_epi64(INT64_C(-4893117706119522679), INT64_C( 5420919605114671392),
                            INT64_C( 5087336166907414861), INT64_C( -562883644934737039),
                            INT64_C(-3838729031805448294), INT64_C(-7418143174233432135),
                            INT64_C( 7017318210470297490), INT64_C( 3464955922400203693)),
      0xe,
      simde_mm512_set_epi64(INT64_C(     827247703099977), INT64_C(     330866675116862),
                            INT64_C(     310506357843470), INT64_C(    1091544215623462),
                            INT64_C(     891602480584967), INT64_C(     673132379118415),
                            INT64_C(     428303113432024), INT64_C(     211484126123059)) },
    { simde_mm512_set_epi64(INT64_C( 2541614580543521019), INT64_C(  499823435321299561),
                            INT64_C(-5904924501366764508), INT64_C( 7023944739814045444),
                            INT64_C( 6015406288340926104), INT64_C( 7321833489159498588),
                            INT64_C(-2737849912327243109), INT64_C(-3578554550642761007)),
      0x32,
      simde_mm512_set_epi64(INT64_C(                2257), INT64_C(                 443),
                            INT64_C(               11139), INT64_C(                6238),
                            INT64_C(                5342), INT64_C(                6503),
                            INT64_C(               13952), INT64_C(               13205)) },
    { simde_mm512_set_epi64(INT64_C(-5028928596309812666), INT64_C(-4599097054342878650),
                            INT64_C( 1737746464556527965), INT64_C( 7519897503489365685),
                            INT64_C( 2668093889339798821), INT64_C(-3758388356888738937),
                            INT64_C(-2613982157457207556), INT64_C(-2225410235035714021)),
      0x30,
      simde_mm512_set_epi64(INT64_C(               47669), INT64_C(               49196),
                            INT64_C(                6173), INT64_C(               26716),
                            INT64_C(                9478), INT64_C(               52183),
                            INT64_C(               56249), INT64_C(               57629)) },
    { simde_mm512_set_epi64(INT64_C(-5661929570079819163), INT64_C(  606174630548676143),
                            INT64_C( 4062026724724267051), INT64_C(-7721509817758052189),
                            INT64_C(-4899766988012067491), INT64_C(  849655025943263586),
                            INT64_C(-7243604229092766255), INT64_C(-3011226666080476035)),
      0x29,
      simde_mm512_set_epi64(INT64_C(             5813860), INT64_C(              275656),
                            INT64_C(             1847195), INT64_C(             4877271),
                            INT64_C(             6160451), INT64_C(              386378),
                            INT64_C(             5094598), INT64_C(             7019260)) },
    { simde_mm512_set_epi64(INT64_C( 3357536311959110775), INT64_C( 4508830932063799722),
                            INT64_C(-5800425134717732029), INT64_C( 1782066721260114087),
                            INT64_C( -181633913032181218), INT64_C(-5152953019677919849),
                            INT64_C( 3009514543526146963), INT64_C( -248934049093542484)),
      0x31,
      simde_mm512_set_epi64(INT64_C(                5964), INT64_C(                8009),
                            INT64_C(               22464), INT64_C(                3165),
                            INT64_C(               32445), INT64_C(               23614),
                            INT64_C(                5345), INT64_C(               32325)) },
    { simde_mm512_set_epi64(INT64_C( 7443398932235525007), INT64_C(-1954475805396281420),
                            INT64_C( 2896517201997827064), INT64_C(-7120983626837339415),
                            INT64_C( -201538146421797804), INT64_C(   96284688433294814),
                            INT64_C(  317424323145668713), INT64_C(-2012972091494378925)),
      0x24,
      simde_mm512_set_epi64(INT64_C(           108315710), INT64_C(           239994089),
                            INT64_C(            42149872), INT64_C(           164811505),
                            INT64_C(           265502689), INT64_C(             1401126),
                            INT64_C(             4619131), INT64_C(           239142856)) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i r = simde_mm512_srli_epi64(test_vec[i].a, test_vec[i].b);
    simde_assert_m512i_i64(r, ==, test_vec[i].r);
  }

  return 0;
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_srli_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_srli_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_srli_epi64)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/avx512/test-avx512-footer.h>
