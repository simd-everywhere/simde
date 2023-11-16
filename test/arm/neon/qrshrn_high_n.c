#define SIMDE_TEST_ARM_NEON_INSN qrshrn_high_n

#include "test-neon.h"
#include "../../../simde/arm/neon/qrshrn_high_n.h"

static int
test_simde_vqrshrn_high_n_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[8];
    int8_t r[8];
    int8_t r1[16];
    int8_t r3[16];
    int8_t r5[16];
    int8_t r6[16];
    int8_t r8[16];
  } test_vec[] = {
    { { -INT16_C(  8959), -INT16_C( 20900),  INT16_C( 18988),  INT16_C( 21099),  INT16_C( 29503),  INT16_C(  4915), -INT16_C( 29844), -INT16_C( 19802) },
      {  INT8_C( 96),  INT8_C( 14), -INT8_C(126), -INT8_C( 88),  INT8_C(  1),  INT8_C( 73),  INT8_C( 48),  INT8_C( 63)  },
      {  INT8_C( 96),  INT8_C( 14), -INT8_C(126), -INT8_C( 88),  INT8_C(  1),  INT8_C( 73),  INT8_C( 48),  INT8_C( 63),     INT8_MIN,     INT8_MIN,     INT8_MAX,     INT8_MAX,     INT8_MAX,     INT8_MAX,     INT8_MIN,     INT8_MIN  },
      {  INT8_C( 96),  INT8_C( 14), -INT8_C(126), -INT8_C( 88),  INT8_C(  1),  INT8_C( 73),  INT8_C( 48),  INT8_C( 63),     INT8_MIN,     INT8_MIN,     INT8_MAX,     INT8_MAX,     INT8_MAX,     INT8_MAX,     INT8_MIN,     INT8_MIN  },
      {  INT8_C( 96),  INT8_C( 14), -INT8_C(126), -INT8_C( 88),  INT8_C(  1),  INT8_C( 73),  INT8_C( 48),  INT8_C( 63),     INT8_MIN,     INT8_MIN,     INT8_MAX,     INT8_MAX,     INT8_MAX,     INT8_MAX,     INT8_MIN,     INT8_MIN  },
      {  INT8_C( 96),  INT8_C( 14), -INT8_C(126), -INT8_C( 88),  INT8_C(  1),  INT8_C( 73),  INT8_C( 48),  INT8_C( 63),     INT8_MIN,     INT8_MIN,     INT8_MAX,     INT8_MAX,     INT8_MAX,  INT8_C( 77),     INT8_MIN,     INT8_MIN  },
      {  INT8_C( 96),  INT8_C( 14), -INT8_C(126), -INT8_C( 88),  INT8_C(  1),  INT8_C( 73),  INT8_C( 48),  INT8_C( 63), -INT8_C( 35), -INT8_C( 82),  INT8_C( 74),  INT8_C( 82),  INT8_C(115),  INT8_C( 19), -INT8_C(117), -INT8_C( 77)  } },
    { {  INT16_C( 26238), -INT16_C(   985),  INT16_C( 29239), -INT16_C( 23094), -INT16_C(  4541), -INT16_C( 17388),  INT16_C( 17256),  INT16_C( 20751) },
      {  INT8_C(  9), -INT8_C(118), -INT8_C(118), -INT8_C( 12),  INT8_C( 56),  INT8_C( 23),  INT8_C( 83),  INT8_C(  6)  },
      {  INT8_C(  9), -INT8_C(118), -INT8_C(118), -INT8_C( 12),  INT8_C( 56),  INT8_C( 23),  INT8_C( 83),  INT8_C(  6),     INT8_MAX,     INT8_MIN,     INT8_MAX,     INT8_MIN,     INT8_MIN,     INT8_MIN,     INT8_MAX,     INT8_MAX  },
      {  INT8_C(  9), -INT8_C(118), -INT8_C(118), -INT8_C( 12),  INT8_C( 56),  INT8_C( 23),  INT8_C( 83),  INT8_C(  6),     INT8_MAX, -INT8_C(123),     INT8_MAX,     INT8_MIN,     INT8_MIN,     INT8_MIN,     INT8_MAX,     INT8_MAX  },
      {  INT8_C(  9), -INT8_C(118), -INT8_C(118), -INT8_C( 12),  INT8_C( 56),  INT8_C( 23),  INT8_C( 83),  INT8_C(  6),     INT8_MAX, -INT8_C( 31),     INT8_MAX,     INT8_MIN,     INT8_MIN,     INT8_MIN,     INT8_MAX,     INT8_MAX  },
      {  INT8_C(  9), -INT8_C(118), -INT8_C(118), -INT8_C( 12),  INT8_C( 56),  INT8_C( 23),  INT8_C( 83),  INT8_C(  6),     INT8_MAX, -INT8_C( 15),     INT8_MAX,     INT8_MIN, -INT8_C( 71),     INT8_MIN,     INT8_MAX,     INT8_MAX  },
      {  INT8_C(  9), -INT8_C(118), -INT8_C(118), -INT8_C( 12),  INT8_C( 56),  INT8_C( 23),  INT8_C( 83),  INT8_C(  6),  INT8_C(102), -INT8_C(  4),  INT8_C(114), -INT8_C( 90), -INT8_C( 18), -INT8_C( 68),  INT8_C( 67),  INT8_C( 81)  } },
    { {  INT16_C( 31174),  INT16_C( 29637),  INT16_C(  8980), -INT16_C( 10006),  INT16_C( 10437), -INT16_C(  1914), -INT16_C(  3412),  INT16_C( 17144) },
      { -INT8_C( 94),  INT8_C( 93), -INT8_C( 37), -INT8_C( 86),  INT8_C( 32), -INT8_C(102), -INT8_C( 70),  INT8_C( 43)  },
      { -INT8_C( 94),  INT8_C( 93), -INT8_C( 37), -INT8_C( 86),  INT8_C( 32), -INT8_C(102), -INT8_C( 70),  INT8_C( 43),     INT8_MAX,     INT8_MAX,     INT8_MAX,     INT8_MIN,     INT8_MAX,     INT8_MIN,     INT8_MIN,     INT8_MAX  },
      { -INT8_C( 94),  INT8_C( 93), -INT8_C( 37), -INT8_C( 86),  INT8_C( 32), -INT8_C(102), -INT8_C( 70),  INT8_C( 43),     INT8_MAX,     INT8_MAX,     INT8_MAX,     INT8_MIN,     INT8_MAX,     INT8_MIN,     INT8_MIN,     INT8_MAX  },
      { -INT8_C( 94),  INT8_C( 93), -INT8_C( 37), -INT8_C( 86),  INT8_C( 32), -INT8_C(102), -INT8_C( 70),  INT8_C( 43),     INT8_MAX,     INT8_MAX,     INT8_MAX,     INT8_MIN,     INT8_MAX, -INT8_C( 60), -INT8_C(107),     INT8_MAX  },
      { -INT8_C( 94),  INT8_C( 93), -INT8_C( 37), -INT8_C( 86),  INT8_C( 32), -INT8_C(102), -INT8_C( 70),  INT8_C( 43),     INT8_MAX,     INT8_MAX,     INT8_MAX,     INT8_MIN,     INT8_MAX, -INT8_C( 30), -INT8_C( 53),     INT8_MAX  },
      { -INT8_C( 94),  INT8_C( 93), -INT8_C( 37), -INT8_C( 86),  INT8_C( 32), -INT8_C(102), -INT8_C( 70),  INT8_C( 43),  INT8_C(122),  INT8_C(116),  INT8_C( 35), -INT8_C( 39),  INT8_C( 41), -INT8_C(  7), -INT8_C( 13),  INT8_C( 67)  } },
    { {  INT16_C( 21045), -INT16_C( 23324),  INT16_C( 22922),  INT16_C( 25211),  INT16_C(  8402),  INT16_C(  2492),  INT16_C( 20769),  INT16_C(  8198) },
      {  INT8_C( 94), -INT8_C( 29), -INT8_C( 54),  INT8_C(  6),  INT8_C(109),  INT8_C(  3),  INT8_C( 41),  INT8_C(  1)  },
      {  INT8_C( 94), -INT8_C( 29), -INT8_C( 54),  INT8_C(  6),  INT8_C(109),  INT8_C(  3),  INT8_C( 41),  INT8_C(  1),     INT8_MAX,     INT8_MIN,     INT8_MAX,     INT8_MAX,     INT8_MAX,     INT8_MAX,     INT8_MAX,     INT8_MAX  },
      {  INT8_C( 94), -INT8_C( 29), -INT8_C( 54),  INT8_C(  6),  INT8_C(109),  INT8_C(  3),  INT8_C( 41),  INT8_C(  1),     INT8_MAX,     INT8_MIN,     INT8_MAX,     INT8_MAX,     INT8_MAX,     INT8_MAX,     INT8_MAX,     INT8_MAX  },
      {  INT8_C( 94), -INT8_C( 29), -INT8_C( 54),  INT8_C(  6),  INT8_C(109),  INT8_C(  3),  INT8_C( 41),  INT8_C(  1),     INT8_MAX,     INT8_MIN,     INT8_MAX,     INT8_MAX,     INT8_MAX,  INT8_C( 78),     INT8_MAX,     INT8_MAX  },
      {  INT8_C( 94), -INT8_C( 29), -INT8_C( 54),  INT8_C(  6),  INT8_C(109),  INT8_C(  3),  INT8_C( 41),  INT8_C(  1),     INT8_MAX,     INT8_MIN,     INT8_MAX,     INT8_MAX,     INT8_MAX,  INT8_C( 39),     INT8_MAX,     INT8_MAX  },
      {  INT8_C( 94), -INT8_C( 29), -INT8_C( 54),  INT8_C(  6),  INT8_C(109),  INT8_C(  3),  INT8_C( 41),  INT8_C(  1),  INT8_C( 82), -INT8_C( 91),  INT8_C( 90),  INT8_C( 98),  INT8_C( 33),  INT8_C( 10),  INT8_C( 81),  INT8_C( 32)  } },
    { { -INT16_C( 11612), -INT16_C(  1033), -INT16_C( 17168), -INT16_C( 12007),  INT16_C( 22319),  INT16_C( 32085), -INT16_C(  9898), -INT16_C(  3457) },
      {  INT8_C( 66),  INT8_C(109),  INT8_C(115), -INT8_C(125),  INT8_C( 82), -INT8_C( 81),  INT8_C( 46),  INT8_C(  4)  },
      {  INT8_C( 66),  INT8_C(109),  INT8_C(115), -INT8_C(125),  INT8_C( 82), -INT8_C( 81),  INT8_C( 46),  INT8_C(  4),     INT8_MIN,     INT8_MIN,     INT8_MIN,     INT8_MIN,     INT8_MAX,     INT8_MAX,     INT8_MIN,     INT8_MIN  },
      {  INT8_C( 66),  INT8_C(109),  INT8_C(115), -INT8_C(125),  INT8_C( 82), -INT8_C( 81),  INT8_C( 46),  INT8_C(  4),     INT8_MIN,     INT8_MIN,     INT8_MIN,     INT8_MIN,     INT8_MAX,     INT8_MAX,     INT8_MIN,     INT8_MIN  },
      {  INT8_C( 66),  INT8_C(109),  INT8_C(115), -INT8_C(125),  INT8_C( 82), -INT8_C( 81),  INT8_C( 46),  INT8_C(  4),     INT8_MIN, -INT8_C( 32),     INT8_MIN,     INT8_MIN,     INT8_MAX,     INT8_MAX,     INT8_MIN, -INT8_C(108)  },
      {  INT8_C( 66),  INT8_C(109),  INT8_C(115), -INT8_C(125),  INT8_C( 82), -INT8_C( 81),  INT8_C( 46),  INT8_C(  4),     INT8_MIN, -INT8_C( 16),     INT8_MIN,     INT8_MIN,     INT8_MAX,     INT8_MAX,     INT8_MIN, -INT8_C( 54)  },
      {  INT8_C( 66),  INT8_C(109),  INT8_C(115), -INT8_C(125),  INT8_C( 82), -INT8_C( 81),  INT8_C( 46),  INT8_C(  4), -INT8_C( 45), -INT8_C(  4), -INT8_C( 67), -INT8_C( 47),  INT8_C( 87),  INT8_C(125), -INT8_C( 39), -INT8_C( 14)  } },
    { {  INT16_C(  2289),  INT16_C( 19821), -INT16_C(  9734),  INT16_C( 13238), -INT16_C( 14567),  INT16_C(  5610), -INT16_C( 31769),  INT16_C( 11544) },
      { -INT8_C( 81),  INT8_C( 17), -INT8_C(123),  INT8_C( 83), -INT8_C(  4),  INT8_C(116), -INT8_C( 22), -INT8_C( 58)  },
      { -INT8_C( 81),  INT8_C( 17), -INT8_C(123),  INT8_C( 83), -INT8_C(  4),  INT8_C(116), -INT8_C( 22), -INT8_C( 58),     INT8_MAX,     INT8_MAX,     INT8_MIN,     INT8_MAX,     INT8_MIN,     INT8_MAX,     INT8_MIN,     INT8_MAX  },
      { -INT8_C( 81),  INT8_C( 17), -INT8_C(123),  INT8_C( 83), -INT8_C(  4),  INT8_C(116), -INT8_C( 22), -INT8_C( 58),     INT8_MAX,     INT8_MAX,     INT8_MIN,     INT8_MAX,     INT8_MIN,     INT8_MAX,     INT8_MIN,     INT8_MAX  },
      { -INT8_C( 81),  INT8_C( 17), -INT8_C(123),  INT8_C( 83), -INT8_C(  4),  INT8_C(116), -INT8_C( 22), -INT8_C( 58),  INT8_C( 72),     INT8_MAX,     INT8_MIN,     INT8_MAX,     INT8_MIN,     INT8_MAX,     INT8_MIN,     INT8_MAX  },
      { -INT8_C( 81),  INT8_C( 17), -INT8_C(123),  INT8_C( 83), -INT8_C(  4),  INT8_C(116), -INT8_C( 22), -INT8_C( 58),  INT8_C( 36),     INT8_MAX,     INT8_MIN,     INT8_MAX,     INT8_MIN,  INT8_C( 88),     INT8_MIN,     INT8_MAX  },
      { -INT8_C( 81),  INT8_C( 17), -INT8_C(123),  INT8_C( 83), -INT8_C(  4),  INT8_C(116), -INT8_C( 22), -INT8_C( 58),  INT8_C(  9),  INT8_C( 77), -INT8_C( 38),  INT8_C( 52), -INT8_C( 57),  INT8_C( 22), -INT8_C(124),  INT8_C( 45)  } },
    { { -INT16_C( 31286),  INT16_C( 28817), -INT16_C(  3444), -INT16_C( 20538), -INT16_C( 23929), -INT16_C( 24903),  INT16_C( 25277),  INT16_C( 25921) },
      {  INT8_C( 58), -INT8_C( 55),  INT8_C( 59),  INT8_C( 21), -INT8_C(101), -INT8_C(119),  INT8_C( 12),  INT8_C( 38)  },
      {  INT8_C( 58), -INT8_C( 55),  INT8_C( 59),  INT8_C( 21), -INT8_C(101), -INT8_C(119),  INT8_C( 12),  INT8_C( 38),     INT8_MIN,     INT8_MAX,     INT8_MIN,     INT8_MIN,     INT8_MIN,     INT8_MIN,     INT8_MAX,     INT8_MAX  },
      {  INT8_C( 58), -INT8_C( 55),  INT8_C( 59),  INT8_C( 21), -INT8_C(101), -INT8_C(119),  INT8_C( 12),  INT8_C( 38),     INT8_MIN,     INT8_MAX,     INT8_MIN,     INT8_MIN,     INT8_MIN,     INT8_MIN,     INT8_MAX,     INT8_MAX  },
      {  INT8_C( 58), -INT8_C( 55),  INT8_C( 59),  INT8_C( 21), -INT8_C(101), -INT8_C(119),  INT8_C( 12),  INT8_C( 38),     INT8_MIN,     INT8_MAX, -INT8_C(108),     INT8_MIN,     INT8_MIN,     INT8_MIN,     INT8_MAX,     INT8_MAX  },
      {  INT8_C( 58), -INT8_C( 55),  INT8_C( 59),  INT8_C( 21), -INT8_C(101), -INT8_C(119),  INT8_C( 12),  INT8_C( 38),     INT8_MIN,     INT8_MAX, -INT8_C( 54),     INT8_MIN,     INT8_MIN,     INT8_MIN,     INT8_MAX,     INT8_MAX  },
      {  INT8_C( 58), -INT8_C( 55),  INT8_C( 59),  INT8_C( 21), -INT8_C(101), -INT8_C(119),  INT8_C( 12),  INT8_C( 38), -INT8_C(122),  INT8_C(113), -INT8_C( 13), -INT8_C( 80), -INT8_C( 93), -INT8_C( 97),  INT8_C( 99),  INT8_C(101)  } },
    { { -INT16_C( 27367),  INT16_C( 16601),  INT16_C( 25930), -INT16_C( 21136), -INT16_C( 25785),  INT16_C( 22041), -INT16_C( 21785),  INT16_C(  3537) },
      {  INT8_C( 12),  INT8_C( 59), -INT8_C( 49),  INT8_C(103),  INT8_C(101),  INT8_C( 39),  INT8_C( 21), -INT8_C( 48)  },
      {  INT8_C( 12),  INT8_C( 59), -INT8_C( 49),  INT8_C(103),  INT8_C(101),  INT8_C( 39),  INT8_C( 21), -INT8_C( 48),     INT8_MIN,     INT8_MAX,     INT8_MAX,     INT8_MIN,     INT8_MIN,     INT8_MAX,     INT8_MIN,     INT8_MAX  },
      {  INT8_C( 12),  INT8_C( 59), -INT8_C( 49),  INT8_C(103),  INT8_C(101),  INT8_C( 39),  INT8_C( 21), -INT8_C( 48),     INT8_MIN,     INT8_MAX,     INT8_MAX,     INT8_MIN,     INT8_MIN,     INT8_MAX,     INT8_MIN,     INT8_MAX  },
      {  INT8_C( 12),  INT8_C( 59), -INT8_C( 49),  INT8_C(103),  INT8_C(101),  INT8_C( 39),  INT8_C( 21), -INT8_C( 48),     INT8_MIN,     INT8_MAX,     INT8_MAX,     INT8_MIN,     INT8_MIN,     INT8_MAX,     INT8_MIN,  INT8_C(111)  },
      {  INT8_C( 12),  INT8_C( 59), -INT8_C( 49),  INT8_C(103),  INT8_C(101),  INT8_C( 39),  INT8_C( 21), -INT8_C( 48),     INT8_MIN,     INT8_MAX,     INT8_MAX,     INT8_MIN,     INT8_MIN,     INT8_MAX,     INT8_MIN,  INT8_C( 55)  },
      {  INT8_C( 12),  INT8_C( 59), -INT8_C( 49),  INT8_C(103),  INT8_C(101),  INT8_C( 39),  INT8_C( 21), -INT8_C( 48), -INT8_C(107),  INT8_C( 65),  INT8_C(101), -INT8_C( 83), -INT8_C(101),  INT8_C( 86), -INT8_C( 85),  INT8_C( 14)  } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_int8x8_t r = simde_vld1_s8(test_vec[i].r);

    simde_int8x16_t r1 = simde_vqrshrn_high_n_s16(r, a, 1);
    simde_int8x16_t r3 = simde_vqrshrn_high_n_s16(r, a, 3);
    simde_int8x16_t r5 = simde_vqrshrn_high_n_s16(r, a, 5);
    simde_int8x16_t r6 = simde_vqrshrn_high_n_s16(r, a, 6);
    simde_int8x16_t r8 = simde_vqrshrn_high_n_s16(r, a, 8);

    simde_test_arm_neon_assert_equal_i8x16(r1, simde_vld1q_s8(test_vec[i].r1));
    simde_test_arm_neon_assert_equal_i8x16(r3, simde_vld1q_s8(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_i8x16(r5, simde_vld1q_s8(test_vec[i].r5));
    simde_test_arm_neon_assert_equal_i8x16(r6, simde_vld1q_s8(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_i8x16(r8, simde_vld1q_s8(test_vec[i].r8));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x8_t a = simde_test_arm_neon_random_i16x8();
    simde_int8x8_t r = simde_test_arm_neon_random_i8x8();
    simde_int8x16_t r1 = simde_vqrshrn_high_n_s16(r, a, 1);
    simde_int8x16_t r3 = simde_vqrshrn_high_n_s16(r, a, 3);
    simde_int8x16_t r5 = simde_vqrshrn_high_n_s16(r, a, 5);
    simde_int8x16_t r6 = simde_vqrshrn_high_n_s16(r, a, 6);
    simde_int8x16_t r8 = simde_vqrshrn_high_n_s16(r, a, 8);

    simde_test_arm_neon_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x8(2, r, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x16(2, r1, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x16(2, r3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x16(2, r5, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x16(2, r6, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x16(2, r8, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqrshrn_high_n_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[4];
    int16_t r[4];
    int16_t r3[8];
    int16_t r6[8];
    int16_t r10[8];
    int16_t r13[8];
    int16_t r16[8];
  } test_vec[] = {
    { { -INT32_C(838827553),  INT32_C(1607126122), -INT32_C(694124064),  INT32_C(211448551) },
      {  INT16_C(11897),  INT16_C(12501),  INT16_C(11247),  INT16_C( 9125)  },
      {  INT16_C(11897),  INT16_C(12501),  INT16_C(11247),  INT16_C( 9125),      INT16_MIN,      INT16_MAX,      INT16_MIN,      INT16_MAX  },
      {  INT16_C(11897),  INT16_C(12501),  INT16_C(11247),  INT16_C( 9125),      INT16_MIN,      INT16_MAX,      INT16_MIN,      INT16_MAX  },
      {  INT16_C(11897),  INT16_C(12501),  INT16_C(11247),  INT16_C( 9125),      INT16_MIN,      INT16_MAX,      INT16_MIN,      INT16_MAX  },
      {  INT16_C(11897),  INT16_C(12501),  INT16_C(11247),  INT16_C( 9125),      INT16_MIN,      INT16_MAX,      INT16_MIN,  INT16_C(25812)  },
      {  INT16_C(11897),  INT16_C(12501),  INT16_C(11247),  INT16_C( 9125), -INT16_C(12799),  INT16_C(24523), -INT16_C(10591),  INT16_C( 3226)  } },
    { {  INT32_C(849016275), -INT32_C(875822714), -INT32_C(1739265907),  INT32_C(973245645) },
      { -INT16_C(27935), -INT16_C( 4116),  INT16_C(25434),  INT16_C(22961)  },
      { -INT16_C(27935), -INT16_C( 4116),  INT16_C(25434),  INT16_C(22961),      INT16_MAX,      INT16_MIN,      INT16_MIN,      INT16_MAX  },
      { -INT16_C(27935), -INT16_C( 4116),  INT16_C(25434),  INT16_C(22961),      INT16_MAX,      INT16_MIN,      INT16_MIN,      INT16_MAX  },
      { -INT16_C(27935), -INT16_C( 4116),  INT16_C(25434),  INT16_C(22961),      INT16_MAX,      INT16_MIN,      INT16_MIN,      INT16_MAX  },
      { -INT16_C(27935), -INT16_C( 4116),  INT16_C(25434),  INT16_C(22961),      INT16_MAX,      INT16_MIN,      INT16_MIN,      INT16_MAX  },
      { -INT16_C(27935), -INT16_C( 4116),  INT16_C(25434),  INT16_C(22961),  INT16_C(12955), -INT16_C(13364), -INT16_C(26539),  INT16_C(14851)  } },
    { { -INT32_C(1957939153), -INT32_C(1625665171), -INT32_C(1499812866),  INT32_C(707976967) },
      {  INT16_C(11870),  INT16_C(13351),  INT16_C(13405),  INT16_C(30046)  },
      {  INT16_C(11870),  INT16_C(13351),  INT16_C(13405),  INT16_C(30046),      INT16_MIN,      INT16_MIN,      INT16_MIN,      INT16_MAX  },
      {  INT16_C(11870),  INT16_C(13351),  INT16_C(13405),  INT16_C(30046),      INT16_MIN,      INT16_MIN,      INT16_MIN,      INT16_MAX  },
      {  INT16_C(11870),  INT16_C(13351),  INT16_C(13405),  INT16_C(30046),      INT16_MIN,      INT16_MIN,      INT16_MIN,      INT16_MAX  },
      {  INT16_C(11870),  INT16_C(13351),  INT16_C(13405),  INT16_C(30046),      INT16_MIN,      INT16_MIN,      INT16_MIN,      INT16_MAX  },
      {  INT16_C(11870),  INT16_C(13351),  INT16_C(13405),  INT16_C(30046), -INT16_C(29876), -INT16_C(24806), -INT16_C(22885),  INT16_C(10803)  } },
    { { -INT32_C(2082889817), -INT32_C(1620731234), -INT32_C(1429774637),  INT32_C(1507838808) },
      {  INT16_C(30166),  INT16_C( 2317),  INT16_C(30082),  INT16_C( 6538)  },
      {  INT16_C(30166),  INT16_C( 2317),  INT16_C(30082),  INT16_C( 6538),      INT16_MIN,      INT16_MIN,      INT16_MIN,      INT16_MAX  },
      {  INT16_C(30166),  INT16_C( 2317),  INT16_C(30082),  INT16_C( 6538),      INT16_MIN,      INT16_MIN,      INT16_MIN,      INT16_MAX  },
      {  INT16_C(30166),  INT16_C( 2317),  INT16_C(30082),  INT16_C( 6538),      INT16_MIN,      INT16_MIN,      INT16_MIN,      INT16_MAX  },
      {  INT16_C(30166),  INT16_C( 2317),  INT16_C(30082),  INT16_C( 6538),      INT16_MIN,      INT16_MIN,      INT16_MIN,      INT16_MAX  },
      {  INT16_C(30166),  INT16_C( 2317),  INT16_C(30082),  INT16_C( 6538), -INT16_C(31782), -INT16_C(24730), -INT16_C(21817),  INT16_C(23008)  } },
    { { -INT32_C(513980245), -INT32_C(1640959032),  INT32_C(1061604646), -INT32_C(1446821021) },
      { -INT16_C(24229),  INT16_C( 3795), -INT16_C( 2212), -INT16_C(30706)  },
      { -INT16_C(24229),  INT16_C( 3795), -INT16_C( 2212), -INT16_C(30706),      INT16_MIN,      INT16_MIN,      INT16_MAX,      INT16_MIN  },
      { -INT16_C(24229),  INT16_C( 3795), -INT16_C( 2212), -INT16_C(30706),      INT16_MIN,      INT16_MIN,      INT16_MAX,      INT16_MIN  },
      { -INT16_C(24229),  INT16_C( 3795), -INT16_C( 2212), -INT16_C(30706),      INT16_MIN,      INT16_MIN,      INT16_MAX,      INT16_MIN  },
      { -INT16_C(24229),  INT16_C( 3795), -INT16_C( 2212), -INT16_C(30706),      INT16_MIN,      INT16_MIN,      INT16_MAX,      INT16_MIN  },
      { -INT16_C(24229),  INT16_C( 3795), -INT16_C( 2212), -INT16_C(30706), -INT16_C( 7843), -INT16_C(25039),  INT16_C(16199), -INT16_C(22077)  } },
    { {  INT32_C(1589592708),  INT32_C(1213245629),  INT32_C(1766780598), -INT32_C(429338091) },
      {  INT16_C(30697), -INT16_C(32657),  INT16_C(31358), -INT16_C(23784)  },
      {  INT16_C(30697), -INT16_C(32657),  INT16_C(31358), -INT16_C(23784),      INT16_MAX,      INT16_MAX,      INT16_MAX,      INT16_MIN  },
      {  INT16_C(30697), -INT16_C(32657),  INT16_C(31358), -INT16_C(23784),      INT16_MAX,      INT16_MAX,      INT16_MAX,      INT16_MIN  },
      {  INT16_C(30697), -INT16_C(32657),  INT16_C(31358), -INT16_C(23784),      INT16_MAX,      INT16_MAX,      INT16_MAX,      INT16_MIN  },
      {  INT16_C(30697), -INT16_C(32657),  INT16_C(31358), -INT16_C(23784),      INT16_MAX,      INT16_MAX,      INT16_MAX,      INT16_MIN  },
      {  INT16_C(30697), -INT16_C(32657),  INT16_C(31358), -INT16_C(23784),  INT16_C(24255),  INT16_C(18513),  INT16_C(26959), -INT16_C( 6551)  } },
    { { -INT32_C(202005891), -INT32_C(1323207242),  INT32_C(177620803),  INT32_C(2037880450) },
      { -INT16_C(23811), -INT16_C(12176), -INT16_C( 1895),  INT16_C(24733)  },
      { -INT16_C(23811), -INT16_C(12176), -INT16_C( 1895),  INT16_C(24733),      INT16_MIN,      INT16_MIN,      INT16_MAX,      INT16_MAX  },
      { -INT16_C(23811), -INT16_C(12176), -INT16_C( 1895),  INT16_C(24733),      INT16_MIN,      INT16_MIN,      INT16_MAX,      INT16_MAX  },
      { -INT16_C(23811), -INT16_C(12176), -INT16_C( 1895),  INT16_C(24733),      INT16_MIN,      INT16_MIN,      INT16_MAX,      INT16_MAX  },
      { -INT16_C(23811), -INT16_C(12176), -INT16_C( 1895),  INT16_C(24733), -INT16_C(24659),      INT16_MIN,  INT16_C(21682),      INT16_MAX  },
      { -INT16_C(23811), -INT16_C(12176), -INT16_C( 1895),  INT16_C(24733), -INT16_C( 3082), -INT16_C(20191),  INT16_C( 2710),  INT16_C(31096)  } },
    { { -INT32_C(2081077396),  INT32_C(1188157182),  INT32_C(587049621),  INT32_C(34538214) },
      {  INT16_C(  689),  INT16_C(15545),  INT16_C(18263),  INT16_C( 7102)  },
      {  INT16_C(  689),  INT16_C(15545),  INT16_C(18263),  INT16_C( 7102),      INT16_MIN,      INT16_MAX,      INT16_MAX,      INT16_MAX  },
      {  INT16_C(  689),  INT16_C(15545),  INT16_C(18263),  INT16_C( 7102),      INT16_MIN,      INT16_MAX,      INT16_MAX,      INT16_MAX  },
      {  INT16_C(  689),  INT16_C(15545),  INT16_C(18263),  INT16_C( 7102),      INT16_MIN,      INT16_MAX,      INT16_MAX,      INT16_MAX  },
      {  INT16_C(  689),  INT16_C(15545),  INT16_C(18263),  INT16_C( 7102),      INT16_MIN,      INT16_MAX,      INT16_MAX,  INT16_C( 4216)  },
      {  INT16_C(  689),  INT16_C(15545),  INT16_C(18263),  INT16_C( 7102), -INT16_C(31755),  INT16_C(18130),  INT16_C( 8958),  INT16_C(  527)  } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int16x4_t r = simde_vld1_s16(test_vec[i].r);

    simde_int16x8_t r3 = simde_vqrshrn_high_n_s32(r, a, 3);
    simde_int16x8_t r6 = simde_vqrshrn_high_n_s32(r, a, 6);
    simde_int16x8_t r10 = simde_vqrshrn_high_n_s32(r, a, 10);
    simde_int16x8_t r13 = simde_vqrshrn_high_n_s32(r, a, 13);
    simde_int16x8_t r16 = simde_vqrshrn_high_n_s32(r, a, 16);

    simde_test_arm_neon_assert_equal_i16x8(r3, simde_vld1q_s16(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_i16x8(r6, simde_vld1q_s16(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_i16x8(r10, simde_vld1q_s16(test_vec[i].r10));
    simde_test_arm_neon_assert_equal_i16x8(r13, simde_vld1q_s16(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_i16x8(r16, simde_vld1q_s16(test_vec[i].r16));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x4_t a = simde_test_arm_neon_random_i32x4();
    simde_int16x4_t r = simde_test_arm_neon_random_i16x4();
    simde_int16x8_t r3 = simde_vqrshrn_high_n_s32(r, a, 3);
    simde_int16x8_t r6 = simde_vqrshrn_high_n_s32(r, a, 6);
    simde_int16x8_t r10 = simde_vqrshrn_high_n_s32(r, a, 10);
    simde_int16x8_t r13 = simde_vqrshrn_high_n_s32(r, a, 13);
    simde_int16x8_t r16 = simde_vqrshrn_high_n_s32(r, a, 16);

    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x4(2, r, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, r3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, r6, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, r10, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, r16, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqrshrn_high_n_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a[2];
    int32_t r[2];
    int32_t r6[4];
    int32_t r13[4];
    int32_t r19[4];
    int32_t r26[4];
    int32_t r32[4];
  } test_vec[] = {
    { { -INT64_C(8015303269875855703), -INT64_C(777811017774347363) },
      {  INT32_C(   574933518), -INT32_C(  1140181041)  },
      {  INT32_C(   574933518), -INT32_C(  1140181041),              INT32_MIN,              INT32_MIN  },
      {  INT32_C(   574933518), -INT32_C(  1140181041),              INT32_MIN,              INT32_MIN  },
      {  INT32_C(   574933518), -INT32_C(  1140181041),              INT32_MIN,              INT32_MIN  },
      {  INT32_C(   574933518), -INT32_C(  1140181041),              INT32_MIN,              INT32_MIN  },
      {  INT32_C(   574933518), -INT32_C(  1140181041), -INT32_C(  1866208219), -INT32_C(   181098240)  } },
    { { -INT64_C(587885589199966149),  INT64_C(2787293872381207041) },
      { -INT32_C(   813752761), -INT32_C(  1951079511)  },
      { -INT32_C(   813752761), -INT32_C(  1951079511),              INT32_MIN,              INT32_MAX  },
      { -INT32_C(   813752761), -INT32_C(  1951079511),              INT32_MIN,              INT32_MAX  },
      { -INT32_C(   813752761), -INT32_C(  1951079511),              INT32_MIN,              INT32_MAX  },
      { -INT32_C(   813752761), -INT32_C(  1951079511),              INT32_MIN,              INT32_MAX  },
      { -INT32_C(   813752761), -INT32_C(  1951079511), -INT32_C(   136877780),  INT32_C(   648967426)  } },
    { {  INT64_C(1565806582601031981), -INT64_C(3247663395406986982) },
      { -INT32_C(  1379490026),  INT32_C(  1383927484)  },
      { -INT32_C(  1379490026),  INT32_C(  1383927484),              INT32_MAX,              INT32_MIN  },
      { -INT32_C(  1379490026),  INT32_C(  1383927484),              INT32_MAX,              INT32_MIN  },
      { -INT32_C(  1379490026),  INT32_C(  1383927484),              INT32_MAX,              INT32_MIN  },
      { -INT32_C(  1379490026),  INT32_C(  1383927484),              INT32_MAX,              INT32_MIN  },
      { -INT32_C(  1379490026),  INT32_C(  1383927484),  INT32_C(   364567754), -INT32_C(   756155559)  } },
    { {  INT64_C(4698504543164676664),  INT64_C(5218700252402638633) },
      {  INT32_C(   856401848),  INT32_C(    10657996)  },
      {  INT32_C(   856401848),  INT32_C(    10657996),              INT32_MAX,              INT32_MAX  },
      {  INT32_C(   856401848),  INT32_C(    10657996),              INT32_MAX,              INT32_MAX  },
      {  INT32_C(   856401848),  INT32_C(    10657996),              INT32_MAX,              INT32_MAX  },
      {  INT32_C(   856401848),  INT32_C(    10657996),              INT32_MAX,              INT32_MAX  },
      {  INT32_C(   856401848),  INT32_C(    10657996),  INT32_C(  1093955837),  INT32_C(  1215073339)  } },
    { {  INT64_C(8695645370954972431), -INT64_C(1836535992261928359) },
      { -INT32_C(  1064871033), -INT32_C(   121309809)  },
      { -INT32_C(  1064871033), -INT32_C(   121309809),              INT32_MAX,              INT32_MIN  },
      { -INT32_C(  1064871033), -INT32_C(   121309809),              INT32_MAX,              INT32_MIN  },
      { -INT32_C(  1064871033), -INT32_C(   121309809),              INT32_MAX,              INT32_MIN  },
      { -INT32_C(  1064871033), -INT32_C(   121309809),              INT32_MAX,              INT32_MIN  },
      { -INT32_C(  1064871033), -INT32_C(   121309809),  INT32_C(  2024612709), -INT32_C(   427601857)  } },
    { { -INT64_C(7805581545156263502), -INT64_C(2190689431020379460) },
      { -INT32_C(  1254046386), -INT32_C(   754305916)  },
      { -INT32_C(  1254046386), -INT32_C(   754305916),              INT32_MIN,              INT32_MIN  },
      { -INT32_C(  1254046386), -INT32_C(   754305916),              INT32_MIN,              INT32_MIN  },
      { -INT32_C(  1254046386), -INT32_C(   754305916),              INT32_MIN,              INT32_MIN  },
      { -INT32_C(  1254046386), -INT32_C(   754305916),              INT32_MIN,              INT32_MIN  },
      { -INT32_C(  1254046386), -INT32_C(   754305916), -INT32_C(  1817378575), -INT32_C(   510059630)  } },
    { { -INT64_C(7462190876657743812),  INT64_C(7255948533612809631) },
      {  INT32_C(  1609417307), -INT32_C(   632775540)  },
      {  INT32_C(  1609417307), -INT32_C(   632775540),              INT32_MIN,              INT32_MAX  },
      {  INT32_C(  1609417307), -INT32_C(   632775540),              INT32_MIN,              INT32_MAX  },
      {  INT32_C(  1609417307), -INT32_C(   632775540),              INT32_MIN,              INT32_MAX  },
      {  INT32_C(  1609417307), -INT32_C(   632775540),              INT32_MIN,              INT32_MAX  },
      {  INT32_C(  1609417307), -INT32_C(   632775540), -INT32_C(  1737426705),  INT32_C(  1689407167)  } },
    { {  INT64_C(3129277321313730118),  INT64_C(9162266446141080176) },
      {  INT32_C(   521065375),  INT32_C(  1213388315)  },
      {  INT32_C(   521065375),  INT32_C(  1213388315),              INT32_MAX,              INT32_MAX  },
      {  INT32_C(   521065375),  INT32_C(  1213388315),              INT32_MAX,              INT32_MAX  },
      {  INT32_C(   521065375),  INT32_C(  1213388315),              INT32_MAX,              INT32_MAX  },
      {  INT32_C(   521065375),  INT32_C(  1213388315),              INT32_MAX,              INT32_MAX  },
      {  INT32_C(   521065375),  INT32_C(  1213388315),  INT32_C(   728591653),  INT32_C(  2133256394)  } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);
    simde_int32x2_t r = simde_vld1_s32(test_vec[i].r);

    simde_int32x4_t r6 = simde_vqrshrn_high_n_s64(r, a, 6);
    simde_int32x4_t r13 = simde_vqrshrn_high_n_s64(r, a, 13);
    simde_int32x4_t r19 = simde_vqrshrn_high_n_s64(r, a, 19);
    simde_int32x4_t r26 = simde_vqrshrn_high_n_s64(r, a, 26);
    simde_int32x4_t r32 = simde_vqrshrn_high_n_s64(r, a, 32);

    simde_test_arm_neon_assert_equal_i32x4(r6, simde_vld1q_s32(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_i32x4(r13, simde_vld1q_s32(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_i32x4(r19, simde_vld1q_s32(test_vec[i].r19));
    simde_test_arm_neon_assert_equal_i32x4(r26, simde_vld1q_s32(test_vec[i].r26));
    simde_test_arm_neon_assert_equal_i32x4(r32, simde_vld1q_s32(test_vec[i].r32));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int64x2_t a = simde_test_arm_neon_random_i64x2();
    simde_int32x2_t r = simde_test_arm_neon_random_i32x2();
    simde_int32x4_t r6 = simde_vqrshrn_high_n_s64(r, a, 6);
    simde_int32x4_t r13 = simde_vqrshrn_high_n_s64(r, a, 13);
    simde_int32x4_t r19 = simde_vqrshrn_high_n_s64(r, a, 19);
    simde_int32x4_t r26 = simde_vqrshrn_high_n_s64(r, a, 26);
    simde_int32x4_t r32 = simde_vqrshrn_high_n_s64(r, a, 32);

    simde_test_arm_neon_write_i64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x2(2, r, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r6, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r19, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r26, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r32, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqrshrn_high_n_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[8];
    uint8_t r[8];
    uint8_t r1[16];
    uint8_t r3[16];
    uint8_t r5[16];
    uint8_t r6[16];
    uint8_t r8[16];
  } test_vec[] = {
    { {  UINT16_C(  24470),  UINT16_C(  63986),  UINT16_C(  20177),  UINT16_C(  31660),  UINT16_C(  62352),  UINT16_C(  53911),  UINT16_C(  56962),  UINT16_C(  44856) },
      {  UINT8_C( 197),  UINT8_C( 177),  UINT8_C(  80),  UINT8_C( 199),  UINT8_C( 199),  UINT8_C(  75),  UINT8_C(  58),  UINT8_C( 173)  },
      {  UINT8_C( 197),  UINT8_C( 177),  UINT8_C(  80),  UINT8_C( 199),  UINT8_C( 199),  UINT8_C(  75),  UINT8_C(  58),  UINT8_C( 173),      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX  },
      {  UINT8_C( 197),  UINT8_C( 177),  UINT8_C(  80),  UINT8_C( 199),  UINT8_C( 199),  UINT8_C(  75),  UINT8_C(  58),  UINT8_C( 173),      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX  },
      {  UINT8_C( 197),  UINT8_C( 177),  UINT8_C(  80),  UINT8_C( 199),  UINT8_C( 199),  UINT8_C(  75),  UINT8_C(  58),  UINT8_C( 173),      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX  },
      {  UINT8_C( 197),  UINT8_C( 177),  UINT8_C(  80),  UINT8_C( 199),  UINT8_C( 199),  UINT8_C(  75),  UINT8_C(  58),  UINT8_C( 173),      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX  },
      {  UINT8_C( 197),  UINT8_C( 177),  UINT8_C(  80),  UINT8_C( 199),  UINT8_C( 199),  UINT8_C(  75),  UINT8_C(  58),  UINT8_C( 173),  UINT8_C(  96),  UINT8_C( 250),  UINT8_C(  79),  UINT8_C( 124),  UINT8_C( 244),  UINT8_C( 211),  UINT8_C( 223),  UINT8_C( 175)  } },
    { {  UINT16_C(   5860),  UINT16_C(  26864),  UINT16_C(  16809),  UINT16_C(  27423),  UINT16_C(   1079),  UINT16_C(  39522),  UINT16_C(  37626),  UINT16_C(  52910) },
      {  UINT8_C( 100),  UINT8_C(  33),  UINT8_C(  61),  UINT8_C( 175),  UINT8_C( 253),  UINT8_C(  92),  UINT8_C( 177),  UINT8_C( 177)  },
      {  UINT8_C( 100),  UINT8_C(  33),  UINT8_C(  61),  UINT8_C( 175),  UINT8_C( 253),  UINT8_C(  92),  UINT8_C( 177),  UINT8_C( 177),      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX  },
      {  UINT8_C( 100),  UINT8_C(  33),  UINT8_C(  61),  UINT8_C( 175),  UINT8_C( 253),  UINT8_C(  92),  UINT8_C( 177),  UINT8_C( 177),      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,  UINT8_C( 135),      UINT8_MAX,      UINT8_MAX,      UINT8_MAX  },
      {  UINT8_C( 100),  UINT8_C(  33),  UINT8_C(  61),  UINT8_C( 175),  UINT8_C( 253),  UINT8_C(  92),  UINT8_C( 177),  UINT8_C( 177),  UINT8_C( 183),      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,  UINT8_C(  34),      UINT8_MAX,      UINT8_MAX,      UINT8_MAX  },
      {  UINT8_C( 100),  UINT8_C(  33),  UINT8_C(  61),  UINT8_C( 175),  UINT8_C( 253),  UINT8_C(  92),  UINT8_C( 177),  UINT8_C( 177),  UINT8_C(  92),      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,  UINT8_C(  17),      UINT8_MAX,      UINT8_MAX,      UINT8_MAX  },
      {  UINT8_C( 100),  UINT8_C(  33),  UINT8_C(  61),  UINT8_C( 175),  UINT8_C( 253),  UINT8_C(  92),  UINT8_C( 177),  UINT8_C( 177),  UINT8_C(  23),  UINT8_C( 105),  UINT8_C(  66),  UINT8_C( 107),  UINT8_C(   4),  UINT8_C( 154),  UINT8_C( 147),  UINT8_C( 207)  } },
    { {  UINT16_C(   2748),  UINT16_C(    108),  UINT16_C(  19947),  UINT16_C(  21790),  UINT16_C(  38555),  UINT16_C(  63630),  UINT16_C(  14718),  UINT16_C(  60222) },
      {  UINT8_C(  30),  UINT8_C( 226),  UINT8_C(  46),  UINT8_C( 227),  UINT8_C( 201),  UINT8_C( 102),  UINT8_C( 144),  UINT8_C( 153)  },
      {  UINT8_C(  30),  UINT8_C( 226),  UINT8_C(  46),  UINT8_C( 227),  UINT8_C( 201),  UINT8_C( 102),  UINT8_C( 144),  UINT8_C( 153),      UINT8_MAX,  UINT8_C(  54),      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX  },
      {  UINT8_C(  30),  UINT8_C( 226),  UINT8_C(  46),  UINT8_C( 227),  UINT8_C( 201),  UINT8_C( 102),  UINT8_C( 144),  UINT8_C( 153),      UINT8_MAX,  UINT8_C(  14),      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX  },
      {  UINT8_C(  30),  UINT8_C( 226),  UINT8_C(  46),  UINT8_C( 227),  UINT8_C( 201),  UINT8_C( 102),  UINT8_C( 144),  UINT8_C( 153),  UINT8_C(  86),  UINT8_C(   3),      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX  },
      {  UINT8_C(  30),  UINT8_C( 226),  UINT8_C(  46),  UINT8_C( 227),  UINT8_C( 201),  UINT8_C( 102),  UINT8_C( 144),  UINT8_C( 153),  UINT8_C(  43),  UINT8_C(   2),      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,  UINT8_C( 230),      UINT8_MAX  },
      {  UINT8_C(  30),  UINT8_C( 226),  UINT8_C(  46),  UINT8_C( 227),  UINT8_C( 201),  UINT8_C( 102),  UINT8_C( 144),  UINT8_C( 153),  UINT8_C(  11),  UINT8_C(   0),  UINT8_C(  78),  UINT8_C(  85),  UINT8_C( 151),  UINT8_C( 249),  UINT8_C(  57),  UINT8_C( 235)  } },
    { {  UINT16_C(  52200),  UINT16_C(  59734),  UINT16_C(  60538),  UINT16_C(  17968),  UINT16_C(  54622),  UINT16_C(  48753),  UINT16_C(  51901),  UINT16_C(  49581) },
      {  UINT8_C(  83),  UINT8_C(  10),  UINT8_C( 178),  UINT8_C( 125),  UINT8_C(  66),  UINT8_C( 255),  UINT8_C( 198),  UINT8_C( 172)  },
      {  UINT8_C(  83),  UINT8_C(  10),  UINT8_C( 178),  UINT8_C( 125),  UINT8_C(  66),      UINT8_MAX,  UINT8_C( 198),  UINT8_C( 172),      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX  },
      {  UINT8_C(  83),  UINT8_C(  10),  UINT8_C( 178),  UINT8_C( 125),  UINT8_C(  66),      UINT8_MAX,  UINT8_C( 198),  UINT8_C( 172),      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX  },
      {  UINT8_C(  83),  UINT8_C(  10),  UINT8_C( 178),  UINT8_C( 125),  UINT8_C(  66),      UINT8_MAX,  UINT8_C( 198),  UINT8_C( 172),      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX  },
      {  UINT8_C(  83),  UINT8_C(  10),  UINT8_C( 178),  UINT8_C( 125),  UINT8_C(  66),      UINT8_MAX,  UINT8_C( 198),  UINT8_C( 172),      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX  },
      {  UINT8_C(  83),  UINT8_C(  10),  UINT8_C( 178),  UINT8_C( 125),  UINT8_C(  66),      UINT8_MAX,  UINT8_C( 198),  UINT8_C( 172),  UINT8_C( 204),  UINT8_C( 233),  UINT8_C( 236),  UINT8_C(  70),  UINT8_C( 213),  UINT8_C( 190),  UINT8_C( 203),  UINT8_C( 194)  } },
    { {  UINT16_C(  36034),  UINT16_C(  14511),  UINT16_C(  22328),  UINT16_C(  37025),  UINT16_C(  29360),  UINT16_C(  36089),  UINT16_C(  42636),  UINT16_C(  34999) },
      {  UINT8_C(  83),  UINT8_C( 110),  UINT8_C(  85),  UINT8_C(  81),  UINT8_C( 158),  UINT8_C( 156),  UINT8_C( 172),  UINT8_C( 119)  },
      {  UINT8_C(  83),  UINT8_C( 110),  UINT8_C(  85),  UINT8_C(  81),  UINT8_C( 158),  UINT8_C( 156),  UINT8_C( 172),  UINT8_C( 119),      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX  },
      {  UINT8_C(  83),  UINT8_C( 110),  UINT8_C(  85),  UINT8_C(  81),  UINT8_C( 158),  UINT8_C( 156),  UINT8_C( 172),  UINT8_C( 119),      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX  },
      {  UINT8_C(  83),  UINT8_C( 110),  UINT8_C(  85),  UINT8_C(  81),  UINT8_C( 158),  UINT8_C( 156),  UINT8_C( 172),  UINT8_C( 119),      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX  },
      {  UINT8_C(  83),  UINT8_C( 110),  UINT8_C(  85),  UINT8_C(  81),  UINT8_C( 158),  UINT8_C( 156),  UINT8_C( 172),  UINT8_C( 119),      UINT8_MAX,  UINT8_C( 227),      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX  },
      {  UINT8_C(  83),  UINT8_C( 110),  UINT8_C(  85),  UINT8_C(  81),  UINT8_C( 158),  UINT8_C( 156),  UINT8_C( 172),  UINT8_C( 119),  UINT8_C( 141),  UINT8_C(  57),  UINT8_C(  87),  UINT8_C( 145),  UINT8_C( 115),  UINT8_C( 141),  UINT8_C( 167),  UINT8_C( 137)  } },
    { {  UINT16_C(  30613),  UINT16_C(  63781),  UINT16_C(   7132),  UINT16_C(  20485),  UINT16_C(  56272),  UINT16_C(  22617),  UINT16_C(  27265),  UINT16_C(  34256) },
      {  UINT8_C( 243),  UINT8_C( 105),  UINT8_C(  61),  UINT8_C(   8),  UINT8_C(  81),  UINT8_C(  50),  UINT8_C(  77),  UINT8_C( 193)  },
      {  UINT8_C( 243),  UINT8_C( 105),  UINT8_C(  61),  UINT8_C(   8),  UINT8_C(  81),  UINT8_C(  50),  UINT8_C(  77),  UINT8_C( 193),      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX  },
      {  UINT8_C( 243),  UINT8_C( 105),  UINT8_C(  61),  UINT8_C(   8),  UINT8_C(  81),  UINT8_C(  50),  UINT8_C(  77),  UINT8_C( 193),      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX  },
      {  UINT8_C( 243),  UINT8_C( 105),  UINT8_C(  61),  UINT8_C(   8),  UINT8_C(  81),  UINT8_C(  50),  UINT8_C(  77),  UINT8_C( 193),      UINT8_MAX,      UINT8_MAX,  UINT8_C( 223),      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX  },
      {  UINT8_C( 243),  UINT8_C( 105),  UINT8_C(  61),  UINT8_C(   8),  UINT8_C(  81),  UINT8_C(  50),  UINT8_C(  77),  UINT8_C( 193),      UINT8_MAX,      UINT8_MAX,  UINT8_C( 111),      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX  },
      {  UINT8_C( 243),  UINT8_C( 105),  UINT8_C(  61),  UINT8_C(   8),  UINT8_C(  81),  UINT8_C(  50),  UINT8_C(  77),  UINT8_C( 193),  UINT8_C( 120),  UINT8_C( 249),  UINT8_C(  28),  UINT8_C(  80),  UINT8_C( 220),  UINT8_C(  88),  UINT8_C( 107),  UINT8_C( 134)  } },
    { {  UINT16_C(  48120),  UINT16_C(  29559),  UINT16_C(  33290),  UINT16_C(  12707),  UINT16_C(  14758),  UINT16_C(  64626),  UINT16_C(  33733),  UINT16_C(  12553) },
      {  UINT8_C(   1),  UINT8_C( 250),  UINT8_C(  42),  UINT8_C( 195),  UINT8_C( 208),  UINT8_C( 222),  UINT8_C( 120),  UINT8_C( 111)  },
      {  UINT8_C(   1),  UINT8_C( 250),  UINT8_C(  42),  UINT8_C( 195),  UINT8_C( 208),  UINT8_C( 222),  UINT8_C( 120),  UINT8_C( 111),      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX  },
      {  UINT8_C(   1),  UINT8_C( 250),  UINT8_C(  42),  UINT8_C( 195),  UINT8_C( 208),  UINT8_C( 222),  UINT8_C( 120),  UINT8_C( 111),      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX  },
      {  UINT8_C(   1),  UINT8_C( 250),  UINT8_C(  42),  UINT8_C( 195),  UINT8_C( 208),  UINT8_C( 222),  UINT8_C( 120),  UINT8_C( 111),      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX  },
      {  UINT8_C(   1),  UINT8_C( 250),  UINT8_C(  42),  UINT8_C( 195),  UINT8_C( 208),  UINT8_C( 222),  UINT8_C( 120),  UINT8_C( 111),      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,  UINT8_C( 199),  UINT8_C( 231),      UINT8_MAX,      UINT8_MAX,  UINT8_C( 196)  },
      {  UINT8_C(   1),  UINT8_C( 250),  UINT8_C(  42),  UINT8_C( 195),  UINT8_C( 208),  UINT8_C( 222),  UINT8_C( 120),  UINT8_C( 111),  UINT8_C( 188),  UINT8_C( 115),  UINT8_C( 130),  UINT8_C(  50),  UINT8_C(  58),  UINT8_C( 252),  UINT8_C( 132),  UINT8_C(  49)  } },
    { {  UINT16_C(  16273),  UINT16_C(  63973),  UINT16_C(   6852),  UINT16_C(  53429),  UINT16_C(  49781),  UINT16_C(  55429),  UINT16_C(   2600),  UINT16_C(  52231) },
      {  UINT8_C(  99),  UINT8_C( 137),  UINT8_C(  53),  UINT8_C( 146),  UINT8_C(  50),  UINT8_C( 116),  UINT8_C( 190),  UINT8_C(   9)  },
      {  UINT8_C(  99),  UINT8_C( 137),  UINT8_C(  53),  UINT8_C( 146),  UINT8_C(  50),  UINT8_C( 116),  UINT8_C( 190),  UINT8_C(   9),      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX  },
      {  UINT8_C(  99),  UINT8_C( 137),  UINT8_C(  53),  UINT8_C( 146),  UINT8_C(  50),  UINT8_C( 116),  UINT8_C( 190),  UINT8_C(   9),      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX  },
      {  UINT8_C(  99),  UINT8_C( 137),  UINT8_C(  53),  UINT8_C( 146),  UINT8_C(  50),  UINT8_C( 116),  UINT8_C( 190),  UINT8_C(   9),      UINT8_MAX,      UINT8_MAX,  UINT8_C( 214),      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,  UINT8_C(  81),      UINT8_MAX  },
      {  UINT8_C(  99),  UINT8_C( 137),  UINT8_C(  53),  UINT8_C( 146),  UINT8_C(  50),  UINT8_C( 116),  UINT8_C( 190),  UINT8_C(   9),  UINT8_C( 254),      UINT8_MAX,  UINT8_C( 107),      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,  UINT8_C(  41),      UINT8_MAX  },
      {  UINT8_C(  99),  UINT8_C( 137),  UINT8_C(  53),  UINT8_C( 146),  UINT8_C(  50),  UINT8_C( 116),  UINT8_C( 190),  UINT8_C(   9),  UINT8_C(  64),  UINT8_C( 250),  UINT8_C(  27),  UINT8_C( 209),  UINT8_C( 194),  UINT8_C( 217),  UINT8_C(  10),  UINT8_C( 204)  } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);
    simde_uint8x8_t r = simde_vld1_u8(test_vec[i].r);

    simde_uint8x16_t r1 = simde_vqrshrn_high_n_u16(r, a, 1);
    simde_uint8x16_t r3 = simde_vqrshrn_high_n_u16(r, a, 3);
    simde_uint8x16_t r5 = simde_vqrshrn_high_n_u16(r, a, 5);
    simde_uint8x16_t r6 = simde_vqrshrn_high_n_u16(r, a, 6);
    simde_uint8x16_t r8 = simde_vqrshrn_high_n_u16(r, a, 8);

    simde_test_arm_neon_assert_equal_u8x16(r1, simde_vld1q_u8(test_vec[i].r1));
    simde_test_arm_neon_assert_equal_u8x16(r3, simde_vld1q_u8(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_u8x16(r5, simde_vld1q_u8(test_vec[i].r5));
    simde_test_arm_neon_assert_equal_u8x16(r6, simde_vld1q_u8(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_u8x16(r8, simde_vld1q_u8(test_vec[i].r8));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x8_t a = simde_test_arm_neon_random_u16x8();
    simde_uint8x8_t r = simde_test_arm_neon_random_u8x8();
    simde_uint8x16_t r1 = simde_vqrshrn_high_n_u16(r, a, 1);
    simde_uint8x16_t r3 = simde_vqrshrn_high_n_u16(r, a, 3);
    simde_uint8x16_t r5 = simde_vqrshrn_high_n_u16(r, a, 5);
    simde_uint8x16_t r6 = simde_vqrshrn_high_n_u16(r, a, 6);
    simde_uint8x16_t r8 = simde_vqrshrn_high_n_u16(r, a, 8);

    simde_test_arm_neon_write_u16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x8(2, r, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x16(2, r1, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x16(2, r3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x16(2, r5, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x16(2, r6, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x16(2, r8, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqrshrn_high_n_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[4];
    uint16_t r[4];
    uint16_t r3[8];
    uint16_t r6[8];
    uint16_t r10[8];
    uint16_t r13[8];
    uint16_t r16[8];
  } test_vec[] = {
    { {  UINT32_C( 761942977),  UINT32_C(3012305286),  UINT32_C(2310290612),  UINT32_C(2542994018) },
      {  UINT16_C(  30761),  UINT16_C(  35410),  UINT16_C(  34506),  UINT16_C(  38571)  },
      {  UINT16_C(  30761),  UINT16_C(  35410),  UINT16_C(  34506),  UINT16_C(  38571),         UINT16_MAX,         UINT16_MAX,         UINT16_MAX,         UINT16_MAX  },
      {  UINT16_C(  30761),  UINT16_C(  35410),  UINT16_C(  34506),  UINT16_C(  38571),         UINT16_MAX,         UINT16_MAX,         UINT16_MAX,         UINT16_MAX  },
      {  UINT16_C(  30761),  UINT16_C(  35410),  UINT16_C(  34506),  UINT16_C(  38571),         UINT16_MAX,         UINT16_MAX,         UINT16_MAX,         UINT16_MAX  },
      {  UINT16_C(  30761),  UINT16_C(  35410),  UINT16_C(  34506),  UINT16_C(  38571),         UINT16_MAX,         UINT16_MAX,         UINT16_MAX,         UINT16_MAX  },
      {  UINT16_C(  30761),  UINT16_C(  35410),  UINT16_C(  34506),  UINT16_C(  38571),  UINT16_C(  11626),  UINT16_C(  45964),  UINT16_C(  35252),  UINT16_C(  38803)  } },
    { {  UINT32_C(2782830608),  UINT32_C(2268713308),  UINT32_C(  49027278),  UINT32_C( 818790821) },
      {  UINT16_C(  45788),  UINT16_C(  58593),  UINT16_C(  41499),  UINT16_C(  24941)  },
      {  UINT16_C(  45788),  UINT16_C(  58593),  UINT16_C(  41499),  UINT16_C(  24941),         UINT16_MAX,         UINT16_MAX,         UINT16_MAX,         UINT16_MAX  },
      {  UINT16_C(  45788),  UINT16_C(  58593),  UINT16_C(  41499),  UINT16_C(  24941),         UINT16_MAX,         UINT16_MAX,         UINT16_MAX,         UINT16_MAX  },
      {  UINT16_C(  45788),  UINT16_C(  58593),  UINT16_C(  41499),  UINT16_C(  24941),         UINT16_MAX,         UINT16_MAX,  UINT16_C(  47878),         UINT16_MAX  },
      {  UINT16_C(  45788),  UINT16_C(  58593),  UINT16_C(  41499),  UINT16_C(  24941),         UINT16_MAX,         UINT16_MAX,  UINT16_C(   5985),         UINT16_MAX  },
      {  UINT16_C(  45788),  UINT16_C(  58593),  UINT16_C(  41499),  UINT16_C(  24941),  UINT16_C(  42463),  UINT16_C(  34618),  UINT16_C(    748),  UINT16_C(  12494)  } },
    { {  UINT32_C(3585933417),  UINT32_C( 926257399),  UINT32_C(3632638559),  UINT32_C(2995582533) },
      {  UINT16_C(  38100),  UINT16_C(  35761),  UINT16_C(   3837),  UINT16_C(   5494)  },
      {  UINT16_C(  38100),  UINT16_C(  35761),  UINT16_C(   3837),  UINT16_C(   5494),         UINT16_MAX,         UINT16_MAX,         UINT16_MAX,         UINT16_MAX  },
      {  UINT16_C(  38100),  UINT16_C(  35761),  UINT16_C(   3837),  UINT16_C(   5494),         UINT16_MAX,         UINT16_MAX,         UINT16_MAX,         UINT16_MAX  },
      {  UINT16_C(  38100),  UINT16_C(  35761),  UINT16_C(   3837),  UINT16_C(   5494),         UINT16_MAX,         UINT16_MAX,         UINT16_MAX,         UINT16_MAX  },
      {  UINT16_C(  38100),  UINT16_C(  35761),  UINT16_C(   3837),  UINT16_C(   5494),         UINT16_MAX,         UINT16_MAX,         UINT16_MAX,         UINT16_MAX  },
      {  UINT16_C(  38100),  UINT16_C(  35761),  UINT16_C(   3837),  UINT16_C(   5494),  UINT16_C(  54717),  UINT16_C(  14134),  UINT16_C(  55430),  UINT16_C(  45709)  } },
    { {  UINT32_C( 340008151),  UINT32_C(1376253756),  UINT32_C(3971226977),  UINT32_C(1406890267) },
      {  UINT16_C(  11711),  UINT16_C(   5240),  UINT16_C(  24173),  UINT16_C(  29531)  },
      {  UINT16_C(  11711),  UINT16_C(   5240),  UINT16_C(  24173),  UINT16_C(  29531),         UINT16_MAX,         UINT16_MAX,         UINT16_MAX,         UINT16_MAX  },
      {  UINT16_C(  11711),  UINT16_C(   5240),  UINT16_C(  24173),  UINT16_C(  29531),         UINT16_MAX,         UINT16_MAX,         UINT16_MAX,         UINT16_MAX  },
      {  UINT16_C(  11711),  UINT16_C(   5240),  UINT16_C(  24173),  UINT16_C(  29531),         UINT16_MAX,         UINT16_MAX,         UINT16_MAX,         UINT16_MAX  },
      {  UINT16_C(  11711),  UINT16_C(   5240),  UINT16_C(  24173),  UINT16_C(  29531),  UINT16_C(  41505),         UINT16_MAX,         UINT16_MAX,         UINT16_MAX  },
      {  UINT16_C(  11711),  UINT16_C(   5240),  UINT16_C(  24173),  UINT16_C(  29531),  UINT16_C(   5188),  UINT16_C(  21000),  UINT16_C(  60596),  UINT16_C(  21467)  } },
    { {  UINT32_C( 421449578),  UINT32_C(3134076478),  UINT32_C(3574088918),  UINT32_C(2882483406) },
      {  UINT16_C(  31960),  UINT16_C(  39737),  UINT16_C(  30571),  UINT16_C(  33065)  },
      {  UINT16_C(  31960),  UINT16_C(  39737),  UINT16_C(  30571),  UINT16_C(  33065),         UINT16_MAX,         UINT16_MAX,         UINT16_MAX,         UINT16_MAX  },
      {  UINT16_C(  31960),  UINT16_C(  39737),  UINT16_C(  30571),  UINT16_C(  33065),         UINT16_MAX,         UINT16_MAX,         UINT16_MAX,         UINT16_MAX  },
      {  UINT16_C(  31960),  UINT16_C(  39737),  UINT16_C(  30571),  UINT16_C(  33065),         UINT16_MAX,         UINT16_MAX,         UINT16_MAX,         UINT16_MAX  },
      {  UINT16_C(  31960),  UINT16_C(  39737),  UINT16_C(  30571),  UINT16_C(  33065),  UINT16_C(  51446),         UINT16_MAX,         UINT16_MAX,         UINT16_MAX  },
      {  UINT16_C(  31960),  UINT16_C(  39737),  UINT16_C(  30571),  UINT16_C(  33065),  UINT16_C(   6431),  UINT16_C(  47822),  UINT16_C(  54536),  UINT16_C(  43983)  } },
    { {  UINT32_C( 583537289),  UINT32_C( 434301634),  UINT32_C(1444419016),  UINT32_C(3837079129) },
      {  UINT16_C(  35705),  UINT16_C(  32452),  UINT16_C(  10162),  UINT16_C(   9715)  },
      {  UINT16_C(  35705),  UINT16_C(  32452),  UINT16_C(  10162),  UINT16_C(   9715),         UINT16_MAX,         UINT16_MAX,         UINT16_MAX,         UINT16_MAX  },
      {  UINT16_C(  35705),  UINT16_C(  32452),  UINT16_C(  10162),  UINT16_C(   9715),         UINT16_MAX,         UINT16_MAX,         UINT16_MAX,         UINT16_MAX  },
      {  UINT16_C(  35705),  UINT16_C(  32452),  UINT16_C(  10162),  UINT16_C(   9715),         UINT16_MAX,         UINT16_MAX,         UINT16_MAX,         UINT16_MAX  },
      {  UINT16_C(  35705),  UINT16_C(  32452),  UINT16_C(  10162),  UINT16_C(   9715),         UINT16_MAX,  UINT16_C(  53015),         UINT16_MAX,         UINT16_MAX  },
      {  UINT16_C(  35705),  UINT16_C(  32452),  UINT16_C(  10162),  UINT16_C(   9715),  UINT16_C(   8904),  UINT16_C(   6627),  UINT16_C(  22040),  UINT16_C(  58549)  } },
    { {  UINT32_C(1525121211),  UINT32_C(  50780994),  UINT32_C(3903631585),  UINT32_C(2029273804) },
      {  UINT16_C(  13555),  UINT16_C(   7478),  UINT16_C(  21263),  UINT16_C(  64627)  },
      {  UINT16_C(  13555),  UINT16_C(   7478),  UINT16_C(  21263),  UINT16_C(  64627),         UINT16_MAX,         UINT16_MAX,         UINT16_MAX,         UINT16_MAX  },
      {  UINT16_C(  13555),  UINT16_C(   7478),  UINT16_C(  21263),  UINT16_C(  64627),         UINT16_MAX,         UINT16_MAX,         UINT16_MAX,         UINT16_MAX  },
      {  UINT16_C(  13555),  UINT16_C(   7478),  UINT16_C(  21263),  UINT16_C(  64627),         UINT16_MAX,  UINT16_C(  49591),         UINT16_MAX,         UINT16_MAX  },
      {  UINT16_C(  13555),  UINT16_C(   7478),  UINT16_C(  21263),  UINT16_C(  64627),         UINT16_MAX,  UINT16_C(   6199),         UINT16_MAX,         UINT16_MAX  },
      {  UINT16_C(  13555),  UINT16_C(   7478),  UINT16_C(  21263),  UINT16_C(  64627),  UINT16_C(  23272),  UINT16_C(    775),  UINT16_C(  59565),  UINT16_C(  30964)  } },
    { {  UINT32_C(3426504747),  UINT32_C(2501582580),  UINT32_C(3527744463),  UINT32_C(3789559335) },
      {  UINT16_C(  21127),  UINT16_C(  62248),  UINT16_C(  28059),  UINT16_C(   2777)  },
      {  UINT16_C(  21127),  UINT16_C(  62248),  UINT16_C(  28059),  UINT16_C(   2777),         UINT16_MAX,         UINT16_MAX,         UINT16_MAX,         UINT16_MAX  },
      {  UINT16_C(  21127),  UINT16_C(  62248),  UINT16_C(  28059),  UINT16_C(   2777),         UINT16_MAX,         UINT16_MAX,         UINT16_MAX,         UINT16_MAX  },
      {  UINT16_C(  21127),  UINT16_C(  62248),  UINT16_C(  28059),  UINT16_C(   2777),         UINT16_MAX,         UINT16_MAX,         UINT16_MAX,         UINT16_MAX  },
      {  UINT16_C(  21127),  UINT16_C(  62248),  UINT16_C(  28059),  UINT16_C(   2777),         UINT16_MAX,         UINT16_MAX,         UINT16_MAX,         UINT16_MAX  },
      {  UINT16_C(  21127),  UINT16_C(  62248),  UINT16_C(  28059),  UINT16_C(   2777),  UINT16_C(  52284),  UINT16_C(  38171),  UINT16_C(  53829),  UINT16_C(  57824)  } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint16x4_t r = simde_vld1_u16(test_vec[i].r);

    simde_uint16x8_t r3 = simde_vqrshrn_high_n_u32(r, a, 3);
    simde_uint16x8_t r6 = simde_vqrshrn_high_n_u32(r, a, 6);
    simde_uint16x8_t r10 = simde_vqrshrn_high_n_u32(r, a, 10);
    simde_uint16x8_t r13 = simde_vqrshrn_high_n_u32(r, a, 13);
    simde_uint16x8_t r16 = simde_vqrshrn_high_n_u32(r, a, 16);

    simde_test_arm_neon_assert_equal_u16x8(r3, simde_vld1q_u16(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_u16x8(r6, simde_vld1q_u16(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_u16x8(r10, simde_vld1q_u16(test_vec[i].r10));
    simde_test_arm_neon_assert_equal_u16x8(r13, simde_vld1q_u16(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_u16x8(r16, simde_vld1q_u16(test_vec[i].r16));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x4_t a = simde_test_arm_neon_random_u32x4();
    simde_uint16x4_t r = simde_test_arm_neon_random_u16x4();
    simde_uint16x8_t r3 = simde_vqrshrn_high_n_u32(r, a, 3);
    simde_uint16x8_t r6 = simde_vqrshrn_high_n_u32(r, a, 6);
    simde_uint16x8_t r10 = simde_vqrshrn_high_n_u32(r, a, 10);
    simde_uint16x8_t r13 = simde_vqrshrn_high_n_u32(r, a, 13);
    simde_uint16x8_t r16 = simde_vqrshrn_high_n_u32(r, a, 16);

    simde_test_arm_neon_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x4(2, r, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r6, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r10, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r16, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}


static int
test_simde_vqrshrn_high_n_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a[2];
    uint32_t r[2];
    uint32_t r6[4];
    uint32_t r13[4];
    uint32_t r19[4];
    uint32_t r26[4];
    uint32_t r32[4];
  } test_vec[] = {
    { {  UINT64_C(7203098596803566357),  UINT64_C(7876275415649177280) },
      {  UINT32_C( 3637702956),  UINT32_C( 1215937871)  },
      {  UINT32_C( 3637702956),  UINT32_C( 1215937871),             UINT32_MAX,             UINT32_MAX  },
      {  UINT32_C( 3637702956),  UINT32_C( 1215937871),             UINT32_MAX,             UINT32_MAX  },
      {  UINT32_C( 3637702956),  UINT32_C( 1215937871),             UINT32_MAX,             UINT32_MAX  },
      {  UINT32_C( 3637702956),  UINT32_C( 1215937871),             UINT32_MAX,             UINT32_MAX  },
      {  UINT32_C( 3637702956),  UINT32_C( 1215937871),  UINT32_C( 1677102083),  UINT32_C( 1833838275)  } },
    { {  UINT64_C(3581476421860816228),  UINT64_C(9270783597829440304) },
      {  UINT32_C( 1646634326),  UINT32_C(  245511145)  },
      {  UINT32_C( 1646634326),  UINT32_C(  245511145),             UINT32_MAX,             UINT32_MAX  },
      {  UINT32_C( 1646634326),  UINT32_C(  245511145),             UINT32_MAX,             UINT32_MAX  },
      {  UINT32_C( 1646634326),  UINT32_C(  245511145),             UINT32_MAX,             UINT32_MAX  },
      {  UINT32_C( 1646634326),  UINT32_C(  245511145),             UINT32_MAX,             UINT32_MAX  },
      {  UINT32_C( 1646634326),  UINT32_C(  245511145),  UINT32_C(  833877461),  UINT32_C( 2158522512)  } },
    { {  UINT64_C(2090022547083456224),  UINT64_C(11194466363031690243) },
      {  UINT32_C(  287061320),  UINT32_C( 1554413028)  },
      {  UINT32_C(  287061320),  UINT32_C( 1554413028),             UINT32_MAX,             UINT32_MAX  },
      {  UINT32_C(  287061320),  UINT32_C( 1554413028),             UINT32_MAX,             UINT32_MAX  },
      {  UINT32_C(  287061320),  UINT32_C( 1554413028),             UINT32_MAX,             UINT32_MAX  },
      {  UINT32_C(  287061320),  UINT32_C( 1554413028),             UINT32_MAX,             UINT32_MAX  },
      {  UINT32_C(  287061320),  UINT32_C( 1554413028),  UINT32_C(  486621295),  UINT32_C( 2606414809)  } },
    { {  UINT64_C(13755076121551726691),  UINT64_C(12745973165242992493) },
      {  UINT32_C( 1937771326),  UINT32_C( 1133803333)  },
      {  UINT32_C( 1937771326),  UINT32_C( 1133803333),             UINT32_MAX,             UINT32_MAX  },
      {  UINT32_C( 1937771326),  UINT32_C( 1133803333),             UINT32_MAX,             UINT32_MAX  },
      {  UINT32_C( 1937771326),  UINT32_C( 1133803333),             UINT32_MAX,             UINT32_MAX  },
      {  UINT32_C( 1937771326),  UINT32_C( 1133803333),             UINT32_MAX,             UINT32_MAX  },
      {  UINT32_C( 1937771326),  UINT32_C( 1133803333),  UINT32_C( 3202603227),  UINT32_C( 2967653136)  } },
    { {  UINT64_C(7457958405694239083),  UINT64_C(12033233808983669995) },
      {  UINT32_C( 2159049551),  UINT32_C( 1055810932)  },
      {  UINT32_C( 2159049551),  UINT32_C( 1055810932),             UINT32_MAX,             UINT32_MAX  },
      {  UINT32_C( 2159049551),  UINT32_C( 1055810932),             UINT32_MAX,             UINT32_MAX  },
      {  UINT32_C( 2159049551),  UINT32_C( 1055810932),             UINT32_MAX,             UINT32_MAX  },
      {  UINT32_C( 2159049551),  UINT32_C( 1055810932),             UINT32_MAX,             UINT32_MAX  },
      {  UINT32_C( 2159049551),  UINT32_C( 1055810932),  UINT32_C( 1736441256),  UINT32_C( 2801705573)  } },
    { {  UINT64_C(18146717995352602586),  UINT64_C(6450929778631403120) },
      {  UINT32_C( 3226552088),  UINT32_C(  732607272)  },
      {  UINT32_C( 3226552088),  UINT32_C(  732607272),             UINT32_MAX,             UINT32_MAX  },
      {  UINT32_C( 3226552088),  UINT32_C(  732607272),             UINT32_MAX,             UINT32_MAX  },
      {  UINT32_C( 3226552088),  UINT32_C(  732607272),             UINT32_MAX,             UINT32_MAX  },
      {  UINT32_C( 3226552088),  UINT32_C(  732607272),             UINT32_MAX,             UINT32_MAX  },
      {  UINT32_C( 3226552088),  UINT32_C(  732607272),  UINT32_C( 4225112031),  UINT32_C( 1501974133)  } },
    { {  UINT64_C(10272196743332054363),  UINT64_C(6156165500414793683) },
      {  UINT32_C(  535844076),  UINT32_C( 3274829162)  },
      {  UINT32_C(  535844076),  UINT32_C( 3274829162),             UINT32_MAX,             UINT32_MAX  },
      {  UINT32_C(  535844076),  UINT32_C( 3274829162),             UINT32_MAX,             UINT32_MAX  },
      {  UINT32_C(  535844076),  UINT32_C( 3274829162),             UINT32_MAX,             UINT32_MAX  },
      {  UINT32_C(  535844076),  UINT32_C( 3274829162),             UINT32_MAX,             UINT32_MAX  },
      {  UINT32_C(  535844076),  UINT32_C( 3274829162),  UINT32_C( 2391682179),  UINT32_C( 1433343976)  } },
    { {  UINT64_C(6350607551009767646),  UINT64_C(13198785150916825998) },
      {  UINT32_C( 2487826802),  UINT32_C( 2586560249)  },
      {  UINT32_C( 2487826802),  UINT32_C( 2586560249),             UINT32_MAX,             UINT32_MAX  },
      {  UINT32_C( 2487826802),  UINT32_C( 2586560249),             UINT32_MAX,             UINT32_MAX  },
      {  UINT32_C( 2487826802),  UINT32_C( 2586560249),             UINT32_MAX,             UINT32_MAX  },
      {  UINT32_C( 2487826802),  UINT32_C( 2586560249),             UINT32_MAX,             UINT32_MAX  },
      {  UINT32_C( 2487826802),  UINT32_C( 2586560249),  UINT32_C( 1478616044),  UINT32_C( 3073081642)  } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x2_t a = simde_vld1q_u64(test_vec[i].a);
    simde_uint32x2_t r = simde_vld1_u32(test_vec[i].r);

    simde_uint32x4_t r6 = simde_vqrshrn_high_n_u64(r, a, 6);
    simde_uint32x4_t r13 = simde_vqrshrn_high_n_u64(r, a, 13);
    simde_uint32x4_t r19 = simde_vqrshrn_high_n_u64(r, a, 19);
    simde_uint32x4_t r26 = simde_vqrshrn_high_n_u64(r, a, 26);
    simde_uint32x4_t r32 = simde_vqrshrn_high_n_u64(r, a, 32);

    simde_test_arm_neon_assert_equal_u32x4(r6, simde_vld1q_u32(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_u32x4(r13, simde_vld1q_u32(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_u32x4(r19, simde_vld1q_u32(test_vec[i].r19));
    simde_test_arm_neon_assert_equal_u32x4(r26, simde_vld1q_u32(test_vec[i].r26));
    simde_test_arm_neon_assert_equal_u32x4(r32, simde_vld1q_u32(test_vec[i].r32));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint64x2_t a = simde_test_arm_neon_random_u64x2();
    simde_uint32x2_t r = simde_test_arm_neon_random_u32x2();
    simde_uint32x4_t r6 = simde_vqrshrn_high_n_u64(r, a, 6);
    simde_uint32x4_t r13 = simde_vqrshrn_high_n_u64(r, a, 13);
    simde_uint32x4_t r19 = simde_vqrshrn_high_n_u64(r, a, 19);
    simde_uint32x4_t r26 = simde_vqrshrn_high_n_u64(r, a, 26);
    simde_uint32x4_t r32 = simde_vqrshrn_high_n_u64(r, a, 32);

    simde_test_arm_neon_write_u64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x2(2, r, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r6, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r19, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r26, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r32, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vqrshrn_high_n_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqrshrn_high_n_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vqrshrn_high_n_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vqrshrn_high_n_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqrshrn_high_n_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vqrshrn_high_n_u64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
