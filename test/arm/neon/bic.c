#define SIMDE_TEST_ARM_NEON_INSN bic

#include "test-neon.h"
#include "../../../simde/arm/neon/bic.h"

static int
test_simde_vbic_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[8];
    int8_t b[8];
    int8_t r[8];
  } test_vec[] = {
    { { -INT8_C(  62),  INT8_C(   9),  INT8_C( 113),  INT8_C( 100), -INT8_C(  96), -INT8_C(  44),  INT8_C(  44), -INT8_C(  52) },
      { -INT8_C(  99), -INT8_C(  76),  INT8_C(  33), -INT8_C(  61), -INT8_C(  16), -INT8_C(  42),  INT8_C(  93),  INT8_C(  44) },
      {  INT8_C(  66),  INT8_C(   9),  INT8_C(  80),  INT8_C(  36),  INT8_C(   0),  INT8_C(   0),  INT8_C(  32), -INT8_C(  64) } },
    { {  INT8_C(   1), -INT8_C( 113),  INT8_C(  51), -INT8_C(   4), -INT8_C(  32),  INT8_C(  91),  INT8_C(  93), -INT8_C( 121) },
      {  INT8_C(  52),  INT8_C(  72),  INT8_C(  55), -INT8_C(  13), -INT8_C( 124),  INT8_C(  83), -INT8_C(  76),  INT8_C(  70) },
      {  INT8_C(   1), -INT8_C( 121),  INT8_C(   0),  INT8_C(  12),  INT8_C(  96),  INT8_C(   8),  INT8_C(  73), -INT8_C( 127) } },
    { {  INT8_C(  92),  INT8_C(  37), -INT8_C(  85), -INT8_C(   3), -INT8_C(   6), -INT8_C(  41), -INT8_C(  55), -INT8_C( 105) },
      { -INT8_C( 117), -INT8_C(  22),  INT8_C(  91),  INT8_C( 123), -INT8_C(  64), -INT8_C(  72), -INT8_C(  89), -INT8_C(  63) },
      {  INT8_C(  84),  INT8_C(   5), -INT8_C(  96), -INT8_C( 124),  INT8_C(  58),  INT8_C(  71),  INT8_C(  72),  INT8_C(  22) } },
    { {  INT8_C(  71), -INT8_C(  38), -INT8_C(  66),  INT8_C(  39),  INT8_C(  54),  INT8_C(  27), -INT8_C(  81),  INT8_C( 106) },
      {  INT8_C(  99), -INT8_C(  26),  INT8_C(  93), -INT8_C(  25),  INT8_C(  58),  INT8_C(  18),  INT8_C(  45), -INT8_C( 106) },
      {  INT8_C(   4),  INT8_C(  24), -INT8_C(  94),  INT8_C(   0),  INT8_C(   4),  INT8_C(   9), -INT8_C( 126),  INT8_C( 104) } },
    { {  INT8_C(  55), -INT8_C(  40), -INT8_C( 109),  INT8_C(  49), -INT8_C(  81),  INT8_C(  92), -INT8_C(  55),  INT8_C(  58) },
      {  INT8_C(  71),  INT8_C(  36), -INT8_C(  75),  INT8_C(   7), -INT8_C(  36),  INT8_C(  93), -INT8_C(  55),  INT8_C(  36) },
      {  INT8_C(  48), -INT8_C(  40),  INT8_C(   2),  INT8_C(  48),  INT8_C(  35),  INT8_C(   0),  INT8_C(   0),  INT8_C(  26) } },
    { {  INT8_C(  55), -INT8_C( 121),  INT8_C(  75),  INT8_C( 109), -INT8_C(  94), -INT8_C(   6), -INT8_C(  40),  INT8_C(   5) },
      { -INT8_C(  31),  INT8_C(  53), -INT8_C(  20),  INT8_C(  27),  INT8_C(  71),  INT8_C(  25), -INT8_C(  79),      INT8_MAX },
      {  INT8_C(  22), -INT8_C( 126),  INT8_C(   3),  INT8_C( 100), -INT8_C(  96), -INT8_C(  30),  INT8_C(  72),  INT8_C(   0) } },
    { { -INT8_C(  14),  INT8_C(  69), -INT8_C(  80), -INT8_C(  95), -INT8_C(  95),  INT8_C( 121), -INT8_C(  36), -INT8_C(  24) },
      { -INT8_C(  99), -INT8_C( 111), -INT8_C(  16),  INT8_C( 122), -INT8_C(  18), -INT8_C(  71), -INT8_C(  98),  INT8_C(  38) },
      {  INT8_C(  98),  INT8_C(  68),  INT8_C(   0), -INT8_C( 127),  INT8_C(   1),  INT8_C(  64),  INT8_C(  64), -INT8_C(  56) } },
    { {  INT8_C(  64), -INT8_C(  23), -INT8_C( 109), -INT8_C(  30), -INT8_C(  28),  INT8_C( 107), -INT8_C(  25), -INT8_C(  59) },
      { -INT8_C(  95), -INT8_C(  45), -INT8_C(  32), -INT8_C(  24), -INT8_C(  20), -INT8_C( 111),  INT8_C( 103), -INT8_C(  34) },
      {  INT8_C(  64),  INT8_C(  40),  INT8_C(  19),  INT8_C(   2),  INT8_C(   0),  INT8_C( 106),      INT8_MIN,  INT8_C(   1) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8_t a = simde_vld1_s8(test_vec[i].a);
    simde_int8x8_t b = simde_vld1_s8(test_vec[i].b);
    simde_int8x8_t r = simde_vbic_s8(a, b);

    simde_test_arm_neon_assert_equal_i8x8(r, simde_vld1_s8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x8_t a = simde_test_arm_neon_random_i8x8();
    simde_int8x8_t b = simde_test_arm_neon_random_i8x8();
    simde_int8x8_t r = simde_vbic_s8(a, b);

    simde_test_arm_neon_write_i8x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vbic_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[4];
    int16_t b[4];
    int16_t r[4];
  } test_vec[] = {
    { {  INT16_C( 18838), -INT16_C(  1368), -INT16_C(  3988), -INT16_C( 30957) },
      { -INT16_C( 22454),  INT16_C( 21529),  INT16_C( 11667),  INT16_C( 21102) },
      {  INT16_C( 16788), -INT16_C( 21856), -INT16_C( 12180), -INT16_C( 31471) } },
    { {  INT16_C(  2977), -INT16_C( 11559),  INT16_C(  6524), -INT16_C( 19665) },
      { -INT16_C( 26774),  INT16_C(  5880),  INT16_C( 11737),  INT16_C( 28443) },
      {  INT16_C(  2177), -INT16_C( 16383),  INT16_C(  4132), -INT16_C( 28636) } },
    { { -INT16_C( 15498), -INT16_C(  7575),  INT16_C( 32180), -INT16_C(   406) },
      { -INT16_C( 31963), -INT16_C( 18349), -INT16_C( 15952),  INT16_C( 20746) },
      {  INT16_C( 16466),  INT16_C( 16936),  INT16_C( 15364), -INT16_C( 20896) } },
    { { -INT16_C(  7219),  INT16_C( 18723),  INT16_C( 21244),  INT16_C( 26620) },
      { -INT16_C(  2583), -INT16_C( 15747), -INT16_C( 26590), -INT16_C( 26575) },
      {  INT16_C(   516),  INT16_C(  2306),  INT16_C( 17116),  INT16_C( 26572) } },
    { { -INT16_C( 25764),  INT16_C(  4219), -INT16_C(  6888),  INT16_C( 15630) },
      {  INT16_C( 24936),  INT16_C(  6389),  INT16_C(    35), -INT16_C(  3991) },
      { -INT16_C( 26092),  INT16_C(    10), -INT16_C(  6888),  INT16_C(  3334) } },
    { { -INT16_C( 29469), -INT16_C(  8135),  INT16_C( 13790), -INT16_C( 14521) },
      { -INT16_C( 15318),  INT16_C( 19594), -INT16_C( 17571), -INT16_C( 17947) },
      {  INT16_C(  2241), -INT16_C( 24527),  INT16_C(  1154),  INT16_C( 17922) } },
    { {  INT16_C( 24662),  INT16_C( 28361), -INT16_C( 10427), -INT16_C( 21077) },
      { -INT16_C( 24263),  INT16_C( 23749),  INT16_C( 11937), -INT16_C( 31668) },
      {  INT16_C( 16454),  INT16_C(  8712), -INT16_C( 11964),  INT16_C( 10659) } },
    { { -INT16_C( 31302), -INT16_C( 26524), -INT16_C( 21574), -INT16_C(  6817) },
      { -INT16_C(  5776), -INT16_C( 13007),  INT16_C(  5797), -INT16_C(  1146) },
      {  INT16_C(  1162),  INT16_C(  4164), -INT16_C( 22246),  INT16_C(  1113) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t a = simde_vld1_s16(test_vec[i].a);
    simde_int16x4_t b = simde_vld1_s16(test_vec[i].b);
    simde_int16x4_t r = simde_vbic_s16(a, b);

    simde_test_arm_neon_assert_equal_i16x4(r, simde_vld1_s16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x4_t a = simde_test_arm_neon_random_i16x4();
    simde_int16x4_t b = simde_test_arm_neon_random_i16x4();
    simde_int16x4_t r = simde_vbic_s16(a, b);

    simde_test_arm_neon_write_i16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vbic_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[2];
    int32_t b[2];
    int32_t r[2];
  } test_vec[] = {
    { { -INT32_C(  1150660746),  INT32_C(  1600656678) },
      {  INT32_C(  1471884726),  INT32_C(   366741339) },
      { -INT32_C(  1472183744),  INT32_C(  1243615268) } },
    { {  INT32_C(  1202536588),  INT32_C(  1546391020) },
      { -INT32_C(  1691787786), -INT32_C(   359157900) },
      {  INT32_C(  1149501448),  INT32_C(   338165896) } },
    { {  INT32_C(   614859262), -INT32_C(   846983658) },
      { -INT32_C(  1759232196), -INT32_C(   743636921) },
      {  INT32_C(   545390786),  INT32_C(   201330192) } },
    { {  INT32_C(   756701761),  INT32_C(  1586054759) },
      {  INT32_C(   419017380),  INT32_C(  1594003553) },
      {  INT32_C(   620906561),  INT32_C(     8996358) } },
    { { -INT32_C(  1467766639), -INT32_C(   210434121) },
      { -INT32_C(  1903519417), -INT32_C(   614385766) },
      {  INT32_C(   536944784),  INT32_C(   538181669) } },
    { { -INT32_C(   116884334),  INT32_C(  1717014978) },
      { -INT32_C(  1535225533),  INT32_C(  1929609697) },
      {  INT32_C(  1493183632),  INT32_C(    72617986) } },
    { { -INT32_C(   535067095), -INT32_C(   707555186) },
      { -INT32_C(  1016898007),  INT32_C(   664716437) },
      {  INT32_C(   538476544), -INT32_C(   801042422) } },
    { {  INT32_C(    52536896),  INT32_C(  2053732407) },
      { -INT32_C(  1424037687), -INT32_C(  1843519127) },
      {  INT32_C(     2164224),  INT32_C(  1751210006) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t a = simde_vld1_s32(test_vec[i].a);
    simde_int32x2_t b = simde_vld1_s32(test_vec[i].b);
    simde_int32x2_t r = simde_vbic_s32(a, b);

    simde_test_arm_neon_assert_equal_i32x2(r, simde_vld1_s32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x2_t a = simde_test_arm_neon_random_i32x2();
    simde_int32x2_t b = simde_test_arm_neon_random_i32x2();
    simde_int32x2_t r = simde_vbic_s32(a, b);

    simde_test_arm_neon_write_i32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vbic_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a[1];
    int64_t b[1];
    int64_t r[1];
  } test_vec[] = {
    { { -INT64_C( 1005632261771282008) },
      {  INT64_C( 8314018961812778660) },
      { -INT64_C( 9220554224704614136) } },
    { { -INT64_C( 4274514201328319749) },
      { -INT64_C( 7655118891740312633) },
      {  INT64_C( 4624161154700148792) } },
    { {  INT64_C( 2414728180700755654) },
      { -INT64_C( 8653177897548564412) },
      {  INT64_C( 2306479010277754498) } },
    { {  INT64_C(  503953729577967423) },
      { -INT64_C( 4416629378076152270) },
      {  INT64_C(  309065039712096525) } },
    { { -INT64_C( 7363997450764189904) },
      {  INT64_C( 2603073874137458699) },
      { -INT64_C( 7367886722027137232) } },
    { {  INT64_C( 8331197793186011481) },
      { -INT64_C(   33698039489964598) },
      {  INT64_C(    6218838174337041) } },
    { { -INT64_C( 5137066015528789562) },
      {  INT64_C( 1777638445839074722) },
      { -INT64_C( 6911889632088287164) } },
    { {  INT64_C( 3530063880953792841) },
      { -INT64_C( 7065163928733053148) },
      {  INT64_C( 2309220850802360393) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x1_t a = simde_vld1_s64(test_vec[i].a);
    simde_int64x1_t b = simde_vld1_s64(test_vec[i].b);
    simde_int64x1_t r = simde_vbic_s64(a, b);

    simde_test_arm_neon_assert_equal_i64x1(r, simde_vld1_s64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int64x1_t a = simde_test_arm_neon_random_i64x1();
    simde_int64x1_t b = simde_test_arm_neon_random_i64x1();
    simde_int64x1_t r = simde_vbic_s64(a, b);

    simde_test_arm_neon_write_i64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x1(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vbic_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t a[8];
    uint8_t b[8];
    uint8_t r[8];
  } test_vec[] = {
    { { UINT8_C( 61), UINT8_C(245), UINT8_C(159), UINT8_C(215), UINT8_C( 64), UINT8_C( 72), UINT8_C(123), UINT8_C( 15) },
      { UINT8_C( 58), UINT8_C(163), UINT8_C(124), UINT8_C( 94), UINT8_C(  7), UINT8_C( 32), UINT8_C(188), UINT8_C(107) },
      { UINT8_C(  5), UINT8_C( 84), UINT8_C(131), UINT8_C(129), UINT8_C( 64), UINT8_C( 72), UINT8_C( 67), UINT8_C(  4) } },
    { { UINT8_C( 63), UINT8_C( 97), UINT8_C( 14), UINT8_C(228), UINT8_C(197), UINT8_C( 10), UINT8_C(226), UINT8_C(203) },
      { UINT8_C( 13), UINT8_C(222), UINT8_C(120), UINT8_C(213), UINT8_C(244), UINT8_C(243), UINT8_C( 39), UINT8_C( 50) },
      { UINT8_C( 50), UINT8_C( 33), UINT8_C(  6), UINT8_C( 32), UINT8_C(  1), UINT8_C(  8), UINT8_C(192), UINT8_C(201) } },
    { { UINT8_C(232), UINT8_C(199), UINT8_C(  9), UINT8_C( 41), UINT8_C( 15), UINT8_C(132), UINT8_C( 56), UINT8_C( 73) },
      { UINT8_C( 39), UINT8_C(180), UINT8_C(167), UINT8_C( 46), UINT8_C(213), UINT8_C( 99), UINT8_C(153), UINT8_C( 20) },
      { UINT8_C(200), UINT8_C( 67), UINT8_C(  8), UINT8_C(  1), UINT8_C( 10), UINT8_C(132), UINT8_C( 32), UINT8_C( 73) } },
    { { UINT8_C(197), UINT8_C(167), UINT8_C(249), UINT8_C(138), UINT8_C(177), UINT8_C(219), UINT8_C( 86), UINT8_C(191) },
      { UINT8_C(186), UINT8_C(206), UINT8_C(148), UINT8_C(174), UINT8_C(193), UINT8_C(188), UINT8_C(224), UINT8_C(169) },
      { UINT8_C( 69), UINT8_C( 33), UINT8_C(105), UINT8_C(  0), UINT8_C( 48), UINT8_C( 67), UINT8_C( 22), UINT8_C( 22) } },
    { { UINT8_C(131), UINT8_C(233), UINT8_C(210), UINT8_C(146), UINT8_C(109), UINT8_C( 11), UINT8_C(219), UINT8_C(148) },
      { UINT8_C(191), UINT8_C(130), UINT8_C(194), UINT8_C(148), UINT8_C(229), UINT8_C( 91), UINT8_C(169), UINT8_C(170) },
      { UINT8_C(  0), UINT8_C(105), UINT8_C( 16), UINT8_C(  2), UINT8_C(  8), UINT8_C(  0), UINT8_C( 82), UINT8_C( 20) } },
    { { UINT8_C(  3), UINT8_C(162), UINT8_C( 53), UINT8_C(180), UINT8_C(125), UINT8_C(139), UINT8_C(115), UINT8_C( 55) },
      { UINT8_C( 89), UINT8_C(  8), UINT8_C(230), UINT8_C( 26), UINT8_C(196), UINT8_C(198), UINT8_C(195), UINT8_C( 71) },
      { UINT8_C(  2), UINT8_C(162), UINT8_C( 17), UINT8_C(164), UINT8_C( 57), UINT8_C(  9), UINT8_C( 48), UINT8_C( 48) } },
    { { UINT8_C(176), UINT8_C(150), UINT8_C(217), UINT8_C( 29), UINT8_C(161), UINT8_C(180), UINT8_C(178), UINT8_C( 96) },
      { UINT8_C( 54), UINT8_C(116), UINT8_C(245), UINT8_C( 27), UINT8_C(208), UINT8_C(158), UINT8_C(198), UINT8_C(211) },
      { UINT8_C(128), UINT8_C(130), UINT8_C(  8), UINT8_C(  4), UINT8_C( 33), UINT8_C( 32), UINT8_C( 48), UINT8_C( 32) } },
    { { UINT8_C( 64), UINT8_C(251), UINT8_C(135), UINT8_C(189), UINT8_C(134), UINT8_C(251), UINT8_C(245), UINT8_C(223) },
      { UINT8_C(  3), UINT8_C(219), UINT8_C(249), UINT8_C(199), UINT8_C(161), UINT8_C(188), UINT8_C( 14), UINT8_C( 81) },
      { UINT8_C( 64), UINT8_C( 32), UINT8_C(  6), UINT8_C( 56), UINT8_C(  6), UINT8_C( 67), UINT8_C(241), UINT8_C(142) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x8_t a = simde_vld1_u8(test_vec[i].a);
    simde_uint8x8_t b = simde_vld1_u8(test_vec[i].b);
    simde_uint8x8_t r = simde_vbic_u8(a, b);

    simde_test_arm_neon_assert_equal_u8x8(r, simde_vld1_u8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8x8_t a = simde_test_arm_neon_random_u8x8();
    simde_uint8x8_t b = simde_test_arm_neon_random_u8x8();
    simde_uint8x8_t r = simde_vbic_u8(a, b);

    simde_test_arm_neon_write_u8x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vbic_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[4];
    uint16_t b[4];
    uint16_t r[4];
  } test_vec[] = {
    { { UINT16_C(59218), UINT16_C(62319), UINT16_C( 8603), UINT16_C(53588) },
      { UINT16_C(18837), UINT16_C(26092), UINT16_C(45799), UINT16_C(10040) },
      { UINT16_C(42562), UINT16_C(37379), UINT16_C(  280), UINT16_C(53316) } },
    { { UINT16_C(49325), UINT16_C(13284), UINT16_C(55739), UINT16_C(48658) },
      { UINT16_C( 2996), UINT16_C(22149), UINT16_C(37832), UINT16_C( 6823) },
      { UINT16_C(49161), UINT16_C( 8544), UINT16_C(18483), UINT16_C(42000) } },
    { { UINT16_C( 5754), UINT16_C( 5390), UINT16_C(25143), UINT16_C(52710) },
      { UINT16_C(53931), UINT16_C(37426), UINT16_C(27525), UINT16_C(12985) },
      { UINT16_C( 1104), UINT16_C( 1292), UINT16_C(   50), UINT16_C(52550) } },
    { { UINT16_C(40235), UINT16_C(58982), UINT16_C(30839), UINT16_C(11172) },
      { UINT16_C(10628), UINT16_C(19585), UINT16_C(10684), UINT16_C(13926) },
      { UINT16_C(37931), UINT16_C(41574), UINT16_C(20547), UINT16_C( 2432) } },
    { { UINT16_C(29759), UINT16_C(30539), UINT16_C(12758), UINT16_C(33092) },
      { UINT16_C(30211), UINT16_C(34835), UINT16_C(52449), UINT16_C( 3259) },
      { UINT16_C(   60), UINT16_C(30536), UINT16_C(12566), UINT16_C(33092) } },
    { { UINT16_C( 8554), UINT16_C(57842), UINT16_C(38553), UINT16_C( 7436) },
      { UINT16_C(36543), UINT16_C(31593), UINT16_C(53431), UINT16_C(63153) },
      { UINT16_C( 8512), UINT16_C(32914), UINT16_C( 1544), UINT16_C( 2316) } },
    { { UINT16_C(64580), UINT16_C( 7021), UINT16_C(45357), UINT16_C(12700) },
      { UINT16_C(45096), UINT16_C( 2489), UINT16_C(29820), UINT16_C(58902) },
      { UINT16_C(19524), UINT16_C( 4676), UINT16_C(33025), UINT16_C( 4488) } },
    { { UINT16_C( 2197), UINT16_C(12231), UINT16_C(54431), UINT16_C(24140) },
      { UINT16_C(46690), UINT16_C( 6618), UINT16_C(35718), UINT16_C(51727) },
      { UINT16_C( 2197), UINT16_C( 9733), UINT16_C(21529), UINT16_C( 5184) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4_t a = simde_vld1_u16(test_vec[i].a);
    simde_uint16x4_t b = simde_vld1_u16(test_vec[i].b);
    simde_uint16x4_t r = simde_vbic_u16(a, b);

    simde_test_arm_neon_assert_equal_u16x4(r, simde_vld1_u16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x4_t a = simde_test_arm_neon_random_u16x4();
    simde_uint16x4_t b = simde_test_arm_neon_random_u16x4();
    simde_uint16x4_t r = simde_vbic_u16(a, b);

    simde_test_arm_neon_write_u16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vbic_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[2];
    uint32_t b[2];
    uint32_t r[2];
  } test_vec[] = {
    { { UINT32_C(3051715976), UINT32_C(1457947182) },
      { UINT32_C(2925568050), UINT32_C(2861921812) },
      { UINT32_C( 293952904), UINT32_C(1415741482) } },
    { { UINT32_C( 500784254), UINT32_C(2457609520) },
      { UINT32_C(1638618843), UINT32_C(1764539361) },
      { UINT32_C( 475007012), UINT32_C(2454717456) } },
    { { UINT32_C(1713312056), UINT32_C(3317499283) },
      { UINT32_C(3128171941), UINT32_C( 291768723) },
      { UINT32_C(1141571608), UINT32_C(3298362368) } },
    { { UINT32_C(2519678309), UINT32_C(1042852706) },
      { UINT32_C(3802125313), UINT32_C(3343698831) },
      { UINT32_C( 337652068), UINT32_C( 941629536) } },
    { { UINT32_C(1882024925), UINT32_C( 372697712) },
      { UINT32_C(2597366279), UINT32_C( 413938867) },
      { UINT32_C(1613578712), UINT32_C( 101894720) } },
    { { UINT32_C(3551452017), UINT32_C(2266093446) },
      { UINT32_C( 980005291), UINT32_C(1493284220) },
      { UINT32_C(3246803536), UINT32_C(2249212546) } },
    { { UINT32_C(2445946400), UINT32_C( 547815449) },
      { UINT32_C(1572566954), UINT32_C( 477456299) },
      { UINT32_C(2151680000), UINT32_C( 545390608) } },
    { { UINT32_C(3371115586), UINT32_C(2790195707) },
      { UINT32_C( 786479282), UINT32_C(2391335278) },
      { UINT32_C(3222209600), UINT32_C( 541524113) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2_t a = simde_vld1_u32(test_vec[i].a);
    simde_uint32x2_t b = simde_vld1_u32(test_vec[i].b);
    simde_uint32x2_t r = simde_vbic_u32(a, b);

    simde_test_arm_neon_assert_equal_u32x2(r, simde_vld1_u32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x2_t a = simde_test_arm_neon_random_u32x2();
    simde_uint32x2_t b = simde_test_arm_neon_random_u32x2();
    simde_uint32x2_t r = simde_vbic_u32(a, b);

    simde_test_arm_neon_write_u32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vbic_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a[1];
    uint64_t b[1];
    uint64_t r[1];
  } test_vec[] = {
    { { UINT64_C(18179279427020476943) },
      { UINT64_C(12467316631323345981) },
      { UINT64_C( 5785155265054003714) } },
    { { UINT64_C(12075211586440393970) },
      { UINT64_C( 7239920495273276284) },
      { UINT64_C( 9476277995005052034) } },
    { { UINT64_C(11312432443049154735) },
      { UINT64_C( 1725310925415995097) },
      { UINT64_C( 9803303234419853350) } },
    { { UINT64_C(12040822386820736637) },
      { UINT64_C(18213694116147097356) },
      { UINT64_C(  223368132537090161) } },
    { { UINT64_C(   44749186997768611) },
      { UINT64_C( 3066448514927305553) },
      { UINT64_C(    4724610066632866) } },
    { { UINT64_C( 3994330218673050524) },
      { UINT64_C(12533056015108210597) },
      { UINT64_C( 1297214955384537112) } },
    { { UINT64_C( 4094983614992739245) },
      { UINT64_C(16953867103456073841) },
      { UINT64_C( 1194651959831946124) } },
    { { UINT64_C( 4697853219910641103) },
      { UINT64_C(15336482033135503903) },
      { UINT64_C(   81065449659311552) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x1_t a = simde_vld1_u64(test_vec[i].a);
    simde_uint64x1_t b = simde_vld1_u64(test_vec[i].b);
    simde_uint64x1_t r = simde_vbic_u64(a, b);

    simde_test_arm_neon_assert_equal_u64x1(r, simde_vld1_u64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint64x1_t a = simde_test_arm_neon_random_u64x1();
    simde_uint64x1_t b = simde_test_arm_neon_random_u64x1();
    simde_uint64x1_t r = simde_vbic_u64(a, b);

    simde_test_arm_neon_write_u64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x1(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vbicq_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[16];
    int8_t b[16];
    int8_t r[16];
  } test_vec[] = {
    { {  INT8_C(  87), -INT8_C(  97), -INT8_C(  71),  INT8_C(   4),  INT8_C(  24),  INT8_C( 110), -INT8_C(  67), -INT8_C(  70),
         INT8_C(  52),  INT8_C(  13),  INT8_C(  65), -INT8_C(  13),  INT8_C( 125), -INT8_C(  20),  INT8_C(  11), -INT8_C(  57) },
      { -INT8_C(  11), -INT8_C(  69),  INT8_C(  81),  INT8_C(  91),  INT8_C(   9),  INT8_C(  78), -INT8_C( 117),  INT8_C(  45),
        -INT8_C(  35), -INT8_C( 127),  INT8_C(  33), -INT8_C(  76), -INT8_C(   1),  INT8_C(  20),  INT8_C(  81),  INT8_C(  86) },
      {  INT8_C(   2),  INT8_C(   4), -INT8_C(  88),  INT8_C(   4),  INT8_C(  16),  INT8_C(  32),  INT8_C(  52), -INT8_C( 110),
         INT8_C(  32),  INT8_C(  12),  INT8_C(  64),  INT8_C(  67),  INT8_C(   0), -INT8_C(  24),  INT8_C(  10), -INT8_C( 127) } },
    { { -INT8_C(  77),  INT8_C(  10),  INT8_C(  91), -INT8_C(  53),  INT8_C( 120),  INT8_C(  24), -INT8_C( 122), -INT8_C(  84),
         INT8_C(  37), -INT8_C(  57), -INT8_C(  97), -INT8_C(  93), -INT8_C(  76), -INT8_C(  86),  INT8_C( 106), -INT8_C(  87) },
      {  INT8_C( 101), -INT8_C(  69),  INT8_C(   4),  INT8_C( 111),  INT8_C(   9), -INT8_C( 113), -INT8_C( 100), -INT8_C(  26),
         INT8_C(  16), -INT8_C(  67), -INT8_C( 102),  INT8_C(  15), -INT8_C(  47), -INT8_C(  21),  INT8_C( 102), -INT8_C( 124) },
      { -INT8_C( 110),  INT8_C(   0),  INT8_C(  91),      INT8_MIN,  INT8_C( 112),  INT8_C(  16),  INT8_C(   2),  INT8_C(   8),
         INT8_C(  37),  INT8_C(  66),  INT8_C(   5), -INT8_C(  96),  INT8_C(  36),  INT8_C(   0),  INT8_C(   8),  INT8_C(  41) } },
    { { -INT8_C(  11), -INT8_C(  63),  INT8_C(  80),  INT8_C( 110), -INT8_C(  39), -INT8_C(  42),  INT8_C(  26), -INT8_C(   2),
        -INT8_C(  99), -INT8_C(  70), -INT8_C(  95),  INT8_C(  81),  INT8_C( 100),  INT8_C(  11), -INT8_C(   5), -INT8_C(  54) },
      { -INT8_C(  58), -INT8_C(   1),  INT8_C(  57), -INT8_C(  49), -INT8_C( 113), -INT8_C(  43), -INT8_C(  74), -INT8_C(  97),
        -INT8_C( 109),  INT8_C(  80), -INT8_C(  81),  INT8_C( 100),  INT8_C(  60),  INT8_C(  21), -INT8_C(  23),  INT8_C(  49) },
      {  INT8_C(  49),  INT8_C(   0),  INT8_C(  64),  INT8_C(  32),  INT8_C(  80),  INT8_C(   2),  INT8_C(   8),  INT8_C(  96),
         INT8_C(  12), -INT8_C(  86),  INT8_C(   0),  INT8_C(  17),  INT8_C(  64),  INT8_C(  10),  INT8_C(  18), -INT8_C(  54) } },
    { { -INT8_C(  42),  INT8_C(  57), -INT8_C(  97), -INT8_C(  81),  INT8_C(  15), -INT8_C(  70), -INT8_C(  83), -INT8_C(  84),
         INT8_C( 116),  INT8_C(  79), -INT8_C(   2), -INT8_C(  40),  INT8_C(  90), -INT8_C(   7), -INT8_C(  94),  INT8_C(  33) },
      { -INT8_C(   8), -INT8_C(  37), -INT8_C(  16), -INT8_C( 121), -INT8_C(  79), -INT8_C(  90),  INT8_C(  39),  INT8_C(  68),
        -INT8_C(   9), -INT8_C(  42), -INT8_C(  88),  INT8_C(  51), -INT8_C(  21), -INT8_C( 111),  INT8_C( 100), -INT8_C(  63) },
      {  INT8_C(   6),  INT8_C(  32),  INT8_C(  15),  INT8_C(  40),  INT8_C(  14),  INT8_C(  24), -INT8_C( 120), -INT8_C(  88),
         INT8_C(   0),  INT8_C(   9),  INT8_C(  86), -INT8_C(  56),  INT8_C(  16),  INT8_C( 104), -INT8_C( 126),  INT8_C(  32) } },
    { { -INT8_C(  54),  INT8_C(   4),  INT8_C( 112), -INT8_C(  39), -INT8_C(  66),  INT8_C(  29), -INT8_C( 122),  INT8_C(  50),
         INT8_C( 108), -INT8_C( 124),  INT8_C(  10), -INT8_C(  57),  INT8_C( 125), -INT8_C(  83), -INT8_C(  24),  INT8_C( 117) },
      { -INT8_C( 120), -INT8_C(  40), -INT8_C(   3),  INT8_C(  57),      INT8_MAX,  INT8_C(  36),  INT8_C( 125),  INT8_C( 118),
        -INT8_C(   6),  INT8_C(  38), -INT8_C(  87), -INT8_C(  27), -INT8_C(  73),  INT8_C(  13), -INT8_C(  90), -INT8_C( 126) },
      {  INT8_C(  66),  INT8_C(   4),  INT8_C(   0), -INT8_C(  64),      INT8_MIN,  INT8_C(  25), -INT8_C( 126),  INT8_C(   0),
         INT8_C(   4),      INT8_MIN,  INT8_C(   2),  INT8_C(   2),  INT8_C(  72), -INT8_C(  96),  INT8_C(  72),  INT8_C( 117) } },
    { {  INT8_C(  17),  INT8_C(  22),  INT8_C(  91), -INT8_C(  49),  INT8_C(  51), -INT8_C(  31),  INT8_C(   1), -INT8_C(  96),
         INT8_C( 101),  INT8_C(  12),  INT8_C( 103), -INT8_C(  30), -INT8_C(  71),  INT8_C(  79),  INT8_C(  88),  INT8_C(  65) },
      {  INT8_C(  39),  INT8_C(  85),  INT8_C( 123), -INT8_C(  90),  INT8_C( 121), -INT8_C(   8),  INT8_C(  28),  INT8_C( 115),
         INT8_C(  30), -INT8_C(  59),  INT8_C(  88), -INT8_C(  42), -INT8_C(  45), -INT8_C(   2),  INT8_C(  88), -INT8_C(  28) },
      {  INT8_C(  16),  INT8_C(   2),  INT8_C(   0),  INT8_C(  73),  INT8_C(   2),  INT8_C(   1),  INT8_C(   1),      INT8_MIN,
         INT8_C(  97),  INT8_C(   8),  INT8_C(  39),  INT8_C(  32),  INT8_C(  40),  INT8_C(   1),  INT8_C(   0),  INT8_C(   1) } },
    { {  INT8_C(  20), -INT8_C(  77), -INT8_C(  76),  INT8_C(  71), -INT8_C( 107), -INT8_C(  75), -INT8_C(  25), -INT8_C(   6),
        -INT8_C(  63),  INT8_C(  78), -INT8_C(  35),  INT8_C( 122), -INT8_C(  99),  INT8_C(  53), -INT8_C(  68), -INT8_C(  59) },
      { -INT8_C( 118),  INT8_C(  55),  INT8_C( 107),  INT8_C(   3),  INT8_C(  47), -INT8_C( 120),  INT8_C( 118),  INT8_C(  78),
         INT8_C(  77), -INT8_C(  50),  INT8_C(  36),  INT8_C(  32), -INT8_C(  52),  INT8_C( 124),  INT8_C(   5), -INT8_C(  32) },
      {  INT8_C(  20),      INT8_MIN, -INT8_C( 108),  INT8_C(  68), -INT8_C( 112),  INT8_C(  53), -INT8_C( 127), -INT8_C(  80),
             INT8_MIN,  INT8_C(   0), -INT8_C(  39),  INT8_C(  90),  INT8_C(  17),  INT8_C(   1), -INT8_C(  72),  INT8_C(   5) } },
    { {  INT8_C(  47), -INT8_C(  71),  INT8_C(  39), -INT8_C(  60),  INT8_C( 110),  INT8_C(  15), -INT8_C(  65),  INT8_C(  48),
         INT8_C(  93), -INT8_C( 100), -INT8_C(  86), -INT8_C(   5), -INT8_C(  47),  INT8_C( 102), -INT8_C(  64),  INT8_C(  91) },
      { -INT8_C(  99),  INT8_C(  43),  INT8_C(  94), -INT8_C(  51), -INT8_C(  77), -INT8_C(  44),  INT8_C(  27),  INT8_C(   1),
        -INT8_C(  94),  INT8_C(  63),  INT8_C(  33),  INT8_C( 110), -INT8_C(  69),  INT8_C(  38),  INT8_C(  78), -INT8_C(  22) },
      {  INT8_C(  34), -INT8_C( 112),  INT8_C(  33),  INT8_C(   0),  INT8_C(  76),  INT8_C(  11), -INT8_C(  92),  INT8_C(  48),
         INT8_C(  93),      INT8_MIN, -INT8_C( 118), -INT8_C( 111),  INT8_C(  64),  INT8_C(  64),      INT8_MIN,  INT8_C(  17) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16_t a = simde_vld1q_s8(test_vec[i].a);
    simde_int8x16_t b = simde_vld1q_s8(test_vec[i].b);
    simde_int8x16_t r = simde_vbicq_s8(a, b);

    simde_test_arm_neon_assert_equal_i8x16(r, simde_vld1q_s8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x16_t a = simde_test_arm_neon_random_i8x16();
    simde_int8x16_t b = simde_test_arm_neon_random_i8x16();
    simde_int8x16_t r = simde_vbicq_s8(a, b);

    simde_test_arm_neon_write_i8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vbicq_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[8];
    int16_t b[8];
    int16_t r[8];
  } test_vec[] = {
    { {  INT16_C( 30175),  INT16_C( 20143),  INT16_C( 28292), -INT16_C(  7554),  INT16_C( 10250), -INT16_C(  9251), -INT16_C( 25201),  INT16_C( 11318) },
      { -INT16_C( 27448),  INT16_C( 31993),  INT16_C(  5224),  INT16_C(  2685), -INT16_C( 25005),  INT16_C(  3704), -INT16_C( 14651), -INT16_C( 23303) },
      {  INT16_C( 24855),  INT16_C(   518),  INT16_C( 27268), -INT16_C(  8190),  INT16_C(  8200), -INT16_C( 11899),  INT16_C(  6410),  INT16_C(  2054) } },
    { { -INT16_C( 22469), -INT16_C( 16142),  INT16_C( 28694),  INT16_C(  8354),  INT16_C( 32665),  INT16_C( 10491),  INT16_C( 12572), -INT16_C(  7084) },
      {  INT16_C( 20165),  INT16_C( 11616), -INT16_C(  8862), -INT16_C( 18889), -INT16_C( 20612),  INT16_C( 16836), -INT16_C( 17035), -INT16_C( 20251) },
      { -INT16_C( 24518), -INT16_C( 16238),  INT16_C(  8212),  INT16_C(   128),  INT16_C( 20609),  INT16_C( 10299),  INT16_C(     8),  INT16_C( 17424) } },
    { { -INT16_C( 10139),  INT16_C( 31600),  INT16_C(  4680), -INT16_C(  7781), -INT16_C( 26991), -INT16_C( 21239),  INT16_C( 24263), -INT16_C( 29550) },
      { -INT16_C(  3412),  INT16_C(  3769), -INT16_C(  3888),  INT16_C( 19652), -INT16_C( 30305),  INT16_C(  5261),  INT16_C( 29254), -INT16_C( 21307) },
      {  INT16_C(  2113),  INT16_C( 28992),  INT16_C(   520), -INT16_C( 24293),  INT16_C(  5632), -INT16_C( 22272),  INT16_C(  3201),  INT16_C(    18) } },
    { {  INT16_C( 13642), -INT16_C( 27865), -INT16_C( 15544), -INT16_C(  9868),  INT16_C( 32345),  INT16_C(  8583),  INT16_C(  6620), -INT16_C( 30547) },
      {  INT16_C( 26379), -INT16_C(  9322),  INT16_C( 23383), -INT16_C(  2265), -INT16_C( 19228),  INT16_C( 10763), -INT16_C( 12249),  INT16_C( 29142) },
      {  INT16_C(  4160),  INT16_C(    33), -INT16_C( 32760),  INT16_C(  2128),  INT16_C( 18969),  INT16_C(   388),  INT16_C(  2520), -INT16_C( 30679) } },
    { { -INT16_C(   506),  INT16_C( 19972),  INT16_C( 31169),  INT16_C(  6695), -INT16_C( 20745), -INT16_C( 11461), -INT16_C(  5689), -INT16_C( 11429) },
      { -INT16_C(  3760), -INT16_C( 22610), -INT16_C( 10676),  INT16_C( 12446), -INT16_C( 21878), -INT16_C( 20133),  INT16_C( 12666), -INT16_C( 32733) },
      {  INT16_C(  3590),  INT16_C( 18432),  INT16_C( 10625),  INT16_C(  2593),  INT16_C(  1141),  INT16_C( 16928), -INT16_C( 14203),  INT16_C( 21336) } },
    { {  INT16_C( 10031), -INT16_C(  3890), -INT16_C(  2400), -INT16_C( 26869),  INT16_C( 18084),  INT16_C( 27754), -INT16_C( 15057),  INT16_C( 32575) },
      { -INT16_C(  4681),  INT16_C(   807), -INT16_C( 14909),  INT16_C( 20020), -INT16_C( 28817), -INT16_C(  5377),  INT16_C(  8896), -INT16_C(  3990) },
      {  INT16_C(   520), -INT16_C(  3896),  INT16_C( 12832), -INT16_C( 28405),  INT16_C( 16512),  INT16_C(  1024), -INT16_C( 15057),  INT16_C(  3861) } },
    { {  INT16_C( 14666), -INT16_C(  5408), -INT16_C(  5329), -INT16_C( 11390), -INT16_C(  5070),  INT16_C( 24895),  INT16_C( 32434),  INT16_C( 27105) },
      {  INT16_C(  2156),  INT16_C( 12140), -INT16_C( 24371),  INT16_C( 15741),  INT16_C( 32047), -INT16_C(  4057), -INT16_C( 28257), -INT16_C(  5664) },
      {  INT16_C( 12546), -INT16_C( 16256),  INT16_C( 19234), -INT16_C( 15742), -INT16_C( 32752),  INT16_C(   280),  INT16_C( 28192),  INT16_C(     1) } },
    { { -INT16_C( 16182), -INT16_C(  1580),  INT16_C( 22188), -INT16_C(  8499),  INT16_C(  3138), -INT16_C(  3009),  INT16_C(  8331), -INT16_C(  2211) },
      { -INT16_C( 13784), -INT16_C(  2522), -INT16_C( 23446), -INT16_C( 26061),  INT16_C( 23073), -INT16_C( 16246),  INT16_C( 27371), -INT16_C( 18774) },
      {  INT16_C(   194),  INT16_C(  2512),  INT16_C( 21124),  INT16_C( 17612),  INT16_C(  1090),  INT16_C( 13365),  INT16_C(     0),  INT16_C( 16725) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_int16x8_t b = simde_vld1q_s16(test_vec[i].b);
    simde_int16x8_t r = simde_vbicq_s16(a, b);

    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x8_t a = simde_test_arm_neon_random_i16x8();
    simde_int16x8_t b = simde_test_arm_neon_random_i16x8();
    simde_int16x8_t r = simde_vbicq_s16(a, b);

    simde_test_arm_neon_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vbicq_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[4];
    int32_t b[4];
    int32_t r[4];
  } test_vec[] = {
    { { -INT32_C(   693141974),  INT32_C(   380927188),  INT32_C(   336327817),  INT32_C(  1024157716) },
      { -INT32_C(  1657589454), -INT32_C(   164141355), -INT32_C(  1414020672),  INT32_C(  1432445227) },
      {  INT32_C(  1116491272),  INT32_C(     8394752),  INT32_C(   336081929),  INT32_C(   671746068) } },
    { { -INT32_C(  1288957473),  INT32_C(   382328973), -INT32_C(   383068972),  INT32_C(  1864774973) },
      {  INT32_C(  1007442279),  INT32_C(  2134066111),  INT32_C(   791341572),  INT32_C(   713395275) },
      { -INT32_C(  2095054696),  INT32_C(    13148160), -INT32_C(  1073736496),  INT32_C(  1159868724) } },
    { {  INT32_C(   719171997),  INT32_C(  1715578513), -INT32_C(  1202754693),  INT32_C(   136803745) },
      { -INT32_C(  1924909874),  INT32_C(  2081191799), -INT32_C(  1398065567),  INT32_C(  1607872706) },
      {  INT32_C(   580485393),  INT32_C(    37847168),  INT32_C(   272910618),  INT32_C(     2180385) } },
    { {  INT32_C(  1938469857), -INT32_C(   707146918), -INT32_C(   678614986),  INT32_C(  1809822877) },
      {  INT32_C(  1626875112), -INT32_C(    35912549), -INT32_C(    39221446), -INT32_C(  1721990984) },
      {  INT32_C(   318935809),  INT32_C(      117568),  INT32_C(    33826820),  INT32_C(  1652765701) } },
    { { -INT32_C(  1928534477), -INT32_C(   396171855), -INT32_C(  1430262003), -INT32_C(  1944739932) },
      {  INT32_C(  1592528323),  INT32_C(  1281083409),  INT32_C(   139003216), -INT32_C(  1197365883) },
      { -INT32_C(  2130648528), -INT32_C(  1608505952), -INT32_C(  1565070835),  INT32_C(    68426272) } },
    { {  INT32_C(  1028042380), -INT32_C(  1591367533),  INT32_C(  1011606936),  INT32_C(  1204314500) },
      { -INT32_C(  2136623762), -INT32_C(   842268291), -INT32_C(  1948969722),  INT32_C(  1178826682) },
      {  INT32_C(  1027738240),  INT32_C(   539076738),  INT32_C(   873128088),  INT32_C(    25690116) } },
    { { -INT32_C(  1199273691), -INT32_C(   900093646),  INT32_C(   302425486),  INT32_C(  1952042502) },
      {  INT32_C(    32833411),  INT32_C(   114212864), -INT32_C(  1869503275),  INT32_C(  1087820827) },
      { -INT32_C(  1207959516), -INT32_C(   938399438),  INT32_C(    33947914),  INT32_C(   873007620) } },
    { { -INT32_C(  1862772130), -INT32_C(  1839574524), -INT32_C(    39493385), -INT32_C(  1301152210) },
      { -INT32_C(    38574339), -INT32_C(    66879194),  INT32_C(  1082954789), -INT32_C(   947887511) },
      {  INT32_C(     4724738),  INT32_C(    39342592), -INT32_C(  1121885998),  INT32_C(   812751878) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int32x4_t b = simde_vld1q_s32(test_vec[i].b);
    simde_int32x4_t r = simde_vbicq_s32(a, b);

    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x4_t a = simde_test_arm_neon_random_i32x4();
    simde_int32x4_t b = simde_test_arm_neon_random_i32x4();
    simde_int32x4_t r = simde_vbicq_s32(a, b);

    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vbicq_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a[2];
    int64_t b[2];
    int64_t r[2];
  } test_vec[] = {
    { { -INT64_C( 4444012918604334659), -INT64_C(  796801820583266287) },
      {  INT64_C( 5456661970280424598),  INT64_C( 7258127664946103690) },
      { -INT64_C( 9204793824029353687), -INT64_C( 8052101538401503215) } },
    { { -INT64_C( 3237391306650742395), -INT64_C( 7467808198727904911) },
      { -INT64_C( 3595545663819657304),  INT64_C( 4062101397569644115) },
      {  INT64_C( 1225103902074998789), -INT64_C( 9223367638807064288) } },
    { {  INT64_C( 8007853128983020940), -INT64_C( 2303814167882615700) },
      { -INT64_C( 4713077020254315388),  INT64_C( 6942608699457886319) },
      {  INT64_C( 4692771238685212936), -INT64_C( 9221643431464393728) } },
    { { -INT64_C( 1653999200210263394), -INT64_C( 7197492071771872508) },
      {  INT64_C(  352965863342984379),  INT64_C( 6163597989662531156) },
      { -INT64_C( 1654509463869447676), -INT64_C( 8641281750316064512) } },
    { {  INT64_C(  993040457400399969),  INT64_C( 4221392921263939552) },
      {  INT64_C( 5461535899326151218), -INT64_C( 3318593889820741148) },
      {  INT64_C(  289558620969959489),  INT64_C( 3027547110263754240) } },
    { { -INT64_C( 4590726168966077900),  INT64_C( 3192576021848757142) },
      { -INT64_C( 2843249158965121207),  INT64_C( 3454654514130648752) },
      {  INT64_C(   18084814499037236),  INT64_C(    3951645134749958) } },
    { { -INT64_C( 5915559374965923769),  INT64_C( 3994711485002653769) },
      { -INT64_C( 3131126388082907969), -INT64_C( 6041044099464429313) },
      {  INT64_C( 2982427575332667456),  INT64_C( 1391630469765898240) } },
    { { -INT64_C( 7761186173886425722), -INT64_C( 2630022896049189798) },
      { -INT64_C(  530550670868154452),  INT64_C(  300645505253414938) },
      {  INT64_C(  308672505199001602), -INT64_C( 2630031813639666624) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);
    simde_int64x2_t b = simde_vld1q_s64(test_vec[i].b);
    simde_int64x2_t r = simde_vbicq_s64(a, b);

    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int64x2_t a = simde_test_arm_neon_random_i64x2();
    simde_int64x2_t b = simde_test_arm_neon_random_i64x2();
    simde_int64x2_t r = simde_vbicq_s64(a, b);

    simde_test_arm_neon_write_i64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vbicq_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t a[16];
    uint8_t b[16];
    uint8_t r[16];
  } test_vec[] = {
    { { UINT8_C(  6), UINT8_C(195), UINT8_C(160), UINT8_C(106), UINT8_C( 80), UINT8_C(102), UINT8_C( 27), UINT8_C( 38),
        UINT8_C(175), UINT8_C(183), UINT8_C(232), UINT8_C(244), UINT8_C(131), UINT8_C(155), UINT8_C(128), UINT8_C( 86) },
      { UINT8_C( 16), UINT8_C(100), UINT8_C(232), UINT8_C(249), UINT8_C(152), UINT8_C( 38), UINT8_C( 57), UINT8_C( 75),
        UINT8_C(125), UINT8_C(193), UINT8_C(180), UINT8_C(146), UINT8_C(196), UINT8_C(103), UINT8_C(  2), UINT8_C(202) },
      { UINT8_C(  6), UINT8_C(131), UINT8_C(  0), UINT8_C(  2), UINT8_C( 64), UINT8_C( 64), UINT8_C(  2), UINT8_C( 36),
        UINT8_C(130), UINT8_C( 54), UINT8_C( 72), UINT8_C(100), UINT8_C(  3), UINT8_C(152), UINT8_C(128), UINT8_C( 20) } },
    { { UINT8_C( 42), UINT8_C(163), UINT8_C( 52), UINT8_C(122), UINT8_C(  9), UINT8_C( 80), UINT8_C(160), UINT8_C(184),
        UINT8_C(  7), UINT8_C(136), UINT8_C(173), UINT8_C(138), UINT8_C( 36), UINT8_C( 45), UINT8_C(225), UINT8_C( 52) },
      { UINT8_C(145), UINT8_C(201), UINT8_C( 45), UINT8_C( 42), UINT8_C(239), UINT8_C(102), UINT8_C(117), UINT8_C(109),
        UINT8_C( 40), UINT8_C( 41),    UINT8_MAX, UINT8_C(236), UINT8_C(144), UINT8_C(  2), UINT8_C(182), UINT8_C(186) },
      { UINT8_C( 42), UINT8_C( 34), UINT8_C( 16), UINT8_C( 80), UINT8_C(  0), UINT8_C( 16), UINT8_C(128), UINT8_C(144),
        UINT8_C(  7), UINT8_C(128), UINT8_C(  0), UINT8_C(  2), UINT8_C( 36), UINT8_C( 45), UINT8_C( 65), UINT8_C(  4) } },
    { { UINT8_C(165), UINT8_C(234), UINT8_C( 53), UINT8_C(174), UINT8_C( 58), UINT8_C(213), UINT8_C(103), UINT8_C( 65),
        UINT8_C( 94), UINT8_C( 20), UINT8_C(204), UINT8_C(130), UINT8_C( 65), UINT8_C(173), UINT8_C(182), UINT8_C(211) },
      { UINT8_C(118), UINT8_C(227), UINT8_C(253), UINT8_C(102), UINT8_C( 74), UINT8_C(114), UINT8_C(211), UINT8_C(114),
        UINT8_C(155), UINT8_C(210), UINT8_C( 94), UINT8_C( 44), UINT8_C(212), UINT8_C( 20), UINT8_C(230), UINT8_C(121) },
      { UINT8_C(129), UINT8_C(  8), UINT8_C(  0), UINT8_C(136), UINT8_C( 48), UINT8_C(133), UINT8_C( 36), UINT8_C(  1),
        UINT8_C( 68), UINT8_C(  4), UINT8_C(128), UINT8_C(130), UINT8_C(  1), UINT8_C(169), UINT8_C( 16), UINT8_C(130) } },
    { { UINT8_C(254), UINT8_C( 27), UINT8_C( 40), UINT8_C( 57), UINT8_C(241), UINT8_C(143), UINT8_C(122), UINT8_C( 79),
        UINT8_C(163), UINT8_C( 70), UINT8_C(209), UINT8_C(228), UINT8_C(243), UINT8_C(135), UINT8_C(183), UINT8_C(106) },
      { UINT8_C(106), UINT8_C(180), UINT8_C(208), UINT8_C(180), UINT8_C( 38), UINT8_C(163), UINT8_C( 38), UINT8_C(194),
        UINT8_C(117), UINT8_C(132), UINT8_C(238), UINT8_C( 74), UINT8_C(152), UINT8_C(212), UINT8_C(195), UINT8_C(151) },
      { UINT8_C(148), UINT8_C( 11), UINT8_C( 40), UINT8_C(  9), UINT8_C(209), UINT8_C( 12), UINT8_C( 88), UINT8_C( 13),
        UINT8_C(130), UINT8_C( 66), UINT8_C( 17), UINT8_C(164), UINT8_C( 99), UINT8_C(  3), UINT8_C( 52), UINT8_C(104) } },
    { { UINT8_C(240), UINT8_C(235), UINT8_C(208), UINT8_C(225), UINT8_C(122), UINT8_C( 74), UINT8_C( 48), UINT8_C( 29),
        UINT8_C(145), UINT8_C(  1), UINT8_C(  2), UINT8_C(132), UINT8_C(136), UINT8_C(185), UINT8_C(238), UINT8_C(242) },
      { UINT8_C(110), UINT8_C(190), UINT8_C(167), UINT8_C(148), UINT8_C( 97), UINT8_C(205), UINT8_C( 86), UINT8_C(215),
        UINT8_C( 82), UINT8_C( 68), UINT8_C( 33), UINT8_C(234), UINT8_C( 25), UINT8_C(228), UINT8_C(129), UINT8_C(  9) },
      { UINT8_C(144), UINT8_C( 65), UINT8_C( 80), UINT8_C( 97), UINT8_C( 26), UINT8_C(  2), UINT8_C( 32), UINT8_C(  8),
        UINT8_C(129), UINT8_C(  1), UINT8_C(  2), UINT8_C(  4), UINT8_C(128), UINT8_C( 25), UINT8_C(110), UINT8_C(242) } },
    { { UINT8_C(208), UINT8_C( 81), UINT8_C(234), UINT8_C( 74), UINT8_C(156), UINT8_C( 26), UINT8_C(104), UINT8_C( 45),
        UINT8_C( 27), UINT8_C(106), UINT8_C(177), UINT8_C(163), UINT8_C( 35), UINT8_C(160), UINT8_C(149), UINT8_C(145) },
      { UINT8_C( 94), UINT8_C( 60), UINT8_C( 38), UINT8_C(192), UINT8_C( 10), UINT8_C(124), UINT8_C(151), UINT8_C( 92),
        UINT8_C(193), UINT8_C(184), UINT8_C( 70), UINT8_C(218), UINT8_C(156), UINT8_C(200), UINT8_C(227), UINT8_C(108) },
      { UINT8_C(128), UINT8_C( 65), UINT8_C(200), UINT8_C( 10), UINT8_C(148), UINT8_C(  2), UINT8_C(104), UINT8_C( 33),
        UINT8_C( 26), UINT8_C( 66), UINT8_C(177), UINT8_C( 33), UINT8_C( 35), UINT8_C( 32), UINT8_C( 20), UINT8_C(145) } },
    { { UINT8_C( 25), UINT8_C(205), UINT8_C(183), UINT8_C(181), UINT8_C(231), UINT8_C( 31), UINT8_C(226), UINT8_C(  2),
        UINT8_C(137), UINT8_C(148), UINT8_C(165), UINT8_C(172), UINT8_C( 52), UINT8_C( 58), UINT8_C( 62), UINT8_C(146) },
      { UINT8_C(119), UINT8_C(100), UINT8_C( 82), UINT8_C(129), UINT8_C(224), UINT8_C(233), UINT8_C(221), UINT8_C(161),
        UINT8_C(161), UINT8_C( 35), UINT8_C(123), UINT8_C( 62), UINT8_C(235), UINT8_C( 94), UINT8_C(170), UINT8_C(  5) },
      { UINT8_C(  8), UINT8_C(137), UINT8_C(165), UINT8_C( 52), UINT8_C(  7), UINT8_C( 22), UINT8_C( 34), UINT8_C(  2),
        UINT8_C(  8), UINT8_C(148), UINT8_C(132), UINT8_C(128), UINT8_C( 20), UINT8_C( 32), UINT8_C( 20), UINT8_C(146) } },
    { { UINT8_C( 43), UINT8_C( 97), UINT8_C(186), UINT8_C( 18), UINT8_C(128), UINT8_C(157), UINT8_C( 20), UINT8_C(  9),
        UINT8_C( 49), UINT8_C(185), UINT8_C(182), UINT8_C(101), UINT8_C(244), UINT8_C(244), UINT8_C(247), UINT8_C(107) },
      { UINT8_C( 88), UINT8_C( 74), UINT8_C(236), UINT8_C( 56), UINT8_C( 51), UINT8_C(201), UINT8_C(218), UINT8_C(213),
        UINT8_C(236), UINT8_C( 85), UINT8_C( 19), UINT8_C(216), UINT8_C(180), UINT8_C(189), UINT8_C(221), UINT8_C(223) },
      { UINT8_C( 35), UINT8_C( 33), UINT8_C( 18), UINT8_C(  2), UINT8_C(128), UINT8_C( 20), UINT8_C(  4), UINT8_C(  8),
        UINT8_C( 17), UINT8_C(168), UINT8_C(164), UINT8_C( 37), UINT8_C( 64), UINT8_C( 64), UINT8_C( 34), UINT8_C( 32) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x16_t a = simde_vld1q_u8(test_vec[i].a);
    simde_uint8x16_t b = simde_vld1q_u8(test_vec[i].b);
    simde_uint8x16_t r = simde_vbicq_u8(a, b);

    simde_test_arm_neon_assert_equal_u8x16(r, simde_vld1q_u8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8x16_t a = simde_test_arm_neon_random_u8x16();
    simde_uint8x16_t b = simde_test_arm_neon_random_u8x16();
    simde_uint8x16_t r = simde_vbicq_u8(a, b);

    simde_test_arm_neon_write_u8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vbicq_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[8];
    uint16_t b[8];
    uint16_t r[8];
  } test_vec[] = {
    { { UINT16_C(38687), UINT16_C(40946), UINT16_C( 1588), UINT16_C(26025), UINT16_C(24512), UINT16_C(46282), UINT16_C(49747), UINT16_C(43807) },
      { UINT16_C( 2828), UINT16_C(16355), UINT16_C(48596), UINT16_C(49172), UINT16_C(10003), UINT16_C(51096), UINT16_C(30181), UINT16_C( 1190) },
      { UINT16_C(37907), UINT16_C(32784), UINT16_C(  544), UINT16_C( 9641), UINT16_C(22720), UINT16_C(12354), UINT16_C(33298), UINT16_C(43801) } },
    { { UINT16_C(38925), UINT16_C(16803), UINT16_C(19615), UINT16_C(24487), UINT16_C(29099), UINT16_C(65043), UINT16_C(12851), UINT16_C(16297) },
      { UINT16_C(36157), UINT16_C( 4479), UINT16_C(37706), UINT16_C(24017), UINT16_C(27323), UINT16_C(40996), UINT16_C(52191), UINT16_C(60580) },
      { UINT16_C( 4096), UINT16_C(16512), UINT16_C(19605), UINT16_C(  550), UINT16_C( 4352), UINT16_C(24083), UINT16_C(12320), UINT16_C( 4873) } },
    { { UINT16_C(18275), UINT16_C(  558), UINT16_C(54676), UINT16_C(16225), UINT16_C(29766), UINT16_C(31294), UINT16_C(59302), UINT16_C(58297) },
      { UINT16_C(14452), UINT16_C(49140), UINT16_C(50892), UINT16_C(34588), UINT16_C(16688), UINT16_C( 3879), UINT16_C(51980), UINT16_C(28668) },
      { UINT16_C(18179), UINT16_C(   10), UINT16_C( 4368), UINT16_C(14433), UINT16_C(13382), UINT16_C(28696), UINT16_C( 9378), UINT16_C(32769) } },
    { { UINT16_C(10770), UINT16_C(42610), UINT16_C(54271), UINT16_C(17894), UINT16_C( 9288), UINT16_C(61119), UINT16_C(30987), UINT16_C(32978) },
      { UINT16_C(50865), UINT16_C(32063), UINT16_C(23436), UINT16_C(48132), UINT16_C(11164), UINT16_C(43212), UINT16_C(51446), UINT16_C( 2328) },
      { UINT16_C(10242), UINT16_C(33344), UINT16_C(32883), UINT16_C(16866), UINT16_C( 1088), UINT16_C(17971), UINT16_C(12553), UINT16_C(32962) } },
    { { UINT16_C(35570), UINT16_C(61871), UINT16_C(38237), UINT16_C(42294), UINT16_C(63161), UINT16_C(50580), UINT16_C(26223), UINT16_C( 8261) },
      { UINT16_C(33836), UINT16_C(47518), UINT16_C(41695), UINT16_C(31861), UINT16_C(16846), UINT16_C(50212), UINT16_C(15369), UINT16_C(64461) },
      { UINT16_C( 2770), UINT16_C(16417), UINT16_C( 5376), UINT16_C(33026), UINT16_C(46641), UINT16_C(  400), UINT16_C(16998), UINT16_C(    0) } },
    { { UINT16_C(32198), UINT16_C( 9452), UINT16_C( 8978), UINT16_C(52425), UINT16_C(23833), UINT16_C(34961), UINT16_C(54979), UINT16_C(61608) },
      { UINT16_C(18010), UINT16_C(14761), UINT16_C( 7913), UINT16_C(47029), UINT16_C(55904), UINT16_C(27003), UINT16_C(18710), UINT16_C(56677) },
      { UINT16_C(14724), UINT16_C( 1092), UINT16_C( 8466), UINT16_C(18504), UINT16_C( 1305), UINT16_C(32896), UINT16_C(38593), UINT16_C( 8328) } },
    { { UINT16_C(20934), UINT16_C(55297), UINT16_C(51828), UINT16_C(36260), UINT16_C(13608), UINT16_C(60181), UINT16_C(48651), UINT16_C(26075) },
      { UINT16_C(33796), UINT16_C(60831), UINT16_C(21667), UINT16_C(  932), UINT16_C( 8238), UINT16_C(17772), UINT16_C(53609), UINT16_C(12066) },
      { UINT16_C(20930), UINT16_C( 4096), UINT16_C(35412), UINT16_C(35840), UINT16_C( 5376), UINT16_C(43537), UINT16_C(11778), UINT16_C(16601) } },
    { { UINT16_C( 8995), UINT16_C(38663), UINT16_C(44269), UINT16_C( 5413), UINT16_C(15073), UINT16_C(60673), UINT16_C(56568), UINT16_C(64850) },
      { UINT16_C(61793), UINT16_C( 1258), UINT16_C(36678), UINT16_C(29703), UINT16_C(29615), UINT16_C( 6329), UINT16_C(56133), UINT16_C(26695) },
      { UINT16_C(  514), UINT16_C(37637), UINT16_C( 8361), UINT16_C(  288), UINT16_C( 2112), UINT16_C(58624), UINT16_C( 1208), UINT16_C(38160) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);
    simde_uint16x8_t b = simde_vld1q_u16(test_vec[i].b);
    simde_uint16x8_t r = simde_vbicq_u16(a, b);

    simde_test_arm_neon_assert_equal_u16x8(r, simde_vld1q_u16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x8_t a = simde_test_arm_neon_random_u16x8();
    simde_uint16x8_t b = simde_test_arm_neon_random_u16x8();
    simde_uint16x8_t r = simde_vbicq_u16(a, b);

    simde_test_arm_neon_write_u16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vbicq_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[4];
    uint32_t b[4];
    uint32_t r[4];
  } test_vec[] = {
    { { UINT32_C(3976154878), UINT32_C(3691062522), UINT32_C(1472791135), UINT32_C(1079253983) },
      { UINT32_C(1396981517), UINT32_C(2110213070), UINT32_C(  60129726), UINT32_C(1533795420) },
      { UINT32_C(2897953010), UINT32_C(2147492912), UINT32_C(1414005313), UINT32_C(   1311619) } },
    { { UINT32_C( 625437482), UINT32_C(3993061519), UINT32_C( 709282379), UINT32_C(4067072741) },
      { UINT32_C(2806361817), UINT32_C(3072593401), UINT32_C(3938171278), UINT32_C(3225757333) },
      { UINT32_C(    147746), UINT32_C(1208041478), UINT32_C(   4473409), UINT32_C( 841652320) } },
    { { UINT32_C( 568691857), UINT32_C( 537913045), UINT32_C(2504676784), UINT32_C(3381179632) },
      { UINT32_C(1534184802), UINT32_C(1746048474), UINT32_C(3830697295), UINT32_C(2242156788) },
      { UINT32_C( 545521809), UINT32_C(    877061), UINT32_C( 285741232), UINT32_C(1208493056) } },
    { { UINT32_C(4205218085), UINT32_C( 521844335), UINT32_C(4222968843), UINT32_C(2059746584) },
      { UINT32_C(3855955466), UINT32_C( 441313227), UINT32_C(2852102325), UINT32_C(1580114745) },
      { UINT32_C( 438470949), UINT32_C(  85069860), UINT32_C(1375749130), UINT32_C( 549526528) } },
    { { UINT32_C(2623067437), UINT32_C(2528932491), UINT32_C(4002574806), UINT32_C(3093845934) },
      { UINT32_C(1486699917), UINT32_C(3648252708), UINT32_C(3296883339), UINT32_C(1109569813) },
      { UINT32_C(2218836000), UINT32_C( 109842571), UINT32_C( 705691988), UINT32_C(3091744426) } },
    { { UINT32_C( 299858566), UINT32_C(3265764332), UINT32_C(3132111116), UINT32_C( 494016656) },
      { UINT32_C(2054557781), UINT32_C(2253646331), UINT32_C(1884018267), UINT32_C( 229862791) },
      { UINT32_C(  25782914), UINT32_C(1084494340), UINT32_C(2326800644), UINT32_C( 272633872) } },
    { { UINT32_C(3558773480), UINT32_C( 966247725), UINT32_C(2415085567), UINT32_C(3048039776) },
      { UINT32_C(1882137461), UINT32_C(1744274188), UINT32_C(3772203609), UINT32_C(2548927151) },
      { UINT32_C(2215678088), UINT32_C( 402670625), UINT32_C( 253756838), UINT32_C( 536896832) } },
    { { UINT32_C(1231817500), UINT32_C(3481404368), UINT32_C(2858382666), UINT32_C(1348472027) },
      { UINT32_C(1002540847), UINT32_C(1805826066), UINT32_C(2840295930), UINT32_C( 541145092) },
      { UINT32_C(1076625424), UINT32_C(2214593472), UINT32_C(  34866176), UINT32_C(1344275675) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint32x4_t b = simde_vld1q_u32(test_vec[i].b);
    simde_uint32x4_t r = simde_vbicq_u32(a, b);

    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x4_t a = simde_test_arm_neon_random_u32x4();
    simde_uint32x4_t b = simde_test_arm_neon_random_u32x4();
    simde_uint32x4_t r = simde_vbicq_u32(a, b);

    simde_test_arm_neon_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vbicq_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a[2];
    uint64_t b[2];
    uint64_t r[2];
  } test_vec[] = {
    { { UINT64_C(18078553570196237635), UINT64_C( 9046893060057023074) },
      { UINT64_C(    5165534210969236), UINT64_C(15778620327605198548) },
      { UINT64_C(18077911455335883075), UINT64_C( 2667543062192128034) } },
    { { UINT64_C(12773001631632351896), UINT64_C( 9358616280878212884) },
      { UINT64_C(14398354302523971786), UINT64_C(18305328625565531032) },
      { UINT64_C( 3459539721204949520), UINT64_C(  135222923226022916) } },
    { { UINT64_C(15923189826326034426), UINT64_C( 3304832213169727600) },
      { UINT64_C(15596474861214369207), UINT64_C(11722325196785782858) },
      { UINT64_C(  327074508143915592), UINT64_C(  959564977322649648) } },
    { { UINT64_C(17054258213189055495), UINT64_C(14005673716370500557) },
      { UINT64_C( 8450123078937893932), UINT64_C( 7221754397098069230) },
      { UINT64_C( 9847157232331104259), UINT64_C( 9387230064850543361) } },
    { { UINT64_C(15362024655052612551), UINT64_C(14670586423812717004) },
      { UINT64_C(15087196070036833728), UINT64_C( 2272242312436811208) },
      { UINT64_C(  292874747627184647), UINT64_C(13839637005044447236) } },
    { { UINT64_C( 7611807526646103236), UINT64_C(14733200779913439243) },
      { UINT64_C(17478777101190934237), UINT64_C( 6778937351991654812) },
      { UINT64_C(  658229873193521152), UINT64_C( 9251589920637124611) } },
    { { UINT64_C( 1396621698356901211), UINT64_C( 6218403981459104116) },
      { UINT64_C(13186441964294636515), UINT64_C( 1196195757836342689) },
      { UINT64_C(   72136762904310808), UINT64_C( 5063172196752728148) } },
    { { UINT64_C(  310302592033407795), UINT64_C( 2727722607947615499) },
      { UINT64_C( 4082004640880849109), UINT64_C( 4686853095696846918) },
      { UINT64_C(  308577938604294946), UINT64_C( 2652850253405097225) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x2_t a = simde_vld1q_u64(test_vec[i].a);
    simde_uint64x2_t b = simde_vld1q_u64(test_vec[i].b);
    simde_uint64x2_t r = simde_vbicq_u64(a, b);

    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint64x2_t a = simde_test_arm_neon_random_u64x2();
    simde_uint64x2_t b = simde_test_arm_neon_random_u64x2();
    simde_uint64x2_t r = simde_vbicq_u64(a, b);

    simde_test_arm_neon_write_u64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vbic_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vbic_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vbic_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vbic_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vbic_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vbic_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vbic_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vbic_u64)
SIMDE_TEST_FUNC_LIST_ENTRY(vbicq_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vbicq_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vbicq_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vbicq_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vbicq_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vbicq_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vbicq_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vbicq_u64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
