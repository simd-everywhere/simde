#define SIMDE_TEST_ARM_NEON_INSN hadd

#include "test-neon.h"
#include "../../../simde/arm/neon/hadd.h"

static int
test_simde_vhadd_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[8];
    int8_t b[8];
    int8_t r[8];
  } test_vec[] = {
    { { -INT8_C( 111), -INT8_C( 110),  INT8_C(  14), -INT8_C(  92), -INT8_C(  21), -INT8_C(  15), -INT8_C(  67),  INT8_C(  34) },
      {  INT8_C(  85),  INT8_C( 113),  INT8_C(  87), -INT8_C(  58),  INT8_C( 112),  INT8_C(  51), -INT8_C(  18),  INT8_C( 103) },
      { -INT8_C(  13),  INT8_C(   1),  INT8_C(  50), -INT8_C(  75),  INT8_C(  45),  INT8_C(  18), -INT8_C(  43),  INT8_C(  68) } },
    { {  INT8_C( 119), -INT8_C(  32), -INT8_C(  32), -INT8_C(  30), -INT8_C(   5), -INT8_C(  80), -INT8_C( 127),  INT8_C(  47) },
      { -INT8_C(  27), -INT8_C(  10), -INT8_C( 111), -INT8_C(  68),  INT8_C( 125), -INT8_C(  43), -INT8_C(  31),  INT8_C(  14) },
      {  INT8_C(  46), -INT8_C(  21), -INT8_C(  72), -INT8_C(  49),  INT8_C(  60), -INT8_C(  62), -INT8_C(  79),  INT8_C(  30) } },
    { {  INT8_C( 103), -INT8_C(  17), -INT8_C(  78),  INT8_C(  83), -INT8_C(  32),  INT8_C( 112),  INT8_C( 117),  INT8_C(  53) },
      { -INT8_C(  31), -INT8_C(  52), -INT8_C(   4),  INT8_C(  81), -INT8_C(   1), -INT8_C(  22), -INT8_C(  72),  INT8_C( 118) },
      {  INT8_C(  36), -INT8_C(  35), -INT8_C(  41),  INT8_C(  82), -INT8_C(  17),  INT8_C(  45),  INT8_C(  22),  INT8_C(  85) } },
    { { -INT8_C(  54), -INT8_C( 104),  INT8_C(  89), -INT8_C(  59),  INT8_C(  73), -INT8_C(  38), -INT8_C(  12),  INT8_C(  46) },
      { -INT8_C(  48), -INT8_C( 123), -INT8_C(  22),  INT8_C(  78),  INT8_C(  90), -INT8_C(  53),  INT8_C(  92), -INT8_C(  63) },
      { -INT8_C(  51), -INT8_C( 114),  INT8_C(  33),  INT8_C(   9),  INT8_C(  81), -INT8_C(  46),  INT8_C(  40), -INT8_C(   9) } },
    { { -INT8_C(  70),  INT8_C(  15),  INT8_C(  20), -INT8_C( 101),      INT8_MAX, -INT8_C( 119), -INT8_C(  48),  INT8_C(  96) },
      {  INT8_C(  85), -INT8_C(  52), -INT8_C(  79),  INT8_C(  84), -INT8_C(  74),  INT8_C( 106), -INT8_C(  53),      INT8_MIN },
      {  INT8_C(   7), -INT8_C(  19), -INT8_C(  30), -INT8_C(   9),  INT8_C(  26), -INT8_C(   7), -INT8_C(  51), -INT8_C(  16) } },
    { {  INT8_C(   2),  INT8_C(  36),  INT8_C(  69),  INT8_C(  75), -INT8_C(   2),  INT8_C(  57),  INT8_C( 121), -INT8_C(  50) },
      { -INT8_C(  66),  INT8_C(  99),  INT8_C(  28),  INT8_C(  24),  INT8_C(  46),  INT8_C( 121), -INT8_C(  38), -INT8_C(  23) },
      { -INT8_C(  32),  INT8_C(  67),  INT8_C(  48),  INT8_C(  49),  INT8_C(  22),  INT8_C(  89),  INT8_C(  41), -INT8_C(  37) } },
    { { -INT8_C( 120), -INT8_C(  18), -INT8_C( 124),  INT8_C(   7),  INT8_C( 120),  INT8_C(  84),  INT8_C( 103), -INT8_C(  51) },
      {  INT8_C(  33),  INT8_C(  24),  INT8_C(  34), -INT8_C(  41), -INT8_C( 126), -INT8_C(  19),  INT8_C(  88), -INT8_C( 123) },
      { -INT8_C(  44),  INT8_C(   3), -INT8_C(  45), -INT8_C(  17), -INT8_C(   3),  INT8_C(  32),  INT8_C(  95), -INT8_C(  87) } },
    { {  INT8_C(  17), -INT8_C(  99), -INT8_C(  48),  INT8_C(  15), -INT8_C(  41),  INT8_C(  74), -INT8_C(  35), -INT8_C( 107) },
      { -INT8_C(  83), -INT8_C(   6), -INT8_C(  82), -INT8_C(  36),  INT8_C( 115), -INT8_C( 120), -INT8_C(  59), -INT8_C(   5) },
      { -INT8_C(  33), -INT8_C(  53), -INT8_C(  65), -INT8_C(  11),  INT8_C(  37), -INT8_C(  23), -INT8_C(  47), -INT8_C(  56) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8_t a = simde_vld1_s8(test_vec[i].a);
    simde_int8x8_t b = simde_vld1_s8(test_vec[i].b);
    simde_int8x8_t r = simde_vhadd_s8(a, b);

    simde_test_arm_neon_assert_equal_i8x8(r, simde_vld1_s8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x8_t a = simde_test_arm_neon_random_i8x8();
    simde_int8x8_t b = simde_test_arm_neon_random_i8x8();
    simde_int8x8_t r = simde_vhadd_s8(a, b);

    simde_test_arm_neon_write_i8x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vhadd_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[4];
    int16_t b[4];
    int16_t r[4];
  } test_vec[] = {
    { {  INT16_C( 16201), -INT16_C( 11732), -INT16_C( 17864),  INT16_C( 19476) },
      {  INT16_C(  3388), -INT16_C( 22085),  INT16_C(  2842),  INT16_C(  4373) },
      {  INT16_C(  9794), -INT16_C( 16909), -INT16_C(  7511),  INT16_C( 11924) } },
    { {  INT16_C( 23570), -INT16_C(  1377),  INT16_C( 13725),  INT16_C(  9933) },
      { -INT16_C(  6686),  INT16_C( 12749), -INT16_C( 30519),  INT16_C(  4848) },
      {  INT16_C(  8442),  INT16_C(  5686), -INT16_C(  8397),  INT16_C(  7390) } },
    { {  INT16_C(  7367), -INT16_C(    28), -INT16_C(  1834),  INT16_C(  4683) },
      {  INT16_C(  1542),  INT16_C(  8379), -INT16_C( 12270),  INT16_C(  9265) },
      {  INT16_C(  4454),  INT16_C(  4175), -INT16_C(  7052),  INT16_C(  6974) } },
    { { -INT16_C( 11987), -INT16_C( 13794), -INT16_C(  5114), -INT16_C(  5904) },
      { -INT16_C( 16943), -INT16_C( 26086),  INT16_C(  2629),  INT16_C(  3244) },
      { -INT16_C( 14465), -INT16_C( 19940), -INT16_C(  1243), -INT16_C(  1330) } },
    { { -INT16_C( 28633), -INT16_C(   757),  INT16_C( 22409), -INT16_C( 28912) },
      { -INT16_C( 13475),  INT16_C( 28591), -INT16_C(  8036), -INT16_C( 13933) },
      { -INT16_C( 21054),  INT16_C( 13917),  INT16_C(  7186), -INT16_C( 21423) } },
    { { -INT16_C( 19791), -INT16_C( 18541), -INT16_C( 31586),  INT16_C( 28576) },
      { -INT16_C( 17855), -INT16_C( 30966), -INT16_C( 18748), -INT16_C(  5229) },
      { -INT16_C( 18823), -INT16_C( 24754), -INT16_C( 25167),  INT16_C( 11673) } },
    { { -INT16_C( 24761), -INT16_C( 12055), -INT16_C(  1546),  INT16_C( 21343) },
      {  INT16_C(  3780),  INT16_C( 24771),  INT16_C( 22254), -INT16_C( 24535) },
      { -INT16_C( 10491),  INT16_C(  6358),  INT16_C( 10354), -INT16_C(  1596) } },
    { { -INT16_C( 17144), -INT16_C( 22953), -INT16_C(  2239), -INT16_C( 32234) },
      {  INT16_C(  8369),  INT16_C( 30217), -INT16_C( 25130),  INT16_C(  7521) },
      { -INT16_C(  4388),  INT16_C(  3632), -INT16_C( 13685), -INT16_C( 12357) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t a = simde_vld1_s16(test_vec[i].a);
    simde_int16x4_t b = simde_vld1_s16(test_vec[i].b);
    simde_int16x4_t r = simde_vhadd_s16(a, b);

    simde_test_arm_neon_assert_equal_i16x4(r, simde_vld1_s16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x4_t a = simde_test_arm_neon_random_i16x4();
    simde_int16x4_t b = simde_test_arm_neon_random_i16x4();
    simde_int16x4_t r = simde_vhadd_s16(a, b);

    simde_test_arm_neon_write_i16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

#if !defined(TEST_SIMDE_VABD_NO_TEST_32)
static int
test_simde_vhadd_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[2];
    int32_t b[2];
    int32_t r[2];
  } test_vec[] = {
    { {  INT32_C(   854411836),  INT32_C(   142953539) },
      {  INT32_C(  1231571034), -INT32_C(  1477864801) },
      {  INT32_C(  1042991435), -INT32_C(   667455631) } },
    { { -INT32_C(  1873919921), -INT32_C(   384670664) },
      {  INT32_C(  1516182660), -INT32_C(   176635463) },
      { -INT32_C(   178868631), -INT32_C(   280653064) } },
    { {  INT32_C(  1327981835),  INT32_C(   207072434) },
      { -INT32_C(  1806319627), -INT32_C(  1606730159) },
      { -INT32_C(   239168896), -INT32_C(   699828863) } },
    { { -INT32_C(  1221555841),  INT32_C(  1906328557) },
      {  INT32_C(   416022623), -INT32_C(   871545663) },
      { -INT32_C(   402766609),  INT32_C(   517391447) } },
    { {  INT32_C(  1528509609), -INT32_C(   714575136) },
      { -INT32_C(  2090222286),  INT32_C(  2065999356) },
      { -INT32_C(   280856339),  INT32_C(   675712110) } },
    { {  INT32_C(   473060398), -INT32_C(   158477673) },
      { -INT32_C(  1827776046),  INT32_C(  1197480861) },
      { -INT32_C(   677357824),  INT32_C(   519501594) } },
    { {  INT32_C(   815954767),  INT32_C(   537201390) },
      { -INT32_C(   995921976),  INT32_C(  1111475988) },
      { -INT32_C(    89983605),  INT32_C(   824338689) } },
    { { -INT32_C(  1285656292),  INT32_C(   380300355) },
      { -INT32_C(   475416507),  INT32_C(   589957588) },
      { -INT32_C(   880536400),  INT32_C(   485128971) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t a = simde_vld1_s32(test_vec[i].a);
    simde_int32x2_t b = simde_vld1_s32(test_vec[i].b);
    simde_int32x2_t r = simde_vhadd_s32(a, b);

    simde_test_arm_neon_assert_equal_i32x2(r, simde_vld1_s32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x2_t a = simde_test_arm_neon_random_i32x2();
    simde_int32x2_t b = simde_test_arm_neon_random_i32x2();
    simde_int32x2_t r = simde_vhadd_s32(a, b);

    simde_test_arm_neon_write_i32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}
#endif

static int
test_simde_vhadd_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t a[8];
    uint8_t b[8];
    uint8_t r[8];
  } test_vec[] = {
    { { UINT8_C( 10), UINT8_C(  5), UINT8_C(217), UINT8_C(190), UINT8_C(214), UINT8_C( 67), UINT8_C(105), UINT8_C(247) },
      {    UINT8_MAX, UINT8_C(155), UINT8_C( 39), UINT8_C( 51), UINT8_C( 23), UINT8_C(170), UINT8_C(219), UINT8_C( 72) },
      { UINT8_C(132), UINT8_C( 80), UINT8_C(128), UINT8_C(120), UINT8_C(118), UINT8_C(118), UINT8_C(162), UINT8_C(159) } },
    { { UINT8_C(178), UINT8_C(  4), UINT8_C(120), UINT8_C(197), UINT8_C( 83), UINT8_C(228), UINT8_C(140), UINT8_C(197) },
      { UINT8_C(105), UINT8_C(117), UINT8_C(168), UINT8_C(164), UINT8_C(176), UINT8_C( 55), UINT8_C(155), UINT8_C(186) },
      { UINT8_C(141), UINT8_C( 60), UINT8_C(144), UINT8_C(180), UINT8_C(129), UINT8_C(141), UINT8_C(147), UINT8_C(191) } },
    { { UINT8_C( 60), UINT8_C(116), UINT8_C(120), UINT8_C( 18), UINT8_C(183), UINT8_C(225), UINT8_C( 10), UINT8_C(182) },
      { UINT8_C(124), UINT8_C( 49), UINT8_C(233), UINT8_C(147), UINT8_C(220), UINT8_C(197), UINT8_C(219), UINT8_C(142) },
      { UINT8_C( 92), UINT8_C( 82), UINT8_C(176), UINT8_C( 82), UINT8_C(201), UINT8_C(211), UINT8_C(114), UINT8_C(162) } },
    { { UINT8_C(201), UINT8_C( 83), UINT8_C( 83), UINT8_C( 29), UINT8_C( 56), UINT8_C(224), UINT8_C(226), UINT8_C(161) },
      { UINT8_C( 85), UINT8_C(139), UINT8_C( 70), UINT8_C(  5), UINT8_C(194), UINT8_C(225), UINT8_C(191), UINT8_C(254) },
      { UINT8_C(143), UINT8_C(111), UINT8_C( 76), UINT8_C( 17), UINT8_C(125), UINT8_C(224), UINT8_C(208), UINT8_C(207) } },
    { { UINT8_C( 85), UINT8_C( 55), UINT8_C( 16), UINT8_C( 13), UINT8_C( 24), UINT8_C( 26), UINT8_C(195), UINT8_C(149) },
      { UINT8_C( 76), UINT8_C(173), UINT8_C( 40), UINT8_C( 40), UINT8_C(114), UINT8_C(  4), UINT8_C(182), UINT8_C( 59) },
      { UINT8_C( 80), UINT8_C(114), UINT8_C( 28), UINT8_C( 26), UINT8_C( 69), UINT8_C( 15), UINT8_C(188), UINT8_C(104) } },
    { { UINT8_C( 87), UINT8_C( 10), UINT8_C( 88), UINT8_C(143), UINT8_C(234), UINT8_C( 59), UINT8_C( 49), UINT8_C( 63) },
      { UINT8_C(198), UINT8_C(119), UINT8_C( 68), UINT8_C(136), UINT8_C( 88), UINT8_C(  3), UINT8_C(134), UINT8_C(173) },
      { UINT8_C(142), UINT8_C( 64), UINT8_C( 78), UINT8_C(139), UINT8_C(161), UINT8_C( 31), UINT8_C( 91), UINT8_C(118) } },
    { { UINT8_C( 58), UINT8_C(150), UINT8_C(186), UINT8_C( 82), UINT8_C(177), UINT8_C(126), UINT8_C(231), UINT8_C(253) },
      { UINT8_C( 43), UINT8_C( 16), UINT8_C( 37), UINT8_C(157), UINT8_C( 20), UINT8_C(219), UINT8_C(216), UINT8_C(107) },
      { UINT8_C( 50), UINT8_C( 83), UINT8_C(111), UINT8_C(119), UINT8_C( 98), UINT8_C(172), UINT8_C(223), UINT8_C(180) } },
    { { UINT8_C(229), UINT8_C( 49), UINT8_C(251), UINT8_C(207), UINT8_C(108), UINT8_C( 44), UINT8_C( 14), UINT8_C( 50) },
      { UINT8_C(163), UINT8_C( 82), UINT8_C(186), UINT8_C(251), UINT8_C( 85), UINT8_C( 64), UINT8_C(168), UINT8_C(143) },
      { UINT8_C(196), UINT8_C( 65), UINT8_C(218), UINT8_C(229), UINT8_C( 96), UINT8_C( 54), UINT8_C( 91), UINT8_C( 96) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x8_t a = simde_vld1_u8(test_vec[i].a);
    simde_uint8x8_t b = simde_vld1_u8(test_vec[i].b);
    simde_uint8x8_t r = simde_vhadd_u8(a, b);

    simde_test_arm_neon_assert_equal_u8x8(r, simde_vld1_u8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8x8_t a = simde_test_arm_neon_random_u8x8();
    simde_uint8x8_t b = simde_test_arm_neon_random_u8x8();
    simde_uint8x8_t r = simde_vhadd_u8(a, b);

    simde_test_arm_neon_write_u8x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vhadd_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[4];
    uint16_t b[4];
    uint16_t r[4];
  } test_vec[] = {
    { { UINT16_C(52357), UINT16_C(29523), UINT16_C(22999), UINT16_C(40851) },
      { UINT16_C(14024), UINT16_C(56419), UINT16_C(41726), UINT16_C( 6686) },
      { UINT16_C(33190), UINT16_C(42971), UINT16_C(32362), UINT16_C(23768) } },
    { { UINT16_C(32019), UINT16_C(22221), UINT16_C(30569), UINT16_C(44652) },
      { UINT16_C( 5680), UINT16_C( 1169), UINT16_C(47903), UINT16_C(42023) },
      { UINT16_C(18849), UINT16_C(11695), UINT16_C(39236), UINT16_C(43337) } },
    { { UINT16_C(31624), UINT16_C(24343), UINT16_C(43732), UINT16_C(40190) },
      { UINT16_C(25057), UINT16_C(57208), UINT16_C(38403), UINT16_C( 5881) },
      { UINT16_C(28340), UINT16_C(40775), UINT16_C(41067), UINT16_C(23035) } },
    { { UINT16_C(50707), UINT16_C(31852), UINT16_C(55614), UINT16_C(28203) },
      { UINT16_C(48367), UINT16_C( 3698), UINT16_C(39288), UINT16_C(  179) },
      { UINT16_C(49537), UINT16_C(17775), UINT16_C(47451), UINT16_C(14191) } },
    { { UINT16_C(51732), UINT16_C(59487), UINT16_C(23925), UINT16_C(22148) },
      { UINT16_C(64702), UINT16_C(49461), UINT16_C(11923), UINT16_C(42711) },
      { UINT16_C(58217), UINT16_C(54474), UINT16_C(17924), UINT16_C(32429) } },
    { { UINT16_C(17396), UINT16_C(12835), UINT16_C(19996), UINT16_C( 2976) },
      { UINT16_C( 4618), UINT16_C(33306), UINT16_C(52652), UINT16_C(49282) },
      { UINT16_C(11007), UINT16_C(23070), UINT16_C(36324), UINT16_C(26129) } },
    { { UINT16_C(57751), UINT16_C( 3241), UINT16_C(11582), UINT16_C(64610) },
      { UINT16_C(38698), UINT16_C(48573), UINT16_C(38085), UINT16_C(47715) },
      { UINT16_C(48224), UINT16_C(25907), UINT16_C(24833), UINT16_C(56162) } },
    { { UINT16_C(34520), UINT16_C(62700), UINT16_C(36308), UINT16_C(57088) },
      { UINT16_C( 6815), UINT16_C(19297), UINT16_C(58599), UINT16_C(32268) },
      { UINT16_C(20667), UINT16_C(40998), UINT16_C(47453), UINT16_C(44678) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4_t a = simde_vld1_u16(test_vec[i].a);
    simde_uint16x4_t b = simde_vld1_u16(test_vec[i].b);
    simde_uint16x4_t r = simde_vhadd_u16(a, b);
    simde_test_arm_neon_assert_equal_u16x4(r, simde_vld1_u16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x4_t a = simde_test_arm_neon_random_u16x4();
    simde_uint16x4_t b = simde_test_arm_neon_random_u16x4();
    simde_uint16x4_t r = simde_vhadd_u16(a, b);

    simde_test_arm_neon_write_u16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vhadd_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[2];
    uint32_t b[2];
    uint32_t r[2];
  } test_vec[] = {
    { { UINT32_C(  76264901), UINT32_C( 201387490) },
      { UINT32_C(1254735493), UINT32_C( 704916818) },
      { UINT32_C( 665500197), UINT32_C( 453152154) } },
    { { UINT32_C(2283794867), UINT32_C( 493297534) },
      { UINT32_C( 543803449), UINT32_C(1922987436) },
      { UINT32_C(1413799158), UINT32_C(1208142485) } },
    { { UINT32_C( 209070378), UINT32_C(2618914327) },
      { UINT32_C(2280055348), UINT32_C(3283217167) },
      { UINT32_C(1244562863), UINT32_C(2951065747) } },
    { { UINT32_C(1514918108), UINT32_C( 678933231) },
      { UINT32_C( 659087482), UINT32_C(2140792661) },
      { UINT32_C(1087002795), UINT32_C(1409862946) } },
    { { UINT32_C( 663490320), UINT32_C(3133384069) },
      { UINT32_C(2537663111), UINT32_C(1901785749) },
      { UINT32_C(1600576715), UINT32_C(2517584909) } },
    { { UINT32_C(2999690691), UINT32_C(3520807511) },
      { UINT32_C(2029527843), UINT32_C( 469274890) },
      { UINT32_C(2514609267), UINT32_C(1995041200) } },
    { { UINT32_C( 641893536), UINT32_C(2967471657) },
      { UINT32_C(1162289584), UINT32_C(3602293011) },
      { UINT32_C( 902091560), UINT32_C(3284882334) } },
    { { UINT32_C(2643034438), UINT32_C(3866059971) },
      { UINT32_C(2455725959), UINT32_C(2578274297) },
      { UINT32_C(2549380198), UINT32_C(3222167134) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2_t a = simde_vld1_u32(test_vec[i].a);
    simde_uint32x2_t b = simde_vld1_u32(test_vec[i].b);
    simde_uint32x2_t r = simde_vhadd_u32(a, b);
    simde_test_arm_neon_assert_equal_u32x2(r, simde_vld1_u32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x2_t a = simde_test_arm_neon_random_u32x2();
    simde_uint32x2_t b = simde_test_arm_neon_random_u32x2();
    simde_uint32x2_t r = simde_vhadd_u32(a, b);

    simde_test_arm_neon_write_u32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vhaddq_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[16];
    int8_t b[16];
    int8_t r[16];
  } test_vec[] = {
    { {  INT8_C(  14), -INT8_C(   8),  INT8_C(  51),  INT8_C(  84), -INT8_C(  33),  INT8_C( 105), -INT8_C(  96), -INT8_C(  60),
        -INT8_C(  70),  INT8_C(  54), -INT8_C( 105), -INT8_C( 122), -INT8_C(   3), -INT8_C(  81),  INT8_C(  63),  INT8_C(  57) },
      {  INT8_C(  47),  INT8_C(  56), -INT8_C(  25),  INT8_C(  91),  INT8_C(  15), -INT8_C(  61), -INT8_C(   2), -INT8_C( 127),
         INT8_C(  51),  INT8_C(  85),  INT8_C( 118),  INT8_C(  49),  INT8_C(  49),  INT8_C(  74), -INT8_C(  66),  INT8_C(  63) },
      {  INT8_C(  30),  INT8_C(  24),  INT8_C(  13),  INT8_C(  87), -INT8_C(   9),  INT8_C(  22), -INT8_C(  49), -INT8_C(  94),
        -INT8_C(  10),  INT8_C(  69),  INT8_C(   6), -INT8_C(  37),  INT8_C(  23), -INT8_C(   4), -INT8_C(   2),  INT8_C(  60) } },
    { {  INT8_C(  66), -INT8_C(  15), -INT8_C( 108),  INT8_C(  34),  INT8_C(  91),  INT8_C(  52), -INT8_C(  26),  INT8_C(  21),
         INT8_C( 107),  INT8_C( 125), -INT8_C( 101),  INT8_C( 104),  INT8_C(  44), -INT8_C(  37), -INT8_C(  94),  INT8_C(  91) },
      {  INT8_C(  19), -INT8_C( 119), -INT8_C(  74),  INT8_C(  34),  INT8_C(  76), -INT8_C(  75), -INT8_C(  93),      INT8_MAX,
         INT8_C(  10),  INT8_C(  25), -INT8_C(  79),  INT8_C(  59),  INT8_C(  99),  INT8_C( 111),  INT8_C( 123), -INT8_C(  90) },
      {  INT8_C(  42), -INT8_C(  67), -INT8_C(  91),  INT8_C(  34),  INT8_C(  83), -INT8_C(  12), -INT8_C(  60),  INT8_C(  74),
         INT8_C(  58),  INT8_C(  75), -INT8_C(  90),  INT8_C(  81),  INT8_C(  71),  INT8_C(  37),  INT8_C(  14),  INT8_C(   0) } },
    { {  INT8_C(  96),  INT8_C(  15), -INT8_C(  56), -INT8_C(  69),  INT8_C(  67), -INT8_C(  82), -INT8_C(  48), -INT8_C(  82),
         INT8_C(  43),  INT8_C( 108),  INT8_C(  23),  INT8_C(  88),  INT8_C(  71), -INT8_C(  71), -INT8_C(  77),  INT8_C(  90) },
      {  INT8_C(  66),  INT8_C( 106),  INT8_C( 125), -INT8_C( 114),  INT8_C(  31),  INT8_C(  32),  INT8_C(  13),  INT8_C(  41),
         INT8_C(  58), -INT8_C(  66),  INT8_C( 101), -INT8_C(  99),  INT8_C(  45), -INT8_C(  32),  INT8_C(  67), -INT8_C( 114) },
      {  INT8_C(  81),  INT8_C(  60),  INT8_C(  34), -INT8_C(  92),  INT8_C(  49), -INT8_C(  25), -INT8_C(  18), -INT8_C(  21),
         INT8_C(  50),  INT8_C(  21),  INT8_C(  62), -INT8_C(   6),  INT8_C(  58), -INT8_C(  52), -INT8_C(   5), -INT8_C(  12) } },
    { { -INT8_C(  17),  INT8_C(  11),  INT8_C(  73),  INT8_C(  50), -INT8_C(  71),  INT8_C(  26), -INT8_C(  31), -INT8_C(  27),
        -INT8_C( 122), -INT8_C(   8),  INT8_C(  61), -INT8_C(  51), -INT8_C(  79), -INT8_C(  16),  INT8_C(  39), -INT8_C(  13) },
      {  INT8_C(  90), -INT8_C(  92), -INT8_C( 127),  INT8_C( 121), -INT8_C(  59), -INT8_C( 114), -INT8_C(  93), -INT8_C(   1),
         INT8_C(  77),  INT8_C(   8), -INT8_C( 100),  INT8_C( 122), -INT8_C(  24), -INT8_C(  32),  INT8_C(   8), -INT8_C(  41) },
      {  INT8_C(  36), -INT8_C(  41), -INT8_C(  27),  INT8_C(  85), -INT8_C(  65), -INT8_C(  44), -INT8_C(  62), -INT8_C(  14),
        -INT8_C(  23),  INT8_C(   0), -INT8_C(  20),  INT8_C(  35), -INT8_C(  52), -INT8_C(  24),  INT8_C(  23), -INT8_C(  27) } },
    { { -INT8_C(  21),  INT8_C(  82),  INT8_C(   9), -INT8_C(  91),  INT8_C( 108), -INT8_C(  22), -INT8_C( 118), -INT8_C(  14),
        -INT8_C(  30), -INT8_C(  57), -INT8_C(  65), -INT8_C( 109), -INT8_C(  73), -INT8_C(  26), -INT8_C( 122),  INT8_C(  18) },
      { -INT8_C( 117),  INT8_C(   7), -INT8_C( 117),  INT8_C(  80), -INT8_C( 106),  INT8_C(  46),  INT8_C(  79), -INT8_C(  29),
         INT8_C(  54), -INT8_C(  21),  INT8_C(  93),  INT8_C(  30), -INT8_C(  53),  INT8_C( 102), -INT8_C(  11), -INT8_C(  73) },
      { -INT8_C(  69),  INT8_C(  44), -INT8_C(  54), -INT8_C(   6),  INT8_C(   1),  INT8_C(  12), -INT8_C(  20), -INT8_C(  22),
         INT8_C(  12), -INT8_C(  39),  INT8_C(  14), -INT8_C(  40), -INT8_C(  63),  INT8_C(  38), -INT8_C(  67), -INT8_C(  28) } },
    { { -INT8_C(  72), -INT8_C(   1),  INT8_C(  92),  INT8_C(  36), -INT8_C(  23), -INT8_C(  26),  INT8_C(  22), -INT8_C(  52),
        -INT8_C(  83), -INT8_C(  43),  INT8_C(  95),  INT8_C( 100), -INT8_C(  69), -INT8_C(  26),  INT8_C( 118),  INT8_C(  70) },
      { -INT8_C(  19),  INT8_C(   2), -INT8_C( 106), -INT8_C( 125),  INT8_C(  48), -INT8_C(  27),  INT8_C( 102),  INT8_C( 103),
        -INT8_C(  47), -INT8_C(  60), -INT8_C( 123), -INT8_C( 100),  INT8_C(  42),  INT8_C( 123),  INT8_C(  83), -INT8_C(  30) },
      { -INT8_C(  46),  INT8_C(   0), -INT8_C(   7), -INT8_C(  45),  INT8_C(  12), -INT8_C(  27),  INT8_C(  62),  INT8_C(  25),
        -INT8_C(  65), -INT8_C(  52), -INT8_C(  14),  INT8_C(   0), -INT8_C(  14),  INT8_C(  48),  INT8_C( 100),  INT8_C(  20) } },
    { {  INT8_C( 122), -INT8_C(  81),  INT8_C(   6),  INT8_C(  99), -INT8_C( 107),  INT8_C(  28),  INT8_C(  47),  INT8_C(  66),
        -INT8_C(  15), -INT8_C( 113), -INT8_C(  89), -INT8_C(  84),  INT8_C( 117),  INT8_C(  29), -INT8_C(  13),  INT8_C(  98) },
      {  INT8_C(  31), -INT8_C( 119), -INT8_C(  26),  INT8_C(  80),  INT8_C( 111),  INT8_C(  76), -INT8_C(  73),  INT8_C(  64),
         INT8_C(  16),  INT8_C(  60), -INT8_C(  36),  INT8_C(  58), -INT8_C(  73),  INT8_C(  48),  INT8_C(  28),  INT8_C(  49) },
      {  INT8_C(  76), -INT8_C( 100), -INT8_C(  10),  INT8_C(  89),  INT8_C(   2),  INT8_C(  52), -INT8_C(  13),  INT8_C(  65),
         INT8_C(   0), -INT8_C(  27), -INT8_C(  63), -INT8_C(  13),  INT8_C(  22),  INT8_C(  38),  INT8_C(   7),  INT8_C(  73) } },
    { { -INT8_C(  33),  INT8_C(  34), -INT8_C( 107),  INT8_C( 117),  INT8_C(  62), -INT8_C(  60), -INT8_C(  73),  INT8_C(  47),
         INT8_C(  83),  INT8_C(  94), -INT8_C(  36), -INT8_C(  56),  INT8_C( 124), -INT8_C(  49),  INT8_C(  43), -INT8_C( 101) },
      {  INT8_C(  88),  INT8_C(  17), -INT8_C(  21), -INT8_C(  57),  INT8_C(  93), -INT8_C(  94),  INT8_C(   7),  INT8_C( 110),
        -INT8_C(  33), -INT8_C(  28), -INT8_C(  88), -INT8_C( 106),  INT8_C(  20), -INT8_C(  59), -INT8_C(  56), -INT8_C(  13) },
      {  INT8_C(  27),  INT8_C(  25), -INT8_C(  64),  INT8_C(  30),  INT8_C(  77), -INT8_C(  77), -INT8_C(  33),  INT8_C(  78),
         INT8_C(  25),  INT8_C(  33), -INT8_C(  62), -INT8_C(  81),  INT8_C(  72), -INT8_C(  54), -INT8_C(   7), -INT8_C(  57) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16_t a = simde_vld1q_s8(test_vec[i].a);
    simde_int8x16_t b = simde_vld1q_s8(test_vec[i].b);
    simde_int8x16_t r = simde_vhaddq_s8(a, b);

    simde_test_arm_neon_assert_equal_i8x16(r, simde_vld1q_s8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x16_t a = simde_test_arm_neon_random_i8x16();
    simde_int8x16_t b = simde_test_arm_neon_random_i8x16();
    simde_int8x16_t r = simde_vhaddq_s8(a, b);

    simde_test_arm_neon_write_i8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vhaddq_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[8];
    int16_t b[8];
    int16_t r[8];
  } test_vec[] = {
    { { -INT16_C(  4133),  INT16_C(  1215), -INT16_C( 24587), -INT16_C( 23116), -INT16_C(   832), -INT16_C( 11030), -INT16_C( 24419), -INT16_C(  6998) },
      {  INT16_C( 13089), -INT16_C(  6783), -INT16_C(  3945),  INT16_C(  8139),  INT16_C( 10840),  INT16_C( 20913),  INT16_C( 24193),  INT16_C( 23786) },
      {  INT16_C(  4478), -INT16_C(  2784), -INT16_C( 14266), -INT16_C(  7489),  INT16_C(  5004),  INT16_C(  4941), -INT16_C(   113),  INT16_C(  8394) } },
    { { -INT16_C( 21939),  INT16_C( 17248),  INT16_C(  5449),  INT16_C(  2792), -INT16_C( 11503), -INT16_C( 20770), -INT16_C( 30605), -INT16_C( 27246) },
      {  INT16_C(  5308),  INT16_C( 21370),  INT16_C( 17668),  INT16_C( 23666),  INT16_C(  9072), -INT16_C(  3667), -INT16_C( 26495), -INT16_C( 12466) },
      { -INT16_C(  8316),  INT16_C( 19309),  INT16_C( 11558),  INT16_C( 13229), -INT16_C(  1216), -INT16_C( 12219), -INT16_C( 28550), -INT16_C( 19856) } },
    { { -INT16_C( 20926), -INT16_C( 29934), -INT16_C(  1341), -INT16_C( 11115),  INT16_C( 29645),  INT16_C( 16771),  INT16_C(  5628), -INT16_C( 18218) },
      {  INT16_C( 20521),  INT16_C( 11787),  INT16_C( 32405),  INT16_C(  1418),  INT16_C( 14497),  INT16_C(  9207),  INT16_C( 17872),  INT16_C(  4850) },
      { -INT16_C(   203), -INT16_C(  9074),  INT16_C( 15532), -INT16_C(  4849),  INT16_C( 22071),  INT16_C( 12989),  INT16_C( 11750), -INT16_C(  6684) } },
    { {  INT16_C(  1267), -INT16_C( 18531),  INT16_C( 13310), -INT16_C( 13173),  INT16_C(  3750), -INT16_C( 24051), -INT16_C(  7388),  INT16_C( 19802) },
      {  INT16_C( 26163), -INT16_C( 14213),  INT16_C(  1764), -INT16_C( 31282), -INT16_C( 15042),  INT16_C(  3752), -INT16_C( 26102), -INT16_C(   736) },
      {  INT16_C( 13715), -INT16_C( 16372),  INT16_C(  7537), -INT16_C( 22228), -INT16_C(  5646), -INT16_C( 10150), -INT16_C( 16745),  INT16_C(  9533) } },
    { { -INT16_C( 16994), -INT16_C( 25164),  INT16_C( 16624), -INT16_C( 26775),  INT16_C( 30286),  INT16_C( 29241), -INT16_C( 27559), -INT16_C( 29504) },
      {  INT16_C( 15354), -INT16_C(  8620),  INT16_C(  8769),  INT16_C( 32611),  INT16_C(  3303), -INT16_C(  3699), -INT16_C( 21082),  INT16_C( 17903) },
      { -INT16_C(   820), -INT16_C( 16892),  INT16_C( 12696),  INT16_C(  2918),  INT16_C( 16794),  INT16_C( 12771), -INT16_C( 24321), -INT16_C(  5801) } },
    { { -INT16_C( 23701),  INT16_C( 23522),  INT16_C( 19427),  INT16_C( 13042),  INT16_C( 11457),  INT16_C(  6820),  INT16_C( 25792), -INT16_C( 17754) },
      { -INT16_C(  1376), -INT16_C(  7784), -INT16_C(  1251),  INT16_C(  1121), -INT16_C(  4601), -INT16_C( 20746), -INT16_C(  6756),  INT16_C(  2035) },
      { -INT16_C( 12539),  INT16_C(  7869),  INT16_C(  9088),  INT16_C(  7081),  INT16_C(  3428), -INT16_C(  6963),  INT16_C(  9518), -INT16_C(  7860) } },
    { { -INT16_C( 10872),  INT16_C( 27746),  INT16_C( 21792), -INT16_C(  7778),  INT16_C( 17025),  INT16_C( 16891), -INT16_C( 24153),  INT16_C( 18427) },
      { -INT16_C( 27749), -INT16_C( 18392), -INT16_C( 30322), -INT16_C( 26947), -INT16_C( 19592),  INT16_C(  5188),  INT16_C( 14232),  INT16_C(  8219) },
      { -INT16_C( 19311),  INT16_C(  4677), -INT16_C(  4265), -INT16_C( 17363), -INT16_C(  1284),  INT16_C( 11039), -INT16_C(  4961),  INT16_C( 13323) } },
    { {  INT16_C( 32012),  INT16_C( 11404),  INT16_C( 10962),  INT16_C( 21261),  INT16_C(  2157),  INT16_C(  5268), -INT16_C( 28759),  INT16_C( 17499) },
      { -INT16_C( 31966), -INT16_C( 19971), -INT16_C( 17907), -INT16_C( 31417), -INT16_C( 29843),  INT16_C(  1433), -INT16_C( 19262), -INT16_C( 12763) },
      {  INT16_C(    23), -INT16_C(  4284), -INT16_C(  3473), -INT16_C(  5078), -INT16_C( 13843),  INT16_C(  3350), -INT16_C( 24011),  INT16_C(  2368) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_int16x8_t b = simde_vld1q_s16(test_vec[i].b);
    simde_int16x8_t r = simde_vhaddq_s16(a, b);

    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x8_t a = simde_test_arm_neon_random_i16x8();
    simde_int16x8_t b = simde_test_arm_neon_random_i16x8();
    simde_int16x8_t r = simde_vhaddq_s16(a, b);

    simde_test_arm_neon_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vhaddq_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[4];
    int32_t b[4];
    int32_t r[4];
  } test_vec[] = {
    { {  INT32_C(    83538481),  INT32_C(  1230440412), -INT32_C(  1201804273), -INT32_C(  1627604869) },
      {  INT32_C(  1229977916),  INT32_C(   550409907), -INT32_C(   484088031),  INT32_C(  1286687515) },
      {  INT32_C(   656758198),  INT32_C(   890425159), -INT32_C(   842946152), -INT32_C(   170458677) } },
    { { -INT32_C(   649024515), -INT32_C(  1054627662),  INT32_C(   259621012),  INT32_C(  1974302009) },
      {  INT32_C(   582941807), -INT32_C(  1287418734),  INT32_C(   244738291), -INT32_C(  1336260685) },
      { -INT32_C(    33041354), -INT32_C(  1171023198),  INT32_C(   252179651),  INT32_C(   319020662) } },
    { { -INT32_C(  1534415886), -INT32_C(   412766893),  INT32_C(  1727454765), -INT32_C(  1009015724) },
      {  INT32_C(   870685088),  INT32_C(   417736741),  INT32_C(  1143373201), -INT32_C(  1208647228) },
      { -INT32_C(   331865399),  INT32_C(     2484924),  INT32_C(  1435413983), -INT32_C(  1108831476) } },
    { {  INT32_C(  2136702764),  INT32_C(  1499906348), -INT32_C(   205497185), -INT32_C(  1581868288) },
      {  INT32_C(  1523883061),  INT32_C(  1433647812), -INT32_C(    56977097),  INT32_C(  1186172698) },
      {  INT32_C(  1830292912),  INT32_C(  1466777080), -INT32_C(   131237141), -INT32_C(   197847795) } },
    { {  INT32_C(   985992718),  INT32_C(  1871915983), -INT32_C(  2006822008),  INT32_C(   606673391) },
      {  INT32_C(  2038365621), -INT32_C(   271584840), -INT32_C(  1511298677),  INT32_C(   116170488) },
      {  INT32_C(  1512179169),  INT32_C(   800165571), -INT32_C(  1759060343),  INT32_C(   361421939) } },
    { {  INT32_C(  2084614573),  INT32_C(  1709954013),  INT32_C(   384650791),  INT32_C(   473569127) },
      { -INT32_C(   862603244),  INT32_C(   901538986), -INT32_C(   975525939), -INT32_C(   204749242) },
      {  INT32_C(   611005664),  INT32_C(  1305746499), -INT32_C(   295437574),  INT32_C(   134409942) } },
    { {  INT32_C(  1433340792),  INT32_C(   112876511),  INT32_C(   270313385), -INT32_C(   752068930) },
      { -INT32_C(  1197489906), -INT32_C(   202548442),  INT32_C(  1236912131),  INT32_C(   104629390) },
      {  INT32_C(   117925443), -INT32_C(    44835966),  INT32_C(   753612758), -INT32_C(   323719770) } },
    { {  INT32_C(  1868278672), -INT32_C(  1351281402),  INT32_C(  2076152253), -INT32_C(   179377177) },
      { -INT32_C(   743510355),  INT32_C(  1288084297), -INT32_C(   225083549), -INT32_C(  1795632892) },
      {  INT32_C(   562384158), -INT32_C(    31598553),  INT32_C(   925534352), -INT32_C(   987505035) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int32x4_t b = simde_vld1q_s32(test_vec[i].b);
    simde_int32x4_t r = simde_vhaddq_s32(a, b);
    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x4_t a = simde_test_arm_neon_random_i32x4();
    simde_int32x4_t b = simde_test_arm_neon_random_i32x4();
    simde_int32x4_t r = simde_vhaddq_s32(a, b);

    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vhaddq_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t a[16];
    uint8_t b[16];
    uint8_t r[16];
  } test_vec[] = {
    { { UINT8_C(115), UINT8_C(226), UINT8_C( 55), UINT8_C( 33), UINT8_C(202), UINT8_C(200), UINT8_C(178), UINT8_C(204),
        UINT8_C( 73), UINT8_C(156), UINT8_C(208), UINT8_C(156), UINT8_C(200), UINT8_C( 50), UINT8_C( 25), UINT8_C( 63) },
      { UINT8_C(197), UINT8_C(  4), UINT8_C(161), UINT8_C(225), UINT8_C( 73), UINT8_C(219), UINT8_C(126), UINT8_C( 35),
        UINT8_C( 44), UINT8_C(165), UINT8_C( 54), UINT8_C( 96), UINT8_C(  3), UINT8_C(194), UINT8_C( 69), UINT8_C(118) },
      { UINT8_C(156), UINT8_C(115), UINT8_C(108), UINT8_C(129), UINT8_C(137), UINT8_C(209), UINT8_C(152), UINT8_C(119),
        UINT8_C( 58), UINT8_C(160), UINT8_C(131), UINT8_C(126), UINT8_C(101), UINT8_C(122), UINT8_C( 47), UINT8_C( 90) } },
    { { UINT8_C(164), UINT8_C(124), UINT8_C(151), UINT8_C(111), UINT8_C( 68), UINT8_C( 73), UINT8_C( 59), UINT8_C(141),
        UINT8_C(230), UINT8_C( 11), UINT8_C( 41), UINT8_C(174), UINT8_C( 61), UINT8_C( 66), UINT8_C(238), UINT8_C(  3) },
      { UINT8_C( 71), UINT8_C(143), UINT8_C(228), UINT8_C(144), UINT8_C(106), UINT8_C( 99), UINT8_C(180), UINT8_C(150),
        UINT8_C(  8), UINT8_C(234), UINT8_C(246), UINT8_C( 11), UINT8_C(172), UINT8_C( 60), UINT8_C(129), UINT8_C( 81) },
      { UINT8_C(117), UINT8_C(133), UINT8_C(189), UINT8_C(127), UINT8_C( 87), UINT8_C( 86), UINT8_C(119), UINT8_C(145),
        UINT8_C(119), UINT8_C(122), UINT8_C(143), UINT8_C( 92), UINT8_C(116), UINT8_C( 63), UINT8_C(183), UINT8_C( 42) } },
    { { UINT8_C(184), UINT8_C( 25), UINT8_C(192), UINT8_C(253), UINT8_C( 98), UINT8_C(251), UINT8_C(138), UINT8_C( 72),
        UINT8_C(  6), UINT8_C(180), UINT8_C(247), UINT8_C( 67), UINT8_C(246), UINT8_C(229), UINT8_C( 70), UINT8_C( 61) },
      { UINT8_C(116), UINT8_C( 43), UINT8_C(206), UINT8_C(222), UINT8_C(142), UINT8_C(130), UINT8_C(116), UINT8_C(150),
        UINT8_C(108), UINT8_C(107), UINT8_C(162), UINT8_C( 25), UINT8_C(167), UINT8_C( 35), UINT8_C(106), UINT8_C( 95) },
      { UINT8_C(150), UINT8_C( 34), UINT8_C(199), UINT8_C(237), UINT8_C(120), UINT8_C(190), UINT8_C(127), UINT8_C(111),
        UINT8_C( 57), UINT8_C(143), UINT8_C(204), UINT8_C( 46), UINT8_C(206), UINT8_C(132), UINT8_C( 88), UINT8_C( 78) } },
    { { UINT8_C( 60), UINT8_C( 42), UINT8_C( 92), UINT8_C(159), UINT8_C( 37), UINT8_C(231), UINT8_C(231), UINT8_C( 43),
        UINT8_C(155), UINT8_C(222), UINT8_C(110), UINT8_C(145), UINT8_C(195), UINT8_C(181), UINT8_C(207), UINT8_C( 55) },
      { UINT8_C(224), UINT8_C(157), UINT8_C( 21), UINT8_C(110), UINT8_C( 31), UINT8_C(138), UINT8_C(  4), UINT8_C(139),
        UINT8_C(245), UINT8_C(166), UINT8_C(164), UINT8_C(156), UINT8_C(202), UINT8_C( 14), UINT8_C(251), UINT8_C(  6) },
      { UINT8_C(142), UINT8_C( 99), UINT8_C( 56), UINT8_C(134), UINT8_C( 34), UINT8_C(184), UINT8_C(117), UINT8_C( 91),
        UINT8_C(200), UINT8_C(194), UINT8_C(137), UINT8_C(150), UINT8_C(198), UINT8_C( 97), UINT8_C(229), UINT8_C( 30) } },
    { { UINT8_C( 56), UINT8_C( 88), UINT8_C(165), UINT8_C( 93), UINT8_C( 63), UINT8_C(141), UINT8_C(136), UINT8_C(218),
        UINT8_C(107), UINT8_C(247), UINT8_C(107), UINT8_C( 47), UINT8_C(172), UINT8_C( 58), UINT8_C(102), UINT8_C(140) },
      { UINT8_C(215), UINT8_C(124), UINT8_C(250), UINT8_C(246), UINT8_C(  6), UINT8_C(254), UINT8_C(130), UINT8_C(251),
        UINT8_C(165), UINT8_C( 38), UINT8_C(151), UINT8_C(111), UINT8_C( 53), UINT8_C(146), UINT8_C(117), UINT8_C(109) },
      { UINT8_C(135), UINT8_C(106), UINT8_C(207), UINT8_C(169), UINT8_C( 34), UINT8_C(197), UINT8_C(133), UINT8_C(234),
        UINT8_C(136), UINT8_C(142), UINT8_C(129), UINT8_C( 79), UINT8_C(112), UINT8_C(102), UINT8_C(109), UINT8_C(124) } },
    { { UINT8_C(234), UINT8_C( 27), UINT8_C(203), UINT8_C( 41), UINT8_C(168), UINT8_C( 83), UINT8_C(  3), UINT8_C( 19),
        UINT8_C( 74), UINT8_C(111), UINT8_C( 66), UINT8_C(246), UINT8_C(169), UINT8_C(169), UINT8_C(130), UINT8_C(129) },
      { UINT8_C( 37), UINT8_C(124), UINT8_C(119), UINT8_C( 43), UINT8_C(123), UINT8_C(249), UINT8_C( 38), UINT8_C( 32),
        UINT8_C( 32), UINT8_C(189), UINT8_C(143), UINT8_C( 85), UINT8_C( 79), UINT8_C(  4), UINT8_C(194), UINT8_C( 58) },
      { UINT8_C(135), UINT8_C( 75), UINT8_C(161), UINT8_C( 42), UINT8_C(145), UINT8_C(166), UINT8_C( 20), UINT8_C( 25),
        UINT8_C( 53), UINT8_C(150), UINT8_C(104), UINT8_C(165), UINT8_C(124), UINT8_C( 86), UINT8_C(162), UINT8_C( 93) } },
    { { UINT8_C( 31), UINT8_C(141), UINT8_C( 99), UINT8_C(199), UINT8_C(225), UINT8_C(103), UINT8_C(219), UINT8_C( 43),
        UINT8_C(214), UINT8_C( 29), UINT8_C( 34), UINT8_C(127), UINT8_C(198), UINT8_C(164), UINT8_C(  0), UINT8_C(235) },
      { UINT8_C( 33), UINT8_C(120), UINT8_C( 22), UINT8_C(156), UINT8_C(113), UINT8_C( 60), UINT8_C(188), UINT8_C(145),
        UINT8_C(249), UINT8_C( 75), UINT8_C(230), UINT8_C( 73), UINT8_C( 79), UINT8_C(169), UINT8_C(131), UINT8_C(111) },
      { UINT8_C( 32), UINT8_C(130), UINT8_C( 60), UINT8_C(177), UINT8_C(169), UINT8_C( 81), UINT8_C(203), UINT8_C( 94),
        UINT8_C(231), UINT8_C( 52), UINT8_C(132), UINT8_C(100), UINT8_C(138), UINT8_C(166), UINT8_C( 65), UINT8_C(173) } },
    { { UINT8_C( 54), UINT8_C(230), UINT8_C( 54), UINT8_C( 23), UINT8_C( 77), UINT8_C( 17), UINT8_C( 67), UINT8_C( 35),
        UINT8_C( 47), UINT8_C(101), UINT8_C(163), UINT8_C(245), UINT8_C(  9), UINT8_C(163), UINT8_C(225), UINT8_C( 42) },
      { UINT8_C( 27), UINT8_C(247), UINT8_C(198), UINT8_C(141), UINT8_C( 52), UINT8_C(130), UINT8_C( 30), UINT8_C( 45),
        UINT8_C(205), UINT8_C(  5), UINT8_C(118), UINT8_C( 29), UINT8_C(174), UINT8_C(249), UINT8_C(140), UINT8_C(228) },
      { UINT8_C( 40), UINT8_C(238), UINT8_C(126), UINT8_C( 82), UINT8_C( 64), UINT8_C( 73), UINT8_C( 48), UINT8_C( 40),
        UINT8_C(126), UINT8_C( 53), UINT8_C(140), UINT8_C(137), UINT8_C( 91), UINT8_C(206), UINT8_C(182), UINT8_C(135) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x16_t a = simde_vld1q_u8(test_vec[i].a);
    simde_uint8x16_t b = simde_vld1q_u8(test_vec[i].b);
    simde_uint8x16_t r = simde_vhaddq_u8(a, b);

    simde_test_arm_neon_assert_equal_u8x16(r, simde_vld1q_u8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8x16_t a = simde_test_arm_neon_random_u8x16();
    simde_uint8x16_t b = simde_test_arm_neon_random_u8x16();
    simde_uint8x16_t r = simde_vhaddq_u8(a, b);

    simde_test_arm_neon_write_u8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vhaddq_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[8];
    uint16_t b[8];
    uint16_t r[8];
  } test_vec[] = {
    { { UINT16_C(21629), UINT16_C(33539), UINT16_C(30825), UINT16_C( 9779), UINT16_C(61961), UINT16_C(61602), UINT16_C(61662), UINT16_C(35813) },
      { UINT16_C(37854), UINT16_C(10334), UINT16_C( 9263), UINT16_C(37492), UINT16_C( 2724), UINT16_C(43140), UINT16_C(32219), UINT16_C(22588) },
      { UINT16_C(29741), UINT16_C(21936), UINT16_C(20044), UINT16_C(23635), UINT16_C(32342), UINT16_C(52371), UINT16_C(46940), UINT16_C(29200) } },
    { { UINT16_C(16337), UINT16_C(15068), UINT16_C( 4023), UINT16_C(49249), UINT16_C(  769), UINT16_C(57264), UINT16_C(38387), UINT16_C(53866) },
      { UINT16_C(51241), UINT16_C(22778), UINT16_C(28397), UINT16_C(37354), UINT16_C(28536), UINT16_C(21561), UINT16_C(30188), UINT16_C(48556) },
      { UINT16_C(33789), UINT16_C(18923), UINT16_C(16210), UINT16_C(43301), UINT16_C(14652), UINT16_C(39412), UINT16_C(34287), UINT16_C(51211) } },
    { { UINT16_C(34996), UINT16_C(27639), UINT16_C(22679), UINT16_C(39211), UINT16_C(56155), UINT16_C(20344), UINT16_C(58224), UINT16_C(39201) },
      { UINT16_C( 7083), UINT16_C(39153), UINT16_C(56457), UINT16_C(  553), UINT16_C(25163), UINT16_C(14166), UINT16_C(  727), UINT16_C(35828) },
      { UINT16_C(21039), UINT16_C(33396), UINT16_C(39568), UINT16_C(19882), UINT16_C(40659), UINT16_C(17255), UINT16_C(29475), UINT16_C(37514) } },
    { { UINT16_C(60299), UINT16_C( 8950), UINT16_C( 8516), UINT16_C(40891), UINT16_C(13564), UINT16_C(28142), UINT16_C( 3863), UINT16_C(49670) },
      { UINT16_C(63530), UINT16_C(46171), UINT16_C(34004), UINT16_C( 8118), UINT16_C( 3303), UINT16_C(48726), UINT16_C(18958), UINT16_C(39242) },
      { UINT16_C(61914), UINT16_C(27560), UINT16_C(21260), UINT16_C(24504), UINT16_C( 8433), UINT16_C(38434), UINT16_C(11410), UINT16_C(44456) } },
    { { UINT16_C(16437), UINT16_C(31164), UINT16_C(30562), UINT16_C(24089), UINT16_C( 1963), UINT16_C(49867), UINT16_C(53783), UINT16_C(16773) },
      { UINT16_C(57546), UINT16_C(40693), UINT16_C(43876), UINT16_C(19389), UINT16_C( 5047), UINT16_C(50698), UINT16_C(21597), UINT16_C(37471) },
      { UINT16_C(36991), UINT16_C(35928), UINT16_C(37219), UINT16_C(21739), UINT16_C( 3505), UINT16_C(50282), UINT16_C(37690), UINT16_C(27122) } },
    { { UINT16_C( 7060), UINT16_C(62988), UINT16_C( 9619), UINT16_C(15957), UINT16_C( 8236), UINT16_C(17153), UINT16_C(34546), UINT16_C(48261) },
      { UINT16_C(31334), UINT16_C(51802), UINT16_C( 5926), UINT16_C(56598), UINT16_C( 8234), UINT16_C(34723), UINT16_C(  884), UINT16_C( 2074) },
      { UINT16_C(19197), UINT16_C(57395), UINT16_C( 7772), UINT16_C(36277), UINT16_C( 8235), UINT16_C(25938), UINT16_C(17715), UINT16_C(25167) } },
    { { UINT16_C( 9758), UINT16_C(45567), UINT16_C(21579), UINT16_C(30704), UINT16_C(61812), UINT16_C(26555), UINT16_C(16503), UINT16_C(56611) },
      { UINT16_C(32442), UINT16_C(57511), UINT16_C(48533), UINT16_C(49342), UINT16_C(25053), UINT16_C(20807), UINT16_C(24932), UINT16_C(33626) },
      { UINT16_C(21100), UINT16_C(51539), UINT16_C(35056), UINT16_C(40023), UINT16_C(43432), UINT16_C(23681), UINT16_C(20717), UINT16_C(45118) } },
    { { UINT16_C(22919), UINT16_C(53812), UINT16_C( 9389), UINT16_C( 8522), UINT16_C( 1301), UINT16_C(35976), UINT16_C(44101), UINT16_C(65385) },
      { UINT16_C( 4394), UINT16_C(49120), UINT16_C(40654), UINT16_C(44159), UINT16_C(51199), UINT16_C(25853), UINT16_C(22312), UINT16_C(45287) },
      { UINT16_C(13656), UINT16_C(51466), UINT16_C(25021), UINT16_C(26340), UINT16_C(26250), UINT16_C(30914), UINT16_C(33206), UINT16_C(55336) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);
    simde_uint16x8_t b = simde_vld1q_u16(test_vec[i].b);
    simde_uint16x8_t r = simde_vhaddq_u16(a, b);
    simde_test_arm_neon_assert_equal_u16x8(r, simde_vld1q_u16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x8_t a = simde_test_arm_neon_random_u16x8();
    simde_uint16x8_t b = simde_test_arm_neon_random_u16x8();
    simde_uint16x8_t r = simde_vhaddq_u16(a, b);

    simde_test_arm_neon_write_u16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vhaddq_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[4];
    uint32_t b[4];
    uint32_t r[4];
  } test_vec[] = {
    { { UINT32_C(1568807856), UINT32_C(1434438720), UINT32_C( 383911889), UINT32_C(3709225907) },
      { UINT32_C( 731772508), UINT32_C(2480348308), UINT32_C( 217568483), UINT32_C(3703365164) },
      { UINT32_C(1150290182), UINT32_C(1957393514), UINT32_C( 300740186), UINT32_C(3706295535) } },
    { { UINT32_C( 976895738), UINT32_C(3700406539), UINT32_C(1962111424), UINT32_C( 424741309) },
      { UINT32_C(2470768383), UINT32_C(3995474699), UINT32_C( 486153968), UINT32_C(4143494908) },
      { UINT32_C(1723832060), UINT32_C(3847940619), UINT32_C(1224132696), UINT32_C(2284118108) } },
    { { UINT32_C(   3158773), UINT32_C(2900148459), UINT32_C(3995127601), UINT32_C(3607654872) },
      { UINT32_C(1802128480), UINT32_C(1482264936), UINT32_C(2876527791), UINT32_C(4288834570) },
      { UINT32_C( 902643626), UINT32_C(2191206697), UINT32_C(3435827696), UINT32_C(3948244721) } },
    { { UINT32_C(2332021407), UINT32_C(3291929746), UINT32_C(2226280107), UINT32_C( 677100232) },
      { UINT32_C(1871955463), UINT32_C( 113765463), UINT32_C(1269906240), UINT32_C(1179276199) },
      { UINT32_C(2101988435), UINT32_C(1702847604), UINT32_C(1748093173), UINT32_C( 928188215) } },
    { { UINT32_C(3100723750), UINT32_C(3514566438), UINT32_C( 643116894), UINT32_C(4031689193) },
      { UINT32_C(3462390135), UINT32_C( 248784589), UINT32_C( 156861793), UINT32_C(4283409369) },
      { UINT32_C(3281556942), UINT32_C(1881675513), UINT32_C( 399989343), UINT32_C(4157549281) } },
    { { UINT32_C( 330768621), UINT32_C(2263168040), UINT32_C(1286355555), UINT32_C(1648229099) },
      { UINT32_C(2821758171), UINT32_C( 615908547), UINT32_C(1663897482), UINT32_C(2690809267) },
      { UINT32_C(1576263396), UINT32_C(1439538293), UINT32_C(1475126518), UINT32_C(2169519183) } },
    { { UINT32_C(3316914589), UINT32_C(2957744461), UINT32_C(3221092307), UINT32_C(3424729841) },
      { UINT32_C(2574602966), UINT32_C(3770559318), UINT32_C(3997428539), UINT32_C( 110011752) },
      { UINT32_C(2945758777), UINT32_C(3364151889), UINT32_C(3609260423), UINT32_C(1767370796) } },
    { { UINT32_C( 214647487), UINT32_C(2948405211), UINT32_C(   7256590), UINT32_C(3402403828) },
      { UINT32_C( 946094561), UINT32_C(2820153965), UINT32_C(1989565453), UINT32_C(3229361153) },
      { UINT32_C( 580371024), UINT32_C(2884279588), UINT32_C( 998411021), UINT32_C(3315882490) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint32x4_t b = simde_vld1q_u32(test_vec[i].b);
    simde_uint32x4_t r = simde_vhaddq_u32(a, b);

    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x4_t a = simde_test_arm_neon_random_u32x4();
    simde_uint32x4_t b = simde_test_arm_neon_random_u32x4();
    simde_uint32x4_t r = simde_vhaddq_u32(a, b);

    simde_test_arm_neon_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vhadd_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vhadd_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vhadd_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vhadd_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vhadd_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vhadd_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vhaddq_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vhaddq_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vhaddq_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vhaddq_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vhaddq_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vhaddq_u32)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
