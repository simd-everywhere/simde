#define SIMDE_TEST_ARM_NEON_INSN cmla_rot90_lane

#include "test-neon.h"
#include "../../../simde/arm/neon/cmla_rot90_lane.h"
#include "../../../simde/arm/neon/dup_n.h"

static int
test_simde_vcmla_rot90_lane_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16_t r_[4];
    simde_float16_t a[4];
    simde_float16_t b[4];
    const int lane;
    simde_float16_t r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT16_VALUE(   231.50), SIMDE_FLOAT16_VALUE(   124.88), SIMDE_FLOAT16_VALUE(  -241.62), SIMDE_FLOAT16_VALUE(  -272.75) },
      { SIMDE_FLOAT16_VALUE(    26.38), SIMDE_FLOAT16_VALUE(  -235.50), SIMDE_FLOAT16_VALUE(     6.92), SIMDE_FLOAT16_VALUE(  -107.12) },
      { SIMDE_FLOAT16_VALUE(   -39.38), SIMDE_FLOAT16_VALUE(   261.25), SIMDE_FLOAT16_VALUE(   206.88), SIMDE_FLOAT16_VALUE(  -140.25) },
       INT32_C(           0),
      { SIMDE_FLOAT16_VALUE( 61760.00), SIMDE_FLOAT16_VALUE(  9400.00), SIMDE_FLOAT16_VALUE( 27744.00), SIMDE_FLOAT16_VALUE(  3946.00) } },
    { { SIMDE_FLOAT16_VALUE(    31.55), SIMDE_FLOAT16_VALUE(   -80.94), SIMDE_FLOAT16_VALUE(    41.69), SIMDE_FLOAT16_VALUE(   254.50) },
      { SIMDE_FLOAT16_VALUE(   207.25), SIMDE_FLOAT16_VALUE(   172.62), SIMDE_FLOAT16_VALUE(  -186.25), SIMDE_FLOAT16_VALUE(   272.75) },
      { SIMDE_FLOAT16_VALUE(    13.74), SIMDE_FLOAT16_VALUE(    -7.06), SIMDE_FLOAT16_VALUE(   221.50), SIMDE_FLOAT16_VALUE(   -19.20) },
       INT32_C(           1),
      { SIMDE_FLOAT16_VALUE(  3346.00), SIMDE_FLOAT16_VALUE( 38144.00), SIMDE_FLOAT16_VALUE(  5280.00), SIMDE_FLOAT16_VALUE( 60672.00) } },
    { { SIMDE_FLOAT16_VALUE(   -21.98), SIMDE_FLOAT16_VALUE(   -51.56), SIMDE_FLOAT16_VALUE(  -293.75), SIMDE_FLOAT16_VALUE(    57.72) },
      { SIMDE_FLOAT16_VALUE(   298.50), SIMDE_FLOAT16_VALUE(   169.00), SIMDE_FLOAT16_VALUE(  -116.81), SIMDE_FLOAT16_VALUE(   258.25) },
      { SIMDE_FLOAT16_VALUE(  -143.62), SIMDE_FLOAT16_VALUE(    16.39), SIMDE_FLOAT16_VALUE(   -12.13), SIMDE_FLOAT16_VALUE(   146.62) },
       INT32_C(           0),
      { SIMDE_FLOAT16_VALUE( -2792.00), SIMDE_FLOAT16_VALUE(-24320.00), SIMDE_FLOAT16_VALUE( -4528.00), SIMDE_FLOAT16_VALUE(-37024.00) } },
    { { SIMDE_FLOAT16_VALUE(   -38.91), SIMDE_FLOAT16_VALUE(  -138.25), SIMDE_FLOAT16_VALUE(  -139.62), SIMDE_FLOAT16_VALUE(    -0.96) },
      { SIMDE_FLOAT16_VALUE(   121.12), SIMDE_FLOAT16_VALUE(   299.00), SIMDE_FLOAT16_VALUE(  -283.00), SIMDE_FLOAT16_VALUE(  -184.62) },
      { SIMDE_FLOAT16_VALUE(   276.25), SIMDE_FLOAT16_VALUE(  -153.62), SIMDE_FLOAT16_VALUE(  -144.75), SIMDE_FLOAT16_VALUE(   207.25) },
       INT32_C(           1),
      { SIMDE_FLOAT16_VALUE(-62016.00), SIMDE_FLOAT16_VALUE(-43424.00), SIMDE_FLOAT16_VALUE( 38112.00), SIMDE_FLOAT16_VALUE( 26720.00) } },
    { { SIMDE_FLOAT16_VALUE(  -176.50), SIMDE_FLOAT16_VALUE(  -274.25), SIMDE_FLOAT16_VALUE(   -11.55), SIMDE_FLOAT16_VALUE(   270.75) },
      { SIMDE_FLOAT16_VALUE(   -37.00), SIMDE_FLOAT16_VALUE(  -196.62), SIMDE_FLOAT16_VALUE(   -93.56), SIMDE_FLOAT16_VALUE(  -133.00) },
      { SIMDE_FLOAT16_VALUE(  -121.94), SIMDE_FLOAT16_VALUE(  -144.00), SIMDE_FLOAT16_VALUE(   -52.09), SIMDE_FLOAT16_VALUE(    18.34) },
       INT32_C(           0),
      { SIMDE_FLOAT16_VALUE(-28496.00), SIMDE_FLOAT16_VALUE( 23696.00), SIMDE_FLOAT16_VALUE(-19168.00), SIMDE_FLOAT16_VALUE( 16496.00) } },
    { { SIMDE_FLOAT16_VALUE(  -152.50), SIMDE_FLOAT16_VALUE(   120.38), SIMDE_FLOAT16_VALUE(   123.81), SIMDE_FLOAT16_VALUE(  -107.88) },
      { SIMDE_FLOAT16_VALUE(  -260.50), SIMDE_FLOAT16_VALUE(   204.00), SIMDE_FLOAT16_VALUE(   265.75), SIMDE_FLOAT16_VALUE(  -169.88) },
      { SIMDE_FLOAT16_VALUE(  -270.00), SIMDE_FLOAT16_VALUE(    92.44), SIMDE_FLOAT16_VALUE(  -267.50), SIMDE_FLOAT16_VALUE(     3.83) },
       INT32_C(           1),
      { SIMDE_FLOAT16_VALUE(  -934.00), SIMDE_FLOAT16_VALUE(-54464.00), SIMDE_FLOAT16_VALUE(   774.50), SIMDE_FLOAT16_VALUE( 45344.00) } },
    { { SIMDE_FLOAT16_VALUE(   163.50), SIMDE_FLOAT16_VALUE(   296.50), SIMDE_FLOAT16_VALUE(   -43.03), SIMDE_FLOAT16_VALUE(   164.38) },
      { SIMDE_FLOAT16_VALUE(    51.38), SIMDE_FLOAT16_VALUE(  -252.38), SIMDE_FLOAT16_VALUE(   149.50), SIMDE_FLOAT16_VALUE(  -287.75) },
      { SIMDE_FLOAT16_VALUE(   -11.45), SIMDE_FLOAT16_VALUE(   176.75), SIMDE_FLOAT16_VALUE(  -166.25), SIMDE_FLOAT16_VALUE(   277.50) },
       INT32_C(           0),
      { SIMDE_FLOAT16_VALUE( 44768.00), SIMDE_FLOAT16_VALUE(  3186.00), SIMDE_FLOAT16_VALUE( 50816.00), SIMDE_FLOAT16_VALUE(  3460.00) } },
    { { SIMDE_FLOAT16_VALUE(   208.00), SIMDE_FLOAT16_VALUE(   236.88), SIMDE_FLOAT16_VALUE(   -88.75), SIMDE_FLOAT16_VALUE(    20.41) },
      { SIMDE_FLOAT16_VALUE(  -282.00), SIMDE_FLOAT16_VALUE(   282.25), SIMDE_FLOAT16_VALUE(    67.06), SIMDE_FLOAT16_VALUE(    40.97) },
      { SIMDE_FLOAT16_VALUE(  -151.75), SIMDE_FLOAT16_VALUE(   149.50), SIMDE_FLOAT16_VALUE(   -88.25), SIMDE_FLOAT16_VALUE(  -134.50) },
       INT32_C(           1),
      { SIMDE_FLOAT16_VALUE( 38176.00), SIMDE_FLOAT16_VALUE(-24672.00), SIMDE_FLOAT16_VALUE(  5420.00), SIMDE_FLOAT16_VALUE( -3596.00) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x4_t r_ = simde_vld1_f16(test_vec[i].r_);
    simde_float16x4_t a = simde_vld1_f16(test_vec[i].a);
    simde_float16x4_t b = simde_vld1_f16(test_vec[i].b);
    simde_float16x4_t r;
    switch(i & 1) {
      case 0:
        r = simde_vcmla_rot90_lane_f16(r_, a, b, 0);
        break;
      case 1:
        r = simde_vcmla_rot90_lane_f16(r_, a, b, 1);
        break;
      default:
        HEDLEY_UNREACHABLE();
    }
    simde_test_arm_neon_assert_equal_f16x4(r, simde_vld1_f16(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  const int lanes[] = { 0, 1, 0, 1, 0, 1, 0, 1 };
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16x4_t r_ = simde_test_arm_neon_random_f16x4(-300.0f, 300.0f);
    simde_float16x4_t a = simde_test_arm_neon_random_f16x4(-300.0f, 300.0f);
    simde_float16x4_t b = simde_test_arm_neon_random_f16x4(-300.0f, 300.0f);
    simde_float16x4_t r;
    if(i % 2)
      r = simde_vcmla_rot90_lane_f16(r_, a, b, 1);
    else
      r = simde_vcmla_rot90_lane_f16(r_, a, b, 0);


    simde_test_arm_neon_write_f16x4(2, r_, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f16x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lanes[i], SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcmla_rot90_lane_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32_t r_[2];
    simde_float32_t a[2];
    simde_float32_t b[2];
    const int lane;
    simde_float32_t r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   948.37), SIMDE_FLOAT32_C(  -663.54) },
      { SIMDE_FLOAT32_C(  -129.24), SIMDE_FLOAT32_C(  -112.47) },
      { SIMDE_FLOAT32_C(  -263.58), SIMDE_FLOAT32_C(    59.47) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C(  7636.96), SIMDE_FLOAT32_C( 28981.30) } },
    { { SIMDE_FLOAT32_C(  -508.18), SIMDE_FLOAT32_C(  -977.36) },
      { SIMDE_FLOAT32_C(  -434.66), SIMDE_FLOAT32_C(   747.76) },
      { SIMDE_FLOAT32_C(  -378.73), SIMDE_FLOAT32_C(   660.91) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C(-494710.22), SIMDE_FLOAT32_C(-284176.53) } },
    { { SIMDE_FLOAT32_C(    -2.91), SIMDE_FLOAT32_C(  -847.24) },
      { SIMDE_FLOAT32_C(   389.83), SIMDE_FLOAT32_C(  -122.97) },
      { SIMDE_FLOAT32_C(  -797.93), SIMDE_FLOAT32_C(  -854.27) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C(-105052.49), SIMDE_FLOAT32_C( 97274.21) } },
    { { SIMDE_FLOAT32_C(   360.11), SIMDE_FLOAT32_C(   284.83) },
      { SIMDE_FLOAT32_C(  -841.33), SIMDE_FLOAT32_C(  -170.61) },
      { SIMDE_FLOAT32_C(   604.14), SIMDE_FLOAT32_C(  -210.88) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C(-35618.13), SIMDE_FLOAT32_C(-102787.50) } },
    { { SIMDE_FLOAT32_C(  -203.88), SIMDE_FLOAT32_C(  -689.37) },
      { SIMDE_FLOAT32_C(  -229.77), SIMDE_FLOAT32_C(   315.27) },
      { SIMDE_FLOAT32_C(   693.42), SIMDE_FLOAT32_C(   382.15) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C(-120684.30), SIMDE_FLOAT32_C(217925.14) } },
    { { SIMDE_FLOAT32_C(   794.62), SIMDE_FLOAT32_C(  -789.91) },
      { SIMDE_FLOAT32_C(    64.55), SIMDE_FLOAT32_C(   816.06) },
      { SIMDE_FLOAT32_C(  -543.43), SIMDE_FLOAT32_C(   617.50) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C(-503122.44), SIMDE_FLOAT32_C(-444261.38) } },
    { { SIMDE_FLOAT32_C(   366.21), SIMDE_FLOAT32_C(   893.09) },
      { SIMDE_FLOAT32_C(   116.22), SIMDE_FLOAT32_C(  -634.33) },
      { SIMDE_FLOAT32_C(   768.03), SIMDE_FLOAT32_C(   342.13) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C(217389.55), SIMDE_FLOAT32_C(-486291.41) } },
    { { SIMDE_FLOAT32_C(   163.12), SIMDE_FLOAT32_C(  -390.83) },
      { SIMDE_FLOAT32_C(  -692.36), SIMDE_FLOAT32_C(  -453.71) },
      { SIMDE_FLOAT32_C(   550.47), SIMDE_FLOAT32_C(  -183.75) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C(-83206.09), SIMDE_FLOAT32_C(-250144.56) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t r_ = simde_vld1_f32(test_vec[i].r_);
    simde_float32x2_t a = simde_vld1_f32(test_vec[i].a);
    simde_float32x2_t b = simde_vld1_f32(test_vec[i].b);
    simde_float32x2_t r = simde_vcmla_rot90_lane_f32(r_, a, b, 0);
    simde_test_arm_neon_assert_equal_f32x2(r, simde_vld1_f32(test_vec[i].r), 1);
  }
  
  return 0;
#else
  fputc('\n', stdout);
  const int lanes[] = { 0, 0, 0, 0, 0, 0, 0, 0 };
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x2_t r_ = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f);
    simde_float32x2_t a = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f);
    simde_float32x2_t b = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f);
    simde_float32x2_t r = simde_vcmla_rot90_lane_f32(r_, a, b, 0);


    simde_test_arm_neon_write_f32x2(2, r_, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x2(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, 0, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}


static int
test_simde_vcmla_rot90_laneq_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16_t r_[4];
    simde_float16_t a[4];
    simde_float16_t b[8];
    const int lane;
    simde_float16_t r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT16_VALUE(  -145.25), SIMDE_FLOAT16_VALUE(    39.50), SIMDE_FLOAT16_VALUE(    55.31), SIMDE_FLOAT16_VALUE(  -221.88) },
      { SIMDE_FLOAT16_VALUE(   105.50), SIMDE_FLOAT16_VALUE(  -208.75), SIMDE_FLOAT16_VALUE(    29.83), SIMDE_FLOAT16_VALUE(  -208.25) },
      { SIMDE_FLOAT16_VALUE(  -228.50), SIMDE_FLOAT16_VALUE(   -49.47), SIMDE_FLOAT16_VALUE(  -271.75), SIMDE_FLOAT16_VALUE(   -22.83),
        SIMDE_FLOAT16_VALUE(   221.12), SIMDE_FLOAT16_VALUE(   217.88), SIMDE_FLOAT16_VALUE(   224.75), SIMDE_FLOAT16_VALUE(    25.00) },
       INT32_C(           0),
      { SIMDE_FLOAT16_VALUE(-10472.00), SIMDE_FLOAT16_VALUE( 47744.00), SIMDE_FLOAT16_VALUE(-10248.00), SIMDE_FLOAT16_VALUE( 47360.00) } },
    { { SIMDE_FLOAT16_VALUE(   220.25), SIMDE_FLOAT16_VALUE(  -259.75), SIMDE_FLOAT16_VALUE(   -72.81), SIMDE_FLOAT16_VALUE(   138.88) },
      { SIMDE_FLOAT16_VALUE(  -136.38), SIMDE_FLOAT16_VALUE(  -138.25), SIMDE_FLOAT16_VALUE(  -101.00), SIMDE_FLOAT16_VALUE(  -140.88) },
      { SIMDE_FLOAT16_VALUE(   180.00), SIMDE_FLOAT16_VALUE(   262.25), SIMDE_FLOAT16_VALUE(     3.55), SIMDE_FLOAT16_VALUE(   247.62),
        SIMDE_FLOAT16_VALUE(   213.12), SIMDE_FLOAT16_VALUE(  -163.50), SIMDE_FLOAT16_VALUE(   175.50), SIMDE_FLOAT16_VALUE(   155.88) },
       INT32_C(           1),
      { SIMDE_FLOAT16_VALUE( 34464.00), SIMDE_FLOAT16_VALUE(  -750.50), SIMDE_FLOAT16_VALUE( 34816.00), SIMDE_FLOAT16_VALUE(  -361.25) } },
    { { SIMDE_FLOAT16_VALUE(  -223.88), SIMDE_FLOAT16_VALUE(   133.75), SIMDE_FLOAT16_VALUE(   -96.12), SIMDE_FLOAT16_VALUE(  -136.50) },
      { SIMDE_FLOAT16_VALUE(  -235.88), SIMDE_FLOAT16_VALUE(   -44.03), SIMDE_FLOAT16_VALUE(   226.00), SIMDE_FLOAT16_VALUE(    52.94) },
      { SIMDE_FLOAT16_VALUE(     4.27), SIMDE_FLOAT16_VALUE(   282.25), SIMDE_FLOAT16_VALUE(   190.75), SIMDE_FLOAT16_VALUE(    29.61),
        SIMDE_FLOAT16_VALUE(   294.00), SIMDE_FLOAT16_VALUE(    66.19), SIMDE_FLOAT16_VALUE(    49.69), SIMDE_FLOAT16_VALUE(   169.50) },
       INT32_C(           0),
      { SIMDE_FLOAT16_VALUE( 12200.00), SIMDE_FLOAT16_VALUE(   -54.25), SIMDE_FLOAT16_VALUE(-15040.00), SIMDE_FLOAT16_VALUE(    89.50) } },
    { { SIMDE_FLOAT16_VALUE(   -69.00), SIMDE_FLOAT16_VALUE(   101.75), SIMDE_FLOAT16_VALUE(  -227.00), SIMDE_FLOAT16_VALUE(   185.00) },
      { SIMDE_FLOAT16_VALUE(    17.22), SIMDE_FLOAT16_VALUE(   282.50), SIMDE_FLOAT16_VALUE(   -19.38), SIMDE_FLOAT16_VALUE(   212.75) },
      { SIMDE_FLOAT16_VALUE(  -114.12), SIMDE_FLOAT16_VALUE(   -64.44), SIMDE_FLOAT16_VALUE(  -151.25), SIMDE_FLOAT16_VALUE(    -3.73),
        SIMDE_FLOAT16_VALUE(   226.25), SIMDE_FLOAT16_VALUE(    74.81), SIMDE_FLOAT16_VALUE(   -61.75), SIMDE_FLOAT16_VALUE(     8.32) },
       INT32_C(           1),
      { SIMDE_FLOAT16_VALUE(   985.00), SIMDE_FLOAT16_VALUE(-42624.00), SIMDE_FLOAT16_VALUE(   566.50), SIMDE_FLOAT16_VALUE(-32000.00) } },
    { { SIMDE_FLOAT16_VALUE(    84.00), SIMDE_FLOAT16_VALUE(   -64.25), SIMDE_FLOAT16_VALUE(  -113.00), SIMDE_FLOAT16_VALUE(   138.75) },
      { SIMDE_FLOAT16_VALUE(   -53.62), SIMDE_FLOAT16_VALUE(   135.75), SIMDE_FLOAT16_VALUE(  -228.75), SIMDE_FLOAT16_VALUE(    48.84) },
      { SIMDE_FLOAT16_VALUE(   109.75), SIMDE_FLOAT16_VALUE(   201.75), SIMDE_FLOAT16_VALUE(  -258.75), SIMDE_FLOAT16_VALUE(   -58.72),
        SIMDE_FLOAT16_VALUE(   205.38), SIMDE_FLOAT16_VALUE(  -237.38), SIMDE_FLOAT16_VALUE(   -16.84), SIMDE_FLOAT16_VALUE(    60.72) },
       INT32_C(           0),
      { SIMDE_FLOAT16_VALUE(-27296.00), SIMDE_FLOAT16_VALUE( 14832.00), SIMDE_FLOAT16_VALUE( -9968.00), SIMDE_FLOAT16_VALUE(  5500.00) } },
    { { SIMDE_FLOAT16_VALUE(   118.38), SIMDE_FLOAT16_VALUE(  -237.62), SIMDE_FLOAT16_VALUE(    -0.65), SIMDE_FLOAT16_VALUE(  -107.38) },
      { SIMDE_FLOAT16_VALUE(   -87.75), SIMDE_FLOAT16_VALUE(   121.88), SIMDE_FLOAT16_VALUE(   -99.25), SIMDE_FLOAT16_VALUE(   129.25) },
      { SIMDE_FLOAT16_VALUE(  -114.25), SIMDE_FLOAT16_VALUE(   166.12), SIMDE_FLOAT16_VALUE(    78.75), SIMDE_FLOAT16_VALUE(   -51.97),
        SIMDE_FLOAT16_VALUE(   262.25), SIMDE_FLOAT16_VALUE(    71.81), SIMDE_FLOAT16_VALUE(  -108.94), SIMDE_FLOAT16_VALUE(    35.88) },
       INT32_C(           1),
      { SIMDE_FLOAT16_VALUE(  6452.00), SIMDE_FLOAT16_VALUE(  9360.00), SIMDE_FLOAT16_VALUE(  6716.00), SIMDE_FLOAT16_VALUE( 10072.00) } },
    { { SIMDE_FLOAT16_VALUE(    87.00), SIMDE_FLOAT16_VALUE(   278.25), SIMDE_FLOAT16_VALUE(  -132.25), SIMDE_FLOAT16_VALUE(  -215.75) },
      { SIMDE_FLOAT16_VALUE(  -108.88), SIMDE_FLOAT16_VALUE(   -78.06), SIMDE_FLOAT16_VALUE(  -127.31), SIMDE_FLOAT16_VALUE(  -267.25) },
      { SIMDE_FLOAT16_VALUE(    65.62), SIMDE_FLOAT16_VALUE(  -169.88), SIMDE_FLOAT16_VALUE(    68.69), SIMDE_FLOAT16_VALUE(   143.62),
        SIMDE_FLOAT16_VALUE(    98.62), SIMDE_FLOAT16_VALUE(   -42.59), SIMDE_FLOAT16_VALUE(  -243.88), SIMDE_FLOAT16_VALUE(    82.75) },
       INT32_C(           0),
      { SIMDE_FLOAT16_VALUE(-13176.00), SIMDE_FLOAT16_VALUE( -4844.00), SIMDE_FLOAT16_VALUE(-45536.00), SIMDE_FLOAT16_VALUE(-17760.00) } },
    { { SIMDE_FLOAT16_VALUE(  -262.25), SIMDE_FLOAT16_VALUE(   208.12), SIMDE_FLOAT16_VALUE(   168.38), SIMDE_FLOAT16_VALUE(   197.38) },
      { SIMDE_FLOAT16_VALUE(   268.75), SIMDE_FLOAT16_VALUE(   194.50), SIMDE_FLOAT16_VALUE(  -242.00), SIMDE_FLOAT16_VALUE(  -158.25) },
      { SIMDE_FLOAT16_VALUE(    -8.37), SIMDE_FLOAT16_VALUE(  -199.12), SIMDE_FLOAT16_VALUE(   114.25), SIMDE_FLOAT16_VALUE(   232.75),
        SIMDE_FLOAT16_VALUE(  -108.00), SIMDE_FLOAT16_VALUE(   -25.03), SIMDE_FLOAT16_VALUE(  -141.75), SIMDE_FLOAT16_VALUE(  -202.62) },
       INT32_C(           1),
      { SIMDE_FLOAT16_VALUE(-45536.00), SIMDE_FLOAT16_VALUE( 22432.00), SIMDE_FLOAT16_VALUE( 36992.00), SIMDE_FLOAT16_VALUE(-17888.00) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x4_t r_ = simde_vld1_f16(test_vec[i].r_);
    simde_float16x4_t a = simde_vld1_f16(test_vec[i].a);
    simde_float16x8_t b = simde_vld1q_f16(test_vec[i].b);
    simde_float16x4_t r;
    switch(i & 1) {
      case 0:
        r = simde_vcmla_rot90_laneq_f16(r_, a, b, 0);
        break;
      case 1:
        r = simde_vcmla_rot90_laneq_f16(r_, a, b, 1);
        break;
      default:
        HEDLEY_UNREACHABLE();
    }
    simde_test_arm_neon_assert_equal_f16x4(r, simde_vld1_f16(test_vec[i].r), 1);
  }
  return 0;
#else
  fputc('\n', stdout);
  const int lanes[] = { 0, 1, 0, 1, 0, 1, 0, 1 };
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16x4_t r_ = simde_test_arm_neon_random_f16x4(-300.0f, 300.0f);
    simde_float16x4_t a = simde_test_arm_neon_random_f16x4(-300.0f, 300.0f);
    simde_float16x8_t b = simde_test_arm_neon_random_f16x8(-300.0f, 300.0f);
    simde_float16x4_t r;
    if(i % 2)
      r = simde_vcmla_rot90_laneq_f16(r_, a, b, 1);
    else
      r = simde_vcmla_rot90_laneq_f16(r_, a, b, 0);


    simde_test_arm_neon_write_f16x4(2, r_, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f16x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lanes[i], SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcmla_rot90_laneq_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32_t r_[2];
    simde_float32_t a[2];
    simde_float32_t b[4];
    const int lane;
    simde_float32_t r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -931.69), SIMDE_FLOAT32_C(  -920.70) },
      { SIMDE_FLOAT32_C(  -221.33), SIMDE_FLOAT32_C(   120.64) },
      { SIMDE_FLOAT32_C(  -383.16), SIMDE_FLOAT32_C(   277.79), SIMDE_FLOAT32_C(   760.23), SIMDE_FLOAT32_C(  -771.08) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C(-34444.28), SIMDE_FLOAT32_C(-47145.12) } },
    { { SIMDE_FLOAT32_C(   482.81), SIMDE_FLOAT32_C(   547.77) },
      { SIMDE_FLOAT32_C(   310.06), SIMDE_FLOAT32_C(  -790.26) },
      { SIMDE_FLOAT32_C(    41.72), SIMDE_FLOAT32_C(  -878.04), SIMDE_FLOAT32_C(   847.25), SIMDE_FLOAT32_C(  -343.42) },
       INT32_C(           1),
      { SIMDE_FLOAT32_C(-270908.28), SIMDE_FLOAT32_C(-669000.00) } },
    { { SIMDE_FLOAT32_C(   142.06), SIMDE_FLOAT32_C(  -462.51) },
      { SIMDE_FLOAT32_C(   649.55), SIMDE_FLOAT32_C(   949.61) },
      { SIMDE_FLOAT32_C(   143.14), SIMDE_FLOAT32_C(  -184.10), SIMDE_FLOAT32_C(  -161.62), SIMDE_FLOAT32_C(  -376.45) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C(174965.27), SIMDE_FLOAT32_C(135464.66) } },
    { { SIMDE_FLOAT32_C(   939.75), SIMDE_FLOAT32_C(   371.20) },
      { SIMDE_FLOAT32_C(   828.46), SIMDE_FLOAT32_C(  -145.73) },
      { SIMDE_FLOAT32_C(   697.35), SIMDE_FLOAT32_C(   334.07), SIMDE_FLOAT32_C(   740.00), SIMDE_FLOAT32_C(  -878.77) },
       INT32_C(           1),
      { SIMDE_FLOAT32_C(-127123.40), SIMDE_FLOAT32_C(-107469.00) } },
    { { SIMDE_FLOAT32_C(   440.15), SIMDE_FLOAT32_C(  -409.74) },
      { SIMDE_FLOAT32_C(  -441.59), SIMDE_FLOAT32_C(   235.26) },
      { SIMDE_FLOAT32_C(   -55.32), SIMDE_FLOAT32_C(   265.28), SIMDE_FLOAT32_C(   595.33), SIMDE_FLOAT32_C(  -346.56) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C(-61969.62), SIMDE_FLOAT32_C(-13424.32) } },
    { { SIMDE_FLOAT32_C(  -678.02), SIMDE_FLOAT32_C(   583.77) },
      { SIMDE_FLOAT32_C(  -602.68), SIMDE_FLOAT32_C(   713.06) },
      { SIMDE_FLOAT32_C(   451.06), SIMDE_FLOAT32_C(   894.88), SIMDE_FLOAT32_C(   288.08), SIMDE_FLOAT32_C(  -204.22) },
       INT32_C(           1),
      { SIMDE_FLOAT32_C(144943.09), SIMDE_FLOAT32_C(206002.08) } },
    { { SIMDE_FLOAT32_C(  -351.68), SIMDE_FLOAT32_C(  -767.19) },
      { SIMDE_FLOAT32_C(   -90.50), SIMDE_FLOAT32_C(   992.18) },
      { SIMDE_FLOAT32_C(  -451.98), SIMDE_FLOAT32_C(  -425.01), SIMDE_FLOAT32_C(   806.62), SIMDE_FLOAT32_C(   872.81) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C(421334.75), SIMDE_FLOAT32_C(-449212.72) } },
    { { SIMDE_FLOAT32_C(  -699.20), SIMDE_FLOAT32_C(   623.90) },
      { SIMDE_FLOAT32_C(   -67.54), SIMDE_FLOAT32_C(   776.35) },
      { SIMDE_FLOAT32_C(   112.90), SIMDE_FLOAT32_C(  -529.17), SIMDE_FLOAT32_C(   300.41), SIMDE_FLOAT32_C(   915.76) },
       INT32_C(           1),
      { SIMDE_FLOAT32_C(-711649.44), SIMDE_FLOAT32_C(233847.20) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t r_ = simde_vld1_f32(test_vec[i].r_);
    simde_float32x2_t a = simde_vld1_f32(test_vec[i].a);
    simde_float32x4_t b = simde_vld1q_f32(test_vec[i].b);
    simde_float32x2_t r;
    switch(i & 1) {
      case 0:
        r = simde_vcmla_rot90_laneq_f32(r_, a, b, 0);
        break;
      case 1:
        r = simde_vcmla_rot90_laneq_f32(r_, a, b, 1);
        break;
      default:
        HEDLEY_UNREACHABLE();
    }
    simde_test_arm_neon_assert_equal_f32x2(r, simde_vld1_f32(test_vec[i].r), 1);
  }
  return 0;
#else
  fputc('\n', stdout);
  const int lanes[] = { 0, 1, 0, 1, 0, 1, 0, 1 };
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x2_t r_ = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f);
    simde_float32x2_t a = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f);
    simde_float32x4_t b = simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f);
    simde_float32x2_t r;
    if(i % 2)
      r = simde_vcmla_rot90_laneq_f32(r_, a, b, 1);
    else
      r = simde_vcmla_rot90_laneq_f32(r_, a, b, 0);


    simde_test_arm_neon_write_f32x2(2, r_, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x2(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lanes[i], SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcmlaq_rot90_lane_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16_t r_[8];
    simde_float16_t a[8];
    simde_float16_t b[4];
    const int lane;
    simde_float16_t r[8];
  } test_vec[] = {
    { { SIMDE_FLOAT16_VALUE(   -46.88), SIMDE_FLOAT16_VALUE(  -159.75), SIMDE_FLOAT16_VALUE(  -141.75), SIMDE_FLOAT16_VALUE(   129.88),
        SIMDE_FLOAT16_VALUE(   136.75), SIMDE_FLOAT16_VALUE(   147.25), SIMDE_FLOAT16_VALUE(   -13.35), SIMDE_FLOAT16_VALUE(    14.51) },
      { SIMDE_FLOAT16_VALUE(   -67.75), SIMDE_FLOAT16_VALUE(  -129.50), SIMDE_FLOAT16_VALUE(  -198.12), SIMDE_FLOAT16_VALUE(  -164.88),
        SIMDE_FLOAT16_VALUE(   178.75), SIMDE_FLOAT16_VALUE(   137.12), SIMDE_FLOAT16_VALUE(   144.12), SIMDE_FLOAT16_VALUE(    29.48) },
      { SIMDE_FLOAT16_VALUE(   -91.06), SIMDE_FLOAT16_VALUE(   -66.69), SIMDE_FLOAT16_VALUE(    80.31), SIMDE_FLOAT16_VALUE(  -120.25) },
       INT32_C(           0),
      { SIMDE_FLOAT16_VALUE( -8680.00), SIMDE_FLOAT16_VALUE( 11632.00), SIMDE_FLOAT16_VALUE(-11136.00), SIMDE_FLOAT16_VALUE( 15144.00),
        SIMDE_FLOAT16_VALUE(  9280.00), SIMDE_FLOAT16_VALUE(-12336.00), SIMDE_FLOAT16_VALUE(  1953.00), SIMDE_FLOAT16_VALUE( -2670.00) } },
    { { SIMDE_FLOAT16_VALUE(    20.42), SIMDE_FLOAT16_VALUE(   -45.78), SIMDE_FLOAT16_VALUE(   -47.62), SIMDE_FLOAT16_VALUE(   -34.50),
        SIMDE_FLOAT16_VALUE(   -21.30), SIMDE_FLOAT16_VALUE(  -173.75), SIMDE_FLOAT16_VALUE(   -67.75), SIMDE_FLOAT16_VALUE(  -102.00) },
      { SIMDE_FLOAT16_VALUE(   197.50), SIMDE_FLOAT16_VALUE(   190.25), SIMDE_FLOAT16_VALUE(    24.09), SIMDE_FLOAT16_VALUE(    43.31),
        SIMDE_FLOAT16_VALUE(    74.06), SIMDE_FLOAT16_VALUE(    94.38), SIMDE_FLOAT16_VALUE(    18.52), SIMDE_FLOAT16_VALUE(    85.75) },
      { SIMDE_FLOAT16_VALUE(   -92.06), SIMDE_FLOAT16_VALUE(  -138.75), SIMDE_FLOAT16_VALUE(   -71.00), SIMDE_FLOAT16_VALUE(   185.00) },
       INT32_C(           1),
      { SIMDE_FLOAT16_VALUE(-35168.00), SIMDE_FLOAT16_VALUE(-13552.00), SIMDE_FLOAT16_VALUE( -8060.00), SIMDE_FLOAT16_VALUE( -3110.00),
        SIMDE_FLOAT16_VALUE(-17488.00), SIMDE_FLOAT16_VALUE( -6876.00), SIMDE_FLOAT16_VALUE(-15928.00), SIMDE_FLOAT16_VALUE( -6192.00) } },
    { { SIMDE_FLOAT16_VALUE(    89.25), SIMDE_FLOAT16_VALUE(   106.94), SIMDE_FLOAT16_VALUE(     3.91), SIMDE_FLOAT16_VALUE(   187.50),
        SIMDE_FLOAT16_VALUE(  -132.38), SIMDE_FLOAT16_VALUE(   -58.47), SIMDE_FLOAT16_VALUE(  -119.25), SIMDE_FLOAT16_VALUE(   116.38) },
      { SIMDE_FLOAT16_VALUE(  -147.62), SIMDE_FLOAT16_VALUE(  -185.00), SIMDE_FLOAT16_VALUE(  -131.00), SIMDE_FLOAT16_VALUE(    -3.34),
        SIMDE_FLOAT16_VALUE(  -180.25), SIMDE_FLOAT16_VALUE(     7.24), SIMDE_FLOAT16_VALUE(    82.94), SIMDE_FLOAT16_VALUE(  -194.00) },
      { SIMDE_FLOAT16_VALUE(   171.50), SIMDE_FLOAT16_VALUE(   -65.31), SIMDE_FLOAT16_VALUE(  -102.25), SIMDE_FLOAT16_VALUE(  -128.12) },
       INT32_C(           0),
      { SIMDE_FLOAT16_VALUE(-11992.00), SIMDE_FLOAT16_VALUE(-31616.00), SIMDE_FLOAT16_VALUE(  -214.25), SIMDE_FLOAT16_VALUE(  -385.25),
        SIMDE_FLOAT16_VALUE(   340.50), SIMDE_FLOAT16_VALUE(  1183.00), SIMDE_FLOAT16_VALUE(-12792.00), SIMDE_FLOAT16_VALUE(-33152.00) } },
    { { SIMDE_FLOAT16_VALUE(    64.94), SIMDE_FLOAT16_VALUE(   -85.94), SIMDE_FLOAT16_VALUE(   -65.00), SIMDE_FLOAT16_VALUE(   123.44),
        SIMDE_FLOAT16_VALUE(   166.50), SIMDE_FLOAT16_VALUE(    91.94), SIMDE_FLOAT16_VALUE(  -197.75), SIMDE_FLOAT16_VALUE(  -166.00) },
      { SIMDE_FLOAT16_VALUE(    96.81), SIMDE_FLOAT16_VALUE(  -141.00), SIMDE_FLOAT16_VALUE(   -65.19), SIMDE_FLOAT16_VALUE(   -12.64),
        SIMDE_FLOAT16_VALUE(    19.52), SIMDE_FLOAT16_VALUE(  -149.88), SIMDE_FLOAT16_VALUE(   164.00), SIMDE_FLOAT16_VALUE(   177.62) },
      { SIMDE_FLOAT16_VALUE(    24.81), SIMDE_FLOAT16_VALUE(   -22.02), SIMDE_FLOAT16_VALUE(  -173.38), SIMDE_FLOAT16_VALUE(    -4.83) },
       INT32_C(           1),
      { SIMDE_FLOAT16_VALUE(  -616.00), SIMDE_FLOAT16_VALUE( 24352.00), SIMDE_FLOAT16_VALUE(  -126.00), SIMDE_FLOAT16_VALUE(  2316.00),
        SIMDE_FLOAT16_VALUE(  -557.00), SIMDE_FLOAT16_VALUE( 26080.00), SIMDE_FLOAT16_VALUE(   660.00), SIMDE_FLOAT16_VALUE(-30960.00) } },
    { { SIMDE_FLOAT16_VALUE(    55.12), SIMDE_FLOAT16_VALUE(  -102.94), SIMDE_FLOAT16_VALUE(   -93.94), SIMDE_FLOAT16_VALUE(   -35.94),
        SIMDE_FLOAT16_VALUE(   119.62), SIMDE_FLOAT16_VALUE(   -66.06), SIMDE_FLOAT16_VALUE(    11.61), SIMDE_FLOAT16_VALUE(   -45.88) },
      { SIMDE_FLOAT16_VALUE(   -55.88), SIMDE_FLOAT16_VALUE(   -50.28), SIMDE_FLOAT16_VALUE(    27.59), SIMDE_FLOAT16_VALUE(   -90.12),
        SIMDE_FLOAT16_VALUE(   -86.00), SIMDE_FLOAT16_VALUE(  -150.62), SIMDE_FLOAT16_VALUE(    86.38), SIMDE_FLOAT16_VALUE(  -149.62) },
      { SIMDE_FLOAT16_VALUE(   175.38), SIMDE_FLOAT16_VALUE(   156.88), SIMDE_FLOAT16_VALUE(   111.75), SIMDE_FLOAT16_VALUE(   -22.52) },
       INT32_C(           0),
      { SIMDE_FLOAT16_VALUE(  7944.00), SIMDE_FLOAT16_VALUE( -8920.00), SIMDE_FLOAT16_VALUE( 14048.00), SIMDE_FLOAT16_VALUE(-15840.00),
        SIMDE_FLOAT16_VALUE( 23744.00), SIMDE_FLOAT16_VALUE(-26480.00), SIMDE_FLOAT16_VALUE( 23488.00), SIMDE_FLOAT16_VALUE(-26288.00) } },
    { { SIMDE_FLOAT16_VALUE(   155.25), SIMDE_FLOAT16_VALUE(   179.75), SIMDE_FLOAT16_VALUE(   -51.75), SIMDE_FLOAT16_VALUE(    97.19),
        SIMDE_FLOAT16_VALUE(  -168.75), SIMDE_FLOAT16_VALUE(  -133.75), SIMDE_FLOAT16_VALUE(  -113.00), SIMDE_FLOAT16_VALUE(   135.12) },
      { SIMDE_FLOAT16_VALUE(  -191.00), SIMDE_FLOAT16_VALUE(    14.64), SIMDE_FLOAT16_VALUE(    43.78), SIMDE_FLOAT16_VALUE(   -86.81),
        SIMDE_FLOAT16_VALUE(  -184.38), SIMDE_FLOAT16_VALUE(  -142.75), SIMDE_FLOAT16_VALUE(   166.25), SIMDE_FLOAT16_VALUE(    37.97) },
      { SIMDE_FLOAT16_VALUE(   -37.22), SIMDE_FLOAT16_VALUE(  -141.50), SIMDE_FLOAT16_VALUE(  -192.50), SIMDE_FLOAT16_VALUE(   102.81) },
       INT32_C(           1),
      { SIMDE_FLOAT16_VALUE( -1350.00), SIMDE_FLOAT16_VALUE( -2638.00), SIMDE_FLOAT16_VALUE(  8872.00), SIMDE_FLOAT16_VALUE( 16816.00),
        SIMDE_FLOAT16_VALUE( 14504.00), SIMDE_FLOAT16_VALUE( 27344.00), SIMDE_FLOAT16_VALUE( -4016.00), SIMDE_FLOAT16_VALUE( -7172.00) } },
    { { SIMDE_FLOAT16_VALUE(   -12.60), SIMDE_FLOAT16_VALUE(  -190.88), SIMDE_FLOAT16_VALUE(   138.38), SIMDE_FLOAT16_VALUE(  -104.19),
        SIMDE_FLOAT16_VALUE(  -119.88), SIMDE_FLOAT16_VALUE(    65.75), SIMDE_FLOAT16_VALUE(  -185.88), SIMDE_FLOAT16_VALUE(    -6.18) },
      { SIMDE_FLOAT16_VALUE(   121.50), SIMDE_FLOAT16_VALUE(   -93.00), SIMDE_FLOAT16_VALUE(   146.38), SIMDE_FLOAT16_VALUE(    -6.63),
        SIMDE_FLOAT16_VALUE(    86.75), SIMDE_FLOAT16_VALUE(  -162.62), SIMDE_FLOAT16_VALUE(   -37.34), SIMDE_FLOAT16_VALUE(    67.81) },
      { SIMDE_FLOAT16_VALUE(   109.25), SIMDE_FLOAT16_VALUE(   -39.78), SIMDE_FLOAT16_VALUE(   -31.98), SIMDE_FLOAT16_VALUE(     3.13) },
       INT32_C(           0),
      { SIMDE_FLOAT16_VALUE( -3712.00), SIMDE_FLOAT16_VALUE(-10352.00), SIMDE_FLOAT16_VALUE(  -125.31), SIMDE_FLOAT16_VALUE(  -828.50),
        SIMDE_FLOAT16_VALUE( -6588.00), SIMDE_FLOAT16_VALUE(-17696.00), SIMDE_FLOAT16_VALUE(  2512.00), SIMDE_FLOAT16_VALUE(  7404.00) } },
    { { SIMDE_FLOAT16_VALUE(   124.94), SIMDE_FLOAT16_VALUE(   111.25), SIMDE_FLOAT16_VALUE(  -198.00), SIMDE_FLOAT16_VALUE(    13.74),
        SIMDE_FLOAT16_VALUE(  -198.00), SIMDE_FLOAT16_VALUE(    50.47), SIMDE_FLOAT16_VALUE(   -99.75), SIMDE_FLOAT16_VALUE(   -11.94) },
      { SIMDE_FLOAT16_VALUE(   170.88), SIMDE_FLOAT16_VALUE(   -56.44), SIMDE_FLOAT16_VALUE(    44.91), SIMDE_FLOAT16_VALUE(  -110.88),
        SIMDE_FLOAT16_VALUE(   156.12), SIMDE_FLOAT16_VALUE(  -100.44), SIMDE_FLOAT16_VALUE(    70.56), SIMDE_FLOAT16_VALUE(  -170.62) },
      { SIMDE_FLOAT16_VALUE(    77.25), SIMDE_FLOAT16_VALUE(  -164.62), SIMDE_FLOAT16_VALUE(    11.42), SIMDE_FLOAT16_VALUE(   -42.62) },
       INT32_C(           1),
      { SIMDE_FLOAT16_VALUE( -2280.00), SIMDE_FLOAT16_VALUE(  -533.50), SIMDE_FLOAT16_VALUE( -4924.00), SIMDE_FLOAT16_VALUE( -1253.00),
        SIMDE_FLOAT16_VALUE( -4480.00), SIMDE_FLOAT16_VALUE( -1097.00), SIMDE_FLOAT16_VALUE( -7372.00), SIMDE_FLOAT16_VALUE( -1961.00) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x8_t r_ = simde_vld1q_f16(test_vec[i].r_);
    simde_float16x8_t a = simde_vld1q_f16(test_vec[i].a);
    simde_float16x4_t b = simde_vld1_f16(test_vec[i].b);
    simde_float16x8_t r;
    switch(i & 1) {
      case 0:
        r = simde_vcmlaq_rot90_lane_f16(r_, a, b, 0);
        break;
      case 1:
        r = simde_vcmlaq_rot90_lane_f16(r_, a, b, 1);
        break;
      default:
        HEDLEY_UNREACHABLE();
    }
    simde_test_arm_neon_assert_equal_f16x8(r, simde_vld1q_f16(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  const int lanes[] = { 0, 1, 0, 1, 0, 1, 0, 1 };
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16x8_t r_ = simde_test_arm_neon_random_f16x8(-200.0f, 200.0f);
    simde_float16x8_t a = simde_test_arm_neon_random_f16x8(-200.0f, 200.0f);
    simde_float16x4_t b = simde_test_arm_neon_random_f16x4(-200.0f, 200.0f);
    simde_float16x8_t r;
    if(i % 2)
      r = simde_vcmlaq_rot90_lane_f16(r_, a, b, 1);
    else
      r = simde_vcmlaq_rot90_lane_f16(r_, a, b, 0);


    simde_test_arm_neon_write_f16x8(2, r_, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f16x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lanes[i], SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcmlaq_rot90_lane_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32_t r_[4];
    simde_float32_t a[4];
    simde_float32_t b[2];
    const int lane;
    simde_float32_t r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -606.87), SIMDE_FLOAT32_C(   281.36), SIMDE_FLOAT32_C(   801.90), SIMDE_FLOAT32_C(  -480.25) },
      { SIMDE_FLOAT32_C(   411.57), SIMDE_FLOAT32_C(  -814.05), SIMDE_FLOAT32_C(   184.06), SIMDE_FLOAT32_C(  -535.08) },
      { SIMDE_FLOAT32_C(   882.55), SIMDE_FLOAT32_C(  -925.53) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C(-754034.56), SIMDE_FLOAT32_C(-718158.44), SIMDE_FLOAT32_C(-494430.72), SIMDE_FLOAT32_C(-472715.12) } },
    { { SIMDE_FLOAT32_C(   594.05), SIMDE_FLOAT32_C(   232.07), SIMDE_FLOAT32_C(   398.96), SIMDE_FLOAT32_C(  -609.08) },
      { SIMDE_FLOAT32_C(  -871.17), SIMDE_FLOAT32_C(   293.96), SIMDE_FLOAT32_C(   517.18), SIMDE_FLOAT32_C(   204.91) },
      { SIMDE_FLOAT32_C(   -35.71), SIMDE_FLOAT32_C(   -93.52) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C( 28085.19), SIMDE_FLOAT32_C(-10265.24), SIMDE_FLOAT32_C( 19562.14), SIMDE_FLOAT32_C( -7926.42) } },
    { { SIMDE_FLOAT32_C(   155.46), SIMDE_FLOAT32_C(   900.57), SIMDE_FLOAT32_C(  -176.49), SIMDE_FLOAT32_C(  -313.50) },
      { SIMDE_FLOAT32_C(  -945.97), SIMDE_FLOAT32_C(  -983.21), SIMDE_FLOAT32_C(  -879.75), SIMDE_FLOAT32_C(     1.24) },
      { SIMDE_FLOAT32_C(   780.08), SIMDE_FLOAT32_C(   848.20) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C(834114.19), SIMDE_FLOAT32_C(-766081.94), SIMDE_FLOAT32_C( -1228.26), SIMDE_FLOAT32_C(   653.80) } },
    { { SIMDE_FLOAT32_C(  -351.64), SIMDE_FLOAT32_C(   -64.68), SIMDE_FLOAT32_C(  -995.56), SIMDE_FLOAT32_C(  -362.89) },
      { SIMDE_FLOAT32_C(   901.16), SIMDE_FLOAT32_C(  -172.25), SIMDE_FLOAT32_C(  -978.90), SIMDE_FLOAT32_C(  -308.35) },
      { SIMDE_FLOAT32_C(  -444.48), SIMDE_FLOAT32_C(  -372.12) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C(-64449.31), SIMDE_FLOAT32_C( 76497.00), SIMDE_FLOAT32_C(-115738.77), SIMDE_FLOAT32_C(136692.53) } },
    { { SIMDE_FLOAT32_C(  -163.82), SIMDE_FLOAT32_C(   689.83), SIMDE_FLOAT32_C(   -34.71), SIMDE_FLOAT32_C(   582.23) },
      { SIMDE_FLOAT32_C(  -437.81), SIMDE_FLOAT32_C(  -260.96), SIMDE_FLOAT32_C(    80.70), SIMDE_FLOAT32_C(   298.00) },
      { SIMDE_FLOAT32_C(   457.76), SIMDE_FLOAT32_C(  -360.82) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C(-94323.41), SIMDE_FLOAT32_C(-118767.22), SIMDE_FLOAT32_C(107489.65), SIMDE_FLOAT32_C(136994.72) } },
    { { SIMDE_FLOAT32_C(  -323.42), SIMDE_FLOAT32_C(   363.30), SIMDE_FLOAT32_C(    19.16), SIMDE_FLOAT32_C(    93.73) },
      { SIMDE_FLOAT32_C(  -615.85), SIMDE_FLOAT32_C(  -568.20), SIMDE_FLOAT32_C(   284.35), SIMDE_FLOAT32_C(  -908.64) },
      { SIMDE_FLOAT32_C(   518.90), SIMDE_FLOAT32_C(  -783.50) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C(-445508.12), SIMDE_FLOAT32_C(-294475.69), SIMDE_FLOAT32_C(-711900.31), SIMDE_FLOAT32_C(-471399.59) } },
    { { SIMDE_FLOAT32_C(  -345.76), SIMDE_FLOAT32_C(   786.53), SIMDE_FLOAT32_C(  -753.21), SIMDE_FLOAT32_C(   838.46) },
      { SIMDE_FLOAT32_C(    69.23), SIMDE_FLOAT32_C(  -531.56), SIMDE_FLOAT32_C(    30.71), SIMDE_FLOAT32_C(   222.17) },
      { SIMDE_FLOAT32_C(    85.60), SIMDE_FLOAT32_C(   619.29) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C(328844.03), SIMDE_FLOAT32_C(-44715.00), SIMDE_FLOAT32_C(-138340.86), SIMDE_FLOAT32_C( 19856.21) } },
    { { SIMDE_FLOAT32_C(   368.53), SIMDE_FLOAT32_C(   -48.37), SIMDE_FLOAT32_C(  -925.98), SIMDE_FLOAT32_C(   977.19) },
      { SIMDE_FLOAT32_C(  -289.48), SIMDE_FLOAT32_C(   631.24), SIMDE_FLOAT32_C(  -676.98), SIMDE_FLOAT32_C(    70.37) },
      { SIMDE_FLOAT32_C(   645.05), SIMDE_FLOAT32_C(  -714.66) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C(451490.50), SIMDE_FLOAT32_C(407132.97), SIMDE_FLOAT32_C( 49364.64), SIMDE_FLOAT32_C( 46369.36) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t r_ = simde_vld1q_f32(test_vec[i].r_);
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_float32x2_t b = simde_vld1_f32(test_vec[i].b);
    simde_float32x4_t r = simde_vcmlaq_rot90_lane_f32(r_, a, b, 0);
    simde_test_arm_neon_assert_equal_f32x4(r, simde_vld1q_f32(test_vec[i].r), 1);
  }
  return 0;
#else
  fputc('\n', stdout);
  const int lanes[] = { 0, 0, 0, 0, 0, 0, 0, 0 };
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x4_t r_ = simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f);
    simde_float32x4_t a = simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f);
    simde_float32x2_t b = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f);
    simde_float32x4_t r = simde_vcmlaq_rot90_lane_f32(r_, a, b, 0);


    simde_test_arm_neon_write_f32x4(2, r_, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, 0, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcmlaq_rot90_laneq_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16_t r_[8];
    simde_float16_t a[8];
    simde_float16_t b[8];
    const int lane;
    simde_float16_t r[8];
  } test_vec[] = {
    { { SIMDE_FLOAT16_VALUE(  -117.75), SIMDE_FLOAT16_VALUE(   111.00), SIMDE_FLOAT16_VALUE(   -88.00), SIMDE_FLOAT16_VALUE(    69.62),
        SIMDE_FLOAT16_VALUE(  -117.31), SIMDE_FLOAT16_VALUE(    99.50), SIMDE_FLOAT16_VALUE(   -38.12), SIMDE_FLOAT16_VALUE(   199.00) },
      { SIMDE_FLOAT16_VALUE(   184.50), SIMDE_FLOAT16_VALUE(    65.31), SIMDE_FLOAT16_VALUE(   -60.75), SIMDE_FLOAT16_VALUE(   -65.88),
        SIMDE_FLOAT16_VALUE(   100.12), SIMDE_FLOAT16_VALUE(   147.25), SIMDE_FLOAT16_VALUE(    66.69), SIMDE_FLOAT16_VALUE(   162.12) },
      { SIMDE_FLOAT16_VALUE(  -154.50), SIMDE_FLOAT16_VALUE(  -123.56), SIMDE_FLOAT16_VALUE(    40.38), SIMDE_FLOAT16_VALUE(  -151.00),
        SIMDE_FLOAT16_VALUE(     0.51), SIMDE_FLOAT16_VALUE(   193.00), SIMDE_FLOAT16_VALUE(  -186.00), SIMDE_FLOAT16_VALUE(  -122.62) },
       INT32_C(           0),
      { SIMDE_FLOAT16_VALUE(  7952.00), SIMDE_FLOAT16_VALUE( -9976.00), SIMDE_FLOAT16_VALUE( -8224.00), SIMDE_FLOAT16_VALUE( 10248.00),
        SIMDE_FLOAT16_VALUE( 18080.00), SIMDE_FLOAT16_VALUE(-22656.00), SIMDE_FLOAT16_VALUE( 20000.00), SIMDE_FLOAT16_VALUE(-24848.00) } },
    { { SIMDE_FLOAT16_VALUE(   -59.03), SIMDE_FLOAT16_VALUE(    61.88), SIMDE_FLOAT16_VALUE(   134.75), SIMDE_FLOAT16_VALUE(   172.62),
        SIMDE_FLOAT16_VALUE(  -145.00), SIMDE_FLOAT16_VALUE(    32.78), SIMDE_FLOAT16_VALUE(   -79.38), SIMDE_FLOAT16_VALUE(  -122.12) },
      { SIMDE_FLOAT16_VALUE(   -72.94), SIMDE_FLOAT16_VALUE(    74.75), SIMDE_FLOAT16_VALUE(  -157.12), SIMDE_FLOAT16_VALUE(    11.66),
        SIMDE_FLOAT16_VALUE(   -34.16), SIMDE_FLOAT16_VALUE(   117.38), SIMDE_FLOAT16_VALUE(   -88.69), SIMDE_FLOAT16_VALUE(   184.62) },
      { SIMDE_FLOAT16_VALUE(    -3.31), SIMDE_FLOAT16_VALUE(  -115.00), SIMDE_FLOAT16_VALUE(   -71.25), SIMDE_FLOAT16_VALUE(    19.36),
        SIMDE_FLOAT16_VALUE(   156.38), SIMDE_FLOAT16_VALUE(   -16.27), SIMDE_FLOAT16_VALUE(  -141.62), SIMDE_FLOAT16_VALUE(   -99.81) },
       INT32_C(           1),
      { SIMDE_FLOAT16_VALUE( -1506.00), SIMDE_FLOAT16_VALUE( -5264.00), SIMDE_FLOAT16_VALUE(   -90.94), SIMDE_FLOAT16_VALUE(  -658.00),
        SIMDE_FLOAT16_VALUE( -2418.00), SIMDE_FLOAT16_VALUE( -8328.00), SIMDE_FLOAT16_VALUE( -3654.00), SIMDE_FLOAT16_VALUE(-13280.00) } },
    { { SIMDE_FLOAT16_VALUE(   -20.67), SIMDE_FLOAT16_VALUE(  -163.75), SIMDE_FLOAT16_VALUE(  -193.25), SIMDE_FLOAT16_VALUE(   -66.50),
        SIMDE_FLOAT16_VALUE(  -173.25), SIMDE_FLOAT16_VALUE(  -143.62), SIMDE_FLOAT16_VALUE(  -196.12), SIMDE_FLOAT16_VALUE(    96.50) },
      { SIMDE_FLOAT16_VALUE(   110.44), SIMDE_FLOAT16_VALUE(   -72.31), SIMDE_FLOAT16_VALUE(   -83.88), SIMDE_FLOAT16_VALUE(    -4.73),
        SIMDE_FLOAT16_VALUE(   158.38), SIMDE_FLOAT16_VALUE(   -39.31), SIMDE_FLOAT16_VALUE(    87.81), SIMDE_FLOAT16_VALUE(    25.36) },
      { SIMDE_FLOAT16_VALUE(  -172.75), SIMDE_FLOAT16_VALUE(  -153.50), SIMDE_FLOAT16_VALUE(  -106.19), SIMDE_FLOAT16_VALUE(   -60.62),
        SIMDE_FLOAT16_VALUE(  -122.50), SIMDE_FLOAT16_VALUE(    16.91), SIMDE_FLOAT16_VALUE(    77.94), SIMDE_FLOAT16_VALUE(    79.44) },
       INT32_C(           2),
      { SIMDE_FLOAT16_VALUE(  1202.00), SIMDE_FLOAT16_VALUE(  8696.00), SIMDE_FLOAT16_VALUE(  -113.25), SIMDE_FLOAT16_VALUE(   513.00),
        SIMDE_FLOAT16_VALUE(   491.50), SIMDE_FLOAT16_VALUE(  4672.00), SIMDE_FLOAT16_VALUE(  -625.00), SIMDE_FLOAT16_VALUE( -3010.00) } },
    { { SIMDE_FLOAT16_VALUE(  -162.50), SIMDE_FLOAT16_VALUE(   150.12), SIMDE_FLOAT16_VALUE(    99.25), SIMDE_FLOAT16_VALUE(    79.62),
        SIMDE_FLOAT16_VALUE(  -121.12), SIMDE_FLOAT16_VALUE(   -93.00), SIMDE_FLOAT16_VALUE(   153.12), SIMDE_FLOAT16_VALUE(     0.17) },
      { SIMDE_FLOAT16_VALUE(    93.88), SIMDE_FLOAT16_VALUE(   -24.22), SIMDE_FLOAT16_VALUE(    63.84), SIMDE_FLOAT16_VALUE(  -152.75),
        SIMDE_FLOAT16_VALUE(    54.72), SIMDE_FLOAT16_VALUE(   154.62), SIMDE_FLOAT16_VALUE(   132.62), SIMDE_FLOAT16_VALUE(    -4.25) },
      { SIMDE_FLOAT16_VALUE(  -183.75), SIMDE_FLOAT16_VALUE(   -37.25), SIMDE_FLOAT16_VALUE(    37.88), SIMDE_FLOAT16_VALUE(    62.78),
        SIMDE_FLOAT16_VALUE(    50.62), SIMDE_FLOAT16_VALUE(   -78.62), SIMDE_FLOAT16_VALUE(  -122.06), SIMDE_FLOAT16_VALUE(   190.00) },
       INT32_C(           3),
      { SIMDE_FLOAT16_VALUE(  4440.00), SIMDE_FLOAT16_VALUE(  3106.00), SIMDE_FLOAT16_VALUE( 29120.00), SIMDE_FLOAT16_VALUE( 18720.00),
        SIMDE_FLOAT16_VALUE(-29504.00), SIMDE_FLOAT16_VALUE(-18960.00), SIMDE_FLOAT16_VALUE(   960.50), SIMDE_FLOAT16_VALUE(   519.00) } },
    { { SIMDE_FLOAT16_VALUE(   188.25), SIMDE_FLOAT16_VALUE(    67.50), SIMDE_FLOAT16_VALUE(    80.88), SIMDE_FLOAT16_VALUE(    65.44),
        SIMDE_FLOAT16_VALUE(    62.44), SIMDE_FLOAT16_VALUE(  -158.12), SIMDE_FLOAT16_VALUE(   143.25), SIMDE_FLOAT16_VALUE(   123.50) },
      { SIMDE_FLOAT16_VALUE(   146.38), SIMDE_FLOAT16_VALUE(  -163.62), SIMDE_FLOAT16_VALUE(   -27.53), SIMDE_FLOAT16_VALUE(    98.44),
        SIMDE_FLOAT16_VALUE(   173.38), SIMDE_FLOAT16_VALUE(   172.00), SIMDE_FLOAT16_VALUE(   191.75), SIMDE_FLOAT16_VALUE(   -24.80) },
      { SIMDE_FLOAT16_VALUE(   -53.47), SIMDE_FLOAT16_VALUE(    -6.85), SIMDE_FLOAT16_VALUE(   112.69), SIMDE_FLOAT16_VALUE(    96.62),
        SIMDE_FLOAT16_VALUE(    98.12), SIMDE_FLOAT16_VALUE(   179.75), SIMDE_FLOAT16_VALUE(   199.75), SIMDE_FLOAT16_VALUE(   169.25) },
       INT32_C(           0),
      { SIMDE_FLOAT16_VALUE(  -933.00), SIMDE_FLOAT16_VALUE(  8816.00), SIMDE_FLOAT16_VALUE(   755.50), SIMDE_FLOAT16_VALUE( -5196.00),
        SIMDE_FLOAT16_VALUE(  1241.00), SIMDE_FLOAT16_VALUE( -9352.00), SIMDE_FLOAT16_VALUE(   -26.64), SIMDE_FLOAT16_VALUE(  1449.00) } },
    { { SIMDE_FLOAT16_VALUE(  -146.38), SIMDE_FLOAT16_VALUE(  -174.75), SIMDE_FLOAT16_VALUE(     9.00), SIMDE_FLOAT16_VALUE(    97.50),
        SIMDE_FLOAT16_VALUE(   -64.50), SIMDE_FLOAT16_VALUE(  -198.75), SIMDE_FLOAT16_VALUE(   -83.56), SIMDE_FLOAT16_VALUE(   115.38) },
      { SIMDE_FLOAT16_VALUE(   146.38), SIMDE_FLOAT16_VALUE(  -104.19), SIMDE_FLOAT16_VALUE(   129.38), SIMDE_FLOAT16_VALUE(    37.50),
        SIMDE_FLOAT16_VALUE(    46.59), SIMDE_FLOAT16_VALUE(    58.44), SIMDE_FLOAT16_VALUE(   172.12), SIMDE_FLOAT16_VALUE(     2.71) },
      { SIMDE_FLOAT16_VALUE(    -8.19), SIMDE_FLOAT16_VALUE(   -27.27), SIMDE_FLOAT16_VALUE(   151.12), SIMDE_FLOAT16_VALUE(   156.75),
        SIMDE_FLOAT16_VALUE(  -100.94), SIMDE_FLOAT16_VALUE(    77.44), SIMDE_FLOAT16_VALUE(   -12.85), SIMDE_FLOAT16_VALUE(    46.06) },
       INT32_C(           1),
      { SIMDE_FLOAT16_VALUE( 16184.00), SIMDE_FLOAT16_VALUE(-15920.00), SIMDE_FLOAT16_VALUE( -5868.00), SIMDE_FLOAT16_VALUE(  5764.00),
        SIMDE_FLOAT16_VALUE( -9224.00), SIMDE_FLOAT16_VALUE(  8632.00), SIMDE_FLOAT16_VALUE(  -508.50), SIMDE_FLOAT16_VALUE(   525.00) } },
    { { SIMDE_FLOAT16_VALUE(  -188.62), SIMDE_FLOAT16_VALUE(   -70.12), SIMDE_FLOAT16_VALUE(   -86.06), SIMDE_FLOAT16_VALUE(  -168.12),
        SIMDE_FLOAT16_VALUE(  -196.88), SIMDE_FLOAT16_VALUE(   125.31), SIMDE_FLOAT16_VALUE(   -45.91), SIMDE_FLOAT16_VALUE(   109.19) },
      { SIMDE_FLOAT16_VALUE(    67.75), SIMDE_FLOAT16_VALUE(  -107.50), SIMDE_FLOAT16_VALUE(    42.75), SIMDE_FLOAT16_VALUE(    52.22),
        SIMDE_FLOAT16_VALUE(  -146.00), SIMDE_FLOAT16_VALUE(   -36.34), SIMDE_FLOAT16_VALUE(   142.88), SIMDE_FLOAT16_VALUE(  -153.12) },
      { SIMDE_FLOAT16_VALUE(  -165.12), SIMDE_FLOAT16_VALUE(  -124.38), SIMDE_FLOAT16_VALUE(    12.66), SIMDE_FLOAT16_VALUE(    -7.05),
        SIMDE_FLOAT16_VALUE(  -103.44), SIMDE_FLOAT16_VALUE(    41.03), SIMDE_FLOAT16_VALUE(  -148.75), SIMDE_FLOAT16_VALUE(    34.81) },
       INT32_C(           2),
      { SIMDE_FLOAT16_VALUE(  4224.00), SIMDE_FLOAT16_VALUE( 11048.00), SIMDE_FLOAT16_VALUE( -2228.00), SIMDE_FLOAT16_VALUE( -5568.00),
        SIMDE_FLOAT16_VALUE(  1294.00), SIMDE_FLOAT16_VALUE(  3884.00), SIMDE_FLOAT16_VALUE(  6236.00), SIMDE_FLOAT16_VALUE( 15952.00) } },
    { { SIMDE_FLOAT16_VALUE(   146.25), SIMDE_FLOAT16_VALUE(  -137.75), SIMDE_FLOAT16_VALUE(   -81.50), SIMDE_FLOAT16_VALUE(  -191.12),
        SIMDE_FLOAT16_VALUE(   -33.72), SIMDE_FLOAT16_VALUE(   160.25), SIMDE_FLOAT16_VALUE(    94.25), SIMDE_FLOAT16_VALUE(    18.91) },
      { SIMDE_FLOAT16_VALUE(    43.97), SIMDE_FLOAT16_VALUE(  -140.62), SIMDE_FLOAT16_VALUE(    69.81), SIMDE_FLOAT16_VALUE(   165.38),
        SIMDE_FLOAT16_VALUE(   150.88), SIMDE_FLOAT16_VALUE(  -116.06), SIMDE_FLOAT16_VALUE(   -70.50), SIMDE_FLOAT16_VALUE(   -69.19) },
      { SIMDE_FLOAT16_VALUE(    22.03), SIMDE_FLOAT16_VALUE(  -146.12), SIMDE_FLOAT16_VALUE(    97.31), SIMDE_FLOAT16_VALUE(  -103.25),
        SIMDE_FLOAT16_VALUE(  -188.75), SIMDE_FLOAT16_VALUE(   111.56), SIMDE_FLOAT16_VALUE(    74.94), SIMDE_FLOAT16_VALUE(   143.62) },
       INT32_C(           3),
      { SIMDE_FLOAT16_VALUE( 20336.00), SIMDE_FLOAT16_VALUE(-10672.00), SIMDE_FLOAT16_VALUE(-23840.00), SIMDE_FLOAT16_VALUE( 12200.00),
        SIMDE_FLOAT16_VALUE( 16640.00), SIMDE_FLOAT16_VALUE( -8536.00), SIMDE_FLOAT16_VALUE( 10032.00), SIMDE_FLOAT16_VALUE( -5164.00) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x8_t r_ = simde_vld1q_f16(test_vec[i].r_);
    simde_float16x8_t a = simde_vld1q_f16(test_vec[i].a);
    simde_float16x8_t b = simde_vld1q_f16(test_vec[i].b);
    simde_float16x8_t r;
    switch(i & 3) {
      case 0:
        r = simde_vcmlaq_rot90_laneq_f16(r_, a, b, 0);
        break;
      case 1:
        r = simde_vcmlaq_rot90_laneq_f16(r_, a, b, 1);
        break;
      case 2:
        r = simde_vcmlaq_rot90_laneq_f16(r_, a, b, 2);
        break;
      case 3:
        r = simde_vcmlaq_rot90_laneq_f16(r_, a, b, 3);
        break;
      default:
        HEDLEY_UNREACHABLE();
    }
    simde_test_arm_neon_assert_equal_f16x8(r, simde_vld1q_f16(test_vec[i].r), 1);
  }
  return 0;
#else
  fputc('\n', stdout);
  const int lanes[] = { 0, 1, 2, 3, 0, 1, 2, 3 };
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16x8_t r_ = simde_test_arm_neon_random_f16x8(-200.0f, 200.0f);
    simde_float16x8_t a = simde_test_arm_neon_random_f16x8(-200.0f, 200.0f);
    simde_float16x8_t b = simde_test_arm_neon_random_f16x8(-200.0f, 200.0f);
    simde_float16x8_t r;
    if(i % 4 == 1)
      r = simde_vcmlaq_rot90_laneq_f16(r_, a, b, 1);
    else if(i % 4 == 2)
      r = simde_vcmlaq_rot90_laneq_f16(r_, a, b, 2);
    else if(i % 4 == 3)
      r = simde_vcmlaq_rot90_laneq_f16(r_, a, b, 3);
    else
      r = simde_vcmlaq_rot90_laneq_f16(r_, a, b, 0);


    simde_test_arm_neon_write_f16x8(2, r_, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f16x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lanes[i], SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcmlaq_rot90_laneq_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32_t r_[4];
    simde_float32_t a[4];
    simde_float32_t b[4];
    const int lane;
    simde_float32_t r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   676.67), SIMDE_FLOAT32_C(   809.94), SIMDE_FLOAT32_C(   595.46), SIMDE_FLOAT32_C(   -62.91) },
      { SIMDE_FLOAT32_C(   733.19), SIMDE_FLOAT32_C(   660.73), SIMDE_FLOAT32_C(   919.31), SIMDE_FLOAT32_C(   865.27) },
      { SIMDE_FLOAT32_C(   552.03), SIMDE_FLOAT32_C(    43.45), SIMDE_FLOAT32_C(   223.82), SIMDE_FLOAT32_C(  -305.96) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C(-28032.05), SIMDE_FLOAT32_C(365552.72), SIMDE_FLOAT32_C(-37000.52), SIMDE_FLOAT32_C(477592.12) } },
    { { SIMDE_FLOAT32_C(  -311.58), SIMDE_FLOAT32_C(  -696.00), SIMDE_FLOAT32_C(   412.71), SIMDE_FLOAT32_C(   370.52) },
      { SIMDE_FLOAT32_C(  -655.85), SIMDE_FLOAT32_C(  -854.52), SIMDE_FLOAT32_C(    26.03), SIMDE_FLOAT32_C(  -448.41) },
      { SIMDE_FLOAT32_C(  -445.44), SIMDE_FLOAT32_C(  -523.36), SIMDE_FLOAT32_C(  -171.06), SIMDE_FLOAT32_C(  -991.16) },
       INT32_C(           1),
      { SIMDE_FLOAT32_C(-847277.62), SIMDE_FLOAT32_C(145478.19), SIMDE_FLOAT32_C(-444033.34), SIMDE_FLOAT32_C( 77075.53) } },
    { { SIMDE_FLOAT32_C(  -477.36), SIMDE_FLOAT32_C(   965.45), SIMDE_FLOAT32_C(   365.20), SIMDE_FLOAT32_C(   -47.26) },
      { SIMDE_FLOAT32_C(  -320.04), SIMDE_FLOAT32_C(  -977.54), SIMDE_FLOAT32_C(   467.18), SIMDE_FLOAT32_C(   -64.13) },
      { SIMDE_FLOAT32_C(   187.21), SIMDE_FLOAT32_C(   502.39), SIMDE_FLOAT32_C(  -307.04), SIMDE_FLOAT32_C(  -468.66) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C(490628.97), SIMDE_FLOAT32_C(-182039.81), SIMDE_FLOAT32_C( 32583.47), SIMDE_FLOAT32_C(-12053.04) } },
    { { SIMDE_FLOAT32_C(  -786.03), SIMDE_FLOAT32_C(  -867.52), SIMDE_FLOAT32_C(  -431.74), SIMDE_FLOAT32_C(  -253.44) },
      { SIMDE_FLOAT32_C(   460.71), SIMDE_FLOAT32_C(  -919.05), SIMDE_FLOAT32_C(  -445.17), SIMDE_FLOAT32_C(    44.58) },
      { SIMDE_FLOAT32_C(  -825.63), SIMDE_FLOAT32_C(  -388.81), SIMDE_FLOAT32_C(  -741.36), SIMDE_FLOAT32_C(  -108.76) },
       INT32_C(           1),
      { SIMDE_FLOAT32_C(-100741.91), SIMDE_FLOAT32_C(680479.38), SIMDE_FLOAT32_C(  4416.78), SIMDE_FLOAT32_C(-33303.27) } },
    { { SIMDE_FLOAT32_C(    83.89), SIMDE_FLOAT32_C(    13.44), SIMDE_FLOAT32_C(  -139.40), SIMDE_FLOAT32_C(  -837.31) },
      { SIMDE_FLOAT32_C(  -677.17), SIMDE_FLOAT32_C(   758.42), SIMDE_FLOAT32_C(   746.93), SIMDE_FLOAT32_C(  -263.70) },
      { SIMDE_FLOAT32_C(    50.99), SIMDE_FLOAT32_C(   949.25), SIMDE_FLOAT32_C(    28.81), SIMDE_FLOAT32_C(   181.99) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C(-719846.25), SIMDE_FLOAT32_C( 38685.28), SIMDE_FLOAT32_C(250177.84), SIMDE_FLOAT32_C(-14283.37) } },
    { { SIMDE_FLOAT32_C(   691.62), SIMDE_FLOAT32_C(   125.28), SIMDE_FLOAT32_C(  -398.94), SIMDE_FLOAT32_C(   944.80) },
      { SIMDE_FLOAT32_C(  -683.87), SIMDE_FLOAT32_C(   151.94), SIMDE_FLOAT32_C(  -261.12), SIMDE_FLOAT32_C(  -621.50) },
      { SIMDE_FLOAT32_C(   508.96), SIMDE_FLOAT32_C(   119.38), SIMDE_FLOAT32_C(   425.43), SIMDE_FLOAT32_C(   198.06) },
       INT32_C(           1),
      { SIMDE_FLOAT32_C(-29401.62), SIMDE_FLOAT32_C( 64765.11), SIMDE_FLOAT32_C(122695.35), SIMDE_FLOAT32_C(-263459.94) } },
    { { SIMDE_FLOAT32_C(   762.96), SIMDE_FLOAT32_C(  -981.39), SIMDE_FLOAT32_C(  -169.33), SIMDE_FLOAT32_C(    72.70) },
      { SIMDE_FLOAT32_C(  -114.99), SIMDE_FLOAT32_C(  -710.94), SIMDE_FLOAT32_C(  -760.59), SIMDE_FLOAT32_C(   775.78) },
      { SIMDE_FLOAT32_C(   573.04), SIMDE_FLOAT32_C(  -937.57), SIMDE_FLOAT32_C(   260.18), SIMDE_FLOAT32_C(   841.25) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C(-665793.06), SIMDE_FLOAT32_C(-408378.44), SIMDE_FLOAT32_C(727178.75), SIMDE_FLOAT32_C(444625.66) } },
    { { SIMDE_FLOAT32_C(   901.11), SIMDE_FLOAT32_C(   914.32), SIMDE_FLOAT32_C(   982.77), SIMDE_FLOAT32_C(  -516.71) },
      { SIMDE_FLOAT32_C(  -418.68), SIMDE_FLOAT32_C(  -701.93), SIMDE_FLOAT32_C(   671.63), SIMDE_FLOAT32_C(    18.58) },
      { SIMDE_FLOAT32_C(   306.45), SIMDE_FLOAT32_C(   540.11), SIMDE_FLOAT32_C(  -315.08), SIMDE_FLOAT32_C(   444.57) },
       INT32_C(           1),
      { SIMDE_FLOAT32_C(312958.12), SIMDE_FLOAT32_C(222078.41), SIMDE_FLOAT32_C( -7277.34), SIMDE_FLOAT32_C( -6370.90) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t r_ = simde_vld1q_f32(test_vec[i].r_);
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_float32x4_t b = simde_vld1q_f32(test_vec[i].b);
    simde_float32x4_t r;
    switch(i & 1) {
      case 0:
        r = simde_vcmlaq_rot90_laneq_f32(r_, a, b, 0);
        break;
      case 1:
        r = simde_vcmlaq_rot90_laneq_f32(r_, a, b, 1);
        break;
      default:
        HEDLEY_UNREACHABLE();
    }
    simde_test_arm_neon_assert_equal_f32x4(r, simde_vld1q_f32(test_vec[i].r), 1);
  }
  return 0;
#else
  fputc('\n', stdout);
  const int lanes[] = { 0, 1, 0, 1, 0, 1, 0, 1 };
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x4_t r_ = simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f);
    simde_float32x4_t a = simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f);
    simde_float32x4_t b = simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f);
    simde_float32x4_t r;
    if(i % 2 == 1)
      r = simde_vcmlaq_rot90_laneq_f32(r_, a, b, 1);
    else
      r = simde_vcmlaq_rot90_laneq_f32(r_, a, b, 0);

    simde_test_arm_neon_write_f32x4(2, r_, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lanes[i], SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}
SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vcmla_rot90_lane_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcmla_rot90_lane_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcmla_rot90_laneq_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcmla_rot90_laneq_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcmlaq_rot90_lane_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcmlaq_rot90_lane_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcmlaq_rot90_laneq_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcmlaq_rot90_laneq_f32)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
