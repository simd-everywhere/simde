#define SIMDE_TEST_ARM_NEON_INSN minnm

#include "test-neon.h"
#include "../../../simde/arm/neon/minnm.h"

static int
test_simde_vminnm_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a[2];
    simde_float32 b[2];
    simde_float32 r[2];
  } test_vec[] = {
    #if !defined(SIMDE_FAST_NANS)
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   944.82) },
      { SIMDE_FLOAT32_C(   575.31),            SIMDE_MATH_NANF },
      { SIMDE_FLOAT32_C(   575.31), SIMDE_FLOAT32_C(   944.82) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -343.95) },
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   317.39) },
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -343.95) } },
    #endif
    { { SIMDE_FLOAT32_C(  -696.17), SIMDE_FLOAT32_C(   907.59) },
      { SIMDE_FLOAT32_C(  -623.94), SIMDE_FLOAT32_C(   625.50) },
      { SIMDE_FLOAT32_C(  -696.17), SIMDE_FLOAT32_C(   625.50) } },
    { { SIMDE_FLOAT32_C(  -705.76), SIMDE_FLOAT32_C(  -732.20) },
      { SIMDE_FLOAT32_C(  -126.64), SIMDE_FLOAT32_C(  -660.16) },
      { SIMDE_FLOAT32_C(  -705.76), SIMDE_FLOAT32_C(  -732.20) } },
    { { SIMDE_FLOAT32_C(  -661.61), SIMDE_FLOAT32_C(  -734.04) },
      { SIMDE_FLOAT32_C(   847.38), SIMDE_FLOAT32_C(   816.85) },
      { SIMDE_FLOAT32_C(  -661.61), SIMDE_FLOAT32_C(  -734.04) } },
    { { SIMDE_FLOAT32_C(   945.94), SIMDE_FLOAT32_C(  -136.95) },
      { SIMDE_FLOAT32_C(    70.32), SIMDE_FLOAT32_C(   820.87) },
      { SIMDE_FLOAT32_C(    70.32), SIMDE_FLOAT32_C(  -136.95) } },
    { { SIMDE_FLOAT32_C(   441.43), SIMDE_FLOAT32_C(  -694.16) },
      { SIMDE_FLOAT32_C(   343.41), SIMDE_FLOAT32_C(    88.05) },
      { SIMDE_FLOAT32_C(   343.41), SIMDE_FLOAT32_C(  -694.16) } },
    { { SIMDE_FLOAT32_C(   175.22), SIMDE_FLOAT32_C(  -756.19) },
      { SIMDE_FLOAT32_C(  -558.30), SIMDE_FLOAT32_C(   795.61) },
      { SIMDE_FLOAT32_C(  -558.30), SIMDE_FLOAT32_C(  -756.19) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t a = simde_vld1_f32(test_vec[i].a);
    simde_float32x2_t b = simde_vld1_f32(test_vec[i].b);
    simde_float32x2_t r = simde_vminnm_f32(a, b);

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
    simde_float32x2_t r = simde_vminnm_f32(a, b);

    simde_test_arm_neon_write_f32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vminnm_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 a[1];
    simde_float64 b[1];
    simde_float64 r[1];
  } test_vec[] = {
    #if !defined(SIMDE_FAST_NANS)
    { {             SIMDE_MATH_NAN },
      { SIMDE_FLOAT64_C(   814.09) },
      { SIMDE_FLOAT64_C(   814.09) } },
    { { SIMDE_FLOAT64_C(   857.46) },
      {             SIMDE_MATH_NAN },
      { SIMDE_FLOAT64_C(   857.46) } },
    { {             SIMDE_MATH_NAN },
      {             SIMDE_MATH_NAN },
      {             SIMDE_MATH_NAN } },
    #endif
    { { SIMDE_FLOAT64_C(   611.47) },
      { SIMDE_FLOAT64_C(   938.24) },
      { SIMDE_FLOAT64_C(   611.47) } },
    { { SIMDE_FLOAT64_C(  -733.28) },
      { SIMDE_FLOAT64_C(  -430.87) },
      { SIMDE_FLOAT64_C(  -733.28) } },
    { { SIMDE_FLOAT64_C(   558.71) },
      { SIMDE_FLOAT64_C(   197.76) },
      { SIMDE_FLOAT64_C(   197.76) } },
    { { SIMDE_FLOAT64_C(   -73.48) },
      { SIMDE_FLOAT64_C(  -904.42) },
      { SIMDE_FLOAT64_C(  -904.42) } },
    { { SIMDE_FLOAT64_C(   443.92) },
      { SIMDE_FLOAT64_C(   926.58) },
      { SIMDE_FLOAT64_C(   443.92) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x1_t a = simde_vld1_f64(test_vec[i].a);
    simde_float64x1_t b = simde_vld1_f64(test_vec[i].b);
    simde_float64x1_t r = simde_vminnm_f64(a, b);

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
    simde_float64x1_t r = simde_vminnm_f64(a, b);

    simde_test_arm_neon_write_f64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x1(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vminnmq_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a[4];
    simde_float32 b[4];
    simde_float32 r[4];
  } test_vec[] = {
    #if !defined(SIMDE_FAST_NANS)
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   819.39),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   912.19) },
      { SIMDE_FLOAT32_C(  -631.16),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   587.97) },
      { SIMDE_FLOAT32_C(  -631.16), SIMDE_FLOAT32_C(   819.39),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   587.97) } },
    #endif
    { { SIMDE_FLOAT32_C(   979.32), SIMDE_FLOAT32_C(  -967.75), SIMDE_FLOAT32_C(  -462.78), SIMDE_FLOAT32_C(  -270.14) },
      { SIMDE_FLOAT32_C(  -821.32), SIMDE_FLOAT32_C(  -724.47), SIMDE_FLOAT32_C(  -442.09), SIMDE_FLOAT32_C(   -73.38) },
      { SIMDE_FLOAT32_C(  -821.32), SIMDE_FLOAT32_C(  -967.75), SIMDE_FLOAT32_C(  -462.78), SIMDE_FLOAT32_C(  -270.14) } },
    { { SIMDE_FLOAT32_C(  -910.38), SIMDE_FLOAT32_C(  -584.63), SIMDE_FLOAT32_C(   694.05), SIMDE_FLOAT32_C(  -314.00) },
      { SIMDE_FLOAT32_C(   781.88), SIMDE_FLOAT32_C(   305.53), SIMDE_FLOAT32_C(  -375.75), SIMDE_FLOAT32_C(  -951.40) },
      { SIMDE_FLOAT32_C(  -910.38), SIMDE_FLOAT32_C(  -584.63), SIMDE_FLOAT32_C(  -375.75), SIMDE_FLOAT32_C(  -951.40) } },
    { { SIMDE_FLOAT32_C(   874.66), SIMDE_FLOAT32_C(  -817.04), SIMDE_FLOAT32_C(   246.35), SIMDE_FLOAT32_C(  -198.82) },
      { SIMDE_FLOAT32_C(  -721.46), SIMDE_FLOAT32_C(  -309.72), SIMDE_FLOAT32_C(  -272.24), SIMDE_FLOAT32_C(  -582.08) },
      { SIMDE_FLOAT32_C(  -721.46), SIMDE_FLOAT32_C(  -817.04), SIMDE_FLOAT32_C(  -272.24), SIMDE_FLOAT32_C(  -582.08) } },
    { { SIMDE_FLOAT32_C(  -490.34), SIMDE_FLOAT32_C(  -147.19), SIMDE_FLOAT32_C(  -669.89), SIMDE_FLOAT32_C(  -121.49) },
      { SIMDE_FLOAT32_C(  -220.92), SIMDE_FLOAT32_C(   -59.54), SIMDE_FLOAT32_C(  -533.53), SIMDE_FLOAT32_C(  -241.60) },
      { SIMDE_FLOAT32_C(  -490.34), SIMDE_FLOAT32_C(  -147.19), SIMDE_FLOAT32_C(  -669.89), SIMDE_FLOAT32_C(  -241.60) } },
    { { SIMDE_FLOAT32_C(   -27.29), SIMDE_FLOAT32_C(     3.69), SIMDE_FLOAT32_C(   488.26), SIMDE_FLOAT32_C(   151.39) },
      { SIMDE_FLOAT32_C(   279.22), SIMDE_FLOAT32_C(  -953.83), SIMDE_FLOAT32_C(  -922.00), SIMDE_FLOAT32_C(   368.84) },
      { SIMDE_FLOAT32_C(   -27.29), SIMDE_FLOAT32_C(  -953.83), SIMDE_FLOAT32_C(  -922.00), SIMDE_FLOAT32_C(   151.39) } },
    { { SIMDE_FLOAT32_C(  -538.47), SIMDE_FLOAT32_C(   772.06), SIMDE_FLOAT32_C(  -945.16), SIMDE_FLOAT32_C(  -756.59) },
      { SIMDE_FLOAT32_C(    77.58), SIMDE_FLOAT32_C(  -320.91), SIMDE_FLOAT32_C(  -708.00), SIMDE_FLOAT32_C(   -47.76) },
      { SIMDE_FLOAT32_C(  -538.47), SIMDE_FLOAT32_C(  -320.91), SIMDE_FLOAT32_C(  -945.16), SIMDE_FLOAT32_C(  -756.59) } },
    { { SIMDE_FLOAT32_C(  -137.95), SIMDE_FLOAT32_C(   538.36), SIMDE_FLOAT32_C(   753.42), SIMDE_FLOAT32_C(   140.59) },
      { SIMDE_FLOAT32_C(  -771.36), SIMDE_FLOAT32_C(  -518.82), SIMDE_FLOAT32_C(   558.51), SIMDE_FLOAT32_C(  -261.70) },
      { SIMDE_FLOAT32_C(  -771.36), SIMDE_FLOAT32_C(  -518.82), SIMDE_FLOAT32_C(   558.51), SIMDE_FLOAT32_C(  -261.70) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_float32x4_t b = simde_vld1q_f32(test_vec[i].b);
    simde_float32x4_t r = simde_vminnmq_f32(a, b);

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
    simde_float32x4_t r = simde_vminnmq_f32(a, b);

    simde_test_arm_neon_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vminnmq_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 a[2];
    simde_float64 b[2];
    simde_float64 r[2];
  } test_vec[] = {
    #if !defined(SIMDE_FAST_NANS)
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   888.63) },
      { SIMDE_FLOAT64_C(   616.81),             SIMDE_MATH_NAN },
      { SIMDE_FLOAT64_C(   616.81), SIMDE_FLOAT64_C(   888.63) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -916.72) },
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   801.79) },
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -916.72) } },
    #endif
    { { SIMDE_FLOAT64_C(    86.97), SIMDE_FLOAT64_C(  -640.28) },
      { SIMDE_FLOAT64_C(   -46.82), SIMDE_FLOAT64_C(  -633.81) },
      { SIMDE_FLOAT64_C(   -46.82), SIMDE_FLOAT64_C(  -640.28) } },
    { { SIMDE_FLOAT64_C(  -594.11), SIMDE_FLOAT64_C(    31.18) },
      { SIMDE_FLOAT64_C(   735.03), SIMDE_FLOAT64_C(  -132.58) },
      { SIMDE_FLOAT64_C(  -594.11), SIMDE_FLOAT64_C(  -132.58) } },
    { { SIMDE_FLOAT64_C(  -196.76), SIMDE_FLOAT64_C(   789.88) },
      { SIMDE_FLOAT64_C(   110.83), SIMDE_FLOAT64_C(   880.82) },
      { SIMDE_FLOAT64_C(  -196.76), SIMDE_FLOAT64_C(   789.88) } },
    { { SIMDE_FLOAT64_C(  -531.03), SIMDE_FLOAT64_C(   402.83) },
      { SIMDE_FLOAT64_C(  -166.93), SIMDE_FLOAT64_C(   331.02) },
      { SIMDE_FLOAT64_C(  -531.03), SIMDE_FLOAT64_C(   331.02) } },
    { { SIMDE_FLOAT64_C(   -58.81), SIMDE_FLOAT64_C(  -413.51) },
      { SIMDE_FLOAT64_C(  -528.39), SIMDE_FLOAT64_C(   169.82) },
      { SIMDE_FLOAT64_C(  -528.39), SIMDE_FLOAT64_C(  -413.51) } },
    { { SIMDE_FLOAT64_C(    67.67), SIMDE_FLOAT64_C(  -969.88) },
      { SIMDE_FLOAT64_C(   908.12), SIMDE_FLOAT64_C(  -598.34) },
      { SIMDE_FLOAT64_C(    67.67), SIMDE_FLOAT64_C(  -969.88) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2_t a = simde_vld1q_f64(test_vec[i].a);
    simde_float64x2_t b = simde_vld1q_f64(test_vec[i].b);
    simde_float64x2_t r = simde_vminnmq_f64(a, b);

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
    simde_float64x2_t r = simde_vminnmq_f64(a, b);

    simde_test_arm_neon_write_f64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vminnm_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vminnm_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vminnmq_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vminnmq_f64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
