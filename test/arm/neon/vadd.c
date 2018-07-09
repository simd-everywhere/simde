/* Copyright (c) 2018 Evan Nemerson <evan@nemerson.com>
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

#include <test/arm/arm-internal.h>
#include <simde/arm/neon.h>

static MunitResult
test_simde_vadd_s8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_int8x8_t a;
    simde_int8x8_t b;
    simde_int8x8_t r;
  } test_vec[8] = {
    { simde_x_vload_s8(INT8_C( -43), INT8_C( -27), INT8_C( 114), INT8_C( -95),
                       INT8_C( -80), INT8_C(  -5), INT8_C(  84), INT8_C( 122)),
      simde_x_vload_s8(INT8_C(   6), INT8_C(  12), INT8_C( -61), INT8_C( 101),
                       INT8_C( 120), INT8_C( -62), INT8_C(  81), INT8_C( -57)),
      simde_x_vload_s8(INT8_C( -37), INT8_C( -15), INT8_C(  53), INT8_C(   6),
                       INT8_C(  40), INT8_C( -67), INT8_C( -91), INT8_C(  65)) },
    { simde_x_vload_s8(INT8_C( -91), INT8_C(  -1), INT8_C( 121), INT8_C( 113),
                       INT8_C(  96), INT8_C(  24), INT8_C( 122), INT8_C(  73)),
      simde_x_vload_s8(INT8_C( -55), INT8_C(  88), INT8_C(  21), INT8_C(  70),
                       INT8_C(  35), INT8_C(  40), INT8_C(  32), INT8_C(  28)),
      simde_x_vload_s8(INT8_C( 110), INT8_C(  87), INT8_C(-114), INT8_C( -73),
                       INT8_C(-125), INT8_C(  64), INT8_C(-102), INT8_C( 101)) },
    { simde_x_vload_s8(INT8_C( -55), INT8_C( -59), INT8_C( -17), INT8_C(  34),
                       INT8_C(  94), INT8_C(   4), INT8_C(  40), INT8_C( -89)),
      simde_x_vload_s8(INT8_C(  73), INT8_C( 102), INT8_C(  14), INT8_C(  89),
                       INT8_C(  24), INT8_C( -86), INT8_C( 109), INT8_C( 103)),
      simde_x_vload_s8(INT8_C(  18), INT8_C(  43), INT8_C(  -3), INT8_C( 123),
                       INT8_C( 118), INT8_C( -82), INT8_C(-107), INT8_C(  14)) },
    { simde_x_vload_s8(INT8_C( -18), INT8_C( -34), INT8_C(  42), INT8_C(-127),
                       INT8_C(  88), INT8_C(  15), INT8_C(  -8), INT8_C( -16)),
      simde_x_vload_s8(INT8_C(-110), INT8_C(  39), INT8_C(  65), INT8_C(  80),
                       INT8_C(-127), INT8_C(  92), INT8_C( -63), INT8_C(-109)),
      simde_x_vload_s8(INT8_C(-128), INT8_C(   5), INT8_C( 107), INT8_C( -47),
                       INT8_C( -39), INT8_C( 107), INT8_C( -71), INT8_C(-125)) },
    { simde_x_vload_s8(INT8_C(  54), INT8_C(  38), INT8_C( -64), INT8_C( -18),
                       INT8_C( -51), INT8_C(  46), INT8_C(  19), INT8_C( -51)),
      simde_x_vload_s8(INT8_C(-110), INT8_C(  27), INT8_C(-120), INT8_C( -92),
                       INT8_C( -33), INT8_C(  46), INT8_C( -85), INT8_C( -28)),
      simde_x_vload_s8(INT8_C( -56), INT8_C(  65), INT8_C(  72), INT8_C(-110),
                       INT8_C( -84), INT8_C(  92), INT8_C( -66), INT8_C( -79)) },
    { simde_x_vload_s8(INT8_C( -42), INT8_C( -16), INT8_C(-101), INT8_C(-127),
                       INT8_C(-121), INT8_C( -61), INT8_C( -10), INT8_C(  -6)),
      simde_x_vload_s8(INT8_C( 120), INT8_C(   6), INT8_C(  -8), INT8_C( -68),
                       INT8_C( -10), INT8_C(  70), INT8_C(  -5), INT8_C(-113)),
      simde_x_vload_s8(INT8_C(  78), INT8_C( -10), INT8_C(-109), INT8_C(  61),
                       INT8_C( 125), INT8_C(   9), INT8_C( -15), INT8_C(-119)) },
    { simde_x_vload_s8(INT8_C(  77), INT8_C( 105), INT8_C(  92), INT8_C( -63),
                       INT8_C( -30), INT8_C( -46), INT8_C(-122), INT8_C( 115)),
      simde_x_vload_s8(INT8_C( -65), INT8_C(  75), INT8_C(  11), INT8_C(  -2),
                       INT8_C(  78), INT8_C( 116), INT8_C(   7), INT8_C( -14)),
      simde_x_vload_s8(INT8_C(  12), INT8_C( -76), INT8_C( 103), INT8_C( -65),
                       INT8_C(  48), INT8_C(  70), INT8_C(-115), INT8_C( 101)) },
    { simde_x_vload_s8(INT8_C(  12), INT8_C( -46), INT8_C(  94), INT8_C(   7),
                       INT8_C(   6), INT8_C(  96), INT8_C(-120), INT8_C( -98)),
      simde_x_vload_s8(INT8_C( -15), INT8_C( -24), INT8_C( -94), INT8_C(  72),
                       INT8_C(  79), INT8_C(  36), INT8_C( 121), INT8_C( -55)),
      simde_x_vload_s8(INT8_C(  -3), INT8_C( -70), INT8_C(   0), INT8_C(  79),
                       INT8_C(  85), INT8_C(-124), INT8_C(   1), INT8_C( 103)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_int8x8_t r = simde_vadd_s8(test_vec[i].a, test_vec[i].b);
    simde_neon_assert_int8x8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_vadd_s16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_int16x4_t a;
    simde_int16x4_t b;
    simde_int16x4_t r;
  } test_vec[8] = {
    { simde_x_vload_s16(INT16_C( -6699), INT16_C(-24206), INT16_C( -1104), INT16_C( 31316)),
      simde_x_vload_s16(INT16_C(  3078), INT16_C( 26051), INT16_C(-15752), INT16_C(-14511)),
      simde_x_vload_s16(INT16_C( -3621), INT16_C(  1845), INT16_C(-16856), INT16_C( 16805)) },
    { simde_x_vload_s16(INT16_C(   -91), INT16_C( 29049), INT16_C(  6240), INT16_C( 18810)),
      simde_x_vload_s16(INT16_C( 22729), INT16_C( 17941), INT16_C( 10275), INT16_C(  7200)),
      simde_x_vload_s16(INT16_C( 22638), INT16_C(-18546), INT16_C( 16515), INT16_C( 26010)) },
    { simde_x_vload_s16(INT16_C(-14903), INT16_C(  8943), INT16_C(  1118), INT16_C(-22744)),
      simde_x_vload_s16(INT16_C( 26185), INT16_C( 22798), INT16_C(-21992), INT16_C( 26477)),
      simde_x_vload_s16(INT16_C( 11282), INT16_C( 31741), INT16_C(-20874), INT16_C(  3733)) },
    { simde_x_vload_s16(INT16_C( -8466), INT16_C(-32470), INT16_C(  3928), INT16_C( -3848)),
      simde_x_vload_s16(INT16_C( 10130), INT16_C( 20545), INT16_C( 23681), INT16_C(-27711)),
      simde_x_vload_s16(INT16_C(  1664), INT16_C(-11925), INT16_C( 27609), INT16_C(-31559)) },
    { simde_x_vload_s16(INT16_C(  9782), INT16_C( -4416), INT16_C( 11981), INT16_C(-13037)),
      simde_x_vload_s16(INT16_C(  7058), INT16_C(-23416), INT16_C( 11999), INT16_C( -6997)),
      simde_x_vload_s16(INT16_C( 16840), INT16_C(-27832), INT16_C( 23980), INT16_C(-20034)) },
    { simde_x_vload_s16(INT16_C( -3882), INT16_C(-32357), INT16_C(-15481), INT16_C( -1290)),
      simde_x_vload_s16(INT16_C(  1656), INT16_C(-17160), INT16_C( 18166), INT16_C(-28677)),
      simde_x_vload_s16(INT16_C( -2226), INT16_C( 16019), INT16_C(  2685), INT16_C(-29967)) },
    { simde_x_vload_s16(INT16_C( 26957), INT16_C(-16036), INT16_C(-11550), INT16_C( 29574)),
      simde_x_vload_s16(INT16_C( 19391), INT16_C(  -501), INT16_C( 29774), INT16_C( -3577)),
      simde_x_vload_s16(INT16_C(-19188), INT16_C(-16537), INT16_C( 18224), INT16_C( 25997)) },
    { simde_x_vload_s16(INT16_C(-11764), INT16_C(  1886), INT16_C( 24582), INT16_C(-24952)),
      simde_x_vload_s16(INT16_C( -5903), INT16_C( 18594), INT16_C(  9295), INT16_C(-13959)),
      simde_x_vload_s16(INT16_C(-17667), INT16_C( 20480), INT16_C(-31659), INT16_C( 26625)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_int16x4_t r = simde_vadd_s16(test_vec[i].a, test_vec[i].b);
    simde_neon_assert_int16x4(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_vadd_s32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_int32x2_t a;
    simde_int32x2_t b;
    simde_int32x2_t r;
  } test_vec[8] = {
    { simde_x_vload_s32(INT32_C(-1586305579), INT32_C( 2052389808)),
      simde_x_vload_s32(INT32_C( 1707281414), INT32_C( -950943112)),
      simde_x_vload_s32(INT32_C(  120975835), INT32_C( 1101446696)) },
    { simde_x_vload_s32(INT32_C( 1903820709), INT32_C( 1232738400)),
      simde_x_vload_s32(INT32_C( 1175804105), INT32_C(  471869475)),
      simde_x_vload_s32(INT32_C(-1215342482), INT32_C( 1704607875)) },
    { simde_x_vload_s32(INT32_C(  586139081), INT32_C(-1490549666)),
      simde_x_vload_s32(INT32_C( 1494115913), INT32_C( 1735240216)),
      simde_x_vload_s32(INT32_C( 2080254994), INT32_C(  244690550)) },
    { simde_x_vload_s32(INT32_C(-2127896850), INT32_C( -252178600)),
      simde_x_vload_s32(INT32_C( 1346447250), INT32_C(-1816044415)),
      simde_x_vload_s32(INT32_C( -781449600), INT32_C(-2068223015)) },
    { simde_x_vload_s32(INT32_C( -289397194), INT32_C( -854380851)),
      simde_x_vload_s32(INT32_C(-1534583918), INT32_C( -458543393)),
      simde_x_vload_s32(INT32_C(-1823981112), INT32_C(-1312924244)) },
    { simde_x_vload_s32(INT32_C(-2120486698), INT32_C(  -84491385)),
      simde_x_vload_s32(INT32_C(-1124596104), INT32_C(-1879357706)),
      simde_x_vload_s32(INT32_C( 1049884494), INT32_C(-1963849091)) },
    { simde_x_vload_s32(INT32_C(-1050908339), INT32_C( 1938215650)),
      simde_x_vload_s32(INT32_C(  -32814145), INT32_C( -234392498)),
      simde_x_vload_s32(INT32_C(-1083722484), INT32_C( 1703823152)) },
    { simde_x_vload_s32(INT32_C(  123654668), INT32_C(-1635229690)),
      simde_x_vload_s32(INT32_C( 1218636017), INT32_C( -914807729)),
      simde_x_vload_s32(INT32_C( 1342290685), INT32_C( 1744929877)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_int32x2_t r = simde_vadd_s32(test_vec[i].a, test_vec[i].b);
    simde_neon_assert_int32x2(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_vadd_s64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_int64x1_t a;
    simde_int64x1_t b;
    simde_int64x1_t r;
  } test_vec[8] = {
    { simde_x_vload_s64(INT64_C( 8814947106712380885)),
      simde_x_vload_s64(INT64_C(-4084269564689183738)),
      simde_x_vload_s64(INT64_C( 4730677542023197147)) },
    { simde_x_vload_s64(INT64_C( 5294571114427187109)),
      simde_x_vload_s64(INT64_C( 2026663964281493705)),
      simde_x_vload_s64(INT64_C( 7321235078708680814)) },
    { simde_x_vload_s64(INT64_C(-6401862067947584055)),
      simde_x_vload_s64(INT64_C( 7452799979918091849)),
      simde_x_vload_s64(INT64_C( 1050937911970507794)) },
    { simde_x_vload_s64(INT64_C(-1083098837583995154)),
      simde_x_vload_s64(INT64_C(-7799851369162004590)),
      simde_x_vload_s64(INT64_C(-8882950206745999744)) },
    { simde_x_vload_s64(INT64_C(-3669537809368078794)),
      simde_x_vload_s64(INT64_C(-1969428873971491950)),
      simde_x_vload_s64(INT64_C(-5638966683339570744)) },
    { simde_x_vload_s64(INT64_C( -362887733194264362)),
      simde_x_vload_s64(INT64_C(-8071779881585211784)),
      simde_x_vload_s64(INT64_C(-8434667614779476146)) },
    { simde_x_vload_s64(INT64_C( 8324572832589441357)),
      simde_x_vload_s64(INT64_C(-1006708109075592257)),
      simde_x_vload_s64(INT64_C( 7317864723513849100)) },
    { simde_x_vload_s64(INT64_C(-7023258039874563572)),
      simde_x_vload_s64(INT64_C(-3929069276964394767)),
      simde_x_vload_s64(INT64_C( 7494416756870593277)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_int64x1_t r = simde_vadd_s64(test_vec[i].a, test_vec[i].b);
    simde_neon_assert_int64x1(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_vadd_u8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_uint8x8_t a;
    simde_uint8x8_t b;
    simde_uint8x8_t r;
  } test_vec[8] = {
    { simde_x_vload_u8(UINT8_C(185), UINT8_C(152), UINT8_C(111), UINT8_C(192),
                       UINT8_C( 44), UINT8_C(  4), UINT8_C(146), UINT8_C(  3)),
      simde_x_vload_u8(UINT8_C( 93), UINT8_C(234), UINT8_C(190), UINT8_C(171),
                       UINT8_C(128), UINT8_C( 70), UINT8_C( 74), UINT8_C(208)),
      simde_x_vload_u8(UINT8_C( 22), UINT8_C(130), UINT8_C( 45), UINT8_C(107),
                       UINT8_C(172), UINT8_C( 74), UINT8_C(220), UINT8_C(211)) },
    { simde_x_vload_u8(UINT8_C(103), UINT8_C(234), UINT8_C(135), UINT8_C(173),
                       UINT8_C( 44), UINT8_C(235), UINT8_C(155), UINT8_C(167)),
      simde_x_vload_u8(UINT8_C( 22), UINT8_C( 62), UINT8_C(  8), UINT8_C(119),
                       UINT8_C( 34), UINT8_C(254), UINT8_C( 15), UINT8_C(  2)),
      simde_x_vload_u8(UINT8_C(125), UINT8_C( 40), UINT8_C(143), UINT8_C( 36),
                       UINT8_C( 78), UINT8_C(233), UINT8_C(170), UINT8_C(169)) },
    { simde_x_vload_u8(UINT8_C(220), UINT8_C( 81), UINT8_C(125), UINT8_C(185),
                       UINT8_C( 37), UINT8_C(250), UINT8_C(253), UINT8_C( 58)),
      simde_x_vload_u8(UINT8_C(192), UINT8_C(128), UINT8_C(150), UINT8_C(240),
                       UINT8_C( 19), UINT8_C(220), UINT8_C( 38), UINT8_C(251)),
      simde_x_vload_u8(UINT8_C(156), UINT8_C(209), UINT8_C( 19), UINT8_C(169),
                       UINT8_C( 56), UINT8_C(214), UINT8_C( 35), UINT8_C( 53)) },
    { simde_x_vload_u8(UINT8_C( 15), UINT8_C(  9), UINT8_C(207), UINT8_C(252),
                       UINT8_C( 60), UINT8_C(109), UINT8_C(233), UINT8_C( 92)),
      simde_x_vload_u8(UINT8_C( 85), UINT8_C(151), UINT8_C(198), UINT8_C(100),
                       UINT8_C( 48), UINT8_C( 65), UINT8_C(192), UINT8_C(194)),
      simde_x_vload_u8(UINT8_C(100), UINT8_C(160), UINT8_C(149), UINT8_C( 96),
                       UINT8_C(108), UINT8_C(174), UINT8_C(169), UINT8_C( 30)) },
    { simde_x_vload_u8(UINT8_C( 72), UINT8_C(234), UINT8_C(163), UINT8_C( 48),
                       UINT8_C(  0), UINT8_C( 65), UINT8_C(140), UINT8_C(131)),
      simde_x_vload_u8(UINT8_C( 71), UINT8_C( 13), UINT8_C(157), UINT8_C(236),
                       UINT8_C(180), UINT8_C(139), UINT8_C(204), UINT8_C( 25)),
      simde_x_vload_u8(UINT8_C(143), UINT8_C(247), UINT8_C( 64), UINT8_C( 28),
                       UINT8_C(180), UINT8_C(204), UINT8_C( 88), UINT8_C(156)) },
    { simde_x_vload_u8(UINT8_C( 44), UINT8_C(197), UINT8_C( 43), UINT8_C(200),
                       UINT8_C(195), UINT8_C(185), UINT8_C( 14), UINT8_C( 97)),
      simde_x_vload_u8(UINT8_C(223), UINT8_C(246), UINT8_C(129), UINT8_C(240),
                       UINT8_C(147), UINT8_C( 17), UINT8_C( 38), UINT8_C( 40)),
      simde_x_vload_u8(UINT8_C( 11), UINT8_C(187), UINT8_C(172), UINT8_C(184),
                       UINT8_C( 86), UINT8_C(202), UINT8_C( 52), UINT8_C(137)) },
    { simde_x_vload_u8(UINT8_C(247), UINT8_C( 58), UINT8_C( 56), UINT8_C(135),
                       UINT8_C(202), UINT8_C( 44), UINT8_C( 87), UINT8_C(202)),
      simde_x_vload_u8(UINT8_C(129), UINT8_C( 30), UINT8_C( 48), UINT8_C(194),
                       UINT8_C( 89), UINT8_C(122), UINT8_C(115), UINT8_C(161)),
      simde_x_vload_u8(UINT8_C(120), UINT8_C( 88), UINT8_C(104), UINT8_C( 73),
                       UINT8_C( 35), UINT8_C(166), UINT8_C(202), UINT8_C(107)) },
    { simde_x_vload_u8(UINT8_C(179), UINT8_C(  3), UINT8_C(235), UINT8_C(114),
                       UINT8_C(108), UINT8_C(170), UINT8_C(174), UINT8_C(140)),
      simde_x_vload_u8(UINT8_C(166), UINT8_C(255), UINT8_C(112), UINT8_C(161),
                       UINT8_C(  0), UINT8_C(151), UINT8_C( 43), UINT8_C(160)),
      simde_x_vload_u8(UINT8_C( 89), UINT8_C(  2), UINT8_C( 91), UINT8_C( 19),
                       UINT8_C(108), UINT8_C( 65), UINT8_C(217), UINT8_C( 44)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_uint8x8_t r = simde_vadd_u8(test_vec[i].a, test_vec[i].b);
    simde_neon_assert_uint8x8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_vadd_u16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_uint16x4_t a;
    simde_uint16x4_t b;
    simde_uint16x4_t r;
  } test_vec[8] = {
    { simde_x_vload_u16(UINT16_C(39097), UINT16_C(49263), UINT16_C( 1068), UINT16_C(  914)),
      simde_x_vload_u16(UINT16_C(59997), UINT16_C(43966), UINT16_C(18048), UINT16_C(53322)),
      simde_x_vload_u16(UINT16_C(33558), UINT16_C(27693), UINT16_C(19116), UINT16_C(54236)) },
    { simde_x_vload_u16(UINT16_C(60007), UINT16_C(44423), UINT16_C(60204), UINT16_C(42907)),
      simde_x_vload_u16(UINT16_C(15894), UINT16_C(30472), UINT16_C(65058), UINT16_C(  527)),
      simde_x_vload_u16(UINT16_C(10365), UINT16_C( 9359), UINT16_C(59726), UINT16_C(43434)) },
    { simde_x_vload_u16(UINT16_C(20956), UINT16_C(47485), UINT16_C(64037), UINT16_C(15101)),
      simde_x_vload_u16(UINT16_C(32960), UINT16_C(61590), UINT16_C(56339), UINT16_C(64294)),
      simde_x_vload_u16(UINT16_C(53916), UINT16_C(43539), UINT16_C(54840), UINT16_C(13859)) },
    { simde_x_vload_u16(UINT16_C( 2319), UINT16_C(64719), UINT16_C(27964), UINT16_C(23785)),
      simde_x_vload_u16(UINT16_C(38741), UINT16_C(25798), UINT16_C(16688), UINT16_C(49856)),
      simde_x_vload_u16(UINT16_C(41060), UINT16_C(24981), UINT16_C(44652), UINT16_C( 8105)) },
    { simde_x_vload_u16(UINT16_C(59976), UINT16_C(12451), UINT16_C(16640), UINT16_C(33676)),
      simde_x_vload_u16(UINT16_C( 3399), UINT16_C(60573), UINT16_C(35764), UINT16_C( 6604)),
      simde_x_vload_u16(UINT16_C(63375), UINT16_C( 7488), UINT16_C(52404), UINT16_C(40280)) },
    { simde_x_vload_u16(UINT16_C(50476), UINT16_C(51243), UINT16_C(47555), UINT16_C(24846)),
      simde_x_vload_u16(UINT16_C(63199), UINT16_C(61569), UINT16_C( 4499), UINT16_C(10278)),
      simde_x_vload_u16(UINT16_C(48139), UINT16_C(47276), UINT16_C(52054), UINT16_C(35124)) },
    { simde_x_vload_u16(UINT16_C(15095), UINT16_C(34616), UINT16_C(11466), UINT16_C(51799)),
      simde_x_vload_u16(UINT16_C( 7809), UINT16_C(49712), UINT16_C(31321), UINT16_C(41331)),
      simde_x_vload_u16(UINT16_C(22904), UINT16_C(18792), UINT16_C(42787), UINT16_C(27594)) },
    { simde_x_vload_u16(UINT16_C(  947), UINT16_C(29419), UINT16_C(43628), UINT16_C(36014)),
      simde_x_vload_u16(UINT16_C(65446), UINT16_C(41328), UINT16_C(38656), UINT16_C(41003)),
      simde_x_vload_u16(UINT16_C(  857), UINT16_C( 5211), UINT16_C(16748), UINT16_C(11481)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_uint16x4_t r = simde_vadd_u16(test_vec[i].a, test_vec[i].b);
    simde_neon_assert_uint16x4(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_vadd_u32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_uint32x2_t a;
    simde_uint32x2_t b;
    simde_uint32x2_t r;
  } test_vec[8] = {
    { simde_x_vload_u32(UINT32_C(3228539065), UINT32_C(  59900972)),
      simde_x_vload_u32(UINT32_C(2881415773), UINT32_C(3494528640)),
      simde_x_vload_u32(UINT32_C(1814987542), UINT32_C(3554429612)) },
    { simde_x_vload_u32(UINT32_C(2911365735), UINT32_C(2812013356)),
      simde_x_vload_u32(UINT32_C(1997028886), UINT32_C(  34602530)),
      simde_x_vload_u32(UINT32_C( 613427325), UINT32_C(2846615886)) },
    { simde_x_vload_u32(UINT32_C(3111997916), UINT32_C( 989723173)),
      simde_x_vload_u32(UINT32_C(4036395200), UINT32_C(4213627923)),
      simde_x_vload_u32(UINT32_C(2853425820), UINT32_C( 908383800)) },
    { simde_x_vload_u32(UINT32_C(4241426703), UINT32_C(1558801724)),
      simde_x_vload_u32(UINT32_C(1690736469), UINT32_C(3267379504)),
      simde_x_vload_u32(UINT32_C(1637195876), UINT32_C( 531213932)) },
    { simde_x_vload_u32(UINT32_C( 816048712), UINT32_C(2207006976)),
      simde_x_vload_u32(UINT32_C(3969715527), UINT32_C( 432835508)),
      simde_x_vload_u32(UINT32_C( 490796943), UINT32_C(2639842484)) },
    { simde_x_vload_u32(UINT32_C(3358311724), UINT32_C(1628355011)),
      simde_x_vload_u32(UINT32_C(4035049183), UINT32_C( 673583507)),
      simde_x_vload_u32(UINT32_C(3098393611), UINT32_C(2301938518)) },
    { simde_x_vload_u32(UINT32_C(2268609271), UINT32_C(3394710730)),
      simde_x_vload_u32(UINT32_C(3257933441), UINT32_C(2708699737)),
      simde_x_vload_u32(UINT32_C(1231575416), UINT32_C(1808443171)) },
    { simde_x_vload_u32(UINT32_C(1928004531), UINT32_C(2360257132)),
      simde_x_vload_u32(UINT32_C(2708537254), UINT32_C(2687211264)),
      simde_x_vload_u32(UINT32_C( 341574489), UINT32_C( 752501100)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_uint32x2_t r = simde_vadd_u32(test_vec[i].a, test_vec[i].b);
    simde_neon_assert_uint32x2(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_vadd_u64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_uint64x1_t a;
    simde_uint64x1_t b;
    simde_uint64x1_t r;
  } test_vec[8] = {
    { simde_x_vload_u64(UINT64_C(2988365797476798144)),
      simde_x_vload_u64(UINT64_C(14536346859563613917)),
      simde_x_vload_u64(UINT64_C(17524712657040412061)) },
    { simde_x_vload_u64(UINT64_C(5678633365736443338)),
      simde_x_vload_u64(UINT64_C(4940129491139631581)),
      simde_x_vload_u64(UINT64_C(10618762856876074919)) },
    { simde_x_vload_u64(UINT64_C(  29909639398620333)),
      simde_x_vload_u64(UINT64_C(8546208132393020897)),
      simde_x_vload_u64(UINT64_C(8576117771791641230)) },
    { simde_x_vload_u64(UINT64_C(9321457332119617943)),
      simde_x_vload_u64(UINT64_C(18128308684460165007)),
      simde_x_vload_u64(UINT64_C(9003021942870231334)) },
    { simde_x_vload_u64(UINT64_C(8923015922424851036)),
      simde_x_vload_u64(UINT64_C(3997597374735367052)),
      simde_x_vload_u64(UINT64_C(12920613297160218088)) },
    { simde_x_vload_u64(UINT64_C(4178088500218833773)),
      simde_x_vload_u64(UINT64_C(17782660096017580449)),
      simde_x_vload_u64(UINT64_C(3514004522526862606)) },
    { simde_x_vload_u64(UINT64_C(11558839574564786513)),
      simde_x_vload_u64(UINT64_C(14330555088518900538)),
      simde_x_vload_u64(UINT64_C(7442650589374135435)) },
    { simde_x_vload_u64(UINT64_C(4522764093253119630)),
      simde_x_vload_u64(UINT64_C(15810665949067353962)),
      simde_x_vload_u64(UINT64_C(1886685968610921976)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_uint64x1_t r = simde_vadd_u64(test_vec[i].a, test_vec[i].b);
    simde_neon_assert_uint64x1(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_vadd_f32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_float32x2_t a;
    simde_float32x2_t b;
    simde_float32x2_t r;
  } test_vec[8] = {
    { simde_x_vload_f32(SIMDE_FLOAT32_C( -834.90), SIMDE_FLOAT32_C(  684.58)),
      simde_x_vload_f32(SIMDE_FLOAT32_C( -781.01), SIMDE_FLOAT32_C(  417.00)),
      simde_x_vload_f32(SIMDE_FLOAT32_C(-1615.91), SIMDE_FLOAT32_C( 1101.58)) },
    { simde_x_vload_f32(SIMDE_FLOAT32_C( -723.37), SIMDE_FLOAT32_C(  743.19)),
      simde_x_vload_f32(SIMDE_FLOAT32_C(   -5.84), SIMDE_FLOAT32_C(  244.51)),
      simde_x_vload_f32(SIMDE_FLOAT32_C( -729.21), SIMDE_FLOAT32_C(  987.70)) },
    { simde_x_vload_f32(SIMDE_FLOAT32_C(  604.56), SIMDE_FLOAT32_C(  504.88)),
      simde_x_vload_f32(SIMDE_FLOAT32_C(  347.99), SIMDE_FLOAT32_C( -637.93)),
      simde_x_vload_f32(SIMDE_FLOAT32_C(  952.55), SIMDE_FLOAT32_C( -133.05)) },
    { simde_x_vload_f32(SIMDE_FLOAT32_C( -410.97), SIMDE_FLOAT32_C( -536.76)),
      simde_x_vload_f32(SIMDE_FLOAT32_C(  364.65), SIMDE_FLOAT32_C(  953.49)),
      simde_x_vload_f32(SIMDE_FLOAT32_C(  -46.32), SIMDE_FLOAT32_C(  416.73)) },
    { simde_x_vload_f32(SIMDE_FLOAT32_C( -705.16), SIMDE_FLOAT32_C( -740.50)),
      simde_x_vload_f32(SIMDE_FLOAT32_C( -539.36), SIMDE_FLOAT32_C(  287.38)),
      simde_x_vload_f32(SIMDE_FLOAT32_C(-1244.52), SIMDE_FLOAT32_C( -453.12)) },
    { simde_x_vload_f32(SIMDE_FLOAT32_C( -693.05), SIMDE_FLOAT32_C(  261.81)),
      simde_x_vload_f32(SIMDE_FLOAT32_C( -149.85), SIMDE_FLOAT32_C(   15.54)),
      simde_x_vload_f32(SIMDE_FLOAT32_C( -842.90), SIMDE_FLOAT32_C(  277.35)) },
    { simde_x_vload_f32(SIMDE_FLOAT32_C(  190.69), SIMDE_FLOAT32_C(  179.84)),
      simde_x_vload_f32(SIMDE_FLOAT32_C(  846.94), SIMDE_FLOAT32_C(  141.87)),
      simde_x_vload_f32(SIMDE_FLOAT32_C( 1037.63), SIMDE_FLOAT32_C(  321.71)) },
    { simde_x_vload_f32(SIMDE_FLOAT32_C( -309.61), SIMDE_FLOAT32_C( -413.80)),
      simde_x_vload_f32(SIMDE_FLOAT32_C(  924.34), SIMDE_FLOAT32_C( -825.49)),
      simde_x_vload_f32(SIMDE_FLOAT32_C(  614.73), SIMDE_FLOAT32_C(-1239.29)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_float32x2_t r = simde_vadd_f32(test_vec[i].a, test_vec[i].b);
    simde_neon_assert_float32x2_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_vadd_f64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_float64x1_t a;
    simde_float64x1_t b;
    simde_float64x1_t r;
  } test_vec[8] = {
    { simde_x_vload_f64(SIMDE_FLOAT64_C( -834.90)),
      simde_x_vload_f64(SIMDE_FLOAT64_C(  684.58)),
      simde_x_vload_f64(SIMDE_FLOAT64_C( -150.32)) },
    { simde_x_vload_f64(SIMDE_FLOAT64_C( -781.01)),
      simde_x_vload_f64(SIMDE_FLOAT64_C(  417.00)),
      simde_x_vload_f64(SIMDE_FLOAT64_C( -364.01)) },
    { simde_x_vload_f64(SIMDE_FLOAT64_C( -723.37)),
      simde_x_vload_f64(SIMDE_FLOAT64_C(  743.19)),
      simde_x_vload_f64(SIMDE_FLOAT64_C(   19.82)) },
    { simde_x_vload_f64(SIMDE_FLOAT64_C(   -5.84)),
      simde_x_vload_f64(SIMDE_FLOAT64_C(  244.51)),
      simde_x_vload_f64(SIMDE_FLOAT64_C(  238.67)) },
    { simde_x_vload_f64(SIMDE_FLOAT64_C(  604.56)),
      simde_x_vload_f64(SIMDE_FLOAT64_C(  504.88)),
      simde_x_vload_f64(SIMDE_FLOAT64_C( 1109.44)) },
    { simde_x_vload_f64(SIMDE_FLOAT64_C(  347.99)),
      simde_x_vload_f64(SIMDE_FLOAT64_C( -637.93)),
      simde_x_vload_f64(SIMDE_FLOAT64_C( -289.94)) },
    { simde_x_vload_f64(SIMDE_FLOAT64_C( -410.97)),
      simde_x_vload_f64(SIMDE_FLOAT64_C( -536.76)),
      simde_x_vload_f64(SIMDE_FLOAT64_C( -947.73)) },
    { simde_x_vload_f64(SIMDE_FLOAT64_C(  364.65)),
      simde_x_vload_f64(SIMDE_FLOAT64_C(  953.49)),
      simde_x_vload_f64(SIMDE_FLOAT64_C( 1318.14)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_float64x1_t r = simde_vadd_f64(test_vec[i].a, test_vec[i].b);
    simde_neon_assert_float64x1_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_vaddq_s8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_int8x16_t a;
    simde_int8x16_t b;
    simde_int8x16_t r;
  } test_vec[8] = {
    { simde_x_vloadq_s8(INT8_C(  53), INT8_C(  15), INT8_C( -70), INT8_C( 118),
                        INT8_C(  -6), INT8_C( -39), INT8_C( -36), INT8_C(  27),
                        INT8_C(   1), INT8_C(  43), INT8_C(  75), INT8_C( -90),
                        INT8_C(-125), INT8_C(-112), INT8_C(  64), INT8_C( -44)),
      simde_x_vloadq_s8(INT8_C( -32), INT8_C( -57), INT8_C(   5), INT8_C( 114),
                        INT8_C( -78), INT8_C(  24), INT8_C( 115), INT8_C(   9),
                        INT8_C(  50), INT8_C(-122), INT8_C(  38), INT8_C(  39),
                        INT8_C(  82), INT8_C(  11), INT8_C(  39), INT8_C(  85)),
      simde_x_vloadq_s8(INT8_C(  21), INT8_C( -42), INT8_C( -65), INT8_C( -24),
                        INT8_C( -84), INT8_C( -15), INT8_C(  79), INT8_C(  36),
                        INT8_C(  51), INT8_C( -79), INT8_C( 113), INT8_C( -51),
                        INT8_C( -43), INT8_C(-101), INT8_C( 103), INT8_C(  41)) },
    { simde_x_vloadq_s8(INT8_C(  26), INT8_C(  34), INT8_C( -69), INT8_C(  50),
                        INT8_C( -20), INT8_C( 105), INT8_C(  74), INT8_C(  96),
                        INT8_C(  80), INT8_C(-106), INT8_C( 105), INT8_C(  50),
                        INT8_C( -86), INT8_C( 106), INT8_C(   4), INT8_C(  54)),
      simde_x_vloadq_s8(INT8_C(  37), INT8_C( -63), INT8_C( -54), INT8_C(  84),
                        INT8_C( 123), INT8_C(  44), INT8_C(  65), INT8_C( -23),
                        INT8_C( 109), INT8_C( -83), INT8_C(   8), INT8_C( 112),
                        INT8_C( 122), INT8_C( -89), INT8_C(-126), INT8_C( 111)),
      simde_x_vloadq_s8(INT8_C(  63), INT8_C( -29), INT8_C(-123), INT8_C(-122),
                        INT8_C( 103), INT8_C(-107), INT8_C(-117), INT8_C(  73),
                        INT8_C( -67), INT8_C(  67), INT8_C( 113), INT8_C( -94),
                        INT8_C(  36), INT8_C(  17), INT8_C(-122), INT8_C( -91)) },
    { simde_x_vloadq_s8(INT8_C(  70), INT8_C(  44), INT8_C(-119), INT8_C( 109),
                        INT8_C(  43), INT8_C( -72), INT8_C( -50), INT8_C(  23),
                        INT8_C(  99), INT8_C(  79), INT8_C( -34), INT8_C(  42),
                        INT8_C(  17), INT8_C(   6), INT8_C( 107), INT8_C( -47)),
      simde_x_vloadq_s8(INT8_C(-104), INT8_C( -54), INT8_C(  81), INT8_C( -59),
                        INT8_C(   7), INT8_C(  72), INT8_C( 109), INT8_C(  54),
                        INT8_C(  65), INT8_C(  40), INT8_C( -74), INT8_C(  54),
                        INT8_C(  49), INT8_C( -36), INT8_C(   4), INT8_C(  70)),
      simde_x_vloadq_s8(INT8_C( -34), INT8_C( -10), INT8_C( -38), INT8_C(  50),
                        INT8_C(  50), INT8_C(   0), INT8_C(  59), INT8_C(  77),
                        INT8_C( -92), INT8_C( 119), INT8_C(-108), INT8_C(  96),
                        INT8_C(  66), INT8_C( -30), INT8_C( 111), INT8_C(  23)) },
    { simde_x_vloadq_s8(INT8_C(  84), INT8_C(  50), INT8_C(  -1), INT8_C( 124),
                        INT8_C( -16), INT8_C(  60), INT8_C(  71), INT8_C(  96),
                        INT8_C(  88), INT8_C(  55), INT8_C( -28), INT8_C(-102),
                        INT8_C(-110), INT8_C(  98), INT8_C(-122), INT8_C( -47)),
      simde_x_vloadq_s8(INT8_C( -32), INT8_C(  44), INT8_C( -49), INT8_C(  34),
                        INT8_C(  41), INT8_C(  91), INT8_C( -87), INT8_C(  18),
                        INT8_C(  67), INT8_C( -69), INT8_C( -17), INT8_C(  15),
                        INT8_C( -51), INT8_C(-117), INT8_C(-122), INT8_C(  81)),
      simde_x_vloadq_s8(INT8_C(  52), INT8_C(  94), INT8_C( -50), INT8_C( -98),
                        INT8_C(  25), INT8_C(-105), INT8_C( -16), INT8_C( 114),
                        INT8_C(-101), INT8_C( -14), INT8_C( -45), INT8_C( -87),
                        INT8_C(  95), INT8_C( -19), INT8_C(  12), INT8_C(  34)) },
    { simde_x_vloadq_s8(INT8_C(-101), INT8_C(-111), INT8_C( -83), INT8_C( -75),
                        INT8_C(-114), INT8_C(  70), INT8_C(-116), INT8_C( -78),
                        INT8_C(  99), INT8_C(  72), INT8_C( -50), INT8_C( -21),
                        INT8_C(  21), INT8_C( 114), INT8_C( -80), INT8_C( -56)),
      simde_x_vloadq_s8(INT8_C(-127), INT8_C( -98), INT8_C( -63), INT8_C(-121),
                        INT8_C( -91), INT8_C(  97), INT8_C(  75), INT8_C(  47),
                        INT8_C( -20), INT8_C( -87), INT8_C(  55), INT8_C( 127),
                        INT8_C( -46), INT8_C(  79), INT8_C(  66), INT8_C( -94)),
      simde_x_vloadq_s8(INT8_C(  28), INT8_C(  47), INT8_C( 110), INT8_C(  60),
                        INT8_C(  51), INT8_C( -89), INT8_C( -41), INT8_C( -31),
                        INT8_C(  79), INT8_C( -15), INT8_C(   5), INT8_C( 106),
                        INT8_C( -25), INT8_C( -63), INT8_C( -14), INT8_C( 106)) },
    { simde_x_vloadq_s8(INT8_C( 118), INT8_C( 124), INT8_C(  52), INT8_C(  99),
                        INT8_C(-111), INT8_C( -18), INT8_C( -39), INT8_C(  66),
                        INT8_C(  89), INT8_C(  66), INT8_C( -38), INT8_C( -40),
                        INT8_C( -16), INT8_C( -47), INT8_C(  79), INT8_C( 123)),
      simde_x_vloadq_s8(INT8_C(-100), INT8_C(  50), INT8_C( -86), INT8_C(  68),
                        INT8_C(-114), INT8_C(  55), INT8_C( -89), INT8_C(-125),
                        INT8_C(  24), INT8_C(-108), INT8_C( -96), INT8_C(  79),
                        INT8_C( -73), INT8_C( -30), INT8_C(  20), INT8_C(   8)),
      simde_x_vloadq_s8(INT8_C(  18), INT8_C( -82), INT8_C( -34), INT8_C( -89),
                        INT8_C(  31), INT8_C(  37), INT8_C(-128), INT8_C( -59),
                        INT8_C( 113), INT8_C( -42), INT8_C( 122), INT8_C(  39),
                        INT8_C( -89), INT8_C( -77), INT8_C(  99), INT8_C(-125)) },
    { simde_x_vloadq_s8(INT8_C( 109), INT8_C( -88), INT8_C( 118), INT8_C(  45),
                        INT8_C( -31), INT8_C( -50), INT8_C(  46), INT8_C(  10),
                        INT8_C( -66), INT8_C(  77), INT8_C( -14), INT8_C(  46),
                        INT8_C(  14), INT8_C(  -8), INT8_C(  49), INT8_C(  81)),
      simde_x_vloadq_s8(INT8_C(  45), INT8_C( -99), INT8_C(  -3), INT8_C(  63),
                        INT8_C( -31), INT8_C( -61), INT8_C( -34), INT8_C( -95),
                        INT8_C(  24), INT8_C(   6), INT8_C(-122), INT8_C( -15),
                        INT8_C(  80), INT8_C(-105), INT8_C(  91), INT8_C( -78)),
      simde_x_vloadq_s8(INT8_C(-102), INT8_C(  69), INT8_C( 115), INT8_C( 108),
                        INT8_C( -62), INT8_C(-111), INT8_C(  12), INT8_C( -85),
                        INT8_C( -42), INT8_C(  83), INT8_C( 120), INT8_C(  31),
                        INT8_C(  94), INT8_C(-113), INT8_C(-116), INT8_C(   3)) },
    { simde_x_vloadq_s8(INT8_C(-127), INT8_C( -39), INT8_C( -66), INT8_C(-127),
                        INT8_C( 120), INT8_C( -61), INT8_C(  -4), INT8_C( -67),
                        INT8_C( 101), INT8_C( -46), INT8_C( -28), INT8_C( -35),
                        INT8_C(  73), INT8_C( -80), INT8_C( -70), INT8_C(  33)),
      simde_x_vloadq_s8(INT8_C(-120), INT8_C( 119), INT8_C( 102), INT8_C( -58),
                        INT8_C( -14), INT8_C( -11), INT8_C( -39), INT8_C(  65),
                        INT8_C( -62), INT8_C( -79), INT8_C( -52), INT8_C( 112),
                        INT8_C(-104), INT8_C( -95), INT8_C(  77), INT8_C( -82)),
      simde_x_vloadq_s8(INT8_C(   9), INT8_C(  80), INT8_C(  36), INT8_C(  71),
                        INT8_C( 106), INT8_C( -72), INT8_C( -43), INT8_C(  -2),
                        INT8_C(  39), INT8_C(-125), INT8_C( -80), INT8_C(  77),
                        INT8_C( -31), INT8_C(  81), INT8_C(   7), INT8_C( -49)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_int8x16_t r = simde_vaddq_s8(test_vec[i].a, test_vec[i].b);
    simde_neon_assert_int8x16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_vaddq_s16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_int16x8_t a;
    simde_int16x8_t b;
    simde_int16x8_t r;
  } test_vec[8] = {
    { simde_x_vloadq_s16(INT16_C(  3893), INT16_C( 30394), INT16_C( -9734), INT16_C(  7132),
                         INT16_C( 11009), INT16_C(-22965), INT16_C(-28541), INT16_C(-11200)),
      simde_x_vloadq_s16(INT16_C(-14368), INT16_C( 29189), INT16_C(  6322), INT16_C(  2419),
                         INT16_C(-31182), INT16_C( 10022), INT16_C(  2898), INT16_C( 21799)),
      simde_x_vloadq_s16(INT16_C(-10475), INT16_C( -5953), INT16_C( -3412), INT16_C(  9551),
                         INT16_C(-20173), INT16_C(-12943), INT16_C(-25643), INT16_C( 10599)) },
    { simde_x_vloadq_s16(INT16_C(  8730), INT16_C( 12987), INT16_C( 27116), INT16_C( 24650),
                         INT16_C(-27056), INT16_C( 12905), INT16_C( 27306), INT16_C( 13828)),
      simde_x_vloadq_s16(INT16_C(-16091), INT16_C( 21706), INT16_C( 11387), INT16_C( -5823),
                         INT16_C(-21139), INT16_C( 28680), INT16_C(-22662), INT16_C( 28546)),
      simde_x_vloadq_s16(INT16_C( -7361), INT16_C(-30843), INT16_C(-27033), INT16_C( 18827),
                         INT16_C( 17341), INT16_C(-23951), INT16_C(  4644), INT16_C(-23162)) },
    { simde_x_vloadq_s16(INT16_C( 11334), INT16_C( 28041), INT16_C(-18389), INT16_C(  6094),
                         INT16_C( 20323), INT16_C( 10974), INT16_C(  1553), INT16_C(-11925)),
      simde_x_vloadq_s16(INT16_C(-13672), INT16_C(-15023), INT16_C( 18439), INT16_C( 13933),
                         INT16_C( 10305), INT16_C( 14006), INT16_C( -9167), INT16_C( 17924)),
      simde_x_vloadq_s16(INT16_C( -2338), INT16_C( 13018), INT16_C(    50), INT16_C( 20027),
                         INT16_C( 30628), INT16_C( 24980), INT16_C( -7614), INT16_C(  5999)) },
    { simde_x_vloadq_s16(INT16_C( 12884), INT16_C( 31999), INT16_C( 15600), INT16_C( 24647),
                         INT16_C( 14168), INT16_C(-25884), INT16_C( 25234), INT16_C(-11898)),
      simde_x_vloadq_s16(INT16_C( 11488), INT16_C(  8911), INT16_C( 23337), INT16_C(  4777),
                         INT16_C(-17597), INT16_C(  4079), INT16_C(-29747), INT16_C( 20870)),
      simde_x_vloadq_s16(INT16_C( 24372), INT16_C(-24626), INT16_C(-26599), INT16_C( 29424),
                         INT16_C( -3429), INT16_C(-21805), INT16_C( -4513), INT16_C(  8972)) },
    { simde_x_vloadq_s16(INT16_C(-28261), INT16_C(-19027), INT16_C( 18062), INT16_C(-19828),
                         INT16_C( 18531), INT16_C( -5170), INT16_C( 29205), INT16_C(-14160)),
      simde_x_vloadq_s16(INT16_C(-24959), INT16_C(-30783), INT16_C( 24997), INT16_C( 12107),
                         INT16_C(-22036), INT16_C( 32567), INT16_C( 20434), INT16_C(-23998)),
      simde_x_vloadq_s16(INT16_C( 12316), INT16_C( 15726), INT16_C(-22477), INT16_C( -7721),
                         INT16_C( -3505), INT16_C( 27397), INT16_C(-15897), INT16_C( 27378)) },
    { simde_x_vloadq_s16(INT16_C( 31862), INT16_C( 25396), INT16_C( -4463), INT16_C( 17113),
                         INT16_C( 16985), INT16_C(-10022), INT16_C(-11792), INT16_C( 31567)),
      simde_x_vloadq_s16(INT16_C( 12956), INT16_C( 17578), INT16_C( 14222), INT16_C(-31833),
                         INT16_C(-27624), INT16_C( 20384), INT16_C( -7497), INT16_C(  2068)),
      simde_x_vloadq_s16(INT16_C(-20718), INT16_C(-22562), INT16_C(  9759), INT16_C(-14720),
                         INT16_C(-10639), INT16_C( 10362), INT16_C(-19289), INT16_C(-31901)) },
    { simde_x_vloadq_s16(INT16_C(-22419), INT16_C( 11638), INT16_C(-12575), INT16_C(  2606),
                         INT16_C( 19902), INT16_C( 12018), INT16_C( -2034), INT16_C( 20785)),
      simde_x_vloadq_s16(INT16_C(-25299), INT16_C( 16381), INT16_C(-15391), INT16_C(-24098),
                         INT16_C(  1560), INT16_C( -3706), INT16_C(-26800), INT16_C(-19877)),
      simde_x_vloadq_s16(INT16_C( 17818), INT16_C( 28019), INT16_C(-27966), INT16_C(-21492),
                         INT16_C( 21462), INT16_C(  8312), INT16_C(-28834), INT16_C(   908)) },
    { simde_x_vloadq_s16(INT16_C( -9855), INT16_C(-32322), INT16_C(-15496), INT16_C(-16900),
                         INT16_C(-11675), INT16_C( -8732), INT16_C(-20407), INT16_C(  8634)),
      simde_x_vloadq_s16(INT16_C( 30600), INT16_C(-14746), INT16_C( -2574), INT16_C( 16857),
                         INT16_C(-20030), INT16_C( 28876), INT16_C(-24168), INT16_C(-20915)),
      simde_x_vloadq_s16(INT16_C( 20745), INT16_C( 18468), INT16_C(-18070), INT16_C(   -43),
                         INT16_C(-31705), INT16_C( 20144), INT16_C( 20961), INT16_C(-12281)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_int16x8_t r = simde_vaddq_s16(test_vec[i].a, test_vec[i].b);
    simde_neon_assert_int16x8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_vaddq_s32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_int32x4_t a;
    simde_int32x4_t b;
    simde_int32x4_t r;
  } test_vec[8] = {
    { simde_x_vloadq_s32(INT32_C( 1991905077), INT32_C(  467458554),
                         INT32_C(-1505023231), INT32_C( -733966205)),
      simde_x_vloadq_s32(INT32_C( 1912981472), INT32_C(  158537906),
                         INT32_C(  656836146), INT32_C( 1428622162)),
      simde_x_vloadq_s32(INT32_C( -390080747), INT32_C(  625996460),
                         INT32_C( -848187085), INT32_C(  694655957)) },
    { simde_x_vloadq_s32(INT32_C(  851124762), INT32_C( 1615489516),
                         INT32_C(  845780560), INT32_C(  906259114)),
      simde_x_vloadq_s32(INT32_C( 1422573861), INT32_C( -381604741),
                         INT32_C( 1879616877), INT32_C( 1870833530)),
      simde_x_vloadq_s32(INT32_C(-2021268673), INT32_C( 1233884775),
                         INT32_C(-1569569859), INT32_C(-1517874652)) },
    { simde_x_vloadq_s32(INT32_C( 1837706310), INT32_C(  399423531),
                         INT32_C(  719212387), INT32_C( -781515247)),
      simde_x_vloadq_s32(INT32_C( -984495464), INT32_C(  913131527),
                         INT32_C(  917907521), INT32_C( 1174723633)),
      simde_x_vloadq_s32(INT32_C(  853210846), INT32_C( 1312555058),
                         INT32_C( 1637119908), INT32_C(  393208386)) },
    { simde_x_vloadq_s32(INT32_C( 2097099348), INT32_C( 1615281392),
                         INT32_C(-1696319656), INT32_C( -779722094)),
      simde_x_vloadq_s32(INT32_C(  584002784), INT32_C(  313088809),
                         INT32_C(  267369283), INT32_C( 1367772109)),
      simde_x_vloadq_s32(INT32_C(-1613865164), INT32_C( 1928370201),
                         INT32_C(-1428950373), INT32_C(  588050015)) },
    { simde_x_vloadq_s32(INT32_C(-1246916197), INT32_C(-1299429746),
                         INT32_C( -338802589), INT32_C( -927960555)),
      simde_x_vloadq_s32(INT32_C(-2017354111), INT32_C(  793469349),
                         INT32_C( 2134354412), INT32_C(-1572712494)),
      simde_x_vloadq_s32(INT32_C( 1030696988), INT32_C( -505960397),
                         INT32_C( 1795551823), INT32_C( 1794294247)) },
    { simde_x_vloadq_s32(INT32_C( 1664384118), INT32_C( 1121578641),
                         INT32_C( -656784807), INT32_C( 2068828656)),
      simde_x_vloadq_s32(INT32_C( 1152004764), INT32_C(-2086193266),
                         INT32_C( 1335923736), INT32_C(  135586487)),
      simde_x_vloadq_s32(INT32_C(-1478578414), INT32_C( -964614625),
                         INT32_C(  679138929), INT32_C(-2090552153)) },
    { simde_x_vloadq_s32(INT32_C(  762751085), INT32_C(  170839777),
                         INT32_C(  787631550), INT32_C( 1362229262)),
      simde_x_vloadq_s32(INT32_C( 1073585453), INT32_C(-1579236383),
                         INT32_C( -242874856), INT32_C(-1302620336)),
      simde_x_vloadq_s32(INT32_C( 1836336538), INT32_C(-1408396606),
                         INT32_C(  544756694), INT32_C(   59608926)) },
    { simde_x_vloadq_s32(INT32_C(-2118198911), INT32_C(-1107508360),
                         INT32_C( -572206491), INT32_C(  565882953)),
      simde_x_vloadq_s32(INT32_C( -966363256), INT32_C( 1104803314),
                         INT32_C( 1892463042), INT32_C(-1370644072)),
      simde_x_vloadq_s32(INT32_C( 1210405129), INT32_C(   -2705046),
                         INT32_C( 1320256551), INT32_C( -804761119)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_int32x4_t r = simde_vaddq_s32(test_vec[i].a, test_vec[i].b);
    simde_neon_assert_int32x4(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_vaddq_s64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_int64x2_t a;
    simde_int64x2_t b;
    simde_int64x2_t r;
  } test_vec[8] = {
    { simde_x_vloadq_s64(INT64_C( 2007719203657355061), INT64_C(-3152360844054287615)),
      simde_x_vloadq_s64(INT64_C(  680915123359303648), INT64_C( 6135885464787650098)),
      simde_x_vloadq_s64(INT64_C( 2688634327016658709), INT64_C( 2983524620733362483)) },
    { simde_x_vloadq_s64(INT64_C( 6938474639101993498), INT64_C( 3892353257177716304)),
      simde_x_vloadq_s64(INT64_C(-1638979881170976475), INT64_C( 8035168829489851757)),
      simde_x_vloadq_s64(INT64_C( 5299494757931017023), INT64_C(-6519221987041983555)) },
    { simde_x_vloadq_s64(INT64_C( 1715511004735548486), INT64_C(-3356582426471149725)),
      simde_x_vloadq_s64(INT64_C( 3921870048722012824), INT64_C( 5045399586491213889)),
      simde_x_vloadq_s64(INT64_C( 5637381053457561310), INT64_C( 1688817160020064164)) },
    { simde_x_vloadq_s64(INT64_C( 6937580754574455380), INT64_C(-3348880891099990184)),
      simde_x_vloadq_s64(INT64_C( 1344706195982593248), INT64_C( 5874536476803316547)),
      simde_x_vloadq_s64(INT64_C( 8282286950557048628), INT64_C( 2525655585703326363)) },
    { simde_x_vloadq_s64(INT64_C(-5581008259471535717), INT64_C(-3985560231746844573)),
      simde_x_vloadq_s64(INT64_C( 3407924906611023489), INT64_C(-6754748725606241812)),
      simde_x_vloadq_s64(INT64_C(-2173083352860512228), INT64_C( 7706435116356465231)) },
    { simde_x_vloadq_s64(INT64_C( 4817143584651508854), INT64_C( 8885551422185816665)),
      simde_x_vloadq_s64(INT64_C(-8960131849453423972), INT64_C(  582339528780452888)),
      simde_x_vloadq_s64(INT64_C(-4142988264801915118), INT64_C(-8978853122743282063)) },
    { simde_x_vloadq_s64(INT64_C(  733751255833684077), INT64_C( 5850730130731847102)),
      simde_x_vloadq_s64(INT64_C(-6782768616564744915), INT64_C(-5594711738172439016)),
      simde_x_vloadq_s64(INT64_C(-6049017360731060838), INT64_C(  256018392559408086)) },
    { simde_x_vloadq_s64(INT64_C(-4756712184069826175), INT64_C( 2430448780221665893)),
      simde_x_vloadq_s64(INT64_C( 4745094105471022984), INT64_C(-5886871461803806270)),
      simde_x_vloadq_s64(INT64_C(  -11618078598803191), INT64_C(-3456422681582140377)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_int64x2_t r = simde_vaddq_s64(test_vec[i].a, test_vec[i].b);
    simde_neon_assert_int64x2(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_vaddq_u8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_uint8x16_t a;
    simde_uint8x16_t b;
    simde_uint8x16_t r;
  } test_vec[8] = {
    { simde_x_vloadq_u8(UINT8_C(188), UINT8_C(134), UINT8_C(105), UINT8_C( 90),
                        UINT8_C(115), UINT8_C(172), UINT8_C(103), UINT8_C(215),
                        UINT8_C(200), UINT8_C(171), UINT8_C( 67), UINT8_C(161),
                        UINT8_C( 68), UINT8_C(102), UINT8_C(160), UINT8_C(233) ),
      simde_x_vloadq_u8(UINT8_C(215), UINT8_C(208), UINT8_C(191), UINT8_C(234),
                        UINT8_C(107), UINT8_C( 16), UINT8_C( 41), UINT8_C(230),
                        UINT8_C( 93), UINT8_C( 33), UINT8_C(223), UINT8_C( 56),
                        UINT8_C(182), UINT8_C( 57), UINT8_C(117), UINT8_C( 38) ),
      simde_x_vloadq_u8(UINT8_C(147), UINT8_C( 86), UINT8_C( 40), UINT8_C( 68),
                        UINT8_C(222), UINT8_C(188), UINT8_C(144), UINT8_C(189),
                        UINT8_C( 37), UINT8_C(204), UINT8_C( 34), UINT8_C(217),
                        UINT8_C(250), UINT8_C(159), UINT8_C( 21), UINT8_C( 15) ) },
    { simde_x_vloadq_u8(UINT8_C(198), UINT8_C(168), UINT8_C(114), UINT8_C( 45),
                        UINT8_C(120), UINT8_C(180), UINT8_C( 46), UINT8_C( 20),
                        UINT8_C(125), UINT8_C( 64), UINT8_C( 36), UINT8_C( 25),
                        UINT8_C(221), UINT8_C(171), UINT8_C(152), UINT8_C(120) ),
      simde_x_vloadq_u8(UINT8_C( 37), UINT8_C(188), UINT8_C(155), UINT8_C(230),
                        UINT8_C(255), UINT8_C(100), UINT8_C(  3), UINT8_C(214),
                        UINT8_C(123), UINT8_C( 17), UINT8_C(183), UINT8_C( 75),
                        UINT8_C(106), UINT8_C(102), UINT8_C( 69), UINT8_C(134) ),
      simde_x_vloadq_u8(UINT8_C(235), UINT8_C(100), UINT8_C( 13), UINT8_C( 19),
                        UINT8_C(119), UINT8_C( 24), UINT8_C( 49), UINT8_C(234),
                        UINT8_C(248), UINT8_C( 81), UINT8_C(219), UINT8_C(100),
                        UINT8_C( 71), UINT8_C( 17), UINT8_C(221), UINT8_C(254) ) },
    { simde_x_vloadq_u8(UINT8_C(203), UINT8_C( 75), UINT8_C(210), UINT8_C(  5),
                        UINT8_C(239), UINT8_C( 95), UINT8_C(251), UINT8_C(240),
                        UINT8_C(  1), UINT8_C(157), UINT8_C( 93), UINT8_C(211),
                        UINT8_C(236), UINT8_C(109), UINT8_C( 75), UINT8_C( 85) ),
      simde_x_vloadq_u8(UINT8_C(115), UINT8_C(242), UINT8_C(240), UINT8_C(231),
                        UINT8_C(232), UINT8_C(167), UINT8_C( 68), UINT8_C( 79),
                        UINT8_C( 95), UINT8_C( 41), UINT8_C(241), UINT8_C(144),
                        UINT8_C( 21), UINT8_C(128), UINT8_C( 89), UINT8_C( 16) ),
      simde_x_vloadq_u8(UINT8_C( 62), UINT8_C( 61), UINT8_C(194), UINT8_C(236),
                        UINT8_C(215), UINT8_C(  6), UINT8_C( 63), UINT8_C( 63),
                        UINT8_C( 96), UINT8_C(198), UINT8_C( 78), UINT8_C( 99),
                        UINT8_C(  1), UINT8_C(237), UINT8_C(164), UINT8_C(101) ) },
    { simde_x_vloadq_u8(UINT8_C(176), UINT8_C(187), UINT8_C(107), UINT8_C(155),
                        UINT8_C(122), UINT8_C(141), UINT8_C(127), UINT8_C(242),
                        UINT8_C( 59), UINT8_C(181), UINT8_C(146), UINT8_C(252),
                        UINT8_C(172), UINT8_C( 95), UINT8_C( 88), UINT8_C( 48) ),
      simde_x_vloadq_u8(UINT8_C(105), UINT8_C( 84), UINT8_C(163), UINT8_C(145),
                        UINT8_C(133), UINT8_C(115), UINT8_C(225), UINT8_C( 43),
                        UINT8_C(212), UINT8_C(112), UINT8_C(170), UINT8_C( 19),
                        UINT8_C(133), UINT8_C(161), UINT8_C(235), UINT8_C(253) ),
      simde_x_vloadq_u8(UINT8_C( 25), UINT8_C( 15), UINT8_C( 14), UINT8_C( 44),
                        UINT8_C(255), UINT8_C(  0), UINT8_C( 96), UINT8_C( 29),
                        UINT8_C( 15), UINT8_C( 37), UINT8_C( 60), UINT8_C( 15),
                        UINT8_C( 49), UINT8_C(  0), UINT8_C( 67), UINT8_C( 45) ) },
    { simde_x_vloadq_u8(UINT8_C(238), UINT8_C(106), UINT8_C(129), UINT8_C(132),
                        UINT8_C(  7), UINT8_C(152), UINT8_C(167), UINT8_C(234),
                        UINT8_C(158), UINT8_C(133), UINT8_C( 68), UINT8_C(180),
                        UINT8_C(125), UINT8_C( 17), UINT8_C(206), UINT8_C(186) ),
      simde_x_vloadq_u8(UINT8_C(161), UINT8_C(220), UINT8_C(149), UINT8_C(249),
                        UINT8_C(170), UINT8_C( 70), UINT8_C( 71), UINT8_C( 54),
                        UINT8_C(232), UINT8_C(  3), UINT8_C( 72), UINT8_C( 65),
                        UINT8_C(114), UINT8_C(112), UINT8_C( 73), UINT8_C( 15) ),
      simde_x_vloadq_u8(UINT8_C(143), UINT8_C( 70), UINT8_C( 22), UINT8_C(125),
                        UINT8_C(177), UINT8_C(222), UINT8_C(238), UINT8_C( 32),
                        UINT8_C(134), UINT8_C(136), UINT8_C(140), UINT8_C(245),
                        UINT8_C(239), UINT8_C(129), UINT8_C( 23), UINT8_C(201) ) },
    { simde_x_vloadq_u8(UINT8_C(156), UINT8_C(226), UINT8_C( 97), UINT8_C( 45),
                        UINT8_C(  7), UINT8_C(134), UINT8_C(235), UINT8_C(106),
                        UINT8_C(246), UINT8_C(150), UINT8_C(135), UINT8_C( 95),
                        UINT8_C(128), UINT8_C(230), UINT8_C(172), UINT8_C(203) ),
      simde_x_vloadq_u8(UINT8_C(254), UINT8_C(229), UINT8_C(234), UINT8_C(241),
                        UINT8_C(236), UINT8_C( 62), UINT8_C(147), UINT8_C(177),
                        UINT8_C(177), UINT8_C( 83), UINT8_C(242), UINT8_C(236),
                        UINT8_C(123), UINT8_C(171), UINT8_C( 54), UINT8_C( 98) ),
      simde_x_vloadq_u8(UINT8_C(154), UINT8_C(199), UINT8_C( 75), UINT8_C( 30),
                        UINT8_C(243), UINT8_C(196), UINT8_C(126), UINT8_C( 27),
                        UINT8_C(167), UINT8_C(233), UINT8_C(121), UINT8_C( 75),
                        UINT8_C(251), UINT8_C(145), UINT8_C(226), UINT8_C( 45) ) },
    { simde_x_vloadq_u8(UINT8_C( 27), UINT8_C( 14), UINT8_C(184), UINT8_C( 98),
                        UINT8_C( 92), UINT8_C( 40), UINT8_C( 14), UINT8_C(  7),
                        UINT8_C(176), UINT8_C(200), UINT8_C(126), UINT8_C( 52),
                        UINT8_C( 25), UINT8_C( 86), UINT8_C(143), UINT8_C( 77) ),
      simde_x_vloadq_u8(UINT8_C(194), UINT8_C(191), UINT8_C(200), UINT8_C(143),
                        UINT8_C(154), UINT8_C( 17), UINT8_C(211), UINT8_C(182),
                        UINT8_C( 98), UINT8_C( 96), UINT8_C( 74), UINT8_C( 94),
                        UINT8_C(129), UINT8_C(230), UINT8_C( 74), UINT8_C( 44) ),
      simde_x_vloadq_u8(UINT8_C(221), UINT8_C(205), UINT8_C(128), UINT8_C(241),
                        UINT8_C(246), UINT8_C( 57), UINT8_C(225), UINT8_C(189),
                        UINT8_C( 18), UINT8_C( 40), UINT8_C(200), UINT8_C(146),
                        UINT8_C(154), UINT8_C( 60), UINT8_C(217), UINT8_C(121) ) },
    { simde_x_vloadq_u8(UINT8_C(245), UINT8_C(128), UINT8_C( 89), UINT8_C(249),
                        UINT8_C( 36), UINT8_C(187), UINT8_C(  8), UINT8_C(163),
                        UINT8_C(199), UINT8_C( 13), UINT8_C(157), UINT8_C(178),
                        UINT8_C(255), UINT8_C(174), UINT8_C(203), UINT8_C( 42) ),
      simde_x_vloadq_u8(UINT8_C(223), UINT8_C(107), UINT8_C(115), UINT8_C(  5),
                        UINT8_C(230), UINT8_C(157), UINT8_C( 37), UINT8_C( 60),
                        UINT8_C(169), UINT8_C(159), UINT8_C(132), UINT8_C(  0),
                        UINT8_C(112), UINT8_C(190), UINT8_C(249), UINT8_C(226) ),
      simde_x_vloadq_u8(UINT8_C(212), UINT8_C(235), UINT8_C(204), UINT8_C(254),
                        UINT8_C( 10), UINT8_C( 88), UINT8_C( 45), UINT8_C(223),
                        UINT8_C(112), UINT8_C(172), UINT8_C( 33), UINT8_C(178),
                        UINT8_C(111), UINT8_C(108), UINT8_C(196), UINT8_C( 12) ) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_uint8x16_t r = simde_vaddq_u8(test_vec[i].a, test_vec[i].b);
    simde_neon_assert_uint8x16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_vaddq_u16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_uint16x8_t a;
    simde_uint16x8_t b;
    simde_uint16x8_t r;
  } test_vec[8] = {
    { simde_x_vloadq_u16(UINT16_C(34492), UINT16_C(23145), UINT16_C(44147), UINT16_C(55143),
                         UINT16_C(43976), UINT16_C(41283), UINT16_C(26180), UINT16_C(59808)),
      simde_x_vloadq_u16(UINT16_C(53463), UINT16_C(60095), UINT16_C( 4203), UINT16_C(58921),
                         UINT16_C( 8541), UINT16_C(14559), UINT16_C(14774), UINT16_C( 9845)),
      simde_x_vloadq_u16(UINT16_C(22419), UINT16_C(17704), UINT16_C(48350), UINT16_C(48528),
                         UINT16_C(52517), UINT16_C(55842), UINT16_C(40954), UINT16_C( 4117)) },
    { simde_x_vloadq_u16(UINT16_C(43206), UINT16_C(11634), UINT16_C(46200), UINT16_C( 5166),
                         UINT16_C(16509), UINT16_C( 6436), UINT16_C(43997), UINT16_C(30872)),
      simde_x_vloadq_u16(UINT16_C(48165), UINT16_C(59035), UINT16_C(25855), UINT16_C(54787),
                         UINT16_C( 4475), UINT16_C(19383), UINT16_C(26218), UINT16_C(34373)),
      simde_x_vloadq_u16(UINT16_C(25835), UINT16_C( 5133), UINT16_C( 6519), UINT16_C(59953),
                         UINT16_C(20984), UINT16_C(25819), UINT16_C( 4679), UINT16_C(65245)) },
    { simde_x_vloadq_u16(UINT16_C(19403), UINT16_C( 1490), UINT16_C(24559), UINT16_C(61691),
                         UINT16_C(40193), UINT16_C(54109), UINT16_C(28140), UINT16_C(21835)),
      simde_x_vloadq_u16(UINT16_C(62067), UINT16_C(59376), UINT16_C(42984), UINT16_C(20292),
                         UINT16_C(10591), UINT16_C(37105), UINT16_C(32789), UINT16_C( 4185)),
      simde_x_vloadq_u16(UINT16_C(15934), UINT16_C(60866), UINT16_C( 2007), UINT16_C(16447),
                         UINT16_C(50784), UINT16_C(25678), UINT16_C(60929), UINT16_C(26020)) },
    { simde_x_vloadq_u16(UINT16_C(48048), UINT16_C(39787), UINT16_C(36218), UINT16_C(62079),
                         UINT16_C(46395), UINT16_C(64658), UINT16_C(24492), UINT16_C(12376)),
      simde_x_vloadq_u16(UINT16_C(21609), UINT16_C(37283), UINT16_C(29573), UINT16_C(11233),
                         UINT16_C(28884), UINT16_C( 5034), UINT16_C(41349), UINT16_C(65003)),
      simde_x_vloadq_u16(UINT16_C( 4121), UINT16_C(11534), UINT16_C(  255), UINT16_C( 7776),
                         UINT16_C( 9743), UINT16_C( 4156), UINT16_C(  305), UINT16_C(11843)) },
    { simde_x_vloadq_u16(UINT16_C(27374), UINT16_C(33921), UINT16_C(38919), UINT16_C(60071),
                         UINT16_C(34206), UINT16_C(46148), UINT16_C( 4477), UINT16_C(47822)),
      simde_x_vloadq_u16(UINT16_C(56481), UINT16_C(63893), UINT16_C(18090), UINT16_C(13895),
                         UINT16_C( 1000), UINT16_C(16712), UINT16_C(28786), UINT16_C( 3913)),
      simde_x_vloadq_u16(UINT16_C(18319), UINT16_C(32278), UINT16_C(57009), UINT16_C( 8430),
                         UINT16_C(35206), UINT16_C(62860), UINT16_C(33263), UINT16_C(51735)) },
    { simde_x_vloadq_u16(UINT16_C(58012), UINT16_C(11617), UINT16_C(34311), UINT16_C(27371),
                         UINT16_C(38646), UINT16_C(24455), UINT16_C(59008), UINT16_C(52140)),
      simde_x_vloadq_u16(UINT16_C(58878), UINT16_C(61930), UINT16_C(16108), UINT16_C(45459),
                         UINT16_C(21425), UINT16_C(60658), UINT16_C(43899), UINT16_C(25142)),
      simde_x_vloadq_u16(UINT16_C(51354), UINT16_C( 8011), UINT16_C(50419), UINT16_C( 7294),
                         UINT16_C(60071), UINT16_C(19577), UINT16_C(37371), UINT16_C(11746)) },
    { simde_x_vloadq_u16(UINT16_C( 3611), UINT16_C(25272), UINT16_C(10332), UINT16_C( 1806),
                         UINT16_C(51376), UINT16_C(13438), UINT16_C(22041), UINT16_C(19855)),
      simde_x_vloadq_u16(UINT16_C(49090), UINT16_C(36808), UINT16_C( 4506), UINT16_C(46803),
                         UINT16_C(24674), UINT16_C(24138), UINT16_C(59009), UINT16_C(11338)),
      simde_x_vloadq_u16(UINT16_C(52701), UINT16_C(62080), UINT16_C(14838), UINT16_C(48609),
                         UINT16_C(10514), UINT16_C(37576), UINT16_C(15514), UINT16_C(31193)) },
    { simde_x_vloadq_u16(UINT16_C(33013), UINT16_C(63833), UINT16_C(47908), UINT16_C(41736),
                         UINT16_C( 3527), UINT16_C(45725), UINT16_C(44799), UINT16_C(10955)),
      simde_x_vloadq_u16(UINT16_C(27615), UINT16_C( 1395), UINT16_C(40422), UINT16_C(15397),
                         UINT16_C(40873), UINT16_C(  132), UINT16_C(48752), UINT16_C(58105)),
      simde_x_vloadq_u16(UINT16_C(60628), UINT16_C(65228), UINT16_C(22794), UINT16_C(57133),
                         UINT16_C(44400), UINT16_C(45857), UINT16_C(28015), UINT16_C( 3524)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_uint16x8_t r = simde_vaddq_u16(test_vec[i].a, test_vec[i].b);
    simde_neon_assert_uint16x8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_vaddq_u32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_uint32x4_t a;
    simde_uint32x4_t b;
    simde_uint32x4_t r;
  } test_vec[8] = {
    { simde_x_vloadq_u32(UINT32_C(1516865212), UINT32_C(3613895795),
                         UINT32_C(2705566664), UINT32_C(3919603268)),
      simde_x_vloadq_u32(UINT32_C(3938439383), UINT32_C(3861450859),
                         UINT32_C( 954147165), UINT32_C( 645216694)),
      simde_x_vloadq_u32(UINT32_C(1160337299), UINT32_C(3180379358),
                         UINT32_C(3659713829), UINT32_C( 269852666)) },
    { simde_x_vloadq_u32(UINT32_C( 762489030), UINT32_C( 338605176),
                         UINT32_C( 421806205), UINT32_C(2023271389)),
      simde_x_vloadq_u32(UINT32_C(3868965925), UINT32_C(3590546687),
                         UINT32_C(1270288763), UINT32_C(2252695146)),
      simde_x_vloadq_u32(UINT32_C( 336487659), UINT32_C(3929151863),
                         UINT32_C(1692094968), UINT32_C(4275966535)) },
    { simde_x_vloadq_u32(UINT32_C(  97668043), UINT32_C(4043005935),
                         UINT32_C(3546127617), UINT32_C(1431006700)),
      simde_x_vloadq_u32(UINT32_C(3891327603), UINT32_C(1329899496),
                         UINT32_C(2431723871), UINT32_C( 274300949)),
      simde_x_vloadq_u32(UINT32_C(3988995646), UINT32_C(1077938135),
                         UINT32_C(1682884192), UINT32_C(1705307649)) },
    { simde_x_vloadq_u32(UINT32_C(2607528880), UINT32_C(4068445562),
                         UINT32_C(4237473083), UINT32_C( 811098028)),
      simde_x_vloadq_u32(UINT32_C(2443400297), UINT32_C( 736195461),
                         UINT32_C( 329937108), UINT32_C(4260077957)),
      simde_x_vloadq_u32(UINT32_C( 755961881), UINT32_C( 509673727),
                         UINT32_C( 272442895), UINT32_C( 776208689)) },
    { simde_x_vloadq_u32(UINT32_C(2223074030), UINT32_C(3936851975),
                         UINT32_C(3024389534), UINT32_C(3134067069)),
      simde_x_vloadq_u32(UINT32_C(4187348129), UINT32_C( 910640810),
                         UINT32_C(1095238632), UINT32_C( 256471154)),
      simde_x_vloadq_u32(UINT32_C(2115454863), UINT32_C( 552525489),
                         UINT32_C(4119628166), UINT32_C(3390538223)) },
    { simde_x_vloadq_u32(UINT32_C( 761389724), UINT32_C(1793820167),
                         UINT32_C(1602721526), UINT32_C(3417106048)),
      simde_x_vloadq_u32(UINT32_C(4058703358), UINT32_C(2979217132),
                         UINT32_C(3975304113), UINT32_C(1647750011)),
      simde_x_vloadq_u32(UINT32_C( 525125786), UINT32_C( 478070003),
                         UINT32_C(1283058343), UINT32_C( 769888763)) },
    { simde_x_vloadq_u32(UINT32_C(1656229403), UINT32_C( 118368348),
                         UINT32_C( 880724144), UINT32_C(1301239321)),
      simde_x_vloadq_u32(UINT32_C(2412298178), UINT32_C(3067285914),
                         UINT32_C(1581932642), UINT32_C( 743106177)),
      simde_x_vloadq_u32(UINT32_C(4068527581), UINT32_C(3185654262),
                         UINT32_C(2462656786), UINT32_C(2044345498)) },
    { simde_x_vloadq_u32(UINT32_C(4183392501), UINT32_C(2735258404),
                         UINT32_C(2996637127), UINT32_C( 717991679)),
      simde_x_vloadq_u32(UINT32_C(  91450335), UINT32_C(1009098214),
                         UINT32_C(   8691625), UINT32_C(3808018032)),
      simde_x_vloadq_u32(UINT32_C(4274842836), UINT32_C(3744356618),
                         UINT32_C(3005328752), UINT32_C( 231042415)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_uint32x4_t r = simde_vaddq_u32(test_vec[i].a, test_vec[i].b);
    simde_neon_assert_uint32x4(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_vaddq_u64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_uint64x2_t a;
    simde_uint64x2_t b;
    simde_uint64x2_t r;
  } test_vec[8] = {
    { simde_x_vloadq_u64(UINT64_C(15521564252193785532), UINT64_C(16834567852060289992)),
      simde_x_vloadq_u64(UINT64_C(16584805158454546647), UINT64_C(2771184600517386589)),
      simde_x_vloadq_u64(UINT64_C(13659625336938780563), UINT64_C(1159008378868124965)) },
    { simde_x_vloadq_u64(UINT64_C(1454298157938813126), UINT64_C(8689884447109300349)),
      simde_x_vloadq_u64(UINT64_C(15421280599295114277), UINT64_C(9675251981198233979)),
      simde_x_vloadq_u64(UINT64_C(16875578757233927403), UINT64_C(18365136428307534328)) },
    { simde_x_vloadq_u64(UINT64_C(17364578268456569803), UINT64_C(6146126980403010817)),
      simde_x_vloadq_u64(UINT64_C(5711874846178210419), UINT64_C(1178113607648487775)),
      simde_x_vloadq_u64(UINT64_C(4629709040925228606), UINT64_C(7324240588051498592)) },
    { simde_x_vloadq_u64(UINT64_C(17473840636953869232), UINT64_C(3483639508347565371)),
      simde_x_vloadq_u64(UINT64_C(3161935430902043753), UINT64_C(18296895504055431380)),
      simde_x_vloadq_u64(UINT64_C(2189031994146361369), UINT64_C(3333790938693445135)) },
    { simde_x_vloadq_u64(UINT64_C(16908650484041083630), UINT64_C(13460715567849964958)),
      simde_x_vloadq_u64(UINT64_C(3911172501540297889), UINT64_C(1101535219892618216)),
      simde_x_vloadq_u64(UINT64_C(2373078911871829903), UINT64_C(14562250787742583174)) },
    { simde_x_vloadq_u64(UINT64_C(7704398952931648156), UINT64_C(14676358724726527734)),
      simde_x_vloadq_u64(UINT64_C(12795640153681618430), UINT64_C(7077032413203944369)),
      simde_x_vloadq_u64(UINT64_C(2053295032903714970), UINT64_C(3306647064220920487)) },
    { simde_x_vloadq_u64(UINT64_C( 508388185197776411), UINT64_C(5588780328844970160)),
      simde_x_vloadq_u64(UINT64_C(13173892690523766722), UINT64_C(3191616729252520034)),
      simde_x_vloadq_u64(UINT64_C(13682280875721543133), UINT64_C(8780397058097490194)) },
    { simde_x_vloadq_u64(UINT64_C(11747845395472548085), UINT64_C(3083750783101767111)),
      simde_x_vloadq_u64(UINT64_C(4334043827673459679), UINT64_C(16355312910026973097)),
      simde_x_vloadq_u64(UINT64_C(16081889223146007764), UINT64_C( 992319619419188592)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_uint64x2_t r = simde_vaddq_u64(test_vec[i].a, test_vec[i].b);
    simde_neon_assert_uint64x2(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_vaddq_f32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_float32x4_t a;
    simde_float32x4_t b;
    simde_float32x4_t r;
  } test_vec[8] = {
    { simde_x_vloadq_f32(SIMDE_FLOAT32_C( -919.97), SIMDE_FLOAT32_C(  785.15),
                         SIMDE_FLOAT32_C( -611.53), SIMDE_FLOAT32_C( -602.10)),
      simde_x_vloadq_f32(SIMDE_FLOAT32_C( -924.97), SIMDE_FLOAT32_C( -727.27),
                         SIMDE_FLOAT32_C( -752.32), SIMDE_FLOAT32_C( -767.11)),
      simde_x_vloadq_f32(SIMDE_FLOAT32_C(-1844.94), SIMDE_FLOAT32_C(   57.88),
                         SIMDE_FLOAT32_C(-1363.85), SIMDE_FLOAT32_C(-1369.21)) },
    { simde_x_vloadq_f32(SIMDE_FLOAT32_C(  -14.93), SIMDE_FLOAT32_C(  608.03),
                         SIMDE_FLOAT32_C( -789.79), SIMDE_FLOAT32_C(   68.13)),
      simde_x_vloadq_f32(SIMDE_FLOAT32_C( -858.58), SIMDE_FLOAT32_C( -414.28),
                         SIMDE_FLOAT32_C(  897.52), SIMDE_FLOAT32_C(  872.30)),
      simde_x_vloadq_f32(SIMDE_FLOAT32_C( -873.51), SIMDE_FLOAT32_C(  193.75),
                         SIMDE_FLOAT32_C(  107.73), SIMDE_FLOAT32_C(  940.43)) },
    { simde_x_vloadq_f32(SIMDE_FLOAT32_C( -263.95), SIMDE_FLOAT32_C(  795.10),
                         SIMDE_FLOAT32_C(  545.87), SIMDE_FLOAT32_C(  506.17)),
      simde_x_vloadq_f32(SIMDE_FLOAT32_C(  946.10), SIMDE_FLOAT32_C(  516.44),
                         SIMDE_FLOAT32_C( -681.35), SIMDE_FLOAT32_C( -180.00)),
      simde_x_vloadq_f32(SIMDE_FLOAT32_C(  682.15), SIMDE_FLOAT32_C( 1311.54),
                         SIMDE_FLOAT32_C( -135.48), SIMDE_FLOAT32_C(  326.17)) },
    { simde_x_vloadq_f32(SIMDE_FLOAT32_C(  547.94), SIMDE_FLOAT32_C( -151.93),
                         SIMDE_FLOAT32_C(  865.78), SIMDE_FLOAT32_C( -390.75)),
      simde_x_vloadq_f32(SIMDE_FLOAT32_C( -476.37), SIMDE_FLOAT32_C(  990.69),
                         SIMDE_FLOAT32_C(  890.86), SIMDE_FLOAT32_C(  555.02)),
      simde_x_vloadq_f32(SIMDE_FLOAT32_C(   71.57), SIMDE_FLOAT32_C(  838.76),
                         SIMDE_FLOAT32_C( 1756.64), SIMDE_FLOAT32_C(  164.27)) },
    { simde_x_vloadq_f32(SIMDE_FLOAT32_C( -126.52), SIMDE_FLOAT32_C(  983.51),
                         SIMDE_FLOAT32_C(  833.14), SIMDE_FLOAT32_C(  459.96)),
      simde_x_vloadq_f32(SIMDE_FLOAT32_C(  322.14), SIMDE_FLOAT32_C(  954.88),
                         SIMDE_FLOAT32_C( -247.30), SIMDE_FLOAT32_C(  346.82)),
      simde_x_vloadq_f32(SIMDE_FLOAT32_C(  195.62), SIMDE_FLOAT32_C( 1938.39),
                         SIMDE_FLOAT32_C(  585.84), SIMDE_FLOAT32_C(  806.78)) },
    { simde_x_vloadq_f32(SIMDE_FLOAT32_C( -553.63), SIMDE_FLOAT32_C( -968.44),
                         SIMDE_FLOAT32_C( -255.74), SIMDE_FLOAT32_C( -226.64)),
      simde_x_vloadq_f32(SIMDE_FLOAT32_C(  118.57), SIMDE_FLOAT32_C(  901.85),
                         SIMDE_FLOAT32_C(  842.68), SIMDE_FLOAT32_C(   16.95)),
      simde_x_vloadq_f32(SIMDE_FLOAT32_C( -435.06), SIMDE_FLOAT32_C(  -66.59),
                         SIMDE_FLOAT32_C(  586.94), SIMDE_FLOAT32_C( -209.69)) },
    { simde_x_vloadq_f32(SIMDE_FLOAT32_C( -941.60), SIMDE_FLOAT32_C(  301.41),
                         SIMDE_FLOAT32_C( -661.60), SIMDE_FLOAT32_C(  559.21)),
      simde_x_vloadq_f32(SIMDE_FLOAT32_C(  991.39), SIMDE_FLOAT32_C(  876.21),
                         SIMDE_FLOAT32_C( -643.72), SIMDE_FLOAT32_C(  222.34)),
      simde_x_vloadq_f32(SIMDE_FLOAT32_C(   49.79), SIMDE_FLOAT32_C( 1177.62),
                         SIMDE_FLOAT32_C(-1305.32), SIMDE_FLOAT32_C(  781.55)) },
    { simde_x_vloadq_f32(SIMDE_FLOAT32_C( -511.28), SIMDE_FLOAT32_C(  578.71),
                         SIMDE_FLOAT32_C( -174.25), SIMDE_FLOAT32_C( -799.18)),
      simde_x_vloadq_f32(SIMDE_FLOAT32_C(  576.28), SIMDE_FLOAT32_C(  681.28),
                         SIMDE_FLOAT32_C( -327.62), SIMDE_FLOAT32_C(   30.52)),
      simde_x_vloadq_f32(SIMDE_FLOAT32_C(   65.00), SIMDE_FLOAT32_C( 1259.99),
                         SIMDE_FLOAT32_C( -501.87), SIMDE_FLOAT32_C( -768.66)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_float32x4_t r = simde_vaddq_f32(test_vec[i].a, test_vec[i].b);
    simde_neon_assert_float32x4_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_vaddq_f64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_float64x2_t a;
    simde_float64x2_t b;
    simde_float64x2_t r;
  } test_vec[8] = {
    { simde_x_vloadq_f64(SIMDE_FLOAT64_C( -919.97), SIMDE_FLOAT64_C(  785.15)),
      simde_x_vloadq_f64(SIMDE_FLOAT64_C( -611.53), SIMDE_FLOAT64_C( -602.10)),
      simde_x_vloadq_f64(SIMDE_FLOAT64_C(-1531.50), SIMDE_FLOAT64_C(  183.05)) },
    { simde_x_vloadq_f64(SIMDE_FLOAT64_C( -924.97), SIMDE_FLOAT64_C( -727.27)),
      simde_x_vloadq_f64(SIMDE_FLOAT64_C( -752.32), SIMDE_FLOAT64_C( -767.11)),
      simde_x_vloadq_f64(SIMDE_FLOAT64_C(-1677.29), SIMDE_FLOAT64_C(-1494.38)) },
    { simde_x_vloadq_f64(SIMDE_FLOAT64_C(  -14.93), SIMDE_FLOAT64_C(  608.03)),
      simde_x_vloadq_f64(SIMDE_FLOAT64_C( -789.79), SIMDE_FLOAT64_C(   68.13)),
      simde_x_vloadq_f64(SIMDE_FLOAT64_C( -804.72), SIMDE_FLOAT64_C(  676.16)) },
    { simde_x_vloadq_f64(SIMDE_FLOAT64_C( -858.58), SIMDE_FLOAT64_C( -414.28)),
      simde_x_vloadq_f64(SIMDE_FLOAT64_C(  897.52), SIMDE_FLOAT64_C(  872.30)),
      simde_x_vloadq_f64(SIMDE_FLOAT64_C(   38.94), SIMDE_FLOAT64_C(  458.02)) },
    { simde_x_vloadq_f64(SIMDE_FLOAT64_C( -263.95), SIMDE_FLOAT64_C(  795.10)),
      simde_x_vloadq_f64(SIMDE_FLOAT64_C(  545.87), SIMDE_FLOAT64_C(  506.17)),
      simde_x_vloadq_f64(SIMDE_FLOAT64_C(  281.92), SIMDE_FLOAT64_C( 1301.27)) },
    { simde_x_vloadq_f64(SIMDE_FLOAT64_C(  946.10), SIMDE_FLOAT64_C(  516.44)),
      simde_x_vloadq_f64(SIMDE_FLOAT64_C( -681.35), SIMDE_FLOAT64_C( -180.00)),
      simde_x_vloadq_f64(SIMDE_FLOAT64_C(  264.75), SIMDE_FLOAT64_C(  336.44)) },
    { simde_x_vloadq_f64(SIMDE_FLOAT64_C(  547.94), SIMDE_FLOAT64_C( -151.93)),
      simde_x_vloadq_f64(SIMDE_FLOAT64_C(  865.78), SIMDE_FLOAT64_C( -390.75)),
      simde_x_vloadq_f64(SIMDE_FLOAT64_C( 1413.72), SIMDE_FLOAT64_C( -542.68)) },
    { simde_x_vloadq_f64(SIMDE_FLOAT64_C( -476.37), SIMDE_FLOAT64_C(  990.69)),
      simde_x_vloadq_f64(SIMDE_FLOAT64_C(  890.86), SIMDE_FLOAT64_C(  555.02)),
      simde_x_vloadq_f64(SIMDE_FLOAT64_C(  414.49), SIMDE_FLOAT64_C( 1545.71)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_float64x2_t r = simde_vaddq_f64(test_vec[i].a, test_vec[i].b);
    simde_neon_assert_float64x2_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitTest vadd_tests[] = {
  TEST_FUNC2(vadd, s8),
  TEST_FUNC2(vadd, s16),
  TEST_FUNC2(vadd, s32),
  TEST_FUNC2(vadd, s64),
  TEST_FUNC2(vadd, u8),
  TEST_FUNC2(vadd, u16),
  TEST_FUNC2(vadd, u32),
  TEST_FUNC2(vadd, u64),
  TEST_FUNC2(vadd, f32),
  TEST_FUNC2(vadd, f64),
  TEST_FUNC3(vaddq, q, s8),
  TEST_FUNC3(vaddq, q, s16),
  TEST_FUNC3(vaddq, q, s32),
  TEST_FUNC3(vaddq, q, s64),
  TEST_FUNC3(vaddq, q, u8),
  TEST_FUNC3(vaddq, q, u16),
  TEST_FUNC3(vaddq, q, u32),
  TEST_FUNC3(vaddq, q, u64),
  TEST_FUNC3(vaddq, q, f32),
  TEST_FUNC3(vaddq, q, f64),

  { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

MunitSuite NEON_TEST_SUITE(vadd) = {
  (char*) "/vadd",
  vadd_tests,
  NULL,
  1,
  MUNIT_SUITE_OPTION_NONE
};
