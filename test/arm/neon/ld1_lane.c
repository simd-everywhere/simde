#define SIMDE_TEST_ARM_NEON_INSN ld1_lane

#include "test-neon.h"
#include "../../../simde/arm/neon/ld1_lane.h"
#include "../../../simde/arm/neon/ld1.h"

static int
test_simde_vld1_lane_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t src[8];
    int8_t buf;
    int8_t r[8];
  } test_vec[] = {
    { { -INT8_C(  55), -INT8_C(  75), -INT8_C(   8),  INT8_C( 112),      INT8_MIN,  INT8_C( 101),  INT8_C(  50),  INT8_C(  24) },
       INT8_C(  45),
      {  INT8_C(  45), -INT8_C(  75), -INT8_C(   8),  INT8_C( 112),      INT8_MIN,  INT8_C( 101),  INT8_C(  50),  INT8_C(  24) } },
    { { -INT8_C( 110), -INT8_C(  74), -INT8_C(  44), -INT8_C( 100), -INT8_C(   5),  INT8_C(  37),  INT8_C(  90),  INT8_C(  77) },
       INT8_C( 125),
      { -INT8_C( 110),  INT8_C( 125), -INT8_C(  44), -INT8_C( 100), -INT8_C(   5),  INT8_C(  37),  INT8_C(  90),  INT8_C(  77) } },
    { { -INT8_C(   3),  INT8_C(  44),  INT8_C(  39),  INT8_C(  17), -INT8_C(  12),  INT8_C(  69),  INT8_C( 111),  INT8_C(  66) },
      -INT8_C(  34),
      { -INT8_C(   3),  INT8_C(  44), -INT8_C(  34),  INT8_C(  17), -INT8_C(  12),  INT8_C(  69),  INT8_C( 111),  INT8_C(  66) } },
    { { -INT8_C(  86),  INT8_C( 120), -INT8_C(  99), -INT8_C(   1),  INT8_C(  65),  INT8_C(  82), -INT8_C(   9), -INT8_C(  79) },
      -INT8_C(  46),
      { -INT8_C(  86),  INT8_C( 120), -INT8_C(  99), -INT8_C(  46),  INT8_C(  65),  INT8_C(  82), -INT8_C(   9), -INT8_C(  79) } },
    { {  INT8_C(  92), -INT8_C(  29), -INT8_C(  22), -INT8_C( 119),  INT8_C( 118), -INT8_C(  96),  INT8_C(  94),  INT8_C(  18) },
      -INT8_C( 101),
      {  INT8_C(  92), -INT8_C(  29), -INT8_C(  22), -INT8_C( 119), -INT8_C( 101), -INT8_C(  96),  INT8_C(  94),  INT8_C(  18) } },
    { { -INT8_C( 125),  INT8_C( 108), -INT8_C(  23),  INT8_C(   0),  INT8_C( 106),  INT8_C(  21),  INT8_C(  40),  INT8_C( 123) },
       INT8_C(   9),
      { -INT8_C( 125),  INT8_C( 108), -INT8_C(  23),  INT8_C(   0),  INT8_C( 106),  INT8_C(   9),  INT8_C(  40),  INT8_C( 123) } },
    { {  INT8_C( 109), -INT8_C(  22),  INT8_C(  75),  INT8_C(  75), -INT8_C( 108), -INT8_C(  61), -INT8_C(  23), -INT8_C( 109) },
       INT8_C(   4),
      {  INT8_C( 109), -INT8_C(  22),  INT8_C(  75),  INT8_C(  75), -INT8_C( 108), -INT8_C(  61),  INT8_C(   4), -INT8_C( 109) } },
    { {  INT8_C(  59), -INT8_C( 118), -INT8_C(  75),  INT8_C(  14), -INT8_C(  26), -INT8_C( 103), -INT8_C(   8),  INT8_C( 111) },
       INT8_C(  15),
      {  INT8_C(  59), -INT8_C( 118), -INT8_C(  75),  INT8_C(  14), -INT8_C(  26), -INT8_C( 103), -INT8_C(   8),  INT8_C(  15) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8_t r, src, expected;
    src = simde_vld1_s8(test_vec[i].src);

    SIMDE_CONSTIFY_8_(simde_vld1_lane_s8, r, (HEDLEY_UNREACHABLE(), r), i, &test_vec[i].buf, src);

    expected = simde_vld1_s8(test_vec[i].r);

    simde_test_arm_neon_assert_equal_i8x8(r, expected);
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x8_t src = simde_test_arm_neon_random_i8x8();
    simde_test_arm_neon_write_i8x8(2, src, SIMDE_TEST_VEC_POS_FIRST);
    int8_t buf = simde_test_codegen_random_i8();
    simde_test_codegen_write_i8(2, buf, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_int8x8_t r;
    SIMDE_CONSTIFY_8_(simde_vld1_lane_s8, r, (HEDLEY_UNREACHABLE(), r), i, &buf, src);
    simde_test_arm_neon_write_i8x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld1_lane_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t src[4];
    int16_t buf;
    int16_t r[4];
  } test_vec[] = {
    { {  INT16_C( 19347),  INT16_C( 17766),  INT16_C( 23239), -INT16_C( 30206) },
      -INT16_C( 32260),
      { -INT16_C( 32260),  INT16_C( 17766),  INT16_C( 23239), -INT16_C( 30206) } },
    { {  INT16_C( 25790),  INT16_C( 13609),  INT16_C( 14273), -INT16_C( 12881) },
      -INT16_C( 17258),
      {  INT16_C( 25790), -INT16_C( 17258),  INT16_C( 14273), -INT16_C( 12881) } },
    { {  INT16_C( 26888),  INT16_C(  9050), -INT16_C( 18228),  INT16_C( 29801) },
      -INT16_C( 31716),
      {  INT16_C( 26888),  INT16_C(  9050), -INT16_C( 31716),  INT16_C( 29801) } },
    { { -INT16_C( 20441), -INT16_C( 29233), -INT16_C( 26635), -INT16_C(  2073) },
      -INT16_C(  7135),
      { -INT16_C( 20441), -INT16_C( 29233), -INT16_C( 26635), -INT16_C(  7135) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t r, src, expected;
    src = simde_vld1_s16(test_vec[i].src);

    SIMDE_CONSTIFY_4_(simde_vld1_lane_s16, r, (HEDLEY_UNREACHABLE(), r), i, &test_vec[i].buf, src);

    expected = simde_vld1_s16(test_vec[i].r);

    simde_test_arm_neon_assert_equal_i16x4(r, expected);
  }

  return 0;
#else
  for (int i = 0 ; i < 4 ; i++) {
    simde_int16x4_t src = simde_test_arm_neon_random_i16x4();
    simde_test_arm_neon_write_i16x4(2, src, SIMDE_TEST_VEC_POS_FIRST);
    int16_t buf = simde_test_codegen_random_i16();
    simde_test_codegen_write_i16(2, buf, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_int16x4_t r;
    SIMDE_CONSTIFY_4_(simde_vld1_lane_s16, r, (HEDLEY_UNREACHABLE(), r), i, &buf, src);
    simde_test_arm_neon_write_i16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld1_lane_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t src[2];
    int32_t buf;
    int32_t r[2];
  } test_vec[] = {
    { { -INT32_C(  1104754807),  INT32_C(  2135949966) },
      -INT32_C(   116713766),
      { -INT32_C(   116713766),  INT32_C(  2135949966) } },
    { { -INT32_C(  1952710930), -INT32_C(   636410658) },
       INT32_C(  1338714941),
      { -INT32_C(  1952710930),  INT32_C(  1338714941) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t r, src, expected;
    src = simde_vld1_s32(test_vec[i].src);

    SIMDE_CONSTIFY_2_(simde_vld1_lane_s32, r, (HEDLEY_UNREACHABLE(), r), i, &test_vec[i].buf, src);

    expected = simde_vld1_s32(test_vec[i].r);

    simde_test_arm_neon_assert_equal_i32x2(r, expected);
  }

  return 0;
#else
  for (int i = 0 ; i < 2 ; i++) {
    simde_int32x2_t src = simde_test_arm_neon_random_i32x2();
    simde_test_arm_neon_write_i32x2(2, src, SIMDE_TEST_VEC_POS_FIRST);
    int32_t buf = simde_test_codegen_random_i32();
    simde_test_codegen_write_i32(2, buf, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_int32x2_t r;
    SIMDE_CONSTIFY_2_(simde_vld1_lane_s32, r, (HEDLEY_UNREACHABLE(), r), i, &buf, src);
    simde_test_arm_neon_write_i32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld1_lane_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t src[1];
    int64_t buf;
    int64_t r[1];
  } test_vec[] = {
    { {  INT64_C( 7149379227895133833) },
       INT64_C( 2846293066403646557),
      {  INT64_C( 2846293066403646557) } },
    { { -INT64_C( 8816928758706757553) },
      -INT64_C( 8921826593701387128),
      { -INT64_C( 8921826593701387128) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x1_t src = simde_vld1_s64(test_vec[i].src);
    simde_int64x1_t r = simde_vld1_lane_s64(&test_vec[i].buf, src, 0);

    simde_int64x1_t expected = simde_vld1_s64(test_vec[i].r);

    simde_test_arm_neon_assert_equal_i64x1(r, expected);
  }

  return 0;
#else
  for (int i = 0 ; i < 2 ; i++) {
    simde_int64x1_t src = simde_test_arm_neon_random_i64x1();
    simde_test_arm_neon_write_i64x1(2, src, SIMDE_TEST_VEC_POS_FIRST);
    int64_t buf = simde_test_codegen_random_i64();
    simde_test_codegen_write_i64(2, buf, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_int64x1_t r;
    r = simde_vld1_lane_s64(&buf, src, 0);
    simde_test_arm_neon_write_i64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld1_lane_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t src[8];
    uint8_t buf;
    uint8_t r[8];
  } test_vec[] = {
    { { UINT8_C( 69), UINT8_C( 30), UINT8_C(202), UINT8_C( 17), UINT8_C( 59), UINT8_C(205), UINT8_C( 78), UINT8_C( 43) },
      UINT8_C(243),
      { UINT8_C(243), UINT8_C( 30), UINT8_C(202), UINT8_C( 17), UINT8_C( 59), UINT8_C(205), UINT8_C( 78), UINT8_C( 43) } },
    { { UINT8_C(131), UINT8_C( 91), UINT8_C(236), UINT8_C(239), UINT8_C(171), UINT8_C( 28), UINT8_C(194), UINT8_C(209) },
      UINT8_C( 89),
      { UINT8_C(131), UINT8_C( 89), UINT8_C(236), UINT8_C(239), UINT8_C(171), UINT8_C( 28), UINT8_C(194), UINT8_C(209) } },
    { { UINT8_C(124), UINT8_C( 85), UINT8_C(187), UINT8_C(111), UINT8_C(149), UINT8_C(105), UINT8_C( 82), UINT8_C(225) },
      UINT8_C(150),
      { UINT8_C(124), UINT8_C( 85), UINT8_C(150), UINT8_C(111), UINT8_C(149), UINT8_C(105), UINT8_C( 82), UINT8_C(225) } },
    { { UINT8_C(108), UINT8_C(147), UINT8_C(204), UINT8_C(247), UINT8_C(216), UINT8_C(234), UINT8_C(193), UINT8_C(233) },
      UINT8_C( 38),
      { UINT8_C(108), UINT8_C(147), UINT8_C(204), UINT8_C( 38), UINT8_C(216), UINT8_C(234), UINT8_C(193), UINT8_C(233) } },
    { { UINT8_C(143), UINT8_C( 56), UINT8_C( 81), UINT8_C(130), UINT8_C(187), UINT8_C(172), UINT8_C(111), UINT8_C(170) },
      UINT8_C( 87),
      { UINT8_C(143), UINT8_C( 56), UINT8_C( 81), UINT8_C(130), UINT8_C( 87), UINT8_C(172), UINT8_C(111), UINT8_C(170) } },
    { { UINT8_C(139), UINT8_C(108), UINT8_C( 40), UINT8_C(228), UINT8_C(232), UINT8_C(125), UINT8_C(159), UINT8_C( 87) },
      UINT8_C( 19),
      { UINT8_C(139), UINT8_C(108), UINT8_C( 40), UINT8_C(228), UINT8_C(232), UINT8_C( 19), UINT8_C(159), UINT8_C( 87) } },
    { { UINT8_C(  9), UINT8_C(170), UINT8_C(244), UINT8_C(159), UINT8_C( 22), UINT8_C(135), UINT8_C(108), UINT8_C( 14) },
      UINT8_C( 96),
      { UINT8_C(  9), UINT8_C(170), UINT8_C(244), UINT8_C(159), UINT8_C( 22), UINT8_C(135), UINT8_C( 96), UINT8_C( 14) } },
    { { UINT8_C( 86), UINT8_C(207), UINT8_C( 73), UINT8_C(124), UINT8_C( 94), UINT8_C(129), UINT8_C(205), UINT8_C(225) },
      UINT8_C( 60),
      { UINT8_C( 86), UINT8_C(207), UINT8_C( 73), UINT8_C(124), UINT8_C( 94), UINT8_C(129), UINT8_C(205), UINT8_C( 60) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x8_t r, src, expected;
    src = simde_vld1_u8(test_vec[i].src);

    SIMDE_CONSTIFY_8_(simde_vld1_lane_u8, r, (HEDLEY_UNREACHABLE(), r), i, &test_vec[i].buf, src);

    expected = simde_vld1_u8(test_vec[i].r);

    simde_test_arm_neon_assert_equal_u8x8(r, expected);
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8x8_t src = simde_test_arm_neon_random_u8x8();
    simde_test_arm_neon_write_u8x8(2, src, SIMDE_TEST_VEC_POS_FIRST);
    uint8_t buf = simde_test_codegen_random_u8();
    simde_test_codegen_write_u8(2, buf, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_uint8x8_t r;
    SIMDE_CONSTIFY_8_(simde_vld1_lane_u8, r, (HEDLEY_UNREACHABLE(), r), i, &buf, src);
    simde_test_arm_neon_write_u8x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld1_lane_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t src[4];
    uint16_t buf;
    uint16_t r[4];
  } test_vec[] = {
    { { UINT16_C(49660), UINT16_C(58705), UINT16_C(34786), UINT16_C(30542) },
      UINT16_C(48518),
      { UINT16_C(48518), UINT16_C(58705), UINT16_C(34786), UINT16_C(30542) } },
    { { UINT16_C(62377), UINT16_C(40854), UINT16_C(42223), UINT16_C(39172) },
      UINT16_C(62761),
      { UINT16_C(62377), UINT16_C(62761), UINT16_C(42223), UINT16_C(39172) } },
    { { UINT16_C(57555), UINT16_C(31014), UINT16_C(25314), UINT16_C(40612) },
      UINT16_C(59476),
      { UINT16_C(57555), UINT16_C(31014), UINT16_C(59476), UINT16_C(40612) } },
    { { UINT16_C(20564), UINT16_C(42665), UINT16_C(35637), UINT16_C(33837) },
      UINT16_C(45826),
      { UINT16_C(20564), UINT16_C(42665), UINT16_C(35637), UINT16_C(45826) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4_t r, src, expected;
    src = simde_vld1_u16(test_vec[i].src);

    SIMDE_CONSTIFY_4_(simde_vld1_lane_u16, r, (HEDLEY_UNREACHABLE(), r), i, &test_vec[i].buf, src);

    expected = simde_vld1_u16(test_vec[i].r);

    simde_test_arm_neon_assert_equal_u16x4(r, expected);
  }

  return 0;
#else
  for (int i = 0 ; i < 4 ; i++) {
    simde_uint16x4_t src = simde_test_arm_neon_random_u16x4();
    simde_test_arm_neon_write_u16x4(2, src, SIMDE_TEST_VEC_POS_FIRST);
    uint16_t buf = simde_test_codegen_random_u16();
    simde_test_codegen_write_u16(2, buf, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_uint16x4_t r;
    SIMDE_CONSTIFY_4_(simde_vld1_lane_u16, r, (HEDLEY_UNREACHABLE(), r), i, &buf, src);
    simde_test_arm_neon_write_u16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld1_lane_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t src[2];
    uint32_t buf;
    uint32_t r[2];
  } test_vec[] = {
    { { UINT32_C(3257715921), UINT32_C(2684269018) },
      UINT32_C(3089681982),
      { UINT32_C(3089681982), UINT32_C(2684269018) } },
    { { UINT32_C(1958854073), UINT32_C(3595729610) },
      UINT32_C(1853624174),
      { UINT32_C(1958854073), UINT32_C(1853624174) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2_t r, src, expected;
    src = simde_vld1_u32(test_vec[i].src);

    SIMDE_CONSTIFY_2_(simde_vld1_lane_u32, r, (HEDLEY_UNREACHABLE(), r), i, &test_vec[i].buf, src);

    expected = simde_vld1_u32(test_vec[i].r);

    simde_test_arm_neon_assert_equal_u32x2(r, expected);
  }

  return 0;
#else
  for (int i = 0 ; i < 2 ; i++) {
    simde_uint32x2_t src = simde_test_arm_neon_random_u32x2();
    simde_test_arm_neon_write_u32x2(2, src, SIMDE_TEST_VEC_POS_FIRST);
    uint32_t buf = simde_test_codegen_random_u32();
    simde_test_codegen_write_u32(2, buf, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_uint32x2_t r;
    SIMDE_CONSTIFY_2_(simde_vld1_lane_u32, r, (HEDLEY_UNREACHABLE(), r), i, &buf, src);
    simde_test_arm_neon_write_u32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld1_lane_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t src[1];
    uint64_t buf;
    uint64_t r[1];
  } test_vec[] = {
    { { UINT64_C(14981060459779388252) },
      UINT64_C( 1638082936137734683),
      { UINT64_C( 1638082936137734683) } },
    { { UINT64_C( 6837410834594238057) },
      UINT64_C( 8070199927570576967),
      { UINT64_C( 8070199927570576967) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x1_t src = simde_vld1_u64(test_vec[i].src);
    simde_uint64x1_t r = simde_vld1_lane_u64(&test_vec[i].buf, src, 0);

    simde_uint64x1_t expected = simde_vld1_u64(test_vec[i].r);

    simde_test_arm_neon_assert_equal_u64x1(r, expected);
  }

  return 0;
#else
  for (int i = 0 ; i < 2 ; i++) {
    simde_uint64x1_t src = simde_test_arm_neon_random_u64x1();
    simde_test_arm_neon_write_u64x1(2, src, SIMDE_TEST_VEC_POS_FIRST);
    uint64_t buf = simde_test_codegen_random_u64();
    simde_test_codegen_write_u64(2, buf, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_uint64x1_t r = simde_vld1_lane_u64(&buf, src, 0);
    simde_test_arm_neon_write_u64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld1_lane_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32_t src[2];
    simde_float32_t buf;
    simde_float32_t r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(    -5.93), SIMDE_FLOAT32_C(    20.02) },
      SIMDE_FLOAT32_C(    20.61),
      { SIMDE_FLOAT32_C(    20.61), SIMDE_FLOAT32_C(    20.02) } },
    { { SIMDE_FLOAT32_C(    71.16), SIMDE_FLOAT32_C(   -92.70) },
      SIMDE_FLOAT32_C(   -43.23),
      { SIMDE_FLOAT32_C(    71.16), SIMDE_FLOAT32_C(   -43.23) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t r, src, expected;
    src = simde_vld1_f32(test_vec[i].src);

    SIMDE_CONSTIFY_2_(simde_vld1_lane_f32, r, (HEDLEY_UNREACHABLE(), r), i, &test_vec[i].buf, src);

    expected = simde_vld1_f32(test_vec[i].r);

    simde_test_arm_neon_assert_equal_f32x2(r, expected, 1);
  }

  return 0;
#else
  for (int i = 0 ; i < 2 ; i++) {
    simde_float32x2_t src = simde_test_arm_neon_random_f32x2(-100.0f, 100.0f);
    simde_test_arm_neon_write_f32x2(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_float32_t buf = simde_test_codegen_random_f32(-100.0f, 100.0f);
    simde_test_codegen_write_f32(2, buf, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_float32x2_t r;
    SIMDE_CONSTIFY_2_(simde_vld1_lane_f32, r, (HEDLEY_UNREACHABLE(), r), i, &buf, src);
    simde_test_arm_neon_write_f32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld1_lane_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64_t src[1];
    simde_float64_t buf;
    simde_float64_t r[1];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(    20.18) },
      SIMDE_FLOAT64_C(   -60.60),
      { SIMDE_FLOAT64_C(   -60.60) } },
    { { SIMDE_FLOAT64_C(   -37.50) },
      SIMDE_FLOAT64_C(    77.41),
      { SIMDE_FLOAT64_C(    77.41) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x1_t src = simde_vld1_f64(test_vec[i].src);
    simde_float64x1_t r = simde_vld1_lane_f64(&test_vec[i].buf, src, 0);

    simde_float64x1_t expected = simde_vld1_f64(test_vec[i].r);

    simde_test_arm_neon_assert_equal_f64x1(r, expected, 1);
  }

  return 0;
#else
  for (int i = 0 ; i < 2 ; i++) {
    simde_float64x1_t src = simde_test_arm_neon_random_f64x1(-100.0, 100.0);
    simde_test_arm_neon_write_f64x1(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_float64_t buf = simde_test_codegen_random_f64(-100.0, 100.0);
    simde_test_codegen_write_f64(2, buf, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_float64x1_t r = simde_vld1_lane_f64(&buf, src, 0);
    simde_test_arm_neon_write_f64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld1q_lane_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t src[16];
    int8_t buf;
    int8_t r[16];
  } test_vec[] = {
    { {  INT8_C(  10),  INT8_C(  13), -INT8_C(  12),  INT8_C(   5),  INT8_C(  99),  INT8_C( 103), -INT8_C(  99),  INT8_C(  30),
        -INT8_C(  75), -INT8_C(  35), -INT8_C( 102),  INT8_C( 112),  INT8_C(  25),  INT8_C(   0),  INT8_C( 109),  INT8_C( 109) },
      -INT8_C(   1),
      { -INT8_C(   1),  INT8_C(  13), -INT8_C(  12),  INT8_C(   5),  INT8_C(  99),  INT8_C( 103), -INT8_C(  99),  INT8_C(  30),
        -INT8_C(  75), -INT8_C(  35), -INT8_C( 102),  INT8_C( 112),  INT8_C(  25),  INT8_C(   0),  INT8_C( 109),  INT8_C( 109) } },
    { { -INT8_C(  20),  INT8_C(  78),  INT8_C(  29),  INT8_C(  78), -INT8_C(  85),  INT8_C( 103), -INT8_C(  31),  INT8_C(  11),
        -INT8_C(  70), -INT8_C( 110), -INT8_C(  58), -INT8_C(  84),  INT8_C(  47),  INT8_C(  51), -INT8_C(  74),  INT8_C(  60) },
       INT8_C(  39),
      { -INT8_C(  20),  INT8_C(  39),  INT8_C(  29),  INT8_C(  78), -INT8_C(  85),  INT8_C( 103), -INT8_C(  31),  INT8_C(  11),
        -INT8_C(  70), -INT8_C( 110), -INT8_C(  58), -INT8_C(  84),  INT8_C(  47),  INT8_C(  51), -INT8_C(  74),  INT8_C(  60) } },
    { { -INT8_C(  69), -INT8_C(  97), -INT8_C( 113),  INT8_C(  89), -INT8_C(  67),  INT8_C(  68),  INT8_C(  54),  INT8_C(  88),
        -INT8_C(  76),  INT8_C(  79),  INT8_C(  88),  INT8_C(  33), -INT8_C(  67),  INT8_C(  87),  INT8_C(  13),  INT8_C(  11) },
       INT8_C( 117),
      { -INT8_C(  69), -INT8_C(  97),  INT8_C( 117),  INT8_C(  89), -INT8_C(  67),  INT8_C(  68),  INT8_C(  54),  INT8_C(  88),
        -INT8_C(  76),  INT8_C(  79),  INT8_C(  88),  INT8_C(  33), -INT8_C(  67),  INT8_C(  87),  INT8_C(  13),  INT8_C(  11) } },
    { {  INT8_C(  91), -INT8_C(  74), -INT8_C(  36),  INT8_C(  60), -INT8_C(  63), -INT8_C( 106), -INT8_C(  49), -INT8_C( 121),
         INT8_C(  66), -INT8_C(   2), -INT8_C(  70), -INT8_C(   7),  INT8_C(  58), -INT8_C(  31), -INT8_C(  76), -INT8_C(  38) },
       INT8_C( 112),
      {  INT8_C(  91), -INT8_C(  74), -INT8_C(  36),  INT8_C( 112), -INT8_C(  63), -INT8_C( 106), -INT8_C(  49), -INT8_C( 121),
         INT8_C(  66), -INT8_C(   2), -INT8_C(  70), -INT8_C(   7),  INT8_C(  58), -INT8_C(  31), -INT8_C(  76), -INT8_C(  38) } },
    { {  INT8_C(  13), -INT8_C( 105), -INT8_C(  75),  INT8_C(  68), -INT8_C(  17),  INT8_C( 105), -INT8_C( 109),  INT8_C(  72),
        -INT8_C( 117),  INT8_C(  80), -INT8_C(  97), -INT8_C( 104),  INT8_C(  91),  INT8_C(  20), -INT8_C(  12),  INT8_C(  17) },
      -INT8_C(  15),
      {  INT8_C(  13), -INT8_C( 105), -INT8_C(  75),  INT8_C(  68), -INT8_C(  15),  INT8_C( 105), -INT8_C( 109),  INT8_C(  72),
        -INT8_C( 117),  INT8_C(  80), -INT8_C(  97), -INT8_C( 104),  INT8_C(  91),  INT8_C(  20), -INT8_C(  12),  INT8_C(  17) } },
    { {  INT8_C(  48), -INT8_C(  46), -INT8_C( 121), -INT8_C(   1),  INT8_C(  89), -INT8_C(  54), -INT8_C(   3),  INT8_C(  19),
        -INT8_C(  61),  INT8_C(  56), -INT8_C(  11),  INT8_C( 119),  INT8_C(  18),  INT8_C( 101), -INT8_C( 123), -INT8_C(  87) },
       INT8_C(  26),
      {  INT8_C(  48), -INT8_C(  46), -INT8_C( 121), -INT8_C(   1),  INT8_C(  89),  INT8_C(  26), -INT8_C(   3),  INT8_C(  19),
        -INT8_C(  61),  INT8_C(  56), -INT8_C(  11),  INT8_C( 119),  INT8_C(  18),  INT8_C( 101), -INT8_C( 123), -INT8_C(  87) } },
    { { -INT8_C(  55), -INT8_C( 103), -INT8_C( 124),  INT8_C(  92), -INT8_C(  31),  INT8_C(  15), -INT8_C(  83),      INT8_MIN,
        -INT8_C(  89),  INT8_C(   8), -INT8_C( 107), -INT8_C( 101),  INT8_C(  26), -INT8_C( 122), -INT8_C(  52), -INT8_C(  20) },
       INT8_C(  13),
      { -INT8_C(  55), -INT8_C( 103), -INT8_C( 124),  INT8_C(  92), -INT8_C(  31),  INT8_C(  15),  INT8_C(  13),      INT8_MIN,
        -INT8_C(  89),  INT8_C(   8), -INT8_C( 107), -INT8_C( 101),  INT8_C(  26), -INT8_C( 122), -INT8_C(  52), -INT8_C(  20) } },
    { { -INT8_C(  53),  INT8_C(  70), -INT8_C(  41), -INT8_C(  55),  INT8_C(  89), -INT8_C( 102),  INT8_C(   1),  INT8_C(  78),
         INT8_C(  18),  INT8_C(  19), -INT8_C(  76), -INT8_C( 105), -INT8_C(  68), -INT8_C(  50),  INT8_C(  96),  INT8_C(  85) },
       INT8_C(  82),
      { -INT8_C(  53),  INT8_C(  70), -INT8_C(  41), -INT8_C(  55),  INT8_C(  89), -INT8_C( 102),  INT8_C(   1),  INT8_C(  82),
         INT8_C(  18),  INT8_C(  19), -INT8_C(  76), -INT8_C( 105), -INT8_C(  68), -INT8_C(  50),  INT8_C(  96),  INT8_C(  85) } },
    { { -INT8_C(  68),  INT8_C(  54),  INT8_C(  97),  INT8_C( 105), -INT8_C(  73),  INT8_C(   9),  INT8_C( 114),  INT8_C(  76),
        -INT8_C(  92), -INT8_C( 116), -INT8_C(  46),  INT8_C( 112),  INT8_C( 120), -INT8_C(  33),  INT8_C(  60), -INT8_C(  66) },
      -INT8_C(  73),
      { -INT8_C(  68),  INT8_C(  54),  INT8_C(  97),  INT8_C( 105), -INT8_C(  73),  INT8_C(   9),  INT8_C( 114),  INT8_C(  76),
        -INT8_C(  73), -INT8_C( 116), -INT8_C(  46),  INT8_C( 112),  INT8_C( 120), -INT8_C(  33),  INT8_C(  60), -INT8_C(  66) } },
    { {  INT8_C(   5),  INT8_C(  24),  INT8_C(  81),  INT8_C(   6),  INT8_C( 102),  INT8_C(  99),  INT8_C(  25),  INT8_C(  26),
        -INT8_C(   6), -INT8_C(  43), -INT8_C(  23),  INT8_C(  90),  INT8_C(  43),  INT8_C(  59),  INT8_C(  23),  INT8_C(  97) },
      -INT8_C(  99),
      {  INT8_C(   5),  INT8_C(  24),  INT8_C(  81),  INT8_C(   6),  INT8_C( 102),  INT8_C(  99),  INT8_C(  25),  INT8_C(  26),
        -INT8_C(   6), -INT8_C(  99), -INT8_C(  23),  INT8_C(  90),  INT8_C(  43),  INT8_C(  59),  INT8_C(  23),  INT8_C(  97) } },
    { {      INT8_MIN,  INT8_C(  24), -INT8_C(  90), -INT8_C(  14),  INT8_C( 100),  INT8_C(  74),  INT8_C( 126),  INT8_C(  54),
        -INT8_C(  69), -INT8_C(   9),  INT8_C(  22), -INT8_C(   9), -INT8_C(  75), -INT8_C(  51), -INT8_C(   4), -INT8_C(  51) },
       INT8_C(  30),
      {      INT8_MIN,  INT8_C(  24), -INT8_C(  90), -INT8_C(  14),  INT8_C( 100),  INT8_C(  74),  INT8_C( 126),  INT8_C(  54),
        -INT8_C(  69), -INT8_C(   9),  INT8_C(  30), -INT8_C(   9), -INT8_C(  75), -INT8_C(  51), -INT8_C(   4), -INT8_C(  51) } },
    { {  INT8_C(   2),  INT8_C(  52), -INT8_C( 126),  INT8_C(  27),  INT8_C(  78),  INT8_C( 124), -INT8_C(  16),  INT8_C(  55),
        -INT8_C(  41),  INT8_C(  27),  INT8_C( 115), -INT8_C(  18),  INT8_C( 125),  INT8_C(  16),  INT8_C( 110), -INT8_C( 107) },
      -INT8_C(  74),
      {  INT8_C(   2),  INT8_C(  52), -INT8_C( 126),  INT8_C(  27),  INT8_C(  78),  INT8_C( 124), -INT8_C(  16),  INT8_C(  55),
        -INT8_C(  41),  INT8_C(  27),  INT8_C( 115), -INT8_C(  74),  INT8_C( 125),  INT8_C(  16),  INT8_C( 110), -INT8_C( 107) } },
    { {  INT8_C(  97), -INT8_C(   6),  INT8_C(   0), -INT8_C(  33),  INT8_C(  48), -INT8_C(  69), -INT8_C(  42),  INT8_C(  70),
        -INT8_C(  78), -INT8_C( 116),  INT8_C(  19), -INT8_C(  82),  INT8_C(  89),  INT8_C(  50), -INT8_C(  80), -INT8_C( 115) },
      -INT8_C(  76),
      {  INT8_C(  97), -INT8_C(   6),  INT8_C(   0), -INT8_C(  33),  INT8_C(  48), -INT8_C(  69), -INT8_C(  42),  INT8_C(  70),
        -INT8_C(  78), -INT8_C( 116),  INT8_C(  19), -INT8_C(  82), -INT8_C(  76),  INT8_C(  50), -INT8_C(  80), -INT8_C( 115) } },
    { { -INT8_C(  53), -INT8_C(  36),  INT8_C(  48), -INT8_C(  68),  INT8_C(  19),  INT8_C(   7), -INT8_C(  41), -INT8_C( 122),
        -INT8_C(  11),  INT8_C(  84), -INT8_C( 106),  INT8_C( 100), -INT8_C(  22),  INT8_C(  76), -INT8_C(  59), -INT8_C(  28) },
       INT8_C(  77),
      { -INT8_C(  53), -INT8_C(  36),  INT8_C(  48), -INT8_C(  68),  INT8_C(  19),  INT8_C(   7), -INT8_C(  41), -INT8_C( 122),
        -INT8_C(  11),  INT8_C(  84), -INT8_C( 106),  INT8_C( 100), -INT8_C(  22),  INT8_C(  77), -INT8_C(  59), -INT8_C(  28) } },
    { { -INT8_C(  92),  INT8_C(  20),  INT8_C(   8),  INT8_C( 123),  INT8_C(  91), -INT8_C(  69),  INT8_C(   7),  INT8_C( 110),
         INT8_C( 105),  INT8_C(  96), -INT8_C(  96),  INT8_C(  26), -INT8_C(  18),  INT8_C(  84), -INT8_C(  27), -INT8_C(  54) },
      -INT8_C( 123),
      { -INT8_C(  92),  INT8_C(  20),  INT8_C(   8),  INT8_C( 123),  INT8_C(  91), -INT8_C(  69),  INT8_C(   7),  INT8_C( 110),
         INT8_C( 105),  INT8_C(  96), -INT8_C(  96),  INT8_C(  26), -INT8_C(  18),  INT8_C(  84), -INT8_C( 123), -INT8_C(  54) } },
    { { -INT8_C(  95), -INT8_C(  35), -INT8_C( 116),  INT8_C( 121),  INT8_C( 100), -INT8_C( 126), -INT8_C(  51), -INT8_C(   6),
        -INT8_C(  26), -INT8_C(  73),  INT8_C(  71), -INT8_C(  85), -INT8_C( 101), -INT8_C( 108),  INT8_C(  79), -INT8_C(  80) },
      -INT8_C( 100),
      { -INT8_C(  95), -INT8_C(  35), -INT8_C( 116),  INT8_C( 121),  INT8_C( 100), -INT8_C( 126), -INT8_C(  51), -INT8_C(   6),
        -INT8_C(  26), -INT8_C(  73),  INT8_C(  71), -INT8_C(  85), -INT8_C( 101), -INT8_C( 108),  INT8_C(  79), -INT8_C( 100) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16_t r, src, expected;
    src = simde_vld1q_s8(test_vec[i].src);

    SIMDE_CONSTIFY_16_(simde_vld1q_lane_s8, r, (HEDLEY_UNREACHABLE(), r), i, &test_vec[i].buf, src);

    expected = simde_vld1q_s8(test_vec[i].r);

    simde_test_arm_neon_assert_equal_i8x16(r, expected);
  }

  return 0;
#else
  for (int i = 0 ; i < 16 ; i++) {
    simde_int8x16_t src = simde_test_arm_neon_random_i8x16();
    simde_test_arm_neon_write_i8x16(2, src, SIMDE_TEST_VEC_POS_FIRST);
    int8_t buf = simde_test_codegen_random_i8();
    simde_test_codegen_write_i8(2, buf, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_int8x16_t r;
    SIMDE_CONSTIFY_16_(simde_vld1q_lane_s8, r, (HEDLEY_UNREACHABLE(), r), i, &buf, src);
    simde_test_arm_neon_write_i8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld1q_lane_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t src[8];
    int16_t buf;
    int16_t r[8];
  } test_vec[] = {
    { {  INT16_C( 18302),  INT16_C(  3351), -INT16_C( 15221),  INT16_C(  4138),  INT16_C( 24143),  INT16_C( 27205), -INT16_C( 18604),  INT16_C( 26567) },
      -INT16_C( 20762),
      { -INT16_C( 20762),  INT16_C(  3351), -INT16_C( 15221),  INT16_C(  4138),  INT16_C( 24143),  INT16_C( 27205), -INT16_C( 18604),  INT16_C( 26567) } },
    { {  INT16_C( 24465),  INT16_C( 13439),  INT16_C( 14251),  INT16_C( 13140), -INT16_C(  7928), -INT16_C( 26737),  INT16_C(  3356),  INT16_C( 13278) },
       INT16_C( 26906),
      {  INT16_C( 24465),  INT16_C( 26906),  INT16_C( 14251),  INT16_C( 13140), -INT16_C(  7928), -INT16_C( 26737),  INT16_C(  3356),  INT16_C( 13278) } },
    { {  INT16_C( 17911),  INT16_C( 18297), -INT16_C( 16733), -INT16_C(  2127),  INT16_C( 30837),  INT16_C( 23390), -INT16_C(  4058), -INT16_C( 23109) },
       INT16_C( 26148),
      {  INT16_C( 17911),  INT16_C( 18297),  INT16_C( 26148), -INT16_C(  2127),  INT16_C( 30837),  INT16_C( 23390), -INT16_C(  4058), -INT16_C( 23109) } },
    { {  INT16_C( 30941), -INT16_C(  6759),  INT16_C( 10585),  INT16_C( 30076),  INT16_C( 23094),  INT16_C( 20905), -INT16_C( 24380),  INT16_C( 15766) },
       INT16_C( 14823),
      {  INT16_C( 30941), -INT16_C(  6759),  INT16_C( 10585),  INT16_C( 14823),  INT16_C( 23094),  INT16_C( 20905), -INT16_C( 24380),  INT16_C( 15766) } },
    { { -INT16_C( 26372),  INT16_C( 28977), -INT16_C( 28911),  INT16_C( 14285), -INT16_C( 30593), -INT16_C( 23587), -INT16_C( 17682), -INT16_C( 30949) },
       INT16_C( 30111),
      { -INT16_C( 26372),  INT16_C( 28977), -INT16_C( 28911),  INT16_C( 14285),  INT16_C( 30111), -INT16_C( 23587), -INT16_C( 17682), -INT16_C( 30949) } },
    { {  INT16_C(  7344), -INT16_C(  6166), -INT16_C( 27786),  INT16_C( 14904), -INT16_C( 12748),  INT16_C(  7032),  INT16_C( 29703),  INT16_C( 14516) },
      -INT16_C( 14875),
      {  INT16_C(  7344), -INT16_C(  6166), -INT16_C( 27786),  INT16_C( 14904), -INT16_C( 12748), -INT16_C( 14875),  INT16_C( 29703),  INT16_C( 14516) } },
    { { -INT16_C( 19768),  INT16_C( 18428), -INT16_C(  9926),  INT16_C( 10475),  INT16_C(  1683),  INT16_C( 13232),  INT16_C( 24699),  INT16_C( 26191) },
      -INT16_C( 15033),
      { -INT16_C( 19768),  INT16_C( 18428), -INT16_C(  9926),  INT16_C( 10475),  INT16_C(  1683),  INT16_C( 13232), -INT16_C( 15033),  INT16_C( 26191) } },
    { {  INT16_C( 32761),  INT16_C( 11520),  INT16_C( 30797),  INT16_C( 21833), -INT16_C(   532), -INT16_C( 11891),  INT16_C( 21954), -INT16_C( 16764) },
      -INT16_C( 16739),
      {  INT16_C( 32761),  INT16_C( 11520),  INT16_C( 30797),  INT16_C( 21833), -INT16_C(   532), -INT16_C( 11891),  INT16_C( 21954), -INT16_C( 16739) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t r, src, expected;
    src = simde_vld1q_s16(test_vec[i].src);

    SIMDE_CONSTIFY_8_(simde_vld1q_lane_s16, r, (HEDLEY_UNREACHABLE(), r), i, &test_vec[i].buf, src);

    expected = simde_vld1q_s16(test_vec[i].r);

    simde_test_arm_neon_assert_equal_i16x8(r, expected);
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x8_t src = simde_test_arm_neon_random_i16x8();
    simde_test_arm_neon_write_i16x8(2, src, SIMDE_TEST_VEC_POS_FIRST);
    int16_t buf = simde_test_codegen_random_i16();
    simde_test_codegen_write_i16(2, buf, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_int16x8_t r;
    SIMDE_CONSTIFY_8_(simde_vld1q_lane_s16, r, (HEDLEY_UNREACHABLE(), r), i, &buf, src);
    simde_test_arm_neon_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld1q_lane_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t src[4];
    int32_t buf;
    int32_t r[4];
  } test_vec[] = {
    { {  INT32_C(  2138414382),  INT32_C(  1848472475), -INT32_C(   524604284), -INT32_C(  1210462103) },
       INT32_C(   739647408),
      {  INT32_C(   739647408),  INT32_C(  1848472475), -INT32_C(   524604284), -INT32_C(  1210462103) } },
    { { -INT32_C(    22011503),  INT32_C(   188965100),  INT32_C(  2028133450),  INT32_C(   351819641) },
       INT32_C(  1317152202),
      { -INT32_C(    22011503),  INT32_C(  1317152202),  INT32_C(  2028133450),  INT32_C(   351819641) } },
    { { -INT32_C(  1171309231), -INT32_C(  1099823090), -INT32_C(  1192523737), -INT32_C(  1766417494) },
       INT32_C(  1185020667),
      { -INT32_C(  1171309231), -INT32_C(  1099823090),  INT32_C(  1185020667), -INT32_C(  1766417494) } },
    { {  INT32_C(  1337885654), -INT32_C(  1520126246),  INT32_C(   770959067),  INT32_C(   854008356) },
       INT32_C(  1391483179),
      {  INT32_C(  1337885654), -INT32_C(  1520126246),  INT32_C(   770959067),  INT32_C(  1391483179) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t r, src, expected;
    src = simde_vld1q_s32(test_vec[i].src);

    SIMDE_CONSTIFY_4_(simde_vld1q_lane_s32, r, (HEDLEY_UNREACHABLE(), r), i, &test_vec[i].buf, src);

    expected = simde_vld1q_s32(test_vec[i].r);

    simde_test_arm_neon_assert_equal_i32x4(r, expected);
  }

  return 0;
#else
  for (int i = 0 ; i < 4 ; i++) {
    simde_int32x4_t src = simde_test_arm_neon_random_i32x4();
    simde_test_arm_neon_write_i32x4(2, src, SIMDE_TEST_VEC_POS_FIRST);
    int32_t buf = simde_test_codegen_random_i32();
    simde_test_codegen_write_i32(2, buf, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_int32x4_t r;
    SIMDE_CONSTIFY_4_(simde_vld1q_lane_s32, r, (HEDLEY_UNREACHABLE(), r), i, &buf, src);
    simde_test_arm_neon_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld1q_lane_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t src[2];
    int64_t buf;
    int64_t r[2];
  } test_vec[] = {
    { {  INT64_C( 2164059718870077732),  INT64_C( 5387725316222076229) },
      -INT64_C( 7942503363506704069),
      { -INT64_C( 7942503363506704069),  INT64_C( 5387725316222076229) } },
    { {  INT64_C(  664346800261312842), -INT64_C( 4556708806472944692) },
      -INT64_C( 3097708420003426538),
      { -INT64_C( 3097708420003426538), -INT64_C( 4556708806472944692) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t src = simde_vld1q_s64(test_vec[i].src);
    simde_int64x2_t r = simde_vld1q_lane_s64(&test_vec[i].buf, src, 0);

    simde_int64x2_t expected = simde_vld1q_s64(test_vec[i].r);

    simde_test_arm_neon_assert_equal_i64x2(r, expected);
  }

  return 0;
#else
  for (int i = 0 ; i < 2 ; i++) {
    simde_int64x2_t src = simde_test_arm_neon_random_i64x2();
    simde_test_arm_neon_write_i64x2(2, src, SIMDE_TEST_VEC_POS_FIRST);
    int64_t buf = simde_test_codegen_random_i64();
    simde_test_codegen_write_i64(2, buf, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_int64x2_t r;
    r = simde_vld1q_lane_s64(&buf, src, 0);
    simde_test_arm_neon_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld1q_lane_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t src[16];
    uint8_t buf;
    uint8_t r[16];
  } test_vec[] = {
    { { UINT8_C( 28), UINT8_C(110), UINT8_C(109), UINT8_C(109), UINT8_C(253), UINT8_C( 66), UINT8_C(132), UINT8_C( 11),
        UINT8_C(  5), UINT8_C( 58), UINT8_C(156), UINT8_C( 31), UINT8_C(191), UINT8_C( 51), UINT8_C(130), UINT8_C(104) },
      UINT8_C(234),
      { UINT8_C(234), UINT8_C(110), UINT8_C(109), UINT8_C(109), UINT8_C(253), UINT8_C( 66), UINT8_C(132), UINT8_C( 11),
        UINT8_C(  5), UINT8_C( 58), UINT8_C(156), UINT8_C( 31), UINT8_C(191), UINT8_C( 51), UINT8_C(130), UINT8_C(104) } },
    { { UINT8_C(135), UINT8_C(158), UINT8_C( 67), UINT8_C(136), UINT8_C(184), UINT8_C( 37), UINT8_C( 84), UINT8_C(230),
        UINT8_C(111), UINT8_C(226), UINT8_C( 46), UINT8_C( 47), UINT8_C( 20), UINT8_C( 88), UINT8_C( 76), UINT8_C(130) },
      UINT8_C(197),
      { UINT8_C(135), UINT8_C(197), UINT8_C( 67), UINT8_C(136), UINT8_C(184), UINT8_C( 37), UINT8_C( 84), UINT8_C(230),
        UINT8_C(111), UINT8_C(226), UINT8_C( 46), UINT8_C( 47), UINT8_C( 20), UINT8_C( 88), UINT8_C( 76), UINT8_C(130) } },
    { { UINT8_C(185), UINT8_C(127), UINT8_C(  7), UINT8_C( 61), UINT8_C(139), UINT8_C( 12), UINT8_C(119), UINT8_C( 39),
        UINT8_C( 43), UINT8_C( 54), UINT8_C( 90), UINT8_C(173), UINT8_C(158), UINT8_C( 68), UINT8_C( 52), UINT8_C( 60) },
      UINT8_C(135),
      { UINT8_C(185), UINT8_C(127), UINT8_C(135), UINT8_C( 61), UINT8_C(139), UINT8_C( 12), UINT8_C(119), UINT8_C( 39),
        UINT8_C( 43), UINT8_C( 54), UINT8_C( 90), UINT8_C(173), UINT8_C(158), UINT8_C( 68), UINT8_C( 52), UINT8_C( 60) } },
    { { UINT8_C(188), UINT8_C(245), UINT8_C(172), UINT8_C( 17), UINT8_C(219), UINT8_C( 27), UINT8_C(243), UINT8_C(  9),
        UINT8_C( 74), UINT8_C(  7), UINT8_C( 97), UINT8_C(150), UINT8_C(137), UINT8_C( 38), UINT8_C( 79), UINT8_C(  9) },
      UINT8_C( 45),
      { UINT8_C(188), UINT8_C(245), UINT8_C(172), UINT8_C( 45), UINT8_C(219), UINT8_C( 27), UINT8_C(243), UINT8_C(  9),
        UINT8_C( 74), UINT8_C(  7), UINT8_C( 97), UINT8_C(150), UINT8_C(137), UINT8_C( 38), UINT8_C( 79), UINT8_C(  9) } },
    { { UINT8_C(141), UINT8_C(148), UINT8_C( 57), UINT8_C(  4), UINT8_C(187), UINT8_C(101), UINT8_C( 59), UINT8_C( 21),
        UINT8_C( 18), UINT8_C(217), UINT8_C( 89), UINT8_C( 71), UINT8_C( 22), UINT8_C(224), UINT8_C(  3), UINT8_C( 11) },
      UINT8_C(140),
      { UINT8_C(141), UINT8_C(148), UINT8_C( 57), UINT8_C(  4), UINT8_C(140), UINT8_C(101), UINT8_C( 59), UINT8_C( 21),
        UINT8_C( 18), UINT8_C(217), UINT8_C( 89), UINT8_C( 71), UINT8_C( 22), UINT8_C(224), UINT8_C(  3), UINT8_C( 11) } },
    { { UINT8_C( 20), UINT8_C(230), UINT8_C(167), UINT8_C(  7), UINT8_C(239), UINT8_C(241), UINT8_C( 14), UINT8_C( 80),
        UINT8_C(136), UINT8_C(152), UINT8_C(118), UINT8_C(215), UINT8_C(161), UINT8_C(163), UINT8_C(100), UINT8_C( 53) },
      UINT8_C(220),
      { UINT8_C( 20), UINT8_C(230), UINT8_C(167), UINT8_C(  7), UINT8_C(239), UINT8_C(220), UINT8_C( 14), UINT8_C( 80),
        UINT8_C(136), UINT8_C(152), UINT8_C(118), UINT8_C(215), UINT8_C(161), UINT8_C(163), UINT8_C(100), UINT8_C( 53) } },
    { { UINT8_C(105), UINT8_C(240), UINT8_C( 65), UINT8_C(164), UINT8_C(  5), UINT8_C( 84), UINT8_C(125), UINT8_C( 94),
        UINT8_C(155), UINT8_C(147), UINT8_C( 62), UINT8_C(158), UINT8_C(158), UINT8_C(202), UINT8_C(179), UINT8_C(132) },
      UINT8_C(113),
      { UINT8_C(105), UINT8_C(240), UINT8_C( 65), UINT8_C(164), UINT8_C(  5), UINT8_C( 84), UINT8_C(113), UINT8_C( 94),
        UINT8_C(155), UINT8_C(147), UINT8_C( 62), UINT8_C(158), UINT8_C(158), UINT8_C(202), UINT8_C(179), UINT8_C(132) } },
    { { UINT8_C(186), UINT8_C(115), UINT8_C( 98), UINT8_C(201), UINT8_C(195), UINT8_C(234), UINT8_C( 97), UINT8_C( 57),
        UINT8_C(194), UINT8_C(  2), UINT8_C(220), UINT8_C( 38), UINT8_C( 55), UINT8_C(185), UINT8_C(143), UINT8_C( 39) },
      UINT8_C(250),
      { UINT8_C(186), UINT8_C(115), UINT8_C( 98), UINT8_C(201), UINT8_C(195), UINT8_C(234), UINT8_C( 97), UINT8_C(250),
        UINT8_C(194), UINT8_C(  2), UINT8_C(220), UINT8_C( 38), UINT8_C( 55), UINT8_C(185), UINT8_C(143), UINT8_C( 39) } },
    { { UINT8_C( 51), UINT8_C( 44), UINT8_C( 78), UINT8_C(177), UINT8_C(138), UINT8_C(233), UINT8_C( 68), UINT8_C(200),
        UINT8_C(136), UINT8_C(227), UINT8_C(146), UINT8_C( 59), UINT8_C(103), UINT8_C(  3), UINT8_C(245), UINT8_C(219) },
      UINT8_C(101),
      { UINT8_C( 51), UINT8_C( 44), UINT8_C( 78), UINT8_C(177), UINT8_C(138), UINT8_C(233), UINT8_C( 68), UINT8_C(200),
        UINT8_C(101), UINT8_C(227), UINT8_C(146), UINT8_C( 59), UINT8_C(103), UINT8_C(  3), UINT8_C(245), UINT8_C(219) } },
    { { UINT8_C(190), UINT8_C(158), UINT8_C( 80), UINT8_C( 31), UINT8_C(216), UINT8_C( 18), UINT8_C( 33), UINT8_C(180),
        UINT8_C( 56), UINT8_C( 88), UINT8_C(109), UINT8_C(200), UINT8_C(127), UINT8_C(104), UINT8_C(251), UINT8_C(171) },
      UINT8_C(182),
      { UINT8_C(190), UINT8_C(158), UINT8_C( 80), UINT8_C( 31), UINT8_C(216), UINT8_C( 18), UINT8_C( 33), UINT8_C(180),
        UINT8_C( 56), UINT8_C(182), UINT8_C(109), UINT8_C(200), UINT8_C(127), UINT8_C(104), UINT8_C(251), UINT8_C(171) } },
    { { UINT8_C(172), UINT8_C( 53), UINT8_C(160), UINT8_C(241), UINT8_C(253), UINT8_C( 40), UINT8_C(212), UINT8_C(143),
        UINT8_C( 99), UINT8_C( 59), UINT8_C(146), UINT8_C( 88), UINT8_C( 22), UINT8_C(248), UINT8_C( 23), UINT8_C(181) },
      UINT8_C( 72),
      { UINT8_C(172), UINT8_C( 53), UINT8_C(160), UINT8_C(241), UINT8_C(253), UINT8_C( 40), UINT8_C(212), UINT8_C(143),
        UINT8_C( 99), UINT8_C( 59), UINT8_C( 72), UINT8_C( 88), UINT8_C( 22), UINT8_C(248), UINT8_C( 23), UINT8_C(181) } },
    { { UINT8_C( 54), UINT8_C(141), UINT8_C( 90), UINT8_C( 88), UINT8_C( 65), UINT8_C(146), UINT8_C(176), UINT8_C(175),
        UINT8_C( 90), UINT8_C( 48), UINT8_C( 23), UINT8_C( 86), UINT8_C(219), UINT8_C(205), UINT8_C(  2), UINT8_C( 17) },
      UINT8_C(109),
      { UINT8_C( 54), UINT8_C(141), UINT8_C( 90), UINT8_C( 88), UINT8_C( 65), UINT8_C(146), UINT8_C(176), UINT8_C(175),
        UINT8_C( 90), UINT8_C( 48), UINT8_C( 23), UINT8_C(109), UINT8_C(219), UINT8_C(205), UINT8_C(  2), UINT8_C( 17) } },
    { { UINT8_C(243), UINT8_C( 14), UINT8_C(149), UINT8_C(199), UINT8_C(158), UINT8_C(248), UINT8_C(  3), UINT8_C( 48),
        UINT8_C( 81), UINT8_C( 25), UINT8_C( 40), UINT8_C(104), UINT8_C(206), UINT8_C(112), UINT8_C(158), UINT8_C( 91) },
      UINT8_C(202),
      { UINT8_C(243), UINT8_C( 14), UINT8_C(149), UINT8_C(199), UINT8_C(158), UINT8_C(248), UINT8_C(  3), UINT8_C( 48),
        UINT8_C( 81), UINT8_C( 25), UINT8_C( 40), UINT8_C(104), UINT8_C(202), UINT8_C(112), UINT8_C(158), UINT8_C( 91) } },
    { { UINT8_C(246), UINT8_C(157), UINT8_C( 93), UINT8_C(167), UINT8_C( 76), UINT8_C(183), UINT8_C(215), UINT8_C( 99),
        UINT8_C( 13), UINT8_C(178), UINT8_C( 48), UINT8_C( 16), UINT8_C(195), UINT8_C(158), UINT8_C(  3), UINT8_C(210) },
      UINT8_C( 51),
      { UINT8_C(246), UINT8_C(157), UINT8_C( 93), UINT8_C(167), UINT8_C( 76), UINT8_C(183), UINT8_C(215), UINT8_C( 99),
        UINT8_C( 13), UINT8_C(178), UINT8_C( 48), UINT8_C( 16), UINT8_C(195), UINT8_C( 51), UINT8_C(  3), UINT8_C(210) } },
    { { UINT8_C(203), UINT8_C(112), UINT8_C( 44), UINT8_C(206), UINT8_C(160), UINT8_C(125), UINT8_C(231), UINT8_C(201),
        UINT8_C(229), UINT8_C(182), UINT8_C( 57), UINT8_C(131), UINT8_C( 17), UINT8_C(  4), UINT8_C(122), UINT8_C(174) },
      UINT8_C( 97),
      { UINT8_C(203), UINT8_C(112), UINT8_C( 44), UINT8_C(206), UINT8_C(160), UINT8_C(125), UINT8_C(231), UINT8_C(201),
        UINT8_C(229), UINT8_C(182), UINT8_C( 57), UINT8_C(131), UINT8_C( 17), UINT8_C(  4), UINT8_C( 97), UINT8_C(174) } },
    { { UINT8_C( 33), UINT8_C(250), UINT8_C( 24), UINT8_C(248), UINT8_C( 93), UINT8_C( 38), UINT8_C(170), UINT8_C(142),
        UINT8_C( 54), UINT8_C(110), UINT8_C( 44), UINT8_C( 57), UINT8_C( 64), UINT8_C( 95), UINT8_C(  4), UINT8_C(176) },
      UINT8_C(139),
      { UINT8_C( 33), UINT8_C(250), UINT8_C( 24), UINT8_C(248), UINT8_C( 93), UINT8_C( 38), UINT8_C(170), UINT8_C(142),
        UINT8_C( 54), UINT8_C(110), UINT8_C( 44), UINT8_C( 57), UINT8_C( 64), UINT8_C( 95), UINT8_C(  4), UINT8_C(139) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x16_t r, src, expected;
    src = simde_vld1q_u8(test_vec[i].src);

    SIMDE_CONSTIFY_16_(simde_vld1q_lane_u8, r, (HEDLEY_UNREACHABLE(), r), i, &test_vec[i].buf, src);

    expected = simde_vld1q_u8(test_vec[i].r);

    simde_test_arm_neon_assert_equal_u8x16(r, expected);
  }

  return 0;
#else
  for (int i = 0 ; i < 16 ; i++) {
    simde_uint8x16_t src = simde_test_arm_neon_random_u8x16();
    simde_test_arm_neon_write_u8x16(2, src, SIMDE_TEST_VEC_POS_FIRST);
    uint8_t buf = simde_test_codegen_random_u8();
    simde_test_codegen_write_u8(2, buf, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_uint8x16_t r;
    SIMDE_CONSTIFY_16_(simde_vld1q_lane_u8, r, (HEDLEY_UNREACHABLE(), r), i, &buf, src);
    simde_test_arm_neon_write_u8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld1q_lane_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t src[8];
    uint16_t buf;
    uint16_t r[8];
  } test_vec[] = {
    { { UINT16_C(61365), UINT16_C(27343), UINT16_C(39618), UINT16_C(64185), UINT16_C(22927), UINT16_C(35469), UINT16_C( 7993), UINT16_C(29855) },
      UINT16_C(47168),
      { UINT16_C(47168), UINT16_C(27343), UINT16_C(39618), UINT16_C(64185), UINT16_C(22927), UINT16_C(35469), UINT16_C( 7993), UINT16_C(29855) } },
    { { UINT16_C(27409), UINT16_C(44369), UINT16_C(21309), UINT16_C(21310), UINT16_C(53091), UINT16_C(63175), UINT16_C(31809), UINT16_C( 4325) },
      UINT16_C(43238),
      { UINT16_C(27409), UINT16_C(43238), UINT16_C(21309), UINT16_C(21310), UINT16_C(53091), UINT16_C(63175), UINT16_C(31809), UINT16_C( 4325) } },
    { { UINT16_C(40874), UINT16_C(14754), UINT16_C(12280), UINT16_C(12740), UINT16_C(25422), UINT16_C(36518), UINT16_C(46875), UINT16_C(27898) },
      UINT16_C(14180),
      { UINT16_C(40874), UINT16_C(14754), UINT16_C(14180), UINT16_C(12740), UINT16_C(25422), UINT16_C(36518), UINT16_C(46875), UINT16_C(27898) } },
    { { UINT16_C(41663), UINT16_C( 9098), UINT16_C(20850), UINT16_C(45849), UINT16_C(65485), UINT16_C(46020), UINT16_C(28327), UINT16_C(18770) },
      UINT16_C(19112),
      { UINT16_C(41663), UINT16_C( 9098), UINT16_C(20850), UINT16_C(19112), UINT16_C(65485), UINT16_C(46020), UINT16_C(28327), UINT16_C(18770) } },
    { { UINT16_C(27768), UINT16_C(50812), UINT16_C( 8911), UINT16_C(59989), UINT16_C(20441), UINT16_C(15959), UINT16_C( 5766), UINT16_C( 4320) },
      UINT16_C(21049),
      { UINT16_C(27768), UINT16_C(50812), UINT16_C( 8911), UINT16_C(59989), UINT16_C(21049), UINT16_C(15959), UINT16_C( 5766), UINT16_C( 4320) } },
    { { UINT16_C(21346), UINT16_C(12038), UINT16_C(51794), UINT16_C(63971), UINT16_C(13624), UINT16_C(57410), UINT16_C(47744), UINT16_C(64588) },
      UINT16_C( 7040),
      { UINT16_C(21346), UINT16_C(12038), UINT16_C(51794), UINT16_C(63971), UINT16_C(13624), UINT16_C( 7040), UINT16_C(47744), UINT16_C(64588) } },
    { { UINT16_C(54558), UINT16_C(63238), UINT16_C(23844), UINT16_C(43573), UINT16_C( 5747), UINT16_C(44475), UINT16_C( 7528), UINT16_C(28160) },
      UINT16_C(21068),
      { UINT16_C(54558), UINT16_C(63238), UINT16_C(23844), UINT16_C(43573), UINT16_C( 5747), UINT16_C(44475), UINT16_C(21068), UINT16_C(28160) } },
    { { UINT16_C(12088), UINT16_C(29003), UINT16_C(36197), UINT16_C(58705), UINT16_C(40519), UINT16_C(51169), UINT16_C(65465), UINT16_C(49053) },
      UINT16_C(49654),
      { UINT16_C(12088), UINT16_C(29003), UINT16_C(36197), UINT16_C(58705), UINT16_C(40519), UINT16_C(51169), UINT16_C(65465), UINT16_C(49654) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t r, src, expected;
    src = simde_vld1q_u16(test_vec[i].src);

    SIMDE_CONSTIFY_8_(simde_vld1q_lane_u16, r, (HEDLEY_UNREACHABLE(), r), i, &test_vec[i].buf, src);

    expected = simde_vld1q_u16(test_vec[i].r);

    simde_test_arm_neon_assert_equal_u16x8(r, expected);
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x8_t src = simde_test_arm_neon_random_u16x8();
    simde_test_arm_neon_write_u16x8(2, src, SIMDE_TEST_VEC_POS_FIRST);
    uint16_t buf = simde_test_codegen_random_u16();
    simde_test_codegen_write_u16(2, buf, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_uint16x8_t r;
    SIMDE_CONSTIFY_8_(simde_vld1q_lane_u16, r, (HEDLEY_UNREACHABLE(), r), i, &buf, src);
    simde_test_arm_neon_write_u16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld1q_lane_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t src[4];
    uint32_t buf;
    uint32_t r[4];
  } test_vec[] = {
    { { UINT32_C(3227330157), UINT32_C( 910377813), UINT32_C(3219848662), UINT32_C( 546199499) },
      UINT32_C(1503651563),
      { UINT32_C(1503651563), UINT32_C( 910377813), UINT32_C(3219848662), UINT32_C( 546199499) } },
    { { UINT32_C(2206470288), UINT32_C(2627461039), UINT32_C(1511652076), UINT32_C(1981445665) },
      UINT32_C(2427280826),
      { UINT32_C(2206470288), UINT32_C(2427280826), UINT32_C(1511652076), UINT32_C(1981445665) } },
    { { UINT32_C( 625973082), UINT32_C(3645234670), UINT32_C(1395844291), UINT32_C(2765600757) },
      UINT32_C(2185327254),
      { UINT32_C( 625973082), UINT32_C(3645234670), UINT32_C(2185327254), UINT32_C(2765600757) } },
    { { UINT32_C(2380028524), UINT32_C(2332358353), UINT32_C(2921050451), UINT32_C( 919824968) },
      UINT32_C( 168761671),
      { UINT32_C(2380028524), UINT32_C(2332358353), UINT32_C(2921050451), UINT32_C( 168761671) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t r, src, expected;
    src = simde_vld1q_u32(test_vec[i].src);

    SIMDE_CONSTIFY_4_(simde_vld1q_lane_u32, r, (HEDLEY_UNREACHABLE(), r), i, &test_vec[i].buf, src);

    expected = simde_vld1q_u32(test_vec[i].r);

    simde_test_arm_neon_assert_equal_u32x4(r, expected);
  }

  return 0;
#else
  for (int i = 0 ; i < 4 ; i++) {
    simde_uint32x4_t src = simde_test_arm_neon_random_u32x4();
    simde_test_arm_neon_write_u32x4(2, src, SIMDE_TEST_VEC_POS_FIRST);
    uint32_t buf = simde_test_codegen_random_u32();
    simde_test_codegen_write_u32(2, buf, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_uint32x4_t r;
    SIMDE_CONSTIFY_4_(simde_vld1q_lane_u32, r, (HEDLEY_UNREACHABLE(), r), i, &buf, src);
    simde_test_arm_neon_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld1q_lane_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t src[2];
    uint64_t buf;
    uint64_t r[2];
  } test_vec[] = {
    { { UINT64_C( 1558444252673088813), UINT64_C(14638023719726696460) },
      UINT64_C(17965117724479085764),
      { UINT64_C(17965117724479085764), UINT64_C(14638023719726696460) } },
    { { UINT64_C(17456204787348126692), UINT64_C(15411604664602596610) },
      UINT64_C( 7501718952898326092),
      { UINT64_C( 7501718952898326092), UINT64_C(15411604664602596610) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x2_t src = simde_vld1q_u64(test_vec[i].src);
    simde_uint64x2_t r = simde_vld1q_lane_u64(&test_vec[i].buf, src, 0);

    simde_uint64x2_t expected = simde_vld1q_u64(test_vec[i].r);

    simde_test_arm_neon_assert_equal_u64x2(r, expected);
  }

  return 0;
#else
  for (int i = 0 ; i < 2 ; i++) {
    simde_uint64x2_t src = simde_test_arm_neon_random_u64x2();
    simde_test_arm_neon_write_u64x2(2, src, SIMDE_TEST_VEC_POS_FIRST);
    uint64_t buf = simde_test_codegen_random_u64();
    simde_test_codegen_write_u64(2, buf, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_uint64x2_t r = simde_vld1q_lane_u64(&buf, src, 0);
    simde_test_arm_neon_write_u64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld1q_lane_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32_t src[4];
    simde_float32_t buf;
    simde_float32_t r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(    66.78), SIMDE_FLOAT32_C(   -23.96), SIMDE_FLOAT32_C(    23.06), SIMDE_FLOAT32_C(    55.69) },
      SIMDE_FLOAT32_C(   -28.53),
      { SIMDE_FLOAT32_C(   -28.53), SIMDE_FLOAT32_C(   -23.96), SIMDE_FLOAT32_C(    23.06), SIMDE_FLOAT32_C(    55.69) } },
    { { SIMDE_FLOAT32_C(   -99.61), SIMDE_FLOAT32_C(   -58.57), SIMDE_FLOAT32_C(   -81.59), SIMDE_FLOAT32_C(   -91.49) },
      SIMDE_FLOAT32_C(    47.16),
      { SIMDE_FLOAT32_C(   -99.61), SIMDE_FLOAT32_C(    47.16), SIMDE_FLOAT32_C(   -81.59), SIMDE_FLOAT32_C(   -91.49) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t r, src, expected;
    src = simde_vld1q_f32(test_vec[i].src);

    SIMDE_CONSTIFY_2_(simde_vld1q_lane_f32, r, (HEDLEY_UNREACHABLE(), r), i, &test_vec[i].buf, src);

    expected = simde_vld1q_f32(test_vec[i].r);

    simde_test_arm_neon_assert_equal_f32x4(r, expected, 1);
  }

  return 0;
#else
  for (int i = 0 ; i < 2 ; i++) {
    simde_float32x4_t src = simde_test_arm_neon_random_f32x4(-100.0f, 100.0f);
    simde_test_arm_neon_write_f32x4(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_float32_t buf = simde_test_codegen_random_f32(-100.0f, 100.0f);
    simde_test_codegen_write_f32(2, buf, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_float32x4_t r;
    SIMDE_CONSTIFY_2_(simde_vld1q_lane_f32, r, (HEDLEY_UNREACHABLE(), r), i, &buf, src);
    simde_test_arm_neon_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld1q_lane_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64_t src[2];
    simde_float64_t buf;
    simde_float64_t r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(    46.67), SIMDE_FLOAT64_C(   -34.89) },
      SIMDE_FLOAT64_C(   -24.31),
      { SIMDE_FLOAT64_C(   -24.31), SIMDE_FLOAT64_C(   -34.89) } },
    { { SIMDE_FLOAT64_C(    43.52), SIMDE_FLOAT64_C(   -35.64) },
      SIMDE_FLOAT64_C(   -28.94),
      { SIMDE_FLOAT64_C(   -28.94), SIMDE_FLOAT64_C(   -35.64) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2_t src = simde_vld1q_f64(test_vec[i].src);
    simde_float64x2_t r = simde_vld1q_lane_f64(&test_vec[i].buf, src, 0);

    simde_float64x2_t expected = simde_vld1q_f64(test_vec[i].r);

    simde_test_arm_neon_assert_equal_f64x2(r, expected, 1);
  }

  return 0;
#else
  for (int i = 0 ; i < 2 ; i++) {
    simde_float64x2_t src = simde_test_arm_neon_random_f64x2(-100.0, 100.0);
    simde_test_arm_neon_write_f64x2(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_float64_t buf = simde_test_codegen_random_f64(-100.0, 100.0);
    simde_test_codegen_write_f64(2, buf, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_float64x2_t r = simde_vld1q_lane_f64(&buf, src, 0);
    simde_test_arm_neon_write_f64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vld1_lane_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vld1_lane_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vld1_lane_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vld1_lane_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vld1_lane_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vld1_lane_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vld1_lane_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vld1_lane_u64)
SIMDE_TEST_FUNC_LIST_ENTRY(vld1_lane_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vld1_lane_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vld1q_lane_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vld1q_lane_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vld1q_lane_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vld1q_lane_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vld1q_lane_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vld1q_lane_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vld1q_lane_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vld1q_lane_u64)
SIMDE_TEST_FUNC_LIST_ENTRY(vld1q_lane_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vld1q_lane_f64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
