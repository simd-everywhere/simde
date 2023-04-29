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
 *   2020      Himanshi Mathur <himanshi18037@iiitd.ac.in>
 *   2020      Hidayat Khan <huk2209@gmail.com>
 */

#define SIMDE_TEST_X86_AVX512_INSN cvt

#include <test/x86/avx512/test-avx512.h>
#include <simde/x86/avx512/set.h>
#include <simde/x86/avx512/cvt.h>

static int
test_simde_mm_cvtepi64_pd (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int64_t a[2];
    const simde_float64 r[2];
  } test_vec[] = {
    { { -INT64_C( 8614850050345457108),  INT64_C( 7285479202649351501) },
      { SIMDE_FLOAT64_C(-8614850050345456640.00), SIMDE_FLOAT64_C(7285479202649351168.00) } },
    { { -INT64_C( 1053323752731789121),  INT64_C( 4215849800157546739) },
      { SIMDE_FLOAT64_C(-1053323752731789184.00), SIMDE_FLOAT64_C(4215849800157546496.00) } },
    { { -INT64_C( 7066862152626902817),  INT64_C( 5673917116813760156) },
      { SIMDE_FLOAT64_C(-7066862152626903040.00), SIMDE_FLOAT64_C(5673917116813760512.00) } },
    { {  INT64_C( 8653485836458438277),  INT64_C( 8460994408982831395) },
      { SIMDE_FLOAT64_C(8653485836458438656.00), SIMDE_FLOAT64_C(8460994408982831104.00) } },
    { { -INT64_C( 8947589338295078682), -INT64_C( 2884106609811028963) },
      { SIMDE_FLOAT64_C(-8947589338295078912.00), SIMDE_FLOAT64_C(-2884106609811028992.00) } },
    { {  INT64_C( 8305785945735427142), -INT64_C( 6629280240916741899) },
      { SIMDE_FLOAT64_C(8305785945735427072.00), SIMDE_FLOAT64_C(-6629280240916742144.00) } },
    { { -INT64_C( 4761802751542109824), -INT64_C( 6603857745514281679) },
      { SIMDE_FLOAT64_C(-4761802751542110208.00), SIMDE_FLOAT64_C(-6603857745514281984.00) } },
    { {  INT64_C( 6924482801512240982),  INT64_C( 5572900857620184564) },
      { SIMDE_FLOAT64_C(6924482801512241152.00), SIMDE_FLOAT64_C(5572900857620184064.00) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi64(test_vec[i].a);
    simde__m128d r = simde_mm_cvtepi64_pd(a);
    simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i64x2();
    simde__m128d r = simde_mm_cvtepi64_pd(a);

    simde_test_x86_write_i64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_mask_cvtepi64_pd (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float64 src[4];
    const simde__mmask8 k;
    const int64_t a[4];
    const simde_float64 r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(  -473.83), SIMDE_FLOAT64_C(  -406.96) },
      UINT8_C(196),
      { -INT64_C( 1992989217109780021), -INT64_C( 6433624543855457372) },
      { SIMDE_FLOAT64_C(  -473.83), SIMDE_FLOAT64_C(  -406.96) } },
    { { SIMDE_FLOAT64_C(  -513.89), SIMDE_FLOAT64_C(  -815.78) },
      UINT8_C( 96),
      {  INT64_C( 2086762660172277667), -INT64_C( 9170721129076888069) },
      { SIMDE_FLOAT64_C(  -513.89), SIMDE_FLOAT64_C(  -815.78) } },
    { { SIMDE_FLOAT64_C(  -542.00), SIMDE_FLOAT64_C(  -263.18) },
      UINT8_C(215),
      { -INT64_C(  126888838459893298), -INT64_C(  984278822482543143) },
      { SIMDE_FLOAT64_C(-126888838459893296.00), SIMDE_FLOAT64_C(-984278822482543104.00) } },
    { { SIMDE_FLOAT64_C(   864.63), SIMDE_FLOAT64_C(   848.40) },
      UINT8_C(231),
      {  INT64_C( 8652977002587160277), -INT64_C( 2340033633719550196) },
      { SIMDE_FLOAT64_C(8652977002587160576.00), SIMDE_FLOAT64_C(-2340033633719549952.00) } },
    { { SIMDE_FLOAT64_C(   533.58), SIMDE_FLOAT64_C(   829.96) },
      UINT8_C( 28),
      {  INT64_C( 2588366695741100747), -INT64_C( 9049943346622585684) },
      { SIMDE_FLOAT64_C(   533.58), SIMDE_FLOAT64_C(   829.96) } },
    { { SIMDE_FLOAT64_C(   318.23), SIMDE_FLOAT64_C(    13.31) },
      UINT8_C(151),
      {  INT64_C( 7677904969774072153), -INT64_C( 1262779044074398908) },
      { SIMDE_FLOAT64_C(7677904969774071808.00), SIMDE_FLOAT64_C(-1262779044074398976.00) } },
    { { SIMDE_FLOAT64_C(   -96.33), SIMDE_FLOAT64_C(  -858.32) },
      UINT8_C(218),
      { -INT64_C( 2670924357076853084),  INT64_C( 3362164892836482938) },
      { SIMDE_FLOAT64_C(   -96.33), SIMDE_FLOAT64_C(3362164892836483072.00) } },
    { { SIMDE_FLOAT64_C(   450.36), SIMDE_FLOAT64_C(  -203.41) },
      UINT8_C(188),
      {  INT64_C( 3096011100367835422), -INT64_C( 1836277756508407764) },
      { SIMDE_FLOAT64_C(   450.36), SIMDE_FLOAT64_C(  -203.41) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128d src = simde_mm_loadu_pd(test_vec[i].src);
    simde__m128i a = simde_mm_loadu_epi64(test_vec[i].a);
    simde__m128d r = simde_mm_mask_cvtepi64_pd(src, test_vec[i].k, a);
    simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128d src = simde_test_x86_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128i a = simde_test_x86_random_i64x2();
    simde__m128d r = simde_mm_mask_cvtepi64_pd(src, k, a);

    simde_test_x86_write_f64x2(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x2(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_maskz_cvtepi64_pd (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const int64_t a[4];
    const simde_float64 r[4];
  } test_vec[] = {
    { UINT8_C(113),
      { -INT64_C( 6355182479456762882),  INT64_C( 8509915296800176537) },
      { SIMDE_FLOAT64_C(-6355182479456762880.00), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C( 34),
      { -INT64_C( 6715931139535670978),  INT64_C( 1737937097877344696) },
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(1737937097877344768.00) } },
    { UINT8_C(149),
      {  INT64_C( 7109507003511295203), -INT64_C( 1053896188309501688) },
      { SIMDE_FLOAT64_C(7109507003511294976.00), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C(204),
      { -INT64_C( 4825399424035051413),  INT64_C(  206804629430836700) },
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C( 40),
      {  INT64_C(  414958266262681231), -INT64_C( 2583200638144560549) },
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C(164),
      { -INT64_C( 8934229738644199843), -INT64_C( 5573657829329618632) },
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C(149),
      { -INT64_C( 2061475383289640225), -INT64_C( 7320274690666981146) },
      { SIMDE_FLOAT64_C(-2061475383289640192.00), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C(137),
      { -INT64_C( 4788171370732782129),  INT64_C(  404117779594102806) },
      { SIMDE_FLOAT64_C(-4788171370732782592.00), SIMDE_FLOAT64_C(     0.00) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi64(test_vec[i].a);
    simde__m128d r = simde_mm_maskz_cvtepi64_pd(test_vec[i].k, a);
    simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128i a = simde_test_x86_random_i64x2();
    simde__m128d r = simde_mm_maskz_cvtepi64_pd(k, a);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x2(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_cvtepi16_epi8(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m512i a;
    simde__m256i r;
  } test_vec[8] = {
    { simde_mm512_set_epi16(INT16_C( 14423), INT16_C(  3775), INT16_C( 16156), INT16_C( 17811),
                            INT16_C(-14881), INT16_C(-30283), INT16_C( 27295), INT16_C(-12290),
                            INT16_C( 12394), INT16_C( 32764), INT16_C(  8681), INT16_C( 21255),
                            INT16_C(-21785), INT16_C(-24065), INT16_C(-28005), INT16_C( 15206),
                            INT16_C(  6131), INT16_C(-29323), INT16_C( -9530), INT16_C( -6655),
                            INT16_C( 14785), INT16_C( -9158), INT16_C(  7009), INT16_C(  4834),
                            INT16_C(-15579), INT16_C(  5296), INT16_C( 20054), INT16_C( 12832),
                            INT16_C( 15724), INT16_C(  5918), INT16_C( 25398), INT16_C( 14084)),
      simde_mm256_set_epi8(INT8_C(  87), INT8_C( -65), INT8_C(  28), INT8_C(-109),
                           INT8_C( -33), INT8_C( -75), INT8_C( -97), INT8_C(  -2),
                           INT8_C( 106), INT8_C(  -4), INT8_C( -23), INT8_C(   7),
                           INT8_C( -25), INT8_C(  -1), INT8_C(-101), INT8_C( 102),
                           INT8_C( -13), INT8_C( 117), INT8_C( -58), INT8_C(   1),
                           INT8_C( -63), INT8_C(  58), INT8_C(  97), INT8_C( -30),
                           INT8_C(  37), INT8_C( -80), INT8_C(  86), INT8_C(  32),
                           INT8_C( 108), INT8_C(  30), INT8_C(  54), INT8_C(   4)) },
    { simde_mm512_set_epi16(INT16_C(  8455), INT16_C(  1140), INT16_C(-23383), INT16_C( 22825),
                            INT16_C(-21438), INT16_C(  8713), INT16_C(-25940), INT16_C(-31180),
                            INT16_C(-13214), INT16_C( 10200), INT16_C(-21253), INT16_C(  2612),
                            INT16_C(-27891), INT16_C( 14031), INT16_C( -9014), INT16_C( 10287),
                            INT16_C(-11660), INT16_C( 26858), INT16_C(-19518), INT16_C(  2472),
                            INT16_C( 27637), INT16_C( 14857), INT16_C( 30034), INT16_C(-24153),
                            INT16_C( 31935), INT16_C( -6397), INT16_C( -2502), INT16_C( 31062),
                            INT16_C( 30236), INT16_C(  5156), INT16_C( 18439), INT16_C(-13074)),
      simde_mm256_set_epi8(INT8_C(   7), INT8_C( 116), INT8_C( -87), INT8_C(  41),
                           INT8_C(  66), INT8_C(   9), INT8_C( -84), INT8_C(  52),
                           INT8_C(  98), INT8_C( -40), INT8_C(  -5), INT8_C(  52),
                           INT8_C(  13), INT8_C( -49), INT8_C( -54), INT8_C(  47),
                           INT8_C( 116), INT8_C( -22), INT8_C( -62), INT8_C( -88),
                           INT8_C( -11), INT8_C(   9), INT8_C(  82), INT8_C( -89),
                           INT8_C( -65), INT8_C(   3), INT8_C(  58), INT8_C(  86),
                           INT8_C(  28), INT8_C(  36), INT8_C(   7), INT8_C( -18)) },
    { simde_mm512_set_epi16(INT16_C( 18175), INT16_C( -3760), INT16_C( 10318), INT16_C(-31849),
                            INT16_C(-32429), INT16_C(-26500), INT16_C( 24084), INT16_C(-23946),
                            INT16_C(  2525), INT16_C(  2478), INT16_C(-15141), INT16_C(-27410),
                            INT16_C( 30961), INT16_C(-31554), INT16_C( -9533), INT16_C(-20012),
                            INT16_C(-21820), INT16_C( 11767), INT16_C(-17849), INT16_C( 24518),
                            INT16_C(-22206), INT16_C(-24996), INT16_C(-19566), INT16_C( 17826),
                            INT16_C( 25765), INT16_C( 29123), INT16_C( 28065), INT16_C(  1432),
                            INT16_C(-24949), INT16_C( 30580), INT16_C( 20499), INT16_C(-29164)),
      simde_mm256_set_epi8(INT8_C(  -1), INT8_C(  80), INT8_C(  78), INT8_C(-105),
                           INT8_C(  83), INT8_C( 124), INT8_C(  20), INT8_C( 118),
                           INT8_C( -35), INT8_C( -82), INT8_C( -37), INT8_C( -18),
                           INT8_C( -15), INT8_C( -66), INT8_C( -61), INT8_C( -44),
                           INT8_C( -60), INT8_C(  -9), INT8_C(  71), INT8_C( -58),
                           INT8_C(  66), INT8_C(  92), INT8_C(-110), INT8_C( -94),
                           INT8_C( -91), INT8_C( -61), INT8_C( -95), INT8_C(-104),
                           INT8_C(-117), INT8_C( 116), INT8_C(  19), INT8_C(  20)) },
    { simde_mm512_set_epi16(INT16_C( 10816), INT16_C( 16713), INT16_C( 29707), INT16_C( 15186),
                            INT16_C( 31860), INT16_C(-28520), INT16_C( 18947), INT16_C(-27460),
                            INT16_C( 10883), INT16_C(   310), INT16_C(  8277), INT16_C(-28768),
                            INT16_C( -4553), INT16_C( 23273), INT16_C(-27696), INT16_C(-20678),
                            INT16_C( 13089), INT16_C( -6620), INT16_C( 31575), INT16_C(-20169),
                            INT16_C( 14440), INT16_C( -9264), INT16_C(-26919), INT16_C(-25720),
                            INT16_C(-18371), INT16_C( 25765), INT16_C(-13162), INT16_C(-16808),
                            INT16_C(  5695), INT16_C(-25080), INT16_C( 19142), INT16_C(  3825)),
      simde_mm256_set_epi8(INT8_C(  64), INT8_C(  73), INT8_C(  11), INT8_C(  82),
                           INT8_C( 116), INT8_C(-104), INT8_C(   3), INT8_C( -68),
                           INT8_C(-125), INT8_C(  54), INT8_C(  85), INT8_C( -96),
                           INT8_C(  55), INT8_C( -23), INT8_C( -48), INT8_C(  58),
                           INT8_C(  33), INT8_C(  36), INT8_C(  87), INT8_C(  55),
                           INT8_C( 104), INT8_C( -48), INT8_C( -39), INT8_C(-120),
                           INT8_C(  61), INT8_C( -91), INT8_C(-106), INT8_C(  88),
                           INT8_C(  63), INT8_C(   8), INT8_C( -58), INT8_C( -15)) },
    { simde_mm512_set_epi16(INT16_C(  5079), INT16_C(-24746), INT16_C( 23487), INT16_C(-22087),
                            INT16_C( -8346), INT16_C( 29848), INT16_C( 14241), INT16_C( 18254),
                            INT16_C( -3124), INT16_C(-16186), INT16_C(-13364), INT16_C( 10652),
                            INT16_C( 31028), INT16_C( 21346), INT16_C(  1443), INT16_C(-20222),
                            INT16_C(-17028), INT16_C(-21899), INT16_C( 18933), INT16_C(  6935),
                            INT16_C( 24619), INT16_C(  1737), INT16_C( 12596), INT16_C( 31606),
                            INT16_C(-32691), INT16_C( 11392), INT16_C( 32126), INT16_C(-32712),
                            INT16_C( 20927), INT16_C(-27859), INT16_C( 22640), INT16_C(  8969)),
      simde_mm256_set_epi8(INT8_C( -41), INT8_C(  86), INT8_C( -65), INT8_C( -71),
                           INT8_C( 102), INT8_C(-104), INT8_C( -95), INT8_C(  78),
                           INT8_C( -52), INT8_C( -58), INT8_C( -52), INT8_C(-100),
                           INT8_C(  52), INT8_C(  98), INT8_C( -93), INT8_C(   2),
                           INT8_C( 124), INT8_C( 117), INT8_C( -11), INT8_C(  23),
                           INT8_C(  43), INT8_C( -55), INT8_C(  52), INT8_C( 118),
                           INT8_C(  77), INT8_C(-128), INT8_C( 126), INT8_C(  56),
                           INT8_C( -65), INT8_C(  45), INT8_C( 112), INT8_C(   9)) },
    { simde_mm512_set_epi16(INT16_C(  6901), INT16_C(-23435), INT16_C(-26040), INT16_C(-11295),
                            INT16_C(   623), INT16_C(-23058), INT16_C( 17549), INT16_C(-23291),
                            INT16_C( 17215), INT16_C( -4892), INT16_C(  -849), INT16_C( 21086),
                            INT16_C(-13056), INT16_C( 19549), INT16_C( 16492), INT16_C(-22767),
                            INT16_C(-24079), INT16_C(  6429), INT16_C( 15302), INT16_C( -9175),
                            INT16_C( 17671), INT16_C(-29856), INT16_C(-12718), INT16_C(-22914),
                            INT16_C(-19613), INT16_C( 14088), INT16_C(-10443), INT16_C( 31757),
                            INT16_C( 24994), INT16_C( 24174), INT16_C( -9596), INT16_C(-22481)),
      simde_mm256_set_epi8(INT8_C( -11), INT8_C( 117), INT8_C(  72), INT8_C( -31),
                           INT8_C( 111), INT8_C( -18), INT8_C(-115), INT8_C(   5),
                           INT8_C(  63), INT8_C( -28), INT8_C( -81), INT8_C(  94),
                           INT8_C(   0), INT8_C(  93), INT8_C( 108), INT8_C(  17),
                           INT8_C( -15), INT8_C(  29), INT8_C( -58), INT8_C(  41),
                           INT8_C(   7), INT8_C(  96), INT8_C(  82), INT8_C( 126),
                           INT8_C(  99), INT8_C(   8), INT8_C(  53), INT8_C(  13),
                           INT8_C( -94), INT8_C( 110), INT8_C(-124), INT8_C(  47)) },
    { simde_mm512_set_epi16(INT16_C( 15520), INT16_C( 15679), INT16_C(  8541), INT16_C(-20376),
                            INT16_C(  8861), INT16_C( 12926), INT16_C( 25712), INT16_C( -8433),
                            INT16_C( -7066), INT16_C(-23691), INT16_C(-20251), INT16_C( 18056),
                            INT16_C(  5498), INT16_C(-18751), INT16_C(-26321), INT16_C(  7918),
                            INT16_C(  1647), INT16_C( 21774), INT16_C(  5430), INT16_C(-19512),
                            INT16_C(-14894), INT16_C( 12466), INT16_C( -9612), INT16_C(-23130),
                            INT16_C( 18357), INT16_C( 32349), INT16_C(-25760), INT16_C( -6559),
                            INT16_C(-24198), INT16_C( 13614), INT16_C( 13473), INT16_C(-25578)),
      simde_mm256_set_epi8(INT8_C( -96), INT8_C(  63), INT8_C(  93), INT8_C( 104),
                           INT8_C( -99), INT8_C( 126), INT8_C( 112), INT8_C(  15),
                           INT8_C( 102), INT8_C( 117), INT8_C( -27), INT8_C(-120),
                           INT8_C( 122), INT8_C( -63), INT8_C(  47), INT8_C( -18),
                           INT8_C( 111), INT8_C(  14), INT8_C(  54), INT8_C( -56),
                           INT8_C( -46), INT8_C( -78), INT8_C( 116), INT8_C( -90),
                           INT8_C( -75), INT8_C(  93), INT8_C(  96), INT8_C(  97),
                           INT8_C( 122), INT8_C(  46), INT8_C( -95), INT8_C(  22)) },
    { simde_mm512_set_epi16(INT16_C(-13944), INT16_C( 30422), INT16_C( 10523), INT16_C( 28986),
                            INT16_C(-23789), INT16_C(-20754), INT16_C( 29282), INT16_C(-10845),
                            INT16_C( 10721), INT16_C(  2777), INT16_C(-18838), INT16_C(  8324),
                            INT16_C( 19192), INT16_C(   114), INT16_C( -9073), INT16_C(  2615),
                            INT16_C( 21008), INT16_C( 12652), INT16_C(-14859), INT16_C(  5734),
                            INT16_C( -5598), INT16_C(-10707), INT16_C(  2170), INT16_C( 23903),
                            INT16_C( 29988), INT16_C( 24405), INT16_C(  5383), INT16_C(-29994),
                            INT16_C(  7143), INT16_C( 22270), INT16_C( -1480), INT16_C( 15491)),
      simde_mm256_set_epi8(INT8_C(-120), INT8_C( -42), INT8_C(  27), INT8_C(  58),
                           INT8_C(  19), INT8_C( -18), INT8_C(  98), INT8_C( -93),
                           INT8_C( -31), INT8_C( -39), INT8_C( 106), INT8_C(-124),
                           INT8_C(  -8), INT8_C( 114), INT8_C(-113), INT8_C(  55),
                           INT8_C(  16), INT8_C( 108), INT8_C( -11), INT8_C( 102),
                           INT8_C(  34), INT8_C(  45), INT8_C( 122), INT8_C(  95),
                           INT8_C(  36), INT8_C(  85), INT8_C(   7), INT8_C( -42),
                           INT8_C( -25), INT8_C(  -2), INT8_C(  56), INT8_C(-125)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm512_cvtepi16_epi8(test_vec[i].a);
    simde_assert_m256i_i8(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm512_mask_cvtepi16_epi8(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m256i src;
    simde__mmask32 k;
    simde__m512i a;
    simde__m256i r;
  } test_vec[8] = {
    { simde_mm256_set_epi8(INT8_C(-112), INT8_C(  50), INT8_C( -90), INT8_C( -47),
                           INT8_C(  24), INT8_C( -14), INT8_C( -76), INT8_C(  -4),
                           INT8_C(-104), INT8_C( 115), INT8_C( -75), INT8_C(  98),
                           INT8_C( -58), INT8_C( -14), INT8_C(  98), INT8_C(  29),
                           INT8_C( -34), INT8_C(  91), INT8_C(  -9), INT8_C( -32),
                           INT8_C( 105), INT8_C( -54), INT8_C(  11), INT8_C(  76),
                           INT8_C(  83), INT8_C(   3), INT8_C(  48), INT8_C(   2),
                           INT8_C(  92), INT8_C( -54), INT8_C(  99), INT8_C(  95)),
      UINT32_C(     36055),
      simde_mm512_set_epi16(INT16_C( 29253), INT16_C(-14914), INT16_C(  8284), INT16_C( 18521),
                            INT16_C( 32034), INT16_C( 27278), INT16_C( -3730), INT16_C( -7695),
                            INT16_C(  8989), INT16_C(-29300), INT16_C(-14890), INT16_C( 11419),
                            INT16_C( -1355), INT16_C( 25284), INT16_C(-28026), INT16_C(  1548),
                            INT16_C( 26140), INT16_C( -8634), INT16_C( 26242), INT16_C(  1035),
                            INT16_C(-29578), INT16_C( -2997), INT16_C( 22546), INT16_C(-28782),
                            INT16_C(-11973), INT16_C( 12912), INT16_C(-22923), INT16_C(-12898),
                            INT16_C(  4984), INT16_C(   989), INT16_C(  2511), INT16_C( 26483)),
      simde_mm256_set_epi8(INT8_C(-112), INT8_C(  50), INT8_C( -90), INT8_C( -47),
                           INT8_C(  24), INT8_C( -14), INT8_C( -76), INT8_C(  -4),
                           INT8_C(-104), INT8_C( 115), INT8_C( -75), INT8_C(  98),
                           INT8_C( -58), INT8_C( -14), INT8_C(  98), INT8_C(  29),
                           INT8_C(  28), INT8_C(  91), INT8_C(  -9), INT8_C( -32),
                           INT8_C( 118), INT8_C(  75), INT8_C(  11), INT8_C(  76),
                           INT8_C(  59), INT8_C( 112), INT8_C(  48), INT8_C( -98),
                           INT8_C(  92), INT8_C( -35), INT8_C( -49), INT8_C( 115)) },
    { simde_mm256_set_epi8(INT8_C( -93), INT8_C( -75), INT8_C( 109), INT8_C(  43),
                           INT8_C( -79), INT8_C( -91), INT8_C( -13), INT8_C( 103),
                           INT8_C(  -6), INT8_C( -39), INT8_C(   3), INT8_C(-115),
                           INT8_C(  30), INT8_C( -62), INT8_C(  30), INT8_C( 115),
                           INT8_C( -28), INT8_C( -92), INT8_C( 110), INT8_C( -10),
                           INT8_C(  20), INT8_C( -82), INT8_C(  59), INT8_C(  62),
                           INT8_C(  57), INT8_C(  97), INT8_C(  29), INT8_C(  -4),
                           INT8_C( -48), INT8_C(   1), INT8_C(  47), INT8_C(  43)),
      UINT32_C(     13848),
      simde_mm512_set_epi16(INT16_C( 19920), INT16_C( 28417), INT16_C(-26944), INT16_C( -1327),
                            INT16_C(-18966), INT16_C(-19374), INT16_C(  9639), INT16_C(-25572),
                            INT16_C(-16315), INT16_C( 16363), INT16_C( -4686), INT16_C(-14474),
                            INT16_C( 26743), INT16_C( 20737), INT16_C(-16355), INT16_C( 24251),
                            INT16_C(-20830), INT16_C( 19809), INT16_C(-32085), INT16_C(-29115),
                            INT16_C(-21999), INT16_C( 14843), INT16_C( 13075), INT16_C(-28846),
                            INT16_C(-12894), INT16_C( 31357), INT16_C( 16553), INT16_C(-16546),
                            INT16_C(-16544), INT16_C( 30528), INT16_C( -9494), INT16_C(  8241)),
      simde_mm256_set_epi8(INT8_C( -93), INT8_C( -75), INT8_C( 109), INT8_C(  43),
                           INT8_C( -79), INT8_C( -91), INT8_C( -13), INT8_C( 103),
                           INT8_C(  -6), INT8_C( -39), INT8_C(   3), INT8_C(-115),
                           INT8_C(  30), INT8_C( -62), INT8_C(  30), INT8_C( 115),
                           INT8_C( -28), INT8_C( -92), INT8_C( -85), INT8_C(  69),
                           INT8_C(  20), INT8_C(  -5), INT8_C(  19), INT8_C(  62),
                           INT8_C(  57), INT8_C(  97), INT8_C(  29), INT8_C(  94),
                           INT8_C(  96), INT8_C(   1), INT8_C(  47), INT8_C(  43)) },
    { simde_mm256_set_epi8(INT8_C(  57), INT8_C( 119), INT8_C(   6), INT8_C( -62),
                           INT8_C( -27), INT8_C( -22), INT8_C( -69), INT8_C( -61),
                           INT8_C(   8), INT8_C(-101), INT8_C( -24), INT8_C(  69),
                           INT8_C(-111), INT8_C(  66), INT8_C( -48), INT8_C(-122),
                           INT8_C( -19), INT8_C( -25), INT8_C( -88), INT8_C(  96),
                           INT8_C( -81), INT8_C(  28), INT8_C( -73), INT8_C(-105),
                           INT8_C( 109), INT8_C( -84), INT8_C(  26), INT8_C( 108),
                           INT8_C(  16), INT8_C(  69), INT8_C( -67), INT8_C(-122)),
      UINT32_C(     52950),
      simde_mm512_set_epi16(INT16_C(-28100), INT16_C(  2824), INT16_C(-32113), INT16_C(-30059),
                            INT16_C(-19864), INT16_C(-29923), INT16_C( 19573), INT16_C(-11183),
                            INT16_C(-18980), INT16_C( 26281), INT16_C( -7946), INT16_C( 14491),
                            INT16_C( 28715), INT16_C( 26138), INT16_C( 16023), INT16_C( 24398),
                            INT16_C( 20578), INT16_C( -1642), INT16_C( 24774), INT16_C( 26937),
                            INT16_C(-19881), INT16_C(-20408), INT16_C( 26365), INT16_C( -2980),
                            INT16_C( -4479), INT16_C(-10298), INT16_C( 13784), INT16_C(-25535),
                            INT16_C(-26583), INT16_C(-31618), INT16_C(  -202), INT16_C( 28295)),
      simde_mm256_set_epi8(INT8_C(  57), INT8_C( 119), INT8_C(   6), INT8_C( -62),
                           INT8_C( -27), INT8_C( -22), INT8_C( -69), INT8_C( -61),
                           INT8_C(   8), INT8_C(-101), INT8_C( -24), INT8_C(  69),
                           INT8_C(-111), INT8_C(  66), INT8_C( -48), INT8_C(-122),
                           INT8_C(  98), INT8_C(-106), INT8_C( -88), INT8_C(  96),
                           INT8_C(  87), INT8_C(  72), INT8_C(  -3), INT8_C(-105),
                           INT8_C(-127), INT8_C( -58), INT8_C(  26), INT8_C(  65),
                           INT8_C(  16), INT8_C( 126), INT8_C(  54), INT8_C(-122)) },
    { simde_mm256_set_epi8(INT8_C(  89), INT8_C(  16), INT8_C(  86), INT8_C( 124),
                           INT8_C(-106), INT8_C(  54), INT8_C(  30), INT8_C( -60),
                           INT8_C(  41), INT8_C(  45), INT8_C(-103), INT8_C( -75),
                           INT8_C( -46), INT8_C(  -2), INT8_C( 119), INT8_C(  28),
                           INT8_C(  69), INT8_C( -84), INT8_C(  78), INT8_C( -36),
                           INT8_C(  42), INT8_C( -59), INT8_C(  42), INT8_C(   5),
                           INT8_C( -74), INT8_C( -70), INT8_C( 107), INT8_C(  22),
                           INT8_C(  91), INT8_C(  10), INT8_C( -44), INT8_C(  28)),
      UINT32_C(      4183),
      simde_mm512_set_epi16(INT16_C(  8531), INT16_C(  2537), INT16_C(  7090), INT16_C( 32184),
                            INT16_C(   918), INT16_C( -4406), INT16_C( -1230), INT16_C(-20248),
                            INT16_C( 28454), INT16_C( -8033), INT16_C( 29491), INT16_C(  9038),
                            INT16_C( 31537), INT16_C(-32476), INT16_C( 15213), INT16_C(  2771),
                            INT16_C(  9158), INT16_C( 15700), INT16_C( 24392), INT16_C(-14500),
                            INT16_C( 20701), INT16_C( -9424), INT16_C( -5862), INT16_C(  8150),
                            INT16_C(-14293), INT16_C( 29409), INT16_C(-21051), INT16_C(-16951),
                            INT16_C(-32102), INT16_C(-16442), INT16_C(  4517), INT16_C(-32738)),
      simde_mm256_set_epi8(INT8_C(  89), INT8_C(  16), INT8_C(  86), INT8_C( 124),
                           INT8_C(-106), INT8_C(  54), INT8_C(  30), INT8_C( -60),
                           INT8_C(  41), INT8_C(  45), INT8_C(-103), INT8_C( -75),
                           INT8_C( -46), INT8_C(  -2), INT8_C( 119), INT8_C(  28),
                           INT8_C(  69), INT8_C( -84), INT8_C(  78), INT8_C(  92),
                           INT8_C(  42), INT8_C( -59), INT8_C(  42), INT8_C(   5),
                           INT8_C( -74), INT8_C( -31), INT8_C( 107), INT8_C( -55),
                           INT8_C(  91), INT8_C( -58), INT8_C( -91), INT8_C(  30)) },
    { simde_mm256_set_epi8(INT8_C(  66), INT8_C( -53), INT8_C( -22), INT8_C(-109),
                           INT8_C(-122), INT8_C( -34), INT8_C(  49), INT8_C( -51),
                           INT8_C(  45), INT8_C(  96), INT8_C(  21), INT8_C(   9),
                           INT8_C(-107), INT8_C(  88), INT8_C(  41), INT8_C(  63),
                           INT8_C( -15), INT8_C(  66), INT8_C( -60), INT8_C(  80),
                           INT8_C( -27), INT8_C(   9), INT8_C(  30), INT8_C( -73),
                           INT8_C( -55), INT8_C( -22), INT8_C(-122), INT8_C(  86),
                           INT8_C( -35), INT8_C( -54), INT8_C(  95), INT8_C( -17)),
      UINT32_C(     34749),
      simde_mm512_set_epi16(INT16_C(  6349), INT16_C( -1940), INT16_C( 12009), INT16_C( 26974),
                            INT16_C( 15374), INT16_C(  6913), INT16_C(-19915), INT16_C(-14530),
                            INT16_C(-31337), INT16_C( 22983), INT16_C(  6281), INT16_C(  -506),
                            INT16_C(-24168), INT16_C(-22228), INT16_C(-32449), INT16_C(-30658),
                            INT16_C(-16400), INT16_C( -7823), INT16_C( -6600), INT16_C( -5428),
                            INT16_C( 10840), INT16_C(-16201), INT16_C(-15359), INT16_C(-30650),
                            INT16_C(  6966), INT16_C(-30042), INT16_C( 32539), INT16_C(-32588),
                            INT16_C(-23367), INT16_C(-13235), INT16_C(-19835), INT16_C( 15017)),
      simde_mm256_set_epi8(INT8_C(  66), INT8_C( -53), INT8_C( -22), INT8_C(-109),
                           INT8_C(-122), INT8_C( -34), INT8_C(  49), INT8_C( -51),
                           INT8_C(  45), INT8_C(  96), INT8_C(  21), INT8_C(   9),
                           INT8_C(-107), INT8_C(  88), INT8_C(  41), INT8_C(  63),
                           INT8_C( -16), INT8_C(  66), INT8_C( -60), INT8_C(  80),
                           INT8_C( -27), INT8_C( -73), INT8_C(   1), INT8_C(  70),
                           INT8_C(  54), INT8_C( -22), INT8_C(  27), INT8_C( -76),
                           INT8_C( -71), INT8_C(  77), INT8_C(  95), INT8_C( -87)) },
    { simde_mm256_set_epi8(INT8_C(-124), INT8_C(  59), INT8_C( -81), INT8_C(  66),
                           INT8_C( -65), INT8_C( -38), INT8_C( -36), INT8_C(   5),
                           INT8_C(  15), INT8_C(  28), INT8_C( -18), INT8_C( -54),
                           INT8_C(  82), INT8_C(  30), INT8_C(-110), INT8_C(-114),
                           INT8_C(   3), INT8_C(  71), INT8_C(  64), INT8_C(  21),
                           INT8_C( 115), INT8_C( 123), INT8_C( -22), INT8_C(-111),
                           INT8_C( -10), INT8_C(  18), INT8_C(   3), INT8_C(  -8),
                           INT8_C( -97), INT8_C(  26), INT8_C(  72), INT8_C( -94)),
      UINT32_C(     31044),
      simde_mm512_set_epi16(INT16_C(-26750), INT16_C(-23902), INT16_C( 29963), INT16_C(  2819),
                            INT16_C(  9258), INT16_C( 16800), INT16_C(-21230), INT16_C( -2332),
                            INT16_C(-12889), INT16_C( 23107), INT16_C( 17922), INT16_C(  3552),
                            INT16_C( 16956), INT16_C(-21244), INT16_C( -9865), INT16_C( 24672),
                            INT16_C(-32513), INT16_C( -3970), INT16_C( 14993), INT16_C(-21626),
                            INT16_C(-29335), INT16_C( -2219), INT16_C(  4209), INT16_C( 11969),
                            INT16_C( -6560), INT16_C(-26729), INT16_C(  7233), INT16_C( 27170),
                            INT16_C(  5881), INT16_C( -9473), INT16_C(-30967), INT16_C(  3275)),
      simde_mm256_set_epi8(INT8_C(-124), INT8_C(  59), INT8_C( -81), INT8_C(  66),
                           INT8_C( -65), INT8_C( -38), INT8_C( -36), INT8_C(   5),
                           INT8_C(  15), INT8_C(  28), INT8_C( -18), INT8_C( -54),
                           INT8_C(  82), INT8_C(  30), INT8_C(-110), INT8_C(-114),
                           INT8_C(   3), INT8_C( 126), INT8_C(-111), INT8_C(-122),
                           INT8_C( 105), INT8_C( 123), INT8_C( -22), INT8_C( -63),
                           INT8_C( -10), INT8_C(-105), INT8_C(   3), INT8_C(  -8),
                           INT8_C( -97), INT8_C(  -1), INT8_C(  72), INT8_C( -94)) },
    { simde_mm256_set_epi8(INT8_C(  76), INT8_C( -68), INT8_C(   3), INT8_C( 100),
                           INT8_C(  64), INT8_C( -71), INT8_C( -39), INT8_C(  30),
                           INT8_C( 110), INT8_C(  44), INT8_C(  96), INT8_C(  10),
                           INT8_C(  66), INT8_C(  40), INT8_C(  31), INT8_C( -85),
                           INT8_C( 120), INT8_C(  70), INT8_C( -37), INT8_C( -25),
                           INT8_C(  51), INT8_C( -19), INT8_C( 124), INT8_C( -52),
                           INT8_C(  69), INT8_C( 107), INT8_C(  96), INT8_C( 106),
                           INT8_C(-126), INT8_C(  61), INT8_C( -71), INT8_C(   9)),
      UINT32_C(     63997),
      simde_mm512_set_epi16(INT16_C( 25271), INT16_C( 20153), INT16_C(-23804), INT16_C(-24091),
                            INT16_C(  6064), INT16_C(  3189), INT16_C( -2682), INT16_C(  5283),
                            INT16_C( 14900), INT16_C(   731), INT16_C(-14623), INT16_C( 14729),
                            INT16_C( -3836), INT16_C( 26379), INT16_C( 13131), INT16_C( 14975),
                            INT16_C( 19045), INT16_C( 14845), INT16_C(-21672), INT16_C(  4155),
                            INT16_C(  9032), INT16_C(-30375), INT16_C( 14167), INT16_C( 25860),
                            INT16_C( -6683), INT16_C(-21473), INT16_C( -6588), INT16_C( 22432),
                            INT16_C( -4408), INT16_C( -2180), INT16_C( 26333), INT16_C( 18369)),
      simde_mm256_set_epi8(INT8_C(  76), INT8_C( -68), INT8_C(   3), INT8_C( 100),
                           INT8_C(  64), INT8_C( -71), INT8_C( -39), INT8_C(  30),
                           INT8_C( 110), INT8_C(  44), INT8_C(  96), INT8_C(  10),
                           INT8_C(  66), INT8_C(  40), INT8_C(  31), INT8_C( -85),
                           INT8_C( 101), INT8_C(  -3), INT8_C(  88), INT8_C(  59),
                           INT8_C(  72), INT8_C( -19), INT8_C( 124), INT8_C(   4),
                           INT8_C( -27), INT8_C(  31), INT8_C(  68), INT8_C( -96),
                           INT8_C( -56), INT8_C( 124), INT8_C( -71), INT8_C( -63)) },
    { simde_mm256_set_epi8(INT8_C(  40), INT8_C( -41), INT8_C(-126), INT8_C(   8),
                           INT8_C(-115), INT8_C( 108), INT8_C(  31), INT8_C(  41),
                           INT8_C( -21), INT8_C( -60), INT8_C(  76), INT8_C(  74),
                           INT8_C(  86), INT8_C(  39), INT8_C(  41), INT8_C( -61),
                           INT8_C( 120), INT8_C(  -6), INT8_C(-117), INT8_C(  43),
                           INT8_C(  64), INT8_C( -40), INT8_C( -63), INT8_C(  39),
                           INT8_C(  82), INT8_C(  -3), INT8_C(  -8), INT8_C(-102),
                           INT8_C(  21), INT8_C(-109), INT8_C(  -6), INT8_C( 102)),
      UINT32_C(     16734),
      simde_mm512_set_epi16(INT16_C(-25905), INT16_C( 19727), INT16_C( 28735), INT16_C(  3852),
                            INT16_C(-23084), INT16_C( -6530), INT16_C( -1505), INT16_C(  9601),
                            INT16_C( -7362), INT16_C(  8505), INT16_C(-26382), INT16_C( 25139),
                            INT16_C(  4198), INT16_C( -1011), INT16_C( -5955), INT16_C( 29084),
                            INT16_C( 25996), INT16_C( 30463), INT16_C( -4775), INT16_C( 11032),
                            INT16_C(-28689), INT16_C(-14740), INT16_C( -1416), INT16_C(  8406),
                            INT16_C(-23209), INT16_C( 25079), INT16_C( 23521), INT16_C( 23507),
                            INT16_C( 15383), INT16_C(-27993), INT16_C(  2371), INT16_C(-19992)),
      simde_mm256_set_epi8(INT8_C(  40), INT8_C( -41), INT8_C(-126), INT8_C(   8),
                           INT8_C(-115), INT8_C( 108), INT8_C(  31), INT8_C(  41),
                           INT8_C( -21), INT8_C( -60), INT8_C(  76), INT8_C(  74),
                           INT8_C(  86), INT8_C(  39), INT8_C(  41), INT8_C( -61),
                           INT8_C( 120), INT8_C(  -1), INT8_C(-117), INT8_C(  43),
                           INT8_C(  64), INT8_C( -40), INT8_C( -63), INT8_C( -42),
                           INT8_C(  82), INT8_C(  -9), INT8_C(  -8), INT8_C( -45),
                           INT8_C(  23), INT8_C( -89), INT8_C(  67), INT8_C( 102)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm512_mask_cvtepi16_epi8(test_vec[i].src, test_vec[i].k, test_vec[i].a);
    simde_assert_m256i_i8(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm512_maskz_cvtepi16_epi8(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__mmask32 k;
    simde__m512i a;
    simde__m256i r;
  } test_vec[8] = {
    { UINT32_C(     25439),
      simde_mm512_set_epi16(INT16_C( 26140), INT16_C( -8634), INT16_C( 26242), INT16_C(  1035),
                            INT16_C(-29578), INT16_C( -2997), INT16_C( 22546), INT16_C(-28782),
                            INT16_C(-11973), INT16_C( 12912), INT16_C(-22923), INT16_C(-12898),
                            INT16_C(  4984), INT16_C(   989), INT16_C(  2511), INT16_C( 26483),
                            INT16_C(-18247), INT16_C( 15612), INT16_C( -5009), INT16_C(-29481),
                            INT16_C(-28622), INT16_C(-22831), INT16_C(  6386), INT16_C(-19204),
                            INT16_C(-26509), INT16_C(-19102), INT16_C(-14606), INT16_C( 25117),
                            INT16_C( -8613), INT16_C( -2080), INT16_C( 27082), INT16_C(  2892)),
      simde_mm256_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(  -4), INT8_C( 111), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C( -14), INT8_C(  -4),
                           INT8_C(   0), INT8_C(  98), INT8_C(   0), INT8_C(  29),
                           INT8_C(  91), INT8_C( -32), INT8_C( -54), INT8_C(  76)) },
    { UINT32_C(      1548),
      simde_mm512_set_epi16(INT16_C( -5255), INT16_C( 10791), INT16_C(-28009), INT16_C( 13848),
                            INT16_C(-23627), INT16_C( 27947), INT16_C(-20059), INT16_C( -3225),
                            INT16_C( -1319), INT16_C(   909), INT16_C(  7874), INT16_C(  7795),
                            INT16_C( -7004), INT16_C( 28406), INT16_C(  5294), INT16_C( 15166),
                            INT16_C( 14689), INT16_C(  7676), INT16_C(-12287), INT16_C( 12075),
                            INT16_C( 29253), INT16_C(-14914), INT16_C(  8284), INT16_C( 18521),
                            INT16_C( 32034), INT16_C( 27278), INT16_C( -3730), INT16_C( -7695),
                            INT16_C(  8989), INT16_C(-29300), INT16_C(-14890), INT16_C( 11419)),
      simde_mm256_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C( -66), INT8_C(  92), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(  29), INT8_C(-116), INT8_C(   0), INT8_C(   0)) },
    { UINT32_C(      8241),
      simde_mm512_set_epi16(INT16_C( 28076), INT16_C(  6764), INT16_C(  4165), INT16_C(-17018),
                            INT16_C( 19920), INT16_C( 28417), INT16_C(-26944), INT16_C( -1327),
                            INT16_C(-18966), INT16_C(-19374), INT16_C(  9639), INT16_C(-25572),
                            INT16_C(-16315), INT16_C( 16363), INT16_C( -4686), INT16_C(-14474),
                            INT16_C( 26743), INT16_C( 20737), INT16_C(-16355), INT16_C( 24251),
                            INT16_C(-20830), INT16_C( 19809), INT16_C(-32085), INT16_C(-29115),
                            INT16_C(-21999), INT16_C( 14843), INT16_C( 13075), INT16_C(-28846),
                            INT16_C(-12894), INT16_C( 31357), INT16_C( 16553), INT16_C(-16546)),
      simde_mm256_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(  29), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(  19), INT8_C(  82),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(  94)) },
    { UINT32_C(     46999),
      simde_mm512_set_epi16(INT16_C( 28715), INT16_C( 26138), INT16_C( 16023), INT16_C( 24398),
                            INT16_C( 20578), INT16_C( -1642), INT16_C( 24774), INT16_C( 26937),
                            INT16_C(-19881), INT16_C(-20408), INT16_C( 26365), INT16_C( -2980),
                            INT16_C( -4479), INT16_C(-10298), INT16_C( 13784), INT16_C(-25535),
                            INT16_C(-26583), INT16_C(-31618), INT16_C(  -202), INT16_C( 28295),
                            INT16_C(-12554), INT16_C( -5929), INT16_C(-27764), INT16_C(-12586),
                            INT16_C( 14711), INT16_C(  1730), INT16_C( -6678), INT16_C(-17469),
                            INT16_C(  2203), INT16_C( -6075), INT16_C(-28350), INT16_C(-12154)),
      simde_mm256_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(  41), INT8_C(   0), INT8_C(  54), INT8_C(-121),
                           INT8_C(   0), INT8_C( -41), INT8_C(-116), INT8_C( -42),
                           INT8_C( 119), INT8_C(   0), INT8_C(   0), INT8_C( -61),
                           INT8_C(   0), INT8_C(  69), INT8_C(  66), INT8_C(-122)) },
    { UINT32_C(     14491),
      simde_mm512_set_epi16(INT16_C(-32102), INT16_C(-16442), INT16_C(  4517), INT16_C(-32738),
                            INT16_C(  -320), INT16_C(  2839), INT16_C( 18963), INT16_C(  4183),
                            INT16_C( 22800), INT16_C( 22140), INT16_C(-27082), INT16_C(  7876),
                            INT16_C( 10541), INT16_C(-26187), INT16_C(-11522), INT16_C( 30492),
                            INT16_C( 17836), INT16_C( 20188), INT16_C( 10949), INT16_C( 10757),
                            INT16_C(-18758), INT16_C( 27414), INT16_C( 23306), INT16_C(-11236),
                            INT16_C(-28100), INT16_C(  2824), INT16_C(-32113), INT16_C(-30059),
                            INT16_C(-19864), INT16_C(-29923), INT16_C( 19573), INT16_C(-11183)),
      simde_mm256_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C( -59), INT8_C(   5),
                           INT8_C( -70), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(  60), INT8_C(   0), INT8_C(   0), INT8_C(-107),
                           INT8_C( 104), INT8_C(   0), INT8_C( 117), INT8_C(  81)) },
    { UINT32_C(     48585),
      simde_mm512_set_epi16(INT16_C( -3774), INT16_C(-15280), INT16_C( -6903), INT16_C(  7863),
                            INT16_C(-13846), INT16_C(-31146), INT16_C( -8758), INT16_C( 24559),
                            INT16_C(  8531), INT16_C(  2537), INT16_C(  7090), INT16_C( 32184),
                            INT16_C(   918), INT16_C( -4406), INT16_C( -1230), INT16_C(-20248),
                            INT16_C( 28454), INT16_C( -8033), INT16_C( 29491), INT16_C(  9038),
                            INT16_C( 31537), INT16_C(-32476), INT16_C( 15213), INT16_C(  2771),
                            INT16_C(  9158), INT16_C( 15700), INT16_C( 24392), INT16_C(-14500),
                            INT16_C( 20701), INT16_C( -9424), INT16_C( -5862), INT16_C(  8150)),
      simde_mm256_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(  38), INT8_C(   0), INT8_C(  51), INT8_C(  78),
                           INT8_C(  49), INT8_C(  36), INT8_C(   0), INT8_C( -45),
                           INT8_C( -58), INT8_C(  84), INT8_C(   0), INT8_C(   0),
                           INT8_C( -35), INT8_C(   0), INT8_C(   0), INT8_C( -42)) },
    { UINT32_C(     10559),
      simde_mm512_set_epi16(INT16_C(-31337), INT16_C( 22983), INT16_C(  6281), INT16_C(  -506),
                            INT16_C(-24168), INT16_C(-22228), INT16_C(-32449), INT16_C(-30658),
                            INT16_C(-16400), INT16_C( -7823), INT16_C( -6600), INT16_C( -5428),
                            INT16_C( 10840), INT16_C(-16201), INT16_C(-15359), INT16_C(-30650),
                            INT16_C(  6966), INT16_C(-30042), INT16_C( 32539), INT16_C(-32588),
                            INT16_C(-23367), INT16_C(-13235), INT16_C(-19835), INT16_C( 15017),
                            INT16_C( -4677), INT16_C(-14834), INT16_C(  9957), INT16_C(-30787),
                            INT16_C( 17099), INT16_C( -5485), INT16_C(-31010), INT16_C( 12749)),
      simde_mm256_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(  27), INT8_C(   0),
                           INT8_C( -71), INT8_C(   0), INT8_C(   0), INT8_C( -87),
                           INT8_C(   0), INT8_C(   0), INT8_C( -27), INT8_C( -67),
                           INT8_C( -53), INT8_C(-109), INT8_C( -34), INT8_C( -51)) },
    { UINT32_C(     51006),
      simde_mm512_set_epi16(INT16_C( -6560), INT16_C(-26729), INT16_C(  7233), INT16_C( 27170),
                            INT16_C(  5881), INT16_C( -9473), INT16_C(-30967), INT16_C(  3275),
                            INT16_C( -2646), INT16_C( 14621), INT16_C( 19871), INT16_C( 31044),
                            INT16_C(-31685), INT16_C(-20670), INT16_C(-16422), INT16_C( -9211),
                            INT16_C(  3868), INT16_C( -4406), INT16_C( 21022), INT16_C(-28018),
                            INT16_C(   839), INT16_C( 16405), INT16_C( 29563), INT16_C( -5487),
                            INT16_C( -2542), INT16_C(  1016), INT16_C(-24806), INT16_C( 18594),
                            INT16_C(  6349), INT16_C( -1940), INT16_C( 12009), INT16_C( 26974)),
      simde_mm256_set_epi8(INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(   0), INT8_C(   0), INT8_C(   0),
                           INT8_C(  28), INT8_C( -54), INT8_C(   0), INT8_C(   0),
                           INT8_C(   0), INT8_C(  21), INT8_C( 123), INT8_C(-111),
                           INT8_C(   0), INT8_C(   0), INT8_C(  26), INT8_C( -94),
                           INT8_C( -51), INT8_C( 108), INT8_C( -23), INT8_C(   0)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm512_maskz_cvtepi16_epi8(test_vec[i].k, test_vec[i].a);
    simde_assert_m256i_i8(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm512_cvtepi8_epi16(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m256i a;
    simde__m512i r;
  } test_vec[8] = {
    { simde_mm256_set_epi8(INT8_C(   7), INT8_C(  68), INT8_C( -86), INT8_C( -36),
                           INT8_C( -19), INT8_C(  73), INT8_C(  92), INT8_C( -27),
                           INT8_C(  55), INT8_C( -65), INT8_C( -50), INT8_C(  19),
                           INT8_C(-111), INT8_C( -79), INT8_C( -16), INT8_C(  70),
                           INT8_C(  27), INT8_C( -28), INT8_C( 116), INT8_C(  42),
                           INT8_C(  -4), INT8_C(  78), INT8_C(  31), INT8_C(  51),
                           INT8_C(  92), INT8_C(  39), INT8_C(-125), INT8_C(  94),
                           INT8_C( -78), INT8_C(  67), INT8_C( -43), INT8_C( -71)),
      simde_mm512_set_epi16(INT16_C(     7), INT16_C(    68), INT16_C(   -86), INT16_C(   -36),
                            INT16_C(   -19), INT16_C(    73), INT16_C(    92), INT16_C(   -27),
                            INT16_C(    55), INT16_C(   -65), INT16_C(   -50), INT16_C(    19),
                            INT16_C(  -111), INT16_C(   -79), INT16_C(   -16), INT16_C(    70),
                            INT16_C(    27), INT16_C(   -28), INT16_C(   116), INT16_C(    42),
                            INT16_C(    -4), INT16_C(    78), INT16_C(    31), INT16_C(    51),
                            INT16_C(    92), INT16_C(    39), INT16_C(  -125), INT16_C(    94),
                            INT16_C(   -78), INT16_C(    67), INT16_C(   -43), INT16_C(   -71)) },
    { simde_mm256_set_epi8(INT8_C(  29), INT8_C( -37), INT8_C(  27), INT8_C(  10),
                           INT8_C( -22), INT8_C(  -9), INT8_C(-125), INT8_C(  -3),
                           INT8_C( -53), INT8_C(  92), INT8_C( 103), INT8_C(  92),
                           INT8_C( 123), INT8_C(  74), INT8_C(  36), INT8_C(  59),
                           INT8_C(  46), INT8_C( -29), INT8_C(-103), INT8_C(  -4),
                           INT8_C( 109), INT8_C( -54), INT8_C(  41), INT8_C(  79),
                           INT8_C(  15), INT8_C( -92), INT8_C( 102), INT8_C( 116),
                           INT8_C( -42), INT8_C(  52), INT8_C( -61), INT8_C( -99)),
      simde_mm512_set_epi16(INT16_C(    29), INT16_C(   -37), INT16_C(    27), INT16_C(    10),
                            INT16_C(   -22), INT16_C(    -9), INT16_C(  -125), INT16_C(    -3),
                            INT16_C(   -53), INT16_C(    92), INT16_C(   103), INT16_C(    92),
                            INT16_C(   123), INT16_C(    74), INT16_C(    36), INT16_C(    59),
                            INT16_C(    46), INT16_C(   -29), INT16_C(  -103), INT16_C(    -4),
                            INT16_C(   109), INT16_C(   -54), INT16_C(    41), INT16_C(    79),
                            INT16_C(    15), INT16_C(   -92), INT16_C(   102), INT16_C(   116),
                            INT16_C(   -42), INT16_C(    52), INT16_C(   -61), INT16_C(   -99)) },
    { simde_mm256_set_epi8(INT8_C(  -9), INT8_C( -47), INT8_C( 107), INT8_C( -74),
                           INT8_C(-126), INT8_C(  34), INT8_C(  64), INT8_C( 115),
                           INT8_C( -65), INT8_C(-124), INT8_C(  54), INT8_C(  27),
                           INT8_C(  41), INT8_C( 112), INT8_C(  61), INT8_C(   6),
                           INT8_C(   7), INT8_C(  39), INT8_C(-109), INT8_C( -99),
                           INT8_C(  63), INT8_C( -35), INT8_C(-111), INT8_C( -72),
                           INT8_C( 109), INT8_C( -39), INT8_C( -99), INT8_C(  26),
                           INT8_C(  66), INT8_C( -78), INT8_C(  30), INT8_C(  38)),
      simde_mm512_set_epi16(INT16_C(    -9), INT16_C(   -47), INT16_C(   107), INT16_C(   -74),
                            INT16_C(  -126), INT16_C(    34), INT16_C(    64), INT16_C(   115),
                            INT16_C(   -65), INT16_C(  -124), INT16_C(    54), INT16_C(    27),
                            INT16_C(    41), INT16_C(   112), INT16_C(    61), INT16_C(     6),
                            INT16_C(     7), INT16_C(    39), INT16_C(  -109), INT16_C(   -99),
                            INT16_C(    63), INT16_C(   -35), INT16_C(  -111), INT16_C(   -72),
                            INT16_C(   109), INT16_C(   -39), INT16_C(   -99), INT16_C(    26),
                            INT16_C(    66), INT16_C(   -78), INT16_C(    30), INT16_C(    38)) },
    { simde_mm256_set_epi8(INT8_C( -72), INT8_C( -80), INT8_C( 101), INT8_C(  81),
                           INT8_C(  23), INT8_C( -68), INT8_C( -57), INT8_C(-111),
                           INT8_C(  -3), INT8_C(  21), INT8_C( 121), INT8_C( -22),
                           INT8_C(-104), INT8_C( -10), INT8_C( -37), INT8_C(  66),
                           INT8_C( -93), INT8_C( -80), INT8_C(  34), INT8_C( 104),
                           INT8_C( -39), INT8_C( -99), INT8_C(  18), INT8_C( 110),
                           INT8_C(-118), INT8_C(  38), INT8_C( 112), INT8_C( -67),
                           INT8_C(  60), INT8_C(  47), INT8_C(  32), INT8_C(  33)),
      simde_mm512_set_epi16(INT16_C(   -72), INT16_C(   -80), INT16_C(   101), INT16_C(    81),
                            INT16_C(    23), INT16_C(   -68), INT16_C(   -57), INT16_C(  -111),
                            INT16_C(    -3), INT16_C(    21), INT16_C(   121), INT16_C(   -22),
                            INT16_C(  -104), INT16_C(   -10), INT16_C(   -37), INT16_C(    66),
                            INT16_C(   -93), INT16_C(   -80), INT16_C(    34), INT16_C(   104),
                            INT16_C(   -39), INT16_C(   -99), INT16_C(    18), INT16_C(   110),
                            INT16_C(  -118), INT16_C(    38), INT16_C(   112), INT16_C(   -67),
                            INT16_C(    60), INT16_C(    47), INT16_C(    32), INT16_C(    33)) },
    { simde_mm256_set_epi8(INT8_C( 120), INT8_C( -90), INT8_C(-101), INT8_C(-106),
                           INT8_C(  70), INT8_C( -49), INT8_C(  29), INT8_C( -43),
                           INT8_C( -42), INT8_C(  38), INT8_C(  16), INT8_C( -43),
                           INT8_C( -40), INT8_C( -76), INT8_C( -67), INT8_C(  53),
                           INT8_C( -73), INT8_C( -17), INT8_C(  66), INT8_C(  57),
                           INT8_C( -65), INT8_C( -63), INT8_C(  17), INT8_C(  -9),
                           INT8_C(  95), INT8_C( -50), INT8_C(-118), INT8_C( 114),
                           INT8_C(  58), INT8_C( -28), INT8_C( -81), INT8_C( -37)),
      simde_mm512_set_epi16(INT16_C(   120), INT16_C(   -90), INT16_C(  -101), INT16_C(  -106),
                            INT16_C(    70), INT16_C(   -49), INT16_C(    29), INT16_C(   -43),
                            INT16_C(   -42), INT16_C(    38), INT16_C(    16), INT16_C(   -43),
                            INT16_C(   -40), INT16_C(   -76), INT16_C(   -67), INT16_C(    53),
                            INT16_C(   -73), INT16_C(   -17), INT16_C(    66), INT16_C(    57),
                            INT16_C(   -65), INT16_C(   -63), INT16_C(    17), INT16_C(    -9),
                            INT16_C(    95), INT16_C(   -50), INT16_C(  -118), INT16_C(   114),
                            INT16_C(    58), INT16_C(   -28), INT16_C(   -81), INT16_C(   -37)) },
    { simde_mm256_set_epi8(INT8_C( -97), INT8_C(  10), INT8_C( -75), INT8_C(-120),
                           INT8_C( -32), INT8_C(-105), INT8_C( -75), INT8_C(-101),
                           INT8_C(  71), INT8_C(-122), INT8_C(-112), INT8_C(  -2),
                           INT8_C(  60), INT8_C( -71), INT8_C( 101), INT8_C(  -1),
                           INT8_C(  95), INT8_C( -58), INT8_C( -70), INT8_C( 102),
                           INT8_C( 115), INT8_C( -68), INT8_C(-110), INT8_C( -36),
                           INT8_C(   6), INT8_C(  58), INT8_C(  73), INT8_C(  97),
                           INT8_C( -51), INT8_C(  -4), INT8_C(  58), INT8_C(  31)),
      simde_mm512_set_epi16(INT16_C(   -97), INT16_C(    10), INT16_C(   -75), INT16_C(  -120),
                            INT16_C(   -32), INT16_C(  -105), INT16_C(   -75), INT16_C(  -101),
                            INT16_C(    71), INT16_C(  -122), INT16_C(  -112), INT16_C(    -2),
                            INT16_C(    60), INT16_C(   -71), INT16_C(   101), INT16_C(    -1),
                            INT16_C(    95), INT16_C(   -58), INT16_C(   -70), INT16_C(   102),
                            INT16_C(   115), INT16_C(   -68), INT16_C(  -110), INT16_C(   -36),
                            INT16_C(     6), INT16_C(    58), INT16_C(    73), INT16_C(    97),
                            INT16_C(   -51), INT16_C(    -4), INT16_C(    58), INT16_C(    31)) },
    { simde_mm256_set_epi8(INT8_C( -73), INT8_C(-123), INT8_C( -11), INT8_C(  62),
                           INT8_C( -96), INT8_C(-103), INT8_C(  85), INT8_C(  88),
                           INT8_C( -19), INT8_C(  28), INT8_C(-107), INT8_C( -81),
                           INT8_C(-125), INT8_C(  88), INT8_C(  84), INT8_C( 115),
                           INT8_C( 105), INT8_C( -47), INT8_C(  68), INT8_C(-124),
                           INT8_C(  32), INT8_C(-100), INT8_C(  10), INT8_C( -69),
                           INT8_C( 124), INT8_C( -51), INT8_C( -89), INT8_C( -72),
                           INT8_C( -92), INT8_C(  -5), INT8_C( -46), INT8_C( 115)),
      simde_mm512_set_epi16(INT16_C(   -73), INT16_C(  -123), INT16_C(   -11), INT16_C(    62),
                            INT16_C(   -96), INT16_C(  -103), INT16_C(    85), INT16_C(    88),
                            INT16_C(   -19), INT16_C(    28), INT16_C(  -107), INT16_C(   -81),
                            INT16_C(  -125), INT16_C(    88), INT16_C(    84), INT16_C(   115),
                            INT16_C(   105), INT16_C(   -47), INT16_C(    68), INT16_C(  -124),
                            INT16_C(    32), INT16_C(  -100), INT16_C(    10), INT16_C(   -69),
                            INT16_C(   124), INT16_C(   -51), INT16_C(   -89), INT16_C(   -72),
                            INT16_C(   -92), INT16_C(    -5), INT16_C(   -46), INT16_C(   115)) },
    { simde_mm256_set_epi8(INT8_C( 104), INT8_C(  66), INT8_C(  51), INT8_C(  81),
                           INT8_C( -69), INT8_C( 104), INT8_C( 126), INT8_C( -43),
                           INT8_C( -40), INT8_C(  23), INT8_C(-124), INT8_C(  98),
                           INT8_C(-125), INT8_C(  95), INT8_C( -36), INT8_C(  46),
                           INT8_C(-115), INT8_C( -93), INT8_C(   2), INT8_C( -77),
                           INT8_C(  80), INT8_C(-116), INT8_C(  61), INT8_C( -89),
                           INT8_C( -37), INT8_C(   9), INT8_C(  84), INT8_C( -64),
                           INT8_C(  94), INT8_C(  67), INT8_C( -53), INT8_C( 111)),
      simde_mm512_set_epi16(INT16_C(   104), INT16_C(    66), INT16_C(    51), INT16_C(    81),
                            INT16_C(   -69), INT16_C(   104), INT16_C(   126), INT16_C(   -43),
                            INT16_C(   -40), INT16_C(    23), INT16_C(  -124), INT16_C(    98),
                            INT16_C(  -125), INT16_C(    95), INT16_C(   -36), INT16_C(    46),
                            INT16_C(  -115), INT16_C(   -93), INT16_C(     2), INT16_C(   -77),
                            INT16_C(    80), INT16_C(  -116), INT16_C(    61), INT16_C(   -89),
                            INT16_C(   -37), INT16_C(     9), INT16_C(    84), INT16_C(   -64),
                            INT16_C(    94), INT16_C(    67), INT16_C(   -53), INT16_C(   111)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i r = simde_mm512_cvtepi8_epi16(test_vec[i].a);
    simde_assert_m512i_i16(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm512_cvtepi32_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t a[16];
    const simde_float32 r[16];
  } test_vec[] = {
    { { -INT32_C(   306772899), -INT32_C(    67271131), -INT32_C(   861816948),  INT32_C(  1650063263), -INT32_C(   965362418),  INT32_C(  1647322575),  INT32_C(   278105299),  INT32_C(   223924400),
        -INT32_C(    84275243),  INT32_C(   569833365),  INT32_C(  1324259247), -INT32_C(  1649326194), -INT32_C(   731699707),  INT32_C(   506893131), -INT32_C(   819017185),  INT32_C(  1876723354) },
      { SIMDE_FLOAT32_C(-306772896.00), SIMDE_FLOAT32_C(-67271128.00), SIMDE_FLOAT32_C(-861816960.00), SIMDE_FLOAT32_C(1650063232.00),
        SIMDE_FLOAT32_C(-965362432.00), SIMDE_FLOAT32_C(1647322624.00), SIMDE_FLOAT32_C(278105312.00), SIMDE_FLOAT32_C(223924400.00),
        SIMDE_FLOAT32_C(-84275240.00), SIMDE_FLOAT32_C(569833344.00), SIMDE_FLOAT32_C(1324259200.00), SIMDE_FLOAT32_C(-1649326208.00),
        SIMDE_FLOAT32_C(-731699712.00), SIMDE_FLOAT32_C(506893120.00), SIMDE_FLOAT32_C(-819017216.00), SIMDE_FLOAT32_C(1876723328.00) } },
    { {  INT32_C(   728422293),  INT32_C(  2102157518), -INT32_C(  2033435913), -INT32_C(  2027717246), -INT32_C(   279214429),  INT32_C(   940413465), -INT32_C(   167232420),  INT32_C(  1483138242),
        -INT32_C(  1971072837),  INT32_C(   654823216), -INT32_C(  1934765302), -INT32_C(   200028080),  INT32_C(  1877175894),  INT32_C(  1554575360), -INT32_C(   279728084),  INT32_C(  1346877844) },
      { SIMDE_FLOAT32_C(728422272.00), SIMDE_FLOAT32_C(2102157568.00), SIMDE_FLOAT32_C(-2033435904.00), SIMDE_FLOAT32_C(-2027717248.00),
        SIMDE_FLOAT32_C(-279214432.00), SIMDE_FLOAT32_C(940413440.00), SIMDE_FLOAT32_C(-167232416.00), SIMDE_FLOAT32_C(1483138304.00),
        SIMDE_FLOAT32_C(-1971072896.00), SIMDE_FLOAT32_C(654823232.00), SIMDE_FLOAT32_C(-1934765312.00), SIMDE_FLOAT32_C(-200028080.00),
        SIMDE_FLOAT32_C(1877175936.00), SIMDE_FLOAT32_C(1554575360.00), SIMDE_FLOAT32_C(-279728096.00), SIMDE_FLOAT32_C(1346877824.00) } },
    { { -INT32_C(  1176843639), -INT32_C(  1545543271),  INT32_C(    87002805), -INT32_C(  1241955746), -INT32_C(  1322984271), -INT32_C(   116470579),  INT32_C(   300441980), -INT32_C(  1553912038),
        -INT32_C(  1822671879), -INT32_C(   784974820),  INT32_C(   701982410),  INT32_C(  1507774632),  INT32_C(  2047541933),  INT32_C(  1265834447), -INT32_C(  1805886342), -INT32_C(  2059944565) },
      { SIMDE_FLOAT32_C(-1176843648.00), SIMDE_FLOAT32_C(-1545543296.00), SIMDE_FLOAT32_C(87002808.00), SIMDE_FLOAT32_C(-1241955712.00),
        SIMDE_FLOAT32_C(-1322984320.00), SIMDE_FLOAT32_C(-116470576.00), SIMDE_FLOAT32_C(300441984.00), SIMDE_FLOAT32_C(-1553912064.00),
        SIMDE_FLOAT32_C(-1822671872.00), SIMDE_FLOAT32_C(-784974848.00), SIMDE_FLOAT32_C(701982400.00), SIMDE_FLOAT32_C(1507774592.00),
        SIMDE_FLOAT32_C(2047541888.00), SIMDE_FLOAT32_C(1265834496.00), SIMDE_FLOAT32_C(-1805886336.00), SIMDE_FLOAT32_C(-2059944576.00) } },
    { {  INT32_C(   353932280), -INT32_C(  1696182577),  INT32_C(  1573109172),  INT32_C(  1001824654),  INT32_C(  1924514211),  INT32_C(  1421748442),  INT32_C(   283646596), -INT32_C(   795533352),
        -INT32_C(  2098877006), -INT32_C(  1340289797),  INT32_C(   386785161),  INT32_C(   592626560),  INT32_C(  1603667845), -INT32_C(  1263250384),  INT32_C(  1187290222),  INT32_C(  1847024060) },
      { SIMDE_FLOAT32_C(353932288.00), SIMDE_FLOAT32_C(-1696182528.00), SIMDE_FLOAT32_C(1573109120.00), SIMDE_FLOAT32_C(1001824640.00),
        SIMDE_FLOAT32_C(1924514176.00), SIMDE_FLOAT32_C(1421748480.00), SIMDE_FLOAT32_C(283646592.00), SIMDE_FLOAT32_C(-795533376.00),
        SIMDE_FLOAT32_C(-2098877056.00), SIMDE_FLOAT32_C(-1340289792.00), SIMDE_FLOAT32_C(386785152.00), SIMDE_FLOAT32_C(592626560.00),
        SIMDE_FLOAT32_C(1603667840.00), SIMDE_FLOAT32_C(-1263250432.00), SIMDE_FLOAT32_C(1187290240.00), SIMDE_FLOAT32_C(1847024000.00) } },
    { {  INT32_C(    49347590),  INT32_C(  1387400392),  INT32_C(  1802092523),  INT32_C(   126860418), -INT32_C(   211343933), -INT32_C(   408413319),  INT32_C(  1932422327), -INT32_C(   857586234),
         INT32_C(   181326401), -INT32_C(   899907361), -INT32_C(  1036597953),  INT32_C(  1170851201),  INT32_C(  1664626922),  INT32_C(    55238731),  INT32_C(   326531149), -INT32_C(     2139971) },
      { SIMDE_FLOAT32_C(49347592.00), SIMDE_FLOAT32_C(1387400448.00), SIMDE_FLOAT32_C(1802092544.00), SIMDE_FLOAT32_C(126860416.00),
        SIMDE_FLOAT32_C(-211343936.00), SIMDE_FLOAT32_C(-408413312.00), SIMDE_FLOAT32_C(1932422272.00), SIMDE_FLOAT32_C(-857586240.00),
        SIMDE_FLOAT32_C(181326400.00), SIMDE_FLOAT32_C(-899907392.00), SIMDE_FLOAT32_C(-1036597952.00), SIMDE_FLOAT32_C(1170851200.00),
        SIMDE_FLOAT32_C(1664626944.00), SIMDE_FLOAT32_C(55238732.00), SIMDE_FLOAT32_C(326531136.00), SIMDE_FLOAT32_C(-2139971.00) } },
    { {  INT32_C(   168406571),  INT32_C(  1859413294), -INT32_C(  1406137814), -INT32_C(  1175324209),  INT32_C(  1964779818),  INT32_C(  1467508490), -INT32_C(  1653936161),  INT32_C(  1922844999),
         INT32_C(   645703159),  INT32_C(   882135306),  INT32_C(   736150619), -INT32_C(   404434499),  INT32_C(    89981435),  INT32_C(  1197266280),  INT32_C(   216319684),  INT32_C(   125730831) },
      { SIMDE_FLOAT32_C(168406576.00), SIMDE_FLOAT32_C(1859413248.00), SIMDE_FLOAT32_C(-1406137856.00), SIMDE_FLOAT32_C(-1175324160.00),
        SIMDE_FLOAT32_C(1964779776.00), SIMDE_FLOAT32_C(1467508480.00), SIMDE_FLOAT32_C(-1653936128.00), SIMDE_FLOAT32_C(1922845056.00),
        SIMDE_FLOAT32_C(645703168.00), SIMDE_FLOAT32_C(882135296.00), SIMDE_FLOAT32_C(736150592.00), SIMDE_FLOAT32_C(-404434496.00),
        SIMDE_FLOAT32_C(89981432.00), SIMDE_FLOAT32_C(1197266304.00), SIMDE_FLOAT32_C(216319680.00), SIMDE_FLOAT32_C(125730832.00) } },
    { {  INT32_C(   791542565), -INT32_C(  1486569140),  INT32_C(  1121076357),  INT32_C(   288012054),  INT32_C(   538347448),  INT32_C(   560427612),  INT32_C(  1194150968), -INT32_C(   229725236),
        -INT32_C(   232686682), -INT32_C(  1046837956), -INT32_C(   536580918), -INT32_C(   604951005),  INT32_C(   301664181), -INT32_C(  1322097799),  INT32_C(  2079874991), -INT32_C(  1318238453) },
      { SIMDE_FLOAT32_C(791542592.00), SIMDE_FLOAT32_C(-1486569088.00), SIMDE_FLOAT32_C(1121076352.00), SIMDE_FLOAT32_C(288012064.00),
        SIMDE_FLOAT32_C(538347456.00), SIMDE_FLOAT32_C(560427584.00), SIMDE_FLOAT32_C(1194150912.00), SIMDE_FLOAT32_C(-229725232.00),
        SIMDE_FLOAT32_C(-232686688.00), SIMDE_FLOAT32_C(-1046837952.00), SIMDE_FLOAT32_C(-536580928.00), SIMDE_FLOAT32_C(-604950976.00),
        SIMDE_FLOAT32_C(301664192.00), SIMDE_FLOAT32_C(-1322097792.00), SIMDE_FLOAT32_C(2079874944.00), SIMDE_FLOAT32_C(-1318238464.00) } },
    { { -INT32_C(     5992510), -INT32_C(   557826540), -INT32_C(   826358614), -INT32_C(  1482051598),  INT32_C(   800695734), -INT32_C(  1209996536),  INT32_C(  1446173003), -INT32_C(   502816736),
         INT32_C(  1138862895), -INT32_C(  1809669399),  INT32_C(  1499652198),  INT32_C(  1174408080), -INT32_C(  1200178768), -INT32_C(   261138779),  INT32_C(  1330029103),  INT32_C(  1899121986) },
      { SIMDE_FLOAT32_C(-5992510.00), SIMDE_FLOAT32_C(-557826560.00), SIMDE_FLOAT32_C(-826358592.00), SIMDE_FLOAT32_C(-1482051584.00),
        SIMDE_FLOAT32_C(800695744.00), SIMDE_FLOAT32_C(-1209996544.00), SIMDE_FLOAT32_C(1446173056.00), SIMDE_FLOAT32_C(-502816736.00),
        SIMDE_FLOAT32_C(1138862848.00), SIMDE_FLOAT32_C(-1809669376.00), SIMDE_FLOAT32_C(1499652224.00), SIMDE_FLOAT32_C(1174408064.00),
        SIMDE_FLOAT32_C(-1200178816.00), SIMDE_FLOAT32_C(-261138784.00), SIMDE_FLOAT32_C(1330029056.00), SIMDE_FLOAT32_C(1899122048.00) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_epi32(test_vec[i].a);
    simde__m512 r = simde_mm512_cvtepi32_ps(a);
    simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512i a = simde_test_x86_random_i32x16();
    simde__m512 r = simde_mm512_cvtepi32_ps(a);

    simde_test_x86_write_i32x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f32x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_cvtepi64_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int64_t a[8];
    const int32_t r[8];
  } test_vec[] = {
    { {  INT64_C( 5499118837676661407),  INT64_C(  802518787675509433), -INT64_C( 1895252414684915744), -INT64_C(  815293002885254977),
        -INT64_C( 7667159720415325990), -INT64_C( 8054238576114298471), -INT64_C( 5796790294263940432),  INT64_C( 1126953469552277081) },
      { -INT32_C(  2124391777), -INT32_C(   520498503),  INT32_C(  1728124896),  INT32_C(  1596567743),  INT32_C(  1282805978),  INT32_C(   779456921), -INT32_C(  1460192592), -INT32_C(  1357990311) } },
    { {  INT64_C( 8736688473384884686), -INT64_C(  232532088305765499), -INT64_C( 4631053477468652517),  INT64_C( 6137300763706051047),
         INT64_C(   37222295617373995),  INT64_C( 2898622769958038769), -INT64_C(  730446195659055690), -INT64_C( 8604904046600303944) },
      { -INT32_C(  1453647410),  INT32_C(   900182917),  INT32_C(   195345435),  INT32_C(   477022695),  INT32_C(   201295659),  INT32_C(  1026895089),  INT32_C(   473226678),  INT32_C(  1074875064) } },
    { { -INT64_C( 4377471546498509627),  INT64_C( 2700252601848460612),  INT64_C( 6131966023613721878),  INT64_C( 3264311934393330280),
         INT64_C( 4347290823422763199), -INT64_C( 6650119495152217054),  INT64_C( 9198285675416778932),  INT64_C( 2638987771557198602) },
      {  INT32_C(  1083413701),  INT32_C(  1358984516),  INT32_C(   608349462), -INT32_C(   980080024), -INT32_C(  1855070017), -INT32_C(  1853008862),  INT32_C(  1372059828),  INT32_C(  1917074186) } },
    { { -INT64_C( 2619395441305514895), -INT64_C( 1185252386685569955),  INT64_C( 4589702607123010587), -INT64_C(  600296487079774943),
        -INT64_C( 3967099070008172195), -INT64_C( 7104920433032274116), -INT64_C( 5834271970793904236),  INT64_C( 7562635636565784949) },
      {  INT32_C(  1790250097), -INT32_C(   362007459),  INT32_C(   843076635), -INT32_C(  2018380511),  INT32_C(   392257885),  INT32_C(  2008178492), -INT32_C(   909138028), -INT32_C(    80299659) } },
    { { -INT64_C( 7460932564807625662), -INT64_C(  220546195610720304), -INT64_C( 5379042602290659555), -INT64_C( 5478166664036905082),
        -INT64_C( 4977086815038048008), -INT64_C( 8043151361953694211),  INT64_C( 8768953720801732028), -INT64_C(   51788068926365149) },
      { -INT32_C(  1384164286),  INT32_C(  1376724944), -INT32_C(  1429881059), -INT32_C(  1850634362),  INT32_C(  1432385784),  INT32_C(  1678573053), -INT32_C(    63298116), -INT32_C(  1811258845) } },
    { {  INT64_C( 8871600327071410299), -INT64_C( 2071303814381622466),  INT64_C( 3733925065463397477),  INT64_C( 6483231688452791283),
        -INT64_C( 3624873721694696008),  INT64_C( 3896388632289644807),  INT64_C( 8538648431752573244),  INT64_C( 1184843999768233786) },
      {  INT32_C(  1683269755), -INT32_C(  1310774466),  INT32_C(  1491041381), -INT32_C(    87499789),  INT32_C(   918375864),  INT32_C(   780046599),  INT32_C(  1284436284),  INT32_C(   410011450) } },
    { {  INT64_C( 1302094494560563126), -INT64_C( 8318058006688264055), -INT64_C( 5099104476076695740), -INT64_C( 3817289872535606113),
        -INT64_C( 3562592197892092558),  INT64_C( 7389765019772702641),  INT64_C( 6633637038055515607), -INT64_C( 7640821710201888747) },
      {  INT32_C(  1145450422),  INT32_C(  1514180745), -INT32_C(   958914748), -INT32_C(   154030945),  INT32_C(  2098220402),  INT32_C(    19451825),  INT32_C(  1445750231),  INT32_C(   726851605) } },
    { { -INT64_C( 2757996099673127258),  INT64_C( 8212710404306755953), -INT64_C( 6564042024150424114),  INT64_C( 4066686223065758134),
        -INT64_C( 7724275738892598580), -INT64_C( 2321570349060740931),  INT64_C( 1979421534026633030), -INT64_C( 2786209687447189622) },
      { -INT32_C(   351140186), -INT32_C(  1814306447), -INT32_C(  1949882930), -INT32_C(   623953482), -INT32_C(   198999348),  INT32_C(  1462216893), -INT32_C(   731214010),  INT32_C(   502613898) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_epi64(test_vec[i].a);
    simde__m256i r = simde_mm512_cvtepi64_epi32(a);
    simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512i a = simde_test_x86_random_i64x8();
    simde__m256i r = simde_mm512_cvtepi64_epi32(a);

    simde_test_x86_write_i64x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_cvtepu32_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint32_t a[16];
    const simde_float32 r[16];
  } test_vec[] = {
    { { UINT32_C(1870160146), UINT32_C( 989482389), UINT32_C( 886655870), UINT32_C(1378107877), UINT32_C(3861032350), UINT32_C(3088204513), UINT32_C(3493347028), UINT32_C(4188785639),
        UINT32_C(3261670189), UINT32_C(4026360688), UINT32_C(2485376687), UINT32_C(3068544791), UINT32_C(3600550132), UINT32_C( 512667466), UINT32_C(3572418541), UINT32_C(3217987986) },
      { SIMDE_FLOAT32_C(1870160128.00), SIMDE_FLOAT32_C(989482368.00), SIMDE_FLOAT32_C(886655872.00), SIMDE_FLOAT32_C(1378107904.00),
        SIMDE_FLOAT32_C(3861032448.00), SIMDE_FLOAT32_C(3088204544.00), SIMDE_FLOAT32_C(3493347072.00), SIMDE_FLOAT32_C(4188785664.00),
        SIMDE_FLOAT32_C(3261670144.00), SIMDE_FLOAT32_C(4026360576.00), SIMDE_FLOAT32_C(2485376768.00), SIMDE_FLOAT32_C(3068544768.00),
        SIMDE_FLOAT32_C(3600550144.00), SIMDE_FLOAT32_C(512667456.00), SIMDE_FLOAT32_C(3572418560.00), SIMDE_FLOAT32_C(3217988096.00) } },
    { { UINT32_C( 746731452), UINT32_C(1226538906), UINT32_C(1843215957), UINT32_C(2049164166), UINT32_C( 357613515), UINT32_C(1530126190), UINT32_C( 942678438), UINT32_C(1996029626),
        UINT32_C(3483597365), UINT32_C(1310310137), UINT32_C(2210133757), UINT32_C(2248007354), UINT32_C( 211504798), UINT32_C(3546861101), UINT32_C(2852886768), UINT32_C(3407938454) },
      { SIMDE_FLOAT32_C(746731456.00), SIMDE_FLOAT32_C(1226538880.00), SIMDE_FLOAT32_C(1843216000.00), SIMDE_FLOAT32_C(2049164160.00),
        SIMDE_FLOAT32_C(357613504.00), SIMDE_FLOAT32_C(1530126208.00), SIMDE_FLOAT32_C(942678464.00), SIMDE_FLOAT32_C(1996029568.00),
        SIMDE_FLOAT32_C(3483597312.00), SIMDE_FLOAT32_C(1310310144.00), SIMDE_FLOAT32_C(2210133760.00), SIMDE_FLOAT32_C(2248007424.00),
        SIMDE_FLOAT32_C(211504800.00), SIMDE_FLOAT32_C(3546861056.00), SIMDE_FLOAT32_C(2852886784.00), SIMDE_FLOAT32_C(3407938560.00) } },
    { { UINT32_C(1989854333), UINT32_C(2143662978), UINT32_C(1677885610), UINT32_C(4259905631), UINT32_C(2064221262), UINT32_C(1129214291), UINT32_C(2683132169), UINT32_C(3664383581),
        UINT32_C(1431373266), UINT32_C(1658066616), UINT32_C(4123449238), UINT32_C( 636661975), UINT32_C(2275474484), UINT32_C(2009788013), UINT32_C(2752952391), UINT32_C(2575270342) },
      { SIMDE_FLOAT32_C(1989854336.00), SIMDE_FLOAT32_C(2143662976.00), SIMDE_FLOAT32_C(1677885568.00), SIMDE_FLOAT32_C(4259905536.00),
        SIMDE_FLOAT32_C(2064221312.00), SIMDE_FLOAT32_C(1129214336.00), SIMDE_FLOAT32_C(2683132160.00), SIMDE_FLOAT32_C(3664383488.00),
        SIMDE_FLOAT32_C(1431373312.00), SIMDE_FLOAT32_C(1658066560.00), SIMDE_FLOAT32_C(4123449344.00), SIMDE_FLOAT32_C(636661952.00),
        SIMDE_FLOAT32_C(2275474432.00), SIMDE_FLOAT32_C(2009788032.00), SIMDE_FLOAT32_C(2752952320.00), SIMDE_FLOAT32_C(2575270400.00) } },
    { { UINT32_C(1055838342), UINT32_C(2090975974), UINT32_C(1886545817), UINT32_C(1284858903), UINT32_C(3469948256), UINT32_C(1799724579), UINT32_C( 470768470), UINT32_C(1656065756),
        UINT32_C(1151443806), UINT32_C(4290855526), UINT32_C(3245355945), UINT32_C(4161602967), UINT32_C(1590091835), UINT32_C(3569945470), UINT32_C(1139923302), UINT32_C(3332744807) },
      { SIMDE_FLOAT32_C(1055838336.00), SIMDE_FLOAT32_C(2090976000.00), SIMDE_FLOAT32_C(1886545792.00), SIMDE_FLOAT32_C(1284858880.00),
        SIMDE_FLOAT32_C(3469948160.00), SIMDE_FLOAT32_C(1799724544.00), SIMDE_FLOAT32_C(470768480.00), SIMDE_FLOAT32_C(1656065792.00),
        SIMDE_FLOAT32_C(1151443840.00), SIMDE_FLOAT32_C(4290855424.00), SIMDE_FLOAT32_C(3245356032.00), SIMDE_FLOAT32_C(4161603072.00),
        SIMDE_FLOAT32_C(1590091776.00), SIMDE_FLOAT32_C(3569945344.00), SIMDE_FLOAT32_C(1139923328.00), SIMDE_FLOAT32_C(3332744704.00) } },
    { { UINT32_C(2953463370), UINT32_C( 850381704), UINT32_C(2532515838), UINT32_C(1619918885), UINT32_C(1606309088), UINT32_C(3308488799), UINT32_C(3355976801), UINT32_C( 361672395),
        UINT32_C(2110102004), UINT32_C(1672442980), UINT32_C(3120145044), UINT32_C(2182711202), UINT32_C( 987879387), UINT32_C(3237942623), UINT32_C(  76089401), UINT32_C(2853771190) },
      { SIMDE_FLOAT32_C(2953463296.00), SIMDE_FLOAT32_C(850381696.00), SIMDE_FLOAT32_C(2532515840.00), SIMDE_FLOAT32_C(1619918848.00),
        SIMDE_FLOAT32_C(1606309120.00), SIMDE_FLOAT32_C(3308488704.00), SIMDE_FLOAT32_C(3355976704.00), SIMDE_FLOAT32_C(361672384.00),
        SIMDE_FLOAT32_C(2110102016.00), SIMDE_FLOAT32_C(1672443008.00), SIMDE_FLOAT32_C(3120145152.00), SIMDE_FLOAT32_C(2182711296.00),
        SIMDE_FLOAT32_C(987879360.00), SIMDE_FLOAT32_C(3237942528.00), SIMDE_FLOAT32_C(76089400.00), SIMDE_FLOAT32_C(2853771264.00) } },
    { { UINT32_C( 354934448), UINT32_C(3883456083), UINT32_C( 446722424), UINT32_C(3550329336), UINT32_C(4027416208), UINT32_C(3450866835), UINT32_C(3402709268), UINT32_C(  24505169),
        UINT32_C( 471243977), UINT32_C(3942878835), UINT32_C(4144407551), UINT32_C(3989480284), UINT32_C(3051214625), UINT32_C(4169305572), UINT32_C( 415454151), UINT32_C( 135870526) },
      { SIMDE_FLOAT32_C(354934464.00), SIMDE_FLOAT32_C(3883456000.00), SIMDE_FLOAT32_C(446722432.00), SIMDE_FLOAT32_C(3550329344.00),
        SIMDE_FLOAT32_C(4027416320.00), SIMDE_FLOAT32_C(3450866944.00), SIMDE_FLOAT32_C(3402709248.00), SIMDE_FLOAT32_C(24505168.00),
        SIMDE_FLOAT32_C(471243968.00), SIMDE_FLOAT32_C(3942878720.00), SIMDE_FLOAT32_C(4144407552.00), SIMDE_FLOAT32_C(3989480192.00),
        SIMDE_FLOAT32_C(3051214592.00), SIMDE_FLOAT32_C(4169305600.00), SIMDE_FLOAT32_C(415454144.00), SIMDE_FLOAT32_C(135870528.00) } },
    { { UINT32_C(1193554132), UINT32_C(3191023806), UINT32_C( 682965451), UINT32_C(4246044892), UINT32_C(1001583191), UINT32_C(1177826431), UINT32_C(3328112520), UINT32_C(  63862831),
        UINT32_C(1716253608), UINT32_C(3861151259), UINT32_C(2467224247), UINT32_C(2979013466), UINT32_C(2515354389), UINT32_C(4292551031), UINT32_C(1204173336), UINT32_C(1514837170) },
      { SIMDE_FLOAT32_C(1193554176.00), SIMDE_FLOAT32_C(3191023872.00), SIMDE_FLOAT32_C(682965440.00), SIMDE_FLOAT32_C(4246044928.00),
        SIMDE_FLOAT32_C(1001583168.00), SIMDE_FLOAT32_C(1177826432.00), SIMDE_FLOAT32_C(3328112640.00), SIMDE_FLOAT32_C(63862832.00),
        SIMDE_FLOAT32_C(1716253568.00), SIMDE_FLOAT32_C(3861151232.00), SIMDE_FLOAT32_C(2467224320.00), SIMDE_FLOAT32_C(2979013376.00),
        SIMDE_FLOAT32_C(2515354368.00), SIMDE_FLOAT32_C(4292550912.00), SIMDE_FLOAT32_C(1204173312.00), SIMDE_FLOAT32_C(1514837120.00) } },
    { { UINT32_C(2730530183), UINT32_C(3398034707), UINT32_C( 425564095), UINT32_C(3502960315), UINT32_C(2825238321), UINT32_C(4037558744), UINT32_C( 758607483), UINT32_C(2324136450),
        UINT32_C( 724322071), UINT32_C(3958748460), UINT32_C( 134501197), UINT32_C(1926811457), UINT32_C(1595555462), UINT32_C(4199531135), UINT32_C( 858228528), UINT32_C( 549301769) },
      { SIMDE_FLOAT32_C(2730530304.00), SIMDE_FLOAT32_C(3398034688.00), SIMDE_FLOAT32_C(425564096.00), SIMDE_FLOAT32_C(3502960384.00),
        SIMDE_FLOAT32_C(2825238272.00), SIMDE_FLOAT32_C(4037558784.00), SIMDE_FLOAT32_C(758607488.00), SIMDE_FLOAT32_C(2324136448.00),
        SIMDE_FLOAT32_C(724322048.00), SIMDE_FLOAT32_C(3958748416.00), SIMDE_FLOAT32_C(134501200.00), SIMDE_FLOAT32_C(1926811520.00),
        SIMDE_FLOAT32_C(1595555456.00), SIMDE_FLOAT32_C(4199531008.00), SIMDE_FLOAT32_C(858228544.00), SIMDE_FLOAT32_C(549301760.00) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_epi32(test_vec[i].a);
    simde__m512 r = simde_mm512_cvtepu32_ps(a);
    simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512i a = simde_test_x86_random_u32x16();
    simde__m512 r = simde_mm512_cvtepu32_ps(a);

    simde_test_x86_write_u32x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f32x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_cvtph_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint16_t a[16];
    const simde_float32 r[16];
  } test_vec[] = {
    #if !defined(SIMDE_FAST_MATH)
    { { UINT16_C(32632), UINT16_C(36683), UINT16_C(18546), UINT16_C(51187), UINT16_C(33803), UINT16_C(35143), UINT16_C(30623), UINT16_C(24534),
        UINT16_C(28431), UINT16_C(40447), UINT16_C(62650), UINT16_C(16359), UINT16_C(56775), UINT16_C(44943), UINT16_C(35557), UINT16_C(23914) },
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(    -0.00), SIMDE_FLOAT32_C(     8.89), SIMDE_FLOAT32_C(    -7.95),
        SIMDE_FLOAT32_C(    -0.00), SIMDE_FLOAT32_C(    -0.00), SIMDE_FLOAT32_C( 31216.00), SIMDE_FLOAT32_C(   501.50),
        SIMDE_FLOAT32_C(  7228.00), SIMDE_FLOAT32_C(    -0.01), SIMDE_FLOAT32_C(-19360.00), SIMDE_FLOAT32_C(     1.98),
        SIMDE_FLOAT32_C(  -369.75), SIMDE_FLOAT32_C(    -0.12), SIMDE_FLOAT32_C(    -0.00), SIMDE_FLOAT32_C(   346.50) } },
    { { UINT16_C(41196), UINT16_C(59759), UINT16_C(45695), UINT16_C(58354), UINT16_C(33596), UINT16_C(15846), UINT16_C(18667), UINT16_C(49998),
        UINT16_C(64681), UINT16_C(65108), UINT16_C( 9617), UINT16_C(  795), UINT16_C(59525), UINT16_C(28506), UINT16_C( 3614), UINT16_C( 2659) },
      { SIMDE_FLOAT32_C(    -0.01), SIMDE_FLOAT32_C( -2782.00), SIMDE_FLOAT32_C(    -0.20), SIMDE_FLOAT32_C( -1017.00),
        SIMDE_FLOAT32_C(    -0.00), SIMDE_FLOAT32_C(     1.47), SIMDE_FLOAT32_C(     9.84), SIMDE_FLOAT32_C(    -3.65),
                   SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(     0.02), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C( -2314.00), SIMDE_FLOAT32_C(  7528.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    #endif
    { { UINT16_C(20084), UINT16_C(63622), UINT16_C(  506), UINT16_C(38217), UINT16_C(42669), UINT16_C(23539), UINT16_C(51678), UINT16_C(24564),
        UINT16_C( 5252), UINT16_C(47129), UINT16_C(15484), UINT16_C(26255), UINT16_C(50293), UINT16_C(34953), UINT16_C(37361), UINT16_C(25911) },
      { SIMDE_FLOAT32_C(    25.81), SIMDE_FLOAT32_C(-37056.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    -0.00),
        SIMDE_FLOAT32_C(    -0.03), SIMDE_FLOAT32_C(   254.38), SIMDE_FLOAT32_C(   -11.73), SIMDE_FLOAT32_C(   509.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    -0.51), SIMDE_FLOAT32_C(     1.12), SIMDE_FLOAT32_C(  1679.00),
        SIMDE_FLOAT32_C(    -4.46), SIMDE_FLOAT32_C(    -0.00), SIMDE_FLOAT32_C(    -0.00), SIMDE_FLOAT32_C(  1335.00) } },
    { { UINT16_C(48607), UINT16_C(55646), UINT16_C(42942), UINT16_C(27503), UINT16_C(25165), UINT16_C(11462), UINT16_C(47915), UINT16_C(44939),
        UINT16_C(42191), UINT16_C(19303), UINT16_C(63456), UINT16_C(21937), UINT16_C(15035), UINT16_C(44253), UINT16_C( 5579), UINT16_C(43538) },
      { SIMDE_FLOAT32_C(    -1.47), SIMDE_FLOAT32_C(  -171.75), SIMDE_FLOAT32_C(    -0.03), SIMDE_FLOAT32_C(  3806.00),
        SIMDE_FLOAT32_C(   806.50), SIMDE_FLOAT32_C(     0.07), SIMDE_FLOAT32_C(    -0.90), SIMDE_FLOAT32_C(    -0.12),
        SIMDE_FLOAT32_C(    -0.02), SIMDE_FLOAT32_C(    14.80), SIMDE_FLOAT32_C(-32256.00), SIMDE_FLOAT32_C(    91.06),
        SIMDE_FLOAT32_C(     0.84), SIMDE_FLOAT32_C(    -0.08), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    -0.05) } },
    { { UINT16_C(28882), UINT16_C(37252), UINT16_C(62231), UINT16_C(25852), UINT16_C(50005), UINT16_C(32912), UINT16_C( 7038), UINT16_C(19760),
        UINT16_C(38847), UINT16_C(41113), UINT16_C(19086), UINT16_C(18933), UINT16_C(54149), UINT16_C(20726), UINT16_C( 2280), UINT16_C(47867) },
      { SIMDE_FLOAT32_C(  9872.00), SIMDE_FLOAT32_C(    -0.00), SIMDE_FLOAT32_C(-14520.00), SIMDE_FLOAT32_C(  1276.00),
        SIMDE_FLOAT32_C(    -3.67), SIMDE_FLOAT32_C(    -0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    20.75),
        SIMDE_FLOAT32_C(    -0.00), SIMDE_FLOAT32_C(    -0.01), SIMDE_FLOAT32_C(    13.11), SIMDE_FLOAT32_C(    11.91),
        SIMDE_FLOAT32_C(   -60.16), SIMDE_FLOAT32_C(    39.69), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    -0.87) } },
    { { UINT16_C(46345), UINT16_C(31724), UINT16_C(57341), UINT16_C( 2114), UINT16_C(35427), UINT16_C(  913), UINT16_C(26625), UINT16_C( 4194),
        UINT16_C(25047), UINT16_C(37294), UINT16_C(38229), UINT16_C( 7632), UINT16_C(24690), UINT16_C(22476), UINT16_C(14058), UINT16_C(62644) },
      { SIMDE_FLOAT32_C(    -0.31), SIMDE_FLOAT32_C( 64896.00), SIMDE_FLOAT32_C(  -511.25), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(    -0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  2050.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(   747.50), SIMDE_FLOAT32_C(    -0.00), SIMDE_FLOAT32_C(    -0.00), SIMDE_FLOAT32_C(     0.01),
        SIMDE_FLOAT32_C(   569.00), SIMDE_FLOAT32_C(   124.75), SIMDE_FLOAT32_C(     0.43), SIMDE_FLOAT32_C(-19264.00) } },
    { { UINT16_C(54190), UINT16_C(11764), UINT16_C(59013), UINT16_C(49424), UINT16_C(63081), UINT16_C(22014), UINT16_C(19518), UINT16_C(59160),
        UINT16_C(27720), UINT16_C(55782), UINT16_C(  401), UINT16_C( 5852), UINT16_C(14057), UINT16_C( 2182), UINT16_C(59716), UINT16_C(61970) },
      { SIMDE_FLOAT32_C(   -61.44), SIMDE_FLOAT32_C(     0.09), SIMDE_FLOAT32_C( -1669.00), SIMDE_FLOAT32_C(    -2.53),
        SIMDE_FLOAT32_C(-26256.00), SIMDE_FLOAT32_C(    95.88), SIMDE_FLOAT32_C(    16.97), SIMDE_FLOAT32_C( -1816.00),
        SIMDE_FLOAT32_C(  4384.00), SIMDE_FLOAT32_C(  -188.75), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.43), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C( -2696.00), SIMDE_FLOAT32_C(-12432.00) } },
    { { UINT16_C( 1724), UINT16_C(16672), UINT16_C(12524), UINT16_C(22018), UINT16_C(  295), UINT16_C(26027), UINT16_C(49997), UINT16_C(38477),
        UINT16_C(13103), UINT16_C(49519), UINT16_C(19508), UINT16_C( 7895), UINT16_C(23938), UINT16_C(50982), UINT16_C(14407), UINT16_C(  953) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     2.56), SIMDE_FLOAT32_C(     0.15), SIMDE_FLOAT32_C(    96.12),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  1451.00), SIMDE_FLOAT32_C(    -3.65), SIMDE_FLOAT32_C(    -0.00),
        SIMDE_FLOAT32_C(     0.22), SIMDE_FLOAT32_C(    -2.72), SIMDE_FLOAT32_C(    16.81), SIMDE_FLOAT32_C(     0.01),
        SIMDE_FLOAT32_C(   352.50), SIMDE_FLOAT32_C(    -7.15), SIMDE_FLOAT32_C(     0.53), SIMDE_FLOAT32_C(     0.00) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i a = simde_mm256_loadu_epi32(test_vec[i].a);
    simde__m512 r = simde_mm512_cvtph_ps(a);
    simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256i a = simde_test_x86_random_u16x16();
    simde__m512 r = simde_mm512_cvtph_ps(a);

    simde_test_x86_write_u16x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f32x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cvtepi64_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_cvtepi64_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_maskz_cvtepi64_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_cvtepi8_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_cvtepi16_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_cvtepi16_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_maskz_cvtepi16_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_cvtepi32_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_cvtepi64_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_cvtepu32_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_cvtph_ps)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/avx512/test-avx512-footer.h>
