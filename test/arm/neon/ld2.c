#define SIMDE_TEST_ARM_NEON_INSN ld2

#include "test-neon.h"
#include "../../../simde/arm/neon/ld2.h"

#if !defined(SIMDE_BUG_INTEL_857088)

static int
test_simde_vld2_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t a[8];
    uint8_t b[8];
    uint8_t r[2][8];
  } test_vec[] = {

    { { UINT8_C(144), UINT8_C(234), UINT8_C(130), UINT8_C(145), UINT8_C( 26), UINT8_C(241), UINT8_C( 35), UINT8_C( 43) },
      { UINT8_C( 76), UINT8_C(223), UINT8_C(152), UINT8_C(128), UINT8_C(203), UINT8_C( 66), UINT8_C( 17), UINT8_C(218) },
        { { UINT8_C(144), UINT8_C(130), UINT8_C( 26), UINT8_C( 35), UINT8_C( 76), UINT8_C(152), UINT8_C(203), UINT8_C( 17) },
          { UINT8_C(234), UINT8_C(145), UINT8_C(241), UINT8_C( 43), UINT8_C(223), UINT8_C(128), UINT8_C( 66), UINT8_C(218) } },
    },
    { { UINT8_C(196), UINT8_C( 14), UINT8_C( 36), UINT8_C( 59), UINT8_C(230), UINT8_C(253), UINT8_C(216), UINT8_C( 14) },
      { UINT8_C( 31), UINT8_C( 73), UINT8_C( 48), UINT8_C( 55), UINT8_C(200), UINT8_C( 71), UINT8_C(176), UINT8_C( 88) },
        { { UINT8_C(196), UINT8_C( 36), UINT8_C(230), UINT8_C(216), UINT8_C( 31), UINT8_C( 48), UINT8_C(200), UINT8_C(176) },
          { UINT8_C( 14), UINT8_C( 59), UINT8_C(253), UINT8_C( 14), UINT8_C( 73), UINT8_C( 55), UINT8_C( 71), UINT8_C( 88) } },
    },
    { { UINT8_C( 49), UINT8_C( 50), UINT8_C(233), UINT8_C( 76), UINT8_C( 35), UINT8_C( 13), UINT8_C(119), UINT8_C(111) },
      { UINT8_C(236), UINT8_C( 15), UINT8_C(240), UINT8_C(184), UINT8_C( 81), UINT8_C(  1), UINT8_C(146), UINT8_C( 22) },
        { { UINT8_C( 49), UINT8_C(233), UINT8_C( 35), UINT8_C(119), UINT8_C(236), UINT8_C(240), UINT8_C( 81), UINT8_C(146) },
          { UINT8_C( 50), UINT8_C( 76), UINT8_C( 13), UINT8_C(111), UINT8_C( 15), UINT8_C(184), UINT8_C(  1), UINT8_C( 22) } },
    },
    { { UINT8_C( 15), UINT8_C(182), UINT8_C( 81), UINT8_C(245), UINT8_C(179), UINT8_C( 41), UINT8_C(  4), UINT8_C(211) },
      { UINT8_C(115), UINT8_C( 52), UINT8_C( 10), UINT8_C( 59), UINT8_C(123), UINT8_C(187), UINT8_C(147), UINT8_C(173) },
        { { UINT8_C( 15), UINT8_C( 81), UINT8_C(179), UINT8_C(  4), UINT8_C(115), UINT8_C( 10), UINT8_C(123), UINT8_C(147) },
          { UINT8_C(182), UINT8_C(245), UINT8_C( 41), UINT8_C(211), UINT8_C( 52), UINT8_C( 59), UINT8_C(187), UINT8_C(173) } },
    },
    { { UINT8_C(237), UINT8_C(125), UINT8_C(249), UINT8_C( 17), UINT8_C(138), UINT8_C(112), UINT8_C(128), UINT8_C(118) },
      { UINT8_C(127), UINT8_C(112), UINT8_C( 46), UINT8_C(208), UINT8_C(113), UINT8_C(193), UINT8_C(230), UINT8_C(129) },
        { { UINT8_C(237), UINT8_C(249), UINT8_C(138), UINT8_C(128), UINT8_C(127), UINT8_C( 46), UINT8_C(113), UINT8_C(230) },
          { UINT8_C(125), UINT8_C( 17), UINT8_C(112), UINT8_C(118), UINT8_C(112), UINT8_C(208), UINT8_C(193), UINT8_C(129) } },
    },
    { { UINT8_C(119), UINT8_C( 56), UINT8_C(118), UINT8_C( 43), UINT8_C( 97), UINT8_C(122), UINT8_C(254), UINT8_C(212) },
      { UINT8_C(175), UINT8_C(  8), UINT8_C( 15), UINT8_C( 42), UINT8_C(195), UINT8_C(163), UINT8_C(215), UINT8_C(177) },
        { { UINT8_C(119), UINT8_C(118), UINT8_C( 97), UINT8_C(254), UINT8_C(175), UINT8_C( 15), UINT8_C(195), UINT8_C(215) },
          { UINT8_C( 56), UINT8_C( 43), UINT8_C(122), UINT8_C(212), UINT8_C(  8), UINT8_C( 42), UINT8_C(163), UINT8_C(177) } },
    },
    { { UINT8_C( 32), UINT8_C(208), UINT8_C(194), UINT8_C(170), UINT8_C( 64), UINT8_C( 66), UINT8_C( 32), UINT8_C(191) },
      { UINT8_C(179), UINT8_C( 79), UINT8_C(144), UINT8_C( 36), UINT8_C( 16), UINT8_C(118), UINT8_C(165), UINT8_C(135) },
        { { UINT8_C( 32), UINT8_C(194), UINT8_C( 64), UINT8_C( 32), UINT8_C(179), UINT8_C(144), UINT8_C( 16), UINT8_C(165) },
          { UINT8_C(208), UINT8_C(170), UINT8_C( 66), UINT8_C(191), UINT8_C( 79), UINT8_C( 36), UINT8_C(118), UINT8_C(135) } },
    },
    { { UINT8_C(174), UINT8_C( 28), UINT8_C(178), UINT8_C( 16), UINT8_C(150), UINT8_C(176), UINT8_C(228), UINT8_C( 69) },
      { UINT8_C(185), UINT8_C(244), UINT8_C(112), UINT8_C(124), UINT8_C(151), UINT8_C( 71), UINT8_C( 45), UINT8_C(183) },
        { { UINT8_C(174), UINT8_C(178), UINT8_C(150), UINT8_C(228), UINT8_C(185), UINT8_C(112), UINT8_C(151), UINT8_C( 45) },
          { UINT8_C( 28), UINT8_C( 16), UINT8_C(176), UINT8_C( 69), UINT8_C(244), UINT8_C(124), UINT8_C( 71), UINT8_C(183) } },
    },


  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x8x2_t r = simde_vld2_u8(test_vec[i].a);

    simde_uint8x8x2_t expected = {
        {simde_vld1_u8(test_vec[i].r[0]), simde_vld1_u8(test_vec[i].r[1])}};

    simde_test_arm_neon_assert_equal_u8x8(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_u8x8(r.val[1], expected.val[1]);
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8x8_t a = simde_test_arm_neon_random_u8x8();
    simde_uint8x8_t b = simde_test_arm_neon_random_u8x8();
    simde_uint8x8x2_t c = {{a, b}};

    simde_test_arm_neon_write_u8x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);

    uint8_t buf[16];
    simde_memcpy(buf, c.val, sizeof(buf));
    simde_uint8x8x2_t r = simde_vld2_u8(buf);

    simde_test_arm_neon_write_u8x8x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld2_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[4];
    uint16_t b[4];
    uint16_t r[2][4];
  } test_vec[] = {
    { { UINT16_C(42664), UINT16_C(53887), UINT16_C(10958), UINT16_C(61123) },
      { UINT16_C( 7800), UINT16_C(15834), UINT16_C(36089), UINT16_C(22799) },
        { { UINT16_C(42664), UINT16_C(10958), UINT16_C( 7800), UINT16_C(36089) },
          { UINT16_C(53887), UINT16_C(61123), UINT16_C(15834), UINT16_C(22799) } },
    },
    { { UINT16_C(62795), UINT16_C(22857), UINT16_C(11632), UINT16_C(39934) },
      { UINT16_C(56742), UINT16_C(64150), UINT16_C( 8095), UINT16_C(18414) },
        { { UINT16_C(62795), UINT16_C(11632), UINT16_C(56742), UINT16_C( 8095) },
          { UINT16_C(22857), UINT16_C(39934), UINT16_C(64150), UINT16_C(18414) } },
    },
    { { UINT16_C(28101), UINT16_C(37914), UINT16_C(56727), UINT16_C( 3970) },
      { UINT16_C(23803), UINT16_C(62797), UINT16_C(23784), UINT16_C(13390) },
        { { UINT16_C(28101), UINT16_C(56727), UINT16_C(23803), UINT16_C(23784) },
          { UINT16_C(37914), UINT16_C( 3970), UINT16_C(62797), UINT16_C(13390) } },
    },
    { { UINT16_C(38737), UINT16_C(49549), UINT16_C(36037), UINT16_C(27485) },
      { UINT16_C(62313), UINT16_C( 2149), UINT16_C(21522), UINT16_C(55375) },
        { { UINT16_C(38737), UINT16_C(36037), UINT16_C(62313), UINT16_C(21522) },
          { UINT16_C(49549), UINT16_C(27485), UINT16_C( 2149), UINT16_C(55375) } },
    },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4x2_t r = simde_vld2_u16(test_vec[i].a);

    simde_uint16x4x2_t expected = {
        {simde_vld1_u16(test_vec[i].r[0]), simde_vld1_u16(test_vec[i].r[1])}};

    simde_test_arm_neon_assert_equal_u16x4(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_u16x4(r.val[1], expected.val[1]);
  }

  return 0;
#else
  for (int i = 0 ; i < 4 ; i++) {
    simde_uint16x4_t a = simde_test_arm_neon_random_u16x4();
    simde_uint16x4_t b = simde_test_arm_neon_random_u16x4();
    simde_uint16x4x2_t c = {{a, b}};

    simde_test_arm_neon_write_u16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);

    uint16_t buf[8];
    simde_memcpy(buf, c.val, sizeof(buf));
    simde_uint16x4x2_t r = simde_vld2_u16(buf);

    simde_test_arm_neon_write_u16x4x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld2_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[2];
    uint32_t b[2];
    uint32_t r[2][2];
  } test_vec[] = {
    { { UINT32_C(1500277185), UINT32_C(1114172999) },
      { UINT32_C( 859288906), UINT32_C(1650951697) },
        { { UINT32_C(1500277185), UINT32_C( 859288906) },
          { UINT32_C(1114172999), UINT32_C(1650951697) } },
    },
    { { UINT32_C(3794072605), UINT32_C(3914236288) },
      { UINT32_C(2280764276), UINT32_C(3378462983) },
        { { UINT32_C(3794072605), UINT32_C(2280764276) },
          { UINT32_C(3914236288), UINT32_C(3378462983) } },
    },
    { { UINT32_C(4045589418), UINT32_C(  53775033) },
      { UINT32_C(1362520896), UINT32_C( 263495153) },
        { { UINT32_C(4045589418), UINT32_C(1362520896) },
          { UINT32_C(  53775033), UINT32_C( 263495153) } },
    },
    { { UINT32_C( 317839506), UINT32_C(3455860569) },
      { UINT32_C(4199869939), UINT32_C(3653481262) },
        { { UINT32_C( 317839506), UINT32_C(4199869939) },
          { UINT32_C(3455860569), UINT32_C(3653481262) } },
    },
    { { UINT32_C( 936043902), UINT32_C(2956721776) },
      { UINT32_C(1526821226), UINT32_C(2708124943) },
        { { UINT32_C( 936043902), UINT32_C(1526821226) },
          { UINT32_C(2956721776), UINT32_C(2708124943) } },
    },
    { { UINT32_C(3870514317), UINT32_C(2394206107) },
      { UINT32_C(3414755485), UINT32_C( 983846076) },
        { { UINT32_C(3870514317), UINT32_C(3414755485) },
          { UINT32_C(2394206107), UINT32_C( 983846076) } },
    },
    { { UINT32_C(2725408562), UINT32_C(3612519789) },
      { UINT32_C( 758338334), UINT32_C(2530123017) },
        { { UINT32_C(2725408562), UINT32_C( 758338334) },
          { UINT32_C(3612519789), UINT32_C(2530123017) } },
    },
    { { UINT32_C(2508030713), UINT32_C(3458412849) },
      { UINT32_C(4120554553), UINT32_C( 724582137) },
        { { UINT32_C(2508030713), UINT32_C(4120554553) },
          { UINT32_C(3458412849), UINT32_C( 724582137) } },
    },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2x2_t r = simde_vld2_u32(test_vec[i].a);

    simde_uint32x2x2_t expected = {
        {simde_vld1_u32(test_vec[i].r[0]), simde_vld1_u32(test_vec[i].r[1])}};

    simde_test_arm_neon_assert_equal_u32x2(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_u32x2(r.val[1], expected.val[1]);
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x2_t a = simde_test_arm_neon_random_u32x2();
    simde_uint32x2_t b = simde_test_arm_neon_random_u32x2();
    simde_uint32x2x2_t c = {{a, b}};

    simde_test_arm_neon_write_u32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);

    uint32_t buf[4];
    simde_memcpy(buf, c.val, sizeof(buf));
    simde_uint32x2x2_t r = simde_vld2_u32(buf);

    simde_test_arm_neon_write_u32x2x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld2q_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t a[16];
    uint8_t b[16];
    uint8_t r[2][16];
  } test_vec[] = {
    { { UINT8_C( 56), UINT8_C(119), UINT8_C(167), UINT8_C( 99), UINT8_C(221), UINT8_C(126), UINT8_C(139), UINT8_C( 94),
        UINT8_C(  0), UINT8_C(203), UINT8_C(216), UINT8_C( 77), UINT8_C( 79), UINT8_C(152), UINT8_C(  2), UINT8_C(187) },
      { UINT8_C(173), UINT8_C(251), UINT8_C( 63), UINT8_C( 57), UINT8_C(133), UINT8_C( 35), UINT8_C(243), UINT8_C(166),
        UINT8_C( 51), UINT8_C(149), UINT8_C(128), UINT8_C( 99), UINT8_C(176), UINT8_C(195), UINT8_C( 30), UINT8_C(232) },
        { { UINT8_C( 56), UINT8_C(167), UINT8_C(221), UINT8_C(139), UINT8_C(  0), UINT8_C(216), UINT8_C( 79), UINT8_C(  2),
            UINT8_C(173), UINT8_C( 63), UINT8_C(133), UINT8_C(243), UINT8_C( 51), UINT8_C(128), UINT8_C(176), UINT8_C( 30) },
          { UINT8_C(119), UINT8_C( 99), UINT8_C(126), UINT8_C( 94), UINT8_C(203), UINT8_C( 77), UINT8_C(152), UINT8_C(187),
            UINT8_C(251), UINT8_C( 57), UINT8_C( 35), UINT8_C(166), UINT8_C(149), UINT8_C( 99), UINT8_C(195), UINT8_C(232) } },
    },
    { { UINT8_C( 58), UINT8_C(198), UINT8_C( 75), UINT8_C( 24), UINT8_C( 68), UINT8_C(214), UINT8_C(118), UINT8_C( 68),
        UINT8_C(161), UINT8_C( 78), UINT8_C(145), UINT8_C(240), UINT8_C(231), UINT8_C(148), UINT8_C(172), UINT8_C(148) },
      { UINT8_C(143), UINT8_C(235), UINT8_C(205), UINT8_C( 20), UINT8_C( 14), UINT8_C(192), UINT8_C(186), UINT8_C( 65),
        UINT8_C( 85), UINT8_C( 58), UINT8_C(164), UINT8_C(  5), UINT8_C(254), UINT8_C(195), UINT8_C(237), UINT8_C( 56) },
        { { UINT8_C( 58), UINT8_C( 75), UINT8_C( 68), UINT8_C(118), UINT8_C(161), UINT8_C(145), UINT8_C(231), UINT8_C(172),
            UINT8_C(143), UINT8_C(205), UINT8_C( 14), UINT8_C(186), UINT8_C( 85), UINT8_C(164), UINT8_C(254), UINT8_C(237) },
          { UINT8_C(198), UINT8_C( 24), UINT8_C(214), UINT8_C( 68), UINT8_C( 78), UINT8_C(240), UINT8_C(148), UINT8_C(148),
            UINT8_C(235), UINT8_C( 20), UINT8_C(192), UINT8_C( 65), UINT8_C( 58), UINT8_C(  5), UINT8_C(195), UINT8_C( 56) } },
    },
    { { UINT8_C(137), UINT8_C( 56), UINT8_C( 80), UINT8_C(205), UINT8_C( 15), UINT8_C(199), UINT8_C( 18), UINT8_C(176),
        UINT8_C( 21), UINT8_C(163), UINT8_C(161), UINT8_C(252), UINT8_C( 55), UINT8_C( 77), UINT8_C(144), UINT8_C(198) },
      { UINT8_C( 56), UINT8_C( 93), UINT8_C(219), UINT8_C( 70), UINT8_C( 29), UINT8_C(149), UINT8_C(135), UINT8_C(115),
        UINT8_C(208), UINT8_C( 43), UINT8_C(120), UINT8_C(206), UINT8_C(238), UINT8_C(102), UINT8_C(  6), UINT8_C(119) },
        { { UINT8_C(137), UINT8_C( 80), UINT8_C( 15), UINT8_C( 18), UINT8_C( 21), UINT8_C(161), UINT8_C( 55), UINT8_C(144),
            UINT8_C( 56), UINT8_C(219), UINT8_C( 29), UINT8_C(135), UINT8_C(208), UINT8_C(120), UINT8_C(238), UINT8_C(  6) },
          { UINT8_C( 56), UINT8_C(205), UINT8_C(199), UINT8_C(176), UINT8_C(163), UINT8_C(252), UINT8_C( 77), UINT8_C(198),
            UINT8_C( 93), UINT8_C( 70), UINT8_C(149), UINT8_C(115), UINT8_C( 43), UINT8_C(206), UINT8_C(102), UINT8_C(119) } },
    },
    { { UINT8_C(158), UINT8_C( 87), UINT8_C( 69), UINT8_C(173), UINT8_C( 30), UINT8_C( 87), UINT8_C( 94), UINT8_C( 51),
        UINT8_C(250),    UINT8_MAX, UINT8_C( 48), UINT8_C( 50), UINT8_C( 76), UINT8_C(192), UINT8_C(248), UINT8_C(132) },
      { UINT8_C( 30), UINT8_C(211), UINT8_C(202), UINT8_C( 59), UINT8_C(105), UINT8_C( 81), UINT8_C(174), UINT8_C( 57),
        UINT8_C(124), UINT8_C( 39), UINT8_C(  7), UINT8_C(107), UINT8_C(141), UINT8_C( 13), UINT8_C(226), UINT8_C( 43) },
        { { UINT8_C(158), UINT8_C( 69), UINT8_C( 30), UINT8_C( 94), UINT8_C(250), UINT8_C( 48), UINT8_C( 76), UINT8_C(248),
            UINT8_C( 30), UINT8_C(202), UINT8_C(105), UINT8_C(174), UINT8_C(124), UINT8_C(  7), UINT8_C(141), UINT8_C(226) },
          { UINT8_C( 87), UINT8_C(173), UINT8_C( 87), UINT8_C( 51),    UINT8_MAX, UINT8_C( 50), UINT8_C(192), UINT8_C(132),
            UINT8_C(211), UINT8_C( 59), UINT8_C( 81), UINT8_C( 57), UINT8_C( 39), UINT8_C(107), UINT8_C( 13), UINT8_C( 43) } },
    },
    { { UINT8_C(100), UINT8_C( 39), UINT8_C(217), UINT8_C(130), UINT8_C(126), UINT8_C( 55), UINT8_C(182), UINT8_C(121),
        UINT8_C( 54), UINT8_C(230), UINT8_C(171), UINT8_C(130), UINT8_C(166), UINT8_C(163), UINT8_C(  6), UINT8_C(196) },
      { UINT8_C(119), UINT8_C(208), UINT8_C(  0), UINT8_C(224), UINT8_C( 33), UINT8_C(174), UINT8_C( 25), UINT8_C(157),
        UINT8_C(213), UINT8_C( 32), UINT8_C(  8), UINT8_C( 98), UINT8_C( 45), UINT8_C(235), UINT8_C(142), UINT8_C(146) },
        { { UINT8_C(100), UINT8_C(217), UINT8_C(126), UINT8_C(182), UINT8_C( 54), UINT8_C(171), UINT8_C(166), UINT8_C(  6),
            UINT8_C(119), UINT8_C(  0), UINT8_C( 33), UINT8_C( 25), UINT8_C(213), UINT8_C(  8), UINT8_C( 45), UINT8_C(142) },
          { UINT8_C( 39), UINT8_C(130), UINT8_C( 55), UINT8_C(121), UINT8_C(230), UINT8_C(130), UINT8_C(163), UINT8_C(196),
            UINT8_C(208), UINT8_C(224), UINT8_C(174), UINT8_C(157), UINT8_C( 32), UINT8_C( 98), UINT8_C(235), UINT8_C(146) } },
    },
    { { UINT8_C( 18), UINT8_C(103), UINT8_C( 20), UINT8_C(145), UINT8_C(158), UINT8_C(202), UINT8_C( 10), UINT8_C(212),
        UINT8_C(176), UINT8_C(181), UINT8_C( 86), UINT8_C( 87), UINT8_C( 88), UINT8_C( 92), UINT8_C( 27), UINT8_C(207) },
      { UINT8_C( 44), UINT8_C( 27), UINT8_C(175), UINT8_C( 77), UINT8_C(202), UINT8_C(200), UINT8_C(234), UINT8_C(159),
        UINT8_C(232), UINT8_C(243), UINT8_C(  2), UINT8_C( 22), UINT8_C(222), UINT8_C(144), UINT8_C(168), UINT8_C(240) },
        { { UINT8_C( 18), UINT8_C( 20), UINT8_C(158), UINT8_C( 10), UINT8_C(176), UINT8_C( 86), UINT8_C( 88), UINT8_C( 27),
            UINT8_C( 44), UINT8_C(175), UINT8_C(202), UINT8_C(234), UINT8_C(232), UINT8_C(  2), UINT8_C(222), UINT8_C(168) },
          { UINT8_C(103), UINT8_C(145), UINT8_C(202), UINT8_C(212), UINT8_C(181), UINT8_C( 87), UINT8_C( 92), UINT8_C(207),
            UINT8_C( 27), UINT8_C( 77), UINT8_C(200), UINT8_C(159), UINT8_C(243), UINT8_C( 22), UINT8_C(144), UINT8_C(240) } },
    },
    { { UINT8_C(247), UINT8_C(188), UINT8_C(129), UINT8_C(149), UINT8_C(135), UINT8_C(139), UINT8_C(105), UINT8_C( 55),
        UINT8_C( 64), UINT8_C(191), UINT8_C(142), UINT8_C(153), UINT8_C( 27), UINT8_C(170), UINT8_C(104), UINT8_C( 71) },
      { UINT8_C(197), UINT8_C( 24), UINT8_C(148), UINT8_C(143), UINT8_C(224), UINT8_C(126), UINT8_C( 47), UINT8_C(201),
        UINT8_C(113), UINT8_C( 49), UINT8_C(223), UINT8_C( 79), UINT8_C(193), UINT8_C(135), UINT8_C( 64), UINT8_C(184) },
        { { UINT8_C(247), UINT8_C(129), UINT8_C(135), UINT8_C(105), UINT8_C( 64), UINT8_C(142), UINT8_C( 27), UINT8_C(104),
            UINT8_C(197), UINT8_C(148), UINT8_C(224), UINT8_C( 47), UINT8_C(113), UINT8_C(223), UINT8_C(193), UINT8_C( 64) },
          { UINT8_C(188), UINT8_C(149), UINT8_C(139), UINT8_C( 55), UINT8_C(191), UINT8_C(153), UINT8_C(170), UINT8_C( 71),
            UINT8_C( 24), UINT8_C(143), UINT8_C(126), UINT8_C(201), UINT8_C( 49), UINT8_C( 79), UINT8_C(135), UINT8_C(184) } },
    },
    { { UINT8_C( 67), UINT8_C(193), UINT8_C( 77), UINT8_C(202), UINT8_C( 77), UINT8_C(182), UINT8_C(  2), UINT8_C(141),
        UINT8_C(117), UINT8_C(144), UINT8_C( 38), UINT8_C(144), UINT8_C( 58), UINT8_C(143), UINT8_C(215), UINT8_C(  0) },
      { UINT8_C(167), UINT8_C(107), UINT8_C(143), UINT8_C(135), UINT8_C(233), UINT8_C(190), UINT8_C( 80), UINT8_C( 91),
        UINT8_C(239), UINT8_C( 47), UINT8_C(170), UINT8_C(176), UINT8_C(182), UINT8_C(234), UINT8_C(104), UINT8_C(250) },
        { { UINT8_C( 67), UINT8_C( 77), UINT8_C( 77), UINT8_C(  2), UINT8_C(117), UINT8_C( 38), UINT8_C( 58), UINT8_C(215),
            UINT8_C(167), UINT8_C(143), UINT8_C(233), UINT8_C( 80), UINT8_C(239), UINT8_C(170), UINT8_C(182), UINT8_C(104) },
          { UINT8_C(193), UINT8_C(202), UINT8_C(182), UINT8_C(141), UINT8_C(144), UINT8_C(144), UINT8_C(143), UINT8_C(  0),
            UINT8_C(107), UINT8_C(135), UINT8_C(190), UINT8_C( 91), UINT8_C( 47), UINT8_C(176), UINT8_C(234), UINT8_C(250) } },
    },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x16x2_t r = simde_vld2q_u8(test_vec[i].a);

    simde_uint8x16x2_t expected = {
        {simde_vld1q_u8(test_vec[i].r[0]), simde_vld1q_u8(test_vec[i].r[1])}};

    simde_test_arm_neon_assert_equal_u8x16(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_u8x16(r.val[1], expected.val[1]);
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8x16_t a = simde_test_arm_neon_random_u8x16();
    simde_uint8x16_t b = simde_test_arm_neon_random_u8x16();
    simde_uint8x16x2_t c = {{a, b}};

    simde_test_arm_neon_write_u8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);

    uint8_t buf[32];
    simde_memcpy(buf, c.val, sizeof(buf));
    simde_uint8x16x2_t r = simde_vld2q_u8(buf);

    simde_test_arm_neon_write_u8x16x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld2q_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[8];
    uint16_t b[8];
    uint16_t r[2][8];
  } test_vec[] = {
    { { UINT16_C( 5263), UINT16_C(46704), UINT16_C(17324), UINT16_C(  435), UINT16_C(22826), UINT16_C(35226), UINT16_C( 4289), UINT16_C(14289) },
      { UINT16_C(15842), UINT16_C(32624), UINT16_C( 9166), UINT16_C(50530), UINT16_C(15251), UINT16_C(37458), UINT16_C(64003), UINT16_C(37377) },
        { { UINT16_C( 5263), UINT16_C(17324), UINT16_C(22826), UINT16_C( 4289), UINT16_C(15842), UINT16_C( 9166), UINT16_C(15251), UINT16_C(64003) },
          { UINT16_C(46704), UINT16_C(  435), UINT16_C(35226), UINT16_C(14289), UINT16_C(32624), UINT16_C(50530), UINT16_C(37458), UINT16_C(37377) } },
    },
    { { UINT16_C(28943), UINT16_C(47944), UINT16_C(64436), UINT16_C(57020), UINT16_C(22100), UINT16_C( 5480), UINT16_C(14695), UINT16_C(18765) },
      { UINT16_C(48502), UINT16_C(17865), UINT16_C(11232), UINT16_C(29450), UINT16_C(23654), UINT16_C(26886), UINT16_C( 1879), UINT16_C(26363) },
        { { UINT16_C(28943), UINT16_C(64436), UINT16_C(22100), UINT16_C(14695), UINT16_C(48502), UINT16_C(11232), UINT16_C(23654), UINT16_C( 1879) },
          { UINT16_C(47944), UINT16_C(57020), UINT16_C( 5480), UINT16_C(18765), UINT16_C(17865), UINT16_C(29450), UINT16_C(26886), UINT16_C(26363) } },
    },
    { { UINT16_C(17528), UINT16_C(11297), UINT16_C(56639), UINT16_C(37899), UINT16_C(29491), UINT16_C(39593), UINT16_C(63148), UINT16_C( 8932) },
      { UINT16_C(44468), UINT16_C(37991), UINT16_C(29144), UINT16_C(16136), UINT16_C( 3790), UINT16_C( 9640), UINT16_C(42005), UINT16_C(36235) },
        { { UINT16_C(17528), UINT16_C(56639), UINT16_C(29491), UINT16_C(63148), UINT16_C(44468), UINT16_C(29144), UINT16_C( 3790), UINT16_C(42005) },
          { UINT16_C(11297), UINT16_C(37899), UINT16_C(39593), UINT16_C( 8932), UINT16_C(37991), UINT16_C(16136), UINT16_C( 9640), UINT16_C(36235) } },
    },
    { { UINT16_C(44264), UINT16_C(10169), UINT16_C(50313), UINT16_C(48315), UINT16_C(25911), UINT16_C(58199), UINT16_C(15195), UINT16_C( 3846) },
      { UINT16_C(28136), UINT16_C(49316), UINT16_C(44255), UINT16_C(44543), UINT16_C(43194), UINT16_C(53202), UINT16_C(23884), UINT16_C(13404) },
        { { UINT16_C(44264), UINT16_C(50313), UINT16_C(25911), UINT16_C(15195), UINT16_C(28136), UINT16_C(44255), UINT16_C(43194), UINT16_C(23884) },
          { UINT16_C(10169), UINT16_C(48315), UINT16_C(58199), UINT16_C( 3846), UINT16_C(49316), UINT16_C(44543), UINT16_C(53202), UINT16_C(13404) } },
    },
    { { UINT16_C( 5385), UINT16_C(37467), UINT16_C( 6106), UINT16_C( 4430), UINT16_C(42364), UINT16_C(55285), UINT16_C(64480), UINT16_C(51431) },
      { UINT16_C(35688), UINT16_C(18313), UINT16_C(34871), UINT16_C(61940), UINT16_C(50736), UINT16_C(31936), UINT16_C( 7203), UINT16_C(11440) },
        { { UINT16_C( 5385), UINT16_C( 6106), UINT16_C(42364), UINT16_C(64480), UINT16_C(35688), UINT16_C(34871), UINT16_C(50736), UINT16_C( 7203) },
          { UINT16_C(37467), UINT16_C( 4430), UINT16_C(55285), UINT16_C(51431), UINT16_C(18313), UINT16_C(61940), UINT16_C(31936), UINT16_C(11440) } },
    },
    { { UINT16_C( 3121), UINT16_C( 3006), UINT16_C( 3363), UINT16_C(40733), UINT16_C( 4786), UINT16_C(37750), UINT16_C(23821), UINT16_C(30043) },
      { UINT16_C(58600), UINT16_C( 8125), UINT16_C(45421), UINT16_C(40208), UINT16_C(53368), UINT16_C(39706), UINT16_C(51948), UINT16_C( 7880) },
        { { UINT16_C( 3121), UINT16_C( 3363), UINT16_C( 4786), UINT16_C(23821), UINT16_C(58600), UINT16_C(45421), UINT16_C(53368), UINT16_C(51948) },
          { UINT16_C( 3006), UINT16_C(40733), UINT16_C(37750), UINT16_C(30043), UINT16_C( 8125), UINT16_C(40208), UINT16_C(39706), UINT16_C( 7880) } },
    },
    { { UINT16_C(34518), UINT16_C(63785), UINT16_C(18067), UINT16_C(18072), UINT16_C( 3928), UINT16_C(26073), UINT16_C(13420), UINT16_C(21979) },
      { UINT16_C(38937), UINT16_C(34420), UINT16_C(34121), UINT16_C(49443), UINT16_C(15701), UINT16_C(16989), UINT16_C( 9480), UINT16_C(56928) },
        { { UINT16_C(34518), UINT16_C(18067), UINT16_C( 3928), UINT16_C(13420), UINT16_C(38937), UINT16_C(34121), UINT16_C(15701), UINT16_C( 9480) },
          { UINT16_C(63785), UINT16_C(18072), UINT16_C(26073), UINT16_C(21979), UINT16_C(34420), UINT16_C(49443), UINT16_C(16989), UINT16_C(56928) } },
    },
    { { UINT16_C(35243), UINT16_C(16344), UINT16_C(28880), UINT16_C(10373), UINT16_C(24191), UINT16_C(60558), UINT16_C(27026), UINT16_C(43841) },
      { UINT16_C(46337), UINT16_C(18993), UINT16_C(21818), UINT16_C(36876), UINT16_C(27026), UINT16_C(39634), UINT16_C(12942), UINT16_C(14713) },
        { { UINT16_C(35243), UINT16_C(28880), UINT16_C(24191), UINT16_C(27026), UINT16_C(46337), UINT16_C(21818), UINT16_C(27026), UINT16_C(12942) },
          { UINT16_C(16344), UINT16_C(10373), UINT16_C(60558), UINT16_C(43841), UINT16_C(18993), UINT16_C(36876), UINT16_C(39634), UINT16_C(14713) } },
    },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8x2_t r = simde_vld2q_u16(test_vec[i].a);

    simde_uint16x8x2_t expected = {
        {simde_vld1q_u16(test_vec[i].r[0]), simde_vld1q_u16(test_vec[i].r[1])}};

    simde_test_arm_neon_assert_equal_u16x8(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_u16x8(r.val[1], expected.val[1]);
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x8_t a = simde_test_arm_neon_random_u16x8();
    simde_uint16x8_t b = simde_test_arm_neon_random_u16x8();
    simde_uint16x8x2_t c = {{a, b}};

    simde_test_arm_neon_write_u16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);

    uint16_t buf[16];
    simde_memcpy(buf, c.val, sizeof(buf));
    simde_uint16x8x2_t r = simde_vld2q_u16(buf);

    simde_test_arm_neon_write_u16x8x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld2q_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[4];
    uint32_t b[4];
    uint32_t r[2][4];
  } test_vec[] = {
    { { UINT32_C(2339918267), UINT32_C(1102380481), UINT32_C(3995943515), UINT32_C(2895736491) },
      { UINT32_C(1593232163), UINT32_C(3001942560), UINT32_C(4182622315), UINT32_C(2905851634) },
        { { UINT32_C(2339918267), UINT32_C(3995943515), UINT32_C(1593232163), UINT32_C(4182622315) },
          { UINT32_C(1102380481), UINT32_C(2895736491), UINT32_C(3001942560), UINT32_C(2905851634) } },
    },
    { { UINT32_C(3627658007), UINT32_C(  68808105), UINT32_C(3673310767), UINT32_C(3632696500) },
      { UINT32_C(2000059479), UINT32_C(3928564863), UINT32_C(3605296868), UINT32_C(1401100092) },
        { { UINT32_C(3627658007), UINT32_C(3673310767), UINT32_C(2000059479), UINT32_C(3605296868) },
          { UINT32_C(  68808105), UINT32_C(3632696500), UINT32_C(3928564863), UINT32_C(1401100092) } },
    },
    { { UINT32_C(1798094018), UINT32_C(3631236521), UINT32_C(1085432460), UINT32_C(1159215342) },
      { UINT32_C( 884756149), UINT32_C(1444865650), UINT32_C(2569798236), UINT32_C(3706499097) },
        { { UINT32_C(1798094018), UINT32_C(1085432460), UINT32_C( 884756149), UINT32_C(2569798236) },
          { UINT32_C(3631236521), UINT32_C(1159215342), UINT32_C(1444865650), UINT32_C(3706499097) } },
    },
    { { UINT32_C( 373758060), UINT32_C(3941513054), UINT32_C( 137011482), UINT32_C(2387493849) },
      { UINT32_C(  79825553), UINT32_C(1297801712), UINT32_C(4259743715), UINT32_C(2748961335) },
        { { UINT32_C( 373758060), UINT32_C( 137011482), UINT32_C(  79825553), UINT32_C(4259743715) },
          { UINT32_C(3941513054), UINT32_C(2387493849), UINT32_C(1297801712), UINT32_C(2748961335) } },
    },
    { { UINT32_C(1236869355), UINT32_C(4063471832), UINT32_C( 586833225), UINT32_C( 850479264) },
      { UINT32_C(1127641939), UINT32_C( 948998228), UINT32_C(1312126487), UINT32_C( 888278601) },
        { { UINT32_C(1236869355), UINT32_C( 586833225), UINT32_C(1127641939), UINT32_C(1312126487) },
          { UINT32_C(4063471832), UINT32_C( 850479264), UINT32_C( 948998228), UINT32_C( 888278601) } },
    },
    { { UINT32_C( 108899118), UINT32_C(2633543763), UINT32_C(2931815181), UINT32_C(2397073467) },
      { UINT32_C( 953292515), UINT32_C(3195036326), UINT32_C( 571254233), UINT32_C(3780574899) },
        { { UINT32_C( 108899118), UINT32_C(2931815181), UINT32_C( 953292515), UINT32_C( 571254233) },
          { UINT32_C(2633543763), UINT32_C(2397073467), UINT32_C(3195036326), UINT32_C(3780574899) } },
    },
    { { UINT32_C(4259894186), UINT32_C(2426069123), UINT32_C( 255744467), UINT32_C(2895978185) },
      { UINT32_C(3689180980), UINT32_C(2878952658), UINT32_C(2899158521), UINT32_C(1317938084) },
        { { UINT32_C(4259894186), UINT32_C( 255744467), UINT32_C(3689180980), UINT32_C(2899158521) },
          { UINT32_C(2426069123), UINT32_C(2895978185), UINT32_C(2878952658), UINT32_C(1317938084) } },
    },
    { { UINT32_C(2034988790), UINT32_C( 705291606), UINT32_C( 121194558), UINT32_C(2612319846) },
      { UINT32_C( 410425414), UINT32_C(3871543277), UINT32_C(1486065844), UINT32_C(2846237107) },
        { { UINT32_C(2034988790), UINT32_C( 121194558), UINT32_C( 410425414), UINT32_C(1486065844) },
          { UINT32_C( 705291606), UINT32_C(2612319846), UINT32_C(3871543277), UINT32_C(2846237107) } },
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4x2_t r = simde_vld2q_u32(test_vec[i].a);

    simde_uint32x4x2_t expected = {
        {simde_vld1q_u32(test_vec[i].r[0]), simde_vld1q_u32(test_vec[i].r[1])}};

    simde_test_arm_neon_assert_equal_u32x4(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_u32x4(r.val[1], expected.val[1]);
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x4_t a = simde_test_arm_neon_random_u32x4();
    simde_uint32x4_t b = simde_test_arm_neon_random_u32x4();
    simde_uint32x4x2_t c = {{a, b}};

    simde_test_arm_neon_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);

    uint32_t buf[8];
    simde_memcpy(buf, c.val, sizeof(buf));
    simde_uint32x4x2_t r = simde_vld2q_u32(buf);

    simde_test_arm_neon_write_u32x4x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld2q_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32_t a[4];
    simde_float32_t b[4];
    simde_float32_t r[2][4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   793.71), SIMDE_FLOAT32_C(   221.62), SIMDE_FLOAT32_C(   781.57), SIMDE_FLOAT32_C(  -525.52) },
      { SIMDE_FLOAT32_C(   800.99), SIMDE_FLOAT32_C(  -411.87), SIMDE_FLOAT32_C(   483.99), SIMDE_FLOAT32_C(   852.73) },
        { { SIMDE_FLOAT32_C(   793.71), SIMDE_FLOAT32_C(   781.57), SIMDE_FLOAT32_C(   800.99), SIMDE_FLOAT32_C(   483.99) },
          { SIMDE_FLOAT32_C(   221.62), SIMDE_FLOAT32_C(  -525.52), SIMDE_FLOAT32_C(  -411.87), SIMDE_FLOAT32_C(   852.73) } },
    },
    { { SIMDE_FLOAT32_C(  -433.25), SIMDE_FLOAT32_C(  -811.76), SIMDE_FLOAT32_C(  -463.04), SIMDE_FLOAT32_C(   671.94) },
      { SIMDE_FLOAT32_C(   -60.94), SIMDE_FLOAT32_C(  -434.20), SIMDE_FLOAT32_C(  -263.89), SIMDE_FLOAT32_C(   754.63) },
        { { SIMDE_FLOAT32_C(  -433.25), SIMDE_FLOAT32_C(  -463.04), SIMDE_FLOAT32_C(   -60.94), SIMDE_FLOAT32_C(  -263.89) },
          { SIMDE_FLOAT32_C(  -811.76), SIMDE_FLOAT32_C(   671.94), SIMDE_FLOAT32_C(  -434.20), SIMDE_FLOAT32_C(   754.63) } },
    },
    { { SIMDE_FLOAT32_C(  -877.85), SIMDE_FLOAT32_C(  -225.98), SIMDE_FLOAT32_C(  -292.03), SIMDE_FLOAT32_C(   932.32) },
      { SIMDE_FLOAT32_C(  -463.10), SIMDE_FLOAT32_C(   171.18), SIMDE_FLOAT32_C(  -115.23), SIMDE_FLOAT32_C(  -867.52) },
        { { SIMDE_FLOAT32_C(  -877.85), SIMDE_FLOAT32_C(  -292.03), SIMDE_FLOAT32_C(  -463.10), SIMDE_FLOAT32_C(  -115.23) },
          { SIMDE_FLOAT32_C(  -225.98), SIMDE_FLOAT32_C(   932.32), SIMDE_FLOAT32_C(   171.18), SIMDE_FLOAT32_C(  -867.52) } },
    },
    { { SIMDE_FLOAT32_C(  -182.14), SIMDE_FLOAT32_C(   874.57), SIMDE_FLOAT32_C(  -306.44), SIMDE_FLOAT32_C(   180.87) },
      { SIMDE_FLOAT32_C(  -827.59), SIMDE_FLOAT32_C(  -449.53), SIMDE_FLOAT32_C(  -593.39), SIMDE_FLOAT32_C(   966.11) },
        { { SIMDE_FLOAT32_C(  -182.14), SIMDE_FLOAT32_C(  -306.44), SIMDE_FLOAT32_C(  -827.59), SIMDE_FLOAT32_C(  -593.39) },
          { SIMDE_FLOAT32_C(   874.57), SIMDE_FLOAT32_C(   180.87), SIMDE_FLOAT32_C(  -449.53), SIMDE_FLOAT32_C(   966.11) } },
    },
    { { SIMDE_FLOAT32_C(   772.09), SIMDE_FLOAT32_C(  -811.82), SIMDE_FLOAT32_C(  -559.40), SIMDE_FLOAT32_C(   573.08) },
      { SIMDE_FLOAT32_C(  -223.69), SIMDE_FLOAT32_C(   924.59), SIMDE_FLOAT32_C(   425.81), SIMDE_FLOAT32_C(   343.06) },
        { { SIMDE_FLOAT32_C(   772.09), SIMDE_FLOAT32_C(  -559.40), SIMDE_FLOAT32_C(  -223.69), SIMDE_FLOAT32_C(   425.81) },
          { SIMDE_FLOAT32_C(  -811.82), SIMDE_FLOAT32_C(   573.08), SIMDE_FLOAT32_C(   924.59), SIMDE_FLOAT32_C(   343.06) } },
    },
    { { SIMDE_FLOAT32_C(  -887.17), SIMDE_FLOAT32_C(   962.76), SIMDE_FLOAT32_C(    15.01), SIMDE_FLOAT32_C(    51.89) },
      { SIMDE_FLOAT32_C(  -471.44), SIMDE_FLOAT32_C(   751.11), SIMDE_FLOAT32_C(  -193.48), SIMDE_FLOAT32_C(  -349.29) },
        { { SIMDE_FLOAT32_C(  -887.17), SIMDE_FLOAT32_C(    15.01), SIMDE_FLOAT32_C(  -471.44), SIMDE_FLOAT32_C(  -193.48) },
          { SIMDE_FLOAT32_C(   962.76), SIMDE_FLOAT32_C(    51.89), SIMDE_FLOAT32_C(   751.11), SIMDE_FLOAT32_C(  -349.29) } },
    },
    { { SIMDE_FLOAT32_C(  -474.87), SIMDE_FLOAT32_C(   514.49), SIMDE_FLOAT32_C(  -416.97), SIMDE_FLOAT32_C(    62.03) },
      { SIMDE_FLOAT32_C(  -314.33), SIMDE_FLOAT32_C(   467.80), SIMDE_FLOAT32_C(   194.51), SIMDE_FLOAT32_C(   503.53) },
        { { SIMDE_FLOAT32_C(  -474.87), SIMDE_FLOAT32_C(  -416.97), SIMDE_FLOAT32_C(  -314.33), SIMDE_FLOAT32_C(   194.51) },
          { SIMDE_FLOAT32_C(   514.49), SIMDE_FLOAT32_C(    62.03), SIMDE_FLOAT32_C(   467.80), SIMDE_FLOAT32_C(   503.53) } },
    },
    { { SIMDE_FLOAT32_C(   342.37), SIMDE_FLOAT32_C(   888.07), SIMDE_FLOAT32_C(  -315.60), SIMDE_FLOAT32_C(   514.77) },
      { SIMDE_FLOAT32_C(  -561.46), SIMDE_FLOAT32_C(    91.01), SIMDE_FLOAT32_C(   480.89), SIMDE_FLOAT32_C(  -789.37) },
        { { SIMDE_FLOAT32_C(   342.37), SIMDE_FLOAT32_C(  -315.60), SIMDE_FLOAT32_C(  -561.46), SIMDE_FLOAT32_C(   480.89) },
          { SIMDE_FLOAT32_C(   888.07), SIMDE_FLOAT32_C(   514.77), SIMDE_FLOAT32_C(    91.01), SIMDE_FLOAT32_C(  -789.37) } },
    },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4x2_t r = simde_vld2q_f32(test_vec[i].a);

    simde_float32x4x2_t expected = {
        {simde_vld1q_f32(test_vec[i].r[0]), simde_vld1q_f32(test_vec[i].r[1])}};

    simde_test_arm_neon_assert_equal_f32x4(r.val[0], expected.val[0], INT_MAX);
    simde_test_arm_neon_assert_equal_f32x4(r.val[1], expected.val[1], INT_MAX);
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x4_t a = simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f);
    simde_float32x4_t b = simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f);
    simde_float32x4x2_t c = {{a, b}};

    simde_test_arm_neon_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);

    simde_float32_t buf[8];
    simde_memcpy(buf, c.val, sizeof(buf));
    simde_float32x4x2_t r = simde_vld2q_f32(buf);

    simde_test_arm_neon_write_f32x4x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

#endif /* !defined(SIMDE_BUG_INTEL_857088) */

SIMDE_TEST_FUNC_LIST_BEGIN
#if !defined(SIMDE_BUG_INTEL_857088)
SIMDE_TEST_FUNC_LIST_ENTRY(vld2_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vld2_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vld2_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vld2q_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vld2q_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vld2q_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vld2q_f32)
#endif /* !defined(SIMDE_BUG_INTEL_857088) */
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
