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

#define SIMDE_TESTS_CURRENT_NEON_OP mul
#include <test/arm/neon/test-neon-internal.h>
#include <simde/arm/neon.h>

#if defined(SIMDE_NEON_NATIVE) || defined(SIMDE_NO_NATIVE) || defined(SIMDE_ALWAYS_BUILD_NATIVE_TESTS)

static MunitResult
test_simde_vmul_s8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_int8x8_t a;
    simde_int8x8_t b;
    simde_int8x8_t r;
  } test_vec[8] = {
    { simde_x_vload_s8(INT8_C( 102), INT8_C( -11), INT8_C( -66), INT8_C(-119),
                       INT8_C(  43), INT8_C( 110), INT8_C(  64), INT8_C( -56)),
      simde_x_vload_s8(INT8_C(  21), INT8_C(-117), INT8_C( 108), INT8_C(-116),
                       INT8_C( -14), INT8_C(  64), INT8_C(  89), INT8_C(  83)),
      simde_x_vload_s8(INT8_C(  94), INT8_C(   7), INT8_C(  40), INT8_C( -20),
                       INT8_C( -90), INT8_C(-128), INT8_C(  64), INT8_C( -40)) },
    { simde_x_vload_s8(INT8_C( 117), INT8_C( -87), INT8_C( -31), INT8_C( 110),
                       INT8_C(  28), INT8_C(  19), INT8_C(  18), INT8_C(  64)),
      simde_x_vload_s8(INT8_C( 117), INT8_C(-106), INT8_C(  24), INT8_C( -75),
                       INT8_C(  22), INT8_C( -42), INT8_C( -80), INT8_C(  85)),
      simde_x_vload_s8(INT8_C( 121), INT8_C(   6), INT8_C(  24), INT8_C( -58),
                       INT8_C( 104), INT8_C( -30), INT8_C(  96), INT8_C(  64)) },
    { simde_x_vload_s8(INT8_C( -67), INT8_C(  22), INT8_C(  58), INT8_C(-112),
                       INT8_C( 113), INT8_C(  58), INT8_C(-121), INT8_C(-109)),
      simde_x_vload_s8(INT8_C( -53), INT8_C(-109), INT8_C(   9), INT8_C(  -8),
                       INT8_C(  45), INT8_C(  17), INT8_C( -71), INT8_C( -33)),
      simde_x_vload_s8(INT8_C( -33), INT8_C( -94), INT8_C(  10), INT8_C(-128),
                       INT8_C( -35), INT8_C( -38), INT8_C(-113), INT8_C(  13)) },
    { simde_x_vload_s8(INT8_C( -52), INT8_C(-112), INT8_C( -62), INT8_C(  74),
                       INT8_C(   1), INT8_C( -87), INT8_C( -43), INT8_C(  20)),
      simde_x_vload_s8(INT8_C(  79), INT8_C( -70), INT8_C( 124), INT8_C(-110),
                       INT8_C(-103), INT8_C(  92), INT8_C(  62), INT8_C( -96)),
      simde_x_vload_s8(INT8_C( -12), INT8_C( -96), INT8_C(  -8), INT8_C(  52),
                       INT8_C(-103), INT8_C( -68), INT8_C(-106), INT8_C(-128)) },
    { simde_x_vload_s8(INT8_C( 106), INT8_C(  23), INT8_C( -98), INT8_C(  21),
                       INT8_C(-114), INT8_C(   8), INT8_C( -78), INT8_C( -32)),
      simde_x_vload_s8(INT8_C(-100), INT8_C(  22), INT8_C(-126), INT8_C( -35),
                       INT8_C(  -1), INT8_C( -46), INT8_C( -93), INT8_C( -32)),
      simde_x_vload_s8(INT8_C(-104), INT8_C(  -6), INT8_C(  60), INT8_C(  33),
                       INT8_C( 114), INT8_C(-112), INT8_C(  86), INT8_C(   0)) },
    { simde_x_vload_s8(INT8_C( 118), INT8_C( -95), INT8_C( -87), INT8_C(  25),
                       INT8_C( -22), INT8_C(  92), INT8_C(  48), INT8_C(  41)),
      simde_x_vload_s8(INT8_C(  -2), INT8_C(  61), INT8_C(-127), INT8_C( 120),
                       INT8_C(  32), INT8_C(-125), INT8_C( -64), INT8_C( 119)),
      simde_x_vload_s8(INT8_C(  20), INT8_C(  93), INT8_C(  41), INT8_C( -72),
                       INT8_C(  64), INT8_C(  20), INT8_C(   0), INT8_C(  15)) },
    { simde_x_vload_s8(INT8_C( -71), INT8_C( 100), INT8_C(   2), INT8_C( -47),
                       INT8_C(-105), INT8_C(  83), INT8_C(  36), INT8_C( -48)),
      simde_x_vload_s8(INT8_C(  37), INT8_C( -86), INT8_C( -62), INT8_C(-128),
                       INT8_C( 111), INT8_C(  42), INT8_C( -35), INT8_C(  99)),
      simde_x_vload_s8(INT8_C( -67), INT8_C( 104), INT8_C(-124), INT8_C(-128),
                       INT8_C( 121), INT8_C( -98), INT8_C(  20), INT8_C( 112)) },
    { simde_x_vload_s8(INT8_C(  31), INT8_C(-109), INT8_C(  79), INT8_C(  57),
                       INT8_C( -62), INT8_C(  16), INT8_C(   2), INT8_C( 111)),
      simde_x_vload_s8(INT8_C( -78), INT8_C( -76), INT8_C( -69), INT8_C( -53),
                       INT8_C(   0), INT8_C( -37), INT8_C(  19), INT8_C(  18)),
      simde_x_vload_s8(INT8_C(-114), INT8_C(  92), INT8_C( -75), INT8_C(  51),
                       INT8_C(   0), INT8_C( -80), INT8_C(  38), INT8_C( -50)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_int8x8_t r = simde_vmul_s8(test_vec[i].a, test_vec[i].b);
    simde_neon_assert_int8x8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_vmul_s16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_int16x4_t a;
    simde_int16x4_t b;
    simde_int16x4_t r;
  } test_vec[8] = {
    { simde_x_vload_s16(INT16_C(-31826), INT16_C( -7391), INT16_C(  -462), INT16_C(-10931)),
      simde_x_vload_s16(INT16_C(-29948), INT16_C(-20769), INT16_C( 17251), INT16_C( 13600)),
      simde_x_vload_s16(INT16_C(-30536), INT16_C( 18367), INT16_C( 25430), INT16_C(-25952)) },
    { simde_x_vload_s16(INT16_C(-12602), INT16_C( 26994), INT16_C( 15946), INT16_C(-17611)),
      simde_x_vload_s16(INT16_C(-27918), INT16_C( 31417), INT16_C(-31752), INT16_C( 12675)),
      simde_x_vload_s16(INT16_C( 25388), INT16_C(-30878), INT16_C( 13744), INT16_C( -3809)) },
    { simde_x_vload_s16(INT16_C( 25025), INT16_C( 10589), INT16_C(  6804), INT16_C(  7776)),
      simde_x_vload_s16(INT16_C(-25648), INT16_C(-28276), INT16_C(  -793), INT16_C( 31106)),
      simde_x_vload_s16(INT16_C( 18384), INT16_C( 19420), INT16_C(-21620), INT16_C(-13120)) },
    { simde_x_vload_s16(INT16_C(   196), INT16_C(  1304), INT16_C(-31290), INT16_C(-32121)),
      simde_x_vload_s16(INT16_C( 21652), INT16_C( -9418), INT16_C( 29473), INT16_C( 15166)),
      simde_x_vload_s16(INT16_C(-16048), INT16_C(-25840), INT16_C( 12422), INT16_C(-17998)) },
    { simde_x_vload_s16(INT16_C(-29855), INT16_C(  -248), INT16_C(-21274), INT16_C(-28669)),
      simde_x_vload_s16(INT16_C(-15098), INT16_C( -8131), INT16_C( 30935), INT16_C( -2866)),
      simde_x_vload_s16(INT16_C( -5818), INT16_C(-15128), INT16_C(  1322), INT16_C(-16790)) },
    { simde_x_vload_s16(INT16_C(-12706), INT16_C(  1479), INT16_C(-16812), INT16_C(  7789)),
      simde_x_vload_s16(INT16_C( 25541), INT16_C( 26457), INT16_C( 25772), INT16_C( 31684)),
      simde_x_vload_s16(INT16_C( 10326), INT16_C(  4911), INT16_C(-20368), INT16_C(-21900)) },
    { simde_x_vload_s16(INT16_C(  6250), INT16_C(-24625), INT16_C(  1194), INT16_C( -6051)),
      simde_x_vload_s16(INT16_C( 29420), INT16_C( 25728), INT16_C( 23202), INT16_C( 22987)),
      simde_x_vload_s16(INT16_C(-19016), INT16_C(-15488), INT16_C(-18540), INT16_C(-26945)) },
    { simde_x_vload_s16(INT16_C(-30139), INT16_C( 13263), INT16_C( 10350), INT16_C( 31500)),
      simde_x_vload_s16(INT16_C( -4536), INT16_C( 10209), INT16_C(-32488), INT16_C(  9174)),
      simde_x_vload_s16(INT16_C(  2408), INT16_C(  4591), INT16_C( 14416), INT16_C(-32760)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_int16x4_t r = simde_vmul_s16(test_vec[i].a, test_vec[i].b);
    simde_neon_assert_int16x4(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_vmul_s32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_int32x2_t a;
    simde_int32x2_t b;
    simde_int32x2_t r;
  } test_vec[8] = {
    { simde_x_vload_s32(INT32_C(-1462480123), INT32_C(-1568774293)),
      simde_x_vload_s32(INT32_C(  855416238), INT32_C(  670298924)),
      simde_x_vload_s32(INT32_C(-1440317850), INT32_C( 1635080036)) },
    { simde_x_vload_s32(INT32_C( 1950510690), INT32_C(-1312310854)),
      simde_x_vload_s32(INT32_C( 1186234862), INT32_C(-1064675530)),
      simde_x_vload_s32(INT32_C( -129367780), INT32_C(  -24943812)) },
    { simde_x_vload_s32(INT32_C(-1982046851), INT32_C(-1152099595)),
      simde_x_vload_s32(INT32_C(-1466083134), INT32_C( -479470034)),
      simde_x_vload_s32(INT32_C(-1765093190), INT32_C(  326094342)) },
    { simde_x_vload_s32(INT32_C(-1099740866), INT32_C(-2031221022)),
      simde_x_vload_s32(INT32_C( -272182105), INT32_C( 1934242918)),
      simde_x_vload_s32(INT32_C( 1037049714), INT32_C(-1617910260)) },
    { simde_x_vload_s32(INT32_C(  846494307), INT32_C(  992291677)),
      simde_x_vload_s32(INT32_C(-1062975990), INT32_C( -728231586)),
      simde_x_vload_s32(INT32_C( 2037373406), INT32_C( -222357210)) },
    { simde_x_vload_s32(INT32_C( 1233604686), INT32_C(  913582180)),
      simde_x_vload_s32(INT32_C(-2062706547), INT32_C( 1757955985)),
      simde_x_vload_s32(INT32_C( 1898679030), INT32_C( 1025416356)) },
    { simde_x_vload_s32(INT32_C(  504229488), INT32_C(-2135950055)),
      simde_x_vload_s32(INT32_C(   57241002), INT32_C(-2085005546)),
      simde_x_vload_s32(INT32_C(   -4848032), INT32_C(-1875624154)) },
    { simde_x_vload_s32(INT32_C(-2063505862), INT32_C( 1539186741)),
      simde_x_vload_s32(INT32_C( -513744611), INT32_C(  522045179)),
      simde_x_vload_s32(INT32_C(-1681813870), INT32_C(  290689527)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_int32x2_t r = simde_vmul_s32(test_vec[i].a, test_vec[i].b);
    simde_neon_assert_int32x2(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_vmul_u8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_uint8x8_t a;
    simde_uint8x8_t b;
    simde_uint8x8_t r;
  } test_vec[8] = {
    { simde_x_vload_u8(UINT8_C(122), UINT8_C(173), UINT8_C(147), UINT8_C( 28),
                       UINT8_C(219), UINT8_C( 56), UINT8_C(136), UINT8_C(125)),
      simde_x_vload_u8(UINT8_C( 44), UINT8_C(186), UINT8_C(141), UINT8_C(226),
                       UINT8_C( 55), UINT8_C(190), UINT8_C(143), UINT8_C(187)),
      simde_x_vload_u8(UINT8_C(248), UINT8_C(178), UINT8_C(247), UINT8_C(184),
                       UINT8_C( 13), UINT8_C(144), UINT8_C(248), UINT8_C( 79)) },
    { simde_x_vload_u8(UINT8_C(102), UINT8_C(120), UINT8_C(  9), UINT8_C( 82),
                       UINT8_C( 26), UINT8_C(142), UINT8_C(247), UINT8_C( 47)),
      simde_x_vload_u8(UINT8_C(150), UINT8_C(107), UINT8_C(122), UINT8_C(192),
                       UINT8_C(153), UINT8_C( 74), UINT8_C(207), UINT8_C(  1)),
      simde_x_vload_u8(UINT8_C(196), UINT8_C( 40), UINT8_C( 74), UINT8_C(128),
                       UINT8_C(138), UINT8_C( 12), UINT8_C(185), UINT8_C( 47)) },
    { simde_x_vload_u8(UINT8_C(213), UINT8_C(100), UINT8_C( 93), UINT8_C(149),
                       UINT8_C( 25), UINT8_C( 65), UINT8_C(188), UINT8_C(157)),
      simde_x_vload_u8(UINT8_C( 32), UINT8_C(165), UINT8_C( 78), UINT8_C( 59),
                       UINT8_C(236), UINT8_C(154), UINT8_C( 33), UINT8_C(249)),
      simde_x_vload_u8(UINT8_C(160), UINT8_C(116), UINT8_C( 86), UINT8_C( 87),
                       UINT8_C( 12), UINT8_C( 26), UINT8_C( 60), UINT8_C(181)) },
    { simde_x_vload_u8(UINT8_C( 39), UINT8_C(171), UINT8_C(211), UINT8_C( 66),
                       UINT8_C( 72), UINT8_C(124), UINT8_C( 28), UINT8_C( 70)),
      simde_x_vload_u8(UINT8_C(153), UINT8_C(  6), UINT8_C( 71), UINT8_C(240),
                       UINT8_C(187), UINT8_C(114), UINT8_C(108), UINT8_C(190)),
      simde_x_vload_u8(UINT8_C( 79), UINT8_C(  2), UINT8_C(133), UINT8_C(224),
                       UINT8_C(152), UINT8_C( 56), UINT8_C(208), UINT8_C(244)) },
    { simde_x_vload_u8(UINT8_C(144), UINT8_C(250), UINT8_C( 70), UINT8_C(245),
                       UINT8_C(242), UINT8_C( 79), UINT8_C(119), UINT8_C(191)),
      simde_x_vload_u8(UINT8_C(  7), UINT8_C(166), UINT8_C( 88), UINT8_C( 47),
                       UINT8_C( 44), UINT8_C( 81), UINT8_C(234), UINT8_C(140)),
      simde_x_vload_u8(UINT8_C(240), UINT8_C( 28), UINT8_C( 16), UINT8_C(251),
                       UINT8_C(152), UINT8_C(255), UINT8_C(198), UINT8_C(116)) },
    { simde_x_vload_u8(UINT8_C(144), UINT8_C( 31), UINT8_C(104), UINT8_C( 79),
                       UINT8_C( 59), UINT8_C(248), UINT8_C( 83), UINT8_C( 47)),
      simde_x_vload_u8(UINT8_C(213), UINT8_C(219), UINT8_C(235), UINT8_C( 56),
                       UINT8_C(101), UINT8_C( 11), UINT8_C(121), UINT8_C(224)),
      simde_x_vload_u8(UINT8_C(208), UINT8_C(133), UINT8_C(120), UINT8_C( 72),
                       UINT8_C( 71), UINT8_C(168), UINT8_C( 59), UINT8_C( 32)) },
    { simde_x_vload_u8(UINT8_C( 60), UINT8_C( 93), UINT8_C(193), UINT8_C(141),
                       UINT8_C( 94), UINT8_C( 73), UINT8_C( 11), UINT8_C(237)),
      simde_x_vload_u8(UINT8_C(212), UINT8_C(250), UINT8_C(105), UINT8_C( 20),
                       UINT8_C( 97), UINT8_C(145), UINT8_C( 38), UINT8_C(145)),
      simde_x_vload_u8(UINT8_C(176), UINT8_C(210), UINT8_C( 41), UINT8_C(  4),
                       UINT8_C(158), UINT8_C( 89), UINT8_C(162), UINT8_C( 61)) },
    { simde_x_vload_u8(UINT8_C(  0), UINT8_C( 70), UINT8_C(114), UINT8_C(145),
                       UINT8_C( 45), UINT8_C(152), UINT8_C(129), UINT8_C( 87)),
      simde_x_vload_u8(UINT8_C( 26), UINT8_C(240), UINT8_C( 84), UINT8_C(165),
                       UINT8_C(123), UINT8_C( 30), UINT8_C( 67), UINT8_C(102)),
      simde_x_vload_u8(UINT8_C(  0), UINT8_C(160), UINT8_C(104), UINT8_C(117),
                       UINT8_C(159), UINT8_C(208), UINT8_C(195), UINT8_C(170)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_uint8x8_t r = simde_vmul_u8(test_vec[i].a, test_vec[i].b);
    simde_neon_assert_uint8x8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_vmul_u16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_uint16x4_t a;
    simde_uint16x4_t b;
    simde_uint16x4_t r;
  } test_vec[8] = {
    { simde_x_vload_u16(UINT16_C( 3243), UINT16_C(48979), UINT16_C(13740), UINT16_C(  548)),
      simde_x_vload_u16(UINT16_C(33299), UINT16_C(22598), UINT16_C(38440), UINT16_C(37700)),
      simde_x_vload_u16(UINT16_C(50865), UINT16_C(55474), UINT16_C(10976), UINT16_C(15760)) },
    { simde_x_vload_u16(UINT16_C(33812), UINT16_C(24559), UINT16_C(20280), UINT16_C(29924)),
      simde_x_vload_u16(UINT16_C( 1544), UINT16_C(35519), UINT16_C(26256), UINT16_C(45486)),
      simde_x_vload_u16(UINT16_C(39072), UINT16_C(26961), UINT16_C(57216), UINT16_C( 5880)) },
    { simde_x_vload_u16(UINT16_C(42628), UINT16_C(33742), UINT16_C(64614), UINT16_C(12076)),
      simde_x_vload_u16(UINT16_C(34782), UINT16_C(62945), UINT16_C(57802), UINT16_C( 3464)),
      simde_x_vload_u16(UINT16_C(  632), UINT16_C(65038), UINT16_C(52860), UINT16_C(19296)) },
    { simde_x_vload_u16(UINT16_C(30310), UINT16_C(13289), UINT16_C(24252), UINT16_C(44497)),
      simde_x_vload_u16(UINT16_C(60569), UINT16_C(42651), UINT16_C(61697), UINT16_C( 5994)),
      simde_x_vload_u16(UINT16_C(51958), UINT16_C(33811), UINT16_C(23228), UINT16_C(49034)) },
    { simde_x_vload_u16(UINT16_C(13840), UINT16_C(32818), UINT16_C(16327), UINT16_C(45233)),
      simde_x_vload_u16(UINT16_C(53905), UINT16_C(53691), UINT16_C(49691), UINT16_C(13942)),
      simde_x_vload_u16(UINT16_C(48912), UINT16_C(30342), UINT16_C(34813), UINT16_C(51094)) },
    { simde_x_vload_u16(UINT16_C(22976), UINT16_C(40255), UINT16_C(55574), UINT16_C(29449)),
      simde_x_vload_u16(UINT16_C(56709), UINT16_C(22563), UINT16_C(29259), UINT16_C(28398)),
      simde_x_vload_u16(UINT16_C(24768), UINT16_C(10141), UINT16_C(25970), UINT16_C(53342)) },
    { simde_x_vload_u16(UINT16_C(60271), UINT16_C(29991), UINT16_C( 1809), UINT16_C(12217)),
      simde_x_vload_u16(UINT16_C(38755), UINT16_C(35233), UINT16_C(42873), UINT16_C(28048)),
      simde_x_vload_u16(UINT16_C(34029), UINT16_C(35975), UINT16_C(28169), UINT16_C(40208)) },
    { simde_x_vload_u16(UINT16_C(14808), UINT16_C(46271), UINT16_C(  898), UINT16_C(34464)),
      simde_x_vload_u16(UINT16_C(11637), UINT16_C(17181), UINT16_C(45377), UINT16_C(21995)),
      simde_x_vload_u16(UINT16_C(26552), UINT16_C(30371), UINT16_C(50690), UINT16_C(46304)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_uint16x4_t r = simde_vmul_u16(test_vec[i].a, test_vec[i].b);
    simde_neon_assert_uint16x4(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_vmul_u32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_uint32x2_t a;
    simde_uint32x2_t b;
    simde_uint32x2_t r;
  } test_vec[8] = {
    { simde_x_vload_u32(UINT32_C(3269571689), UINT32_C( 733666179)),
      simde_x_vload_u32(UINT32_C(3150126302), UINT32_C(3039826473)),
      simde_x_vload_u32(UINT32_C(3463507726), UINT32_C(3958136315)) },
    { simde_x_vload_u32(UINT32_C(3052965843), UINT32_C(2222125336)),
      simde_x_vload_u32(UINT32_C( 191761853), UINT32_C(3420348928)),
      simde_x_vload_u32(UINT32_C(3581535687), UINT32_C( 454766592)) },
    { simde_x_vload_u32(UINT32_C(  25380888), UINT32_C(2761087377)),
      simde_x_vload_u32(UINT32_C(2170081949), UINT32_C(2408729295)),
      simde_x_vload_u32(UINT32_C(2129061560), UINT32_C(2572408383)) },
    { simde_x_vload_u32(UINT32_C(1772322605), UINT32_C(2834267239)),
      simde_x_vload_u32(UINT32_C(1803133576), UINT32_C(1820444802)),
      simde_x_vload_u32(UINT32_C(2157644264), UINT32_C( 112501838)) },
    { simde_x_vload_u32(UINT32_C(1769263504), UINT32_C(1439650640)),
      simde_x_vload_u32(UINT32_C(3130677651), UINT32_C(2329460577)),
      simde_x_vload_u32(UINT32_C(3683607984), UINT32_C(2654421328)) },
    { simde_x_vload_u32(UINT32_C(3689635154), UINT32_C( 675235401)),
      simde_x_vload_u32(UINT32_C(2394861819), UINT32_C(  13551513)),
      simde_x_vload_u32(UINT32_C( 784916326), UINT32_C(3425812641)) },
    { simde_x_vload_u32(UINT32_C(  32265746), UINT32_C(1506124520)),
      simde_x_vload_u32(UINT32_C( 586841937), UINT32_C(2995843402)),
      simde_x_vload_u32(UINT32_C(1275996594), UINT32_C(4093476624)) },
    { simde_x_vload_u32(UINT32_C( 493330379), UINT32_C(3333627124)),
      simde_x_vload_u32(UINT32_C(4056152600), UINT32_C( 122221865)),
      simde_x_vload_u32(UINT32_C(3328456968), UINT32_C( 235218708)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_uint32x2_t r = simde_vmul_u32(test_vec[i].a, test_vec[i].b);
    simde_neon_assert_uint32x2(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_vmul_f32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_float32x2_t a;
    simde_float32x2_t b;
    simde_float32x2_t r;
  } test_vec[8] = {
    { simde_x_vload_f32(SIMDE_FLOAT32_C(  709.32), SIMDE_FLOAT32_C(  328.06)),
      simde_x_vload_f32(SIMDE_FLOAT32_C( -587.68), SIMDE_FLOAT32_C(  662.19)),
      simde_x_vload_f32(SIMDE_FLOAT32_C(-416853.19), SIMDE_FLOAT32_C(217238.05)) },
    { simde_x_vload_f32(SIMDE_FLOAT32_C(  272.36), SIMDE_FLOAT32_C( -510.45)),
      simde_x_vload_f32(SIMDE_FLOAT32_C(  160.08), SIMDE_FLOAT32_C( -874.02)),
      simde_x_vload_f32(SIMDE_FLOAT32_C(43599.39), SIMDE_FLOAT32_C(446143.53)) },
    { simde_x_vload_f32(SIMDE_FLOAT32_C( -793.25), SIMDE_FLOAT32_C(  239.08)),
      simde_x_vload_f32(SIMDE_FLOAT32_C(  670.43), SIMDE_FLOAT32_C(  908.32)),
      simde_x_vload_f32(SIMDE_FLOAT32_C(-531818.56), SIMDE_FLOAT32_C(217161.16)) },
    { simde_x_vload_f32(SIMDE_FLOAT32_C(  536.53), SIMDE_FLOAT32_C(  128.77)),
      simde_x_vload_f32(SIMDE_FLOAT32_C(  717.28), SIMDE_FLOAT32_C(   92.51)),
      simde_x_vload_f32(SIMDE_FLOAT32_C(384842.28), SIMDE_FLOAT32_C(11912.51)) },
    { simde_x_vload_f32(SIMDE_FLOAT32_C(  477.63), SIMDE_FLOAT32_C(  569.89)),
      simde_x_vload_f32(SIMDE_FLOAT32_C( -104.64), SIMDE_FLOAT32_C( -250.44)),
      simde_x_vload_f32(SIMDE_FLOAT32_C(-49979.20), SIMDE_FLOAT32_C(-142723.25)) },
    { simde_x_vload_f32(SIMDE_FLOAT32_C( -148.80), SIMDE_FLOAT32_C(  904.67)),
      simde_x_vload_f32(SIMDE_FLOAT32_C( -644.39), SIMDE_FLOAT32_C(  -98.71)),
      simde_x_vload_f32(SIMDE_FLOAT32_C(95885.23), SIMDE_FLOAT32_C(-89299.98)) },
    { simde_x_vload_f32(SIMDE_FLOAT32_C( -491.91), SIMDE_FLOAT32_C( -357.57)),
      simde_x_vload_f32(SIMDE_FLOAT32_C(  647.10), SIMDE_FLOAT32_C( -816.96)),
      simde_x_vload_f32(SIMDE_FLOAT32_C(-318314.94), SIMDE_FLOAT32_C(292120.41)) },
    { simde_x_vload_f32(SIMDE_FLOAT32_C(  942.18), SIMDE_FLOAT32_C( -728.13)),
      simde_x_vload_f32(SIMDE_FLOAT32_C(  796.63), SIMDE_FLOAT32_C( -402.16)),
      simde_x_vload_f32(SIMDE_FLOAT32_C(750568.88), SIMDE_FLOAT32_C(292824.75)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_float32x2_t r = simde_vmul_f32(test_vec[i].a, test_vec[i].b);
    simde_neon_assert_float32x2_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_vmul_f64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_float64x1_t a;
    simde_float64x1_t b;
    simde_float64x1_t r;
  } test_vec[8] = {
    { simde_x_vload_f64(SIMDE_FLOAT64_C(  550.79)),
      simde_x_vload_f64(SIMDE_FLOAT64_C(  249.76)),
      simde_x_vload_f64(SIMDE_FLOAT64_C(137565.31)) },
    { simde_x_vload_f64(SIMDE_FLOAT64_C( -302.70)),
      simde_x_vload_f64(SIMDE_FLOAT64_C( -373.11)),
      simde_x_vload_f64(SIMDE_FLOAT64_C(112940.40)) },
    { simde_x_vload_f64(SIMDE_FLOAT64_C(  541.09)),
      simde_x_vload_f64(SIMDE_FLOAT64_C(  765.69)),
      simde_x_vload_f64(SIMDE_FLOAT64_C(414307.20)) },
    { simde_x_vload_f64(SIMDE_FLOAT64_C(  829.25)),
      simde_x_vload_f64(SIMDE_FLOAT64_C(  607.20)),
      simde_x_vload_f64(SIMDE_FLOAT64_C(503520.60)) },
    { simde_x_vload_f64(SIMDE_FLOAT64_C( -860.60)),
      simde_x_vload_f64(SIMDE_FLOAT64_C( -496.29)),
      simde_x_vload_f64(SIMDE_FLOAT64_C(427107.17)) },
    { simde_x_vload_f64(SIMDE_FLOAT64_C(  398.42)),
      simde_x_vload_f64(SIMDE_FLOAT64_C(  348.46)),
      simde_x_vload_f64(SIMDE_FLOAT64_C(138833.43)) },
    { simde_x_vload_f64(SIMDE_FLOAT64_C(  -13.38)),
      simde_x_vload_f64(SIMDE_FLOAT64_C(  905.20)),
      simde_x_vload_f64(SIMDE_FLOAT64_C(-12111.58)) },
    { simde_x_vload_f64(SIMDE_FLOAT64_C( -883.24)),
      simde_x_vload_f64(SIMDE_FLOAT64_C(  588.39)),
      simde_x_vload_f64(SIMDE_FLOAT64_C(-519689.58)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_float64x1_t r = simde_vmul_f64(test_vec[i].a, test_vec[i].b);
    simde_neon_assert_float64x1_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_vmulq_s8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_int8x16_t a;
    simde_int8x16_t b;
    simde_int8x16_t r;
  } test_vec[8] = {
    { simde_x_vloadq_s8(INT8_C(-127), INT8_C(  30), INT8_C( -94), INT8_C(  45),
                        INT8_C(  22), INT8_C(  -3), INT8_C(  39), INT8_C( 115),
                        INT8_C( 112), INT8_C( -51), INT8_C( 121), INT8_C( 125),
                        INT8_C( -78), INT8_C(  69), INT8_C( -42), INT8_C(  74)),
      simde_x_vloadq_s8(INT8_C(  35), INT8_C( -23), INT8_C( -17), INT8_C(-126),
                        INT8_C( -31), INT8_C(-106), INT8_C( -83), INT8_C(-118),
                        INT8_C(  40), INT8_C(-126), INT8_C(  -6), INT8_C(  38),
                        INT8_C( -47), INT8_C( 106), INT8_C( -22), INT8_C( -69)),
      simde_x_vloadq_s8(INT8_C( -93), INT8_C(  78), INT8_C(  62), INT8_C( -38),
                        INT8_C(  86), INT8_C(  62), INT8_C(  91), INT8_C(  -2),
                        INT8_C(-128), INT8_C(  26), INT8_C(  42), INT8_C(-114),
                        INT8_C(  82), INT8_C(-110), INT8_C(-100), INT8_C(  14)) },
    { simde_x_vloadq_s8(INT8_C( -46), INT8_C(  10), INT8_C( -18), INT8_C( -86),
                        INT8_C(  84), INT8_C( -75), INT8_C(  -6), INT8_C( -52),
                        INT8_C( -15), INT8_C(  62), INT8_C( 113), INT8_C(  52),
                        INT8_C( 118), INT8_C(  40), INT8_C(-114), INT8_C( -53)),
      simde_x_vloadq_s8(INT8_C( 118), INT8_C(  -3), INT8_C(  61), INT8_C(  26),
                        INT8_C(-111), INT8_C(   7), INT8_C( -62), INT8_C(-109),
                        INT8_C(  75), INT8_C( 107), INT8_C(  24), INT8_C( -50),
                        INT8_C( -58), INT8_C( -11), INT8_C(-125), INT8_C(  65)),
      simde_x_vloadq_s8(INT8_C( -52), INT8_C( -30), INT8_C( -74), INT8_C(  68),
                        INT8_C(-108), INT8_C( -13), INT8_C( 116), INT8_C(  36),
                        INT8_C(-101), INT8_C( -22), INT8_C(-104), INT8_C( -40),
                        INT8_C(  68), INT8_C(  72), INT8_C( -86), INT8_C(-117)) },
    { simde_x_vloadq_s8(INT8_C(  24), INT8_C( -71), INT8_C(  80), INT8_C( -24),
                        INT8_C(  97), INT8_C(   8), INT8_C(  91), INT8_C( -11),
                        INT8_C(  -1), INT8_C(  82), INT8_C(  52), INT8_C(  98),
                        INT8_C( -56), INT8_C(  61), INT8_C( 103), INT8_C(  17)),
      simde_x_vloadq_s8(INT8_C( 108), INT8_C(-120), INT8_C(  84), INT8_C(  59),
                        INT8_C( -97), INT8_C( -12), INT8_C(  19), INT8_C(-111),
                        INT8_C( -18), INT8_C(  16), INT8_C(-109), INT8_C(  92),
                        INT8_C(  19), INT8_C( -30), INT8_C(  92), INT8_C(  34)),
      simde_x_vloadq_s8(INT8_C(  32), INT8_C(  72), INT8_C(  64), INT8_C( 120),
                        INT8_C(  63), INT8_C( -96), INT8_C( -63), INT8_C( -59),
                        INT8_C(  18), INT8_C(  32), INT8_C( -36), INT8_C(  56),
                        INT8_C( -40), INT8_C( -38), INT8_C(   4), INT8_C(  66)) },
    { simde_x_vloadq_s8(INT8_C( 119), INT8_C(  38), INT8_C(-126), INT8_C(-104),
                        INT8_C(  -9), INT8_C( -61), INT8_C( -53), INT8_C(-102),
                        INT8_C(  34), INT8_C(-123), INT8_C(  94), INT8_C( 102),
                        INT8_C( 126), INT8_C( -98), INT8_C( -82), INT8_C(  70)),
      simde_x_vloadq_s8(INT8_C( -36), INT8_C(  31), INT8_C( -43), INT8_C( -87),
                        INT8_C(-101), INT8_C(  37), INT8_C(  51), INT8_C(  62),
                        INT8_C(  55), INT8_C( 107), INT8_C(  19), INT8_C( -79),
                        INT8_C( -67), INT8_C(-104), INT8_C( -66), INT8_C( -28)),
      simde_x_vloadq_s8(INT8_C(  68), INT8_C(-102), INT8_C(  42), INT8_C(  88),
                        INT8_C(-115), INT8_C(  47), INT8_C( 113), INT8_C(  76),
                        INT8_C(  78), INT8_C(-105), INT8_C(  -6), INT8_C(-122),
                        INT8_C(   6), INT8_C( -48), INT8_C(  36), INT8_C(  88)) },
    { simde_x_vloadq_s8(INT8_C(  34), INT8_C( -79), INT8_C( -76), INT8_C(  98),
                        INT8_C(   2), INT8_C( -94), INT8_C(  51), INT8_C(  68),
                        INT8_C(-107), INT8_C(  82), INT8_C(  -6), INT8_C( -35),
                        INT8_C(   7), INT8_C( -99), INT8_C(  36), INT8_C(   3)),
      simde_x_vloadq_s8(INT8_C(  88), INT8_C(   9), INT8_C( -47), INT8_C(  -9),
                        INT8_C(  52), INT8_C( 114), INT8_C(  79), INT8_C(  52),
                        INT8_C(   3), INT8_C(  -2), INT8_C(-115), INT8_C( -50),
                        INT8_C(  58), INT8_C(  37), INT8_C(-126), INT8_C(   9)),
      simde_x_vloadq_s8(INT8_C( -80), INT8_C(  57), INT8_C( -12), INT8_C(-114),
                        INT8_C( 104), INT8_C(  36), INT8_C( -67), INT8_C( -48),
                        INT8_C( -65), INT8_C(  92), INT8_C( -78), INT8_C( -42),
                        INT8_C(-106), INT8_C( -79), INT8_C(  72), INT8_C(  27)) },
    { simde_x_vloadq_s8(INT8_C(  10), INT8_C( 124), INT8_C(  81), INT8_C(  42),
                        INT8_C(  82), INT8_C( -37), INT8_C( 125), INT8_C(  86),
                        INT8_C( -51), INT8_C(-126), INT8_C( -82), INT8_C( -29),
                        INT8_C(  74), INT8_C( 115), INT8_C( -92), INT8_C(-111)),
      simde_x_vloadq_s8(INT8_C( -46), INT8_C( 126), INT8_C( -67), INT8_C( 122),
                        INT8_C(  17), INT8_C( -26), INT8_C(  92), INT8_C(  45),
                        INT8_C( -76), INT8_C(  13), INT8_C(  59), INT8_C(  23),
                        INT8_C( -74), INT8_C( -28), INT8_C(-126), INT8_C( -57)),
      simde_x_vloadq_s8(INT8_C(  52), INT8_C(   8), INT8_C( -51), INT8_C(   4),
                        INT8_C( 114), INT8_C( -62), INT8_C( -20), INT8_C(  30),
                        INT8_C(  36), INT8_C(-102), INT8_C(  26), INT8_C( 101),
                        INT8_C(-100), INT8_C( 108), INT8_C(  72), INT8_C( -73)) },
    { simde_x_vloadq_s8(INT8_C(-110), INT8_C( 103), INT8_C( -90), INT8_C( -37),
                        INT8_C(  10), INT8_C( -77), INT8_C( -99), INT8_C( -84),
                        INT8_C(  39), INT8_C(  66), INT8_C( -48), INT8_C( -53),
                        INT8_C(  76), INT8_C(  34), INT8_C( -75), INT8_C( 106)),
      simde_x_vloadq_s8(INT8_C( -23), INT8_C(  95), INT8_C( -41), INT8_C(  -9),
                        INT8_C(-122), INT8_C(  76), INT8_C(-125), INT8_C( -69),
                        INT8_C(  22), INT8_C( -84), INT8_C(  36), INT8_C( 108),
                        INT8_C(-116), INT8_C(-127), INT8_C(   2), INT8_C( 124)),
      simde_x_vloadq_s8(INT8_C( -30), INT8_C(  57), INT8_C( 106), INT8_C(  77),
                        INT8_C(  60), INT8_C(  36), INT8_C(  87), INT8_C( -92),
                        INT8_C(  90), INT8_C(  88), INT8_C(  64), INT8_C( -92),
                        INT8_C(-112), INT8_C(  34), INT8_C( 106), INT8_C(  88)) },
    { simde_x_vloadq_s8(INT8_C( -61), INT8_C( -14), INT8_C(  90), INT8_C(  34),
                        INT8_C( -60), INT8_C(  47), INT8_C(  73), INT8_C(   4),
                        INT8_C( 101), INT8_C( -83), INT8_C(  12), INT8_C( -87),
                        INT8_C( -41), INT8_C(  33), INT8_C(  95), INT8_C(  47)),
      simde_x_vloadq_s8(INT8_C(  43), INT8_C( -60), INT8_C( 103), INT8_C(  61),
                        INT8_C(  87), INT8_C( -37), INT8_C(   8), INT8_C(  89),
                        INT8_C(  78), INT8_C( -98), INT8_C(-109), INT8_C(  95),
                        INT8_C(   3), INT8_C( -59), INT8_C( 114), INT8_C( -99)),
      simde_x_vloadq_s8(INT8_C( -63), INT8_C(  72), INT8_C(  54), INT8_C(  26),
                        INT8_C(-100), INT8_C(  53), INT8_C(  72), INT8_C( 100),
                        INT8_C( -58), INT8_C( -58), INT8_C( -28), INT8_C( -73),
                        INT8_C(-123), INT8_C( 101), INT8_C(  78), INT8_C( -45)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_int8x16_t r = simde_vmulq_s8(test_vec[i].a, test_vec[i].b);
    simde_neon_assert_int8x16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_vmulq_s16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_int16x8_t a;
    simde_int16x8_t b;
    simde_int16x8_t r;
  } test_vec[8] = {
    { simde_x_vloadq_s16(INT16_C(  3606), INT16_C(-26146), INT16_C( 29578), INT16_C(-21917),
                         INT16_C( 16291), INT16_C(-12460), INT16_C( 16844), INT16_C( -7447)),
      simde_x_vloadq_s16(INT16_C(-14567), INT16_C( -9750), INT16_C(-13348), INT16_C(-21787),
                         INT16_C(-10512), INT16_C(-12251), INT16_C(-12570), INT16_C(  1106)),
      simde_x_vloadq_s16(INT16_C( 31270), INT16_C(-11540), INT16_C(-18280), INT16_C( 10383),
                         INT16_C( -5424), INT16_C( 14116), INT16_C( 17736), INT16_C( 21154)) },
    { simde_x_vloadq_s16(INT16_C(  -110), INT16_C( 17978), INT16_C(-18156), INT16_C( 14375),
                         INT16_C(-18791), INT16_C( 12877), INT16_C( 31925), INT16_C(-31559)),
      simde_x_vloadq_s16(INT16_C(-30054), INT16_C(-28348), INT16_C( 11497), INT16_C(-23041),
                         INT16_C(-12411), INT16_C(  8254), INT16_C(-11572), INT16_C( 28407)),
      simde_x_vloadq_s16(INT16_C( 29140), INT16_C(-32408), INT16_C( -7372), INT16_C(  4569),
                         INT16_C(-27523), INT16_C(-12634), INT16_C( -9668), INT16_C(-29569)) },
    { simde_x_vloadq_s16(INT16_C( -5983), INT16_C( 29026), INT16_C( 18029), INT16_C(  5032),
                         INT16_C(-21014), INT16_C(-14771), INT16_C( 32443), INT16_C(-21683)),
      simde_x_vloadq_s16(INT16_C(-17878), INT16_C( -2583), INT16_C( 19128), INT16_C( -6228),
                         INT16_C( 28126), INT16_C(-22741), INT16_C(-24337), INT16_C(-26084)),
      simde_x_vloadq_s16(INT16_C(  9322), INT16_C(  -974), INT16_C(  8280), INT16_C(-13088),
                         INT16_C( 29420), INT16_C(-30225), INT16_C( 12437), INT16_C(  3692)) },
    { simde_x_vloadq_s16(INT16_C( -2929), INT16_C( -6488), INT16_C(-13187), INT16_C( -1982),
                         INT16_C( 17773), INT16_C( 15022), INT16_C( 13905), INT16_C( 10993)),
      simde_x_vloadq_s16(INT16_C( 16456), INT16_C(-22704), INT16_C(-19837), INT16_C( 30752),
                         INT16_C(-10591), INT16_C(-26882), INT16_C(  2522), INT16_C(  9207)),
      simde_x_vloadq_s16(INT16_C(-30664), INT16_C(-21376), INT16_C(-29193), INT16_C( -1984),
                         INT16_C(-14451), INT16_C( 11428), INT16_C(  6650), INT16_C( 24967)) },
    { simde_x_vloadq_s16(INT16_C( -8487), INT16_C( 18864), INT16_C(-23663), INT16_C( -2393),
                         INT16_C(-30875), INT16_C( 25925), INT16_C(   115), INT16_C(-31502)),
      simde_x_vloadq_s16(INT16_C( 19805), INT16_C(-22785), INT16_C( 13361), INT16_C( 31862),
                         INT16_C(-27097), INT16_C(-13524), INT16_C( 23305), INT16_C(  4600)),
      simde_x_vloadq_s16(INT16_C( 14805), INT16_C(-31152), INT16_C(-15679), INT16_C(-27398),
                         INT16_C(-12701), INT16_C(  7900), INT16_C( -6901), INT16_C( -9104)) },
    { simde_x_vloadq_s16(INT16_C(  3051), INT16_C( 10349), INT16_C( 12948), INT16_C(  9215),
                         INT16_C( -2354), INT16_C(-30618), INT16_C(-28405), INT16_C(  9209)),
      simde_x_vloadq_s16(INT16_C(-12161), INT16_C(-14552), INT16_C(-19362), INT16_C( 27494),
                         INT16_C( -8686), INT16_C(  1070), INT16_C(-30539), INT16_C( 25944)),
      simde_x_vloadq_s16(INT16_C( -9835), INT16_C(  3080), INT16_C(-23976), INT16_C( -4966),
                         INT16_C(  -388), INT16_C(  6740), INT16_C( 25799), INT16_C(-25960)) },
    { simde_x_vloadq_s16(INT16_C(-12070), INT16_C( 24160), INT16_C(-23416), INT16_C(-30079),
                         INT16_C(  5294), INT16_C( 11657), INT16_C(-31940), INT16_C(  7362)),
      simde_x_vloadq_s16(INT16_C(-14737), INT16_C( 20723), INT16_C(  9772), INT16_C(-12264),
                         INT16_C( 24972), INT16_C(-24660), INT16_C( -4901), INT16_C( 23959)),
      simde_x_vloadq_s16(INT16_C( 10886), INT16_C(-27360), INT16_C( 30560), INT16_C(-13288),
                         INT16_C( 15656), INT16_C(-20724), INT16_C(-27564), INT16_C( 28782)) },
    { simde_x_vloadq_s16(INT16_C(-19244), INT16_C(-24194), INT16_C(-25952), INT16_C(-16694),
                         INT16_C( 20006), INT16_C(-12804), INT16_C( 17167), INT16_C(  -934)),
      simde_x_vloadq_s16(INT16_C( -5526), INT16_C( 27910), INT16_C(-12649), INT16_C( -8536),
                         INT16_C( 32495), INT16_C( 12909), INT16_C( 11959), INT16_C(  8750)),
      simde_x_vloadq_s16(INT16_C(-22584), INT16_C( 28404), INT16_C( -2976), INT16_C( 24720),
                         INT16_C(-22150), INT16_C( -5044), INT16_C(-24135), INT16_C( 19500)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_int16x8_t r = simde_vmulq_s16(test_vec[i].a, test_vec[i].b);
    simde_neon_assert_int16x8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_vmulq_s32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_int32x4_t a;
    simde_int32x4_t b;
    simde_int32x4_t r;
  } test_vec[8] = {
    { simde_x_vloadq_s32(INT32_C( 1123170826), INT32_C( 1724201296),
                         INT32_C(-1071829400), INT32_C( -605407000)),
      simde_x_vloadq_s32(INT32_C(-1297699783), INT32_C(  827772923),
                         INT32_C(  918675174), INT32_C( -817623083)),
      simde_x_vloadq_s32(INT32_C( 1030333498), INT32_C( -845749904),
                         INT32_C( -723656336), INT32_C( 1758916872)) },
    { simde_x_vloadq_s32(INT32_C( 1918919185), INT32_C(  262393006),
                         INT32_C( 1657094748), INT32_C(  837021098)),
      simde_x_vloadq_s32(INT32_C( 1949462567), INT32_C(-1250655484),
                         INT32_C( 1421638944), INT32_C(-1778492349)),
      simde_x_vloadq_s32(INT32_C( 1927831703), INT32_C( -719045448),
                         INT32_C(-1784727680), INT32_C(-1195619458)) },
    { simde_x_vloadq_s32(INT32_C(-1515943730), INT32_C( 2003246422),
                         INT32_C( 1694426031), INT32_C(-1948948754)),
      simde_x_vloadq_s32(INT32_C( -398862630), INT32_C( 2132045133),
                         INT32_C(-1807602235), INT32_C( 1783413341)),
      simde_x_vloadq_s32(INT32_C(-1101614228), INT32_C( -969314082),
                         INT32_C( 1699281067), INT32_C( -201895818)) },
    { simde_x_vloadq_s32(INT32_C( -764500520), INT32_C(-1890077122),
                         INT32_C( -441183161), INT32_C( 1043231808)),
      simde_x_vloadq_s32(INT32_C( 1295880986), INT32_C(  533621567),
                         INT32_C( -165031911), INT32_C( -725208039)),
      simde_x_vloadq_s32(INT32_C( 1693442032), INT32_C(  396739394),
                         INT32_C(  946776815), INT32_C( 1806064192)) },
    { simde_x_vloadq_s32(INT32_C(-1009530908), INT32_C(-1685480510),
                         INT32_C( -100061526), INT32_C(  486038522)),
      simde_x_vloadq_s32(INT32_C(-2078046313), INT32_C( -449627785),
                         INT32_C(-1737499256), INT32_C(-1480286984)),
      simde_x_vloadq_s32(INT32_C(  343942012), INT32_C(-2108974802),
                         INT32_C( -304116656), INT32_C( -368217552)) },
    { simde_x_vloadq_s32(INT32_C(-1961990836), INT32_C( 1719683566),
                         INT32_C( 1283520022), INT32_C(  427779620)),
      simde_x_vloadq_s32(INT32_C(-1041353110), INT32_C( 2047817713),
                         INT32_C( -453743286), INT32_C( -190808905)),
      simde_x_vloadq_s32(INT32_C(  368834936), INT32_C( -812008690),
                         INT32_C(  721846364), INT32_C(  369849276)) },
    { simde_x_vloadq_s32(INT32_C( -205929908), INT32_C(-1288775358),
                         INT32_C( 1260732697), INT32_C(-1728995848)),
      simde_x_vloadq_s32(INT32_C( -474735779), INT32_C(-1917133953),
                         INT32_C(  269438727), INT32_C(  588750565)),
      simde_x_vloadq_s32(INT32_C(  594123164), INT32_C(  739065278),
                         INT32_C( -309166417), INT32_C(  149511896)) },
    { simde_x_vloadq_s32(INT32_C( 1285818920), INT32_C(  251500733),
                         INT32_C( -957328722), INT32_C(  376096822)),
      simde_x_vloadq_s32(INT32_C(-1080123710), INT32_C(  -43912310),
                         INT32_C( -764093305), INT32_C( 1166743576)),
      simde_x_vloadq_s32(INT32_C( 1866752592), INT32_C( 1967963362),
                         INT32_C(-1566498366), INT32_C( 1612305680)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_int32x4_t r = simde_vmulq_s32(test_vec[i].a, test_vec[i].b);
    simde_neon_assert_int32x4(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_vmulq_u8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_uint8x16_t a;
    simde_uint8x16_t b;
    simde_uint8x16_t r;
  } test_vec[8] = {
    { simde_x_vloadq_u8(UINT8_C(126), UINT8_C( 74), UINT8_C( 80), UINT8_C(137),
                        UINT8_C( 99), UINT8_C(157), UINT8_C(205), UINT8_C(210),
                        UINT8_C( 39), UINT8_C( 80), UINT8_C(198), UINT8_C( 44),
                        UINT8_C(160), UINT8_C(209), UINT8_C(123), UINT8_C(223) ),
      simde_x_vloadq_u8(UINT8_C(164), UINT8_C( 57), UINT8_C(116), UINT8_C(244),
                        UINT8_C( 62), UINT8_C( 78), UINT8_C(109), UINT8_C(114),
                        UINT8_C( 12), UINT8_C(108), UINT8_C( 47), UINT8_C(217),
                        UINT8_C( 64), UINT8_C(230), UINT8_C( 89), UINT8_C(254) ),
      simde_x_vloadq_u8(UINT8_C(184), UINT8_C(122), UINT8_C( 64), UINT8_C(148),
                        UINT8_C(250), UINT8_C(214), UINT8_C( 73), UINT8_C(132),
                        UINT8_C(212), UINT8_C(192), UINT8_C( 90), UINT8_C( 76),
                        UINT8_C(  0), UINT8_C(198), UINT8_C(195), UINT8_C( 66) ) },
    { simde_x_vloadq_u8(UINT8_C(130), UINT8_C(192), UINT8_C(246), UINT8_C(206),
                        UINT8_C(120), UINT8_C(140), UINT8_C(116), UINT8_C(157),
                        UINT8_C(128), UINT8_C( 75), UINT8_C(144), UINT8_C(138),
                        UINT8_C(244), UINT8_C( 96), UINT8_C(118), UINT8_C(213) ),
      simde_x_vloadq_u8(UINT8_C(132), UINT8_C(156), UINT8_C( 48), UINT8_C( 81),
                        UINT8_C( 87), UINT8_C( 60), UINT8_C(167), UINT8_C( 88),
                        UINT8_C(202), UINT8_C(206), UINT8_C(182), UINT8_C(144),
                        UINT8_C(125), UINT8_C(103), UINT8_C( 27), UINT8_C(109) ),
      simde_x_vloadq_u8(UINT8_C(  8), UINT8_C(  0), UINT8_C( 32), UINT8_C( 46),
                        UINT8_C(200), UINT8_C(208), UINT8_C(172), UINT8_C(248),
                        UINT8_C(  0), UINT8_C( 90), UINT8_C( 96), UINT8_C(160),
                        UINT8_C( 36), UINT8_C(160), UINT8_C(114), UINT8_C(177) ) },
    { simde_x_vloadq_u8(UINT8_C( 57), UINT8_C( 69), UINT8_C( 12), UINT8_C(222),
                        UINT8_C( 62), UINT8_C( 70), UINT8_C(174), UINT8_C( 65),
                        UINT8_C(234), UINT8_C(200), UINT8_C(157), UINT8_C(  2),
                        UINT8_C(123), UINT8_C(247), UINT8_C( 90), UINT8_C(161) ),
      simde_x_vloadq_u8(UINT8_C(243), UINT8_C( 52), UINT8_C(110), UINT8_C(121),
                        UINT8_C( 94), UINT8_C(106), UINT8_C(150), UINT8_C(135),
                        UINT8_C( 38), UINT8_C(108), UINT8_C( 84), UINT8_C(152),
                        UINT8_C( 79), UINT8_C( 50), UINT8_C(197), UINT8_C(194) ),
      simde_x_vloadq_u8(UINT8_C( 27), UINT8_C(  4), UINT8_C( 40), UINT8_C(238),
                        UINT8_C(196), UINT8_C(252), UINT8_C(244), UINT8_C( 71),
                        UINT8_C(188), UINT8_C( 96), UINT8_C(132), UINT8_C( 48),
                        UINT8_C(245), UINT8_C( 62), UINT8_C( 66), UINT8_C(  2) ) },
    { simde_x_vloadq_u8(UINT8_C( 31), UINT8_C( 18), UINT8_C(  4), UINT8_C( 19),
                        UINT8_C(118), UINT8_C(179), UINT8_C(138), UINT8_C( 53),
                        UINT8_C(106), UINT8_C(228), UINT8_C( 75), UINT8_C(106),
                        UINT8_C(142), UINT8_C(177), UINT8_C(130), UINT8_C(187) ),
      simde_x_vloadq_u8(UINT8_C( 81), UINT8_C(104), UINT8_C( 98), UINT8_C(136),
                        UINT8_C(147), UINT8_C( 62), UINT8_C(226), UINT8_C(107),
                        UINT8_C( 61), UINT8_C(139), UINT8_C(232), UINT8_C( 20),
                        UINT8_C(198), UINT8_C(120), UINT8_C( 39), UINT8_C( 95) ),
      simde_x_vloadq_u8(UINT8_C(207), UINT8_C( 80), UINT8_C(136), UINT8_C( 24),
                        UINT8_C(194), UINT8_C( 90), UINT8_C(212), UINT8_C( 39),
                        UINT8_C( 66), UINT8_C(204), UINT8_C(248), UINT8_C( 72),
                        UINT8_C(212), UINT8_C(248), UINT8_C(206), UINT8_C(101) ) },
    { simde_x_vloadq_u8(UINT8_C(115), UINT8_C( 58), UINT8_C(178), UINT8_C(232),
                        UINT8_C(203), UINT8_C( 40), UINT8_C( 37), UINT8_C(168),
                        UINT8_C(178), UINT8_C(135), UINT8_C(125), UINT8_C(214),
                        UINT8_C(244), UINT8_C( 13), UINT8_C(201), UINT8_C(183) ),
      simde_x_vloadq_u8(UINT8_C(182), UINT8_C( 21), UINT8_C(101), UINT8_C(  9),
                        UINT8_C(209), UINT8_C( 43), UINT8_C(159), UINT8_C(143),
                        UINT8_C( 21), UINT8_C(212), UINT8_C( 67), UINT8_C( 34),
                        UINT8_C( 83), UINT8_C( 77), UINT8_C(196), UINT8_C(245) ),
      simde_x_vloadq_u8(UINT8_C(194), UINT8_C(194), UINT8_C( 58), UINT8_C( 40),
                        UINT8_C(187), UINT8_C(184), UINT8_C(251), UINT8_C(216),
                        UINT8_C(154), UINT8_C(204), UINT8_C(183), UINT8_C(108),
                        UINT8_C( 28), UINT8_C(233), UINT8_C(228), UINT8_C( 35) ) },
    { simde_x_vloadq_u8(UINT8_C( 33), UINT8_C( 64), UINT8_C(252), UINT8_C(104),
                        UINT8_C( 64), UINT8_C(132), UINT8_C(155), UINT8_C(  5),
                        UINT8_C(192), UINT8_C(140), UINT8_C(  9), UINT8_C(119),
                        UINT8_C(111), UINT8_C(109), UINT8_C(122), UINT8_C(221) ),
      simde_x_vloadq_u8(UINT8_C(233), UINT8_C( 26), UINT8_C(123), UINT8_C(153),
                        UINT8_C( 95), UINT8_C(120), UINT8_C(130), UINT8_C(168),
                        UINT8_C( 34), UINT8_C( 37), UINT8_C(150), UINT8_C(150),
                        UINT8_C(207), UINT8_C(153), UINT8_C(251), UINT8_C(245) ),
      simde_x_vloadq_u8(UINT8_C(  9), UINT8_C(128), UINT8_C( 20), UINT8_C( 40),
                        UINT8_C(192), UINT8_C(224), UINT8_C(182), UINT8_C( 72),
                        UINT8_C(128), UINT8_C( 60), UINT8_C( 70), UINT8_C(186),
                        UINT8_C(193), UINT8_C( 37), UINT8_C(158), UINT8_C(129) ) },
    { simde_x_vloadq_u8(UINT8_C( 20), UINT8_C(223), UINT8_C(245), UINT8_C(209),
                        UINT8_C(145), UINT8_C(183), UINT8_C(224), UINT8_C( 55),
                        UINT8_C(113), UINT8_C(226), UINT8_C(146), UINT8_C(229),
                        UINT8_C(255), UINT8_C(156), UINT8_C( 39), UINT8_C(101) ),
      simde_x_vloadq_u8(UINT8_C(119), UINT8_C(140), UINT8_C(  6), UINT8_C(233),
                        UINT8_C( 68), UINT8_C( 82), UINT8_C( 80), UINT8_C( 61),
                        UINT8_C(229), UINT8_C(139), UINT8_C(236), UINT8_C(217),
                        UINT8_C( 55), UINT8_C(231), UINT8_C( 17), UINT8_C( 27) ),
      simde_x_vloadq_u8(UINT8_C( 76), UINT8_C(244), UINT8_C(190), UINT8_C( 57),
                        UINT8_C(132), UINT8_C(158), UINT8_C(  0), UINT8_C( 27),
                        UINT8_C( 21), UINT8_C(182), UINT8_C(152), UINT8_C( 29),
                        UINT8_C(201), UINT8_C(196), UINT8_C(151), UINT8_C(167) ) },
    { simde_x_vloadq_u8(UINT8_C(185), UINT8_C(200), UINT8_C(242), UINT8_C(242),
                        UINT8_C(137), UINT8_C(106), UINT8_C(236), UINT8_C( 70),
                        UINT8_C(127), UINT8_C(191), UINT8_C(140), UINT8_C(  2),
                        UINT8_C(230), UINT8_C(137), UINT8_C(180), UINT8_C( 63) ),
      simde_x_vloadq_u8(UINT8_C(243), UINT8_C( 61), UINT8_C( 95), UINT8_C( 53),
                        UINT8_C(149), UINT8_C( 43), UINT8_C( 36), UINT8_C(164),
                        UINT8_C( 19), UINT8_C(160), UINT8_C(138), UINT8_C( 78),
                        UINT8_C(241), UINT8_C(165), UINT8_C(145), UINT8_C(172) ),
      simde_x_vloadq_u8(UINT8_C(155), UINT8_C(168), UINT8_C(206), UINT8_C( 26),
                        UINT8_C(189), UINT8_C(206), UINT8_C( 48), UINT8_C(216),
                        UINT8_C(109), UINT8_C( 96), UINT8_C(120), UINT8_C(156),
                        UINT8_C(134), UINT8_C( 77), UINT8_C(244), UINT8_C( 84) ) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_uint8x16_t r = simde_vmulq_u8(test_vec[i].a, test_vec[i].b);
    simde_neon_assert_uint8x16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_vmulq_u16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_uint16x8_t a;
    simde_uint16x8_t b;
    simde_uint16x8_t r;
  } test_vec[8] = {
    { simde_x_vloadq_u16(UINT16_C(57954), UINT16_C(44854), UINT16_C(11016), UINT16_C( 7879),
                         UINT16_C(53913), UINT16_C(49380), UINT16_C( 4238), UINT16_C(16363)),
      simde_x_vloadq_u16(UINT16_C(23701), UINT16_C(36025), UINT16_C(20163), UINT16_C(52240),
                         UINT16_C(58420), UINT16_C(35739), UINT16_C(47224), UINT16_C(50522)),
      simde_x_vloadq_u16(UINT16_C(64266), UINT16_C( 9734), UINT16_C(14104), UINT16_C(32880),
                         UINT16_C( 2836), UINT16_C(38412), UINT16_C(53904), UINT16_C(20382)) },
    { simde_x_vloadq_u16(UINT16_C(21507), UINT16_C(16851), UINT16_C(37450), UINT16_C(18168),
                         UINT16_C( 2860), UINT16_C(59306), UINT16_C(60364), UINT16_C(13145)),
      simde_x_vloadq_u16(UINT16_C(55394), UINT16_C(37714), UINT16_C(65217), UINT16_C( 7971),
                         UINT16_C(10952), UINT16_C(29506), UINT16_C(37052), UINT16_C( 2147)),
      simde_x_vloadq_u16(UINT16_C(45350), UINT16_C(16022), UINT16_C(46538), UINT16_C(48104),
                         UINT16_C(62048), UINT16_C( 6100), UINT16_C(59856), UINT16_C(41835)) },
    { simde_x_vloadq_u16(UINT16_C(48292), UINT16_C(62594), UINT16_C( 3256), UINT16_C( 8059),
                         UINT16_C(36503), UINT16_C(23744), UINT16_C( 5869), UINT16_C( 8493)),
      simde_x_vloadq_u16(UINT16_C(44723), UINT16_C(64161), UINT16_C(57320), UINT16_C(37355),
                         UINT16_C(50612), UINT16_C( 6289), UINT16_C(22199), UINT16_C(32637)),
      simde_x_vloadq_u16(UINT16_C(24236), UINT16_C(47554), UINT16_C(52928), UINT16_C(37097),
                         UINT16_C(29996), UINT16_C(35008), UINT16_C(  363), UINT16_C(34297)) },
    { simde_x_vloadq_u16(UINT16_C(13882), UINT16_C(48253), UINT16_C(61217), UINT16_C(33326),
                         UINT16_C( 3325), UINT16_C(37911), UINT16_C(32474), UINT16_C(   30)),
      simde_x_vloadq_u16(UINT16_C(59817), UINT16_C(13531), UINT16_C(58022), UINT16_C(27945),
                         UINT16_C(18424), UINT16_C(18686), UINT16_C(57158), UINT16_C(37766)),
      simde_x_vloadq_u16(UINT16_C(38474), UINT16_C(41711), UINT16_C(12646), UINT16_C(28510),
                         UINT16_C(49176), UINT16_C(26322), UINT16_C(38300), UINT16_C(18868)) },
    { simde_x_vloadq_u16(UINT16_C(29922), UINT16_C(21770), UINT16_C(13743), UINT16_C(64131),
                         UINT16_C(44236), UINT16_C( 6320), UINT16_C( 1235), UINT16_C(12856)),
      simde_x_vloadq_u16(UINT16_C(54137), UINT16_C( 9316), UINT16_C( 7539), UINT16_C( 9579),
                         UINT16_C( 9529), UINT16_C(46971), UINT16_C(14527), UINT16_C(13778)),
      simde_x_vloadq_u16(UINT16_C(34002), UINT16_C(40936), UINT16_C(61597), UINT16_C(41921),
                         UINT16_C(62828), UINT16_C(44176), UINT16_C(49517), UINT16_C(51696)) },
    { simde_x_vloadq_u16(UINT16_C(22341), UINT16_C(29452), UINT16_C(20004), UINT16_C(57521),
                         UINT16_C(15740), UINT16_C(16551), UINT16_C(49777), UINT16_C(63636)),
      simde_x_vloadq_u16(UINT16_C(40908), UINT16_C(34280), UINT16_C(49053), UINT16_C(31260),
                         UINT16_C(58817), UINT16_C( 2677), UINT16_C(12774), UINT16_C(43621)),
      simde_x_vloadq_u16(UINT16_C(26108), UINT16_C(32480), UINT16_C(51220), UINT16_C(60764),
                         UINT16_C(18044), UINT16_C( 4691), UINT16_C(21126), UINT16_C(23140)) },
    { simde_x_vloadq_u16(UINT16_C(38925), UINT16_C(29195), UINT16_C(36350), UINT16_C( 1990),
                         UINT16_C( 2672), UINT16_C( 4756), UINT16_C(59542), UINT16_C(32965)),
      simde_x_vloadq_u16(UINT16_C( 7599), UINT16_C(48968), UINT16_C( 7710), UINT16_C(33995),
                         UINT16_C(56860), UINT16_C(36311), UINT16_C(10145), UINT16_C(14871)),
      simde_x_vloadq_u16(UINT16_C(27107), UINT16_C(18456), UINT16_C(26564), UINT16_C(16898),
                         UINT16_C(17472), UINT16_C( 7756), UINT16_C( 8278), UINT16_C(13235)) },
    { simde_x_vloadq_u16(UINT16_C(50306), UINT16_C(14229), UINT16_C(19051), UINT16_C(24713),
                         UINT16_C(37797), UINT16_C(32691), UINT16_C(32387), UINT16_C(53422)),
      simde_x_vloadq_u16(UINT16_C(52105), UINT16_C(57603), UINT16_C(35832), UINT16_C(27715),
                         UINT16_C(61559), UINT16_C( 2260), UINT16_C(37277), UINT16_C(38380)),
      simde_x_vloadq_u16(UINT16_C(16274), UINT16_C(39871), UINT16_C(12456), UINT16_C( 4059),
                         UINT16_C(20915), UINT16_C(22588), UINT16_C(51543), UINT16_C(42600)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_uint16x8_t r = simde_vmulq_u16(test_vec[i].a, test_vec[i].b);
    simde_neon_assert_uint16x8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_vmulq_u32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_uint32x4_t a;
    simde_uint32x4_t b;
    simde_uint32x4_t r;
  } test_vec[8] = {
    { simde_x_vloadq_u32(UINT32_C(3958288120), UINT32_C( 956872615),
                         UINT32_C(2294683009), UINT32_C(3805713255)),
      simde_x_vloadq_u32(UINT32_C(1250198096), UINT32_C(3188317560),
                         UINT32_C(2975088804), UINT32_C(1157674059)),
      simde_x_vloadq_u32(UINT32_C(3612384640), UINT32_C(2843754824),
                         UINT32_C(1671038628), UINT32_C( 394369837)) },
    { simde_x_vloadq_u32(UINT32_C(3253804944), UINT32_C(2275803417),
                         UINT32_C(3217780119), UINT32_C(2805772733)),
      simde_x_vloadq_u32(UINT32_C(2303755275), UINT32_C( 739359423),
                         UINT32_C( 509143968), UINT32_C(2387159198)),
      simde_x_vloadq_u32(UINT32_C(2527238960), UINT32_C( 810548135),
                         UINT32_C(4205189984), UINT32_C( 941636262)) },
    { simde_x_vloadq_u32(UINT32_C(3316533415), UINT32_C(2372288697),
                         UINT32_C(2634527217), UINT32_C(3578420369)),
      simde_x_vloadq_u32(UINT32_C(2318049332), UINT32_C(1737870643),
                         UINT32_C( 316097046), UINT32_C(1988165889)),
      simde_x_vloadq_u32(UINT32_C( 104145388), UINT32_C( 668994011),
                         UINT32_C(3723521206), UINT32_C(2595745169)) },
    { simde_x_vloadq_u32(UINT32_C(2183642275), UINT32_C(2838944061),
                         UINT32_C( 961498069), UINT32_C(4012733225)),
      simde_x_vloadq_u32(UINT32_C(2455707487), UINT32_C(1102429086),
                         UINT32_C(3614870952), UINT32_C(2124555621)),
      simde_x_vloadq_u32(UINT32_C( 320060797), UINT32_C(2510987942),
                         UINT32_C( 536614088), UINT32_C(4236598317)) },
    { simde_x_vloadq_u32(UINT32_C(1746629002), UINT32_C(3420579250),
                         UINT32_C(2351405457), UINT32_C(   5315732)),
      simde_x_vloadq_u32(UINT32_C(1374835167), UINT32_C(3729888048),
                         UINT32_C(1636607397), UINT32_C(1226229338)),
      simde_x_vloadq_u32(UINT32_C(1565036854), UINT32_C(4203890528),
                         UINT32_C(3352063861), UINT32_C(2169930760)) },
    { simde_x_vloadq_u32(UINT32_C( 549320667), UINT32_C(2322323920),
                         UINT32_C( 151754473), UINT32_C(4047667140)),
      simde_x_vloadq_u32(UINT32_C(1818929917), UINT32_C(3103405141),
                         UINT32_C(1952449955), UINT32_C(  82542915)),
      simde_x_vloadq_u32(UINT32_C(2265145711), UINT32_C( 321753616),
                         UINT32_C( 666084187), UINT32_C(4290065484)) },
    { simde_x_vloadq_u32(UINT32_C(2077124603), UINT32_C(2666703247),
                         UINT32_C(2161899434), UINT32_C( 575602451)),
      simde_x_vloadq_u32(UINT32_C( 251474702), UINT32_C(1393348005),
                         UINT32_C(3757489762), UINT32_C(4131780358)),
      simde_x_vloadq_u32(UINT32_C(1628418234), UINT32_C( 333630507),
                         UINT32_C(2841705236), UINT32_C( 135548786)) },
    { simde_x_vloadq_u32(UINT32_C(1086457379), UINT32_C(  14743562),
                         UINT32_C(1761520088), UINT32_C(2057869708)),
      simde_x_vloadq_u32(UINT32_C(2746909344), UINT32_C(1754166210),
                         UINT32_C(4038189003), UINT32_C(2974027701)),
      simde_x_vloadq_u32(UINT32_C(3201276896), UINT32_C(1601467796),
                         UINT32_C( 104584776), UINT32_C( 795067388)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_uint32x4_t r = simde_vmulq_u32(test_vec[i].a, test_vec[i].b);
    simde_neon_assert_uint32x4(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_vmulq_f32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_float32x4_t a;
    simde_float32x4_t b;
    simde_float32x4_t r;
  } test_vec[8] = {
    { simde_x_vloadq_f32(SIMDE_FLOAT32_C(  764.73), SIMDE_FLOAT32_C( -904.55),
                         SIMDE_FLOAT32_C(  692.13), SIMDE_FLOAT32_C( -510.35)),
      simde_x_vloadq_f32(SIMDE_FLOAT32_C(   32.75), SIMDE_FLOAT32_C(   51.72),
                         SIMDE_FLOAT32_C( -142.44), SIMDE_FLOAT32_C(  194.67)),
      simde_x_vloadq_f32(SIMDE_FLOAT32_C(25044.91), SIMDE_FLOAT32_C(-46783.33),
                         SIMDE_FLOAT32_C(-98587.00), SIMDE_FLOAT32_C(-99349.84)) },
    { simde_x_vloadq_f32(SIMDE_FLOAT32_C( -904.10), SIMDE_FLOAT32_C( -331.30),
                         SIMDE_FLOAT32_C(  798.10), SIMDE_FLOAT32_C( -717.75)),
      simde_x_vloadq_f32(SIMDE_FLOAT32_C(  673.61), SIMDE_FLOAT32_C(  902.28),
                         SIMDE_FLOAT32_C(   17.82), SIMDE_FLOAT32_C(  262.95)),
      simde_x_vloadq_f32(SIMDE_FLOAT32_C(-609010.75), SIMDE_FLOAT32_C(-298925.38),
                         SIMDE_FLOAT32_C(14222.14), SIMDE_FLOAT32_C(-188732.38)) },
    { simde_x_vloadq_f32(SIMDE_FLOAT32_C( -782.37), SIMDE_FLOAT32_C(  839.26),
                         SIMDE_FLOAT32_C(  988.92), SIMDE_FLOAT32_C(  194.85)),
      simde_x_vloadq_f32(SIMDE_FLOAT32_C( -438.71), SIMDE_FLOAT32_C(  397.59),
                         SIMDE_FLOAT32_C( -906.02), SIMDE_FLOAT32_C( -645.00)),
      simde_x_vloadq_f32(SIMDE_FLOAT32_C(343233.53), SIMDE_FLOAT32_C(333681.38),
                         SIMDE_FLOAT32_C(-895981.31), SIMDE_FLOAT32_C(-125678.26)) },
    { simde_x_vloadq_f32(SIMDE_FLOAT32_C(  514.53), SIMDE_FLOAT32_C(  516.76),
                         SIMDE_FLOAT32_C(  141.10), SIMDE_FLOAT32_C(   80.68)),
      simde_x_vloadq_f32(SIMDE_FLOAT32_C( -996.77), SIMDE_FLOAT32_C(  465.18),
                         SIMDE_FLOAT32_C(  267.79), SIMDE_FLOAT32_C(  -96.82)),
      simde_x_vloadq_f32(SIMDE_FLOAT32_C(-512868.09), SIMDE_FLOAT32_C(240386.42),
                         SIMDE_FLOAT32_C(37785.17), SIMDE_FLOAT32_C(-7811.44)) },
    { simde_x_vloadq_f32(SIMDE_FLOAT32_C(   17.49), SIMDE_FLOAT32_C( -972.94),
                         SIMDE_FLOAT32_C(   -9.96), SIMDE_FLOAT32_C(  557.04)),
      simde_x_vloadq_f32(SIMDE_FLOAT32_C(  658.33), SIMDE_FLOAT32_C(  152.31),
                         SIMDE_FLOAT32_C( -894.23), SIMDE_FLOAT32_C( -290.74)),
      simde_x_vloadq_f32(SIMDE_FLOAT32_C(11514.19), SIMDE_FLOAT32_C(-148188.48),
                         SIMDE_FLOAT32_C( 8906.53), SIMDE_FLOAT32_C(-161953.80)) },
    { simde_x_vloadq_f32(SIMDE_FLOAT32_C( -221.71), SIMDE_FLOAT32_C(  835.86),
                         SIMDE_FLOAT32_C(  400.30), SIMDE_FLOAT32_C( -158.20)),
      simde_x_vloadq_f32(SIMDE_FLOAT32_C(  216.50), SIMDE_FLOAT32_C(  439.51),
                         SIMDE_FLOAT32_C( -451.11), SIMDE_FLOAT32_C(   42.20)),
      simde_x_vloadq_f32(SIMDE_FLOAT32_C(-48000.21), SIMDE_FLOAT32_C(367368.84),
                         SIMDE_FLOAT32_C(-180579.33), SIMDE_FLOAT32_C(-6676.04)) },
    { simde_x_vloadq_f32(SIMDE_FLOAT32_C( -279.50), SIMDE_FLOAT32_C( -471.25),
                         SIMDE_FLOAT32_C(  976.16), SIMDE_FLOAT32_C( -178.14)),
      simde_x_vloadq_f32(SIMDE_FLOAT32_C(  -66.41), SIMDE_FLOAT32_C( -721.09),
                         SIMDE_FLOAT32_C(  642.38), SIMDE_FLOAT32_C(  930.30)),
      simde_x_vloadq_f32(SIMDE_FLOAT32_C(18561.60), SIMDE_FLOAT32_C(339813.69),
                         SIMDE_FLOAT32_C(627065.62), SIMDE_FLOAT32_C(-165723.64)) },
    { simde_x_vloadq_f32(SIMDE_FLOAT32_C( -593.59), SIMDE_FLOAT32_C(  407.91),
                         SIMDE_FLOAT32_C( -402.54), SIMDE_FLOAT32_C(  522.63)),
      simde_x_vloadq_f32(SIMDE_FLOAT32_C( -180.83), SIMDE_FLOAT32_C( -430.34),
                         SIMDE_FLOAT32_C( -204.65), SIMDE_FLOAT32_C( -888.67)),
      simde_x_vloadq_f32(SIMDE_FLOAT32_C(107338.88), SIMDE_FLOAT32_C(-175539.98),
                         SIMDE_FLOAT32_C(82379.81), SIMDE_FLOAT32_C(-464445.59)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_float32x4_t r = simde_vmulq_f32(test_vec[i].a, test_vec[i].b);
    simde_neon_assert_float32x4_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_vmulq_f64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_float64x2_t a;
    simde_float64x2_t b;
    simde_float64x2_t r;
  } test_vec[8] = {
    { simde_x_vloadq_f64(SIMDE_FLOAT64_C(  261.94), SIMDE_FLOAT64_C(  389.36)),
      simde_x_vloadq_f64(SIMDE_FLOAT64_C( -604.87), SIMDE_FLOAT64_C( -117.53)),
      simde_x_vloadq_f64(SIMDE_FLOAT64_C(-158439.65), SIMDE_FLOAT64_C(-45761.48)) },
    { simde_x_vloadq_f64(SIMDE_FLOAT64_C(  516.97), SIMDE_FLOAT64_C(  458.14)),
      simde_x_vloadq_f64(SIMDE_FLOAT64_C(  808.10), SIMDE_FLOAT64_C( -730.44)),
      simde_x_vloadq_f64(SIMDE_FLOAT64_C(417763.46), SIMDE_FLOAT64_C(-334643.78)) },
    { simde_x_vloadq_f64(SIMDE_FLOAT64_C(  956.22), SIMDE_FLOAT64_C(   84.60)),
      simde_x_vloadq_f64(SIMDE_FLOAT64_C(  683.61), SIMDE_FLOAT64_C( -964.54)),
      simde_x_vloadq_f64(SIMDE_FLOAT64_C(653681.55), SIMDE_FLOAT64_C(-81600.08)) },
    { simde_x_vloadq_f64(SIMDE_FLOAT64_C( -723.12), SIMDE_FLOAT64_C(  136.75)),
      simde_x_vloadq_f64(SIMDE_FLOAT64_C( -859.96), SIMDE_FLOAT64_C(  319.65)),
      simde_x_vloadq_f64(SIMDE_FLOAT64_C(621854.28), SIMDE_FLOAT64_C(43712.14)) },
    { simde_x_vloadq_f64(SIMDE_FLOAT64_C( -937.43), SIMDE_FLOAT64_C( -648.19)),
      simde_x_vloadq_f64(SIMDE_FLOAT64_C(  344.36), SIMDE_FLOAT64_C( -506.13)),
      simde_x_vloadq_f64(SIMDE_FLOAT64_C(-322813.39), SIMDE_FLOAT64_C(328068.40)) },
    { simde_x_vloadq_f64(SIMDE_FLOAT64_C( -967.06), SIMDE_FLOAT64_C( -492.64)),
      simde_x_vloadq_f64(SIMDE_FLOAT64_C( -564.55), SIMDE_FLOAT64_C(  904.04)),
      simde_x_vloadq_f64(SIMDE_FLOAT64_C(545953.72), SIMDE_FLOAT64_C(-445366.27)) },
    { simde_x_vloadq_f64(SIMDE_FLOAT64_C(   86.34), SIMDE_FLOAT64_C(  355.85)),
      simde_x_vloadq_f64(SIMDE_FLOAT64_C( -892.48), SIMDE_FLOAT64_C( -794.20)),
      simde_x_vloadq_f64(SIMDE_FLOAT64_C(-77056.72), SIMDE_FLOAT64_C(-282616.07)) },
    { simde_x_vloadq_f64(SIMDE_FLOAT64_C(  554.46), SIMDE_FLOAT64_C(  210.82)),
      simde_x_vloadq_f64(SIMDE_FLOAT64_C(   71.90), SIMDE_FLOAT64_C( -553.26)),
      simde_x_vloadq_f64(SIMDE_FLOAT64_C(39865.67), SIMDE_FLOAT64_C(-116638.27)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_float64x2_t r = simde_vmulq_f64(test_vec[i].a, test_vec[i].b);
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
  // SIMDE_TESTS_NEON_DEFINE_TEST(s64),
  SIMDE_TESTS_NEON_DEFINE_TEST(u8),
  SIMDE_TESTS_NEON_DEFINE_TEST(u16),
  SIMDE_TESTS_NEON_DEFINE_TEST(u32),
  // SIMDE_TESTS_NEON_DEFINE_TEST(u64),
  SIMDE_TESTS_NEON_DEFINE_TEST(f32),
  SIMDE_TESTS_NEON_DEFINE_TEST(f64),
  SIMDE_TESTS_NEON_DEFINE_TEST_FULL(q, s8),
  SIMDE_TESTS_NEON_DEFINE_TEST_FULL(q, s16),
  SIMDE_TESTS_NEON_DEFINE_TEST_FULL(q, s32),
  // SIMDE_TESTS_NEON_DEFINE_TEST_FULL(q, s64),
  SIMDE_TESTS_NEON_DEFINE_TEST_FULL(q, u8),
  SIMDE_TESTS_NEON_DEFINE_TEST_FULL(q, u16),
  SIMDE_TESTS_NEON_DEFINE_TEST_FULL(q, u32),
  // SIMDE_TESTS_NEON_DEFINE_TEST_FULL(q, u64),
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
