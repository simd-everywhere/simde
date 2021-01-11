#define SIMDE_TEST_ARM_NEON_INSN orr

#include "test-neon.h"
#include "../../../simde/arm/neon/orr.h"

static int
test_simde_vorr_s8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int8_t a[8];
    int8_t b[8];
    int8_t r[8];
  } test_vec[] = {
    { {  INT8_C(  43), -INT8_C(  72),  INT8_C(  13), -INT8_C(  58), -INT8_C(  99),  INT8_C( 110), -INT8_C( 120), -INT8_C( 100) },
      {  INT8_C(  21), -INT8_C(  25), -INT8_C(  50),  INT8_C(  76),  INT8_C(  92),  INT8_C(  65),  INT8_C( 115), -INT8_C(  62) },
      {  INT8_C(  63), -INT8_C(   1), -INT8_C(  49), -INT8_C(  50), -INT8_C(  35),  INT8_C( 111), -INT8_C(   5), -INT8_C(  34) } },
    { {  INT8_C(  30), -INT8_C( 126),  INT8_C(  57),  INT8_C(  41),  INT8_C(  64),  INT8_C(  98), -INT8_C(  52), -INT8_C(  70) },
      {  INT8_C(  41),  INT8_C(  28),      INT8_MAX,  INT8_C(  96), -INT8_C(  11),  INT8_C(  40),  INT8_C(  71),  INT8_C(  32) },
      {  INT8_C(  63), -INT8_C(  98),      INT8_MAX,  INT8_C( 105), -INT8_C(  11),  INT8_C( 106), -INT8_C(  49), -INT8_C(  70) } },
    { { -INT8_C(  32),  INT8_C(  84), -INT8_C(  25),  INT8_C( 125), -INT8_C(  61),  INT8_C( 111),  INT8_C(  25), -INT8_C(  40) },
      {  INT8_C(  87), -INT8_C(  25),  INT8_C(  36), -INT8_C(  77),  INT8_C(  40), -INT8_C( 105),  INT8_C( 117),  INT8_C(  71) },
      { -INT8_C(   9), -INT8_C(   9), -INT8_C(  25), -INT8_C(   1), -INT8_C(  21), -INT8_C(   1),  INT8_C( 125), -INT8_C(  33) } },
    { {  INT8_C(  26), -INT8_C(  82),  INT8_C( 112),  INT8_C(  90),  INT8_C(  17),  INT8_C(  60),  INT8_C(  20),  INT8_C(  58) },
      {  INT8_C(  88), -INT8_C( 108), -INT8_C( 102),  INT8_C(  77), -INT8_C(  68), -INT8_C(  31),  INT8_C( 109), -INT8_C( 100) },
      {  INT8_C(  90), -INT8_C(  66), -INT8_C(   6),  INT8_C(  95), -INT8_C(  67), -INT8_C(   3),  INT8_C( 125), -INT8_C(  66) } },
    { {  INT8_C(  54),  INT8_C(  84),  INT8_C(  25), -INT8_C(   7), -INT8_C(  60),  INT8_C(  50), -INT8_C(  47),  INT8_C(  27) },
      {  INT8_C(  25), -INT8_C(  10), -INT8_C(  50),  INT8_C(  65), -INT8_C( 115),  INT8_C(  67), -INT8_C( 120), -INT8_C(  89) },
      {  INT8_C(  63), -INT8_C(  10), -INT8_C(  33), -INT8_C(   7), -INT8_C(  51),  INT8_C( 115), -INT8_C(  39), -INT8_C(  65) } },
    { { -INT8_C(  15), -INT8_C(   8),  INT8_C(   1),  INT8_C(   2),  INT8_C(  52),  INT8_C(  22),  INT8_C(  60), -INT8_C( 116) },
      { -INT8_C(  86), -INT8_C(  41), -INT8_C(  39),  INT8_C( 102), -INT8_C(  72),  INT8_C(  71),  INT8_C(   2), -INT8_C(  18) },
      { -INT8_C(   5), -INT8_C(   1), -INT8_C(  39),  INT8_C( 102), -INT8_C(  68),  INT8_C(  87),  INT8_C(  62), -INT8_C(  18) } },
    { { -INT8_C( 101),  INT8_C(  27), -INT8_C(  25),  INT8_C(  95),  INT8_C(  77), -INT8_C(  71),  INT8_C( 122),  INT8_C( 102) },
      { -INT8_C(  81),  INT8_C(  72), -INT8_C(  89),  INT8_C(  60), -INT8_C( 117),  INT8_C(  48), -INT8_C(  28),  INT8_C( 125) },
      { -INT8_C(  65),  INT8_C(  91), -INT8_C(  25),      INT8_MAX, -INT8_C(  49), -INT8_C(  71), -INT8_C(   2),      INT8_MAX } },
    { {  INT8_C(  40), -INT8_C(  27),      INT8_MAX,  INT8_C(  93), -INT8_C(   5), -INT8_C(  68), -INT8_C(  23), -INT8_C(  91) },
      { -INT8_C( 109), -INT8_C(  61),  INT8_C(  11),  INT8_C(  75),  INT8_C(  10),  INT8_C(  13),  INT8_C(  58), -INT8_C(  91) },
      { -INT8_C(  69), -INT8_C(  25),      INT8_MAX,  INT8_C(  95), -INT8_C(   5), -INT8_C(  67), -INT8_C(   5), -INT8_C(  91) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8_t a = simde_vld1_s8(test_vec[i].a);
    simde_int8x8_t b = simde_vld1_s8(test_vec[i].b);
    simde_int8x8_t r = simde_vorr_s8(a, b);

    simde_test_arm_neon_assert_equal_i8x8(r, simde_vld1_s8(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vorr_s16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int16_t a[4];
    int16_t b[4];
    int16_t r[4];
  } test_vec[] = {
    { { -INT16_C( 16819),  INT16_C( 16268),  INT16_C( 17482),  INT16_C( 11881) },
      {  INT16_C( 12073),  INT16_C( 22113),  INT16_C( 13230), -INT16_C( 21136) },
      { -INT16_C( 16531),  INT16_C( 32749),  INT16_C( 30702), -INT16_C( 20615) } },
    { { -INT16_C(  3611), -INT16_C( 18421),  INT16_C( 29876), -INT16_C(   552) },
      { -INT16_C( 26226),  INT16_C( 29711), -INT16_C( 15476), -INT16_C(  9483) },
      { -INT16_C(  1553), -INT16_C(  1009), -INT16_C(  2116), -INT16_C(     3) } },
    { { -INT16_C( 32383), -INT16_C( 13287), -INT16_C( 32059), -INT16_C(  4102) },
      {  INT16_C( 23729),  INT16_C( 24389), -INT16_C( 19057),  INT16_C( 29708) },
      { -INT16_C(  8783), -INT16_C(  8355), -INT16_C( 18481), -INT16_C(     2) } },
    { {  INT16_C(  6054),  INT16_C( 23340),  INT16_C(  1419),  INT16_C(  6744) },
      {  INT16_C( 26526),  INT16_C( 10894), -INT16_C( 31957), -INT16_C( 21500) },
      {  INT16_C( 30654),  INT16_C( 31662), -INT16_C( 30805), -INT16_C( 16804) } },
    { {  INT16_C(  7428), -INT16_C( 13960),  INT16_C( 29599),  INT16_C( 20664) },
      { -INT16_C(   305),  INT16_C( 24239), -INT16_C( 17229),  INT16_C( 23251) },
      { -INT16_C(    49), -INT16_C(  8193), -INT16_C(    65),  INT16_C( 23291) } },
    { { -INT16_C(    45),  INT16_C( 24501),  INT16_C(  3332), -INT16_C( 23943) },
      {  INT16_C(  1908), -INT16_C( 24627), -INT16_C( 11894), -INT16_C( 29108) },
      { -INT16_C(     9), -INT16_C(  8195), -INT16_C(  8818), -INT16_C( 20867) } },
    { { -INT16_C( 15121), -INT16_C( 29097),  INT16_C(  4151),  INT16_C(  1759) },
      { -INT16_C( 29170), -INT16_C( 16027),  INT16_C( 14410),  INT16_C(  7707) },
      { -INT16_C( 12561), -INT16_C( 12425),  INT16_C( 14463),  INT16_C(  7903) } },
    { { -INT16_C( 12233),  INT16_C( 15485), -INT16_C(  2339),  INT16_C( 21214) },
      { -INT16_C( 21507), -INT16_C( 30735),  INT16_C( 15741),  INT16_C( 27669) },
      { -INT16_C(  1025), -INT16_C( 16387), -INT16_C(     3),  INT16_C( 32479) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t a = simde_vld1_s16(test_vec[i].a);
    simde_int16x4_t b = simde_vld1_s16(test_vec[i].b);
    simde_int16x4_t r = simde_vorr_s16(a, b);

    simde_test_arm_neon_assert_equal_i16x4(r, simde_vld1_s16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vorr_s32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int32_t a[2];
    int32_t b[2];
    int32_t r[2];
  } test_vec[] = {
    { { -INT32_C(  1845357222),  INT32_C(  1792000206) },
      {  INT32_C(  1952762721), -INT32_C(   591518222) },
      { -INT32_C(   161030277), -INT32_C(    16783874) } },
    { {  INT32_C(  1074647543), -INT32_C(  1556974049) },
      {  INT32_C(  1200672026),  INT32_C(   225866674) },
      {  INT32_C(  1201528319), -INT32_C(  1351190593) } },
    { {  INT32_C(  1453291656), -INT32_C(  1698599368) },
      {  INT32_C(   722347321),  INT32_C(  1091095626) },
      {  INT32_C(  2141158841), -INT32_C(   607523206) } },
    { { -INT32_C(  1115613795), -INT32_C(  1503612020) },
      {  INT32_C(   871231616), -INT32_C(   348101789) },
      { -INT32_C(  1074924131), -INT32_C(   278858769) } },
    { {  INT32_C(   339927004), -INT32_C(  2018639027) },
      {  INT32_C(  1924316200),  INT32_C(   649312904) },
      {  INT32_C(  1995636732), -INT32_C(  1480606771) } },
    { {  INT32_C(  1558394320),  INT32_C(  1761756136) },
      { -INT32_C(  1751322572),  INT32_C(   797170771) },
      { -INT32_C(   536873484),  INT32_C(  1870913531) } },
    { {  INT32_C(   138724795), -INT32_C(   259001656) },
      {  INT32_C(   929186479), -INT32_C(   866314756) },
      {  INT32_C(  1063700415), -INT32_C(    52430852) } },
    { {  INT32_C(   858275914), -INT32_C(  1197724796) },
      {  INT32_C(  1850685467), -INT32_C(   811675116) },
      {  INT32_C(  2138011739), -INT32_C(     6358124) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t a = simde_vld1_s32(test_vec[i].a);
    simde_int32x2_t b = simde_vld1_s32(test_vec[i].b);
    simde_int32x2_t r = simde_vorr_s32(a, b);

    simde_test_arm_neon_assert_equal_i32x2(r, simde_vld1_s32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vorr_s64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int64_t a[1];
    int64_t b[1];
    int64_t r[1];
  } test_vec[] = {
    { {  INT64_C( 3151194404085669577) },
      {  INT64_C( 7150093679456372669) },
      {  INT64_C( 7762937874449424381) } },
    { {  INT64_C( 8772691476915187418) },
      { -INT64_C( 7160547676975981979) },
      { -INT64_C(  162446265433882881) } },
    { {  INT64_C( 6919140515929545021) },
      { -INT64_C( 2327186706082379520) },
      { -INT64_C(   20902094605199043) } },
    { { -INT64_C( 7602424505649834598) },
      { -INT64_C(  914887447672121379) },
      { -INT64_C(  612511850049939489) } },
    { {  INT64_C(  290432717920553731) },
      { -INT64_C( 4575365684894762596) },
      { -INT64_C( 4285215561364800609) } },
    { {  INT64_C( 2748959705308497502) },
      { -INT64_C( 2376172329570520740) },
      { -INT64_C(   61247352163879074) } },
    { {  INT64_C( 4933285092639757422) },
      {  INT64_C( 3705450760845577094) },
      {  INT64_C( 8610583385991536622) } },
    { { -INT64_C( 3216438236108606739) },
      { -INT64_C( 4191185119456447717) },
      { -INT64_C( 2891896485226007553) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x1_t a = simde_vld1_s64(test_vec[i].a);
    simde_int64x1_t b = simde_vld1_s64(test_vec[i].b);
    simde_int64x1_t r = simde_vorr_s64(a, b);

    simde_test_arm_neon_assert_equal_i64x1(r, simde_vld1_s64(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vorr_u8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint8_t a[16];
    uint8_t b[16];
    uint8_t r[16];
  } test_vec[] = {
    { { UINT8_C( 35), UINT8_C(214), UINT8_C(198), UINT8_C(133), UINT8_C(234), UINT8_C(114), UINT8_C(199), UINT8_C(150) },
      { UINT8_C( 85), UINT8_C( 51), UINT8_C( 53), UINT8_C(117), UINT8_C(  5), UINT8_C(105), UINT8_C(134), UINT8_C( 51) },
      { UINT8_C(119), UINT8_C(247), UINT8_C(247), UINT8_C(245), UINT8_C(239), UINT8_C(123), UINT8_C(199), UINT8_C(183) } },
    { { UINT8_C( 44), UINT8_C( 39), UINT8_C( 84), UINT8_C(230), UINT8_C( 67), UINT8_C(145), UINT8_C(231), UINT8_C( 39) },
      { UINT8_C( 56), UINT8_C(162), UINT8_C(186), UINT8_C(218), UINT8_C(216), UINT8_C( 29), UINT8_C(225), UINT8_C(251) },
      { UINT8_C( 60), UINT8_C(167), UINT8_C(254), UINT8_C(254), UINT8_C(219), UINT8_C(157), UINT8_C(231),    UINT8_MAX } },
    { { UINT8_C(243), UINT8_C(167), UINT8_C(128), UINT8_C(222), UINT8_C( 25), UINT8_C( 71), UINT8_C(116), UINT8_C(110) },
      { UINT8_C(122), UINT8_C(170), UINT8_C(228), UINT8_C(128), UINT8_C( 19), UINT8_C(106), UINT8_C(179), UINT8_C( 63) },
      { UINT8_C(251), UINT8_C(175), UINT8_C(228), UINT8_C(222), UINT8_C( 27), UINT8_C(111), UINT8_C(247), UINT8_C(127) } },
    { { UINT8_C(146), UINT8_C(  7), UINT8_C( 37), UINT8_C(213), UINT8_C(152), UINT8_C( 12), UINT8_C(252), UINT8_C(208) },
      { UINT8_C(174), UINT8_C(183), UINT8_C(170), UINT8_C(135), UINT8_C(212), UINT8_C(139), UINT8_C(130), UINT8_C(199) },
      { UINT8_C(190), UINT8_C(183), UINT8_C(175), UINT8_C(215), UINT8_C(220), UINT8_C(143), UINT8_C(254), UINT8_C(215) } },
    { { UINT8_C( 50), UINT8_C(  3), UINT8_C(165), UINT8_C( 75), UINT8_C( 74), UINT8_C( 26), UINT8_C(186), UINT8_C(197) },
      { UINT8_C(196), UINT8_C(158), UINT8_C( 69), UINT8_C(215), UINT8_C(  8), UINT8_C(248), UINT8_C( 23), UINT8_C(154) },
      { UINT8_C(246), UINT8_C(159), UINT8_C(229), UINT8_C(223), UINT8_C( 74), UINT8_C(250), UINT8_C(191), UINT8_C(223) } },
    { {    UINT8_MAX, UINT8_C( 60), UINT8_C(112), UINT8_C(151), UINT8_C( 73), UINT8_C(108), UINT8_C(103), UINT8_C(247) },
      { UINT8_C( 35), UINT8_C( 17), UINT8_C(126), UINT8_C(247), UINT8_C(157), UINT8_C(  1), UINT8_C(191), UINT8_C(207) },
      {    UINT8_MAX, UINT8_C( 61), UINT8_C(126), UINT8_C(247), UINT8_C(221), UINT8_C(109),    UINT8_MAX,    UINT8_MAX } },
    { { UINT8_C(  4), UINT8_C(100), UINT8_C( 27), UINT8_C( 78), UINT8_C(126), UINT8_C(213), UINT8_C( 19), UINT8_C( 66) },
      { UINT8_C(115), UINT8_C( 88), UINT8_C( 26), UINT8_C(123), UINT8_C( 80), UINT8_C( 49), UINT8_C( 22), UINT8_C( 79) },
      { UINT8_C(119), UINT8_C(124), UINT8_C( 27), UINT8_C(127), UINT8_C(126), UINT8_C(245), UINT8_C( 23), UINT8_C( 79) } },
    { { UINT8_C(109), UINT8_C(134), UINT8_C(230), UINT8_C(182), UINT8_C(242), UINT8_C( 77), UINT8_C(174), UINT8_C( 22) },
      { UINT8_C( 95), UINT8_C( 44), UINT8_C( 13), UINT8_C(252), UINT8_C( 45), UINT8_C(204), UINT8_C(203), UINT8_C( 49) },
      { UINT8_C(127), UINT8_C(174), UINT8_C(239), UINT8_C(254),    UINT8_MAX, UINT8_C(205), UINT8_C(239), UINT8_C( 55) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x8_t a = simde_vld1_u8(test_vec[i].a);
    simde_uint8x8_t b = simde_vld1_u8(test_vec[i].b);
    simde_uint8x8_t r = simde_vorr_u8(a, b);

    simde_test_arm_neon_assert_equal_u8x8(r, simde_vld1_u8(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vorr_u16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint16_t a[4];
    uint16_t b[4];
    uint16_t r[4];
  } test_vec[] = {
    { { UINT16_C(38025), UINT16_C( 1112), UINT16_C(15377), UINT16_C( 4043) },
      { UINT16_C( 8697), UINT16_C(57130), UINT16_C( 4216), UINT16_C(52332) },
      { UINT16_C(46585), UINT16_C(57210), UINT16_C(15481), UINT16_C(53231) } },
    { { UINT16_C(31219), UINT16_C(35443), UINT16_C(51575), UINT16_C(56842) },
      { UINT16_C(57021), UINT16_C(64071), UINT16_C( 9441), UINT16_C(27152) },
      {      UINT16_MAX, UINT16_C(64119), UINT16_C(60919), UINT16_C(65050) } },
    { { UINT16_C(26808), UINT16_C(51823), UINT16_C(15012), UINT16_C(40665) },
      { UINT16_C(  859), UINT16_C(54141), UINT16_C(59668), UINT16_C( 1952) },
      { UINT16_C(27643), UINT16_C(56191), UINT16_C(64436), UINT16_C(40953) } },
    { { UINT16_C( 4962), UINT16_C(55953), UINT16_C(39900), UINT16_C(39608) },
      { UINT16_C(65401), UINT16_C(23444), UINT16_C(42019), UINT16_C(56261) },
      { UINT16_C(65403), UINT16_C(56213), UINT16_C(49151), UINT16_C(56317) } },
    { { UINT16_C(13325), UINT16_C(45477), UINT16_C(32622), UINT16_C(51791) },
      { UINT16_C(52610), UINT16_C(38557), UINT16_C(15798), UINT16_C( 6557) },
      { UINT16_C(64911), UINT16_C(47037), UINT16_C(32766), UINT16_C(56287) } },
    { { UINT16_C(11857), UINT16_C(11763), UINT16_C(43977), UINT16_C(17351) },
      { UINT16_C(23466), UINT16_C(52638), UINT16_C(25344), UINT16_C( 3496) },
      { UINT16_C(32763), UINT16_C(60927), UINT16_C(60361), UINT16_C(20463) } },
    { { UINT16_C(20120), UINT16_C( 1726), UINT16_C( 3789), UINT16_C(20432) },
      { UINT16_C(28379), UINT16_C(37350), UINT16_C(33707), UINT16_C(64682) },
      { UINT16_C(28379), UINT16_C(38910), UINT16_C(36847), UINT16_C(65530) } },
    { { UINT16_C(40370), UINT16_C(31530), UINT16_C(61768), UINT16_C(62142) },
      { UINT16_C(23629), UINT16_C(19903), UINT16_C(26816), UINT16_C(22618) },
      { UINT16_C(56831), UINT16_C(32703), UINT16_C(63944), UINT16_C(64254) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4_t a = simde_vld1_u16(test_vec[i].a);
    simde_uint16x4_t b = simde_vld1_u16(test_vec[i].b);
    simde_uint16x4_t r = simde_vorr_u16(a, b);
    simde_test_arm_neon_assert_equal_u16x4(r, simde_vld1_u16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vorr_u32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint32_t a[2];
    uint32_t b[2];
    uint32_t r[2];
  } test_vec[] = {
    { { UINT32_C(2542243251), UINT32_C(1923390208) },
      { UINT32_C(1002757752), UINT32_C(4145368516) },
      { UINT32_C(3217547259), UINT32_C(4155891652) } },
    { { UINT32_C(1695516834), UINT32_C(1276650104) },
      { UINT32_C(2163439025), UINT32_C(4227580744) },
      { UINT32_C(3858759091), UINT32_C(4294697848) } },
    { { UINT32_C(1351844688), UINT32_C(2529310494) },
      { UINT32_C(3654453013), UINT32_C(1993402324) },
      { UINT32_C(3654518613), UINT32_C(4141021150) } },
    { { UINT32_C(3906789232), UINT32_C(3006592002) },
      { UINT32_C(2972919657), UINT32_C( 984428522) },
      { UINT32_C(4194303865), UINT32_C(3149791210) } },
    { { UINT32_C(3498721458), UINT32_C(2355514743) },
      { UINT32_C(2825205972), UINT32_C(2417964320) },
      { UINT32_C(4176443638), UINT32_C(2625600887) } },
    { { UINT32_C( 377027348), UINT32_C(1506454767) },
      { UINT32_C(3188391379), UINT32_C(3740841772) },
      { UINT32_C(3195731927), UINT32_C(3757752303) } },
    { { UINT32_C(1856930807), UINT32_C(2767853008) },
      { UINT32_C(1833721677), UINT32_C(2851957652) },
      { UINT32_C(1877925887), UINT32_C(2919202772) } },
    { { UINT32_C(1455388006), UINT32_C(4121921825) },
      { UINT32_C(3014900103), UINT32_C(1754442609) },
      { UINT32_C(4156554727), UINT32_C(4257196913) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2_t a = simde_vld1_u32(test_vec[i].a);
    simde_uint32x2_t b = simde_vld1_u32(test_vec[i].b);
    simde_uint32x2_t r = simde_vorr_u32(a, b);
    simde_test_arm_neon_assert_equal_u32x2(r, simde_vld1_u32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vorr_u64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint64_t a[1];
    uint64_t b[1];
    uint64_t r[1];
  } test_vec[] = {
    { { UINT64_C( 8723019818965631880) },
      { UINT64_C(10354760186494598420) },
      { UINT64_C(18428588727770005404) } },
    { { UINT64_C(13192140800111500143) },
      { UINT64_C(11472348407170591550) },
      { UINT64_C(13778761135761128319) } },
    { { UINT64_C(15007327377362344059) },
      { UINT64_C(10380688433334625017) },
      { UINT64_C(15010424705917123323) } },
    { { UINT64_C(14472684133206828281) },
      { UINT64_C( 4102455717689345080) },
      { UINT64_C(17942303254750553337) } },
    { { UINT64_C( 5889942334929607729) },
      { UINT64_C( 4511446038880561129) },
      { UINT64_C( 9205330554010189817) } },
    { { UINT64_C( 6473705803523085444) },
      { UINT64_C( 9796340008937356542) },
      { UINT64_C(16138578302157257982) } },
    { { UINT64_C( 2944283500602521395) },
      { UINT64_C( 1251100802482875865) },
      { UINT64_C( 4169488553517449211) } },
    { { UINT64_C(17590489458298371234) },
      { UINT64_C(10326932464964978036) },
      { UINT64_C(18401139624751660534) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x1_t a = simde_vld1_u64(test_vec[i].a);
    simde_uint64x1_t b = simde_vld1_u64(test_vec[i].b);
    simde_uint64x1_t r = simde_vorr_u64(a, b);
    simde_test_arm_neon_assert_equal_u64x1(r, simde_vld1_u64(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vorrq_s8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int8_t a[16];
    int8_t b[16];
    int8_t r[16];
  } test_vec[] = {
    { { -INT8_C( 120), -INT8_C(  40),  INT8_C(  38),  INT8_C(  49), -INT8_C( 100),  INT8_C(  57), -INT8_C(  73), -INT8_C( 108),
         INT8_C(  39),  INT8_C(   6), -INT8_C(   9),  INT8_C(   2),  INT8_C(  86),  INT8_C(  18),  INT8_C(  34),  INT8_C(  37) },
      {  INT8_C(  83),  INT8_C(  10),  INT8_C(  53),  INT8_C(  69),  INT8_C(  64),  INT8_C(  88),  INT8_C(  30), -INT8_C(  92),
         INT8_C( 121), -INT8_C(  41),  INT8_C( 117),  INT8_C(  38), -INT8_C(   6),  INT8_C(  74), -INT8_C( 127), -INT8_C( 126) },
      { -INT8_C(  37), -INT8_C(  38),  INT8_C(  55),  INT8_C( 117), -INT8_C(  36),  INT8_C( 121), -INT8_C(  65), -INT8_C(  76),
             INT8_MAX, -INT8_C(  41), -INT8_C(   9),  INT8_C(  38), -INT8_C(   2),  INT8_C(  90), -INT8_C(  93), -INT8_C(  89) } },
    { {  INT8_C(  35), -INT8_C(  88), -INT8_C(  77), -INT8_C(  65), -INT8_C(  31),  INT8_C( 106),  INT8_C(  83),  INT8_C(   8),
         INT8_C( 113),  INT8_C(  74),  INT8_C(  10), -INT8_C(  57),  INT8_C(  92),  INT8_C(  45), -INT8_C(  20), -INT8_C(  81) },
      {  INT8_C(  55),  INT8_C(  34), -INT8_C(  11),  INT8_C( 119),  INT8_C( 122),  INT8_C(  19),  INT8_C(  27), -INT8_C(  13),
        -INT8_C(  22), -INT8_C( 112),  INT8_C(  25), -INT8_C(  28), -INT8_C(  37), -INT8_C( 101),  INT8_C( 103), -INT8_C(   2) },
      {  INT8_C(  55), -INT8_C(  86), -INT8_C(   9), -INT8_C(   1), -INT8_C(   5),  INT8_C( 123),  INT8_C(  91), -INT8_C(   5),
        -INT8_C(   5), -INT8_C(  38),  INT8_C(  27), -INT8_C(  25), -INT8_C(  33), -INT8_C(  65), -INT8_C(  17), -INT8_C(   1) } },
    { {  INT8_C(  67),  INT8_C(  26), -INT8_C(  67),  INT8_C(  36), -INT8_C( 123),  INT8_C(  16),  INT8_C(  45), -INT8_C(  10),
         INT8_C(  90),  INT8_C(  55), -INT8_C(  67), -INT8_C(  74),  INT8_C( 100), -INT8_C(  87),  INT8_C( 101), -INT8_C( 100) },
      { -INT8_C(  53),  INT8_C(  90),  INT8_C(  19),  INT8_C(  70),  INT8_C( 109),  INT8_C(  47),  INT8_C(  57),  INT8_C(  87),
        -INT8_C(  65),  INT8_C(  83),  INT8_C(  60), -INT8_C( 102), -INT8_C(  18), -INT8_C(  93), -INT8_C( 104),  INT8_C(  49) },
      { -INT8_C(  53),  INT8_C(  90), -INT8_C(  65),  INT8_C( 102), -INT8_C(  19),  INT8_C(  63),  INT8_C(  61), -INT8_C(   9),
        -INT8_C(   1),  INT8_C( 119), -INT8_C(  67), -INT8_C(  66), -INT8_C(  18), -INT8_C(  85), -INT8_C(   3), -INT8_C(  67) } },
    { { -INT8_C(  67),  INT8_C(  85),  INT8_C(  85),  INT8_C(  66),  INT8_C( 101), -INT8_C( 126),  INT8_C(  56), -INT8_C(  65),
        -INT8_C(  70), -INT8_C(  11),  INT8_C( 117),  INT8_C(  30), -INT8_C(  97), -INT8_C(  37), -INT8_C(  70),  INT8_C( 106) },
      {  INT8_C(  53), -INT8_C(  50), -INT8_C(  80), -INT8_C(  93), -INT8_C(   3), -INT8_C(  22), -INT8_C(   6), -INT8_C(  68),
         INT8_C(  61),  INT8_C(  54),  INT8_C(  87),  INT8_C(  43), -INT8_C(  39), -INT8_C(  17),  INT8_C(  92), -INT8_C( 105) },
      { -INT8_C(  67), -INT8_C(  33), -INT8_C(  11), -INT8_C(  29), -INT8_C(   3), -INT8_C(  22), -INT8_C(   6), -INT8_C(  65),
        -INT8_C(  65), -INT8_C(   9),  INT8_C( 119),  INT8_C(  63), -INT8_C(  33), -INT8_C(   1), -INT8_C(   2), -INT8_C(   1) } },
    { {  INT8_C(  69), -INT8_C(  79), -INT8_C(  39), -INT8_C(  86),  INT8_C(  52),  INT8_C(  18),  INT8_C( 106), -INT8_C(  18),
         INT8_C(   7), -INT8_C(  33),  INT8_C(  12), -INT8_C(  90), -INT8_C(  70), -INT8_C(  57),  INT8_C(  17), -INT8_C(  16) },
      { -INT8_C( 107), -INT8_C(  63), -INT8_C( 109), -INT8_C( 110), -INT8_C(  85), -INT8_C( 115),  INT8_C(  78), -INT8_C(  24),
        -INT8_C(  60), -INT8_C(  91),  INT8_C(  19), -INT8_C(  99), -INT8_C( 107),  INT8_C( 111),  INT8_C(  52), -INT8_C(  38) },
      { -INT8_C(  43), -INT8_C(  15), -INT8_C(  37), -INT8_C(  70), -INT8_C(  65), -INT8_C(  97),  INT8_C( 110), -INT8_C(  18),
        -INT8_C(  57), -INT8_C(   1),  INT8_C(  31), -INT8_C(  65), -INT8_C(  65), -INT8_C(  17),  INT8_C(  53), -INT8_C(   6) } },
    { {  INT8_C(  33),  INT8_C(  14), -INT8_C( 124),  INT8_C(  85),  INT8_C(  32), -INT8_C(  18),  INT8_C(  67),  INT8_C(  39),
        -INT8_C(  50),  INT8_C(  79), -INT8_C(  50), -INT8_C( 120),  INT8_C(  22), -INT8_C(  33),  INT8_C( 120), -INT8_C(  85) },
      { -INT8_C(  96),  INT8_C(  11),  INT8_C(  61),  INT8_C(  76), -INT8_C( 103), -INT8_C( 116),  INT8_C(  52),  INT8_C(  93),
         INT8_C(  49),  INT8_C(  72), -INT8_C(   6), -INT8_C(  58), -INT8_C(  73),  INT8_C(  47), -INT8_C(  96), -INT8_C(  40) },
      { -INT8_C(  95),  INT8_C(  15), -INT8_C(  67),  INT8_C(  93), -INT8_C(  71), -INT8_C(  18),  INT8_C( 119),      INT8_MAX,
        -INT8_C(   1),  INT8_C(  79), -INT8_C(   2), -INT8_C(  50), -INT8_C(  73), -INT8_C(   1), -INT8_C(   8), -INT8_C(   5) } },
    { {  INT8_C(  61),  INT8_C(  37),  INT8_C(  45),  INT8_C(  93),  INT8_C(  19),  INT8_C( 112), -INT8_C( 124), -INT8_C(  31),
        -INT8_C(  64),  INT8_C(  82),  INT8_C( 106), -INT8_C(  42),  INT8_C(  49), -INT8_C(  30), -INT8_C( 126), -INT8_C(  46) },
      { -INT8_C(  18), -INT8_C(  65),  INT8_C(  30), -INT8_C( 121),  INT8_C(  75),  INT8_C(  82), -INT8_C(  28),  INT8_C( 125),
        -INT8_C( 102), -INT8_C(  34),  INT8_C(  67),  INT8_C(  82),  INT8_C(  13), -INT8_C(  28),  INT8_C(  42),  INT8_C(  74) },
      { -INT8_C(   1), -INT8_C(  65),  INT8_C(  63), -INT8_C(  33),  INT8_C(  91),  INT8_C( 114), -INT8_C(  28), -INT8_C(   3),
        -INT8_C(  38), -INT8_C(  34),  INT8_C( 107), -INT8_C(  42),  INT8_C(  61), -INT8_C(  26), -INT8_C(  86), -INT8_C(  38) } },
    { {  INT8_C(   9),  INT8_C(  88), -INT8_C(  89),  INT8_C(  28), -INT8_C(  56),  INT8_C(  44), -INT8_C(   2), -INT8_C( 120),
         INT8_C( 126),  INT8_C( 104),  INT8_C(  95), -INT8_C(  80),  INT8_C(  74), -INT8_C(  31), -INT8_C( 126),  INT8_C(  56) },
      { -INT8_C(  96), -INT8_C(  96), -INT8_C(  65), -INT8_C(  20), -INT8_C(  14), -INT8_C(  93),  INT8_C( 105), -INT8_C( 115),
        -INT8_C( 126), -INT8_C(  84), -INT8_C(  33), -INT8_C( 113), -INT8_C( 112),  INT8_C(   9), -INT8_C(  38), -INT8_C( 103) },
      { -INT8_C(  87), -INT8_C(   8), -INT8_C(  65), -INT8_C(   4), -INT8_C(   6), -INT8_C(  81), -INT8_C(   1), -INT8_C( 115),
        -INT8_C(   2), -INT8_C(  20), -INT8_C(  33), -INT8_C(  65), -INT8_C(  38), -INT8_C(  23), -INT8_C(  38), -INT8_C(  71) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16_t a = simde_vld1q_s8(test_vec[i].a);
    simde_int8x16_t b = simde_vld1q_s8(test_vec[i].b);
    simde_int8x16_t r = simde_vorrq_s8(a, b);

    simde_test_arm_neon_assert_equal_i8x16(r, simde_vld1q_s8(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vorrq_s16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int16_t a[8];
    int16_t b[8];
    int16_t r[8];
  } test_vec[] = {
    { {  INT16_C( 13388),  INT16_C( 21211),  INT16_C( 15643),  INT16_C( 19225), -INT16_C(  8663), -INT16_C(  7904), -INT16_C( 29244),  INT16_C( 28768) },
      { -INT16_C(  7306), -INT16_C(  3637),  INT16_C( 28019), -INT16_C( 12496),  INT16_C(  7322),  INT16_C(   853), -INT16_C(   284),  INT16_C( 12518) },
      { -INT16_C(  2178), -INT16_C(  3109),  INT16_C( 32123), -INT16_C( 12487), -INT16_C(  8517), -INT16_C(  7307), -INT16_C(    28),  INT16_C( 28902) } },
    { { -INT16_C( 15821),  INT16_C( 20098), -INT16_C( 25601),  INT16_C( 10649), -INT16_C( 18055),  INT16_C( 15882),  INT16_C( 27206), -INT16_C( 17234) },
      {  INT16_C( 31053), -INT16_C( 16211), -INT16_C(  8730), -INT16_C( 32625), -INT16_C(  6662), -INT16_C(  8572),  INT16_C( 27363),  INT16_C(  5646) },
      { -INT16_C(  1153), -INT16_C( 12625), -INT16_C(  8193), -INT16_C( 22113), -INT16_C(   517), -INT16_C(   370),  INT16_C( 27367), -INT16_C( 16722) } },
    { { -INT16_C( 28628),  INT16_C( 11364), -INT16_C(   468), -INT16_C( 23211),  INT16_C( 24503), -INT16_C(   285), -INT16_C( 28215),  INT16_C(  5818) },
      {  INT16_C( 26635), -INT16_C(  3626),  INT16_C( 25925),  INT16_C( 16242), -INT16_C(  2486),  INT16_C( 11805),  INT16_C( 11104), -INT16_C( 29372) },
      { -INT16_C(  2001), -INT16_C(   522), -INT16_C(   147), -INT16_C( 16521), -INT16_C(     1), -INT16_C(   257), -INT16_C( 17431), -INT16_C( 24578) } },
    { { -INT16_C( 22084), -INT16_C(  5959),  INT16_C(  3751),  INT16_C( 24205),  INT16_C( 29037),  INT16_C( 13916),  INT16_C(  5890),  INT16_C(  3404) },
      {  INT16_C(  8831), -INT16_C( 15105),  INT16_C( 29063), -INT16_C( 11772),  INT16_C(  8551), -INT16_C( 14592),  INT16_C( 17485),  INT16_C(  2388) },
      { -INT16_C( 21505), -INT16_C(  4865),  INT16_C( 32679), -INT16_C(  8563),  INT16_C( 29039), -INT16_C(  2212),  INT16_C( 22351),  INT16_C(  3420) } },
    { {  INT16_C(  3565), -INT16_C( 27407),  INT16_C( 32283), -INT16_C( 30477),  INT16_C( 20463), -INT16_C(  3394),  INT16_C(  2662), -INT16_C(  6657) },
      { -INT16_C(   468), -INT16_C( 19286), -INT16_C( 20881), -INT16_C( 10618), -INT16_C( 31025),  INT16_C(  7326), -INT16_C(  3382), -INT16_C( 18395) },
      { -INT16_C(    19), -INT16_C( 19205), -INT16_C(   385), -INT16_C(  8457), -INT16_C( 12305), -INT16_C(   322), -INT16_C(  1298), -INT16_C(   513) } },
    { {  INT16_C(  5632),  INT16_C(  6988),  INT16_C( 16277), -INT16_C( 31580),  INT16_C( 25231), -INT16_C(  2698),  INT16_C( 30317), -INT16_C( 26149) },
      { -INT16_C( 31372), -INT16_C(  7091), -INT16_C( 11469),  INT16_C(   698),  INT16_C( 22617),  INT16_C(  9247),  INT16_C( 17483),  INT16_C( 19420) },
      { -INT16_C( 26764), -INT16_C(   179), -INT16_C(    73), -INT16_C( 31042),  INT16_C( 31455), -INT16_C(  2689),  INT16_C( 30319), -INT16_C(  9249) } },
    { {  INT16_C( 10331), -INT16_C(  3994),  INT16_C(  2664), -INT16_C(  2188), -INT16_C(  5267), -INT16_C(  9492), -INT16_C( 14495), -INT16_C( 10893) },
      { -INT16_C( 16052),  INT16_C( 32697),  INT16_C( 29844), -INT16_C(  4478), -INT16_C( 24116),  INT16_C(  5906), -INT16_C(  4379),  INT16_C( 16482) },
      { -INT16_C(  5793), -INT16_C(     1),  INT16_C( 32508), -INT16_C(    10), -INT16_C(  5139), -INT16_C(  8194), -INT16_C(  4123), -INT16_C( 10893) } },
    { { -INT16_C( 14058),  INT16_C( 32304), -INT16_C( 23085),  INT16_C( 16501),  INT16_C( 25232), -INT16_C(  3814), -INT16_C( 29143),  INT16_C( 30406) },
      { -INT16_C( 32689), -INT16_C(  7179),  INT16_C( 30708), -INT16_C( 16175), -INT16_C(  7400), -INT16_C(   296),  INT16_C( 15057), -INT16_C(  6082) },
      { -INT16_C( 13985), -INT16_C(    11), -INT16_C(  2057), -INT16_C( 16139), -INT16_C(  7272), -INT16_C(    38), -INT16_C( 16647), -INT16_C(   258) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_int16x8_t b = simde_vld1q_s16(test_vec[i].b);
    simde_int16x8_t r = simde_vorrq_s16(a, b);

    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vorrq_s32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int32_t a[4];
    int32_t b[4];
    int32_t r[4];
  } test_vec[] = {
    { {  INT32_C(  1853195043), -INT32_C(   662805650), -INT32_C(  1554457435),  INT32_C(   316683366) },
      {  INT32_C(   811600762),  INT32_C(  1834839949),  INT32_C(   555751229),  INT32_C(   715490055) },
      {  INT32_C(  2121632635), -INT32_C(    41979921), -INT32_C(  1552359491),  INT32_C(   988133223) } },
    { {  INT32_C(  1956125190),  INT32_C(   575477373),  INT32_C(  1506125299),  INT32_C(  1399629273) },
      {  INT32_C(  1048890545),  INT32_C(  2041372988), -INT32_C(     6566664),  INT32_C(  1428766799) },
      {  INT32_C(  2124209847),  INT32_C(  2079192957), -INT32_C(     2101765),  INT32_C(  1466820063) } },
    { { -INT32_C(   657800870), -INT32_C(   872802344), -INT32_C(  1775976260),  INT32_C(   384405605) },
      { -INT32_C(  1722454691),  INT32_C(  1192362319),  INT32_C(   491236813),  INT32_C(  1215459565) },
      { -INT32_C(   639636129), -INT32_C(   805693473), -INT32_C(  1620578819),  INT32_C(  1593569517) } },
    { {  INT32_C(   169884722),  INT32_C(   282401363),  INT32_C(  1084684762), -INT32_C(   413757558) },
      {  INT32_C(  1283501053),  INT32_C(  2056491692),  INT32_C(   764926528),  INT32_C(  2104822091) },
      {  INT32_C(  1319157759),  INT32_C(  2060950271),  INT32_C(  1840774106), -INT32_C(     8941621) } },
    { { -INT32_C(  1719167674), -INT32_C(  1968612176), -INT32_C(   540389547), -INT32_C(   590994977) },
      {  INT32_C(  2032682700),  INT32_C(   435403737), -INT32_C(   515470698), -INT32_C(   648102765) },
      { -INT32_C(   105916466), -INT32_C(  1677983751), -INT32_C(     3223593), -INT32_C(   572604961) } },
    { {  INT32_C(    24372561), -INT32_C(  1769202623),  INT32_C(  1266046572),  INT32_C(  1143422071) },
      {  INT32_C(  1555910531), -INT32_C(  1602899958), -INT32_C(   847135942), -INT32_C(   911745161) },
      {  INT32_C(  1577054163), -INT32_C(  1224885173), -INT32_C(   805830786), -INT32_C(   844628105) } },
    { {  INT32_C(    97131204), -INT32_C(  1566812618),  INT32_C(   619516589), -INT32_C(   781708210) },
      {  INT32_C(  1848452451),  INT32_C(   252617429), -INT32_C(   706899874),  INT32_C(   882803823) },
      {  INT32_C(  1877950439), -INT32_C(  1348536585), -INT32_C(   167931137), -INT32_C(   167865233) } },
    { { -INT32_C(   734434914),  INT32_C(  1819792831),  INT32_C(   915498215), -INT32_C(   603457159) },
      { -INT32_C(   196463329),  INT32_C(   889477591),  INT32_C(  1477173737),  INT32_C(    59550053) },
      { -INT32_C(   193233505),  INT32_C(  2105007615),  INT32_C(  2124146159), -INT32_C(   544212611) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int32x4_t b = simde_vld1q_s32(test_vec[i].b);
    simde_int32x4_t r = simde_vorrq_s32(a, b);
    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vorrq_s64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int64_t a[2];
    int64_t b[2];
    int64_t r[2];
  } test_vec[] = {
    { { -INT64_C( 7289792402058885751),  INT64_C( 7962744538976951060) },
      {  INT64_C( 4959271613877493853), -INT64_C( 8811573062044955811) },
      { -INT64_C( 2389160221097794083), -INT64_C( 1173370237447316643) } },
    { {  INT64_C( 3408739052754675525), -INT64_C( 1456366311260998302) },
      { -INT64_C( 2515076220118064750), -INT64_C( 4182735194501316494) },
      { -INT64_C(   45344289161107497), -INT64_C( 1154062185669216910) } },
    { {  INT64_C( 1000299032988902807), -INT64_C( 2993713681861684485) },
      {  INT64_C( 7075087877057169874), -INT64_C( 1186764091284166590) },
      {  INT64_C( 8065884243059437015), -INT64_C(    2263495882474757) } },
    { { -INT64_C( 4403813695115689943),  INT64_C( 5615637420298685140) },
      { -INT64_C( 7035803098410936055),  INT64_C( 1908937941248388150) },
      { -INT64_C( 2379080516704954071),  INT64_C( 6917503720056647414) } },
    { {  INT64_C( 8390437693362740968), -INT64_C( 8798490521932874724) },
      { -INT64_C( 8498897969402182380),  INT64_C( 4472521205212540422) },
      { -INT64_C(  108688975236980740), -INT64_C( 4614501322251764194) } },
    { { -INT64_C( 1168299466064920140), -INT64_C( 1938115942705310183) },
      {  INT64_C( 8633227249326528754),  INT64_C( 3631168478866499792) },
      { -INT64_C(   13651590762423818), -INT64_C(  612790816717406503) } },
    { { -INT64_C( 4160391825870860159),  INT64_C( 3052725007824964519) },
      { -INT64_C( 2020358029854134003),  INT64_C( 7410512544945235239) },
      { -INT64_C( 1731775071238753907),  INT64_C( 7989242793809407911) } },
    { {  INT64_C( 6283363364298710974),  INT64_C( 1164791845038820808) },
      {  INT64_C(   59820965681404637),  INT64_C(  663854660148649707) },
      {  INT64_C( 6338534974706147327),  INT64_C( 1819027964574031851) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);
    simde_int64x2_t b = simde_vld1q_s64(test_vec[i].b);
    simde_int64x2_t r = simde_vorrq_s64(a, b);
    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vorrq_u8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint8_t a[16];
    uint8_t b[16];
    uint8_t r[16];
  } test_vec[] = {
    { { UINT8_C(218), UINT8_C(190), UINT8_C( 55), UINT8_C(196), UINT8_C(201), UINT8_C(122), UINT8_C(129), UINT8_C(177),
        UINT8_C(  1), UINT8_C(192), UINT8_C(189), UINT8_C( 65), UINT8_C(239), UINT8_C(179), UINT8_C(198), UINT8_C(110) },
      { UINT8_C( 30), UINT8_C(135), UINT8_C(179), UINT8_C( 66), UINT8_C( 65), UINT8_C(253), UINT8_C(112), UINT8_C( 11),
        UINT8_C(224), UINT8_C( 85), UINT8_C(152), UINT8_C( 57), UINT8_C(139), UINT8_C(214), UINT8_C(122), UINT8_C(101) },
      { UINT8_C(222), UINT8_C(191), UINT8_C(183), UINT8_C(198), UINT8_C(201),    UINT8_MAX, UINT8_C(241), UINT8_C(187),
        UINT8_C(225), UINT8_C(213), UINT8_C(189), UINT8_C(121), UINT8_C(239), UINT8_C(247), UINT8_C(254), UINT8_C(111) } },
    { { UINT8_C(148), UINT8_C(177), UINT8_C( 41), UINT8_C( 93), UINT8_C( 43), UINT8_C(170), UINT8_C( 15), UINT8_C( 44),
        UINT8_C(107), UINT8_C(204), UINT8_C(110), UINT8_C( 90), UINT8_C(127), UINT8_C( 52), UINT8_C(200), UINT8_C(157) },
      { UINT8_C(188), UINT8_C(123), UINT8_C(224), UINT8_C(253), UINT8_C(120), UINT8_C( 80), UINT8_C(  8), UINT8_C( 89),
        UINT8_C(166), UINT8_C(160), UINT8_C(146), UINT8_C( 49), UINT8_C(119), UINT8_C( 12), UINT8_C(150), UINT8_C( 11) },
      { UINT8_C(188), UINT8_C(251), UINT8_C(233), UINT8_C(253), UINT8_C(123), UINT8_C(250), UINT8_C( 15), UINT8_C(125),
        UINT8_C(239), UINT8_C(236), UINT8_C(254), UINT8_C(123), UINT8_C(127), UINT8_C( 60), UINT8_C(222), UINT8_C(159) } },
    { { UINT8_C(189), UINT8_C(192), UINT8_C(105), UINT8_C(232), UINT8_C(106), UINT8_C(120), UINT8_C( 21), UINT8_C(213),
        UINT8_C( 68), UINT8_C(131), UINT8_C( 47), UINT8_C(196), UINT8_C(183), UINT8_C(247), UINT8_C( 97), UINT8_C(115) },
      { UINT8_C(115), UINT8_C( 65), UINT8_C(112), UINT8_C(235), UINT8_C(146), UINT8_C(120), UINT8_C( 68), UINT8_C( 56),
        UINT8_C( 25), UINT8_C(214), UINT8_C(105), UINT8_C(144), UINT8_C(226),    UINT8_MAX, UINT8_C(155), UINT8_C(159) },
      {    UINT8_MAX, UINT8_C(193), UINT8_C(121), UINT8_C(235), UINT8_C(250), UINT8_C(120), UINT8_C( 85), UINT8_C(253),
        UINT8_C( 93), UINT8_C(215), UINT8_C(111), UINT8_C(212), UINT8_C(247),    UINT8_MAX, UINT8_C(251),    UINT8_MAX } },
    { { UINT8_C(191), UINT8_C(  4), UINT8_C(136), UINT8_C( 42), UINT8_C(124), UINT8_C(157),    UINT8_MAX, UINT8_C(193),
        UINT8_C( 32), UINT8_C( 47), UINT8_C(133), UINT8_C(215), UINT8_C( 38), UINT8_C(230), UINT8_C( 75), UINT8_C(153) },
      { UINT8_C( 40), UINT8_C(187), UINT8_C(133), UINT8_C(186), UINT8_C( 52), UINT8_C(201), UINT8_C(242), UINT8_C( 77),
        UINT8_C(160), UINT8_C( 91), UINT8_C(221), UINT8_C(130), UINT8_C( 90), UINT8_C(120), UINT8_C( 34), UINT8_C( 26) },
      { UINT8_C(191), UINT8_C(191), UINT8_C(141), UINT8_C(186), UINT8_C(124), UINT8_C(221),    UINT8_MAX, UINT8_C(205),
        UINT8_C(160), UINT8_C(127), UINT8_C(221), UINT8_C(215), UINT8_C(126), UINT8_C(254), UINT8_C(107), UINT8_C(155) } },
    { { UINT8_C(125), UINT8_C(170), UINT8_C( 68), UINT8_C(249), UINT8_C( 71), UINT8_C( 67), UINT8_C(186), UINT8_C(103),
        UINT8_C(114), UINT8_C( 63), UINT8_C( 62), UINT8_C(153), UINT8_C( 38), UINT8_C(137), UINT8_C( 50), UINT8_C( 78) },
      { UINT8_C( 69), UINT8_C(183), UINT8_C(  8), UINT8_C(121), UINT8_C(129), UINT8_C(250), UINT8_C(198), UINT8_C( 33),
        UINT8_C( 85), UINT8_C(163), UINT8_C(163), UINT8_C(175), UINT8_C( 27), UINT8_C(197), UINT8_C(201), UINT8_C(152) },
      { UINT8_C(125), UINT8_C(191), UINT8_C( 76), UINT8_C(249), UINT8_C(199), UINT8_C(251), UINT8_C(254), UINT8_C(103),
        UINT8_C(119), UINT8_C(191), UINT8_C(191), UINT8_C(191), UINT8_C( 63), UINT8_C(205), UINT8_C(251), UINT8_C(222) } },
    { { UINT8_C(111), UINT8_C( 13), UINT8_C(146), UINT8_C(182), UINT8_C( 81), UINT8_C( 76), UINT8_C( 29), UINT8_C(195),
        UINT8_C(140), UINT8_C( 92), UINT8_C( 92), UINT8_C(178), UINT8_C(229), UINT8_C(143), UINT8_C(  0), UINT8_C( 42) },
      { UINT8_C( 70), UINT8_C(  8), UINT8_C(163), UINT8_C(199), UINT8_C(  2), UINT8_C(105), UINT8_C(232), UINT8_C( 87),
        UINT8_C( 12), UINT8_C(140), UINT8_C(  6), UINT8_C( 40), UINT8_C( 81), UINT8_C(208), UINT8_C(192), UINT8_C(193) },
      { UINT8_C(111), UINT8_C( 13), UINT8_C(179), UINT8_C(247), UINT8_C( 83), UINT8_C(109), UINT8_C(253), UINT8_C(215),
        UINT8_C(140), UINT8_C(220), UINT8_C( 94), UINT8_C(186), UINT8_C(245), UINT8_C(223), UINT8_C(192), UINT8_C(235) } },
    { { UINT8_C(221), UINT8_C( 82), UINT8_C(119), UINT8_C( 46), UINT8_C(159), UINT8_C(149), UINT8_C(242), UINT8_C( 43),
        UINT8_C(241), UINT8_C( 78), UINT8_C(221), UINT8_C(214), UINT8_C(221), UINT8_C(221), UINT8_C(  1), UINT8_C( 36) },
      { UINT8_C(229), UINT8_C(164), UINT8_C(235), UINT8_C(231), UINT8_C( 14), UINT8_C(212), UINT8_C( 62), UINT8_C( 26),
        UINT8_C( 96), UINT8_C( 68), UINT8_C( 66), UINT8_C(177), UINT8_C( 20), UINT8_C(  3), UINT8_C(114), UINT8_C(242) },
      { UINT8_C(253), UINT8_C(246),    UINT8_MAX, UINT8_C(239), UINT8_C(159), UINT8_C(213), UINT8_C(254), UINT8_C( 59),
        UINT8_C(241), UINT8_C( 78), UINT8_C(223), UINT8_C(247), UINT8_C(221), UINT8_C(223), UINT8_C(115), UINT8_C(246) } },
    { { UINT8_C( 85), UINT8_C(234), UINT8_C( 32), UINT8_C(244), UINT8_C(127), UINT8_C( 18), UINT8_C( 31), UINT8_C(112),
        UINT8_C( 97), UINT8_C(252), UINT8_C( 70), UINT8_C( 62), UINT8_C(217), UINT8_C( 71), UINT8_C( 98), UINT8_C(190) },
      { UINT8_C(236), UINT8_C( 78), UINT8_C(165), UINT8_C(250), UINT8_C( 34), UINT8_C(227), UINT8_C( 20), UINT8_C(130),
        UINT8_C( 40), UINT8_C( 87), UINT8_C( 51), UINT8_C( 60), UINT8_C( 90), UINT8_C(166), UINT8_C( 46), UINT8_C(175) },
      { UINT8_C(253), UINT8_C(238), UINT8_C(165), UINT8_C(254), UINT8_C(127), UINT8_C(243), UINT8_C( 31), UINT8_C(242),
        UINT8_C(105),    UINT8_MAX, UINT8_C(119), UINT8_C( 62), UINT8_C(219), UINT8_C(231), UINT8_C(110), UINT8_C(191) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x16_t a = simde_vld1q_u8(test_vec[i].a);
    simde_uint8x16_t b = simde_vld1q_u8(test_vec[i].b);
    simde_uint8x16_t r = simde_vorrq_u8(a, b);

    simde_test_arm_neon_assert_equal_u8x16(r, simde_vld1q_u8(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vorrq_u16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint16_t a[8];
    uint16_t b[8];
    uint16_t r[8];
  } test_vec[] = {
    { { UINT16_C(10801), UINT16_C(20218), UINT16_C(39462), UINT16_C(17462), UINT16_C(43429), UINT16_C(54451), UINT16_C(35031), UINT16_C(64204) },
      { UINT16_C(47232), UINT16_C(47860), UINT16_C(40274), UINT16_C(46114), UINT16_C(30801), UINT16_C(19838), UINT16_C(16556), UINT16_C(56677) },
      { UINT16_C(47793), UINT16_C(65278), UINT16_C(40822), UINT16_C(62518), UINT16_C(63989), UINT16_C(56831), UINT16_C(51455), UINT16_C(65517) } },
    { { UINT16_C(24682), UINT16_C(36907), UINT16_C(25082), UINT16_C(41172), UINT16_C(34571), UINT16_C(57972), UINT16_C(16400), UINT16_C(37084) },
      { UINT16_C(53752), UINT16_C(19019), UINT16_C(28014), UINT16_C(49150), UINT16_C(32229), UINT16_C(37133), UINT16_C(29373), UINT16_C(10094) },
      { UINT16_C(61946), UINT16_C(55915), UINT16_C(28158), UINT16_C(49150), UINT16_C(65519), UINT16_C(62333), UINT16_C(29373), UINT16_C(47102) } },
    { { UINT16_C(39634), UINT16_C(52663), UINT16_C(36091), UINT16_C( 1645), UINT16_C(57619), UINT16_C( 9192), UINT16_C(50465), UINT16_C( 6580) },
      { UINT16_C(65430), UINT16_C( 1123), UINT16_C(25196), UINT16_C(20931), UINT16_C(53471), UINT16_C(40162), UINT16_C(20547), UINT16_C( 5571) },
      { UINT16_C(65494), UINT16_C(52727), UINT16_C(61183), UINT16_C(22511), UINT16_C(61919), UINT16_C(49130), UINT16_C(54627), UINT16_C( 7671) } },
    { { UINT16_C(31466), UINT16_C(59106), UINT16_C(20230), UINT16_C( 6892), UINT16_C(54576), UINT16_C(20797), UINT16_C(61850), UINT16_C(12394) },
      { UINT16_C(52976), UINT16_C(23604), UINT16_C(63280), UINT16_C( 4013), UINT16_C(36808), UINT16_C( 2987), UINT16_C(28384), UINT16_C(51744) },
      { UINT16_C(65274), UINT16_C(65270), UINT16_C(65334), UINT16_C( 8173), UINT16_C(57336), UINT16_C(23487), UINT16_C(65530), UINT16_C(64106) } },
    { { UINT16_C( 1000), UINT16_C(61360), UINT16_C(40274), UINT16_C(33545), UINT16_C(18034), UINT16_C( 3284), UINT16_C(16184), UINT16_C(10300) },
      { UINT16_C(28685), UINT16_C(15749), UINT16_C(12903), UINT16_C(12108), UINT16_C(63426), UINT16_C(41530), UINT16_C(23397), UINT16_C(19820) },
      { UINT16_C(29677), UINT16_C(65461), UINT16_C(49015), UINT16_C(44877), UINT16_C(63474), UINT16_C(44798), UINT16_C(32637), UINT16_C(28028) } },
    { { UINT16_C( 7518), UINT16_C(45116), UINT16_C(17850), UINT16_C(11315), UINT16_C( 2188), UINT16_C(50232), UINT16_C(29767), UINT16_C(21740) },
      { UINT16_C(29156), UINT16_C(19345), UINT16_C(56740), UINT16_C(26235), UINT16_C(46548), UINT16_C(14600), UINT16_C(29712), UINT16_C(28294) },
      { UINT16_C(32254), UINT16_C(64445), UINT16_C(56766), UINT16_C(28283), UINT16_C(48604), UINT16_C(64824), UINT16_C(29783), UINT16_C(32494) } },
    { { UINT16_C(50065), UINT16_C(19231), UINT16_C(21000), UINT16_C(38007), UINT16_C(44890), UINT16_C(41304), UINT16_C(17699), UINT16_C( 2037) },
      { UINT16_C(34486), UINT16_C(23123), UINT16_C(52835), UINT16_C(14272), UINT16_C(51331), UINT16_C(38000), UINT16_C(63293), UINT16_C(52738) },
      { UINT16_C(51127), UINT16_C(23391), UINT16_C(56939), UINT16_C(47095), UINT16_C(61403), UINT16_C(46456), UINT16_C(63295), UINT16_C(53239) } },
    { { UINT16_C( 8634), UINT16_C(49690), UINT16_C(37236), UINT16_C(52823), UINT16_C(44865), UINT16_C(25712), UINT16_C(26100), UINT16_C(43884) },
      { UINT16_C(49132), UINT16_C(20229), UINT16_C(50829), UINT16_C( 4231), UINT16_C(63374), UINT16_C(52132), UINT16_C(42990), UINT16_C(43162) },
      { UINT16_C(49150), UINT16_C(53023), UINT16_C(55293), UINT16_C(57047), UINT16_C(65487), UINT16_C(61428), UINT16_C(59390), UINT16_C(44030) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);
    simde_uint16x8_t b = simde_vld1q_u16(test_vec[i].b);
    simde_uint16x8_t r = simde_vorrq_u16(a, b);
    simde_test_arm_neon_assert_equal_u16x8(r, simde_vld1q_u16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vorrq_u32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint32_t a[4];
    uint32_t b[4];
    uint32_t r[4];
  } test_vec[] = {
    { { UINT32_C(  99494175), UINT32_C(4046041379), UINT32_C(2532327692), UINT32_C(3424227086) },
      { UINT32_C(1287656047), UINT32_C(1421712740), UINT32_C(3503588178), UINT32_C(1167418662) },
      { UINT32_C(1307458431), UINT32_C(4122852711), UINT32_C(3606365022), UINT32_C(3449679662) } },
    { { UINT32_C(2991293326), UINT32_C(1101231157), UINT32_C(3285685173), UINT32_C(2442195234) },
      { UINT32_C(1742622723), UINT32_C(1086036973), UINT32_C(1158713374), UINT32_C(2223678965) },
      { UINT32_C(4158641039), UINT32_C(1102839805), UINT32_C(3352794047), UINT32_C(2509960695) } },
    { { UINT32_C(1563874600), UINT32_C(4271888713), UINT32_C(2395108972), UINT32_C(1780437607) },
      { UINT32_C(2412969378), UINT32_C(3083832729), UINT32_C( 335339293), UINT32_C(2912388996) },
      { UINT32_C(3757505962), UINT32_C(4292861401), UINT32_C(2684288893), UINT32_C(4020230119) } },
    { { UINT32_C(2785725788), UINT32_C( 312781222), UINT32_C(2275436064), UINT32_C(1525858232) },
      { UINT32_C(1458226365), UINT32_C(1863170385), UINT32_C( 495061657), UINT32_C(3989445009) },
      { UINT32_C(4142583293), UINT32_C(2142091767), UINT32_C(2678222521), UINT32_C(4294623161) } },
    { { UINT32_C(2358498790), UINT32_C(2661169278), UINT32_C(1462124190), UINT32_C(3132168445) },
      { UINT32_C( 756063196), UINT32_C(4003208789), UINT32_C(3104513576), UINT32_C( 497473079) },
      { UINT32_C(2912149502), UINT32_C(4271783551), UINT32_C(4281286334), UINT32_C(3216498431) } },
    { { UINT32_C( 698956459), UINT32_C( 281560946), UINT32_C(2204626565), UINT32_C(3795654918) },
      { UINT32_C( 151998132), UINT32_C(2499259500), UINT32_C(  38601674), UINT32_C(2216686553) },
      { UINT32_C( 699367103), UINT32_C(2499800958), UINT32_C(2205151183), UINT32_C(3862952927) } },
    { { UINT32_C(2678966573), UINT32_C(2528146704), UINT32_C(1763252067), UINT32_C(3846919728) },
      { UINT32_C( 284056484), UINT32_C(3517244935), UINT32_C(3268669929), UINT32_C( 306639845) },
      { UINT32_C(2683296685), UINT32_C(3618961175), UINT32_C(3957061611), UINT32_C(4149213173) } },
    { { UINT32_C(3434279868), UINT32_C(3428999785), UINT32_C(2855697273), UINT32_C(1989116370) },
      { UINT32_C(3817307612), UINT32_C(1286941539), UINT32_C(  34506781), UINT32_C( 924079227) },
      { UINT32_C(4021813244), UINT32_C(3438766955), UINT32_C(2856254333), UINT32_C(2006963707) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint32x4_t b = simde_vld1q_u32(test_vec[i].b);
    simde_uint32x4_t r = simde_vorrq_u32(a, b);

    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vorrq_u64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint64_t a[2];
    uint64_t b[2];
    uint64_t r[2];
  } test_vec[] = {
    { { UINT64_C(14452183464467521954), UINT64_C( 9768552466044535994) },
      { UINT64_C( 8323295634090358226), UINT64_C( 6983312523239866925) },
      { UINT64_C(18127684834605135346), UINT64_C(16715672690978965183) } },
    { { UINT64_C( 8658500954789528855), UINT64_C( 3687679955597296624) },
      { UINT64_C( 2807013575393128506), UINT64_C(   28059438019851078) },
      { UINT64_C( 9150663531423462719), UINT64_C( 3706444805173523446) } },
    { { UINT64_C( 1957528908326895604), UINT64_C( 6818994250571767565) },
      { UINT64_C( 7836495514368451232), UINT64_C( 3022147574291203335) },
      { UINT64_C( 9217420585431203828), UINT64_C( 9219430515284631311) } },
    { { UINT64_C(16796463827198366162), UINT64_C( 7739429135089916901) },
      { UINT64_C( 2318724998057182875), UINT64_C( 4802808010765278538) },
      { UINT64_C(16806808032609523675), UINT64_C( 7775458140247023599) } },
    { { UINT64_C( 7932627338875929425), UINT64_C(  174477540259753269) },
      { UINT64_C( 9105980703266533412), UINT64_C(13853253254717992590) },
      { UINT64_C( 9105992286793364341), UINT64_C(14009570822839037887) } },
    { { UINT64_C( 1161369996009242919), UINT64_C(10941913606644667761) },
      { UINT64_C( 2062423839904996844), UINT64_C( 7552917285566586017) },
      { UINT64_C( 2062424190215888367), UINT64_C(18435905585613086193) } },
    { { UINT64_C( 3731012125718068955), UINT64_C( 4744793257937656013) },
      { UINT64_C( 9307535116733689217), UINT64_C( 8883178328313447838) },
      { UINT64_C(12965643299237642203), UINT64_C( 8926107935186804191) } },
    { { UINT64_C( 7284282782848737313), UINT64_C( 9684565509766717904) },
      { UINT64_C( 7461550652344617002), UINT64_C(11682212645880339973) },
      { UINT64_C( 7466678847073019947), UINT64_C(11997588881817419733) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x2_t a = simde_vld1q_u64(test_vec[i].a);
    simde_uint64x2_t b = simde_vld1q_u64(test_vec[i].b);
    simde_uint64x2_t r = simde_vorrq_u64(a, b);
    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[i].r));
  }

  return 0;
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vorr_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vorr_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vorr_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vorr_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vorr_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vorr_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vorr_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vorr_u64)

SIMDE_TEST_FUNC_LIST_ENTRY(vorrq_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vorrq_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vorrq_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vorrq_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vorrq_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vorrq_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vorrq_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vorrq_u64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
