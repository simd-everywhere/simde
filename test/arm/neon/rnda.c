#define SIMDE_TEST_ARM_NEON_INSN rnda

#include "test-neon.h"
#include "../../../simde/arm/neon/rnda.h"

static int
test_simde_vrndah_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16 a;
    simde_float16 r;
  } test_vec[] = {
    {    SIMDE_FLOAT16_VALUE(   6.736),
         SIMDE_FLOAT16_VALUE(   7.000) },
    {    SIMDE_FLOAT16_VALUE(  -1.376),
         SIMDE_FLOAT16_VALUE(  -1.000) },
    {    SIMDE_FLOAT16_VALUE(  13.024),
         SIMDE_FLOAT16_VALUE(  13.000) },
    {    SIMDE_FLOAT16_VALUE(  -3.766),
         SIMDE_FLOAT16_VALUE(  -4.000) },
    {    SIMDE_FLOAT16_VALUE(  13.381),
         SIMDE_FLOAT16_VALUE(  13.000) },
    {    SIMDE_FLOAT16_VALUE(   1.703),
         SIMDE_FLOAT16_VALUE(   2.000) },
    {    SIMDE_FLOAT16_VALUE( -14.441),
         SIMDE_FLOAT16_VALUE( -14.000) },
    {    SIMDE_FLOAT16_VALUE( -12.916),
         SIMDE_FLOAT16_VALUE( -13.000) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16_t a = test_vec[i].a;
    simde_float16_t r = simde_vrndah_f16(a);

    simde_assert_equal_f16(r, test_vec[i].r, 1);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16_t a = simde_test_codegen_random_f16(-100.0f, 100.0f);
    simde_float16_t r = simde_vrndah_f16(a);

    simde_test_codegen_write_f16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_f16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vrnda_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16 a[4];
    simde_float16 r[4];
  } test_vec[] = {
    { {  SIMDE_FLOAT16_VALUE(   6.871),  SIMDE_FLOAT16_VALUE(  14.982),  SIMDE_FLOAT16_VALUE( -13.894),  SIMDE_FLOAT16_VALUE(  11.464) },
      {  SIMDE_FLOAT16_VALUE(   7.000),  SIMDE_FLOAT16_VALUE(  15.000),  SIMDE_FLOAT16_VALUE( -14.000),  SIMDE_FLOAT16_VALUE(  11.000) } },
    { {  SIMDE_FLOAT16_VALUE(  -0.308),  SIMDE_FLOAT16_VALUE(   5.472),  SIMDE_FLOAT16_VALUE(  -2.787),  SIMDE_FLOAT16_VALUE(  -9.117) },
      {  SIMDE_FLOAT16_VALUE(  -0.000),  SIMDE_FLOAT16_VALUE(   5.000),  SIMDE_FLOAT16_VALUE(  -3.000),  SIMDE_FLOAT16_VALUE(  -9.000) } },
    { {  SIMDE_FLOAT16_VALUE( -13.714),  SIMDE_FLOAT16_VALUE(  -5.764),  SIMDE_FLOAT16_VALUE(  -4.124),  SIMDE_FLOAT16_VALUE(  10.999) },
      {  SIMDE_FLOAT16_VALUE( -14.000),  SIMDE_FLOAT16_VALUE(  -6.000),  SIMDE_FLOAT16_VALUE(  -4.000),  SIMDE_FLOAT16_VALUE(  11.000) } },
    { {  SIMDE_FLOAT16_VALUE(  -1.350),  SIMDE_FLOAT16_VALUE(  10.834),  SIMDE_FLOAT16_VALUE(   7.572),  SIMDE_FLOAT16_VALUE(  -9.312) },
      {  SIMDE_FLOAT16_VALUE(  -1.000),  SIMDE_FLOAT16_VALUE(  11.000),  SIMDE_FLOAT16_VALUE(   8.000),  SIMDE_FLOAT16_VALUE(  -9.000) } },
    { {  SIMDE_FLOAT16_VALUE(  -0.107),  SIMDE_FLOAT16_VALUE(  13.492),  SIMDE_FLOAT16_VALUE(  -2.932),  SIMDE_FLOAT16_VALUE( -12.573) },
      {  SIMDE_FLOAT16_VALUE(  -0.000),  SIMDE_FLOAT16_VALUE(  13.000),  SIMDE_FLOAT16_VALUE(  -3.000),  SIMDE_FLOAT16_VALUE( -13.000) } },
    { {  SIMDE_FLOAT16_VALUE( -10.880),  SIMDE_FLOAT16_VALUE( -13.001),  SIMDE_FLOAT16_VALUE(   5.054),  SIMDE_FLOAT16_VALUE(  -8.685) },
      {  SIMDE_FLOAT16_VALUE( -11.000),  SIMDE_FLOAT16_VALUE( -13.000),  SIMDE_FLOAT16_VALUE(   5.000),  SIMDE_FLOAT16_VALUE(  -9.000) } },
    { {  SIMDE_FLOAT16_VALUE(  -0.873),  SIMDE_FLOAT16_VALUE( -10.907),  SIMDE_FLOAT16_VALUE(   6.177),  SIMDE_FLOAT16_VALUE( -10.352) },
      {  SIMDE_FLOAT16_VALUE(  -1.000),  SIMDE_FLOAT16_VALUE( -11.000),  SIMDE_FLOAT16_VALUE(   6.000),  SIMDE_FLOAT16_VALUE( -10.000) } },
    { {  SIMDE_FLOAT16_VALUE(   7.022),  SIMDE_FLOAT16_VALUE(  -1.662),  SIMDE_FLOAT16_VALUE(  10.313),  SIMDE_FLOAT16_VALUE(  -0.816) },
      {  SIMDE_FLOAT16_VALUE(   7.000),  SIMDE_FLOAT16_VALUE(  -2.000),  SIMDE_FLOAT16_VALUE(  10.000),  SIMDE_FLOAT16_VALUE(  -1.000) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x4_t a = simde_vld1_f16(test_vec[i].a);
    simde_float16x4_t r = simde_vrnda_f16(a);

    simde_test_arm_neon_assert_equal_f16x4(r, simde_vld1_f16(test_vec[i].r), 1);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16x4_t a = simde_test_arm_neon_random_f16x4(-100.0f, 100.0f);
    simde_float16x4_t r = simde_vrnda_f16(a);

    simde_test_arm_neon_write_f16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vrnda_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a[2];
    simde_float32 r[2];
  } test_vec[] = {
    #if defined(SIMDE_FAST_NANS) && !defined(SIMDE_FAST_MATH)
    { {            SIMDE_MATH_NANF,           -SIMDE_MATH_NANF },
      {            SIMDE_MATH_NANF,           -SIMDE_MATH_NANF } },
    #endif
    { {  SIMDE_FLOAT32_C( 197.733), -SIMDE_FLOAT32_C( 703.017) },
      {  SIMDE_FLOAT32_C( 198.000), -SIMDE_FLOAT32_C( 703.000) } },
    { { -SIMDE_FLOAT32_C( 280.594), -SIMDE_FLOAT32_C( 810.720) },
      { -SIMDE_FLOAT32_C( 281.000), -SIMDE_FLOAT32_C( 811.000) } },
    { {  SIMDE_FLOAT32_C( 527.543), -SIMDE_FLOAT32_C( 264.107) },
      {  SIMDE_FLOAT32_C( 528.000), -SIMDE_FLOAT32_C( 264.000) } },
    { { -SIMDE_FLOAT32_C( 248.846), -SIMDE_FLOAT32_C( 723.257) },
      { -SIMDE_FLOAT32_C( 249.000), -SIMDE_FLOAT32_C( 723.000) } },
    { { -SIMDE_FLOAT32_C( 310.557),  SIMDE_FLOAT32_C( 836.121) },
      { -SIMDE_FLOAT32_C( 311.000),  SIMDE_FLOAT32_C( 836.000) } },
    { { -SIMDE_FLOAT32_C( 959.016),  SIMDE_FLOAT32_C( 821.254) },
      { -SIMDE_FLOAT32_C( 959.000),  SIMDE_FLOAT32_C( 821.000) } },
    { { -SIMDE_FLOAT32_C( 960.285),  SIMDE_FLOAT32_C( 632.779) },
      { -SIMDE_FLOAT32_C( 960.000),  SIMDE_FLOAT32_C( 633.000) } },
    { {  SIMDE_FLOAT32_C( 678.633), -SIMDE_FLOAT32_C( 945.967) },
      {  SIMDE_FLOAT32_C( 679.000), -SIMDE_FLOAT32_C( 946.000) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t a = simde_vld1_f32(test_vec[i].a);
    simde_float32x2_t r = simde_vrnda_f32(a);

    simde_test_arm_neon_assert_equal_f32x2(r, simde_vld1_f32(test_vec[i].r), 1);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x2_t a = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f);
    simde_float32x2_t r = simde_vrnda_f32(a);

    simde_test_arm_neon_write_f32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vrnda_f64 (SIMDE_MUNIT_TEST_ARGS) {
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
    { {  SIMDE_FLOAT64_C( 36459.750) },
      {  SIMDE_FLOAT64_C( 36460.000) } },
    { { -SIMDE_FLOAT64_C( 15092.453) },
      { -SIMDE_FLOAT64_C( 15092.000) } },
    { {  SIMDE_FLOAT64_C( 36894.703) },
      {  SIMDE_FLOAT64_C( 36895.000) } },
    { { -SIMDE_FLOAT64_C( 83931.336) },
      { -SIMDE_FLOAT64_C( 83931.000) } },
    { { -SIMDE_FLOAT64_C(  6804.094) },
      { -SIMDE_FLOAT64_C(  6804.000) } },
    { { -SIMDE_FLOAT64_C( 92113.172) },
      { -SIMDE_FLOAT64_C( 92113.000) } },
    { {  SIMDE_FLOAT64_C( 95536.969) },
      {  SIMDE_FLOAT64_C( 95537.000) } },
    { { -SIMDE_FLOAT64_C( 25631.938) },
      { -SIMDE_FLOAT64_C( 25632.000) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x1_t a = simde_vld1_f64(test_vec[i].a);
    simde_float64x1_t r = simde_vrnda_f64(a);

    simde_test_arm_neon_assert_equal_f64x1(r, simde_vld1_f64(test_vec[i].r), 1);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x1_t a = simde_test_arm_neon_random_f64x1(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde_float64x1_t r = simde_vrnda_f64(a);

    simde_test_arm_neon_write_f64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vrndaq_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16 a[8];
    simde_float16 r[8];
  } test_vec[] = {
    { {  SIMDE_FLOAT16_VALUE(  -6.892),  SIMDE_FLOAT16_VALUE(  -3.661),  SIMDE_FLOAT16_VALUE( -13.835),  SIMDE_FLOAT16_VALUE(  -0.473),
         SIMDE_FLOAT16_VALUE(  10.422),  SIMDE_FLOAT16_VALUE(   1.102),  SIMDE_FLOAT16_VALUE(   4.893),  SIMDE_FLOAT16_VALUE(   9.618) },
      {  SIMDE_FLOAT16_VALUE(  -7.000),  SIMDE_FLOAT16_VALUE(  -4.000),  SIMDE_FLOAT16_VALUE( -14.000),  SIMDE_FLOAT16_VALUE(  -0.000),
         SIMDE_FLOAT16_VALUE(  10.000),  SIMDE_FLOAT16_VALUE(   1.000),  SIMDE_FLOAT16_VALUE(   5.000),  SIMDE_FLOAT16_VALUE(  10.000) } },
    { {  SIMDE_FLOAT16_VALUE(  14.852),  SIMDE_FLOAT16_VALUE(  -2.536),  SIMDE_FLOAT16_VALUE(  10.842),  SIMDE_FLOAT16_VALUE(  -1.668),
         SIMDE_FLOAT16_VALUE(  -9.043),  SIMDE_FLOAT16_VALUE( -12.193),  SIMDE_FLOAT16_VALUE(  12.205),  SIMDE_FLOAT16_VALUE(  -2.455) },
      {  SIMDE_FLOAT16_VALUE(  15.000),  SIMDE_FLOAT16_VALUE(  -3.000),  SIMDE_FLOAT16_VALUE(  11.000),  SIMDE_FLOAT16_VALUE(  -2.000),
         SIMDE_FLOAT16_VALUE(  -9.000),  SIMDE_FLOAT16_VALUE( -12.000),  SIMDE_FLOAT16_VALUE(  12.000),  SIMDE_FLOAT16_VALUE(  -2.000) } },
    { {  SIMDE_FLOAT16_VALUE(  -6.576),  SIMDE_FLOAT16_VALUE(  -0.330),  SIMDE_FLOAT16_VALUE(   3.201),  SIMDE_FLOAT16_VALUE(  -3.354),
         SIMDE_FLOAT16_VALUE(  -3.893),  SIMDE_FLOAT16_VALUE(  -0.735),  SIMDE_FLOAT16_VALUE(  10.914),  SIMDE_FLOAT16_VALUE(  -4.372) },
      {  SIMDE_FLOAT16_VALUE(  -7.000),  SIMDE_FLOAT16_VALUE(  -0.000),  SIMDE_FLOAT16_VALUE(   3.000),  SIMDE_FLOAT16_VALUE(  -3.000),
         SIMDE_FLOAT16_VALUE(  -4.000),  SIMDE_FLOAT16_VALUE(  -1.000),  SIMDE_FLOAT16_VALUE(  11.000),  SIMDE_FLOAT16_VALUE(  -4.000) } },
    { {  SIMDE_FLOAT16_VALUE(   2.797),  SIMDE_FLOAT16_VALUE( -10.777),  SIMDE_FLOAT16_VALUE(   3.585),  SIMDE_FLOAT16_VALUE(   4.909),
         SIMDE_FLOAT16_VALUE(  -8.589),  SIMDE_FLOAT16_VALUE( -12.654),  SIMDE_FLOAT16_VALUE(  12.824),  SIMDE_FLOAT16_VALUE(   0.208) },
      {  SIMDE_FLOAT16_VALUE(   3.000),  SIMDE_FLOAT16_VALUE( -11.000),  SIMDE_FLOAT16_VALUE(   4.000),  SIMDE_FLOAT16_VALUE(   5.000),
         SIMDE_FLOAT16_VALUE(  -9.000),  SIMDE_FLOAT16_VALUE( -13.000),  SIMDE_FLOAT16_VALUE(  13.000),  SIMDE_FLOAT16_VALUE(   0.000) } },
    { {  SIMDE_FLOAT16_VALUE( -11.300),  SIMDE_FLOAT16_VALUE(  -4.632),  SIMDE_FLOAT16_VALUE(  14.850),  SIMDE_FLOAT16_VALUE(  -6.672),
         SIMDE_FLOAT16_VALUE(   0.537),  SIMDE_FLOAT16_VALUE(   9.147),  SIMDE_FLOAT16_VALUE( -14.792),  SIMDE_FLOAT16_VALUE(  12.159) },
      {  SIMDE_FLOAT16_VALUE( -11.000),  SIMDE_FLOAT16_VALUE(  -5.000),  SIMDE_FLOAT16_VALUE(  15.000),  SIMDE_FLOAT16_VALUE(  -7.000),
         SIMDE_FLOAT16_VALUE(   1.000),  SIMDE_FLOAT16_VALUE(   9.000),  SIMDE_FLOAT16_VALUE( -15.000),  SIMDE_FLOAT16_VALUE(  12.000) } },
    { {  SIMDE_FLOAT16_VALUE( -12.395),  SIMDE_FLOAT16_VALUE(  12.656),  SIMDE_FLOAT16_VALUE( -11.353),  SIMDE_FLOAT16_VALUE(   0.572),
         SIMDE_FLOAT16_VALUE(  -6.730),  SIMDE_FLOAT16_VALUE(   0.011),  SIMDE_FLOAT16_VALUE( -10.815),  SIMDE_FLOAT16_VALUE( -11.053) },
      {  SIMDE_FLOAT16_VALUE( -12.000),  SIMDE_FLOAT16_VALUE(  13.000),  SIMDE_FLOAT16_VALUE( -11.000),  SIMDE_FLOAT16_VALUE(   1.000),
         SIMDE_FLOAT16_VALUE(  -7.000),  SIMDE_FLOAT16_VALUE(   0.000),  SIMDE_FLOAT16_VALUE( -11.000),  SIMDE_FLOAT16_VALUE( -11.000) } },
    { {  SIMDE_FLOAT16_VALUE(   6.242),  SIMDE_FLOAT16_VALUE(   8.134),  SIMDE_FLOAT16_VALUE(  12.486),  SIMDE_FLOAT16_VALUE(  -5.416),
         SIMDE_FLOAT16_VALUE(   6.483),  SIMDE_FLOAT16_VALUE( -13.180),  SIMDE_FLOAT16_VALUE(  -3.250),  SIMDE_FLOAT16_VALUE( -11.421) },
      {  SIMDE_FLOAT16_VALUE(   6.000),  SIMDE_FLOAT16_VALUE(   8.000),  SIMDE_FLOAT16_VALUE(  12.000),  SIMDE_FLOAT16_VALUE(  -5.000),
         SIMDE_FLOAT16_VALUE(   6.000),  SIMDE_FLOAT16_VALUE( -13.000),  SIMDE_FLOAT16_VALUE(  -3.000),  SIMDE_FLOAT16_VALUE( -11.000) } },
    { {  SIMDE_FLOAT16_VALUE(   0.277),  SIMDE_FLOAT16_VALUE(  11.683),  SIMDE_FLOAT16_VALUE(  10.970),  SIMDE_FLOAT16_VALUE(  11.361),
         SIMDE_FLOAT16_VALUE(  -5.683),  SIMDE_FLOAT16_VALUE(  11.647),  SIMDE_FLOAT16_VALUE( -13.872),  SIMDE_FLOAT16_VALUE(  -9.766) },
      {  SIMDE_FLOAT16_VALUE(   0.000),  SIMDE_FLOAT16_VALUE(  12.000),  SIMDE_FLOAT16_VALUE(  11.000),  SIMDE_FLOAT16_VALUE(  11.000),
         SIMDE_FLOAT16_VALUE(  -6.000),  SIMDE_FLOAT16_VALUE(  12.000),  SIMDE_FLOAT16_VALUE( -14.000),  SIMDE_FLOAT16_VALUE( -10.000) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x8_t a = simde_vld1q_f16(test_vec[i].a);
    simde_float16x8_t r = simde_vrndaq_f16(a);
    simde_test_arm_neon_assert_equal_f16x8(r, simde_vld1q_f16(test_vec[i].r), 1);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16x8_t a = simde_test_arm_neon_random_f16x8(-100.0f, 100.0f);
    simde_float16x8_t r = simde_vrndaq_f16(a);

    simde_test_arm_neon_write_f16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vrndaq_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a[4];
    simde_float32 r[4];
  } test_vec[] = {
    #if !defined(SIMDE_FAST_NANS)
    { {            SIMDE_MATH_NANF,           -SIMDE_MATH_NANF,            SIMDE_MATH_NANF,           -SIMDE_MATH_NANF },
      {            SIMDE_MATH_NANF,           -SIMDE_MATH_NANF,            SIMDE_MATH_NANF,           -SIMDE_MATH_NANF } },
    #endif
    { { -SIMDE_FLOAT32_C( 781.239), -SIMDE_FLOAT32_C( 636.652),  SIMDE_FLOAT32_C( 314.554),  SIMDE_FLOAT32_C( 850.348) },
      { -SIMDE_FLOAT32_C( 781.000), -SIMDE_FLOAT32_C( 637.000),  SIMDE_FLOAT32_C( 315.000),  SIMDE_FLOAT32_C( 850.000) } },
    { {  SIMDE_FLOAT32_C( 627.817), -SIMDE_FLOAT32_C( 146.386), -SIMDE_FLOAT32_C(  57.039),  SIMDE_FLOAT32_C( 594.762) },
      {  SIMDE_FLOAT32_C( 628.000), -SIMDE_FLOAT32_C( 146.000), -SIMDE_FLOAT32_C(  57.000),  SIMDE_FLOAT32_C( 595.000) } },
    { {  SIMDE_FLOAT32_C( 160.131),  SIMDE_FLOAT32_C( 376.915), -SIMDE_FLOAT32_C( 909.500), -SIMDE_FLOAT32_C( 167.874) },
      {  SIMDE_FLOAT32_C( 160.000),  SIMDE_FLOAT32_C( 377.000), -SIMDE_FLOAT32_C( 910.000), -SIMDE_FLOAT32_C( 168.000) } },
    { {  SIMDE_FLOAT32_C( 379.051),  SIMDE_FLOAT32_C( 454.543),  SIMDE_FLOAT32_C( 100.075),  SIMDE_FLOAT32_C( 899.298) },
      {  SIMDE_FLOAT32_C( 379.000),  SIMDE_FLOAT32_C( 455.000),  SIMDE_FLOAT32_C( 100.000),  SIMDE_FLOAT32_C( 899.000) } },
    { { -SIMDE_FLOAT32_C(  41.128), -SIMDE_FLOAT32_C( 425.349),  SIMDE_FLOAT32_C( 585.964),  SIMDE_FLOAT32_C( 840.558) },
      { -SIMDE_FLOAT32_C(  41.000), -SIMDE_FLOAT32_C( 425.000),  SIMDE_FLOAT32_C( 586.000),  SIMDE_FLOAT32_C( 841.000) } },
    { { -SIMDE_FLOAT32_C( 212.222), -SIMDE_FLOAT32_C( 612.625), -SIMDE_FLOAT32_C( 917.235),  SIMDE_FLOAT32_C( 130.068) },
      { -SIMDE_FLOAT32_C( 212.000), -SIMDE_FLOAT32_C( 613.000), -SIMDE_FLOAT32_C( 917.000),  SIMDE_FLOAT32_C( 130.000) } },
    { {  SIMDE_FLOAT32_C( 743.414),  SIMDE_FLOAT32_C( 305.845), -SIMDE_FLOAT32_C( 706.328), -SIMDE_FLOAT32_C( 237.941) },
      {  SIMDE_FLOAT32_C( 743.000),  SIMDE_FLOAT32_C( 306.000), -SIMDE_FLOAT32_C( 706.000), -SIMDE_FLOAT32_C( 238.000) } },
    { {  SIMDE_FLOAT32_C( 841.700), -SIMDE_FLOAT32_C(  35.482),  SIMDE_FLOAT32_C( 836.224),  SIMDE_FLOAT32_C(   7.087) },
      {  SIMDE_FLOAT32_C( 842.000), -SIMDE_FLOAT32_C(  35.000),  SIMDE_FLOAT32_C( 836.000),  SIMDE_FLOAT32_C(   7.000) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_float32x4_t r = simde_vrndaq_f32(a);
    simde_test_arm_neon_assert_equal_f32x4(r, simde_vld1q_f32(test_vec[i].r), 1);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x4_t a = simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f);
    simde_float32x4_t r = simde_vrndaq_f32(a);

    simde_test_arm_neon_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vrndaq_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 a[2];
    simde_float64 r[2];
  } test_vec[] = {
    #if !defined(SIMDE_FAST_NANS)
    { {             SIMDE_MATH_NAN,            -SIMDE_MATH_NAN },
      {             SIMDE_MATH_NAN,            -SIMDE_MATH_NAN } },
    #endif
    { {  SIMDE_FLOAT64_C( 40696.578),  SIMDE_FLOAT64_C(  5235.766) },
      {  SIMDE_FLOAT64_C( 40697.000),  SIMDE_FLOAT64_C(  5236.000) } },
    { { -SIMDE_FLOAT64_C( 47016.145),  SIMDE_FLOAT64_C( 41946.219) },
      { -SIMDE_FLOAT64_C( 47016.000),  SIMDE_FLOAT64_C( 41946.000) } },
    { { -SIMDE_FLOAT64_C( 51036.566), -SIMDE_FLOAT64_C( 93299.359) },
      { -SIMDE_FLOAT64_C( 51037.000), -SIMDE_FLOAT64_C( 93299.000) } },
    { { -SIMDE_FLOAT64_C( 38175.742), -SIMDE_FLOAT64_C( 66542.070) },
      { -SIMDE_FLOAT64_C( 38176.000), -SIMDE_FLOAT64_C( 66542.000) } },
    { {  SIMDE_FLOAT64_C( 91767.109), -SIMDE_FLOAT64_C(  9011.594) },
      {  SIMDE_FLOAT64_C( 91767.000), -SIMDE_FLOAT64_C(  9012.000) } },
    { { -SIMDE_FLOAT64_C( 15053.062),  SIMDE_FLOAT64_C( 53011.312) },
      { -SIMDE_FLOAT64_C( 15053.000),  SIMDE_FLOAT64_C( 53011.000) } },
    { { -SIMDE_FLOAT64_C(  1268.938), -SIMDE_FLOAT64_C( 40951.945) },
      { -SIMDE_FLOAT64_C(  1269.000), -SIMDE_FLOAT64_C( 40952.000) } },
    { {  SIMDE_FLOAT64_C( 71025.484), -SIMDE_FLOAT64_C( 68604.133) },
      {  SIMDE_FLOAT64_C( 71025.000), -SIMDE_FLOAT64_C( 68604.000) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2_t a = simde_vld1q_f64(test_vec[i].a);
    simde_float64x2_t r = simde_vrndaq_f64(a);

    simde_test_arm_neon_assert_equal_f64x2(r, simde_vld1q_f64(test_vec[i].r), 1);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x2_t a = simde_test_arm_neon_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde_float64x2_t r = simde_vrndaq_f64(a);

    simde_test_arm_neon_write_f64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vrndah_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vrnda_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vrnda_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vrnda_f64)

SIMDE_TEST_FUNC_LIST_ENTRY(vrndaq_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vrndaq_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vrndaq_f64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
