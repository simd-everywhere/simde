#define SIMDE_TEST_ARM_NEON_INSN ld3_lane

#include "test-neon.h"
#include "../../../simde/arm/neon/ld3_lane.h"
#include "../../../simde/arm/neon/ld1.h"
#include "../../../simde/arm/neon/ld3.h"

static int
test_simde_vld3_lane_s8 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int8_t src[3][8];
    int8_t buf[3];
    int8_t r[3][8];
  } test_vec[] = {
   { { {  -INT8_C(17), -INT8_C(27), -INT8_C(24), -INT8_C(29),
        INT8_C(45), -INT8_C(6), INT8_C(34), INT8_C(10) },
       {  INT8_C(15), -INT8_C(6), -INT8_C(6), -INT8_C(34),
        INT8_C(47), -INT8_C(6), -INT8_C(24), INT8_C(49) },
       {  INT8_C(32), -INT8_C(18), -INT8_C(20), -INT8_C(33),
        INT8_C(12), -INT8_C(21), INT8_C(2), INT8_C(28) } },
       {  -INT8_C(9), -INT8_C(28), -INT8_C(19)},
     { {  -INT8_C(9), -INT8_C(27), -INT8_C(24), -INT8_C(29),
        INT8_C(45), -INT8_C(6), INT8_C(34), INT8_C(10) },
       {  -INT8_C(28), -INT8_C(6), -INT8_C(6), -INT8_C(34),
        INT8_C(47), -INT8_C(6), -INT8_C(24), INT8_C(49) },
       {  -INT8_C(19), -INT8_C(18), -INT8_C(20), -INT8_C(33),
        INT8_C(12), -INT8_C(21), INT8_C(2), INT8_C(28) } } },
   { { {  INT8_C(33), -INT8_C(24), INT8_C(12), -INT8_C(5),
        -INT8_C(4), INT8_C(9), INT8_C(28), -INT8_C(40) },
       {  -INT8_C(25), -INT8_C(46), -INT8_C(36), -INT8_C(31),
        -INT8_C(43), INT8_C(0), -INT8_C(20), -INT8_C(12) },
       {  INT8_C(49), -INT8_C(13), -INT8_C(21), -INT8_C(19),
        -INT8_C(42), INT8_C(4), INT8_C(13), INT8_C(29) } },
       {  INT8_C(46), INT8_C(40), -INT8_C(35)},
     { {  INT8_C(33), INT8_C(46), INT8_C(12), -INT8_C(5),
        -INT8_C(4), INT8_C(9), INT8_C(28), -INT8_C(40) },
       {  -INT8_C(25), INT8_C(40), -INT8_C(36), -INT8_C(31),
        -INT8_C(43), INT8_C(0), -INT8_C(20), -INT8_C(12) },
       {  INT8_C(49), -INT8_C(35), -INT8_C(21), -INT8_C(19),
        -INT8_C(42), INT8_C(4), INT8_C(13), INT8_C(29) } } },
   { { {  -INT8_C(27), INT8_C(37), -INT8_C(43), -INT8_C(32),
        -INT8_C(3), INT8_C(33), -INT8_C(33), -INT8_C(40) },
       {  INT8_C(34), INT8_C(6), -INT8_C(20), -INT8_C(40),
        -INT8_C(34), -INT8_C(45), -INT8_C(44), INT8_C(38) },
       {  INT8_C(3), INT8_C(26), INT8_C(30), INT8_C(6),
        -INT8_C(3), -INT8_C(2), -INT8_C(40), -INT8_C(5) } },
       {  INT8_C(16), INT8_C(31), INT8_C(26)},
     { {  -INT8_C(27), INT8_C(37), INT8_C(16), -INT8_C(32),
        -INT8_C(3), INT8_C(33), -INT8_C(33), -INT8_C(40) },
       {  INT8_C(34), INT8_C(6), INT8_C(31), -INT8_C(40),
        -INT8_C(34), -INT8_C(45), -INT8_C(44), INT8_C(38) },
       {  INT8_C(3), INT8_C(26), INT8_C(26), INT8_C(6),
        -INT8_C(3), -INT8_C(2), -INT8_C(40), -INT8_C(5) } } },
   { { {  INT8_C(10), INT8_C(35), -INT8_C(11), -INT8_C(33),
        -INT8_C(4), -INT8_C(40), -INT8_C(41), INT8_C(1) },
       {  -INT8_C(21), -INT8_C(47), -INT8_C(4), -INT8_C(34),
        INT8_C(19), -INT8_C(3), -INT8_C(44), INT8_C(33) },
       {  -INT8_C(7), INT8_C(0), INT8_C(1), INT8_C(17),
        -INT8_C(20), -INT8_C(4), -INT8_C(6), INT8_C(0) } },
       {  INT8_C(34), -INT8_C(2), -INT8_C(40)},
     { {  INT8_C(10), INT8_C(35), -INT8_C(11), INT8_C(34),
        -INT8_C(4), -INT8_C(40), -INT8_C(41), INT8_C(1) },
       {  -INT8_C(21), -INT8_C(47), -INT8_C(4), -INT8_C(2),
        INT8_C(19), -INT8_C(3), -INT8_C(44), INT8_C(33) },
       {  -INT8_C(7), INT8_C(0), INT8_C(1), -INT8_C(40),
        -INT8_C(20), -INT8_C(4), -INT8_C(6), INT8_C(0) } } },
   { { {  -INT8_C(12), INT8_C(32), -INT8_C(3), INT8_C(11),
        INT8_C(0), INT8_C(1), INT8_C(1), -INT8_C(2) },
       {  INT8_C(6), -INT8_C(22), -INT8_C(37), -INT8_C(9),
        INT8_C(0), INT8_C(43), INT8_C(37), -INT8_C(31) },
       {  -INT8_C(33), -INT8_C(18), INT8_C(20), -INT8_C(34),
        INT8_C(49), -INT8_C(23), INT8_C(10), -INT8_C(44) } },
       {  -INT8_C(38), -INT8_C(42), -INT8_C(3)},
     { {  -INT8_C(12), INT8_C(32), -INT8_C(3), INT8_C(11),
        -INT8_C(38), INT8_C(1), INT8_C(1), -INT8_C(2) },
       {  INT8_C(6), -INT8_C(22), -INT8_C(37), -INT8_C(9),
        -INT8_C(42), INT8_C(43), INT8_C(37), -INT8_C(31) },
       {  -INT8_C(33), -INT8_C(18), INT8_C(20), -INT8_C(34),
        -INT8_C(3), -INT8_C(23), INT8_C(10), -INT8_C(44) } } },
   { { {  -INT8_C(33), -INT8_C(1), -INT8_C(12), -INT8_C(11),
        INT8_C(22), INT8_C(9), -INT8_C(46), -INT8_C(47) },
       {  INT8_C(11), INT8_C(4), INT8_C(6), INT8_C(27),
        INT8_C(47), -INT8_C(17), -INT8_C(44), -INT8_C(20) },
       {  INT8_C(42), INT8_C(16), -INT8_C(25), -INT8_C(48),
        -INT8_C(20), -INT8_C(32), INT8_C(29), INT8_C(28) } },
       {  -INT8_C(20), INT8_C(0), -INT8_C(3)},
     { {  -INT8_C(33), -INT8_C(1), -INT8_C(12), -INT8_C(11),
        INT8_C(22), -INT8_C(20), -INT8_C(46), -INT8_C(47) },
       {  INT8_C(11), INT8_C(4), INT8_C(6), INT8_C(27),
        INT8_C(47), INT8_C(0), -INT8_C(44), -INT8_C(20) },
       {  INT8_C(42), INT8_C(16), -INT8_C(25), -INT8_C(48),
        -INT8_C(20), -INT8_C(3), INT8_C(29), INT8_C(28) } } },
   { { {  INT8_C(11), -INT8_C(5), INT8_C(3), -INT8_C(28),
        INT8_C(37), INT8_C(25), INT8_C(16), INT8_C(13) },
       {  INT8_C(24), -INT8_C(39), -INT8_C(4), -INT8_C(13),
        INT8_C(49), -INT8_C(3), INT8_C(25), INT8_C(9) },
       {  -INT8_C(48), INT8_C(8), INT8_C(12), -INT8_C(4),
        INT8_C(0), -INT8_C(7), -INT8_C(14), INT8_C(20) } },
       {  -INT8_C(25), INT8_C(1), INT8_C(11)},
     { {  INT8_C(11), -INT8_C(5), INT8_C(3), -INT8_C(28),
        INT8_C(37), INT8_C(25), -INT8_C(25), INT8_C(13) },
       {  INT8_C(24), -INT8_C(39), -INT8_C(4), -INT8_C(13),
        INT8_C(49), -INT8_C(3), INT8_C(1), INT8_C(9) },
       {  -INT8_C(48), INT8_C(8), INT8_C(12), -INT8_C(4),
        INT8_C(0), -INT8_C(7), INT8_C(11), INT8_C(20) } } },
   { { {  INT8_C(22), -INT8_C(26), INT8_C(11), -INT8_C(25),
        INT8_C(7), INT8_C(29), INT8_C(35), -INT8_C(33) },
       {  -INT8_C(21), INT8_C(33), INT8_C(0), -INT8_C(39),
        -INT8_C(43), INT8_C(28), INT8_C(31), -INT8_C(10) },
       {  -INT8_C(17), INT8_C(14), -INT8_C(41), INT8_C(30),
        INT8_C(37), INT8_C(32), -INT8_C(7), -INT8_C(4) } },
       {  -INT8_C(30), -INT8_C(48), INT8_C(17)},
     { {  INT8_C(22), -INT8_C(26), INT8_C(11), -INT8_C(25),
        INT8_C(7), INT8_C(29), INT8_C(35), -INT8_C(30) },
       {  -INT8_C(21), INT8_C(33), INT8_C(0), -INT8_C(39),
        -INT8_C(43), INT8_C(28), INT8_C(31), -INT8_C(48) },
       {  -INT8_C(17), INT8_C(14), -INT8_C(41), INT8_C(30),
        INT8_C(37), INT8_C(32), -INT8_C(7), INT8_C(17) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8x3_t r, src, expected;
    src.val[0] = simde_vld1_s8(test_vec[i].src[0]);
    src.val[1] = simde_vld1_s8(test_vec[i].src[1]);
    src.val[2] = simde_vld1_s8(test_vec[i].src[2]);

    SIMDE_CONSTIFY_8_(simde_vld3_lane_s8, r, (HEDLEY_UNREACHABLE(), r), i, test_vec[i].buf, src);

    expected.val[0] = simde_vld1_s8(test_vec[i].r[0]);
    expected.val[1] = simde_vld1_s8(test_vec[i].r[1]);
    expected.val[2] = simde_vld1_s8(test_vec[i].r[2]);

    simde_test_arm_neon_assert_equal_i8x8(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_i8x8(r.val[1], expected.val[1]);
    simde_test_arm_neon_assert_equal_i8x8(r.val[2], expected.val[2]);
  }

  return 0;
}

static int
test_simde_vld3_lane_s16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int16_t src[3][4];
    int16_t buf[3];
    int16_t r[3][4];
  } test_vec[] = {
   { { {  INT16_C(2717), INT16_C(575), INT16_C(4902), INT16_C(2261) },
       {  INT16_C(1233), INT16_C(4720), -INT16_C(4726), INT16_C(4438) },
       {  -INT16_C(4256), -INT16_C(1119), INT16_C(3307), -INT16_C(1818) } },
       {  INT16_C(986), -INT16_C(4050), -INT16_C(1206)},
     { {  INT16_C(986), INT16_C(575), INT16_C(4902), INT16_C(2261) },
       {  -INT16_C(4050), INT16_C(4720), -INT16_C(4726), INT16_C(4438) },
       {  -INT16_C(1206), -INT16_C(1119), INT16_C(3307), -INT16_C(1818) } } },
   { { {  -INT16_C(82), INT16_C(3569), -INT16_C(3685), -INT16_C(2988) },
       {  INT16_C(2597), INT16_C(868), INT16_C(1723), INT16_C(2628) },
       {  INT16_C(905), -INT16_C(2883), -INT16_C(1731), -INT16_C(2362) } },
       {  INT16_C(4882), INT16_C(4746), -INT16_C(2975)},
     { {  -INT16_C(82), INT16_C(4882), -INT16_C(3685), -INT16_C(2988) },
       {  INT16_C(2597), INT16_C(4746), INT16_C(1723), INT16_C(2628) },
       {  INT16_C(905), -INT16_C(2975), -INT16_C(1731), -INT16_C(2362) } } },
   { { {  -INT16_C(1293), -INT16_C(551), -INT16_C(1223), INT16_C(4017) },
       {  INT16_C(1594), INT16_C(1517), INT16_C(2534), INT16_C(2808) },
       {  INT16_C(415), INT16_C(2904), INT16_C(1958), INT16_C(961) } },
       {  -INT16_C(3918), INT16_C(1301), INT16_C(150)},
     { {  -INT16_C(1293), -INT16_C(551), -INT16_C(3918), INT16_C(4017) },
       {  INT16_C(1594), INT16_C(1517), INT16_C(1301), INT16_C(2808) },
       {  INT16_C(415), INT16_C(2904), INT16_C(150), INT16_C(961) } } },
   { { {  -INT16_C(2100), INT16_C(2262), -INT16_C(3223), -INT16_C(3872) },
       {  -INT16_C(2926), -INT16_C(109), -INT16_C(4620), INT16_C(4053) },
       {  INT16_C(3674), INT16_C(2439), INT16_C(4543), -INT16_C(996) } },
       {  INT16_C(4138), INT16_C(3789), -INT16_C(566)},
     { {  -INT16_C(2100), INT16_C(2262), -INT16_C(3223), INT16_C(4138) },
       {  -INT16_C(2926), -INT16_C(109), -INT16_C(4620), INT16_C(3789) },
       {  INT16_C(3674), INT16_C(2439), INT16_C(4543), -INT16_C(566) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4x3_t r, src, expected;
    src.val[0] = simde_vld1_s16(test_vec[i].src[0]);
    src.val[1] = simde_vld1_s16(test_vec[i].src[1]);
    src.val[2] = simde_vld1_s16(test_vec[i].src[2]);

    SIMDE_CONSTIFY_4_(simde_vld3_lane_s16, r, (HEDLEY_UNREACHABLE(), r), i, test_vec[i].buf, src);

    expected.val[0] = simde_vld1_s16(test_vec[i].r[0]);
    expected.val[1] = simde_vld1_s16(test_vec[i].r[1]);
    expected.val[2] = simde_vld1_s16(test_vec[i].r[2]);

    simde_test_arm_neon_assert_equal_i16x4(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_i16x4(r.val[1], expected.val[1]);
    simde_test_arm_neon_assert_equal_i16x4(r.val[2], expected.val[2]);
  }

  return 0;
}

static int
test_simde_vld3_lane_s32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int32_t src[3][2];
    int32_t buf[3];
    int32_t r[3][2];
  } test_vec[] = {
   { { {  -INT32_C(386983), -INT32_C(217954) },
       {  INT32_C(344519), -INT32_C(251850) },
       {  -INT32_C(126242), INT32_C(117859) } },
       {  INT32_C(83246), INT32_C(273121), INT32_C(59814)},
     { {  INT32_C(83246), -INT32_C(217954) },
       {  INT32_C(273121), -INT32_C(251850) },
       {  INT32_C(59814), INT32_C(117859) } } },
   { { {  -INT32_C(177200), INT32_C(336643) },
       {  INT32_C(240336), -INT32_C(324844) },
       {  -INT32_C(254120), -INT32_C(345522) } },
       {  INT32_C(488920), -INT32_C(470183), -INT32_C(90512)},
     { {  -INT32_C(177200), INT32_C(488920) },
       {  INT32_C(240336), -INT32_C(470183) },
       {  -INT32_C(254120), -INT32_C(90512) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2x3_t r, src, expected;
    src.val[0] = simde_vld1_s32(test_vec[i].src[0]);
    src.val[1] = simde_vld1_s32(test_vec[i].src[1]);
    src.val[2] = simde_vld1_s32(test_vec[i].src[2]);

    SIMDE_CONSTIFY_2_(simde_vld3_lane_s32, r, (HEDLEY_UNREACHABLE(), r), i, test_vec[i].buf, src);

    expected.val[0] = simde_vld1_s32(test_vec[i].r[0]);
    expected.val[1] = simde_vld1_s32(test_vec[i].r[1]);
    expected.val[2] = simde_vld1_s32(test_vec[i].r[2]);

    simde_test_arm_neon_assert_equal_i32x2(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_i32x2(r.val[1], expected.val[1]);
    simde_test_arm_neon_assert_equal_i32x2(r.val[2], expected.val[2]);
  }

  return 0;
}

static int
test_simde_vld3_lane_s64 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int64_t src[3][1];
    int64_t buf[3];
    int64_t r[3][1];
  } test_vec[] = {
   { { {  -INT64_C(41604193) },
       {  -INT64_C(22070552) },
       {  INT64_C(139589) } },
       {  -INT64_C(18919378), -INT64_C(10176256), INT64_C(1594941)},
     { {  -INT64_C(18919378) },
       {  -INT64_C(10176256) },
       {  INT64_C(1594941) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x1x3_t r, src, expected;
    src.val[0] = simde_vld1_s64(test_vec[i].src[0]);
    src.val[1] = simde_vld1_s64(test_vec[i].src[1]);
    src.val[2] = simde_vld1_s64(test_vec[i].src[2]);

    r = simde_vld3_lane_s64(test_vec[i].buf, src, 0);

    expected.val[0] = simde_vld1_s64(test_vec[i].r[0]);
    expected.val[1] = simde_vld1_s64(test_vec[i].r[1]);
    expected.val[2] = simde_vld1_s64(test_vec[i].r[2]);

    simde_test_arm_neon_assert_equal_i64x1(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_i64x1(r.val[1], expected.val[1]);
    simde_test_arm_neon_assert_equal_i64x1(r.val[2], expected.val[2]);
  }

  return 0;
}

static int
test_simde_vld3_lane_u8 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    uint8_t src[3][8];
    uint8_t buf[3];
    uint8_t r[3][8];
  } test_vec[] = {
   { { {  UINT8_C(75), UINT8_C(35), UINT8_C(26), UINT8_C(54),
        UINT8_C(1), UINT8_C(45), UINT8_C(13), UINT8_C(16) },
       {  UINT8_C(71), UINT8_C(47), UINT8_C(17), UINT8_C(80),
        UINT8_C(66), UINT8_C(34), UINT8_C(97), UINT8_C(20) },
       {  UINT8_C(41), UINT8_C(28), UINT8_C(70), UINT8_C(58),
        UINT8_C(81), UINT8_C(47), UINT8_C(7), UINT8_C(80) } },
       {  UINT8_C(92), UINT8_C(95), UINT8_C(50)},
     { {  UINT8_C(92), UINT8_C(35), UINT8_C(26), UINT8_C(54),
        UINT8_C(1), UINT8_C(45), UINT8_C(13), UINT8_C(16) },
       {  UINT8_C(95), UINT8_C(47), UINT8_C(17), UINT8_C(80),
        UINT8_C(66), UINT8_C(34), UINT8_C(97), UINT8_C(20) },
       {  UINT8_C(50), UINT8_C(28), UINT8_C(70), UINT8_C(58),
        UINT8_C(81), UINT8_C(47), UINT8_C(7), UINT8_C(80) } } },
   { { {  UINT8_C(42), UINT8_C(96), UINT8_C(15), UINT8_C(5),
        UINT8_C(54), UINT8_C(1), UINT8_C(68), UINT8_C(93) },
       {  UINT8_C(5), UINT8_C(62), UINT8_C(9), UINT8_C(30),
        UINT8_C(18), UINT8_C(45), UINT8_C(2), UINT8_C(28) },
       {  UINT8_C(65), UINT8_C(82), UINT8_C(30), UINT8_C(37),
        UINT8_C(18), UINT8_C(53), UINT8_C(59), UINT8_C(73) } },
       {  UINT8_C(45), UINT8_C(63), UINT8_C(47)},
     { {  UINT8_C(42), UINT8_C(45), UINT8_C(15), UINT8_C(5),
        UINT8_C(54), UINT8_C(1), UINT8_C(68), UINT8_C(93) },
       {  UINT8_C(5), UINT8_C(63), UINT8_C(9), UINT8_C(30),
        UINT8_C(18), UINT8_C(45), UINT8_C(2), UINT8_C(28) },
       {  UINT8_C(65), UINT8_C(47), UINT8_C(30), UINT8_C(37),
        UINT8_C(18), UINT8_C(53), UINT8_C(59), UINT8_C(73) } } },
   { { {  UINT8_C(5), UINT8_C(76), UINT8_C(80), UINT8_C(97),
        UINT8_C(33), UINT8_C(72), UINT8_C(43), UINT8_C(79) },
       {  UINT8_C(75), UINT8_C(82), UINT8_C(0), UINT8_C(67),
        UINT8_C(37), UINT8_C(5), UINT8_C(72), UINT8_C(27) },
       {  UINT8_C(1), UINT8_C(63), UINT8_C(20), UINT8_C(19),
        UINT8_C(83), UINT8_C(8), UINT8_C(44), UINT8_C(57) } },
       {  UINT8_C(63), UINT8_C(85), UINT8_C(98)},
     { {  UINT8_C(5), UINT8_C(76), UINT8_C(63), UINT8_C(97),
        UINT8_C(33), UINT8_C(72), UINT8_C(43), UINT8_C(79) },
       {  UINT8_C(75), UINT8_C(82), UINT8_C(85), UINT8_C(67),
        UINT8_C(37), UINT8_C(5), UINT8_C(72), UINT8_C(27) },
       {  UINT8_C(1), UINT8_C(63), UINT8_C(98), UINT8_C(19),
        UINT8_C(83), UINT8_C(8), UINT8_C(44), UINT8_C(57) } } },
   { { {  UINT8_C(72), UINT8_C(56), UINT8_C(65), UINT8_C(46),
        UINT8_C(4), UINT8_C(16), UINT8_C(78), UINT8_C(1) },
       {  UINT8_C(18), UINT8_C(48), UINT8_C(95), UINT8_C(22),
        UINT8_C(70), UINT8_C(44), UINT8_C(38), UINT8_C(3) },
       {  UINT8_C(23), UINT8_C(7), UINT8_C(81), UINT8_C(1),
        UINT8_C(25), UINT8_C(17), UINT8_C(17), UINT8_C(41) } },
       {  UINT8_C(60), UINT8_C(43), UINT8_C(32)},
     { {  UINT8_C(72), UINT8_C(56), UINT8_C(65), UINT8_C(60),
        UINT8_C(4), UINT8_C(16), UINT8_C(78), UINT8_C(1) },
       {  UINT8_C(18), UINT8_C(48), UINT8_C(95), UINT8_C(43),
        UINT8_C(70), UINT8_C(44), UINT8_C(38), UINT8_C(3) },
       {  UINT8_C(23), UINT8_C(7), UINT8_C(81), UINT8_C(32),
        UINT8_C(25), UINT8_C(17), UINT8_C(17), UINT8_C(41) } } },
   { { {  UINT8_C(90), UINT8_C(17), UINT8_C(65), UINT8_C(25),
        UINT8_C(72), UINT8_C(23), UINT8_C(54), UINT8_C(47) },
       {  UINT8_C(59), UINT8_C(82), UINT8_C(35), UINT8_C(91),
        UINT8_C(46), UINT8_C(26), UINT8_C(40), UINT8_C(79) },
       {  UINT8_C(73), UINT8_C(71), UINT8_C(80), UINT8_C(13),
        UINT8_C(88), UINT8_C(62), UINT8_C(41), UINT8_C(0) } },
       {  UINT8_C(86), UINT8_C(2), UINT8_C(23)},
     { {  UINT8_C(90), UINT8_C(17), UINT8_C(65), UINT8_C(25),
        UINT8_C(86), UINT8_C(23), UINT8_C(54), UINT8_C(47) },
       {  UINT8_C(59), UINT8_C(82), UINT8_C(35), UINT8_C(91),
        UINT8_C(2), UINT8_C(26), UINT8_C(40), UINT8_C(79) },
       {  UINT8_C(73), UINT8_C(71), UINT8_C(80), UINT8_C(13),
        UINT8_C(23), UINT8_C(62), UINT8_C(41), UINT8_C(0) } } },
   { { {  UINT8_C(9), UINT8_C(4), UINT8_C(48), UINT8_C(49),
        UINT8_C(13), UINT8_C(76), UINT8_C(28), UINT8_C(38) },
       {  UINT8_C(80), UINT8_C(15), UINT8_C(59), UINT8_C(29),
        UINT8_C(83), UINT8_C(69), UINT8_C(55), UINT8_C(2) },
       {  UINT8_C(12), UINT8_C(53), UINT8_C(98), UINT8_C(65),
        UINT8_C(68), UINT8_C(99), UINT8_C(58), UINT8_C(18) } },
       {  UINT8_C(49), UINT8_C(77), UINT8_C(71)},
     { {  UINT8_C(9), UINT8_C(4), UINT8_C(48), UINT8_C(49),
        UINT8_C(13), UINT8_C(49), UINT8_C(28), UINT8_C(38) },
       {  UINT8_C(80), UINT8_C(15), UINT8_C(59), UINT8_C(29),
        UINT8_C(83), UINT8_C(77), UINT8_C(55), UINT8_C(2) },
       {  UINT8_C(12), UINT8_C(53), UINT8_C(98), UINT8_C(65),
        UINT8_C(68), UINT8_C(71), UINT8_C(58), UINT8_C(18) } } },
   { { {  UINT8_C(21), UINT8_C(55), UINT8_C(12), UINT8_C(49),
        UINT8_C(97), UINT8_C(12), UINT8_C(16), UINT8_C(51) },
       {  UINT8_C(90), UINT8_C(34), UINT8_C(48), UINT8_C(61),
        UINT8_C(90), UINT8_C(4), UINT8_C(74), UINT8_C(53) },
       {  UINT8_C(44), UINT8_C(38), UINT8_C(5), UINT8_C(81),
        UINT8_C(71), UINT8_C(12), UINT8_C(0), UINT8_C(21) } },
       {  UINT8_C(61), UINT8_C(40), UINT8_C(87)},
     { {  UINT8_C(21), UINT8_C(55), UINT8_C(12), UINT8_C(49),
        UINT8_C(97), UINT8_C(12), UINT8_C(61), UINT8_C(51) },
       {  UINT8_C(90), UINT8_C(34), UINT8_C(48), UINT8_C(61),
        UINT8_C(90), UINT8_C(4), UINT8_C(40), UINT8_C(53) },
       {  UINT8_C(44), UINT8_C(38), UINT8_C(5), UINT8_C(81),
        UINT8_C(71), UINT8_C(12), UINT8_C(87), UINT8_C(21) } } },
   { { {  UINT8_C(95), UINT8_C(70), UINT8_C(79), UINT8_C(1),
        UINT8_C(27), UINT8_C(95), UINT8_C(83), UINT8_C(31) },
       {  UINT8_C(45), UINT8_C(24), UINT8_C(38), UINT8_C(76),
        UINT8_C(85), UINT8_C(61), UINT8_C(59), UINT8_C(71) },
       {  UINT8_C(7), UINT8_C(7), UINT8_C(22), UINT8_C(38),
        UINT8_C(73), UINT8_C(72), UINT8_C(79), UINT8_C(43) } },
       {  UINT8_C(9), UINT8_C(96), UINT8_C(17)},
     { {  UINT8_C(95), UINT8_C(70), UINT8_C(79), UINT8_C(1),
        UINT8_C(27), UINT8_C(95), UINT8_C(83), UINT8_C(9) },
       {  UINT8_C(45), UINT8_C(24), UINT8_C(38), UINT8_C(76),
        UINT8_C(85), UINT8_C(61), UINT8_C(59), UINT8_C(96) },
       {  UINT8_C(7), UINT8_C(7), UINT8_C(22), UINT8_C(38),
        UINT8_C(73), UINT8_C(72), UINT8_C(79), UINT8_C(17) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x8x3_t r, src, expected;
    src.val[0] = simde_vld1_u8(test_vec[i].src[0]);
    src.val[1] = simde_vld1_u8(test_vec[i].src[1]);
    src.val[2] = simde_vld1_u8(test_vec[i].src[2]);

    SIMDE_CONSTIFY_8_(simde_vld3_lane_u8, r, (HEDLEY_UNREACHABLE(), r), i, test_vec[i].buf, src);

    expected.val[0] = simde_vld1_u8(test_vec[i].r[0]);
    expected.val[1] = simde_vld1_u8(test_vec[i].r[1]);
    expected.val[2] = simde_vld1_u8(test_vec[i].r[2]);

    simde_test_arm_neon_assert_equal_u8x8(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_u8x8(r.val[1], expected.val[1]);
    simde_test_arm_neon_assert_equal_u8x8(r.val[2], expected.val[2]);
  }

  return 0;
}

static int
test_simde_vld3_lane_u16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    uint16_t src[3][4];
    uint16_t buf[3];
    uint16_t r[3][4];
  } test_vec[] = {
   { { {  UINT16_C(6015), UINT16_C(2114), UINT16_C(9985), UINT16_C(6732) },
       {  UINT16_C(8774), UINT16_C(5943), UINT16_C(9952), UINT16_C(6251) },
       {  UINT16_C(7677), UINT16_C(4431), UINT16_C(8936), UINT16_C(5217) } },
       {  UINT16_C(6123), UINT16_C(8122), UINT16_C(6028)},
     { {  UINT16_C(6123), UINT16_C(2114), UINT16_C(9985), UINT16_C(6732) },
       {  UINT16_C(8122), UINT16_C(5943), UINT16_C(9952), UINT16_C(6251) },
       {  UINT16_C(6028), UINT16_C(4431), UINT16_C(8936), UINT16_C(5217) } } },
   { { {  UINT16_C(1502), UINT16_C(4900), UINT16_C(3595), UINT16_C(5262) },
       {  UINT16_C(8144), UINT16_C(1060), UINT16_C(6932), UINT16_C(5912) },
       {  UINT16_C(6252), UINT16_C(4564), UINT16_C(7952), UINT16_C(4773) } },
       {  UINT16_C(8849), UINT16_C(6285), UINT16_C(845)},
     { {  UINT16_C(1502), UINT16_C(8849), UINT16_C(3595), UINT16_C(5262) },
       {  UINT16_C(8144), UINT16_C(6285), UINT16_C(6932), UINT16_C(5912) },
       {  UINT16_C(6252), UINT16_C(845), UINT16_C(7952), UINT16_C(4773) } } },
   { { {  UINT16_C(8789), UINT16_C(6109), UINT16_C(2590), UINT16_C(503) },
       {  UINT16_C(5135), UINT16_C(1328), UINT16_C(5106), UINT16_C(3566) },
       {  UINT16_C(6125), UINT16_C(5630), UINT16_C(1661), UINT16_C(5502) } },
       {  UINT16_C(7329), UINT16_C(958), UINT16_C(9522)},
     { {  UINT16_C(8789), UINT16_C(6109), UINT16_C(7329), UINT16_C(503) },
       {  UINT16_C(5135), UINT16_C(1328), UINT16_C(958), UINT16_C(3566) },
       {  UINT16_C(6125), UINT16_C(5630), UINT16_C(9522), UINT16_C(5502) } } },
   { { {  UINT16_C(237), UINT16_C(4662), UINT16_C(2239), UINT16_C(7486) },
       {  UINT16_C(9269), UINT16_C(4261), UINT16_C(1015), UINT16_C(4021) },
       {  UINT16_C(8255), UINT16_C(239), UINT16_C(9693), UINT16_C(2843) } },
       {  UINT16_C(2785), UINT16_C(9518), UINT16_C(5622)},
     { {  UINT16_C(237), UINT16_C(4662), UINT16_C(2239), UINT16_C(2785) },
       {  UINT16_C(9269), UINT16_C(4261), UINT16_C(1015), UINT16_C(9518) },
       {  UINT16_C(8255), UINT16_C(239), UINT16_C(9693), UINT16_C(5622) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4x3_t r, src, expected;
    src.val[0] = simde_vld1_u16(test_vec[i].src[0]);
    src.val[1] = simde_vld1_u16(test_vec[i].src[1]);
    src.val[2] = simde_vld1_u16(test_vec[i].src[2]);

    SIMDE_CONSTIFY_4_(simde_vld3_lane_u16, r, (HEDLEY_UNREACHABLE(), r), i, test_vec[i].buf, src);

    expected.val[0] = simde_vld1_u16(test_vec[i].r[0]);
    expected.val[1] = simde_vld1_u16(test_vec[i].r[1]);
    expected.val[2] = simde_vld1_u16(test_vec[i].r[2]);

    simde_test_arm_neon_assert_equal_u16x4(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_u16x4(r.val[1], expected.val[1]);
    simde_test_arm_neon_assert_equal_u16x4(r.val[2], expected.val[2]);
  }

  return 0;
}

static int
test_simde_vld3_lane_u32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    uint32_t src[3][2];
    uint32_t buf[3];
    uint32_t r[3][2];
  } test_vec[] = {
   { { {  UINT32_C(649331), UINT32_C(837601) },
       {  UINT32_C(485878), UINT32_C(933696) },
       {  UINT32_C(256110), UINT32_C(394676) } },
       {  UINT32_C(547466), UINT32_C(729971), UINT32_C(327258)},
     { {  UINT32_C(547466), UINT32_C(837601) },
       {  UINT32_C(729971), UINT32_C(933696) },
       {  UINT32_C(327258), UINT32_C(394676) } } },
   { { {  UINT32_C(296079), UINT32_C(480957) },
       {  UINT32_C(878808), UINT32_C(469556) },
       {  UINT32_C(544354), UINT32_C(170596) } },
       {  UINT32_C(663329), UINT32_C(622760), UINT32_C(266353)},
     { {  UINT32_C(296079), UINT32_C(663329) },
       {  UINT32_C(878808), UINT32_C(622760) },
       {  UINT32_C(544354), UINT32_C(266353) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2x3_t r, src, expected;
    src.val[0] = simde_vld1_u32(test_vec[i].src[0]);
    src.val[1] = simde_vld1_u32(test_vec[i].src[1]);
    src.val[2] = simde_vld1_u32(test_vec[i].src[2]);

    SIMDE_CONSTIFY_2_(simde_vld3_lane_u32, r, (HEDLEY_UNREACHABLE(), r), i, test_vec[i].buf, src);

    expected.val[0] = simde_vld1_u32(test_vec[i].r[0]);
    expected.val[1] = simde_vld1_u32(test_vec[i].r[1]);
    expected.val[2] = simde_vld1_u32(test_vec[i].r[2]);

    simde_test_arm_neon_assert_equal_u32x2(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_u32x2(r.val[1], expected.val[1]);
    simde_test_arm_neon_assert_equal_u32x2(r.val[2], expected.val[2]);
  }

  return 0;
}

static int
test_simde_vld3_lane_u64 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    uint64_t src[3][1];
    uint64_t buf[3];
    uint64_t r[3][1];
  } test_vec[] = {
   { { {  UINT64_C(54243463) },
       {  UINT64_C(32138549) },
       {  UINT64_C(65147451) } },
       {  UINT64_C(36001229), UINT64_C(4492888), UINT64_C(79288036)},
     { {  UINT64_C(36001229) },
       {  UINT64_C(4492888) },
       {  UINT64_C(79288036) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x1x3_t r, src, expected;
    src.val[0] = simde_vld1_u64(test_vec[i].src[0]);
    src.val[1] = simde_vld1_u64(test_vec[i].src[1]);
    src.val[2] = simde_vld1_u64(test_vec[i].src[2]);

    r = simde_vld3_lane_u64(test_vec[i].buf, src, 0);

    expected.val[0] = simde_vld1_u64(test_vec[i].r[0]);
    expected.val[1] = simde_vld1_u64(test_vec[i].r[1]);
    expected.val[2] = simde_vld1_u64(test_vec[i].r[2]);

    simde_test_arm_neon_assert_equal_u64x1(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_u64x1(r.val[1], expected.val[1]);
    simde_test_arm_neon_assert_equal_u64x1(r.val[2], expected.val[2]);
  }

  return 0;
}

static int
test_simde_vld3_lane_f16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float16_t src[3][4];
    simde_float16_t buf[3];
    simde_float16_t r[3][4];
  } test_vec[] = {
   { { {  SIMDE_FLOAT16_VALUE(-38.09), SIMDE_FLOAT16_VALUE(39.56), SIMDE_FLOAT16_VALUE(12.85), SIMDE_FLOAT16_VALUE(-6.63) },
       {  SIMDE_FLOAT16_VALUE(-41.59), SIMDE_FLOAT16_VALUE(46.59), SIMDE_FLOAT16_VALUE(22.79), SIMDE_FLOAT16_VALUE(-13.35) },
       {  SIMDE_FLOAT16_VALUE(25.23), SIMDE_FLOAT16_VALUE(-26.59), SIMDE_FLOAT16_VALUE(19.00), SIMDE_FLOAT16_VALUE(-16.99) } },
       {  SIMDE_FLOAT16_VALUE(6.58), SIMDE_FLOAT16_VALUE(-23.21), SIMDE_FLOAT16_VALUE(-16.75)},
     { {  SIMDE_FLOAT16_VALUE(6.58), SIMDE_FLOAT16_VALUE(39.56), SIMDE_FLOAT16_VALUE(12.85), SIMDE_FLOAT16_VALUE(-6.63) },
       {  SIMDE_FLOAT16_VALUE(-23.21), SIMDE_FLOAT16_VALUE(46.59), SIMDE_FLOAT16_VALUE(22.79), SIMDE_FLOAT16_VALUE(-13.35) },
       {  SIMDE_FLOAT16_VALUE(-16.75), SIMDE_FLOAT16_VALUE(-26.59), SIMDE_FLOAT16_VALUE(19.00), SIMDE_FLOAT16_VALUE(-16.99) } } },
   { { {  SIMDE_FLOAT16_VALUE(-31.46), SIMDE_FLOAT16_VALUE(30.50), SIMDE_FLOAT16_VALUE(-31.78), SIMDE_FLOAT16_VALUE(47.74) },
       {  SIMDE_FLOAT16_VALUE(33.97), SIMDE_FLOAT16_VALUE(37.16), SIMDE_FLOAT16_VALUE(27.13), SIMDE_FLOAT16_VALUE(-28.58) },
       {  SIMDE_FLOAT16_VALUE(-7.95), SIMDE_FLOAT16_VALUE(-26.73), SIMDE_FLOAT16_VALUE(17.08), SIMDE_FLOAT16_VALUE(39.81) } },
       {  SIMDE_FLOAT16_VALUE(-28.19), SIMDE_FLOAT16_VALUE(29.28), SIMDE_FLOAT16_VALUE(-1.21)},
     { {  SIMDE_FLOAT16_VALUE(-31.46), SIMDE_FLOAT16_VALUE(-28.19), SIMDE_FLOAT16_VALUE(-31.78), SIMDE_FLOAT16_VALUE(47.74) },
       {  SIMDE_FLOAT16_VALUE(33.97), SIMDE_FLOAT16_VALUE(29.28), SIMDE_FLOAT16_VALUE(27.13), SIMDE_FLOAT16_VALUE(-28.58) },
       {  SIMDE_FLOAT16_VALUE(-7.95), SIMDE_FLOAT16_VALUE(-1.21), SIMDE_FLOAT16_VALUE(17.08), SIMDE_FLOAT16_VALUE(39.81) } } },
   { { {  SIMDE_FLOAT16_VALUE(42.99), SIMDE_FLOAT16_VALUE(-22.57), SIMDE_FLOAT16_VALUE(-7.51), SIMDE_FLOAT16_VALUE(-37.37) },
       {  SIMDE_FLOAT16_VALUE(15.49), SIMDE_FLOAT16_VALUE(-14.01), SIMDE_FLOAT16_VALUE(30.43), SIMDE_FLOAT16_VALUE(-22.10) },
       {  SIMDE_FLOAT16_VALUE(-17.08), SIMDE_FLOAT16_VALUE(28.40), SIMDE_FLOAT16_VALUE(-3.15), SIMDE_FLOAT16_VALUE(-9.72) } },
       {  SIMDE_FLOAT16_VALUE(37.03), SIMDE_FLOAT16_VALUE(-46.18), SIMDE_FLOAT16_VALUE(30.55)},
     { {  SIMDE_FLOAT16_VALUE(42.99), SIMDE_FLOAT16_VALUE(-22.57), SIMDE_FLOAT16_VALUE(37.03), SIMDE_FLOAT16_VALUE(-37.37) },
       {  SIMDE_FLOAT16_VALUE(15.49), SIMDE_FLOAT16_VALUE(-14.01), SIMDE_FLOAT16_VALUE(-46.18), SIMDE_FLOAT16_VALUE(-22.10) },
       {  SIMDE_FLOAT16_VALUE(-17.08), SIMDE_FLOAT16_VALUE(28.40), SIMDE_FLOAT16_VALUE(30.55), SIMDE_FLOAT16_VALUE(-9.72) } } },
   { { {  SIMDE_FLOAT16_VALUE(-27.48), SIMDE_FLOAT16_VALUE(13.58), SIMDE_FLOAT16_VALUE(-24.04), SIMDE_FLOAT16_VALUE(4.66) },
       {  SIMDE_FLOAT16_VALUE(29.23), SIMDE_FLOAT16_VALUE(31.79), SIMDE_FLOAT16_VALUE(-45.75), SIMDE_FLOAT16_VALUE(38.47) },
       {  SIMDE_FLOAT16_VALUE(-41.39), SIMDE_FLOAT16_VALUE(-33.55), SIMDE_FLOAT16_VALUE(-46.68), SIMDE_FLOAT16_VALUE(19.26) } },
       {  SIMDE_FLOAT16_VALUE(39.57), SIMDE_FLOAT16_VALUE(-22.13), SIMDE_FLOAT16_VALUE(6.04)},
     { {  SIMDE_FLOAT16_VALUE(-27.48), SIMDE_FLOAT16_VALUE(13.58), SIMDE_FLOAT16_VALUE(-24.04), SIMDE_FLOAT16_VALUE(39.57) },
       {  SIMDE_FLOAT16_VALUE(29.23), SIMDE_FLOAT16_VALUE(31.79), SIMDE_FLOAT16_VALUE(-45.75), SIMDE_FLOAT16_VALUE(-22.13) },
       {  SIMDE_FLOAT16_VALUE(-41.39), SIMDE_FLOAT16_VALUE(-33.55), SIMDE_FLOAT16_VALUE(-46.68), SIMDE_FLOAT16_VALUE(6.04) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x4x3_t r, src, expected;
    src.val[0] = simde_vld1_f16(test_vec[i].src[0]);
    src.val[1] = simde_vld1_f16(test_vec[i].src[1]);
    src.val[2] = simde_vld1_f16(test_vec[i].src[2]);

    SIMDE_CONSTIFY_4_(simde_vld3_lane_f16, r, (HEDLEY_UNREACHABLE(), r), i, test_vec[i].buf, src);

    expected.val[0] = simde_vld1_f16(test_vec[i].r[0]);
    expected.val[1] = simde_vld1_f16(test_vec[i].r[1]);
    expected.val[2] = simde_vld1_f16(test_vec[i].r[2]);

    simde_test_arm_neon_assert_equal_f16x4(r.val[0], expected.val[0], INT_MAX);
    simde_test_arm_neon_assert_equal_f16x4(r.val[1], expected.val[1], INT_MAX);
    simde_test_arm_neon_assert_equal_f16x4(r.val[2], expected.val[2], INT_MAX);
  }

  return 0;
}

static int
test_simde_vld3_lane_f32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    simde_float32_t src[3][2];
    simde_float32_t buf[3];
    simde_float32_t r[3][2];
  } test_vec[] = {
   { { {  SIMDE_FLOAT32_C(-3815.63), SIMDE_FLOAT32_C(-1707.02) },
       {  SIMDE_FLOAT32_C(1574.07), SIMDE_FLOAT32_C(887.99) },
       {  SIMDE_FLOAT32_C(2512.31), SIMDE_FLOAT32_C(4889.59) } },
       {  SIMDE_FLOAT32_C(-215.06), SIMDE_FLOAT32_C(-3372.22), SIMDE_FLOAT32_C(-242.19)},
     { {  SIMDE_FLOAT32_C(-215.06), SIMDE_FLOAT32_C(-1707.02) },
       {  SIMDE_FLOAT32_C(-3372.22), SIMDE_FLOAT32_C(887.99) },
       {  SIMDE_FLOAT32_C(-242.19), SIMDE_FLOAT32_C(4889.59) } } },
   { { {  SIMDE_FLOAT32_C(-514.65), SIMDE_FLOAT32_C(3958.55) },
       {  SIMDE_FLOAT32_C(-1426.95), SIMDE_FLOAT32_C(1871.07) },
       {  SIMDE_FLOAT32_C(-3767.33), SIMDE_FLOAT32_C(2972.99) } },
       {  SIMDE_FLOAT32_C(-2565.02), SIMDE_FLOAT32_C(-4895.28), SIMDE_FLOAT32_C(2142.44)},
     { {  SIMDE_FLOAT32_C(-514.65), SIMDE_FLOAT32_C(-2565.02) },
       {  SIMDE_FLOAT32_C(-1426.95), SIMDE_FLOAT32_C(-4895.28) },
       {  SIMDE_FLOAT32_C(-3767.33), SIMDE_FLOAT32_C(2142.44) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2x3_t r, src, expected;
    src.val[0] = simde_vld1_f32(test_vec[i].src[0]);
    src.val[1] = simde_vld1_f32(test_vec[i].src[1]);
    src.val[2] = simde_vld1_f32(test_vec[i].src[2]);

    SIMDE_CONSTIFY_2_(simde_vld3_lane_f32, r, (HEDLEY_UNREACHABLE(), r), i, test_vec[i].buf, src);

    expected.val[0] = simde_vld1_f32(test_vec[i].r[0]);
    expected.val[1] = simde_vld1_f32(test_vec[i].r[1]);
    expected.val[2] = simde_vld1_f32(test_vec[i].r[2]);

    simde_test_arm_neon_assert_equal_f32x2(r.val[0], expected.val[0], INT_MAX);
    simde_test_arm_neon_assert_equal_f32x2(r.val[1], expected.val[1], INT_MAX);
    simde_test_arm_neon_assert_equal_f32x2(r.val[2], expected.val[2], INT_MAX);
  }

  return 0;
}

static int
test_simde_vld3_lane_f64 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    simde_float64_t src[3][1];
    simde_float64_t buf[3];
    simde_float64_t r[3][1];
  } test_vec[] = {
   { { {  SIMDE_FLOAT64_C(-227977.76) },
       {  SIMDE_FLOAT64_C(-358189.91) },
       {  SIMDE_FLOAT64_C(329725.67) } },
       {  SIMDE_FLOAT64_C(-308263.36), SIMDE_FLOAT64_C(134133.66), SIMDE_FLOAT64_C(344837.21)},
     { {  SIMDE_FLOAT64_C(-308263.36) },
       {  SIMDE_FLOAT64_C(134133.66) },
       {  SIMDE_FLOAT64_C(344837.21) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x1x3_t r, src, expected;
    src.val[0] = simde_vld1_f64(test_vec[i].src[0]);
    src.val[1] = simde_vld1_f64(test_vec[i].src[1]);
    src.val[2] = simde_vld1_f64(test_vec[i].src[2]);

    r = simde_vld3_lane_f64(test_vec[i].buf, src, 0);

    expected.val[0] = simde_vld1_f64(test_vec[i].r[0]);
    expected.val[1] = simde_vld1_f64(test_vec[i].r[1]);
    expected.val[2] = simde_vld1_f64(test_vec[i].r[2]);

    simde_test_arm_neon_assert_equal_f64x1(r.val[0], expected.val[0], INT_MAX);
    simde_test_arm_neon_assert_equal_f64x1(r.val[1], expected.val[1], INT_MAX);
    simde_test_arm_neon_assert_equal_f64x1(r.val[2], expected.val[2], INT_MAX);
  }

  return 0;
}

static int
test_simde_vld3q_lane_s8 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int8_t src[3][16];
    int8_t buf[3];
    int8_t r[3][16];
  } test_vec[] = {
   { { {  -INT8_C(28), -INT8_C(13), -INT8_C(35), INT8_C(39), -INT8_C(35), INT8_C(35), -INT8_C(17), INT8_C(11),
        INT8_C(40), -INT8_C(11), -INT8_C(11), INT8_C(24), INT8_C(42), INT8_C(33), INT8_C(15), -INT8_C(30) },
       {  -INT8_C(10), -INT8_C(12), INT8_C(18), -INT8_C(9), INT8_C(27), -INT8_C(30), -INT8_C(28), INT8_C(43),
        INT8_C(13), -INT8_C(3), INT8_C(33), INT8_C(34), INT8_C(27), INT8_C(9), -INT8_C(23), INT8_C(48) },
       {  -INT8_C(7), -INT8_C(13), INT8_C(19), INT8_C(4), INT8_C(17), -INT8_C(17), -INT8_C(10), -INT8_C(24),
        INT8_C(6), INT8_C(1), INT8_C(22), -INT8_C(47), -INT8_C(47), INT8_C(0), INT8_C(13), INT8_C(5) } },
       {  -INT8_C(31), -INT8_C(4), INT8_C(11)},
     { {  -INT8_C(31), -INT8_C(13), -INT8_C(35), INT8_C(39), -INT8_C(35), INT8_C(35), -INT8_C(17), INT8_C(11),
        INT8_C(40), -INT8_C(11), -INT8_C(11), INT8_C(24), INT8_C(42), INT8_C(33), INT8_C(15), -INT8_C(30) },
       {  -INT8_C(4), -INT8_C(12), INT8_C(18), -INT8_C(9), INT8_C(27), -INT8_C(30), -INT8_C(28), INT8_C(43),
        INT8_C(13), -INT8_C(3), INT8_C(33), INT8_C(34), INT8_C(27), INT8_C(9), -INT8_C(23), INT8_C(48) },
       {  INT8_C(11), -INT8_C(13), INT8_C(19), INT8_C(4), INT8_C(17), -INT8_C(17), -INT8_C(10), -INT8_C(24),
        INT8_C(6), INT8_C(1), INT8_C(22), -INT8_C(47), -INT8_C(47), INT8_C(0), INT8_C(13), INT8_C(5) } } },
   { { {  -INT8_C(30), INT8_C(25), -INT8_C(8), -INT8_C(18), INT8_C(19), INT8_C(15), INT8_C(31), -INT8_C(19),
        -INT8_C(2), -INT8_C(45), INT8_C(24), -INT8_C(25), -INT8_C(20), INT8_C(34), INT8_C(37), INT8_C(38) },
       {  INT8_C(2), -INT8_C(4), -INT8_C(49), INT8_C(44), -INT8_C(26), INT8_C(24), -INT8_C(40), INT8_C(3),
        -INT8_C(38), INT8_C(5), INT8_C(45), -INT8_C(4), -INT8_C(21), -INT8_C(40), INT8_C(49), -INT8_C(33) },
       {  -INT8_C(42), INT8_C(29), -INT8_C(24), INT8_C(16), INT8_C(25), INT8_C(4), INT8_C(13), -INT8_C(24),
        INT8_C(10), -INT8_C(25), INT8_C(13), -INT8_C(3), INT8_C(36), -INT8_C(44), -INT8_C(1), -INT8_C(33) } },
       {  INT8_C(46), INT8_C(42), -INT8_C(17)},
     { {  -INT8_C(30), INT8_C(46), -INT8_C(8), -INT8_C(18), INT8_C(19), INT8_C(15), INT8_C(31), -INT8_C(19),
        -INT8_C(2), -INT8_C(45), INT8_C(24), -INT8_C(25), -INT8_C(20), INT8_C(34), INT8_C(37), INT8_C(38) },
       {  INT8_C(2), INT8_C(42), -INT8_C(49), INT8_C(44), -INT8_C(26), INT8_C(24), -INT8_C(40), INT8_C(3),
        -INT8_C(38), INT8_C(5), INT8_C(45), -INT8_C(4), -INT8_C(21), -INT8_C(40), INT8_C(49), -INT8_C(33) },
       {  -INT8_C(42), -INT8_C(17), -INT8_C(24), INT8_C(16), INT8_C(25), INT8_C(4), INT8_C(13), -INT8_C(24),
        INT8_C(10), -INT8_C(25), INT8_C(13), -INT8_C(3), INT8_C(36), -INT8_C(44), -INT8_C(1), -INT8_C(33) } } },
   { { {  INT8_C(15), -INT8_C(42), -INT8_C(16), INT8_C(46), -INT8_C(23), INT8_C(33), -INT8_C(21), -INT8_C(49),
        INT8_C(5), INT8_C(47), INT8_C(42), INT8_C(19), -INT8_C(24), -INT8_C(13), -INT8_C(36), -INT8_C(34) },
       {  -INT8_C(48), INT8_C(19), INT8_C(41), INT8_C(8), INT8_C(14), -INT8_C(1), -INT8_C(48), INT8_C(31),
        INT8_C(40), -INT8_C(3), INT8_C(9), -INT8_C(21), INT8_C(21), -INT8_C(3), INT8_C(2), -INT8_C(47) },
       {  INT8_C(24), INT8_C(8), -INT8_C(1), INT8_C(37), INT8_C(18), INT8_C(37), -INT8_C(27), INT8_C(40),
        -INT8_C(42), INT8_C(42), -INT8_C(30), INT8_C(0), INT8_C(45), -INT8_C(6), INT8_C(39), INT8_C(45) } },
       {  INT8_C(23), INT8_C(20), -INT8_C(12)},
     { {  INT8_C(15), -INT8_C(42), INT8_C(23), INT8_C(46), -INT8_C(23), INT8_C(33), -INT8_C(21), -INT8_C(49),
        INT8_C(5), INT8_C(47), INT8_C(42), INT8_C(19), -INT8_C(24), -INT8_C(13), -INT8_C(36), -INT8_C(34) },
       {  -INT8_C(48), INT8_C(19), INT8_C(20), INT8_C(8), INT8_C(14), -INT8_C(1), -INT8_C(48), INT8_C(31),
        INT8_C(40), -INT8_C(3), INT8_C(9), -INT8_C(21), INT8_C(21), -INT8_C(3), INT8_C(2), -INT8_C(47) },
       {  INT8_C(24), INT8_C(8), -INT8_C(12), INT8_C(37), INT8_C(18), INT8_C(37), -INT8_C(27), INT8_C(40),
        -INT8_C(42), INT8_C(42), -INT8_C(30), INT8_C(0), INT8_C(45), -INT8_C(6), INT8_C(39), INT8_C(45) } } },
   { { {  -INT8_C(4), INT8_C(24), INT8_C(10), -INT8_C(19), INT8_C(44), INT8_C(1), INT8_C(1), INT8_C(13),
        -INT8_C(19), INT8_C(8), -INT8_C(47), INT8_C(45), INT8_C(21), -INT8_C(16), -INT8_C(46), -INT8_C(32) },
       {  INT8_C(5), INT8_C(10), -INT8_C(16), -INT8_C(23), -INT8_C(15), INT8_C(39), INT8_C(1), INT8_C(48),
        INT8_C(17), -INT8_C(13), INT8_C(35), INT8_C(11), INT8_C(32), INT8_C(15), INT8_C(11), -INT8_C(25) },
       {  -INT8_C(11), INT8_C(29), -INT8_C(23), INT8_C(17), -INT8_C(31), INT8_C(40), INT8_C(34), INT8_C(13),
        INT8_C(11), -INT8_C(48), INT8_C(18), INT8_C(19), -INT8_C(21), INT8_C(31), -INT8_C(42), -INT8_C(14) } },
       {  -INT8_C(26), INT8_C(0), INT8_C(4)},
     { {  -INT8_C(4), INT8_C(24), INT8_C(10), -INT8_C(26), INT8_C(44), INT8_C(1), INT8_C(1), INT8_C(13),
        -INT8_C(19), INT8_C(8), -INT8_C(47), INT8_C(45), INT8_C(21), -INT8_C(16), -INT8_C(46), -INT8_C(32) },
       {  INT8_C(5), INT8_C(10), -INT8_C(16), INT8_C(0), -INT8_C(15), INT8_C(39), INT8_C(1), INT8_C(48),
        INT8_C(17), -INT8_C(13), INT8_C(35), INT8_C(11), INT8_C(32), INT8_C(15), INT8_C(11), -INT8_C(25) },
       {  -INT8_C(11), INT8_C(29), -INT8_C(23), INT8_C(4), -INT8_C(31), INT8_C(40), INT8_C(34), INT8_C(13),
        INT8_C(11), -INT8_C(48), INT8_C(18), INT8_C(19), -INT8_C(21), INT8_C(31), -INT8_C(42), -INT8_C(14) } } },
   { { {  INT8_C(44), INT8_C(25), -INT8_C(6), INT8_C(45), INT8_C(14), -INT8_C(38), -INT8_C(31), INT8_C(21),
        INT8_C(8), INT8_C(36), -INT8_C(2), -INT8_C(13), INT8_C(16), INT8_C(12), -INT8_C(23), INT8_C(34) },
       {  INT8_C(43), INT8_C(24), INT8_C(19), -INT8_C(35), INT8_C(16), INT8_C(10), INT8_C(29), INT8_C(26),
        INT8_C(36), -INT8_C(27), INT8_C(47), INT8_C(32), INT8_C(6), -INT8_C(29), INT8_C(30), -INT8_C(30) },
       {  -INT8_C(5), -INT8_C(41), INT8_C(19), INT8_C(6), INT8_C(10), INT8_C(11), INT8_C(17), INT8_C(24),
        -INT8_C(24), INT8_C(26), INT8_C(35), INT8_C(17), -INT8_C(12), -INT8_C(38), -INT8_C(22), -INT8_C(30) } },
       {  INT8_C(31), -INT8_C(38), INT8_C(8)},
     { {  INT8_C(44), INT8_C(25), -INT8_C(6), INT8_C(45), INT8_C(31), -INT8_C(38), -INT8_C(31), INT8_C(21),
        INT8_C(8), INT8_C(36), -INT8_C(2), -INT8_C(13), INT8_C(16), INT8_C(12), -INT8_C(23), INT8_C(34) },
       {  INT8_C(43), INT8_C(24), INT8_C(19), -INT8_C(35), -INT8_C(38), INT8_C(10), INT8_C(29), INT8_C(26),
        INT8_C(36), -INT8_C(27), INT8_C(47), INT8_C(32), INT8_C(6), -INT8_C(29), INT8_C(30), -INT8_C(30) },
       {  -INT8_C(5), -INT8_C(41), INT8_C(19), INT8_C(6), INT8_C(8), INT8_C(11), INT8_C(17), INT8_C(24),
        -INT8_C(24), INT8_C(26), INT8_C(35), INT8_C(17), -INT8_C(12), -INT8_C(38), -INT8_C(22), -INT8_C(30) } } },
   { { {  -INT8_C(29), -INT8_C(16), INT8_C(26), INT8_C(17), INT8_C(2), -INT8_C(4), INT8_C(3), -INT8_C(28),
        INT8_C(0), INT8_C(15), INT8_C(44), -INT8_C(43), -INT8_C(1), INT8_C(11), -INT8_C(5), INT8_C(2) },
       {  INT8_C(19), -INT8_C(26), -INT8_C(39), INT8_C(43), INT8_C(10), INT8_C(18), -INT8_C(32), INT8_C(42),
        -INT8_C(30), -INT8_C(1), -INT8_C(1), INT8_C(22), -INT8_C(34), -INT8_C(11), -INT8_C(40), INT8_C(47) },
       {  INT8_C(5), INT8_C(36), INT8_C(0), -INT8_C(6), -INT8_C(46), -INT8_C(23), -INT8_C(48), INT8_C(6),
        INT8_C(45), -INT8_C(35), INT8_C(49), INT8_C(19), -INT8_C(32), -INT8_C(32), -INT8_C(44), -INT8_C(5) } },
       {  -INT8_C(45), INT8_C(0), INT8_C(44)},
     { {  -INT8_C(29), -INT8_C(16), INT8_C(26), INT8_C(17), INT8_C(2), -INT8_C(45), INT8_C(3), -INT8_C(28),
        INT8_C(0), INT8_C(15), INT8_C(44), -INT8_C(43), -INT8_C(1), INT8_C(11), -INT8_C(5), INT8_C(2) },
       {  INT8_C(19), -INT8_C(26), -INT8_C(39), INT8_C(43), INT8_C(10), INT8_C(0), -INT8_C(32), INT8_C(42),
        -INT8_C(30), -INT8_C(1), -INT8_C(1), INT8_C(22), -INT8_C(34), -INT8_C(11), -INT8_C(40), INT8_C(47) },
       {  INT8_C(5), INT8_C(36), INT8_C(0), -INT8_C(6), -INT8_C(46), INT8_C(44), -INT8_C(48), INT8_C(6),
        INT8_C(45), -INT8_C(35), INT8_C(49), INT8_C(19), -INT8_C(32), -INT8_C(32), -INT8_C(44), -INT8_C(5) } } },
   { { {  -INT8_C(22), -INT8_C(22), INT8_C(14), INT8_C(5), -INT8_C(3), -INT8_C(5), INT8_C(22), -INT8_C(29),
        -INT8_C(21), -INT8_C(5), INT8_C(21), -INT8_C(5), INT8_C(6), INT8_C(36), INT8_C(29), -INT8_C(23) },
       {  INT8_C(43), -INT8_C(25), INT8_C(21), -INT8_C(25), -INT8_C(18), INT8_C(38), -INT8_C(31), -INT8_C(7),
        INT8_C(25), INT8_C(7), INT8_C(39), -INT8_C(35), -INT8_C(2), INT8_C(22), -INT8_C(46), -INT8_C(7) },
       {  -INT8_C(49), -INT8_C(16), INT8_C(34), INT8_C(43), INT8_C(38), -INT8_C(5), -INT8_C(8), INT8_C(0),
        INT8_C(3), -INT8_C(19), INT8_C(48), INT8_C(42), INT8_C(25), INT8_C(5), INT8_C(25), INT8_C(17) } },
       {  INT8_C(2), INT8_C(43), INT8_C(12)},
     { {  -INT8_C(22), -INT8_C(22), INT8_C(14), INT8_C(5), -INT8_C(3), -INT8_C(5), INT8_C(2), -INT8_C(29),
        -INT8_C(21), -INT8_C(5), INT8_C(21), -INT8_C(5), INT8_C(6), INT8_C(36), INT8_C(29), -INT8_C(23) },
       {  INT8_C(43), -INT8_C(25), INT8_C(21), -INT8_C(25), -INT8_C(18), INT8_C(38), INT8_C(43), -INT8_C(7),
        INT8_C(25), INT8_C(7), INT8_C(39), -INT8_C(35), -INT8_C(2), INT8_C(22), -INT8_C(46), -INT8_C(7) },
       {  -INT8_C(49), -INT8_C(16), INT8_C(34), INT8_C(43), INT8_C(38), -INT8_C(5), INT8_C(12), INT8_C(0),
        INT8_C(3), -INT8_C(19), INT8_C(48), INT8_C(42), INT8_C(25), INT8_C(5), INT8_C(25), INT8_C(17) } } },
   { { {  -INT8_C(24), INT8_C(26), -INT8_C(29), -INT8_C(11), INT8_C(49), -INT8_C(23), -INT8_C(40), -INT8_C(12),
        -INT8_C(26), INT8_C(39), -INT8_C(8), INT8_C(5), INT8_C(11), INT8_C(35), -INT8_C(35), -INT8_C(21) },
       {  INT8_C(43), INT8_C(15), INT8_C(44), -INT8_C(25), -INT8_C(35), -INT8_C(16), -INT8_C(6), INT8_C(6),
        INT8_C(27), -INT8_C(17), -INT8_C(21), INT8_C(22), INT8_C(8), INT8_C(35), INT8_C(10), INT8_C(18) },
       {  -INT8_C(21), INT8_C(7), INT8_C(41), -INT8_C(40), INT8_C(22), -INT8_C(13), -INT8_C(7), -INT8_C(16),
        INT8_C(30), INT8_C(48), INT8_C(10), INT8_C(30), -INT8_C(9), INT8_C(43), -INT8_C(16), INT8_C(39) } },
       {  -INT8_C(4), INT8_C(38), INT8_C(2)},
     { {  -INT8_C(24), INT8_C(26), -INT8_C(29), -INT8_C(11), INT8_C(49), -INT8_C(23), -INT8_C(40), -INT8_C(4),
        -INT8_C(26), INT8_C(39), -INT8_C(8), INT8_C(5), INT8_C(11), INT8_C(35), -INT8_C(35), -INT8_C(21) },
       {  INT8_C(43), INT8_C(15), INT8_C(44), -INT8_C(25), -INT8_C(35), -INT8_C(16), -INT8_C(6), INT8_C(38),
        INT8_C(27), -INT8_C(17), -INT8_C(21), INT8_C(22), INT8_C(8), INT8_C(35), INT8_C(10), INT8_C(18) },
       {  -INT8_C(21), INT8_C(7), INT8_C(41), -INT8_C(40), INT8_C(22), -INT8_C(13), -INT8_C(7), INT8_C(2),
        INT8_C(30), INT8_C(48), INT8_C(10), INT8_C(30), -INT8_C(9), INT8_C(43), -INT8_C(16), INT8_C(39) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16x3_t r, src, expected;
    src.val[0] = simde_vld1q_s8(test_vec[i].src[0]);
    src.val[1] = simde_vld1q_s8(test_vec[i].src[1]);
    src.val[2] = simde_vld1q_s8(test_vec[i].src[2]);

    SIMDE_CONSTIFY_16_(simde_vld3q_lane_s8, r, (HEDLEY_UNREACHABLE(), r), i, test_vec[i].buf, src);

    expected.val[0] = simde_vld1q_s8(test_vec[i].r[0]);
    expected.val[1] = simde_vld1q_s8(test_vec[i].r[1]);
    expected.val[2] = simde_vld1q_s8(test_vec[i].r[2]);

    simde_test_arm_neon_assert_equal_i8x16(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_i8x16(r.val[1], expected.val[1]);
    simde_test_arm_neon_assert_equal_i8x16(r.val[2], expected.val[2]);
  }

  return 0;
}

static int
test_simde_vld3q_lane_s16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int16_t src[3][8];
    int16_t buf[3];
    int16_t r[3][8];
  } test_vec[] = {
   { { {  -INT16_C(2544), -INT16_C(4642), INT16_C(1229), -INT16_C(3331),
        INT16_C(1420), INT16_C(2297), -INT16_C(3685), -INT16_C(1960) },
       {  -INT16_C(1002), -INT16_C(55), INT16_C(253), -INT16_C(3175),
        INT16_C(4758), -INT16_C(663), INT16_C(4619), -INT16_C(514) },
       {  INT16_C(361), INT16_C(2026), INT16_C(1410), -INT16_C(931),
        INT16_C(2343), -INT16_C(2337), INT16_C(1862), -INT16_C(4072) } },
       {  INT16_C(3171), INT16_C(4950), -INT16_C(4704)},
     { {  INT16_C(3171), -INT16_C(4642), INT16_C(1229), -INT16_C(3331),
        INT16_C(1420), INT16_C(2297), -INT16_C(3685), -INT16_C(1960) },
       {  INT16_C(4950), -INT16_C(55), INT16_C(253), -INT16_C(3175),
        INT16_C(4758), -INT16_C(663), INT16_C(4619), -INT16_C(514) },
       {  -INT16_C(4704), INT16_C(2026), INT16_C(1410), -INT16_C(931),
        INT16_C(2343), -INT16_C(2337), INT16_C(1862), -INT16_C(4072) } } },
   { { {  -INT16_C(2056), -INT16_C(2346), INT16_C(48), -INT16_C(1513),
        -INT16_C(1284), -INT16_C(2465), INT16_C(2451), INT16_C(3724) },
       {  -INT16_C(2631), -INT16_C(2352), -INT16_C(4669), -INT16_C(3875),
        -INT16_C(1356), INT16_C(4686), -INT16_C(1134), INT16_C(4680) },
       {  INT16_C(829), -INT16_C(3778), -INT16_C(1514), INT16_C(3181),
        INT16_C(233), -INT16_C(285), -INT16_C(2967), INT16_C(4139) } },
       {  -INT16_C(761), INT16_C(4943), INT16_C(3163)},
     { {  -INT16_C(2056), -INT16_C(761), INT16_C(48), -INT16_C(1513),
        -INT16_C(1284), -INT16_C(2465), INT16_C(2451), INT16_C(3724) },
       {  -INT16_C(2631), INT16_C(4943), -INT16_C(4669), -INT16_C(3875),
        -INT16_C(1356), INT16_C(4686), -INT16_C(1134), INT16_C(4680) },
       {  INT16_C(829), INT16_C(3163), -INT16_C(1514), INT16_C(3181),
        INT16_C(233), -INT16_C(285), -INT16_C(2967), INT16_C(4139) } } },
   { { {  -INT16_C(532), -INT16_C(2343), INT16_C(4528), -INT16_C(3432),
        INT16_C(2221), INT16_C(3807), -INT16_C(1256), -INT16_C(366) },
       {  -INT16_C(3053), -INT16_C(2035), INT16_C(4749), -INT16_C(876),
        -INT16_C(3988), -INT16_C(2478), -INT16_C(160), INT16_C(1331) },
       {  -INT16_C(4671), -INT16_C(1438), INT16_C(756), -INT16_C(652),
        -INT16_C(4517), -INT16_C(1746), INT16_C(849), INT16_C(1421) } },
       {  -INT16_C(1857), INT16_C(1429), -INT16_C(481)},
     { {  -INT16_C(532), -INT16_C(2343), -INT16_C(1857), -INT16_C(3432),
        INT16_C(2221), INT16_C(3807), -INT16_C(1256), -INT16_C(366) },
       {  -INT16_C(3053), -INT16_C(2035), INT16_C(1429), -INT16_C(876),
        -INT16_C(3988), -INT16_C(2478), -INT16_C(160), INT16_C(1331) },
       {  -INT16_C(4671), -INT16_C(1438), -INT16_C(481), -INT16_C(652),
        -INT16_C(4517), -INT16_C(1746), INT16_C(849), INT16_C(1421) } } },
   { { {  -INT16_C(3293), INT16_C(1799), -INT16_C(2614), INT16_C(2645),
        INT16_C(154), INT16_C(1399), INT16_C(894), INT16_C(1463) },
       {  -INT16_C(714), INT16_C(3903), -INT16_C(87), -INT16_C(1409),
        INT16_C(4155), -INT16_C(3942), -INT16_C(3803), -INT16_C(3385) },
       {  INT16_C(3632), -INT16_C(4465), INT16_C(4972), INT16_C(2353),
        -INT16_C(554), -INT16_C(4589), -INT16_C(1038), -INT16_C(3827) } },
       {  INT16_C(795), -INT16_C(3260), -INT16_C(2863)},
     { {  -INT16_C(3293), INT16_C(1799), -INT16_C(2614), INT16_C(795),
        INT16_C(154), INT16_C(1399), INT16_C(894), INT16_C(1463) },
       {  -INT16_C(714), INT16_C(3903), -INT16_C(87), -INT16_C(3260),
        INT16_C(4155), -INT16_C(3942), -INT16_C(3803), -INT16_C(3385) },
       {  INT16_C(3632), -INT16_C(4465), INT16_C(4972), -INT16_C(2863),
        -INT16_C(554), -INT16_C(4589), -INT16_C(1038), -INT16_C(3827) } } },
   { { {  INT16_C(4874), INT16_C(1787), INT16_C(3061), INT16_C(1342),
        -INT16_C(4591), -INT16_C(1421), INT16_C(1230), INT16_C(3115) },
       {  INT16_C(2715), INT16_C(2686), -INT16_C(4982), -INT16_C(4201),
        INT16_C(1874), -INT16_C(349), INT16_C(3167), INT16_C(1853) },
       {  -INT16_C(599), INT16_C(3177), INT16_C(2976), INT16_C(440),
        -INT16_C(4614), INT16_C(3956), -INT16_C(1913), INT16_C(3599) } },
       {  INT16_C(2739), INT16_C(4689), -INT16_C(4528)},
     { {  INT16_C(4874), INT16_C(1787), INT16_C(3061), INT16_C(1342),
        INT16_C(2739), -INT16_C(1421), INT16_C(1230), INT16_C(3115) },
       {  INT16_C(2715), INT16_C(2686), -INT16_C(4982), -INT16_C(4201),
        INT16_C(4689), -INT16_C(349), INT16_C(3167), INT16_C(1853) },
       {  -INT16_C(599), INT16_C(3177), INT16_C(2976), INT16_C(440),
        -INT16_C(4528), INT16_C(3956), -INT16_C(1913), INT16_C(3599) } } },
   { { {  INT16_C(2333), -INT16_C(4220), -INT16_C(156), INT16_C(2999),
        -INT16_C(756), INT16_C(1397), INT16_C(3426), INT16_C(1946) },
       {  -INT16_C(377), -INT16_C(773), -INT16_C(181), INT16_C(4655),
        INT16_C(577), INT16_C(2152), INT16_C(1822), INT16_C(1387) },
       {  INT16_C(1673), -INT16_C(1590), INT16_C(2338), -INT16_C(4018),
        INT16_C(3127), INT16_C(1790), INT16_C(444), INT16_C(1571) } },
       {  INT16_C(4725), -INT16_C(3008), INT16_C(3862)},
     { {  INT16_C(2333), -INT16_C(4220), -INT16_C(156), INT16_C(2999),
        -INT16_C(756), INT16_C(4725), INT16_C(3426), INT16_C(1946) },
       {  -INT16_C(377), -INT16_C(773), -INT16_C(181), INT16_C(4655),
        INT16_C(577), -INT16_C(3008), INT16_C(1822), INT16_C(1387) },
       {  INT16_C(1673), -INT16_C(1590), INT16_C(2338), -INT16_C(4018),
        INT16_C(3127), INT16_C(3862), INT16_C(444), INT16_C(1571) } } },
   { { {  -INT16_C(1060), -INT16_C(75), INT16_C(3183), INT16_C(4253),
        -INT16_C(1840), INT16_C(4704), -INT16_C(629), INT16_C(3253) },
       {  -INT16_C(34), -INT16_C(4041), -INT16_C(1971), -INT16_C(895),
        INT16_C(1253), -INT16_C(1347), -INT16_C(4546), INT16_C(3931) },
       {  -INT16_C(149), -INT16_C(4817), -INT16_C(2596), -INT16_C(3858),
        INT16_C(2456), -INT16_C(2586), -INT16_C(2889), INT16_C(134) } },
       {  -INT16_C(4708), INT16_C(933), -INT16_C(3647)},
     { {  -INT16_C(1060), -INT16_C(75), INT16_C(3183), INT16_C(4253),
        -INT16_C(1840), INT16_C(4704), -INT16_C(4708), INT16_C(3253) },
       {  -INT16_C(34), -INT16_C(4041), -INT16_C(1971), -INT16_C(895),
        INT16_C(1253), -INT16_C(1347), INT16_C(933), INT16_C(3931) },
       {  -INT16_C(149), -INT16_C(4817), -INT16_C(2596), -INT16_C(3858),
        INT16_C(2456), -INT16_C(2586), -INT16_C(3647), INT16_C(134) } } },
   { { {  INT16_C(3916), -INT16_C(4828), INT16_C(1552), INT16_C(4046),
        -INT16_C(1748), INT16_C(4595), -INT16_C(3476), -INT16_C(3084) },
       {  INT16_C(3756), -INT16_C(3946), INT16_C(4017), -INT16_C(676),
        INT16_C(2556), INT16_C(1106), INT16_C(2577), INT16_C(782) },
       {  -INT16_C(2936), -INT16_C(4886), -INT16_C(4608), -INT16_C(46),
        INT16_C(2459), INT16_C(348), INT16_C(3567), INT16_C(1859) } },
       {  -INT16_C(521), INT16_C(4002), -INT16_C(2389)},
     { {  INT16_C(3916), -INT16_C(4828), INT16_C(1552), INT16_C(4046),
        -INT16_C(1748), INT16_C(4595), -INT16_C(3476), -INT16_C(521) },
       {  INT16_C(3756), -INT16_C(3946), INT16_C(4017), -INT16_C(676),
        INT16_C(2556), INT16_C(1106), INT16_C(2577), INT16_C(4002) },
       {  -INT16_C(2936), -INT16_C(4886), -INT16_C(4608), -INT16_C(46),
        INT16_C(2459), INT16_C(348), INT16_C(3567), -INT16_C(2389) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8x3_t r, src, expected;
    src.val[0] = simde_vld1q_s16(test_vec[i].src[0]);
    src.val[1] = simde_vld1q_s16(test_vec[i].src[1]);
    src.val[2] = simde_vld1q_s16(test_vec[i].src[2]);

    SIMDE_CONSTIFY_8_(simde_vld3q_lane_s16, r, (HEDLEY_UNREACHABLE(), r), i, test_vec[i].buf, src);

    expected.val[0] = simde_vld1q_s16(test_vec[i].r[0]);
    expected.val[1] = simde_vld1q_s16(test_vec[i].r[1]);
    expected.val[2] = simde_vld1q_s16(test_vec[i].r[2]);

    simde_test_arm_neon_assert_equal_i16x8(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_i16x8(r.val[1], expected.val[1]);
    simde_test_arm_neon_assert_equal_i16x8(r.val[2], expected.val[2]);
  }

  return 0;
}

static int
test_simde_vld3q_lane_s32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int32_t src[3][4];
    int32_t buf[3];
    int32_t r[3][4];
  } test_vec[] = {
   { { {  -INT32_C(274313), INT32_C(237242), -INT32_C(282304), INT32_C(204638) },
       {  -INT32_C(80161), INT32_C(113801), INT32_C(414489), INT32_C(260239) },
       {  INT32_C(164558), INT32_C(347080), INT32_C(456851), -INT32_C(190728) } },
       {  -INT32_C(339723), INT32_C(150385), INT32_C(492259)},
     { {  -INT32_C(339723), INT32_C(237242), -INT32_C(282304), INT32_C(204638) },
       {  INT32_C(150385), INT32_C(113801), INT32_C(414489), INT32_C(260239) },
       {  INT32_C(492259), INT32_C(347080), INT32_C(456851), -INT32_C(190728) } } },
   { { {  -INT32_C(255470), -INT32_C(494394), -INT32_C(176874), -INT32_C(178296) },
       {  -INT32_C(495850), INT32_C(428070), -INT32_C(145411), INT32_C(161255) },
       {  INT32_C(169), -INT32_C(335586), INT32_C(344582), INT32_C(177465) } },
       {  -INT32_C(76592), INT32_C(117895), -INT32_C(41174)},
     { {  -INT32_C(255470), -INT32_C(76592), -INT32_C(176874), -INT32_C(178296) },
       {  -INT32_C(495850), INT32_C(117895), -INT32_C(145411), INT32_C(161255) },
       {  INT32_C(169), -INT32_C(41174), INT32_C(344582), INT32_C(177465) } } },
   { { {  INT32_C(8460), -INT32_C(282882), INT32_C(334033), -INT32_C(249990) },
       {  -INT32_C(299308), INT32_C(281874), -INT32_C(265183), INT32_C(45063) },
       {  INT32_C(414608), INT32_C(338741), -INT32_C(193727), -INT32_C(266929) } },
       {  INT32_C(94121), INT32_C(392450), INT32_C(344631)},
     { {  INT32_C(8460), -INT32_C(282882), INT32_C(94121), -INT32_C(249990) },
       {  -INT32_C(299308), INT32_C(281874), INT32_C(392450), INT32_C(45063) },
       {  INT32_C(414608), INT32_C(338741), INT32_C(344631), -INT32_C(266929) } } },
   { { {  -INT32_C(358516), -INT32_C(140139), INT32_C(6751), INT32_C(99765) },
       {  INT32_C(264528), INT32_C(267803), INT32_C(261941), INT32_C(401620) },
       {  -INT32_C(63290), INT32_C(145380), INT32_C(381541), -INT32_C(1568) } },
       {  -INT32_C(327720), INT32_C(173528), INT32_C(6300)},
     { {  -INT32_C(358516), -INT32_C(140139), INT32_C(6751), -INT32_C(327720) },
       {  INT32_C(264528), INT32_C(267803), INT32_C(261941), INT32_C(173528) },
       {  -INT32_C(63290), INT32_C(145380), INT32_C(381541), INT32_C(6300) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4x3_t r, src, expected;
    src.val[0] = simde_vld1q_s32(test_vec[i].src[0]);
    src.val[1] = simde_vld1q_s32(test_vec[i].src[1]);
    src.val[2] = simde_vld1q_s32(test_vec[i].src[2]);

    SIMDE_CONSTIFY_4_(simde_vld3q_lane_s32, r, (HEDLEY_UNREACHABLE(), r), i, test_vec[i].buf, src);

    expected.val[0] = simde_vld1q_s32(test_vec[i].r[0]);
    expected.val[1] = simde_vld1q_s32(test_vec[i].r[1]);
    expected.val[2] = simde_vld1q_s32(test_vec[i].r[2]);

    simde_test_arm_neon_assert_equal_i32x4(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_i32x4(r.val[1], expected.val[1]);
    simde_test_arm_neon_assert_equal_i32x4(r.val[2], expected.val[2]);
  }

  return 0;
}

static int
test_simde_vld3q_lane_s64 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int64_t src[3][2];
    int64_t buf[3];
    int64_t r[3][2];
  } test_vec[] = {
   { { {  INT64_C(46945790), -INT64_C(17840845) },
       {  INT64_C(28832924), INT64_C(18337985) },
       {  INT64_C(31005442), INT64_C(4032821) } },
       {  -INT64_C(17614845), INT64_C(34213434), INT64_C(47541946)},
     { {  -INT64_C(17614845), -INT64_C(17840845) },
       {  INT64_C(34213434), INT64_C(18337985) },
       {  INT64_C(47541946), INT64_C(4032821) } } },
   { { {  INT64_C(19812609), -INT64_C(9082080) },
       {  -INT64_C(48294834), -INT64_C(38787891) },
       {  -INT64_C(12827943), INT64_C(18336010) } },
       {  -INT64_C(35893385), INT64_C(29217445), -INT64_C(9625128)},
     { {  INT64_C(19812609), -INT64_C(35893385) },
       {  -INT64_C(48294834), INT64_C(29217445) },
       {  -INT64_C(12827943), -INT64_C(9625128) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2x3_t r, src, expected;
    src.val[0] = simde_vld1q_s64(test_vec[i].src[0]);
    src.val[1] = simde_vld1q_s64(test_vec[i].src[1]);
    src.val[2] = simde_vld1q_s64(test_vec[i].src[2]);

    SIMDE_CONSTIFY_2_(simde_vld3q_lane_s64, r, (HEDLEY_UNREACHABLE(), r), i, test_vec[i].buf, src);

    expected.val[0] = simde_vld1q_s64(test_vec[i].r[0]);
    expected.val[1] = simde_vld1q_s64(test_vec[i].r[1]);
    expected.val[2] = simde_vld1q_s64(test_vec[i].r[2]);

    simde_test_arm_neon_assert_equal_i64x2(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_i64x2(r.val[1], expected.val[1]);
    simde_test_arm_neon_assert_equal_i64x2(r.val[2], expected.val[2]);
  }

  return 0;
}

static int
test_simde_vld3q_lane_u8 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    uint8_t src[3][16];
    uint8_t buf[3];
    uint8_t r[3][16];
  } test_vec[] = {
   { { {  UINT8_C(97), UINT8_C(34), UINT8_C(43), UINT8_C(79), UINT8_C(40), UINT8_C(28), UINT8_C(65), UINT8_C(74),
        UINT8_C(9), UINT8_C(3), UINT8_C(91), UINT8_C(11), UINT8_C(64), UINT8_C(46), UINT8_C(68), UINT8_C(53) },
       {  UINT8_C(42), UINT8_C(29), UINT8_C(58), UINT8_C(95), UINT8_C(50), UINT8_C(75), UINT8_C(26), UINT8_C(66),
        UINT8_C(71), UINT8_C(45), UINT8_C(14), UINT8_C(13), UINT8_C(88), UINT8_C(66), UINT8_C(0), UINT8_C(95) },
       {  UINT8_C(86), UINT8_C(19), UINT8_C(63), UINT8_C(41), UINT8_C(94), UINT8_C(31), UINT8_C(1), UINT8_C(67),
        UINT8_C(85), UINT8_C(10), UINT8_C(21), UINT8_C(61), UINT8_C(99), UINT8_C(54), UINT8_C(88), UINT8_C(96) } },
       {  UINT8_C(74), UINT8_C(52), UINT8_C(78)},
     { {  UINT8_C(74), UINT8_C(34), UINT8_C(43), UINT8_C(79), UINT8_C(40), UINT8_C(28), UINT8_C(65), UINT8_C(74),
        UINT8_C(9), UINT8_C(3), UINT8_C(91), UINT8_C(11), UINT8_C(64), UINT8_C(46), UINT8_C(68), UINT8_C(53) },
       {  UINT8_C(52), UINT8_C(29), UINT8_C(58), UINT8_C(95), UINT8_C(50), UINT8_C(75), UINT8_C(26), UINT8_C(66),
        UINT8_C(71), UINT8_C(45), UINT8_C(14), UINT8_C(13), UINT8_C(88), UINT8_C(66), UINT8_C(0), UINT8_C(95) },
       {  UINT8_C(78), UINT8_C(19), UINT8_C(63), UINT8_C(41), UINT8_C(94), UINT8_C(31), UINT8_C(1), UINT8_C(67),
        UINT8_C(85), UINT8_C(10), UINT8_C(21), UINT8_C(61), UINT8_C(99), UINT8_C(54), UINT8_C(88), UINT8_C(96) } } },
   { { {  UINT8_C(9), UINT8_C(1), UINT8_C(56), UINT8_C(58), UINT8_C(80), UINT8_C(56), UINT8_C(18), UINT8_C(35),
        UINT8_C(9), UINT8_C(71), UINT8_C(43), UINT8_C(36), UINT8_C(32), UINT8_C(11), UINT8_C(67), UINT8_C(53) },
       {  UINT8_C(6), UINT8_C(75), UINT8_C(57), UINT8_C(21), UINT8_C(70), UINT8_C(8), UINT8_C(57), UINT8_C(52),
        UINT8_C(52), UINT8_C(0), UINT8_C(40), UINT8_C(87), UINT8_C(92), UINT8_C(18), UINT8_C(24), UINT8_C(32) },
       {  UINT8_C(33), UINT8_C(9), UINT8_C(18), UINT8_C(75), UINT8_C(35), UINT8_C(76), UINT8_C(99), UINT8_C(66),
        UINT8_C(40), UINT8_C(47), UINT8_C(2), UINT8_C(94), UINT8_C(66), UINT8_C(80), UINT8_C(73), UINT8_C(10) } },
       {  UINT8_C(68), UINT8_C(58), UINT8_C(68)},
     { {  UINT8_C(9), UINT8_C(68), UINT8_C(56), UINT8_C(58), UINT8_C(80), UINT8_C(56), UINT8_C(18), UINT8_C(35),
        UINT8_C(9), UINT8_C(71), UINT8_C(43), UINT8_C(36), UINT8_C(32), UINT8_C(11), UINT8_C(67), UINT8_C(53) },
       {  UINT8_C(6), UINT8_C(58), UINT8_C(57), UINT8_C(21), UINT8_C(70), UINT8_C(8), UINT8_C(57), UINT8_C(52),
        UINT8_C(52), UINT8_C(0), UINT8_C(40), UINT8_C(87), UINT8_C(92), UINT8_C(18), UINT8_C(24), UINT8_C(32) },
       {  UINT8_C(33), UINT8_C(68), UINT8_C(18), UINT8_C(75), UINT8_C(35), UINT8_C(76), UINT8_C(99), UINT8_C(66),
        UINT8_C(40), UINT8_C(47), UINT8_C(2), UINT8_C(94), UINT8_C(66), UINT8_C(80), UINT8_C(73), UINT8_C(10) } } },
   { { {  UINT8_C(50), UINT8_C(10), UINT8_C(1), UINT8_C(90), UINT8_C(50), UINT8_C(47), UINT8_C(86), UINT8_C(81),
        UINT8_C(61), UINT8_C(7), UINT8_C(95), UINT8_C(60), UINT8_C(48), UINT8_C(8), UINT8_C(31), UINT8_C(91) },
       {  UINT8_C(73), UINT8_C(83), UINT8_C(76), UINT8_C(91), UINT8_C(19), UINT8_C(85), UINT8_C(38), UINT8_C(82),
        UINT8_C(27), UINT8_C(82), UINT8_C(46), UINT8_C(65), UINT8_C(68), UINT8_C(68), UINT8_C(33), UINT8_C(1) },
       {  UINT8_C(47), UINT8_C(15), UINT8_C(55), UINT8_C(34), UINT8_C(74), UINT8_C(43), UINT8_C(84), UINT8_C(10),
        UINT8_C(28), UINT8_C(68), UINT8_C(63), UINT8_C(97), UINT8_C(77), UINT8_C(44), UINT8_C(2), UINT8_C(12) } },
       {  UINT8_C(36), UINT8_C(31), UINT8_C(75)},
     { {  UINT8_C(50), UINT8_C(10), UINT8_C(36), UINT8_C(90), UINT8_C(50), UINT8_C(47), UINT8_C(86), UINT8_C(81),
        UINT8_C(61), UINT8_C(7), UINT8_C(95), UINT8_C(60), UINT8_C(48), UINT8_C(8), UINT8_C(31), UINT8_C(91) },
       {  UINT8_C(73), UINT8_C(83), UINT8_C(31), UINT8_C(91), UINT8_C(19), UINT8_C(85), UINT8_C(38), UINT8_C(82),
        UINT8_C(27), UINT8_C(82), UINT8_C(46), UINT8_C(65), UINT8_C(68), UINT8_C(68), UINT8_C(33), UINT8_C(1) },
       {  UINT8_C(47), UINT8_C(15), UINT8_C(75), UINT8_C(34), UINT8_C(74), UINT8_C(43), UINT8_C(84), UINT8_C(10),
        UINT8_C(28), UINT8_C(68), UINT8_C(63), UINT8_C(97), UINT8_C(77), UINT8_C(44), UINT8_C(2), UINT8_C(12) } } },
   { { {  UINT8_C(47), UINT8_C(52), UINT8_C(57), UINT8_C(40), UINT8_C(37), UINT8_C(25), UINT8_C(31), UINT8_C(34),
        UINT8_C(59), UINT8_C(77), UINT8_C(97), UINT8_C(42), UINT8_C(81), UINT8_C(31), UINT8_C(72), UINT8_C(79) },
       {  UINT8_C(34), UINT8_C(27), UINT8_C(19), UINT8_C(64), UINT8_C(15), UINT8_C(17), UINT8_C(15), UINT8_C(47),
        UINT8_C(63), UINT8_C(27), UINT8_C(7), UINT8_C(9), UINT8_C(63), UINT8_C(44), UINT8_C(81), UINT8_C(91) },
       {  UINT8_C(54), UINT8_C(66), UINT8_C(39), UINT8_C(9), UINT8_C(19), UINT8_C(4), UINT8_C(56), UINT8_C(13),
        UINT8_C(45), UINT8_C(91), UINT8_C(74), UINT8_C(85), UINT8_C(70), UINT8_C(79), UINT8_C(65), UINT8_C(66) } },
       {  UINT8_C(92), UINT8_C(78), UINT8_C(33)},
     { {  UINT8_C(47), UINT8_C(52), UINT8_C(57), UINT8_C(92), UINT8_C(37), UINT8_C(25), UINT8_C(31), UINT8_C(34),
        UINT8_C(59), UINT8_C(77), UINT8_C(97), UINT8_C(42), UINT8_C(81), UINT8_C(31), UINT8_C(72), UINT8_C(79) },
       {  UINT8_C(34), UINT8_C(27), UINT8_C(19), UINT8_C(78), UINT8_C(15), UINT8_C(17), UINT8_C(15), UINT8_C(47),
        UINT8_C(63), UINT8_C(27), UINT8_C(7), UINT8_C(9), UINT8_C(63), UINT8_C(44), UINT8_C(81), UINT8_C(91) },
       {  UINT8_C(54), UINT8_C(66), UINT8_C(39), UINT8_C(33), UINT8_C(19), UINT8_C(4), UINT8_C(56), UINT8_C(13),
        UINT8_C(45), UINT8_C(91), UINT8_C(74), UINT8_C(85), UINT8_C(70), UINT8_C(79), UINT8_C(65), UINT8_C(66) } } },
   { { {  UINT8_C(41), UINT8_C(0), UINT8_C(13), UINT8_C(21), UINT8_C(14), UINT8_C(99), UINT8_C(7), UINT8_C(41),
        UINT8_C(65), UINT8_C(42), UINT8_C(70), UINT8_C(7), UINT8_C(31), UINT8_C(6), UINT8_C(57), UINT8_C(25) },
       {  UINT8_C(89), UINT8_C(11), UINT8_C(40), UINT8_C(22), UINT8_C(75), UINT8_C(80), UINT8_C(72), UINT8_C(0),
        UINT8_C(12), UINT8_C(0), UINT8_C(29), UINT8_C(77), UINT8_C(83), UINT8_C(2), UINT8_C(22), UINT8_C(53) },
       {  UINT8_C(82), UINT8_C(8), UINT8_C(33), UINT8_C(81), UINT8_C(96), UINT8_C(37), UINT8_C(91), UINT8_C(76),
        UINT8_C(39), UINT8_C(58), UINT8_C(73), UINT8_C(97), UINT8_C(11), UINT8_C(15), UINT8_C(21), UINT8_C(99) } },
       {  UINT8_C(96), UINT8_C(62), UINT8_C(14)},
     { {  UINT8_C(41), UINT8_C(0), UINT8_C(13), UINT8_C(21), UINT8_C(96), UINT8_C(99), UINT8_C(7), UINT8_C(41),
        UINT8_C(65), UINT8_C(42), UINT8_C(70), UINT8_C(7), UINT8_C(31), UINT8_C(6), UINT8_C(57), UINT8_C(25) },
       {  UINT8_C(89), UINT8_C(11), UINT8_C(40), UINT8_C(22), UINT8_C(62), UINT8_C(80), UINT8_C(72), UINT8_C(0),
        UINT8_C(12), UINT8_C(0), UINT8_C(29), UINT8_C(77), UINT8_C(83), UINT8_C(2), UINT8_C(22), UINT8_C(53) },
       {  UINT8_C(82), UINT8_C(8), UINT8_C(33), UINT8_C(81), UINT8_C(14), UINT8_C(37), UINT8_C(91), UINT8_C(76),
        UINT8_C(39), UINT8_C(58), UINT8_C(73), UINT8_C(97), UINT8_C(11), UINT8_C(15), UINT8_C(21), UINT8_C(99) } } },
   { { {  UINT8_C(20), UINT8_C(41), UINT8_C(29), UINT8_C(44), UINT8_C(67), UINT8_C(37), UINT8_C(87), UINT8_C(42),
        UINT8_C(73), UINT8_C(62), UINT8_C(94), UINT8_C(35), UINT8_C(12), UINT8_C(53), UINT8_C(34), UINT8_C(89) },
       {  UINT8_C(64), UINT8_C(49), UINT8_C(36), UINT8_C(14), UINT8_C(32), UINT8_C(10), UINT8_C(2), UINT8_C(82),
        UINT8_C(64), UINT8_C(73), UINT8_C(51), UINT8_C(96), UINT8_C(23), UINT8_C(75), UINT8_C(27), UINT8_C(25) },
       {  UINT8_C(24), UINT8_C(87), UINT8_C(35), UINT8_C(68), UINT8_C(68), UINT8_C(9), UINT8_C(10), UINT8_C(17),
        UINT8_C(20), UINT8_C(88), UINT8_C(79), UINT8_C(13), UINT8_C(53), UINT8_C(99), UINT8_C(83), UINT8_C(9) } },
       {  UINT8_C(87), UINT8_C(65), UINT8_C(37)},
     { {  UINT8_C(20), UINT8_C(41), UINT8_C(29), UINT8_C(44), UINT8_C(67), UINT8_C(87), UINT8_C(87), UINT8_C(42),
        UINT8_C(73), UINT8_C(62), UINT8_C(94), UINT8_C(35), UINT8_C(12), UINT8_C(53), UINT8_C(34), UINT8_C(89) },
       {  UINT8_C(64), UINT8_C(49), UINT8_C(36), UINT8_C(14), UINT8_C(32), UINT8_C(65), UINT8_C(2), UINT8_C(82),
        UINT8_C(64), UINT8_C(73), UINT8_C(51), UINT8_C(96), UINT8_C(23), UINT8_C(75), UINT8_C(27), UINT8_C(25) },
       {  UINT8_C(24), UINT8_C(87), UINT8_C(35), UINT8_C(68), UINT8_C(68), UINT8_C(37), UINT8_C(10), UINT8_C(17),
        UINT8_C(20), UINT8_C(88), UINT8_C(79), UINT8_C(13), UINT8_C(53), UINT8_C(99), UINT8_C(83), UINT8_C(9) } } },
   { { {  UINT8_C(98), UINT8_C(75), UINT8_C(1), UINT8_C(3), UINT8_C(9), UINT8_C(61), UINT8_C(91), UINT8_C(69),
        UINT8_C(75), UINT8_C(22), UINT8_C(77), UINT8_C(29), UINT8_C(2), UINT8_C(8), UINT8_C(96), UINT8_C(52) },
       {  UINT8_C(35), UINT8_C(65), UINT8_C(32), UINT8_C(16), UINT8_C(62), UINT8_C(3), UINT8_C(91), UINT8_C(38),
        UINT8_C(42), UINT8_C(23), UINT8_C(81), UINT8_C(61), UINT8_C(28), UINT8_C(1), UINT8_C(5), UINT8_C(84) },
       {  UINT8_C(45), UINT8_C(87), UINT8_C(52), UINT8_C(74), UINT8_C(83), UINT8_C(48), UINT8_C(17), UINT8_C(96),
        UINT8_C(48), UINT8_C(82), UINT8_C(56), UINT8_C(23), UINT8_C(23), UINT8_C(52), UINT8_C(69), UINT8_C(57) } },
       {  UINT8_C(89), UINT8_C(29), UINT8_C(27)},
     { {  UINT8_C(98), UINT8_C(75), UINT8_C(1), UINT8_C(3), UINT8_C(9), UINT8_C(61), UINT8_C(89), UINT8_C(69),
        UINT8_C(75), UINT8_C(22), UINT8_C(77), UINT8_C(29), UINT8_C(2), UINT8_C(8), UINT8_C(96), UINT8_C(52) },
       {  UINT8_C(35), UINT8_C(65), UINT8_C(32), UINT8_C(16), UINT8_C(62), UINT8_C(3), UINT8_C(29), UINT8_C(38),
        UINT8_C(42), UINT8_C(23), UINT8_C(81), UINT8_C(61), UINT8_C(28), UINT8_C(1), UINT8_C(5), UINT8_C(84) },
       {  UINT8_C(45), UINT8_C(87), UINT8_C(52), UINT8_C(74), UINT8_C(83), UINT8_C(48), UINT8_C(27), UINT8_C(96),
        UINT8_C(48), UINT8_C(82), UINT8_C(56), UINT8_C(23), UINT8_C(23), UINT8_C(52), UINT8_C(69), UINT8_C(57) } } },
   { { {  UINT8_C(46), UINT8_C(86), UINT8_C(19), UINT8_C(68), UINT8_C(15), UINT8_C(80), UINT8_C(55), UINT8_C(26),
        UINT8_C(13), UINT8_C(91), UINT8_C(5), UINT8_C(36), UINT8_C(91), UINT8_C(27), UINT8_C(80), UINT8_C(74) },
       {  UINT8_C(88), UINT8_C(47), UINT8_C(36), UINT8_C(33), UINT8_C(37), UINT8_C(91), UINT8_C(41), UINT8_C(63),
        UINT8_C(23), UINT8_C(98), UINT8_C(80), UINT8_C(12), UINT8_C(64), UINT8_C(50), UINT8_C(92), UINT8_C(11) },
       {  UINT8_C(99), UINT8_C(57), UINT8_C(22), UINT8_C(30), UINT8_C(57), UINT8_C(84), UINT8_C(43), UINT8_C(39),
        UINT8_C(54), UINT8_C(15), UINT8_C(21), UINT8_C(38), UINT8_C(13), UINT8_C(93), UINT8_C(96), UINT8_C(10) } },
       {  UINT8_C(75), UINT8_C(42), UINT8_C(8)},
     { {  UINT8_C(46), UINT8_C(86), UINT8_C(19), UINT8_C(68), UINT8_C(15), UINT8_C(80), UINT8_C(55), UINT8_C(75),
        UINT8_C(13), UINT8_C(91), UINT8_C(5), UINT8_C(36), UINT8_C(91), UINT8_C(27), UINT8_C(80), UINT8_C(74) },
       {  UINT8_C(88), UINT8_C(47), UINT8_C(36), UINT8_C(33), UINT8_C(37), UINT8_C(91), UINT8_C(41), UINT8_C(42),
        UINT8_C(23), UINT8_C(98), UINT8_C(80), UINT8_C(12), UINT8_C(64), UINT8_C(50), UINT8_C(92), UINT8_C(11) },
       {  UINT8_C(99), UINT8_C(57), UINT8_C(22), UINT8_C(30), UINT8_C(57), UINT8_C(84), UINT8_C(43), UINT8_C(8),
        UINT8_C(54), UINT8_C(15), UINT8_C(21), UINT8_C(38), UINT8_C(13), UINT8_C(93), UINT8_C(96), UINT8_C(10) } } },
   { { {  UINT8_C(24), UINT8_C(21), UINT8_C(44), UINT8_C(24), UINT8_C(42), UINT8_C(32), UINT8_C(52), UINT8_C(88),
        UINT8_C(75), UINT8_C(41), UINT8_C(31), UINT8_C(71), UINT8_C(42), UINT8_C(21), UINT8_C(95), UINT8_C(29) },
       {  UINT8_C(0), UINT8_C(81), UINT8_C(30), UINT8_C(11), UINT8_C(14), UINT8_C(31), UINT8_C(47), UINT8_C(21),
        UINT8_C(76), UINT8_C(47), UINT8_C(72), UINT8_C(10), UINT8_C(59), UINT8_C(86), UINT8_C(58), UINT8_C(86) },
       {  UINT8_C(90), UINT8_C(32), UINT8_C(67), UINT8_C(12), UINT8_C(21), UINT8_C(76), UINT8_C(45), UINT8_C(14),
        UINT8_C(82), UINT8_C(96), UINT8_C(68), UINT8_C(15), UINT8_C(37), UINT8_C(65), UINT8_C(18), UINT8_C(49) } },
       {  UINT8_C(84), UINT8_C(83), UINT8_C(21)},
     { {  UINT8_C(24), UINT8_C(21), UINT8_C(44), UINT8_C(24), UINT8_C(42), UINT8_C(32), UINT8_C(52), UINT8_C(88),
        UINT8_C(84), UINT8_C(41), UINT8_C(31), UINT8_C(71), UINT8_C(42), UINT8_C(21), UINT8_C(95), UINT8_C(29) },
       {  UINT8_C(0), UINT8_C(81), UINT8_C(30), UINT8_C(11), UINT8_C(14), UINT8_C(31), UINT8_C(47), UINT8_C(21),
        UINT8_C(83), UINT8_C(47), UINT8_C(72), UINT8_C(10), UINT8_C(59), UINT8_C(86), UINT8_C(58), UINT8_C(86) },
       {  UINT8_C(90), UINT8_C(32), UINT8_C(67), UINT8_C(12), UINT8_C(21), UINT8_C(76), UINT8_C(45), UINT8_C(14),
        UINT8_C(21), UINT8_C(96), UINT8_C(68), UINT8_C(15), UINT8_C(37), UINT8_C(65), UINT8_C(18), UINT8_C(49) } } },
   { { {  UINT8_C(22), UINT8_C(62), UINT8_C(79), UINT8_C(5), UINT8_C(54), UINT8_C(45), UINT8_C(83), UINT8_C(98),
        UINT8_C(60), UINT8_C(61), UINT8_C(81), UINT8_C(62), UINT8_C(94), UINT8_C(14), UINT8_C(98), UINT8_C(22) },
       {  UINT8_C(78), UINT8_C(87), UINT8_C(48), UINT8_C(29), UINT8_C(52), UINT8_C(86), UINT8_C(71), UINT8_C(13),
        UINT8_C(20), UINT8_C(11), UINT8_C(89), UINT8_C(3), UINT8_C(5), UINT8_C(93), UINT8_C(48), UINT8_C(27) },
       {  UINT8_C(24), UINT8_C(21), UINT8_C(99), UINT8_C(53), UINT8_C(65), UINT8_C(75), UINT8_C(5), UINT8_C(72),
        UINT8_C(8), UINT8_C(35), UINT8_C(7), UINT8_C(49), UINT8_C(6), UINT8_C(75), UINT8_C(51), UINT8_C(60) } },
       {  UINT8_C(20), UINT8_C(32), UINT8_C(53)},
     { {  UINT8_C(22), UINT8_C(62), UINT8_C(79), UINT8_C(5), UINT8_C(54), UINT8_C(45), UINT8_C(83), UINT8_C(98),
        UINT8_C(60), UINT8_C(20), UINT8_C(81), UINT8_C(62), UINT8_C(94), UINT8_C(14), UINT8_C(98), UINT8_C(22) },
       {  UINT8_C(78), UINT8_C(87), UINT8_C(48), UINT8_C(29), UINT8_C(52), UINT8_C(86), UINT8_C(71), UINT8_C(13),
        UINT8_C(20), UINT8_C(32), UINT8_C(89), UINT8_C(3), UINT8_C(5), UINT8_C(93), UINT8_C(48), UINT8_C(27) },
       {  UINT8_C(24), UINT8_C(21), UINT8_C(99), UINT8_C(53), UINT8_C(65), UINT8_C(75), UINT8_C(5), UINT8_C(72),
        UINT8_C(8), UINT8_C(53), UINT8_C(7), UINT8_C(49), UINT8_C(6), UINT8_C(75), UINT8_C(51), UINT8_C(60) } } },
   { { {  UINT8_C(17), UINT8_C(92), UINT8_C(0), UINT8_C(91), UINT8_C(29), UINT8_C(86), UINT8_C(77), UINT8_C(36),
        UINT8_C(8), UINT8_C(86), UINT8_C(69), UINT8_C(6), UINT8_C(35), UINT8_C(48), UINT8_C(92), UINT8_C(63) },
       {  UINT8_C(69), UINT8_C(16), UINT8_C(3), UINT8_C(40), UINT8_C(43), UINT8_C(9), UINT8_C(40), UINT8_C(29),
        UINT8_C(43), UINT8_C(7), UINT8_C(58), UINT8_C(77), UINT8_C(6), UINT8_C(96), UINT8_C(81), UINT8_C(97) },
       {  UINT8_C(45), UINT8_C(34), UINT8_C(19), UINT8_C(92), UINT8_C(4), UINT8_C(72), UINT8_C(78), UINT8_C(30),
        UINT8_C(15), UINT8_C(12), UINT8_C(37), UINT8_C(53), UINT8_C(85), UINT8_C(88), UINT8_C(0), UINT8_C(40) } },
       {  UINT8_C(63), UINT8_C(11), UINT8_C(19)},
     { {  UINT8_C(17), UINT8_C(92), UINT8_C(0), UINT8_C(91), UINT8_C(29), UINT8_C(86), UINT8_C(77), UINT8_C(36),
        UINT8_C(8), UINT8_C(86), UINT8_C(63), UINT8_C(6), UINT8_C(35), UINT8_C(48), UINT8_C(92), UINT8_C(63) },
       {  UINT8_C(69), UINT8_C(16), UINT8_C(3), UINT8_C(40), UINT8_C(43), UINT8_C(9), UINT8_C(40), UINT8_C(29),
        UINT8_C(43), UINT8_C(7), UINT8_C(11), UINT8_C(77), UINT8_C(6), UINT8_C(96), UINT8_C(81), UINT8_C(97) },
       {  UINT8_C(45), UINT8_C(34), UINT8_C(19), UINT8_C(92), UINT8_C(4), UINT8_C(72), UINT8_C(78), UINT8_C(30),
        UINT8_C(15), UINT8_C(12), UINT8_C(19), UINT8_C(53), UINT8_C(85), UINT8_C(88), UINT8_C(0), UINT8_C(40) } } },
   { { {  UINT8_C(97), UINT8_C(65), UINT8_C(44), UINT8_C(86), UINT8_C(8), UINT8_C(17), UINT8_C(68), UINT8_C(90),
        UINT8_C(28), UINT8_C(50), UINT8_C(29), UINT8_C(7), UINT8_C(32), UINT8_C(0), UINT8_C(49), UINT8_C(9) },
       {  UINT8_C(41), UINT8_C(53), UINT8_C(62), UINT8_C(71), UINT8_C(16), UINT8_C(15), UINT8_C(13), UINT8_C(88),
        UINT8_C(68), UINT8_C(9), UINT8_C(29), UINT8_C(6), UINT8_C(22), UINT8_C(32), UINT8_C(28), UINT8_C(73) },
       {  UINT8_C(90), UINT8_C(12), UINT8_C(95), UINT8_C(43), UINT8_C(28), UINT8_C(11), UINT8_C(77), UINT8_C(24),
        UINT8_C(28), UINT8_C(66), UINT8_C(7), UINT8_C(48), UINT8_C(73), UINT8_C(66), UINT8_C(41), UINT8_C(26) } },
       {  UINT8_C(54), UINT8_C(15), UINT8_C(78)},
     { {  UINT8_C(97), UINT8_C(65), UINT8_C(44), UINT8_C(86), UINT8_C(8), UINT8_C(17), UINT8_C(68), UINT8_C(90),
        UINT8_C(28), UINT8_C(50), UINT8_C(29), UINT8_C(54), UINT8_C(32), UINT8_C(0), UINT8_C(49), UINT8_C(9) },
       {  UINT8_C(41), UINT8_C(53), UINT8_C(62), UINT8_C(71), UINT8_C(16), UINT8_C(15), UINT8_C(13), UINT8_C(88),
        UINT8_C(68), UINT8_C(9), UINT8_C(29), UINT8_C(15), UINT8_C(22), UINT8_C(32), UINT8_C(28), UINT8_C(73) },
       {  UINT8_C(90), UINT8_C(12), UINT8_C(95), UINT8_C(43), UINT8_C(28), UINT8_C(11), UINT8_C(77), UINT8_C(24),
        UINT8_C(28), UINT8_C(66), UINT8_C(7), UINT8_C(78), UINT8_C(73), UINT8_C(66), UINT8_C(41), UINT8_C(26) } } },
   { { {  UINT8_C(68), UINT8_C(0), UINT8_C(37), UINT8_C(9), UINT8_C(36), UINT8_C(20), UINT8_C(51), UINT8_C(43),
        UINT8_C(38), UINT8_C(58), UINT8_C(45), UINT8_C(25), UINT8_C(28), UINT8_C(58), UINT8_C(54), UINT8_C(47) },
       {  UINT8_C(95), UINT8_C(96), UINT8_C(83), UINT8_C(40), UINT8_C(74), UINT8_C(12), UINT8_C(25), UINT8_C(32),
        UINT8_C(23), UINT8_C(42), UINT8_C(57), UINT8_C(39), UINT8_C(36), UINT8_C(42), UINT8_C(21), UINT8_C(54) },
       {  UINT8_C(49), UINT8_C(37), UINT8_C(30), UINT8_C(78), UINT8_C(55), UINT8_C(40), UINT8_C(46), UINT8_C(82),
        UINT8_C(55), UINT8_C(76), UINT8_C(19), UINT8_C(6), UINT8_C(60), UINT8_C(52), UINT8_C(70), UINT8_C(78) } },
       {  UINT8_C(39), UINT8_C(16), UINT8_C(18)},
     { {  UINT8_C(68), UINT8_C(0), UINT8_C(37), UINT8_C(9), UINT8_C(36), UINT8_C(20), UINT8_C(51), UINT8_C(43),
        UINT8_C(38), UINT8_C(58), UINT8_C(45), UINT8_C(25), UINT8_C(39), UINT8_C(58), UINT8_C(54), UINT8_C(47) },
       {  UINT8_C(95), UINT8_C(96), UINT8_C(83), UINT8_C(40), UINT8_C(74), UINT8_C(12), UINT8_C(25), UINT8_C(32),
        UINT8_C(23), UINT8_C(42), UINT8_C(57), UINT8_C(39), UINT8_C(16), UINT8_C(42), UINT8_C(21), UINT8_C(54) },
       {  UINT8_C(49), UINT8_C(37), UINT8_C(30), UINT8_C(78), UINT8_C(55), UINT8_C(40), UINT8_C(46), UINT8_C(82),
        UINT8_C(55), UINT8_C(76), UINT8_C(19), UINT8_C(6), UINT8_C(18), UINT8_C(52), UINT8_C(70), UINT8_C(78) } } },
   { { {  UINT8_C(20), UINT8_C(75), UINT8_C(35), UINT8_C(24), UINT8_C(60), UINT8_C(21), UINT8_C(67), UINT8_C(1),
        UINT8_C(23), UINT8_C(57), UINT8_C(40), UINT8_C(31), UINT8_C(71), UINT8_C(21), UINT8_C(41), UINT8_C(71) },
       {  UINT8_C(3), UINT8_C(21), UINT8_C(89), UINT8_C(29), UINT8_C(51), UINT8_C(99), UINT8_C(90), UINT8_C(35),
        UINT8_C(30), UINT8_C(34), UINT8_C(67), UINT8_C(84), UINT8_C(79), UINT8_C(58), UINT8_C(39), UINT8_C(41) },
       {  UINT8_C(0), UINT8_C(68), UINT8_C(73), UINT8_C(59), UINT8_C(44), UINT8_C(83), UINT8_C(41), UINT8_C(72),
        UINT8_C(54), UINT8_C(29), UINT8_C(52), UINT8_C(51), UINT8_C(25), UINT8_C(25), UINT8_C(13), UINT8_C(15) } },
       {  UINT8_C(13), UINT8_C(84), UINT8_C(69)},
     { {  UINT8_C(20), UINT8_C(75), UINT8_C(35), UINT8_C(24), UINT8_C(60), UINT8_C(21), UINT8_C(67), UINT8_C(1),
        UINT8_C(23), UINT8_C(57), UINT8_C(40), UINT8_C(31), UINT8_C(71), UINT8_C(13), UINT8_C(41), UINT8_C(71) },
       {  UINT8_C(3), UINT8_C(21), UINT8_C(89), UINT8_C(29), UINT8_C(51), UINT8_C(99), UINT8_C(90), UINT8_C(35),
        UINT8_C(30), UINT8_C(34), UINT8_C(67), UINT8_C(84), UINT8_C(79), UINT8_C(84), UINT8_C(39), UINT8_C(41) },
       {  UINT8_C(0), UINT8_C(68), UINT8_C(73), UINT8_C(59), UINT8_C(44), UINT8_C(83), UINT8_C(41), UINT8_C(72),
        UINT8_C(54), UINT8_C(29), UINT8_C(52), UINT8_C(51), UINT8_C(25), UINT8_C(69), UINT8_C(13), UINT8_C(15) } } },
   { { {  UINT8_C(78), UINT8_C(80), UINT8_C(8), UINT8_C(85), UINT8_C(17), UINT8_C(53), UINT8_C(88), UINT8_C(87),
        UINT8_C(32), UINT8_C(29), UINT8_C(69), UINT8_C(78), UINT8_C(28), UINT8_C(38), UINT8_C(52), UINT8_C(24) },
       {  UINT8_C(64), UINT8_C(96), UINT8_C(34), UINT8_C(25), UINT8_C(46), UINT8_C(80), UINT8_C(65), UINT8_C(84),
        UINT8_C(71), UINT8_C(36), UINT8_C(9), UINT8_C(67), UINT8_C(75), UINT8_C(57), UINT8_C(24), UINT8_C(69) },
       {  UINT8_C(77), UINT8_C(59), UINT8_C(66), UINT8_C(82), UINT8_C(84), UINT8_C(12), UINT8_C(12), UINT8_C(87),
        UINT8_C(76), UINT8_C(40), UINT8_C(86), UINT8_C(5), UINT8_C(88), UINT8_C(47), UINT8_C(15), UINT8_C(68) } },
       {  UINT8_C(57), UINT8_C(4), UINT8_C(6)},
     { {  UINT8_C(78), UINT8_C(80), UINT8_C(8), UINT8_C(85), UINT8_C(17), UINT8_C(53), UINT8_C(88), UINT8_C(87),
        UINT8_C(32), UINT8_C(29), UINT8_C(69), UINT8_C(78), UINT8_C(28), UINT8_C(38), UINT8_C(57), UINT8_C(24) },
       {  UINT8_C(64), UINT8_C(96), UINT8_C(34), UINT8_C(25), UINT8_C(46), UINT8_C(80), UINT8_C(65), UINT8_C(84),
        UINT8_C(71), UINT8_C(36), UINT8_C(9), UINT8_C(67), UINT8_C(75), UINT8_C(57), UINT8_C(4), UINT8_C(69) },
       {  UINT8_C(77), UINT8_C(59), UINT8_C(66), UINT8_C(82), UINT8_C(84), UINT8_C(12), UINT8_C(12), UINT8_C(87),
        UINT8_C(76), UINT8_C(40), UINT8_C(86), UINT8_C(5), UINT8_C(88), UINT8_C(47), UINT8_C(6), UINT8_C(68) } } },
   { { {  UINT8_C(10), UINT8_C(53), UINT8_C(42), UINT8_C(50), UINT8_C(80), UINT8_C(86), UINT8_C(65), UINT8_C(9),
        UINT8_C(64), UINT8_C(65), UINT8_C(83), UINT8_C(30), UINT8_C(10), UINT8_C(44), UINT8_C(49), UINT8_C(37) },
       {  UINT8_C(31), UINT8_C(51), UINT8_C(22), UINT8_C(60), UINT8_C(49), UINT8_C(93), UINT8_C(32), UINT8_C(99),
        UINT8_C(7), UINT8_C(29), UINT8_C(87), UINT8_C(97), UINT8_C(99), UINT8_C(4), UINT8_C(60), UINT8_C(5) },
       {  UINT8_C(4), UINT8_C(70), UINT8_C(12), UINT8_C(81), UINT8_C(94), UINT8_C(77), UINT8_C(86), UINT8_C(97),
        UINT8_C(2), UINT8_C(78), UINT8_C(86), UINT8_C(4), UINT8_C(45), UINT8_C(33), UINT8_C(66), UINT8_C(9) } },
       {  UINT8_C(6), UINT8_C(72), UINT8_C(66)},
     { {  UINT8_C(10), UINT8_C(53), UINT8_C(42), UINT8_C(50), UINT8_C(80), UINT8_C(86), UINT8_C(65), UINT8_C(9),
        UINT8_C(64), UINT8_C(65), UINT8_C(83), UINT8_C(30), UINT8_C(10), UINT8_C(44), UINT8_C(49), UINT8_C(6) },
       {  UINT8_C(31), UINT8_C(51), UINT8_C(22), UINT8_C(60), UINT8_C(49), UINT8_C(93), UINT8_C(32), UINT8_C(99),
        UINT8_C(7), UINT8_C(29), UINT8_C(87), UINT8_C(97), UINT8_C(99), UINT8_C(4), UINT8_C(60), UINT8_C(72) },
       {  UINT8_C(4), UINT8_C(70), UINT8_C(12), UINT8_C(81), UINT8_C(94), UINT8_C(77), UINT8_C(86), UINT8_C(97),
        UINT8_C(2), UINT8_C(78), UINT8_C(86), UINT8_C(4), UINT8_C(45), UINT8_C(33), UINT8_C(66), UINT8_C(66) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x16x3_t r, src, expected;
    src.val[0] = simde_vld1q_u8(test_vec[i].src[0]);
    src.val[1] = simde_vld1q_u8(test_vec[i].src[1]);
    src.val[2] = simde_vld1q_u8(test_vec[i].src[2]);

    SIMDE_CONSTIFY_16_(simde_vld3q_lane_u8, r, (HEDLEY_UNREACHABLE(), r), i, test_vec[i].buf, src);

    expected.val[0] = simde_vld1q_u8(test_vec[i].r[0]);
    expected.val[1] = simde_vld1q_u8(test_vec[i].r[1]);
    expected.val[2] = simde_vld1q_u8(test_vec[i].r[2]);

    simde_test_arm_neon_assert_equal_u8x16(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_u8x16(r.val[1], expected.val[1]);
    simde_test_arm_neon_assert_equal_u8x16(r.val[2], expected.val[2]);
  }

  return 0;
}

static int
test_simde_vld3q_lane_u16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    uint16_t src[3][8];
    uint16_t buf[3];
    uint16_t r[3][8];
  } test_vec[] = {
   { { {  UINT16_C(2878), UINT16_C(9122), UINT16_C(7556), UINT16_C(7857),
        UINT16_C(958), UINT16_C(7812), UINT16_C(2259), UINT16_C(582) },
       {  UINT16_C(5578), UINT16_C(9333), UINT16_C(1655), UINT16_C(9009),
        UINT16_C(596), UINT16_C(8223), UINT16_C(5654), UINT16_C(3297) },
       {  UINT16_C(5817), UINT16_C(7331), UINT16_C(8798), UINT16_C(172),
        UINT16_C(1106), UINT16_C(371), UINT16_C(9285), UINT16_C(5940) } },
       {  UINT16_C(9267), UINT16_C(2616), UINT16_C(7110)},
     { {  UINT16_C(9267), UINT16_C(9122), UINT16_C(7556), UINT16_C(7857),
        UINT16_C(958), UINT16_C(7812), UINT16_C(2259), UINT16_C(582) },
       {  UINT16_C(2616), UINT16_C(9333), UINT16_C(1655), UINT16_C(9009),
        UINT16_C(596), UINT16_C(8223), UINT16_C(5654), UINT16_C(3297) },
       {  UINT16_C(7110), UINT16_C(7331), UINT16_C(8798), UINT16_C(172),
        UINT16_C(1106), UINT16_C(371), UINT16_C(9285), UINT16_C(5940) } } },
   { { {  UINT16_C(2435), UINT16_C(4626), UINT16_C(4142), UINT16_C(3387),
        UINT16_C(6479), UINT16_C(7643), UINT16_C(5193), UINT16_C(3942) },
       {  UINT16_C(3016), UINT16_C(1407), UINT16_C(8271), UINT16_C(4950),
        UINT16_C(1775), UINT16_C(4681), UINT16_C(737), UINT16_C(7429) },
       {  UINT16_C(7279), UINT16_C(9658), UINT16_C(8142), UINT16_C(2112),
        UINT16_C(4555), UINT16_C(469), UINT16_C(1007), UINT16_C(2148) } },
       {  UINT16_C(4650), UINT16_C(9800), UINT16_C(2863)},
     { {  UINT16_C(2435), UINT16_C(4650), UINT16_C(4142), UINT16_C(3387),
        UINT16_C(6479), UINT16_C(7643), UINT16_C(5193), UINT16_C(3942) },
       {  UINT16_C(3016), UINT16_C(9800), UINT16_C(8271), UINT16_C(4950),
        UINT16_C(1775), UINT16_C(4681), UINT16_C(737), UINT16_C(7429) },
       {  UINT16_C(7279), UINT16_C(2863), UINT16_C(8142), UINT16_C(2112),
        UINT16_C(4555), UINT16_C(469), UINT16_C(1007), UINT16_C(2148) } } },
   { { {  UINT16_C(3842), UINT16_C(9560), UINT16_C(4451), UINT16_C(3039),
        UINT16_C(1396), UINT16_C(7094), UINT16_C(9151), UINT16_C(328) },
       {  UINT16_C(3222), UINT16_C(3639), UINT16_C(4981), UINT16_C(4084),
        UINT16_C(4213), UINT16_C(6807), UINT16_C(5985), UINT16_C(3640) },
       {  UINT16_C(5867), UINT16_C(7377), UINT16_C(7519), UINT16_C(4002),
        UINT16_C(4302), UINT16_C(897), UINT16_C(4387), UINT16_C(6837) } },
       {  UINT16_C(5729), UINT16_C(6854), UINT16_C(829)},
     { {  UINT16_C(3842), UINT16_C(9560), UINT16_C(5729), UINT16_C(3039),
        UINT16_C(1396), UINT16_C(7094), UINT16_C(9151), UINT16_C(328) },
       {  UINT16_C(3222), UINT16_C(3639), UINT16_C(6854), UINT16_C(4084),
        UINT16_C(4213), UINT16_C(6807), UINT16_C(5985), UINT16_C(3640) },
       {  UINT16_C(5867), UINT16_C(7377), UINT16_C(829), UINT16_C(4002),
        UINT16_C(4302), UINT16_C(897), UINT16_C(4387), UINT16_C(6837) } } },
   { { {  UINT16_C(7563), UINT16_C(2164), UINT16_C(8586), UINT16_C(1245),
        UINT16_C(9300), UINT16_C(1489), UINT16_C(7158), UINT16_C(4863) },
       {  UINT16_C(1424), UINT16_C(4247), UINT16_C(5640), UINT16_C(6608),
        UINT16_C(5989), UINT16_C(3578), UINT16_C(742), UINT16_C(1885) },
       {  UINT16_C(5512), UINT16_C(3861), UINT16_C(6631), UINT16_C(2430),
        UINT16_C(2806), UINT16_C(1789), UINT16_C(8536), UINT16_C(1442) } },
       {  UINT16_C(321), UINT16_C(9802), UINT16_C(8592)},
     { {  UINT16_C(7563), UINT16_C(2164), UINT16_C(8586), UINT16_C(321),
        UINT16_C(9300), UINT16_C(1489), UINT16_C(7158), UINT16_C(4863) },
       {  UINT16_C(1424), UINT16_C(4247), UINT16_C(5640), UINT16_C(9802),
        UINT16_C(5989), UINT16_C(3578), UINT16_C(742), UINT16_C(1885) },
       {  UINT16_C(5512), UINT16_C(3861), UINT16_C(6631), UINT16_C(8592),
        UINT16_C(2806), UINT16_C(1789), UINT16_C(8536), UINT16_C(1442) } } },
   { { {  UINT16_C(846), UINT16_C(2844), UINT16_C(4543), UINT16_C(5042),
        UINT16_C(9059), UINT16_C(789), UINT16_C(9345), UINT16_C(8528) },
       {  UINT16_C(5245), UINT16_C(4972), UINT16_C(9392), UINT16_C(6785),
        UINT16_C(6982), UINT16_C(1587), UINT16_C(9547), UINT16_C(806) },
       {  UINT16_C(2535), UINT16_C(912), UINT16_C(7134), UINT16_C(1939),
        UINT16_C(226), UINT16_C(4171), UINT16_C(756), UINT16_C(7958) } },
       {  UINT16_C(9975), UINT16_C(6402), UINT16_C(5394)},
     { {  UINT16_C(846), UINT16_C(2844), UINT16_C(4543), UINT16_C(5042),
        UINT16_C(9975), UINT16_C(789), UINT16_C(9345), UINT16_C(8528) },
       {  UINT16_C(5245), UINT16_C(4972), UINT16_C(9392), UINT16_C(6785),
        UINT16_C(6402), UINT16_C(1587), UINT16_C(9547), UINT16_C(806) },
       {  UINT16_C(2535), UINT16_C(912), UINT16_C(7134), UINT16_C(1939),
        UINT16_C(5394), UINT16_C(4171), UINT16_C(756), UINT16_C(7958) } } },
   { { {  UINT16_C(5491), UINT16_C(9037), UINT16_C(2121), UINT16_C(3027),
        UINT16_C(9896), UINT16_C(3828), UINT16_C(4925), UINT16_C(6295) },
       {  UINT16_C(4330), UINT16_C(4964), UINT16_C(3055), UINT16_C(2853),
        UINT16_C(5505), UINT16_C(2630), UINT16_C(7217), UINT16_C(9453) },
       {  UINT16_C(9293), UINT16_C(8272), UINT16_C(4351), UINT16_C(7481),
        UINT16_C(2380), UINT16_C(1671), UINT16_C(9975), UINT16_C(6647) } },
       {  UINT16_C(2220), UINT16_C(9744), UINT16_C(8641)},
     { {  UINT16_C(5491), UINT16_C(9037), UINT16_C(2121), UINT16_C(3027),
        UINT16_C(9896), UINT16_C(2220), UINT16_C(4925), UINT16_C(6295) },
       {  UINT16_C(4330), UINT16_C(4964), UINT16_C(3055), UINT16_C(2853),
        UINT16_C(5505), UINT16_C(9744), UINT16_C(7217), UINT16_C(9453) },
       {  UINT16_C(9293), UINT16_C(8272), UINT16_C(4351), UINT16_C(7481),
        UINT16_C(2380), UINT16_C(8641), UINT16_C(9975), UINT16_C(6647) } } },
   { { {  UINT16_C(9694), UINT16_C(2965), UINT16_C(2860), UINT16_C(3217),
        UINT16_C(905), UINT16_C(1382), UINT16_C(2539), UINT16_C(2136) },
       {  UINT16_C(9340), UINT16_C(8057), UINT16_C(2560), UINT16_C(2780),
        UINT16_C(9091), UINT16_C(341), UINT16_C(2559), UINT16_C(5566) },
       {  UINT16_C(5464), UINT16_C(8934), UINT16_C(8459), UINT16_C(5838),
        UINT16_C(5847), UINT16_C(9085), UINT16_C(7113), UINT16_C(1453) } },
       {  UINT16_C(9231), UINT16_C(1160), UINT16_C(1750)},
     { {  UINT16_C(9694), UINT16_C(2965), UINT16_C(2860), UINT16_C(3217),
        UINT16_C(905), UINT16_C(1382), UINT16_C(9231), UINT16_C(2136) },
       {  UINT16_C(9340), UINT16_C(8057), UINT16_C(2560), UINT16_C(2780),
        UINT16_C(9091), UINT16_C(341), UINT16_C(1160), UINT16_C(5566) },
       {  UINT16_C(5464), UINT16_C(8934), UINT16_C(8459), UINT16_C(5838),
        UINT16_C(5847), UINT16_C(9085), UINT16_C(1750), UINT16_C(1453) } } },
   { { {  UINT16_C(4299), UINT16_C(2575), UINT16_C(1738), UINT16_C(2713),
        UINT16_C(3823), UINT16_C(2897), UINT16_C(4868), UINT16_C(3272) },
       {  UINT16_C(1451), UINT16_C(4038), UINT16_C(5588), UINT16_C(8951),
        UINT16_C(8365), UINT16_C(7112), UINT16_C(7225), UINT16_C(5057) },
       {  UINT16_C(1287), UINT16_C(8547), UINT16_C(3369), UINT16_C(2472),
        UINT16_C(2063), UINT16_C(1405), UINT16_C(3647), UINT16_C(1463) } },
       {  UINT16_C(6301), UINT16_C(8922), UINT16_C(8856)},
     { {  UINT16_C(4299), UINT16_C(2575), UINT16_C(1738), UINT16_C(2713),
        UINT16_C(3823), UINT16_C(2897), UINT16_C(4868), UINT16_C(6301) },
       {  UINT16_C(1451), UINT16_C(4038), UINT16_C(5588), UINT16_C(8951),
        UINT16_C(8365), UINT16_C(7112), UINT16_C(7225), UINT16_C(8922) },
       {  UINT16_C(1287), UINT16_C(8547), UINT16_C(3369), UINT16_C(2472),
        UINT16_C(2063), UINT16_C(1405), UINT16_C(3647), UINT16_C(8856) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8x3_t r, src, expected;
    src.val[0] = simde_vld1q_u16(test_vec[i].src[0]);
    src.val[1] = simde_vld1q_u16(test_vec[i].src[1]);
    src.val[2] = simde_vld1q_u16(test_vec[i].src[2]);

    SIMDE_CONSTIFY_8_(simde_vld3q_lane_u16, r, (HEDLEY_UNREACHABLE(), r), i, test_vec[i].buf, src);

    expected.val[0] = simde_vld1q_u16(test_vec[i].r[0]);
    expected.val[1] = simde_vld1q_u16(test_vec[i].r[1]);
    expected.val[2] = simde_vld1q_u16(test_vec[i].r[2]);

    simde_test_arm_neon_assert_equal_u16x8(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_u16x8(r.val[1], expected.val[1]);
    simde_test_arm_neon_assert_equal_u16x8(r.val[2], expected.val[2]);
  }

  return 0;
}

static int
test_simde_vld3q_lane_u32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    uint32_t src[3][4];
    uint32_t buf[3];
    uint32_t r[3][4];
  } test_vec[] = {
   { { {  UINT32_C(959147), UINT32_C(94730), UINT32_C(265123), UINT32_C(263205) },
       {  UINT32_C(327934), UINT32_C(818462), UINT32_C(254631), UINT32_C(86194) },
       {  UINT32_C(686652), UINT32_C(235562), UINT32_C(658626), UINT32_C(197485) } },
       {  UINT32_C(762356), UINT32_C(737061), UINT32_C(61171)},
     { {  UINT32_C(762356), UINT32_C(94730), UINT32_C(265123), UINT32_C(263205) },
       {  UINT32_C(737061), UINT32_C(818462), UINT32_C(254631), UINT32_C(86194) },
       {  UINT32_C(61171), UINT32_C(235562), UINT32_C(658626), UINT32_C(197485) } } },
   { { {  UINT32_C(702078), UINT32_C(591841), UINT32_C(292142), UINT32_C(285089) },
       {  UINT32_C(587049), UINT32_C(158254), UINT32_C(152477), UINT32_C(801436) },
       {  UINT32_C(770450), UINT32_C(89829), UINT32_C(318188), UINT32_C(152245) } },
       {  UINT32_C(632310), UINT32_C(338180), UINT32_C(842631)},
     { {  UINT32_C(702078), UINT32_C(632310), UINT32_C(292142), UINT32_C(285089) },
       {  UINT32_C(587049), UINT32_C(338180), UINT32_C(152477), UINT32_C(801436) },
       {  UINT32_C(770450), UINT32_C(842631), UINT32_C(318188), UINT32_C(152245) } } },
   { { {  UINT32_C(845723), UINT32_C(174450), UINT32_C(865498), UINT32_C(926110) },
       {  UINT32_C(981718), UINT32_C(813344), UINT32_C(735780), UINT32_C(959418) },
       {  UINT32_C(814557), UINT32_C(573143), UINT32_C(702063), UINT32_C(80851) } },
       {  UINT32_C(353668), UINT32_C(149751), UINT32_C(602863)},
     { {  UINT32_C(845723), UINT32_C(174450), UINT32_C(353668), UINT32_C(926110) },
       {  UINT32_C(981718), UINT32_C(813344), UINT32_C(149751), UINT32_C(959418) },
       {  UINT32_C(814557), UINT32_C(573143), UINT32_C(602863), UINT32_C(80851) } } },
   { { {  UINT32_C(306861), UINT32_C(942100), UINT32_C(490421), UINT32_C(582143) },
       {  UINT32_C(266515), UINT32_C(182890), UINT32_C(927663), UINT32_C(939410) },
       {  UINT32_C(876199), UINT32_C(921600), UINT32_C(507718), UINT32_C(447676) } },
       {  UINT32_C(769107), UINT32_C(184326), UINT32_C(759585)},
     { {  UINT32_C(306861), UINT32_C(942100), UINT32_C(490421), UINT32_C(769107) },
       {  UINT32_C(266515), UINT32_C(182890), UINT32_C(927663), UINT32_C(184326) },
       {  UINT32_C(876199), UINT32_C(921600), UINT32_C(507718), UINT32_C(759585) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4x3_t r, src, expected;
    src.val[0] = simde_vld1q_u32(test_vec[i].src[0]);
    src.val[1] = simde_vld1q_u32(test_vec[i].src[1]);
    src.val[2] = simde_vld1q_u32(test_vec[i].src[2]);

    SIMDE_CONSTIFY_4_(simde_vld3q_lane_u32, r, (HEDLEY_UNREACHABLE(), r), i, test_vec[i].buf, src);

    expected.val[0] = simde_vld1q_u32(test_vec[i].r[0]);
    expected.val[1] = simde_vld1q_u32(test_vec[i].r[1]);
    expected.val[2] = simde_vld1q_u32(test_vec[i].r[2]);

    simde_test_arm_neon_assert_equal_u32x4(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_u32x4(r.val[1], expected.val[1]);
    simde_test_arm_neon_assert_equal_u32x4(r.val[2], expected.val[2]);
  }
  return 0;
}

static int
test_simde_vld3q_lane_u64 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    uint64_t src[3][2];
    uint64_t buf[3];
    uint64_t r[3][2];
  } test_vec[] = {
   { { {  UINT64_C(56952904), UINT64_C(35256781) },
       {  UINT64_C(89718407), UINT64_C(12358219) },
       {  UINT64_C(61792069), UINT64_C(55919668) } },
       {  UINT64_C(95716616), UINT64_C(80066973), UINT64_C(46886750)},
     { {  UINT64_C(95716616), UINT64_C(35256781) },
       {  UINT64_C(80066973), UINT64_C(12358219) },
       {  UINT64_C(46886750), UINT64_C(55919668) } } },
   { { {  UINT64_C(95308677), UINT64_C(34498022) },
       {  UINT64_C(67254093), UINT64_C(94380501) },
       {  UINT64_C(77927395), UINT64_C(69899674) } },
       {  UINT64_C(50242963), UINT64_C(81401259), UINT64_C(34813265)},
     { {  UINT64_C(95308677), UINT64_C(50242963) },
       {  UINT64_C(67254093), UINT64_C(81401259) },
       {  UINT64_C(77927395), UINT64_C(34813265) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x2x3_t r, src, expected;
    src.val[0] = simde_vld1q_u64(test_vec[i].src[0]);
    src.val[1] = simde_vld1q_u64(test_vec[i].src[1]);
    src.val[2] = simde_vld1q_u64(test_vec[i].src[2]);

    SIMDE_CONSTIFY_2_(simde_vld3q_lane_u64, r, (HEDLEY_UNREACHABLE(), r), i, test_vec[i].buf, src);

    expected.val[0] = simde_vld1q_u64(test_vec[i].r[0]);
    expected.val[1] = simde_vld1q_u64(test_vec[i].r[1]);
    expected.val[2] = simde_vld1q_u64(test_vec[i].r[2]);

    simde_test_arm_neon_assert_equal_u64x2(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_u64x2(r.val[1], expected.val[1]);
    simde_test_arm_neon_assert_equal_u64x2(r.val[2], expected.val[2]);
  }

  return 0;
}

static int
test_simde_vld3q_lane_f16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float16_t src[3][8];
    simde_float16_t buf[3];
    simde_float16_t r[3][8];
  } test_vec[] = {
   { { {  SIMDE_FLOAT16_VALUE(25.81), SIMDE_FLOAT16_VALUE(32.75), SIMDE_FLOAT16_VALUE(23.73), SIMDE_FLOAT16_VALUE(-45.72),
        SIMDE_FLOAT16_VALUE(21.87), SIMDE_FLOAT16_VALUE(8.97), SIMDE_FLOAT16_VALUE(-15.67), SIMDE_FLOAT16_VALUE(26.89) },
       {  SIMDE_FLOAT16_VALUE(16.63), SIMDE_FLOAT16_VALUE(6.70), SIMDE_FLOAT16_VALUE(26.16), SIMDE_FLOAT16_VALUE(-0.53),
        SIMDE_FLOAT16_VALUE(-39.38), SIMDE_FLOAT16_VALUE(-30.03), SIMDE_FLOAT16_VALUE(33.53), SIMDE_FLOAT16_VALUE(-5.08) },
       {  SIMDE_FLOAT16_VALUE(24.18), SIMDE_FLOAT16_VALUE(-0.77), SIMDE_FLOAT16_VALUE(-38.76), SIMDE_FLOAT16_VALUE(23.74),
        SIMDE_FLOAT16_VALUE(-37.79), SIMDE_FLOAT16_VALUE(-12.87), SIMDE_FLOAT16_VALUE(35.22), SIMDE_FLOAT16_VALUE(18.82) } },
       {  SIMDE_FLOAT16_VALUE(18.75), SIMDE_FLOAT16_VALUE(-19.33), SIMDE_FLOAT16_VALUE(-8.32)},
     { {  SIMDE_FLOAT16_VALUE(18.75), SIMDE_FLOAT16_VALUE(32.75), SIMDE_FLOAT16_VALUE(23.73), SIMDE_FLOAT16_VALUE(-45.72),
        SIMDE_FLOAT16_VALUE(21.87), SIMDE_FLOAT16_VALUE(8.97), SIMDE_FLOAT16_VALUE(-15.67), SIMDE_FLOAT16_VALUE(26.89) },
       {  SIMDE_FLOAT16_VALUE(-19.33), SIMDE_FLOAT16_VALUE(6.70), SIMDE_FLOAT16_VALUE(26.16), SIMDE_FLOAT16_VALUE(-0.53),
        SIMDE_FLOAT16_VALUE(-39.38), SIMDE_FLOAT16_VALUE(-30.03), SIMDE_FLOAT16_VALUE(33.53), SIMDE_FLOAT16_VALUE(-5.08) },
       {  SIMDE_FLOAT16_VALUE(-8.32), SIMDE_FLOAT16_VALUE(-0.77), SIMDE_FLOAT16_VALUE(-38.76), SIMDE_FLOAT16_VALUE(23.74),
        SIMDE_FLOAT16_VALUE(-37.79), SIMDE_FLOAT16_VALUE(-12.87), SIMDE_FLOAT16_VALUE(35.22), SIMDE_FLOAT16_VALUE(18.82) } } },
   { { {  SIMDE_FLOAT16_VALUE(-21.87), SIMDE_FLOAT16_VALUE(-23.46), SIMDE_FLOAT16_VALUE(43.50), SIMDE_FLOAT16_VALUE(-42.37),
        SIMDE_FLOAT16_VALUE(38.96), SIMDE_FLOAT16_VALUE(-39.73), SIMDE_FLOAT16_VALUE(1.99), SIMDE_FLOAT16_VALUE(13.47) },
       {  SIMDE_FLOAT16_VALUE(-21.30), SIMDE_FLOAT16_VALUE(31.71), SIMDE_FLOAT16_VALUE(43.14), SIMDE_FLOAT16_VALUE(6.05),
        SIMDE_FLOAT16_VALUE(-9.36), SIMDE_FLOAT16_VALUE(31.44), SIMDE_FLOAT16_VALUE(-1.40), SIMDE_FLOAT16_VALUE(-46.83) },
       {  SIMDE_FLOAT16_VALUE(22.32), SIMDE_FLOAT16_VALUE(-30.37), SIMDE_FLOAT16_VALUE(-16.31), SIMDE_FLOAT16_VALUE(48.67),
        SIMDE_FLOAT16_VALUE(-32.26), SIMDE_FLOAT16_VALUE(-43.03), SIMDE_FLOAT16_VALUE(-31.49), SIMDE_FLOAT16_VALUE(-29.73) } },
       {  SIMDE_FLOAT16_VALUE(-19.96), SIMDE_FLOAT16_VALUE(16.11), SIMDE_FLOAT16_VALUE(15.29)},
     { {  SIMDE_FLOAT16_VALUE(-21.87), SIMDE_FLOAT16_VALUE(-19.96), SIMDE_FLOAT16_VALUE(43.50), SIMDE_FLOAT16_VALUE(-42.37),
        SIMDE_FLOAT16_VALUE(38.96), SIMDE_FLOAT16_VALUE(-39.73), SIMDE_FLOAT16_VALUE(1.99), SIMDE_FLOAT16_VALUE(13.47) },
       {  SIMDE_FLOAT16_VALUE(-21.30), SIMDE_FLOAT16_VALUE(16.11), SIMDE_FLOAT16_VALUE(43.14), SIMDE_FLOAT16_VALUE(6.05),
        SIMDE_FLOAT16_VALUE(-9.36), SIMDE_FLOAT16_VALUE(31.44), SIMDE_FLOAT16_VALUE(-1.40), SIMDE_FLOAT16_VALUE(-46.83) },
       {  SIMDE_FLOAT16_VALUE(22.32), SIMDE_FLOAT16_VALUE(15.29), SIMDE_FLOAT16_VALUE(-16.31), SIMDE_FLOAT16_VALUE(48.67),
        SIMDE_FLOAT16_VALUE(-32.26), SIMDE_FLOAT16_VALUE(-43.03), SIMDE_FLOAT16_VALUE(-31.49), SIMDE_FLOAT16_VALUE(-29.73) } } },
   { { {  SIMDE_FLOAT16_VALUE(22.99), SIMDE_FLOAT16_VALUE(19.29), SIMDE_FLOAT16_VALUE(-46.27), SIMDE_FLOAT16_VALUE(-49.21),
        SIMDE_FLOAT16_VALUE(48.55), SIMDE_FLOAT16_VALUE(49.51), SIMDE_FLOAT16_VALUE(1.68), SIMDE_FLOAT16_VALUE(4.07) },
       {  SIMDE_FLOAT16_VALUE(-8.20), SIMDE_FLOAT16_VALUE(5.11), SIMDE_FLOAT16_VALUE(17.40), SIMDE_FLOAT16_VALUE(-3.87),
        SIMDE_FLOAT16_VALUE(-20.55), SIMDE_FLOAT16_VALUE(19.44), SIMDE_FLOAT16_VALUE(-49.04), SIMDE_FLOAT16_VALUE(-1.42) },
       {  SIMDE_FLOAT16_VALUE(22.33), SIMDE_FLOAT16_VALUE(-45.53), SIMDE_FLOAT16_VALUE(-33.31), SIMDE_FLOAT16_VALUE(-20.16),
        SIMDE_FLOAT16_VALUE(-39.51), SIMDE_FLOAT16_VALUE(-20.23), SIMDE_FLOAT16_VALUE(-41.96), SIMDE_FLOAT16_VALUE(-27.75) } },
       {  SIMDE_FLOAT16_VALUE(21.67), SIMDE_FLOAT16_VALUE(-1.62), SIMDE_FLOAT16_VALUE(47.29)},
     { {  SIMDE_FLOAT16_VALUE(22.99), SIMDE_FLOAT16_VALUE(19.29), SIMDE_FLOAT16_VALUE(21.67), SIMDE_FLOAT16_VALUE(-49.21),
        SIMDE_FLOAT16_VALUE(48.55), SIMDE_FLOAT16_VALUE(49.51), SIMDE_FLOAT16_VALUE(1.68), SIMDE_FLOAT16_VALUE(4.07) },
       {  SIMDE_FLOAT16_VALUE(-8.20), SIMDE_FLOAT16_VALUE(5.11), SIMDE_FLOAT16_VALUE(-1.62), SIMDE_FLOAT16_VALUE(-3.87),
        SIMDE_FLOAT16_VALUE(-20.55), SIMDE_FLOAT16_VALUE(19.44), SIMDE_FLOAT16_VALUE(-49.04), SIMDE_FLOAT16_VALUE(-1.42) },
       {  SIMDE_FLOAT16_VALUE(22.33), SIMDE_FLOAT16_VALUE(-45.53), SIMDE_FLOAT16_VALUE(47.29), SIMDE_FLOAT16_VALUE(-20.16),
        SIMDE_FLOAT16_VALUE(-39.51), SIMDE_FLOAT16_VALUE(-20.23), SIMDE_FLOAT16_VALUE(-41.96), SIMDE_FLOAT16_VALUE(-27.75) } } },
   { { {  SIMDE_FLOAT16_VALUE(-13.98), SIMDE_FLOAT16_VALUE(-15.40), SIMDE_FLOAT16_VALUE(-41.40), SIMDE_FLOAT16_VALUE(-11.10),
        SIMDE_FLOAT16_VALUE(-0.98), SIMDE_FLOAT16_VALUE(20.30), SIMDE_FLOAT16_VALUE(-21.19), SIMDE_FLOAT16_VALUE(32.22) },
       {  SIMDE_FLOAT16_VALUE(-29.71), SIMDE_FLOAT16_VALUE(-33.61), SIMDE_FLOAT16_VALUE(-34.96), SIMDE_FLOAT16_VALUE(22.05),
        SIMDE_FLOAT16_VALUE(-46.85), SIMDE_FLOAT16_VALUE(49.18), SIMDE_FLOAT16_VALUE(29.80), SIMDE_FLOAT16_VALUE(15.12) },
       {  SIMDE_FLOAT16_VALUE(-48.25), SIMDE_FLOAT16_VALUE(20.21), SIMDE_FLOAT16_VALUE(30.89), SIMDE_FLOAT16_VALUE(-8.00),
        SIMDE_FLOAT16_VALUE(47.59), SIMDE_FLOAT16_VALUE(-33.30), SIMDE_FLOAT16_VALUE(-17.17), SIMDE_FLOAT16_VALUE(15.96) } },
       {  SIMDE_FLOAT16_VALUE(-22.71), SIMDE_FLOAT16_VALUE(18.03), SIMDE_FLOAT16_VALUE(-12.62)},
     { {  SIMDE_FLOAT16_VALUE(-13.98), SIMDE_FLOAT16_VALUE(-15.40), SIMDE_FLOAT16_VALUE(-41.40), SIMDE_FLOAT16_VALUE(-22.71),
        SIMDE_FLOAT16_VALUE(-0.98), SIMDE_FLOAT16_VALUE(20.30), SIMDE_FLOAT16_VALUE(-21.19), SIMDE_FLOAT16_VALUE(32.22) },
       {  SIMDE_FLOAT16_VALUE(-29.71), SIMDE_FLOAT16_VALUE(-33.61), SIMDE_FLOAT16_VALUE(-34.96), SIMDE_FLOAT16_VALUE(18.03),
        SIMDE_FLOAT16_VALUE(-46.85), SIMDE_FLOAT16_VALUE(49.18), SIMDE_FLOAT16_VALUE(29.80), SIMDE_FLOAT16_VALUE(15.12) },
       {  SIMDE_FLOAT16_VALUE(-48.25), SIMDE_FLOAT16_VALUE(20.21), SIMDE_FLOAT16_VALUE(30.89), SIMDE_FLOAT16_VALUE(-12.62),
        SIMDE_FLOAT16_VALUE(47.59), SIMDE_FLOAT16_VALUE(-33.30), SIMDE_FLOAT16_VALUE(-17.17), SIMDE_FLOAT16_VALUE(15.96) } } },
   { { {  SIMDE_FLOAT16_VALUE(-33.16), SIMDE_FLOAT16_VALUE(41.77), SIMDE_FLOAT16_VALUE(0.37), SIMDE_FLOAT16_VALUE(49.97),
        SIMDE_FLOAT16_VALUE(41.81), SIMDE_FLOAT16_VALUE(-38.26), SIMDE_FLOAT16_VALUE(36.03), SIMDE_FLOAT16_VALUE(-6.12) },
       {  SIMDE_FLOAT16_VALUE(45.98), SIMDE_FLOAT16_VALUE(33.57), SIMDE_FLOAT16_VALUE(4.26), SIMDE_FLOAT16_VALUE(19.87),
        SIMDE_FLOAT16_VALUE(6.49), SIMDE_FLOAT16_VALUE(3.23), SIMDE_FLOAT16_VALUE(17.28), SIMDE_FLOAT16_VALUE(-0.70) },
       {  SIMDE_FLOAT16_VALUE(-45.21), SIMDE_FLOAT16_VALUE(10.70), SIMDE_FLOAT16_VALUE(-30.89), SIMDE_FLOAT16_VALUE(17.48),
        SIMDE_FLOAT16_VALUE(-18.12), SIMDE_FLOAT16_VALUE(-36.32), SIMDE_FLOAT16_VALUE(12.70), SIMDE_FLOAT16_VALUE(-9.89) } },
       {  SIMDE_FLOAT16_VALUE(19.50), SIMDE_FLOAT16_VALUE(43.23), SIMDE_FLOAT16_VALUE(-34.14)},
     { {  SIMDE_FLOAT16_VALUE(-33.16), SIMDE_FLOAT16_VALUE(41.77), SIMDE_FLOAT16_VALUE(0.37), SIMDE_FLOAT16_VALUE(49.97),
        SIMDE_FLOAT16_VALUE(19.50), SIMDE_FLOAT16_VALUE(-38.26), SIMDE_FLOAT16_VALUE(36.03), SIMDE_FLOAT16_VALUE(-6.12) },
       {  SIMDE_FLOAT16_VALUE(45.98), SIMDE_FLOAT16_VALUE(33.57), SIMDE_FLOAT16_VALUE(4.26), SIMDE_FLOAT16_VALUE(19.87),
        SIMDE_FLOAT16_VALUE(43.23), SIMDE_FLOAT16_VALUE(3.23), SIMDE_FLOAT16_VALUE(17.28), SIMDE_FLOAT16_VALUE(-0.70) },
       {  SIMDE_FLOAT16_VALUE(-45.21), SIMDE_FLOAT16_VALUE(10.70), SIMDE_FLOAT16_VALUE(-30.89), SIMDE_FLOAT16_VALUE(17.48),
        SIMDE_FLOAT16_VALUE(-34.14), SIMDE_FLOAT16_VALUE(-36.32), SIMDE_FLOAT16_VALUE(12.70), SIMDE_FLOAT16_VALUE(-9.89) } } },
   { { {  SIMDE_FLOAT16_VALUE(34.35), SIMDE_FLOAT16_VALUE(45.11), SIMDE_FLOAT16_VALUE(-17.38), SIMDE_FLOAT16_VALUE(32.13),
        SIMDE_FLOAT16_VALUE(-19.58), SIMDE_FLOAT16_VALUE(-5.73), SIMDE_FLOAT16_VALUE(-14.12), SIMDE_FLOAT16_VALUE(-0.42) },
       {  SIMDE_FLOAT16_VALUE(-17.04), SIMDE_FLOAT16_VALUE(40.80), SIMDE_FLOAT16_VALUE(-45.80), SIMDE_FLOAT16_VALUE(37.28),
        SIMDE_FLOAT16_VALUE(35.24), SIMDE_FLOAT16_VALUE(40.83), SIMDE_FLOAT16_VALUE(41.86), SIMDE_FLOAT16_VALUE(16.76) },
       {  SIMDE_FLOAT16_VALUE(44.82), SIMDE_FLOAT16_VALUE(44.21), SIMDE_FLOAT16_VALUE(-16.87), SIMDE_FLOAT16_VALUE(28.04),
        SIMDE_FLOAT16_VALUE(12.42), SIMDE_FLOAT16_VALUE(-24.77), SIMDE_FLOAT16_VALUE(-2.03), SIMDE_FLOAT16_VALUE(6.16) } },
       {  SIMDE_FLOAT16_VALUE(24.51), SIMDE_FLOAT16_VALUE(-14.45), SIMDE_FLOAT16_VALUE(-29.20)},
     { {  SIMDE_FLOAT16_VALUE(34.35), SIMDE_FLOAT16_VALUE(45.11), SIMDE_FLOAT16_VALUE(-17.38), SIMDE_FLOAT16_VALUE(32.13),
        SIMDE_FLOAT16_VALUE(-19.58), SIMDE_FLOAT16_VALUE(24.51), SIMDE_FLOAT16_VALUE(-14.12), SIMDE_FLOAT16_VALUE(-0.42) },
       {  SIMDE_FLOAT16_VALUE(-17.04), SIMDE_FLOAT16_VALUE(40.80), SIMDE_FLOAT16_VALUE(-45.80), SIMDE_FLOAT16_VALUE(37.28),
        SIMDE_FLOAT16_VALUE(35.24), SIMDE_FLOAT16_VALUE(-14.45), SIMDE_FLOAT16_VALUE(41.86), SIMDE_FLOAT16_VALUE(16.76) },
       {  SIMDE_FLOAT16_VALUE(44.82), SIMDE_FLOAT16_VALUE(44.21), SIMDE_FLOAT16_VALUE(-16.87), SIMDE_FLOAT16_VALUE(28.04),
        SIMDE_FLOAT16_VALUE(12.42), SIMDE_FLOAT16_VALUE(-29.20), SIMDE_FLOAT16_VALUE(-2.03), SIMDE_FLOAT16_VALUE(6.16) } } },
   { { {  SIMDE_FLOAT16_VALUE(-19.86), SIMDE_FLOAT16_VALUE(-49.12), SIMDE_FLOAT16_VALUE(-43.11), SIMDE_FLOAT16_VALUE(6.61),
        SIMDE_FLOAT16_VALUE(-14.42), SIMDE_FLOAT16_VALUE(-26.68), SIMDE_FLOAT16_VALUE(-14.21), SIMDE_FLOAT16_VALUE(-19.62) },
       {  SIMDE_FLOAT16_VALUE(2.80), SIMDE_FLOAT16_VALUE(21.66), SIMDE_FLOAT16_VALUE(-36.49), SIMDE_FLOAT16_VALUE(-15.12),
        SIMDE_FLOAT16_VALUE(-49.41), SIMDE_FLOAT16_VALUE(-26.19), SIMDE_FLOAT16_VALUE(-24.23), SIMDE_FLOAT16_VALUE(36.09) },
       {  SIMDE_FLOAT16_VALUE(10.26), SIMDE_FLOAT16_VALUE(31.20), SIMDE_FLOAT16_VALUE(-42.59), SIMDE_FLOAT16_VALUE(22.36),
        SIMDE_FLOAT16_VALUE(-1.95), SIMDE_FLOAT16_VALUE(-8.53), SIMDE_FLOAT16_VALUE(37.02), SIMDE_FLOAT16_VALUE(-47.32) } },
       {  SIMDE_FLOAT16_VALUE(-2.66), SIMDE_FLOAT16_VALUE(-28.19), SIMDE_FLOAT16_VALUE(-49.39)},
     { {  SIMDE_FLOAT16_VALUE(-19.86), SIMDE_FLOAT16_VALUE(-49.12), SIMDE_FLOAT16_VALUE(-43.11), SIMDE_FLOAT16_VALUE(6.61),
        SIMDE_FLOAT16_VALUE(-14.42), SIMDE_FLOAT16_VALUE(-26.68), SIMDE_FLOAT16_VALUE(-2.66), SIMDE_FLOAT16_VALUE(-19.62) },
       {  SIMDE_FLOAT16_VALUE(2.80), SIMDE_FLOAT16_VALUE(21.66), SIMDE_FLOAT16_VALUE(-36.49), SIMDE_FLOAT16_VALUE(-15.12),
        SIMDE_FLOAT16_VALUE(-49.41), SIMDE_FLOAT16_VALUE(-26.19), SIMDE_FLOAT16_VALUE(-28.19), SIMDE_FLOAT16_VALUE(36.09) },
       {  SIMDE_FLOAT16_VALUE(10.26), SIMDE_FLOAT16_VALUE(31.20), SIMDE_FLOAT16_VALUE(-42.59), SIMDE_FLOAT16_VALUE(22.36),
        SIMDE_FLOAT16_VALUE(-1.95), SIMDE_FLOAT16_VALUE(-8.53), SIMDE_FLOAT16_VALUE(-49.39), SIMDE_FLOAT16_VALUE(-47.32) } } },
   { { {  SIMDE_FLOAT16_VALUE(0.30), SIMDE_FLOAT16_VALUE(6.73), SIMDE_FLOAT16_VALUE(-6.28), SIMDE_FLOAT16_VALUE(35.22),
        SIMDE_FLOAT16_VALUE(-5.78), SIMDE_FLOAT16_VALUE(-32.42), SIMDE_FLOAT16_VALUE(-25.16), SIMDE_FLOAT16_VALUE(14.50) },
       {  SIMDE_FLOAT16_VALUE(9.20), SIMDE_FLOAT16_VALUE(15.26), SIMDE_FLOAT16_VALUE(14.27), SIMDE_FLOAT16_VALUE(24.06),
        SIMDE_FLOAT16_VALUE(9.76), SIMDE_FLOAT16_VALUE(-32.84), SIMDE_FLOAT16_VALUE(23.54), SIMDE_FLOAT16_VALUE(-38.60) },
       {  SIMDE_FLOAT16_VALUE(-2.89), SIMDE_FLOAT16_VALUE(-12.52), SIMDE_FLOAT16_VALUE(-24.22), SIMDE_FLOAT16_VALUE(45.18),
        SIMDE_FLOAT16_VALUE(-49.48), SIMDE_FLOAT16_VALUE(-38.06), SIMDE_FLOAT16_VALUE(0.89), SIMDE_FLOAT16_VALUE(-2.25) } },
       {  SIMDE_FLOAT16_VALUE(2.18), SIMDE_FLOAT16_VALUE(35.99), SIMDE_FLOAT16_VALUE(26.18)},
     { {  SIMDE_FLOAT16_VALUE(0.30), SIMDE_FLOAT16_VALUE(6.73), SIMDE_FLOAT16_VALUE(-6.28), SIMDE_FLOAT16_VALUE(35.22),
        SIMDE_FLOAT16_VALUE(-5.78), SIMDE_FLOAT16_VALUE(-32.42), SIMDE_FLOAT16_VALUE(-25.16), SIMDE_FLOAT16_VALUE(2.18) },
       {  SIMDE_FLOAT16_VALUE(9.20), SIMDE_FLOAT16_VALUE(15.26), SIMDE_FLOAT16_VALUE(14.27), SIMDE_FLOAT16_VALUE(24.06),
        SIMDE_FLOAT16_VALUE(9.76), SIMDE_FLOAT16_VALUE(-32.84), SIMDE_FLOAT16_VALUE(23.54), SIMDE_FLOAT16_VALUE(35.99) },
       {  SIMDE_FLOAT16_VALUE(-2.89), SIMDE_FLOAT16_VALUE(-12.52), SIMDE_FLOAT16_VALUE(-24.22), SIMDE_FLOAT16_VALUE(45.18),
        SIMDE_FLOAT16_VALUE(-49.48), SIMDE_FLOAT16_VALUE(-38.06), SIMDE_FLOAT16_VALUE(0.89), SIMDE_FLOAT16_VALUE(26.18) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x8x3_t r, src, expected;
    src.val[0] = simde_vld1q_f16(test_vec[i].src[0]);
    src.val[1] = simde_vld1q_f16(test_vec[i].src[1]);
    src.val[2] = simde_vld1q_f16(test_vec[i].src[2]);

    SIMDE_CONSTIFY_8_(simde_vld3q_lane_f16, r, (HEDLEY_UNREACHABLE(), r), i, test_vec[i].buf, src);

    expected.val[0] = simde_vld1q_f16(test_vec[i].r[0]);
    expected.val[1] = simde_vld1q_f16(test_vec[i].r[1]);
    expected.val[2] = simde_vld1q_f16(test_vec[i].r[2]);

    simde_test_arm_neon_assert_equal_f16x8(r.val[0], expected.val[0], INT_MAX);
    simde_test_arm_neon_assert_equal_f16x8(r.val[1], expected.val[1], INT_MAX);
    simde_test_arm_neon_assert_equal_f16x8(r.val[2], expected.val[2], INT_MAX);
  }

  return 0;
}

static int
test_simde_vld3q_lane_f32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    simde_float32_t src[3][4];
    simde_float32_t buf[3];
    simde_float32_t r[3][4];
  } test_vec[] = {
   { { {  SIMDE_FLOAT32_C(1442.30), SIMDE_FLOAT32_C(446.63), SIMDE_FLOAT32_C(2243.75), SIMDE_FLOAT32_C(-2499.62) },
       {  SIMDE_FLOAT32_C(-1210.23), SIMDE_FLOAT32_C(1076.44), SIMDE_FLOAT32_C(304.40), SIMDE_FLOAT32_C(4898.02) },
       {  SIMDE_FLOAT32_C(-4476.84), SIMDE_FLOAT32_C(808.69), SIMDE_FLOAT32_C(-1468.41), SIMDE_FLOAT32_C(4180.77) } },
       {  SIMDE_FLOAT32_C(1068.72), SIMDE_FLOAT32_C(-3535.90), SIMDE_FLOAT32_C(-2034.07)},
     { {  SIMDE_FLOAT32_C(1068.72), SIMDE_FLOAT32_C(446.63), SIMDE_FLOAT32_C(2243.75), SIMDE_FLOAT32_C(-2499.62) },
       {  SIMDE_FLOAT32_C(-3535.90), SIMDE_FLOAT32_C(1076.44), SIMDE_FLOAT32_C(304.40), SIMDE_FLOAT32_C(4898.02) },
       {  SIMDE_FLOAT32_C(-2034.07), SIMDE_FLOAT32_C(808.69), SIMDE_FLOAT32_C(-1468.41), SIMDE_FLOAT32_C(4180.77) } } },
   { { {  SIMDE_FLOAT32_C(2644.49), SIMDE_FLOAT32_C(4971.83), SIMDE_FLOAT32_C(861.80), SIMDE_FLOAT32_C(3165.61) },
       {  SIMDE_FLOAT32_C(981.55), SIMDE_FLOAT32_C(4193.07), SIMDE_FLOAT32_C(4921.81), SIMDE_FLOAT32_C(-254.58) },
       {  SIMDE_FLOAT32_C(-1820.81), SIMDE_FLOAT32_C(-2716.98), SIMDE_FLOAT32_C(-4407.29), SIMDE_FLOAT32_C(3037.96) } },
       {  SIMDE_FLOAT32_C(1589.12), SIMDE_FLOAT32_C(-3745.39), SIMDE_FLOAT32_C(-1432.03)},
     { {  SIMDE_FLOAT32_C(2644.49), SIMDE_FLOAT32_C(1589.12), SIMDE_FLOAT32_C(861.80), SIMDE_FLOAT32_C(3165.61) },
       {  SIMDE_FLOAT32_C(981.55), SIMDE_FLOAT32_C(-3745.39), SIMDE_FLOAT32_C(4921.81), SIMDE_FLOAT32_C(-254.58) },
       {  SIMDE_FLOAT32_C(-1820.81), SIMDE_FLOAT32_C(-1432.03), SIMDE_FLOAT32_C(-4407.29), SIMDE_FLOAT32_C(3037.96) } } },
   { { {  SIMDE_FLOAT32_C(103.78), SIMDE_FLOAT32_C(4622.34), SIMDE_FLOAT32_C(2752.48), SIMDE_FLOAT32_C(-1587.27) },
       {  SIMDE_FLOAT32_C(-3510.64), SIMDE_FLOAT32_C(-3612.38), SIMDE_FLOAT32_C(-3439.33), SIMDE_FLOAT32_C(3770.62) },
       {  SIMDE_FLOAT32_C(-2761.21), SIMDE_FLOAT32_C(4309.89), SIMDE_FLOAT32_C(-1652.27), SIMDE_FLOAT32_C(-3021.97) } },
       {  SIMDE_FLOAT32_C(3900.94), SIMDE_FLOAT32_C(3824.24), SIMDE_FLOAT32_C(4471.20)},
     { {  SIMDE_FLOAT32_C(103.78), SIMDE_FLOAT32_C(4622.34), SIMDE_FLOAT32_C(3900.94), SIMDE_FLOAT32_C(-1587.27) },
       {  SIMDE_FLOAT32_C(-3510.64), SIMDE_FLOAT32_C(-3612.38), SIMDE_FLOAT32_C(3824.24), SIMDE_FLOAT32_C(3770.62) },
       {  SIMDE_FLOAT32_C(-2761.21), SIMDE_FLOAT32_C(4309.89), SIMDE_FLOAT32_C(4471.20), SIMDE_FLOAT32_C(-3021.97) } } },
   { { {  SIMDE_FLOAT32_C(4335.85), SIMDE_FLOAT32_C(-509.93), SIMDE_FLOAT32_C(3599.27), SIMDE_FLOAT32_C(3192.52) },
       {  SIMDE_FLOAT32_C(3953.94), SIMDE_FLOAT32_C(-3940.66), SIMDE_FLOAT32_C(-0.37), SIMDE_FLOAT32_C(-529.08) },
       {  SIMDE_FLOAT32_C(3260.04), SIMDE_FLOAT32_C(1545.62), SIMDE_FLOAT32_C(-1906.87), SIMDE_FLOAT32_C(3771.80) } },
       {  SIMDE_FLOAT32_C(2065.71), SIMDE_FLOAT32_C(1441.87), SIMDE_FLOAT32_C(-3831.46)},
     { {  SIMDE_FLOAT32_C(4335.85), SIMDE_FLOAT32_C(-509.93), SIMDE_FLOAT32_C(3599.27), SIMDE_FLOAT32_C(2065.71) },
       {  SIMDE_FLOAT32_C(3953.94), SIMDE_FLOAT32_C(-3940.66), SIMDE_FLOAT32_C(-0.37), SIMDE_FLOAT32_C(1441.87) },
       {  SIMDE_FLOAT32_C(3260.04), SIMDE_FLOAT32_C(1545.62), SIMDE_FLOAT32_C(-1906.87), SIMDE_FLOAT32_C(-3831.46) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4x3_t r, src, expected;
    src.val[0] = simde_vld1q_f32(test_vec[i].src[0]);
    src.val[1] = simde_vld1q_f32(test_vec[i].src[1]);
    src.val[2] = simde_vld1q_f32(test_vec[i].src[2]);

    SIMDE_CONSTIFY_4_(simde_vld3q_lane_f32, r, (HEDLEY_UNREACHABLE(), r), i, test_vec[i].buf, src);

    expected.val[0] = simde_vld1q_f32(test_vec[i].r[0]);
    expected.val[1] = simde_vld1q_f32(test_vec[i].r[1]);
    expected.val[2] = simde_vld1q_f32(test_vec[i].r[2]);

    simde_test_arm_neon_assert_equal_f32x4(r.val[0], expected.val[0], INT_MAX);
    simde_test_arm_neon_assert_equal_f32x4(r.val[1], expected.val[1], INT_MAX);
    simde_test_arm_neon_assert_equal_f32x4(r.val[2], expected.val[2], INT_MAX);
  }

  return 0;

}

static int
test_simde_vld3q_lane_f64 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    simde_float64_t src[3][2];
    simde_float64_t buf[3];
    simde_float64_t r[3][2];
  } test_vec[] = {
   { { {  SIMDE_FLOAT64_C(332972.58), SIMDE_FLOAT64_C(-165510.51) },
       {  SIMDE_FLOAT64_C(473205.46), SIMDE_FLOAT64_C(-167720.34) },
       {  SIMDE_FLOAT64_C(203052.58), SIMDE_FLOAT64_C(-475421.32) } },
       {  SIMDE_FLOAT64_C(-417188.68), SIMDE_FLOAT64_C(-109291.82), SIMDE_FLOAT64_C(-140556.76)},
     { {  SIMDE_FLOAT64_C(-417188.68), SIMDE_FLOAT64_C(-165510.51) },
       {  SIMDE_FLOAT64_C(-109291.82), SIMDE_FLOAT64_C(-167720.34) },
       {  SIMDE_FLOAT64_C(-140556.76), SIMDE_FLOAT64_C(-475421.32) } } },
   { { {  SIMDE_FLOAT64_C(-480339.81), SIMDE_FLOAT64_C(-50482.68) },
       {  SIMDE_FLOAT64_C(214690.23), SIMDE_FLOAT64_C(242650.32) },
       {  SIMDE_FLOAT64_C(-234163.45), SIMDE_FLOAT64_C(-301439.99) } },
       {  SIMDE_FLOAT64_C(-402905.00), SIMDE_FLOAT64_C(-486035.94), SIMDE_FLOAT64_C(491188.01)},
     { {  SIMDE_FLOAT64_C(-480339.81), SIMDE_FLOAT64_C(-402905.00) },
       {  SIMDE_FLOAT64_C(214690.23), SIMDE_FLOAT64_C(-486035.94) },
       {  SIMDE_FLOAT64_C(-234163.45), SIMDE_FLOAT64_C(491188.01) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2x3_t r, src, expected;
    src.val[0] = simde_vld1q_f64(test_vec[i].src[0]);
    src.val[1] = simde_vld1q_f64(test_vec[i].src[1]);
    src.val[2] = simde_vld1q_f64(test_vec[i].src[2]);

    SIMDE_CONSTIFY_2_(simde_vld3q_lane_f64, r, (HEDLEY_UNREACHABLE(), r), i, test_vec[i].buf, src);

    expected.val[0] = simde_vld1q_f64(test_vec[i].r[0]);
    expected.val[1] = simde_vld1q_f64(test_vec[i].r[1]);
    expected.val[2] = simde_vld1q_f64(test_vec[i].r[2]);

    simde_test_arm_neon_assert_equal_f64x2(r.val[0], expected.val[0], INT_MAX);
    simde_test_arm_neon_assert_equal_f64x2(r.val[1], expected.val[1], INT_MAX);
    simde_test_arm_neon_assert_equal_f64x2(r.val[2], expected.val[2], INT_MAX);
  }

  return 0;

}

static int
test_simde_vld3_lane_p8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_poly8_t src[3][8];
    simde_poly8_t buf[3];
    simde_poly8_t r[3][8];
  } test_vec[] = {
   { { {  SIMDE_POLY8_C(75), SIMDE_POLY8_C(35), SIMDE_POLY8_C(26), SIMDE_POLY8_C(54),
        SIMDE_POLY8_C(1), SIMDE_POLY8_C(45), SIMDE_POLY8_C(13), SIMDE_POLY8_C(16) },
       {  SIMDE_POLY8_C(71), SIMDE_POLY8_C(47), SIMDE_POLY8_C(17), SIMDE_POLY8_C(80),
        SIMDE_POLY8_C(66), SIMDE_POLY8_C(34), SIMDE_POLY8_C(97), SIMDE_POLY8_C(20) },
       {  SIMDE_POLY8_C(41), SIMDE_POLY8_C(28), SIMDE_POLY8_C(70), SIMDE_POLY8_C(58),
        SIMDE_POLY8_C(81), SIMDE_POLY8_C(47), SIMDE_POLY8_C(7), SIMDE_POLY8_C(80) } },
       {  SIMDE_POLY8_C(92), SIMDE_POLY8_C(95), SIMDE_POLY8_C(50)},
     { {  SIMDE_POLY8_C(92), SIMDE_POLY8_C(35), SIMDE_POLY8_C(26), SIMDE_POLY8_C(54),
        SIMDE_POLY8_C(1), SIMDE_POLY8_C(45), SIMDE_POLY8_C(13), SIMDE_POLY8_C(16) },
       {  SIMDE_POLY8_C(95), SIMDE_POLY8_C(47), SIMDE_POLY8_C(17), SIMDE_POLY8_C(80),
        SIMDE_POLY8_C(66), SIMDE_POLY8_C(34), SIMDE_POLY8_C(97), SIMDE_POLY8_C(20) },
       {  SIMDE_POLY8_C(50), SIMDE_POLY8_C(28), SIMDE_POLY8_C(70), SIMDE_POLY8_C(58),
        SIMDE_POLY8_C(81), SIMDE_POLY8_C(47), SIMDE_POLY8_C(7), SIMDE_POLY8_C(80) } } },
   { { {  SIMDE_POLY8_C(42), SIMDE_POLY8_C(96), SIMDE_POLY8_C(15), SIMDE_POLY8_C(5),
        SIMDE_POLY8_C(54), SIMDE_POLY8_C(1), SIMDE_POLY8_C(68), SIMDE_POLY8_C(93) },
       {  SIMDE_POLY8_C(5), SIMDE_POLY8_C(62), SIMDE_POLY8_C(9), SIMDE_POLY8_C(30),
        SIMDE_POLY8_C(18), SIMDE_POLY8_C(45), SIMDE_POLY8_C(2), SIMDE_POLY8_C(28) },
       {  SIMDE_POLY8_C(65), SIMDE_POLY8_C(82), SIMDE_POLY8_C(30), SIMDE_POLY8_C(37),
        SIMDE_POLY8_C(18), SIMDE_POLY8_C(53), SIMDE_POLY8_C(59), SIMDE_POLY8_C(73) } },
       {  SIMDE_POLY8_C(45), SIMDE_POLY8_C(63), SIMDE_POLY8_C(47)},
     { {  SIMDE_POLY8_C(42), SIMDE_POLY8_C(45), SIMDE_POLY8_C(15), SIMDE_POLY8_C(5),
        SIMDE_POLY8_C(54), SIMDE_POLY8_C(1), SIMDE_POLY8_C(68), SIMDE_POLY8_C(93) },
       {  SIMDE_POLY8_C(5), SIMDE_POLY8_C(63), SIMDE_POLY8_C(9), SIMDE_POLY8_C(30),
        SIMDE_POLY8_C(18), SIMDE_POLY8_C(45), SIMDE_POLY8_C(2), SIMDE_POLY8_C(28) },
       {  SIMDE_POLY8_C(65), SIMDE_POLY8_C(47), SIMDE_POLY8_C(30), SIMDE_POLY8_C(37),
        SIMDE_POLY8_C(18), SIMDE_POLY8_C(53), SIMDE_POLY8_C(59), SIMDE_POLY8_C(73) } } },
   { { {  SIMDE_POLY8_C(5), SIMDE_POLY8_C(76), SIMDE_POLY8_C(80), SIMDE_POLY8_C(97),
        SIMDE_POLY8_C(33), SIMDE_POLY8_C(72), SIMDE_POLY8_C(43), SIMDE_POLY8_C(79) },
       {  SIMDE_POLY8_C(75), SIMDE_POLY8_C(82), SIMDE_POLY8_C(0), SIMDE_POLY8_C(67),
        SIMDE_POLY8_C(37), SIMDE_POLY8_C(5), SIMDE_POLY8_C(72), SIMDE_POLY8_C(27) },
       {  SIMDE_POLY8_C(1), SIMDE_POLY8_C(63), SIMDE_POLY8_C(20), SIMDE_POLY8_C(19),
        SIMDE_POLY8_C(83), SIMDE_POLY8_C(8), SIMDE_POLY8_C(44), SIMDE_POLY8_C(57) } },
       {  SIMDE_POLY8_C(63), SIMDE_POLY8_C(85), SIMDE_POLY8_C(98)},
     { {  SIMDE_POLY8_C(5), SIMDE_POLY8_C(76), SIMDE_POLY8_C(63), SIMDE_POLY8_C(97),
        SIMDE_POLY8_C(33), SIMDE_POLY8_C(72), SIMDE_POLY8_C(43), SIMDE_POLY8_C(79) },
       {  SIMDE_POLY8_C(75), SIMDE_POLY8_C(82), SIMDE_POLY8_C(85), SIMDE_POLY8_C(67),
        SIMDE_POLY8_C(37), SIMDE_POLY8_C(5), SIMDE_POLY8_C(72), SIMDE_POLY8_C(27) },
       {  SIMDE_POLY8_C(1), SIMDE_POLY8_C(63), SIMDE_POLY8_C(98), SIMDE_POLY8_C(19),
        SIMDE_POLY8_C(83), SIMDE_POLY8_C(8), SIMDE_POLY8_C(44), SIMDE_POLY8_C(57) } } },
   { { {  SIMDE_POLY8_C(72), SIMDE_POLY8_C(56), SIMDE_POLY8_C(65), SIMDE_POLY8_C(46),
        SIMDE_POLY8_C(4), SIMDE_POLY8_C(16), SIMDE_POLY8_C(78), SIMDE_POLY8_C(1) },
       {  SIMDE_POLY8_C(18), SIMDE_POLY8_C(48), SIMDE_POLY8_C(95), SIMDE_POLY8_C(22),
        SIMDE_POLY8_C(70), SIMDE_POLY8_C(44), SIMDE_POLY8_C(38), SIMDE_POLY8_C(3) },
       {  SIMDE_POLY8_C(23), SIMDE_POLY8_C(7), SIMDE_POLY8_C(81), SIMDE_POLY8_C(1),
        SIMDE_POLY8_C(25), SIMDE_POLY8_C(17), SIMDE_POLY8_C(17), SIMDE_POLY8_C(41) } },
       {  SIMDE_POLY8_C(60), SIMDE_POLY8_C(43), SIMDE_POLY8_C(32)},
     { {  SIMDE_POLY8_C(72), SIMDE_POLY8_C(56), SIMDE_POLY8_C(65), SIMDE_POLY8_C(60),
        SIMDE_POLY8_C(4), SIMDE_POLY8_C(16), SIMDE_POLY8_C(78), SIMDE_POLY8_C(1) },
       {  SIMDE_POLY8_C(18), SIMDE_POLY8_C(48), SIMDE_POLY8_C(95), SIMDE_POLY8_C(43),
        SIMDE_POLY8_C(70), SIMDE_POLY8_C(44), SIMDE_POLY8_C(38), SIMDE_POLY8_C(3) },
       {  SIMDE_POLY8_C(23), SIMDE_POLY8_C(7), SIMDE_POLY8_C(81), SIMDE_POLY8_C(32),
        SIMDE_POLY8_C(25), SIMDE_POLY8_C(17), SIMDE_POLY8_C(17), SIMDE_POLY8_C(41) } } },
   { { {  SIMDE_POLY8_C(90), SIMDE_POLY8_C(17), SIMDE_POLY8_C(65), SIMDE_POLY8_C(25),
        SIMDE_POLY8_C(72), SIMDE_POLY8_C(23), SIMDE_POLY8_C(54), SIMDE_POLY8_C(47) },
       {  SIMDE_POLY8_C(59), SIMDE_POLY8_C(82), SIMDE_POLY8_C(35), SIMDE_POLY8_C(91),
        SIMDE_POLY8_C(46), SIMDE_POLY8_C(26), SIMDE_POLY8_C(40), SIMDE_POLY8_C(79) },
       {  SIMDE_POLY8_C(73), SIMDE_POLY8_C(71), SIMDE_POLY8_C(80), SIMDE_POLY8_C(13),
        SIMDE_POLY8_C(88), SIMDE_POLY8_C(62), SIMDE_POLY8_C(41), SIMDE_POLY8_C(0) } },
       {  SIMDE_POLY8_C(86), SIMDE_POLY8_C(2), SIMDE_POLY8_C(23)},
     { {  SIMDE_POLY8_C(90), SIMDE_POLY8_C(17), SIMDE_POLY8_C(65), SIMDE_POLY8_C(25),
        SIMDE_POLY8_C(86), SIMDE_POLY8_C(23), SIMDE_POLY8_C(54), SIMDE_POLY8_C(47) },
       {  SIMDE_POLY8_C(59), SIMDE_POLY8_C(82), SIMDE_POLY8_C(35), SIMDE_POLY8_C(91),
        SIMDE_POLY8_C(2), SIMDE_POLY8_C(26), SIMDE_POLY8_C(40), SIMDE_POLY8_C(79) },
       {  SIMDE_POLY8_C(73), SIMDE_POLY8_C(71), SIMDE_POLY8_C(80), SIMDE_POLY8_C(13),
        SIMDE_POLY8_C(23), SIMDE_POLY8_C(62), SIMDE_POLY8_C(41), SIMDE_POLY8_C(0) } } },
   { { {  SIMDE_POLY8_C(9), SIMDE_POLY8_C(4), SIMDE_POLY8_C(48), SIMDE_POLY8_C(49),
        SIMDE_POLY8_C(13), SIMDE_POLY8_C(76), SIMDE_POLY8_C(28), SIMDE_POLY8_C(38) },
       {  SIMDE_POLY8_C(80), SIMDE_POLY8_C(15), SIMDE_POLY8_C(59), SIMDE_POLY8_C(29),
        SIMDE_POLY8_C(83), SIMDE_POLY8_C(69), SIMDE_POLY8_C(55), SIMDE_POLY8_C(2) },
       {  SIMDE_POLY8_C(12), SIMDE_POLY8_C(53), SIMDE_POLY8_C(98), SIMDE_POLY8_C(65),
        SIMDE_POLY8_C(68), SIMDE_POLY8_C(99), SIMDE_POLY8_C(58), SIMDE_POLY8_C(18) } },
       {  SIMDE_POLY8_C(49), SIMDE_POLY8_C(77), SIMDE_POLY8_C(71)},
     { {  SIMDE_POLY8_C(9), SIMDE_POLY8_C(4), SIMDE_POLY8_C(48), SIMDE_POLY8_C(49),
        SIMDE_POLY8_C(13), SIMDE_POLY8_C(49), SIMDE_POLY8_C(28), SIMDE_POLY8_C(38) },
       {  SIMDE_POLY8_C(80), SIMDE_POLY8_C(15), SIMDE_POLY8_C(59), SIMDE_POLY8_C(29),
        SIMDE_POLY8_C(83), SIMDE_POLY8_C(77), SIMDE_POLY8_C(55), SIMDE_POLY8_C(2) },
       {  SIMDE_POLY8_C(12), SIMDE_POLY8_C(53), SIMDE_POLY8_C(98), SIMDE_POLY8_C(65),
        SIMDE_POLY8_C(68), SIMDE_POLY8_C(71), SIMDE_POLY8_C(58), SIMDE_POLY8_C(18) } } },
   { { {  SIMDE_POLY8_C(21), SIMDE_POLY8_C(55), SIMDE_POLY8_C(12), SIMDE_POLY8_C(49),
        SIMDE_POLY8_C(97), SIMDE_POLY8_C(12), SIMDE_POLY8_C(16), SIMDE_POLY8_C(51) },
       {  SIMDE_POLY8_C(90), SIMDE_POLY8_C(34), SIMDE_POLY8_C(48), SIMDE_POLY8_C(61),
        SIMDE_POLY8_C(90), SIMDE_POLY8_C(4), SIMDE_POLY8_C(74), SIMDE_POLY8_C(53) },
       {  SIMDE_POLY8_C(44), SIMDE_POLY8_C(38), SIMDE_POLY8_C(5), SIMDE_POLY8_C(81),
        SIMDE_POLY8_C(71), SIMDE_POLY8_C(12), SIMDE_POLY8_C(0), SIMDE_POLY8_C(21) } },
       {  SIMDE_POLY8_C(61), SIMDE_POLY8_C(40), SIMDE_POLY8_C(87)},
     { {  SIMDE_POLY8_C(21), SIMDE_POLY8_C(55), SIMDE_POLY8_C(12), SIMDE_POLY8_C(49),
        SIMDE_POLY8_C(97), SIMDE_POLY8_C(12), SIMDE_POLY8_C(61), SIMDE_POLY8_C(51) },
       {  SIMDE_POLY8_C(90), SIMDE_POLY8_C(34), SIMDE_POLY8_C(48), SIMDE_POLY8_C(61),
        SIMDE_POLY8_C(90), SIMDE_POLY8_C(4), SIMDE_POLY8_C(40), SIMDE_POLY8_C(53) },
       {  SIMDE_POLY8_C(44), SIMDE_POLY8_C(38), SIMDE_POLY8_C(5), SIMDE_POLY8_C(81),
        SIMDE_POLY8_C(71), SIMDE_POLY8_C(12), SIMDE_POLY8_C(87), SIMDE_POLY8_C(21) } } },
   { { {  SIMDE_POLY8_C(95), SIMDE_POLY8_C(70), SIMDE_POLY8_C(79), SIMDE_POLY8_C(1),
        SIMDE_POLY8_C(27), SIMDE_POLY8_C(95), SIMDE_POLY8_C(83), SIMDE_POLY8_C(31) },
       {  SIMDE_POLY8_C(45), SIMDE_POLY8_C(24), SIMDE_POLY8_C(38), SIMDE_POLY8_C(76),
        SIMDE_POLY8_C(85), SIMDE_POLY8_C(61), SIMDE_POLY8_C(59), SIMDE_POLY8_C(71) },
       {  SIMDE_POLY8_C(7), SIMDE_POLY8_C(7), SIMDE_POLY8_C(22), SIMDE_POLY8_C(38),
        SIMDE_POLY8_C(73), SIMDE_POLY8_C(72), SIMDE_POLY8_C(79), SIMDE_POLY8_C(43) } },
       {  SIMDE_POLY8_C(9), SIMDE_POLY8_C(96), SIMDE_POLY8_C(17)},
     { {  SIMDE_POLY8_C(95), SIMDE_POLY8_C(70), SIMDE_POLY8_C(79), SIMDE_POLY8_C(1),
        SIMDE_POLY8_C(27), SIMDE_POLY8_C(95), SIMDE_POLY8_C(83), SIMDE_POLY8_C(9) },
       {  SIMDE_POLY8_C(45), SIMDE_POLY8_C(24), SIMDE_POLY8_C(38), SIMDE_POLY8_C(76),
        SIMDE_POLY8_C(85), SIMDE_POLY8_C(61), SIMDE_POLY8_C(59), SIMDE_POLY8_C(96) },
       {  SIMDE_POLY8_C(7), SIMDE_POLY8_C(7), SIMDE_POLY8_C(22), SIMDE_POLY8_C(38),
        SIMDE_POLY8_C(73), SIMDE_POLY8_C(72), SIMDE_POLY8_C(79), SIMDE_POLY8_C(17) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_poly8x8x3_t r, src, expected;
    src.val[0] = simde_vld1_p8(test_vec[i].src[0]);
    src.val[1] = simde_vld1_p8(test_vec[i].src[1]);
    src.val[2] = simde_vld1_p8(test_vec[i].src[2]);

    SIMDE_CONSTIFY_8_(simde_vld3_lane_p8, r, (HEDLEY_UNREACHABLE(), r), i, test_vec[i].buf, src);

    expected.val[0] = simde_vld1_p8(test_vec[i].r[0]);
    expected.val[1] = simde_vld1_p8(test_vec[i].r[1]);
    expected.val[2] = simde_vld1_p8(test_vec[i].r[2]);

    simde_test_arm_neon_assert_equal_p8x8(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_p8x8(r.val[1], expected.val[1]);
    simde_test_arm_neon_assert_equal_p8x8(r.val[2], expected.val[2]);
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_poly8x8x3_t src = simde_test_arm_neon_random_p8x8x3();
    simde_poly8_t buf[3];
    simde_poly8x8x3_t r;
    simde_test_arm_neon_write_p8x8x3(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_random_memory(3, HEDLEY_REINTERPRET_CAST(uint8_t*, buf));
    simde_test_codegen_write_vp8(2, 3, buf, SIMDE_TEST_VEC_POS_MIDDLE);
    SIMDE_CONSTIFY_8_(simde_vld3_lane_p8, r, (HEDLEY_UNREACHABLE(), r), i, buf, src);
    simde_test_arm_neon_write_p8x8x3(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld3_lane_p16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_poly16_t src[3][4];
    simde_poly16_t buf[3];
    simde_poly16_t r[3][4];
  } test_vec[] = {
   { { {  SIMDE_POLY16_C(6015), SIMDE_POLY16_C(2114), SIMDE_POLY16_C(9985), SIMDE_POLY16_C(6732) },
       {  SIMDE_POLY16_C(8774), SIMDE_POLY16_C(5943), SIMDE_POLY16_C(9952), SIMDE_POLY16_C(6251) },
       {  SIMDE_POLY16_C(7677), SIMDE_POLY16_C(4431), SIMDE_POLY16_C(8936), SIMDE_POLY16_C(5217) } },
       {  SIMDE_POLY16_C(6123), SIMDE_POLY16_C(8122), SIMDE_POLY16_C(6028)},
     { {  SIMDE_POLY16_C(6123), SIMDE_POLY16_C(2114), SIMDE_POLY16_C(9985), SIMDE_POLY16_C(6732) },
       {  SIMDE_POLY16_C(8122), SIMDE_POLY16_C(5943), SIMDE_POLY16_C(9952), SIMDE_POLY16_C(6251) },
       {  SIMDE_POLY16_C(6028), SIMDE_POLY16_C(4431), SIMDE_POLY16_C(8936), SIMDE_POLY16_C(5217) } } },
   { { {  SIMDE_POLY16_C(1502), SIMDE_POLY16_C(4900), SIMDE_POLY16_C(3595), SIMDE_POLY16_C(5262) },
       {  SIMDE_POLY16_C(8144), SIMDE_POLY16_C(1060), SIMDE_POLY16_C(6932), SIMDE_POLY16_C(5912) },
       {  SIMDE_POLY16_C(6252), SIMDE_POLY16_C(4564), SIMDE_POLY16_C(7952), SIMDE_POLY16_C(4773) } },
       {  SIMDE_POLY16_C(8849), SIMDE_POLY16_C(6285), SIMDE_POLY16_C(845)},
     { {  SIMDE_POLY16_C(1502), SIMDE_POLY16_C(8849), SIMDE_POLY16_C(3595), SIMDE_POLY16_C(5262) },
       {  SIMDE_POLY16_C(8144), SIMDE_POLY16_C(6285), SIMDE_POLY16_C(6932), SIMDE_POLY16_C(5912) },
       {  SIMDE_POLY16_C(6252), SIMDE_POLY16_C(845), SIMDE_POLY16_C(7952), SIMDE_POLY16_C(4773) } } },
   { { {  SIMDE_POLY16_C(8789), SIMDE_POLY16_C(6109), SIMDE_POLY16_C(2590), SIMDE_POLY16_C(503) },
       {  SIMDE_POLY16_C(5135), SIMDE_POLY16_C(1328), SIMDE_POLY16_C(5106), SIMDE_POLY16_C(3566) },
       {  SIMDE_POLY16_C(6125), SIMDE_POLY16_C(5630), SIMDE_POLY16_C(1661), SIMDE_POLY16_C(5502) } },
       {  SIMDE_POLY16_C(7329), SIMDE_POLY16_C(958), SIMDE_POLY16_C(9522)},
     { {  SIMDE_POLY16_C(8789), SIMDE_POLY16_C(6109), SIMDE_POLY16_C(7329), SIMDE_POLY16_C(503) },
       {  SIMDE_POLY16_C(5135), SIMDE_POLY16_C(1328), SIMDE_POLY16_C(958), SIMDE_POLY16_C(3566) },
       {  SIMDE_POLY16_C(6125), SIMDE_POLY16_C(5630), SIMDE_POLY16_C(9522), SIMDE_POLY16_C(5502) } } },
   { { {  SIMDE_POLY16_C(237), SIMDE_POLY16_C(4662), SIMDE_POLY16_C(2239), SIMDE_POLY16_C(7486) },
       {  SIMDE_POLY16_C(9269), SIMDE_POLY16_C(4261), SIMDE_POLY16_C(1015), SIMDE_POLY16_C(4021) },
       {  SIMDE_POLY16_C(8255), SIMDE_POLY16_C(239), SIMDE_POLY16_C(9693), SIMDE_POLY16_C(2843) } },
       {  SIMDE_POLY16_C(2785), SIMDE_POLY16_C(9518), SIMDE_POLY16_C(5622)},
     { {  SIMDE_POLY16_C(237), SIMDE_POLY16_C(4662), SIMDE_POLY16_C(2239), SIMDE_POLY16_C(2785) },
       {  SIMDE_POLY16_C(9269), SIMDE_POLY16_C(4261), SIMDE_POLY16_C(1015), SIMDE_POLY16_C(9518) },
       {  SIMDE_POLY16_C(8255), SIMDE_POLY16_C(239), SIMDE_POLY16_C(9693), SIMDE_POLY16_C(5622) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_poly16x4x3_t r, src, expected;
    src.val[0] = simde_vld1_p16(test_vec[i].src[0]);
    src.val[1] = simde_vld1_p16(test_vec[i].src[1]);
    src.val[2] = simde_vld1_p16(test_vec[i].src[2]);

    SIMDE_CONSTIFY_4_(simde_vld3_lane_p16, r, (HEDLEY_UNREACHABLE(), r), i, test_vec[i].buf, src);

    expected.val[0] = simde_vld1_p16(test_vec[i].r[0]);
    expected.val[1] = simde_vld1_p16(test_vec[i].r[1]);
    expected.val[2] = simde_vld1_p16(test_vec[i].r[2]);

    simde_test_arm_neon_assert_equal_p16x4(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_p16x4(r.val[1], expected.val[1]);
    simde_test_arm_neon_assert_equal_p16x4(r.val[2], expected.val[2]);
  }

  return 0;
#else
  for (int i = 0 ; i < 4 ; i++) {
    simde_poly16x4x3_t src = simde_test_arm_neon_random_p16x4x3();
    simde_poly16_t buf[3];
    simde_poly16x4x3_t r;
    simde_test_arm_neon_write_p16x4x3(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_random_memory(6, HEDLEY_REINTERPRET_CAST(uint8_t*, buf));
    simde_test_codegen_write_vp16(2, 3, buf, SIMDE_TEST_VEC_POS_MIDDLE);
    SIMDE_CONSTIFY_4_(simde_vld3_lane_p16, r, (HEDLEY_UNREACHABLE(), r), i, buf, src);
    simde_test_arm_neon_write_p16x4x3(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld3_lane_p64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_poly64_t src[3][1];
    simde_poly64_t buf[3];
    simde_poly64_t r[3][1];
  } test_vec[] = {
   { { {  SIMDE_POLY64_C(54243463) },
       {  SIMDE_POLY64_C(32138549) },
       {  SIMDE_POLY64_C(65147451) } },
       {  SIMDE_POLY64_C(36001229), SIMDE_POLY64_C(4492888), SIMDE_POLY64_C(79288036)},
     { {  SIMDE_POLY64_C(36001229) },
       {  SIMDE_POLY64_C(4492888) },
       {  SIMDE_POLY64_C(79288036) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_poly64x1x3_t r, src, expected;
    src.val[0] = simde_vld1_p64(test_vec[i].src[0]);
    src.val[1] = simde_vld1_p64(test_vec[i].src[1]);
    src.val[2] = simde_vld1_p64(test_vec[i].src[2]);

    r = simde_vld3_lane_p64(test_vec[i].buf, src, 0);

    expected.val[0] = simde_vld1_p64(test_vec[i].r[0]);
    expected.val[1] = simde_vld1_p64(test_vec[i].r[1]);
    expected.val[2] = simde_vld1_p64(test_vec[i].r[2]);

    simde_test_arm_neon_assert_equal_p64x1(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_p64x1(r.val[1], expected.val[1]);
    simde_test_arm_neon_assert_equal_p64x1(r.val[2], expected.val[2]);
  }

  return 0;
#else
  for (int i = 0 ; i < 4 ; i++) {
    simde_poly64x1x3_t src = simde_test_arm_neon_random_p64x1x3();
    simde_poly64_t buf[3];
    simde_poly64x1x3_t r;
    simde_test_arm_neon_write_p64x1x3(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_random_memory(24, HEDLEY_REINTERPRET_CAST(uint8_t*, buf));
    simde_test_codegen_write_vp64(2, 3, buf, SIMDE_TEST_VEC_POS_MIDDLE);
    r = simde_vld3_lane_p64(buf, src, 0);
    simde_test_arm_neon_write_p64x1x3(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld3q_lane_p8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_poly8_t src[3][16];
    simde_poly8_t buf[3];
    simde_poly8_t r[3][16];
  } test_vec[] = {
   { { {  SIMDE_POLY8_C(97), SIMDE_POLY8_C(34), SIMDE_POLY8_C(43), SIMDE_POLY8_C(79), SIMDE_POLY8_C(40), SIMDE_POLY8_C(28), SIMDE_POLY8_C(65), SIMDE_POLY8_C(74),
        SIMDE_POLY8_C(9), SIMDE_POLY8_C(3), SIMDE_POLY8_C(91), SIMDE_POLY8_C(11), SIMDE_POLY8_C(64), SIMDE_POLY8_C(46), SIMDE_POLY8_C(68), SIMDE_POLY8_C(53) },
       {  SIMDE_POLY8_C(42), SIMDE_POLY8_C(29), SIMDE_POLY8_C(58), SIMDE_POLY8_C(95), SIMDE_POLY8_C(50), SIMDE_POLY8_C(75), SIMDE_POLY8_C(26), SIMDE_POLY8_C(66),
        SIMDE_POLY8_C(71), SIMDE_POLY8_C(45), SIMDE_POLY8_C(14), SIMDE_POLY8_C(13), SIMDE_POLY8_C(88), SIMDE_POLY8_C(66), SIMDE_POLY8_C(0), SIMDE_POLY8_C(95) },
       {  SIMDE_POLY8_C(86), SIMDE_POLY8_C(19), SIMDE_POLY8_C(63), SIMDE_POLY8_C(41), SIMDE_POLY8_C(94), SIMDE_POLY8_C(31), SIMDE_POLY8_C(1), SIMDE_POLY8_C(67),
        SIMDE_POLY8_C(85), SIMDE_POLY8_C(10), SIMDE_POLY8_C(21), SIMDE_POLY8_C(61), SIMDE_POLY8_C(99), SIMDE_POLY8_C(54), SIMDE_POLY8_C(88), SIMDE_POLY8_C(96) } },
       {  SIMDE_POLY8_C(74), SIMDE_POLY8_C(52), SIMDE_POLY8_C(78)},
     { {  SIMDE_POLY8_C(74), SIMDE_POLY8_C(34), SIMDE_POLY8_C(43), SIMDE_POLY8_C(79), SIMDE_POLY8_C(40), SIMDE_POLY8_C(28), SIMDE_POLY8_C(65), SIMDE_POLY8_C(74),
        SIMDE_POLY8_C(9), SIMDE_POLY8_C(3), SIMDE_POLY8_C(91), SIMDE_POLY8_C(11), SIMDE_POLY8_C(64), SIMDE_POLY8_C(46), SIMDE_POLY8_C(68), SIMDE_POLY8_C(53) },
       {  SIMDE_POLY8_C(52), SIMDE_POLY8_C(29), SIMDE_POLY8_C(58), SIMDE_POLY8_C(95), SIMDE_POLY8_C(50), SIMDE_POLY8_C(75), SIMDE_POLY8_C(26), SIMDE_POLY8_C(66),
        SIMDE_POLY8_C(71), SIMDE_POLY8_C(45), SIMDE_POLY8_C(14), SIMDE_POLY8_C(13), SIMDE_POLY8_C(88), SIMDE_POLY8_C(66), SIMDE_POLY8_C(0), SIMDE_POLY8_C(95) },
       {  SIMDE_POLY8_C(78), SIMDE_POLY8_C(19), SIMDE_POLY8_C(63), SIMDE_POLY8_C(41), SIMDE_POLY8_C(94), SIMDE_POLY8_C(31), SIMDE_POLY8_C(1), SIMDE_POLY8_C(67),
        SIMDE_POLY8_C(85), SIMDE_POLY8_C(10), SIMDE_POLY8_C(21), SIMDE_POLY8_C(61), SIMDE_POLY8_C(99), SIMDE_POLY8_C(54), SIMDE_POLY8_C(88), SIMDE_POLY8_C(96) } } },
   { { {  SIMDE_POLY8_C(9), SIMDE_POLY8_C(1), SIMDE_POLY8_C(56), SIMDE_POLY8_C(58), SIMDE_POLY8_C(80), SIMDE_POLY8_C(56), SIMDE_POLY8_C(18), SIMDE_POLY8_C(35),
        SIMDE_POLY8_C(9), SIMDE_POLY8_C(71), SIMDE_POLY8_C(43), SIMDE_POLY8_C(36), SIMDE_POLY8_C(32), SIMDE_POLY8_C(11), SIMDE_POLY8_C(67), SIMDE_POLY8_C(53) },
       {  SIMDE_POLY8_C(6), SIMDE_POLY8_C(75), SIMDE_POLY8_C(57), SIMDE_POLY8_C(21), SIMDE_POLY8_C(70), SIMDE_POLY8_C(8), SIMDE_POLY8_C(57), SIMDE_POLY8_C(52),
        SIMDE_POLY8_C(52), SIMDE_POLY8_C(0), SIMDE_POLY8_C(40), SIMDE_POLY8_C(87), SIMDE_POLY8_C(92), SIMDE_POLY8_C(18), SIMDE_POLY8_C(24), SIMDE_POLY8_C(32) },
       {  SIMDE_POLY8_C(33), SIMDE_POLY8_C(9), SIMDE_POLY8_C(18), SIMDE_POLY8_C(75), SIMDE_POLY8_C(35), SIMDE_POLY8_C(76), SIMDE_POLY8_C(99), SIMDE_POLY8_C(66),
        SIMDE_POLY8_C(40), SIMDE_POLY8_C(47), SIMDE_POLY8_C(2), SIMDE_POLY8_C(94), SIMDE_POLY8_C(66), SIMDE_POLY8_C(80), SIMDE_POLY8_C(73), SIMDE_POLY8_C(10) } },
       {  SIMDE_POLY8_C(68), SIMDE_POLY8_C(58), SIMDE_POLY8_C(68)},
     { {  SIMDE_POLY8_C(9), SIMDE_POLY8_C(68), SIMDE_POLY8_C(56), SIMDE_POLY8_C(58), SIMDE_POLY8_C(80), SIMDE_POLY8_C(56), SIMDE_POLY8_C(18), SIMDE_POLY8_C(35),
        SIMDE_POLY8_C(9), SIMDE_POLY8_C(71), SIMDE_POLY8_C(43), SIMDE_POLY8_C(36), SIMDE_POLY8_C(32), SIMDE_POLY8_C(11), SIMDE_POLY8_C(67), SIMDE_POLY8_C(53) },
       {  SIMDE_POLY8_C(6), SIMDE_POLY8_C(58), SIMDE_POLY8_C(57), SIMDE_POLY8_C(21), SIMDE_POLY8_C(70), SIMDE_POLY8_C(8), SIMDE_POLY8_C(57), SIMDE_POLY8_C(52),
        SIMDE_POLY8_C(52), SIMDE_POLY8_C(0), SIMDE_POLY8_C(40), SIMDE_POLY8_C(87), SIMDE_POLY8_C(92), SIMDE_POLY8_C(18), SIMDE_POLY8_C(24), SIMDE_POLY8_C(32) },
       {  SIMDE_POLY8_C(33), SIMDE_POLY8_C(68), SIMDE_POLY8_C(18), SIMDE_POLY8_C(75), SIMDE_POLY8_C(35), SIMDE_POLY8_C(76), SIMDE_POLY8_C(99), SIMDE_POLY8_C(66),
        SIMDE_POLY8_C(40), SIMDE_POLY8_C(47), SIMDE_POLY8_C(2), SIMDE_POLY8_C(94), SIMDE_POLY8_C(66), SIMDE_POLY8_C(80), SIMDE_POLY8_C(73), SIMDE_POLY8_C(10) } } },
   { { {  SIMDE_POLY8_C(50), SIMDE_POLY8_C(10), SIMDE_POLY8_C(1), SIMDE_POLY8_C(90), SIMDE_POLY8_C(50), SIMDE_POLY8_C(47), SIMDE_POLY8_C(86), SIMDE_POLY8_C(81),
        SIMDE_POLY8_C(61), SIMDE_POLY8_C(7), SIMDE_POLY8_C(95), SIMDE_POLY8_C(60), SIMDE_POLY8_C(48), SIMDE_POLY8_C(8), SIMDE_POLY8_C(31), SIMDE_POLY8_C(91) },
       {  SIMDE_POLY8_C(73), SIMDE_POLY8_C(83), SIMDE_POLY8_C(76), SIMDE_POLY8_C(91), SIMDE_POLY8_C(19), SIMDE_POLY8_C(85), SIMDE_POLY8_C(38), SIMDE_POLY8_C(82),
        SIMDE_POLY8_C(27), SIMDE_POLY8_C(82), SIMDE_POLY8_C(46), SIMDE_POLY8_C(65), SIMDE_POLY8_C(68), SIMDE_POLY8_C(68), SIMDE_POLY8_C(33), SIMDE_POLY8_C(1) },
       {  SIMDE_POLY8_C(47), SIMDE_POLY8_C(15), SIMDE_POLY8_C(55), SIMDE_POLY8_C(34), SIMDE_POLY8_C(74), SIMDE_POLY8_C(43), SIMDE_POLY8_C(84), SIMDE_POLY8_C(10),
        SIMDE_POLY8_C(28), SIMDE_POLY8_C(68), SIMDE_POLY8_C(63), SIMDE_POLY8_C(97), SIMDE_POLY8_C(77), SIMDE_POLY8_C(44), SIMDE_POLY8_C(2), SIMDE_POLY8_C(12) } },
       {  SIMDE_POLY8_C(36), SIMDE_POLY8_C(31), SIMDE_POLY8_C(75)},
     { {  SIMDE_POLY8_C(50), SIMDE_POLY8_C(10), SIMDE_POLY8_C(36), SIMDE_POLY8_C(90), SIMDE_POLY8_C(50), SIMDE_POLY8_C(47), SIMDE_POLY8_C(86), SIMDE_POLY8_C(81),
        SIMDE_POLY8_C(61), SIMDE_POLY8_C(7), SIMDE_POLY8_C(95), SIMDE_POLY8_C(60), SIMDE_POLY8_C(48), SIMDE_POLY8_C(8), SIMDE_POLY8_C(31), SIMDE_POLY8_C(91) },
       {  SIMDE_POLY8_C(73), SIMDE_POLY8_C(83), SIMDE_POLY8_C(31), SIMDE_POLY8_C(91), SIMDE_POLY8_C(19), SIMDE_POLY8_C(85), SIMDE_POLY8_C(38), SIMDE_POLY8_C(82),
        SIMDE_POLY8_C(27), SIMDE_POLY8_C(82), SIMDE_POLY8_C(46), SIMDE_POLY8_C(65), SIMDE_POLY8_C(68), SIMDE_POLY8_C(68), SIMDE_POLY8_C(33), SIMDE_POLY8_C(1) },
       {  SIMDE_POLY8_C(47), SIMDE_POLY8_C(15), SIMDE_POLY8_C(75), SIMDE_POLY8_C(34), SIMDE_POLY8_C(74), SIMDE_POLY8_C(43), SIMDE_POLY8_C(84), SIMDE_POLY8_C(10),
        SIMDE_POLY8_C(28), SIMDE_POLY8_C(68), SIMDE_POLY8_C(63), SIMDE_POLY8_C(97), SIMDE_POLY8_C(77), SIMDE_POLY8_C(44), SIMDE_POLY8_C(2), SIMDE_POLY8_C(12) } } },
   { { {  SIMDE_POLY8_C(47), SIMDE_POLY8_C(52), SIMDE_POLY8_C(57), SIMDE_POLY8_C(40), SIMDE_POLY8_C(37), SIMDE_POLY8_C(25), SIMDE_POLY8_C(31), SIMDE_POLY8_C(34),
        SIMDE_POLY8_C(59), SIMDE_POLY8_C(77), SIMDE_POLY8_C(97), SIMDE_POLY8_C(42), SIMDE_POLY8_C(81), SIMDE_POLY8_C(31), SIMDE_POLY8_C(72), SIMDE_POLY8_C(79) },
       {  SIMDE_POLY8_C(34), SIMDE_POLY8_C(27), SIMDE_POLY8_C(19), SIMDE_POLY8_C(64), SIMDE_POLY8_C(15), SIMDE_POLY8_C(17), SIMDE_POLY8_C(15), SIMDE_POLY8_C(47),
        SIMDE_POLY8_C(63), SIMDE_POLY8_C(27), SIMDE_POLY8_C(7), SIMDE_POLY8_C(9), SIMDE_POLY8_C(63), SIMDE_POLY8_C(44), SIMDE_POLY8_C(81), SIMDE_POLY8_C(91) },
       {  SIMDE_POLY8_C(54), SIMDE_POLY8_C(66), SIMDE_POLY8_C(39), SIMDE_POLY8_C(9), SIMDE_POLY8_C(19), SIMDE_POLY8_C(4), SIMDE_POLY8_C(56), SIMDE_POLY8_C(13),
        SIMDE_POLY8_C(45), SIMDE_POLY8_C(91), SIMDE_POLY8_C(74), SIMDE_POLY8_C(85), SIMDE_POLY8_C(70), SIMDE_POLY8_C(79), SIMDE_POLY8_C(65), SIMDE_POLY8_C(66) } },
       {  SIMDE_POLY8_C(92), SIMDE_POLY8_C(78), SIMDE_POLY8_C(33)},
     { {  SIMDE_POLY8_C(47), SIMDE_POLY8_C(52), SIMDE_POLY8_C(57), SIMDE_POLY8_C(92), SIMDE_POLY8_C(37), SIMDE_POLY8_C(25), SIMDE_POLY8_C(31), SIMDE_POLY8_C(34),
        SIMDE_POLY8_C(59), SIMDE_POLY8_C(77), SIMDE_POLY8_C(97), SIMDE_POLY8_C(42), SIMDE_POLY8_C(81), SIMDE_POLY8_C(31), SIMDE_POLY8_C(72), SIMDE_POLY8_C(79) },
       {  SIMDE_POLY8_C(34), SIMDE_POLY8_C(27), SIMDE_POLY8_C(19), SIMDE_POLY8_C(78), SIMDE_POLY8_C(15), SIMDE_POLY8_C(17), SIMDE_POLY8_C(15), SIMDE_POLY8_C(47),
        SIMDE_POLY8_C(63), SIMDE_POLY8_C(27), SIMDE_POLY8_C(7), SIMDE_POLY8_C(9), SIMDE_POLY8_C(63), SIMDE_POLY8_C(44), SIMDE_POLY8_C(81), SIMDE_POLY8_C(91) },
       {  SIMDE_POLY8_C(54), SIMDE_POLY8_C(66), SIMDE_POLY8_C(39), SIMDE_POLY8_C(33), SIMDE_POLY8_C(19), SIMDE_POLY8_C(4), SIMDE_POLY8_C(56), SIMDE_POLY8_C(13),
        SIMDE_POLY8_C(45), SIMDE_POLY8_C(91), SIMDE_POLY8_C(74), SIMDE_POLY8_C(85), SIMDE_POLY8_C(70), SIMDE_POLY8_C(79), SIMDE_POLY8_C(65), SIMDE_POLY8_C(66) } } },
   { { {  SIMDE_POLY8_C(41), SIMDE_POLY8_C(0), SIMDE_POLY8_C(13), SIMDE_POLY8_C(21), SIMDE_POLY8_C(14), SIMDE_POLY8_C(99), SIMDE_POLY8_C(7), SIMDE_POLY8_C(41),
        SIMDE_POLY8_C(65), SIMDE_POLY8_C(42), SIMDE_POLY8_C(70), SIMDE_POLY8_C(7), SIMDE_POLY8_C(31), SIMDE_POLY8_C(6), SIMDE_POLY8_C(57), SIMDE_POLY8_C(25) },
       {  SIMDE_POLY8_C(89), SIMDE_POLY8_C(11), SIMDE_POLY8_C(40), SIMDE_POLY8_C(22), SIMDE_POLY8_C(75), SIMDE_POLY8_C(80), SIMDE_POLY8_C(72), SIMDE_POLY8_C(0),
        SIMDE_POLY8_C(12), SIMDE_POLY8_C(0), SIMDE_POLY8_C(29), SIMDE_POLY8_C(77), SIMDE_POLY8_C(83), SIMDE_POLY8_C(2), SIMDE_POLY8_C(22), SIMDE_POLY8_C(53) },
       {  SIMDE_POLY8_C(82), SIMDE_POLY8_C(8), SIMDE_POLY8_C(33), SIMDE_POLY8_C(81), SIMDE_POLY8_C(96), SIMDE_POLY8_C(37), SIMDE_POLY8_C(91), SIMDE_POLY8_C(76),
        SIMDE_POLY8_C(39), SIMDE_POLY8_C(58), SIMDE_POLY8_C(73), SIMDE_POLY8_C(97), SIMDE_POLY8_C(11), SIMDE_POLY8_C(15), SIMDE_POLY8_C(21), SIMDE_POLY8_C(99) } },
       {  SIMDE_POLY8_C(96), SIMDE_POLY8_C(62), SIMDE_POLY8_C(14)},
     { {  SIMDE_POLY8_C(41), SIMDE_POLY8_C(0), SIMDE_POLY8_C(13), SIMDE_POLY8_C(21), SIMDE_POLY8_C(96), SIMDE_POLY8_C(99), SIMDE_POLY8_C(7), SIMDE_POLY8_C(41),
        SIMDE_POLY8_C(65), SIMDE_POLY8_C(42), SIMDE_POLY8_C(70), SIMDE_POLY8_C(7), SIMDE_POLY8_C(31), SIMDE_POLY8_C(6), SIMDE_POLY8_C(57), SIMDE_POLY8_C(25) },
       {  SIMDE_POLY8_C(89), SIMDE_POLY8_C(11), SIMDE_POLY8_C(40), SIMDE_POLY8_C(22), SIMDE_POLY8_C(62), SIMDE_POLY8_C(80), SIMDE_POLY8_C(72), SIMDE_POLY8_C(0),
        SIMDE_POLY8_C(12), SIMDE_POLY8_C(0), SIMDE_POLY8_C(29), SIMDE_POLY8_C(77), SIMDE_POLY8_C(83), SIMDE_POLY8_C(2), SIMDE_POLY8_C(22), SIMDE_POLY8_C(53) },
       {  SIMDE_POLY8_C(82), SIMDE_POLY8_C(8), SIMDE_POLY8_C(33), SIMDE_POLY8_C(81), SIMDE_POLY8_C(14), SIMDE_POLY8_C(37), SIMDE_POLY8_C(91), SIMDE_POLY8_C(76),
        SIMDE_POLY8_C(39), SIMDE_POLY8_C(58), SIMDE_POLY8_C(73), SIMDE_POLY8_C(97), SIMDE_POLY8_C(11), SIMDE_POLY8_C(15), SIMDE_POLY8_C(21), SIMDE_POLY8_C(99) } } },
   { { {  SIMDE_POLY8_C(20), SIMDE_POLY8_C(41), SIMDE_POLY8_C(29), SIMDE_POLY8_C(44), SIMDE_POLY8_C(67), SIMDE_POLY8_C(37), SIMDE_POLY8_C(87), SIMDE_POLY8_C(42),
        SIMDE_POLY8_C(73), SIMDE_POLY8_C(62), SIMDE_POLY8_C(94), SIMDE_POLY8_C(35), SIMDE_POLY8_C(12), SIMDE_POLY8_C(53), SIMDE_POLY8_C(34), SIMDE_POLY8_C(89) },
       {  SIMDE_POLY8_C(64), SIMDE_POLY8_C(49), SIMDE_POLY8_C(36), SIMDE_POLY8_C(14), SIMDE_POLY8_C(32), SIMDE_POLY8_C(10), SIMDE_POLY8_C(2), SIMDE_POLY8_C(82),
        SIMDE_POLY8_C(64), SIMDE_POLY8_C(73), SIMDE_POLY8_C(51), SIMDE_POLY8_C(96), SIMDE_POLY8_C(23), SIMDE_POLY8_C(75), SIMDE_POLY8_C(27), SIMDE_POLY8_C(25) },
       {  SIMDE_POLY8_C(24), SIMDE_POLY8_C(87), SIMDE_POLY8_C(35), SIMDE_POLY8_C(68), SIMDE_POLY8_C(68), SIMDE_POLY8_C(9), SIMDE_POLY8_C(10), SIMDE_POLY8_C(17),
        SIMDE_POLY8_C(20), SIMDE_POLY8_C(88), SIMDE_POLY8_C(79), SIMDE_POLY8_C(13), SIMDE_POLY8_C(53), SIMDE_POLY8_C(99), SIMDE_POLY8_C(83), SIMDE_POLY8_C(9) } },
       {  SIMDE_POLY8_C(87), SIMDE_POLY8_C(65), SIMDE_POLY8_C(37)},
     { {  SIMDE_POLY8_C(20), SIMDE_POLY8_C(41), SIMDE_POLY8_C(29), SIMDE_POLY8_C(44), SIMDE_POLY8_C(67), SIMDE_POLY8_C(87), SIMDE_POLY8_C(87), SIMDE_POLY8_C(42),
        SIMDE_POLY8_C(73), SIMDE_POLY8_C(62), SIMDE_POLY8_C(94), SIMDE_POLY8_C(35), SIMDE_POLY8_C(12), SIMDE_POLY8_C(53), SIMDE_POLY8_C(34), SIMDE_POLY8_C(89) },
       {  SIMDE_POLY8_C(64), SIMDE_POLY8_C(49), SIMDE_POLY8_C(36), SIMDE_POLY8_C(14), SIMDE_POLY8_C(32), SIMDE_POLY8_C(65), SIMDE_POLY8_C(2), SIMDE_POLY8_C(82),
        SIMDE_POLY8_C(64), SIMDE_POLY8_C(73), SIMDE_POLY8_C(51), SIMDE_POLY8_C(96), SIMDE_POLY8_C(23), SIMDE_POLY8_C(75), SIMDE_POLY8_C(27), SIMDE_POLY8_C(25) },
       {  SIMDE_POLY8_C(24), SIMDE_POLY8_C(87), SIMDE_POLY8_C(35), SIMDE_POLY8_C(68), SIMDE_POLY8_C(68), SIMDE_POLY8_C(37), SIMDE_POLY8_C(10), SIMDE_POLY8_C(17),
        SIMDE_POLY8_C(20), SIMDE_POLY8_C(88), SIMDE_POLY8_C(79), SIMDE_POLY8_C(13), SIMDE_POLY8_C(53), SIMDE_POLY8_C(99), SIMDE_POLY8_C(83), SIMDE_POLY8_C(9) } } },
   { { {  SIMDE_POLY8_C(98), SIMDE_POLY8_C(75), SIMDE_POLY8_C(1), SIMDE_POLY8_C(3), SIMDE_POLY8_C(9), SIMDE_POLY8_C(61), SIMDE_POLY8_C(91), SIMDE_POLY8_C(69),
        SIMDE_POLY8_C(75), SIMDE_POLY8_C(22), SIMDE_POLY8_C(77), SIMDE_POLY8_C(29), SIMDE_POLY8_C(2), SIMDE_POLY8_C(8), SIMDE_POLY8_C(96), SIMDE_POLY8_C(52) },
       {  SIMDE_POLY8_C(35), SIMDE_POLY8_C(65), SIMDE_POLY8_C(32), SIMDE_POLY8_C(16), SIMDE_POLY8_C(62), SIMDE_POLY8_C(3), SIMDE_POLY8_C(91), SIMDE_POLY8_C(38),
        SIMDE_POLY8_C(42), SIMDE_POLY8_C(23), SIMDE_POLY8_C(81), SIMDE_POLY8_C(61), SIMDE_POLY8_C(28), SIMDE_POLY8_C(1), SIMDE_POLY8_C(5), SIMDE_POLY8_C(84) },
       {  SIMDE_POLY8_C(45), SIMDE_POLY8_C(87), SIMDE_POLY8_C(52), SIMDE_POLY8_C(74), SIMDE_POLY8_C(83), SIMDE_POLY8_C(48), SIMDE_POLY8_C(17), SIMDE_POLY8_C(96),
        SIMDE_POLY8_C(48), SIMDE_POLY8_C(82), SIMDE_POLY8_C(56), SIMDE_POLY8_C(23), SIMDE_POLY8_C(23), SIMDE_POLY8_C(52), SIMDE_POLY8_C(69), SIMDE_POLY8_C(57) } },
       {  SIMDE_POLY8_C(89), SIMDE_POLY8_C(29), SIMDE_POLY8_C(27)},
     { {  SIMDE_POLY8_C(98), SIMDE_POLY8_C(75), SIMDE_POLY8_C(1), SIMDE_POLY8_C(3), SIMDE_POLY8_C(9), SIMDE_POLY8_C(61), SIMDE_POLY8_C(89), SIMDE_POLY8_C(69),
        SIMDE_POLY8_C(75), SIMDE_POLY8_C(22), SIMDE_POLY8_C(77), SIMDE_POLY8_C(29), SIMDE_POLY8_C(2), SIMDE_POLY8_C(8), SIMDE_POLY8_C(96), SIMDE_POLY8_C(52) },
       {  SIMDE_POLY8_C(35), SIMDE_POLY8_C(65), SIMDE_POLY8_C(32), SIMDE_POLY8_C(16), SIMDE_POLY8_C(62), SIMDE_POLY8_C(3), SIMDE_POLY8_C(29), SIMDE_POLY8_C(38),
        SIMDE_POLY8_C(42), SIMDE_POLY8_C(23), SIMDE_POLY8_C(81), SIMDE_POLY8_C(61), SIMDE_POLY8_C(28), SIMDE_POLY8_C(1), SIMDE_POLY8_C(5), SIMDE_POLY8_C(84) },
       {  SIMDE_POLY8_C(45), SIMDE_POLY8_C(87), SIMDE_POLY8_C(52), SIMDE_POLY8_C(74), SIMDE_POLY8_C(83), SIMDE_POLY8_C(48), SIMDE_POLY8_C(27), SIMDE_POLY8_C(96),
        SIMDE_POLY8_C(48), SIMDE_POLY8_C(82), SIMDE_POLY8_C(56), SIMDE_POLY8_C(23), SIMDE_POLY8_C(23), SIMDE_POLY8_C(52), SIMDE_POLY8_C(69), SIMDE_POLY8_C(57) } } },
   { { {  SIMDE_POLY8_C(46), SIMDE_POLY8_C(86), SIMDE_POLY8_C(19), SIMDE_POLY8_C(68), SIMDE_POLY8_C(15), SIMDE_POLY8_C(80), SIMDE_POLY8_C(55), SIMDE_POLY8_C(26),
        SIMDE_POLY8_C(13), SIMDE_POLY8_C(91), SIMDE_POLY8_C(5), SIMDE_POLY8_C(36), SIMDE_POLY8_C(91), SIMDE_POLY8_C(27), SIMDE_POLY8_C(80), SIMDE_POLY8_C(74) },
       {  SIMDE_POLY8_C(88), SIMDE_POLY8_C(47), SIMDE_POLY8_C(36), SIMDE_POLY8_C(33), SIMDE_POLY8_C(37), SIMDE_POLY8_C(91), SIMDE_POLY8_C(41), SIMDE_POLY8_C(63),
        SIMDE_POLY8_C(23), SIMDE_POLY8_C(98), SIMDE_POLY8_C(80), SIMDE_POLY8_C(12), SIMDE_POLY8_C(64), SIMDE_POLY8_C(50), SIMDE_POLY8_C(92), SIMDE_POLY8_C(11) },
       {  SIMDE_POLY8_C(99), SIMDE_POLY8_C(57), SIMDE_POLY8_C(22), SIMDE_POLY8_C(30), SIMDE_POLY8_C(57), SIMDE_POLY8_C(84), SIMDE_POLY8_C(43), SIMDE_POLY8_C(39),
        SIMDE_POLY8_C(54), SIMDE_POLY8_C(15), SIMDE_POLY8_C(21), SIMDE_POLY8_C(38), SIMDE_POLY8_C(13), SIMDE_POLY8_C(93), SIMDE_POLY8_C(96), SIMDE_POLY8_C(10) } },
       {  SIMDE_POLY8_C(75), SIMDE_POLY8_C(42), SIMDE_POLY8_C(8)},
     { {  SIMDE_POLY8_C(46), SIMDE_POLY8_C(86), SIMDE_POLY8_C(19), SIMDE_POLY8_C(68), SIMDE_POLY8_C(15), SIMDE_POLY8_C(80), SIMDE_POLY8_C(55), SIMDE_POLY8_C(75),
        SIMDE_POLY8_C(13), SIMDE_POLY8_C(91), SIMDE_POLY8_C(5), SIMDE_POLY8_C(36), SIMDE_POLY8_C(91), SIMDE_POLY8_C(27), SIMDE_POLY8_C(80), SIMDE_POLY8_C(74) },
       {  SIMDE_POLY8_C(88), SIMDE_POLY8_C(47), SIMDE_POLY8_C(36), SIMDE_POLY8_C(33), SIMDE_POLY8_C(37), SIMDE_POLY8_C(91), SIMDE_POLY8_C(41), SIMDE_POLY8_C(42),
        SIMDE_POLY8_C(23), SIMDE_POLY8_C(98), SIMDE_POLY8_C(80), SIMDE_POLY8_C(12), SIMDE_POLY8_C(64), SIMDE_POLY8_C(50), SIMDE_POLY8_C(92), SIMDE_POLY8_C(11) },
       {  SIMDE_POLY8_C(99), SIMDE_POLY8_C(57), SIMDE_POLY8_C(22), SIMDE_POLY8_C(30), SIMDE_POLY8_C(57), SIMDE_POLY8_C(84), SIMDE_POLY8_C(43), SIMDE_POLY8_C(8),
        SIMDE_POLY8_C(54), SIMDE_POLY8_C(15), SIMDE_POLY8_C(21), SIMDE_POLY8_C(38), SIMDE_POLY8_C(13), SIMDE_POLY8_C(93), SIMDE_POLY8_C(96), SIMDE_POLY8_C(10) } } },
   { { {  SIMDE_POLY8_C(24), SIMDE_POLY8_C(21), SIMDE_POLY8_C(44), SIMDE_POLY8_C(24), SIMDE_POLY8_C(42), SIMDE_POLY8_C(32), SIMDE_POLY8_C(52), SIMDE_POLY8_C(88),
        SIMDE_POLY8_C(75), SIMDE_POLY8_C(41), SIMDE_POLY8_C(31), SIMDE_POLY8_C(71), SIMDE_POLY8_C(42), SIMDE_POLY8_C(21), SIMDE_POLY8_C(95), SIMDE_POLY8_C(29) },
       {  SIMDE_POLY8_C(0), SIMDE_POLY8_C(81), SIMDE_POLY8_C(30), SIMDE_POLY8_C(11), SIMDE_POLY8_C(14), SIMDE_POLY8_C(31), SIMDE_POLY8_C(47), SIMDE_POLY8_C(21),
        SIMDE_POLY8_C(76), SIMDE_POLY8_C(47), SIMDE_POLY8_C(72), SIMDE_POLY8_C(10), SIMDE_POLY8_C(59), SIMDE_POLY8_C(86), SIMDE_POLY8_C(58), SIMDE_POLY8_C(86) },
       {  SIMDE_POLY8_C(90), SIMDE_POLY8_C(32), SIMDE_POLY8_C(67), SIMDE_POLY8_C(12), SIMDE_POLY8_C(21), SIMDE_POLY8_C(76), SIMDE_POLY8_C(45), SIMDE_POLY8_C(14),
        SIMDE_POLY8_C(82), SIMDE_POLY8_C(96), SIMDE_POLY8_C(68), SIMDE_POLY8_C(15), SIMDE_POLY8_C(37), SIMDE_POLY8_C(65), SIMDE_POLY8_C(18), SIMDE_POLY8_C(49) } },
       {  SIMDE_POLY8_C(84), SIMDE_POLY8_C(83), SIMDE_POLY8_C(21)},
     { {  SIMDE_POLY8_C(24), SIMDE_POLY8_C(21), SIMDE_POLY8_C(44), SIMDE_POLY8_C(24), SIMDE_POLY8_C(42), SIMDE_POLY8_C(32), SIMDE_POLY8_C(52), SIMDE_POLY8_C(88),
        SIMDE_POLY8_C(84), SIMDE_POLY8_C(41), SIMDE_POLY8_C(31), SIMDE_POLY8_C(71), SIMDE_POLY8_C(42), SIMDE_POLY8_C(21), SIMDE_POLY8_C(95), SIMDE_POLY8_C(29) },
       {  SIMDE_POLY8_C(0), SIMDE_POLY8_C(81), SIMDE_POLY8_C(30), SIMDE_POLY8_C(11), SIMDE_POLY8_C(14), SIMDE_POLY8_C(31), SIMDE_POLY8_C(47), SIMDE_POLY8_C(21),
        SIMDE_POLY8_C(83), SIMDE_POLY8_C(47), SIMDE_POLY8_C(72), SIMDE_POLY8_C(10), SIMDE_POLY8_C(59), SIMDE_POLY8_C(86), SIMDE_POLY8_C(58), SIMDE_POLY8_C(86) },
       {  SIMDE_POLY8_C(90), SIMDE_POLY8_C(32), SIMDE_POLY8_C(67), SIMDE_POLY8_C(12), SIMDE_POLY8_C(21), SIMDE_POLY8_C(76), SIMDE_POLY8_C(45), SIMDE_POLY8_C(14),
        SIMDE_POLY8_C(21), SIMDE_POLY8_C(96), SIMDE_POLY8_C(68), SIMDE_POLY8_C(15), SIMDE_POLY8_C(37), SIMDE_POLY8_C(65), SIMDE_POLY8_C(18), SIMDE_POLY8_C(49) } } },
   { { {  SIMDE_POLY8_C(22), SIMDE_POLY8_C(62), SIMDE_POLY8_C(79), SIMDE_POLY8_C(5), SIMDE_POLY8_C(54), SIMDE_POLY8_C(45), SIMDE_POLY8_C(83), SIMDE_POLY8_C(98),
        SIMDE_POLY8_C(60), SIMDE_POLY8_C(61), SIMDE_POLY8_C(81), SIMDE_POLY8_C(62), SIMDE_POLY8_C(94), SIMDE_POLY8_C(14), SIMDE_POLY8_C(98), SIMDE_POLY8_C(22) },
       {  SIMDE_POLY8_C(78), SIMDE_POLY8_C(87), SIMDE_POLY8_C(48), SIMDE_POLY8_C(29), SIMDE_POLY8_C(52), SIMDE_POLY8_C(86), SIMDE_POLY8_C(71), SIMDE_POLY8_C(13),
        SIMDE_POLY8_C(20), SIMDE_POLY8_C(11), SIMDE_POLY8_C(89), SIMDE_POLY8_C(3), SIMDE_POLY8_C(5), SIMDE_POLY8_C(93), SIMDE_POLY8_C(48), SIMDE_POLY8_C(27) },
       {  SIMDE_POLY8_C(24), SIMDE_POLY8_C(21), SIMDE_POLY8_C(99), SIMDE_POLY8_C(53), SIMDE_POLY8_C(65), SIMDE_POLY8_C(75), SIMDE_POLY8_C(5), SIMDE_POLY8_C(72),
        SIMDE_POLY8_C(8), SIMDE_POLY8_C(35), SIMDE_POLY8_C(7), SIMDE_POLY8_C(49), SIMDE_POLY8_C(6), SIMDE_POLY8_C(75), SIMDE_POLY8_C(51), SIMDE_POLY8_C(60) } },
       {  SIMDE_POLY8_C(20), SIMDE_POLY8_C(32), SIMDE_POLY8_C(53)},
     { {  SIMDE_POLY8_C(22), SIMDE_POLY8_C(62), SIMDE_POLY8_C(79), SIMDE_POLY8_C(5), SIMDE_POLY8_C(54), SIMDE_POLY8_C(45), SIMDE_POLY8_C(83), SIMDE_POLY8_C(98),
        SIMDE_POLY8_C(60), SIMDE_POLY8_C(20), SIMDE_POLY8_C(81), SIMDE_POLY8_C(62), SIMDE_POLY8_C(94), SIMDE_POLY8_C(14), SIMDE_POLY8_C(98), SIMDE_POLY8_C(22) },
       {  SIMDE_POLY8_C(78), SIMDE_POLY8_C(87), SIMDE_POLY8_C(48), SIMDE_POLY8_C(29), SIMDE_POLY8_C(52), SIMDE_POLY8_C(86), SIMDE_POLY8_C(71), SIMDE_POLY8_C(13),
        SIMDE_POLY8_C(20), SIMDE_POLY8_C(32), SIMDE_POLY8_C(89), SIMDE_POLY8_C(3), SIMDE_POLY8_C(5), SIMDE_POLY8_C(93), SIMDE_POLY8_C(48), SIMDE_POLY8_C(27) },
       {  SIMDE_POLY8_C(24), SIMDE_POLY8_C(21), SIMDE_POLY8_C(99), SIMDE_POLY8_C(53), SIMDE_POLY8_C(65), SIMDE_POLY8_C(75), SIMDE_POLY8_C(5), SIMDE_POLY8_C(72),
        SIMDE_POLY8_C(8), SIMDE_POLY8_C(53), SIMDE_POLY8_C(7), SIMDE_POLY8_C(49), SIMDE_POLY8_C(6), SIMDE_POLY8_C(75), SIMDE_POLY8_C(51), SIMDE_POLY8_C(60) } } },
   { { {  SIMDE_POLY8_C(17), SIMDE_POLY8_C(92), SIMDE_POLY8_C(0), SIMDE_POLY8_C(91), SIMDE_POLY8_C(29), SIMDE_POLY8_C(86), SIMDE_POLY8_C(77), SIMDE_POLY8_C(36),
        SIMDE_POLY8_C(8), SIMDE_POLY8_C(86), SIMDE_POLY8_C(69), SIMDE_POLY8_C(6), SIMDE_POLY8_C(35), SIMDE_POLY8_C(48), SIMDE_POLY8_C(92), SIMDE_POLY8_C(63) },
       {  SIMDE_POLY8_C(69), SIMDE_POLY8_C(16), SIMDE_POLY8_C(3), SIMDE_POLY8_C(40), SIMDE_POLY8_C(43), SIMDE_POLY8_C(9), SIMDE_POLY8_C(40), SIMDE_POLY8_C(29),
        SIMDE_POLY8_C(43), SIMDE_POLY8_C(7), SIMDE_POLY8_C(58), SIMDE_POLY8_C(77), SIMDE_POLY8_C(6), SIMDE_POLY8_C(96), SIMDE_POLY8_C(81), SIMDE_POLY8_C(97) },
       {  SIMDE_POLY8_C(45), SIMDE_POLY8_C(34), SIMDE_POLY8_C(19), SIMDE_POLY8_C(92), SIMDE_POLY8_C(4), SIMDE_POLY8_C(72), SIMDE_POLY8_C(78), SIMDE_POLY8_C(30),
        SIMDE_POLY8_C(15), SIMDE_POLY8_C(12), SIMDE_POLY8_C(37), SIMDE_POLY8_C(53), SIMDE_POLY8_C(85), SIMDE_POLY8_C(88), SIMDE_POLY8_C(0), SIMDE_POLY8_C(40) } },
       {  SIMDE_POLY8_C(63), SIMDE_POLY8_C(11), SIMDE_POLY8_C(19)},
     { {  SIMDE_POLY8_C(17), SIMDE_POLY8_C(92), SIMDE_POLY8_C(0), SIMDE_POLY8_C(91), SIMDE_POLY8_C(29), SIMDE_POLY8_C(86), SIMDE_POLY8_C(77), SIMDE_POLY8_C(36),
        SIMDE_POLY8_C(8), SIMDE_POLY8_C(86), SIMDE_POLY8_C(63), SIMDE_POLY8_C(6), SIMDE_POLY8_C(35), SIMDE_POLY8_C(48), SIMDE_POLY8_C(92), SIMDE_POLY8_C(63) },
       {  SIMDE_POLY8_C(69), SIMDE_POLY8_C(16), SIMDE_POLY8_C(3), SIMDE_POLY8_C(40), SIMDE_POLY8_C(43), SIMDE_POLY8_C(9), SIMDE_POLY8_C(40), SIMDE_POLY8_C(29),
        SIMDE_POLY8_C(43), SIMDE_POLY8_C(7), SIMDE_POLY8_C(11), SIMDE_POLY8_C(77), SIMDE_POLY8_C(6), SIMDE_POLY8_C(96), SIMDE_POLY8_C(81), SIMDE_POLY8_C(97) },
       {  SIMDE_POLY8_C(45), SIMDE_POLY8_C(34), SIMDE_POLY8_C(19), SIMDE_POLY8_C(92), SIMDE_POLY8_C(4), SIMDE_POLY8_C(72), SIMDE_POLY8_C(78), SIMDE_POLY8_C(30),
        SIMDE_POLY8_C(15), SIMDE_POLY8_C(12), SIMDE_POLY8_C(19), SIMDE_POLY8_C(53), SIMDE_POLY8_C(85), SIMDE_POLY8_C(88), SIMDE_POLY8_C(0), SIMDE_POLY8_C(40) } } },
   { { {  SIMDE_POLY8_C(97), SIMDE_POLY8_C(65), SIMDE_POLY8_C(44), SIMDE_POLY8_C(86), SIMDE_POLY8_C(8), SIMDE_POLY8_C(17), SIMDE_POLY8_C(68), SIMDE_POLY8_C(90),
        SIMDE_POLY8_C(28), SIMDE_POLY8_C(50), SIMDE_POLY8_C(29), SIMDE_POLY8_C(7), SIMDE_POLY8_C(32), SIMDE_POLY8_C(0), SIMDE_POLY8_C(49), SIMDE_POLY8_C(9) },
       {  SIMDE_POLY8_C(41), SIMDE_POLY8_C(53), SIMDE_POLY8_C(62), SIMDE_POLY8_C(71), SIMDE_POLY8_C(16), SIMDE_POLY8_C(15), SIMDE_POLY8_C(13), SIMDE_POLY8_C(88),
        SIMDE_POLY8_C(68), SIMDE_POLY8_C(9), SIMDE_POLY8_C(29), SIMDE_POLY8_C(6), SIMDE_POLY8_C(22), SIMDE_POLY8_C(32), SIMDE_POLY8_C(28), SIMDE_POLY8_C(73) },
       {  SIMDE_POLY8_C(90), SIMDE_POLY8_C(12), SIMDE_POLY8_C(95), SIMDE_POLY8_C(43), SIMDE_POLY8_C(28), SIMDE_POLY8_C(11), SIMDE_POLY8_C(77), SIMDE_POLY8_C(24),
        SIMDE_POLY8_C(28), SIMDE_POLY8_C(66), SIMDE_POLY8_C(7), SIMDE_POLY8_C(48), SIMDE_POLY8_C(73), SIMDE_POLY8_C(66), SIMDE_POLY8_C(41), SIMDE_POLY8_C(26) } },
       {  SIMDE_POLY8_C(54), SIMDE_POLY8_C(15), SIMDE_POLY8_C(78)},
     { {  SIMDE_POLY8_C(97), SIMDE_POLY8_C(65), SIMDE_POLY8_C(44), SIMDE_POLY8_C(86), SIMDE_POLY8_C(8), SIMDE_POLY8_C(17), SIMDE_POLY8_C(68), SIMDE_POLY8_C(90),
        SIMDE_POLY8_C(28), SIMDE_POLY8_C(50), SIMDE_POLY8_C(29), SIMDE_POLY8_C(54), SIMDE_POLY8_C(32), SIMDE_POLY8_C(0), SIMDE_POLY8_C(49), SIMDE_POLY8_C(9) },
       {  SIMDE_POLY8_C(41), SIMDE_POLY8_C(53), SIMDE_POLY8_C(62), SIMDE_POLY8_C(71), SIMDE_POLY8_C(16), SIMDE_POLY8_C(15), SIMDE_POLY8_C(13), SIMDE_POLY8_C(88),
        SIMDE_POLY8_C(68), SIMDE_POLY8_C(9), SIMDE_POLY8_C(29), SIMDE_POLY8_C(15), SIMDE_POLY8_C(22), SIMDE_POLY8_C(32), SIMDE_POLY8_C(28), SIMDE_POLY8_C(73) },
       {  SIMDE_POLY8_C(90), SIMDE_POLY8_C(12), SIMDE_POLY8_C(95), SIMDE_POLY8_C(43), SIMDE_POLY8_C(28), SIMDE_POLY8_C(11), SIMDE_POLY8_C(77), SIMDE_POLY8_C(24),
        SIMDE_POLY8_C(28), SIMDE_POLY8_C(66), SIMDE_POLY8_C(7), SIMDE_POLY8_C(78), SIMDE_POLY8_C(73), SIMDE_POLY8_C(66), SIMDE_POLY8_C(41), SIMDE_POLY8_C(26) } } },
   { { {  SIMDE_POLY8_C(68), SIMDE_POLY8_C(0), SIMDE_POLY8_C(37), SIMDE_POLY8_C(9), SIMDE_POLY8_C(36), SIMDE_POLY8_C(20), SIMDE_POLY8_C(51), SIMDE_POLY8_C(43),
        SIMDE_POLY8_C(38), SIMDE_POLY8_C(58), SIMDE_POLY8_C(45), SIMDE_POLY8_C(25), SIMDE_POLY8_C(28), SIMDE_POLY8_C(58), SIMDE_POLY8_C(54), SIMDE_POLY8_C(47) },
       {  SIMDE_POLY8_C(95), SIMDE_POLY8_C(96), SIMDE_POLY8_C(83), SIMDE_POLY8_C(40), SIMDE_POLY8_C(74), SIMDE_POLY8_C(12), SIMDE_POLY8_C(25), SIMDE_POLY8_C(32),
        SIMDE_POLY8_C(23), SIMDE_POLY8_C(42), SIMDE_POLY8_C(57), SIMDE_POLY8_C(39), SIMDE_POLY8_C(36), SIMDE_POLY8_C(42), SIMDE_POLY8_C(21), SIMDE_POLY8_C(54) },
       {  SIMDE_POLY8_C(49), SIMDE_POLY8_C(37), SIMDE_POLY8_C(30), SIMDE_POLY8_C(78), SIMDE_POLY8_C(55), SIMDE_POLY8_C(40), SIMDE_POLY8_C(46), SIMDE_POLY8_C(82),
        SIMDE_POLY8_C(55), SIMDE_POLY8_C(76), SIMDE_POLY8_C(19), SIMDE_POLY8_C(6), SIMDE_POLY8_C(60), SIMDE_POLY8_C(52), SIMDE_POLY8_C(70), SIMDE_POLY8_C(78) } },
       {  SIMDE_POLY8_C(39), SIMDE_POLY8_C(16), SIMDE_POLY8_C(18)},
     { {  SIMDE_POLY8_C(68), SIMDE_POLY8_C(0), SIMDE_POLY8_C(37), SIMDE_POLY8_C(9), SIMDE_POLY8_C(36), SIMDE_POLY8_C(20), SIMDE_POLY8_C(51), SIMDE_POLY8_C(43),
        SIMDE_POLY8_C(38), SIMDE_POLY8_C(58), SIMDE_POLY8_C(45), SIMDE_POLY8_C(25), SIMDE_POLY8_C(39), SIMDE_POLY8_C(58), SIMDE_POLY8_C(54), SIMDE_POLY8_C(47) },
       {  SIMDE_POLY8_C(95), SIMDE_POLY8_C(96), SIMDE_POLY8_C(83), SIMDE_POLY8_C(40), SIMDE_POLY8_C(74), SIMDE_POLY8_C(12), SIMDE_POLY8_C(25), SIMDE_POLY8_C(32),
        SIMDE_POLY8_C(23), SIMDE_POLY8_C(42), SIMDE_POLY8_C(57), SIMDE_POLY8_C(39), SIMDE_POLY8_C(16), SIMDE_POLY8_C(42), SIMDE_POLY8_C(21), SIMDE_POLY8_C(54) },
       {  SIMDE_POLY8_C(49), SIMDE_POLY8_C(37), SIMDE_POLY8_C(30), SIMDE_POLY8_C(78), SIMDE_POLY8_C(55), SIMDE_POLY8_C(40), SIMDE_POLY8_C(46), SIMDE_POLY8_C(82),
        SIMDE_POLY8_C(55), SIMDE_POLY8_C(76), SIMDE_POLY8_C(19), SIMDE_POLY8_C(6), SIMDE_POLY8_C(18), SIMDE_POLY8_C(52), SIMDE_POLY8_C(70), SIMDE_POLY8_C(78) } } },
   { { {  SIMDE_POLY8_C(20), SIMDE_POLY8_C(75), SIMDE_POLY8_C(35), SIMDE_POLY8_C(24), SIMDE_POLY8_C(60), SIMDE_POLY8_C(21), SIMDE_POLY8_C(67), SIMDE_POLY8_C(1),
        SIMDE_POLY8_C(23), SIMDE_POLY8_C(57), SIMDE_POLY8_C(40), SIMDE_POLY8_C(31), SIMDE_POLY8_C(71), SIMDE_POLY8_C(21), SIMDE_POLY8_C(41), SIMDE_POLY8_C(71) },
       {  SIMDE_POLY8_C(3), SIMDE_POLY8_C(21), SIMDE_POLY8_C(89), SIMDE_POLY8_C(29), SIMDE_POLY8_C(51), SIMDE_POLY8_C(99), SIMDE_POLY8_C(90), SIMDE_POLY8_C(35),
        SIMDE_POLY8_C(30), SIMDE_POLY8_C(34), SIMDE_POLY8_C(67), SIMDE_POLY8_C(84), SIMDE_POLY8_C(79), SIMDE_POLY8_C(58), SIMDE_POLY8_C(39), SIMDE_POLY8_C(41) },
       {  SIMDE_POLY8_C(0), SIMDE_POLY8_C(68), SIMDE_POLY8_C(73), SIMDE_POLY8_C(59), SIMDE_POLY8_C(44), SIMDE_POLY8_C(83), SIMDE_POLY8_C(41), SIMDE_POLY8_C(72),
        SIMDE_POLY8_C(54), SIMDE_POLY8_C(29), SIMDE_POLY8_C(52), SIMDE_POLY8_C(51), SIMDE_POLY8_C(25), SIMDE_POLY8_C(25), SIMDE_POLY8_C(13), SIMDE_POLY8_C(15) } },
       {  SIMDE_POLY8_C(13), SIMDE_POLY8_C(84), SIMDE_POLY8_C(69)},
     { {  SIMDE_POLY8_C(20), SIMDE_POLY8_C(75), SIMDE_POLY8_C(35), SIMDE_POLY8_C(24), SIMDE_POLY8_C(60), SIMDE_POLY8_C(21), SIMDE_POLY8_C(67), SIMDE_POLY8_C(1),
        SIMDE_POLY8_C(23), SIMDE_POLY8_C(57), SIMDE_POLY8_C(40), SIMDE_POLY8_C(31), SIMDE_POLY8_C(71), SIMDE_POLY8_C(13), SIMDE_POLY8_C(41), SIMDE_POLY8_C(71) },
       {  SIMDE_POLY8_C(3), SIMDE_POLY8_C(21), SIMDE_POLY8_C(89), SIMDE_POLY8_C(29), SIMDE_POLY8_C(51), SIMDE_POLY8_C(99), SIMDE_POLY8_C(90), SIMDE_POLY8_C(35),
        SIMDE_POLY8_C(30), SIMDE_POLY8_C(34), SIMDE_POLY8_C(67), SIMDE_POLY8_C(84), SIMDE_POLY8_C(79), SIMDE_POLY8_C(84), SIMDE_POLY8_C(39), SIMDE_POLY8_C(41) },
       {  SIMDE_POLY8_C(0), SIMDE_POLY8_C(68), SIMDE_POLY8_C(73), SIMDE_POLY8_C(59), SIMDE_POLY8_C(44), SIMDE_POLY8_C(83), SIMDE_POLY8_C(41), SIMDE_POLY8_C(72),
        SIMDE_POLY8_C(54), SIMDE_POLY8_C(29), SIMDE_POLY8_C(52), SIMDE_POLY8_C(51), SIMDE_POLY8_C(25), SIMDE_POLY8_C(69), SIMDE_POLY8_C(13), SIMDE_POLY8_C(15) } } },
   { { {  SIMDE_POLY8_C(78), SIMDE_POLY8_C(80), SIMDE_POLY8_C(8), SIMDE_POLY8_C(85), SIMDE_POLY8_C(17), SIMDE_POLY8_C(53), SIMDE_POLY8_C(88), SIMDE_POLY8_C(87),
        SIMDE_POLY8_C(32), SIMDE_POLY8_C(29), SIMDE_POLY8_C(69), SIMDE_POLY8_C(78), SIMDE_POLY8_C(28), SIMDE_POLY8_C(38), SIMDE_POLY8_C(52), SIMDE_POLY8_C(24) },
       {  SIMDE_POLY8_C(64), SIMDE_POLY8_C(96), SIMDE_POLY8_C(34), SIMDE_POLY8_C(25), SIMDE_POLY8_C(46), SIMDE_POLY8_C(80), SIMDE_POLY8_C(65), SIMDE_POLY8_C(84),
        SIMDE_POLY8_C(71), SIMDE_POLY8_C(36), SIMDE_POLY8_C(9), SIMDE_POLY8_C(67), SIMDE_POLY8_C(75), SIMDE_POLY8_C(57), SIMDE_POLY8_C(24), SIMDE_POLY8_C(69) },
       {  SIMDE_POLY8_C(77), SIMDE_POLY8_C(59), SIMDE_POLY8_C(66), SIMDE_POLY8_C(82), SIMDE_POLY8_C(84), SIMDE_POLY8_C(12), SIMDE_POLY8_C(12), SIMDE_POLY8_C(87),
        SIMDE_POLY8_C(76), SIMDE_POLY8_C(40), SIMDE_POLY8_C(86), SIMDE_POLY8_C(5), SIMDE_POLY8_C(88), SIMDE_POLY8_C(47), SIMDE_POLY8_C(15), SIMDE_POLY8_C(68) } },
       {  SIMDE_POLY8_C(57), SIMDE_POLY8_C(4), SIMDE_POLY8_C(6)},
     { {  SIMDE_POLY8_C(78), SIMDE_POLY8_C(80), SIMDE_POLY8_C(8), SIMDE_POLY8_C(85), SIMDE_POLY8_C(17), SIMDE_POLY8_C(53), SIMDE_POLY8_C(88), SIMDE_POLY8_C(87),
        SIMDE_POLY8_C(32), SIMDE_POLY8_C(29), SIMDE_POLY8_C(69), SIMDE_POLY8_C(78), SIMDE_POLY8_C(28), SIMDE_POLY8_C(38), SIMDE_POLY8_C(57), SIMDE_POLY8_C(24) },
       {  SIMDE_POLY8_C(64), SIMDE_POLY8_C(96), SIMDE_POLY8_C(34), SIMDE_POLY8_C(25), SIMDE_POLY8_C(46), SIMDE_POLY8_C(80), SIMDE_POLY8_C(65), SIMDE_POLY8_C(84),
        SIMDE_POLY8_C(71), SIMDE_POLY8_C(36), SIMDE_POLY8_C(9), SIMDE_POLY8_C(67), SIMDE_POLY8_C(75), SIMDE_POLY8_C(57), SIMDE_POLY8_C(4), SIMDE_POLY8_C(69) },
       {  SIMDE_POLY8_C(77), SIMDE_POLY8_C(59), SIMDE_POLY8_C(66), SIMDE_POLY8_C(82), SIMDE_POLY8_C(84), SIMDE_POLY8_C(12), SIMDE_POLY8_C(12), SIMDE_POLY8_C(87),
        SIMDE_POLY8_C(76), SIMDE_POLY8_C(40), SIMDE_POLY8_C(86), SIMDE_POLY8_C(5), SIMDE_POLY8_C(88), SIMDE_POLY8_C(47), SIMDE_POLY8_C(6), SIMDE_POLY8_C(68) } } },
   { { {  SIMDE_POLY8_C(10), SIMDE_POLY8_C(53), SIMDE_POLY8_C(42), SIMDE_POLY8_C(50), SIMDE_POLY8_C(80), SIMDE_POLY8_C(86), SIMDE_POLY8_C(65), SIMDE_POLY8_C(9),
        SIMDE_POLY8_C(64), SIMDE_POLY8_C(65), SIMDE_POLY8_C(83), SIMDE_POLY8_C(30), SIMDE_POLY8_C(10), SIMDE_POLY8_C(44), SIMDE_POLY8_C(49), SIMDE_POLY8_C(37) },
       {  SIMDE_POLY8_C(31), SIMDE_POLY8_C(51), SIMDE_POLY8_C(22), SIMDE_POLY8_C(60), SIMDE_POLY8_C(49), SIMDE_POLY8_C(93), SIMDE_POLY8_C(32), SIMDE_POLY8_C(99),
        SIMDE_POLY8_C(7), SIMDE_POLY8_C(29), SIMDE_POLY8_C(87), SIMDE_POLY8_C(97), SIMDE_POLY8_C(99), SIMDE_POLY8_C(4), SIMDE_POLY8_C(60), SIMDE_POLY8_C(5) },
       {  SIMDE_POLY8_C(4), SIMDE_POLY8_C(70), SIMDE_POLY8_C(12), SIMDE_POLY8_C(81), SIMDE_POLY8_C(94), SIMDE_POLY8_C(77), SIMDE_POLY8_C(86), SIMDE_POLY8_C(97),
        SIMDE_POLY8_C(2), SIMDE_POLY8_C(78), SIMDE_POLY8_C(86), SIMDE_POLY8_C(4), SIMDE_POLY8_C(45), SIMDE_POLY8_C(33), SIMDE_POLY8_C(66), SIMDE_POLY8_C(9) } },
       {  SIMDE_POLY8_C(6), SIMDE_POLY8_C(72), SIMDE_POLY8_C(66)},
     { {  SIMDE_POLY8_C(10), SIMDE_POLY8_C(53), SIMDE_POLY8_C(42), SIMDE_POLY8_C(50), SIMDE_POLY8_C(80), SIMDE_POLY8_C(86), SIMDE_POLY8_C(65), SIMDE_POLY8_C(9),
        SIMDE_POLY8_C(64), SIMDE_POLY8_C(65), SIMDE_POLY8_C(83), SIMDE_POLY8_C(30), SIMDE_POLY8_C(10), SIMDE_POLY8_C(44), SIMDE_POLY8_C(49), SIMDE_POLY8_C(6) },
       {  SIMDE_POLY8_C(31), SIMDE_POLY8_C(51), SIMDE_POLY8_C(22), SIMDE_POLY8_C(60), SIMDE_POLY8_C(49), SIMDE_POLY8_C(93), SIMDE_POLY8_C(32), SIMDE_POLY8_C(99),
        SIMDE_POLY8_C(7), SIMDE_POLY8_C(29), SIMDE_POLY8_C(87), SIMDE_POLY8_C(97), SIMDE_POLY8_C(99), SIMDE_POLY8_C(4), SIMDE_POLY8_C(60), SIMDE_POLY8_C(72) },
       {  SIMDE_POLY8_C(4), SIMDE_POLY8_C(70), SIMDE_POLY8_C(12), SIMDE_POLY8_C(81), SIMDE_POLY8_C(94), SIMDE_POLY8_C(77), SIMDE_POLY8_C(86), SIMDE_POLY8_C(97),
        SIMDE_POLY8_C(2), SIMDE_POLY8_C(78), SIMDE_POLY8_C(86), SIMDE_POLY8_C(4), SIMDE_POLY8_C(45), SIMDE_POLY8_C(33), SIMDE_POLY8_C(66), SIMDE_POLY8_C(66) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_poly8x16x3_t r, src, expected;
    src.val[0] = simde_vld1q_p8(test_vec[i].src[0]);
    src.val[1] = simde_vld1q_p8(test_vec[i].src[1]);
    src.val[2] = simde_vld1q_p8(test_vec[i].src[2]);

    SIMDE_CONSTIFY_16_(simde_vld3q_lane_p8, r, (HEDLEY_UNREACHABLE(), r), i, test_vec[i].buf, src);

    expected.val[0] = simde_vld1q_p8(test_vec[i].r[0]);
    expected.val[1] = simde_vld1q_p8(test_vec[i].r[1]);
    expected.val[2] = simde_vld1q_p8(test_vec[i].r[2]);

    simde_test_arm_neon_assert_equal_p8x16(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_p8x16(r.val[1], expected.val[1]);
    simde_test_arm_neon_assert_equal_p8x16(r.val[2], expected.val[2]);
  }

  return 0;
#else
  for (int i = 0 ; i < 16 ; i++) {
    simde_poly8x16x3_t src = simde_test_arm_neon_random_p8x16x3();
    simde_poly8_t buf[3];
    simde_poly8x16x3_t r;
    simde_test_arm_neon_write_p8x16x3(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_random_memory(3, HEDLEY_REINTERPRET_CAST(uint8_t*, buf));
    simde_test_codegen_write_vp8(2, 3, buf, SIMDE_TEST_VEC_POS_MIDDLE);
    SIMDE_CONSTIFY_16_(simde_vld3q_lane_p8, r, (HEDLEY_UNREACHABLE(), r), i, buf, src);
    simde_test_arm_neon_write_p8x16x3(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld3q_lane_p16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_poly16_t src[3][8];
    simde_poly16_t buf[3];
    simde_poly16_t r[3][8];
  } test_vec[] = {
   { { {  SIMDE_POLY16_C(2878), SIMDE_POLY16_C(9122), SIMDE_POLY16_C(7556), SIMDE_POLY16_C(7857),
        SIMDE_POLY16_C(958), SIMDE_POLY16_C(7812), SIMDE_POLY16_C(2259), SIMDE_POLY16_C(582) },
       {  SIMDE_POLY16_C(5578), SIMDE_POLY16_C(9333), SIMDE_POLY16_C(1655), SIMDE_POLY16_C(9009),
        SIMDE_POLY16_C(596), SIMDE_POLY16_C(8223), SIMDE_POLY16_C(5654), SIMDE_POLY16_C(3297) },
       {  SIMDE_POLY16_C(5817), SIMDE_POLY16_C(7331), SIMDE_POLY16_C(8798), SIMDE_POLY16_C(172),
        SIMDE_POLY16_C(1106), SIMDE_POLY16_C(371), SIMDE_POLY16_C(9285), SIMDE_POLY16_C(5940) } },
       {  SIMDE_POLY16_C(9267), SIMDE_POLY16_C(2616), SIMDE_POLY16_C(7110)},
     { {  SIMDE_POLY16_C(9267), SIMDE_POLY16_C(9122), SIMDE_POLY16_C(7556), SIMDE_POLY16_C(7857),
        SIMDE_POLY16_C(958), SIMDE_POLY16_C(7812), SIMDE_POLY16_C(2259), SIMDE_POLY16_C(582) },
       {  SIMDE_POLY16_C(2616), SIMDE_POLY16_C(9333), SIMDE_POLY16_C(1655), SIMDE_POLY16_C(9009),
        SIMDE_POLY16_C(596), SIMDE_POLY16_C(8223), SIMDE_POLY16_C(5654), SIMDE_POLY16_C(3297) },
       {  SIMDE_POLY16_C(7110), SIMDE_POLY16_C(7331), SIMDE_POLY16_C(8798), SIMDE_POLY16_C(172),
        SIMDE_POLY16_C(1106), SIMDE_POLY16_C(371), SIMDE_POLY16_C(9285), SIMDE_POLY16_C(5940) } } },
   { { {  SIMDE_POLY16_C(2435), SIMDE_POLY16_C(4626), SIMDE_POLY16_C(4142), SIMDE_POLY16_C(3387),
        SIMDE_POLY16_C(6479), SIMDE_POLY16_C(7643), SIMDE_POLY16_C(5193), SIMDE_POLY16_C(3942) },
       {  SIMDE_POLY16_C(3016), SIMDE_POLY16_C(1407), SIMDE_POLY16_C(8271), SIMDE_POLY16_C(4950),
        SIMDE_POLY16_C(1775), SIMDE_POLY16_C(4681), SIMDE_POLY16_C(737), SIMDE_POLY16_C(7429) },
       {  SIMDE_POLY16_C(7279), SIMDE_POLY16_C(9658), SIMDE_POLY16_C(8142), SIMDE_POLY16_C(2112),
        SIMDE_POLY16_C(4555), SIMDE_POLY16_C(469), SIMDE_POLY16_C(1007), SIMDE_POLY16_C(2148) } },
       {  SIMDE_POLY16_C(4650), SIMDE_POLY16_C(9800), SIMDE_POLY16_C(2863)},
     { {  SIMDE_POLY16_C(2435), SIMDE_POLY16_C(4650), SIMDE_POLY16_C(4142), SIMDE_POLY16_C(3387),
        SIMDE_POLY16_C(6479), SIMDE_POLY16_C(7643), SIMDE_POLY16_C(5193), SIMDE_POLY16_C(3942) },
       {  SIMDE_POLY16_C(3016), SIMDE_POLY16_C(9800), SIMDE_POLY16_C(8271), SIMDE_POLY16_C(4950),
        SIMDE_POLY16_C(1775), SIMDE_POLY16_C(4681), SIMDE_POLY16_C(737), SIMDE_POLY16_C(7429) },
       {  SIMDE_POLY16_C(7279), SIMDE_POLY16_C(2863), SIMDE_POLY16_C(8142), SIMDE_POLY16_C(2112),
        SIMDE_POLY16_C(4555), SIMDE_POLY16_C(469), SIMDE_POLY16_C(1007), SIMDE_POLY16_C(2148) } } },
   { { {  SIMDE_POLY16_C(3842), SIMDE_POLY16_C(9560), SIMDE_POLY16_C(4451), SIMDE_POLY16_C(3039),
        SIMDE_POLY16_C(1396), SIMDE_POLY16_C(7094), SIMDE_POLY16_C(9151), SIMDE_POLY16_C(328) },
       {  SIMDE_POLY16_C(3222), SIMDE_POLY16_C(3639), SIMDE_POLY16_C(4981), SIMDE_POLY16_C(4084),
        SIMDE_POLY16_C(4213), SIMDE_POLY16_C(6807), SIMDE_POLY16_C(5985), SIMDE_POLY16_C(3640) },
       {  SIMDE_POLY16_C(5867), SIMDE_POLY16_C(7377), SIMDE_POLY16_C(7519), SIMDE_POLY16_C(4002),
        SIMDE_POLY16_C(4302), SIMDE_POLY16_C(897), SIMDE_POLY16_C(4387), SIMDE_POLY16_C(6837) } },
       {  SIMDE_POLY16_C(5729), SIMDE_POLY16_C(6854), SIMDE_POLY16_C(829)},
     { {  SIMDE_POLY16_C(3842), SIMDE_POLY16_C(9560), SIMDE_POLY16_C(5729), SIMDE_POLY16_C(3039),
        SIMDE_POLY16_C(1396), SIMDE_POLY16_C(7094), SIMDE_POLY16_C(9151), SIMDE_POLY16_C(328) },
       {  SIMDE_POLY16_C(3222), SIMDE_POLY16_C(3639), SIMDE_POLY16_C(6854), SIMDE_POLY16_C(4084),
        SIMDE_POLY16_C(4213), SIMDE_POLY16_C(6807), SIMDE_POLY16_C(5985), SIMDE_POLY16_C(3640) },
       {  SIMDE_POLY16_C(5867), SIMDE_POLY16_C(7377), SIMDE_POLY16_C(829), SIMDE_POLY16_C(4002),
        SIMDE_POLY16_C(4302), SIMDE_POLY16_C(897), SIMDE_POLY16_C(4387), SIMDE_POLY16_C(6837) } } },
   { { {  SIMDE_POLY16_C(7563), SIMDE_POLY16_C(2164), SIMDE_POLY16_C(8586), SIMDE_POLY16_C(1245),
        SIMDE_POLY16_C(9300), SIMDE_POLY16_C(1489), SIMDE_POLY16_C(7158), SIMDE_POLY16_C(4863) },
       {  SIMDE_POLY16_C(1424), SIMDE_POLY16_C(4247), SIMDE_POLY16_C(5640), SIMDE_POLY16_C(6608),
        SIMDE_POLY16_C(5989), SIMDE_POLY16_C(3578), SIMDE_POLY16_C(742), SIMDE_POLY16_C(1885) },
       {  SIMDE_POLY16_C(5512), SIMDE_POLY16_C(3861), SIMDE_POLY16_C(6631), SIMDE_POLY16_C(2430),
        SIMDE_POLY16_C(2806), SIMDE_POLY16_C(1789), SIMDE_POLY16_C(8536), SIMDE_POLY16_C(1442) } },
       {  SIMDE_POLY16_C(321), SIMDE_POLY16_C(9802), SIMDE_POLY16_C(8592)},
     { {  SIMDE_POLY16_C(7563), SIMDE_POLY16_C(2164), SIMDE_POLY16_C(8586), SIMDE_POLY16_C(321),
        SIMDE_POLY16_C(9300), SIMDE_POLY16_C(1489), SIMDE_POLY16_C(7158), SIMDE_POLY16_C(4863) },
       {  SIMDE_POLY16_C(1424), SIMDE_POLY16_C(4247), SIMDE_POLY16_C(5640), SIMDE_POLY16_C(9802),
        SIMDE_POLY16_C(5989), SIMDE_POLY16_C(3578), SIMDE_POLY16_C(742), SIMDE_POLY16_C(1885) },
       {  SIMDE_POLY16_C(5512), SIMDE_POLY16_C(3861), SIMDE_POLY16_C(6631), SIMDE_POLY16_C(8592),
        SIMDE_POLY16_C(2806), SIMDE_POLY16_C(1789), SIMDE_POLY16_C(8536), SIMDE_POLY16_C(1442) } } },
   { { {  SIMDE_POLY16_C(846), SIMDE_POLY16_C(2844), SIMDE_POLY16_C(4543), SIMDE_POLY16_C(5042),
        SIMDE_POLY16_C(9059), SIMDE_POLY16_C(789), SIMDE_POLY16_C(9345), SIMDE_POLY16_C(8528) },
       {  SIMDE_POLY16_C(5245), SIMDE_POLY16_C(4972), SIMDE_POLY16_C(9392), SIMDE_POLY16_C(6785),
        SIMDE_POLY16_C(6982), SIMDE_POLY16_C(1587), SIMDE_POLY16_C(9547), SIMDE_POLY16_C(806) },
       {  SIMDE_POLY16_C(2535), SIMDE_POLY16_C(912), SIMDE_POLY16_C(7134), SIMDE_POLY16_C(1939),
        SIMDE_POLY16_C(226), SIMDE_POLY16_C(4171), SIMDE_POLY16_C(756), SIMDE_POLY16_C(7958) } },
       {  SIMDE_POLY16_C(9975), SIMDE_POLY16_C(6402), SIMDE_POLY16_C(5394)},
     { {  SIMDE_POLY16_C(846), SIMDE_POLY16_C(2844), SIMDE_POLY16_C(4543), SIMDE_POLY16_C(5042),
        SIMDE_POLY16_C(9975), SIMDE_POLY16_C(789), SIMDE_POLY16_C(9345), SIMDE_POLY16_C(8528) },
       {  SIMDE_POLY16_C(5245), SIMDE_POLY16_C(4972), SIMDE_POLY16_C(9392), SIMDE_POLY16_C(6785),
        SIMDE_POLY16_C(6402), SIMDE_POLY16_C(1587), SIMDE_POLY16_C(9547), SIMDE_POLY16_C(806) },
       {  SIMDE_POLY16_C(2535), SIMDE_POLY16_C(912), SIMDE_POLY16_C(7134), SIMDE_POLY16_C(1939),
        SIMDE_POLY16_C(5394), SIMDE_POLY16_C(4171), SIMDE_POLY16_C(756), SIMDE_POLY16_C(7958) } } },
   { { {  SIMDE_POLY16_C(5491), SIMDE_POLY16_C(9037), SIMDE_POLY16_C(2121), SIMDE_POLY16_C(3027),
        SIMDE_POLY16_C(9896), SIMDE_POLY16_C(3828), SIMDE_POLY16_C(4925), SIMDE_POLY16_C(6295) },
       {  SIMDE_POLY16_C(4330), SIMDE_POLY16_C(4964), SIMDE_POLY16_C(3055), SIMDE_POLY16_C(2853),
        SIMDE_POLY16_C(5505), SIMDE_POLY16_C(2630), SIMDE_POLY16_C(7217), SIMDE_POLY16_C(9453) },
       {  SIMDE_POLY16_C(9293), SIMDE_POLY16_C(8272), SIMDE_POLY16_C(4351), SIMDE_POLY16_C(7481),
        SIMDE_POLY16_C(2380), SIMDE_POLY16_C(1671), SIMDE_POLY16_C(9975), SIMDE_POLY16_C(6647) } },
       {  SIMDE_POLY16_C(2220), SIMDE_POLY16_C(9744), SIMDE_POLY16_C(8641)},
     { {  SIMDE_POLY16_C(5491), SIMDE_POLY16_C(9037), SIMDE_POLY16_C(2121), SIMDE_POLY16_C(3027),
        SIMDE_POLY16_C(9896), SIMDE_POLY16_C(2220), SIMDE_POLY16_C(4925), SIMDE_POLY16_C(6295) },
       {  SIMDE_POLY16_C(4330), SIMDE_POLY16_C(4964), SIMDE_POLY16_C(3055), SIMDE_POLY16_C(2853),
        SIMDE_POLY16_C(5505), SIMDE_POLY16_C(9744), SIMDE_POLY16_C(7217), SIMDE_POLY16_C(9453) },
       {  SIMDE_POLY16_C(9293), SIMDE_POLY16_C(8272), SIMDE_POLY16_C(4351), SIMDE_POLY16_C(7481),
        SIMDE_POLY16_C(2380), SIMDE_POLY16_C(8641), SIMDE_POLY16_C(9975), SIMDE_POLY16_C(6647) } } },
   { { {  SIMDE_POLY16_C(9694), SIMDE_POLY16_C(2965), SIMDE_POLY16_C(2860), SIMDE_POLY16_C(3217),
        SIMDE_POLY16_C(905), SIMDE_POLY16_C(1382), SIMDE_POLY16_C(2539), SIMDE_POLY16_C(2136) },
       {  SIMDE_POLY16_C(9340), SIMDE_POLY16_C(8057), SIMDE_POLY16_C(2560), SIMDE_POLY16_C(2780),
        SIMDE_POLY16_C(9091), SIMDE_POLY16_C(341), SIMDE_POLY16_C(2559), SIMDE_POLY16_C(5566) },
       {  SIMDE_POLY16_C(5464), SIMDE_POLY16_C(8934), SIMDE_POLY16_C(8459), SIMDE_POLY16_C(5838),
        SIMDE_POLY16_C(5847), SIMDE_POLY16_C(9085), SIMDE_POLY16_C(7113), SIMDE_POLY16_C(1453) } },
       {  SIMDE_POLY16_C(9231), SIMDE_POLY16_C(1160), SIMDE_POLY16_C(1750)},
     { {  SIMDE_POLY16_C(9694), SIMDE_POLY16_C(2965), SIMDE_POLY16_C(2860), SIMDE_POLY16_C(3217),
        SIMDE_POLY16_C(905), SIMDE_POLY16_C(1382), SIMDE_POLY16_C(9231), SIMDE_POLY16_C(2136) },
       {  SIMDE_POLY16_C(9340), SIMDE_POLY16_C(8057), SIMDE_POLY16_C(2560), SIMDE_POLY16_C(2780),
        SIMDE_POLY16_C(9091), SIMDE_POLY16_C(341), SIMDE_POLY16_C(1160), SIMDE_POLY16_C(5566) },
       {  SIMDE_POLY16_C(5464), SIMDE_POLY16_C(8934), SIMDE_POLY16_C(8459), SIMDE_POLY16_C(5838),
        SIMDE_POLY16_C(5847), SIMDE_POLY16_C(9085), SIMDE_POLY16_C(1750), SIMDE_POLY16_C(1453) } } },
   { { {  SIMDE_POLY16_C(4299), SIMDE_POLY16_C(2575), SIMDE_POLY16_C(1738), SIMDE_POLY16_C(2713),
        SIMDE_POLY16_C(3823), SIMDE_POLY16_C(2897), SIMDE_POLY16_C(4868), SIMDE_POLY16_C(3272) },
       {  SIMDE_POLY16_C(1451), SIMDE_POLY16_C(4038), SIMDE_POLY16_C(5588), SIMDE_POLY16_C(8951),
        SIMDE_POLY16_C(8365), SIMDE_POLY16_C(7112), SIMDE_POLY16_C(7225), SIMDE_POLY16_C(5057) },
       {  SIMDE_POLY16_C(1287), SIMDE_POLY16_C(8547), SIMDE_POLY16_C(3369), SIMDE_POLY16_C(2472),
        SIMDE_POLY16_C(2063), SIMDE_POLY16_C(1405), SIMDE_POLY16_C(3647), SIMDE_POLY16_C(1463) } },
       {  SIMDE_POLY16_C(6301), SIMDE_POLY16_C(8922), SIMDE_POLY16_C(8856)},
     { {  SIMDE_POLY16_C(4299), SIMDE_POLY16_C(2575), SIMDE_POLY16_C(1738), SIMDE_POLY16_C(2713),
        SIMDE_POLY16_C(3823), SIMDE_POLY16_C(2897), SIMDE_POLY16_C(4868), SIMDE_POLY16_C(6301) },
       {  SIMDE_POLY16_C(1451), SIMDE_POLY16_C(4038), SIMDE_POLY16_C(5588), SIMDE_POLY16_C(8951),
        SIMDE_POLY16_C(8365), SIMDE_POLY16_C(7112), SIMDE_POLY16_C(7225), SIMDE_POLY16_C(8922) },
       {  SIMDE_POLY16_C(1287), SIMDE_POLY16_C(8547), SIMDE_POLY16_C(3369), SIMDE_POLY16_C(2472),
        SIMDE_POLY16_C(2063), SIMDE_POLY16_C(1405), SIMDE_POLY16_C(3647), SIMDE_POLY16_C(8856) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_poly16x8x3_t r, src, expected;
    src.val[0] = simde_vld1q_p16(test_vec[i].src[0]);
    src.val[1] = simde_vld1q_p16(test_vec[i].src[1]);
    src.val[2] = simde_vld1q_p16(test_vec[i].src[2]);

    SIMDE_CONSTIFY_8_(simde_vld3q_lane_p16, r, (HEDLEY_UNREACHABLE(), r), i, test_vec[i].buf, src);

    expected.val[0] = simde_vld1q_p16(test_vec[i].r[0]);
    expected.val[1] = simde_vld1q_p16(test_vec[i].r[1]);
    expected.val[2] = simde_vld1q_p16(test_vec[i].r[2]);

    simde_test_arm_neon_assert_equal_p16x8(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_p16x8(r.val[1], expected.val[1]);
    simde_test_arm_neon_assert_equal_p16x8(r.val[2], expected.val[2]);
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_poly16x8x3_t src = simde_test_arm_neon_random_p16x8x3();
    simde_poly16_t buf[3];
    simde_poly16x8x3_t r;
    simde_test_arm_neon_write_p16x8x3(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_random_memory(6, HEDLEY_REINTERPRET_CAST(uint8_t*, buf));
    simde_test_codegen_write_vp16(2, 3, buf, SIMDE_TEST_VEC_POS_MIDDLE);
    SIMDE_CONSTIFY_8_(simde_vld3q_lane_p16, r, (HEDLEY_UNREACHABLE(), r), i, buf, src);
    simde_test_arm_neon_write_p16x8x3(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld3q_lane_p64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_poly64_t src[3][2];
    simde_poly64_t buf[3];
    simde_poly64_t r[3][2];
  } test_vec[] = {
   { { {  SIMDE_POLY64_C(56952904), SIMDE_POLY64_C(35256781) },
       {  SIMDE_POLY64_C(89718407), SIMDE_POLY64_C(12358219) },
       {  SIMDE_POLY64_C(61792069), SIMDE_POLY64_C(55919668) } },
       {  SIMDE_POLY64_C(95716616), SIMDE_POLY64_C(80066973), SIMDE_POLY64_C(46886750)},
     { {  SIMDE_POLY64_C(95716616), SIMDE_POLY64_C(35256781) },
       {  SIMDE_POLY64_C(80066973), SIMDE_POLY64_C(12358219) },
       {  SIMDE_POLY64_C(46886750), SIMDE_POLY64_C(55919668) } } },
   { { {  SIMDE_POLY64_C(95308677), SIMDE_POLY64_C(34498022) },
       {  SIMDE_POLY64_C(67254093), SIMDE_POLY64_C(94380501) },
       {  SIMDE_POLY64_C(77927395), SIMDE_POLY64_C(69899674) } },
       {  SIMDE_POLY64_C(50242963), SIMDE_POLY64_C(81401259), SIMDE_POLY64_C(34813265)},
     { {  SIMDE_POLY64_C(95308677), SIMDE_POLY64_C(50242963) },
       {  SIMDE_POLY64_C(67254093), SIMDE_POLY64_C(81401259) },
       {  SIMDE_POLY64_C(77927395), SIMDE_POLY64_C(34813265) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_poly64x2x3_t r, src, expected;
    src.val[0] = simde_vld1q_p64(test_vec[i].src[0]);
    src.val[1] = simde_vld1q_p64(test_vec[i].src[1]);
    src.val[2] = simde_vld1q_p64(test_vec[i].src[2]);

    SIMDE_CONSTIFY_2_(simde_vld3q_lane_p64, r, (HEDLEY_UNREACHABLE(), r), i, test_vec[i].buf, src);

    expected.val[0] = simde_vld1q_p64(test_vec[i].r[0]);
    expected.val[1] = simde_vld1q_p64(test_vec[i].r[1]);
    expected.val[2] = simde_vld1q_p64(test_vec[i].r[2]);

    simde_test_arm_neon_assert_equal_p64x2(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_p64x2(r.val[1], expected.val[1]);
    simde_test_arm_neon_assert_equal_p64x2(r.val[2], expected.val[2]);
  }

  return 0;
#else
  for (int i = 0 ; i < 2 ; i++) {
    simde_poly64x2x3_t src = simde_test_arm_neon_random_p64x2x3();
    simde_poly64_t buf[3];
    simde_poly64x2x3_t r;
    simde_test_arm_neon_write_p64x2x3(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_random_memory(24, HEDLEY_REINTERPRET_CAST(uint8_t*, buf));
    simde_test_codegen_write_vp64(2, 3, buf, SIMDE_TEST_VEC_POS_MIDDLE);
    SIMDE_CONSTIFY_2_(simde_vld3q_lane_p64, r, (HEDLEY_UNREACHABLE(), r), i, buf, src);
    simde_test_arm_neon_write_p64x2x3(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld3_lane_bf16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_bfloat16_t src[3][4];
    simde_bfloat16_t buf[3];
    simde_bfloat16_t r[3][4];
  } test_vec[] = {
   { { {  SIMDE_BFLOAT16_VALUE(-38.09), SIMDE_BFLOAT16_VALUE(39.56), SIMDE_BFLOAT16_VALUE(12.85), SIMDE_BFLOAT16_VALUE(-6.63) },
       {  SIMDE_BFLOAT16_VALUE(-41.59), SIMDE_BFLOAT16_VALUE(46.59), SIMDE_BFLOAT16_VALUE(22.79), SIMDE_BFLOAT16_VALUE(-13.35) },
       {  SIMDE_BFLOAT16_VALUE(25.23), SIMDE_BFLOAT16_VALUE(-26.59), SIMDE_BFLOAT16_VALUE(19.00), SIMDE_BFLOAT16_VALUE(-16.99) } },
       {  SIMDE_BFLOAT16_VALUE(6.58), SIMDE_BFLOAT16_VALUE(-23.21), SIMDE_BFLOAT16_VALUE(-16.75)},
     { {  SIMDE_BFLOAT16_VALUE(6.58), SIMDE_BFLOAT16_VALUE(39.56), SIMDE_BFLOAT16_VALUE(12.85), SIMDE_BFLOAT16_VALUE(-6.63) },
       {  SIMDE_BFLOAT16_VALUE(-23.21), SIMDE_BFLOAT16_VALUE(46.59), SIMDE_BFLOAT16_VALUE(22.79), SIMDE_BFLOAT16_VALUE(-13.35) },
       {  SIMDE_BFLOAT16_VALUE(-16.75), SIMDE_BFLOAT16_VALUE(-26.59), SIMDE_BFLOAT16_VALUE(19.00), SIMDE_BFLOAT16_VALUE(-16.99) } } },
   { { {  SIMDE_BFLOAT16_VALUE(-31.46), SIMDE_BFLOAT16_VALUE(30.50), SIMDE_BFLOAT16_VALUE(-31.78), SIMDE_BFLOAT16_VALUE(47.74) },
       {  SIMDE_BFLOAT16_VALUE(33.97), SIMDE_BFLOAT16_VALUE(37.16), SIMDE_BFLOAT16_VALUE(27.13), SIMDE_BFLOAT16_VALUE(-28.58) },
       {  SIMDE_BFLOAT16_VALUE(-7.95), SIMDE_BFLOAT16_VALUE(-26.73), SIMDE_BFLOAT16_VALUE(17.08), SIMDE_BFLOAT16_VALUE(39.81) } },
       {  SIMDE_BFLOAT16_VALUE(-28.19), SIMDE_BFLOAT16_VALUE(29.28), SIMDE_BFLOAT16_VALUE(-1.21)},
     { {  SIMDE_BFLOAT16_VALUE(-31.46), SIMDE_BFLOAT16_VALUE(-28.19), SIMDE_BFLOAT16_VALUE(-31.78), SIMDE_BFLOAT16_VALUE(47.74) },
       {  SIMDE_BFLOAT16_VALUE(33.97), SIMDE_BFLOAT16_VALUE(29.28), SIMDE_BFLOAT16_VALUE(27.13), SIMDE_BFLOAT16_VALUE(-28.58) },
       {  SIMDE_BFLOAT16_VALUE(-7.95), SIMDE_BFLOAT16_VALUE(-1.21), SIMDE_BFLOAT16_VALUE(17.08), SIMDE_BFLOAT16_VALUE(39.81) } } },
   { { {  SIMDE_BFLOAT16_VALUE(42.99), SIMDE_BFLOAT16_VALUE(-22.57), SIMDE_BFLOAT16_VALUE(-7.51), SIMDE_BFLOAT16_VALUE(-37.37) },
       {  SIMDE_BFLOAT16_VALUE(15.49), SIMDE_BFLOAT16_VALUE(-14.01), SIMDE_BFLOAT16_VALUE(30.43), SIMDE_BFLOAT16_VALUE(-22.10) },
       {  SIMDE_BFLOAT16_VALUE(-17.08), SIMDE_BFLOAT16_VALUE(28.40), SIMDE_BFLOAT16_VALUE(-3.15), SIMDE_BFLOAT16_VALUE(-9.72) } },
       {  SIMDE_BFLOAT16_VALUE(37.03), SIMDE_BFLOAT16_VALUE(-46.18), SIMDE_BFLOAT16_VALUE(30.55)},
     { {  SIMDE_BFLOAT16_VALUE(42.99), SIMDE_BFLOAT16_VALUE(-22.57), SIMDE_BFLOAT16_VALUE(37.03), SIMDE_BFLOAT16_VALUE(-37.37) },
       {  SIMDE_BFLOAT16_VALUE(15.49), SIMDE_BFLOAT16_VALUE(-14.01), SIMDE_BFLOAT16_VALUE(-46.18), SIMDE_BFLOAT16_VALUE(-22.10) },
       {  SIMDE_BFLOAT16_VALUE(-17.08), SIMDE_BFLOAT16_VALUE(28.40), SIMDE_BFLOAT16_VALUE(30.55), SIMDE_BFLOAT16_VALUE(-9.72) } } },
   { { {  SIMDE_BFLOAT16_VALUE(-27.48), SIMDE_BFLOAT16_VALUE(13.58), SIMDE_BFLOAT16_VALUE(-24.04), SIMDE_BFLOAT16_VALUE(4.66) },
       {  SIMDE_BFLOAT16_VALUE(29.23), SIMDE_BFLOAT16_VALUE(31.79), SIMDE_BFLOAT16_VALUE(-45.75), SIMDE_BFLOAT16_VALUE(38.47) },
       {  SIMDE_BFLOAT16_VALUE(-41.39), SIMDE_BFLOAT16_VALUE(-33.55), SIMDE_BFLOAT16_VALUE(-46.68), SIMDE_BFLOAT16_VALUE(19.26) } },
       {  SIMDE_BFLOAT16_VALUE(39.57), SIMDE_BFLOAT16_VALUE(-22.13), SIMDE_BFLOAT16_VALUE(6.04)},
     { {  SIMDE_BFLOAT16_VALUE(-27.48), SIMDE_BFLOAT16_VALUE(13.58), SIMDE_BFLOAT16_VALUE(-24.04), SIMDE_BFLOAT16_VALUE(39.57) },
       {  SIMDE_BFLOAT16_VALUE(29.23), SIMDE_BFLOAT16_VALUE(31.79), SIMDE_BFLOAT16_VALUE(-45.75), SIMDE_BFLOAT16_VALUE(-22.13) },
       {  SIMDE_BFLOAT16_VALUE(-41.39), SIMDE_BFLOAT16_VALUE(-33.55), SIMDE_BFLOAT16_VALUE(-46.68), SIMDE_BFLOAT16_VALUE(6.04) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_bfloat16x4x3_t r, src, expected;
    src.val[0] = simde_vld1_bf16(test_vec[i].src[0]);
    src.val[1] = simde_vld1_bf16(test_vec[i].src[1]);
    src.val[2] = simde_vld1_bf16(test_vec[i].src[2]);

    SIMDE_CONSTIFY_4_(simde_vld3_lane_bf16, r, (HEDLEY_UNREACHABLE(), r), i, test_vec[i].buf, src);

    expected.val[0] = simde_vld1_bf16(test_vec[i].r[0]);
    expected.val[1] = simde_vld1_bf16(test_vec[i].r[1]);
    expected.val[2] = simde_vld1_bf16(test_vec[i].r[2]);

    simde_test_arm_neon_assert_equal_bf16x4(r.val[0], expected.val[0], INT_MAX);
    simde_test_arm_neon_assert_equal_bf16x4(r.val[1], expected.val[1], INT_MAX);
    simde_test_arm_neon_assert_equal_bf16x4(r.val[2], expected.val[2], INT_MAX);
  }

  return 0;
}

static int
test_simde_vld3q_lane_bf16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_bfloat16_t src[3][8];
    simde_bfloat16_t buf[3];
    simde_bfloat16_t r[3][8];
  } test_vec[] = {
   { { {  SIMDE_BFLOAT16_VALUE(25.81), SIMDE_BFLOAT16_VALUE(32.75), SIMDE_BFLOAT16_VALUE(23.73), SIMDE_BFLOAT16_VALUE(-45.72),
        SIMDE_BFLOAT16_VALUE(21.87), SIMDE_BFLOAT16_VALUE(8.97), SIMDE_BFLOAT16_VALUE(-15.67), SIMDE_BFLOAT16_VALUE(26.89) },
       {  SIMDE_BFLOAT16_VALUE(16.63), SIMDE_BFLOAT16_VALUE(6.70), SIMDE_BFLOAT16_VALUE(26.16), SIMDE_BFLOAT16_VALUE(-0.53),
        SIMDE_BFLOAT16_VALUE(-39.38), SIMDE_BFLOAT16_VALUE(-30.03), SIMDE_BFLOAT16_VALUE(33.53), SIMDE_BFLOAT16_VALUE(-5.08) },
       {  SIMDE_BFLOAT16_VALUE(24.18), SIMDE_BFLOAT16_VALUE(-0.77), SIMDE_BFLOAT16_VALUE(-38.76), SIMDE_BFLOAT16_VALUE(23.74),
        SIMDE_BFLOAT16_VALUE(-37.79), SIMDE_BFLOAT16_VALUE(-12.87), SIMDE_BFLOAT16_VALUE(35.22), SIMDE_BFLOAT16_VALUE(18.82) } },
       {  SIMDE_BFLOAT16_VALUE(18.75), SIMDE_BFLOAT16_VALUE(-19.33), SIMDE_BFLOAT16_VALUE(-8.32)},
     { {  SIMDE_BFLOAT16_VALUE(18.75), SIMDE_BFLOAT16_VALUE(32.75), SIMDE_BFLOAT16_VALUE(23.73), SIMDE_BFLOAT16_VALUE(-45.72),
        SIMDE_BFLOAT16_VALUE(21.87), SIMDE_BFLOAT16_VALUE(8.97), SIMDE_BFLOAT16_VALUE(-15.67), SIMDE_BFLOAT16_VALUE(26.89) },
       {  SIMDE_BFLOAT16_VALUE(-19.33), SIMDE_BFLOAT16_VALUE(6.70), SIMDE_BFLOAT16_VALUE(26.16), SIMDE_BFLOAT16_VALUE(-0.53),
        SIMDE_BFLOAT16_VALUE(-39.38), SIMDE_BFLOAT16_VALUE(-30.03), SIMDE_BFLOAT16_VALUE(33.53), SIMDE_BFLOAT16_VALUE(-5.08) },
       {  SIMDE_BFLOAT16_VALUE(-8.32), SIMDE_BFLOAT16_VALUE(-0.77), SIMDE_BFLOAT16_VALUE(-38.76), SIMDE_BFLOAT16_VALUE(23.74),
        SIMDE_BFLOAT16_VALUE(-37.79), SIMDE_BFLOAT16_VALUE(-12.87), SIMDE_BFLOAT16_VALUE(35.22), SIMDE_BFLOAT16_VALUE(18.82) } } },
   { { {  SIMDE_BFLOAT16_VALUE(-21.87), SIMDE_BFLOAT16_VALUE(-23.46), SIMDE_BFLOAT16_VALUE(43.50), SIMDE_BFLOAT16_VALUE(-42.37),
        SIMDE_BFLOAT16_VALUE(38.96), SIMDE_BFLOAT16_VALUE(-39.73), SIMDE_BFLOAT16_VALUE(1.99), SIMDE_BFLOAT16_VALUE(13.47) },
       {  SIMDE_BFLOAT16_VALUE(-21.30), SIMDE_BFLOAT16_VALUE(31.71), SIMDE_BFLOAT16_VALUE(43.14), SIMDE_BFLOAT16_VALUE(6.05),
        SIMDE_BFLOAT16_VALUE(-9.36), SIMDE_BFLOAT16_VALUE(31.44), SIMDE_BFLOAT16_VALUE(-1.40), SIMDE_BFLOAT16_VALUE(-46.83) },
       {  SIMDE_BFLOAT16_VALUE(22.32), SIMDE_BFLOAT16_VALUE(-30.37), SIMDE_BFLOAT16_VALUE(-16.31), SIMDE_BFLOAT16_VALUE(48.67),
        SIMDE_BFLOAT16_VALUE(-32.26), SIMDE_BFLOAT16_VALUE(-43.03), SIMDE_BFLOAT16_VALUE(-31.49), SIMDE_BFLOAT16_VALUE(-29.73) } },
       {  SIMDE_BFLOAT16_VALUE(-19.96), SIMDE_BFLOAT16_VALUE(16.11), SIMDE_BFLOAT16_VALUE(15.29)},
     { {  SIMDE_BFLOAT16_VALUE(-21.87), SIMDE_BFLOAT16_VALUE(-19.96), SIMDE_BFLOAT16_VALUE(43.50), SIMDE_BFLOAT16_VALUE(-42.37),
        SIMDE_BFLOAT16_VALUE(38.96), SIMDE_BFLOAT16_VALUE(-39.73), SIMDE_BFLOAT16_VALUE(1.99), SIMDE_BFLOAT16_VALUE(13.47) },
       {  SIMDE_BFLOAT16_VALUE(-21.30), SIMDE_BFLOAT16_VALUE(16.11), SIMDE_BFLOAT16_VALUE(43.14), SIMDE_BFLOAT16_VALUE(6.05),
        SIMDE_BFLOAT16_VALUE(-9.36), SIMDE_BFLOAT16_VALUE(31.44), SIMDE_BFLOAT16_VALUE(-1.40), SIMDE_BFLOAT16_VALUE(-46.83) },
       {  SIMDE_BFLOAT16_VALUE(22.32), SIMDE_BFLOAT16_VALUE(15.29), SIMDE_BFLOAT16_VALUE(-16.31), SIMDE_BFLOAT16_VALUE(48.67),
        SIMDE_BFLOAT16_VALUE(-32.26), SIMDE_BFLOAT16_VALUE(-43.03), SIMDE_BFLOAT16_VALUE(-31.49), SIMDE_BFLOAT16_VALUE(-29.73) } } },
   { { {  SIMDE_BFLOAT16_VALUE(22.99), SIMDE_BFLOAT16_VALUE(19.29), SIMDE_BFLOAT16_VALUE(-46.27), SIMDE_BFLOAT16_VALUE(-49.21),
        SIMDE_BFLOAT16_VALUE(48.55), SIMDE_BFLOAT16_VALUE(49.51), SIMDE_BFLOAT16_VALUE(1.68), SIMDE_BFLOAT16_VALUE(4.07) },
       {  SIMDE_BFLOAT16_VALUE(-8.20), SIMDE_BFLOAT16_VALUE(5.11), SIMDE_BFLOAT16_VALUE(17.40), SIMDE_BFLOAT16_VALUE(-3.87),
        SIMDE_BFLOAT16_VALUE(-20.55), SIMDE_BFLOAT16_VALUE(19.44), SIMDE_BFLOAT16_VALUE(-49.04), SIMDE_BFLOAT16_VALUE(-1.42) },
       {  SIMDE_BFLOAT16_VALUE(22.33), SIMDE_BFLOAT16_VALUE(-45.53), SIMDE_BFLOAT16_VALUE(-33.31), SIMDE_BFLOAT16_VALUE(-20.16),
        SIMDE_BFLOAT16_VALUE(-39.51), SIMDE_BFLOAT16_VALUE(-20.23), SIMDE_BFLOAT16_VALUE(-41.96), SIMDE_BFLOAT16_VALUE(-27.75) } },
       {  SIMDE_BFLOAT16_VALUE(21.67), SIMDE_BFLOAT16_VALUE(-1.62), SIMDE_BFLOAT16_VALUE(47.29)},
     { {  SIMDE_BFLOAT16_VALUE(22.99), SIMDE_BFLOAT16_VALUE(19.29), SIMDE_BFLOAT16_VALUE(21.67), SIMDE_BFLOAT16_VALUE(-49.21),
        SIMDE_BFLOAT16_VALUE(48.55), SIMDE_BFLOAT16_VALUE(49.51), SIMDE_BFLOAT16_VALUE(1.68), SIMDE_BFLOAT16_VALUE(4.07) },
       {  SIMDE_BFLOAT16_VALUE(-8.20), SIMDE_BFLOAT16_VALUE(5.11), SIMDE_BFLOAT16_VALUE(-1.62), SIMDE_BFLOAT16_VALUE(-3.87),
        SIMDE_BFLOAT16_VALUE(-20.55), SIMDE_BFLOAT16_VALUE(19.44), SIMDE_BFLOAT16_VALUE(-49.04), SIMDE_BFLOAT16_VALUE(-1.42) },
       {  SIMDE_BFLOAT16_VALUE(22.33), SIMDE_BFLOAT16_VALUE(-45.53), SIMDE_BFLOAT16_VALUE(47.29), SIMDE_BFLOAT16_VALUE(-20.16),
        SIMDE_BFLOAT16_VALUE(-39.51), SIMDE_BFLOAT16_VALUE(-20.23), SIMDE_BFLOAT16_VALUE(-41.96), SIMDE_BFLOAT16_VALUE(-27.75) } } },
   { { {  SIMDE_BFLOAT16_VALUE(-13.98), SIMDE_BFLOAT16_VALUE(-15.40), SIMDE_BFLOAT16_VALUE(-41.40), SIMDE_BFLOAT16_VALUE(-11.10),
        SIMDE_BFLOAT16_VALUE(-0.98), SIMDE_BFLOAT16_VALUE(20.30), SIMDE_BFLOAT16_VALUE(-21.19), SIMDE_BFLOAT16_VALUE(32.22) },
       {  SIMDE_BFLOAT16_VALUE(-29.71), SIMDE_BFLOAT16_VALUE(-33.61), SIMDE_BFLOAT16_VALUE(-34.96), SIMDE_BFLOAT16_VALUE(22.05),
        SIMDE_BFLOAT16_VALUE(-46.85), SIMDE_BFLOAT16_VALUE(49.18), SIMDE_BFLOAT16_VALUE(29.80), SIMDE_BFLOAT16_VALUE(15.12) },
       {  SIMDE_BFLOAT16_VALUE(-48.25), SIMDE_BFLOAT16_VALUE(20.21), SIMDE_BFLOAT16_VALUE(30.89), SIMDE_BFLOAT16_VALUE(-8.00),
        SIMDE_BFLOAT16_VALUE(47.59), SIMDE_BFLOAT16_VALUE(-33.30), SIMDE_BFLOAT16_VALUE(-17.17), SIMDE_BFLOAT16_VALUE(15.96) } },
       {  SIMDE_BFLOAT16_VALUE(-22.71), SIMDE_BFLOAT16_VALUE(18.03), SIMDE_BFLOAT16_VALUE(-12.62)},
     { {  SIMDE_BFLOAT16_VALUE(-13.98), SIMDE_BFLOAT16_VALUE(-15.40), SIMDE_BFLOAT16_VALUE(-41.40), SIMDE_BFLOAT16_VALUE(-22.71),
        SIMDE_BFLOAT16_VALUE(-0.98), SIMDE_BFLOAT16_VALUE(20.30), SIMDE_BFLOAT16_VALUE(-21.19), SIMDE_BFLOAT16_VALUE(32.22) },
       {  SIMDE_BFLOAT16_VALUE(-29.71), SIMDE_BFLOAT16_VALUE(-33.61), SIMDE_BFLOAT16_VALUE(-34.96), SIMDE_BFLOAT16_VALUE(18.03),
        SIMDE_BFLOAT16_VALUE(-46.85), SIMDE_BFLOAT16_VALUE(49.18), SIMDE_BFLOAT16_VALUE(29.80), SIMDE_BFLOAT16_VALUE(15.12) },
       {  SIMDE_BFLOAT16_VALUE(-48.25), SIMDE_BFLOAT16_VALUE(20.21), SIMDE_BFLOAT16_VALUE(30.89), SIMDE_BFLOAT16_VALUE(-12.62),
        SIMDE_BFLOAT16_VALUE(47.59), SIMDE_BFLOAT16_VALUE(-33.30), SIMDE_BFLOAT16_VALUE(-17.17), SIMDE_BFLOAT16_VALUE(15.96) } } },
   { { {  SIMDE_BFLOAT16_VALUE(-33.16), SIMDE_BFLOAT16_VALUE(41.77), SIMDE_BFLOAT16_VALUE(0.37), SIMDE_BFLOAT16_VALUE(49.97),
        SIMDE_BFLOAT16_VALUE(41.81), SIMDE_BFLOAT16_VALUE(-38.26), SIMDE_BFLOAT16_VALUE(36.03), SIMDE_BFLOAT16_VALUE(-6.12) },
       {  SIMDE_BFLOAT16_VALUE(45.98), SIMDE_BFLOAT16_VALUE(33.57), SIMDE_BFLOAT16_VALUE(4.26), SIMDE_BFLOAT16_VALUE(19.87),
        SIMDE_BFLOAT16_VALUE(6.49), SIMDE_BFLOAT16_VALUE(3.23), SIMDE_BFLOAT16_VALUE(17.28), SIMDE_BFLOAT16_VALUE(-0.70) },
       {  SIMDE_BFLOAT16_VALUE(-45.21), SIMDE_BFLOAT16_VALUE(10.70), SIMDE_BFLOAT16_VALUE(-30.89), SIMDE_BFLOAT16_VALUE(17.48),
        SIMDE_BFLOAT16_VALUE(-18.12), SIMDE_BFLOAT16_VALUE(-36.32), SIMDE_BFLOAT16_VALUE(12.70), SIMDE_BFLOAT16_VALUE(-9.89) } },
       {  SIMDE_BFLOAT16_VALUE(19.50), SIMDE_BFLOAT16_VALUE(43.23), SIMDE_BFLOAT16_VALUE(-34.14)},
     { {  SIMDE_BFLOAT16_VALUE(-33.16), SIMDE_BFLOAT16_VALUE(41.77), SIMDE_BFLOAT16_VALUE(0.37), SIMDE_BFLOAT16_VALUE(49.97),
        SIMDE_BFLOAT16_VALUE(19.50), SIMDE_BFLOAT16_VALUE(-38.26), SIMDE_BFLOAT16_VALUE(36.03), SIMDE_BFLOAT16_VALUE(-6.12) },
       {  SIMDE_BFLOAT16_VALUE(45.98), SIMDE_BFLOAT16_VALUE(33.57), SIMDE_BFLOAT16_VALUE(4.26), SIMDE_BFLOAT16_VALUE(19.87),
        SIMDE_BFLOAT16_VALUE(43.23), SIMDE_BFLOAT16_VALUE(3.23), SIMDE_BFLOAT16_VALUE(17.28), SIMDE_BFLOAT16_VALUE(-0.70) },
       {  SIMDE_BFLOAT16_VALUE(-45.21), SIMDE_BFLOAT16_VALUE(10.70), SIMDE_BFLOAT16_VALUE(-30.89), SIMDE_BFLOAT16_VALUE(17.48),
        SIMDE_BFLOAT16_VALUE(-34.14), SIMDE_BFLOAT16_VALUE(-36.32), SIMDE_BFLOAT16_VALUE(12.70), SIMDE_BFLOAT16_VALUE(-9.89) } } },
   { { {  SIMDE_BFLOAT16_VALUE(34.35), SIMDE_BFLOAT16_VALUE(45.11), SIMDE_BFLOAT16_VALUE(-17.38), SIMDE_BFLOAT16_VALUE(32.13),
        SIMDE_BFLOAT16_VALUE(-19.58), SIMDE_BFLOAT16_VALUE(-5.73), SIMDE_BFLOAT16_VALUE(-14.12), SIMDE_BFLOAT16_VALUE(-0.42) },
       {  SIMDE_BFLOAT16_VALUE(-17.04), SIMDE_BFLOAT16_VALUE(40.80), SIMDE_BFLOAT16_VALUE(-45.80), SIMDE_BFLOAT16_VALUE(37.28),
        SIMDE_BFLOAT16_VALUE(35.24), SIMDE_BFLOAT16_VALUE(40.83), SIMDE_BFLOAT16_VALUE(41.86), SIMDE_BFLOAT16_VALUE(16.76) },
       {  SIMDE_BFLOAT16_VALUE(44.82), SIMDE_BFLOAT16_VALUE(44.21), SIMDE_BFLOAT16_VALUE(-16.87), SIMDE_BFLOAT16_VALUE(28.04),
        SIMDE_BFLOAT16_VALUE(12.42), SIMDE_BFLOAT16_VALUE(-24.77), SIMDE_BFLOAT16_VALUE(-2.03), SIMDE_BFLOAT16_VALUE(6.16) } },
       {  SIMDE_BFLOAT16_VALUE(24.51), SIMDE_BFLOAT16_VALUE(-14.45), SIMDE_BFLOAT16_VALUE(-29.20)},
     { {  SIMDE_BFLOAT16_VALUE(34.35), SIMDE_BFLOAT16_VALUE(45.11), SIMDE_BFLOAT16_VALUE(-17.38), SIMDE_BFLOAT16_VALUE(32.13),
        SIMDE_BFLOAT16_VALUE(-19.58), SIMDE_BFLOAT16_VALUE(24.51), SIMDE_BFLOAT16_VALUE(-14.12), SIMDE_BFLOAT16_VALUE(-0.42) },
       {  SIMDE_BFLOAT16_VALUE(-17.04), SIMDE_BFLOAT16_VALUE(40.80), SIMDE_BFLOAT16_VALUE(-45.80), SIMDE_BFLOAT16_VALUE(37.28),
        SIMDE_BFLOAT16_VALUE(35.24), SIMDE_BFLOAT16_VALUE(-14.45), SIMDE_BFLOAT16_VALUE(41.86), SIMDE_BFLOAT16_VALUE(16.76) },
       {  SIMDE_BFLOAT16_VALUE(44.82), SIMDE_BFLOAT16_VALUE(44.21), SIMDE_BFLOAT16_VALUE(-16.87), SIMDE_BFLOAT16_VALUE(28.04),
        SIMDE_BFLOAT16_VALUE(12.42), SIMDE_BFLOAT16_VALUE(-29.20), SIMDE_BFLOAT16_VALUE(-2.03), SIMDE_BFLOAT16_VALUE(6.16) } } },
   { { {  SIMDE_BFLOAT16_VALUE(-19.86), SIMDE_BFLOAT16_VALUE(-49.12), SIMDE_BFLOAT16_VALUE(-43.11), SIMDE_BFLOAT16_VALUE(6.61),
        SIMDE_BFLOAT16_VALUE(-14.42), SIMDE_BFLOAT16_VALUE(-26.68), SIMDE_BFLOAT16_VALUE(-14.21), SIMDE_BFLOAT16_VALUE(-19.62) },
       {  SIMDE_BFLOAT16_VALUE(2.80), SIMDE_BFLOAT16_VALUE(21.66), SIMDE_BFLOAT16_VALUE(-36.49), SIMDE_BFLOAT16_VALUE(-15.12),
        SIMDE_BFLOAT16_VALUE(-49.41), SIMDE_BFLOAT16_VALUE(-26.19), SIMDE_BFLOAT16_VALUE(-24.23), SIMDE_BFLOAT16_VALUE(36.09) },
       {  SIMDE_BFLOAT16_VALUE(10.26), SIMDE_BFLOAT16_VALUE(31.20), SIMDE_BFLOAT16_VALUE(-42.59), SIMDE_BFLOAT16_VALUE(22.36),
        SIMDE_BFLOAT16_VALUE(-1.95), SIMDE_BFLOAT16_VALUE(-8.53), SIMDE_BFLOAT16_VALUE(37.02), SIMDE_BFLOAT16_VALUE(-47.32) } },
       {  SIMDE_BFLOAT16_VALUE(-2.66), SIMDE_BFLOAT16_VALUE(-28.19), SIMDE_BFLOAT16_VALUE(-49.39)},
     { {  SIMDE_BFLOAT16_VALUE(-19.86), SIMDE_BFLOAT16_VALUE(-49.12), SIMDE_BFLOAT16_VALUE(-43.11), SIMDE_BFLOAT16_VALUE(6.61),
        SIMDE_BFLOAT16_VALUE(-14.42), SIMDE_BFLOAT16_VALUE(-26.68), SIMDE_BFLOAT16_VALUE(-2.66), SIMDE_BFLOAT16_VALUE(-19.62) },
       {  SIMDE_BFLOAT16_VALUE(2.80), SIMDE_BFLOAT16_VALUE(21.66), SIMDE_BFLOAT16_VALUE(-36.49), SIMDE_BFLOAT16_VALUE(-15.12),
        SIMDE_BFLOAT16_VALUE(-49.41), SIMDE_BFLOAT16_VALUE(-26.19), SIMDE_BFLOAT16_VALUE(-28.19), SIMDE_BFLOAT16_VALUE(36.09) },
       {  SIMDE_BFLOAT16_VALUE(10.26), SIMDE_BFLOAT16_VALUE(31.20), SIMDE_BFLOAT16_VALUE(-42.59), SIMDE_BFLOAT16_VALUE(22.36),
        SIMDE_BFLOAT16_VALUE(-1.95), SIMDE_BFLOAT16_VALUE(-8.53), SIMDE_BFLOAT16_VALUE(-49.39), SIMDE_BFLOAT16_VALUE(-47.32) } } },
   { { {  SIMDE_BFLOAT16_VALUE(0.30), SIMDE_BFLOAT16_VALUE(6.73), SIMDE_BFLOAT16_VALUE(-6.28), SIMDE_BFLOAT16_VALUE(35.22),
        SIMDE_BFLOAT16_VALUE(-5.78), SIMDE_BFLOAT16_VALUE(-32.42), SIMDE_BFLOAT16_VALUE(-25.16), SIMDE_BFLOAT16_VALUE(14.50) },
       {  SIMDE_BFLOAT16_VALUE(9.20), SIMDE_BFLOAT16_VALUE(15.26), SIMDE_BFLOAT16_VALUE(14.27), SIMDE_BFLOAT16_VALUE(24.06),
        SIMDE_BFLOAT16_VALUE(9.76), SIMDE_BFLOAT16_VALUE(-32.84), SIMDE_BFLOAT16_VALUE(23.54), SIMDE_BFLOAT16_VALUE(-38.60) },
       {  SIMDE_BFLOAT16_VALUE(-2.89), SIMDE_BFLOAT16_VALUE(-12.52), SIMDE_BFLOAT16_VALUE(-24.22), SIMDE_BFLOAT16_VALUE(45.18),
        SIMDE_BFLOAT16_VALUE(-49.48), SIMDE_BFLOAT16_VALUE(-38.06), SIMDE_BFLOAT16_VALUE(0.89), SIMDE_BFLOAT16_VALUE(-2.25) } },
       {  SIMDE_BFLOAT16_VALUE(2.18), SIMDE_BFLOAT16_VALUE(35.99), SIMDE_BFLOAT16_VALUE(26.18)},
     { {  SIMDE_BFLOAT16_VALUE(0.30), SIMDE_BFLOAT16_VALUE(6.73), SIMDE_BFLOAT16_VALUE(-6.28), SIMDE_BFLOAT16_VALUE(35.22),
        SIMDE_BFLOAT16_VALUE(-5.78), SIMDE_BFLOAT16_VALUE(-32.42), SIMDE_BFLOAT16_VALUE(-25.16), SIMDE_BFLOAT16_VALUE(2.18) },
       {  SIMDE_BFLOAT16_VALUE(9.20), SIMDE_BFLOAT16_VALUE(15.26), SIMDE_BFLOAT16_VALUE(14.27), SIMDE_BFLOAT16_VALUE(24.06),
        SIMDE_BFLOAT16_VALUE(9.76), SIMDE_BFLOAT16_VALUE(-32.84), SIMDE_BFLOAT16_VALUE(23.54), SIMDE_BFLOAT16_VALUE(35.99) },
       {  SIMDE_BFLOAT16_VALUE(-2.89), SIMDE_BFLOAT16_VALUE(-12.52), SIMDE_BFLOAT16_VALUE(-24.22), SIMDE_BFLOAT16_VALUE(45.18),
        SIMDE_BFLOAT16_VALUE(-49.48), SIMDE_BFLOAT16_VALUE(-38.06), SIMDE_BFLOAT16_VALUE(0.89), SIMDE_BFLOAT16_VALUE(26.18) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_bfloat16x8x3_t r, src, expected;
    src.val[0] = simde_vld1q_bf16(test_vec[i].src[0]);
    src.val[1] = simde_vld1q_bf16(test_vec[i].src[1]);
    src.val[2] = simde_vld1q_bf16(test_vec[i].src[2]);

    SIMDE_CONSTIFY_8_(simde_vld3q_lane_bf16, r, (HEDLEY_UNREACHABLE(), r), i, test_vec[i].buf, src);

    expected.val[0] = simde_vld1q_bf16(test_vec[i].r[0]);
    expected.val[1] = simde_vld1q_bf16(test_vec[i].r[1]);
    expected.val[2] = simde_vld1q_bf16(test_vec[i].r[2]);

    simde_test_arm_neon_assert_equal_bf16x8(r.val[0], expected.val[0], INT_MAX);
    simde_test_arm_neon_assert_equal_bf16x8(r.val[1], expected.val[1], INT_MAX);
    simde_test_arm_neon_assert_equal_bf16x8(r.val[2], expected.val[2], INT_MAX);
  }

  return 0;
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vld3_lane_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vld3_lane_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vld3_lane_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vld3_lane_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vld3_lane_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vld3_lane_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vld3_lane_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vld3_lane_u64)
SIMDE_TEST_FUNC_LIST_ENTRY(vld3_lane_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vld3_lane_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vld3_lane_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vld3q_lane_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vld3q_lane_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vld3q_lane_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vld3q_lane_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vld3q_lane_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vld3q_lane_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vld3q_lane_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vld3q_lane_u64)
SIMDE_TEST_FUNC_LIST_ENTRY(vld3q_lane_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vld3q_lane_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vld3q_lane_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vld3_lane_p8)
SIMDE_TEST_FUNC_LIST_ENTRY(vld3_lane_p16)
SIMDE_TEST_FUNC_LIST_ENTRY(vld3_lane_p64)
SIMDE_TEST_FUNC_LIST_ENTRY(vld3q_lane_p8)
SIMDE_TEST_FUNC_LIST_ENTRY(vld3q_lane_p16)
SIMDE_TEST_FUNC_LIST_ENTRY(vld3q_lane_p64)
SIMDE_TEST_FUNC_LIST_ENTRY(vld3_lane_bf16)
SIMDE_TEST_FUNC_LIST_ENTRY(vld3q_lane_bf16)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
