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
    { { UINT8_C(130), UINT8_C(201), UINT8_C( 75), UINT8_C( 31), UINT8_C(106), UINT8_C(122), UINT8_C(251), UINT8_C( 26),
        UINT8_C( 25), UINT8_C( 12), UINT8_C(244), UINT8_C(138), UINT8_C(155), UINT8_C( 12), UINT8_C(159), UINT8_C(161) },
      { UINT8_C(176), UINT8_C(104), UINT8_C( 72), UINT8_C( 90), UINT8_C(127), UINT8_C(139), UINT8_C( 93), UINT8_C(168),
        UINT8_C(127), UINT8_C(150), UINT8_C(105), UINT8_C(120), UINT8_C( 65), UINT8_C(222), UINT8_C( 89), UINT8_C(195) },
      { UINT8_C(167), UINT8_C(165), UINT8_C(226), UINT8_C( 17), UINT8_C( 31), UINT8_C(222), UINT8_C( 43), UINT8_C( 56),
        UINT8_C(234), UINT8_C( 32), UINT8_C(194), UINT8_C(133), UINT8_C( 44), UINT8_C( 97), UINT8_C( 38), UINT8_C(220) },
      { UINT8_C(165), UINT8_C( 36), UINT8_C(225), UINT8_C( 20), UINT8_C( 31), UINT8_C(174), UINT8_C(137), UINT8_C( 42),
        UINT8_C(234), UINT8_C( 40), UINT8_C( 86), UINT8_C(  7), UINT8_C(182), UINT8_C( 97), UINT8_C(160), UINT8_C(252) } },
    { { UINT8_C(202), UINT8_C(110), UINT8_C( 54), UINT8_C( 73), UINT8_C(249), UINT8_C(147), UINT8_C(241), UINT8_C(120),
        UINT8_C( 41), UINT8_C( 90), UINT8_C(240), UINT8_C(106), UINT8_C( 56), UINT8_C( 73), UINT8_C( 45), UINT8_C(224) },
      { UINT8_C(238), UINT8_C( 16), UINT8_C(241), UINT8_C( 13), UINT8_C(238), UINT8_C( 29), UINT8_C( 70), UINT8_C(216),
        UINT8_C( 61), UINT8_C(  8), UINT8_C( 93), UINT8_C(105), UINT8_C(106), UINT8_C(131), UINT8_C( 69), UINT8_C( 52) },
      { UINT8_C(241), UINT8_C(123), UINT8_C(125), UINT8_C(234), UINT8_C( 14), UINT8_C(111), UINT8_C( 98), UINT8_C( 55),
        UINT8_C(201), UINT8_C( 82), UINT8_C(161), UINT8_C(  2), UINT8_C(155), UINT8_C(206), UINT8_C(226), UINT8_C(138) },
      { UINT8_C(241), UINT8_C( 21), UINT8_C(123), UINT8_C(170), UINT8_C( 31), UINT8_C(237), UINT8_C(211), UINT8_C( 23),
        UINT8_C(201), UINT8_C(  0), UINT8_C(  1), UINT8_C(  0), UINT8_C(139), UINT8_C(134), UINT8_C(202), UINT8_C( 74) } },
    { { UINT8_C(222), UINT8_C(211), UINT8_C(151), UINT8_C(204), UINT8_C(240), UINT8_C(221), UINT8_C(164), UINT8_C( 45),
        UINT8_C(230), UINT8_C(  1), UINT8_C(150), UINT8_C( 80), UINT8_C(132), UINT8_C(219), UINT8_C(132), UINT8_C(117) },
      { UINT8_C( 86), UINT8_C(  1), UINT8_C( 95), UINT8_C(100), UINT8_C(112), UINT8_C(193), UINT8_C(155), UINT8_C( 58),
        UINT8_C( 19), UINT8_C( 60), UINT8_C( 60), UINT8_C(175), UINT8_C( 11), UINT8_C( 30), UINT8_C( 57), UINT8_C(233) },
      { UINT8_C(241), UINT8_C(208), UINT8_C(182), UINT8_C(226), UINT8_C(174), UINT8_C( 90), UINT8_C( 15), UINT8_C(148),
        UINT8_C( 92), UINT8_C(166), UINT8_C(228), UINT8_C(224), UINT8_C(129), UINT8_C(104), UINT8_C( 86), UINT8_C(216) },
      { UINT8_C(121), UINT8_C(  2), UINT8_C( 54), UINT8_C(106), UINT8_C( 46), UINT8_C( 70), UINT8_C( 43), UINT8_C(145),
        UINT8_C(184), UINT8_C(167), UINT8_C(102), UINT8_C(176), UINT8_C(  5), UINT8_C(169), UINT8_C(210), UINT8_C(204) } },
    { { UINT8_C(105), UINT8_C(181), UINT8_C( 60), UINT8_C(218), UINT8_C(119), UINT8_C(216), UINT8_C( 20), UINT8_C(138),
        UINT8_C( 20), UINT8_C( 80), UINT8_C( 57), UINT8_C( 31), UINT8_C(110), UINT8_C(114), UINT8_C(  9), UINT8_C( 95) },
      { UINT8_C( 67), UINT8_C(191), UINT8_C( 65), UINT8_C(241), UINT8_C( 25), UINT8_C( 81), UINT8_C(133), UINT8_C(117),
        UINT8_C(247), UINT8_C(105), UINT8_C( 86), UINT8_C(120), UINT8_C(209), UINT8_C(172), UINT8_C( 80), UINT8_C( 58) },
      { UINT8_C( 97), UINT8_C(141), UINT8_C( 20), UINT8_C(216), UINT8_C(101), UINT8_C( 40), UINT8_C( 99), UINT8_C(121),
        UINT8_C(120), UINT8_C(156), UINT8_C(153), UINT8_C(230), UINT8_C( 15), UINT8_C(162), UINT8_C( 70), UINT8_C( 82) },
      { UINT8_C( 73), UINT8_C(141), UINT8_C( 40), UINT8_C(210), UINT8_C(  3), UINT8_C(160), UINT8_C(115), UINT8_C(243),
        UINT8_C(120), UINT8_C(140), UINT8_C(176), UINT8_C(225), UINT8_C( 33), UINT8_C(240), UINT8_C( 79), UINT8_C( 23) } },
    { { UINT8_C( 97), UINT8_C(135), UINT8_C( 67), UINT8_C(122), UINT8_C(216), UINT8_C(200), UINT8_C(240), UINT8_C(207),
        UINT8_C( 49), UINT8_C( 70), UINT8_C( 72), UINT8_C(  2), UINT8_C(242), UINT8_C(152), UINT8_C( 60), UINT8_C( 83) },
      { UINT8_C( 37), UINT8_C( 81), UINT8_C( 44), UINT8_C(138), UINT8_C(121), UINT8_C(143), UINT8_C(  4), UINT8_C(242),
        UINT8_C( 43), UINT8_C(157), UINT8_C(216), UINT8_C( 58), UINT8_C( 63), UINT8_C( 30), UINT8_C(140), UINT8_C(160) },
      { UINT8_C(166), UINT8_C(207), UINT8_C( 26), UINT8_C(126), UINT8_C(151), UINT8_C( 10), UINT8_C( 78), UINT8_C(200),
        UINT8_C( 80), UINT8_C(150), UINT8_C(202), UINT8_C( 66), UINT8_C( 46), UINT8_C(  7), UINT8_C(150), UINT8_C( 84) },
      { UINT8_C(230), UINT8_C( 73), UINT8_C( 89), UINT8_C( 14), UINT8_C( 23), UINT8_C( 74), UINT8_C(190), UINT8_C(197),
        UINT8_C( 64), UINT8_C(212), UINT8_C(202), UINT8_C( 66), UINT8_C(238), UINT8_C(135), UINT8_C(166), UINT8_C(  7) } },
    { { UINT8_C( 88), UINT8_C(194), UINT8_C(222), UINT8_C(209), UINT8_C( 81), UINT8_C(226), UINT8_C(195), UINT8_C(124),
        UINT8_C(127), UINT8_C(156), UINT8_C(183), UINT8_C(190), UINT8_C(186), UINT8_C( 67), UINT8_C( 94), UINT8_C( 96) },
      { UINT8_C( 19), UINT8_C(121), UINT8_C(223), UINT8_C(170), UINT8_C(131), UINT8_C( 45), UINT8_C(115), UINT8_C(212),
        UINT8_C(195), UINT8_C( 61), UINT8_C( 22), UINT8_C(241), UINT8_C( 68), UINT8_C(172), UINT8_C( 69), UINT8_C(156) },
      { UINT8_C(110), UINT8_C( 36), UINT8_C(110), UINT8_C(191), UINT8_C(  6), UINT8_C( 49), UINT8_C( 60), UINT8_C(134),
        UINT8_C(205), UINT8_C(243), UINT8_C( 68), UINT8_C(136), UINT8_C( 54), UINT8_C(163), UINT8_C(232), UINT8_C( 73) },
      { UINT8_C( 38), UINT8_C(166), UINT8_C(110), UINT8_C(238), UINT8_C( 86), UINT8_C(243), UINT8_C(188), UINT8_C(174),
        UINT8_C(241), UINT8_C(115), UINT8_C(229), UINT8_C(134), UINT8_C(140), UINT8_C(224), UINT8_C(242), UINT8_C( 41) } },
    { { UINT8_C( 28), UINT8_C(199), UINT8_C(244), UINT8_C(159), UINT8_C(244), UINT8_C(103), UINT8_C(115), UINT8_C(183),
        UINT8_C(164), UINT8_C(138), UINT8_C(169), UINT8_C(233), UINT8_C( 54), UINT8_C(238), UINT8_C(133), UINT8_C(165) },
      { UINT8_C( 18), UINT8_C(243), UINT8_C(100), UINT8_C( 25), UINT8_C( 37), UINT8_C(160), UINT8_C(159), UINT8_C(242),
        UINT8_C(147), UINT8_C(227), UINT8_C(122), UINT8_C(202), UINT8_C(134), UINT8_C( 99), UINT8_C( 19), UINT8_C(162) },
      { UINT8_C( 42), UINT8_C(  7), UINT8_C( 66), UINT8_C( 31), UINT8_C(110), UINT8_C(181), UINT8_C(214), UINT8_C( 19),
        UINT8_C( 63), UINT8_C(127), UINT8_C(252), UINT8_C(118), UINT8_C(110), UINT8_C(129), UINT8_C( 27), UINT8_C(128) },
      { UINT8_C( 38), UINT8_C(  3), UINT8_C(210), UINT8_C(153), UINT8_C(190), UINT8_C(242), UINT8_C(182), UINT8_C( 22),
        UINT8_C( 27), UINT8_C(119), UINT8_C(125), UINT8_C( 87), UINT8_C( 94), UINT8_C( 13), UINT8_C(159), UINT8_C(133) } },
    { { UINT8_C(117), UINT8_C(127), UINT8_C(153), UINT8_C(154), UINT8_C( 32), UINT8_C( 56), UINT8_C(140), UINT8_C(179),
        UINT8_C( 28), UINT8_C(  7), UINT8_C(125), UINT8_C(162), UINT8_C(106), UINT8_C(145), UINT8_C( 69), UINT8_C(148) },
      { UINT8_C(152), UINT8_C(135), UINT8_C(179), UINT8_C(  7), UINT8_C( 60), UINT8_C(138), UINT8_C( 26), UINT8_C(124),
        UINT8_C(  9), UINT8_C( 22), UINT8_C(242), UINT8_C(119), UINT8_C(151), UINT8_C( 13), UINT8_C(248), UINT8_C( 12) },
      { UINT8_C(140), UINT8_C(145), UINT8_C(166), UINT8_C(172), UINT8_C(202), UINT8_C( 51), UINT8_C( 96), UINT8_C(230),
        UINT8_C( 58), UINT8_C(221), UINT8_C(136), UINT8_C(164), UINT8_C(110), UINT8_C(205), UINT8_C( 56), UINT8_C(  7) },
      { UINT8_C(233), UINT8_C(233), UINT8_C(174), UINT8_C( 52), UINT8_C(202), UINT8_C(  3), UINT8_C(228), UINT8_C(101),
        UINT8_C( 46), UINT8_C(220), UINT8_C(133), UINT8_C( 36), UINT8_C(  6), UINT8_C( 93), UINT8_C( 61), UINT8_C(151) } }
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
    { { UINT16_C(33043), UINT16_C( 9782), UINT16_C(27130), UINT16_C(10084), UINT16_C(35351), UINT16_C(26188), UINT16_C(48253), UINT16_C(39169) },
      { UINT16_C( 4827), UINT16_C(50714), UINT16_C(30917), UINT16_C(13976), UINT16_C(52506), UINT16_C(55775), UINT16_C(32943), UINT16_C(49770) },
      { UINT16_C(40961), UINT16_C(64488), UINT16_C(19721), UINT16_C( 8483), UINT16_C(28631), UINT16_C(21639), UINT16_C(35115), UINT16_C( 1773) },
      { UINT16_C( 8449), UINT16_C(56268), UINT16_C(19507), UINT16_C( 8263), UINT16_C(28114), UINT16_C(29319), UINT16_C(46459), UINT16_C( 8172) } },
    { { UINT16_C( 1947), UINT16_C(24781), UINT16_C(25984), UINT16_C(39574), UINT16_C(30258), UINT16_C(57715), UINT16_C(56822), UINT16_C(63396) },
      { UINT16_C(35965), UINT16_C(34546), UINT16_C( 5593), UINT16_C(45223), UINT16_C(12164), UINT16_C(44804), UINT16_C(61880), UINT16_C(21430) },
      { UINT16_C(33785), UINT16_C(31155), UINT16_C(18920), UINT16_C( 6675), UINT16_C(34495), UINT16_C(46587), UINT16_C(40803), UINT16_C(57516) },
      { UINT16_C(32891), UINT16_C( 6590), UINT16_C(10728), UINT16_C( 4099), UINT16_C(54925), UINT16_C(62856), UINT16_C(37669), UINT16_C(17580) } },
    { { UINT16_C(40748), UINT16_C( 1382), UINT16_C( 3764), UINT16_C(14774), UINT16_C(47677), UINT16_C(62952), UINT16_C(40620), UINT16_C(42312) },
      { UINT16_C(64289), UINT16_C( 2334), UINT16_C(12612), UINT16_C( 1059), UINT16_C( 8119), UINT16_C( 6841), UINT16_C(26302), UINT16_C(60154) },
      { UINT16_C(24581), UINT16_C(47600), UINT16_C(42606), UINT16_C(44018), UINT16_C(56160), UINT16_C( 3232), UINT16_C(59513), UINT16_C(39857) },
      { UINT16_C(25609), UINT16_C(48528), UINT16_C(43230), UINT16_C(37478), UINT16_C(31592), UINT16_C(59872), UINT16_C(28793), UINT16_C(40625) } },
    { { UINT16_C(53219), UINT16_C(10404), UINT16_C(51200), UINT16_C(46892), UINT16_C(58855), UINT16_C(42449), UINT16_C(52043), UINT16_C(20624) },
      { UINT16_C(32812), UINT16_C(39434), UINT16_C(64550), UINT16_C(34374), UINT16_C(59095), UINT16_C(20883), UINT16_C(17615), UINT16_C(45804) },
      { UINT16_C(36884), UINT16_C( 5338), UINT16_C( 1624), UINT16_C(16332), UINT16_C(40428), UINT16_C(14309), UINT16_C(30057), UINT16_C(38280) },
      { UINT16_C(57303), UINT16_C(13438), UINT16_C( 1624), UINT16_C( 3812), UINT16_C(40140), UINT16_C(37797), UINT16_C(65129), UINT16_C(54680) } },
    { { UINT16_C(37621), UINT16_C( 6959), UINT16_C(30094), UINT16_C(26273), UINT16_C(13404), UINT16_C(11191), UINT16_C(41849), UINT16_C(36317) },
      { UINT16_C(47155), UINT16_C(36001), UINT16_C(28094), UINT16_C(43723), UINT16_C(45067), UINT16_C(29922), UINT16_C(27173), UINT16_C( 6665) },
      { UINT16_C(14588), UINT16_C(35381), UINT16_C(55214), UINT16_C( 2800), UINT16_C(42763), UINT16_C(33845), UINT16_C( 4682), UINT16_C(32273) },
      { UINT16_C(14904), UINT16_C(39227), UINT16_C(51118), UINT16_C(20176), UINT16_C(41823), UINT16_C(36640), UINT16_C(37650), UINT16_C(64453) } },
    { { UINT16_C(46026), UINT16_C(35082), UINT16_C(54560), UINT16_C(11059), UINT16_C( 5510), UINT16_C(43935), UINT16_C(43135), UINT16_C(31686) },
      { UINT16_C(64481), UINT16_C(36614), UINT16_C(63186), UINT16_C(56985), UINT16_C(52894), UINT16_C(59490), UINT16_C(29920), UINT16_C(43878) },
      { UINT16_C(28711), UINT16_C(18228), UINT16_C(26438), UINT16_C(52339), UINT16_C( 4733), UINT16_C(64631), UINT16_C(15803), UINT16_C(40056) },
      { UINT16_C(28717), UINT16_C(18236), UINT16_C(26214), UINT16_C(60753), UINT16_C(  893), UINT16_C(65514), UINT16_C(46500), UINT16_C(52472) } },
    { { UINT16_C(32313), UINT16_C( 2859), UINT16_C(50292), UINT16_C( 4841), UINT16_C(19602), UINT16_C(29435), UINT16_C(25024), UINT16_C(59165) },
      { UINT16_C(20946), UINT16_C( 6190), UINT16_C(41401), UINT16_C(14052), UINT16_C(23476), UINT16_C(28466), UINT16_C(43673), UINT16_C(53771) },
      { UINT16_C(13864), UINT16_C(40413), UINT16_C(51194), UINT16_C(36015), UINT16_C(43539), UINT16_C(54270), UINT16_C( 7180), UINT16_C(57018) },
      { UINT16_C( 6145), UINT16_C(40668), UINT16_C(33726), UINT16_C(36006), UINT16_C(44561), UINT16_C(49975), UINT16_C(23884), UINT16_C(64430) } },
    { { UINT16_C(59501), UINT16_C( 9974), UINT16_C(55946), UINT16_C(15964), UINT16_C(36661), UINT16_C(52909), UINT16_C(47161), UINT16_C(25248) },
      { UINT16_C(32494), UINT16_C(59647), UINT16_C(44613), UINT16_C(22644), UINT16_C(29273), UINT16_C(25899), UINT16_C(58766), UINT16_C(64579) },
      { UINT16_C(14797), UINT16_C(22306), UINT16_C(32531), UINT16_C(18581), UINT16_C(16910), UINT16_C(18199), UINT16_C(47098), UINT16_C(59561) },
      { UINT16_C(47564), UINT16_C(20770), UINT16_C(12185), UINT16_C(28317), UINT16_C(53034), UINT16_C(52627), UINT16_C(45003), UINT16_C(59913) } }

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
    { { UINT32_C( 898313932), UINT32_C( 944943577), UINT32_C(  91939849), UINT32_C(3545404143) },
      { UINT32_C(2540152340), UINT32_C(2139185394), UINT32_C(1445886815), UINT32_C(4177787949) },
      { UINT32_C(  53382698), UINT32_C(1211859007), UINT32_C(1414378852), UINT32_C(1546100552) },
      { UINT32_C( 598116066), UINT32_C(1214845238), UINT32_C(1427976548), UINT32_C(1584897418) } },
    { { UINT32_C( 938708549), UINT32_C(1320580591), UINT32_C( 497346032), UINT32_C( 186034145) },
      { UINT32_C(1963934773), UINT32_C( 683494084), UINT32_C(1216088832), UINT32_C(4037321898) },
      { UINT32_C( 556242994), UINT32_C(4252032525), UINT32_C(2753172675), UINT32_C(4054790332) },
      { UINT32_C( 601297522), UINT32_C(3144870694), UINT32_C(2979721267), UINT32_C(4206703613) } },
    { { UINT32_C( 946257524), UINT32_C( 157295625), UINT32_C(3646020911), UINT32_C(3016357249) },
      { UINT32_C(2597712269), UINT32_C(2459387343), UINT32_C( 355905881), UINT32_C(1426580961) },
      { UINT32_C(2911727012), UINT32_C(3233214097), UINT32_C(1285162955), UINT32_C(2331993084) },
      { UINT32_C(2377081812), UINT32_C(3386298001), UINT32_C(2228964333), UINT32_C( 674722812) } },
    { { UINT32_C( 589616212), UINT32_C(1941290009), UINT32_C(1334373229), UINT32_C(1973718993) },
      { UINT32_C(2384605949), UINT32_C(3947878432), UINT32_C(3677874655), UINT32_C(2707764812) },
      { UINT32_C( 616860171), UINT32_C(3013048902), UINT32_C( 906109029), UINT32_C(2896930735) },
      { UINT32_C(  96488971), UINT32_C(2737266271), UINT32_C( 847913541), UINT32_C(4163579454) } },
    { { UINT32_C(4181446105), UINT32_C(2229570213), UINT32_C(3210746739), UINT32_C(1549845841) },
      { UINT32_C(2508268879), UINT32_C(  71899295), UINT32_C(3896199992), UINT32_C(3415533298) },
      { UINT32_C(1506070452), UINT32_C(3437144153), UINT32_C( 361512643), UINT32_C(1399974915) },
      { UINT32_C( 838731556), UINT32_C(1283074681), UINT32_C(  46935680), UINT32_C(1192357122) } },
    { { UINT32_C(2968056337), UINT32_C(1135948043), UINT32_C(1865150589), UINT32_C(2319171798) },
      { UINT32_C(3924098959), UINT32_C(1807073960), UINT32_C(  58736896), UINT32_C(1062662702) },
      { UINT32_C(4025499620), UINT32_C(3979584880), UINT32_C(1801281173), UINT32_C(2935396382) },
      { UINT32_C(4294459380), UINT32_C(3979580531), UINT32_C( 125234920), UINT32_C( 786405582) } },
    { { UINT32_C(1066916503), UINT32_C(2628471964), UINT32_C(3164547982), UINT32_C(  50066973) },
      { UINT32_C(2784095029), UINT32_C( 630400144), UINT32_C(2710696067), UINT32_C( 525305736) },
      { UINT32_C(4250920545), UINT32_C(3248032307), UINT32_C(1400715317), UINT32_C(1666545710) },
      { UINT32_C(3881432803), UINT32_C(1504789055), UINT32_C(1332949817), UINT32_C(1675954235) } },
    { { UINT32_C(4094248548), UINT32_C(3994721387), UINT32_C( 344959884), UINT32_C(2469650226) },
      { UINT32_C(4170224325), UINT32_C(3535350172), UINT32_C(2418357857), UINT32_C( 334723759) },
      { UINT32_C( 721943744), UINT32_C( 605626776), UINT32_C(4265126348), UINT32_C(1301376136) },
      { UINT32_C( 789493984), UINT32_C( 136033787), UINT32_C(4205977664), UINT32_C(3448891800) } }
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
    { { UINT64_C( 3850654609092713541), UINT64_C( 5879376381347721284) },
      { UINT64_C(12594968345305323560), UINT64_C( 5510114594776519030) },
      { UINT64_C(12836907582415907321), UINT64_C( 1749772631174361675) },
      { UINT64_C( 4159713514994633797), UINT64_C( 1558300082217808240) } },
    { { UINT64_C( 5021942183645380104), UINT64_C(16170582274016414230) },
      { UINT64_C(18139362056297567387), UINT64_C(  877983142104896552) },
      { UINT64_C( 9713348982059494072), UINT64_C(15317038349108365258) },
      { UINT64_C( 4360264332515961355), UINT64_C(16737420083334879798) } },
    { { UINT64_C( 9118830843100226017), UINT64_C( 8015498827397496108) },
      { UINT64_C(15322866655939676848), UINT64_C( 4005413480479148425) },
      { UINT64_C( 3984652179989885815), UINT64_C( 6338996415484125906) },
      { UINT64_C(13703638200041040225), UINT64_C( 5709106269627249701) } },
    { { UINT64_C( 4236792895857225454), UINT64_C(16065346369505481061) },
      { UINT64_C(16305835574276373254), UINT64_C( 4816709016072466905) },
      { UINT64_C(15076651238499700561), UINT64_C(15104088862857443415) },
      { UINT64_C( 1769050029042327272), UINT64_C(15903319089018228973) } },
    { { UINT64_C( 1814155974779553851), UINT64_C( 5509436142369020126) },
      { UINT64_C( 1008676257108242370), UINT64_C( 5214719821652724929) },
      { UINT64_C( 5479123103899664816), UINT64_C(15537968561870840665) },
      { UINT64_C( 1791066711528564345), UINT64_C( 4912155005795603550) } },
    { { UINT64_C( 4208338395543760803), UINT64_C( 5541157741839987601) },
      { UINT64_C(10673888710832716134), UINT64_C( 4095331808683073768) },
      { UINT64_C( 8155448140985653882), UINT64_C( 9228989552474977323) },
      { UINT64_C(13719935173622615719), UINT64_C( 8368302870585881425) } },
    { { UINT64_C( 8952442015150591854), UINT64_C( 3090400290004346391) },
      { UINT64_C(11058953291644630313), UINT64_C(17066799245104810047) },
      { UINT64_C(13534111433470848706), UINT64_C(14110704085592656888) },
      { UINT64_C( 8940911750109011527), UINT64_C(  498632740761609744) } },
    { { UINT64_C( 8918892232527573183), UINT64_C( 6572913055084324557) },
      { UINT64_C(10825390846085549275), UINT64_C(12406029305581052622) },
      { UINT64_C(  700484823140660994), UINT64_C( 1493377829962026181) },
      { UINT64_C(17133177020149921894), UINT64_C(17525121733923570887) } }
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
    { {  INT8_C(  87),  INT8_C( 106), -INT8_C( 108), -INT8_C(  11), -INT8_C(  19), -INT8_C(  49), -INT8_C( 117), -INT8_C(  69),
         INT8_C( 113), -INT8_C(  54),  INT8_C(  36),  INT8_C(  93), -INT8_C(  37),  INT8_C(  79),  INT8_C(   9), -INT8_C(  35) },
      {  INT8_C(  70), -INT8_C(  30),  INT8_C(  27), -INT8_C( 126), -INT8_C( 127), -INT8_C(  45), -INT8_C( 116),  INT8_C(  70),
         INT8_C(  96), -INT8_C(  32), -INT8_C(  92), -INT8_C( 103),  INT8_C( 108),  INT8_C(  93), -INT8_C(  82), -INT8_C(  61) },
      { -INT8_C(  57),  INT8_C(  66), -INT8_C(  71), -INT8_C(  76),  INT8_C(  17),  INT8_C(  68),  INT8_C( 112), -INT8_C( 126),
         INT8_C(  14), -INT8_C( 108), -INT8_C(  33), -INT8_C(  22), -INT8_C(  29), -INT8_C(  23), -INT8_C(  57),  INT8_C(  42) },
      {  INT8_C(  87), -INT8_C(  54), -INT8_C( 106), -INT8_C(   9),  INT8_C( 109),  INT8_C(  92),  INT8_C(   7), -INT8_C(   1),
         INT8_C(  17), -INT8_C(  86),  INT8_C(   4),  INT8_C(  76), -INT8_C(  41),  INT8_C(  91),  INT8_C(  33),  INT8_C(  28) } },
    { { -INT8_C(  53), -INT8_C(  30), -INT8_C(  84),  INT8_C(  77), -INT8_C(  74),  INT8_C(  56), -INT8_C( 109),  INT8_C(  22),
         INT8_C(  25),  INT8_C(  56), -INT8_C(  81), -INT8_C( 123), -INT8_C( 107),  INT8_C(  93),  INT8_C(  72),  INT8_C(  93) },
      { -INT8_C(  97),  INT8_C(   1),  INT8_C(  17), -INT8_C(  80),  INT8_C(  70), -INT8_C( 127),  INT8_C(  50),  INT8_C(  84),
         INT8_C(  21),  INT8_C(  18),  INT8_C(  62), -INT8_C(   7), -INT8_C(   5),  INT8_C(   6),  INT8_C(  35), -INT8_C(  58) },
      { -INT8_C(  24), -INT8_C(  49),  INT8_C(  19), -INT8_C(  98),  INT8_C(   8), -INT8_C(  89), -INT8_C(  76),  INT8_C(  33),
        -INT8_C(  33),  INT8_C( 100), -INT8_C(  90),  INT8_C( 116), -INT8_C(  63), -INT8_C(  18), -INT8_C(  47),  INT8_C(  97) },
      { -INT8_C(  36), -INT8_C(  30), -INT8_C(  84),  INT8_C( 109), -INT8_C(  16),  INT8_C(  56), -INT8_C( 111),  INT8_C(  66),
         INT8_C(  25),  INT8_C(  42), -INT8_C(  73),  INT8_C(  12), -INT8_C(  81),  INT8_C(  93),  INT8_C( 106), -INT8_C(  37) } },
    { { -INT8_C(  16), -INT8_C(  29),  INT8_C(  17),  INT8_C(  54),  INT8_C( 100),  INT8_C(  68), -INT8_C( 118),  INT8_C( 122),
         INT8_C(  86), -INT8_C(  55),  INT8_C( 115),  INT8_C(  81), -INT8_C(  49), -INT8_C( 106),  INT8_C(  23), -INT8_C(  73) },
      {  INT8_C( 101),  INT8_C(  43),  INT8_C(  86),  INT8_C( 109), -INT8_C(  46),  INT8_C(  10), -INT8_C( 114), -INT8_C(  79),
         INT8_C( 110),  INT8_C(  52),  INT8_C(  37),  INT8_C(  48),  INT8_C(  35), -INT8_C(   9), -INT8_C( 111),  INT8_C(  19) },
      { -INT8_C(  38), -INT8_C(  94),  INT8_C(  73),  INT8_C(  62), -INT8_C(  26), -INT8_C(  45), -INT8_C(  72),  INT8_C(  60),
        -INT8_C( 100),  INT8_C(  43), -INT8_C( 115),  INT8_C( 107), -INT8_C(  63), -INT8_C(  91),  INT8_C(  35),  INT8_C(  39) },
      { -INT8_C(  43), -INT8_C(  22),  INT8_C(   7),  INT8_C( 119),  INT8_C( 116),  INT8_C(  76), -INT8_C( 116), -INT8_C(   5),
         INT8_C(  52), -INT8_C(  35),  INT8_C(  83),  INT8_C(  65), -INT8_C(  19), -INT8_C(  60), -INT8_C( 121), -INT8_C(  89) } },
    { { -INT8_C(  48),  INT8_C( 121), -INT8_C( 108), -INT8_C(  94), -INT8_C( 125),  INT8_C(  35),  INT8_C(  83), -INT8_C(  14),
         INT8_C(  87),  INT8_C( 120),  INT8_C(  34),  INT8_C( 122),  INT8_C( 111), -INT8_C(  77), -INT8_C( 115),  INT8_C(  73) },
      {  INT8_C(  85), -INT8_C(  42), -INT8_C( 120),  INT8_C(  60), -INT8_C(  86),  INT8_C(  64),  INT8_C( 120),  INT8_C(  70),
         INT8_C( 108),  INT8_C(   6), -INT8_C(  78),  INT8_C(  45), -INT8_C(  85), -INT8_C(  43),  INT8_C(  84),  INT8_C( 123) },
      {  INT8_C(  78), -INT8_C(  23),  INT8_C(  29), -INT8_C(  47),  INT8_C(  12),  INT8_C( 112), -INT8_C(  61),  INT8_C(  99),
        -INT8_C(  24), -INT8_C(  27), -INT8_C(  34),  INT8_C(  88), -INT8_C( 104),  INT8_C( 107), -INT8_C(  95), -INT8_C(  18) },
      { -INT8_C(  63),  INT8_C( 111),  INT8_C(  20), -INT8_C( 114),  INT8_C(  33),  INT8_C(  35),  INT8_C( 107), -INT8_C(  10),
         INT8_C(  83),  INT8_C( 122),  INT8_C(   2),  INT8_C(  95),  INT8_C(  76),  INT8_C(  39), -INT8_C(  39),  INT8_C(  88) } },
    { {  INT8_C(  66),  INT8_C(  41),  INT8_C(  42), -INT8_C(  20),  INT8_C( 106), -INT8_C(  94),  INT8_C(  50), -INT8_C(  42),
        -INT8_C(  88), -INT8_C(  28),  INT8_C(   3),  INT8_C(  83), -INT8_C(  71),  INT8_C(  88), -INT8_C(  50),  INT8_C(   7) },
      {  INT8_C(  65), -INT8_C(  21), -INT8_C(  39),  INT8_C(  77),  INT8_C(  91), -INT8_C( 100), -INT8_C(  80),  INT8_C(  68),
        -INT8_C( 126), -INT8_C( 114), -INT8_C( 100),  INT8_C(  26), -INT8_C(   6),  INT8_C(  61),  INT8_C(   8),  INT8_C(  60) },
      {  INT8_C( 103),  INT8_C(  50),  INT8_C(  40), -INT8_C(  47), -INT8_C(  43),  INT8_C(  90), -INT8_C(  89),  INT8_C( 125),
         INT8_C(  63), -INT8_C(  86), -INT8_C(  47), -INT8_C(   8),  INT8_C(   2), -INT8_C(  97),  INT8_C(   0),  INT8_C(  67) },
      {  INT8_C(  66), -INT8_C(  32), -INT8_C(   5), -INT8_C(  32),  INT8_C(  96),  INT8_C(  38),  INT8_C(  34), -INT8_C(  42),
         INT8_C(  40), -INT8_C(  32),  INT8_C(  15),  INT8_C(  81),  INT8_C(  65),  INT8_C( 120), -INT8_C(  58),  INT8_C(  59) } },
    { { -INT8_C( 117), -INT8_C(  39), -INT8_C( 112), -INT8_C(  26),  INT8_C( 117),  INT8_C(  65),  INT8_C(  42), -INT8_C(   9),
        -INT8_C(  49), -INT8_C(  58),  INT8_C(  18), -INT8_C(  55),  INT8_C(   4),  INT8_C(  26),  INT8_C(   5),  INT8_C( 107) },
      {  INT8_C(  77),  INT8_C(  45),  INT8_C(  60),  INT8_C(  34), -INT8_C( 120), -INT8_C(  29), -INT8_C(  97), -INT8_C(  57),
        -INT8_C( 115),  INT8_C( 112), -INT8_C(  65), -INT8_C( 112),  INT8_C(  16), -INT8_C(  65), -INT8_C(  45), -INT8_C( 101) },
      { -INT8_C( 104),  INT8_C( 100), -INT8_C( 127),  INT8_C(  14), -INT8_C(  91), -INT8_C(  84),  INT8_C(   5),  INT8_C( 116),
         INT8_C( 114),  INT8_C(  23),  INT8_C(  62),  INT8_C( 118),  INT8_C(  50),  INT8_C(  67), -INT8_C(  31),      INT8_MAX },
      { -INT8_C(  50), -INT8_C(  48), -INT8_C(  84), -INT8_C(  58),  INT8_C( 125),  INT8_C(   2), -INT8_C(  80),  INT8_C( 116),
         INT8_C(  66), -INT8_C(  90), -INT8_C( 109),  INT8_C(  73),  INT8_C(   4), -INT8_C(  90),  INT8_C(  23), -INT8_C(  21) } },
    { {  INT8_C( 113),  INT8_C(  29), -INT8_C(  95), -INT8_C(   7),  INT8_C(   0),  INT8_C(  64), -INT8_C(  64), -INT8_C( 114),
        -INT8_C(  79),      INT8_MAX,  INT8_C(  30), -INT8_C(  63),  INT8_C(  63), -INT8_C(  15),  INT8_C(  92), -INT8_C(  41) },
      {  INT8_C(  85), -INT8_C(  35), -INT8_C(  27), -INT8_C(   6), -INT8_C( 119), -INT8_C(  21),  INT8_C( 111), -INT8_C(   4),
         INT8_C(   2), -INT8_C(  83),  INT8_C( 114),  INT8_C(  52), -INT8_C(  16),  INT8_C(  84), -INT8_C(  77),  INT8_C(  97) },
      {  INT8_C( 113),  INT8_C(  84),  INT8_C(  90),  INT8_C( 114), -INT8_C( 107),  INT8_C(  26),  INT8_C(   0),  INT8_C(  70),
        -INT8_C( 102),  INT8_C(  30),  INT8_C(   7), -INT8_C(  39),  INT8_C(  15),  INT8_C(  99), -INT8_C(  80),  INT8_C( 101) },
      {  INT8_C( 117), -INT8_C( 108),  INT8_C(   4),  INT8_C( 113),  INT8_C(   8), -INT8_C(  95), -INT8_C(  81),  INT8_C(  54),
        -INT8_C(  79), -INT8_C(  34),  INT8_C( 110), -INT8_C(  27), -INT8_C(  49), -INT8_C(  27),  INT8_C(  95), -INT8_C(  41) } },
    { {  INT8_C(  64), -INT8_C( 106),  INT8_C(  95), -INT8_C(  54), -INT8_C( 127), -INT8_C(  50), -INT8_C(  58), -INT8_C( 125),
         INT8_C( 123),  INT8_C(  56), -INT8_C(  72),  INT8_C( 108), -INT8_C( 116),  INT8_C( 107), -INT8_C(  51), -INT8_C(   2) },
      { -INT8_C(  64),  INT8_C(  40),  INT8_C( 112),  INT8_C(  85),  INT8_C(  66),  INT8_C( 112), -INT8_C( 101), -INT8_C(  36),
        -INT8_C( 114), -INT8_C(  94), -INT8_C(  75), -INT8_C(  99),  INT8_C(   5),  INT8_C( 102),  INT8_C(   2),  INT8_C(  69) },
      { -INT8_C(   4),  INT8_C(  98),  INT8_C(  15),  INT8_C( 125),  INT8_C(  48), -INT8_C(  43),  INT8_C(   0), -INT8_C(  84),
         INT8_C(  14), -INT8_C(  72),  INT8_C(  24), -INT8_C( 102),  INT8_C(  36), -INT8_C(  27), -INT8_C( 104), -INT8_C(  28) },
      {  INT8_C(  64), -INT8_C(  98),  INT8_C(  47), -INT8_C(  54), -INT8_C(  61), -INT8_C(  18),  INT8_C(  93), -INT8_C(  45),
        -INT8_C(   5),  INT8_C(  58),  INT8_C(  29),  INT8_C( 105), -INT8_C( 115),  INT8_C( 105), -INT8_C(  49), -INT8_C(   1) } }
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
    { {  INT32_C(  1038944919),  INT32_C(  1693135794), -INT32_C(   478283200),  INT32_C(  1736067639) },
      {  INT32_C(   140154918), -INT32_C(  1505741274),  INT32_C(  1671557704),  INT32_C(   736538772) },
      {  INT32_C(  1835586491),  INT32_C(  1188123398), -INT32_C(  2060824755), -INT32_C(  1058233191) },
      {  INT32_C(  1489883434),  INT32_C(   108679830),  INT32_C(    91637581), -INT32_C(  2064322886) } },
    { {  INT32_C(  1657292348), -INT32_C(   989263491), -INT32_C(  1893160197),  INT32_C(   364514906) },
      { -INT32_C(   394124575), -INT32_C(  1020373898),  INT32_C(  1011374243),  INT32_C(   972829949) },
      { -INT32_C(   123943557), -INT32_C(   910318130), -INT32_C(  1453791665), -INT32_C(   692120844) },
      { -INT32_C(    86736537), -INT32_C(   843273017),  INT32_C(   712524823), -INT32_C(   759359242) } },
    { { -INT32_C(  1430372044),  INT32_C(   946793621),  INT32_C(  1115010629),  INT32_C(  1719366123) },
      {  INT32_C(    73275190),  INT32_C(   197991356), -INT32_C(   155900671),  INT32_C(  1825338423) },
      {  INT32_C(  1259768501), -INT32_C(  1149008778),  INT32_C(   654178363), -INT32_C(  1601406614) },
      { -INT32_C(   508114251), -INT32_C(  1952358281),  INT32_C(   649947775), -INT32_C(  1564510046) } },
    { {  INT32_C(  1302719120),  INT32_C(   123236869), -INT32_C(   805499496),  INT32_C(   926665089) },
      { -INT32_C(   914206125),  INT32_C(   293930454),  INT32_C(  1748468478), -INT32_C(  1945582597) },
      { -INT32_C(  1277579859), -INT32_C(  1195757280), -INT32_C(  1064847553), -INT32_C(   738737280) },
      { -INT32_C(  1208220371), -INT32_C(  1092467935),  INT32_C(  1196407359), -INT32_C(   523973760) } },
    { { -INT32_C(   342066923),  INT32_C(  2113741183), -INT32_C(  1612368732), -INT32_C(  1523847688) },
      { -INT32_C(  1151859557),  INT32_C(  1970475574),  INT32_C(  1228274377), -INT32_C(   769905219) },
      {  INT32_C(   633256358),  INT32_C(  2124594138), -INT32_C(   417429521),  INT32_C(   277694837) },
      {  INT32_C(  1698349218),  INT32_C(  1982765715),  INT32_C(  1910408139),  INT32_C(   900630837) } },
    { { -INT32_C(  2067012274), -INT32_C(  1040630024), -INT32_C(   167039432),  INT32_C(    46671707) },
      { -INT32_C(  1155037472),  INT32_C(   825870913), -INT32_C(   971483311), -INT32_C(   271145567) },
      { -INT32_C(  2089574005),  INT32_C(   407137503), -INT32_C(   166834278),  INT32_C(  1475925623) },
      { -INT32_C(  2017738619), -INT32_C(   662415257), -INT32_C(   972200014),  INT32_C(  1475400749) } },
    { { -INT32_C(  1642979491),  INT32_C(  1003441385),  INT32_C(  1140975779),  INT32_C(   406050957) },
      {  INT32_C(  1503372921), -INT32_C(  1385045998), -INT32_C(  1499234513), -INT32_C(  1291936939) },
      { -INT32_C(  1538191174),  INT32_C(    14622812), -INT32_C(  1773871096),  INT32_C(   850294968) },
      {  INT32_C(   575736254),  INT32_C(   307309749), -INT32_C(   700161912),  INT32_C(   984561712) } },
    { {  INT32_C(   831212062),  INT32_C(  1507785770), -INT32_C(   805273221), -INT32_C(   695992804) },
      {  INT32_C(  1803211790), -INT32_C(    43296268), -INT32_C(   225202374),  INT32_C(  1176781095) },
      { -INT32_C(  1250447477),  INT32_C(   638539179), -INT32_C(   218689578),  INT32_C(   466123277) },
      { -INT32_C(  1510562405),  INT32_C(   647754145), -INT32_C(   218689641), -INT32_C(  1957968875) } }
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
    { { -INT64_C( 3008420372626914482), -INT64_C( 6985385298481261919) },
      { -INT64_C( 5733252911940139619),  INT64_C( 3358396559109809779) },
      { -INT64_C( 5466894875751341394),  INT64_C( 8374034315201079938) },
      { -INT64_C(  994977658780360468), -INT64_C( 1931463956267501054) } },
    { {  INT64_C( 7105603721047673617),  INT64_C( 6314184844303810194) },
      {  INT64_C( 4857065955557249183), -INT64_C( 9081210197676268371) },
      {  INT64_C( 8424837296987879066), -INT64_C( 1564853209788920505) },
      {  INT64_C( 6085247987639991706), -INT64_C( 4879378880977905835) } },
    { {  INT64_C( 6528536851884403350),  INT64_C( 2151268731171271657) },
      { -INT64_C( 7574049278433736819), -INT64_C( 1831329732369069728) },
      {  INT64_C( 2432180436013495225),  INT64_C(  282413370382720586) },
      {  INT64_C( 7627077521210973099),  INT64_C( 1918891841737174211) } },
    { { -INT64_C( 8898455197144870244), -INT64_C( 7974250031820633824) },
      { -INT64_C( 5453376011347979528), -INT64_C( 4697416989608391594) },
      { -INT64_C( 5069032719830596866), -INT64_C( 7737044951088179402) },
      { -INT64_C( 5105554077456383238), -INT64_C( 7660342297895709162) } },
    { { -INT64_C( 6544269777416447984),  INT64_C( 1928175179057442786) },
      { -INT64_C( 3398557893719659133), -INT64_C( 8292111542340550980) },
      { -INT64_C( 6409408672236654568),  INT64_C( 4835298916564696804) },
      { -INT64_C( 9068239192415920120),  INT64_C( 5843473013974728614) } },
    { { -INT64_C(  484922846794000165), -INT64_C( 4811183995095014093) },
      {  INT64_C( 6510570597182096109),  INT64_C( 5670724019462735280) },
      {  INT64_C( 8791881098285224653),  INT64_C( 9119899822900991022) },
      { -INT64_C( 2664427499549095201), -INT64_C( 3487637597576465363) } },
    { { -INT64_C( 7604456724854950746),  INT64_C( 1464435443981734544) },
      {  INT64_C( 5515538581665224138), -INT64_C( 4646396397822692235) },
      { -INT64_C( 3467680181771258780),  INT64_C( 7458001241479767333) },
      {  INT64_C( 6743254095072334912),  INT64_C( 7481100043765852069) } },
    { {  INT64_C( 3793442381487447610), -INT64_C( 2841843430928497481) },
      { -INT64_C( 1981299343010665613), -INT64_C( 5553833924891749401) },
      {  INT64_C( 2333901893908718959), -INT64_C( 3476638875308220812) },
      {  INT64_C( 3478941004895285607), -INT64_C( 8663991816630429084) } }
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
