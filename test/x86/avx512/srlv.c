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

#define SIMDE_TEST_X86_AVX512_INSN srlv

#include <test/x86/avx512/test-avx512.h>
#include <simde/x86/avx512/srlv.h>

static int
test_simde_mm512_srlv_epi16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const int16_t a[32];
    const int16_t b[32];
    const int16_t r[32];
  } test_vec[] = {
    { {  INT16_C( 11245),  INT16_C( 15388), -INT16_C(  9450),  INT16_C( 14785),  INT16_C( 29263),  INT16_C( 32422), -INT16_C( 27968), -INT16_C(  5555),
        -INT16_C( 13850),  INT16_C(  7512), -INT16_C( 15858),  INT16_C( 20804),  INT16_C( 10819),  INT16_C(  5799),  INT16_C( 23710), -INT16_C( 29883),
         INT16_C( 25224), -INT16_C( 24889), -INT16_C( 30659), -INT16_C( 29481),  INT16_C( 32251), -INT16_C( 17653),  INT16_C( 22543), -INT16_C(  2651),
        -INT16_C(   735),  INT16_C( 12051),  INT16_C( 22463),  INT16_C(   641),  INT16_C( 10369),  INT16_C(  7960),  INT16_C( 24196),  INT16_C(  3242) },
      {  INT16_C(    14),  INT16_C(    31),  INT16_C(    16),  INT16_C(    30),  INT16_C(    18),  INT16_C(     1),  INT16_C(    10),  INT16_C(     1),
         INT16_C(     2),  INT16_C(     2),  INT16_C(    23),  INT16_C(    30),  INT16_C(     5),  INT16_C(    13),  INT16_C(    23),  INT16_C(     9),
         INT16_C(     4),  INT16_C(     4),  INT16_C(    26),  INT16_C(    20),  INT16_C(    25),  INT16_C(    10),  INT16_C(    22),  INT16_C(    14),
         INT16_C(    19),  INT16_C(     7),  INT16_C(    19),  INT16_C(     8),  INT16_C(     7),  INT16_C(    10),  INT16_C(     5),  INT16_C(     4) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C( 16211),  INT16_C(    36),  INT16_C( 29990),
         INT16_C( 12921),  INT16_C(  1878),  INT16_C(     0),  INT16_C(     0),  INT16_C(   338),  INT16_C(     0),  INT16_C(     0),  INT16_C(    69),
         INT16_C(  1576),  INT16_C(  2540),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(    46),  INT16_C(     0),  INT16_C(     3),
         INT16_C(     0),  INT16_C(    94),  INT16_C(     0),  INT16_C(     2),  INT16_C(    81),  INT16_C(     7),  INT16_C(   756),  INT16_C(   202) } },
    { { -INT16_C(  7349), -INT16_C(  4281),  INT16_C( 25524),  INT16_C(  6546),  INT16_C( 17199),  INT16_C( 20844), -INT16_C( 12807), -INT16_C( 14906),
         INT16_C( 19564), -INT16_C( 13824),  INT16_C( 11238), -INT16_C( 21489), -INT16_C( 16538),  INT16_C( 23293), -INT16_C( 26136),  INT16_C( 13179),
        -INT16_C( 15748),  INT16_C( 12322), -INT16_C( 19419),  INT16_C( 21577), -INT16_C( 18953), -INT16_C(  3930),  INT16_C( 27778), -INT16_C(  4426),
        -INT16_C( 18760), -INT16_C( 24904), -INT16_C( 14366),  INT16_C( 18506),  INT16_C( 18567),  INT16_C( 28578),  INT16_C(  7649),  INT16_C( 23970) },
      {  INT16_C(    24),  INT16_C(     0),  INT16_C(    26),  INT16_C(    13),  INT16_C(    31),  INT16_C(     1),  INT16_C(     2),  INT16_C(     4),
         INT16_C(    22),  INT16_C(    21),  INT16_C(     1),  INT16_C(     0),  INT16_C(    19),  INT16_C(     6),  INT16_C(     2),  INT16_C(    18),
         INT16_C(     3),  INT16_C(    10),  INT16_C(    30),  INT16_C(    16),  INT16_C(     4),  INT16_C(    11),  INT16_C(    17),  INT16_C(     0),
         INT16_C(     8),  INT16_C(    23),  INT16_C(    21),  INT16_C(    20),  INT16_C(     6),  INT16_C(    30),  INT16_C(    12),  INT16_C(     4) },
      {  INT16_C(     0), -INT16_C(  4281),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C( 10422),  INT16_C( 13182),  INT16_C(  3164),
         INT16_C(     0),  INT16_C(     0),  INT16_C(  5619), -INT16_C( 21489),  INT16_C(     0),  INT16_C(   363),  INT16_C(  9850),  INT16_C(     0),
         INT16_C(  6223),  INT16_C(    12),  INT16_C(     0),  INT16_C(     0),  INT16_C(  2911),  INT16_C(    30),  INT16_C(     0), -INT16_C(  4426),
         INT16_C(   182),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(   290),  INT16_C(     0),  INT16_C(     1),  INT16_C(  1498) } },
    { {  INT16_C( 10373),  INT16_C( 31349),  INT16_C( 13595),  INT16_C(  3835), -INT16_C( 30122), -INT16_C( 29589), -INT16_C(  5097),  INT16_C( 22927),
         INT16_C( 16685),  INT16_C( 31256), -INT16_C(  9239),  INT16_C( 10779), -INT16_C(  4079),  INT16_C( 23585), -INT16_C( 20650), -INT16_C(  9344),
        -INT16_C(  2601), -INT16_C(  3499),  INT16_C( 20522),       INT16_MIN,  INT16_C( 27867), -INT16_C(  3571), -INT16_C( 25512), -INT16_C( 31413),
         INT16_C( 25565), -INT16_C( 14848),  INT16_C(  6974),  INT16_C( 20464),  INT16_C(  4619),  INT16_C( 25003),  INT16_C( 11201), -INT16_C( 26563) },
      {  INT16_C(    18),  INT16_C(     9),  INT16_C(    17),  INT16_C(    23),  INT16_C(    27),  INT16_C(     9),  INT16_C(    31),  INT16_C(    10),
         INT16_C(    26),  INT16_C(    19),  INT16_C(     1),  INT16_C(    31),  INT16_C(    18),  INT16_C(    27),  INT16_C(    19),  INT16_C(    28),
         INT16_C(    31),  INT16_C(     1),  INT16_C(    30),  INT16_C(    16),  INT16_C(    15),  INT16_C(     8),  INT16_C(    20),  INT16_C(    26),
         INT16_C(    21),  INT16_C(    13),  INT16_C(    11),  INT16_C(    26),  INT16_C(    23),  INT16_C(    22),  INT16_C(     4),  INT16_C(    16) },
      {  INT16_C(     0),  INT16_C(    61),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(    70),  INT16_C(     0),  INT16_C(    22),
         INT16_C(     0),  INT16_C(     0),  INT16_C( 28148),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0),  INT16_C( 31018),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(   242),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     6),  INT16_C(     3),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(   700),  INT16_C(     0) } },
    { { -INT16_C( 16352), -INT16_C( 22127),  INT16_C( 24246), -INT16_C( 31446), -INT16_C(  1574),  INT16_C( 21192),  INT16_C( 23965),  INT16_C(  5671),
        -INT16_C( 26358), -INT16_C( 16002), -INT16_C(  7947), -INT16_C(  5998),  INT16_C( 16543), -INT16_C(  2405),  INT16_C( 12385), -INT16_C( 32391),
         INT16_C(  3056), -INT16_C( 22997),  INT16_C( 21865),  INT16_C( 17195), -INT16_C(  3250), -INT16_C(  4971), -INT16_C( 17072),  INT16_C( 23298),
        -INT16_C( 32682),  INT16_C( 19228), -INT16_C( 20896), -INT16_C(   205), -INT16_C( 12306),  INT16_C( 20726),  INT16_C( 28671), -INT16_C(  4143) },
      {  INT16_C(    31),  INT16_C(    28),  INT16_C(    24),  INT16_C(    20),  INT16_C(    23),  INT16_C(     0),  INT16_C(    17),  INT16_C(    25),
         INT16_C(    15),  INT16_C(    13),  INT16_C(     9),  INT16_C(     3),  INT16_C(    12),  INT16_C(     3),  INT16_C(     7),  INT16_C(     9),
         INT16_C(    20),  INT16_C(    17),  INT16_C(    11),  INT16_C(     2),  INT16_C(    22),  INT16_C(    17),  INT16_C(    15),  INT16_C(    10),
         INT16_C(    15),  INT16_C(     4),  INT16_C(     5),  INT16_C(    28),  INT16_C(    20),  INT16_C(    12),  INT16_C(     1),  INT16_C(     2) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C( 21192),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     1),  INT16_C(     6),  INT16_C(   112),  INT16_C(  7442),  INT16_C(     4),  INT16_C(  7891),  INT16_C(    96),  INT16_C(    64),
         INT16_C(     0),  INT16_C(     0),  INT16_C(    10),  INT16_C(  4298),  INT16_C(     0),  INT16_C(     0),  INT16_C(     1),  INT16_C(    22),
         INT16_C(     1),  INT16_C(  1201),  INT16_C(  1395),  INT16_C(     0),  INT16_C(     0),  INT16_C(     5),  INT16_C( 14335),  INT16_C( 15348) } },
    { { -INT16_C(  6994),  INT16_C(  4254), -INT16_C( 14788),  INT16_C( 20774),  INT16_C( 17019), -INT16_C( 16928),  INT16_C( 16061), -INT16_C( 19186),
        -INT16_C( 12873),  INT16_C( 32471),  INT16_C(  4858), -INT16_C( 29853),  INT16_C( 26038), -INT16_C( 27409), -INT16_C( 23950),  INT16_C(  8362),
         INT16_C( 18566), -INT16_C( 15824),  INT16_C( 22030), -INT16_C( 30444), -INT16_C(  2920),  INT16_C( 22087),  INT16_C( 21810), -INT16_C(  5877),
        -INT16_C(  7646),  INT16_C(  7271), -INT16_C( 13324), -INT16_C( 21849), -INT16_C( 27088), -INT16_C( 24002), -INT16_C(  6088), -INT16_C( 16702) },
      {  INT16_C(    30),  INT16_C(     7),  INT16_C(    18),  INT16_C(    28),  INT16_C(     1),  INT16_C(    23),  INT16_C(     8),  INT16_C(    16),
         INT16_C(     1),  INT16_C(     3),  INT16_C(     9),  INT16_C(     0),  INT16_C(     0),  INT16_C(     3),  INT16_C(    13),  INT16_C(     3),
         INT16_C(    11),  INT16_C(    20),  INT16_C(     4),  INT16_C(    14),  INT16_C(    23),  INT16_C(    18),  INT16_C(    26),  INT16_C(     4),
         INT16_C(    23),  INT16_C(    22),  INT16_C(    31),  INT16_C(    28),  INT16_C(    12),  INT16_C(    28),  INT16_C(    26),  INT16_C(     5) },
      {  INT16_C(     0),  INT16_C(    33),  INT16_C(     0),  INT16_C(     0),  INT16_C(  8509),  INT16_C(     0),  INT16_C(    62),  INT16_C(     0),
         INT16_C( 26331),  INT16_C(  4058),  INT16_C(     9), -INT16_C( 29853),  INT16_C( 26038),  INT16_C(  4765),  INT16_C(     5),  INT16_C(  1045),
         INT16_C(     9),  INT16_C(     0),  INT16_C(  1376),  INT16_C(     2),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(  3728),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     9),  INT16_C(     0),  INT16_C(     0),  INT16_C(  1526) } },
    { {  INT16_C( 22575),  INT16_C(  7378),  INT16_C( 22649), -INT16_C( 21870), -INT16_C( 15595),  INT16_C(  5183),  INT16_C( 23192),  INT16_C( 30775),
         INT16_C( 29208),  INT16_C(  8239), -INT16_C(  4753),  INT16_C( 27655),  INT16_C(  1875),  INT16_C(  9043),  INT16_C( 21470),  INT16_C(  3408),
         INT16_C(  8875),  INT16_C(  9513), -INT16_C( 17542), -INT16_C( 28721),  INT16_C(  3710),  INT16_C(  5795), -INT16_C(  9624), -INT16_C( 32369),
        -INT16_C( 16820), -INT16_C( 17503), -INT16_C( 22357), -INT16_C(   472),  INT16_C( 31664), -INT16_C( 29150),  INT16_C( 29390),  INT16_C( 31132) },
      {  INT16_C(    24),  INT16_C(     1),  INT16_C(    13),  INT16_C(    31),  INT16_C(     8),  INT16_C(    28),  INT16_C(    20),  INT16_C(    13),
         INT16_C(     0),  INT16_C(     1),  INT16_C(     9),  INT16_C(    11),  INT16_C(     5),  INT16_C(    18),  INT16_C(    17),  INT16_C(     6),
         INT16_C(    21),  INT16_C(    25),  INT16_C(    28),  INT16_C(    18),  INT16_C(    28),  INT16_C(     8),  INT16_C(    28),  INT16_C(    29),
         INT16_C(    26),  INT16_C(    18),  INT16_C(     1),  INT16_C(    29),  INT16_C(    28),  INT16_C(    27),  INT16_C(    17),  INT16_C(    22) },
      {  INT16_C(     0),  INT16_C(  3689),  INT16_C(     2),  INT16_C(     0),  INT16_C(   195),  INT16_C(     0),  INT16_C(     0),  INT16_C(     3),
         INT16_C( 29208),  INT16_C(  4119),  INT16_C(   118),  INT16_C(    13),  INT16_C(    58),  INT16_C(     0),  INT16_C(     0),  INT16_C(    53),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(    22),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0),  INT16_C( 21589),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { {  INT16_C( 22844),  INT16_C( 22407),  INT16_C( 22078),  INT16_C( 26350),  INT16_C( 26939), -INT16_C( 14933),  INT16_C( 23113),  INT16_C( 12210),
        -INT16_C( 20691),  INT16_C( 20164), -INT16_C( 18503), -INT16_C(  3530), -INT16_C( 19049),  INT16_C(   206), -INT16_C(  8125),  INT16_C( 32695),
         INT16_C( 15929),  INT16_C( 30934), -INT16_C( 14956), -INT16_C( 12322), -INT16_C( 30162),  INT16_C( 30868),  INT16_C( 18404),  INT16_C(  4519),
         INT16_C( 27638), -INT16_C( 20641), -INT16_C( 27102), -INT16_C( 18015),  INT16_C( 28491), -INT16_C( 28999),  INT16_C( 29008), -INT16_C( 30451) },
      {  INT16_C(    28),  INT16_C(     8),  INT16_C(    28),  INT16_C(    26),  INT16_C(    21),  INT16_C(     9),  INT16_C(    30),  INT16_C(    28),
         INT16_C(    23),  INT16_C(    16),  INT16_C(     6),  INT16_C(    20),  INT16_C(    30),  INT16_C(    30),  INT16_C(     7),  INT16_C(     3),
         INT16_C(    16),  INT16_C(    24),  INT16_C(    13),  INT16_C(    25),  INT16_C(    29),  INT16_C(     0),  INT16_C(    14),  INT16_C(     8),
         INT16_C(    15),  INT16_C(    17),  INT16_C(     1),  INT16_C(    11),  INT16_C(    11),  INT16_C(    13),  INT16_C(    25),  INT16_C(    22) },
      {  INT16_C(     0),  INT16_C(    87),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(    98),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0),  INT16_C(   734),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(   448),  INT16_C(  4086),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     6),  INT16_C(     0),  INT16_C(     0),  INT16_C( 30868),  INT16_C(     1),  INT16_C(    17),
         INT16_C(     0),  INT16_C(     0),  INT16_C( 19217),  INT16_C(    23),  INT16_C(    13),  INT16_C(     4),  INT16_C(     0),  INT16_C(     0) } },
    { { -INT16_C(  9139), -INT16_C( 21126),  INT16_C(  6219),  INT16_C( 25463), -INT16_C( 28923), -INT16_C(  6039),  INT16_C( 21767),  INT16_C( 15662),
        -INT16_C(  1836), -INT16_C( 30263), -INT16_C(  3072), -INT16_C(    29),  INT16_C( 12878), -INT16_C(  7577), -INT16_C(  6400),  INT16_C( 19861),
         INT16_C(  4035),  INT16_C(  4091),  INT16_C( 29223),  INT16_C( 11378), -INT16_C(  9470),  INT16_C(  2325),  INT16_C( 17200),  INT16_C(  1350),
         INT16_C(  3899),  INT16_C( 15246),  INT16_C( 29188),  INT16_C( 21050), -INT16_C( 23900), -INT16_C( 23500), -INT16_C( 13687),  INT16_C( 19954) },
      {  INT16_C(    29),  INT16_C(     0),  INT16_C(    25),  INT16_C(    12),  INT16_C(     8),  INT16_C(    27),  INT16_C(    22),  INT16_C(    24),
         INT16_C(    13),  INT16_C(    24),  INT16_C(     6),  INT16_C(    16),  INT16_C(     9),  INT16_C(    12),  INT16_C(     3),  INT16_C(    29),
         INT16_C(     1),  INT16_C(    12),  INT16_C(     3),  INT16_C(    16),  INT16_C(     6),  INT16_C(    28),  INT16_C(     7),  INT16_C(    20),
         INT16_C(    20),  INT16_C(    17),  INT16_C(    15),  INT16_C(    21),  INT16_C(     6),  INT16_C(    27),  INT16_C(    23),  INT16_C(    10) },
      {  INT16_C(     0), -INT16_C( 21126),  INT16_C(     0),  INT16_C(     6),  INT16_C(   143),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     7),  INT16_C(     0),  INT16_C(   976),  INT16_C(     0),  INT16_C(    25),  INT16_C(    14),  INT16_C(  7392),  INT16_C(     0),
         INT16_C(  2017),  INT16_C(     0),  INT16_C(  3652),  INT16_C(     0),  INT16_C(   876),  INT16_C(     0),  INT16_C(   134),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(   650),  INT16_C(     0),  INT16_C(     0),  INT16_C(    19) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_epi16(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi16(test_vec[i].b);
    simde__m512i r = simde_mm512_srlv_epi16(a, b);
    simde_test_x86_assert_equal_i16x32(r, simde_mm512_loadu_epi16(test_vec[i].r));
  }

  return 0;
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_srlv_epi16)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/avx512/test-avx512-footer.h>
