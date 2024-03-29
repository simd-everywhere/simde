#define SIMDE_TEST_ARM_NEON_INSN dup_lane

#include "test-neon.h"
#include "../../../simde/arm/neon/dup_n.h"
#include "../../../simde/arm/neon/dup_lane.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DIAGNOSTIC_DISABLE_UNREACHABLE_

static int
test_simde_vdup_lane_f16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float16_t vec[4];
    int lane;
    simde_float16_t r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT16_VALUE(-7.6), SIMDE_FLOAT16_VALUE(11.4), SIMDE_FLOAT16_VALUE(10.7), SIMDE_FLOAT16_VALUE(-0.1) },
        INT8_C(2),
      { SIMDE_FLOAT16_VALUE(10.7), SIMDE_FLOAT16_VALUE(10.7), SIMDE_FLOAT16_VALUE(10.7), SIMDE_FLOAT16_VALUE(10.7) } },
    { { SIMDE_FLOAT16_VALUE(1.4), SIMDE_FLOAT16_VALUE(-5.5), SIMDE_FLOAT16_VALUE(3.7), SIMDE_FLOAT16_VALUE(-12.5) },
        INT8_C(0),
      { SIMDE_FLOAT16_VALUE(1.4), SIMDE_FLOAT16_VALUE(1.4), SIMDE_FLOAT16_VALUE(1.4), SIMDE_FLOAT16_VALUE(1.4) } },
    { { SIMDE_FLOAT16_VALUE(13.3), SIMDE_FLOAT16_VALUE(-11.6), SIMDE_FLOAT16_VALUE(4.4), SIMDE_FLOAT16_VALUE(-1.3) },
        INT8_C(2),
      { SIMDE_FLOAT16_VALUE(4.4), SIMDE_FLOAT16_VALUE(4.4), SIMDE_FLOAT16_VALUE(4.4), SIMDE_FLOAT16_VALUE(4.4) } },
    { { SIMDE_FLOAT16_VALUE(-11.5), SIMDE_FLOAT16_VALUE(-10.6), SIMDE_FLOAT16_VALUE(13.5), SIMDE_FLOAT16_VALUE(-5.6) },
        INT8_C(0),
      { SIMDE_FLOAT16_VALUE(-11.5), SIMDE_FLOAT16_VALUE(-11.5), SIMDE_FLOAT16_VALUE(-11.5), SIMDE_FLOAT16_VALUE(-11.5) } },
    { { SIMDE_FLOAT16_VALUE(-12.6), SIMDE_FLOAT16_VALUE(-12.4), SIMDE_FLOAT16_VALUE(11.3), SIMDE_FLOAT16_VALUE(11.8) },
        INT8_C(0),
      { SIMDE_FLOAT16_VALUE(-12.6), SIMDE_FLOAT16_VALUE(-12.6), SIMDE_FLOAT16_VALUE(-12.6), SIMDE_FLOAT16_VALUE(-12.6) } },
    { { SIMDE_FLOAT16_VALUE(1.7), SIMDE_FLOAT16_VALUE(-12.1), SIMDE_FLOAT16_VALUE(-11.1), SIMDE_FLOAT16_VALUE(-11.3) },
        INT8_C(1),
      { SIMDE_FLOAT16_VALUE(-12.1), SIMDE_FLOAT16_VALUE(-12.1), SIMDE_FLOAT16_VALUE(-12.1), SIMDE_FLOAT16_VALUE(-12.1) } },
    { { SIMDE_FLOAT16_VALUE(-2.9), SIMDE_FLOAT16_VALUE(0.3), SIMDE_FLOAT16_VALUE(11.1), SIMDE_FLOAT16_VALUE(8.8) },
        INT8_C(1),
      { SIMDE_FLOAT16_VALUE(0.3), SIMDE_FLOAT16_VALUE(0.3), SIMDE_FLOAT16_VALUE(0.3), SIMDE_FLOAT16_VALUE(0.3) } },
    { { SIMDE_FLOAT16_VALUE(8.0), SIMDE_FLOAT16_VALUE(-13.7), SIMDE_FLOAT16_VALUE(-3.6), SIMDE_FLOAT16_VALUE(5.8) },
        INT8_C(0),
      { SIMDE_FLOAT16_VALUE(8.0), SIMDE_FLOAT16_VALUE(8.0), SIMDE_FLOAT16_VALUE(8.0), SIMDE_FLOAT16_VALUE(8.0) } },
    { { SIMDE_FLOAT16_VALUE(1.1), SIMDE_FLOAT16_VALUE(10.1), SIMDE_FLOAT16_VALUE(1.2), SIMDE_FLOAT16_VALUE(-11.7) },
        INT8_C(0),
      { SIMDE_FLOAT16_VALUE(1.1), SIMDE_FLOAT16_VALUE(1.1), SIMDE_FLOAT16_VALUE(1.1), SIMDE_FLOAT16_VALUE(1.1) } },
    { { SIMDE_FLOAT16_VALUE(-2.0), SIMDE_FLOAT16_VALUE(-14.0), SIMDE_FLOAT16_VALUE(-13.7), SIMDE_FLOAT16_VALUE(-10.2) },
        INT8_C(0),
      { SIMDE_FLOAT16_VALUE(-2.0), SIMDE_FLOAT16_VALUE(-2.0), SIMDE_FLOAT16_VALUE(-2.0), SIMDE_FLOAT16_VALUE(-2.0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x4_t vec;
    simde_float16x4_t r;

    vec = simde_vld1_f16(test_vec[i].vec);
    SIMDE_CONSTIFY_4_(simde_vdup_lane_f16, r, (HEDLEY_UNREACHABLE(), simde_vdup_n_f16(SIMDE_FLOAT16_VALUE(0.0))), test_vec[i].lane, vec);

    simde_test_arm_neon_assert_equal_f16x4(r, simde_vld1_f16(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_vdup_laneq_f16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float16 vec[8];
    int lane;
    simde_float16 r[4];
  } test_vec[] = {
    { {  SIMDE_FLOAT16_VALUE(     9.056),  SIMDE_FLOAT16_VALUE(     1.677),  SIMDE_FLOAT16_VALUE(     7.053),  SIMDE_FLOAT16_VALUE(    28.437),
         SIMDE_FLOAT16_VALUE(    14.165),  SIMDE_FLOAT16_VALUE(    18.651),  SIMDE_FLOAT16_VALUE(   -23.860),  SIMDE_FLOAT16_VALUE(     2.771) },
         INT8_C(         6),
      {  SIMDE_FLOAT16_VALUE(   -23.860),  SIMDE_FLOAT16_VALUE(   -23.860),  SIMDE_FLOAT16_VALUE(   -23.860),  SIMDE_FLOAT16_VALUE(   -23.860) } },
    { {  SIMDE_FLOAT16_VALUE(    24.258),  SIMDE_FLOAT16_VALUE(   -13.828),  SIMDE_FLOAT16_VALUE(   -26.370),  SIMDE_FLOAT16_VALUE(    19.116),
         SIMDE_FLOAT16_VALUE(    -8.063),  SIMDE_FLOAT16_VALUE(    29.418),  SIMDE_FLOAT16_VALUE(   -20.107),  SIMDE_FLOAT16_VALUE(     7.234) },
         INT8_C(         2),
      {  SIMDE_FLOAT16_VALUE(   -26.370),  SIMDE_FLOAT16_VALUE(   -26.370),  SIMDE_FLOAT16_VALUE(   -26.370),  SIMDE_FLOAT16_VALUE(   -26.370) } },
    { {  SIMDE_FLOAT16_VALUE(   -11.462),  SIMDE_FLOAT16_VALUE(    22.959),  SIMDE_FLOAT16_VALUE(   -17.969),  SIMDE_FLOAT16_VALUE(    -9.845),
         SIMDE_FLOAT16_VALUE(     7.748),  SIMDE_FLOAT16_VALUE(   -18.327),  SIMDE_FLOAT16_VALUE(    13.108),  SIMDE_FLOAT16_VALUE(   -16.811) },
         INT8_C(         7),
      {  SIMDE_FLOAT16_VALUE(   -16.811),  SIMDE_FLOAT16_VALUE(   -16.811),  SIMDE_FLOAT16_VALUE(   -16.811),  SIMDE_FLOAT16_VALUE(   -16.811) } },
    { {  SIMDE_FLOAT16_VALUE(     8.525),  SIMDE_FLOAT16_VALUE(   -15.131),  SIMDE_FLOAT16_VALUE(    14.364),  SIMDE_FLOAT16_VALUE(    -8.648),
         SIMDE_FLOAT16_VALUE(   -10.759),  SIMDE_FLOAT16_VALUE(    -3.780),  SIMDE_FLOAT16_VALUE(     3.004),  SIMDE_FLOAT16_VALUE(   -12.422) },
         INT8_C(         4),
      {  SIMDE_FLOAT16_VALUE(   -10.759),  SIMDE_FLOAT16_VALUE(   -10.759),  SIMDE_FLOAT16_VALUE(   -10.759),  SIMDE_FLOAT16_VALUE(   -10.759) } },
    { {  SIMDE_FLOAT16_VALUE(    12.736),  SIMDE_FLOAT16_VALUE(    10.408),  SIMDE_FLOAT16_VALUE(    16.484),  SIMDE_FLOAT16_VALUE(   -11.569),
         SIMDE_FLOAT16_VALUE(   -27.593),  SIMDE_FLOAT16_VALUE(   -22.388),  SIMDE_FLOAT16_VALUE(     0.182),  SIMDE_FLOAT16_VALUE(    27.270) },
         INT8_C(         1),
      {  SIMDE_FLOAT16_VALUE(    10.408),  SIMDE_FLOAT16_VALUE(    10.408),  SIMDE_FLOAT16_VALUE(    10.408),  SIMDE_FLOAT16_VALUE(    10.408) } },
    { {  SIMDE_FLOAT16_VALUE(    -8.778),  SIMDE_FLOAT16_VALUE(     6.046),  SIMDE_FLOAT16_VALUE(     1.558),  SIMDE_FLOAT16_VALUE(     7.396),
         SIMDE_FLOAT16_VALUE(    29.886),  SIMDE_FLOAT16_VALUE(    -0.845),  SIMDE_FLOAT16_VALUE(    14.948),  SIMDE_FLOAT16_VALUE(    17.996) },
         INT8_C(         6),
      {  SIMDE_FLOAT16_VALUE(    14.948),  SIMDE_FLOAT16_VALUE(    14.948),  SIMDE_FLOAT16_VALUE(    14.948),  SIMDE_FLOAT16_VALUE(    14.948) } },
    { {  SIMDE_FLOAT16_VALUE(    -9.902),  SIMDE_FLOAT16_VALUE(    20.687),  SIMDE_FLOAT16_VALUE(   -25.203),  SIMDE_FLOAT16_VALUE(    13.883),
         SIMDE_FLOAT16_VALUE(   -14.370),  SIMDE_FLOAT16_VALUE(   -27.322),  SIMDE_FLOAT16_VALUE(   -24.150),  SIMDE_FLOAT16_VALUE(   -21.580) },
         INT8_C(         1),
      {  SIMDE_FLOAT16_VALUE(    20.687),  SIMDE_FLOAT16_VALUE(    20.687),  SIMDE_FLOAT16_VALUE(    20.687),  SIMDE_FLOAT16_VALUE(    20.687) } },
    { {  SIMDE_FLOAT16_VALUE(    11.499),  SIMDE_FLOAT16_VALUE(   -13.869),  SIMDE_FLOAT16_VALUE(   -27.353),  SIMDE_FLOAT16_VALUE(     6.786),
         SIMDE_FLOAT16_VALUE(    29.577),  SIMDE_FLOAT16_VALUE(    -4.705),  SIMDE_FLOAT16_VALUE(   -25.496),  SIMDE_FLOAT16_VALUE(    26.515) },
         INT8_C(         0),
      {  SIMDE_FLOAT16_VALUE(    11.499),  SIMDE_FLOAT16_VALUE(    11.499),  SIMDE_FLOAT16_VALUE(    11.499),  SIMDE_FLOAT16_VALUE(    11.499) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x8_t vec;
    simde_float16x4_t r;

    vec = simde_vld1q_f16(test_vec[i].vec);
    SIMDE_CONSTIFY_8_(simde_vdup_laneq_f16, r, (HEDLEY_UNREACHABLE(), r), test_vec[i].lane, vec);

    simde_test_arm_neon_assert_equal_f16x4(r, simde_vld1_f16(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_vdupq_lane_f16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float16_t vec[4];
    int lane;
    simde_float16_t r[8];
  } test_vec[] = {
    { { SIMDE_FLOAT16_VALUE(-3.4), SIMDE_FLOAT16_VALUE(6.4), SIMDE_FLOAT16_VALUE(-7.4), SIMDE_FLOAT16_VALUE(0.5) },
        INT8_C(0),
      { SIMDE_FLOAT16_VALUE(-3.4), SIMDE_FLOAT16_VALUE(-3.4), SIMDE_FLOAT16_VALUE(-3.4), SIMDE_FLOAT16_VALUE(-3.4),
        SIMDE_FLOAT16_VALUE(-3.4), SIMDE_FLOAT16_VALUE(-3.4), SIMDE_FLOAT16_VALUE(-3.4), SIMDE_FLOAT16_VALUE(-3.4) } },
    { { SIMDE_FLOAT16_VALUE(8.1), SIMDE_FLOAT16_VALUE(-0.0), SIMDE_FLOAT16_VALUE(6.2), SIMDE_FLOAT16_VALUE(-5.5) },
        INT8_C(3),
      { SIMDE_FLOAT16_VALUE(-5.5), SIMDE_FLOAT16_VALUE(-5.5), SIMDE_FLOAT16_VALUE(-5.5), SIMDE_FLOAT16_VALUE(-5.5),
        SIMDE_FLOAT16_VALUE(-5.5), SIMDE_FLOAT16_VALUE(-5.5), SIMDE_FLOAT16_VALUE(-5.5), SIMDE_FLOAT16_VALUE(-5.5) } },
    { { SIMDE_FLOAT16_VALUE(-9.6), SIMDE_FLOAT16_VALUE(6.7), SIMDE_FLOAT16_VALUE(1.4), SIMDE_FLOAT16_VALUE(10.7) },
        INT8_C(3),
      { SIMDE_FLOAT16_VALUE(10.7), SIMDE_FLOAT16_VALUE(10.7), SIMDE_FLOAT16_VALUE(10.7), SIMDE_FLOAT16_VALUE(10.7),
        SIMDE_FLOAT16_VALUE(10.7), SIMDE_FLOAT16_VALUE(10.7), SIMDE_FLOAT16_VALUE(10.7), SIMDE_FLOAT16_VALUE(10.7) } },
    { { SIMDE_FLOAT16_VALUE(2.9), SIMDE_FLOAT16_VALUE(-15.0), SIMDE_FLOAT16_VALUE(14.8), SIMDE_FLOAT16_VALUE(-2.2) },
        INT8_C(1),
      { SIMDE_FLOAT16_VALUE(-15.0), SIMDE_FLOAT16_VALUE(-15.0), SIMDE_FLOAT16_VALUE(-15.0), SIMDE_FLOAT16_VALUE(-15.0),
        SIMDE_FLOAT16_VALUE(-15.0), SIMDE_FLOAT16_VALUE(-15.0), SIMDE_FLOAT16_VALUE(-15.0), SIMDE_FLOAT16_VALUE(-15.0) } },
    { { SIMDE_FLOAT16_VALUE(0.4), SIMDE_FLOAT16_VALUE(0.2), SIMDE_FLOAT16_VALUE(7.5), SIMDE_FLOAT16_VALUE(-14.7) },
        INT8_C(2),
      { SIMDE_FLOAT16_VALUE(7.5), SIMDE_FLOAT16_VALUE(7.5), SIMDE_FLOAT16_VALUE(7.5), SIMDE_FLOAT16_VALUE(7.5),
        SIMDE_FLOAT16_VALUE(7.5), SIMDE_FLOAT16_VALUE(7.5), SIMDE_FLOAT16_VALUE(7.5), SIMDE_FLOAT16_VALUE(7.5) } },
    { { SIMDE_FLOAT16_VALUE(-6.0), SIMDE_FLOAT16_VALUE(0.4), SIMDE_FLOAT16_VALUE(-8.9), SIMDE_FLOAT16_VALUE(-11.3) },
        INT8_C(3),
      { SIMDE_FLOAT16_VALUE(-11.3), SIMDE_FLOAT16_VALUE(-11.3), SIMDE_FLOAT16_VALUE(-11.3), SIMDE_FLOAT16_VALUE(-11.3),
        SIMDE_FLOAT16_VALUE(-11.3), SIMDE_FLOAT16_VALUE(-11.3), SIMDE_FLOAT16_VALUE(-11.3), SIMDE_FLOAT16_VALUE(-11.3) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x4_t vec;
    simde_float16x8_t r;

    vec = simde_vld1_f16(test_vec[i].vec);
    SIMDE_CONSTIFY_4_(simde_vdupq_lane_f16, r, (HEDLEY_UNREACHABLE(), simde_vdupq_n_f16(SIMDE_FLOAT16_VALUE(0.0))), test_vec[i].lane, vec);

    simde_test_arm_neon_assert_equal_f16x8(r, simde_vld1q_f16(test_vec[i].r), 1);
  }

  return 0;
}


static int
test_simde_vdup_lane_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float32 vec[2];
    int lane;
    simde_float32 r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -787.13), SIMDE_FLOAT32_C(   -15.07) },
       INT8_C(   1),
      { SIMDE_FLOAT32_C(   -15.07), SIMDE_FLOAT32_C(   -15.07) } },
    { { SIMDE_FLOAT32_C(    46.30), SIMDE_FLOAT32_C(   346.17) },
       INT8_C(   1),
      { SIMDE_FLOAT32_C(   346.17), SIMDE_FLOAT32_C(   346.17) } },
    { { SIMDE_FLOAT32_C(  -139.62), SIMDE_FLOAT32_C(   486.64) },
       INT8_C(   0),
      { SIMDE_FLOAT32_C(  -139.62), SIMDE_FLOAT32_C(  -139.62) } },
    { { SIMDE_FLOAT32_C(   -65.92), SIMDE_FLOAT32_C(   539.38) },
       INT8_C(   0),
      { SIMDE_FLOAT32_C(   -65.92), SIMDE_FLOAT32_C(   -65.92) } },
    { { SIMDE_FLOAT32_C(  -303.01), SIMDE_FLOAT32_C(   704.85) },
       INT8_C(   0),
      { SIMDE_FLOAT32_C(  -303.01), SIMDE_FLOAT32_C(  -303.01) } },
    { { SIMDE_FLOAT32_C(   135.71), SIMDE_FLOAT32_C(   169.99) },
       INT8_C(   1),
      { SIMDE_FLOAT32_C(   169.99), SIMDE_FLOAT32_C(   169.99) } },
    { { SIMDE_FLOAT32_C(   262.13), SIMDE_FLOAT32_C(   264.53) },
       INT8_C(   1),
      { SIMDE_FLOAT32_C(   264.53), SIMDE_FLOAT32_C(   264.53) } },
    { { SIMDE_FLOAT32_C(   988.58), SIMDE_FLOAT32_C(  -848.75) },
       INT8_C(   0),
      { SIMDE_FLOAT32_C(   988.58), SIMDE_FLOAT32_C(   988.58) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t vec;
    simde_float32x2_t r;

    vec = simde_vld1_f32(test_vec[i].vec);
    SIMDE_CONSTIFY_2_(simde_vdup_lane_f32, r, (HEDLEY_UNREACHABLE(), simde_vdup_n_f32(0.0f)), test_vec[i].lane, vec);

    simde_test_arm_neon_assert_equal_f32x2(r, simde_vld1_f32(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x2_t vec = simde_test_arm_neon_random_f32x2(-1000.0, 1000.0);
    int lane = simde_test_codegen_random_i8() & 1;

    simde_float32x2_t r;
    SIMDE_CONSTIFY_2_(simde_vdup_lane_f32, r, (HEDLEY_UNREACHABLE(), simde_vdup_n_f32(0.0f)), lane, vec);

    simde_test_arm_neon_write_f32x2(2, vec, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i8(2, HEDLEY_STATIC_CAST(int8_t, lane), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vdup_lane_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float64 vec[1];
    simde_float64 r[1];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(   101.54) },
      { SIMDE_FLOAT64_C(   101.54) } },
    { { SIMDE_FLOAT64_C(   798.61) },
      { SIMDE_FLOAT64_C(   798.61) } },
    { { SIMDE_FLOAT64_C(   273.92) },
      { SIMDE_FLOAT64_C(   273.92) } },
    { { SIMDE_FLOAT64_C(   -17.48) },
      { SIMDE_FLOAT64_C(   -17.48) } },
    { { SIMDE_FLOAT64_C(   458.09) },
      { SIMDE_FLOAT64_C(   458.09) } },
    { { SIMDE_FLOAT64_C(   541.19) },
      { SIMDE_FLOAT64_C(   541.19) } },
    { { SIMDE_FLOAT64_C(  -316.84) },
      { SIMDE_FLOAT64_C(  -316.84) } },
    { { SIMDE_FLOAT64_C(   934.37) },
      { SIMDE_FLOAT64_C(   934.37) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x1_t vec;
    simde_float64x1_t r;

    vec = simde_vld1_f64(test_vec[i].vec);
    r = simde_vdup_lane_f64(vec, 0);

    simde_test_arm_neon_assert_equal_f64x1(r, simde_vld1_f64(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x1_t vec = simde_test_arm_neon_random_f64x1(-1000.0, 1000.0);
    simde_float64x1_t r = simde_vdup_lane_f64(vec, 0);

    simde_test_arm_neon_write_f64x1(2, vec, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vdup_lane_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int8_t vec[8];
    int lane;
    int8_t r[8];
  } test_vec[] = {
    { { -INT8_C( 109),  INT8_C(  86), -INT8_C(  70), -INT8_C(  70),  INT8_C(  94), -INT8_C(  56), -INT8_C(  20),  INT8_C(  18) },
       INT8_C(   3),
      { -INT8_C(  70), -INT8_C(  70), -INT8_C(  70), -INT8_C(  70), -INT8_C(  70), -INT8_C(  70), -INT8_C(  70), -INT8_C(  70) } },
    { {  INT8_C(  28), -INT8_C(  32),  INT8_C(  48), -INT8_C(  97), -INT8_C( 103),  INT8_C(  50),  INT8_C(  39),  INT8_C(  80) },
       INT8_C(   6),
      {  INT8_C(  39),  INT8_C(  39),  INT8_C(  39),  INT8_C(  39),  INT8_C(  39),  INT8_C(  39),  INT8_C(  39),  INT8_C(  39) } },
    { {  INT8_C( 125),  INT8_C(  42),      INT8_MIN, -INT8_C(  38), -INT8_C(  52), -INT8_C(  85),  INT8_C(  12), -INT8_C(  25) },
       INT8_C(   1),
      {  INT8_C(  42),  INT8_C(  42),  INT8_C(  42),  INT8_C(  42),  INT8_C(  42),  INT8_C(  42),  INT8_C(  42),  INT8_C(  42) } },
    { { -INT8_C(  51), -INT8_C( 113), -INT8_C(  42), -INT8_C( 121),  INT8_C(  34),  INT8_C(  44),  INT8_C(  65), -INT8_C(  36) },
       INT8_C(   3),
      { -INT8_C( 121), -INT8_C( 121), -INT8_C( 121), -INT8_C( 121), -INT8_C( 121), -INT8_C( 121), -INT8_C( 121), -INT8_C( 121) } },
    { {  INT8_C(   9), -INT8_C(  55), -INT8_C(  99), -INT8_C(  59), -INT8_C(  27),  INT8_C( 125), -INT8_C(  11), -INT8_C( 124) },
       INT8_C(   6),
      { -INT8_C(  11), -INT8_C(  11), -INT8_C(  11), -INT8_C(  11), -INT8_C(  11), -INT8_C(  11), -INT8_C(  11), -INT8_C(  11) } },
    { {  INT8_C(  40), -INT8_C(  84),  INT8_C( 102),  INT8_C(  22),  INT8_C(  41), -INT8_C( 111), -INT8_C( 105),  INT8_C(   3) },
       INT8_C(   5),
      { -INT8_C( 111), -INT8_C( 111), -INT8_C( 111), -INT8_C( 111), -INT8_C( 111), -INT8_C( 111), -INT8_C( 111), -INT8_C( 111) } },
    { {  INT8_C(  66),  INT8_C(  16),  INT8_C(  68),  INT8_C(  91), -INT8_C(  35), -INT8_C(  44),  INT8_C(  49),  INT8_C( 100) },
       INT8_C(   6),
      {  INT8_C(  49),  INT8_C(  49),  INT8_C(  49),  INT8_C(  49),  INT8_C(  49),  INT8_C(  49),  INT8_C(  49),  INT8_C(  49) } },
    { {  INT8_C(  94), -INT8_C(  91), -INT8_C(  45), -INT8_C(  23), -INT8_C(  81), -INT8_C( 100), -INT8_C( 122),  INT8_C( 116) },
       INT8_C(   1),
      { -INT8_C(  91), -INT8_C(  91), -INT8_C(  91), -INT8_C(  91), -INT8_C(  91), -INT8_C(  91), -INT8_C(  91), -INT8_C(  91) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8_t vec;
    simde_int8x8_t r;

    vec = simde_vld1_s8(test_vec[i].vec);
    SIMDE_CONSTIFY_8_(simde_vdup_lane_s8, r, (HEDLEY_UNREACHABLE(), simde_vdup_n_s8(INT8_C(0))), test_vec[i].lane, vec);

    simde_test_arm_neon_assert_equal_i8x8(r, simde_vld1_s8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x8_t vec = simde_test_arm_neon_random_i8x8();
    int lane = simde_test_codegen_random_i8() & 7;

    simde_int8x8_t r;
    SIMDE_CONSTIFY_8_(simde_vdup_lane_s8, r, (HEDLEY_UNREACHABLE(), simde_vdup_n_s8(INT8_C(0))), lane, vec);

    simde_test_arm_neon_write_i8x8(2, vec, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i8(2, HEDLEY_STATIC_CAST(int8_t, lane), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vdup_lane_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int16_t vec[4];
    int lane;
    int16_t r[4];
  } test_vec[] = {
    { { -INT16_C( 18698), -INT16_C( 28829), -INT16_C( 10148),  INT16_C( 27234) },
       INT8_C(   2),
      { -INT16_C( 10148), -INT16_C( 10148), -INT16_C( 10148), -INT16_C( 10148) } },
    { {  INT16_C( 10218), -INT16_C( 11581),  INT16_C( 15139),  INT16_C(  3770) },
       INT8_C(   0),
      {  INT16_C( 10218),  INT16_C( 10218),  INT16_C( 10218),  INT16_C( 10218) } },
    { { -INT16_C( 17031), -INT16_C( 15001), -INT16_C( 20844), -INT16_C( 10697) },
       INT8_C(   0),
      { -INT16_C( 17031), -INT16_C( 17031), -INT16_C( 17031), -INT16_C( 17031) } },
    { {  INT16_C( 15543),  INT16_C(  6027),  INT16_C( 16691), -INT16_C( 15750) },
       INT8_C(   1),
      {  INT16_C(  6027),  INT16_C(  6027),  INT16_C(  6027),  INT16_C(  6027) } },
    { {  INT16_C(  9555),  INT16_C(  2311),  INT16_C( 11791), -INT16_C(  7731) },
       INT8_C(   1),
      {  INT16_C(  2311),  INT16_C(  2311),  INT16_C(  2311),  INT16_C(  2311) } },
    { { -INT16_C( 25848), -INT16_C(  7073),  INT16_C(  7444), -INT16_C(  9909) },
       INT8_C(   1),
      { -INT16_C(  7073), -INT16_C(  7073), -INT16_C(  7073), -INT16_C(  7073) } },
    { {  INT16_C(  4345),  INT16_C( 10632), -INT16_C( 15161), -INT16_C(  8524) },
       INT8_C(   3),
      { -INT16_C(  8524), -INT16_C(  8524), -INT16_C(  8524), -INT16_C(  8524) } },
    { {  INT16_C( 23029), -INT16_C( 27974), -INT16_C(  8276), -INT16_C( 19047) },
       INT8_C(   2),
      { -INT16_C(  8276), -INT16_C(  8276), -INT16_C(  8276), -INT16_C(  8276) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t vec;
    simde_int16x4_t r;

    vec = simde_vld1_s16(test_vec[i].vec);
    SIMDE_CONSTIFY_4_(simde_vdup_lane_s16, r, (HEDLEY_UNREACHABLE(), simde_vdup_n_s16(INT16_C(0))), test_vec[i].lane, vec);

    simde_test_arm_neon_assert_equal_i16x4(r, simde_vld1_s16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x4_t vec = simde_test_arm_neon_random_i16x4();
    int lane = simde_test_codegen_random_i8() & 3;

    simde_int16x4_t r;
    SIMDE_CONSTIFY_4_(simde_vdup_lane_s16, r, (HEDLEY_UNREACHABLE(), simde_vdup_n_s16(INT8_C(0))), lane, vec);

    simde_test_arm_neon_write_i16x4(2, vec, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i8(2, HEDLEY_STATIC_CAST(int8_t, lane), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vdup_lane_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int32_t vec[2];
    int lane;
    int32_t r[2];
  } test_vec[] = {
    { { -INT32_C(  1646161109), -INT32_C(  1747230745) },
       INT8_C(   0),
      { -INT32_C(  1646161109), -INT32_C(  1646161109) } },
    { { -INT32_C(  1434884716),  INT32_C(   398389744) },
       INT8_C(   1),
      {  INT32_C(   398389744),  INT32_C(   398389744) } },
    { { -INT32_C(  1849175508),  INT32_C(  1020151922) },
       INT8_C(   0),
      { -INT32_C(  1849175508), -INT32_C(  1849175508) } },
    { { -INT32_C(  1012620287),  INT32_C(  1822701775) },
       INT8_C(   1),
      {  INT32_C(  1822701775),  INT32_C(  1822701775) } },
    { {  INT32_C(  1219905284), -INT32_C(  2050876197) },
       INT8_C(   0),
      {  INT32_C(  1219905284),  INT32_C(  1219905284) } },
    { { -INT32_C(   870104141),  INT32_C(    26539632) },
       INT8_C(   0),
      { -INT32_C(   870104141), -INT32_C(   870104141) } },
    { { -INT32_C(  1801137956), -INT32_C(  1808185135) },
       INT8_C(   1),
      { -INT32_C(  1808185135), -INT32_C(  1808185135) } },
    { { -INT32_C(  1870382735), -INT32_C(  2058958019) },
       INT8_C(   1),
      { -INT32_C(  2058958019), -INT32_C(  2058958019) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t vec;
    simde_int32x2_t r;

    vec = simde_vld1_s32(test_vec[i].vec);
    SIMDE_CONSTIFY_2_(simde_vdup_lane_s32, r, (HEDLEY_UNREACHABLE(), simde_vdup_n_s32(INT32_C(0))), test_vec[i].lane, vec);

    simde_test_arm_neon_assert_equal_i32x2(r, simde_vld1_s32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x2_t vec = simde_test_arm_neon_random_i32x2();
    int lane = simde_test_codegen_random_i8() & 1;

    simde_int32x2_t r;
    SIMDE_CONSTIFY_2_(simde_vdup_lane_s32, r, (HEDLEY_UNREACHABLE(), simde_vdup_n_s32(INT8_C(0))), lane, vec);

    simde_test_arm_neon_write_i32x2(2, vec, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i8(2, HEDLEY_STATIC_CAST(int8_t, lane), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vdup_lane_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int64_t vec[1];
    int64_t r[1];
  } test_vec[] = {
    { { -INT64_C( 4066063288374638750) },
      { -INT64_C( 4066063288374638750) } },
    { { -INT64_C( 7732336477994252064) },
      { -INT64_C( 7732336477994252064) } },
    { {  INT64_C( 5798089950005920716) },
      {  INT64_C( 5798089950005920716) } },
    { { -INT64_C( 5770497274961656200) },
      { -INT64_C( 5770497274961656200) } },
    { {  INT64_C( 7430289055526295386) },
      {  INT64_C( 7430289055526295386) } },
    { {  INT64_C( 9060392184859686968) },
      {  INT64_C( 9060392184859686968) } },
    { {  INT64_C(  497077724683344253) },
      {  INT64_C(  497077724683344253) } },
    { { -INT64_C( 2234852464160771073) },
      { -INT64_C( 2234852464160771073) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x1_t vec;
    simde_int64x1_t r;

    vec = simde_vld1_s64(test_vec[i].vec);
    r = simde_vdup_lane_s64(vec, 0);

    simde_test_arm_neon_assert_equal_i64x1(r, simde_vld1_s64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int64x1_t vec = simde_test_arm_neon_random_i64x1();

    simde_int64x1_t r = simde_vdup_lane_s64(vec, 0);

    simde_test_arm_neon_write_i64x1(2, vec, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vdup_lane_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint8_t vec[8];
    int lane;
    uint8_t r[8];
  } test_vec[] = {
    { { UINT8_C(225), UINT8_C( 70), UINT8_C(222), UINT8_C( 40), UINT8_C( 85), UINT8_C( 93), UINT8_C( 35), UINT8_C(172) },
      UINT8_C(  6),
      { UINT8_C( 35), UINT8_C( 35), UINT8_C( 35), UINT8_C( 35), UINT8_C( 35), UINT8_C( 35), UINT8_C( 35), UINT8_C( 35) } },
    { { UINT8_C( 14), UINT8_C(104), UINT8_C(219), UINT8_C(190), UINT8_C( 18), UINT8_C( 59), UINT8_C(  6), UINT8_C(151) },
      UINT8_C(  5),
      { UINT8_C( 59), UINT8_C( 59), UINT8_C( 59), UINT8_C( 59), UINT8_C( 59), UINT8_C( 59), UINT8_C( 59), UINT8_C( 59) } },
    { { UINT8_C( 86), UINT8_C(237), UINT8_C( 93), UINT8_C(114), UINT8_C(246), UINT8_C(234), UINT8_C(197), UINT8_C( 48) },
      UINT8_C(  6),
      { UINT8_C(197), UINT8_C(197), UINT8_C(197), UINT8_C(197), UINT8_C(197), UINT8_C(197), UINT8_C(197), UINT8_C(197) } },
    { { UINT8_C(140), UINT8_C(105), UINT8_C(114), UINT8_C( 55), UINT8_C( 74), UINT8_C(184), UINT8_C( 21), UINT8_C(115) },
      UINT8_C(  5),
      { UINT8_C(184), UINT8_C(184), UINT8_C(184), UINT8_C(184), UINT8_C(184), UINT8_C(184), UINT8_C(184), UINT8_C(184) } },
    { { UINT8_C(114), UINT8_C(150), UINT8_C(186), UINT8_C(200), UINT8_C(164), UINT8_C( 34), UINT8_C(164), UINT8_C( 98) },
      UINT8_C(  4),
      { UINT8_C(164), UINT8_C(164), UINT8_C(164), UINT8_C(164), UINT8_C(164), UINT8_C(164), UINT8_C(164), UINT8_C(164) } },
    { { UINT8_C(223), UINT8_C(104), UINT8_C(203), UINT8_C( 12), UINT8_C(190), UINT8_C(184), UINT8_C(105), UINT8_C( 48) },
      UINT8_C(  7),
      { UINT8_C( 48), UINT8_C( 48), UINT8_C( 48), UINT8_C( 48), UINT8_C( 48), UINT8_C( 48), UINT8_C( 48), UINT8_C( 48) } },
    { { UINT8_C( 84), UINT8_C(245), UINT8_C(223), UINT8_C(146), UINT8_C(130), UINT8_C( 73), UINT8_C(  4), UINT8_C(185) },
      UINT8_C(  3),
      { UINT8_C(146), UINT8_C(146), UINT8_C(146), UINT8_C(146), UINT8_C(146), UINT8_C(146), UINT8_C(146), UINT8_C(146) } },
    { { UINT8_C(188), UINT8_C(206), UINT8_C(  6), UINT8_C(202), UINT8_C( 64), UINT8_C(157), UINT8_C(132), UINT8_C(  8) },
      UINT8_C(  1),
      { UINT8_C(206), UINT8_C(206), UINT8_C(206), UINT8_C(206), UINT8_C(206), UINT8_C(206), UINT8_C(206), UINT8_C(206) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x8_t vec;
    simde_uint8x8_t r;

    vec = simde_vld1_u8(test_vec[i].vec);
    SIMDE_CONSTIFY_8_(simde_vdup_lane_u8, r, (HEDLEY_UNREACHABLE(), simde_vdup_n_u8(UINT8_C(0))), test_vec[i].lane, vec);

    simde_test_arm_neon_assert_equal_u8x8(r, simde_vld1_u8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8x8_t vec = simde_test_arm_neon_random_u8x8();
    int lane = simde_test_codegen_random_u8() & 7;

    simde_uint8x8_t r;
    SIMDE_CONSTIFY_8_(simde_vdup_lane_u8, r, (HEDLEY_UNREACHABLE(), simde_vdup_n_u8(UINT8_C(0))), lane, vec);

    simde_test_arm_neon_write_u8x8(2, vec, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u8(2, HEDLEY_STATIC_CAST(uint8_t, lane), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vdup_lane_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint16_t vec[4];
    int lane;
    uint16_t r[4];
  } test_vec[] = {
    { { UINT16_C(39155), UINT16_C(17108), UINT16_C(35862), UINT16_C(33952) },
      UINT8_C(  0),
      { UINT16_C(39155), UINT16_C(39155), UINT16_C(39155), UINT16_C(39155) } },
    { { UINT16_C(25643), UINT16_C(65303), UINT16_C(24516), UINT16_C(25191) },
      UINT8_C(  2),
      { UINT16_C(24516), UINT16_C(24516), UINT16_C(24516), UINT16_C(24516) } },
    { { UINT16_C(41498), UINT16_C(10432), UINT16_C(25102), UINT16_C( 2461) },
      UINT8_C(  2),
      { UINT16_C(25102), UINT16_C(25102), UINT16_C(25102), UINT16_C(25102) } },
    { { UINT16_C(35666), UINT16_C(21432), UINT16_C(20862), UINT16_C(49191) },
      UINT8_C(  3),
      { UINT16_C(49191), UINT16_C(49191), UINT16_C(49191), UINT16_C(49191) } },
    { { UINT16_C(25011), UINT16_C(28908), UINT16_C(20620), UINT16_C(35719) },
      UINT8_C(  1),
      { UINT16_C(28908), UINT16_C(28908), UINT16_C(28908), UINT16_C(28908) } },
    { { UINT16_C(62439), UINT16_C(54647), UINT16_C( 6413), UINT16_C(13717) },
      UINT8_C(  0),
      { UINT16_C(62439), UINT16_C(62439), UINT16_C(62439), UINT16_C(62439) } },
    { { UINT16_C(54007), UINT16_C(11569), UINT16_C(48165), UINT16_C(30950) },
      UINT8_C(  3),
      { UINT16_C(30950), UINT16_C(30950), UINT16_C(30950), UINT16_C(30950) } },
    { { UINT16_C(41015), UINT16_C(40699), UINT16_C(23635), UINT16_C(50058) },
      UINT8_C(  1),
      { UINT16_C(40699), UINT16_C(40699), UINT16_C(40699), UINT16_C(40699) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4_t vec;
    simde_uint16x4_t r;

    vec = simde_vld1_u16(test_vec[i].vec);
    SIMDE_CONSTIFY_4_(simde_vdup_lane_u16, r, (HEDLEY_UNREACHABLE(), simde_vdup_n_u16(UINT16_C(0))), test_vec[i].lane, vec);

    simde_test_arm_neon_assert_equal_u16x4(r, simde_vld1_u16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x4_t vec = simde_test_arm_neon_random_u16x4();
    int lane = simde_test_codegen_random_u8() & 3;

    simde_uint16x4_t r;
    SIMDE_CONSTIFY_4_(simde_vdup_lane_u16, r, (HEDLEY_UNREACHABLE(), simde_vdup_n_u16(UINT8_C(0))), lane, vec);

    simde_test_arm_neon_write_u16x4(2, vec, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u8(2, HEDLEY_STATIC_CAST(uint8_t, lane), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vdup_lane_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint32_t vec[2];
    int lane;
    uint32_t r[2];
  } test_vec[] = {
    { { UINT32_C(4034153435), UINT32_C( 124217138) },
      UINT8_C(  0),
      { UINT32_C(4034153435), UINT32_C(4034153435) } },
    { { UINT32_C(2846465153), UINT32_C(3235544211) },
      UINT8_C(  1),
      { UINT32_C(3235544211), UINT32_C(3235544211) } },
    { { UINT32_C(3524896407), UINT32_C(2093857245) },
      UINT8_C(  1),
      { UINT32_C(2093857245), UINT32_C(2093857245) } },
    { { UINT32_C( 332400170), UINT32_C(3515292641) },
      UINT8_C(  1),
      { UINT32_C(3515292641), UINT32_C(3515292641) } },
    { { UINT32_C(1666464239), UINT32_C(1661857978) },
      UINT8_C(  1),
      { UINT32_C(1661857978), UINT32_C(1661857978) } },
    { { UINT32_C( 709115273), UINT32_C(2789468884) },
      UINT8_C(  0),
      { UINT32_C( 709115273), UINT32_C( 709115273) } },
    { { UINT32_C( 172258557), UINT32_C(2983873182) },
      UINT8_C(  0),
      { UINT32_C( 172258557), UINT32_C( 172258557) } },
    { { UINT32_C(1140668662), UINT32_C(2342008359) },
      UINT8_C(  0),
      { UINT32_C(1140668662), UINT32_C(1140668662) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2_t vec;
    simde_uint32x2_t r;

    vec = simde_vld1_u32(test_vec[i].vec);
    SIMDE_CONSTIFY_2_(simde_vdup_lane_u32, r, (HEDLEY_UNREACHABLE(), simde_vdup_n_u32(UINT32_C(0))), test_vec[i].lane, vec);

    simde_test_arm_neon_assert_equal_u32x2(r, simde_vld1_u32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x2_t vec = simde_test_arm_neon_random_u32x2();
    int lane = simde_test_codegen_random_u8() & 1;

    simde_uint32x2_t r;
    SIMDE_CONSTIFY_2_(simde_vdup_lane_u32, r, (HEDLEY_UNREACHABLE(), simde_vdup_n_u32(UINT8_C(0))), lane, vec);

    simde_test_arm_neon_write_u32x2(2, vec, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u8(2, HEDLEY_STATIC_CAST(uint8_t, lane), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vdup_lane_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint64_t vec[1];
    uint64_t r[1];
  } test_vec[] = {
    { { UINT64_C( 5426997122108201096) },
      { UINT64_C( 5426997122108201096) } },
    { { UINT64_C( 5080213220590762597) },
      { UINT64_C( 5080213220590762597) } },
    { { UINT64_C(  533322304534421141) },
      { UINT64_C(  533322304534421141) } },
    { { UINT64_C(14619170657803413946) },
      { UINT64_C(14619170657803413946) } },
    { { UINT64_C( 3151999422994724178) },
      { UINT64_C( 3151999422994724178) } },
    { { UINT64_C( 7902049161203633248) },
      { UINT64_C( 7902049161203633248) } },
    { { UINT64_C(12874740165647350485) },
      { UINT64_C(12874740165647350485) } },
    { { UINT64_C(16715255793253080045) },
      { UINT64_C(16715255793253080045) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x1_t vec;
    simde_uint64x1_t r;

    vec = simde_vld1_u64(test_vec[i].vec);
    r = simde_vdup_lane_u64(vec, 0);

    simde_test_arm_neon_assert_equal_u64x1(r, simde_vld1_u64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint64x1_t vec = simde_test_arm_neon_random_u64x1();

    simde_uint64x1_t r = simde_vdup_lane_u64(vec, 0);

    simde_test_arm_neon_write_u64x1(2, vec, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vdup_laneq_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float32 vec[4];
    int lane;
    simde_float32 r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   757.85), SIMDE_FLOAT32_C(  -809.44), SIMDE_FLOAT32_C(  -135.68), SIMDE_FLOAT32_C(  -140.81) },
       INT8_C(   0),
      { SIMDE_FLOAT32_C(   757.85), SIMDE_FLOAT32_C(   757.85) } },
    { { SIMDE_FLOAT32_C(  -948.46), SIMDE_FLOAT32_C(   482.38), SIMDE_FLOAT32_C(   971.59), SIMDE_FLOAT32_C(  -845.91) },
       INT8_C(   0),
      { SIMDE_FLOAT32_C(  -948.46), SIMDE_FLOAT32_C(  -948.46) } },
    { { SIMDE_FLOAT32_C(   656.44), SIMDE_FLOAT32_C(  -574.13), SIMDE_FLOAT32_C(  -306.48), SIMDE_FLOAT32_C(   302.94) },
       INT8_C(   1),
      { SIMDE_FLOAT32_C(  -574.13), SIMDE_FLOAT32_C(  -574.13) } },
    { { SIMDE_FLOAT32_C(  -419.88), SIMDE_FLOAT32_C(   844.59), SIMDE_FLOAT32_C(  -860.06), SIMDE_FLOAT32_C(   931.61) },
       INT8_C(   2),
      { SIMDE_FLOAT32_C(  -860.06), SIMDE_FLOAT32_C(  -860.06) } },
    { { SIMDE_FLOAT32_C(   -45.34), SIMDE_FLOAT32_C(   773.65), SIMDE_FLOAT32_C(   451.92), SIMDE_FLOAT32_C(  -733.20) },
       INT8_C(   1),
      { SIMDE_FLOAT32_C(   773.65), SIMDE_FLOAT32_C(   773.65) } },
    { { SIMDE_FLOAT32_C(   845.90), SIMDE_FLOAT32_C(  -853.55), SIMDE_FLOAT32_C(  -684.75), SIMDE_FLOAT32_C(   154.60) },
       INT8_C(   2),
      { SIMDE_FLOAT32_C(  -684.75), SIMDE_FLOAT32_C(  -684.75) } },
    { { SIMDE_FLOAT32_C(  -651.35), SIMDE_FLOAT32_C(   -87.55), SIMDE_FLOAT32_C(  -854.44), SIMDE_FLOAT32_C(   212.97) },
       INT8_C(   1),
      { SIMDE_FLOAT32_C(   -87.55), SIMDE_FLOAT32_C(   -87.55) } },
    { { SIMDE_FLOAT32_C(  -829.33), SIMDE_FLOAT32_C(   264.52), SIMDE_FLOAT32_C(   254.03), SIMDE_FLOAT32_C(  -857.74) },
       INT8_C(   3),
      { SIMDE_FLOAT32_C(  -857.74), SIMDE_FLOAT32_C(  -857.74) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t vec;
    simde_float32x2_t r;

    vec = simde_vld1q_f32(test_vec[i].vec);
    SIMDE_CONSTIFY_4_(simde_vdup_laneq_f32, r, (HEDLEY_UNREACHABLE(), simde_vdup_n_f32(0.0f)), test_vec[i].lane, vec);

    simde_test_arm_neon_assert_equal_f32x2(r, simde_vld1_f32(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x4_t vec = simde_test_arm_neon_random_f32x4(-1000.0, 1000.0);
    int lane = simde_test_codegen_random_i8() & 3;

    simde_float32x2_t r;
    SIMDE_CONSTIFY_4_(simde_vdup_laneq_f32, r, (HEDLEY_UNREACHABLE(), simde_vdup_n_f32(0.0f)), lane, vec);

    simde_test_arm_neon_write_f32x4(2, vec, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i8(2, HEDLEY_STATIC_CAST(int8_t, lane), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vdup_laneq_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float64 vec[2];
    int lane;
    simde_float64 r[1];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(  -964.14), SIMDE_FLOAT64_C(   302.49) },
       INT8_C(   0),
      { SIMDE_FLOAT64_C(  -964.14) } },
    { { SIMDE_FLOAT64_C(   621.68), SIMDE_FLOAT64_C(   488.00) },
       INT8_C(   0),
      { SIMDE_FLOAT64_C(   621.68) } },
    { { SIMDE_FLOAT64_C(   950.70), SIMDE_FLOAT64_C(  -572.96) },
       INT8_C(   1),
      { SIMDE_FLOAT64_C(  -572.96) } },
    { { SIMDE_FLOAT64_C(   188.34), SIMDE_FLOAT64_C(  -751.64) },
       INT8_C(   1),
      { SIMDE_FLOAT64_C(  -751.64) } },
    { { SIMDE_FLOAT64_C(    97.41), SIMDE_FLOAT64_C(  -734.30) },
       INT8_C(   1),
      { SIMDE_FLOAT64_C(  -734.30) } },
    { { SIMDE_FLOAT64_C(   499.67), SIMDE_FLOAT64_C(  -413.57) },
       INT8_C(   1),
      { SIMDE_FLOAT64_C(  -413.57) } },
    { { SIMDE_FLOAT64_C(   766.87), SIMDE_FLOAT64_C(   -42.42) },
       INT8_C(   0),
      { SIMDE_FLOAT64_C(   766.87) } },
    { { SIMDE_FLOAT64_C(  -881.52), SIMDE_FLOAT64_C(  -131.16) },
       INT8_C(   1),
      { SIMDE_FLOAT64_C(  -131.16) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2_t vec;
    simde_float64x1_t r;

    vec = simde_vld1q_f64(test_vec[i].vec);
    SIMDE_CONSTIFY_2_(simde_vdup_laneq_f64, r, (HEDLEY_UNREACHABLE(), simde_vdup_n_f64(0.0)), test_vec[i].lane, vec);

    simde_test_arm_neon_assert_equal_f64x1(r, simde_vld1_f64(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x2_t vec = simde_test_arm_neon_random_f64x2(-1000.0, 1000.0);
    int lane = simde_test_codegen_random_i8() & 1;

    simde_float64x1_t r;
    SIMDE_CONSTIFY_2_(simde_vdup_laneq_f64, r, (HEDLEY_UNREACHABLE(), simde_vdup_n_f64(0.0)), lane, vec);

    simde_test_arm_neon_write_f64x2(2, vec, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i8(2, HEDLEY_STATIC_CAST(int8_t, lane), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vdup_laneq_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int8_t vec[16];
    int lane;
    int8_t r[8];
  } test_vec[] = {
    { { -INT8_C( 122), -INT8_C(  99), -INT8_C(  68), -INT8_C(  72),  INT8_C( 111),  INT8_C( 103), -INT8_C(  37), -INT8_C(  99),
        -INT8_C(  22),  INT8_C(  69),  INT8_C( 111), -INT8_C(  94),  INT8_C(  15), -INT8_C(  65), -INT8_C(  92),  INT8_C(  54) },
       INT8_C(   8),
      { -INT8_C(  22), -INT8_C(  22), -INT8_C(  22), -INT8_C(  22), -INT8_C(  22), -INT8_C(  22), -INT8_C(  22), -INT8_C(  22) } },
    { { -INT8_C(  44), -INT8_C(  29),  INT8_C(  30),  INT8_C(  24), -INT8_C(  11), -INT8_C( 121), -INT8_C( 123), -INT8_C(  35),
         INT8_C( 114), -INT8_C( 117),  INT8_C(  12),  INT8_C(  84),  INT8_C(  67),  INT8_C(  69), -INT8_C(  38), -INT8_C(  32) },
       INT8_C(   1),
      { -INT8_C(  29), -INT8_C(  29), -INT8_C(  29), -INT8_C(  29), -INT8_C(  29), -INT8_C(  29), -INT8_C(  29), -INT8_C(  29) } },
    { { -INT8_C( 109),  INT8_C(  79),  INT8_C( 104),  INT8_C( 110), -INT8_C(  20),  INT8_C(  82), -INT8_C(  77),  INT8_C(  91),
        -INT8_C(  11), -INT8_C(  61),  INT8_C(  27), -INT8_C( 103), -INT8_C(   7),  INT8_C(  51),  INT8_C( 109), -INT8_C(  36) },
       INT8_C(   1),
      {  INT8_C(  79),  INT8_C(  79),  INT8_C(  79),  INT8_C(  79),  INT8_C(  79),  INT8_C(  79),  INT8_C(  79),  INT8_C(  79) } },
    { { -INT8_C( 122), -INT8_C(  46), -INT8_C(  40),  INT8_C(  11), -INT8_C(  81),  INT8_C(  74), -INT8_C( 105), -INT8_C(  69),
        -INT8_C(  98), -INT8_C(  38),  INT8_C(   0),  INT8_C( 121), -INT8_C(  69),  INT8_C(   1),  INT8_C(  12),  INT8_C(  10) },
       INT8_C(   9),
      { -INT8_C(  38), -INT8_C(  38), -INT8_C(  38), -INT8_C(  38), -INT8_C(  38), -INT8_C(  38), -INT8_C(  38), -INT8_C(  38) } },
    { {  INT8_C( 122), -INT8_C(   9), -INT8_C(  68),  INT8_C(  46),  INT8_C(  82), -INT8_C(  79), -INT8_C(  15),  INT8_C( 109),
         INT8_C(  74), -INT8_C(  22), -INT8_C(  95), -INT8_C(  73), -INT8_C(  57), -INT8_C(  14),  INT8_C(  61), -INT8_C( 103) },
       INT8_C(  11),
      { -INT8_C(  73), -INT8_C(  73), -INT8_C(  73), -INT8_C(  73), -INT8_C(  73), -INT8_C(  73), -INT8_C(  73), -INT8_C(  73) } },
    { {  INT8_C(  73),  INT8_C(  72),  INT8_C(  21), -INT8_C(  32),  INT8_C(   3), -INT8_C(  76), -INT8_C(  70),  INT8_C(   4),
         INT8_C(  45),  INT8_C( 117),  INT8_C(   5),  INT8_C(  57),      INT8_MIN,  INT8_C( 111), -INT8_C(  77),  INT8_C( 119) },
       INT8_C(  11),
      {  INT8_C(  57),  INT8_C(  57),  INT8_C(  57),  INT8_C(  57),  INT8_C(  57),  INT8_C(  57),  INT8_C(  57),  INT8_C(  57) } },
    { { -INT8_C(  31), -INT8_C(  55), -INT8_C(  36), -INT8_C(  46),  INT8_C(  55),  INT8_C(  38), -INT8_C(  67), -INT8_C(  40),
        -INT8_C(  35), -INT8_C( 124), -INT8_C(  54),  INT8_C(  27),  INT8_C(  29), -INT8_C( 107),  INT8_C( 100),  INT8_C( 101) },
       INT8_C(  11),
      {  INT8_C(  27),  INT8_C(  27),  INT8_C(  27),  INT8_C(  27),  INT8_C(  27),  INT8_C(  27),  INT8_C(  27),  INT8_C(  27) } },
    { {  INT8_C(  68),  INT8_C( 104),  INT8_C(  95), -INT8_C(   2),  INT8_C( 108), -INT8_C( 116),  INT8_C( 116),  INT8_C( 114),
        -INT8_C(  59), -INT8_C(  12), -INT8_C(  31),  INT8_C( 120),  INT8_C( 107),  INT8_C(  12),  INT8_C(  90),  INT8_C(  52) },
       INT8_C(   8),
      { -INT8_C(  59), -INT8_C(  59), -INT8_C(  59), -INT8_C(  59), -INT8_C(  59), -INT8_C(  59), -INT8_C(  59), -INT8_C(  59) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16_t vec;
    simde_int8x8_t r;

    vec = simde_vld1q_s8(test_vec[i].vec);
    SIMDE_CONSTIFY_16_(simde_vdup_laneq_s8, r, (HEDLEY_UNREACHABLE(), simde_vdup_n_s8(INT8_C(0))), test_vec[i].lane, vec);

    simde_test_arm_neon_assert_equal_i8x8(r, simde_vld1_s8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x16_t vec = simde_test_arm_neon_random_i8x16();
    int lane = simde_test_codegen_random_i8() & 15;

    simde_int8x8_t r;
    SIMDE_CONSTIFY_16_(simde_vdup_laneq_s8, r, (HEDLEY_UNREACHABLE(), simde_vdup_n_s8(INT8_C(0))), lane, vec);

    simde_test_arm_neon_write_i8x16(2, vec, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i8(2, HEDLEY_STATIC_CAST(int8_t, lane), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vdup_laneq_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int16_t vec[8];
    int lane;
    int16_t r[4];
  } test_vec[] = {
    { {  INT16_C( 23653), -INT16_C( 16842), -INT16_C( 10435), -INT16_C( 21176),  INT16_C( 15511), -INT16_C( 31969),  INT16_C(  1229),  INT16_C( 13269) },
       INT8_C(   7),
      {  INT16_C( 13269),  INT16_C( 13269),  INT16_C( 13269),  INT16_C( 13269) } },
    { { -INT16_C( 16631), -INT16_C(   285),  INT16_C(  1669),  INT16_C(  6286), -INT16_C( 11777), -INT16_C( 29100), -INT16_C(  1421), -INT16_C( 12045) },
       INT8_C(   0),
      { -INT16_C( 16631), -INT16_C( 16631), -INT16_C( 16631), -INT16_C( 16631) } },
    { {  INT16_C(  3506), -INT16_C(  1528), -INT16_C( 24645), -INT16_C(  9674),  INT16_C(   802), -INT16_C(  2081),  INT16_C(  3638), -INT16_C(  2560) },
       INT8_C(   1),
      { -INT16_C(  1528), -INT16_C(  1528), -INT16_C(  1528), -INT16_C(  1528) } },
    { {  INT16_C( 31742), -INT16_C( 29449), -INT16_C(  2413), -INT16_C(  6051), -INT16_C( 11899),  INT16_C( 30946),  INT16_C(  4769), -INT16_C( 20950) },
       INT8_C(   2),
      { -INT16_C(  2413), -INT16_C(  2413), -INT16_C(  2413), -INT16_C(  2413) } },
    { {  INT16_C( 26917),  INT16_C( 23481), -INT16_C(  9404),  INT16_C(  9055), -INT16_C( 27182), -INT16_C( 11727),  INT16_C(  9099),  INT16_C(  1744) },
       INT8_C(   2),
      { -INT16_C(  9404), -INT16_C(  9404), -INT16_C(  9404), -INT16_C(  9404) } },
    { { -INT16_C( 26019), -INT16_C( 17903), -INT16_C( 27006),  INT16_C( 25739),  INT16_C( 11278),  INT16_C( 14710), -INT16_C( 28197),  INT16_C( 17502) },
       INT8_C(   2),
      { -INT16_C( 27006), -INT16_C( 27006), -INT16_C( 27006), -INT16_C( 27006) } },
    { { -INT16_C( 30535),  INT16_C(  6182), -INT16_C(  1877), -INT16_C(  8786),  INT16_C( 14795), -INT16_C( 25856),  INT16_C(  6720), -INT16_C(  9480) },
       INT8_C(   3),
      { -INT16_C(  8786), -INT16_C(  8786), -INT16_C(  8786), -INT16_C(  8786) } },
    { {  INT16_C( 23731),  INT16_C( 16065), -INT16_C( 12096),  INT16_C( 13931),  INT16_C( 17929),  INT16_C( 26567),  INT16_C(  4746),  INT16_C(  4896) },
       INT8_C(   0),
      {  INT16_C( 23731),  INT16_C( 23731),  INT16_C( 23731),  INT16_C( 23731) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t vec;
    simde_int16x4_t r;

    vec = simde_vld1q_s16(test_vec[i].vec);
    SIMDE_CONSTIFY_8_(simde_vdup_laneq_s16, r, (HEDLEY_UNREACHABLE(), simde_vdup_n_s16(INT16_C(0))), test_vec[i].lane, vec);

    simde_test_arm_neon_assert_equal_i16x4(r, simde_vld1_s16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x8_t vec = simde_test_arm_neon_random_i16x8();
    int lane = simde_test_codegen_random_i8() & 7;

    simde_int16x4_t r;
    SIMDE_CONSTIFY_8_(simde_vdup_laneq_s16, r, (HEDLEY_UNREACHABLE(), simde_vdup_n_s16(INT8_C(0))), lane, vec);

    simde_test_arm_neon_write_i16x8(2, vec, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i8(2, HEDLEY_STATIC_CAST(int8_t, lane), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vdup_laneq_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int32_t vec[4];
    int lane;
    int32_t r[2];
  } test_vec[] = {
    { { -INT32_C(   416235975), -INT32_C(  1692337253), -INT32_C(  1883873129), -INT32_C(  1774001862) },
       INT8_C(   3),
      { -INT32_C(  1774001862), -INT32_C(  1774001862) } },
    { { -INT32_C(   327985535),  INT32_C(  1412594829),  INT32_C(    57064675), -INT32_C(  1908629809) },
       INT8_C(   3),
      { -INT32_C(  1908629809), -INT32_C(  1908629809) } },
    { {  INT32_C(  1154099491),  INT32_C(  2074370501),  INT32_C(   861724657), -INT32_C(   860553355) },
       INT8_C(   2),
      {  INT32_C(   861724657),  INT32_C(   861724657) } },
    { { -INT32_C(   756131424),  INT32_C(   344969645),  INT32_C(   296902357),  INT32_C(   372605420) },
       INT8_C(   0),
      { -INT32_C(   756131424), -INT32_C(   756131424) } },
    { {  INT32_C(   497933177), -INT32_C(  1292067242), -INT32_C(  2035125550), -INT32_C(  1759042498) },
       INT8_C(   3),
      { -INT32_C(  1759042498), -INT32_C(  1759042498) } },
    { { -INT32_C(  1998306055),  INT32_C(   199735640),  INT32_C(     9229259), -INT32_C(   998647575) },
       INT8_C(   2),
      {  INT32_C(     9229259),  INT32_C(     9229259) } },
    { { -INT32_C(  1826350442),  INT32_C(  2131097293), -INT32_C(  1532804227),  INT32_C(   513652442) },
       INT8_C(   3),
      {  INT32_C(   513652442),  INT32_C(   513652442) } },
    { {  INT32_C(   223639334),  INT32_C(   249569154), -INT32_C(  1729639905), -INT32_C(  1456509554) },
       INT8_C(   1),
      {  INT32_C(   249569154),  INT32_C(   249569154) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t vec;
    simde_int32x2_t r;

    vec = simde_vld1q_s32(test_vec[i].vec);
    SIMDE_CONSTIFY_4_(simde_vdup_laneq_s32, r, (HEDLEY_UNREACHABLE(), simde_vdup_n_s32(INT32_C(0))), test_vec[i].lane, vec);

    simde_test_arm_neon_assert_equal_i32x2(r, simde_vld1_s32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x4_t vec = simde_test_arm_neon_random_i32x4();
    int lane = simde_test_codegen_random_i8() & 3;

    simde_int32x2_t r;
    SIMDE_CONSTIFY_4_(simde_vdup_laneq_s32, r, (HEDLEY_UNREACHABLE(), simde_vdup_n_s32(INT32_C(0))), lane, vec);

    simde_test_arm_neon_write_i32x4(2, vec, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i8(2, HEDLEY_STATIC_CAST(int8_t, lane), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vdup_laneq_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int64_t vec[2];
    int lane;
    int64_t r[1];
  } test_vec[] = {
    { { -INT64_C( 4867007410252740494),  INT64_C( 6650439126861753290) },
       INT8_C(   0),
      { -INT64_C( 4867007410252740494) } },
    { {  INT64_C( 6951225055928169884),  INT64_C(   68363202768986995) },
       INT8_C(   1),
      {  INT64_C(   68363202768986995) } },
    { {  INT64_C( 4436684764484439282), -INT64_C( 3843432968721221438) },
       INT8_C(   0),
      {  INT64_C( 4436684764484439282) } },
    { {  INT64_C( 5042043137711416734),  INT64_C( 9031044296322969711) },
       INT8_C(   1),
      {  INT64_C( 9031044296322969711) } },
    { {  INT64_C( 6558710019170682555),  INT64_C(  688351337355483718) },
       INT8_C(   1),
      {  INT64_C(  688351337355483718) } },
    { { -INT64_C(  536951092128346461), -INT64_C( 4625794981386355522) },
       INT8_C(   0),
      { -INT64_C(  536951092128346461) } },
    { { -INT64_C( 2721629803226676710), -INT64_C( 5335538334588657980) },
       INT8_C(   0),
      { -INT64_C( 2721629803226676710) } },
    { {  INT64_C( 3429603820960188560),  INT64_C( 1468284878264963704) },
       INT8_C(   1),
      {  INT64_C( 1468284878264963704) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t vec;
    simde_int64x1_t r;

    vec = simde_vld1q_s64(test_vec[i].vec);
    SIMDE_CONSTIFY_2_(simde_vdup_laneq_s64, r, (HEDLEY_UNREACHABLE(), simde_vdup_n_s64(INT64_C(0))), test_vec[i].lane, vec);

    simde_test_arm_neon_assert_equal_i64x1(r, simde_vld1_s64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int64x2_t vec = simde_test_arm_neon_random_i64x2();
    int lane = simde_test_codegen_random_i8() & 1;

    simde_int64x1_t r;
    SIMDE_CONSTIFY_2_(simde_vdup_laneq_s64, r, (HEDLEY_UNREACHABLE(), simde_vdup_n_s64(INT64_C(0))), lane, vec);

    simde_test_arm_neon_write_i64x2(2, vec, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i8(2, HEDLEY_STATIC_CAST(int8_t, lane), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vdup_laneq_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint8_t vec[16];
    int lane;
    uint8_t r[8];
  } test_vec[] = {
    { { UINT8_C( 77), UINT8_C(147), UINT8_C( 62), UINT8_C(115), UINT8_C(118), UINT8_C( 11), UINT8_C( 79), UINT8_C(238),
        UINT8_C(216), UINT8_C( 18), UINT8_C(104), UINT8_C(180), UINT8_C(173), UINT8_C(197), UINT8_C(248), UINT8_C(124) },
      UINT8_C( 15),
      { UINT8_C(124), UINT8_C(124), UINT8_C(124), UINT8_C(124), UINT8_C(124), UINT8_C(124), UINT8_C(124), UINT8_C(124) } },
    { { UINT8_C(115), UINT8_C(176), UINT8_C(  5), UINT8_C(172), UINT8_C(204), UINT8_C(177), UINT8_C(208), UINT8_C(120),
        UINT8_C(189), UINT8_C( 77), UINT8_C(208), UINT8_C( 85), UINT8_C( 21), UINT8_C( 46), UINT8_C(162), UINT8_C(168) },
      UINT8_C( 12),
      { UINT8_C( 21), UINT8_C( 21), UINT8_C( 21), UINT8_C( 21), UINT8_C( 21), UINT8_C( 21), UINT8_C( 21), UINT8_C( 21) } },
    { { UINT8_C( 22), UINT8_C( 30), UINT8_C(119), UINT8_C(101), UINT8_C( 12), UINT8_C( 79), UINT8_C(119), UINT8_C(116),
        UINT8_C(  4), UINT8_C( 37), UINT8_C( 57), UINT8_C(252), UINT8_C(161), UINT8_C(233), UINT8_C(111), UINT8_C( 81) },
      UINT8_C( 14),
      { UINT8_C(111), UINT8_C(111), UINT8_C(111), UINT8_C(111), UINT8_C(111), UINT8_C(111), UINT8_C(111), UINT8_C(111) } },
    { { UINT8_C( 28), UINT8_C( 30), UINT8_C(159), UINT8_C(236), UINT8_C(150), UINT8_C( 93), UINT8_C( 57), UINT8_C(102),
        UINT8_C(178), UINT8_C( 79), UINT8_C(148), UINT8_C( 85), UINT8_C(247), UINT8_C(  0), UINT8_C(107), UINT8_C( 22) },
      UINT8_C(  7),
      { UINT8_C(102), UINT8_C(102), UINT8_C(102), UINT8_C(102), UINT8_C(102), UINT8_C(102), UINT8_C(102), UINT8_C(102) } },
    { { UINT8_C(208), UINT8_C( 34), UINT8_C(199), UINT8_C( 72), UINT8_C(151), UINT8_C(203), UINT8_C(109), UINT8_C(208),
        UINT8_C(199), UINT8_C( 14), UINT8_C(185), UINT8_C( 55), UINT8_C( 96), UINT8_C(167), UINT8_C( 83), UINT8_C(126) },
      UINT8_C(  7),
      { UINT8_C(208), UINT8_C(208), UINT8_C(208), UINT8_C(208), UINT8_C(208), UINT8_C(208), UINT8_C(208), UINT8_C(208) } },
    { { UINT8_C( 63), UINT8_C( 20), UINT8_C(164), UINT8_C(120), UINT8_C(122), UINT8_C( 86), UINT8_C(199), UINT8_C( 14),
        UINT8_C(171), UINT8_C(191), UINT8_C( 14), UINT8_C( 22), UINT8_C(213), UINT8_C(133), UINT8_C(231), UINT8_C(247) },
      UINT8_C( 12),
      { UINT8_C(213), UINT8_C(213), UINT8_C(213), UINT8_C(213), UINT8_C(213), UINT8_C(213), UINT8_C(213), UINT8_C(213) } },
    { { UINT8_C( 47), UINT8_C(142), UINT8_C( 23), UINT8_C(156), UINT8_C( 95), UINT8_C(223), UINT8_C(170), UINT8_C( 24),
        UINT8_C( 22), UINT8_C( 10), UINT8_C(192), UINT8_C(105), UINT8_C(136), UINT8_C(  7), UINT8_C(168), UINT8_C(156) },
      UINT8_C( 11),
      { UINT8_C(105), UINT8_C(105), UINT8_C(105), UINT8_C(105), UINT8_C(105), UINT8_C(105), UINT8_C(105), UINT8_C(105) } },
    { { UINT8_C( 32), UINT8_C( 22), UINT8_C(  1), UINT8_C(232), UINT8_C( 36), UINT8_C(173), UINT8_C(167), UINT8_C( 50),
        UINT8_C(195), UINT8_C(124), UINT8_C(184), UINT8_C(170), UINT8_C(115), UINT8_C(  4), UINT8_C(217), UINT8_C(  2) },
      UINT8_C( 12),
      { UINT8_C(115), UINT8_C(115), UINT8_C(115), UINT8_C(115), UINT8_C(115), UINT8_C(115), UINT8_C(115), UINT8_C(115) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x16_t vec;
    simde_uint8x8_t r;

    vec = simde_vld1q_u8(test_vec[i].vec);
    SIMDE_CONSTIFY_16_(simde_vdup_laneq_u8, r, (HEDLEY_UNREACHABLE(), simde_vdup_n_u8(UINT8_C(0))), test_vec[i].lane, vec);

    simde_test_arm_neon_assert_equal_u8x8(r, simde_vld1_u8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8x16_t vec = simde_test_arm_neon_random_u8x16();
    int lane = simde_test_codegen_random_u8() & 15;

    simde_uint8x8_t r;
    SIMDE_CONSTIFY_16_(simde_vdup_laneq_u8, r, (HEDLEY_UNREACHABLE(), simde_vdup_n_u8(UINT8_C(0))), lane, vec);

    simde_test_arm_neon_write_u8x16(2, vec, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u8(2, HEDLEY_STATIC_CAST(uint8_t, lane), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vdup_laneq_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint16_t vec[8];
    int lane;
    uint16_t r[4];
  } test_vec[] = {
    { { UINT16_C(24949), UINT16_C( 8443), UINT16_C( 4473), UINT16_C(14634), UINT16_C(45946), UINT16_C( 8768), UINT16_C(60239), UINT16_C(26178) },
      UINT8_C(  5),
      { UINT16_C( 8768), UINT16_C( 8768), UINT16_C( 8768), UINT16_C( 8768) } },
    { { UINT16_C(35370), UINT16_C(53658), UINT16_C(23997), UINT16_C(30029), UINT16_C(49416), UINT16_C(57721), UINT16_C(38339), UINT16_C( 9303) },
      UINT8_C(  0),
      { UINT16_C(35370), UINT16_C(35370), UINT16_C(35370), UINT16_C(35370) } },
    { { UINT16_C(40311), UINT16_C(41377), UINT16_C( 7127), UINT16_C( 5972), UINT16_C(42045), UINT16_C(32771), UINT16_C(61450), UINT16_C(38058) },
      UINT8_C(  2),
      { UINT16_C( 7127), UINT16_C( 7127), UINT16_C( 7127), UINT16_C( 7127) } },
    { { UINT16_C(20860), UINT16_C(51687), UINT16_C(61382), UINT16_C(16522), UINT16_C(19921), UINT16_C(10453), UINT16_C(26225), UINT16_C( 3999) },
      UINT8_C(  7),
      { UINT16_C( 3999), UINT16_C( 3999), UINT16_C( 3999), UINT16_C( 3999) } },
    { { UINT16_C(58944), UINT16_C(38179), UINT16_C(24829), UINT16_C(   57), UINT16_C(17376), UINT16_C(35824), UINT16_C(31447), UINT16_C(10503) },
      UINT8_C(  2),
      { UINT16_C(24829), UINT16_C(24829), UINT16_C(24829), UINT16_C(24829) } },
    { { UINT16_C(61392), UINT16_C(23377), UINT16_C( 8751), UINT16_C( 1448), UINT16_C( 6730), UINT16_C(59755), UINT16_C(29225), UINT16_C( 3882) },
      UINT8_C(  5),
      { UINT16_C(59755), UINT16_C(59755), UINT16_C(59755), UINT16_C(59755) } },
    { { UINT16_C( 3263), UINT16_C(63734), UINT16_C(54797), UINT16_C(64827), UINT16_C( 4705), UINT16_C(26744), UINT16_C(55867), UINT16_C(11065) },
      UINT8_C(  3),
      { UINT16_C(64827), UINT16_C(64827), UINT16_C(64827), UINT16_C(64827) } },
    { { UINT16_C(23188), UINT16_C(15438), UINT16_C(39007), UINT16_C(51798), UINT16_C(32642), UINT16_C(44093), UINT16_C(53902), UINT16_C(39787) },
      UINT8_C(  0),
      { UINT16_C(23188), UINT16_C(23188), UINT16_C(23188), UINT16_C(23188) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t vec;
    simde_uint16x4_t r;

    vec = simde_vld1q_u16(test_vec[i].vec);
    SIMDE_CONSTIFY_8_(simde_vdup_laneq_u16, r, (HEDLEY_UNREACHABLE(), simde_vdup_n_u16(UINT16_C(0))), test_vec[i].lane, vec);

    simde_test_arm_neon_assert_equal_u16x4(r, simde_vld1_u16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x8_t vec = simde_test_arm_neon_random_u16x8();
    int lane = simde_test_codegen_random_u8() & 7;

    simde_uint16x4_t r;
    SIMDE_CONSTIFY_8_(simde_vdup_laneq_u16, r, (HEDLEY_UNREACHABLE(), simde_vdup_n_u16(UINT16_C(0))), lane, vec);

    simde_test_arm_neon_write_u16x8(2, vec, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u8(2, HEDLEY_STATIC_CAST(uint8_t, lane), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vdup_laneq_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint32_t vec[8];
    int lane;
    uint32_t r[2];
  } test_vec[] = {
    { { UINT32_C(2661263459), UINT32_C( 498073765), UINT32_C(2734156905), UINT32_C(1899373335) },
      UINT8_C(  1),
      { UINT32_C( 498073765), UINT32_C( 498073765) } },
    { { UINT32_C(3372863858), UINT32_C(3628632987), UINT32_C(2729170743), UINT32_C( 436564850) },
      UINT8_C(  2),
      { UINT32_C(2729170743), UINT32_C(2729170743) } },
    { { UINT32_C(1410580387), UINT32_C(3560996061), UINT32_C(1425495838), UINT32_C(2579917000) },
      UINT8_C(  2),
      { UINT32_C(1425495838), UINT32_C(1425495838) } },
    { { UINT32_C(3640472975), UINT32_C(3098490125), UINT32_C(3710656983), UINT32_C(4202708539) },
      UINT8_C(  1),
      { UINT32_C(3098490125), UINT32_C(3098490125) } },
    { { UINT32_C( 349034452), UINT32_C(2741758892), UINT32_C( 101463103), UINT32_C(  43351757) },
      UINT8_C(  3),
      { UINT32_C(  43351757), UINT32_C(  43351757) } },
    { { UINT32_C( 481300589), UINT32_C(4097673416), UINT32_C(3845355621), UINT32_C(1253737587) },
      UINT8_C(  2),
      { UINT32_C(3845355621), UINT32_C(3845355621) } },
    { { UINT32_C( 977139406), UINT32_C(2792258970), UINT32_C( 405027715), UINT32_C(1317445438) },
      UINT8_C(  0),
      { UINT32_C( 977139406), UINT32_C( 977139406) } },
    { { UINT32_C(3772257954), UINT32_C(1045970187), UINT32_C(3703753506), UINT32_C( 212538390) },
      UINT8_C(  2),
      { UINT32_C(3703753506), UINT32_C(3703753506) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t vec;
    simde_uint32x2_t r;

    vec = simde_vld1q_u32(test_vec[i].vec);
    SIMDE_CONSTIFY_4_(simde_vdup_laneq_u32, r, (HEDLEY_UNREACHABLE(), simde_vdup_n_u32(UINT32_C(0))), test_vec[i].lane, vec);

    simde_test_arm_neon_assert_equal_u32x2(r, simde_vld1_u32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x4_t vec = simde_test_arm_neon_random_u32x4();
    int lane = simde_test_codegen_random_u8() & 3;

    simde_uint32x2_t r;
    SIMDE_CONSTIFY_4_(simde_vdup_laneq_u32, r, (HEDLEY_UNREACHABLE(), simde_vdup_n_u32(UINT32_C(0))), lane, vec);

    simde_test_arm_neon_write_u32x4(2, vec, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u8(2, HEDLEY_STATIC_CAST(uint8_t, lane), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vdup_laneq_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint64_t vec[2];
    int lane;
    uint64_t r[1];
  } test_vec[] = {
    { { UINT64_C( 8110510466717951717), UINT64_C( 3572304598247984234) },
      UINT8_C(  0),
      { UINT64_C( 8110510466717951717) } },
    { { UINT64_C( 4366124917414247539), UINT64_C( 6918834943037648244) },
      UINT8_C(  0),
      { UINT64_C( 4366124917414247539) } },
    { { UINT64_C( 3292744983505054807), UINT64_C( 4117915127713221663) },
      UINT8_C(  0),
      { UINT64_C( 3292744983505054807) } },
    { { UINT64_C( 4698457210627404784), UINT64_C(18068255124800990820) },
      UINT8_C(  0),
      { UINT64_C( 4698457210627404784) } },
    { { UINT64_C(15070002321331591077), UINT64_C( 1022264726452052249) },
      UINT8_C(  0),
      { UINT64_C(15070002321331591077) } },
    { { UINT64_C( 2583179698698190518), UINT64_C( 4114481506476959668) },
      UINT8_C(  1),
      { UINT64_C( 4114481506476959668) } },
    { { UINT64_C(16551956027336260976), UINT64_C( 1981680721021243291) },
      UINT8_C(  1),
      { UINT64_C( 1981680721021243291) } },
    { { UINT64_C(17756356862603385451), UINT64_C( 4845139579135167924) },
      UINT8_C(  1),
      { UINT64_C( 4845139579135167924) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x2_t vec;
    simde_uint64x1_t r;

    vec = simde_vld1q_u64(test_vec[i].vec);
    SIMDE_CONSTIFY_2_(simde_vdup_laneq_u64, r, (HEDLEY_UNREACHABLE(), simde_vdup_n_u64(UINT64_C(0))), test_vec[i].lane, vec);

    simde_test_arm_neon_assert_equal_u64x1(r, simde_vld1_u64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint64x2_t vec = simde_test_arm_neon_random_u64x2();
    int lane = simde_test_codegen_random_u8() & 1;

    simde_uint64x1_t r;
    SIMDE_CONSTIFY_2_(simde_vdup_laneq_u64, r, (HEDLEY_UNREACHABLE(), simde_vdup_n_u64(UINT64_C(0))), lane, vec);

    simde_test_arm_neon_write_u64x2(2, vec, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u8(2, HEDLEY_STATIC_CAST(uint8_t, lane), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vdupq_lane_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float32 vec[2];
    int lane;
    simde_float32 r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   870.88), SIMDE_FLOAT32_C(    24.01) },
       INT8_C(   0),
      { SIMDE_FLOAT32_C(   870.88), SIMDE_FLOAT32_C(   870.88), SIMDE_FLOAT32_C(   870.88), SIMDE_FLOAT32_C(   870.88) } },
    { { SIMDE_FLOAT32_C(   113.79), SIMDE_FLOAT32_C(  -108.45) },
       INT8_C(   1),
      { SIMDE_FLOAT32_C(  -108.45), SIMDE_FLOAT32_C(  -108.45), SIMDE_FLOAT32_C(  -108.45), SIMDE_FLOAT32_C(  -108.45) } },
    { { SIMDE_FLOAT32_C(   134.60), SIMDE_FLOAT32_C(  -240.11) },
       INT8_C(   1),
      { SIMDE_FLOAT32_C(  -240.11), SIMDE_FLOAT32_C(  -240.11), SIMDE_FLOAT32_C(  -240.11), SIMDE_FLOAT32_C(  -240.11) } },
    { { SIMDE_FLOAT32_C(   494.89), SIMDE_FLOAT32_C(  -490.91) },
       INT8_C(   0),
      { SIMDE_FLOAT32_C(   494.89), SIMDE_FLOAT32_C(   494.89), SIMDE_FLOAT32_C(   494.89), SIMDE_FLOAT32_C(   494.89) } },
    { { SIMDE_FLOAT32_C(  -252.90), SIMDE_FLOAT32_C(  -790.94) },
       INT8_C(   1),
      { SIMDE_FLOAT32_C(  -790.94), SIMDE_FLOAT32_C(  -790.94), SIMDE_FLOAT32_C(  -790.94), SIMDE_FLOAT32_C(  -790.94) } },
    { { SIMDE_FLOAT32_C(   232.02), SIMDE_FLOAT32_C(  -102.81) },
       INT8_C(   0),
      { SIMDE_FLOAT32_C(   232.02), SIMDE_FLOAT32_C(   232.02), SIMDE_FLOAT32_C(   232.02), SIMDE_FLOAT32_C(   232.02) } },
    { { SIMDE_FLOAT32_C(   759.52), SIMDE_FLOAT32_C(   383.73) },
       INT8_C(   0),
      { SIMDE_FLOAT32_C(   759.52), SIMDE_FLOAT32_C(   759.52), SIMDE_FLOAT32_C(   759.52), SIMDE_FLOAT32_C(   759.52) } },
    { { SIMDE_FLOAT32_C(  -169.79), SIMDE_FLOAT32_C(  -403.21) },
       INT8_C(   1),
      { SIMDE_FLOAT32_C(  -403.21), SIMDE_FLOAT32_C(  -403.21), SIMDE_FLOAT32_C(  -403.21), SIMDE_FLOAT32_C(  -403.21) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t vec;
    simde_float32x4_t r;

    vec = simde_vld1_f32(test_vec[i].vec);
    SIMDE_CONSTIFY_2_(simde_vdupq_lane_f32, r, (HEDLEY_UNREACHABLE(), simde_vdupq_n_f32(0.0f)), test_vec[i].lane, vec);

    simde_test_arm_neon_assert_equal_f32x4(r, simde_vld1q_f32(test_vec[i].r), 1);
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x2_t vec = simde_test_arm_neon_random_f32x2(-1000.0, 1000.0);
    int lane = simde_test_codegen_random_i8() & 1;

    simde_float32x4_t r;
    SIMDE_CONSTIFY_4_(simde_vdupq_lane_f32, r, (HEDLEY_UNREACHABLE(), simde_vdupq_n_f32(0.0f)), lane, vec);

    simde_test_arm_neon_write_f32x2(2, vec, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i8(2, HEDLEY_STATIC_CAST(int8_t, lane), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vdupq_lane_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float64 vec[1];
    int lane;
    simde_float64 r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(    23.83) },
       INT8_C(   0),
      { SIMDE_FLOAT64_C(    23.83), SIMDE_FLOAT64_C(    23.83) } },
    { { SIMDE_FLOAT64_C(   360.45) },
       INT8_C(   0),
      { SIMDE_FLOAT64_C(   360.45), SIMDE_FLOAT64_C(   360.45) } },
    { { SIMDE_FLOAT64_C(  -969.45) },
       INT8_C(   0),
      { SIMDE_FLOAT64_C(  -969.45), SIMDE_FLOAT64_C(  -969.45) } },
    { { SIMDE_FLOAT64_C(   206.91) },
       INT8_C(   0),
      { SIMDE_FLOAT64_C(   206.91), SIMDE_FLOAT64_C(   206.91) } },
    { { SIMDE_FLOAT64_C(   953.07) },
       INT8_C(   0),
      { SIMDE_FLOAT64_C(   953.07), SIMDE_FLOAT64_C(   953.07) } },
    { { SIMDE_FLOAT64_C(  -531.18) },
       INT8_C(   0),
      { SIMDE_FLOAT64_C(  -531.18), SIMDE_FLOAT64_C(  -531.18) } },
    { { SIMDE_FLOAT64_C(    31.72) },
       INT8_C(   0),
      { SIMDE_FLOAT64_C(    31.72), SIMDE_FLOAT64_C(    31.72) } },
    { { SIMDE_FLOAT64_C(  -358.35) },
       INT8_C(   0),
      { SIMDE_FLOAT64_C(  -358.35), SIMDE_FLOAT64_C(  -358.35) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x1_t vec;
    simde_float64x2_t r;

    vec = simde_vld1_f64(test_vec[i].vec);
    r = simde_vdupq_lane_f64(vec, 0);

    simde_test_arm_neon_assert_equal_f64x2(r, simde_vld1q_f64(test_vec[i].r), 1);
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x1_t vec = simde_test_arm_neon_random_f64x1(-1000.0, 1000.0);
    int lane = 0;

    simde_float64x2_t r = simde_vdupq_lane_f64(vec, 0);

    simde_test_arm_neon_write_f64x1(2, vec, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i8(2, HEDLEY_STATIC_CAST(int8_t, lane), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vdupq_lane_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int8_t vec[8];
    int lane;
    int8_t r[16];
  } test_vec[] = {
    { {  INT8_C(  85),  INT8_C(  76),  INT8_C(  44),  INT8_C(  42), -INT8_C(  96),  INT8_C( 103), -INT8_C(  58), -INT8_C(   8) },
       INT8_C(   7),
      { -INT8_C(   8), -INT8_C(   8), -INT8_C(   8), -INT8_C(   8), -INT8_C(   8), -INT8_C(   8), -INT8_C(   8), -INT8_C(   8),
        -INT8_C(   8), -INT8_C(   8), -INT8_C(   8), -INT8_C(   8), -INT8_C(   8), -INT8_C(   8), -INT8_C(   8), -INT8_C(   8) } },
    { {  INT8_C(  32),  INT8_C(  37), -INT8_C( 119), -INT8_C(  87),  INT8_C( 110), -INT8_C(   5), -INT8_C(  29), -INT8_C(  61) },
       INT8_C(   3),
      { -INT8_C(  87), -INT8_C(  87), -INT8_C(  87), -INT8_C(  87), -INT8_C(  87), -INT8_C(  87), -INT8_C(  87), -INT8_C(  87),
        -INT8_C(  87), -INT8_C(  87), -INT8_C(  87), -INT8_C(  87), -INT8_C(  87), -INT8_C(  87), -INT8_C(  87), -INT8_C(  87) } },
    { { -INT8_C(   3),  INT8_C(  40), -INT8_C( 118), -INT8_C(   1),  INT8_C(  83),  INT8_C( 116), -INT8_C(  91),  INT8_C(  19) },
       INT8_C(   6),
      { -INT8_C(  91), -INT8_C(  91), -INT8_C(  91), -INT8_C(  91), -INT8_C(  91), -INT8_C(  91), -INT8_C(  91), -INT8_C(  91),
        -INT8_C(  91), -INT8_C(  91), -INT8_C(  91), -INT8_C(  91), -INT8_C(  91), -INT8_C(  91), -INT8_C(  91), -INT8_C(  91) } },
    { { -INT8_C(  45), -INT8_C( 109), -INT8_C( 106), -INT8_C(  18), -INT8_C(  24), -INT8_C(  30),  INT8_C(  26),  INT8_C(  19) },
       INT8_C(   2),
      { -INT8_C( 106), -INT8_C( 106), -INT8_C( 106), -INT8_C( 106), -INT8_C( 106), -INT8_C( 106), -INT8_C( 106), -INT8_C( 106),
        -INT8_C( 106), -INT8_C( 106), -INT8_C( 106), -INT8_C( 106), -INT8_C( 106), -INT8_C( 106), -INT8_C( 106), -INT8_C( 106) } },
    { { -INT8_C( 127), -INT8_C(  39),  INT8_C( 122),  INT8_C(   9), -INT8_C(   7), -INT8_C(  97), -INT8_C( 110), -INT8_C(  94) },
       INT8_C(   5),
      { -INT8_C(  97), -INT8_C(  97), -INT8_C(  97), -INT8_C(  97), -INT8_C(  97), -INT8_C(  97), -INT8_C(  97), -INT8_C(  97),
        -INT8_C(  97), -INT8_C(  97), -INT8_C(  97), -INT8_C(  97), -INT8_C(  97), -INT8_C(  97), -INT8_C(  97), -INT8_C(  97) } },
    { { -INT8_C( 115), -INT8_C( 122), -INT8_C(  48),  INT8_C(  89), -INT8_C( 125), -INT8_C(   8), -INT8_C(  29), -INT8_C( 126) },
       INT8_C(   4),
      { -INT8_C( 125), -INT8_C( 125), -INT8_C( 125), -INT8_C( 125), -INT8_C( 125), -INT8_C( 125), -INT8_C( 125), -INT8_C( 125),
        -INT8_C( 125), -INT8_C( 125), -INT8_C( 125), -INT8_C( 125), -INT8_C( 125), -INT8_C( 125), -INT8_C( 125), -INT8_C( 125) } },
    { {  INT8_C(  87),  INT8_C(  39),  INT8_C(  95), -INT8_C(  27), -INT8_C(   6), -INT8_C(  13),  INT8_C( 124), -INT8_C(  24) },
       INT8_C(   3),
      { -INT8_C(  27), -INT8_C(  27), -INT8_C(  27), -INT8_C(  27), -INT8_C(  27), -INT8_C(  27), -INT8_C(  27), -INT8_C(  27),
        -INT8_C(  27), -INT8_C(  27), -INT8_C(  27), -INT8_C(  27), -INT8_C(  27), -INT8_C(  27), -INT8_C(  27), -INT8_C(  27) } },
    { {  INT8_C(  94),  INT8_C(   2), -INT8_C(  18), -INT8_C(  31), -INT8_C( 124), -INT8_C(  56),  INT8_C(  91), -INT8_C( 115) },
       INT8_C(   1),
      {  INT8_C(   2),  INT8_C(   2),  INT8_C(   2),  INT8_C(   2),  INT8_C(   2),  INT8_C(   2),  INT8_C(   2),  INT8_C(   2),
         INT8_C(   2),  INT8_C(   2),  INT8_C(   2),  INT8_C(   2),  INT8_C(   2),  INT8_C(   2),  INT8_C(   2),  INT8_C(   2) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8_t vec;
    simde_int8x16_t r;

    vec = simde_vld1_s8(test_vec[i].vec);
    SIMDE_CONSTIFY_8_(simde_vdupq_lane_s8, r, (HEDLEY_UNREACHABLE(), simde_vdupq_n_s8(0)), test_vec[i].lane, vec);

    simde_test_arm_neon_assert_equal_i8x16(r, simde_vld1q_s8(test_vec[i].r));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x8_t vec = simde_test_arm_neon_random_i8x8();
    int lane = simde_test_codegen_random_i8() & 7;

    simde_int8x16_t r;
    SIMDE_CONSTIFY_8_(simde_vdupq_lane_s8, r, (HEDLEY_UNREACHABLE(), simde_vdupq_n_s8(0)), lane, vec);

    simde_test_arm_neon_write_i8x8(2, vec, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i8(2, HEDLEY_STATIC_CAST(int8_t, lane), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vdupq_lane_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int16_t vec[4];
    int lane;
    int16_t r[8];
  } test_vec[] = {
    { { -INT16_C( 16016), -INT16_C( 22782), -INT16_C( 28914),  INT16_C( 14087) },
       INT8_C(   1),
      { -INT16_C( 22782), -INT16_C( 22782), -INT16_C( 22782), -INT16_C( 22782), -INT16_C( 22782), -INT16_C( 22782), -INT16_C( 22782), -INT16_C( 22782) } },
    { { -INT16_C( 22047), -INT16_C(  6606), -INT16_C(  7386),  INT16_C( 14932) },
       INT8_C(   2),
      { -INT16_C(  7386), -INT16_C(  7386), -INT16_C(  7386), -INT16_C(  7386), -INT16_C(  7386), -INT16_C(  7386), -INT16_C(  7386), -INT16_C(  7386) } },
    { {  INT16_C(   135), -INT16_C(  7551),  INT16_C( 25436), -INT16_C( 28698) },
       INT8_C(   3),
      { -INT16_C( 28698), -INT16_C( 28698), -INT16_C( 28698), -INT16_C( 28698), -INT16_C( 28698), -INT16_C( 28698), -INT16_C( 28698), -INT16_C( 28698) } },
    { {  INT16_C( 12937), -INT16_C( 21229), -INT16_C( 11102),  INT16_C( 18863) },
       INT8_C(   3),
      {  INT16_C( 18863),  INT16_C( 18863),  INT16_C( 18863),  INT16_C( 18863),  INT16_C( 18863),  INT16_C( 18863),  INT16_C( 18863),  INT16_C( 18863) } },
    { {  INT16_C( 20543), -INT16_C( 21478), -INT16_C( 15566),  INT16_C(  6367) },
       INT8_C(   1),
      { -INT16_C( 21478), -INT16_C( 21478), -INT16_C( 21478), -INT16_C( 21478), -INT16_C( 21478), -INT16_C( 21478), -INT16_C( 21478), -INT16_C( 21478) } },
    { {  INT16_C( 28098), -INT16_C( 24541),  INT16_C(  9204), -INT16_C( 10718) },
       INT8_C(   0),
      {  INT16_C( 28098),  INT16_C( 28098),  INT16_C( 28098),  INT16_C( 28098),  INT16_C( 28098),  INT16_C( 28098),  INT16_C( 28098),  INT16_C( 28098) } },
    { { -INT16_C( 17275), -INT16_C(  6129),  INT16_C( 16709), -INT16_C(  3077) },
       INT8_C(   3),
      { -INT16_C(  3077), -INT16_C(  3077), -INT16_C(  3077), -INT16_C(  3077), -INT16_C(  3077), -INT16_C(  3077), -INT16_C(  3077), -INT16_C(  3077) } },
    { { -INT16_C( 23856), -INT16_C( 19667),  INT16_C( 32225), -INT16_C( 28979) },
       INT8_C(   3),
      { -INT16_C( 28979), -INT16_C( 28979), -INT16_C( 28979), -INT16_C( 28979), -INT16_C( 28979), -INT16_C( 28979), -INT16_C( 28979), -INT16_C( 28979) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t vec;
    simde_int16x8_t r;

    vec = simde_vld1_s16(test_vec[i].vec);
    SIMDE_CONSTIFY_4_(simde_vdupq_lane_s16, r, (HEDLEY_UNREACHABLE(), simde_vdupq_n_s16(0)), test_vec[i].lane, vec);

    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x4_t vec = simde_test_arm_neon_random_i16x4();
    int lane = simde_test_codegen_random_i8() & 3;

    simde_int16x8_t r;
    SIMDE_CONSTIFY_4_(simde_vdupq_lane_s16, r, (HEDLEY_UNREACHABLE(), simde_vdupq_n_s16(0)), lane, vec);

    simde_test_arm_neon_write_i16x4(2, vec, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i8(2, HEDLEY_STATIC_CAST(int8_t, lane), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vdupq_lane_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int32_t vec[2];
    int lane;
    int32_t r[4];
  } test_vec[] = {
    { { -INT32_C(   953972085),  INT32_C(  1755395340) },
       INT8_C(   1),
      {  INT32_C(  1755395340),  INT32_C(  1755395340),  INT32_C(  1755395340),  INT32_C(  1755395340) } },
    { {  INT32_C(   708800270),  INT32_C(   126272294) },
       INT8_C(   1),
      {  INT32_C(   126272294),  INT32_C(   126272294),  INT32_C(   126272294),  INT32_C(   126272294) } },
    { {  INT32_C(  1633721669), -INT32_C(   507959388) },
       INT8_C(   0),
      {  INT32_C(  1633721669),  INT32_C(  1633721669),  INT32_C(  1633721669),  INT32_C(  1633721669) } },
    { { -INT32_C(   637428407), -INT32_C(   251819223) },
       INT8_C(   0),
      { -INT32_C(   637428407), -INT32_C(   637428407), -INT32_C(   637428407), -INT32_C(   637428407) } },
    { { -INT32_C(  1946119885), -INT32_C(   909348961) },
       INT8_C(   1),
      { -INT32_C(   909348961), -INT32_C(   909348961), -INT32_C(   909348961), -INT32_C(   909348961) } },
    { { -INT32_C(  1365422193), -INT32_C(   183551340) },
       INT8_C(   0),
      { -INT32_C(  1365422193), -INT32_C(  1365422193), -INT32_C(  1365422193), -INT32_C(  1365422193) } },
    { { -INT32_C(  1195332042), -INT32_C(   776315401) },
       INT8_C(   0),
      { -INT32_C(  1195332042), -INT32_C(  1195332042), -INT32_C(  1195332042), -INT32_C(  1195332042) } },
    { { -INT32_C(   579350715), -INT32_C(  1898117118) },
       INT8_C(   0),
      { -INT32_C(   579350715), -INT32_C(   579350715), -INT32_C(   579350715), -INT32_C(   579350715) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t vec;
    simde_int32x4_t r;

    vec = simde_vld1_s32(test_vec[i].vec);
    SIMDE_CONSTIFY_2_(simde_vdupq_lane_s32, r, (HEDLEY_UNREACHABLE(), simde_vdupq_n_s32(0)), test_vec[i].lane, vec);

    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x2_t vec = simde_test_arm_neon_random_i32x2();
    int lane = simde_test_codegen_random_i8() & 1;

    simde_int32x4_t r;
    SIMDE_CONSTIFY_2_(simde_vdupq_lane_s32, r, (HEDLEY_UNREACHABLE(), simde_vdupq_n_s32(0)), lane, vec);

    simde_test_arm_neon_write_i32x2(2, vec, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i8(2, HEDLEY_STATIC_CAST(int8_t, lane), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vdupq_lane_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int64_t vec[1];
    int lane;
    int64_t r[2];
  } test_vec[] = {
    { { -INT64_C( 5271004726777602230) },
       INT8_C(   0),
      { -INT64_C( 5271004726777602230), -INT64_C( 5271004726777602230) } },
    { { -INT64_C( 5514893245762030507) },
       INT8_C(   0),
      { -INT64_C( 5514893245762030507), -INT64_C( 5514893245762030507) } },
    { {  INT64_C( 2592892641896537330) },
       INT8_C(   0),
      {  INT64_C( 2592892641896537330),  INT64_C( 2592892641896537330) } },
    { {  INT64_C( 2407055658969273279) },
       INT8_C(   0),
      {  INT64_C( 2407055658969273279),  INT64_C( 2407055658969273279) } },
    { {  INT64_C( 4056792530928007688) },
       INT8_C(   0),
      {  INT64_C( 4056792530928007688),  INT64_C( 4056792530928007688) } },
    { {  INT64_C( 6722394993897615222) },
       INT8_C(   0),
      {  INT64_C( 6722394993897615222),  INT64_C( 6722394993897615222) } },
    { {  INT64_C( 8871829688100542744) },
       INT8_C(   0),
      {  INT64_C( 8871829688100542744),  INT64_C( 8871829688100542744) } },
    { {  INT64_C( 1212467663097422515) },
       INT8_C(   0),
      {  INT64_C( 1212467663097422515),  INT64_C( 1212467663097422515) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x1_t vec;
    simde_int64x2_t r;

    vec = simde_vld1_s64(test_vec[i].vec);
    r = simde_vdupq_lane_s64(vec, 0);

    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[i].r));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_int64x1_t vec = simde_test_arm_neon_random_i64x1();
    int lane = simde_test_codegen_random_i8() & 0;

    simde_int64x2_t r;
    r = simde_vdupq_lane_s64(vec, 0);

    simde_test_arm_neon_write_i64x1(2, vec, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i8(2, HEDLEY_STATIC_CAST(int8_t, lane), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vdupq_lane_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint8_t vec[8];
    int lane;
    uint8_t r[16];
  } test_vec[] = {
    { { UINT8_C(169), UINT8_C(207), UINT8_C( 64), UINT8_C(146), UINT8_C(157), UINT8_C(122), UINT8_C( 44), UINT8_C(  4) },
       INT8_C(   1),
      { UINT8_C(207), UINT8_C(207), UINT8_C(207), UINT8_C(207), UINT8_C(207), UINT8_C(207), UINT8_C(207), UINT8_C(207),
        UINT8_C(207), UINT8_C(207), UINT8_C(207), UINT8_C(207), UINT8_C(207), UINT8_C(207), UINT8_C(207), UINT8_C(207) } },
    { {    UINT8_MAX, UINT8_C(115), UINT8_C( 24), UINT8_C(113), UINT8_C( 78), UINT8_C(113), UINT8_C(246), UINT8_C( 13) },
       INT8_C(   7),
      { UINT8_C( 13), UINT8_C( 13), UINT8_C( 13), UINT8_C( 13), UINT8_C( 13), UINT8_C( 13), UINT8_C( 13), UINT8_C( 13),
        UINT8_C( 13), UINT8_C( 13), UINT8_C( 13), UINT8_C( 13), UINT8_C( 13), UINT8_C( 13), UINT8_C( 13), UINT8_C( 13) } },
    { { UINT8_C(236), UINT8_C(229), UINT8_C( 14), UINT8_C(230), UINT8_C(243), UINT8_C( 63), UINT8_C( 37), UINT8_C( 41) },
       INT8_C(   3),
      { UINT8_C(230), UINT8_C(230), UINT8_C(230), UINT8_C(230), UINT8_C(230), UINT8_C(230), UINT8_C(230), UINT8_C(230),
        UINT8_C(230), UINT8_C(230), UINT8_C(230), UINT8_C(230), UINT8_C(230), UINT8_C(230), UINT8_C(230), UINT8_C(230) } },
    { { UINT8_C(239), UINT8_C(141), UINT8_C(206), UINT8_C(146), UINT8_C( 54), UINT8_C(157), UINT8_C(210), UINT8_C(200) },
       INT8_C(   2),
      { UINT8_C(206), UINT8_C(206), UINT8_C(206), UINT8_C(206), UINT8_C(206), UINT8_C(206), UINT8_C(206), UINT8_C(206),
        UINT8_C(206), UINT8_C(206), UINT8_C(206), UINT8_C(206), UINT8_C(206), UINT8_C(206), UINT8_C(206), UINT8_C(206) } },
    { { UINT8_C( 77), UINT8_C(244), UINT8_C( 63), UINT8_C(142), UINT8_C(244), UINT8_C(178), UINT8_C(166), UINT8_C(101) },
       INT8_C(   1),
      { UINT8_C(244), UINT8_C(244), UINT8_C(244), UINT8_C(244), UINT8_C(244), UINT8_C(244), UINT8_C(244), UINT8_C(244),
        UINT8_C(244), UINT8_C(244), UINT8_C(244), UINT8_C(244), UINT8_C(244), UINT8_C(244), UINT8_C(244), UINT8_C(244) } },
    { { UINT8_C( 23), UINT8_C( 92), UINT8_C( 14), UINT8_C(246), UINT8_C( 72), UINT8_C(243), UINT8_C(  4), UINT8_C( 46) },
       INT8_C(   6),
      { UINT8_C(  4), UINT8_C(  4), UINT8_C(  4), UINT8_C(  4), UINT8_C(  4), UINT8_C(  4), UINT8_C(  4), UINT8_C(  4),
        UINT8_C(  4), UINT8_C(  4), UINT8_C(  4), UINT8_C(  4), UINT8_C(  4), UINT8_C(  4), UINT8_C(  4), UINT8_C(  4) } },
    { { UINT8_C( 67), UINT8_C( 83), UINT8_C( 16), UINT8_C(230), UINT8_C( 66), UINT8_C(157), UINT8_C(180), UINT8_C(212) },
       INT8_C(   3),
      { UINT8_C(230), UINT8_C(230), UINT8_C(230), UINT8_C(230), UINT8_C(230), UINT8_C(230), UINT8_C(230), UINT8_C(230),
        UINT8_C(230), UINT8_C(230), UINT8_C(230), UINT8_C(230), UINT8_C(230), UINT8_C(230), UINT8_C(230), UINT8_C(230) } },
    { { UINT8_C( 81), UINT8_C(167), UINT8_C(155), UINT8_C(140), UINT8_C(244), UINT8_C(144), UINT8_C(203), UINT8_C(130) },
       INT8_C(   4),
      { UINT8_C(244), UINT8_C(244), UINT8_C(244), UINT8_C(244), UINT8_C(244), UINT8_C(244), UINT8_C(244), UINT8_C(244),
        UINT8_C(244), UINT8_C(244), UINT8_C(244), UINT8_C(244), UINT8_C(244), UINT8_C(244), UINT8_C(244), UINT8_C(244) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x8_t vec;
    simde_uint8x16_t r;

    vec = simde_vld1_u8(test_vec[i].vec);
    SIMDE_CONSTIFY_8_(simde_vdupq_lane_u8, r, (HEDLEY_UNREACHABLE(), simde_vdupq_n_u8(0)), test_vec[i].lane, vec);

    simde_test_arm_neon_assert_equal_u8x16(r, simde_vld1q_u8(test_vec[i].r));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8x8_t vec = simde_test_arm_neon_random_u8x8();
    int lane = simde_test_codegen_random_i8() & 7;

    simde_uint8x16_t r;
    SIMDE_CONSTIFY_8_(simde_vdupq_lane_u8, r, (HEDLEY_UNREACHABLE(), simde_vdupq_n_u8(0)), lane, vec);

    simde_test_arm_neon_write_u8x8(2, vec, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i8(2, HEDLEY_STATIC_CAST(int8_t, lane), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vdupq_lane_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint16_t vec[4];
    int lane;
    uint16_t r[8];
  } test_vec[] = {
    { { UINT16_C(42621), UINT16_C(14183), UINT16_C(32933), UINT16_C(43737) },
       INT8_C(   0),
      { UINT16_C(42621), UINT16_C(42621), UINT16_C(42621), UINT16_C(42621), UINT16_C(42621), UINT16_C(42621), UINT16_C(42621), UINT16_C(42621) } },
    { { UINT16_C(20803), UINT16_C( 9878), UINT16_C(64829), UINT16_C(53371) },
       INT8_C(   1),
      { UINT16_C( 9878), UINT16_C( 9878), UINT16_C( 9878), UINT16_C( 9878), UINT16_C( 9878), UINT16_C( 9878), UINT16_C( 9878), UINT16_C( 9878) } },
    { { UINT16_C(60523), UINT16_C(37693), UINT16_C(53354), UINT16_C(41286) },
       INT8_C(   3),
      { UINT16_C(41286), UINT16_C(41286), UINT16_C(41286), UINT16_C(41286), UINT16_C(41286), UINT16_C(41286), UINT16_C(41286), UINT16_C(41286) } },
    { { UINT16_C( 8692), UINT16_C(32507), UINT16_C(41630), UINT16_C(54757) },
       INT8_C(   3),
      { UINT16_C(54757), UINT16_C(54757), UINT16_C(54757), UINT16_C(54757), UINT16_C(54757), UINT16_C(54757), UINT16_C(54757), UINT16_C(54757) } },
    { { UINT16_C(44645), UINT16_C(34289), UINT16_C(17393), UINT16_C( 6172) },
       INT8_C(   0),
      { UINT16_C(44645), UINT16_C(44645), UINT16_C(44645), UINT16_C(44645), UINT16_C(44645), UINT16_C(44645), UINT16_C(44645), UINT16_C(44645) } },
    { { UINT16_C(37657), UINT16_C(33360), UINT16_C(15614), UINT16_C(37311) },
       INT8_C(   3),
      { UINT16_C(37311), UINT16_C(37311), UINT16_C(37311), UINT16_C(37311), UINT16_C(37311), UINT16_C(37311), UINT16_C(37311), UINT16_C(37311) } },
    { { UINT16_C(55439), UINT16_C(57928), UINT16_C(27084), UINT16_C(19166) },
       INT8_C(   3),
      { UINT16_C(19166), UINT16_C(19166), UINT16_C(19166), UINT16_C(19166), UINT16_C(19166), UINT16_C(19166), UINT16_C(19166), UINT16_C(19166) } },
    { { UINT16_C(12160), UINT16_C(51164), UINT16_C(35732), UINT16_C( 6584) },
       INT8_C(   0),
      { UINT16_C(12160), UINT16_C(12160), UINT16_C(12160), UINT16_C(12160), UINT16_C(12160), UINT16_C(12160), UINT16_C(12160), UINT16_C(12160) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4_t vec;
    simde_uint16x8_t r;

    vec = simde_vld1_u16(test_vec[i].vec);
    SIMDE_CONSTIFY_4_(simde_vdupq_lane_u16, r, (HEDLEY_UNREACHABLE(), simde_vdupq_n_u16(0)), test_vec[i].lane, vec);

    simde_test_arm_neon_assert_equal_u16x8(r, simde_vld1q_u16(test_vec[i].r));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x4_t vec = simde_test_arm_neon_random_u16x4();
    int lane = simde_test_codegen_random_i8() & 3;

    simde_uint16x8_t r;
    SIMDE_CONSTIFY_4_(simde_vdupq_lane_u16, r, (HEDLEY_UNREACHABLE(), simde_vdupq_n_u16(0)), lane, vec);

    simde_test_arm_neon_write_u16x4(2, vec, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i8(2, HEDLEY_STATIC_CAST(int8_t, lane), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vdupq_lane_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint32_t vec[2];
    int lane;
    uint32_t r[4];
  } test_vec[] = {
    { { UINT32_C(2301534942), UINT32_C(3542810016) },
       INT8_C(   0),
      { UINT32_C(2301534942), UINT32_C(2301534942), UINT32_C(2301534942), UINT32_C(2301534942) } },
    { { UINT32_C(1166405053), UINT32_C(3688154536) },
       INT8_C(   1),
      { UINT32_C(3688154536), UINT32_C(3688154536), UINT32_C(3688154536), UINT32_C(3688154536) } },
    { { UINT32_C(3993153574), UINT32_C(2702071403) },
       INT8_C(   0),
      { UINT32_C(3993153574), UINT32_C(3993153574), UINT32_C(3993153574), UINT32_C(3993153574) } },
    { { UINT32_C(1677804311), UINT32_C(2878514210) },
       INT8_C(   0),
      { UINT32_C(1677804311), UINT32_C(1677804311), UINT32_C(1677804311), UINT32_C(1677804311) } },
    { { UINT32_C(1092081295), UINT32_C(3636921747) },
       INT8_C(   1),
      { UINT32_C(3636921747), UINT32_C(3636921747), UINT32_C(3636921747), UINT32_C(3636921747) } },
    { { UINT32_C( 159952012), UINT32_C(3238738386) },
       INT8_C(   0),
      { UINT32_C( 159952012), UINT32_C( 159952012), UINT32_C( 159952012), UINT32_C( 159952012) } },
    { { UINT32_C(2756104034), UINT32_C(1252428262) },
       INT8_C(   1),
      { UINT32_C(1252428262), UINT32_C(1252428262), UINT32_C(1252428262), UINT32_C(1252428262) } },
    { { UINT32_C(2388122698), UINT32_C(2913348972) },
       INT8_C(   0),
      { UINT32_C(2388122698), UINT32_C(2388122698), UINT32_C(2388122698), UINT32_C(2388122698) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2_t vec;
    simde_uint32x4_t r;

    vec = simde_vld1_u32(test_vec[i].vec);
    SIMDE_CONSTIFY_2_(simde_vdupq_lane_u32, r, (HEDLEY_UNREACHABLE(), simde_vdupq_n_u32(0)), test_vec[i].lane, vec);

    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x2_t vec = simde_test_arm_neon_random_u32x2();
    int lane = simde_test_codegen_random_i8() & 1;

    simde_uint32x4_t r;
    SIMDE_CONSTIFY_2_(simde_vdupq_lane_u32, r, (HEDLEY_UNREACHABLE(), simde_vdupq_n_u32(0)), lane, vec);

    simde_test_arm_neon_write_u32x2(2, vec, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i8(2, HEDLEY_STATIC_CAST(int8_t, lane), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vdupq_lane_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint64_t vec[1];
    int lane;
    uint64_t r[2];
  } test_vec[] = {
    { { UINT64_C(  455882935909149950) },
       INT8_C(   0),
      { UINT64_C(  455882935909149950), UINT64_C(  455882935909149950) } },
    { { UINT64_C(11933587015411218425) },
       INT8_C(   0),
      { UINT64_C(11933587015411218425), UINT64_C(11933587015411218425) } },
    { { UINT64_C(14838357478928476872) },
       INT8_C(   0),
      { UINT64_C(14838357478928476872), UINT64_C(14838357478928476872) } },
    { { UINT64_C(10410602884629015667) },
       INT8_C(   0),
      { UINT64_C(10410602884629015667), UINT64_C(10410602884629015667) } },
    { { UINT64_C(14047218565468644120) },
       INT8_C(   0),
      { UINT64_C(14047218565468644120), UINT64_C(14047218565468644120) } },
    { { UINT64_C(13486723040809934480) },
       INT8_C(   0),
      { UINT64_C(13486723040809934480), UINT64_C(13486723040809934480) } },
    { { UINT64_C(10194163952196691865) },
       INT8_C(   0),
      { UINT64_C(10194163952196691865), UINT64_C(10194163952196691865) } },
    { { UINT64_C( 4928221257128478300) },
       INT8_C(   0),
      { UINT64_C( 4928221257128478300), UINT64_C( 4928221257128478300) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x1_t vec;
    simde_uint64x2_t r;

    vec = simde_vld1_u64(test_vec[i].vec);
    r = simde_vdupq_lane_u64(vec, 0);

    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[i].r));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint64x1_t vec = simde_test_arm_neon_random_u64x1();
    int lane = simde_test_codegen_random_i8() & 0;

    simde_uint64x2_t r;
    r = simde_vdupq_lane_u64(vec, 0);

    simde_test_arm_neon_write_u64x1(2, vec, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i8(2, HEDLEY_STATIC_CAST(int8_t, lane), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vdupq_laneq_f16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float16 vec[8];
    int lane;
    simde_float16 r[8];
  } test_vec[] = {
    { {  SIMDE_FLOAT16_VALUE(   -14.944),  SIMDE_FLOAT16_VALUE(    29.976),  SIMDE_FLOAT16_VALUE(     8.148),  SIMDE_FLOAT16_VALUE(    -8.525),
         SIMDE_FLOAT16_VALUE(     4.332),  SIMDE_FLOAT16_VALUE(    -8.444),  SIMDE_FLOAT16_VALUE(   -17.802),  SIMDE_FLOAT16_VALUE(    18.658) },
         INT8_C(         3),
      {  SIMDE_FLOAT16_VALUE(    -8.525),  SIMDE_FLOAT16_VALUE(    -8.525),  SIMDE_FLOAT16_VALUE(    -8.525),  SIMDE_FLOAT16_VALUE(    -8.525),
         SIMDE_FLOAT16_VALUE(    -8.525),  SIMDE_FLOAT16_VALUE(    -8.525),  SIMDE_FLOAT16_VALUE(    -8.525),  SIMDE_FLOAT16_VALUE(    -8.525) } },
    { {  SIMDE_FLOAT16_VALUE(     2.837),  SIMDE_FLOAT16_VALUE(    -2.966),  SIMDE_FLOAT16_VALUE(   -13.207),  SIMDE_FLOAT16_VALUE(     9.802),
         SIMDE_FLOAT16_VALUE(   -11.553),  SIMDE_FLOAT16_VALUE(     4.185),  SIMDE_FLOAT16_VALUE(    -2.087),  SIMDE_FLOAT16_VALUE(   -25.138) },
         INT8_C(         0),
      {  SIMDE_FLOAT16_VALUE(     2.837),  SIMDE_FLOAT16_VALUE(     2.837),  SIMDE_FLOAT16_VALUE(     2.837),  SIMDE_FLOAT16_VALUE(     2.837),
         SIMDE_FLOAT16_VALUE(     2.837),  SIMDE_FLOAT16_VALUE(     2.837),  SIMDE_FLOAT16_VALUE(     2.837),  SIMDE_FLOAT16_VALUE(     2.837) } },
    { {  SIMDE_FLOAT16_VALUE(    -9.082),  SIMDE_FLOAT16_VALUE(   -20.470),  SIMDE_FLOAT16_VALUE(    -2.951),  SIMDE_FLOAT16_VALUE(   -21.315),
         SIMDE_FLOAT16_VALUE(   -22.110),  SIMDE_FLOAT16_VALUE(     4.867),  SIMDE_FLOAT16_VALUE(    -1.873),  SIMDE_FLOAT16_VALUE(    -9.236) },
         INT8_C(         6),
      {  SIMDE_FLOAT16_VALUE(    -1.873),  SIMDE_FLOAT16_VALUE(    -1.873),  SIMDE_FLOAT16_VALUE(    -1.873),  SIMDE_FLOAT16_VALUE(    -1.873),
         SIMDE_FLOAT16_VALUE(    -1.873),  SIMDE_FLOAT16_VALUE(    -1.873),  SIMDE_FLOAT16_VALUE(    -1.873),  SIMDE_FLOAT16_VALUE(    -1.873) } },
    { {  SIMDE_FLOAT16_VALUE(    -6.811),  SIMDE_FLOAT16_VALUE(   -18.944),  SIMDE_FLOAT16_VALUE(    17.974),  SIMDE_FLOAT16_VALUE(    23.871),
         SIMDE_FLOAT16_VALUE(    22.903),  SIMDE_FLOAT16_VALUE(   -21.458),  SIMDE_FLOAT16_VALUE(    -7.777),  SIMDE_FLOAT16_VALUE(    11.946) },
         INT8_C(         7),
      {  SIMDE_FLOAT16_VALUE(    11.946),  SIMDE_FLOAT16_VALUE(    11.946),  SIMDE_FLOAT16_VALUE(    11.946),  SIMDE_FLOAT16_VALUE(    11.946),
         SIMDE_FLOAT16_VALUE(    11.946),  SIMDE_FLOAT16_VALUE(    11.946),  SIMDE_FLOAT16_VALUE(    11.946),  SIMDE_FLOAT16_VALUE(    11.946) } },
    { {  SIMDE_FLOAT16_VALUE(     4.721),  SIMDE_FLOAT16_VALUE(    22.653),  SIMDE_FLOAT16_VALUE(    -5.854),  SIMDE_FLOAT16_VALUE(    -4.341),
         SIMDE_FLOAT16_VALUE(     0.043),  SIMDE_FLOAT16_VALUE(    -3.823),  SIMDE_FLOAT16_VALUE(     4.788),  SIMDE_FLOAT16_VALUE(    11.244) },
         INT8_C(         4),
      {  SIMDE_FLOAT16_VALUE(     0.043),  SIMDE_FLOAT16_VALUE(     0.043),  SIMDE_FLOAT16_VALUE(     0.043),  SIMDE_FLOAT16_VALUE(     0.043),
         SIMDE_FLOAT16_VALUE(     0.043),  SIMDE_FLOAT16_VALUE(     0.043),  SIMDE_FLOAT16_VALUE(     0.043),  SIMDE_FLOAT16_VALUE(     0.043) } },
    { {  SIMDE_FLOAT16_VALUE(   -29.389),  SIMDE_FLOAT16_VALUE(    25.831),  SIMDE_FLOAT16_VALUE(     2.593),  SIMDE_FLOAT16_VALUE(     0.655),
         SIMDE_FLOAT16_VALUE(   -29.518),  SIMDE_FLOAT16_VALUE(    21.627),  SIMDE_FLOAT16_VALUE(    -9.484),  SIMDE_FLOAT16_VALUE(     9.197) },
         INT8_C(         7),
      {  SIMDE_FLOAT16_VALUE(     9.197),  SIMDE_FLOAT16_VALUE(     9.197),  SIMDE_FLOAT16_VALUE(     9.197),  SIMDE_FLOAT16_VALUE(     9.197),
         SIMDE_FLOAT16_VALUE(     9.197),  SIMDE_FLOAT16_VALUE(     9.197),  SIMDE_FLOAT16_VALUE(     9.197),  SIMDE_FLOAT16_VALUE(     9.197) } },
    { {  SIMDE_FLOAT16_VALUE(     6.412),  SIMDE_FLOAT16_VALUE(    -2.948),  SIMDE_FLOAT16_VALUE(    17.301),  SIMDE_FLOAT16_VALUE(     9.426),
         SIMDE_FLOAT16_VALUE(    23.317),  SIMDE_FLOAT16_VALUE(    -1.470),  SIMDE_FLOAT16_VALUE(   -28.086),  SIMDE_FLOAT16_VALUE(    -4.040) },
         INT8_C(         6),
      {  SIMDE_FLOAT16_VALUE(   -28.086),  SIMDE_FLOAT16_VALUE(   -28.086),  SIMDE_FLOAT16_VALUE(   -28.086),  SIMDE_FLOAT16_VALUE(   -28.086),
         SIMDE_FLOAT16_VALUE(   -28.086),  SIMDE_FLOAT16_VALUE(   -28.086),  SIMDE_FLOAT16_VALUE(   -28.086),  SIMDE_FLOAT16_VALUE(   -28.086) } },
    { {  SIMDE_FLOAT16_VALUE(    17.678),  SIMDE_FLOAT16_VALUE(    12.177),  SIMDE_FLOAT16_VALUE(   -14.208),  SIMDE_FLOAT16_VALUE(   -15.268),
         SIMDE_FLOAT16_VALUE(    15.600),  SIMDE_FLOAT16_VALUE(   -16.025),  SIMDE_FLOAT16_VALUE(    24.952),  SIMDE_FLOAT16_VALUE(    -1.031) },
         INT8_C(         7),
      {  SIMDE_FLOAT16_VALUE(    -1.031),  SIMDE_FLOAT16_VALUE(    -1.031),  SIMDE_FLOAT16_VALUE(    -1.031),  SIMDE_FLOAT16_VALUE(    -1.031),
         SIMDE_FLOAT16_VALUE(    -1.031),  SIMDE_FLOAT16_VALUE(    -1.031),  SIMDE_FLOAT16_VALUE(    -1.031),  SIMDE_FLOAT16_VALUE(    -1.031) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x8_t vec;
    simde_float16x8_t r;

    vec = simde_vld1q_f16(test_vec[i].vec);
    SIMDE_CONSTIFY_8_(simde_vdupq_laneq_f16, r, (HEDLEY_UNREACHABLE(), simde_vdupq_n_f16(SIMDE_FLOAT16_VALUE(0.0))), test_vec[i].lane, vec);

    simde_test_arm_neon_assert_equal_f16x8(r, simde_vld1q_f16(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_vdupq_laneq_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float32 vec[4];
    int lane;
    simde_float32 r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   841.63), SIMDE_FLOAT32_C(   -49.45), SIMDE_FLOAT32_C(   261.67), SIMDE_FLOAT32_C(  -350.53) },
       INT8_C(   2),
      { SIMDE_FLOAT32_C(   261.67), SIMDE_FLOAT32_C(   261.67), SIMDE_FLOAT32_C(   261.67), SIMDE_FLOAT32_C(   261.67) } },
    { { SIMDE_FLOAT32_C(   242.12), SIMDE_FLOAT32_C(   896.58), SIMDE_FLOAT32_C(  -122.58), SIMDE_FLOAT32_C(  -914.43) },
       INT8_C(   3),
      { SIMDE_FLOAT32_C(  -914.43), SIMDE_FLOAT32_C(  -914.43), SIMDE_FLOAT32_C(  -914.43), SIMDE_FLOAT32_C(  -914.43) } },
    { { SIMDE_FLOAT32_C(  -903.27), SIMDE_FLOAT32_C(   -11.67), SIMDE_FLOAT32_C(  -137.96), SIMDE_FLOAT32_C(  -521.79) },
       INT8_C(   1),
      { SIMDE_FLOAT32_C(   -11.67), SIMDE_FLOAT32_C(   -11.67), SIMDE_FLOAT32_C(   -11.67), SIMDE_FLOAT32_C(   -11.67) } },
    { { SIMDE_FLOAT32_C(  -946.62), SIMDE_FLOAT32_C(  -205.01), SIMDE_FLOAT32_C(  -121.41), SIMDE_FLOAT32_C(   159.32) },
       INT8_C(   0),
      { SIMDE_FLOAT32_C(  -946.62), SIMDE_FLOAT32_C(  -946.62), SIMDE_FLOAT32_C(  -946.62), SIMDE_FLOAT32_C(  -946.62) } },
    { { SIMDE_FLOAT32_C(   334.52), SIMDE_FLOAT32_C(  -142.22), SIMDE_FLOAT32_C(  -498.68), SIMDE_FLOAT32_C(  -830.99) },
       INT8_C(   0),
      { SIMDE_FLOAT32_C(   334.52), SIMDE_FLOAT32_C(   334.52), SIMDE_FLOAT32_C(   334.52), SIMDE_FLOAT32_C(   334.52) } },
    { { SIMDE_FLOAT32_C(   855.02), SIMDE_FLOAT32_C(  -765.81), SIMDE_FLOAT32_C(  -476.10), SIMDE_FLOAT32_C(   738.65) },
       INT8_C(   2),
      { SIMDE_FLOAT32_C(  -476.10), SIMDE_FLOAT32_C(  -476.10), SIMDE_FLOAT32_C(  -476.10), SIMDE_FLOAT32_C(  -476.10) } },
    { { SIMDE_FLOAT32_C(    85.00), SIMDE_FLOAT32_C(   580.28), SIMDE_FLOAT32_C(   330.74), SIMDE_FLOAT32_C(  -653.33) },
       INT8_C(   3),
      { SIMDE_FLOAT32_C(  -653.33), SIMDE_FLOAT32_C(  -653.33), SIMDE_FLOAT32_C(  -653.33), SIMDE_FLOAT32_C(  -653.33) } },
    { { SIMDE_FLOAT32_C(  -767.25), SIMDE_FLOAT32_C(   588.80), SIMDE_FLOAT32_C(  -873.67), SIMDE_FLOAT32_C(   110.16) },
       INT8_C(   3),
      { SIMDE_FLOAT32_C(   110.16), SIMDE_FLOAT32_C(   110.16), SIMDE_FLOAT32_C(   110.16), SIMDE_FLOAT32_C(   110.16) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t vec;
    simde_float32x4_t r;

    vec = simde_vld1q_f32(test_vec[i].vec);
    SIMDE_CONSTIFY_4_(simde_vdupq_laneq_f32, r, (HEDLEY_UNREACHABLE(), simde_vdupq_n_f32(0.0f)), test_vec[i].lane, vec);

    simde_test_arm_neon_assert_equal_f32x4(r, simde_vld1q_f32(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x4_t vec = simde_test_arm_neon_random_f32x4(-1000.0, 1000.0);
    int lane = simde_test_codegen_random_i8() & 3;

    simde_float32x4_t r;
    SIMDE_CONSTIFY_4_(simde_vdupq_laneq_f32, r, (HEDLEY_UNREACHABLE(), simde_vdupq_n_f32(0.0f)), lane, vec);

    simde_test_arm_neon_write_f32x4(2, vec, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i8(2, HEDLEY_STATIC_CAST(int8_t, lane), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vdupq_laneq_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float64 vec[2];
    int lane;
    simde_float64 r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(  -955.26), SIMDE_FLOAT64_C(  -551.38) },
       INT8_C(   0),
      { SIMDE_FLOAT64_C(  -955.26), SIMDE_FLOAT64_C(  -955.26) } },
    { { SIMDE_FLOAT64_C(    53.53), SIMDE_FLOAT64_C(   970.21) },
       INT8_C(   1),
      { SIMDE_FLOAT64_C(   970.21), SIMDE_FLOAT64_C(   970.21) } },
    { { SIMDE_FLOAT64_C(  -594.72), SIMDE_FLOAT64_C(   118.44) },
       INT8_C(   1),
      { SIMDE_FLOAT64_C(   118.44), SIMDE_FLOAT64_C(   118.44) } },
    { { SIMDE_FLOAT64_C(   499.85), SIMDE_FLOAT64_C(   930.54) },
       INT8_C(   0),
      { SIMDE_FLOAT64_C(   499.85), SIMDE_FLOAT64_C(   499.85) } },
    { { SIMDE_FLOAT64_C(   858.61), SIMDE_FLOAT64_C(   351.33) },
       INT8_C(   1),
      { SIMDE_FLOAT64_C(   351.33), SIMDE_FLOAT64_C(   351.33) } },
    { { SIMDE_FLOAT64_C(   558.39), SIMDE_FLOAT64_C(  -964.87) },
       INT8_C(   0),
      { SIMDE_FLOAT64_C(   558.39), SIMDE_FLOAT64_C(   558.39) } },
    { { SIMDE_FLOAT64_C(  -858.49), SIMDE_FLOAT64_C(   914.99) },
       INT8_C(   0),
      { SIMDE_FLOAT64_C(  -858.49), SIMDE_FLOAT64_C(  -858.49) } },
    { { SIMDE_FLOAT64_C(   745.32), SIMDE_FLOAT64_C(  -258.32) },
       INT8_C(   1),
      { SIMDE_FLOAT64_C(  -258.32), SIMDE_FLOAT64_C(  -258.32) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2_t vec;
    simde_float64x2_t r;

    vec = simde_vld1q_f64(test_vec[i].vec);
    SIMDE_CONSTIFY_2_(simde_vdupq_laneq_f64, r, (HEDLEY_UNREACHABLE(), simde_vdupq_n_f64(0.0)), test_vec[i].lane, vec);

    simde_test_arm_neon_assert_equal_f64x2(r, simde_vld1q_f64(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x2_t vec = simde_test_arm_neon_random_f64x2(-1000.0, 1000.0);
    int lane = simde_test_codegen_random_i8() & 1;

    simde_float64x2_t r;
    SIMDE_CONSTIFY_2_(simde_vdupq_laneq_f64, r, (HEDLEY_UNREACHABLE(), simde_vdupq_n_f64(0.0)), lane, vec);

    simde_test_arm_neon_write_f64x2(2, vec, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i8(2, HEDLEY_STATIC_CAST(int8_t, lane), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vdupq_laneq_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int8_t vec[16];
    int lane;
    int8_t r[16];
  } test_vec[] = {
    { {  INT8_C(  99), -INT8_C(  62),  INT8_C(  37),  INT8_C(  65),  INT8_C( 113), -INT8_C(   6),  INT8_C(  57), -INT8_C( 114),
         INT8_C(  89), -INT8_C(  29),  INT8_C(   4), -INT8_C(  45),  INT8_C(   8), -INT8_C(  71),  INT8_C(  46),  INT8_C(  87) },
       INT8_C(   7),
      { -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114),
        -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114) } },
    { { -INT8_C(  56), -INT8_C(  99), -INT8_C(  88),  INT8_C(  89), -INT8_C(   4), -INT8_C(   7),  INT8_C(  59), -INT8_C(  97),
        -INT8_C(  11), -INT8_C(  98),  INT8_C(  84), -INT8_C( 108),  INT8_C(   7), -INT8_C(  51), -INT8_C(   9), -INT8_C(  54) },
       INT8_C(   2),
      { -INT8_C(  88), -INT8_C(  88), -INT8_C(  88), -INT8_C(  88), -INT8_C(  88), -INT8_C(  88), -INT8_C(  88), -INT8_C(  88),
        -INT8_C(  88), -INT8_C(  88), -INT8_C(  88), -INT8_C(  88), -INT8_C(  88), -INT8_C(  88), -INT8_C(  88), -INT8_C(  88) } },
    { {  INT8_C(  56),  INT8_C(  59), -INT8_C(  20),  INT8_C( 113), -INT8_C(  55),  INT8_C(  69),  INT8_C(  84), -INT8_C(  51),
         INT8_C(  25),  INT8_C(  92), -INT8_C( 122),  INT8_C(  71), -INT8_C(  77), -INT8_C(  35),  INT8_C(  16),  INT8_C(  81) },
       INT8_C(   6),
      {  INT8_C(  84),  INT8_C(  84),  INT8_C(  84),  INT8_C(  84),  INT8_C(  84),  INT8_C(  84),  INT8_C(  84),  INT8_C(  84),
         INT8_C(  84),  INT8_C(  84),  INT8_C(  84),  INT8_C(  84),  INT8_C(  84),  INT8_C(  84),  INT8_C(  84),  INT8_C(  84) } },
    { {  INT8_C( 105),  INT8_C(  77),      INT8_MAX, -INT8_C(  91), -INT8_C(  20),  INT8_C( 116),  INT8_C(  67),  INT8_C(  65),
         INT8_C(   8),  INT8_C(  74),  INT8_C(  14),  INT8_C(   0),  INT8_C(  20),  INT8_C(   0),  INT8_C(  56),  INT8_C(  80) },
       INT8_C(  12),
      {  INT8_C(  20),  INT8_C(  20),  INT8_C(  20),  INT8_C(  20),  INT8_C(  20),  INT8_C(  20),  INT8_C(  20),  INT8_C(  20),
         INT8_C(  20),  INT8_C(  20),  INT8_C(  20),  INT8_C(  20),  INT8_C(  20),  INT8_C(  20),  INT8_C(  20),  INT8_C(  20) } },
    { { -INT8_C(  86),  INT8_C(  25),  INT8_C(  50), -INT8_C(   2), -INT8_C(  25),  INT8_C(  75),  INT8_C(  91),  INT8_C( 109),
        -INT8_C( 110),  INT8_C(  14),  INT8_C(  75), -INT8_C(  94),  INT8_C(  95), -INT8_C(  47),  INT8_C(  12), -INT8_C(  83) },
       INT8_C(   0),
      { -INT8_C(  86), -INT8_C(  86), -INT8_C(  86), -INT8_C(  86), -INT8_C(  86), -INT8_C(  86), -INT8_C(  86), -INT8_C(  86),
        -INT8_C(  86), -INT8_C(  86), -INT8_C(  86), -INT8_C(  86), -INT8_C(  86), -INT8_C(  86), -INT8_C(  86), -INT8_C(  86) } },
    { { -INT8_C(  79), -INT8_C( 103), -INT8_C(  60), -INT8_C(  12), -INT8_C(  38), -INT8_C(  51),  INT8_C(  62), -INT8_C(  24),
        -INT8_C(  51),  INT8_C(  83), -INT8_C(  24),  INT8_C(   5), -INT8_C(  93), -INT8_C(  43), -INT8_C(  81), -INT8_C(  68) },
       INT8_C(   7),
      { -INT8_C(  24), -INT8_C(  24), -INT8_C(  24), -INT8_C(  24), -INT8_C(  24), -INT8_C(  24), -INT8_C(  24), -INT8_C(  24),
        -INT8_C(  24), -INT8_C(  24), -INT8_C(  24), -INT8_C(  24), -INT8_C(  24), -INT8_C(  24), -INT8_C(  24), -INT8_C(  24) } },
    { { -INT8_C(  82), -INT8_C(  93),  INT8_C(  82),  INT8_C(   9),  INT8_C(  17), -INT8_C(  28),  INT8_C(  23),  INT8_C(  92),
        -INT8_C( 121),  INT8_C( 119),  INT8_C(  45), -INT8_C( 109),  INT8_C(  36),  INT8_C( 125),  INT8_C(  68), -INT8_C(  67) },
       INT8_C(   1),
      { -INT8_C(  93), -INT8_C(  93), -INT8_C(  93), -INT8_C(  93), -INT8_C(  93), -INT8_C(  93), -INT8_C(  93), -INT8_C(  93),
        -INT8_C(  93), -INT8_C(  93), -INT8_C(  93), -INT8_C(  93), -INT8_C(  93), -INT8_C(  93), -INT8_C(  93), -INT8_C(  93) } },
    { {  INT8_C(  56), -INT8_C( 104),  INT8_C(  14),  INT8_C( 118),      INT8_MIN, -INT8_C(  37), -INT8_C(  55),  INT8_C( 105),
        -INT8_C(  31),  INT8_C( 108),  INT8_C(  62), -INT8_C( 112),  INT8_C(  41),  INT8_C(  69),  INT8_C(  62), -INT8_C(  52) },
       INT8_C(   7),
      {  INT8_C( 105),  INT8_C( 105),  INT8_C( 105),  INT8_C( 105),  INT8_C( 105),  INT8_C( 105),  INT8_C( 105),  INT8_C( 105),
         INT8_C( 105),  INT8_C( 105),  INT8_C( 105),  INT8_C( 105),  INT8_C( 105),  INT8_C( 105),  INT8_C( 105),  INT8_C( 105) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16_t vec;
    simde_int8x16_t r;

    vec = simde_vld1q_s8(test_vec[i].vec);
    SIMDE_CONSTIFY_16_(simde_vdupq_laneq_s8, r, (HEDLEY_UNREACHABLE(), simde_vdupq_n_s8(INT8_C(0))), test_vec[i].lane, vec);

    simde_test_arm_neon_assert_equal_i8x16(r, simde_vld1q_s8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x16_t vec = simde_test_arm_neon_random_i8x16();
    int lane = simde_test_codegen_random_i8() & 15;

    simde_int8x16_t r;
    SIMDE_CONSTIFY_16_(simde_vdupq_laneq_s8, r, (HEDLEY_UNREACHABLE(), simde_vdupq_n_s8(INT8_C(0))), lane, vec);

    simde_test_arm_neon_write_i8x16(2, vec, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i8(2, HEDLEY_STATIC_CAST(int8_t, lane), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vdupq_laneq_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int16_t vec[8];
    int lane;
    int16_t r[8];
  } test_vec[] = {
    { { -INT16_C(  8889),  INT16_C( 24443),  INT16_C(   569),  INT16_C( 26326), -INT16_C(  1387), -INT16_C(  9757),  INT16_C(  9655),  INT16_C( 20241) },
       INT8_C(   3),
      {  INT16_C( 26326),  INT16_C( 26326),  INT16_C( 26326),  INT16_C( 26326),  INT16_C( 26326),  INT16_C( 26326),  INT16_C( 26326),  INT16_C( 26326) } },
    { { -INT16_C( 12152),  INT16_C( 20751), -INT16_C(  4039),  INT16_C( 30654), -INT16_C(  6272), -INT16_C( 16452),  INT16_C( 21427), -INT16_C( 28410) },
       INT8_C(   6),
      {  INT16_C( 21427),  INT16_C( 21427),  INT16_C( 21427),  INT16_C( 21427),  INT16_C( 21427),  INT16_C( 21427),  INT16_C( 21427),  INT16_C( 21427) } },
    { { -INT16_C( 13723),  INT16_C( 15313),  INT16_C( 26161),  INT16_C(  5173), -INT16_C(  4800),  INT16_C( 20793),  INT16_C( 27964),  INT16_C(  3289) },
       INT8_C(   4),
      { -INT16_C(  4800), -INT16_C(  4800), -INT16_C(  4800), -INT16_C(  4800), -INT16_C(  4800), -INT16_C(  4800), -INT16_C(  4800), -INT16_C(  4800) } },
    { {  INT16_C( 17707), -INT16_C(  5780), -INT16_C(  4932),  INT16_C( 30928), -INT16_C( 31829), -INT16_C( 19765), -INT16_C( 26092), -INT16_C(  8425) },
       INT8_C(   3),
      {  INT16_C( 30928),  INT16_C( 30928),  INT16_C( 30928),  INT16_C( 30928),  INT16_C( 30928),  INT16_C( 30928),  INT16_C( 30928),  INT16_C( 30928) } },
    { {  INT16_C(  4179), -INT16_C( 30511),  INT16_C(  4388),  INT16_C( 24181), -INT16_C( 19869),  INT16_C( 15563),  INT16_C( 18366),  INT16_C(  1127) },
       INT8_C(   3),
      {  INT16_C( 24181),  INT16_C( 24181),  INT16_C( 24181),  INT16_C( 24181),  INT16_C( 24181),  INT16_C( 24181),  INT16_C( 24181),  INT16_C( 24181) } },
    { { -INT16_C( 16304),  INT16_C(  8351),  INT16_C( 19257),  INT16_C(  1188), -INT16_C( 18179),  INT16_C(  5278),  INT16_C(  2455), -INT16_C( 22681) },
       INT8_C(   3),
      {  INT16_C(  1188),  INT16_C(  1188),  INT16_C(  1188),  INT16_C(  1188),  INT16_C(  1188),  INT16_C(  1188),  INT16_C(  1188),  INT16_C(  1188) } },
    { { -INT16_C( 13072),  INT16_C( 26092),  INT16_C( 20266), -INT16_C(  2793), -INT16_C( 10612), -INT16_C(  3268), -INT16_C(  4134), -INT16_C( 26044) },
       INT8_C(   6),
      { -INT16_C(  4134), -INT16_C(  4134), -INT16_C(  4134), -INT16_C(  4134), -INT16_C(  4134), -INT16_C(  4134), -INT16_C(  4134), -INT16_C(  4134) } },
    { { -INT16_C( 11420),  INT16_C(  2265), -INT16_C( 10536),  INT16_C( 30401),  INT16_C( 22763),  INT16_C( 21120),  INT16_C( 23296), -INT16_C( 13246) },
       INT8_C(   7),
      { -INT16_C( 13246), -INT16_C( 13246), -INT16_C( 13246), -INT16_C( 13246), -INT16_C( 13246), -INT16_C( 13246), -INT16_C( 13246), -INT16_C( 13246) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t vec;
    simde_int16x8_t r;

    vec = simde_vld1q_s16(test_vec[i].vec);
    SIMDE_CONSTIFY_8_(simde_vdupq_laneq_s16, r, (HEDLEY_UNREACHABLE(), simde_vdupq_n_s16(INT16_C(0))), test_vec[i].lane, vec);

    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x8_t vec = simde_test_arm_neon_random_i16x8();
    int lane = simde_test_codegen_random_i8() & 7;

    simde_int16x8_t r;
    SIMDE_CONSTIFY_8_(simde_vdupq_laneq_s16, r, (HEDLEY_UNREACHABLE(), simde_vdupq_n_s16(INT8_C(0))), lane, vec);

    simde_test_arm_neon_write_i16x8(2, vec, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i8(2, HEDLEY_STATIC_CAST(int8_t, lane), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vdupq_laneq_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int32_t vec[4];
    int lane;
    int32_t r[4];
  } test_vec[] = {
    { { -INT32_C(   520769284),  INT32_C(  1690121648),  INT32_C(  2059620000), -INT32_C(   175160556) },
       INT8_C(   1),
      {  INT32_C(  1690121648),  INT32_C(  1690121648),  INT32_C(  1690121648),  INT32_C(  1690121648) } },
    { {  INT32_C(  1145289614),  INT32_C(  1995152945),  INT32_C(  1451618795),  INT32_C(  1381122466) },
       INT8_C(   2),
      {  INT32_C(  1451618795),  INT32_C(  1451618795),  INT32_C(  1451618795),  INT32_C(  1451618795) } },
    { { -INT32_C(   278199502),  INT32_C(   725486439),  INT32_C(   342774405),  INT32_C(    44179271) },
       INT8_C(   2),
      {  INT32_C(   342774405),  INT32_C(   342774405),  INT32_C(   342774405),  INT32_C(   342774405) } },
    { { -INT32_C(   771738649),  INT32_C(   801369002), -INT32_C(  1804573119), -INT32_C(  1144609096) },
       INT8_C(   2),
      { -INT32_C(  1804573119), -INT32_C(  1804573119), -INT32_C(  1804573119), -INT32_C(  1804573119) } },
    { { -INT32_C(   199416906), -INT32_C(  1136221362),  INT32_C(  1524338103), -INT32_C(  1019134577) },
       INT8_C(   1),
      { -INT32_C(  1136221362), -INT32_C(  1136221362), -INT32_C(  1136221362), -INT32_C(  1136221362) } },
    { { -INT32_C(   701993709),  INT32_C(   205286044), -INT32_C(   994904578), -INT32_C(   746928976) },
       INT8_C(   2),
      { -INT32_C(   994904578), -INT32_C(   994904578), -INT32_C(   994904578), -INT32_C(   994904578) } },
    { { -INT32_C(  1266343570), -INT32_C(  1203684131), -INT32_C(   671755882),  INT32_C(    32125588) },
       INT8_C(   3),
      {  INT32_C(    32125588),  INT32_C(    32125588),  INT32_C(    32125588),  INT32_C(    32125588) } },
    { { -INT32_C(    37380671),  INT32_C(  1542636457),  INT32_C(    35693447), -INT32_C(  1737489802) },
       INT8_C(   3),
      { -INT32_C(  1737489802), -INT32_C(  1737489802), -INT32_C(  1737489802), -INT32_C(  1737489802) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t vec;
    simde_int32x4_t r;

    vec = simde_vld1q_s32(test_vec[i].vec);
    SIMDE_CONSTIFY_4_(simde_vdupq_laneq_s32, r, (HEDLEY_UNREACHABLE(), simde_vdupq_n_s32(INT32_C(0))), test_vec[i].lane, vec);

    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x4_t vec = simde_test_arm_neon_random_i32x4();
    int lane = simde_test_codegen_random_i8() & 3;

    simde_int32x4_t r;
    SIMDE_CONSTIFY_4_(simde_vdupq_laneq_s32, r, (HEDLEY_UNREACHABLE(), simde_vdupq_n_s32(INT32_C(0))), lane, vec);

    simde_test_arm_neon_write_i32x4(2, vec, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i8(2, HEDLEY_STATIC_CAST(int8_t, lane), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vdupq_laneq_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int64_t vec[2];
    int lane;
    int64_t r[2];
  } test_vec[] = {
    { { -INT64_C( 8011933124795626931), -INT64_C( 8152842150656023044) },
       INT8_C(   0),
      { -INT64_C( 8011933124795626931), -INT64_C( 8011933124795626931) } },
    { {  INT64_C( 3685999757973111283), -INT64_C( 5386610080087765761) },
       INT8_C(   1),
      { -INT64_C( 5386610080087765761), -INT64_C( 5386610080087765761) } },
    { { -INT64_C( 2623861853923575070),  INT64_C( 2913445673781549215) },
       INT8_C(   1),
      {  INT64_C( 2913445673781549215),  INT64_C( 2913445673781549215) } },
    { {  INT64_C( 8091307841519511702), -INT64_C( 6617296750713834230) },
       INT8_C(   0),
      {  INT64_C( 8091307841519511702),  INT64_C( 8091307841519511702) } },
    { {  INT64_C( 3479766334596526043),  INT64_C( 4763859366259699991) },
       INT8_C(   0),
      {  INT64_C( 3479766334596526043),  INT64_C( 3479766334596526043) } },
    { { -INT64_C( 6333786973713146150), -INT64_C( 7553910520906202330) },
       INT8_C(   0),
      { -INT64_C( 6333786973713146150), -INT64_C( 6333786973713146150) } },
    { { -INT64_C( 6513945781748522339), -INT64_C( 7760827274264939690) },
       INT8_C(   0),
      { -INT64_C( 6513945781748522339), -INT64_C( 6513945781748522339) } },
    { { -INT64_C( 2932731163502779536), -INT64_C( 1373296300908956888) },
       INT8_C(   1),
      { -INT64_C( 1373296300908956888), -INT64_C( 1373296300908956888) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t vec;
    simde_int64x2_t r;

    vec = simde_vld1q_s64(test_vec[i].vec);
    SIMDE_CONSTIFY_2_(simde_vdupq_laneq_s64, r, (HEDLEY_UNREACHABLE(), simde_vdupq_n_s64(INT64_C(0))), test_vec[i].lane, vec);

    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int64x2_t vec = simde_test_arm_neon_random_i64x2();
    int lane = simde_test_codegen_random_i8() & 1;

    simde_int64x2_t r;
    SIMDE_CONSTIFY_2_(simde_vdupq_laneq_s64, r, (HEDLEY_UNREACHABLE(), simde_vdupq_n_s64(INT64_C(0))), lane, vec);

    simde_test_arm_neon_write_i64x2(2, vec, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i8(2, HEDLEY_STATIC_CAST(int8_t, lane), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vdupq_laneq_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint8_t vec[16];
    int lane;
    uint8_t r[16];
  } test_vec[] = {
    { { UINT8_C(217), UINT8_C(190), UINT8_C(155), UINT8_C(115), UINT8_C(100), UINT8_C(241), UINT8_C(230), UINT8_C(170),
        UINT8_C( 99), UINT8_C(156), UINT8_C(170), UINT8_C(175), UINT8_C( 49), UINT8_C(127), UINT8_C( 31), UINT8_C( 20) },
      UINT8_C(  1),
      { UINT8_C(190), UINT8_C(190), UINT8_C(190), UINT8_C(190), UINT8_C(190), UINT8_C(190), UINT8_C(190), UINT8_C(190),
        UINT8_C(190), UINT8_C(190), UINT8_C(190), UINT8_C(190), UINT8_C(190), UINT8_C(190), UINT8_C(190), UINT8_C(190) } },
    { { UINT8_C(168), UINT8_C(159), UINT8_C( 10), UINT8_C(244), UINT8_C(119), UINT8_C( 50), UINT8_C(168), UINT8_C(109),
        UINT8_C(134), UINT8_C(242), UINT8_C(127), UINT8_C(120), UINT8_C(223), UINT8_C( 74), UINT8_C( 81), UINT8_C(157) },
      UINT8_C(  5),
      { UINT8_C( 50), UINT8_C( 50), UINT8_C( 50), UINT8_C( 50), UINT8_C( 50), UINT8_C( 50), UINT8_C( 50), UINT8_C( 50),
        UINT8_C( 50), UINT8_C( 50), UINT8_C( 50), UINT8_C( 50), UINT8_C( 50), UINT8_C( 50), UINT8_C( 50), UINT8_C( 50) } },
    { { UINT8_C(196), UINT8_C(  1), UINT8_C(215), UINT8_C(171), UINT8_C(171), UINT8_C( 58), UINT8_C( 71), UINT8_C( 86),
        UINT8_C(234), UINT8_C(120), UINT8_C(213), UINT8_C(  9), UINT8_C(140), UINT8_C(  6), UINT8_C(178), UINT8_C( 44) },
      UINT8_C(  0),
      { UINT8_C(196), UINT8_C(196), UINT8_C(196), UINT8_C(196), UINT8_C(196), UINT8_C(196), UINT8_C(196), UINT8_C(196),
        UINT8_C(196), UINT8_C(196), UINT8_C(196), UINT8_C(196), UINT8_C(196), UINT8_C(196), UINT8_C(196), UINT8_C(196) } },
    { { UINT8_C(166), UINT8_C(163), UINT8_C( 67), UINT8_C( 78), UINT8_C( 16), UINT8_C(201), UINT8_C( 65), UINT8_C(143),
        UINT8_C( 65), UINT8_C( 32), UINT8_C(217), UINT8_C(147), UINT8_C(189), UINT8_C(190), UINT8_C( 87), UINT8_C(191) },
      UINT8_C(  5),
      { UINT8_C(201), UINT8_C(201), UINT8_C(201), UINT8_C(201), UINT8_C(201), UINT8_C(201), UINT8_C(201), UINT8_C(201),
        UINT8_C(201), UINT8_C(201), UINT8_C(201), UINT8_C(201), UINT8_C(201), UINT8_C(201), UINT8_C(201), UINT8_C(201) } },
    { { UINT8_C(  2), UINT8_C(106), UINT8_C(208), UINT8_C( 74), UINT8_C(192), UINT8_C(186), UINT8_C(194), UINT8_C(149),
        UINT8_C(195), UINT8_C( 79), UINT8_C(156), UINT8_C(117), UINT8_C(123), UINT8_C(172), UINT8_C( 28), UINT8_C( 30) },
      UINT8_C( 15),
      { UINT8_C( 30), UINT8_C( 30), UINT8_C( 30), UINT8_C( 30), UINT8_C( 30), UINT8_C( 30), UINT8_C( 30), UINT8_C( 30),
        UINT8_C( 30), UINT8_C( 30), UINT8_C( 30), UINT8_C( 30), UINT8_C( 30), UINT8_C( 30), UINT8_C( 30), UINT8_C( 30) } },
    { { UINT8_C(106), UINT8_C( 46), UINT8_C(185), UINT8_C(171), UINT8_C(189), UINT8_C(250), UINT8_C(203), UINT8_C(150),
        UINT8_C(141), UINT8_C(137), UINT8_C( 84), UINT8_C(229), UINT8_C( 72), UINT8_C(234), UINT8_C(231), UINT8_C(178) },
      UINT8_C( 10),
      { UINT8_C( 84), UINT8_C( 84), UINT8_C( 84), UINT8_C( 84), UINT8_C( 84), UINT8_C( 84), UINT8_C( 84), UINT8_C( 84),
        UINT8_C( 84), UINT8_C( 84), UINT8_C( 84), UINT8_C( 84), UINT8_C( 84), UINT8_C( 84), UINT8_C( 84), UINT8_C( 84) } },
    { { UINT8_C( 49), UINT8_C(115), UINT8_C(116), UINT8_C(244), UINT8_C(  8), UINT8_C( 55), UINT8_C( 67), UINT8_C(164),
        UINT8_C(173), UINT8_C(190), UINT8_C( 81), UINT8_C(201), UINT8_C(220), UINT8_C( 64), UINT8_C( 51), UINT8_C( 10) },
      UINT8_C(  9),
      { UINT8_C(190), UINT8_C(190), UINT8_C(190), UINT8_C(190), UINT8_C(190), UINT8_C(190), UINT8_C(190), UINT8_C(190),
        UINT8_C(190), UINT8_C(190), UINT8_C(190), UINT8_C(190), UINT8_C(190), UINT8_C(190), UINT8_C(190), UINT8_C(190) } },
    { { UINT8_C(223), UINT8_C(199), UINT8_C(244), UINT8_C(170), UINT8_C( 93), UINT8_C(129), UINT8_C( 51), UINT8_C(177),
        UINT8_C(102), UINT8_C(123), UINT8_C(155), UINT8_C( 78), UINT8_C( 46), UINT8_C( 85), UINT8_C(127), UINT8_C(161) },
      UINT8_C(  9),
      { UINT8_C(123), UINT8_C(123), UINT8_C(123), UINT8_C(123), UINT8_C(123), UINT8_C(123), UINT8_C(123), UINT8_C(123),
        UINT8_C(123), UINT8_C(123), UINT8_C(123), UINT8_C(123), UINT8_C(123), UINT8_C(123), UINT8_C(123), UINT8_C(123) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x16_t vec;
    simde_uint8x16_t r;

    vec = simde_vld1q_u8(test_vec[i].vec);
    SIMDE_CONSTIFY_16_(simde_vdupq_laneq_u8, r, (HEDLEY_UNREACHABLE(), simde_vdupq_n_u8(UINT8_C(0))), test_vec[i].lane, vec);

    simde_test_arm_neon_assert_equal_u8x16(r, simde_vld1q_u8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8x16_t vec = simde_test_arm_neon_random_u8x16();
    int lane = simde_test_codegen_random_u8() & 15;

    simde_uint8x16_t r;
    SIMDE_CONSTIFY_16_(simde_vdupq_laneq_u8, r, (HEDLEY_UNREACHABLE(), simde_vdupq_n_u8(UINT8_C(0))), lane, vec);

    simde_test_arm_neon_write_u8x16(2, vec, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u8(2, HEDLEY_STATIC_CAST(uint8_t, lane), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vdupq_laneq_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint16_t vec[8];
    int lane;
    uint16_t r[8];
  } test_vec[] = {
    { { UINT16_C(12576), UINT16_C(38673), UINT16_C(17857), UINT16_C(51906), UINT16_C(60712), UINT16_C(20918), UINT16_C(54013), UINT16_C(47959) },
      UINT8_C(  1),
      { UINT16_C(38673), UINT16_C(38673), UINT16_C(38673), UINT16_C(38673), UINT16_C(38673), UINT16_C(38673), UINT16_C(38673), UINT16_C(38673) } },
    { { UINT16_C(58637), UINT16_C(48422), UINT16_C(47041), UINT16_C(59773), UINT16_C(22510), UINT16_C(58503), UINT16_C(20626), UINT16_C(49924) },
      UINT8_C(  2),
      { UINT16_C(47041), UINT16_C(47041), UINT16_C(47041), UINT16_C(47041), UINT16_C(47041), UINT16_C(47041), UINT16_C(47041), UINT16_C(47041) } },
    { { UINT16_C(33947), UINT16_C(24231), UINT16_C(53326), UINT16_C( 1099), UINT16_C(18465), UINT16_C(31190), UINT16_C(53251), UINT16_C(59782) },
      UINT8_C(  6),
      { UINT16_C(53251), UINT16_C(53251), UINT16_C(53251), UINT16_C(53251), UINT16_C(53251), UINT16_C(53251), UINT16_C(53251), UINT16_C(53251) } },
    { { UINT16_C(43587), UINT16_C(49582), UINT16_C(40083), UINT16_C( 6680), UINT16_C(43648), UINT16_C(34154), UINT16_C(52334), UINT16_C(61984) },
      UINT8_C(  4),
      { UINT16_C(43648), UINT16_C(43648), UINT16_C(43648), UINT16_C(43648), UINT16_C(43648), UINT16_C(43648), UINT16_C(43648), UINT16_C(43648) } },
    { { UINT16_C(16766), UINT16_C(51524), UINT16_C(25925), UINT16_C( 7185), UINT16_C( 5598), UINT16_C(26092), UINT16_C(58110), UINT16_C(43176) },
      UINT8_C(  0),
      { UINT16_C(16766), UINT16_C(16766), UINT16_C(16766), UINT16_C(16766), UINT16_C(16766), UINT16_C(16766), UINT16_C(16766), UINT16_C(16766) } },
    { { UINT16_C(15209), UINT16_C(33325), UINT16_C(44373), UINT16_C(48940), UINT16_C(39474), UINT16_C(21388), UINT16_C(  141), UINT16_C(52945) },
      UINT8_C(  4),
      { UINT16_C(39474), UINT16_C(39474), UINT16_C(39474), UINT16_C(39474), UINT16_C(39474), UINT16_C(39474), UINT16_C(39474), UINT16_C(39474) } },
    { { UINT16_C( 5019), UINT16_C(44201), UINT16_C(34863), UINT16_C( 7105), UINT16_C(49133), UINT16_C(38398), UINT16_C(36455), UINT16_C(41727) },
      UINT8_C(  3),
      { UINT16_C( 7105), UINT16_C( 7105), UINT16_C( 7105), UINT16_C( 7105), UINT16_C( 7105), UINT16_C( 7105), UINT16_C( 7105), UINT16_C( 7105) } },
    { { UINT16_C(63361), UINT16_C(44393), UINT16_C(39863), UINT16_C(17224), UINT16_C(54766), UINT16_C(49219), UINT16_C(34723), UINT16_C(46683) },
      UINT8_C(  0),
      { UINT16_C(63361), UINT16_C(63361), UINT16_C(63361), UINT16_C(63361), UINT16_C(63361), UINT16_C(63361), UINT16_C(63361), UINT16_C(63361) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t vec;
    simde_uint16x8_t r;

    vec = simde_vld1q_u16(test_vec[i].vec);
    SIMDE_CONSTIFY_8_(simde_vdupq_laneq_u16, r, (HEDLEY_UNREACHABLE(), simde_vdupq_n_u16(UINT16_C(0))), test_vec[i].lane, vec);

    simde_test_arm_neon_assert_equal_u16x8(r, simde_vld1q_u16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x8_t vec = simde_test_arm_neon_random_u16x8();
    int lane = simde_test_codegen_random_u8() & 7;

    simde_uint16x8_t r;
    SIMDE_CONSTIFY_8_(simde_vdupq_laneq_u16, r, (HEDLEY_UNREACHABLE(), simde_vdupq_n_u16(UINT16_C(0))), lane, vec);

    simde_test_arm_neon_write_u16x8(2, vec, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u8(2, HEDLEY_STATIC_CAST(uint8_t, lane), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vdupq_laneq_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint32_t vec[4];
    int lane;
    uint32_t r[4];
  } test_vec[] = {
    { { UINT32_C(3384337927), UINT32_C(4287145217), UINT32_C( 982446139), UINT32_C(2327529874) },
      UINT8_C(  2),
      { UINT32_C( 982446139), UINT32_C( 982446139), UINT32_C( 982446139), UINT32_C( 982446139) } },
    { { UINT32_C(2957918568), UINT32_C(3347397764), UINT32_C(1464740092), UINT32_C(3311369951) },
      UINT8_C(  3),
      { UINT32_C(3311369951), UINT32_C(3311369951), UINT32_C(3311369951), UINT32_C(3311369951) } },
    { { UINT32_C(2967258664), UINT32_C(1419777990), UINT32_C( 211628881), UINT32_C(4269101245) },
      UINT8_C(  2),
      { UINT32_C( 211628881), UINT32_C( 211628881), UINT32_C( 211628881), UINT32_C( 211628881) } },
    { { UINT32_C(2883224101), UINT32_C(2547242825), UINT32_C(2367009326), UINT32_C(1052068983) },
      UINT8_C(  1),
      { UINT32_C(2547242825), UINT32_C(2547242825), UINT32_C(2547242825), UINT32_C(2547242825) } },
    { { UINT32_C( 104858726), UINT32_C(4114190936), UINT32_C( 323352222), UINT32_C(1983505396) },
      UINT8_C(  2),
      { UINT32_C( 323352222), UINT32_C( 323352222), UINT32_C( 323352222), UINT32_C( 323352222) } },
    { { UINT32_C(3080044516), UINT32_C(1818936150), UINT32_C( 112779601), UINT32_C( 594338079) },
      UINT8_C(  2),
      { UINT32_C( 112779601), UINT32_C( 112779601), UINT32_C( 112779601), UINT32_C( 112779601) } },
    { { UINT32_C(2897509235), UINT32_C(3064156785), UINT32_C(2677708646), UINT32_C(3447937038) },
      UINT8_C(  1),
      { UINT32_C(3064156785), UINT32_C(3064156785), UINT32_C(3064156785), UINT32_C(3064156785) } },
    { { UINT32_C(2763007034), UINT32_C(1216741776), UINT32_C(1948951816), UINT32_C(1156009161) },
      UINT8_C(  0),
      { UINT32_C(2763007034), UINT32_C(2763007034), UINT32_C(2763007034), UINT32_C(2763007034) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t vec;
    simde_uint32x4_t r;

    vec = simde_vld1q_u32(test_vec[i].vec);
    SIMDE_CONSTIFY_4_(simde_vdupq_laneq_u32, r, (HEDLEY_UNREACHABLE(), simde_vdupq_n_u32(UINT32_C(0))), test_vec[i].lane, vec);

    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x4_t vec = simde_test_arm_neon_random_u32x4();
    int lane = simde_test_codegen_random_u8() & 3;

    simde_uint32x4_t r;
    SIMDE_CONSTIFY_4_(simde_vdupq_laneq_u32, r, (HEDLEY_UNREACHABLE(), simde_vdupq_n_u32(UINT32_C(0))), lane, vec);

    simde_test_arm_neon_write_u32x4(2, vec, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u8(2, HEDLEY_STATIC_CAST(uint8_t, lane), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vdupq_laneq_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint64_t vec[2];
    int lane;
    uint64_t r[2];
  } test_vec[] = {
    { { UINT64_C(  490532184354108820), UINT64_C(14849858543504251991) },
      UINT8_C(  1),
      { UINT64_C(14849858543504251991), UINT64_C(14849858543504251991) } },
    { { UINT64_C(15052443541152030393), UINT64_C(12174668995002936953) },
      UINT8_C(  1),
      { UINT64_C(12174668995002936953), UINT64_C(12174668995002936953) } },
    { { UINT64_C( 8707568158386885676), UINT64_C(12477432015999959385) },
      UINT8_C(  1),
      { UINT64_C(12477432015999959385), UINT64_C(12477432015999959385) } },
    { { UINT64_C( 4682118690185958247), UINT64_C(12230875630775692699) },
      UINT8_C(  1),
      { UINT64_C(12230875630775692699), UINT64_C(12230875630775692699) } },
    { { UINT64_C(18306794091455890358), UINT64_C( 6830403770862296378) },
      UINT8_C(  0),
      { UINT64_C(18306794091455890358), UINT64_C(18306794091455890358) } },
    { { UINT64_C( 2305295186427806230), UINT64_C(18379435529598636957) },
      UINT8_C(  1),
      { UINT64_C(18379435529598636957), UINT64_C(18379435529598636957) } },
    { { UINT64_C(17584683220473821853), UINT64_C(17625863477911098554) },
      UINT8_C(  1),
      { UINT64_C(17625863477911098554), UINT64_C(17625863477911098554) } },
    { { UINT64_C(13924499850132829868), UINT64_C(12883094807028726044) },
      UINT8_C(  1),
      { UINT64_C(12883094807028726044), UINT64_C(12883094807028726044) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x2_t vec;
    simde_uint64x2_t r;

    vec = simde_vld1q_u64(test_vec[i].vec);
    SIMDE_CONSTIFY_2_(simde_vdupq_laneq_u64, r, (HEDLEY_UNREACHABLE(), simde_vdupq_n_u64(UINT64_C(0))), test_vec[i].lane, vec);

    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint64x2_t vec = simde_test_arm_neon_random_u64x2();
    int lane = simde_test_codegen_random_u8() & 1;

    simde_uint64x2_t r;
    SIMDE_CONSTIFY_2_(simde_vdupq_laneq_u64, r, (HEDLEY_UNREACHABLE(), simde_vdupq_n_u64(UINT64_C(0))), lane, vec);

    simde_test_arm_neon_write_u64x2(2, vec, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u8(2, HEDLEY_STATIC_CAST(uint8_t, lane), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vdupb_lane_s8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int8_t vec[8];
    int lane;
    int8_t r;
  } test_vec[] = {
    { { -INT8_C(    6),  INT8_C(   22),  INT8_C(   58), -INT8_C(   92),
         INT8_C(  121),  INT8_C(   93), -INT8_C(   10),  INT8_C(   62) },
         INT8_C(    1),
         INT8_C(   22) },
    { { -INT8_C(   43),  INT8_C(   32),  INT8_C(  112),  INT8_C(   80),
        -INT8_C(  113),  INT8_C(   26), -INT8_C(   29),  INT8_C(   47) },
         INT8_C(    5),
         INT8_C(   26) },
    { { -INT8_C(   48),  INT8_C(   93),  INT8_C(  100), -INT8_C(   12),
        -INT8_C(   80),       INT8_MAX, -INT8_C(   30),  INT8_C(   44) },
         INT8_C(    2),
         INT8_C(  100) },
    { { -INT8_C(   27), -INT8_C(    8),  INT8_C(  114), -INT8_C(   15),
         INT8_C(   46), -INT8_C(  109), -INT8_C(   26), -INT8_C(   30) },
         INT8_C(    5),
        -INT8_C(  109) },
    { {  INT8_C(    2), -INT8_C(   54), -INT8_C(   28), -INT8_C(   91),
        -INT8_C(  124), -INT8_C(    8), -INT8_C(   11), -INT8_C(    7) },
         INT8_C(    1),
        -INT8_C(   54) },
    { { -INT8_C(  116), -INT8_C(   18), -INT8_C(   81),       INT8_MIN,
        -INT8_C(   94), -INT8_C(   46), -INT8_C(   76), -INT8_C(  112) },
         INT8_C(    0),
        -INT8_C(  116) },
    { {  INT8_C(   70), -INT8_C(   42),  INT8_C(   16), -INT8_C(   27),
        -INT8_C(   63),  INT8_C(   98),  INT8_C(   72),  INT8_C(  118) },
         INT8_C(    7),
         INT8_C(  118) },
    { {  INT8_C(   20),  INT8_C(  112),  INT8_C(   20),  INT8_C(   86),
        -INT8_C(  109),  INT8_C(   68), -INT8_C(   59), -INT8_C(   74) },
         INT8_C(    0),
         INT8_C(   20) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8_t vec;
    int8_t r;

    vec = simde_vld1_s8(test_vec[i].vec);
    SIMDE_CONSTIFY_8_(simde_vdupb_lane_s8, r, (HEDLEY_UNREACHABLE(), r), test_vec[i].lane, vec);

    simde_assert_equal_i8(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_vdupb_lane_u8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint8_t vec[8];
    int lane;
    uint8_t r;
  } test_vec[] = {
    { {  UINT8_C(  245),  UINT8_C(  152),  UINT8_C(  217),  UINT8_C(  115),
         UINT8_C(  189),  UINT8_C(   37),  UINT8_C(   12),  UINT8_C(   69) },
         INT8_C(    5),
         UINT8_C(   37) },
    { {  UINT8_C(  146),  UINT8_C(    7),  UINT8_C(   39),  UINT8_C(  222),
         UINT8_C(   39),  UINT8_C(   52),  UINT8_C(  207),  UINT8_C(   93) },
         INT8_C(    6),
         UINT8_C(  207) },
    { {  UINT8_C(   13),  UINT8_C(  222),  UINT8_C(  153),  UINT8_C(  154),
         UINT8_C(   83),  UINT8_C(  234),  UINT8_C(  231),  UINT8_C(  167) },
         INT8_C(    2),
         UINT8_C(  153) },
    { {  UINT8_C(  237),  UINT8_C(   29),  UINT8_C(   92),  UINT8_C(  102),
         UINT8_C(  201),  UINT8_C(  218),  UINT8_C(  157),  UINT8_C(   12) },
         INT8_C(    3),
         UINT8_C(  102) },
    { {  UINT8_C(  192),  UINT8_C(  129),  UINT8_C(   63),  UINT8_C(  115),
         UINT8_C(   84),  UINT8_C(  168),  UINT8_C(   30),  UINT8_C(  160) },
         INT8_C(    2),
         UINT8_C(   63) },
    { {  UINT8_C(    8),  UINT8_C(   36),  UINT8_C(   69),  UINT8_C(  227),
         UINT8_C(  208),  UINT8_C(  249),  UINT8_C(  155),  UINT8_C(   39) },
         INT8_C(    3),
         UINT8_C(  227) },
    { {  UINT8_C(  183),  UINT8_C(  108),  UINT8_C(  232),  UINT8_C(   74),
         UINT8_C(  219),  UINT8_C(  191),  UINT8_C(  213),  UINT8_C(  189) },
         INT8_C(    4),
         UINT8_C(  219) },
    { {  UINT8_C(  191),  UINT8_C(  213),  UINT8_C(  107),  UINT8_C(   79),
         UINT8_C(  123),  UINT8_C(   18),  UINT8_C(  115),  UINT8_C(   30) },
         INT8_C(    7),
         UINT8_C(   30) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x8_t vec;
    uint8_t r;

    vec = simde_vld1_u8(test_vec[i].vec);
    SIMDE_CONSTIFY_8_(simde_vdupb_lane_u8, r, (HEDLEY_UNREACHABLE(), r), test_vec[i].lane, vec);

    simde_assert_equal_u8(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_vdupb_laneq_s8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int8_t vec[16];
    int lane;
    int8_t r;
  } test_vec[] = {
    { { -INT8_C(   81),  INT8_C(   85), -INT8_C(   87),  INT8_C(   27),
         INT8_C(   25),  INT8_C(   21), -INT8_C(   50), -INT8_C(  110),
        -INT8_C(   81),  INT8_C(   15),  INT8_C(   93), -INT8_C(   78),
         INT8_C(   28),  INT8_C(  120), -INT8_C(   97), -INT8_C(   22) },
         INT8_C(    0),
        -INT8_C(   81) },
    { { -INT8_C(   38),  INT8_C(   85), -INT8_C(   26), -INT8_C(  121),
        -INT8_C(   88), -INT8_C(  104), -INT8_C(  114),  INT8_C(   69),
        -INT8_C(  106),  INT8_C(  126), -INT8_C(   55), -INT8_C(   14),
         INT8_C(   43), -INT8_C(  110), -INT8_C(    6),  INT8_C(   30) },
         INT8_C(    3),
        -INT8_C(  121) },
    { { -INT8_C(  104),  INT8_C(   64),  INT8_C(    8), -INT8_C(   49),
        -INT8_C(  126),  INT8_C(   98),  INT8_C(   47), -INT8_C(   63),
         INT8_C(   60),  INT8_C(   53),  INT8_C(   67), -INT8_C(   99),
        -INT8_C(   13),  INT8_C(   60), -INT8_C(  119),  INT8_C(  101) },
         INT8_C(    7),
        -INT8_C(   63) },
    { { -INT8_C(  105),  INT8_C(   46), -INT8_C(   13),  INT8_C(   66),
         INT8_C(   34),  INT8_C(   84), -INT8_C(   82),       INT8_MIN,
        -INT8_C(   36),  INT8_C(   10),  INT8_C(  116),  INT8_C(   71),
         INT8_C(  109), -INT8_C(   48), -INT8_C(   99),  INT8_C(  121) },
         INT8_C(   13),
        -INT8_C(   48) },
    { {  INT8_C(  104),  INT8_C(   54), -INT8_C(   13), -INT8_C(   58),
         INT8_C(  108),  INT8_C(   62),  INT8_C(   85),  INT8_C(   36),
         INT8_C(   20),  INT8_C(   80), -INT8_C(   43),  INT8_C(   17),
         INT8_C(  107), -INT8_C(   73),  INT8_C(   86),  INT8_C(   12) },
         INT8_C(   10),
        -INT8_C(   43) },
    { {  INT8_C(   44), -INT8_C(   56), -INT8_C(   26),  INT8_C(   11),
        -INT8_C(  104), -INT8_C(   43), -INT8_C(  101),  INT8_C(   30),
        -INT8_C(  127),  INT8_C(   39),  INT8_C(   46),  INT8_C(   28),
         INT8_C(   70), -INT8_C(    1),  INT8_C(   68),  INT8_C(   43) },
         INT8_C(    9),
         INT8_C(   39) },
    { { -INT8_C(   97), -INT8_C(   28), -INT8_C(   16), -INT8_C(  118),
        -INT8_C(   36), -INT8_C(   17), -INT8_C(   69),  INT8_C(   14),
         INT8_C(   88),  INT8_C(   87),  INT8_C(   78),  INT8_C(   61),
        -INT8_C(   21), -INT8_C(   66), -INT8_C(   82),  INT8_C(   32) },
         INT8_C(   15),
         INT8_C(   32) },
    { { -INT8_C(   81),  INT8_C(   11),  INT8_C(   25),       INT8_MIN,
         INT8_C(   93), -INT8_C(  117), -INT8_C(  122), -INT8_C(   23),
        -INT8_C(   44),  INT8_C(   56),  INT8_C(   92),  INT8_C(   24),
         INT8_C(    5),  INT8_C(   93), -INT8_C(   30),  INT8_C(  106) },
         INT8_C(    2),
         INT8_C(   25) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16_t vec;
    int8_t r;

    vec = simde_vld1q_s8(test_vec[i].vec);
    SIMDE_CONSTIFY_16_(simde_vdupb_laneq_s8, r, (HEDLEY_UNREACHABLE(), r), test_vec[i].lane, vec);

    simde_assert_equal_i8(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_vdupb_laneq_u8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint8_t vec[16];
    int lane;
    uint8_t r;
  } test_vec[] = {
    { {  UINT8_C(  230),  UINT8_C(  105),  UINT8_C(   26),  UINT8_C(   81),
         UINT8_C(  175),  UINT8_C(  144),  UINT8_C(    9),  UINT8_C(    6),
         UINT8_C(  171),  UINT8_C(  109),  UINT8_C(   10),  UINT8_C(   73),
         UINT8_C(   22),  UINT8_C(  189),  UINT8_C(  109),  UINT8_C(  140) },
         INT8_C(    5),
         UINT8_C(  144) },
    { {  UINT8_C(  134),  UINT8_C(   16),  UINT8_C(   81),  UINT8_C(  181),
         UINT8_C(  235),  UINT8_C(  108),  UINT8_C(  194),  UINT8_C(  104),
         UINT8_C(   39),  UINT8_C(   27),  UINT8_C(   77),  UINT8_C(  166),
         UINT8_C(   84),  UINT8_C(    4),  UINT8_C(  241),  UINT8_C(   49) },
         INT8_C(   15),
         UINT8_C(   49) },
    { {  UINT8_C(  173),  UINT8_C(  189),  UINT8_C(  113),  UINT8_C(  153),
         UINT8_C(  208),  UINT8_C(   68),  UINT8_C(   23),  UINT8_C(   78),
         UINT8_C(   21),  UINT8_C(   52),  UINT8_C(  245),  UINT8_C(  231),
         UINT8_C(  164),  UINT8_C(  246),  UINT8_C(  168),  UINT8_C(   56) },
         INT8_C(    3),
         UINT8_C(  153) },
    { {  UINT8_C(  186),  UINT8_C(  192),  UINT8_C(  204),  UINT8_C(  154),
         UINT8_C(  169),  UINT8_C(  191),  UINT8_C(  155),  UINT8_C(   14),
         UINT8_C(  224),  UINT8_C(    6),  UINT8_C(    4),  UINT8_C(   24),
         UINT8_C(  153),  UINT8_C(   96),  UINT8_C(   78),  UINT8_C(  110) },
         INT8_C(   11),
         UINT8_C(   24) },
    { {  UINT8_C(  194),  UINT8_C(  160),  UINT8_C(   34),  UINT8_C(  117),
         UINT8_C(  228),  UINT8_C(  135),  UINT8_C(   95),  UINT8_C(  203),
         UINT8_C(   94),  UINT8_C(   71),  UINT8_C(  148),  UINT8_C(  106),
         UINT8_C(  154),  UINT8_C(  119),  UINT8_C(  115),  UINT8_C(   74) },
         INT8_C(   10),
         UINT8_C(  148) },
    { {  UINT8_C(  129),  UINT8_C(   92),  UINT8_C(   35),  UINT8_C(  238),
         UINT8_C(  100),  UINT8_C(  192),  UINT8_C(   44),  UINT8_C(   66),
         UINT8_C(  100),  UINT8_C(  173),  UINT8_C(   43),  UINT8_C(  196),
         UINT8_C(   89),  UINT8_C(   66),  UINT8_C(    8),  UINT8_C(   35) },
         INT8_C(    0),
         UINT8_C(  129) },
    { {  UINT8_C(  237),  UINT8_C(   71),  UINT8_C(   85),  UINT8_C(  176),
         UINT8_C(  103),  UINT8_C(   42),  UINT8_C(   20),  UINT8_C(   78),
         UINT8_C(  133),  UINT8_C(   99),  UINT8_C(  179),  UINT8_C(  133),
         UINT8_C(  225),  UINT8_C(  199),  UINT8_C(   61),  UINT8_C(   92) },
         INT8_C(    2),
         UINT8_C(   85) },
    { {  UINT8_C(  129),  UINT8_C(  143),  UINT8_C(   98),  UINT8_C(   58),
         UINT8_C(   41),  UINT8_C(   58),  UINT8_C(  160),  UINT8_C(  153),
         UINT8_C(  211),  UINT8_C(  206),  UINT8_C(  192),  UINT8_C(  193),
         UINT8_C(    3),  UINT8_C(  112),  UINT8_C(   10),  UINT8_C(  242) },
         INT8_C(    6),
         UINT8_C(  160) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x16_t vec;
    uint8_t r;

    vec = simde_vld1q_u8(test_vec[i].vec);
    SIMDE_CONSTIFY_16_(simde_vdupb_laneq_u8, r, (HEDLEY_UNREACHABLE(), r), test_vec[i].lane, vec);

    simde_assert_equal_u8(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_vduph_lane_s16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int16_t vec[4];
    int lane;
    int16_t r;
  } test_vec[] = {
    { { -INT16_C( 32364), -INT16_C( 27766),  INT16_C( 32295), -INT16_C(  8820) },
         INT16_C(     3),
        -INT16_C(  8820) },
    { { -INT16_C( 19602),  INT16_C( 30329),  INT16_C( 21611), -INT16_C( 28237) },
         INT16_C(     2),
         INT16_C( 21611) },
    { { -INT16_C( 23618), -INT16_C( 16445), -INT16_C( 29678), -INT16_C( 26686) },
         INT16_C(     2),
        -INT16_C( 29678) },
    { {  INT16_C( 27900),  INT16_C( 27945),  INT16_C( 27136),  INT16_C( 16565) },
         INT16_C(     1),
         INT16_C( 27945) },
    { { -INT16_C( 10370),  INT16_C(  7345),  INT16_C( 14065),  INT16_C( 31674) },
         INT16_C(     1),
         INT16_C(  7345) },
    { {  INT16_C(  8735), -INT16_C(  3470),  INT16_C(  8583),  INT16_C( 15639) },
         INT16_C(     1),
        -INT16_C(  3470) },
    { { -INT16_C(  2313),  INT16_C( 29982), -INT16_C( 30579), -INT16_C( 13355) },
         INT16_C(     3),
        -INT16_C( 13355) },
    { {  INT16_C(  2096), -INT16_C( 13330),  INT16_C(  8548),  INT16_C( 30697) },
         INT16_C(     0),
         INT16_C(  2096) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t vec;
    int16_t r;

    vec = simde_vld1_s16(test_vec[i].vec);
    SIMDE_CONSTIFY_4_(simde_vduph_lane_s16, r, (HEDLEY_UNREACHABLE(), r), test_vec[i].lane, vec);

    simde_assert_equal_i16(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_vduph_lane_u16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint16_t vec[4];
    int lane;
    uint16_t r;
  } test_vec[] = {
    { {  UINT16_C( 27436),  UINT16_C( 60731),  UINT16_C(  8131),  UINT16_C( 63274) },
         INT16_C(     0),
         UINT16_C( 27436) },
    { {  UINT16_C( 23538),  UINT16_C( 46099),  UINT16_C( 42839),  UINT16_C( 32144) },
         INT16_C(     0),
         UINT16_C( 23538) },
    { {  UINT16_C( 10649),  UINT16_C( 33779),  UINT16_C( 23462),  UINT16_C( 17951) },
         INT16_C(     1),
         UINT16_C( 33779) },
    { {  UINT16_C( 42321),  UINT16_C( 16328),  UINT16_C( 44735),  UINT16_C( 59999) },
         INT16_C(     1),
         UINT16_C( 16328) },
    { {  UINT16_C( 33534),  UINT16_C( 12727),  UINT16_C( 29464),  UINT16_C( 10589) },
         INT16_C(     2),
         UINT16_C( 29464) },
    { {  UINT16_C( 10963),  UINT16_C(  2733),  UINT16_C( 58099),  UINT16_C( 44876) },
         INT16_C(     3),
         UINT16_C( 44876) },
    { {  UINT16_C( 20112),  UINT16_C( 48793),  UINT16_C(  5269),  UINT16_C( 51155) },
         INT16_C(     3),
         UINT16_C( 51155) },
    { {  UINT16_C( 26801),  UINT16_C( 16635),  UINT16_C( 35849),  UINT16_C( 59673) },
         INT16_C(     0),
         UINT16_C( 26801) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4_t vec;
    uint16_t r;

    vec = simde_vld1_u16(test_vec[i].vec);
    SIMDE_CONSTIFY_4_(simde_vduph_lane_u16, r, (HEDLEY_UNREACHABLE(), r), test_vec[i].lane, vec);

    simde_assert_equal_u16(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_vduph_laneq_s16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int16_t vec[8];
    int lane;
    int16_t r;
  } test_vec[] = {
    { { -INT16_C( 27448),  INT16_C(  7315), -INT16_C( 15454),  INT16_C(  4876),
        -INT16_C(  6152),  INT16_C( 32348), -INT16_C(  4649),  INT16_C( 11094) },
         INT16_C(     2),
        -INT16_C( 15454) },
    { {  INT16_C( 24808), -INT16_C( 16321),  INT16_C(  7443), -INT16_C( 23487),
         INT16_C( 27539),  INT16_C( 28433),  INT16_C(  5801),  INT16_C( 24300) },
         INT16_C(     7),
         INT16_C( 24300) },
    { { -INT16_C( 24159), -INT16_C( 14810),  INT16_C(  5377), -INT16_C( 27922),
        -INT16_C(  8087),  INT16_C( 21479), -INT16_C(  8386),  INT16_C( 24539) },
         INT16_C(     5),
         INT16_C( 21479) },
    { { -INT16_C( 21390),  INT16_C( 30591), -INT16_C( 24678), -INT16_C( 13566),
        -INT16_C( 11521),  INT16_C( 13063), -INT16_C(  8067),  INT16_C( 17412) },
         INT16_C(     7),
         INT16_C( 17412) },
    { {  INT16_C(  7029),  INT16_C( 20823), -INT16_C(  5873), -INT16_C( 26867),
         INT16_C( 32479), -INT16_C( 13865), -INT16_C( 10191),  INT16_C(  9114) },
         INT16_C(     7),
         INT16_C(  9114) },
    { {  INT16_C( 25189),  INT16_C( 26494), -INT16_C(  1728),  INT16_C(  3820),
        -INT16_C( 10450), -INT16_C(  7705), -INT16_C( 24060),  INT16_C(  9431) },
         INT16_C(     4),
        -INT16_C( 10450) },
    { { -INT16_C( 29176),  INT16_C(  1011),  INT16_C(  4305),  INT16_C( 16580),
         INT16_C(  8168), -INT16_C( 17556),  INT16_C(  2493),  INT16_C( 25370) },
         INT16_C(     7),
         INT16_C( 25370) },
    { { -INT16_C( 13653), -INT16_C(   260),  INT16_C( 11874), -INT16_C(  9851),
        -INT16_C( 15286),  INT16_C( 18725),  INT16_C(  2033), -INT16_C( 16194) },
         INT16_C(     0),
        -INT16_C( 13653) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t vec;
    int16_t r;

    vec = simde_vld1q_s16(test_vec[i].vec);
    SIMDE_CONSTIFY_8_(simde_vduph_laneq_s16, r, (HEDLEY_UNREACHABLE(), r), test_vec[i].lane, vec);

    simde_assert_equal_i16(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_vduph_laneq_u16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint16_t vec[8];
    int lane;
    uint16_t r;
  } test_vec[] = {
    { {  UINT16_C( 15983),  UINT16_C( 56340),  UINT16_C( 41900),  UINT16_C( 44873),
         UINT16_C( 39576),  UINT16_C( 42863),  UINT16_C( 31470),  UINT16_C( 48193) },
         INT16_C(     3),
         UINT16_C( 44873) },
    { {  UINT16_C( 29237),  UINT16_C( 19036),  UINT16_C( 53654),  UINT16_C( 35746),
         UINT16_C( 15558),  UINT16_C( 48185),  UINT16_C( 38846),  UINT16_C( 14970) },
         INT16_C(     4),
         UINT16_C( 15558) },
    { {  UINT16_C( 56312),  UINT16_C( 59570),  UINT16_C(  1856),  UINT16_C( 32492),
         UINT16_C( 35792),  UINT16_C( 36746),  UINT16_C( 56904),  UINT16_C( 57449) },
         INT16_C(     3),
         UINT16_C( 32492) },
    { {  UINT16_C( 26550),  UINT16_C( 57975),  UINT16_C( 28715),  UINT16_C(  9461),
         UINT16_C( 14739),  UINT16_C(  7381),  UINT16_C( 13735),  UINT16_C( 57602) },
         INT16_C(     4),
         UINT16_C( 14739) },
    { {  UINT16_C(  7907),  UINT16_C( 45875),  UINT16_C( 23382),  UINT16_C( 10376),
         UINT16_C(  1011),  UINT16_C( 53925),  UINT16_C( 53567),  UINT16_C( 46732) },
         INT16_C(     6),
         UINT16_C( 53567) },
    { {  UINT16_C( 40039),  UINT16_C( 41066),  UINT16_C( 24856),  UINT16_C( 11213),
         UINT16_C(  2899),  UINT16_C( 34256),  UINT16_C( 43679),  UINT16_C( 11070) },
         INT16_C(     7),
         UINT16_C( 11070) },
    { {  UINT16_C( 40970),  UINT16_C( 46568),  UINT16_C( 14501),  UINT16_C( 14957),
         UINT16_C( 30816),  UINT16_C( 14508),  UINT16_C( 13380),  UINT16_C( 15393) },
         INT16_C(     5),
         UINT16_C( 14508) },
    { {  UINT16_C( 28157),  UINT16_C( 40057),  UINT16_C( 10679),  UINT16_C(  7851),
         UINT16_C(  3390),  UINT16_C( 41690),  UINT16_C( 45346),  UINT16_C( 12049) },
         INT16_C(     0),
         UINT16_C( 28157) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t vec;
    uint16_t r;

    vec = simde_vld1q_u16(test_vec[i].vec);
    SIMDE_CONSTIFY_8_(simde_vduph_laneq_u16, r, (HEDLEY_UNREACHABLE(), r), test_vec[i].lane, vec);

    simde_assert_equal_u16(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_vduph_lane_f16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float16_t vec[4];
    int lane;
    simde_float16_t r;
  } test_vec[] = {
    { {  SIMDE_FLOAT16_VALUE(-3.387),  SIMDE_FLOAT16_VALUE(-9.632),  SIMDE_FLOAT16_VALUE(19.992),  SIMDE_FLOAT16_VALUE( 1.837) },
         INT16_C(     0),
         SIMDE_FLOAT16_VALUE(-3.387) },
    { {  SIMDE_FLOAT16_VALUE(26.430),  SIMDE_FLOAT16_VALUE(28.640),  SIMDE_FLOAT16_VALUE(-21.270),  SIMDE_FLOAT16_VALUE(-10.357) },
         INT16_C(     0),
         SIMDE_FLOAT16_VALUE(26.430) },
    { {  SIMDE_FLOAT16_VALUE(24.992),  SIMDE_FLOAT16_VALUE( 2.837),  SIMDE_FLOAT16_VALUE( 1.880),  SIMDE_FLOAT16_VALUE( 1.855) },
         INT16_C(     1),
         SIMDE_FLOAT16_VALUE( 2.837) },
    { {  SIMDE_FLOAT16_VALUE(-15.363),  SIMDE_FLOAT16_VALUE(-5.167),  SIMDE_FLOAT16_VALUE( 4.732),  SIMDE_FLOAT16_VALUE(-14.807) },
         INT16_C(     3),
         SIMDE_FLOAT16_VALUE(-14.807) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x4_t vec;
    simde_float16_t r;

    vec = simde_vld1_f16(test_vec[i].vec);
    SIMDE_CONSTIFY_4_(simde_vduph_lane_f16, r, (HEDLEY_UNREACHABLE(), r), test_vec[i].lane, vec);

    simde_assert_equal_f16(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_vduph_laneq_f16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float16_t vec[8];
    int lane;
    simde_float16_t r;
  } test_vec[] = {
    { {  SIMDE_FLOAT16_VALUE(-3.387),  SIMDE_FLOAT16_VALUE(-9.632),  SIMDE_FLOAT16_VALUE(19.992),  SIMDE_FLOAT16_VALUE( 1.837),
         SIMDE_FLOAT16_VALUE(10.218),  SIMDE_FLOAT16_VALUE( 0.924),  SIMDE_FLOAT16_VALUE(28.548),  SIMDE_FLOAT16_VALUE(10.866) },
         INT16_C(     0),
         SIMDE_FLOAT16_VALUE(-3.387) },
    { {  SIMDE_FLOAT16_VALUE(26.430),  SIMDE_FLOAT16_VALUE(28.640),  SIMDE_FLOAT16_VALUE(-21.270),  SIMDE_FLOAT16_VALUE(-10.357),
         SIMDE_FLOAT16_VALUE( 0.986),  SIMDE_FLOAT16_VALUE(-14.685),  SIMDE_FLOAT16_VALUE(27.090),  SIMDE_FLOAT16_VALUE(16.825) },
         INT16_C(     0),
         SIMDE_FLOAT16_VALUE(26.430) },
    { {  SIMDE_FLOAT16_VALUE(24.992),  SIMDE_FLOAT16_VALUE( 2.837),  SIMDE_FLOAT16_VALUE( 1.880),  SIMDE_FLOAT16_VALUE( 1.855),
         SIMDE_FLOAT16_VALUE(-26.001),  SIMDE_FLOAT16_VALUE(25.433),  SIMDE_FLOAT16_VALUE(-25.054),  SIMDE_FLOAT16_VALUE(-18.612) },
         INT16_C(     1),
         SIMDE_FLOAT16_VALUE( 2.837) },
    { {  SIMDE_FLOAT16_VALUE(-24.460),  SIMDE_FLOAT16_VALUE(-22.313),  SIMDE_FLOAT16_VALUE(-17.405),  SIMDE_FLOAT16_VALUE( 7.420),
         SIMDE_FLOAT16_VALUE(-9.492),  SIMDE_FLOAT16_VALUE(-28.099),  SIMDE_FLOAT16_VALUE(-25.166),  SIMDE_FLOAT16_VALUE(-23.800) },
         INT16_C(     5),
         SIMDE_FLOAT16_VALUE(-28.099) },
    { {  SIMDE_FLOAT16_VALUE(-20.270),  SIMDE_FLOAT16_VALUE(-10.763),  SIMDE_FLOAT16_VALUE(-20.068),  SIMDE_FLOAT16_VALUE( 1.744),
         SIMDE_FLOAT16_VALUE( 4.890),  SIMDE_FLOAT16_VALUE(-28.985),  SIMDE_FLOAT16_VALUE(-27.261),  SIMDE_FLOAT16_VALUE(-5.649) },
         INT16_C(     6),
         SIMDE_FLOAT16_VALUE(-27.261) },
    { {  SIMDE_FLOAT16_VALUE( 2.648),  SIMDE_FLOAT16_VALUE(-19.666),  SIMDE_FLOAT16_VALUE( 0.498),  SIMDE_FLOAT16_VALUE(-12.129),
         SIMDE_FLOAT16_VALUE(-6.541),  SIMDE_FLOAT16_VALUE(20.271),  SIMDE_FLOAT16_VALUE(11.576),  SIMDE_FLOAT16_VALUE(26.583) },
         INT16_C(     5),
         SIMDE_FLOAT16_VALUE(20.271) },
    { {  SIMDE_FLOAT16_VALUE(-15.363),  SIMDE_FLOAT16_VALUE(-5.167),  SIMDE_FLOAT16_VALUE( 4.732),  SIMDE_FLOAT16_VALUE(-14.807),
         SIMDE_FLOAT16_VALUE(13.136),  SIMDE_FLOAT16_VALUE(26.351),  SIMDE_FLOAT16_VALUE(15.240),  SIMDE_FLOAT16_VALUE(-21.142) },
         INT16_C(     3),
         SIMDE_FLOAT16_VALUE(-14.807) },
    { {  SIMDE_FLOAT16_VALUE(-22.512),  SIMDE_FLOAT16_VALUE(15.536),  SIMDE_FLOAT16_VALUE(-20.898),  SIMDE_FLOAT16_VALUE(-24.975),
         SIMDE_FLOAT16_VALUE(-28.439),  SIMDE_FLOAT16_VALUE(-28.696),  SIMDE_FLOAT16_VALUE(12.933),  SIMDE_FLOAT16_VALUE(20.260) },
         INT16_C(     7),
         SIMDE_FLOAT16_VALUE(20.260) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x8_t vec;
    simde_float16_t r;

    vec = simde_vld1q_f16(test_vec[i].vec);
    SIMDE_CONSTIFY_8_(simde_vduph_laneq_f16, r, (HEDLEY_UNREACHABLE(), r), test_vec[i].lane, vec);

    simde_assert_equal_f16(r, test_vec[i].r, INT_MAX);
  }

  return 0;
}

static int
test_simde_vdup_lane_p8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_poly8_t vec[8];
    int lane;
    simde_poly8_t r[8];
  } test_vec[] = {
    { { SIMDE_POLY8_C(225), SIMDE_POLY8_C( 70), SIMDE_POLY8_C(222), SIMDE_POLY8_C( 40), SIMDE_POLY8_C( 85), SIMDE_POLY8_C( 93), SIMDE_POLY8_C( 35), SIMDE_POLY8_C(172) },
      INT8_C(  6),
      { SIMDE_POLY8_C( 35), SIMDE_POLY8_C( 35), SIMDE_POLY8_C( 35), SIMDE_POLY8_C( 35), SIMDE_POLY8_C( 35), SIMDE_POLY8_C( 35), SIMDE_POLY8_C( 35), SIMDE_POLY8_C( 35) } },
    { { SIMDE_POLY8_C( 14), SIMDE_POLY8_C(104), SIMDE_POLY8_C(219), SIMDE_POLY8_C(190), SIMDE_POLY8_C( 18), SIMDE_POLY8_C( 59), SIMDE_POLY8_C(  6), SIMDE_POLY8_C(151) },
      INT8_C(  5),
      { SIMDE_POLY8_C( 59), SIMDE_POLY8_C( 59), SIMDE_POLY8_C( 59), SIMDE_POLY8_C( 59), SIMDE_POLY8_C( 59), SIMDE_POLY8_C( 59), SIMDE_POLY8_C( 59), SIMDE_POLY8_C( 59) } },
    { { SIMDE_POLY8_C( 86), SIMDE_POLY8_C(237), SIMDE_POLY8_C( 93), SIMDE_POLY8_C(114), SIMDE_POLY8_C(246), SIMDE_POLY8_C(234), SIMDE_POLY8_C(197), SIMDE_POLY8_C( 48) },
      INT8_C(  6),
      { SIMDE_POLY8_C(197), SIMDE_POLY8_C(197), SIMDE_POLY8_C(197), SIMDE_POLY8_C(197), SIMDE_POLY8_C(197), SIMDE_POLY8_C(197), SIMDE_POLY8_C(197), SIMDE_POLY8_C(197) } },
    { { SIMDE_POLY8_C(140), SIMDE_POLY8_C(105), SIMDE_POLY8_C(114), SIMDE_POLY8_C( 55), SIMDE_POLY8_C( 74), SIMDE_POLY8_C(184), SIMDE_POLY8_C( 21), SIMDE_POLY8_C(115) },
      INT8_C(  5),
      { SIMDE_POLY8_C(184), SIMDE_POLY8_C(184), SIMDE_POLY8_C(184), SIMDE_POLY8_C(184), SIMDE_POLY8_C(184), SIMDE_POLY8_C(184), SIMDE_POLY8_C(184), SIMDE_POLY8_C(184) } },
    { { SIMDE_POLY8_C(114), SIMDE_POLY8_C(150), SIMDE_POLY8_C(186), SIMDE_POLY8_C(200), SIMDE_POLY8_C(164), SIMDE_POLY8_C( 34), SIMDE_POLY8_C(164), SIMDE_POLY8_C( 98) },
      INT8_C(  4),
      { SIMDE_POLY8_C(164), SIMDE_POLY8_C(164), SIMDE_POLY8_C(164), SIMDE_POLY8_C(164), SIMDE_POLY8_C(164), SIMDE_POLY8_C(164), SIMDE_POLY8_C(164), SIMDE_POLY8_C(164) } },
    { { SIMDE_POLY8_C(223), SIMDE_POLY8_C(104), SIMDE_POLY8_C(203), SIMDE_POLY8_C( 12), SIMDE_POLY8_C(190), SIMDE_POLY8_C(184), SIMDE_POLY8_C(105), SIMDE_POLY8_C( 48) },
      INT8_C(  7),
      { SIMDE_POLY8_C( 48), SIMDE_POLY8_C( 48), SIMDE_POLY8_C( 48), SIMDE_POLY8_C( 48), SIMDE_POLY8_C( 48), SIMDE_POLY8_C( 48), SIMDE_POLY8_C( 48), SIMDE_POLY8_C( 48) } },
    { { SIMDE_POLY8_C( 84), SIMDE_POLY8_C(245), SIMDE_POLY8_C(223), SIMDE_POLY8_C(146), SIMDE_POLY8_C(130), SIMDE_POLY8_C( 73), SIMDE_POLY8_C(  4), SIMDE_POLY8_C(185) },
      INT8_C(  3),
      { SIMDE_POLY8_C(146), SIMDE_POLY8_C(146), SIMDE_POLY8_C(146), SIMDE_POLY8_C(146), SIMDE_POLY8_C(146), SIMDE_POLY8_C(146), SIMDE_POLY8_C(146), SIMDE_POLY8_C(146) } },
    { { SIMDE_POLY8_C(188), SIMDE_POLY8_C(206), SIMDE_POLY8_C(  6), SIMDE_POLY8_C(202), SIMDE_POLY8_C( 64), SIMDE_POLY8_C(157), SIMDE_POLY8_C(132), SIMDE_POLY8_C(  8) },
      INT8_C(  1),
      { SIMDE_POLY8_C(206), SIMDE_POLY8_C(206), SIMDE_POLY8_C(206), SIMDE_POLY8_C(206), SIMDE_POLY8_C(206), SIMDE_POLY8_C(206), SIMDE_POLY8_C(206), SIMDE_POLY8_C(206) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_poly8x8_t vec;
    simde_poly8x8_t r;

    vec = simde_vld1_p8(test_vec[i].vec);
    SIMDE_CONSTIFY_8_(simde_vdup_lane_p8, r, (HEDLEY_UNREACHABLE(), simde_vdup_n_p8(SIMDE_POLY8_C(0))), test_vec[i].lane, vec);

    simde_test_arm_neon_assert_equal_p8x8(r, simde_vld1_p8(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vdup_lane_p16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_poly16_t vec[4];
    int lane;
    simde_poly16_t r[4];
  } test_vec[] = {
    { { SIMDE_POLY16_C(39155), SIMDE_POLY16_C(17108), SIMDE_POLY16_C(35862), SIMDE_POLY16_C(33952) },
      SIMDE_POLY8_C(  0),
      { SIMDE_POLY16_C(39155), SIMDE_POLY16_C(39155), SIMDE_POLY16_C(39155), SIMDE_POLY16_C(39155) } },
    { { SIMDE_POLY16_C(25643), SIMDE_POLY16_C(65303), SIMDE_POLY16_C(24516), SIMDE_POLY16_C(25191) },
      SIMDE_POLY8_C(  2),
      { SIMDE_POLY16_C(24516), SIMDE_POLY16_C(24516), SIMDE_POLY16_C(24516), SIMDE_POLY16_C(24516) } },
    { { SIMDE_POLY16_C(41498), SIMDE_POLY16_C(10432), SIMDE_POLY16_C(25102), SIMDE_POLY16_C( 2461) },
      SIMDE_POLY8_C(  2),
      { SIMDE_POLY16_C(25102), SIMDE_POLY16_C(25102), SIMDE_POLY16_C(25102), SIMDE_POLY16_C(25102) } },
    { { SIMDE_POLY16_C(35666), SIMDE_POLY16_C(21432), SIMDE_POLY16_C(20862), SIMDE_POLY16_C(49191) },
      SIMDE_POLY8_C(  3),
      { SIMDE_POLY16_C(49191), SIMDE_POLY16_C(49191), SIMDE_POLY16_C(49191), SIMDE_POLY16_C(49191) } },
    { { SIMDE_POLY16_C(25011), SIMDE_POLY16_C(28908), SIMDE_POLY16_C(20620), SIMDE_POLY16_C(35719) },
      SIMDE_POLY8_C(  1),
      { SIMDE_POLY16_C(28908), SIMDE_POLY16_C(28908), SIMDE_POLY16_C(28908), SIMDE_POLY16_C(28908) } },
    { { SIMDE_POLY16_C(62439), SIMDE_POLY16_C(54647), SIMDE_POLY16_C( 6413), SIMDE_POLY16_C(13717) },
      SIMDE_POLY8_C(  0),
      { SIMDE_POLY16_C(62439), SIMDE_POLY16_C(62439), SIMDE_POLY16_C(62439), SIMDE_POLY16_C(62439) } },
    { { SIMDE_POLY16_C(54007), SIMDE_POLY16_C(11569), SIMDE_POLY16_C(48165), SIMDE_POLY16_C(30950) },
      SIMDE_POLY8_C(  3),
      { SIMDE_POLY16_C(30950), SIMDE_POLY16_C(30950), SIMDE_POLY16_C(30950), SIMDE_POLY16_C(30950) } },
    { { SIMDE_POLY16_C(41015), SIMDE_POLY16_C(40699), SIMDE_POLY16_C(23635), SIMDE_POLY16_C(50058) },
      SIMDE_POLY8_C(  1),
      { SIMDE_POLY16_C(40699), SIMDE_POLY16_C(40699), SIMDE_POLY16_C(40699), SIMDE_POLY16_C(40699) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_poly16x4_t vec;
    simde_poly16x4_t r;

    vec = simde_vld1_p16(test_vec[i].vec);
    SIMDE_CONSTIFY_4_(simde_vdup_lane_p16, r, (HEDLEY_UNREACHABLE(), simde_vdup_n_p16(SIMDE_POLY16_C(0))), test_vec[i].lane, vec);

    simde_test_arm_neon_assert_equal_p16x4(r, simde_vld1_p16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vdup_lane_p64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_poly64_t vec[1];
    simde_poly64_t r[1];
  } test_vec[] = {
    { { SIMDE_POLY64_C( 5426997122108201096) },
      { SIMDE_POLY64_C( 5426997122108201096) } },
    { { SIMDE_POLY64_C( 5080213220590762597) },
      { SIMDE_POLY64_C( 5080213220590762597) } },
    { { SIMDE_POLY64_C(  533322304534421141) },
      { SIMDE_POLY64_C(  533322304534421141) } },
    { { SIMDE_POLY64_C(14619170657803413946) },
      { SIMDE_POLY64_C(14619170657803413946) } },
    { { SIMDE_POLY64_C( 3151999422994724178) },
      { SIMDE_POLY64_C( 3151999422994724178) } },
    { { SIMDE_POLY64_C( 7902049161203633248) },
      { SIMDE_POLY64_C( 7902049161203633248) } },
    { { SIMDE_POLY64_C(12874740165647350485) },
      { SIMDE_POLY64_C(12874740165647350485) } },
    { { SIMDE_POLY64_C(16715255793253080045) },
      { SIMDE_POLY64_C(16715255793253080045) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_poly64x1_t vec;
    simde_poly64x1_t r;

    vec = simde_vld1_p64(test_vec[i].vec);
    r = simde_vdup_lane_p64(vec, 0);

    simde_test_arm_neon_assert_equal_p64x1(r, simde_vld1_p64(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vdup_laneq_p8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_poly8_t vec[16];
    int lane;
    simde_poly8_t r[8];
  } test_vec[] = {
    { { SIMDE_POLY8_C( 77), SIMDE_POLY8_C(147), SIMDE_POLY8_C( 62), SIMDE_POLY8_C(115), SIMDE_POLY8_C(118), SIMDE_POLY8_C( 11), SIMDE_POLY8_C( 79), SIMDE_POLY8_C(238),
        SIMDE_POLY8_C(216), SIMDE_POLY8_C( 18), SIMDE_POLY8_C(104), SIMDE_POLY8_C(180), SIMDE_POLY8_C(173), SIMDE_POLY8_C(197), SIMDE_POLY8_C(248), SIMDE_POLY8_C(124) },
      INT8_C( 15),
      { SIMDE_POLY8_C(124), SIMDE_POLY8_C(124), SIMDE_POLY8_C(124), SIMDE_POLY8_C(124), SIMDE_POLY8_C(124), SIMDE_POLY8_C(124), SIMDE_POLY8_C(124), SIMDE_POLY8_C(124) } },
    { { SIMDE_POLY8_C(115), SIMDE_POLY8_C(176), SIMDE_POLY8_C(  5), SIMDE_POLY8_C(172), SIMDE_POLY8_C(204), SIMDE_POLY8_C(177), SIMDE_POLY8_C(208), SIMDE_POLY8_C(120),
        SIMDE_POLY8_C(189), SIMDE_POLY8_C( 77), SIMDE_POLY8_C(208), SIMDE_POLY8_C( 85), SIMDE_POLY8_C( 21), SIMDE_POLY8_C( 46), SIMDE_POLY8_C(162), SIMDE_POLY8_C(168) },
      INT8_C( 12),
      { SIMDE_POLY8_C( 21), SIMDE_POLY8_C( 21), SIMDE_POLY8_C( 21), SIMDE_POLY8_C( 21), SIMDE_POLY8_C( 21), SIMDE_POLY8_C( 21), SIMDE_POLY8_C( 21), SIMDE_POLY8_C( 21) } },
    { { SIMDE_POLY8_C( 22), SIMDE_POLY8_C( 30), SIMDE_POLY8_C(119), SIMDE_POLY8_C(101), SIMDE_POLY8_C( 12), SIMDE_POLY8_C( 79), SIMDE_POLY8_C(119), SIMDE_POLY8_C(116),
        SIMDE_POLY8_C(  4), SIMDE_POLY8_C( 37), SIMDE_POLY8_C( 57), SIMDE_POLY8_C(252), SIMDE_POLY8_C(161), SIMDE_POLY8_C(233), SIMDE_POLY8_C(111), SIMDE_POLY8_C( 81) },
      INT8_C( 14),
      { SIMDE_POLY8_C(111), SIMDE_POLY8_C(111), SIMDE_POLY8_C(111), SIMDE_POLY8_C(111), SIMDE_POLY8_C(111), SIMDE_POLY8_C(111), SIMDE_POLY8_C(111), SIMDE_POLY8_C(111) } },
    { { SIMDE_POLY8_C( 28), SIMDE_POLY8_C( 30), SIMDE_POLY8_C(159), SIMDE_POLY8_C(236), SIMDE_POLY8_C(150), SIMDE_POLY8_C( 93), SIMDE_POLY8_C( 57), SIMDE_POLY8_C(102),
        SIMDE_POLY8_C(178), SIMDE_POLY8_C( 79), SIMDE_POLY8_C(148), SIMDE_POLY8_C( 85), SIMDE_POLY8_C(247), SIMDE_POLY8_C(  0), SIMDE_POLY8_C(107), SIMDE_POLY8_C( 22) },
      INT8_C(  7),
      { SIMDE_POLY8_C(102), SIMDE_POLY8_C(102), SIMDE_POLY8_C(102), SIMDE_POLY8_C(102), SIMDE_POLY8_C(102), SIMDE_POLY8_C(102), SIMDE_POLY8_C(102), SIMDE_POLY8_C(102) } },
    { { SIMDE_POLY8_C(208), SIMDE_POLY8_C( 34), SIMDE_POLY8_C(199), SIMDE_POLY8_C( 72), SIMDE_POLY8_C(151), SIMDE_POLY8_C(203), SIMDE_POLY8_C(109), SIMDE_POLY8_C(208),
        SIMDE_POLY8_C(199), SIMDE_POLY8_C( 14), SIMDE_POLY8_C(185), SIMDE_POLY8_C( 55), SIMDE_POLY8_C( 96), SIMDE_POLY8_C(167), SIMDE_POLY8_C( 83), SIMDE_POLY8_C(126) },
      INT8_C(  7),
      { SIMDE_POLY8_C(208), SIMDE_POLY8_C(208), SIMDE_POLY8_C(208), SIMDE_POLY8_C(208), SIMDE_POLY8_C(208), SIMDE_POLY8_C(208), SIMDE_POLY8_C(208), SIMDE_POLY8_C(208) } },
    { { SIMDE_POLY8_C( 63), SIMDE_POLY8_C( 20), SIMDE_POLY8_C(164), SIMDE_POLY8_C(120), SIMDE_POLY8_C(122), SIMDE_POLY8_C( 86), SIMDE_POLY8_C(199), SIMDE_POLY8_C( 14),
        SIMDE_POLY8_C(171), SIMDE_POLY8_C(191), SIMDE_POLY8_C( 14), SIMDE_POLY8_C( 22), SIMDE_POLY8_C(213), SIMDE_POLY8_C(133), SIMDE_POLY8_C(231), SIMDE_POLY8_C(247) },
      INT8_C( 12),
      { SIMDE_POLY8_C(213), SIMDE_POLY8_C(213), SIMDE_POLY8_C(213), SIMDE_POLY8_C(213), SIMDE_POLY8_C(213), SIMDE_POLY8_C(213), SIMDE_POLY8_C(213), SIMDE_POLY8_C(213) } },
    { { SIMDE_POLY8_C( 47), SIMDE_POLY8_C(142), SIMDE_POLY8_C( 23), SIMDE_POLY8_C(156), SIMDE_POLY8_C( 95), SIMDE_POLY8_C(223), SIMDE_POLY8_C(170), SIMDE_POLY8_C( 24),
        SIMDE_POLY8_C( 22), SIMDE_POLY8_C( 10), SIMDE_POLY8_C(192), SIMDE_POLY8_C(105), SIMDE_POLY8_C(136), SIMDE_POLY8_C(  7), SIMDE_POLY8_C(168), SIMDE_POLY8_C(156) },
      INT8_C( 11),
      { SIMDE_POLY8_C(105), SIMDE_POLY8_C(105), SIMDE_POLY8_C(105), SIMDE_POLY8_C(105), SIMDE_POLY8_C(105), SIMDE_POLY8_C(105), SIMDE_POLY8_C(105), SIMDE_POLY8_C(105) } },
    { { SIMDE_POLY8_C( 32), SIMDE_POLY8_C( 22), SIMDE_POLY8_C(  1), SIMDE_POLY8_C(232), SIMDE_POLY8_C( 36), SIMDE_POLY8_C(173), SIMDE_POLY8_C(167), SIMDE_POLY8_C( 50),
        SIMDE_POLY8_C(195), SIMDE_POLY8_C(124), SIMDE_POLY8_C(184), SIMDE_POLY8_C(170), SIMDE_POLY8_C(115), SIMDE_POLY8_C(  4), SIMDE_POLY8_C(217), SIMDE_POLY8_C(  2) },
      INT8_C( 12),
      { SIMDE_POLY8_C(115), SIMDE_POLY8_C(115), SIMDE_POLY8_C(115), SIMDE_POLY8_C(115), SIMDE_POLY8_C(115), SIMDE_POLY8_C(115), SIMDE_POLY8_C(115), SIMDE_POLY8_C(115) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_poly8x16_t vec;
    simde_poly8x8_t r;

    vec = simde_vld1q_p8(test_vec[i].vec);
    SIMDE_CONSTIFY_16_(simde_vdup_laneq_p8, r, (HEDLEY_UNREACHABLE(), simde_vdup_n_p8(SIMDE_POLY8_C(0))), test_vec[i].lane, vec);

    simde_test_arm_neon_assert_equal_p8x8(r, simde_vld1_p8(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vdup_laneq_p16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_poly16_t vec[8];
    int lane;
    simde_poly16_t r[4];
  } test_vec[] = {
    { { SIMDE_POLY16_C(24949), SIMDE_POLY16_C( 8443), SIMDE_POLY16_C( 4473), SIMDE_POLY16_C(14634), SIMDE_POLY16_C(45946), SIMDE_POLY16_C( 8768), SIMDE_POLY16_C(60239), SIMDE_POLY16_C(26178) },
      INT8_C(  5),
      { SIMDE_POLY16_C( 8768), SIMDE_POLY16_C( 8768), SIMDE_POLY16_C( 8768), SIMDE_POLY16_C( 8768) } },
    { { SIMDE_POLY16_C(35370), SIMDE_POLY16_C(53658), SIMDE_POLY16_C(23997), SIMDE_POLY16_C(30029), SIMDE_POLY16_C(49416), SIMDE_POLY16_C(57721), SIMDE_POLY16_C(38339), SIMDE_POLY16_C( 9303) },
      INT8_C(  0),
      { SIMDE_POLY16_C(35370), SIMDE_POLY16_C(35370), SIMDE_POLY16_C(35370), SIMDE_POLY16_C(35370) } },
    { { SIMDE_POLY16_C(40311), SIMDE_POLY16_C(41377), SIMDE_POLY16_C( 7127), SIMDE_POLY16_C( 5972), SIMDE_POLY16_C(42045), SIMDE_POLY16_C(32771), SIMDE_POLY16_C(61450), SIMDE_POLY16_C(38058) },
      INT8_C(  2),
      { SIMDE_POLY16_C( 7127), SIMDE_POLY16_C( 7127), SIMDE_POLY16_C( 7127), SIMDE_POLY16_C( 7127) } },
    { { SIMDE_POLY16_C(20860), SIMDE_POLY16_C(51687), SIMDE_POLY16_C(61382), SIMDE_POLY16_C(16522), SIMDE_POLY16_C(19921), SIMDE_POLY16_C(10453), SIMDE_POLY16_C(26225), SIMDE_POLY16_C( 3999) },
      INT8_C(  7),
      { SIMDE_POLY16_C( 3999), SIMDE_POLY16_C( 3999), SIMDE_POLY16_C( 3999), SIMDE_POLY16_C( 3999) } },
    { { SIMDE_POLY16_C(58944), SIMDE_POLY16_C(38179), SIMDE_POLY16_C(24829), SIMDE_POLY16_C(   57), SIMDE_POLY16_C(17376), SIMDE_POLY16_C(35824), SIMDE_POLY16_C(31447), SIMDE_POLY16_C(10503) },
      INT8_C(  2),
      { SIMDE_POLY16_C(24829), SIMDE_POLY16_C(24829), SIMDE_POLY16_C(24829), SIMDE_POLY16_C(24829) } },
    { { SIMDE_POLY16_C(61392), SIMDE_POLY16_C(23377), SIMDE_POLY16_C( 8751), SIMDE_POLY16_C( 1448), SIMDE_POLY16_C( 6730), SIMDE_POLY16_C(59755), SIMDE_POLY16_C(29225), SIMDE_POLY16_C( 3882) },
      INT8_C(  5),
      { SIMDE_POLY16_C(59755), SIMDE_POLY16_C(59755), SIMDE_POLY16_C(59755), SIMDE_POLY16_C(59755) } },
    { { SIMDE_POLY16_C( 3263), SIMDE_POLY16_C(63734), SIMDE_POLY16_C(54797), SIMDE_POLY16_C(64827), SIMDE_POLY16_C( 4705), SIMDE_POLY16_C(26744), SIMDE_POLY16_C(55867), SIMDE_POLY16_C(11065) },
      INT8_C(  3),
      { SIMDE_POLY16_C(64827), SIMDE_POLY16_C(64827), SIMDE_POLY16_C(64827), SIMDE_POLY16_C(64827) } },
    { { SIMDE_POLY16_C(23188), SIMDE_POLY16_C(15438), SIMDE_POLY16_C(39007), SIMDE_POLY16_C(51798), SIMDE_POLY16_C(32642), SIMDE_POLY16_C(44093), SIMDE_POLY16_C(53902), SIMDE_POLY16_C(39787) },
      INT8_C(  0),
      { SIMDE_POLY16_C(23188), SIMDE_POLY16_C(23188), SIMDE_POLY16_C(23188), SIMDE_POLY16_C(23188) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_poly16x8_t vec;
    simde_poly16x4_t r;

    vec = simde_vld1q_p16(test_vec[i].vec);
    SIMDE_CONSTIFY_8_(simde_vdup_laneq_p16, r, (HEDLEY_UNREACHABLE(), simde_vdup_n_p16(SIMDE_POLY16_C(0))), test_vec[i].lane, vec);

    simde_test_arm_neon_assert_equal_p16x4(r, simde_vld1_p16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vdup_laneq_p64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_poly64_t vec[2];
    int lane;
    simde_poly64_t r[1];
  } test_vec[] = {
    { { SIMDE_POLY64_C( 8110510466717951717), SIMDE_POLY64_C( 3572304598247984234) },
      SIMDE_POLY8_C(  0),
      { SIMDE_POLY64_C( 8110510466717951717) } },
    { { SIMDE_POLY64_C( 4366124917414247539), SIMDE_POLY64_C( 6918834943037648244) },
      SIMDE_POLY8_C(  0),
      { SIMDE_POLY64_C( 4366124917414247539) } },
    { { SIMDE_POLY64_C( 3292744983505054807), SIMDE_POLY64_C( 4117915127713221663) },
      SIMDE_POLY8_C(  0),
      { SIMDE_POLY64_C( 3292744983505054807) } },
    { { SIMDE_POLY64_C( 4698457210627404784), SIMDE_POLY64_C(18068255124800990820) },
      SIMDE_POLY8_C(  0),
      { SIMDE_POLY64_C( 4698457210627404784) } },
    { { SIMDE_POLY64_C(15070002321331591077), SIMDE_POLY64_C( 1022264726452052249) },
      SIMDE_POLY8_C(  0),
      { SIMDE_POLY64_C(15070002321331591077) } },
    { { SIMDE_POLY64_C( 2583179698698190518), SIMDE_POLY64_C( 4114481506476959668) },
      SIMDE_POLY8_C(  1),
      { SIMDE_POLY64_C( 4114481506476959668) } },
    { { SIMDE_POLY64_C(16551956027336260976), SIMDE_POLY64_C( 1981680721021243291) },
      SIMDE_POLY8_C(  1),
      { SIMDE_POLY64_C( 1981680721021243291) } },
    { { SIMDE_POLY64_C(17756356862603385451), SIMDE_POLY64_C( 4845139579135167924) },
      SIMDE_POLY8_C(  1),
      { SIMDE_POLY64_C( 4845139579135167924) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_poly64x2_t vec;
    simde_poly64x1_t r;

    vec = simde_vld1q_p64(test_vec[i].vec);
    SIMDE_CONSTIFY_2_(simde_vdup_laneq_p64, r, (HEDLEY_UNREACHABLE(), simde_vdup_n_p64(SIMDE_POLY64_C(0))), test_vec[i].lane, vec);

    simde_test_arm_neon_assert_equal_p64x1(r, simde_vld1_p64(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vdupq_lane_p8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_poly8_t vec[8];
    int lane;
    simde_poly8_t r[16];
  } test_vec[] = {
    { { SIMDE_POLY8_C(169), SIMDE_POLY8_C(207), SIMDE_POLY8_C( 64), SIMDE_POLY8_C(146), SIMDE_POLY8_C(157), SIMDE_POLY8_C(122), SIMDE_POLY8_C( 44), SIMDE_POLY8_C(  4) },
       INT8_C(   1),
      { SIMDE_POLY8_C(207), SIMDE_POLY8_C(207), SIMDE_POLY8_C(207), SIMDE_POLY8_C(207), SIMDE_POLY8_C(207), SIMDE_POLY8_C(207), SIMDE_POLY8_C(207), SIMDE_POLY8_C(207),
        SIMDE_POLY8_C(207), SIMDE_POLY8_C(207), SIMDE_POLY8_C(207), SIMDE_POLY8_C(207), SIMDE_POLY8_C(207), SIMDE_POLY8_C(207), SIMDE_POLY8_C(207), SIMDE_POLY8_C(207) } },
    { { SIMDE_POLY8_C(UINT8_MAX), SIMDE_POLY8_C(115), SIMDE_POLY8_C( 24), SIMDE_POLY8_C(113), SIMDE_POLY8_C( 78), SIMDE_POLY8_C(113), SIMDE_POLY8_C(246), SIMDE_POLY8_C( 13) },
       INT8_C(   7),
      { SIMDE_POLY8_C( 13), SIMDE_POLY8_C( 13), SIMDE_POLY8_C( 13), SIMDE_POLY8_C( 13), SIMDE_POLY8_C( 13), SIMDE_POLY8_C( 13), SIMDE_POLY8_C( 13), SIMDE_POLY8_C( 13),
        SIMDE_POLY8_C( 13), SIMDE_POLY8_C( 13), SIMDE_POLY8_C( 13), SIMDE_POLY8_C( 13), SIMDE_POLY8_C( 13), SIMDE_POLY8_C( 13), SIMDE_POLY8_C( 13), SIMDE_POLY8_C( 13) } },
    { { SIMDE_POLY8_C(236), SIMDE_POLY8_C(229), SIMDE_POLY8_C( 14), SIMDE_POLY8_C(230), SIMDE_POLY8_C(243), SIMDE_POLY8_C( 63), SIMDE_POLY8_C( 37), SIMDE_POLY8_C( 41) },
       INT8_C(   3),
      { SIMDE_POLY8_C(230), SIMDE_POLY8_C(230), SIMDE_POLY8_C(230), SIMDE_POLY8_C(230), SIMDE_POLY8_C(230), SIMDE_POLY8_C(230), SIMDE_POLY8_C(230), SIMDE_POLY8_C(230),
        SIMDE_POLY8_C(230), SIMDE_POLY8_C(230), SIMDE_POLY8_C(230), SIMDE_POLY8_C(230), SIMDE_POLY8_C(230), SIMDE_POLY8_C(230), SIMDE_POLY8_C(230), SIMDE_POLY8_C(230) } },
    { { SIMDE_POLY8_C(239), SIMDE_POLY8_C(141), SIMDE_POLY8_C(206), SIMDE_POLY8_C(146), SIMDE_POLY8_C( 54), SIMDE_POLY8_C(157), SIMDE_POLY8_C(210), SIMDE_POLY8_C(200) },
       INT8_C(   2),
      { SIMDE_POLY8_C(206), SIMDE_POLY8_C(206), SIMDE_POLY8_C(206), SIMDE_POLY8_C(206), SIMDE_POLY8_C(206), SIMDE_POLY8_C(206), SIMDE_POLY8_C(206), SIMDE_POLY8_C(206),
        SIMDE_POLY8_C(206), SIMDE_POLY8_C(206), SIMDE_POLY8_C(206), SIMDE_POLY8_C(206), SIMDE_POLY8_C(206), SIMDE_POLY8_C(206), SIMDE_POLY8_C(206), SIMDE_POLY8_C(206) } },
    { { SIMDE_POLY8_C( 77), SIMDE_POLY8_C(244), SIMDE_POLY8_C( 63), SIMDE_POLY8_C(142), SIMDE_POLY8_C(244), SIMDE_POLY8_C(178), SIMDE_POLY8_C(166), SIMDE_POLY8_C(101) },
       INT8_C(   1),
      { SIMDE_POLY8_C(244), SIMDE_POLY8_C(244), SIMDE_POLY8_C(244), SIMDE_POLY8_C(244), SIMDE_POLY8_C(244), SIMDE_POLY8_C(244), SIMDE_POLY8_C(244), SIMDE_POLY8_C(244),
        SIMDE_POLY8_C(244), SIMDE_POLY8_C(244), SIMDE_POLY8_C(244), SIMDE_POLY8_C(244), SIMDE_POLY8_C(244), SIMDE_POLY8_C(244), SIMDE_POLY8_C(244), SIMDE_POLY8_C(244) } },
    { { SIMDE_POLY8_C( 23), SIMDE_POLY8_C( 92), SIMDE_POLY8_C( 14), SIMDE_POLY8_C(246), SIMDE_POLY8_C( 72), SIMDE_POLY8_C(243), SIMDE_POLY8_C(  4), SIMDE_POLY8_C( 46) },
       INT8_C(   6),
      { SIMDE_POLY8_C(  4), SIMDE_POLY8_C(  4), SIMDE_POLY8_C(  4), SIMDE_POLY8_C(  4), SIMDE_POLY8_C(  4), SIMDE_POLY8_C(  4), SIMDE_POLY8_C(  4), SIMDE_POLY8_C(  4),
        SIMDE_POLY8_C(  4), SIMDE_POLY8_C(  4), SIMDE_POLY8_C(  4), SIMDE_POLY8_C(  4), SIMDE_POLY8_C(  4), SIMDE_POLY8_C(  4), SIMDE_POLY8_C(  4), SIMDE_POLY8_C(  4) } },
    { { SIMDE_POLY8_C( 67), SIMDE_POLY8_C( 83), SIMDE_POLY8_C( 16), SIMDE_POLY8_C(230), SIMDE_POLY8_C( 66), SIMDE_POLY8_C(157), SIMDE_POLY8_C(180), SIMDE_POLY8_C(212) },
       INT8_C(   3),
      { SIMDE_POLY8_C(230), SIMDE_POLY8_C(230), SIMDE_POLY8_C(230), SIMDE_POLY8_C(230), SIMDE_POLY8_C(230), SIMDE_POLY8_C(230), SIMDE_POLY8_C(230), SIMDE_POLY8_C(230),
        SIMDE_POLY8_C(230), SIMDE_POLY8_C(230), SIMDE_POLY8_C(230), SIMDE_POLY8_C(230), SIMDE_POLY8_C(230), SIMDE_POLY8_C(230), SIMDE_POLY8_C(230), SIMDE_POLY8_C(230) } },
    { { SIMDE_POLY8_C( 81), SIMDE_POLY8_C(167), SIMDE_POLY8_C(155), SIMDE_POLY8_C(140), SIMDE_POLY8_C(244), SIMDE_POLY8_C(144), SIMDE_POLY8_C(203), SIMDE_POLY8_C(130) },
       INT8_C(   4),
      { SIMDE_POLY8_C(244), SIMDE_POLY8_C(244), SIMDE_POLY8_C(244), SIMDE_POLY8_C(244), SIMDE_POLY8_C(244), SIMDE_POLY8_C(244), SIMDE_POLY8_C(244), SIMDE_POLY8_C(244),
        SIMDE_POLY8_C(244), SIMDE_POLY8_C(244), SIMDE_POLY8_C(244), SIMDE_POLY8_C(244), SIMDE_POLY8_C(244), SIMDE_POLY8_C(244), SIMDE_POLY8_C(244), SIMDE_POLY8_C(244) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_poly8x8_t vec;
    simde_poly8x16_t r;

    vec = simde_vld1_p8(test_vec[i].vec);
    SIMDE_CONSTIFY_8_(simde_vdupq_lane_p8, r, (HEDLEY_UNREACHABLE(), simde_vdupq_n_p8(0)), test_vec[i].lane, vec);

    simde_test_arm_neon_assert_equal_p8x16(r, simde_vld1q_p8(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vdupq_lane_p16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_poly16_t vec[4];
    int lane;
    simde_poly16_t r[8];
  } test_vec[] = {
    { { SIMDE_POLY16_C(42621), SIMDE_POLY16_C(14183), SIMDE_POLY16_C(32933), SIMDE_POLY16_C(43737) },
       INT8_C(   0),
      { SIMDE_POLY16_C(42621), SIMDE_POLY16_C(42621), SIMDE_POLY16_C(42621), SIMDE_POLY16_C(42621), SIMDE_POLY16_C(42621), SIMDE_POLY16_C(42621), SIMDE_POLY16_C(42621), SIMDE_POLY16_C(42621) } },
    { { SIMDE_POLY16_C(20803), SIMDE_POLY16_C( 9878), SIMDE_POLY16_C(64829), SIMDE_POLY16_C(53371) },
       INT8_C(   1),
      { SIMDE_POLY16_C( 9878), SIMDE_POLY16_C( 9878), SIMDE_POLY16_C( 9878), SIMDE_POLY16_C( 9878), SIMDE_POLY16_C( 9878), SIMDE_POLY16_C( 9878), SIMDE_POLY16_C( 9878), SIMDE_POLY16_C( 9878) } },
    { { SIMDE_POLY16_C(60523), SIMDE_POLY16_C(37693), SIMDE_POLY16_C(53354), SIMDE_POLY16_C(41286) },
       INT8_C(   3),
      { SIMDE_POLY16_C(41286), SIMDE_POLY16_C(41286), SIMDE_POLY16_C(41286), SIMDE_POLY16_C(41286), SIMDE_POLY16_C(41286), SIMDE_POLY16_C(41286), SIMDE_POLY16_C(41286), SIMDE_POLY16_C(41286) } },
    { { SIMDE_POLY16_C( 8692), SIMDE_POLY16_C(32507), SIMDE_POLY16_C(41630), SIMDE_POLY16_C(54757) },
       INT8_C(   3),
      { SIMDE_POLY16_C(54757), SIMDE_POLY16_C(54757), SIMDE_POLY16_C(54757), SIMDE_POLY16_C(54757), SIMDE_POLY16_C(54757), SIMDE_POLY16_C(54757), SIMDE_POLY16_C(54757), SIMDE_POLY16_C(54757) } },
    { { SIMDE_POLY16_C(44645), SIMDE_POLY16_C(34289), SIMDE_POLY16_C(17393), SIMDE_POLY16_C( 6172) },
       INT8_C(   0),
      { SIMDE_POLY16_C(44645), SIMDE_POLY16_C(44645), SIMDE_POLY16_C(44645), SIMDE_POLY16_C(44645), SIMDE_POLY16_C(44645), SIMDE_POLY16_C(44645), SIMDE_POLY16_C(44645), SIMDE_POLY16_C(44645) } },
    { { SIMDE_POLY16_C(37657), SIMDE_POLY16_C(33360), SIMDE_POLY16_C(15614), SIMDE_POLY16_C(37311) },
       INT8_C(   3),
      { SIMDE_POLY16_C(37311), SIMDE_POLY16_C(37311), SIMDE_POLY16_C(37311), SIMDE_POLY16_C(37311), SIMDE_POLY16_C(37311), SIMDE_POLY16_C(37311), SIMDE_POLY16_C(37311), SIMDE_POLY16_C(37311) } },
    { { SIMDE_POLY16_C(55439), SIMDE_POLY16_C(57928), SIMDE_POLY16_C(27084), SIMDE_POLY16_C(19166) },
       INT8_C(   3),
      { SIMDE_POLY16_C(19166), SIMDE_POLY16_C(19166), SIMDE_POLY16_C(19166), SIMDE_POLY16_C(19166), SIMDE_POLY16_C(19166), SIMDE_POLY16_C(19166), SIMDE_POLY16_C(19166), SIMDE_POLY16_C(19166) } },
    { { SIMDE_POLY16_C(12160), SIMDE_POLY16_C(51164), SIMDE_POLY16_C(35732), SIMDE_POLY16_C( 6584) },
       INT8_C(   0),
      { SIMDE_POLY16_C(12160), SIMDE_POLY16_C(12160), SIMDE_POLY16_C(12160), SIMDE_POLY16_C(12160), SIMDE_POLY16_C(12160), SIMDE_POLY16_C(12160), SIMDE_POLY16_C(12160), SIMDE_POLY16_C(12160) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_poly16x4_t vec;
    simde_poly16x8_t r;

    vec = simde_vld1_p16(test_vec[i].vec);
    SIMDE_CONSTIFY_4_(simde_vdupq_lane_p16, r, (HEDLEY_UNREACHABLE(), simde_vdupq_n_p16(0)), test_vec[i].lane, vec);

    simde_test_arm_neon_assert_equal_p16x8(r, simde_vld1q_p16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vdupq_lane_p64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_poly64_t vec[1];
    int lane;
    simde_poly64_t r[2];
  } test_vec[] = {
    { { SIMDE_POLY64_C(  455882935909149950) },
       INT8_C(   0),
      { SIMDE_POLY64_C(  455882935909149950), SIMDE_POLY64_C(  455882935909149950) } },
    { { SIMDE_POLY64_C(11933587015411218425) },
       INT8_C(   0),
      { SIMDE_POLY64_C(11933587015411218425), SIMDE_POLY64_C(11933587015411218425) } },
    { { SIMDE_POLY64_C(14838357478928476872) },
       INT8_C(   0),
      { SIMDE_POLY64_C(14838357478928476872), SIMDE_POLY64_C(14838357478928476872) } },
    { { SIMDE_POLY64_C(10410602884629015667) },
       INT8_C(   0),
      { SIMDE_POLY64_C(10410602884629015667), SIMDE_POLY64_C(10410602884629015667) } },
    { { SIMDE_POLY64_C(14047218565468644120) },
       INT8_C(   0),
      { SIMDE_POLY64_C(14047218565468644120), SIMDE_POLY64_C(14047218565468644120) } },
    { { SIMDE_POLY64_C(13486723040809934480) },
       INT8_C(   0),
      { SIMDE_POLY64_C(13486723040809934480), SIMDE_POLY64_C(13486723040809934480) } },
    { { SIMDE_POLY64_C(10194163952196691865) },
       INT8_C(   0),
      { SIMDE_POLY64_C(10194163952196691865), SIMDE_POLY64_C(10194163952196691865) } },
    { { SIMDE_POLY64_C( 4928221257128478300) },
       INT8_C(   0),
      { SIMDE_POLY64_C( 4928221257128478300), SIMDE_POLY64_C( 4928221257128478300) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_poly64x1_t vec;
    simde_poly64x2_t r;

    vec = simde_vld1_p64(test_vec[i].vec);
    r = simde_vdupq_lane_p64(vec, 0);

    simde_test_arm_neon_assert_equal_p64x2(r, simde_vld1q_p64(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vdupq_laneq_p8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_poly8_t vec[16];
    int lane;
    simde_poly8_t r[16];
  } test_vec[] = {
    { { SIMDE_POLY8_C(217), SIMDE_POLY8_C(190), SIMDE_POLY8_C(155), SIMDE_POLY8_C(115), SIMDE_POLY8_C(100), SIMDE_POLY8_C(241), SIMDE_POLY8_C(230), SIMDE_POLY8_C(170),
        SIMDE_POLY8_C( 99), SIMDE_POLY8_C(156), SIMDE_POLY8_C(170), SIMDE_POLY8_C(175), SIMDE_POLY8_C( 49), SIMDE_POLY8_C(127), SIMDE_POLY8_C( 31), SIMDE_POLY8_C( 20) },
      SIMDE_POLY8_C(  1),
      { SIMDE_POLY8_C(190), SIMDE_POLY8_C(190), SIMDE_POLY8_C(190), SIMDE_POLY8_C(190), SIMDE_POLY8_C(190), SIMDE_POLY8_C(190), SIMDE_POLY8_C(190), SIMDE_POLY8_C(190),
        SIMDE_POLY8_C(190), SIMDE_POLY8_C(190), SIMDE_POLY8_C(190), SIMDE_POLY8_C(190), SIMDE_POLY8_C(190), SIMDE_POLY8_C(190), SIMDE_POLY8_C(190), SIMDE_POLY8_C(190) } },
    { { SIMDE_POLY8_C(168), SIMDE_POLY8_C(159), SIMDE_POLY8_C( 10), SIMDE_POLY8_C(244), SIMDE_POLY8_C(119), SIMDE_POLY8_C( 50), SIMDE_POLY8_C(168), SIMDE_POLY8_C(109),
        SIMDE_POLY8_C(134), SIMDE_POLY8_C(242), SIMDE_POLY8_C(127), SIMDE_POLY8_C(120), SIMDE_POLY8_C(223), SIMDE_POLY8_C( 74), SIMDE_POLY8_C( 81), SIMDE_POLY8_C(157) },
      SIMDE_POLY8_C(  5),
      { SIMDE_POLY8_C( 50), SIMDE_POLY8_C( 50), SIMDE_POLY8_C( 50), SIMDE_POLY8_C( 50), SIMDE_POLY8_C( 50), SIMDE_POLY8_C( 50), SIMDE_POLY8_C( 50), SIMDE_POLY8_C( 50),
        SIMDE_POLY8_C( 50), SIMDE_POLY8_C( 50), SIMDE_POLY8_C( 50), SIMDE_POLY8_C( 50), SIMDE_POLY8_C( 50), SIMDE_POLY8_C( 50), SIMDE_POLY8_C( 50), SIMDE_POLY8_C( 50) } },
    { { SIMDE_POLY8_C(196), SIMDE_POLY8_C(  1), SIMDE_POLY8_C(215), SIMDE_POLY8_C(171), SIMDE_POLY8_C(171), SIMDE_POLY8_C( 58), SIMDE_POLY8_C( 71), SIMDE_POLY8_C( 86),
        SIMDE_POLY8_C(234), SIMDE_POLY8_C(120), SIMDE_POLY8_C(213), SIMDE_POLY8_C(  9), SIMDE_POLY8_C(140), SIMDE_POLY8_C(  6), SIMDE_POLY8_C(178), SIMDE_POLY8_C( 44) },
      SIMDE_POLY8_C(  0),
      { SIMDE_POLY8_C(196), SIMDE_POLY8_C(196), SIMDE_POLY8_C(196), SIMDE_POLY8_C(196), SIMDE_POLY8_C(196), SIMDE_POLY8_C(196), SIMDE_POLY8_C(196), SIMDE_POLY8_C(196),
        SIMDE_POLY8_C(196), SIMDE_POLY8_C(196), SIMDE_POLY8_C(196), SIMDE_POLY8_C(196), SIMDE_POLY8_C(196), SIMDE_POLY8_C(196), SIMDE_POLY8_C(196), SIMDE_POLY8_C(196) } },
    { { SIMDE_POLY8_C(166), SIMDE_POLY8_C(163), SIMDE_POLY8_C( 67), SIMDE_POLY8_C( 78), SIMDE_POLY8_C( 16), SIMDE_POLY8_C(201), SIMDE_POLY8_C( 65), SIMDE_POLY8_C(143),
        SIMDE_POLY8_C( 65), SIMDE_POLY8_C( 32), SIMDE_POLY8_C(217), SIMDE_POLY8_C(147), SIMDE_POLY8_C(189), SIMDE_POLY8_C(190), SIMDE_POLY8_C( 87), SIMDE_POLY8_C(191) },
      SIMDE_POLY8_C(  5),
      { SIMDE_POLY8_C(201), SIMDE_POLY8_C(201), SIMDE_POLY8_C(201), SIMDE_POLY8_C(201), SIMDE_POLY8_C(201), SIMDE_POLY8_C(201), SIMDE_POLY8_C(201), SIMDE_POLY8_C(201),
        SIMDE_POLY8_C(201), SIMDE_POLY8_C(201), SIMDE_POLY8_C(201), SIMDE_POLY8_C(201), SIMDE_POLY8_C(201), SIMDE_POLY8_C(201), SIMDE_POLY8_C(201), SIMDE_POLY8_C(201) } },
    { { SIMDE_POLY8_C(  2), SIMDE_POLY8_C(106), SIMDE_POLY8_C(208), SIMDE_POLY8_C( 74), SIMDE_POLY8_C(192), SIMDE_POLY8_C(186), SIMDE_POLY8_C(194), SIMDE_POLY8_C(149),
        SIMDE_POLY8_C(195), SIMDE_POLY8_C( 79), SIMDE_POLY8_C(156), SIMDE_POLY8_C(117), SIMDE_POLY8_C(123), SIMDE_POLY8_C(172), SIMDE_POLY8_C( 28), SIMDE_POLY8_C( 30) },
      SIMDE_POLY8_C( 15),
      { SIMDE_POLY8_C( 30), SIMDE_POLY8_C( 30), SIMDE_POLY8_C( 30), SIMDE_POLY8_C( 30), SIMDE_POLY8_C( 30), SIMDE_POLY8_C( 30), SIMDE_POLY8_C( 30), SIMDE_POLY8_C( 30),
        SIMDE_POLY8_C( 30), SIMDE_POLY8_C( 30), SIMDE_POLY8_C( 30), SIMDE_POLY8_C( 30), SIMDE_POLY8_C( 30), SIMDE_POLY8_C( 30), SIMDE_POLY8_C( 30), SIMDE_POLY8_C( 30) } },
    { { SIMDE_POLY8_C(106), SIMDE_POLY8_C( 46), SIMDE_POLY8_C(185), SIMDE_POLY8_C(171), SIMDE_POLY8_C(189), SIMDE_POLY8_C(250), SIMDE_POLY8_C(203), SIMDE_POLY8_C(150),
        SIMDE_POLY8_C(141), SIMDE_POLY8_C(137), SIMDE_POLY8_C( 84), SIMDE_POLY8_C(229), SIMDE_POLY8_C( 72), SIMDE_POLY8_C(234), SIMDE_POLY8_C(231), SIMDE_POLY8_C(178) },
      SIMDE_POLY8_C( 10),
      { SIMDE_POLY8_C( 84), SIMDE_POLY8_C( 84), SIMDE_POLY8_C( 84), SIMDE_POLY8_C( 84), SIMDE_POLY8_C( 84), SIMDE_POLY8_C( 84), SIMDE_POLY8_C( 84), SIMDE_POLY8_C( 84),
        SIMDE_POLY8_C( 84), SIMDE_POLY8_C( 84), SIMDE_POLY8_C( 84), SIMDE_POLY8_C( 84), SIMDE_POLY8_C( 84), SIMDE_POLY8_C( 84), SIMDE_POLY8_C( 84), SIMDE_POLY8_C( 84) } },
    { { SIMDE_POLY8_C( 49), SIMDE_POLY8_C(115), SIMDE_POLY8_C(116), SIMDE_POLY8_C(244), SIMDE_POLY8_C(  8), SIMDE_POLY8_C( 55), SIMDE_POLY8_C( 67), SIMDE_POLY8_C(164),
        SIMDE_POLY8_C(173), SIMDE_POLY8_C(190), SIMDE_POLY8_C( 81), SIMDE_POLY8_C(201), SIMDE_POLY8_C(220), SIMDE_POLY8_C( 64), SIMDE_POLY8_C( 51), SIMDE_POLY8_C( 10) },
      SIMDE_POLY8_C(  9),
      { SIMDE_POLY8_C(190), SIMDE_POLY8_C(190), SIMDE_POLY8_C(190), SIMDE_POLY8_C(190), SIMDE_POLY8_C(190), SIMDE_POLY8_C(190), SIMDE_POLY8_C(190), SIMDE_POLY8_C(190),
        SIMDE_POLY8_C(190), SIMDE_POLY8_C(190), SIMDE_POLY8_C(190), SIMDE_POLY8_C(190), SIMDE_POLY8_C(190), SIMDE_POLY8_C(190), SIMDE_POLY8_C(190), SIMDE_POLY8_C(190) } },
    { { SIMDE_POLY8_C(223), SIMDE_POLY8_C(199), SIMDE_POLY8_C(244), SIMDE_POLY8_C(170), SIMDE_POLY8_C( 93), SIMDE_POLY8_C(129), SIMDE_POLY8_C( 51), SIMDE_POLY8_C(177),
        SIMDE_POLY8_C(102), SIMDE_POLY8_C(123), SIMDE_POLY8_C(155), SIMDE_POLY8_C( 78), SIMDE_POLY8_C( 46), SIMDE_POLY8_C( 85), SIMDE_POLY8_C(127), SIMDE_POLY8_C(161) },
      SIMDE_POLY8_C(  9),
      { SIMDE_POLY8_C(123), SIMDE_POLY8_C(123), SIMDE_POLY8_C(123), SIMDE_POLY8_C(123), SIMDE_POLY8_C(123), SIMDE_POLY8_C(123), SIMDE_POLY8_C(123), SIMDE_POLY8_C(123),
        SIMDE_POLY8_C(123), SIMDE_POLY8_C(123), SIMDE_POLY8_C(123), SIMDE_POLY8_C(123), SIMDE_POLY8_C(123), SIMDE_POLY8_C(123), SIMDE_POLY8_C(123), SIMDE_POLY8_C(123) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_poly8x16_t vec;
    simde_poly8x16_t r;

    vec = simde_vld1q_p8(test_vec[i].vec);
    SIMDE_CONSTIFY_16_(simde_vdupq_laneq_p8, r, (HEDLEY_UNREACHABLE(), simde_vdupq_n_p8(SIMDE_POLY8_C(0))), test_vec[i].lane, vec);

    simde_test_arm_neon_assert_equal_p8x16(r, simde_vld1q_p8(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vdupq_laneq_p16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_poly16_t vec[8];
    int lane;
    simde_poly16_t r[8];
  } test_vec[] = {
    { { SIMDE_POLY16_C(12576), SIMDE_POLY16_C(38673), SIMDE_POLY16_C(17857), SIMDE_POLY16_C(51906), SIMDE_POLY16_C(60712), SIMDE_POLY16_C(20918), SIMDE_POLY16_C(54013), SIMDE_POLY16_C(47959) },
      SIMDE_POLY8_C(  1),
      { SIMDE_POLY16_C(38673), SIMDE_POLY16_C(38673), SIMDE_POLY16_C(38673), SIMDE_POLY16_C(38673), SIMDE_POLY16_C(38673), SIMDE_POLY16_C(38673), SIMDE_POLY16_C(38673), SIMDE_POLY16_C(38673) } },
    { { SIMDE_POLY16_C(58637), SIMDE_POLY16_C(48422), SIMDE_POLY16_C(47041), SIMDE_POLY16_C(59773), SIMDE_POLY16_C(22510), SIMDE_POLY16_C(58503), SIMDE_POLY16_C(20626), SIMDE_POLY16_C(49924) },
      SIMDE_POLY8_C(  2),
      { SIMDE_POLY16_C(47041), SIMDE_POLY16_C(47041), SIMDE_POLY16_C(47041), SIMDE_POLY16_C(47041), SIMDE_POLY16_C(47041), SIMDE_POLY16_C(47041), SIMDE_POLY16_C(47041), SIMDE_POLY16_C(47041) } },
    { { SIMDE_POLY16_C(33947), SIMDE_POLY16_C(24231), SIMDE_POLY16_C(53326), SIMDE_POLY16_C( 1099), SIMDE_POLY16_C(18465), SIMDE_POLY16_C(31190), SIMDE_POLY16_C(53251), SIMDE_POLY16_C(59782) },
      SIMDE_POLY8_C(  6),
      { SIMDE_POLY16_C(53251), SIMDE_POLY16_C(53251), SIMDE_POLY16_C(53251), SIMDE_POLY16_C(53251), SIMDE_POLY16_C(53251), SIMDE_POLY16_C(53251), SIMDE_POLY16_C(53251), SIMDE_POLY16_C(53251) } },
    { { SIMDE_POLY16_C(43587), SIMDE_POLY16_C(49582), SIMDE_POLY16_C(40083), SIMDE_POLY16_C( 6680), SIMDE_POLY16_C(43648), SIMDE_POLY16_C(34154), SIMDE_POLY16_C(52334), SIMDE_POLY16_C(61984) },
      SIMDE_POLY8_C(  4),
      { SIMDE_POLY16_C(43648), SIMDE_POLY16_C(43648), SIMDE_POLY16_C(43648), SIMDE_POLY16_C(43648), SIMDE_POLY16_C(43648), SIMDE_POLY16_C(43648), SIMDE_POLY16_C(43648), SIMDE_POLY16_C(43648) } },
    { { SIMDE_POLY16_C(16766), SIMDE_POLY16_C(51524), SIMDE_POLY16_C(25925), SIMDE_POLY16_C( 7185), SIMDE_POLY16_C( 5598), SIMDE_POLY16_C(26092), SIMDE_POLY16_C(58110), SIMDE_POLY16_C(43176) },
      SIMDE_POLY8_C(  0),
      { SIMDE_POLY16_C(16766), SIMDE_POLY16_C(16766), SIMDE_POLY16_C(16766), SIMDE_POLY16_C(16766), SIMDE_POLY16_C(16766), SIMDE_POLY16_C(16766), SIMDE_POLY16_C(16766), SIMDE_POLY16_C(16766) } },
    { { SIMDE_POLY16_C(15209), SIMDE_POLY16_C(33325), SIMDE_POLY16_C(44373), SIMDE_POLY16_C(48940), SIMDE_POLY16_C(39474), SIMDE_POLY16_C(21388), SIMDE_POLY16_C(  141), SIMDE_POLY16_C(52945) },
      SIMDE_POLY8_C(  4),
      { SIMDE_POLY16_C(39474), SIMDE_POLY16_C(39474), SIMDE_POLY16_C(39474), SIMDE_POLY16_C(39474), SIMDE_POLY16_C(39474), SIMDE_POLY16_C(39474), SIMDE_POLY16_C(39474), SIMDE_POLY16_C(39474) } },
    { { SIMDE_POLY16_C( 5019), SIMDE_POLY16_C(44201), SIMDE_POLY16_C(34863), SIMDE_POLY16_C( 7105), SIMDE_POLY16_C(49133), SIMDE_POLY16_C(38398), SIMDE_POLY16_C(36455), SIMDE_POLY16_C(41727) },
      SIMDE_POLY8_C(  3),
      { SIMDE_POLY16_C( 7105), SIMDE_POLY16_C( 7105), SIMDE_POLY16_C( 7105), SIMDE_POLY16_C( 7105), SIMDE_POLY16_C( 7105), SIMDE_POLY16_C( 7105), SIMDE_POLY16_C( 7105), SIMDE_POLY16_C( 7105) } },
    { { SIMDE_POLY16_C(63361), SIMDE_POLY16_C(44393), SIMDE_POLY16_C(39863), SIMDE_POLY16_C(17224), SIMDE_POLY16_C(54766), SIMDE_POLY16_C(49219), SIMDE_POLY16_C(34723), SIMDE_POLY16_C(46683) },
      SIMDE_POLY8_C(  0),
      { SIMDE_POLY16_C(63361), SIMDE_POLY16_C(63361), SIMDE_POLY16_C(63361), SIMDE_POLY16_C(63361), SIMDE_POLY16_C(63361), SIMDE_POLY16_C(63361), SIMDE_POLY16_C(63361), SIMDE_POLY16_C(63361) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_poly16x8_t vec;
    simde_poly16x8_t r;

    vec = simde_vld1q_p16(test_vec[i].vec);
    SIMDE_CONSTIFY_8_(simde_vdupq_laneq_p16, r, (HEDLEY_UNREACHABLE(), simde_vdupq_n_p16(SIMDE_POLY16_C(0))), test_vec[i].lane, vec);

    simde_test_arm_neon_assert_equal_p16x8(r, simde_vld1q_p16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vdupq_laneq_p64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_poly64_t vec[2];
    int lane;
    simde_poly64_t r[2];
  } test_vec[] = {
    { { SIMDE_POLY64_C(  490532184354108820), SIMDE_POLY64_C(14849858543504251991) },
      SIMDE_POLY8_C(  1),
      { SIMDE_POLY64_C(14849858543504251991), SIMDE_POLY64_C(14849858543504251991) } },
    { { SIMDE_POLY64_C(15052443541152030393), SIMDE_POLY64_C(12174668995002936953) },
      SIMDE_POLY8_C(  1),
      { SIMDE_POLY64_C(12174668995002936953), SIMDE_POLY64_C(12174668995002936953) } },
    { { SIMDE_POLY64_C( 8707568158386885676), SIMDE_POLY64_C(12477432015999959385) },
      SIMDE_POLY8_C(  1),
      { SIMDE_POLY64_C(12477432015999959385), SIMDE_POLY64_C(12477432015999959385) } },
    { { SIMDE_POLY64_C( 4682118690185958247), SIMDE_POLY64_C(12230875630775692699) },
      SIMDE_POLY8_C(  1),
      { SIMDE_POLY64_C(12230875630775692699), SIMDE_POLY64_C(12230875630775692699) } },
    { { SIMDE_POLY64_C(18306794091455890358), SIMDE_POLY64_C( 6830403770862296378) },
      SIMDE_POLY8_C(  0),
      { SIMDE_POLY64_C(18306794091455890358), SIMDE_POLY64_C(18306794091455890358) } },
    { { SIMDE_POLY64_C( 2305295186427806230), SIMDE_POLY64_C(18379435529598636957) },
      SIMDE_POLY8_C(  1),
      { SIMDE_POLY64_C(18379435529598636957), SIMDE_POLY64_C(18379435529598636957) } },
    { { SIMDE_POLY64_C(17584683220473821853), SIMDE_POLY64_C(17625863477911098554) },
      SIMDE_POLY8_C(  1),
      { SIMDE_POLY64_C(17625863477911098554), SIMDE_POLY64_C(17625863477911098554) } },
    { { SIMDE_POLY64_C(13924499850132829868), SIMDE_POLY64_C(12883094807028726044) },
      SIMDE_POLY8_C(  1),
      { SIMDE_POLY64_C(12883094807028726044), SIMDE_POLY64_C(12883094807028726044) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_poly64x2_t vec;
    simde_poly64x2_t r;

    vec = simde_vld1q_p64(test_vec[i].vec);
    SIMDE_CONSTIFY_2_(simde_vdupq_laneq_p64, r, (HEDLEY_UNREACHABLE(), simde_vdupq_n_p64(SIMDE_POLY64_C(0))), test_vec[i].lane, vec);

    simde_test_arm_neon_assert_equal_p64x2(r, simde_vld1q_p64(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vdupb_lane_p8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_poly8_t vec[8];
    int lane;
    simde_poly8_t r;
  } test_vec[] = {
    { {  SIMDE_POLY8_C(  245),  SIMDE_POLY8_C(  152),  SIMDE_POLY8_C(  217),  SIMDE_POLY8_C(  115),
         SIMDE_POLY8_C(  189),  SIMDE_POLY8_C(   37),  SIMDE_POLY8_C(   12),  SIMDE_POLY8_C(   69) },
         INT8_C(    5),
         SIMDE_POLY8_C(   37) },
    { {  SIMDE_POLY8_C(  146),  SIMDE_POLY8_C(    7),  SIMDE_POLY8_C(   39),  SIMDE_POLY8_C(  222),
         SIMDE_POLY8_C(   39),  SIMDE_POLY8_C(   52),  SIMDE_POLY8_C(  207),  SIMDE_POLY8_C(   93) },
         INT8_C(    6),
         SIMDE_POLY8_C(  207) },
    { {  SIMDE_POLY8_C(   13),  SIMDE_POLY8_C(  222),  SIMDE_POLY8_C(  153),  SIMDE_POLY8_C(  154),
         SIMDE_POLY8_C(   83),  SIMDE_POLY8_C(  234),  SIMDE_POLY8_C(  231),  SIMDE_POLY8_C(  167) },
         INT8_C(    2),
         SIMDE_POLY8_C(  153) },
    { {  SIMDE_POLY8_C(  237),  SIMDE_POLY8_C(   29),  SIMDE_POLY8_C(   92),  SIMDE_POLY8_C(  102),
         SIMDE_POLY8_C(  201),  SIMDE_POLY8_C(  218),  SIMDE_POLY8_C(  157),  SIMDE_POLY8_C(   12) },
         INT8_C(    3),
         SIMDE_POLY8_C(  102) },
    { {  SIMDE_POLY8_C(  192),  SIMDE_POLY8_C(  129),  SIMDE_POLY8_C(   63),  SIMDE_POLY8_C(  115),
         SIMDE_POLY8_C(   84),  SIMDE_POLY8_C(  168),  SIMDE_POLY8_C(   30),  SIMDE_POLY8_C(  160) },
         INT8_C(    2),
         SIMDE_POLY8_C(   63) },
    { {  SIMDE_POLY8_C(    8),  SIMDE_POLY8_C(   36),  SIMDE_POLY8_C(   69),  SIMDE_POLY8_C(  227),
         SIMDE_POLY8_C(  208),  SIMDE_POLY8_C(  249),  SIMDE_POLY8_C(  155),  SIMDE_POLY8_C(   39) },
         INT8_C(    3),
         SIMDE_POLY8_C(  227) },
    { {  SIMDE_POLY8_C(  183),  SIMDE_POLY8_C(  108),  SIMDE_POLY8_C(  232),  SIMDE_POLY8_C(   74),
         SIMDE_POLY8_C(  219),  SIMDE_POLY8_C(  191),  SIMDE_POLY8_C(  213),  SIMDE_POLY8_C(  189) },
         INT8_C(    4),
         SIMDE_POLY8_C(  219) },
    { {  SIMDE_POLY8_C(  191),  SIMDE_POLY8_C(  213),  SIMDE_POLY8_C(  107),  SIMDE_POLY8_C(   79),
         SIMDE_POLY8_C(  123),  SIMDE_POLY8_C(   18),  SIMDE_POLY8_C(  115),  SIMDE_POLY8_C(   30) },
         INT8_C(    7),
         SIMDE_POLY8_C(   30) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_poly8x8_t vec;
    simde_poly8_t r;

    vec = simde_vld1_p8(test_vec[i].vec);
    SIMDE_CONSTIFY_8_(simde_vdupb_lane_p8, r, (HEDLEY_UNREACHABLE(), r), test_vec[i].lane, vec);

    simde_assert_equal_p8(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_vdupb_laneq_p8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_poly8_t vec[16];
    int lane;
    simde_poly8_t r;
  } test_vec[] = {
    { {  SIMDE_POLY8_C(  230),  SIMDE_POLY8_C(  105),  SIMDE_POLY8_C(   26),  SIMDE_POLY8_C(   81),
         SIMDE_POLY8_C(  175),  SIMDE_POLY8_C(  144),  SIMDE_POLY8_C(    9),  SIMDE_POLY8_C(    6),
         SIMDE_POLY8_C(  171),  SIMDE_POLY8_C(  109),  SIMDE_POLY8_C(   10),  SIMDE_POLY8_C(   73),
         SIMDE_POLY8_C(   22),  SIMDE_POLY8_C(  189),  SIMDE_POLY8_C(  109),  SIMDE_POLY8_C(  140) },
         INT8_C(    5),
         SIMDE_POLY8_C(  144) },
    { {  SIMDE_POLY8_C(  134),  SIMDE_POLY8_C(   16),  SIMDE_POLY8_C(   81),  SIMDE_POLY8_C(  181),
         SIMDE_POLY8_C(  235),  SIMDE_POLY8_C(  108),  SIMDE_POLY8_C(  194),  SIMDE_POLY8_C(  104),
         SIMDE_POLY8_C(   39),  SIMDE_POLY8_C(   27),  SIMDE_POLY8_C(   77),  SIMDE_POLY8_C(  166),
         SIMDE_POLY8_C(   84),  SIMDE_POLY8_C(    4),  SIMDE_POLY8_C(  241),  SIMDE_POLY8_C(   49) },
         INT8_C(   15),
         SIMDE_POLY8_C(   49) },
    { {  SIMDE_POLY8_C(  173),  SIMDE_POLY8_C(  189),  SIMDE_POLY8_C(  113),  SIMDE_POLY8_C(  153),
         SIMDE_POLY8_C(  208),  SIMDE_POLY8_C(   68),  SIMDE_POLY8_C(   23),  SIMDE_POLY8_C(   78),
         SIMDE_POLY8_C(   21),  SIMDE_POLY8_C(   52),  SIMDE_POLY8_C(  245),  SIMDE_POLY8_C(  231),
         SIMDE_POLY8_C(  164),  SIMDE_POLY8_C(  246),  SIMDE_POLY8_C(  168),  SIMDE_POLY8_C(   56) },
         INT8_C(    3),
         SIMDE_POLY8_C(  153) },
    { {  SIMDE_POLY8_C(  186),  SIMDE_POLY8_C(  192),  SIMDE_POLY8_C(  204),  SIMDE_POLY8_C(  154),
         SIMDE_POLY8_C(  169),  SIMDE_POLY8_C(  191),  SIMDE_POLY8_C(  155),  SIMDE_POLY8_C(   14),
         SIMDE_POLY8_C(  224),  SIMDE_POLY8_C(    6),  SIMDE_POLY8_C(    4),  SIMDE_POLY8_C(   24),
         SIMDE_POLY8_C(  153),  SIMDE_POLY8_C(   96),  SIMDE_POLY8_C(   78),  SIMDE_POLY8_C(  110) },
         INT8_C(   11),
         SIMDE_POLY8_C(   24) },
    { {  SIMDE_POLY8_C(  194),  SIMDE_POLY8_C(  160),  SIMDE_POLY8_C(   34),  SIMDE_POLY8_C(  117),
         SIMDE_POLY8_C(  228),  SIMDE_POLY8_C(  135),  SIMDE_POLY8_C(   95),  SIMDE_POLY8_C(  203),
         SIMDE_POLY8_C(   94),  SIMDE_POLY8_C(   71),  SIMDE_POLY8_C(  148),  SIMDE_POLY8_C(  106),
         SIMDE_POLY8_C(  154),  SIMDE_POLY8_C(  119),  SIMDE_POLY8_C(  115),  SIMDE_POLY8_C(   74) },
         INT8_C(   10),
         SIMDE_POLY8_C(  148) },
    { {  SIMDE_POLY8_C(  129),  SIMDE_POLY8_C(   92),  SIMDE_POLY8_C(   35),  SIMDE_POLY8_C(  238),
         SIMDE_POLY8_C(  100),  SIMDE_POLY8_C(  192),  SIMDE_POLY8_C(   44),  SIMDE_POLY8_C(   66),
         SIMDE_POLY8_C(  100),  SIMDE_POLY8_C(  173),  SIMDE_POLY8_C(   43),  SIMDE_POLY8_C(  196),
         SIMDE_POLY8_C(   89),  SIMDE_POLY8_C(   66),  SIMDE_POLY8_C(    8),  SIMDE_POLY8_C(   35) },
         INT8_C(    0),
         SIMDE_POLY8_C(  129) },
    { {  SIMDE_POLY8_C(  237),  SIMDE_POLY8_C(   71),  SIMDE_POLY8_C(   85),  SIMDE_POLY8_C(  176),
         SIMDE_POLY8_C(  103),  SIMDE_POLY8_C(   42),  SIMDE_POLY8_C(   20),  SIMDE_POLY8_C(   78),
         SIMDE_POLY8_C(  133),  SIMDE_POLY8_C(   99),  SIMDE_POLY8_C(  179),  SIMDE_POLY8_C(  133),
         SIMDE_POLY8_C(  225),  SIMDE_POLY8_C(  199),  SIMDE_POLY8_C(   61),  SIMDE_POLY8_C(   92) },
         INT8_C(    2),
         SIMDE_POLY8_C(   85) },
    { {  SIMDE_POLY8_C(  129),  SIMDE_POLY8_C(  143),  SIMDE_POLY8_C(   98),  SIMDE_POLY8_C(   58),
         SIMDE_POLY8_C(   41),  SIMDE_POLY8_C(   58),  SIMDE_POLY8_C(  160),  SIMDE_POLY8_C(  153),
         SIMDE_POLY8_C(  211),  SIMDE_POLY8_C(  206),  SIMDE_POLY8_C(  192),  SIMDE_POLY8_C(  193),
         SIMDE_POLY8_C(    3),  SIMDE_POLY8_C(  112),  SIMDE_POLY8_C(   10),  SIMDE_POLY8_C(  242) },
         INT8_C(    6),
         SIMDE_POLY8_C(  160) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_poly8x16_t vec;
    simde_poly8_t r;

    vec = simde_vld1q_p8(test_vec[i].vec);
    SIMDE_CONSTIFY_16_(simde_vdupb_laneq_p8, r, (HEDLEY_UNREACHABLE(), r), test_vec[i].lane, vec);

    simde_assert_equal_p8(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_vduph_lane_p16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_poly16_t vec[4];
    int lane;
    simde_poly16_t r;
  } test_vec[] = {
    { {  SIMDE_POLY16_C( 27436),  SIMDE_POLY16_C( 60731),  SIMDE_POLY16_C(  8131),  SIMDE_POLY16_C( 63274) },
         INT16_C(     0),
         SIMDE_POLY16_C( 27436) },
    { {  SIMDE_POLY16_C( 23538),  SIMDE_POLY16_C( 46099),  SIMDE_POLY16_C( 42839),  SIMDE_POLY16_C( 32144) },
         INT16_C(     0),
         SIMDE_POLY16_C( 23538) },
    { {  SIMDE_POLY16_C( 10649),  SIMDE_POLY16_C( 33779),  SIMDE_POLY16_C( 23462),  SIMDE_POLY16_C( 17951) },
         INT16_C(     1),
         SIMDE_POLY16_C( 33779) },
    { {  SIMDE_POLY16_C( 42321),  SIMDE_POLY16_C( 16328),  SIMDE_POLY16_C( 44735),  SIMDE_POLY16_C( 59999) },
         INT16_C(     1),
         SIMDE_POLY16_C( 16328) },
    { {  SIMDE_POLY16_C( 33534),  SIMDE_POLY16_C( 12727),  SIMDE_POLY16_C( 29464),  SIMDE_POLY16_C( 10589) },
         INT16_C(     2),
         SIMDE_POLY16_C( 29464) },
    { {  SIMDE_POLY16_C( 10963),  SIMDE_POLY16_C(  2733),  SIMDE_POLY16_C( 58099),  SIMDE_POLY16_C( 44876) },
         INT16_C(     3),
         SIMDE_POLY16_C( 44876) },
    { {  SIMDE_POLY16_C( 20112),  SIMDE_POLY16_C( 48793),  SIMDE_POLY16_C(  5269),  SIMDE_POLY16_C( 51155) },
         INT16_C(     3),
         SIMDE_POLY16_C( 51155) },
    { {  SIMDE_POLY16_C( 26801),  SIMDE_POLY16_C( 16635),  SIMDE_POLY16_C( 35849),  SIMDE_POLY16_C( 59673) },
         INT16_C(     0),
         SIMDE_POLY16_C( 26801) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_poly16x4_t vec;
    simde_poly16_t r;

    vec = simde_vld1_p16(test_vec[i].vec);
    SIMDE_CONSTIFY_4_(simde_vduph_lane_p16, r, (HEDLEY_UNREACHABLE(), r), test_vec[i].lane, vec);

    simde_assert_equal_p16(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_vduph_laneq_p16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_poly16_t vec[8];
    int lane;
    simde_poly16_t r;
  } test_vec[] = {
    { {  SIMDE_POLY16_C( 15983),  SIMDE_POLY16_C( 56340),  SIMDE_POLY16_C( 41900),  SIMDE_POLY16_C( 44873),
         SIMDE_POLY16_C( 39576),  SIMDE_POLY16_C( 42863),  SIMDE_POLY16_C( 31470),  SIMDE_POLY16_C( 48193) },
         INT16_C(     3),
         SIMDE_POLY16_C( 44873) },
    { {  SIMDE_POLY16_C( 29237),  SIMDE_POLY16_C( 19036),  SIMDE_POLY16_C( 53654),  SIMDE_POLY16_C( 35746),
         SIMDE_POLY16_C( 15558),  SIMDE_POLY16_C( 48185),  SIMDE_POLY16_C( 38846),  SIMDE_POLY16_C( 14970) },
         INT16_C(     4),
         SIMDE_POLY16_C( 15558) },
    { {  SIMDE_POLY16_C( 56312),  SIMDE_POLY16_C( 59570),  SIMDE_POLY16_C(  1856),  SIMDE_POLY16_C( 32492),
         SIMDE_POLY16_C( 35792),  SIMDE_POLY16_C( 36746),  SIMDE_POLY16_C( 56904),  SIMDE_POLY16_C( 57449) },
         INT16_C(     3),
         SIMDE_POLY16_C( 32492) },
    { {  SIMDE_POLY16_C( 26550),  SIMDE_POLY16_C( 57975),  SIMDE_POLY16_C( 28715),  SIMDE_POLY16_C(  9461),
         SIMDE_POLY16_C( 14739),  SIMDE_POLY16_C(  7381),  SIMDE_POLY16_C( 13735),  SIMDE_POLY16_C( 57602) },
         INT16_C(     4),
         SIMDE_POLY16_C( 14739) },
    { {  SIMDE_POLY16_C(  7907),  SIMDE_POLY16_C( 45875),  SIMDE_POLY16_C( 23382),  SIMDE_POLY16_C( 10376),
         SIMDE_POLY16_C(  1011),  SIMDE_POLY16_C( 53925),  SIMDE_POLY16_C( 53567),  SIMDE_POLY16_C( 46732) },
         INT16_C(     6),
         SIMDE_POLY16_C( 53567) },
    { {  SIMDE_POLY16_C( 40039),  SIMDE_POLY16_C( 41066),  SIMDE_POLY16_C( 24856),  SIMDE_POLY16_C( 11213),
         SIMDE_POLY16_C(  2899),  SIMDE_POLY16_C( 34256),  SIMDE_POLY16_C( 43679),  SIMDE_POLY16_C( 11070) },
         INT16_C(     7),
         SIMDE_POLY16_C( 11070) },
    { {  SIMDE_POLY16_C( 40970),  SIMDE_POLY16_C( 46568),  SIMDE_POLY16_C( 14501),  SIMDE_POLY16_C( 14957),
         SIMDE_POLY16_C( 30816),  SIMDE_POLY16_C( 14508),  SIMDE_POLY16_C( 13380),  SIMDE_POLY16_C( 15393) },
         INT16_C(     5),
         SIMDE_POLY16_C( 14508) },
    { {  SIMDE_POLY16_C( 28157),  SIMDE_POLY16_C( 40057),  SIMDE_POLY16_C( 10679),  SIMDE_POLY16_C(  7851),
         SIMDE_POLY16_C(  3390),  SIMDE_POLY16_C( 41690),  SIMDE_POLY16_C( 45346),  SIMDE_POLY16_C( 12049) },
         INT16_C(     0),
         SIMDE_POLY16_C( 28157) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_poly16x8_t vec;
    simde_poly16_t r;

    vec = simde_vld1q_p16(test_vec[i].vec);
    SIMDE_CONSTIFY_8_(simde_vduph_laneq_p16, r, (HEDLEY_UNREACHABLE(), r), test_vec[i].lane, vec);

    simde_assert_equal_p16(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_vduph_lane_bf16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_bfloat16_t vec[4];
    int lane;
    simde_bfloat16_t r;
  } test_vec[] = {
    { {  SIMDE_BFLOAT16_VALUE(-3.387),  SIMDE_BFLOAT16_VALUE(-9.632),  SIMDE_BFLOAT16_VALUE(19.992),  SIMDE_BFLOAT16_VALUE( 1.837) },
         INT16_C(     0),
         SIMDE_BFLOAT16_VALUE(-3.387) },
    { {  SIMDE_BFLOAT16_VALUE(26.430),  SIMDE_BFLOAT16_VALUE(28.640),  SIMDE_BFLOAT16_VALUE(-21.270),  SIMDE_BFLOAT16_VALUE(-10.357) },
         INT16_C(     0),
         SIMDE_BFLOAT16_VALUE(26.430) },
    { {  SIMDE_BFLOAT16_VALUE(24.992),  SIMDE_BFLOAT16_VALUE( 2.837),  SIMDE_BFLOAT16_VALUE( 1.880),  SIMDE_BFLOAT16_VALUE( 1.855) },
         INT16_C(     1),
         SIMDE_BFLOAT16_VALUE( 2.837) },
    { {  SIMDE_BFLOAT16_VALUE(-15.363),  SIMDE_BFLOAT16_VALUE(-5.167),  SIMDE_BFLOAT16_VALUE( 4.732),  SIMDE_BFLOAT16_VALUE(-14.807) },
         INT16_C(     3),
         SIMDE_BFLOAT16_VALUE(-14.807) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_bfloat16x4_t vec;
    simde_bfloat16_t r;

    vec = simde_vld1_bf16(test_vec[i].vec);
    SIMDE_CONSTIFY_4_(simde_vduph_lane_bf16, r, (HEDLEY_UNREACHABLE(), r), test_vec[i].lane, vec);

    simde_assert_equal_bf16(r, test_vec[i].r, INT_MAX);
  }

  return 0;
}

static int
test_simde_vduph_laneq_bf16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_bfloat16_t vec[8];
    int lane;
    simde_bfloat16_t r;
  } test_vec[] = {
    { {  SIMDE_BFLOAT16_VALUE(-3.387),  SIMDE_BFLOAT16_VALUE(-9.632),  SIMDE_BFLOAT16_VALUE(19.992),  SIMDE_BFLOAT16_VALUE( 1.837),
         SIMDE_BFLOAT16_VALUE(10.218),  SIMDE_BFLOAT16_VALUE( 0.924),  SIMDE_BFLOAT16_VALUE(28.548),  SIMDE_BFLOAT16_VALUE(10.866) },
         INT16_C(     0),
         SIMDE_BFLOAT16_VALUE(-3.387) },
    { {  SIMDE_BFLOAT16_VALUE(26.430),  SIMDE_BFLOAT16_VALUE(28.640),  SIMDE_BFLOAT16_VALUE(-21.270),  SIMDE_BFLOAT16_VALUE(-10.357),
         SIMDE_BFLOAT16_VALUE( 0.986),  SIMDE_BFLOAT16_VALUE(-14.685),  SIMDE_BFLOAT16_VALUE(27.090),  SIMDE_BFLOAT16_VALUE(16.825) },
         INT16_C(     0),
         SIMDE_BFLOAT16_VALUE(26.430) },
    { {  SIMDE_BFLOAT16_VALUE(24.992),  SIMDE_BFLOAT16_VALUE( 2.837),  SIMDE_BFLOAT16_VALUE( 1.880),  SIMDE_BFLOAT16_VALUE( 1.855),
         SIMDE_BFLOAT16_VALUE(-26.001),  SIMDE_BFLOAT16_VALUE(25.433),  SIMDE_BFLOAT16_VALUE(-25.054),  SIMDE_BFLOAT16_VALUE(-18.612) },
         INT16_C(     1),
         SIMDE_BFLOAT16_VALUE( 2.837) },
    { {  SIMDE_BFLOAT16_VALUE(-24.460),  SIMDE_BFLOAT16_VALUE(-22.313),  SIMDE_BFLOAT16_VALUE(-17.405),  SIMDE_BFLOAT16_VALUE( 7.420),
         SIMDE_BFLOAT16_VALUE(-9.492),  SIMDE_BFLOAT16_VALUE(-28.099),  SIMDE_BFLOAT16_VALUE(-25.166),  SIMDE_BFLOAT16_VALUE(-23.800) },
         INT16_C(     5),
         SIMDE_BFLOAT16_VALUE(-28.099) },
    { {  SIMDE_BFLOAT16_VALUE(-20.270),  SIMDE_BFLOAT16_VALUE(-10.763),  SIMDE_BFLOAT16_VALUE(-20.068),  SIMDE_BFLOAT16_VALUE( 1.744),
         SIMDE_BFLOAT16_VALUE( 4.890),  SIMDE_BFLOAT16_VALUE(-28.985),  SIMDE_BFLOAT16_VALUE(-27.261),  SIMDE_BFLOAT16_VALUE(-5.649) },
         INT16_C(     6),
         SIMDE_BFLOAT16_VALUE(-27.261) },
    { {  SIMDE_BFLOAT16_VALUE( 2.648),  SIMDE_BFLOAT16_VALUE(-19.666),  SIMDE_BFLOAT16_VALUE( 0.498),  SIMDE_BFLOAT16_VALUE(-12.129),
         SIMDE_BFLOAT16_VALUE(-6.541),  SIMDE_BFLOAT16_VALUE(20.271),  SIMDE_BFLOAT16_VALUE(11.576),  SIMDE_BFLOAT16_VALUE(26.583) },
         INT16_C(     5),
         SIMDE_BFLOAT16_VALUE(20.271) },
    { {  SIMDE_BFLOAT16_VALUE(-15.363),  SIMDE_BFLOAT16_VALUE(-5.167),  SIMDE_BFLOAT16_VALUE( 4.732),  SIMDE_BFLOAT16_VALUE(-14.807),
         SIMDE_BFLOAT16_VALUE(13.136),  SIMDE_BFLOAT16_VALUE(26.351),  SIMDE_BFLOAT16_VALUE(15.240),  SIMDE_BFLOAT16_VALUE(-21.142) },
         INT16_C(     3),
         SIMDE_BFLOAT16_VALUE(-14.807) },
    { {  SIMDE_BFLOAT16_VALUE(-22.512),  SIMDE_BFLOAT16_VALUE(15.536),  SIMDE_BFLOAT16_VALUE(-20.898),  SIMDE_BFLOAT16_VALUE(-24.975),
         SIMDE_BFLOAT16_VALUE(-28.439),  SIMDE_BFLOAT16_VALUE(-28.696),  SIMDE_BFLOAT16_VALUE(12.933),  SIMDE_BFLOAT16_VALUE(20.260) },
         INT16_C(     7),
         SIMDE_BFLOAT16_VALUE(20.260) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_bfloat16x8_t vec;
    simde_bfloat16_t r;

    vec = simde_vld1q_bf16(test_vec[i].vec);
    SIMDE_CONSTIFY_8_(simde_vduph_laneq_bf16, r, (HEDLEY_UNREACHABLE(), r), test_vec[i].lane, vec);

    simde_assert_equal_bf16(r, test_vec[i].r, INT_MAX);
  }

  return 0;
}

static int
test_simde_vdup_lane_bf16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_bfloat16 vec[4];
    int lane;
    simde_bfloat16 r[4];
  } test_vec[] = {
    { { SIMDE_BFLOAT16_VALUE(-7.6), SIMDE_BFLOAT16_VALUE(11.4), SIMDE_BFLOAT16_VALUE(10.7), SIMDE_BFLOAT16_VALUE(-0.1) },
        INT8_C(2),
      { SIMDE_BFLOAT16_VALUE(10.7), SIMDE_BFLOAT16_VALUE(10.7), SIMDE_BFLOAT16_VALUE(10.7), SIMDE_BFLOAT16_VALUE(10.7) } },
    { { SIMDE_BFLOAT16_VALUE(1.4), SIMDE_BFLOAT16_VALUE(-5.5), SIMDE_BFLOAT16_VALUE(3.7), SIMDE_BFLOAT16_VALUE(-12.5) },
        INT8_C(0),
      { SIMDE_BFLOAT16_VALUE(1.4), SIMDE_BFLOAT16_VALUE(1.4), SIMDE_BFLOAT16_VALUE(1.4), SIMDE_BFLOAT16_VALUE(1.4) } },
    { { SIMDE_BFLOAT16_VALUE(13.3), SIMDE_BFLOAT16_VALUE(-11.6), SIMDE_BFLOAT16_VALUE(4.4), SIMDE_BFLOAT16_VALUE(-1.3) },
        INT8_C(2),
      { SIMDE_BFLOAT16_VALUE(4.4), SIMDE_BFLOAT16_VALUE(4.4), SIMDE_BFLOAT16_VALUE(4.4), SIMDE_BFLOAT16_VALUE(4.4) } },
    { { SIMDE_BFLOAT16_VALUE(-11.5), SIMDE_BFLOAT16_VALUE(-10.6), SIMDE_BFLOAT16_VALUE(13.5), SIMDE_BFLOAT16_VALUE(-5.6) },
        INT8_C(0),
      { SIMDE_BFLOAT16_VALUE(-11.5), SIMDE_BFLOAT16_VALUE(-11.5), SIMDE_BFLOAT16_VALUE(-11.5), SIMDE_BFLOAT16_VALUE(-11.5) } },
    { { SIMDE_BFLOAT16_VALUE(-12.6), SIMDE_BFLOAT16_VALUE(-12.4), SIMDE_BFLOAT16_VALUE(11.3), SIMDE_BFLOAT16_VALUE(11.8) },
        INT8_C(0),
      { SIMDE_BFLOAT16_VALUE(-12.6), SIMDE_BFLOAT16_VALUE(-12.6), SIMDE_BFLOAT16_VALUE(-12.6), SIMDE_BFLOAT16_VALUE(-12.6) } },
    { { SIMDE_BFLOAT16_VALUE(1.7), SIMDE_BFLOAT16_VALUE(-12.1), SIMDE_BFLOAT16_VALUE(-11.1), SIMDE_BFLOAT16_VALUE(-11.3) },
        INT8_C(1),
      { SIMDE_BFLOAT16_VALUE(-12.1), SIMDE_BFLOAT16_VALUE(-12.1), SIMDE_BFLOAT16_VALUE(-12.1), SIMDE_BFLOAT16_VALUE(-12.1) } },
    { { SIMDE_BFLOAT16_VALUE(-2.9), SIMDE_BFLOAT16_VALUE(0.3), SIMDE_BFLOAT16_VALUE(11.1), SIMDE_BFLOAT16_VALUE(8.8) },
        INT8_C(1),
      { SIMDE_BFLOAT16_VALUE(0.3), SIMDE_BFLOAT16_VALUE(0.3), SIMDE_BFLOAT16_VALUE(0.3), SIMDE_BFLOAT16_VALUE(0.3) } },
    { { SIMDE_BFLOAT16_VALUE(8.0), SIMDE_BFLOAT16_VALUE(-13.7), SIMDE_BFLOAT16_VALUE(-3.6), SIMDE_BFLOAT16_VALUE(5.8) },
        INT8_C(0),
      { SIMDE_BFLOAT16_VALUE(8.0), SIMDE_BFLOAT16_VALUE(8.0), SIMDE_BFLOAT16_VALUE(8.0), SIMDE_BFLOAT16_VALUE(8.0) } },
    { { SIMDE_BFLOAT16_VALUE(1.1), SIMDE_BFLOAT16_VALUE(10.1), SIMDE_BFLOAT16_VALUE(1.2), SIMDE_BFLOAT16_VALUE(-11.7) },
        INT8_C(0),
      { SIMDE_BFLOAT16_VALUE(1.1), SIMDE_BFLOAT16_VALUE(1.1), SIMDE_BFLOAT16_VALUE(1.1), SIMDE_BFLOAT16_VALUE(1.1) } },
    { { SIMDE_BFLOAT16_VALUE(-2.0), SIMDE_BFLOAT16_VALUE(-14.0), SIMDE_BFLOAT16_VALUE(-13.7), SIMDE_BFLOAT16_VALUE(-10.2) },
        INT8_C(0),
      { SIMDE_BFLOAT16_VALUE(-2.0), SIMDE_BFLOAT16_VALUE(-2.0), SIMDE_BFLOAT16_VALUE(-2.0), SIMDE_BFLOAT16_VALUE(-2.0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_bfloat16x4_t vec;
    simde_bfloat16x4_t r;

    vec = simde_vld1_bf16(test_vec[i].vec);
    SIMDE_CONSTIFY_4_(simde_vdup_lane_bf16, r, (HEDLEY_UNREACHABLE(), simde_vdup_n_bf16(SIMDE_BFLOAT16_VALUE(0.0))), test_vec[i].lane, vec);

    simde_test_arm_neon_assert_equal_bf16x4(r, simde_vld1_bf16(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_vdup_laneq_bf16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_bfloat16 vec[8];
    int lane;
    simde_bfloat16 r[4];
  } test_vec[] = {
    { {  SIMDE_BFLOAT16_VALUE(     9.056),  SIMDE_BFLOAT16_VALUE(     1.677),  SIMDE_BFLOAT16_VALUE(     7.053),  SIMDE_BFLOAT16_VALUE(    28.437),
         SIMDE_BFLOAT16_VALUE(    14.165),  SIMDE_BFLOAT16_VALUE(    18.651),  SIMDE_BFLOAT16_VALUE(   -23.860),  SIMDE_BFLOAT16_VALUE(     2.771) },
         INT8_C(         6),
      {  SIMDE_BFLOAT16_VALUE(   -23.860),  SIMDE_BFLOAT16_VALUE(   -23.860),  SIMDE_BFLOAT16_VALUE(   -23.860),  SIMDE_BFLOAT16_VALUE(   -23.860) } },
    { {  SIMDE_BFLOAT16_VALUE(    24.258),  SIMDE_BFLOAT16_VALUE(   -13.828),  SIMDE_BFLOAT16_VALUE(   -26.370),  SIMDE_BFLOAT16_VALUE(    19.116),
         SIMDE_BFLOAT16_VALUE(    -8.063),  SIMDE_BFLOAT16_VALUE(    29.418),  SIMDE_BFLOAT16_VALUE(   -20.107),  SIMDE_BFLOAT16_VALUE(     7.234) },
         INT8_C(         2),
      {  SIMDE_BFLOAT16_VALUE(   -26.370),  SIMDE_BFLOAT16_VALUE(   -26.370),  SIMDE_BFLOAT16_VALUE(   -26.370),  SIMDE_BFLOAT16_VALUE(   -26.370) } },
    { {  SIMDE_BFLOAT16_VALUE(   -11.462),  SIMDE_BFLOAT16_VALUE(    22.959),  SIMDE_BFLOAT16_VALUE(   -17.969),  SIMDE_BFLOAT16_VALUE(    -9.845),
         SIMDE_BFLOAT16_VALUE(     7.748),  SIMDE_BFLOAT16_VALUE(   -18.327),  SIMDE_BFLOAT16_VALUE(    13.108),  SIMDE_BFLOAT16_VALUE(   -16.811) },
         INT8_C(         7),
      {  SIMDE_BFLOAT16_VALUE(   -16.811),  SIMDE_BFLOAT16_VALUE(   -16.811),  SIMDE_BFLOAT16_VALUE(   -16.811),  SIMDE_BFLOAT16_VALUE(   -16.811) } },
    { {  SIMDE_BFLOAT16_VALUE(     8.525),  SIMDE_BFLOAT16_VALUE(   -15.131),  SIMDE_BFLOAT16_VALUE(    14.364),  SIMDE_BFLOAT16_VALUE(    -8.648),
         SIMDE_BFLOAT16_VALUE(   -10.759),  SIMDE_BFLOAT16_VALUE(    -3.780),  SIMDE_BFLOAT16_VALUE(     3.004),  SIMDE_BFLOAT16_VALUE(   -12.422) },
         INT8_C(         4),
      {  SIMDE_BFLOAT16_VALUE(   -10.759),  SIMDE_BFLOAT16_VALUE(   -10.759),  SIMDE_BFLOAT16_VALUE(   -10.759),  SIMDE_BFLOAT16_VALUE(   -10.759) } },
    { {  SIMDE_BFLOAT16_VALUE(    12.736),  SIMDE_BFLOAT16_VALUE(    10.408),  SIMDE_BFLOAT16_VALUE(    16.484),  SIMDE_BFLOAT16_VALUE(   -11.569),
         SIMDE_BFLOAT16_VALUE(   -27.593),  SIMDE_BFLOAT16_VALUE(   -22.388),  SIMDE_BFLOAT16_VALUE(     0.182),  SIMDE_BFLOAT16_VALUE(    27.270) },
         INT8_C(         1),
      {  SIMDE_BFLOAT16_VALUE(    10.408),  SIMDE_BFLOAT16_VALUE(    10.408),  SIMDE_BFLOAT16_VALUE(    10.408),  SIMDE_BFLOAT16_VALUE(    10.408) } },
    { {  SIMDE_BFLOAT16_VALUE(    -8.778),  SIMDE_BFLOAT16_VALUE(     6.046),  SIMDE_BFLOAT16_VALUE(     1.558),  SIMDE_BFLOAT16_VALUE(     7.396),
         SIMDE_BFLOAT16_VALUE(    29.886),  SIMDE_BFLOAT16_VALUE(    -0.845),  SIMDE_BFLOAT16_VALUE(    14.948),  SIMDE_BFLOAT16_VALUE(    17.996) },
         INT8_C(         6),
      {  SIMDE_BFLOAT16_VALUE(    14.948),  SIMDE_BFLOAT16_VALUE(    14.948),  SIMDE_BFLOAT16_VALUE(    14.948),  SIMDE_BFLOAT16_VALUE(    14.948) } },
    { {  SIMDE_BFLOAT16_VALUE(    -9.902),  SIMDE_BFLOAT16_VALUE(    20.687),  SIMDE_BFLOAT16_VALUE(   -25.203),  SIMDE_BFLOAT16_VALUE(    13.883),
         SIMDE_BFLOAT16_VALUE(   -14.370),  SIMDE_BFLOAT16_VALUE(   -27.322),  SIMDE_BFLOAT16_VALUE(   -24.150),  SIMDE_BFLOAT16_VALUE(   -21.580) },
         INT8_C(         1),
      {  SIMDE_BFLOAT16_VALUE(    20.687),  SIMDE_BFLOAT16_VALUE(    20.687),  SIMDE_BFLOAT16_VALUE(    20.687),  SIMDE_BFLOAT16_VALUE(    20.687) } },
    { {  SIMDE_BFLOAT16_VALUE(    11.499),  SIMDE_BFLOAT16_VALUE(   -13.869),  SIMDE_BFLOAT16_VALUE(   -27.353),  SIMDE_BFLOAT16_VALUE(     6.786),
         SIMDE_BFLOAT16_VALUE(    29.577),  SIMDE_BFLOAT16_VALUE(    -4.705),  SIMDE_BFLOAT16_VALUE(   -25.496),  SIMDE_BFLOAT16_VALUE(    26.515) },
         INT8_C(         0),
      {  SIMDE_BFLOAT16_VALUE(    11.499),  SIMDE_BFLOAT16_VALUE(    11.499),  SIMDE_BFLOAT16_VALUE(    11.499),  SIMDE_BFLOAT16_VALUE(    11.499) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_bfloat16x8_t vec;
    simde_bfloat16x4_t r;

    vec = simde_vld1q_bf16(test_vec[i].vec);
    SIMDE_CONSTIFY_8_(simde_vdup_laneq_bf16, r, (HEDLEY_UNREACHABLE(), r), test_vec[i].lane, vec);

    simde_test_arm_neon_assert_equal_bf16x4(r, simde_vld1_bf16(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_vdupq_lane_bf16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_bfloat16 vec[4];
    int lane;
    simde_bfloat16 r[8];
  } test_vec[] = {
    { { SIMDE_BFLOAT16_VALUE(-3.4), SIMDE_BFLOAT16_VALUE(6.4), SIMDE_BFLOAT16_VALUE(-7.4), SIMDE_BFLOAT16_VALUE(0.5) },
        INT8_C(0),
      { SIMDE_BFLOAT16_VALUE(-3.4), SIMDE_BFLOAT16_VALUE(-3.4), SIMDE_BFLOAT16_VALUE(-3.4), SIMDE_BFLOAT16_VALUE(-3.4),
        SIMDE_BFLOAT16_VALUE(-3.4), SIMDE_BFLOAT16_VALUE(-3.4), SIMDE_BFLOAT16_VALUE(-3.4), SIMDE_BFLOAT16_VALUE(-3.4) } },
    { { SIMDE_BFLOAT16_VALUE(8.1), SIMDE_BFLOAT16_VALUE(-0.0), SIMDE_BFLOAT16_VALUE(6.2), SIMDE_BFLOAT16_VALUE(-5.5) },
        INT8_C(3),
      { SIMDE_BFLOAT16_VALUE(-5.5), SIMDE_BFLOAT16_VALUE(-5.5), SIMDE_BFLOAT16_VALUE(-5.5), SIMDE_BFLOAT16_VALUE(-5.5),
        SIMDE_BFLOAT16_VALUE(-5.5), SIMDE_BFLOAT16_VALUE(-5.5), SIMDE_BFLOAT16_VALUE(-5.5), SIMDE_BFLOAT16_VALUE(-5.5) } },
    { { SIMDE_BFLOAT16_VALUE(-9.6), SIMDE_BFLOAT16_VALUE(6.7), SIMDE_BFLOAT16_VALUE(1.4), SIMDE_BFLOAT16_VALUE(10.7) },
        INT8_C(3),
      { SIMDE_BFLOAT16_VALUE(10.7), SIMDE_BFLOAT16_VALUE(10.7), SIMDE_BFLOAT16_VALUE(10.7), SIMDE_BFLOAT16_VALUE(10.7),
        SIMDE_BFLOAT16_VALUE(10.7), SIMDE_BFLOAT16_VALUE(10.7), SIMDE_BFLOAT16_VALUE(10.7), SIMDE_BFLOAT16_VALUE(10.7) } },
    { { SIMDE_BFLOAT16_VALUE(2.9), SIMDE_BFLOAT16_VALUE(-15.0), SIMDE_BFLOAT16_VALUE(14.8), SIMDE_BFLOAT16_VALUE(-2.2) },
        INT8_C(1),
      { SIMDE_BFLOAT16_VALUE(-15.0), SIMDE_BFLOAT16_VALUE(-15.0), SIMDE_BFLOAT16_VALUE(-15.0), SIMDE_BFLOAT16_VALUE(-15.0),
        SIMDE_BFLOAT16_VALUE(-15.0), SIMDE_BFLOAT16_VALUE(-15.0), SIMDE_BFLOAT16_VALUE(-15.0), SIMDE_BFLOAT16_VALUE(-15.0) } },
    { { SIMDE_BFLOAT16_VALUE(0.4), SIMDE_BFLOAT16_VALUE(0.2), SIMDE_BFLOAT16_VALUE(7.5), SIMDE_BFLOAT16_VALUE(-14.7) },
        INT8_C(2),
      { SIMDE_BFLOAT16_VALUE(7.5), SIMDE_BFLOAT16_VALUE(7.5), SIMDE_BFLOAT16_VALUE(7.5), SIMDE_BFLOAT16_VALUE(7.5),
        SIMDE_BFLOAT16_VALUE(7.5), SIMDE_BFLOAT16_VALUE(7.5), SIMDE_BFLOAT16_VALUE(7.5), SIMDE_BFLOAT16_VALUE(7.5) } },
    { { SIMDE_BFLOAT16_VALUE(-6.0), SIMDE_BFLOAT16_VALUE(0.4), SIMDE_BFLOAT16_VALUE(-8.9), SIMDE_BFLOAT16_VALUE(-11.3) },
        INT8_C(3),
      { SIMDE_BFLOAT16_VALUE(-11.3), SIMDE_BFLOAT16_VALUE(-11.3), SIMDE_BFLOAT16_VALUE(-11.3), SIMDE_BFLOAT16_VALUE(-11.3),
        SIMDE_BFLOAT16_VALUE(-11.3), SIMDE_BFLOAT16_VALUE(-11.3), SIMDE_BFLOAT16_VALUE(-11.3), SIMDE_BFLOAT16_VALUE(-11.3) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_bfloat16x4_t vec;
    simde_bfloat16x8_t r;

    vec = simde_vld1_bf16(test_vec[i].vec);
    SIMDE_CONSTIFY_4_(simde_vdupq_lane_bf16, r, (HEDLEY_UNREACHABLE(), simde_vdupq_n_bf16(SIMDE_BFLOAT16_VALUE(0.0))), test_vec[i].lane, vec);

    simde_test_arm_neon_assert_equal_bf16x8(r, simde_vld1q_bf16(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_vdupq_laneq_bf16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_bfloat16 vec[8];
    int lane;
    simde_bfloat16 r[8];
  } test_vec[] = {
    { {  SIMDE_BFLOAT16_VALUE(   -14.944),  SIMDE_BFLOAT16_VALUE(    29.976),  SIMDE_BFLOAT16_VALUE(     8.148),  SIMDE_BFLOAT16_VALUE(    -8.525),
         SIMDE_BFLOAT16_VALUE(     4.332),  SIMDE_BFLOAT16_VALUE(    -8.444),  SIMDE_BFLOAT16_VALUE(   -17.802),  SIMDE_BFLOAT16_VALUE(    18.658) },
         INT8_C(         3),
      {  SIMDE_BFLOAT16_VALUE(    -8.525),  SIMDE_BFLOAT16_VALUE(    -8.525),  SIMDE_BFLOAT16_VALUE(    -8.525),  SIMDE_BFLOAT16_VALUE(    -8.525),
         SIMDE_BFLOAT16_VALUE(    -8.525),  SIMDE_BFLOAT16_VALUE(    -8.525),  SIMDE_BFLOAT16_VALUE(    -8.525),  SIMDE_BFLOAT16_VALUE(    -8.525) } },
    { {  SIMDE_BFLOAT16_VALUE(     2.837),  SIMDE_BFLOAT16_VALUE(    -2.966),  SIMDE_BFLOAT16_VALUE(   -13.207),  SIMDE_BFLOAT16_VALUE(     9.802),
         SIMDE_BFLOAT16_VALUE(   -11.553),  SIMDE_BFLOAT16_VALUE(     4.185),  SIMDE_BFLOAT16_VALUE(    -2.087),  SIMDE_BFLOAT16_VALUE(   -25.138) },
         INT8_C(         0),
      {  SIMDE_BFLOAT16_VALUE(     2.837),  SIMDE_BFLOAT16_VALUE(     2.837),  SIMDE_BFLOAT16_VALUE(     2.837),  SIMDE_BFLOAT16_VALUE(     2.837),
         SIMDE_BFLOAT16_VALUE(     2.837),  SIMDE_BFLOAT16_VALUE(     2.837),  SIMDE_BFLOAT16_VALUE(     2.837),  SIMDE_BFLOAT16_VALUE(     2.837) } },
    { {  SIMDE_BFLOAT16_VALUE(    -9.082),  SIMDE_BFLOAT16_VALUE(   -20.470),  SIMDE_BFLOAT16_VALUE(    -2.951),  SIMDE_BFLOAT16_VALUE(   -21.315),
         SIMDE_BFLOAT16_VALUE(   -22.110),  SIMDE_BFLOAT16_VALUE(     4.867),  SIMDE_BFLOAT16_VALUE(    -1.873),  SIMDE_BFLOAT16_VALUE(    -9.236) },
         INT8_C(         6),
      {  SIMDE_BFLOAT16_VALUE(    -1.873),  SIMDE_BFLOAT16_VALUE(    -1.873),  SIMDE_BFLOAT16_VALUE(    -1.873),  SIMDE_BFLOAT16_VALUE(    -1.873),
         SIMDE_BFLOAT16_VALUE(    -1.873),  SIMDE_BFLOAT16_VALUE(    -1.873),  SIMDE_BFLOAT16_VALUE(    -1.873),  SIMDE_BFLOAT16_VALUE(    -1.873) } },
    { {  SIMDE_BFLOAT16_VALUE(    -6.811),  SIMDE_BFLOAT16_VALUE(   -18.944),  SIMDE_BFLOAT16_VALUE(    17.974),  SIMDE_BFLOAT16_VALUE(    23.871),
         SIMDE_BFLOAT16_VALUE(    22.903),  SIMDE_BFLOAT16_VALUE(   -21.458),  SIMDE_BFLOAT16_VALUE(    -7.777),  SIMDE_BFLOAT16_VALUE(    11.946) },
         INT8_C(         7),
      {  SIMDE_BFLOAT16_VALUE(    11.946),  SIMDE_BFLOAT16_VALUE(    11.946),  SIMDE_BFLOAT16_VALUE(    11.946),  SIMDE_BFLOAT16_VALUE(    11.946),
         SIMDE_BFLOAT16_VALUE(    11.946),  SIMDE_BFLOAT16_VALUE(    11.946),  SIMDE_BFLOAT16_VALUE(    11.946),  SIMDE_BFLOAT16_VALUE(    11.946) } },
    { {  SIMDE_BFLOAT16_VALUE(     4.721),  SIMDE_BFLOAT16_VALUE(    22.653),  SIMDE_BFLOAT16_VALUE(    -5.854),  SIMDE_BFLOAT16_VALUE(    -4.341),
         SIMDE_BFLOAT16_VALUE(     0.043),  SIMDE_BFLOAT16_VALUE(    -3.823),  SIMDE_BFLOAT16_VALUE(     4.788),  SIMDE_BFLOAT16_VALUE(    11.244) },
         INT8_C(         4),
      {  SIMDE_BFLOAT16_VALUE(     0.043),  SIMDE_BFLOAT16_VALUE(     0.043),  SIMDE_BFLOAT16_VALUE(     0.043),  SIMDE_BFLOAT16_VALUE(     0.043),
         SIMDE_BFLOAT16_VALUE(     0.043),  SIMDE_BFLOAT16_VALUE(     0.043),  SIMDE_BFLOAT16_VALUE(     0.043),  SIMDE_BFLOAT16_VALUE(     0.043) } },
    { {  SIMDE_BFLOAT16_VALUE(   -29.389),  SIMDE_BFLOAT16_VALUE(    25.831),  SIMDE_BFLOAT16_VALUE(     2.593),  SIMDE_BFLOAT16_VALUE(     0.655),
         SIMDE_BFLOAT16_VALUE(   -29.518),  SIMDE_BFLOAT16_VALUE(    21.627),  SIMDE_BFLOAT16_VALUE(    -9.484),  SIMDE_BFLOAT16_VALUE(     9.197) },
         INT8_C(         7),
      {  SIMDE_BFLOAT16_VALUE(     9.197),  SIMDE_BFLOAT16_VALUE(     9.197),  SIMDE_BFLOAT16_VALUE(     9.197),  SIMDE_BFLOAT16_VALUE(     9.197),
         SIMDE_BFLOAT16_VALUE(     9.197),  SIMDE_BFLOAT16_VALUE(     9.197),  SIMDE_BFLOAT16_VALUE(     9.197),  SIMDE_BFLOAT16_VALUE(     9.197) } },
    { {  SIMDE_BFLOAT16_VALUE(     6.412),  SIMDE_BFLOAT16_VALUE(    -2.948),  SIMDE_BFLOAT16_VALUE(    17.301),  SIMDE_BFLOAT16_VALUE(     9.426),
         SIMDE_BFLOAT16_VALUE(    23.317),  SIMDE_BFLOAT16_VALUE(    -1.470),  SIMDE_BFLOAT16_VALUE(   -28.086),  SIMDE_BFLOAT16_VALUE(    -4.040) },
         INT8_C(         6),
      {  SIMDE_BFLOAT16_VALUE(   -28.086),  SIMDE_BFLOAT16_VALUE(   -28.086),  SIMDE_BFLOAT16_VALUE(   -28.086),  SIMDE_BFLOAT16_VALUE(   -28.086),
         SIMDE_BFLOAT16_VALUE(   -28.086),  SIMDE_BFLOAT16_VALUE(   -28.086),  SIMDE_BFLOAT16_VALUE(   -28.086),  SIMDE_BFLOAT16_VALUE(   -28.086) } },
    { {  SIMDE_BFLOAT16_VALUE(    17.678),  SIMDE_BFLOAT16_VALUE(    12.177),  SIMDE_BFLOAT16_VALUE(   -14.208),  SIMDE_BFLOAT16_VALUE(   -15.268),
         SIMDE_BFLOAT16_VALUE(    15.600),  SIMDE_BFLOAT16_VALUE(   -16.025),  SIMDE_BFLOAT16_VALUE(    24.952),  SIMDE_BFLOAT16_VALUE(    -1.031) },
         INT8_C(         7),
      {  SIMDE_BFLOAT16_VALUE(    -1.031),  SIMDE_BFLOAT16_VALUE(    -1.031),  SIMDE_BFLOAT16_VALUE(    -1.031),  SIMDE_BFLOAT16_VALUE(    -1.031),
         SIMDE_BFLOAT16_VALUE(    -1.031),  SIMDE_BFLOAT16_VALUE(    -1.031),  SIMDE_BFLOAT16_VALUE(    -1.031),  SIMDE_BFLOAT16_VALUE(    -1.031) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_bfloat16x8_t vec;
    simde_bfloat16x8_t r;

    vec = simde_vld1q_bf16(test_vec[i].vec);
    SIMDE_CONSTIFY_8_(simde_vdupq_laneq_bf16, r, (HEDLEY_UNREACHABLE(), simde_vdupq_n_bf16(SIMDE_BFLOAT16_VALUE(0.0))), test_vec[i].lane, vec);

    simde_test_arm_neon_assert_equal_bf16x8(r, simde_vld1q_bf16(test_vec[i].r), 1);
  }

  return 0;
}

HEDLEY_DIAGNOSTIC_POP

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vdup_lane_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vdup_lane_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vdup_lane_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vdup_lane_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vdup_lane_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vdup_lane_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vdup_lane_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vdup_lane_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vdup_lane_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vdup_lane_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vdup_lane_u64)

SIMDE_TEST_FUNC_LIST_ENTRY(vdup_laneq_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vdup_laneq_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vdup_laneq_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vdup_laneq_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vdup_laneq_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vdup_laneq_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vdup_laneq_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vdup_laneq_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vdup_laneq_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vdup_laneq_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vdup_laneq_u64)

SIMDE_TEST_FUNC_LIST_ENTRY(vdupq_lane_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vdupq_lane_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vdupq_lane_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vdupq_lane_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vdupq_lane_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vdupq_lane_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vdupq_lane_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vdupq_lane_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vdupq_lane_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vdupq_lane_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vdupq_lane_u64)

SIMDE_TEST_FUNC_LIST_ENTRY(vdupq_laneq_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vdupq_laneq_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vdupq_laneq_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vdupq_laneq_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vdupq_laneq_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vdupq_laneq_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vdupq_laneq_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vdupq_laneq_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vdupq_laneq_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vdupq_laneq_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vdupq_laneq_u64)

SIMDE_TEST_FUNC_LIST_ENTRY(vdupb_lane_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vdupb_lane_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vdupb_laneq_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vdupb_laneq_u8)

SIMDE_TEST_FUNC_LIST_ENTRY(vduph_lane_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vduph_lane_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vduph_laneq_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vduph_laneq_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vduph_lane_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vduph_laneq_f16)

SIMDE_TEST_FUNC_LIST_ENTRY(vdup_lane_p8)
SIMDE_TEST_FUNC_LIST_ENTRY(vdup_lane_p16)
SIMDE_TEST_FUNC_LIST_ENTRY(vdup_lane_p64)

SIMDE_TEST_FUNC_LIST_ENTRY(vdup_laneq_p8)
SIMDE_TEST_FUNC_LIST_ENTRY(vdup_laneq_p16)
SIMDE_TEST_FUNC_LIST_ENTRY(vdup_laneq_p64)

SIMDE_TEST_FUNC_LIST_ENTRY(vdupq_lane_p8)
SIMDE_TEST_FUNC_LIST_ENTRY(vdupq_lane_p16)
SIMDE_TEST_FUNC_LIST_ENTRY(vdupq_lane_p64)

SIMDE_TEST_FUNC_LIST_ENTRY(vdupq_laneq_p8)
SIMDE_TEST_FUNC_LIST_ENTRY(vdupq_laneq_p16)
SIMDE_TEST_FUNC_LIST_ENTRY(vdupq_laneq_p64)

SIMDE_TEST_FUNC_LIST_ENTRY(vdupb_lane_p8)
SIMDE_TEST_FUNC_LIST_ENTRY(vdupb_laneq_p8)
SIMDE_TEST_FUNC_LIST_ENTRY(vduph_lane_p16)
SIMDE_TEST_FUNC_LIST_ENTRY(vduph_laneq_p16)

SIMDE_TEST_FUNC_LIST_ENTRY(vdup_lane_bf16)
SIMDE_TEST_FUNC_LIST_ENTRY(vdup_laneq_bf16)
SIMDE_TEST_FUNC_LIST_ENTRY(vdupq_lane_bf16)
SIMDE_TEST_FUNC_LIST_ENTRY(vdupq_laneq_bf16)
SIMDE_TEST_FUNC_LIST_ENTRY(vduph_lane_bf16)
SIMDE_TEST_FUNC_LIST_ENTRY(vduph_laneq_bf16)

SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
