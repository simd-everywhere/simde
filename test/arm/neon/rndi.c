#define SIMDE_TEST_ARM_NEON_INSN rndi

#include "test-neon.h"
#include "../../../simde/arm/neon/rndi.h"

static int
test_simde_vrndih_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16 a;
    simde_float16 r;
  } test_vec[] = {
    {    SIMDE_FLOAT16_VALUE(  -1.971),
         SIMDE_FLOAT16_VALUE(  -2.000) },
    {    SIMDE_FLOAT16_VALUE(  10.750),
         SIMDE_FLOAT16_VALUE(  11.000) },
    {    SIMDE_FLOAT16_VALUE(   6.608),
         SIMDE_FLOAT16_VALUE(   7.000) },
    {    SIMDE_FLOAT16_VALUE( -13.543),
         SIMDE_FLOAT16_VALUE( -14.000) },
    {    SIMDE_FLOAT16_VALUE(  10.939),
         SIMDE_FLOAT16_VALUE(  11.000) },
    {    SIMDE_FLOAT16_VALUE( -14.116),
         SIMDE_FLOAT16_VALUE( -14.000) },
    {    SIMDE_FLOAT16_VALUE(  13.529),
         SIMDE_FLOAT16_VALUE(  14.000) },
    {    SIMDE_FLOAT16_VALUE(   0.532),
         SIMDE_FLOAT16_VALUE(   1.000) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16_t a = test_vec[i].a;
    simde_float16_t r = simde_vrndih_f16(a);

    simde_assert_equal_f16(r, test_vec[i].r, 1);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16_t a = simde_test_codegen_random_f16(-100.0f, 100.0f);
    simde_float16_t r = simde_vrndih_f16(a);

    simde_test_codegen_write_f16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_f16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vrndi_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16 a[4];
    simde_float16 r[4];
  } test_vec[] = {
    { {  SIMDE_FLOAT16_VALUE(  -0.772),  SIMDE_FLOAT16_VALUE(  -2.967),  SIMDE_FLOAT16_VALUE( -14.520),  SIMDE_FLOAT16_VALUE(  -7.674) },
      {  SIMDE_FLOAT16_VALUE(  -1.000),  SIMDE_FLOAT16_VALUE(  -3.000),  SIMDE_FLOAT16_VALUE( -15.000),  SIMDE_FLOAT16_VALUE(  -8.000) } },
    { {  SIMDE_FLOAT16_VALUE(  -5.485),  SIMDE_FLOAT16_VALUE(   1.193),  SIMDE_FLOAT16_VALUE(  -7.297),  SIMDE_FLOAT16_VALUE(  -4.643) },
      {  SIMDE_FLOAT16_VALUE(  -5.000),  SIMDE_FLOAT16_VALUE(   1.000),  SIMDE_FLOAT16_VALUE(  -7.000),  SIMDE_FLOAT16_VALUE(  -5.000) } },
    { {  SIMDE_FLOAT16_VALUE(   4.768),  SIMDE_FLOAT16_VALUE(  14.009),  SIMDE_FLOAT16_VALUE(   1.689),  SIMDE_FLOAT16_VALUE(  -3.233) },
      {  SIMDE_FLOAT16_VALUE(   5.000),  SIMDE_FLOAT16_VALUE(  14.000),  SIMDE_FLOAT16_VALUE(   2.000),  SIMDE_FLOAT16_VALUE(  -3.000) } },
    { {  SIMDE_FLOAT16_VALUE(   8.019),  SIMDE_FLOAT16_VALUE(  11.641),  SIMDE_FLOAT16_VALUE(  10.139),  SIMDE_FLOAT16_VALUE( -11.385) },
      {  SIMDE_FLOAT16_VALUE(   8.000),  SIMDE_FLOAT16_VALUE(  12.000),  SIMDE_FLOAT16_VALUE(  10.000),  SIMDE_FLOAT16_VALUE( -11.000) } },
    { {  SIMDE_FLOAT16_VALUE(  12.787),  SIMDE_FLOAT16_VALUE(  12.399),  SIMDE_FLOAT16_VALUE(  13.944),  SIMDE_FLOAT16_VALUE(  -0.689) },
      {  SIMDE_FLOAT16_VALUE(  13.000),  SIMDE_FLOAT16_VALUE(  12.000),  SIMDE_FLOAT16_VALUE(  14.000),  SIMDE_FLOAT16_VALUE(  -1.000) } },
    { {  SIMDE_FLOAT16_VALUE(  14.477),  SIMDE_FLOAT16_VALUE(  -1.853),  SIMDE_FLOAT16_VALUE(  10.022),  SIMDE_FLOAT16_VALUE(   3.184) },
      {  SIMDE_FLOAT16_VALUE(  14.000),  SIMDE_FLOAT16_VALUE(  -2.000),  SIMDE_FLOAT16_VALUE(  10.000),  SIMDE_FLOAT16_VALUE(   3.000) } },
    { {  SIMDE_FLOAT16_VALUE( -12.263),  SIMDE_FLOAT16_VALUE(  -7.845),  SIMDE_FLOAT16_VALUE(  -5.720),  SIMDE_FLOAT16_VALUE(   7.138) },
      {  SIMDE_FLOAT16_VALUE( -12.000),  SIMDE_FLOAT16_VALUE(  -8.000),  SIMDE_FLOAT16_VALUE(  -6.000),  SIMDE_FLOAT16_VALUE(   7.000) } },
    { {  SIMDE_FLOAT16_VALUE(   4.031),  SIMDE_FLOAT16_VALUE( -14.863),  SIMDE_FLOAT16_VALUE(  -8.408),  SIMDE_FLOAT16_VALUE(  13.835) },
      {  SIMDE_FLOAT16_VALUE(   4.000),  SIMDE_FLOAT16_VALUE( -15.000),  SIMDE_FLOAT16_VALUE(  -8.000),  SIMDE_FLOAT16_VALUE(  14.000) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x4_t a = simde_vld1_f16(test_vec[i].a);
    simde_float16x4_t r = simde_vrndi_f16(a);

    simde_test_arm_neon_assert_equal_f16x4(r, simde_vld1_f16(test_vec[i].r), 1);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16x4_t a = simde_test_arm_neon_random_f16x4(-100.0f, 100.0f);
    simde_float16x4_t r = simde_vrndi_f16(a);

    simde_test_arm_neon_write_f16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vrndi_f32 (SIMDE_MUNIT_TEST_ARGS) {
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
      { SIMDE_FLOAT32_C(    -2.00), SIMDE_FLOAT32_C(     2.00) } },
    { { SIMDE_FLOAT32_C(    -2.50), SIMDE_FLOAT32_C(     2.50) },
      { SIMDE_FLOAT32_C(    -2.00), SIMDE_FLOAT32_C(     2.00) } },

    { { SIMDE_FLOAT32_C(  -787.65), SIMDE_FLOAT32_C(  -795.95) },
      { SIMDE_FLOAT32_C(  -788.00), SIMDE_FLOAT32_C(  -796.00) } },
    { { SIMDE_FLOAT32_C(   899.31), SIMDE_FLOAT32_C(   -93.42) },
      { SIMDE_FLOAT32_C(   899.00), SIMDE_FLOAT32_C(   -93.00) } },
    { { SIMDE_FLOAT32_C(  -436.50), SIMDE_FLOAT32_C(  -165.94) },
      { SIMDE_FLOAT32_C(  -436.00), SIMDE_FLOAT32_C(  -166.00) } },
    { { SIMDE_FLOAT32_C(  -516.13), SIMDE_FLOAT32_C(  -288.52) },
      { SIMDE_FLOAT32_C(  -516.00), SIMDE_FLOAT32_C(  -289.00) } },
    { { SIMDE_FLOAT32_C(  -568.31), SIMDE_FLOAT32_C(  -937.97) },
      { SIMDE_FLOAT32_C(  -568.00), SIMDE_FLOAT32_C(  -938.00) } },
    { { SIMDE_FLOAT32_C(   827.64), SIMDE_FLOAT32_C(   984.63) },
      { SIMDE_FLOAT32_C(   828.00), SIMDE_FLOAT32_C(   985.00) } },
    { { SIMDE_FLOAT32_C(   261.25), SIMDE_FLOAT32_C(   -11.30) },
      { SIMDE_FLOAT32_C(   261.00), SIMDE_FLOAT32_C(   -11.00) } },
    { { SIMDE_FLOAT32_C(    97.38), SIMDE_FLOAT32_C(  -824.40) },
      { SIMDE_FLOAT32_C(    97.00), SIMDE_FLOAT32_C(  -824.00) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t a = simde_vld1_f32(test_vec[i].a);
    simde_float32x2_t r = simde_vrndi_f32(a);

    simde_test_arm_neon_assert_equal_f32x2(r, simde_vld1_f32(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x2_t a = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f);
    simde_float32x2_t r = simde_vrndi_f32(a);

    simde_test_arm_neon_write_f32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vrndi_f64 (SIMDE_MUNIT_TEST_ARGS) {
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
      { SIMDE_FLOAT64_C(     2.00) } },
    { { SIMDE_FLOAT64_C(    -2.50) },
      { SIMDE_FLOAT64_C(    -2.00) } },
    { { SIMDE_FLOAT64_C(     2.50) },
      { SIMDE_FLOAT64_C(     2.00) } },

    { { SIMDE_FLOAT64_C(  -405.63) },
      { SIMDE_FLOAT64_C(  -406.00) } },
    { { SIMDE_FLOAT64_C(   554.36) },
      { SIMDE_FLOAT64_C(   554.00) } },
    { { SIMDE_FLOAT64_C(  -286.09) },
      { SIMDE_FLOAT64_C(  -286.00) } },
    { { SIMDE_FLOAT64_C(  -583.84) },
      { SIMDE_FLOAT64_C(  -584.00) } },
    { { SIMDE_FLOAT64_C(  -389.59) },
      { SIMDE_FLOAT64_C(  -390.00) } },
    { { SIMDE_FLOAT64_C(  -683.98) },
      { SIMDE_FLOAT64_C(  -684.00) } },
    { { SIMDE_FLOAT64_C(   628.93) },
      { SIMDE_FLOAT64_C(   629.00) } },
    { { SIMDE_FLOAT64_C(  -112.86) },
      { SIMDE_FLOAT64_C(  -113.00) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x1_t a = simde_vld1_f64(test_vec[i].a);
    simde_float64x1_t r = simde_vrndi_f64(a);

    simde_test_arm_neon_assert_equal_f64x1(r, simde_vld1_f64(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x1_t a = simde_test_arm_neon_random_f64x1(-1000.0, 1000.0);
    simde_float64x1_t r = simde_vrndi_f64(a);

    simde_test_arm_neon_write_f64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vrndiq_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16 a[8];
    simde_float16 r[8];
  } test_vec[] = {
    { {  SIMDE_FLOAT16_VALUE( -13.333),  SIMDE_FLOAT16_VALUE(  -6.534),  SIMDE_FLOAT16_VALUE(   1.461),  SIMDE_FLOAT16_VALUE(   8.065),
         SIMDE_FLOAT16_VALUE(  -7.773),  SIMDE_FLOAT16_VALUE(   3.880),  SIMDE_FLOAT16_VALUE(   3.879),  SIMDE_FLOAT16_VALUE(   1.629) },
      {  SIMDE_FLOAT16_VALUE( -13.000),  SIMDE_FLOAT16_VALUE(  -7.000),  SIMDE_FLOAT16_VALUE(   1.000),  SIMDE_FLOAT16_VALUE(   8.000),
         SIMDE_FLOAT16_VALUE(  -8.000),  SIMDE_FLOAT16_VALUE(   4.000),  SIMDE_FLOAT16_VALUE(   4.000),  SIMDE_FLOAT16_VALUE(   2.000) } },
    { {  SIMDE_FLOAT16_VALUE(  13.649),  SIMDE_FLOAT16_VALUE(  -9.254),  SIMDE_FLOAT16_VALUE(   7.250),  SIMDE_FLOAT16_VALUE(  -5.024),
         SIMDE_FLOAT16_VALUE(  -0.041),  SIMDE_FLOAT16_VALUE(  10.824),  SIMDE_FLOAT16_VALUE(  -6.603),  SIMDE_FLOAT16_VALUE(  -6.021) },
      {  SIMDE_FLOAT16_VALUE(  14.000),  SIMDE_FLOAT16_VALUE(  -9.000),  SIMDE_FLOAT16_VALUE(   7.000),  SIMDE_FLOAT16_VALUE(  -5.000),
         SIMDE_FLOAT16_VALUE(  -0.000),  SIMDE_FLOAT16_VALUE(  11.000),  SIMDE_FLOAT16_VALUE(  -7.000),  SIMDE_FLOAT16_VALUE(  -6.000) } },
    { {  SIMDE_FLOAT16_VALUE(   2.544),  SIMDE_FLOAT16_VALUE(  -0.663),  SIMDE_FLOAT16_VALUE( -14.560),  SIMDE_FLOAT16_VALUE(   4.351),
         SIMDE_FLOAT16_VALUE(   4.475),  SIMDE_FLOAT16_VALUE(   4.862),  SIMDE_FLOAT16_VALUE(  11.744),  SIMDE_FLOAT16_VALUE( -12.948) },
      {  SIMDE_FLOAT16_VALUE(   3.000),  SIMDE_FLOAT16_VALUE(  -1.000),  SIMDE_FLOAT16_VALUE( -15.000),  SIMDE_FLOAT16_VALUE(   4.000),
         SIMDE_FLOAT16_VALUE(   4.000),  SIMDE_FLOAT16_VALUE(   5.000),  SIMDE_FLOAT16_VALUE(  12.000),  SIMDE_FLOAT16_VALUE( -13.000) } },
    { {  SIMDE_FLOAT16_VALUE(  -8.052),  SIMDE_FLOAT16_VALUE(   9.711),  SIMDE_FLOAT16_VALUE(  10.144),  SIMDE_FLOAT16_VALUE(   0.454),
         SIMDE_FLOAT16_VALUE(  -9.812),  SIMDE_FLOAT16_VALUE(  -3.705),  SIMDE_FLOAT16_VALUE(  11.255),  SIMDE_FLOAT16_VALUE(   6.389) },
      {  SIMDE_FLOAT16_VALUE(  -8.000),  SIMDE_FLOAT16_VALUE(  10.000),  SIMDE_FLOAT16_VALUE(  10.000),  SIMDE_FLOAT16_VALUE(   0.000),
         SIMDE_FLOAT16_VALUE( -10.000),  SIMDE_FLOAT16_VALUE(  -4.000),  SIMDE_FLOAT16_VALUE(  11.000),  SIMDE_FLOAT16_VALUE(   6.000) } },
    { {  SIMDE_FLOAT16_VALUE( -11.469),  SIMDE_FLOAT16_VALUE(   8.987),  SIMDE_FLOAT16_VALUE(  14.997),  SIMDE_FLOAT16_VALUE(  -6.383),
         SIMDE_FLOAT16_VALUE(  -8.802),  SIMDE_FLOAT16_VALUE(  10.679),  SIMDE_FLOAT16_VALUE(  -0.238),  SIMDE_FLOAT16_VALUE(   0.873) },
      {  SIMDE_FLOAT16_VALUE( -11.000),  SIMDE_FLOAT16_VALUE(   9.000),  SIMDE_FLOAT16_VALUE(  15.000),  SIMDE_FLOAT16_VALUE(  -6.000),
         SIMDE_FLOAT16_VALUE(  -9.000),  SIMDE_FLOAT16_VALUE(  11.000),  SIMDE_FLOAT16_VALUE(  -0.000),  SIMDE_FLOAT16_VALUE(   1.000) } },
    { {  SIMDE_FLOAT16_VALUE( -12.111),  SIMDE_FLOAT16_VALUE(   3.012),  SIMDE_FLOAT16_VALUE(   6.714),  SIMDE_FLOAT16_VALUE( -14.491),
         SIMDE_FLOAT16_VALUE(   5.915),  SIMDE_FLOAT16_VALUE(   7.081),  SIMDE_FLOAT16_VALUE(  -6.477),  SIMDE_FLOAT16_VALUE( -11.878) },
      {  SIMDE_FLOAT16_VALUE( -12.000),  SIMDE_FLOAT16_VALUE(   3.000),  SIMDE_FLOAT16_VALUE(   7.000),  SIMDE_FLOAT16_VALUE( -14.000),
         SIMDE_FLOAT16_VALUE(   6.000),  SIMDE_FLOAT16_VALUE(   7.000),  SIMDE_FLOAT16_VALUE(  -6.000),  SIMDE_FLOAT16_VALUE( -12.000) } },
    { {  SIMDE_FLOAT16_VALUE(  -2.943),  SIMDE_FLOAT16_VALUE( -12.268),  SIMDE_FLOAT16_VALUE(  -0.653),  SIMDE_FLOAT16_VALUE( -12.643),
         SIMDE_FLOAT16_VALUE( -10.790),  SIMDE_FLOAT16_VALUE(  -0.174),  SIMDE_FLOAT16_VALUE(   9.143),  SIMDE_FLOAT16_VALUE(  10.740) },
      {  SIMDE_FLOAT16_VALUE(  -3.000),  SIMDE_FLOAT16_VALUE( -12.000),  SIMDE_FLOAT16_VALUE(  -1.000),  SIMDE_FLOAT16_VALUE( -13.000),
         SIMDE_FLOAT16_VALUE( -11.000),  SIMDE_FLOAT16_VALUE(  -0.000),  SIMDE_FLOAT16_VALUE(   9.000),  SIMDE_FLOAT16_VALUE(  11.000) } },
    { {  SIMDE_FLOAT16_VALUE(   9.915),  SIMDE_FLOAT16_VALUE(  -6.208),  SIMDE_FLOAT16_VALUE( -14.325),  SIMDE_FLOAT16_VALUE(  -6.559),
         SIMDE_FLOAT16_VALUE(   4.518),  SIMDE_FLOAT16_VALUE(   5.550),  SIMDE_FLOAT16_VALUE( -11.703),  SIMDE_FLOAT16_VALUE(  13.945) },
      {  SIMDE_FLOAT16_VALUE(  10.000),  SIMDE_FLOAT16_VALUE(  -6.000),  SIMDE_FLOAT16_VALUE( -14.000),  SIMDE_FLOAT16_VALUE(  -7.000),
         SIMDE_FLOAT16_VALUE(   5.000),  SIMDE_FLOAT16_VALUE(   6.000),  SIMDE_FLOAT16_VALUE( -12.000),  SIMDE_FLOAT16_VALUE(  14.000) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x8_t a = simde_vld1q_f16(test_vec[i].a);
    simde_float16x8_t r = simde_vrndiq_f16(a);
    simde_test_arm_neon_assert_equal_f16x8(r, simde_vld1q_f16(test_vec[i].r), 1);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16x8_t a = simde_test_arm_neon_random_f16x8(-100.0f, 100.0f);
    simde_float16x8_t r = simde_vrndiq_f16(a);

    simde_test_arm_neon_write_f16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vrndiq_f32 (SIMDE_MUNIT_TEST_ARGS) {
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
      { SIMDE_FLOAT32_C(    -2.00), SIMDE_FLOAT32_C(     2.00), SIMDE_FLOAT32_C(    -2.00), SIMDE_FLOAT32_C(     2.00) } },

    { { SIMDE_FLOAT32_C(  -938.67), SIMDE_FLOAT32_C(  -583.30), SIMDE_FLOAT32_C(  -219.07), SIMDE_FLOAT32_C(   510.59) },
      { SIMDE_FLOAT32_C(  -939.00), SIMDE_FLOAT32_C(  -583.00), SIMDE_FLOAT32_C(  -219.00), SIMDE_FLOAT32_C(   511.00) } },
    { { SIMDE_FLOAT32_C(  -715.91), SIMDE_FLOAT32_C(  -372.75), SIMDE_FLOAT32_C(  -712.38), SIMDE_FLOAT32_C(  -503.56) },
      { SIMDE_FLOAT32_C(  -716.00), SIMDE_FLOAT32_C(  -373.00), SIMDE_FLOAT32_C(  -712.00), SIMDE_FLOAT32_C(  -504.00) } },
    { { SIMDE_FLOAT32_C(  -168.71), SIMDE_FLOAT32_C(  -813.07), SIMDE_FLOAT32_C(   403.02), SIMDE_FLOAT32_C(   394.80) },
      { SIMDE_FLOAT32_C(  -169.00), SIMDE_FLOAT32_C(  -813.00), SIMDE_FLOAT32_C(   403.00), SIMDE_FLOAT32_C(   395.00) } },
    { { SIMDE_FLOAT32_C(    21.00), SIMDE_FLOAT32_C(   886.89), SIMDE_FLOAT32_C(  -893.72), SIMDE_FLOAT32_C(   452.69) },
      { SIMDE_FLOAT32_C(    21.00), SIMDE_FLOAT32_C(   887.00), SIMDE_FLOAT32_C(  -894.00), SIMDE_FLOAT32_C(   453.00) } },
    { { SIMDE_FLOAT32_C(   948.91), SIMDE_FLOAT32_C(   933.92), SIMDE_FLOAT32_C(   437.32), SIMDE_FLOAT32_C(   210.16) },
      { SIMDE_FLOAT32_C(   949.00), SIMDE_FLOAT32_C(   934.00), SIMDE_FLOAT32_C(   437.00), SIMDE_FLOAT32_C(   210.00) } },
    { { SIMDE_FLOAT32_C(   -77.38), SIMDE_FLOAT32_C(  -465.30), SIMDE_FLOAT32_C(   385.77), SIMDE_FLOAT32_C(   516.99) },
      { SIMDE_FLOAT32_C(   -77.00), SIMDE_FLOAT32_C(  -465.00), SIMDE_FLOAT32_C(   386.00), SIMDE_FLOAT32_C(   517.00) } },
    { { SIMDE_FLOAT32_C(  -910.94), SIMDE_FLOAT32_C(  -900.33), SIMDE_FLOAT32_C(   933.15), SIMDE_FLOAT32_C(  -300.52) },
      { SIMDE_FLOAT32_C(  -911.00), SIMDE_FLOAT32_C(  -900.00), SIMDE_FLOAT32_C(   933.00), SIMDE_FLOAT32_C(  -301.00) } },
    { { SIMDE_FLOAT32_C(  -584.31), SIMDE_FLOAT32_C(   562.08), SIMDE_FLOAT32_C(   586.62), SIMDE_FLOAT32_C(  -522.98) },
      { SIMDE_FLOAT32_C(  -584.00), SIMDE_FLOAT32_C(   562.00), SIMDE_FLOAT32_C(   587.00), SIMDE_FLOAT32_C(  -523.00) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_float32x4_t r = simde_vrndiq_f32(a);
    simde_test_arm_neon_assert_equal_f32x4(r, simde_vld1q_f32(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x4_t a = simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f);
    simde_float32x4_t r = simde_vrndiq_f32(a);

    simde_test_arm_neon_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vrndiq_f64 (SIMDE_MUNIT_TEST_ARGS) {
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
      { SIMDE_FLOAT64_C(    -2.00), SIMDE_FLOAT64_C(     2.00) } },
    { { SIMDE_FLOAT64_C(    -2.50), SIMDE_FLOAT64_C(     2.50) },
      { SIMDE_FLOAT64_C(    -2.00), SIMDE_FLOAT64_C(     2.00) } },

    { { SIMDE_FLOAT64_C(   978.78), SIMDE_FLOAT64_C(  -632.45) },
      { SIMDE_FLOAT64_C(   979.00), SIMDE_FLOAT64_C(  -632.00) } },
    { { SIMDE_FLOAT64_C(   987.61), SIMDE_FLOAT64_C(  -737.13) },
      { SIMDE_FLOAT64_C(   988.00), SIMDE_FLOAT64_C(  -737.00) } },
    { { SIMDE_FLOAT64_C(    -5.20), SIMDE_FLOAT64_C(  -724.77) },
      { SIMDE_FLOAT64_C(    -5.00), SIMDE_FLOAT64_C(  -725.00) } },
    { { SIMDE_FLOAT64_C(  -240.69), SIMDE_FLOAT64_C(   826.09) },
      { SIMDE_FLOAT64_C(  -241.00), SIMDE_FLOAT64_C(   826.00) } },
    { { SIMDE_FLOAT64_C(  -537.84), SIMDE_FLOAT64_C(  -837.67) },
      { SIMDE_FLOAT64_C(  -538.00), SIMDE_FLOAT64_C(  -838.00) } },
    { { SIMDE_FLOAT64_C(   220.89), SIMDE_FLOAT64_C(   483.16) },
      { SIMDE_FLOAT64_C(   221.00), SIMDE_FLOAT64_C(   483.00) } },
    { { SIMDE_FLOAT64_C(  -950.78), SIMDE_FLOAT64_C(   327.17) },
      { SIMDE_FLOAT64_C(  -951.00), SIMDE_FLOAT64_C(   327.00) } },
    { { SIMDE_FLOAT64_C(   -64.15), SIMDE_FLOAT64_C(   998.14) },
      { SIMDE_FLOAT64_C(   -64.00), SIMDE_FLOAT64_C(   998.00) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2_t a = simde_vld1q_f64(test_vec[i].a);
    simde_float64x2_t r = simde_vrndiq_f64(a);

    simde_test_arm_neon_assert_equal_f64x2(r, simde_vld1q_f64(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x2_t a = simde_test_arm_neon_random_f64x2(-1000.0, 1000.0);
    simde_float64x2_t r = simde_vrndiq_f64(a);

    simde_test_arm_neon_write_f64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vrndih_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vrndi_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vrndi_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vrndi_f64)

SIMDE_TEST_FUNC_LIST_ENTRY(vrndiq_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vrndiq_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vrndiq_f64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
