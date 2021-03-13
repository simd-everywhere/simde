#define SIMDE_TEST_ARM_NEON_INSN cmla

#include "test-neon.h"
#include "../../../simde/arm/neon/cmla.h"

/* * rot 0 * */

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

/* * rot 90 * */

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

/* * rot 180 * */

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

/* * rot 270 * */

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
SIMDE_TEST_FUNC_LIST_ENTRY(vcmla_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcmlaq_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcmlaq_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vcmla_rot90_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcmlaq_rot90_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcmlaq_rot90_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vcmla_rot180_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcmlaq_rot180_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcmlaq_rot180_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vcmla_rot270_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcmlaq_rot270_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcmlaq_rot270_f64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
