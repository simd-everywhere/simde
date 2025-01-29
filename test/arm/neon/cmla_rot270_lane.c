#define SIMDE_TEST_ARM_NEON_INSN cmla_rot270_lane

#include "test-neon.h"
#include "../../../simde/arm/neon/cmla_rot270_lane.h"
#include "../../../simde/arm/neon/dup_n.h"

static int
test_simde_vcmla_rot270_lane_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16_t r_[4];
    simde_float16_t a[4];
    simde_float16_t b[4];
    const int lane;
    simde_float16_t r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT16_VALUE(   -25.19), SIMDE_FLOAT16_VALUE(  -232.38), SIMDE_FLOAT16_VALUE(    -4.53), SIMDE_FLOAT16_VALUE(    39.00) },
      { SIMDE_FLOAT16_VALUE(  -116.00), SIMDE_FLOAT16_VALUE(  -269.00), SIMDE_FLOAT16_VALUE(    -9.35), SIMDE_FLOAT16_VALUE(   126.62) },
      { SIMDE_FLOAT16_VALUE(  -152.00), SIMDE_FLOAT16_VALUE(   182.00), SIMDE_FLOAT16_VALUE(    39.59), SIMDE_FLOAT16_VALUE(    31.48) },
       INT32_C(           0),
      { SIMDE_FLOAT16_VALUE(-48992.00), SIMDE_FLOAT16_VALUE(-41120.00), SIMDE_FLOAT16_VALUE( 23040.00), SIMDE_FLOAT16_VALUE( 19280.00) } },
    { { SIMDE_FLOAT16_VALUE(   -73.31), SIMDE_FLOAT16_VALUE(  -240.25), SIMDE_FLOAT16_VALUE(   -87.56), SIMDE_FLOAT16_VALUE(  -283.25) },
      { SIMDE_FLOAT16_VALUE(   259.50), SIMDE_FLOAT16_VALUE(   -50.38), SIMDE_FLOAT16_VALUE(  -153.25), SIMDE_FLOAT16_VALUE(  -205.50) },
      { SIMDE_FLOAT16_VALUE(     4.19), SIMDE_FLOAT16_VALUE(   207.00), SIMDE_FLOAT16_VALUE(   -18.02), SIMDE_FLOAT16_VALUE(   119.94) },
       INT32_C(           1),
      { SIMDE_FLOAT16_VALUE( -6116.00), SIMDE_FLOAT16_VALUE( -1148.00), SIMDE_FLOAT16_VALUE(-24736.00), SIMDE_FLOAT16_VALUE( -3986.00) } },
    { { SIMDE_FLOAT16_VALUE(  -179.75), SIMDE_FLOAT16_VALUE(   -86.25), SIMDE_FLOAT16_VALUE(   -25.55), SIMDE_FLOAT16_VALUE(   261.00) },
      { SIMDE_FLOAT16_VALUE(     9.96), SIMDE_FLOAT16_VALUE(    35.25), SIMDE_FLOAT16_VALUE(   226.88), SIMDE_FLOAT16_VALUE(   -12.50) },
      { SIMDE_FLOAT16_VALUE(  -158.25), SIMDE_FLOAT16_VALUE(  -244.62), SIMDE_FLOAT16_VALUE(  -283.00), SIMDE_FLOAT16_VALUE(  -174.50) },
       INT32_C(           0),
      { SIMDE_FLOAT16_VALUE( -8800.00), SIMDE_FLOAT16_VALUE(  5492.00), SIMDE_FLOAT16_VALUE(  3032.00), SIMDE_FLOAT16_VALUE( -1717.00) } },
    { { SIMDE_FLOAT16_VALUE(  -279.50), SIMDE_FLOAT16_VALUE(   258.75), SIMDE_FLOAT16_VALUE(    -1.53), SIMDE_FLOAT16_VALUE(    82.31) },
      { SIMDE_FLOAT16_VALUE(  -183.75), SIMDE_FLOAT16_VALUE(    65.31), SIMDE_FLOAT16_VALUE(   177.62), SIMDE_FLOAT16_VALUE(   -91.56) },
      { SIMDE_FLOAT16_VALUE(   -64.50), SIMDE_FLOAT16_VALUE(   256.25), SIMDE_FLOAT16_VALUE(   135.00), SIMDE_FLOAT16_VALUE(   292.00) },
       INT32_C(           1),
      { SIMDE_FLOAT16_VALUE( 18784.00), SIMDE_FLOAT16_VALUE( -8560.00), SIMDE_FLOAT16_VALUE(-26736.00), SIMDE_FLOAT16_VALUE( 12440.00) } },
    { { SIMDE_FLOAT16_VALUE(    35.81), SIMDE_FLOAT16_VALUE(   -23.45), SIMDE_FLOAT16_VALUE(   159.25), SIMDE_FLOAT16_VALUE(    28.23) },
      { SIMDE_FLOAT16_VALUE(  -109.62), SIMDE_FLOAT16_VALUE(  -163.38), SIMDE_FLOAT16_VALUE(  -191.12), SIMDE_FLOAT16_VALUE(   253.88) },
      { SIMDE_FLOAT16_VALUE(   125.31), SIMDE_FLOAT16_VALUE(   177.50), SIMDE_FLOAT16_VALUE(   268.75), SIMDE_FLOAT16_VALUE(   154.62) },
       INT32_C(           0),
      { SIMDE_FLOAT16_VALUE(-28960.00), SIMDE_FLOAT16_VALUE( 20448.00), SIMDE_FLOAT16_VALUE( 45216.00), SIMDE_FLOAT16_VALUE(-31792.00) } },
    { { SIMDE_FLOAT16_VALUE(   -79.38), SIMDE_FLOAT16_VALUE(   187.75), SIMDE_FLOAT16_VALUE(   100.00), SIMDE_FLOAT16_VALUE(   289.75) },
      { SIMDE_FLOAT16_VALUE(   -34.47), SIMDE_FLOAT16_VALUE(   164.00), SIMDE_FLOAT16_VALUE(    45.38), SIMDE_FLOAT16_VALUE(  -274.50) },
      { SIMDE_FLOAT16_VALUE(   120.31), SIMDE_FLOAT16_VALUE(   -13.77), SIMDE_FLOAT16_VALUE(    94.56), SIMDE_FLOAT16_VALUE(  -242.00) },
       INT32_C(           1),
      { SIMDE_FLOAT16_VALUE(-39776.00), SIMDE_FLOAT16_VALUE(-15320.00),      SIMDE_INFINITYHF, SIMDE_FLOAT16_VALUE( 26240.00) } },
    { { SIMDE_FLOAT16_VALUE(   160.25), SIMDE_FLOAT16_VALUE(   -23.23), SIMDE_FLOAT16_VALUE(   -78.19), SIMDE_FLOAT16_VALUE(   170.50) },
      { SIMDE_FLOAT16_VALUE(   272.75), SIMDE_FLOAT16_VALUE(   124.50), SIMDE_FLOAT16_VALUE(   185.12), SIMDE_FLOAT16_VALUE(  -112.75) },
      { SIMDE_FLOAT16_VALUE(    91.75), SIMDE_FLOAT16_VALUE(    81.94), SIMDE_FLOAT16_VALUE(   248.88), SIMDE_FLOAT16_VALUE(  -107.94) },
       INT32_C(           0),
      { SIMDE_FLOAT16_VALUE( 10360.00), SIMDE_FLOAT16_VALUE(-11448.00), SIMDE_FLOAT16_VALUE( -9320.00), SIMDE_FLOAT16_VALUE( 10512.00) } },
    { { SIMDE_FLOAT16_VALUE(   -28.30), SIMDE_FLOAT16_VALUE(  -248.50), SIMDE_FLOAT16_VALUE(    -8.07), SIMDE_FLOAT16_VALUE(    31.56) },
      { SIMDE_FLOAT16_VALUE(    10.48), SIMDE_FLOAT16_VALUE(  -218.25), SIMDE_FLOAT16_VALUE(    49.38), SIMDE_FLOAT16_VALUE(    58.81) },
      { SIMDE_FLOAT16_VALUE(   238.12), SIMDE_FLOAT16_VALUE(  -179.62), SIMDE_FLOAT16_VALUE(  -239.00), SIMDE_FLOAT16_VALUE(   140.62) },
       INT32_C(           1),
      { SIMDE_FLOAT16_VALUE(-30720.00), SIMDE_FLOAT16_VALUE(-52416.00), SIMDE_FLOAT16_VALUE(  8264.00), SIMDE_FLOAT16_VALUE( 14088.00) } }
    
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x4_t r_ = simde_vld1_f16(test_vec[i].r_);
    simde_float16x4_t a = simde_vld1_f16(test_vec[i].a);
    simde_float16x4_t b = simde_vld1_f16(test_vec[i].b);
    simde_float16x4_t r;
    switch(i & 1) {
      case 0:
        r = simde_vcmla_rot270_lane_f16(r_, a, b, 0);
        break;
      case 1:
        r = simde_vcmla_rot270_lane_f16(r_, a, b, 1);
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
      r = simde_vcmla_rot270_lane_f16(r_, a, b, 1);
    else
      r = simde_vcmla_rot270_lane_f16(r_, a, b, 0);


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
test_simde_vcmla_rot270_lane_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32_t r_[2];
    simde_float32_t a[2];
    simde_float32_t b[2];
    const int lane;
    simde_float32_t r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -236.13), SIMDE_FLOAT32_C(  -252.85) },
      { SIMDE_FLOAT32_C(   172.47), SIMDE_FLOAT32_C(    46.66) },
      { SIMDE_FLOAT32_C(    79.92), SIMDE_FLOAT32_C(  -139.43) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C( -6741.93), SIMDE_FLOAT32_C( -3981.92) } },
    { { SIMDE_FLOAT32_C(   124.84), SIMDE_FLOAT32_C(   -72.68) },
      { SIMDE_FLOAT32_C(   146.86), SIMDE_FLOAT32_C(  -168.14) },
      { SIMDE_FLOAT32_C(    40.07), SIMDE_FLOAT32_C(   267.82) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C(-44906.41), SIMDE_FLOAT32_C(  6664.69) } },
    { { SIMDE_FLOAT32_C(    89.51), SIMDE_FLOAT32_C(   114.95) },
      { SIMDE_FLOAT32_C(   -14.73), SIMDE_FLOAT32_C(   153.26) },
      { SIMDE_FLOAT32_C(    14.21), SIMDE_FLOAT32_C(   107.02) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C( 16491.39), SIMDE_FLOAT32_C( -2062.87) } },
    { { SIMDE_FLOAT32_C(   -46.39), SIMDE_FLOAT32_C(  -228.17) },
      { SIMDE_FLOAT32_C(  -198.04), SIMDE_FLOAT32_C(  -291.73) },
      { SIMDE_FLOAT32_C(   168.13), SIMDE_FLOAT32_C(  -297.06) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C( 86614.93), SIMDE_FLOAT32_C( 48820.40) } },
    { { SIMDE_FLOAT32_C(  -147.86), SIMDE_FLOAT32_C(    49.65) },
      { SIMDE_FLOAT32_C(  -117.60), SIMDE_FLOAT32_C(  -156.49) },
      { SIMDE_FLOAT32_C(  -272.27), SIMDE_FLOAT32_C(   191.13) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C(-30057.79), SIMDE_FLOAT32_C(-42557.88) } },
    { { SIMDE_FLOAT32_C(   -51.96), SIMDE_FLOAT32_C(  -273.83) },
      { SIMDE_FLOAT32_C(  -295.52), SIMDE_FLOAT32_C(    17.02) },
      { SIMDE_FLOAT32_C(   -79.80), SIMDE_FLOAT32_C(  -211.00) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C( -3643.18), SIMDE_FLOAT32_C(  1084.37) } },
    { { SIMDE_FLOAT32_C(   259.58), SIMDE_FLOAT32_C(   238.85) },
      { SIMDE_FLOAT32_C(   291.04), SIMDE_FLOAT32_C(  -280.49) },
      { SIMDE_FLOAT32_C(   -27.31), SIMDE_FLOAT32_C(   -70.77) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C( 20109.86), SIMDE_FLOAT32_C( -7421.33) } },
    { { SIMDE_FLOAT32_C(  -276.32), SIMDE_FLOAT32_C(   -51.49) },
      { SIMDE_FLOAT32_C(  -144.37), SIMDE_FLOAT32_C(   -12.71) },
      { SIMDE_FLOAT32_C(    25.89), SIMDE_FLOAT32_C(    66.85) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C( -1125.98), SIMDE_FLOAT32_C(   277.57) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t r_ = simde_vld1_f32(test_vec[i].r_);
    simde_float32x2_t a = simde_vld1_f32(test_vec[i].a);
    simde_float32x2_t b = simde_vld1_f32(test_vec[i].b);
    simde_float32x2_t r = simde_vcmla_rot270_lane_f32(r_, a, b, 0);

    simde_test_arm_neon_assert_equal_f32x2(r, simde_vld1_f32(test_vec[i].r), 1);
  }
  
  return 0;
#else
  fputc('\n', stdout);
  const int lanes[] = { 0, 0, 0, 0, 0, 0, 0, 0 };
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x2_t r_ = simde_test_arm_neon_random_f32x2(-300.0f, 300.0f);
    simde_float32x2_t a = simde_test_arm_neon_random_f32x2(-300.0f, 300.0f);
    simde_float32x2_t b = simde_test_arm_neon_random_f32x2(-300.0f, 300.0f);
    simde_float32x2_t r = simde_vcmla_rot270_lane_f32(r_, a, b, 0);


    simde_test_arm_neon_write_f32x2(2, r_, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x2(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lanes[i], SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}


static int
test_simde_vcmla_rot270_laneq_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16_t r_[4];
    simde_float16_t a[4];
    simde_float16_t b[8];
    const int lane;
    simde_float16_t r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT16_VALUE(    96.19), SIMDE_FLOAT16_VALUE(   167.50), SIMDE_FLOAT16_VALUE(    36.31), SIMDE_FLOAT16_VALUE(  -112.94) },
      { SIMDE_FLOAT16_VALUE(   -58.38), SIMDE_FLOAT16_VALUE(    -1.59), SIMDE_FLOAT16_VALUE(    93.50), SIMDE_FLOAT16_VALUE(  -122.88) },
      { SIMDE_FLOAT16_VALUE(   177.50), SIMDE_FLOAT16_VALUE(  -161.25), SIMDE_FLOAT16_VALUE(   -67.31), SIMDE_FLOAT16_VALUE(   108.62),
        SIMDE_FLOAT16_VALUE(  -166.38), SIMDE_FLOAT16_VALUE(  -146.00), SIMDE_FLOAT16_VALUE(   168.50), SIMDE_FLOAT16_VALUE(  -140.12) },
       INT32_C(           0),
      { SIMDE_FLOAT16_VALUE(   352.50), SIMDE_FLOAT16_VALUE(   449.75), SIMDE_FLOAT16_VALUE( 19856.00), SIMDE_FLOAT16_VALUE( 21696.00) } },
    { { SIMDE_FLOAT16_VALUE(   131.38), SIMDE_FLOAT16_VALUE(   -81.50), SIMDE_FLOAT16_VALUE(   -34.88), SIMDE_FLOAT16_VALUE(   -74.81) },
      { SIMDE_FLOAT16_VALUE(   -53.81), SIMDE_FLOAT16_VALUE(    43.38), SIMDE_FLOAT16_VALUE(    78.19), SIMDE_FLOAT16_VALUE(    86.44) },
      { SIMDE_FLOAT16_VALUE(  -148.12), SIMDE_FLOAT16_VALUE(    86.06), SIMDE_FLOAT16_VALUE(    62.94), SIMDE_FLOAT16_VALUE(   192.12),
        SIMDE_FLOAT16_VALUE(    50.38), SIMDE_FLOAT16_VALUE(   -94.56), SIMDE_FLOAT16_VALUE(   164.62), SIMDE_FLOAT16_VALUE(   -41.28) },
       INT32_C(           1),
      { SIMDE_FLOAT16_VALUE(  8464.00), SIMDE_FLOAT16_VALUE( -2812.00), SIMDE_FLOAT16_VALUE( 16576.00), SIMDE_FLOAT16_VALUE( -5516.00) } },
    { { SIMDE_FLOAT16_VALUE(   -78.00), SIMDE_FLOAT16_VALUE(   173.25), SIMDE_FLOAT16_VALUE(   -37.34), SIMDE_FLOAT16_VALUE(   142.88) },
      { SIMDE_FLOAT16_VALUE(   135.38), SIMDE_FLOAT16_VALUE(   -60.06), SIMDE_FLOAT16_VALUE(    40.84), SIMDE_FLOAT16_VALUE(   -14.89) },
      { SIMDE_FLOAT16_VALUE(   106.94), SIMDE_FLOAT16_VALUE(  -123.88), SIMDE_FLOAT16_VALUE(   -98.38), SIMDE_FLOAT16_VALUE(  -144.88),
        SIMDE_FLOAT16_VALUE(    19.45), SIMDE_FLOAT16_VALUE(   -77.19), SIMDE_FLOAT16_VALUE(   188.62), SIMDE_FLOAT16_VALUE(  -198.00) },
       INT32_C(           0),
      { SIMDE_FLOAT16_VALUE(  7364.00), SIMDE_FLOAT16_VALUE(  6596.00), SIMDE_FLOAT16_VALUE(  1807.00), SIMDE_FLOAT16_VALUE(  1735.00) } },
    { { SIMDE_FLOAT16_VALUE(  -130.38), SIMDE_FLOAT16_VALUE(    75.88), SIMDE_FLOAT16_VALUE(  -199.50), SIMDE_FLOAT16_VALUE(   -35.19) },
      { SIMDE_FLOAT16_VALUE(    15.55), SIMDE_FLOAT16_VALUE(   142.75), SIMDE_FLOAT16_VALUE(   181.75), SIMDE_FLOAT16_VALUE(   156.88) },
      { SIMDE_FLOAT16_VALUE(    49.38), SIMDE_FLOAT16_VALUE(   -87.06), SIMDE_FLOAT16_VALUE(   191.38), SIMDE_FLOAT16_VALUE(    21.02),
        SIMDE_FLOAT16_VALUE(  -152.25), SIMDE_FLOAT16_VALUE(    58.97), SIMDE_FLOAT16_VALUE(  -127.88), SIMDE_FLOAT16_VALUE(   133.88) },
       INT32_C(           1),
      { SIMDE_FLOAT16_VALUE(  2870.00), SIMDE_FLOAT16_VALUE(-27248.00), SIMDE_FLOAT16_VALUE(  3098.00), SIMDE_FLOAT16_VALUE(-30064.00) } },
    { { SIMDE_FLOAT16_VALUE(   185.75), SIMDE_FLOAT16_VALUE(    81.69), SIMDE_FLOAT16_VALUE(    -5.27), SIMDE_FLOAT16_VALUE(  -122.00) },
      { SIMDE_FLOAT16_VALUE(   -22.02), SIMDE_FLOAT16_VALUE(   -70.69), SIMDE_FLOAT16_VALUE(   -50.28), SIMDE_FLOAT16_VALUE(   121.62) },
      { SIMDE_FLOAT16_VALUE(  -195.12), SIMDE_FLOAT16_VALUE(   156.38), SIMDE_FLOAT16_VALUE(    72.00), SIMDE_FLOAT16_VALUE(   -48.03),
        SIMDE_FLOAT16_VALUE(    26.00), SIMDE_FLOAT16_VALUE(   169.38), SIMDE_FLOAT16_VALUE(    37.59), SIMDE_FLOAT16_VALUE(   -21.22) },
       INT32_C(           0),
      { SIMDE_FLOAT16_VALUE(-10872.00), SIMDE_FLOAT16_VALUE(-13712.00), SIMDE_FLOAT16_VALUE( 19008.00), SIMDE_FLOAT16_VALUE( 23616.00) } },
    { { SIMDE_FLOAT16_VALUE(   178.00), SIMDE_FLOAT16_VALUE(   -50.81), SIMDE_FLOAT16_VALUE(    48.09), SIMDE_FLOAT16_VALUE(   -34.09) },
      { SIMDE_FLOAT16_VALUE(  -153.50), SIMDE_FLOAT16_VALUE(   119.38), SIMDE_FLOAT16_VALUE(    84.44), SIMDE_FLOAT16_VALUE(  -124.31) },
      { SIMDE_FLOAT16_VALUE(  -178.88), SIMDE_FLOAT16_VALUE(   164.62), SIMDE_FLOAT16_VALUE(  -142.75), SIMDE_FLOAT16_VALUE(   120.25),
        SIMDE_FLOAT16_VALUE(     0.53), SIMDE_FLOAT16_VALUE(   181.00), SIMDE_FLOAT16_VALUE(   121.25), SIMDE_FLOAT16_VALUE(    15.29) },
       INT32_C(           1),
      { SIMDE_FLOAT16_VALUE( 14536.00), SIMDE_FLOAT16_VALUE( 16992.00), SIMDE_FLOAT16_VALUE(-14904.00), SIMDE_FLOAT16_VALUE(-17776.00) } },
    { { SIMDE_FLOAT16_VALUE(   160.38), SIMDE_FLOAT16_VALUE(    28.97), SIMDE_FLOAT16_VALUE(    40.97), SIMDE_FLOAT16_VALUE(    23.77) },
      { SIMDE_FLOAT16_VALUE(  -193.38), SIMDE_FLOAT16_VALUE(   181.88), SIMDE_FLOAT16_VALUE(    56.44), SIMDE_FLOAT16_VALUE(    48.69) },
      { SIMDE_FLOAT16_VALUE(   134.50), SIMDE_FLOAT16_VALUE(   -32.12), SIMDE_FLOAT16_VALUE(  -128.25), SIMDE_FLOAT16_VALUE(   -66.19),
        SIMDE_FLOAT16_VALUE(   -90.62), SIMDE_FLOAT16_VALUE(    44.62), SIMDE_FLOAT16_VALUE(  -114.25), SIMDE_FLOAT16_VALUE(    71.56) },
       INT32_C(           0),
      { SIMDE_FLOAT16_VALUE( -5684.00), SIMDE_FLOAT16_VALUE(-24432.00), SIMDE_FLOAT16_VALUE( -1523.00), SIMDE_FLOAT16_VALUE( -6524.00) } },
    { { SIMDE_FLOAT16_VALUE(   -47.50), SIMDE_FLOAT16_VALUE(   128.75), SIMDE_FLOAT16_VALUE(  -145.62), SIMDE_FLOAT16_VALUE(   106.81) },
      { SIMDE_FLOAT16_VALUE(   116.00), SIMDE_FLOAT16_VALUE(   168.75), SIMDE_FLOAT16_VALUE(    31.67), SIMDE_FLOAT16_VALUE(   -94.44) },
      { SIMDE_FLOAT16_VALUE(  -150.25), SIMDE_FLOAT16_VALUE(    -6.83), SIMDE_FLOAT16_VALUE(   -19.30), SIMDE_FLOAT16_VALUE(    24.03),
        SIMDE_FLOAT16_VALUE(   -55.47), SIMDE_FLOAT16_VALUE(    11.40), SIMDE_FLOAT16_VALUE(    68.00), SIMDE_FLOAT16_VALUE(   120.06) },
       INT32_C(           1),
      { SIMDE_FLOAT16_VALUE(  4008.00), SIMDE_FLOAT16_VALUE(  3386.00), SIMDE_FLOAT16_VALUE( -2416.00), SIMDE_FLOAT16_VALUE( -1716.00) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x4_t r_ = simde_vld1_f16(test_vec[i].r_);
    simde_float16x4_t a = simde_vld1_f16(test_vec[i].a);
    simde_float16x8_t b = simde_vld1q_f16(test_vec[i].b);
    
    simde_float16x4_t r;
    switch(i & 1) {
      case 0:
        r = simde_vcmla_rot270_laneq_f16(r_, a, b, 0);
        break;
      case 1:
        r = simde_vcmla_rot270_laneq_f16(r_, a, b, 1);
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
    simde_float16x4_t r_ = simde_test_arm_neon_random_f16x4(-200.0f, 200.0f);
    simde_float16x4_t a = simde_test_arm_neon_random_f16x4(-200.0f, 200.0f);
    simde_float16x8_t b = simde_test_arm_neon_random_f16x8(-200.0f, 200.0f);
    simde_float16x4_t r;
    if(i % 2)
      r = simde_vcmla_rot270_laneq_f16(r_, a, b, 1);
    else
      r = simde_vcmla_rot270_laneq_f16(r_, a, b, 0);


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
test_simde_vcmla_rot270_laneq_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32_t r_[2];
    simde_float32_t a[2];
    simde_float32_t b[4];
    const int lane;
    simde_float32_t r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -373.38), SIMDE_FLOAT32_C(   628.68) },
      { SIMDE_FLOAT32_C(   168.41), SIMDE_FLOAT32_C(   443.47) },
      { SIMDE_FLOAT32_C(  -612.75), SIMDE_FLOAT32_C(  -459.39), SIMDE_FLOAT32_C(  -916.11), SIMDE_FLOAT32_C(   931.91) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C(-204099.08), SIMDE_FLOAT32_C(272364.94) } },
    { { SIMDE_FLOAT32_C(   631.46), SIMDE_FLOAT32_C(  -977.95) },
      { SIMDE_FLOAT32_C(  -435.60), SIMDE_FLOAT32_C(   922.11) },
      { SIMDE_FLOAT32_C(  -150.91), SIMDE_FLOAT32_C(  -327.46), SIMDE_FLOAT32_C(   317.23), SIMDE_FLOAT32_C(  -281.41) },
       INT32_C(           1),
      { SIMDE_FLOAT32_C(-258859.52), SIMDE_FLOAT32_C(-293498.91) } },
    { { SIMDE_FLOAT32_C(   332.91), SIMDE_FLOAT32_C(  -759.15) },
      { SIMDE_FLOAT32_C(   931.28), SIMDE_FLOAT32_C(   -40.73) },
      { SIMDE_FLOAT32_C(  -536.62), SIMDE_FLOAT32_C(  -965.05), SIMDE_FLOAT32_C(   429.21), SIMDE_FLOAT32_C(  -211.19) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C( 39639.39), SIMDE_FLOAT32_C(-22615.68) } },
    { { SIMDE_FLOAT32_C(   546.88), SIMDE_FLOAT32_C(  -662.33) },
      { SIMDE_FLOAT32_C(   213.37), SIMDE_FLOAT32_C(   167.98) },
      { SIMDE_FLOAT32_C(  -685.91), SIMDE_FLOAT32_C(  -171.63), SIMDE_FLOAT32_C(  -594.01), SIMDE_FLOAT32_C(   498.11) },
       INT32_C(           1),
      { SIMDE_FLOAT32_C( 84219.39), SIMDE_FLOAT32_C( 99119.47) } },
    { { SIMDE_FLOAT32_C(  -186.41), SIMDE_FLOAT32_C(  -925.57) },
      { SIMDE_FLOAT32_C(    11.18), SIMDE_FLOAT32_C(  -176.24) },
      { SIMDE_FLOAT32_C(   -63.01), SIMDE_FLOAT32_C(   963.69), SIMDE_FLOAT32_C(   756.06), SIMDE_FLOAT32_C(  -910.41) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C(-170027.14), SIMDE_FLOAT32_C(-12030.45) } },
    { { SIMDE_FLOAT32_C(   822.34), SIMDE_FLOAT32_C(  -923.74) },
      { SIMDE_FLOAT32_C(   685.17), SIMDE_FLOAT32_C(  -281.64) },
      { SIMDE_FLOAT32_C(   454.74), SIMDE_FLOAT32_C(   846.84), SIMDE_FLOAT32_C(   848.39), SIMDE_FLOAT32_C(   894.00) },
       INT32_C(           1),
      { SIMDE_FLOAT32_C(-250963.83), SIMDE_FLOAT32_C(238016.84) } },
    { { SIMDE_FLOAT32_C(  -554.71), SIMDE_FLOAT32_C(  -934.81) },
      { SIMDE_FLOAT32_C(   598.72), SIMDE_FLOAT32_C(   671.12) },
      { SIMDE_FLOAT32_C(  -483.92), SIMDE_FLOAT32_C(   705.72), SIMDE_FLOAT32_C(   962.92), SIMDE_FLOAT32_C(  -149.20) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C(473068.06), SIMDE_FLOAT32_C(323833.59) } },
    { { SIMDE_FLOAT32_C(   379.99), SIMDE_FLOAT32_C(   448.73) },
      { SIMDE_FLOAT32_C(  -224.18), SIMDE_FLOAT32_C(   280.11) },
      { SIMDE_FLOAT32_C(  -156.10), SIMDE_FLOAT32_C(   423.01), SIMDE_FLOAT32_C(  -412.58), SIMDE_FLOAT32_C(  -242.83) },
       INT32_C(           1),
      { SIMDE_FLOAT32_C(-67639.12), SIMDE_FLOAT32_C(116016.51) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t r_ = simde_vld1_f32(test_vec[i].r_);
    simde_float32x2_t a = simde_vld1_f32(test_vec[i].a);
    simde_float32x4_t b = simde_vld1q_f32(test_vec[i].b);
    simde_float32x2_t r;
    switch(i & 1) {
      case 0:
        r = simde_vcmla_rot270_laneq_f32(r_, a, b, 0);
        break;
      case 1:
        r = simde_vcmla_rot270_laneq_f32(r_, a, b, 1);
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
      r = simde_vcmla_rot270_laneq_f32(r_, a, b, 1);
    else
      r = simde_vcmla_rot270_laneq_f32(r_, a, b, 0);
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
test_simde_vcmlaq_rot270_lane_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16_t r_[8];
    simde_float16_t a[8];
    simde_float16_t b[4];
    const int lane;
    simde_float16_t r[8];
  } test_vec[] = {
    { { SIMDE_FLOAT16_VALUE(   234.62), SIMDE_FLOAT16_VALUE(  -231.38), SIMDE_FLOAT16_VALUE(  -145.12), SIMDE_FLOAT16_VALUE(  -115.50),
        SIMDE_FLOAT16_VALUE(  -261.75), SIMDE_FLOAT16_VALUE(    50.06), SIMDE_FLOAT16_VALUE(   -92.81), SIMDE_FLOAT16_VALUE(   -38.81) },
      { SIMDE_FLOAT16_VALUE(   -12.77), SIMDE_FLOAT16_VALUE(   202.88), SIMDE_FLOAT16_VALUE(  -237.50), SIMDE_FLOAT16_VALUE(   -15.54),
        SIMDE_FLOAT16_VALUE(  -251.00), SIMDE_FLOAT16_VALUE(  -250.62), SIMDE_FLOAT16_VALUE(   266.00), SIMDE_FLOAT16_VALUE(    23.39) },
      { SIMDE_FLOAT16_VALUE(   197.12), SIMDE_FLOAT16_VALUE(  -107.00), SIMDE_FLOAT16_VALUE(    51.44), SIMDE_FLOAT16_VALUE(  -287.75) },
       INT32_C(           0),
      { SIMDE_FLOAT16_VALUE(-21472.00), SIMDE_FLOAT16_VALUE(-40224.00), SIMDE_FLOAT16_VALUE(  1518.00), SIMDE_FLOAT16_VALUE(  2948.00),
        SIMDE_FLOAT16_VALUE( 26560.00), SIMDE_FLOAT16_VALUE( 49440.00), SIMDE_FLOAT16_VALUE( -2596.00), SIMDE_FLOAT16_VALUE( -4648.00) } },
    { { SIMDE_FLOAT16_VALUE(    56.75), SIMDE_FLOAT16_VALUE(  -229.38), SIMDE_FLOAT16_VALUE(   227.38), SIMDE_FLOAT16_VALUE(   263.00),
        SIMDE_FLOAT16_VALUE(  -164.75), SIMDE_FLOAT16_VALUE(   203.50), SIMDE_FLOAT16_VALUE(    48.62), SIMDE_FLOAT16_VALUE(   111.75) },
      { SIMDE_FLOAT16_VALUE(   -29.09), SIMDE_FLOAT16_VALUE(     9.13), SIMDE_FLOAT16_VALUE(  -172.50), SIMDE_FLOAT16_VALUE(  -268.75),
        SIMDE_FLOAT16_VALUE(   -85.88), SIMDE_FLOAT16_VALUE(   204.00), SIMDE_FLOAT16_VALUE(   165.75), SIMDE_FLOAT16_VALUE(  -232.88) },
      { SIMDE_FLOAT16_VALUE(   -16.59), SIMDE_FLOAT16_VALUE(   194.25), SIMDE_FLOAT16_VALUE(   286.50), SIMDE_FLOAT16_VALUE(   224.75) },
       INT32_C(           1),
      { SIMDE_FLOAT16_VALUE(  2110.00), SIMDE_FLOAT16_VALUE( -2846.00), SIMDE_FLOAT16_VALUE(-60160.00),      SIMDE_INFINITYHF,
        SIMDE_FLOAT16_VALUE( 45696.00), SIMDE_FLOAT16_VALUE(-58240.00), SIMDE_FLOAT16_VALUE(-52288.00),      SIMDE_INFINITYHF } },
    { { SIMDE_FLOAT16_VALUE(    10.48), SIMDE_FLOAT16_VALUE(   285.75), SIMDE_FLOAT16_VALUE(   238.50), SIMDE_FLOAT16_VALUE(   288.25),
        SIMDE_FLOAT16_VALUE(   -48.62), SIMDE_FLOAT16_VALUE(  -194.25), SIMDE_FLOAT16_VALUE(   194.50), SIMDE_FLOAT16_VALUE(   159.62) },
      { SIMDE_FLOAT16_VALUE(   108.44), SIMDE_FLOAT16_VALUE(   195.38), SIMDE_FLOAT16_VALUE(  -187.75), SIMDE_FLOAT16_VALUE(   136.38),
        SIMDE_FLOAT16_VALUE(    64.31), SIMDE_FLOAT16_VALUE(   112.94), SIMDE_FLOAT16_VALUE(   166.50), SIMDE_FLOAT16_VALUE(  -182.75) },
      { SIMDE_FLOAT16_VALUE(   -38.88), SIMDE_FLOAT16_VALUE(    34.28), SIMDE_FLOAT16_VALUE(  -207.50), SIMDE_FLOAT16_VALUE(   217.88) },
       INT32_C(           0),
      { SIMDE_FLOAT16_VALUE(  6708.00), SIMDE_FLOAT16_VALUE(  7880.00), SIMDE_FLOAT16_VALUE(  4912.00), SIMDE_FLOAT16_VALUE(  5588.00),
        SIMDE_FLOAT16_VALUE(  3824.00), SIMDE_FLOAT16_VALUE(  4196.00), SIMDE_FLOAT16_VALUE( -6072.00), SIMDE_FLOAT16_VALUE( -6944.00) } },
    { { SIMDE_FLOAT16_VALUE(   215.50), SIMDE_FLOAT16_VALUE(   263.00), SIMDE_FLOAT16_VALUE(   -91.81), SIMDE_FLOAT16_VALUE(   -83.38),
        SIMDE_FLOAT16_VALUE(   275.00), SIMDE_FLOAT16_VALUE(  -145.38), SIMDE_FLOAT16_VALUE(   169.88), SIMDE_FLOAT16_VALUE(    73.00) },
      { SIMDE_FLOAT16_VALUE(   201.00), SIMDE_FLOAT16_VALUE(    95.38), SIMDE_FLOAT16_VALUE(   201.00), SIMDE_FLOAT16_VALUE(   158.75),
        SIMDE_FLOAT16_VALUE(   196.88), SIMDE_FLOAT16_VALUE(   266.25), SIMDE_FLOAT16_VALUE(   149.75), SIMDE_FLOAT16_VALUE(   202.12) },
      { SIMDE_FLOAT16_VALUE(  -112.31), SIMDE_FLOAT16_VALUE(    75.06), SIMDE_FLOAT16_VALUE(  -100.94), SIMDE_FLOAT16_VALUE(  -113.31) },
       INT32_C(           1),
      { SIMDE_FLOAT16_VALUE(-10592.00), SIMDE_FLOAT16_VALUE(  9888.00), SIMDE_FLOAT16_VALUE(-18080.00), SIMDE_FLOAT16_VALUE( 15944.00),
        SIMDE_FLOAT16_VALUE(-29888.00), SIMDE_FLOAT16_VALUE( 26736.00), SIMDE_FLOAT16_VALUE(-22736.00), SIMDE_FLOAT16_VALUE( 20480.00) } },
    { { SIMDE_FLOAT16_VALUE(    37.41), SIMDE_FLOAT16_VALUE(  -253.62), SIMDE_FLOAT16_VALUE(  -192.75), SIMDE_FLOAT16_VALUE(  -186.88),
        SIMDE_FLOAT16_VALUE(  -112.50), SIMDE_FLOAT16_VALUE(    87.75), SIMDE_FLOAT16_VALUE(   122.50), SIMDE_FLOAT16_VALUE(   -80.50) },
      { SIMDE_FLOAT16_VALUE(   277.75), SIMDE_FLOAT16_VALUE(  -294.75), SIMDE_FLOAT16_VALUE(  -120.56), SIMDE_FLOAT16_VALUE(  -222.62),
        SIMDE_FLOAT16_VALUE(    60.16), SIMDE_FLOAT16_VALUE(   -19.69), SIMDE_FLOAT16_VALUE(  -151.12), SIMDE_FLOAT16_VALUE(   -83.31) },
      { SIMDE_FLOAT16_VALUE(   -87.44), SIMDE_FLOAT16_VALUE(   123.25), SIMDE_FLOAT16_VALUE(  -210.50), SIMDE_FLOAT16_VALUE(   128.88) },
       INT32_C(           0),
      { SIMDE_FLOAT16_VALUE(-36288.00), SIMDE_FLOAT16_VALUE(-26032.00), SIMDE_FLOAT16_VALUE(-27632.00), SIMDE_FLOAT16_VALUE(-19648.00),
        SIMDE_FLOAT16_VALUE( -2538.00), SIMDE_FLOAT16_VALUE( -1634.00), SIMDE_FLOAT16_VALUE(-10144.00), SIMDE_FLOAT16_VALUE( -7364.00) } },
    { { SIMDE_FLOAT16_VALUE(   173.50), SIMDE_FLOAT16_VALUE(  -203.62), SIMDE_FLOAT16_VALUE(    35.69), SIMDE_FLOAT16_VALUE(  -123.00),
        SIMDE_FLOAT16_VALUE(   -82.62), SIMDE_FLOAT16_VALUE(    56.00), SIMDE_FLOAT16_VALUE(  -250.12), SIMDE_FLOAT16_VALUE(  -125.75) },
      { SIMDE_FLOAT16_VALUE(  -150.50), SIMDE_FLOAT16_VALUE(    17.44), SIMDE_FLOAT16_VALUE(   126.81), SIMDE_FLOAT16_VALUE(  -196.62),
        SIMDE_FLOAT16_VALUE(   208.25), SIMDE_FLOAT16_VALUE(  -141.38), SIMDE_FLOAT16_VALUE(  -242.62), SIMDE_FLOAT16_VALUE(   -76.12) },
      { SIMDE_FLOAT16_VALUE(    75.44), SIMDE_FLOAT16_VALUE(   173.50), SIMDE_FLOAT16_VALUE(  -192.12), SIMDE_FLOAT16_VALUE(   160.12) },
       INT32_C(           1),
      { SIMDE_FLOAT16_VALUE(  2966.00), SIMDE_FLOAT16_VALUE(  3146.00), SIMDE_FLOAT16_VALUE(-31456.00), SIMDE_FLOAT16_VALUE(-37888.00),
        SIMDE_FLOAT16_VALUE(-22720.00), SIMDE_FLOAT16_VALUE(-27104.00), SIMDE_FLOAT16_VALUE(-12440.00), SIMDE_FLOAT16_VALUE(-14752.00) } },
    { { SIMDE_FLOAT16_VALUE(    12.42), SIMDE_FLOAT16_VALUE(     6.08), SIMDE_FLOAT16_VALUE(   187.38), SIMDE_FLOAT16_VALUE(   231.38),
        SIMDE_FLOAT16_VALUE(   140.12), SIMDE_FLOAT16_VALUE(   -34.16), SIMDE_FLOAT16_VALUE(   -25.70), SIMDE_FLOAT16_VALUE(   133.88) },
      { SIMDE_FLOAT16_VALUE(  -183.38), SIMDE_FLOAT16_VALUE(  -101.75), SIMDE_FLOAT16_VALUE(   278.25), SIMDE_FLOAT16_VALUE(   -12.21),
        SIMDE_FLOAT16_VALUE(    55.03), SIMDE_FLOAT16_VALUE(  -209.75), SIMDE_FLOAT16_VALUE(   195.75), SIMDE_FLOAT16_VALUE(   105.88) },
      { SIMDE_FLOAT16_VALUE(    98.81), SIMDE_FLOAT16_VALUE(   269.00), SIMDE_FLOAT16_VALUE(   180.12), SIMDE_FLOAT16_VALUE(   -61.47) },
       INT32_C(           0),
      { SIMDE_FLOAT16_VALUE(-27360.00), SIMDE_FLOAT16_VALUE( 10064.00), SIMDE_FLOAT16_VALUE( -3098.00), SIMDE_FLOAT16_VALUE(  1438.00),
        SIMDE_FLOAT16_VALUE(-56288.00), SIMDE_FLOAT16_VALUE( 20688.00), SIMDE_FLOAT16_VALUE( 28448.00), SIMDE_FLOAT16_VALUE(-10328.00) } },
    { { SIMDE_FLOAT16_VALUE(   197.75), SIMDE_FLOAT16_VALUE(  -245.12), SIMDE_FLOAT16_VALUE(   -30.56), SIMDE_FLOAT16_VALUE(   -23.75),
        SIMDE_FLOAT16_VALUE(  -116.62), SIMDE_FLOAT16_VALUE(   -25.19), SIMDE_FLOAT16_VALUE(   240.75), SIMDE_FLOAT16_VALUE(  -174.12) },
      { SIMDE_FLOAT16_VALUE(   -87.81), SIMDE_FLOAT16_VALUE(  -227.12), SIMDE_FLOAT16_VALUE(  -211.12), SIMDE_FLOAT16_VALUE(   293.00),
        SIMDE_FLOAT16_VALUE(    11.07), SIMDE_FLOAT16_VALUE(    85.94), SIMDE_FLOAT16_VALUE(    21.05), SIMDE_FLOAT16_VALUE(  -162.50) },
      { SIMDE_FLOAT16_VALUE(   265.75), SIMDE_FLOAT16_VALUE(  -163.25), SIMDE_FLOAT16_VALUE(    51.03), SIMDE_FLOAT16_VALUE(  -191.38) },
       INT32_C(           1),
      { SIMDE_FLOAT16_VALUE( 43648.00), SIMDE_FLOAT16_VALUE( 11344.00), SIMDE_FLOAT16_VALUE(-56096.00), SIMDE_FLOAT16_VALUE(-14976.00),
        SIMDE_FLOAT16_VALUE(-16560.00), SIMDE_FLOAT16_VALUE( -4412.00), SIMDE_FLOAT16_VALUE( 31344.00), SIMDE_FLOAT16_VALUE(  8120.00) } }
    
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x8_t r_ = simde_vld1q_f16(test_vec[i].r_);
    simde_float16x8_t a = simde_vld1q_f16(test_vec[i].a);
    simde_float16x4_t b = simde_vld1_f16(test_vec[i].b);
    simde_float16x8_t r;
    switch(i & 1) {
      case 0:
        r = simde_vcmlaq_rot270_lane_f16(r_, a, b, 0);
        break;
      case 1:
        r = simde_vcmlaq_rot270_lane_f16(r_, a, b, 1);
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
    simde_float16x8_t r_ = simde_test_arm_neon_random_f16x8(-300.0f, 300.0f);
    simde_float16x8_t a = simde_test_arm_neon_random_f16x8(-300.0f, 300.0f);
    simde_float16x4_t b = simde_test_arm_neon_random_f16x4(-300.0f, 300.0f);
    simde_float16x8_t r;
    if(i % 2)
      r = simde_vcmlaq_rot270_lane_f16(r_, a, b, 1);
    else
      r = simde_vcmlaq_rot270_lane_f16(r_, a, b, 0);


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
test_simde_vcmlaq_rot270_lane_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32_t r_[4];
    simde_float32_t a[4];
    simde_float32_t b[2];
    const int lane;
    simde_float32_t r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   -35.36), SIMDE_FLOAT32_C(   242.11), SIMDE_FLOAT32_C(  -126.89), SIMDE_FLOAT32_C(  -160.81) },
      { SIMDE_FLOAT32_C(   229.86), SIMDE_FLOAT32_C(   -82.27), SIMDE_FLOAT32_C(   273.84), SIMDE_FLOAT32_C(  -189.30) },
      { SIMDE_FLOAT32_C(   277.22), SIMDE_FLOAT32_C(   225.57) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C(-18593.00), SIMDE_FLOAT32_C( 23049.00), SIMDE_FLOAT32_C(-42827.29), SIMDE_FLOAT32_C( 52316.94) } },
    { { SIMDE_FLOAT32_C(  -251.54), SIMDE_FLOAT32_C(  -111.04), SIMDE_FLOAT32_C(   271.08), SIMDE_FLOAT32_C(   283.39) },
      { SIMDE_FLOAT32_C(   204.08), SIMDE_FLOAT32_C(  -295.76), SIMDE_FLOAT32_C(   120.00), SIMDE_FLOAT32_C(   229.79) },
      { SIMDE_FLOAT32_C(   -90.00), SIMDE_FLOAT32_C(    -6.25) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C(  1596.96), SIMDE_FLOAT32_C(-26729.44), SIMDE_FLOAT32_C( -1165.11), SIMDE_FLOAT32_C( 20964.49) } },
    { { SIMDE_FLOAT32_C(    24.29), SIMDE_FLOAT32_C(   190.38), SIMDE_FLOAT32_C(   -57.23), SIMDE_FLOAT32_C(    17.83) },
      { SIMDE_FLOAT32_C(   189.60), SIMDE_FLOAT32_C(   -73.47), SIMDE_FLOAT32_C(   -77.33), SIMDE_FLOAT32_C(  -117.10) },
      { SIMDE_FLOAT32_C(   -95.55), SIMDE_FLOAT32_C(   278.66) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C(-20448.86), SIMDE_FLOAT32_C( -6829.68), SIMDE_FLOAT32_C(-32688.32), SIMDE_FLOAT32_C(-11171.08) } },
    { { SIMDE_FLOAT32_C(  -153.79), SIMDE_FLOAT32_C(   107.85), SIMDE_FLOAT32_C(    50.85), SIMDE_FLOAT32_C(   233.01) },
      { SIMDE_FLOAT32_C(    38.95), SIMDE_FLOAT32_C(    -4.37), SIMDE_FLOAT32_C(  -245.00), SIMDE_FLOAT32_C(    16.34) },
      { SIMDE_FLOAT32_C(  -105.12), SIMDE_FLOAT32_C(   254.21) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C( -1264.69), SIMDE_FLOAT32_C(  -351.52), SIMDE_FLOAT32_C(  4204.64), SIMDE_FLOAT32_C(  1950.67) } },
    { { SIMDE_FLOAT32_C(  -165.54), SIMDE_FLOAT32_C(    10.68), SIMDE_FLOAT32_C(    65.72), SIMDE_FLOAT32_C(   -73.49) },
      { SIMDE_FLOAT32_C(  -272.66), SIMDE_FLOAT32_C(   215.40), SIMDE_FLOAT32_C(  -190.94), SIMDE_FLOAT32_C(   272.13) },
      { SIMDE_FLOAT32_C(  -145.39), SIMDE_FLOAT32_C(   212.06) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C( 45512.18), SIMDE_FLOAT32_C( 31327.69), SIMDE_FLOAT32_C( 57773.61), SIMDE_FLOAT32_C( 39491.49) } },
    { { SIMDE_FLOAT32_C(   130.14), SIMDE_FLOAT32_C(   198.95), SIMDE_FLOAT32_C(    30.97), SIMDE_FLOAT32_C(  -295.79) },
      { SIMDE_FLOAT32_C(   263.55), SIMDE_FLOAT32_C(   230.30), SIMDE_FLOAT32_C(    -5.84), SIMDE_FLOAT32_C(   217.30) },
      { SIMDE_FLOAT32_C(   -39.64), SIMDE_FLOAT32_C(  -234.87) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C(-53960.42), SIMDE_FLOAT32_C(  9328.04), SIMDE_FLOAT32_C(-51006.28), SIMDE_FLOAT32_C(  8317.98) } },
    { { SIMDE_FLOAT32_C(   -12.15), SIMDE_FLOAT32_C(  -201.74), SIMDE_FLOAT32_C(    -7.10), SIMDE_FLOAT32_C(    -6.43) },
      { SIMDE_FLOAT32_C(   -38.90), SIMDE_FLOAT32_C(   273.48), SIMDE_FLOAT32_C(  -188.85), SIMDE_FLOAT32_C(   -49.80) },
      { SIMDE_FLOAT32_C(    35.35), SIMDE_FLOAT32_C(   121.30) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C( 33160.98), SIMDE_FLOAT32_C( -9869.26), SIMDE_FLOAT32_C( -6047.84), SIMDE_FLOAT32_C(  1754.00) } },
    { { SIMDE_FLOAT32_C(  -191.99), SIMDE_FLOAT32_C(    56.32), SIMDE_FLOAT32_C(  -282.00), SIMDE_FLOAT32_C(  -204.08) },
      { SIMDE_FLOAT32_C(   171.00), SIMDE_FLOAT32_C(   -16.50), SIMDE_FLOAT32_C(   -36.48), SIMDE_FLOAT32_C(   164.79) },
      { SIMDE_FLOAT32_C(   -49.39), SIMDE_FLOAT32_C(   259.74) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C( -4477.70), SIMDE_FLOAT32_C(  -758.61), SIMDE_FLOAT32_C( 42520.55), SIMDE_FLOAT32_C(  7934.90) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t r_ = simde_vld1q_f32(test_vec[i].r_);
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_float32x2_t b = simde_vld1_f32(test_vec[i].b);
    simde_float32x4_t r = simde_vcmlaq_rot270_lane_f32(r_, a, b, 0);
    simde_test_arm_neon_assert_equal_f32x4(r, simde_vld1q_f32(test_vec[i].r), 1);
  }
  return 0;
#else
  fputc('\n', stdout);
  const int lanes[] = { 0, 0, 0, 0, 0, 0, 0, 0 };
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x4_t r_ = simde_test_arm_neon_random_f32x4(-300.0f, 300.0f);
    simde_float32x4_t a = simde_test_arm_neon_random_f32x4(-300.0f, 300.0f);
    simde_float32x2_t b = simde_test_arm_neon_random_f32x2(-300.0f, 300.0f);
    simde_float32x4_t r = simde_vcmlaq_rot270_lane_f32(r_, a, b, 0);


    simde_test_arm_neon_write_f32x4(2, r_, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lanes[i], SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcmlaq_rot270_laneq_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16_t r_[8];
    simde_float16_t a[8];
    simde_float16_t b[8];
    const int lane;
    simde_float16_t r[8];
  } test_vec[] = {
    { { SIMDE_FLOAT16_VALUE(    30.69), SIMDE_FLOAT16_VALUE(   197.00), SIMDE_FLOAT16_VALUE(   -36.59), SIMDE_FLOAT16_VALUE(   147.12),
        SIMDE_FLOAT16_VALUE(    27.20), SIMDE_FLOAT16_VALUE(    87.75), SIMDE_FLOAT16_VALUE(   -38.66), SIMDE_FLOAT16_VALUE(   -11.09) },
      { SIMDE_FLOAT16_VALUE(    65.25), SIMDE_FLOAT16_VALUE(   -62.66), SIMDE_FLOAT16_VALUE(   -99.56), SIMDE_FLOAT16_VALUE(    51.12),
        SIMDE_FLOAT16_VALUE(   -21.22), SIMDE_FLOAT16_VALUE(   177.25), SIMDE_FLOAT16_VALUE(    -5.21), SIMDE_FLOAT16_VALUE(   -27.23) },
      { SIMDE_FLOAT16_VALUE(  -127.62), SIMDE_FLOAT16_VALUE(  -132.12), SIMDE_FLOAT16_VALUE(   -48.38), SIMDE_FLOAT16_VALUE(    95.00),
        SIMDE_FLOAT16_VALUE(   -92.00), SIMDE_FLOAT16_VALUE(  -183.25), SIMDE_FLOAT16_VALUE(   102.75), SIMDE_FLOAT16_VALUE(   136.25) },
       INT32_C(           0),
      { SIMDE_FLOAT16_VALUE(  8312.00), SIMDE_FLOAT16_VALUE( -7800.00), SIMDE_FLOAT16_VALUE( -6792.00), SIMDE_FLOAT16_VALUE(  6672.00),
        SIMDE_FLOAT16_VALUE(-23392.00), SIMDE_FLOAT16_VALUE( 22704.00), SIMDE_FLOAT16_VALUE(  3560.00), SIMDE_FLOAT16_VALUE( -3486.00) } },
    { { SIMDE_FLOAT16_VALUE(    73.75), SIMDE_FLOAT16_VALUE(   -65.31), SIMDE_FLOAT16_VALUE(    49.25), SIMDE_FLOAT16_VALUE(   -12.29),
        SIMDE_FLOAT16_VALUE(  -103.31), SIMDE_FLOAT16_VALUE(    46.84), SIMDE_FLOAT16_VALUE(   176.12), SIMDE_FLOAT16_VALUE(   -72.69) },
      { SIMDE_FLOAT16_VALUE(   -44.47), SIMDE_FLOAT16_VALUE(     3.78), SIMDE_FLOAT16_VALUE(   -56.47), SIMDE_FLOAT16_VALUE(   111.19),
        SIMDE_FLOAT16_VALUE(   -52.34), SIMDE_FLOAT16_VALUE(   -20.45), SIMDE_FLOAT16_VALUE(    84.31), SIMDE_FLOAT16_VALUE(    73.12) },
      { SIMDE_FLOAT16_VALUE(    81.50), SIMDE_FLOAT16_VALUE(  -167.38), SIMDE_FLOAT16_VALUE(   183.62), SIMDE_FLOAT16_VALUE(  -109.44),
        SIMDE_FLOAT16_VALUE(  -162.88), SIMDE_FLOAT16_VALUE(    96.50), SIMDE_FLOAT16_VALUE(   103.81), SIMDE_FLOAT16_VALUE(  -165.38) },
       INT32_C(           1),
      { SIMDE_FLOAT16_VALUE(  -339.75), SIMDE_FLOAT16_VALUE(  -759.50), SIMDE_FLOAT16_VALUE(-12120.00), SIMDE_FLOAT16_VALUE(-20432.00),
        SIMDE_FLOAT16_VALUE(  2136.00), SIMDE_FLOAT16_VALUE(  3802.00), SIMDE_FLOAT16_VALUE( -7828.00), SIMDE_FLOAT16_VALUE(-13504.00) } },
    { { SIMDE_FLOAT16_VALUE(  -127.44), SIMDE_FLOAT16_VALUE(    68.25), SIMDE_FLOAT16_VALUE(    25.16), SIMDE_FLOAT16_VALUE(    -8.30),
        SIMDE_FLOAT16_VALUE(   124.81), SIMDE_FLOAT16_VALUE(   100.88), SIMDE_FLOAT16_VALUE(  -127.12), SIMDE_FLOAT16_VALUE(  -100.88) },
      { SIMDE_FLOAT16_VALUE(   139.50), SIMDE_FLOAT16_VALUE(  -104.25), SIMDE_FLOAT16_VALUE(  -152.38), SIMDE_FLOAT16_VALUE(   105.38),
        SIMDE_FLOAT16_VALUE(  -103.06), SIMDE_FLOAT16_VALUE(   104.88), SIMDE_FLOAT16_VALUE(   -10.63), SIMDE_FLOAT16_VALUE(   164.62) },
      { SIMDE_FLOAT16_VALUE(    35.50), SIMDE_FLOAT16_VALUE(  -136.00), SIMDE_FLOAT16_VALUE(   -24.38), SIMDE_FLOAT16_VALUE(  -104.31),
        SIMDE_FLOAT16_VALUE(  -130.88), SIMDE_FLOAT16_VALUE(     8.60), SIMDE_FLOAT16_VALUE(  -183.88), SIMDE_FLOAT16_VALUE(    -0.42) },
       INT32_C(           2),
      { SIMDE_FLOAT16_VALUE( -1024.00), SIMDE_FLOAT16_VALUE(-13576.00), SIMDE_FLOAT16_VALUE(   931.50), SIMDE_FLOAT16_VALUE( 13784.00),
        SIMDE_FLOAT16_VALUE(  1027.00), SIMDE_FLOAT16_VALUE( 13824.00), SIMDE_FLOAT16_VALUE(  1289.00), SIMDE_FLOAT16_VALUE( 21440.00) } },
    { { SIMDE_FLOAT16_VALUE(   115.25), SIMDE_FLOAT16_VALUE(    64.19), SIMDE_FLOAT16_VALUE(   193.75), SIMDE_FLOAT16_VALUE(  -186.75),
        SIMDE_FLOAT16_VALUE(   118.75), SIMDE_FLOAT16_VALUE(  -194.88), SIMDE_FLOAT16_VALUE(   -21.34), SIMDE_FLOAT16_VALUE(   182.62) },
      { SIMDE_FLOAT16_VALUE(     0.88), SIMDE_FLOAT16_VALUE(   -62.44), SIMDE_FLOAT16_VALUE(   -37.12), SIMDE_FLOAT16_VALUE(    42.78),
        SIMDE_FLOAT16_VALUE(   -38.94), SIMDE_FLOAT16_VALUE(   177.25), SIMDE_FLOAT16_VALUE(    42.94), SIMDE_FLOAT16_VALUE(   -73.31) },
      { SIMDE_FLOAT16_VALUE(  -197.25), SIMDE_FLOAT16_VALUE(   101.62), SIMDE_FLOAT16_VALUE(   199.75), SIMDE_FLOAT16_VALUE(    -0.25),
        SIMDE_FLOAT16_VALUE(  -186.00), SIMDE_FLOAT16_VALUE(   156.62), SIMDE_FLOAT16_VALUE(   172.75), SIMDE_FLOAT16_VALUE(   198.00) },
       INT32_C(           3),
      { SIMDE_FLOAT16_VALUE(-12248.00), SIMDE_FLOAT16_VALUE( 10848.00), SIMDE_FLOAT16_VALUE(  8664.00), SIMDE_FLOAT16_VALUE( -7576.00),
        SIMDE_FLOAT16_VALUE( 35200.00), SIMDE_FLOAT16_VALUE(-30816.00), SIMDE_FLOAT16_VALUE(-14536.00), SIMDE_FLOAT16_VALUE( 12848.00) } },
    { { SIMDE_FLOAT16_VALUE(   130.25), SIMDE_FLOAT16_VALUE(   -79.69), SIMDE_FLOAT16_VALUE(   194.25), SIMDE_FLOAT16_VALUE(    52.50),
        SIMDE_FLOAT16_VALUE(   158.25), SIMDE_FLOAT16_VALUE(   127.50), SIMDE_FLOAT16_VALUE(    81.75), SIMDE_FLOAT16_VALUE(     8.75) },
      { SIMDE_FLOAT16_VALUE(   -85.50), SIMDE_FLOAT16_VALUE(    71.06), SIMDE_FLOAT16_VALUE(   170.88), SIMDE_FLOAT16_VALUE(   -22.62),
        SIMDE_FLOAT16_VALUE(    95.44), SIMDE_FLOAT16_VALUE(   128.12), SIMDE_FLOAT16_VALUE(   -91.81), SIMDE_FLOAT16_VALUE(   -12.95) },
      { SIMDE_FLOAT16_VALUE(   -33.75), SIMDE_FLOAT16_VALUE(   161.50), SIMDE_FLOAT16_VALUE(    21.45), SIMDE_FLOAT16_VALUE(   -82.69),
        SIMDE_FLOAT16_VALUE(   -23.09), SIMDE_FLOAT16_VALUE(   -96.00), SIMDE_FLOAT16_VALUE(  -180.62), SIMDE_FLOAT16_VALUE(  -196.38) },
       INT32_C(           0),
      { SIMDE_FLOAT16_VALUE( 11608.00), SIMDE_FLOAT16_VALUE(  2318.00), SIMDE_FLOAT16_VALUE( -3460.00), SIMDE_FLOAT16_VALUE(  -711.00),
        SIMDE_FLOAT16_VALUE( 20848.00), SIMDE_FLOAT16_VALUE(  4452.00), SIMDE_FLOAT16_VALUE( -2010.00), SIMDE_FLOAT16_VALUE(  -428.50) } },
    { { SIMDE_FLOAT16_VALUE(   102.38), SIMDE_FLOAT16_VALUE(   175.50), SIMDE_FLOAT16_VALUE(  -166.25), SIMDE_FLOAT16_VALUE(   174.75),
        SIMDE_FLOAT16_VALUE(   -90.56), SIMDE_FLOAT16_VALUE(  -193.25), SIMDE_FLOAT16_VALUE(   -70.62), SIMDE_FLOAT16_VALUE(   188.38) },
      { SIMDE_FLOAT16_VALUE(    90.75), SIMDE_FLOAT16_VALUE(   -79.19), SIMDE_FLOAT16_VALUE(   -32.72), SIMDE_FLOAT16_VALUE(     8.70),
        SIMDE_FLOAT16_VALUE(   139.38), SIMDE_FLOAT16_VALUE(    -0.72), SIMDE_FLOAT16_VALUE(   -20.88), SIMDE_FLOAT16_VALUE(   -60.62) },
      { SIMDE_FLOAT16_VALUE(  -118.81), SIMDE_FLOAT16_VALUE(  -160.38), SIMDE_FLOAT16_VALUE(    12.43), SIMDE_FLOAT16_VALUE(    44.97),
        SIMDE_FLOAT16_VALUE(  -161.88), SIMDE_FLOAT16_VALUE(  -139.12), SIMDE_FLOAT16_VALUE(  -189.75), SIMDE_FLOAT16_VALUE(   -53.94) },
       INT32_C(           1),
      { SIMDE_FLOAT16_VALUE( -3458.00), SIMDE_FLOAT16_VALUE(  1160.00), SIMDE_FLOAT16_VALUE(   225.12), SIMDE_FLOAT16_VALUE(    66.56),
        SIMDE_FLOAT16_VALUE(  -122.94), SIMDE_FLOAT16_VALUE(  -184.25), SIMDE_FLOAT16_VALUE( -2796.00), SIMDE_FLOAT16_VALUE(   942.00) } },
    { { SIMDE_FLOAT16_VALUE(   -51.81), SIMDE_FLOAT16_VALUE(    12.64), SIMDE_FLOAT16_VALUE(    -0.92), SIMDE_FLOAT16_VALUE(   125.88),
        SIMDE_FLOAT16_VALUE(  -152.38), SIMDE_FLOAT16_VALUE(  -175.38), SIMDE_FLOAT16_VALUE(    -9.19), SIMDE_FLOAT16_VALUE(     6.30) },
      { SIMDE_FLOAT16_VALUE(  -105.06), SIMDE_FLOAT16_VALUE(   172.75), SIMDE_FLOAT16_VALUE(   -62.03), SIMDE_FLOAT16_VALUE(  -188.38),
        SIMDE_FLOAT16_VALUE(    34.69), SIMDE_FLOAT16_VALUE(   -54.06), SIMDE_FLOAT16_VALUE(    56.88), SIMDE_FLOAT16_VALUE(   168.00) },
      { SIMDE_FLOAT16_VALUE(   149.12), SIMDE_FLOAT16_VALUE(   -22.12), SIMDE_FLOAT16_VALUE(   -98.56), SIMDE_FLOAT16_VALUE(   -68.06),
        SIMDE_FLOAT16_VALUE(   107.88), SIMDE_FLOAT16_VALUE(    27.06), SIMDE_FLOAT16_VALUE(   -68.31), SIMDE_FLOAT16_VALUE(  -101.50) },
       INT32_C(           2),
      { SIMDE_FLOAT16_VALUE(  4624.00), SIMDE_FLOAT16_VALUE(-18624.00), SIMDE_FLOAT16_VALUE( -5100.00), SIMDE_FLOAT16_VALUE( 20448.00),
        SIMDE_FLOAT16_VALUE( -1615.00), SIMDE_FLOAT16_VALUE(  5656.00), SIMDE_FLOAT16_VALUE(  4536.00), SIMDE_FLOAT16_VALUE(-18112.00) } },
    { { SIMDE_FLOAT16_VALUE(  -184.62), SIMDE_FLOAT16_VALUE(   150.25), SIMDE_FLOAT16_VALUE(   101.81), SIMDE_FLOAT16_VALUE(    -6.41),
        SIMDE_FLOAT16_VALUE(  -113.56), SIMDE_FLOAT16_VALUE(   149.25), SIMDE_FLOAT16_VALUE(   160.00), SIMDE_FLOAT16_VALUE(  -192.38) },
      { SIMDE_FLOAT16_VALUE(  -118.31), SIMDE_FLOAT16_VALUE(   -29.31), SIMDE_FLOAT16_VALUE(  -157.88), SIMDE_FLOAT16_VALUE(    52.44),
        SIMDE_FLOAT16_VALUE(   160.25), SIMDE_FLOAT16_VALUE(   155.50), SIMDE_FLOAT16_VALUE(   181.00), SIMDE_FLOAT16_VALUE(   -91.00) },
      { SIMDE_FLOAT16_VALUE(  -128.25), SIMDE_FLOAT16_VALUE(    93.12), SIMDE_FLOAT16_VALUE(    52.34), SIMDE_FLOAT16_VALUE(   -96.81),
        SIMDE_FLOAT16_VALUE(     7.65), SIMDE_FLOAT16_VALUE(  -168.50), SIMDE_FLOAT16_VALUE(    63.53), SIMDE_FLOAT16_VALUE(   -44.12) },
       INT32_C(           3),
      { SIMDE_FLOAT16_VALUE(  1109.00), SIMDE_FLOAT16_VALUE(  2013.00), SIMDE_FLOAT16_VALUE( -2212.00), SIMDE_FLOAT16_VALUE( -3338.00),
        SIMDE_FLOAT16_VALUE( -6976.00), SIMDE_FLOAT16_VALUE( -9728.00), SIMDE_FLOAT16_VALUE(  4176.00), SIMDE_FLOAT16_VALUE(  5588.00) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x8_t r_ = simde_vld1q_f16(test_vec[i].r_);
    simde_float16x8_t a = simde_vld1q_f16(test_vec[i].a);
    simde_float16x8_t b = simde_vld1q_f16(test_vec[i].b);
    
    simde_float16x8_t r; 
    switch(i & 3) {
      case 0:
        r = simde_vcmlaq_rot270_laneq_f16(r_, a, b, 0);
        break;
      case 1:
        r = simde_vcmlaq_rot270_laneq_f16(r_, a, b, 1);
        break;
      case 2:
        r = simde_vcmlaq_rot270_laneq_f16(r_, a, b, 2);
        break;
      case 3:
        r = simde_vcmlaq_rot270_laneq_f16(r_, a, b, 3);
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
      r = simde_vcmlaq_rot270_laneq_f16(r_, a, b, 1);
    else if(i % 4 == 2)
      r = simde_vcmlaq_rot270_laneq_f16(r_, a, b, 2);
    else if(i % 4 == 3)
      r = simde_vcmlaq_rot270_laneq_f16(r_, a, b, 3);
    else
      r = simde_vcmlaq_rot270_laneq_f16(r_, a, b, 0);


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
test_simde_vcmlaq_rot270_laneq_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32_t r_[4];
    simde_float32_t a[4];
    simde_float32_t b[4];
    const int lane;
    simde_float32_t r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -173.75), SIMDE_FLOAT32_C(   -44.53), SIMDE_FLOAT32_C(  -164.22), SIMDE_FLOAT32_C(   -11.28) },
      { SIMDE_FLOAT32_C(     4.09), SIMDE_FLOAT32_C(  -193.51), SIMDE_FLOAT32_C(   283.07), SIMDE_FLOAT32_C(   156.21) },
      { SIMDE_FLOAT32_C(  -113.63), SIMDE_FLOAT32_C(   -42.09), SIMDE_FLOAT32_C(   -15.73), SIMDE_FLOAT32_C(   244.05) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C(  7971.09), SIMDE_FLOAT32_C(-22033.07), SIMDE_FLOAT32_C( -6739.10), SIMDE_FLOAT32_C( 17738.86) } },
    { { SIMDE_FLOAT32_C(   162.37), SIMDE_FLOAT32_C(   109.16), SIMDE_FLOAT32_C(  -157.70), SIMDE_FLOAT32_C(  -299.94) },
      { SIMDE_FLOAT32_C(    79.07), SIMDE_FLOAT32_C(    -1.63), SIMDE_FLOAT32_C(   272.44), SIMDE_FLOAT32_C(  -243.69) },
      { SIMDE_FLOAT32_C(   -38.26), SIMDE_FLOAT32_C(   162.83), SIMDE_FLOAT32_C(   153.26), SIMDE_FLOAT32_C(    68.76) },
       INT32_C(           1),
      { SIMDE_FLOAT32_C(    50.29), SIMDE_FLOAT32_C(   358.97), SIMDE_FLOAT32_C(-16913.82), SIMDE_FLOAT32_C( 37047.99) } },
    { { SIMDE_FLOAT32_C(    72.79), SIMDE_FLOAT32_C(    20.47), SIMDE_FLOAT32_C(   179.79), SIMDE_FLOAT32_C(   176.50) },
      { SIMDE_FLOAT32_C(   -33.78), SIMDE_FLOAT32_C(  -149.72), SIMDE_FLOAT32_C(   118.47), SIMDE_FLOAT32_C(   276.37) },
      { SIMDE_FLOAT32_C(   285.26), SIMDE_FLOAT32_C(  -261.52), SIMDE_FLOAT32_C(   167.86), SIMDE_FLOAT32_C(    23.81) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C( 39227.56), SIMDE_FLOAT32_C( 42729.60), SIMDE_FLOAT32_C(-72096.48), SIMDE_FLOAT32_C(-78660.80) } },
    { { SIMDE_FLOAT32_C(   -55.09), SIMDE_FLOAT32_C(   -45.75), SIMDE_FLOAT32_C(  -275.36), SIMDE_FLOAT32_C(  -252.77) },
      { SIMDE_FLOAT32_C(   270.30), SIMDE_FLOAT32_C(  -226.08), SIMDE_FLOAT32_C(    52.65), SIMDE_FLOAT32_C(   -30.17) },
      { SIMDE_FLOAT32_C(   -30.06), SIMDE_FLOAT32_C(    22.65), SIMDE_FLOAT32_C(   289.70), SIMDE_FLOAT32_C(    17.45) },
       INT32_C(           1),
      { SIMDE_FLOAT32_C( -4000.19), SIMDE_FLOAT32_C( 65449.63), SIMDE_FLOAT32_C(  -801.83), SIMDE_FLOAT32_C(  8487.48) } },
    { { SIMDE_FLOAT32_C(  -187.96), SIMDE_FLOAT32_C(  -117.81), SIMDE_FLOAT32_C(   -97.89), SIMDE_FLOAT32_C(     4.75) },
      { SIMDE_FLOAT32_C(     5.26), SIMDE_FLOAT32_C(   197.95), SIMDE_FLOAT32_C(  -117.69), SIMDE_FLOAT32_C(   148.50) },
      { SIMDE_FLOAT32_C(   -83.63), SIMDE_FLOAT32_C(   151.28), SIMDE_FLOAT32_C(   282.54), SIMDE_FLOAT32_C(   262.94) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C( 29757.92), SIMDE_FLOAT32_C( 16436.75), SIMDE_FLOAT32_C( 22367.19), SIMDE_FLOAT32_C( 12423.80) } },
    { { SIMDE_FLOAT32_C(   282.79), SIMDE_FLOAT32_C(   260.35), SIMDE_FLOAT32_C(  -175.75), SIMDE_FLOAT32_C(    30.96) },
      { SIMDE_FLOAT32_C(   153.22), SIMDE_FLOAT32_C(   -95.00), SIMDE_FLOAT32_C(   -63.18), SIMDE_FLOAT32_C(    57.16) },
      { SIMDE_FLOAT32_C(   138.99), SIMDE_FLOAT32_C(   180.78), SIMDE_FLOAT32_C(   -66.65), SIMDE_FLOAT32_C(    50.87) },
       INT32_C(           1),
      { SIMDE_FLOAT32_C( -4549.86), SIMDE_FLOAT32_C( -6071.40), SIMDE_FLOAT32_C(  2731.98), SIMDE_FLOAT32_C(  3840.67) } },
    { { SIMDE_FLOAT32_C(   -67.30), SIMDE_FLOAT32_C(   -37.15), SIMDE_FLOAT32_C(   287.99), SIMDE_FLOAT32_C(    61.04) },
      { SIMDE_FLOAT32_C(  -140.94), SIMDE_FLOAT32_C(    11.42), SIMDE_FLOAT32_C(   -85.12), SIMDE_FLOAT32_C(  -270.48) },
      { SIMDE_FLOAT32_C(   236.23), SIMDE_FLOAT32_C(    86.91), SIMDE_FLOAT32_C(   218.17), SIMDE_FLOAT32_C(   130.71) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C(   925.21), SIMDE_FLOAT32_C( -2734.90), SIMDE_FLOAT32_C(-23219.43), SIMDE_FLOAT32_C( 63956.53) } },
    { { SIMDE_FLOAT32_C(   239.01), SIMDE_FLOAT32_C(    65.06), SIMDE_FLOAT32_C(   257.13), SIMDE_FLOAT32_C(  -147.77) },
      { SIMDE_FLOAT32_C(  -133.03), SIMDE_FLOAT32_C(  -286.30), SIMDE_FLOAT32_C(   181.10), SIMDE_FLOAT32_C(    -5.97) },
      { SIMDE_FLOAT32_C(   -72.36), SIMDE_FLOAT32_C(   -23.69), SIMDE_FLOAT32_C(   277.29), SIMDE_FLOAT32_C(   226.68) },
       INT32_C(           1),
      { SIMDE_FLOAT32_C(-64659.47), SIMDE_FLOAT32_C( 79453.19), SIMDE_FLOAT32_C( -1096.15), SIMDE_FLOAT32_C(  1507.65) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t r_ = simde_vld1q_f32(test_vec[i].r_);
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_float32x4_t b = simde_vld1q_f32(test_vec[i].b);
    simde_float32x4_t r;
    switch(i & 1) {
      case 0:
        r = simde_vcmlaq_rot270_laneq_f32(r_, a, b, 0);
        break;
      case 1:
        r = simde_vcmlaq_rot270_laneq_f32(r_, a, b, 1);
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
    simde_float32x4_t r_ = simde_test_arm_neon_random_f32x4(-300.0f, 300.0f);
    simde_float32x4_t a = simde_test_arm_neon_random_f32x4(-300.0f, 300.0f);
    simde_float32x4_t b = simde_test_arm_neon_random_f32x4(-300.0f, 300.0f);
    simde_float32x4_t r;
    if(i % 2 == 1)
      r = simde_vcmlaq_rot270_laneq_f32(r_, a, b, 1);
    else
      r = simde_vcmlaq_rot270_laneq_f32(r_, a, b, 0);


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
SIMDE_TEST_FUNC_LIST_ENTRY(vcmla_rot270_lane_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcmla_rot270_lane_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcmla_rot270_laneq_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcmla_rot270_laneq_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcmlaq_rot270_lane_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcmlaq_rot270_lane_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcmlaq_rot270_laneq_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcmlaq_rot270_laneq_f32)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
