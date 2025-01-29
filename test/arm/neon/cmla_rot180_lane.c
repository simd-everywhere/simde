#define SIMDE_TEST_ARM_NEON_INSN cmla_rot180_lane

#include "test-neon.h"
#include "../../../simde/arm/neon/cmla_rot180_lane.h"
#include "../../../simde/arm/neon/dup_n.h"

static int
test_simde_vcmla_rot180_lane_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16_t r_[4];
    simde_float16_t a[4];
    simde_float16_t b[4];
    const int lane;
    simde_float16_t r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT16_VALUE(    53.16), SIMDE_FLOAT16_VALUE(   105.88), SIMDE_FLOAT16_VALUE(    90.75), SIMDE_FLOAT16_VALUE(   -36.34) },
      { SIMDE_FLOAT16_VALUE(  -117.88), SIMDE_FLOAT16_VALUE(   -45.19), SIMDE_FLOAT16_VALUE(   105.88), SIMDE_FLOAT16_VALUE(   155.50) },
      { SIMDE_FLOAT16_VALUE(    44.22), SIMDE_FLOAT16_VALUE(  -150.62), SIMDE_FLOAT16_VALUE(   -91.31), SIMDE_FLOAT16_VALUE(   -43.53) },
       INT32_C(           0),
      { SIMDE_FLOAT16_VALUE(  5264.00), SIMDE_FLOAT16_VALUE(-17648.00), SIMDE_FLOAT16_VALUE( -4592.00), SIMDE_FLOAT16_VALUE( 15912.00) } },
    { { SIMDE_FLOAT16_VALUE(   185.88), SIMDE_FLOAT16_VALUE(    -2.70), SIMDE_FLOAT16_VALUE(  -181.75), SIMDE_FLOAT16_VALUE(  -151.38) },
      { SIMDE_FLOAT16_VALUE(   136.12), SIMDE_FLOAT16_VALUE(   115.06), SIMDE_FLOAT16_VALUE(  -190.50), SIMDE_FLOAT16_VALUE(   -36.34) },
      { SIMDE_FLOAT16_VALUE(  -170.88), SIMDE_FLOAT16_VALUE(   -29.23), SIMDE_FLOAT16_VALUE(   195.12), SIMDE_FLOAT16_VALUE(   -42.78) },
       INT32_C(           1),
      { SIMDE_FLOAT16_VALUE(-26368.00), SIMDE_FLOAT16_VALUE(  5820.00), SIMDE_FLOAT16_VALUE( 36992.00), SIMDE_FLOAT16_VALUE( -8304.00) } },
    { { SIMDE_FLOAT16_VALUE(    43.03), SIMDE_FLOAT16_VALUE(  -156.62), SIMDE_FLOAT16_VALUE(    89.75), SIMDE_FLOAT16_VALUE(    39.06) },
      { SIMDE_FLOAT16_VALUE(   141.12), SIMDE_FLOAT16_VALUE(    57.84), SIMDE_FLOAT16_VALUE(    14.02), SIMDE_FLOAT16_VALUE(   -17.73) },
      { SIMDE_FLOAT16_VALUE(    -6.09), SIMDE_FLOAT16_VALUE(    74.69), SIMDE_FLOAT16_VALUE(    75.50), SIMDE_FLOAT16_VALUE(   -39.31) },
       INT32_C(           0),
      { SIMDE_FLOAT16_VALUE(   902.50), SIMDE_FLOAT16_VALUE(-10696.00), SIMDE_FLOAT16_VALUE(   175.12), SIMDE_FLOAT16_VALUE( -1008.50) } },
    { { SIMDE_FLOAT16_VALUE(  -169.12), SIMDE_FLOAT16_VALUE(   167.88), SIMDE_FLOAT16_VALUE(   176.88), SIMDE_FLOAT16_VALUE(  -113.38) },
      { SIMDE_FLOAT16_VALUE(   187.12), SIMDE_FLOAT16_VALUE(   -99.75), SIMDE_FLOAT16_VALUE(   121.31), SIMDE_FLOAT16_VALUE(   163.12) },
      { SIMDE_FLOAT16_VALUE(   114.19), SIMDE_FLOAT16_VALUE(    48.41), SIMDE_FLOAT16_VALUE(   -18.30), SIMDE_FLOAT16_VALUE(    27.00) },
       INT32_C(           1),
      { SIMDE_FLOAT16_VALUE(  3254.00), SIMDE_FLOAT16_VALUE( -4884.00), SIMDE_FLOAT16_VALUE(  2396.00), SIMDE_FLOAT16_VALUE( -3388.00) } },
    { { SIMDE_FLOAT16_VALUE(  -180.88), SIMDE_FLOAT16_VALUE(   -38.97), SIMDE_FLOAT16_VALUE(  -192.12), SIMDE_FLOAT16_VALUE(   143.38) },
      { SIMDE_FLOAT16_VALUE(    84.62), SIMDE_FLOAT16_VALUE(   -98.56), SIMDE_FLOAT16_VALUE(  -141.62), SIMDE_FLOAT16_VALUE(    64.75) },
      { SIMDE_FLOAT16_VALUE(   138.50), SIMDE_FLOAT16_VALUE(   129.38), SIMDE_FLOAT16_VALUE(    98.62), SIMDE_FLOAT16_VALUE(   -71.50) },
       INT32_C(           0),
      { SIMDE_FLOAT16_VALUE(-11904.00), SIMDE_FLOAT16_VALUE(-10984.00), SIMDE_FLOAT16_VALUE( 19424.00), SIMDE_FLOAT16_VALUE( 18464.00) } },
    { { SIMDE_FLOAT16_VALUE(    94.12), SIMDE_FLOAT16_VALUE(   -21.59), SIMDE_FLOAT16_VALUE(  -123.00), SIMDE_FLOAT16_VALUE(   170.38) },
      { SIMDE_FLOAT16_VALUE(   141.25), SIMDE_FLOAT16_VALUE(  -136.50), SIMDE_FLOAT16_VALUE(   166.50), SIMDE_FLOAT16_VALUE(   -32.62) },
      { SIMDE_FLOAT16_VALUE(   -16.20), SIMDE_FLOAT16_VALUE(   108.44), SIMDE_FLOAT16_VALUE(   104.00), SIMDE_FLOAT16_VALUE(    70.06) },
       INT32_C(           1),
      { SIMDE_FLOAT16_VALUE(-14592.00), SIMDE_FLOAT16_VALUE( -9920.00), SIMDE_FLOAT16_VALUE(-17440.00), SIMDE_FLOAT16_VALUE(-11496.00) } },
    { { SIMDE_FLOAT16_VALUE(   142.50), SIMDE_FLOAT16_VALUE(   -68.81), SIMDE_FLOAT16_VALUE(  -149.00), SIMDE_FLOAT16_VALUE(     9.88) },
      { SIMDE_FLOAT16_VALUE(   122.44), SIMDE_FLOAT16_VALUE(    -8.40), SIMDE_FLOAT16_VALUE(   -45.00), SIMDE_FLOAT16_VALUE(  -128.38) },
      { SIMDE_FLOAT16_VALUE(   -92.25), SIMDE_FLOAT16_VALUE(   192.88), SIMDE_FLOAT16_VALUE(  -112.56), SIMDE_FLOAT16_VALUE(   141.25) },
       INT32_C(           0),
      { SIMDE_FLOAT16_VALUE( 11440.00), SIMDE_FLOAT16_VALUE(-23680.00), SIMDE_FLOAT16_VALUE( -4300.00), SIMDE_FLOAT16_VALUE(  8688.00) } },
    { { SIMDE_FLOAT16_VALUE(   166.25), SIMDE_FLOAT16_VALUE(   -46.25), SIMDE_FLOAT16_VALUE(   124.88), SIMDE_FLOAT16_VALUE(    -7.83) },
      { SIMDE_FLOAT16_VALUE(   -36.41), SIMDE_FLOAT16_VALUE(  -176.12), SIMDE_FLOAT16_VALUE(    56.00), SIMDE_FLOAT16_VALUE(  -134.88) },
      { SIMDE_FLOAT16_VALUE(   -24.69), SIMDE_FLOAT16_VALUE(    12.76), SIMDE_FLOAT16_VALUE(    31.98), SIMDE_FLOAT16_VALUE(   -28.44) },
       INT32_C(           1),
      { SIMDE_FLOAT16_VALUE(  1331.00), SIMDE_FLOAT16_VALUE( -1082.00), SIMDE_FLOAT16_VALUE( -1666.00), SIMDE_FLOAT16_VALUE(  1585.00) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x4_t r_ = simde_vld1_f16(test_vec[i].r_);
    simde_float16x4_t a = simde_vld1_f16(test_vec[i].a);
    simde_float16x4_t b = simde_vld1_f16(test_vec[i].b);
    simde_float16x4_t r;
    switch(i & 1) {
      case 0:
        r = simde_vcmla_rot180_lane_f16(r_, a, b, 0);
        break;
      case 1:
        r = simde_vcmla_rot180_lane_f16(r_, a, b, 1);
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
      r = simde_vcmla_rot180_lane_f16(r_, a, b, 1);
    else
      r = simde_vcmla_rot180_lane_f16(r_, a, b, 0);


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
test_simde_vcmla_rot180_lane_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32_t r_[2];
    simde_float32_t a[2];
    simde_float32_t b[2];
    const int lane;
    simde_float32_t r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -136.89), SIMDE_FLOAT32_C(  -636.06) },
      { SIMDE_FLOAT32_C(  -194.40), SIMDE_FLOAT32_C(   709.50) },
      { SIMDE_FLOAT32_C(   484.49), SIMDE_FLOAT32_C(   840.67) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C( 94047.96), SIMDE_FLOAT32_C(162790.17) } },
    { { SIMDE_FLOAT32_C(  -852.00), SIMDE_FLOAT32_C(   364.27) },
      { SIMDE_FLOAT32_C(   208.73), SIMDE_FLOAT32_C(   109.98) },
      { SIMDE_FLOAT32_C(   508.80), SIMDE_FLOAT32_C(  -574.50) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C(-107053.82), SIMDE_FLOAT32_C(120279.66) } },
    { { SIMDE_FLOAT32_C(   329.52), SIMDE_FLOAT32_C(   312.53) },
      { SIMDE_FLOAT32_C(   635.65), SIMDE_FLOAT32_C(  -661.11) },
      { SIMDE_FLOAT32_C(   764.98), SIMDE_FLOAT32_C(  -966.47) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C(-485930.03), SIMDE_FLOAT32_C(614649.19) } },
    { { SIMDE_FLOAT32_C(   576.27), SIMDE_FLOAT32_C(  -609.61) },
      { SIMDE_FLOAT32_C(   336.47), SIMDE_FLOAT32_C(  -940.30) },
      { SIMDE_FLOAT32_C(   341.27), SIMDE_FLOAT32_C(  -195.49) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C(-114250.84), SIMDE_FLOAT32_C( 65166.91) } },
    { { SIMDE_FLOAT32_C(   332.30), SIMDE_FLOAT32_C(  -974.30) },
      { SIMDE_FLOAT32_C(   916.36), SIMDE_FLOAT32_C(  -730.58) },
      { SIMDE_FLOAT32_C(  -779.11), SIMDE_FLOAT32_C(  -484.20) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C(714277.50), SIMDE_FLOAT32_C(442727.22) } },
    { { SIMDE_FLOAT32_C(    82.12), SIMDE_FLOAT32_C(   120.75) },
      { SIMDE_FLOAT32_C(  -616.60), SIMDE_FLOAT32_C(   724.25) },
      { SIMDE_FLOAT32_C(   482.35), SIMDE_FLOAT32_C(   819.40) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C(297499.12), SIMDE_FLOAT32_C(505362.78) } },
    { { SIMDE_FLOAT32_C(  -361.90), SIMDE_FLOAT32_C(  -422.61) },
      { SIMDE_FLOAT32_C(  -873.26), SIMDE_FLOAT32_C(  -804.10) },
      { SIMDE_FLOAT32_C(  -532.15), SIMDE_FLOAT32_C(   133.05) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C(-465067.25), SIMDE_FLOAT32_C(115764.64) } },
    { { SIMDE_FLOAT32_C(   169.17), SIMDE_FLOAT32_C(  -718.75) },
      { SIMDE_FLOAT32_C(   -21.95), SIMDE_FLOAT32_C(  -914.86) },
      { SIMDE_FLOAT32_C(   -97.11), SIMDE_FLOAT32_C(  -182.15) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C( -1962.39), SIMDE_FLOAT32_C( -4716.94) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t r_ = simde_vld1_f32(test_vec[i].r_);
    simde_float32x2_t a = simde_vld1_f32(test_vec[i].a);
    simde_float32x2_t b = simde_vld1_f32(test_vec[i].b);
    simde_float32x2_t r = simde_vcmla_rot180_lane_f32(r_, a, b, 0);
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
    simde_float32x2_t r = simde_vcmla_rot180_lane_f32(r_, a, b, 0);


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
test_simde_vcmla_rot180_laneq_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16_t r_[4];
    simde_float16_t a[4];
    simde_float16_t b[8];
    const int lane;
    simde_float16_t r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT16_VALUE(   134.50), SIMDE_FLOAT16_VALUE(   163.38), SIMDE_FLOAT16_VALUE(   -93.06), SIMDE_FLOAT16_VALUE(    30.12) },
      { SIMDE_FLOAT16_VALUE(   171.62), SIMDE_FLOAT16_VALUE(  -174.00), SIMDE_FLOAT16_VALUE(   122.81), SIMDE_FLOAT16_VALUE(  -160.88) },
      { SIMDE_FLOAT16_VALUE(  -193.88), SIMDE_FLOAT16_VALUE(   -35.88), SIMDE_FLOAT16_VALUE(   -29.69), SIMDE_FLOAT16_VALUE(   -98.69),
        SIMDE_FLOAT16_VALUE(    51.56), SIMDE_FLOAT16_VALUE(    26.86), SIMDE_FLOAT16_VALUE(  -109.12), SIMDE_FLOAT16_VALUE(   -58.03) },
       INT32_C(           0),
      { SIMDE_FLOAT16_VALUE( 33408.00), SIMDE_FLOAT16_VALUE(  6320.00), SIMDE_FLOAT16_VALUE( 23712.00), SIMDE_FLOAT16_VALUE(  4436.00) } },
    { { SIMDE_FLOAT16_VALUE(  -170.12), SIMDE_FLOAT16_VALUE(   -48.28), SIMDE_FLOAT16_VALUE(  -152.50), SIMDE_FLOAT16_VALUE(    59.97) },
      { SIMDE_FLOAT16_VALUE(   169.50), SIMDE_FLOAT16_VALUE(   174.12), SIMDE_FLOAT16_VALUE(  -171.50), SIMDE_FLOAT16_VALUE(   165.12) },
      { SIMDE_FLOAT16_VALUE(  -159.62), SIMDE_FLOAT16_VALUE(   122.88), SIMDE_FLOAT16_VALUE(   -74.25), SIMDE_FLOAT16_VALUE(  -174.50),
        SIMDE_FLOAT16_VALUE(    45.62), SIMDE_FLOAT16_VALUE(   -78.75), SIMDE_FLOAT16_VALUE(  -182.88), SIMDE_FLOAT16_VALUE(   197.88) },
       INT32_C(           1),
      { SIMDE_FLOAT16_VALUE( 12416.00), SIMDE_FLOAT16_VALUE( 29536.00), SIMDE_FLOAT16_VALUE(-12888.00), SIMDE_FLOAT16_VALUE(-29872.00) } },
    { { SIMDE_FLOAT16_VALUE(    18.64), SIMDE_FLOAT16_VALUE(    58.34), SIMDE_FLOAT16_VALUE(   155.12), SIMDE_FLOAT16_VALUE(   137.88) },
      { SIMDE_FLOAT16_VALUE(  -174.50), SIMDE_FLOAT16_VALUE(   -94.88), SIMDE_FLOAT16_VALUE(  -199.50), SIMDE_FLOAT16_VALUE(   126.06) },
      { SIMDE_FLOAT16_VALUE(    24.88), SIMDE_FLOAT16_VALUE(  -187.75), SIMDE_FLOAT16_VALUE(   134.50), SIMDE_FLOAT16_VALUE(   172.12),
        SIMDE_FLOAT16_VALUE(  -178.00), SIMDE_FLOAT16_VALUE(  -115.88), SIMDE_FLOAT16_VALUE(  -123.75), SIMDE_FLOAT16_VALUE(    -7.63) },
       INT32_C(           0),
      { SIMDE_FLOAT16_VALUE(  4360.00), SIMDE_FLOAT16_VALUE(-32704.00), SIMDE_FLOAT16_VALUE(  5116.00), SIMDE_FLOAT16_VALUE(-37312.00) } },
    { { SIMDE_FLOAT16_VALUE(   165.12), SIMDE_FLOAT16_VALUE(  -170.25), SIMDE_FLOAT16_VALUE(    86.00), SIMDE_FLOAT16_VALUE(    54.69) },
      { SIMDE_FLOAT16_VALUE(   -65.81), SIMDE_FLOAT16_VALUE(  -194.00), SIMDE_FLOAT16_VALUE(   139.50), SIMDE_FLOAT16_VALUE(   -14.27) },
      { SIMDE_FLOAT16_VALUE(   172.75), SIMDE_FLOAT16_VALUE(  -132.62), SIMDE_FLOAT16_VALUE(  -152.12), SIMDE_FLOAT16_VALUE(   129.12),
        SIMDE_FLOAT16_VALUE(   178.12), SIMDE_FLOAT16_VALUE(  -166.75), SIMDE_FLOAT16_VALUE(    46.34), SIMDE_FLOAT16_VALUE(   -25.30) },
       INT32_C(           1),
      { SIMDE_FLOAT16_VALUE( -9848.00), SIMDE_FLOAT16_VALUE(  8328.00), SIMDE_FLOAT16_VALUE( 21312.00), SIMDE_FLOAT16_VALUE(-17952.00) } },
    { { SIMDE_FLOAT16_VALUE(   120.62), SIMDE_FLOAT16_VALUE(  -188.62), SIMDE_FLOAT16_VALUE(   -52.22), SIMDE_FLOAT16_VALUE(  -190.75) },
      { SIMDE_FLOAT16_VALUE(   -54.34), SIMDE_FLOAT16_VALUE(  -122.69), SIMDE_FLOAT16_VALUE(    31.20), SIMDE_FLOAT16_VALUE(    94.81) },
      { SIMDE_FLOAT16_VALUE(    53.19), SIMDE_FLOAT16_VALUE(   -47.53), SIMDE_FLOAT16_VALUE(   -35.94), SIMDE_FLOAT16_VALUE(   -49.28),
        SIMDE_FLOAT16_VALUE(   -62.03), SIMDE_FLOAT16_VALUE(    39.78), SIMDE_FLOAT16_VALUE(   -49.56), SIMDE_FLOAT16_VALUE(   -25.30) },
       INT32_C(           0),
      { SIMDE_FLOAT16_VALUE(  3012.00), SIMDE_FLOAT16_VALUE( -2772.00), SIMDE_FLOAT16_VALUE( -1712.00), SIMDE_FLOAT16_VALUE(  1292.00) } },
    { { SIMDE_FLOAT16_VALUE(    60.12), SIMDE_FLOAT16_VALUE(   -70.50), SIMDE_FLOAT16_VALUE(   123.12), SIMDE_FLOAT16_VALUE(    10.71) },
      { SIMDE_FLOAT16_VALUE(    81.12), SIMDE_FLOAT16_VALUE(  -102.06), SIMDE_FLOAT16_VALUE(    13.96), SIMDE_FLOAT16_VALUE(  -186.38) },
      { SIMDE_FLOAT16_VALUE(    35.41), SIMDE_FLOAT16_VALUE(   -75.88), SIMDE_FLOAT16_VALUE(   199.75), SIMDE_FLOAT16_VALUE(    77.69),
        SIMDE_FLOAT16_VALUE(    40.62), SIMDE_FLOAT16_VALUE(    25.03), SIMDE_FLOAT16_VALUE(   -65.25), SIMDE_FLOAT16_VALUE(  -184.00) },
       INT32_C(           1),
      { SIMDE_FLOAT16_VALUE(-16144.00), SIMDE_FLOAT16_VALUE( -6372.00), SIMDE_FLOAT16_VALUE( -2666.00), SIMDE_FLOAT16_VALUE( -1074.00) } },
    { { SIMDE_FLOAT16_VALUE(  -187.62), SIMDE_FLOAT16_VALUE(    28.69), SIMDE_FLOAT16_VALUE(  -173.12), SIMDE_FLOAT16_VALUE(   173.75) },
      { SIMDE_FLOAT16_VALUE(    48.53), SIMDE_FLOAT16_VALUE(    94.31), SIMDE_FLOAT16_VALUE(    95.69), SIMDE_FLOAT16_VALUE(  -116.12) },
      { SIMDE_FLOAT16_VALUE(  -157.75), SIMDE_FLOAT16_VALUE(   -13.77), SIMDE_FLOAT16_VALUE(   184.75), SIMDE_FLOAT16_VALUE(  -192.75),
        SIMDE_FLOAT16_VALUE(  -101.62), SIMDE_FLOAT16_VALUE(   -17.31), SIMDE_FLOAT16_VALUE(  -117.00), SIMDE_FLOAT16_VALUE(  -165.12) },
       INT32_C(           0),
      { SIMDE_FLOAT16_VALUE(  7468.00), SIMDE_FLOAT16_VALUE(   697.00), SIMDE_FLOAT16_VALUE( 14920.00), SIMDE_FLOAT16_VALUE(  1492.00) } },
    { { SIMDE_FLOAT16_VALUE(    60.62), SIMDE_FLOAT16_VALUE(   -34.03), SIMDE_FLOAT16_VALUE(   102.75), SIMDE_FLOAT16_VALUE(   -14.29) },
      { SIMDE_FLOAT16_VALUE(  -141.50), SIMDE_FLOAT16_VALUE(    46.38), SIMDE_FLOAT16_VALUE(   169.50), SIMDE_FLOAT16_VALUE(   108.25) },
      { SIMDE_FLOAT16_VALUE(    29.31), SIMDE_FLOAT16_VALUE(    58.56), SIMDE_FLOAT16_VALUE(   198.00), SIMDE_FLOAT16_VALUE(   169.38),
        SIMDE_FLOAT16_VALUE(   181.00), SIMDE_FLOAT16_VALUE(   179.00), SIMDE_FLOAT16_VALUE(  -148.00), SIMDE_FLOAT16_VALUE(   156.50) },
       INT32_C(           1),
      { SIMDE_FLOAT16_VALUE( 28080.00), SIMDE_FLOAT16_VALUE( 23936.00), SIMDE_FLOAT16_VALUE(-33472.00), SIMDE_FLOAT16_VALUE(-28720.00) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x4_t r_ = simde_vld1_f16(test_vec[i].r_);
    simde_float16x4_t a = simde_vld1_f16(test_vec[i].a);
    simde_float16x8_t b = simde_vld1q_f16(test_vec[i].b);
    simde_float16x4_t r;
    switch(i & 1) {
      case 0:
        r = simde_vcmla_rot180_laneq_f16(r_, a, b, 0);
        break;
      case 1:
        r = simde_vcmla_rot180_laneq_f16(r_, a, b, 1);
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
      r = simde_vcmla_rot180_laneq_f16(r_, a, b, 1);
    else
      r = simde_vcmla_rot180_laneq_f16(r_, a, b, 0);


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
test_simde_vcmla_rot180_laneq_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32_t r_[2];
    simde_float32_t a[2];
    simde_float32_t b[4];
    const int lane;
    simde_float32_t r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -797.17), SIMDE_FLOAT32_C(     5.93) },
      { SIMDE_FLOAT32_C(  -324.87), SIMDE_FLOAT32_C(  -117.00) },
      { SIMDE_FLOAT32_C(  -448.35), SIMDE_FLOAT32_C(   560.70), SIMDE_FLOAT32_C(  -288.40), SIMDE_FLOAT32_C(   937.95) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C(-146452.64), SIMDE_FLOAT32_C(182160.55) } },
    { { SIMDE_FLOAT32_C(   152.50), SIMDE_FLOAT32_C(  -986.86) },
      { SIMDE_FLOAT32_C(   -79.47), SIMDE_FLOAT32_C(   326.97) },
      { SIMDE_FLOAT32_C(  -556.99), SIMDE_FLOAT32_C(   667.30), SIMDE_FLOAT32_C(  -728.22), SIMDE_FLOAT32_C(   727.26) },
       INT32_C(           1),
      { SIMDE_FLOAT32_C(-57719.14), SIMDE_FLOAT32_C( 56808.49) } },
    { { SIMDE_FLOAT32_C(  -934.17), SIMDE_FLOAT32_C(  -569.82) },
      { SIMDE_FLOAT32_C(  -976.22), SIMDE_FLOAT32_C(   613.84) },
      { SIMDE_FLOAT32_C(   728.79), SIMDE_FLOAT32_C(   836.48), SIMDE_FLOAT32_C(   795.90), SIMDE_FLOAT32_C(   717.49) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C(710525.19), SIMDE_FLOAT32_C(816018.62) } },
    { { SIMDE_FLOAT32_C(   850.93), SIMDE_FLOAT32_C(  -377.39) },
      { SIMDE_FLOAT32_C(  -792.69), SIMDE_FLOAT32_C(  -785.92) },
      { SIMDE_FLOAT32_C(  -900.54), SIMDE_FLOAT32_C(   697.48), SIMDE_FLOAT32_C(   520.98), SIMDE_FLOAT32_C(    81.06) },
       INT32_C(           1),
      { SIMDE_FLOAT32_C(413826.56), SIMDE_FLOAT32_C( 63878.06) } },
    { { SIMDE_FLOAT32_C(   405.20), SIMDE_FLOAT32_C(   129.21) },
      { SIMDE_FLOAT32_C(  -326.12), SIMDE_FLOAT32_C(   885.93) },
      { SIMDE_FLOAT32_C(  -181.72), SIMDE_FLOAT32_C(  -245.21), SIMDE_FLOAT32_C(   701.37), SIMDE_FLOAT32_C(   -38.15) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C(-58857.32), SIMDE_FLOAT32_C(-79838.68) } },
    { { SIMDE_FLOAT32_C(   871.95), SIMDE_FLOAT32_C(   800.00) },
      { SIMDE_FLOAT32_C(  -431.50), SIMDE_FLOAT32_C(  -186.98) },
      { SIMDE_FLOAT32_C(  -609.18), SIMDE_FLOAT32_C(  -483.32), SIMDE_FLOAT32_C(   824.98), SIMDE_FLOAT32_C(  -623.14) },
       INT32_C(           1),
      { SIMDE_FLOAT32_C(356850.81), SIMDE_FLOAT32_C(-268084.91) } },
    { { SIMDE_FLOAT32_C(   864.24), SIMDE_FLOAT32_C(  -758.94) },
      { SIMDE_FLOAT32_C(   503.69), SIMDE_FLOAT32_C(  -565.03) },
      { SIMDE_FLOAT32_C(  -442.46), SIMDE_FLOAT32_C(  -443.13), SIMDE_FLOAT32_C(   296.87), SIMDE_FLOAT32_C(  -538.92) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C(223726.92), SIMDE_FLOAT32_C(222441.22) } },
    { { SIMDE_FLOAT32_C(   438.30), SIMDE_FLOAT32_C(   568.60) },
      { SIMDE_FLOAT32_C(   492.19), SIMDE_FLOAT32_C(   217.88) },
      { SIMDE_FLOAT32_C(   -94.63), SIMDE_FLOAT32_C(  -413.27), SIMDE_FLOAT32_C(   185.95), SIMDE_FLOAT32_C(  -785.46) },
       INT32_C(           1),
      { SIMDE_FLOAT32_C(-91084.43), SIMDE_FLOAT32_C(387164.16) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t r_ = simde_vld1_f32(test_vec[i].r_);
    simde_float32x2_t a = simde_vld1_f32(test_vec[i].a);
    simde_float32x4_t b = simde_vld1q_f32(test_vec[i].b);
    simde_float32x2_t r;
    switch(i & 1) {
      case 0:
        r = simde_vcmla_rot180_laneq_f32(r_, a, b, 0);
        break;
      case 1:
        r = simde_vcmla_rot180_laneq_f32(r_, a, b, 1);
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
      r = simde_vcmla_rot180_laneq_f32(r_, a, b, 1);
    else
      r = simde_vcmla_rot180_laneq_f32(r_, a, b, 0);


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
test_simde_vcmlaq_rot180_lane_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16_t r_[8];
    simde_float16_t a[8];
    simde_float16_t b[4];
    const int lane;
    simde_float16_t r[8];
  } test_vec[] = {
    { { SIMDE_FLOAT16_VALUE(   241.38), SIMDE_FLOAT16_VALUE(   289.50), SIMDE_FLOAT16_VALUE(  -145.00), SIMDE_FLOAT16_VALUE(   -83.25),
        SIMDE_FLOAT16_VALUE(  -276.50), SIMDE_FLOAT16_VALUE(  -108.69), SIMDE_FLOAT16_VALUE(  -129.25), SIMDE_FLOAT16_VALUE(    -3.50) },
      { SIMDE_FLOAT16_VALUE(   -23.16), SIMDE_FLOAT16_VALUE(    77.31), SIMDE_FLOAT16_VALUE(    99.50), SIMDE_FLOAT16_VALUE(   172.25),
        SIMDE_FLOAT16_VALUE(   169.50), SIMDE_FLOAT16_VALUE(  -183.50), SIMDE_FLOAT16_VALUE(  -275.25), SIMDE_FLOAT16_VALUE(   285.00) },
      { SIMDE_FLOAT16_VALUE(   201.25), SIMDE_FLOAT16_VALUE(   137.38), SIMDE_FLOAT16_VALUE(  -189.75), SIMDE_FLOAT16_VALUE(    68.44) },
       INT32_C(           0),
      { SIMDE_FLOAT16_VALUE(  4900.00), SIMDE_FLOAT16_VALUE(  3470.00), SIMDE_FLOAT16_VALUE(-20176.00), SIMDE_FLOAT16_VALUE(-13752.00),
        SIMDE_FLOAT16_VALUE(-34400.00), SIMDE_FLOAT16_VALUE(-23392.00), SIMDE_FLOAT16_VALUE( 55264.00), SIMDE_FLOAT16_VALUE( 37824.00) } },
    { { SIMDE_FLOAT16_VALUE(    -5.71), SIMDE_FLOAT16_VALUE(   -46.78), SIMDE_FLOAT16_VALUE(   -30.50), SIMDE_FLOAT16_VALUE(  -159.50),
        SIMDE_FLOAT16_VALUE(  -203.12), SIMDE_FLOAT16_VALUE(    62.31), SIMDE_FLOAT16_VALUE(   195.50), SIMDE_FLOAT16_VALUE(  -234.38) },
      { SIMDE_FLOAT16_VALUE(   -10.46), SIMDE_FLOAT16_VALUE(   -83.75), SIMDE_FLOAT16_VALUE(   135.88), SIMDE_FLOAT16_VALUE(   -57.03),
        SIMDE_FLOAT16_VALUE(  -149.38), SIMDE_FLOAT16_VALUE(   262.50), SIMDE_FLOAT16_VALUE(    48.62), SIMDE_FLOAT16_VALUE(  -272.25) },
      { SIMDE_FLOAT16_VALUE(   -59.69), SIMDE_FLOAT16_VALUE(   195.88), SIMDE_FLOAT16_VALUE(   -80.06), SIMDE_FLOAT16_VALUE(  -210.88) },
       INT32_C(           1),
      { SIMDE_FLOAT16_VALUE(  -843.00), SIMDE_FLOAT16_VALUE( -2252.00), SIMDE_FLOAT16_VALUE( 10848.00), SIMDE_FLOAT16_VALUE( 28496.00),
        SIMDE_FLOAT16_VALUE(-12160.00), SIMDE_FLOAT16_VALUE(-31440.00), SIMDE_FLOAT16_VALUE(  4088.00), SIMDE_FLOAT16_VALUE( 10016.00) } },
    { { SIMDE_FLOAT16_VALUE(  -200.62), SIMDE_FLOAT16_VALUE(    66.00), SIMDE_FLOAT16_VALUE(   -11.95), SIMDE_FLOAT16_VALUE(   102.44),
        SIMDE_FLOAT16_VALUE(   142.50), SIMDE_FLOAT16_VALUE(    70.94), SIMDE_FLOAT16_VALUE(  -291.50), SIMDE_FLOAT16_VALUE(  -123.19) },
      { SIMDE_FLOAT16_VALUE(    76.25), SIMDE_FLOAT16_VALUE(   234.50), SIMDE_FLOAT16_VALUE(   257.00), SIMDE_FLOAT16_VALUE(   195.12),
        SIMDE_FLOAT16_VALUE(    -6.41), SIMDE_FLOAT16_VALUE(   297.50), SIMDE_FLOAT16_VALUE(  -200.38), SIMDE_FLOAT16_VALUE(    69.62) },
      { SIMDE_FLOAT16_VALUE(  -237.12), SIMDE_FLOAT16_VALUE(  -169.62), SIMDE_FLOAT16_VALUE(   109.94), SIMDE_FLOAT16_VALUE(  -103.62) },
       INT32_C(           0),
      { SIMDE_FLOAT16_VALUE( 17888.00), SIMDE_FLOAT16_VALUE( 13000.00), SIMDE_FLOAT16_VALUE( 60928.00), SIMDE_FLOAT16_VALUE( 43712.00),
        SIMDE_FLOAT16_VALUE( -1378.00), SIMDE_FLOAT16_VALUE( -1016.50), SIMDE_FLOAT16_VALUE(-47808.00), SIMDE_FLOAT16_VALUE(-34112.00) } },
    { { SIMDE_FLOAT16_VALUE(  -198.38), SIMDE_FLOAT16_VALUE(    12.84), SIMDE_FLOAT16_VALUE(  -224.25), SIMDE_FLOAT16_VALUE(   101.88),
        SIMDE_FLOAT16_VALUE(   297.25), SIMDE_FLOAT16_VALUE(   212.00), SIMDE_FLOAT16_VALUE(   114.56), SIMDE_FLOAT16_VALUE(  -224.38) },
      { SIMDE_FLOAT16_VALUE(   265.25), SIMDE_FLOAT16_VALUE(  -126.88), SIMDE_FLOAT16_VALUE(  -208.75), SIMDE_FLOAT16_VALUE(   263.50),
        SIMDE_FLOAT16_VALUE(  -118.75), SIMDE_FLOAT16_VALUE(  -281.25), SIMDE_FLOAT16_VALUE(  -198.12), SIMDE_FLOAT16_VALUE(   257.00) },
      { SIMDE_FLOAT16_VALUE(  -148.25), SIMDE_FLOAT16_VALUE(   120.88), SIMDE_FLOAT16_VALUE(   109.94), SIMDE_FLOAT16_VALUE(   125.94) },
       INT32_C(           1),
      { SIMDE_FLOAT16_VALUE(-29360.00), SIMDE_FLOAT16_VALUE(-33408.00), SIMDE_FLOAT16_VALUE( 22720.00), SIMDE_FLOAT16_VALUE( 26384.00),
        SIMDE_FLOAT16_VALUE( 13352.00), SIMDE_FLOAT16_VALUE( 15168.00), SIMDE_FLOAT16_VALUE( 21888.00), SIMDE_FLOAT16_VALUE( 24720.00) } },
    { { SIMDE_FLOAT16_VALUE(   265.50), SIMDE_FLOAT16_VALUE(   -89.31), SIMDE_FLOAT16_VALUE(   281.50), SIMDE_FLOAT16_VALUE(   215.38),
        SIMDE_FLOAT16_VALUE(    71.38), SIMDE_FLOAT16_VALUE(   171.50), SIMDE_FLOAT16_VALUE(  -224.00), SIMDE_FLOAT16_VALUE(     5.07) },
      { SIMDE_FLOAT16_VALUE(    76.50), SIMDE_FLOAT16_VALUE(  -233.62), SIMDE_FLOAT16_VALUE(     6.55), SIMDE_FLOAT16_VALUE(  -258.50),
        SIMDE_FLOAT16_VALUE(  -230.50), SIMDE_FLOAT16_VALUE(   158.25), SIMDE_FLOAT16_VALUE(  -120.12), SIMDE_FLOAT16_VALUE(   288.00) },
      { SIMDE_FLOAT16_VALUE(   293.50), SIMDE_FLOAT16_VALUE(   -95.25), SIMDE_FLOAT16_VALUE(   240.12), SIMDE_FLOAT16_VALUE(   147.75) },
       INT32_C(           0),
      { SIMDE_FLOAT16_VALUE(-22192.00), SIMDE_FLOAT16_VALUE(  7196.00), SIMDE_FLOAT16_VALUE( -1641.00), SIMDE_FLOAT16_VALUE(   839.50),
             SIMDE_INFINITYHF, SIMDE_FLOAT16_VALUE(-21776.00), SIMDE_FLOAT16_VALUE( 35040.00), SIMDE_FLOAT16_VALUE(-11440.00) } },
    { { SIMDE_FLOAT16_VALUE(    38.34), SIMDE_FLOAT16_VALUE(    10.60), SIMDE_FLOAT16_VALUE(   -49.91), SIMDE_FLOAT16_VALUE(   198.00),
        SIMDE_FLOAT16_VALUE(   -78.44), SIMDE_FLOAT16_VALUE(  -163.50), SIMDE_FLOAT16_VALUE(   -70.12), SIMDE_FLOAT16_VALUE(   189.12) },
      { SIMDE_FLOAT16_VALUE(   245.25), SIMDE_FLOAT16_VALUE(   -82.62), SIMDE_FLOAT16_VALUE(  -131.50), SIMDE_FLOAT16_VALUE(   136.25),
        SIMDE_FLOAT16_VALUE(   255.00), SIMDE_FLOAT16_VALUE(   108.19), SIMDE_FLOAT16_VALUE(   222.62), SIMDE_FLOAT16_VALUE(   251.62) },
      { SIMDE_FLOAT16_VALUE(  -117.38), SIMDE_FLOAT16_VALUE(   -91.12), SIMDE_FLOAT16_VALUE(    14.67), SIMDE_FLOAT16_VALUE(  -101.50) },
       INT32_C(           1),
      { SIMDE_FLOAT16_VALUE( -3560.00), SIMDE_FLOAT16_VALUE( 24896.00), SIMDE_FLOAT16_VALUE(  1879.00), SIMDE_FLOAT16_VALUE(-13152.00),
        SIMDE_FLOAT16_VALUE( -3820.00), SIMDE_FLOAT16_VALUE( 25712.00), SIMDE_FLOAT16_VALUE( -3336.00), SIMDE_FLOAT16_VALUE( 22784.00) } },
    { { SIMDE_FLOAT16_VALUE(  -259.75), SIMDE_FLOAT16_VALUE(  -195.25), SIMDE_FLOAT16_VALUE(   117.06), SIMDE_FLOAT16_VALUE(   -36.72),
        SIMDE_FLOAT16_VALUE(    69.62), SIMDE_FLOAT16_VALUE(   -87.38), SIMDE_FLOAT16_VALUE(  -212.38), SIMDE_FLOAT16_VALUE(   -82.69) },
      { SIMDE_FLOAT16_VALUE(  -281.25), SIMDE_FLOAT16_VALUE(  -187.00), SIMDE_FLOAT16_VALUE(   232.88), SIMDE_FLOAT16_VALUE(  -222.88),
        SIMDE_FLOAT16_VALUE(  -195.62), SIMDE_FLOAT16_VALUE(   -47.00), SIMDE_FLOAT16_VALUE(  -229.75), SIMDE_FLOAT16_VALUE(   -10.74) },
      { SIMDE_FLOAT16_VALUE(    51.50), SIMDE_FLOAT16_VALUE(   -74.25), SIMDE_FLOAT16_VALUE(   280.75), SIMDE_FLOAT16_VALUE(   105.75) },
       INT32_C(           0),
      { SIMDE_FLOAT16_VALUE( 14224.00), SIMDE_FLOAT16_VALUE(-21072.00), SIMDE_FLOAT16_VALUE(-11872.00), SIMDE_FLOAT16_VALUE( 17248.00),
        SIMDE_FLOAT16_VALUE( 10144.00), SIMDE_FLOAT16_VALUE(-14616.00), SIMDE_FLOAT16_VALUE( 11616.00), SIMDE_FLOAT16_VALUE(-17136.00) } },
    { { SIMDE_FLOAT16_VALUE(  -130.12), SIMDE_FLOAT16_VALUE(   299.50), SIMDE_FLOAT16_VALUE(  -239.62), SIMDE_FLOAT16_VALUE(  -202.50),
        SIMDE_FLOAT16_VALUE(   155.50), SIMDE_FLOAT16_VALUE(   186.62), SIMDE_FLOAT16_VALUE(   163.38), SIMDE_FLOAT16_VALUE(   256.25) },
      { SIMDE_FLOAT16_VALUE(   -54.41), SIMDE_FLOAT16_VALUE(   -54.12), SIMDE_FLOAT16_VALUE(  -168.62), SIMDE_FLOAT16_VALUE(   184.75),
        SIMDE_FLOAT16_VALUE(    59.28), SIMDE_FLOAT16_VALUE(   197.00), SIMDE_FLOAT16_VALUE(   163.62), SIMDE_FLOAT16_VALUE(  -168.38) },
      { SIMDE_FLOAT16_VALUE(   156.50), SIMDE_FLOAT16_VALUE(  -248.88), SIMDE_FLOAT16_VALUE(  -208.50), SIMDE_FLOAT16_VALUE(  -218.12) },
       INT32_C(           1),
      { SIMDE_FLOAT16_VALUE(-11472.00), SIMDE_FLOAT16_VALUE(-11568.00), SIMDE_FLOAT16_VALUE(-35392.00), SIMDE_FLOAT16_VALUE(-36992.00),
        SIMDE_FLOAT16_VALUE( 12512.00), SIMDE_FLOAT16_VALUE( 13120.00), SIMDE_FLOAT16_VALUE( 34272.00), SIMDE_FLOAT16_VALUE( 35936.00) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x8_t r_ = simde_vld1q_f16(test_vec[i].r_);
    simde_float16x8_t a = simde_vld1q_f16(test_vec[i].a);
    simde_float16x4_t b = simde_vld1_f16(test_vec[i].b);
    simde_float16x8_t r;
    switch(i & 1) {
      case 0:
        r = simde_vcmlaq_rot180_lane_f16(r_, a, b, 0);
        break;
      case 1:
        r = simde_vcmlaq_rot180_lane_f16(r_, a, b, 1);
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
      r = simde_vcmlaq_rot180_lane_f16(r_, a, b, 1);
    else
      r = simde_vcmlaq_rot180_lane_f16(r_, a, b, 0);


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
test_simde_vcmlaq_rot180_lane_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32_t r_[4];
    simde_float32_t a[4];
    simde_float32_t b[2];
    const int lane;
    simde_float32_t r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   921.61), SIMDE_FLOAT32_C(  -416.79), SIMDE_FLOAT32_C(   985.29), SIMDE_FLOAT32_C(  -288.65) },
      { SIMDE_FLOAT32_C(   712.56), SIMDE_FLOAT32_C(   -47.02), SIMDE_FLOAT32_C(  -255.47), SIMDE_FLOAT32_C(   383.50) },
      { SIMDE_FLOAT32_C(  -442.37), SIMDE_FLOAT32_C(  -870.02) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C(316136.78), SIMDE_FLOAT32_C(619524.69), SIMDE_FLOAT32_C(-112026.98), SIMDE_FLOAT32_C(-222552.67) } },
    { { SIMDE_FLOAT32_C(  -344.64), SIMDE_FLOAT32_C(  -357.94), SIMDE_FLOAT32_C(    32.12), SIMDE_FLOAT32_C(  -151.14) },
      { SIMDE_FLOAT32_C(  -273.44), SIMDE_FLOAT32_C(   279.83), SIMDE_FLOAT32_C(  -928.81), SIMDE_FLOAT32_C(  -477.10) },
      { SIMDE_FLOAT32_C(  -672.58), SIMDE_FLOAT32_C(  -100.88) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C(-184254.92), SIMDE_FLOAT32_C(-27942.57), SIMDE_FLOAT32_C(-624666.94), SIMDE_FLOAT32_C(-93849.49) } },
    { { SIMDE_FLOAT32_C(   534.22), SIMDE_FLOAT32_C(   661.78), SIMDE_FLOAT32_C(   580.09), SIMDE_FLOAT32_C(  -381.99) },
      { SIMDE_FLOAT32_C(  -123.64), SIMDE_FLOAT32_C(     6.24), SIMDE_FLOAT32_C(   919.81), SIMDE_FLOAT32_C(  -699.03) },
      { SIMDE_FLOAT32_C(  -653.79), SIMDE_FLOAT32_C(  -226.39) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C(-80300.38), SIMDE_FLOAT32_C(-27329.08), SIMDE_FLOAT32_C(601942.62), SIMDE_FLOAT32_C(207853.80) } },
    { { SIMDE_FLOAT32_C(  -979.59), SIMDE_FLOAT32_C(    57.49), SIMDE_FLOAT32_C(   161.16), SIMDE_FLOAT32_C(   625.86) },
      { SIMDE_FLOAT32_C(   820.97), SIMDE_FLOAT32_C(    77.33), SIMDE_FLOAT32_C(  -309.80), SIMDE_FLOAT32_C(  -839.29) },
      { SIMDE_FLOAT32_C(    79.17), SIMDE_FLOAT32_C(   535.69) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C(-65975.78), SIMDE_FLOAT32_C(-439727.91), SIMDE_FLOAT32_C( 24688.03), SIMDE_FLOAT32_C(166582.61) } },
    { { SIMDE_FLOAT32_C(  -688.68), SIMDE_FLOAT32_C(  -579.26), SIMDE_FLOAT32_C(   360.53), SIMDE_FLOAT32_C(  -600.64) },
      { SIMDE_FLOAT32_C(  -941.17), SIMDE_FLOAT32_C(  -174.89), SIMDE_FLOAT32_C(   671.97), SIMDE_FLOAT32_C(  -284.78) },
      { SIMDE_FLOAT32_C(  -231.39), SIMDE_FLOAT32_C(  -969.18) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C(-218466.00), SIMDE_FLOAT32_C(-912742.38), SIMDE_FLOAT32_C(155847.66), SIMDE_FLOAT32_C(650659.19) } },
    { { SIMDE_FLOAT32_C(  -974.36), SIMDE_FLOAT32_C(    -4.19), SIMDE_FLOAT32_C(  -468.29), SIMDE_FLOAT32_C(  -588.32) },
      { SIMDE_FLOAT32_C(   169.98), SIMDE_FLOAT32_C(   934.12), SIMDE_FLOAT32_C(  -296.67), SIMDE_FLOAT32_C(   -98.45) },
      { SIMDE_FLOAT32_C(  -701.48), SIMDE_FLOAT32_C(   280.50) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C(118263.20), SIMDE_FLOAT32_C(-47683.58), SIMDE_FLOAT32_C(-208576.36), SIMDE_FLOAT32_C( 82627.62) } },
    { { SIMDE_FLOAT32_C(   371.59), SIMDE_FLOAT32_C(  -643.26), SIMDE_FLOAT32_C(   784.87), SIMDE_FLOAT32_C(  -679.20) },
      { SIMDE_FLOAT32_C(   755.11), SIMDE_FLOAT32_C(  -796.59), SIMDE_FLOAT32_C(  -263.09), SIMDE_FLOAT32_C(   236.32) },
      { SIMDE_FLOAT32_C(  -194.81), SIMDE_FLOAT32_C(  -137.62) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C(147474.56), SIMDE_FLOAT32_C(103274.97), SIMDE_FLOAT32_C(-50467.69), SIMDE_FLOAT32_C(-36885.64) } },
    { { SIMDE_FLOAT32_C(   967.48), SIMDE_FLOAT32_C(   367.60), SIMDE_FLOAT32_C(   237.88), SIMDE_FLOAT32_C(    29.13) },
      { SIMDE_FLOAT32_C(  -366.29), SIMDE_FLOAT32_C(  -189.76), SIMDE_FLOAT32_C(   703.04), SIMDE_FLOAT32_C(   -55.45) },
      { SIMDE_FLOAT32_C(    78.11), SIMDE_FLOAT32_C(   781.98) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C( 29578.39), SIMDE_FLOAT32_C(286799.06), SIMDE_FLOAT32_C(-54676.57), SIMDE_FLOAT32_C(-549734.06) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t r_ = simde_vld1q_f32(test_vec[i].r_);
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_float32x2_t b = simde_vld1_f32(test_vec[i].b);
    simde_float32x4_t r = simde_vcmlaq_rot180_lane_f32(r_, a, b, 0);
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
    simde_float32x4_t r = simde_vcmlaq_rot180_lane_f32(r_, a, b, 0);


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
test_simde_vcmlaq_rot180_laneq_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16_t r_[8];
    simde_float16_t a[8];
    simde_float16_t b[8];
    const int lane;
    simde_float16_t r[8];
  } test_vec[] = {
    { { SIMDE_FLOAT16_VALUE(   203.62), SIMDE_FLOAT16_VALUE(    11.64), SIMDE_FLOAT16_VALUE(   115.81), SIMDE_FLOAT16_VALUE(   187.50),
        SIMDE_FLOAT16_VALUE(  -140.88), SIMDE_FLOAT16_VALUE(  -132.12), SIMDE_FLOAT16_VALUE(  -191.25), SIMDE_FLOAT16_VALUE(  -257.50) },
      { SIMDE_FLOAT16_VALUE(  -138.50), SIMDE_FLOAT16_VALUE(   153.00), SIMDE_FLOAT16_VALUE(    -1.42), SIMDE_FLOAT16_VALUE(    95.50),
        SIMDE_FLOAT16_VALUE(   149.00), SIMDE_FLOAT16_VALUE(   141.75), SIMDE_FLOAT16_VALUE(   247.75), SIMDE_FLOAT16_VALUE(  -163.12) },
      { SIMDE_FLOAT16_VALUE(   230.50), SIMDE_FLOAT16_VALUE(  -169.38), SIMDE_FLOAT16_VALUE(  -252.50), SIMDE_FLOAT16_VALUE(  -283.00),
        SIMDE_FLOAT16_VALUE(    55.75), SIMDE_FLOAT16_VALUE(   140.75), SIMDE_FLOAT16_VALUE(    -6.22), SIMDE_FLOAT16_VALUE(   -80.88) },
       INT32_C(           0),
      { SIMDE_FLOAT16_VALUE( 32128.00), SIMDE_FLOAT16_VALUE(-23440.00), SIMDE_FLOAT16_VALUE(   443.00), SIMDE_FLOAT16_VALUE(   -53.00),
        SIMDE_FLOAT16_VALUE(-34496.00), SIMDE_FLOAT16_VALUE( 25104.00), SIMDE_FLOAT16_VALUE(-57312.00), SIMDE_FLOAT16_VALUE( 41696.00) } },
    { { SIMDE_FLOAT16_VALUE(    67.06), SIMDE_FLOAT16_VALUE(  -110.75), SIMDE_FLOAT16_VALUE(   172.38), SIMDE_FLOAT16_VALUE(  -201.88),
        SIMDE_FLOAT16_VALUE(  -178.88), SIMDE_FLOAT16_VALUE(   118.50), SIMDE_FLOAT16_VALUE(   104.62), SIMDE_FLOAT16_VALUE(  -180.25) },
      { SIMDE_FLOAT16_VALUE(  -163.00), SIMDE_FLOAT16_VALUE(   165.00), SIMDE_FLOAT16_VALUE(  -192.00), SIMDE_FLOAT16_VALUE(    34.88),
        SIMDE_FLOAT16_VALUE(   254.75), SIMDE_FLOAT16_VALUE(  -249.12), SIMDE_FLOAT16_VALUE(    90.38), SIMDE_FLOAT16_VALUE(   -25.20) },
      { SIMDE_FLOAT16_VALUE(   134.12), SIMDE_FLOAT16_VALUE(   149.38), SIMDE_FLOAT16_VALUE(   -45.34), SIMDE_FLOAT16_VALUE(   185.25),
        SIMDE_FLOAT16_VALUE(  -184.62), SIMDE_FLOAT16_VALUE(  -286.00), SIMDE_FLOAT16_VALUE(  -226.12), SIMDE_FLOAT16_VALUE(   229.00) },
       INT32_C(           1),
      { SIMDE_FLOAT16_VALUE( -7324.00), SIMDE_FLOAT16_VALUE( 30080.00), SIMDE_FLOAT16_VALUE( -8536.00), SIMDE_FLOAT16_VALUE( 35360.00),
        SIMDE_FLOAT16_VALUE( 11376.00), SIMDE_FLOAT16_VALUE(-47072.00), SIMDE_FLOAT16_VALUE(  4204.00), SIMDE_FLOAT16_VALUE(-16928.00) } },
    { { SIMDE_FLOAT16_VALUE(   287.25), SIMDE_FLOAT16_VALUE(   289.25), SIMDE_FLOAT16_VALUE(    98.50), SIMDE_FLOAT16_VALUE(  -186.00),
        SIMDE_FLOAT16_VALUE(   187.38), SIMDE_FLOAT16_VALUE(   164.62), SIMDE_FLOAT16_VALUE(   -29.98), SIMDE_FLOAT16_VALUE(    21.48) },
      { SIMDE_FLOAT16_VALUE(    48.09), SIMDE_FLOAT16_VALUE(    40.69), SIMDE_FLOAT16_VALUE(    39.25), SIMDE_FLOAT16_VALUE(   167.62),
        SIMDE_FLOAT16_VALUE(    70.25), SIMDE_FLOAT16_VALUE(   299.00), SIMDE_FLOAT16_VALUE(   102.56), SIMDE_FLOAT16_VALUE(  -178.62) },
      { SIMDE_FLOAT16_VALUE(   -59.88), SIMDE_FLOAT16_VALUE(   196.75), SIMDE_FLOAT16_VALUE(   -83.75), SIMDE_FLOAT16_VALUE(  -177.00),
        SIMDE_FLOAT16_VALUE(  -161.62), SIMDE_FLOAT16_VALUE(   116.19), SIMDE_FLOAT16_VALUE(   -41.59), SIMDE_FLOAT16_VALUE(   -77.00) },
       INT32_C(           2),
      { SIMDE_FLOAT16_VALUE(  8060.00), SIMDE_FLOAT16_VALUE( -5300.00), SIMDE_FLOAT16_VALUE(  6444.00), SIMDE_FLOAT16_VALUE( -4748.00),
        SIMDE_FLOAT16_VALUE( 11544.00), SIMDE_FLOAT16_VALUE( -7996.00), SIMDE_FLOAT16_VALUE( 16544.00), SIMDE_FLOAT16_VALUE(-11896.00) } },
    { { SIMDE_FLOAT16_VALUE(    32.41), SIMDE_FLOAT16_VALUE(    40.34), SIMDE_FLOAT16_VALUE(    47.16), SIMDE_FLOAT16_VALUE(     6.57),
        SIMDE_FLOAT16_VALUE(   -19.11), SIMDE_FLOAT16_VALUE(  -100.69), SIMDE_FLOAT16_VALUE(  -198.75), SIMDE_FLOAT16_VALUE(  -174.88) },
      { SIMDE_FLOAT16_VALUE(  -116.50), SIMDE_FLOAT16_VALUE(  -167.12), SIMDE_FLOAT16_VALUE(   239.38), SIMDE_FLOAT16_VALUE(  -255.62),
        SIMDE_FLOAT16_VALUE(   263.25), SIMDE_FLOAT16_VALUE(     5.85), SIMDE_FLOAT16_VALUE(   -45.22), SIMDE_FLOAT16_VALUE(   161.00) },
      { SIMDE_FLOAT16_VALUE(  -271.00), SIMDE_FLOAT16_VALUE(   152.62), SIMDE_FLOAT16_VALUE(  -245.00), SIMDE_FLOAT16_VALUE(  -137.25),
        SIMDE_FLOAT16_VALUE(   -23.59), SIMDE_FLOAT16_VALUE(    37.44), SIMDE_FLOAT16_VALUE(   216.62), SIMDE_FLOAT16_VALUE(    81.56) },
       INT32_C(           3),
      { SIMDE_FLOAT16_VALUE( 25264.00), SIMDE_FLOAT16_VALUE(  9544.00), SIMDE_FLOAT16_VALUE(-51808.00), SIMDE_FLOAT16_VALUE(-19520.00),
        SIMDE_FLOAT16_VALUE(-57056.00), SIMDE_FLOAT16_VALUE(-21568.00), SIMDE_FLOAT16_VALUE(  9600.00), SIMDE_FLOAT16_VALUE(  3514.00) } },
    { { SIMDE_FLOAT16_VALUE(  -290.00), SIMDE_FLOAT16_VALUE(   -27.58), SIMDE_FLOAT16_VALUE(  -286.25), SIMDE_FLOAT16_VALUE(   129.00),
        SIMDE_FLOAT16_VALUE(     4.65), SIMDE_FLOAT16_VALUE(   200.12), SIMDE_FLOAT16_VALUE(  -234.38), SIMDE_FLOAT16_VALUE(  -111.00) },
      { SIMDE_FLOAT16_VALUE(   176.38), SIMDE_FLOAT16_VALUE(   296.75), SIMDE_FLOAT16_VALUE(   299.25), SIMDE_FLOAT16_VALUE(   -79.00),
        SIMDE_FLOAT16_VALUE(  -230.25), SIMDE_FLOAT16_VALUE(    54.62), SIMDE_FLOAT16_VALUE(   268.25), SIMDE_FLOAT16_VALUE(  -263.50) },
      { SIMDE_FLOAT16_VALUE(   135.00), SIMDE_FLOAT16_VALUE(     2.77), SIMDE_FLOAT16_VALUE(  -275.25), SIMDE_FLOAT16_VALUE(   -88.50),
        SIMDE_FLOAT16_VALUE(    56.38), SIMDE_FLOAT16_VALUE(  -219.75), SIMDE_FLOAT16_VALUE(   -37.16), SIMDE_FLOAT16_VALUE(   170.88) },
       INT32_C(           0),
      { SIMDE_FLOAT16_VALUE(-24096.00), SIMDE_FLOAT16_VALUE(  -516.00), SIMDE_FLOAT16_VALUE(-40672.00), SIMDE_FLOAT16_VALUE(  -700.00),
        SIMDE_FLOAT16_VALUE( 31088.00), SIMDE_FLOAT16_VALUE(   838.00), SIMDE_FLOAT16_VALUE(-36448.00), SIMDE_FLOAT16_VALUE(  -854.00) } },
    { { SIMDE_FLOAT16_VALUE(   203.12), SIMDE_FLOAT16_VALUE(  -298.75), SIMDE_FLOAT16_VALUE(    21.98), SIMDE_FLOAT16_VALUE(   -96.12),
        SIMDE_FLOAT16_VALUE(    12.51), SIMDE_FLOAT16_VALUE(   230.00), SIMDE_FLOAT16_VALUE(   199.25), SIMDE_FLOAT16_VALUE(  -127.75) },
      { SIMDE_FLOAT16_VALUE(  -248.88), SIMDE_FLOAT16_VALUE(    94.50), SIMDE_FLOAT16_VALUE(   -11.63), SIMDE_FLOAT16_VALUE(    83.19),
        SIMDE_FLOAT16_VALUE(  -160.38), SIMDE_FLOAT16_VALUE(  -140.50), SIMDE_FLOAT16_VALUE(   -13.07), SIMDE_FLOAT16_VALUE(   -82.12) },
      { SIMDE_FLOAT16_VALUE(    26.09), SIMDE_FLOAT16_VALUE(  -123.88), SIMDE_FLOAT16_VALUE(   189.75), SIMDE_FLOAT16_VALUE(   -79.88),
        SIMDE_FLOAT16_VALUE(   232.25), SIMDE_FLOAT16_VALUE(    21.41), SIMDE_FLOAT16_VALUE(  -268.75), SIMDE_FLOAT16_VALUE(  -255.25) },
       INT32_C(           1),
      { SIMDE_FLOAT16_VALUE( 47424.00), SIMDE_FLOAT16_VALUE(-20176.00), SIMDE_FLOAT16_VALUE(  2230.00), SIMDE_FLOAT16_VALUE( -1025.00),
        SIMDE_FLOAT16_VALUE( 30448.00), SIMDE_FLOAT16_VALUE(-12576.00), SIMDE_FLOAT16_VALUE(  2680.00), SIMDE_FLOAT16_VALUE( -1172.00) } },
    { { SIMDE_FLOAT16_VALUE(   179.88), SIMDE_FLOAT16_VALUE(    63.69), SIMDE_FLOAT16_VALUE(   -85.38), SIMDE_FLOAT16_VALUE(    28.23),
        SIMDE_FLOAT16_VALUE(  -186.00), SIMDE_FLOAT16_VALUE(  -282.75), SIMDE_FLOAT16_VALUE(   163.25), SIMDE_FLOAT16_VALUE(   237.62) },
      { SIMDE_FLOAT16_VALUE(  -110.81), SIMDE_FLOAT16_VALUE(   217.50), SIMDE_FLOAT16_VALUE(   216.88), SIMDE_FLOAT16_VALUE(   -71.50),
        SIMDE_FLOAT16_VALUE(   282.25), SIMDE_FLOAT16_VALUE(   241.50), SIMDE_FLOAT16_VALUE(   163.50), SIMDE_FLOAT16_VALUE(   128.62) },
      { SIMDE_FLOAT16_VALUE(   -28.12), SIMDE_FLOAT16_VALUE(    16.30), SIMDE_FLOAT16_VALUE(  -222.62), SIMDE_FLOAT16_VALUE(    16.86),
        SIMDE_FLOAT16_VALUE(   178.88), SIMDE_FLOAT16_VALUE(  -131.12), SIMDE_FLOAT16_VALUE(  -198.62), SIMDE_FLOAT16_VALUE(  -275.25) },
       INT32_C(           2),
      { SIMDE_FLOAT16_VALUE( 20000.00), SIMDE_FLOAT16_VALUE(-14464.00), SIMDE_FLOAT16_VALUE(-38880.00), SIMDE_FLOAT16_VALUE( 28464.00),
        SIMDE_FLOAT16_VALUE(-50688.00), SIMDE_FLOAT16_VALUE( 36736.00), SIMDE_FLOAT16_VALUE(-29088.00), SIMDE_FLOAT16_VALUE( 21680.00) } },
    { { SIMDE_FLOAT16_VALUE(  -184.38), SIMDE_FLOAT16_VALUE(   -14.02), SIMDE_FLOAT16_VALUE(   205.50), SIMDE_FLOAT16_VALUE(  -242.75),
        SIMDE_FLOAT16_VALUE(   145.38), SIMDE_FLOAT16_VALUE(  -141.12), SIMDE_FLOAT16_VALUE(  -189.88), SIMDE_FLOAT16_VALUE(    76.75) },
      { SIMDE_FLOAT16_VALUE(  -146.75), SIMDE_FLOAT16_VALUE(  -195.62), SIMDE_FLOAT16_VALUE(   -79.69), SIMDE_FLOAT16_VALUE(   116.00),
        SIMDE_FLOAT16_VALUE(  -192.12), SIMDE_FLOAT16_VALUE(  -197.75), SIMDE_FLOAT16_VALUE(    52.12), SIMDE_FLOAT16_VALUE(   -12.37) },
      { SIMDE_FLOAT16_VALUE(   249.88), SIMDE_FLOAT16_VALUE(    79.56), SIMDE_FLOAT16_VALUE(   -95.25), SIMDE_FLOAT16_VALUE(  -242.88),
        SIMDE_FLOAT16_VALUE(  -117.94), SIMDE_FLOAT16_VALUE(   291.25), SIMDE_FLOAT16_VALUE(   -14.69), SIMDE_FLOAT16_VALUE(   245.12) },
       INT32_C(           3),
      { SIMDE_FLOAT16_VALUE( -2340.00), SIMDE_FLOAT16_VALUE( 35968.00), SIMDE_FLOAT16_VALUE(  -965.00), SIMDE_FLOAT16_VALUE( 19296.00),
        SIMDE_FLOAT16_VALUE( -2676.00), SIMDE_FLOAT16_VALUE( 46944.00), SIMDE_FLOAT16_VALUE(   575.50), SIMDE_FLOAT16_VALUE(-12704.00) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x8_t r_ = simde_vld1q_f16(test_vec[i].r_);
    simde_float16x8_t a = simde_vld1q_f16(test_vec[i].a);
    simde_float16x8_t b = simde_vld1q_f16(test_vec[i].b);
    simde_float16x8_t r;
    switch(i & 3) {
      case 0:
        r = simde_vcmlaq_rot180_laneq_f16(r_, a, b, 0);
        break;
      case 1:
        r = simde_vcmlaq_rot180_laneq_f16(r_, a, b, 1);
        break;
      case 2:
        r = simde_vcmlaq_rot180_laneq_f16(r_, a, b, 2);
        break;
      case 3:
        r = simde_vcmlaq_rot180_laneq_f16(r_, a, b, 3);
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
    simde_float16x8_t r_ = simde_test_arm_neon_random_f16x8(-300.0f, 300.0f);
    simde_float16x8_t a = simde_test_arm_neon_random_f16x8(-300.0f, 300.0f);
    simde_float16x8_t b = simde_test_arm_neon_random_f16x8(-300.0f, 300.0f);
    simde_float16x8_t r;
    if(i % 4 == 1)
      r = simde_vcmlaq_rot180_laneq_f16(r_, a, b, 1);
    else if(i % 4 == 2)
      r = simde_vcmlaq_rot180_laneq_f16(r_, a, b, 2);
    else if(i % 4 == 3)
      r = simde_vcmlaq_rot180_laneq_f16(r_, a, b, 3);
    else
      r = simde_vcmlaq_rot180_laneq_f16(r_, a, b, 0);


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
test_simde_vcmlaq_rot180_laneq_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32_t r_[4];
    simde_float32_t a[4];
    simde_float32_t b[4];
    const int lane;
    simde_float32_t r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   -80.27), SIMDE_FLOAT32_C(   976.14), SIMDE_FLOAT32_C(    24.05), SIMDE_FLOAT32_C(   171.48) },
      { SIMDE_FLOAT32_C(   102.03), SIMDE_FLOAT32_C(   817.84), SIMDE_FLOAT32_C(  -593.02), SIMDE_FLOAT32_C(  -945.64) },
      { SIMDE_FLOAT32_C(   638.29), SIMDE_FLOAT32_C(  -180.36), SIMDE_FLOAT32_C(   680.85), SIMDE_FLOAT32_C(  -920.46) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C(-65205.00), SIMDE_FLOAT32_C( 19378.27), SIMDE_FLOAT32_C(378542.78), SIMDE_FLOAT32_C(-106785.61) } },
    { { SIMDE_FLOAT32_C(  -166.05), SIMDE_FLOAT32_C(  -785.21), SIMDE_FLOAT32_C(  -951.83), SIMDE_FLOAT32_C(   595.54) },
      { SIMDE_FLOAT32_C(  -699.10), SIMDE_FLOAT32_C(   245.07), SIMDE_FLOAT32_C(   932.97), SIMDE_FLOAT32_C(   374.00) },
      { SIMDE_FLOAT32_C(  -181.48), SIMDE_FLOAT32_C(   -58.07), SIMDE_FLOAT32_C(   -55.82), SIMDE_FLOAT32_C(  -168.35) },
       INT32_C(           1),
      { SIMDE_FLOAT32_C(-39189.81), SIMDE_FLOAT32_C(-118478.70), SIMDE_FLOAT32_C( 51126.55), SIMDE_FLOAT32_C(157661.05) } },
    { { SIMDE_FLOAT32_C(   527.13), SIMDE_FLOAT32_C(  -596.92), SIMDE_FLOAT32_C(  -390.98), SIMDE_FLOAT32_C(   870.87) },
      { SIMDE_FLOAT32_C(   729.80), SIMDE_FLOAT32_C(  -189.01), SIMDE_FLOAT32_C(  -736.92), SIMDE_FLOAT32_C(   522.32) },
      { SIMDE_FLOAT32_C(   700.96), SIMDE_FLOAT32_C(  -974.91), SIMDE_FLOAT32_C(   721.11), SIMDE_FLOAT32_C(  -376.43) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C(-511033.50), SIMDE_FLOAT32_C(710892.38), SIMDE_FLOAT32_C(516160.47), SIMDE_FLOAT32_C(-717559.75) } },
    { { SIMDE_FLOAT32_C(  -720.23), SIMDE_FLOAT32_C(  -838.05), SIMDE_FLOAT32_C(   857.28), SIMDE_FLOAT32_C(   367.90) },
      { SIMDE_FLOAT32_C(  -697.26), SIMDE_FLOAT32_C(  -765.12), SIMDE_FLOAT32_C(   640.39), SIMDE_FLOAT32_C(  -922.29) },
      { SIMDE_FLOAT32_C(  -848.20), SIMDE_FLOAT32_C(   257.82), SIMDE_FLOAT32_C(  -810.33), SIMDE_FLOAT32_C(   798.96) },
       INT32_C(           1),
      { SIMDE_FLOAT32_C(-565730.94), SIMDE_FLOAT32_C(556244.81), SIMDE_FLOAT32_C(519784.53), SIMDE_FLOAT32_C(-511278.12) } },
    { { SIMDE_FLOAT32_C(    65.11), SIMDE_FLOAT32_C(   285.20), SIMDE_FLOAT32_C(  -710.48), SIMDE_FLOAT32_C(  -991.96) },
      { SIMDE_FLOAT32_C(    78.12), SIMDE_FLOAT32_C(  -960.83), SIMDE_FLOAT32_C(  -726.32), SIMDE_FLOAT32_C(   740.91) },
      { SIMDE_FLOAT32_C(   546.70), SIMDE_FLOAT32_C(   422.14), SIMDE_FLOAT32_C(   967.31), SIMDE_FLOAT32_C(  -460.27) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C(-42643.10), SIMDE_FLOAT32_C(-32692.38), SIMDE_FLOAT32_C(396368.69), SIMDE_FLOAT32_C(305616.78) } },
    { { SIMDE_FLOAT32_C(   215.04), SIMDE_FLOAT32_C(   180.49), SIMDE_FLOAT32_C(  -583.85), SIMDE_FLOAT32_C(  -844.59) },
      { SIMDE_FLOAT32_C(  -943.92), SIMDE_FLOAT32_C(  -498.45), SIMDE_FLOAT32_C(   605.42), SIMDE_FLOAT32_C(  -671.16) },
      { SIMDE_FLOAT32_C(  -166.43), SIMDE_FLOAT32_C(   767.17), SIMDE_FLOAT32_C(  -253.99), SIMDE_FLOAT32_C(  -759.46) },
       INT32_C(           1),
      { SIMDE_FLOAT32_C(-239531.20), SIMDE_FLOAT32_C(-716689.00), SIMDE_FLOAT32_C(153186.78), SIMDE_FLOAT32_C(458947.69) } },
    { { SIMDE_FLOAT32_C(  -271.88), SIMDE_FLOAT32_C(   480.81), SIMDE_FLOAT32_C(   910.66), SIMDE_FLOAT32_C(  -580.35) },
      { SIMDE_FLOAT32_C(   -16.63), SIMDE_FLOAT32_C(   466.72), SIMDE_FLOAT32_C(   156.95), SIMDE_FLOAT32_C(  -218.86) },
      { SIMDE_FLOAT32_C(  -340.34), SIMDE_FLOAT32_C(  -101.87), SIMDE_FLOAT32_C(   -71.08), SIMDE_FLOAT32_C(  -641.77) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C( -5931.73), SIMDE_FLOAT32_C( -1213.29), SIMDE_FLOAT32_C( 54327.02), SIMDE_FLOAT32_C( 15408.15) } },
    { { SIMDE_FLOAT32_C(  -299.27), SIMDE_FLOAT32_C(   129.31), SIMDE_FLOAT32_C(  -764.46), SIMDE_FLOAT32_C(  -326.90) },
      { SIMDE_FLOAT32_C(  -206.94), SIMDE_FLOAT32_C(  -115.19), SIMDE_FLOAT32_C(    10.39), SIMDE_FLOAT32_C(   639.97) },
      { SIMDE_FLOAT32_C(    60.58), SIMDE_FLOAT32_C(   107.87), SIMDE_FLOAT32_C(  -985.27), SIMDE_FLOAT32_C(   564.09) },
       INT32_C(           1),
      { SIMDE_FLOAT32_C(-204191.05), SIMDE_FLOAT32_C(116862.10), SIMDE_FLOAT32_C(  9472.50), SIMDE_FLOAT32_C( -6187.80) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t r_ = simde_vld1q_f32(test_vec[i].r_);
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_float32x4_t b = simde_vld1q_f32(test_vec[i].b);
    simde_float32x4_t r;
    switch(i & 1) {
      case 0:
        r = simde_vcmlaq_rot180_laneq_f32(r_, a, b, 0);
        break;
      case 1:
        r = simde_vcmlaq_rot180_laneq_f32(r_, a, b, 1);
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
      r = simde_vcmlaq_rot180_laneq_f32(r_, a, b, 1);
    else
      r = simde_vcmlaq_rot180_laneq_f32(r_, a, b, 0);


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
SIMDE_TEST_FUNC_LIST_ENTRY(vcmla_rot180_lane_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcmla_rot180_lane_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcmla_rot180_laneq_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcmla_rot180_laneq_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcmlaq_rot180_lane_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcmlaq_rot180_lane_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcmlaq_rot180_laneq_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcmlaq_rot180_laneq_f32)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
