#define SIMDE_TEST_ARM_NEON_INSN ld2_lane

#include "test-neon.h"
#include "../../../simde/arm/neon/ld2_lane.h"
#include "../../../simde/arm/neon/ld1.h"
#include "../../../simde/arm/neon/ld2.h"

static int
test_simde_vld2_lane_s8 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int8_t src[2][8];
    int8_t buf[2];
    int8_t r[2][8];
  } test_vec[] = {
   { { {  -INT8_C(16), INT8_C(44), -INT8_C(6), INT8_C(49),
        -INT8_C(48), -INT8_C(22), INT8_C(4), INT8_C(6) },
       {  -INT8_C(7), INT8_C(40), -INT8_C(17), INT8_C(15),
        -INT8_C(21), -INT8_C(4), INT8_C(14), -INT8_C(25) } },
       {  INT8_C(43), -INT8_C(26)},
     { {  INT8_C(43), INT8_C(44), -INT8_C(6), INT8_C(49),
        -INT8_C(48), -INT8_C(22), INT8_C(4), INT8_C(6) },
       {  -INT8_C(26), INT8_C(40), -INT8_C(17), INT8_C(15),
        -INT8_C(21), -INT8_C(4), INT8_C(14), -INT8_C(25) } } },
   { { {  INT8_C(0), -INT8_C(47), INT8_C(9), INT8_C(28),
        -INT8_C(8), -INT8_C(39), -INT8_C(37), INT8_C(35) },
       {  INT8_C(38), INT8_C(35), INT8_C(27), -INT8_C(16),
        INT8_C(14), -INT8_C(1), -INT8_C(16), INT8_C(5) } },
       {  -INT8_C(48), INT8_C(10)},
     { {  INT8_C(0), -INT8_C(48), INT8_C(9), INT8_C(28),
        -INT8_C(8), -INT8_C(39), -INT8_C(37), INT8_C(35) },
       {  INT8_C(38), INT8_C(10), INT8_C(27), -INT8_C(16),
        INT8_C(14), -INT8_C(1), -INT8_C(16), INT8_C(5) } } },
   { { {  -INT8_C(45), -INT8_C(48), -INT8_C(30), -INT8_C(12),
        INT8_C(2), INT8_C(21), INT8_C(16), INT8_C(39) },
       {  -INT8_C(3), INT8_C(30), -INT8_C(37), -INT8_C(12),
        INT8_C(17), INT8_C(23), -INT8_C(41), INT8_C(18) } },
       {  -INT8_C(30), -INT8_C(13)},
     { {  -INT8_C(45), -INT8_C(48), -INT8_C(30), -INT8_C(12),
        INT8_C(2), INT8_C(21), INT8_C(16), INT8_C(39) },
       {  -INT8_C(3), INT8_C(30), -INT8_C(13), -INT8_C(12),
        INT8_C(17), INT8_C(23), -INT8_C(41), INT8_C(18) } } },
   { { {  -INT8_C(9), -INT8_C(39), INT8_C(49), -INT8_C(10),
        -INT8_C(45), INT8_C(24), -INT8_C(17), INT8_C(30) },
       {  -INT8_C(36), INT8_C(20), -INT8_C(15), -INT8_C(21),
        -INT8_C(23), INT8_C(22), -INT8_C(39), -INT8_C(18) } },
       {  INT8_C(13), -INT8_C(37)},
     { {  -INT8_C(9), -INT8_C(39), INT8_C(49), INT8_C(13),
        -INT8_C(45), INT8_C(24), -INT8_C(17), INT8_C(30) },
       {  -INT8_C(36), INT8_C(20), -INT8_C(15), -INT8_C(37),
        -INT8_C(23), INT8_C(22), -INT8_C(39), -INT8_C(18) } } },
   { { {  INT8_C(17), INT8_C(17), -INT8_C(11), INT8_C(43),
        -INT8_C(20), -INT8_C(10), INT8_C(44), INT8_C(43) },
       {  INT8_C(23), -INT8_C(4), -INT8_C(32), -INT8_C(2),
        -INT8_C(39), -INT8_C(1), -INT8_C(37), INT8_C(42) } },
       {  -INT8_C(40), INT8_C(34)},
     { {  INT8_C(17), INT8_C(17), -INT8_C(11), INT8_C(43),
        -INT8_C(40), -INT8_C(10), INT8_C(44), INT8_C(43) },
       {  INT8_C(23), -INT8_C(4), -INT8_C(32), -INT8_C(2),
        INT8_C(34), -INT8_C(1), -INT8_C(37), INT8_C(42) } } },
   { { {  INT8_C(16), INT8_C(35), -INT8_C(33), -INT8_C(19),
        INT8_C(15), -INT8_C(17), INT8_C(13), -INT8_C(49) },
       {  INT8_C(21), -INT8_C(24), -INT8_C(3), INT8_C(10),
        -INT8_C(31), INT8_C(24), -INT8_C(46), -INT8_C(14) } },
       {  -INT8_C(24), -INT8_C(3)},
     { {  INT8_C(16), INT8_C(35), -INT8_C(33), -INT8_C(19),
        INT8_C(15), -INT8_C(24), INT8_C(13), -INT8_C(49) },
       {  INT8_C(21), -INT8_C(24), -INT8_C(3), INT8_C(10),
        -INT8_C(31), -INT8_C(3), -INT8_C(46), -INT8_C(14) } } },
   { { {  INT8_C(25), -INT8_C(9), -INT8_C(16), INT8_C(33),
        -INT8_C(14), -INT8_C(45), INT8_C(0), -INT8_C(45) },
       {  -INT8_C(40), INT8_C(36), INT8_C(38), -INT8_C(48),
        -INT8_C(20), -INT8_C(22), INT8_C(1), -INT8_C(43) } },
       {  -INT8_C(33), -INT8_C(50)},
     { {  INT8_C(25), -INT8_C(9), -INT8_C(16), INT8_C(33),
        -INT8_C(14), -INT8_C(45), -INT8_C(33), -INT8_C(45) },
       {  -INT8_C(40), INT8_C(36), INT8_C(38), -INT8_C(48),
        -INT8_C(20), -INT8_C(22), -INT8_C(50), -INT8_C(43) } } },
   { { {  INT8_C(38), -INT8_C(16), INT8_C(32), -INT8_C(48),
        INT8_C(28), -INT8_C(6), -INT8_C(48), -INT8_C(36) },
       {  INT8_C(12), INT8_C(7), -INT8_C(12), -INT8_C(12),
        INT8_C(33), INT8_C(28), INT8_C(26), -INT8_C(43) } },
       {  -INT8_C(42), -INT8_C(7)},
     { {  INT8_C(38), -INT8_C(16), INT8_C(32), -INT8_C(48),
        INT8_C(28), -INT8_C(6), -INT8_C(48), -INT8_C(42) },
       {  INT8_C(12), INT8_C(7), -INT8_C(12), -INT8_C(12),
        INT8_C(33), INT8_C(28), INT8_C(26), -INT8_C(7) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8x2_t r, src, expected;
    src.val[0] = simde_vld1_s8(test_vec[i].src[0]);
    src.val[1] = simde_vld1_s8(test_vec[i].src[1]);

    SIMDE_CONSTIFY_8_(simde_vld2_lane_s8, r, (HEDLEY_UNREACHABLE(), r), i, test_vec[i].buf, src);

    expected.val[0] = simde_vld1_s8(test_vec[i].r[0]);
    expected.val[1] = simde_vld1_s8(test_vec[i].r[1]);

    simde_test_arm_neon_assert_equal_i8x8(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_i8x8(r.val[1], expected.val[1]);
  }

  return 0;
}

static int
test_simde_vld2_lane_s16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int16_t src[2][4];
    int16_t buf[2];
    int16_t r[2][4];
  } test_vec[] = {
   { { {  INT16_C(124), INT16_C(412), -INT16_C(312), -INT16_C(107) },
       {  INT16_C(349), INT16_C(217), INT16_C(241), INT16_C(95) } },
       {  -INT16_C(275), INT16_C(317)},
     { {  -INT16_C(275), INT16_C(412), -INT16_C(312), -INT16_C(107) },
       {  INT16_C(317), INT16_C(217), INT16_C(241), INT16_C(95) } } },
   { { {  INT16_C(378), INT16_C(448), -INT16_C(60), -INT16_C(474) },
       {  INT16_C(266), -INT16_C(135), INT16_C(422), INT16_C(223) } },
       {  INT16_C(297), INT16_C(5)},
     { {  INT16_C(378), INT16_C(297), -INT16_C(60), -INT16_C(474) },
       {  INT16_C(266), INT16_C(5), INT16_C(422), INT16_C(223) } } },
   { { {  -INT16_C(197), INT16_C(3), -INT16_C(245), INT16_C(218) },
       {  -INT16_C(216), -INT16_C(262), INT16_C(180), -INT16_C(60) } },
       {  -INT16_C(96), INT16_C(492)},
     { {  -INT16_C(197), INT16_C(3), -INT16_C(96), INT16_C(218) },
       {  -INT16_C(216), -INT16_C(262), INT16_C(492), -INT16_C(60) } } },
   { { {  -INT16_C(395), INT16_C(374), -INT16_C(448), -INT16_C(445) },
       {  INT16_C(60), INT16_C(486), -INT16_C(283), INT16_C(298) } },
       {  INT16_C(218), INT16_C(225)},
     { {  -INT16_C(395), INT16_C(374), -INT16_C(448), INT16_C(218) },
       {  INT16_C(60), INT16_C(486), -INT16_C(283), INT16_C(225) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4x2_t r, src, expected;
    src.val[0] = simde_vld1_s16(test_vec[i].src[0]);
    src.val[1] = simde_vld1_s16(test_vec[i].src[1]);

    SIMDE_CONSTIFY_4_(simde_vld2_lane_s16, r, (HEDLEY_UNREACHABLE(), r), i, test_vec[i].buf, src);

    expected.val[0] = simde_vld1_s16(test_vec[i].r[0]);
    expected.val[1] = simde_vld1_s16(test_vec[i].r[1]);

    simde_test_arm_neon_assert_equal_i16x4(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_i16x4(r.val[1], expected.val[1]);
  }

  return 0;
}

static int
test_simde_vld2_lane_s32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int32_t src[2][2];
    int32_t buf[2];
    int32_t r[2][2];
  } test_vec[] = {
   { { {  -INT32_C(617), INT32_C(1303) },
       {  -INT32_C(4779), -INT32_C(4756) } },
       {  INT32_C(4193), -INT32_C(4032)},
     { {  INT32_C(4193), INT32_C(1303) },
       {  -INT32_C(4032), -INT32_C(4756) } } },
   { { {  -INT32_C(1012), -INT32_C(3240) },
       {  -INT32_C(3259), -INT32_C(3396) } },
       {  -INT32_C(3438), -INT32_C(693)},
     { {  -INT32_C(1012), -INT32_C(3438) },
       {  -INT32_C(3259), -INT32_C(693) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2x2_t r, src, expected;
    src.val[0] = simde_vld1_s32(test_vec[i].src[0]);
    src.val[1] = simde_vld1_s32(test_vec[i].src[1]);

    SIMDE_CONSTIFY_2_(simde_vld2_lane_s32, r, (HEDLEY_UNREACHABLE(), r), i, test_vec[i].buf, src);

    expected.val[0] = simde_vld1_s32(test_vec[i].r[0]);
    expected.val[1] = simde_vld1_s32(test_vec[i].r[1]);

    simde_test_arm_neon_assert_equal_i32x2(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_i32x2(r.val[1], expected.val[1]);
  }

  return 0;
}

static int
test_simde_vld2_lane_s64 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int64_t src[2][1];
    int64_t buf[2];
    int64_t r[2][1];
  } test_vec[] = {
   { { {  -INT64_C(382464207) },
       {  -INT64_C(391984763) } },
       {  -INT64_C(283052241), INT64_C(176704794)},
     { {  -INT64_C(283052241) },
       {  INT64_C(176704794) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x1x2_t r, src, expected;
    src.val[0] = simde_vld1_s64(test_vec[i].src[0]);
    src.val[1] = simde_vld1_s64(test_vec[i].src[1]);

    r = simde_vld2_lane_s64(test_vec[i].buf, src, 0);

    expected.val[0] = simde_vld1_s64(test_vec[i].r[0]);
    expected.val[1] = simde_vld1_s64(test_vec[i].r[1]);

    simde_test_arm_neon_assert_equal_i64x1(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_i64x1(r.val[1], expected.val[1]);
  }

  return 0;
}


static int
test_simde_vld2_lane_u8 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    uint8_t src[2][8];
    uint8_t buf[2];
    uint8_t r[2][8];
  } test_vec[] = {
   { { {   UINT8_C(16), UINT8_C(44),  UINT8_C(6), UINT8_C(49),
         UINT8_C(48),  UINT8_C(22), UINT8_C(4), UINT8_C(6) },
       {   UINT8_C(7), UINT8_C(40),  UINT8_C(17), UINT8_C(15),
         UINT8_C(21),  UINT8_C(4), UINT8_C(14),  UINT8_C(25) } },
       {  UINT8_C(43),  UINT8_C(26)},
     { {  UINT8_C(43), UINT8_C(44),  UINT8_C(6), UINT8_C(49),
         UINT8_C(48),  UINT8_C(22), UINT8_C(4), UINT8_C(6) },
       {   UINT8_C(26), UINT8_C(40),  UINT8_C(17), UINT8_C(15),
         UINT8_C(21),  UINT8_C(4), UINT8_C(14),  UINT8_C(25) } } },
   { { {  UINT8_C(0),  UINT8_C(47), UINT8_C(9), UINT8_C(28),
         UINT8_C(8),  UINT8_C(39),  UINT8_C(37), UINT8_C(35) },
       {  UINT8_C(38), UINT8_C(35), UINT8_C(27),  UINT8_C(16),
        UINT8_C(14),  UINT8_C(1),  UINT8_C(16), UINT8_C(5) } },
       {   UINT8_C(48), UINT8_C(10)},
     { {  UINT8_C(0),  UINT8_C(48), UINT8_C(9), UINT8_C(28),
         UINT8_C(8),  UINT8_C(39),  UINT8_C(37), UINT8_C(35) },
       {  UINT8_C(38), UINT8_C(10), UINT8_C(27),  UINT8_C(16),
        UINT8_C(14),  UINT8_C(1),  UINT8_C(16), UINT8_C(5) } } },
   { { {   UINT8_C(45),  UINT8_C(48),  UINT8_C(30),  UINT8_C(12),
        UINT8_C(2), UINT8_C(21), UINT8_C(16), UINT8_C(39) },
       {   UINT8_C(3), UINT8_C(30),  UINT8_C(37),  UINT8_C(12),
        UINT8_C(17), UINT8_C(23),  UINT8_C(41), UINT8_C(18) } },
       {   UINT8_C(30),  UINT8_C(13)},
     { {   UINT8_C(45),  UINT8_C(48),  UINT8_C(30),  UINT8_C(12),
        UINT8_C(2), UINT8_C(21), UINT8_C(16), UINT8_C(39) },
       {   UINT8_C(3), UINT8_C(30),  UINT8_C(13),  UINT8_C(12),
        UINT8_C(17), UINT8_C(23),  UINT8_C(41), UINT8_C(18) } } },
   { { {   UINT8_C(9),  UINT8_C(39), UINT8_C(49),  UINT8_C(10),
         UINT8_C(45), UINT8_C(24),  UINT8_C(17), UINT8_C(30) },
       {   UINT8_C(36), UINT8_C(20),  UINT8_C(15),  UINT8_C(21),
         UINT8_C(23), UINT8_C(22),  UINT8_C(39),  UINT8_C(18) } },
       {  UINT8_C(13),  UINT8_C(37)},
     { {   UINT8_C(9),  UINT8_C(39), UINT8_C(49), UINT8_C(13),
         UINT8_C(45), UINT8_C(24),  UINT8_C(17), UINT8_C(30) },
       {   UINT8_C(36), UINT8_C(20),  UINT8_C(15),  UINT8_C(37),
         UINT8_C(23), UINT8_C(22),  UINT8_C(39),  UINT8_C(18) } } },
   { { {  UINT8_C(17), UINT8_C(17),  UINT8_C(11), UINT8_C(43),
         UINT8_C(20),  UINT8_C(10), UINT8_C(44), UINT8_C(43) },
       {  UINT8_C(23),  UINT8_C(4),  UINT8_C(32),  UINT8_C(2),
         UINT8_C(39),  UINT8_C(1),  UINT8_C(37), UINT8_C(42) } },
       {   UINT8_C(40), UINT8_C(34)},
     { {  UINT8_C(17), UINT8_C(17),  UINT8_C(11), UINT8_C(43),
         UINT8_C(40),  UINT8_C(10), UINT8_C(44), UINT8_C(43) },
       {  UINT8_C(23),  UINT8_C(4),  UINT8_C(32),  UINT8_C(2),
        UINT8_C(34),  UINT8_C(1),  UINT8_C(37), UINT8_C(42) } } },
   { { {  UINT8_C(16), UINT8_C(35),  UINT8_C(33),  UINT8_C(19),
        UINT8_C(15),  UINT8_C(17), UINT8_C(13),  UINT8_C(49) },
       {  UINT8_C(21),  UINT8_C(24),  UINT8_C(3), UINT8_C(10),
         UINT8_C(31), UINT8_C(24),  UINT8_C(46),  UINT8_C(14) } },
       {   UINT8_C(24),  UINT8_C(3)},
     { {  UINT8_C(16), UINT8_C(35),  UINT8_C(33),  UINT8_C(19),
        UINT8_C(15),  UINT8_C(24), UINT8_C(13),  UINT8_C(49) },
       {  UINT8_C(21),  UINT8_C(24),  UINT8_C(3), UINT8_C(10),
         UINT8_C(31),  UINT8_C(3),  UINT8_C(46),  UINT8_C(14) } } },
   { { {  UINT8_C(25),  UINT8_C(9),  UINT8_C(16), UINT8_C(33),
         UINT8_C(14),  UINT8_C(45), UINT8_C(0),  UINT8_C(45) },
       {   UINT8_C(40), UINT8_C(36), UINT8_C(38),  UINT8_C(48),
         UINT8_C(20),  UINT8_C(22), UINT8_C(1),  UINT8_C(43) } },
       {   UINT8_C(33),  UINT8_C(50)},
     { {  UINT8_C(25),  UINT8_C(9),  UINT8_C(16), UINT8_C(33),
         UINT8_C(14),  UINT8_C(45),  UINT8_C(33),  UINT8_C(45) },
       {   UINT8_C(40), UINT8_C(36), UINT8_C(38),  UINT8_C(48),
         UINT8_C(20),  UINT8_C(22),  UINT8_C(50),  UINT8_C(43) } } },
   { { {  UINT8_C(38),  UINT8_C(16), UINT8_C(32),  UINT8_C(48),
        UINT8_C(28),  UINT8_C(6),  UINT8_C(48),  UINT8_C(36) },
       {  UINT8_C(12), UINT8_C(7),  UINT8_C(12),  UINT8_C(12),
        UINT8_C(33), UINT8_C(28), UINT8_C(26),  UINT8_C(43) } },
       {   UINT8_C(42),  UINT8_C(7)},
     { {  UINT8_C(38),  UINT8_C(16), UINT8_C(32),  UINT8_C(48),
        UINT8_C(28),  UINT8_C(6),  UINT8_C(48),  UINT8_C(42) },
       {  UINT8_C(12), UINT8_C(7),  UINT8_C(12),  UINT8_C(12),
        UINT8_C(33), UINT8_C(28), UINT8_C(26),  UINT8_C(7) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x8x2_t r, src, expected;
    src.val[0] = simde_vld1_u8(test_vec[i].src[0]);
    src.val[1] = simde_vld1_u8(test_vec[i].src[1]);

    SIMDE_CONSTIFY_8_(simde_vld2_lane_u8, r, (HEDLEY_UNREACHABLE(), r), i, test_vec[i].buf, src);

    expected.val[0] = simde_vld1_u8(test_vec[i].r[0]);
    expected.val[1] = simde_vld1_u8(test_vec[i].r[1]);

    simde_test_arm_neon_assert_equal_u8x8(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_u8x8(r.val[1], expected.val[1]);
  }

  return 0;
}

static int
test_simde_vld2_lane_u16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    uint16_t src[2][4];
    uint16_t buf[2];
    uint16_t r[2][4];
  } test_vec[] = {
   { { {  UINT16_C(124), UINT16_C(412), UINT16_C(312), UINT16_C(107) },
       {  UINT16_C(349), UINT16_C(217), UINT16_C(241), UINT16_C(95) } },
       {  UINT16_C(275), UINT16_C(317)},
     { {  UINT16_C(275), UINT16_C(412), UINT16_C(312), UINT16_C(107) },
       {  UINT16_C(317), UINT16_C(217), UINT16_C(241), UINT16_C(95) } } },
   { { {  UINT16_C(378), UINT16_C(448), UINT16_C(60), UINT16_C(474) },
       {  UINT16_C(266), UINT16_C(135), UINT16_C(422), UINT16_C(223) } },
       {  UINT16_C(297), UINT16_C(5)},
     { {  UINT16_C(378), UINT16_C(297), UINT16_C(60), UINT16_C(474) },
       {  UINT16_C(266), UINT16_C(5), UINT16_C(422), UINT16_C(223) } } },
   { { {  UINT16_C(197), UINT16_C(3), UINT16_C(245), UINT16_C(218) },
       {  UINT16_C(216), UINT16_C(262), UINT16_C(180), UINT16_C(60) } },
       {  UINT16_C(96), UINT16_C(492)},
     { {  UINT16_C(197), UINT16_C(3), UINT16_C(96), UINT16_C(218) },
       {  UINT16_C(216), UINT16_C(262), UINT16_C(492), UINT16_C(60) } } },
   { { {  UINT16_C(395), UINT16_C(374), UINT16_C(448), UINT16_C(445) },
       {  UINT16_C(60), UINT16_C(486), UINT16_C(283), UINT16_C(298) } },
       {  UINT16_C(218), UINT16_C(225)},
     { {  UINT16_C(395), UINT16_C(374), UINT16_C(448), UINT16_C(218) },
       {  UINT16_C(60), UINT16_C(486), UINT16_C(283), UINT16_C(225) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4x2_t r, src, expected;
    src.val[0] = simde_vld1_u16(test_vec[i].src[0]);
    src.val[1] = simde_vld1_u16(test_vec[i].src[1]);

    SIMDE_CONSTIFY_4_(simde_vld2_lane_u16, r, (HEDLEY_UNREACHABLE(), r), i, test_vec[i].buf, src);

    expected.val[0] = simde_vld1_u16(test_vec[i].r[0]);
    expected.val[1] = simde_vld1_u16(test_vec[i].r[1]);

    simde_test_arm_neon_assert_equal_u16x4(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_u16x4(r.val[1], expected.val[1]);
  }

  return 0;
}

static int
test_simde_vld2_lane_u32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    uint32_t src[2][2];
    uint32_t buf[2];
    uint32_t r[2][2];
  } test_vec[] = {
   { { {  UINT32_C(617), UINT32_C(1303) },
       {  UINT32_C(4779), UINT32_C(4756) } },
       {  UINT32_C(4193), UINT32_C(4032)},
     { {  UINT32_C(4193), UINT32_C(1303) },
       {  UINT32_C(4032), UINT32_C(4756) } } },
   { { {  UINT32_C(1012), UINT32_C(3240) },
       {  UINT32_C(3259), UINT32_C(3396) } },
       {  UINT32_C(3438), UINT32_C(693)},
     { {  UINT32_C(1012), UINT32_C(3438) },
       {  UINT32_C(3259), UINT32_C(693) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2x2_t r, src, expected;
    src.val[0] = simde_vld1_u32(test_vec[i].src[0]);
    src.val[1] = simde_vld1_u32(test_vec[i].src[1]);

    SIMDE_CONSTIFY_2_(simde_vld2_lane_u32, r, (HEDLEY_UNREACHABLE(), r), i, test_vec[i].buf, src);

    expected.val[0] = simde_vld1_u32(test_vec[i].r[0]);
    expected.val[1] = simde_vld1_u32(test_vec[i].r[1]);

    simde_test_arm_neon_assert_equal_u32x2(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_u32x2(r.val[1], expected.val[1]);
  }

  return 0;
}

static int
test_simde_vld2_lane_u64 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    uint64_t src[2][1];
    uint64_t buf[2];
    uint64_t r[2][1];
  } test_vec[] = {
   { { {  UINT64_C(382464207) },
       {  UINT64_C(391984763) } },
       {  UINT64_C(283052241), UINT64_C(176704794)},
     { {  UINT64_C(283052241) },
       {  UINT64_C(176704794) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x1x2_t r, src, expected;
    src.val[0] = simde_vld1_u64(test_vec[i].src[0]);
    src.val[1] = simde_vld1_u64(test_vec[i].src[1]);

    r = simde_vld2_lane_u64(test_vec[i].buf, src, 0);

    expected.val[0] = simde_vld1_u64(test_vec[i].r[0]);
    expected.val[1] = simde_vld1_u64(test_vec[i].r[1]);

    simde_test_arm_neon_assert_equal_u64x1(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_u64x1(r.val[1], expected.val[1]);
  }

  return 0;
}

static int
test_simde_vld2_lane_f16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float16_t src[2][4];
    simde_float16_t buf[2];
    simde_float16_t r[2][4];
  } test_vec[] = {
   { { {  SIMDE_FLOAT16_VALUE(-45.80), SIMDE_FLOAT16_VALUE(29.77), SIMDE_FLOAT16_VALUE(44.10), SIMDE_FLOAT16_VALUE(-17.29) },
       {  SIMDE_FLOAT16_VALUE(-34.30), SIMDE_FLOAT16_VALUE(-46.41), SIMDE_FLOAT16_VALUE(-43.15), SIMDE_FLOAT16_VALUE(-30.34) } },
       {  SIMDE_FLOAT16_VALUE(-16.64), SIMDE_FLOAT16_VALUE(-13.70)},
     { {  SIMDE_FLOAT16_VALUE(-16.64), SIMDE_FLOAT16_VALUE(29.77), SIMDE_FLOAT16_VALUE(44.10), SIMDE_FLOAT16_VALUE(-17.29) },
       {  SIMDE_FLOAT16_VALUE(-13.70), SIMDE_FLOAT16_VALUE(-46.41), SIMDE_FLOAT16_VALUE(-43.15), SIMDE_FLOAT16_VALUE(-30.34) } } },
   { { {  SIMDE_FLOAT16_VALUE(-31.49), SIMDE_FLOAT16_VALUE(-3.02), SIMDE_FLOAT16_VALUE(4.73), SIMDE_FLOAT16_VALUE(29.19) },
       {  SIMDE_FLOAT16_VALUE(-6.51), SIMDE_FLOAT16_VALUE(-6.97), SIMDE_FLOAT16_VALUE(-24.86), SIMDE_FLOAT16_VALUE(20.04) } },
       {  SIMDE_FLOAT16_VALUE(4.78), SIMDE_FLOAT16_VALUE(-24.76)},
     { {  SIMDE_FLOAT16_VALUE(-31.49), SIMDE_FLOAT16_VALUE(4.78), SIMDE_FLOAT16_VALUE(4.73), SIMDE_FLOAT16_VALUE(29.19) },
       {  SIMDE_FLOAT16_VALUE(-6.51), SIMDE_FLOAT16_VALUE(-24.76), SIMDE_FLOAT16_VALUE(-24.86), SIMDE_FLOAT16_VALUE(20.04) } } },
   { { {  SIMDE_FLOAT16_VALUE(-33.05), SIMDE_FLOAT16_VALUE(44.60), SIMDE_FLOAT16_VALUE(44.07), SIMDE_FLOAT16_VALUE(-42.37) },
       {  SIMDE_FLOAT16_VALUE(45.53), SIMDE_FLOAT16_VALUE(4.23), SIMDE_FLOAT16_VALUE(13.47), SIMDE_FLOAT16_VALUE(2.19) } },
       {  SIMDE_FLOAT16_VALUE(-14.88), SIMDE_FLOAT16_VALUE(-15.37)},
     { {  SIMDE_FLOAT16_VALUE(-33.05), SIMDE_FLOAT16_VALUE(44.60), SIMDE_FLOAT16_VALUE(-14.88), SIMDE_FLOAT16_VALUE(-42.37) },
       {  SIMDE_FLOAT16_VALUE(45.53), SIMDE_FLOAT16_VALUE(4.23), SIMDE_FLOAT16_VALUE(-15.37), SIMDE_FLOAT16_VALUE(2.19) } } },
   { { {  SIMDE_FLOAT16_VALUE(22.74), SIMDE_FLOAT16_VALUE(-1.07), SIMDE_FLOAT16_VALUE(48.37), SIMDE_FLOAT16_VALUE(26.68) },
       {  SIMDE_FLOAT16_VALUE(-34.05), SIMDE_FLOAT16_VALUE(-26.07), SIMDE_FLOAT16_VALUE(-44.28), SIMDE_FLOAT16_VALUE(6.92) } },
       {  SIMDE_FLOAT16_VALUE(-28.27), SIMDE_FLOAT16_VALUE(-30.31)},
     { {  SIMDE_FLOAT16_VALUE(22.74), SIMDE_FLOAT16_VALUE(-1.07), SIMDE_FLOAT16_VALUE(48.37), SIMDE_FLOAT16_VALUE(-28.27) },
       {  SIMDE_FLOAT16_VALUE(-34.05), SIMDE_FLOAT16_VALUE(-26.07), SIMDE_FLOAT16_VALUE(-44.28), SIMDE_FLOAT16_VALUE(-30.31) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x4x2_t r, src, expected;
    src.val[0] = simde_vld1_f16(test_vec[i].src[0]);
    src.val[1] = simde_vld1_f16(test_vec[i].src[1]);

    SIMDE_CONSTIFY_4_(simde_vld2_lane_f16, r, (HEDLEY_UNREACHABLE(), r), i, test_vec[i].buf, src);

    expected.val[0] = simde_vld1_f16(test_vec[i].r[0]);
    expected.val[1] = simde_vld1_f16(test_vec[i].r[1]);

    simde_test_arm_neon_assert_equal_f16x4(r.val[0], expected.val[0], INT_MAX);
    simde_test_arm_neon_assert_equal_f16x4(r.val[1], expected.val[1], INT_MAX);
  }

  return 0;
}

static int
test_simde_vld2_lane_f32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    simde_float32_t src[2][2];
    simde_float32_t buf[2];
    simde_float32_t r[2][2];
  } test_vec[] = {
   { { {  SIMDE_FLOAT32_C(1651.66), SIMDE_FLOAT32_C(4335.15) },
       {  SIMDE_FLOAT32_C(3302.66), SIMDE_FLOAT32_C(2212.82) } },
       {  SIMDE_FLOAT32_C(-293.68), SIMDE_FLOAT32_C(4822.66)},
     { {  SIMDE_FLOAT32_C(-293.68), SIMDE_FLOAT32_C(4335.15) },
       {  SIMDE_FLOAT32_C(4822.66), SIMDE_FLOAT32_C(2212.82) } } },
   { { {  SIMDE_FLOAT32_C(-569.07), SIMDE_FLOAT32_C(1299.98) },
       {  SIMDE_FLOAT32_C(2879.02), SIMDE_FLOAT32_C(4991.35) } },
       {  SIMDE_FLOAT32_C(3143.46), SIMDE_FLOAT32_C(2846.67)},
     { {  SIMDE_FLOAT32_C(-569.07), SIMDE_FLOAT32_C(3143.46) },
       {  SIMDE_FLOAT32_C(2879.02), SIMDE_FLOAT32_C(2846.67) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2x2_t r, src, expected;
    src.val[0] = simde_vld1_f32(test_vec[i].src[0]);
    src.val[1] = simde_vld1_f32(test_vec[i].src[1]);

    SIMDE_CONSTIFY_2_(simde_vld2_lane_f32, r, (HEDLEY_UNREACHABLE(), r), i, test_vec[i].buf, src);

    expected.val[0] = simde_vld1_f32(test_vec[i].r[0]);
    expected.val[1] = simde_vld1_f32(test_vec[i].r[1]);

    simde_test_arm_neon_assert_equal_f32x2(r.val[0], expected.val[0], INT_MAX);
    simde_test_arm_neon_assert_equal_f32x2(r.val[1], expected.val[1], INT_MAX);
  }

  return 0;
}

static int
test_simde_vld2_lane_f64 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    simde_float64_t src[2][1];
    simde_float64_t buf[2];
    simde_float64_t r[2][1];
  } test_vec[] = {
   { { {  SIMDE_FLOAT64_C(-463008.81) },
       {  SIMDE_FLOAT64_C(-130916.96) } },
       {  SIMDE_FLOAT64_C(392863.67), SIMDE_FLOAT64_C(310874.94)},
     { {  SIMDE_FLOAT64_C(392863.67) },
       {  SIMDE_FLOAT64_C(310874.94) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x1x2_t r, src, expected;
    src.val[0] = simde_vld1_f64(test_vec[i].src[0]);
    src.val[1] = simde_vld1_f64(test_vec[i].src[1]);

    r = simde_vld2_lane_f64(test_vec[i].buf, src, 0);

    expected.val[0] = simde_vld1_f64(test_vec[i].r[0]);
    expected.val[1] = simde_vld1_f64(test_vec[i].r[1]);

    simde_test_arm_neon_assert_equal_f64x1(r.val[0], expected.val[0], INT_MAX);
    simde_test_arm_neon_assert_equal_f64x1(r.val[1], expected.val[1], INT_MAX);
  }

  return 0;
}

static int
test_simde_vld2q_lane_s8 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int8_t src[2][16];
    int8_t buf[2];
    int8_t r[2][16];
  } test_vec[] = {
   { { {  INT8_C(46), INT8_C(42), -INT8_C(1), INT8_C(9), -INT8_C(24), -INT8_C(23), -INT8_C(11), INT8_C(37),
        INT8_C(22), INT8_C(30), INT8_C(25), INT8_C(27), -INT8_C(10), -INT8_C(26), -INT8_C(1), -INT8_C(10) },
       {  INT8_C(13), INT8_C(29), -INT8_C(22), INT8_C(40), -INT8_C(48), -INT8_C(40), INT8_C(0), -INT8_C(12),
        -INT8_C(18), -INT8_C(35), INT8_C(43), -INT8_C(30), -INT8_C(32), INT8_C(30), -INT8_C(21), -INT8_C(36) } },
       {  -INT8_C(13), -INT8_C(15)},
     { {  -INT8_C(13), INT8_C(42), -INT8_C(1), INT8_C(9), -INT8_C(24), -INT8_C(23), -INT8_C(11), INT8_C(37),
        INT8_C(22), INT8_C(30), INT8_C(25), INT8_C(27), -INT8_C(10), -INT8_C(26), -INT8_C(1), -INT8_C(10) },
       {  -INT8_C(15), INT8_C(29), -INT8_C(22), INT8_C(40), -INT8_C(48), -INT8_C(40), INT8_C(0), -INT8_C(12),
        -INT8_C(18), -INT8_C(35), INT8_C(43), -INT8_C(30), -INT8_C(32), INT8_C(30), -INT8_C(21), -INT8_C(36) } } },
   { { {  -INT8_C(20), -INT8_C(7), INT8_C(32), -INT8_C(38), INT8_C(1), -INT8_C(28), -INT8_C(5), -INT8_C(1),
        -INT8_C(17), INT8_C(10), INT8_C(10), INT8_C(23), -INT8_C(26), INT8_C(1), -INT8_C(37), -INT8_C(35) },
       {  INT8_C(18), -INT8_C(31), INT8_C(37), INT8_C(26), INT8_C(9), INT8_C(14), -INT8_C(17), INT8_C(38),
        -INT8_C(8), -INT8_C(27), INT8_C(45), -INT8_C(15), INT8_C(0), INT8_C(36), INT8_C(1), -INT8_C(20) } },
       {  -INT8_C(11), INT8_C(6)},
     { {  -INT8_C(20), -INT8_C(11), INT8_C(32), -INT8_C(38), INT8_C(1), -INT8_C(28), -INT8_C(5), -INT8_C(1),
        -INT8_C(17), INT8_C(10), INT8_C(10), INT8_C(23), -INT8_C(26), INT8_C(1), -INT8_C(37), -INT8_C(35) },
       {  INT8_C(18), INT8_C(6), INT8_C(37), INT8_C(26), INT8_C(9), INT8_C(14), -INT8_C(17), INT8_C(38),
        -INT8_C(8), -INT8_C(27), INT8_C(45), -INT8_C(15), INT8_C(0), INT8_C(36), INT8_C(1), -INT8_C(20) } } },
   { { {  INT8_C(13), -INT8_C(26), -INT8_C(44), INT8_C(35), -INT8_C(42), -INT8_C(3), INT8_C(9), INT8_C(23),
        INT8_C(0), -INT8_C(20), INT8_C(17), INT8_C(46), INT8_C(15), INT8_C(39), -INT8_C(26), -INT8_C(34) },
       {  INT8_C(5), INT8_C(22), -INT8_C(30), INT8_C(9), INT8_C(17), -INT8_C(44), -INT8_C(46), -INT8_C(25),
        -INT8_C(45), INT8_C(46), INT8_C(16), -INT8_C(6), -INT8_C(40), INT8_C(37), -INT8_C(15), -INT8_C(11) } },
       {  INT8_C(25), INT8_C(25)},
     { {  INT8_C(13), -INT8_C(26), INT8_C(25), INT8_C(35), -INT8_C(42), -INT8_C(3), INT8_C(9), INT8_C(23),
        INT8_C(0), -INT8_C(20), INT8_C(17), INT8_C(46), INT8_C(15), INT8_C(39), -INT8_C(26), -INT8_C(34) },
       {  INT8_C(5), INT8_C(22), INT8_C(25), INT8_C(9), INT8_C(17), -INT8_C(44), -INT8_C(46), -INT8_C(25),
        -INT8_C(45), INT8_C(46), INT8_C(16), -INT8_C(6), -INT8_C(40), INT8_C(37), -INT8_C(15), -INT8_C(11) } } },
   { { {  -INT8_C(6), -INT8_C(37), INT8_C(49), INT8_C(9), INT8_C(38), -INT8_C(40), -INT8_C(21), -INT8_C(28),
        -INT8_C(2), -INT8_C(1), -INT8_C(18), INT8_C(31), -INT8_C(34), -INT8_C(2), INT8_C(23), INT8_C(35) },
       {  -INT8_C(17), INT8_C(12), -INT8_C(24), -INT8_C(48), -INT8_C(30), -INT8_C(16), INT8_C(21), INT8_C(31),
        INT8_C(39), INT8_C(29), INT8_C(4), -INT8_C(18), -INT8_C(47), INT8_C(15), -INT8_C(49), INT8_C(18) } },
       {  -INT8_C(41), INT8_C(33)},
     { {  -INT8_C(6), -INT8_C(37), INT8_C(49), -INT8_C(41), INT8_C(38), -INT8_C(40), -INT8_C(21), -INT8_C(28),
        -INT8_C(2), -INT8_C(1), -INT8_C(18), INT8_C(31), -INT8_C(34), -INT8_C(2), INT8_C(23), INT8_C(35) },
       {  -INT8_C(17), INT8_C(12), -INT8_C(24), INT8_C(33), -INT8_C(30), -INT8_C(16), INT8_C(21), INT8_C(31),
        INT8_C(39), INT8_C(29), INT8_C(4), -INT8_C(18), -INT8_C(47), INT8_C(15), -INT8_C(49), INT8_C(18) } } },
   { { {  INT8_C(10), -INT8_C(27), INT8_C(21), -INT8_C(23), -INT8_C(17), -INT8_C(42), INT8_C(24), -INT8_C(35),
        -INT8_C(38), -INT8_C(3), INT8_C(29), INT8_C(41), -INT8_C(44), -INT8_C(15), -INT8_C(48), -INT8_C(26) },
       {  -INT8_C(9), -INT8_C(47), -INT8_C(29), INT8_C(8), INT8_C(7), INT8_C(6), -INT8_C(26), INT8_C(9),
        -INT8_C(11), -INT8_C(2), -INT8_C(6), INT8_C(22), INT8_C(34), -INT8_C(5), -INT8_C(38), -INT8_C(18) } },
       {  INT8_C(21), -INT8_C(25)},
     { {  INT8_C(10), -INT8_C(27), INT8_C(21), -INT8_C(23), INT8_C(21), -INT8_C(42), INT8_C(24), -INT8_C(35),
        -INT8_C(38), -INT8_C(3), INT8_C(29), INT8_C(41), -INT8_C(44), -INT8_C(15), -INT8_C(48), -INT8_C(26) },
       {  -INT8_C(9), -INT8_C(47), -INT8_C(29), INT8_C(8), -INT8_C(25), INT8_C(6), -INT8_C(26), INT8_C(9),
        -INT8_C(11), -INT8_C(2), -INT8_C(6), INT8_C(22), INT8_C(34), -INT8_C(5), -INT8_C(38), -INT8_C(18) } } },
   { { {  INT8_C(2), INT8_C(33), INT8_C(23), INT8_C(0), -INT8_C(48), INT8_C(2), INT8_C(26), INT8_C(29),
        INT8_C(38), INT8_C(14), INT8_C(48), INT8_C(0), -INT8_C(44), -INT8_C(42), -INT8_C(37), INT8_C(5) },
       {  INT8_C(24), INT8_C(4), INT8_C(37), INT8_C(46), INT8_C(40), INT8_C(24), INT8_C(40), -INT8_C(18),
        -INT8_C(44), INT8_C(48), -INT8_C(36), INT8_C(45), INT8_C(2), INT8_C(4), -INT8_C(35), -INT8_C(9) } },
       {  INT8_C(15), INT8_C(13)},
     { {  INT8_C(2), INT8_C(33), INT8_C(23), INT8_C(0), -INT8_C(48), INT8_C(15), INT8_C(26), INT8_C(29),
        INT8_C(38), INT8_C(14), INT8_C(48), INT8_C(0), -INT8_C(44), -INT8_C(42), -INT8_C(37), INT8_C(5) },
       {  INT8_C(24), INT8_C(4), INT8_C(37), INT8_C(46), INT8_C(40), INT8_C(13), INT8_C(40), -INT8_C(18),
        -INT8_C(44), INT8_C(48), -INT8_C(36), INT8_C(45), INT8_C(2), INT8_C(4), -INT8_C(35), -INT8_C(9) } } },
   { { {  -INT8_C(19), INT8_C(26), -INT8_C(45), INT8_C(37), -INT8_C(27), -INT8_C(2), INT8_C(43), -INT8_C(37),
        -INT8_C(26), -INT8_C(18), INT8_C(35), INT8_C(9), -INT8_C(15), INT8_C(38), -INT8_C(12), -INT8_C(35) },
       {  INT8_C(9), -INT8_C(5), -INT8_C(6), -INT8_C(48), INT8_C(10), -INT8_C(7), -INT8_C(18), INT8_C(18),
        -INT8_C(5), -INT8_C(48), -INT8_C(36), INT8_C(12), -INT8_C(8), INT8_C(23), INT8_C(0), -INT8_C(27) } },
       {  -INT8_C(19), -INT8_C(38)},
     { {  -INT8_C(19), INT8_C(26), -INT8_C(45), INT8_C(37), -INT8_C(27), -INT8_C(2), -INT8_C(19), -INT8_C(37),
        -INT8_C(26), -INT8_C(18), INT8_C(35), INT8_C(9), -INT8_C(15), INT8_C(38), -INT8_C(12), -INT8_C(35) },
       {  INT8_C(9), -INT8_C(5), -INT8_C(6), -INT8_C(48), INT8_C(10), -INT8_C(7), -INT8_C(38), INT8_C(18),
        -INT8_C(5), -INT8_C(48), -INT8_C(36), INT8_C(12), -INT8_C(8), INT8_C(23), INT8_C(0), -INT8_C(27) } } },
   { { {  INT8_C(27), INT8_C(17), -INT8_C(31), INT8_C(14), INT8_C(14), INT8_C(10), INT8_C(47), INT8_C(29),
        -INT8_C(16), INT8_C(21), -INT8_C(21), -INT8_C(49), INT8_C(40), -INT8_C(7), -INT8_C(47), INT8_C(0) },
       {  -INT8_C(39), -INT8_C(29), -INT8_C(1), -INT8_C(3), -INT8_C(6), INT8_C(48), INT8_C(32), -INT8_C(2),
        -INT8_C(14), INT8_C(9), -INT8_C(49), -INT8_C(9), -INT8_C(7), INT8_C(24), INT8_C(42), INT8_C(39) } },
       {  INT8_C(4), -INT8_C(15)},
     { {  INT8_C(27), INT8_C(17), -INT8_C(31), INT8_C(14), INT8_C(14), INT8_C(10), INT8_C(47), INT8_C(4),
        -INT8_C(16), INT8_C(21), -INT8_C(21), -INT8_C(49), INT8_C(40), -INT8_C(7), -INT8_C(47), INT8_C(0) },
       {  -INT8_C(39), -INT8_C(29), -INT8_C(1), -INT8_C(3), -INT8_C(6), INT8_C(48), INT8_C(32), -INT8_C(15),
        -INT8_C(14), INT8_C(9), -INT8_C(49), -INT8_C(9), -INT8_C(7), INT8_C(24), INT8_C(42), INT8_C(39) } } },
   { { {  INT8_C(37), INT8_C(15), -INT8_C(46), INT8_C(31), -INT8_C(34), INT8_C(45), -INT8_C(14), INT8_C(4),
        -INT8_C(14), INT8_C(26), INT8_C(46), INT8_C(29), INT8_C(18), INT8_C(8), -INT8_C(42), -INT8_C(46) },
       {  -INT8_C(21), INT8_C(6), INT8_C(17), -INT8_C(27), -INT8_C(20), -INT8_C(32), -INT8_C(7), INT8_C(47),
        -INT8_C(2), -INT8_C(20), INT8_C(26), INT8_C(18), -INT8_C(49), -INT8_C(34), -INT8_C(49), INT8_C(20) } },
       {  INT8_C(35), -INT8_C(38)},
     { {  INT8_C(37), INT8_C(15), -INT8_C(46), INT8_C(31), -INT8_C(34), INT8_C(45), -INT8_C(14), INT8_C(4),
        INT8_C(35), INT8_C(26), INT8_C(46), INT8_C(29), INT8_C(18), INT8_C(8), -INT8_C(42), -INT8_C(46) },
       {  -INT8_C(21), INT8_C(6), INT8_C(17), -INT8_C(27), -INT8_C(20), -INT8_C(32), -INT8_C(7), INT8_C(47),
        -INT8_C(38), -INT8_C(20), INT8_C(26), INT8_C(18), -INT8_C(49), -INT8_C(34), -INT8_C(49), INT8_C(20) } } },
   { { {  -INT8_C(3), -INT8_C(7), -INT8_C(11), INT8_C(42), -INT8_C(30), INT8_C(18), -INT8_C(19), INT8_C(10),
        INT8_C(28), INT8_C(27), -INT8_C(40), INT8_C(8), -INT8_C(37), -INT8_C(45), -INT8_C(46), INT8_C(28) },
       {  -INT8_C(20), -INT8_C(48), INT8_C(0), INT8_C(46), INT8_C(25), -INT8_C(39), INT8_C(0), -INT8_C(21),
        INT8_C(25), INT8_C(28), -INT8_C(48), -INT8_C(12), -INT8_C(13), -INT8_C(44), -INT8_C(45), -INT8_C(26) } },
       {  INT8_C(47), INT8_C(22)},
     { {  -INT8_C(3), -INT8_C(7), -INT8_C(11), INT8_C(42), -INT8_C(30), INT8_C(18), -INT8_C(19), INT8_C(10),
        INT8_C(28), INT8_C(47), -INT8_C(40), INT8_C(8), -INT8_C(37), -INT8_C(45), -INT8_C(46), INT8_C(28) },
       {  -INT8_C(20), -INT8_C(48), INT8_C(0), INT8_C(46), INT8_C(25), -INT8_C(39), INT8_C(0), -INT8_C(21),
        INT8_C(25), INT8_C(22), -INT8_C(48), -INT8_C(12), -INT8_C(13), -INT8_C(44), -INT8_C(45), -INT8_C(26) } } },
   { { {  -INT8_C(3), INT8_C(35), -INT8_C(46), INT8_C(27), -INT8_C(13), INT8_C(31), -INT8_C(44), INT8_C(37),
        INT8_C(46), -INT8_C(47), -INT8_C(29), INT8_C(24), INT8_C(0), INT8_C(31), -INT8_C(24), INT8_C(39) },
       {  INT8_C(8), INT8_C(45), -INT8_C(22), -INT8_C(28), INT8_C(9), -INT8_C(19), -INT8_C(27), -INT8_C(1),
        INT8_C(47), INT8_C(38), -INT8_C(11), -INT8_C(30), -INT8_C(18), INT8_C(13), -INT8_C(36), INT8_C(6) } },
       {  INT8_C(27), INT8_C(45)},
     { {  -INT8_C(3), INT8_C(35), -INT8_C(46), INT8_C(27), -INT8_C(13), INT8_C(31), -INT8_C(44), INT8_C(37),
        INT8_C(46), -INT8_C(47), INT8_C(27), INT8_C(24), INT8_C(0), INT8_C(31), -INT8_C(24), INT8_C(39) },
       {  INT8_C(8), INT8_C(45), -INT8_C(22), -INT8_C(28), INT8_C(9), -INT8_C(19), -INT8_C(27), -INT8_C(1),
        INT8_C(47), INT8_C(38), INT8_C(45), -INT8_C(30), -INT8_C(18), INT8_C(13), -INT8_C(36), INT8_C(6) } } },
   { { {  -INT8_C(27), INT8_C(22), -INT8_C(2), -INT8_C(45), -INT8_C(16), -INT8_C(20), -INT8_C(11), INT8_C(41),
        INT8_C(5), INT8_C(39), INT8_C(35), INT8_C(0), -INT8_C(42), INT8_C(15), -INT8_C(7), -INT8_C(9) },
       {  -INT8_C(42), INT8_C(1), INT8_C(5), -INT8_C(26), -INT8_C(17), -INT8_C(42), -INT8_C(12), INT8_C(7),
        INT8_C(43), -INT8_C(27), -INT8_C(46), -INT8_C(18), -INT8_C(44), INT8_C(7), INT8_C(49), INT8_C(24) } },
       {  INT8_C(14), -INT8_C(8)},
     { {  -INT8_C(27), INT8_C(22), -INT8_C(2), -INT8_C(45), -INT8_C(16), -INT8_C(20), -INT8_C(11), INT8_C(41),
        INT8_C(5), INT8_C(39), INT8_C(35), INT8_C(14), -INT8_C(42), INT8_C(15), -INT8_C(7), -INT8_C(9) },
       {  -INT8_C(42), INT8_C(1), INT8_C(5), -INT8_C(26), -INT8_C(17), -INT8_C(42), -INT8_C(12), INT8_C(7),
        INT8_C(43), -INT8_C(27), -INT8_C(46), -INT8_C(8), -INT8_C(44), INT8_C(7), INT8_C(49), INT8_C(24) } } },
   { { {  INT8_C(49), -INT8_C(24), -INT8_C(24), -INT8_C(11), INT8_C(12), -INT8_C(25), INT8_C(0), INT8_C(3),
        -INT8_C(10), -INT8_C(16), INT8_C(24), INT8_C(47), INT8_C(42), INT8_C(8), INT8_C(45), -INT8_C(14) },
       {  INT8_C(19), INT8_C(19), INT8_C(0), -INT8_C(4), INT8_C(9), INT8_C(37), INT8_C(17), INT8_C(6),
        INT8_C(16), INT8_C(49), -INT8_C(39), INT8_C(30), INT8_C(42), -INT8_C(1), INT8_C(27), INT8_C(22) } },
       {  -INT8_C(14), INT8_C(8)},
     { {  INT8_C(49), -INT8_C(24), -INT8_C(24), -INT8_C(11), INT8_C(12), -INT8_C(25), INT8_C(0), INT8_C(3),
        -INT8_C(10), -INT8_C(16), INT8_C(24), INT8_C(47), -INT8_C(14), INT8_C(8), INT8_C(45), -INT8_C(14) },
       {  INT8_C(19), INT8_C(19), INT8_C(0), -INT8_C(4), INT8_C(9), INT8_C(37), INT8_C(17), INT8_C(6),
        INT8_C(16), INT8_C(49), -INT8_C(39), INT8_C(30), INT8_C(8), -INT8_C(1), INT8_C(27), INT8_C(22) } } },
   { { {  -INT8_C(6), -INT8_C(22), -INT8_C(33), INT8_C(31), INT8_C(29), -INT8_C(16), INT8_C(29), INT8_C(38),
        -INT8_C(25), -INT8_C(9), INT8_C(19), INT8_C(12), -INT8_C(2), -INT8_C(47), INT8_C(19), -INT8_C(47) },
       {  -INT8_C(42), INT8_C(2), -INT8_C(24), INT8_C(27), -INT8_C(3), INT8_C(20), INT8_C(2), -INT8_C(20),
        -INT8_C(10), -INT8_C(29), -INT8_C(37), -INT8_C(33), -INT8_C(47), -INT8_C(1), INT8_C(31), -INT8_C(4) } },
       {  -INT8_C(12), -INT8_C(31)},
     { {  -INT8_C(6), -INT8_C(22), -INT8_C(33), INT8_C(31), INT8_C(29), -INT8_C(16), INT8_C(29), INT8_C(38),
        -INT8_C(25), -INT8_C(9), INT8_C(19), INT8_C(12), -INT8_C(2), -INT8_C(12), INT8_C(19), -INT8_C(47) },
       {  -INT8_C(42), INT8_C(2), -INT8_C(24), INT8_C(27), -INT8_C(3), INT8_C(20), INT8_C(2), -INT8_C(20),
        -INT8_C(10), -INT8_C(29), -INT8_C(37), -INT8_C(33), -INT8_C(47), -INT8_C(31), INT8_C(31), -INT8_C(4) } } },
   { { {  -INT8_C(4), -INT8_C(34), -INT8_C(11), -INT8_C(37), -INT8_C(11), INT8_C(18), INT8_C(0), INT8_C(13),
        -INT8_C(45), INT8_C(20), -INT8_C(3), INT8_C(34), -INT8_C(42), -INT8_C(2), INT8_C(17), INT8_C(0) },
       {  INT8_C(43), -INT8_C(15), INT8_C(29), -INT8_C(47), INT8_C(29), INT8_C(31), INT8_C(20), INT8_C(42),
        INT8_C(37), INT8_C(6), -INT8_C(39), -INT8_C(2), INT8_C(40), -INT8_C(34), INT8_C(46), INT8_C(21) } },
       {  -INT8_C(1), -INT8_C(27)},
     { {  -INT8_C(4), -INT8_C(34), -INT8_C(11), -INT8_C(37), -INT8_C(11), INT8_C(18), INT8_C(0), INT8_C(13),
        -INT8_C(45), INT8_C(20), -INT8_C(3), INT8_C(34), -INT8_C(42), -INT8_C(2), -INT8_C(1), INT8_C(0) },
       {  INT8_C(43), -INT8_C(15), INT8_C(29), -INT8_C(47), INT8_C(29), INT8_C(31), INT8_C(20), INT8_C(42),
        INT8_C(37), INT8_C(6), -INT8_C(39), -INT8_C(2), INT8_C(40), -INT8_C(34), -INT8_C(27), INT8_C(21) } } },
   { { {  -INT8_C(45), INT8_C(24), INT8_C(18), INT8_C(2), -INT8_C(29), INT8_C(24), -INT8_C(25), INT8_C(8),
        INT8_C(2), INT8_C(10), INT8_C(15), -INT8_C(30), INT8_C(16), INT8_C(4), INT8_C(46), -INT8_C(26) },
       {  -INT8_C(24), -INT8_C(33), INT8_C(14), INT8_C(42), INT8_C(12), INT8_C(0), INT8_C(14), INT8_C(30),
        -INT8_C(11), -INT8_C(3), INT8_C(46), -INT8_C(16), -INT8_C(32), -INT8_C(30), -INT8_C(15), INT8_C(0) } },
       {  -INT8_C(18), -INT8_C(19)},
     { {  -INT8_C(45), INT8_C(24), INT8_C(18), INT8_C(2), -INT8_C(29), INT8_C(24), -INT8_C(25), INT8_C(8),
        INT8_C(2), INT8_C(10), INT8_C(15), -INT8_C(30), INT8_C(16), INT8_C(4), INT8_C(46), -INT8_C(18) },
       {  -INT8_C(24), -INT8_C(33), INT8_C(14), INT8_C(42), INT8_C(12), INT8_C(0), INT8_C(14), INT8_C(30),
        -INT8_C(11), -INT8_C(3), INT8_C(46), -INT8_C(16), -INT8_C(32), -INT8_C(30), -INT8_C(15), -INT8_C(19) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16x2_t r, src, expected;
    src.val[0] = simde_vld1q_s8(test_vec[i].src[0]);
    src.val[1] = simde_vld1q_s8(test_vec[i].src[1]);

    SIMDE_CONSTIFY_16_(simde_vld2q_lane_s8, r, (HEDLEY_UNREACHABLE(), r), i, test_vec[i].buf, src);

    expected.val[0] = simde_vld1q_s8(test_vec[i].r[0]);
    expected.val[1] = simde_vld1q_s8(test_vec[i].r[1]);

    simde_test_arm_neon_assert_equal_i8x16(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_i8x16(r.val[1], expected.val[1]);
  }

  return 0;
}

static int
test_simde_vld2q_lane_s16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int16_t src[2][8];
    int16_t buf[2];
    int16_t r[2][8];
  } test_vec[] = {
   { { {  INT16_C(418), INT16_C(216), INT16_C(347), INT16_C(476),
        -INT16_C(360), INT16_C(143), -INT16_C(316), -INT16_C(114) },
       {  INT16_C(387), -INT16_C(146), INT16_C(225), -INT16_C(190),
        INT16_C(399), -INT16_C(128), INT16_C(400), INT16_C(257) } },
       {  INT16_C(488), -INT16_C(232)},
     { {  INT16_C(488), INT16_C(216), INT16_C(347), INT16_C(476),
        -INT16_C(360), INT16_C(143), -INT16_C(316), -INT16_C(114) },
       {  -INT16_C(232), -INT16_C(146), INT16_C(225), -INT16_C(190),
        INT16_C(399), -INT16_C(128), INT16_C(400), INT16_C(257) } } },
   { { {  -INT16_C(311), INT16_C(430), -INT16_C(36), INT16_C(399),
        -INT16_C(84), INT16_C(165), INT16_C(434), -INT16_C(105) },
       {  -INT16_C(449), INT16_C(455), INT16_C(390), -INT16_C(160),
        INT16_C(77), INT16_C(147), INT16_C(38), INT16_C(271) } },
       {  INT16_C(106), -INT16_C(427)},
     { {  -INT16_C(311), INT16_C(106), -INT16_C(36), INT16_C(399),
        -INT16_C(84), INT16_C(165), INT16_C(434), -INT16_C(105) },
       {  -INT16_C(449), -INT16_C(427), INT16_C(390), -INT16_C(160),
        INT16_C(77), INT16_C(147), INT16_C(38), INT16_C(271) } } },
   { { {  INT16_C(181), -INT16_C(136), INT16_C(379), INT16_C(296),
        -INT16_C(309), -INT16_C(435), -INT16_C(152), INT16_C(215) },
       {  -INT16_C(379), INT16_C(147), INT16_C(345), -INT16_C(276),
        INT16_C(105), -INT16_C(142), -INT16_C(485), -INT16_C(383) } },
       {  -INT16_C(39), -INT16_C(212)},
     { {  INT16_C(181), -INT16_C(136), -INT16_C(39), INT16_C(296),
        -INT16_C(309), -INT16_C(435), -INT16_C(152), INT16_C(215) },
       {  -INT16_C(379), INT16_C(147), -INT16_C(212), -INT16_C(276),
        INT16_C(105), -INT16_C(142), -INT16_C(485), -INT16_C(383) } } },
   { { {  INT16_C(181), -INT16_C(451), INT16_C(74), -INT16_C(26),
        INT16_C(435), -INT16_C(466), INT16_C(458), -INT16_C(378) },
       {  -INT16_C(292), -INT16_C(173), INT16_C(470), INT16_C(400),
        -INT16_C(286), INT16_C(269), INT16_C(383), -INT16_C(317) } },
       {  INT16_C(240), INT16_C(459)},
     { {  INT16_C(181), -INT16_C(451), INT16_C(74), INT16_C(240),
        INT16_C(435), -INT16_C(466), INT16_C(458), -INT16_C(378) },
       {  -INT16_C(292), -INT16_C(173), INT16_C(470), INT16_C(459),
        -INT16_C(286), INT16_C(269), INT16_C(383), -INT16_C(317) } } },
   { { {  -INT16_C(377), -INT16_C(162), -INT16_C(3), -INT16_C(316),
        -INT16_C(150), INT16_C(261), INT16_C(40), INT16_C(64) },
       {  INT16_C(243), INT16_C(47), -INT16_C(381), -INT16_C(58),
        INT16_C(290), INT16_C(64), -INT16_C(220), -INT16_C(89) } },
       {  INT16_C(378), INT16_C(355)},
     { {  -INT16_C(377), -INT16_C(162), -INT16_C(3), -INT16_C(316),
        INT16_C(378), INT16_C(261), INT16_C(40), INT16_C(64) },
       {  INT16_C(243), INT16_C(47), -INT16_C(381), -INT16_C(58),
        INT16_C(355), INT16_C(64), -INT16_C(220), -INT16_C(89) } } },
   { { {  -INT16_C(298), INT16_C(486), -INT16_C(96), INT16_C(132),
        -INT16_C(108), INT16_C(284), INT16_C(54), INT16_C(224) },
       {  INT16_C(249), -INT16_C(117), -INT16_C(26), -INT16_C(467),
        -INT16_C(477), -INT16_C(25), INT16_C(300), -INT16_C(233) } },
       {  -INT16_C(454), INT16_C(179)},
     { {  -INT16_C(298), INT16_C(486), -INT16_C(96), INT16_C(132),
        -INT16_C(108), -INT16_C(454), INT16_C(54), INT16_C(224) },
       {  INT16_C(249), -INT16_C(117), -INT16_C(26), -INT16_C(467),
        -INT16_C(477), INT16_C(179), INT16_C(300), -INT16_C(233) } } },
   { { {  -INT16_C(15), -INT16_C(88), -INT16_C(166), INT16_C(374),
        INT16_C(203), -INT16_C(81), INT16_C(316), -INT16_C(214) },
       {  -INT16_C(227), INT16_C(24), -INT16_C(14), -INT16_C(100),
        -INT16_C(31), INT16_C(86), INT16_C(474), -INT16_C(470) } },
       {  INT16_C(325), -INT16_C(388)},
     { {  -INT16_C(15), -INT16_C(88), -INT16_C(166), INT16_C(374),
        INT16_C(203), -INT16_C(81), INT16_C(325), -INT16_C(214) },
       {  -INT16_C(227), INT16_C(24), -INT16_C(14), -INT16_C(100),
        -INT16_C(31), INT16_C(86), -INT16_C(388), -INT16_C(470) } } },
   { { {  INT16_C(370), -INT16_C(25), -INT16_C(181), INT16_C(342),
        INT16_C(6), -INT16_C(89), -INT16_C(30), INT16_C(425) },
       {  -INT16_C(478), -INT16_C(331), INT16_C(463), INT16_C(400),
        -INT16_C(469), -INT16_C(40), INT16_C(46), -INT16_C(134) } },
       {  INT16_C(225), -INT16_C(7)},
     { {  INT16_C(370), -INT16_C(25), -INT16_C(181), INT16_C(342),
        INT16_C(6), -INT16_C(89), -INT16_C(30), INT16_C(225) },
       {  -INT16_C(478), -INT16_C(331), INT16_C(463), INT16_C(400),
        -INT16_C(469), -INT16_C(40), INT16_C(46), -INT16_C(7) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8x2_t r, src, expected;
    src.val[0] = simde_vld1q_s16(test_vec[i].src[0]);
    src.val[1] = simde_vld1q_s16(test_vec[i].src[1]);

    SIMDE_CONSTIFY_8_(simde_vld2q_lane_s16, r, (HEDLEY_UNREACHABLE(), r), i, test_vec[i].buf, src);

    expected.val[0] = simde_vld1q_s16(test_vec[i].r[0]);
    expected.val[1] = simde_vld1q_s16(test_vec[i].r[1]);

    simde_test_arm_neon_assert_equal_i16x8(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_i16x8(r.val[1], expected.val[1]);
  }

  return 0;
}

static int
test_simde_vld2q_lane_s32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int32_t src[2][4];
    int32_t buf[2];
    int32_t r[2][4];
  } test_vec[] = {
   { { {  -INT32_C(224), -INT32_C(24), INT32_C(2014), INT32_C(3335) },
       {  -INT32_C(4141), INT32_C(3456), -INT32_C(3311), -INT32_C(746) } },
       {  -INT32_C(2149), -INT32_C(82)},
     { {  -INT32_C(2149), -INT32_C(24), INT32_C(2014), INT32_C(3335) },
       {  -INT32_C(82), INT32_C(3456), -INT32_C(3311), -INT32_C(746) } } },
   { { {  -INT32_C(2915), -INT32_C(4196), INT32_C(1917), -INT32_C(77) },
       {  -INT32_C(506), -INT32_C(4630), -INT32_C(894), INT32_C(1062) } },
       {  INT32_C(121), -INT32_C(4389)},
     { {  -INT32_C(2915), INT32_C(121), INT32_C(1917), -INT32_C(77) },
       {  -INT32_C(506), -INT32_C(4389), -INT32_C(894), INT32_C(1062) } } },
   { { {  -INT32_C(2980), INT32_C(3337), -INT32_C(2109), -INT32_C(1551) },
       {  INT32_C(3126), -INT32_C(3966), INT32_C(686), INT32_C(3121) } },
       {  INT32_C(3921), -INT32_C(4929)},
     { {  -INT32_C(2980), INT32_C(3337), INT32_C(3921), -INT32_C(1551) },
       {  INT32_C(3126), -INT32_C(3966), -INT32_C(4929), INT32_C(3121) } } },
   { { {  -INT32_C(4755), INT32_C(2232), INT32_C(2970), -INT32_C(272) },
       {  INT32_C(492), -INT32_C(4034), -INT32_C(412), INT32_C(1495) } },
       {  INT32_C(4153), INT32_C(2365)},
     { {  -INT32_C(4755), INT32_C(2232), INT32_C(2970), INT32_C(4153) },
       {  INT32_C(492), -INT32_C(4034), -INT32_C(412), INT32_C(2365) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4x2_t r, src, expected;
    src.val[0] = simde_vld1q_s32(test_vec[i].src[0]);
    src.val[1] = simde_vld1q_s32(test_vec[i].src[1]);

    SIMDE_CONSTIFY_4_(simde_vld2q_lane_s32, r, (HEDLEY_UNREACHABLE(), r), i, test_vec[i].buf, src);

    expected.val[0] = simde_vld1q_s32(test_vec[i].r[0]);
    expected.val[1] = simde_vld1q_s32(test_vec[i].r[1]);

    simde_test_arm_neon_assert_equal_i32x4(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_i32x4(r.val[1], expected.val[1]);
  }
  return 0;
}

static int
test_simde_vld2q_lane_s64 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int64_t src[2][2];
    int64_t buf[2];
    int64_t r[2][2];
  } test_vec[] = {
   { { {  INT64_C(133259958), INT64_C(495309638) },
       {  INT64_C(463332514), INT64_C(273508271) } },
       {  INT64_C(159685885), -INT64_C(187025881)},
     { {  INT64_C(159685885), INT64_C(495309638) },
       {  -INT64_C(187025881), INT64_C(273508271) } } },
   { { {  -INT64_C(430109367), -INT64_C(402602870) },
       {  -INT64_C(309788205), -INT64_C(441710399) } },
       {  -INT64_C(264334842), -INT64_C(60309831)},
     { {  -INT64_C(430109367), -INT64_C(264334842) },
       {  -INT64_C(309788205), -INT64_C(60309831) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2x2_t r, src, expected;
    src.val[0] = simde_vld1q_s64(test_vec[i].src[0]);
    src.val[1] = simde_vld1q_s64(test_vec[i].src[1]);

    SIMDE_CONSTIFY_2_(simde_vld2q_lane_s64, r, (HEDLEY_UNREACHABLE(), r), i, test_vec[i].buf, src);

    expected.val[0] = simde_vld1q_s64(test_vec[i].r[0]);
    expected.val[1] = simde_vld1q_s64(test_vec[i].r[1]);

    simde_test_arm_neon_assert_equal_i64x2(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_i64x2(r.val[1], expected.val[1]);
  }

  return 0;
}

static int
test_simde_vld2q_lane_u8 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    uint8_t src[2][16];
    uint8_t buf[2];
    uint8_t r[2][16];
  } test_vec[] = {
   { { {  UINT8_C(46), UINT8_C(42), UINT8_C(1), UINT8_C(9), UINT8_C(24), UINT8_C(23), UINT8_C(11), UINT8_C(37),
        UINT8_C(22), UINT8_C(30), UINT8_C(25), UINT8_C(27), UINT8_C(10), UINT8_C(26), UINT8_C(1), UINT8_C(10) },
       {  UINT8_C(13), UINT8_C(29), UINT8_C(22), UINT8_C(40), UINT8_C(48), UINT8_C(40), UINT8_C(0), UINT8_C(12),
        UINT8_C(18), UINT8_C(35), UINT8_C(43), UINT8_C(30), UINT8_C(32), UINT8_C(30), UINT8_C(21), UINT8_C(36) } },
       {  UINT8_C(13), UINT8_C(15)},
     { {  UINT8_C(13), UINT8_C(42), UINT8_C(1), UINT8_C(9), UINT8_C(24), UINT8_C(23), UINT8_C(11), UINT8_C(37),
        UINT8_C(22), UINT8_C(30), UINT8_C(25), UINT8_C(27), UINT8_C(10), UINT8_C(26), UINT8_C(1), UINT8_C(10) },
       {  UINT8_C(15), UINT8_C(29), UINT8_C(22), UINT8_C(40), UINT8_C(48), UINT8_C(40), UINT8_C(0), UINT8_C(12),
        UINT8_C(18), UINT8_C(35), UINT8_C(43), UINT8_C(30), UINT8_C(32), UINT8_C(30), UINT8_C(21), UINT8_C(36) } } },
   { { {  UINT8_C(20), UINT8_C(7), UINT8_C(32), UINT8_C(38), UINT8_C(1), UINT8_C(28), UINT8_C(5), UINT8_C(1),
        UINT8_C(17), UINT8_C(10), UINT8_C(10), UINT8_C(23), UINT8_C(26), UINT8_C(1), UINT8_C(37), UINT8_C(35) },
       {  UINT8_C(18), UINT8_C(31), UINT8_C(37), UINT8_C(26), UINT8_C(9), UINT8_C(14), UINT8_C(17), UINT8_C(38),
        UINT8_C(8), UINT8_C(27), UINT8_C(45), UINT8_C(15), UINT8_C(0), UINT8_C(36), UINT8_C(1), UINT8_C(20) } },
       {  UINT8_C(11), UINT8_C(6)},
     { {  UINT8_C(20), UINT8_C(11), UINT8_C(32), UINT8_C(38), UINT8_C(1), UINT8_C(28), UINT8_C(5), UINT8_C(1),
        UINT8_C(17), UINT8_C(10), UINT8_C(10), UINT8_C(23), UINT8_C(26), UINT8_C(1), UINT8_C(37), UINT8_C(35) },
       {  UINT8_C(18), UINT8_C(6), UINT8_C(37), UINT8_C(26), UINT8_C(9), UINT8_C(14), UINT8_C(17), UINT8_C(38),
        UINT8_C(8), UINT8_C(27), UINT8_C(45), UINT8_C(15), UINT8_C(0), UINT8_C(36), UINT8_C(1), UINT8_C(20) } } },
   { { {  UINT8_C(13), UINT8_C(26), UINT8_C(44), UINT8_C(35), UINT8_C(42), UINT8_C(3), UINT8_C(9), UINT8_C(23),
        UINT8_C(0), UINT8_C(20), UINT8_C(17), UINT8_C(46), UINT8_C(15), UINT8_C(39), UINT8_C(26), UINT8_C(34) },
       {  UINT8_C(5), UINT8_C(22), UINT8_C(30), UINT8_C(9), UINT8_C(17), UINT8_C(44), UINT8_C(46), UINT8_C(25),
        UINT8_C(45), UINT8_C(46), UINT8_C(16), UINT8_C(6), UINT8_C(40), UINT8_C(37), UINT8_C(15), UINT8_C(11) } },
       {  UINT8_C(25), UINT8_C(25)},
     { {  UINT8_C(13), UINT8_C(26), UINT8_C(25), UINT8_C(35), UINT8_C(42), UINT8_C(3), UINT8_C(9), UINT8_C(23),
        UINT8_C(0), UINT8_C(20), UINT8_C(17), UINT8_C(46), UINT8_C(15), UINT8_C(39), UINT8_C(26), UINT8_C(34) },
       {  UINT8_C(5), UINT8_C(22), UINT8_C(25), UINT8_C(9), UINT8_C(17), UINT8_C(44), UINT8_C(46), UINT8_C(25),
        UINT8_C(45), UINT8_C(46), UINT8_C(16), UINT8_C(6), UINT8_C(40), UINT8_C(37), UINT8_C(15), UINT8_C(11) } } },
   { { {  UINT8_C(6), UINT8_C(37), UINT8_C(49), UINT8_C(9), UINT8_C(38), UINT8_C(40), UINT8_C(21), UINT8_C(28),
        UINT8_C(2), UINT8_C(1), UINT8_C(18), UINT8_C(31), UINT8_C(34), UINT8_C(2), UINT8_C(23), UINT8_C(35) },
       {  UINT8_C(17), UINT8_C(12), UINT8_C(24), UINT8_C(48), UINT8_C(30), UINT8_C(16), UINT8_C(21), UINT8_C(31),
        UINT8_C(39), UINT8_C(29), UINT8_C(4), UINT8_C(18), UINT8_C(47), UINT8_C(15), UINT8_C(49), UINT8_C(18) } },
       {  UINT8_C(41), UINT8_C(33)},
     { {  UINT8_C(6), UINT8_C(37), UINT8_C(49), UINT8_C(41), UINT8_C(38), UINT8_C(40), UINT8_C(21), UINT8_C(28),
        UINT8_C(2), UINT8_C(1), UINT8_C(18), UINT8_C(31), UINT8_C(34), UINT8_C(2), UINT8_C(23), UINT8_C(35) },
       {  UINT8_C(17), UINT8_C(12), UINT8_C(24), UINT8_C(33), UINT8_C(30), UINT8_C(16), UINT8_C(21), UINT8_C(31),
        UINT8_C(39), UINT8_C(29), UINT8_C(4), UINT8_C(18), UINT8_C(47), UINT8_C(15), UINT8_C(49), UINT8_C(18) } } },
   { { {  UINT8_C(10), UINT8_C(27), UINT8_C(21), UINT8_C(23), UINT8_C(17), UINT8_C(42), UINT8_C(24), UINT8_C(35),
        UINT8_C(38), UINT8_C(3), UINT8_C(29), UINT8_C(41), UINT8_C(44), UINT8_C(15), UINT8_C(48), UINT8_C(26) },
       {  UINT8_C(9), UINT8_C(47), UINT8_C(29), UINT8_C(8), UINT8_C(7), UINT8_C(6), UINT8_C(26), UINT8_C(9),
        UINT8_C(11), UINT8_C(2), UINT8_C(6), UINT8_C(22), UINT8_C(34), UINT8_C(5), UINT8_C(38), UINT8_C(18) } },
       {  UINT8_C(21), UINT8_C(25)},
     { {  UINT8_C(10), UINT8_C(27), UINT8_C(21), UINT8_C(23), UINT8_C(21), UINT8_C(42), UINT8_C(24), UINT8_C(35),
        UINT8_C(38), UINT8_C(3), UINT8_C(29), UINT8_C(41), UINT8_C(44), UINT8_C(15), UINT8_C(48), UINT8_C(26) },
       {  UINT8_C(9), UINT8_C(47), UINT8_C(29), UINT8_C(8), UINT8_C(25), UINT8_C(6), UINT8_C(26), UINT8_C(9),
        UINT8_C(11), UINT8_C(2), UINT8_C(6), UINT8_C(22), UINT8_C(34), UINT8_C(5), UINT8_C(38), UINT8_C(18) } } },
   { { {  UINT8_C(2), UINT8_C(33), UINT8_C(23), UINT8_C(0), UINT8_C(48), UINT8_C(2), UINT8_C(26), UINT8_C(29),
        UINT8_C(38), UINT8_C(14), UINT8_C(48), UINT8_C(0), UINT8_C(44), UINT8_C(42), UINT8_C(37), UINT8_C(5) },
       {  UINT8_C(24), UINT8_C(4), UINT8_C(37), UINT8_C(46), UINT8_C(40), UINT8_C(24), UINT8_C(40), UINT8_C(18),
        UINT8_C(44), UINT8_C(48), UINT8_C(36), UINT8_C(45), UINT8_C(2), UINT8_C(4), UINT8_C(35), UINT8_C(9) } },
       {  UINT8_C(15), UINT8_C(13)},
     { {  UINT8_C(2), UINT8_C(33), UINT8_C(23), UINT8_C(0), UINT8_C(48), UINT8_C(15), UINT8_C(26), UINT8_C(29),
        UINT8_C(38), UINT8_C(14), UINT8_C(48), UINT8_C(0), UINT8_C(44), UINT8_C(42), UINT8_C(37), UINT8_C(5) },
       {  UINT8_C(24), UINT8_C(4), UINT8_C(37), UINT8_C(46), UINT8_C(40), UINT8_C(13), UINT8_C(40), UINT8_C(18),
        UINT8_C(44), UINT8_C(48), UINT8_C(36), UINT8_C(45), UINT8_C(2), UINT8_C(4), UINT8_C(35), UINT8_C(9) } } },
   { { {  UINT8_C(19), UINT8_C(26), UINT8_C(45), UINT8_C(37), UINT8_C(27), UINT8_C(2), UINT8_C(43), UINT8_C(37),
        UINT8_C(26), UINT8_C(18), UINT8_C(35), UINT8_C(9), UINT8_C(15), UINT8_C(38), UINT8_C(12), UINT8_C(35) },
       {  UINT8_C(9), UINT8_C(5), UINT8_C(6), UINT8_C(48), UINT8_C(10), UINT8_C(7), UINT8_C(18), UINT8_C(18),
        UINT8_C(5), UINT8_C(48), UINT8_C(36), UINT8_C(12), UINT8_C(8), UINT8_C(23), UINT8_C(0), UINT8_C(27) } },
       {  UINT8_C(19), UINT8_C(38)},
     { {  UINT8_C(19), UINT8_C(26), UINT8_C(45), UINT8_C(37), UINT8_C(27), UINT8_C(2), UINT8_C(19), UINT8_C(37),
        UINT8_C(26), UINT8_C(18), UINT8_C(35), UINT8_C(9), UINT8_C(15), UINT8_C(38), UINT8_C(12), UINT8_C(35) },
       {  UINT8_C(9), UINT8_C(5), UINT8_C(6), UINT8_C(48), UINT8_C(10), UINT8_C(7), UINT8_C(38), UINT8_C(18),
        UINT8_C(5), UINT8_C(48), UINT8_C(36), UINT8_C(12), UINT8_C(8), UINT8_C(23), UINT8_C(0), UINT8_C(27) } } },
   { { {  UINT8_C(27), UINT8_C(17), UINT8_C(31), UINT8_C(14), UINT8_C(14), UINT8_C(10), UINT8_C(47), UINT8_C(29),
        UINT8_C(16), UINT8_C(21), UINT8_C(21), UINT8_C(49), UINT8_C(40), UINT8_C(7), UINT8_C(47), UINT8_C(0) },
       {  UINT8_C(39), UINT8_C(29), UINT8_C(1), UINT8_C(3), UINT8_C(6), UINT8_C(48), UINT8_C(32), UINT8_C(2),
        UINT8_C(14), UINT8_C(9), UINT8_C(49), UINT8_C(9), UINT8_C(7), UINT8_C(24), UINT8_C(42), UINT8_C(39) } },
       {  UINT8_C(4), UINT8_C(15)},
     { {  UINT8_C(27), UINT8_C(17), UINT8_C(31), UINT8_C(14), UINT8_C(14), UINT8_C(10), UINT8_C(47), UINT8_C(4),
        UINT8_C(16), UINT8_C(21), UINT8_C(21), UINT8_C(49), UINT8_C(40), UINT8_C(7), UINT8_C(47), UINT8_C(0) },
       {  UINT8_C(39), UINT8_C(29), UINT8_C(1), UINT8_C(3), UINT8_C(6), UINT8_C(48), UINT8_C(32), UINT8_C(15),
        UINT8_C(14), UINT8_C(9), UINT8_C(49), UINT8_C(9), UINT8_C(7), UINT8_C(24), UINT8_C(42), UINT8_C(39) } } },
   { { {  UINT8_C(37), UINT8_C(15), UINT8_C(46), UINT8_C(31), UINT8_C(34), UINT8_C(45), UINT8_C(14), UINT8_C(4),
        UINT8_C(14), UINT8_C(26), UINT8_C(46), UINT8_C(29), UINT8_C(18), UINT8_C(8), UINT8_C(42), UINT8_C(46) },
       {  UINT8_C(21), UINT8_C(6), UINT8_C(17), UINT8_C(27), UINT8_C(20), UINT8_C(32), UINT8_C(7), UINT8_C(47),
        UINT8_C(2), UINT8_C(20), UINT8_C(26), UINT8_C(18), UINT8_C(49), UINT8_C(34), UINT8_C(49), UINT8_C(20) } },
       {  UINT8_C(35), UINT8_C(38)},
     { {  UINT8_C(37), UINT8_C(15), UINT8_C(46), UINT8_C(31), UINT8_C(34), UINT8_C(45), UINT8_C(14), UINT8_C(4),
        UINT8_C(35), UINT8_C(26), UINT8_C(46), UINT8_C(29), UINT8_C(18), UINT8_C(8), UINT8_C(42), UINT8_C(46) },
       {  UINT8_C(21), UINT8_C(6), UINT8_C(17), UINT8_C(27), UINT8_C(20), UINT8_C(32), UINT8_C(7), UINT8_C(47),
        UINT8_C(38), UINT8_C(20), UINT8_C(26), UINT8_C(18), UINT8_C(49), UINT8_C(34), UINT8_C(49), UINT8_C(20) } } },
   { { {  UINT8_C(3), UINT8_C(7), UINT8_C(11), UINT8_C(42), UINT8_C(30), UINT8_C(18), UINT8_C(19), UINT8_C(10),
        UINT8_C(28), UINT8_C(27), UINT8_C(40), UINT8_C(8), UINT8_C(37), UINT8_C(45), UINT8_C(46), UINT8_C(28) },
       {  UINT8_C(20), UINT8_C(48), UINT8_C(0), UINT8_C(46), UINT8_C(25), UINT8_C(39), UINT8_C(0), UINT8_C(21),
        UINT8_C(25), UINT8_C(28), UINT8_C(48), UINT8_C(12), UINT8_C(13), UINT8_C(44), UINT8_C(45), UINT8_C(26) } },
       {  UINT8_C(47), UINT8_C(22)},
     { {  UINT8_C(3), UINT8_C(7), UINT8_C(11), UINT8_C(42), UINT8_C(30), UINT8_C(18), UINT8_C(19), UINT8_C(10),
        UINT8_C(28), UINT8_C(47), UINT8_C(40), UINT8_C(8), UINT8_C(37), UINT8_C(45), UINT8_C(46), UINT8_C(28) },
       {  UINT8_C(20), UINT8_C(48), UINT8_C(0), UINT8_C(46), UINT8_C(25), UINT8_C(39), UINT8_C(0), UINT8_C(21),
        UINT8_C(25), UINT8_C(22), UINT8_C(48), UINT8_C(12), UINT8_C(13), UINT8_C(44), UINT8_C(45), UINT8_C(26) } } },
   { { {  UINT8_C(3), UINT8_C(35), UINT8_C(46), UINT8_C(27), UINT8_C(13), UINT8_C(31), UINT8_C(44), UINT8_C(37),
        UINT8_C(46), UINT8_C(47), UINT8_C(29), UINT8_C(24), UINT8_C(0), UINT8_C(31), UINT8_C(24), UINT8_C(39) },
       {  UINT8_C(8), UINT8_C(45), UINT8_C(22), UINT8_C(28), UINT8_C(9), UINT8_C(19), UINT8_C(27), UINT8_C(1),
        UINT8_C(47), UINT8_C(38), UINT8_C(11), UINT8_C(30), UINT8_C(18), UINT8_C(13), UINT8_C(36), UINT8_C(6) } },
       {  UINT8_C(27), UINT8_C(45)},
     { {  UINT8_C(3), UINT8_C(35), UINT8_C(46), UINT8_C(27), UINT8_C(13), UINT8_C(31), UINT8_C(44), UINT8_C(37),
        UINT8_C(46), UINT8_C(47), UINT8_C(27), UINT8_C(24), UINT8_C(0), UINT8_C(31), UINT8_C(24), UINT8_C(39) },
       {  UINT8_C(8), UINT8_C(45), UINT8_C(22), UINT8_C(28), UINT8_C(9), UINT8_C(19), UINT8_C(27), UINT8_C(1),
        UINT8_C(47), UINT8_C(38), UINT8_C(45), UINT8_C(30), UINT8_C(18), UINT8_C(13), UINT8_C(36), UINT8_C(6) } } },
   { { {  UINT8_C(27), UINT8_C(22), UINT8_C(2), UINT8_C(45), UINT8_C(16), UINT8_C(20), UINT8_C(11), UINT8_C(41),
        UINT8_C(5), UINT8_C(39), UINT8_C(35), UINT8_C(0), UINT8_C(42), UINT8_C(15), UINT8_C(7), UINT8_C(9) },
       {  UINT8_C(42), UINT8_C(1), UINT8_C(5), UINT8_C(26), UINT8_C(17), UINT8_C(42), UINT8_C(12), UINT8_C(7),
        UINT8_C(43), UINT8_C(27), UINT8_C(46), UINT8_C(18), UINT8_C(44), UINT8_C(7), UINT8_C(49), UINT8_C(24) } },
       {  UINT8_C(14), UINT8_C(8)},
     { {  UINT8_C(27), UINT8_C(22), UINT8_C(2), UINT8_C(45), UINT8_C(16), UINT8_C(20), UINT8_C(11), UINT8_C(41),
        UINT8_C(5), UINT8_C(39), UINT8_C(35), UINT8_C(14), UINT8_C(42), UINT8_C(15), UINT8_C(7), UINT8_C(9) },
       {  UINT8_C(42), UINT8_C(1), UINT8_C(5), UINT8_C(26), UINT8_C(17), UINT8_C(42), UINT8_C(12), UINT8_C(7),
        UINT8_C(43), UINT8_C(27), UINT8_C(46), UINT8_C(8), UINT8_C(44), UINT8_C(7), UINT8_C(49), UINT8_C(24) } } },
   { { {  UINT8_C(49), UINT8_C(24), UINT8_C(24), UINT8_C(11), UINT8_C(12), UINT8_C(25), UINT8_C(0), UINT8_C(3),
        UINT8_C(10), UINT8_C(16), UINT8_C(24), UINT8_C(47), UINT8_C(42), UINT8_C(8), UINT8_C(45), UINT8_C(14) },
       {  UINT8_C(19), UINT8_C(19), UINT8_C(0), UINT8_C(4), UINT8_C(9), UINT8_C(37), UINT8_C(17), UINT8_C(6),
        UINT8_C(16), UINT8_C(49), UINT8_C(39), UINT8_C(30), UINT8_C(42), UINT8_C(1), UINT8_C(27), UINT8_C(22) } },
       {  UINT8_C(14), UINT8_C(8)},
     { {  UINT8_C(49), UINT8_C(24), UINT8_C(24), UINT8_C(11), UINT8_C(12), UINT8_C(25), UINT8_C(0), UINT8_C(3),
        UINT8_C(10), UINT8_C(16), UINT8_C(24), UINT8_C(47), UINT8_C(14), UINT8_C(8), UINT8_C(45), UINT8_C(14) },
       {  UINT8_C(19), UINT8_C(19), UINT8_C(0), UINT8_C(4), UINT8_C(9), UINT8_C(37), UINT8_C(17), UINT8_C(6),
        UINT8_C(16), UINT8_C(49), UINT8_C(39), UINT8_C(30), UINT8_C(8), UINT8_C(1), UINT8_C(27), UINT8_C(22) } } },
   { { {  UINT8_C(6), UINT8_C(22), UINT8_C(33), UINT8_C(31), UINT8_C(29), UINT8_C(16), UINT8_C(29), UINT8_C(38),
        UINT8_C(25), UINT8_C(9), UINT8_C(19), UINT8_C(12), UINT8_C(2), UINT8_C(47), UINT8_C(19), UINT8_C(47) },
       {  UINT8_C(42), UINT8_C(2), UINT8_C(24), UINT8_C(27), UINT8_C(3), UINT8_C(20), UINT8_C(2), UINT8_C(20),
        UINT8_C(10), UINT8_C(29), UINT8_C(37), UINT8_C(33), UINT8_C(47), UINT8_C(1), UINT8_C(31), UINT8_C(4) } },
       {  UINT8_C(12), UINT8_C(31)},
     { {  UINT8_C(6), UINT8_C(22), UINT8_C(33), UINT8_C(31), UINT8_C(29), UINT8_C(16), UINT8_C(29), UINT8_C(38),
        UINT8_C(25), UINT8_C(9), UINT8_C(19), UINT8_C(12), UINT8_C(2), UINT8_C(12), UINT8_C(19), UINT8_C(47) },
       {  UINT8_C(42), UINT8_C(2), UINT8_C(24), UINT8_C(27), UINT8_C(3), UINT8_C(20), UINT8_C(2), UINT8_C(20),
        UINT8_C(10), UINT8_C(29), UINT8_C(37), UINT8_C(33), UINT8_C(47), UINT8_C(31), UINT8_C(31), UINT8_C(4) } } },
   { { {  UINT8_C(4), UINT8_C(34), UINT8_C(11), UINT8_C(37), UINT8_C(11), UINT8_C(18), UINT8_C(0), UINT8_C(13),
        UINT8_C(45), UINT8_C(20), UINT8_C(3), UINT8_C(34), UINT8_C(42), UINT8_C(2), UINT8_C(17), UINT8_C(0) },
       {  UINT8_C(43), UINT8_C(15), UINT8_C(29), UINT8_C(47), UINT8_C(29), UINT8_C(31), UINT8_C(20), UINT8_C(42),
        UINT8_C(37), UINT8_C(6), UINT8_C(39), UINT8_C(2), UINT8_C(40), UINT8_C(34), UINT8_C(46), UINT8_C(21) } },
       {  UINT8_C(1), UINT8_C(27)},
     { {  UINT8_C(4), UINT8_C(34), UINT8_C(11), UINT8_C(37), UINT8_C(11), UINT8_C(18), UINT8_C(0), UINT8_C(13),
        UINT8_C(45), UINT8_C(20), UINT8_C(3), UINT8_C(34), UINT8_C(42), UINT8_C(2), UINT8_C(1), UINT8_C(0) },
       {  UINT8_C(43), UINT8_C(15), UINT8_C(29), UINT8_C(47), UINT8_C(29), UINT8_C(31), UINT8_C(20), UINT8_C(42),
        UINT8_C(37), UINT8_C(6), UINT8_C(39), UINT8_C(2), UINT8_C(40), UINT8_C(34), UINT8_C(27), UINT8_C(21) } } },
   { { {  UINT8_C(45), UINT8_C(24), UINT8_C(18), UINT8_C(2), UINT8_C(29), UINT8_C(24), UINT8_C(25), UINT8_C(8),
        UINT8_C(2), UINT8_C(10), UINT8_C(15), UINT8_C(30), UINT8_C(16), UINT8_C(4), UINT8_C(46), UINT8_C(26) },
       {  UINT8_C(24), UINT8_C(33), UINT8_C(14), UINT8_C(42), UINT8_C(12), UINT8_C(0), UINT8_C(14), UINT8_C(30),
        UINT8_C(11), UINT8_C(3), UINT8_C(46), UINT8_C(16), UINT8_C(32), UINT8_C(30), UINT8_C(15), UINT8_C(0) } },
       {  UINT8_C(18), UINT8_C(19)},
     { {  UINT8_C(45), UINT8_C(24), UINT8_C(18), UINT8_C(2), UINT8_C(29), UINT8_C(24), UINT8_C(25), UINT8_C(8),
        UINT8_C(2), UINT8_C(10), UINT8_C(15), UINT8_C(30), UINT8_C(16), UINT8_C(4), UINT8_C(46), UINT8_C(18) },
       {  UINT8_C(24), UINT8_C(33), UINT8_C(14), UINT8_C(42), UINT8_C(12), UINT8_C(0), UINT8_C(14), UINT8_C(30),
        UINT8_C(11), UINT8_C(3), UINT8_C(46), UINT8_C(16), UINT8_C(32), UINT8_C(30), UINT8_C(15), UINT8_C(19) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x16x2_t r, src, expected;
    src.val[0] = simde_vld1q_u8(test_vec[i].src[0]);
    src.val[1] = simde_vld1q_u8(test_vec[i].src[1]);

    SIMDE_CONSTIFY_16_(simde_vld2q_lane_u8, r, (HEDLEY_UNREACHABLE(), r), i, test_vec[i].buf, src);

    expected.val[0] = simde_vld1q_u8(test_vec[i].r[0]);
    expected.val[1] = simde_vld1q_u8(test_vec[i].r[1]);

    simde_test_arm_neon_assert_equal_u8x16(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_u8x16(r.val[1], expected.val[1]);
  }

  return 0;
}

static int
test_simde_vld2q_lane_u16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    uint16_t src[2][8];
    uint16_t buf[2];
    uint16_t r[2][8];
  } test_vec[] = {
   { { {  UINT16_C(418), UINT16_C(216), UINT16_C(347), UINT16_C(476),
        UINT16_C(360), UINT16_C(143), UINT16_C(316), UINT16_C(114) },
       {  UINT16_C(387), UINT16_C(146), UINT16_C(225), UINT16_C(190),
        UINT16_C(399), UINT16_C(128), UINT16_C(400), UINT16_C(257) } },
       {  UINT16_C(488), UINT16_C(232)},
     { {  UINT16_C(488), UINT16_C(216), UINT16_C(347), UINT16_C(476),
        UINT16_C(360), UINT16_C(143), UINT16_C(316), UINT16_C(114) },
       {  UINT16_C(232), UINT16_C(146), UINT16_C(225), UINT16_C(190),
        UINT16_C(399), UINT16_C(128), UINT16_C(400), UINT16_C(257) } } },
   { { {  UINT16_C(311), UINT16_C(430), UINT16_C(36), UINT16_C(399),
        UINT16_C(84), UINT16_C(165), UINT16_C(434), UINT16_C(105) },
       {  UINT16_C(449), UINT16_C(455), UINT16_C(390), UINT16_C(160),
        UINT16_C(77), UINT16_C(147), UINT16_C(38), UINT16_C(271) } },
       {  UINT16_C(106), UINT16_C(427)},
     { {  UINT16_C(311), UINT16_C(106), UINT16_C(36), UINT16_C(399),
        UINT16_C(84), UINT16_C(165), UINT16_C(434), UINT16_C(105) },
       {  UINT16_C(449), UINT16_C(427), UINT16_C(390), UINT16_C(160),
        UINT16_C(77), UINT16_C(147), UINT16_C(38), UINT16_C(271) } } },
   { { {  UINT16_C(181), UINT16_C(136), UINT16_C(379), UINT16_C(296),
        UINT16_C(309), UINT16_C(435), UINT16_C(152), UINT16_C(215) },
       {  UINT16_C(379), UINT16_C(147), UINT16_C(345), UINT16_C(276),
        UINT16_C(105), UINT16_C(142), UINT16_C(485), UINT16_C(383) } },
       {  UINT16_C(39), UINT16_C(212)},
     { {  UINT16_C(181), UINT16_C(136), UINT16_C(39), UINT16_C(296),
        UINT16_C(309), UINT16_C(435), UINT16_C(152), UINT16_C(215) },
       {  UINT16_C(379), UINT16_C(147), UINT16_C(212), UINT16_C(276),
        UINT16_C(105), UINT16_C(142), UINT16_C(485), UINT16_C(383) } } },
   { { {  UINT16_C(181), UINT16_C(451), UINT16_C(74), UINT16_C(26),
        UINT16_C(435), UINT16_C(466), UINT16_C(458), UINT16_C(378) },
       {  UINT16_C(292), UINT16_C(173), UINT16_C(470), UINT16_C(400),
        UINT16_C(286), UINT16_C(269), UINT16_C(383), UINT16_C(317) } },
       {  UINT16_C(240), UINT16_C(459)},
     { {  UINT16_C(181), UINT16_C(451), UINT16_C(74), UINT16_C(240),
        UINT16_C(435), UINT16_C(466), UINT16_C(458), UINT16_C(378) },
       {  UINT16_C(292), UINT16_C(173), UINT16_C(470), UINT16_C(459),
        UINT16_C(286), UINT16_C(269), UINT16_C(383), UINT16_C(317) } } },
   { { {  UINT16_C(377), UINT16_C(162), UINT16_C(3), UINT16_C(316),
        UINT16_C(150), UINT16_C(261), UINT16_C(40), UINT16_C(64) },
       {  UINT16_C(243), UINT16_C(47), UINT16_C(381), UINT16_C(58),
        UINT16_C(290), UINT16_C(64), UINT16_C(220), UINT16_C(89) } },
       {  UINT16_C(378), UINT16_C(355)},
     { {  UINT16_C(377), UINT16_C(162), UINT16_C(3), UINT16_C(316),
        UINT16_C(378), UINT16_C(261), UINT16_C(40), UINT16_C(64) },
       {  UINT16_C(243), UINT16_C(47), UINT16_C(381), UINT16_C(58),
        UINT16_C(355), UINT16_C(64), UINT16_C(220), UINT16_C(89) } } },
   { { {  UINT16_C(298), UINT16_C(486), UINT16_C(96), UINT16_C(132),
        UINT16_C(108), UINT16_C(284), UINT16_C(54), UINT16_C(224) },
       {  UINT16_C(249), UINT16_C(117), UINT16_C(26), UINT16_C(467),
        UINT16_C(477), UINT16_C(25), UINT16_C(300), UINT16_C(233) } },
       {  UINT16_C(454), UINT16_C(179)},
     { {  UINT16_C(298), UINT16_C(486), UINT16_C(96), UINT16_C(132),
        UINT16_C(108), UINT16_C(454), UINT16_C(54), UINT16_C(224) },
       {  UINT16_C(249), UINT16_C(117), UINT16_C(26), UINT16_C(467),
        UINT16_C(477), UINT16_C(179), UINT16_C(300), UINT16_C(233) } } },
   { { {  UINT16_C(15), UINT16_C(88), UINT16_C(166), UINT16_C(374),
        UINT16_C(203), UINT16_C(81), UINT16_C(316), UINT16_C(214) },
       {  UINT16_C(227), UINT16_C(24), UINT16_C(14), UINT16_C(100),
        UINT16_C(31), UINT16_C(86), UINT16_C(474), UINT16_C(470) } },
       {  UINT16_C(325), UINT16_C(388)},
     { {  UINT16_C(15), UINT16_C(88), UINT16_C(166), UINT16_C(374),
        UINT16_C(203), UINT16_C(81), UINT16_C(325), UINT16_C(214) },
       {  UINT16_C(227), UINT16_C(24), UINT16_C(14), UINT16_C(100),
        UINT16_C(31), UINT16_C(86), UINT16_C(388), UINT16_C(470) } } },
   { { {  UINT16_C(370), UINT16_C(25), UINT16_C(181), UINT16_C(342),
        UINT16_C(6), UINT16_C(89), UINT16_C(30), UINT16_C(425) },
       {  UINT16_C(478), UINT16_C(331), UINT16_C(463), UINT16_C(400),
        UINT16_C(469), UINT16_C(40), UINT16_C(46), UINT16_C(134) } },
       {  UINT16_C(225), UINT16_C(7)},
     { {  UINT16_C(370), UINT16_C(25), UINT16_C(181), UINT16_C(342),
        UINT16_C(6), UINT16_C(89), UINT16_C(30), UINT16_C(225) },
       {  UINT16_C(478), UINT16_C(331), UINT16_C(463), UINT16_C(400),
        UINT16_C(469), UINT16_C(40), UINT16_C(46), UINT16_C(7) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8x2_t r, src, expected;
    src.val[0] = simde_vld1q_u16(test_vec[i].src[0]);
    src.val[1] = simde_vld1q_u16(test_vec[i].src[1]);

    SIMDE_CONSTIFY_8_(simde_vld2q_lane_u16, r, (HEDLEY_UNREACHABLE(), r), i, test_vec[i].buf, src);

    expected.val[0] = simde_vld1q_u16(test_vec[i].r[0]);
    expected.val[1] = simde_vld1q_u16(test_vec[i].r[1]);

    simde_test_arm_neon_assert_equal_u16x8(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_u16x8(r.val[1], expected.val[1]);
  }

  return 0;
}

static int
test_simde_vld2q_lane_u32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    uint32_t src[2][4];
    uint32_t buf[2];
    uint32_t r[2][4];
  } test_vec[] = {
   { { {  UINT32_C(224), UINT32_C(24), UINT32_C(2014), UINT32_C(3335) },
       {  UINT32_C(4141), UINT32_C(3456), UINT32_C(3311), UINT32_C(746) } },
       {  UINT32_C(2149), UINT32_C(82)},
     { {  UINT32_C(2149), UINT32_C(24), UINT32_C(2014), UINT32_C(3335) },
       {  UINT32_C(82), UINT32_C(3456), UINT32_C(3311), UINT32_C(746) } } },
   { { {  UINT32_C(2915), UINT32_C(4196), UINT32_C(1917), UINT32_C(77) },
       {  UINT32_C(506), UINT32_C(4630), UINT32_C(894), UINT32_C(1062) } },
       {  UINT32_C(121), UINT32_C(4389)},
     { {  UINT32_C(2915), UINT32_C(121), UINT32_C(1917), UINT32_C(77) },
       {  UINT32_C(506), UINT32_C(4389), UINT32_C(894), UINT32_C(1062) } } },
   { { {  UINT32_C(2980), UINT32_C(3337), UINT32_C(2109), UINT32_C(1551) },
       {  UINT32_C(3126), UINT32_C(3966), UINT32_C(686), UINT32_C(3121) } },
       {  UINT32_C(3921), UINT32_C(4929)},
     { {  UINT32_C(2980), UINT32_C(3337), UINT32_C(3921), UINT32_C(1551) },
       {  UINT32_C(3126), UINT32_C(3966), UINT32_C(4929), UINT32_C(3121) } } },
   { { {  UINT32_C(4755), UINT32_C(2232), UINT32_C(2970), UINT32_C(272) },
       {  UINT32_C(492), UINT32_C(4034), UINT32_C(412), UINT32_C(1495) } },
       {  UINT32_C(4153), UINT32_C(2365)},
     { {  UINT32_C(4755), UINT32_C(2232), UINT32_C(2970), UINT32_C(4153) },
       {  UINT32_C(492), UINT32_C(4034), UINT32_C(412), UINT32_C(2365) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4x2_t r, src, expected;
    src.val[0] = simde_vld1q_u32(test_vec[i].src[0]);
    src.val[1] = simde_vld1q_u32(test_vec[i].src[1]);

    SIMDE_CONSTIFY_4_(simde_vld2q_lane_u32, r, (HEDLEY_UNREACHABLE(), r), i, test_vec[i].buf, src);

    expected.val[0] = simde_vld1q_u32(test_vec[i].r[0]);
    expected.val[1] = simde_vld1q_u32(test_vec[i].r[1]);

    simde_test_arm_neon_assert_equal_u32x4(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_u32x4(r.val[1], expected.val[1]);
  }
  return 0;
}

static int
test_simde_vld2q_lane_u64 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    uint64_t src[2][2];
    uint64_t buf[2];
    uint64_t r[2][2];
  } test_vec[] = {
   { { {  UINT64_C(133259958), UINT64_C(495309638) },
       {  UINT64_C(463332514), UINT64_C(273508271) } },
       {  UINT64_C(159685885), UINT64_C(187025881)},
     { {  UINT64_C(159685885), UINT64_C(495309638) },
       {  UINT64_C(187025881), UINT64_C(273508271) } } },
   { { {  UINT64_C(430109367), UINT64_C(402602870) },
       {  UINT64_C(309788205), UINT64_C(441710399) } },
       {  UINT64_C(264334842), UINT64_C(60309831)},
     { {  UINT64_C(430109367), UINT64_C(264334842) },
       {  UINT64_C(309788205), UINT64_C(60309831) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x2x2_t r, src, expected;
    src.val[0] = simde_vld1q_u64(test_vec[i].src[0]);
    src.val[1] = simde_vld1q_u64(test_vec[i].src[1]);

    SIMDE_CONSTIFY_2_(simde_vld2q_lane_u64, r, (HEDLEY_UNREACHABLE(), r), i, test_vec[i].buf, src);

    expected.val[0] = simde_vld1q_u64(test_vec[i].r[0]);
    expected.val[1] = simde_vld1q_u64(test_vec[i].r[1]);

    simde_test_arm_neon_assert_equal_u64x2(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_u64x2(r.val[1], expected.val[1]);
  }

  return 0;
}

static int
test_simde_vld2q_lane_f16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float16_t src[2][8];
    simde_float16_t buf[2];
    simde_float16_t r[2][8];
  } test_vec[] = {
   { { {  SIMDE_FLOAT16_VALUE(-44.86), SIMDE_FLOAT16_VALUE(-27.30), SIMDE_FLOAT16_VALUE(-35.67), SIMDE_FLOAT16_VALUE(22.98),
        SIMDE_FLOAT16_VALUE(-34.31), SIMDE_FLOAT16_VALUE(-40.87), SIMDE_FLOAT16_VALUE(-37.54), SIMDE_FLOAT16_VALUE(-11.89) },
       {  SIMDE_FLOAT16_VALUE(-19.39), SIMDE_FLOAT16_VALUE(-21.84), SIMDE_FLOAT16_VALUE(-32.89), SIMDE_FLOAT16_VALUE(43.11),
        SIMDE_FLOAT16_VALUE(-10.75), SIMDE_FLOAT16_VALUE(-18.47), SIMDE_FLOAT16_VALUE(14.59), SIMDE_FLOAT16_VALUE(48.79) } },
       {  SIMDE_FLOAT16_VALUE(7.62), SIMDE_FLOAT16_VALUE(-49.51)},
     { {  SIMDE_FLOAT16_VALUE(7.62), SIMDE_FLOAT16_VALUE(-27.30), SIMDE_FLOAT16_VALUE(-35.67), SIMDE_FLOAT16_VALUE(22.98),
        SIMDE_FLOAT16_VALUE(-34.31), SIMDE_FLOAT16_VALUE(-40.87), SIMDE_FLOAT16_VALUE(-37.54), SIMDE_FLOAT16_VALUE(-11.89) },
       {  SIMDE_FLOAT16_VALUE(-49.51), SIMDE_FLOAT16_VALUE(-21.84), SIMDE_FLOAT16_VALUE(-32.89), SIMDE_FLOAT16_VALUE(43.11),
        SIMDE_FLOAT16_VALUE(-10.75), SIMDE_FLOAT16_VALUE(-18.47), SIMDE_FLOAT16_VALUE(14.59), SIMDE_FLOAT16_VALUE(48.79) } } },
   { { {  SIMDE_FLOAT16_VALUE(-38.62), SIMDE_FLOAT16_VALUE(4.41), SIMDE_FLOAT16_VALUE(-33.69), SIMDE_FLOAT16_VALUE(-29.42),
        SIMDE_FLOAT16_VALUE(-26.20), SIMDE_FLOAT16_VALUE(-37.93), SIMDE_FLOAT16_VALUE(-22.76), SIMDE_FLOAT16_VALUE(9.22) },
       {  SIMDE_FLOAT16_VALUE(33.15), SIMDE_FLOAT16_VALUE(36.15), SIMDE_FLOAT16_VALUE(8.88), SIMDE_FLOAT16_VALUE(-47.77),
        SIMDE_FLOAT16_VALUE(42.44), SIMDE_FLOAT16_VALUE(-2.49), SIMDE_FLOAT16_VALUE(-30.82), SIMDE_FLOAT16_VALUE(-8.07) } },
       {  SIMDE_FLOAT16_VALUE(13.95), SIMDE_FLOAT16_VALUE(-11.74)},
     { {  SIMDE_FLOAT16_VALUE(-38.62), SIMDE_FLOAT16_VALUE(13.95), SIMDE_FLOAT16_VALUE(-33.69), SIMDE_FLOAT16_VALUE(-29.42),
        SIMDE_FLOAT16_VALUE(-26.20), SIMDE_FLOAT16_VALUE(-37.93), SIMDE_FLOAT16_VALUE(-22.76), SIMDE_FLOAT16_VALUE(9.22) },
       {  SIMDE_FLOAT16_VALUE(33.15), SIMDE_FLOAT16_VALUE(-11.74), SIMDE_FLOAT16_VALUE(8.88), SIMDE_FLOAT16_VALUE(-47.77),
        SIMDE_FLOAT16_VALUE(42.44), SIMDE_FLOAT16_VALUE(-2.49), SIMDE_FLOAT16_VALUE(-30.82), SIMDE_FLOAT16_VALUE(-8.07) } } },
   { { {  SIMDE_FLOAT16_VALUE(20.63), SIMDE_FLOAT16_VALUE(-26.03), SIMDE_FLOAT16_VALUE(-49.03), SIMDE_FLOAT16_VALUE(-9.02),
        SIMDE_FLOAT16_VALUE(-7.24), SIMDE_FLOAT16_VALUE(21.25), SIMDE_FLOAT16_VALUE(7.83), SIMDE_FLOAT16_VALUE(13.60) },
       {  SIMDE_FLOAT16_VALUE(-25.60), SIMDE_FLOAT16_VALUE(-0.34), SIMDE_FLOAT16_VALUE(-14.32), SIMDE_FLOAT16_VALUE(11.44),
        SIMDE_FLOAT16_VALUE(-0.16), SIMDE_FLOAT16_VALUE(44.81), SIMDE_FLOAT16_VALUE(-26.95), SIMDE_FLOAT16_VALUE(-20.70) } },
       {  SIMDE_FLOAT16_VALUE(-12.06), SIMDE_FLOAT16_VALUE(-20.03)},
     { {  SIMDE_FLOAT16_VALUE(20.63), SIMDE_FLOAT16_VALUE(-26.03), SIMDE_FLOAT16_VALUE(-12.06), SIMDE_FLOAT16_VALUE(-9.02),
        SIMDE_FLOAT16_VALUE(-7.24), SIMDE_FLOAT16_VALUE(21.25), SIMDE_FLOAT16_VALUE(7.83), SIMDE_FLOAT16_VALUE(13.60) },
       {  SIMDE_FLOAT16_VALUE(-25.60), SIMDE_FLOAT16_VALUE(-0.34), SIMDE_FLOAT16_VALUE(-20.03), SIMDE_FLOAT16_VALUE(11.44),
        SIMDE_FLOAT16_VALUE(-0.16), SIMDE_FLOAT16_VALUE(44.81), SIMDE_FLOAT16_VALUE(-26.95), SIMDE_FLOAT16_VALUE(-20.70) } } },
   { { {  SIMDE_FLOAT16_VALUE(-11.60), SIMDE_FLOAT16_VALUE(-14.50), SIMDE_FLOAT16_VALUE(45.43), SIMDE_FLOAT16_VALUE(40.80),
        SIMDE_FLOAT16_VALUE(-19.67), SIMDE_FLOAT16_VALUE(-0.54), SIMDE_FLOAT16_VALUE(31.88), SIMDE_FLOAT16_VALUE(14.74) },
       {  SIMDE_FLOAT16_VALUE(-31.78), SIMDE_FLOAT16_VALUE(8.81), SIMDE_FLOAT16_VALUE(10.59), SIMDE_FLOAT16_VALUE(6.10),
        SIMDE_FLOAT16_VALUE(-25.88), SIMDE_FLOAT16_VALUE(0.90), SIMDE_FLOAT16_VALUE(45.87), SIMDE_FLOAT16_VALUE(13.51) } },
       {  SIMDE_FLOAT16_VALUE(-26.80), SIMDE_FLOAT16_VALUE(13.43)},
     { {  SIMDE_FLOAT16_VALUE(-11.60), SIMDE_FLOAT16_VALUE(-14.50), SIMDE_FLOAT16_VALUE(45.43), SIMDE_FLOAT16_VALUE(-26.80),
        SIMDE_FLOAT16_VALUE(-19.67), SIMDE_FLOAT16_VALUE(-0.54), SIMDE_FLOAT16_VALUE(31.88), SIMDE_FLOAT16_VALUE(14.74) },
       {  SIMDE_FLOAT16_VALUE(-31.78), SIMDE_FLOAT16_VALUE(8.81), SIMDE_FLOAT16_VALUE(10.59), SIMDE_FLOAT16_VALUE(13.43),
        SIMDE_FLOAT16_VALUE(-25.88), SIMDE_FLOAT16_VALUE(0.90), SIMDE_FLOAT16_VALUE(45.87), SIMDE_FLOAT16_VALUE(13.51) } } },
   { { {  SIMDE_FLOAT16_VALUE(33.71), SIMDE_FLOAT16_VALUE(-5.48), SIMDE_FLOAT16_VALUE(-13.87), SIMDE_FLOAT16_VALUE(2.58),
        SIMDE_FLOAT16_VALUE(22.05), SIMDE_FLOAT16_VALUE(-25.14), SIMDE_FLOAT16_VALUE(32.71), SIMDE_FLOAT16_VALUE(49.78) },
       {  SIMDE_FLOAT16_VALUE(-33.81), SIMDE_FLOAT16_VALUE(-37.35), SIMDE_FLOAT16_VALUE(6.37), SIMDE_FLOAT16_VALUE(42.63),
        SIMDE_FLOAT16_VALUE(27.98), SIMDE_FLOAT16_VALUE(-47.79), SIMDE_FLOAT16_VALUE(0.37), SIMDE_FLOAT16_VALUE(24.16) } },
       {  SIMDE_FLOAT16_VALUE(-22.12), SIMDE_FLOAT16_VALUE(22.45)},
     { {  SIMDE_FLOAT16_VALUE(33.71), SIMDE_FLOAT16_VALUE(-5.48), SIMDE_FLOAT16_VALUE(-13.87), SIMDE_FLOAT16_VALUE(2.58),
        SIMDE_FLOAT16_VALUE(-22.12), SIMDE_FLOAT16_VALUE(-25.14), SIMDE_FLOAT16_VALUE(32.71), SIMDE_FLOAT16_VALUE(49.78) },
       {  SIMDE_FLOAT16_VALUE(-33.81), SIMDE_FLOAT16_VALUE(-37.35), SIMDE_FLOAT16_VALUE(6.37), SIMDE_FLOAT16_VALUE(42.63),
        SIMDE_FLOAT16_VALUE(22.45), SIMDE_FLOAT16_VALUE(-47.79), SIMDE_FLOAT16_VALUE(0.37), SIMDE_FLOAT16_VALUE(24.16) } } },
   { { {  SIMDE_FLOAT16_VALUE(35.13), SIMDE_FLOAT16_VALUE(-36.13), SIMDE_FLOAT16_VALUE(-42.60), SIMDE_FLOAT16_VALUE(-23.46),
        SIMDE_FLOAT16_VALUE(-42.93), SIMDE_FLOAT16_VALUE(-21.16), SIMDE_FLOAT16_VALUE(-29.86), SIMDE_FLOAT16_VALUE(29.04) },
       {  SIMDE_FLOAT16_VALUE(37.40), SIMDE_FLOAT16_VALUE(30.74), SIMDE_FLOAT16_VALUE(30.82), SIMDE_FLOAT16_VALUE(44.38),
        SIMDE_FLOAT16_VALUE(-30.52), SIMDE_FLOAT16_VALUE(42.55), SIMDE_FLOAT16_VALUE(16.70), SIMDE_FLOAT16_VALUE(47.97) } },
       {  SIMDE_FLOAT16_VALUE(41.68), SIMDE_FLOAT16_VALUE(12.98)},
     { {  SIMDE_FLOAT16_VALUE(35.13), SIMDE_FLOAT16_VALUE(-36.13), SIMDE_FLOAT16_VALUE(-42.60), SIMDE_FLOAT16_VALUE(-23.46),
        SIMDE_FLOAT16_VALUE(-42.93), SIMDE_FLOAT16_VALUE(41.68), SIMDE_FLOAT16_VALUE(-29.86), SIMDE_FLOAT16_VALUE(29.04) },
       {  SIMDE_FLOAT16_VALUE(37.40), SIMDE_FLOAT16_VALUE(30.74), SIMDE_FLOAT16_VALUE(30.82), SIMDE_FLOAT16_VALUE(44.38),
        SIMDE_FLOAT16_VALUE(-30.52), SIMDE_FLOAT16_VALUE(12.98), SIMDE_FLOAT16_VALUE(16.70), SIMDE_FLOAT16_VALUE(47.97) } } },
   { { {  SIMDE_FLOAT16_VALUE(45.22), SIMDE_FLOAT16_VALUE(-8.00), SIMDE_FLOAT16_VALUE(-27.03), SIMDE_FLOAT16_VALUE(48.60),
        SIMDE_FLOAT16_VALUE(19.87), SIMDE_FLOAT16_VALUE(-1.72), SIMDE_FLOAT16_VALUE(-45.40), SIMDE_FLOAT16_VALUE(-3.56) },
       {  SIMDE_FLOAT16_VALUE(36.60), SIMDE_FLOAT16_VALUE(-32.25), SIMDE_FLOAT16_VALUE(13.01), SIMDE_FLOAT16_VALUE(-12.64),
        SIMDE_FLOAT16_VALUE(22.43), SIMDE_FLOAT16_VALUE(1.87), SIMDE_FLOAT16_VALUE(-38.57), SIMDE_FLOAT16_VALUE(-24.61) } },
       {  SIMDE_FLOAT16_VALUE(49.75), SIMDE_FLOAT16_VALUE(-1.23)},
     { {  SIMDE_FLOAT16_VALUE(45.22), SIMDE_FLOAT16_VALUE(-8.00), SIMDE_FLOAT16_VALUE(-27.03), SIMDE_FLOAT16_VALUE(48.60),
        SIMDE_FLOAT16_VALUE(19.87), SIMDE_FLOAT16_VALUE(-1.72), SIMDE_FLOAT16_VALUE(49.75), SIMDE_FLOAT16_VALUE(-3.56) },
       {  SIMDE_FLOAT16_VALUE(36.60), SIMDE_FLOAT16_VALUE(-32.25), SIMDE_FLOAT16_VALUE(13.01), SIMDE_FLOAT16_VALUE(-12.64),
        SIMDE_FLOAT16_VALUE(22.43), SIMDE_FLOAT16_VALUE(1.87), SIMDE_FLOAT16_VALUE(-1.23), SIMDE_FLOAT16_VALUE(-24.61) } } },
   { { {  SIMDE_FLOAT16_VALUE(24.31), SIMDE_FLOAT16_VALUE(-43.53), SIMDE_FLOAT16_VALUE(20.69), SIMDE_FLOAT16_VALUE(26.28),
        SIMDE_FLOAT16_VALUE(44.06), SIMDE_FLOAT16_VALUE(42.57), SIMDE_FLOAT16_VALUE(7.84), SIMDE_FLOAT16_VALUE(-4.34) },
       {  SIMDE_FLOAT16_VALUE(-7.29), SIMDE_FLOAT16_VALUE(5.56), SIMDE_FLOAT16_VALUE(-20.99), SIMDE_FLOAT16_VALUE(-46.49),
        SIMDE_FLOAT16_VALUE(24.87), SIMDE_FLOAT16_VALUE(40.56), SIMDE_FLOAT16_VALUE(-20.02), SIMDE_FLOAT16_VALUE(38.66) } },
       {  SIMDE_FLOAT16_VALUE(17.79), SIMDE_FLOAT16_VALUE(37.56)},
     { {  SIMDE_FLOAT16_VALUE(24.31), SIMDE_FLOAT16_VALUE(-43.53), SIMDE_FLOAT16_VALUE(20.69), SIMDE_FLOAT16_VALUE(26.28),
        SIMDE_FLOAT16_VALUE(44.06), SIMDE_FLOAT16_VALUE(42.57), SIMDE_FLOAT16_VALUE(7.84), SIMDE_FLOAT16_VALUE(17.79) },
       {  SIMDE_FLOAT16_VALUE(-7.29), SIMDE_FLOAT16_VALUE(5.56), SIMDE_FLOAT16_VALUE(-20.99), SIMDE_FLOAT16_VALUE(-46.49),
        SIMDE_FLOAT16_VALUE(24.87), SIMDE_FLOAT16_VALUE(40.56), SIMDE_FLOAT16_VALUE(-20.02), SIMDE_FLOAT16_VALUE(37.56) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x8x2_t r, src, expected;
    src.val[0] = simde_vld1q_f16(test_vec[i].src[0]);
    src.val[1] = simde_vld1q_f16(test_vec[i].src[1]);

    SIMDE_CONSTIFY_8_(simde_vld2q_lane_f16, r, (HEDLEY_UNREACHABLE(), r), i, test_vec[i].buf, src);

    expected.val[0] = simde_vld1q_f16(test_vec[i].r[0]);
    expected.val[1] = simde_vld1q_f16(test_vec[i].r[1]);

    simde_test_arm_neon_assert_equal_f16x8(r.val[0], expected.val[0], INT_MAX);
    simde_test_arm_neon_assert_equal_f16x8(r.val[1], expected.val[1], INT_MAX);
  }

  return 0;
}

static int
test_simde_vld2q_lane_f32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    simde_float32_t src[2][4];
    simde_float32_t buf[2];
    simde_float32_t r[2][4];
  } test_vec[] = {
   { { {  SIMDE_FLOAT32_C(2894.40), SIMDE_FLOAT32_C(2128.37), SIMDE_FLOAT32_C(-2323.09), SIMDE_FLOAT32_C(1580.08) },
       {  SIMDE_FLOAT32_C(2459.79), SIMDE_FLOAT32_C(-3713.19), SIMDE_FLOAT32_C(3258.52), SIMDE_FLOAT32_C(-1845.95) } },
       {  SIMDE_FLOAT32_C(806.30), SIMDE_FLOAT32_C(3875.55)},
     { {  SIMDE_FLOAT32_C(806.30), SIMDE_FLOAT32_C(2128.37), SIMDE_FLOAT32_C(-2323.09), SIMDE_FLOAT32_C(1580.08) },
       {  SIMDE_FLOAT32_C(3875.55), SIMDE_FLOAT32_C(-3713.19), SIMDE_FLOAT32_C(3258.52), SIMDE_FLOAT32_C(-1845.95) } } },
   { { {  SIMDE_FLOAT32_C(-827.29), SIMDE_FLOAT32_C(-188.20), SIMDE_FLOAT32_C(3036.33), SIMDE_FLOAT32_C(-2521.65) },
       {  SIMDE_FLOAT32_C(1688.02), SIMDE_FLOAT32_C(-4475.05), SIMDE_FLOAT32_C(-1748.43), SIMDE_FLOAT32_C(-4757.62) } },
       {  SIMDE_FLOAT32_C(3632.65), SIMDE_FLOAT32_C(4364.49)},
     { {  SIMDE_FLOAT32_C(-827.29), SIMDE_FLOAT32_C(3632.65), SIMDE_FLOAT32_C(3036.33), SIMDE_FLOAT32_C(-2521.65) },
       {  SIMDE_FLOAT32_C(1688.02), SIMDE_FLOAT32_C(4364.49), SIMDE_FLOAT32_C(-1748.43), SIMDE_FLOAT32_C(-4757.62) } } },
   { { {  SIMDE_FLOAT32_C(-1210.04), SIMDE_FLOAT32_C(-1519.92), SIMDE_FLOAT32_C(-362.73), SIMDE_FLOAT32_C(-1943.77) },
       {  SIMDE_FLOAT32_C(-3218.48), SIMDE_FLOAT32_C(3093.08), SIMDE_FLOAT32_C(1976.08), SIMDE_FLOAT32_C(3235.56) } },
       {  SIMDE_FLOAT32_C(91.16), SIMDE_FLOAT32_C(-1366.95)},
     { {  SIMDE_FLOAT32_C(-1210.04), SIMDE_FLOAT32_C(-1519.92), SIMDE_FLOAT32_C(91.16), SIMDE_FLOAT32_C(-1943.77) },
       {  SIMDE_FLOAT32_C(-3218.48), SIMDE_FLOAT32_C(3093.08), SIMDE_FLOAT32_C(-1366.95), SIMDE_FLOAT32_C(3235.56) } } },
   { { {  SIMDE_FLOAT32_C(1155.21), SIMDE_FLOAT32_C(2979.92), SIMDE_FLOAT32_C(3342.26), SIMDE_FLOAT32_C(2850.18) },
       {  SIMDE_FLOAT32_C(-1185.46), SIMDE_FLOAT32_C(1494.90), SIMDE_FLOAT32_C(3871.56), SIMDE_FLOAT32_C(4240.34) } },
       {  SIMDE_FLOAT32_C(4082.13), SIMDE_FLOAT32_C(479.75)},
     { {  SIMDE_FLOAT32_C(1155.21), SIMDE_FLOAT32_C(2979.92), SIMDE_FLOAT32_C(3342.26), SIMDE_FLOAT32_C(4082.13) },
       {  SIMDE_FLOAT32_C(-1185.46), SIMDE_FLOAT32_C(1494.90), SIMDE_FLOAT32_C(3871.56), SIMDE_FLOAT32_C(479.75) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4x2_t r, src, expected;
    src.val[0] = simde_vld1q_f32(test_vec[i].src[0]);
    src.val[1] = simde_vld1q_f32(test_vec[i].src[1]);

    SIMDE_CONSTIFY_4_(simde_vld2q_lane_f32, r, (HEDLEY_UNREACHABLE(), r), i, test_vec[i].buf, src);

    expected.val[0] = simde_vld1q_f32(test_vec[i].r[0]);
    expected.val[1] = simde_vld1q_f32(test_vec[i].r[1]);

    simde_test_arm_neon_assert_equal_f32x4(r.val[0], expected.val[0], INT_MAX);
    simde_test_arm_neon_assert_equal_f32x4(r.val[1], expected.val[1], INT_MAX);
  }

  return 0;

}

static int
test_simde_vld2q_lane_f64 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    simde_float64_t src[2][2];
    simde_float64_t buf[2];
    simde_float64_t r[2][2];
  } test_vec[] = {
   { { {  SIMDE_FLOAT64_C(-441230.65), SIMDE_FLOAT64_C(460847.11) },
       {  SIMDE_FLOAT64_C(178930.01), SIMDE_FLOAT64_C(325559.94) } },
       {  SIMDE_FLOAT64_C(244879.30), SIMDE_FLOAT64_C(-169707.98)},
     { {  SIMDE_FLOAT64_C(244879.30), SIMDE_FLOAT64_C(460847.11) },
       {  SIMDE_FLOAT64_C(-169707.98), SIMDE_FLOAT64_C(325559.94) } } },
   { { {  SIMDE_FLOAT64_C(-157130.88), SIMDE_FLOAT64_C(-243630.90) },
       {  SIMDE_FLOAT64_C(173252.82), SIMDE_FLOAT64_C(96002.40) } },
       {  SIMDE_FLOAT64_C(429185.16), SIMDE_FLOAT64_C(-474490.37)},
     { {  SIMDE_FLOAT64_C(-157130.88), SIMDE_FLOAT64_C(429185.16) },
       {  SIMDE_FLOAT64_C(173252.82), SIMDE_FLOAT64_C(-474490.37) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2x2_t r, src, expected;
    src.val[0] = simde_vld1q_f64(test_vec[i].src[0]);
    src.val[1] = simde_vld1q_f64(test_vec[i].src[1]);

    SIMDE_CONSTIFY_2_(simde_vld2q_lane_f64, r, (HEDLEY_UNREACHABLE(), r), i, test_vec[i].buf, src);

    expected.val[0] = simde_vld1q_f64(test_vec[i].r[0]);
    expected.val[1] = simde_vld1q_f64(test_vec[i].r[1]);

    simde_test_arm_neon_assert_equal_f64x2(r.val[0], expected.val[0], INT_MAX);
    simde_test_arm_neon_assert_equal_f64x2(r.val[1], expected.val[1], INT_MAX);
  }

  return 0;

}

static int
test_simde_vld2_lane_p8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_poly8_t src[2][8];
    simde_poly8_t buf[2];
    simde_poly8_t r[2][8];
  } test_vec[] = {
   { { {   SIMDE_POLY8_C(16), SIMDE_POLY8_C(44),  SIMDE_POLY8_C(6), SIMDE_POLY8_C(49),
         SIMDE_POLY8_C(48),  SIMDE_POLY8_C(22), SIMDE_POLY8_C(4), SIMDE_POLY8_C(6) },
       {   SIMDE_POLY8_C(7), SIMDE_POLY8_C(40),  SIMDE_POLY8_C(17), SIMDE_POLY8_C(15),
         SIMDE_POLY8_C(21),  SIMDE_POLY8_C(4), SIMDE_POLY8_C(14),  SIMDE_POLY8_C(25) } },
       {  SIMDE_POLY8_C(43),  SIMDE_POLY8_C(26)},
     { {  SIMDE_POLY8_C(43), SIMDE_POLY8_C(44),  SIMDE_POLY8_C(6), SIMDE_POLY8_C(49),
         SIMDE_POLY8_C(48),  SIMDE_POLY8_C(22), SIMDE_POLY8_C(4), SIMDE_POLY8_C(6) },
       {   SIMDE_POLY8_C(26), SIMDE_POLY8_C(40),  SIMDE_POLY8_C(17), SIMDE_POLY8_C(15),
         SIMDE_POLY8_C(21),  SIMDE_POLY8_C(4), SIMDE_POLY8_C(14),  SIMDE_POLY8_C(25) } } },
   { { {  SIMDE_POLY8_C(0),  SIMDE_POLY8_C(47), SIMDE_POLY8_C(9), SIMDE_POLY8_C(28),
         SIMDE_POLY8_C(8),  SIMDE_POLY8_C(39),  SIMDE_POLY8_C(37), SIMDE_POLY8_C(35) },
       {  SIMDE_POLY8_C(38), SIMDE_POLY8_C(35), SIMDE_POLY8_C(27),  SIMDE_POLY8_C(16),
        SIMDE_POLY8_C(14),  SIMDE_POLY8_C(1),  SIMDE_POLY8_C(16), SIMDE_POLY8_C(5) } },
       {   SIMDE_POLY8_C(48), SIMDE_POLY8_C(10)},
     { {  SIMDE_POLY8_C(0),  SIMDE_POLY8_C(48), SIMDE_POLY8_C(9), SIMDE_POLY8_C(28),
         SIMDE_POLY8_C(8),  SIMDE_POLY8_C(39),  SIMDE_POLY8_C(37), SIMDE_POLY8_C(35) },
       {  SIMDE_POLY8_C(38), SIMDE_POLY8_C(10), SIMDE_POLY8_C(27),  SIMDE_POLY8_C(16),
        SIMDE_POLY8_C(14),  SIMDE_POLY8_C(1),  SIMDE_POLY8_C(16), SIMDE_POLY8_C(5) } } },
   { { {   SIMDE_POLY8_C(45),  SIMDE_POLY8_C(48),  SIMDE_POLY8_C(30),  SIMDE_POLY8_C(12),
        SIMDE_POLY8_C(2), SIMDE_POLY8_C(21), SIMDE_POLY8_C(16), SIMDE_POLY8_C(39) },
       {   SIMDE_POLY8_C(3), SIMDE_POLY8_C(30),  SIMDE_POLY8_C(37),  SIMDE_POLY8_C(12),
        SIMDE_POLY8_C(17), SIMDE_POLY8_C(23),  SIMDE_POLY8_C(41), SIMDE_POLY8_C(18) } },
       {   SIMDE_POLY8_C(30),  SIMDE_POLY8_C(13)},
     { {   SIMDE_POLY8_C(45),  SIMDE_POLY8_C(48),  SIMDE_POLY8_C(30),  SIMDE_POLY8_C(12),
        SIMDE_POLY8_C(2), SIMDE_POLY8_C(21), SIMDE_POLY8_C(16), SIMDE_POLY8_C(39) },
       {   SIMDE_POLY8_C(3), SIMDE_POLY8_C(30),  SIMDE_POLY8_C(13),  SIMDE_POLY8_C(12),
        SIMDE_POLY8_C(17), SIMDE_POLY8_C(23),  SIMDE_POLY8_C(41), SIMDE_POLY8_C(18) } } },
   { { {   SIMDE_POLY8_C(9),  SIMDE_POLY8_C(39), SIMDE_POLY8_C(49),  SIMDE_POLY8_C(10),
         SIMDE_POLY8_C(45), SIMDE_POLY8_C(24),  SIMDE_POLY8_C(17), SIMDE_POLY8_C(30) },
       {   SIMDE_POLY8_C(36), SIMDE_POLY8_C(20),  SIMDE_POLY8_C(15),  SIMDE_POLY8_C(21),
         SIMDE_POLY8_C(23), SIMDE_POLY8_C(22),  SIMDE_POLY8_C(39),  SIMDE_POLY8_C(18) } },
       {  SIMDE_POLY8_C(13),  SIMDE_POLY8_C(37)},
     { {   SIMDE_POLY8_C(9),  SIMDE_POLY8_C(39), SIMDE_POLY8_C(49), SIMDE_POLY8_C(13),
         SIMDE_POLY8_C(45), SIMDE_POLY8_C(24),  SIMDE_POLY8_C(17), SIMDE_POLY8_C(30) },
       {   SIMDE_POLY8_C(36), SIMDE_POLY8_C(20),  SIMDE_POLY8_C(15),  SIMDE_POLY8_C(37),
         SIMDE_POLY8_C(23), SIMDE_POLY8_C(22),  SIMDE_POLY8_C(39),  SIMDE_POLY8_C(18) } } },
   { { {  SIMDE_POLY8_C(17), SIMDE_POLY8_C(17),  SIMDE_POLY8_C(11), SIMDE_POLY8_C(43),
         SIMDE_POLY8_C(20),  SIMDE_POLY8_C(10), SIMDE_POLY8_C(44), SIMDE_POLY8_C(43) },
       {  SIMDE_POLY8_C(23),  SIMDE_POLY8_C(4),  SIMDE_POLY8_C(32),  SIMDE_POLY8_C(2),
         SIMDE_POLY8_C(39),  SIMDE_POLY8_C(1),  SIMDE_POLY8_C(37), SIMDE_POLY8_C(42) } },
       {   SIMDE_POLY8_C(40), SIMDE_POLY8_C(34)},
     { {  SIMDE_POLY8_C(17), SIMDE_POLY8_C(17),  SIMDE_POLY8_C(11), SIMDE_POLY8_C(43),
         SIMDE_POLY8_C(40),  SIMDE_POLY8_C(10), SIMDE_POLY8_C(44), SIMDE_POLY8_C(43) },
       {  SIMDE_POLY8_C(23),  SIMDE_POLY8_C(4),  SIMDE_POLY8_C(32),  SIMDE_POLY8_C(2),
        SIMDE_POLY8_C(34),  SIMDE_POLY8_C(1),  SIMDE_POLY8_C(37), SIMDE_POLY8_C(42) } } },
   { { {  SIMDE_POLY8_C(16), SIMDE_POLY8_C(35),  SIMDE_POLY8_C(33),  SIMDE_POLY8_C(19),
        SIMDE_POLY8_C(15),  SIMDE_POLY8_C(17), SIMDE_POLY8_C(13),  SIMDE_POLY8_C(49) },
       {  SIMDE_POLY8_C(21),  SIMDE_POLY8_C(24),  SIMDE_POLY8_C(3), SIMDE_POLY8_C(10),
         SIMDE_POLY8_C(31), SIMDE_POLY8_C(24),  SIMDE_POLY8_C(46),  SIMDE_POLY8_C(14) } },
       {   SIMDE_POLY8_C(24),  SIMDE_POLY8_C(3)},
     { {  SIMDE_POLY8_C(16), SIMDE_POLY8_C(35),  SIMDE_POLY8_C(33),  SIMDE_POLY8_C(19),
        SIMDE_POLY8_C(15),  SIMDE_POLY8_C(24), SIMDE_POLY8_C(13),  SIMDE_POLY8_C(49) },
       {  SIMDE_POLY8_C(21),  SIMDE_POLY8_C(24),  SIMDE_POLY8_C(3), SIMDE_POLY8_C(10),
         SIMDE_POLY8_C(31),  SIMDE_POLY8_C(3),  SIMDE_POLY8_C(46),  SIMDE_POLY8_C(14) } } },
   { { {  SIMDE_POLY8_C(25),  SIMDE_POLY8_C(9),  SIMDE_POLY8_C(16), SIMDE_POLY8_C(33),
         SIMDE_POLY8_C(14),  SIMDE_POLY8_C(45), SIMDE_POLY8_C(0),  SIMDE_POLY8_C(45) },
       {   SIMDE_POLY8_C(40), SIMDE_POLY8_C(36), SIMDE_POLY8_C(38),  SIMDE_POLY8_C(48),
         SIMDE_POLY8_C(20),  SIMDE_POLY8_C(22), SIMDE_POLY8_C(1),  SIMDE_POLY8_C(43) } },
       {   SIMDE_POLY8_C(33),  SIMDE_POLY8_C(50)},
     { {  SIMDE_POLY8_C(25),  SIMDE_POLY8_C(9),  SIMDE_POLY8_C(16), SIMDE_POLY8_C(33),
         SIMDE_POLY8_C(14),  SIMDE_POLY8_C(45),  SIMDE_POLY8_C(33),  SIMDE_POLY8_C(45) },
       {   SIMDE_POLY8_C(40), SIMDE_POLY8_C(36), SIMDE_POLY8_C(38),  SIMDE_POLY8_C(48),
         SIMDE_POLY8_C(20),  SIMDE_POLY8_C(22),  SIMDE_POLY8_C(50),  SIMDE_POLY8_C(43) } } },
   { { {  SIMDE_POLY8_C(38),  SIMDE_POLY8_C(16), SIMDE_POLY8_C(32),  SIMDE_POLY8_C(48),
        SIMDE_POLY8_C(28),  SIMDE_POLY8_C(6),  SIMDE_POLY8_C(48),  SIMDE_POLY8_C(36) },
       {  SIMDE_POLY8_C(12), SIMDE_POLY8_C(7),  SIMDE_POLY8_C(12),  SIMDE_POLY8_C(12),
        SIMDE_POLY8_C(33), SIMDE_POLY8_C(28), SIMDE_POLY8_C(26),  SIMDE_POLY8_C(43) } },
       {   SIMDE_POLY8_C(42),  SIMDE_POLY8_C(7)},
     { {  SIMDE_POLY8_C(38),  SIMDE_POLY8_C(16), SIMDE_POLY8_C(32),  SIMDE_POLY8_C(48),
        SIMDE_POLY8_C(28),  SIMDE_POLY8_C(6),  SIMDE_POLY8_C(48),  SIMDE_POLY8_C(42) },
       {  SIMDE_POLY8_C(12), SIMDE_POLY8_C(7),  SIMDE_POLY8_C(12),  SIMDE_POLY8_C(12),
        SIMDE_POLY8_C(33), SIMDE_POLY8_C(28), SIMDE_POLY8_C(26),  SIMDE_POLY8_C(7) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_poly8x8x2_t r, src, expected;
    src.val[0] = simde_vld1_p8(test_vec[i].src[0]);
    src.val[1] = simde_vld1_p8(test_vec[i].src[1]);

    SIMDE_CONSTIFY_8_(simde_vld2_lane_p8, r, (HEDLEY_UNREACHABLE(), r), i, test_vec[i].buf, src);

    expected.val[0] = simde_vld1_p8(test_vec[i].r[0]);
    expected.val[1] = simde_vld1_p8(test_vec[i].r[1]);

    simde_test_arm_neon_assert_equal_p8x8(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_p8x8(r.val[1], expected.val[1]);
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_poly8x8x2_t src = simde_test_arm_neon_random_p8x8x2();
    simde_poly8_t buf[2];
    simde_poly8x8x2_t r;
    simde_test_arm_neon_write_p8x8x2(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_random_memory(2, HEDLEY_REINTERPRET_CAST(uint8_t*, buf));
    simde_test_codegen_write_vp8(2, 2, buf, SIMDE_TEST_VEC_POS_MIDDLE);
    SIMDE_CONSTIFY_8_(simde_vld2_lane_p8, r, (HEDLEY_UNREACHABLE(), r), i, buf, src);
    simde_test_arm_neon_write_p8x8x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld2_lane_p16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_poly16_t src[2][4];
    simde_poly16_t buf[2];
    simde_poly16_t r[2][4];
  } test_vec[] = {
   { { {  SIMDE_POLY16_C(124), SIMDE_POLY16_C(412), SIMDE_POLY16_C(312), SIMDE_POLY16_C(107) },
       {  SIMDE_POLY16_C(349), SIMDE_POLY16_C(217), SIMDE_POLY16_C(241), SIMDE_POLY16_C(95) } },
       {  SIMDE_POLY16_C(275), SIMDE_POLY16_C(317)},
     { {  SIMDE_POLY16_C(275), SIMDE_POLY16_C(412), SIMDE_POLY16_C(312), SIMDE_POLY16_C(107) },
       {  SIMDE_POLY16_C(317), SIMDE_POLY16_C(217), SIMDE_POLY16_C(241), SIMDE_POLY16_C(95) } } },
   { { {  SIMDE_POLY16_C(378), SIMDE_POLY16_C(448), SIMDE_POLY16_C(60), SIMDE_POLY16_C(474) },
       {  SIMDE_POLY16_C(266), SIMDE_POLY16_C(135), SIMDE_POLY16_C(422), SIMDE_POLY16_C(223) } },
       {  SIMDE_POLY16_C(297), SIMDE_POLY16_C(5)},
     { {  SIMDE_POLY16_C(378), SIMDE_POLY16_C(297), SIMDE_POLY16_C(60), SIMDE_POLY16_C(474) },
       {  SIMDE_POLY16_C(266), SIMDE_POLY16_C(5), SIMDE_POLY16_C(422), SIMDE_POLY16_C(223) } } },
   { { {  SIMDE_POLY16_C(197), SIMDE_POLY16_C(3), SIMDE_POLY16_C(245), SIMDE_POLY16_C(218) },
       {  SIMDE_POLY16_C(216), SIMDE_POLY16_C(262), SIMDE_POLY16_C(180), SIMDE_POLY16_C(60) } },
       {  SIMDE_POLY16_C(96), SIMDE_POLY16_C(492)},
     { {  SIMDE_POLY16_C(197), SIMDE_POLY16_C(3), SIMDE_POLY16_C(96), SIMDE_POLY16_C(218) },
       {  SIMDE_POLY16_C(216), SIMDE_POLY16_C(262), SIMDE_POLY16_C(492), SIMDE_POLY16_C(60) } } },
   { { {  SIMDE_POLY16_C(395), SIMDE_POLY16_C(374), SIMDE_POLY16_C(448), SIMDE_POLY16_C(445) },
       {  SIMDE_POLY16_C(60), SIMDE_POLY16_C(486), SIMDE_POLY16_C(283), SIMDE_POLY16_C(298) } },
       {  SIMDE_POLY16_C(218), SIMDE_POLY16_C(225)},
     { {  SIMDE_POLY16_C(395), SIMDE_POLY16_C(374), SIMDE_POLY16_C(448), SIMDE_POLY16_C(218) },
       {  SIMDE_POLY16_C(60), SIMDE_POLY16_C(486), SIMDE_POLY16_C(283), SIMDE_POLY16_C(225) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_poly16x4x2_t r, src, expected;
    src.val[0] = simde_vld1_p16(test_vec[i].src[0]);
    src.val[1] = simde_vld1_p16(test_vec[i].src[1]);

    SIMDE_CONSTIFY_4_(simde_vld2_lane_p16, r, (HEDLEY_UNREACHABLE(), r), i, test_vec[i].buf, src);

    expected.val[0] = simde_vld1_p16(test_vec[i].r[0]);
    expected.val[1] = simde_vld1_p16(test_vec[i].r[1]);

    simde_test_arm_neon_assert_equal_p16x4(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_p16x4(r.val[1], expected.val[1]);
  }

  return 0;
#else
  for (int i = 0 ; i < 4 ; i++) {
    simde_poly16x4x2_t src = simde_test_arm_neon_random_p16x4x2();
    simde_poly16_t buf[2];
    simde_poly16x4x2_t r;
    simde_test_arm_neon_write_p16x4x2(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_random_memory(4, HEDLEY_REINTERPRET_CAST(uint8_t*, buf));
    simde_test_codegen_write_vp16(2, 2, buf, SIMDE_TEST_VEC_POS_MIDDLE);
    SIMDE_CONSTIFY_4_(simde_vld2_lane_p16, r, (HEDLEY_UNREACHABLE(), r), i, buf, src);
    simde_test_arm_neon_write_p16x4x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld2_lane_p64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_poly64_t src[2][1];
    simde_poly64_t buf[2];
    simde_poly64_t r[2][1];
  } test_vec[] = {
   { { {  SIMDE_POLY64_C(382464207) },
       {  SIMDE_POLY64_C(391984763) } },
       {  SIMDE_POLY64_C(283052241), SIMDE_POLY64_C(176704794)},
     { {  SIMDE_POLY64_C(283052241) },
       {  SIMDE_POLY64_C(176704794) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_poly64x1x2_t r, src, expected;
    src.val[0] = simde_vld1_p64(test_vec[i].src[0]);
    src.val[1] = simde_vld1_p64(test_vec[i].src[1]);

    r = simde_vld2_lane_p64(test_vec[i].buf, src, 0);

    expected.val[0] = simde_vld1_p64(test_vec[i].r[0]);
    expected.val[1] = simde_vld1_p64(test_vec[i].r[1]);

    simde_test_arm_neon_assert_equal_p64x1(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_p64x1(r.val[1], expected.val[1]);
  }

  return 0;
#else
  for (int i = 0 ; i < 4 ; i++) {
    simde_poly64x1x2_t src = simde_test_arm_neon_random_p64x1x2();
    simde_poly64_t buf[2];
    simde_poly64x1x2_t r;
    simde_test_arm_neon_write_p64x1x2(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_random_memory(16, HEDLEY_REINTERPRET_CAST(uint8_t*, buf));
    simde_test_codegen_write_vp64(2, 2, buf, SIMDE_TEST_VEC_POS_MIDDLE);
    r = simde_vld2_lane_p64(buf, src, 0);
    simde_test_arm_neon_write_p64x1x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld2q_lane_p8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_poly8_t src[2][16];
    simde_poly8_t buf[2];
    simde_poly8_t r[2][16];
  } test_vec[] = {
   { { {  SIMDE_POLY8_C(46), SIMDE_POLY8_C(42), SIMDE_POLY8_C(1), SIMDE_POLY8_C(9), SIMDE_POLY8_C(24), SIMDE_POLY8_C(23), SIMDE_POLY8_C(11), SIMDE_POLY8_C(37),
        SIMDE_POLY8_C(22), SIMDE_POLY8_C(30), SIMDE_POLY8_C(25), SIMDE_POLY8_C(27), SIMDE_POLY8_C(10), SIMDE_POLY8_C(26), SIMDE_POLY8_C(1), SIMDE_POLY8_C(10) },
       {  SIMDE_POLY8_C(13), SIMDE_POLY8_C(29), SIMDE_POLY8_C(22), SIMDE_POLY8_C(40), SIMDE_POLY8_C(48), SIMDE_POLY8_C(40), SIMDE_POLY8_C(0), SIMDE_POLY8_C(12),
        SIMDE_POLY8_C(18), SIMDE_POLY8_C(35), SIMDE_POLY8_C(43), SIMDE_POLY8_C(30), SIMDE_POLY8_C(32), SIMDE_POLY8_C(30), SIMDE_POLY8_C(21), SIMDE_POLY8_C(36) } },
       {  SIMDE_POLY8_C(13), SIMDE_POLY8_C(15)},
     { {  SIMDE_POLY8_C(13), SIMDE_POLY8_C(42), SIMDE_POLY8_C(1), SIMDE_POLY8_C(9), SIMDE_POLY8_C(24), SIMDE_POLY8_C(23), SIMDE_POLY8_C(11), SIMDE_POLY8_C(37),
        SIMDE_POLY8_C(22), SIMDE_POLY8_C(30), SIMDE_POLY8_C(25), SIMDE_POLY8_C(27), SIMDE_POLY8_C(10), SIMDE_POLY8_C(26), SIMDE_POLY8_C(1), SIMDE_POLY8_C(10) },
       {  SIMDE_POLY8_C(15), SIMDE_POLY8_C(29), SIMDE_POLY8_C(22), SIMDE_POLY8_C(40), SIMDE_POLY8_C(48), SIMDE_POLY8_C(40), SIMDE_POLY8_C(0), SIMDE_POLY8_C(12),
        SIMDE_POLY8_C(18), SIMDE_POLY8_C(35), SIMDE_POLY8_C(43), SIMDE_POLY8_C(30), SIMDE_POLY8_C(32), SIMDE_POLY8_C(30), SIMDE_POLY8_C(21), SIMDE_POLY8_C(36) } } },
   { { {  SIMDE_POLY8_C(20), SIMDE_POLY8_C(7), SIMDE_POLY8_C(32), SIMDE_POLY8_C(38), SIMDE_POLY8_C(1), SIMDE_POLY8_C(28), SIMDE_POLY8_C(5), SIMDE_POLY8_C(1),
        SIMDE_POLY8_C(17), SIMDE_POLY8_C(10), SIMDE_POLY8_C(10), SIMDE_POLY8_C(23), SIMDE_POLY8_C(26), SIMDE_POLY8_C(1), SIMDE_POLY8_C(37), SIMDE_POLY8_C(35) },
       {  SIMDE_POLY8_C(18), SIMDE_POLY8_C(31), SIMDE_POLY8_C(37), SIMDE_POLY8_C(26), SIMDE_POLY8_C(9), SIMDE_POLY8_C(14), SIMDE_POLY8_C(17), SIMDE_POLY8_C(38),
        SIMDE_POLY8_C(8), SIMDE_POLY8_C(27), SIMDE_POLY8_C(45), SIMDE_POLY8_C(15), SIMDE_POLY8_C(0), SIMDE_POLY8_C(36), SIMDE_POLY8_C(1), SIMDE_POLY8_C(20) } },
       {  SIMDE_POLY8_C(11), SIMDE_POLY8_C(6)},
     { {  SIMDE_POLY8_C(20), SIMDE_POLY8_C(11), SIMDE_POLY8_C(32), SIMDE_POLY8_C(38), SIMDE_POLY8_C(1), SIMDE_POLY8_C(28), SIMDE_POLY8_C(5), SIMDE_POLY8_C(1),
        SIMDE_POLY8_C(17), SIMDE_POLY8_C(10), SIMDE_POLY8_C(10), SIMDE_POLY8_C(23), SIMDE_POLY8_C(26), SIMDE_POLY8_C(1), SIMDE_POLY8_C(37), SIMDE_POLY8_C(35) },
       {  SIMDE_POLY8_C(18), SIMDE_POLY8_C(6), SIMDE_POLY8_C(37), SIMDE_POLY8_C(26), SIMDE_POLY8_C(9), SIMDE_POLY8_C(14), SIMDE_POLY8_C(17), SIMDE_POLY8_C(38),
        SIMDE_POLY8_C(8), SIMDE_POLY8_C(27), SIMDE_POLY8_C(45), SIMDE_POLY8_C(15), SIMDE_POLY8_C(0), SIMDE_POLY8_C(36), SIMDE_POLY8_C(1), SIMDE_POLY8_C(20) } } },
   { { {  SIMDE_POLY8_C(13), SIMDE_POLY8_C(26), SIMDE_POLY8_C(44), SIMDE_POLY8_C(35), SIMDE_POLY8_C(42), SIMDE_POLY8_C(3), SIMDE_POLY8_C(9), SIMDE_POLY8_C(23),
        SIMDE_POLY8_C(0), SIMDE_POLY8_C(20), SIMDE_POLY8_C(17), SIMDE_POLY8_C(46), SIMDE_POLY8_C(15), SIMDE_POLY8_C(39), SIMDE_POLY8_C(26), SIMDE_POLY8_C(34) },
       {  SIMDE_POLY8_C(5), SIMDE_POLY8_C(22), SIMDE_POLY8_C(30), SIMDE_POLY8_C(9), SIMDE_POLY8_C(17), SIMDE_POLY8_C(44), SIMDE_POLY8_C(46), SIMDE_POLY8_C(25),
        SIMDE_POLY8_C(45), SIMDE_POLY8_C(46), SIMDE_POLY8_C(16), SIMDE_POLY8_C(6), SIMDE_POLY8_C(40), SIMDE_POLY8_C(37), SIMDE_POLY8_C(15), SIMDE_POLY8_C(11) } },
       {  SIMDE_POLY8_C(25), SIMDE_POLY8_C(25)},
     { {  SIMDE_POLY8_C(13), SIMDE_POLY8_C(26), SIMDE_POLY8_C(25), SIMDE_POLY8_C(35), SIMDE_POLY8_C(42), SIMDE_POLY8_C(3), SIMDE_POLY8_C(9), SIMDE_POLY8_C(23),
        SIMDE_POLY8_C(0), SIMDE_POLY8_C(20), SIMDE_POLY8_C(17), SIMDE_POLY8_C(46), SIMDE_POLY8_C(15), SIMDE_POLY8_C(39), SIMDE_POLY8_C(26), SIMDE_POLY8_C(34) },
       {  SIMDE_POLY8_C(5), SIMDE_POLY8_C(22), SIMDE_POLY8_C(25), SIMDE_POLY8_C(9), SIMDE_POLY8_C(17), SIMDE_POLY8_C(44), SIMDE_POLY8_C(46), SIMDE_POLY8_C(25),
        SIMDE_POLY8_C(45), SIMDE_POLY8_C(46), SIMDE_POLY8_C(16), SIMDE_POLY8_C(6), SIMDE_POLY8_C(40), SIMDE_POLY8_C(37), SIMDE_POLY8_C(15), SIMDE_POLY8_C(11) } } },
   { { {  SIMDE_POLY8_C(6), SIMDE_POLY8_C(37), SIMDE_POLY8_C(49), SIMDE_POLY8_C(9), SIMDE_POLY8_C(38), SIMDE_POLY8_C(40), SIMDE_POLY8_C(21), SIMDE_POLY8_C(28),
        SIMDE_POLY8_C(2), SIMDE_POLY8_C(1), SIMDE_POLY8_C(18), SIMDE_POLY8_C(31), SIMDE_POLY8_C(34), SIMDE_POLY8_C(2), SIMDE_POLY8_C(23), SIMDE_POLY8_C(35) },
       {  SIMDE_POLY8_C(17), SIMDE_POLY8_C(12), SIMDE_POLY8_C(24), SIMDE_POLY8_C(48), SIMDE_POLY8_C(30), SIMDE_POLY8_C(16), SIMDE_POLY8_C(21), SIMDE_POLY8_C(31),
        SIMDE_POLY8_C(39), SIMDE_POLY8_C(29), SIMDE_POLY8_C(4), SIMDE_POLY8_C(18), SIMDE_POLY8_C(47), SIMDE_POLY8_C(15), SIMDE_POLY8_C(49), SIMDE_POLY8_C(18) } },
       {  SIMDE_POLY8_C(41), SIMDE_POLY8_C(33)},
     { {  SIMDE_POLY8_C(6), SIMDE_POLY8_C(37), SIMDE_POLY8_C(49), SIMDE_POLY8_C(41), SIMDE_POLY8_C(38), SIMDE_POLY8_C(40), SIMDE_POLY8_C(21), SIMDE_POLY8_C(28),
        SIMDE_POLY8_C(2), SIMDE_POLY8_C(1), SIMDE_POLY8_C(18), SIMDE_POLY8_C(31), SIMDE_POLY8_C(34), SIMDE_POLY8_C(2), SIMDE_POLY8_C(23), SIMDE_POLY8_C(35) },
       {  SIMDE_POLY8_C(17), SIMDE_POLY8_C(12), SIMDE_POLY8_C(24), SIMDE_POLY8_C(33), SIMDE_POLY8_C(30), SIMDE_POLY8_C(16), SIMDE_POLY8_C(21), SIMDE_POLY8_C(31),
        SIMDE_POLY8_C(39), SIMDE_POLY8_C(29), SIMDE_POLY8_C(4), SIMDE_POLY8_C(18), SIMDE_POLY8_C(47), SIMDE_POLY8_C(15), SIMDE_POLY8_C(49), SIMDE_POLY8_C(18) } } },
   { { {  SIMDE_POLY8_C(10), SIMDE_POLY8_C(27), SIMDE_POLY8_C(21), SIMDE_POLY8_C(23), SIMDE_POLY8_C(17), SIMDE_POLY8_C(42), SIMDE_POLY8_C(24), SIMDE_POLY8_C(35),
        SIMDE_POLY8_C(38), SIMDE_POLY8_C(3), SIMDE_POLY8_C(29), SIMDE_POLY8_C(41), SIMDE_POLY8_C(44), SIMDE_POLY8_C(15), SIMDE_POLY8_C(48), SIMDE_POLY8_C(26) },
       {  SIMDE_POLY8_C(9), SIMDE_POLY8_C(47), SIMDE_POLY8_C(29), SIMDE_POLY8_C(8), SIMDE_POLY8_C(7), SIMDE_POLY8_C(6), SIMDE_POLY8_C(26), SIMDE_POLY8_C(9),
        SIMDE_POLY8_C(11), SIMDE_POLY8_C(2), SIMDE_POLY8_C(6), SIMDE_POLY8_C(22), SIMDE_POLY8_C(34), SIMDE_POLY8_C(5), SIMDE_POLY8_C(38), SIMDE_POLY8_C(18) } },
       {  SIMDE_POLY8_C(21), SIMDE_POLY8_C(25)},
     { {  SIMDE_POLY8_C(10), SIMDE_POLY8_C(27), SIMDE_POLY8_C(21), SIMDE_POLY8_C(23), SIMDE_POLY8_C(21), SIMDE_POLY8_C(42), SIMDE_POLY8_C(24), SIMDE_POLY8_C(35),
        SIMDE_POLY8_C(38), SIMDE_POLY8_C(3), SIMDE_POLY8_C(29), SIMDE_POLY8_C(41), SIMDE_POLY8_C(44), SIMDE_POLY8_C(15), SIMDE_POLY8_C(48), SIMDE_POLY8_C(26) },
       {  SIMDE_POLY8_C(9), SIMDE_POLY8_C(47), SIMDE_POLY8_C(29), SIMDE_POLY8_C(8), SIMDE_POLY8_C(25), SIMDE_POLY8_C(6), SIMDE_POLY8_C(26), SIMDE_POLY8_C(9),
        SIMDE_POLY8_C(11), SIMDE_POLY8_C(2), SIMDE_POLY8_C(6), SIMDE_POLY8_C(22), SIMDE_POLY8_C(34), SIMDE_POLY8_C(5), SIMDE_POLY8_C(38), SIMDE_POLY8_C(18) } } },
   { { {  SIMDE_POLY8_C(2), SIMDE_POLY8_C(33), SIMDE_POLY8_C(23), SIMDE_POLY8_C(0), SIMDE_POLY8_C(48), SIMDE_POLY8_C(2), SIMDE_POLY8_C(26), SIMDE_POLY8_C(29),
        SIMDE_POLY8_C(38), SIMDE_POLY8_C(14), SIMDE_POLY8_C(48), SIMDE_POLY8_C(0), SIMDE_POLY8_C(44), SIMDE_POLY8_C(42), SIMDE_POLY8_C(37), SIMDE_POLY8_C(5) },
       {  SIMDE_POLY8_C(24), SIMDE_POLY8_C(4), SIMDE_POLY8_C(37), SIMDE_POLY8_C(46), SIMDE_POLY8_C(40), SIMDE_POLY8_C(24), SIMDE_POLY8_C(40), SIMDE_POLY8_C(18),
        SIMDE_POLY8_C(44), SIMDE_POLY8_C(48), SIMDE_POLY8_C(36), SIMDE_POLY8_C(45), SIMDE_POLY8_C(2), SIMDE_POLY8_C(4), SIMDE_POLY8_C(35), SIMDE_POLY8_C(9) } },
       {  SIMDE_POLY8_C(15), SIMDE_POLY8_C(13)},
     { {  SIMDE_POLY8_C(2), SIMDE_POLY8_C(33), SIMDE_POLY8_C(23), SIMDE_POLY8_C(0), SIMDE_POLY8_C(48), SIMDE_POLY8_C(15), SIMDE_POLY8_C(26), SIMDE_POLY8_C(29),
        SIMDE_POLY8_C(38), SIMDE_POLY8_C(14), SIMDE_POLY8_C(48), SIMDE_POLY8_C(0), SIMDE_POLY8_C(44), SIMDE_POLY8_C(42), SIMDE_POLY8_C(37), SIMDE_POLY8_C(5) },
       {  SIMDE_POLY8_C(24), SIMDE_POLY8_C(4), SIMDE_POLY8_C(37), SIMDE_POLY8_C(46), SIMDE_POLY8_C(40), SIMDE_POLY8_C(13), SIMDE_POLY8_C(40), SIMDE_POLY8_C(18),
        SIMDE_POLY8_C(44), SIMDE_POLY8_C(48), SIMDE_POLY8_C(36), SIMDE_POLY8_C(45), SIMDE_POLY8_C(2), SIMDE_POLY8_C(4), SIMDE_POLY8_C(35), SIMDE_POLY8_C(9) } } },
   { { {  SIMDE_POLY8_C(19), SIMDE_POLY8_C(26), SIMDE_POLY8_C(45), SIMDE_POLY8_C(37), SIMDE_POLY8_C(27), SIMDE_POLY8_C(2), SIMDE_POLY8_C(43), SIMDE_POLY8_C(37),
        SIMDE_POLY8_C(26), SIMDE_POLY8_C(18), SIMDE_POLY8_C(35), SIMDE_POLY8_C(9), SIMDE_POLY8_C(15), SIMDE_POLY8_C(38), SIMDE_POLY8_C(12), SIMDE_POLY8_C(35) },
       {  SIMDE_POLY8_C(9), SIMDE_POLY8_C(5), SIMDE_POLY8_C(6), SIMDE_POLY8_C(48), SIMDE_POLY8_C(10), SIMDE_POLY8_C(7), SIMDE_POLY8_C(18), SIMDE_POLY8_C(18),
        SIMDE_POLY8_C(5), SIMDE_POLY8_C(48), SIMDE_POLY8_C(36), SIMDE_POLY8_C(12), SIMDE_POLY8_C(8), SIMDE_POLY8_C(23), SIMDE_POLY8_C(0), SIMDE_POLY8_C(27) } },
       {  SIMDE_POLY8_C(19), SIMDE_POLY8_C(38)},
     { {  SIMDE_POLY8_C(19), SIMDE_POLY8_C(26), SIMDE_POLY8_C(45), SIMDE_POLY8_C(37), SIMDE_POLY8_C(27), SIMDE_POLY8_C(2), SIMDE_POLY8_C(19), SIMDE_POLY8_C(37),
        SIMDE_POLY8_C(26), SIMDE_POLY8_C(18), SIMDE_POLY8_C(35), SIMDE_POLY8_C(9), SIMDE_POLY8_C(15), SIMDE_POLY8_C(38), SIMDE_POLY8_C(12), SIMDE_POLY8_C(35) },
       {  SIMDE_POLY8_C(9), SIMDE_POLY8_C(5), SIMDE_POLY8_C(6), SIMDE_POLY8_C(48), SIMDE_POLY8_C(10), SIMDE_POLY8_C(7), SIMDE_POLY8_C(38), SIMDE_POLY8_C(18),
        SIMDE_POLY8_C(5), SIMDE_POLY8_C(48), SIMDE_POLY8_C(36), SIMDE_POLY8_C(12), SIMDE_POLY8_C(8), SIMDE_POLY8_C(23), SIMDE_POLY8_C(0), SIMDE_POLY8_C(27) } } },
   { { {  SIMDE_POLY8_C(27), SIMDE_POLY8_C(17), SIMDE_POLY8_C(31), SIMDE_POLY8_C(14), SIMDE_POLY8_C(14), SIMDE_POLY8_C(10), SIMDE_POLY8_C(47), SIMDE_POLY8_C(29),
        SIMDE_POLY8_C(16), SIMDE_POLY8_C(21), SIMDE_POLY8_C(21), SIMDE_POLY8_C(49), SIMDE_POLY8_C(40), SIMDE_POLY8_C(7), SIMDE_POLY8_C(47), SIMDE_POLY8_C(0) },
       {  SIMDE_POLY8_C(39), SIMDE_POLY8_C(29), SIMDE_POLY8_C(1), SIMDE_POLY8_C(3), SIMDE_POLY8_C(6), SIMDE_POLY8_C(48), SIMDE_POLY8_C(32), SIMDE_POLY8_C(2),
        SIMDE_POLY8_C(14), SIMDE_POLY8_C(9), SIMDE_POLY8_C(49), SIMDE_POLY8_C(9), SIMDE_POLY8_C(7), SIMDE_POLY8_C(24), SIMDE_POLY8_C(42), SIMDE_POLY8_C(39) } },
       {  SIMDE_POLY8_C(4), SIMDE_POLY8_C(15)},
     { {  SIMDE_POLY8_C(27), SIMDE_POLY8_C(17), SIMDE_POLY8_C(31), SIMDE_POLY8_C(14), SIMDE_POLY8_C(14), SIMDE_POLY8_C(10), SIMDE_POLY8_C(47), SIMDE_POLY8_C(4),
        SIMDE_POLY8_C(16), SIMDE_POLY8_C(21), SIMDE_POLY8_C(21), SIMDE_POLY8_C(49), SIMDE_POLY8_C(40), SIMDE_POLY8_C(7), SIMDE_POLY8_C(47), SIMDE_POLY8_C(0) },
       {  SIMDE_POLY8_C(39), SIMDE_POLY8_C(29), SIMDE_POLY8_C(1), SIMDE_POLY8_C(3), SIMDE_POLY8_C(6), SIMDE_POLY8_C(48), SIMDE_POLY8_C(32), SIMDE_POLY8_C(15),
        SIMDE_POLY8_C(14), SIMDE_POLY8_C(9), SIMDE_POLY8_C(49), SIMDE_POLY8_C(9), SIMDE_POLY8_C(7), SIMDE_POLY8_C(24), SIMDE_POLY8_C(42), SIMDE_POLY8_C(39) } } },
   { { {  SIMDE_POLY8_C(37), SIMDE_POLY8_C(15), SIMDE_POLY8_C(46), SIMDE_POLY8_C(31), SIMDE_POLY8_C(34), SIMDE_POLY8_C(45), SIMDE_POLY8_C(14), SIMDE_POLY8_C(4),
        SIMDE_POLY8_C(14), SIMDE_POLY8_C(26), SIMDE_POLY8_C(46), SIMDE_POLY8_C(29), SIMDE_POLY8_C(18), SIMDE_POLY8_C(8), SIMDE_POLY8_C(42), SIMDE_POLY8_C(46) },
       {  SIMDE_POLY8_C(21), SIMDE_POLY8_C(6), SIMDE_POLY8_C(17), SIMDE_POLY8_C(27), SIMDE_POLY8_C(20), SIMDE_POLY8_C(32), SIMDE_POLY8_C(7), SIMDE_POLY8_C(47),
        SIMDE_POLY8_C(2), SIMDE_POLY8_C(20), SIMDE_POLY8_C(26), SIMDE_POLY8_C(18), SIMDE_POLY8_C(49), SIMDE_POLY8_C(34), SIMDE_POLY8_C(49), SIMDE_POLY8_C(20) } },
       {  SIMDE_POLY8_C(35), SIMDE_POLY8_C(38)},
     { {  SIMDE_POLY8_C(37), SIMDE_POLY8_C(15), SIMDE_POLY8_C(46), SIMDE_POLY8_C(31), SIMDE_POLY8_C(34), SIMDE_POLY8_C(45), SIMDE_POLY8_C(14), SIMDE_POLY8_C(4),
        SIMDE_POLY8_C(35), SIMDE_POLY8_C(26), SIMDE_POLY8_C(46), SIMDE_POLY8_C(29), SIMDE_POLY8_C(18), SIMDE_POLY8_C(8), SIMDE_POLY8_C(42), SIMDE_POLY8_C(46) },
       {  SIMDE_POLY8_C(21), SIMDE_POLY8_C(6), SIMDE_POLY8_C(17), SIMDE_POLY8_C(27), SIMDE_POLY8_C(20), SIMDE_POLY8_C(32), SIMDE_POLY8_C(7), SIMDE_POLY8_C(47),
        SIMDE_POLY8_C(38), SIMDE_POLY8_C(20), SIMDE_POLY8_C(26), SIMDE_POLY8_C(18), SIMDE_POLY8_C(49), SIMDE_POLY8_C(34), SIMDE_POLY8_C(49), SIMDE_POLY8_C(20) } } },
   { { {  SIMDE_POLY8_C(3), SIMDE_POLY8_C(7), SIMDE_POLY8_C(11), SIMDE_POLY8_C(42), SIMDE_POLY8_C(30), SIMDE_POLY8_C(18), SIMDE_POLY8_C(19), SIMDE_POLY8_C(10),
        SIMDE_POLY8_C(28), SIMDE_POLY8_C(27), SIMDE_POLY8_C(40), SIMDE_POLY8_C(8), SIMDE_POLY8_C(37), SIMDE_POLY8_C(45), SIMDE_POLY8_C(46), SIMDE_POLY8_C(28) },
       {  SIMDE_POLY8_C(20), SIMDE_POLY8_C(48), SIMDE_POLY8_C(0), SIMDE_POLY8_C(46), SIMDE_POLY8_C(25), SIMDE_POLY8_C(39), SIMDE_POLY8_C(0), SIMDE_POLY8_C(21),
        SIMDE_POLY8_C(25), SIMDE_POLY8_C(28), SIMDE_POLY8_C(48), SIMDE_POLY8_C(12), SIMDE_POLY8_C(13), SIMDE_POLY8_C(44), SIMDE_POLY8_C(45), SIMDE_POLY8_C(26) } },
       {  SIMDE_POLY8_C(47), SIMDE_POLY8_C(22)},
     { {  SIMDE_POLY8_C(3), SIMDE_POLY8_C(7), SIMDE_POLY8_C(11), SIMDE_POLY8_C(42), SIMDE_POLY8_C(30), SIMDE_POLY8_C(18), SIMDE_POLY8_C(19), SIMDE_POLY8_C(10),
        SIMDE_POLY8_C(28), SIMDE_POLY8_C(47), SIMDE_POLY8_C(40), SIMDE_POLY8_C(8), SIMDE_POLY8_C(37), SIMDE_POLY8_C(45), SIMDE_POLY8_C(46), SIMDE_POLY8_C(28) },
       {  SIMDE_POLY8_C(20), SIMDE_POLY8_C(48), SIMDE_POLY8_C(0), SIMDE_POLY8_C(46), SIMDE_POLY8_C(25), SIMDE_POLY8_C(39), SIMDE_POLY8_C(0), SIMDE_POLY8_C(21),
        SIMDE_POLY8_C(25), SIMDE_POLY8_C(22), SIMDE_POLY8_C(48), SIMDE_POLY8_C(12), SIMDE_POLY8_C(13), SIMDE_POLY8_C(44), SIMDE_POLY8_C(45), SIMDE_POLY8_C(26) } } },
   { { {  SIMDE_POLY8_C(3), SIMDE_POLY8_C(35), SIMDE_POLY8_C(46), SIMDE_POLY8_C(27), SIMDE_POLY8_C(13), SIMDE_POLY8_C(31), SIMDE_POLY8_C(44), SIMDE_POLY8_C(37),
        SIMDE_POLY8_C(46), SIMDE_POLY8_C(47), SIMDE_POLY8_C(29), SIMDE_POLY8_C(24), SIMDE_POLY8_C(0), SIMDE_POLY8_C(31), SIMDE_POLY8_C(24), SIMDE_POLY8_C(39) },
       {  SIMDE_POLY8_C(8), SIMDE_POLY8_C(45), SIMDE_POLY8_C(22), SIMDE_POLY8_C(28), SIMDE_POLY8_C(9), SIMDE_POLY8_C(19), SIMDE_POLY8_C(27), SIMDE_POLY8_C(1),
        SIMDE_POLY8_C(47), SIMDE_POLY8_C(38), SIMDE_POLY8_C(11), SIMDE_POLY8_C(30), SIMDE_POLY8_C(18), SIMDE_POLY8_C(13), SIMDE_POLY8_C(36), SIMDE_POLY8_C(6) } },
       {  SIMDE_POLY8_C(27), SIMDE_POLY8_C(45)},
     { {  SIMDE_POLY8_C(3), SIMDE_POLY8_C(35), SIMDE_POLY8_C(46), SIMDE_POLY8_C(27), SIMDE_POLY8_C(13), SIMDE_POLY8_C(31), SIMDE_POLY8_C(44), SIMDE_POLY8_C(37),
        SIMDE_POLY8_C(46), SIMDE_POLY8_C(47), SIMDE_POLY8_C(27), SIMDE_POLY8_C(24), SIMDE_POLY8_C(0), SIMDE_POLY8_C(31), SIMDE_POLY8_C(24), SIMDE_POLY8_C(39) },
       {  SIMDE_POLY8_C(8), SIMDE_POLY8_C(45), SIMDE_POLY8_C(22), SIMDE_POLY8_C(28), SIMDE_POLY8_C(9), SIMDE_POLY8_C(19), SIMDE_POLY8_C(27), SIMDE_POLY8_C(1),
        SIMDE_POLY8_C(47), SIMDE_POLY8_C(38), SIMDE_POLY8_C(45), SIMDE_POLY8_C(30), SIMDE_POLY8_C(18), SIMDE_POLY8_C(13), SIMDE_POLY8_C(36), SIMDE_POLY8_C(6) } } },
   { { {  SIMDE_POLY8_C(27), SIMDE_POLY8_C(22), SIMDE_POLY8_C(2), SIMDE_POLY8_C(45), SIMDE_POLY8_C(16), SIMDE_POLY8_C(20), SIMDE_POLY8_C(11), SIMDE_POLY8_C(41),
        SIMDE_POLY8_C(5), SIMDE_POLY8_C(39), SIMDE_POLY8_C(35), SIMDE_POLY8_C(0), SIMDE_POLY8_C(42), SIMDE_POLY8_C(15), SIMDE_POLY8_C(7), SIMDE_POLY8_C(9) },
       {  SIMDE_POLY8_C(42), SIMDE_POLY8_C(1), SIMDE_POLY8_C(5), SIMDE_POLY8_C(26), SIMDE_POLY8_C(17), SIMDE_POLY8_C(42), SIMDE_POLY8_C(12), SIMDE_POLY8_C(7),
        SIMDE_POLY8_C(43), SIMDE_POLY8_C(27), SIMDE_POLY8_C(46), SIMDE_POLY8_C(18), SIMDE_POLY8_C(44), SIMDE_POLY8_C(7), SIMDE_POLY8_C(49), SIMDE_POLY8_C(24) } },
       {  SIMDE_POLY8_C(14), SIMDE_POLY8_C(8)},
     { {  SIMDE_POLY8_C(27), SIMDE_POLY8_C(22), SIMDE_POLY8_C(2), SIMDE_POLY8_C(45), SIMDE_POLY8_C(16), SIMDE_POLY8_C(20), SIMDE_POLY8_C(11), SIMDE_POLY8_C(41),
        SIMDE_POLY8_C(5), SIMDE_POLY8_C(39), SIMDE_POLY8_C(35), SIMDE_POLY8_C(14), SIMDE_POLY8_C(42), SIMDE_POLY8_C(15), SIMDE_POLY8_C(7), SIMDE_POLY8_C(9) },
       {  SIMDE_POLY8_C(42), SIMDE_POLY8_C(1), SIMDE_POLY8_C(5), SIMDE_POLY8_C(26), SIMDE_POLY8_C(17), SIMDE_POLY8_C(42), SIMDE_POLY8_C(12), SIMDE_POLY8_C(7),
        SIMDE_POLY8_C(43), SIMDE_POLY8_C(27), SIMDE_POLY8_C(46), SIMDE_POLY8_C(8), SIMDE_POLY8_C(44), SIMDE_POLY8_C(7), SIMDE_POLY8_C(49), SIMDE_POLY8_C(24) } } },
   { { {  SIMDE_POLY8_C(49), SIMDE_POLY8_C(24), SIMDE_POLY8_C(24), SIMDE_POLY8_C(11), SIMDE_POLY8_C(12), SIMDE_POLY8_C(25), SIMDE_POLY8_C(0), SIMDE_POLY8_C(3),
        SIMDE_POLY8_C(10), SIMDE_POLY8_C(16), SIMDE_POLY8_C(24), SIMDE_POLY8_C(47), SIMDE_POLY8_C(42), SIMDE_POLY8_C(8), SIMDE_POLY8_C(45), SIMDE_POLY8_C(14) },
       {  SIMDE_POLY8_C(19), SIMDE_POLY8_C(19), SIMDE_POLY8_C(0), SIMDE_POLY8_C(4), SIMDE_POLY8_C(9), SIMDE_POLY8_C(37), SIMDE_POLY8_C(17), SIMDE_POLY8_C(6),
        SIMDE_POLY8_C(16), SIMDE_POLY8_C(49), SIMDE_POLY8_C(39), SIMDE_POLY8_C(30), SIMDE_POLY8_C(42), SIMDE_POLY8_C(1), SIMDE_POLY8_C(27), SIMDE_POLY8_C(22) } },
       {  SIMDE_POLY8_C(14), SIMDE_POLY8_C(8)},
     { {  SIMDE_POLY8_C(49), SIMDE_POLY8_C(24), SIMDE_POLY8_C(24), SIMDE_POLY8_C(11), SIMDE_POLY8_C(12), SIMDE_POLY8_C(25), SIMDE_POLY8_C(0), SIMDE_POLY8_C(3),
        SIMDE_POLY8_C(10), SIMDE_POLY8_C(16), SIMDE_POLY8_C(24), SIMDE_POLY8_C(47), SIMDE_POLY8_C(14), SIMDE_POLY8_C(8), SIMDE_POLY8_C(45), SIMDE_POLY8_C(14) },
       {  SIMDE_POLY8_C(19), SIMDE_POLY8_C(19), SIMDE_POLY8_C(0), SIMDE_POLY8_C(4), SIMDE_POLY8_C(9), SIMDE_POLY8_C(37), SIMDE_POLY8_C(17), SIMDE_POLY8_C(6),
        SIMDE_POLY8_C(16), SIMDE_POLY8_C(49), SIMDE_POLY8_C(39), SIMDE_POLY8_C(30), SIMDE_POLY8_C(8), SIMDE_POLY8_C(1), SIMDE_POLY8_C(27), SIMDE_POLY8_C(22) } } },
   { { {  SIMDE_POLY8_C(6), SIMDE_POLY8_C(22), SIMDE_POLY8_C(33), SIMDE_POLY8_C(31), SIMDE_POLY8_C(29), SIMDE_POLY8_C(16), SIMDE_POLY8_C(29), SIMDE_POLY8_C(38),
        SIMDE_POLY8_C(25), SIMDE_POLY8_C(9), SIMDE_POLY8_C(19), SIMDE_POLY8_C(12), SIMDE_POLY8_C(2), SIMDE_POLY8_C(47), SIMDE_POLY8_C(19), SIMDE_POLY8_C(47) },
       {  SIMDE_POLY8_C(42), SIMDE_POLY8_C(2), SIMDE_POLY8_C(24), SIMDE_POLY8_C(27), SIMDE_POLY8_C(3), SIMDE_POLY8_C(20), SIMDE_POLY8_C(2), SIMDE_POLY8_C(20),
        SIMDE_POLY8_C(10), SIMDE_POLY8_C(29), SIMDE_POLY8_C(37), SIMDE_POLY8_C(33), SIMDE_POLY8_C(47), SIMDE_POLY8_C(1), SIMDE_POLY8_C(31), SIMDE_POLY8_C(4) } },
       {  SIMDE_POLY8_C(12), SIMDE_POLY8_C(31)},
     { {  SIMDE_POLY8_C(6), SIMDE_POLY8_C(22), SIMDE_POLY8_C(33), SIMDE_POLY8_C(31), SIMDE_POLY8_C(29), SIMDE_POLY8_C(16), SIMDE_POLY8_C(29), SIMDE_POLY8_C(38),
        SIMDE_POLY8_C(25), SIMDE_POLY8_C(9), SIMDE_POLY8_C(19), SIMDE_POLY8_C(12), SIMDE_POLY8_C(2), SIMDE_POLY8_C(12), SIMDE_POLY8_C(19), SIMDE_POLY8_C(47) },
       {  SIMDE_POLY8_C(42), SIMDE_POLY8_C(2), SIMDE_POLY8_C(24), SIMDE_POLY8_C(27), SIMDE_POLY8_C(3), SIMDE_POLY8_C(20), SIMDE_POLY8_C(2), SIMDE_POLY8_C(20),
        SIMDE_POLY8_C(10), SIMDE_POLY8_C(29), SIMDE_POLY8_C(37), SIMDE_POLY8_C(33), SIMDE_POLY8_C(47), SIMDE_POLY8_C(31), SIMDE_POLY8_C(31), SIMDE_POLY8_C(4) } } },
   { { {  SIMDE_POLY8_C(4), SIMDE_POLY8_C(34), SIMDE_POLY8_C(11), SIMDE_POLY8_C(37), SIMDE_POLY8_C(11), SIMDE_POLY8_C(18), SIMDE_POLY8_C(0), SIMDE_POLY8_C(13),
        SIMDE_POLY8_C(45), SIMDE_POLY8_C(20), SIMDE_POLY8_C(3), SIMDE_POLY8_C(34), SIMDE_POLY8_C(42), SIMDE_POLY8_C(2), SIMDE_POLY8_C(17), SIMDE_POLY8_C(0) },
       {  SIMDE_POLY8_C(43), SIMDE_POLY8_C(15), SIMDE_POLY8_C(29), SIMDE_POLY8_C(47), SIMDE_POLY8_C(29), SIMDE_POLY8_C(31), SIMDE_POLY8_C(20), SIMDE_POLY8_C(42),
        SIMDE_POLY8_C(37), SIMDE_POLY8_C(6), SIMDE_POLY8_C(39), SIMDE_POLY8_C(2), SIMDE_POLY8_C(40), SIMDE_POLY8_C(34), SIMDE_POLY8_C(46), SIMDE_POLY8_C(21) } },
       {  SIMDE_POLY8_C(1), SIMDE_POLY8_C(27)},
     { {  SIMDE_POLY8_C(4), SIMDE_POLY8_C(34), SIMDE_POLY8_C(11), SIMDE_POLY8_C(37), SIMDE_POLY8_C(11), SIMDE_POLY8_C(18), SIMDE_POLY8_C(0), SIMDE_POLY8_C(13),
        SIMDE_POLY8_C(45), SIMDE_POLY8_C(20), SIMDE_POLY8_C(3), SIMDE_POLY8_C(34), SIMDE_POLY8_C(42), SIMDE_POLY8_C(2), SIMDE_POLY8_C(1), SIMDE_POLY8_C(0) },
       {  SIMDE_POLY8_C(43), SIMDE_POLY8_C(15), SIMDE_POLY8_C(29), SIMDE_POLY8_C(47), SIMDE_POLY8_C(29), SIMDE_POLY8_C(31), SIMDE_POLY8_C(20), SIMDE_POLY8_C(42),
        SIMDE_POLY8_C(37), SIMDE_POLY8_C(6), SIMDE_POLY8_C(39), SIMDE_POLY8_C(2), SIMDE_POLY8_C(40), SIMDE_POLY8_C(34), SIMDE_POLY8_C(27), SIMDE_POLY8_C(21) } } },
   { { {  SIMDE_POLY8_C(45), SIMDE_POLY8_C(24), SIMDE_POLY8_C(18), SIMDE_POLY8_C(2), SIMDE_POLY8_C(29), SIMDE_POLY8_C(24), SIMDE_POLY8_C(25), SIMDE_POLY8_C(8),
        SIMDE_POLY8_C(2), SIMDE_POLY8_C(10), SIMDE_POLY8_C(15), SIMDE_POLY8_C(30), SIMDE_POLY8_C(16), SIMDE_POLY8_C(4), SIMDE_POLY8_C(46), SIMDE_POLY8_C(26) },
       {  SIMDE_POLY8_C(24), SIMDE_POLY8_C(33), SIMDE_POLY8_C(14), SIMDE_POLY8_C(42), SIMDE_POLY8_C(12), SIMDE_POLY8_C(0), SIMDE_POLY8_C(14), SIMDE_POLY8_C(30),
        SIMDE_POLY8_C(11), SIMDE_POLY8_C(3), SIMDE_POLY8_C(46), SIMDE_POLY8_C(16), SIMDE_POLY8_C(32), SIMDE_POLY8_C(30), SIMDE_POLY8_C(15), SIMDE_POLY8_C(0) } },
       {  SIMDE_POLY8_C(18), SIMDE_POLY8_C(19)},
     { {  SIMDE_POLY8_C(45), SIMDE_POLY8_C(24), SIMDE_POLY8_C(18), SIMDE_POLY8_C(2), SIMDE_POLY8_C(29), SIMDE_POLY8_C(24), SIMDE_POLY8_C(25), SIMDE_POLY8_C(8),
        SIMDE_POLY8_C(2), SIMDE_POLY8_C(10), SIMDE_POLY8_C(15), SIMDE_POLY8_C(30), SIMDE_POLY8_C(16), SIMDE_POLY8_C(4), SIMDE_POLY8_C(46), SIMDE_POLY8_C(18) },
       {  SIMDE_POLY8_C(24), SIMDE_POLY8_C(33), SIMDE_POLY8_C(14), SIMDE_POLY8_C(42), SIMDE_POLY8_C(12), SIMDE_POLY8_C(0), SIMDE_POLY8_C(14), SIMDE_POLY8_C(30),
        SIMDE_POLY8_C(11), SIMDE_POLY8_C(3), SIMDE_POLY8_C(46), SIMDE_POLY8_C(16), SIMDE_POLY8_C(32), SIMDE_POLY8_C(30), SIMDE_POLY8_C(15), SIMDE_POLY8_C(19) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_poly8x16x2_t r, src, expected;
    src.val[0] = simde_vld1q_p8(test_vec[i].src[0]);
    src.val[1] = simde_vld1q_p8(test_vec[i].src[1]);

    SIMDE_CONSTIFY_16_(simde_vld2q_lane_p8, r, (HEDLEY_UNREACHABLE(), r), i, test_vec[i].buf, src);

    expected.val[0] = simde_vld1q_p8(test_vec[i].r[0]);
    expected.val[1] = simde_vld1q_p8(test_vec[i].r[1]);

    simde_test_arm_neon_assert_equal_p8x16(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_p8x16(r.val[1], expected.val[1]);
  }

  return 0;
#else
  for (int i = 0 ; i < 16 ; i++) {
    simde_poly8x16x2_t src = simde_test_arm_neon_random_p8x16x2();
    simde_poly8_t buf[2];
    simde_poly8x16x2_t r;
    simde_test_arm_neon_write_p8x16x2(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_random_memory(2, HEDLEY_REINTERPRET_CAST(uint8_t*, buf));
    simde_test_codegen_write_vp8(2, 2, buf, SIMDE_TEST_VEC_POS_MIDDLE);
    SIMDE_CONSTIFY_16_(simde_vld2q_lane_p8, r, (HEDLEY_UNREACHABLE(), r), i, buf, src);
    simde_test_arm_neon_write_p8x16x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld2q_lane_p16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_poly16_t src[2][8];
    simde_poly16_t buf[2];
    simde_poly16_t r[2][8];
  } test_vec[] = {
   { { {  SIMDE_POLY16_C(418), SIMDE_POLY16_C(216), SIMDE_POLY16_C(347), SIMDE_POLY16_C(476),
        SIMDE_POLY16_C(360), SIMDE_POLY16_C(143), SIMDE_POLY16_C(316), SIMDE_POLY16_C(114) },
       {  SIMDE_POLY16_C(387), SIMDE_POLY16_C(146), SIMDE_POLY16_C(225), SIMDE_POLY16_C(190),
        SIMDE_POLY16_C(399), SIMDE_POLY16_C(128), SIMDE_POLY16_C(400), SIMDE_POLY16_C(257) } },
       {  SIMDE_POLY16_C(488), SIMDE_POLY16_C(232)},
     { {  SIMDE_POLY16_C(488), SIMDE_POLY16_C(216), SIMDE_POLY16_C(347), SIMDE_POLY16_C(476),
        SIMDE_POLY16_C(360), SIMDE_POLY16_C(143), SIMDE_POLY16_C(316), SIMDE_POLY16_C(114) },
       {  SIMDE_POLY16_C(232), SIMDE_POLY16_C(146), SIMDE_POLY16_C(225), SIMDE_POLY16_C(190),
        SIMDE_POLY16_C(399), SIMDE_POLY16_C(128), SIMDE_POLY16_C(400), SIMDE_POLY16_C(257) } } },
   { { {  SIMDE_POLY16_C(311), SIMDE_POLY16_C(430), SIMDE_POLY16_C(36), SIMDE_POLY16_C(399),
        SIMDE_POLY16_C(84), SIMDE_POLY16_C(165), SIMDE_POLY16_C(434), SIMDE_POLY16_C(105) },
       {  SIMDE_POLY16_C(449), SIMDE_POLY16_C(455), SIMDE_POLY16_C(390), SIMDE_POLY16_C(160),
        SIMDE_POLY16_C(77), SIMDE_POLY16_C(147), SIMDE_POLY16_C(38), SIMDE_POLY16_C(271) } },
       {  SIMDE_POLY16_C(106), SIMDE_POLY16_C(427)},
     { {  SIMDE_POLY16_C(311), SIMDE_POLY16_C(106), SIMDE_POLY16_C(36), SIMDE_POLY16_C(399),
        SIMDE_POLY16_C(84), SIMDE_POLY16_C(165), SIMDE_POLY16_C(434), SIMDE_POLY16_C(105) },
       {  SIMDE_POLY16_C(449), SIMDE_POLY16_C(427), SIMDE_POLY16_C(390), SIMDE_POLY16_C(160),
        SIMDE_POLY16_C(77), SIMDE_POLY16_C(147), SIMDE_POLY16_C(38), SIMDE_POLY16_C(271) } } },
   { { {  SIMDE_POLY16_C(181), SIMDE_POLY16_C(136), SIMDE_POLY16_C(379), SIMDE_POLY16_C(296),
        SIMDE_POLY16_C(309), SIMDE_POLY16_C(435), SIMDE_POLY16_C(152), SIMDE_POLY16_C(215) },
       {  SIMDE_POLY16_C(379), SIMDE_POLY16_C(147), SIMDE_POLY16_C(345), SIMDE_POLY16_C(276),
        SIMDE_POLY16_C(105), SIMDE_POLY16_C(142), SIMDE_POLY16_C(485), SIMDE_POLY16_C(383) } },
       {  SIMDE_POLY16_C(39), SIMDE_POLY16_C(212)},
     { {  SIMDE_POLY16_C(181), SIMDE_POLY16_C(136), SIMDE_POLY16_C(39), SIMDE_POLY16_C(296),
        SIMDE_POLY16_C(309), SIMDE_POLY16_C(435), SIMDE_POLY16_C(152), SIMDE_POLY16_C(215) },
       {  SIMDE_POLY16_C(379), SIMDE_POLY16_C(147), SIMDE_POLY16_C(212), SIMDE_POLY16_C(276),
        SIMDE_POLY16_C(105), SIMDE_POLY16_C(142), SIMDE_POLY16_C(485), SIMDE_POLY16_C(383) } } },
   { { {  SIMDE_POLY16_C(181), SIMDE_POLY16_C(451), SIMDE_POLY16_C(74), SIMDE_POLY16_C(26),
        SIMDE_POLY16_C(435), SIMDE_POLY16_C(466), SIMDE_POLY16_C(458), SIMDE_POLY16_C(378) },
       {  SIMDE_POLY16_C(292), SIMDE_POLY16_C(173), SIMDE_POLY16_C(470), SIMDE_POLY16_C(400),
        SIMDE_POLY16_C(286), SIMDE_POLY16_C(269), SIMDE_POLY16_C(383), SIMDE_POLY16_C(317) } },
       {  SIMDE_POLY16_C(240), SIMDE_POLY16_C(459)},
     { {  SIMDE_POLY16_C(181), SIMDE_POLY16_C(451), SIMDE_POLY16_C(74), SIMDE_POLY16_C(240),
        SIMDE_POLY16_C(435), SIMDE_POLY16_C(466), SIMDE_POLY16_C(458), SIMDE_POLY16_C(378) },
       {  SIMDE_POLY16_C(292), SIMDE_POLY16_C(173), SIMDE_POLY16_C(470), SIMDE_POLY16_C(459),
        SIMDE_POLY16_C(286), SIMDE_POLY16_C(269), SIMDE_POLY16_C(383), SIMDE_POLY16_C(317) } } },
   { { {  SIMDE_POLY16_C(377), SIMDE_POLY16_C(162), SIMDE_POLY16_C(3), SIMDE_POLY16_C(316),
        SIMDE_POLY16_C(150), SIMDE_POLY16_C(261), SIMDE_POLY16_C(40), SIMDE_POLY16_C(64) },
       {  SIMDE_POLY16_C(243), SIMDE_POLY16_C(47), SIMDE_POLY16_C(381), SIMDE_POLY16_C(58),
        SIMDE_POLY16_C(290), SIMDE_POLY16_C(64), SIMDE_POLY16_C(220), SIMDE_POLY16_C(89) } },
       {  SIMDE_POLY16_C(378), SIMDE_POLY16_C(355)},
     { {  SIMDE_POLY16_C(377), SIMDE_POLY16_C(162), SIMDE_POLY16_C(3), SIMDE_POLY16_C(316),
        SIMDE_POLY16_C(378), SIMDE_POLY16_C(261), SIMDE_POLY16_C(40), SIMDE_POLY16_C(64) },
       {  SIMDE_POLY16_C(243), SIMDE_POLY16_C(47), SIMDE_POLY16_C(381), SIMDE_POLY16_C(58),
        SIMDE_POLY16_C(355), SIMDE_POLY16_C(64), SIMDE_POLY16_C(220), SIMDE_POLY16_C(89) } } },
   { { {  SIMDE_POLY16_C(298), SIMDE_POLY16_C(486), SIMDE_POLY16_C(96), SIMDE_POLY16_C(132),
        SIMDE_POLY16_C(108), SIMDE_POLY16_C(284), SIMDE_POLY16_C(54), SIMDE_POLY16_C(224) },
       {  SIMDE_POLY16_C(249), SIMDE_POLY16_C(117), SIMDE_POLY16_C(26), SIMDE_POLY16_C(467),
        SIMDE_POLY16_C(477), SIMDE_POLY16_C(25), SIMDE_POLY16_C(300), SIMDE_POLY16_C(233) } },
       {  SIMDE_POLY16_C(454), SIMDE_POLY16_C(179)},
     { {  SIMDE_POLY16_C(298), SIMDE_POLY16_C(486), SIMDE_POLY16_C(96), SIMDE_POLY16_C(132),
        SIMDE_POLY16_C(108), SIMDE_POLY16_C(454), SIMDE_POLY16_C(54), SIMDE_POLY16_C(224) },
       {  SIMDE_POLY16_C(249), SIMDE_POLY16_C(117), SIMDE_POLY16_C(26), SIMDE_POLY16_C(467),
        SIMDE_POLY16_C(477), SIMDE_POLY16_C(179), SIMDE_POLY16_C(300), SIMDE_POLY16_C(233) } } },
   { { {  SIMDE_POLY16_C(15), SIMDE_POLY16_C(88), SIMDE_POLY16_C(166), SIMDE_POLY16_C(374),
        SIMDE_POLY16_C(203), SIMDE_POLY16_C(81), SIMDE_POLY16_C(316), SIMDE_POLY16_C(214) },
       {  SIMDE_POLY16_C(227), SIMDE_POLY16_C(24), SIMDE_POLY16_C(14), SIMDE_POLY16_C(100),
        SIMDE_POLY16_C(31), SIMDE_POLY16_C(86), SIMDE_POLY16_C(474), SIMDE_POLY16_C(470) } },
       {  SIMDE_POLY16_C(325), SIMDE_POLY16_C(388)},
     { {  SIMDE_POLY16_C(15), SIMDE_POLY16_C(88), SIMDE_POLY16_C(166), SIMDE_POLY16_C(374),
        SIMDE_POLY16_C(203), SIMDE_POLY16_C(81), SIMDE_POLY16_C(325), SIMDE_POLY16_C(214) },
       {  SIMDE_POLY16_C(227), SIMDE_POLY16_C(24), SIMDE_POLY16_C(14), SIMDE_POLY16_C(100),
        SIMDE_POLY16_C(31), SIMDE_POLY16_C(86), SIMDE_POLY16_C(388), SIMDE_POLY16_C(470) } } },
   { { {  SIMDE_POLY16_C(370), SIMDE_POLY16_C(25), SIMDE_POLY16_C(181), SIMDE_POLY16_C(342),
        SIMDE_POLY16_C(6), SIMDE_POLY16_C(89), SIMDE_POLY16_C(30), SIMDE_POLY16_C(425) },
       {  SIMDE_POLY16_C(478), SIMDE_POLY16_C(331), SIMDE_POLY16_C(463), SIMDE_POLY16_C(400),
        SIMDE_POLY16_C(469), SIMDE_POLY16_C(40), SIMDE_POLY16_C(46), SIMDE_POLY16_C(134) } },
       {  SIMDE_POLY16_C(225), SIMDE_POLY16_C(7)},
     { {  SIMDE_POLY16_C(370), SIMDE_POLY16_C(25), SIMDE_POLY16_C(181), SIMDE_POLY16_C(342),
        SIMDE_POLY16_C(6), SIMDE_POLY16_C(89), SIMDE_POLY16_C(30), SIMDE_POLY16_C(225) },
       {  SIMDE_POLY16_C(478), SIMDE_POLY16_C(331), SIMDE_POLY16_C(463), SIMDE_POLY16_C(400),
        SIMDE_POLY16_C(469), SIMDE_POLY16_C(40), SIMDE_POLY16_C(46), SIMDE_POLY16_C(7) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_poly16x8x2_t r, src, expected;
    src.val[0] = simde_vld1q_p16(test_vec[i].src[0]);
    src.val[1] = simde_vld1q_p16(test_vec[i].src[1]);

    SIMDE_CONSTIFY_8_(simde_vld2q_lane_p16, r, (HEDLEY_UNREACHABLE(), r), i, test_vec[i].buf, src);

    expected.val[0] = simde_vld1q_p16(test_vec[i].r[0]);
    expected.val[1] = simde_vld1q_p16(test_vec[i].r[1]);

    simde_test_arm_neon_assert_equal_p16x8(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_p16x8(r.val[1], expected.val[1]);
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_poly16x8x2_t src = simde_test_arm_neon_random_p16x8x2();
    simde_poly16_t buf[2];
    simde_poly16x8x2_t r;
    simde_test_arm_neon_write_p16x8x2(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_random_memory(4, HEDLEY_REINTERPRET_CAST(uint8_t*, buf));
    simde_test_codegen_write_vp16(2, 2, buf, SIMDE_TEST_VEC_POS_MIDDLE);
    SIMDE_CONSTIFY_8_(simde_vld2q_lane_p16, r, (HEDLEY_UNREACHABLE(), r), i, buf, src);
    simde_test_arm_neon_write_p16x8x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld2q_lane_p64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_poly64_t src[2][2];
    simde_poly64_t buf[2];
    simde_poly64_t r[2][2];
  } test_vec[] = {
   { { {  SIMDE_POLY64_C(133259958), SIMDE_POLY64_C(495309638) },
       {  SIMDE_POLY64_C(463332514), SIMDE_POLY64_C(273508271) } },
       {  SIMDE_POLY64_C(159685885), SIMDE_POLY64_C(187025881)},
     { {  SIMDE_POLY64_C(159685885), SIMDE_POLY64_C(495309638) },
       {  SIMDE_POLY64_C(187025881), SIMDE_POLY64_C(273508271) } } },
   { { {  SIMDE_POLY64_C(430109367), SIMDE_POLY64_C(402602870) },
       {  SIMDE_POLY64_C(309788205), SIMDE_POLY64_C(441710399) } },
       {  SIMDE_POLY64_C(264334842), SIMDE_POLY64_C(60309831)},
     { {  SIMDE_POLY64_C(430109367), SIMDE_POLY64_C(264334842) },
       {  SIMDE_POLY64_C(309788205), SIMDE_POLY64_C(60309831) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_poly64x2x2_t r, src, expected;
    src.val[0] = simde_vld1q_p64(test_vec[i].src[0]);
    src.val[1] = simde_vld1q_p64(test_vec[i].src[1]);

    SIMDE_CONSTIFY_2_(simde_vld2q_lane_p64, r, (HEDLEY_UNREACHABLE(), r), i, test_vec[i].buf, src);

    expected.val[0] = simde_vld1q_p64(test_vec[i].r[0]);
    expected.val[1] = simde_vld1q_p64(test_vec[i].r[1]);

    simde_test_arm_neon_assert_equal_p64x2(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_p64x2(r.val[1], expected.val[1]);
  }

  return 0;
#else
  for (int i = 0 ; i < 2 ; i++) {
    simde_poly64x2x2_t src = simde_test_arm_neon_random_p64x2x2();
    simde_poly64_t buf[2];
    simde_poly64x2x2_t r;
    simde_test_arm_neon_write_p64x2x2(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_random_memory(16, HEDLEY_REINTERPRET_CAST(uint8_t*, buf));
    simde_test_codegen_write_vp64(2, 2, buf, SIMDE_TEST_VEC_POS_MIDDLE);
    SIMDE_CONSTIFY_2_(simde_vld2q_lane_p64, r, (HEDLEY_UNREACHABLE(), r), i, buf, src);
    simde_test_arm_neon_write_p64x2x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld2_lane_bf16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_bfloat16_t src[2][4];
    simde_bfloat16_t buf[2];
    simde_bfloat16_t r[2][4];
  } test_vec[] = {
   { { {  SIMDE_BFLOAT16_VALUE(-45.80), SIMDE_BFLOAT16_VALUE(29.77), SIMDE_BFLOAT16_VALUE(44.10), SIMDE_BFLOAT16_VALUE(-17.29) },
       {  SIMDE_BFLOAT16_VALUE(-34.30), SIMDE_BFLOAT16_VALUE(-46.41), SIMDE_BFLOAT16_VALUE(-43.15), SIMDE_BFLOAT16_VALUE(-30.34) } },
       {  SIMDE_BFLOAT16_VALUE(-16.64), SIMDE_BFLOAT16_VALUE(-13.70)},
     { {  SIMDE_BFLOAT16_VALUE(-16.64), SIMDE_BFLOAT16_VALUE(29.77), SIMDE_BFLOAT16_VALUE(44.10), SIMDE_BFLOAT16_VALUE(-17.29) },
       {  SIMDE_BFLOAT16_VALUE(-13.70), SIMDE_BFLOAT16_VALUE(-46.41), SIMDE_BFLOAT16_VALUE(-43.15), SIMDE_BFLOAT16_VALUE(-30.34) } } },
   { { {  SIMDE_BFLOAT16_VALUE(-31.49), SIMDE_BFLOAT16_VALUE(-3.02), SIMDE_BFLOAT16_VALUE(4.73), SIMDE_BFLOAT16_VALUE(29.19) },
       {  SIMDE_BFLOAT16_VALUE(-6.51), SIMDE_BFLOAT16_VALUE(-6.97), SIMDE_BFLOAT16_VALUE(-24.86), SIMDE_BFLOAT16_VALUE(20.04) } },
       {  SIMDE_BFLOAT16_VALUE(4.78), SIMDE_BFLOAT16_VALUE(-24.76)},
     { {  SIMDE_BFLOAT16_VALUE(-31.49), SIMDE_BFLOAT16_VALUE(4.78), SIMDE_BFLOAT16_VALUE(4.73), SIMDE_BFLOAT16_VALUE(29.19) },
       {  SIMDE_BFLOAT16_VALUE(-6.51), SIMDE_BFLOAT16_VALUE(-24.76), SIMDE_BFLOAT16_VALUE(-24.86), SIMDE_BFLOAT16_VALUE(20.04) } } },
   { { {  SIMDE_BFLOAT16_VALUE(-33.05), SIMDE_BFLOAT16_VALUE(44.60), SIMDE_BFLOAT16_VALUE(44.07), SIMDE_BFLOAT16_VALUE(-42.37) },
       {  SIMDE_BFLOAT16_VALUE(45.53), SIMDE_BFLOAT16_VALUE(4.23), SIMDE_BFLOAT16_VALUE(13.47), SIMDE_BFLOAT16_VALUE(2.19) } },
       {  SIMDE_BFLOAT16_VALUE(-14.88), SIMDE_BFLOAT16_VALUE(-15.37)},
     { {  SIMDE_BFLOAT16_VALUE(-33.05), SIMDE_BFLOAT16_VALUE(44.60), SIMDE_BFLOAT16_VALUE(-14.88), SIMDE_BFLOAT16_VALUE(-42.37) },
       {  SIMDE_BFLOAT16_VALUE(45.53), SIMDE_BFLOAT16_VALUE(4.23), SIMDE_BFLOAT16_VALUE(-15.37), SIMDE_BFLOAT16_VALUE(2.19) } } },
   { { {  SIMDE_BFLOAT16_VALUE(22.74), SIMDE_BFLOAT16_VALUE(-1.07), SIMDE_BFLOAT16_VALUE(48.37), SIMDE_BFLOAT16_VALUE(26.68) },
       {  SIMDE_BFLOAT16_VALUE(-34.05), SIMDE_BFLOAT16_VALUE(-26.07), SIMDE_BFLOAT16_VALUE(-44.28), SIMDE_BFLOAT16_VALUE(6.92) } },
       {  SIMDE_BFLOAT16_VALUE(-28.27), SIMDE_BFLOAT16_VALUE(-30.31)},
     { {  SIMDE_BFLOAT16_VALUE(22.74), SIMDE_BFLOAT16_VALUE(-1.07), SIMDE_BFLOAT16_VALUE(48.37), SIMDE_BFLOAT16_VALUE(-28.27) },
       {  SIMDE_BFLOAT16_VALUE(-34.05), SIMDE_BFLOAT16_VALUE(-26.07), SIMDE_BFLOAT16_VALUE(-44.28), SIMDE_BFLOAT16_VALUE(-30.31) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_bfloat16x4x2_t r, src, expected;
    src.val[0] = simde_vld1_bf16(test_vec[i].src[0]);
    src.val[1] = simde_vld1_bf16(test_vec[i].src[1]);

    SIMDE_CONSTIFY_4_(simde_vld2_lane_bf16, r, (HEDLEY_UNREACHABLE(), r), i, test_vec[i].buf, src);

    expected.val[0] = simde_vld1_bf16(test_vec[i].r[0]);
    expected.val[1] = simde_vld1_bf16(test_vec[i].r[1]);

    simde_test_arm_neon_assert_equal_bf16x4(r.val[0], expected.val[0], INT_MAX);
    simde_test_arm_neon_assert_equal_bf16x4(r.val[1], expected.val[1], INT_MAX);
  }

  return 0;
}

static int
test_simde_vld2q_lane_bf16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_bfloat16_t src[2][8];
    simde_bfloat16_t buf[2];
    simde_bfloat16_t r[2][8];
  } test_vec[] = {
   { { {  SIMDE_BFLOAT16_VALUE(-44.86), SIMDE_BFLOAT16_VALUE(-27.30), SIMDE_BFLOAT16_VALUE(-35.67), SIMDE_BFLOAT16_VALUE(22.98),
        SIMDE_BFLOAT16_VALUE(-34.31), SIMDE_BFLOAT16_VALUE(-40.87), SIMDE_BFLOAT16_VALUE(-37.54), SIMDE_BFLOAT16_VALUE(-11.89) },
       {  SIMDE_BFLOAT16_VALUE(-19.39), SIMDE_BFLOAT16_VALUE(-21.84), SIMDE_BFLOAT16_VALUE(-32.89), SIMDE_BFLOAT16_VALUE(43.11),
        SIMDE_BFLOAT16_VALUE(-10.75), SIMDE_BFLOAT16_VALUE(-18.47), SIMDE_BFLOAT16_VALUE(14.59), SIMDE_BFLOAT16_VALUE(48.79) } },
       {  SIMDE_BFLOAT16_VALUE(7.62), SIMDE_BFLOAT16_VALUE(-49.51)},
     { {  SIMDE_BFLOAT16_VALUE(7.62), SIMDE_BFLOAT16_VALUE(-27.30), SIMDE_BFLOAT16_VALUE(-35.67), SIMDE_BFLOAT16_VALUE(22.98),
        SIMDE_BFLOAT16_VALUE(-34.31), SIMDE_BFLOAT16_VALUE(-40.87), SIMDE_BFLOAT16_VALUE(-37.54), SIMDE_BFLOAT16_VALUE(-11.89) },
       {  SIMDE_BFLOAT16_VALUE(-49.51), SIMDE_BFLOAT16_VALUE(-21.84), SIMDE_BFLOAT16_VALUE(-32.89), SIMDE_BFLOAT16_VALUE(43.11),
        SIMDE_BFLOAT16_VALUE(-10.75), SIMDE_BFLOAT16_VALUE(-18.47), SIMDE_BFLOAT16_VALUE(14.59), SIMDE_BFLOAT16_VALUE(48.79) } } },
   { { {  SIMDE_BFLOAT16_VALUE(-38.62), SIMDE_BFLOAT16_VALUE(4.41), SIMDE_BFLOAT16_VALUE(-33.69), SIMDE_BFLOAT16_VALUE(-29.42),
        SIMDE_BFLOAT16_VALUE(-26.20), SIMDE_BFLOAT16_VALUE(-37.93), SIMDE_BFLOAT16_VALUE(-22.76), SIMDE_BFLOAT16_VALUE(9.22) },
       {  SIMDE_BFLOAT16_VALUE(33.15), SIMDE_BFLOAT16_VALUE(36.15), SIMDE_BFLOAT16_VALUE(8.88), SIMDE_BFLOAT16_VALUE(-47.77),
        SIMDE_BFLOAT16_VALUE(42.44), SIMDE_BFLOAT16_VALUE(-2.49), SIMDE_BFLOAT16_VALUE(-30.82), SIMDE_BFLOAT16_VALUE(-8.07) } },
       {  SIMDE_BFLOAT16_VALUE(13.95), SIMDE_BFLOAT16_VALUE(-11.74)},
     { {  SIMDE_BFLOAT16_VALUE(-38.62), SIMDE_BFLOAT16_VALUE(13.95), SIMDE_BFLOAT16_VALUE(-33.69), SIMDE_BFLOAT16_VALUE(-29.42),
        SIMDE_BFLOAT16_VALUE(-26.20), SIMDE_BFLOAT16_VALUE(-37.93), SIMDE_BFLOAT16_VALUE(-22.76), SIMDE_BFLOAT16_VALUE(9.22) },
       {  SIMDE_BFLOAT16_VALUE(33.15), SIMDE_BFLOAT16_VALUE(-11.74), SIMDE_BFLOAT16_VALUE(8.88), SIMDE_BFLOAT16_VALUE(-47.77),
        SIMDE_BFLOAT16_VALUE(42.44), SIMDE_BFLOAT16_VALUE(-2.49), SIMDE_BFLOAT16_VALUE(-30.82), SIMDE_BFLOAT16_VALUE(-8.07) } } },
   { { {  SIMDE_BFLOAT16_VALUE(20.63), SIMDE_BFLOAT16_VALUE(-26.03), SIMDE_BFLOAT16_VALUE(-49.03), SIMDE_BFLOAT16_VALUE(-9.02),
        SIMDE_BFLOAT16_VALUE(-7.24), SIMDE_BFLOAT16_VALUE(21.25), SIMDE_BFLOAT16_VALUE(7.83), SIMDE_BFLOAT16_VALUE(13.60) },
       {  SIMDE_BFLOAT16_VALUE(-25.60), SIMDE_BFLOAT16_VALUE(-0.34), SIMDE_BFLOAT16_VALUE(-14.32), SIMDE_BFLOAT16_VALUE(11.44),
        SIMDE_BFLOAT16_VALUE(-0.16), SIMDE_BFLOAT16_VALUE(44.81), SIMDE_BFLOAT16_VALUE(-26.95), SIMDE_BFLOAT16_VALUE(-20.70) } },
       {  SIMDE_BFLOAT16_VALUE(-12.06), SIMDE_BFLOAT16_VALUE(-20.03)},
     { {  SIMDE_BFLOAT16_VALUE(20.63), SIMDE_BFLOAT16_VALUE(-26.03), SIMDE_BFLOAT16_VALUE(-12.06), SIMDE_BFLOAT16_VALUE(-9.02),
        SIMDE_BFLOAT16_VALUE(-7.24), SIMDE_BFLOAT16_VALUE(21.25), SIMDE_BFLOAT16_VALUE(7.83), SIMDE_BFLOAT16_VALUE(13.60) },
       {  SIMDE_BFLOAT16_VALUE(-25.60), SIMDE_BFLOAT16_VALUE(-0.34), SIMDE_BFLOAT16_VALUE(-20.03), SIMDE_BFLOAT16_VALUE(11.44),
        SIMDE_BFLOAT16_VALUE(-0.16), SIMDE_BFLOAT16_VALUE(44.81), SIMDE_BFLOAT16_VALUE(-26.95), SIMDE_BFLOAT16_VALUE(-20.70) } } },
   { { {  SIMDE_BFLOAT16_VALUE(-11.60), SIMDE_BFLOAT16_VALUE(-14.50), SIMDE_BFLOAT16_VALUE(45.43), SIMDE_BFLOAT16_VALUE(40.80),
        SIMDE_BFLOAT16_VALUE(-19.67), SIMDE_BFLOAT16_VALUE(-0.54), SIMDE_BFLOAT16_VALUE(31.88), SIMDE_BFLOAT16_VALUE(14.74) },
       {  SIMDE_BFLOAT16_VALUE(-31.78), SIMDE_BFLOAT16_VALUE(8.81), SIMDE_BFLOAT16_VALUE(10.59), SIMDE_BFLOAT16_VALUE(6.10),
        SIMDE_BFLOAT16_VALUE(-25.88), SIMDE_BFLOAT16_VALUE(0.90), SIMDE_BFLOAT16_VALUE(45.87), SIMDE_BFLOAT16_VALUE(13.51) } },
       {  SIMDE_BFLOAT16_VALUE(-26.80), SIMDE_BFLOAT16_VALUE(13.43)},
     { {  SIMDE_BFLOAT16_VALUE(-11.60), SIMDE_BFLOAT16_VALUE(-14.50), SIMDE_BFLOAT16_VALUE(45.43), SIMDE_BFLOAT16_VALUE(-26.80),
        SIMDE_BFLOAT16_VALUE(-19.67), SIMDE_BFLOAT16_VALUE(-0.54), SIMDE_BFLOAT16_VALUE(31.88), SIMDE_BFLOAT16_VALUE(14.74) },
       {  SIMDE_BFLOAT16_VALUE(-31.78), SIMDE_BFLOAT16_VALUE(8.81), SIMDE_BFLOAT16_VALUE(10.59), SIMDE_BFLOAT16_VALUE(13.43),
        SIMDE_BFLOAT16_VALUE(-25.88), SIMDE_BFLOAT16_VALUE(0.90), SIMDE_BFLOAT16_VALUE(45.87), SIMDE_BFLOAT16_VALUE(13.51) } } },
   { { {  SIMDE_BFLOAT16_VALUE(33.71), SIMDE_BFLOAT16_VALUE(-5.48), SIMDE_BFLOAT16_VALUE(-13.87), SIMDE_BFLOAT16_VALUE(2.58),
        SIMDE_BFLOAT16_VALUE(22.05), SIMDE_BFLOAT16_VALUE(-25.14), SIMDE_BFLOAT16_VALUE(32.71), SIMDE_BFLOAT16_VALUE(49.78) },
       {  SIMDE_BFLOAT16_VALUE(-33.81), SIMDE_BFLOAT16_VALUE(-37.35), SIMDE_BFLOAT16_VALUE(6.37), SIMDE_BFLOAT16_VALUE(42.63),
        SIMDE_BFLOAT16_VALUE(27.98), SIMDE_BFLOAT16_VALUE(-47.79), SIMDE_BFLOAT16_VALUE(0.37), SIMDE_BFLOAT16_VALUE(24.16) } },
       {  SIMDE_BFLOAT16_VALUE(-22.12), SIMDE_BFLOAT16_VALUE(22.45)},
     { {  SIMDE_BFLOAT16_VALUE(33.71), SIMDE_BFLOAT16_VALUE(-5.48), SIMDE_BFLOAT16_VALUE(-13.87), SIMDE_BFLOAT16_VALUE(2.58),
        SIMDE_BFLOAT16_VALUE(-22.12), SIMDE_BFLOAT16_VALUE(-25.14), SIMDE_BFLOAT16_VALUE(32.71), SIMDE_BFLOAT16_VALUE(49.78) },
       {  SIMDE_BFLOAT16_VALUE(-33.81), SIMDE_BFLOAT16_VALUE(-37.35), SIMDE_BFLOAT16_VALUE(6.37), SIMDE_BFLOAT16_VALUE(42.63),
        SIMDE_BFLOAT16_VALUE(22.45), SIMDE_BFLOAT16_VALUE(-47.79), SIMDE_BFLOAT16_VALUE(0.37), SIMDE_BFLOAT16_VALUE(24.16) } } },
   { { {  SIMDE_BFLOAT16_VALUE(35.13), SIMDE_BFLOAT16_VALUE(-36.13), SIMDE_BFLOAT16_VALUE(-42.60), SIMDE_BFLOAT16_VALUE(-23.46),
        SIMDE_BFLOAT16_VALUE(-42.93), SIMDE_BFLOAT16_VALUE(-21.16), SIMDE_BFLOAT16_VALUE(-29.86), SIMDE_BFLOAT16_VALUE(29.04) },
       {  SIMDE_BFLOAT16_VALUE(37.40), SIMDE_BFLOAT16_VALUE(30.74), SIMDE_BFLOAT16_VALUE(30.82), SIMDE_BFLOAT16_VALUE(44.38),
        SIMDE_BFLOAT16_VALUE(-30.52), SIMDE_BFLOAT16_VALUE(42.55), SIMDE_BFLOAT16_VALUE(16.70), SIMDE_BFLOAT16_VALUE(47.97) } },
       {  SIMDE_BFLOAT16_VALUE(41.68), SIMDE_BFLOAT16_VALUE(12.98)},
     { {  SIMDE_BFLOAT16_VALUE(35.13), SIMDE_BFLOAT16_VALUE(-36.13), SIMDE_BFLOAT16_VALUE(-42.60), SIMDE_BFLOAT16_VALUE(-23.46),
        SIMDE_BFLOAT16_VALUE(-42.93), SIMDE_BFLOAT16_VALUE(41.68), SIMDE_BFLOAT16_VALUE(-29.86), SIMDE_BFLOAT16_VALUE(29.04) },
       {  SIMDE_BFLOAT16_VALUE(37.40), SIMDE_BFLOAT16_VALUE(30.74), SIMDE_BFLOAT16_VALUE(30.82), SIMDE_BFLOAT16_VALUE(44.38),
        SIMDE_BFLOAT16_VALUE(-30.52), SIMDE_BFLOAT16_VALUE(12.98), SIMDE_BFLOAT16_VALUE(16.70), SIMDE_BFLOAT16_VALUE(47.97) } } },
   { { {  SIMDE_BFLOAT16_VALUE(45.22), SIMDE_BFLOAT16_VALUE(-8.00), SIMDE_BFLOAT16_VALUE(-27.03), SIMDE_BFLOAT16_VALUE(48.60),
        SIMDE_BFLOAT16_VALUE(19.87), SIMDE_BFLOAT16_VALUE(-1.72), SIMDE_BFLOAT16_VALUE(-45.40), SIMDE_BFLOAT16_VALUE(-3.56) },
       {  SIMDE_BFLOAT16_VALUE(36.60), SIMDE_BFLOAT16_VALUE(-32.25), SIMDE_BFLOAT16_VALUE(13.01), SIMDE_BFLOAT16_VALUE(-12.64),
        SIMDE_BFLOAT16_VALUE(22.43), SIMDE_BFLOAT16_VALUE(1.87), SIMDE_BFLOAT16_VALUE(-38.57), SIMDE_BFLOAT16_VALUE(-24.61) } },
       {  SIMDE_BFLOAT16_VALUE(49.75), SIMDE_BFLOAT16_VALUE(-1.23)},
     { {  SIMDE_BFLOAT16_VALUE(45.22), SIMDE_BFLOAT16_VALUE(-8.00), SIMDE_BFLOAT16_VALUE(-27.03), SIMDE_BFLOAT16_VALUE(48.60),
        SIMDE_BFLOAT16_VALUE(19.87), SIMDE_BFLOAT16_VALUE(-1.72), SIMDE_BFLOAT16_VALUE(49.75), SIMDE_BFLOAT16_VALUE(-3.56) },
       {  SIMDE_BFLOAT16_VALUE(36.60), SIMDE_BFLOAT16_VALUE(-32.25), SIMDE_BFLOAT16_VALUE(13.01), SIMDE_BFLOAT16_VALUE(-12.64),
        SIMDE_BFLOAT16_VALUE(22.43), SIMDE_BFLOAT16_VALUE(1.87), SIMDE_BFLOAT16_VALUE(-1.23), SIMDE_BFLOAT16_VALUE(-24.61) } } },
   { { {  SIMDE_BFLOAT16_VALUE(24.31), SIMDE_BFLOAT16_VALUE(-43.53), SIMDE_BFLOAT16_VALUE(20.69), SIMDE_BFLOAT16_VALUE(26.28),
        SIMDE_BFLOAT16_VALUE(44.06), SIMDE_BFLOAT16_VALUE(42.57), SIMDE_BFLOAT16_VALUE(7.84), SIMDE_BFLOAT16_VALUE(-4.34) },
       {  SIMDE_BFLOAT16_VALUE(-7.29), SIMDE_BFLOAT16_VALUE(5.56), SIMDE_BFLOAT16_VALUE(-20.99), SIMDE_BFLOAT16_VALUE(-46.49),
        SIMDE_BFLOAT16_VALUE(24.87), SIMDE_BFLOAT16_VALUE(40.56), SIMDE_BFLOAT16_VALUE(-20.02), SIMDE_BFLOAT16_VALUE(38.66) } },
       {  SIMDE_BFLOAT16_VALUE(17.79), SIMDE_BFLOAT16_VALUE(37.56)},
     { {  SIMDE_BFLOAT16_VALUE(24.31), SIMDE_BFLOAT16_VALUE(-43.53), SIMDE_BFLOAT16_VALUE(20.69), SIMDE_BFLOAT16_VALUE(26.28),
        SIMDE_BFLOAT16_VALUE(44.06), SIMDE_BFLOAT16_VALUE(42.57), SIMDE_BFLOAT16_VALUE(7.84), SIMDE_BFLOAT16_VALUE(17.79) },
       {  SIMDE_BFLOAT16_VALUE(-7.29), SIMDE_BFLOAT16_VALUE(5.56), SIMDE_BFLOAT16_VALUE(-20.99), SIMDE_BFLOAT16_VALUE(-46.49),
        SIMDE_BFLOAT16_VALUE(24.87), SIMDE_BFLOAT16_VALUE(40.56), SIMDE_BFLOAT16_VALUE(-20.02), SIMDE_BFLOAT16_VALUE(37.56) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_bfloat16x8x2_t r, src, expected;
    src.val[0] = simde_vld1q_bf16(test_vec[i].src[0]);
    src.val[1] = simde_vld1q_bf16(test_vec[i].src[1]);

    SIMDE_CONSTIFY_8_(simde_vld2q_lane_bf16, r, (HEDLEY_UNREACHABLE(), r), i, test_vec[i].buf, src);

    expected.val[0] = simde_vld1q_bf16(test_vec[i].r[0]);
    expected.val[1] = simde_vld1q_bf16(test_vec[i].r[1]);

    simde_test_arm_neon_assert_equal_bf16x8(r.val[0], expected.val[0], INT_MAX);
    simde_test_arm_neon_assert_equal_bf16x8(r.val[1], expected.val[1], INT_MAX);
  }

  return 0;
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vld2_lane_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vld2_lane_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vld2_lane_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vld2_lane_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vld2_lane_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vld2_lane_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vld2_lane_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vld2_lane_u64)
SIMDE_TEST_FUNC_LIST_ENTRY(vld2_lane_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vld2_lane_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vld2_lane_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vld2q_lane_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vld2q_lane_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vld2q_lane_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vld2q_lane_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vld2q_lane_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vld2q_lane_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vld2q_lane_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vld2q_lane_u64)
SIMDE_TEST_FUNC_LIST_ENTRY(vld2q_lane_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vld2q_lane_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vld2q_lane_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vld2_lane_p8)
SIMDE_TEST_FUNC_LIST_ENTRY(vld2_lane_p16)
SIMDE_TEST_FUNC_LIST_ENTRY(vld2_lane_p64)
SIMDE_TEST_FUNC_LIST_ENTRY(vld2q_lane_p8)
SIMDE_TEST_FUNC_LIST_ENTRY(vld2q_lane_p16)
SIMDE_TEST_FUNC_LIST_ENTRY(vld2q_lane_p64)
SIMDE_TEST_FUNC_LIST_ENTRY(vld2_lane_bf16)
SIMDE_TEST_FUNC_LIST_ENTRY(vld2q_lane_bf16)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
