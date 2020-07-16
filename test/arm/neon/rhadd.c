#define SIMDE_TEST_ARM_NEON_INSN rhadd

#include "test-neon.h"
#include "../../../simde/arm/neon/rhadd.h"

static int
test_simde_vrhadd_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[8];
    int8_t b[8];
    int8_t r[8];
  } test_vec[] = {
    { {  INT8_C(  36), -INT8_C(  29), -INT8_C(  56),  INT8_C(  59), -INT8_C(  57), -INT8_C(  47),  INT8_C(  80), -INT8_C( 118) },
      {  INT8_C(  67),  INT8_C(  70),  INT8_C(   3), -INT8_C(  93),  INT8_C(  56), -INT8_C(  95), -INT8_C(  31), -INT8_C(  57) },
      {  INT8_C(  52),  INT8_C(  21), -INT8_C(  26), -INT8_C(  17),  INT8_C(   0), -INT8_C(  71),  INT8_C(  25), -INT8_C(  87) } },
    { {  INT8_C( 122), -INT8_C(  28),  INT8_C(  39), -INT8_C(  51),  INT8_C(  36),  INT8_C( 123), -INT8_C( 105), -INT8_C(  67) },
      { -INT8_C(  33),  INT8_C( 123), -INT8_C(  90), -INT8_C( 110), -INT8_C(  50), -INT8_C( 124), -INT8_C(  64), -INT8_C(  14) },
      {  INT8_C(  45),  INT8_C(  48), -INT8_C(  25), -INT8_C(  80), -INT8_C(   7),  INT8_C(   0), -INT8_C(  84), -INT8_C(  40) } },
    { {  INT8_C( 103), -INT8_C( 119),  INT8_C(  45),  INT8_C(  46),  INT8_C(  90),  INT8_C( 125), -INT8_C(  72), -INT8_C(  99) },
      { -INT8_C(  61), -INT8_C(  69),  INT8_C(  64), -INT8_C(   5),  INT8_C(  92),  INT8_C(  34), -INT8_C(  62), -INT8_C(  42) },
      {  INT8_C(  21), -INT8_C(  94),  INT8_C(  55),  INT8_C(  21),  INT8_C(  91),  INT8_C(  80), -INT8_C(  67), -INT8_C(  70) } },
    { {  INT8_C(   6), -INT8_C(  22), -INT8_C(  92),  INT8_C(  42),  INT8_C( 101),  INT8_C(  59), -INT8_C(  25),  INT8_C(  68) },
      { -INT8_C(  74), -INT8_C( 114), -INT8_C(  42), -INT8_C( 124),  INT8_C(  18), -INT8_C( 105),  INT8_C( 119),  INT8_C( 121) },
      { -INT8_C(  34), -INT8_C(  68), -INT8_C(  67), -INT8_C(  41),  INT8_C(  60), -INT8_C(  23),  INT8_C(  47),  INT8_C(  95) } },
    { {  INT8_C(  32), -INT8_C(  92), -INT8_C(  89),  INT8_C( 122),  INT8_C(  34),  INT8_C(  96),  INT8_C(  24), -INT8_C(  27) },
      {  INT8_C(  27),  INT8_C(  88), -INT8_C(  31),  INT8_C( 120),  INT8_C( 122), -INT8_C(  93),  INT8_C(  78), -INT8_C( 127) },
      {  INT8_C(  30), -INT8_C(   2), -INT8_C(  60),  INT8_C( 121),  INT8_C(  78),  INT8_C(   2),  INT8_C(  51), -INT8_C(  77) } },
    { { -INT8_C( 115), -INT8_C(  14), -INT8_C(  85), -INT8_C(  13),  INT8_C(  45), -INT8_C( 109),  INT8_C(  55), -INT8_C(  29) },
      {  INT8_C(  33),  INT8_C(  14),  INT8_C( 104),  INT8_C(  51), -INT8_C(  91), -INT8_C(  33), -INT8_C(  84), -INT8_C(  59) },
      { -INT8_C(  41),  INT8_C(   0),  INT8_C(  10),  INT8_C(  19), -INT8_C(  23), -INT8_C(  71), -INT8_C(  14), -INT8_C(  44) } },
    { { -INT8_C( 125),  INT8_C(  83),  INT8_C(  63), -INT8_C(  91), -INT8_C(  77),  INT8_C(  87), -INT8_C( 117), -INT8_C(  49) },
      { -INT8_C(  80),  INT8_C( 108),  INT8_C(  71),  INT8_C(  42),  INT8_C(  15), -INT8_C( 107), -INT8_C(  85), -INT8_C(  99) },
      { -INT8_C( 102),  INT8_C(  96),  INT8_C(  67), -INT8_C(  24), -INT8_C(  31), -INT8_C(  10), -INT8_C( 101), -INT8_C(  74) } },
    { { -INT8_C( 120),  INT8_C(  87), -INT8_C( 112), -INT8_C(  75), -INT8_C(  22), -INT8_C(  57), -INT8_C( 103),  INT8_C(  11) },
      { -INT8_C(  43),  INT8_C(   1),  INT8_C(  62),  INT8_C( 122), -INT8_C(  32), -INT8_C(  22),  INT8_C(  63),  INT8_C(  99) },
      { -INT8_C(  81),  INT8_C(  44), -INT8_C(  25),  INT8_C(  24), -INT8_C(  27), -INT8_C(  39), -INT8_C(  20),  INT8_C(  55) } },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8_t a = simde_vld1_s8(test_vec[i].a);
    simde_int8x8_t b = simde_vld1_s8(test_vec[i].b);
    simde_int8x8_t r = simde_vrhadd_s8(a, b);

    simde_test_arm_neon_assert_equal_i8x8(r, simde_vld1_s8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x8_t a = simde_test_arm_neon_random_i8x8();
    simde_int8x8_t b = simde_test_arm_neon_random_i8x8();
    simde_int8x8_t r = simde_vrhadd_s8(a, b);

    simde_test_arm_neon_write_i8x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vrhadd_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[4];
    int16_t b[4];
    int16_t r[4];
  } test_vec[] = {
    { { -INT16_C( 14695),  INT16_C(  2201), -INT16_C( 12911), -INT16_C( 29684) },
      {  INT16_C( 27918),  INT16_C( 16028), -INT16_C( 16180), -INT16_C( 15218) },
      {  INT16_C(  6612),  INT16_C(  9115), -INT16_C( 14545), -INT16_C( 22451) } },
    { {  INT16_C( 19026),  INT16_C( 15451), -INT16_C(  3167), -INT16_C( 15174) },
      { -INT16_C( 13769),  INT16_C( 10656),  INT16_C(   509), -INT16_C( 26635) },
      {  INT16_C(  2629),  INT16_C( 13054), -INT16_C(  1329), -INT16_C( 20904) } },
    { { -INT16_C( 28984),  INT16_C( 22943), -INT16_C( 21668),  INT16_C( 27365) },
      { -INT16_C( 32232), -INT16_C(  6744),  INT16_C( 13890), -INT16_C( 27223) },
      { -INT16_C( 30608),  INT16_C(  8100), -INT16_C(  3889),  INT16_C(    71) } },
    { {  INT16_C(  1152),  INT16_C(  8657), -INT16_C( 29449),  INT16_C( 12005) },
      { -INT16_C( 31402),  INT16_C( 21335),  INT16_C( 19591),  INT16_C( 20458) },
      { -INT16_C( 15125),  INT16_C( 14996), -INT16_C(  4929),  INT16_C( 16232) } },
    { { -INT16_C( 30245),  INT16_C( 14248), -INT16_C( 29131),  INT16_C( 19873) },
      {  INT16_C( 18704),  INT16_C( 21042), -INT16_C(  9345), -INT16_C(    25) },
      { -INT16_C(  5770),  INT16_C( 17645), -INT16_C( 19238),  INT16_C(  9924) } },
    { { -INT16_C( 17953), -INT16_C( 10720),  INT16_C(  1349), -INT16_C( 25852) },
      {  INT16_C( 23691),  INT16_C(  4846), -INT16_C(  9816), -INT16_C( 31903) },
      {  INT16_C(  2869), -INT16_C(  2937), -INT16_C(  4233), -INT16_C( 28877) } },
    { {  INT16_C(  2402), -INT16_C( 26694),  INT16_C( 23447), -INT16_C( 22555) },
      {  INT16_C(  6052),  INT16_C(  9210), -INT16_C(  7693), -INT16_C( 11742) },
      {  INT16_C(  4227), -INT16_C(  8742),  INT16_C(  7877), -INT16_C( 17148) } },
    { {  INT16_C( 17050), -INT16_C(  8279), -INT16_C( 21176), -INT16_C( 11398) },
      {  INT16_C( 26889), -INT16_C( 19739),  INT16_C( 17986), -INT16_C( 23499) },
      {  INT16_C( 21970), -INT16_C( 14009), -INT16_C(  1595), -INT16_C( 17448) } },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t a = simde_vld1_s16(test_vec[i].a);
    simde_int16x4_t b = simde_vld1_s16(test_vec[i].b);
    simde_int16x4_t r = simde_vrhadd_s16(a, b);

    simde_test_arm_neon_assert_equal_i16x4(r, simde_vld1_s16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x4_t a = simde_test_arm_neon_random_i16x4();
    simde_int16x4_t b = simde_test_arm_neon_random_i16x4();
    simde_int16x4_t r = simde_vrhadd_s16(a, b);

    simde_test_arm_neon_write_i16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vrhadd_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[2];
    int32_t b[2];
    int32_t r[2];
  } test_vec[] = {
    { { -INT32_C(  2031040152),  INT32_C(  1764816448) },
      { -INT32_C(   381377707), -INT32_C(  1742334847) },
      { -INT32_C(  1206208929),  INT32_C(    11240801) } },
    { {  INT32_C(  1058518367),  INT32_C(  1886799718) },
      { -INT32_C(   157827149), -INT32_C(   303142780) },
      {  INT32_C(   450345609),  INT32_C(   791828469) } },
    { {  INT32_C(  1920196145),  INT32_C(   702260180) },
      { -INT32_C(   955048122), -INT32_C(  1822475980) },
      {  INT32_C(   482574012), -INT32_C(   560107900) } },
    { {  INT32_C(  1439856366),  INT32_C(  1908754621) },
      { -INT32_C(  1939383288), -INT32_C(   159820092) },
      { -INT32_C(   249763461),  INT32_C(   874467265) } },
    { {  INT32_C(   157871156), -INT32_C(   718126193) },
      { -INT32_C(  1751300765),  INT32_C(  1831533695) },
      { -INT32_C(   796714804),  INT32_C(   556703751) } },
    { {  INT32_C(   818084979),  INT32_C(  1285654340) },
      { -INT32_C(  1462171165), -INT32_C(  1818340769) },
      { -INT32_C(   322043093), -INT32_C(   266343214) } },
    { { -INT32_C(   828635585), -INT32_C(  1398485175) },
      { -INT32_C(  1824308972), -INT32_C(  1342083779) },
      { -INT32_C(  1326472278), -INT32_C(  1370284477) } },
    { { -INT32_C(  1360936087),  INT32_C(   788169291) },
      { -INT32_C(   355019893),  INT32_C(  1702786086) },
      { -INT32_C(   857977990),  INT32_C(  1245477689) } },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t a = simde_vld1_s32(test_vec[i].a);
    simde_int32x2_t b = simde_vld1_s32(test_vec[i].b);
    simde_int32x2_t r = simde_vrhadd_s32(a, b);

    simde_test_arm_neon_assert_equal_i32x2(r, simde_vld1_s32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x2_t a = simde_test_arm_neon_random_i32x2();
    simde_int32x2_t b = simde_test_arm_neon_random_i32x2();
    simde_int32x2_t r = simde_vrhadd_s32(a, b);

    simde_test_arm_neon_write_i32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}


static int
test_simde_vrhadd_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t a[8];
    uint8_t b[8];
    uint8_t r[8];
  } test_vec[] = {
    { { UINT8_C( 80), UINT8_C(186), UINT8_C(146), UINT8_C(154), UINT8_C(188), UINT8_C(150), UINT8_C(103), UINT8_C( 95) },
      { UINT8_C( 52), UINT8_C(115), UINT8_C(142), UINT8_C( 80), UINT8_C( 70), UINT8_C( 37), UINT8_C(168), UINT8_C(229) },
      { UINT8_C( 66), UINT8_C(151), UINT8_C(144), UINT8_C(117), UINT8_C(129), UINT8_C( 94), UINT8_C(136), UINT8_C(162) } },
    { { UINT8_C(180), UINT8_C( 27), UINT8_C(135), UINT8_C(242), UINT8_C( 51), UINT8_C(146), UINT8_C( 99), UINT8_C(105) },
      { UINT8_C(117), UINT8_C(218), UINT8_C(  3), UINT8_C(199), UINT8_C(230), UINT8_C(129), UINT8_C(195), UINT8_C( 55) },
      { UINT8_C(149), UINT8_C(123), UINT8_C( 69), UINT8_C(221), UINT8_C(141), UINT8_C(138), UINT8_C(147), UINT8_C( 80) } },
    { { UINT8_C( 59), UINT8_C( 85), UINT8_C(209), UINT8_C(247), UINT8_C(235), UINT8_C( 56), UINT8_C( 86), UINT8_C( 31) },
      { UINT8_C(171), UINT8_C(229), UINT8_C(111), UINT8_C(241), UINT8_C( 10), UINT8_C( 23), UINT8_C(214), UINT8_C(191) },
      { UINT8_C(115), UINT8_C(157), UINT8_C(160), UINT8_C(244), UINT8_C(123), UINT8_C( 40), UINT8_C(150), UINT8_C(111) } },
    { { UINT8_C( 50), UINT8_C( 94), UINT8_C(177), UINT8_C(101), UINT8_C(240), UINT8_C( 20), UINT8_C(206), UINT8_C(101) },
      { UINT8_C(238), UINT8_C(209), UINT8_C( 44), UINT8_C(213), UINT8_C( 82), UINT8_C(239), UINT8_C( 12), UINT8_C(141) },
      { UINT8_C(144), UINT8_C(152), UINT8_C(111), UINT8_C(157), UINT8_C(161), UINT8_C(130), UINT8_C(109), UINT8_C(121) } },
    { { UINT8_C( 68), UINT8_C(221), UINT8_C(133), UINT8_C( 47), UINT8_C( 21), UINT8_C(219), UINT8_C( 79), UINT8_C(192) },
      { UINT8_C(192), UINT8_C(190), UINT8_C(177), UINT8_C(203), UINT8_C(214), UINT8_C(135), UINT8_C(138), UINT8_C(  8) },
      { UINT8_C(130), UINT8_C(206), UINT8_C(155), UINT8_C(125), UINT8_C(118), UINT8_C(177), UINT8_C(109), UINT8_C(100) } },
    { { UINT8_C(229), UINT8_C( 59), UINT8_C(110), UINT8_C(213), UINT8_C( 79), UINT8_C( 60), UINT8_C( 58), UINT8_C( 61) },
      { UINT8_C( 14), UINT8_C(102), UINT8_C( 18), UINT8_C( 96), UINT8_C( 85), UINT8_C( 30), UINT8_C(238), UINT8_C(153) },
      { UINT8_C(122), UINT8_C( 81), UINT8_C( 64), UINT8_C(155), UINT8_C( 82), UINT8_C( 45), UINT8_C(148), UINT8_C(107) } },
    { { UINT8_C(251), UINT8_C(115), UINT8_C(201), UINT8_C( 16), UINT8_C( 78), UINT8_C( 24), UINT8_C(208), UINT8_C( 15) },
      { UINT8_C(214), UINT8_C(129), UINT8_C(218), UINT8_C(172), UINT8_C(  9), UINT8_C(100), UINT8_C(181), UINT8_C(238) },
      { UINT8_C(233), UINT8_C(122), UINT8_C(210), UINT8_C( 94), UINT8_C( 44), UINT8_C( 62), UINT8_C(195), UINT8_C(127) } },
    { { UINT8_C(159), UINT8_C( 35), UINT8_C(196), UINT8_C(238), UINT8_C( 95), UINT8_C(254), UINT8_C( 43), UINT8_C(109) },
      { UINT8_C(101), UINT8_C( 62), UINT8_C(206), UINT8_C(186), UINT8_C( 92), UINT8_C(188), UINT8_C( 84), UINT8_C( 88) },
      { UINT8_C(130), UINT8_C( 49), UINT8_C(201), UINT8_C(212), UINT8_C( 94), UINT8_C(221), UINT8_C( 64), UINT8_C( 99) } },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x8_t a = simde_vld1_u8(test_vec[i].a);
    simde_uint8x8_t b = simde_vld1_u8(test_vec[i].b);
    simde_uint8x8_t r = simde_vrhadd_u8(a, b);

    simde_test_arm_neon_assert_equal_u8x8(r, simde_vld1_u8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8x8_t a = simde_test_arm_neon_random_u8x8();
    simde_uint8x8_t b = simde_test_arm_neon_random_u8x8();
    simde_uint8x8_t r = simde_vrhadd_u8(a, b);

    simde_test_arm_neon_write_u8x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vrhadd_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[4];
    uint16_t b[4];
    uint16_t r[4];
  } test_vec[] = {
    { { UINT16_C(20571), UINT16_C(32595), UINT16_C(53673), UINT16_C(25528) },
      { UINT16_C(32933), UINT16_C(36832), UINT16_C(64829), UINT16_C(10516) },
      { UINT16_C(26752), UINT16_C(34714), UINT16_C(59251), UINT16_C(18022) } },
    { { UINT16_C(59927), UINT16_C(49725), UINT16_C(56129), UINT16_C(50223) },
      { UINT16_C(19705), UINT16_C(59602), UINT16_C(22360), UINT16_C(45941) },
      { UINT16_C(39816), UINT16_C(54664), UINT16_C(39245), UINT16_C(48082) } },
    { { UINT16_C(51367), UINT16_C(20786), UINT16_C(60313), UINT16_C(16052) },
      { UINT16_C(37995), UINT16_C(43213), UINT16_C(58001), UINT16_C(43218) },
      { UINT16_C(44681), UINT16_C(32000), UINT16_C(59157), UINT16_C(29635) } },
    { { UINT16_C( 4044), UINT16_C( 3691), UINT16_C(39658), UINT16_C(58322) },
      { UINT16_C(42214), UINT16_C(16075), UINT16_C(16636), UINT16_C(41970) },
      { UINT16_C(23129), UINT16_C( 9883), UINT16_C(28147), UINT16_C(50146) } },
    { { UINT16_C( 9225), UINT16_C(41716), UINT16_C(43279), UINT16_C(31457) },
      { UINT16_C(44605), UINT16_C(53027), UINT16_C(62864), UINT16_C(23927) },
      { UINT16_C(26915), UINT16_C(47372), UINT16_C(53072), UINT16_C(27692) } },
    { { UINT16_C(57860), UINT16_C(61035), UINT16_C(15740), UINT16_C(25297) },
      { UINT16_C(40417), UINT16_C(56737), UINT16_C(37853), UINT16_C(59009) },
      { UINT16_C(49139), UINT16_C(58886), UINT16_C(26797), UINT16_C(42153) } },
    { { UINT16_C(30135), UINT16_C(51081), UINT16_C(27166), UINT16_C(23617) },
      { UINT16_C(25624), UINT16_C(43307), UINT16_C(41561), UINT16_C(23814) },
      { UINT16_C(27880), UINT16_C(47194), UINT16_C(34364), UINT16_C(23716) } },
    { { UINT16_C(29061), UINT16_C(  331), UINT16_C( 7598), UINT16_C(36708) },
      { UINT16_C( 1466), UINT16_C(38765), UINT16_C(61080), UINT16_C(20350) },
      { UINT16_C(15264), UINT16_C(19548), UINT16_C(34339), UINT16_C(28529) } },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4_t a = simde_vld1_u16(test_vec[i].a);
    simde_uint16x4_t b = simde_vld1_u16(test_vec[i].b);
    simde_uint16x4_t r = simde_vrhadd_u16(a, b);
    simde_test_arm_neon_assert_equal_u16x4(r, simde_vld1_u16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x4_t a = simde_test_arm_neon_random_u16x4();
    simde_uint16x4_t b = simde_test_arm_neon_random_u16x4();
    simde_uint16x4_t r = simde_vrhadd_u16(a, b);

    simde_test_arm_neon_write_u16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vrhadd_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[2];
    uint32_t b[2];
    uint32_t r[2];
  } test_vec[] = {
    { { UINT32_C( 499522018), UINT32_C(1059676568) },
      { UINT32_C( 159590395), UINT32_C(3867488461) },
      { UINT32_C( 329556207), UINT32_C(2463582515) } },
    { { UINT32_C(2140259654), UINT32_C(3410156506) },
      { UINT32_C(3081595877), UINT32_C( 210904874) },
      { UINT32_C(2610927766), UINT32_C(1810530690) } },
    { { UINT32_C(3626588224), UINT32_C(3021427385) },
      { UINT32_C(1203608186), UINT32_C( 288178891) },
      { UINT32_C(2415098205), UINT32_C(1654803138) } },
    { { UINT32_C(3801202440), UINT32_C(2142098330) },
      { UINT32_C(1748392510), UINT32_C(3245721985) },
      { UINT32_C(2774797475), UINT32_C(2693910158) } },
    { { UINT32_C(3684277793), UINT32_C(1804579313) },
      { UINT32_C( 380783947), UINT32_C(2536038543) },
      { UINT32_C(2032530870), UINT32_C(2170308928) } },
    { { UINT32_C( 964278687), UINT32_C(3401066124) },
      { UINT32_C(  20180608), UINT32_C(3653413047) },
      { UINT32_C( 492229648), UINT32_C(3527239586) } },
    { { UINT32_C( 934566982), UINT32_C(1487029005) },
      { UINT32_C( 544167312), UINT32_C(3568801589) },
      { UINT32_C( 739367147), UINT32_C(2527915297) } },
    { { UINT32_C(3691852112), UINT32_C(3634808151) },
      { UINT32_C(1809439155), UINT32_C(3359939713) },
      { UINT32_C(2750645634), UINT32_C(3497373932) } },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2_t a = simde_vld1_u32(test_vec[i].a);
    simde_uint32x2_t b = simde_vld1_u32(test_vec[i].b);
    simde_uint32x2_t r = simde_vrhadd_u32(a, b);
    simde_test_arm_neon_assert_equal_u32x2(r, simde_vld1_u32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x2_t a = simde_test_arm_neon_random_u32x2();
    simde_uint32x2_t b = simde_test_arm_neon_random_u32x2();
    simde_uint32x2_t r = simde_vrhadd_u32(a, b);

    simde_test_arm_neon_write_u32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}


static int
test_simde_vrhaddq_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[16];
    int8_t b[16];
    int8_t r[16];
  } test_vec[] = {
    { {  INT8_C(  15), -INT8_C( 106),  INT8_C(  68), -INT8_C(  52), -INT8_C(  14), -INT8_C(  27),  INT8_C(  43), -INT8_C(  62),
        -INT8_C(  19),  INT8_C(   7),  INT8_C(  93), -INT8_C(  28),  INT8_C(  22),  INT8_C(  11), -INT8_C( 122), -INT8_C(  60) },
      {  INT8_C( 112), -INT8_C(   6),  INT8_C(  83), -INT8_C(  35),  INT8_C( 100), -INT8_C( 104), -INT8_C(  75), -INT8_C(  91),
         INT8_C(  32), -INT8_C(  61), -INT8_C(  52), -INT8_C(  87), -INT8_C( 102),  INT8_C(  44), -INT8_C(  11), -INT8_C(  87) },
      {  INT8_C(  64), -INT8_C(  56),  INT8_C(  76), -INT8_C(  43),  INT8_C(  43), -INT8_C(  65), -INT8_C(  16), -INT8_C(  76),
         INT8_C(   7), -INT8_C(  27),  INT8_C(  21), -INT8_C(  57), -INT8_C(  40),  INT8_C(  28), -INT8_C(  66), -INT8_C(  73) } },
    { { -INT8_C(  61),  INT8_C(  57),  INT8_C( 118), -INT8_C(  75),  INT8_C(  31), -INT8_C(  95),  INT8_C( 120),  INT8_C(  12),
        -INT8_C(  88), -INT8_C(  43), -INT8_C(  16), -INT8_C(  65), -INT8_C(  32),  INT8_C( 119), -INT8_C( 125),  INT8_C(  80) },
      {  INT8_C( 113), -INT8_C(  41),  INT8_C(  46), -INT8_C(  43),  INT8_C( 111), -INT8_C(  29),  INT8_C( 122), -INT8_C( 113),
        -INT8_C(  89),  INT8_C(  70),  INT8_C(  57),  INT8_C(  65),  INT8_C( 115),  INT8_C(  46), -INT8_C(  21),  INT8_C(  54) },
      {  INT8_C(  26),  INT8_C(   8),  INT8_C(  82), -INT8_C(  59),  INT8_C(  71), -INT8_C(  62),  INT8_C( 121), -INT8_C(  50),
        -INT8_C(  88),  INT8_C(  14),  INT8_C(  21),  INT8_C(   0),  INT8_C(  42),  INT8_C(  83), -INT8_C(  73),  INT8_C(  67) } },
    { {  INT8_C( 104),  INT8_C(  97), -INT8_C(  21), -INT8_C( 121),  INT8_C(   2),  INT8_C(  99), -INT8_C( 109), -INT8_C(  85),
         INT8_C(  56), -INT8_C( 125),  INT8_C( 106),  INT8_C(  25), -INT8_C(   6), -INT8_C(  19),  INT8_C( 105),  INT8_C( 107) },
      { -INT8_C(  60), -INT8_C( 105),  INT8_C(  65),  INT8_C(  51),  INT8_C( 123), -INT8_C(  69), -INT8_C(  61),  INT8_C(  34),
         INT8_C(   2), -INT8_C(   4),  INT8_C(  99),  INT8_C( 117),  INT8_C(  42),  INT8_C(  78), -INT8_C(  85), -INT8_C( 110) },
      {  INT8_C(  22), -INT8_C(   4),  INT8_C(  22), -INT8_C(  35),  INT8_C(  63),  INT8_C(  15), -INT8_C(  85), -INT8_C(  25),
         INT8_C(  29), -INT8_C(  64),  INT8_C( 103),  INT8_C(  71),  INT8_C(  18),  INT8_C(  30),  INT8_C(  10), -INT8_C(   1) } },
    { { -INT8_C(  81), -INT8_C( 106),  INT8_C(  25), -INT8_C(  78), -INT8_C(   6), -INT8_C(  84),  INT8_C(  93),  INT8_C(  50),
         INT8_C(  48), -INT8_C(  57),  INT8_C(  75),  INT8_C(  42), -INT8_C(  76), -INT8_C(  75), -INT8_C( 106),  INT8_C( 121) },
      {  INT8_C(  76), -INT8_C(  41), -INT8_C(  84), -INT8_C(  57), -INT8_C( 110),  INT8_C( 111), -INT8_C(  23), -INT8_C( 108),
         INT8_C( 107),  INT8_C(  77),  INT8_C(   9), -INT8_C( 106), -INT8_C( 101), -INT8_C(  76),  INT8_C(  40),  INT8_C(  75) },
      { -INT8_C(   2), -INT8_C(  73), -INT8_C(  29), -INT8_C(  67), -INT8_C(  58),  INT8_C(  14),  INT8_C(  35), -INT8_C(  29),
         INT8_C(  78),  INT8_C(  10),  INT8_C(  42), -INT8_C(  32), -INT8_C(  88), -INT8_C(  75), -INT8_C(  33),  INT8_C(  98) } },
    { {  INT8_C(  75),  INT8_C(  66), -INT8_C(   3),  INT8_C(  69), -INT8_C(  18),  INT8_C(  90),  INT8_C( 119),  INT8_C(  30),
         INT8_C(  33), -INT8_C(  61),  INT8_C(  73), -INT8_C(  43),  INT8_C( 120), -INT8_C(  33),  INT8_C(  78), -INT8_C(  60) },
      { -INT8_C(  74), -INT8_C(   5), -INT8_C( 116),  INT8_C(  72),  INT8_C( 106),  INT8_C( 117), -INT8_C(  35), -INT8_C(  42),
        -INT8_C(  62), -INT8_C(  26),  INT8_C( 108),  INT8_C(  94), -INT8_C( 101), -INT8_C( 108), -INT8_C(  87), -INT8_C(  26) },
      {  INT8_C(   1),  INT8_C(  31), -INT8_C(  59),  INT8_C(  71),  INT8_C(  44),  INT8_C( 104),  INT8_C(  42), -INT8_C(   6),
        -INT8_C(  14), -INT8_C(  43),  INT8_C(  91),  INT8_C(  26),  INT8_C(  10), -INT8_C(  70), -INT8_C(   4), -INT8_C(  43) } },
    { { -INT8_C(  42), -INT8_C(  90),  INT8_C(  43), -INT8_C(  59),  INT8_C(   0), -INT8_C(  94), -INT8_C(  29),  INT8_C(  33),
         INT8_C( 101),  INT8_C(  44), -INT8_C(  10), -INT8_C(  35),  INT8_C(  11),  INT8_C(  69), -INT8_C(  94), -INT8_C(  63) },
      {  INT8_C(  64),  INT8_C(  46),  INT8_C(  10), -INT8_C(  86), -INT8_C(  93), -INT8_C(  25),      INT8_MIN,  INT8_C( 102),
        -INT8_C(  51), -INT8_C(  20), -INT8_C(  60),  INT8_C( 104), -INT8_C( 127),  INT8_C( 109),  INT8_C(  78),  INT8_C(  87) },
      {  INT8_C(  11), -INT8_C(  22),  INT8_C(  27), -INT8_C(  72), -INT8_C(  46), -INT8_C(  59), -INT8_C(  78),  INT8_C(  68),
         INT8_C(  25),  INT8_C(  12), -INT8_C(  35),  INT8_C(  35), -INT8_C(  58),  INT8_C(  89), -INT8_C(   8),  INT8_C(  12) } },
    { {  INT8_C(  19),  INT8_C( 121),  INT8_C(  28),  INT8_C(  19),  INT8_C(  28),  INT8_C(   0),  INT8_C(  52), -INT8_C( 127),
         INT8_C(  44),  INT8_C(  42),  INT8_C(  95),  INT8_C(  56),  INT8_C( 111),  INT8_C(   1), -INT8_C(   7), -INT8_C(  81) },
      {  INT8_C(  47),  INT8_C(   3),  INT8_C(  90), -INT8_C(  46), -INT8_C(  22), -INT8_C(  38),  INT8_C(  56), -INT8_C(  72),
        -INT8_C(  57), -INT8_C(   4),  INT8_C(  32),  INT8_C(  72),  INT8_C( 105),  INT8_C( 111), -INT8_C(  97),  INT8_C( 124) },
      {  INT8_C(  33),  INT8_C(  62),  INT8_C(  59), -INT8_C(  13),  INT8_C(   3), -INT8_C(  19),  INT8_C(  54), -INT8_C(  99),
        -INT8_C(   6),  INT8_C(  19),  INT8_C(  64),  INT8_C(  64),  INT8_C( 108),  INT8_C(  56), -INT8_C(  52),  INT8_C(  22) } },
    { { -INT8_C(  24), -INT8_C(  68), -INT8_C( 113),  INT8_C(   4), -INT8_C(  68), -INT8_C(  61), -INT8_C( 122), -INT8_C(  24),
        -INT8_C(  18), -INT8_C(  27),  INT8_C(  32),  INT8_C(  93), -INT8_C(  26),  INT8_C(  26),  INT8_C(  13),  INT8_C(  21) },
      {  INT8_C(  29),  INT8_C( 103), -INT8_C(  25),  INT8_C(   8),  INT8_C(  65),  INT8_C(  32), -INT8_C(  64),  INT8_C(   8),
         INT8_C(  28), -INT8_C(  32),  INT8_C(  80), -INT8_C( 122),  INT8_C(  79), -INT8_C(  16),  INT8_C(   2),  INT8_C(  56) },
      {  INT8_C(   3),  INT8_C(  18), -INT8_C(  69),  INT8_C(   6), -INT8_C(   1), -INT8_C(  14), -INT8_C(  93), -INT8_C(   8),
         INT8_C(   5), -INT8_C(  29),  INT8_C(  56), -INT8_C(  14),  INT8_C(  27),  INT8_C(   5),  INT8_C(   8),  INT8_C(  39) } },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16_t a = simde_vld1q_s8(test_vec[i].a);
    simde_int8x16_t b = simde_vld1q_s8(test_vec[i].b);
    simde_int8x16_t r = simde_vrhaddq_s8(a, b);

    simde_test_arm_neon_assert_equal_i8x16(r, simde_vld1q_s8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x16_t a = simde_test_arm_neon_random_i8x16();
    simde_int8x16_t b = simde_test_arm_neon_random_i8x16();
    simde_int8x16_t r = simde_vrhaddq_s8(a, b);

    simde_test_arm_neon_write_i8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vrhaddq_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[8];
    int16_t b[8];
    int16_t r[8];
  } test_vec[] = {
    { { -INT16_C( 12427), -INT16_C(  6809),  INT16_C(  2649), -INT16_C( 22355), -INT16_C( 19692),  INT16_C(  3337),  INT16_C(  9695), -INT16_C(  8924) },
      {  INT16_C( 26907),  INT16_C( 10689),  INT16_C(  2586),  INT16_C(  9923),  INT16_C( 13987),  INT16_C( 13485),  INT16_C( 13940), -INT16_C(  5796) },
      {  INT16_C(  7240),  INT16_C(  1940),  INT16_C(  2618), -INT16_C(  6216), -INT16_C(  2852),  INT16_C(  8411),  INT16_C( 11818), -INT16_C(  7360) } },
    { { -INT16_C( 15611),  INT16_C( 24270),  INT16_C( 31694), -INT16_C(  7674),  INT16_C(  3886),  INT16_C(  3567),  INT16_C(  4917),  INT16_C( 20714) },
      { -INT16_C( 21636), -INT16_C( 27015),  INT16_C( 15541),  INT16_C( 22973),  INT16_C( 27251), -INT16_C(  6259), -INT16_C(  5728), -INT16_C( 23088) },
      { -INT16_C( 18623), -INT16_C(  1372),  INT16_C( 23618),  INT16_C(  7650),  INT16_C( 15569), -INT16_C(  1346), -INT16_C(   405), -INT16_C(  1187) } },
    { { -INT16_C( 24915),  INT16_C( 31491),  INT16_C(  2585),  INT16_C( 18269),  INT16_C( 19481),  INT16_C( 20053),  INT16_C( 16224), -INT16_C(  9057) },
      {  INT16_C(  6379), -INT16_C( 24461),  INT16_C( 12373), -INT16_C( 14087), -INT16_C( 30822),  INT16_C( 15023),  INT16_C( 32624),  INT16_C(  7647) },
      { -INT16_C(  9268),  INT16_C(  3515),  INT16_C(  7479),  INT16_C(  2091), -INT16_C(  5670),  INT16_C( 17538),  INT16_C( 24424), -INT16_C(   705) } },
    { { -INT16_C(  7651),  INT16_C( 13976), -INT16_C(  2580),  INT16_C(  1661), -INT16_C( 11710), -INT16_C( 23980), -INT16_C(  3310), -INT16_C(   642) },
      { -INT16_C(  3828),  INT16_C( 24989), -INT16_C( 26847), -INT16_C( 17623), -INT16_C( 10210), -INT16_C( 28939), -INT16_C( 11177),  INT16_C( 29868) },
      { -INT16_C(  5739),  INT16_C( 19483), -INT16_C( 14713), -INT16_C(  7981), -INT16_C( 10960), -INT16_C( 26459), -INT16_C(  7243),  INT16_C( 14613) } },
    { {  INT16_C( 17591), -INT16_C( 23638),  INT16_C( 10042),  INT16_C( 31913), -INT16_C(   262),  INT16_C(  3102), -INT16_C( 25359), -INT16_C(   759) },
      { -INT16_C( 22898), -INT16_C( 20642), -INT16_C( 30915),  INT16_C( 23403),  INT16_C( 24671), -INT16_C( 18710), -INT16_C( 27083), -INT16_C(  5078) },
      { -INT16_C(  2653), -INT16_C( 22140), -INT16_C( 10436),  INT16_C( 27658),  INT16_C( 12205), -INT16_C(  7804), -INT16_C( 26221), -INT16_C(  2918) } },
    { { -INT16_C( 11046),  INT16_C(  5263),  INT16_C( 14844), -INT16_C(  2416), -INT16_C( 20937),  INT16_C( 10242),  INT16_C(  2891), -INT16_C(  9946) },
      { -INT16_C( 31567), -INT16_C(  4216), -INT16_C(  3316),  INT16_C( 27466),  INT16_C( 13396), -INT16_C( 30430),  INT16_C( 19658), -INT16_C( 23179) },
      { -INT16_C( 21306),  INT16_C(   524),  INT16_C(  5764),  INT16_C( 12525), -INT16_C(  3770), -INT16_C( 10094),  INT16_C( 11275), -INT16_C( 16562) } },
    { {  INT16_C(  1057),  INT16_C(  7609),  INT16_C( 19005),  INT16_C( 29715),  INT16_C(  5624),  INT16_C( 17309), -INT16_C( 15584), -INT16_C( 12004) },
      { -INT16_C( 23225),  INT16_C( 21440),  INT16_C(  2968), -INT16_C(  4929), -INT16_C(  7873),  INT16_C(  2677), -INT16_C(  5587),  INT16_C( 20143) },
      { -INT16_C( 11084),  INT16_C( 14525),  INT16_C( 10987),  INT16_C( 12393), -INT16_C(  1124),  INT16_C(  9993), -INT16_C( 10585),  INT16_C(  4070) } },
    { {  INT16_C( 26863),  INT16_C( 11371),  INT16_C( 32434), -INT16_C( 21599),  INT16_C( 16019), -INT16_C( 19474),  INT16_C(  2817),  INT16_C( 18565) },
      {  INT16_C( 17840),  INT16_C( 18588),  INT16_C( 23376), -INT16_C( 28619), -INT16_C( 21956),  INT16_C( 27034),  INT16_C( 18837), -INT16_C( 31560) },
      {  INT16_C( 22352),  INT16_C( 14980),  INT16_C( 27905), -INT16_C( 25109), -INT16_C(  2968),  INT16_C(  3780),  INT16_C( 10827), -INT16_C(  6497) } },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_int16x8_t b = simde_vld1q_s16(test_vec[i].b);
    simde_int16x8_t r = simde_vrhaddq_s16(a, b);

    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x8_t a = simde_test_arm_neon_random_i16x8();
    simde_int16x8_t b = simde_test_arm_neon_random_i16x8();
    simde_int16x8_t r = simde_vrhaddq_s16(a, b);

    simde_test_arm_neon_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vrhaddq_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[4];
    int32_t b[4];
    int32_t r[4];
  } test_vec[] = {
    { {  INT32_C(   760845893), -INT32_C(   891314450), -INT32_C(   836422950),  INT32_C(   376615154) },
      { -INT32_C(   916305564),  INT32_C(   325179058),  INT32_C(  1510259932),  INT32_C(   894450672) },
      { -INT32_C(    77729835), -INT32_C(   283067696),  INT32_C(   336918491),  INT32_C(   635532913) } },
    { { -INT32_C(  1067275822),  INT32_C(   579486280),  INT32_C(  1727049588), -INT32_C(   998481057) },
      {  INT32_C(  1586355884), -INT32_C(  1871581516), -INT32_C(  1695910486), -INT32_C(  2083571023) },
      {  INT32_C(   259540031), -INT32_C(   646047618),  INT32_C(    15569551), -INT32_C(  1541026040) } },
    { {  INT32_C(   742601444), -INT32_C(   397488780), -INT32_C(   598851716),  INT32_C(  1319160482) },
      {  INT32_C(  1554787752), -INT32_C(   974381797),  INT32_C(  1130354322), -INT32_C(   171561455) },
      {  INT32_C(  1148694598), -INT32_C(   685935288),  INT32_C(   265751303),  INT32_C(   573799514) } },
    { { -INT32_C(   736032416),  INT32_C(  1404858326),  INT32_C(  1345260206),  INT32_C(  2090782676) },
      {  INT32_C(   400050940), -INT32_C(    86195097), -INT32_C(  1405273189), -INT32_C(   895417239) },
      { -INT32_C(   167990738),  INT32_C(   659331615), -INT32_C(    30006491),  INT32_C(   597682719) } },
    { { -INT32_C(   459357683), -INT32_C(   533243087),  INT32_C(   976250469),  INT32_C(   834064181) },
      { -INT32_C(  2125951207), -INT32_C(   293919661), -INT32_C(   929384353), -INT32_C(   896386116) },
      { -INT32_C(  1292654445), -INT32_C(   413581374),  INT32_C(    23433058), -INT32_C(    31160967) } },
    { {  INT32_C(   799945213), -INT32_C(   250616436), -INT32_C(  2144649397),  INT32_C(   682746382) },
      { -INT32_C(   995493519),  INT32_C(  2092114973), -INT32_C(  1723576868), -INT32_C(  2040277111) },
      { -INT32_C(    97774153),  INT32_C(   920749269), -INT32_C(  1934113132), -INT32_C(   678765364) } },
    { { -INT32_C(  1800072952),  INT32_C(  1099285750),  INT32_C(   314683652),  INT32_C(    70939283) },
      { -INT32_C(  2000100501), -INT32_C(   469468409),  INT32_C(  1383942345),  INT32_C(   668524575) },
      { -INT32_C(  1900086726),  INT32_C(   314908671),  INT32_C(   849312999),  INT32_C(   369731929) } },
    { { -INT32_C(   407138575),  INT32_C(  1445478738), -INT32_C(  2056656398), -INT32_C(   964058277) },
      { -INT32_C(  1907469945), -INT32_C(  1770892595), -INT32_C(  1159139430), -INT32_C(  1058946865) },
      { -INT32_C(  1157304260), -INT32_C(   162706928), -INT32_C(  1607897914), -INT32_C(  1011502571) } },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int32x4_t b = simde_vld1q_s32(test_vec[i].b);
    simde_int32x4_t r = simde_vrhaddq_s32(a, b);
    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x4_t a = simde_test_arm_neon_random_i32x4();
    simde_int32x4_t b = simde_test_arm_neon_random_i32x4();
    simde_int32x4_t r = simde_vrhaddq_s32(a, b);

    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}


static int
test_simde_vrhaddq_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t a[16];
    uint8_t b[16];
    uint8_t r[16];
  } test_vec[] = {
    { { UINT8_C(150), UINT8_C(167), UINT8_C(203), UINT8_C(236), UINT8_C(160), UINT8_C( 41), UINT8_C( 47), UINT8_C(101),
        UINT8_C( 47), UINT8_C( 78), UINT8_C(231), UINT8_C(185), UINT8_C(  8), UINT8_C( 74), UINT8_C( 24), UINT8_C(128) },
      { UINT8_C(164), UINT8_C(162), UINT8_C(165), UINT8_C(162), UINT8_C(209), UINT8_C(237), UINT8_C(222), UINT8_C( 42),
        UINT8_C( 79), UINT8_C( 11), UINT8_C(  3), UINT8_C(234), UINT8_C(238), UINT8_C(233), UINT8_C( 40), UINT8_C(132) },
      { UINT8_C(157), UINT8_C(165), UINT8_C(184), UINT8_C(199), UINT8_C(185), UINT8_C(139), UINT8_C(135), UINT8_C( 72),
        UINT8_C( 63), UINT8_C( 45), UINT8_C(117), UINT8_C(210), UINT8_C(123), UINT8_C(154), UINT8_C( 32), UINT8_C(130) } },
    { { UINT8_C(144), UINT8_C(243), UINT8_C(112), UINT8_C( 48), UINT8_C( 29), UINT8_C(159), UINT8_C(150), UINT8_C( 76),
        UINT8_C(237), UINT8_C(125), UINT8_C(  5), UINT8_C(246), UINT8_C(199), UINT8_C( 29), UINT8_C(118), UINT8_C(107) },
      { UINT8_C(191), UINT8_C( 27), UINT8_C( 14), UINT8_C(144), UINT8_C(  8), UINT8_C(236), UINT8_C(187), UINT8_C( 87),
        UINT8_C(247), UINT8_C(190), UINT8_C( 66), UINT8_C(229), UINT8_C(167), UINT8_C(106), UINT8_C(105), UINT8_C( 56) },
      { UINT8_C(168), UINT8_C(135), UINT8_C( 63), UINT8_C( 96), UINT8_C( 19), UINT8_C(198), UINT8_C(169), UINT8_C( 82),
        UINT8_C(242), UINT8_C(158), UINT8_C( 36), UINT8_C(238), UINT8_C(183), UINT8_C( 68), UINT8_C(112), UINT8_C( 82) } },
    { { UINT8_C( 93), UINT8_C(217), UINT8_C(104), UINT8_C(122), UINT8_C(120), UINT8_C(254), UINT8_C(198), UINT8_C(102),
        UINT8_C(123), UINT8_C(203), UINT8_C( 92), UINT8_C( 66), UINT8_C(232), UINT8_C(210), UINT8_C(174), UINT8_C(167) },
      { UINT8_C(237), UINT8_C(188), UINT8_C( 56), UINT8_C(245), UINT8_C(168), UINT8_C(243), UINT8_C( 77), UINT8_C(159),
        UINT8_C(177), UINT8_C(143), UINT8_C(133), UINT8_C( 89), UINT8_C(249), UINT8_C(238), UINT8_C(145), UINT8_C( 86) },
      { UINT8_C(165), UINT8_C(203), UINT8_C( 80), UINT8_C(184), UINT8_C(144), UINT8_C(249), UINT8_C(138), UINT8_C(131),
        UINT8_C(150), UINT8_C(173), UINT8_C(113), UINT8_C( 78), UINT8_C(241), UINT8_C(224), UINT8_C(160), UINT8_C(127) } },
    { { UINT8_C(200), UINT8_C(249), UINT8_C(209), UINT8_C( 64), UINT8_C(248), UINT8_C(151), UINT8_C(166), UINT8_C(115),
        UINT8_C( 99), UINT8_C(  2), UINT8_C(182), UINT8_C( 75), UINT8_C(212), UINT8_C(100), UINT8_C(243), UINT8_C(193) },
      { UINT8_C( 32), UINT8_C( 43), UINT8_C(183), UINT8_C(200), UINT8_C( 30), UINT8_C(  4), UINT8_C(103), UINT8_C(207),
        UINT8_C(147), UINT8_C(236), UINT8_C( 40), UINT8_C(140), UINT8_C(219), UINT8_C(185), UINT8_C(226), UINT8_C(163) },
      { UINT8_C(116), UINT8_C(146), UINT8_C(196), UINT8_C(132), UINT8_C(139), UINT8_C( 78), UINT8_C(135), UINT8_C(161),
        UINT8_C(123), UINT8_C(119), UINT8_C(111), UINT8_C(108), UINT8_C(216), UINT8_C(143), UINT8_C(235), UINT8_C(178) } },
    { { UINT8_C(179), UINT8_C(179), UINT8_C(227), UINT8_C(171), UINT8_C( 75), UINT8_C(138), UINT8_C( 30), UINT8_C(174),
        UINT8_C(140), UINT8_C(212), UINT8_C(249), UINT8_C( 97), UINT8_C( 56), UINT8_C(236), UINT8_C( 34), UINT8_C( 88) },
      { UINT8_C( 23), UINT8_C(217), UINT8_C( 32), UINT8_C( 53), UINT8_C(221), UINT8_C(136), UINT8_C(  5), UINT8_C(112),
        UINT8_C(116), UINT8_C( 45), UINT8_C(252), UINT8_C( 79), UINT8_C(231), UINT8_C(223), UINT8_C(242), UINT8_C(154) },
      { UINT8_C(101), UINT8_C(198), UINT8_C(130), UINT8_C(112), UINT8_C(148), UINT8_C(137), UINT8_C( 18), UINT8_C(143),
        UINT8_C(128), UINT8_C(129), UINT8_C(251), UINT8_C( 88), UINT8_C(144), UINT8_C(230), UINT8_C(138), UINT8_C(121) } },
    { { UINT8_C(146), UINT8_C(214), UINT8_C( 69), UINT8_C(221), UINT8_C( 96), UINT8_C( 99), UINT8_C(139), UINT8_C(236),
        UINT8_C( 56), UINT8_C(133), UINT8_C( 77), UINT8_C(112), UINT8_C(113), UINT8_C(112), UINT8_C(201), UINT8_C(137) },
      { UINT8_C( 73), UINT8_C(233), UINT8_C(190), UINT8_C( 39), UINT8_C(113), UINT8_C(195), UINT8_C(151), UINT8_C(230),
        UINT8_C(241), UINT8_C(148), UINT8_C( 53), UINT8_C(216), UINT8_C(115), UINT8_C( 40), UINT8_C(114), UINT8_C(  5) },
      { UINT8_C(110), UINT8_C(224), UINT8_C(130), UINT8_C(130), UINT8_C(105), UINT8_C(147), UINT8_C(145), UINT8_C(233),
        UINT8_C(149), UINT8_C(141), UINT8_C( 65), UINT8_C(164), UINT8_C(114), UINT8_C( 76), UINT8_C(158), UINT8_C( 71) } },
    { { UINT8_C(254), UINT8_C(183), UINT8_C(227), UINT8_C( 94), UINT8_C( 26), UINT8_C(110), UINT8_C( 74), UINT8_C( 82),
        UINT8_C(243), UINT8_C(152), UINT8_C(195), UINT8_C(101), UINT8_C(  8), UINT8_C(140), UINT8_C(238), UINT8_C( 81) },
      { UINT8_C(117), UINT8_C(172), UINT8_C(120), UINT8_C(231), UINT8_C(112), UINT8_C( 16), UINT8_C(205), UINT8_C( 97),
        UINT8_C(164), UINT8_C(  2), UINT8_C( 57), UINT8_C( 23), UINT8_C( 42), UINT8_C(171), UINT8_C( 28), UINT8_C( 40) },
      { UINT8_C(186), UINT8_C(178), UINT8_C(174), UINT8_C(163), UINT8_C( 69), UINT8_C( 63), UINT8_C(140), UINT8_C( 90),
        UINT8_C(204), UINT8_C( 77), UINT8_C(126), UINT8_C( 62), UINT8_C( 25), UINT8_C(156), UINT8_C(133), UINT8_C( 61) } },
    { { UINT8_C( 98),    UINT8_MAX, UINT8_C(134), UINT8_C(124), UINT8_C(110), UINT8_C(209), UINT8_C(207), UINT8_C( 97),
        UINT8_C(105), UINT8_C(146), UINT8_C(198), UINT8_C(113), UINT8_C( 30), UINT8_C(180), UINT8_C(194), UINT8_C(147) },
      { UINT8_C( 97), UINT8_C( 59), UINT8_C(122), UINT8_C(209), UINT8_C( 75), UINT8_C( 71), UINT8_C( 50), UINT8_C(239),
        UINT8_C( 74), UINT8_C(107), UINT8_C(  6), UINT8_C(116), UINT8_C( 22), UINT8_C( 34), UINT8_C(157), UINT8_C(120) },
      { UINT8_C( 98), UINT8_C(157), UINT8_C(128), UINT8_C(167), UINT8_C( 93), UINT8_C(140), UINT8_C(129), UINT8_C(168),
        UINT8_C( 90), UINT8_C(127), UINT8_C(102), UINT8_C(115), UINT8_C( 26), UINT8_C(107), UINT8_C(176), UINT8_C(134) } },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x16_t a = simde_vld1q_u8(test_vec[i].a);
    simde_uint8x16_t b = simde_vld1q_u8(test_vec[i].b);
    simde_uint8x16_t r = simde_vrhaddq_u8(a, b);

    simde_test_arm_neon_assert_equal_u8x16(r, simde_vld1q_u8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8x16_t a = simde_test_arm_neon_random_u8x16();
    simde_uint8x16_t b = simde_test_arm_neon_random_u8x16();
    simde_uint8x16_t r = simde_vrhaddq_u8(a, b);

    simde_test_arm_neon_write_u8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vrhaddq_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[8];
    uint16_t b[8];
    uint16_t r[8];
  } test_vec[] = {
    { { UINT16_C(51215), UINT16_C(32160), UINT16_C(55135), UINT16_C(43104), UINT16_C(32699), UINT16_C(11689), UINT16_C(18157), UINT16_C(40650) },
      { UINT16_C(43290), UINT16_C(35791), UINT16_C(10404), UINT16_C(41944), UINT16_C( 2814), UINT16_C(22591), UINT16_C(25777), UINT16_C(49195) },
      { UINT16_C(47253), UINT16_C(33976), UINT16_C(32770), UINT16_C(42524), UINT16_C(17757), UINT16_C(17140), UINT16_C(21967), UINT16_C(44923) } },
    { { UINT16_C(52012), UINT16_C(35645), UINT16_C(40355), UINT16_C(24115), UINT16_C(56348), UINT16_C( 2443), UINT16_C(21794), UINT16_C(15783) },
      { UINT16_C(30718), UINT16_C(41672), UINT16_C(41375), UINT16_C(40262), UINT16_C(34219), UINT16_C(23797), UINT16_C( 8682), UINT16_C( 5660) },
      { UINT16_C(41365), UINT16_C(38659), UINT16_C(40865), UINT16_C(32189), UINT16_C(45284), UINT16_C(13120), UINT16_C(15238), UINT16_C(10722) } },
    { { UINT16_C(23020), UINT16_C(36770), UINT16_C(54774), UINT16_C( 4845), UINT16_C(30898), UINT16_C(54300), UINT16_C(50125), UINT16_C(52241) },
      { UINT16_C(55866), UINT16_C(55662), UINT16_C(46203), UINT16_C( 9847), UINT16_C(27706), UINT16_C( 9347), UINT16_C(40845), UINT16_C(31290) },
      { UINT16_C(39443), UINT16_C(46216), UINT16_C(50489), UINT16_C( 7346), UINT16_C(29302), UINT16_C(31824), UINT16_C(45485), UINT16_C(41766) } },
    { { UINT16_C(56569), UINT16_C(61193), UINT16_C(63410), UINT16_C(25602), UINT16_C( 7791), UINT16_C(15672), UINT16_C(19169), UINT16_C( 7177) },
      { UINT16_C(30500), UINT16_C(40949), UINT16_C(27692), UINT16_C(26309), UINT16_C(18649), UINT16_C(26250), UINT16_C(50408), UINT16_C(57824) },
      { UINT16_C(43535), UINT16_C(51071), UINT16_C(45551), UINT16_C(25956), UINT16_C(13220), UINT16_C(20961), UINT16_C(34789), UINT16_C(32501) } },
    { { UINT16_C(60065), UINT16_C(21456), UINT16_C(53985), UINT16_C(20663), UINT16_C(61424), UINT16_C(53901), UINT16_C(38457), UINT16_C(24046) },
      { UINT16_C(58126), UINT16_C(15100), UINT16_C(49744), UINT16_C(10656), UINT16_C(10762), UINT16_C(62095), UINT16_C(28910), UINT16_C(36819) },
      { UINT16_C(59096), UINT16_C(18278), UINT16_C(51865), UINT16_C(15660), UINT16_C(36093), UINT16_C(57998), UINT16_C(33684), UINT16_C(30433) } },
    { { UINT16_C(42074), UINT16_C(15330), UINT16_C(39286), UINT16_C(26507), UINT16_C( 6537), UINT16_C(49721), UINT16_C(10159), UINT16_C(48416) },
      { UINT16_C( 7178), UINT16_C(23287), UINT16_C(38878), UINT16_C(59779), UINT16_C( 5057), UINT16_C(45275), UINT16_C(44931), UINT16_C(56639) },
      { UINT16_C(24626), UINT16_C(19309), UINT16_C(39082), UINT16_C(43143), UINT16_C( 5797), UINT16_C(47498), UINT16_C(27545), UINT16_C(52528) } },
    { { UINT16_C( 8787), UINT16_C(51480), UINT16_C(41915), UINT16_C(17456), UINT16_C(27068), UINT16_C(27655), UINT16_C(10128), UINT16_C(39721) },
      { UINT16_C( 8515), UINT16_C( 8949), UINT16_C(31160), UINT16_C(31243), UINT16_C(59020), UINT16_C( 3882), UINT16_C(27029), UINT16_C(59628) },
      { UINT16_C( 8651), UINT16_C(30215), UINT16_C(36538), UINT16_C(24350), UINT16_C(43044), UINT16_C(15769), UINT16_C(18579), UINT16_C(49675) } },
    { { UINT16_C( 1163), UINT16_C(18354), UINT16_C(58023), UINT16_C(25739), UINT16_C(37452), UINT16_C(56528), UINT16_C(63929), UINT16_C(64887) },
      { UINT16_C(27930), UINT16_C(54047), UINT16_C(10982), UINT16_C(29261), UINT16_C(30480), UINT16_C(42625), UINT16_C(28128), UINT16_C(27790) },
      { UINT16_C(14547), UINT16_C(36201), UINT16_C(34503), UINT16_C(27500), UINT16_C(33966), UINT16_C(49577), UINT16_C(46029), UINT16_C(46339) } },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);
    simde_uint16x8_t b = simde_vld1q_u16(test_vec[i].b);
    simde_uint16x8_t r = simde_vrhaddq_u16(a, b);
    simde_test_arm_neon_assert_equal_u16x8(r, simde_vld1q_u16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x8_t a = simde_test_arm_neon_random_u16x8();
    simde_uint16x8_t b = simde_test_arm_neon_random_u16x8();
    simde_uint16x8_t r = simde_vrhaddq_u16(a, b);

    simde_test_arm_neon_write_u16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vrhaddq_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[4];
    uint32_t b[4];
    uint32_t r[4];
  } test_vec[] = {
    { { UINT32_C(2123283924), UINT32_C(2831405666), UINT32_C(1820489986), UINT32_C(2642437646) },
      { UINT32_C(1224219618), UINT32_C(3851204320), UINT32_C(2309803833), UINT32_C(4223364647) },
      { UINT32_C(1673751771), UINT32_C(3341304993), UINT32_C(2065146910), UINT32_C(3432901147) } },
    { { UINT32_C(2390378796), UINT32_C( 506871068), UINT32_C(3297425846), UINT32_C(  23137055) },
      { UINT32_C( 122312998), UINT32_C(1240258063), UINT32_C(3453130918), UINT32_C( 868781319) },
      { UINT32_C(1256345897), UINT32_C( 873564566), UINT32_C(3375278382), UINT32_C( 445959187) } },
    { { UINT32_C(4089529047), UINT32_C( 890369919), UINT32_C(3489307824), UINT32_C(3453049767) },
      { UINT32_C(3302235061), UINT32_C(2534260977), UINT32_C(1617223513), UINT32_C(1150496109) },
      { UINT32_C(3695882054), UINT32_C(1712315448), UINT32_C(2553265669), UINT32_C(2301772938) } },
    { { UINT32_C(4013380719), UINT32_C(4230236235), UINT32_C(2345344740), UINT32_C( 794401914) },
      { UINT32_C(2851286455), UINT32_C(1195377134), UINT32_C(1302832608), UINT32_C(1100036818) },
      { UINT32_C(3432333587), UINT32_C(2712806685), UINT32_C(1824088674), UINT32_C( 947219366) } },
    { { UINT32_C(3643852942), UINT32_C(4124398865), UINT32_C(3984695667), UINT32_C(4112308797) },
      { UINT32_C(4120776711), UINT32_C(4047298065), UINT32_C(1430250371), UINT32_C(2878853149) },
      { UINT32_C(3882314827), UINT32_C(4085848465), UINT32_C(2707473019), UINT32_C(3495580973) } },
    { { UINT32_C(2860894105), UINT32_C(2426362396), UINT32_C( 964501755), UINT32_C(  36608762) },
      { UINT32_C(3153579178), UINT32_C( 783037610), UINT32_C( 897837847), UINT32_C(1440750268) },
      { UINT32_C(3007236642), UINT32_C(1604700003), UINT32_C( 931169801), UINT32_C( 738679515) } },
    { { UINT32_C(4278150626), UINT32_C(3146686144), UINT32_C(3119779007), UINT32_C(1354441382) },
      { UINT32_C(2567681006), UINT32_C(4274501607), UINT32_C(1597196963), UINT32_C(1202984037) },
      { UINT32_C(3422915816), UINT32_C(3710593876), UINT32_C(2358487985), UINT32_C(1278712710) } },
    { { UINT32_C( 960869241), UINT32_C( 284546129), UINT32_C(2261445088), UINT32_C(4208362764) },
      { UINT32_C( 529785144), UINT32_C( 991845016), UINT32_C( 177885605), UINT32_C(3746647653) },
      { UINT32_C( 745327193), UINT32_C( 638195573), UINT32_C(1219665347), UINT32_C(3977505209) } },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint32x4_t b = simde_vld1q_u32(test_vec[i].b);
    simde_uint32x4_t r = simde_vrhaddq_u32(a, b);

    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x4_t a = simde_test_arm_neon_random_u32x4();
    simde_uint32x4_t b = simde_test_arm_neon_random_u32x4();
    simde_uint32x4_t r = simde_vrhaddq_u32(a, b);

    simde_test_arm_neon_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vrhadd_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vrhadd_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vrhadd_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vrhadd_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vrhadd_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vrhadd_u32)

SIMDE_TEST_FUNC_LIST_ENTRY(vrhaddq_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vrhaddq_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vrhaddq_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vrhaddq_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vrhaddq_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vrhaddq_u32)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
