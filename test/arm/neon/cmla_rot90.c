#define SIMDE_TEST_ARM_NEON_INSN cmla_rot90

#include "test-neon.h"
#include "../../../simde/arm/neon/cmla_rot90.h"

static int
test_simde_vcmla_rot90_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a[4];
    simde_float32 b[4];
    simde_float32 r[4];
    simde_float32 r_[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -736.61), SIMDE_FLOAT32_C(  -886.60) },
      { SIMDE_FLOAT32_C(   281.46), SIMDE_FLOAT32_C(   182.30) },
      { SIMDE_FLOAT32_C(   429.99), SIMDE_FLOAT32_C(  -897.20) },
      { SIMDE_FLOAT32_C(162057.17), SIMDE_FLOAT32_C(-250439.62) } },
    { { SIMDE_FLOAT32_C(   776.49), SIMDE_FLOAT32_C(   342.21) },
      { SIMDE_FLOAT32_C(  -299.64), SIMDE_FLOAT32_C(   786.30) },
      { SIMDE_FLOAT32_C(  -603.93), SIMDE_FLOAT32_C(   -76.17) },
      { SIMDE_FLOAT32_C(-269683.66), SIMDE_FLOAT32_C(-102615.98) } },
    { { SIMDE_FLOAT32_C(   513.95), SIMDE_FLOAT32_C(  -299.36) },
      { SIMDE_FLOAT32_C(  -719.19), SIMDE_FLOAT32_C(   762.89) },
      { SIMDE_FLOAT32_C(   552.54), SIMDE_FLOAT32_C(    14.06) },
      { SIMDE_FLOAT32_C(228931.28), SIMDE_FLOAT32_C(215310.77) } },
    { { SIMDE_FLOAT32_C(   529.94), SIMDE_FLOAT32_C(  -725.03) },
      { SIMDE_FLOAT32_C(   627.20), SIMDE_FLOAT32_C(   167.43) },
      { SIMDE_FLOAT32_C(   101.22), SIMDE_FLOAT32_C(   -38.51) },
      { SIMDE_FLOAT32_C(121492.99), SIMDE_FLOAT32_C(-454777.34) } },
    { { SIMDE_FLOAT32_C(  -773.64), SIMDE_FLOAT32_C(   578.09) },
      { SIMDE_FLOAT32_C(  -557.39), SIMDE_FLOAT32_C(  -616.25) },
      { SIMDE_FLOAT32_C(   304.61), SIMDE_FLOAT32_C(   452.27) },
      { SIMDE_FLOAT32_C(356552.59), SIMDE_FLOAT32_C(-321769.34) } },
    { { SIMDE_FLOAT32_C(   530.02), SIMDE_FLOAT32_C(   568.00) },
      { SIMDE_FLOAT32_C(   565.67), SIMDE_FLOAT32_C(  -188.52) },
      { SIMDE_FLOAT32_C(  -249.70), SIMDE_FLOAT32_C(    -4.33) },
      { SIMDE_FLOAT32_C(106829.66), SIMDE_FLOAT32_C(321296.22) } },
    { { SIMDE_FLOAT32_C(   -85.72), SIMDE_FLOAT32_C(  -473.21) },
      { SIMDE_FLOAT32_C(  -662.12), SIMDE_FLOAT32_C(   614.64) },
      { SIMDE_FLOAT32_C(  -686.90), SIMDE_FLOAT32_C(  -266.06) },
      { SIMDE_FLOAT32_C(290166.91), SIMDE_FLOAT32_C(313055.75) } },
    { { SIMDE_FLOAT32_C(  -461.53), SIMDE_FLOAT32_C(   827.04) },
      { SIMDE_FLOAT32_C(   434.59), SIMDE_FLOAT32_C(  -180.71) },
      { SIMDE_FLOAT32_C(   589.93), SIMDE_FLOAT32_C(   -12.87) },
      { SIMDE_FLOAT32_C(150044.33), SIMDE_FLOAT32_C(359410.44) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t a = simde_vld1_f32(test_vec[i].a);
    simde_float32x2_t b = simde_vld1_f32(test_vec[i].b);
    simde_float32x2_t r = simde_vld1_f32(test_vec[i].r);
    simde_float32x2_t r_ = simde_vcmla_rot90_f32(r, a, b);

    simde_test_arm_neon_assert_equal_f32x2(r_, simde_vld1_f32(test_vec[i].r_), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x2_t a = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f);
    simde_float32x2_t b = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f);
    simde_float32x2_t r = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f);
    simde_float32x2_t r_ = simde_vcmla_rot90_f32(r, a, b);

    simde_test_arm_neon_write_f32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x2(2, r, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x2(2, r_, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcmlaq_rot90_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a[4];
    simde_float32 b[4];
    simde_float32 r[4];
    simde_float32 r_[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   809.81), SIMDE_FLOAT32_C(   702.36), SIMDE_FLOAT32_C(  -440.66), SIMDE_FLOAT32_C(    26.41) },
      { SIMDE_FLOAT32_C(   196.20), SIMDE_FLOAT32_C(   580.52), SIMDE_FLOAT32_C(   918.89), SIMDE_FLOAT32_C(  -116.23) },
      { SIMDE_FLOAT32_C(   484.07), SIMDE_FLOAT32_C(   711.80), SIMDE_FLOAT32_C(   891.23), SIMDE_FLOAT32_C(    40.72) },
      { SIMDE_FLOAT32_C(-407249.97), SIMDE_FLOAT32_C(138514.83), SIMDE_FLOAT32_C(  3960.86), SIMDE_FLOAT32_C( 24308.61) } },
    { { SIMDE_FLOAT32_C(   509.40), SIMDE_FLOAT32_C(  -504.44), SIMDE_FLOAT32_C(    19.20), SIMDE_FLOAT32_C(   170.91) },
      { SIMDE_FLOAT32_C(   886.34), SIMDE_FLOAT32_C(   555.20), SIMDE_FLOAT32_C(  -753.29), SIMDE_FLOAT32_C(   -56.21) },
      { SIMDE_FLOAT32_C(  -843.97), SIMDE_FLOAT32_C(  -640.31), SIMDE_FLOAT32_C(   469.39), SIMDE_FLOAT32_C(  -535.58) },
      { SIMDE_FLOAT32_C(279221.12), SIMDE_FLOAT32_C(-447745.69), SIMDE_FLOAT32_C( 10076.24), SIMDE_FLOAT32_C(-129280.38) } },
    { { SIMDE_FLOAT32_C(  -886.22), SIMDE_FLOAT32_C(   250.51), SIMDE_FLOAT32_C(   591.50), SIMDE_FLOAT32_C(   599.25) },
      { SIMDE_FLOAT32_C(   260.71), SIMDE_FLOAT32_C(  -574.11), SIMDE_FLOAT32_C(  -734.49), SIMDE_FLOAT32_C(    70.52) },
      { SIMDE_FLOAT32_C(  -871.75), SIMDE_FLOAT32_C(  -175.15), SIMDE_FLOAT32_C(  -903.07), SIMDE_FLOAT32_C(   324.45) },
      { SIMDE_FLOAT32_C(142948.55), SIMDE_FLOAT32_C( 65135.31), SIMDE_FLOAT32_C(-43162.18), SIMDE_FLOAT32_C(-439818.69) } },
    { { SIMDE_FLOAT32_C(  -594.62), SIMDE_FLOAT32_C(  -984.18), SIMDE_FLOAT32_C(  -791.78), SIMDE_FLOAT32_C(   889.45) },
      { SIMDE_FLOAT32_C(   727.61), SIMDE_FLOAT32_C(  -900.55), SIMDE_FLOAT32_C(   -69.84), SIMDE_FLOAT32_C(   237.02) },
      { SIMDE_FLOAT32_C(  -404.99), SIMDE_FLOAT32_C(   949.36), SIMDE_FLOAT32_C(  -592.07), SIMDE_FLOAT32_C(  -518.65) },
      { SIMDE_FLOAT32_C(-886708.25), SIMDE_FLOAT32_C(-715149.81), SIMDE_FLOAT32_C(-211409.52), SIMDE_FLOAT32_C(-62637.84) } },
    { { SIMDE_FLOAT32_C(   504.57), SIMDE_FLOAT32_C(  -345.36), SIMDE_FLOAT32_C(   425.14), SIMDE_FLOAT32_C(   660.60) },
      { SIMDE_FLOAT32_C(    14.33), SIMDE_FLOAT32_C(  -105.47), SIMDE_FLOAT32_C(  -874.99), SIMDE_FLOAT32_C(   128.10) },
      { SIMDE_FLOAT32_C(  -854.96), SIMDE_FLOAT32_C(   716.51), SIMDE_FLOAT32_C(  -272.64), SIMDE_FLOAT32_C(   405.75) },
      { SIMDE_FLOAT32_C(-37280.08), SIMDE_FLOAT32_C( -4232.50), SIMDE_FLOAT32_C(-84895.50), SIMDE_FLOAT32_C(-577612.62) } },
    { { SIMDE_FLOAT32_C(  -857.59), SIMDE_FLOAT32_C(    -7.13), SIMDE_FLOAT32_C(  -523.73), SIMDE_FLOAT32_C(  -729.34) },
      { SIMDE_FLOAT32_C(   817.72), SIMDE_FLOAT32_C(  -426.81), SIMDE_FLOAT32_C(   595.11), SIMDE_FLOAT32_C(  -776.90) },
      { SIMDE_FLOAT32_C(  -410.99), SIMDE_FLOAT32_C(   803.33), SIMDE_FLOAT32_C(  -887.46), SIMDE_FLOAT32_C(  -683.37) },
      { SIMDE_FLOAT32_C( -3454.15), SIMDE_FLOAT32_C( -5027.01), SIMDE_FLOAT32_C(-567511.75), SIMDE_FLOAT32_C(-434720.91) } },
    { { SIMDE_FLOAT32_C(   902.78), SIMDE_FLOAT32_C(    42.71), SIMDE_FLOAT32_C(   553.64), SIMDE_FLOAT32_C(  -502.21) },
      { SIMDE_FLOAT32_C(    -7.93), SIMDE_FLOAT32_C(   961.57), SIMDE_FLOAT32_C(   -20.86), SIMDE_FLOAT32_C(  -503.36) },
      { SIMDE_FLOAT32_C(  -383.79), SIMDE_FLOAT32_C(  -595.71), SIMDE_FLOAT32_C(  -842.76), SIMDE_FLOAT32_C(   630.53) },
      { SIMDE_FLOAT32_C(-41452.45), SIMDE_FLOAT32_C(  -934.40), SIMDE_FLOAT32_C(-253635.17), SIMDE_FLOAT32_C( 11106.63) } },
    { { SIMDE_FLOAT32_C(   298.82), SIMDE_FLOAT32_C(  -717.75), SIMDE_FLOAT32_C(  -241.36), SIMDE_FLOAT32_C(   443.86) },
      { SIMDE_FLOAT32_C(   998.76), SIMDE_FLOAT32_C(   486.00), SIMDE_FLOAT32_C(  -150.39), SIMDE_FLOAT32_C(  -858.84) },
      { SIMDE_FLOAT32_C(  -521.14), SIMDE_FLOAT32_C(   325.87), SIMDE_FLOAT32_C(  -588.18), SIMDE_FLOAT32_C(  -703.42) },
      { SIMDE_FLOAT32_C(348305.38), SIMDE_FLOAT32_C(-716534.12), SIMDE_FLOAT32_C(380616.53), SIMDE_FLOAT32_C(-67455.52) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_float32x4_t b = simde_vld1q_f32(test_vec[i].b);
    simde_float32x4_t r = simde_vld1q_f32(test_vec[i].r);
    simde_float32x4_t r_ = simde_vcmlaq_rot90_f32(r, a, b);
    simde_test_arm_neon_assert_equal_f32x4(r_, simde_vld1q_f32(test_vec[i].r_), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x4_t a = simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f);
    simde_float32x4_t b = simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f);
    simde_float32x4_t r = simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f);
    simde_float32x4_t r_ = simde_vcmlaq_rot90_f32(r, a, b);

    simde_test_arm_neon_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x4(2, r, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x4(2, r_, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcmlaq_rot90_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 a[2];
    simde_float64 b[2];
    simde_float64 r[2];
    simde_float64 r_[2];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(  -913.35), SIMDE_FLOAT64_C(   651.70) },
      { SIMDE_FLOAT64_C(  -202.18), SIMDE_FLOAT64_C(   611.89) },
      { SIMDE_FLOAT64_C(  -924.95), SIMDE_FLOAT64_C(   395.75) },
      { SIMDE_FLOAT64_C(-399693.66), SIMDE_FLOAT64_C(-131364.96) } },
    { { SIMDE_FLOAT64_C(  -917.75), SIMDE_FLOAT64_C(  -438.33) },
      { SIMDE_FLOAT64_C(    -0.32), SIMDE_FLOAT64_C(   810.69) },
      { SIMDE_FLOAT64_C(    11.74), SIMDE_FLOAT64_C(  -666.19) },
      { SIMDE_FLOAT64_C(355361.49), SIMDE_FLOAT64_C(  -525.92) } },
    { { SIMDE_FLOAT64_C(  -434.30), SIMDE_FLOAT64_C(  -744.37) },
      { SIMDE_FLOAT64_C(  -564.35), SIMDE_FLOAT64_C(   -95.18) },
      { SIMDE_FLOAT64_C(   956.50), SIMDE_FLOAT64_C(   334.31) },
      { SIMDE_FLOAT64_C(-69892.64), SIMDE_FLOAT64_C(420419.52) } },
    { { SIMDE_FLOAT64_C(   595.20), SIMDE_FLOAT64_C(   271.18) },
      { SIMDE_FLOAT64_C(   967.27), SIMDE_FLOAT64_C(   979.29) },
      { SIMDE_FLOAT64_C(   428.77), SIMDE_FLOAT64_C(   858.33) },
      { SIMDE_FLOAT64_C(-265135.09), SIMDE_FLOAT64_C(263162.61) } },
    { { SIMDE_FLOAT64_C(  -931.38), SIMDE_FLOAT64_C(   720.93) },
      { SIMDE_FLOAT64_C(   860.06), SIMDE_FLOAT64_C(  -977.02) },
      { SIMDE_FLOAT64_C(  -592.65), SIMDE_FLOAT64_C(   976.85) },
      { SIMDE_FLOAT64_C(703770.38), SIMDE_FLOAT64_C(621019.91) } },
    { { SIMDE_FLOAT64_C(   776.69), SIMDE_FLOAT64_C(  -506.00) },
      { SIMDE_FLOAT64_C(   628.55), SIMDE_FLOAT64_C(  -425.49) },
      { SIMDE_FLOAT64_C(  -894.11), SIMDE_FLOAT64_C(   703.60) },
      { SIMDE_FLOAT64_C(-216192.05), SIMDE_FLOAT64_C(-317342.70) } },
    { { SIMDE_FLOAT64_C(   970.25), SIMDE_FLOAT64_C(  -811.86) },
      { SIMDE_FLOAT64_C(  -734.73), SIMDE_FLOAT64_C(   -30.06) },
      { SIMDE_FLOAT64_C(   998.84), SIMDE_FLOAT64_C(   277.01) },
      { SIMDE_FLOAT64_C(-23405.67), SIMDE_FLOAT64_C(596774.91) } },
    { { SIMDE_FLOAT64_C(   303.75), SIMDE_FLOAT64_C(  -435.46) },
      { SIMDE_FLOAT64_C(   532.64), SIMDE_FLOAT64_C(   739.40) },
      { SIMDE_FLOAT64_C(   469.36), SIMDE_FLOAT64_C(   489.13) },
      { SIMDE_FLOAT64_C(322448.48), SIMDE_FLOAT64_C(-231454.28) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2_t a = simde_vld1q_f64(test_vec[i].a);
    simde_float64x2_t b = simde_vld1q_f64(test_vec[i].b);
    simde_float64x2_t r = simde_vld1q_f64(test_vec[i].r);
    simde_float64x2_t r_ = simde_vcmlaq_rot90_f64(r, a, b);
    simde_test_arm_neon_assert_equal_f64x2(r_, simde_vld1q_f64(test_vec[i].r_), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x2_t a = simde_test_arm_neon_random_f64x2(-1000.0f, 1000.0f);
    simde_float64x2_t b = simde_test_arm_neon_random_f64x2(-1000.0f, 1000.0f);
    simde_float64x2_t r = simde_test_arm_neon_random_f64x2(-1000.0f, 1000.0f);
    simde_float64x2_t r_ = simde_vcmlaq_rot90_f64(r, a, b);

    simde_test_arm_neon_write_f64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f64x2(2, r, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f64x2(2, r_, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vcmla_rot90_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcmlaq_rot90_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcmlaq_rot90_f64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
