/* Copyright (c) 2019 Evan Nemerson <evan@nemerson.com>
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

#define SIMDE_TESTS_CURRENT_NEON_OP sub
#include <test/arm/neon/test-neon-internal.h>
#include <simde/arm/neon.h>

#if defined(SIMDE_NEON_NATIVE) || defined(SIMDE_NO_NATIVE) || defined(SIMDE_ALWAYS_BUILD_NATIVE_TESTS)

static MunitResult
test_simde_vsub_s8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_int8x8_t a;
    simde_int8x8_t b;
    simde_int8x8_t r;
  } test_vec[8] = {
    { simde_x_vload_s8(INT8_C( -37), INT8_C( -36), INT8_C(   2), INT8_C( -96),
                       INT8_C( -72), INT8_C( -93), INT8_C(   9), INT8_C( -71)),
      simde_x_vload_s8(INT8_C(  96), INT8_C( 106), INT8_C(  75), INT8_C( -96),
                       INT8_C(  -4), INT8_C(  44), INT8_C(  38), INT8_C( -45)),
      simde_x_vload_s8(INT8_C( 123), INT8_C( 114), INT8_C( -73), INT8_C(   0),
                       INT8_C( -68), INT8_C( 119), INT8_C( -29), INT8_C( -26)) },
    { simde_x_vload_s8(INT8_C(  -5), INT8_C( -33), INT8_C( -73), INT8_C(  22),
                       INT8_C( -99), INT8_C(  42), INT8_C( -15), INT8_C( -34)),
      simde_x_vload_s8(INT8_C( -51), INT8_C( 115), INT8_C( -77), INT8_C(  61),
                       INT8_C( -66), INT8_C(  -1), INT8_C(  14), INT8_C(  29)),
      simde_x_vload_s8(INT8_C(  46), INT8_C( 108), INT8_C(   4), INT8_C( -39),
                       INT8_C( -33), INT8_C(  43), INT8_C( -29), INT8_C( -63)) },
    { simde_x_vload_s8(INT8_C(-128), INT8_C( -74), INT8_C(   5), INT8_C(  28),
                       INT8_C(  66), INT8_C(  15), INT8_C(  84), INT8_C(  57)),
      simde_x_vload_s8(INT8_C(  85), INT8_C(  -7), INT8_C(-111), INT8_C( 127),
                       INT8_C(  29), INT8_C( -36), INT8_C( -49), INT8_C( -64)),
      simde_x_vload_s8(INT8_C(  43), INT8_C( -67), INT8_C( 116), INT8_C( -99),
                       INT8_C(  37), INT8_C(  51), INT8_C(-123), INT8_C( 121)) },
    { simde_x_vload_s8(INT8_C(   6), INT8_C(  80), INT8_C(  98), INT8_C(  -1),
                       INT8_C( -72), INT8_C( 127), INT8_C( -21), INT8_C( 102)),
      simde_x_vload_s8(INT8_C( -66), INT8_C(  79), INT8_C( -10), INT8_C( 116),
                       INT8_C(-109), INT8_C( -89), INT8_C(  86), INT8_C( -70)),
      simde_x_vload_s8(INT8_C(  72), INT8_C(   1), INT8_C( 108), INT8_C(-117),
                       INT8_C(  37), INT8_C( -40), INT8_C(-107), INT8_C( -84)) },
    { simde_x_vload_s8(INT8_C(  44), INT8_C(   7), INT8_C(   4), INT8_C( -21),
                       INT8_C(  60), INT8_C(  93), INT8_C(  58), INT8_C(  62)),
      simde_x_vload_s8(INT8_C( -23), INT8_C(  75), INT8_C( -67), INT8_C(  92),
                       INT8_C(  17), INT8_C( 100), INT8_C(  61), INT8_C(  28)),
      simde_x_vload_s8(INT8_C(  67), INT8_C( -68), INT8_C(  71), INT8_C(-113),
                       INT8_C(  43), INT8_C(  -7), INT8_C(  -3), INT8_C(  34)) },
    { simde_x_vload_s8(INT8_C( -94), INT8_C( -96), INT8_C(  -5), INT8_C( -70),
                       INT8_C(  60), INT8_C( 114), INT8_C( -44), INT8_C(  -9)),
      simde_x_vload_s8(INT8_C(-122), INT8_C(  42), INT8_C(  92), INT8_C(  96),
                       INT8_C(  37), INT8_C( 121), INT8_C(   9), INT8_C( -91)),
      simde_x_vload_s8(INT8_C(  28), INT8_C( 118), INT8_C( -97), INT8_C(  90),
                       INT8_C(  23), INT8_C(  -7), INT8_C( -53), INT8_C(  82)) },
    { simde_x_vload_s8(INT8_C(  28), INT8_C( -81), INT8_C( -40), INT8_C(-110),
                       INT8_C(  63), INT8_C(  82), INT8_C( -67), INT8_C(   7)),
      simde_x_vload_s8(INT8_C( 119), INT8_C(   6), INT8_C(  56), INT8_C(  11),
                       INT8_C( -13), INT8_C( 100), INT8_C(-108), INT8_C(-115)),
      simde_x_vload_s8(INT8_C( -91), INT8_C( -87), INT8_C( -96), INT8_C(-121),
                       INT8_C(  76), INT8_C( -18), INT8_C(  41), INT8_C( 122)) },
    { simde_x_vload_s8(INT8_C( 106), INT8_C( -74), INT8_C(  24), INT8_C( -79),
                       INT8_C(  -4), INT8_C( -55), INT8_C(  90), INT8_C(  10)),
      simde_x_vload_s8(INT8_C(  80), INT8_C(  78), INT8_C(  34), INT8_C( -48),
                       INT8_C(  99), INT8_C(-115), INT8_C(  91), INT8_C(  66)),
      simde_x_vload_s8(INT8_C(  26), INT8_C( 104), INT8_C( -10), INT8_C( -31),
                       INT8_C(-103), INT8_C(  60), INT8_C(  -1), INT8_C( -56)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_int8x8_t r = simde_vsub_s8(test_vec[i].a, test_vec[i].b);
    simde_neon_assert_int8x8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_vsub_s16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_int16x4_t a;
    simde_int16x4_t b;
    simde_int16x4_t r;
  } test_vec[8] = {
    { simde_x_vload_s16(INT16_C(-14111), INT16_C( 18824), INT16_C(-21849), INT16_C(  4616)),
      simde_x_vload_s16(INT16_C(  5795), INT16_C(  7143), INT16_C(  5812), INT16_C(   196)),
      simde_x_vload_s16(INT16_C(-19906), INT16_C( 11681), INT16_C(-27661), INT16_C(  4420)) },
    { simde_x_vload_s16(INT16_C( 22250), INT16_C( -1040), INT16_C( 15496), INT16_C( -2604)),
      simde_x_vload_s16(INT16_C( 27298), INT16_C( 16152), INT16_C( -1313), INT16_C( 31117)),
      simde_x_vload_s16(INT16_C( -5048), INT16_C(-17192), INT16_C( 16809), INT16_C( 31815)) },
    { simde_x_vload_s16(INT16_C( 16667), INT16_C( -6715), INT16_C( -3312), INT16_C( 14904)),
      simde_x_vload_s16(INT16_C(-13864), INT16_C( 18124), INT16_C( 31980), INT16_C(-16639)),
      simde_x_vload_s16(INT16_C( 30531), INT16_C(-24839), INT16_C( 30244), INT16_C( 31543)) },
    { simde_x_vload_s16(INT16_C(-13624), INT16_C( 15318), INT16_C(-16753), INT16_C(  5361)),
      simde_x_vload_s16(INT16_C(  -997), INT16_C(  7636), INT16_C( 23352), INT16_C( -4061)),
      simde_x_vload_s16(INT16_C(-12627), INT16_C(  7682), INT16_C( 25431), INT16_C(  9422)) },
    { simde_x_vload_s16(INT16_C( 17298), INT16_C( 20617), INT16_C(-15704), INT16_C( 20998)),
      simde_x_vload_s16(INT16_C( -5243), INT16_C(-23055), INT16_C( 11286), INT16_C( 22862)),
      simde_x_vload_s16(INT16_C( 22541), INT16_C(-21864), INT16_C(-26990), INT16_C( -1864)) },
    { simde_x_vload_s16(INT16_C( -8125), INT16_C( 17253), INT16_C(-22390), INT16_C( -1004)),
      simde_x_vload_s16(INT16_C( 20202), INT16_C( 22564), INT16_C( 26065), INT16_C( 31272)),
      simde_x_vload_s16(INT16_C(-28327), INT16_C( -5311), INT16_C( 17081), INT16_C(-32276)) },
    { simde_x_vload_s16(INT16_C( 19932), INT16_C(   743), INT16_C( 22659), INT16_C( 15104)),
      simde_x_vload_s16(INT16_C( 11972), INT16_C(  6408), INT16_C(-27074), INT16_C(  4793)),
      simde_x_vload_s16(INT16_C(  7960), INT16_C( -5665), INT16_C(-15803), INT16_C( 10311)) },
    { simde_x_vload_s16(INT16_C( 13977), INT16_C( 18898), INT16_C(-13590), INT16_C(-20807)),
      simde_x_vload_s16(INT16_C(-25522), INT16_C( -7382), INT16_C(-22841), INT16_C( -5401)),
      simde_x_vload_s16(INT16_C(-26037), INT16_C( 26280), INT16_C(  9251), INT16_C(-15406)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_int16x4_t r = simde_vsub_s16(test_vec[i].a, test_vec[i].b);
    simde_neon_assert_int16x4(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_vsub_s32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_int32x2_t a;
    simde_int32x2_t b;
    simde_int32x2_t r;
  } test_vec[8] = {
    { simde_x_vload_s32(INT32_C( 1984799789), INT32_C( 1614293491)),
      simde_x_vload_s32(INT32_C( 1366009077), INT32_C(  624537206)),
      simde_x_vload_s32(INT32_C(  618790712), INT32_C(  989756285)) },
    { simde_x_vload_s32(INT32_C(-1594895836), INT32_C( 2102087776)),
      simde_x_vload_s32(INT32_C( 1894603626), INT32_C(-1774211407)),
      simde_x_vload_s32(INT32_C(  805467834), INT32_C( -418668113)) },
    { simde_x_vload_s32(INT32_C(-1108372257), INT32_C(  578916545)),
      simde_x_vload_s32(INT32_C(  717783548), INT32_C(  747324151)),
      simde_x_vload_s32(INT32_C(-1826155805), INT32_C( -168407606)) },
    { simde_x_vload_s32(INT32_C( -494477761), INT32_C(   45737703)),
      simde_x_vload_s32(INT32_C( 1384114837), INT32_C( 1768395276)),
      simde_x_vload_s32(INT32_C(-1878592598), INT32_C(-1722657573)) },
    { simde_x_vload_s32(INT32_C(-1928892032), INT32_C( -625136713)),
      simde_x_vload_s32(INT32_C( -608697091), INT32_C(-1499675239)),
      simde_x_vload_s32(INT32_C(-1320194941), INT32_C(  874538526)) },
    { simde_x_vload_s32(INT32_C( -818130826), INT32_C( 1761083523)),
      simde_x_vload_s32(INT32_C(  747143995), INT32_C(  982923146)),
      simde_x_vload_s32(INT32_C(-1565274821), INT32_C(  778160377)) },
    { simde_x_vload_s32(INT32_C(  727287038), INT32_C( 1476178736)),
      simde_x_vload_s32(INT32_C(  869955011), INT32_C( 1649209025)),
      simde_x_vload_s32(INT32_C( -142667973), INT32_C( -173030289)) },
    { simde_x_vload_s32(INT32_C(  340781678), INT32_C(-1368501231)),
      simde_x_vload_s32(INT32_C( 1930912879), INT32_C( 1045548067)),
      simde_x_vload_s32(INT32_C(-1590131201), INT32_C( 1880917998)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_int32x2_t r = simde_vsub_s32(test_vec[i].a, test_vec[i].b);
    simde_neon_assert_int32x2(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_vsub_s64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_int64x1_t a;
    simde_int64x1_t b;
    simde_int64x1_t r;
  } test_vec[8] = {
    { simde_x_vload_s64(INT64_C(-4943373233697329301)),
      simde_x_vload_s64(INT64_C( 3512059779770080645)),
      simde_x_vload_s64(INT64_C(-8455433013467409946)) },
    { simde_x_vload_s64(INT64_C(-8185513873329872926)),
      simde_x_vload_s64(INT64_C( 7795236760724609678)),
      simde_x_vload_s64(INT64_C( 2465993439655069012)) },
    { simde_x_vload_s64(INT64_C(-1794875855984181891)),
      simde_x_vload_s64(INT64_C(-5326491736934413717)),
      simde_x_vload_s64(INT64_C( 3531615880950231826)) },
    { simde_x_vload_s64(INT64_C( -136055898301259445)),
      simde_x_vload_s64(INT64_C(  970507860556016427)),
      simde_x_vload_s64(INT64_C(-1106563758857275872)) },
    { simde_x_vload_s64(INT64_C( 2444272399882168566)),
      simde_x_vload_s64(INT64_C(-5872539651416703481)),
      simde_x_vload_s64(INT64_C( 8316812051298872047)) },
    { simde_x_vload_s64(INT64_C( 4263823998790759071)),
      simde_x_vload_s64(INT64_C( 7412649410322713882)),
      simde_x_vload_s64(INT64_C(-3148825411531954811)) },
    { simde_x_vload_s64(INT64_C( 8294241550524916467)),
      simde_x_vload_s64(INT64_C( 3520541369967028956)),
      simde_x_vload_s64(INT64_C( 4773700180557887511)) },
    { simde_x_vload_s64(INT64_C(-7306887266544301894)),
      simde_x_vload_s64(INT64_C(-1889250389483863155)),
      simde_x_vload_s64(INT64_C(-5417636877060438739)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_int64x1_t r = simde_vsub_s64(test_vec[i].a, test_vec[i].b);
    simde_neon_assert_int64x1(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_vsub_u8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_uint8x8_t a;
    simde_uint8x8_t b;
    simde_uint8x8_t r;
  } test_vec[8] = {
    { simde_x_vload_u8(UINT8_C(191), UINT8_C( 81), UINT8_C(127), UINT8_C(142),
                       UINT8_C(249), UINT8_C( 25), UINT8_C(123), UINT8_C( 26)),
      simde_x_vload_u8(UINT8_C( 57), UINT8_C(151), UINT8_C( 54), UINT8_C( 76),
                       UINT8_C(173), UINT8_C(145), UINT8_C(101), UINT8_C(119)),
      simde_x_vload_u8(UINT8_C(134), UINT8_C(186), UINT8_C( 73), UINT8_C( 66),
                       UINT8_C( 76), UINT8_C(136), UINT8_C( 22), UINT8_C(163)) },
    { simde_x_vload_u8(UINT8_C( 25), UINT8_C( 14), UINT8_C(148), UINT8_C(196),
                       UINT8_C(146), UINT8_C(203), UINT8_C( 88), UINT8_C( 77)),
      simde_x_vload_u8(UINT8_C( 81), UINT8_C(233), UINT8_C(126), UINT8_C(  6),
                       UINT8_C(206), UINT8_C( 23), UINT8_C( 44), UINT8_C(181)),
      simde_x_vload_u8(UINT8_C(200), UINT8_C( 37), UINT8_C( 22), UINT8_C(190),
                       UINT8_C(196), UINT8_C(180), UINT8_C( 44), UINT8_C(152)) },
    { simde_x_vload_u8(UINT8_C(233), UINT8_C( 64), UINT8_C( 17), UINT8_C(225),
                       UINT8_C(133), UINT8_C(156), UINT8_C( 24), UINT8_C( 95)),
      simde_x_vload_u8(UINT8_C(198), UINT8_C(250), UINT8_C(135), UINT8_C( 74),
                       UINT8_C(254), UINT8_C(137), UINT8_C(162), UINT8_C(168)),
      simde_x_vload_u8(UINT8_C( 35), UINT8_C( 70), UINT8_C(138), UINT8_C(151),
                       UINT8_C(135), UINT8_C( 19), UINT8_C(118), UINT8_C(183)) },
    { simde_x_vload_u8(UINT8_C(107), UINT8_C(212), UINT8_C(123), UINT8_C( 50),
                       UINT8_C(138), UINT8_C( 37), UINT8_C( 83), UINT8_C(189)),
      simde_x_vload_u8(UINT8_C(221), UINT8_C( 69), UINT8_C(171), UINT8_C(113),
                       UINT8_C(118), UINT8_C(148), UINT8_C(175), UINT8_C( 83)),
      simde_x_vload_u8(UINT8_C(142), UINT8_C(143), UINT8_C(208), UINT8_C(193),
                       UINT8_C( 20), UINT8_C(145), UINT8_C(164), UINT8_C(106)) },
    { simde_x_vload_u8(UINT8_C(147), UINT8_C( 46), UINT8_C( 36), UINT8_C(247),
                       UINT8_C( 68), UINT8_C( 59), UINT8_C( 79), UINT8_C(177)),
      simde_x_vload_u8(UINT8_C(146), UINT8_C(254), UINT8_C(116), UINT8_C(172),
                       UINT8_C( 23), UINT8_C(132), UINT8_C( 55), UINT8_C( 35)),
      simde_x_vload_u8(UINT8_C(  1), UINT8_C( 48), UINT8_C(176), UINT8_C( 75),
                       UINT8_C( 45), UINT8_C(183), UINT8_C( 24), UINT8_C(142)) },
    { simde_x_vload_u8(UINT8_C( 73), UINT8_C(145), UINT8_C(242), UINT8_C(203),
                       UINT8_C(228), UINT8_C( 74), UINT8_C(  0), UINT8_C(236)),
      simde_x_vload_u8(UINT8_C(157), UINT8_C(243), UINT8_C(159), UINT8_C( 43),
                       UINT8_C(247), UINT8_C( 45), UINT8_C(197), UINT8_C(248)),
      simde_x_vload_u8(UINT8_C(172), UINT8_C(158), UINT8_C( 83), UINT8_C(160),
                       UINT8_C(237), UINT8_C( 29), UINT8_C( 59), UINT8_C(244)) },
    { simde_x_vload_u8(UINT8_C( 55), UINT8_C(  2), UINT8_C( 33), UINT8_C(112),
                       UINT8_C(107), UINT8_C( 62), UINT8_C( 81), UINT8_C( 25)),
      simde_x_vload_u8(UINT8_C(  5), UINT8_C( 46), UINT8_C(  9), UINT8_C( 55),
                       UINT8_C(137), UINT8_C(243), UINT8_C( 41), UINT8_C( 14)),
      simde_x_vload_u8(UINT8_C( 50), UINT8_C(212), UINT8_C( 24), UINT8_C( 57),
                       UINT8_C(226), UINT8_C( 75), UINT8_C( 40), UINT8_C( 11)) },
    { simde_x_vload_u8(UINT8_C(214), UINT8_C( 35), UINT8_C( 24), UINT8_C(152),
                       UINT8_C(249), UINT8_C(211), UINT8_C( 34), UINT8_C(148)),
      simde_x_vload_u8(UINT8_C(132), UINT8_C(174), UINT8_C(198), UINT8_C(119),
                       UINT8_C( 15), UINT8_C( 53), UINT8_C(142), UINT8_C(101)),
      simde_x_vload_u8(UINT8_C( 82), UINT8_C(117), UINT8_C( 82), UINT8_C( 33),
                       UINT8_C(234), UINT8_C(158), UINT8_C(148), UINT8_C( 47)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_uint8x8_t r = simde_vsub_u8(test_vec[i].a, test_vec[i].b);
    simde_neon_assert_uint8x8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_vsub_u16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_uint16x4_t a;
    simde_uint16x4_t b;
    simde_uint16x4_t r;
  } test_vec[8] = {
    { simde_x_vload_u16(UINT16_C(48223), UINT16_C(50867), UINT16_C(48082), UINT16_C( 2665)),
      simde_x_vload_u16(UINT16_C(59993), UINT16_C(42266), UINT16_C(10432), UINT16_C(44082)),
      simde_x_vload_u16(UINT16_C(53766), UINT16_C( 8601), UINT16_C(37650), UINT16_C(24119)) },
    { simde_x_vload_u16(UINT16_C(24941), UINT16_C(47948), UINT16_C(11907), UINT16_C(36303)),
      simde_x_vload_u16(UINT16_C( 7815), UINT16_C(10383), UINT16_C(29405), UINT16_C(61652)),
      simde_x_vload_u16(UINT16_C(17126), UINT16_C(37565), UINT16_C(48038), UINT16_C(40187)) },
    { simde_x_vload_u16(UINT16_C(28462), UINT16_C( 9248), UINT16_C( 6523), UINT16_C(25838)),
      simde_x_vload_u16(UINT16_C(30404), UINT16_C(21387), UINT16_C(51331), UINT16_C(27661)),
      simde_x_vload_u16(UINT16_C(63594), UINT16_C(53397), UINT16_C(20728), UINT16_C(63713)) },
    { simde_x_vload_u16(UINT16_C( 9599), UINT16_C( 6357), UINT16_C(47695), UINT16_C(27046)),
      simde_x_vload_u16(UINT16_C(38129), UINT16_C(64014), UINT16_C(48035), UINT16_C(13887)),
      simde_x_vload_u16(UINT16_C(37006), UINT16_C( 7879), UINT16_C(65196), UINT16_C(13159)) },
    { simde_x_vload_u16(UINT16_C(44687), UINT16_C(17981), UINT16_C(31332), UINT16_C(60426)),
      simde_x_vload_u16(UINT16_C(52812), UINT16_C(44247), UINT16_C(38502), UINT16_C(30153)),
      simde_x_vload_u16(UINT16_C(57411), UINT16_C(39270), UINT16_C(58366), UINT16_C(30273)) },
    { simde_x_vload_u16(UINT16_C(42610), UINT16_C(21966), UINT16_C(41660), UINT16_C( 1960)),
      simde_x_vload_u16(UINT16_C(17066), UINT16_C(26127), UINT16_C( 1932), UINT16_C(39429)),
      simde_x_vload_u16(UINT16_C(25544), UINT16_C(61375), UINT16_C(39728), UINT16_C(28067)) },
    { simde_x_vload_u16(UINT16_C(15534), UINT16_C( 4666), UINT16_C(23694), UINT16_C( 9679)),
      simde_x_vload_u16(UINT16_C(53422), UINT16_C(13900), UINT16_C(32150), UINT16_C(31322)),
      simde_x_vload_u16(UINT16_C(27648), UINT16_C(56302), UINT16_C(57080), UINT16_C(43893)) },
    { simde_x_vload_u16(UINT16_C(15202), UINT16_C(61259), UINT16_C(46371), UINT16_C(24403)),
      simde_x_vload_u16(UINT16_C( 2026), UINT16_C(31299), UINT16_C(13786), UINT16_C(26993)),
      simde_x_vload_u16(UINT16_C(13176), UINT16_C(29960), UINT16_C(32585), UINT16_C(62946)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_uint16x4_t r = simde_vsub_u16(test_vec[i].a, test_vec[i].b);
    simde_neon_assert_uint16x4(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_vsub_u32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_uint32x2_t a;
    simde_uint32x2_t b;
    simde_uint32x2_t r;
  } test_vec[8] = {
    { simde_x_vload_u32(UINT32_C(2975214003), UINT32_C( 741963422)),
      simde_x_vload_u32(UINT32_C(1106378674), UINT32_C(2001202843)),
      simde_x_vload_u32(UINT32_C(1868835329), UINT32_C(3035727875)) },
    { simde_x_vload_u32(UINT32_C( 631537799), UINT32_C( 133948393)),
      simde_x_vload_u32(UINT32_C(2673177213), UINT32_C(2434411774)),
      simde_x_vload_u32(UINT32_C(2253327882), UINT32_C(1994503915)) },
    { simde_x_vload_u32(UINT32_C(2657161563), UINT32_C( 768269797)),
      simde_x_vload_u32(UINT32_C(3116181497), UINT32_C(1425632443)),
      simde_x_vload_u32(UINT32_C(3835947362), UINT32_C(3637604650)) },
    { simde_x_vload_u32(UINT32_C( 294243551), UINT32_C( 265814871)),
      simde_x_vload_u32(UINT32_C(2364431343), UINT32_C( 951230457)),
      simde_x_vload_u32(UINT32_C(2224779504), UINT32_C(3609551710)) },
    { simde_x_vload_u32(UINT32_C( 131983137), UINT32_C(2534419200)),
      simde_x_vload_u32(UINT32_C(3297552523), UINT32_C(1710645813)),
      simde_x_vload_u32(UINT32_C(1129397910), UINT32_C( 823773387)) },
    { simde_x_vload_u32(UINT32_C(4165452150), UINT32_C(1232131517)),
      simde_x_vload_u32(UINT32_C(1456354963), UINT32_C(3902805375)),
      simde_x_vload_u32(UINT32_C(2709097187), UINT32_C(1624293438)) },
    { simde_x_vload_u32(UINT32_C(1447604069), UINT32_C(3135348846)),
      simde_x_vload_u32(UINT32_C(4051253168), UINT32_C(1516205751)),
      simde_x_vload_u32(UINT32_C(1691318197), UINT32_C(1619143095)) },
    { simde_x_vload_u32(UINT32_C(1514440368), UINT32_C(2479035141)),
      simde_x_vload_u32(UINT32_C( 140215595), UINT32_C(2450662976)),
      simde_x_vload_u32(UINT32_C(1374224773), UINT32_C(  28372165)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_uint32x2_t r = simde_vsub_u32(test_vec[i].a, test_vec[i].b);
    simde_neon_assert_uint32x2(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_vsub_u64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_uint64x1_t a;
    simde_uint64x1_t b;
    simde_uint64x1_t r;
  } test_vec[8] = {
    { simde_x_vload_u64(UINT64_C(1936986223633213948)),
      simde_x_vload_u64(UINT64_C(8847896019390123612)),
      simde_x_vload_u64(UINT64_C(11535834277952641952)) },
    { simde_x_vload_u64(UINT64_C(10718644368272015670)),
      simde_x_vload_u64(UINT64_C(15876979127427977051)),
      simde_x_vload_u64(UINT64_C(13288409314553590235)) },
    { simde_x_vload_u64(UINT64_C(7920926281338567907)),
      simde_x_vload_u64(UINT64_C(5876662223356338855)),
      simde_x_vload_u64(UINT64_C(2044264057982229052)) },
    { simde_x_vload_u64(UINT64_C(2152545993092625936)),
      simde_x_vload_u64(UINT64_C(5968089876997405873)),
      simde_x_vload_u64(UINT64_C(14631200189804771679)) },
    { simde_x_vload_u64(UINT64_C(5384786867744097014)),
      simde_x_vload_u64(UINT64_C(5558818678212911970)),
      simde_x_vload_u64(UINT64_C(18272712263240736660)) },
    { simde_x_vload_u64(UINT64_C(6837335513581327967)),
      simde_x_vload_u64(UINT64_C( 213032869806481304)),
      simde_x_vload_u64(UINT64_C(6624302643774846663)) },
    { simde_x_vload_u64(UINT64_C(12407096746524455118)),
      simde_x_vload_u64(UINT64_C(9728709649850370960)),
      simde_x_vload_u64(UINT64_C(2678387096674084158)) },
    { simde_x_vload_u64(UINT64_C(16295407813227308533)),
      simde_x_vload_u64(UINT64_C(1567153282166012823)),
      simde_x_vload_u64(UINT64_C(14728254531061295710)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_uint64x1_t r = simde_vsub_u64(test_vec[i].a, test_vec[i].b);
    simde_neon_assert_uint64x1(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_vsub_f32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_float32x2_t a;
    simde_float32x2_t b;
    simde_float32x2_t r;
  } test_vec[8] = {
    { simde_x_vload_f32(SIMDE_FLOAT32_C( -679.55), SIMDE_FLOAT32_C( -380.07)),
      simde_x_vload_f32(SIMDE_FLOAT32_C(  -76.24), SIMDE_FLOAT32_C(  210.53)),
      simde_x_vload_f32(SIMDE_FLOAT32_C( -603.31), SIMDE_FLOAT32_C( -590.60)) },
    { simde_x_vload_f32(SIMDE_FLOAT32_C(  251.95), SIMDE_FLOAT32_C(  117.44)),
      simde_x_vload_f32(SIMDE_FLOAT32_C(  178.33), SIMDE_FLOAT32_C( -943.22)),
      simde_x_vload_f32(SIMDE_FLOAT32_C(   73.62), SIMDE_FLOAT32_C( 1060.66)) },
    { simde_x_vload_f32(SIMDE_FLOAT32_C( -913.61), SIMDE_FLOAT32_C(  734.07)),
      simde_x_vload_f32(SIMDE_FLOAT32_C(  239.65), SIMDE_FLOAT32_C( -254.71)),
      simde_x_vload_f32(SIMDE_FLOAT32_C(-1153.26), SIMDE_FLOAT32_C(  988.78)) },
    { simde_x_vload_f32(SIMDE_FLOAT32_C( -492.68), SIMDE_FLOAT32_C(  226.18)),
      simde_x_vload_f32(SIMDE_FLOAT32_C( -939.53), SIMDE_FLOAT32_C( -555.21)),
      simde_x_vload_f32(SIMDE_FLOAT32_C(  446.85), SIMDE_FLOAT32_C(  781.39)) },
    { simde_x_vload_f32(SIMDE_FLOAT32_C( -223.46), SIMDE_FLOAT32_C(  644.31)),
      simde_x_vload_f32(SIMDE_FLOAT32_C(  497.64), SIMDE_FLOAT32_C( -984.04)),
      simde_x_vload_f32(SIMDE_FLOAT32_C( -721.10), SIMDE_FLOAT32_C( 1628.35)) },
    { simde_x_vload_f32(SIMDE_FLOAT32_C( -731.48), SIMDE_FLOAT32_C(  -32.34)),
      simde_x_vload_f32(SIMDE_FLOAT32_C( -429.71), SIMDE_FLOAT32_C(  124.70)),
      simde_x_vload_f32(SIMDE_FLOAT32_C( -301.77), SIMDE_FLOAT32_C( -157.04)) },
    { simde_x_vload_f32(SIMDE_FLOAT32_C( -305.10), SIMDE_FLOAT32_C(  187.85)),
      simde_x_vload_f32(SIMDE_FLOAT32_C( -464.37), SIMDE_FLOAT32_C( -869.02)),
      simde_x_vload_f32(SIMDE_FLOAT32_C(  159.27), SIMDE_FLOAT32_C( 1056.87)) },
    { simde_x_vload_f32(SIMDE_FLOAT32_C( -311.70), SIMDE_FLOAT32_C( -825.92)),
      simde_x_vload_f32(SIMDE_FLOAT32_C(  836.51), SIMDE_FLOAT32_C(  663.00)),
      simde_x_vload_f32(SIMDE_FLOAT32_C(-1148.21), SIMDE_FLOAT32_C(-1488.92)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_float32x2_t r = simde_vsub_f32(test_vec[i].a, test_vec[i].b);
    simde_neon_assert_float32x2_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_vsub_f64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_float64x1_t a;
    simde_float64x1_t b;
    simde_float64x1_t r;
  } test_vec[8] = {
    { simde_x_vload_f64(SIMDE_FLOAT64_C(  184.84)),
      simde_x_vload_f64(SIMDE_FLOAT64_C(  696.66)),
      simde_x_vload_f64(SIMDE_FLOAT64_C( -511.82)) },
    { simde_x_vload_f64(SIMDE_FLOAT64_C(  463.00)),
      simde_x_vload_f64(SIMDE_FLOAT64_C(  280.90)),
      simde_x_vload_f64(SIMDE_FLOAT64_C(  182.10)) },
    { simde_x_vload_f64(SIMDE_FLOAT64_C(  443.58)),
      simde_x_vload_f64(SIMDE_FLOAT64_C( -388.57)),
      simde_x_vload_f64(SIMDE_FLOAT64_C(  832.15)) },
    { simde_x_vload_f64(SIMDE_FLOAT64_C(  -74.54)),
      simde_x_vload_f64(SIMDE_FLOAT64_C( -208.53)),
      simde_x_vload_f64(SIMDE_FLOAT64_C(  133.99)) },
    { simde_x_vload_f64(SIMDE_FLOAT64_C( -834.57)),
      simde_x_vload_f64(SIMDE_FLOAT64_C(   -2.20)),
      simde_x_vload_f64(SIMDE_FLOAT64_C( -832.37)) },
    { simde_x_vload_f64(SIMDE_FLOAT64_C(   48.05)),
      simde_x_vload_f64(SIMDE_FLOAT64_C(  657.05)),
      simde_x_vload_f64(SIMDE_FLOAT64_C( -609.00)) },
    { simde_x_vload_f64(SIMDE_FLOAT64_C( -559.45)),
      simde_x_vload_f64(SIMDE_FLOAT64_C( -465.28)),
      simde_x_vload_f64(SIMDE_FLOAT64_C(  -94.17)) },
    { simde_x_vload_f64(SIMDE_FLOAT64_C( -302.94)),
      simde_x_vload_f64(SIMDE_FLOAT64_C( -629.36)),
      simde_x_vload_f64(SIMDE_FLOAT64_C(  326.42)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_float64x1_t r = simde_vsub_f64(test_vec[i].a, test_vec[i].b);
    simde_neon_assert_float64x1_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_vsubq_s8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_int8x16_t a;
    simde_int8x16_t b;
    simde_int8x16_t r;
  } test_vec[8] = {
    { simde_x_vloadq_s8(INT8_C(-125), INT8_C(  49), INT8_C( -91), INT8_C(  90),
                        INT8_C(  28), INT8_C( -43), INT8_C( -55), INT8_C(  78),
                        INT8_C(-125), INT8_C(-127), INT8_C( -32), INT8_C( -71),
                        INT8_C( -73), INT8_C( -28), INT8_C( -70), INT8_C(-125)),
      simde_x_vloadq_s8(INT8_C( -94), INT8_C( 124), INT8_C( -70), INT8_C( -91),
                        INT8_C( -88), INT8_C( -40), INT8_C(  13), INT8_C(  28),
                        INT8_C( -67), INT8_C(-127), INT8_C(  83), INT8_C(-111),
                        INT8_C( 104), INT8_C(  91), INT8_C(  97), INT8_C( -60)),
      simde_x_vloadq_s8(INT8_C( -31), INT8_C( -75), INT8_C( -21), INT8_C( -75),
                        INT8_C( 116), INT8_C(  -3), INT8_C( -68), INT8_C(  50),
                        INT8_C( -58), INT8_C(   0), INT8_C(-115), INT8_C(  40),
                        INT8_C(  79), INT8_C(-119), INT8_C(  89), INT8_C( -65)) },
    { simde_x_vloadq_s8(INT8_C(  80), INT8_C(  41), INT8_C(  54), INT8_C( -74),
                        INT8_C(  49), INT8_C(   1), INT8_C(-119), INT8_C(  27),
                        INT8_C( -64), INT8_C( -86), INT8_C( -55), INT8_C( -12),
                        INT8_C( -77), INT8_C(  93), INT8_C( -63), INT8_C(-116)),
      simde_x_vloadq_s8(INT8_C(-105), INT8_C(  -2), INT8_C(  58), INT8_C( -15),
                        INT8_C( 111), INT8_C(  88), INT8_C( -97), INT8_C( -53),
                        INT8_C( -24), INT8_C( -59), INT8_C( -69), INT8_C( -56),
                        INT8_C(  60), INT8_C( 125), INT8_C(  -6), INT8_C( 113)),
      simde_x_vloadq_s8(INT8_C( -71), INT8_C(  43), INT8_C(  -4), INT8_C( -59),
                        INT8_C( -62), INT8_C( -87), INT8_C( -22), INT8_C(  80),
                        INT8_C( -40), INT8_C( -27), INT8_C(  14), INT8_C(  44),
                        INT8_C( 119), INT8_C( -32), INT8_C( -57), INT8_C(  27)) },
    { simde_x_vloadq_s8(INT8_C(  84), INT8_C( -45), INT8_C(  18), INT8_C(  47),
                        INT8_C( -79), INT8_C(  30), INT8_C( -93), INT8_C(  53),
                        INT8_C(-115), INT8_C( -90), INT8_C(  -5), INT8_C( 105),
                        INT8_C(  85), INT8_C( -95), INT8_C( -57), INT8_C(  54)),
      simde_x_vloadq_s8(INT8_C(   0), INT8_C(  17), INT8_C( -39), INT8_C( 102),
                        INT8_C(  -2), INT8_C( -94), INT8_C(  28), INT8_C(  10),
                        INT8_C( 110), INT8_C(  36), INT8_C(  54), INT8_C( -17),
                        INT8_C( 110), INT8_C( -77), INT8_C( -15), INT8_C( -82)),
      simde_x_vloadq_s8(INT8_C(  84), INT8_C( -62), INT8_C(  57), INT8_C( -55),
                        INT8_C( -77), INT8_C( 124), INT8_C(-121), INT8_C(  43),
                        INT8_C(  31), INT8_C(-126), INT8_C( -59), INT8_C( 122),
                        INT8_C( -25), INT8_C( -18), INT8_C( -42), INT8_C(-120)) },
    { simde_x_vloadq_s8(INT8_C( -95), INT8_C( -42), INT8_C(  35), INT8_C(   1),
                        INT8_C(  32), INT8_C(  18), INT8_C(  75), INT8_C( 123),
                        INT8_C(  82), INT8_C(  23), INT8_C(  27), INT8_C( -61),
                        INT8_C(  31), INT8_C( 102), INT8_C( -52), INT8_C( 105)),
      simde_x_vloadq_s8(INT8_C( -39), INT8_C( 114), INT8_C( -84), INT8_C( 102),
                        INT8_C(  49), INT8_C(-119), INT8_C(   3), INT8_C(-104),
                        INT8_C( -37), INT8_C( -97), INT8_C( -34), INT8_C(  37),
                        INT8_C(  23), INT8_C(  11), INT8_C( -54), INT8_C(  29)),
      simde_x_vloadq_s8(INT8_C( -56), INT8_C( 100), INT8_C( 119), INT8_C(-101),
                        INT8_C( -17), INT8_C(-119), INT8_C(  72), INT8_C( -29),
                        INT8_C( 119), INT8_C( 120), INT8_C(  61), INT8_C( -98),
                        INT8_C(   8), INT8_C(  91), INT8_C(   2), INT8_C(  76)) },
    { simde_x_vloadq_s8(INT8_C( -93), INT8_C(  12), INT8_C( -11), INT8_C( -43),
                        INT8_C(  52), INT8_C(-115), INT8_C( -79), INT8_C( -77),
                        INT8_C(   9), INT8_C(  42), INT8_C( -88), INT8_C( -16),
                        INT8_C( 125), INT8_C( -73), INT8_C( 104), INT8_C( -34)),
      simde_x_vloadq_s8(INT8_C(  11), INT8_C(  -5), INT8_C(  62), INT8_C( -46),
                        INT8_C(-127), INT8_C(  81), INT8_C(  54), INT8_C( -56),
                        INT8_C( -83), INT8_C(  97), INT8_C(  81), INT8_C(  -3),
                        INT8_C( -10), INT8_C( -56), INT8_C(   1), INT8_C( -80)),
      simde_x_vloadq_s8(INT8_C(-104), INT8_C(  17), INT8_C( -73), INT8_C(   3),
                        INT8_C( -77), INT8_C(  60), INT8_C( 123), INT8_C( -21),
                        INT8_C(  92), INT8_C( -55), INT8_C(  87), INT8_C( -13),
                        INT8_C(-121), INT8_C( -17), INT8_C( 103), INT8_C(  46)) },
    { simde_x_vloadq_s8(INT8_C( 127), INT8_C( 102), INT8_C( -72), INT8_C( -98),
                        INT8_C( -83), INT8_C(  33), INT8_C( -54), INT8_C( -48),
                        INT8_C( -52), INT8_C( -80), INT8_C(-116), INT8_C(  59),
                        INT8_C(  83), INT8_C(  20), INT8_C(  70), INT8_C( 112)),
      simde_x_vloadq_s8(INT8_C( -13), INT8_C(  48), INT8_C( 120), INT8_C( -86),
                        INT8_C(-109), INT8_C(  27), INT8_C( -25), INT8_C( -55),
                        INT8_C(  76), INT8_C( -35), INT8_C(  41), INT8_C(  44),
                        INT8_C( 122), INT8_C( 110), INT8_C(  81), INT8_C(  49)),
      simde_x_vloadq_s8(INT8_C(-116), INT8_C(  54), INT8_C(  64), INT8_C( -12),
                        INT8_C(  26), INT8_C(   6), INT8_C( -29), INT8_C(   7),
                        INT8_C(-128), INT8_C( -45), INT8_C(  99), INT8_C(  15),
                        INT8_C( -39), INT8_C( -90), INT8_C( -11), INT8_C(  63)) },
    { simde_x_vloadq_s8(INT8_C(  59), INT8_C(   9), INT8_C(  55), INT8_C(  73),
                        INT8_C(  81), INT8_C(  82), INT8_C(  74), INT8_C( -10),
                        INT8_C(  73), INT8_C(-112), INT8_C( -42), INT8_C( -39),
                        INT8_C(  61), INT8_C(  23), INT8_C(  31), INT8_C( 113)),
      simde_x_vloadq_s8(INT8_C( -38), INT8_C(  82), INT8_C( -46), INT8_C( -94),
                        INT8_C( 104), INT8_C( -15), INT8_C(  25), INT8_C(  76),
                        INT8_C(  66), INT8_C( -71), INT8_C(  35), INT8_C( -56),
                        INT8_C(  85), INT8_C( -52), INT8_C( 101), INT8_C( 124)),
      simde_x_vloadq_s8(INT8_C(  97), INT8_C( -73), INT8_C( 101), INT8_C( -89),
                        INT8_C( -23), INT8_C(  97), INT8_C(  49), INT8_C( -86),
                        INT8_C(   7), INT8_C( -41), INT8_C( -77), INT8_C(  17),
                        INT8_C( -24), INT8_C(  75), INT8_C( -70), INT8_C( -11)) },
    { simde_x_vloadq_s8(INT8_C(  36), INT8_C( -67), INT8_C( -53), INT8_C( 102),
                        INT8_C(-101), INT8_C(-120), INT8_C( -51), INT8_C(  96),
                        INT8_C(  51), INT8_C( -92), INT8_C(  32), INT8_C( -14),
                        INT8_C(  37), INT8_C( -19), INT8_C(   1), INT8_C( -70)),
      simde_x_vloadq_s8(INT8_C(-120), INT8_C(   2), INT8_C( 118), INT8_C(  16),
                        INT8_C(-123), INT8_C(-117), INT8_C(-105), INT8_C(  56),
                        INT8_C(  96), INT8_C( -12), INT8_C(  51), INT8_C(  97),
                        INT8_C( -87), INT8_C( -16), INT8_C( -41), INT8_C(  60)),
      simde_x_vloadq_s8(INT8_C(-100), INT8_C( -69), INT8_C(  85), INT8_C(  86),
                        INT8_C(  22), INT8_C(  -3), INT8_C(  54), INT8_C(  40),
                        INT8_C( -45), INT8_C( -80), INT8_C( -19), INT8_C(-111),
                        INT8_C( 124), INT8_C(  -3), INT8_C(  42), INT8_C( 126)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_int8x16_t r = simde_vsubq_s8(test_vec[i].a, test_vec[i].b);
    simde_neon_assert_int8x16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_vsubq_s16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_int16x8_t a;
    simde_int16x8_t b;
    simde_int16x8_t r;
  } test_vec[8] = {
    { simde_x_vloadq_s16(INT16_C( -3064), INT16_C( -6478), INT16_C(-19169), INT16_C( -8323),
                         INT16_C( 10190), INT16_C(-25337), INT16_C(  5190), INT16_C(-23585)),
      simde_x_vloadq_s16(INT16_C(-31375), INT16_C( -4312), INT16_C(-20814), INT16_C( -8615),
                         INT16_C( 20734), INT16_C( 20825), INT16_C( -2208), INT16_C(-12727)),
      simde_x_vloadq_s16(INT16_C( 28311), INT16_C( -2166), INT16_C(  1645), INT16_C(   292),
                         INT16_C(-10544), INT16_C( 19374), INT16_C(  7398), INT16_C(-10858)) },
    { simde_x_vloadq_s16(INT16_C( 31361), INT16_C( 19716), INT16_C(-25427), INT16_C(-21999),
                         INT16_C(-31976), INT16_C( 25709), INT16_C(-31293), INT16_C( 12981)),
      simde_x_vloadq_s16(INT16_C(-24370), INT16_C(-10981), INT16_C( 24886), INT16_C( 29713),
                         INT16_C(-28205), INT16_C( 26287), INT16_C( 32689), INT16_C( -6763)),
      simde_x_vloadq_s16(INT16_C( -9805), INT16_C( 30697), INT16_C( 15223), INT16_C( 13824),
                         INT16_C( -3771), INT16_C(  -578), INT16_C(  1554), INT16_C( 19744)) },
    { simde_x_vloadq_s16(INT16_C( -6586), INT16_C( 18756), INT16_C(-19800), INT16_C( -6814),
                         INT16_C(  1525), INT16_C(-17635), INT16_C(-21122), INT16_C( 29494)),
      simde_x_vloadq_s16(INT16_C(-17885), INT16_C( 13224), INT16_C( 24925), INT16_C(-20719),
                         INT16_C( -2570), INT16_C(-11542), INT16_C( 17364), INT16_C(-32054)),
      simde_x_vloadq_s16(INT16_C( 11299), INT16_C(  5532), INT16_C( 20811), INT16_C( 13905),
                         INT16_C(  4095), INT16_C( -6093), INT16_C( 27050), INT16_C( -3988)) },
    { simde_x_vloadq_s16(INT16_C( 23412), INT16_C(  2384), INT16_C(-11534), INT16_C(-20699),
                         INT16_C( -8361), INT16_C( 26604), INT16_C( -8831), INT16_C(  4802)),
      simde_x_vloadq_s16(INT16_C( 21240), INT16_C(-30954), INT16_C( -9256), INT16_C( 14852),
                         INT16_C(-31416), INT16_C(-32724), INT16_C(-10577), INT16_C(-23423)),
      simde_x_vloadq_s16(INT16_C(  2172), INT16_C(-32198), INT16_C( -2278), INT16_C( 29985),
                         INT16_C( 23055), INT16_C( -6208), INT16_C(  1746), INT16_C( 28225)) },
    { simde_x_vloadq_s16(INT16_C(-26829), INT16_C(-31551), INT16_C( 17339), INT16_C( 26030),
                         INT16_C( 18116), INT16_C( 23813), INT16_C(-29427), INT16_C(-31129)),
      simde_x_vloadq_s16(INT16_C( 11744), INT16_C(-26134), INT16_C(-32172), INT16_C( 22772),
                         INT16_C( 13692), INT16_C(-12598), INT16_C( 18660), INT16_C(  8856)),
      simde_x_vloadq_s16(INT16_C( 26963), INT16_C( -5417), INT16_C(-16025), INT16_C(  3258),
                         INT16_C(  4424), INT16_C(-29125), INT16_C( 17449), INT16_C( 25551)) },
    { simde_x_vloadq_s16(INT16_C( 27534), INT16_C(-12880), INT16_C(  1587), INT16_C( 13556),
                         INT16_C( 17408), INT16_C(-27424), INT16_C( 14128), INT16_C(-18368)),
      simde_x_vloadq_s16(INT16_C( 13780), INT16_C( 25990), INT16_C( 13539), INT16_C(  -821),
                         INT16_C( -7574), INT16_C(-19266), INT16_C( 17436), INT16_C( 13085)),
      simde_x_vloadq_s16(INT16_C( 13754), INT16_C( 26666), INT16_C(-11952), INT16_C( 14377),
                         INT16_C( 24982), INT16_C( -8158), INT16_C( -3308), INT16_C(-31453)) },
    { simde_x_vloadq_s16(INT16_C( 27183), INT16_C(  5881), INT16_C(-18942), INT16_C( 15986),
                         INT16_C(  9009), INT16_C( -2829), INT16_C(  2978), INT16_C(-16401)),
      simde_x_vloadq_s16(INT16_C(-17269), INT16_C( 32472), INT16_C(-18651), INT16_C(  6285),
                         INT16_C(-28747), INT16_C( 22516), INT16_C( 12510), INT16_C(-12894)),
      simde_x_vloadq_s16(INT16_C(-21084), INT16_C(-26591), INT16_C(  -291), INT16_C(  9701),
                         INT16_C(-27780), INT16_C(-25345), INT16_C( -9532), INT16_C( -3507)) },
    { simde_x_vloadq_s16(INT16_C( 12730), INT16_C(   147), INT16_C( 29151), INT16_C(  5069),
                         INT16_C(-32293), INT16_C( 21273), INT16_C( -9141), INT16_C(-30821)),
      simde_x_vloadq_s16(INT16_C( 19519), INT16_C(  7184), INT16_C( 29373), INT16_C( 17347),
                         INT16_C( 31501), INT16_C(-17643), INT16_C( 24181), INT16_C(    68)),
      simde_x_vloadq_s16(INT16_C( -6789), INT16_C( -7037), INT16_C(  -222), INT16_C(-12278),
                         INT16_C(  1742), INT16_C(-26620), INT16_C( 32214), INT16_C(-30889)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_int16x8_t r = simde_vsubq_s16(test_vec[i].a, test_vec[i].b);
    simde_neon_assert_int16x8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_vsubq_s32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_int32x4_t a;
    simde_int32x4_t b;
    simde_int32x4_t r;
  } test_vec[8] = {
    { simde_x_vloadq_s32(INT32_C(-1101685234), INT32_C( 1180920411),
                         INT32_C( -564596575), INT32_C( 1686309491)),
      simde_x_vloadq_s32(INT32_C(  845411365), INT32_C(  663983193),
                         INT32_C(-1054239476), INT32_C( -913377435)),
      simde_x_vloadq_s32(INT32_C(-1947096599), INT32_C(  516937218),
                         INT32_C(  489642901), INT32_C(-1695280370)) },
    { simde_x_vloadq_s32(INT32_C(-1972829951), INT32_C( -648135840),
                         INT32_C( -561565135), INT32_C( -140995998)),
      simde_x_vloadq_s32(INT32_C(  947827814), INT32_C( 1431067015),
                         INT32_C( 1239445055), INT32_C(  373088742)),
      simde_x_vloadq_s32(INT32_C( 1374309531), INT32_C(-2079202855),
                         INT32_C(-1801010190), INT32_C( -514084740)) },
    { simde_x_vloadq_s32(INT32_C(-1708152046), INT32_C(  610550290),
                         INT32_C( -275708746), INT32_C( 1930775610)),
      simde_x_vloadq_s32(INT32_C(-1432684320), INT32_C( 1920044618),
                         INT32_C(  900010268), INT32_C( -243039165)),
      simde_x_vloadq_s32(INT32_C( -275467726), INT32_C(-1309494328),
                         INT32_C(-1175719014), INT32_C(-2121152521)) },
    { simde_x_vloadq_s32(INT32_C(-1493380734), INT32_C( 1539675282),
                         INT32_C(-1665826128), INT32_C(-2085077931)),
      simde_x_vloadq_s32(INT32_C(-1899313907), INT32_C(-1453149283),
                         INT32_C( 1877171515), INT32_C( 1597838518)),
      simde_x_vloadq_s32(INT32_C(  405933173), INT32_C(-1302142731),
                         INT32_C(  751969653), INT32_C(  612050847)) },
    { simde_x_vloadq_s32(INT32_C( -247963587), INT32_C(  674028815),
                         INT32_C(  130053867), INT32_C( 1037968629)),
      simde_x_vloadq_s32(INT32_C( -299910818), INT32_C(  327709173),
                         INT32_C(  439117134), INT32_C(-1117344472)),
      simde_x_vloadq_s32(INT32_C(   51947231), INT32_C(  346319642),
                         INT32_C( -309063267), INT32_C(-2139654195)) },
    { simde_x_vloadq_s32(INT32_C( 1689129365), INT32_C( 1866705563),
                         INT32_C( 1871339308), INT32_C( 1664204744)),
      simde_x_vloadq_s32(INT32_C( -298376576), INT32_C( 1102343447),
                         INT32_C(  726874084), INT32_C(-1691749647)),
      simde_x_vloadq_s32(INT32_C( 1987505941), INT32_C(  764362116),
                         INT32_C( 1144465224), INT32_C( -939012905)) },
    { simde_x_vloadq_s32(INT32_C( -563712427), INT32_C(  969271584),
                         INT32_C( -123068166), INT32_C( -364046344)),
      simde_x_vloadq_s32(INT32_C( 1838532984), INT32_C( -154506264),
                         INT32_C(-1805936744), INT32_C( 1922367201)),
      simde_x_vloadq_s32(INT32_C( 1892721885), INT32_C( 1123777848),
                         INT32_C( 1682868578), INT32_C( 2008553751)) },
    { simde_x_vloadq_s32(INT32_C( 1221273160), INT32_C(  899236763),
                         INT32_C(-1589608708), INT32_C(  888351319)),
      simde_x_vloadq_s32(INT32_C( 1872743482), INT32_C( 1264023526),
                         INT32_C( 2090293152), INT32_C( 1664402116)),
      simde_x_vloadq_s32(INT32_C( -651470322), INT32_C( -364786763),
                         INT32_C(  615065436), INT32_C( -776050797)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_int32x4_t r = simde_vsubq_s32(test_vec[i].a, test_vec[i].b);
    simde_neon_assert_int32x4(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_vsubq_s64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_int64x2_t a;
    simde_int64x2_t b;
    simde_int64x2_t r;
  } test_vec[8] = {
    { simde_x_vloadq_s64(INT64_C(  274222156456610435), INT64_C(-8012782520979457469)),
      simde_x_vloadq_s64(INT64_C(-1951579396529905934), INT64_C(-8949642768782436772)),
      simde_x_vloadq_s64(INT64_C( 2225801552986516369), INT64_C(  936860247802979303)) },
    { simde_x_vloadq_s64(INT64_C( 6363094968655137069), INT64_C(-6522196357844283659)),
      simde_x_vloadq_s64(INT64_C(  171738256209698764), INT64_C( 4332781025410659193)),
      simde_x_vloadq_s64(INT64_C( 6191356712445438305), INT64_C( 7591766690454608764)) },
    { simde_x_vloadq_s64(INT64_C( 7545908718737944913), INT64_C( 6620037987636810772)),
      simde_x_vloadq_s64(INT64_C(-5998593649828178346), INT64_C( 7689368957132035206)),
      simde_x_vloadq_s64(INT64_C(-4902241705143428357), INT64_C(-1069330969495224434)) },
    { simde_x_vloadq_s64(INT64_C(-6078566214002893154), INT64_C( 4141250803303811646)),
      simde_x_vloadq_s64(INT64_C( 5190927894885744620), INT64_C( 8853395625688132922)),
      simde_x_vloadq_s64(INT64_C( 7177249964820913842), INT64_C(-4712144822384321276)) },
    { simde_x_vloadq_s64(INT64_C( 5509488642277061692), INT64_C( 4838938835417695175)),
      simde_x_vloadq_s64(INT64_C( 6187764650123727738), INT64_C(-5535891583034837807)),
      simde_x_vloadq_s64(INT64_C( -678276007846666046), INT64_C(-8071913655257018634)) },
    { simde_x_vloadq_s64(INT64_C(-5696555285264059925), INT64_C( 3640797763463904411)),
      simde_x_vloadq_s64(INT64_C( 1005953358039190781), INT64_C( 5966532970448653645)),
      simde_x_vloadq_s64(INT64_C(-6702508643303250706), INT64_C(-2325735206984749234)) },
    { simde_x_vloadq_s64(INT64_C(-2907053929439635722), INT64_C( 3182714029933510774)),
      simde_x_vloadq_s64(INT64_C(-3401187050751067841), INT64_C( 2862565250883486067)),
      simde_x_vloadq_s64(INT64_C(  494133121311432119), INT64_C(  320148779050024707)) },
    { simde_x_vloadq_s64(INT64_C( 6765691477153603441), INT64_C( 7918281142011594378)),
      simde_x_vloadq_s64(INT64_C( 3538463942809388704), INT64_C( 6955926674885320041)),
      simde_x_vloadq_s64(INT64_C( 3227227534344214737), INT64_C(  962354467126274337)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_int64x2_t r = simde_vsubq_s64(test_vec[i].a, test_vec[i].b);
    simde_neon_assert_int64x2(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_vsubq_u8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_uint8x16_t a;
    simde_uint8x16_t b;
    simde_uint8x16_t r;
  } test_vec[8] = {
    { simde_x_vloadq_u8(UINT8_C( 87), UINT8_C(166), UINT8_C(133), UINT8_C(200),
                        UINT8_C(211), UINT8_C( 23), UINT8_C( 52), UINT8_C(201),
                        UINT8_C(140), UINT8_C( 28), UINT8_C(164), UINT8_C( 87),
                        UINT8_C(223), UINT8_C(140), UINT8_C( 81), UINT8_C(145) ),
      simde_x_vloadq_u8(UINT8_C(152), UINT8_C(232), UINT8_C( 56), UINT8_C(163),
                        UINT8_C(241), UINT8_C(221), UINT8_C(205), UINT8_C(167),
                        UINT8_C(140), UINT8_C(111), UINT8_C(223), UINT8_C( 99),
                        UINT8_C(240), UINT8_C(161), UINT8_C( 11), UINT8_C(227) ),
      simde_x_vloadq_u8(UINT8_C(191), UINT8_C(190), UINT8_C( 77), UINT8_C( 37),
                        UINT8_C(226), UINT8_C( 58), UINT8_C(103), UINT8_C( 34),
                        UINT8_C(  0), UINT8_C(173), UINT8_C(197), UINT8_C(244),
                        UINT8_C(239), UINT8_C(235), UINT8_C( 70), UINT8_C(174) ) },
    { simde_x_vloadq_u8(UINT8_C( 78), UINT8_C(248), UINT8_C(127), UINT8_C( 50),
                        UINT8_C(109), UINT8_C( 16), UINT8_C( 48), UINT8_C(232),
                        UINT8_C(142), UINT8_C( 47), UINT8_C(147), UINT8_C(229),
                        UINT8_C( 49), UINT8_C(105), UINT8_C( 55), UINT8_C(126) ),
      simde_x_vloadq_u8(UINT8_C(100), UINT8_C( 45), UINT8_C( 97), UINT8_C(206),
                        UINT8_C(115), UINT8_C( 34), UINT8_C(225), UINT8_C(163),
                        UINT8_C(112), UINT8_C(233), UINT8_C( 18), UINT8_C(183),
                        UINT8_C( 19), UINT8_C( 93), UINT8_C(192), UINT8_C(250) ),
      simde_x_vloadq_u8(UINT8_C(234), UINT8_C(203), UINT8_C( 30), UINT8_C(100),
                        UINT8_C(250), UINT8_C(238), UINT8_C( 79), UINT8_C( 69),
                        UINT8_C( 30), UINT8_C( 70), UINT8_C(129), UINT8_C( 46),
                        UINT8_C( 30), UINT8_C( 12), UINT8_C(119), UINT8_C(132) ) },
    { simde_x_vloadq_u8(UINT8_C(142), UINT8_C(126), UINT8_C(125), UINT8_C(192),
                        UINT8_C( 49), UINT8_C(244), UINT8_C( 25), UINT8_C(167),
                        UINT8_C( 93), UINT8_C(226), UINT8_C(205), UINT8_C(169),
                        UINT8_C( 52), UINT8_C( 68), UINT8_C(146), UINT8_C( 69) ),
      simde_x_vloadq_u8(UINT8_C(150), UINT8_C(111), UINT8_C( 21), UINT8_C(234),
                        UINT8_C(182), UINT8_C(188), UINT8_C(152), UINT8_C( 59),
                        UINT8_C(165), UINT8_C(143), UINT8_C(  0), UINT8_C(157),
                        UINT8_C(255), UINT8_C(215), UINT8_C( 72), UINT8_C(154) ),
      simde_x_vloadq_u8(UINT8_C(248), UINT8_C( 15), UINT8_C(104), UINT8_C(214),
                        UINT8_C(123), UINT8_C( 56), UINT8_C(129), UINT8_C(108),
                        UINT8_C(184), UINT8_C( 83), UINT8_C(205), UINT8_C( 12),
                        UINT8_C( 53), UINT8_C(109), UINT8_C( 74), UINT8_C(171) ) },
    { simde_x_vloadq_u8(UINT8_C(233), UINT8_C(157), UINT8_C(171), UINT8_C( 93),
                        UINT8_C( 59), UINT8_C(112), UINT8_C(155), UINT8_C(145),
                        UINT8_C( 14), UINT8_C(206), UINT8_C(123), UINT8_C( 33),
                        UINT8_C(134), UINT8_C(124), UINT8_C(173), UINT8_C( 21) ),
      simde_x_vloadq_u8(UINT8_C(178), UINT8_C(228), UINT8_C(119), UINT8_C(103),
                        UINT8_C(  9), UINT8_C( 45), UINT8_C( 47), UINT8_C(186),
                        UINT8_C( 59), UINT8_C(218), UINT8_C( 90), UINT8_C(122),
                        UINT8_C(239), UINT8_C(194), UINT8_C( 89), UINT8_C(141) ),
      simde_x_vloadq_u8(UINT8_C( 55), UINT8_C(185), UINT8_C( 52), UINT8_C(246),
                        UINT8_C( 50), UINT8_C( 67), UINT8_C(108), UINT8_C(215),
                        UINT8_C(211), UINT8_C(244), UINT8_C( 33), UINT8_C(167),
                        UINT8_C(151), UINT8_C(186), UINT8_C( 84), UINT8_C(136) ) },
    { simde_x_vloadq_u8(UINT8_C(  7), UINT8_C(184), UINT8_C( 89), UINT8_C(229),
                        UINT8_C( 26), UINT8_C(225), UINT8_C(171), UINT8_C( 84),
                        UINT8_C(163), UINT8_C(191), UINT8_C( 98), UINT8_C(129),
                        UINT8_C(143), UINT8_C(170), UINT8_C(148), UINT8_C( 70) ),
      simde_x_vloadq_u8(UINT8_C(  5), UINT8_C(254), UINT8_C(214), UINT8_C(207),
                        UINT8_C(152), UINT8_C(188), UINT8_C(231), UINT8_C(116),
                        UINT8_C(199), UINT8_C(147), UINT8_C( 90), UINT8_C(229),
                        UINT8_C(191), UINT8_C( 52), UINT8_C(224), UINT8_C(113) ),
      simde_x_vloadq_u8(UINT8_C(  2), UINT8_C(186), UINT8_C(131), UINT8_C( 22),
                        UINT8_C(130), UINT8_C( 37), UINT8_C(196), UINT8_C(224),
                        UINT8_C(220), UINT8_C( 44), UINT8_C(  8), UINT8_C(156),
                        UINT8_C(208), UINT8_C(118), UINT8_C(180), UINT8_C(213) ) },
    { simde_x_vloadq_u8(UINT8_C( 64), UINT8_C(  6), UINT8_C( 42), UINT8_C(193),
                        UINT8_C(142), UINT8_C(  7), UINT8_C(114), UINT8_C( 83),
                        UINT8_C( 65), UINT8_C(177), UINT8_C(114), UINT8_C(206),
                        UINT8_C(218), UINT8_C(169), UINT8_C( 31), UINT8_C( 17) ),
      simde_x_vloadq_u8(UINT8_C( 72), UINT8_C(215), UINT8_C( 74), UINT8_C( 77),
                        UINT8_C( 51), UINT8_C(124), UINT8_C(148), UINT8_C(247),
                        UINT8_C(227), UINT8_C(145), UINT8_C( 46), UINT8_C( 93),
                        UINT8_C( 71), UINT8_C(189), UINT8_C( 75), UINT8_C( 95) ),
      simde_x_vloadq_u8(UINT8_C(248), UINT8_C( 47), UINT8_C(224), UINT8_C(116),
                        UINT8_C( 91), UINT8_C(139), UINT8_C(222), UINT8_C( 92),
                        UINT8_C( 94), UINT8_C( 32), UINT8_C( 68), UINT8_C(113),
                        UINT8_C(147), UINT8_C(236), UINT8_C(212), UINT8_C(178) ) },
    { simde_x_vloadq_u8(UINT8_C(229), UINT8_C( 36), UINT8_C( 55), UINT8_C( 75),
                        UINT8_C( 32), UINT8_C( 62), UINT8_C(175), UINT8_C(217),
                        UINT8_C(  6), UINT8_C( 76), UINT8_C( 16), UINT8_C(228),
                        UINT8_C( 98), UINT8_C( 43), UINT8_C(172), UINT8_C( 10) ),
      simde_x_vloadq_u8(UINT8_C(221), UINT8_C( 62), UINT8_C( 60), UINT8_C(117),
                        UINT8_C(127), UINT8_C(225), UINT8_C(161), UINT8_C(111),
                        UINT8_C( 71), UINT8_C( 10), UINT8_C( 89), UINT8_C(137),
                        UINT8_C( 24), UINT8_C( 13), UINT8_C(189), UINT8_C(193) ),
      simde_x_vloadq_u8(UINT8_C(  8), UINT8_C(230), UINT8_C(251), UINT8_C(214),
                        UINT8_C(161), UINT8_C( 93), UINT8_C( 14), UINT8_C(106),
                        UINT8_C(191), UINT8_C( 66), UINT8_C(183), UINT8_C( 91),
                        UINT8_C( 74), UINT8_C( 30), UINT8_C(239), UINT8_C( 73) ) },
    { simde_x_vloadq_u8(UINT8_C(216), UINT8_C( 46), UINT8_C(120), UINT8_C(228),
                        UINT8_C(105), UINT8_C(220), UINT8_C( 54), UINT8_C(187),
                        UINT8_C(106), UINT8_C( 67), UINT8_C(134), UINT8_C(119),
                        UINT8_C(202), UINT8_C( 11), UINT8_C(190), UINT8_C( 21) ),
      simde_x_vloadq_u8(UINT8_C(111), UINT8_C(153), UINT8_C( 58), UINT8_C( 46),
                        UINT8_C(233), UINT8_C(135), UINT8_C( 56), UINT8_C( 71),
                        UINT8_C(213), UINT8_C(201), UINT8_C( 10), UINT8_C(126),
                        UINT8_C(252), UINT8_C( 75), UINT8_C( 50), UINT8_C(  2) ),
      simde_x_vloadq_u8(UINT8_C(105), UINT8_C(149), UINT8_C( 62), UINT8_C(182),
                        UINT8_C(128), UINT8_C( 85), UINT8_C(254), UINT8_C(116),
                        UINT8_C(149), UINT8_C(122), UINT8_C(124), UINT8_C(249),
                        UINT8_C(206), UINT8_C(192), UINT8_C(140), UINT8_C( 19) ) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_uint8x16_t r = simde_vsubq_u8(test_vec[i].a, test_vec[i].b);
    simde_neon_assert_uint8x16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_vsubq_u16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_uint16x8_t a;
    simde_uint16x8_t b;
    simde_uint16x8_t r;
  } test_vec[8] = {
    { simde_x_vloadq_u16(UINT16_C(32058), UINT16_C(26873), UINT16_C(51051), UINT16_C(31536),
                         UINT16_C(10411), UINT16_C(39995), UINT16_C(21610), UINT16_C( 9384)),
      simde_x_vloadq_u16(UINT16_C(59598), UINT16_C(35382), UINT16_C(33176), UINT16_C(25970),
                         UINT16_C(41560), UINT16_C(47620), UINT16_C( 1773), UINT16_C(42681)),
      simde_x_vloadq_u16(UINT16_C(37996), UINT16_C(57027), UINT16_C(17875), UINT16_C( 5566),
                         UINT16_C(34387), UINT16_C(57911), UINT16_C(19837), UINT16_C(32239)) },
    { simde_x_vloadq_u16(UINT16_C(59399), UINT16_C(53992), UINT16_C(46317), UINT16_C(28372),
                         UINT16_C(25727), UINT16_C(30337), UINT16_C(55706), UINT16_C(63759)),
      simde_x_vloadq_u16(UINT16_C( 5797), UINT16_C(19305), UINT16_C(37560), UINT16_C(46549),
                         UINT16_C(33738), UINT16_C(15792), UINT16_C(10742), UINT16_C(32928)),
      simde_x_vloadq_u16(UINT16_C(53602), UINT16_C(34687), UINT16_C( 8757), UINT16_C(47359),
                         UINT16_C(57525), UINT16_C(14545), UINT16_C(44964), UINT16_C(30831)) },
    { simde_x_vloadq_u16(UINT16_C(53681), UINT16_C(22004), UINT16_C(53966), UINT16_C(35356),
                         UINT16_C(62005), UINT16_C(63604), UINT16_C(59737), UINT16_C(55622)),
      simde_x_vloadq_u16(UINT16_C(34367), UINT16_C(61611), UINT16_C(14128), UINT16_C(16396),
                         UINT16_C(52618), UINT16_C(49102), UINT16_C( 2031), UINT16_C(63431)),
      simde_x_vloadq_u16(UINT16_C(19314), UINT16_C(25929), UINT16_C(39838), UINT16_C(18960),
                         UINT16_C( 9387), UINT16_C(14502), UINT16_C(57706), UINT16_C(57727)) },
    { simde_x_vloadq_u16(UINT16_C(39646), UINT16_C(45587), UINT16_C(23807), UINT16_C(48676),
                         UINT16_C( 8603), UINT16_C( 9561), UINT16_C(50591), UINT16_C(45984)),
      simde_x_vloadq_u16(UINT16_C(58421), UINT16_C(30266), UINT16_C(17160), UINT16_C(14127),
                         UINT16_C(59428), UINT16_C(25189), UINT16_C(40047), UINT16_C(49620)),
      simde_x_vloadq_u16(UINT16_C(46761), UINT16_C(15321), UINT16_C( 6647), UINT16_C(34549),
                         UINT16_C(14711), UINT16_C(49908), UINT16_C(10544), UINT16_C(61900)) },
    { simde_x_vloadq_u16(UINT16_C( 6007), UINT16_C(32558), UINT16_C(60603), UINT16_C( 8094),
                         UINT16_C(46041), UINT16_C(14496), UINT16_C( 9960), UINT16_C(64452)),
      simde_x_vloadq_u16(UINT16_C(55919), UINT16_C(48705), UINT16_C(  278), UINT16_C(40315),
                         UINT16_C(43583), UINT16_C(32754), UINT16_C(54969), UINT16_C(32537)),
      simde_x_vloadq_u16(UINT16_C(15624), UINT16_C(49389), UINT16_C(60325), UINT16_C(33315),
                         UINT16_C( 2458), UINT16_C(47278), UINT16_C(20527), UINT16_C(31915)) },
    { simde_x_vloadq_u16(UINT16_C(29699), UINT16_C( 6878), UINT16_C(61985), UINT16_C(28537),
                         UINT16_C(11093), UINT16_C(59294), UINT16_C(49467), UINT16_C(14552)),
      simde_x_vloadq_u16(UINT16_C(28129), UINT16_C(16604), UINT16_C( 2705), UINT16_C(46832),
                         UINT16_C(52122), UINT16_C(33620), UINT16_C(45368), UINT16_C(46933)),
      simde_x_vloadq_u16(UINT16_C( 1570), UINT16_C(55810), UINT16_C(59280), UINT16_C(47241),
                         UINT16_C(24507), UINT16_C(25674), UINT16_C( 4099), UINT16_C(33155)) },
    { simde_x_vloadq_u16(UINT16_C(10975), UINT16_C( 9937), UINT16_C(22680), UINT16_C( 9723),
                         UINT16_C(21167), UINT16_C(13605), UINT16_C(22850), UINT16_C(50938)),
      simde_x_vloadq_u16(UINT16_C(  791), UINT16_C(29997), UINT16_C( 6816), UINT16_C(19884),
                         UINT16_C(27158), UINT16_C(  195), UINT16_C(51377), UINT16_C(51054)),
      simde_x_vloadq_u16(UINT16_C(10184), UINT16_C(45476), UINT16_C(15864), UINT16_C(55375),
                         UINT16_C(59545), UINT16_C(13410), UINT16_C(37009), UINT16_C(65420)) },
    { simde_x_vloadq_u16(UINT16_C(35815), UINT16_C(48475), UINT16_C(62387), UINT16_C(39859),
                         UINT16_C( 8385), UINT16_C( 1980), UINT16_C(63086), UINT16_C(23583)),
      simde_x_vloadq_u16(UINT16_C(32032), UINT16_C(34559), UINT16_C(38712), UINT16_C(51264),
                         UINT16_C( 1517), UINT16_C( 1962), UINT16_C( 5545), UINT16_C(52626)),
      simde_x_vloadq_u16(UINT16_C( 3783), UINT16_C(13916), UINT16_C(23675), UINT16_C(54131),
                         UINT16_C( 6868), UINT16_C(   18), UINT16_C(57541), UINT16_C(36493)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_uint16x8_t r = simde_vsubq_u16(test_vec[i].a, test_vec[i].b);
    simde_neon_assert_uint16x8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_vsubq_u32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_uint32x4_t a;
    simde_uint32x4_t b;
    simde_uint32x4_t r;
  } test_vec[8] = {
    { simde_x_vloadq_u32(UINT32_C(3895408461), UINT32_C(3640128288),
                         UINT32_C(1854574044), UINT32_C(1659558118)),
      simde_x_vloadq_u32(UINT32_C(1884519680), UINT32_C( 213141937),
                         UINT32_C(2264515241), UINT32_C( 599802617)),
      simde_x_vloadq_u32(UINT32_C(2010888781), UINT32_C(3426986351),
                         UINT32_C(3885026099), UINT32_C(1059755501)) },
    { simde_x_vloadq_u32(UINT32_C(3891897214), UINT32_C(1797204056),
                         UINT32_C(3471191210), UINT32_C(3208034210)),
      simde_x_vloadq_u32(UINT32_C(4270742654), UINT32_C(1803662066),
                         UINT32_C( 905537885), UINT32_C(3774829890)),
      simde_x_vloadq_u32(UINT32_C(3916121856), UINT32_C(4288509286),
                         UINT32_C(2565653325), UINT32_C(3728171616)) },
    { simde_x_vloadq_u32(UINT32_C(1716681133), UINT32_C(1373763584),
                         UINT32_C(2129047472), UINT32_C( 660748118)),
      simde_x_vloadq_u32(UINT32_C(1322003017), UINT32_C(2735955115),
                         UINT32_C(1208054480), UINT32_C(3915748514)),
      simde_x_vloadq_u32(UINT32_C( 394678116), UINT32_C(2932775765),
                         UINT32_C( 920992992), UINT32_C(1039966900)) },
    { simde_x_vloadq_u32(UINT32_C(1227832463), UINT32_C( 881560198),
                         UINT32_C(3487996398), UINT32_C(3949354035)),
      simde_x_vloadq_u32(UINT32_C(2421331614), UINT32_C(2819230368),
                         UINT32_C(2423324594), UINT32_C( 998713619)),
      simde_x_vloadq_u32(UINT32_C(3101468145), UINT32_C(2357297126),
                         UINT32_C(1064671804), UINT32_C(2950640416)) },
    { simde_x_vloadq_u32(UINT32_C(3212444536), UINT32_C(3255121650),
                         UINT32_C( 280297817), UINT32_C(2780019175)),
      simde_x_vloadq_u32(UINT32_C(1634711183), UINT32_C(  74404227),
                         UINT32_C(4155314604), UINT32_C(2276824421)),
      simde_x_vloadq_u32(UINT32_C(1577733353), UINT32_C(3180717423),
                         UINT32_C( 419950509), UINT32_C( 503194754)) },
    { simde_x_vloadq_u32(UINT32_C(2531614680), UINT32_C(3065185794),
                         UINT32_C(1559662141), UINT32_C(4245192357)),
      simde_x_vloadq_u32(UINT32_C( 629083668), UINT32_C( 165904817),
                         UINT32_C(1258087237), UINT32_C( 869898369)),
      simde_x_vloadq_u32(UINT32_C(1902531012), UINT32_C(2899280977),
                         UINT32_C( 301574904), UINT32_C(3375293988)) },
    { simde_x_vloadq_u32(UINT32_C(3370588623), UINT32_C( 378752671),
                         UINT32_C( 654547258), UINT32_C(3831311079)),
      simde_x_vloadq_u32(UINT32_C(1157532660), UINT32_C(1026394530),
                         UINT32_C(1443726588), UINT32_C(1444660531)),
      simde_x_vloadq_u32(UINT32_C(2213055963), UINT32_C(3647325437),
                         UINT32_C(3505787966), UINT32_C(2386650548)) },
    { simde_x_vloadq_u32(UINT32_C( 388092756), UINT32_C(2451063360),
                         UINT32_C(2692706503), UINT32_C(3353389405)),
      simde_x_vloadq_u32(UINT32_C( 598271220), UINT32_C(3357759735),
                         UINT32_C(2490786438), UINT32_C(2782412551)),
      simde_x_vloadq_u32(UINT32_C(4084788832), UINT32_C(3388270921),
                         UINT32_C( 201920065), UINT32_C( 570976854)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_uint32x4_t r = simde_vsubq_u32(test_vec[i].a, test_vec[i].b);
    simde_neon_assert_uint32x4(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_vsubq_u64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_uint64x2_t a;
    simde_uint64x2_t b;
    simde_uint64x2_t r;
  } test_vec[8] = {
    { simde_x_vloadq_u64(UINT64_C(18062352261781936342), UINT64_C(7388857429341683123)),
      simde_x_vloadq_u64(UINT64_C(1553436335104468014), UINT64_C(16839974875395556662)),
      simde_x_vloadq_u64(UINT64_C(16508915926677468328), UINT64_C(8995626627655678077)) },
    { simde_x_vloadq_u64(UINT64_C(9781783238890835896), UINT64_C(17293201827280780780)),
      simde_x_vloadq_u64(UINT64_C(7134357670424035822), UINT64_C(4404198093893325283)),
      simde_x_vloadq_u64(UINT64_C(2647425568466800074), UINT64_C(12889003733387455497)) },
    { simde_x_vloadq_u64(UINT64_C(4488961572228535140), UINT64_C(1346563325554989949)),
      simde_x_vloadq_u64(UINT64_C(2634888985021256352), UINT64_C( 666451602867372356)),
      simde_x_vloadq_u64(UINT64_C(1854072587207278788), UINT64_C( 680111722687617593)) },
    { simde_x_vloadq_u64(UINT64_C(1318235667828533745), UINT64_C(14815956286012371914)),
      simde_x_vloadq_u64(UINT64_C(11432878494825478518), UINT64_C(17685580310423747579)),
      simde_x_vloadq_u64(UINT64_C(8332101246712606843), UINT64_C(15577120049298175951)) },
    { simde_x_vloadq_u64(UINT64_C(17790576723876784299), UINT64_C(11663761306291148559)),
      simde_x_vloadq_u64(UINT64_C(15385151009115536057), UINT64_C(13794328263855967094)),
      simde_x_vloadq_u64(UINT64_C(2405425714761248242), UINT64_C(16316177116144733081)) },
    { simde_x_vloadq_u64(UINT64_C( 350914325027652600), UINT64_C(14797590881591740981)),
      simde_x_vloadq_u64(UINT64_C(12036897114441261299), UINT64_C(8202964999985589665)),
      simde_x_vloadq_u64(UINT64_C(6760761284295942917), UINT64_C(6594625881606151316)) },
    { simde_x_vloadq_u64(UINT64_C(8518920335610308466), UINT64_C(16046307191155630549)),
      simde_x_vloadq_u64(UINT64_C(6106112106205787470), UINT64_C(16756353123063307916)),
      simde_x_vloadq_u64(UINT64_C(2412808229404520996), UINT64_C(17736698141801874249)) },
    { simde_x_vloadq_u64(UINT64_C(5938134708777591391), UINT64_C(5692436156143036134)),
      simde_x_vloadq_u64(UINT64_C(1370976571276529480), UINT64_C(2772233378346164097)),
      simde_x_vloadq_u64(UINT64_C(4567158137501061911), UINT64_C(2920202777796872037)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_uint64x2_t r = simde_vsubq_u64(test_vec[i].a, test_vec[i].b);
    simde_neon_assert_uint64x2(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_vsubq_f32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_float32x4_t a;
    simde_float32x4_t b;
    simde_float32x4_t r;
  } test_vec[8] = {
    { simde_x_vloadq_f32(SIMDE_FLOAT32_C(    7.69), SIMDE_FLOAT32_C(  907.62),
                         SIMDE_FLOAT32_C(  434.05), SIMDE_FLOAT32_C(  467.28)),
      simde_x_vloadq_f32(SIMDE_FLOAT32_C( -933.64), SIMDE_FLOAT32_C( -442.18),
                         SIMDE_FLOAT32_C(  903.29), SIMDE_FLOAT32_C(  399.69)),
      simde_x_vloadq_f32(SIMDE_FLOAT32_C(  941.33), SIMDE_FLOAT32_C( 1349.80),
                         SIMDE_FLOAT32_C( -469.24), SIMDE_FLOAT32_C(   67.59)) },
    { simde_x_vloadq_f32(SIMDE_FLOAT32_C(  730.21), SIMDE_FLOAT32_C(  541.58),
                         SIMDE_FLOAT32_C( -112.19), SIMDE_FLOAT32_C( -183.13)),
      simde_x_vloadq_f32(SIMDE_FLOAT32_C( -894.87), SIMDE_FLOAT32_C( -998.92),
                         SIMDE_FLOAT32_C( -118.73), SIMDE_FLOAT32_C(  578.99)),
      simde_x_vloadq_f32(SIMDE_FLOAT32_C( 1625.08), SIMDE_FLOAT32_C( 1540.50),
                         SIMDE_FLOAT32_C(    6.54), SIMDE_FLOAT32_C( -762.12)) },
    { simde_x_vloadq_f32(SIMDE_FLOAT32_C(   39.67), SIMDE_FLOAT32_C(  381.67),
                         SIMDE_FLOAT32_C(  729.76), SIMDE_FLOAT32_C(  -88.71)),
      simde_x_vloadq_f32(SIMDE_FLOAT32_C(  432.56), SIMDE_FLOAT32_C(  323.88),
                         SIMDE_FLOAT32_C( -791.56), SIMDE_FLOAT32_C(  976.13)),
      simde_x_vloadq_f32(SIMDE_FLOAT32_C( -392.89), SIMDE_FLOAT32_C(   57.79),
                         SIMDE_FLOAT32_C( 1521.32), SIMDE_FLOAT32_C(-1064.84)) },
    { simde_x_vloadq_f32(SIMDE_FLOAT32_C( -983.53), SIMDE_FLOAT32_C(  399.10),
                         SIMDE_FLOAT32_C(  580.81), SIMDE_FLOAT32_C(  664.21)),
      simde_x_vloadq_f32(SIMDE_FLOAT32_C( -569.36), SIMDE_FLOAT32_C(  667.71),
                         SIMDE_FLOAT32_C(  933.23), SIMDE_FLOAT32_C( -924.97)),
      simde_x_vloadq_f32(SIMDE_FLOAT32_C( -414.17), SIMDE_FLOAT32_C( -268.61),
                         SIMDE_FLOAT32_C( -352.42), SIMDE_FLOAT32_C( 1589.18)) },
    { simde_x_vloadq_f32(SIMDE_FLOAT32_C(  921.09), SIMDE_FLOAT32_C( -843.40),
                         SIMDE_FLOAT32_C(  221.06), SIMDE_FLOAT32_C( -617.96)),
      simde_x_vloadq_f32(SIMDE_FLOAT32_C( -739.66), SIMDE_FLOAT32_C(  351.29),
                         SIMDE_FLOAT32_C(  257.33), SIMDE_FLOAT32_C( -723.30)),
      simde_x_vloadq_f32(SIMDE_FLOAT32_C( 1660.75), SIMDE_FLOAT32_C(-1194.69),
                         SIMDE_FLOAT32_C(  -36.27), SIMDE_FLOAT32_C(  105.34)) },
    { simde_x_vloadq_f32(SIMDE_FLOAT32_C(  598.06), SIMDE_FLOAT32_C( -849.67),
                         SIMDE_FLOAT32_C( -665.04), SIMDE_FLOAT32_C(  262.46)),
      simde_x_vloadq_f32(SIMDE_FLOAT32_C(  403.08), SIMDE_FLOAT32_C( -450.69),
                         SIMDE_FLOAT32_C(  315.14), SIMDE_FLOAT32_C( -172.43)),
      simde_x_vloadq_f32(SIMDE_FLOAT32_C(  194.98), SIMDE_FLOAT32_C( -398.98),
                         SIMDE_FLOAT32_C( -980.18), SIMDE_FLOAT32_C(  434.89)) },
    { simde_x_vloadq_f32(SIMDE_FLOAT32_C( -734.13), SIMDE_FLOAT32_C(  313.84),
                         SIMDE_FLOAT32_C(  126.41), SIMDE_FLOAT32_C(  460.30)),
      simde_x_vloadq_f32(SIMDE_FLOAT32_C(  981.68), SIMDE_FLOAT32_C( -396.47),
                         SIMDE_FLOAT32_C(  734.12), SIMDE_FLOAT32_C( -993.96)),
      simde_x_vloadq_f32(SIMDE_FLOAT32_C(-1715.81), SIMDE_FLOAT32_C(  710.31),
                         SIMDE_FLOAT32_C( -607.71), SIMDE_FLOAT32_C( 1454.26)) },
    { simde_x_vloadq_f32(SIMDE_FLOAT32_C(  -43.70), SIMDE_FLOAT32_C(  865.01),
                         SIMDE_FLOAT32_C(  778.14), SIMDE_FLOAT32_C(  818.60)),
      simde_x_vloadq_f32(SIMDE_FLOAT32_C(  597.32), SIMDE_FLOAT32_C( -982.41),
                         SIMDE_FLOAT32_C(  529.34), SIMDE_FLOAT32_C(  891.14)),
      simde_x_vloadq_f32(SIMDE_FLOAT32_C( -641.02), SIMDE_FLOAT32_C( 1847.42),
                         SIMDE_FLOAT32_C(  248.80), SIMDE_FLOAT32_C(  -72.54)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_float32x4_t r = simde_vsubq_f32(test_vec[i].a, test_vec[i].b);
    simde_neon_assert_float32x4_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_vsubq_f64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_float64x2_t a;
    simde_float64x2_t b;
    simde_float64x2_t r;
  } test_vec[8] = {
    { simde_x_vloadq_f64(SIMDE_FLOAT64_C(  825.97), SIMDE_FLOAT64_C(  668.02)),
      simde_x_vloadq_f64(SIMDE_FLOAT64_C( -306.36), SIMDE_FLOAT64_C( -166.09)),
      simde_x_vloadq_f64(SIMDE_FLOAT64_C( 1132.33), SIMDE_FLOAT64_C(  834.11)) },
    { simde_x_vloadq_f64(SIMDE_FLOAT64_C( -347.97), SIMDE_FLOAT64_C(  878.12)),
      simde_x_vloadq_f64(SIMDE_FLOAT64_C( -577.04), SIMDE_FLOAT64_C(  589.16)),
      simde_x_vloadq_f64(SIMDE_FLOAT64_C(  229.07), SIMDE_FLOAT64_C(  288.96)) },
    { simde_x_vloadq_f64(SIMDE_FLOAT64_C(  977.90), SIMDE_FLOAT64_C(  617.14)),
      simde_x_vloadq_f64(SIMDE_FLOAT64_C(  203.07), SIMDE_FLOAT64_C(  438.54)),
      simde_x_vloadq_f64(SIMDE_FLOAT64_C(  774.83), SIMDE_FLOAT64_C(  178.60)) },
    { simde_x_vloadq_f64(SIMDE_FLOAT64_C(  -37.98), SIMDE_FLOAT64_C( -671.53)),
      simde_x_vloadq_f64(SIMDE_FLOAT64_C(  -96.79), SIMDE_FLOAT64_C(  106.17)),
      simde_x_vloadq_f64(SIMDE_FLOAT64_C(   58.81), SIMDE_FLOAT64_C( -777.70)) },
    { simde_x_vloadq_f64(SIMDE_FLOAT64_C( -617.94), SIMDE_FLOAT64_C(  127.13)),
      simde_x_vloadq_f64(SIMDE_FLOAT64_C(  546.61), SIMDE_FLOAT64_C(  958.62)),
      simde_x_vloadq_f64(SIMDE_FLOAT64_C(-1164.55), SIMDE_FLOAT64_C( -831.49)) },
    { simde_x_vloadq_f64(SIMDE_FLOAT64_C( -851.38), SIMDE_FLOAT64_C( -117.61)),
      simde_x_vloadq_f64(SIMDE_FLOAT64_C( -556.18), SIMDE_FLOAT64_C(  808.85)),
      simde_x_vloadq_f64(SIMDE_FLOAT64_C( -295.20), SIMDE_FLOAT64_C( -926.46)) },
    { simde_x_vloadq_f64(SIMDE_FLOAT64_C(  810.93), SIMDE_FLOAT64_C(  200.78)),
      simde_x_vloadq_f64(SIMDE_FLOAT64_C(  375.25), SIMDE_FLOAT64_C(  -38.10)),
      simde_x_vloadq_f64(SIMDE_FLOAT64_C(  435.68), SIMDE_FLOAT64_C(  238.88)) },
    { simde_x_vloadq_f64(SIMDE_FLOAT64_C( -395.68), SIMDE_FLOAT64_C(  663.06)),
      simde_x_vloadq_f64(SIMDE_FLOAT64_C( -565.25), SIMDE_FLOAT64_C(  522.03)),
      simde_x_vloadq_f64(SIMDE_FLOAT64_C(  169.57), SIMDE_FLOAT64_C(  141.03)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_float64x2_t r = simde_vsubq_f64(test_vec[i].a, test_vec[i].b);
    simde_neon_assert_float64x2_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

#endif /* defined(SIMDE_NEON_NATIVE) || defined(SIMDE_NO_NATIVE) || defined(SIMDE_ALWAYS_BUILD_NATIVE_TESTS) */

HEDLEY_DIAGNOSTIC_PUSH
HEDLEY_DIAGNOSTIC_DISABLE_CAST_QUAL

static MunitTest test_suite_tests[] = {
#if defined(SIMDE_NEON_NATIVE) || defined(SIMDE_NO_NATIVE) || defined(SIMDE_ALWAYS_BUILD_NATIVE_TESTS)
  SIMDE_TESTS_NEON_DEFINE_TEST(s8),
  SIMDE_TESTS_NEON_DEFINE_TEST(s16),
  SIMDE_TESTS_NEON_DEFINE_TEST(s32),
  SIMDE_TESTS_NEON_DEFINE_TEST(s64),
  SIMDE_TESTS_NEON_DEFINE_TEST(u8),
  SIMDE_TESTS_NEON_DEFINE_TEST(u16),
  SIMDE_TESTS_NEON_DEFINE_TEST(u32),
  SIMDE_TESTS_NEON_DEFINE_TEST(u64),
  SIMDE_TESTS_NEON_DEFINE_TEST(f32),
  SIMDE_TESTS_NEON_DEFINE_TEST(f64),
  SIMDE_TESTS_NEON_DEFINE_TEST_FULL(q, s8),
  SIMDE_TESTS_NEON_DEFINE_TEST_FULL(q, s16),
  SIMDE_TESTS_NEON_DEFINE_TEST_FULL(q, s32),
  SIMDE_TESTS_NEON_DEFINE_TEST_FULL(q, s64),
  SIMDE_TESTS_NEON_DEFINE_TEST_FULL(q, u8),
  SIMDE_TESTS_NEON_DEFINE_TEST_FULL(q, u16),
  SIMDE_TESTS_NEON_DEFINE_TEST_FULL(q, u32),
  SIMDE_TESTS_NEON_DEFINE_TEST_FULL(q, u64),
  SIMDE_TESTS_NEON_DEFINE_TEST_FULL(q, f32),
  SIMDE_TESTS_NEON_DEFINE_TEST_FULL(q, f64),
#endif /* defined(SIMDE_NEON_NATIVE) || defined(SIMDE_NO_NATIVE) || defined(SIMDE_ALWAYS_BUILD_NATIVE_TESTS) */

  { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

HEDLEY_C_DECL MunitSuite* SIMDE_TESTS_GENERATE_SYMBOL(SIMDE_TESTS_CURRENT_NEON_OP)(void) {
  static MunitSuite suite = { (char*) "/v" HEDLEY_STRINGIFY(SIMDE_TESTS_CURRENT_NEON_OP), test_suite_tests, NULL, 1, MUNIT_SUITE_OPTION_NONE };

  return &suite;
}

HEDLEY_DIAGNOSTIC_POP
