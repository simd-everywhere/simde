#define SIMDE_TEST_ARM_NEON_INSN cmla_lane

#include "test-neon.h"
#include "../../../simde/arm/neon/cmla_lane.h"
#include "../../../simde/arm/neon/dup_n.h"

static int
test_simde_vcmla_lane_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16_t r_[4];
    simde_float16_t a[4];
    simde_float16_t b[4];
    const int lane;
    simde_float16_t r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT16_VALUE(   -83.31), SIMDE_FLOAT16_VALUE(  -136.25), SIMDE_FLOAT16_VALUE(  -164.62), SIMDE_FLOAT16_VALUE(  -116.62) },
      { SIMDE_FLOAT16_VALUE(   131.00), SIMDE_FLOAT16_VALUE(    33.06), SIMDE_FLOAT16_VALUE(    37.81), SIMDE_FLOAT16_VALUE(   -55.62) },
      { SIMDE_FLOAT16_VALUE(   -14.03), SIMDE_FLOAT16_VALUE(  -167.75), SIMDE_FLOAT16_VALUE(   118.06), SIMDE_FLOAT16_VALUE(   -71.50) },
       INT32_C(           0),
      { SIMDE_FLOAT16_VALUE( -1921.00), SIMDE_FLOAT16_VALUE(-22112.00), SIMDE_FLOAT16_VALUE(  -695.00), SIMDE_FLOAT16_VALUE( -6460.00) } },
    { { SIMDE_FLOAT16_VALUE(   -47.50), SIMDE_FLOAT16_VALUE(   144.12), SIMDE_FLOAT16_VALUE(   -36.75), SIMDE_FLOAT16_VALUE(    88.75) },
      { SIMDE_FLOAT16_VALUE(   -96.62), SIMDE_FLOAT16_VALUE(   -33.66), SIMDE_FLOAT16_VALUE(  -183.50), SIMDE_FLOAT16_VALUE(    75.38) },
      { SIMDE_FLOAT16_VALUE(  -118.50), SIMDE_FLOAT16_VALUE(    70.69), SIMDE_FLOAT16_VALUE(    31.02), SIMDE_FLOAT16_VALUE(   181.25) },
       INT32_C(           1),
      { SIMDE_FLOAT16_VALUE( -3044.00), SIMDE_FLOAT16_VALUE(-17376.00), SIMDE_FLOAT16_VALUE( -5728.00), SIMDE_FLOAT16_VALUE(-33184.00) } },
    { { SIMDE_FLOAT16_VALUE(   -14.92), SIMDE_FLOAT16_VALUE(    38.72), SIMDE_FLOAT16_VALUE(  -198.38), SIMDE_FLOAT16_VALUE(    62.12) },
      { SIMDE_FLOAT16_VALUE(  -180.75), SIMDE_FLOAT16_VALUE(   -87.06), SIMDE_FLOAT16_VALUE(  -154.25), SIMDE_FLOAT16_VALUE(   135.12) },
      { SIMDE_FLOAT16_VALUE(   184.50), SIMDE_FLOAT16_VALUE(    26.23), SIMDE_FLOAT16_VALUE(  -113.56), SIMDE_FLOAT16_VALUE(   -88.06) },
       INT32_C(           0),
      { SIMDE_FLOAT16_VALUE(-33376.00), SIMDE_FLOAT16_VALUE( -4704.00), SIMDE_FLOAT16_VALUE(-28656.00), SIMDE_FLOAT16_VALUE( -3984.00) } },
    { { SIMDE_FLOAT16_VALUE(   176.50), SIMDE_FLOAT16_VALUE(   147.50), SIMDE_FLOAT16_VALUE(  -140.75), SIMDE_FLOAT16_VALUE(  -171.25) },
      { SIMDE_FLOAT16_VALUE(   -63.19), SIMDE_FLOAT16_VALUE(     3.22), SIMDE_FLOAT16_VALUE(   167.38), SIMDE_FLOAT16_VALUE(  -126.69) },
      { SIMDE_FLOAT16_VALUE(   -29.22), SIMDE_FLOAT16_VALUE(    65.81), SIMDE_FLOAT16_VALUE(   144.12), SIMDE_FLOAT16_VALUE(  -173.38) },
       INT32_C(           1),
      { SIMDE_FLOAT16_VALUE( -8928.00), SIMDE_FLOAT16_VALUE( 11104.00), SIMDE_FLOAT16_VALUE( 23984.00), SIMDE_FLOAT16_VALUE(-29184.00) } },
    { { SIMDE_FLOAT16_VALUE(   184.50), SIMDE_FLOAT16_VALUE(    82.25), SIMDE_FLOAT16_VALUE(    62.16), SIMDE_FLOAT16_VALUE(   176.75) },
      { SIMDE_FLOAT16_VALUE(  -154.75), SIMDE_FLOAT16_VALUE(   -66.75), SIMDE_FLOAT16_VALUE(  -138.25), SIMDE_FLOAT16_VALUE(  -176.00) },
      { SIMDE_FLOAT16_VALUE(  -128.50), SIMDE_FLOAT16_VALUE(   102.06), SIMDE_FLOAT16_VALUE(   182.38), SIMDE_FLOAT16_VALUE(  -174.00) },
       INT32_C(           0),
      { SIMDE_FLOAT16_VALUE( 20064.00), SIMDE_FLOAT16_VALUE(-15712.00), SIMDE_FLOAT16_VALUE( 17824.00), SIMDE_FLOAT16_VALUE(-13936.00) } },
    { { SIMDE_FLOAT16_VALUE(    73.75), SIMDE_FLOAT16_VALUE(  -102.88), SIMDE_FLOAT16_VALUE(   160.75), SIMDE_FLOAT16_VALUE(  -172.25) },
      { SIMDE_FLOAT16_VALUE(   -80.25), SIMDE_FLOAT16_VALUE(  -172.75), SIMDE_FLOAT16_VALUE(  -118.19), SIMDE_FLOAT16_VALUE(   -54.91) },
      { SIMDE_FLOAT16_VALUE(   -97.56), SIMDE_FLOAT16_VALUE(  -182.50), SIMDE_FLOAT16_VALUE(    71.88), SIMDE_FLOAT16_VALUE(    11.07) },
       INT32_C(           1),
      { SIMDE_FLOAT16_VALUE( -5696.00), SIMDE_FLOAT16_VALUE(  -991.50), SIMDE_FLOAT16_VALUE( -8336.00), SIMDE_FLOAT16_VALUE( -1481.00) } },
    { { SIMDE_FLOAT16_VALUE(    94.81), SIMDE_FLOAT16_VALUE(    92.81), SIMDE_FLOAT16_VALUE(   165.00), SIMDE_FLOAT16_VALUE(   153.88) },
      { SIMDE_FLOAT16_VALUE(   121.88), SIMDE_FLOAT16_VALUE(  -102.50), SIMDE_FLOAT16_VALUE(  -175.75), SIMDE_FLOAT16_VALUE(  -178.00) },
      { SIMDE_FLOAT16_VALUE(  -111.25), SIMDE_FLOAT16_VALUE(   160.62), SIMDE_FLOAT16_VALUE(   -37.91), SIMDE_FLOAT16_VALUE(    84.44) },
       INT32_C(           0),
      { SIMDE_FLOAT16_VALUE(-13464.00), SIMDE_FLOAT16_VALUE( 19664.00), SIMDE_FLOAT16_VALUE( 19712.00), SIMDE_FLOAT16_VALUE(-28080.00) } },
    { { SIMDE_FLOAT16_VALUE(   -49.25), SIMDE_FLOAT16_VALUE(   -45.59), SIMDE_FLOAT16_VALUE(   198.75), SIMDE_FLOAT16_VALUE(   -13.55) },
      { SIMDE_FLOAT16_VALUE(  -160.88), SIMDE_FLOAT16_VALUE(    72.81), SIMDE_FLOAT16_VALUE(   113.94), SIMDE_FLOAT16_VALUE(   123.38) },
      { SIMDE_FLOAT16_VALUE(  -179.75), SIMDE_FLOAT16_VALUE(   123.56), SIMDE_FLOAT16_VALUE(    -8.53), SIMDE_FLOAT16_VALUE(   183.62) },
       INT32_C(           1),
      { SIMDE_FLOAT16_VALUE(  1323.00), SIMDE_FLOAT16_VALUE(-29584.00), SIMDE_FLOAT16_VALUE(  -773.50), SIMDE_FLOAT16_VALUE( 20912.00) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x4_t r_ = simde_vld1_f16(test_vec[i].r_);
    simde_float16x4_t a = simde_vld1_f16(test_vec[i].a);
    simde_float16x4_t b = simde_vld1_f16(test_vec[i].b);
    simde_float16x4_t r;
    switch(i & 1) {
      case 0:
        r = simde_vcmla_lane_f16(r_, a, b, 0);
        break;
      case 1:
        r = simde_vcmla_lane_f16(r_, a, b, 1);
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
    simde_float16x4_t b = simde_test_arm_neon_random_f16x4(-200.0f, 200.0f);
    simde_float16x4_t r;
    if(i % 2)
      r = simde_vcmla_lane_f16(r_, a, b, 1);
    else
      r = simde_vcmla_lane_f16(r_, a, b, 0);


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
test_simde_vcmla_lane_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32_t r_[2];
    simde_float32_t a[2];
    simde_float32_t b[2];
    const int lane;
    simde_float32_t r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   854.83), SIMDE_FLOAT32_C(  -889.32) },
      { SIMDE_FLOAT32_C(  -828.95), SIMDE_FLOAT32_C(   -91.02) },
      { SIMDE_FLOAT32_C(   199.05), SIMDE_FLOAT32_C(  -576.94) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C(-164147.67), SIMDE_FLOAT32_C(477365.09) } },
    { { SIMDE_FLOAT32_C(  -650.24), SIMDE_FLOAT32_C(  -541.50) },
      { SIMDE_FLOAT32_C(  -970.37), SIMDE_FLOAT32_C(   962.03) },
      { SIMDE_FLOAT32_C(   774.43), SIMDE_FLOAT32_C(  -227.43) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C(-752133.88), SIMDE_FLOAT32_C(220149.73) } },
    { { SIMDE_FLOAT32_C(  -397.31), SIMDE_FLOAT32_C(   342.29) },
      { SIMDE_FLOAT32_C(   915.72), SIMDE_FLOAT32_C(   501.56) },
      { SIMDE_FLOAT32_C(  -255.70), SIMDE_FLOAT32_C(   466.89) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C(-234546.91), SIMDE_FLOAT32_C(427882.81) } },
    { { SIMDE_FLOAT32_C(  -949.99), SIMDE_FLOAT32_C(  -486.24) },
      { SIMDE_FLOAT32_C(  -299.36), SIMDE_FLOAT32_C(   671.30) },
      { SIMDE_FLOAT32_C(   534.83), SIMDE_FLOAT32_C(   935.21) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C(-161056.70), SIMDE_FLOAT32_C(-280450.69) } },
    { { SIMDE_FLOAT32_C(    25.38), SIMDE_FLOAT32_C(   545.08) },
      { SIMDE_FLOAT32_C(  -772.27), SIMDE_FLOAT32_C(   510.24) },
      { SIMDE_FLOAT32_C(  -362.99), SIMDE_FLOAT32_C(  -736.76) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C(280351.66), SIMDE_FLOAT32_C(569522.75) } },
    { { SIMDE_FLOAT32_C(  -663.63), SIMDE_FLOAT32_C(   428.06) },
      { SIMDE_FLOAT32_C(   474.74), SIMDE_FLOAT32_C(   962.54) },
      { SIMDE_FLOAT32_C(  -588.55), SIMDE_FLOAT32_C(   244.81) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C(-280071.84), SIMDE_FLOAT32_C(116649.16) } },
    { { SIMDE_FLOAT32_C(   524.15), SIMDE_FLOAT32_C(  -545.12) },
      { SIMDE_FLOAT32_C(   183.58), SIMDE_FLOAT32_C(  -519.59) },
      { SIMDE_FLOAT32_C(  -758.14), SIMDE_FLOAT32_C(    -8.87) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C(-138655.19), SIMDE_FLOAT32_C( -2173.47) } },
    { { SIMDE_FLOAT32_C(   977.56), SIMDE_FLOAT32_C(  -100.14) },
      { SIMDE_FLOAT32_C(   923.32), SIMDE_FLOAT32_C(   191.19) },
      { SIMDE_FLOAT32_C(  -728.50), SIMDE_FLOAT32_C(    24.94) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C(-671661.06), SIMDE_FLOAT32_C( 22927.46) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t r_ = simde_vld1_f32(test_vec[i].r_);
    simde_float32x2_t a = simde_vld1_f32(test_vec[i].a);
    simde_float32x2_t b = simde_vld1_f32(test_vec[i].b);
    simde_float32x2_t r = simde_vcmla_lane_f32(r_, a, b, 0);
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
    simde_float32x2_t r = simde_vcmla_lane_f32(r_, a, b, 0);


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
test_simde_vcmla_laneq_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16_t r_[4];
    simde_float16_t a[4];
    simde_float16_t b[8];
    const int lane;
    simde_float16_t r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT16_VALUE(  -235.00), SIMDE_FLOAT16_VALUE(  -274.75), SIMDE_FLOAT16_VALUE(    79.50), SIMDE_FLOAT16_VALUE(    22.38) },
      { SIMDE_FLOAT16_VALUE(  -155.75), SIMDE_FLOAT16_VALUE(  -294.00), SIMDE_FLOAT16_VALUE(   152.38), SIMDE_FLOAT16_VALUE(  -282.50) },
      { SIMDE_FLOAT16_VALUE(  -204.50), SIMDE_FLOAT16_VALUE(    20.81), SIMDE_FLOAT16_VALUE(    80.56), SIMDE_FLOAT16_VALUE(    91.56),
        SIMDE_FLOAT16_VALUE(  -258.50), SIMDE_FLOAT16_VALUE(  -197.00), SIMDE_FLOAT16_VALUE(   226.12), SIMDE_FLOAT16_VALUE(  -181.00) },
       INT32_C(           0),
      { SIMDE_FLOAT16_VALUE( 31616.00), SIMDE_FLOAT16_VALUE( -3516.00), SIMDE_FLOAT16_VALUE(-31088.00), SIMDE_FLOAT16_VALUE(  3194.00) } },
    { { SIMDE_FLOAT16_VALUE(  -268.75), SIMDE_FLOAT16_VALUE(   151.12), SIMDE_FLOAT16_VALUE(   255.75), SIMDE_FLOAT16_VALUE(   236.38) },
      { SIMDE_FLOAT16_VALUE(    50.84), SIMDE_FLOAT16_VALUE(   275.50), SIMDE_FLOAT16_VALUE(   162.62), SIMDE_FLOAT16_VALUE(  -147.25) },
      { SIMDE_FLOAT16_VALUE(    76.38), SIMDE_FLOAT16_VALUE(  -139.62), SIMDE_FLOAT16_VALUE(  -168.50), SIMDE_FLOAT16_VALUE(   275.75),
        SIMDE_FLOAT16_VALUE(  -286.25), SIMDE_FLOAT16_VALUE(  -164.38), SIMDE_FLOAT16_VALUE(  -187.00), SIMDE_FLOAT16_VALUE(   -76.62) },
       INT32_C(           1),
      { SIMDE_FLOAT16_VALUE( -8832.00), SIMDE_FLOAT16_VALUE( 14168.00), SIMDE_FLOAT16_VALUE(-27152.00), SIMDE_FLOAT16_VALUE( 45088.00) } },
    { { SIMDE_FLOAT16_VALUE(   228.12), SIMDE_FLOAT16_VALUE(  -251.25), SIMDE_FLOAT16_VALUE(  -139.88), SIMDE_FLOAT16_VALUE(  -238.75) },
      { SIMDE_FLOAT16_VALUE(  -166.38), SIMDE_FLOAT16_VALUE(   169.38), SIMDE_FLOAT16_VALUE(   -41.00), SIMDE_FLOAT16_VALUE(  -273.75) },
      { SIMDE_FLOAT16_VALUE(   225.00), SIMDE_FLOAT16_VALUE(   156.00), SIMDE_FLOAT16_VALUE(   -88.25), SIMDE_FLOAT16_VALUE(    93.75),
        SIMDE_FLOAT16_VALUE(    13.90), SIMDE_FLOAT16_VALUE(   149.75), SIMDE_FLOAT16_VALUE(  -119.44), SIMDE_FLOAT16_VALUE(   265.50) },
       INT32_C(           0),
      { SIMDE_FLOAT16_VALUE(-37216.00), SIMDE_FLOAT16_VALUE(-26208.00), SIMDE_FLOAT16_VALUE( -9368.00), SIMDE_FLOAT16_VALUE( -6636.00) } },
    { { SIMDE_FLOAT16_VALUE(   -78.06), SIMDE_FLOAT16_VALUE(   -27.62), SIMDE_FLOAT16_VALUE(   -17.89), SIMDE_FLOAT16_VALUE(   -87.19) },
      { SIMDE_FLOAT16_VALUE(   240.38), SIMDE_FLOAT16_VALUE(   138.12), SIMDE_FLOAT16_VALUE(  -285.75), SIMDE_FLOAT16_VALUE(   -75.25) },
      { SIMDE_FLOAT16_VALUE(  -271.25), SIMDE_FLOAT16_VALUE(   226.25), SIMDE_FLOAT16_VALUE(  -160.00), SIMDE_FLOAT16_VALUE(   -42.94),
        SIMDE_FLOAT16_VALUE(    22.20), SIMDE_FLOAT16_VALUE(   -93.56), SIMDE_FLOAT16_VALUE(   156.25), SIMDE_FLOAT16_VALUE(   231.00) },
       INT32_C(           1),
      { SIMDE_FLOAT16_VALUE(-38528.00), SIMDE_FLOAT16_VALUE(-10352.00), SIMDE_FLOAT16_VALUE( 45696.00), SIMDE_FLOAT16_VALUE( 12184.00) } },
    { { SIMDE_FLOAT16_VALUE(   197.75), SIMDE_FLOAT16_VALUE(   256.00), SIMDE_FLOAT16_VALUE(    96.62), SIMDE_FLOAT16_VALUE(  -289.75) },
      { SIMDE_FLOAT16_VALUE(  -202.75), SIMDE_FLOAT16_VALUE(     0.10), SIMDE_FLOAT16_VALUE(   -68.56), SIMDE_FLOAT16_VALUE(   123.12) },
      { SIMDE_FLOAT16_VALUE(   116.75), SIMDE_FLOAT16_VALUE(    24.34), SIMDE_FLOAT16_VALUE(  -100.06), SIMDE_FLOAT16_VALUE(    69.88),
        SIMDE_FLOAT16_VALUE(     1.55), SIMDE_FLOAT16_VALUE(  -268.00), SIMDE_FLOAT16_VALUE(   136.50), SIMDE_FLOAT16_VALUE(   102.44) },
       INT32_C(           0),
      { SIMDE_FLOAT16_VALUE(-23472.00), SIMDE_FLOAT16_VALUE( -4680.00), SIMDE_FLOAT16_VALUE( -7908.00), SIMDE_FLOAT16_VALUE( -1959.00) } },
    { { SIMDE_FLOAT16_VALUE(    67.06), SIMDE_FLOAT16_VALUE(  -274.75), SIMDE_FLOAT16_VALUE(  -131.00), SIMDE_FLOAT16_VALUE(    50.50) },
      { SIMDE_FLOAT16_VALUE(  -231.25), SIMDE_FLOAT16_VALUE(   263.25), SIMDE_FLOAT16_VALUE(   132.62), SIMDE_FLOAT16_VALUE(  -294.00) },
      { SIMDE_FLOAT16_VALUE(   146.50), SIMDE_FLOAT16_VALUE(   -77.62), SIMDE_FLOAT16_VALUE(   184.25), SIMDE_FLOAT16_VALUE(   -45.00),
        SIMDE_FLOAT16_VALUE(    70.88), SIMDE_FLOAT16_VALUE(  -161.25), SIMDE_FLOAT16_VALUE(   -21.83), SIMDE_FLOAT16_VALUE(  -270.00) },
       INT32_C(           1),
      { SIMDE_FLOAT16_VALUE(-42528.00), SIMDE_FLOAT16_VALUE( 10128.00), SIMDE_FLOAT16_VALUE( 24304.00), SIMDE_FLOAT16_VALUE( -5916.00) } },
    { { SIMDE_FLOAT16_VALUE(  -175.00), SIMDE_FLOAT16_VALUE(   265.50), SIMDE_FLOAT16_VALUE(  -207.12), SIMDE_FLOAT16_VALUE(    90.81) },
      { SIMDE_FLOAT16_VALUE(  -244.12), SIMDE_FLOAT16_VALUE(  -245.38), SIMDE_FLOAT16_VALUE(   209.38), SIMDE_FLOAT16_VALUE(   197.50) },
      { SIMDE_FLOAT16_VALUE(   -45.09), SIMDE_FLOAT16_VALUE(     0.55), SIMDE_FLOAT16_VALUE(   203.75), SIMDE_FLOAT16_VALUE(    46.94),
        SIMDE_FLOAT16_VALUE(  -141.38), SIMDE_FLOAT16_VALUE(   191.25), SIMDE_FLOAT16_VALUE(   173.75), SIMDE_FLOAT16_VALUE(   -82.19) },
       INT32_C(           0),
      { SIMDE_FLOAT16_VALUE( 10832.00), SIMDE_FLOAT16_VALUE(   131.25), SIMDE_FLOAT16_VALUE( -9648.00), SIMDE_FLOAT16_VALUE(   205.88) } },
    { { SIMDE_FLOAT16_VALUE(  -243.00), SIMDE_FLOAT16_VALUE(   152.12), SIMDE_FLOAT16_VALUE(   -83.56), SIMDE_FLOAT16_VALUE(    39.50) },
      { SIMDE_FLOAT16_VALUE(  -182.62), SIMDE_FLOAT16_VALUE(   116.19), SIMDE_FLOAT16_VALUE(   207.62), SIMDE_FLOAT16_VALUE(  -253.62) },
      { SIMDE_FLOAT16_VALUE(   242.25), SIMDE_FLOAT16_VALUE(   243.75), SIMDE_FLOAT16_VALUE(  -144.50), SIMDE_FLOAT16_VALUE(   232.38),
        SIMDE_FLOAT16_VALUE(   179.88), SIMDE_FLOAT16_VALUE(  -129.50), SIMDE_FLOAT16_VALUE(   227.25), SIMDE_FLOAT16_VALUE(   219.25) },
       INT32_C(           1),
      { SIMDE_FLOAT16_VALUE( 26144.00), SIMDE_FLOAT16_VALUE(-42272.00), SIMDE_FLOAT16_VALUE(-30080.00), SIMDE_FLOAT16_VALUE( 48288.00) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x4_t r_ = simde_vld1_f16(test_vec[i].r_);
    simde_float16x4_t a = simde_vld1_f16(test_vec[i].a);
    simde_float16x8_t b = simde_vld1q_f16(test_vec[i].b);
    simde_float16x4_t r;
    switch(i & 1) {
      case 0:
        r = simde_vcmla_laneq_f16(r_, a, b, 0);
        break;
      case 1:
        r = simde_vcmla_laneq_f16(r_, a, b, 1);
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
      r = simde_vcmla_laneq_f16(r_, a, b, 1);
    else
      r = simde_vcmla_laneq_f16(r_, a, b, 0);


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
test_simde_vcmla_laneq_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32_t r_[2];
    simde_float32_t a[2];
    simde_float32_t b[4];
    const int lane;
    simde_float32_t r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -118.40), SIMDE_FLOAT32_C(  -269.16) },
      { SIMDE_FLOAT32_C(   155.49), SIMDE_FLOAT32_C(   271.26) },
      { SIMDE_FLOAT32_C(   297.69), SIMDE_FLOAT32_C(  -142.97), SIMDE_FLOAT32_C(    71.66), SIMDE_FLOAT32_C(   183.71) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C( 46169.42), SIMDE_FLOAT32_C(-22499.57) } },
    { { SIMDE_FLOAT32_C(     0.21), SIMDE_FLOAT32_C(   -35.22) },
      { SIMDE_FLOAT32_C(   239.51), SIMDE_FLOAT32_C(    54.53) },
      { SIMDE_FLOAT32_C(   283.90), SIMDE_FLOAT32_C(  -227.13), SIMDE_FLOAT32_C(   -91.04), SIMDE_FLOAT32_C(   -72.37) },
       INT32_C(           1),
      { SIMDE_FLOAT32_C(-21804.78), SIMDE_FLOAT32_C(-17368.56) } },
    { { SIMDE_FLOAT32_C(   -94.28), SIMDE_FLOAT32_C(    32.75) },
      { SIMDE_FLOAT32_C(   217.79), SIMDE_FLOAT32_C(  -184.89) },
      { SIMDE_FLOAT32_C(   -20.66), SIMDE_FLOAT32_C(   171.84), SIMDE_FLOAT32_C(  -287.92), SIMDE_FLOAT32_C(  -128.74) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C( -4593.82), SIMDE_FLOAT32_C( 37457.78) } },
    { { SIMDE_FLOAT32_C(  -113.87), SIMDE_FLOAT32_C(   202.02) },
      { SIMDE_FLOAT32_C(    -6.28), SIMDE_FLOAT32_C(    49.19) },
      { SIMDE_FLOAT32_C(     9.56), SIMDE_FLOAT32_C(  -194.15), SIMDE_FLOAT32_C(  -235.98), SIMDE_FLOAT32_C(   -92.88) },
       INT32_C(           1),
      { SIMDE_FLOAT32_C(  1368.08), SIMDE_FLOAT32_C(   785.31) } },
    { { SIMDE_FLOAT32_C(    98.97), SIMDE_FLOAT32_C(   218.41) },
      { SIMDE_FLOAT32_C(   -46.91), SIMDE_FLOAT32_C(    53.53) },
      { SIMDE_FLOAT32_C(  -263.90), SIMDE_FLOAT32_C(  -223.34), SIMDE_FLOAT32_C(  -134.35), SIMDE_FLOAT32_C(  -246.13) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C( 12478.52), SIMDE_FLOAT32_C( 10695.29) } },
    { { SIMDE_FLOAT32_C(   225.93), SIMDE_FLOAT32_C(  -196.84) },
      { SIMDE_FLOAT32_C(    83.84), SIMDE_FLOAT32_C(  -241.36) },
      { SIMDE_FLOAT32_C(   142.84), SIMDE_FLOAT32_C(   176.08), SIMDE_FLOAT32_C(   193.01), SIMDE_FLOAT32_C(  -219.42) },
       INT32_C(           1),
      { SIMDE_FLOAT32_C( 16407.89), SIMDE_FLOAT32_C(-18593.01) } },
    { { SIMDE_FLOAT32_C(  -209.71), SIMDE_FLOAT32_C(  -162.57) },
      { SIMDE_FLOAT32_C(   150.27), SIMDE_FLOAT32_C(   199.59) },
      { SIMDE_FLOAT32_C(   -48.88), SIMDE_FLOAT32_C(   -99.86), SIMDE_FLOAT32_C(  -208.71), SIMDE_FLOAT32_C(  -160.53) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C( -7554.91), SIMDE_FLOAT32_C(-15168.53) } },
    { { SIMDE_FLOAT32_C(   145.52), SIMDE_FLOAT32_C(    81.06) },
      { SIMDE_FLOAT32_C(  -180.08), SIMDE_FLOAT32_C(  -182.44) },
      { SIMDE_FLOAT32_C(  -254.71), SIMDE_FLOAT32_C(   136.15), SIMDE_FLOAT32_C(   -80.17), SIMDE_FLOAT32_C(   226.50) },
       INT32_C(           1),
      { SIMDE_FLOAT32_C( 14582.53), SIMDE_FLOAT32_C(-40707.06) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t r_ = simde_vld1_f32(test_vec[i].r_);
    simde_float32x2_t a = simde_vld1_f32(test_vec[i].a);
    simde_float32x4_t b = simde_vld1q_f32(test_vec[i].b);
    simde_float32x2_t r;
    switch(i & 1) {
      case 0:
        r = simde_vcmla_laneq_f32(r_, a, b, 0);
        break;
      case 1:
        r = simde_vcmla_laneq_f32(r_, a, b, 1);
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
    simde_float32x2_t r_ = simde_test_arm_neon_random_f32x2(-300.0f, 300.0f);
    simde_float32x2_t a = simde_test_arm_neon_random_f32x2(-300.0f, 300.0f);
    simde_float32x4_t b = simde_test_arm_neon_random_f32x4(-300.0f, 300.0f);
    simde_float32x2_t r;
    if(i % 2)
      r = simde_vcmla_laneq_f32(r_, a, b, 1);
    else
      r = simde_vcmla_laneq_f32(r_, a, b, 0);


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
test_simde_vcmlaq_lane_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16_t r_[8];
    simde_float16_t a[8];
    simde_float16_t b[4];
    const int lane;
    simde_float16_t r[8];
  } test_vec[] = {

    { { SIMDE_FLOAT16_VALUE(  -284.25), SIMDE_FLOAT16_VALUE(  -254.12), SIMDE_FLOAT16_VALUE(   -31.88), SIMDE_FLOAT16_VALUE(   224.62),
        SIMDE_FLOAT16_VALUE(  -172.38), SIMDE_FLOAT16_VALUE(   295.00), SIMDE_FLOAT16_VALUE(   152.12), SIMDE_FLOAT16_VALUE(    64.12) },
      { SIMDE_FLOAT16_VALUE(  -187.00), SIMDE_FLOAT16_VALUE(     7.77), SIMDE_FLOAT16_VALUE(  -168.25), SIMDE_FLOAT16_VALUE(  -274.75),
        SIMDE_FLOAT16_VALUE(   200.25), SIMDE_FLOAT16_VALUE(  -101.38), SIMDE_FLOAT16_VALUE(  -142.62), SIMDE_FLOAT16_VALUE(  -280.25) },
      { SIMDE_FLOAT16_VALUE(    56.41), SIMDE_FLOAT16_VALUE(   277.25), SIMDE_FLOAT16_VALUE(     1.31), SIMDE_FLOAT16_VALUE(  -214.88) },
       INT32_C(           0),
      { SIMDE_FLOAT16_VALUE(-10832.00), SIMDE_FLOAT16_VALUE(-52096.00), SIMDE_FLOAT16_VALUE( -9520.00), SIMDE_FLOAT16_VALUE(-46432.00),
        SIMDE_FLOAT16_VALUE( 11120.00), SIMDE_FLOAT16_VALUE( 55808.00), SIMDE_FLOAT16_VALUE( -7892.00), SIMDE_FLOAT16_VALUE(-39488.00) } },
    { { SIMDE_FLOAT16_VALUE(   124.12), SIMDE_FLOAT16_VALUE(    66.44), SIMDE_FLOAT16_VALUE(   108.19), SIMDE_FLOAT16_VALUE(  -123.19),
        SIMDE_FLOAT16_VALUE(   -45.41), SIMDE_FLOAT16_VALUE(    -9.85), SIMDE_FLOAT16_VALUE(   109.94), SIMDE_FLOAT16_VALUE(  -130.25) },
      { SIMDE_FLOAT16_VALUE(   -45.19), SIMDE_FLOAT16_VALUE(  -104.88), SIMDE_FLOAT16_VALUE(  -212.38), SIMDE_FLOAT16_VALUE(   224.12),
        SIMDE_FLOAT16_VALUE(  -194.12), SIMDE_FLOAT16_VALUE(   -26.95), SIMDE_FLOAT16_VALUE(   -73.56), SIMDE_FLOAT16_VALUE(  -173.88) },
      { SIMDE_FLOAT16_VALUE(  -182.75), SIMDE_FLOAT16_VALUE(   113.31), SIMDE_FLOAT16_VALUE(   197.00), SIMDE_FLOAT16_VALUE(  -253.00) },
       INT32_C(           1),
      { SIMDE_FLOAT16_VALUE( -8776.00), SIMDE_FLOAT16_VALUE( 11496.00), SIMDE_FLOAT16_VALUE(-41728.00), SIMDE_FLOAT16_VALUE( 53600.00),
        SIMDE_FLOAT16_VALUE(-38304.00), SIMDE_FLOAT16_VALUE( 49088.00), SIMDE_FLOAT16_VALUE(-14384.00), SIMDE_FLOAT16_VALUE( 18480.00) } },
    { { SIMDE_FLOAT16_VALUE(  -196.50), SIMDE_FLOAT16_VALUE(   -73.19), SIMDE_FLOAT16_VALUE(    74.75), SIMDE_FLOAT16_VALUE(  -234.00),
        SIMDE_FLOAT16_VALUE(  -272.75), SIMDE_FLOAT16_VALUE(    80.44), SIMDE_FLOAT16_VALUE(    53.56), SIMDE_FLOAT16_VALUE(   -18.67) },
      { SIMDE_FLOAT16_VALUE(   -44.59), SIMDE_FLOAT16_VALUE(  -148.25), SIMDE_FLOAT16_VALUE(  -194.62), SIMDE_FLOAT16_VALUE(    48.00),
        SIMDE_FLOAT16_VALUE(   226.50), SIMDE_FLOAT16_VALUE(   -29.56), SIMDE_FLOAT16_VALUE(   -30.09), SIMDE_FLOAT16_VALUE(    80.56) },
      { SIMDE_FLOAT16_VALUE(  -143.62), SIMDE_FLOAT16_VALUE(   -29.59), SIMDE_FLOAT16_VALUE(    69.31), SIMDE_FLOAT16_VALUE(    92.25) },
       INT32_C(           0),
      { SIMDE_FLOAT16_VALUE(  6208.00), SIMDE_FLOAT16_VALUE(  1247.00), SIMDE_FLOAT16_VALUE( 28032.00), SIMDE_FLOAT16_VALUE(  5524.00),
        SIMDE_FLOAT16_VALUE(-32800.00), SIMDE_FLOAT16_VALUE( -6624.00), SIMDE_FLOAT16_VALUE(  4376.00), SIMDE_FLOAT16_VALUE(   872.00) } },
    { { SIMDE_FLOAT16_VALUE(   113.00), SIMDE_FLOAT16_VALUE(   106.44), SIMDE_FLOAT16_VALUE(   -80.50), SIMDE_FLOAT16_VALUE(   211.75),
        SIMDE_FLOAT16_VALUE(   -86.44), SIMDE_FLOAT16_VALUE(  -139.38), SIMDE_FLOAT16_VALUE(   260.75), SIMDE_FLOAT16_VALUE(  -232.50) },
      { SIMDE_FLOAT16_VALUE(   280.00), SIMDE_FLOAT16_VALUE(  -103.75), SIMDE_FLOAT16_VALUE(   -71.38), SIMDE_FLOAT16_VALUE(   -30.59),
        SIMDE_FLOAT16_VALUE(    17.08), SIMDE_FLOAT16_VALUE(  -270.75), SIMDE_FLOAT16_VALUE(    -7.52), SIMDE_FLOAT16_VALUE(   156.50) },
      { SIMDE_FLOAT16_VALUE(   -88.31), SIMDE_FLOAT16_VALUE(  -221.00), SIMDE_FLOAT16_VALUE(  -214.38), SIMDE_FLOAT16_VALUE(  -122.75) },
       INT32_C(           1),
      { SIMDE_FLOAT16_VALUE(-59904.00), SIMDE_FLOAT16_VALUE(-34272.00), SIMDE_FLOAT16_VALUE( 15224.00), SIMDE_FLOAT16_VALUE(  8976.00),
        SIMDE_FLOAT16_VALUE( -3748.00), SIMDE_FLOAT16_VALUE( -2236.00), SIMDE_FLOAT16_VALUE(  1873.00), SIMDE_FLOAT16_VALUE(   690.50) } },
    { { SIMDE_FLOAT16_VALUE(   138.50), SIMDE_FLOAT16_VALUE(  -205.38), SIMDE_FLOAT16_VALUE(   289.75), SIMDE_FLOAT16_VALUE(   -16.59),
        SIMDE_FLOAT16_VALUE(    22.66), SIMDE_FLOAT16_VALUE(  -201.00), SIMDE_FLOAT16_VALUE(  -226.00), SIMDE_FLOAT16_VALUE(   267.25) },
      { SIMDE_FLOAT16_VALUE(  -267.25), SIMDE_FLOAT16_VALUE(   153.88), SIMDE_FLOAT16_VALUE(    20.80), SIMDE_FLOAT16_VALUE(   209.12),
        SIMDE_FLOAT16_VALUE(   202.25), SIMDE_FLOAT16_VALUE(   -82.75), SIMDE_FLOAT16_VALUE(  -178.62), SIMDE_FLOAT16_VALUE(   -36.31) },
      { SIMDE_FLOAT16_VALUE(  -105.88), SIMDE_FLOAT16_VALUE(   -97.75), SIMDE_FLOAT16_VALUE(   228.38), SIMDE_FLOAT16_VALUE(   131.12) },
       INT32_C(           0),
      { SIMDE_FLOAT16_VALUE( 28432.00), SIMDE_FLOAT16_VALUE( 25920.00), SIMDE_FLOAT16_VALUE( -1912.00), SIMDE_FLOAT16_VALUE( -2050.00),
        SIMDE_FLOAT16_VALUE(-21392.00), SIMDE_FLOAT16_VALUE(-19968.00), SIMDE_FLOAT16_VALUE( 18688.00), SIMDE_FLOAT16_VALUE( 17728.00) } },
    { { SIMDE_FLOAT16_VALUE(   266.00), SIMDE_FLOAT16_VALUE(    46.91), SIMDE_FLOAT16_VALUE(   173.12), SIMDE_FLOAT16_VALUE(   193.12),
        SIMDE_FLOAT16_VALUE(    77.69), SIMDE_FLOAT16_VALUE(   132.38), SIMDE_FLOAT16_VALUE(   134.62), SIMDE_FLOAT16_VALUE(   224.88) },
      { SIMDE_FLOAT16_VALUE(  -207.50), SIMDE_FLOAT16_VALUE(   115.56), SIMDE_FLOAT16_VALUE(  -259.50), SIMDE_FLOAT16_VALUE(    63.84),
        SIMDE_FLOAT16_VALUE(    80.00), SIMDE_FLOAT16_VALUE(   115.81), SIMDE_FLOAT16_VALUE(   -46.59), SIMDE_FLOAT16_VALUE(  -141.00) },
      { SIMDE_FLOAT16_VALUE(   165.62), SIMDE_FLOAT16_VALUE(  -269.25), SIMDE_FLOAT16_VALUE(  -200.75), SIMDE_FLOAT16_VALUE(  -247.00) },
       INT32_C(           1),
      { SIMDE_FLOAT16_VALUE( 41920.00), SIMDE_FLOAT16_VALUE( 51296.00), SIMDE_FLOAT16_VALUE( 52256.00), SIMDE_FLOAT16_VALUE( 64288.00),
        SIMDE_FLOAT16_VALUE(-15984.00), SIMDE_FLOAT16_VALUE(-19632.00), SIMDE_FLOAT16_VALUE(  9488.00), SIMDE_FLOAT16_VALUE( 11736.00) } },
    { { SIMDE_FLOAT16_VALUE(   253.38), SIMDE_FLOAT16_VALUE(    52.44), SIMDE_FLOAT16_VALUE(  -166.12), SIMDE_FLOAT16_VALUE(  -166.88),
        SIMDE_FLOAT16_VALUE(   173.25), SIMDE_FLOAT16_VALUE(   141.00), SIMDE_FLOAT16_VALUE(   283.25), SIMDE_FLOAT16_VALUE(   288.25) },
      { SIMDE_FLOAT16_VALUE(   -55.94), SIMDE_FLOAT16_VALUE(  -234.75), SIMDE_FLOAT16_VALUE(   201.25), SIMDE_FLOAT16_VALUE(   138.38),
        SIMDE_FLOAT16_VALUE(  -242.00), SIMDE_FLOAT16_VALUE(   -19.02), SIMDE_FLOAT16_VALUE(   206.75), SIMDE_FLOAT16_VALUE(   -73.69) },
      { SIMDE_FLOAT16_VALUE(    50.47), SIMDE_FLOAT16_VALUE(     1.19), SIMDE_FLOAT16_VALUE(   238.62), SIMDE_FLOAT16_VALUE(   -44.88) },
       INT32_C(           0),
      { SIMDE_FLOAT16_VALUE( -2570.00), SIMDE_FLOAT16_VALUE(   -14.15), SIMDE_FLOAT16_VALUE(  9992.00), SIMDE_FLOAT16_VALUE(    72.69),
        SIMDE_FLOAT16_VALUE(-12040.00), SIMDE_FLOAT16_VALUE(  -147.12), SIMDE_FLOAT16_VALUE( 10720.00), SIMDE_FLOAT16_VALUE(   534.50) } },
    { { SIMDE_FLOAT16_VALUE(   276.25), SIMDE_FLOAT16_VALUE(    95.56), SIMDE_FLOAT16_VALUE(   184.50), SIMDE_FLOAT16_VALUE(  -263.75),
        SIMDE_FLOAT16_VALUE(    22.33), SIMDE_FLOAT16_VALUE(   262.25), SIMDE_FLOAT16_VALUE(    61.22), SIMDE_FLOAT16_VALUE(  -207.62) },
      { SIMDE_FLOAT16_VALUE(  -241.38), SIMDE_FLOAT16_VALUE(    47.47), SIMDE_FLOAT16_VALUE(    41.06), SIMDE_FLOAT16_VALUE(  -257.25),
        SIMDE_FLOAT16_VALUE(    96.50), SIMDE_FLOAT16_VALUE(  -193.75), SIMDE_FLOAT16_VALUE(   -23.00), SIMDE_FLOAT16_VALUE(  -117.06) },
      { SIMDE_FLOAT16_VALUE(  -129.00), SIMDE_FLOAT16_VALUE(   172.62), SIMDE_FLOAT16_VALUE(    35.66), SIMDE_FLOAT16_VALUE(    42.03) },
       INT32_C(           1),
      { SIMDE_FLOAT16_VALUE( -8328.00), SIMDE_FLOAT16_VALUE(-10048.00), SIMDE_FLOAT16_VALUE(  1649.00), SIMDE_FLOAT16_VALUE(  1462.00),
        SIMDE_FLOAT16_VALUE(  3464.00), SIMDE_FLOAT16_VALUE(  4320.00), SIMDE_FLOAT16_VALUE(  -759.00), SIMDE_FLOAT16_VALUE( -1174.00) } }
    
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x8_t r_ = simde_vld1q_f16(test_vec[i].r_);
    simde_float16x8_t a = simde_vld1q_f16(test_vec[i].a);
    simde_float16x4_t b = simde_vld1_f16(test_vec[i].b);
    simde_float16x8_t r;
    switch(i & 1) {
      case 0:
        r = simde_vcmlaq_lane_f16(r_, a, b, 0);
        break;
      case 1:
        r = simde_vcmlaq_lane_f16(r_, a, b, 1);
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
      r = simde_vcmlaq_lane_f16(r_, a, b, 1);
    else
      r = simde_vcmlaq_lane_f16(r_, a, b, 0);


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
test_simde_vcmlaq_lane_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32_t r_[4];
    simde_float32_t a[4];
    simde_float32_t b[2];
    const int lane;
    simde_float32_t r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -702.91), SIMDE_FLOAT32_C(   255.88), SIMDE_FLOAT32_C(   560.25), SIMDE_FLOAT32_C(   187.99) },
      { SIMDE_FLOAT32_C(  -442.40), SIMDE_FLOAT32_C(   666.59), SIMDE_FLOAT32_C(  -697.08), SIMDE_FLOAT32_C(   250.93) },
      { SIMDE_FLOAT32_C(  -642.19), SIMDE_FLOAT32_C(   700.73) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C(283401.94), SIMDE_FLOAT32_C(-309747.06), SIMDE_FLOAT32_C(448218.06), SIMDE_FLOAT32_C(-488276.88) } },
    { { SIMDE_FLOAT32_C(  -846.86), SIMDE_FLOAT32_C(   768.10), SIMDE_FLOAT32_C(  -508.69), SIMDE_FLOAT32_C(   382.71) },
      { SIMDE_FLOAT32_C(   161.05), SIMDE_FLOAT32_C(   741.11), SIMDE_FLOAT32_C(  -109.17), SIMDE_FLOAT32_C(  -796.36) },
      { SIMDE_FLOAT32_C(  -434.57), SIMDE_FLOAT32_C(   154.60) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C(-70834.36), SIMDE_FLOAT32_C( 25666.43), SIMDE_FLOAT32_C( 46933.32), SIMDE_FLOAT32_C(-16494.97) } },
    { { SIMDE_FLOAT32_C(   327.91), SIMDE_FLOAT32_C(  -748.79), SIMDE_FLOAT32_C(  -889.79), SIMDE_FLOAT32_C(  -739.71) },
      { SIMDE_FLOAT32_C(  -382.67), SIMDE_FLOAT32_C(   429.06), SIMDE_FLOAT32_C(  -791.89), SIMDE_FLOAT32_C(   750.46) },
      { SIMDE_FLOAT32_C(  -983.69), SIMDE_FLOAT32_C(  -915.73) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C(376756.56), SIMDE_FLOAT32_C(349673.62), SIMDE_FLOAT32_C(778084.50), SIMDE_FLOAT32_C(724417.69) } },
    { { SIMDE_FLOAT32_C(  -631.95), SIMDE_FLOAT32_C(   836.15), SIMDE_FLOAT32_C(  -851.56), SIMDE_FLOAT32_C(  -161.21) },
      { SIMDE_FLOAT32_C(   584.07), SIMDE_FLOAT32_C(   439.31), SIMDE_FLOAT32_C(  -434.61), SIMDE_FLOAT32_C(  -421.02) },
      { SIMDE_FLOAT32_C(   -13.33), SIMDE_FLOAT32_C(    -9.03) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C( -8417.60), SIMDE_FLOAT32_C( -4438.00), SIMDE_FLOAT32_C(  4941.79), SIMDE_FLOAT32_C(  3763.32) } },
    { { SIMDE_FLOAT32_C(   310.30), SIMDE_FLOAT32_C(  -704.49), SIMDE_FLOAT32_C(  -392.91), SIMDE_FLOAT32_C(   391.63) },
      { SIMDE_FLOAT32_C(    65.92), SIMDE_FLOAT32_C(  -141.59), SIMDE_FLOAT32_C(   223.20), SIMDE_FLOAT32_C(  -726.52) },
      { SIMDE_FLOAT32_C(  -667.28), SIMDE_FLOAT32_C(   996.87) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C(-43676.80), SIMDE_FLOAT32_C( 65009.18), SIMDE_FLOAT32_C(-149329.81), SIMDE_FLOAT32_C(222893.02) } },
    { { SIMDE_FLOAT32_C(   438.86), SIMDE_FLOAT32_C(  -157.54), SIMDE_FLOAT32_C(   194.25), SIMDE_FLOAT32_C(   744.41) },
      { SIMDE_FLOAT32_C(  -620.81), SIMDE_FLOAT32_C(   124.70), SIMDE_FLOAT32_C(  -126.21), SIMDE_FLOAT32_C(   732.53) },
      { SIMDE_FLOAT32_C(  -449.14), SIMDE_FLOAT32_C(  -758.62) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C(279269.47), SIMDE_FLOAT32_C(470801.34), SIMDE_FLOAT32_C( 56880.21), SIMDE_FLOAT32_C( 96489.84) } },
    { { SIMDE_FLOAT32_C(  -136.22), SIMDE_FLOAT32_C(   509.16), SIMDE_FLOAT32_C(  -491.82), SIMDE_FLOAT32_C(    24.62) },
      { SIMDE_FLOAT32_C(  -208.64), SIMDE_FLOAT32_C(  -647.22), SIMDE_FLOAT32_C(   166.88), SIMDE_FLOAT32_C(   720.43) },
      { SIMDE_FLOAT32_C(   297.43), SIMDE_FLOAT32_C(   949.68) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C(-62192.01), SIMDE_FLOAT32_C(-197632.08), SIMDE_FLOAT32_C( 49143.30), SIMDE_FLOAT32_C(158507.22) } },
    { { SIMDE_FLOAT32_C(  -725.81), SIMDE_FLOAT32_C(  -606.03), SIMDE_FLOAT32_C(   408.33), SIMDE_FLOAT32_C(   823.31) },
      { SIMDE_FLOAT32_C(  -604.63), SIMDE_FLOAT32_C(   -85.11), SIMDE_FLOAT32_C(  -377.70), SIMDE_FLOAT32_C(    25.42) },
      { SIMDE_FLOAT32_C(  -744.67), SIMDE_FLOAT32_C(   282.01) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C(449524.00), SIMDE_FLOAT32_C(-171117.75), SIMDE_FLOAT32_C(281670.19), SIMDE_FLOAT32_C(-105691.88) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t r_ = simde_vld1q_f32(test_vec[i].r_);
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_float32x2_t b = simde_vld1_f32(test_vec[i].b);
    simde_float32x4_t r = simde_vcmlaq_lane_f32(r_, a, b, 0);
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
    simde_float32x4_t r = simde_vcmlaq_lane_f32(r_, a, b, 0);


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
test_simde_vcmlaq_laneq_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16_t r_[8];
    simde_float16_t a[8];
    simde_float16_t b[8];
    const int lane;
    simde_float16_t r[8];
  } test_vec[] = {
    { { SIMDE_FLOAT16_VALUE(  -109.25), SIMDE_FLOAT16_VALUE(  -121.62), SIMDE_FLOAT16_VALUE(    17.56), SIMDE_FLOAT16_VALUE(    10.65),
        SIMDE_FLOAT16_VALUE(   142.50), SIMDE_FLOAT16_VALUE(  -197.88), SIMDE_FLOAT16_VALUE(  -115.56), SIMDE_FLOAT16_VALUE(  -111.38) },
      { SIMDE_FLOAT16_VALUE(  -135.50), SIMDE_FLOAT16_VALUE(   -85.81), SIMDE_FLOAT16_VALUE(   -15.50), SIMDE_FLOAT16_VALUE(  -107.69),
        SIMDE_FLOAT16_VALUE(  -152.00), SIMDE_FLOAT16_VALUE(    86.25), SIMDE_FLOAT16_VALUE(  -149.50), SIMDE_FLOAT16_VALUE(    89.19) },
      { SIMDE_FLOAT16_VALUE(  -197.88), SIMDE_FLOAT16_VALUE(    63.19), SIMDE_FLOAT16_VALUE(   -13.34), SIMDE_FLOAT16_VALUE(  -166.88),
        SIMDE_FLOAT16_VALUE(   -17.66), SIMDE_FLOAT16_VALUE(    69.81), SIMDE_FLOAT16_VALUE(   185.88), SIMDE_FLOAT16_VALUE(    73.06) },
       INT32_C(           0),
      { SIMDE_FLOAT16_VALUE( 26704.00), SIMDE_FLOAT16_VALUE( -8680.00), SIMDE_FLOAT16_VALUE(  3084.00), SIMDE_FLOAT16_VALUE(  -969.00),
        SIMDE_FLOAT16_VALUE( 30224.00), SIMDE_FLOAT16_VALUE( -9800.00), SIMDE_FLOAT16_VALUE( 29472.00), SIMDE_FLOAT16_VALUE( -9560.00) } },
    { { SIMDE_FLOAT16_VALUE(   172.88), SIMDE_FLOAT16_VALUE(    50.75), SIMDE_FLOAT16_VALUE(    -4.95), SIMDE_FLOAT16_VALUE(   -59.25),
        SIMDE_FLOAT16_VALUE(   185.12), SIMDE_FLOAT16_VALUE(    60.97), SIMDE_FLOAT16_VALUE(   127.12), SIMDE_FLOAT16_VALUE(  -142.75) },
      { SIMDE_FLOAT16_VALUE(  -117.81), SIMDE_FLOAT16_VALUE(   -56.00), SIMDE_FLOAT16_VALUE(   104.50), SIMDE_FLOAT16_VALUE(  -131.50),
        SIMDE_FLOAT16_VALUE(  -152.50), SIMDE_FLOAT16_VALUE(   -60.66), SIMDE_FLOAT16_VALUE(   144.00), SIMDE_FLOAT16_VALUE(  -145.75) },
      { SIMDE_FLOAT16_VALUE(   178.75), SIMDE_FLOAT16_VALUE(   -15.86), SIMDE_FLOAT16_VALUE(   186.75), SIMDE_FLOAT16_VALUE(   -84.56),
        SIMDE_FLOAT16_VALUE(    -0.51), SIMDE_FLOAT16_VALUE(   172.75), SIMDE_FLOAT16_VALUE(   144.88), SIMDE_FLOAT16_VALUE(   109.38) },
       INT32_C(           1),
      { SIMDE_FLOAT16_VALUE(-21824.00), SIMDE_FLOAT16_VALUE( 10016.00), SIMDE_FLOAT16_VALUE( 19504.00), SIMDE_FLOAT16_VALUE( -8896.00),
        SIMDE_FLOAT16_VALUE(-28288.00), SIMDE_FLOAT16_VALUE( 12960.00), SIMDE_FLOAT16_VALUE( 27024.00), SIMDE_FLOAT16_VALUE(-12320.00) } },
    { { SIMDE_FLOAT16_VALUE(  -109.69), SIMDE_FLOAT16_VALUE(    40.44), SIMDE_FLOAT16_VALUE(   -87.06), SIMDE_FLOAT16_VALUE(    91.81),
        SIMDE_FLOAT16_VALUE(   133.88), SIMDE_FLOAT16_VALUE(    68.19), SIMDE_FLOAT16_VALUE(    80.44), SIMDE_FLOAT16_VALUE(   190.75) },
      { SIMDE_FLOAT16_VALUE(   161.25), SIMDE_FLOAT16_VALUE(   -52.41), SIMDE_FLOAT16_VALUE(   166.38), SIMDE_FLOAT16_VALUE(   189.88),
        SIMDE_FLOAT16_VALUE(   -50.75), SIMDE_FLOAT16_VALUE(    12.16), SIMDE_FLOAT16_VALUE(    22.98), SIMDE_FLOAT16_VALUE(  -138.00) },
      { SIMDE_FLOAT16_VALUE(    88.81), SIMDE_FLOAT16_VALUE(   -34.66), SIMDE_FLOAT16_VALUE(  -123.19), SIMDE_FLOAT16_VALUE(  -132.00),
        SIMDE_FLOAT16_VALUE(    58.75), SIMDE_FLOAT16_VALUE(   -40.78), SIMDE_FLOAT16_VALUE(   176.75), SIMDE_FLOAT16_VALUE(   -81.06) },
       INT32_C(           2),
      { SIMDE_FLOAT16_VALUE(  9360.00), SIMDE_FLOAT16_VALUE( -6536.00), SIMDE_FLOAT16_VALUE(  9688.00), SIMDE_FLOAT16_VALUE( -6692.00),
        SIMDE_FLOAT16_VALUE( -2848.00), SIMDE_FLOAT16_VALUE(  2138.00), SIMDE_FLOAT16_VALUE(  1431.00), SIMDE_FLOAT16_VALUE(  -746.50) } },
    { { SIMDE_FLOAT16_VALUE(   -97.75), SIMDE_FLOAT16_VALUE(   115.38), SIMDE_FLOAT16_VALUE(   146.50), SIMDE_FLOAT16_VALUE(  -148.50),
        SIMDE_FLOAT16_VALUE(   128.75), SIMDE_FLOAT16_VALUE(   -15.79), SIMDE_FLOAT16_VALUE(  -175.75), SIMDE_FLOAT16_VALUE(    70.19) },
      { SIMDE_FLOAT16_VALUE(    55.62), SIMDE_FLOAT16_VALUE(  -182.62), SIMDE_FLOAT16_VALUE(   149.50), SIMDE_FLOAT16_VALUE(     0.03),
        SIMDE_FLOAT16_VALUE(   142.50), SIMDE_FLOAT16_VALUE(    88.88), SIMDE_FLOAT16_VALUE(  -176.75), SIMDE_FLOAT16_VALUE(    36.19) },
      { SIMDE_FLOAT16_VALUE(    -3.01), SIMDE_FLOAT16_VALUE(   132.50), SIMDE_FLOAT16_VALUE(  -163.75), SIMDE_FLOAT16_VALUE(   195.62),
        SIMDE_FLOAT16_VALUE(   -78.69), SIMDE_FLOAT16_VALUE(   167.88), SIMDE_FLOAT16_VALUE(  -192.25), SIMDE_FLOAT16_VALUE(  -114.38) },
       INT32_C(           3),
      { SIMDE_FLOAT16_VALUE(-10792.00), SIMDE_FLOAT16_VALUE( -6248.00), SIMDE_FLOAT16_VALUE(-28592.00), SIMDE_FLOAT16_VALUE(-17248.00),
        SIMDE_FLOAT16_VALUE(-27264.00), SIMDE_FLOAT16_VALUE(-16312.00), SIMDE_FLOAT16_VALUE( 33792.00), SIMDE_FLOAT16_VALUE( 20288.00) } },
    { { SIMDE_FLOAT16_VALUE(   145.88), SIMDE_FLOAT16_VALUE(    14.76), SIMDE_FLOAT16_VALUE(    78.19), SIMDE_FLOAT16_VALUE(   -17.27),
        SIMDE_FLOAT16_VALUE(   -48.16), SIMDE_FLOAT16_VALUE(    55.19), SIMDE_FLOAT16_VALUE(  -183.62), SIMDE_FLOAT16_VALUE(  -149.00) },
      { SIMDE_FLOAT16_VALUE(  -153.75), SIMDE_FLOAT16_VALUE(   195.38), SIMDE_FLOAT16_VALUE(   -43.38), SIMDE_FLOAT16_VALUE(   -95.25),
        SIMDE_FLOAT16_VALUE(   -49.59), SIMDE_FLOAT16_VALUE(  -137.88), SIMDE_FLOAT16_VALUE(     8.55), SIMDE_FLOAT16_VALUE(   101.06) },
      { SIMDE_FLOAT16_VALUE(   190.62), SIMDE_FLOAT16_VALUE(    74.62), SIMDE_FLOAT16_VALUE(  -157.38), SIMDE_FLOAT16_VALUE(  -155.00),
        SIMDE_FLOAT16_VALUE(    18.92), SIMDE_FLOAT16_VALUE(   -55.50), SIMDE_FLOAT16_VALUE(  -184.38), SIMDE_FLOAT16_VALUE(   -81.31) },
       INT32_C(           0),
      { SIMDE_FLOAT16_VALUE(-29168.00), SIMDE_FLOAT16_VALUE(-11456.00), SIMDE_FLOAT16_VALUE( -8192.00), SIMDE_FLOAT16_VALUE( -3254.00),
        SIMDE_FLOAT16_VALUE( -9504.00), SIMDE_FLOAT16_VALUE( -3646.00), SIMDE_FLOAT16_VALUE(  1446.00), SIMDE_FLOAT16_VALUE(   488.75) } },
    { { SIMDE_FLOAT16_VALUE(  -102.69), SIMDE_FLOAT16_VALUE(    39.00), SIMDE_FLOAT16_VALUE(    91.88), SIMDE_FLOAT16_VALUE(    80.38),
        SIMDE_FLOAT16_VALUE(    79.06), SIMDE_FLOAT16_VALUE(   -52.56), SIMDE_FLOAT16_VALUE(     8.83), SIMDE_FLOAT16_VALUE(    83.88) },
      { SIMDE_FLOAT16_VALUE(   -99.06), SIMDE_FLOAT16_VALUE(   -54.69), SIMDE_FLOAT16_VALUE(   108.25), SIMDE_FLOAT16_VALUE(  -155.50),
        SIMDE_FLOAT16_VALUE(  -145.12), SIMDE_FLOAT16_VALUE(   198.75), SIMDE_FLOAT16_VALUE(   -95.69), SIMDE_FLOAT16_VALUE(  -183.00) },
      { SIMDE_FLOAT16_VALUE(    46.84), SIMDE_FLOAT16_VALUE(   147.00), SIMDE_FLOAT16_VALUE(    38.75), SIMDE_FLOAT16_VALUE(    45.44),
        SIMDE_FLOAT16_VALUE(  -144.62), SIMDE_FLOAT16_VALUE(   108.62), SIMDE_FLOAT16_VALUE(   105.88), SIMDE_FLOAT16_VALUE(    52.44) },
       INT32_C(           1),
      { SIMDE_FLOAT16_VALUE( -3942.00), SIMDE_FLOAT16_VALUE( -4464.00), SIMDE_FLOAT16_VALUE(  4288.00), SIMDE_FLOAT16_VALUE(  5000.00),
        SIMDE_FLOAT16_VALUE( -5544.00), SIMDE_FLOAT16_VALUE( -6648.00), SIMDE_FLOAT16_VALUE( -3700.00), SIMDE_FLOAT16_VALUE( -4264.00) } },
    { { SIMDE_FLOAT16_VALUE(   -57.41), SIMDE_FLOAT16_VALUE(    37.00), SIMDE_FLOAT16_VALUE(    94.75), SIMDE_FLOAT16_VALUE(  -134.62),
        SIMDE_FLOAT16_VALUE(  -198.12), SIMDE_FLOAT16_VALUE(   -49.44), SIMDE_FLOAT16_VALUE(   122.75), SIMDE_FLOAT16_VALUE(     3.89) },
      { SIMDE_FLOAT16_VALUE(   102.88), SIMDE_FLOAT16_VALUE(    48.12), SIMDE_FLOAT16_VALUE(   -82.62), SIMDE_FLOAT16_VALUE(   -21.19),
        SIMDE_FLOAT16_VALUE(   -80.00), SIMDE_FLOAT16_VALUE(  -164.50), SIMDE_FLOAT16_VALUE(    54.78), SIMDE_FLOAT16_VALUE(  -193.62) },
      { SIMDE_FLOAT16_VALUE(     0.56), SIMDE_FLOAT16_VALUE(   132.00), SIMDE_FLOAT16_VALUE(  -156.00), SIMDE_FLOAT16_VALUE(  -126.38),
        SIMDE_FLOAT16_VALUE(   116.44), SIMDE_FLOAT16_VALUE(     3.64), SIMDE_FLOAT16_VALUE(   -16.05), SIMDE_FLOAT16_VALUE(    36.09) },
       INT32_C(           2),
      { SIMDE_FLOAT16_VALUE( 11920.00), SIMDE_FLOAT16_VALUE(   411.50), SIMDE_FLOAT16_VALUE( -9528.00), SIMDE_FLOAT16_VALUE(  -435.50),
        SIMDE_FLOAT16_VALUE( -9512.00), SIMDE_FLOAT16_VALUE(  -340.75), SIMDE_FLOAT16_VALUE(  6500.00), SIMDE_FLOAT16_VALUE(   203.38) } },
    { { SIMDE_FLOAT16_VALUE(     1.32), SIMDE_FLOAT16_VALUE(   134.75), SIMDE_FLOAT16_VALUE(   -97.00), SIMDE_FLOAT16_VALUE(   155.62),
        SIMDE_FLOAT16_VALUE(  -181.00), SIMDE_FLOAT16_VALUE(   -19.30), SIMDE_FLOAT16_VALUE(   182.00), SIMDE_FLOAT16_VALUE(   103.25) },
      { SIMDE_FLOAT16_VALUE(   -50.78), SIMDE_FLOAT16_VALUE(  -137.75), SIMDE_FLOAT16_VALUE(  -106.00), SIMDE_FLOAT16_VALUE(   -97.06),
        SIMDE_FLOAT16_VALUE(   145.62), SIMDE_FLOAT16_VALUE(   168.88), SIMDE_FLOAT16_VALUE(  -134.25), SIMDE_FLOAT16_VALUE(  -131.38) },
      { SIMDE_FLOAT16_VALUE(  -106.31), SIMDE_FLOAT16_VALUE(  -138.62), SIMDE_FLOAT16_VALUE(   193.50), SIMDE_FLOAT16_VALUE(  -131.25),
        SIMDE_FLOAT16_VALUE(  -193.00), SIMDE_FLOAT16_VALUE(   169.12), SIMDE_FLOAT16_VALUE(   130.25), SIMDE_FLOAT16_VALUE(   159.00) },
       INT32_C(           3),
      { SIMDE_FLOAT16_VALUE( -6612.00), SIMDE_FLOAT16_VALUE( -7940.00), SIMDE_FLOAT16_VALUE(-13904.00), SIMDE_FLOAT16_VALUE(-16704.00),
        SIMDE_FLOAT16_VALUE( 18784.00), SIMDE_FLOAT16_VALUE( 23136.00), SIMDE_FLOAT16_VALUE(-17312.00), SIMDE_FLOAT16_VALUE(-21248.00) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x8_t r_ = simde_vld1q_f16(test_vec[i].r_);
    simde_float16x8_t a = simde_vld1q_f16(test_vec[i].a);
    simde_float16x8_t b = simde_vld1q_f16(test_vec[i].b);
    simde_float16x8_t r;
    switch(i & 3) {
      case 0:
        r = simde_vcmlaq_laneq_f16(r_, a, b, 0);
        break;
      case 1:
        r = simde_vcmlaq_laneq_f16(r_, a, b, 1);
        break;
      case 2:
        r = simde_vcmlaq_laneq_f16(r_, a, b, 2);
        break;
      case 3:
        r = simde_vcmlaq_laneq_f16(r_, a, b, 3);
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
      r = simde_vcmlaq_laneq_f16(r_, a, b, 1);
    else if(i % 4 == 2)
      r = simde_vcmlaq_laneq_f16(r_, a, b, 2);
    else if(i % 4 == 3)
      r = simde_vcmlaq_laneq_f16(r_, a, b, 3);
    else
      r = simde_vcmlaq_laneq_f16(r_, a, b, 0);

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
test_simde_vcmlaq_laneq_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32_t r_[4];
    simde_float32_t a[4];
    simde_float32_t b[4];
    const int lane;
    simde_float32_t r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(    -3.97), SIMDE_FLOAT32_C(  -791.98), SIMDE_FLOAT32_C(  -816.94), SIMDE_FLOAT32_C(  -319.60) },
      { SIMDE_FLOAT32_C(   495.19), SIMDE_FLOAT32_C(   588.83), SIMDE_FLOAT32_C(   475.98), SIMDE_FLOAT32_C(  -245.72) },
      { SIMDE_FLOAT32_C(   119.41), SIMDE_FLOAT32_C(   989.49), SIMDE_FLOAT32_C(   389.53), SIMDE_FLOAT32_C(   749.74) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C( 59126.67), SIMDE_FLOAT32_C(489193.56), SIMDE_FLOAT32_C( 56019.84), SIMDE_FLOAT32_C(470657.84) } },
    { { SIMDE_FLOAT32_C(   850.92), SIMDE_FLOAT32_C(  -569.00), SIMDE_FLOAT32_C(   899.18), SIMDE_FLOAT32_C(   484.59) },
      { SIMDE_FLOAT32_C(   426.93), SIMDE_FLOAT32_C(  -510.03), SIMDE_FLOAT32_C(   -37.82), SIMDE_FLOAT32_C(   334.77) },
      { SIMDE_FLOAT32_C(   439.20), SIMDE_FLOAT32_C(  -405.40), SIMDE_FLOAT32_C(   522.40), SIMDE_FLOAT32_C(   -11.93) },
       INT32_C(           1),
      { SIMDE_FLOAT32_C(223879.16), SIMDE_FLOAT32_C( -5662.27), SIMDE_FLOAT32_C(-18857.99), SIMDE_FLOAT32_C(   935.78) } },
    { { SIMDE_FLOAT32_C(  -533.35), SIMDE_FLOAT32_C(    61.18), SIMDE_FLOAT32_C(   306.96), SIMDE_FLOAT32_C(  -885.90) },
      { SIMDE_FLOAT32_C(   751.81), SIMDE_FLOAT32_C(  -279.22), SIMDE_FLOAT32_C(  -898.49), SIMDE_FLOAT32_C(  -968.94) },
      { SIMDE_FLOAT32_C(   959.16), SIMDE_FLOAT32_C(   625.05), SIMDE_FLOAT32_C(  -744.57), SIMDE_FLOAT32_C(    50.69) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C(720572.69), SIMDE_FLOAT32_C(469980.00), SIMDE_FLOAT32_C(-861488.69), SIMDE_FLOAT32_C(-562487.06) } },
    { { SIMDE_FLOAT32_C(   -82.03), SIMDE_FLOAT32_C(  -616.75), SIMDE_FLOAT32_C(   233.35), SIMDE_FLOAT32_C(   -49.48) },
      { SIMDE_FLOAT32_C(   313.50), SIMDE_FLOAT32_C(  -939.39), SIMDE_FLOAT32_C(  -251.27), SIMDE_FLOAT32_C(   986.51) },
      { SIMDE_FLOAT32_C(   305.90), SIMDE_FLOAT32_C(  -805.59), SIMDE_FLOAT32_C(   465.96), SIMDE_FLOAT32_C(  -538.82) },
       INT32_C(           1),
      { SIMDE_FLOAT32_C(145996.42), SIMDE_FLOAT32_C(-169536.83), SIMDE_FLOAT32_C(-116848.42), SIMDE_FLOAT32_C(135339.83) } },
    { { SIMDE_FLOAT32_C(    75.05), SIMDE_FLOAT32_C(  -670.69), SIMDE_FLOAT32_C(  -255.57), SIMDE_FLOAT32_C(   637.27) },
      { SIMDE_FLOAT32_C(   583.27), SIMDE_FLOAT32_C(   959.29), SIMDE_FLOAT32_C(   720.63), SIMDE_FLOAT32_C(  -449.49) },
      { SIMDE_FLOAT32_C(  -579.45), SIMDE_FLOAT32_C(  -840.00), SIMDE_FLOAT32_C(    73.20), SIMDE_FLOAT32_C(   307.16) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C(-337900.78), SIMDE_FLOAT32_C(-490617.50), SIMDE_FLOAT32_C(-417824.62), SIMDE_FLOAT32_C(-604691.94) } },
    { { SIMDE_FLOAT32_C(   522.86), SIMDE_FLOAT32_C(  -227.64), SIMDE_FLOAT32_C(   107.65), SIMDE_FLOAT32_C(  -750.83) },
      { SIMDE_FLOAT32_C(   735.78), SIMDE_FLOAT32_C(   194.85), SIMDE_FLOAT32_C(   813.56), SIMDE_FLOAT32_C(  -574.87) },
      { SIMDE_FLOAT32_C(   241.66), SIMDE_FLOAT32_C(  -460.59), SIMDE_FLOAT32_C(   946.09), SIMDE_FLOAT32_C(   995.37) },
       INT32_C(           1),
      { SIMDE_FLOAT32_C(696637.00), SIMDE_FLOAT32_C(732145.75), SIMDE_FLOAT32_C(769808.62), SIMDE_FLOAT32_C(809042.38) } },
    { { SIMDE_FLOAT32_C(  -754.92), SIMDE_FLOAT32_C(   127.10), SIMDE_FLOAT32_C(   168.83), SIMDE_FLOAT32_C(  -391.46) },
      { SIMDE_FLOAT32_C(   758.45), SIMDE_FLOAT32_C(  -764.50), SIMDE_FLOAT32_C(  -885.73), SIMDE_FLOAT32_C(  -531.17) },
      { SIMDE_FLOAT32_C(   642.38), SIMDE_FLOAT32_C(   556.37), SIMDE_FLOAT32_C(   928.15), SIMDE_FLOAT32_C(  -501.16) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C(486458.19), SIMDE_FLOAT32_C(422105.94), SIMDE_FLOAT32_C(-568806.38), SIMDE_FLOAT32_C(-493185.03) } },
    { { SIMDE_FLOAT32_C(   934.10), SIMDE_FLOAT32_C(  -641.51), SIMDE_FLOAT32_C(    83.53), SIMDE_FLOAT32_C(  -183.18) },
      { SIMDE_FLOAT32_C(  -761.61), SIMDE_FLOAT32_C(  -418.42), SIMDE_FLOAT32_C(  -422.92), SIMDE_FLOAT32_C(   -95.01) },
      { SIMDE_FLOAT32_C(  -816.35), SIMDE_FLOAT32_C(  -403.12), SIMDE_FLOAT32_C(   765.03), SIMDE_FLOAT32_C(  -131.63) },
       INT32_C(           1),
      { SIMDE_FLOAT32_C(-581720.44), SIMDE_FLOAT32_C( 99609.22), SIMDE_FLOAT32_C(-323462.97), SIMDE_FLOAT32_C( 55485.79) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t r_ = simde_vld1q_f32(test_vec[i].r_);
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_float32x4_t b = simde_vld1q_f32(test_vec[i].b);
    simde_float32x4_t r;
    switch(i & 1) {
      case 0:
        r = simde_vcmlaq_laneq_f32(r_, a, b, 0);
        break;
      case 1:
        r = simde_vcmlaq_laneq_f32(r_, a, b, 1);
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
      r = simde_vcmlaq_laneq_f32(r_, a, b, 1);
    else
      r = simde_vcmlaq_laneq_f32(r_, a, b, 0);


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
SIMDE_TEST_FUNC_LIST_ENTRY(vcmla_lane_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcmla_lane_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcmla_laneq_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcmla_laneq_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcmlaq_lane_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcmlaq_lane_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcmlaq_laneq_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcmlaq_laneq_f32)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
