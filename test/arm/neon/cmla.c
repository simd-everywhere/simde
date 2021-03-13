#define SIMDE_TEST_ARM_NEON_INSN cmla

#include "test-neon.h"
#include "../../../simde/arm/neon/cmla.h"

static int
test_simde_vcmla_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a[4];
    simde_float32 b[4];
    simde_float32 r[4];
    simde_float32 r_[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   212.87), SIMDE_FLOAT32_C(    70.46) },
      { SIMDE_FLOAT32_C(  -900.86), SIMDE_FLOAT32_C(  -975.82) },
      { SIMDE_FLOAT32_C(  -978.80), SIMDE_FLOAT32_C(   764.65) },
      { SIMDE_FLOAT32_C(-192744.86), SIMDE_FLOAT32_C(-206958.16) } },
    { { SIMDE_FLOAT32_C(  -187.99), SIMDE_FLOAT32_C(    49.57) },
      { SIMDE_FLOAT32_C(  -750.73), SIMDE_FLOAT32_C(   590.72) },
      { SIMDE_FLOAT32_C(   251.58), SIMDE_FLOAT32_C(   997.06) },
      { SIMDE_FLOAT32_C(141381.31), SIMDE_FLOAT32_C(-110052.39) } },
    { { SIMDE_FLOAT32_C(  -131.09), SIMDE_FLOAT32_C(  -878.84) },
      { SIMDE_FLOAT32_C(   800.24), SIMDE_FLOAT32_C(   223.42) },
      { SIMDE_FLOAT32_C(  -487.42), SIMDE_FLOAT32_C(  -464.44) },
      { SIMDE_FLOAT32_C(-105390.88), SIMDE_FLOAT32_C(-29752.57) } },
    { { SIMDE_FLOAT32_C(   669.97), SIMDE_FLOAT32_C(  -863.16) },
      { SIMDE_FLOAT32_C(   580.78), SIMDE_FLOAT32_C(  -195.58) },
      { SIMDE_FLOAT32_C(  -125.02), SIMDE_FLOAT32_C(  -125.29) },
      { SIMDE_FLOAT32_C(388980.16), SIMDE_FLOAT32_C(-131158.02) } },
    { { SIMDE_FLOAT32_C(    11.00), SIMDE_FLOAT32_C(  -886.22) },
      { SIMDE_FLOAT32_C(  -210.36), SIMDE_FLOAT32_C(  -525.26) },
      { SIMDE_FLOAT32_C(  -275.11), SIMDE_FLOAT32_C(  -377.71) },
      { SIMDE_FLOAT32_C( -2589.07), SIMDE_FLOAT32_C( -6155.57) } },
    { { SIMDE_FLOAT32_C(   383.29), SIMDE_FLOAT32_C(   937.75) },
      { SIMDE_FLOAT32_C(   692.75), SIMDE_FLOAT32_C(   482.42) },
      { SIMDE_FLOAT32_C(   961.94), SIMDE_FLOAT32_C(   713.95) },
      { SIMDE_FLOAT32_C(266486.09), SIMDE_FLOAT32_C(185620.72) } },
    { { SIMDE_FLOAT32_C(   247.08), SIMDE_FLOAT32_C(  -226.05) },
      { SIMDE_FLOAT32_C(  -236.48), SIMDE_FLOAT32_C(   496.35) },
      { SIMDE_FLOAT32_C(  -635.33), SIMDE_FLOAT32_C(  -984.90) },
      { SIMDE_FLOAT32_C(-59064.81), SIMDE_FLOAT32_C(121653.26) } },
    { { SIMDE_FLOAT32_C(   493.40), SIMDE_FLOAT32_C(   233.58) },
      { SIMDE_FLOAT32_C(  -863.74), SIMDE_FLOAT32_C(   293.64) },
      { SIMDE_FLOAT32_C(  -543.00), SIMDE_FLOAT32_C(  -351.16) },
      { SIMDE_FLOAT32_C(-426712.31), SIMDE_FLOAT32_C(144530.83) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t a = simde_vld1_f32(test_vec[i].a);
    simde_float32x2_t b = simde_vld1_f32(test_vec[i].b);
    simde_float32x2_t r = simde_vld1_f32(test_vec[i].r);
    simde_float32x2_t r_ = simde_vcmla_f32(r, a, b);

    simde_test_arm_neon_assert_equal_f32x2(r_, simde_vld1_f32(test_vec[i].r_), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x2_t a = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f);
    simde_float32x2_t b = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f);
    simde_float32x2_t r = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f);
    simde_float32x2_t r_ = simde_vcmla_f32(r, a, b);

    simde_test_arm_neon_write_f32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x2(2, r, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x2(2, r_, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcmlaq_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a[4];
    simde_float32 b[4];
    simde_float32 r[4];
    simde_float32 r_[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   -44.15), SIMDE_FLOAT32_C(   162.35), SIMDE_FLOAT32_C(  -263.81), SIMDE_FLOAT32_C(  -419.51) },
      { SIMDE_FLOAT32_C(   557.47), SIMDE_FLOAT32_C(   231.31), SIMDE_FLOAT32_C(  -146.84), SIMDE_FLOAT32_C(  -373.27) },
      { SIMDE_FLOAT32_C(   890.34), SIMDE_FLOAT32_C(   811.38), SIMDE_FLOAT32_C(  -300.85), SIMDE_FLOAT32_C(   -15.80) },
      { SIMDE_FLOAT32_C(-23721.96), SIMDE_FLOAT32_C( -9400.96), SIMDE_FLOAT32_C( 38437.01), SIMDE_FLOAT32_C( 98456.55) } },
    { { SIMDE_FLOAT32_C(  -992.19), SIMDE_FLOAT32_C(   519.83), SIMDE_FLOAT32_C(  -699.21), SIMDE_FLOAT32_C(   988.58) },
      { SIMDE_FLOAT32_C(   744.14), SIMDE_FLOAT32_C(  -947.63), SIMDE_FLOAT32_C(   992.55), SIMDE_FLOAT32_C(   654.06) },
      { SIMDE_FLOAT32_C(  -430.76), SIMDE_FLOAT32_C(  -498.64), SIMDE_FLOAT32_C(  -584.99), SIMDE_FLOAT32_C(   338.77) },
      { SIMDE_FLOAT32_C(-738759.06), SIMDE_FLOAT32_C(939730.38), SIMDE_FLOAT32_C(-694585.88), SIMDE_FLOAT32_C(-456986.53) } },
    { { SIMDE_FLOAT32_C(  -355.89), SIMDE_FLOAT32_C(  -589.60), SIMDE_FLOAT32_C(   579.00), SIMDE_FLOAT32_C(  -954.28) },
      { SIMDE_FLOAT32_C(  -272.65), SIMDE_FLOAT32_C(   977.05), SIMDE_FLOAT32_C(  -572.00), SIMDE_FLOAT32_C(   683.20) },
      { SIMDE_FLOAT32_C(   139.40), SIMDE_FLOAT32_C(   164.19), SIMDE_FLOAT32_C(  -736.30), SIMDE_FLOAT32_C(  -303.12) },
      { SIMDE_FLOAT32_C( 97172.81), SIMDE_FLOAT32_C(-347558.16), SIMDE_FLOAT32_C(-331924.31), SIMDE_FLOAT32_C(395269.69) } },
    { { SIMDE_FLOAT32_C(  -604.50), SIMDE_FLOAT32_C(   116.85), SIMDE_FLOAT32_C(   323.61), SIMDE_FLOAT32_C(  -714.16) },
      { SIMDE_FLOAT32_C(   -71.76), SIMDE_FLOAT32_C(  -977.24), SIMDE_FLOAT32_C(   270.05), SIMDE_FLOAT32_C(   -63.95) },
      { SIMDE_FLOAT32_C(   542.59), SIMDE_FLOAT32_C(   570.84), SIMDE_FLOAT32_C(   -75.38), SIMDE_FLOAT32_C(   286.73) },
      { SIMDE_FLOAT32_C( 43921.51), SIMDE_FLOAT32_C(591312.44), SIMDE_FLOAT32_C( 87315.49), SIMDE_FLOAT32_C(-20408.13) } },
    { { SIMDE_FLOAT32_C(   623.21), SIMDE_FLOAT32_C(   -82.82), SIMDE_FLOAT32_C(   -59.21), SIMDE_FLOAT32_C(  -807.55) },
      { SIMDE_FLOAT32_C(   418.54), SIMDE_FLOAT32_C(   355.80), SIMDE_FLOAT32_C(   531.22), SIMDE_FLOAT32_C(  -937.34) },
      { SIMDE_FLOAT32_C(   766.20), SIMDE_FLOAT32_C(   110.21), SIMDE_FLOAT32_C(  -891.63), SIMDE_FLOAT32_C(  -506.46) },
      { SIMDE_FLOAT32_C(261604.53), SIMDE_FLOAT32_C(221848.33), SIMDE_FLOAT32_C(-32345.16), SIMDE_FLOAT32_C( 54993.44) } },
    { { SIMDE_FLOAT32_C(    87.27), SIMDE_FLOAT32_C(  -463.63), SIMDE_FLOAT32_C(  -823.25), SIMDE_FLOAT32_C(  -773.33) },
      { SIMDE_FLOAT32_C(   700.56), SIMDE_FLOAT32_C(  -559.56), SIMDE_FLOAT32_C(   -76.45), SIMDE_FLOAT32_C(  -903.93) },
      { SIMDE_FLOAT32_C(   557.30), SIMDE_FLOAT32_C(  -752.84), SIMDE_FLOAT32_C(  -618.09), SIMDE_FLOAT32_C(  -514.46) },
      { SIMDE_FLOAT32_C( 61695.17), SIMDE_FLOAT32_C(-49585.64), SIMDE_FLOAT32_C( 62319.37), SIMDE_FLOAT32_C(743645.94) } },
    { { SIMDE_FLOAT32_C(  -730.08), SIMDE_FLOAT32_C(   651.96), SIMDE_FLOAT32_C(   421.58), SIMDE_FLOAT32_C(   812.51) },
      { SIMDE_FLOAT32_C(   222.80), SIMDE_FLOAT32_C(  -653.79), SIMDE_FLOAT32_C(    99.24), SIMDE_FLOAT32_C(  -153.99) },
      { SIMDE_FLOAT32_C(   263.39), SIMDE_FLOAT32_C(  -959.97), SIMDE_FLOAT32_C(    38.46), SIMDE_FLOAT32_C(  -318.07) },
      { SIMDE_FLOAT32_C(-162398.44), SIMDE_FLOAT32_C(476359.03), SIMDE_FLOAT32_C( 41876.06), SIMDE_FLOAT32_C(-65237.18) } },
    { { SIMDE_FLOAT32_C(   395.83), SIMDE_FLOAT32_C(  -430.33), SIMDE_FLOAT32_C(  -255.42), SIMDE_FLOAT32_C(   162.03) },
      { SIMDE_FLOAT32_C(   679.89), SIMDE_FLOAT32_C(  -147.05), SIMDE_FLOAT32_C(   655.57), SIMDE_FLOAT32_C(  -232.84) },
      { SIMDE_FLOAT32_C(   389.33), SIMDE_FLOAT32_C(   832.32), SIMDE_FLOAT32_C(    -6.17), SIMDE_FLOAT32_C(    89.89) },
      { SIMDE_FLOAT32_C(269510.19), SIMDE_FLOAT32_C(-57374.48), SIMDE_FLOAT32_C(-167451.86), SIMDE_FLOAT32_C( 59561.88) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_float32x4_t b = simde_vld1q_f32(test_vec[i].b);
    simde_float32x4_t r = simde_vld1q_f32(test_vec[i].r);
    simde_float32x4_t r_ = simde_vcmlaq_f32(r, a, b);
    simde_test_arm_neon_assert_equal_f32x4(r_, simde_vld1q_f32(test_vec[i].r_), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x4_t a = simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f);
    simde_float32x4_t b = simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f);
    simde_float32x4_t r = simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f);
    simde_float32x4_t r_ = simde_vcmlaq_f32(r, a, b);

    simde_test_arm_neon_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x4(2, r, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x4(2, r_, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcmlaq_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 a[2];
    simde_float64 b[2];
    simde_float64 r[2];
    simde_float64 r_[2];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(   -57.99), SIMDE_FLOAT64_C(   135.55) },
      { SIMDE_FLOAT64_C(  -596.04), SIMDE_FLOAT64_C(  -782.75) },
      { SIMDE_FLOAT64_C(  -359.68), SIMDE_FLOAT64_C(   599.02) },
      { SIMDE_FLOAT64_C( 34204.68), SIMDE_FLOAT64_C( 45990.69) } },
    { { SIMDE_FLOAT64_C(  -264.72), SIMDE_FLOAT64_C(  -256.75) },
      { SIMDE_FLOAT64_C(   447.46), SIMDE_FLOAT64_C(  -783.75) },
      { SIMDE_FLOAT64_C(   191.17), SIMDE_FLOAT64_C(  -558.46) },
      { SIMDE_FLOAT64_C(-118260.44), SIMDE_FLOAT64_C(206915.84) } },
    { { SIMDE_FLOAT64_C(  -770.71), SIMDE_FLOAT64_C(  -784.24) },
      { SIMDE_FLOAT64_C(  -699.41), SIMDE_FLOAT64_C(   563.40) },
      { SIMDE_FLOAT64_C(   833.00), SIMDE_FLOAT64_C(   587.87) },
      { SIMDE_FLOAT64_C(539875.28), SIMDE_FLOAT64_C(-433630.14) } },
    { { SIMDE_FLOAT64_C(  -937.25), SIMDE_FLOAT64_C(  -903.59) },
      { SIMDE_FLOAT64_C(  -150.40), SIMDE_FLOAT64_C(  -333.08) },
      { SIMDE_FLOAT64_C(  -232.36), SIMDE_FLOAT64_C(   783.49) },
      { SIMDE_FLOAT64_C(140730.04), SIMDE_FLOAT64_C(312962.72) } },
    { { SIMDE_FLOAT64_C(   694.12), SIMDE_FLOAT64_C(   454.67) },
      { SIMDE_FLOAT64_C(   921.25), SIMDE_FLOAT64_C(  -888.91) },
      { SIMDE_FLOAT64_C(  -246.87), SIMDE_FLOAT64_C(  -960.96) },
      { SIMDE_FLOAT64_C(639211.18), SIMDE_FLOAT64_C(-617971.17) } },
    { { SIMDE_FLOAT64_C(    69.74), SIMDE_FLOAT64_C(   695.13) },
      { SIMDE_FLOAT64_C(   174.59), SIMDE_FLOAT64_C(   473.70) },
      { SIMDE_FLOAT64_C(   912.38), SIMDE_FLOAT64_C(   814.91) },
      { SIMDE_FLOAT64_C( 13088.29), SIMDE_FLOAT64_C( 33850.75) } },
    { { SIMDE_FLOAT64_C(    72.72), SIMDE_FLOAT64_C(  -352.34) },
      { SIMDE_FLOAT64_C(  -441.84), SIMDE_FLOAT64_C(  -479.82) },
      { SIMDE_FLOAT64_C(  -136.09), SIMDE_FLOAT64_C(   749.33) },
      { SIMDE_FLOAT64_C(-32266.69), SIMDE_FLOAT64_C(-34143.18) } },
    { { SIMDE_FLOAT64_C(   -38.28), SIMDE_FLOAT64_C(    93.20) },
      { SIMDE_FLOAT64_C(   965.09), SIMDE_FLOAT64_C(   262.31) },
      { SIMDE_FLOAT64_C(  -343.40), SIMDE_FLOAT64_C(   798.09) },
      { SIMDE_FLOAT64_C(-37287.05), SIMDE_FLOAT64_C( -9243.14) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2_t a = simde_vld1q_f64(test_vec[i].a);
    simde_float64x2_t b = simde_vld1q_f64(test_vec[i].b);
    simde_float64x2_t r = simde_vld1q_f64(test_vec[i].r);
    simde_float64x2_t r_ = simde_vcmlaq_f64(r, a, b);
    simde_test_arm_neon_assert_equal_f64x2(r_, simde_vld1q_f64(test_vec[i].r_), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x2_t a = simde_test_arm_neon_random_f64x2(-1000.0f, 1000.0f);
    simde_float64x2_t b = simde_test_arm_neon_random_f64x2(-1000.0f, 1000.0f);
    simde_float64x2_t r = simde_test_arm_neon_random_f64x2(-1000.0f, 1000.0f);
    simde_float64x2_t r_ = simde_vcmlaq_f64(r, a, b);

    simde_test_arm_neon_write_f64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f64x2(2, r, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f64x2(2, r_, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vcmla_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcmlaq_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcmlaq_f64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
