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
 */

#define SIMDE_TEST_X86_AVX512_INSN mov_mask

#include <test/x86/avx512/test-avx512.h>
#include <simde/x86/avx512/mov_mask.h>

static int
test_simde_mm512_movepi8_mask(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m512i a;
    simde__mmask64 r;
  } test_vec[8] = {
    { simde_mm512_set_epi8(INT8_C(  75), INT8_C(  84), INT8_C( -79), INT8_C( 113),
                           INT8_C( -44), INT8_C( 119), INT8_C( -99), INT8_C(  -4),
                           INT8_C(  89), INT8_C(-108), INT8_C( -20), INT8_C(  38),
                           INT8_C(  62), INT8_C(-115), INT8_C( -29), INT8_C(  -6),
                           INT8_C( 109), INT8_C(  49), INT8_C( 126), INT8_C(  76),
                           INT8_C(  52), INT8_C( -99), INT8_C(  65), INT8_C(  -6),
                           INT8_C( -62), INT8_C( -30), INT8_C( 123), INT8_C(-120),
                           INT8_C( 125), INT8_C( -67), INT8_C(  19), INT8_C( -96),
                           INT8_C( -23), INT8_C(-114), INT8_C( -85), INT8_C(  24),
                           INT8_C( -96), INT8_C(  27), INT8_C( 107), INT8_C( -48),
                           INT8_C(  68), INT8_C(  79), INT8_C(-118), INT8_C(  69),
                           INT8_C(-100), INT8_C(  45), INT8_C(-127), INT8_C( -25),
                           INT8_C(   9), INT8_C( -99), INT8_C( -49), INT8_C(  57),
                           INT8_C( -33), INT8_C( -74), INT8_C(  36), INT8_C( -16),
                           INT8_C(   9), INT8_C(-119), INT8_C( -47), INT8_C( -40),
                           INT8_C(   1), INT8_C(-104), INT8_C( -83), INT8_C( -86)),
      UINT64_C( 3127474882530209143) },
    { simde_mm512_set_epi8(INT8_C( -83), INT8_C(  52), INT8_C(-122), INT8_C(  -1),
                           INT8_C( -37), INT8_C( -46), INT8_C( -20), INT8_C( -41),
                           INT8_C( -29), INT8_C( -98), INT8_C( -38), INT8_C( 119),
                           INT8_C( -30), INT8_C( -12), INT8_C(  38), INT8_C(   8),
                           INT8_C( -90), INT8_C( -98), INT8_C(  69), INT8_C(  44),
                           INT8_C( -98), INT8_C(  64), INT8_C(-113), INT8_C(  32),
                           INT8_C( -82), INT8_C(  31), INT8_C( -61), INT8_C(  74),
                           INT8_C(  55), INT8_C(  19), INT8_C( -15), INT8_C( -10),
                           INT8_C(  24), INT8_C(  71), INT8_C( -97), INT8_C( -89),
                           INT8_C(-113), INT8_C( -22), INT8_C(   7), INT8_C( -79),
                           INT8_C( 106), INT8_C(  -5), INT8_C(  74), INT8_C( -28),
                           INT8_C(-121), INT8_C( -90), INT8_C( -60), INT8_C( -53),
                           INT8_C(   0), INT8_C(-112), INT8_C( -95), INT8_C( 115),
                           INT8_C(-101), INT8_C(  14), INT8_C(-105), INT8_C( -35),
                           INT8_C(-121), INT8_C(  -9), INT8_C( 105), INT8_C(  14),
                           INT8_C(  36), INT8_C( 103), INT8_C( -76), INT8_C(  42)),
      UINT64_C(13829651358206094274) },
    { simde_mm512_set_epi8(INT8_C( -71), INT8_C( -56), INT8_C( -76), INT8_C(  52),
                           INT8_C(  20), INT8_C(-117), INT8_C( -18), INT8_C(-112),
                           INT8_C(  87), INT8_C(-104), INT8_C( 127), INT8_C(  76),
                           INT8_C(  77), INT8_C(  75), INT8_C( -19), INT8_C( -45),
                           INT8_C( -26), INT8_C( -13), INT8_C(  75), INT8_C( -95),
                           INT8_C(  -9), INT8_C(  77), INT8_C( -48), INT8_C( -15),
                           INT8_C( -67), INT8_C(  74), INT8_C(-118), INT8_C( -27),
                           INT8_C(  55), INT8_C( -43), INT8_C(  66), INT8_C(  14),
                           INT8_C(  -1), INT8_C(-106), INT8_C(-103), INT8_C(  31),
                           INT8_C( 121), INT8_C( -29), INT8_C(-102), INT8_C( -49),
                           INT8_C(  83), INT8_C( 107), INT8_C( 108), INT8_C(   3),
                           INT8_C(  22), INT8_C(   3), INT8_C( -29), INT8_C( -27),
                           INT8_C( 120), INT8_C( -58), INT8_C( 125), INT8_C(   0),
                           INT8_C(  -9), INT8_C(  -3), INT8_C(  15), INT8_C( -66),
                           INT8_C( -51), INT8_C( 101), INT8_C(  34), INT8_C( 126),
                           INT8_C(-112), INT8_C(-122), INT8_C(  95), INT8_C(  48)),
      UINT64_C(16664404616217316748) },
    { simde_mm512_set_epi8(INT8_C(-116), INT8_C(-100), INT8_C( -34), INT8_C(-123),
                           INT8_C( -47), INT8_C( -44), INT8_C( 113), INT8_C( -91),
                           INT8_C(  58), INT8_C( -81), INT8_C( -77), INT8_C( -24),
                           INT8_C(  21), INT8_C( -62), INT8_C(-107), INT8_C( 106),
                           INT8_C(-106), INT8_C( 105), INT8_C(  13), INT8_C(-125),
                           INT8_C( -31), INT8_C(  28), INT8_C( -32), INT8_C( -10),
                           INT8_C(  15), INT8_C(  23), INT8_C(  39), INT8_C(  16),
                           INT8_C( 122), INT8_C(  67), INT8_C(  -7), INT8_C(  68),
                           INT8_C( 116), INT8_C( -71), INT8_C( -82), INT8_C( -91),
                           INT8_C( -59), INT8_C( -18), INT8_C(-128), INT8_C(  16),
                           INT8_C( -63), INT8_C( 127), INT8_C( -98), INT8_C(  94),
                           INT8_C(  -2), INT8_C( -80), INT8_C( -35), INT8_C( -93),
                           INT8_C(  -5), INT8_C(   3), INT8_C( 126), INT8_C(  13),
                           INT8_C( -63), INT8_C(  43), INT8_C(  49), INT8_C(  77),
                           INT8_C(  30), INT8_C(  66), INT8_C(  35), INT8_C(-127),
                           INT8_C(  78), INT8_C(  40), INT8_C(   5), INT8_C(  66)),
      UINT64_C(18263955773865297936) },
    { simde_mm512_set_epi8(INT8_C( -92), INT8_C( -13), INT8_C(  48), INT8_C(  12),
                           INT8_C(  95), INT8_C(  98), INT8_C( 122), INT8_C( 111),
                           INT8_C(  27), INT8_C( -60), INT8_C( -86), INT8_C( -36),
                           INT8_C(  67), INT8_C(  45), INT8_C(  28), INT8_C(  89),
                           INT8_C(  36), INT8_C( -13), INT8_C( -96), INT8_C(  48),
                           INT8_C(  88), INT8_C(   9), INT8_C( -73), INT8_C(  80),
                           INT8_C( -52), INT8_C(-107), INT8_C( -78), INT8_C(  89),
                           INT8_C(-100), INT8_C( -11), INT8_C( 124), INT8_C(  50),
                           INT8_C(  52), INT8_C(  14), INT8_C(  84), INT8_C(  75),
                           INT8_C( -26), INT8_C(  56), INT8_C( -88), INT8_C(  97),
                           INT8_C(  48), INT8_C(  37), INT8_C(  28), INT8_C(  73),
                           INT8_C(  20), INT8_C( 113), INT8_C( -11), INT8_C(-118),
                           INT8_C( 118), INT8_C( -13), INT8_C( 119), INT8_C(  10),
                           INT8_C( 113), INT8_C(  86), INT8_C( -63), INT8_C(  67),
                           INT8_C(  52), INT8_C(  18), INT8_C(  22), INT8_C(  21),
                           INT8_C(  82), INT8_C( -77), INT8_C(  13), INT8_C(  -3)),
      UINT64_C(13866692018593546757) },
    { simde_mm512_set_epi8(INT8_C( -39), INT8_C( -32), INT8_C( -11), INT8_C(  52),
                           INT8_C(  61), INT8_C(  14), INT8_C(  35), INT8_C(  -8),
                           INT8_C(-119), INT8_C(-116), INT8_C( -41), INT8_C( -89),
                           INT8_C( -55), INT8_C( -86), INT8_C(  77), INT8_C(  46),
                           INT8_C(-121), INT8_C( -53), INT8_C( -15), INT8_C(  39),
                           INT8_C(  82), INT8_C( 120), INT8_C( -49), INT8_C(  93),
                           INT8_C( 100), INT8_C( 121), INT8_C(  31), INT8_C( -32),
                           INT8_C(  22), INT8_C( -32), INT8_C(  88), INT8_C( -52),
                           INT8_C(-102), INT8_C( -24), INT8_C(   9), INT8_C(  67),
                           INT8_C(-114), INT8_C(   4), INT8_C( 106), INT8_C(-121),
                           INT8_C( -75), INT8_C(  30), INT8_C(  16), INT8_C(  48),
                           INT8_C( 127), INT8_C(  71), INT8_C( -26), INT8_C( -22),
                           INT8_C( -63), INT8_C(  35), INT8_C( -80), INT8_C( -51),
                           INT8_C(  20), INT8_C( 120), INT8_C( 123), INT8_C(  28),
                           INT8_C(  25), INT8_C(  66), INT8_C( -14), INT8_C( -79),
                           INT8_C(  44), INT8_C(  96), INT8_C(  31), INT8_C( -24)),
      UINT64_C(16284138935867912241) },
    { simde_mm512_set_epi8(INT8_C(  -8), INT8_C(-106), INT8_C( -32), INT8_C(-125),
                           INT8_C(  -8), INT8_C(  59), INT8_C( 113), INT8_C( 106),
                           INT8_C( 124), INT8_C( 123), INT8_C( -45), INT8_C(  -6),
                           INT8_C( 110), INT8_C( -44), INT8_C( 116), INT8_C(  65),
                           INT8_C(-109), INT8_C(  54), INT8_C( -45), INT8_C(-108),
                           INT8_C( 113), INT8_C( -80), INT8_C( -25), INT8_C( -81),
                           INT8_C(  66), INT8_C(   5), INT8_C( -16), INT8_C(  69),
                           INT8_C(-120), INT8_C( 101), INT8_C(-120), INT8_C(-105),
                           INT8_C(  93), INT8_C(  26), INT8_C( 126), INT8_C( -64),
                           INT8_C( 107), INT8_C( 115), INT8_C(  -9), INT8_C(  38),
                           INT8_C(  67), INT8_C( -62), INT8_C(  22), INT8_C(  68),
                           INT8_C( -28), INT8_C( -64), INT8_C(  52), INT8_C(  39),
                           INT8_C(  38), INT8_C( -87), INT8_C(  -5), INT8_C(  99),
                           INT8_C(  33), INT8_C(   4), INT8_C(-101), INT8_C(-121),
                           INT8_C(-105), INT8_C(  71), INT8_C( -11), INT8_C( -20),
                           INT8_C(   0), INT8_C(  19), INT8_C(  16), INT8_C(-121)),
      UINT64_C(17885121415813555121) },
    { simde_mm512_set_epi8(INT8_C(-113), INT8_C(   2), INT8_C(  81), INT8_C( -78),
                           INT8_C(  -3), INT8_C(-106), INT8_C( -17), INT8_C(-117),
                           INT8_C(   2), INT8_C(  20), INT8_C(  53), INT8_C( -65),
                           INT8_C(  30), INT8_C(  26), INT8_C(  22), INT8_C(  99),
                           INT8_C(  -8), INT8_C( -85), INT8_C(  90), INT8_C( -79),
                           INT8_C( -92), INT8_C( -73), INT8_C( -12), INT8_C( -69),
                           INT8_C(  75), INT8_C(-113), INT8_C(  90), INT8_C(  28),
                           INT8_C(-109), INT8_C(-116), INT8_C(  79), INT8_C( -43),
                           INT8_C( -42), INT8_C( -70), INT8_C(  36), INT8_C( -40),
                           INT8_C(-104), INT8_C( 116), INT8_C( -91), INT8_C( -94),
                           INT8_C( 104), INT8_C( -96), INT8_C(  80), INT8_C( -49),
                           INT8_C(   7), INT8_C(  18), INT8_C(  11), INT8_C(  65),
                           INT8_C( -67), INT8_C(  98), INT8_C(  11), INT8_C( -90),
                           INT8_C( 109), INT8_C(-116), INT8_C( 101), INT8_C(  94),
                           INT8_C(  56), INT8_C( -34), INT8_C(  49), INT8_C(  75),
                           INT8_C(  63), INT8_C(-104), INT8_C(-118), INT8_C( -65)),
      UINT64_C(11461906577142879303) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__mmask64 r = simde_mm512_movepi8_mask(test_vec[i].a);
    simde_assert_mmask64(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm512_movepi16_mask(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m512i a;
    simde__mmask32 r;
  } test_vec[8] = {
    { simde_mm512_set_epi16(INT16_C(-17047), INT16_C(-27489), INT16_C(-15227), INT16_C( 31130),
                            INT16_C(  7900), INT16_C(  4229), INT16_C( 19494), INT16_C(  -313),
                            INT16_C( -7407), INT16_C(  6880), INT16_C( 31932), INT16_C(-13004),
                            INT16_C(-16593), INT16_C( 30037), INT16_C( 23370), INT16_C(-27033),
                            INT16_C( -6275), INT16_C(-24391), INT16_C( 19922), INT16_C(  9007),
                            INT16_C(-32282), INT16_C( 30675), INT16_C(-23274), INT16_C(-21419),
                            INT16_C( 30850), INT16_C(-11557), INT16_C(-13740), INT16_C(  3686),
                            INT16_C( 25062), INT16_C( -6498), INT16_C(-22187), INT16_C(  3349)),
      UINT32_C(3784952678) },
    { simde_mm512_set_epi16(INT16_C( 13923), INT16_C( 27595), INT16_C(-30758), INT16_C(  6795),
                            INT16_C( 23230), INT16_C( 13435), INT16_C( 30013), INT16_C(  -139),
                            INT16_C(-20677), INT16_C( 11858), INT16_C(  8955), INT16_C( 19017),
                            INT16_C(   604), INT16_C(-27923), INT16_C( -6277), INT16_C(-19699),
                            INT16_C( 25596), INT16_C( -5717), INT16_C(-26964), INT16_C( 16652),
                            INT16_C( 24642), INT16_C( 18959), INT16_C(-25136), INT16_C( -8754),
                            INT16_C( -5203), INT16_C(-23370), INT16_C(-26802), INT16_C(-30926),
                            INT16_C( 20471), INT16_C(-28596), INT16_C(-19925), INT16_C( 29562)),
      UINT32_C(562521078) },
    { simde_mm512_set_epi16(INT16_C(  1548), INT16_C( -4457), INT16_C( 28166), INT16_C(-19674),
                            INT16_C(  -618), INT16_C(-20513), INT16_C(-19054), INT16_C( -9253),
                            INT16_C(-13318), INT16_C( -7485), INT16_C( 29771), INT16_C( 24344),
                            INT16_C(  7181), INT16_C(-19395), INT16_C(-25613), INT16_C(-15382),
                            INT16_C( 11288), INT16_C( 15682), INT16_C( 21669), INT16_C( 20625),
                            INT16_C( 29057), INT16_C( -8121), INT16_C( -5440), INT16_C(  3057),
                            INT16_C( -7315), INT16_C(-18718), INT16_C(-26828), INT16_C( -6341),
                            INT16_C( -6106), INT16_C( -2348), INT16_C( 30905), INT16_C(-10037)),
      UINT32_C(1606878973) },
    { simde_mm512_set_epi16(INT16_C( 14148), INT16_C( 31053), INT16_C(-19743), INT16_C(-19340),
                            INT16_C(-12275), INT16_C( 27369), INT16_C(-24803), INT16_C(  5116),
                            INT16_C(-16383), INT16_C( 28006), INT16_C(-24294), INT16_C(-24984),
                            INT16_C( 12919), INT16_C(-17951), INT16_C( 31664), INT16_C(  7912),
                            INT16_C( 12196), INT16_C(-27188), INT16_C( 23535), INT16_C(-31330),
                            INT16_C(-27343), INT16_C( 14195), INT16_C(  5995), INT16_C( 10459),
                            INT16_C( 12832), INT16_C( 13655), INT16_C(-20140), INT16_C(-26343),
                            INT16_C(-13772), INT16_C( -9475), INT16_C(-28427), INT16_C(-11691)),
      UINT32_C(984897599) },
    { simde_mm512_set_epi16(INT16_C(-22300), INT16_C(-10421), INT16_C( -5153), INT16_C(  5119),
                            INT16_C( 12821), INT16_C( 17382), INT16_C( -4532), INT16_C(-11640),
                            INT16_C( -1430), INT16_C( 18534), INT16_C( -8310), INT16_C(-13530),
                            INT16_C( 24972), INT16_C(-18125), INT16_C( 24561), INT16_C( -2389),
                            INT16_C(-27012), INT16_C(-15171), INT16_C( 25076), INT16_C( 17208),
                            INT16_C(-10726), INT16_C(-14428), INT16_C( 18609), INT16_C( 16453),
                            INT16_C( 17590), INT16_C(   596), INT16_C(  5139), INT16_C(-28922),
                            INT16_C(-14748), INT16_C(-14808), INT16_C( 29503), INT16_C( 18271)),
      UINT32_C(3820342300) },
    { simde_mm512_set_epi16(INT16_C( -1922), INT16_C( 28045), INT16_C(  7072), INT16_C( -6655),
                            INT16_C(-10335), INT16_C(  3620), INT16_C(-24526), INT16_C( 22370),
                            INT16_C( 21531), INT16_C( 30935), INT16_C(  8939), INT16_C(-11772),
                            INT16_C( 17436), INT16_C(  5814), INT16_C(-22069), INT16_C( 15046),
                            INT16_C(  4673), INT16_C( 28770), INT16_C(   154), INT16_C(  3548),
                            INT16_C(-13962), INT16_C(-26257), INT16_C(  -315), INT16_C( 21241),
                            INT16_C( -5135), INT16_C(  2068), INT16_C(  4376), INT16_C(-32178),
                            INT16_C( 14170), INT16_C( -3876), INT16_C( 30653), INT16_C( 15729)),
      UINT32_C(2584874644) },
    { simde_mm512_set_epi16(INT16_C( 10719), INT16_C( 25050), INT16_C(-15358), INT16_C( -1679),
                            INT16_C(-13098), INT16_C(-28834), INT16_C( -9407), INT16_C(  1027),
                            INT16_C( -8964), INT16_C( 27458), INT16_C( 16082), INT16_C( 12178),
                            INT16_C(  1218), INT16_C(-18769), INT16_C(-25942), INT16_C(-28951),
                            INT16_C( 25249), INT16_C(-28972), INT16_C(-23822), INT16_C( 15695),
                            INT16_C( 24838), INT16_C( -7902), INT16_C( 17882), INT16_C( -8203),
                            INT16_C(-28681), INT16_C( -7333), INT16_C( 30548), INT16_C(-23603),
                            INT16_C( 15565), INT16_C(-21742), INT16_C( 12497), INT16_C( -3539)),
      UINT32_C(1049060821) },
    { simde_mm512_set_epi16(INT16_C( 27841), INT16_C(  5697), INT16_C( 21581), INT16_C(-21663),
                            INT16_C(-31814), INT16_C( 15339), INT16_C(-24806), INT16_C( 28625),
                            INT16_C( -2580), INT16_C(-27637), INT16_C( 20611), INT16_C( 26105),
                            INT16_C( 20780), INT16_C( 32638), INT16_C( 17822), INT16_C( 21576),
                            INT16_C( 16865), INT16_C(-18111), INT16_C( -8939), INT16_C(-14679),
                            INT16_C(-25963), INT16_C( -8164), INT16_C( -7364), INT16_C( 13563),
                            INT16_C(  4030), INT16_C(-20513), INT16_C(-30065), INT16_C(-30263),
                            INT16_C( 23452), INT16_C(  9713), INT16_C(-23717), INT16_C( -7690)),
      UINT32_C(448822899) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__mmask32 r = simde_mm512_movepi16_mask(test_vec[i].a);
    simde_assert_mmask32(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm512_movepi32_mask(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m512i a;
    simde__mmask16 r;
  } test_vec[8] = {
    { simde_mm512_set_epi32(INT32_C(  949963630), INT32_C( 1064968775), INT32_C(-1905189849), INT32_C(-1560216302),
                            INT32_C(-1667094448), INT32_C( 1432096084), INT32_C(  614973119), INT32_C( -938109633),
                            INT32_C( -573293838), INT32_C(-1613148160), INT32_C(  914563081), INT32_C( -664378047),
                            INT32_C(  580894207), INT32_C(   -5278152), INT32_C(-1290389695), INT32_C( 1268875821)),
      UINT16_C(14806) },
    { simde_mm512_set_epi32(INT32_C( 1744063513), INT32_C(  199551019), INT32_C( 2145427118), INT32_C( 2117462748),
                            INT32_C(-1526152394), INT32_C(-1859380110), INT32_C(-2006621963), INT32_C( 1533584129),
                            INT32_C(   86408218), INT32_C( 1744524288), INT32_C( 1245749395), INT32_C( 2117755472),
                            INT32_C( 1319846799), INT32_C(  684013019), INT32_C( -958932880), INT32_C(-1652765619)),
      UINT16_C(3587) },
    { simde_mm512_set_epi32(INT32_C( -357876242), INT32_C(-1625926758), INT32_C(-2123740483), INT32_C( -660511291),
                            INT32_C(-1776054627), INT32_C(  141209285), INT32_C(-1246421832), INT32_C( 1688546782),
                            INT32_C(  466911744), INT32_C( 1735300956), INT32_C(-1996452777), INT32_C( 2033250973),
                            INT32_C(  895403481), INT32_C(  890095351), INT32_C(-1050174441), INT32_C(  300665935)),
      UINT16_C(64034) },
    { simde_mm512_set_epi32(INT32_C( 1350930633), INT32_C(-2104240005), INT32_C(  -73808375), INT32_C( -223326096),
                            INT32_C(-1133084350), INT32_C(-2121661437), INT32_C( -195344417), INT32_C( -410489209),
                            INT32_C( 1846491503), INT32_C( 2122554983), INT32_C(  194022155), INT32_C(-1349250510),
                            INT32_C( 1589005094), INT32_C( -533309401), INT32_C(-1277337937), INT32_C(-1321119452)),
      UINT16_C(32535) },
    { simde_mm512_set_epi32(INT32_C(  918165817), INT32_C( 1913225422), INT32_C(-1721286233), INT32_C( 1673520973),
                            INT32_C( 1260386883), INT32_C( -845723997), INT32_C(  607206184), INT32_C(  655955271),
                            INT32_C( 1232293371), INT32_C( -686952046), INT32_C(  -38269764), INT32_C( 1897508883),
                            INT32_C(  232912531), INT32_C(  655019124), INT32_C( -684909810), INT32_C(  175412708)),
      UINT16_C(9314) },
    { simde_mm512_set_epi32(INT32_C( -167347570), INT32_C( 2106669082), INT32_C(  414695275), INT32_C( -187234329),
                            INT32_C(  687995662), INT32_C(-1870754825), INT32_C( -333242798), INT32_C(   41400550),
                            INT32_C(  956450496), INT32_C( -690912424), INT32_C(-1689027692), INT32_C( -582951840),
                            INT32_C( -348307758), INT32_C(-2091243549), INT32_C(-1450595733), INT32_C( 1635199293)),
      UINT16_C(38526) },
    { simde_mm512_set_epi32(INT32_C(  747298364), INT32_C( 1882006238), INT32_C( -996575344), INT32_C( 1843963633),
                            INT32_C(  705136482), INT32_C( 1503368131), INT32_C(-1576593524), INT32_C( 1439140790),
                            INT32_C( -402748742), INT32_C(  664771884), INT32_C(  747175899), INT32_C(  405982929),
                            INT32_C( 2131890450), INT32_C(-1594643895), INT32_C(-1014095286), INT32_C( 1590577530)),
      UINT16_C(8838) },
    { simde_mm512_set_epi32(INT32_C(  919103752), INT32_C(  840271230), INT32_C(  580240564), INT32_C(-1788774714),
                            INT32_C(  400169555), INT32_C(-1853738938), INT32_C(-1112922052), INT32_C(-1623445030),
                            INT32_C( 1270846818), INT32_C(-2065143748), INT32_C( 2058102073), INT32_C(  986096322),
                            INT32_C( 1628330811), INT32_C( 1467380999), INT32_C( -786808342), INT32_C(-1903665992)),
      UINT16_C(5955) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__mmask16 r = simde_mm512_movepi32_mask(test_vec[i].a);
    simde_assert_mmask16(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm512_movepi64_mask(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m512i a;
    simde__mmask8 r;
  } test_vec[8] = {
    { simde_mm512_set_epi64(INT64_C( 4315835916621638572), INT64_C(-6674257362849511307),
                            INT64_C(-1762049467229420749), INT64_C(-8132359750587133268),
                            INT64_C( 6148678802780014396), INT64_C( 4664933343968897426),
                            INT64_C( 1014284963407527334), INT64_C( 3422825313800233729)),
      UINT8_C(112) },
    { simde_mm512_set_epi64(INT64_C(  574478659121970685), INT64_C(-6605171674412584848),
                            INT64_C( 4638820310774021553), INT64_C( 7174745169641818539),
                            INT64_C( 7314921907136775571), INT64_C(-2641502309573857208),
                            INT64_C( 6620802922844884113), INT64_C(-7711278827686512216)),
      UINT8_C(69) },
    { simde_mm512_set_epi64(INT64_C(-6147235395367117233), INT64_C( 6542122732864503940),
                            INT64_C(-4893279094642154374), INT64_C( -710603276995935312),
                            INT64_C(-6985907794246737252), INT64_C(-2323934421260723283),
                            INT64_C( 2081892758864471809), INT64_C(-1783091129455251103)),
      UINT8_C(189) },
    { simde_mm512_set_epi64(INT64_C(-7008686659697006374), INT64_C(-2302187120743568504),
                            INT64_C(-7431666373478318054), INT64_C(-1666370852874022248),
                            INT64_C(-5526045067730894819), INT64_C(-5366397760872850523),
                            INT64_C(-8148401067962473275), INT64_C( 6379593722474677948)),
      UINT8_C(254) },
    { simde_mm512_set_epi64(INT64_C( 5834225915365902233), INT64_C( 5212224477281615403),
                            INT64_C(-9044565203383400851), INT64_C(-7453762113383947542),
                            INT64_C( 7219309658228626013), INT64_C(-5724922725847615845),
                            INT64_C( 4784587912595387278), INT64_C( 2886700108880873396)),
      UINT8_C(52) },
    { simde_mm512_set_epi64(INT64_C( 1408273437008202704), INT64_C(-3431263432981659490),
                            INT64_C( -308854217089784545), INT64_C(-4251857914359021805),
                            INT64_C( 5524011446548464963), INT64_C( 7842350355250917332),
                            INT64_C( 1150922164682347155), INT64_C(-6938335843482793568)),
      UINT8_C(113) },
    { simde_mm512_set_epi64(INT64_C( 3466369033061057719), INT64_C( -853883159898808651),
                            INT64_C(-8837301080476701753), INT64_C( 1624970283957331834),
                            INT64_C( 8454378025299498630), INT64_C(-4025270946591081596),
                            INT64_C( 1760420628646065087), INT64_C(-7311372421099691274)),
      UINT8_C(101) },
    { simde_mm512_set_epi64(INT64_C( 6360525706956998040), INT64_C(-9084014240271266814),
                            INT64_C(-5488573213012393938), INT64_C( 9146279599643928313),
                            INT64_C(-2309198113695918692), INT64_C( 7647503988947974660),
                            INT64_C( -340783369849195617), INT64_C(-7174097298174507843)),
      UINT8_C(107) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__mmask8 r = simde_mm512_movepi64_mask(test_vec[i].a);
    simde_assert_mmask8(r, ==, test_vec[i].r);
  }

  return 0;
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_movepi8_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_movepi16_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_movepi32_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_movepi64_mask)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/avx512/test-avx512-footer.h>
