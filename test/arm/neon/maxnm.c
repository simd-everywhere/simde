#define SIMDE_TEST_ARM_NEON_INSN maxnm

#include "test-neon.h"
#include "../../../simde/arm/neon/maxnm.h"

static int
test_simde_vmaxnm_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a[2];
    simde_float32 b[2];
    simde_float32 r[2];
  } test_vec[] = {
    #if !defined(SIMDE_FAST_NANS)
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   656.90) },
      { SIMDE_FLOAT32_C(   427.79),            SIMDE_MATH_NANF },
      { SIMDE_FLOAT32_C(   427.79), SIMDE_FLOAT32_C(   656.90) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   116.96) },
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -999.94) },
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   116.96) } },
    #endif
    { { SIMDE_FLOAT32_C(  -619.20), SIMDE_FLOAT32_C(  -413.47) },
      { SIMDE_FLOAT32_C(   871.28), SIMDE_FLOAT32_C(  -660.33) },
      { SIMDE_FLOAT32_C(   871.28), SIMDE_FLOAT32_C(  -413.47) } },
    { { SIMDE_FLOAT32_C(   422.55), SIMDE_FLOAT32_C(   160.51) },
      { SIMDE_FLOAT32_C(   148.88), SIMDE_FLOAT32_C(   905.13) },
      { SIMDE_FLOAT32_C(   422.55), SIMDE_FLOAT32_C(   905.13) } },
    { { SIMDE_FLOAT32_C(  -605.53), SIMDE_FLOAT32_C(  -971.47) },
      { SIMDE_FLOAT32_C(   182.75), SIMDE_FLOAT32_C(  -737.07) },
      { SIMDE_FLOAT32_C(   182.75), SIMDE_FLOAT32_C(  -737.07) } },
    { { SIMDE_FLOAT32_C(  -182.06), SIMDE_FLOAT32_C(  -678.54) },
      { SIMDE_FLOAT32_C(   165.68), SIMDE_FLOAT32_C(   413.12) },
      { SIMDE_FLOAT32_C(   165.68), SIMDE_FLOAT32_C(   413.12) } },
    { { SIMDE_FLOAT32_C(    20.28), SIMDE_FLOAT32_C(  -770.49) },
      { SIMDE_FLOAT32_C(   647.00), SIMDE_FLOAT32_C(  -632.40) },
      { SIMDE_FLOAT32_C(   647.00), SIMDE_FLOAT32_C(  -632.40) } },
    { { SIMDE_FLOAT32_C(   949.17), SIMDE_FLOAT32_C(   616.00) },
      { SIMDE_FLOAT32_C(  -967.88), SIMDE_FLOAT32_C(  -301.85) },
      { SIMDE_FLOAT32_C(   949.17), SIMDE_FLOAT32_C(   616.00) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t a = simde_vld1_f32(test_vec[i].a);
    simde_float32x2_t b = simde_vld1_f32(test_vec[i].b);
    simde_float32x2_t r = simde_vmaxnm_f32(a, b);

    simde_test_arm_neon_assert_equal_f32x2(r, simde_vld1_f32(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  simde_float32_t values[8 * 2 * sizeof(simde_float32x2_t)];
  simde_test_arm_neon_random_f32x2_full(8, 2, values, -1000.0f, 1000.0f, SIMDE_TEST_VEC_FLOAT_NAN);

  for (size_t i = 0 ; i < 8 ; i++) {
    simde_float32x2_t a = simde_test_arm_neon_random_extract_f32x2(i, 2, 0, values);
    simde_float32x2_t b = simde_test_arm_neon_random_extract_f32x2(i, 2, 1, values);
    simde_float32x2_t r = simde_vmaxnm_f32(a, b);

    simde_test_arm_neon_write_f32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmaxnm_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 a[1];
    simde_float64 b[1];
    simde_float64 r[1];
  } test_vec[] = {
    #if !defined(SIMDE_FAST_NANS)
    { {             SIMDE_MATH_NAN },
      { SIMDE_FLOAT64_C(   169.64) },
      { SIMDE_FLOAT64_C(   169.64) } },
    { { SIMDE_FLOAT64_C(  -986.47) },
      {             SIMDE_MATH_NAN },
      { SIMDE_FLOAT64_C(  -986.47) } },
    { {             SIMDE_MATH_NAN },
      {             SIMDE_MATH_NAN },
      {             SIMDE_MATH_NAN } },
    #endif
    { { SIMDE_FLOAT64_C(   827.71) },
      { SIMDE_FLOAT64_C(   191.90) },
      { SIMDE_FLOAT64_C(   827.71) } },
    { { SIMDE_FLOAT64_C(  -275.70) },
      { SIMDE_FLOAT64_C(   295.23) },
      { SIMDE_FLOAT64_C(   295.23) } },
    { { SIMDE_FLOAT64_C(   188.72) },
      { SIMDE_FLOAT64_C(   429.15) },
      { SIMDE_FLOAT64_C(   429.15) } },
    { { SIMDE_FLOAT64_C(  -147.66) },
      { SIMDE_FLOAT64_C(   487.54) },
      { SIMDE_FLOAT64_C(   487.54) } },
    { { SIMDE_FLOAT64_C(  -528.84) },
      { SIMDE_FLOAT64_C(  -797.49) },
      { SIMDE_FLOAT64_C(  -528.84) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x1_t a = simde_vld1_f64(test_vec[i].a);
    simde_float64x1_t b = simde_vld1_f64(test_vec[i].b);
    simde_float64x1_t r = simde_vmaxnm_f64(a, b);

    simde_test_arm_neon_assert_equal_f64x1(r, simde_vld1_f64(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  simde_float64_t values[8 * 2 * sizeof(simde_float64x1_t)];
  simde_test_arm_neon_random_f64x1_full(8, 2, values, -1000.0, 1000.0, SIMDE_TEST_VEC_FLOAT_NAN);

  for (size_t i = 0 ; i < 8 ; i++) {
    simde_float64x1_t a = simde_test_arm_neon_random_extract_f64x1(i, 2, 0, values);
    simde_float64x1_t b = simde_test_arm_neon_random_extract_f64x1(i, 2, 1, values);
    simde_float64x1_t r = simde_vmaxnm_f64(a, b);

    simde_test_arm_neon_write_f64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x1(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmaxnmq_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a[4];
    simde_float32 b[4];
    simde_float32 r[4];
  } test_vec[] = {
    #if !defined(SIMDE_FAST_NANS)
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -830.15),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   116.42) },
      { SIMDE_FLOAT32_C(  -786.61),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   704.38) },
      { SIMDE_FLOAT32_C(  -786.61), SIMDE_FLOAT32_C(  -830.15),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   704.38) } },
    #endif
    { { SIMDE_FLOAT32_C(    42.56), SIMDE_FLOAT32_C(  -762.07), SIMDE_FLOAT32_C(   243.80), SIMDE_FLOAT32_C(   127.20) },
      { SIMDE_FLOAT32_C(  -554.99), SIMDE_FLOAT32_C(   818.92), SIMDE_FLOAT32_C(  -693.45), SIMDE_FLOAT32_C(   417.65) },
      { SIMDE_FLOAT32_C(    42.56), SIMDE_FLOAT32_C(   818.92), SIMDE_FLOAT32_C(   243.80), SIMDE_FLOAT32_C(   417.65) } },
    { { SIMDE_FLOAT32_C(   -84.44), SIMDE_FLOAT32_C(   320.00), SIMDE_FLOAT32_C(   451.21), SIMDE_FLOAT32_C(    71.41) },
      { SIMDE_FLOAT32_C(  -104.53), SIMDE_FLOAT32_C(   615.74), SIMDE_FLOAT32_C(  -465.38), SIMDE_FLOAT32_C(    92.29) },
      { SIMDE_FLOAT32_C(   -84.44), SIMDE_FLOAT32_C(   615.74), SIMDE_FLOAT32_C(   451.21), SIMDE_FLOAT32_C(    92.29) } },
    { { SIMDE_FLOAT32_C(  -599.78), SIMDE_FLOAT32_C(   592.36), SIMDE_FLOAT32_C(  -378.07), SIMDE_FLOAT32_C(  -109.06) },
      { SIMDE_FLOAT32_C(   386.28), SIMDE_FLOAT32_C(  -742.91), SIMDE_FLOAT32_C(   270.77), SIMDE_FLOAT32_C(   106.07) },
      { SIMDE_FLOAT32_C(   386.28), SIMDE_FLOAT32_C(   592.36), SIMDE_FLOAT32_C(   270.77), SIMDE_FLOAT32_C(   106.07) } },
    { { SIMDE_FLOAT32_C(  -573.06), SIMDE_FLOAT32_C(   931.15), SIMDE_FLOAT32_C(  -777.52), SIMDE_FLOAT32_C(  -359.67) },
      { SIMDE_FLOAT32_C(  -618.04), SIMDE_FLOAT32_C(  -590.04), SIMDE_FLOAT32_C(  -655.29), SIMDE_FLOAT32_C(   424.52) },
      { SIMDE_FLOAT32_C(  -573.06), SIMDE_FLOAT32_C(   931.15), SIMDE_FLOAT32_C(  -655.29), SIMDE_FLOAT32_C(   424.52) } },
    { { SIMDE_FLOAT32_C(  -352.11), SIMDE_FLOAT32_C(   588.52), SIMDE_FLOAT32_C(  -448.29), SIMDE_FLOAT32_C(    92.89) },
      { SIMDE_FLOAT32_C(   407.44), SIMDE_FLOAT32_C(  -141.74), SIMDE_FLOAT32_C(  -489.46), SIMDE_FLOAT32_C(  -677.00) },
      { SIMDE_FLOAT32_C(   407.44), SIMDE_FLOAT32_C(   588.52), SIMDE_FLOAT32_C(  -448.29), SIMDE_FLOAT32_C(    92.89) } },
    { { SIMDE_FLOAT32_C(  -821.73), SIMDE_FLOAT32_C(   961.75), SIMDE_FLOAT32_C(   394.41), SIMDE_FLOAT32_C(    73.73) },
      { SIMDE_FLOAT32_C(   577.49), SIMDE_FLOAT32_C(   929.03), SIMDE_FLOAT32_C(  -833.98), SIMDE_FLOAT32_C(   977.71) },
      { SIMDE_FLOAT32_C(   577.49), SIMDE_FLOAT32_C(   961.75), SIMDE_FLOAT32_C(   394.41), SIMDE_FLOAT32_C(   977.71) } },
    { { SIMDE_FLOAT32_C(   521.39), SIMDE_FLOAT32_C(  -212.06), SIMDE_FLOAT32_C(  -131.35), SIMDE_FLOAT32_C(   -92.34) },
      { SIMDE_FLOAT32_C(    45.03), SIMDE_FLOAT32_C(  -860.58), SIMDE_FLOAT32_C(  -986.27), SIMDE_FLOAT32_C(   471.98) },
      { SIMDE_FLOAT32_C(   521.39), SIMDE_FLOAT32_C(  -212.06), SIMDE_FLOAT32_C(  -131.35), SIMDE_FLOAT32_C(   471.98) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_float32x4_t b = simde_vld1q_f32(test_vec[i].b);
    simde_float32x4_t r = simde_vmaxnmq_f32(a, b);

    simde_test_arm_neon_assert_equal_f32x4(r, simde_vld1q_f32(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  simde_float32_t values[8 * 2 * sizeof(simde_float32x4_t)];
  simde_test_arm_neon_random_f32x4_full(8, 2, values, -1000.0f, 1000.0f, SIMDE_TEST_VEC_FLOAT_NAN);

  for (size_t i = 0 ; i < 8 ; i++) {
    simde_float32x4_t a = simde_test_arm_neon_random_extract_f32x4(i, 2, 0, values);
    simde_float32x4_t b = simde_test_arm_neon_random_extract_f32x4(i, 2, 1, values);
    simde_float32x4_t r = simde_vmaxnmq_f32(a, b);

    simde_test_arm_neon_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmaxnmq_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 a[2];
    simde_float64 b[2];
    simde_float64 r[2];
  } test_vec[] = {
    #if !defined(SIMDE_FAST_NANS)
        { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -182.58) },
      { SIMDE_FLOAT64_C(   743.82),             SIMDE_MATH_NAN },
      { SIMDE_FLOAT64_C(   743.82), SIMDE_FLOAT64_C(  -182.58) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   493.92) },
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   934.94) },
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   934.94) } },
    #endif
    { { SIMDE_FLOAT64_C(  -559.75), SIMDE_FLOAT64_C(  -168.42) },
      { SIMDE_FLOAT64_C(   193.83), SIMDE_FLOAT64_C(  -311.43) },
      { SIMDE_FLOAT64_C(   193.83), SIMDE_FLOAT64_C(  -168.42) } },
    { { SIMDE_FLOAT64_C(   685.60), SIMDE_FLOAT64_C(   642.39) },
      { SIMDE_FLOAT64_C(  -129.77), SIMDE_FLOAT64_C(  -575.43) },
      { SIMDE_FLOAT64_C(   685.60), SIMDE_FLOAT64_C(   642.39) } },
    { { SIMDE_FLOAT64_C(   166.90), SIMDE_FLOAT64_C(  -869.88) },
      { SIMDE_FLOAT64_C(    87.77), SIMDE_FLOAT64_C(  -554.15) },
      { SIMDE_FLOAT64_C(   166.90), SIMDE_FLOAT64_C(  -554.15) } },
    { { SIMDE_FLOAT64_C(  -667.35), SIMDE_FLOAT64_C(  -294.71) },
      { SIMDE_FLOAT64_C(   134.11), SIMDE_FLOAT64_C(   615.74) },
      { SIMDE_FLOAT64_C(   134.11), SIMDE_FLOAT64_C(   615.74) } },
    { { SIMDE_FLOAT64_C(   -85.63), SIMDE_FLOAT64_C(  -649.42) },
      { SIMDE_FLOAT64_C(  -536.78), SIMDE_FLOAT64_C(   843.96) },
      { SIMDE_FLOAT64_C(   -85.63), SIMDE_FLOAT64_C(   843.96) } },
    { { SIMDE_FLOAT64_C(   349.79), SIMDE_FLOAT64_C(   234.11) },
      { SIMDE_FLOAT64_C(  -713.81), SIMDE_FLOAT64_C(   557.65) },
      { SIMDE_FLOAT64_C(   349.79), SIMDE_FLOAT64_C(   557.65) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2_t a = simde_vld1q_f64(test_vec[i].a);
    simde_float64x2_t b = simde_vld1q_f64(test_vec[i].b);
    simde_float64x2_t r = simde_vmaxnmq_f64(a, b);

    simde_test_arm_neon_assert_equal_f64x2(r, simde_vld1q_f64(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  simde_float64_t values[8 * 2 * sizeof(simde_float64x2_t)];
  simde_test_arm_neon_random_f64x2_full(8, 2, values, -1000.0, 1000.0, SIMDE_TEST_VEC_FLOAT_NAN);

  for (size_t i = 0 ; i < 8 ; i++) {
    simde_float64x2_t a = simde_test_arm_neon_random_extract_f64x2(i, 2, 0, values);
    simde_float64x2_t b = simde_test_arm_neon_random_extract_f64x2(i, 2, 1, values);
    simde_float64x2_t r = simde_vmaxnmq_f64(a, b);

    simde_test_arm_neon_write_f64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vmaxnm_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vmaxnm_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vmaxnmq_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vmaxnmq_f64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
