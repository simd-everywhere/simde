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

#define SIMDE_TEST_X86_AVX512_INSN sllv

#include <test/x86/avx512/test-avx512.h>
#include <simde/x86/avx512/sllv.h>

static int
test_simde_mm512_sllv_epi16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const int16_t a[32];
    const int16_t b[32];
    const int16_t r[32];
  } test_vec[] = {
    { {  INT16_C( 22565),  INT16_C(  7765), -INT16_C(  5967),  INT16_C(  8467),  INT16_C( 20064),  INT16_C( 22451),  INT16_C(  4892), -INT16_C( 11833),
        -INT16_C( 29997),  INT16_C( 21077), -INT16_C( 20080),  INT16_C( 23507),  INT16_C( 27770), -INT16_C( 29233), -INT16_C(  7519), -INT16_C( 14708),
        -INT16_C(  7621), -INT16_C(  4892), -INT16_C(  2102),  INT16_C( 10765), -INT16_C( 16059),  INT16_C( 24961),  INT16_C( 18644), -INT16_C( 22733),
        -INT16_C( 30510),  INT16_C( 25594), -INT16_C( 12999), -INT16_C( 19522), -INT16_C( 29383), -INT16_C(  9663), -INT16_C( 12944), -INT16_C( 21600) },
      {  INT16_C(    16),  INT16_C(    15),  INT16_C(    20),  INT16_C(    24),  INT16_C(     4),  INT16_C(     7),  INT16_C(    10),  INT16_C(     8),
         INT16_C(    27),  INT16_C(     2),  INT16_C(    12),  INT16_C(    28),  INT16_C(     1),  INT16_C(    11),  INT16_C(    11),  INT16_C(    16),
         INT16_C(    20),  INT16_C(    11),  INT16_C(    20),  INT16_C(    21),  INT16_C(     7),  INT16_C(     7),  INT16_C(    24),  INT16_C(    13),
         INT16_C(     3),  INT16_C(     9),  INT16_C(     9),  INT16_C(    14),  INT16_C(    28),  INT16_C(     6),  INT16_C(    27),  INT16_C(     3) },
      {  INT16_C(     0),       INT16_MIN,  INT16_C(     0),  INT16_C(     0), -INT16_C(  6656), -INT16_C(  9856),  INT16_C( 28672), -INT16_C( 14592),
         INT16_C(     0),  INT16_C( 18772),  INT16_C(     0),  INT16_C(     0), -INT16_C(  9996),  INT16_C( 30720),  INT16_C(  2048),  INT16_C(     0),
         INT16_C(     0),  INT16_C(  8192),  INT16_C(     0),  INT16_C(     0), -INT16_C( 23936), -INT16_C( 16256),  INT16_C(     0),  INT16_C( 24576),
         INT16_C( 18064), -INT16_C(  3072),  INT16_C( 29184),       INT16_MIN,  INT16_C(     0), -INT16_C( 28608),  INT16_C(     0),  INT16_C( 23808) } },
    { { -INT16_C( 18052), -INT16_C( 15751), -INT16_C( 27809),  INT16_C( 11118),  INT16_C( 21456),  INT16_C( 24934), -INT16_C(  7911), -INT16_C( 17712),
         INT16_C( 21505), -INT16_C( 32253),  INT16_C( 11682), -INT16_C(  1037), -INT16_C( 15342),  INT16_C( 21035), -INT16_C(  7265),  INT16_C(  7025),
        -INT16_C(  5475), -INT16_C(   802),  INT16_C( 19581),  INT16_C( 19752), -INT16_C( 29025), -INT16_C( 18257),  INT16_C( 32623),  INT16_C( 28786),
         INT16_C( 30163),  INT16_C( 30451), -INT16_C(  6494), -INT16_C( 19343), -INT16_C( 25430),  INT16_C( 18694),  INT16_C( 30592),  INT16_C(  7525) },
      {  INT16_C(     8),  INT16_C(    27),  INT16_C(     8),  INT16_C(     5),  INT16_C(    27),  INT16_C(     7),  INT16_C(    11),  INT16_C(     5),
         INT16_C(    20),  INT16_C(    13),  INT16_C(     2),  INT16_C(     6),  INT16_C(     5),  INT16_C(     6),  INT16_C(    28),  INT16_C(     0),
         INT16_C(    12),  INT16_C(    22),  INT16_C(     1),  INT16_C(    15),  INT16_C(    25),  INT16_C(     8),  INT16_C(    12),  INT16_C(    29),
         INT16_C(     2),  INT16_C(    18),  INT16_C(    15),  INT16_C(    26),  INT16_C(     8),  INT16_C(     9),  INT16_C(    10),  INT16_C(     9) },
      {  INT16_C( 31744),  INT16_C(     0),  INT16_C( 24320),  INT16_C( 28096),  INT16_C(     0), -INT16_C( 19712), -INT16_C( 14336),  INT16_C( 23040),
         INT16_C(     0),  INT16_C( 24576), -INT16_C( 18808), -INT16_C(   832), -INT16_C( 32192), -INT16_C( 30016),  INT16_C(     0),  INT16_C(  7025),
        -INT16_C( 12288),  INT16_C(     0), -INT16_C( 26374),  INT16_C(     0),  INT16_C(     0), -INT16_C( 20736), -INT16_C(  4096),  INT16_C(     0),
        -INT16_C( 10420),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C( 22016),  INT16_C(  3072),  INT16_C(     0), -INT16_C( 13824) } },
    { {  INT16_C( 10429),  INT16_C( 26366), -INT16_C(  8140),  INT16_C(  6879), -INT16_C( 26968), -INT16_C( 14245), -INT16_C( 13827),  INT16_C(  1973),
         INT16_C(  4570),  INT16_C(   153),  INT16_C( 24464),  INT16_C( 14551), -INT16_C(  8286), -INT16_C( 14464), -INT16_C( 14027), -INT16_C(  3311),
         INT16_C(  4081),  INT16_C(  9561),  INT16_C( 14575), -INT16_C( 26816), -INT16_C( 25649), -INT16_C( 13217),  INT16_C(  5220),  INT16_C( 16083),
         INT16_C( 27941), -INT16_C( 19137),  INT16_C(  5836),  INT16_C( 28653),  INT16_C( 28150),  INT16_C( 11062),  INT16_C( 18486),  INT16_C( 10270) },
      {  INT16_C(    15),  INT16_C(     8),  INT16_C(    17),  INT16_C(    15),  INT16_C(     7),  INT16_C(    17),  INT16_C(     3),  INT16_C(    15),
         INT16_C(     1),  INT16_C(    11),  INT16_C(     3),  INT16_C(     2),  INT16_C(    31),  INT16_C(    23),  INT16_C(    12),  INT16_C(    19),
         INT16_C(     6),  INT16_C(    17),  INT16_C(    24),  INT16_C(    29),  INT16_C(    10),  INT16_C(    10),  INT16_C(     8),  INT16_C(     0),
         INT16_C(    31),  INT16_C(    13),  INT16_C(     4),  INT16_C(    19),  INT16_C(    24),  INT16_C(    12),  INT16_C(     8),  INT16_C(    31) },
      {       INT16_MIN, -INT16_C(   512),  INT16_C(     0),       INT16_MIN,  INT16_C( 21504),  INT16_C(     0),  INT16_C( 20456),       INT16_MIN,
         INT16_C(  9140), -INT16_C( 14336), -INT16_C(   896), -INT16_C(  7332),  INT16_C(     0),  INT16_C(     0),  INT16_C( 20480),  INT16_C(     0),
        -INT16_C(   960),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C( 15360),  INT16_C( 31744),  INT16_C( 25600),  INT16_C( 16083),
         INT16_C(     0), -INT16_C(  8192),  INT16_C( 27840),  INT16_C(     0),  INT16_C(     0),  INT16_C( 24576),  INT16_C( 13824),  INT16_C(     0) } },
    { { -INT16_C(  5769),  INT16_C( 14727), -INT16_C( 28755), -INT16_C( 20956), -INT16_C( 25628),  INT16_C( 22530), -INT16_C( 12579),  INT16_C( 10584),
        -INT16_C( 19768), -INT16_C(  9067),  INT16_C(  6355), -INT16_C(  3207), -INT16_C( 10787),  INT16_C(   858),  INT16_C( 24088), -INT16_C( 28671),
        -INT16_C( 30648), -INT16_C(  2615), -INT16_C(  4841), -INT16_C(  1117), -INT16_C( 22904),  INT16_C( 25939), -INT16_C( 21388),  INT16_C( 15502),
         INT16_C(  9310),  INT16_C( 12569), -INT16_C( 28100),  INT16_C(  6693),  INT16_C( 32616), -INT16_C( 32739),  INT16_C(  7901),  INT16_C(  9488) },
      {  INT16_C(    27),  INT16_C(    23),  INT16_C(    23),  INT16_C(    10),  INT16_C(     1),  INT16_C(    27),  INT16_C(     8),  INT16_C(     2),
         INT16_C(     5),  INT16_C(    20),  INT16_C(    13),  INT16_C(     5),  INT16_C(    27),  INT16_C(    25),  INT16_C(    23),  INT16_C(    19),
         INT16_C(     1),  INT16_C(    11),  INT16_C(     2),  INT16_C(     5),  INT16_C(    12),  INT16_C(    27),  INT16_C(     3),  INT16_C(     1),
         INT16_C(     7),  INT16_C(     0),  INT16_C(    13),  INT16_C(    18),  INT16_C(    27),  INT16_C(     8),  INT16_C(     9),  INT16_C(     4) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C( 28672),  INT16_C( 14280),  INT16_C(     0), -INT16_C(  8960), -INT16_C( 23200),
         INT16_C( 22784),  INT16_C(     0),  INT16_C( 24576),  INT16_C( 28448),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C(  4240),  INT16_C( 18432), -INT16_C( 19364),  INT16_C( 29792),       INT16_MIN,  INT16_C(     0),  INT16_C( 25504),  INT16_C( 31004),
         INT16_C( 12032),  INT16_C( 12569),       INT16_MIN,  INT16_C(     0),  INT16_C(     0),  INT16_C(  7424), -INT16_C( 17920),  INT16_C( 20736) } },
    { {  INT16_C( 16724),  INT16_C(  7297),  INT16_C( 11351),  INT16_C( 31047),  INT16_C( 19340),  INT16_C( 12628),  INT16_C( 18020), -INT16_C( 21699),
        -INT16_C(  4481),  INT16_C(  9907), -INT16_C(  7330), -INT16_C( 22088),  INT16_C(  5308),  INT16_C( 20205), -INT16_C( 11937), -INT16_C( 19340),
        -INT16_C(  2798),  INT16_C( 27088),  INT16_C(  5921), -INT16_C( 20765),  INT16_C( 14179), -INT16_C( 14369),  INT16_C(  7293), -INT16_C(   653),
         INT16_C(  9739),  INT16_C( 26915), -INT16_C(  9463), -INT16_C( 15086), -INT16_C(    16),  INT16_C( 20243), -INT16_C( 30511), -INT16_C(  7421) },
      {  INT16_C(    26),  INT16_C(    19),  INT16_C(     6),  INT16_C(     9),  INT16_C(     5),  INT16_C(    28),  INT16_C(    17),  INT16_C(    10),
         INT16_C(     0),  INT16_C(    22),  INT16_C(    25),  INT16_C(    26),  INT16_C(    18),  INT16_C(    19),  INT16_C(     4),  INT16_C(    18),
         INT16_C(    25),  INT16_C(    28),  INT16_C(    16),  INT16_C(    12),  INT16_C(     8),  INT16_C(    30),  INT16_C(     5),  INT16_C(    15),
         INT16_C(     0),  INT16_C(     2),  INT16_C(    22),  INT16_C(    20),  INT16_C(     0),  INT16_C(    11),  INT16_C(    24),  INT16_C(     3) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(  5568), -INT16_C( 29184),  INT16_C( 29056),  INT16_C(     0),  INT16_C(     0), -INT16_C(  3072),
        -INT16_C(  4481),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(  5616),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C( 12288),  INT16_C( 25344),  INT16_C(     0), -INT16_C( 28768),       INT16_MIN,
         INT16_C(  9739), -INT16_C( 23412),  INT16_C(     0),  INT16_C(     0), -INT16_C(    16), -INT16_C( 26624),  INT16_C(     0),  INT16_C(  6168) } },
    { {  INT16_C(  8851), -INT16_C( 27904),  INT16_C( 12452),  INT16_C( 20986),  INT16_C( 18038),  INT16_C( 17479), -INT16_C( 28300), -INT16_C( 22592),
        -INT16_C(  2921),  INT16_C( 27578), -INT16_C( 24923), -INT16_C(  6898),  INT16_C( 20386), -INT16_C( 13762),  INT16_C( 11283), -INT16_C( 22552),
        -INT16_C(  5810), -INT16_C(  3526),  INT16_C( 13337), -INT16_C( 28860), -INT16_C( 29830), -INT16_C(  4397), -INT16_C( 27620), -INT16_C( 19563),
         INT16_C( 20360),  INT16_C( 11551),  INT16_C( 11758), -INT16_C( 28653),  INT16_C( 20860), -INT16_C( 28582),  INT16_C( 17277), -INT16_C( 13513) },
      {  INT16_C(    14),  INT16_C(     8),  INT16_C(     0),  INT16_C(     3),  INT16_C(    21),  INT16_C(    21),  INT16_C(    20),  INT16_C(    24),
         INT16_C(    15),  INT16_C(    27),  INT16_C(     0),  INT16_C(     4),  INT16_C(    25),  INT16_C(    26),  INT16_C(    29),  INT16_C(     7),
         INT16_C(    11),  INT16_C(     0),  INT16_C(    10),  INT16_C(    29),  INT16_C(     5),  INT16_C(     7),  INT16_C(    30),  INT16_C(    24),
         INT16_C(    30),  INT16_C(     3),  INT16_C(     2),  INT16_C(     9),  INT16_C(    30),  INT16_C(    29),  INT16_C(    23),  INT16_C(     8) },
      { -INT16_C( 16384),  INT16_C(     0),  INT16_C( 12452), -INT16_C( 28720),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
              INT16_MIN,  INT16_C(     0), -INT16_C( 24923),  INT16_C( 20704),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(  3072),
         INT16_C( 28672), -INT16_C(  3526),  INT16_C( 25600),  INT16_C(     0),  INT16_C( 28480),  INT16_C( 27008),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0),  INT16_C( 26872), -INT16_C( 18504),  INT16_C(  9728),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C( 14080) } },
    { { -INT16_C( 24036),  INT16_C( 31556),  INT16_C( 26358), -INT16_C(  3225), -INT16_C(   363),  INT16_C( 26156),  INT16_C( 10994),  INT16_C( 25128),
        -INT16_C( 13798),  INT16_C(  4220), -INT16_C( 17188), -INT16_C( 18083),  INT16_C( 32178), -INT16_C( 27229), -INT16_C( 14788),  INT16_C( 22742),
         INT16_C(  6761),  INT16_C( 24531),  INT16_C( 14976),  INT16_C(  5458),  INT16_C( 32312),  INT16_C( 10875), -INT16_C( 23384), -INT16_C( 15475),
         INT16_C(  2414),  INT16_C( 19411),  INT16_C( 12486),  INT16_C( 30724), -INT16_C( 22611), -INT16_C(  5874), -INT16_C(  7059), -INT16_C( 10687) },
      {  INT16_C(     2),  INT16_C(    15),  INT16_C(    17),  INT16_C(    16),  INT16_C(     2),  INT16_C(    21),  INT16_C(     7),  INT16_C(     4),
         INT16_C(     8),  INT16_C(     1),  INT16_C(    14),  INT16_C(     4),  INT16_C(    18),  INT16_C(    16),  INT16_C(     9),  INT16_C(    15),
         INT16_C(    18),  INT16_C(    22),  INT16_C(    17),  INT16_C(     4),  INT16_C(    29),  INT16_C(    10),  INT16_C(     8),  INT16_C(    14),
         INT16_C(    28),  INT16_C(     0),  INT16_C(     1),  INT16_C(    13),  INT16_C(     6),  INT16_C(     2),  INT16_C(    10),  INT16_C(    28) },
      { -INT16_C( 30608),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(  1452),  INT16_C(     0),  INT16_C( 30976),  INT16_C(  8832),
         INT16_C(  6656),  INT16_C(  8440),  INT16_C(     0), -INT16_C( 27184),  INT16_C(     0),  INT16_C(     0),  INT16_C( 30720),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C( 21792),  INT16_C(     0), -INT16_C(  5120), -INT16_C( 22528),  INT16_C( 16384),
         INT16_C(     0),  INT16_C( 19411),  INT16_C( 24972),       INT16_MIN, -INT16_C(  5312), -INT16_C( 23496), -INT16_C( 19456),  INT16_C(     0) } },
    { { -INT16_C( 30492),  INT16_C(   151), -INT16_C( 12011), -INT16_C( 19934), -INT16_C(  2883), -INT16_C(  6140),  INT16_C( 31033), -INT16_C( 15524),
        -INT16_C(  8612), -INT16_C( 20028), -INT16_C(  5657), -INT16_C( 31457),  INT16_C(  5148), -INT16_C( 25188),  INT16_C( 11365),  INT16_C( 19074),
         INT16_C(  6836), -INT16_C( 14006),  INT16_C( 27883), -INT16_C( 22148), -INT16_C( 32671), -INT16_C( 25967), -INT16_C(  4614),  INT16_C( 22109),
         INT16_C(  8907), -INT16_C( 19960),  INT16_C(  9995),  INT16_C( 10039), -INT16_C( 11205), -INT16_C( 24123),  INT16_C( 18176), -INT16_C( 18965) },
      {  INT16_C(     6),  INT16_C(     9),  INT16_C(    31),  INT16_C(     0),  INT16_C(    16),  INT16_C(    14),  INT16_C(    31),  INT16_C(     8),
         INT16_C(    26),  INT16_C(     4),  INT16_C(     5),  INT16_C(     6),  INT16_C(     2),  INT16_C(    31),  INT16_C(    24),  INT16_C(    23),
         INT16_C(     6),  INT16_C(    19),  INT16_C(     0),  INT16_C(    21),  INT16_C(     7),  INT16_C(    31),  INT16_C(    29),  INT16_C(     9),
         INT16_C(     6),  INT16_C(    22),  INT16_C(    24),  INT16_C(    11),  INT16_C(    24),  INT16_C(     6),  INT16_C(     1),  INT16_C(    15) },
      {  INT16_C( 14592),  INT16_C( 11776),  INT16_C(     0), -INT16_C( 19934),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C( 23552),
         INT16_C(     0),  INT16_C(  7232),  INT16_C( 15584),  INT16_C( 18368),  INT16_C( 20592),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
        -INT16_C( 21248),  INT16_C(     0),  INT16_C( 27883),  INT16_C(     0),  INT16_C( 12416),  INT16_C(     0),  INT16_C(     0), -INT16_C( 17920),
        -INT16_C( 19776),  INT16_C(     0),  INT16_C(     0), -INT16_C( 18432),  INT16_C(     0),  INT16_C( 28992), -INT16_C( 29184),       INT16_MIN } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_epi16(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi16(test_vec[i].b);
    simde__m512i r = simde_mm512_sllv_epi16(a, b);
    simde_test_x86_assert_equal_i16x32(r, simde_mm512_loadu_epi16(test_vec[i].r));
  }

  return 0;
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_sllv_epi16)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/avx512/test-avx512-footer.h>
