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
 *   2025      Michael R. Crusoe <crusoe@debian.org>
 */

#include "test/test.h"
#define SIMDE_TEST_X86_AVX512_INSN srli

#include <test/x86/avx512/test-avx512.h>
#include <simde/x86/avx512/set.h>
#include <simde/x86/avx512/srli.h>

static int
test_simde_mm_mask_srli_epi16(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  const struct {
    const int16_t src[8];
    const simde__mmask8 k;
    const int16_t a[8];
    const int16_t r[8];
  } test_vec[] = {
    { { -INT16_C( 22201), -INT16_C(  1696), -INT16_C(  8280), -INT16_C( 28520),  INT16_C( 18763), -INT16_C( 10610),  INT16_C(  4818), -INT16_C( 28705) },
      UINT8_C(135),
      {  INT16_C( 14001), -INT16_C( 24994),  INT16_C( 12292),  INT16_C( 15768),  INT16_C( 10461),  INT16_C( 31719),  INT16_C( 23669),  INT16_C(  7874) },
      {  INT16_C(   109),  INT16_C(   316),  INT16_C(    96), -INT16_C( 28520),  INT16_C( 18763), -INT16_C( 10610),  INT16_C(  4818),  INT16_C(    61) } },
    { { -INT16_C( 17475), -INT16_C( 25401),  INT16_C( 22355), -INT16_C( 25369), -INT16_C( 16923), -INT16_C(  1937), -INT16_C(   356),  INT16_C( 19839) },
      UINT8_C( 52),
      { -INT16_C(  5155),  INT16_C(  3384),  INT16_C( 30083), -INT16_C( 21270),  INT16_C( 25949), -INT16_C( 18143),  INT16_C( 16424), -INT16_C(  7306) },
      { -INT16_C( 17475), -INT16_C( 25401),  INT16_C(   235), -INT16_C( 25369),  INT16_C(   202),  INT16_C(   370), -INT16_C(   356),  INT16_C( 19839) } },
    { {  INT16_C(  4615),  INT16_C( 24119), -INT16_C( 11271), -INT16_C( 18876),  INT16_C( 15426),  INT16_C( 16466), -INT16_C( 24389), -INT16_C( 26508) },
      UINT8_C(139),
      { -INT16_C( 23123),  INT16_C(  8719), -INT16_C( 17521), -INT16_C(  2689),  INT16_C( 14812),  INT16_C(  7197),  INT16_C(   175), -INT16_C( 15837) },
      {  INT16_C(   331),  INT16_C(    68), -INT16_C( 11271),  INT16_C(   490),  INT16_C( 15426),  INT16_C( 16466), -INT16_C( 24389),  INT16_C(   388) } },
    { { -INT16_C( 32201),  INT16_C(  3003),  INT16_C( 29382),  INT16_C(   589), -INT16_C( 28988),  INT16_C( 25789),  INT16_C( 21762), -INT16_C( 20496) },
      UINT8_C(250),
      { -INT16_C( 11521), -INT16_C( 17783),  INT16_C( 32337), -INT16_C( 30058), -INT16_C( 19557), -INT16_C( 25542), -INT16_C(   810),  INT16_C( 22739) },
      { -INT16_C( 32201),  INT16_C(   373),  INT16_C( 29382),  INT16_C(   277),  INT16_C(   359),  INT16_C(   312),  INT16_C(   505),  INT16_C(   177) } },
    { { -INT16_C(  8521),  INT16_C( 10526),  INT16_C(  8236), -INT16_C( 17682),  INT16_C( 21213),  INT16_C( 12988),  INT16_C( 27714),  INT16_C( 16684) },
      UINT8_C( 62),
      { -INT16_C(  1098),  INT16_C( 13455),  INT16_C(  6802),  INT16_C( 17872),  INT16_C( 27732),  INT16_C( 20507),  INT16_C( 29759),  INT16_C(  7687) },
      { -INT16_C(  8521),  INT16_C(   105),  INT16_C(    53),  INT16_C(   139),  INT16_C(   216),  INT16_C(   160),  INT16_C( 27714),  INT16_C( 16684) } },
    { {  INT16_C( 12690), -INT16_C( 19638),  INT16_C(  1055),  INT16_C( 29072), -INT16_C( 15424),  INT16_C( 11444), -INT16_C(  2577), -INT16_C( 23190) },
      UINT8_C(241),
      { -INT16_C(  9478),  INT16_C(  5251), -INT16_C( 14166),  INT16_C(  5736), -INT16_C( 18205),  INT16_C( 22357),  INT16_C( 29631), -INT16_C(  3862) },
      {  INT16_C(   437), -INT16_C( 19638),  INT16_C(  1055),  INT16_C( 29072),  INT16_C(   369),  INT16_C(   174),  INT16_C(   231),  INT16_C(   481) } },
    { { -INT16_C( 25155), -INT16_C( 16113), -INT16_C( 32467), -INT16_C(  3966), -INT16_C( 20939),  INT16_C( 10976), -INT16_C( 31463),  INT16_C(  4891) },
      UINT8_C( 95),
      {  INT16_C( 10142),  INT16_C( 26121),  INT16_C(  8079),  INT16_C( 18250), -INT16_C( 24203), -INT16_C(  6138), -INT16_C(  2165),  INT16_C( 10406) },
      {  INT16_C(    79),  INT16_C(   204),  INT16_C(    63),  INT16_C(   142),  INT16_C(   322),  INT16_C( 10976),  INT16_C(   495),  INT16_C(  4891) } },
    { {  INT16_C( 26374), -INT16_C( 30890),  INT16_C( 18153), -INT16_C( 26436), -INT16_C(  6362), -INT16_C( 21327), -INT16_C( 15358), -INT16_C( 24309) },
      UINT8_C(235),
      {  INT16_C(  1813),  INT16_C( 13434), -INT16_C( 16047), -INT16_C(  3159), -INT16_C( 27961), -INT16_C( 16770), -INT16_C( 22728), -INT16_C( 24635) },
      {  INT16_C(    14),  INT16_C(   104),  INT16_C( 18153),  INT16_C(   487), -INT16_C(  6362),  INT16_C(   380),  INT16_C(   334),  INT16_C(   319) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i src = simde_mm_loadu_epi16(test_vec[i].src);
    simde__m128i a = simde_mm_loadu_epi16(test_vec[i].a);
    simde__m128i r = simde_mm_mask_srli_epi16(src, test_vec[i].k, a, 7);
    simde_test_x86_assert_equal_i16x8(r, simde_mm_loadu_epi16(test_vec[i].r));
  }
  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i src = simde_test_x86_random_i16x8();
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128i a = simde_test_x86_random_i16x8();
    simde__m128i r = simde_mm_mask_srli_epi16(src, k, a, 7);

    simde_test_x86_write_i16x8(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_maskz_srli_epi16(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  const struct {
    const simde__mmask8 k;
    const int16_t a[8];
    const int16_t r[8];
  } test_vec[] = {
    { UINT8_C(253),
      { -INT16_C( 30388),  INT16_C(  2371),  INT16_C( 27169), -INT16_C( 11536), -INT16_C(  3562),  INT16_C(  8598), -INT16_C( 32365), -INT16_C( 25802) },
      {  INT16_C(   274),  INT16_C(     0),  INT16_C(   212),  INT16_C(   421),  INT16_C(   484),  INT16_C(    67),  INT16_C(   259),  INT16_C(   310) } },
    { UINT8_C(251),
      { -INT16_C(  5013),  INT16_C(  5308), -INT16_C( 31777),  INT16_C( 24230), -INT16_C(  8638),  INT16_C(  1797),  INT16_C(   638),  INT16_C(  1875) },
      {  INT16_C(   472),  INT16_C(    41),  INT16_C(     0),  INT16_C(   189),  INT16_C(   444),  INT16_C(    14),  INT16_C(     4),  INT16_C(    14) } },
    { UINT8_C( 69),
      {  INT16_C( 10332),  INT16_C( 19631), -INT16_C( 14854), -INT16_C( 28609), -INT16_C( 11545),  INT16_C(  7441),  INT16_C(  3181),  INT16_C( 23176) },
      {  INT16_C(    80),  INT16_C(     0),  INT16_C(   395),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(    24),  INT16_C(     0) } },
    { UINT8_C(200),
      {  INT16_C( 14749),  INT16_C( 17227), -INT16_C( 29289), -INT16_C( 25566), -INT16_C( 24428), -INT16_C(  5986), -INT16_C(  7001), -INT16_C( 12476) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(   312),  INT16_C(     0),  INT16_C(     0),  INT16_C(   457),  INT16_C(   414) } },
    { UINT8_C(147),
      { -INT16_C( 13935), -INT16_C( 12199),  INT16_C( 16473),  INT16_C( 27298),  INT16_C(  4189), -INT16_C(  6538),  INT16_C( 15978), -INT16_C( 23677) },
      {  INT16_C(   403),  INT16_C(   416),  INT16_C(     0),  INT16_C(     0),  INT16_C(    32),  INT16_C(     0),  INT16_C(     0),  INT16_C(   327) } },
    { UINT8_C(137),
      {  INT16_C( 15302), -INT16_C(  6121), -INT16_C( 21545),  INT16_C( 30344),  INT16_C( 12179), -INT16_C( 10150), -INT16_C(  4610), -INT16_C( 14487) },
      {  INT16_C(   119),  INT16_C(     0),  INT16_C(     0),  INT16_C(   237),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(   398) } },
    { UINT8_C( 70),
      {  INT16_C(  8249), -INT16_C(  9338), -INT16_C(  7030),  INT16_C(   235),  INT16_C( 21962),  INT16_C( 19774), -INT16_C( 14087),  INT16_C( 13331) },
      {  INT16_C(     0),  INT16_C(   439),  INT16_C(   457),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(   401),  INT16_C(     0) } },
    { UINT8_C(223),
      {  INT16_C(  3068), -INT16_C( 31606),  INT16_C(  7809), -INT16_C(  9292), -INT16_C( 19722),  INT16_C( 24521),  INT16_C(  3962), -INT16_C( 25960) },
      {  INT16_C(    23),  INT16_C(   265),  INT16_C(    61),  INT16_C(   439),  INT16_C(   357),  INT16_C(     0),  INT16_C(    30),  INT16_C(   309) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi16(test_vec[i].a);
    simde__m128i r = simde_mm_maskz_srli_epi16(test_vec[i].k, a, 7);
    simde_test_x86_assert_equal_i16x8(r, simde_mm_loadu_epi16(test_vec[i].r));
  }
  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask16 k = simde_test_x86_random_mmask8();
    simde__m128i a = simde_test_x86_random_i16x8();
    simde__m128i r = simde_mm_maskz_srli_epi16(k, a, 7);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i16x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_mask_srli_epi16(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  const struct {
    const int16_t src[16];
    const simde__mmask16 k;
    const int16_t a[16];
    const int16_t r[16];
  } test_vec[] = {
    { {  INT16_C( 29590),  INT16_C( 31269),  INT16_C(  9567), -INT16_C( 19388), -INT16_C( 28316),  INT16_C( 11437), -INT16_C(  7772), -INT16_C( 24565),
        -INT16_C( 27155),  INT16_C( 28197), -INT16_C(  9805), -INT16_C( 22198),  INT16_C(  5003),  INT16_C(  1288), -INT16_C( 24542), -INT16_C( 18272) },
      UINT16_C(50452),
      {  INT16_C( 29490),  INT16_C( 30442),  INT16_C( 20007), -INT16_C( 11001), -INT16_C( 21382), -INT16_C( 31306), -INT16_C( 23732),  INT16_C( 28955),
        -INT16_C( 12782),  INT16_C( 23626), -INT16_C( 10632), -INT16_C( 32657), -INT16_C( 28197),  INT16_C( 31521),  INT16_C( 13642),  INT16_C( 31808) },
      {  INT16_C( 29590),  INT16_C( 31269),  INT16_C(   156), -INT16_C( 19388),  INT16_C(   344),  INT16_C( 11437), -INT16_C(  7772), -INT16_C( 24565),
         INT16_C(   412),  INT16_C( 28197),  INT16_C(   428), -INT16_C( 22198),  INT16_C(  5003),  INT16_C(  1288),  INT16_C(   106),  INT16_C(   248) } },
    { {  INT16_C( 11176), -INT16_C( 12301), -INT16_C(  1415), -INT16_C(  2908),  INT16_C( 23462), -INT16_C(  3207), -INT16_C( 27394),  INT16_C(  4196),
        -INT16_C( 20637), -INT16_C(  9364), -INT16_C(  9339),  INT16_C( 24667),  INT16_C( 31853), -INT16_C( 18468),  INT16_C(  7345),  INT16_C( 22835) },
      UINT16_C( 9799),
      { -INT16_C( 16087), -INT16_C( 13023), -INT16_C( 14411),  INT16_C( 11816),  INT16_C( 10170),  INT16_C(  8131),  INT16_C(  9783), -INT16_C( 23346),
         INT16_C( 21249),  INT16_C( 23679), -INT16_C(  4941), -INT16_C( 28711), -INT16_C( 30045), -INT16_C( 10324), -INT16_C(  3100),  INT16_C(  3581) },
      {  INT16_C(   386),  INT16_C(   410),  INT16_C(   399), -INT16_C(  2908),  INT16_C( 23462), -INT16_C(  3207),  INT16_C(    76),  INT16_C(  4196),
        -INT16_C( 20637),  INT16_C(   184),  INT16_C(   473),  INT16_C( 24667),  INT16_C( 31853),  INT16_C(   431),  INT16_C(  7345),  INT16_C( 22835) } },
    { {  INT16_C(  7860),  INT16_C( 27098),  INT16_C(   998), -INT16_C( 24424),  INT16_C( 23338),  INT16_C( 25023), -INT16_C( 29311), -INT16_C( 32251),
        -INT16_C( 31264), -INT16_C( 27426), -INT16_C( 18575),  INT16_C(  5411), -INT16_C( 12478),  INT16_C(  9964), -INT16_C(  5693),  INT16_C( 30515) },
      UINT16_C( 3336),
      { -INT16_C(  4383),  INT16_C( 30992),  INT16_C( 14990),  INT16_C( 20180),  INT16_C( 21916), -INT16_C( 24101), -INT16_C( 17193), -INT16_C( 19162),
        -INT16_C( 26544),  INT16_C( 29549), -INT16_C( 20563), -INT16_C( 26301),  INT16_C(  1749),  INT16_C(  2178), -INT16_C( 30083),  INT16_C( 24085) },
      {  INT16_C(  7860),  INT16_C( 27098),  INT16_C(   998),  INT16_C(   157),  INT16_C( 23338),  INT16_C( 25023), -INT16_C( 29311), -INT16_C( 32251),
         INT16_C(   304), -INT16_C( 27426),  INT16_C(   351),  INT16_C(   306), -INT16_C( 12478),  INT16_C(  9964), -INT16_C(  5693),  INT16_C( 30515) } },
    { {  INT16_C(  9848),  INT16_C(  2007), -INT16_C( 21664), -INT16_C(   939),  INT16_C( 12288), -INT16_C( 10338), -INT16_C( 15124),  INT16_C( 15501),
        -INT16_C(  1444),  INT16_C(  2480), -INT16_C(  3159),  INT16_C( 32418),  INT16_C(  9721),  INT16_C( 30342), -INT16_C( 25681),  INT16_C( 10453) },
      UINT16_C(44225),
      {  INT16_C(  8751), -INT16_C( 31656),  INT16_C( 22558), -INT16_C( 17228), -INT16_C( 24272), -INT16_C( 17023), -INT16_C(  8739), -INT16_C( 29257),
         INT16_C( 24807), -INT16_C( 30336),  INT16_C( 31198),  INT16_C( 25774),  INT16_C( 24304), -INT16_C( 14849), -INT16_C( 15994), -INT16_C( 19087) },
      {  INT16_C(    68),  INT16_C(  2007), -INT16_C( 21664), -INT16_C(   939),  INT16_C( 12288), -INT16_C( 10338),  INT16_C(   443),  INT16_C(   283),
        -INT16_C(  1444),  INT16_C(  2480),  INT16_C(   243),  INT16_C(   201),  INT16_C(  9721),  INT16_C(   395), -INT16_C( 25681),  INT16_C(   362) } },
    { { -INT16_C( 13853),  INT16_C(   313), -INT16_C(  4830),  INT16_C( 21182),  INT16_C( 16270),  INT16_C( 27663), -INT16_C( 14820),  INT16_C(  1017),
         INT16_C( 31270),  INT16_C(  1165),  INT16_C( 15347), -INT16_C(  7320),  INT16_C( 26521),  INT16_C(  8104),  INT16_C(  6696),  INT16_C(  3028) },
      UINT16_C( 3555),
      {  INT16_C(  1293), -INT16_C( 13317), -INT16_C( 30377),  INT16_C( 26122),  INT16_C(  9973), -INT16_C(  4308),  INT16_C( 21034), -INT16_C( 18583),
         INT16_C( 23638), -INT16_C( 16654), -INT16_C( 29632), -INT16_C(  6106),  INT16_C( 20139), -INT16_C( 32766), -INT16_C(  6566),  INT16_C( 26509) },
      {  INT16_C(    10),  INT16_C(   407), -INT16_C(  4830),  INT16_C( 21182),  INT16_C( 16270),  INT16_C(   478),  INT16_C(   164),  INT16_C(   366),
         INT16_C(   184),  INT16_C(  1165),  INT16_C(   280),  INT16_C(   464),  INT16_C( 26521),  INT16_C(  8104),  INT16_C(  6696),  INT16_C(  3028) } },
    { { -INT16_C( 30485),  INT16_C( 17202),  INT16_C( 15378),  INT16_C(  1961), -INT16_C( 10654), -INT16_C( 29450),  INT16_C( 24360),  INT16_C( 32579),
         INT16_C( 14012), -INT16_C(   963),  INT16_C( 25538),  INT16_C( 28132), -INT16_C(  6222),  INT16_C(  3309),  INT16_C( 31693), -INT16_C( 18317) },
      UINT16_C(42243),
      {  INT16_C(  5627), -INT16_C( 23071),  INT16_C( 17181),  INT16_C(  4987), -INT16_C( 23600),  INT16_C(  4979),  INT16_C( 12066),  INT16_C( 24649),
         INT16_C(  2859),  INT16_C(  4035),  INT16_C( 30073),  INT16_C( 26358), -INT16_C( 15487), -INT16_C(  2847), -INT16_C(  6788),  INT16_C( 30617) },
      {  INT16_C(    43),  INT16_C(   331),  INT16_C( 15378),  INT16_C(  1961), -INT16_C( 10654), -INT16_C( 29450),  INT16_C( 24360),  INT16_C( 32579),
         INT16_C(    22), -INT16_C(   963),  INT16_C(   234),  INT16_C( 28132), -INT16_C(  6222),  INT16_C(   489),  INT16_C( 31693),  INT16_C(   239) } },
    { {  INT16_C( 31482),  INT16_C(  5916), -INT16_C( 26690), -INT16_C( 29141), -INT16_C( 25029),  INT16_C( 23969), -INT16_C(  5171), -INT16_C(  1859),
        -INT16_C( 32266),  INT16_C( 28423), -INT16_C(   266),  INT16_C( 30934), -INT16_C( 18495),  INT16_C( 15724),  INT16_C(  1692), -INT16_C( 26699) },
      UINT16_C(53632),
      {  INT16_C( 16046), -INT16_C(  9879), -INT16_C( 23348),  INT16_C( 28279),  INT16_C( 17409), -INT16_C( 16551),  INT16_C( 20284),  INT16_C( 17472),
         INT16_C( 14015), -INT16_C( 27326),  INT16_C(   942),  INT16_C(  6988), -INT16_C(  5823), -INT16_C(  2527), -INT16_C( 24192),  INT16_C( 11975) },
      {  INT16_C( 31482),  INT16_C(  5916), -INT16_C( 26690), -INT16_C( 29141), -INT16_C( 25029),  INT16_C( 23969), -INT16_C(  5171),  INT16_C(   136),
         INT16_C(   109),  INT16_C( 28423), -INT16_C(   266),  INT16_C( 30934),  INT16_C(   466),  INT16_C( 15724),  INT16_C(   323),  INT16_C(    93) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i src = simde_mm256_loadu_epi16(test_vec[i].src);
    simde__m256i a = simde_mm256_loadu_epi16(test_vec[i].a);
    simde__m256i r = simde_mm256_mask_srli_epi16(src, test_vec[i].k, a, 7);
    simde_test_x86_assert_equal_i16x16(r, simde_mm256_loadu_epi16(test_vec[i].r));
  }
  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256i src = simde_test_x86_random_i16x16();
    simde__mmask16 k = simde_test_x86_random_mmask16();
    simde__m256i a = simde_test_x86_random_i16x16();
    simde__m256i r = simde_mm256_mask_srli_epi16(src, k, a, 7);

    simde_test_x86_write_i16x16(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask16(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_maskz_srli_epi16(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  const struct {
    const simde__mmask16 k;
    const int16_t a[16];
    const int16_t r[16];
  } test_vec[] = {
    { UINT16_C( 3063),
      {  INT16_C( 23247), -INT16_C( 32431), -INT16_C( 26541),  INT16_C(  8438), -INT16_C(  4828),  INT16_C( 14073), -INT16_C( 29445),  INT16_C( 28114),
         INT16_C( 14836),  INT16_C( 21035), -INT16_C( 19103),  INT16_C(  4424), -INT16_C( 19141), -INT16_C( 15493),  INT16_C( 29254),  INT16_C(  5582) },
      {  INT16_C(   181),  INT16_C(   258),  INT16_C(   304),  INT16_C(     0),  INT16_C(   474),  INT16_C(   109),  INT16_C(   281),  INT16_C(   219),
         INT16_C(   115),  INT16_C(   164),  INT16_C(     0),  INT16_C(    34),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { UINT16_C( 8396),
      {  INT16_C(  8087), -INT16_C( 29256), -INT16_C(  9152),  INT16_C( 14715),  INT16_C( 30226), -INT16_C(  6970), -INT16_C( 17693),  INT16_C(  3613),
         INT16_C( 32269),  INT16_C( 21956), -INT16_C(   112),  INT16_C(  2826),  INT16_C( 20674), -INT16_C( 28291),  INT16_C( 18789), -INT16_C(   847) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(   440),  INT16_C(   114),  INT16_C(     0),  INT16_C(     0),  INT16_C(   373),  INT16_C(    28),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(   290),  INT16_C(     0),  INT16_C(     0) } },
    { UINT16_C(26985),
      { -INT16_C( 22134),  INT16_C(  1350),  INT16_C( 22754), -INT16_C( 22405),  INT16_C( 24381),  INT16_C( 23139),  INT16_C( 28781),  INT16_C( 12761),
         INT16_C( 27077), -INT16_C( 12496), -INT16_C(  3212), -INT16_C(  3809), -INT16_C( 31612),  INT16_C( 13626), -INT16_C( 23679),  INT16_C(  2974) },
      {  INT16_C(   339),  INT16_C(     0),  INT16_C(     0),  INT16_C(   336),  INT16_C(     0),  INT16_C(   180),  INT16_C(   224),  INT16_C(     0),
         INT16_C(   211),  INT16_C(     0),  INT16_C(     0),  INT16_C(   482),  INT16_C(     0),  INT16_C(   106),  INT16_C(   327),  INT16_C(     0) } },
    { UINT16_C(58444),
      {  INT16_C( 12048), -INT16_C( 29891),  INT16_C( 31447),  INT16_C( 15082),  INT16_C( 22740), -INT16_C( 21078),  INT16_C( 28553), -INT16_C( 17898),
        -INT16_C( 30146),  INT16_C( 23981),  INT16_C( 12667), -INT16_C( 18718),  INT16_C( 25446),  INT16_C(  1113), -INT16_C( 22930),  INT16_C( 32489) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(   245),  INT16_C(   117),  INT16_C(     0),  INT16_C(     0),  INT16_C(   223),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0),  INT16_C(    98),  INT16_C(     0),  INT16_C(     0),  INT16_C(     8),  INT16_C(   332),  INT16_C(   253) } },
    { UINT16_C( 9941),
      { -INT16_C( 21495), -INT16_C(  2912),  INT16_C( 29927), -INT16_C( 28340), -INT16_C( 10974),  INT16_C( 14337),  INT16_C( 16271),  INT16_C( 15555),
         INT16_C( 16029),  INT16_C( 32621), -INT16_C( 11276),  INT16_C( 20194),  INT16_C( 20696), -INT16_C( 15884), -INT16_C( 13874), -INT16_C( 10265) },
      {  INT16_C(   344),  INT16_C(     0),  INT16_C(   233),  INT16_C(     0),  INT16_C(   426),  INT16_C(     0),  INT16_C(   127),  INT16_C(   121),
         INT16_C(     0),  INT16_C(   254),  INT16_C(   423),  INT16_C(     0),  INT16_C(     0),  INT16_C(   387),  INT16_C(     0),  INT16_C(     0) } },
    { UINT16_C(34677),
      {  INT16_C( 23755),  INT16_C(  6139),  INT16_C(  7662), -INT16_C(  4115),  INT16_C( 31830),  INT16_C(  6446), -INT16_C( 13383),  INT16_C(  9815),
         INT16_C( 19530),  INT16_C( 11514), -INT16_C( 11622), -INT16_C( 29060),  INT16_C( 19091),  INT16_C( 31319), -INT16_C( 13278), -INT16_C(  4863) },
      {  INT16_C(   185),  INT16_C(     0),  INT16_C(    59),  INT16_C(     0),  INT16_C(   248),  INT16_C(    50),  INT16_C(   407),  INT16_C(     0),
         INT16_C(   152),  INT16_C(    89),  INT16_C(   421),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(   474) } },
    { UINT16_C(64553),
      {  INT16_C(  5893), -INT16_C(  3558),  INT16_C( 28678),  INT16_C( 13422),  INT16_C( 10121), -INT16_C(  8192),  INT16_C( 19022),  INT16_C( 18476),
        -INT16_C( 14729), -INT16_C(  3302), -INT16_C( 21164), -INT16_C( 21698),  INT16_C( 24615),  INT16_C( 10360), -INT16_C( 24243),  INT16_C( 21028) },
      {  INT16_C(    46),  INT16_C(     0),  INT16_C(     0),  INT16_C(   104),  INT16_C(     0),  INT16_C(   448),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0),  INT16_C(   346),  INT16_C(   342),  INT16_C(   192),  INT16_C(    80),  INT16_C(   322),  INT16_C(   164) } },
    { UINT16_C(16056),
      { -INT16_C( 16828), -INT16_C( 19538),  INT16_C( 14322), -INT16_C(  3366),  INT16_C( 10264),  INT16_C( 17469), -INT16_C( 19344), -INT16_C( 30197),
         INT16_C( 24487), -INT16_C(  6857),  INT16_C( 24075), -INT16_C( 31931), -INT16_C( 27770), -INT16_C( 21724), -INT16_C(  8987),  INT16_C( 10985) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(   485),  INT16_C(    80),  INT16_C(   136),  INT16_C(     0),  INT16_C(   276),
         INT16_C(     0),  INT16_C(   458),  INT16_C(   188),  INT16_C(   262),  INT16_C(   295),  INT16_C(   342),  INT16_C(     0),  INT16_C(     0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i a = simde_mm256_loadu_epi16(test_vec[i].a);
    simde__m256i r = simde_mm256_maskz_srli_epi16(test_vec[i].k, a, 7);
    simde_test_x86_assert_equal_i16x16(r, simde_mm256_loadu_epi16(test_vec[i].r));
  }
  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask16 k = simde_test_x86_random_mmask16();
    simde__m256i a = simde_test_x86_random_i16x16();
    simde__m256i r = simde_mm256_maskz_srli_epi16(k, a, 7);

    simde_test_x86_write_mmask16(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i16x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

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
test_simde_mm512_mask_srli_epi16(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  const struct {
    const int16_t src[32];
    const simde__mmask32 k;
    const int16_t a[32];
    const int16_t r[32];
  } test_vec[] = {
    { { -INT16_C( 26470), -INT16_C( 29475), -INT16_C( 18481), -INT16_C(  6273), -INT16_C( 17184),  INT16_C( 20524),  INT16_C( 14192),  INT16_C(  6107),
         INT16_C(  4758), -INT16_C( 24067),  INT16_C( 17009), -INT16_C(  2268),  INT16_C( 18645), -INT16_C( 17502), -INT16_C( 29660), -INT16_C( 16667),
        -INT16_C( 15836), -INT16_C(  3253), -INT16_C( 13703),  INT16_C( 23003),  INT16_C(  1926), -INT16_C(  2390), -INT16_C( 31426), -INT16_C( 11251),
         INT16_C(  2711),  INT16_C(  2166), -INT16_C( 26035),  INT16_C(  8704), -INT16_C( 23837),  INT16_C(  2013), -INT16_C( 15826),  INT16_C( 21190) },
      UINT32_C(4266004868),
      {  INT16_C(  8667),  INT16_C( 24919),  INT16_C(   296),  INT16_C( 26199),  INT16_C( 25734),  INT16_C(  7738), -INT16_C( 20369), -INT16_C( 17370),
         INT16_C(  9803),  INT16_C( 11998), -INT16_C( 17207), -INT16_C(  2251), -INT16_C(  1154),  INT16_C(   842), -INT16_C( 28660), -INT16_C(  6399),
         INT16_C( 22705), -INT16_C(  9912), -INT16_C( 24742), -INT16_C(  8129),  INT16_C( 30980),  INT16_C( 29694),  INT16_C(  9514),  INT16_C( 29999),
         INT16_C(  3403),  INT16_C(  5283), -INT16_C( 10039),  INT16_C( 18444),  INT16_C( 22228), -INT16_C(  8117),  INT16_C( 19686), -INT16_C( 26680) },
      { -INT16_C( 26470), -INT16_C( 29475),  INT16_C(     2), -INT16_C(  6273), -INT16_C( 17184),  INT16_C( 20524),  INT16_C( 14192),  INT16_C(   376),
         INT16_C(    76), -INT16_C( 24067),  INT16_C( 17009), -INT16_C(  2268),  INT16_C(   502), -INT16_C( 17502), -INT16_C( 29660), -INT16_C( 16667),
        -INT16_C( 15836),  INT16_C(   434),  INT16_C(   318),  INT16_C( 23003),  INT16_C(  1926), -INT16_C(  2390),  INT16_C(    74), -INT16_C( 11251),
         INT16_C(  2711),  INT16_C(    41),  INT16_C(   433),  INT16_C(   144),  INT16_C(   173),  INT16_C(   448),  INT16_C(   153),  INT16_C(   303) } },
    { {  INT16_C(  4260), -INT16_C(   400), -INT16_C( 20560), -INT16_C( 19233), -INT16_C(  8920),  INT16_C( 21031),  INT16_C( 22018),  INT16_C( 20167),
         INT16_C( 27235),  INT16_C( 11618),  INT16_C( 28227),  INT16_C(  6005), -INT16_C( 16188), -INT16_C( 21769), -INT16_C( 16628), -INT16_C( 20415),
        -INT16_C( 20016), -INT16_C( 32593), -INT16_C( 29088), -INT16_C( 30412),  INT16_C( 23403),  INT16_C( 28379), -INT16_C( 23631),  INT16_C(  5308),
         INT16_C(  7693),  INT16_C( 20545), -INT16_C( 18803),  INT16_C( 20839),  INT16_C( 24438), -INT16_C( 32004),  INT16_C( 15646), -INT16_C(  4557) },
      UINT32_C(1332667119),
      { -INT16_C( 23952), -INT16_C(  9256), -INT16_C( 19203), -INT16_C( 20919),  INT16_C(  1367),  INT16_C( 25795),  INT16_C(  1060), -INT16_C( 20043),
         INT16_C(  7355),  INT16_C( 12546), -INT16_C(   389), -INT16_C( 25932), -INT16_C(  6340),  INT16_C( 11144), -INT16_C(  2103),  INT16_C( 14714),
         INT16_C( 21401), -INT16_C( 26860),  INT16_C( 24071),  INT16_C( 24133),  INT16_C(  2147), -INT16_C( 30782),  INT16_C( 30477), -INT16_C( 14280),
         INT16_C( 15252),  INT16_C(  4089), -INT16_C( 21191),  INT16_C( 30121),  INT16_C( 12948),  INT16_C( 23968),  INT16_C(  6953), -INT16_C( 15722) },
      {  INT16_C(   324),  INT16_C(   439),  INT16_C(   361),  INT16_C(   348), -INT16_C(  8920),  INT16_C(   201),  INT16_C(     8),  INT16_C(   355),
         INT16_C( 27235),  INT16_C(    98),  INT16_C( 28227),  INT16_C(  6005), -INT16_C( 16188),  INT16_C(    87),  INT16_C(   495),  INT16_C(   114),
        -INT16_C( 20016),  INT16_C(   302),  INT16_C(   188),  INT16_C(   188),  INT16_C( 23403),  INT16_C(   271),  INT16_C(   238),  INT16_C(  5308),
         INT16_C(   119),  INT16_C(    31),  INT16_C(   346),  INT16_C(   235),  INT16_C( 24438), -INT16_C( 32004),  INT16_C(    54), -INT16_C(  4557) } },
    { { -INT16_C( 21650),  INT16_C( 30041), -INT16_C( 24823),  INT16_C( 27859), -INT16_C( 27225), -INT16_C( 19212),  INT16_C( 11277), -INT16_C( 24196),
         INT16_C( 30311), -INT16_C( 24144),  INT16_C( 23075), -INT16_C( 18410), -INT16_C( 18548), -INT16_C( 19179), -INT16_C( 21294),  INT16_C( 16503),
        -INT16_C( 11945),  INT16_C( 24757), -INT16_C( 30608),  INT16_C(  6092), -INT16_C( 16355),  INT16_C( 10956),  INT16_C( 18669),  INT16_C( 21707),
         INT16_C( 31934), -INT16_C(  7435),  INT16_C(  3286),  INT16_C( 25242), -INT16_C( 20541), -INT16_C( 27369), -INT16_C( 29093), -INT16_C( 19755) },
      UINT32_C(3474098783),
      { -INT16_C(  8430),  INT16_C( 12263), -INT16_C( 19553), -INT16_C( 29606),  INT16_C(  9723), -INT16_C( 17695), -INT16_C( 10591),  INT16_C( 30620),
         INT16_C( 14050), -INT16_C( 23079), -INT16_C(  3867),  INT16_C( 16698),  INT16_C(  3967), -INT16_C(  8461),  INT16_C(  1689), -INT16_C( 21586),
        -INT16_C( 27163), -INT16_C( 31525),  INT16_C( 13640),  INT16_C( 17169), -INT16_C(  3494), -INT16_C(   771), -INT16_C( 26168), -INT16_C( 21645),
         INT16_C( 19919), -INT16_C( 19120), -INT16_C( 29891), -INT16_C( 17162), -INT16_C(  5734),  INT16_C( 13467),  INT16_C( 18927), -INT16_C( 11041) },
      {  INT16_C(   446),  INT16_C(    95),  INT16_C(   359),  INT16_C(   280),  INT16_C(    75), -INT16_C( 19212),  INT16_C(   429), -INT16_C( 24196),
         INT16_C( 30311),  INT16_C(   331),  INT16_C( 23075),  INT16_C(   130), -INT16_C( 18548), -INT16_C( 19179), -INT16_C( 21294),  INT16_C(   343),
        -INT16_C( 11945),  INT16_C(   265), -INT16_C( 30608),  INT16_C(  6092),  INT16_C(   484),  INT16_C( 10956),  INT16_C( 18669),  INT16_C( 21707),
         INT16_C(   155),  INT16_C(   362),  INT16_C(   278),  INT16_C(   377), -INT16_C( 20541), -INT16_C( 27369),  INT16_C(   147),  INT16_C(   425) } },
    { { -INT16_C( 17698),  INT16_C(  9817),  INT16_C( 27375),  INT16_C( 19049),  INT16_C( 26460),  INT16_C(  9286), -INT16_C( 18176), -INT16_C( 12081),
         INT16_C(  8198),  INT16_C( 17541),  INT16_C( 31659),  INT16_C( 17664), -INT16_C( 25756),  INT16_C( 21625),  INT16_C( 23012), -INT16_C( 15832),
        -INT16_C( 32493),  INT16_C(  1000),  INT16_C( 21227),  INT16_C( 18253), -INT16_C( 27719), -INT16_C( 18068),  INT16_C( 15180),  INT16_C( 21385),
         INT16_C(  3675),  INT16_C(  1687), -INT16_C( 26743), -INT16_C(  4532), -INT16_C( 15053),  INT16_C(  5954),  INT16_C( 27166),  INT16_C( 13018) },
      UINT32_C(3610624748),
      { -INT16_C( 32236), -INT16_C( 13025), -INT16_C( 29931),  INT16_C( 24967),  INT16_C(  4294),  INT16_C(  8884),  INT16_C( 19231), -INT16_C( 22488),
         INT16_C( 29923),  INT16_C(  5782), -INT16_C( 10182),  INT16_C( 22573),  INT16_C(  1859),  INT16_C( 12170), -INT16_C( 16438), -INT16_C(  8698),
         INT16_C(  9537),  INT16_C( 22188),  INT16_C( 13232),  INT16_C( 30648),  INT16_C( 27715),  INT16_C( 25241), -INT16_C( 15944), -INT16_C( 25845),
        -INT16_C( 24266),  INT16_C( 28849), -INT16_C(  8582), -INT16_C( 16952),  INT16_C( 21478), -INT16_C( 20244), -INT16_C(  3566),  INT16_C( 21646) },
      { -INT16_C( 17698),  INT16_C(  9817),  INT16_C(   278),  INT16_C(   195),  INT16_C( 26460),  INT16_C(    69),  INT16_C(   150),  INT16_C(   336),
         INT16_C(  8198),  INT16_C(    45),  INT16_C( 31659),  INT16_C( 17664), -INT16_C( 25756),  INT16_C( 21625),  INT16_C(   383),  INT16_C(   444),
         INT16_C(    74),  INT16_C(  1000),  INT16_C(   103),  INT16_C( 18253),  INT16_C(   216),  INT16_C(   197),  INT16_C( 15180),  INT16_C( 21385),
         INT16_C(   322),  INT16_C(   225),  INT16_C(   444), -INT16_C(  4532),  INT16_C(   167),  INT16_C(  5954),  INT16_C(   484),  INT16_C(   169) } },
    { {  INT16_C( 14872), -INT16_C( 14166),  INT16_C( 25197), -INT16_C( 20161), -INT16_C( 10033), -INT16_C( 30957),  INT16_C(  7834), -INT16_C( 12254),
        -INT16_C( 11328),  INT16_C( 14912),  INT16_C(  2225), -INT16_C( 26633), -INT16_C(  7333),  INT16_C( 28231), -INT16_C( 10539), -INT16_C(  4670),
         INT16_C( 27664),  INT16_C( 32438), -INT16_C(  2609), -INT16_C( 25041),  INT16_C( 17102),  INT16_C( 26661),  INT16_C( 18273),  INT16_C(  8504),
         INT16_C( 30746), -INT16_C( 13477),  INT16_C( 21120), -INT16_C(  9117), -INT16_C( 21963),  INT16_C(  2634),  INT16_C(  3200), -INT16_C( 28168) },
      UINT32_C(1192210040),
      {  INT16_C( 16035),  INT16_C( 29157),  INT16_C(  2688), -INT16_C(  7719),  INT16_C(  4433),  INT16_C( 27394),  INT16_C( 23945),  INT16_C(  2615),
        -INT16_C( 25937), -INT16_C(  6938),  INT16_C( 12356), -INT16_C( 14865), -INT16_C(  6340), -INT16_C( 19370),  INT16_C( 26005),  INT16_C( 14588),
        -INT16_C(  7773),  INT16_C(  9130), -INT16_C( 31764),  INT16_C( 15621),  INT16_C(  1941),  INT16_C(  7849), -INT16_C(  8091),  INT16_C(  5160),
         INT16_C(  3706), -INT16_C( 16647), -INT16_C(  6082),  INT16_C( 31363), -INT16_C(  9777),  INT16_C( 25647),  INT16_C( 11070), -INT16_C(  7780) },
      {  INT16_C( 14872), -INT16_C( 14166),  INT16_C( 25197),  INT16_C(   451),  INT16_C(    34),  INT16_C(   214),  INT16_C(   187), -INT16_C( 12254),
        -INT16_C( 11328),  INT16_C(   457),  INT16_C(    96),  INT16_C(   395), -INT16_C(  7333),  INT16_C(   360), -INT16_C( 10539),  INT16_C(   113),
         INT16_C(   451),  INT16_C(    71),  INT16_C(   263),  INT16_C(   122),  INT16_C( 17102),  INT16_C( 26661),  INT16_C( 18273),  INT16_C(  8504),
         INT16_C(    28),  INT16_C(   381),  INT16_C(   464), -INT16_C(  9117), -INT16_C( 21963),  INT16_C(  2634),  INT16_C(    86), -INT16_C( 28168) } },
    { {  INT16_C( 17932), -INT16_C(  2043),  INT16_C(  2762),  INT16_C( 24374), -INT16_C(  8431),  INT16_C( 30333), -INT16_C( 22849),  INT16_C( 14731),
        -INT16_C( 31564), -INT16_C(  3081),  INT16_C( 31596),  INT16_C( 15213), -INT16_C( 25516), -INT16_C( 27745),  INT16_C( 15303), -INT16_C( 11148),
         INT16_C( 31106),  INT16_C( 19660),  INT16_C(   643), -INT16_C( 27221),  INT16_C( 10465), -INT16_C( 24565), -INT16_C( 26930), -INT16_C( 31783),
        -INT16_C( 12006), -INT16_C( 31114), -INT16_C(  7348), -INT16_C( 24383),  INT16_C( 24704),  INT16_C( 18227), -INT16_C( 22372),  INT16_C(  7707) },
      UINT32_C(2775246881),
      {  INT16_C(  5610), -INT16_C( 13254),  INT16_C( 17725),  INT16_C(  3180),  INT16_C( 18140), -INT16_C(  2417),  INT16_C(  1303),  INT16_C( 25469),
         INT16_C( 16104),  INT16_C( 26627),  INT16_C( 14239),  INT16_C( 15280), -INT16_C( 13345),  INT16_C(    89), -INT16_C( 15437), -INT16_C( 24923),
        -INT16_C(  8232),  INT16_C(  5482), -INT16_C( 10715),  INT16_C(   289), -INT16_C( 20452),  INT16_C( 13303),  INT16_C( 29877), -INT16_C( 24938),
        -INT16_C( 25933),  INT16_C( 20998), -INT16_C( 18735), -INT16_C( 20339), -INT16_C(  6526),  INT16_C( 13744),  INT16_C( 22185), -INT16_C( 32301) },
      {  INT16_C(    43), -INT16_C(  2043),  INT16_C(  2762),  INT16_C( 24374), -INT16_C(  8431),  INT16_C(   493), -INT16_C( 22849),  INT16_C( 14731),
        -INT16_C( 31564), -INT16_C(  3081),  INT16_C( 31596),  INT16_C(   119), -INT16_C( 25516),  INT16_C(     0),  INT16_C(   391),  INT16_C(   317),
         INT16_C( 31106),  INT16_C(    42),  INT16_C(   643),  INT16_C(     2),  INT16_C( 10465),  INT16_C(   103),  INT16_C(   233), -INT16_C( 31783),
         INT16_C(   309), -INT16_C( 31114),  INT16_C(   365), -INT16_C( 24383),  INT16_C( 24704),  INT16_C(   107), -INT16_C( 22372),  INT16_C(   259) } },
    { {  INT16_C( 15669),  INT16_C( 23190), -INT16_C( 18412),  INT16_C( 12379),  INT16_C( 21352),  INT16_C(  7780), -INT16_C(  1337),  INT16_C( 31420),
        -INT16_C( 15724),  INT16_C( 26060),  INT16_C( 22905), -INT16_C(  1259), -INT16_C( 14785), -INT16_C(  6096),  INT16_C(  1052),  INT16_C( 20841),
         INT16_C(    65),  INT16_C( 21932),  INT16_C(  1976),  INT16_C(  8326), -INT16_C(  5542),  INT16_C(  8766), -INT16_C(  1308),  INT16_C( 31132),
         INT16_C( 27069),  INT16_C( 14046), -INT16_C(  2878),  INT16_C(   561),  INT16_C( 25018), -INT16_C( 10518),  INT16_C( 21605), -INT16_C( 22745) },
      UINT32_C( 217895764),
      { -INT16_C( 32037),  INT16_C( 13612),  INT16_C( 27500),  INT16_C( 20823), -INT16_C(  2971),  INT16_C(  8906), -INT16_C( 22435),  INT16_C(  8024),
        -INT16_C( 30308),  INT16_C( 22049),  INT16_C(  3307),  INT16_C( 20524),  INT16_C( 21600), -INT16_C( 19209), -INT16_C(  3033),  INT16_C(   704),
        -INT16_C(  5002), -INT16_C(  7368), -INT16_C( 28841), -INT16_C( 17100), -INT16_C(   381), -INT16_C(  7969),  INT16_C( 14502),  INT16_C( 17152),
         INT16_C(  8641), -INT16_C( 21351), -INT16_C( 14803), -INT16_C( 29187), -INT16_C(  3046),  INT16_C( 16705),  INT16_C(   488),  INT16_C( 24388) },
      {  INT16_C( 15669),  INT16_C( 23190),  INT16_C(   214),  INT16_C( 12379),  INT16_C(   488),  INT16_C(  7780),  INT16_C(   336),  INT16_C( 31420),
         INT16_C(   275),  INT16_C(   172),  INT16_C( 22905), -INT16_C(  1259),  INT16_C(   168), -INT16_C(  6096),  INT16_C(   488),  INT16_C(     5),
         INT16_C(    65),  INT16_C( 21932),  INT16_C(   286),  INT16_C(   378),  INT16_C(   509),  INT16_C(   449),  INT16_C(   113),  INT16_C(   134),
         INT16_C( 27069),  INT16_C( 14046),  INT16_C(   396),  INT16_C(   283),  INT16_C( 25018), -INT16_C( 10518),  INT16_C( 21605), -INT16_C( 22745) } },
    { {  INT16_C( 31982),  INT16_C( 17730),  INT16_C( 30219), -INT16_C( 28926), -INT16_C(  7564),  INT16_C(  6767),  INT16_C( 28442), -INT16_C(  9379),
        -INT16_C(  2159), -INT16_C( 16760), -INT16_C( 31299), -INT16_C( 10420), -INT16_C( 29319),  INT16_C( 25112),  INT16_C( 23695),  INT16_C( 32193),
         INT16_C(   984), -INT16_C(  6974), -INT16_C( 14983), -INT16_C(  4749), -INT16_C(  7513), -INT16_C( 16121),  INT16_C( 25938), -INT16_C(  7268),
         INT16_C(  9308),  INT16_C(  6561), -INT16_C(  4695),  INT16_C(  9200),  INT16_C(  2171),  INT16_C(  2693),  INT16_C( 18021),  INT16_C( 15751) },
      UINT32_C(3256961353),
      { -INT16_C( 27634), -INT16_C( 19025), -INT16_C( 18825), -INT16_C( 13962),  INT16_C(  4891),  INT16_C( 30636),  INT16_C( 19767), -INT16_C(  7792),
        -INT16_C( 32709), -INT16_C( 18940), -INT16_C( 30327), -INT16_C(  4416),  INT16_C( 18383),  INT16_C(  6187),  INT16_C( 19856), -INT16_C( 24614),
        -INT16_C( 30239),  INT16_C( 22612), -INT16_C( 13505),  INT16_C( 23329), -INT16_C( 12834),  INT16_C(  5586),  INT16_C( 25371),  INT16_C( 22262),
        -INT16_C(  1309),  INT16_C( 27660), -INT16_C( 13181),  INT16_C( 21082), -INT16_C( 31213), -INT16_C( 23702),  INT16_C( 17619), -INT16_C( 19390) },
      {  INT16_C(   296),  INT16_C( 17730),  INT16_C( 30219),  INT16_C(   402), -INT16_C(  7564),  INT16_C(  6767),  INT16_C(   154), -INT16_C(  9379),
         INT16_C(   256), -INT16_C( 16760), -INT16_C( 31299),  INT16_C(   477), -INT16_C( 29319),  INT16_C( 25112),  INT16_C(   155),  INT16_C( 32193),
         INT16_C(   275), -INT16_C(  6974), -INT16_C( 14983), -INT16_C(  4749), -INT16_C(  7513),  INT16_C(    43),  INT16_C( 25938), -INT16_C(  7268),
         INT16_C(  9308),  INT16_C(   216), -INT16_C(  4695),  INT16_C(  9200),  INT16_C(  2171),  INT16_C(  2693),  INT16_C(   137),  INT16_C(   360) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i src = simde_mm512_loadu_epi16(test_vec[i].src);
    simde__m512i a = simde_mm512_loadu_epi16(test_vec[i].a);
    simde__m512i r = simde_mm512_mask_srli_epi16(src, test_vec[i].k, a, 7);
    simde_test_x86_assert_equal_i16x32(r, simde_mm512_loadu_epi16(test_vec[i].r));
  }
  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512i src = simde_test_x86_random_i16x32();
    simde__mmask32 k = simde_test_x86_random_mmask32();
    simde__m512i a = simde_test_x86_random_i16x32();
    simde__m512i r = simde_mm512_mask_srli_epi16(src, k, a, 7);

    simde_test_x86_write_i16x32(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask32(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x32(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_maskz_srli_epi16(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  const struct {
    const simde__mmask32 k;
    const int16_t a[32];
    const int16_t r[32];
  } test_vec[] = {
    { UINT32_C( 218994637),
      {  INT16_C( 11874),  INT16_C( 16488),  INT16_C( 15100),  INT16_C(  5973),  INT16_C( 19613), -INT16_C( 32403),  INT16_C( 31046), -INT16_C( 13587),
         INT16_C( 18501),  INT16_C( 22556), -INT16_C( 30770), -INT16_C( 24069),  INT16_C( 16075), -INT16_C( 26283),  INT16_C( 25301),  INT16_C( 14246),
         INT16_C(  3729), -INT16_C( 29321), -INT16_C( 13240), -INT16_C(  6492),  INT16_C(  4376),  INT16_C( 24423),  INT16_C( 21642), -INT16_C( 12503),
         INT16_C( 17820),  INT16_C( 27175),  INT16_C(  8908), -INT16_C( 26613),  INT16_C( 24928),  INT16_C( 13617), -INT16_C( 10301),  INT16_C( 21612) },
      {  INT16_C(    92),  INT16_C(     0),  INT16_C(   117),  INT16_C(    46),  INT16_C(     0),  INT16_C(     0),  INT16_C(   242),  INT16_C(   405),
         INT16_C(   144),  INT16_C(   176),  INT16_C(   271),  INT16_C(     0),  INT16_C(   125),  INT16_C(     0),  INT16_C(     0),  INT16_C(   111),
         INT16_C(    29),  INT16_C(     0),  INT16_C(   408),  INT16_C(   461),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C(   139),  INT16_C(     0),  INT16_C(    69),  INT16_C(   304),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { UINT32_C( 769778661),
      { -INT16_C( 31312), -INT16_C( 14317),  INT16_C( 31382),  INT16_C(  8231),  INT16_C( 20687),  INT16_C( 27631),  INT16_C(  5782),  INT16_C( 25302),
        -INT16_C(  7879), -INT16_C( 26118),  INT16_C( 11074),  INT16_C(  1743),  INT16_C( 15106), -INT16_C(  6310),  INT16_C( 15391), -INT16_C( 12523),
         INT16_C( 10433),  INT16_C( 22679), -INT16_C( 16477),  INT16_C( 29304),  INT16_C( 26639), -INT16_C( 23075), -INT16_C( 19586), -INT16_C( 18680),
         INT16_C(   661), -INT16_C( 10415),  INT16_C(  8238),  INT16_C( 12509),  INT16_C( 14427),  INT16_C( 31256),  INT16_C( 11636),  INT16_C( 13641) },
      {  INT16_C(   267),  INT16_C(     0),  INT16_C(   245),  INT16_C(     0),  INT16_C(     0),  INT16_C(   215),  INT16_C(    45),  INT16_C(   197),
         INT16_C(   450),  INT16_C(   307),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(   462),  INT16_C(   120),  INT16_C(   414),
         INT16_C(    81),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(   331),  INT16_C(   358),  INT16_C(   366),
         INT16_C(     5),  INT16_C(     0),  INT16_C(    64),  INT16_C(    97),  INT16_C(     0),  INT16_C(   244),  INT16_C(     0),  INT16_C(     0) } },
    { UINT32_C(4170047829),
      {  INT16_C(  1696), -INT16_C( 20630),  INT16_C( 18542), -INT16_C(  5035),  INT16_C( 24059), -INT16_C( 28508), -INT16_C(  2721), -INT16_C( 29336),
         INT16_C( 17685),  INT16_C( 28862), -INT16_C( 10627), -INT16_C(  3605),  INT16_C( 13315),  INT16_C( 22567), -INT16_C( 19435), -INT16_C( 19119),
        -INT16_C( 17478),  INT16_C( 10341), -INT16_C( 17917), -INT16_C(   235), -INT16_C( 18153),  INT16_C( 30351), -INT16_C(  2130), -INT16_C( 15612),
        -INT16_C( 15811), -INT16_C( 17869),  INT16_C(  7832), -INT16_C( 25684), -INT16_C( 11437),  INT16_C( 26867),  INT16_C( 17543),  INT16_C( 16926) },
      {  INT16_C(    13),  INT16_C(     0),  INT16_C(   144),  INT16_C(     0),  INT16_C(   187),  INT16_C(     0),  INT16_C(   490),  INT16_C(     0),
         INT16_C(   138),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(   176),  INT16_C(   360),  INT16_C(   362),
         INT16_C(   375),  INT16_C(     0),  INT16_C(   372),  INT16_C(   510),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(   390),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(   311),  INT16_C(   422),  INT16_C(   209),  INT16_C(   137),  INT16_C(   132) } },
    { UINT32_C(  57312000),
      {  INT16_C( 32573),  INT16_C( 21506), -INT16_C( 28104), -INT16_C(  6454), -INT16_C( 12663), -INT16_C( 14679), -INT16_C(  8816),  INT16_C( 10369),
         INT16_C( 11771),  INT16_C( 20163), -INT16_C( 18688), -INT16_C( 30793), -INT16_C( 10757), -INT16_C(  1079),  INT16_C( 13400), -INT16_C( 27137),
         INT16_C(   435), -INT16_C(  4887), -INT16_C( 19565),  INT16_C(  7634),  INT16_C( 31874),  INT16_C(  4835),  INT16_C( 25689),  INT16_C( 21563),
        -INT16_C(   367), -INT16_C( 28253),  INT16_C( 23221), -INT16_C( 20199), -INT16_C(  7633), -INT16_C( 30804), -INT16_C( 21738), -INT16_C( 13796) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C(    91),  INT16_C(   157),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(   299),
         INT16_C(     0),  INT16_C(   473),  INT16_C(     0),  INT16_C(    59),  INT16_C(     0),  INT16_C(    37),  INT16_C(   200),  INT16_C(     0),
         INT16_C(   509),  INT16_C(   291),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { UINT32_C(1085670829),
      { -INT16_C( 30536),  INT16_C( 14941),  INT16_C( 16644),  INT16_C( 23885), -INT16_C( 30555),  INT16_C( 14258),  INT16_C( 21894),  INT16_C( 15560),
        -INT16_C(  7761), -INT16_C(  8467), -INT16_C( 26172), -INT16_C(  9627), -INT16_C( 32443), -INT16_C(  3420),  INT16_C( 23174),  INT16_C( 15922),
        -INT16_C( 28445), -INT16_C(  6279), -INT16_C( 14639),  INT16_C( 30277), -INT16_C(  2226), -INT16_C( 11091),  INT16_C( 30284), -INT16_C(  1264),
        -INT16_C(   681),  INT16_C(  7129),  INT16_C( 16023), -INT16_C(  8970), -INT16_C( 25921),  INT16_C( 17870),  INT16_C(   245), -INT16_C( 10109) },
      {  INT16_C(   273),  INT16_C(     0),  INT16_C(   130),  INT16_C(   186),  INT16_C(     0),  INT16_C(   111),  INT16_C(     0),  INT16_C(   121),
         INT16_C(   451),  INT16_C(     0),  INT16_C(   307),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0),  INT16_C(   462),  INT16_C(   397),  INT16_C(     0),  INT16_C(   494),  INT16_C(   425),  INT16_C(     0),  INT16_C(   502),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     1),  INT16_C(     0) } },
    { UINT32_C(1639971984),
      {  INT16_C(  1218),  INT16_C(  4312), -INT16_C( 31237),  INT16_C( 18405), -INT16_C(  2565),  INT16_C( 21314),  INT16_C(  7155), -INT16_C( 30098),
         INT16_C( 25689),  INT16_C(  6246),  INT16_C( 13567), -INT16_C(  2979), -INT16_C(  7884), -INT16_C( 14900), -INT16_C( 29731), -INT16_C( 24538),
        -INT16_C(   368), -INT16_C( 29776), -INT16_C( 27260),  INT16_C( 32723),  INT16_C(  5515),  INT16_C( 32466),  INT16_C( 16689), -INT16_C( 30200),
         INT16_C( 28325), -INT16_C( 23389),  INT16_C(   162), -INT16_C( 10600),  INT16_C( 25825), -INT16_C( 16485), -INT16_C( 15632), -INT16_C( 32673) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(   491),  INT16_C(     0),  INT16_C(     0),  INT16_C(   276),
         INT16_C(     0),  INT16_C(     0),  INT16_C(   105),  INT16_C(   488),  INT16_C(   450),  INT16_C(   395),  INT16_C(   279),  INT16_C(   320),
         INT16_C(   509),  INT16_C(   279),  INT16_C(   299),  INT16_C(   255),  INT16_C(    43),  INT16_C(   253),  INT16_C(     0),  INT16_C(   276),
         INT16_C(   221),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(   383),  INT16_C(   389),  INT16_C(     0) } },
    { UINT32_C(1141575616),
      { -INT16_C(  8539),  INT16_C( 12484), -INT16_C( 26892),  INT16_C(  9646), -INT16_C( 18729),  INT16_C( 32175),  INT16_C( 21028), -INT16_C( 14815),
        -INT16_C( 17837),  INT16_C( 13468),  INT16_C( 14366),  INT16_C(  3827),  INT16_C( 21242), -INT16_C( 17778), -INT16_C( 26014),  INT16_C(  2047),
        -INT16_C( 15496),  INT16_C( 27703), -INT16_C(  6823),  INT16_C( 12689),  INT16_C( 16795), -INT16_C( 16466), -INT16_C( 12397), -INT16_C(  6523),
         INT16_C(  8585), -INT16_C( 22501),  INT16_C(  3673),  INT16_C( 21430),  INT16_C( 17761), -INT16_C( 15602),  INT16_C(  3551),  INT16_C( 22474) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(   164),  INT16_C(   396),
         INT16_C(   372),  INT16_C(   105),  INT16_C(   112),  INT16_C(    29),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C(   390),  INT16_C(   216),  INT16_C(     0),  INT16_C(    99),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0),  INT16_C(    28),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(    27),  INT16_C(     0) } },
    { UINT32_C( 700711376),
      {  INT16_C( 21990), -INT16_C( 32422),  INT16_C(  2198),  INT16_C( 10816), -INT16_C( 14888),  INT16_C( 24848),  INT16_C( 11238),  INT16_C( 16393),
        -INT16_C( 16326), -INT16_C( 25709), -INT16_C( 24315), -INT16_C(  7074),  INT16_C( 10414),  INT16_C( 32315), -INT16_C(   215),  INT16_C(  4008),
         INT16_C(   597), -INT16_C(  5232), -INT16_C( 12277), -INT16_C(  7403),  INT16_C(  9877),  INT16_C( 31556),  INT16_C( 20049), -INT16_C( 29765),
         INT16_C( 20238),  INT16_C(  4902), -INT16_C( 31504), -INT16_C( 24585),  INT16_C( 12972), -INT16_C( 10979), -INT16_C( 15054), -INT16_C( 30748) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(   395),  INT16_C(     0),  INT16_C(    87),  INT16_C(   128),
         INT16_C(   384),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0),  INT16_C(   416),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(   156),  INT16_C(   279),
         INT16_C(   158),  INT16_C(     0),  INT16_C(     0),  INT16_C(   319),  INT16_C(     0),  INT16_C(   426),  INT16_C(     0),  INT16_C(     0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_epi16(test_vec[i].a);
    simde__m512i r = simde_mm512_maskz_srli_epi16(test_vec[i].k, a, 7);
    simde_test_x86_assert_equal_i16x32(r, simde_mm512_loadu_epi16(test_vec[i].r));
  }
  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask32 k = simde_test_x86_random_mmask32();
    simde__m512i a = simde_test_x86_random_i16x32();
    simde__m512i r = simde_mm512_maskz_srli_epi16(k, a, 7);

    simde_test_x86_write_mmask32(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i16x32(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_mask_srli_epi32(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  const struct {
    const int32_t src[4];
    const simde__mmask8 k;
    const int32_t a[4];
    const int32_t r[4];
  } test_vec[] = {
    { { -INT32_C(   747473720), -INT32_C(   642348988), -INT32_C(    11142482),  INT32_C(  1451954248) },
      UINT8_C( 95),
      {  INT32_C(   911239601), -INT32_C(  1813844128), -INT32_C(   758794228),  INT32_C(   295324828) },
      {  INT32_C(     7119059),  INT32_C(    19383774),  INT32_C(    27626352),  INT32_C(     2307225) } },
    { {  INT32_C(  1180003774),  INT32_C(   502542115), -INT32_C(  1805192060),  INT32_C(   821345407) },
      UINT8_C( 38),
      {  INT32_C(   864446020),  INT32_C(    20912457),  INT32_C(   714936798),  INT32_C(   417967787) },
      {  INT32_C(  1180003774),  INT32_C(      163378),  INT32_C(     5585443),  INT32_C(   821345407) } },
    { {  INT32_C(   859516676),  INT32_C(   414669092),  INT32_C(  2073512895), -INT32_C(  2086549697) },
      UINT8_C( 46),
      {  INT32_C(  1098364456),  INT32_C(   119568630), -INT32_C(   994883051),  INT32_C(  1674103603) },
      {  INT32_C(   859516676),  INT32_C(      934129),  INT32_C(    25781908),  INT32_C(    13078934) } },
    { {  INT32_C(  1619524359), -INT32_C(    48259150), -INT32_C(    46294474),  INT32_C(  1680588860) },
      UINT8_C(119),
      {  INT32_C(   443393442),  INT32_C(   271611077), -INT32_C(   213650393), -INT32_C(  1208310084) },
      {  INT32_C(     3464011),  INT32_C(     2121961),  INT32_C(    31885288),  INT32_C(  1680588860) } },
    { { -INT32_C(   865510867),  INT32_C(   318924409),  INT32_C(  1682899107), -INT32_C(   824462549) },
      UINT8_C( 89),
      { -INT32_C(  1138825144),  INT32_C(   216280600),  INT32_C(   415815538),  INT32_C(   726040529) },
      {  INT32_C(    24657360),  INT32_C(   318924409),  INT32_C(  1682899107),  INT32_C(     5672191) } },
    { {  INT32_C(  1336152808),  INT32_C(   368228117), -INT32_C(  1170188793),  INT32_C(  2031291953) },
      UINT8_C(247),
      {  INT32_C(  1611609650), -INT32_C(   237888486),  INT32_C(  1690495972),  INT32_C(  1129114929) },
      {  INT32_C(    12590700),  INT32_C(    31695928),  INT32_C(    13206999),  INT32_C(  2031291953) } },
    { {  INT32_C(  1213766545), -INT32_C(   464556658), -INT32_C(  1139406162),  INT32_C(  1337167645) },
      UINT8_C(197),
      { -INT32_C(   538988349),  INT32_C(  1841549442),  INT32_C(  2141071250),  INT32_C(   252764788) },
      {  INT32_C(    29343585), -INT32_C(   464556658),  INT32_C(    16727119),  INT32_C(  1337167645) } },
    { { -INT32_C(  1466083014), -INT32_C(  1302953304),  INT32_C(   667947672), -INT32_C(  1980948538) },
      UINT8_C(207),
      { -INT32_C(  1655543604),  INT32_C(  1395638059),  INT32_C(  1086828382),  INT32_C(   410703551) },
      {  INT32_C(    20620497),  INT32_C(    10903422),  INT32_C(     8490846),  INT32_C(     3208621) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i src = simde_mm_loadu_epi32(test_vec[i].src);
    simde__m128i a = simde_mm_loadu_epi32(test_vec[i].a);
    simde__m128i r = simde_mm_mask_srli_epi32(src, test_vec[i].k, a, 7);
    simde_test_x86_assert_equal_i32x4(r, simde_mm_loadu_epi32(test_vec[i].r));
  }
  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i src = simde_test_x86_random_i32x4();
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128i a = simde_test_x86_random_i32x4();
    simde__m128i r = simde_mm_mask_srli_epi32(src, k, a, 7);

    simde_test_x86_write_i32x4(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_maskz_srli_epi32(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  const struct {
    const simde__mmask8 k;
    const int32_t a[4];
    const int32_t r[4];
  } test_vec[] = {
    { UINT8_C( 85),
      { -INT32_C(   329416768),  INT32_C(   691753345), -INT32_C(  1716433061), -INT32_C(   684309919) },
      {  INT32_C(    30980863),  INT32_C(           0),  INT32_C(    20144798),  INT32_C(           0) } },
    { UINT8_C(207),
      { -INT32_C(   997835278),  INT32_C(   358689715), -INT32_C(   911459560),  INT32_C(  1938424308) },
      {  INT32_C(    25758843),  INT32_C(     2802263),  INT32_C(    26433654),  INT32_C(    15143939) } },
    { UINT8_C( 94),
      { -INT32_C(  1313868682), -INT32_C(   822015203), -INT32_C(   636394844),  INT32_C(  2009915450) },
      {  INT32_C(           0),  INT32_C(    27132438),  INT32_C(    28582597),  INT32_C(    15702464) } },
    { UINT8_C(102),
      { -INT32_C(   225301872), -INT32_C(   332551616), -INT32_C(    34791053), -INT32_C(  1988866924) },
      {  INT32_C(           0),  INT32_C(    30956372),  INT32_C(    33282626),  INT32_C(           0) } },
    { UINT8_C(251),
      {  INT32_C(   637969957), -INT32_C(  2021021067),  INT32_C(  1365754756),  INT32_C(  1709297210) },
      {  INT32_C(     4984140),  INT32_C(    17765204),  INT32_C(           0),  INT32_C(    13353884) } },
    { UINT8_C( 96),
      {  INT32_C(    17475027),  INT32_C(  2116189585), -INT32_C(   271927429), -INT32_C(   434846144) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { UINT8_C(204),
      { -INT32_C(   998810565),  INT32_C(  1250425827),  INT32_C(   773374284), -INT32_C(   889096154) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(     6041986),  INT32_C(    26608368) } },
    { UINT8_C(130),
      {  INT32_C(   620780546), -INT32_C(  1512277029),  INT32_C(  2120948842),  INT32_C(  1589196802) },
      {  INT32_C(           0),  INT32_C(    21739767),  INT32_C(           0),  INT32_C(           0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi32(test_vec[i].a);
    simde__m128i r = simde_mm_maskz_srli_epi32(test_vec[i].k, a, 7);
    simde_test_x86_assert_equal_i32x4(r, simde_mm_loadu_epi32(test_vec[i].r));
  }
  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128i a = simde_test_x86_random_i32x4();
    simde__m128i r = simde_mm_maskz_srli_epi32(k, a, 7);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_mask_srli_epi32(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  const struct {
    const int32_t src[8];
    const simde__mmask8 k;
    const int32_t a[8];
    const int32_t r[8];
  } test_vec[] = {
    { { -INT32_C(   890610197), -INT32_C(  1147451028), -INT32_C(  1587035278), -INT32_C(    17689199),  INT32_C(  1439030984),  INT32_C(  1599678045), -INT32_C(   950679721), -INT32_C(  1987672674) },
      UINT8_C(226),
      { -INT32_C(  1186049168), -INT32_C(  1322513682), -INT32_C(  2025665167), -INT32_C(  1638973248),  INT32_C(   754754822), -INT32_C(   964469762),  INT32_C(   895765424),  INT32_C(  1092087249) },
      { -INT32_C(   890610197),  INT32_C(    23222293), -INT32_C(  1587035278), -INT32_C(    17689199),  INT32_C(  1439030984),  INT32_C(    26019511),  INT32_C(     6998167),  INT32_C(     8531931) } },
    { {  INT32_C(   805004609), -INT32_C(   505338001), -INT32_C(  1268243468),  INT32_C(  1783871332),  INT32_C(  1536577372),  INT32_C(  1512118954),  INT32_C(   915375461), -INT32_C(  1284004238) },
      UINT8_C( 11),
      { -INT32_C(  1719934094), -INT32_C(   410100540),  INT32_C(  2068529860), -INT32_C(   455559787),  INT32_C(  1720595276), -INT32_C(   640948140),  INT32_C(   491454839), -INT32_C(   349569160) },
      {  INT32_C(    20117446),  INT32_C(    30350521), -INT32_C(  1268243468),  INT32_C(    29995371),  INT32_C(  1536577372),  INT32_C(  1512118954),  INT32_C(   915375461), -INT32_C(  1284004238) } },
    { { -INT32_C(  1501256478), -INT32_C(   997387776), -INT32_C(   364914347), -INT32_C(   623962226), -INT32_C(  1639948982), -INT32_C(  1116271802), -INT32_C(  2049195252), -INT32_C(  1536162622) },
      UINT8_C(168),
      {  INT32_C(   128469748), -INT32_C(  1336120105), -INT32_C(  1019263317),  INT32_C(  1930238229),  INT32_C(  1706667098), -INT32_C(   428706269),  INT32_C(  1437136721),  INT32_C(  1543326823) },
      { -INT32_C(  1501256478), -INT32_C(   997387776), -INT32_C(   364914347),  INT32_C(    15079986), -INT32_C(  1639948982),  INT32_C(    30205164), -INT32_C(  2049195252),  INT32_C(    12057240) } },
    { {  INT32_C(  1851958678), -INT32_C(  1122058735),  INT32_C(   444620037), -INT32_C(   779252361),  INT32_C(  1563838009),  INT32_C(   239315133),  INT32_C(   107277471), -INT32_C(   815636168) },
      UINT8_C(  7),
      { -INT32_C(  2095563324), -INT32_C(  1182214821), -INT32_C(   483351979),  INT32_C(  1981546800), -INT32_C(   533497545), -INT32_C(  1451277635),  INT32_C(   132220582), -INT32_C(  1408323352) },
      {  INT32_C(    17182843),  INT32_C(    24318378),  INT32_C(    29778244), -INT32_C(   779252361),  INT32_C(  1563838009),  INT32_C(   239315133),  INT32_C(   107277471), -INT32_C(   815636168) } },
    { {  INT32_C(  1227827181),  INT32_C(  1375909884), -INT32_C(  1976225190),  INT32_C(  1778405683), -INT32_C(  2008402741),  INT32_C(   473025142),  INT32_C(   941822544), -INT32_C(  1327222077) },
      UINT8_C( 89),
      { -INT32_C(   883558124),  INT32_C(   757442555),  INT32_C(   778088412), -INT32_C(   453391440), -INT32_C(   547716843), -INT32_C(  1003522382), -INT32_C(   880318567),  INT32_C(  1612986444) },
      {  INT32_C(    26651634),  INT32_C(  1375909884), -INT32_C(  1976225190),  INT32_C(    30012311),  INT32_C(    29275394),  INT32_C(   473025142),  INT32_C(    26676943), -INT32_C(  1327222077) } },
    { {  INT32_C(   757824049), -INT32_C(    27635423), -INT32_C(  1339245824), -INT32_C(  1684789882),  INT32_C(  1484517030), -INT32_C(    31675804),  INT32_C(  1590273042),  INT32_C(   230616796) },
      UINT8_C(104),
      {  INT32_C(   982072041),  INT32_C(  1346078613), -INT32_C(   657003597),  INT32_C(  1853780352), -INT32_C(  1747724564), -INT32_C(  1750478349), -INT32_C(  2005727334), -INT32_C(  1359970107) },
      {  INT32_C(   757824049), -INT32_C(    27635423), -INT32_C(  1339245824),  INT32_C(    14482659),  INT32_C(  1484517030),  INT32_C(    19878819),  INT32_C(    17884687),  INT32_C(   230616796) } },
    { {  INT32_C(  1357478587), -INT32_C(  1247796223), -INT32_C(  1886554609), -INT32_C(   721548057), -INT32_C(   714354206),  INT32_C(  1013716130), -INT32_C(   523903205),  INT32_C(   462337376) },
      UINT8_C( 47),
      { -INT32_C(  1691260041), -INT32_C(  2119440885),  INT32_C(  2137537139),  INT32_C(   157432888), -INT32_C(  1146407001), -INT32_C(  2083067740),  INT32_C(  1659090605), -INT32_C(  1131217339) },
      {  INT32_C(    20341462),  INT32_C(    16996300),  INT32_C(    16699508),  INT32_C(     1229944), -INT32_C(   714354206),  INT32_C(    17280465), -INT32_C(   523903205),  INT32_C(   462337376) } },
    { {  INT32_C(  1951974249),  INT32_C(   485819305),  INT32_C(  1989959229),  INT32_C(  1115684506), -INT32_C(   637719755), -INT32_C(  1067592685), -INT32_C(   819838838), -INT32_C(  1467173825) },
      UINT8_C(119),
      { -INT32_C(   417325596),  INT32_C(  1881423122), -INT32_C(   687105319),  INT32_C(  1158434074),  INT32_C(   509142602), -INT32_C(  2086070205), -INT32_C(   272467910), -INT32_C(   395941116) },
      {  INT32_C(    30294075),  INT32_C(    14698618),  INT32_C(    28186421),  INT32_C(  1115684506),  INT32_C(     3977676),  INT32_C(    17257008),  INT32_C(    31425776), -INT32_C(  1467173825) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i src = simde_mm256_loadu_epi32(test_vec[i].src);
    simde__m256i a = simde_mm256_loadu_epi32(test_vec[i].a);
    simde__m256i r = simde_mm256_mask_srli_epi32(src, test_vec[i].k, a, 7);
    simde_test_x86_assert_equal_i32x8(r, simde_mm256_loadu_epi32(test_vec[i].r));
  }
  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256i src = simde_test_x86_random_i32x8();
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256i a = simde_test_x86_random_i32x8();
    simde__m256i r = simde_mm256_mask_srli_epi32(src, k, a, 7);

    simde_test_x86_write_i32x8(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_maskz_srli_epi32(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  const struct {
    const simde__mmask8 k;
    const int32_t a[8];
    const int32_t r[8];
  } test_vec[] = {
    { UINT8_C(175),
      {  INT32_C(    78266749), -INT32_C(  1530464372),  INT32_C(   639495205),  INT32_C(   338272184),  INT32_C(   451890847),  INT32_C(  1183094058),  INT32_C(   944243456),  INT32_C(   988260284) },
      {  INT32_C(      611458),  INT32_C(    21597679),  INT32_C(     4996056),  INT32_C(     2642751),  INT32_C(           0),  INT32_C(     9242922),  INT32_C(           0),  INT32_C(     7720783) } },
    { UINT8_C(232),
      { -INT32_C(  1988870510), -INT32_C(   240248572), -INT32_C(   710290378),  INT32_C(  1266007549),  INT32_C(  1115000749),  INT32_C(   390249236), -INT32_C(  1412203772), -INT32_C(   191689374) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(     9890683),  INT32_C(           0),  INT32_C(     3048822),  INT32_C(    22521590),  INT32_C(    32056858) } },
    { UINT8_C( 76),
      {  INT32_C(   558923016),  INT32_C(     5718315), -INT32_C(  1459802902),  INT32_C(   827672993),  INT32_C(  2051381182),  INT32_C(  1417567449),  INT32_C(  1035413807), -INT32_C(   997610564) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(    22149721),  INT32_C(     6466195),  INT32_C(           0),  INT32_C(           0),  INT32_C(     8089170),  INT32_C(           0) } },
    { UINT8_C( 41),
      {  INT32_C(   458548697),  INT32_C(  1761956924), -INT32_C(  1693799086), -INT32_C(  1722205438), -INT32_C(   596388992),  INT32_C(  2047657809),  INT32_C(   708266366), -INT32_C(  1420559406) },
      {  INT32_C(     3582411),  INT32_C(           0),  INT32_C(           0),  INT32_C(    20099702),  INT32_C(           0),  INT32_C(    15997326),  INT32_C(           0),  INT32_C(           0) } },
    { UINT8_C(225),
      { -INT32_C(    65157465),  INT32_C(  2035189452), -INT32_C(   864228975),  INT32_C(   374150466),  INT32_C(  1348938120),  INT32_C(  2127487541),  INT32_C(   340850713), -INT32_C(   201982901) },
      {  INT32_C(    33045389),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(    16620996),  INT32_C(     2662896),  INT32_C(    31976440) } },
    { UINT8_C(194),
      { -INT32_C(  1718685933),  INT32_C(   640288829), -INT32_C(  1721174140),  INT32_C(  1830977092), -INT32_C(   928812314),  INT32_C(   971055424),  INT32_C(  1854207346), -INT32_C(    30378005) },
      {  INT32_C(           0),  INT32_C(     5002256),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(    14485994),  INT32_C(    33317103) } },
    { UINT8_C(102),
      { -INT32_C(   945580097), -INT32_C(  1186215486), -INT32_C(  1325538254),  INT32_C(  2023123462),  INT32_C(   800677389),  INT32_C(   899805759), -INT32_C(   299888778), -INT32_C(    28041665) },
      {  INT32_C(           0),  INT32_C(    24287123),  INT32_C(    23198664),  INT32_C(           0),  INT32_C(           0),  INT32_C(     7029732),  INT32_C(    31211550),  INT32_C(           0) } },
    { UINT8_C(181),
      { -INT32_C(  1049115144), -INT32_C(   168611824), -INT32_C(  1728338899), -INT32_C(  1717210054),  INT32_C(   534303789), -INT32_C(  2070606475),  INT32_C(  1271169837), -INT32_C(   805190952) },
      {  INT32_C(    25358219),  INT32_C(           0),  INT32_C(    20051784),  INT32_C(           0),  INT32_C(     4174248),  INT32_C(    17377818),  INT32_C(           0),  INT32_C(    27263877) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i a = simde_mm256_loadu_epi32(test_vec[i].a);
    simde__m256i r = simde_mm256_maskz_srli_epi32(test_vec[i].k, a, 7);
    simde_test_x86_assert_equal_i32x8(r, simde_mm256_loadu_epi32(test_vec[i].r));
  }
  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256i a = simde_test_x86_random_i32x8();
    simde__m256i r = simde_mm256_maskz_srli_epi32(k, a, 7);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
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
test_simde_mm512_mask_srli_epi32(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  const struct {
    const int32_t src[16];
    const simde__mmask16 k;
    const int32_t a[16];
    const int32_t r[16];
  } test_vec[] = {
    { {  INT32_C(  1042267835),  INT32_C(   539106445), -INT32_C(   921518253),  INT32_C(   223977517), -INT32_C(    74999377), -INT32_C(  1924410034),  INT32_C(  1332672789), -INT32_C(  1859708714),
         INT32_C(  1674528470), -INT32_C(  1232866717), -INT32_C(   562063951), -INT32_C(   437528267), -INT32_C(  1059032206),  INT32_C(  1582181192), -INT32_C(    72500187), -INT32_C(  1433611052) },
      UINT16_C(23578),
      { -INT32_C(  1873904371), -INT32_C(  1289289933), -INT32_C(   913548323),  INT32_C(   557645376),  INT32_C(   206341310), -INT32_C(  1882623518), -INT32_C(   110912148),  INT32_C(  1431666248),
         INT32_C(   803644411),  INT32_C(  2145520802), -INT32_C(  1471648153),  INT32_C(   717849708), -INT32_C(   348711671), -INT32_C(   210042745), -INT32_C(   437461347),  INT32_C(  1480278364) },
      {  INT32_C(  1042267835),  INT32_C(    23481854), -INT32_C(   921518253),  INT32_C(     4356604),  INT32_C(     1612041), -INT32_C(  1924410034),  INT32_C(  1332672789), -INT32_C(  1859708714),
         INT32_C(  1674528470), -INT32_C(  1232866717),  INT32_C(    22057180),  INT32_C(     5608200),  INT32_C(    30830122),  INT32_C(  1582181192),  INT32_C(    30136765), -INT32_C(  1433611052) } },
    { { -INT32_C(  2037964316), -INT32_C(  1811519187),  INT32_C(  1128025815), -INT32_C(   596834861), -INT32_C(  1563974629),  INT32_C(  1117078180),  INT32_C(  2099741217), -INT32_C(  1462410557),
        -INT32_C(  1339138941), -INT32_C(  1673186107),  INT32_C(  1457488259), -INT32_C(  1573761657), -INT32_C(  1773864463),  INT32_C(  1574492476),  INT32_C(   534445915), -INT32_C(   439898014) },
      UINT16_C(62732),
      { -INT32_C(   617950570),  INT32_C(  1314696558),  INT32_C(   899408643), -INT32_C(   919696251), -INT32_C(    89953758), -INT32_C(  1560609081), -INT32_C(   464364515), -INT32_C(   673554879),
        -INT32_C(  1615723472), -INT32_C(  1259532367),  INT32_C(  2028570866),  INT32_C(   927012628),  INT32_C(  1228006530),  INT32_C(    15412195), -INT32_C(   907723385), -INT32_C(   861880420) },
      { -INT32_C(  2037964316), -INT32_C(  1811519187),  INT32_C(     7026630),  INT32_C(    26369305), -INT32_C(  1563974629),  INT32_C(  1117078180),  INT32_C(  2099741217), -INT32_C(  1462410557),
         INT32_C(    20931592), -INT32_C(  1673186107),  INT32_C(    15848209), -INT32_C(  1573761657),  INT32_C(     9593801),  INT32_C(      120407),  INT32_C(    26462843),  INT32_C(    26820991) } },
    { {  INT32_C(  1953190851),  INT32_C(  1411930210), -INT32_C(   171175456), -INT32_C(  1439953368), -INT32_C(   705405454),  INT32_C(   282517385), -INT32_C(  1176913123),  INT32_C(  1032157818),
         INT32_C(   800190925),  INT32_C(   713283913),  INT32_C(   304042218),  INT32_C(  1354582878),  INT32_C(   824619432), -INT32_C(  1388118896),  INT32_C(   828775351),  INT32_C(  1651436693) },
      UINT16_C( 8157),
      {  INT32_C(   368584337),  INT32_C(  1868948048), -INT32_C(  1313160204),  INT32_C(   962749203), -INT32_C(   701107308),  INT32_C(   133360800), -INT32_C(  1946974435),  INT32_C(  2074792170),
         INT32_C(  1200661238),  INT32_C(  2042033540), -INT32_C(   869633608),  INT32_C(  1745194452),  INT32_C(   541014912),  INT32_C(  1160196391), -INT32_C(  1563419976), -INT32_C(   518095894) },
      {  INT32_C(     2879565),  INT32_C(  1411930210),  INT32_C(    23295367),  INT32_C(     7521478),  INT32_C(    28077031),  INT32_C(   282517385),  INT32_C(    18343694),  INT32_C(    16209313),
         INT32_C(     9380165),  INT32_C(    15953387),  INT32_C(    26760419),  INT32_C(    13634331),  INT32_C(     4226679), -INT32_C(  1388118896),  INT32_C(   828775351),  INT32_C(  1651436693) } },
    { { -INT32_C(  1574392291),  INT32_C(  1545330340),  INT32_C(   589841743),  INT32_C(  1384918738), -INT32_C(  1871459479), -INT32_C(  1261069572), -INT32_C(  1621645643),  INT32_C(  1048605985),
        -INT32_C(   941578205), -INT32_C(   702219385),  INT32_C(   335170625), -INT32_C(   479820166),  INT32_C(  1299503441),  INT32_C(   671172979),  INT32_C(   281565423), -INT32_C(   246462259) },
      UINT16_C(12273),
      { -INT32_C(   601130824),  INT32_C(  1210674254), -INT32_C(   439442561), -INT32_C(    71426169),  INT32_C(  1849963116),  INT32_C(   583414874), -INT32_C(  1821666236),  INT32_C(  1036213381),
         INT32_C(   572190420), -INT32_C(   647281830),  INT32_C(  1841248742), -INT32_C(   983007911),  INT32_C(   171158959),  INT32_C(   623704801),  INT32_C(   330930062), -INT32_C(   951026445) },
      {  INT32_C(    28858097),  INT32_C(  1545330340),  INT32_C(   589841743),  INT32_C(  1384918738),  INT32_C(    14452836),  INT32_C(     4557928),  INT32_C(    19322664),  INT32_C(     8095417),
         INT32_C(     4470237),  INT32_C(    28497542),  INT32_C(    14384755),  INT32_C(    25874682),  INT32_C(  1299503441),  INT32_C(     4872693),  INT32_C(   281565423), -INT32_C(   246462259) } },
    { { -INT32_C(   991270294), -INT32_C(  1801628243), -INT32_C(   419341170), -INT32_C(  1985123622), -INT32_C(   124526569),  INT32_C(  1746780378),  INT32_C(  1266406999), -INT32_C(  1139618734),
        -INT32_C(   461308874), -INT32_C(   528998831),  INT32_C(  1422358906), -INT32_C(    86084381),  INT32_C(   804417877), -INT32_C(  1986523087),  INT32_C(   970200038),  INT32_C(   385214175) },
      UINT16_C(30435),
      {  INT32_C(  1922315514), -INT32_C(   588575212),  INT32_C(  1095815011), -INT32_C(  1129142839),  INT32_C(  1842144469),  INT32_C(  1098953325), -INT32_C(   517512981),  INT32_C(  1884752502),
         INT32_C(  1407380287),  INT32_C(  1546636793),  INT32_C(  1721598108), -INT32_C(    98414555), -INT32_C(  1587024332), -INT32_C(  1931286368), -INT32_C(  1100150456),  INT32_C(  1395573780) },
      {  INT32_C(    15018089),  INT32_C(    28956188), -INT32_C(   419341170), -INT32_C(  1985123622), -INT32_C(   124526569),  INT32_C(     8585572),  INT32_C(    29511361),  INT32_C(    14724628),
        -INT32_C(   461308874),  INT32_C(    12083099),  INT32_C(    13449985), -INT32_C(    86084381),  INT32_C(    21155804),  INT32_C(    18466257),  INT32_C(    24959506),  INT32_C(   385214175) } },
    { { -INT32_C(  1465511761),  INT32_C(  2047203037),  INT32_C(  2078319190),  INT32_C(   645268210), -INT32_C(  1865949712),  INT32_C(   219982277), -INT32_C(   942962253), -INT32_C(    65341107),
        -INT32_C(   408567799), -INT32_C(   329143658),  INT32_C(  1063797068),  INT32_C(   862314051), -INT32_C(  2117915205), -INT32_C(  1987125034), -INT32_C(  1219470743),  INT32_C(  1572039251) },
      UINT16_C(22571),
      { -INT32_C(  1526546108),  INT32_C(   384192430), -INT32_C(   202102386),  INT32_C(   522235740), -INT32_C(  1073744080), -INT32_C(   786863744), -INT32_C(   751080416),  INT32_C(   221013705),
        -INT32_C(   692965848),  INT32_C(   200054909),  INT32_C(   503308481), -INT32_C(  1069736049), -INT32_C(  1753269226), -INT32_C(   983000923), -INT32_C(   828792060),  INT32_C(   853263626) },
      {  INT32_C(    21628290),  INT32_C(     3001503),  INT32_C(  2078319190),  INT32_C(     4079966), -INT32_C(  1865949712),  INT32_C(    27407059), -INT32_C(   942962253), -INT32_C(    65341107),
        -INT32_C(   408567799), -INT32_C(   329143658),  INT32_C(  1063797068),  INT32_C(    25197119),  INT32_C(    19857016), -INT32_C(  1987125034),  INT32_C(    27079494),  INT32_C(  1572039251) } },
    { {  INT32_C(  1896386291), -INT32_C(   394464218),  INT32_C(  1661303764), -INT32_C(  1323089253),  INT32_C(   608739967),  INT32_C(  1072345146),  INT32_C(  1577943892),  INT32_C(   999352392),
        -INT32_C(  1649633162),  INT32_C(  1619339660),  INT32_C(  1069779620),  INT32_C(  1290921933), -INT32_C(   999278199),  INT32_C(  1040407274),  INT32_C(   630984925),  INT32_C(  1868639480) },
      UINT16_C( 3524),
      { -INT32_C(  1858711540),  INT32_C(  1931205552),  INT32_C(   190507034), -INT32_C(  1522146252), -INT32_C(  1409339480),  INT32_C(   163306861),  INT32_C(  1664463618),  INT32_C(   779221282),
        -INT32_C(   104880311), -INT32_C(  1653810302), -INT32_C(   123156541),  INT32_C(  1402858923), -INT32_C(  1979802596),  INT32_C(  2089990521), -INT32_C(  1881159828),  INT32_C(   163401920) },
      {  INT32_C(  1896386291), -INT32_C(   394464218),  INT32_C(     1488336), -INT32_C(  1323089253),  INT32_C(   608739967),  INT32_C(  1072345146),  INT32_C(    13003622),  INT32_C(     6087666),
         INT32_C(    32735054),  INT32_C(  1619339660),  INT32_C(    32592271),  INT32_C(    10959835), -INT32_C(   999278199),  INT32_C(  1040407274),  INT32_C(   630984925),  INT32_C(  1868639480) } },
    { {  INT32_C(  2046983672),  INT32_C(   454520664), -INT32_C(   518799306), -INT32_C(   902516563), -INT32_C(   967626163),  INT32_C(  1464002283),  INT32_C(  1860575917),  INT32_C(  1786225778),
         INT32_C(  2045082145),  INT32_C(   529857769),  INT32_C(  1778428092), -INT32_C(  1523305384),  INT32_C(  1366067046),  INT32_C(   464039533),  INT32_C(  1133088720),  INT32_C(  1420623923) },
      UINT16_C(37498),
      {  INT32_C(  1636787149), -INT32_C(  2113320062), -INT32_C(   373923147),  INT32_C(  1936792583),  INT32_C(   371383917), -INT32_C(  2103053575), -INT32_C(   477898699), -INT32_C(   109707988),
        -INT32_C(   480639903),  INT32_C(    90596432), -INT32_C(   839967546), -INT32_C(  1505664967),  INT32_C(   951870270), -INT32_C(  1950719659),  INT32_C(  1701723449), -INT32_C(  1671503045) },
      {  INT32_C(  2046983672),  INT32_C(    17044119), -INT32_C(   518799306),  INT32_C(    15131192),  INT32_C(     2901436),  INT32_C(    17124325),  INT32_C(    29820848),  INT32_C(  1786225778),
         INT32_C(  2045082145),  INT32_C(      707784),  INT32_C(  1778428092), -INT32_C(  1523305384),  INT32_C(     7436486),  INT32_C(   464039533),  INT32_C(  1133088720),  INT32_C(    20495814) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i src = simde_mm512_loadu_epi32(test_vec[i].src);
    simde__m512i a = simde_mm512_loadu_epi32(test_vec[i].a);
    simde__m512i r = simde_mm512_mask_srli_epi32(src, test_vec[i].k, a, 7);
    simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[i].r));
  }
  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512i src = simde_test_x86_random_i32x16();
    simde__mmask16 k = simde_test_x86_random_mmask16();
    simde__m512i a = simde_test_x86_random_i32x16();
    simde__m512i r = simde_mm512_mask_srli_epi32(src, k, a, 7);

    simde_test_x86_write_i32x16(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask16(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_maskz_srli_epi32(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  const struct {
    const simde__mmask16 k;
    const int32_t a[16];
    const int32_t r[16];
  } test_vec[] = {
    { UINT16_C(30856),
      { -INT32_C(  2052482927), -INT32_C(  1993746803),  INT32_C(   352150382), -INT32_C(   706204932), -INT32_C(   555590071), -INT32_C(  1503522590),  INT32_C(  1550400091), -INT32_C(  1680477942),
         INT32_C(   388005513), -INT32_C(  1012905644), -INT32_C(  1445487187),  INT32_C(   276742087),  INT32_C(    15622429), -INT32_C(   861515663), -INT32_C(  1809248374), -INT32_C(  1976500736) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(    28037205),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(    20425698),
         INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(     2162047),  INT32_C(      122050),  INT32_C(    26823840),  INT32_C(    19419679),  INT32_C(           0) } },
    { UINT16_C(20604),
      {  INT32_C(  1100664993),  INT32_C(  1792952211),  INT32_C(  1865065968), -INT32_C(  1546631243), -INT32_C(   285982393),  INT32_C(   922582541),  INT32_C(  1127546387),  INT32_C(   697544840),
         INT32_C(   342502785),  INT32_C(  1702840436), -INT32_C(  1563121171),  INT32_C(   944088304), -INT32_C(   232375835), -INT32_C(   886496328), -INT32_C(  1458676447), -INT32_C(  1882021618) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(    14570827),  INT32_C(    21471375),  INT32_C(    31320194),  INT32_C(     7207676),  INT32_C(     8808956),  INT32_C(           0),
         INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(    31738995),  INT32_C(           0),  INT32_C(    22158522),  INT32_C(           0) } },
    { UINT16_C(15567),
      {  INT32_C(   579093411),  INT32_C(  2093707688),  INT32_C(  1495317523),  INT32_C(   445777396),  INT32_C(   557665016),  INT32_C(   595484437), -INT32_C(   607810552), -INT32_C(  1088973797),
        -INT32_C(  2132697897),  INT32_C(   570207501),  INT32_C(  1568284009),  INT32_C(   444009506),  INT32_C(  1815852119),  INT32_C(   479246867),  INT32_C(  1660376390), -INT32_C(  1071575319) },
      {  INT32_C(     4524167),  INT32_C(    16357091),  INT32_C(    11682168),  INT32_C(     3482635),  INT32_C(           0),  INT32_C(           0),  INT32_C(    28805912),  INT32_C(    25046824),
         INT32_C(           0),  INT32_C(           0),  INT32_C(    12252218),  INT32_C(     3468824),  INT32_C(    14186344),  INT32_C(     3744116),  INT32_C(           0),  INT32_C(           0) } },
    { UINT16_C(  682),
      {  INT32_C(  1034926144),  INT32_C(  1398413529), -INT32_C(   329286539), -INT32_C(   761153897), -INT32_C(  1282624477), -INT32_C(   955722800),  INT32_C(  1456927029), -INT32_C(   229080911),
         INT32_C(   288294968), -INT32_C(  1771796192), -INT32_C(  1669151739), -INT32_C(  1653660806), -INT32_C(  1471087656),  INT32_C(    57694414), -INT32_C(    78035383), -INT32_C(     1199418) },
      {  INT32_C(           0),  INT32_C(    10925105),  INT32_C(           0),  INT32_C(    27607917),  INT32_C(           0),  INT32_C(    26087847),  INT32_C(           0),  INT32_C(    31764737),
         INT32_C(           0),  INT32_C(    19712274),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { UINT16_C( 7354),
      {  INT32_C(  1973803536), -INT32_C(   214324624), -INT32_C(  1240026297), -INT32_C(  1582174639),  INT32_C(   133857431), -INT32_C(   582139005),  INT32_C(   730796862),  INT32_C(   591874322),
        -INT32_C(  1801917405), -INT32_C(   561524329), -INT32_C(   711680636),  INT32_C(   595019148),  INT32_C(  1227518405), -INT32_C(   215582796), -INT32_C(  1658931830),  INT32_C(   566257406) },
      {  INT32_C(           0),  INT32_C(    31880020),  INT32_C(           0),  INT32_C(    21193692),  INT32_C(     1045761),  INT32_C(    29006471),  INT32_C(           0),  INT32_C(     4624018),
         INT32_C(           0),  INT32_C(           0),  INT32_C(    27994427),  INT32_C(     4648587),  INT32_C(     9589987),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { UINT16_C(22610),
      {  INT32_C(  1009379765),  INT32_C(  1541057991), -INT32_C(    90085757), -INT32_C(  1284807031), -INT32_C(   718659665),  INT32_C(   831173650),  INT32_C(   295143505),  INT32_C(  1600776618),
        -INT32_C(  1701014829), -INT32_C(  1007258048),  INT32_C(  1706923996), -INT32_C(  1390925571),  INT32_C(  1518486087),  INT32_C(  1217072630),  INT32_C(  1062806165), -INT32_C(   559955189) },
      {  INT32_C(           0),  INT32_C(    12039515),  INT32_C(           0),  INT32_C(           0),  INT32_C(    27939903),  INT32_C(           0),  INT32_C(     2305808),  INT32_C(           0),
         INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(    22687825),  INT32_C(    11863172),  INT32_C(           0),  INT32_C(     8303173),  INT32_C(           0) } },
    { UINT16_C(15189),
      {  INT32_C(  1873909113),  INT32_C(   352750936),  INT32_C(   171770866),  INT32_C(   860652976),  INT32_C(  1782596319), -INT32_C(   460532342), -INT32_C(  1264085227), -INT32_C(   269484938),
        -INT32_C(   362897262),  INT32_C(   520119341),  INT32_C(   405355879), -INT32_C(  1588890174),  INT32_C(  1108052919),  INT32_C(  1965463392), -INT32_C(  1523987153),  INT32_C(  1536432329) },
      {  INT32_C(    14639914),  INT32_C(           0),  INT32_C(     1341959),  INT32_C(           0),  INT32_C(    13926533),  INT32_C(           0),  INT32_C(    23678766),  INT32_C(           0),
         INT32_C(    30719297),  INT32_C(     4063432),  INT32_C(           0),  INT32_C(    21141227),  INT32_C(     8656663),  INT32_C(    15355182),  INT32_C(           0),  INT32_C(           0) } },
    { UINT16_C(62136),
      {  INT32_C(  1180099910),  INT32_C(   763608324),  INT32_C(   547505877), -INT32_C(   206873881), -INT32_C(  1031140196), -INT32_C(  1416644223), -INT32_C(   222078882), -INT32_C(    85689164),
         INT32_C(  1715485281), -INT32_C(   845954056), -INT32_C(   236046839),  INT32_C(   753179024),  INT32_C(   669937317), -INT32_C(  2033025752), -INT32_C(  1988520491),  INT32_C(  1937988881) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(    31938229),  INT32_C(    25498649),  INT32_C(    22486899),  INT32_C(           0),  INT32_C(    32884985),
         INT32_C(           0),  INT32_C(    26945415),  INT32_C(           0),  INT32_C(           0),  INT32_C(     5233885),  INT32_C(    17671418),  INT32_C(    18019115),  INT32_C(    15140538) } },  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_epi32(test_vec[i].a);
    simde__m512i r = simde_mm512_maskz_srli_epi32(test_vec[i].k, a, 7);
    simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[i].r));
  }
  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask16 k = simde_test_x86_random_mmask16();
    simde__m512i a = simde_test_x86_random_i32x16();
    simde__m512i r = simde_mm512_maskz_srli_epi32(k, a, 7);

    simde_test_x86_write_mmask16(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_mask_srli_epi64(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  const struct {
    const int64_t src[2];
    const simde__mmask8 k;
    const int64_t a[2];
    const int64_t r[2];
  } test_vec[] = {
    { {  INT64_C( 8463041320645032681), -INT64_C( 3454890445466999187) },
      UINT8_C(103),
      { -INT64_C( 6587507019157627639), -INT64_C( 7787895182240590981) },
      {  INT64_C(   92650289488686906),  INT64_C(   83272256964601254) } },
    { { -INT64_C( 5150352909240574123),  INT64_C( 8177686348336552530) },
      UINT8_C(151),
      { -INT64_C( 9211972653863462604), -INT64_C(  775274346454636015) },
      {  INT64_C(   72146651717547570),  INT64_C(  138058357244179028) } },
    { {  INT64_C( 3896739426206176892), -INT64_C( 2757873520374568664) },
      UINT8_C( 41),
      { -INT64_C( 2799453713161877867), -INT64_C( 6730378627551130000) },
      {  INT64_C(  122244455941778701), -INT64_C( 2757873520374568664) } },
    { { -INT64_C( 7614544163996018389), -INT64_C( 4211968258225769133) },
      UINT8_C(155),
      {  INT64_C( 1092442870629718626),  INT64_C( 3973016951056975122) },
      {  INT64_C(    8534709926794676),  INT64_C(   31039194930132618) } },
    { {  INT64_C( 1549865677142379643), -INT64_C( 3159827705298098827) },
      UINT8_C(227),
      { -INT64_C(  241519035208659600),  INT64_C(  776327490487098190) },
      {  INT64_C(  142228320613288218),  INT64_C(    6065058519430454) } },
    { {  INT64_C( 6729713169824609717), -INT64_C( 8795350761449984253) },
      UINT8_C( 48),
      {  INT64_C( 6347230753602345172),  INT64_C( 1982745087005057214) },
      {  INT64_C( 6729713169824609717), -INT64_C( 8795350761449984253) } },
    { { -INT64_C( 4139949524425411639),  INT64_C( 6598724013640095680) },
      UINT8_C(120),
      { -INT64_C( 7557728231186161029), -INT64_C( 2049743177023361884) },
      { -INT64_C( 4139949524425411639),  INT64_C( 6598724013640095680) } },
    { {  INT64_C( 4043530566215800172), -INT64_C( 8127560176623452068) },
      UINT8_C( 61),
      { -INT64_C(  604313529428349333),  INT64_C(  292534889606504906) },
      {  INT64_C(  139393988627196892), -INT64_C( 8127560176623452068) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i src = simde_mm_loadu_epi64(test_vec[i].src);
    simde__m128i a = simde_mm_loadu_epi64(test_vec[i].a);
    simde__m128i r = simde_mm_mask_srli_epi64(src, test_vec[i].k, a, 7);
    simde_test_x86_assert_equal_i64x2(r, simde_mm_loadu_epi64(test_vec[i].r));
  }
  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i src = simde_test_x86_random_i64x2();
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128i a = simde_test_x86_random_i64x2();
    simde__m128i r = simde_mm_mask_srli_epi64(src, k, a, 7);

    simde_test_x86_write_i64x2(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x2(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_maskz_srli_epi64(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  const struct {
    const simde__mmask8 k;
    const int64_t a[2];
    const int64_t r[2];
  } test_vec[] = {
    { UINT8_C(  4),
      { -INT64_C( 7202413742204279699), -INT64_C( 7187757448529764449) },
      {  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C(105),
      {  INT64_C(  375558669862348600), -INT64_C( 3648105733522774557) },
      {  INT64_C(    2934052108299598),  INT64_C(                   0) } },
    { UINT8_C(217),
      { -INT64_C(  210444021762643222),  INT64_C(  407113277469999662) },
      {  INT64_C(  142471094155835221),  INT64_C(                   0) } },
    { UINT8_C(209),
      { -INT64_C(  587732220969376900),  INT64_C( 8660461452282953958) },
      {  INT64_C(  139523530099532614),  INT64_C(                   0) } },
    { UINT8_C(222),
      { -INT64_C( 5982073626215006683),  INT64_C(  141819813588064725) },
      {  INT64_C(                   0),  INT64_C(    1107967293656755) } },
    { UINT8_C(233),
      { -INT64_C( 1548459128209430102), -INT64_C( 8764026005128065014) },
      {  INT64_C(  132017851136719699),  INT64_C(                   0) } },
    { UINT8_C( 37),
      { -INT64_C(  726097766902906472), -INT64_C(  829023745068938532) },
      {  INT64_C(  138442549271926915),  INT64_C(                   0) } },
    { UINT8_C(148),
      { -INT64_C( 8299744342791645953),  INT64_C( 6959079709417773468) },
      {  INT64_C(                   0),  INT64_C(                   0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi64(test_vec[i].a);
    simde__m128i r = simde_mm_maskz_srli_epi64(test_vec[i].k, a, 7);
    simde_test_x86_assert_equal_i64x2(r, simde_mm_loadu_epi64(test_vec[i].r));
  }
  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128i a = simde_test_x86_random_i64x2();
    simde__m128i r = simde_mm_maskz_srli_epi64(k, a, 7);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x2(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_mask_srli_epi64(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  const struct {
    const int64_t src[4];
    const simde__mmask8 k;
    const int64_t a[4];
    const int64_t r[4];
  } test_vec[] = {
    { {  INT64_C( 6658364321016194602), -INT64_C( 5090022256614622448), -INT64_C( 5532095896424369105),  INT64_C( 8873571559779840933) },
      UINT8_C(105),
      { -INT64_C( 6212759190914791821), -INT64_C( 6968725681594986881), -INT64_C( 1871129975752034218),  INT64_C( 7405241540797844760) },
      {  INT64_C(   95578006896834060), -INT64_C( 5090022256614622448), -INT64_C( 5532095896424369105),  INT64_C(   57853449537483162) } },
    { { -INT64_C( 7506969415253213254), -INT64_C( 6342198228138445710),  INT64_C( 3678896753941787125), -INT64_C( 5460804785952373026) },
      UINT8_C(146),
      { -INT64_C( 2114087437366338477), -INT64_C( 5556077437937121806),  INT64_C( 7048979057052814563),  INT64_C( 3347317860113032335) },
      { -INT64_C( 7506969415253213254),  INT64_C(  100708333091972107),  INT64_C( 3678896753941787125), -INT64_C( 5460804785952373026) } },
    { {  INT64_C( 5798963269639413227),  INT64_C( 7622099953136938260),  INT64_C( 2714317721983423791),  INT64_C(   62622777907545813) },
      UINT8_C(153),
      { -INT64_C( 4582897422480992188), -INT64_C( 2820748411928151161), -INT64_C( 3092684525764991986), -INT64_C( 1823981342171675493) },
      {  INT64_C(  108311301962723120),  INT64_C( 7622099953136938260),  INT64_C( 2714317721983423791),  INT64_C(  129865333840139657) } },
    { {  INT64_C( 8454839722512590466),  INT64_C( 6500657218547850267), -INT64_C( 3260134199535229923),  INT64_C( 1799918767139564401) },
      UINT8_C( 63),
      { -INT64_C( 6922698914903773901),  INT64_C( 2727005997878692801),  INT64_C( 3673863650937783774),  INT64_C( 4391254869416546072) },
      {  INT64_C(   90031602803170138),  INT64_C(   21304734358427287),  INT64_C(   28702059772951435),  INT64_C(   34306678667316766) } },
    { { -INT64_C( 9209864813263512179),  INT64_C( 4462808157377993288), -INT64_C( 7741190250306188071), -INT64_C( 4244302655473231405) },
      UINT8_C( 82),
      { -INT64_C( 7030803446511872728),  INT64_C( 8194926406333707981),  INT64_C(  331720097341970690), -INT64_C( 5094412781772572730) },
      { -INT64_C( 9209864813263512179),  INT64_C(   64022862549482093), -INT64_C( 7741190250306188071), -INT64_C( 4244302655473231405) } },
    { { -INT64_C( 4865492953845572009), -INT64_C( 5397467728575629183),  INT64_C( 5485408011884889457), -INT64_C( 5271863181851534196) },
      UINT8_C(242),
      { -INT64_C( 8898939085014265164),  INT64_C( 4973359650615797564), -INT64_C( 7131141869696966553), -INT64_C( 5699391103414098336) },
      { -INT64_C( 4865492953845572009),  INT64_C(   38854372270435918),  INT64_C( 5485408011884889457), -INT64_C( 5271863181851534196) } },
    { { -INT64_C( 6641630330171176637),  INT64_C( 6907743338036136791),  INT64_C( 2394197296647285084),  INT64_C( 3078770984704423180) },
      UINT8_C(198),
      {  INT64_C( 6552967593314843240),  INT64_C(  981697188462692104), -INT64_C( 6161222852968235892), -INT64_C( 6284285925701614074) },
      { -INT64_C( 6641630330171176637),  INT64_C(    7669509284864782),  INT64_C(   95980634537041529),  INT64_C( 3078770984704423180) } },
    { { -INT64_C( 3396504906213820619),  INT64_C( 7794239875948163000), -INT64_C( 1148597222466717201), -INT64_C( 8013384387826310942) },
      UINT8_C(180),
      {  INT64_C( 2374326027523199754),  INT64_C( 3603279069749120863),  INT64_C( 1551503771049944649),  INT64_C( 9110782547548220159) },
      { -INT64_C( 3396504906213820619),  INT64_C( 7794239875948163000),  INT64_C(   12121123211327692), -INT64_C( 8013384387826310942) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i src = simde_mm256_loadu_epi64(test_vec[i].src);
    simde__m256i a = simde_mm256_loadu_epi64(test_vec[i].a);
    simde__m256i r = simde_mm256_mask_srli_epi64(src, test_vec[i].k, a, 7);
    simde_test_x86_assert_equal_i64x4(r, simde_mm256_loadu_epi64(test_vec[i].r));
  }
  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256i src = simde_test_x86_random_i64x4();
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256i a = simde_test_x86_random_i64x4();
    simde__m256i r = simde_mm256_mask_srli_epi64(src, k, a, 7);

    simde_test_x86_write_i64x4(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_maskz_srli_epi64(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  const struct {
    const simde__mmask8 k;
    const int64_t a[4];
    const int64_t r[4];
  } test_vec[] = {
    { UINT8_C( 19),
      { -INT64_C( 4857091876026271252),  INT64_C( 1358161484243642916), -INT64_C( 5742199448939299260),  INT64_C( 7574952851435424780) },
      {  INT64_C(  106169157794400627),  INT64_C(   10610636595653460),  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C( 92),
      { -INT64_C( 1986996485764832988),  INT64_C( 5991655393775910074), -INT64_C( 3255809206781315543),  INT64_C( 2318993154630409519) },
      {  INT64_C(                   0),  INT64_C(                   0),  INT64_C(  118679178647876844),  INT64_C(   18117134020550074) } },
    { UINT8_C( 89),
      { -INT64_C( 3335066337606997705),  INT64_C( 3950214053550790918),  INT64_C( 4939831309665867348), -INT64_C( 4238624408211464419) },
      {  INT64_C(  118059982313301202),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(  111000934886703806) } },
    { UINT8_C(202),
      {  INT64_C( 1314331431683539648),  INT64_C( 5577155870444414232), -INT64_C( 5624440325457722363), -INT64_C( 5519717749439347398) },
      {  INT64_C(                   0),  INT64_C(   43571530237846986),  INT64_C(                   0),  INT64_C(  100992393158360970) } },
    { UINT8_C(199),
      {  INT64_C(  905313850281224454), -INT64_C( 3732622038829653467), -INT64_C( 4685484170525407291),  INT64_C(  205869241817208079) },
      {  INT64_C(    7072764455322066),  INT64_C(  114954078397499204),  INT64_C(  107509842993626127),  INT64_C(                   0) } },
    { UINT8_C( 77),
      { -INT64_C( 6011320295318324709), -INT64_C(  281050615357587133),  INT64_C( 7457876120545056927), -INT64_C( 8496773591203605661) },
      {  INT64_C(   97151748268681460),  INT64_C(                   0),  INT64_C(   58264657191758257),  INT64_C(   77734144394577702) } },
    { UINT8_C(224),
      {  INT64_C( 5497935868535175305), -INT64_C( 8039983370853048501), -INT64_C( 1276830577120322767), -INT64_C( 5948719488536080596) },
      {  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C(224),
      { -INT64_C( 6827817662233725348),  INT64_C( 5937972431445167097), -INT64_C( 6754946910052857012), -INT64_C( 6863640567440026632) },
      {  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i a = simde_mm256_loadu_epi64(test_vec[i].a);
    simde__m256i r = simde_mm256_maskz_srli_epi64(test_vec[i].k, a, 7);
    simde_test_x86_assert_equal_i64x4(r, simde_mm256_loadu_epi64(test_vec[i].r));
  }
  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256i a = simde_test_x86_random_i64x4();
    simde__m256i r = simde_mm256_maskz_srli_epi64(k, a, 7);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
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

static int
test_simde_mm512_mask_srli_epi64(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  const struct {
    const int64_t src[8];
    const simde__mmask8 k;
    const int64_t a[8];
    const int64_t r[8];
  } test_vec[] = {
    { { -INT64_C( 2536420616985957591),  INT64_C( 6748214206993147613), -INT64_C( 1802929765029293115),  INT64_C( 6659844406499524743),
        -INT64_C( 5805329230773944144), -INT64_C( 4546196925996367494), -INT64_C( 7506917765000176643), -INT64_C( 3575347806092420910) },
      UINT8_C(208),
      {  INT64_C( 5959759640985231848), -INT64_C( 8864758442530881452),  INT64_C( 5767189967542740517),  INT64_C( 6282305354733522575),
         INT64_C( 8556918604725211549),  INT64_C( 4699064326444813961), -INT64_C( 8764986777192051884), -INT64_C( 6748902405357254000) },
      { -INT64_C( 2536420616985957591),  INT64_C( 6748214206993147613), -INT64_C( 1802929765029293115),  INT64_C( 6659844406499524743),
         INT64_C(   66850926599415715), -INT64_C( 4546196925996367494),  INT64_C(   75638728879042966),  INT64_C(   91389388034002325) } },
    { { -INT64_C( 4863657580434494745), -INT64_C( 5243416596127484705), -INT64_C( 4112595466694970257), -INT64_C( 3489692775454682134),
         INT64_C( 5978345381817852424),  INT64_C( 8747828905685902669),  INT64_C( 3763264683283327548),  INT64_C( 2763157509834538912) },
      UINT8_C( 88),
      { -INT64_C( 4695250716580945615),  INT64_C( 1670909051519141483), -INT64_C( 2625715285887180254), -INT64_C( 6861763518300416072),
         INT64_C( 1916002021243785600), -INT64_C( 4283980278066683768),  INT64_C( 4221916304962219488),  INT64_C( 3344325895285935961) },
      { -INT64_C( 4863657580434494745), -INT64_C( 5243416596127484705), -INT64_C( 4112595466694970257),  INT64_C(   90507660589133871),
         INT64_C(   14968765790967075),  INT64_C( 8747828905685902669),  INT64_C(   32983721132517339),  INT64_C( 2763157509834538912) } },
    { {  INT64_C( 2146702538119287808), -INT64_C(  692395360176121602), -INT64_C( 5492059096600144117), -INT64_C( 2326700884253445927),
         INT64_C( 6425607912182168697), -INT64_C( 1640050384821436624),  INT64_C( 1333696857669824373),  INT64_C( 6732123757245759151) },
      UINT8_C( 10),
      {  INT64_C( 6306373840174083323), -INT64_C(  609641779490862153), -INT64_C( 2773580908598371948),  INT64_C( 8661295633237086427),
         INT64_C(  897994601737787526),  INT64_C( 6709146049793075996),  INT64_C( 7690655640421682181),  INT64_C( 1709335485237917634) },
      {  INT64_C( 2146702538119287808),  INT64_C(  139352361673583511), -INT64_C( 5492059096600144117),  INT64_C(   67666372134664737),
         INT64_C( 6425607912182168697), -INT64_C( 1640050384821436624),  INT64_C( 1333696857669824373),  INT64_C( 6732123757245759151) } },
    { { -INT64_C( 1026349206212279201), -INT64_C( 7746981297513962921),  INT64_C( 2555000453158252157),  INT64_C( 3409254399520934311),
        -INT64_C( 8545962706272549217),  INT64_C( 3001973147158805383), -INT64_C(  767676483589824812),  INT64_C( 8408921810236455603) },
      UINT8_C(  3),
      { -INT64_C( 3836576164349613930), -INT64_C( 6961825599954954393), -INT64_C( 6182348345178220587), -INT64_C(   31257562720520689),
        -INT64_C( 1372195441378474277), -INT64_C( 2309823196972815662), -INT64_C( 3454943984124699020),  INT64_C( 6607041786044845128) },
      {  INT64_C(  114141936791874513),  INT64_C(   89725925576207790),  INT64_C( 2555000453158252157),  INT64_C( 3409254399520934311),
        -INT64_C( 8545962706272549217),  INT64_C( 3001973147158805383), -INT64_C(  767676483589824812),  INT64_C( 8408921810236455603) } },
    { { -INT64_C( 5249937240204383565), -INT64_C( 1239057817058828573),  INT64_C(  534344778034326745),  INT64_C( 7549838048955516908),
        -INT64_C( 6273579408861148333), -INT64_C( 3617687976632977310),  INT64_C( 7518145484786441616), -INT64_C( 3840274745059438952) },
      UINT8_C(230),
      { -INT64_C( 1622893520259251628),  INT64_C( 4601739983560988648), -INT64_C( 8180185637186754031), -INT64_C( 3496816981015410952),
         INT64_C( 6821654318503437265),  INT64_C( 4835324702927521977), -INT64_C(  955150174057539920),  INT64_C( 7183520212946568038) },
      { -INT64_C( 5249937240204383565),  INT64_C(   35951093621570223),  INT64_C(   80207487785334356),  INT64_C( 7549838048955516908),
        -INT64_C( 6273579408861148333),  INT64_C(   37775974241621265),  INT64_C(  136653077341031341),  INT64_C(   56121251663645062) } },
    { { -INT64_C( 5407747849072568288), -INT64_C( 3112081747830858407), -INT64_C(  401731224273095296),  INT64_C( 1043864167907062150),
        -INT64_C( 3687155674201742812), -INT64_C( 8130079185233746892),  INT64_C( 8839570957640740893),  INT64_C( 4063107864532846439) },
      UINT8_C(177),
      { -INT64_C( 8083133211554326778), -INT64_C( 8751007176637666743),  INT64_C( 8292240636262367286), -INT64_C( 3294172246296795001),
        -INT64_C( 6354225730440696810), -INT64_C( 3222141241687249045),  INT64_C( 4415378898125046503), -INT64_C( 6658260282628649477) },
      {  INT64_C(   80965709860587694), -INT64_C( 3112081747830858407), -INT64_C(  401731224273095296),  INT64_C( 1043864167907062150),
         INT64_C(   94472799556787928),  INT64_C(  118942209625174238),  INT64_C( 8839570957640740893),  INT64_C(   92097529617819547) } },
    { { -INT64_C( 5364712623304275832),  INT64_C( 3717087403865253158), -INT64_C( 6668620862867499647), -INT64_C( 1492658074967980262),
         INT64_C(  795832998746402316), -INT64_C( 4431151426209742334), -INT64_C( 1314085912703301768),  INT64_C( 4396600864179236533) },
      UINT8_C( 12),
      {  INT64_C( 2392252112738292691), -INT64_C( 8600708701400891191), -INT64_C( 5313885234501204961),  INT64_C( 3514819114405681629),
         INT64_C( 9041420129692334264),  INT64_C( 2350120347122719763),  INT64_C( 2328904456469346579),  INT64_C( 1645118286978562120) },
      { -INT64_C( 5364712623304275832),  INT64_C( 3717087403865253158),  INT64_C(  102600459681315208),  INT64_C(   27459524331294387),
         INT64_C(  795832998746402316), -INT64_C( 4431151426209742334), -INT64_C( 1314085912703301768),  INT64_C( 4396600864179236533) } },
    { { -INT64_C( 2626470735753956006), -INT64_C( 7501714378401499454), -INT64_C( 3968934057425596025), -INT64_C( 4382211992754272580),
         INT64_C( 5051172374860438902),  INT64_C( 2283587348082592404),  INT64_C( 2506487826710454912), -INT64_C( 1456796329128020837) },
      UINT8_C(  8),
      {  INT64_C( 5588071327522826650),  INT64_C( 3984001582590436571),  INT64_C( 5070981792754649838), -INT64_C( 4220533470944009222),
        -INT64_C( 6457799258392364591),  INT64_C( 4141546160448882414), -INT64_C( 3432767845191379452), -INT64_C( 7948673293350528833) },
      { -INT64_C( 2626470735753956006), -INT64_C( 7501714378401499454), -INT64_C( 3968934057425596025),  INT64_C(  111142270334105799),
         INT64_C( 5051172374860438902),  INT64_C( 2283587348082592404),  INT64_C( 2506487826710454912), -INT64_C( 1456796329128020837) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i src = simde_mm512_loadu_epi64(test_vec[i].src);
    simde__m512i a = simde_mm512_loadu_epi64(test_vec[i].a);
    simde__m512i r = simde_mm512_mask_srli_epi64(src, test_vec[i].k, a, 7);
    simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[i].r));
  }
  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512i src = simde_test_x86_random_i64x8();
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m512i a = simde_test_x86_random_i64x8();
    simde__m512i r = simde_mm512_mask_srli_epi64(src, k, a, 7);

    simde_test_x86_write_i64x8(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_maskz_srli_epi64(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  const struct {
    const simde__mmask8 k;
    const int64_t a[8];
    const int64_t r[8];
  } test_vec[] = {
    { UINT8_C(156),
      {  INT64_C( 5522833741026076013),  INT64_C( 8591407255597279100), -INT64_C( 4186626174068371252), -INT64_C( 1256198073633877678),
        -INT64_C( 9147573883830404933),  INT64_C( 4542709752370013234), -INT64_C( 4056250724749191358),  INT64_C(  904746687627278878) },
      {  INT64_C(                   0),  INT64_C(                   0),  INT64_C(  111407171090946721),  INT64_C(  134301140625591202),
         INT64_C(   72649767108430833),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(    7068333497088116) } },
    { UINT8_C( 70),
      {  INT64_C( 9201078182295031347), -INT64_C( 6505675828440644733), -INT64_C( 7636450903517976679),  INT64_C( 7363935369565808029),
        -INT64_C( 3882784268410913854), -INT64_C( 2536944676116688681),  INT64_C( 7030339766654854045),  INT64_C( 3244699957748070253) },
      {  INT64_C(                   0),  INT64_C(   93289595666163335),  INT64_C(   84455415392121679),  INT64_C(                   0),
         INT64_C(                   0),  INT64_C(                   0),  INT64_C(   54924529426991047),  INT64_C(                   0) } },
    { UINT8_C(248),
      { -INT64_C(  551961535140869141),  INT64_C( 3088367935433636936), -INT64_C( 2517706364437997863), -INT64_C( 6768779711179280229),
        -INT64_C( 6763990641972981695),  INT64_C( 5505577367845821686),  INT64_C( 4600424429391861139), -INT64_C( 2880219541053955923) },
      {  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(   91234096582267745),
         INT64_C(   91271511185441952),  INT64_C(   43012323186295481),  INT64_C(   35940815854623915),  INT64_C(  121613472911371841) } },
    { UINT8_C(183),
      {  INT64_C( 9194858554871316777), -INT64_C( 7789752642595334252), -INT64_C( 3038110378162135509),  INT64_C( 7776665707700042701),
         INT64_C( 4965123689324477765),  INT64_C( 4778734917722167680), -INT64_C( 3754803629900724135), -INT64_C( 2798165194365251460) },
      {  INT64_C(   71834832459932162),  INT64_C(   83257745555579823),  INT64_C(  120379950746464188),  INT64_C(                   0),
         INT64_C(   38790028822847482),  INT64_C(   37333866544704435),  INT64_C(                   0),  INT64_C(  122254522494877344) } },
    { UINT8_C(232),
      {  INT64_C(  171941808246899257), -INT64_C(  484880840021958542), -INT64_C( 8609543041717939002), -INT64_C( 6515031438811970879),
         INT64_C( 8963263914192612919), -INT64_C( 7101139946938205175), -INT64_C( 1242385277261616638),  INT64_C(  827871597231332971) },
      {  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(   93216504960137349),
         INT64_C(                   0),  INT64_C(   88637532240401144),  INT64_C(  134409053097249492),  INT64_C(    6467746853369788) } },
    { UINT8_C( 94),
      {  INT64_C( 5546435626622610437),  INT64_C( 5836596839929115214), -INT64_C( 2595362027765679514),  INT64_C( 6167040118431404806),
         INT64_C( 3621805475139747367), -INT64_C( 8077999600504445010), -INT64_C( 3224547863730101656), -INT64_C( 3417213242533351443) },
      {  INT64_C(                   0),  INT64_C(   45598412811946212),  INT64_C(  123838922233936500),  INT64_C(   48180000925245350),
         INT64_C(   28295355274529276),  INT64_C(                   0),  INT64_C(  118923407890464452),  INT64_C(                   0) } },
    { UINT8_C(156),
      {  INT64_C( 8269086151470532567), -INT64_C( 7099877279884683551),  INT64_C(  887557798016769354), -INT64_C(  540003000161825210),
        -INT64_C( 7724854565663997619), -INT64_C( 2595449349565290973), -INT64_C( 1719653081869752839), -INT64_C( 6108764157613582561) },
      {  INT64_C(                   0),  INT64_C(                   0),  INT64_C(    6934045297006010),  INT64_C(  139896414637091612),
         INT64_C(   83764761781605890),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(   96390468094499758) } },
    { UINT8_C( 80),
      {  INT64_C( 3833857193615295300), -INT64_C(  985828115453930948),  INT64_C( 7030538522588375009),  INT64_C( 5758530567796609354),
        -INT64_C( 4363823635167646099), -INT64_C( 4996904479730485465),  INT64_C(  270143106512075988),  INT64_C( 6118289522567249295) },
      {  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
         INT64_C(  110022815926108636),  INT64_C(                   0),  INT64_C(    2110493019625593),  INT64_C(                   0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_epi64(test_vec[i].a);
    simde__m512i r = simde_mm512_maskz_srli_epi64(test_vec[i].k, a, 7);
    simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[i].r));
  }
  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m512i a = simde_test_x86_random_i64x8();
    simde__m512i r = simde_mm512_maskz_srli_epi64(k, a, 7);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_srli_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_maskz_srli_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_srli_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_maskz_srli_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_srli_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_srli_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_maskz_srli_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_srli_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_maskz_srli_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_srli_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_maskz_srli_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_srli_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_srli_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_maskz_srli_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_srli_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_maskz_srli_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_srli_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_maskz_srli_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_srli_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_srli_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_maskz_srli_epi64)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/avx512/test-avx512-footer.h>
