#define SIMDE_TEST_ARM_NEON_INSN rsqrts

#include "test-neon.h"
#include "../../../simde/arm/neon/rsqrts.h"

static int
test_simde_vrsqrts_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a[2];
    simde_float32 b[2];
    simde_float32 r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(    -1.81), SIMDE_FLOAT32_C(     6.08) },
      { SIMDE_FLOAT32_C(    -0.75), SIMDE_FLOAT32_C(     3.06) },
      { SIMDE_FLOAT32_C(     0.82), SIMDE_FLOAT32_C(    -7.80) } },
    { { SIMDE_FLOAT32_C(     4.44), SIMDE_FLOAT32_C(     6.63) },
      { SIMDE_FLOAT32_C(     5.97), SIMDE_FLOAT32_C(    -5.82) },
      { SIMDE_FLOAT32_C(   -11.75), SIMDE_FLOAT32_C(    20.79) } },
    { { SIMDE_FLOAT32_C(    -4.07), SIMDE_FLOAT32_C(     2.30) },
      { SIMDE_FLOAT32_C(    -2.84), SIMDE_FLOAT32_C(    -2.53) },
      { SIMDE_FLOAT32_C(    -4.28), SIMDE_FLOAT32_C(     4.41) } },
    { { SIMDE_FLOAT32_C(    -7.18), SIMDE_FLOAT32_C(    -5.76) },
      { SIMDE_FLOAT32_C(     0.29), SIMDE_FLOAT32_C(    -6.65) },
      { SIMDE_FLOAT32_C(     2.54), SIMDE_FLOAT32_C(   -17.65) } },
    { { SIMDE_FLOAT32_C(    -6.30), SIMDE_FLOAT32_C(    -9.44) },
      { SIMDE_FLOAT32_C(    -1.04), SIMDE_FLOAT32_C(     1.58) },
      { SIMDE_FLOAT32_C(    -1.78), SIMDE_FLOAT32_C(     8.96) } },
    { { SIMDE_FLOAT32_C(     9.05), SIMDE_FLOAT32_C(     4.99) },
      { SIMDE_FLOAT32_C(     3.75), SIMDE_FLOAT32_C(    -1.14) },
      { SIMDE_FLOAT32_C(   -15.47), SIMDE_FLOAT32_C(     4.34) } },
    { { SIMDE_FLOAT32_C(    -6.57), SIMDE_FLOAT32_C(    -6.46) },
      { SIMDE_FLOAT32_C(    -0.70), SIMDE_FLOAT32_C(     8.06) },
      { SIMDE_FLOAT32_C(    -0.80), SIMDE_FLOAT32_C(    27.53) } },
    { { SIMDE_FLOAT32_C(     4.91), SIMDE_FLOAT32_C(     1.78) },
      { SIMDE_FLOAT32_C(     6.18), SIMDE_FLOAT32_C(    -6.90) },
      { SIMDE_FLOAT32_C(   -13.67), SIMDE_FLOAT32_C(     7.64) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t a = simde_vld1_f32(test_vec[i].a);
    simde_float32x2_t b = simde_vld1_f32(test_vec[i].b);
    simde_float32x2_t r = simde_vrsqrts_f32(a, b);

    simde_test_arm_neon_assert_equal_f32x2(r, simde_vld1_f32(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x2_t a = simde_test_arm_neon_random_f32x2(-10.0f, 10.0f);
    simde_float32x2_t b = simde_test_arm_neon_random_f32x2(-10.0f, 10.0f);
    simde_float32x2_t r = simde_vrsqrts_f32(a, b);

    simde_test_arm_neon_write_f32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vrsqrts_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 a[1];
    simde_float64 b[1];
    simde_float64 r[1];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(     6.87) },
  { SIMDE_FLOAT64_C(     8.55) },
  { SIMDE_FLOAT64_C(   -27.87) } },
{ { SIMDE_FLOAT64_C(    -1.98) },
  { SIMDE_FLOAT64_C(     2.09) },
  { SIMDE_FLOAT64_C(     3.57) } },
{ { SIMDE_FLOAT64_C(     7.13) },
  { SIMDE_FLOAT64_C(    -9.63) },
  { SIMDE_FLOAT64_C(    35.83) } },
{ { SIMDE_FLOAT64_C(    -3.43) },
  { SIMDE_FLOAT64_C(    -5.37) },
  { SIMDE_FLOAT64_C(    -7.71) } },
{ { SIMDE_FLOAT64_C(    -1.34) },
  { SIMDE_FLOAT64_C(    -4.98) },
  { SIMDE_FLOAT64_C(    -1.84) } },
{ { SIMDE_FLOAT64_C(     9.08) },
  { SIMDE_FLOAT64_C(    -0.19) },
  { SIMDE_FLOAT64_C(     2.36) } },
{ { SIMDE_FLOAT64_C(    -7.89) },
  { SIMDE_FLOAT64_C(     9.75) },
  { SIMDE_FLOAT64_C(    39.96) } },
{ { SIMDE_FLOAT64_C(     2.41) },
  { SIMDE_FLOAT64_C(     8.30) },
  { SIMDE_FLOAT64_C(    -8.50) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x1_t a = simde_vld1_f64(test_vec[i].a);
    simde_float64x1_t b = simde_vld1_f64(test_vec[i].b);
    simde_float64x1_t r = simde_vrsqrts_f64(a, b);

    simde_test_arm_neon_assert_equal_f64x1(r, simde_vld1_f64(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x1_t a = simde_test_arm_neon_random_f64x1(-10.0, 10.0);
    simde_float64x1_t b = simde_test_arm_neon_random_f64x1(-10.0, 10.0);
    simde_float64x1_t r = simde_vrsqrts_f64(a, b);

    simde_test_arm_neon_write_f64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x1(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vrsqrtsq_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a[4];
    simde_float32 b[4];
    simde_float32 r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(    -2.14), SIMDE_FLOAT32_C(    -4.57), SIMDE_FLOAT32_C(     6.16), SIMDE_FLOAT32_C(    -7.69) },
      { SIMDE_FLOAT32_C(    -7.94), SIMDE_FLOAT32_C(     2.13), SIMDE_FLOAT32_C(    -3.52), SIMDE_FLOAT32_C(    -2.01) },
      { SIMDE_FLOAT32_C(    -7.00), SIMDE_FLOAT32_C(     6.37), SIMDE_FLOAT32_C(    12.34), SIMDE_FLOAT32_C(    -6.23) } },
    { { SIMDE_FLOAT32_C(    -5.58), SIMDE_FLOAT32_C(     3.64), SIMDE_FLOAT32_C(     5.46), SIMDE_FLOAT32_C(    -2.76) },
      { SIMDE_FLOAT32_C(     7.89), SIMDE_FLOAT32_C(    -4.25), SIMDE_FLOAT32_C(     0.59), SIMDE_FLOAT32_C(    -8.41) },
      { SIMDE_FLOAT32_C(    23.51), SIMDE_FLOAT32_C(     9.24), SIMDE_FLOAT32_C(    -0.11), SIMDE_FLOAT32_C(   -10.11) } },
    { { SIMDE_FLOAT32_C(    -3.70), SIMDE_FLOAT32_C(     9.56), SIMDE_FLOAT32_C(     3.17), SIMDE_FLOAT32_C(    -4.64) },
      { SIMDE_FLOAT32_C(     4.55), SIMDE_FLOAT32_C(    -3.08), SIMDE_FLOAT32_C(     4.22), SIMDE_FLOAT32_C(     7.98) },
      { SIMDE_FLOAT32_C(     9.92), SIMDE_FLOAT32_C(    16.22), SIMDE_FLOAT32_C(    -5.19), SIMDE_FLOAT32_C(    20.01) } },
    { { SIMDE_FLOAT32_C(     0.47), SIMDE_FLOAT32_C(    -6.48), SIMDE_FLOAT32_C(     6.04), SIMDE_FLOAT32_C(    -4.62) },
      { SIMDE_FLOAT32_C(     5.30), SIMDE_FLOAT32_C(     2.22), SIMDE_FLOAT32_C(    -1.53), SIMDE_FLOAT32_C(    -6.84) },
      { SIMDE_FLOAT32_C(     0.25), SIMDE_FLOAT32_C(     8.69), SIMDE_FLOAT32_C(     6.12), SIMDE_FLOAT32_C(   -14.30) } },
    { { SIMDE_FLOAT32_C(     7.64), SIMDE_FLOAT32_C(    -5.37), SIMDE_FLOAT32_C(    -4.53), SIMDE_FLOAT32_C(     9.70) },
      { SIMDE_FLOAT32_C(     6.76), SIMDE_FLOAT32_C(     1.95), SIMDE_FLOAT32_C(    -2.31), SIMDE_FLOAT32_C(    -8.82) },
      { SIMDE_FLOAT32_C(   -24.32), SIMDE_FLOAT32_C(     6.74), SIMDE_FLOAT32_C(    -3.73), SIMDE_FLOAT32_C(    44.28) } },
    { { SIMDE_FLOAT32_C(    -4.41), SIMDE_FLOAT32_C(    -6.85), SIMDE_FLOAT32_C(    -1.58), SIMDE_FLOAT32_C(    -6.52) },
      { SIMDE_FLOAT32_C(    -1.10), SIMDE_FLOAT32_C(     9.02), SIMDE_FLOAT32_C(    -4.93), SIMDE_FLOAT32_C(     5.20) },
      { SIMDE_FLOAT32_C(    -0.93), SIMDE_FLOAT32_C(    32.39), SIMDE_FLOAT32_C(    -2.39), SIMDE_FLOAT32_C(    18.45) } },
    { { SIMDE_FLOAT32_C(     8.57), SIMDE_FLOAT32_C(     8.24), SIMDE_FLOAT32_C(    -9.44), SIMDE_FLOAT32_C(     3.12) },
      { SIMDE_FLOAT32_C(    -4.83), SIMDE_FLOAT32_C(     4.78), SIMDE_FLOAT32_C(     1.10), SIMDE_FLOAT32_C(     5.63) },
      { SIMDE_FLOAT32_C(    22.20), SIMDE_FLOAT32_C(   -18.19), SIMDE_FLOAT32_C(     6.69), SIMDE_FLOAT32_C(    -7.28) } },
    { { SIMDE_FLOAT32_C(     8.30), SIMDE_FLOAT32_C(    -2.87), SIMDE_FLOAT32_C(    -8.99), SIMDE_FLOAT32_C(     3.60) },
      { SIMDE_FLOAT32_C(     9.35), SIMDE_FLOAT32_C(    -0.52), SIMDE_FLOAT32_C(     6.77), SIMDE_FLOAT32_C(     6.99) },
      { SIMDE_FLOAT32_C(   -37.30), SIMDE_FLOAT32_C(     0.75), SIMDE_FLOAT32_C(    31.93), SIMDE_FLOAT32_C(   -11.08) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_float32x4_t b = simde_vld1q_f32(test_vec[i].b);
    simde_float32x4_t r = simde_vrsqrtsq_f32(a, b);
    simde_test_arm_neon_assert_equal_f32x4(r, simde_vld1q_f32(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x4_t a = simde_test_arm_neon_random_f32x4(-10.0f, 10.0f);
    simde_float32x4_t b = simde_test_arm_neon_random_f32x4(-10.0f, 10.0f);
    simde_float32x4_t r = simde_vrsqrtsq_f32(a, b);

    simde_test_arm_neon_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vrsqrtsq_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 a[2];
    simde_float64 b[2];
    simde_float64 r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(     5.69), SIMDE_FLOAT64_C(     9.51) },
      { SIMDE_FLOAT64_C(     7.48), SIMDE_FLOAT64_C(    -9.06) },
      { SIMDE_FLOAT64_C(   -19.78), SIMDE_FLOAT64_C(    44.58) } },
    { { SIMDE_FLOAT64_C(     3.21), SIMDE_FLOAT64_C(    -0.11) },
      { SIMDE_FLOAT64_C(     4.18), SIMDE_FLOAT64_C(    -0.48) },
      { SIMDE_FLOAT64_C(    -5.21), SIMDE_FLOAT64_C(     1.47) } },
    { { SIMDE_FLOAT64_C(    -8.62), SIMDE_FLOAT64_C(     1.53) },
      { SIMDE_FLOAT64_C(     1.11), SIMDE_FLOAT64_C(    -6.72) },
      { SIMDE_FLOAT64_C(     6.28), SIMDE_FLOAT64_C(     6.64) } },
    { { SIMDE_FLOAT64_C(    -9.36), SIMDE_FLOAT64_C(    -8.80) },
      { SIMDE_FLOAT64_C(     7.91), SIMDE_FLOAT64_C(    -3.14) },
      { SIMDE_FLOAT64_C(    38.52), SIMDE_FLOAT64_C(   -12.32) } },
    { { SIMDE_FLOAT64_C(    -6.74), SIMDE_FLOAT64_C(     1.44) },
      { SIMDE_FLOAT64_C(    -9.99), SIMDE_FLOAT64_C(    -4.84) },
      { SIMDE_FLOAT64_C(   -32.17), SIMDE_FLOAT64_C(     4.98) } },
    { { SIMDE_FLOAT64_C(    -1.82), SIMDE_FLOAT64_C(     4.17) },
      { SIMDE_FLOAT64_C(    -1.16), SIMDE_FLOAT64_C(    -1.96) },
      { SIMDE_FLOAT64_C(     0.44), SIMDE_FLOAT64_C(     5.59) } },
    { { SIMDE_FLOAT64_C(     5.33), SIMDE_FLOAT64_C(     5.84) },
      { SIMDE_FLOAT64_C(    -3.06), SIMDE_FLOAT64_C(     7.73) },
      { SIMDE_FLOAT64_C(     9.65), SIMDE_FLOAT64_C(   -21.07) } },
    { { SIMDE_FLOAT64_C(    -7.36), SIMDE_FLOAT64_C(     9.00) },
      { SIMDE_FLOAT64_C(     4.68), SIMDE_FLOAT64_C(     8.34) },
      { SIMDE_FLOAT64_C(    18.72), SIMDE_FLOAT64_C(   -36.03) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2_t a = simde_vld1q_f64(test_vec[i].a);
    simde_float64x2_t b = simde_vld1q_f64(test_vec[i].b);
    simde_float64x2_t r = simde_vrsqrtsq_f64(a, b);
    simde_test_arm_neon_assert_equal_f64x2(r, simde_vld1q_f64(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x2_t a = simde_test_arm_neon_random_f64x2(-10.0, 10.0);
    simde_float64x2_t b = simde_test_arm_neon_random_f64x2(-10.0, 10.0);
    simde_float64x2_t r = simde_vrsqrtsq_f64(a, b);

    simde_test_arm_neon_write_f64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vrsqrtss_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32_t a;
    simde_float32_t b;
    simde_float32_t r;
  } test_vec[] = {
    { SIMDE_FLOAT32_C(   -68.85),
      SIMDE_FLOAT32_C(  -965.73),
      SIMDE_FLOAT32_C(-33243.75) },
    { SIMDE_FLOAT32_C(  -888.41),
      SIMDE_FLOAT32_C(  -408.81),
      SIMDE_FLOAT32_C(-181593.94) },
    { SIMDE_FLOAT32_C(  -560.30),
      SIMDE_FLOAT32_C(  -722.30),
      SIMDE_FLOAT32_C(-202350.84) },
    { SIMDE_FLOAT32_C(   234.04),
      SIMDE_FLOAT32_C(  -798.13),
      SIMDE_FLOAT32_C( 93398.67) },
    { SIMDE_FLOAT32_C(  -880.28),
      SIMDE_FLOAT32_C(  -643.05),
      SIMDE_FLOAT32_C(-283030.53) },
    { SIMDE_FLOAT32_C(  -257.26),
      SIMDE_FLOAT32_C(   445.45),
      SIMDE_FLOAT32_C( 57299.74) },
    { SIMDE_FLOAT32_C(   162.67),
      SIMDE_FLOAT32_C(   786.15),
      SIMDE_FLOAT32_C(-63940.01) },
    { SIMDE_FLOAT32_C(  -927.81),
      SIMDE_FLOAT32_C(   416.86),
      SIMDE_FLOAT32_C(193384.94) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32_t r = simde_vrsqrtss_f32(test_vec[i].a, test_vec[i].b);
    simde_assert_equal_f32(r, test_vec[i].r, 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32_t a = simde_test_codegen_random_f32(-1000, 1000);
    simde_float32_t b = simde_test_codegen_random_f32(-1000, 1000);
    simde_float32_t r = simde_vrsqrtss_f32(a, b);

    simde_test_codegen_write_f32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_f32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_f32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vrsqrtsd_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64_t a;
    simde_float64_t b;
    simde_float64_t r;
  } test_vec[] = {
    { SIMDE_FLOAT64_C(   733.74),
      SIMDE_FLOAT64_C(  -247.63),
      SIMDE_FLOAT64_C( 90849.52) },
    { SIMDE_FLOAT64_C(  -888.92),
      SIMDE_FLOAT64_C(  -818.58),
      SIMDE_FLOAT64_C(-363824.57) },
    { SIMDE_FLOAT64_C(  -846.64),
      SIMDE_FLOAT64_C(   961.55),
      SIMDE_FLOAT64_C(407044.85) },
    { SIMDE_FLOAT64_C(  -865.36),
      SIMDE_FLOAT64_C(   170.96),
      SIMDE_FLOAT64_C( 73972.47) },
    { SIMDE_FLOAT64_C(  -307.65),
      SIMDE_FLOAT64_C(  -831.35),
      SIMDE_FLOAT64_C(-127880.91) },
    { SIMDE_FLOAT64_C(  -150.80),
      SIMDE_FLOAT64_C(   619.79),
      SIMDE_FLOAT64_C( 46733.67) },
    { SIMDE_FLOAT64_C(   764.67),
      SIMDE_FLOAT64_C(  -382.92),
      SIMDE_FLOAT64_C(146405.22) },
    { SIMDE_FLOAT64_C(  -804.26),
      SIMDE_FLOAT64_C(  -267.13),
      SIMDE_FLOAT64_C(-107419.49) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64_t r = simde_vrsqrtsd_f64(test_vec[i].a, test_vec[i].b);
    simde_assert_equal_f64(r, test_vec[i].r, 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64_t a = simde_test_codegen_random_f64(-1000, 1000);
    simde_float64_t b = simde_test_codegen_random_f64(-1000, 1000);
    simde_float64_t r = simde_vrsqrtsd_f64(a, b);

    simde_test_codegen_write_f64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_f64(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_f64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vrsqrts_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vrsqrts_f64)

SIMDE_TEST_FUNC_LIST_ENTRY(vrsqrtsq_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vrsqrtsq_f64)

SIMDE_TEST_FUNC_LIST_ENTRY(vrsqrtss_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vrsqrtsd_f64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
