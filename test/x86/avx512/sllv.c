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

static int
test_simde_mm512_sllv_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t a[16];
    const int32_t b[16];
    const int32_t r[16];
  } test_vec[] = {
    { { -INT32_C(  1563396387),  INT32_C(   888640547), -INT32_C(  1184643408),  INT32_C(   662816507), -INT32_C(   495417630),  INT32_C(   554019217),  INT32_C(   968011970), -INT32_C(  2021223511),
         INT32_C(   740906505), -INT32_C(  1704975894), -INT32_C(   481049625),  INT32_C(  1795871881), -INT32_C(   330399141), -INT32_C(   317893845), -INT32_C(  1389969404),  INT32_C(  1546955859) },
      {  INT32_C(   877255597),  INT32_C(  1173226576),  INT32_C(    78707593), -INT32_C(   573742581), -INT32_C(  1583166736),  INT32_C(          18), -INT32_C(   142479181),  INT32_C(   497920318),
        -INT32_C(  1814739691),  INT32_C(           8), -INT32_C(  2057831716),  INT32_C(          12),  INT32_C(          26), -INT32_C(   164751037),  INT32_C(          19),  INT32_C(   407843752) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(  1505492992),  INT32_C(           0),  INT32_C(           0),
         INT32_C(           0),  INT32_C(  1612835328),  INT32_C(           0), -INT32_C(  1387753472),  INT32_C(  1811939328),  INT32_C(           0),  INT32_C(     2097152),  INT32_C(           0) } },
    { {  INT32_C(  1336101482), -INT32_C(  1958514852), -INT32_C(  1669238391),  INT32_C(  1723661558), -INT32_C(  1311567925), -INT32_C(  2064567542), -INT32_C(  1116466407), -INT32_C(  1311390905),
         INT32_C(  1761638413),  INT32_C(  1895056359), -INT32_C(  1441958220),  INT32_C(  1041287538), -INT32_C(   487595048),  INT32_C(   812048406),  INT32_C(   988666611), -INT32_C(  1427389795) },
      {  INT32_C(          26),  INT32_C(          30),  INT32_C(    19641443),  INT32_C(          22),  INT32_C(           7), -INT32_C(  1183835277),  INT32_C(          15),  INT32_C(           5),
         INT32_C(          25),  INT32_C(          15),  INT32_C(     5252331),  INT32_C(   368976163),  INT32_C(          10), -INT32_C(   471964201),  INT32_C(           6),  INT32_C(           9) },
      { -INT32_C(  1476395008),  INT32_C(           0),  INT32_C(           0),  INT32_C(  1031798784), -INT32_C(   376969856),  INT32_C(           0),  INT32_C(   160202752),  INT32_C(   985164000),
         INT32_C(   436207616),  INT32_C(   569606144),  INT32_C(           0),  INT32_C(           0), -INT32_C(  1081122816),  INT32_C(           0), -INT32_C(  1149846336), -INT32_C(   679134720) } },
    { {  INT32_C(  1898267391),  INT32_C(  1176668221), -INT32_C(   282839254), -INT32_C(  2100165732), -INT32_C(   565154802), -INT32_C(   575287404), -INT32_C(  1825529523),  INT32_C(   132026631),
         INT32_C(   276300755), -INT32_C(  1252615285),  INT32_C(  1873116114), -INT32_C(  1930332290),  INT32_C(  2020295140),  INT32_C(  1582637073), -INT32_C(   923695679), -INT32_C(   372257002) },
      {  INT32_C(  1227143389),  INT32_C(   583459185), -INT32_C(   440901880),  INT32_C(          16),  INT32_C(          21),  INT32_C(    99974168),  INT32_C(          28),  INT32_C(    25221840),
         INT32_C(   204659014), -INT32_C(   738284430),  INT32_C(           4),  INT32_C(          23),  INT32_C(   581098962),  INT32_C(           9),  INT32_C(           4),  INT32_C(          24) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(    60555264), -INT32_C(  2118123520),  INT32_C(           0), -INT32_C(   805306368),  INT32_C(           0),
         INT32_C(           0),  INT32_C(           0), -INT32_C(    94913248), -INT32_C(  1090519040),  INT32_C(           0), -INT32_C(  1438637568), -INT32_C(  1894228976),  INT32_C(   369098752) } },
    { {  INT32_C(   543004778), -INT32_C(    29163659), -INT32_C(  2069153888), -INT32_C(   393786812), -INT32_C(    83632165),  INT32_C(  1281212116), -INT32_C(   887082427), -INT32_C(   261302394),
        -INT32_C(   468661649),  INT32_C(  1776440009), -INT32_C(   840004215), -INT32_C(  1296730665),  INT32_C(   699250772), -INT32_C(  1133180042), -INT32_C(  1014524355), -INT32_C(   592186259) },
      {  INT32_C(   124575565),  INT32_C(          20),  INT32_C(  1176905370),  INT32_C(          10),  INT32_C(  1364749821),  INT32_C(          21),  INT32_C(          26),  INT32_C(  1096974968),
         INT32_C(          15),  INT32_C(  1383377924),  INT32_C(          13),  INT32_C(          15),  INT32_C(          18),  INT32_C(  1100432327),  INT32_C(          16),  INT32_C(  1269743538) },
      {  INT32_C(           0), -INT32_C(   145752064),  INT32_C(           0),  INT32_C(   489230336),  INT32_C(           0), -INT32_C(   629145600),  INT32_C(   335544320),  INT32_C(           0),
         INT32_C(  1698136064),  INT32_C(           0), -INT32_C(   776921088), -INT32_C(  1158971392), -INT32_C(   514850816),  INT32_C(           0), -INT32_C(  1774387200),  INT32_C(           0) } },
    { { -INT32_C(  1292544541),  INT32_C(   709882480), -INT32_C(  1502878154),  INT32_C(  2026280915),  INT32_C(    59671790),  INT32_C(     7026565),  INT32_C(   671690379), -INT32_C(   780945427),
         INT32_C(  2105764109), -INT32_C(  1851272613), -INT32_C(  1942481991), -INT32_C(  1744503126),  INT32_C(   127636354),  INT32_C(  1426524106),  INT32_C(   578687029), -INT32_C(   722210361) },
      { -INT32_C(  1232109786),  INT32_C(          29),  INT32_C(   280575174),  INT32_C(   180915872),  INT32_C(           1),  INT32_C(          30),  INT32_C(  1761364727),  INT32_C(          24),
        -INT32_C(   533526703), -INT32_C(  1655853626),  INT32_C(  1299641189),  INT32_C(    17640206),  INT32_C(           5),  INT32_C(          20),  INT32_C(           4), -INT32_C(  1251197850) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(   119343580),  INT32_C(  1073741824),  INT32_C(           0), -INT32_C(   318767104),
         INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(   210603968),  INT32_C(  2090860544),  INT32_C(   669057872),  INT32_C(           0) } },
    { {  INT32_C(  1687385200), -INT32_C(  1953121005),  INT32_C(  1381536270), -INT32_C(   714182395),  INT32_C(  1896588819),  INT32_C(   919046105),  INT32_C(  1496915216), -INT32_C(   905009830),
         INT32_C(   741253401),  INT32_C(  1824047966),  INT32_C(  1522405461), -INT32_C(  1792004735), -INT32_C(  1408877613), -INT32_C(   756888126),  INT32_C(  1160453099), -INT32_C(   636536383) },
      {  INT32_C(          26),  INT32_C(          15), -INT32_C(   823534808),  INT32_C(  1032637571),  INT32_C(   420884846), -INT32_C(   710498654),  INT32_C(          22),  INT32_C(     8142832),
         INT32_C(           5), -INT32_C(   902434292),  INT32_C(   675898404),  INT32_C(          29),  INT32_C(   175415447),  INT32_C(  2036227322),  INT32_C(          21),  INT32_C(           8) },
      { -INT32_C(  1073741824), -INT32_C(   561414144),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(  1140850688),  INT32_C(           0),
        -INT32_C(  2049694944),  INT32_C(           0),  INT32_C(           0),  INT32_C(   536870912),  INT32_C(           0),  INT32_C(           0),  INT32_C(  2103443456),  INT32_C(   255443200) } },
    { { -INT32_C(   238216814),  INT32_C(  1555848521), -INT32_C(  1332490284),  INT32_C(     2748715),  INT32_C(  2004754462),  INT32_C(  1576957973),  INT32_C(  1431864347),  INT32_C(   135855478),
         INT32_C(  1610212630),  INT32_C(   398243138), -INT32_C(  1345892476),  INT32_C(  1605431360),  INT32_C(   634793488), -INT32_C(  1048390490), -INT32_C(   837363112), -INT32_C(   304730409) },
      { -INT32_C(  1732692884), -INT32_C(    83895387),  INT32_C(          21),  INT32_C(          15),  INT32_C(   670499734),  INT32_C(          31),  INT32_C(           8),  INT32_C(          21),
         INT32_C(  2002559100),  INT32_C(           9),  INT32_C(          10),  INT32_C(           1),  INT32_C(          23),  INT32_C(          17), -INT32_C(   955535706), -INT32_C(  1853856527) },
      {  INT32_C(           0),  INT32_C(           0), -INT32_C(    92274688), -INT32_C(   124420096),  INT32_C(           0),              INT32_MIN,  INT32_C(  1485052672), -INT32_C(  1363148800),
         INT32_C(           0),  INT32_C(  2037023744),  INT32_C(   490606592), -INT32_C(  1084104576),  INT32_C(   134217728), -INT32_C(  1454637056),  INT32_C(           0),  INT32_C(           0) } },
    { { -INT32_C(  1755609531), -INT32_C(  1699438699), -INT32_C(  2038493297),  INT32_C(   295626608),  INT32_C(   114862741),  INT32_C(   581938689),  INT32_C(  1001323099), -INT32_C(  1546834338),
         INT32_C(  1245391028),  INT32_C(  1457844167),  INT32_C(  1860003070), -INT32_C(   528516277),  INT32_C(   652629797),  INT32_C(  1615435269), -INT32_C(   274925680), -INT32_C(   627939034) },
      {  INT32_C(          17),  INT32_C(   106135053), -INT32_C(    57399681), -INT32_C(  1780050526),  INT32_C(  1152822223),  INT32_C(   202730071),  INT32_C(          13),  INT32_C(          31),
         INT32_C(   948264687),  INT32_C(  1065730471), -INT32_C(  1650396158), -INT32_C(   129713942),  INT32_C(          22),  INT32_C(           7),  INT32_C(          15),  INT32_C(           4) },
      {  INT32_C(   210370560),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(   548708352),  INT32_C(           0),
         INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(   918552576),  INT32_C(   617284224),  INT32_C(  2076704768), -INT32_C(  1457089952) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_epi32(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi32(test_vec[i].b);
    simde__m512i r = simde_mm512_sllv_epi32(a, b);
    simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512i a = simde_test_x86_random_i32x16();

    int b1[16];
    for (size_t i = 0 ; i < 16 ; i++) {
      b1[i] = simde_test_codegen_random_i32() & 31;
      if (simde_test_codegen_random_i32() & 1) {
        b1[i] += simde_test_codegen_random_i32();
      }
    }

    simde__m512i b = simde_mm512_set_epi32(b1[15], b1[14], b1[13], b1[12], b1[11], b1[10], b1[9], b1[8], b1[7], b1[6], b1[5], b1[4], b1[3], b1[2], b1[1], b1[0]);
    simde__m512i r = simde_mm512_sllv_epi32(a, b);

    simde_test_x86_write_i32x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_sllv_epi64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int64_t a[8];
    const int64_t b[8];
    const int64_t r[8];
  } test_vec[] = {
    { {  INT64_C( 8664687853358416575), -INT64_C( 5550029704638101992), -INT64_C( 4196181940940767460), -INT64_C( 3117759686239728776),
         INT64_C(  984328942264110464),  INT64_C( 5198729761049794319),  INT64_C( 1738066888435791256), -INT64_C( 4499287060462976091) },
      {  INT64_C(                  31),  INT64_C(                  30), -INT64_C(          2005349426),  INT64_C(           979884154),
         INT64_C(          2114435566),  INT64_C(                   9),  INT64_C(            55305589),  INT64_C(                  26) },
      { -INT64_C(  393781982737203200), -INT64_C( 1978345198773600256),  INT64_C(                   0),  INT64_C(                   0),
         INT64_C(                   0),  INT64_C( 5418491043319258624),  INT64_C(                   0),  INT64_C(  498315224995069952) } },
    { { -INT64_C( 4696891151666200048), -INT64_C( 7612740216071054289), -INT64_C( 6515760994083051591),  INT64_C( 4127494260798059696),
         INT64_C(  193943766325102993),  INT64_C( 5320126168983695906),  INT64_C( 4022759583882881353), -INT64_C( 8714770982576707413) },
      {  INT64_C(           791386555),  INT64_C(          2014610123), -INT64_C(           290961752), -INT64_C(           667103298),
         INT64_C(                  30),  INT64_C(                  16),  INT64_C(                   7),  INT64_C(          2010912366) },
      {  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
        -INT64_C(  248434221725515776), -INT64_C( 2121126668740198400), -INT64_C( 1595607326858632064),  INT64_C(                   0) } },
    { {  INT64_C( 1768983087041095020),  INT64_C( 6104985209406522383),  INT64_C( 7921713104533007017),  INT64_C( 4320963937867975594),
         INT64_C( 8656353242038384971), -INT64_C( 4749329387608485617), -INT64_C( 7733059985093470680),  INT64_C(  250908245301957233) },
      {  INT64_C(                   0),  INT64_C(                   3),  INT64_C(          2116348004),  INT64_C(                  24),
        -INT64_C(            29377885), -INT64_C(           694435977),  INT64_C(                  22),  INT64_C(                  13) },
      {  INT64_C( 1768983087041095020), -INT64_C( 6500350545876475784),  INT64_C(                   0), -INT64_C( 3540985118615142400),
         INT64_C(                   0),  INT64_C(                   0), -INT64_C( 5003378422097903616),  INT64_C( 7851753331873423360) } },
    { { -INT64_C( 4394728917858967536),  INT64_C( 4884994468226723138),  INT64_C( 2520773836211126778),  INT64_C( 9221209776543105874),
        -INT64_C( 1906465597712115342), -INT64_C( 1754441306376113972),  INT64_C(  364138128856980601),  INT64_C(  549026378646766768) },
      { -INT64_C(            25964467), -INT64_C(          1844874105),  INT64_C(          1241947608),  INT64_C(           738121554),
        -INT64_C(          1959131190), -INT64_C(           838154681),  INT64_C(          2123290446),  INT64_C(                   8) },
      {  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
         INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0), -INT64_C( 7023199656104120320) } },
    { {  INT64_C( 7481966854117573326),  INT64_C( 3209493016119436064),  INT64_C( 3393785523431941365),  INT64_C( 7206977210559503635),
         INT64_C( 6535753547811975189), -INT64_C(  712235036831082228),  INT64_C( 6695137724410504390),  INT64_C( 1008838174905509125) },
      {  INT64_C(           114977994), -INT64_C(          1641525940),  INT64_C(                  18), -INT64_C(           832295308),
         INT64_C(                  26), -INT64_C(           775656559),  INT64_C(                  16), -INT64_C(          1452645507) },
      {  INT64_C(                   0),  INT64_C(                   0), -INT64_C( 7507676395127701504),  INT64_C(                   0),
        -INT64_C( 1931107729703698432),  INT64_C(                   0), -INT64_C( 1708630288579035136),  INT64_C(                   0) } },
    { {  INT64_C( 3789003459160994149), -INT64_C( 6741919992002067803),  INT64_C( 6633058849015457006), -INT64_C( 3088779465371256898),
         INT64_C(  769164894511114213),  INT64_C( 1837545802203285601),  INT64_C( 7883653050295800618), -INT64_C( 4172433454167331117) },
      {  INT64_C(                  16),  INT64_C(                  19),  INT64_C(                  18),  INT64_C(                   1),
         INT64_C(                  25),  INT64_C(                   4),  INT64_C(                  20), -INT64_C(           428260991) },
      {  INT64_C( 4508723370638245888),  INT64_C( 2010405223027703808),  INT64_C( 8035784371916505088), -INT64_C( 6177558930742513796),
        -INT64_C( 3824098899690258432), -INT64_C( 7492755312166533616), -INT64_C( 3827860786775064576),  INT64_C(                   0) } },
    { { -INT64_C( 2805410306358902429),  INT64_C(  977101064481753180),  INT64_C( 4197799891881246709), -INT64_C( 7946528776603517995),
        -INT64_C( 8841609327036138685), -INT64_C( 5341595984381647725),  INT64_C(  653787428719927061), -INT64_C( 5173542556370587021) },
      {  INT64_C(                  29), -INT64_C(           288935088),  INT64_C(          1995983001),  INT64_C(                  18),
         INT64_C(                  27),  INT64_C(                  20), -INT64_C(           314010087), -INT64_C(           959711227) },
      {  INT64_C( 1515531833943523328),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(  628397845914058752),
         INT64_C( 5447622555986821120),  INT64_C( 7785901829060034560),  INT64_C(                   0),  INT64_C(                   0) } },
    { {  INT64_C( 7261773026974920830),  INT64_C( 3586393421900545915),  INT64_C( 7234633043494677485), -INT64_C( 7464063156543147381),
         INT64_C( 4557450154332505283), -INT64_C( 4084248254247572401),  INT64_C( 4490452435820879489), -INT64_C( 7984981307585495940) },
      { -INT64_C(          1715364624),  INT64_C(                  14), -INT64_C(          1491162873),  INT64_C(                   7),
         INT64_C(                  20), -INT64_C(           744137882),  INT64_C(           318366175),  INT64_C(                   2) },
      {  INT64_C(                   0),  INT64_C( 6589949653622374400),  INT64_C(                   0),  INT64_C( 3830607795373819264),
         INT64_C(  886550090908434432),  INT64_C(                   0),  INT64_C(                   0),  INT64_C( 4953562917077119472) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_epi64(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi64(test_vec[i].b);
    simde__m512i r = simde_mm512_sllv_epi64(a, b);
    simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512i a = simde_test_x86_random_i64x8();

    int b1[8];
    for (size_t i = 0 ; i < 8 ; i++) {
      b1[i] = simde_test_codegen_random_i64() & 31;
      if (simde_test_codegen_random_i64() & 1) {
        b1[i] += simde_test_codegen_random_i64();
      }
    }

    simde__m512i b = simde_mm512_set_epi64(b1[7], b1[6], b1[5], b1[4], b1[3], b1[2], b1[1], b1[0]);
    simde__m512i r = simde_mm512_sllv_epi64(a, b);

    simde_test_x86_write_i64x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_sllv_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_sllv_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_sllv_epi64)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/avx512/test-avx512-footer.h>
