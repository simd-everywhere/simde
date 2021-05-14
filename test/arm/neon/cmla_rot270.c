#define SIMDE_TEST_ARM_NEON_INSN cmla_rot270

#include "test-neon.h"
#include "../../../simde/arm/neon/cmla_rot270.h"

static int
test_simde_vcmla_rot270_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a[4];
    simde_float32 b[4];
    simde_float32 r[4];
    simde_float32 r_[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   -50.23), SIMDE_FLOAT32_C(   -93.80) },
      { SIMDE_FLOAT32_C(   167.59), SIMDE_FLOAT32_C(    54.72) },
      { SIMDE_FLOAT32_C(   889.39), SIMDE_FLOAT32_C(   -46.05) },
      { SIMDE_FLOAT32_C( -4243.35), SIMDE_FLOAT32_C( 15673.89) } },
    { { SIMDE_FLOAT32_C(  -703.48), SIMDE_FLOAT32_C(   367.81) },
      { SIMDE_FLOAT32_C(   743.72), SIMDE_FLOAT32_C(    47.92) },
      { SIMDE_FLOAT32_C(   999.37), SIMDE_FLOAT32_C(   -87.94) },
      { SIMDE_FLOAT32_C( 18624.82), SIMDE_FLOAT32_C(-273635.59) } },
    { { SIMDE_FLOAT32_C(  -326.37), SIMDE_FLOAT32_C(   604.88) },
      { SIMDE_FLOAT32_C(   224.18), SIMDE_FLOAT32_C(  -994.49) },
      { SIMDE_FLOAT32_C(  -175.46), SIMDE_FLOAT32_C(  -858.15) },
      { SIMDE_FLOAT32_C(-601722.56), SIMDE_FLOAT32_C(-136460.14) } },
    { { SIMDE_FLOAT32_C(  -942.56), SIMDE_FLOAT32_C(    45.37) },
      { SIMDE_FLOAT32_C(   163.87), SIMDE_FLOAT32_C(   969.32) },
      { SIMDE_FLOAT32_C(   778.80), SIMDE_FLOAT32_C(   918.99) },
      { SIMDE_FLOAT32_C( 44756.85), SIMDE_FLOAT32_C( -6515.79) } },
    { { SIMDE_FLOAT32_C(   909.88), SIMDE_FLOAT32_C(   955.41) },
      { SIMDE_FLOAT32_C(   975.43), SIMDE_FLOAT32_C(   253.10) },
      { SIMDE_FLOAT32_C(  -261.19), SIMDE_FLOAT32_C(   233.33) },
      { SIMDE_FLOAT32_C(241553.08), SIMDE_FLOAT32_C(-931702.19) } },
    { { SIMDE_FLOAT32_C(  -953.37), SIMDE_FLOAT32_C(   688.58) },
      { SIMDE_FLOAT32_C(  -860.47), SIMDE_FLOAT32_C(   214.22) },
      { SIMDE_FLOAT32_C(  -256.70), SIMDE_FLOAT32_C(  -971.08) },
      { SIMDE_FLOAT32_C(147250.91), SIMDE_FLOAT32_C(591531.38) } },
    { { SIMDE_FLOAT32_C(  -831.83), SIMDE_FLOAT32_C(    39.82) },
      { SIMDE_FLOAT32_C(   396.73), SIMDE_FLOAT32_C(   911.89) },
      { SIMDE_FLOAT32_C(  -912.26), SIMDE_FLOAT32_C(   396.10) },
      { SIMDE_FLOAT32_C( 35399.20), SIMDE_FLOAT32_C(-15401.69) } },
    { { SIMDE_FLOAT32_C(  -176.06), SIMDE_FLOAT32_C(  -238.62) },
      { SIMDE_FLOAT32_C(     0.99), SIMDE_FLOAT32_C(  -951.87) },
      { SIMDE_FLOAT32_C(  -233.12), SIMDE_FLOAT32_C(   825.53) },
      { SIMDE_FLOAT32_C(226902.09), SIMDE_FLOAT32_C(  1061.76) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t a = simde_vld1_f32(test_vec[i].a);
    simde_float32x2_t b = simde_vld1_f32(test_vec[i].b);
    simde_float32x2_t r = simde_vld1_f32(test_vec[i].r);
    simde_float32x2_t r_ = simde_vcmla_rot270_f32(r, a, b);

    simde_test_arm_neon_assert_equal_f32x2(r_, simde_vld1_f32(test_vec[i].r_), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x2_t a = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f);
    simde_float32x2_t b = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f);
    simde_float32x2_t r = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f);
    simde_float32x2_t r_ = simde_vcmla_rot270_f32(r, a, b);

    simde_test_arm_neon_write_f32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x2(2, r, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x2(2, r_, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcmlaq_rot270_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a[4];
    simde_float32 b[4];
    simde_float32 r[4];
    simde_float32 r_[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   126.46), SIMDE_FLOAT32_C(  -102.84), SIMDE_FLOAT32_C(  -564.92), SIMDE_FLOAT32_C(  -510.64) },
      { SIMDE_FLOAT32_C(   175.98), SIMDE_FLOAT32_C(  -552.56), SIMDE_FLOAT32_C(  -211.73), SIMDE_FLOAT32_C(  -777.22) },
      { SIMDE_FLOAT32_C(   582.03), SIMDE_FLOAT32_C(   874.49), SIMDE_FLOAT32_C(  -164.75), SIMDE_FLOAT32_C(  -792.98) },
      { SIMDE_FLOAT32_C( 57407.30), SIMDE_FLOAT32_C( 18972.27), SIMDE_FLOAT32_C(396714.88), SIMDE_FLOAT32_C(-108910.79) } },
    { { SIMDE_FLOAT32_C(   596.49), SIMDE_FLOAT32_C(  -138.97), SIMDE_FLOAT32_C(   939.08), SIMDE_FLOAT32_C(  -705.25) },
      { SIMDE_FLOAT32_C(   449.34), SIMDE_FLOAT32_C(  -193.80), SIMDE_FLOAT32_C(   928.27), SIMDE_FLOAT32_C(  -625.06) },
      { SIMDE_FLOAT32_C(  -301.19), SIMDE_FLOAT32_C(  -563.73), SIMDE_FLOAT32_C(  -710.46), SIMDE_FLOAT32_C(  -738.46) },
      { SIMDE_FLOAT32_C( 26631.20), SIMDE_FLOAT32_C( 61881.05), SIMDE_FLOAT32_C(440113.09), SIMDE_FLOAT32_C(653924.00) } },
    { { SIMDE_FLOAT32_C(   489.04), SIMDE_FLOAT32_C(   298.23), SIMDE_FLOAT32_C(  -122.18), SIMDE_FLOAT32_C(   614.08) },
      { SIMDE_FLOAT32_C(   157.80), SIMDE_FLOAT32_C(  -378.12), SIMDE_FLOAT32_C(   654.24), SIMDE_FLOAT32_C(  -715.73) },
      { SIMDE_FLOAT32_C(   519.04), SIMDE_FLOAT32_C(  -910.68), SIMDE_FLOAT32_C(  -226.37), SIMDE_FLOAT32_C(  -304.98) },
      { SIMDE_FLOAT32_C(-112247.69), SIMDE_FLOAT32_C(-47971.38), SIMDE_FLOAT32_C(-439741.84), SIMDE_FLOAT32_C(-402060.69) } },
    { { SIMDE_FLOAT32_C(  -463.25), SIMDE_FLOAT32_C(   561.90), SIMDE_FLOAT32_C(   -82.20), SIMDE_FLOAT32_C(  -881.22) },
      { SIMDE_FLOAT32_C(   436.39), SIMDE_FLOAT32_C(   753.06), SIMDE_FLOAT32_C(  -674.20), SIMDE_FLOAT32_C(    32.88) },
      { SIMDE_FLOAT32_C(  -385.92), SIMDE_FLOAT32_C(  -735.12), SIMDE_FLOAT32_C(   327.63), SIMDE_FLOAT32_C(  -936.58) },
      { SIMDE_FLOAT32_C(422758.50), SIMDE_FLOAT32_C(-245942.69), SIMDE_FLOAT32_C(-28646.88), SIMDE_FLOAT32_C(-595055.12) } },
    { { SIMDE_FLOAT32_C(    71.08), SIMDE_FLOAT32_C(   255.90), SIMDE_FLOAT32_C(  -561.64), SIMDE_FLOAT32_C(   769.89) },
      { SIMDE_FLOAT32_C(   692.17), SIMDE_FLOAT32_C(  -272.09), SIMDE_FLOAT32_C(  -968.57), SIMDE_FLOAT32_C(   181.21) },
      { SIMDE_FLOAT32_C(  -973.86), SIMDE_FLOAT32_C(   -90.75), SIMDE_FLOAT32_C(  -204.71), SIMDE_FLOAT32_C(   183.94) },
      { SIMDE_FLOAT32_C(-70601.69), SIMDE_FLOAT32_C(-177217.05), SIMDE_FLOAT32_C(139307.06), SIMDE_FLOAT32_C(745876.31) } },
    { { SIMDE_FLOAT32_C(   531.13), SIMDE_FLOAT32_C(  -550.47), SIMDE_FLOAT32_C(   468.21), SIMDE_FLOAT32_C(    50.17) },
      { SIMDE_FLOAT32_C(  -461.15), SIMDE_FLOAT32_C(  -758.16), SIMDE_FLOAT32_C(   745.19), SIMDE_FLOAT32_C(    75.60) },
      { SIMDE_FLOAT32_C(   803.74), SIMDE_FLOAT32_C(  -337.01), SIMDE_FLOAT32_C(   194.38), SIMDE_FLOAT32_C(   240.13) },
      { SIMDE_FLOAT32_C(418148.03), SIMDE_FLOAT32_C(-254186.23), SIMDE_FLOAT32_C(  3987.23), SIMDE_FLOAT32_C(-37146.05) } },
    { { SIMDE_FLOAT32_C(  -583.95), SIMDE_FLOAT32_C(   520.18), SIMDE_FLOAT32_C(  -726.99), SIMDE_FLOAT32_C(    30.13) },
      { SIMDE_FLOAT32_C(   785.06), SIMDE_FLOAT32_C(   600.64), SIMDE_FLOAT32_C(    93.55), SIMDE_FLOAT32_C(  -143.86) },
      { SIMDE_FLOAT32_C(  -143.46), SIMDE_FLOAT32_C(   531.91), SIMDE_FLOAT32_C(  -373.97), SIMDE_FLOAT32_C(  -451.29) },
      { SIMDE_FLOAT32_C(312297.47), SIMDE_FLOAT32_C(-407840.59), SIMDE_FLOAT32_C( -4708.47), SIMDE_FLOAT32_C( -3269.95) } },
    { { SIMDE_FLOAT32_C(  -740.18), SIMDE_FLOAT32_C(  -342.54), SIMDE_FLOAT32_C(   729.92), SIMDE_FLOAT32_C(  -714.05) },
      { SIMDE_FLOAT32_C(   566.71), SIMDE_FLOAT32_C(  -474.78), SIMDE_FLOAT32_C(   469.90), SIMDE_FLOAT32_C(    97.84) },
      { SIMDE_FLOAT32_C(   -25.25), SIMDE_FLOAT32_C(   -61.89), SIMDE_FLOAT32_C(  -851.99), SIMDE_FLOAT32_C(   513.60) },
      { SIMDE_FLOAT32_C(162605.89), SIMDE_FLOAT32_C(194058.97), SIMDE_FLOAT32_C(-70714.64), SIMDE_FLOAT32_C(336045.69) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_float32x4_t b = simde_vld1q_f32(test_vec[i].b);
    simde_float32x4_t r = simde_vld1q_f32(test_vec[i].r);
    simde_float32x4_t r_ = simde_vcmlaq_rot270_f32(r, a, b);
    simde_test_arm_neon_assert_equal_f32x4(r_, simde_vld1q_f32(test_vec[i].r_), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x4_t a = simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f);
    simde_float32x4_t b = simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f);
    simde_float32x4_t r = simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f);
    simde_float32x4_t r_ = simde_vcmlaq_rot270_f32(r, a, b);

    simde_test_arm_neon_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x4(2, r, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x4(2, r_, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcmlaq_rot270_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 a[2];
    simde_float64 b[2];
    simde_float64 r[2];
    simde_float64 r_[2];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(  -772.20), SIMDE_FLOAT64_C(  -289.07) },
      { SIMDE_FLOAT64_C(  -254.86), SIMDE_FLOAT64_C(   875.19) },
      { SIMDE_FLOAT64_C(  -291.25), SIMDE_FLOAT64_C(  -386.54) },
      { SIMDE_FLOAT64_C(-253282.42), SIMDE_FLOAT64_C(-74058.92) } },
    { { SIMDE_FLOAT64_C(   901.93), SIMDE_FLOAT64_C(  -182.45) },
      { SIMDE_FLOAT64_C(  -401.46), SIMDE_FLOAT64_C(   570.66) },
      { SIMDE_FLOAT64_C(  -805.46), SIMDE_FLOAT64_C(   495.43) },
      { SIMDE_FLOAT64_C(-104922.38), SIMDE_FLOAT64_C(-72750.95) } },
    { { SIMDE_FLOAT64_C(   735.86), SIMDE_FLOAT64_C(   696.07) },
      { SIMDE_FLOAT64_C(    67.50), SIMDE_FLOAT64_C(  -993.11) },
      { SIMDE_FLOAT64_C(  -328.56), SIMDE_FLOAT64_C(  -238.82) },
      { SIMDE_FLOAT64_C(-691602.64), SIMDE_FLOAT64_C(-47223.55) } },
    { { SIMDE_FLOAT64_C(  -528.21), SIMDE_FLOAT64_C(   -73.41) },
      { SIMDE_FLOAT64_C(    25.60), SIMDE_FLOAT64_C(  -492.76) },
      { SIMDE_FLOAT64_C(  -996.44), SIMDE_FLOAT64_C(  -171.25) },
      { SIMDE_FLOAT64_C( 35177.07), SIMDE_FLOAT64_C(  1708.05) } },
    { { SIMDE_FLOAT64_C(   532.55), SIMDE_FLOAT64_C(    64.30) },
      { SIMDE_FLOAT64_C(  -451.87), SIMDE_FLOAT64_C(  -697.40) },
      { SIMDE_FLOAT64_C(  -232.31), SIMDE_FLOAT64_C(  -793.59) },
      { SIMDE_FLOAT64_C(-45075.13), SIMDE_FLOAT64_C( 28261.65) } },
    { { SIMDE_FLOAT64_C(    99.38), SIMDE_FLOAT64_C(    -4.51) },
      { SIMDE_FLOAT64_C(   -82.66), SIMDE_FLOAT64_C(   844.53) },
      { SIMDE_FLOAT64_C(  -129.32), SIMDE_FLOAT64_C(   626.09) },
      { SIMDE_FLOAT64_C( -3938.15), SIMDE_FLOAT64_C(   253.29) } },
    { { SIMDE_FLOAT64_C(  -542.02), SIMDE_FLOAT64_C(  -227.39) },
      { SIMDE_FLOAT64_C(  -556.35), SIMDE_FLOAT64_C(    56.52) },
      { SIMDE_FLOAT64_C(  -656.73), SIMDE_FLOAT64_C(  -361.81) },
      { SIMDE_FLOAT64_C(-13508.81), SIMDE_FLOAT64_C(-126870.24) } },
    { { SIMDE_FLOAT64_C(  -448.05), SIMDE_FLOAT64_C(  -920.87) },
      { SIMDE_FLOAT64_C(  -665.74), SIMDE_FLOAT64_C(   619.45) },
      { SIMDE_FLOAT64_C(  -913.98), SIMDE_FLOAT64_C(     5.70) },
      { SIMDE_FLOAT64_C(-571346.90), SIMDE_FLOAT64_C(-613054.29) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2_t a = simde_vld1q_f64(test_vec[i].a);
    simde_float64x2_t b = simde_vld1q_f64(test_vec[i].b);
    simde_float64x2_t r = simde_vld1q_f64(test_vec[i].r);
    simde_float64x2_t r_ = simde_vcmlaq_rot270_f64(r, a, b);
    simde_test_arm_neon_assert_equal_f64x2(r_, simde_vld1q_f64(test_vec[i].r_), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x2_t a = simde_test_arm_neon_random_f64x2(-1000.0f, 1000.0f);
    simde_float64x2_t b = simde_test_arm_neon_random_f64x2(-1000.0f, 1000.0f);
    simde_float64x2_t r = simde_test_arm_neon_random_f64x2(-1000.0f, 1000.0f);
    simde_float64x2_t r_ = simde_vcmlaq_rot270_f64(r, a, b);

    simde_test_arm_neon_write_f64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f64x2(2, r, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f64x2(2, r_, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vcmla_rot270_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcmlaq_rot270_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcmlaq_rot270_f64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
