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
#include <simde/x86/avx512/srli.h>
#include <simde/x86/avx512/and.h>
#include <simde/x86/avx512/set1.h>
#include <simde/x86/avx512/blend.h>

static int
test_simde_mm_srlv_epi16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int16_t a[8];
    const int16_t b[8];
    const int16_t r[8];
  } test_vec[] = {
    { {  INT16_C( 20854),  INT16_C( 32520),  INT16_C(   459),  INT16_C( 13016), -INT16_C( 10658), -INT16_C( 10061), -INT16_C( 28349),  INT16_C( 13711) },
      {  INT16_C(     0),  INT16_C(    31), -INT16_C(     1),  INT16_C(    32),  INT16_C(    21),  INT16_C(     6),  INT16_C(    14),  INT16_C(    24) },
      {  INT16_C( 20854),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(   866),  INT16_C(     2),  INT16_C(     0) } },
    { {  INT16_C( 24789), -INT16_C( 24476),  INT16_C( 15458), -INT16_C( 16173), -INT16_C( 31214),  INT16_C( 21912),  INT16_C( 10008), -INT16_C( 30837) },
      {  INT16_C(    24),  INT16_C(    20),  INT16_C(    17),  INT16_C(     0),  INT16_C(    18),  INT16_C(    24),  INT16_C(    11),  INT16_C(     5) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C( 16173),  INT16_C(     0),  INT16_C(     0),  INT16_C(     4),  INT16_C(  1084) } },
    { { -INT16_C(  5808), -INT16_C( 19807),  INT16_C( 29734),  INT16_C( 14450),  INT16_C(  3066),  INT16_C(  4750),  INT16_C(  6450), -INT16_C( 30054) },
      {  INT16_C(    27),  INT16_C(    12),  INT16_C(     1),  INT16_C(    19),  INT16_C(    18),  INT16_C(    19),  INT16_C(    27),  INT16_C(    30) },
      {  INT16_C(     0),  INT16_C(    11),  INT16_C( 14867),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { {  INT16_C( 16322), -INT16_C(  5986),  INT16_C(  4275), -INT16_C( 21215), -INT16_C( 20709),  INT16_C( 20160),  INT16_C( 23240),  INT16_C(  9176) },
      {  INT16_C(     8),  INT16_C(    15),  INT16_C(    16),  INT16_C(    28),  INT16_C(    13),  INT16_C(     0),  INT16_C(     8),  INT16_C(    20) },
      {  INT16_C(    63),  INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     5),  INT16_C( 20160),  INT16_C(    90),  INT16_C(     0) } },
    { {  INT16_C( 21245), -INT16_C( 20397),  INT16_C( 29794),  INT16_C( 32350),  INT16_C(  7715), -INT16_C(  5172), -INT16_C( 23432), -INT16_C( 16370) },
      {  INT16_C(     9),  INT16_C(     9),  INT16_C(     0),  INT16_C(    28),  INT16_C(    20),  INT16_C(    22),  INT16_C(    27),  INT16_C(     8) },
      {  INT16_C(    41),  INT16_C(    88),  INT16_C( 29794),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(   192) } },
    { {  INT16_C( 15356),  INT16_C( 24329),  INT16_C( 26544), -INT16_C( 11299), -INT16_C( 22139), -INT16_C(   577), -INT16_C( 12979),  INT16_C( 14013) },
      {  INT16_C(    11),  INT16_C(    16),  INT16_C(    11),  INT16_C(    26),  INT16_C(     9),  INT16_C(    29),  INT16_C(    27),  INT16_C(    30) },
      {  INT16_C(     7),  INT16_C(     0),  INT16_C(    12),  INT16_C(     0),  INT16_C(    84),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { {  INT16_C(  1984),  INT16_C( 28790),  INT16_C( 21359), -INT16_C(  3004),  INT16_C(  1020),  INT16_C( 19186), -INT16_C( 20528),  INT16_C(  7296) },
      {  INT16_C(    22),  INT16_C(     8),  INT16_C(    29),  INT16_C(     1),  INT16_C(    18),  INT16_C(    11),  INT16_C(     3),  INT16_C(     5) },
      {  INT16_C(     0),  INT16_C(   112),  INT16_C(     0),  INT16_C( 31266),  INT16_C(     0),  INT16_C(     9),  INT16_C(  5626),  INT16_C(   228) } },
    { { -INT16_C(  1199), -INT16_C( 16204), -INT16_C(  1969),  INT16_C( 19380), -INT16_C( 22789), -INT16_C( 13163),  INT16_C(  5718),  INT16_C( 19688) },
      {  INT16_C(     6),  INT16_C(    13),  INT16_C(    18),  INT16_C(    10),  INT16_C(    13),  INT16_C(    18),  INT16_C(    31),  INT16_C(    21) },
      {  INT16_C(  1005),  INT16_C(     6),  INT16_C(     0),  INT16_C(    18),  INT16_C(     5),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_x_mm_loadu_epi16(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epi16(test_vec[i].b);
    simde__m128i r = simde_mm_srlv_epi16(a, b);
    simde_test_x86_assert_equal_i16x8(r, simde_x_mm_loadu_epi16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i16x8();
    simde__m128i b = simde_test_x86_random_i16x8();
    simde__m128i r = simde_mm_srlv_epi16(a, b);

    b = simde_mm_and_si128(b, simde_mm_set1_epi16(31));
    if (i == 0 )
      b = simde_mm_mask_blend_epi16(0xf, b,
            simde_mm_set_epi16(0, 0, 0, 0, 32, -1, 31, 0));
    r = simde_mm_srlv_epi16(a, b);

    simde_test_x86_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_mask_srlv_epi16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int16_t src[8];
    const simde__mmask8 k;
    const int16_t a[8];
    const int16_t b[8];
    const int16_t r[8];
  } test_vec[] = {
    { {  INT16_C( 23213), -INT16_C( 23484), -INT16_C(  3615),  INT16_C( 20407),  INT16_C( 12157), -INT16_C( 32012), -INT16_C( 26926), -INT16_C(  1675) },
      UINT8_C(222),
      { -INT16_C( 29011),  INT16_C(  7859),  INT16_C(   600),  INT16_C( 16506),  INT16_C(  6847), -INT16_C( 26796),  INT16_C(  1432), -INT16_C(  3516) },
      {  INT16_C(     0),  INT16_C(    31), -INT16_C(     1),  INT16_C(    32),  INT16_C(    22),  INT16_C(     1),  INT16_C(    15),  INT16_C(    10) },
      {  INT16_C( 23213),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C( 32012),  INT16_C(     0),  INT16_C(    60) } },
    { {  INT16_C( 15657), -INT16_C( 32389), -INT16_C(  2752), -INT16_C(    63),  INT16_C(  5391), -INT16_C( 22634), -INT16_C(  9702),  INT16_C( 25498) },
      UINT8_C(195),
      { -INT16_C( 24979), -INT16_C( 28573),  INT16_C( 12886), -INT16_C( 28506),  INT16_C( 21460),  INT16_C( 28223), -INT16_C( 25379),  INT16_C(  7063) },
      {  INT16_C(    24),  INT16_C(    27),  INT16_C(    26),  INT16_C(    29),  INT16_C(    16),  INT16_C(    10),  INT16_C(    30),  INT16_C(    14) },
      {  INT16_C(     0),  INT16_C(     0), -INT16_C(  2752), -INT16_C(    63),  INT16_C(  5391), -INT16_C( 22634),  INT16_C(     0),  INT16_C(     0) } },
    { { -INT16_C(  3828),  INT16_C( 25180),  INT16_C(   548), -INT16_C(  1806),  INT16_C( 12629),  INT16_C( 13158), -INT16_C(   306), -INT16_C(  6578) },
      UINT8_C( 23),
      { -INT16_C(  3159),  INT16_C(  1009), -INT16_C(  7920), -INT16_C( 10765), -INT16_C( 16916),  INT16_C( 23091), -INT16_C(   181),  INT16_C( 15718) },
      {  INT16_C(    27),  INT16_C(     1),  INT16_C(    26),  INT16_C(    19),  INT16_C(    31),  INT16_C(    25),  INT16_C(    20),  INT16_C(    20) },
      {  INT16_C(     0),  INT16_C(   504),  INT16_C(     0), -INT16_C(  1806),  INT16_C(     0),  INT16_C( 13158), -INT16_C(   306), -INT16_C(  6578) } },
    { { -INT16_C( 14701), -INT16_C( 23584), -INT16_C( 11353), -INT16_C( 27784), -INT16_C( 21359), -INT16_C(  8979),  INT16_C( 21419),  INT16_C(  1817) },
      UINT8_C( 27),
      {  INT16_C( 25978), -INT16_C( 11307), -INT16_C( 16104), -INT16_C(   109),  INT16_C( 20602),  INT16_C(  6707),  INT16_C(  4389), -INT16_C(  5203) },
      {  INT16_C(    17),  INT16_C(    18),  INT16_C(     9),  INT16_C(    22),  INT16_C(    19),  INT16_C(     0),  INT16_C(    12),  INT16_C(     2) },
      {  INT16_C(     0),  INT16_C(     0), -INT16_C( 11353),  INT16_C(     0),  INT16_C(     0), -INT16_C(  8979),  INT16_C( 21419),  INT16_C(  1817) } },
    { {  INT16_C( 22668), -INT16_C( 23142),  INT16_C( 11545), -INT16_C( 27740), -INT16_C( 10371), -INT16_C( 23891),  INT16_C( 23272), -INT16_C(  9587) },
      UINT8_C(171),
      { -INT16_C( 24800),  INT16_C( 18036), -INT16_C(  5643),  INT16_C( 10073), -INT16_C( 16375),  INT16_C( 12659),  INT16_C( 14915), -INT16_C( 25667) },
      {  INT16_C(    20),  INT16_C(    20),  INT16_C(     6),  INT16_C(    30),  INT16_C(    21),  INT16_C(     6),  INT16_C(    14),  INT16_C(    26) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C( 11545),  INT16_C(     0), -INT16_C( 10371),  INT16_C(   197),  INT16_C( 23272),  INT16_C(     0) } },
    { {  INT16_C( 28223),  INT16_C( 13332),  INT16_C( 28247),  INT16_C( 24924), -INT16_C( 12498),  INT16_C( 29074),  INT16_C( 20233), -INT16_C(  8948) },
      UINT8_C(178),
      { -INT16_C(  8512),  INT16_C(  2232), -INT16_C( 27043),  INT16_C( 32509),  INT16_C( 19549), -INT16_C(   724), -INT16_C(  1209), -INT16_C( 19139) },
      {  INT16_C(    15),  INT16_C(    13),  INT16_C(    13),  INT16_C(    12),  INT16_C(     0),  INT16_C(     6),  INT16_C(    10),  INT16_C(     1) },
      {  INT16_C( 28223),  INT16_C(     0),  INT16_C( 28247),  INT16_C( 24924),  INT16_C( 19549),  INT16_C(  1012),  INT16_C( 20233),  INT16_C( 23198) } },
    { { -INT16_C( 17822), -INT16_C( 16398), -INT16_C(  4272), -INT16_C( 21187),  INT16_C( 27196), -INT16_C( 31829), -INT16_C(  6043),  INT16_C( 29752) },
      UINT8_C( 89),
      { -INT16_C(  3515), -INT16_C( 19673), -INT16_C( 15202), -INT16_C( 17485),  INT16_C(   874), -INT16_C(  4379), -INT16_C( 12284), -INT16_C( 16815) },
      {  INT16_C(     2),  INT16_C(    15),  INT16_C(    14),  INT16_C(    14),  INT16_C(     7),  INT16_C(    29),  INT16_C(     9),  INT16_C(     9) },
      {  INT16_C( 15505), -INT16_C( 16398), -INT16_C(  4272),  INT16_C(     2),  INT16_C(     6), -INT16_C( 31829),  INT16_C(   104),  INT16_C( 29752) } },
    { { -INT16_C( 12157),  INT16_C(  8610),  INT16_C( 22164), -INT16_C(   291), -INT16_C( 15783),  INT16_C( 24045),  INT16_C( 16018),  INT16_C( 21788) },
      UINT8_C( 78),
      {  INT16_C(  1835), -INT16_C(  6244),  INT16_C( 21749),  INT16_C( 26191), -INT16_C( 24975),  INT16_C(   783), -INT16_C(   441),  INT16_C(  6022) },
      {  INT16_C(     1),  INT16_C(    11),  INT16_C(     5),  INT16_C(    16),  INT16_C(    23),  INT16_C(    26),  INT16_C(     9),  INT16_C(     3) },
      { -INT16_C( 12157),  INT16_C(    28),  INT16_C(   679),  INT16_C(     0), -INT16_C( 15783),  INT16_C( 24045),  INT16_C(   127),  INT16_C( 21788) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i src = simde_x_mm_loadu_epi16(test_vec[i].src);
    simde__m128i a = simde_x_mm_loadu_epi16(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epi16(test_vec[i].b);
    simde__m128i r = simde_mm_mask_srlv_epi16(src, test_vec[i].k, a, b);
    simde_test_x86_assert_equal_i16x8(r, simde_x_mm_loadu_epi16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i src = simde_test_x86_random_i16x8();
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128i a = simde_test_x86_random_i16x8();
    simde__m128i b = simde_test_x86_random_i16x8();
    simde__m128i r;

    b = simde_mm_and_si128(b, simde_mm_set1_epi16(31));
    if (i == 0 )
      b = simde_mm_mask_blend_epi16(0xf, b,
            simde_mm_set_epi16(0, 0, 0, 0, 32, -1, 31, 0));
    r = simde_mm_mask_srlv_epi16(src, k, a, b);

    simde_test_x86_write_i16x8(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_maskz_srlv_epi16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const int16_t a[8];
    const int16_t b[8];
    const int16_t r[8];
  } test_vec[] = {
    { UINT8_C( 78),
      { -INT16_C(  1423), -INT16_C( 21384), -INT16_C(  6824),  INT16_C( 11575),  INT16_C( 13486),  INT16_C( 24722), -INT16_C(  7561), -INT16_C( 13693) },
      {  INT16_C(     0),  INT16_C(    31), -INT16_C(     1),  INT16_C(    32),  INT16_C(    31),  INT16_C(    19),  INT16_C(     9),  INT16_C(    25) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(   113),  INT16_C(     0) } },
    { UINT8_C(113),
      { -INT16_C(  6542),  INT16_C( 22473), -INT16_C(  2531),  INT16_C( 20997),  INT16_C( 25992),  INT16_C( 27337), -INT16_C( 27672),  INT16_C( 26631) },
      {  INT16_C(    29),  INT16_C(    14),  INT16_C(    10),  INT16_C(    13),  INT16_C(    29),  INT16_C(    12),  INT16_C(    18),  INT16_C(     5) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     6),  INT16_C(     0),  INT16_C(     0) } },
    { UINT8_C( 13),
      {  INT16_C( 15311), -INT16_C( 15062),  INT16_C( 31808), -INT16_C( 22962), -INT16_C( 18363), -INT16_C( 10098), -INT16_C(  2368),  INT16_C(  2006) },
      {  INT16_C(     4),  INT16_C(    17),  INT16_C(    18),  INT16_C(    11),  INT16_C(     1),  INT16_C(    29),  INT16_C(     5),  INT16_C(    21) },
      {  INT16_C(   956),  INT16_C(     0),  INT16_C(     0),  INT16_C(    20),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { UINT8_C(125),
      { -INT16_C( 18145), -INT16_C( 25410),  INT16_C( 25607), -INT16_C( 16159), -INT16_C( 17678), -INT16_C(  5760), -INT16_C( 30832),  INT16_C( 13421) },
      {  INT16_C(    24),  INT16_C(     6),  INT16_C(     7),  INT16_C(    15),  INT16_C(    15),  INT16_C(    12),  INT16_C(    12),  INT16_C(    14) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(   200),  INT16_C(     1),  INT16_C(     1),  INT16_C(    14),  INT16_C(     8),  INT16_C(     0) } },
    { UINT8_C( 89),
      {  INT16_C( 26476), -INT16_C( 12191),  INT16_C(  8521),  INT16_C(   963), -INT16_C( 21343),  INT16_C( 10387), -INT16_C( 14567), -INT16_C(  2720) },
      {  INT16_C(    14),  INT16_C(    29),  INT16_C(    29),  INT16_C(    14),  INT16_C(    16),  INT16_C(     0),  INT16_C(    14),  INT16_C(     9) },
      {  INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     3),  INT16_C(     0) } },
    { UINT8_C(211),
      {  INT16_C(  3050),  INT16_C(  2844),  INT16_C(  8142),  INT16_C( 31404), -INT16_C( 11086),  INT16_C( 31123), -INT16_C( 30411), -INT16_C( 23577) },
      {  INT16_C(     6),  INT16_C(     0),  INT16_C(    21),  INT16_C(    26),  INT16_C(    20),  INT16_C(     3),  INT16_C(    19),  INT16_C(    18) },
      {  INT16_C(    47),  INT16_C(  2844),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { UINT8_C(  8),
      {  INT16_C(  2510), -INT16_C(  4650),  INT16_C( 20662), -INT16_C( 30049),  INT16_C(  6628),  INT16_C( 28095),  INT16_C( 25088), -INT16_C(  6317) },
      {  INT16_C(     2),  INT16_C(    29),  INT16_C(    23),  INT16_C(    10),  INT16_C(    21),  INT16_C(    20),  INT16_C(    28),  INT16_C(    27) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(    34),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { UINT8_C( 28),
      { -INT16_C( 10159), -INT16_C( 23854),  INT16_C( 23672), -INT16_C( 28282), -INT16_C(  3300),  INT16_C( 32401),  INT16_C( 31046),  INT16_C( 25537) },
      {  INT16_C(    22),  INT16_C(    26),  INT16_C(     2),  INT16_C(    29),  INT16_C(    15),  INT16_C(     8),  INT16_C(    10),  INT16_C(    30) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(  5918),  INT16_C(     0),  INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_x_mm_loadu_epi16(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epi16(test_vec[i].b);
    simde__m128i r = simde_mm_maskz_srlv_epi16(test_vec[i].k, a, b);
    simde_test_x86_assert_equal_i16x8(r, simde_x_mm_loadu_epi16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128i a = simde_test_x86_random_i16x8();
    simde__m128i b = simde_test_x86_random_i16x8();
    simde__m128i r;

    b = simde_mm_and_si128(b, simde_mm_set1_epi16(31));
    if (i == 0 )
      b = simde_mm_mask_blend_epi16(0xf, b,
            simde_mm_set_epi16(0, 0, 0, 0, 32, -1, 31, 0));
    r = simde_mm_maskz_srlv_epi16(k, a, b);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i16x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_mask_srlv_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t src[4];
    const simde__mmask8 k;
    const int32_t a[4];
    const int32_t b[4];
    const int32_t r[4];
  } test_vec[] = {
    { {  INT32_C(  1045051322),  INT32_C(   813297984),  INT32_C(   277504789), -INT32_C(   698453306) },
      UINT8_C(195),
      { -INT32_C(   987978706),  INT32_C(   942231910), -INT32_C(  1996244392), -INT32_C(  1572658069) },
      {  INT32_C(           0),  INT32_C(          31), -INT32_C(           1),  INT32_C(          32) },
      { -INT32_C(   987978706),  INT32_C(           0),  INT32_C(   277504789), -INT32_C(   698453306) } },
    { {  INT32_C(    98037663), -INT32_C(  1724055488),  INT32_C(   623002042), -INT32_C(   725064347) },
      UINT8_C(231),
      { -INT32_C(  1092406357),  INT32_C(   777798056),  INT32_C(  1611754854),  INT32_C(   822027072) },
      {  INT32_C(          26),  INT32_C(           2),  INT32_C(          11),  INT32_C(           2) },
      {  INT32_C(          47),  INT32_C(   194449514),  INT32_C(      786989), -INT32_C(   725064347) } },
    { { -INT32_C(  1744020496),  INT32_C(    63334557),  INT32_C(   375642325), -INT32_C(   163159045) },
      UINT8_C(103),
      { -INT32_C(  1062604618), -INT32_C(  2132071259), -INT32_C(   786269163),  INT32_C(  1354854645) },
      {  INT32_C(          28),  INT32_C(           0),  INT32_C(          20),  INT32_C(          22) },
      {  INT32_C(          12), -INT32_C(  2132071259),  INT32_C(        3346), -INT32_C(   163159045) } },
    { { -INT32_C(  2138257190),  INT32_C(   151025908), -INT32_C(   371514636),  INT32_C(   238722194) },
      UINT8_C(246),
      {  INT32_C(   404222759),  INT32_C(  2104233901), -INT32_C(   309124349),  INT32_C(   164126529) },
      {  INT32_C(          12),  INT32_C(           8),  INT32_C(           2),  INT32_C(          28) },
      { -INT32_C(  2138257190),  INT32_C(     8219663),  INT32_C(   996460736),  INT32_C(   238722194) } },
    { { -INT32_C(  1413772034), -INT32_C(  1624758372), -INT32_C(  1936868534),  INT32_C(   127227163) },
      UINT8_C(157),
      { -INT32_C(  1679463533),  INT32_C(    92098499),  INT32_C(  1484913740), -INT32_C(    27908750) },
      {  INT32_C(           0),  INT32_C(          10),  INT32_C(           7),  INT32_C(          20) },
      { -INT32_C(  1679463533), -INT32_C(  1624758372),  INT32_C(    11600888),  INT32_C(        4069) } },
    { {  INT32_C(   916627059),  INT32_C(   977019117), -INT32_C(  1902985956), -INT32_C(  1014109982) },
      UINT8_C(234),
      {  INT32_C(  1628818215), -INT32_C(    64423139),  INT32_C(    74466556), -INT32_C(  1686669315) },
      {  INT32_C(          26),  INT32_C(           9),  INT32_C(          21),  INT32_C(          18) },
      {  INT32_C(   916627059),  INT32_C(     8262781), -INT32_C(  1902985956),  INT32_C(        9949) } },
    { {  INT32_C(   905657623),  INT32_C(   875635512),  INT32_C(  1698210152),  INT32_C(   838971160) },
      UINT8_C( 92),
      {  INT32_C(  1296460938), -INT32_C(  1465717309), -INT32_C(  1021649034),  INT32_C(  1155183367) },
      {  INT32_C(          14),  INT32_C(           0),  INT32_C(           8),  INT32_C(           0) },
      {  INT32_C(   905657623),  INT32_C(   875635512),  INT32_C(    12786399),  INT32_C(  1155183367) } },
    { {  INT32_C(  1551317657), -INT32_C(  1660675801),  INT32_C(     6299385), -INT32_C(  2142946351) },
      UINT8_C( 74),
      {  INT32_C(  1921733313),  INT32_C(   727346316), -INT32_C(  1815285146),  INT32_C(   539817702) },
      {  INT32_C(          14),  INT32_C(          12),  INT32_C(           5),  INT32_C(           6) },
      {  INT32_C(  1551317657),  INT32_C(      177574),  INT32_C(     6299385),  INT32_C(     8434651) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i src = simde_x_mm_loadu_epi32(test_vec[i].src);
    simde__m128i a = simde_x_mm_loadu_epi32(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epi32(test_vec[i].b);
    simde__m128i r = simde_mm_mask_srlv_epi32(src, test_vec[i].k, a, b);
    simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i src = simde_test_x86_random_i32x4();
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128i a = simde_test_x86_random_i32x4();
    simde__m128i b = simde_test_x86_random_i32x4();
    simde__m128i r;

    b = simde_mm_and_si128(b, simde_mm_set1_epi32(31));
    if (i == 0 )
      b = simde_mm_mask_blend_epi32(0xf, b,
            simde_mm_set_epi32(32, -1, 31, 0));
    r = simde_mm_mask_srlv_epi32(src, k, a, b);

    simde_test_x86_write_i32x4(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_maskz_srlv_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const int32_t a[4];
    const int32_t b[4];
    const int32_t r[4];
  } test_vec[] = {
    { UINT8_C( 77),
      { -INT32_C(  1025902251),  INT32_C(  1177027924), -INT32_C(   953369647),  INT32_C(  1865764071) },
      {  INT32_C(           0),  INT32_C(          31), -INT32_C(           1),  INT32_C(          32) },
      { -INT32_C(  1025902251),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { UINT8_C(  5),
      {  INT32_C(  1213800003),  INT32_C(    35233607),  INT32_C(   401269195), -INT32_C(   743810794) },
      {  INT32_C(          21),  INT32_C(          30),  INT32_C(          20),  INT32_C(           2) },
      {  INT32_C(         578),  INT32_C(           0),  INT32_C(         382),  INT32_C(           0) } },
    { UINT8_C(157),
      {  INT32_C(  1592012479),  INT32_C(   673900103),  INT32_C(   708788688),  INT32_C(   243208940) },
      {  INT32_C(           3),  INT32_C(          21),  INT32_C(           9),  INT32_C(          12) },
      {  INT32_C(   199001559),  INT32_C(           0),  INT32_C(     1384352),  INT32_C(       59377) } },
    { UINT8_C(130),
      {  INT32_C(   264907305), -INT32_C(  1780420012),  INT32_C(  1149307441),  INT32_C(    40341385) },
      {  INT32_C(          28),  INT32_C(           1),  INT32_C(          19),  INT32_C(          26) },
      {  INT32_C(           0),  INT32_C(  1257273642),  INT32_C(           0),  INT32_C(           0) } },
    { UINT8_C( 74),
      {  INT32_C(  1738461812), -INT32_C(  1130875726),  INT32_C(  1162206389), -INT32_C(  1631500220) },
      {  INT32_C(          31),  INT32_C(          17),  INT32_C(          29),  INT32_C(          10) },
      {  INT32_C(           0),  INT32_C(       24140),  INT32_C(           0),  INT32_C(     2601042) } },
    { UINT8_C(118),
      {  INT32_C(   455656935),  INT32_C(   986768734),  INT32_C(  1920865578),  INT32_C(   458366422) },
      {  INT32_C(          29),  INT32_C(          13),  INT32_C(          19),  INT32_C(           9) },
      {  INT32_C(           0),  INT32_C(      120455),  INT32_C(        3663),  INT32_C(           0) } },
    { UINT8_C(251),
      {  INT32_C(  1515785077), -INT32_C(   242904100),  INT32_C(   801699602), -INT32_C(   544414903) },
      {  INT32_C(          15),  INT32_C(          20),  INT32_C(          17),  INT32_C(          26) },
      {  INT32_C(       46258),  INT32_C(        3864),  INT32_C(           0),  INT32_C(          55) } },
    { UINT8_C(251),
      {  INT32_C(  1859611354), -INT32_C(   427767569),  INT32_C(  1932570512), -INT32_C(  1402794181) },
      {  INT32_C(          28),  INT32_C(          27),  INT32_C(          21),  INT32_C(          15) },
      {  INT32_C(           6),  INT32_C(          28),  INT32_C(           0),  INT32_C(       88262) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_x_mm_loadu_epi32(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epi32(test_vec[i].b);
    simde__m128i r = simde_mm_maskz_srlv_epi32(test_vec[i].k, a, b);
    simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128i a = simde_test_x86_random_i32x4();
    simde__m128i b = simde_test_x86_random_i32x4();
    simde__m128i r;

    b = simde_mm_and_si128(b, simde_mm_set1_epi32(31));
    if (i == 0 )
      b = simde_mm_mask_blend_epi32(0xf, b,
            simde_mm_set_epi32(32, -1, 31, 0));
    r = simde_mm_maskz_srlv_epi32(k, a, b);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_mask_srlv_epi64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int64_t src[2];
    const simde__mmask8 k;
    const int64_t a[2];
    const int64_t b[2];
    const int64_t r[2];
  } test_vec[] = {
    { {  INT64_C( 4759340010941027350), -INT64_C( 1967368948826934569) },
      UINT8_C(135),
      { -INT64_C(  172620600388341517),  INT64_C( 4905822627423390417) },
      {  INT64_C(                   0),  INT64_C(                  63) },
      { -INT64_C(  172620600388341517),  INT64_C(                   0) } },
    { { -INT64_C( 7378324697411089118), -INT64_C( 6275014858101014282) },
      UINT8_C(221),
      { -INT64_C( 6208830575577618764), -INT64_C( 7642509024037409829) },
      { -INT64_C(                   1),  INT64_C(                  64) },
      {  INT64_C(                   0), -INT64_C( 6275014858101014282) } },
    { { -INT64_C( 2731880677689380111), -INT64_C( 6561577564133417261) },
      UINT8_C( 36),
      { -INT64_C(   13313113293308851),  INT64_C( 5878305957286381910) },
      {  INT64_C(                   3),  INT64_C(                  17) },
      { -INT64_C( 2731880677689380111), -INT64_C( 6561577564133417261) } },
    { { -INT64_C( 2064500699318003313), -INT64_C( 1449006342675794060) },
      UINT8_C( 24),
      { -INT64_C( 5967298555844504012), -INT64_C(   39392036025624429) },
      {  INT64_C(                  40),  INT64_C(                  53) },
      { -INT64_C( 2064500699318003313), -INT64_C( 1449006342675794060) } },
    { { -INT64_C( 3672193763761957432),  INT64_C( 8465966638073823320) },
      UINT8_C(245),
      {  INT64_C( 2985812952140843018), -INT64_C(  684730067239600956) },
      {  INT64_C(                  41),  INT64_C(                  48) },
      {  INT64_C(             1357790),  INT64_C( 8465966638073823320) } },
    { {  INT64_C( 7758276810793609841),  INT64_C( 1442174611476369771) },
      UINT8_C(126),
      {  INT64_C( 4458855818550558004),  INT64_C( 8058418049905768572) },
      {  INT64_C(                   1),  INT64_C(                  36) },
      {  INT64_C( 7758276810793609841),  INT64_C(           117265416) } },
    { { -INT64_C( 5995853301519603762),  INT64_C(  441605950480122924) },
      UINT8_C( 60),
      { -INT64_C(  334657449128839626), -INT64_C( 8220608201982697206) },
      {  INT64_C(                  26),  INT64_C(                  59) },
      { -INT64_C( 5995853301519603762),  INT64_C(  441605950480122924) } },
    { { -INT64_C(  930603654640510393), -INT64_C( 2276296078673429131) },
      UINT8_C(111),
      { -INT64_C( 7851191246785515995), -INT64_C( 1992034650794595198) },
      {  INT64_C(                  24),  INT64_C(                  14) },
      {  INT64_C(        631544162447),  INT64_C(    1004315760675961) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i src = simde_x_mm_loadu_epi64(test_vec[i].src);
    simde__m128i a = simde_x_mm_loadu_epi64(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epi64(test_vec[i].b);
    simde__m128i r = simde_mm_mask_srlv_epi64(src, test_vec[i].k, a, b);
    simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i src = simde_test_x86_random_i64x2();
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128i a = simde_test_x86_random_i64x2();
    simde__m128i b = simde_test_x86_random_i64x2();
    simde__m128i r;

    b = simde_mm_and_si128(b, simde_mm_set1_epi64x(63));
    switch (i) {
      case 0:
        b = simde_mm_set_epi64x(63, 0);
        break;
      case 1:
        b = simde_mm_set_epi64x(64, -1);
        break;
    }
    r = simde_mm_mask_srlv_epi64(src, k, a, b);

    simde_test_x86_write_i64x2(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x2(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_maskz_srlv_epi64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const int64_t a[2];
    const int64_t b[2];
    const int64_t r[2];
  } test_vec[] = {
    { UINT8_C(197),
      {  INT64_C(  320422378828511374),  INT64_C( 4719663389677011455) },
      {  INT64_C(                   0),  INT64_C(                  63) },
      {  INT64_C(  320422378828511374),  INT64_C(                   0) } },
    { UINT8_C(119),
      { -INT64_C(  936202600172470364),  INT64_C( 6540085766919084813) },
      { -INT64_C(                   1),  INT64_C(                  64) },
      {  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C( 32),
      {  INT64_C( 1229418059044893969), -INT64_C(  447609553217144687) },
      {  INT64_C(                  34),  INT64_C(                  30) },
      {  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C(182),
      { -INT64_C( 5041500496302640207), -INT64_C( 4624863187752802711) },
      {  INT64_C(                  31),  INT64_C(                  59) },
      {  INT64_C(                   0),  INT64_C(                  23) } },
    { UINT8_C(123),
      {  INT64_C( 4253148009518173342), -INT64_C(  649527669600668307) },
      {  INT64_C(                  22),  INT64_C(                  63) },
      {  INT64_C(       1014029505137),  INT64_C(                   1) } },
    { UINT8_C( 57),
      { -INT64_C( 6745255973997353025), -INT64_C( 2092873116858973773) },
      {  INT64_C(                  16),  INT64_C(                  23) },
      {  INT64_C(     178550538630862),  INT64_C(                   0) } },
    { UINT8_C( 76),
      { -INT64_C( 7221421285141039604), -INT64_C( 3372215517009287676) },
      {  INT64_C(                  10),  INT64_C(                  16) },
      {  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C( 26),
      {  INT64_C( 3790711809845331259), -INT64_C( 2562583989125759511) },
      {  INT64_C(                  37),  INT64_C(                   7) },
      {  INT64_C(                   0),  INT64_C(  124095000660810875) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_x_mm_loadu_epi64(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epi64(test_vec[i].b);
    simde__m128i r = simde_mm_maskz_srlv_epi64(test_vec[i].k, a, b);
    simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128i a = simde_test_x86_random_i64x2();
    simde__m128i b = simde_test_x86_random_i64x2();
    simde__m128i r;

    b = simde_mm_and_si128(b, simde_mm_set1_epi64x(63));
    switch (i) {
      case 0:
        b = simde_mm_set_epi64x(63, 0);
        break;
      case 1:
        b = simde_mm_set_epi64x(64, -1);
        break;
    }
    r = simde_mm_maskz_srlv_epi64(k, a, b);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x2(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_srlv_epi16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int16_t a[16];
    const int16_t b[16];
    const int16_t r[16];
  } test_vec[] = {
    { { -INT16_C( 30765), -INT16_C(  4649),  INT16_C(  8331), -INT16_C(  2502),  INT16_C( 27582),  INT16_C(  3401), -INT16_C( 22990),  INT16_C( 13442),
        -INT16_C(  1803),  INT16_C(  4907), -INT16_C(  2305),  INT16_C(  1438), -INT16_C(  6736), -INT16_C( 12403), -INT16_C( 20039), -INT16_C( 29497) },
      {  INT16_C(     0),  INT16_C(    31), -INT16_C(     1),  INT16_C(    32),  INT16_C(    30),  INT16_C(    11),  INT16_C(     9),  INT16_C(     4),
         INT16_C(     5),  INT16_C(    17),  INT16_C(     6),  INT16_C(    10),  INT16_C(    21),  INT16_C(     6),  INT16_C(     8),  INT16_C(    26) },
      { -INT16_C( 30765),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     1),  INT16_C(    83),  INT16_C(   840),
         INT16_C(  1991),  INT16_C(     0),  INT16_C(   987),  INT16_C(     1),  INT16_C(     0),  INT16_C(   830),  INT16_C(   177),  INT16_C(     0) } },
    { { -INT16_C(  3188),  INT16_C( 19269), -INT16_C(    90), -INT16_C( 14904),  INT16_C( 21250), -INT16_C( 21739), -INT16_C( 26015),  INT16_C( 26185),
        -INT16_C(  1462), -INT16_C(  3989),  INT16_C( 30025),  INT16_C( 32326),  INT16_C( 27660),  INT16_C( 21868), -INT16_C(  6566), -INT16_C(  6442) },
      {  INT16_C(    25),  INT16_C(    17),  INT16_C(    26),  INT16_C(     5),  INT16_C(    13),  INT16_C(     7),  INT16_C(    20),  INT16_C(    20),
         INT16_C(    10),  INT16_C(    14),  INT16_C(    21),  INT16_C(    18),  INT16_C(     1),  INT16_C(    23),  INT16_C(     5),  INT16_C(     1) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(  1582),  INT16_C(     2),  INT16_C(   342),  INT16_C(     0),  INT16_C(     0),
         INT16_C(    62),  INT16_C(     3),  INT16_C(     0),  INT16_C(     0),  INT16_C( 13830),  INT16_C(     0),  INT16_C(  1842),  INT16_C( 29547) } },
    { {  INT16_C( 21064),  INT16_C( 25214), -INT16_C( 15540), -INT16_C( 26242),  INT16_C( 17694),  INT16_C(  4679),  INT16_C( 23381),  INT16_C( 24401),
         INT16_C( 32731), -INT16_C( 11854), -INT16_C( 31500), -INT16_C( 10541),  INT16_C( 10947), -INT16_C(  6127),  INT16_C( 13143), -INT16_C( 24602) },
      {  INT16_C(     5),  INT16_C(     1),  INT16_C(     8),  INT16_C(    10),  INT16_C(     4),  INT16_C(    25),  INT16_C(    13),  INT16_C(    24),
         INT16_C(     9),  INT16_C(    25),  INT16_C(    15),  INT16_C(    20),  INT16_C(    22),  INT16_C(    26),  INT16_C(    24),  INT16_C(    12) },
      {  INT16_C(   658),  INT16_C( 12607),  INT16_C(   195),  INT16_C(    38),  INT16_C(  1105),  INT16_C(     0),  INT16_C(     2),  INT16_C(     0),
         INT16_C(    63),  INT16_C(     0),  INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     9) } },
    { { -INT16_C( 21083), -INT16_C( 12657), -INT16_C(  1492), -INT16_C(  4076),  INT16_C( 28075), -INT16_C( 18423), -INT16_C( 32489),  INT16_C( 16801),
         INT16_C( 23212),  INT16_C( 23391),  INT16_C( 21479), -INT16_C( 25139),  INT16_C( 10072), -INT16_C( 28245),  INT16_C( 22375),  INT16_C(  3407) },
      {  INT16_C(     5),  INT16_C(    27),  INT16_C(    24),  INT16_C(     2),  INT16_C(    29),  INT16_C(    28),  INT16_C(    13),  INT16_C(    21),
         INT16_C(    24),  INT16_C(    20),  INT16_C(     7),  INT16_C(    28),  INT16_C(     8),  INT16_C(    17),  INT16_C(    31),  INT16_C(    28) },
      {  INT16_C(  1389),  INT16_C(     0),  INT16_C(     0),  INT16_C( 15365),  INT16_C(     0),  INT16_C(     0),  INT16_C(     4),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0),  INT16_C(   167),  INT16_C(     0),  INT16_C(    39),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { { -INT16_C(  2178),  INT16_C( 22517),  INT16_C(  6119),  INT16_C( 17627),  INT16_C(  5955), -INT16_C(  3912),  INT16_C( 28405),  INT16_C( 11593),
        -INT16_C(   638), -INT16_C(  5556),  INT16_C(  2174),  INT16_C(  9898), -INT16_C(  1168),  INT16_C( 12085),  INT16_C( 21147),  INT16_C(  6643) },
      {  INT16_C(     9),  INT16_C(    16),  INT16_C(     0),  INT16_C(    20),  INT16_C(     3),  INT16_C(    19),  INT16_C(    27),  INT16_C(     5),
         INT16_C(    25),  INT16_C(     7),  INT16_C(    25),  INT16_C(    29),  INT16_C(    12),  INT16_C(    24),  INT16_C(     4),  INT16_C(     1) },
      {  INT16_C(   123),  INT16_C(     0),  INT16_C(  6119),  INT16_C(     0),  INT16_C(   744),  INT16_C(     0),  INT16_C(     0),  INT16_C(   362),
         INT16_C(     0),  INT16_C(   468),  INT16_C(     0),  INT16_C(     0),  INT16_C(    15),  INT16_C(     0),  INT16_C(  1321),  INT16_C(  3321) } },
    { { -INT16_C( 11948),  INT16_C( 21534), -INT16_C( 27875), -INT16_C( 32617), -INT16_C( 13632),  INT16_C( 23512),  INT16_C( 23878), -INT16_C( 16520),
        -INT16_C( 32722),  INT16_C(  1974), -INT16_C( 11471), -INT16_C(  8623), -INT16_C( 14043), -INT16_C( 13787), -INT16_C( 31179), -INT16_C( 30280) },
      {  INT16_C(    24),  INT16_C(    29),  INT16_C(     9),  INT16_C(    21),  INT16_C(    30),  INT16_C(     4),  INT16_C(    10),  INT16_C(     3),
         INT16_C(    29),  INT16_C(    31),  INT16_C(    12),  INT16_C(    12),  INT16_C(    26),  INT16_C(    27),  INT16_C(    24),  INT16_C(    24) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(    73),  INT16_C(     0),  INT16_C(     0),  INT16_C(  1469),  INT16_C(    23),  INT16_C(  6127),
         INT16_C(     0),  INT16_C(     0),  INT16_C(    13),  INT16_C(    13),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { {  INT16_C(  5450), -INT16_C( 19707), -INT16_C(  1399), -INT16_C( 14371),  INT16_C( 25031), -INT16_C(  3765), -INT16_C( 29090), -INT16_C(  9399),
        -INT16_C( 22137),  INT16_C( 21386),  INT16_C(  5721), -INT16_C( 11452),  INT16_C(   200),  INT16_C(   386), -INT16_C( 17805), -INT16_C( 17007) },
      {  INT16_C(    15),  INT16_C(    17),  INT16_C(    17),  INT16_C(    31),  INT16_C(    15),  INT16_C(    10),  INT16_C(    24),  INT16_C(     9),
         INT16_C(    29),  INT16_C(    18),  INT16_C(    10),  INT16_C(    10),  INT16_C(    23),  INT16_C(    19),  INT16_C(     7),  INT16_C(     8) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(    60),  INT16_C(     0),  INT16_C(   109),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     5),  INT16_C(    52),  INT16_C(     0),  INT16_C(     0),  INT16_C(   372),  INT16_C(   189) } },
    { { -INT16_C( 18052),  INT16_C(  3535), -INT16_C(  4601), -INT16_C( 18842), -INT16_C( 20135),  INT16_C( 20932), -INT16_C( 20923), -INT16_C( 32047),
        -INT16_C( 23775), -INT16_C( 21736), -INT16_C( 32070), -INT16_C( 11778),  INT16_C( 20847),  INT16_C(  5724), -INT16_C( 23498), -INT16_C( 19828) },
      {  INT16_C(    29),  INT16_C(     0),  INT16_C(    10),  INT16_C(    26),  INT16_C(    23),  INT16_C(    20),  INT16_C(    13),  INT16_C(    30),
         INT16_C(     9),  INT16_C(    26),  INT16_C(    25),  INT16_C(    21),  INT16_C(     9),  INT16_C(    30),  INT16_C(    21),  INT16_C(    18) },
      {  INT16_C(     0),  INT16_C(  3535),  INT16_C(    59),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     5),  INT16_C(     0),
         INT16_C(    81),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(    40),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i a = simde_x_mm256_loadu_epi16(test_vec[i].a);
    simde__m256i b = simde_x_mm256_loadu_epi16(test_vec[i].b);
    simde__m256i r = simde_mm256_srlv_epi16(a, b);
    simde_test_x86_assert_equal_i16x16(r, simde_x_mm256_loadu_epi16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256i
      r,
      a = simde_test_x86_random_i16x16(),
      b = simde_test_x86_random_i16x16();

    b = simde_mm256_and_si256(b, simde_mm256_set1_epi16(31));
    if (i == 0 )
      b = simde_mm256_mask_blend_epi16(0xf, b,
            simde_mm256_set_epi16(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 32, -1, 31, 0));
    r = simde_mm256_srlv_epi16(a, b);

    simde_test_x86_write_i16x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i16x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_srlv_epi16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int16_t a[32];
    const int16_t b[32];
    const int16_t r[32];
  } test_vec[] = {
    { { -INT16_C( 10059), -INT16_C( 29715),  INT16_C( 14501), -INT16_C(  6071), -INT16_C(  7543), -INT16_C( 19762), -INT16_C(  5974),  INT16_C( 26858),
         INT16_C( 17414), -INT16_C( 28813),  INT16_C( 23223), -INT16_C( 29510), -INT16_C( 13013), -INT16_C( 17439), -INT16_C( 13407),  INT16_C( 22246),
        -INT16_C( 11356),  INT16_C( 18913),  INT16_C( 10763), -INT16_C( 27599), -INT16_C(   243), -INT16_C( 18618),  INT16_C( 12520), -INT16_C(  4576),
        -INT16_C( 27788),  INT16_C( 11134),  INT16_C( 14573),  INT16_C(  6584), -INT16_C( 26363), -INT16_C( 22828), -INT16_C( 17820),  INT16_C(  2300) },
      {  INT16_C(     0),  INT16_C(    31), -INT16_C(     1),  INT16_C(    32),  INT16_C(     3),  INT16_C(    12),  INT16_C(     4),  INT16_C(    25),
         INT16_C(     0),  INT16_C(     4),  INT16_C(    15),  INT16_C(     6),  INT16_C(    21),  INT16_C(    26),  INT16_C(    20),  INT16_C(     2),
         INT16_C(    20),  INT16_C(    27),  INT16_C(    24),  INT16_C(    17),  INT16_C(    28),  INT16_C(     6),  INT16_C(    10),  INT16_C(    26),
         INT16_C(    23),  INT16_C(    23),  INT16_C(    27),  INT16_C(    27),  INT16_C(    24),  INT16_C(    10),  INT16_C(    12),  INT16_C(    15) },
      { -INT16_C( 10059),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(  7249),  INT16_C(    11),  INT16_C(  3722),  INT16_C(     0),
         INT16_C( 17414),  INT16_C(  2295),  INT16_C(     0),  INT16_C(   562),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(  5561),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(   733),  INT16_C(    12),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(    41),  INT16_C(    11),  INT16_C(     0) } },
    { {  INT16_C( 10945), -INT16_C( 26180),  INT16_C( 28050),  INT16_C( 28660), -INT16_C( 17686),  INT16_C( 21744), -INT16_C( 29990), -INT16_C( 11970),
        -INT16_C( 27032),  INT16_C( 17367), -INT16_C(  3468), -INT16_C( 21324),  INT16_C(  7880),  INT16_C( 21753), -INT16_C(  6005),  INT16_C( 19828),
         INT16_C( 12306), -INT16_C( 23066), -INT16_C(  9315), -INT16_C( 30956),  INT16_C(  1173),  INT16_C( 28636),  INT16_C(  6798), -INT16_C(  2496),
         INT16_C(  6320),  INT16_C(  9274), -INT16_C(  4598), -INT16_C( 11567), -INT16_C( 13812), -INT16_C( 26586), -INT16_C( 25933), -INT16_C( 14875) },
      {  INT16_C(    10),  INT16_C(    10),  INT16_C(     6),  INT16_C(    15),  INT16_C(     2),  INT16_C(    11),  INT16_C(     5),  INT16_C(     7),
         INT16_C(     4),  INT16_C(    26),  INT16_C(    15),  INT16_C(     1),  INT16_C(    22),  INT16_C(    19),  INT16_C(     2),  INT16_C(    14),
         INT16_C(     4),  INT16_C(    20),  INT16_C(    23),  INT16_C(     6),  INT16_C(    14),  INT16_C(    10),  INT16_C(    30),  INT16_C(     9),
         INT16_C(    18),  INT16_C(    16),  INT16_C(    15),  INT16_C(    29),  INT16_C(    25),  INT16_C(    14),  INT16_C(     9),  INT16_C(     7) },
      {  INT16_C(    10),  INT16_C(    38),  INT16_C(   438),  INT16_C(     0),  INT16_C( 11962),  INT16_C(    10),  INT16_C(  1110),  INT16_C(   418),
         INT16_C(  2406),  INT16_C(     0),  INT16_C(     1),  INT16_C( 22106),  INT16_C(     0),  INT16_C(     0),  INT16_C( 14882),  INT16_C(     1),
         INT16_C(   769),  INT16_C(     0),  INT16_C(     0),  INT16_C(   540),  INT16_C(     0),  INT16_C(    27),  INT16_C(     0),  INT16_C(   123),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     2),  INT16_C(    77),  INT16_C(   395) } },
    { { -INT16_C(  9290),  INT16_C( 27959), -INT16_C( 24930),  INT16_C( 11431), -INT16_C(  3408), -INT16_C( 20832), -INT16_C( 22205), -INT16_C( 10576),
        -INT16_C( 16275), -INT16_C( 17001), -INT16_C( 27470), -INT16_C( 21662),  INT16_C(  4453), -INT16_C(  4538),  INT16_C( 19854),  INT16_C( 17659),
         INT16_C( 12841), -INT16_C( 14415),  INT16_C( 22992), -INT16_C( 32524), -INT16_C( 27573), -INT16_C( 29138), -INT16_C(  8643), -INT16_C( 21660),
        -INT16_C(   865),  INT16_C( 20840), -INT16_C( 13680), -INT16_C(  2564),  INT16_C( 17115),  INT16_C( 27107), -INT16_C(  8561), -INT16_C( 18259) },
      {  INT16_C(    17),  INT16_C(     0),  INT16_C(    24),  INT16_C(     2),  INT16_C(     8),  INT16_C(    17),  INT16_C(    15),  INT16_C(    16),
         INT16_C(    18),  INT16_C(    31),  INT16_C(     3),  INT16_C(    24),  INT16_C(    29),  INT16_C(     8),  INT16_C(    26),  INT16_C(     5),
         INT16_C(    20),  INT16_C(    12),  INT16_C(    25),  INT16_C(    15),  INT16_C(    31),  INT16_C(     6),  INT16_C(    23),  INT16_C(    28),
         INT16_C(    15),  INT16_C(    11),  INT16_C(    22),  INT16_C(    17),  INT16_C(    31),  INT16_C(    31),  INT16_C(    14),  INT16_C(     4) },
      {  INT16_C(     0),  INT16_C( 27959),  INT16_C(     0),  INT16_C(  2857),  INT16_C(   242),  INT16_C(     0),  INT16_C(     1),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0),  INT16_C(  4758),  INT16_C(     0),  INT16_C(     0),  INT16_C(   238),  INT16_C(     0),  INT16_C(   551),
         INT16_C(     0),  INT16_C(    12),  INT16_C(     0),  INT16_C(     1),  INT16_C(     0),  INT16_C(   568),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     1),  INT16_C(    10),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     3),  INT16_C(  2954) } },
    { { -INT16_C( 20375),  INT16_C( 17071), -INT16_C(  8385),  INT16_C( 24099),  INT16_C( 19104),  INT16_C( 22508), -INT16_C( 30623), -INT16_C( 12288),
         INT16_C( 11139), -INT16_C(  9885), -INT16_C(  2865), -INT16_C( 12596), -INT16_C(  5139), -INT16_C(  1273), -INT16_C( 29712),  INT16_C( 22910),
         INT16_C( 11835),  INT16_C( 31388), -INT16_C( 16627), -INT16_C( 21032), -INT16_C( 15351),  INT16_C( 27140),  INT16_C(  1100), -INT16_C( 12485),
        -INT16_C( 25041), -INT16_C(   344),  INT16_C( 29842),  INT16_C( 32716), -INT16_C( 11424),  INT16_C( 20602), -INT16_C(  1698), -INT16_C( 25943) },
      {  INT16_C(     7),  INT16_C(    20),  INT16_C(     5),  INT16_C(     1),  INT16_C(    17),  INT16_C(    25),  INT16_C(     9),  INT16_C(    13),
         INT16_C(    18),  INT16_C(    23),  INT16_C(    10),  INT16_C(     3),  INT16_C(    23),  INT16_C(    26),  INT16_C(    22),  INT16_C(    15),
         INT16_C(     9),  INT16_C(    17),  INT16_C(    17),  INT16_C(    29),  INT16_C(    23),  INT16_C(     0),  INT16_C(    10),  INT16_C(    25),
         INT16_C(     4),  INT16_C(     0),  INT16_C(    19),  INT16_C(    25),  INT16_C(     0),  INT16_C(     0),  INT16_C(    23),  INT16_C(    20) },
      {  INT16_C(   352),  INT16_C(     0),  INT16_C(  1785),  INT16_C( 12049),  INT16_C(     0),  INT16_C(     0),  INT16_C(    68),  INT16_C(     6),
         INT16_C(     0),  INT16_C(     0),  INT16_C(    61),  INT16_C(  6617),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C(    23),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C( 27140),  INT16_C(     1),  INT16_C(     0),
         INT16_C(  2530), -INT16_C(   344),  INT16_C(     0),  INT16_C(     0), -INT16_C( 11424),  INT16_C( 20602),  INT16_C(     0),  INT16_C(     0) } },
    { {  INT16_C( 17971), -INT16_C(  6961),  INT16_C( 27736),  INT16_C( 20551), -INT16_C( 22654),  INT16_C( 19504),  INT16_C( 10709),  INT16_C( 31080),
         INT16_C( 26681),  INT16_C( 11528), -INT16_C(  7733),  INT16_C(  3287), -INT16_C( 26796),  INT16_C(  3107),  INT16_C( 14087),  INT16_C( 14925),
         INT16_C(  7293), -INT16_C( 10721),  INT16_C( 26249),  INT16_C(  2854),  INT16_C( 22029), -INT16_C(  7336), -INT16_C( 16256), -INT16_C( 18084),
         INT16_C( 25641), -INT16_C(  2842), -INT16_C( 16827), -INT16_C( 26112),  INT16_C(  9045),  INT16_C( 23718), -INT16_C(  3237), -INT16_C( 10089) },
      {  INT16_C(    15),  INT16_C(    14),  INT16_C(    28),  INT16_C(     4),  INT16_C(    11),  INT16_C(    12),  INT16_C(    28),  INT16_C(     4),
         INT16_C(    13),  INT16_C(    26),  INT16_C(     9),  INT16_C(    13),  INT16_C(    30),  INT16_C(    27),  INT16_C(     6),  INT16_C(    17),
         INT16_C(     8),  INT16_C(    14),  INT16_C(    20),  INT16_C(    13),  INT16_C(    14),  INT16_C(    10),  INT16_C(     3),  INT16_C(    16),
         INT16_C(    26),  INT16_C(     3),  INT16_C(     4),  INT16_C(     1),  INT16_C(     3),  INT16_C(    27),  INT16_C(    14),  INT16_C(    31) },
      {  INT16_C(     0),  INT16_C(     3),  INT16_C(     0),  INT16_C(  1284),  INT16_C(    20),  INT16_C(     4),  INT16_C(     0),  INT16_C(  1942),
         INT16_C(     3),  INT16_C(     0),  INT16_C(   112),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(   220),  INT16_C(     0),
         INT16_C(    28),  INT16_C(     3),  INT16_C(     0),  INT16_C(     0),  INT16_C(     1),  INT16_C(    56),  INT16_C(  6160),  INT16_C(     0),
         INT16_C(     0),  INT16_C(  7836),  INT16_C(  3044),  INT16_C( 19712),  INT16_C(  1130),  INT16_C(     0),  INT16_C(     3),  INT16_C(     0) } },
    { {  INT16_C( 11597),  INT16_C(   474),  INT16_C( 10431),  INT16_C( 19937),  INT16_C( 27522),  INT16_C( 17815), -INT16_C( 14502), -INT16_C( 27435),
         INT16_C( 31185), -INT16_C( 18729),  INT16_C( 31177),  INT16_C( 28056), -INT16_C( 11051), -INT16_C( 31658), -INT16_C( 27327), -INT16_C( 29126),
         INT16_C(  5570), -INT16_C( 32369),  INT16_C( 28733), -INT16_C( 16434),  INT16_C( 26332),  INT16_C( 13828), -INT16_C(  9939), -INT16_C(    53),
        -INT16_C( 23982),  INT16_C(  7349),  INT16_C( 19739), -INT16_C(  3703), -INT16_C(  8415),  INT16_C( 25205), -INT16_C( 20619),  INT16_C( 14320) },
      {  INT16_C(     4),  INT16_C(    25),  INT16_C(    16),  INT16_C(     0),  INT16_C(    13),  INT16_C(     3),  INT16_C(    30),  INT16_C(    26),
         INT16_C(    16),  INT16_C(    12),  INT16_C(    28),  INT16_C(    29),  INT16_C(    21),  INT16_C(     0),  INT16_C(     1),  INT16_C(     1),
         INT16_C(    17),  INT16_C(     7),  INT16_C(     2),  INT16_C(    14),  INT16_C(    12),  INT16_C(    10),  INT16_C(    31),  INT16_C(    27),
         INT16_C(    19),  INT16_C(    27),  INT16_C(    29),  INT16_C(    14),  INT16_C(    10),  INT16_C(    28),  INT16_C(    31),  INT16_C(    18) },
      {  INT16_C(   724),  INT16_C(     0),  INT16_C(     0),  INT16_C( 19937),  INT16_C(     3),  INT16_C(  2226),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0),  INT16_C(    11),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C( 31658),  INT16_C( 19104),  INT16_C( 18205),
         INT16_C(     0),  INT16_C(   259),  INT16_C(  7183),  INT16_C(     2),  INT16_C(     6),  INT16_C(    13),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     3),  INT16_C(    55),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { {  INT16_C( 31096), -INT16_C(  9486), -INT16_C( 16223), -INT16_C( 29143), -INT16_C( 27503),  INT16_C( 12312), -INT16_C( 27880),  INT16_C( 27711),
        -INT16_C(  9445),  INT16_C( 14556), -INT16_C( 29965), -INT16_C(   310),  INT16_C( 18136), -INT16_C( 18262), -INT16_C( 17181),  INT16_C( 23464),
        -INT16_C( 26059), -INT16_C( 10443),  INT16_C( 24410), -INT16_C(  5275),  INT16_C( 32243),  INT16_C(  2843),  INT16_C( 23313),  INT16_C( 11383),
         INT16_C( 21302),  INT16_C( 10596),  INT16_C( 11997), -INT16_C( 18905), -INT16_C( 11916),  INT16_C( 22382),  INT16_C(  5773), -INT16_C( 15437) },
      {  INT16_C(    17),  INT16_C(    26),  INT16_C(     7),  INT16_C(    23),  INT16_C(    28),  INT16_C(     6),  INT16_C(    13),  INT16_C(    25),
         INT16_C(    17),  INT16_C(    13),  INT16_C(    11),  INT16_C(     4),  INT16_C(     6),  INT16_C(    23),  INT16_C(     9),  INT16_C(    22),
         INT16_C(    18),  INT16_C(     5),  INT16_C(    15),  INT16_C(    20),  INT16_C(    15),  INT16_C(    25),  INT16_C(    24),  INT16_C(     0),
         INT16_C(    16),  INT16_C(    23),  INT16_C(     1),  INT16_C(    27),  INT16_C(    14),  INT16_C(    27),  INT16_C(    28),  INT16_C(    17) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(   385),  INT16_C(     0),  INT16_C(     0),  INT16_C(   192),  INT16_C(     4),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     1),  INT16_C(    17),  INT16_C(  4076),  INT16_C(   283),  INT16_C(     0),  INT16_C(    94),  INT16_C(     0),
         INT16_C(     0),  INT16_C(  1721),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C( 11383),
         INT16_C(     0),  INT16_C(     0),  INT16_C(  5998),  INT16_C(     0),  INT16_C(     3),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { { -INT16_C( 10334),  INT16_C( 20777),  INT16_C( 23987), -INT16_C( 23939),  INT16_C( 14296),  INT16_C(  4351), -INT16_C(    86),  INT16_C( 14937),
        -INT16_C( 28468), -INT16_C( 29418), -INT16_C( 19860),  INT16_C( 23317), -INT16_C(  3996), -INT16_C(  7822),  INT16_C( 25825), -INT16_C( 31984),
         INT16_C( 14651), -INT16_C(  4395),  INT16_C( 21142),  INT16_C( 28305), -INT16_C( 28535),  INT16_C( 13182), -INT16_C( 10353),  INT16_C( 23406),
        -INT16_C( 31640), -INT16_C( 11032), -INT16_C(   714), -INT16_C( 25809), -INT16_C( 23827), -INT16_C( 12420), -INT16_C( 29690),  INT16_C( 16722) },
      {  INT16_C(     5),  INT16_C(    15),  INT16_C(    26),  INT16_C(    10),  INT16_C(    16),  INT16_C(    23),  INT16_C(     0),  INT16_C(    26),
         INT16_C(     9),  INT16_C(    28),  INT16_C(     0),  INT16_C(    27),  INT16_C(    14),  INT16_C(    29),  INT16_C(     3),  INT16_C(    21),
         INT16_C(    23),  INT16_C(     3),  INT16_C(     5),  INT16_C(    20),  INT16_C(    22),  INT16_C(    21),  INT16_C(    16),  INT16_C(    30),
         INT16_C(    18),  INT16_C(    26),  INT16_C(     6),  INT16_C(     1),  INT16_C(    12),  INT16_C(     8),  INT16_C(    13),  INT16_C(    23) },
      {  INT16_C(  1725),  INT16_C(     0),  INT16_C(     0),  INT16_C(    40),  INT16_C(     0),  INT16_C(     0), -INT16_C(    86),  INT16_C(     0),
         INT16_C(    72),  INT16_C(     0), -INT16_C( 19860),  INT16_C(     0),  INT16_C(     3),  INT16_C(     0),  INT16_C(  3228),  INT16_C(     0),
         INT16_C(     0),  INT16_C(  7642),  INT16_C(   660),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0),  INT16_C(  1012),  INT16_C( 19863),  INT16_C(    10),  INT16_C(   207),  INT16_C(     4),  INT16_C(     0) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_epi16(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi16(test_vec[i].b);
    simde__m512i r = simde_mm512_srlv_epi16(a, b);
    simde_test_x86_assert_equal_i16x32(r, simde_mm512_loadu_epi16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512i
      r,
      a = simde_test_x86_random_i16x32(),
      b = simde_test_x86_random_i16x32();

    b = simde_mm512_and_si512(b, simde_mm512_set1_epi16(31));
    if (i == 0 )
      b = simde_mm512_mask_blend_epi16(0xf, b,
            simde_mm512_set_epi16(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 32, -1, 31, 0));
    r = simde_mm512_srlv_epi16(a, b);

    simde_test_x86_write_i16x32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i16x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_srlv_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t a[16];
    const int32_t b[16];
    const int32_t r[16];
  } test_vec[] = {
    { { -INT32_C(  2112154129), -INT32_C(   934216458),  INT32_C(    84870349), -INT32_C(  1586062879), -INT32_C(   576350279), -INT32_C(   828904262), -INT32_C(  1116817424),  INT32_C(  2111336333),
         INT32_C(  2063594628), -INT32_C(  1119727376),  INT32_C(   918704724), -INT32_C(  1529398805), -INT32_C(  1971225392),  INT32_C(  1498945641),  INT32_C(  1544996559), -INT32_C(  1160122826) },
      {  INT32_C(           0),  INT32_C(          31), -INT32_C(           1),  INT32_C(          32),  INT32_C(           7),  INT32_C(          17),  INT32_C(           6),  INT32_C(          14),
         INT32_C(          15),  INT32_C(           3),  INT32_C(           7),  INT32_C(          20),  INT32_C(          19),  INT32_C(          22),  INT32_C(          21),  INT32_C(          24) },
      { -INT32_C(  2112154129),  INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(    29051695),  INT32_C(       26443),  INT32_C(    49658591),  INT32_C(      128865),
         INT32_C(       62975),  INT32_C(   396904990),  INT32_C(     7177380),  INT32_C(        2637),  INT32_C(        4432),  INT32_C(         357),  INT32_C(         736),  INT32_C(         186) } },
    { {  INT32_C(  2111887322),  INT32_C(  1391023851),  INT32_C(   876939904), -INT32_C(   672098940),  INT32_C(  1092296139), -INT32_C(   390258669),  INT32_C(  1535931714), -INT32_C(    29106140),
        -INT32_C(  1552211017), -INT32_C(    84581254), -INT32_C(   215073937), -INT32_C(  1681252400),  INT32_C(  1339942204),  INT32_C(  1211603462),  INT32_C(   883147536),  INT32_C(  1530062499) },
      {  INT32_C(          10),  INT32_C(          17),  INT32_C(          14),  INT32_C(          11),  INT32_C(           3),  INT32_C(          17),  INT32_C(          17),  INT32_C(          27),
         INT32_C(          20),  INT32_C(           1),  INT32_C(          20),  INT32_C(          23),  INT32_C(          31),  INT32_C(          11),  INT32_C(          10),  INT32_C(          15) },
      {  INT32_C(     2062389),  INT32_C(       10612),  INT32_C(       53524),  INT32_C(     1768978),  INT32_C(   136537017),  INT32_C(       29790),  INT32_C(       11718),  INT32_C(          31),
         INT32_C(        2615),  INT32_C(  2105193021),  INT32_C(        3890),  INT32_C(         311),  INT32_C(           0),  INT32_C(      591603),  INT32_C(      862448),  INT32_C(       46693) } },
    { { -INT32_C(  1861561264), -INT32_C(  1878929188), -INT32_C(  2112917494), -INT32_C(   132344200), -INT32_C(   544612236),  INT32_C(  1604074261), -INT32_C(   744206781), -INT32_C(  1600655536),
        -INT32_C(  1607294524),  INT32_C(  2083533681),  INT32_C(   486424483),  INT32_C(  1242831574),  INT32_C(   254385658),  INT32_C(   477021912),  INT32_C(  1710166804), -INT32_C(   972716542) },
      {  INT32_C(           7),  INT32_C(          11),  INT32_C(          22),  INT32_C(          13),  INT32_C(          27),  INT32_C(           5),  INT32_C(          24),  INT32_C(           5),
         INT32_C(          28),  INT32_C(          30),  INT32_C(          11),  INT32_C(          30),  INT32_C(          22),  INT32_C(          28),  INT32_C(          29),  INT32_C(          25) },
      {  INT32_C(    19010984),  INT32_C(     1179706),  INT32_C(         520),  INT32_C(      508132),  INT32_C(          27),  INT32_C(    50127320),  INT32_C(         211),  INT32_C(    84197242),
         INT32_C(          10),  INT32_C(           1),  INT32_C(      237511),  INT32_C(           1),  INT32_C(          60),  INT32_C(           1),  INT32_C(           3),  INT32_C(          99) } },
    { { -INT32_C(  1201909191), -INT32_C(  1760792213),  INT32_C(   820972977),  INT32_C(   428502787), -INT32_C(  2095736794),  INT32_C(   328731254),  INT32_C(   418736223), -INT32_C(   210943047),
         INT32_C(    28035477), -INT32_C(   325535942), -INT32_C(   937654332),  INT32_C(   501327607), -INT32_C(  1264519618),  INT32_C(  1623668737),  INT32_C(  1517862048), -INT32_C(  1806834177) },
      {  INT32_C(          14),  INT32_C(          15),  INT32_C(          21),  INT32_C(          22),  INT32_C(          20),  INT32_C(           2),  INT32_C(          11),  INT32_C(          18),
         INT32_C(           2),  INT32_C(           2),  INT32_C(          13),  INT32_C(          31),  INT32_C(          22),  INT32_C(          16),  INT32_C(          10),  INT32_C(           3) },
      {  INT32_C(      188785),  INT32_C(       77336),  INT32_C(         391),  INT32_C(         102),  INT32_C(        2097),  INT32_C(    82182813),  INT32_C(      204461),  INT32_C(       15579),
         INT32_C(     7008869),  INT32_C(   992357838),  INT32_C(      409828),  INT32_C(           0),  INT32_C(         722),  INT32_C(       24775),  INT32_C(     1482287),  INT32_C(   311016639) } },
    { { -INT32_C(  1126783910),  INT32_C(   265542881),  INT32_C(  2094241309),  INT32_C(   435120930), -INT32_C(    38635636),  INT32_C(  1585024628),  INT32_C(  1780154119),  INT32_C(  2142197285),
        -INT32_C(   600078853),  INT32_C(  2146111073), -INT32_C(   956580188), -INT32_C(  1226839254), -INT32_C(   676097694),  INT32_C(   641018911),  INT32_C(  1368412204), -INT32_C(  1580187738) },
      {  INT32_C(           5),  INT32_C(          25),  INT32_C(           8),  INT32_C(          12),  INT32_C(          20),  INT32_C(           8),  INT32_C(          11),  INT32_C(          10),
         INT32_C(           0),  INT32_C(          26),  INT32_C(          28),  INT32_C(          29),  INT32_C(          25),  INT32_C(          23),  INT32_C(          11),  INT32_C(          17) },
      {  INT32_C(    99005730),  INT32_C(           7),  INT32_C(     8180630),  INT32_C(      106230),  INT32_C(        4059),  INT32_C(     6191502),  INT32_C(      869215),  INT32_C(     2091989),
        -INT32_C(   600078853),  INT32_C(          31),  INT32_C(          12),  INT32_C(           5),  INT32_C(         107),  INT32_C(          76),  INT32_C(      668170),  INT32_C(       20712) } },
    { { -INT32_C(   756294824), -INT32_C(  1284177546), -INT32_C(  1736742501),  INT32_C(   529150566),  INT32_C(   650219439), -INT32_C(   622233649), -INT32_C(   470770286),  INT32_C(  1014355428),
         INT32_C(   638476464), -INT32_C(    36076703),  INT32_C(  1402295789),  INT32_C(   913514375),  INT32_C(  2120037551),  INT32_C(  1029260971), -INT32_C(   954119709), -INT32_C(   838625762) },
      {  INT32_C(          22),  INT32_C(          21),  INT32_C(           3),  INT32_C(           9),  INT32_C(          28),  INT32_C(           4),  INT32_C(          25),  INT32_C(          28),
         INT32_C(           2),  INT32_C(           7),  INT32_C(           8),  INT32_C(          23),  INT32_C(          20),  INT32_C(          17),  INT32_C(           6),  INT32_C(          30) },
      {  INT32_C(         843),  INT32_C(        1435),  INT32_C(   319778099),  INT32_C(     1033497),  INT32_C(           2),  INT32_C(   229545852),  INT32_C(         113),  INT32_C(           3),
         INT32_C(   159619116),  INT32_C(    33272582),  INT32_C(     5477717),  INT32_C(         108),  INT32_C(        2021),  INT32_C(        7852),  INT32_C(    52200743),  INT32_C(           3) } },
    { {  INT32_C(   131636863),  INT32_C(    78721372), -INT32_C(   659224992), -INT32_C(  1328799940), -INT32_C(   240588864),  INT32_C(  1861945192),  INT32_C(  1385299092),  INT32_C(  1112786370),
        -INT32_C(  1085723805), -INT32_C(  1111229860),  INT32_C(  1033206017),  INT32_C(  1508794776), -INT32_C(  1337289144),  INT32_C(   840910494),  INT32_C(    92647490), -INT32_C(   649602955) },
      {  INT32_C(           3),  INT32_C(          10),  INT32_C(          21),  INT32_C(          18),  INT32_C(          13),  INT32_C(          23),  INT32_C(          26),  INT32_C(          27),
         INT32_C(          21),  INT32_C(          29),  INT32_C(          11),  INT32_C(          11),  INT32_C(          23),  INT32_C(          15),  INT32_C(           5),  INT32_C(          12) },
      {  INT32_C(    16454607),  INT32_C(       76876),  INT32_C(        1733),  INT32_C(       11315),  INT32_C(      494919),  INT32_C(         221),  INT32_C(          20),  INT32_C(           8),
         INT32_C(        1530),  INT32_C(           5),  INT32_C(      504495),  INT32_C(      736716),  INT32_C(         352),  INT32_C(       25662),  INT32_C(     2895234),  INT32_C(      889981) } },
    { { -INT32_C(  2128487324), -INT32_C(  2123059754),  INT32_C(   222286849),  INT32_C(   845568250), -INT32_C(   859788675),  INT32_C(   318105613),  INT32_C(  1536389039),  INT32_C(  1971097873),
         INT32_C(  1140301421),  INT32_C(  1288006475),  INT32_C(   962135103), -INT32_C(   630472867),  INT32_C(  2007379050), -INT32_C(  1014392044),  INT32_C(   471735306),  INT32_C(   462527406) },
      {  INT32_C(          25),  INT32_C(          19),  INT32_C(           8),  INT32_C(           9),  INT32_C(           3),  INT32_C(           1),  INT32_C(          16),  INT32_C(          21),
         INT32_C(           1),  INT32_C(          29),  INT32_C(          12),  INT32_C(          11),  INT32_C(          16),  INT32_C(           8),  INT32_C(          28),  INT32_C(          29) },
      {  INT32_C(          64),  INT32_C(        4142),  INT32_C(      868308),  INT32_C(     1651500),  INT32_C(   429397327),  INT32_C(   159052806),  INT32_C(       23443),  INT32_C(         939),
         INT32_C(   570150710),  INT32_C(           2),  INT32_C(      234896),  INT32_C(     1789303),  INT32_C(       30630),  INT32_C(    12814747),  INT32_C(           1),  INT32_C(           0) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_epi32(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi32(test_vec[i].b);
    simde__m512i r = simde_mm512_srlv_epi32(a, b);
    simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512i
      r,
      a = simde_test_x86_random_i32x16(),
      b = simde_test_x86_random_i32x16();

    b = simde_mm512_and_si512(b, simde_mm512_set1_epi32(31));
    if (i == 0 )
      b = simde_mm512_mask_blend_epi32(0xf, b,
            simde_mm512_set_epi32(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 32, -1, 31, 0));
    r = simde_mm512_srlv_epi32(a, b);

    simde_test_x86_write_i32x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_srlv_epi64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int64_t a[8];
    const int64_t b[8];
    const int64_t r[8];
  } test_vec[] = {
    { {  INT64_C( 6966218786012918026), -INT64_C( 5618205476508002450), -INT64_C( 1426445156367503757), -INT64_C( 1837648021358286045),
        -INT64_C( 2539650388535184819), -INT64_C( 1583686562416863375), -INT64_C( 8383106113674598388),  INT64_C( 1181749340145411748) },
      {  INT64_C(                   0),  INT64_C(                  63), -INT64_C(                   1),  INT64_C(                  64),
         INT64_C(                   8),  INT64_C(                  48),  INT64_C(                  12),  INT64_C(                  42) },
      {  INT64_C( 6966218786012918026),  INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
         INT64_C(   62137084707712370),  INT64_C(               59909),  INT64_C(    2456942861336658),  INT64_C(              268698) } },
    { { -INT64_C( 4046179603180281090),  INT64_C( 3795197655086337113),  INT64_C( 6970565303225370834), -INT64_C( 4283339106891513924),
        -INT64_C(  106883913000185689),  INT64_C( 7543103411622860113),  INT64_C( 4637673542611507141), -INT64_C( 5107767993907966574) },
      {  INT64_C(                  32),  INT64_C(                  16),  INT64_C(                  29),  INT64_C(                  60),
         INT64_C(                   8),  INT64_C(                  51),  INT64_C(                  35),  INT64_C(                  20) },
      {  INT64_C(          3352892694),  INT64_C(      57910120469457),  INT64_C(         12983689649),  INT64_C(                  12),
         INT64_C(   71640078752770960),  INT64_C(                3349),  INT64_C(           134974064),  INT64_C(      12721038894464) } },
    { { -INT64_C( 8993731813987568914),  INT64_C( 4658525066509246244),  INT64_C( 8976307826881951255), -INT64_C( 2729782890559505209),
         INT64_C( 4549462570720903694),  INT64_C( 3056988749443738447),  INT64_C( 5761990167718086418),  INT64_C( 2555505904528996527) },
      {  INT64_C(                  61),  INT64_C(                  15),  INT64_C(                  24),  INT64_C(                  34),
         INT64_C(                  25),  INT64_C(                  62),  INT64_C(                  39),  INT64_C(                  31) },
      {  INT64_C(                   4),  INT64_C(     142166902664466),  INT64_C(        535029639415),  INT64_C(           914847547),
         INT64_C(        135584550223),  INT64_C(                   0),  INT64_C(            10480999),  INT64_C(          1190000169) } },
    { {  INT64_C( 3915167907981510217), -INT64_C( 6518895596913605547),  INT64_C( 6982693785598471437), -INT64_C(  979970894321009915),
         INT64_C( 8243081679749162423), -INT64_C( 4019676266592108397), -INT64_C( 6104004055400373270),  INT64_C( 4111781521073115507) },
      {  INT64_C(                  32),  INT64_C(                  13),  INT64_C(                  23),  INT64_C(                  18),
         INT64_C(                   3),  INT64_C(                  45),  INT64_C(                  10),  INT64_C(                  53) },
      {  INT64_C(           911571064),  INT64_C(    1456036191015130),  INT64_C(        832401965331),  INT64_C(      66630451886705),
         INT64_C( 1030385209968645302),  INT64_C(              410041),  INT64_C(   12053457049130056),  INT64_C(                 456) } },
    { {  INT64_C( 6057686915148406591), -INT64_C( 7078250056236356866),  INT64_C( 4598512266726445908), -INT64_C( 7639947378485785139),
         INT64_C( 2652382851266767955), -INT64_C( 3926188394952363054),  INT64_C(  341291946128573683),  INT64_C( 3601860306028357904) },
      {  INT64_C(                  12),  INT64_C(                  46),  INT64_C(                  59),  INT64_C(                  39),
         INT64_C(                  41),  INT64_C(                   6),  INT64_C(                  53),  INT64_C(                  33) },
      {  INT64_C(    1478927469518653),  INT64_C(              161556),  INT64_C(                   7),  INT64_C(            19657448),
         INT64_C(             1206164),  INT64_C(  226883682480581071),  INT64_C(                  37),  INT64_C(           419311726) } },
    { {  INT64_C(   55303212152202527), -INT64_C(  190921087765614432),  INT64_C( 5384226706700903894),  INT64_C( 2258363894737715711),
        -INT64_C( 5300351835966890634), -INT64_C( 7632388881543525681), -INT64_C( 4150345481680443020), -INT64_C( 7502623004535435325) },
      {  INT64_C(                  49),  INT64_C(                   2),  INT64_C(                  61),  INT64_C(                   9),
         INT64_C(                   8),  INT64_C(                   6),  INT64_C(                   3),  INT64_C(                  50) },
      {  INT64_C(                  98),  INT64_C( 4563955746485984296),  INT64_C(                   2),  INT64_C(    4410866981909600),
         INT64_C(   51353094678682269),  INT64_C(  168974299877594155),  INT64_C( 1787049824003638574),  INT64_C(                9720) } },
    { {  INT64_C( 5155634216359390984), -INT64_C( 5330768873949015095),  INT64_C( 4899478041251538590), -INT64_C( 8932982782673421075),
         INT64_C( 4711637638825507354), -INT64_C( 2371656200242924692),  INT64_C( 1489501970028344598), -INT64_C( 9024348993671742269) },
      {  INT64_C(                  12),  INT64_C(                  52),  INT64_C(                   1),  INT64_C(                   4),
         INT64_C(                  56),  INT64_C(                  32),  INT64_C(                  39),  INT64_C(                  34) },
      {  INT64_C(    1258699759853366),  INT64_C(                2912),  INT64_C( 2449739020625769295),  INT64_C(  594610080689758158),
         INT64_C(                  65),  INT64_C(          3742773056),  INT64_C(             2709388),  INT64_C(           548455577) } },
    { {  INT64_C( 1861832143430731975),  INT64_C(   48924248233315771),  INT64_C( 5557999578332679780),  INT64_C( 8107508098736352848),
         INT64_C( 7206212032826514031),  INT64_C( 1045194286659328553),  INT64_C( 1661107840780061844), -INT64_C( 1442935853270313505) },
      {  INT64_C(                   3),  INT64_C(                  47),  INT64_C(                  17),  INT64_C(                  37),
         INT64_C(                   6),  INT64_C(                  41),  INT64_C(                  28),  INT64_C(                  27) },
      {  INT64_C(  232729017928841496),  INT64_C(                 347),  INT64_C(      42404171587621),  INT64_C(            58989885),
         INT64_C(  112597063012914281),  INT64_C(              475299),  INT64_C(          6188108923),  INT64_C(        126688243601) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_epi64(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi64(test_vec[i].b);
    simde__m512i r = simde_mm512_srlv_epi64(a, b);
    simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512i
      r,
      a = simde_test_x86_random_i64x8(),
      b = simde_test_x86_random_i64x8();

    b = simde_mm512_and_si512(b, simde_mm512_set1_epi64(63));
    if (i == 0 )
      b = simde_mm512_mask_blend_epi64(0xf, b,
            simde_mm512_set_epi64(0, 0, 0, 0, 64, -1, 63, 0));
    r = simde_mm512_srlv_epi64(a, b);

    simde_test_x86_write_i64x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_srlv_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_srlv_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_maskz_srlv_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_srlv_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_maskz_srlv_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_srlv_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_maskz_srlv_epi64)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_srlv_epi16)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_srlv_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_srlv_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_srlv_epi64)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/avx512/test-avx512-footer.h>
