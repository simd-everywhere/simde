#define SIMDE_TEST_ARM_NEON_INSN bcax

#include "test-neon.h"
#include "../../../simde/arm/neon/bcax.h"

static int
test_simde_vbcaxq_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t a[16];
    uint8_t b[16];
    uint8_t c[16];
    uint8_t r[16];
  } test_vec[] = {
    { { UINT8_C( 94), UINT8_C(202), UINT8_C(219), UINT8_C( 52), UINT8_C(161), UINT8_C(226), UINT8_C(154), UINT8_C(223),
        UINT8_C(137), UINT8_C(203), UINT8_C( 64), UINT8_C(129), UINT8_C( 78), UINT8_C(197), UINT8_C(180), UINT8_C( 34) },
      { UINT8_C(223), UINT8_C(135), UINT8_C( 27), UINT8_C(251), UINT8_C( 74), UINT8_C(213), UINT8_C( 41), UINT8_C(249),
        UINT8_C( 21), UINT8_C(146), UINT8_C(219), UINT8_C(116), UINT8_C(213), UINT8_C(160), UINT8_C(106), UINT8_C( 51) },
      { UINT8_C(107), UINT8_C( 69), UINT8_C(104), UINT8_C( 12), UINT8_C( 39), UINT8_C(  2), UINT8_C(235), UINT8_C(177),
        UINT8_C(205), UINT8_C( 43), UINT8_C( 50), UINT8_C( 28), UINT8_C(240), UINT8_C(230), UINT8_C( 62), UINT8_C(208) },
      { UINT8_C(202), UINT8_C( 72), UINT8_C(200), UINT8_C(199), UINT8_C(233), UINT8_C( 55), UINT8_C(154), UINT8_C(151),
        UINT8_C(153), UINT8_C( 91), UINT8_C(137), UINT8_C(225), UINT8_C( 75), UINT8_C(197), UINT8_C(244), UINT8_C(  1) } },
    { { UINT8_C(109), UINT8_C( 90), UINT8_C(203), UINT8_C(184), UINT8_C( 47), UINT8_C(244), UINT8_C(177), UINT8_C( 68),
        UINT8_C(135), UINT8_C(140), UINT8_C(184), UINT8_C( 92), UINT8_C( 45), UINT8_C( 34), UINT8_C(144), UINT8_C(152) },
      { UINT8_C(103), UINT8_C(248), UINT8_C(164), UINT8_C(143), UINT8_C(250), UINT8_C(144), UINT8_C( 64), UINT8_C(200),
        UINT8_C(187), UINT8_C(114), UINT8_C(228), UINT8_C(172), UINT8_C( 89), UINT8_C( 34), UINT8_C(124), UINT8_C(198) },
      { UINT8_C(124), UINT8_C( 71), UINT8_C(126), UINT8_C(172), UINT8_C( 60), UINT8_C( 48), UINT8_C(240), UINT8_C(195),
        UINT8_C(188), UINT8_C(169), UINT8_C( 31), UINT8_C(233), UINT8_C(203), UINT8_C(175), UINT8_C(129), UINT8_C( 51) },
      { UINT8_C(110), UINT8_C(226), UINT8_C( 75), UINT8_C(187), UINT8_C(237), UINT8_C(116), UINT8_C(177), UINT8_C( 76),
        UINT8_C(132), UINT8_C(222), UINT8_C( 88), UINT8_C( 88), UINT8_C( 61), UINT8_C( 34), UINT8_C(236), UINT8_C( 92) } },
    { { UINT8_C(167), UINT8_C( 38), UINT8_C(194), UINT8_C(162), UINT8_C(182), UINT8_C(  2), UINT8_C(106), UINT8_C(113),
        UINT8_C(116), UINT8_C( 78), UINT8_C( 29), UINT8_C(205), UINT8_C(112), UINT8_C(153), UINT8_C(148), UINT8_C(237) },
      { UINT8_C(225), UINT8_C( 18), UINT8_C(153), UINT8_C( 29), UINT8_C( 66), UINT8_C(137), UINT8_C(224),    UINT8_MAX,
        UINT8_C( 50),    UINT8_MAX, UINT8_C(232), UINT8_C(254), UINT8_C(175), UINT8_C(106), UINT8_C( 49), UINT8_C( 86) },
      { UINT8_C(144), UINT8_C(243), UINT8_C(248), UINT8_C( 70), UINT8_C(245), UINT8_C( 98), UINT8_C(183), UINT8_C(105),
        UINT8_C(176), UINT8_C(213), UINT8_C( 55), UINT8_C( 33), UINT8_C(110), UINT8_C(203), UINT8_C( 14), UINT8_C( 79) },
      { UINT8_C(198), UINT8_C( 38), UINT8_C(195), UINT8_C(187), UINT8_C(180), UINT8_C(139), UINT8_C( 42), UINT8_C(231),
        UINT8_C(118), UINT8_C(100), UINT8_C(213), UINT8_C( 19), UINT8_C(241), UINT8_C(185), UINT8_C(165), UINT8_C(253) } },
    { { UINT8_C(221), UINT8_C(167), UINT8_C(108), UINT8_C( 32), UINT8_C( 48), UINT8_C( 76), UINT8_C( 31), UINT8_C( 99),
        UINT8_C( 76), UINT8_C(  7), UINT8_C( 97), UINT8_C(251), UINT8_C(113), UINT8_C(146), UINT8_C( 81), UINT8_C(  1) },
      { UINT8_C(133), UINT8_C( 74), UINT8_C( 71), UINT8_C(122), UINT8_C(172),    UINT8_MAX, UINT8_C(227), UINT8_C( 93),
        UINT8_C(212), UINT8_C( 26), UINT8_C(126), UINT8_C( 66), UINT8_C(229), UINT8_C(140), UINT8_C(146), UINT8_C(195) },
      { UINT8_C( 51), UINT8_C(254), UINT8_C(227), UINT8_C( 99), UINT8_C( 75), UINT8_C(  2), UINT8_C(198), UINT8_C(151),
        UINT8_C(  9), UINT8_C( 39), UINT8_C(146), UINT8_C(123), UINT8_C(185), UINT8_C(227), UINT8_C(124), UINT8_C( 62) },
      { UINT8_C( 89), UINT8_C(167), UINT8_C(104), UINT8_C( 56), UINT8_C(148), UINT8_C(177), UINT8_C( 62), UINT8_C( 43),
        UINT8_C(152), UINT8_C( 31), UINT8_C( 13), UINT8_C(251), UINT8_C( 53), UINT8_C(158), UINT8_C(211), UINT8_C(192) } },
    { { UINT8_C( 45), UINT8_C(196), UINT8_C(184), UINT8_C(218), UINT8_C(195), UINT8_C(156), UINT8_C( 55), UINT8_C(151),
        UINT8_C(182), UINT8_C(181), UINT8_C(217), UINT8_C(156), UINT8_C( 65), UINT8_C(107), UINT8_C( 95), UINT8_C(116) },
      { UINT8_C(106), UINT8_C( 66), UINT8_C(215), UINT8_C(181), UINT8_C( 68), UINT8_C(158), UINT8_C( 76), UINT8_C( 77),
        UINT8_C(197), UINT8_C(222), UINT8_C(200), UINT8_C(127), UINT8_C(193), UINT8_C( 69), UINT8_C(189), UINT8_C(239) },
      { UINT8_C(  9), UINT8_C(118), UINT8_C(201), UINT8_C(204), UINT8_C( 18), UINT8_C(  0), UINT8_C( 99), UINT8_C(200),
        UINT8_C(181), UINT8_C( 60), UINT8_C(100), UINT8_C(246), UINT8_C(168), UINT8_C(195), UINT8_C(106), UINT8_C( 18) },
      { UINT8_C( 79), UINT8_C(196), UINT8_C(174), UINT8_C(235), UINT8_C(135), UINT8_C(  2), UINT8_C( 59), UINT8_C(146),
        UINT8_C(246), UINT8_C(119), UINT8_C( 81), UINT8_C(149), UINT8_C(  0), UINT8_C(111), UINT8_C(202), UINT8_C(153) } },
    { { UINT8_C(  5), UINT8_C( 65), UINT8_C(199), UINT8_C( 73), UINT8_C(223), UINT8_C( 19), UINT8_C(151), UINT8_C(165),
        UINT8_C(241), UINT8_C( 95), UINT8_C( 36), UINT8_C(178), UINT8_C(164), UINT8_C(225), UINT8_C(161), UINT8_C(173) },
      { UINT8_C( 87), UINT8_C(106), UINT8_C(121), UINT8_C(105), UINT8_C(106), UINT8_C(220), UINT8_C( 50), UINT8_C( 31),
        UINT8_C( 25), UINT8_C(150), UINT8_C( 21), UINT8_C(193), UINT8_C( 90), UINT8_C(127), UINT8_C(211), UINT8_C( 95) },
      { UINT8_C(193), UINT8_C(154), UINT8_C(169), UINT8_C(160), UINT8_C(173), UINT8_C( 64), UINT8_C( 69), UINT8_C(158),
        UINT8_C(159), UINT8_C(105), UINT8_C( 80), UINT8_C( 68), UINT8_C( 75), UINT8_C(242), UINT8_C(241), UINT8_C(162) },
      { UINT8_C( 19), UINT8_C( 33), UINT8_C(151), UINT8_C(  0), UINT8_C(157), UINT8_C(143), UINT8_C(165), UINT8_C(164),
        UINT8_C(241), UINT8_C(201), UINT8_C( 33), UINT8_C( 51), UINT8_C(180), UINT8_C(236), UINT8_C(163), UINT8_C(240) } },
    { { UINT8_C( 92), UINT8_C(107), UINT8_C( 12), UINT8_C(199), UINT8_C( 71), UINT8_C( 62), UINT8_C(230), UINT8_C( 96),
        UINT8_C(212), UINT8_C(252), UINT8_C( 33), UINT8_C( 46), UINT8_C(123), UINT8_C(244), UINT8_C(142), UINT8_C( 60) },
      { UINT8_C(142), UINT8_C( 55), UINT8_C(221), UINT8_C( 59), UINT8_C(119), UINT8_C( 34), UINT8_C(217), UINT8_C( 22),
        UINT8_C(140), UINT8_C( 42), UINT8_C( 90), UINT8_C(215), UINT8_C( 28), UINT8_C( 76), UINT8_C(121), UINT8_C(120) },
      { UINT8_C(183), UINT8_C(133), UINT8_C( 63), UINT8_C(254), UINT8_C(195), UINT8_C( 38), UINT8_C( 95), UINT8_C(152),
        UINT8_C( 34), UINT8_C(128), UINT8_C(198), UINT8_C(157), UINT8_C(117), UINT8_C( 84), UINT8_C(218), UINT8_C(  3) },
      { UINT8_C( 84), UINT8_C( 89), UINT8_C(204), UINT8_C(198), UINT8_C(115), UINT8_C( 62), UINT8_C(102), UINT8_C(102),
        UINT8_C( 88), UINT8_C(214), UINT8_C( 57), UINT8_C(108), UINT8_C(115), UINT8_C(252), UINT8_C(175), UINT8_C( 68) } },
    { { UINT8_C(139), UINT8_C(183), UINT8_C( 63), UINT8_C(  2), UINT8_C(217), UINT8_C( 24), UINT8_C( 25), UINT8_C(101),
        UINT8_C( 66), UINT8_C(115), UINT8_C( 60), UINT8_C( 94), UINT8_C(191), UINT8_C(182), UINT8_C(215), UINT8_C(118) },
      { UINT8_C( 59), UINT8_C( 22), UINT8_C(117),    UINT8_MAX, UINT8_C( 60), UINT8_C(212), UINT8_C(151), UINT8_C( 94),
        UINT8_C( 84), UINT8_C( 93), UINT8_C(252), UINT8_C(201), UINT8_C(178), UINT8_C(214), UINT8_C(205), UINT8_C( 61) },
      { UINT8_C(141), UINT8_C( 12), UINT8_C( 64), UINT8_C(102), UINT8_C( 36), UINT8_C( 89), UINT8_C(204), UINT8_C(103),
        UINT8_C(204), UINT8_C(  8), UINT8_C(197), UINT8_C(140), UINT8_C(190), UINT8_C(156), UINT8_C(  2), UINT8_C(250) },
      { UINT8_C(185), UINT8_C(165), UINT8_C( 10), UINT8_C(155), UINT8_C(193), UINT8_C(156), UINT8_C( 10), UINT8_C(125),
        UINT8_C( 82), UINT8_C( 38), UINT8_C(  4), UINT8_C( 31), UINT8_C(191), UINT8_C(244), UINT8_C( 26), UINT8_C(115) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x16_t a = simde_vld1q_u8(test_vec[i].a);
    simde_uint8x16_t b = simde_vld1q_u8(test_vec[i].b);
    simde_uint8x16_t c = simde_vld1q_u8(test_vec[i].c);
    simde_uint8x16_t r = simde_vbcaxq_u8(a, b, c);

    simde_test_arm_neon_assert_equal_u8x16(r, simde_vld1q_u8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8x16_t a = simde_test_arm_neon_random_u8x16();
    simde_uint8x16_t b = simde_test_arm_neon_random_u8x16();
    simde_uint8x16_t c = simde_test_arm_neon_random_u8x16();
    simde_uint8x16_t r = simde_vbcaxq_u8(a, b, c);

    simde_test_arm_neon_write_u8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x16(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vbcaxq_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[8];
    uint16_t b[8];
    uint16_t c[8];
    uint16_t r[8];
  } test_vec[] = {
    { { UINT16_C(44728), UINT16_C(53981), UINT16_C( 8580), UINT16_C(18108), UINT16_C(50134), UINT16_C(26135), UINT16_C(37728), UINT16_C(10922) },
      { UINT16_C(15915), UINT16_C(14734), UINT16_C(19885), UINT16_C(16007), UINT16_C(25394), UINT16_C(29216), UINT16_C( 5226), UINT16_C( 8908) },
      { UINT16_C(43715), UINT16_C(18420), UINT16_C(45515), UINT16_C(41357), UINT16_C(42100), UINT16_C(54536), UINT16_C(45623), UINT16_C(25343) },
      { UINT16_C(47760), UINT16_C(60119), UINT16_C(28064), UINT16_C(22718), UINT16_C(32980), UINT16_C(17463), UINT16_C(38696), UINT16_C(10922) } },
    { { UINT16_C(36336), UINT16_C(40603), UINT16_C( 9179), UINT16_C( 3548), UINT16_C(64646), UINT16_C(61567), UINT16_C(19217), UINT16_C(54290) },
      { UINT16_C( 2037), UINT16_C(49179), UINT16_C(43192), UINT16_C(11362), UINT16_C(27212), UINT16_C(33793), UINT16_C(   28), UINT16_C( 3558) },
      { UINT16_C(33422), UINT16_C(27051), UINT16_C(34725), UINT16_C(11126), UINT16_C(62851), UINT16_C(37916), UINT16_C(11840), UINT16_C(13928) },
      { UINT16_C(34945), UINT16_C( 7819), UINT16_C( 3011), UINT16_C( 2524), UINT16_C(63178), UINT16_C(61566), UINT16_C(19213), UINT16_C(56724) } },
    { { UINT16_C(33589), UINT16_C(60918), UINT16_C(22571), UINT16_C(30746), UINT16_C( 7106), UINT16_C(57340), UINT16_C(57884), UINT16_C(43756) },
      { UINT16_C(38756), UINT16_C( 2323), UINT16_C(35102), UINT16_C(41269), UINT16_C(20862), UINT16_C(48694), UINT16_C(40575), UINT16_C(46580) },
      { UINT16_C(60194), UINT16_C(19874), UINT16_C(48195), UINT16_C( 1733), UINT16_C(49624), UINT16_C(62693), UINT16_C(53668), UINT16_C( 2206) },
      { UINT16_C(38769), UINT16_C(60903), UINT16_C(22839), UINT16_C(55594), UINT16_C( 3044), UINT16_C(54766), UINT16_C(60487), UINT16_C( 8076) } },
    { { UINT16_C(45416), UINT16_C(34322), UINT16_C(18234), UINT16_C(47143), UINT16_C(23960), UINT16_C( 6006), UINT16_C(27644), UINT16_C( 7884) },
      { UINT16_C(28502), UINT16_C(39275), UINT16_C(12587), UINT16_C(  927), UINT16_C(34034), UINT16_C(38647), UINT16_C(38229), UINT16_C(48543) },
      { UINT16_C(45382), UINT16_C(32835), UINT16_C(27640), UINT16_C(36920), UINT16_C(45000), UINT16_C(50343), UINT16_C(29722), UINT16_C(28898) },
      { UINT16_C(65400), UINT16_C(40762), UINT16_C(22329), UINT16_C(48032), UINT16_C(23978), UINT16_C( 1318), UINT16_C(60089), UINT16_C(37841) } },
    { { UINT16_C(20195), UINT16_C( 3593), UINT16_C(43391), UINT16_C(28946), UINT16_C( 2349), UINT16_C(33544), UINT16_C(42911), UINT16_C(58688) },
      { UINT16_C(33880), UINT16_C(20582), UINT16_C(40687), UINT16_C(47072), UINT16_C(34637), UINT16_C(26492), UINT16_C(24315), UINT16_C(57047) },
      { UINT16_C(57772), UINT16_C(11245), UINT16_C(65418), UINT16_C(47005), UINT16_C(42248), UINT16_C(42810), UINT16_C(31564), UINT16_C(42125) },
      { UINT16_C(19123), UINT16_C(24075), UINT16_C(43290), UINT16_C(29042), UINT16_C( 2920), UINT16_C(49996), UINT16_C(41772), UINT16_C(48914) } },
    { { UINT16_C(62463), UINT16_C(61172), UINT16_C(54417), UINT16_C(57253), UINT16_C( 8539), UINT16_C(22342), UINT16_C( 7808), UINT16_C(11317) },
      { UINT16_C( 8959), UINT16_C(35160), UINT16_C(62753), UINT16_C(10816), UINT16_C(31642), UINT16_C(59089), UINT16_C(24310), UINT16_C(62858) },
      { UINT16_C(32337), UINT16_C(58339), UINT16_C(34898), UINT16_C(44482), UINT16_C( 2218), UINT16_C(10756), UINT16_C(14886), UINT16_C( 9558) },
      { UINT16_C(62289), UINT16_C(59116), UINT16_C(41392), UINT16_C(56741), UINT16_C(21067), UINT16_C(37783), UINT16_C(23120), UINT16_C(64701) } },
    { { UINT16_C(44636), UINT16_C(32430), UINT16_C(61347), UINT16_C(15784), UINT16_C(31082), UINT16_C(24611), UINT16_C(44504), UINT16_C(10581) },
      { UINT16_C(14379), UINT16_C(32012), UINT16_C(52928), UINT16_C(27179), UINT16_C(12247), UINT16_C(64916), UINT16_C(60265), UINT16_C(50723) },
      { UINT16_C(53657), UINT16_C(15684), UINT16_C(60608), UINT16_C(10874), UINT16_C(40549), UINT16_C(15754), UINT16_C(57163), UINT16_C(30567) },
      { UINT16_C(34430), UINT16_C(16038), UINT16_C(60835), UINT16_C(32169), UINT16_C(22776), UINT16_C(41015), UINT16_C(36344), UINT16_C(43349) } },
    { { UINT16_C(29463), UINT16_C(55540), UINT16_C( 8002), UINT16_C( 6466), UINT16_C(55119), UINT16_C(47126), UINT16_C(14786), UINT16_C(23422) },
      { UINT16_C(49675), UINT16_C(52120), UINT16_C( 5038), UINT16_C( 5366), UINT16_C(32945), UINT16_C(64593), UINT16_C(47200), UINT16_C(30579) },
      { UINT16_C(26668), UINT16_C(28239), UINT16_C(37511), UINT16_C(54919), UINT16_C(40297), UINT16_C(11151), UINT16_C( 3543), UINT16_C(57990) },
      { UINT16_C(61716), UINT16_C(22884), UINT16_C( 7786), UINT16_C( 6450), UINT16_C(55263), UINT16_C(27718), UINT16_C(35298), UINT16_C(19983) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);
    simde_uint16x8_t b = simde_vld1q_u16(test_vec[i].b);
    simde_uint16x8_t c = simde_vld1q_u16(test_vec[i].c);
    simde_uint16x8_t r = simde_vbcaxq_u16(a, b, c);
    simde_test_arm_neon_assert_equal_u16x8(r, simde_vld1q_u16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x8_t a = simde_test_arm_neon_random_u16x8();
    simde_uint16x8_t b = simde_test_arm_neon_random_u16x8();
    simde_uint16x8_t c = simde_test_arm_neon_random_u16x8();
    simde_uint16x8_t r = simde_vbcaxq_u16(a, b, c);

    simde_test_arm_neon_write_u16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vbcaxq_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[4];
    uint32_t b[4];
    uint32_t c[4];
    uint32_t r[4];
  } test_vec[] = {
    { { UINT32_C( 772490388), UINT32_C(2412909815), UINT32_C(4003969784), UINT32_C(2243975421) },
      { UINT32_C( 866695375), UINT32_C( 896231729), UINT32_C( 583176858), UINT32_C(2233797617) },
      { UINT32_C(1202991439), UINT32_C(1037469253), UINT32_C(1026260288), UINT32_C(2781080533) },
      { UINT32_C( 503565332), UINT32_C(2415623623), UINT32_C(3966187618), UINT32_C(2246334685) } },
    { { UINT32_C(3570953123), UINT32_C(1862878165), UINT32_C(3348286422), UINT32_C( 642562007) },
      { UINT32_C( 762118376), UINT32_C(3328853126), UINT32_C(2533660097), UINT32_C( 591185792) },
      { UINT32_C( 133633074), UINT32_C( 762773847), UINT32_C(2750679500), UINT32_C(2848604608) },
      { UINT32_C(4241517419), UINT32_C(2902525781), UINT32_C(3549585367), UINT32_C( 611856855) } },
    { { UINT32_C(3369482049), UINT32_C(1032733051), UINT32_C(1473549014), UINT32_C(2356809817) },
      { UINT32_C(2073260580), UINT32_C(1068042867), UINT32_C(3571686675), UINT32_C( 545107422) },
      { UINT32_C(1625838564), UINT32_C(1805481620), UINT32_C(1656910089), UINT32_C(2783853697) },
      { UINT32_C(3552909121), UINT32_C( 699287832), UINT32_C(3287621316), UINT32_C(2355859719) } },
    { { UINT32_C( 555778734), UINT32_C(2690763148), UINT32_C(1165247591), UINT32_C(3580228081) },
      { UINT32_C(3644149060), UINT32_C(3443839684), UINT32_C(3291416131), UINT32_C(4050198082) },
      { UINT32_C( 739412640), UINT32_C(3133961043), UINT32_C(2818588855), UINT32_C(1987994929) },
      { UINT32_C(4026910698), UINT32_C(3848358152), UINT32_C(  22757927), UINT32_C(1415900083) } },
    { { UINT32_C(2001712051), UINT32_C(3376714630), UINT32_C(3683546009), UINT32_C( 835516305) },
      { UINT32_C(3579764609), UINT32_C( 177154642), UINT32_C(2628947819), UINT32_C(2819764469) },
      { UINT32_C(1780441572), UINT32_C(2368955380), UINT32_C(1751761366), UINT32_C( 983119289) },
      { UINT32_C(3792645554), UINT32_C(3418921860), UINT32_C(1327267248), UINT32_C(2983131093) } },
    { { UINT32_C(1729099540), UINT32_C(2373033762), UINT32_C( 589898542), UINT32_C( 952843348) },
      { UINT32_C(2460150429), UINT32_C( 606065997), UINT32_C(1351387287), UINT32_C(3532268990) },
      { UINT32_C(1060739613), UINT32_C(1741466169), UINT32_C( 579597774), UINT32_C(3478804017) },
      { UINT32_C(3884816276), UINT32_C(2372061798), UINT32_C(1932340031), UINT32_C( 676011482) } },
    { { UINT32_C(2388786241), UINT32_C(1756528849), UINT32_C(3350740489), UINT32_C(2174305124) },
      { UINT32_C( 381735901), UINT32_C(1266519165), UINT32_C(3010267265), UINT32_C(2692925279) },
      { UINT32_C(2502878147), UINT32_C(1828577635), UINT32_C(2201204255), UINT32_C(3590639097) },
      { UINT32_C(2359422045), UINT32_C(1806863565), UINT32_C(4159977097), UINT32_C(2702917986) } },
    { { UINT32_C( 502056096), UINT32_C(3530123600), UINT32_C(3515209330), UINT32_C(1634797470) },
      { UINT32_C(1308008426), UINT32_C(2696606848), UINT32_C(2737040810), UINT32_C(1517889722) },
      { UINT32_C(1031300588), UINT32_C(1074782670), UINT32_C(1427215543), UINT32_C(2243396251) },
      { UINT32_C(1567252130), UINT32_C(1926856016), UINT32_C(1940373370), UINT32_C( 993603518) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint32x4_t b = simde_vld1q_u32(test_vec[i].b);
    simde_uint32x4_t c = simde_vld1q_u32(test_vec[i].c);
    simde_uint32x4_t r = simde_vbcaxq_u32(a, b, c);

    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x4_t a = simde_test_arm_neon_random_u32x4();
    simde_uint32x4_t b = simde_test_arm_neon_random_u32x4();
    simde_uint32x4_t c = simde_test_arm_neon_random_u32x4();
    simde_uint32x4_t r = simde_vbcaxq_u32(a, b, c);

    simde_test_arm_neon_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vbcaxq_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a[2];
    uint64_t b[2];
    uint64_t c[2];
    uint64_t r[2];
  } test_vec[] = {
    { { UINT64_C(14054494001353930496), UINT64_C(  710101730332602073) },
      { UINT64_C( 2964514158989067003), UINT64_C( 5688424899664169746) },
      { UINT64_C(17304776004398448783), UINT64_C(14421855097822511961) },
      { UINT64_C(14558877812941354352), UINT64_C( 1084111593827804891) } },
    { { UINT64_C( 8182669293432491386), UINT64_C( 7896540633248335609) },
      { UINT64_C(13307281890023077285), UINT64_C(13659409160542128890) },
      { UINT64_C(13913222099136289093), UINT64_C( 1406142803834652983) },
      { UINT64_C( 5271155816217061850), UINT64_C(13950539617781417009) } },
    { { UINT64_C( 4912436853255132180), UINT64_C( 4468867121392844805) },
      { UINT64_C( 1098306393328461748), UINT64_C(17996852389883496000) },
      { UINT64_C( 1192496275068391677), UINT64_C(16631613321159088025) },
      { UINT64_C( 5412514875694740244), UINT64_C( 2811437202329518149) } },
    { { UINT64_C(16747373709767127427), UINT64_C( 3946656554200502502) },
      { UINT64_C( 7206333125297517287), UINT64_C( 4159573119884155553) },
      { UINT64_C(11531465446252616566), UINT64_C(15995996383172402830) },
      { UINT64_C(12423917248757600514), UINT64_C( 1640879524533489863) } },
    { { UINT64_C( 2707457791165954915), UINT64_C(14059025605550704428) },
      { UINT64_C( 4334690097885786060), UINT64_C( 2835580858805752711) },
      { UINT64_C( 2821197281822583164), UINT64_C(11276490995892035183) },
      { UINT64_C( 4437130304023297507), UINT64_C(16148694714952582828) } },
    { { UINT64_C(15113318707891495123), UINT64_C( 4452556731231158494) },
      { UINT64_C( 8571867450440556754), UINT64_C(17793634318513536642) },
      { UINT64_C( 4335898116822077969), UINT64_C(17722976404466793461) },
      { UINT64_C(10622878025012428817), UINT64_C( 4594156237778470108) } },
    { { UINT64_C( 1749569938160562889), UINT64_C( 4310043983476390326) },
      { UINT64_C( 8144410817376700268), UINT64_C( 6365305421664085309) },
      { UINT64_C( 9870888530050881869), UINT64_C( 3264882960207276010) },
      { UINT64_C( 7585533721560052969), UINT64_C( 7764293876229994915) } },
    { { UINT64_C(16530178380138014073), UINT64_C(17782916855212969442) },
      { UINT64_C( 5480834990207595190), UINT64_C( 1957851577609908541) },
      { UINT64_C(  225591337163957140), UINT64_C(13376602404224788228) },
      { UINT64_C(12207145214472435035), UINT64_C(17636410640354942427) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x2_t a = simde_vld1q_u64(test_vec[i].a);
    simde_uint64x2_t b = simde_vld1q_u64(test_vec[i].b);
    simde_uint64x2_t c = simde_vld1q_u64(test_vec[i].c);
    simde_uint64x2_t r = simde_vbcaxq_u64(a, b, c);
    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint64x2_t a = simde_test_arm_neon_random_u64x2();
    simde_uint64x2_t b = simde_test_arm_neon_random_u64x2();
    simde_uint64x2_t c = simde_test_arm_neon_random_u64x2();
    simde_uint64x2_t r = simde_vbcaxq_u64(a, b, c);

    simde_test_arm_neon_write_u64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vbcaxq_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[16];
    int8_t b[16];
    int8_t c[16];
    int8_t r[16];
  } test_vec[] = {
    { { -INT8_C( 103), -INT8_C(  71),  INT8_C(   6),  INT8_C(  82), -INT8_C(  51),  INT8_C(  66),  INT8_C(  10), -INT8_C(  52),
         INT8_C(  65),  INT8_C(  75), -INT8_C(  62),  INT8_C( 103),  INT8_C(  45), -INT8_C(  87),  INT8_C( 124),  INT8_C(  66) },
      { -INT8_C(  81), -INT8_C(  44), -INT8_C( 101), -INT8_C(  63), -INT8_C(  91),  INT8_C(  72),  INT8_C(  28),  INT8_C(  25),
        -INT8_C(  33),  INT8_C(  14), -INT8_C(  36),  INT8_C(  36), -INT8_C(  68), -INT8_C(  35), -INT8_C(  28),  INT8_C(  86) },
      { -INT8_C( 105), -INT8_C(  22), -INT8_C(  88),  INT8_C( 100),  INT8_C(  45), -INT8_C(  77),  INT8_C(  49),  INT8_C( 110),
        -INT8_C(   2), -INT8_C(  13), -INT8_C(  43),  INT8_C(  43), -INT8_C( 100),  INT8_C(  81),  INT8_C( 109),  INT8_C(  76) },
      { -INT8_C(  79), -INT8_C(  83),  INT8_C(  21), -INT8_C(  45),  INT8_C(  77),  INT8_C(  10),  INT8_C(   6), -INT8_C(  35),
         INT8_C(  64),  INT8_C(  71), -INT8_C(  54),  INT8_C(  99),  INT8_C(  13),  INT8_C(  37), -INT8_C(   4),  INT8_C(  80) } },
    { {  INT8_C(  38),  INT8_C(   8),  INT8_C(  13), -INT8_C(  53),  INT8_C(  81),  INT8_C(  41), -INT8_C(  27),  INT8_C(  48),
         INT8_C(  56), -INT8_C(  63),  INT8_C(  84), -INT8_C(  12), -INT8_C(  98),  INT8_C(  56),  INT8_C(  74),  INT8_C(  53) },
      {  INT8_C(  34), -INT8_C(  13), -INT8_C( 102),  INT8_C(  79), -INT8_C(  90), -INT8_C(  53), -INT8_C(  67), -INT8_C(  92),
        -INT8_C(  66), -INT8_C( 110), -INT8_C(  48),  INT8_C(  90), -INT8_C(  28),  INT8_C(  61), -INT8_C(  90),  INT8_C(  10) },
      {  INT8_C(  70), -INT8_C(  76), -INT8_C(  43), -INT8_C( 105), -INT8_C(  35), -INT8_C(  70), -INT8_C(  57),  INT8_C(  21),
         INT8_C( 123),  INT8_C(  27),  INT8_C(  10),  INT8_C(  26),  INT8_C(  83),  INT8_C(  84),  INT8_C(  79),  INT8_C( 117) },
      {  INT8_C(   6),  INT8_C(  75),  INT8_C(   7), -INT8_C( 125),  INT8_C( 115),  INT8_C( 104), -INT8_C(  35), -INT8_C( 112),
        -INT8_C(  68),  INT8_C(  65), -INT8_C( 124), -INT8_C(  76),  INT8_C(  58),  INT8_C(  17), -INT8_C(  22),  INT8_C(  63) } },
    { {  INT8_C(  71), -INT8_C(  23), -INT8_C(  59), -INT8_C(  19), -INT8_C(  76), -INT8_C( 126), -INT8_C( 110),  INT8_C( 114),
         INT8_C(  21),  INT8_C(  98), -INT8_C(  51), -INT8_C(   7), -INT8_C(  97),  INT8_C( 115),  INT8_C(   3), -INT8_C(  27) },
      {  INT8_C(  39), -INT8_C(  40),  INT8_C( 124),  INT8_C(   5), -INT8_C( 109),  INT8_C(  67),  INT8_C(  26),  INT8_C(  14),
         INT8_C(  94),  INT8_C(  36),  INT8_C(  40), -INT8_C(  79),  INT8_C( 121),  INT8_C( 120),  INT8_C(  39), -INT8_C(  64) },
      {  INT8_C(  97), -INT8_C(  20), -INT8_C(  82),  INT8_C(  22),  INT8_C( 110),  INT8_C(  64), -INT8_C( 120), -INT8_C( 125),
        -INT8_C(  94),  INT8_C(  85),  INT8_C( 124),  INT8_C(  65), -INT8_C(  55),      INT8_MAX,  INT8_C(  39), -INT8_C(  16) },
      {  INT8_C(  65), -INT8_C(   7), -INT8_C( 107), -INT8_C(  20),  INT8_C(  37), -INT8_C( 127),      INT8_MIN,  INT8_C( 126),
         INT8_C(  73),  INT8_C(  66), -INT8_C(  51),  INT8_C(  73), -INT8_C(  81),  INT8_C( 115),  INT8_C(   3), -INT8_C(  27) } },
    { {  INT8_C(  88), -INT8_C(  93), -INT8_C(  11), -INT8_C(  21), -INT8_C(  25),  INT8_C(  16), -INT8_C(   7),  INT8_C(  69),
         INT8_C(  52),  INT8_C(  34), -INT8_C(   9), -INT8_C(  83), -INT8_C( 102),  INT8_C(  30),  INT8_C( 110), -INT8_C(   5) },
      {  INT8_C(  10),  INT8_C(  28),  INT8_C(  17),  INT8_C( 120),  INT8_C(  92), -INT8_C( 102), -INT8_C(   4), -INT8_C(   2),
        -INT8_C(  17),  INT8_C( 120),  INT8_C(  63), -INT8_C(  72), -INT8_C(   8),  INT8_C( 102), -INT8_C(  87),  INT8_C(  80) },
      {  INT8_C(  10), -INT8_C(  98),  INT8_C(  59), -INT8_C(  15), -INT8_C(  82),  INT8_C(  52),  INT8_C(  54), -INT8_C(  29),
         INT8_C(  86),  INT8_C(  45), -INT8_C( 112), -INT8_C(  16),  INT8_C(  75), -INT8_C(   2), -INT8_C(  20),  INT8_C(  85) },
      {  INT8_C(  88), -INT8_C(  93), -INT8_C(  11), -INT8_C(  29), -INT8_C(  73), -INT8_C( 102),  INT8_C(  49),  INT8_C(  89),
        -INT8_C(  99),  INT8_C( 114), -INT8_C(  40), -INT8_C(  91),  INT8_C(  42),  INT8_C(  30),  INT8_C( 111), -INT8_C(   5) } },
    { {  INT8_C(  26), -INT8_C(   3), -INT8_C(  50),  INT8_C( 118), -INT8_C( 105), -INT8_C(  54),  INT8_C( 116), -INT8_C( 121),
         INT8_C(  66), -INT8_C(  76),  INT8_C(  63),  INT8_C(  58),  INT8_C(  26), -INT8_C(  24), -INT8_C( 118),  INT8_C(  36) },
      { -INT8_C( 121), -INT8_C(  59),  INT8_C(  21),  INT8_C(  53), -INT8_C(   6),  INT8_C(  76),  INT8_C(  24),  INT8_C(  80),
         INT8_C( 121), -INT8_C(  87),  INT8_C(  65), -INT8_C(  59), -INT8_C(  89),  INT8_C(  45),  INT8_C(  26), -INT8_C(  62) },
      {  INT8_C(  42), -INT8_C(  24),  INT8_C(  56), -INT8_C(  62), -INT8_C(  78), -INT8_C(  83),  INT8_C(  73), -INT8_C(  11),
         INT8_C(  97), -INT8_C( 120),  INT8_C(  47),  INT8_C( 123),  INT8_C( 113), -INT8_C(  70), -INT8_C(  96), -INT8_C(   8) },
      { -INT8_C(  97), -INT8_C(   8), -INT8_C(  53),  INT8_C(  67), -INT8_C(  33), -INT8_C( 118),  INT8_C( 100), -INT8_C( 121),
         INT8_C(  90), -INT8_C( 107),      INT8_MAX, -INT8_C(  66), -INT8_C( 100), -INT8_C(  19), -INT8_C( 112),  INT8_C(  38) } },
    { {      INT8_MAX, -INT8_C(  75),  INT8_C(  45),  INT8_C( 121),  INT8_C(   1),  INT8_C(  70), -INT8_C(  54),  INT8_C( 123),
        -INT8_C(  17),  INT8_C(  11),  INT8_C(  64), -INT8_C( 106),  INT8_C(  56),  INT8_C(  90),  INT8_C(  88),  INT8_C(  98) },
      {  INT8_C(  67), -INT8_C( 111),  INT8_C(  36), -INT8_C(  11),  INT8_C(  62),  INT8_C( 109), -INT8_C(  22), -INT8_C(  97),
        -INT8_C(  10),  INT8_C(  26),  INT8_C(  26),  INT8_C( 103), -INT8_C(  44), -INT8_C(  70),  INT8_C(  95),  INT8_C(  83) },
      {  INT8_C( 112), -INT8_C( 116), -INT8_C(  51),  INT8_C( 113), -INT8_C(  46), -INT8_C( 105), -INT8_C(  20), -INT8_C(  63),
        -INT8_C(  94),  INT8_C(  44),  INT8_C(  88), -INT8_C(  38), -INT8_C( 121), -INT8_C(  80),  INT8_C(  60), -INT8_C(  54) },
      {  INT8_C( 124), -INT8_C(  92),  INT8_C(  13), -INT8_C(   3),  INT8_C(  45),  INT8_C(  46), -INT8_C(  56),  INT8_C( 101),
        -INT8_C(  69),  INT8_C(  25),  INT8_C(  66), -INT8_C(  77),  INT8_C( 104),  INT8_C(  80),  INT8_C(  27),  INT8_C( 115) } },
    { {  INT8_C(  65),  INT8_C(  97), -INT8_C(  65),      INT8_MAX, -INT8_C(  50), -INT8_C(  86),  INT8_C(  30), -INT8_C(  60),
        -INT8_C(  60),  INT8_C(  57),  INT8_C(  43), -INT8_C( 104), -INT8_C(  13), -INT8_C( 118), -INT8_C(  21),  INT8_C(  99) },
      {  INT8_C(  23), -INT8_C(  72), -INT8_C(  43), -INT8_C(  23),  INT8_C(  79), -INT8_C(  63), -INT8_C(  85), -INT8_C(  15),
        -INT8_C(  18),  INT8_C(   3), -INT8_C(  53),  INT8_C( 117), -INT8_C(  77),  INT8_C(   8),  INT8_C(  63), -INT8_C(  11) },
      {  INT8_C( 105), -INT8_C(   2),  INT8_C( 116),  INT8_C(  55), -INT8_C(  88), -INT8_C( 109), -INT8_C(   4),  INT8_C( 108),
        -INT8_C(  52),  INT8_C(  39),  INT8_C(   4), -INT8_C(  65), -INT8_C(  78), -INT8_C(  16),  INT8_C(  35), -INT8_C(  55) },
      {  INT8_C(  87),  INT8_C(  97),  INT8_C(  62), -INT8_C(  73), -INT8_C( 119), -INT8_C(  22),  INT8_C(  29),  INT8_C(  85),
        -INT8_C(  26),  INT8_C(  57), -INT8_C(  32), -INT8_C(  40), -INT8_C(  14), -INT8_C( 126), -INT8_C(   9),  INT8_C(  87) } },
    { { -INT8_C(  88), -INT8_C(   8), -INT8_C(  78), -INT8_C(   8), -INT8_C(  71),  INT8_C(  93), -INT8_C(  23), -INT8_C(  89),
         INT8_C(  96), -INT8_C(  75),  INT8_C(  28),  INT8_C(  20), -INT8_C(  67),  INT8_C(  91),  INT8_C(   9),  INT8_C(  38) },
      {  INT8_C(  90),  INT8_C( 125),  INT8_C(  93),  INT8_C(   2),  INT8_C(  16),  INT8_C(  89),  INT8_C( 111), -INT8_C(  36),
        -INT8_C( 127),  INT8_C( 115), -INT8_C( 100),  INT8_C(  51),  INT8_C(  99), -INT8_C(  65), -INT8_C(   4),  INT8_C(  12) },
      { -INT8_C(  73), -INT8_C(  82),  INT8_C(   4),  INT8_C( 112),  INT8_C(  12), -INT8_C(  19),  INT8_C(  24),  INT8_C( 108),
        -INT8_C(  94),  INT8_C(  52),      INT8_MIN,  INT8_C(  95), -INT8_C( 112), -INT8_C( 119), -INT8_C( 123), -INT8_C(  22) },
      { -INT8_C(  32), -INT8_C(  87), -INT8_C(  21), -INT8_C(   6), -INT8_C(  87),  INT8_C(  77), -INT8_C( 114),  INT8_C(  55),
         INT8_C(  97), -INT8_C(  10),  INT8_C(   0),  INT8_C(  52), -INT8_C(  34),  INT8_C( 109),  INT8_C( 113),  INT8_C(  34) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16_t a = simde_vld1q_s8(test_vec[i].a);
    simde_int8x16_t b = simde_vld1q_s8(test_vec[i].b);
    simde_int8x16_t c = simde_vld1q_s8(test_vec[i].c);
    simde_int8x16_t r = simde_vbcaxq_s8(a, b, c);

    simde_test_arm_neon_assert_equal_i8x16(r, simde_vld1q_s8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x16_t a = simde_test_arm_neon_random_i8x16();
    simde_int8x16_t b = simde_test_arm_neon_random_i8x16();
    simde_int8x16_t c = simde_test_arm_neon_random_i8x16();
    simde_int8x16_t r = simde_vbcaxq_s8(a, b, c);

    simde_test_arm_neon_write_i8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x16(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vbcaxq_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[8];
    int16_t b[8];
    int16_t c[8];
    int16_t r[8];
  } test_vec[] = {
    { { -INT16_C( 10108),  INT16_C( 24521),  INT16_C( 13061), -INT16_C(  6982), -INT16_C( 11581),  INT16_C( 10359),  INT16_C( 13708), -INT16_C( 24168) },
      { -INT16_C( 20369),  INT16_C(  2103), -INT16_C( 14580),  INT16_C(  9322), -INT16_C( 11143), -INT16_C( 13105),  INT16_C( 15202), -INT16_C(  6404) },
      { -INT16_C( 14829),  INT16_C(  6469), -INT16_C(     7), -INT16_C( 17155),  INT16_C( 29906),  INT16_C( 24293),  INT16_C( 32170),  INT16_C(  6655) },
      { -INT16_C(  5912),  INT16_C( 24571),  INT16_C( 13057), -INT16_C(  6984),  INT16_C( 21226), -INT16_C( 22403),  INT16_C( 14284),  INT16_C( 18328) } },
    { {  INT16_C( 13869),  INT16_C( 14881), -INT16_C( 29699),  INT16_C( 30558),  INT16_C( 11615), -INT16_C( 16061),  INT16_C( 16233),  INT16_C( 31911) },
      { -INT16_C(  5115), -INT16_C(   363), -INT16_C( 27924), -INT16_C( 16709), -INT16_C( 24569), -INT16_C( 20196),  INT16_C(  7197),  INT16_C( 19402) },
      { -INT16_C(  5294),  INT16_C( 20613), -INT16_C(  7306), -INT16_C( 10809),  INT16_C(  2576),  INT16_C( 31126),  INT16_C( 15689),  INT16_C( 20470) },
      {  INT16_C( 12840), -INT16_C( 27599), -INT16_C( 25739),  INT16_C( 23910), -INT16_C( 29352),  INT16_C( 16715),  INT16_C( 16253),  INT16_C( 31919) } },
    { { -INT16_C( 29911),  INT16_C(  5453),  INT16_C(  2078),  INT16_C(  9683), -INT16_C(  3928), -INT16_C( 14634), -INT16_C( 24564),  INT16_C( 24081) },
      { -INT16_C( 26997),  INT16_C(   430),  INT16_C( 30073), -INT16_C( 30250),  INT16_C( 27775), -INT16_C( 14077), -INT16_C(  1623), -INT16_C( 11752) },
      {  INT16_C( 25988), -INT16_C( 23832), -INT16_C( 17554),  INT16_C(  5831), -INT16_C( 25173), -INT16_C( 18468), -INT16_C(  4803), -INT16_C( 14314) },
      {  INT16_C(  6434),  INT16_C(  5195),  INT16_C( 19471), -INT16_C( 21309), -INT16_C( 28420), -INT16_C( 28971), -INT16_C( 20340),  INT16_C( 19481) } },
    { { -INT16_C( 15229), -INT16_C(   823), -INT16_C( 24774), -INT16_C( 18042), -INT16_C( 30453), -INT16_C( 19326), -INT16_C( 25982),  INT16_C(  1671) },
      {  INT16_C( 28416),  INT16_C( 28329),  INT16_C( 28714), -INT16_C( 10620),  INT16_C( 24846),  INT16_C( 19341), -INT16_C( 23730), -INT16_C( 11756) },
      { -INT16_C(  8856), -INT16_C( 23858),  INT16_C( 21629), -INT16_C( 30629), -INT16_C(  8483),  INT16_C( 24381), -INT16_C( 15240),  INT16_C( 30822) },
      { -INT16_C(  6525), -INT16_C( 20248), -INT16_C( 16584), -INT16_C(  4350), -INT16_C( 22519), -INT16_C( 19454), -INT16_C( 18044), -INT16_C( 31593) } },
    { {  INT16_C(  3891),  INT16_C( 24038),  INT16_C( 27519), -INT16_C( 29389), -INT16_C( 15924),  INT16_C(  6873), -INT16_C(  4764), -INT16_C( 13076) },
      { -INT16_C( 17462),  INT16_C( 18286), -INT16_C( 13809), -INT16_C(  4656),  INT16_C(  3496),  INT16_C(  8268), -INT16_C( 19759),  INT16_C(  1177) },
      {  INT16_C( 32705),  INT16_C( 16737), -INT16_C( 27158), -INT16_C( 18738), -INT16_C( 22698), -INT16_C( 17711), -INT16_C( 17004),  INT16_C( 24455) },
      { -INT16_C( 28871),  INT16_C( 23528),  INT16_C(  8570), -INT16_C( 15325), -INT16_C( 13980),  INT16_C(  6869), -INT16_C(  4315), -INT16_C( 13068) } },
    { { -INT16_C(  2696), -INT16_C( 30554),  INT16_C( 30399),  INT16_C( 26485), -INT16_C( 15997),  INT16_C( 21640),  INT16_C(  8564),  INT16_C( 13656) },
      { -INT16_C( 17760), -INT16_C( 29834),  INT16_C( 17743), -INT16_C( 23231),  INT16_C(  4844), -INT16_C( 32417), -INT16_C(  6448),  INT16_C( 18656) },
      { -INT16_C( 31012), -INT16_C( 25648),  INT16_C( 17917), -INT16_C( 32765), -INT16_C( 29945),  INT16_C( 31701),  INT16_C( 11692),  INT16_C( 19632) },
      { -INT16_C( 12968), -INT16_C( 30592),  INT16_C( 30397),  INT16_C( 16949), -INT16_C( 11925), -INT16_C( 11134), -INT16_C(  7388),  INT16_C( 13592) } },
    { {  INT16_C( 10215),  INT16_C( 14039),  INT16_C(  6508),  INT16_C( 22747),  INT16_C( 15147), -INT16_C(  1063), -INT16_C( 18143), -INT16_C(   700) },
      {  INT16_C(  5184),  INT16_C( 15769), -INT16_C( 25510),  INT16_C( 25021), -INT16_C( 28121), -INT16_C( 11300), -INT16_C( 29504), -INT16_C( 22753) },
      { -INT16_C(  2125),  INT16_C(  8158), -INT16_C( 18160),  INT16_C( 15224),  INT16_C( 20980),  INT16_C(  5687),  INT16_C( 31499),  INT16_C( 19219) },
      {  INT16_C( 10151),  INT16_C(  5846),  INT16_C(  7462),  INT16_C(  6238), -INT16_C( 18136),  INT16_C( 14865),  INT16_C( 15841),  INT16_C( 22856) } },
    { { -INT16_C( 21361), -INT16_C(  5752),  INT16_C( 17736),  INT16_C( 28490),  INT16_C(  9944), -INT16_C( 26558),  INT16_C( 25267),  INT16_C( 26175) },
      {  INT16_C(  7513),  INT16_C( 27014), -INT16_C(   297), -INT16_C( 13404), -INT16_C(  9393),  INT16_C( 23265), -INT16_C(  2730), -INT16_C(  6491) },
      {  INT16_C( 11681), -INT16_C(  5425),  INT16_C(  6771),  INT16_C( 19289), -INT16_C( 25536), -INT16_C(  3101),  INT16_C(  8958),  INT16_C( 22362) },
      { -INT16_C( 17193), -INT16_C(  6008), -INT16_C( 24116), -INT16_C(  4114),  INT16_C( 26071), -INT16_C( 28606), -INT16_C( 18509), -INT16_C( 14694) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_int16x8_t b = simde_vld1q_s16(test_vec[i].b);
    simde_int16x8_t c = simde_vld1q_s16(test_vec[i].c);
    simde_int16x8_t r = simde_vbcaxq_s16(a, b, c);

    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x8_t a = simde_test_arm_neon_random_i16x8();
    simde_int16x8_t b = simde_test_arm_neon_random_i16x8();
    simde_int16x8_t c = simde_test_arm_neon_random_i16x8();
    simde_int16x8_t r = simde_vbcaxq_s16(a, b, c);

    simde_test_arm_neon_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vbcaxq_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[4];
    int32_t b[4];
    int32_t c[4];
    int32_t r[4];
  } test_vec[] = {
    { {  INT32_C(   441959548), -INT32_C(  1082363232), -INT32_C(   775652682),  INT32_C(    88517895) },
      { -INT32_C(  1172532840),  INT32_C(  1936342528),  INT32_C(   562456237),  INT32_C(  1720743402) },
      { -INT32_C(   645863623),  INT32_C(   261749849),  INT32_C(  2111855990), -INT32_C(  1551751670) },
      {  INT32_C(   944493820), -INT32_C(   820088672), -INT32_C(   775792577),  INT32_C(  1096219879) } },
    { { -INT32_C(  1218601289), -INT32_C(  1976907811),  INT32_C(   397127725),  INT32_C(  1585265445) },
      {  INT32_C(  2067332642),  INT32_C(  1904923130),  INT32_C(   971926062),  INT32_C(  1205629328) },
      { -INT32_C(   318883569),  INT32_C(   762783744), -INT32_C(    29089063), -INT32_C(  2141339298) },
      { -INT32_C(  1537386345), -INT32_C(   626911705),  INT32_C(   369227787),  INT32_C(   436013989) } },
    { { -INT32_C(  1157851713), -INT32_C(  1809086874), -INT32_C(  2117264911), -INT32_C(  1698059894) },
      { -INT32_C(   494483486), -INT32_C(   921698832),  INT32_C(  2126992160), -INT32_C(   721542123) },
      {  INT32_C(   529463993),  INT32_C(  1924446593),  INT32_C(  1576239571),  INT32_C(   234339371) },
      {  INT32_C(  1526501629),  INT32_C(   488686102), -INT32_C(  1547088943),  INT32_C(  1254205854) } },
    { {  INT32_C(  1961918084), -INT32_C(  1690435717),  INT32_C(  1746469971), -INT32_C(   499378135) },
      { -INT32_C(  1828533486),  INT32_C(  1459992196),  INT32_C(  1656092983),  INT32_C(   963685557) },
      { -INT32_C(  1498587094), -INT32_C(  1304303009),  INT32_C(   404380655), -INT32_C(  2047191181) },
      {  INT32_C(  1710421396), -INT32_C(   566629381),  INT32_C(   180134979), -INT32_C(   633556819) } },
    { { -INT32_C(  1508246494), -INT32_C(   352444750), -INT32_C(   850611433), -INT32_C(  1979270049) },
      {  INT32_C(  2083566620), -INT32_C(  1926336098),  INT32_C(  1067796940), -INT32_C(  1027235680) },
      {  INT32_C(  1332272796),  INT32_C(   339306236),  INT32_C(  2044822809),  INT32_C(  1577314114) },
      { -INT32_C(  1777738718),  INT32_C(  1677201328), -INT32_C(   884409389),  INT32_C(   180534527) } },
    { {  INT32_C(   987378587),  INT32_C(  1908869540), -INT32_C(   223318702), -INT32_C(  1447791347) },
      {  INT32_C(  1358437459), -INT32_C(  1671155325), -INT32_C(   116046409), -INT32_C(   933816276) },
      { -INT32_C(   268291509), -INT32_C(  1922971333),  INT32_C(  1132400950), -INT32_C(   621988985) },
      {  INT32_C(   975323019),  INT32_C(  1640184100),  INT32_C(  1253059027), -INT32_C(  1448706779) } },
    { { -INT32_C(   768940721), -INT32_C(   831549929),  INT32_C(    13075667), -INT32_C(   389538147) },
      { -INT32_C(  1948726704), -INT32_C(   904382061), -INT32_C(   770861237),  INT32_C(   447544010) },
      { -INT32_C(   135473184),  INT32_C(   969235301),  INT32_C(  2100923616), -INT32_C(    77266518) },
      { -INT32_C(   633672353),  INT32_C(   209170053), -INT32_C(  2101110824), -INT32_C(   398400291) } },
    { {  INT32_C(  1585856203), -INT32_C(  1037525129),  INT32_C(    26490422),  INT32_C(   270221616) },
      {  INT32_C(  2097612568),  INT32_C(  1136053347),  INT32_C(    62975832), -INT32_C(  1140972048) },
      { -INT32_C(   619019165),  INT32_C(  1520255523), -INT32_C(  1453641096), -INT32_C(  1950779789) },
      {  INT32_C(  2055421395), -INT32_C(  1022749897),  INT32_C(    51706678),  INT32_C(   542982320) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int32x4_t b = simde_vld1q_s32(test_vec[i].b);
    simde_int32x4_t c = simde_vld1q_s32(test_vec[i].c);
    simde_int32x4_t r = simde_vbcaxq_s32(a, b, c);
    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x4_t a = simde_test_arm_neon_random_i32x4();
    simde_int32x4_t b = simde_test_arm_neon_random_i32x4();
    simde_int32x4_t c = simde_test_arm_neon_random_i32x4();
    simde_int32x4_t r = simde_vbcaxq_s32(a, b, c);

    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vbcaxq_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a[2];
    int64_t b[2];
    int64_t c[2];
    int64_t r[2];
  } test_vec[] = {
    { { -INT64_C( 3462287186040434751), -INT64_C( 6674236485794349748) },
      { -INT64_C( 7346311981408679831), -INT64_C( 3463912364889816063) },
      {  INT64_C( 7132215360962795781),  INT64_C(  243440231280230517) },
      {  INT64_C( 6338671396723117993),  INT64_C( 8065235828269791564) } },
    { { -INT64_C(  419131661051670169), -INT64_C( 7884838071252822347) },
      { -INT64_C( 8827416939770062842),  INT64_C( 4941473388158975479) },
      {  INT64_C( 2370871884672170484), -INT64_C( 2667126228906711331) },
      {  INT64_C( 9166586562769604965), -INT64_C( 7597312535473205353) } },
    { {  INT64_C( 7450207711703513550),  INT64_C( 4437043204863796849) },
      {  INT64_C( 5804596152899365636), -INT64_C( 5249588681811266952) },
      {  INT64_C(   92035238734404463), -INT64_C( 3735768013344916064) },
      {  INT64_C( 4029723314214459854),  INT64_C( 1050358412707619881) } },
    { { -INT64_C( 2661405949511904946), -INT64_C( 1163251965499094469) },
      {  INT64_C(  790404184260112487),  INT64_C( 8711960772314613586) },
      {  INT64_C( 2858178190662705772), -INT64_C( 8898226534565031917) },
      { -INT64_C( 3224333911882661555), -INT64_C( 7512192597887627909) } },
    { { -INT64_C( 5185205139031764330), -INT64_C( 8909041346764603718) },
      { -INT64_C( 1013593732843072036), -INT64_C(  689603385379964466) },
      {  INT64_C( 1691666107933845851), -INT64_C( 2045663343242686977) },
      {  INT64_C( 6381195931554563602), -INT64_C( 8052793199924097350) } },
    { { -INT64_C( 4918887446392147987), -INT64_C( 6473902151140293934) },
      {  INT64_C( 2193782018283085565), -INT64_C( 5685562789407069138) },
      {  INT64_C( 3344267268526490561),  INT64_C( 2336391993931861883) },
      { -INT64_C( 6076382915880946735),  INT64_C( 3979007850838172374) } },
    { { -INT64_C( 2024953291481623641), -INT64_C( 5850683971459277992) },
      { -INT64_C(  108149598742295820),  INT64_C( 1087954012395069397) },
      { -INT64_C( 2910246201446788348), -INT64_C( 2634111105882671659) },
      { -INT64_C( 3781142192707167401), -INT64_C( 6141218958208052904) } },
    { {  INT64_C( 7678263069258862092), -INT64_C( 8718551596975107446) },
      {  INT64_C( 7450603676269336335),  INT64_C( 2762001909977536658) },
      { -INT64_C( 5303196179986284440),  INT64_C( 6098061109219608982) },
      {  INT64_C( 3138506483015915787), -INT64_C( 6533197377100889462) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);
    simde_int64x2_t b = simde_vld1q_s64(test_vec[i].b);
    simde_int64x2_t c = simde_vld1q_s64(test_vec[i].c);
    simde_int64x2_t r = simde_vbcaxq_s64(a, b, c);
    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int64x2_t a = simde_test_arm_neon_random_i64x2();
    simde_int64x2_t b = simde_test_arm_neon_random_i64x2();
    simde_int64x2_t c = simde_test_arm_neon_random_i64x2();
    simde_int64x2_t r = simde_vbcaxq_s64(a, b, c);

    simde_test_arm_neon_write_i64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x2(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}


SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vbcaxq_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vbcaxq_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vbcaxq_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vbcaxq_u64)
SIMDE_TEST_FUNC_LIST_ENTRY(vbcaxq_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vbcaxq_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vbcaxq_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vbcaxq_s64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
