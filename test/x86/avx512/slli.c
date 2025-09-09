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
 *   2020      Christopher Moore <moore@free.fr>
 *   2025      Michael R. Crusoe <crusoe@debian.org>
 */

#define SIMDE_TEST_X86_AVX512_INSN slli

#include <test/x86/avx512/test-avx512.h>
#include <simde/x86/avx512/set.h>
#include <simde/x86/avx512/slli.h>

static int
test_simde_mm_mask_slli_epi16(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  const struct {
    const int16_t src[8];
    const simde__mmask8 k;
    const int16_t a[8];
    const int16_t r[8];
  } test_vec[] = {
    { { -INT16_C( 14760),  INT16_C( 15655),  INT16_C( 12796),  INT16_C( 20828),  INT16_C(  1442),  INT16_C( 12808),  INT16_C( 32601),  INT16_C( 18851) },
      UINT8_C(147),
      { -INT16_C( 11418), -INT16_C( 25089),  INT16_C(  5944), -INT16_C( 25962),  INT16_C( 28043), -INT16_C(  5239), -INT16_C(   926),  INT16_C( 10307) },
      { -INT16_C( 19712), -INT16_C(   128),  INT16_C( 12796),  INT16_C( 20828), -INT16_C( 14976),  INT16_C( 12808),  INT16_C( 32601),  INT16_C(  8576) } },
    { { -INT16_C( 32733),  INT16_C( 21796),  INT16_C( 30428), -INT16_C(  7689),  INT16_C( 10622), -INT16_C(   710), -INT16_C( 31796),  INT16_C( 13200) },
      UINT8_C( 86),
      { -INT16_C( 12145), -INT16_C( 22897),  INT16_C( 10598), -INT16_C( 11471),  INT16_C(  7347), -INT16_C( 20683),  INT16_C( 24159), -INT16_C(  8237) },
      { -INT16_C( 32733),  INT16_C( 18304), -INT16_C( 19712), -INT16_C(  7689),  INT16_C( 22912), -INT16_C(   710),  INT16_C( 12160),  INT16_C( 13200) } },
    { {  INT16_C( 10370), -INT16_C(  1860), -INT16_C( 25313),  INT16_C( 18550),  INT16_C( 29656),  INT16_C( 23316),  INT16_C( 18179), -INT16_C( 27982) },
      UINT8_C( 23),
      {  INT16_C( 14401),  INT16_C( 27262),  INT16_C( 20841), -INT16_C( 31459), -INT16_C( 12921), -INT16_C(  6684), -INT16_C( 15200), -INT16_C( 14233) },
      {  INT16_C(  8320),  INT16_C( 16128), -INT16_C( 19328),  INT16_C( 18550), -INT16_C( 15488),  INT16_C( 23316),  INT16_C( 18179), -INT16_C( 27982) } },
    { {  INT16_C( 24704),  INT16_C(  7655),  INT16_C( 12246),  INT16_C( 19189),  INT16_C( 20803), -INT16_C( 29875), -INT16_C(  8189),  INT16_C( 17570) },
      UINT8_C( 24),
      { -INT16_C( 20960),  INT16_C( 29314),  INT16_C(  1996), -INT16_C( 26119), -INT16_C(  8468), -INT16_C( 20423),  INT16_C(   325), -INT16_C( 23248) },
      {  INT16_C( 24704),  INT16_C(  7655),  INT16_C( 12246), -INT16_C(   896),  INT16_C( 30208), -INT16_C( 29875), -INT16_C(  8189),  INT16_C( 17570) } },
    { {  INT16_C( 19944),  INT16_C(  6012), -INT16_C( 14781), -INT16_C( 27558), -INT16_C(  6893), -INT16_C(  3177), -INT16_C(  9336), -INT16_C( 22516) },
      UINT8_C(137),
      {  INT16_C(  6798), -INT16_C( 27307), -INT16_C(  4589), -INT16_C(  3711),  INT16_C( 12583),  INT16_C( 10295), -INT16_C(  9119), -INT16_C( 20720) },
      {  INT16_C( 18176),  INT16_C(  6012), -INT16_C( 14781), -INT16_C( 16256), -INT16_C(  6893), -INT16_C(  3177), -INT16_C(  9336), -INT16_C( 30720) } },
    { {  INT16_C( 10072),  INT16_C(  7922), -INT16_C( 31102),  INT16_C( 26418),  INT16_C(  9501), -INT16_C(  1809), -INT16_C( 26575), -INT16_C( 16511) },
      UINT8_C(178),
      {  INT16_C( 21975), -INT16_C( 14906), -INT16_C( 18474),  INT16_C(  2285),  INT16_C(  5614), -INT16_C( 13463),  INT16_C(  6182),  INT16_C( 19747) },
      {  INT16_C( 10072), -INT16_C(  7424), -INT16_C( 31102),  INT16_C( 26418), -INT16_C(  2304), -INT16_C( 19328), -INT16_C( 26575), -INT16_C( 28288) } },
    { {  INT16_C( 16906), -INT16_C( 28465),  INT16_C( 14196), -INT16_C( 26195), -INT16_C( 23258), -INT16_C( 16693), -INT16_C( 30169), -INT16_C(   399) },
      UINT8_C(223),
      { -INT16_C( 15561), -INT16_C(  4426), -INT16_C( 16720), -INT16_C( 14627), -INT16_C( 22489),  INT16_C( 16620),  INT16_C( 14795),  INT16_C(  3402) },
      { -INT16_C( 25728),  INT16_C( 23296),  INT16_C( 22528),  INT16_C( 28288),  INT16_C(  4992), -INT16_C( 16693), -INT16_C(  6784), -INT16_C( 23296) } },
    { { -INT16_C(  9463),  INT16_C( 16513),  INT16_C(  7048),  INT16_C( 11878),  INT16_C(  9702),  INT16_C( 28757),  INT16_C( 21398), -INT16_C( 12976) },
      UINT8_C( 22),
      { -INT16_C( 17658), -INT16_C( 15161), -INT16_C( 29288),  INT16_C( 16619),  INT16_C( 11129), -INT16_C( 19956),  INT16_C(  6518),  INT16_C( 20923) },
      { -INT16_C(  9463),  INT16_C( 25472), -INT16_C( 13312),  INT16_C( 11878), -INT16_C( 17280),  INT16_C( 28757),  INT16_C( 21398), -INT16_C( 12976) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i src = simde_mm_loadu_epi16(test_vec[i].src);
    simde__m128i a = simde_mm_loadu_epi16(test_vec[i].a);
    simde__m128i r = simde_mm_mask_slli_epi16(src, test_vec[i].k, a, 7);
    simde_test_x86_assert_equal_i16x8(r, simde_mm_loadu_epi16(test_vec[i].r));
  }
  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i src = simde_test_x86_random_i16x8();
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128i a = simde_test_x86_random_i16x8();
    simde__m128i r = simde_mm_mask_slli_epi16(src, k, a, 7);

    simde_test_x86_write_i16x8(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_maskz_slli_epi16(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  const struct {
    const simde__mmask8 k;
    const int16_t a[8];
    const int16_t r[8];
  } test_vec[] = {
    { UINT8_C(155),
      { -INT16_C(  9733),  INT16_C( 25270), -INT16_C( 25593),  INT16_C( 23687),  INT16_C(  7436),  INT16_C( 23727), -INT16_C( 14614), -INT16_C( 23198) },
      { -INT16_C(   640),  INT16_C( 23296),  INT16_C(     0),  INT16_C( 17280), -INT16_C( 31232),  INT16_C(     0),  INT16_C(     0), -INT16_C( 20224) } },
    { UINT8_C(141),
      {  INT16_C( 15910),  INT16_C(  4634), -INT16_C( 27778), -INT16_C( 30147), -INT16_C( 19643),  INT16_C(   420),  INT16_C( 16132), -INT16_C(  8452) },
      {  INT16_C(  4864),  INT16_C(     0), -INT16_C( 16640),  INT16_C(  7808),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C( 32256) } },
    { UINT8_C(245),
      { -INT16_C(  6818), -INT16_C(  6767), -INT16_C( 25278), -INT16_C(  3838), -INT16_C(  4870),  INT16_C( 23735),  INT16_C( 17554), -INT16_C( 12157) },
      { -INT16_C( 20736),  INT16_C(     0), -INT16_C( 24320),  INT16_C(     0),  INT16_C( 32000),  INT16_C( 23424),  INT16_C( 18688),  INT16_C( 16768) } },
    { UINT8_C( 94),
      {  INT16_C( 20117), -INT16_C( 11535),  INT16_C( 14297),  INT16_C( 32134), -INT16_C( 30152),  INT16_C( 13500), -INT16_C( 20120),  INT16_C( 20115) },
      {  INT16_C(     0),  INT16_C( 30848), -INT16_C(  4992), -INT16_C( 15616),  INT16_C(  7168),  INT16_C(     0), -INT16_C( 19456),  INT16_C(     0) } },
    { UINT8_C( 66),
      { -INT16_C( 28552),  INT16_C( 31711), -INT16_C(  9855),  INT16_C( 14695), -INT16_C(  1738), -INT16_C( 18051), -INT16_C(  9015),  INT16_C(  6222) },
      {  INT16_C(     0), -INT16_C(  4224),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C( 25728),  INT16_C(     0) } },
    { UINT8_C(205),
      { -INT16_C(  3808), -INT16_C( 23036),  INT16_C( 15470),  INT16_C( 10801), -INT16_C( 26255),  INT16_C(  1243),  INT16_C(  7655),  INT16_C( 30588) },
      { -INT16_C( 28672),  INT16_C(     0),  INT16_C( 14080),  INT16_C(  6272),  INT16_C(     0),  INT16_C(     0), -INT16_C(  3200), -INT16_C( 16896) } },
    { UINT8_C(252),
      { -INT16_C(  1545),  INT16_C( 24534),  INT16_C(  3122), -INT16_C( 20648),  INT16_C(  8901),  INT16_C(  5003),  INT16_C( 22842),  INT16_C( 11059) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(  6400), -INT16_C( 21504),  INT16_C( 25216), -INT16_C( 14976), -INT16_C( 25344), -INT16_C( 26240) } },
    { UINT8_C( 93),
      { -INT16_C( 26150),  INT16_C(  2970),  INT16_C(  3011), -INT16_C( 24924), -INT16_C( 29681), -INT16_C( 29765), -INT16_C( 18685), -INT16_C(   893) },
      { -INT16_C(  4864),  INT16_C(     0), -INT16_C(  7808),  INT16_C( 20992),  INT16_C(  1920),  INT16_C(     0), -INT16_C( 32384),  INT16_C(     0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi16(test_vec[i].a);
    simde__m128i r = simde_mm_maskz_slli_epi16(test_vec[i].k, a, 7);
    simde_test_x86_assert_equal_i16x8(r, simde_mm_loadu_epi16(test_vec[i].r));
  }
  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask16 k = simde_test_x86_random_mmask8();
    simde__m128i a = simde_test_x86_random_i16x8();
    simde__m128i r = simde_mm_maskz_slli_epi16(k, a, 7);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i16x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_mask_slli_epi16(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  const struct {
    const int16_t src[16];
    const simde__mmask16 k;
    const int16_t a[16];
    const int16_t r[16];
  } test_vec[] = {
    { { -INT16_C(  7539), -INT16_C( 26322), -INT16_C(  8646),  INT16_C( 23646),  INT16_C( 29033), -INT16_C( 15722), -INT16_C( 15963),  INT16_C( 32544),
        -INT16_C( 17830),  INT16_C(  7562),  INT16_C( 11973), -INT16_C( 11077),  INT16_C( 30394), -INT16_C( 16801), -INT16_C(  7634), -INT16_C( 17478) },
      UINT16_C(59844),
      { -INT16_C(   171), -INT16_C( 19513),  INT16_C( 12379), -INT16_C(  3547), -INT16_C( 13581),  INT16_C(  5043),  INT16_C(  3657), -INT16_C( 11315),
        -INT16_C( 28117), -INT16_C(  6399), -INT16_C( 17306), -INT16_C( 15011), -INT16_C( 29830),  INT16_C( 13480),  INT16_C( 27719), -INT16_C( 25571) },
      { -INT16_C(  7539), -INT16_C( 26322),  INT16_C( 11648),  INT16_C( 23646),  INT16_C( 29033), -INT16_C( 15722),  INT16_C(  9344), -INT16_C(  6528),
         INT16_C(  5504),  INT16_C(  7562),  INT16_C( 11973), -INT16_C( 20864),  INT16_C( 30394),  INT16_C( 21504),  INT16_C(  9088),  INT16_C(  3712) } },
    { { -INT16_C(  7061), -INT16_C( 14513),  INT16_C( 29717),  INT16_C(  2233),  INT16_C( 27710), -INT16_C( 30949), -INT16_C(  6022), -INT16_C( 22950),
         INT16_C( 23674), -INT16_C(  8051), -INT16_C(  5608), -INT16_C( 27995),  INT16_C( 19830), -INT16_C( 16954), -INT16_C(  6982),  INT16_C(  9561) },
      UINT16_C(43208),
      { -INT16_C(  8724), -INT16_C( 23267),  INT16_C( 23525),  INT16_C(    18), -INT16_C( 29469),  INT16_C( 15848),  INT16_C( 25138), -INT16_C( 16487),
        -INT16_C( 20158), -INT16_C(  5974),  INT16_C(  8259),  INT16_C(  2613), -INT16_C(  4131),  INT16_C( 14062), -INT16_C( 18923),  INT16_C(   478) },
      { -INT16_C(  7061), -INT16_C( 14513),  INT16_C( 29717),  INT16_C(  2304),  INT16_C( 27710), -INT16_C( 30949),  INT16_C(  6400), -INT16_C( 13184),
         INT16_C( 23674), -INT16_C(  8051), -INT16_C(  5608),  INT16_C(  6784),  INT16_C( 19830),  INT16_C( 30464), -INT16_C(  6982), -INT16_C(  4352) } },
    { { -INT16_C(  1132),  INT16_C( 31143), -INT16_C( 18089),  INT16_C( 14970),  INT16_C( 25157),  INT16_C( 30839),  INT16_C(  4549),  INT16_C(  1847),
        -INT16_C(  7742),  INT16_C(  1775),  INT16_C(  9473), -INT16_C(  8688), -INT16_C(   492),  INT16_C( 10516), -INT16_C(  3148),  INT16_C( 18475) },
      UINT16_C(53998),
      {  INT16_C( 17858),  INT16_C( 15499), -INT16_C( 12161), -INT16_C(  2146),  INT16_C( 25416), -INT16_C( 32760), -INT16_C( 13717),  INT16_C( 23137),
         INT16_C( 25552), -INT16_C(  8065), -INT16_C( 27583),  INT16_C( 22238), -INT16_C( 27715), -INT16_C(  6071),  INT16_C( 14299), -INT16_C( 25158) },
      { -INT16_C(  1132),  INT16_C( 17792),  INT16_C( 16256), -INT16_C( 12544),  INT16_C( 25157),  INT16_C(  1024),  INT16_C( 13696),  INT16_C( 12416),
        -INT16_C(  7742),  INT16_C( 16256),  INT16_C(  9473), -INT16_C(  8688), -INT16_C(  8576),  INT16_C( 10516), -INT16_C(  4736), -INT16_C(  8960) } },
    { {  INT16_C( 17789), -INT16_C(   807),  INT16_C( 30742),  INT16_C( 24307), -INT16_C(  1061),  INT16_C( 18142),  INT16_C( 16582), -INT16_C( 26975),
         INT16_C(  8355), -INT16_C(  7049),  INT16_C( 21940),  INT16_C( 29242), -INT16_C( 31768), -INT16_C( 15270),  INT16_C(  5563),  INT16_C( 14433) },
      UINT16_C(15194),
      {  INT16_C( 28724),  INT16_C( 10419), -INT16_C( 28977), -INT16_C( 21213), -INT16_C(  5675),  INT16_C( 30445), -INT16_C( 28544), -INT16_C(  2154),
         INT16_C( 19317), -INT16_C( 20660),  INT16_C( 13757),  INT16_C(  5939), -INT16_C(  4359),  INT16_C( 23084), -INT16_C( 30938),  INT16_C( 23189) },
      {  INT16_C( 17789),  INT16_C( 22912),  INT16_C( 30742), -INT16_C( 28288), -INT16_C(  5504),  INT16_C( 18142),  INT16_C( 16384), -INT16_C( 26975),
        -INT16_C( 17792), -INT16_C( 23040),  INT16_C( 21940), -INT16_C( 26240),  INT16_C( 31872),  INT16_C(  5632),  INT16_C(  5563),  INT16_C( 14433) } },
    { {  INT16_C( 18679), -INT16_C( 14718), -INT16_C( 22825), -INT16_C( 21388),  INT16_C( 24975),  INT16_C(  3874), -INT16_C( 18190),  INT16_C( 26374),
         INT16_C( 21251), -INT16_C( 16362),  INT16_C( 18824), -INT16_C( 32296),  INT16_C(  1079),  INT16_C( 24027),  INT16_C( 29067), -INT16_C( 31816) },
      UINT16_C(15033),
      { -INT16_C( 28599), -INT16_C( 16928),  INT16_C( 28732),  INT16_C( 24095),  INT16_C(  4479), -INT16_C( 31209),  INT16_C(  6776), -INT16_C( 28967),
         INT16_C( 25051), -INT16_C( 19496),  INT16_C(  4066), -INT16_C( 16969),  INT16_C( 17261),  INT16_C(  9518), -INT16_C(  5946),  INT16_C(  3935) },
      {  INT16_C(  9344), -INT16_C( 14718), -INT16_C( 22825),  INT16_C(  3968), -INT16_C( 16512),  INT16_C(  2944), -INT16_C( 18190),  INT16_C( 27776),
         INT16_C( 21251), -INT16_C(  5120),  INT16_C( 18824), -INT16_C(  9344), -INT16_C( 18816), -INT16_C( 26880),  INT16_C( 29067), -INT16_C( 31816) } },
    { {  INT16_C( 16504), -INT16_C( 18995), -INT16_C(  4944),  INT16_C( 12051),  INT16_C( 11005),  INT16_C( 30133), -INT16_C( 29115),  INT16_C(  8195),
        -INT16_C(  9233), -INT16_C( 11821), -INT16_C( 29973),  INT16_C( 22671), -INT16_C( 16947), -INT16_C( 27779), -INT16_C(  9051),  INT16_C(  7843) },
      UINT16_C(28700),
      { -INT16_C( 13101), -INT16_C(  6564),  INT16_C( 23036), -INT16_C( 20207),  INT16_C( 22222), -INT16_C( 11968),  INT16_C( 12150),  INT16_C( 18861),
        -INT16_C( 26623), -INT16_C( 28461), -INT16_C( 24080),  INT16_C( 27981), -INT16_C(  3276), -INT16_C( 10423),  INT16_C( 26129), -INT16_C(  7097) },
      {  INT16_C( 16504), -INT16_C( 18995), -INT16_C(   512), -INT16_C( 30592),  INT16_C( 26368),  INT16_C( 30133), -INT16_C( 29115),  INT16_C(  8195),
        -INT16_C(  9233), -INT16_C( 11821), -INT16_C( 29973),  INT16_C( 22671), -INT16_C( 26112), -INT16_C( 23424),  INT16_C(  2176),  INT16_C(  7843) } },
    { { -INT16_C( 23758),  INT16_C( 11978), -INT16_C(  9220), -INT16_C( 13600),  INT16_C(  8241), -INT16_C( 22628),  INT16_C( 18767),  INT16_C( 20720),
        -INT16_C( 15135), -INT16_C( 11808),  INT16_C( 11877), -INT16_C( 26306), -INT16_C( 30943),  INT16_C( 12913), -INT16_C( 18195),  INT16_C(  8214) },
      UINT16_C(57436),
      {  INT16_C( 22606),  INT16_C( 11964), -INT16_C(  4829), -INT16_C( 16562), -INT16_C( 24939), -INT16_C( 31480), -INT16_C(  5650), -INT16_C( 12471),
        -INT16_C( 20806), -INT16_C(  1795),  INT16_C(  7752), -INT16_C( 18049),  INT16_C( 27984),  INT16_C( 26225), -INT16_C( 12915), -INT16_C(  9402) },
      { -INT16_C( 23758),  INT16_C( 11978), -INT16_C( 28288), -INT16_C( 22784),  INT16_C( 19072), -INT16_C( 22628), -INT16_C(  2304),  INT16_C( 20720),
        -INT16_C( 15135), -INT16_C( 11808),  INT16_C( 11877), -INT16_C( 26306), -INT16_C( 30943),  INT16_C( 14464), -INT16_C( 14720), -INT16_C( 23808) } },
    { {  INT16_C(   550),  INT16_C( 18698),  INT16_C( 22768), -INT16_C( 31480),  INT16_C(  4342), -INT16_C(  6902),  INT16_C( 21753), -INT16_C( 19532),
        -INT16_C( 20222),  INT16_C( 19115),  INT16_C( 10959),  INT16_C(  7939),  INT16_C( 30103),  INT16_C(  9349), -INT16_C( 13502),  INT16_C( 26624) },
      UINT16_C( 2766),
      { -INT16_C( 16719), -INT16_C( 18078),  INT16_C( 22851),  INT16_C( 19913), -INT16_C( 15810), -INT16_C(  3423), -INT16_C( 23435),  INT16_C(  8355),
         INT16_C( 29422), -INT16_C(  3509), -INT16_C(  7535),  INT16_C(  5735), -INT16_C( 22265),  INT16_C(  2017), -INT16_C( 20718), -INT16_C( 15599) },
      {  INT16_C(   550), -INT16_C( 20224), -INT16_C( 24192), -INT16_C(  7040),  INT16_C(  4342), -INT16_C(  6902),  INT16_C( 14976),  INT16_C( 20864),
        -INT16_C( 20222),  INT16_C(  9600),  INT16_C( 10959),  INT16_C( 13184),  INT16_C( 30103),  INT16_C(  9349), -INT16_C( 13502),  INT16_C( 26624) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i src = simde_mm256_loadu_epi16(test_vec[i].src);
    simde__m256i a = simde_mm256_loadu_epi16(test_vec[i].a);
    simde__m256i r = simde_mm256_mask_slli_epi16(src, test_vec[i].k, a, 7);
    simde_test_x86_assert_equal_i16x16(r, simde_mm256_loadu_epi16(test_vec[i].r));
  }
  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256i src = simde_test_x86_random_i16x16();
    simde__mmask16 k = simde_test_x86_random_mmask16();
    simde__m256i a = simde_test_x86_random_i16x16();
    simde__m256i r = simde_mm256_mask_slli_epi16(src, k, a, 7);

    simde_test_x86_write_i16x16(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask16(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_maskz_slli_epi16(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  const struct {
    const simde__mmask16 k;
    const int16_t a[16];
    const int16_t r[16];
  } test_vec[] = {
    { UINT16_C(29549),
      { -INT16_C( 20355),  INT16_C( 18124),  INT16_C(  2814), -INT16_C( 24823),  INT16_C( 32508), -INT16_C( 24765),  INT16_C( 12959), -INT16_C(  5615),
        -INT16_C( 24028), -INT16_C( 29748), -INT16_C( 11336), -INT16_C( 26060),  INT16_C( 18138), -INT16_C(  5303), -INT16_C( 18678), -INT16_C( 30881) },
      {  INT16_C( 16000),  INT16_C(     0),  INT16_C( 32512), -INT16_C( 31616),  INT16_C(     0), -INT16_C( 24192),  INT16_C( 20352),  INT16_C(     0),
         INT16_C(  4608), -INT16_C(  6656),  INT16_C(     0),  INT16_C(     0),  INT16_C( 27904), -INT16_C( 23424), -INT16_C( 31488),  INT16_C(     0) } },
    { UINT16_C(11111),
      {  INT16_C( 26061), -INT16_C( 10698),  INT16_C( 12805),  INT16_C( 18517), -INT16_C(  2862), -INT16_C(  7302), -INT16_C( 24866), -INT16_C( 21882),
         INT16_C( 15913),  INT16_C( 24190),  INT16_C( 22744),  INT16_C(  8868), -INT16_C( 20924), -INT16_C( 23591),  INT16_C( 16437),  INT16_C(   974) },
      { -INT16_C(  6528),  INT16_C(  6912),  INT16_C(   640),  INT16_C(     0),  INT16_C(     0), -INT16_C( 17152),  INT16_C( 28416),  INT16_C(     0),
         INT16_C(  5248),  INT16_C( 16128),  INT16_C(     0),  INT16_C( 20992),  INT16_C(     0), -INT16_C(  4992),  INT16_C(     0),  INT16_C(     0) } },
    { UINT16_C( 1190),
      { -INT16_C( 21543),  INT16_C( 11831),  INT16_C(  2547),  INT16_C( 28194),  INT16_C(   236),  INT16_C( 29196),  INT16_C( 13995),  INT16_C( 10673),
        -INT16_C( 30316),  INT16_C( 14465), -INT16_C( 14933), -INT16_C( 31513),  INT16_C(  7272),  INT16_C( 14277),  INT16_C( 27423), -INT16_C(  1733) },
      {  INT16_C(     0),  INT16_C(  7040), -INT16_C(  1664),  INT16_C(     0),  INT16_C(     0),  INT16_C(  1536),  INT16_C(     0), -INT16_C( 10112),
         INT16_C(     0),  INT16_C(     0), -INT16_C( 10880),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { UINT16_C(29206),
      {  INT16_C(  2343),  INT16_C( 19067),  INT16_C( 26743), -INT16_C( 31670), -INT16_C(  2598), -INT16_C( 29766),  INT16_C( 19998), -INT16_C( 24555),
        -INT16_C( 16250),  INT16_C( 28005), -INT16_C( 12731),  INT16_C(  2698), -INT16_C( 22267),  INT16_C( 16501), -INT16_C( 29790), -INT16_C( 13645) },
      {  INT16_C(     0),  INT16_C( 15744),  INT16_C( 15232),  INT16_C(     0), -INT16_C(  4864),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0), -INT16_C( 19840),  INT16_C(     0),  INT16_C(     0), -INT16_C( 32128),  INT16_C( 14976), -INT16_C( 12032),  INT16_C(     0) } },
    { UINT16_C(11924),
      {  INT16_C(  3092),  INT16_C( 24214),  INT16_C( 29072),  INT16_C( 19028),  INT16_C( 29436),  INT16_C(  4504),  INT16_C(  7698),  INT16_C( 30930),
         INT16_C(  6028),  INT16_C(  5702),  INT16_C( 19233), -INT16_C( 26945),  INT16_C( 25227),  INT16_C( 15905), -INT16_C( 19156),  INT16_C( 16493) },
      {  INT16_C(     0),  INT16_C(     0), -INT16_C( 14336),  INT16_C(     0),  INT16_C( 32256),  INT16_C(     0),  INT16_C(     0),  INT16_C( 26880),
         INT16_C(     0),  INT16_C(  8960), -INT16_C( 28544),  INT16_C( 24448),  INT16_C(     0),  INT16_C(  4224),  INT16_C(     0),  INT16_C(     0) } },
    { UINT16_C(  961),
      {  INT16_C( 20894), -INT16_C(  3468),  INT16_C( 29083),  INT16_C( 13157),  INT16_C( 30594),  INT16_C( 21586), -INT16_C(  8465),  INT16_C( 13675),
        -INT16_C( 29452), -INT16_C( 19584),  INT16_C(  3106),  INT16_C( 17173),  INT16_C( 16714), -INT16_C( 18439), -INT16_C( 17791),  INT16_C(  8379) },
      { -INT16_C( 12544),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C( 30592), -INT16_C( 19072),
         INT16_C( 31232), -INT16_C( 16384),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { UINT16_C(12044),
      { -INT16_C( 22766),  INT16_C( 30624),  INT16_C(  9179),  INT16_C( 11759), -INT16_C(  8585), -INT16_C(  7413), -INT16_C(   236), -INT16_C( 27537),
        -INT16_C( 27982), -INT16_C( 14176), -INT16_C(  5163), -INT16_C( 12791), -INT16_C( 29790),  INT16_C( 23945), -INT16_C( 27221), -INT16_C( 17011) },
      {  INT16_C(     0),  INT16_C(     0), -INT16_C(  4736), -INT16_C(  2176),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C( 22784),  INT16_C( 20480), -INT16_C(  5504),  INT16_C(  1152),  INT16_C(     0), -INT16_C( 15232),  INT16_C(     0),  INT16_C(     0) } },
    { UINT16_C(11580),
      {  INT16_C(  5941),  INT16_C(  9296), -INT16_C( 14268),  INT16_C( 20226),  INT16_C(  5803),  INT16_C(  6734),  INT16_C(   427),  INT16_C( 19372),
        -INT16_C( 32055), -INT16_C( 11722), -INT16_C(  9904), -INT16_C(  9891),  INT16_C(  2102), -INT16_C( 15506), -INT16_C( 21562), -INT16_C(  1039) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(  8704), -INT16_C( 32512),  INT16_C( 21888),  INT16_C(  9984),  INT16_C(     0),  INT16_C(     0),
         INT16_C( 25728),  INT16_C(     0), -INT16_C( 22528), -INT16_C( 20864),  INT16_C(     0), -INT16_C( 18688),  INT16_C(     0),  INT16_C(     0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i a = simde_mm256_loadu_epi16(test_vec[i].a);
    simde__m256i r = simde_mm256_maskz_slli_epi16(test_vec[i].k, a, 7);
    simde_test_x86_assert_equal_i16x16(r, simde_mm256_loadu_epi16(test_vec[i].r));
  }
  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask16 k = simde_test_x86_random_mmask16();
    simde__m256i a = simde_test_x86_random_i16x16();
    simde__m256i r = simde_mm256_maskz_slli_epi16(k, a, 7);

    simde_test_x86_write_mmask16(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i16x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_slli_epi16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const int16_t a[32];
    const int16_t r0[32];
    const int16_t r3[32];
    const int16_t r7[32];
    const int16_t r13[32];
    const int16_t r24[32];
  } test_vec[] = {
    { { -INT16_C(  4513), -INT16_C( 32064), -INT16_C( 20539),  INT16_C( 16953), -INT16_C( 19443),  INT16_C(  8904),  INT16_C( 17111), -INT16_C( 18058),
         INT16_C(  9034), -INT16_C( 18739), -INT16_C( 25271),  INT16_C(  4847), -INT16_C( 27918), -INT16_C(  9400), -INT16_C(  4204), -INT16_C(  3107),
        -INT16_C( 24867), -INT16_C( 23691), -INT16_C( 20915),  INT16_C( 23269), -INT16_C( 21149),  INT16_C( 14973), -INT16_C(  3088),  INT16_C( 15091),
        -INT16_C( 16362),  INT16_C( 24561), -INT16_C(  8099),  INT16_C( 20594), -INT16_C( 17806),  INT16_C(  1579),  INT16_C(  2218), -INT16_C( 30727) },
      { -INT16_C(  4513), -INT16_C( 32064), -INT16_C( 20539),  INT16_C( 16953), -INT16_C( 19443),  INT16_C(  8904),  INT16_C( 17111), -INT16_C( 18058),
         INT16_C(  9034), -INT16_C( 18739), -INT16_C( 25271),  INT16_C(  4847), -INT16_C( 27918), -INT16_C(  9400), -INT16_C(  4204), -INT16_C(  3107),
        -INT16_C( 24867), -INT16_C( 23691), -INT16_C( 20915),  INT16_C( 23269), -INT16_C( 21149),  INT16_C( 14973), -INT16_C(  3088),  INT16_C( 15091),
        -INT16_C( 16362),  INT16_C( 24561), -INT16_C(  8099),  INT16_C( 20594), -INT16_C( 17806),  INT16_C(  1579),  INT16_C(  2218), -INT16_C( 30727) },
      {  INT16_C( 29432),  INT16_C(  5632),  INT16_C( 32296),  INT16_C(  4552), -INT16_C( 24472),  INT16_C(  5696),  INT16_C(  5816), -INT16_C( 13392),
         INT16_C(  6736), -INT16_C( 18840), -INT16_C(  5560), -INT16_C( 26760), -INT16_C( 26736), -INT16_C(  9664),  INT16_C( 31904), -INT16_C( 24856),
        -INT16_C(  2328),  INT16_C(  7080),  INT16_C( 29288), -INT16_C( 10456),  INT16_C( 27416), -INT16_C( 11288), -INT16_C( 24704), -INT16_C( 10344),
         INT16_C(   176), -INT16_C(   120),  INT16_C(   744), -INT16_C( 31856), -INT16_C( 11376),  INT16_C( 12632),  INT16_C( 17744),  INT16_C( 16328) },
      {  INT16_C( 12160),  INT16_C( 24576), -INT16_C(  7552),  INT16_C(  7296),  INT16_C(  1664),  INT16_C( 25600),  INT16_C( 27520), -INT16_C( 17664),
        -INT16_C( 23296),  INT16_C( 26240), -INT16_C( 23424),  INT16_C( 30592),  INT16_C( 30976), -INT16_C( 23552), -INT16_C( 13824), -INT16_C(  4480),
         INT16_C( 28288), -INT16_C( 17792),  INT16_C(  9856),  INT16_C( 29312), -INT16_C( 20096),  INT16_C( 16000), -INT16_C(  2048),  INT16_C( 31104),
         INT16_C(  2816), -INT16_C(  1920),  INT16_C( 11904),  INT16_C( 14592),  INT16_C( 14592),  INT16_C(  5504),  INT16_C( 21760), -INT16_C(   896) },
      { -INT16_C(  8192),  INT16_C(     0), -INT16_C( 24576),  INT16_C(  8192), -INT16_C( 24576),  INT16_C(     0), -INT16_C(  8192), -INT16_C( 16384),
         INT16_C( 16384), -INT16_C( 24576),  INT16_C(  8192), -INT16_C(  8192),  INT16_C( 16384),  INT16_C(     0),       INT16_MIN, -INT16_C( 24576),
        -INT16_C( 24576), -INT16_C( 24576), -INT16_C( 24576), -INT16_C( 24576),  INT16_C( 24576), -INT16_C( 24576),  INT16_C(     0),  INT16_C( 24576),
        -INT16_C( 16384),  INT16_C(  8192), -INT16_C( 24576),  INT16_C( 16384),  INT16_C( 16384),  INT16_C( 24576),  INT16_C( 16384),  INT16_C(  8192) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { {  INT16_C( 28582), -INT16_C(  3030),  INT16_C(  3869), -INT16_C( 32690), -INT16_C( 13379), -INT16_C( 21062), -INT16_C( 20801), -INT16_C( 10777),
        -INT16_C( 10130), -INT16_C( 13259), -INT16_C( 22600),  INT16_C( 11036),  INT16_C( 18273),  INT16_C(  2865),  INT16_C( 11087), -INT16_C(  2413),
        -INT16_C( 16998), -INT16_C( 18454),  INT16_C( 14541), -INT16_C( 30152), -INT16_C(  3580), -INT16_C( 15561),  INT16_C(  7840),  INT16_C(  3992),
        -INT16_C( 12809), -INT16_C( 20517), -INT16_C(  2188), -INT16_C( 10534),  INT16_C(  3134), -INT16_C( 29215),  INT16_C( 29751), -INT16_C( 11901) },
      {  INT16_C( 28582), -INT16_C(  3030),  INT16_C(  3869), -INT16_C( 32690), -INT16_C( 13379), -INT16_C( 21062), -INT16_C( 20801), -INT16_C( 10777),
        -INT16_C( 10130), -INT16_C( 13259), -INT16_C( 22600),  INT16_C( 11036),  INT16_C( 18273),  INT16_C(  2865),  INT16_C( 11087), -INT16_C(  2413),
        -INT16_C( 16998), -INT16_C( 18454),  INT16_C( 14541), -INT16_C( 30152), -INT16_C(  3580), -INT16_C( 15561),  INT16_C(  7840),  INT16_C(  3992),
        -INT16_C( 12809), -INT16_C( 20517), -INT16_C(  2188), -INT16_C( 10534),  INT16_C(  3134), -INT16_C( 29215),  INT16_C( 29751), -INT16_C( 11901) },
      {  INT16_C( 32048), -INT16_C( 24240),  INT16_C( 30952),  INT16_C(   624),  INT16_C( 24040),  INT16_C( 28112),  INT16_C( 30200), -INT16_C( 20680),
        -INT16_C( 15504),  INT16_C( 25000),  INT16_C( 15808),  INT16_C( 22752),  INT16_C( 15112),  INT16_C( 22920),  INT16_C( 23160), -INT16_C( 19304),
        -INT16_C(  4912), -INT16_C( 16560), -INT16_C( 14744),  INT16_C( 20928), -INT16_C( 28640),  INT16_C(  6584), -INT16_C(  2816),  INT16_C( 31936),
         INT16_C( 28600),  INT16_C( 32472), -INT16_C( 17504), -INT16_C( 18736),  INT16_C( 25072),  INT16_C( 28424), -INT16_C( 24136), -INT16_C( 29672) },
      { -INT16_C( 11520),  INT16_C(  5376), -INT16_C( 29056),  INT16_C(  9984), -INT16_C(  8576), -INT16_C(  8960),  INT16_C( 24448), -INT16_C(  3200),
         INT16_C( 14080),  INT16_C(  6784), -INT16_C(  9216), -INT16_C( 29184), -INT16_C( 20352), -INT16_C( 26496), -INT16_C( 22656),  INT16_C( 18816),
        -INT16_C( 13056), -INT16_C(  2816),  INT16_C( 26240),  INT16_C(  7168),  INT16_C(   512), -INT16_C( 25728),  INT16_C( 20480), -INT16_C( 13312),
        -INT16_C(  1152), -INT16_C(  4736), -INT16_C( 17920),  INT16_C( 27904),  INT16_C(  7936), -INT16_C(  3968),  INT16_C(  7040), -INT16_C( 16000) },
      { -INT16_C( 16384),  INT16_C( 16384), -INT16_C( 24576), -INT16_C( 16384), -INT16_C( 24576),  INT16_C( 16384), -INT16_C(  8192), -INT16_C(  8192),
        -INT16_C( 16384), -INT16_C( 24576),  INT16_C(     0),       INT16_MIN,  INT16_C(  8192),  INT16_C(  8192), -INT16_C(  8192),  INT16_C( 24576),
         INT16_C( 16384),  INT16_C( 16384), -INT16_C( 24576),  INT16_C(     0),       INT16_MIN, -INT16_C(  8192),  INT16_C(     0),  INT16_C(     0),
        -INT16_C(  8192),  INT16_C( 24576),       INT16_MIN,  INT16_C( 16384), -INT16_C( 16384),  INT16_C(  8192), -INT16_C(  8192),  INT16_C( 24576) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { {  INT16_C( 27954), -INT16_C(   120), -INT16_C( 16218), -INT16_C( 21879), -INT16_C( 16205),  INT16_C( 21357),  INT16_C(  1502), -INT16_C( 10910),
         INT16_C( 15827),  INT16_C( 18309),  INT16_C( 24372),  INT16_C( 29213), -INT16_C(   149), -INT16_C( 24064), -INT16_C( 31885), -INT16_C( 23181),
        -INT16_C(   783), -INT16_C( 26716),  INT16_C( 11708),  INT16_C( 28481), -INT16_C( 20755), -INT16_C( 13117),  INT16_C(  9651), -INT16_C( 31071),
         INT16_C(  9827), -INT16_C( 26674), -INT16_C(  5242), -INT16_C(  3830),  INT16_C(  2794),  INT16_C( 24212),  INT16_C(  1933),  INT16_C( 32259) },
      {  INT16_C( 27954), -INT16_C(   120), -INT16_C( 16218), -INT16_C( 21879), -INT16_C( 16205),  INT16_C( 21357),  INT16_C(  1502), -INT16_C( 10910),
         INT16_C( 15827),  INT16_C( 18309),  INT16_C( 24372),  INT16_C( 29213), -INT16_C(   149), -INT16_C( 24064), -INT16_C( 31885), -INT16_C( 23181),
        -INT16_C(   783), -INT16_C( 26716),  INT16_C( 11708),  INT16_C( 28481), -INT16_C( 20755), -INT16_C( 13117),  INT16_C(  9651), -INT16_C( 31071),
         INT16_C(  9827), -INT16_C( 26674), -INT16_C(  5242), -INT16_C(  3830),  INT16_C(  2794),  INT16_C( 24212),  INT16_C(  1933),  INT16_C( 32259) },
      {  INT16_C( 27024), -INT16_C(   960),  INT16_C(  1328),  INT16_C( 21576),  INT16_C(  1432), -INT16_C( 25752),  INT16_C( 12016), -INT16_C( 21744),
        -INT16_C(  4456),  INT16_C( 15400), -INT16_C(  1632), -INT16_C( 28440), -INT16_C(  1192),  INT16_C(  4096),  INT16_C(  7064),  INT16_C( 11160),
        -INT16_C(  6264), -INT16_C( 17120),  INT16_C( 28128),  INT16_C( 31240),  INT16_C( 30568),  INT16_C( 26136),  INT16_C( 11672),  INT16_C( 13576),
         INT16_C( 13080), -INT16_C( 16784),  INT16_C( 23600), -INT16_C( 30640),  INT16_C( 22352), -INT16_C(  2912),  INT16_C( 15464), -INT16_C(  4072) },
      { -INT16_C( 26368), -INT16_C( 15360),  INT16_C( 21248),  INT16_C( 17536),  INT16_C( 22912), -INT16_C( 18816), -INT16_C(  4352), -INT16_C( 20224),
        -INT16_C(  5760), -INT16_C( 15744), -INT16_C( 26112),  INT16_C(  3712), -INT16_C( 19072),  INT16_C(     0), -INT16_C( 18048), -INT16_C( 18048),
         INT16_C( 30848), -INT16_C( 11776), -INT16_C(  8704), -INT16_C( 24448),  INT16_C( 30336),  INT16_C( 24960), -INT16_C(  9856),  INT16_C( 20608),
         INT16_C( 12672), -INT16_C(  6400), -INT16_C( 15616), -INT16_C( 31488),  INT16_C( 29952),  INT16_C( 18944), -INT16_C( 14720),  INT16_C(   384) },
      {  INT16_C( 16384),  INT16_C(     0), -INT16_C( 16384),  INT16_C(  8192),  INT16_C( 24576), -INT16_C( 24576), -INT16_C( 16384),  INT16_C( 16384),
         INT16_C( 24576), -INT16_C( 24576),       INT16_MIN, -INT16_C( 24576),  INT16_C( 24576),  INT16_C(     0),  INT16_C( 24576),  INT16_C( 24576),
         INT16_C(  8192),       INT16_MIN,       INT16_MIN,  INT16_C(  8192), -INT16_C( 24576),  INT16_C( 24576),  INT16_C( 24576),  INT16_C(  8192),
         INT16_C( 24576), -INT16_C( 16384), -INT16_C( 16384),  INT16_C( 16384),  INT16_C( 16384),       INT16_MIN, -INT16_C( 24576),  INT16_C( 24576) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { { -INT16_C( 22525), -INT16_C( 16363),  INT16_C( 22229), -INT16_C( 15569), -INT16_C(  3580), -INT16_C( 18289),  INT16_C( 12312),  INT16_C( 31550),
         INT16_C(  3159), -INT16_C(  8942),  INT16_C(  7416), -INT16_C(  7474),  INT16_C( 25126), -INT16_C( 19392),  INT16_C( 17514),  INT16_C( 27954),
         INT16_C( 18668), -INT16_C( 16083),  INT16_C( 23966), -INT16_C( 23676),  INT16_C(  4943),  INT16_C( 26459), -INT16_C( 26300), -INT16_C( 25630),
        -INT16_C(  2650), -INT16_C( 24968),  INT16_C( 17937),  INT16_C( 14464), -INT16_C( 15959),  INT16_C(  5100),  INT16_C(  7685), -INT16_C(  3712) },
      { -INT16_C( 22525), -INT16_C( 16363),  INT16_C( 22229), -INT16_C( 15569), -INT16_C(  3580), -INT16_C( 18289),  INT16_C( 12312),  INT16_C( 31550),
         INT16_C(  3159), -INT16_C(  8942),  INT16_C(  7416), -INT16_C(  7474),  INT16_C( 25126), -INT16_C( 19392),  INT16_C( 17514),  INT16_C( 27954),
         INT16_C( 18668), -INT16_C( 16083),  INT16_C( 23966), -INT16_C( 23676),  INT16_C(  4943),  INT16_C( 26459), -INT16_C( 26300), -INT16_C( 25630),
        -INT16_C(  2650), -INT16_C( 24968),  INT16_C( 17937),  INT16_C( 14464), -INT16_C( 15959),  INT16_C(  5100),  INT16_C(  7685), -INT16_C(  3712) },
      {  INT16_C( 16408),  INT16_C(   168), -INT16_C( 18776),  INT16_C(  6520), -INT16_C( 28640), -INT16_C( 15240), -INT16_C( 32576), -INT16_C(  9744),
         INT16_C( 25272), -INT16_C(  6000), -INT16_C(  6208),  INT16_C(  5744),  INT16_C(  4400), -INT16_C( 24064),  INT16_C(  9040),  INT16_C( 27024),
         INT16_C( 18272),  INT16_C(  2408), -INT16_C(  4880),  INT16_C(  7200), -INT16_C( 25992),  INT16_C( 15064), -INT16_C( 13792), -INT16_C(  8432),
        -INT16_C( 21200), -INT16_C(  3136),  INT16_C( 12424), -INT16_C( 15360),  INT16_C(  3400), -INT16_C( 24736), -INT16_C(  4056), -INT16_C( 29696) },
      {  INT16_C(   384),  INT16_C(  2688),  INT16_C( 27264), -INT16_C( 26752),  INT16_C(   512),  INT16_C( 18304),  INT16_C(  3072), -INT16_C( 24832),
         INT16_C( 11136), -INT16_C( 30464),  INT16_C( 31744),  INT16_C( 26368),  INT16_C(  4864),  INT16_C(  8192),  INT16_C( 13568), -INT16_C( 26368),
         INT16_C( 30208), -INT16_C( 27008), -INT16_C( 12544), -INT16_C( 15872), -INT16_C( 22656), -INT16_C( 21120), -INT16_C( 24064), -INT16_C(  3840),
        -INT16_C( 11520),  INT16_C( 15360),  INT16_C(  2176),  INT16_C( 16384), -INT16_C( 11136), -INT16_C(  2560),  INT16_C(   640), -INT16_C( 16384) },
      {  INT16_C( 24576), -INT16_C( 24576), -INT16_C( 24576), -INT16_C(  8192),       INT16_MIN, -INT16_C(  8192),  INT16_C(     0), -INT16_C( 16384),
        -INT16_C(  8192),  INT16_C( 16384),  INT16_C(     0), -INT16_C( 16384), -INT16_C( 16384),  INT16_C(     0),  INT16_C( 16384),  INT16_C( 16384),
              INT16_MIN, -INT16_C( 24576), -INT16_C( 16384),       INT16_MIN, -INT16_C(  8192),  INT16_C( 24576),       INT16_MIN,  INT16_C( 16384),
        -INT16_C( 16384),  INT16_C(     0),  INT16_C(  8192),  INT16_C(     0),  INT16_C(  8192),       INT16_MIN, -INT16_C( 24576),  INT16_C(     0) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { { -INT16_C( 20890),  INT16_C(  1458),  INT16_C( 14091),  INT16_C( 23208),  INT16_C(   842), -INT16_C( 28990), -INT16_C( 23396),  INT16_C( 16937),
        -INT16_C( 24167), -INT16_C( 21536),  INT16_C( 25064), -INT16_C( 28189), -INT16_C( 12510),  INT16_C( 10148),  INT16_C(  9453),  INT16_C( 21528),
        -INT16_C( 13614), -INT16_C(  8871),  INT16_C(   257),  INT16_C( 19512), -INT16_C(  1532), -INT16_C( 24358),  INT16_C(  1182),  INT16_C( 14563),
        -INT16_C( 15451), -INT16_C( 29213), -INT16_C( 14812),  INT16_C( 17950), -INT16_C( 15723), -INT16_C( 32147), -INT16_C( 31257), -INT16_C( 17962) },
      { -INT16_C( 20890),  INT16_C(  1458),  INT16_C( 14091),  INT16_C( 23208),  INT16_C(   842), -INT16_C( 28990), -INT16_C( 23396),  INT16_C( 16937),
        -INT16_C( 24167), -INT16_C( 21536),  INT16_C( 25064), -INT16_C( 28189), -INT16_C( 12510),  INT16_C( 10148),  INT16_C(  9453),  INT16_C( 21528),
        -INT16_C( 13614), -INT16_C(  8871),  INT16_C(   257),  INT16_C( 19512), -INT16_C(  1532), -INT16_C( 24358),  INT16_C(  1182),  INT16_C( 14563),
        -INT16_C( 15451), -INT16_C( 29213), -INT16_C( 14812),  INT16_C( 17950), -INT16_C( 15723), -INT16_C( 32147), -INT16_C( 31257), -INT16_C( 17962) },
      {  INT16_C( 29488),  INT16_C( 11664), -INT16_C( 18344), -INT16_C( 10944),  INT16_C(  6736),  INT16_C( 30224),  INT16_C(  9440),  INT16_C(  4424),
         INT16_C(  3272),  INT16_C( 24320),  INT16_C(  3904), -INT16_C( 28904),  INT16_C( 30992),  INT16_C( 15648),  INT16_C( 10088), -INT16_C( 24384),
         INT16_C( 22160), -INT16_C(  5432),  INT16_C(  2056),  INT16_C( 25024), -INT16_C( 12256),  INT16_C(  1744),  INT16_C(  9456), -INT16_C( 14568),
         INT16_C(  7464),  INT16_C( 28440),  INT16_C( 12576),  INT16_C( 12528),  INT16_C(  5288),  INT16_C(  4968),  INT16_C( 12088), -INT16_C( 12624) },
      {  INT16_C( 13056), -INT16_C(  9984), -INT16_C( 31360),  INT16_C( 21504), -INT16_C( 23296),  INT16_C( 24832),  INT16_C( 19968),  INT16_C(  5248),
        -INT16_C( 13184), -INT16_C(  4096), -INT16_C(  3072), -INT16_C(  3712), -INT16_C( 28416), -INT16_C( 11776),  INT16_C( 30336),  INT16_C(  3072),
         INT16_C( 26880), -INT16_C( 21376), -INT16_C( 32640),  INT16_C(  7168),  INT16_C(   512),  INT16_C( 27904),  INT16_C( 20224),  INT16_C( 29056),
        -INT16_C( 11648), -INT16_C(  3712),  INT16_C(  4608),  INT16_C(  3840),  INT16_C( 19072),  INT16_C( 13952), -INT16_C(  3200), -INT16_C(  5376) },
      { -INT16_C( 16384),  INT16_C( 16384),  INT16_C( 24576),  INT16_C(     0),  INT16_C( 16384),  INT16_C( 16384),       INT16_MIN,  INT16_C(  8192),
         INT16_C(  8192),  INT16_C(     0),  INT16_C(     0),  INT16_C( 24576),  INT16_C( 16384),       INT16_MIN, -INT16_C( 24576),  INT16_C(     0),
         INT16_C( 16384),  INT16_C(  8192),  INT16_C(  8192),  INT16_C(     0),       INT16_MIN,  INT16_C( 16384), -INT16_C( 16384),  INT16_C( 24576),
        -INT16_C( 24576),  INT16_C( 24576),       INT16_MIN, -INT16_C( 16384), -INT16_C( 24576), -INT16_C( 24576), -INT16_C(  8192), -INT16_C( 16384) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { {  INT16_C( 12112),  INT16_C( 20887), -INT16_C( 12496),  INT16_C( 13469),  INT16_C( 30921),  INT16_C( 26581), -INT16_C( 18308),  INT16_C(  8607),
        -INT16_C( 32133), -INT16_C( 24401), -INT16_C( 12984), -INT16_C(  8730),  INT16_C( 21648),  INT16_C( 30560),  INT16_C( 14041),  INT16_C( 10544),
        -INT16_C( 14490), -INT16_C( 27013),  INT16_C(  6294),  INT16_C( 24523), -INT16_C( 24432),  INT16_C(  3271),  INT16_C( 26200), -INT16_C( 11474),
        -INT16_C(  8727),  INT16_C( 12659),  INT16_C( 23210),  INT16_C( 14863),  INT16_C( 28590), -INT16_C( 30799), -INT16_C(  7515),  INT16_C(  2993) },
      {  INT16_C( 12112),  INT16_C( 20887), -INT16_C( 12496),  INT16_C( 13469),  INT16_C( 30921),  INT16_C( 26581), -INT16_C( 18308),  INT16_C(  8607),
        -INT16_C( 32133), -INT16_C( 24401), -INT16_C( 12984), -INT16_C(  8730),  INT16_C( 21648),  INT16_C( 30560),  INT16_C( 14041),  INT16_C( 10544),
        -INT16_C( 14490), -INT16_C( 27013),  INT16_C(  6294),  INT16_C( 24523), -INT16_C( 24432),  INT16_C(  3271),  INT16_C( 26200), -INT16_C( 11474),
        -INT16_C(  8727),  INT16_C( 12659),  INT16_C( 23210),  INT16_C( 14863),  INT16_C( 28590), -INT16_C( 30799), -INT16_C(  7515),  INT16_C(  2993) },
      {  INT16_C( 31360), -INT16_C( 29512),  INT16_C( 31104), -INT16_C( 23320), -INT16_C( 14776),  INT16_C( 16040), -INT16_C( 15392),  INT16_C(  3320),
         INT16_C(  5080),  INT16_C(  1400),  INT16_C( 27200), -INT16_C(  4304), -INT16_C( 23424), -INT16_C( 17664), -INT16_C( 18744),  INT16_C( 18816),
         INT16_C( 15152), -INT16_C( 19496), -INT16_C( 15184), -INT16_C(   424),  INT16_C(  1152),  INT16_C( 26168),  INT16_C( 12992), -INT16_C( 26256),
        -INT16_C(  4280), -INT16_C( 29800), -INT16_C( 10928), -INT16_C( 12168),  INT16_C( 32112),  INT16_C( 15752),  INT16_C(  5416),  INT16_C( 23944) },
      { -INT16_C( 22528), -INT16_C( 13440), -INT16_C( 26624),  INT16_C( 20096),  INT16_C( 25728), -INT16_C(  5504),  INT16_C( 15872), -INT16_C( 12416),
         INT16_C( 15744),  INT16_C( 22400), -INT16_C( 23552), -INT16_C(  3328),  INT16_C( 18432), -INT16_C( 20480),  INT16_C( 27776), -INT16_C( 26624),
        -INT16_C( 19712),  INT16_C( 15744),  INT16_C( 19200), -INT16_C(  6784),  INT16_C( 18432),  INT16_C( 25472),  INT16_C( 11264), -INT16_C( 26880),
        -INT16_C(  2944), -INT16_C( 18048),  INT16_C( 21760),  INT16_C(  1920), -INT16_C( 10496), -INT16_C( 10112),  INT16_C( 21120), -INT16_C( 10112) },
      {  INT16_C(     0), -INT16_C(  8192),  INT16_C(     0), -INT16_C( 24576),  INT16_C(  8192), -INT16_C( 24576),       INT16_MIN, -INT16_C(  8192),
         INT16_C( 24576), -INT16_C(  8192),  INT16_C(     0), -INT16_C( 16384),  INT16_C(     0),  INT16_C(     0),  INT16_C(  8192),  INT16_C(     0),
        -INT16_C( 16384),  INT16_C( 24576), -INT16_C( 16384),  INT16_C( 24576),  INT16_C(     0), -INT16_C(  8192),  INT16_C(     0), -INT16_C( 16384),
         INT16_C(  8192),  INT16_C( 24576),  INT16_C( 16384), -INT16_C(  8192), -INT16_C( 16384),  INT16_C(  8192), -INT16_C( 24576),  INT16_C(  8192) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { {  INT16_C( 11433),  INT16_C( 16546),  INT16_C( 27972), -INT16_C( 10849),  INT16_C( 26125),  INT16_C( 26081),  INT16_C(  4045), -INT16_C( 18888),
        -INT16_C( 21268), -INT16_C( 26649), -INT16_C(  2554), -INT16_C( 19247), -INT16_C( 31899),  INT16_C(  2875), -INT16_C(  5019),  INT16_C(  3606),
        -INT16_C( 18408),  INT16_C( 23886), -INT16_C(  4571),  INT16_C( 12850),  INT16_C(  4948),  INT16_C(  8599), -INT16_C( 12253),  INT16_C(  4055),
        -INT16_C( 16516), -INT16_C( 32090),  INT16_C( 30901),  INT16_C(  6966),  INT16_C( 29179),  INT16_C( 24614),  INT16_C( 15454),  INT16_C( 30318) },
      {  INT16_C( 11433),  INT16_C( 16546),  INT16_C( 27972), -INT16_C( 10849),  INT16_C( 26125),  INT16_C( 26081),  INT16_C(  4045), -INT16_C( 18888),
        -INT16_C( 21268), -INT16_C( 26649), -INT16_C(  2554), -INT16_C( 19247), -INT16_C( 31899),  INT16_C(  2875), -INT16_C(  5019),  INT16_C(  3606),
        -INT16_C( 18408),  INT16_C( 23886), -INT16_C(  4571),  INT16_C( 12850),  INT16_C(  4948),  INT16_C(  8599), -INT16_C( 12253),  INT16_C(  4055),
        -INT16_C( 16516), -INT16_C( 32090),  INT16_C( 30901),  INT16_C(  6966),  INT16_C( 29179),  INT16_C( 24614),  INT16_C( 15454),  INT16_C( 30318) },
      {  INT16_C( 25928),  INT16_C(  1296),  INT16_C( 27168), -INT16_C( 21256),  INT16_C( 12392),  INT16_C( 12040),  INT16_C( 32360), -INT16_C( 20032),
         INT16_C( 26464), -INT16_C( 16584), -INT16_C( 20432), -INT16_C( 22904),  INT16_C(  6952),  INT16_C( 23000),  INT16_C( 25384),  INT16_C( 28848),
        -INT16_C( 16192), -INT16_C(  5520),  INT16_C( 28968), -INT16_C( 28272), -INT16_C( 25952),  INT16_C(  3256), -INT16_C( 32488),  INT16_C( 32440),
        -INT16_C(  1056),  INT16_C(  5424), -INT16_C( 14936), -INT16_C(  9808), -INT16_C( 28712),  INT16_C(   304), -INT16_C(  7440), -INT16_C( 19600) },
      {  INT16_C( 21632),  INT16_C( 20736), -INT16_C( 24064), -INT16_C( 12416),  INT16_C(  1664), -INT16_C(  3968), -INT16_C(  6528),  INT16_C(  7168),
         INT16_C( 30208), -INT16_C(  3200),  INT16_C(   768),  INT16_C( 26752), -INT16_C( 19840), -INT16_C( 25216),  INT16_C( 12928),  INT16_C(  2816),
         INT16_C(  3072), -INT16_C( 22784),  INT16_C(  4736),  INT16_C(  6400), -INT16_C( 22016), -INT16_C( 13440),  INT16_C(  4480), -INT16_C(  5248),
        -INT16_C( 16896),  INT16_C( 21248),  INT16_C( 23168), -INT16_C( 25856), -INT16_C(   640),  INT16_C(  4864),  INT16_C( 12032),  INT16_C( 14080) },
      {  INT16_C(  8192),  INT16_C( 16384),       INT16_MIN, -INT16_C(  8192), -INT16_C( 24576),  INT16_C(  8192), -INT16_C( 24576),  INT16_C(     0),
              INT16_MIN, -INT16_C(  8192), -INT16_C( 16384),  INT16_C(  8192), -INT16_C( 24576),  INT16_C( 24576), -INT16_C( 24576), -INT16_C( 16384),
         INT16_C(     0), -INT16_C( 16384), -INT16_C( 24576),  INT16_C( 16384),       INT16_MIN, -INT16_C(  8192),  INT16_C( 24576), -INT16_C(  8192),
              INT16_MIN, -INT16_C( 16384), -INT16_C( 24576), -INT16_C( 16384),  INT16_C( 24576), -INT16_C( 16384), -INT16_C( 16384), -INT16_C( 16384) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { { -INT16_C( 16907),  INT16_C(  6867),  INT16_C(  1451), -INT16_C(   179), -INT16_C(  7143),  INT16_C( 15393), -INT16_C(  1868),  INT16_C( 12363),
        -INT16_C(  3401),  INT16_C( 28082), -INT16_C(  6038),  INT16_C( 25992), -INT16_C( 20902), -INT16_C( 18235),  INT16_C( 13290), -INT16_C(  8402),
         INT16_C(   752), -INT16_C( 25606),  INT16_C( 18183),  INT16_C(  8347), -INT16_C( 17365), -INT16_C(  8100), -INT16_C( 22348),  INT16_C( 27664),
        -INT16_C( 15462),  INT16_C(  1241),  INT16_C( 25003),  INT16_C(  1385),  INT16_C( 11791), -INT16_C(  1603), -INT16_C(  5023),  INT16_C( 21209) },
      { -INT16_C( 16907),  INT16_C(  6867),  INT16_C(  1451), -INT16_C(   179), -INT16_C(  7143),  INT16_C( 15393), -INT16_C(  1868),  INT16_C( 12363),
        -INT16_C(  3401),  INT16_C( 28082), -INT16_C(  6038),  INT16_C( 25992), -INT16_C( 20902), -INT16_C( 18235),  INT16_C( 13290), -INT16_C(  8402),
         INT16_C(   752), -INT16_C( 25606),  INT16_C( 18183),  INT16_C(  8347), -INT16_C( 17365), -INT16_C(  8100), -INT16_C( 22348),  INT16_C( 27664),
        -INT16_C( 15462),  INT16_C(  1241),  INT16_C( 25003),  INT16_C(  1385),  INT16_C( 11791), -INT16_C(  1603), -INT16_C(  5023),  INT16_C( 21209) },
      { -INT16_C(  4184), -INT16_C( 10600),  INT16_C( 11608), -INT16_C(  1432),  INT16_C(  8392), -INT16_C(  7928), -INT16_C( 14944), -INT16_C( 32168),
        -INT16_C( 27208),  INT16_C( 28048),  INT16_C( 17232),  INT16_C( 11328),  INT16_C( 29392), -INT16_C( 14808), -INT16_C( 24752), -INT16_C(  1680),
         INT16_C(  6016), -INT16_C(  8240),  INT16_C( 14392),  INT16_C(  1240), -INT16_C(  7848),  INT16_C(   736),  INT16_C( 17824),  INT16_C( 24704),
         INT16_C(  7376),  INT16_C(  9928),  INT16_C(  3416),  INT16_C( 11080),  INT16_C( 28792), -INT16_C( 12824),  INT16_C( 25352), -INT16_C( 26936) },
      { -INT16_C(  1408),  INT16_C( 27008), -INT16_C( 10880), -INT16_C( 22912),  INT16_C(  3200),  INT16_C(  4224),  INT16_C( 23040),  INT16_C(  9600),
         INT16_C( 23424), -INT16_C(  9984),  INT16_C( 13568), -INT16_C( 15360),  INT16_C( 11520),  INT16_C( 25216), -INT16_C(  2816), -INT16_C( 26880),
         INT16_C( 30720), -INT16_C(   768), -INT16_C( 31872),  INT16_C( 19840),  INT16_C(  5504),  INT16_C( 11776),  INT16_C( 23040),  INT16_C(  2048),
        -INT16_C( 13056),  INT16_C( 27776), -INT16_C( 10880), -INT16_C( 19328),  INT16_C(  1920), -INT16_C(  8576),  INT16_C( 12416),  INT16_C( 27776) },
      { -INT16_C( 24576),  INT16_C( 24576),  INT16_C( 24576), -INT16_C( 24576),  INT16_C(  8192),  INT16_C(  8192),       INT16_MIN,  INT16_C( 24576),
        -INT16_C(  8192),  INT16_C( 16384),  INT16_C( 16384),  INT16_C(     0),  INT16_C( 16384), -INT16_C( 24576),  INT16_C( 16384), -INT16_C( 16384),
         INT16_C(     0),  INT16_C( 16384), -INT16_C(  8192),  INT16_C( 24576),  INT16_C( 24576),       INT16_MIN,       INT16_MIN,  INT16_C(     0),
         INT16_C( 16384),  INT16_C(  8192),  INT16_C( 24576),  INT16_C(  8192), -INT16_C(  8192), -INT16_C( 24576),  INT16_C(  8192),  INT16_C(  8192) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a, r0, r3, r7, r13, r24;
    a = simde_mm512_loadu_epi16(test_vec[i].a);
    r0 = simde_mm512_slli_epi16(a, 0);
    simde_test_x86_assert_equal_i16x32(r0, simde_mm512_loadu_epi16(test_vec[i].r0));
    r3 = simde_mm512_slli_epi16(a, 3);
    simde_test_x86_assert_equal_i16x32(r3, simde_mm512_loadu_epi16(test_vec[i].r3));
    r7 = simde_mm512_slli_epi16(a, 7);
    simde_test_x86_assert_equal_i16x32(r7, simde_mm512_loadu_epi16(test_vec[i].r7));
    r13 = simde_mm512_slli_epi16(a, 13);
    simde_test_x86_assert_equal_i16x32(r13, simde_mm512_loadu_epi16(test_vec[i].r13));
    r24 = simde_mm512_slli_epi16(a, 24);
    simde_test_x86_assert_equal_i16x32(r24, simde_mm512_loadu_epi16(test_vec[i].r24));
  }

  return 0;
}

static int
test_simde_mm512_mask_slli_epi16(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  const struct {
    const int16_t src[32];
    const simde__mmask32 k;
    const int16_t a[32];
    const int16_t r[32];
  } test_vec[] = {
    { {  INT16_C( 16834),  INT16_C(  1823),  INT16_C(  8457), -INT16_C( 19370), -INT16_C( 23240), -INT16_C(  7217),  INT16_C( 31654),  INT16_C( 28462),
         INT16_C( 26109),  INT16_C( 20033), -INT16_C( 24770),  INT16_C( 29735), -INT16_C( 26969),  INT16_C( 27960),  INT16_C( 10561),  INT16_C(   872),
        -INT16_C( 30870),  INT16_C( 29706),  INT16_C( 25001), -INT16_C(  7896), -INT16_C(  2298), -INT16_C( 21308), -INT16_C(  3469),  INT16_C( 28699),
         INT16_C( 23639), -INT16_C( 27202), -INT16_C(  6405), -INT16_C( 23798),  INT16_C( 17020), -INT16_C( 17136),  INT16_C( 31083), -INT16_C( 10816) },
      UINT32_C(2840185600),
      {  INT16_C( 29228),  INT16_C( 12938),  INT16_C( 20073), -INT16_C(  8994), -INT16_C(  1727), -INT16_C( 26547),  INT16_C(  2901),  INT16_C( 20782),
         INT16_C( 14577),  INT16_C( 28148),  INT16_C(  1146), -INT16_C(  6870), -INT16_C(  5251),  INT16_C( 32442),  INT16_C(  1206), -INT16_C(  7641),
        -INT16_C( 19850), -INT16_C(  8428), -INT16_C(  3584),  INT16_C( 16828),  INT16_C(  2539),  INT16_C( 16602),  INT16_C(  2068),  INT16_C(  1681),
        -INT16_C( 31424), -INT16_C( 17805), -INT16_C( 24950),  INT16_C(  1951),  INT16_C( 22921),  INT16_C( 16261), -INT16_C( 21155), -INT16_C( 11487) },
      {  INT16_C( 16834),  INT16_C(  1823),  INT16_C(  8457), -INT16_C( 19370), -INT16_C( 23240), -INT16_C(  7217),  INT16_C( 31654),  INT16_C( 28462),
         INT16_C( 30848), -INT16_C(  1536), -INT16_C( 24770), -INT16_C( 27392), -INT16_C( 26969),  INT16_C( 27960),  INT16_C( 23296),  INT16_C(  4992),
         INT16_C( 15104),  INT16_C( 29706),  INT16_C( 25001), -INT16_C(  8704), -INT16_C(  2298), -INT16_C( 21308),  INT16_C(  2560),  INT16_C( 28699),
        -INT16_C( 24576), -INT16_C( 27202), -INT16_C(  6405), -INT16_C( 12416),  INT16_C( 17020), -INT16_C( 15744),  INT16_C( 31083), -INT16_C( 28544) } },
    { {  INT16_C( 13663),  INT16_C( 24499),  INT16_C( 28455),  INT16_C(  4769),  INT16_C( 31608), -INT16_C( 29614), -INT16_C(  7037), -INT16_C( 15470),
         INT16_C(  1641), -INT16_C(  3203),  INT16_C(  7332),  INT16_C( 11771), -INT16_C( 32651), -INT16_C( 11412), -INT16_C( 29395), -INT16_C( 29530),
         INT16_C( 22978), -INT16_C(  5652), -INT16_C( 29240),  INT16_C( 16635),  INT16_C( 19720), -INT16_C( 29747),  INT16_C( 24369), -INT16_C( 25778),
        -INT16_C( 13467),  INT16_C(  2446), -INT16_C( 30233),  INT16_C( 23606), -INT16_C( 24054),  INT16_C( 14127), -INT16_C( 10705), -INT16_C(  3644) },
      UINT32_C(4175081519),
      { -INT16_C( 10947),  INT16_C( 17720),  INT16_C(  1315),  INT16_C( 21712),  INT16_C(  7781), -INT16_C( 13585),  INT16_C( 32489), -INT16_C( 12076),
         INT16_C(  2567),  INT16_C(  4396),  INT16_C( 23725), -INT16_C(  9143),  INT16_C(  3378),  INT16_C( 25038), -INT16_C( 22339), -INT16_C(  1447),
        -INT16_C( 28034), -INT16_C( 24257),  INT16_C(  3991), -INT16_C(   779), -INT16_C(  6867),  INT16_C(  5831), -INT16_C( 25757),  INT16_C( 27366),
         INT16_C(  4773),  INT16_C( 21116), -INT16_C( 14994), -INT16_C( 24529), -INT16_C(   558), -INT16_C( 28926),  INT16_C( 23461),  INT16_C(  9097) },
      { -INT16_C( 24960), -INT16_C( 25600), -INT16_C( 28288),  INT16_C( 26624),  INT16_C( 31608),  INT16_C( 30592), -INT16_C(  7037), -INT16_C( 15470),
         INT16_C(  1641), -INT16_C(  3203),  INT16_C(  7332),  INT16_C( 11771), -INT16_C( 26368), -INT16_C(  6400), -INT16_C( 29395),  INT16_C( 11392),
         INT16_C( 22978), -INT16_C( 24704), -INT16_C( 29240),  INT16_C( 31360), -INT16_C( 27008), -INT16_C( 29747), -INT16_C( 20096),  INT16_C( 29440),
        -INT16_C( 13467),  INT16_C(  2446), -INT16_C( 30233),  INT16_C(  6016), -INT16_C(  5888), -INT16_C( 32512), -INT16_C( 11648), -INT16_C( 15232) } },
    { { -INT16_C( 14099), -INT16_C( 31292), -INT16_C( 17705),  INT16_C(  1153),  INT16_C( 18591),  INT16_C(   538),  INT16_C(   227), -INT16_C( 30356),
        -INT16_C(  6126), -INT16_C( 32293),  INT16_C(  2733),  INT16_C( 32545),  INT16_C(  8967), -INT16_C( 21234), -INT16_C( 26753),  INT16_C( 27856),
        -INT16_C( 27297),  INT16_C( 14065),  INT16_C( 29519), -INT16_C(  4550),  INT16_C( 21691), -INT16_C( 24592),  INT16_C( 23636),  INT16_C( 26408),
         INT16_C(   837), -INT16_C(  3352),  INT16_C(  2318),  INT16_C(  5490), -INT16_C( 32723), -INT16_C( 21310), -INT16_C( 27880),  INT16_C( 30488) },
      UINT32_C(2007894568),
      { -INT16_C(  6019),  INT16_C( 14437),  INT16_C( 21821), -INT16_C( 28201), -INT16_C(    79), -INT16_C(  2312), -INT16_C(  8189),  INT16_C(  4585),
         INT16_C( 23530),  INT16_C(  5926), -INT16_C(  5669), -INT16_C(  3133), -INT16_C(  9348), -INT16_C( 23445),  INT16_C(  6629),  INT16_C( 25115),
        -INT16_C( 32767),  INT16_C( 16027),  INT16_C( 29397), -INT16_C( 31024), -INT16_C( 14222),  INT16_C( 30077),  INT16_C( 26281), -INT16_C( 27770),
        -INT16_C( 21311), -INT16_C( 25430),  INT16_C( 28053),  INT16_C(  4496), -INT16_C(  1208),  INT16_C( 11957), -INT16_C( 12268),  INT16_C(  5520) },
      { -INT16_C( 14099), -INT16_C( 31292), -INT16_C( 17705), -INT16_C(  5248),  INT16_C( 18591),  INT16_C( 31744),  INT16_C(   227), -INT16_C( 30356),
        -INT16_C(  6126), -INT16_C( 27904),  INT16_C(  2733), -INT16_C(  7808),  INT16_C(  8967), -INT16_C( 21234), -INT16_C( 26753),  INT16_C( 27856),
        -INT16_C( 27297),  INT16_C( 19840),  INT16_C( 27264),  INT16_C( 26624),  INT16_C( 21691), -INT16_C( 16768),  INT16_C( 23636), -INT16_C( 15616),
         INT16_C( 24704),  INT16_C( 21760), -INT16_C( 13696),  INT16_C(  5490), -INT16_C( 23552),  INT16_C( 23168),  INT16_C(  2560),  INT16_C( 30488) } },
    { {  INT16_C( 11088),  INT16_C(  9556),  INT16_C(  9374),  INT16_C(  4268),  INT16_C( 10732), -INT16_C( 27259),  INT16_C(  2959),  INT16_C( 20520),
        -INT16_C( 11593),  INT16_C( 19948),  INT16_C( 31807), -INT16_C( 30626),  INT16_C(  5239), -INT16_C( 29770),  INT16_C( 18148),  INT16_C( 13729),
        -INT16_C(  2702),  INT16_C(  4186),  INT16_C(  1561),  INT16_C(  1312), -INT16_C( 23249), -INT16_C( 16741), -INT16_C( 15440),  INT16_C( 26382),
        -INT16_C(  1130), -INT16_C( 10828),  INT16_C(  4983), -INT16_C(  4259),  INT16_C(  4903),  INT16_C(  2938),  INT16_C(  7002), -INT16_C( 13248) },
      UINT32_C( 702323472),
      { -INT16_C(   863), -INT16_C( 11985), -INT16_C( 13663),  INT16_C( 20879), -INT16_C( 24947),  INT16_C(  9144),  INT16_C( 28057),  INT16_C(  4345),
         INT16_C( 22144), -INT16_C( 22529),  INT16_C( 31338), -INT16_C( 15182), -INT16_C(  3179), -INT16_C( 22896),  INT16_C( 27790),  INT16_C( 12239),
        -INT16_C(   408),  INT16_C(  2304), -INT16_C( 28472),  INT16_C( 22106),  INT16_C(  4654), -INT16_C( 14471),  INT16_C( 29311), -INT16_C(    41),
        -INT16_C( 10295),  INT16_C( 13222),  INT16_C( 22865), -INT16_C(  6409), -INT16_C( 30900), -INT16_C(  9588),  INT16_C( 23795),  INT16_C( 23305) },
      {  INT16_C( 11088),  INT16_C(  9556),  INT16_C(  9374),  INT16_C(  4268),  INT16_C( 18048), -INT16_C( 27259),  INT16_C(  2959),  INT16_C( 20520),
         INT16_C( 16384), -INT16_C(   128),  INT16_C( 31807),  INT16_C( 22784), -INT16_C( 13696), -INT16_C( 29770),  INT16_C( 18148), -INT16_C(  6272),
        -INT16_C(  2702),  INT16_C(  4186),  INT16_C( 25600),  INT16_C( 11520),  INT16_C(  5888), -INT16_C( 16741),  INT16_C( 16256), -INT16_C(  5248),
        -INT16_C(  7040), -INT16_C( 10828),  INT16_C(  4983),  INT16_C( 31616),  INT16_C(  4903),  INT16_C( 17920),  INT16_C(  7002), -INT16_C( 13248) } },
    { {  INT16_C(  2650),  INT16_C(  9060), -INT16_C( 16742), -INT16_C( 14215), -INT16_C(  3376),  INT16_C( 20623),  INT16_C( 26213),  INT16_C( 11855),
        -INT16_C(  2499), -INT16_C( 29087),  INT16_C( 22607), -INT16_C( 25739),  INT16_C(   479), -INT16_C( 11659),  INT16_C( 32349), -INT16_C( 18387),
        -INT16_C( 28280),  INT16_C(  8923),  INT16_C( 21583),  INT16_C(  8170),  INT16_C( 31046), -INT16_C( 21649), -INT16_C( 16416),  INT16_C(  7641),
         INT16_C( 15029),  INT16_C(  1196),  INT16_C(  8594),  INT16_C( 29087),  INT16_C(  5154), -INT16_C( 32701),  INT16_C( 28818),  INT16_C(  6968) },
      UINT32_C(1346179841),
      {  INT16_C( 10343), -INT16_C( 21136), -INT16_C(  8287), -INT16_C( 32423),  INT16_C( 12958),  INT16_C( 21407),  INT16_C( 19309), -INT16_C(   169),
        -INT16_C(  2452), -INT16_C( 29071), -INT16_C( 19446), -INT16_C( 25330),  INT16_C( 17957),  INT16_C(  9912), -INT16_C(  2727), -INT16_C( 16265),
        -INT16_C(  6371), -INT16_C( 16530), -INT16_C( 14394),  INT16_C( 25920), -INT16_C(  8199),  INT16_C( 26296),  INT16_C(  4138), -INT16_C( 27034),
        -INT16_C( 10490),  INT16_C(  4389),  INT16_C( 13195), -INT16_C( 20306),  INT16_C( 26234), -INT16_C( 11305),  INT16_C( 20059),  INT16_C( 31124) },
      {  INT16_C( 13184),  INT16_C(  9060), -INT16_C( 16742), -INT16_C( 14215), -INT16_C(  3376),  INT16_C( 20623),  INT16_C( 26213),  INT16_C( 11855),
         INT16_C( 13824),  INT16_C( 14464),  INT16_C( 22607), -INT16_C( 25739),  INT16_C(  4736), -INT16_C( 11659),  INT16_C( 32349), -INT16_C( 18387),
        -INT16_C( 29056),  INT16_C(  8923), -INT16_C(  7424), -INT16_C( 24576), -INT16_C(   896),  INT16_C( 23552), -INT16_C( 16416),  INT16_C(  7641),
         INT16_C( 15029),  INT16_C(  1196),  INT16_C(  8594),  INT16_C( 29087),  INT16_C( 15616), -INT16_C( 32701),  INT16_C( 11648),  INT16_C(  6968) } },
    { {  INT16_C(   565), -INT16_C(  1224),  INT16_C( 30921), -INT16_C( 15776),  INT16_C(  6488), -INT16_C( 32215), -INT16_C( 28887),  INT16_C( 12057),
         INT16_C( 15974), -INT16_C(  3776), -INT16_C(  4495), -INT16_C(  5214),  INT16_C( 31060), -INT16_C( 20289),  INT16_C( 21447), -INT16_C(   983),
         INT16_C( 24917),  INT16_C(  7927),  INT16_C( 22745),  INT16_C( 12768),  INT16_C(  2417), -INT16_C( 25932), -INT16_C( 12904), -INT16_C(   311),
         INT16_C(  2571),  INT16_C( 31984), -INT16_C( 27912),  INT16_C( 19816),  INT16_C(  9995), -INT16_C( 11523),  INT16_C(  9850), -INT16_C( 12338) },
      UINT32_C(1626195335),
      { -INT16_C( 13027), -INT16_C( 29038),  INT16_C( 18135),  INT16_C( 28456), -INT16_C(  3565),  INT16_C(  7790),  INT16_C( 24316), -INT16_C(  2918),
         INT16_C(   752), -INT16_C(  1215),  INT16_C( 15913), -INT16_C( 23603), -INT16_C( 25756), -INT16_C(  5262),  INT16_C( 24416),  INT16_C( 32332),
        -INT16_C(  8659),  INT16_C(  1036),  INT16_C( 13604),  INT16_C( 14195), -INT16_C(  7897),  INT16_C(  9045), -INT16_C(  4289),  INT16_C( 12055),
         INT16_C( 23026),  INT16_C(  6954), -INT16_C(  2153), -INT16_C(   833),  INT16_C( 12690), -INT16_C(  3097),  INT16_C( 13201), -INT16_C( 16783) },
      { -INT16_C( 29056),  INT16_C( 18688),  INT16_C( 27520), -INT16_C( 15776),  INT16_C(  6488), -INT16_C( 32215), -INT16_C( 28887),  INT16_C( 19712),
         INT16_C( 30720), -INT16_C(  3776),  INT16_C(  5248), -INT16_C(  5214),  INT16_C( 31060), -INT16_C( 20289), -INT16_C( 20480),  INT16_C(  9728),
         INT16_C(  5760),  INT16_C(  7927), -INT16_C( 28160), -INT16_C( 18048),  INT16_C(  2417), -INT16_C( 21888), -INT16_C( 24704), -INT16_C( 29824),
         INT16_C(  2571),  INT16_C( 31984), -INT16_C( 27912),  INT16_C( 19816),  INT16_C(  9995), -INT16_C(  3200), -INT16_C( 14208), -INT16_C( 12338) } },
    { {  INT16_C( 32017),  INT16_C( 13762),  INT16_C( 13746), -INT16_C(  9876), -INT16_C( 16105),  INT16_C( 22268),  INT16_C(  5297), -INT16_C( 23674),
        -INT16_C( 20371),  INT16_C(  1214),  INT16_C( 32168),  INT16_C( 14848), -INT16_C(  5969),  INT16_C( 16429), -INT16_C( 25061),  INT16_C( 11774),
        -INT16_C( 16356), -INT16_C( 12702), -INT16_C( 12299),  INT16_C(  3240), -INT16_C( 23408),  INT16_C( 16739), -INT16_C(  5704),  INT16_C(  9700),
        -INT16_C( 23655),  INT16_C( 16682),  INT16_C( 10784), -INT16_C( 12420), -INT16_C( 22254),  INT16_C( 11791),  INT16_C(  3400),  INT16_C( 25691) },
      UINT32_C(3274882509),
      { -INT16_C(  9588),  INT16_C(  7631),  INT16_C( 12927),  INT16_C( 14174),  INT16_C( 17179), -INT16_C( 19107), -INT16_C( 30746),  INT16_C(  1782),
         INT16_C( 29361), -INT16_C( 15146), -INT16_C(  6884),  INT16_C( 25842),  INT16_C( 19955), -INT16_C( 16184), -INT16_C(  1526), -INT16_C( 26749),
         INT16_C( 21461),  INT16_C( 21684),  INT16_C(  4741), -INT16_C( 24181), -INT16_C(  6059),  INT16_C( 15190),  INT16_C( 19567),  INT16_C(  8514),
         INT16_C(  6335), -INT16_C(  9243), -INT16_C( 10243), -INT16_C(  4033),  INT16_C(  1828),  INT16_C( 11953),  INT16_C( 13313), -INT16_C( 10555) },
      {  INT16_C( 17920),  INT16_C( 13762),  INT16_C( 16256), -INT16_C( 20736), -INT16_C( 16105),  INT16_C( 22268), -INT16_C(  3328),  INT16_C( 31488),
         INT16_C( 22656),  INT16_C(  1214), -INT16_C( 29184),  INT16_C( 30976), -INT16_C(  1664),  INT16_C( 25600), -INT16_C( 25061), -INT16_C( 16000),
        -INT16_C( 16356),  INT16_C( 23040), -INT16_C( 12299),  INT16_C(  3240),  INT16_C( 10880), -INT16_C( 21760), -INT16_C(  5704),  INT16_C(  9700),
         INT16_C( 24448), -INT16_C(  3456),  INT16_C( 10784), -INT16_C( 12420), -INT16_C( 22254),  INT16_C( 11791),  INT16_C(   128),  INT16_C( 25216) } },
    { {  INT16_C( 31111),  INT16_C(  3370), -INT16_C( 18804), -INT16_C(  7762),  INT16_C(  1182),  INT16_C(  3613),  INT16_C( 24400),  INT16_C(  3887),
         INT16_C(  5239),  INT16_C( 29930),  INT16_C( 10731),  INT16_C(  3941),  INT16_C(  5680),  INT16_C( 12861),  INT16_C(   842), -INT16_C( 11768),
         INT16_C( 13180),  INT16_C(  2271), -INT16_C( 29207), -INT16_C( 30742),  INT16_C(  1937), -INT16_C(  7787), -INT16_C( 15258), -INT16_C(  8719),
        -INT16_C(  9256), -INT16_C( 15535), -INT16_C( 18939),  INT16_C( 13778),  INT16_C(  4300),  INT16_C(  5991),  INT16_C( 28691), -INT16_C( 28695) },
      UINT32_C(2358823075),
      { -INT16_C( 32171), -INT16_C(  6637), -INT16_C( 22135), -INT16_C(  4153), -INT16_C( 18323),  INT16_C( 18124),  INT16_C(  7572), -INT16_C( 26359),
        -INT16_C(  9004), -INT16_C( 24370),  INT16_C( 14060), -INT16_C(    73), -INT16_C( 24410),  INT16_C( 18830),  INT16_C(  9832), -INT16_C( 16939),
        -INT16_C(  5976),  INT16_C( 12707),  INT16_C( 27537), -INT16_C(   224), -INT16_C(  5085), -INT16_C( 18619),  INT16_C( 19978), -INT16_C(  8624),
         INT16_C(  7978),  INT16_C(  5758),  INT16_C( 13909), -INT16_C(  1259), -INT16_C( 23338),  INT16_C( 16196),  INT16_C(  6602),  INT16_C( 29692) },
      {  INT16_C( 10880),  INT16_C(  2432), -INT16_C( 18804), -INT16_C(  7762),  INT16_C(  1182),  INT16_C( 26112),  INT16_C( 24400), -INT16_C( 31616),
         INT16_C(  5239),  INT16_C( 29930),  INT16_C( 10731), -INT16_C(  9344),  INT16_C(  5680),  INT16_C( 12861),  INT16_C( 13312), -INT16_C(  5504),
         INT16_C( 13180),  INT16_C(  2271), -INT16_C( 29207), -INT16_C( 28672),  INT16_C(  4480), -INT16_C(  7787), -INT16_C( 15258),  INT16_C( 10240),
        -INT16_C(  9256), -INT16_C( 15535),  INT16_C( 10880), -INT16_C( 30080),  INT16_C(  4300),  INT16_C(  5991),  INT16_C( 28691), -INT16_C(   512) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i src = simde_mm512_loadu_epi16(test_vec[i].src);
    simde__m512i a = simde_mm512_loadu_epi16(test_vec[i].a);
    simde__m512i r = simde_mm512_mask_slli_epi16(src, test_vec[i].k, a, 7);
    simde_test_x86_assert_equal_i16x32(r, simde_mm512_loadu_epi16(test_vec[i].r));
  }
  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512i src = simde_test_x86_random_i16x32();
    simde__mmask32 k = simde_test_x86_random_mmask32();
    simde__m512i a = simde_test_x86_random_i16x32();
    simde__m512i r = simde_mm512_mask_slli_epi16(src, k, a, 7);

    simde_test_x86_write_i16x32(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask32(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x32(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_maskz_slli_epi16(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  const struct {
    const simde__mmask32 k;
    const int16_t a[32];
    const int16_t r[32];
  } test_vec[] = {
    { UINT32_C(2477039617),
      { -INT16_C( 15093),  INT16_C( 11922), -INT16_C( 10319), -INT16_C( 17434),  INT16_C( 13861),  INT16_C( 20633),  INT16_C(  6229), -INT16_C( 21914),
         INT16_C( 31822),  INT16_C(  9381), -INT16_C(  5856), -INT16_C(  5533),  INT16_C( 24578),  INT16_C(  1117),  INT16_C(   512),  INT16_C(  2967),
         INT16_C( 10695),  INT16_C( 30777),  INT16_C(  7936),  INT16_C(  9524), -INT16_C( 12970), -INT16_C( 21643), -INT16_C(  8987),  INT16_C( 13142),
        -INT16_C(  1192),  INT16_C( 30808), -INT16_C( 17435), -INT16_C(  6302), -INT16_C( 16357),  INT16_C(  7147), -INT16_C( 32062), -INT16_C( 30426) },
      { -INT16_C( 31360),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C( 11904),  INT16_C(     0), -INT16_C( 13440),
         INT16_C(     0),  INT16_C(     0),        INT16_MIN,  INT16_C(     0),  INT16_C(     0), -INT16_C( 17792),  INT16_C(     0), -INT16_C( 21760),
        -INT16_C( 21504),  INT16_C( 11264),  INT16_C(     0),  INT16_C(     0),  INT16_C(  3456),  INT16_C(     0),  INT16_C(     0), -INT16_C( 27904) } },
    { UINT32_C(2868994219),
      {  INT16_C( 13695), -INT16_C( 10799),  INT16_C( 17923), -INT16_C(  6015), -INT16_C( 10462),  INT16_C( 31260),  INT16_C( 29906), -INT16_C( 18446),
         INT16_C( 21807),  INT16_C( 19359), -INT16_C( 30187), -INT16_C( 10394), -INT16_C( 29427), -INT16_C( 18336),  INT16_C( 25069),  INT16_C( 27748),
         INT16_C( 13719), -INT16_C( 26046), -INT16_C( 15493), -INT16_C( 24958), -INT16_C( 24934),  INT16_C( 27672),  INT16_C(  2834),  INT16_C( 16932),
        -INT16_C( 15520),  INT16_C( 30093), -INT16_C(  3251),  INT16_C( 23116), -INT16_C( 21376),  INT16_C( 27923),  INT16_C( 30477), -INT16_C( 23334) },
      { -INT16_C( 16512), -INT16_C(  6016),  INT16_C(     0),  INT16_C( 16512),  INT16_C(     0),  INT16_C(  3584),  INT16_C(     0), -INT16_C(  1792),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C( 12288), -INT16_C(  2432),  INT16_C(     0),
        -INT16_C( 13440),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
        -INT16_C( 20480), -INT16_C( 14720),  INT16_C(     0),  INT16_C(  9728),  INT16_C(     0), -INT16_C( 30336),  INT16_C(     0),  INT16_C( 27904) } },
    { UINT32_C( 658381996),
      { -INT16_C( 15905),  INT16_C( 31173), -INT16_C(  8609),  INT16_C( 29413),  INT16_C(  2537),  INT16_C( 18868),  INT16_C( 16844),  INT16_C(  6846),
         INT16_C(  2612), -INT16_C( 19084), -INT16_C( 30794), -INT16_C( 15582), -INT16_C(   770), -INT16_C( 21912), -INT16_C( 23016), -INT16_C(  2094),
        -INT16_C( 26777), -INT16_C( 14480),  INT16_C( 22133),  INT16_C( 24121), -INT16_C(  4769),  INT16_C( 11431),  INT16_C( 25902),  INT16_C( 25158),
        -INT16_C( 17809),  INT16_C(  9495),  INT16_C( 14914),  INT16_C( 16617),  INT16_C( 20790),  INT16_C( 20459), -INT16_C( 16905),  INT16_C( 24390) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C( 12160),  INT16_C( 29312),  INT16_C(     0), -INT16_C(  9728),  INT16_C(     0),  INT16_C( 24320),
         INT16_C(     0),  INT16_C(     0), -INT16_C(  9472), -INT16_C( 28416),  INT16_C( 32512),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0), -INT16_C( 18432),  INT16_C( 14976),  INT16_C(  7296), -INT16_C( 20608),  INT16_C( 21376),  INT16_C(     0),  INT16_C(     0),
         INT16_C( 14208), -INT16_C( 29824),  INT16_C(  8448),  INT16_C(     0),  INT16_C(     0), -INT16_C(  2688),  INT16_C(     0),  INT16_C(     0) } },
    { UINT32_C(3391534932),
      {  INT16_C( 24333),  INT16_C( 27688), -INT16_C( 12212),  INT16_C( 31384), -INT16_C(  8651), -INT16_C( 23076), -INT16_C(  2919), -INT16_C(  9270),
        -INT16_C( 19666),  INT16_C( 25627),  INT16_C(  1540), -INT16_C(   845), -INT16_C(  1341),  INT16_C(  6235), -INT16_C( 32335), -INT16_C( 16670),
         INT16_C(  2784),  INT16_C( 11306), -INT16_C( 15398),  INT16_C(  4262), -INT16_C( 32095),  INT16_C( 15029),  INT16_C( 32630), -INT16_C( 23531),
         INT16_C( 12595),  INT16_C( 14089), -INT16_C( 17353), -INT16_C(  1229), -INT16_C( 29002),  INT16_C( 26387), -INT16_C(  2801), -INT16_C(  4315) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(  9728),  INT16_C(     0),  INT16_C(  6784),  INT16_C(     0),  INT16_C( 19584),  INT16_C(     0),
        -INT16_C( 26880),  INT16_C(  3456),  INT16_C(   512),  INT16_C(     0),  INT16_C( 24960),  INT16_C( 11648),  INT16_C(     0),  INT16_C( 28928),
         INT16_C(     0),  INT16_C(  5376), -INT16_C(  4864),  INT16_C(     0),  INT16_C(     0),  INT16_C( 23168),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0), -INT16_C( 31616),  INT16_C(     0), -INT16_C( 26240),  INT16_C(     0),  INT16_C(     0), -INT16_C( 30848), -INT16_C( 28032) } },
    { UINT32_C(3659223295),
      { -INT16_C( 16109), -INT16_C( 19222), -INT16_C( 24764), -INT16_C( 17681),  INT16_C(  1054),  INT16_C( 20831),  INT16_C( 26677),  INT16_C( 28041),
        -INT16_C( 17372), -INT16_C(  9368),  INT16_C( 31563),  INT16_C( 23106),  INT16_C( 26736),  INT16_C( 28490),  INT16_C( 26040), -INT16_C( 13495),
         INT16_C( 13095),  INT16_C( 27519),  INT16_C( 28370), -INT16_C(  3803), -INT16_C( 31629), -INT16_C( 22462), -INT16_C( 13332),  INT16_C(  4373),
         INT16_C( 32136), -INT16_C( 11284),  INT16_C( 12024),  INT16_C( 26669),  INT16_C( 30614),  INT16_C( 20184),  INT16_C(  8669),  INT16_C(  1049) },
      { -INT16_C( 30336),  INT16_C( 29952), -INT16_C( 24064),  INT16_C( 30592),  INT16_C(  3840), -INT16_C( 20608),  INT16_C(  6784), -INT16_C( 15232),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C( 14336),  INT16_C(     0), -INT16_C(  9216),  INT16_C(     0),
        -INT16_C( 27776), -INT16_C( 16512),  INT16_C(     0), -INT16_C( 28032),  INT16_C( 14720),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0), -INT16_C(  2560),  INT16_C(     0),  INT16_C(  5760), -INT16_C( 13568),  INT16_C(     0), -INT16_C(  4480),  INT16_C(  3200) } },
    { UINT32_C( 661625173),
      { -INT16_C( 27641),  INT16_C( 31256),  INT16_C( 23321),  INT16_C(  1315),  INT16_C( 14374), -INT16_C( 20970),  INT16_C(   694), -INT16_C( 20863),
        -INT16_C( 20687), -INT16_C( 14569), -INT16_C(  4314),  INT16_C(   790),  INT16_C( 12048),  INT16_C( 25863),  INT16_C( 30408), -INT16_C( 12147),
        -INT16_C( 23285),  INT16_C(  9290),  INT16_C( 27904),  INT16_C( 10025),  INT16_C( 16550),  INT16_C( 23765),  INT16_C( 22338),  INT16_C( 29450),
         INT16_C(  8454),  INT16_C( 11323),  INT16_C( 20752),  INT16_C(  8496),  INT16_C( 14208),  INT16_C( 18822),  INT16_C(  5038), -INT16_C( 18151) },
      {  INT16_C(   896),  INT16_C(     0), -INT16_C( 29568),  INT16_C(     0),  INT16_C(  4864),  INT16_C(     0),  INT16_C( 23296),  INT16_C(     0),
        -INT16_C( 26496),  INT16_C(     0),  INT16_C(     0), -INT16_C( 29952), -INT16_C( 30720),  INT16_C(     0),  INT16_C(     0),  INT16_C( 18048),
        -INT16_C( 31360),  INT16_C(  9472),        INT16_MIN, -INT16_C( 27520),  INT16_C(     0),  INT16_C( 27264), -INT16_C( 24320),  INT16_C(     0),
        -INT16_C( 32000),  INT16_C(  7552), -INT16_C( 30720),  INT16_C(     0),  INT16_C(     0), -INT16_C( 15616),  INT16_C(     0),  INT16_C(     0) } },
    { UINT32_C(3118293945),
      {  INT16_C(  1745),  INT16_C( 30688), -INT16_C( 18874), -INT16_C( 30253), -INT16_C(  8947),  INT16_C(  5116),  INT16_C( 14335),  INT16_C(  3903),
         INT16_C( 28552),  INT16_C(  2352), -INT16_C( 18521),  INT16_C( 21842),  INT16_C( 27594), -INT16_C( 31986), -INT16_C(  5170), -INT16_C( 24771),
         INT16_C(  7665),  INT16_C( 14358), -INT16_C(  5677), -INT16_C(  7999), -INT16_C( 16953), -INT16_C( 14605),  INT16_C( 13301),  INT16_C( 32213),
         INT16_C(  1698),  INT16_C( 18822), -INT16_C( 10051), -INT16_C( 30818), -INT16_C( 21437),  INT16_C(  4619),  INT16_C( 18583), -INT16_C( 30287) },
      {  INT16_C( 26752),  INT16_C(     0),  INT16_C(     0), -INT16_C(  5760), -INT16_C( 31104), -INT16_C(   512),  INT16_C(     0), -INT16_C( 24704),
        -INT16_C( 15360), -INT16_C( 26624),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C( 30976), -INT16_C(  6400),  INT16_C(     0),
        -INT16_C(  1920),  INT16_C(     0), -INT16_C(  5760),  INT16_C( 24704), -INT16_C(  7296),  INT16_C(     0), -INT16_C(  1408), -INT16_C(  5504),
         INT16_C( 20736),  INT16_C(     0),  INT16_C(     0), -INT16_C( 12544),  INT16_C(  8576),  INT16_C(  1408),  INT16_C(     0), -INT16_C( 10112) } },
    { UINT32_C( 969001061),
      { -INT16_C( 32079),  INT16_C( 30745),  INT16_C(  3391),  INT16_C( 13374),  INT16_C(  5184), -INT16_C(  7502),  INT16_C( 14362), -INT16_C( 10452),
        -INT16_C( 13807),  INT16_C( 21598),  INT16_C( 26999),  INT16_C(  3686),  INT16_C(  6321),  INT16_C(  6039),  INT16_C( 22752), -INT16_C( 28336),
         INT16_C( 27098),  INT16_C(  6666),  INT16_C( 18550), -INT16_C( 18866),  INT16_C(    92),  INT16_C( 30361), -INT16_C( 15047),  INT16_C( 19021),
        -INT16_C( 21361),  INT16_C(  1694),  INT16_C(  1301), -INT16_C( 14571), -INT16_C( 21475), -INT16_C(   546),  INT16_C( 11781), -INT16_C(  8306) },
      {  INT16_C( 22656),  INT16_C(     0), -INT16_C( 24704),  INT16_C(     0),  INT16_C(     0),  INT16_C( 22784),  INT16_C(  3328),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C( 13056),  INT16_C(     0),  INT16_C(     0),  INT16_C( 28672), -INT16_C( 22528),
        -INT16_C(  4864),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C( 25472),  INT16_C(  9856),
         INT16_C( 18304),  INT16_C(     0),  INT16_C(     0), -INT16_C( 30080),  INT16_C(  3712), -INT16_C(  4352),  INT16_C(     0),  INT16_C(     0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_epi16(test_vec[i].a);
    simde__m512i r = simde_mm512_maskz_slli_epi16(test_vec[i].k, a, 7);
    simde_test_x86_assert_equal_i16x32(r, simde_mm512_loadu_epi16(test_vec[i].r));
  }
  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask32 k = simde_test_x86_random_mmask32();
    simde__m512i a = simde_test_x86_random_i16x32();
    simde__m512i r = simde_mm512_maskz_slli_epi16(k, a, 7);

    simde_test_x86_write_mmask32(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i16x32(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_mask_slli_epi32(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  const struct {
    const int32_t src[4];
    const simde__mmask8 k;
    const int32_t a[4];
    const int32_t r[4];
  } test_vec[] = {
    { {  INT32_C(   251238551),  INT32_C(  1036273889), -INT32_C(  2118886072), -INT32_C(  1295318750) },
      UINT8_C(173),
      {  INT32_C(  1875097706),  INT32_C(  2056030925), -INT32_C(  1770026648), -INT32_C(  1339204073) },
      { -INT32_C(   505662208),  INT32_C(  1036273889),  INT32_C(  1069855744),  INT32_C(   380570496) } },
    { { -INT32_C(  1601094824),  INT32_C(  1575538176), -INT32_C(  2071958910), -INT32_C(  1624165835) },
      UINT8_C(234),
      {  INT32_C(  2125991668),  INT32_C(   602288794),  INT32_C(   255556785), -INT32_C(   446174294) },
      { -INT32_C(  1601094824), -INT32_C(   216445696), -INT32_C(  2071958910), -INT32_C(  1275734784) } },
    { {  INT32_C(  1256523644),  INT32_C(  1523401712), -INT32_C(   175156797),  INT32_C(  2011115394) },
      UINT8_C( 61),
      { -INT32_C(   908528233),  INT32_C(  1484454876),  INT32_C(   553814582), -INT32_C(   107091727) },
      { -INT32_C(   327496832),  INT32_C(  1523401712), -INT32_C(  2126177536), -INT32_C(   822839168) } },
    { {  INT32_C(   283764941),  INT32_C(   114508725),  INT32_C(    25741522),  INT32_C(  1061158824) },
      UINT8_C(245),
      {  INT32_C(   315689239),  INT32_C(   222898563),  INT32_C(   352283180), -INT32_C(   253626360) },
      {  INT32_C(  1753516928),  INT32_C(   114508725),  INT32_C(  2142574080),  INT32_C(  1061158824) } },
    { {  INT32_C(   614855393), -INT32_C(  1896436795),  INT32_C(   859240499),  INT32_C(  1311274295) },
      UINT8_C(126),
      {  INT32_C(   570581241),  INT32_C(   340660137),  INT32_C(   102523406),  INT32_C(   921111620) },
      {  INT32_C(   614855393),  INT32_C(   654824576),  INT32_C(   238094080),  INT32_C(  1938170368) } },
    { {  INT32_C(  1559956401), -INT32_C(    91256574),  INT32_C(   892453567), -INT32_C(   474775574) },
      UINT8_C(223),
      { -INT32_C(   980875595), -INT32_C(  1210868396), -INT32_C(   973350215), -INT32_C(   847892031) },
      { -INT32_C(   998024576), -INT32_C(   372332032), -INT32_C(    34775936), -INT32_C(  1155997568) } },
    { { -INT32_C(  1227894228),  INT32_C(   611699041),  INT32_C(  2031004410),  INT32_C(   324596318) },
      UINT8_C(248),
      {  INT32_C(  2118965473), -INT32_C(  2043214932),  INT32_C(   793246974),  INT32_C(  1146885234) },
      { -INT32_C(  1227894228),  INT32_C(   611699041),  INT32_C(  2031004410),  INT32_C(   772421888) } },
    { { -INT32_C(  1398402333),  INT32_C(   849791623), -INT32_C(   896524328),  INT32_C(  1505928056) },
      UINT8_C(124),
      {  INT32_C(   304666639),  INT32_C(   202485263),  INT32_C(   176046325), -INT32_C(  1360149604) },
      { -INT32_C(  1398402333),  INT32_C(   849791623),  INT32_C(  1059093120),  INT32_C(  1994509824) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i src = simde_mm_loadu_epi32(test_vec[i].src);
    simde__m128i a = simde_mm_loadu_epi32(test_vec[i].a);
    simde__m128i r = simde_mm_mask_slli_epi32(src, test_vec[i].k, a, 7);
    simde_test_x86_assert_equal_i32x4(r, simde_mm_loadu_epi32(test_vec[i].r));
  }
  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i src = simde_test_x86_random_i32x4();
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128i a = simde_test_x86_random_i32x4();
    simde__m128i r = simde_mm_mask_slli_epi32(src, k, a, 7);

    simde_test_x86_write_i32x4(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_maskz_slli_epi32(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  const struct {
    const simde__mmask8 k;
    const int32_t a[4];
    const int32_t r[4];
  } test_vec[] = {
    { UINT8_C( 56),
      { -INT32_C(  1000581199),  INT32_C(  1871436352), -INT32_C(  1395441428),  INT32_C(  1157684722) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(  2140210944) } },
    { UINT8_C( 30),
      {  INT32_C(   969281721), -INT32_C(  1970603906), -INT32_C(   364788099), -INT32_C(  1466205871) },
      {  INT32_C(           0),  INT32_C(  1165770496),  INT32_C(   551763584),  INT32_C(  1304209536) } },
    { UINT8_C(214),
      { -INT32_C(   340727713),  INT32_C(   724278359),  INT32_C(  1208491592),  INT32_C(  1946298211) },
      {  INT32_C(           0), -INT32_C(  1781650560),  INT32_C(    68101120),  INT32_C(           0) } },
    { UINT8_C(237),
      { -INT32_C(   974785989), -INT32_C(  1098161539), -INT32_C(   415769524),  INT32_C(  1833373060) },
      { -INT32_C(   218555008),  INT32_C(           0), -INT32_C(  1678891520), -INT32_C(  1551449600) } },
    { UINT8_C(189),
      {  INT32_C(  1566164018), -INT32_C(   126115089), -INT32_C(   333455382),  INT32_C(  1160186963) },
      { -INT32_C(  1394468608),  INT32_C(           0),  INT32_C(   267384064), -INT32_C(  1819924096) } },
    { UINT8_C(241),
      {  INT32_C(  2018755309), -INT32_C(  1202348160), -INT32_C(   842671738),  INT32_C(   201294662) },
      {  INT32_C(   702641792),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { UINT8_C(220),
      { -INT32_C(   662767011),  INT32_C(   297232882),  INT32_C(  2099055189),  INT32_C(   308940368) },
      {  INT32_C(           0),  INT32_C(           0), -INT32_C(  1903875456),  INT32_C(   889661440) } },
    { UINT8_C( 97),
      {  INT32_C(   922784738),  INT32_C(   269584203),  INT32_C(  1418942292),  INT32_C(  1571909730) },
      { -INT32_C(  2142637824),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi32(test_vec[i].a);
    simde__m128i r = simde_mm_maskz_slli_epi32(test_vec[i].k, a, 7);
    simde_test_x86_assert_equal_i32x4(r, simde_mm_loadu_epi32(test_vec[i].r));
  }
  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128i a = simde_test_x86_random_i32x4();
    simde__m128i r = simde_mm_maskz_slli_epi32(k, a, 7);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_mask_slli_epi32(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  const struct {
    const int32_t src[8];
    const simde__mmask8 k;
    const int32_t a[8];
    const int32_t r[8];
  } test_vec[] = {
    { {  INT32_C(   859216489),  INT32_C(  1611360320), -INT32_C(  1680288008), -INT32_C(  1491652200),  INT32_C(   431636233), -INT32_C(   484062227), -INT32_C(  1460821237), -INT32_C(   816391578) },
      UINT8_C(116),
      { -INT32_C(   189463924), -INT32_C(   454290162),  INT32_C(   511477997), -INT32_C(   551017313), -INT32_C(  1446231586),  INT32_C(   162836326),  INT32_C(  2003852444),  INT32_C(  1072381875) },
      {  INT32_C(   859216489),  INT32_C(  1611360320),  INT32_C(  1044674176), -INT32_C(  1491652200), -INT32_C(   434049280), -INT32_C(   631786752), -INT32_C(  1204924928), -INT32_C(   816391578) } },
    { {  INT32_C(  1345626178), -INT32_C(  1573642059),  INT32_C(  1220653224), -INT32_C(  1306007084), -INT32_C(  1873022166),  INT32_C(  1066995875),  INT32_C(   532023660), -INT32_C(  1956666807) },
      UINT8_C( 66),
      { -INT32_C(  1275536493), -INT32_C(  1084450289),  INT32_C(  1150592091), -INT32_C(  1100069173), -INT32_C(  1302200670), -INT32_C(  1591828072), -INT32_C(   102089129),  INT32_C(   809268637) },
      {  INT32_C(  1345626178), -INT32_C(  1370683520),  INT32_C(  1220653224), -INT32_C(  1306007084), -INT32_C(  1873022166),  INT32_C(  1066995875), -INT32_C(   182506624), -INT32_C(  1956666807) } },
    { {  INT32_C(  1608725584),  INT32_C(   706691022), -INT32_C(  1368476701), -INT32_C(  1687298567),  INT32_C(  1934479067), -INT32_C(   954897297),  INT32_C(  1203830698), -INT32_C(   981992331) },
      UINT8_C( 48),
      { -INT32_C(  1694554790), -INT32_C(   142792380),  INT32_C(  1961897111),  INT32_C(  1733332121),  INT32_C(  1171768281), -INT32_C(   655384872),  INT32_C(  1531786846),  INT32_C(   143332013) },
      {  INT32_C(  1608725584),  INT32_C(   706691022), -INT32_C(  1368476701), -INT32_C(  1687298567), -INT32_C(   337515392),  INT32_C(  2010082304),  INT32_C(  1203830698), -INT32_C(   981992331) } },
    { {  INT32_C(  2074249783),  INT32_C(  1265770419), -INT32_C(   457219253), -INT32_C(   934539281), -INT32_C(  1425136685),  INT32_C(   528743873), -INT32_C(   512045004),  INT32_C(   451479267) },
      UINT8_C(144),
      { -INT32_C(  1421568373),  INT32_C(  1811320584),  INT32_C(  1583012686),  INT32_C(  1244734247),  INT32_C(   772529201),  INT32_C(   811739744), -INT32_C(  1424800603), -INT32_C(  1187303891) },
      {  INT32_C(  2074249783),  INT32_C(  1265770419), -INT32_C(   457219253), -INT32_C(   934539281),  INT32_C(    99489920),  INT32_C(   528743873), -INT32_C(   512045004), -INT32_C(  1651042688) } },
    { { -INT32_C(   865828924),  INT32_C(  1563974158),  INT32_C(  1555796533), -INT32_C(   425268043),  INT32_C(   672510408), -INT32_C(  2124843044), -INT32_C(   382964549),  INT32_C(  1587701658) },
      UINT8_C(231),
      {  INT32_C(  1626680070), -INT32_C(   174697885), -INT32_C(   106171891),  INT32_C(  1254265241),  INT32_C(   505866918), -INT32_C(  1327913149),  INT32_C(   994755283),  INT32_C(  1780656484) },
      {  INT32_C(  2056618752), -INT32_C(   886492800), -INT32_C(   705100160), -INT32_C(   425268043),  INT32_C(   672510408),  INT32_C(  1825808768), -INT32_C(  1520342656),  INT32_C(   290763264) } },
    { {  INT32_C(   936056788),  INT32_C(  1999397226), -INT32_C(   328083629),  INT32_C(   255275881),  INT32_C(  1630362909), -INT32_C(   669972731),  INT32_C(   773020617), -INT32_C(   661113596) },
      UINT8_C( 77),
      { -INT32_C(   994635933),  INT32_C(   320351804), -INT32_C(   763624289), -INT32_C(  1712288709), -INT32_C(  1063366215), -INT32_C(  1114999198), -INT32_C(  1077757814), -INT32_C(  1274242480) },
      {  INT32_C(  1535619456),  INT32_C(  1999397226),  INT32_C(  1040338816), -INT32_C(   129622656),  INT32_C(  1630362909), -INT32_C(   669972731), -INT32_C(   514046720), -INT32_C(   661113596) } },
    { { -INT32_C(   428293206), -INT32_C(  1845915406), -INT32_C(   798722411), -INT32_C(  1150725118),  INT32_C(   125568933),  INT32_C(   147064446),  INT32_C(   247957182), -INT32_C(   876424159) },
      UINT8_C(151),
      { -INT32_C(   880168645),  INT32_C(   543169450), -INT32_C(   752733825), -INT32_C(  1569136998),  INT32_C(  1612742490), -INT32_C(   903993277), -INT32_C(  1007997713),  INT32_C(   710653679) },
      { -INT32_C(   992436864),  INT32_C(   806212864), -INT32_C(  1860649088), -INT32_C(  1150725118),  INT32_C(   272608512),  INT32_C(   147064446),  INT32_C(   247957182),  INT32_C(   769357696) } },
    { {  INT32_C(   301327463),  INT32_C(  2117228287),  INT32_C(   558978183), -INT32_C(  1933326030), -INT32_C(  1930632376), -INT32_C(    78247413),  INT32_C(   650002743),  INT32_C(  1582307831) },
      UINT8_C(254),
      { -INT32_C(  1677889723), -INT32_C(   165512031), -INT32_C(  1758968627), -INT32_C(   337660665), -INT32_C(  1393136735),  INT32_C(    48492993), -INT32_C(   906425936), -INT32_C(  1631103143) },
      {  INT32_C(   301327463),  INT32_C(   289296512), -INT32_C(  1809684864), -INT32_C(   270892160),  INT32_C(  2067124352),  INT32_C(  1912135808), -INT32_C(    58402816),  INT32_C(  1672195200) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i src = simde_mm256_loadu_epi32(test_vec[i].src);
    simde__m256i a = simde_mm256_loadu_epi32(test_vec[i].a);
    simde__m256i r = simde_mm256_mask_slli_epi32(src, test_vec[i].k, a, 7);
    simde_test_x86_assert_equal_i32x8(r, simde_mm256_loadu_epi32(test_vec[i].r));
  }
  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256i src = simde_test_x86_random_i32x8();
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256i a = simde_test_x86_random_i32x8();
    simde__m256i r = simde_mm256_mask_slli_epi32(src, k, a, 7);

    simde_test_x86_write_i32x8(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_maskz_slli_epi32(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  const struct {
    const simde__mmask8 k;
    const int32_t a[8];
    const int32_t r[8];
  } test_vec[] = {
    { UINT8_C(238),
      {  INT32_C(  1096241033),  INT32_C(  2118888801), -INT32_C(  1802659030),  INT32_C(  1098313390),  INT32_C(  1988931311),  INT32_C(   382377151), -INT32_C(  1602675152),  INT32_C(  1502533327) },
      {  INT32_C(           0),  INT32_C(   634826880),  INT32_C(  1187878144), -INT32_C(  1149806848),  INT32_C(           0),  INT32_C(  1699635072),  INT32_C(  1016010752), -INT32_C(   949262464) } },
    { UINT8_C( 37),
      { -INT32_C(  1819895066), -INT32_C(  2118318619), -INT32_C(  2144382574),  INT32_C(  1970237639), -INT32_C(  1741363716), -INT32_C(   825734224), -INT32_C(  1700894524), -INT32_C(   574621705) },
      { -INT32_C(  1018334464),  INT32_C(           0),  INT32_C(   396937472),  INT32_C(           0),  INT32_C(           0),  INT32_C(  1680201728),  INT32_C(           0),  INT32_C(           0) } },
    { UINT8_C(145),
      {  INT32_C(  1266053190),  INT32_C(  2128475949), -INT32_C(  1773839066), -INT32_C(  1299006515),  INT32_C(   979512303),  INT32_C(  1560162803), -INT32_C(   967599921), -INT32_C(  1638453160) },
      { -INT32_C(  1153948928),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(   823523200),  INT32_C(           0),  INT32_C(           0),  INT32_C(   731393024) } },
    { UINT8_C(160),
      { -INT32_C(   976361011),  INT32_C(   602622918),  INT32_C(  1274053264),  INT32_C(  1060872980),  INT32_C(   909341957),  INT32_C(   201690996),  INT32_C(   308595682), -INT32_C(   256769502) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(    46643712),  INT32_C(           0),  INT32_C(  1493242112) } },
    { UINT8_C(235),
      { -INT32_C(   894323329),  INT32_C(   576378272),  INT32_C(  1748477637),  INT32_C(  1450079969),  INT32_C(   952804521),  INT32_C(  1964693418),  INT32_C(  1050160187),  INT32_C(  1563003102) },
      {  INT32_C(  1490730880),  INT32_C(   761974784),  INT32_C(           0),  INT32_C(   926642304),  INT32_C(           0), -INT32_C(  1922312960),  INT32_C(  1276517760), -INT32_C(  1799065856) } },
    { UINT8_C( 61),
      { -INT32_C(  1327683621),  INT32_C(   678756482), -INT32_C(  1391862217), -INT32_C(   262709428),  INT32_C(    26906410), -INT32_C(   700706646),  INT32_C(   817199784),  INT32_C(  2137854628) },
      {  INT32_C(  1855188352),  INT32_C(           0), -INT32_C(  2064704640),  INT32_C(   732931584), -INT32_C(   850946816),  INT32_C(   503862528),  INT32_C(           0),  INT32_C(           0) } },
    { UINT8_C( 58),
      {  INT32_C(  1253846858), -INT32_C(  2105416540),  INT32_C(  1288581101),  INT32_C(   360103814),  INT32_C(  1774155609),  INT32_C(   772904628),  INT32_C(  1574060363), -INT32_C(   107523666) },
      {  INT32_C(           0),  INT32_C(  1089622528),  INT32_C(           0), -INT32_C(  1151352064), -INT32_C(   541348736),  INT32_C(   147544576),  INT32_C(           0),  INT32_C(           0) } },
    { UINT8_C(128),
      {  INT32_C(   925188947), -INT32_C(   198924347),  INT32_C(   897216886),  INT32_C(  1603178471), -INT32_C(   451676081),  INT32_C(  1261453577),  INT32_C(  1710853396),  INT32_C(  2028401189) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(  1937314432) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i a = simde_mm256_loadu_epi32(test_vec[i].a);
    simde__m256i r = simde_mm256_maskz_slli_epi32(test_vec[i].k, a, 7);
    simde_test_x86_assert_equal_i32x8(r, simde_mm256_loadu_epi32(test_vec[i].r));
  }
  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256i a = simde_test_x86_random_i32x8();
    simde__m256i r = simde_mm256_maskz_slli_epi32(k, a, 7);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_slli_epi32(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m512i a;
    unsigned int b;
    simde__m512i r;
  } test_vec[8] = {
    { simde_mm512_set_epi32(INT32_C( -687706949), INT32_C( 1593775683), INT32_C(  332932989), INT32_C(  583872054),
                            INT32_C( 1838832857), INT32_C(  847835558), INT32_C(-1396128258), INT32_C( -183977070),
                            INT32_C( -902383138), INT32_C( -512492201), INT32_C(-1812249336), INT32_C( -562835271),
                            INT32_C(-1029714159), INT32_C( 1476158556), INT32_C(  877549641), INT32_C( 1218378177)),
      0xac,
      simde_mm512_set_epi32(INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0),
                            INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0),
                            INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0),
                            INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0)) },
    { simde_mm512_set_epi32(INT32_C(  241549121), INT32_C( 1732816264), INT32_C(  875489890), INT32_C(   72071518),
                            INT32_C(-1641761300), INT32_C(  313288882), INT32_C(-1735158939), INT32_C( 1219761116),
                            INT32_C(  877921588), INT32_C( 2045964482), INT32_C( -360092415), INT32_C(-1302958505),
                            INT32_C(-1122092800), INT32_C( -177019481), INT32_C(  875636041), INT32_C( -150268654)),
      0x8017,
      simde_mm512_set_epi32(INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0),
                            INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0),
                            INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0),
                            INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0)) },
    { simde_mm512_set_epi32(INT32_C(  -52534216), INT32_C( -794188551), INT32_C( -186449823), INT32_C( 1580979103),
                            INT32_C( -972993456), INT32_C( -666426563), INT32_C( -645023430), INT32_C(-1043227266),
                            INT32_C( 1237525980), INT32_C(  349749966), INT32_C( -978999744), INT32_C( -487689408),
                            INT32_C(  898649460), INT32_C(-1217796896), INT32_C( 1277301360), INT32_C( 1454357892)),
      0x10,
      simde_mm512_set_epi32(INT32_C( 1681391616), INT32_C(-1527185408), INT32_C(    6356992), INT32_C( -744554496),
                            INT32_C( 1280311296), INT32_C(  591200256), INT32_C(-1187381248), INT32_C(-1652686848),
                            INT32_C(  635174912), INT32_C(-1026686976), INT32_C(-1505755136), INT32_C( 1933574144),
                            INT32_C( 1299447808), INT32_C( -455081984), INT32_C(  309329920), INT32_C(-1115422720)) },
    { simde_mm512_set_epi32(INT32_C(-1898779532), INT32_C( 1141724513), INT32_C( -782352739), INT32_C(  973072470),
                            INT32_C( 1112939167), INT32_C(  368903984), INT32_C( 1631675339), INT32_C(  -86505288),
                            INT32_C( 2011287771), INT32_C( 1938765310), INT32_C( 2078191935), INT32_C( -616151900),
                            INT32_C( -454977425), INT32_C(  544105809), INT32_C(-1307935124), INT32_C(-1400984309)),
      0xa,
      simde_mm512_set_epi32(INT32_C( 1269944320), INT32_C(  894796800), INT32_C( 2029679616), INT32_C(   -6203392),
                            INT32_C( 1483373568), INT32_C( -199442432), INT32_C(   93268992), INT32_C( 1612898304),
                            INT32_C(-2025624576), INT32_C( 1020786688), INT32_C( 2059729920), INT32_C(  420646912),
                            INT32_C(-2040415232), INT32_C(-1181400064), INT32_C(  704229376), INT32_C(  -88855552)) },
    { simde_mm512_set_epi32(INT32_C( -955538666), INT32_C( 1399393330), INT32_C( 1832782688), INT32_C(-1931362608),
                            INT32_C(-1247233529), INT32_C( -537843102), INT32_C( -120831887), INT32_C( 1329473476),
                            INT32_C( 1569899726), INT32_C(  920247722), INT32_C(  275348332), INT32_C( 1640312018),
                            INT32_C( -873496512), INT32_C(  957396290), INT32_C(  390504842), INT32_C( 1781792417)),
      0xf,
      simde_mm512_set_epi32(INT32_C( -779419648), INT32_C(-2045181952), INT32_C(   95420416), INT32_C( -546832384),
                            INT32_C( 1560510464), INT32_C(-1791950848), INT32_C(  540573696), INT32_C(  333578240),
                            INT32_C( 1650917376), INT32_C( -288030720), INT32_C(-1112145920), INT32_C(-1771503616),
                            INT32_C(-1071644672), INT32_C( 1520500736), INT32_C( 1355087872), INT32_C(  -11501568)) },
    { simde_mm512_set_epi32(INT32_C(  188085108), INT32_C(  489074602), INT32_C( 1720231560), INT32_C(  106164094),
                            INT32_C( 1250223633), INT32_C( -962071158), INT32_C(   38255424), INT32_C(  801121683),
                            INT32_C(-1580720854), INT32_C(  609844423), INT32_C(   44983522), INT32_C(  481953328),
                            INT32_C( -181212371), INT32_C(  912186226), INT32_C(  -42587351), INT32_C(  680089879)),
      0x18,
      simde_mm512_set_epi32(INT32_C( 1946157056), INT32_C(-1442840576), INT32_C(-2013265920), INT32_C( 2113929216),
                            INT32_C(  285212672), INT32_C(-1979711488), INT32_C( 1073741824), INT32_C(-1828716544),
                            INT32_C(  704643072), INT32_C( -956301312), INT32_C( -503316480), INT32_C(  805306368),
                            INT32_C(  754974720), INT32_C( 1912602624), INT32_C(  687865856), INT32_C(  385875968)) },
    { simde_mm512_set_epi32(INT32_C(-1878529143), INT32_C(  968369206), INT32_C(-2025408372), INT32_C( -521427427),
                            INT32_C(  750337953), INT32_C( 1599422728), INT32_C( 1832999614), INT32_C( -922516627),
                            INT32_C( 1054703043), INT32_C( -229764941), INT32_C(-1888970968), INT32_C( -770679003),
                            INT32_C(  957667650), INT32_C(-1367078699), INT32_C(  400185050), INT32_C(  619858989)),
      0,
      simde_mm512_set_epi32(INT32_C(-1878529143), INT32_C(  968369206), INT32_C(-2025408372), INT32_C( -521427427),
                            INT32_C(  750337953), INT32_C( 1599422728), INT32_C( 1832999614), INT32_C( -922516627),
                            INT32_C( 1054703043), INT32_C( -229764941), INT32_C(-1888970968), INT32_C( -770679003),
                            INT32_C(  957667650), INT32_C(-1367078699), INT32_C(  400185050), INT32_C(  619858989)) },
    { simde_mm512_set_epi32(INT32_C( -939632719), INT32_C( 1727963384), INT32_C( 1880331239), INT32_C(  699090974),
                            INT32_C( 1068401563), INT32_C(-1558361689), INT32_C(-1814494206), INT32_C( 1865180366),
                            INT32_C(-1767733366), INT32_C(-1147256695), INT32_C(-1631901793), INT32_C( -198157319),
                            INT32_C(  285018015), INT32_C(  583696937), INT32_C( 1785762602), INT32_C(-1724046997)),
      0x16,
      simde_mm512_set_epi32(INT32_C( -331350016), INT32_C( 1040187392), INT32_C( -104857600), INT32_C(  125829120),
                            INT32_C( -423624704), INT32_C( 1774190592), INT32_C(    8388608), INT32_C(  864026624),
                            INT32_C( -494927872), INT32_C(  574619648), INT32_C( -406847488), INT32_C(  -29360128),
                            INT32_C( -406847488), INT32_C(-1975517184), INT32_C( -897581056), INT32_C( 1522532352)) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i r = simde_mm512_slli_epi32(test_vec[i].a, test_vec[i].b);
    simde_assert_m512i_i32(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm512_mask_slli_epi32(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  const struct {
    const int32_t src[16];
    const simde__mmask16 k;
    const int32_t a[16];
    const int32_t r[16];
  } test_vec[] = {
    { { -INT32_C(   609570352), -INT32_C(   632939831),  INT32_C(  2035926413), -INT32_C(  1590679888),  INT32_C(   227884002), -INT32_C(   708047668), -INT32_C(  1578008433),  INT32_C(  1317048702),
         INT32_C(   204024386), -INT32_C(   756650172), -INT32_C(   448053451),  INT32_C(  1199995749), -INT32_C(  2091639881), -INT32_C(  1218961112),  INT32_C(   525879713),  INT32_C(   493738458) },
      UINT16_C(38403),
      {  INT32_C(   252069929),  INT32_C(  1699625754), -INT32_C(  1478380768),  INT32_C(  1321375994),  INT32_C(  1936714267), -INT32_C(    88272734), -INT32_C(  1663854801), -INT32_C(   583805004),
         INT32_C(   971782431), -INT32_C(  1801569676), -INT32_C(   415531027),  INT32_C(   842464791), -INT32_C(  1968790040), -INT32_C(   444243018), -INT32_C(  1350412038),  INT32_C(  1317844271) },
      { -INT32_C(  2094787456), -INT32_C(  1491235584),  INT32_C(  2035926413), -INT32_C(  1590679888),  INT32_C(   227884002), -INT32_C(   708047668), -INT32_C(  1578008433),  INT32_C(  1317048702),
         INT32_C(   204024386),  INT32_C(  1327315456), -INT32_C(  1648363904),  INT32_C(  1199995749),  INT32_C(  1397945344), -INT32_C(  1218961112),  INT32_C(   525879713),  INT32_C(  1180342144) } },
    { {  INT32_C(  1653045742), -INT32_C(  1577703757), -INT32_C(  1115147611),  INT32_C(   418364976),  INT32_C(   446928228), -INT32_C(   201381640), -INT32_C(  1331527296),  INT32_C(   620637750),
         INT32_C(  1535542951),  INT32_C(  1375501740), -INT32_C(   552696657), -INT32_C(  1476919741), -INT32_C(  1933469037),  INT32_C(  1132445890),  INT32_C(  2029199682), -INT32_C(   140644017) },
      UINT16_C( 9079),
      {  INT32_C(  1319117650), -INT32_C(  2083369099),  INT32_C(   645993774),  INT32_C(  2109740476),  INT32_C(   540967841), -INT32_C(  1186889530), -INT32_C(  1783983880), -INT32_C(   642178425),
        -INT32_C(  1171826363), -INT32_C(   683738455), -INT32_C(   855785713),  INT32_C(  1967767252),  INT32_C(   127240001),  INT32_C(    12637703), -INT32_C(   292197785), -INT32_C(   758624628) },
      {  INT32_C(  1343334656), -INT32_C(   383272320),  INT32_C(  1082824448),  INT32_C(   418364976),  INT32_C(   524406912), -INT32_C(  1598004480), -INT32_C(   716669952),  INT32_C(   620637750),
         INT32_C(   330080896), -INT32_C(  1619176320), -INT32_C(   552696657), -INT32_C(  1476919741), -INT32_C(  1933469037),  INT32_C(  1617625984),  INT32_C(  2029199682), -INT32_C(   140644017) } },
    { {  INT32_C(  1368190888), -INT32_C(   114767127),  INT32_C(  1589978762),  INT32_C(   634654436), -INT32_C(  1658033770), -INT32_C(  1482822592), -INT32_C(   476761258),  INT32_C(   699751809),
         INT32_C(   913981773), -INT32_C(  1775262964), -INT32_C(  1376455479), -INT32_C(  1714239485),  INT32_C(  1916206642),  INT32_C(  1075434730), -INT32_C(  2010927609),  INT32_C(  1504892940) },
      UINT16_C(11290),
      { -INT32_C(  1076943217), -INT32_C(  1330407236),  INT32_C(   393852485), -INT32_C(  2045400241),  INT32_C(   911933213),  INT32_C(  1675911488), -INT32_C(  1690504983), -INT32_C(   641182135),
         INT32_C(   949524348),  INT32_C(  1978157872),  INT32_C(  1368219906),  INT32_C(   701997580), -INT32_C(   497077854),  INT32_C(  2084914322),  INT32_C(  2115469620),  INT32_C(  1398267863) },
      {  INT32_C(  1368190888),  INT32_C(  1506565632),  INT32_C(  1589978762),  INT32_C(   181774208),  INT32_C(   763334272), -INT32_C(  1482822592), -INT32_C(   476761258),  INT32_C(   699751809),
         INT32_C(   913981773), -INT32_C(  1775262964), -INT32_C(   961511168), -INT32_C(   338622976),  INT32_C(  1916206642),  INT32_C(   581060864), -INT32_C(  2010927609),  INT32_C(  1504892940) } },
    { { -INT32_C(  1484001417),  INT32_C(  1008497722), -INT32_C(   493966891), -INT32_C(   301243060),  INT32_C(   701524887), -INT32_C(   475720273),  INT32_C(  1851899287),  INT32_C(   331528348),
        -INT32_C(   491106905), -INT32_C(  1759586367), -INT32_C(   864441216), -INT32_C(  1447394286), -INT32_C(  1630369041),  INT32_C(   931297440), -INT32_C(   777657547),  INT32_C(  1139107740) },
      UINT16_C(40885),
      {  INT32_C(  1148614181), -INT32_C(  2031028467),  INT32_C(  2114650819),  INT32_C(  2114517675),  INT32_C(   469149849), -INT32_C(  2046940193), -INT32_C(   504587524),  INT32_C(    58827230),
         INT32_C(   625473304), -INT32_C(  1297336082), -INT32_C(   433014982),  INT32_C(  1248082097), -INT32_C(  1067099423), -INT32_C(  2126158715), -INT32_C(   597478658), -INT32_C(   337582893) },
      {  INT32_C(   993727104),  INT32_C(  1008497722),  INT32_C(    92365184), -INT32_C(   301243060), -INT32_C(    78361472), -INT32_C(    15339648),  INT32_C(  1851899287), -INT32_C(  1060049152),
        -INT32_C(  1543795712),  INT32_C(  1444706048),  INT32_C(   408657152),  INT32_C(   840718464),  INT32_C(   850227328),  INT32_C(   931297440), -INT32_C(   777657547), -INT32_C(   260937344) } },
    { { -INT32_C(   904845349), -INT32_C(  1703101089),  INT32_C(   629189748), -INT32_C(   982457116), -INT32_C(  1014573762),  INT32_C(   944032569), -INT32_C(   787175427),  INT32_C(  1740436619),
         INT32_C(  2066861340), -INT32_C(    32133750),  INT32_C(  1025807705), -INT32_C(  1224502151), -INT32_C(  1552250519),  INT32_C(  1390133076), -INT32_C(   232525978),  INT32_C(     5890020) },
      UINT16_C(35501),
      { -INT32_C(  1858652293),  INT32_C(  1512476726), -INT32_C(   789667635), -INT32_C(   765896873), -INT32_C(   711872774),  INT32_C(   600176384),  INT32_C(  1107470825),  INT32_C(   617394089),
         INT32_C(   498402279),  INT32_C(  1635245203), -INT32_C(   751737476), -INT32_C(  1213887556),  INT32_C(   965490233),  INT32_C(   391926062), -INT32_C(  1554358534), -INT32_C(   171432434) },
      { -INT32_C(  1684292224), -INT32_C(  1703101089),  INT32_C(  2001757824),  INT32_C(   749448064), -INT32_C(  1014573762), -INT32_C(   486834176), -INT32_C(   787175427),  INT32_C(  1717032064),
         INT32_C(  2066861340), -INT32_C(  1142011520),  INT32_C(  1025807705), -INT32_C(   758784512), -INT32_C(  1552250519),  INT32_C(  1390133076), -INT32_C(   232525978), -INT32_C(   468515072) } },
    { { -INT32_C(  1122861782), -INT32_C(   719419047), -INT32_C(  1431744274),  INT32_C(   341921499), -INT32_C(  1286738299),  INT32_C(   986360127),  INT32_C(   366814215),  INT32_C(  1963631947),
         INT32_C(  2083658787), -INT32_C(  1823321691),  INT32_C(  2084502433), -INT32_C(   829382839), -INT32_C(   847127155), -INT32_C(  1928901498), -INT32_C(  1146887056), -INT32_C(  1389318774) },
      UINT16_C(25546),
      {  INT32_C(  2075422505),  INT32_C(  1098274051),  INT32_C(  1642119377),  INT32_C(   272526990),  INT32_C(  1113375803), -INT32_C(   198783919), -INT32_C(  1197297528), -INT32_C(  2028245923),
        -INT32_C(   570241061), -INT32_C(   182486748), -INT32_C(   950665159), -INT32_C(  1445489554), -INT32_C(  1427426472), -INT32_C(  2002906880),  INT32_C(   524304578), -INT32_C(  2002363220) },
      { -INT32_C(  1122861782), -INT32_C(  1154842240), -INT32_C(  1431744274),  INT32_C(   523716352), -INT32_C(  1286738299),  INT32_C(   986360127),  INT32_C(  1364739072), -INT32_C(  1917440384),
         INT32_C(    23588224), -INT32_C(  1883467264),  INT32_C(  2084502433), -INT32_C(   829382839), -INT32_C(   847127155),  INT32_C(  1325957120), -INT32_C(  1608490752), -INT32_C(  1389318774) } },
    { {  INT32_C(  1348905259),  INT32_C(  1531282978), -INT32_C(   199058298), -INT32_C(  1986135504),  INT32_C(   758351917),  INT32_C(  1538642329), -INT32_C(  1099172334),  INT32_C(  2101748050),
        -INT32_C(   322064950), -INT32_C(  1186524365), -INT32_C(   542283089), -INT32_C(  1855436188),  INT32_C(  1807719378),  INT32_C(  2143777901), -INT32_C(  1136835990),  INT32_C(   775586915) },
      UINT16_C( 1841),
      {  INT32_C(  1645896730), -INT32_C(   892548835),  INT32_C(   286535849), -INT32_C(  2136086847),  INT32_C(   418716241), -INT32_C(   698720359),  INT32_C(  1448787484),  INT32_C(   106793964),
         INT32_C(   208173295), -INT32_C(   355060671),  INT32_C(   654109284),  INT32_C(   581347792),  INT32_C(  1547344835),  INT32_C(   389191163),  INT32_C(  1064144211),  INT32_C(   138791448) },
      {  INT32_C(   221383936),  INT32_C(  1531282978), -INT32_C(   199058298), -INT32_C(  1986135504),  INT32_C(  2056071296),  INT32_C(   758107264), -INT32_C(  1099172334),  INT32_C(  2101748050),
         INT32_C(   876377984),  INT32_C(  1796874368),  INT32_C(  2121609728), -INT32_C(  1855436188),  INT32_C(  1807719378),  INT32_C(  2143777901), -INT32_C(  1136835990),  INT32_C(   775586915) } },
    { { -INT32_C(  2079019454),  INT32_C(  1198451682), -INT32_C(  1502778667), -INT32_C(   691530989), -INT32_C(  1439563089), -INT32_C(   356424297),  INT32_C(   170471154),  INT32_C(   991064056),
        -INT32_C(     4249827), -INT32_C(   414831342), -INT32_C(  1416776808),  INT32_C(  1988253127), -INT32_C(   283069352),  INT32_C(   198893849),  INT32_C(   118883087), -INT32_C(  1891489678) },
      UINT16_C(  335),
      { -INT32_C(   718315121), -INT32_C(   695613623), -INT32_C(   198422414), -INT32_C(   425098042),  INT32_C(  1304937075), -INT32_C(   464398642),  INT32_C(   537707485), -INT32_C(   501130157),
         INT32_C(   112677053), -INT32_C(  1965211625),  INT32_C(  1451100560),  INT32_C(     3942285), -INT32_C(  1202846742), -INT32_C(  1214472231), -INT32_C(  1244157854), -INT32_C(  1030227964) },
      { -INT32_C(  1750022272),  INT32_C(  1155769472),  INT32_C(   371734784),  INT32_C(  1422025472), -INT32_C(  1439563089), -INT32_C(   356424297),  INT32_C(   107081344),  INT32_C(   991064056),
         INT32_C(  1537760896), -INT32_C(   414831342), -INT32_C(  1416776808),  INT32_C(  1988253127), -INT32_C(   283069352),  INT32_C(   198893849),  INT32_C(   118883087), -INT32_C(  1891489678) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i src = simde_mm512_loadu_epi32(test_vec[i].src);
    simde__m512i a = simde_mm512_loadu_epi32(test_vec[i].a);
    simde__m512i r = simde_mm512_mask_slli_epi32(src, test_vec[i].k, a, 7);
    simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[i].r));
  }
  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512i src = simde_test_x86_random_i32x16();
    simde__mmask16 k = simde_test_x86_random_mmask16();
    simde__m512i a = simde_test_x86_random_i32x16();
    simde__m512i r = simde_mm512_mask_slli_epi32(src, k, a, 7);

    simde_test_x86_write_i32x16(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask16(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_maskz_slli_epi32(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  const struct {
    const simde__mmask16 k;
    const int32_t a[16];
    const int32_t r[16];
  } test_vec[] = {
    { UINT16_C( 2870),
      { -INT32_C(   726467664),  INT32_C(  1766140143), -INT32_C(   319279779), -INT32_C(  1612429428),  INT32_C(  1558244652),  INT32_C(   854258744),  INT32_C(  1076105050),  INT32_C(   927685255),
         INT32_C(  1141701973), -INT32_C(  2085793498),  INT32_C(   175089278),  INT32_C(   447304685),  INT32_C(  2037811777), -INT32_C(   659857282), -INT32_C(   149368721), -INT32_C(  2144443606) },
      {  INT32_C(           0), -INT32_C(  1567328384),  INT32_C(  2081861248),  INT32_C(           0),  INT32_C(  1886819840),  INT32_C(  1970936832),  INT32_C(           0),  INT32_C(           0),
         INT32_C(   108964480), -INT32_C(   693595392),  INT32_C(           0),  INT32_C(  1420424832),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { UINT16_C(14945),
      {  INT32_C(  1921812420),  INT32_C(  2048395786), -INT32_C(  1093860075), -INT32_C(  1773662689),  INT32_C(   871810952), -INT32_C(  1207736673), -INT32_C(  1961152931),  INT32_C(  1925610670),
         INT32_C(   249844227),  INT32_C(  1904802908),  INT32_C(   556815618), -INT32_C(   323520412), -INT32_C(   551571905),  INT32_C(  1905730324), -INT32_C(      216495),  INT32_C(   846316079) },
      {  INT32_C(  1178853888),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(    28528512), -INT32_C(  1919472000),  INT32_C(           0),
         INT32_C(           0), -INT32_C(   998363648),  INT32_C(           0),  INT32_C(  1539060224), -INT32_C(  1881727104), -INT32_C(   879654400),  INT32_C(           0),  INT32_C(           0) } },
    { UINT16_C(22036),
      { -INT32_C(   934121152),  INT32_C(   303977698),  INT32_C(   764117622), -INT32_C(  1914975634),  INT32_C(  1085337513),  INT32_C(  1576206688),  INT32_C(  1914642944), -INT32_C(  1782041516),
        -INT32_C(  2023941467), -INT32_C(   442860689),  INT32_C(  1796351485), -INT32_C(  1711673617),  INT32_C(  1054452189), -INT32_C(  1415852885),  INT32_C(  1126021870), -INT32_C(  1814501906) },
      {  INT32_C(           0),  INT32_C(           0), -INT32_C(   977192192),  INT32_C(           0),  INT32_C(  1484248192),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
         INT32_C(           0), -INT32_C(   851593344), -INT32_C(  1995243904),  INT32_C(           0),  INT32_C(  1825894016),  INT32_C(           0), -INT32_C(  1898088704),  INT32_C(           0) } },
    { UINT16_C(13568),
      { -INT32_C(  1246662885),  INT32_C(  1725607508),  INT32_C(   324323610),  INT32_C(  1018966626),  INT32_C(   185100144),  INT32_C(   818280211),  INT32_C(   303477818),  INT32_C(  1648825927),
        -INT32_C(   652740475), -INT32_C(  1052773977),  INT32_C(   500470971),  INT32_C(   911839430),  INT32_C(   188834552), -INT32_C(  1824848295),  INT32_C(    44388794), -INT32_C(   328930201) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
        -INT32_C(  1946402176),  INT32_C(           0), -INT32_C(   364225152),  INT32_C(           0), -INT32_C(  1598981120), -INT32_C(  1652347776),  INT32_C(           0),  INT32_C(           0) } },
    { UINT16_C(31973),
      {  INT32_C(    91065541),  INT32_C(   563685453), -INT32_C(  1615765690), -INT32_C(   704534123), -INT32_C(   253994316), -INT32_C(  1841195027), -INT32_C(    41965159),  INT32_C(  1534682261),
         INT32_C(  1029761008),  INT32_C(  1432287503), -INT32_C(   302706856),  INT32_C(  1841559225),  INT32_C(  1046323025), -INT32_C(   808345802), -INT32_C(   573747128), -INT32_C(  1539815756) },
      { -INT32_C(  1228512640),  INT32_C(           0), -INT32_C(   659578112),  INT32_C(           0),  INT32_C(           0),  INT32_C(   550237824), -INT32_C(  1076573056), -INT32_C(  1129166208),
         INT32_C(           0),  INT32_C(           0), -INT32_C(    91771904), -INT32_C(   503620480),  INT32_C(   785361024), -INT32_C(   389047552), -INT32_C(   425188352),  INT32_C(           0) } },
    { UINT16_C(38957),
      {  INT32_C(  1066483169), -INT32_C(  2024871534), -INT32_C(  1719793706), -INT32_C(   767963275), -INT32_C(   562991347),  INT32_C(   204388671), -INT32_C(   816651625),  INT32_C(  1734901894),
         INT32_C(  1336342973), -INT32_C(  1177029149),  INT32_C(  1901286908),  INT32_C(   826575908),  INT32_C(   974173691),  INT32_C(   105266799), -INT32_C(  1479173855), -INT32_C(   703644391) },
      { -INT32_C(   929107840),  INT32_C(           0), -INT32_C(  1090262272),  INT32_C(   484948608),  INT32_C(           0),  INT32_C(   391946112),  INT32_C(           0),  INT32_C(           0),
         INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(  1572466176),  INT32_C(   140180864),  INT32_C(           0),  INT32_C(           0),  INT32_C(   127831168) } },
    { UINT16_C(46391),
      { -INT32_C(    55961051),  INT32_C(   642885587),  INT32_C(  1555199256), -INT32_C(  1223512409),  INT32_C(   804618728),  INT32_C(  1556616839), -INT32_C(   845487682), -INT32_C(   595406409),
        -INT32_C(  1093063189), -INT32_C(   320525612),  INT32_C(  1196005280),  INT32_C(   788421445),  INT32_C(  1667101660), -INT32_C(   926997238), -INT32_C(  1114285818),  INT32_C(   362354474) },
      {  INT32_C(  1426920064),  INT32_C(   684976512),  INT32_C(  1497009152),  INT32_C(           0), -INT32_C(    88017920),  INT32_C(  1678459776),  INT32_C(           0),  INT32_C(           0),
         INT32_C(  1821832576),  INT32_C(           0), -INT32_C(  1530146816),  INT32_C(           0), -INT32_C(  1359352320),  INT32_C(  1603437824),  INT32_C(           0), -INT32_C(   863267584) } },
    { UINT16_C(29252),
      { -INT32_C(  1180886828),  INT32_C(  1313881349), -INT32_C(  2102815100),  INT32_C(   561350084), -INT32_C(  1488551960), -INT32_C(   603894713), -INT32_C(  1561056503),  INT32_C(   353712193),
         INT32_C(  1456386641),  INT32_C(  1940135663),  INT32_C(  2029342132), -INT32_C(  1164350766),  INT32_C(   828497898),  INT32_C(   873357867), -INT32_C(   807992690), -INT32_C(  1947931590) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(  1422606848),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(  2048230528),  INT32_C(           0),
         INT32_C(           0), -INT32_C(   770738304),  INT32_C(           0),  INT32_C(           0), -INT32_C(  1326451456),  INT32_C(   120657280), -INT32_C(   343849216),  INT32_C(           0) } },  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_epi32(test_vec[i].a);
    simde__m512i r = simde_mm512_maskz_slli_epi32(test_vec[i].k, a, 7);
    simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[i].r));
  }
  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask16 k = simde_test_x86_random_mmask16();
    simde__m512i a = simde_test_x86_random_i32x16();
    simde__m512i r = simde_mm512_maskz_slli_epi32(k, a, 7);

    simde_test_x86_write_mmask16(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_mask_slli_epi64(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  const struct {
    const int64_t src[2];
    const simde__mmask8 k;
    const int64_t a[2];
    const int64_t r[2];
  } test_vec[] = {
    { {  INT64_C( 2371890188986634057),  INT64_C( 8808112403284126126) },
      UINT8_C(182),
      {  INT64_C( 8614057663062356618),  INT64_C( 2837054288566108446) },
      {  INT64_C( 2371890188986634057), -INT64_C( 5791932537729151232) } },
    { {  INT64_C( 1394664162649948166),  INT64_C( 6608784861197276493) },
      UINT8_C( 81),
      {  INT64_C( 5885243810914468935), -INT64_C( 2137713240318557678) },
      { -INT64_C( 3005299225039592576),  INT64_C( 6608784861197276493) } },
    { { -INT64_C( 1140360289178615544),  INT64_C( 3148893431208750404) },
      UINT8_C(162),
      {  INT64_C( 2844871323714501075),  INT64_C( 2415384193695075116) },
      { -INT64_C( 1140360289178615544), -INT64_C( 4425472460092762624) } },
    { { -INT64_C( 4711770639114148680), -INT64_C( 8795866856534376913) },
      UINT8_C(134),
      {  INT64_C( 3877619528391978656),  INT64_C( 3981032346011127132) },
      { -INT64_C( 4711770639114148680), -INT64_C( 6936693774443172352) } },
    { {  INT64_C( 3643278178791233523),  INT64_C( 7744900304623426600) },
      UINT8_C( 87),
      {  INT64_C( 3230759743094066790),  INT64_C( 3726225788626754636) },
      {  INT64_C( 7708877494430413568), -INT64_C( 2658444972223748608) } },
    { { -INT64_C( 9030111262349518849), -INT64_C( 8845711645938441347) },
      UINT8_C(198),
      {  INT64_C( 3477291095596334847), -INT64_C( 3312960772123130672) },
      { -INT64_C( 9030111262349518849),  INT64_C(  216134863558961152) } },
    { { -INT64_C( 2558894261735486618), -INT64_C( 6933712052079074744) },
      UINT8_C(127),
      { -INT64_C( 2734665917562383253), -INT64_C( 6650295920647400625) },
      {  INT64_C(  450899952496424320), -INT64_C( 2687650452227905664) } },
    { { -INT64_C( 7844222502156061472),  INT64_C( 6176074363070260148) },
      UINT8_C(103),
      { -INT64_C( 5631162414365044472), -INT64_C( 7857534653550745427) },
      { -INT64_C( 1365770164053179392),  INT64_C( 8806488399529924224) } },  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i src = simde_mm_loadu_epi64(test_vec[i].src);
    simde__m128i a = simde_mm_loadu_epi64(test_vec[i].a);
    simde__m128i r = simde_mm_mask_slli_epi64(src, test_vec[i].k, a, 7);
    simde_test_x86_assert_equal_i64x2(r, simde_mm_loadu_epi64(test_vec[i].r));
  }
  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i src = simde_test_x86_random_i64x2();
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128i a = simde_test_x86_random_i64x2();
    simde__m128i r = simde_mm_mask_slli_epi64(src, k, a, 7);

    simde_test_x86_write_i64x2(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x2(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_maskz_slli_epi64(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  const struct {
    const simde__mmask8 k;
    const int64_t a[2];
    const int64_t r[2];
  } test_vec[] = {
    { UINT8_C(199),
      { -INT64_C( 6913484627639780667), -INT64_C( 1090553334296173177) },
      {  INT64_C(  517683200166552192),  INT64_C( 7983125799766246272) } },
    { UINT8_C(137),
      { -INT64_C( 5875742084920790391), -INT64_C( 6376590825701912844) },
      {  INT64_C( 4221520152230446208),  INT64_C(                   0) } },
    { UINT8_C( 53),
      {  INT64_C( 5509620489310634946), -INT64_C( 7080387679742854314) },
      {  INT64_C( 4255147830798311680),  INT64_C(                   0) } },
    { UINT8_C(227),
      {  INT64_C(  391253518831211050), -INT64_C( 8862512860697011265) },
      { -INT64_C( 5259781810733640448), -INT64_C( 9150257672934793344) } },
    { UINT8_C(154),
      {  INT64_C( 6071709320984472018),  INT64_C( 2172882147520360255) },
      {  INT64_C(                   0),  INT64_C( 1427753776962838400) } },
    { UINT8_C(175),
      { -INT64_C(  716229415411769658),  INT64_C( 4649288318389686705) },
      {  INT64_C(  556355195841241856),  INT64_C( 4813094395174246528) } },
    { UINT8_C( 76),
      { -INT64_C( 4089102392155916594),  INT64_C( 5368879182374243732) },
      {  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C(201),
      {  INT64_C( 7014333762707812022),  INT64_C( 7345729085743066782) },
      { -INT64_C( 6055737985168090368),  INT64_C(                   0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi64(test_vec[i].a);
    simde__m128i r = simde_mm_maskz_slli_epi64(test_vec[i].k, a, 7);
    simde_test_x86_assert_equal_i64x2(r, simde_mm_loadu_epi64(test_vec[i].r));
  }
  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128i a = simde_test_x86_random_i64x2();
    simde__m128i r = simde_mm_maskz_slli_epi64(k, a, 7);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x2(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_mask_slli_epi64(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  const struct {
    const int64_t src[4];
    const simde__mmask8 k;
    const int64_t a[4];
    const int64_t r[4];
  } test_vec[] = {
    { {  INT64_C( 5821244755135103901), -INT64_C( 4791893746365201249),  INT64_C( 4826128876172458292), -INT64_C( 3216318665265385143) },
      UINT8_C( 90),
      {  INT64_C( 6170757020927199436), -INT64_C( 8042274622556841878), -INT64_C( 1819604927812141924), -INT64_C( 2193833473911965732) },
      {  INT64_C( 5821244755135103901),  INT64_C( 3606516440459130112),  INT64_C( 4826128876172458292), -INT64_C( 4109523555088339456) } },
    { { -INT64_C( 9070382583964751112),  INT64_C( 3478774065159896031), -INT64_C( 3535775467742790638), -INT64_C(  859185894370768099) },
      UINT8_C(185),
      {  INT64_C( 6295562635107745271), -INT64_C( 2869044355158829818),  INT64_C( 3478354672090822594), -INT64_C( 9015608825785649253) },
      { -INT64_C( 5824721949428876416),  INT64_C( 3478774065159896031), -INT64_C( 3535775467742790638),  INT64_C( 8146946943138647424) } },
    { {  INT64_C( 1013694782691652829), -INT64_C( 2690800615223985037), -INT64_C( 6275969431486958702),  INT64_C( 1138201458920985279) },
      UINT8_C(104),
      { -INT64_C( 2981806432087652148), -INT64_C( 8460073378077839702),  INT64_C( 5174705469009645258), -INT64_C( 5680014509595878896) },
      {  INT64_C( 1013694782691652829), -INT64_C( 2690800615223985037), -INT64_C( 6275969431486958702), -INT64_C( 7618838353599985664) } },
    { { -INT64_C( 4251263791135941551), -INT64_C( 9184984001435472152),  INT64_C( 8010604521909788591),  INT64_C( 9084710621373769084) },
      UINT8_C(252),
      { -INT64_C( 7470947686660199953), -INT64_C(  525003779799625562),  INT64_C( 7728394418039200353), -INT64_C( 6533289616771341575) },
      { -INT64_C( 4251263791135941551), -INT64_C( 9184984001435472152), -INT64_C( 6889694471298142080), -INT64_C( 6157587629801898880) } },
    { { -INT64_C( 1152534161218703936), -INT64_C( 9187151789370683216), -INT64_C( 7675959383598835896), -INT64_C( 1621220919279218139) },
      UINT8_C(177),
      { -INT64_C( 6584567954661551474),  INT64_C( 9140129830715729890),  INT64_C( 8227988970762135430),  INT64_C( 1843243879560317599) },
      {  INT64_C( 5725529193960785664), -INT64_C( 9187151789370683216), -INT64_C( 7675959383598835896), -INT64_C( 1621220919279218139) } },
    { {  INT64_C( 6615689416973717207),  INT64_C( 6625854798349177549),  INT64_C( 6736705261083627178),  INT64_C( 8377773503323052447) },
      UINT8_C( 99),
      {  INT64_C(   53259720225234762),  INT64_C( 3715523731420164642),  INT64_C( 3588048493365795734), -INT64_C( 9023169418924919409) },
      {  INT64_C( 6817244188830049536), -INT64_C( 4028308294667267840),  INT64_C( 6736705261083627178),  INT64_C( 8377773503323052447) } },
    { { -INT64_C(  265095713833901085), -INT64_C( 1172500127925852318), -INT64_C( 8478336381656323060),  INT64_C( 5518516381306201562) },
      UINT8_C( 88),
      {  INT64_C( 1701004889237396744), -INT64_C( 8534779938368183792),  INT64_C( 3402766426858369913), -INT64_C( 1726034378446320643) },
      { -INT64_C(  265095713833901085), -INT64_C( 1172500127925852318), -INT64_C( 8478336381656323060),  INT64_C(  428528443385577088) } },
    { {  INT64_C( 8973629431476206977), -INT64_C( 3511528604804712482), -INT64_C( 3136925540625299394),  INT64_C( 8393462805856391090) },
      UINT8_C(207),
      {  INT64_C( 7293218326832735644), -INT64_C(   36439781353459020),  INT64_C( 5535111121525458615),  INT64_C( 8759981614752031280) },
      { -INT64_C( 7252001924596969984), -INT64_C( 4664292013242754560),  INT64_C( 7517948754295741312), -INT64_C( 3973741808022644736) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i src = simde_mm256_loadu_epi64(test_vec[i].src);
    simde__m256i a = simde_mm256_loadu_epi64(test_vec[i].a);
    simde__m256i r = simde_mm256_mask_slli_epi64(src, test_vec[i].k, a, 7);
    simde_test_x86_assert_equal_i64x4(r, simde_mm256_loadu_epi64(test_vec[i].r));
  }
  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256i src = simde_test_x86_random_i64x4();
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256i a = simde_test_x86_random_i64x4();
    simde__m256i r = simde_mm256_mask_slli_epi64(src, k, a, 7);

    simde_test_x86_write_i64x4(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_maskz_slli_epi64(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  const struct {
    const simde__mmask8 k;
    const int64_t a[4];
    const int64_t r[4];
  } test_vec[] = {
    { UINT8_C(153),
      { -INT64_C(  416745656694615604), -INT64_C( 4870590260419987673), -INT64_C( 5052961443776133627), -INT64_C(   12648561739652474) },
      {  INT64_C( 1996788164217857536),  INT64_C(                   0),  INT64_C(                   0), -INT64_C( 1619015902675516672) } },
    { UINT8_C(225),
      {  INT64_C( 3561753265218093786),  INT64_C(  957546565879668244),  INT64_C( 8838910032828758237), -INT64_C( 7879702067752868685) },
      { -INT64_C( 5264183894822785792),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C( 46),
      {  INT64_C( 7243504841038289038),  INT64_C(  793188865701300544), -INT64_C( 5535664121755523747),  INT64_C( 2659090354278166795) },
      {  INT64_C(                   0), -INT64_C( 9152289632490840064), -INT64_C( 7588732783744078208),  INT64_C( 8322172020833420672) } },
    { UINT8_C(213),
      { -INT64_C( 1862380158781253938),  INT64_C( 8196836423437405035),  INT64_C( 6435911496676424679), -INT64_C( 4814606458380416931) },
      {  INT64_C( 1423012634223666944),  INT64_C(                   0), -INT64_C( 6306811742347463808),  INT64_C(                   0) } },
    { UINT8_C(170),
      {  INT64_C( 1672152456731534666), -INT64_C( 7741454277890828123),  INT64_C( 3343173015440315668),  INT64_C( 4036591883279777606) },
      {  INT64_C(                   0),  INT64_C( 5218032410289787520),  INT64_C(                   0),  INT64_C(  174926995944088320) } },
    { UINT8_C(127),
      { -INT64_C( 3594326366997446197),  INT64_C( 3220280818021222343), -INT64_C( 2641784372896614471), -INT64_C( 9154127317968506724) },
      {  INT64_C( 1094826867065677184),  INT64_C( 6367575085106324352), -INT64_C( 6107006403994723200),  INT64_C( 8863324017442442752) } },
    { UINT8_C(  3),
      { -INT64_C( 2491327225006524350),  INT64_C( 8117000250758268975), -INT64_C( 4913875746129398350),  INT64_C( 9094720634578027825) },
      { -INT64_C( 5295235547772739328),  INT64_C( 5958363969323538304),  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C(232),
      { -INT64_C( 7374964822447807377), -INT64_C( 1359029119155531247),  INT64_C( 7559490040027960654), -INT64_C( 4540717692174001372) },
      {  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C( 9083945760433476096) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i a = simde_mm256_loadu_epi64(test_vec[i].a);
    simde__m256i r = simde_mm256_maskz_slli_epi64(test_vec[i].k, a, 7);
    simde_test_x86_assert_equal_i64x4(r, simde_mm256_loadu_epi64(test_vec[i].r));
  }
  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256i a = simde_test_x86_random_i64x4();
    simde__m256i r = simde_mm256_maskz_slli_epi64(k, a, 7);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_slli_epi64(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m512i a;
    unsigned int b;
    simde__m512i r;
  } test_vec[8] = {
    { simde_mm512_set_epi64(INT64_C(-2953678853593164221), INT64_C( 1429936300098399798),
                            INT64_C( 7897726984473080230), INT64_C(-5996325205020460142),
                            INT64_C(-3875706062389379753), INT64_C(-7783551626585583431),
                            INT64_C(-4422588635656985508), INT64_C( 3769047009929918913)),
      0xac,
      simde_mm512_set_epi64(INT64_C(                   0), INT64_C(                   0),
                            INT64_C(                   0), INT64_C(                   0),
                            INT64_C(                   0), INT64_C(                   0),
                            INT64_C(                   0), INT64_C(                   0)) },
    { simde_mm512_set_epi64(INT64_C( 1037445576805363080), INT64_C( 3760200445600708958),
                            INT64_C(-7051311091025155918), INT64_C(-7452450895147297828),
                            INT64_C( 3770644510958350530), INT64_C(-1546585142970651049),
                            INT64_C(-4819351874959120985), INT64_C( 3760828163438613778)),
      0x8017,
      simde_mm512_set_epi64(INT64_C(                   0), INT64_C(                   0),
                            INT64_C(                   0), INT64_C(                   0),
                            INT64_C(                   0), INT64_C(                   0),
                            INT64_C(                   0), INT64_C(                   0)) },
    { simde_mm512_set_epi64(INT64_C( -225632736140221191), INT64_C( -800795890549009505),
                            INT64_C(-4178975069113474243), INT64_C(-2770354533752005250),
                            INT64_C( 5315133612400100046), INT64_C(-4204771879465094336),
                            INT64_C( 3859670044345230560), INT64_C( 5485967569790680452)),
      0x10,
      simde_mm512_set_epi64(INT64_C( 7221751429524422656), INT64_C(   27406683787427840),
                            INT64_C( 5499132945064853504), INT64_C(-5099550522009059328),
                            INT64_C( 2728078395493449728), INT64_C(-6466919551140364288),
                            INT64_C( 5581287503658221568), INT64_C( 1328657202873106432)) },
    { simde_mm512_set_epi64(INT64_C(  854012069371251830), INT64_C(-7338075353641633319),
                            INT64_C(-3664756911608965568), INT64_C( 6190577389993756354),
                            INT64_C(-5695521678932466387), INT64_C( 8986269833406294113),
                            INT64_C(-6594347992267195055), INT64_C(  897886006004895547)),
      0x2a,
      simde_mm512_set_epi64(INT64_C( 1455181649128980480), INT64_C(-8005319861464989696),
                            INT64_C(-8117456853358608384), INT64_C(-7918726723707863040),
                            INT64_C(-4137484245553643520), INT64_C( -675113333593997312),
                            INT64_C( 7635083510067232768), INT64_C(-2504867807980683264)) },
    { simde_mm512_set_epi64(INT64_C( 6876450537877586373), INT64_C(-2498836913726354503),
                            INT64_C(-5925650014767999746), INT64_C(-5091981247482556140),
                            INT64_C( 2276397305581596841), INT64_C( 4333846664358463853),
                            INT64_C( -724672155607878887), INT64_C( 3417746373838389455)),
      0x2a,
      simde_mm512_set_epi64(INT64_C( -934756407423533056), INT64_C(-3157335600089006080),
                            INT64_C(-2570438283414732800), INT64_C( 7513218039291052032),
                            INT64_C( 7188488275143688192), INT64_C( 7216371890024087552),
                            INT64_C(-9165841190443024384), INT64_C( 1225889494272573440)) },
    { simde_mm512_set_epi64(INT64_C(-8036497785869311574), INT64_C( 3581702479948115598),
                            INT64_C(  748249211564829520), INT64_C( -816680525172154454),
                            INT64_C(-4839891842343135042), INT64_C(-6001583230129728210),
                            INT64_C(-4279294013059977744), INT64_C(-1555144075545091790)),
      0x26,
      simde_mm512_set_epi64(INT64_C(-4397647938138931200), INT64_C( 2043406626093793280),
                            INT64_C(-5590422890961960960), INT64_C(-8604150727591329792),
                            INT64_C( 8423472379845410816), INT64_C(-8411233715916636160),
                            INT64_C(-8742757912167841792), INT64_C(-6541394346116120576)) },
    { simde_mm512_set_epi64(INT64_C(-6276545081940248579), INT64_C(-9016855820360504888),
                            INT64_C( 2589347389053699338), INT64_C(-6212989007002338187),
                            INT64_C( 5925964847698460032), INT64_C( 8758478916256841908),
                            INT64_C( 5134329058456078862), INT64_C(-4414137185393506410)),
      0x18,
      simde_mm512_set_epi64(INT64_C(-9176583453456465920), INT64_C( 7465982649455083520),
                            INT64_C(-4954907897243893760), INT64_C( 7673069422566703104),
                            INT64_C(-6790719338690117632), INT64_C( 3134572139001151488),
                            INT64_C( 1398716822424911872), INT64_C(-7065366029995606016)) },
    { simde_mm512_set_epi64(INT64_C(-4035691796628594440), INT64_C( 8075961177851250718),
                            INT64_C( 4588749774816889255), INT64_C(-7793193271686306610),
                            INT64_C(-7592356991870287735), INT64_C(-7008964827121951751),
                            INT64_C( 1224143053779534377), INT64_C( 7669791976580784491)),
      0x16,
      simde_mm512_set_epi64(INT64_C(-1415889878515712000), INT64_C( -447427762668437504),
                            INT64_C(-1807976093613817856), INT64_C(   43851930488799232),
                            INT64_C(-2112496568954257408), INT64_C(-1730213388945981440),
                            INT64_C(-1744948453022105600), INT64_C(-3844298059735367680)) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i r = simde_mm512_slli_epi64(test_vec[i].a, test_vec[i].b);
    simde_assert_m512i_i64(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm512_mask_slli_epi64(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  const struct {
    const int64_t src[8];
    const simde__mmask8 k;
    const int64_t a[8];
    const int64_t r[8];
  } test_vec[] = {
    { { -INT64_C( 1625556641615774907), -INT64_C( 3273133395976469906),  INT64_C( 7160284977098755027),  INT64_C( 7538309048676319628),
         INT64_C( 2175431791664419695), -INT64_C( 2537964164710364303),  INT64_C( 5586205993870708963), -INT64_C( 2180367355020116687) },
      UINT8_C(155),
      { -INT64_C( 2009615499867248388),  INT64_C( 2983856684929978670),  INT64_C( 1079799659748821915),  INT64_C(  776133224261767522),
        -INT64_C( 6357163502562111351),  INT64_C( 1721383845517702114),  INT64_C( 7512249396153732640), -INT64_C( 6176591088643293136) },
      {  INT64_C( 1023633048925928960), -INT64_C( 5447969876863314176),  INT64_C( 7160284977098755027),  INT64_C( 7111332336958484736),
        -INT64_C( 2060189084729981824), -INT64_C( 2537964164710364303),  INT64_C( 5586205993870708963),  INT64_C( 2606335823169198080) } },
    { { -INT64_C( 5726234778189038233),  INT64_C( 7753877269682763015), -INT64_C( 8319593973826093796), -INT64_C( 2564779695161074275),
         INT64_C( 5804371678305580303),  INT64_C( 7111586534709786875), -INT64_C( 3975255517021581588), -INT64_C( 4504461976800944341) },
      UINT8_C(228),
      {  INT64_C( 2628269487596347193), -INT64_C( 4635386602532978863),  INT64_C( 7533031004209673296), -INT64_C( 2373998822342120902),
         INT64_C(  706176429672250235),  INT64_C( 6036921381894567575), -INT64_C( 6874114372097887640),  INT64_C(  859579018109367399) },
      { -INT64_C( 5726234778189038233),  INT64_C( 7753877269682763015),  INT64_C( 4997276705941497856), -INT64_C( 2564779695161074275),
         INT64_C( 5804371678305580303), -INT64_C( 2037314213296518272),  INT64_C( 5557075909528859648), -INT64_C(  654350124258282624) } },
    { { -INT64_C( 4984500570867676399),  INT64_C( 8722497287517019317),  INT64_C( 7152356105286041148), -INT64_C(  894704628179858439),
         INT64_C( 9045357564421556394),  INT64_C( 1060388608511658285), -INT64_C( 6818745982496251392), -INT64_C( 2822982708862660611) },
      UINT8_C(  9),
      {  INT64_C( 8452215452575245711), -INT64_C( 6574034711293228413), -INT64_C( 1227533131124523002),  INT64_C( 3954710949530490136),
        -INT64_C( 9062752080718548327), -INT64_C( 2444597152819216083),  INT64_C( 7266783729003487179), -INT64_C( 9114970187794352989) },
      { -INT64_C( 6474322419232094336),  INT64_C( 8722497287517019317),  INT64_C( 7152356105286041148),  INT64_C( 8140911549744843776),
         INT64_C( 9045357564421556394),  INT64_C( 1060388608511658285), -INT64_C( 6818745982496251392), -INT64_C( 2822982708862660611) } },
    { { -INT64_C( 6461961254649538608),  INT64_C( 8122006245274392833), -INT64_C(  128015744400454008),  INT64_C( 7318290661038978598),
         INT64_C( 6323485250898220449), -INT64_C( 8631175075104500191), -INT64_C( 1526835976601759371), -INT64_C( 9005078422925797363) },
      UINT8_C( 94),
      {  INT64_C( 3883803130813717821),  INT64_C( 8473167436939832634),  INT64_C( 5673730922860078873), -INT64_C( 6700314567157719267),
        -INT64_C(  223966388171524272), -INT64_C( 1272912488981260036), -INT64_C( 3413909166796927205), -INT64_C( 3259346630495318086) },
      { -INT64_C( 6461961254649538608), -INT64_C( 3792468420564968192),  INT64_C( 6814539251417582720), -INT64_C( 9090037205548691840),
         INT64_C( 8225790461463996416), -INT64_C( 8631175075104500191),  INT64_C( 5741484419022556544), -INT64_C( 9005078422925797363) } },
    { {  INT64_C( 8713732441333902640), -INT64_C( 2719701662706431106), -INT64_C(  666591861063032772), -INT64_C( 2383007086983826023),
         INT64_C( 5979863125700079368),  INT64_C( 4495127901144175816), -INT64_C( 1154912350760956729), -INT64_C(  887499484365713630) },
      UINT8_C(102),
      { -INT64_C( 3962167716806428546),  INT64_C( 8638196465644833331), -INT64_C( 1493017097736953033),  INT64_C( 4910272448677943494),
         INT64_C( 2269676690403712834), -INT64_C( 8399747302772094452), -INT64_C( 4772134486719579138), -INT64_C( 6333293186932564976) },
      {  INT64_C( 8713732441333902640), -INT64_C( 1115496820034430592), -INT64_C( 6638747773234472064), -INT64_C( 2383007086983826023),
         INT64_C( 5979863125700079368), -INT64_C( 5256498479674096128), -INT64_C( 2090659867690926336), -INT64_C(  887499484365713630) } },
    { {  INT64_C( 2957420325389638398),  INT64_C( 6631708087275307816), -INT64_C( 4575380484817241909), -INT64_C( 7447350030037943401),
         INT64_C(  762107666016371788),  INT64_C( 1047807382023288016),  INT64_C( 6032661568638009415),  INT64_C( 5656228670043344716) },
      UINT8_C(250),
      { -INT64_C(  117684807359744256), -INT64_C( 3079248189857821843),  INT64_C( 4953647279187704865),  INT64_C( 2532310665436439604),
         INT64_C( 6094511479744102475),  INT64_C( 5224901411540620952),  INT64_C( 3029086325169590992),  INT64_C( 3270590667538320925) },
      {  INT64_C( 2957420325389638398), -INT64_C( 6762142753900611968), -INT64_C( 4575380484817241909), -INT64_C( 7905628150907659776),
         INT64_C( 5334218311443948928),  INT64_C( 4704594023655623680),  INT64_C(  341424073807063040), -INT64_C( 5639508250414608768) } },
    { { -INT64_C( 5137949527847595144),  INT64_C( 7537873038459863852), -INT64_C( 1434054743936903687),  INT64_C( 6742891282528234884),
        -INT64_C( 2775784532039936350), -INT64_C( 4651717286725623951),  INT64_C( 6401806212143226396),  INT64_C( 3781144149638447926) },
      UINT8_C(168),
      {  INT64_C( 5698511964818765365),  INT64_C( 3259995416486551130),  INT64_C(  180805888074918019),  INT64_C( 5409887576021835032),
        -INT64_C( 1117732089438967618), -INT64_C( 1522692317233704414),  INT64_C( 5870926141911916407), -INT64_C( 7658142646489313706) },
      { -INT64_C( 5137949527847595144),  INT64_C( 7537873038459863852), -INT64_C( 1434054743936903687), -INT64_C( 8510665070168077312),
        -INT64_C( 2775784532039936350),  INT64_C( 8009568204890902784),  INT64_C( 6401806212143226396), -INT64_C( 2564822844025918720) } },
    { { -INT64_C( 3621103369218447560), -INT64_C( 7555531510649007917),  INT64_C( 7693422585355066171), -INT64_C( 8646473333500116843),
        -INT64_C( 2761527881525443531), -INT64_C( 4423598581427786778), -INT64_C( 4101941215103636844), -INT64_C( 6029417787004032901) },
      UINT8_C(249),
      {  INT64_C( 7396554610355113385), -INT64_C( 1029160170238924053),  INT64_C( 6511056560618430438),  INT64_C( 2543545849608218142),
         INT64_C(  985029524781681162),  INT64_C( 3344741071227754545), -INT64_C( 7560582282691506873),  INT64_C( 7794946320471090321) },
      {  INT64_C( 5975042366267380864), -INT64_C( 7555531510649007917),  INT64_C( 7693422585355066171), -INT64_C( 6467524576920006912),
        -INT64_C( 3043429343911672576),  INT64_C( 3851743421832894592), -INT64_C( 8523840351616195712),  INT64_C( 1628949039983773824) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i src = simde_mm512_loadu_epi64(test_vec[i].src);
    simde__m512i a = simde_mm512_loadu_epi64(test_vec[i].a);
    simde__m512i r = simde_mm512_mask_slli_epi64(src, test_vec[i].k, a, 7);
    simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[i].r));
  }
  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512i src = simde_test_x86_random_i64x8();
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m512i a = simde_test_x86_random_i64x8();
    simde__m512i r = simde_mm512_mask_slli_epi64(src, k, a, 7);

    simde_test_x86_write_i64x8(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_maskz_slli_epi64(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  const struct {
    const simde__mmask8 k;
    const int64_t a[8];
    const int64_t r[8];
  } test_vec[] = {
    { UINT8_C(128),
      { -INT64_C(  808203320913907441),  INT64_C( 4039565772022694112), -INT64_C( 4650450555436480390), -INT64_C( 4762400825750224847),
         INT64_C( 1913497929701952062), -INT64_C( 5674551786805736612),  INT64_C( 7517928585837342650),  INT64_C( 4753751730717488781) },
      {  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
         INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(  262332900576639360) } },
    { UINT8_C( 66),
      {  INT64_C( 3874668433890925388), -INT64_C(  422180530198623112), -INT64_C( 8913298699351639628), -INT64_C( 3646569341307615126),
        -INT64_C( 1134067667402563165),  INT64_C( 9208874751938440903),  INT64_C(  201128818524618295), -INT64_C( 4727504061045911018) },
      {  INT64_C(                   0),  INT64_C( 1301124355704896512),  INT64_C(                   0),  INT64_C(                   0),
         INT64_C(                   0),  INT64_C(                   0),  INT64_C( 7297744697441590144),  INT64_C(                   0) } },
    { UINT8_C(105),
      { -INT64_C( 4945848434480264294), -INT64_C(  441345085531607509),  INT64_C( 4893605136960661062),  INT64_C( 9198914385305501879),
        -INT64_C( 8741925186945316122), -INT64_C( 9109639397582621280),  INT64_C( 8028298246396060982), -INT64_C( 3953219412685830210) },
      { -INT64_C( 5879301107349074688),  INT64_C(                   0),  INT64_C(                   0), -INT64_C( 3130579398307062912),
         INT64_C(                   0), -INT64_C( 3888966246873772032), -INT64_C( 5395492589039084800),  INT64_C(                   0) } },
    { UINT8_C(225),
      { -INT64_C( 6896767586684584648), -INT64_C( 7118119015538760463), -INT64_C( 8093596588027060559), -INT64_C( 6004357730881351309),
        -INT64_C( 7204176470437664519), -INT64_C( 1253737658549673853),  INT64_C( 2777184625839959858),  INT64_C( 3601645192197831899) },
      {  INT64_C( 2657464442431642624),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
         INT64_C(                   0),  INT64_C( 5542276369027711360),  INT64_C( 4991494707033381120), -INT64_C(  158017241416307328) } },
    { UINT8_C(133),
      {  INT64_C( 8895679758620202577), -INT64_C(  544471521281151126), -INT64_C(  942990692707505021), -INT64_C( 8798524916976895549),
         INT64_C( 5551225179250956018), -INT64_C( 1487878477602569896), -INT64_C( 7326543129593969302), -INT64_C( 3686513116201714404) },
      { -INT64_C( 5051123466606270336),  INT64_C(                   0),  INT64_C( 8424399849406218624),  INT64_C(                   0),
         INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C( 7741667042628898304) } },
    { UINT8_C(245),
      {  INT64_C( 2633803564611820107),  INT64_C( 5555885343909932722),  INT64_C( 5363996945287510641), -INT64_C( 2121774216043511368),
         INT64_C( 4526861495288948043),  INT64_C( 5199135117518200722), -INT64_C( 4495985469340955773), -INT64_C(  339768126577459250) },
      {  INT64_C( 5085462943541044608),  INT64_C(                   0),  INT64_C( 4062078269547952256),  INT64_C(                   0),
         INT64_C( 7589205111989249408),  INT64_C( 1406508388785834240), -INT64_C( 3637073790646238848), -INT64_C( 6596832054495680768) } },
    { UINT8_C( 75),
      { -INT64_C( 2624167585488852641), -INT64_C( 2048862303793549309),  INT64_C( 4283959516647448727), -INT64_C( 9207355305247385337),
         INT64_C( 2947351024245084048),  INT64_C( 3099537109035555208), -INT64_C( 6603608986957582427), -INT64_C( 4702098660961204451) },
      { -INT64_C( 3852057615801208960), -INT64_C( 3999957853640588928),  INT64_C(                   0),  INT64_C( 2050141645745980288),
         INT64_C(                   0),  INT64_C(                   0),  INT64_C( 3288277060068823680),  INT64_C(                   0) } },
    { UINT8_C(217),
      {  INT64_C( 5540033039075035969), -INT64_C(  809509916382330278), -INT64_C( 8701739255957625636),  INT64_C( 8821270986246945736),
        -INT64_C( 1567897465412949698),  INT64_C(  338277021866597815),  INT64_C( 4717627786035217329), -INT64_C( 2337579720493552164) },
      {  INT64_C( 8147954200641642624),  INT64_C(                   0),  INT64_C(                   0),  INT64_C( 3871297743326405632),
         INT64_C( 2223309237947506432),  INT64_C(                   0), -INT64_C( 4886197819907385216), -INT64_C( 4062299043821851136) } },  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_epi64(test_vec[i].a);
    simde__m512i r = simde_mm512_maskz_slli_epi64(test_vec[i].k, a, 7);
    simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[i].r));
  }
  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m512i a = simde_test_x86_random_i64x8();
    simde__m512i r = simde_mm512_maskz_slli_epi64(k, a, 7);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_slli_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_maskz_slli_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_slli_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_maskz_slli_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_slli_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_slli_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_maskz_slli_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_slli_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_maskz_slli_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_slli_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_maskz_slli_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_slli_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_slli_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_maskz_slli_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_slli_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_maskz_slli_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_slli_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_maskz_slli_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_slli_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_slli_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_maskz_slli_epi64)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/avx512/test-avx512-footer.h>
