#define SIMDE_TEST_ARM_NEON_INSN rev32

#include "test-neon.h"

/* Check that both of these work */
#if defined(__cplusplus)
  #include "../../../simde/arm/neon/rev32.h"
#else
  #include "../../../simde/arm/neon.h"
#endif

static int
test_simde_vrev32_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[8];
    int8_t r[8];
  } test_vec[] = {
    { {  INT8_C(  10), -INT8_C(   9),  INT8_C(  64),  INT8_C( 118), -INT8_C(   1), -INT8_C(  64), -INT8_C(  72), -INT8_C(  13) },
      {  INT8_C( 118),  INT8_C(  64), -INT8_C(   9),  INT8_C(  10), -INT8_C(  13), -INT8_C(  72), -INT8_C(  64), -INT8_C(   1) } },
    { {  INT8_C(  68),  INT8_C( 117),  INT8_C(  70), -INT8_C( 116),  INT8_C(  76),  INT8_C(  58), -INT8_C(  19), -INT8_C(  60) },
      { -INT8_C( 116),  INT8_C(  70),  INT8_C( 117),  INT8_C(  68), -INT8_C(  60), -INT8_C(  19),  INT8_C(  58),  INT8_C(  76) } },
    { {  INT8_C(  79), -INT8_C(  21),  INT8_C(  50), -INT8_C(   7), -INT8_C(   8), -INT8_C(  25), -INT8_C(  17), -INT8_C(  39) },
      { -INT8_C(   7),  INT8_C(  50), -INT8_C(  21),  INT8_C(  79), -INT8_C(  39), -INT8_C(  17), -INT8_C(  25), -INT8_C(   8) } },
    { {  INT8_C(  72),  INT8_C(  94), -INT8_C(  41), -INT8_C(  85),  INT8_C(  22), -INT8_C(  54),  INT8_C(  31),  INT8_C(  32) },
      { -INT8_C(  85), -INT8_C(  41),  INT8_C(  94),  INT8_C(  72),  INT8_C(  32),  INT8_C(  31), -INT8_C(  54),  INT8_C(  22) } },
    { { -INT8_C(  63),  INT8_C(  96), -INT8_C( 106), -INT8_C(  64),  INT8_C(  32),  INT8_C(  78), -INT8_C(  77),  INT8_C( 101) },
      { -INT8_C(  64), -INT8_C( 106),  INT8_C(  96), -INT8_C(  63),  INT8_C( 101), -INT8_C(  77),  INT8_C(  78),  INT8_C(  32) } },
    { { -INT8_C(  61), -INT8_C(   7), -INT8_C(  15),  INT8_C(  15),  INT8_C(  52), -INT8_C(  33), -INT8_C(  45), -INT8_C( 125) },
      {  INT8_C(  15), -INT8_C(  15), -INT8_C(   7), -INT8_C(  61), -INT8_C( 125), -INT8_C(  45), -INT8_C(  33),  INT8_C(  52) } },
    { { -INT8_C(  54),  INT8_C(   5),  INT8_C( 124), -INT8_C(  61), -INT8_C(  19),  INT8_C( 108), -INT8_C( 100),  INT8_C(  53) },
      { -INT8_C(  61),  INT8_C( 124),  INT8_C(   5), -INT8_C(  54),  INT8_C(  53), -INT8_C( 100),  INT8_C( 108), -INT8_C(  19) } },
    { { -INT8_C(  54),  INT8_C( 116), -INT8_C(  32), -INT8_C(  32),  INT8_C(  62), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1) },
      { -INT8_C(  32), -INT8_C(  32),  INT8_C( 116), -INT8_C(  54), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(  62) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8_t a = simde_vld1_s8(test_vec[i].a);
    simde_int8x8_t r = simde_vrev32_s8(a);

    simde_test_arm_neon_assert_equal_i8x8(r, simde_vld1_s8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x8_t a = simde_test_arm_neon_random_i8x8();
    simde_int8x8_t r = simde_vrev32_s8(a);

    simde_test_arm_neon_write_i8x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vrev32_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[4];
    int16_t r[4];
  } test_vec[] = {
    { {  INT16_C( 15754), -INT16_C( 21890), -INT16_C( 21019), -INT16_C(  3597) },
      { -INT16_C( 21890),  INT16_C( 15754), -INT16_C(  3597), -INT16_C( 21019) } },
    { {  INT16_C( 10757),  INT16_C( 12620), -INT16_C(  4738),  INT16_C( 30694) },
      {  INT16_C( 12620),  INT16_C( 10757),  INT16_C( 30694), -INT16_C(  4738) } },
    { { -INT16_C( 31277),  INT16_C( 31359), -INT16_C( 21795),  INT16_C( 26775) },
      {  INT16_C( 31359), -INT16_C( 31277),  INT16_C( 26775), -INT16_C( 21795) } },
    { {  INT16_C(  1077), -INT16_C( 19248),  INT16_C( 29596),  INT16_C( 10059) },
      { -INT16_C( 19248),  INT16_C(  1077),  INT16_C( 10059),  INT16_C( 29596) } },
    { { -INT16_C( 13904), -INT16_C( 26927), -INT16_C( 15242),  INT16_C( 31879) },
      { -INT16_C( 26927), -INT16_C( 13904),  INT16_C( 31879), -INT16_C( 15242) } },
    { { -INT16_C( 11282),  INT16_C( 27821), -INT16_C( 27712), -INT16_C( 27677) },
      {  INT16_C( 27821), -INT16_C( 11282), -INT16_C( 27677), -INT16_C( 27712) } },
    { {  INT16_C( 25112), -INT16_C(  2802), -INT16_C( 23283),  INT16_C( 16989) },
      { -INT16_C(  2802),  INT16_C( 25112),  INT16_C( 16989), -INT16_C( 23283) } },
    { {  INT16_C( 11689),  INT16_C( 18166),  INT16_C( 16801),  INT16_C( 20845) },
      {  INT16_C( 18166),  INT16_C( 11689),  INT16_C( 20845),  INT16_C( 16801) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t a = simde_vld1_s16(test_vec[i].a);
    simde_int16x4_t r = simde_vrev32_s16(a);

    simde_test_arm_neon_assert_equal_i16x4(r, simde_vld1_s16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x4_t a = simde_test_arm_neon_random_i16x4();
    simde_int16x4_t r = simde_vrev32_s16(a);

    simde_test_arm_neon_write_i16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vrev32_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t a[8];
    uint8_t r[8];
  } test_vec[] = {
    { { UINT8_C( 11), UINT8_C(159), UINT8_C(143), UINT8_C(167), UINT8_C(185), UINT8_C(247), UINT8_C( 63), UINT8_C(210) },
      { UINT8_C(167), UINT8_C(143), UINT8_C(159), UINT8_C( 11), UINT8_C(210), UINT8_C( 63), UINT8_C(247), UINT8_C(185) } },
    { { UINT8_C(126), UINT8_C(187), UINT8_C( 97), UINT8_C( 34), UINT8_C( 33), UINT8_C( 88), UINT8_C( 12), UINT8_C(158) },
      { UINT8_C( 34), UINT8_C( 97), UINT8_C(187), UINT8_C(126), UINT8_C(158), UINT8_C( 12), UINT8_C( 88), UINT8_C( 33) } },
    { { UINT8_C(120), UINT8_C(219), UINT8_C(  2), UINT8_C( 23), UINT8_C(244), UINT8_C( 23), UINT8_C( 40), UINT8_C(164) },
      { UINT8_C( 23), UINT8_C(  2), UINT8_C(219), UINT8_C(120), UINT8_C(164), UINT8_C( 40), UINT8_C( 23), UINT8_C(244) } },
    { { UINT8_C(213), UINT8_C( 66), UINT8_C(210), UINT8_C(230), UINT8_C( 51), UINT8_C(148), UINT8_C(224), UINT8_C( 63) },
      { UINT8_C(230), UINT8_C(210), UINT8_C( 66), UINT8_C(213), UINT8_C( 63), UINT8_C(224), UINT8_C(148), UINT8_C( 51) } },
    { { UINT8_C( 51), UINT8_C(111), UINT8_C(230), UINT8_C(236), UINT8_C(102), UINT8_C( 37), UINT8_C(191), UINT8_C(228) },
      { UINT8_C(236), UINT8_C(230), UINT8_C(111), UINT8_C( 51), UINT8_C(228), UINT8_C(191), UINT8_C( 37), UINT8_C(102) } },
    { { UINT8_C(225), UINT8_C( 32), UINT8_C(  7), UINT8_C(  2), UINT8_C(120), UINT8_C( 19), UINT8_C(160), UINT8_C(240) },
      { UINT8_C(  2), UINT8_C(  7), UINT8_C( 32), UINT8_C(225), UINT8_C(240), UINT8_C(160), UINT8_C( 19), UINT8_C(120) } },
    { { UINT8_C(239), UINT8_C(162), UINT8_C(  8), UINT8_C(227), UINT8_C(186), UINT8_C( 48), UINT8_C(135), UINT8_C(143) },
      { UINT8_C(227), UINT8_C(  8), UINT8_C(162), UINT8_C(239), UINT8_C(143), UINT8_C(135), UINT8_C( 48), UINT8_C(186) } },
    { { UINT8_C(114), UINT8_C( 90), UINT8_C(118), UINT8_C(165), UINT8_C(238), UINT8_C( 86), UINT8_C(228), UINT8_C( 33) },
      { UINT8_C(165), UINT8_C(118), UINT8_C( 90), UINT8_C(114), UINT8_C( 33), UINT8_C(228), UINT8_C( 86), UINT8_C(238) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x8_t a = simde_vld1_u8(test_vec[i].a);
    simde_uint8x8_t r = simde_vrev32_u8(a);

    simde_test_arm_neon_assert_equal_u8x8(r, simde_vld1_u8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8x8_t a = simde_test_arm_neon_random_u8x8();
    simde_uint8x8_t r = simde_vrev32_u8(a);

    simde_test_arm_neon_write_u8x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vrev32_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[4];
    uint16_t r[4];
  } test_vec[] = {
    { { UINT16_C(28484), UINT16_C(36729), UINT16_C(20702), UINT16_C(17090) },
      { UINT16_C(36729), UINT16_C(28484), UINT16_C(17090), UINT16_C(20702) } },
    { { UINT16_C( 5558), UINT16_C(16791), UINT16_C(  863), UINT16_C(34542) },
      { UINT16_C(16791), UINT16_C( 5558), UINT16_C(34542), UINT16_C(  863) } },
    { { UINT16_C(65329), UINT16_C(53465), UINT16_C(26394), UINT16_C(35387) },
      { UINT16_C(53465), UINT16_C(65329), UINT16_C(35387), UINT16_C(26394) } },
    { { UINT16_C(32028), UINT16_C( 8342), UINT16_C(52300), UINT16_C(36878) },
      { UINT16_C( 8342), UINT16_C(32028), UINT16_C(36878), UINT16_C(52300) } },
    { { UINT16_C(34619), UINT16_C( 6688), UINT16_C(58071), UINT16_C(36188) },
      { UINT16_C( 6688), UINT16_C(34619), UINT16_C(36188), UINT16_C(58071) } },
    { { UINT16_C(62455), UINT16_C(22222), UINT16_C(48631), UINT16_C(10460) },
      { UINT16_C(22222), UINT16_C(62455), UINT16_C(10460), UINT16_C(48631) } },
    { { UINT16_C(46524), UINT16_C(55288), UINT16_C(13085), UINT16_C(14689) },
      { UINT16_C(55288), UINT16_C(46524), UINT16_C(14689), UINT16_C(13085) } },
    { { UINT16_C(63408), UINT16_C(64601), UINT16_C(26564), UINT16_C(65420) },
      { UINT16_C(64601), UINT16_C(63408), UINT16_C(65420), UINT16_C(26564) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4_t a = simde_vld1_u16(test_vec[i].a);
    simde_uint16x4_t r = simde_vrev32_u16(a);
    simde_test_arm_neon_assert_equal_u16x4(r, simde_vld1_u16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x4_t a = simde_test_arm_neon_random_u16x4();
    simde_uint16x4_t r = simde_vrev32_u16(a);

    simde_test_arm_neon_write_u16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vrev32q_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[16];
    int8_t r[16];
  } test_vec[] = {
    { {  INT8_C(  45), -INT8_C(  48),  INT8_C(  72), -INT8_C( 116), -INT8_C(  46),  INT8_C(  32), -INT8_C( 105),  INT8_C(  41),
         INT8_C( 120), -INT8_C(  96), -INT8_C(  35),  INT8_C(   8), -INT8_C(  28), -INT8_C(  14),  INT8_C(  47), -INT8_C( 125) },
      { -INT8_C( 116),  INT8_C(  72), -INT8_C(  48),  INT8_C(  45),  INT8_C(  41), -INT8_C( 105),  INT8_C(  32), -INT8_C(  46),
         INT8_C(   8), -INT8_C(  35), -INT8_C(  96),  INT8_C( 120), -INT8_C( 125),  INT8_C(  47), -INT8_C(  14), -INT8_C(  28) } },
    { { -INT8_C(  48),  INT8_C(  25),  INT8_C( 111), -INT8_C(   3),  INT8_C(  85), -INT8_C(  34),  INT8_C(  77), -INT8_C(   4),
        -INT8_C(   3),  INT8_C(  17), -INT8_C( 104),  INT8_C(  73),  INT8_C(  99),  INT8_C(  29), -INT8_C( 126), -INT8_C( 112) },
      { -INT8_C(   3),  INT8_C( 111),  INT8_C(  25), -INT8_C(  48), -INT8_C(   4),  INT8_C(  77), -INT8_C(  34),  INT8_C(  85),
         INT8_C(  73), -INT8_C( 104),  INT8_C(  17), -INT8_C(   3), -INT8_C( 112), -INT8_C( 126),  INT8_C(  29),  INT8_C(  99) } },
    { { -INT8_C(  19), -INT8_C(  54),  INT8_C(  28), -INT8_C(  65), -INT8_C(  21), -INT8_C(  77), -INT8_C(  24),  INT8_C(  99),
         INT8_C(  83), -INT8_C(  58),  INT8_C( 107),  INT8_C(  55), -INT8_C(  72), -INT8_C( 102), -INT8_C(  70), -INT8_C( 120) },
      { -INT8_C(  65),  INT8_C(  28), -INT8_C(  54), -INT8_C(  19),  INT8_C(  99), -INT8_C(  24), -INT8_C(  77), -INT8_C(  21),
         INT8_C(  55),  INT8_C( 107), -INT8_C(  58),  INT8_C(  83), -INT8_C( 120), -INT8_C(  70), -INT8_C( 102), -INT8_C(  72) } },
    { { -INT8_C(  76),  INT8_C(  41), -INT8_C( 123),  INT8_C(   9),  INT8_C(   8), -INT8_C(  45),  INT8_C(   5),  INT8_C(   5),
        -INT8_C(  28), -INT8_C(  99),  INT8_C(  78),  INT8_C(  71), -INT8_C(  70), -INT8_C(  48), -INT8_C(  41), -INT8_C(  88) },
      {  INT8_C(   9), -INT8_C( 123),  INT8_C(  41), -INT8_C(  76),  INT8_C(   5),  INT8_C(   5), -INT8_C(  45),  INT8_C(   8),
         INT8_C(  71),  INT8_C(  78), -INT8_C(  99), -INT8_C(  28), -INT8_C(  88), -INT8_C(  41), -INT8_C(  48), -INT8_C(  70) } },
    { { -INT8_C( 102), -INT8_C(  13),  INT8_C( 103), -INT8_C( 123), -INT8_C(  90),  INT8_C(  80), -INT8_C(  24), -INT8_C(   7),
         INT8_C(  22),  INT8_C(  84),  INT8_C(  48), -INT8_C(  50), -INT8_C(  18), -INT8_C(  21),  INT8_C(  86), -INT8_C(  94) },
      { -INT8_C( 123),  INT8_C( 103), -INT8_C(  13), -INT8_C( 102), -INT8_C(   7), -INT8_C(  24),  INT8_C(  80), -INT8_C(  90),
        -INT8_C(  50),  INT8_C(  48),  INT8_C(  84),  INT8_C(  22), -INT8_C(  94),  INT8_C(  86), -INT8_C(  21), -INT8_C(  18) } },
    { {  INT8_C(  20), -INT8_C(  37), -INT8_C(  85),  INT8_C(  28), -INT8_C(  82), -INT8_C(  79),  INT8_C(  33), -INT8_C( 110),
         INT8_C(  78),  INT8_C( 111), -INT8_C(  39),  INT8_C(   9),  INT8_C(  63), -INT8_C(  80), -INT8_C(  79), -INT8_C(  38) },
      {  INT8_C(  28), -INT8_C(  85), -INT8_C(  37),  INT8_C(  20), -INT8_C( 110),  INT8_C(  33), -INT8_C(  79), -INT8_C(  82),
         INT8_C(   9), -INT8_C(  39),  INT8_C( 111),  INT8_C(  78), -INT8_C(  38), -INT8_C(  79), -INT8_C(  80),  INT8_C(  63) } },
    { { -INT8_C(  93),  INT8_C(  24),  INT8_C(  95),  INT8_C(  73),  INT8_C( 104),  INT8_C(  72),  INT8_C(  66),  INT8_C( 126),
        -INT8_C( 100),  INT8_C( 115),  INT8_C(  76), -INT8_C( 118),  INT8_C(  94), -INT8_C(  94),  INT8_C(  45),  INT8_C( 114) },
      {  INT8_C(  73),  INT8_C(  95),  INT8_C(  24), -INT8_C(  93),  INT8_C( 126),  INT8_C(  66),  INT8_C(  72),  INT8_C( 104),
        -INT8_C( 118),  INT8_C(  76),  INT8_C( 115), -INT8_C( 100),  INT8_C( 114),  INT8_C(  45), -INT8_C(  94),  INT8_C(  94) } },
    { {  INT8_C( 126), -INT8_C(  40), -INT8_C( 113),  INT8_C(  44), -INT8_C( 119), -INT8_C(  80), -INT8_C(  65), -INT8_C(  40),
         INT8_C(  32), -INT8_C( 104), -INT8_C(  31),  INT8_C(  95),  INT8_C(  73), -INT8_C( 110),  INT8_C(  57), -INT8_C(  20) },
      {  INT8_C(  44), -INT8_C( 113), -INT8_C(  40),  INT8_C( 126), -INT8_C(  40), -INT8_C(  65), -INT8_C(  80), -INT8_C( 119),
         INT8_C(  95), -INT8_C(  31), -INT8_C( 104),  INT8_C(  32), -INT8_C(  20),  INT8_C(  57), -INT8_C( 110),  INT8_C(  73) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16_t a = simde_vld1q_s8(test_vec[i].a);
    simde_int8x16_t r = simde_vrev32q_s8(a);

    simde_test_arm_neon_assert_equal_i8x16(r, simde_vld1q_s8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x16_t a = simde_test_arm_neon_random_i8x16();
    simde_int8x16_t r = simde_vrev32q_s8(a);

    simde_test_arm_neon_write_i8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vrev32q_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[8];
    int16_t r[8];
  } test_vec[] = {
    { {  INT16_C( 31985), -INT16_C( 12190), -INT16_C(  3912), -INT16_C( 17108), -INT16_C(  1350), -INT16_C(  2067), -INT16_C( 12798), -INT16_C( 26494) },
      { -INT16_C( 12190),  INT16_C( 31985), -INT16_C( 17108), -INT16_C(  3912), -INT16_C(  2067), -INT16_C(  1350), -INT16_C( 26494), -INT16_C( 12798) } },
    { {  INT16_C( 18268),  INT16_C( 25032), -INT16_C( 22072), -INT16_C(  3994), -INT16_C( 10072),  INT16_C( 17409), -INT16_C( 18539), -INT16_C( 31089) },
      {  INT16_C( 25032),  INT16_C( 18268), -INT16_C(  3994), -INT16_C( 22072),  INT16_C( 17409), -INT16_C( 10072), -INT16_C( 31089), -INT16_C( 18539) } },
    { { -INT16_C(  3789), -INT16_C(  5289), -INT16_C( 31774), -INT16_C( 25431), -INT16_C( 27011), -INT16_C( 32621),  INT16_C(  5477), -INT16_C( 16104) },
      { -INT16_C(  5289), -INT16_C(  3789), -INT16_C( 25431), -INT16_C( 31774), -INT16_C( 32621), -INT16_C( 27011), -INT16_C( 16104),  INT16_C(  5477) } },
    { { -INT16_C(  8100),  INT16_C(  9506), -INT16_C( 30582),  INT16_C( 12821),  INT16_C(  5728), -INT16_C(  2442),  INT16_C(  1486),  INT16_C(   380) },
      {  INT16_C(  9506), -INT16_C(  8100),  INT16_C( 12821), -INT16_C( 30582), -INT16_C(  2442),  INT16_C(  5728),  INT16_C(   380),  INT16_C(  1486) } },
    { { -INT16_C( 11274), -INT16_C( 10003), -INT16_C( 27049), -INT16_C( 11148),  INT16_C(  2092), -INT16_C( 28332),  INT16_C( 27933),  INT16_C( 31314) },
      { -INT16_C( 10003), -INT16_C( 11274), -INT16_C( 11148), -INT16_C( 27049), -INT16_C( 28332),  INT16_C(  2092),  INT16_C( 31314),  INT16_C( 27933) } },
    { {  INT16_C( 29773), -INT16_C( 10337), -INT16_C( 19203),  INT16_C( 23817),  INT16_C( 32714), -INT16_C( 26541), -INT16_C( 12156),  INT16_C( 31642) },
      { -INT16_C( 10337),  INT16_C( 29773),  INT16_C( 23817), -INT16_C( 19203), -INT16_C( 26541),  INT16_C( 32714),  INT16_C( 31642), -INT16_C( 12156) } },
    { { -INT16_C( 30813), -INT16_C(  1453), -INT16_C( 14307),  INT16_C( 18895),  INT16_C(  9168), -INT16_C(  4645),  INT16_C( 11664), -INT16_C(  8601) },
      { -INT16_C(  1453), -INT16_C( 30813),  INT16_C( 18895), -INT16_C( 14307), -INT16_C(  4645),  INT16_C(  9168), -INT16_C(  8601),  INT16_C( 11664) } },
    { {  INT16_C(  1698), -INT16_C( 24651), -INT16_C( 16454), -INT16_C( 31236),  INT16_C( 20542), -INT16_C( 15587), -INT16_C( 18656), -INT16_C( 15554) },
      { -INT16_C( 24651),  INT16_C(  1698), -INT16_C( 31236), -INT16_C( 16454), -INT16_C( 15587),  INT16_C( 20542), -INT16_C( 15554), -INT16_C( 18656) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_int16x8_t r = simde_vrev32q_s16(a);

    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x8_t a = simde_test_arm_neon_random_i16x8();
    simde_int16x8_t r = simde_vrev32q_s16(a);

    simde_test_arm_neon_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vrev32q_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t a[16];
    uint8_t r[16];
  } test_vec[] = {
    { { UINT8_C(161), UINT8_C( 83), UINT8_C(223), UINT8_C(188), UINT8_C(  0), UINT8_C(  2), UINT8_C(160), UINT8_C( 92),
        UINT8_C(226), UINT8_C(198), UINT8_C( 48), UINT8_C(190), UINT8_C( 11), UINT8_C( 36), UINT8_C(224), UINT8_C(212) },
      { UINT8_C(188), UINT8_C(223), UINT8_C( 83), UINT8_C(161), UINT8_C( 92), UINT8_C(160), UINT8_C(  2), UINT8_C(  0),
        UINT8_C(190), UINT8_C( 48), UINT8_C(198), UINT8_C(226), UINT8_C(212), UINT8_C(224), UINT8_C( 36), UINT8_C( 11) } },
    { { UINT8_C(151), UINT8_C(142), UINT8_C(141), UINT8_C(201), UINT8_C(166), UINT8_C(146), UINT8_C( 50), UINT8_C(151),
        UINT8_C(121), UINT8_C(173), UINT8_C( 52), UINT8_C(209), UINT8_C(112), UINT8_C( 40), UINT8_C(201), UINT8_C( 17) },
      { UINT8_C(201), UINT8_C(141), UINT8_C(142), UINT8_C(151), UINT8_C(151), UINT8_C( 50), UINT8_C(146), UINT8_C(166),
        UINT8_C(209), UINT8_C( 52), UINT8_C(173), UINT8_C(121), UINT8_C( 17), UINT8_C(201), UINT8_C( 40), UINT8_C(112) } },
    { { UINT8_C(123), UINT8_C(169), UINT8_C(205), UINT8_C(124), UINT8_C(171), UINT8_C(109), UINT8_C(216), UINT8_C(141),
        UINT8_C( 51), UINT8_C(  9), UINT8_C( 76), UINT8_C( 62), UINT8_C( 45), UINT8_C( 44), UINT8_C( 19), UINT8_C(196) },
      { UINT8_C(124), UINT8_C(205), UINT8_C(169), UINT8_C(123), UINT8_C(141), UINT8_C(216), UINT8_C(109), UINT8_C(171),
        UINT8_C( 62), UINT8_C( 76), UINT8_C(  9), UINT8_C( 51), UINT8_C(196), UINT8_C( 19), UINT8_C( 44), UINT8_C( 45) } },
    { { UINT8_C(186), UINT8_C(160), UINT8_C(141), UINT8_C( 97), UINT8_C( 50), UINT8_C(191), UINT8_C(248), UINT8_C(171),
        UINT8_C(108), UINT8_C( 44), UINT8_C(124), UINT8_C(220), UINT8_C( 85), UINT8_C( 69), UINT8_C(238), UINT8_C(208) },
      { UINT8_C( 97), UINT8_C(141), UINT8_C(160), UINT8_C(186), UINT8_C(171), UINT8_C(248), UINT8_C(191), UINT8_C( 50),
        UINT8_C(220), UINT8_C(124), UINT8_C( 44), UINT8_C(108), UINT8_C(208), UINT8_C(238), UINT8_C( 69), UINT8_C( 85) } },
    { { UINT8_C(238), UINT8_C(187), UINT8_C( 76), UINT8_C(153), UINT8_C( 41), UINT8_C( 37), UINT8_C( 39), UINT8_C( 92),
        UINT8_C( 46), UINT8_C(115), UINT8_C(155), UINT8_C( 91), UINT8_C(159), UINT8_C(174), UINT8_C( 31), UINT8_C( 89) },
      { UINT8_C(153), UINT8_C( 76), UINT8_C(187), UINT8_C(238), UINT8_C( 92), UINT8_C( 39), UINT8_C( 37), UINT8_C( 41),
        UINT8_C( 91), UINT8_C(155), UINT8_C(115), UINT8_C( 46), UINT8_C( 89), UINT8_C( 31), UINT8_C(174), UINT8_C(159) } },
    { { UINT8_C( 78), UINT8_C(172), UINT8_C(186), UINT8_C(128), UINT8_C(108), UINT8_C(179), UINT8_C( 43), UINT8_C(216),
        UINT8_C(223), UINT8_C(167), UINT8_C(181), UINT8_C( 52), UINT8_C(236), UINT8_C(163), UINT8_C(  5), UINT8_C(219) },
      { UINT8_C(128), UINT8_C(186), UINT8_C(172), UINT8_C( 78), UINT8_C(216), UINT8_C( 43), UINT8_C(179), UINT8_C(108),
        UINT8_C( 52), UINT8_C(181), UINT8_C(167), UINT8_C(223), UINT8_C(219), UINT8_C(  5), UINT8_C(163), UINT8_C(236) } },
    { { UINT8_C( 94), UINT8_C( 81), UINT8_C(116), UINT8_C(135), UINT8_C(118), UINT8_C(155), UINT8_C(228), UINT8_C(164),
        UINT8_C( 14), UINT8_C(127),    UINT8_MAX, UINT8_C(173), UINT8_C( 45), UINT8_C( 30), UINT8_C(  7), UINT8_C(123) },
      { UINT8_C(135), UINT8_C(116), UINT8_C( 81), UINT8_C( 94), UINT8_C(164), UINT8_C(228), UINT8_C(155), UINT8_C(118),
        UINT8_C(173),    UINT8_MAX, UINT8_C(127), UINT8_C( 14), UINT8_C(123), UINT8_C(  7), UINT8_C( 30), UINT8_C( 45) } },
    { { UINT8_C(203), UINT8_C(193), UINT8_C(251), UINT8_C( 55), UINT8_C(116), UINT8_C( 38), UINT8_C( 15), UINT8_C( 84),
        UINT8_C(205), UINT8_C(196), UINT8_C(136), UINT8_C(185), UINT8_C(103), UINT8_C(141), UINT8_C(148), UINT8_C(198) },
      { UINT8_C( 55), UINT8_C(251), UINT8_C(193), UINT8_C(203), UINT8_C( 84), UINT8_C( 15), UINT8_C( 38), UINT8_C(116),
        UINT8_C(185), UINT8_C(136), UINT8_C(196), UINT8_C(205), UINT8_C(198), UINT8_C(148), UINT8_C(141), UINT8_C(103) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x16_t a = simde_vld1q_u8(test_vec[i].a);
    simde_uint8x16_t r = simde_vrev32q_u8(a);

    simde_test_arm_neon_assert_equal_u8x16(r, simde_vld1q_u8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8x16_t a = simde_test_arm_neon_random_u8x16();
    simde_uint8x16_t r = simde_vrev32q_u8(a);

    simde_test_arm_neon_write_u8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vrev32q_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[8];
    uint16_t r[8];
  } test_vec[] = {
    { { UINT16_C(42975), UINT16_C(62484), UINT16_C(10015), UINT16_C(42627), UINT16_C(64639), UINT16_C(55475), UINT16_C(16695), UINT16_C(29054) },
      { UINT16_C(62484), UINT16_C(42975), UINT16_C(42627), UINT16_C(10015), UINT16_C(55475), UINT16_C(64639), UINT16_C(29054), UINT16_C(16695) } },
    { { UINT16_C(44679), UINT16_C(21448), UINT16_C(49234), UINT16_C(30812), UINT16_C(  245), UINT16_C(47171), UINT16_C(12985), UINT16_C(39011) },
      { UINT16_C(21448), UINT16_C(44679), UINT16_C(30812), UINT16_C(49234), UINT16_C(47171), UINT16_C(  245), UINT16_C(39011), UINT16_C(12985) } },
    { { UINT16_C(30938), UINT16_C(63884), UINT16_C( 4255), UINT16_C( 7839), UINT16_C(21004), UINT16_C(17398), UINT16_C(30099), UINT16_C( 7092) },
      { UINT16_C(63884), UINT16_C(30938), UINT16_C( 7839), UINT16_C( 4255), UINT16_C(17398), UINT16_C(21004), UINT16_C( 7092), UINT16_C(30099) } },
    { { UINT16_C(32035), UINT16_C(30062), UINT16_C(52029), UINT16_C(13293), UINT16_C(12747), UINT16_C(34027), UINT16_C(20067), UINT16_C(15644) },
      { UINT16_C(30062), UINT16_C(32035), UINT16_C(13293), UINT16_C(52029), UINT16_C(34027), UINT16_C(12747), UINT16_C(15644), UINT16_C(20067) } },
    { { UINT16_C(43206), UINT16_C(26166), UINT16_C(54712), UINT16_C(50308), UINT16_C(31527), UINT16_C(47880), UINT16_C(48368), UINT16_C( 5078) },
      { UINT16_C(26166), UINT16_C(43206), UINT16_C(50308), UINT16_C(54712), UINT16_C(47880), UINT16_C(31527), UINT16_C( 5078), UINT16_C(48368) } },
    { { UINT16_C(17465), UINT16_C(30600), UINT16_C(30223), UINT16_C(55978), UINT16_C(38311), UINT16_C( 2654), UINT16_C(31459), UINT16_C(43592) },
      { UINT16_C(30600), UINT16_C(17465), UINT16_C(55978), UINT16_C(30223), UINT16_C( 2654), UINT16_C(38311), UINT16_C(43592), UINT16_C(31459) } },
    { { UINT16_C(32291), UINT16_C(56080), UINT16_C(37972), UINT16_C(31648), UINT16_C(43023), UINT16_C(65334), UINT16_C( 3172), UINT16_C(40466) },
      { UINT16_C(56080), UINT16_C(32291), UINT16_C(31648), UINT16_C(37972), UINT16_C(65334), UINT16_C(43023), UINT16_C(40466), UINT16_C( 3172) } },
    { { UINT16_C(39761), UINT16_C(24597), UINT16_C(48913), UINT16_C(47163), UINT16_C(39252), UINT16_C(14274), UINT16_C( 2580), UINT16_C(14305) },
      { UINT16_C(24597), UINT16_C(39761), UINT16_C(47163), UINT16_C(48913), UINT16_C(14274), UINT16_C(39252), UINT16_C(14305), UINT16_C( 2580) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);
    simde_uint16x8_t r = simde_vrev32q_u16(a);
    simde_test_arm_neon_assert_equal_u16x8(r, simde_vld1q_u16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x8_t a = simde_test_arm_neon_random_u16x8();
    simde_uint16x8_t r = simde_vrev32q_u16(a);

    simde_test_arm_neon_write_u16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vrev32_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vrev32_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vrev32_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vrev32_u16)

SIMDE_TEST_FUNC_LIST_ENTRY(vrev32q_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vrev32q_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vrev32q_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vrev32q_u16)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
