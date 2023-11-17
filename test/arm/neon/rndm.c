#define SIMDE_TEST_ARM_NEON_INSN rndm

#include "test-neon.h"
#include "../../../simde/arm/neon/rndm.h"

static int
test_simde_vrndmh_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16 a;
    simde_float16 r;
  } test_vec[] = {
    {    SIMDE_FLOAT16_VALUE(  -9.173),
         SIMDE_FLOAT16_VALUE( -10.000) },
    {    SIMDE_FLOAT16_VALUE(  11.447),
         SIMDE_FLOAT16_VALUE(  11.000) },
    {    SIMDE_FLOAT16_VALUE( -12.280),
         SIMDE_FLOAT16_VALUE( -13.000) },
    {    SIMDE_FLOAT16_VALUE(  -3.306),
         SIMDE_FLOAT16_VALUE(  -4.000) },
    {    SIMDE_FLOAT16_VALUE(  11.735),
         SIMDE_FLOAT16_VALUE(  11.000) },
    {    SIMDE_FLOAT16_VALUE( -10.946),
         SIMDE_FLOAT16_VALUE( -11.000) },
    {    SIMDE_FLOAT16_VALUE(   9.931),
         SIMDE_FLOAT16_VALUE(   9.000) },
    {    SIMDE_FLOAT16_VALUE( -12.979),
         SIMDE_FLOAT16_VALUE( -13.000) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16_t a = test_vec[i].a;
    simde_float16_t r = simde_vrndmh_f16(a);

    simde_assert_equal_f16(r, test_vec[i].r, 1);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16_t a = simde_test_codegen_random_f16(-100.0f, 100.0f);
    simde_float16_t r = simde_vrndmh_f16(a);

    simde_test_codegen_write_f16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_f16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vrndm_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16 a[4];
    simde_float16 r[4];
  } test_vec[] = {
    { {  SIMDE_FLOAT16_VALUE(  -2.379),  SIMDE_FLOAT16_VALUE(   4.542),  SIMDE_FLOAT16_VALUE(  -7.585),  SIMDE_FLOAT16_VALUE(   6.519) },
      {  SIMDE_FLOAT16_VALUE(  -3.000),  SIMDE_FLOAT16_VALUE(   4.000),  SIMDE_FLOAT16_VALUE(  -8.000),  SIMDE_FLOAT16_VALUE(   6.000) } },
    { {  SIMDE_FLOAT16_VALUE( -11.393),  SIMDE_FLOAT16_VALUE(  13.886),  SIMDE_FLOAT16_VALUE(  -1.843),  SIMDE_FLOAT16_VALUE( -10.969) },
      {  SIMDE_FLOAT16_VALUE( -12.000),  SIMDE_FLOAT16_VALUE(  13.000),  SIMDE_FLOAT16_VALUE(  -2.000),  SIMDE_FLOAT16_VALUE( -11.000) } },
    { {  SIMDE_FLOAT16_VALUE(   2.602),  SIMDE_FLOAT16_VALUE(  -0.236),  SIMDE_FLOAT16_VALUE(   4.740),  SIMDE_FLOAT16_VALUE( -12.796) },
      {  SIMDE_FLOAT16_VALUE(   2.000),  SIMDE_FLOAT16_VALUE(  -1.000),  SIMDE_FLOAT16_VALUE(   4.000),  SIMDE_FLOAT16_VALUE( -13.000) } },
    { {  SIMDE_FLOAT16_VALUE( -11.112),  SIMDE_FLOAT16_VALUE(  -2.740),  SIMDE_FLOAT16_VALUE(  11.841),  SIMDE_FLOAT16_VALUE( -11.292) },
      {  SIMDE_FLOAT16_VALUE( -12.000),  SIMDE_FLOAT16_VALUE(  -3.000),  SIMDE_FLOAT16_VALUE(  11.000),  SIMDE_FLOAT16_VALUE( -12.000) } },
    { {  SIMDE_FLOAT16_VALUE( -14.513),  SIMDE_FLOAT16_VALUE( -12.480),  SIMDE_FLOAT16_VALUE(   7.073),  SIMDE_FLOAT16_VALUE(  -0.692) },
      {  SIMDE_FLOAT16_VALUE( -15.000),  SIMDE_FLOAT16_VALUE( -13.000),  SIMDE_FLOAT16_VALUE(   7.000),  SIMDE_FLOAT16_VALUE(  -1.000) } },
    { {  SIMDE_FLOAT16_VALUE(   8.690),  SIMDE_FLOAT16_VALUE(   0.633),  SIMDE_FLOAT16_VALUE(  -6.096),  SIMDE_FLOAT16_VALUE(  -5.570) },
      {  SIMDE_FLOAT16_VALUE(   8.000),  SIMDE_FLOAT16_VALUE(   0.000),  SIMDE_FLOAT16_VALUE(  -7.000),  SIMDE_FLOAT16_VALUE(  -6.000) } },
    { {  SIMDE_FLOAT16_VALUE(  10.356),  SIMDE_FLOAT16_VALUE(  11.634),  SIMDE_FLOAT16_VALUE(   1.680),  SIMDE_FLOAT16_VALUE(  -3.994) },
      {  SIMDE_FLOAT16_VALUE(  10.000),  SIMDE_FLOAT16_VALUE(  11.000),  SIMDE_FLOAT16_VALUE(   1.000),  SIMDE_FLOAT16_VALUE(  -4.000) } },
    { {  SIMDE_FLOAT16_VALUE(   6.787),  SIMDE_FLOAT16_VALUE(   0.691),  SIMDE_FLOAT16_VALUE(   0.723),  SIMDE_FLOAT16_VALUE(  -2.915) },
      {  SIMDE_FLOAT16_VALUE(   6.000),  SIMDE_FLOAT16_VALUE(   0.000),  SIMDE_FLOAT16_VALUE(   0.000),  SIMDE_FLOAT16_VALUE(  -3.000) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x4_t a = simde_vld1_f16(test_vec[i].a);
    simde_float16x4_t r = simde_vrndm_f16(a);

    simde_test_arm_neon_assert_equal_f16x4(r, simde_vld1_f16(test_vec[i].r), 1);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16x4_t a = simde_test_arm_neon_random_f16x4(-100.0f, 100.0f);
    simde_float16x4_t r = simde_vrndm_f16(a);

    simde_test_arm_neon_write_f16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vrndm_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a[2];
    simde_float32 r[2];
  } test_vec[] = {
    #if defined(SIMDE_FAST_NANS) && !defined(SIMDE_FAST_MATH)
    { {            SIMDE_MATH_NANF,           -SIMDE_MATH_NANF },
      {            SIMDE_MATH_NANF,           -SIMDE_MATH_NANF } },
    #endif
    { { SIMDE_FLOAT32_C(    -1.50), SIMDE_FLOAT32_C(     1.50) },
      { SIMDE_FLOAT32_C(    -2.00), SIMDE_FLOAT32_C(     1.00) } },
    { { SIMDE_FLOAT32_C(    -2.50), SIMDE_FLOAT32_C(     2.50) },
      { SIMDE_FLOAT32_C(    -3.00), SIMDE_FLOAT32_C(     2.00) } },

    { { SIMDE_FLOAT32_C(  -897.30), SIMDE_FLOAT32_C(   351.51) },
      { SIMDE_FLOAT32_C(  -898.00), SIMDE_FLOAT32_C(   351.00) } },
    { { SIMDE_FLOAT32_C(  -396.24), SIMDE_FLOAT32_C(  -136.90) },
      { SIMDE_FLOAT32_C(  -397.00), SIMDE_FLOAT32_C(  -137.00) } },
    { { SIMDE_FLOAT32_C(  -966.64), SIMDE_FLOAT32_C(   805.58) },
      { SIMDE_FLOAT32_C(  -967.00), SIMDE_FLOAT32_C(   805.00) } },
    { { SIMDE_FLOAT32_C(   848.81), SIMDE_FLOAT32_C(  -910.27) },
      { SIMDE_FLOAT32_C(   848.00), SIMDE_FLOAT32_C(  -911.00) } },
    { { SIMDE_FLOAT32_C(  -262.75), SIMDE_FLOAT32_C(   779.23) },
      { SIMDE_FLOAT32_C(  -263.00), SIMDE_FLOAT32_C(   779.00) } },
    { { SIMDE_FLOAT32_C(   824.19), SIMDE_FLOAT32_C(  -986.07) },
      { SIMDE_FLOAT32_C(   824.00), SIMDE_FLOAT32_C(  -987.00) } },
    { { SIMDE_FLOAT32_C(   272.13), SIMDE_FLOAT32_C(   812.56) },
      { SIMDE_FLOAT32_C(   272.00), SIMDE_FLOAT32_C(   812.00) } },
    { { SIMDE_FLOAT32_C(  -763.50), SIMDE_FLOAT32_C(   477.59) },
      { SIMDE_FLOAT32_C(  -764.00), SIMDE_FLOAT32_C(   477.00) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t a = simde_vld1_f32(test_vec[i].a);
    simde_float32x2_t r = simde_vrndm_f32(a);

    simde_test_arm_neon_assert_equal_f32x2(r, simde_vld1_f32(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x2_t a = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f);
    simde_float32x2_t r = simde_vrndm_f32(a);

    simde_test_arm_neon_write_f32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vrndm_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 a[1];
    simde_float64 r[1];
  } test_vec[] = {
    #if !defined(SIMDE_FAST_NANS)
    { {             SIMDE_MATH_NAN },
      {             SIMDE_MATH_NAN } },
    { {            -SIMDE_MATH_NAN },
      {            -SIMDE_MATH_NAN } },
    #endif
    { { SIMDE_FLOAT64_C(    -1.50) },
      { SIMDE_FLOAT64_C(    -2.00) } },
    { { SIMDE_FLOAT64_C(     1.50) },
      { SIMDE_FLOAT64_C(     1.00) } },
    { { SIMDE_FLOAT64_C(    -2.50) },
      { SIMDE_FLOAT64_C(    -3.00) } },
    { { SIMDE_FLOAT64_C(     2.50) },
      { SIMDE_FLOAT64_C(     2.00) } },

    { { SIMDE_FLOAT64_C(   333.88) },
      { SIMDE_FLOAT64_C(   333.00) } },
    { { SIMDE_FLOAT64_C(   629.40) },
      { SIMDE_FLOAT64_C(   629.00) } },
    { { SIMDE_FLOAT64_C(  -124.31) },
      { SIMDE_FLOAT64_C(  -125.00) } },
    { { SIMDE_FLOAT64_C(   133.65) },
      { SIMDE_FLOAT64_C(   133.00) } },
    { { SIMDE_FLOAT64_C(  -307.19) },
      { SIMDE_FLOAT64_C(  -308.00) } },
    { { SIMDE_FLOAT64_C(   596.65) },
      { SIMDE_FLOAT64_C(   596.00) } },
    { { SIMDE_FLOAT64_C(   827.64) },
      { SIMDE_FLOAT64_C(   827.00) } },
    { { SIMDE_FLOAT64_C(   250.89) },
      { SIMDE_FLOAT64_C(   250.00) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x1_t a = simde_vld1_f64(test_vec[i].a);
    simde_float64x1_t r = simde_vrndm_f64(a);

    simde_test_arm_neon_assert_equal_f64x1(r, simde_vld1_f64(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x1_t a = simde_test_arm_neon_random_f64x1(-1000.0, 1000.0);
    simde_float64x1_t r = simde_vrndm_f64(a);

    simde_test_arm_neon_write_f64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vrndmq_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16 a[8];
    simde_float16 r[8];
  } test_vec[] = {
    { {  SIMDE_FLOAT16_VALUE(  12.316),  SIMDE_FLOAT16_VALUE(   6.207),  SIMDE_FLOAT16_VALUE(  -7.010),  SIMDE_FLOAT16_VALUE(  -2.756),
         SIMDE_FLOAT16_VALUE(   3.880),  SIMDE_FLOAT16_VALUE(  -4.529),  SIMDE_FLOAT16_VALUE(  -1.830),  SIMDE_FLOAT16_VALUE(   7.099) },
      {  SIMDE_FLOAT16_VALUE(  12.000),  SIMDE_FLOAT16_VALUE(   6.000),  SIMDE_FLOAT16_VALUE(  -8.000),  SIMDE_FLOAT16_VALUE(  -3.000),
         SIMDE_FLOAT16_VALUE(   3.000),  SIMDE_FLOAT16_VALUE(  -5.000),  SIMDE_FLOAT16_VALUE(  -2.000),  SIMDE_FLOAT16_VALUE(   7.000) } },
    { {  SIMDE_FLOAT16_VALUE(   0.069),  SIMDE_FLOAT16_VALUE( -13.074),  SIMDE_FLOAT16_VALUE(   4.743),  SIMDE_FLOAT16_VALUE(  -7.822),
         SIMDE_FLOAT16_VALUE(   6.738),  SIMDE_FLOAT16_VALUE(   3.987),  SIMDE_FLOAT16_VALUE(   8.981),  SIMDE_FLOAT16_VALUE(   6.574) },
      {  SIMDE_FLOAT16_VALUE(   0.000),  SIMDE_FLOAT16_VALUE( -14.000),  SIMDE_FLOAT16_VALUE(   4.000),  SIMDE_FLOAT16_VALUE(  -8.000),
         SIMDE_FLOAT16_VALUE(   6.000),  SIMDE_FLOAT16_VALUE(   3.000),  SIMDE_FLOAT16_VALUE(   8.000),  SIMDE_FLOAT16_VALUE(   6.000) } },
    { {  SIMDE_FLOAT16_VALUE( -12.115),  SIMDE_FLOAT16_VALUE(  -9.219),  SIMDE_FLOAT16_VALUE( -11.847),  SIMDE_FLOAT16_VALUE(  -0.519),
         SIMDE_FLOAT16_VALUE( -12.974),  SIMDE_FLOAT16_VALUE(   3.431),  SIMDE_FLOAT16_VALUE( -13.006),  SIMDE_FLOAT16_VALUE(  -3.632) },
      {  SIMDE_FLOAT16_VALUE( -13.000),  SIMDE_FLOAT16_VALUE( -10.000),  SIMDE_FLOAT16_VALUE( -12.000),  SIMDE_FLOAT16_VALUE(  -1.000),
         SIMDE_FLOAT16_VALUE( -13.000),  SIMDE_FLOAT16_VALUE(   3.000),  SIMDE_FLOAT16_VALUE( -14.000),  SIMDE_FLOAT16_VALUE(  -4.000) } },
    { {  SIMDE_FLOAT16_VALUE(   5.561),  SIMDE_FLOAT16_VALUE(   4.862),  SIMDE_FLOAT16_VALUE(  -2.777),  SIMDE_FLOAT16_VALUE(  -1.666),
         SIMDE_FLOAT16_VALUE( -14.182),  SIMDE_FLOAT16_VALUE(  10.188),  SIMDE_FLOAT16_VALUE( -12.497),  SIMDE_FLOAT16_VALUE(   7.534) },
      {  SIMDE_FLOAT16_VALUE(   5.000),  SIMDE_FLOAT16_VALUE(   4.000),  SIMDE_FLOAT16_VALUE(  -3.000),  SIMDE_FLOAT16_VALUE(  -2.000),
         SIMDE_FLOAT16_VALUE( -15.000),  SIMDE_FLOAT16_VALUE(  10.000),  SIMDE_FLOAT16_VALUE( -13.000),  SIMDE_FLOAT16_VALUE(   7.000) } },
    { {  SIMDE_FLOAT16_VALUE(  10.757),  SIMDE_FLOAT16_VALUE(   5.534),  SIMDE_FLOAT16_VALUE(   0.216),  SIMDE_FLOAT16_VALUE(  -0.573),
         SIMDE_FLOAT16_VALUE(  -3.911),  SIMDE_FLOAT16_VALUE( -14.799),  SIMDE_FLOAT16_VALUE(  -6.012),  SIMDE_FLOAT16_VALUE(  -0.565) },
      {  SIMDE_FLOAT16_VALUE(  10.000),  SIMDE_FLOAT16_VALUE(   5.000),  SIMDE_FLOAT16_VALUE(   0.000),  SIMDE_FLOAT16_VALUE(  -1.000),
         SIMDE_FLOAT16_VALUE(  -4.000),  SIMDE_FLOAT16_VALUE( -15.000),  SIMDE_FLOAT16_VALUE(  -7.000),  SIMDE_FLOAT16_VALUE(  -1.000) } },
    { {  SIMDE_FLOAT16_VALUE(   8.949),  SIMDE_FLOAT16_VALUE( -11.439),  SIMDE_FLOAT16_VALUE(  14.844),  SIMDE_FLOAT16_VALUE(  -6.808),
         SIMDE_FLOAT16_VALUE(  14.334),  SIMDE_FLOAT16_VALUE(  -9.234),  SIMDE_FLOAT16_VALUE(  -2.210),  SIMDE_FLOAT16_VALUE(   8.783) },
      {  SIMDE_FLOAT16_VALUE(   8.000),  SIMDE_FLOAT16_VALUE( -12.000),  SIMDE_FLOAT16_VALUE(  14.000),  SIMDE_FLOAT16_VALUE(  -7.000),
         SIMDE_FLOAT16_VALUE(  14.000),  SIMDE_FLOAT16_VALUE( -10.000),  SIMDE_FLOAT16_VALUE(  -3.000),  SIMDE_FLOAT16_VALUE(   8.000) } },
    { {  SIMDE_FLOAT16_VALUE(   2.023),  SIMDE_FLOAT16_VALUE( -13.690),  SIMDE_FLOAT16_VALUE(  -3.775),  SIMDE_FLOAT16_VALUE(  -3.677),
         SIMDE_FLOAT16_VALUE(  -1.737),  SIMDE_FLOAT16_VALUE(  -0.698),  SIMDE_FLOAT16_VALUE( -12.550),  SIMDE_FLOAT16_VALUE(  -3.609) },
      {  SIMDE_FLOAT16_VALUE(   2.000),  SIMDE_FLOAT16_VALUE( -14.000),  SIMDE_FLOAT16_VALUE(  -4.000),  SIMDE_FLOAT16_VALUE(  -4.000),
         SIMDE_FLOAT16_VALUE(  -2.000),  SIMDE_FLOAT16_VALUE(  -1.000),  SIMDE_FLOAT16_VALUE( -13.000),  SIMDE_FLOAT16_VALUE(  -4.000) } },
    { {  SIMDE_FLOAT16_VALUE( -10.790),  SIMDE_FLOAT16_VALUE(   7.928),  SIMDE_FLOAT16_VALUE(  -4.525),  SIMDE_FLOAT16_VALUE(  -2.016),
         SIMDE_FLOAT16_VALUE(   9.566),  SIMDE_FLOAT16_VALUE( -11.880),  SIMDE_FLOAT16_VALUE(  12.959),  SIMDE_FLOAT16_VALUE(  -6.830) },
      {  SIMDE_FLOAT16_VALUE( -11.000),  SIMDE_FLOAT16_VALUE(   7.000),  SIMDE_FLOAT16_VALUE(  -5.000),  SIMDE_FLOAT16_VALUE(  -3.000),
         SIMDE_FLOAT16_VALUE(   9.000),  SIMDE_FLOAT16_VALUE( -12.000),  SIMDE_FLOAT16_VALUE(  12.000),  SIMDE_FLOAT16_VALUE(  -7.000) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x8_t a = simde_vld1q_f16(test_vec[i].a);
    simde_float16x8_t r = simde_vrndmq_f16(a);
    simde_test_arm_neon_assert_equal_f16x8(r, simde_vld1q_f16(test_vec[i].r), 1);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16x8_t a = simde_test_arm_neon_random_f16x8(-100.0f, 100.0f);
    simde_float16x8_t r = simde_vrndmq_f16(a);

    simde_test_arm_neon_write_f16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vrndmq_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a[4];
    simde_float32 r[4];
  } test_vec[] = {
    #if !defined(SIMDE_FAST_NANS)
    { {            SIMDE_MATH_NANF,           -SIMDE_MATH_NANF,            SIMDE_MATH_NANF,           -SIMDE_MATH_NANF },
      {            SIMDE_MATH_NANF,           -SIMDE_MATH_NANF,            SIMDE_MATH_NANF,           -SIMDE_MATH_NANF } },
    #endif
    { { SIMDE_FLOAT32_C(    -1.50), SIMDE_FLOAT32_C(     1.50), SIMDE_FLOAT32_C(    -2.50), SIMDE_FLOAT32_C(     2.50) },
      { SIMDE_FLOAT32_C(    -2.00), SIMDE_FLOAT32_C(     1.00), SIMDE_FLOAT32_C(    -3.00), SIMDE_FLOAT32_C(     2.00) } },

    { { SIMDE_FLOAT32_C(   744.58), SIMDE_FLOAT32_C(  -175.23), SIMDE_FLOAT32_C(  -591.29), SIMDE_FLOAT32_C(   759.75) },
      { SIMDE_FLOAT32_C(   744.00), SIMDE_FLOAT32_C(  -176.00), SIMDE_FLOAT32_C(  -592.00), SIMDE_FLOAT32_C(   759.00) } },
    { { SIMDE_FLOAT32_C(   273.17), SIMDE_FLOAT32_C(   118.54), SIMDE_FLOAT32_C(  -744.67), SIMDE_FLOAT32_C(   375.86) },
      { SIMDE_FLOAT32_C(   273.00), SIMDE_FLOAT32_C(   118.00), SIMDE_FLOAT32_C(  -745.00), SIMDE_FLOAT32_C(   375.00) } },
    { { SIMDE_FLOAT32_C(  -529.96), SIMDE_FLOAT32_C(  -140.92), SIMDE_FLOAT32_C(  -761.03), SIMDE_FLOAT32_C(  -496.59) },
      { SIMDE_FLOAT32_C(  -530.00), SIMDE_FLOAT32_C(  -141.00), SIMDE_FLOAT32_C(  -762.00), SIMDE_FLOAT32_C(  -497.00) } },
    { { SIMDE_FLOAT32_C(  -335.34), SIMDE_FLOAT32_C(  -912.22), SIMDE_FLOAT32_C(  -406.86), SIMDE_FLOAT32_C(   401.91) },
      { SIMDE_FLOAT32_C(  -336.00), SIMDE_FLOAT32_C(  -913.00), SIMDE_FLOAT32_C(  -407.00), SIMDE_FLOAT32_C(   401.00) } },
    { { SIMDE_FLOAT32_C(   867.01), SIMDE_FLOAT32_C(  -582.67), SIMDE_FLOAT32_C(   415.83), SIMDE_FLOAT32_C(   139.14) },
      { SIMDE_FLOAT32_C(   867.00), SIMDE_FLOAT32_C(  -583.00), SIMDE_FLOAT32_C(   415.00), SIMDE_FLOAT32_C(   139.00) } },
    { { SIMDE_FLOAT32_C(  -770.11), SIMDE_FLOAT32_C(   652.33), SIMDE_FLOAT32_C(  -383.28), SIMDE_FLOAT32_C(   563.77) },
      { SIMDE_FLOAT32_C(  -771.00), SIMDE_FLOAT32_C(   652.00), SIMDE_FLOAT32_C(  -384.00), SIMDE_FLOAT32_C(   563.00) } },
    { { SIMDE_FLOAT32_C(   281.73), SIMDE_FLOAT32_C(   492.41), SIMDE_FLOAT32_C(  -302.57), SIMDE_FLOAT32_C(   974.54) },
      { SIMDE_FLOAT32_C(   281.00), SIMDE_FLOAT32_C(   492.00), SIMDE_FLOAT32_C(  -303.00), SIMDE_FLOAT32_C(   974.00) } },
    { { SIMDE_FLOAT32_C(    89.06), SIMDE_FLOAT32_C(  -474.93), SIMDE_FLOAT32_C(   225.42), SIMDE_FLOAT32_C(  -166.36) },
      { SIMDE_FLOAT32_C(    89.00), SIMDE_FLOAT32_C(  -475.00), SIMDE_FLOAT32_C(   225.00), SIMDE_FLOAT32_C(  -167.00) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_float32x4_t r = simde_vrndmq_f32(a);
    simde_test_arm_neon_assert_equal_f32x4(r, simde_vld1q_f32(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x4_t a = simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f);
    simde_float32x4_t r = simde_vrndmq_f32(a);

    simde_test_arm_neon_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vrndmq_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 a[2];
    simde_float64 r[2];
  } test_vec[] = {
    #if !defined(SIMDE_FAST_NANS)
    { {             SIMDE_MATH_NAN,            -SIMDE_MATH_NAN },
      {             SIMDE_MATH_NAN,            -SIMDE_MATH_NAN } },
    #endif
    { { SIMDE_FLOAT64_C(    -1.50), SIMDE_FLOAT64_C(     1.50) },
      { SIMDE_FLOAT64_C(    -2.00), SIMDE_FLOAT64_C(     1.00) } },
    { { SIMDE_FLOAT64_C(    -2.50), SIMDE_FLOAT64_C(     2.50) },
      { SIMDE_FLOAT64_C(    -3.00), SIMDE_FLOAT64_C(     2.00) } },

    { { SIMDE_FLOAT64_C(   349.83), SIMDE_FLOAT64_C(   634.13) },
      { SIMDE_FLOAT64_C(   349.00), SIMDE_FLOAT64_C(   634.00) } },
    { { SIMDE_FLOAT64_C(  -406.61), SIMDE_FLOAT64_C(  -377.00) },
      { SIMDE_FLOAT64_C(  -407.00), SIMDE_FLOAT64_C(  -377.00) } },
    { { SIMDE_FLOAT64_C(  -247.33), SIMDE_FLOAT64_C(  -151.28) },
      { SIMDE_FLOAT64_C(  -248.00), SIMDE_FLOAT64_C(  -152.00) } },
    { { SIMDE_FLOAT64_C(   998.86), SIMDE_FLOAT64_C(   222.71) },
      { SIMDE_FLOAT64_C(   998.00), SIMDE_FLOAT64_C(   222.00) } },
    { { SIMDE_FLOAT64_C(   707.80), SIMDE_FLOAT64_C(  -762.17) },
      { SIMDE_FLOAT64_C(   707.00), SIMDE_FLOAT64_C(  -763.00) } },
    { { SIMDE_FLOAT64_C(   726.12), SIMDE_FLOAT64_C(  -627.54) },
      { SIMDE_FLOAT64_C(   726.00), SIMDE_FLOAT64_C(  -628.00) } },
    { { SIMDE_FLOAT64_C(  -674.40), SIMDE_FLOAT64_C(  -680.74) },
      { SIMDE_FLOAT64_C(  -675.00), SIMDE_FLOAT64_C(  -681.00) } },
    { { SIMDE_FLOAT64_C(   774.37), SIMDE_FLOAT64_C(  -807.39) },
      { SIMDE_FLOAT64_C(   774.00), SIMDE_FLOAT64_C(  -808.00) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2_t a = simde_vld1q_f64(test_vec[i].a);
    simde_float64x2_t r = simde_vrndmq_f64(a);

    simde_test_arm_neon_assert_equal_f64x2(r, simde_vld1q_f64(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x2_t a = simde_test_arm_neon_random_f64x2(-1000.0, 1000.0);
    simde_float64x2_t r = simde_vrndmq_f64(a);

    simde_test_arm_neon_write_f64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vrndmh_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vrndm_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vrndm_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vrndm_f64)

SIMDE_TEST_FUNC_LIST_ENTRY(vrndmq_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vrndmq_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vrndmq_f64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
