#define SIMDE_TEST_ARM_NEON_INSN minnm

#include "test-neon.h"
#include "../../../simde/arm/neon/minnm.h"

static int
test_simde_vminnmh_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16 a;
    simde_float16 b;
    simde_float16 r;
  } test_vec[] = {
    {    SIMDE_FLOAT16_VALUE(     1.440),
         SIMDE_FLOAT16_VALUE(    13.328),
         SIMDE_FLOAT16_VALUE(     1.440) },
    {    SIMDE_FLOAT16_VALUE(    -9.878),
         SIMDE_FLOAT16_VALUE(   -19.650),
         SIMDE_FLOAT16_VALUE(   -19.650) },
    {    SIMDE_FLOAT16_VALUE(    29.644),
         SIMDE_FLOAT16_VALUE(    22.014),
         SIMDE_FLOAT16_VALUE(    22.014) },
    {    SIMDE_FLOAT16_VALUE(    14.777),
         SIMDE_FLOAT16_VALUE(    12.875),
         SIMDE_FLOAT16_VALUE(    12.875) },
    {    SIMDE_FLOAT16_VALUE(    17.656),
         SIMDE_FLOAT16_VALUE(   -13.833),
         SIMDE_FLOAT16_VALUE(   -13.833) },
    {    SIMDE_FLOAT16_VALUE(    21.142),
         SIMDE_FLOAT16_VALUE(    23.027),
         SIMDE_FLOAT16_VALUE(    21.142) },
    {    SIMDE_FLOAT16_VALUE(    22.998),
         SIMDE_FLOAT16_VALUE(   -29.475),
         SIMDE_FLOAT16_VALUE(   -29.475) },
    {    SIMDE_FLOAT16_VALUE(     2.236),
         SIMDE_FLOAT16_VALUE(     9.245),
         SIMDE_FLOAT16_VALUE(     2.236) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16_t a = test_vec[i].a;
    simde_float16_t b = test_vec[i].b;
    simde_float16_t r = simde_vminnmh_f16(a, b);

    simde_assert_equal_f16(r, test_vec[i].r, 1);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16_t a = simde_test_codegen_random_f16(-100.0f, 100.0f);
    simde_float16_t b = simde_test_codegen_random_f16(-100.0f, 100.0f);
    simde_float16_t r = simde_vminnmh_f16(a, b);

    simde_test_codegen_write_f16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_f16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_f16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vminnm_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16 a[4];
    simde_float16 b[4];
    simde_float16 r[4];
  } test_vec[] = {
    #if !defined(SIMDE_FAST_NANS)
    { {            SIMDE_NANHF, SIMDE_FLOAT16_VALUE(   944.82),            SIMDE_NANHF, SIMDE_FLOAT16_VALUE(  -343.95) },
      { SIMDE_FLOAT16_VALUE(   575.31),            SIMDE_NANHF,            SIMDE_NANHF, SIMDE_FLOAT16_VALUE(   317.39) },
      { SIMDE_FLOAT16_VALUE(   575.31), SIMDE_FLOAT16_VALUE(   944.82),            SIMDE_NANHF, SIMDE_FLOAT16_VALUE(  -343.95) } },
    #endif
    { {  SIMDE_FLOAT16_VALUE(     5.257),  SIMDE_FLOAT16_VALUE(   -27.950),  SIMDE_FLOAT16_VALUE(     7.602),  SIMDE_FLOAT16_VALUE(   -12.753) },
      {  SIMDE_FLOAT16_VALUE(   -21.739),  SIMDE_FLOAT16_VALUE(    28.253),  SIMDE_FLOAT16_VALUE(     8.492),  SIMDE_FLOAT16_VALUE(     2.422) },
      {  SIMDE_FLOAT16_VALUE(   -21.739),  SIMDE_FLOAT16_VALUE(   -27.950),  SIMDE_FLOAT16_VALUE(     7.602),  SIMDE_FLOAT16_VALUE(   -12.753) } },
    { {  SIMDE_FLOAT16_VALUE(    21.558),  SIMDE_FLOAT16_VALUE(    29.490),  SIMDE_FLOAT16_VALUE(     7.239),  SIMDE_FLOAT16_VALUE(     2.544) },
      {  SIMDE_FLOAT16_VALUE(    19.640),  SIMDE_FLOAT16_VALUE(     5.764),  SIMDE_FLOAT16_VALUE(    18.197),  SIMDE_FLOAT16_VALUE(   -27.999) },
      {  SIMDE_FLOAT16_VALUE(    19.640),  SIMDE_FLOAT16_VALUE(     5.764),  SIMDE_FLOAT16_VALUE(     7.239),  SIMDE_FLOAT16_VALUE(   -27.999) } },
    { {  SIMDE_FLOAT16_VALUE(     5.755),  SIMDE_FLOAT16_VALUE(   -22.042),  SIMDE_FLOAT16_VALUE(     4.094),  SIMDE_FLOAT16_VALUE(    18.587) },
      {  SIMDE_FLOAT16_VALUE(    27.599),  SIMDE_FLOAT16_VALUE(   -23.918),  SIMDE_FLOAT16_VALUE(   -11.318),  SIMDE_FLOAT16_VALUE(   -18.671) },
      {  SIMDE_FLOAT16_VALUE(     5.755),  SIMDE_FLOAT16_VALUE(   -23.918),  SIMDE_FLOAT16_VALUE(   -11.318),  SIMDE_FLOAT16_VALUE(   -18.671) } },
    { {  SIMDE_FLOAT16_VALUE(    13.520),  SIMDE_FLOAT16_VALUE(   -17.320),  SIMDE_FLOAT16_VALUE(    14.735),  SIMDE_FLOAT16_VALUE(    17.080) },
      {  SIMDE_FLOAT16_VALUE(    24.380),  SIMDE_FLOAT16_VALUE(    -7.842),  SIMDE_FLOAT16_VALUE(    25.952),  SIMDE_FLOAT16_VALUE(   -25.221) },
      {  SIMDE_FLOAT16_VALUE(    13.520),  SIMDE_FLOAT16_VALUE(   -17.320),  SIMDE_FLOAT16_VALUE(    14.735),  SIMDE_FLOAT16_VALUE(   -25.221) } },
    { {  SIMDE_FLOAT16_VALUE(    27.555),  SIMDE_FLOAT16_VALUE(   -29.369),  SIMDE_FLOAT16_VALUE(     2.941),  SIMDE_FLOAT16_VALUE(    -3.960) },
      {  SIMDE_FLOAT16_VALUE(    15.107),  SIMDE_FLOAT16_VALUE(    19.687),  SIMDE_FLOAT16_VALUE(   -26.641),  SIMDE_FLOAT16_VALUE(   -24.712) },
      {  SIMDE_FLOAT16_VALUE(    15.107),  SIMDE_FLOAT16_VALUE(   -29.369),  SIMDE_FLOAT16_VALUE(   -26.641),  SIMDE_FLOAT16_VALUE(   -24.712) } },
    { {  SIMDE_FLOAT16_VALUE(   -18.835),  SIMDE_FLOAT16_VALUE(   -10.539),  SIMDE_FLOAT16_VALUE(   -14.920),  SIMDE_FLOAT16_VALUE(    16.874) },
      {  SIMDE_FLOAT16_VALUE(     0.092),  SIMDE_FLOAT16_VALUE(   -11.558),  SIMDE_FLOAT16_VALUE(   -22.247),  SIMDE_FLOAT16_VALUE(   -16.417) },
      {  SIMDE_FLOAT16_VALUE(   -18.835),  SIMDE_FLOAT16_VALUE(   -11.558),  SIMDE_FLOAT16_VALUE(   -22.247),  SIMDE_FLOAT16_VALUE(   -16.417) } },
    { {  SIMDE_FLOAT16_VALUE(    10.387),  SIMDE_FLOAT16_VALUE(   -14.357),  SIMDE_FLOAT16_VALUE(    19.689),  SIMDE_FLOAT16_VALUE(   -22.069) },
      {  SIMDE_FLOAT16_VALUE(   -28.179),  SIMDE_FLOAT16_VALUE(   -12.706),  SIMDE_FLOAT16_VALUE(   -16.267),  SIMDE_FLOAT16_VALUE(    26.743) },
      {  SIMDE_FLOAT16_VALUE(   -28.179),  SIMDE_FLOAT16_VALUE(   -14.357),  SIMDE_FLOAT16_VALUE(   -16.267),  SIMDE_FLOAT16_VALUE(   -22.069) } },
    { {  SIMDE_FLOAT16_VALUE(    13.458),  SIMDE_FLOAT16_VALUE(    22.370),  SIMDE_FLOAT16_VALUE(   -22.303),  SIMDE_FLOAT16_VALUE(     7.416) },
      {  SIMDE_FLOAT16_VALUE(   -16.858),  SIMDE_FLOAT16_VALUE(    27.661),  SIMDE_FLOAT16_VALUE(     3.087),  SIMDE_FLOAT16_VALUE(   -20.780) },
      {  SIMDE_FLOAT16_VALUE(   -16.858),  SIMDE_FLOAT16_VALUE(    22.370),  SIMDE_FLOAT16_VALUE(   -22.303),  SIMDE_FLOAT16_VALUE(   -20.780) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x4_t a = simde_vld1_f16(test_vec[i].a);
    simde_float16x4_t b = simde_vld1_f16(test_vec[i].b);
    simde_float16x4_t r = simde_vminnm_f16(a, b);

    simde_test_arm_neon_assert_equal_f16x4(r, simde_vld1_f16(test_vec[i].r), 1);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16x4_t a = simde_test_arm_neon_random_f16x4(-100.0f, 100.0f);
    simde_float16x4_t b = simde_test_arm_neon_random_f16x4(-100.0f, 100.0f);
    simde_float16x4_t r = simde_vminnm_f16(a, b);

    simde_test_arm_neon_write_f16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

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
test_simde_vminnmq_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16 a[8];
    simde_float16 b[8];
    simde_float16 r[8];
  } test_vec[] = {
    { {  SIMDE_FLOAT16_VALUE(     5.798),  SIMDE_FLOAT16_VALUE(   -27.153),  SIMDE_FLOAT16_VALUE(     8.716),  SIMDE_FLOAT16_VALUE(     8.907),
         SIMDE_FLOAT16_VALUE(   -24.412),  SIMDE_FLOAT16_VALUE(   -21.332),  SIMDE_FLOAT16_VALUE(   -26.545),  SIMDE_FLOAT16_VALUE(     2.976) },
      {  SIMDE_FLOAT16_VALUE(     3.813),  SIMDE_FLOAT16_VALUE(     6.027),  SIMDE_FLOAT16_VALUE(     0.118),  SIMDE_FLOAT16_VALUE(   -25.063),
         SIMDE_FLOAT16_VALUE(    20.165),  SIMDE_FLOAT16_VALUE(    -4.071),  SIMDE_FLOAT16_VALUE(     5.899),  SIMDE_FLOAT16_VALUE(    11.264) },
      {  SIMDE_FLOAT16_VALUE(     3.813),  SIMDE_FLOAT16_VALUE(   -27.153),  SIMDE_FLOAT16_VALUE(     0.118),  SIMDE_FLOAT16_VALUE(   -25.063),
         SIMDE_FLOAT16_VALUE(   -24.412),  SIMDE_FLOAT16_VALUE(   -21.332),  SIMDE_FLOAT16_VALUE(   -26.545),  SIMDE_FLOAT16_VALUE(     2.976) } },
    { {  SIMDE_FLOAT16_VALUE(     9.396),  SIMDE_FLOAT16_VALUE(     5.451),  SIMDE_FLOAT16_VALUE(   -29.429),  SIMDE_FLOAT16_VALUE(   -14.539),
         SIMDE_FLOAT16_VALUE(    12.815),  SIMDE_FLOAT16_VALUE(    -6.594),  SIMDE_FLOAT16_VALUE(    16.752),  SIMDE_FLOAT16_VALUE(    27.869) },
      {  SIMDE_FLOAT16_VALUE(    29.771),  SIMDE_FLOAT16_VALUE(    -6.720),  SIMDE_FLOAT16_VALUE(    -0.918),  SIMDE_FLOAT16_VALUE(    20.495),
         SIMDE_FLOAT16_VALUE(   -11.969),  SIMDE_FLOAT16_VALUE(    -5.342),  SIMDE_FLOAT16_VALUE(    -4.910),  SIMDE_FLOAT16_VALUE(    13.154) },
      {  SIMDE_FLOAT16_VALUE(     9.396),  SIMDE_FLOAT16_VALUE(    -6.720),  SIMDE_FLOAT16_VALUE(   -29.429),  SIMDE_FLOAT16_VALUE(   -14.539),
         SIMDE_FLOAT16_VALUE(   -11.969),  SIMDE_FLOAT16_VALUE(    -6.594),  SIMDE_FLOAT16_VALUE(    -4.910),  SIMDE_FLOAT16_VALUE(    13.154) } },
    { {  SIMDE_FLOAT16_VALUE(   -19.043),  SIMDE_FLOAT16_VALUE(    14.641),  SIMDE_FLOAT16_VALUE(   -20.188),  SIMDE_FLOAT16_VALUE(    -9.812),
         SIMDE_FLOAT16_VALUE(   -27.498),  SIMDE_FLOAT16_VALUE(    12.160),  SIMDE_FLOAT16_VALUE(    -4.529),  SIMDE_FLOAT16_VALUE(   -15.966) },
      {  SIMDE_FLOAT16_VALUE(    -7.762),  SIMDE_FLOAT16_VALUE(    -6.922),  SIMDE_FLOAT16_VALUE(   -17.457),  SIMDE_FLOAT16_VALUE(   -26.470),
         SIMDE_FLOAT16_VALUE(   -16.153),  SIMDE_FLOAT16_VALUE(    29.905),  SIMDE_FLOAT16_VALUE(    -4.615),  SIMDE_FLOAT16_VALUE(   -19.026) },
      {  SIMDE_FLOAT16_VALUE(   -19.043),  SIMDE_FLOAT16_VALUE(    -6.922),  SIMDE_FLOAT16_VALUE(   -20.188),  SIMDE_FLOAT16_VALUE(   -26.470),
         SIMDE_FLOAT16_VALUE(   -27.498),  SIMDE_FLOAT16_VALUE(    12.160),  SIMDE_FLOAT16_VALUE(    -4.615),  SIMDE_FLOAT16_VALUE(   -19.026) } },
    { {  SIMDE_FLOAT16_VALUE(   -16.833),  SIMDE_FLOAT16_VALUE(   -25.270),  SIMDE_FLOAT16_VALUE(   -14.787),  SIMDE_FLOAT16_VALUE(    16.772),
         SIMDE_FLOAT16_VALUE(   -14.448),  SIMDE_FLOAT16_VALUE(     7.956),  SIMDE_FLOAT16_VALUE(     6.572),  SIMDE_FLOAT16_VALUE(     3.912) },
      {  SIMDE_FLOAT16_VALUE(   -28.064),  SIMDE_FLOAT16_VALUE(   -13.535),  SIMDE_FLOAT16_VALUE(    26.978),  SIMDE_FLOAT16_VALUE(   -29.120),
         SIMDE_FLOAT16_VALUE(    19.885),  SIMDE_FLOAT16_VALUE(   -26.347),  SIMDE_FLOAT16_VALUE(    23.193),  SIMDE_FLOAT16_VALUE(     3.554) },
      {  SIMDE_FLOAT16_VALUE(   -28.064),  SIMDE_FLOAT16_VALUE(   -25.270),  SIMDE_FLOAT16_VALUE(   -14.787),  SIMDE_FLOAT16_VALUE(   -29.120),
         SIMDE_FLOAT16_VALUE(   -14.448),  SIMDE_FLOAT16_VALUE(   -26.347),  SIMDE_FLOAT16_VALUE(     6.572),  SIMDE_FLOAT16_VALUE(     3.554) } },
    { {  SIMDE_FLOAT16_VALUE(   -29.718),  SIMDE_FLOAT16_VALUE(    12.630),  SIMDE_FLOAT16_VALUE(    28.181),  SIMDE_FLOAT16_VALUE(     4.814),
         SIMDE_FLOAT16_VALUE(     9.088),  SIMDE_FLOAT16_VALUE(   -14.647),  SIMDE_FLOAT16_VALUE(    -0.167),  SIMDE_FLOAT16_VALUE(   -17.205) },
      {  SIMDE_FLOAT16_VALUE(    -8.720),  SIMDE_FLOAT16_VALUE(    15.678),  SIMDE_FLOAT16_VALUE(   -15.505),  SIMDE_FLOAT16_VALUE(    12.442),
         SIMDE_FLOAT16_VALUE(   -16.962),  SIMDE_FLOAT16_VALUE(    -7.101),  SIMDE_FLOAT16_VALUE(   -25.773),  SIMDE_FLOAT16_VALUE(   -13.136) },
      {  SIMDE_FLOAT16_VALUE(   -29.718),  SIMDE_FLOAT16_VALUE(    12.630),  SIMDE_FLOAT16_VALUE(   -15.505),  SIMDE_FLOAT16_VALUE(     4.814),
         SIMDE_FLOAT16_VALUE(   -16.962),  SIMDE_FLOAT16_VALUE(   -14.647),  SIMDE_FLOAT16_VALUE(   -25.773),  SIMDE_FLOAT16_VALUE(   -17.205) } },
    { {  SIMDE_FLOAT16_VALUE(    -6.764),  SIMDE_FLOAT16_VALUE(    -7.654),  SIMDE_FLOAT16_VALUE(     6.292),  SIMDE_FLOAT16_VALUE(     3.678),
         SIMDE_FLOAT16_VALUE(   -14.953),  SIMDE_FLOAT16_VALUE(   -29.760),  SIMDE_FLOAT16_VALUE(    26.763),  SIMDE_FLOAT16_VALUE(   -27.812) },
      {  SIMDE_FLOAT16_VALUE(     9.526),  SIMDE_FLOAT16_VALUE(    11.672),  SIMDE_FLOAT16_VALUE(     3.555),  SIMDE_FLOAT16_VALUE(     2.668),
         SIMDE_FLOAT16_VALUE(    -7.167),  SIMDE_FLOAT16_VALUE(    22.281),  SIMDE_FLOAT16_VALUE(   -28.505),  SIMDE_FLOAT16_VALUE(    -4.155) },
      {  SIMDE_FLOAT16_VALUE(    -6.764),  SIMDE_FLOAT16_VALUE(    -7.654),  SIMDE_FLOAT16_VALUE(     3.555),  SIMDE_FLOAT16_VALUE(     2.668),
         SIMDE_FLOAT16_VALUE(   -14.953),  SIMDE_FLOAT16_VALUE(   -29.760),  SIMDE_FLOAT16_VALUE(   -28.505),  SIMDE_FLOAT16_VALUE(   -27.812) } },
    { {  SIMDE_FLOAT16_VALUE(   -17.445),  SIMDE_FLOAT16_VALUE(    -9.868),  SIMDE_FLOAT16_VALUE(     5.646),  SIMDE_FLOAT16_VALUE(    22.175),
         SIMDE_FLOAT16_VALUE(   -24.196),  SIMDE_FLOAT16_VALUE(   -16.388),  SIMDE_FLOAT16_VALUE(    -1.688),  SIMDE_FLOAT16_VALUE(   -18.190) },
      {  SIMDE_FLOAT16_VALUE(   -20.535),  SIMDE_FLOAT16_VALUE(    19.722),  SIMDE_FLOAT16_VALUE(    -0.297),  SIMDE_FLOAT16_VALUE(    20.425),
         SIMDE_FLOAT16_VALUE(    19.676),  SIMDE_FLOAT16_VALUE(   -27.862),  SIMDE_FLOAT16_VALUE(    -2.094),  SIMDE_FLOAT16_VALUE(   -26.692) },
      {  SIMDE_FLOAT16_VALUE(   -20.535),  SIMDE_FLOAT16_VALUE(    -9.868),  SIMDE_FLOAT16_VALUE(    -0.297),  SIMDE_FLOAT16_VALUE(    20.425),
         SIMDE_FLOAT16_VALUE(   -24.196),  SIMDE_FLOAT16_VALUE(   -27.862),  SIMDE_FLOAT16_VALUE(    -2.094),  SIMDE_FLOAT16_VALUE(   -26.692) } },
    { {  SIMDE_FLOAT16_VALUE(   -13.072),  SIMDE_FLOAT16_VALUE(   -10.733),  SIMDE_FLOAT16_VALUE(   -25.012),  SIMDE_FLOAT16_VALUE(    11.412),
         SIMDE_FLOAT16_VALUE(     4.015),  SIMDE_FLOAT16_VALUE(   -18.567),  SIMDE_FLOAT16_VALUE(   -22.735),  SIMDE_FLOAT16_VALUE(   -11.129) },
      {  SIMDE_FLOAT16_VALUE(    12.100),  SIMDE_FLOAT16_VALUE(   -21.278),  SIMDE_FLOAT16_VALUE(    13.321),  SIMDE_FLOAT16_VALUE(   -28.376),
         SIMDE_FLOAT16_VALUE(    23.727),  SIMDE_FLOAT16_VALUE(    -3.649),  SIMDE_FLOAT16_VALUE(   -28.264),  SIMDE_FLOAT16_VALUE(   -10.418) },
      {  SIMDE_FLOAT16_VALUE(   -13.072),  SIMDE_FLOAT16_VALUE(   -21.278),  SIMDE_FLOAT16_VALUE(   -25.012),  SIMDE_FLOAT16_VALUE(   -28.376),
         SIMDE_FLOAT16_VALUE(     4.015),  SIMDE_FLOAT16_VALUE(   -18.567),  SIMDE_FLOAT16_VALUE(   -28.264),  SIMDE_FLOAT16_VALUE(   -11.129) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x8_t a = simde_vld1q_f16(test_vec[i].a);
    simde_float16x8_t b = simde_vld1q_f16(test_vec[i].b);
    simde_float16x8_t r = simde_vminnmq_f16(a, b);

    simde_test_arm_neon_assert_equal_f16x8(r, simde_vld1q_f16(test_vec[i].r), 1);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16x8_t a = simde_test_arm_neon_random_f16x8(-100.0f, 100.0f);
    simde_float16x8_t b = simde_test_arm_neon_random_f16x8(-100.0f, 100.0f);
    simde_float16x8_t r = simde_vminnmq_f16(a, b);

    simde_test_arm_neon_write_f16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
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
SIMDE_TEST_FUNC_LIST_ENTRY(vminnmh_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vminnm_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vminnm_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vminnm_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vminnmq_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vminnmq_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vminnmq_f64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
