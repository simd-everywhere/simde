#define SIMDE_TEST_ARM_NEON_INSN mulx_lane

#include "test-neon.h"
#include "../../../simde/arm/neon/mulx_lane.h"
#include "../../../simde/arm/neon/dup_n.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DIAGNOSTIC_DISABLE_UNREACHABLE_

static int
test_simde_vmulx_lane_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16 a[4];
    simde_float16 b[4];
    int lane;
    simde_float16 r[4];
  } test_vec[] = {
   { {  SIMDE_FLOAT16_VALUE(-2.2), SIMDE_FLOAT16_VALUE(-6.4), SIMDE_FLOAT16_VALUE(-8.8), SIMDE_FLOAT16_VALUE(-3.0) },
     {  SIMDE_FLOAT16_VALUE(-6.1), SIMDE_FLOAT16_VALUE(-3.0), SIMDE_FLOAT16_VALUE(-6.1), SIMDE_FLOAT16_VALUE(6.2) },
        INT8_C(2),
     {  SIMDE_FLOAT16_VALUE(13.420), SIMDE_FLOAT16_VALUE(39.040), SIMDE_FLOAT16_VALUE(53.680), SIMDE_FLOAT16_VALUE(18.300) } },
   { {  SIMDE_FLOAT16_VALUE(-5.5), SIMDE_FLOAT16_VALUE(0.2), SIMDE_FLOAT16_VALUE(9.1), SIMDE_FLOAT16_VALUE(6.4) },
     {  SIMDE_FLOAT16_VALUE(-0.2), SIMDE_FLOAT16_VALUE(-0.9), SIMDE_FLOAT16_VALUE(-7.8), SIMDE_FLOAT16_VALUE(-0.8) },
        INT8_C(3),
     {  SIMDE_FLOAT16_VALUE(4.400), SIMDE_FLOAT16_VALUE(-0.160), SIMDE_FLOAT16_VALUE(-7.280), SIMDE_FLOAT16_VALUE(-5.120) } },
   { {  SIMDE_FLOAT16_VALUE(9.2), SIMDE_FLOAT16_VALUE(3.3), SIMDE_FLOAT16_VALUE(-9.1), SIMDE_FLOAT16_VALUE(5.3) },
     {  SIMDE_FLOAT16_VALUE(3.4), SIMDE_FLOAT16_VALUE(1.2), SIMDE_FLOAT16_VALUE(6.2), SIMDE_FLOAT16_VALUE(1.3) },
        INT8_C(3),
     {  SIMDE_FLOAT16_VALUE(11.960), SIMDE_FLOAT16_VALUE(4.290), SIMDE_FLOAT16_VALUE(-11.830), SIMDE_FLOAT16_VALUE(6.890) } },
   { {  SIMDE_FLOAT16_VALUE(4.7), SIMDE_FLOAT16_VALUE(-1.9), SIMDE_FLOAT16_VALUE(-0.5), SIMDE_FLOAT16_VALUE(-3.3) },
     {  SIMDE_FLOAT16_VALUE(-4.7), SIMDE_FLOAT16_VALUE(-9.8), SIMDE_FLOAT16_VALUE(5.8), SIMDE_FLOAT16_VALUE(0.7) },
        INT8_C(3),
     {  SIMDE_FLOAT16_VALUE(3.290), SIMDE_FLOAT16_VALUE(-1.330), SIMDE_FLOAT16_VALUE(-0.350), SIMDE_FLOAT16_VALUE(-2.310) } },
   { {  SIMDE_FLOAT16_VALUE(-9.6), SIMDE_FLOAT16_VALUE(-2.1), SIMDE_FLOAT16_VALUE(-5.5), SIMDE_FLOAT16_VALUE(9.7) },
     {  SIMDE_FLOAT16_VALUE(-6.3), SIMDE_FLOAT16_VALUE(1.8), SIMDE_FLOAT16_VALUE(9.6), SIMDE_FLOAT16_VALUE(1.6) },
        INT8_C(3),
     {  SIMDE_FLOAT16_VALUE(-15.360), SIMDE_FLOAT16_VALUE(-3.360), SIMDE_FLOAT16_VALUE(-8.800), SIMDE_FLOAT16_VALUE(15.520) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x4_t a = simde_vld1_f16(test_vec[i].a);
    simde_float16x4_t b = simde_vld1_f16(test_vec[i].b);

    simde_float16x4_t r;
    SIMDE_CONSTIFY_4_(simde_vmulx_lane_f16, r, (HEDLEY_UNREACHABLE(), simde_vdup_n_f16(SIMDE_FLOAT16_VALUE(0.0))), test_vec[i].lane, a, b);

    simde_test_arm_neon_assert_equal_f16x4(r, simde_vld1_f16(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16x4_t a = simde_test_arm_neon_random_f16x4(-1000.0f, 1000.0f);
    simde_float16x4_t b = simde_test_arm_neon_random_f16x4(-1000.0f, 1000.0f);
    simde_float16x4_t r;
    int lane = simde_test_codegen_random_i8() & 3;
    SIMDE_CONSTIFY_4_(simde_vmulx_lane_f16, r, (HEDLEY_UNREACHABLE(), simde_vdup_n_f16(SIMDE_FLOAT16_VALUE(0.0))), test_vec[i].lane, a, b);

    simde_test_arm_neon_write_f16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i8(2, HEDLEY_STATIC_CAST(int8_t, lane), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmulx_lane_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a[2];
    simde_float32 b[2];
    int lane;
    simde_float32 r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -773.99), SIMDE_FLOAT32_C(   962.49) },
      { SIMDE_FLOAT32_C(  -531.26), SIMDE_FLOAT32_C(   540.16) },
       INT8_C(   1),
      { SIMDE_FLOAT32_C(-418078.41), SIMDE_FLOAT32_C(519898.56) } },
    { { SIMDE_FLOAT32_C(  -409.93), SIMDE_FLOAT32_C(   510.04) },
      { SIMDE_FLOAT32_C(  -659.02), SIMDE_FLOAT32_C(   102.89) },
       INT8_C(   1),
      { SIMDE_FLOAT32_C(-42177.70), SIMDE_FLOAT32_C( 52478.02) } },
    { { SIMDE_FLOAT32_C(  -999.99), SIMDE_FLOAT32_C(  -702.78) },
      { SIMDE_FLOAT32_C(  -114.76), SIMDE_FLOAT32_C(   327.24) },
       INT8_C(   1),
      { SIMDE_FLOAT32_C(-327236.72), SIMDE_FLOAT32_C(-229977.73) } },
    { { SIMDE_FLOAT32_C(   302.70), SIMDE_FLOAT32_C(  -977.40) },
      { SIMDE_FLOAT32_C(    45.80), SIMDE_FLOAT32_C(   892.47) },
       INT8_C(   1),
      { SIMDE_FLOAT32_C(270150.66), SIMDE_FLOAT32_C(-872300.19) } },
    { { SIMDE_FLOAT32_C(   306.93), SIMDE_FLOAT32_C(   371.14) },
      { SIMDE_FLOAT32_C(   546.46), SIMDE_FLOAT32_C(   323.18) },
       INT8_C(   1),
      { SIMDE_FLOAT32_C( 99193.63), SIMDE_FLOAT32_C(119945.02) } },
    { { SIMDE_FLOAT32_C(   148.94), SIMDE_FLOAT32_C(   -38.81) },
      { SIMDE_FLOAT32_C(  -107.93), SIMDE_FLOAT32_C(  -920.00) },
       INT8_C(   0),
      { SIMDE_FLOAT32_C(-16075.09), SIMDE_FLOAT32_C(  4188.76) } },
    { { SIMDE_FLOAT32_C(  -268.22), SIMDE_FLOAT32_C(  -693.98) },
      { SIMDE_FLOAT32_C(  -987.79), SIMDE_FLOAT32_C(   200.52) },
       INT8_C(   1),
      { SIMDE_FLOAT32_C(-53783.48), SIMDE_FLOAT32_C(-139156.88) } },
    { { SIMDE_FLOAT32_C(   646.59), SIMDE_FLOAT32_C(   790.59) },
      { SIMDE_FLOAT32_C(   356.21), SIMDE_FLOAT32_C(   987.57) },
       INT8_C(   0),
      { SIMDE_FLOAT32_C(230321.83), SIMDE_FLOAT32_C(281616.06) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t a = simde_vld1_f32(test_vec[i].a);
    simde_float32x2_t b = simde_vld1_f32(test_vec[i].b);

    simde_float32x2_t r;
    SIMDE_CONSTIFY_2_(simde_vmulx_lane_f32, r, (HEDLEY_UNREACHABLE(), simde_vdup_n_f32(SIMDE_FLOAT32_C(0.0))), test_vec[i].lane, a, b);

    simde_test_arm_neon_assert_equal_f32x2(r, simde_vld1_f32(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x2_t a = simde_test_arm_neon_random_f32x2(-1000.0, 1000.0);
    simde_float32x2_t b = simde_test_arm_neon_random_f32x2(-1000.0, 1000.0);
    int lane = simde_test_codegen_random_i8() & 1;

    simde_float32x2_t r;
    SIMDE_CONSTIFY_2_(simde_vmulx_lane_f32, r, (HEDLEY_UNREACHABLE(), simde_vdup_n_f32(SIMDE_FLOAT32_C(0.0))), lane, a, b);

    simde_test_arm_neon_write_f32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i8(2, HEDLEY_STATIC_CAST(int8_t, lane), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmulx_lane_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 a[1];
    simde_float64 b[1];
    simde_float64 r[1];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(   361.11) },
      { SIMDE_FLOAT64_C(  -650.09) },
      { SIMDE_FLOAT64_C(-234754.00) } },
    { { SIMDE_FLOAT64_C(    96.20) },
      { SIMDE_FLOAT64_C(   967.05) },
      { SIMDE_FLOAT64_C( 93030.21) } },
    { { SIMDE_FLOAT64_C(   -44.02) },
      { SIMDE_FLOAT64_C(   966.32) },
      { SIMDE_FLOAT64_C(-42537.41) } },
    { { SIMDE_FLOAT64_C(   207.91) },
      { SIMDE_FLOAT64_C(   922.18) },
      { SIMDE_FLOAT64_C(191730.44) } },
    { { SIMDE_FLOAT64_C(   263.40) },
      { SIMDE_FLOAT64_C(  -535.20) },
      { SIMDE_FLOAT64_C(-140971.68) } },
    { { SIMDE_FLOAT64_C(  -474.15) },
      { SIMDE_FLOAT64_C(   105.73) },
      { SIMDE_FLOAT64_C(-50131.88) } },
    { { SIMDE_FLOAT64_C(  -684.09) },
      { SIMDE_FLOAT64_C(  -137.80) },
      { SIMDE_FLOAT64_C( 94267.60) } },
    { { SIMDE_FLOAT64_C(   842.76) },
      { SIMDE_FLOAT64_C(  -239.29) },
      { SIMDE_FLOAT64_C(-201664.04) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x1_t a = simde_vld1_f64(test_vec[i].a);
    simde_float64x1_t b = simde_vld1_f64(test_vec[i].b);
    simde_float64x1_t r = simde_vmulx_lane_f64(a, b, 0);

    simde_test_arm_neon_assert_equal_f64x1(r, simde_vld1_f64(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x1_t a = simde_test_arm_neon_random_f64x1(-1000.0, 1000.0);
    simde_float64x1_t b = simde_test_arm_neon_random_f64x1(-1000.0, 1000.0);
    simde_float64x1_t r = simde_vmulx_lane_f64(a, b, 0);

    simde_test_arm_neon_write_f64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x1(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmulxq_lane_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16 a[8];
    simde_float16 b[4];
    int lane;
    simde_float16 r[8];
  } test_vec[] = {
  { { SIMDE_FLOAT16_VALUE( 218.125), SIMDE_FLOAT16_VALUE( 147.75), SIMDE_FLOAT16_VALUE( 163.875), SIMDE_FLOAT16_VALUE( 3.16796875),
      SIMDE_FLOAT16_VALUE( 168.5), SIMDE_FLOAT16_VALUE( 4.4453125), SIMDE_FLOAT16_VALUE( 166.25), SIMDE_FLOAT16_VALUE( 95.0625), },
    { SIMDE_FLOAT16_VALUE( 1.25), SIMDE_FLOAT16_VALUE( 69.25), SIMDE_FLOAT16_VALUE( 68.1875), SIMDE_FLOAT16_VALUE( 71.3125) },
      INT8_C(   0),
    { SIMDE_FLOAT16_VALUE(272.65625), SIMDE_FLOAT16_VALUE(184.6875), SIMDE_FLOAT16_VALUE(204.84375), SIMDE_FLOAT16_VALUE(3.95947265625),
      SIMDE_FLOAT16_VALUE(210.625), SIMDE_FLOAT16_VALUE(5.556640625), SIMDE_FLOAT16_VALUE(207.8125), SIMDE_FLOAT16_VALUE(118.828125) } },
  { { SIMDE_FLOAT16_VALUE( -190.5), SIMDE_FLOAT16_VALUE( -167.5), SIMDE_FLOAT16_VALUE( -108.0), SIMDE_FLOAT16_VALUE( -18.5),
      SIMDE_FLOAT16_VALUE( -45.0), SIMDE_FLOAT16_VALUE( -37.2), SIMDE_FLOAT16_VALUE( -41.25), SIMDE_FLOAT16_VALUE( -212.4), },
    { SIMDE_FLOAT16_VALUE( 193.0), SIMDE_FLOAT16_VALUE( 17.5), SIMDE_FLOAT16_VALUE( 179.5), SIMDE_FLOAT16_VALUE( 116.2), },
      INT8_C(   1),
    { SIMDE_FLOAT16_VALUE(-3333.75), SIMDE_FLOAT16_VALUE(-2931.25), SIMDE_FLOAT16_VALUE(-1890.0), SIMDE_FLOAT16_VALUE(-323.75),
      SIMDE_FLOAT16_VALUE(-787.5), SIMDE_FLOAT16_VALUE(-651.0), SIMDE_FLOAT16_VALUE(-721.875), SIMDE_FLOAT16_VALUE(-3717.0) } },
  { { SIMDE_FLOAT16_VALUE( 19.0), SIMDE_FLOAT16_VALUE( 83.2), SIMDE_FLOAT16_VALUE( 7.75), SIMDE_FLOAT16_VALUE( 12.125),
      SIMDE_FLOAT16_VALUE( 15.3), SIMDE_FLOAT16_VALUE( 26.5), SIMDE_FLOAT16_VALUE( 39.5), SIMDE_FLOAT16_VALUE( -7.25), },
    { SIMDE_FLOAT16_VALUE( -152.875), SIMDE_FLOAT16_VALUE( -221.625), SIMDE_FLOAT16_VALUE( -9.2), SIMDE_FLOAT16_VALUE( -251.0) },
      INT8_C(   2),
    { SIMDE_FLOAT16_VALUE(-174.875), SIMDE_FLOAT16_VALUE(-765.44), SIMDE_FLOAT16_VALUE(-71.4), SIMDE_FLOAT16_VALUE(-111.55),
      SIMDE_FLOAT16_VALUE(-140.76), SIMDE_FLOAT16_VALUE(-243.875), SIMDE_FLOAT16_VALUE(-363.4), SIMDE_FLOAT16_VALUE(66.7) } },
  { { SIMDE_FLOAT16_VALUE( -46.25), SIMDE_FLOAT16_VALUE( -74.5), SIMDE_FLOAT16_VALUE( -14.5), SIMDE_FLOAT16_VALUE( -1.125),
      SIMDE_FLOAT16_VALUE( -13.25), SIMDE_FLOAT16_VALUE( -93.5), SIMDE_FLOAT16_VALUE( -19.0), SIMDE_FLOAT16_VALUE( -50.5), },
    { SIMDE_FLOAT16_VALUE( -165.875), SIMDE_FLOAT16_VALUE( -0.9404296875), SIMDE_FLOAT16_VALUE( -124.9375), SIMDE_FLOAT16_VALUE( -2.5) },
      INT8_C(   3),
    { SIMDE_FLOAT16_VALUE( 115.625), SIMDE_FLOAT16_VALUE( 186.25), SIMDE_FLOAT16_VALUE( 36.25), SIMDE_FLOAT16_VALUE( 2.8125),
      SIMDE_FLOAT16_VALUE( 33.125), SIMDE_FLOAT16_VALUE( 233.75), SIMDE_FLOAT16_VALUE( 47.5), SIMDE_FLOAT16_VALUE( 126.25), } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x8_t a = simde_vld1q_f16(test_vec[i].a);
    simde_float16x4_t b = simde_vld1_f16(test_vec[i].b);

    simde_float16x8_t r;
    SIMDE_CONSTIFY_4_(simde_vmulxq_lane_f16, r, (HEDLEY_UNREACHABLE(), simde_vdupq_n_f16(SIMDE_FLOAT16_VALUE(0.0))), test_vec[i].lane, a, b);

    simde_test_arm_neon_assert_equal_f16x8(r, simde_vld1q_f16(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16x8_t a = simde_test_arm_neon_random_f16x8(-1000.0f, 1000.0f);
    simde_float16x4_t b = simde_test_arm_neon_random_f16x4(-1000.0f, 1000.0f);
    simde_float16x8_t r;
    int lane = simde_test_codegen_random_i8() & 3;
    SIMDE_CONSTIFY_4_(simde_vmulxq_lane_f16, r, (HEDLEY_UNREACHABLE(), simde_vdupq_n_f16(SIMDE_FLOAT16_VALUE(0.0))), test_vec[i].lane, a, b);

    simde_test_arm_neon_write_f16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i8(2, HEDLEY_STATIC_CAST(int8_t, lane), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmulxq_lane_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a[4];
    simde_float32 b[2];
    int lane;
    simde_float32 r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   213.13), SIMDE_FLOAT32_C(   981.87), SIMDE_FLOAT32_C(   831.27), SIMDE_FLOAT32_C(   118.60) },
      { SIMDE_FLOAT32_C(  -324.54), SIMDE_FLOAT32_C(   912.98) },
       INT8_C(   0),
      { SIMDE_FLOAT32_C(-69169.21), SIMDE_FLOAT32_C(-318656.09), SIMDE_FLOAT32_C(-269780.38), SIMDE_FLOAT32_C(-38490.45) } },
    { { SIMDE_FLOAT32_C(   398.02), SIMDE_FLOAT32_C(    -7.67), SIMDE_FLOAT32_C(   260.87), SIMDE_FLOAT32_C(   702.83) },
      { SIMDE_FLOAT32_C(   333.84), SIMDE_FLOAT32_C(   873.07) },
       INT8_C(   1),
      { SIMDE_FLOAT32_C(347499.31), SIMDE_FLOAT32_C( -6696.45), SIMDE_FLOAT32_C(227757.77), SIMDE_FLOAT32_C(613619.81) } },
    { { SIMDE_FLOAT32_C(  -354.62), SIMDE_FLOAT32_C(   438.98), SIMDE_FLOAT32_C(    27.69), SIMDE_FLOAT32_C(  -892.52) },
      { SIMDE_FLOAT32_C(   356.02), SIMDE_FLOAT32_C(  -450.46) },
       INT8_C(   0),
      { SIMDE_FLOAT32_C(-126251.80), SIMDE_FLOAT32_C(156285.66), SIMDE_FLOAT32_C(  9858.19), SIMDE_FLOAT32_C(-317754.97) } },
    { { SIMDE_FLOAT32_C(  -796.85), SIMDE_FLOAT32_C(   254.52), SIMDE_FLOAT32_C(   640.39), SIMDE_FLOAT32_C(   497.52) },
      { SIMDE_FLOAT32_C(   257.72), SIMDE_FLOAT32_C(    -9.95) },
       INT8_C(   1),
      { SIMDE_FLOAT32_C(  7928.66), SIMDE_FLOAT32_C( -2532.47), SIMDE_FLOAT32_C( -6371.88), SIMDE_FLOAT32_C( -4950.32) } },
    { { SIMDE_FLOAT32_C(  -951.01), SIMDE_FLOAT32_C(  -981.56), SIMDE_FLOAT32_C(    34.30), SIMDE_FLOAT32_C(   262.12) },
      { SIMDE_FLOAT32_C(  -999.70), SIMDE_FLOAT32_C(  -134.44) },
       INT8_C(   0),
      { SIMDE_FLOAT32_C(950724.69), SIMDE_FLOAT32_C(981265.56), SIMDE_FLOAT32_C(-34289.71), SIMDE_FLOAT32_C(-262041.36) } },
    { { SIMDE_FLOAT32_C(  -324.23), SIMDE_FLOAT32_C(  -221.45), SIMDE_FLOAT32_C(   748.19), SIMDE_FLOAT32_C(  -926.22) },
      { SIMDE_FLOAT32_C(   770.88), SIMDE_FLOAT32_C(     9.06) },
       INT8_C(   1),
      { SIMDE_FLOAT32_C( -2937.52), SIMDE_FLOAT32_C( -2006.34), SIMDE_FLOAT32_C(  6778.60), SIMDE_FLOAT32_C( -8391.55) } },
    { { SIMDE_FLOAT32_C(   104.72), SIMDE_FLOAT32_C(  -117.86), SIMDE_FLOAT32_C(  -296.55), SIMDE_FLOAT32_C(   750.10) },
      { SIMDE_FLOAT32_C(  -678.89), SIMDE_FLOAT32_C(   731.14) },
       INT8_C(   1),
      { SIMDE_FLOAT32_C( 76564.98), SIMDE_FLOAT32_C(-86172.16), SIMDE_FLOAT32_C(-216819.56), SIMDE_FLOAT32_C(548428.12) } },
    { { SIMDE_FLOAT32_C(   677.13), SIMDE_FLOAT32_C(  -719.32), SIMDE_FLOAT32_C(  -444.57), SIMDE_FLOAT32_C(   880.28) },
      { SIMDE_FLOAT32_C(   535.19), SIMDE_FLOAT32_C(  -804.18) },
       INT8_C(   0),
      { SIMDE_FLOAT32_C(362393.22), SIMDE_FLOAT32_C(-384972.88), SIMDE_FLOAT32_C(-237929.42), SIMDE_FLOAT32_C(471117.06) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_float32x2_t b = simde_vld1_f32(test_vec[i].b);

    simde_float32x4_t r;
    SIMDE_CONSTIFY_2_(simde_vmulxq_lane_f32, r, (HEDLEY_UNREACHABLE(), simde_vdupq_n_f32(SIMDE_FLOAT32_C(0.0))), test_vec[i].lane, a, b);

    simde_test_arm_neon_assert_equal_f32x4(r, simde_vld1q_f32(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x4_t a = simde_test_arm_neon_random_f32x4(-1000.0, 1000.0);
    simde_float32x2_t b = simde_test_arm_neon_random_f32x2(-1000.0, 1000.0);
    int lane = simde_test_codegen_random_i8() & 1;

    simde_float32x4_t r;
    SIMDE_CONSTIFY_2_(simde_vmulxq_lane_f32, r, (HEDLEY_UNREACHABLE(), simde_vdupq_n_f32(SIMDE_FLOAT32_C(0.0))), lane, a, b);

    simde_test_arm_neon_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i8(2, HEDLEY_STATIC_CAST(int8_t, lane), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmulxq_lane_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 a[2];
    simde_float64 b[1];
    simde_float64 r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(  -207.09), SIMDE_FLOAT64_C(   185.86) },
      { SIMDE_FLOAT64_C(   705.49) },
      { SIMDE_FLOAT64_C(-146099.92), SIMDE_FLOAT64_C(131122.37) } },
    { { SIMDE_FLOAT64_C(  -158.10), SIMDE_FLOAT64_C(   204.30) },
      { SIMDE_FLOAT64_C(  -260.21) },
      { SIMDE_FLOAT64_C( 41139.20), SIMDE_FLOAT64_C(-53160.90) } },
    { { SIMDE_FLOAT64_C(  -895.97), SIMDE_FLOAT64_C(   204.60) },
      { SIMDE_FLOAT64_C(   605.35) },
      { SIMDE_FLOAT64_C(-542375.44), SIMDE_FLOAT64_C(123854.61) } },
    { { SIMDE_FLOAT64_C(  -515.25), SIMDE_FLOAT64_C(   880.37) },
      { SIMDE_FLOAT64_C(  -616.10) },
      { SIMDE_FLOAT64_C(317445.53), SIMDE_FLOAT64_C(-542395.96) } },
    { { SIMDE_FLOAT64_C(  -767.06), SIMDE_FLOAT64_C(   954.16) },
      { SIMDE_FLOAT64_C(  -845.22) },
      { SIMDE_FLOAT64_C(648334.45), SIMDE_FLOAT64_C(-806475.12) } },
    { { SIMDE_FLOAT64_C(   242.00), SIMDE_FLOAT64_C(   730.77) },
      { SIMDE_FLOAT64_C(   259.50) },
      { SIMDE_FLOAT64_C( 62799.00), SIMDE_FLOAT64_C(189634.82) } },
    { { SIMDE_FLOAT64_C(  -875.86), SIMDE_FLOAT64_C(  -565.78) },
      { SIMDE_FLOAT64_C(     9.60) },
      { SIMDE_FLOAT64_C( -8408.26), SIMDE_FLOAT64_C( -5431.49) } },
    { { SIMDE_FLOAT64_C(  -554.75), SIMDE_FLOAT64_C(  -834.64) },
      { SIMDE_FLOAT64_C(  -132.82) },
      { SIMDE_FLOAT64_C( 73681.89), SIMDE_FLOAT64_C(110856.88) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2_t a = simde_vld1q_f64(test_vec[i].a);
    simde_float64x1_t b = simde_vld1_f64(test_vec[i].b);
    simde_float64x2_t r = simde_vmulxq_lane_f64(a, b, 0);

    simde_test_arm_neon_assert_equal_f64x2(r, simde_vld1q_f64(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x2_t a = simde_test_arm_neon_random_f64x2(-1000.0, 1000.0);
    simde_float64x1_t b = simde_test_arm_neon_random_f64x1(-1000.0, 1000.0);

    simde_float64x2_t r = simde_vmulxq_lane_f64(a, b, 0);

    simde_test_arm_neon_write_f64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x1(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmulxq_laneq_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16 a[8];
    simde_float16 b[8];
    int lane;
    simde_float16 r[8];
  } test_vec[] = {
   { {  SIMDE_FLOAT16_VALUE(-4.6), SIMDE_FLOAT16_VALUE(0.6), SIMDE_FLOAT16_VALUE(5.9), SIMDE_FLOAT16_VALUE(-1.8),
        SIMDE_FLOAT16_VALUE(0.0), SIMDE_FLOAT16_VALUE(-2.4), SIMDE_FLOAT16_VALUE(-1.9), SIMDE_FLOAT16_VALUE(9.7) },
     {  SIMDE_FLOAT16_VALUE(9.3), SIMDE_FLOAT16_VALUE(-0.3), SIMDE_FLOAT16_VALUE(-6.4), SIMDE_FLOAT16_VALUE(0.1),
        SIMDE_FLOAT16_VALUE(3.6), SIMDE_FLOAT16_VALUE(-2.8), SIMDE_FLOAT16_VALUE(-8.4), SIMDE_FLOAT16_VALUE(2.2) },
        INT8_C(6),
     {  SIMDE_FLOAT16_VALUE(38.640), SIMDE_FLOAT16_VALUE(-5.040), SIMDE_FLOAT16_VALUE(-49.560), SIMDE_FLOAT16_VALUE(15.120),
        SIMDE_FLOAT16_VALUE(-0.000), SIMDE_FLOAT16_VALUE(20.160), SIMDE_FLOAT16_VALUE(15.960), SIMDE_FLOAT16_VALUE(-81.480) } },
   { {  SIMDE_FLOAT16_VALUE(2.6), SIMDE_FLOAT16_VALUE(3.1), SIMDE_FLOAT16_VALUE(3.2), SIMDE_FLOAT16_VALUE(-8.3),
        SIMDE_FLOAT16_VALUE(5.4), SIMDE_FLOAT16_VALUE(1.8), SIMDE_FLOAT16_VALUE(-7.8), SIMDE_FLOAT16_VALUE(-7.3) },
     {  SIMDE_FLOAT16_VALUE(-3.5), SIMDE_FLOAT16_VALUE(5.5), SIMDE_FLOAT16_VALUE(-0.1), SIMDE_FLOAT16_VALUE(2.4),
        SIMDE_FLOAT16_VALUE(9.5), SIMDE_FLOAT16_VALUE(-3.3), SIMDE_FLOAT16_VALUE(0.9), SIMDE_FLOAT16_VALUE(5.2) },
        INT8_C(1),
     {  SIMDE_FLOAT16_VALUE(14.300), SIMDE_FLOAT16_VALUE(17.050), SIMDE_FLOAT16_VALUE(17.600), SIMDE_FLOAT16_VALUE(-45.650),
        SIMDE_FLOAT16_VALUE(29.700), SIMDE_FLOAT16_VALUE(9.900), SIMDE_FLOAT16_VALUE(-42.900), SIMDE_FLOAT16_VALUE(-40.150) } },
   { {  SIMDE_FLOAT16_VALUE(-0.2), SIMDE_FLOAT16_VALUE(2.2), SIMDE_FLOAT16_VALUE(6.7), SIMDE_FLOAT16_VALUE(-6.7),
        SIMDE_FLOAT16_VALUE(0.8), SIMDE_FLOAT16_VALUE(-5.1), SIMDE_FLOAT16_VALUE(1.0), SIMDE_FLOAT16_VALUE(-8.7) },
     {  SIMDE_FLOAT16_VALUE(-5.8), SIMDE_FLOAT16_VALUE(2.9), SIMDE_FLOAT16_VALUE(7.3), SIMDE_FLOAT16_VALUE(6.6),
        SIMDE_FLOAT16_VALUE(-0.3), SIMDE_FLOAT16_VALUE(6.2), SIMDE_FLOAT16_VALUE(2.5), SIMDE_FLOAT16_VALUE(0.2) },
        INT8_C(5),
     {  SIMDE_FLOAT16_VALUE(-1.240), SIMDE_FLOAT16_VALUE(13.640), SIMDE_FLOAT16_VALUE(41.540), SIMDE_FLOAT16_VALUE(-41.540),
        SIMDE_FLOAT16_VALUE(4.960), SIMDE_FLOAT16_VALUE(-31.620), SIMDE_FLOAT16_VALUE(6.200), SIMDE_FLOAT16_VALUE(-53.940) } },
   { {  SIMDE_FLOAT16_VALUE(1.5), SIMDE_FLOAT16_VALUE(-3.3), SIMDE_FLOAT16_VALUE(-0.3), SIMDE_FLOAT16_VALUE(1.4),
        SIMDE_FLOAT16_VALUE(-3.7), SIMDE_FLOAT16_VALUE(1.1), SIMDE_FLOAT16_VALUE(0.6), SIMDE_FLOAT16_VALUE(0.8) },
     {  SIMDE_FLOAT16_VALUE(-4.1), SIMDE_FLOAT16_VALUE(2.0), SIMDE_FLOAT16_VALUE(-6.6), SIMDE_FLOAT16_VALUE(1.6),
        SIMDE_FLOAT16_VALUE(1.3), SIMDE_FLOAT16_VALUE(8.6), SIMDE_FLOAT16_VALUE(8.0), SIMDE_FLOAT16_VALUE(2.0) },
        INT8_C(5),
     {  SIMDE_FLOAT16_VALUE(12.900), SIMDE_FLOAT16_VALUE(-28.380), SIMDE_FLOAT16_VALUE(-2.580), SIMDE_FLOAT16_VALUE(12.040),
        SIMDE_FLOAT16_VALUE(-31.820), SIMDE_FLOAT16_VALUE(9.460), SIMDE_FLOAT16_VALUE(5.160), SIMDE_FLOAT16_VALUE(6.880) } },
   { {  SIMDE_FLOAT16_VALUE(-0.3), SIMDE_FLOAT16_VALUE(9.6), SIMDE_FLOAT16_VALUE(6.8), SIMDE_FLOAT16_VALUE(-7.4),
        SIMDE_FLOAT16_VALUE(6.2), SIMDE_FLOAT16_VALUE(-3.4), SIMDE_FLOAT16_VALUE(6.5), SIMDE_FLOAT16_VALUE(-9.6) },
     {  SIMDE_FLOAT16_VALUE(-3.2), SIMDE_FLOAT16_VALUE(-9.0), SIMDE_FLOAT16_VALUE(-1.0), SIMDE_FLOAT16_VALUE(7.0),
        SIMDE_FLOAT16_VALUE(7.8), SIMDE_FLOAT16_VALUE(9.6), SIMDE_FLOAT16_VALUE(-1.9), SIMDE_FLOAT16_VALUE(3.1) },
        INT8_C(6),
     {  SIMDE_FLOAT16_VALUE(0.570), SIMDE_FLOAT16_VALUE(-18.240), SIMDE_FLOAT16_VALUE(-12.920), SIMDE_FLOAT16_VALUE(14.060),
        SIMDE_FLOAT16_VALUE(-11.780), SIMDE_FLOAT16_VALUE(6.460), SIMDE_FLOAT16_VALUE(-12.350), SIMDE_FLOAT16_VALUE(18.240) } },
   { {  SIMDE_FLOAT16_VALUE(-2.6), SIMDE_FLOAT16_VALUE(3.3), SIMDE_FLOAT16_VALUE(3.3), SIMDE_FLOAT16_VALUE(-1.0),
        SIMDE_FLOAT16_VALUE(-2.4), SIMDE_FLOAT16_VALUE(7.8), SIMDE_FLOAT16_VALUE(0.8), SIMDE_FLOAT16_VALUE(-1.4) },
     {  SIMDE_FLOAT16_VALUE(6.5), SIMDE_FLOAT16_VALUE(-8.3), SIMDE_FLOAT16_VALUE(8.1), SIMDE_FLOAT16_VALUE(0.2),
        SIMDE_FLOAT16_VALUE(1.4), SIMDE_FLOAT16_VALUE(-2.7), SIMDE_FLOAT16_VALUE(7.9), SIMDE_FLOAT16_VALUE(-8.9) },
        INT8_C(6),
     {  SIMDE_FLOAT16_VALUE(-20.540), SIMDE_FLOAT16_VALUE(26.070), SIMDE_FLOAT16_VALUE(26.070), SIMDE_FLOAT16_VALUE(-7.900),
        SIMDE_FLOAT16_VALUE(-18.960), SIMDE_FLOAT16_VALUE(61.620), SIMDE_FLOAT16_VALUE(6.320), SIMDE_FLOAT16_VALUE(-11.060) } },
   { {  SIMDE_FLOAT16_VALUE(-3.9), SIMDE_FLOAT16_VALUE(-6.7), SIMDE_FLOAT16_VALUE(0.4), SIMDE_FLOAT16_VALUE(1.3),
        SIMDE_FLOAT16_VALUE(9.4), SIMDE_FLOAT16_VALUE(-5.3), SIMDE_FLOAT16_VALUE(-4.6), SIMDE_FLOAT16_VALUE(-6.5) },
     {  SIMDE_FLOAT16_VALUE(8.3), SIMDE_FLOAT16_VALUE(2.5), SIMDE_FLOAT16_VALUE(-0.5), SIMDE_FLOAT16_VALUE(-7.4),
        SIMDE_FLOAT16_VALUE(-7.7), SIMDE_FLOAT16_VALUE(-8.0), SIMDE_FLOAT16_VALUE(9.0), SIMDE_FLOAT16_VALUE(-0.2) },
        INT8_C(4),
     {  SIMDE_FLOAT16_VALUE(30.030), SIMDE_FLOAT16_VALUE(51.590), SIMDE_FLOAT16_VALUE(-3.080), SIMDE_FLOAT16_VALUE(-10.010),
        SIMDE_FLOAT16_VALUE(-72.380), SIMDE_FLOAT16_VALUE(40.810), SIMDE_FLOAT16_VALUE(35.420), SIMDE_FLOAT16_VALUE(50.050) } },
   { {  SIMDE_FLOAT16_VALUE(1.4), SIMDE_FLOAT16_VALUE(-3.5), SIMDE_FLOAT16_VALUE(7.2), SIMDE_FLOAT16_VALUE(2.3),
        SIMDE_FLOAT16_VALUE(-1.5), SIMDE_FLOAT16_VALUE(-9.1), SIMDE_FLOAT16_VALUE(-9.4), SIMDE_FLOAT16_VALUE(0.9) },
     {  SIMDE_FLOAT16_VALUE(-1.4), SIMDE_FLOAT16_VALUE(9.7), SIMDE_FLOAT16_VALUE(-0.7), SIMDE_FLOAT16_VALUE(9.1),
        SIMDE_FLOAT16_VALUE(-7.9), SIMDE_FLOAT16_VALUE(1.5), SIMDE_FLOAT16_VALUE(9.7), SIMDE_FLOAT16_VALUE(2.4) },
        INT8_C(1),
     {  SIMDE_FLOAT16_VALUE(13.580), SIMDE_FLOAT16_VALUE(-33.950), SIMDE_FLOAT16_VALUE(69.840), SIMDE_FLOAT16_VALUE(22.310),
        SIMDE_FLOAT16_VALUE(-14.550), SIMDE_FLOAT16_VALUE(-88.270), SIMDE_FLOAT16_VALUE(-91.180), SIMDE_FLOAT16_VALUE(8.730) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x8_t a = simde_vld1q_f16(test_vec[i].a);
    simde_float16x8_t b = simde_vld1q_f16(test_vec[i].b);

    simde_float16x8_t r;
    SIMDE_CONSTIFY_8_(simde_vmulxq_laneq_f16, r, (HEDLEY_UNREACHABLE(), simde_vdupq_n_f16(SIMDE_FLOAT16_VALUE(0.0))), test_vec[i].lane, a, b);

    simde_test_arm_neon_assert_equal_f16x8(r, simde_vld1q_f16(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16x8_t a = simde_test_arm_neon_random_f16x8(-1000.0f, 1000.0f);
    simde_float16x8_t b = simde_test_arm_neon_random_f16x8(-1000.0f, 1000.0f);
    simde_float16x8_t r;
    int lane = simde_test_codegen_random_i8() & 7;
    SIMDE_CONSTIFY_8_(simde_vmulxq_laneq_f16, r, (HEDLEY_UNREACHABLE(), simde_vdupq_n_f16(SIMDE_FLOAT16_VALUE(0.0))), test_vec[i].lane, a, b);

    simde_test_arm_neon_write_f16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i8(2, HEDLEY_STATIC_CAST(int8_t, lane), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmulxq_laneq_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a[4];
    simde_float32 b[4];
    int lane;
    simde_float32 r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -483.10), SIMDE_FLOAT32_C(   841.64), SIMDE_FLOAT32_C(   832.87), SIMDE_FLOAT32_C(   478.63) },
      { SIMDE_FLOAT32_C(   684.27), SIMDE_FLOAT32_C(  -437.87), SIMDE_FLOAT32_C(   138.75), SIMDE_FLOAT32_C(   -36.57) },
       INT8_C(   0),
      { SIMDE_FLOAT32_C(-330570.84), SIMDE_FLOAT32_C(575909.00), SIMDE_FLOAT32_C(569907.94), SIMDE_FLOAT32_C(327512.16) } },
    { { SIMDE_FLOAT32_C(   141.10), SIMDE_FLOAT32_C(   936.51), SIMDE_FLOAT32_C(  -996.31), SIMDE_FLOAT32_C(   809.04) },
      { SIMDE_FLOAT32_C(  -520.77), SIMDE_FLOAT32_C(  -383.63), SIMDE_FLOAT32_C(   396.57), SIMDE_FLOAT32_C(  -505.39) },
       INT8_C(   0),
      { SIMDE_FLOAT32_C(-73480.66), SIMDE_FLOAT32_C(-487706.34), SIMDE_FLOAT32_C(518848.38), SIMDE_FLOAT32_C(-421323.75) } },
    { { SIMDE_FLOAT32_C(   757.82), SIMDE_FLOAT32_C(  -769.31), SIMDE_FLOAT32_C(   479.87), SIMDE_FLOAT32_C(    27.24) },
      { SIMDE_FLOAT32_C(    87.58), SIMDE_FLOAT32_C(  -325.93), SIMDE_FLOAT32_C(  -147.19), SIMDE_FLOAT32_C(   630.99) },
       INT8_C(   1),
      { SIMDE_FLOAT32_C(-246996.27), SIMDE_FLOAT32_C(250741.20), SIMDE_FLOAT32_C(-156404.03), SIMDE_FLOAT32_C( -8878.33) } },
    { { SIMDE_FLOAT32_C(   921.82), SIMDE_FLOAT32_C(    48.37), SIMDE_FLOAT32_C(  -130.34), SIMDE_FLOAT32_C(   806.30) },
      { SIMDE_FLOAT32_C(   565.26), SIMDE_FLOAT32_C(  -288.70), SIMDE_FLOAT32_C(   639.18), SIMDE_FLOAT32_C(    43.89) },
       INT8_C(   3),
      { SIMDE_FLOAT32_C( 40458.68), SIMDE_FLOAT32_C(  2122.96), SIMDE_FLOAT32_C( -5720.62), SIMDE_FLOAT32_C( 35388.51) } },
    { { SIMDE_FLOAT32_C(  -798.70), SIMDE_FLOAT32_C(  -817.36), SIMDE_FLOAT32_C(   359.00), SIMDE_FLOAT32_C(   117.01) },
      { SIMDE_FLOAT32_C(   323.75), SIMDE_FLOAT32_C(   295.51), SIMDE_FLOAT32_C(   120.71), SIMDE_FLOAT32_C(   132.79) },
       INT8_C(   3),
      { SIMDE_FLOAT32_C(-106059.37), SIMDE_FLOAT32_C(-108537.23), SIMDE_FLOAT32_C( 47671.61), SIMDE_FLOAT32_C( 15537.76) } },
    { { SIMDE_FLOAT32_C(   737.08), SIMDE_FLOAT32_C(  -470.63), SIMDE_FLOAT32_C(  -730.64), SIMDE_FLOAT32_C(    79.42) },
      { SIMDE_FLOAT32_C(  -712.82), SIMDE_FLOAT32_C(  -499.95), SIMDE_FLOAT32_C(  -440.71), SIMDE_FLOAT32_C(   314.43) },
       INT8_C(   1),
      { SIMDE_FLOAT32_C(-368503.16), SIMDE_FLOAT32_C(235291.48), SIMDE_FLOAT32_C(365283.47), SIMDE_FLOAT32_C(-39706.03) } },
    { { SIMDE_FLOAT32_C(   233.36), SIMDE_FLOAT32_C(  -832.76), SIMDE_FLOAT32_C(   218.62), SIMDE_FLOAT32_C(   442.88) },
      { SIMDE_FLOAT32_C(  -910.95), SIMDE_FLOAT32_C(  -733.02), SIMDE_FLOAT32_C(  -687.47), SIMDE_FLOAT32_C(   895.36) },
       INT8_C(   1),
      { SIMDE_FLOAT32_C(-171057.55), SIMDE_FLOAT32_C(610429.75), SIMDE_FLOAT32_C(-160252.83), SIMDE_FLOAT32_C(-324639.91) } },
    { { SIMDE_FLOAT32_C(    23.84), SIMDE_FLOAT32_C(   534.54), SIMDE_FLOAT32_C(  -123.86), SIMDE_FLOAT32_C(   419.41) },
      { SIMDE_FLOAT32_C(   735.84), SIMDE_FLOAT32_C(    58.79), SIMDE_FLOAT32_C(  -221.60), SIMDE_FLOAT32_C(  -147.15) },
       INT8_C(   1),
      { SIMDE_FLOAT32_C(  1401.55), SIMDE_FLOAT32_C( 31425.61), SIMDE_FLOAT32_C( -7281.73), SIMDE_FLOAT32_C( 24657.12) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_float32x4_t b = simde_vld1q_f32(test_vec[i].b);

    simde_float32x4_t r;
    SIMDE_CONSTIFY_4_(simde_vmulxq_laneq_f32, r, (HEDLEY_UNREACHABLE(), simde_vdupq_n_f32(SIMDE_FLOAT32_C(0.0))), test_vec[i].lane, a, b);

    simde_test_arm_neon_assert_equal_f32x4(r, simde_vld1q_f32(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x4_t a = simde_test_arm_neon_random_f32x4(-1000.0, 1000.0);
    simde_float32x4_t b = simde_test_arm_neon_random_f32x4(-1000.0, 1000.0);
    int lane = simde_test_codegen_random_i8() & 3;

    simde_float32x4_t r;
    SIMDE_CONSTIFY_4_(simde_vmulxq_laneq_f32, r, (HEDLEY_UNREACHABLE(), simde_vdupq_n_f32(SIMDE_FLOAT32_C(0.0))), lane, a, b);

    simde_test_arm_neon_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i8(2, HEDLEY_STATIC_CAST(int8_t, lane), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmulxq_laneq_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 a[2];
    simde_float64 b[2];
    int lane;
    simde_float64 r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(    -8.30), SIMDE_FLOAT64_C(    39.42) },
      { SIMDE_FLOAT64_C(  -145.93), SIMDE_FLOAT64_C(  -489.21) },
       INT8_C(   0),
      { SIMDE_FLOAT64_C(  1211.22), SIMDE_FLOAT64_C( -5752.56) } },
    { { SIMDE_FLOAT64_C(  -947.61), SIMDE_FLOAT64_C(   662.96) },
      { SIMDE_FLOAT64_C(   341.51), SIMDE_FLOAT64_C(   581.12) },
       INT8_C(   1),
      { SIMDE_FLOAT64_C(-550675.12), SIMDE_FLOAT64_C(385259.32) } },
    { { SIMDE_FLOAT64_C(   777.29), SIMDE_FLOAT64_C(   252.16) },
      { SIMDE_FLOAT64_C(   955.20), SIMDE_FLOAT64_C(  -332.93) },
       INT8_C(   1),
      { SIMDE_FLOAT64_C(-258783.16), SIMDE_FLOAT64_C(-83951.63) } },
    { { SIMDE_FLOAT64_C(   446.81), SIMDE_FLOAT64_C(  -501.58) },
      { SIMDE_FLOAT64_C(  -807.53), SIMDE_FLOAT64_C(  -797.54) },
       INT8_C(   0),
      { SIMDE_FLOAT64_C(-360812.48), SIMDE_FLOAT64_C(405040.90) } },
    { { SIMDE_FLOAT64_C(   357.00), SIMDE_FLOAT64_C(  -144.04) },
      { SIMDE_FLOAT64_C(   968.23), SIMDE_FLOAT64_C(  -970.92) },
       INT8_C(   0),
      { SIMDE_FLOAT64_C(345658.11), SIMDE_FLOAT64_C(-139463.85) } },
    { { SIMDE_FLOAT64_C(   974.60), SIMDE_FLOAT64_C(    51.96) },
      { SIMDE_FLOAT64_C(   988.71), SIMDE_FLOAT64_C(   292.59) },
       INT8_C(   0),
      { SIMDE_FLOAT64_C(963596.77), SIMDE_FLOAT64_C( 51373.37) } },
    { { SIMDE_FLOAT64_C(  -177.10), SIMDE_FLOAT64_C(  -715.71) },
      { SIMDE_FLOAT64_C(  -172.78), SIMDE_FLOAT64_C(   676.97) },
       INT8_C(   1),
      { SIMDE_FLOAT64_C(-119891.39), SIMDE_FLOAT64_C(-484514.20) } },
    { { SIMDE_FLOAT64_C(  -585.24), SIMDE_FLOAT64_C(   729.36) },
      { SIMDE_FLOAT64_C(  -541.96), SIMDE_FLOAT64_C(   756.27) },
       INT8_C(   1),
      { SIMDE_FLOAT64_C(-442599.45), SIMDE_FLOAT64_C(551593.09) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2_t a = simde_vld1q_f64(test_vec[i].a);
    simde_float64x2_t b = simde_vld1q_f64(test_vec[i].b);

    simde_float64x2_t r;
    SIMDE_CONSTIFY_2_(simde_vmulxq_laneq_f64, r, (HEDLEY_UNREACHABLE(), simde_vdupq_n_f64(SIMDE_FLOAT64_C(0.0))), test_vec[i].lane, a, b);

    simde_test_arm_neon_assert_equal_f64x2(r, simde_vld1q_f64(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x2_t a = simde_test_arm_neon_random_f64x2(-1000.0, 1000.0);
    simde_float64x2_t b = simde_test_arm_neon_random_f64x2(-1000.0, 1000.0);
    int lane = simde_test_codegen_random_i8() & 1;

    simde_float64x2_t r;
    SIMDE_CONSTIFY_2_(simde_vmulxq_laneq_f64, r, (HEDLEY_UNREACHABLE(), simde_vdupq_n_f64(SIMDE_FLOAT64_C(0.0))), lane, a, b);

    simde_test_arm_neon_write_f64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i8(2, HEDLEY_STATIC_CAST(int8_t, lane), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmulxd_lane_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64_t a;
    simde_float64_t b[1];
    simde_float64_t r;
  } test_vec[] = {
    { SIMDE_FLOAT64_C(   701.55),
      { SIMDE_FLOAT64_C(   763.69) },
      SIMDE_FLOAT64_C(535766.72) },
    { SIMDE_FLOAT64_C(  -207.75),
      { SIMDE_FLOAT64_C(  -252.26) },
      SIMDE_FLOAT64_C( 52407.01) },
    { SIMDE_FLOAT64_C(   258.78),
      { SIMDE_FLOAT64_C(   426.42) },
      SIMDE_FLOAT64_C(110348.97) },
    { SIMDE_FLOAT64_C(  -228.36),
      { SIMDE_FLOAT64_C(   601.45) },
      SIMDE_FLOAT64_C(-137347.12) },
    { SIMDE_FLOAT64_C(   257.18),
      { SIMDE_FLOAT64_C(   100.91) },
      SIMDE_FLOAT64_C( 25952.03) },
    { SIMDE_FLOAT64_C(  -786.84),
      { SIMDE_FLOAT64_C(  -162.95) },
      SIMDE_FLOAT64_C(128215.58) },
    { SIMDE_FLOAT64_C(  -602.83),
      { SIMDE_FLOAT64_C(   531.21) },
      SIMDE_FLOAT64_C(-320229.32) },
    { SIMDE_FLOAT64_C(   286.53),
      { SIMDE_FLOAT64_C(   607.95) },
      SIMDE_FLOAT64_C(174195.91) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64_t r = simde_vmulxd_lane_f64(test_vec[i].a, simde_vld1_f64(test_vec[i].b), 0);
    simde_assert_equal_f64(r, test_vec[i].r, 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64_t a = simde_test_codegen_random_f64(-1000, 1000);
    simde_float64x1_t b = simde_test_arm_neon_random_f64x1(-1000, 1000);
    simde_float64_t r = simde_vmulxd_lane_f64(a, b, 0);

    simde_test_codegen_write_f64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x1(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_f64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmulxd_laneq_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64_t a;
    simde_float64_t b[2];
    int lane;
    simde_float64_t r;
  } test_vec[] = {
    { SIMDE_FLOAT64_C(  -966.64),
      { SIMDE_FLOAT64_C(   703.89), SIMDE_FLOAT64_C(  -629.15) },
       INT8_C(   0),
      SIMDE_FLOAT64_C(-680408.23) },
    { SIMDE_FLOAT64_C(  -363.33),
      { SIMDE_FLOAT64_C(  -559.71), SIMDE_FLOAT64_C(  -456.98) },
       INT8_C(   1),
      SIMDE_FLOAT64_C(166034.54) },
    { SIMDE_FLOAT64_C(  -605.56),
      { SIMDE_FLOAT64_C(  -750.10), SIMDE_FLOAT64_C(     3.29) },
       INT8_C(   0),
      SIMDE_FLOAT64_C(454230.56) },
    { SIMDE_FLOAT64_C(  -653.37),
      { SIMDE_FLOAT64_C(  -480.38), SIMDE_FLOAT64_C(   279.75) },
       INT8_C(   1),
      SIMDE_FLOAT64_C(-182780.26) },
    { SIMDE_FLOAT64_C(  -832.94),
      { SIMDE_FLOAT64_C(   271.64), SIMDE_FLOAT64_C(  -658.01) },
       INT8_C(   0),
      SIMDE_FLOAT64_C(-226259.82) },
    { SIMDE_FLOAT64_C(  -530.95),
      { SIMDE_FLOAT64_C(   366.84), SIMDE_FLOAT64_C(   230.32) },
       INT8_C(   1),
      SIMDE_FLOAT64_C(-122288.40) },
    { SIMDE_FLOAT64_C(   710.66),
      { SIMDE_FLOAT64_C(   453.17), SIMDE_FLOAT64_C(   153.31) },
       INT8_C(   0),
      SIMDE_FLOAT64_C(322049.79) },
    { SIMDE_FLOAT64_C(   325.93),
      { SIMDE_FLOAT64_C(   880.39), SIMDE_FLOAT64_C(   -35.41) },
       INT8_C(   1),
      SIMDE_FLOAT64_C(-11541.18) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64_t r;
    simde_float64x2_t b = simde_vld1q_f64(test_vec[i].b);
    SIMDE_CONSTIFY_2_(simde_vmulxd_laneq_f64, r, (HEDLEY_UNREACHABLE(), r), test_vec[i].lane, test_vec[i].a, b);
    simde_assert_equal_f64(r, test_vec[i].r, 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  int lanes[] = { 0, 1, 0, 1, 0, 1, 0, 1 };
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64_t a = simde_test_codegen_random_f64(-1000, 1000);
    simde_float64x2_t b = simde_test_arm_neon_random_f64x2(-1000, 1000);
    simde_float64_t r;
    SIMDE_CONSTIFY_2_(simde_vmulxd_laneq_f64, r, (HEDLEY_UNREACHABLE(), r), lanes[i], a, b);

    simde_test_codegen_write_f64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i8(2, HEDLEY_STATIC_CAST(int8_t, lanes[i]), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_f64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmulxh_lane_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16_t a;
    simde_float16_t b[4];
    int lane;
    simde_float16_t r;
  } test_vec[] = {
    {   SIMDE_FLOAT16_VALUE(-0.9),
      { SIMDE_FLOAT16_VALUE(-6.7), SIMDE_FLOAT16_VALUE(-3.2), SIMDE_FLOAT16_VALUE(11.3), SIMDE_FLOAT16_VALUE(-6.7) },
        INT8_C(0),
        SIMDE_FLOAT16_VALUE(6.030) },
    {   SIMDE_FLOAT16_VALUE(4.5),
      { SIMDE_FLOAT16_VALUE(-1.1), SIMDE_FLOAT16_VALUE(7.4), SIMDE_FLOAT16_VALUE(-6.5), SIMDE_FLOAT16_VALUE(13.1) },
        INT8_C(2),
        SIMDE_FLOAT16_VALUE(-29.250) },
    {   SIMDE_FLOAT16_VALUE(-3.7),
      { SIMDE_FLOAT16_VALUE(1.6), SIMDE_FLOAT16_VALUE(13.7), SIMDE_FLOAT16_VALUE(13.3), SIMDE_FLOAT16_VALUE(14.0) },
        INT8_C(1),
        SIMDE_FLOAT16_VALUE(-50.690) },
    {   SIMDE_FLOAT16_VALUE(13.3),
      { SIMDE_FLOAT16_VALUE(11.7), SIMDE_FLOAT16_VALUE(8.7), SIMDE_FLOAT16_VALUE(-10.1), SIMDE_FLOAT16_VALUE(-4.4) },
        INT8_C(1),
        SIMDE_FLOAT16_VALUE(115.710) },
    {   SIMDE_FLOAT16_VALUE(-9.9),
      { SIMDE_FLOAT16_VALUE(3.6), SIMDE_FLOAT16_VALUE(-13.7), SIMDE_FLOAT16_VALUE(-3.5), SIMDE_FLOAT16_VALUE(14.4) },
        INT8_C(3),
        SIMDE_FLOAT16_VALUE(-142.560) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x4_t b = simde_vld1_f16(test_vec[i].b);
    simde_float16_t r;
    SIMDE_CONSTIFY_4_(simde_vmulxh_lane_f16, r, (HEDLEY_UNREACHABLE(), r), test_vec[i].lane, test_vec[i].a, b);
    simde_assert_equal_f16(r, test_vec[i].r, 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16_t a = simde_test_codegen_random_f16(-1000.0f, 1000.0f);
    simde_float16x4_t b = simde_test_arm_neon_random_f16x4(-1000.0f, 1000.0f);
    simde_float16_t r;
    int lane = simde_test_codegen_random_i8() & 3;
    SIMDE_CONSTIFY_4_(simde_vmulxh_lane_f16, r, (HEDLEY_UNREACHABLE(), r), test_vec[i].lane, a, b);

    simde_test_codegen_write_f16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i8(2, HEDLEY_STATIC_CAST(int8_t, lane), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_f16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmulxs_lane_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32_t a;
    simde_float32_t b[2];
    int lane;
    simde_float32_t r;
  } test_vec[] = {
    { SIMDE_FLOAT32_C(   114.36),
      { SIMDE_FLOAT32_C(   411.22), SIMDE_FLOAT32_C(   916.69) },
       INT8_C(   0),
      SIMDE_FLOAT32_C( 47027.12) },
    { SIMDE_FLOAT32_C(   700.21),
      { SIMDE_FLOAT32_C(  -898.84), SIMDE_FLOAT32_C(  -718.55) },
       INT8_C(   1),
      SIMDE_FLOAT32_C(-503135.91) },
    { SIMDE_FLOAT32_C(  -369.32),
      { SIMDE_FLOAT32_C(  -865.48), SIMDE_FLOAT32_C(   985.34) },
       INT8_C(   0),
      SIMDE_FLOAT32_C(319639.06) },
    { SIMDE_FLOAT32_C(     1.52),
      { SIMDE_FLOAT32_C(  -228.81), SIMDE_FLOAT32_C(  -574.37) },
       INT8_C(   1),
      SIMDE_FLOAT32_C(  -873.04) },
    { SIMDE_FLOAT32_C(   544.55),
      { SIMDE_FLOAT32_C(   165.63), SIMDE_FLOAT32_C(  -324.47) },
       INT8_C(   0),
      SIMDE_FLOAT32_C( 90193.82) },
    { SIMDE_FLOAT32_C(  -452.16),
      { SIMDE_FLOAT32_C(   512.26), SIMDE_FLOAT32_C(   195.14) },
       INT8_C(   1),
      SIMDE_FLOAT32_C(-88234.50) },
    { SIMDE_FLOAT32_C(   827.58),
      { SIMDE_FLOAT32_C(   679.32), SIMDE_FLOAT32_C(  -533.22) },
       INT8_C(   0),
      SIMDE_FLOAT32_C(562191.69) },
    { SIMDE_FLOAT32_C(  -830.42),
      { SIMDE_FLOAT32_C(  -851.63), SIMDE_FLOAT32_C(   833.63) },
       INT8_C(   1),
      SIMDE_FLOAT32_C(-692263.00) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t b = simde_vld1_f32(test_vec[i].b);
    simde_float32_t r;
    SIMDE_CONSTIFY_2_(simde_vmulxs_lane_f32, r, (HEDLEY_UNREACHABLE(), r), test_vec[i].lane, test_vec[i].a, b);
    simde_assert_equal_f32(r, test_vec[i].r, 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  int lanes[] = { 0, 1, 0, 1, 0, 1, 0, 1};
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32_t a = simde_test_codegen_random_f32(-1000, 1000);
    simde_float32x2_t b = simde_test_arm_neon_random_f32x2(-1000, 1000);
    simde_float32_t r;
    SIMDE_CONSTIFY_2_(simde_vmulxs_lane_f32, r, (HEDLEY_UNREACHABLE(), r), lanes[i], a, b);

    simde_test_codegen_write_f32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i8(2, HEDLEY_STATIC_CAST(int8_t, lanes[i]), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_f32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmulxh_laneq_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16_t a;
    simde_float16_t b[8];
    int lane;
    simde_float16_t r;
  } test_vec[] = {
    {   SIMDE_FLOAT16_VALUE(9.2),
      { SIMDE_FLOAT16_VALUE(7.8), SIMDE_FLOAT16_VALUE(-2.1), SIMDE_FLOAT16_VALUE(6.4), SIMDE_FLOAT16_VALUE(-8.2),
        SIMDE_FLOAT16_VALUE(10.0), SIMDE_FLOAT16_VALUE(1.3), SIMDE_FLOAT16_VALUE(-13.3), SIMDE_FLOAT16_VALUE(3.9) },
        INT8_C(1),
        SIMDE_FLOAT16_VALUE(-19.320) },
    {   SIMDE_FLOAT16_VALUE(7.7),
      { SIMDE_FLOAT16_VALUE(-14.5), SIMDE_FLOAT16_VALUE(-4.9), SIMDE_FLOAT16_VALUE(13.4), SIMDE_FLOAT16_VALUE(14.6),
        SIMDE_FLOAT16_VALUE(-12.9), SIMDE_FLOAT16_VALUE(-0.6), SIMDE_FLOAT16_VALUE(-7.4), SIMDE_FLOAT16_VALUE(6.6) },
        INT8_C(7),
        SIMDE_FLOAT16_VALUE(50.820) },
    {   SIMDE_FLOAT16_VALUE(8.5),
      { SIMDE_FLOAT16_VALUE(5.6), SIMDE_FLOAT16_VALUE(-4.6), SIMDE_FLOAT16_VALUE(5.9), SIMDE_FLOAT16_VALUE(-11.4),
        SIMDE_FLOAT16_VALUE(-11.6), SIMDE_FLOAT16_VALUE(7.8), SIMDE_FLOAT16_VALUE(-2.7), SIMDE_FLOAT16_VALUE(-4.8) },
        INT8_C(6),
        SIMDE_FLOAT16_VALUE(-22.950) },
    {   SIMDE_FLOAT16_VALUE(-4.8),
      { SIMDE_FLOAT16_VALUE(-1.8), SIMDE_FLOAT16_VALUE(-3.2), SIMDE_FLOAT16_VALUE(14.6), SIMDE_FLOAT16_VALUE(-5.4),
        SIMDE_FLOAT16_VALUE(-12.8), SIMDE_FLOAT16_VALUE(-8.3), SIMDE_FLOAT16_VALUE(9.9), SIMDE_FLOAT16_VALUE(-2.3) },
        INT8_C(6),
        SIMDE_FLOAT16_VALUE(-47.520) },
    {   SIMDE_FLOAT16_VALUE(9.9),
      { SIMDE_FLOAT16_VALUE(-5.8), SIMDE_FLOAT16_VALUE(4.5), SIMDE_FLOAT16_VALUE(-0.2), SIMDE_FLOAT16_VALUE(12.2),
        SIMDE_FLOAT16_VALUE(13.1), SIMDE_FLOAT16_VALUE(-4.2), SIMDE_FLOAT16_VALUE(-4.2), SIMDE_FLOAT16_VALUE(-7.1) },
        INT8_C(0),
        SIMDE_FLOAT16_VALUE(-57.420) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x8_t b = simde_vld1q_f16(test_vec[i].b);
    simde_float16_t r;
    SIMDE_CONSTIFY_8_(simde_vmulxh_laneq_f16, r, (HEDLEY_UNREACHABLE(), r), test_vec[i].lane, test_vec[i].a, b);
    simde_assert_equal_f16(r, test_vec[i].r, 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16_t a = simde_test_codegen_random_f16(-1000.0f, 1000.0f);
    simde_float16x8_t b = simde_test_arm_neon_random_f16x8(-1000.0f, 1000.0f);
    simde_float16_t r;
    int lane = simde_test_codegen_random_i8() & 7;
    SIMDE_CONSTIFY_8_(simde_vmulxh_laneq_f16, r, (HEDLEY_UNREACHABLE(), r), test_vec[i].lane, a, b);

    simde_test_codegen_write_f16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i8(2, HEDLEY_STATIC_CAST(int8_t, lane), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_f16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmulxs_laneq_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32_t a;
    simde_float32_t b[4];
    int lane;
    simde_float32_t r;
  } test_vec[] = {
    { SIMDE_FLOAT32_C(   399.90),
      { SIMDE_FLOAT32_C(   859.03), SIMDE_FLOAT32_C(   286.79), SIMDE_FLOAT32_C(  -446.80), SIMDE_FLOAT32_C(   184.96) },
       INT8_C(   0),
      SIMDE_FLOAT32_C(343526.09) },
    { SIMDE_FLOAT32_C(   167.18),
      { SIMDE_FLOAT32_C(   517.79), SIMDE_FLOAT32_C(  -700.69), SIMDE_FLOAT32_C(  -421.60), SIMDE_FLOAT32_C(   434.49) },
       INT8_C(   1),
      SIMDE_FLOAT32_C(-117141.35) },
    { SIMDE_FLOAT32_C(   999.53),
      { SIMDE_FLOAT32_C(  -320.44), SIMDE_FLOAT32_C(   715.94), SIMDE_FLOAT32_C(  -369.79), SIMDE_FLOAT32_C(  -185.93) },
       INT8_C(   0),
      SIMDE_FLOAT32_C(-320289.41) },
    { SIMDE_FLOAT32_C(   701.28),
      { SIMDE_FLOAT32_C(   631.73), SIMDE_FLOAT32_C(   585.26), SIMDE_FLOAT32_C(  -873.09), SIMDE_FLOAT32_C(   176.28) },
       INT8_C(   1),
      SIMDE_FLOAT32_C(410431.16) },
    { SIMDE_FLOAT32_C(  -249.11),
      { SIMDE_FLOAT32_C(  -197.56), SIMDE_FLOAT32_C(   724.11), SIMDE_FLOAT32_C(  -736.85), SIMDE_FLOAT32_C(   997.59) },
       INT8_C(   0),
      SIMDE_FLOAT32_C( 49214.17) },
    { SIMDE_FLOAT32_C(   551.70),
      { SIMDE_FLOAT32_C(   942.47), SIMDE_FLOAT32_C(  -535.63), SIMDE_FLOAT32_C(   721.27), SIMDE_FLOAT32_C(  -909.16) },
       INT8_C(   1),
      SIMDE_FLOAT32_C(-295507.09) },
    { SIMDE_FLOAT32_C(  -702.00),
      { SIMDE_FLOAT32_C(   121.17), SIMDE_FLOAT32_C(   949.86), SIMDE_FLOAT32_C(   584.79), SIMDE_FLOAT32_C(   674.37) },
       INT8_C(   0),
      SIMDE_FLOAT32_C(-85061.34) },
    { SIMDE_FLOAT32_C(   134.82),
      { SIMDE_FLOAT32_C(  -248.03), SIMDE_FLOAT32_C(   192.17), SIMDE_FLOAT32_C(   434.13), SIMDE_FLOAT32_C(   330.37) },
       INT8_C(   1),
      SIMDE_FLOAT32_C( 25908.36) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t b = simde_vld1q_f32(test_vec[i].b);
    simde_float32_t r;
    SIMDE_CONSTIFY_4_(simde_vmulxs_laneq_f32, r, (HEDLEY_UNREACHABLE(), r), test_vec[i].lane, test_vec[i].a, b);
    simde_assert_equal_f32(r, test_vec[i].r, 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  int lanes[] = { 0, 1, 0, 1, 0, 1, 0, 1};
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32_t a = simde_test_codegen_random_f32(-1000, 1000);
    simde_float32x4_t b = simde_test_arm_neon_random_f32x4(-1000, 1000);
    simde_float32_t r;
    SIMDE_CONSTIFY_4_(simde_vmulxs_laneq_f32, r, (HEDLEY_UNREACHABLE(), r), lanes[i], a, b);

    simde_test_codegen_write_f32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i8(2, HEDLEY_STATIC_CAST(int8_t, lanes[i]) , SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_f32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmulx_laneq_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16 a[4];
    simde_float16 b[8];
    int lane;
    simde_float16 r[4];
  } test_vec[] = {
   { {  SIMDE_FLOAT16_VALUE(-2.3), SIMDE_FLOAT16_VALUE(-2.7), SIMDE_FLOAT16_VALUE(0.1), SIMDE_FLOAT16_VALUE(6.2) },
     {  SIMDE_FLOAT16_VALUE(-4.0), SIMDE_FLOAT16_VALUE(1.4), SIMDE_FLOAT16_VALUE(-5.2), SIMDE_FLOAT16_VALUE(6.9),
        SIMDE_FLOAT16_VALUE(8.4), SIMDE_FLOAT16_VALUE(2.6), SIMDE_FLOAT16_VALUE(-8.1), SIMDE_FLOAT16_VALUE(-9.4) },
        INT8_C(3),
     {  SIMDE_FLOAT16_VALUE(-15.870), SIMDE_FLOAT16_VALUE(-18.630), SIMDE_FLOAT16_VALUE(0.690), SIMDE_FLOAT16_VALUE(42.780) } },
   { {  SIMDE_FLOAT16_VALUE(-7.8), SIMDE_FLOAT16_VALUE(5.4), SIMDE_FLOAT16_VALUE(8.4), SIMDE_FLOAT16_VALUE(-2.2) },
     {  SIMDE_FLOAT16_VALUE(4.8), SIMDE_FLOAT16_VALUE(-5.0), SIMDE_FLOAT16_VALUE(-2.1), SIMDE_FLOAT16_VALUE(-6.0),
        SIMDE_FLOAT16_VALUE(-7.9), SIMDE_FLOAT16_VALUE(-9.2), SIMDE_FLOAT16_VALUE(5.4), SIMDE_FLOAT16_VALUE(-9.1) },
        INT8_C(4),
     {  SIMDE_FLOAT16_VALUE(61.620), SIMDE_FLOAT16_VALUE(-42.660), SIMDE_FLOAT16_VALUE(-66.360), SIMDE_FLOAT16_VALUE(17.380) } },
   { {  SIMDE_FLOAT16_VALUE(7.7), SIMDE_FLOAT16_VALUE(-1.8), SIMDE_FLOAT16_VALUE(-6.4), SIMDE_FLOAT16_VALUE(-1.7) },
     {  SIMDE_FLOAT16_VALUE(7.6), SIMDE_FLOAT16_VALUE(-3.0), SIMDE_FLOAT16_VALUE(-4.4), SIMDE_FLOAT16_VALUE(-8.0),
        SIMDE_FLOAT16_VALUE(-4.5), SIMDE_FLOAT16_VALUE(-7.9), SIMDE_FLOAT16_VALUE(6.1), SIMDE_FLOAT16_VALUE(-5.3) },
        INT8_C(3),
     {  SIMDE_FLOAT16_VALUE(-61.600), SIMDE_FLOAT16_VALUE(14.400), SIMDE_FLOAT16_VALUE(51.200), SIMDE_FLOAT16_VALUE(13.600) } },
   { {  SIMDE_FLOAT16_VALUE(-5.9), SIMDE_FLOAT16_VALUE(0.9), SIMDE_FLOAT16_VALUE(2.3), SIMDE_FLOAT16_VALUE(9.1) },
     {  SIMDE_FLOAT16_VALUE(-0.5), SIMDE_FLOAT16_VALUE(1.1), SIMDE_FLOAT16_VALUE(-1.4), SIMDE_FLOAT16_VALUE(3.7),
        SIMDE_FLOAT16_VALUE(4.4), SIMDE_FLOAT16_VALUE(4.5), SIMDE_FLOAT16_VALUE(-0.5), SIMDE_FLOAT16_VALUE(6.5) },
        INT8_C(2),
     {  SIMDE_FLOAT16_VALUE(8.260), SIMDE_FLOAT16_VALUE(-1.260), SIMDE_FLOAT16_VALUE(-3.220), SIMDE_FLOAT16_VALUE(-12.740) } },
   { {  SIMDE_FLOAT16_VALUE(1.6), SIMDE_FLOAT16_VALUE(6.5), SIMDE_FLOAT16_VALUE(-4.1), SIMDE_FLOAT16_VALUE(-1.1) },
     {  SIMDE_FLOAT16_VALUE(-4.6), SIMDE_FLOAT16_VALUE(9.8), SIMDE_FLOAT16_VALUE(-4.3), SIMDE_FLOAT16_VALUE(-3.0),
        SIMDE_FLOAT16_VALUE(-1.0), SIMDE_FLOAT16_VALUE(-7.7), SIMDE_FLOAT16_VALUE(2.3), SIMDE_FLOAT16_VALUE(-0.6) },
        INT8_C(3),
     {  SIMDE_FLOAT16_VALUE(-4.800), SIMDE_FLOAT16_VALUE(-19.500), SIMDE_FLOAT16_VALUE(12.300), SIMDE_FLOAT16_VALUE(3.300) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x4_t a = simde_vld1_f16(test_vec[i].a);
    simde_float16x8_t b = simde_vld1q_f16(test_vec[i].b);

    simde_float16x4_t r;
    SIMDE_CONSTIFY_8_(simde_vmulx_laneq_f16, r, (HEDLEY_UNREACHABLE(), simde_vdup_n_f16(SIMDE_FLOAT16_VALUE(0.0))), test_vec[i].lane, a, b);

    simde_test_arm_neon_assert_equal_f16x4(r, simde_vld1_f16(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16x4_t a = simde_test_arm_neon_random_f16x4(-1000.0f, 1000.0f);
    simde_float16x8_t b = simde_test_arm_neon_random_f16x8(-1000.0f, 1000.0f);
    simde_float16x4_t r;
    int lane = simde_test_codegen_random_i8() & 7;
    SIMDE_CONSTIFY_8_(simde_vmulx_laneq_f16, r, (HEDLEY_UNREACHABLE(), simde_vdup_n_f16(SIMDE_FLOAT16_VALUE(0.0))), test_vec[i].lane, a, b);

    simde_test_arm_neon_write_f16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i8(2, HEDLEY_STATIC_CAST(int8_t, lane), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmulx_laneq_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a[2];
    simde_float32 b[4];
    int lane;
    simde_float32 r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -450.23), SIMDE_FLOAT32_C(   250.17) },
      { SIMDE_FLOAT32_C(  -637.45), SIMDE_FLOAT32_C(  -230.90), SIMDE_FLOAT32_C(   241.82), SIMDE_FLOAT32_C(   684.35) },
       INT8_C(   2),
      { SIMDE_FLOAT32_C(-108874.62), SIMDE_FLOAT32_C( 60496.11) } },
    { { SIMDE_FLOAT32_C(  -527.99), SIMDE_FLOAT32_C(   169.94) },
      { SIMDE_FLOAT32_C(  -242.42), SIMDE_FLOAT32_C(   315.71), SIMDE_FLOAT32_C(   591.47), SIMDE_FLOAT32_C(   461.07) },
       INT8_C(   2),
      { SIMDE_FLOAT32_C(-312290.22), SIMDE_FLOAT32_C(100514.41) } },
    { { SIMDE_FLOAT32_C(   282.28), SIMDE_FLOAT32_C(  -679.21) },
      { SIMDE_FLOAT32_C(    -7.25), SIMDE_FLOAT32_C(   965.48), SIMDE_FLOAT32_C(  -996.40), SIMDE_FLOAT32_C(   494.36) },
       INT8_C(   2),
      { SIMDE_FLOAT32_C(-281263.81), SIMDE_FLOAT32_C(676764.88) } },
    { { SIMDE_FLOAT32_C(  -776.91), SIMDE_FLOAT32_C(   857.04) },
      { SIMDE_FLOAT32_C(   724.13), SIMDE_FLOAT32_C(  -786.43), SIMDE_FLOAT32_C(  -311.62), SIMDE_FLOAT32_C(  -105.35) },
       INT8_C(   1),
      { SIMDE_FLOAT32_C(610985.31), SIMDE_FLOAT32_C(-674001.94) } },
    { { SIMDE_FLOAT32_C(   551.51), SIMDE_FLOAT32_C(   956.48) },
      { SIMDE_FLOAT32_C(    44.53), SIMDE_FLOAT32_C(  -898.71), SIMDE_FLOAT32_C(   206.65), SIMDE_FLOAT32_C(   407.07) },
       INT8_C(   1),
      { SIMDE_FLOAT32_C(-495647.56), SIMDE_FLOAT32_C(-859598.12) } },
    { { SIMDE_FLOAT32_C(  -551.53), SIMDE_FLOAT32_C(    91.43) },
      { SIMDE_FLOAT32_C(  -422.60), SIMDE_FLOAT32_C(   -79.51), SIMDE_FLOAT32_C(  -738.63), SIMDE_FLOAT32_C(   334.98) },
       INT8_C(   1),
      { SIMDE_FLOAT32_C( 43852.15), SIMDE_FLOAT32_C( -7269.60) } },
    { { SIMDE_FLOAT32_C(   852.83), SIMDE_FLOAT32_C(  -203.95) },
      { SIMDE_FLOAT32_C(   817.55), SIMDE_FLOAT32_C(   135.11), SIMDE_FLOAT32_C(   116.84), SIMDE_FLOAT32_C(  -189.70) },
       INT8_C(   1),
      { SIMDE_FLOAT32_C(115225.87), SIMDE_FLOAT32_C(-27555.68) } },
    { { SIMDE_FLOAT32_C(   120.44), SIMDE_FLOAT32_C(  -695.35) },
      { SIMDE_FLOAT32_C(   723.25), SIMDE_FLOAT32_C(   343.53), SIMDE_FLOAT32_C(  -838.30), SIMDE_FLOAT32_C(   447.37) },
       INT8_C(   2),
      { SIMDE_FLOAT32_C(-100964.85), SIMDE_FLOAT32_C(582911.88) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t a = simde_vld1_f32(test_vec[i].a);
    simde_float32x4_t b = simde_vld1q_f32(test_vec[i].b);

    simde_float32x2_t r;
    SIMDE_CONSTIFY_4_(simde_vmulx_laneq_f32, r, (HEDLEY_UNREACHABLE(), simde_vdup_n_f32(SIMDE_FLOAT32_C(0.0))), test_vec[i].lane, a, b);

    simde_test_arm_neon_assert_equal_f32x2(r, simde_vld1_f32(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x2_t a = simde_test_arm_neon_random_f32x2(-1000.0, 1000.0);
    simde_float32x4_t b = simde_test_arm_neon_random_f32x4(-1000.0, 1000.0);
    int lane = simde_test_codegen_random_i8() & 3;

    simde_float32x2_t r;
    SIMDE_CONSTIFY_4_(simde_vmulx_laneq_f32, r, (HEDLEY_UNREACHABLE(), simde_vdup_n_f32(SIMDE_FLOAT32_C(0.0))), lane, a, b);

    simde_test_arm_neon_write_f32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i8(2, HEDLEY_STATIC_CAST(int8_t, lane), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmulx_laneq_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 a[1];
    simde_float64 b[2];
    int lane;
    simde_float64 r[1];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(  -149.93) },
      { SIMDE_FLOAT64_C(  -657.97), SIMDE_FLOAT64_C(  -689.39) },
       INT8_C(   1),
      { SIMDE_FLOAT64_C(103360.24) } },
    { { SIMDE_FLOAT64_C(  -701.49) },
      { SIMDE_FLOAT64_C(   355.13), SIMDE_FLOAT64_C(  -497.12) },
       INT8_C(   0),
      { SIMDE_FLOAT64_C(-249120.14) } },
    { { SIMDE_FLOAT64_C(  -237.80) },
      { SIMDE_FLOAT64_C(   373.27), SIMDE_FLOAT64_C(   953.64) },
       INT8_C(   1),
      { SIMDE_FLOAT64_C(-226775.59) } },
    { { SIMDE_FLOAT64_C(   950.67) },
      { SIMDE_FLOAT64_C(  -125.88), SIMDE_FLOAT64_C(  -885.00) },
       INT8_C(   0),
      { SIMDE_FLOAT64_C(-119670.34) } },
    { { SIMDE_FLOAT64_C(   110.32) },
      { SIMDE_FLOAT64_C(   967.83), SIMDE_FLOAT64_C(  -918.30) },
       INT8_C(   0),
      { SIMDE_FLOAT64_C(106771.01) } },
    { { SIMDE_FLOAT64_C(   102.94) },
      { SIMDE_FLOAT64_C(   198.54), SIMDE_FLOAT64_C(   738.16) },
       INT8_C(   0),
      { SIMDE_FLOAT64_C( 20437.71) } },
    { { SIMDE_FLOAT64_C(  -681.01) },
      { SIMDE_FLOAT64_C(  -957.18), SIMDE_FLOAT64_C(   926.77) },
       INT8_C(   0),
      { SIMDE_FLOAT64_C(651849.15) } },
    { { SIMDE_FLOAT64_C(  -795.48) },
      { SIMDE_FLOAT64_C(   374.15), SIMDE_FLOAT64_C(   219.63) },
       INT8_C(   0),
      { SIMDE_FLOAT64_C(-297628.84) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x1_t a = simde_vld1_f64(test_vec[i].a);
    simde_float64x2_t b = simde_vld1q_f64(test_vec[i].b);

    simde_float64x1_t r;
    SIMDE_CONSTIFY_2_(simde_vmulx_laneq_f64, r, (HEDLEY_UNREACHABLE(), simde_vdup_n_f64(SIMDE_FLOAT64_C(0.0))), test_vec[i].lane, a, b);

    simde_test_arm_neon_assert_equal_f64x1(r, simde_vld1_f64(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x1_t a = simde_test_arm_neon_random_f64x1(-1000.0, 1000.0);
    simde_float64x2_t b = simde_test_arm_neon_random_f64x2(-1000.0, 1000.0);
    int lane = simde_test_codegen_random_i8() & 1;

    simde_float64x1_t r;
    SIMDE_CONSTIFY_2_(simde_vmulx_laneq_f64, r, (HEDLEY_UNREACHABLE(), simde_vdup_n_f64(SIMDE_FLOAT64_C(0.0))), lane, a, b);

    simde_test_arm_neon_write_f64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i8(2, HEDLEY_STATIC_CAST(int8_t, lane), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

HEDLEY_DIAGNOSTIC_POP

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vmulxh_lane_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmulxs_lane_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vmulxd_lane_f64)

SIMDE_TEST_FUNC_LIST_ENTRY(vmulxh_laneq_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmulxs_laneq_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vmulxd_laneq_f64)

SIMDE_TEST_FUNC_LIST_ENTRY(vmulx_lane_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmulx_lane_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vmulx_lane_f64)

SIMDE_TEST_FUNC_LIST_ENTRY(vmulxq_lane_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmulxq_lane_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vmulxq_lane_f64)

SIMDE_TEST_FUNC_LIST_ENTRY(vmulx_laneq_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmulx_laneq_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vmulx_laneq_f64)

SIMDE_TEST_FUNC_LIST_ENTRY(vmulxq_laneq_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmulxq_laneq_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vmulxq_laneq_f64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
