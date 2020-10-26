#define SIMDE_TEST_ARM_NEON_INSN orn

#include "test-neon.h"
#include "../../../simde/arm/neon/orn.h"

static int
test_simde_vorn_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[8];
    int8_t b[8];
    int8_t r[8];
  } test_vec[] = {
    { {  INT8_C(  71), -INT8_C(  69),  INT8_C( 126), -INT8_C(  50),  INT8_C(  51), -INT8_C(  21), -INT8_C(  47), -INT8_C( 103) },
      {  INT8_C(  30),  INT8_C(  10),  INT8_C(  57),  INT8_C(  26),  INT8_C( 126), -INT8_C(   9), -INT8_C(   8),  INT8_C(  99) },
      { -INT8_C(  25), -INT8_C(   1), -INT8_C(   2), -INT8_C(  17), -INT8_C(  77), -INT8_C(  21), -INT8_C(  41), -INT8_C(  99) } },
    { {  INT8_C(  83), -INT8_C(  92),  INT8_C(  91),  INT8_C(  51),  INT8_C(  23),  INT8_C(  56),  INT8_C(  16), -INT8_C(  37) },
      {  INT8_C(  38),  INT8_C(  14), -INT8_C( 105),  INT8_C(  93),  INT8_C(  53), -INT8_C(  77), -INT8_C(  24),  INT8_C( 124) },
      { -INT8_C(  37), -INT8_C(  11),  INT8_C( 123), -INT8_C(  77), -INT8_C(  33),  INT8_C( 124),  INT8_C(  23), -INT8_C(  37) } },
    { {  INT8_C( 111),  INT8_C( 102),  INT8_C(  74), -INT8_C(  94),  INT8_C(  82),  INT8_C(  27),  INT8_C(  59),  INT8_C( 112) },
      {  INT8_C(  38),  INT8_C( 116), -INT8_C( 118), -INT8_C(  92),  INT8_C( 107), -INT8_C( 126),  INT8_C(   7), -INT8_C(  65) },
      { -INT8_C(   1), -INT8_C(  17),      INT8_MAX, -INT8_C(   5), -INT8_C(  42),      INT8_MAX, -INT8_C(   5),  INT8_C( 112) } },
    { {  INT8_C(  39),  INT8_C(  99), -INT8_C(  14),  INT8_C(  62), -INT8_C( 101),  INT8_C(   2),  INT8_C(  25), -INT8_C(  63) },
      {  INT8_C(  16), -INT8_C(  80),  INT8_C(  30),  INT8_C(  69),  INT8_C( 100),  INT8_C(   6), -INT8_C(  63), -INT8_C(  45) },
      { -INT8_C(  17),  INT8_C( 111), -INT8_C(  13), -INT8_C(  66), -INT8_C( 101), -INT8_C(   5),  INT8_C(  63), -INT8_C(  19) } },
    { {  INT8_C( 108),  INT8_C(  11),  INT8_C( 117), -INT8_C(  66),  INT8_C(  39), -INT8_C(  80),  INT8_C(  46),  INT8_C(  77) },
      {  INT8_C(  36), -INT8_C(  72), -INT8_C(  15), -INT8_C( 112),  INT8_C(  59), -INT8_C(   7),  INT8_C(  79),  INT8_C(  98) },
      { -INT8_C(   1),  INT8_C(  79),      INT8_MAX, -INT8_C(   1), -INT8_C(  25), -INT8_C(  74), -INT8_C(  66), -INT8_C(  35) } },
    { {  INT8_C(  92),  INT8_C(  65), -INT8_C(  96), -INT8_C(   9),  INT8_C(  67), -INT8_C(  71), -INT8_C(  72),  INT8_C(  83) },
      {  INT8_C( 105), -INT8_C(  42), -INT8_C( 103), -INT8_C(  51), -INT8_C(  36),  INT8_C(  90), -INT8_C(  96),  INT8_C(  72) },
      { -INT8_C(  34),  INT8_C( 105), -INT8_C(  26), -INT8_C(   9),  INT8_C(  99), -INT8_C(  67), -INT8_C(   1), -INT8_C(   9) } },
    { {  INT8_C( 102),  INT8_C(  21),  INT8_C(   7), -INT8_C( 115), -INT8_C(  59),  INT8_C(  53), -INT8_C(  38), -INT8_C(  22) },
      { -INT8_C(  18), -INT8_C(  53),  INT8_C( 122),  INT8_C(  41), -INT8_C(  60), -INT8_C(  55), -INT8_C( 117),  INT8_C(  32) },
      {  INT8_C( 119),  INT8_C(  53), -INT8_C( 121), -INT8_C(  33), -INT8_C(   1),  INT8_C(  55), -INT8_C(   2), -INT8_C(   1) } },
    { {  INT8_C(  10),  INT8_C(  43),  INT8_C(  23),  INT8_C(  77), -INT8_C(  28), -INT8_C(  49), -INT8_C(  96),  INT8_C(  77) },
      { -INT8_C(  91),  INT8_C(  57),  INT8_C(  27), -INT8_C( 127), -INT8_C( 108), -INT8_C(  69), -INT8_C(  54), -INT8_C(   6) },
      {  INT8_C(  90), -INT8_C(  17), -INT8_C(   9),      INT8_MAX, -INT8_C(  17), -INT8_C(  49), -INT8_C(  75),  INT8_C(  77) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8_t a = simde_vld1_s8(test_vec[i].a);
    simde_int8x8_t b = simde_vld1_s8(test_vec[i].b);
    simde_int8x8_t r = simde_vorn_s8(a, b);

    simde_test_arm_neon_assert_equal_i8x8(r, simde_vld1_s8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x8_t a = simde_test_arm_neon_random_i8x8();
    simde_int8x8_t b = simde_test_arm_neon_random_i8x8();
    simde_int8x8_t r = simde_vorn_s8(a, b);

    simde_test_arm_neon_write_i8x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vorn_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[4];
    int16_t b[4];
    int16_t r[4];
  } test_vec[] = {
    { { -INT16_C( 11823), -INT16_C( 27001),  INT16_C( 24838), -INT16_C(  2944) },
      { -INT16_C(  1492), -INT16_C(  3811), -INT16_C( 22333), -INT16_C( 13039) },
      { -INT16_C( 10797), -INT16_C( 24857),  INT16_C( 30526), -INT16_C(  2322) } },
    { {  INT16_C( 10707), -INT16_C( 18662), -INT16_C( 17416), -INT16_C( 25083) },
      {  INT16_C(  8436), -INT16_C( 30689), -INT16_C(  5669), -INT16_C( 21374) },
      { -INT16_C(    37), -INT16_C(  2054), -INT16_C( 16388), -INT16_C(  8323) } },
    { {  INT16_C(  2490), -INT16_C( 16061), -INT16_C( 15510), -INT16_C( 26699) },
      { -INT16_C( 11330), -INT16_C( 32376), -INT16_C( 26245),  INT16_C( 20303) },
      {  INT16_C( 11771), -INT16_C(   137), -INT16_C(  6162), -INT16_C( 18507) } },
    { {  INT16_C( 27074), -INT16_C( 17658),  INT16_C(  2852),  INT16_C(  6489) },
      {  INT16_C( 30763),  INT16_C(  1953),  INT16_C(  9314),  INT16_C(  7347) },
      { -INT16_C(  4138), -INT16_C(  1186), -INT16_C(  9283), -INT16_C(  1187) } },
    { { -INT16_C(  2515), -INT16_C( 26403), -INT16_C( 27718),  INT16_C( 30767) },
      { -INT16_C( 18586), -INT16_C(  7687),  INT16_C( 18512),  INT16_C(  4912) },
      { -INT16_C(   323), -INT16_C( 24865), -INT16_C( 18497), -INT16_C(   785) } },
    { {  INT16_C( 14258), -INT16_C( 10546),  INT16_C( 10050),  INT16_C( 28399) },
      { -INT16_C( 28257),  INT16_C(   373),  INT16_C( 10421), -INT16_C(  7650) },
      {  INT16_C( 32754), -INT16_C(   306), -INT16_C(  2230),  INT16_C( 32751) } },
    { { -INT16_C(  1249), -INT16_C(  9862), -INT16_C( 22130), -INT16_C(  2991) },
      {  INT16_C( 19040), -INT16_C( 20010),  INT16_C(  1683),  INT16_C( 17860) },
      { -INT16_C(    97), -INT16_C(  8325), -INT16_C(  1554), -INT16_C(   389) } },
    { { -INT16_C( 28099), -INT16_C( 32741),  INT16_C(  3001),  INT16_C( 22766) },
      {  INT16_C( 25500),  INT16_C( 20826),  INT16_C( 30859), -INT16_C( 21965) },
      { -INT16_C( 24961), -INT16_C( 20801), -INT16_C( 28675),  INT16_C( 24046) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t a = simde_vld1_s16(test_vec[i].a);
    simde_int16x4_t b = simde_vld1_s16(test_vec[i].b);
    simde_int16x4_t r = simde_vorn_s16(a, b);

    simde_test_arm_neon_assert_equal_i16x4(r, simde_vld1_s16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x4_t a = simde_test_arm_neon_random_i16x4();
    simde_int16x4_t b = simde_test_arm_neon_random_i16x4();
    simde_int16x4_t r = simde_vorn_s16(a, b);

    simde_test_arm_neon_write_i16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vorn_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[2];
    int32_t b[2];
    int32_t r[2];
  } test_vec[] = {
    { { -INT32_C(   941672358),  INT32_C(  1460359429) },
      {  INT32_C(  1534253508), -INT32_C(  1871844903) },
      { -INT32_C(   404799877),  INT32_C(  2140886823) } },
    { {  INT32_C(  1247411385),  INT32_C(  1043917429) },
      { -INT32_C(   790489490), -INT32_C(  1189984161) },
      {  INT32_C(  1868430777),  INT32_C(  2130575349) } },
    { { -INT32_C(  2055147136),  INT32_C(   115182402) },
      {  INT32_C(  1046564709), -INT32_C(   221327560) },
      { -INT32_C(   979439206),  INT32_C(   268286919) } },
    { {  INT32_C(  1077684171), -INT32_C(  2139196398) },
      { -INT32_C(   363831157),  INT32_C(   681796264) },
      {  INT32_C(  1438629887), -INT32_C(   679543465) } },
    { { -INT32_C(  1783815341),  INT32_C(   345803439) },
      {  INT32_C(   307428825), -INT32_C(  1761336884) },
      { -INT32_C(    38984841),  INT32_C(  2097143487) } },
    { {  INT32_C(  1524056136),  INT32_C(  1088050613) },
      {  INT32_C(  1563044789), -INT32_C(   511324787) },
      { -INT32_C(    86518710),  INT32_C(  1593473015) } },
    { { -INT32_C(  1619643408), -INT32_C(  1749871939) },
      { -INT32_C(   592902640),  INT32_C(  1869917479) },
      { -INT32_C(  1082721281), -INT32_C(  1749331203) } },
    { { -INT32_C(  1563800595),  INT32_C(  1457693857) },
      {  INT32_C(  1572080847), -INT32_C(   901891623) },
      { -INT32_C(  1563689987),  INT32_C(  2011424423) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t a = simde_vld1_s32(test_vec[i].a);
    simde_int32x2_t b = simde_vld1_s32(test_vec[i].b);
    simde_int32x2_t r = simde_vorn_s32(a, b);

    simde_test_arm_neon_assert_equal_i32x2(r, simde_vld1_s32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x2_t a = simde_test_arm_neon_random_i32x2();
    simde_int32x2_t b = simde_test_arm_neon_random_i32x2();
    simde_int32x2_t r = simde_vorn_s32(a, b);

    simde_test_arm_neon_write_i32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vorn_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a[1];
    int64_t b[1];
    int64_t r[1];
  } test_vec[] = {
    { { -INT64_C( 2900003943802620820) },
      {  INT64_C(  340346227834186275) },
      { -INT64_C(   15800051893946884) } },
    { { -INT64_C(  618531193571802253) },
      { -INT64_C( 4307250660080607594) },
      { -INT64_C(    4805211211177093) } },
    { { -INT64_C( 2025019218014067897) },
      {  INT64_C( 3690109182816393241) },
      { -INT64_C( 1157495473783773209) } },
    { { -INT64_C(  321530848576283542) },
      { -INT64_C( 5193595468643574064) },
      { -INT64_C(  316382341262475921) } },
    { { -INT64_C( 6563245997126460601) },
      {  INT64_C( 7509200415277455171) },
      { -INT64_C( 5193777867993908225) } },
    { { -INT64_C(  124267704839668251) },
      { -INT64_C( 7095118474331639455) },
      { -INT64_C(  110637604046929921) } },
    { {  INT64_C( 4331495243257303022) },
      { -INT64_C( 2302054115141750361) },
      {  INT64_C( 4611281387325313022) } },
    { { -INT64_C( 1432301318404634638) },
      {  INT64_C( 5122360075800692259) },
      { -INT64_C(  216179728562012162) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x1_t a = simde_vld1_s64(test_vec[i].a);
    simde_int64x1_t b = simde_vld1_s64(test_vec[i].b);
    simde_int64x1_t r = simde_vorn_s64(a, b);

    simde_test_arm_neon_assert_equal_i64x1(r, simde_vld1_s64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int64x1_t a = simde_test_arm_neon_random_i64x1();
    simde_int64x1_t b = simde_test_arm_neon_random_i64x1();
    simde_int64x1_t r = simde_vorn_s64(a, b);

    simde_test_arm_neon_write_i64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x1(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vorn_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t a[8];
    uint8_t b[8];
    uint8_t r[8];
  } test_vec[] = {
    { { UINT8_C(150), UINT8_C(187), UINT8_C(191), UINT8_C(144), UINT8_C( 75), UINT8_C(220), UINT8_C(204), UINT8_C(242) },
      { UINT8_C(205), UINT8_C( 12), UINT8_C(151), UINT8_C(199), UINT8_C(129), UINT8_C(164), UINT8_C(167), UINT8_C(116) },
      { UINT8_C(182), UINT8_C(251),    UINT8_MAX, UINT8_C(184), UINT8_C(127), UINT8_C(223), UINT8_C(220), UINT8_C(251) } },
    { { UINT8_C(171), UINT8_C(210), UINT8_C(149), UINT8_C( 53), UINT8_C( 68), UINT8_C(180), UINT8_C( 33), UINT8_C(103) },
      { UINT8_C(250), UINT8_C(223), UINT8_C(224), UINT8_C( 83), UINT8_C( 39), UINT8_C(246), UINT8_C(154), UINT8_C(189) },
      { UINT8_C(175), UINT8_C(242), UINT8_C(159), UINT8_C(189), UINT8_C(220), UINT8_C(189), UINT8_C(101), UINT8_C(103) } },
    { { UINT8_C(178), UINT8_C( 90), UINT8_C( 77), UINT8_C(253), UINT8_C( 54), UINT8_C( 26), UINT8_C(239), UINT8_C(  3) },
      { UINT8_C( 38), UINT8_C(134), UINT8_C(202), UINT8_C(167), UINT8_C( 42), UINT8_C(114), UINT8_C( 27), UINT8_C(213) },
      { UINT8_C(251), UINT8_C(123), UINT8_C(125), UINT8_C(253), UINT8_C(247), UINT8_C(159), UINT8_C(239), UINT8_C( 43) } },
    { { UINT8_C( 68), UINT8_C(176), UINT8_C( 10), UINT8_C(136), UINT8_C(101), UINT8_C( 44), UINT8_C(239), UINT8_C( 95) },
      { UINT8_C( 11), UINT8_C(207), UINT8_C(179), UINT8_C( 50), UINT8_C(198), UINT8_C( 77), UINT8_C(240), UINT8_C(120) },
      { UINT8_C(244), UINT8_C(176), UINT8_C( 78), UINT8_C(205), UINT8_C(125), UINT8_C(190), UINT8_C(239), UINT8_C(223) } },
    { { UINT8_C(167), UINT8_C( 61), UINT8_C(117), UINT8_C(221), UINT8_C( 87), UINT8_C(100), UINT8_C(224), UINT8_C(125) },
      { UINT8_C(234), UINT8_C(171), UINT8_C( 37), UINT8_C( 20), UINT8_C( 29), UINT8_C( 64), UINT8_C(233), UINT8_C( 97) },
      { UINT8_C(183), UINT8_C(125),    UINT8_MAX,    UINT8_MAX, UINT8_C(247),    UINT8_MAX, UINT8_C(246),    UINT8_MAX } },
    { { UINT8_C(241), UINT8_C(243), UINT8_C(234), UINT8_C( 86), UINT8_C( 31), UINT8_C(217), UINT8_C(181), UINT8_C( 43) },
      { UINT8_C(169), UINT8_C(104), UINT8_C( 93), UINT8_C(111), UINT8_C(182), UINT8_C( 77), UINT8_C(231), UINT8_C( 93) },
      { UINT8_C(247), UINT8_C(247), UINT8_C(234), UINT8_C(214), UINT8_C( 95), UINT8_C(251), UINT8_C(189), UINT8_C(171) } },
    { { UINT8_C(139), UINT8_C( 92), UINT8_C( 59), UINT8_C(226), UINT8_C(192), UINT8_C( 27), UINT8_C( 96), UINT8_C(170) },
      { UINT8_C(198), UINT8_C(133), UINT8_C(190), UINT8_C(227), UINT8_C(197), UINT8_C(167), UINT8_C( 69), UINT8_C(182) },
      { UINT8_C(187), UINT8_C(126), UINT8_C(123), UINT8_C(254), UINT8_C(250), UINT8_C( 91), UINT8_C(250), UINT8_C(235) } },
    { { UINT8_C(154), UINT8_C( 47), UINT8_C( 12), UINT8_C(186), UINT8_C(  8), UINT8_C(194), UINT8_C(229), UINT8_C(177) },
      { UINT8_C( 42), UINT8_C( 66), UINT8_C( 32), UINT8_C(224), UINT8_C(144), UINT8_C(  7), UINT8_C( 62), UINT8_C( 27) },
      { UINT8_C(223), UINT8_C(191), UINT8_C(223), UINT8_C(191), UINT8_C(111), UINT8_C(250), UINT8_C(229), UINT8_C(245) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x8_t a = simde_vld1_u8(test_vec[i].a);
    simde_uint8x8_t b = simde_vld1_u8(test_vec[i].b);
    simde_uint8x8_t r = simde_vorn_u8(a, b);

    simde_test_arm_neon_assert_equal_u8x8(r, simde_vld1_u8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8x8_t a = simde_test_arm_neon_random_u8x8();
    simde_uint8x8_t b = simde_test_arm_neon_random_u8x8();
    simde_uint8x8_t r = simde_vorn_u8(a, b);

    simde_test_arm_neon_write_u8x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vorn_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[4];
    uint16_t b[4];
    uint16_t r[4];
  } test_vec[] = {
    { { UINT16_C(31075), UINT16_C( 9213), UINT16_C(23956), UINT16_C(23501) },
      { UINT16_C(35810), UINT16_C(43070), UINT16_C(33586), UINT16_C(52574) },
      { UINT16_C(32127), UINT16_C(30717), UINT16_C(32221), UINT16_C(31725) } },
    { { UINT16_C(27570), UINT16_C(48007), UINT16_C(27693), UINT16_C(22380) },
      { UINT16_C(36270), UINT16_C(15928), UINT16_C(30356), UINT16_C(63577) },
      { UINT16_C(31731), UINT16_C(64455), UINT16_C(60783), UINT16_C(22510) } },
    { { UINT16_C(22511), UINT16_C(33563), UINT16_C(59828), UINT16_C(38878) },
      { UINT16_C( 7540), UINT16_C(42815), UINT16_C(40352), UINT16_C(21364) },
      { UINT16_C(63471), UINT16_C(56283), UINT16_C(60415), UINT16_C(49119) } },
    { { UINT16_C(64264), UINT16_C(13582), UINT16_C(31335), UINT16_C( 5517) },
      { UINT16_C(50439), UINT16_C(40020), UINT16_C(44347), UINT16_C(10900) },
      { UINT16_C(64504), UINT16_C(30639), UINT16_C(31463), UINT16_C(54767) } },
    { { UINT16_C(44804), UINT16_C(47533), UINT16_C(35992), UINT16_C( 3408) },
      { UINT16_C(36777), UINT16_C(18868), UINT16_C(10284), UINT16_C(13724) },
      { UINT16_C(65366), UINT16_C(49135), UINT16_C(57307), UINT16_C(53107) } },
    { { UINT16_C(43555), UINT16_C(35434), UINT16_C(63269), UINT16_C(11423) },
      { UINT16_C(62396), UINT16_C(63432), UINT16_C(23713), UINT16_C(42273) },
      { UINT16_C(44643), UINT16_C(35455), UINT16_C(63359), UINT16_C(32479) } },
    { { UINT16_C(53004), UINT16_C(42078), UINT16_C(44635), UINT16_C( 1201) },
      { UINT16_C(25917), UINT16_C(27213), UINT16_C(60045), UINT16_C(45215) },
      { UINT16_C(57294), UINT16_C(46590), UINT16_C(49019), UINT16_C(20465) } },
    { { UINT16_C( 2452), UINT16_C(47418), UINT16_C(55809), UINT16_C(48614) },
      { UINT16_C(44749), UINT16_C(28341), UINT16_C(54795), UINT16_C( 5908) },
      { UINT16_C(22966), UINT16_C(47482), UINT16_C(64501), UINT16_C(65007) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4_t a = simde_vld1_u16(test_vec[i].a);
    simde_uint16x4_t b = simde_vld1_u16(test_vec[i].b);
    simde_uint16x4_t r = simde_vorn_u16(a, b);

    simde_test_arm_neon_assert_equal_u16x4(r, simde_vld1_u16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x4_t a = simde_test_arm_neon_random_u16x4();
    simde_uint16x4_t b = simde_test_arm_neon_random_u16x4();
    simde_uint16x4_t r = simde_vorn_u16(a, b);

    simde_test_arm_neon_write_u16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vorn_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[2];
    uint32_t b[2];
    uint32_t r[2];
  } test_vec[] = {
    { { UINT32_C(  12284581), UINT32_C(1577348385) },
      { UINT32_C(1623741138), UINT32_C(3490735932) },
      { UINT32_C(2680160173), UINT32_C(2146434531) } },
    { { UINT32_C(1921665905), UINT32_C(4063195173) },
      { UINT32_C( 694281246), UINT32_C(1614837179) },
      { UINT32_C(4137573361), UINT32_C(4290771557) } },
    { { UINT32_C( 140639463), UINT32_C( 996631913) },
      { UINT32_C(4087033783), UINT32_C( 147106967) },
      { UINT32_C( 208010479), UINT32_C(4286543721) } },
    { { UINT32_C( 477777655), UINT32_C(3691948478) },
      { UINT32_C(1225158542), UINT32_C(3433645796) },
      { UINT32_C(3204177655), UINT32_C(4284398015) } },
    { { UINT32_C(2882800194), UINT32_C( 669465456) },
      { UINT32_C(  35357291), UINT32_C( 621469486) },
      { UINT32_C(4294213590), UINT32_C(4294392817) } },
    { { UINT32_C(3946939437), UINT32_C(3150401581) },
      { UINT32_C(2751778239), UINT32_C(1450225172) },
      { UINT32_C(4227577453), UINT32_C(3150926319) } },
    { { UINT32_C( 671237304), UINT32_C(3947948416) },
      { UINT32_C(2599250795), UINT32_C(2009069386) },
      { UINT32_C(1829950652), UINT32_C(3947948469) } },
    { { UINT32_C(2824995195), UINT32_C( 274999633) },
      { UINT32_C( 196372727), UINT32_C(3479249942) },
      { UINT32_C(4234909563), UINT32_C( 822017017) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2_t a = simde_vld1_u32(test_vec[i].a);
    simde_uint32x2_t b = simde_vld1_u32(test_vec[i].b);
    simde_uint32x2_t r = simde_vorn_u32(a, b);

    simde_test_arm_neon_assert_equal_u32x2(r, simde_vld1_u32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x2_t a = simde_test_arm_neon_random_u32x2();
    simde_uint32x2_t b = simde_test_arm_neon_random_u32x2();
    simde_uint32x2_t r = simde_vorn_u32(a, b);

    simde_test_arm_neon_write_u32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vorn_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a[1];
    uint64_t b[1];
    uint64_t r[1];
  } test_vec[] = {
    { { UINT64_C(13318348393709790057) },
      { UINT64_C( 3707326404460986802) },
      { UINT64_C(18220701318975029101) } },
    { { UINT64_C(17758889596753270034) },
      { UINT64_C(13154278172658837672) },
      { UINT64_C(18408111630538757975) } },
    { { UINT64_C( 9208299708435367366) },
      { UINT64_C( 4620674727520443444) },
      { UINT64_C(18440679017576130511) } },
    { { UINT64_C(16337115763932723908) },
      { UINT64_C(16375983374514305600) },
      { UINT64_C(18356067328090701823) } },
    { { UINT64_C( 9943596500732207795) },
      { UINT64_C( 3263865533828004572) },
      { UINT64_C(15852367051336181683) } },
    { { UINT64_C( 5164408348139974543) },
      { UINT64_C( 3198990020481731429) },
      { UINT64_C(15545281906160172959) } },
    { { UINT64_C(17859774302290467579) },
      { UINT64_C( 8339343679508533028) },
      { UINT64_C(18437379651069213435) } },
    { { UINT64_C(13513867989543070779) },
      { UINT64_C( 8275542950167797554) },
      { UINT64_C(13812539912525622527) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x1_t a = simde_vld1_u64(test_vec[i].a);
    simde_uint64x1_t b = simde_vld1_u64(test_vec[i].b);
    simde_uint64x1_t r = simde_vorn_u64(a, b);

    simde_test_arm_neon_assert_equal_u64x1(r, simde_vld1_u64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint64x1_t a = simde_test_arm_neon_random_u64x1();
    simde_uint64x1_t b = simde_test_arm_neon_random_u64x1();
    simde_uint64x1_t r = simde_vorn_u64(a, b);

    simde_test_arm_neon_write_u64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x1(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vornq_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[16];
    int8_t b[16];
    int8_t r[16];
  } test_vec[] = {
    { { -INT8_C(   3), -INT8_C( 124), -INT8_C(  61),  INT8_C(  23),  INT8_C(  47), -INT8_C(  99),  INT8_C(  14),  INT8_C(  83),
        -INT8_C(  20),  INT8_C(  16), -INT8_C(  31), -INT8_C(  48),  INT8_C(  92), -INT8_C( 100),  INT8_C(  67), -INT8_C( 104) },
      {  INT8_C(  72),      INT8_MAX, -INT8_C(  38), -INT8_C(  98),  INT8_C( 102),  INT8_C( 100),  INT8_C(  90), -INT8_C( 103),
        -INT8_C(  61), -INT8_C( 105),  INT8_C(  69),  INT8_C(  59),  INT8_C(  58),  INT8_C(  29), -INT8_C(  83),  INT8_C(  55) },
      { -INT8_C(   1), -INT8_C( 124), -INT8_C(  25),  INT8_C( 119), -INT8_C(  65), -INT8_C(  97), -INT8_C(  81),  INT8_C( 119),
        -INT8_C(   4),  INT8_C( 120), -INT8_C(   5), -INT8_C(  44), -INT8_C(  35), -INT8_C(   2),  INT8_C(  83), -INT8_C(  40) } },
    { { -INT8_C(  94),  INT8_C( 112),  INT8_C(  78), -INT8_C(  47),  INT8_C(  13),  INT8_C(  93),  INT8_C(  36), -INT8_C(   6),
         INT8_C( 109),  INT8_C(   5), -INT8_C(  54), -INT8_C(  55), -INT8_C(  95),  INT8_C(  14),  INT8_C(  97), -INT8_C(  23) },
      { -INT8_C( 115),  INT8_C(  60), -INT8_C( 120), -INT8_C(  12), -INT8_C(  96), -INT8_C(  30), -INT8_C( 115),  INT8_C( 100),
         INT8_C( 121), -INT8_C(  46), -INT8_C(  97), -INT8_C(  77), -INT8_C(  17),  INT8_C(  76), -INT8_C(  22), -INT8_C( 111) },
      { -INT8_C(  14), -INT8_C(  13),      INT8_MAX, -INT8_C(  37),  INT8_C(  95),  INT8_C(  93),  INT8_C( 118), -INT8_C(   5),
        -INT8_C(  17),  INT8_C(  45), -INT8_C(  22), -INT8_C(  51), -INT8_C(  79), -INT8_C(  65),  INT8_C( 117), -INT8_C(  17) } },
    { { -INT8_C(  67),  INT8_C(  57),  INT8_C(  98), -INT8_C(  54), -INT8_C( 106), -INT8_C( 121), -INT8_C(  60),  INT8_C(   3),
        -INT8_C( 116), -INT8_C( 113), -INT8_C(  52),  INT8_C(  46), -INT8_C(  99),  INT8_C(  46),  INT8_C(  23),  INT8_C(  42) },
      {  INT8_C( 106), -INT8_C(  97),  INT8_C(  30),  INT8_C(  10), -INT8_C( 127), -INT8_C(  85),  INT8_C( 110), -INT8_C(   5),
         INT8_C( 125),  INT8_C(  13), -INT8_C(  82),  INT8_C( 109),  INT8_C(  90), -INT8_C( 103), -INT8_C(   2),  INT8_C(  23) },
      { -INT8_C(  67),  INT8_C( 121), -INT8_C(  29), -INT8_C(   1), -INT8_C(   2), -INT8_C(  41), -INT8_C(  43),  INT8_C(   7),
        -INT8_C( 114), -INT8_C(   1), -INT8_C(  35), -INT8_C(  66), -INT8_C(  67),  INT8_C( 110),  INT8_C(  23), -INT8_C(  22) } },
    { { -INT8_C(  46),  INT8_C(  97), -INT8_C(  31),  INT8_C( 104), -INT8_C(  24), -INT8_C(  90),  INT8_C( 107),  INT8_C( 116),
         INT8_C(  53),  INT8_C(  55), -INT8_C(  94), -INT8_C(  46),  INT8_C( 101), -INT8_C(  70), -INT8_C(   4), -INT8_C(  49) },
      {  INT8_C(  89),  INT8_C(  27), -INT8_C(  38), -INT8_C(  37), -INT8_C(  58),  INT8_C(  72), -INT8_C(  42),  INT8_C(  68),
         INT8_C(  86), -INT8_C( 124), -INT8_C(  79), -INT8_C(  80),  INT8_C(  29), -INT8_C(  81), -INT8_C(  57), -INT8_C(  17) },
      { -INT8_C(  10), -INT8_C(  27), -INT8_C(  27),  INT8_C( 108), -INT8_C(   7), -INT8_C(  73),  INT8_C( 107), -INT8_C(   1),
        -INT8_C(  67),      INT8_MAX, -INT8_C(  18), -INT8_C(  33), -INT8_C(  25), -INT8_C(   6), -INT8_C(   4), -INT8_C(  33) } },
    { {  INT8_C(  16), -INT8_C(  88),  INT8_C(  87), -INT8_C(   8),  INT8_C(  78), -INT8_C(  62),  INT8_C( 109), -INT8_C( 125),
        -INT8_C(   6),  INT8_C(  15),  INT8_C(  85),  INT8_C(  95), -INT8_C(  55),  INT8_C(  82),  INT8_C(  47),  INT8_C(  35) },
      {  INT8_C( 109),  INT8_C(   9), -INT8_C(   2),  INT8_C(  51),  INT8_C(  81), -INT8_C(  44),  INT8_C( 119), -INT8_C(  89),
         INT8_C(  88),  INT8_C(  40),  INT8_C(  87),  INT8_C( 118), -INT8_C(  40),  INT8_C(  30),  INT8_C( 101), -INT8_C(  24) },
      { -INT8_C( 110), -INT8_C(   2),  INT8_C(  87), -INT8_C(   4), -INT8_C(  18), -INT8_C(  21), -INT8_C(  19), -INT8_C(  37),
        -INT8_C(   1), -INT8_C(  33), -INT8_C(   3), -INT8_C(  33), -INT8_C(  17), -INT8_C(  13), -INT8_C(  65),  INT8_C(  55) } },
    { { -INT8_C(  57), -INT8_C(  67), -INT8_C(  31),  INT8_C(  21),      INT8_MAX,  INT8_C(  78), -INT8_C( 103),  INT8_C( 121),
         INT8_C(  93), -INT8_C(  18), -INT8_C(  39),  INT8_C(  39),  INT8_C(  64),  INT8_C(   8),  INT8_C(  74), -INT8_C(  83) },
      {  INT8_C(  17),  INT8_C(  72), -INT8_C(  31),  INT8_C(  98),  INT8_C(  28),  INT8_C(  88),  INT8_C(  10),  INT8_C( 116),
        -INT8_C( 127),  INT8_C(  97), -INT8_C(  22),  INT8_C(  89),      INT8_MIN,  INT8_C(  80),  INT8_C(  65),  INT8_C(  71) },
      { -INT8_C(  17), -INT8_C(  65), -INT8_C(   1), -INT8_C(  99), -INT8_C(   1), -INT8_C(  17), -INT8_C(   3), -INT8_C(   5),
             INT8_MAX, -INT8_C(   2), -INT8_C(  35), -INT8_C(  89),      INT8_MAX, -INT8_C(  81), -INT8_C(   2), -INT8_C(  67) } },
    { {  INT8_C(  13),  INT8_C(  34),  INT8_C(  92), -INT8_C( 116),  INT8_C( 112), -INT8_C(  11),  INT8_C(   6), -INT8_C(  50),
        -INT8_C(  28), -INT8_C(  33), -INT8_C(  11),  INT8_C(  36), -INT8_C(  25),  INT8_C(  63), -INT8_C(  46), -INT8_C(   8) },
      { -INT8_C( 121), -INT8_C(  77),  INT8_C(  90), -INT8_C(  93),  INT8_C(  11),  INT8_C( 100),  INT8_C(  23), -INT8_C( 116),
        -INT8_C(  58),  INT8_C(   2), -INT8_C(  27),  INT8_C(  70),  INT8_C(  82),  INT8_C(  39), -INT8_C( 115),  INT8_C(  95) },
      {  INT8_C( 125),  INT8_C( 110), -INT8_C(   3), -INT8_C(  36), -INT8_C(  12), -INT8_C(   1), -INT8_C(  18), -INT8_C(   1),
        -INT8_C(   3), -INT8_C(   1), -INT8_C(   1), -INT8_C(  67), -INT8_C(  17), -INT8_C(   1), -INT8_C(  14), -INT8_C(   8) } },
    { {  INT8_C(  73), -INT8_C(  23), -INT8_C(  21), -INT8_C(  70), -INT8_C(  33), -INT8_C(  15), -INT8_C( 120), -INT8_C(  61),
        -INT8_C(  48),  INT8_C( 125), -INT8_C(  25), -INT8_C(  73), -INT8_C(  68), -INT8_C(  71), -INT8_C(  81),  INT8_C(  67) },
      {  INT8_C( 108),  INT8_C(  10), -INT8_C(  26),  INT8_C( 120),  INT8_C( 110), -INT8_C(   3),  INT8_C(   4),  INT8_C(  52),
        -INT8_C(   1), -INT8_C(  22),  INT8_C( 122),  INT8_C(  81),  INT8_C(  17),  INT8_C(   7), -INT8_C(  80),  INT8_C(  90) },
      { -INT8_C(  37), -INT8_C(   3), -INT8_C(   5), -INT8_C(  65), -INT8_C(  33), -INT8_C(  13), -INT8_C(   5), -INT8_C(  53),
        -INT8_C(  48),  INT8_C( 125), -INT8_C(  25), -INT8_C(  65), -INT8_C(   2), -INT8_C(   7), -INT8_C(  17), -INT8_C(  25) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16_t a = simde_vld1q_s8(test_vec[i].a);
    simde_int8x16_t b = simde_vld1q_s8(test_vec[i].b);
    simde_int8x16_t r = simde_vornq_s8(a, b);

    simde_test_arm_neon_assert_equal_i8x16(r, simde_vld1q_s8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x16_t a = simde_test_arm_neon_random_i8x16();
    simde_int8x16_t b = simde_test_arm_neon_random_i8x16();
    simde_int8x16_t r = simde_vornq_s8(a, b);

    simde_test_arm_neon_write_i8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vornq_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[8];
    int16_t b[8];
    int16_t r[8];
  } test_vec[] = {
    { { -INT16_C( 25359), -INT16_C( 12268), -INT16_C( 25459),  INT16_C( 24211),  INT16_C( 31257), -INT16_C( 10987), -INT16_C( 15052), -INT16_C( 24552) },
      { -INT16_C(   305),  INT16_C( 15640),  INT16_C(  7676), -INT16_C(  1166), -INT16_C(  5113),  INT16_C(  6221), -INT16_C(   524), -INT16_C(  6798) },
      { -INT16_C( 25103), -INT16_C( 11529), -INT16_C(   369),  INT16_C( 24223),  INT16_C( 31737), -INT16_C(  2121), -INT16_C( 14529), -INT16_C( 17763) } },
    { { -INT16_C( 30823),  INT16_C( 10165),  INT16_C( 18467),  INT16_C( 15749), -INT16_C( 25918), -INT16_C(  2542),  INT16_C( 11103),  INT16_C( 11927) },
      { -INT16_C( 20695),  INT16_C(  9580), -INT16_C(  8500), -INT16_C( 11487),  INT16_C( 28362), -INT16_C( 16661),  INT16_C( 24171),  INT16_C(  1443) },
      { -INT16_C( 10273), -INT16_C(    73),  INT16_C( 26931),  INT16_C( 15839), -INT16_C( 25609), -INT16_C(  2282), -INT16_C( 21537), -INT16_C(   289) } },
    { {  INT16_C( 22757),  INT16_C(  2092), -INT16_C( 20064),  INT16_C( 25413),  INT16_C( 22603), -INT16_C( 21671), -INT16_C(  3965), -INT16_C( 21287) },
      {  INT16_C( 17824),  INT16_C( 27858), -INT16_C(  3293), -INT16_C(  4544),  INT16_C( 11105), -INT16_C( 13140),  INT16_C( 20617),  INT16_C( 28369) },
      { -INT16_C(  1281), -INT16_C( 25811), -INT16_C( 16900),  INT16_C( 29695), -INT16_C(  8993), -INT16_C( 17573), -INT16_C(     9), -INT16_C( 16897) } },
    { { -INT16_C(   600),  INT16_C( 18807), -INT16_C( 17234), -INT16_C(  1364),  INT16_C(  1300), -INT16_C( 26715),  INT16_C( 32502), -INT16_C( 27068) },
      {  INT16_C(  5828), -INT16_C(  6398),  INT16_C( 16905),  INT16_C( 27349), -INT16_C( 32146), -INT16_C(  2250),  INT16_C(  2258),  INT16_C( 31334) },
      { -INT16_C(   581),  INT16_C( 23039), -INT16_C( 16898), -INT16_C(    82),  INT16_C( 32149), -INT16_C( 24595), -INT16_C(     1), -INT16_C( 26659) } },
    { { -INT16_C(  8955), -INT16_C( 19261),  INT16_C( 28569), -INT16_C( 20818),  INT16_C( 21365),  INT16_C( 27461), -INT16_C( 30255), -INT16_C( 27391) },
      {  INT16_C(   927), -INT16_C( 22403),  INT16_C( 21062), -INT16_C( 19438),  INT16_C( 18900), -INT16_C( 22869),  INT16_C(  4433),  INT16_C( 22049) },
      { -INT16_C(   667), -INT16_C(  2109), -INT16_C(  4167), -INT16_C(  4113), -INT16_C(  2177),  INT16_C( 31573), -INT16_C(  4097), -INT16_C( 16929) } },
    { { -INT16_C(  6930), -INT16_C( 30710), -INT16_C( 18348), -INT16_C( 14026),  INT16_C( 31499), -INT16_C(  8908),  INT16_C( 13573), -INT16_C( 23438) },
      { -INT16_C(  4296),  INT16_C( 32333),  INT16_C( 24386),  INT16_C(  5682), -INT16_C(  8536), -INT16_C(  1603), -INT16_C(  8465), -INT16_C(  8624) },
      { -INT16_C(  2833), -INT16_C( 30278), -INT16_C( 18179), -INT16_C(  5633),  INT16_C( 31583), -INT16_C(  8330),  INT16_C( 13589), -INT16_C( 23041) } },
    { {  INT16_C( 23234),  INT16_C(  5734), -INT16_C( 25581),  INT16_C(  7903),  INT16_C(  4887),  INT16_C(  7419),  INT16_C( 28232), -INT16_C( 32319) },
      {  INT16_C(  3677), -INT16_C( 24577),  INT16_C( 12909),  INT16_C(  5814),  INT16_C( 29456), -INT16_C(   241),  INT16_C( 24401),  INT16_C(  5085) },
      { -INT16_C(  1054),  INT16_C( 30310), -INT16_C(  8813), -INT16_C(    33), -INT16_C( 24577),  INT16_C(  7419), -INT16_C(  4370), -INT16_C(  4637) } },
    { {  INT16_C( 17338), -INT16_C( 13014),  INT16_C(  2527), -INT16_C(  2069), -INT16_C(  6371),  INT16_C( 25875), -INT16_C( 11179), -INT16_C( 19738) },
      { -INT16_C(  6430),  INT16_C( 20562),  INT16_C(  2072),  INT16_C( 10342),  INT16_C( 30075), -INT16_C( 13273),  INT16_C(  1493), -INT16_C( 28705) },
      {  INT16_C( 23487), -INT16_C(  4177), -INT16_C(     1), -INT16_C(  2053), -INT16_C(  4195),  INT16_C( 30683), -INT16_C(   385), -INT16_C(  3354) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_int16x8_t b = simde_vld1q_s16(test_vec[i].b);
    simde_int16x8_t r = simde_vornq_s16(a, b);

    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x8_t a = simde_test_arm_neon_random_i16x8();
    simde_int16x8_t b = simde_test_arm_neon_random_i16x8();
    simde_int16x8_t r = simde_vornq_s16(a, b);

    simde_test_arm_neon_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vornq_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[4];
    int32_t b[4];
    int32_t r[4];
  } test_vec[] = {
    { {  INT32_C(   677120328),  INT32_C(   807356179), -INT32_C(  2087374290), -INT32_C(   382305273) },
      {  INT32_C(  2050590818),  INT32_C(   195207056), -INT32_C(   354957035),  INT32_C(   393852622) },
      { -INT32_C(  1377927203), -INT32_C(   195074177), -INT32_C(  1749207314), -INT32_C(   373916361) } },
    { { -INT32_C(   750791232),  INT32_C(  1258511900), -INT32_C(  1748068208),  INT32_C(  1988166676) },
      {  INT32_C(   485538444),  INT32_C(  1864864346),  INT32_C(   710540892),  INT32_C(  1967248053) },
      { -INT32_C(   213920269), -INT32_C(   606371907), -INT32_C(   672228941), -INT32_C(    21025442) } },
    { { -INT32_C(  1018658649),  INT32_C(  1863207902), -INT32_C(   133767709),  INT32_C(  1852737505) },
      { -INT32_C(  1668653246),  INT32_C(  1292612337),  INT32_C(  1702388912), -INT32_C(   572868298) },
      { -INT32_C(   478306113), -INT32_C(      110626), -INT32_C(    91758609),  INT32_C(  1852819433) } },
    { {  INT32_C(   413147706),  INT32_C(  1367846765),  INT32_C(  1833537164),  INT32_C(  1474017045) },
      {  INT32_C(   150169110), -INT32_C(   933888488), -INT32_C(  1741763230), -INT32_C(  1049294713) },
      { -INT32_C(     5456901),  INT32_C(  2008002543),  INT32_C(  1876541085),  INT32_C(  2145122173) } },
    { { -INT32_C(  1730603477),  INT32_C(  1374249413),  INT32_C(    79573743),  INT32_C(     6068970) },
      {  INT32_C(   403197696), -INT32_C(  1327473074), -INT32_C(  1303835093),  INT32_C(  1114881559) },
      { -INT32_C(       18689),  INT32_C(  1610605045),  INT32_C(  1304359935), -INT32_C(  1109599254) } },
    { { -INT32_C(  1713746476), -INT32_C(  1645558610), -INT32_C(   526276106),  INT32_C(  1138883907) },
      { -INT32_C(  1688475315),  INT32_C(  1934310215),  INT32_C(  1629852746),  INT32_C(   665033043) },
      { -INT32_C(    33660938), -INT32_C(  1644247874), -INT32_C(    17044489), -INT32_C(   604110865) } },
    { { -INT32_C(  1799258650),  INT32_C(   942779201), -INT32_C(  1759980972),  INT32_C(   500890064) },
      {  INT32_C(   716715491), -INT32_C(  1147337871), -INT32_C(   350436456),  INT32_C(  1108524892) },
      { -INT32_C(   708313090),  INT32_C(  2087976911), -INT32_C(  1745093001), -INT32_C(  1107297805) } },
    { {  INT32_C(  2128007996), -INT32_C(   743045249), -INT32_C(  1452552487), -INT32_C(  1413069368) },
      { -INT32_C(   321552773),  INT32_C(   447181698), -INT32_C(  1845116106), -INT32_C(  1093396606) },
      {  INT32_C(  2147406780), -INT32_C(   134312065), -INT32_C(   302252327), -INT32_C(   336597507) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int32x4_t b = simde_vld1q_s32(test_vec[i].b);
    simde_int32x4_t r = simde_vornq_s32(a, b);

    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x4_t a = simde_test_arm_neon_random_i32x4();
    simde_int32x4_t b = simde_test_arm_neon_random_i32x4();
    simde_int32x4_t r = simde_vornq_s32(a, b);

    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vornq_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a[2];
    int64_t b[2];
    int64_t r[2];
  } test_vec[] = {
    { { -INT64_C( 8485359279090652437),  INT64_C( 7580959975182477505) },
      { -INT64_C( 5614303746724656775),  INT64_C( 2089415351950645951) },
      { -INT64_C( 3458778036814545169), -INT64_C( 1498291375123206719) } },
    { { -INT64_C( 1153268750774551358), -INT64_C( 6502164130496499092) },
      { -INT64_C( 3177934863686690634),  INT64_C(  296415424194816463) },
      { -INT64_C( 1153256924374892597), -INT64_C(    7899175018826116) } },
    { { -INT64_C( 3139441699060145072),  INT64_C( 5294811028661462696) },
      { -INT64_C( 6921081755340695029),  INT64_C( 7768918383820539786) },
      { -INT64_C(  833448024532523532), -INT64_C( 2486000222950392067) } },
    { {  INT64_C( 7394445214660315234), -INT64_C( 3811534294866997954) },
      { -INT64_C( 9205395062007359793), -INT64_C(   41625736401068059) },
      {  INT64_C( 9213936852346562930), -INT64_C( 3775151308294853314) } },
    { { -INT64_C( 1402193236821715355),  INT64_C( 5386543176955643189) },
      {  INT64_C( 7918780086091361134), -INT64_C( 5429693740112530936) },
      { -INT64_C(  100486567778363659),  INT64_C( 5465960352241929719) } },
    { {  INT64_C(  921658848263564848), -INT64_C( 3463898813775640536) },
      {  INT64_C(  532298867592713837), -INT64_C( 2643804658750140084) },
      { -INT64_C(  225488021274005582), -INT64_C( 1153503739377373509) } },
    { { -INT64_C( 5502691159140915008), -INT64_C( 3225629125903997940) },
      { -INT64_C( 2945306279867289318), -INT64_C( 2413154112914666244) },
      { -INT64_C( 4899960375199420699), -INT64_C(  901423718178244849) } },
    { { -INT64_C( 3807767373881787415), -INT64_C( 2525265113918177605) },
      { -INT64_C( 1997603821643776795),  INT64_C( 7267981299377027553) },
      { -INT64_C( 2614058383598257157), -INT64_C( 2308387527666729281) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);
    simde_int64x2_t b = simde_vld1q_s64(test_vec[i].b);
    simde_int64x2_t r = simde_vornq_s64(a, b);

    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int64x2_t a = simde_test_arm_neon_random_i64x2();
    simde_int64x2_t b = simde_test_arm_neon_random_i64x2();
    simde_int64x2_t r = simde_vornq_s64(a, b);

    simde_test_arm_neon_write_i64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vornq_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t a[16];
    uint8_t b[16];
    uint8_t r[16];
  } test_vec[] = {
    { { UINT8_C(167), UINT8_C( 77), UINT8_C( 14),    UINT8_MAX, UINT8_C(136), UINT8_C( 28), UINT8_C(151), UINT8_C( 36),
        UINT8_C( 23), UINT8_C( 41), UINT8_C( 21), UINT8_C(245), UINT8_C(241), UINT8_C( 71), UINT8_C(105), UINT8_C( 50) },
      { UINT8_C(200), UINT8_C(232), UINT8_C( 25), UINT8_C( 33), UINT8_C(236), UINT8_C( 98), UINT8_C(210), UINT8_C(206),
        UINT8_C(228), UINT8_C(213), UINT8_C(147), UINT8_C(252), UINT8_C(137), UINT8_C(209), UINT8_C( 39), UINT8_C( 48) },
      { UINT8_C(183), UINT8_C( 95), UINT8_C(238),    UINT8_MAX, UINT8_C(155), UINT8_C(157), UINT8_C(191), UINT8_C( 53),
        UINT8_C( 31), UINT8_C( 43), UINT8_C(125), UINT8_C(247), UINT8_C(247), UINT8_C(111), UINT8_C(249),    UINT8_MAX } },
    { { UINT8_C( 30), UINT8_C( 54), UINT8_C( 47), UINT8_C(167), UINT8_C( 82), UINT8_C(199), UINT8_C(203), UINT8_C(106),
        UINT8_C(240), UINT8_C(224), UINT8_C( 95), UINT8_C(225), UINT8_C( 39), UINT8_C(200), UINT8_C( 19), UINT8_C(240) },
      { UINT8_C(176), UINT8_C( 45), UINT8_C( 17), UINT8_C(157), UINT8_C(143), UINT8_C(227), UINT8_C(107), UINT8_C(115),
        UINT8_C(184), UINT8_C(254), UINT8_C(112), UINT8_C( 65), UINT8_C(207), UINT8_C(151), UINT8_C(113), UINT8_C(238) },
      { UINT8_C( 95), UINT8_C(246), UINT8_C(239), UINT8_C(231), UINT8_C(114), UINT8_C(223), UINT8_C(223), UINT8_C(238),
        UINT8_C(247), UINT8_C(225), UINT8_C(223),    UINT8_MAX, UINT8_C( 55), UINT8_C(232), UINT8_C(159), UINT8_C(241) } },
    { { UINT8_C(205), UINT8_C(161), UINT8_C(149), UINT8_C( 32), UINT8_C(104), UINT8_C( 96), UINT8_C(138), UINT8_C( 88),
        UINT8_C( 64), UINT8_C(233), UINT8_C( 57), UINT8_C(104), UINT8_C(177), UINT8_C( 76), UINT8_C( 88), UINT8_C( 98) },
      { UINT8_C(121), UINT8_C(105),    UINT8_MAX, UINT8_C(  9), UINT8_C( 76), UINT8_C(106), UINT8_C(124), UINT8_C(  5),
        UINT8_C(105), UINT8_C(236), UINT8_C( 70), UINT8_C( 56), UINT8_C(132), UINT8_C(184), UINT8_C( 38), UINT8_C( 81) },
      { UINT8_C(207), UINT8_C(183), UINT8_C(149), UINT8_C(246), UINT8_C(251), UINT8_C(245), UINT8_C(139), UINT8_C(250),
        UINT8_C(214), UINT8_C(251), UINT8_C(185), UINT8_C(239), UINT8_C(251), UINT8_C( 79), UINT8_C(217), UINT8_C(238) } },
    { { UINT8_C( 89), UINT8_C(187), UINT8_C(113), UINT8_C(193), UINT8_C( 27), UINT8_C(251), UINT8_C( 25), UINT8_C( 92),
        UINT8_C(228), UINT8_C( 82), UINT8_C(196), UINT8_C(150), UINT8_C(158), UINT8_C( 28), UINT8_C(248), UINT8_C( 24) },
      { UINT8_C(133), UINT8_C(247), UINT8_C( 33), UINT8_C(209), UINT8_C( 97), UINT8_C(157), UINT8_C(214), UINT8_C(202),
        UINT8_C(138), UINT8_C( 29), UINT8_C(  3), UINT8_C( 14), UINT8_C(213), UINT8_C( 41), UINT8_C( 95), UINT8_C( 46) },
      { UINT8_C(123), UINT8_C(187),    UINT8_MAX, UINT8_C(239), UINT8_C(159), UINT8_C(251), UINT8_C( 57), UINT8_C(125),
        UINT8_C(245), UINT8_C(242), UINT8_C(252), UINT8_C(247), UINT8_C(190), UINT8_C(222), UINT8_C(248), UINT8_C(217) } },
    { { UINT8_C(229), UINT8_C(209), UINT8_C(239), UINT8_C(  0), UINT8_C(204), UINT8_C(  8), UINT8_C( 92), UINT8_C(177),
        UINT8_C( 90), UINT8_C( 32), UINT8_C( 71), UINT8_C(248), UINT8_C( 60), UINT8_C( 63), UINT8_C( 16), UINT8_C(193) },
      { UINT8_C( 54), UINT8_C( 49), UINT8_C(147), UINT8_C(151), UINT8_C(207), UINT8_C(105), UINT8_C( 98), UINT8_C( 89),
        UINT8_C(134), UINT8_C(101), UINT8_C(103), UINT8_C( 91), UINT8_C(142), UINT8_C(198), UINT8_C(137), UINT8_C(115) },
      { UINT8_C(237), UINT8_C(223), UINT8_C(239), UINT8_C(104), UINT8_C(252), UINT8_C(158), UINT8_C(221), UINT8_C(183),
        UINT8_C(123), UINT8_C(186), UINT8_C(223), UINT8_C(252), UINT8_C(125), UINT8_C( 63), UINT8_C(118), UINT8_C(205) } },
    { { UINT8_C(151), UINT8_C(120), UINT8_C(116), UINT8_C(100), UINT8_C(128), UINT8_C(208), UINT8_C( 21), UINT8_C(218),
        UINT8_C(241), UINT8_C( 92), UINT8_C(211), UINT8_C( 45), UINT8_C(155), UINT8_C(227), UINT8_C(239), UINT8_C(209) },
      { UINT8_C( 21), UINT8_C(130), UINT8_C(104), UINT8_C(228), UINT8_C(235), UINT8_C(202), UINT8_C( 61), UINT8_C(114),
        UINT8_C( 47), UINT8_C(164), UINT8_C(205), UINT8_C(190), UINT8_C(106), UINT8_C( 87), UINT8_C( 49), UINT8_C(  2) },
      {    UINT8_MAX, UINT8_C(125), UINT8_C(247), UINT8_C(127), UINT8_C(148), UINT8_C(245), UINT8_C(215), UINT8_C(223),
        UINT8_C(241), UINT8_C( 95), UINT8_C(243), UINT8_C(109), UINT8_C(159), UINT8_C(235), UINT8_C(239), UINT8_C(253) } },
    { { UINT8_C(207), UINT8_C(165), UINT8_C(102), UINT8_C( 80), UINT8_C(118), UINT8_C(123), UINT8_C( 42), UINT8_C(103),
        UINT8_C(215), UINT8_C(253), UINT8_C(148), UINT8_C(114), UINT8_C(225), UINT8_C(131), UINT8_C( 67), UINT8_C(246) },
      { UINT8_C(  5), UINT8_C(171), UINT8_C(218), UINT8_C(241), UINT8_C(118), UINT8_C( 23), UINT8_C( 99), UINT8_C(165),
        UINT8_C(187), UINT8_C( 48), UINT8_C( 99), UINT8_C( 37), UINT8_C(135), UINT8_C(149), UINT8_C( 39), UINT8_C( 87) },
      {    UINT8_MAX, UINT8_C(245), UINT8_C(103), UINT8_C( 94),    UINT8_MAX, UINT8_C(251), UINT8_C(190), UINT8_C(127),
        UINT8_C(215),    UINT8_MAX, UINT8_C(156), UINT8_C(250), UINT8_C(249), UINT8_C(235), UINT8_C(219), UINT8_C(254) } },
    { { UINT8_C( 58), UINT8_C(141), UINT8_C(167), UINT8_C(176), UINT8_C(  8), UINT8_C(209), UINT8_C( 23), UINT8_C(223),
        UINT8_C(207), UINT8_C(172), UINT8_C( 81), UINT8_C(176), UINT8_C( 47), UINT8_C(148), UINT8_C(166), UINT8_C( 53) },
      { UINT8_C( 64), UINT8_C(128), UINT8_C( 38), UINT8_C(182), UINT8_C(151), UINT8_C(137), UINT8_C( 91), UINT8_C( 82),
        UINT8_C(185), UINT8_C(191), UINT8_C(119), UINT8_C( 65), UINT8_C( 84), UINT8_C(159), UINT8_C(152), UINT8_C(142) },
      { UINT8_C(191),    UINT8_MAX,    UINT8_MAX, UINT8_C(249), UINT8_C(104), UINT8_C(247), UINT8_C(183),    UINT8_MAX,
        UINT8_C(207), UINT8_C(236), UINT8_C(217), UINT8_C(190), UINT8_C(175), UINT8_C(244), UINT8_C(231), UINT8_C(117) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x16_t a = simde_vld1q_u8(test_vec[i].a);
    simde_uint8x16_t b = simde_vld1q_u8(test_vec[i].b);
    simde_uint8x16_t r = simde_vornq_u8(a, b);

    simde_test_arm_neon_assert_equal_u8x16(r, simde_vld1q_u8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8x16_t a = simde_test_arm_neon_random_u8x16();
    simde_uint8x16_t b = simde_test_arm_neon_random_u8x16();
    simde_uint8x16_t r = simde_vornq_u8(a, b);

    simde_test_arm_neon_write_u8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vornq_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[8];
    uint16_t b[8];
    uint16_t r[8];
  } test_vec[] = {
    { { UINT16_C(16172), UINT16_C(13631), UINT16_C(22032), UINT16_C(57108), UINT16_C(26114), UINT16_C(12943), UINT16_C(13818), UINT16_C(14951) },
      { UINT16_C(36277), UINT16_C(19696), UINT16_C(19478), UINT16_C(53150), UINT16_C( 5643), UINT16_C(24336), UINT16_C(43189), UINT16_C(57837) },
      { UINT16_C(32622), UINT16_C(46911), UINT16_C(63481), UINT16_C(65397), UINT16_C(61430), UINT16_C(45807), UINT16_C(30714), UINT16_C(15991) } },
    { { UINT16_C(11495), UINT16_C(63510), UINT16_C(11139), UINT16_C(34263), UINT16_C(26513), UINT16_C(35767), UINT16_C( 7836), UINT16_C(21190) },
      { UINT16_C(46763), UINT16_C(49566), UINT16_C(15618), UINT16_C( 3473), UINT16_C(41299), UINT16_C( 2156), UINT16_C(23114), UINT16_C(12777) },
      { UINT16_C(28151), UINT16_C(65143), UINT16_C(60415), UINT16_C(63487), UINT16_C(32701), UINT16_C(65463), UINT16_C(49085), UINT16_C(57046) } },
    { { UINT16_C(  134), UINT16_C( 2345), UINT16_C(  299), UINT16_C(48271), UINT16_C(18024), UINT16_C( 1095), UINT16_C( 3429), UINT16_C( 4182) },
      { UINT16_C(62916), UINT16_C(50898), UINT16_C(25394), UINT16_C(34260), UINT16_C(16388), UINT16_C(20109), UINT16_C(30362), UINT16_C( 8576) },
      { UINT16_C( 2751), UINT16_C(14637), UINT16_C(40431), UINT16_C(65199), UINT16_C(65531), UINT16_C(46455), UINT16_C(36197), UINT16_C(56959) } },
    { { UINT16_C(43382), UINT16_C(41258), UINT16_C(47530), UINT16_C( 4701), UINT16_C(42240), UINT16_C(25879), UINT16_C(28082), UINT16_C(30325) },
      { UINT16_C(18274), UINT16_C(37949), UINT16_C( 4522), UINT16_C(44825), UINT16_C(42577), UINT16_C(60669), UINT16_C(32029), UINT16_C(37645) },
      { UINT16_C(47615), UINT16_C(60394),      UINT16_MAX, UINT16_C(21247), UINT16_C(64942), UINT16_C(30487), UINT16_C(61426), UINT16_C(32503) } },
    { { UINT16_C(14119), UINT16_C(53557), UINT16_C(37617), UINT16_C(61924), UINT16_C(64311), UINT16_C(59990), UINT16_C(52072), UINT16_C(52064) },
      { UINT16_C(40211), UINT16_C(48479), UINT16_C(31150), UINT16_C(  108), UINT16_C(27167), UINT16_C(15596), UINT16_C(63975), UINT16_C( 3792) },
      { UINT16_C(30703), UINT16_C(54197), UINT16_C(38641), UINT16_C(65527), UINT16_C(65527), UINT16_C(60247), UINT16_C(53112), UINT16_C(64367) } },
    { { UINT16_C( 1328), UINT16_C( 8672), UINT16_C(50327), UINT16_C(53010), UINT16_C(26815), UINT16_C(10169), UINT16_C( 6452), UINT16_C(18418) },
      { UINT16_C(21175), UINT16_C(25860), UINT16_C(29131), UINT16_C(60005), UINT16_C(20955), UINT16_C(49703), UINT16_C(63306), UINT16_C(31697) },
      { UINT16_C(44408), UINT16_C(48123), UINT16_C(52919), UINT16_C(57242), UINT16_C(61119), UINT16_C(16377), UINT16_C( 6581), UINT16_C(51198) } },
    { { UINT16_C(45564), UINT16_C(37788), UINT16_C(44917), UINT16_C(13410), UINT16_C( 6935), UINT16_C(19291), UINT16_C(20021), UINT16_C(60562) },
      { UINT16_C(38816), UINT16_C(27473), UINT16_C(46856), UINT16_C(58197), UINT16_C(31752), UINT16_C(21413), UINT16_C(30323), UINT16_C(28622) },
      { UINT16_C(63999), UINT16_C(38846), UINT16_C(61431), UINT16_C(15594), UINT16_C(39927), UINT16_C(61275), UINT16_C(53181), UINT16_C(64691) } },
    { { UINT16_C(27175), UINT16_C(39939), UINT16_C(25881), UINT16_C(12752), UINT16_C(11393), UINT16_C(46716), UINT16_C( 3962), UINT16_C( 6818) },
      { UINT16_C(62374), UINT16_C(44677), UINT16_C(55978), UINT16_C(45969), UINT16_C(13911), UINT16_C(51718), UINT16_C(54445), UINT16_C(54330) },
      { UINT16_C(28287), UINT16_C(56699), UINT16_C(25949), UINT16_C(32254), UINT16_C(60841), UINT16_C(47101), UINT16_C(12154), UINT16_C(15335) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);
    simde_uint16x8_t b = simde_vld1q_u16(test_vec[i].b);
    simde_uint16x8_t r = simde_vornq_u16(a, b);

    simde_test_arm_neon_assert_equal_u16x8(r, simde_vld1q_u16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x8_t a = simde_test_arm_neon_random_u16x8();
    simde_uint16x8_t b = simde_test_arm_neon_random_u16x8();
    simde_uint16x8_t r = simde_vornq_u16(a, b);

    simde_test_arm_neon_write_u16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vornq_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[4];
    uint32_t b[4];
    uint32_t r[4];
  } test_vec[] = {
    { { UINT32_C(1483816254), UINT32_C( 596197794), UINT32_C(3889759597), UINT32_C(3120659220) },
      { UINT32_C( 426280559), UINT32_C(3100440929), UINT32_C(3716338224), UINT32_C(3853630630) },
      { UINT32_C(4277632446), UINT32_C(1740326846), UINT32_C(3892129263), UINT32_C(3125771101) } },
    { { UINT32_C(2621252345), UINT32_C(3519006308), UINT32_C(3770259915), UINT32_C(2207955476) },
      { UINT32_C(2728198977), UINT32_C( 744122876), UINT32_C(3792297020), UINT32_C(2462563225) },
      { UINT32_C(3716153087), UINT32_C(3552564839), UINT32_C(4261395403), UINT32_C(4022009462) } },
    { { UINT32_C(1093534941), UINT32_C(2517888714), UINT32_C(2608254087), UINT32_C(3340701830) },
      { UINT32_C( 275364883), UINT32_C(1631372069), UINT32_C( 960775840), UINT32_C(3737848577) },
      { UINT32_C(4022224893), UINT32_C(2664693466), UINT32_C(3758095839), UINT32_C(3879728382) } },
    { { UINT32_C(3659594256), UINT32_C(1869624296), UINT32_C(2232084223), UINT32_C( 172829175) },
      { UINT32_C( 186300133), UINT32_C( 443307898), UINT32_C(2656284829), UINT32_C(3430686396) },
      { UINT32_C(4276484890), UINT32_C(4025727981), UINT32_C(3853447167), UINT32_C(1003481591) } },
    { { UINT32_C(  10918936), UINT32_C(3463387087), UINT32_C(4099177213), UINT32_C(2315231651) },
      { UINT32_C(3516143959), UINT32_C( 233504880), UINT32_C(1839939249), UINT32_C(1966680157) },
      { UINT32_C( 787480248), UINT32_C(4269801423), UINT32_C(4132764671), UINT32_C(2348808099) } },
    { { UINT32_C(2490818500), UINT32_C(4100122102), UINT32_C(  65582687), UINT32_C(2945247063) },
      { UINT32_C(1904222209), UINT32_C(3514788896), UINT32_C( 121514666), UINT32_C( 394098514) },
      { UINT32_C(2659180542), UINT32_C(4276287487), UINT32_C(4226414431), UINT32_C(4019122175) } },
    { { UINT32_C(1303114583), UINT32_C( 943787480), UINT32_C( 456862404), UINT32_C( 315279121) },
      { UINT32_C( 126110695), UINT32_C(1641612215), UINT32_C(2154370861), UINT32_C(3868714639) },
      { UINT32_C(4261148511), UINT32_C(3194486232), UINT32_C(2143283926), UINT32_C( 468377457) } },
    { { UINT32_C(2972926681), UINT32_C( 334067023), UINT32_C(2955879583), UINT32_C(3536058859) },
      { UINT32_C(4225386308), UINT32_C(2002629450), UINT32_C(1509410506), UINT32_C(2235535020) },
      { UINT32_C(3040344827), UINT32_C(2615901695), UINT32_C(3056549311), UINT32_C(4207147515) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint32x4_t b = simde_vld1q_u32(test_vec[i].b);
    simde_uint32x4_t r = simde_vornq_u32(a, b);

    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x4_t a = simde_test_arm_neon_random_u32x4();
    simde_uint32x4_t b = simde_test_arm_neon_random_u32x4();
    simde_uint32x4_t r = simde_vornq_u32(a, b);

    simde_test_arm_neon_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vornq_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a[2];
    uint64_t b[2];
    uint64_t r[2];
  } test_vec[] = {
    { { UINT64_C( 9742166600277455824), UINT64_C(11530053269874762308) },
      { UINT64_C( 6486302283261598785), UINT64_C( 6480947635329170111) },
      { UINT64_C(12105437171942913022), UINT64_C(11966062555094280004) } },
    { { UINT64_C(10076150258787231334), UINT64_C( 5191732310021180431) },
      { UINT64_C( 6954639336781686938), UINT64_C(10427164827855828945) },
      { UINT64_C(11528561244109502311), UINT64_C( 8020908565252262959) } },
    { { UINT64_C(16912058775276236257), UINT64_C(14199674990761438911) },
      { UINT64_C(10018946467096421129), UINT64_C( 8242601689839228329) },
      { UINT64_C(18372364171491556855), UINT64_C(14816672830487097087) } },
    { { UINT64_C(13009859136661897671), UINT64_C( 5524941767599382971) },
      { UINT64_C(13236643410795273068), UINT64_C(18003682885643180247) },
      { UINT64_C(18216497504031761879), UINT64_C( 5669638099513108411) } },
    { { UINT64_C( 8923926367836009263), UINT64_C( 5230947306527937033) },
      { UINT64_C( 7524707462120705961), UINT64_C( 1577572578750363833) },
      { UINT64_C(18436329424100750207), UINT64_C(16905209931097069391) } },
    { { UINT64_C(12706925761294598172), UINT64_C( 8180953410434808420) },
      { UINT64_C(15068363861602662180), UINT64_C(12864991478119460237) },
      { UINT64_C(13761447847209699551), UINT64_C( 9078940094085184118) } },
    { { UINT64_C( 4069539738901529121), UINT64_C( 3448631459411686818) },
      { UINT64_C( 2873862372947395832), UINT64_C( 6933050006603276015) },
      { UINT64_C(17905746926224014119), UINT64_C(13825166618822210994) } },
    { { UINT64_C( 5904960937062418406), UINT64_C( 7156669968291752471) },
      { UINT64_C( 2765022391870633373), UINT64_C(  330138391560321780) },
      { UINT64_C(15704802798273941478), UINT64_C(18121251162307718943) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x2_t a = simde_vld1q_u64(test_vec[i].a);
    simde_uint64x2_t b = simde_vld1q_u64(test_vec[i].b);
    simde_uint64x2_t r = simde_vornq_u64(a, b);

    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint64x2_t a = simde_test_arm_neon_random_u64x2();
    simde_uint64x2_t b = simde_test_arm_neon_random_u64x2();
    simde_uint64x2_t r = simde_vornq_u64(a, b);

    simde_test_arm_neon_write_u64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vorn_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vorn_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vorn_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vorn_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vorn_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vorn_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vorn_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vorn_u64)

SIMDE_TEST_FUNC_LIST_ENTRY(vornq_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vornq_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vornq_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vornq_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vornq_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vornq_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vornq_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vornq_u64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
