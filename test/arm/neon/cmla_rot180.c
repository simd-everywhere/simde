#define SIMDE_TEST_ARM_NEON_INSN cmla_rot180

#include "test-neon.h"
#include "../../../simde/arm/neon/cmla_rot180.h"

static int
test_simde_vcmla_rot180_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a[4];
    simde_float32 b[4];
    simde_float32 r[4];
    simde_float32 r_[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   452.95), SIMDE_FLOAT32_C(   195.89) },
      { SIMDE_FLOAT32_C(   444.91), SIMDE_FLOAT32_C(    53.65) },
      { SIMDE_FLOAT32_C(  -340.35), SIMDE_FLOAT32_C(  -889.91) },
      { SIMDE_FLOAT32_C(-201862.34), SIMDE_FLOAT32_C(-25190.68) } },
    { { SIMDE_FLOAT32_C(   306.65), SIMDE_FLOAT32_C(  -419.57) },
      { SIMDE_FLOAT32_C(  -861.69), SIMDE_FLOAT32_C(   727.62) },
      { SIMDE_FLOAT32_C(  -997.28), SIMDE_FLOAT32_C(   144.31) },
      { SIMDE_FLOAT32_C(263239.97), SIMDE_FLOAT32_C(-222980.36) } },
    { { SIMDE_FLOAT32_C(   196.29), SIMDE_FLOAT32_C(   798.44) },
      { SIMDE_FLOAT32_C(  -778.96), SIMDE_FLOAT32_C(   915.31) },
      { SIMDE_FLOAT32_C(   222.88), SIMDE_FLOAT32_C(   691.69) },
      { SIMDE_FLOAT32_C(153124.94), SIMDE_FLOAT32_C(-178974.50) } },
    { { SIMDE_FLOAT32_C(   -68.29), SIMDE_FLOAT32_C(   627.45) },
      { SIMDE_FLOAT32_C(  -373.33), SIMDE_FLOAT32_C(   724.33) },
      { SIMDE_FLOAT32_C(   133.16), SIMDE_FLOAT32_C(   234.76) },
      { SIMDE_FLOAT32_C(-25361.54), SIMDE_FLOAT32_C( 49699.26) } },
    { { SIMDE_FLOAT32_C(   964.74), SIMDE_FLOAT32_C(   624.02) },
      { SIMDE_FLOAT32_C(  -835.66), SIMDE_FLOAT32_C(   908.14) },
      { SIMDE_FLOAT32_C(   913.15), SIMDE_FLOAT32_C(   697.78) },
      { SIMDE_FLOAT32_C(807107.75), SIMDE_FLOAT32_C(-875421.19) } },
    { { SIMDE_FLOAT32_C(   162.44), SIMDE_FLOAT32_C(   366.10) },
      { SIMDE_FLOAT32_C(  -106.33), SIMDE_FLOAT32_C(  -392.64) },
      { SIMDE_FLOAT32_C(  -580.25), SIMDE_FLOAT32_C(   553.32) },
      { SIMDE_FLOAT32_C( 16692.00), SIMDE_FLOAT32_C( 64333.77) } },
    { { SIMDE_FLOAT32_C(  -282.55), SIMDE_FLOAT32_C(   726.40) },
      { SIMDE_FLOAT32_C(  -866.24), SIMDE_FLOAT32_C(  -144.24) },
      { SIMDE_FLOAT32_C(   454.02), SIMDE_FLOAT32_C(  -863.52) },
      { SIMDE_FLOAT32_C(-244302.08), SIMDE_FLOAT32_C(-41618.53) } },
    { { SIMDE_FLOAT32_C(  -999.93), SIMDE_FLOAT32_C(  -349.69) },
      { SIMDE_FLOAT32_C(   934.92), SIMDE_FLOAT32_C(  -778.90) },
      { SIMDE_FLOAT32_C(  -434.38), SIMDE_FLOAT32_C(   157.80) },
      { SIMDE_FLOAT32_C(934420.12), SIMDE_FLOAT32_C(-778687.69) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t a = simde_vld1_f32(test_vec[i].a);
    simde_float32x2_t b = simde_vld1_f32(test_vec[i].b);
    simde_float32x2_t r = simde_vld1_f32(test_vec[i].r);
    simde_float32x2_t r_ = simde_vcmla_rot180_f32(r, a, b);

    simde_test_arm_neon_assert_equal_f32x2(r_, simde_vld1_f32(test_vec[i].r_), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x2_t a = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f);
    simde_float32x2_t b = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f);
    simde_float32x2_t r = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f);
    simde_float32x2_t r_ = simde_vcmla_rot180_f32(r, a, b);

    simde_test_arm_neon_write_f32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x2(2, r, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x2(2, r_, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcmlaq_rot180_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a[4];
    simde_float32 b[4];
    simde_float32 r[4];
    simde_float32 r_[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   581.15), SIMDE_FLOAT32_C(  -956.71), SIMDE_FLOAT32_C(   565.79), SIMDE_FLOAT32_C(  -665.78) },
      { SIMDE_FLOAT32_C(   634.03), SIMDE_FLOAT32_C(  -372.68), SIMDE_FLOAT32_C(  -843.04), SIMDE_FLOAT32_C(  -573.31) },
      { SIMDE_FLOAT32_C(   743.16), SIMDE_FLOAT32_C(   262.51), SIMDE_FLOAT32_C(   315.71), SIMDE_FLOAT32_C(   643.97) },
      { SIMDE_FLOAT32_C(-367723.41), SIMDE_FLOAT32_C(216845.50), SIMDE_FLOAT32_C(477299.28), SIMDE_FLOAT32_C(325017.03) } },
    { { SIMDE_FLOAT32_C(   -14.23), SIMDE_FLOAT32_C(   146.05), SIMDE_FLOAT32_C(  -713.83), SIMDE_FLOAT32_C(   -20.06) },
      { SIMDE_FLOAT32_C(   104.47), SIMDE_FLOAT32_C(   216.28), SIMDE_FLOAT32_C(  -177.08), SIMDE_FLOAT32_C(    12.18) },
      { SIMDE_FLOAT32_C(  -643.47), SIMDE_FLOAT32_C(   708.88), SIMDE_FLOAT32_C(   686.41), SIMDE_FLOAT32_C(   709.88) },
      { SIMDE_FLOAT32_C(   843.14), SIMDE_FLOAT32_C(  3786.54), SIMDE_FLOAT32_C(-125718.61), SIMDE_FLOAT32_C(  9404.33) } },
    { { SIMDE_FLOAT32_C(  -814.88), SIMDE_FLOAT32_C(  -711.88), SIMDE_FLOAT32_C(  -748.81), SIMDE_FLOAT32_C(   858.53) },
      { SIMDE_FLOAT32_C(   737.87), SIMDE_FLOAT32_C(  -589.28), SIMDE_FLOAT32_C(  -895.36), SIMDE_FLOAT32_C(   319.02) },
      { SIMDE_FLOAT32_C(  -546.00), SIMDE_FLOAT32_C(   670.42), SIMDE_FLOAT32_C(   653.24), SIMDE_FLOAT32_C(  -911.97) },
      { SIMDE_FLOAT32_C(600729.50), SIMDE_FLOAT32_C(-479522.09), SIMDE_FLOAT32_C(-669801.25), SIMDE_FLOAT32_C(237973.39) } },
    { { SIMDE_FLOAT32_C(  -702.25), SIMDE_FLOAT32_C(   810.19), SIMDE_FLOAT32_C(  -485.28), SIMDE_FLOAT32_C(  -959.09) },
      { SIMDE_FLOAT32_C(    72.70), SIMDE_FLOAT32_C(   830.43), SIMDE_FLOAT32_C(   684.88), SIMDE_FLOAT32_C(  -941.53) },
      { SIMDE_FLOAT32_C(   -23.52), SIMDE_FLOAT32_C(   971.04), SIMDE_FLOAT32_C(    38.42), SIMDE_FLOAT32_C(  -919.05) },
      { SIMDE_FLOAT32_C( 51030.05), SIMDE_FLOAT32_C(584140.50), SIMDE_FLOAT32_C(332397.00), SIMDE_FLOAT32_C(-457824.75) } },
    { { SIMDE_FLOAT32_C(   187.33), SIMDE_FLOAT32_C(   861.34), SIMDE_FLOAT32_C(    93.13), SIMDE_FLOAT32_C(   543.85) },
      { SIMDE_FLOAT32_C(   570.21), SIMDE_FLOAT32_C(  -220.46), SIMDE_FLOAT32_C(   253.73), SIMDE_FLOAT32_C(   755.33) },
      { SIMDE_FLOAT32_C(    67.66), SIMDE_FLOAT32_C(   504.92), SIMDE_FLOAT32_C(   613.86), SIMDE_FLOAT32_C(  -194.47) },
      { SIMDE_FLOAT32_C(-106749.78), SIMDE_FLOAT32_C( 41803.70), SIMDE_FLOAT32_C(-23016.01), SIMDE_FLOAT32_C(-70538.35) } },
    { { SIMDE_FLOAT32_C(   915.64), SIMDE_FLOAT32_C(   718.50), SIMDE_FLOAT32_C(  -875.45), SIMDE_FLOAT32_C(  -630.36) },
      { SIMDE_FLOAT32_C(   388.92), SIMDE_FLOAT32_C(   777.79), SIMDE_FLOAT32_C(  -542.33), SIMDE_FLOAT32_C(   686.66) },
      { SIMDE_FLOAT32_C(   587.98), SIMDE_FLOAT32_C(   -27.61), SIMDE_FLOAT32_C(   727.57), SIMDE_FLOAT32_C(  -339.32) },
      { SIMDE_FLOAT32_C(-355522.75), SIMDE_FLOAT32_C(-712203.25), SIMDE_FLOAT32_C(-474055.25), SIMDE_FLOAT32_C(600797.19) } },
    { { SIMDE_FLOAT32_C(  -197.18), SIMDE_FLOAT32_C(   412.45), SIMDE_FLOAT32_C(  -280.84), SIMDE_FLOAT32_C(   779.30) },
      { SIMDE_FLOAT32_C(   383.50), SIMDE_FLOAT32_C(   757.57), SIMDE_FLOAT32_C(   860.25), SIMDE_FLOAT32_C(  -429.18) },
      { SIMDE_FLOAT32_C(   618.91), SIMDE_FLOAT32_C(   -46.62), SIMDE_FLOAT32_C(  -885.33), SIMDE_FLOAT32_C(   189.12) },
      { SIMDE_FLOAT32_C( 76237.44), SIMDE_FLOAT32_C(149331.03), SIMDE_FLOAT32_C(240707.28), SIMDE_FLOAT32_C(-120341.79) } },
    { { SIMDE_FLOAT32_C(   732.92), SIMDE_FLOAT32_C(   368.40), SIMDE_FLOAT32_C(   -55.55), SIMDE_FLOAT32_C(  -199.42) },
      { SIMDE_FLOAT32_C(  -126.68), SIMDE_FLOAT32_C(  -441.69), SIMDE_FLOAT32_C(   606.11), SIMDE_FLOAT32_C(  -211.04) },
      { SIMDE_FLOAT32_C(  -723.20), SIMDE_FLOAT32_C(   730.66), SIMDE_FLOAT32_C(   158.60), SIMDE_FLOAT32_C(   665.72) },
      { SIMDE_FLOAT32_C( 92123.10), SIMDE_FLOAT32_C(324454.09), SIMDE_FLOAT32_C( 33828.01), SIMDE_FLOAT32_C(-11057.55) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_float32x4_t b = simde_vld1q_f32(test_vec[i].b);
    simde_float32x4_t r = simde_vld1q_f32(test_vec[i].r);
    simde_float32x4_t r_ = simde_vcmlaq_rot180_f32(r, a, b);
    simde_test_arm_neon_assert_equal_f32x4(r_, simde_vld1q_f32(test_vec[i].r_), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x4_t a = simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f);
    simde_float32x4_t b = simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f);
    simde_float32x4_t r = simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f);
    simde_float32x4_t r_ = simde_vcmlaq_rot180_f32(r, a, b);

    simde_test_arm_neon_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x4(2, r, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x4(2, r_, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcmlaq_rot180_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 a[2];
    simde_float64 b[2];
    simde_float64 r[2];
    simde_float64 r_[2];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(   262.77), SIMDE_FLOAT64_C(  -594.87) },
      { SIMDE_FLOAT64_C(  -382.77), SIMDE_FLOAT64_C(   813.86) },
      { SIMDE_FLOAT64_C(   154.31), SIMDE_FLOAT64_C(   621.90) },
      { SIMDE_FLOAT64_C(100734.78), SIMDE_FLOAT64_C(-213236.09) } },
    { { SIMDE_FLOAT64_C(   972.42), SIMDE_FLOAT64_C(  -414.89) },
      { SIMDE_FLOAT64_C(   356.78), SIMDE_FLOAT64_C(   498.91) },
      { SIMDE_FLOAT64_C(   960.93), SIMDE_FLOAT64_C(  -942.16) },
      { SIMDE_FLOAT64_C(-345979.08), SIMDE_FLOAT64_C(-486092.22) } },
    { { SIMDE_FLOAT64_C(   920.42), SIMDE_FLOAT64_C(  -123.39) },
      { SIMDE_FLOAT64_C(  -106.64), SIMDE_FLOAT64_C(   660.02) },
      { SIMDE_FLOAT64_C(   429.81), SIMDE_FLOAT64_C(   808.37) },
      { SIMDE_FLOAT64_C( 98583.40), SIMDE_FLOAT64_C(-606687.24) } },
    { { SIMDE_FLOAT64_C(   -29.61), SIMDE_FLOAT64_C(    98.57) },
      { SIMDE_FLOAT64_C(   828.43), SIMDE_FLOAT64_C(  -489.72) },
      { SIMDE_FLOAT64_C(   575.48), SIMDE_FLOAT64_C(   187.12) },
      { SIMDE_FLOAT64_C( 25105.29), SIMDE_FLOAT64_C(-14313.49) } },
    { { SIMDE_FLOAT64_C(  -389.68), SIMDE_FLOAT64_C(  -827.75) },
      { SIMDE_FLOAT64_C(    15.22), SIMDE_FLOAT64_C(   408.31) },
      { SIMDE_FLOAT64_C(   -24.59), SIMDE_FLOAT64_C(   768.89) },
      { SIMDE_FLOAT64_C(  5906.34), SIMDE_FLOAT64_C(159879.13) } },
    { { SIMDE_FLOAT64_C(  -685.93), SIMDE_FLOAT64_C(  -761.82) },
      { SIMDE_FLOAT64_C(  -825.99), SIMDE_FLOAT64_C(   -68.70) },
      { SIMDE_FLOAT64_C(  -947.96), SIMDE_FLOAT64_C(   328.32) },
      { SIMDE_FLOAT64_C(-567519.28), SIMDE_FLOAT64_C(-46795.07) } },
    { { SIMDE_FLOAT64_C(  -446.80), SIMDE_FLOAT64_C(  -975.54) },
      { SIMDE_FLOAT64_C(   913.43), SIMDE_FLOAT64_C(   909.98) },
      { SIMDE_FLOAT64_C(   523.37), SIMDE_FLOAT64_C(   874.37) },
      { SIMDE_FLOAT64_C(408643.89), SIMDE_FLOAT64_C(407453.43) } },
    { { SIMDE_FLOAT64_C(   967.82), SIMDE_FLOAT64_C(   443.78) },
      { SIMDE_FLOAT64_C(  -249.02), SIMDE_FLOAT64_C(  -138.82) },
      { SIMDE_FLOAT64_C(   103.81), SIMDE_FLOAT64_C(  -819.21) },
      { SIMDE_FLOAT64_C(241110.35), SIMDE_FLOAT64_C(133533.56) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2_t a = simde_vld1q_f64(test_vec[i].a);
    simde_float64x2_t b = simde_vld1q_f64(test_vec[i].b);
    simde_float64x2_t r = simde_vld1q_f64(test_vec[i].r);
    simde_float64x2_t r_ = simde_vcmlaq_rot180_f64(r, a, b);
    simde_test_arm_neon_assert_equal_f64x2(r_, simde_vld1q_f64(test_vec[i].r_), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x2_t a = simde_test_arm_neon_random_f64x2(-1000.0f, 1000.0f);
    simde_float64x2_t b = simde_test_arm_neon_random_f64x2(-1000.0f, 1000.0f);
    simde_float64x2_t r = simde_test_arm_neon_random_f64x2(-1000.0f, 1000.0f);
    simde_float64x2_t r_ = simde_vcmlaq_rot180_f64(r, a, b);

    simde_test_arm_neon_write_f64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f64x2(2, r, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f64x2(2, r_, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vcmla_rot180_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcmlaq_rot180_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcmlaq_rot180_f64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
