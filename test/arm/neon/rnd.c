#define SIMDE_TEST_ARM_NEON_INSN rnd

#include "test-neon.h"
#include "../../../simde/arm/neon/rnd.h"

static int
test_simde_vrndh_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16 a;
    simde_float16 r;
  } test_vec[] = {
    {    SIMDE_FLOAT16_VALUE( -14.261),
         SIMDE_FLOAT16_VALUE( -14.000) },
    {    SIMDE_FLOAT16_VALUE(   6.574),
         SIMDE_FLOAT16_VALUE(   6.000) },
    {    SIMDE_FLOAT16_VALUE(  -0.878),
         SIMDE_FLOAT16_VALUE(  -0.000) },
    {    SIMDE_FLOAT16_VALUE(   4.926),
         SIMDE_FLOAT16_VALUE(   4.000) },
    {    SIMDE_FLOAT16_VALUE(   9.135),
         SIMDE_FLOAT16_VALUE(   9.000) },
    {    SIMDE_FLOAT16_VALUE(  -4.597),
         SIMDE_FLOAT16_VALUE(  -4.000) },
    {    SIMDE_FLOAT16_VALUE(  -7.602),
         SIMDE_FLOAT16_VALUE(  -7.000) },
    {    SIMDE_FLOAT16_VALUE(   5.002),
         SIMDE_FLOAT16_VALUE(   5.000) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16_t a = test_vec[i].a;
    simde_float16_t r = simde_vrndh_f16(a);

    simde_assert_equal_f16(r, test_vec[i].r, 1);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16_t a = simde_test_codegen_random_f16(-100.0f, 100.0f);
    simde_float16_t r = simde_vrndh_f16(a);

    simde_test_codegen_write_f16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_f16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vrnd_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16 a[4];
    simde_float16 r[4];
  } test_vec[] = {
    { {  SIMDE_FLOAT16_VALUE(  -6.827),  SIMDE_FLOAT16_VALUE(  11.895),  SIMDE_FLOAT16_VALUE(   9.704),  SIMDE_FLOAT16_VALUE(   0.246) },
      {  SIMDE_FLOAT16_VALUE(  -6.000),  SIMDE_FLOAT16_VALUE(  11.000),  SIMDE_FLOAT16_VALUE(   9.000),  SIMDE_FLOAT16_VALUE(   0.000) } },
    { {  SIMDE_FLOAT16_VALUE(  -2.253),  SIMDE_FLOAT16_VALUE(  -8.446),  SIMDE_FLOAT16_VALUE(   7.552),  SIMDE_FLOAT16_VALUE(   7.496) },
      {  SIMDE_FLOAT16_VALUE(  -2.000),  SIMDE_FLOAT16_VALUE(  -8.000),  SIMDE_FLOAT16_VALUE(   7.000),  SIMDE_FLOAT16_VALUE(   7.000) } },
    { {  SIMDE_FLOAT16_VALUE(   7.468),  SIMDE_FLOAT16_VALUE(  -0.776),  SIMDE_FLOAT16_VALUE(  13.568),  SIMDE_FLOAT16_VALUE(  -8.010) },
      {  SIMDE_FLOAT16_VALUE(   7.000),  SIMDE_FLOAT16_VALUE(  -0.000),  SIMDE_FLOAT16_VALUE(  13.000),  SIMDE_FLOAT16_VALUE(  -8.000) } },
    { {  SIMDE_FLOAT16_VALUE(   3.989),  SIMDE_FLOAT16_VALUE(  -9.543),  SIMDE_FLOAT16_VALUE(   3.469),  SIMDE_FLOAT16_VALUE(   7.344) },
      {  SIMDE_FLOAT16_VALUE(   3.000),  SIMDE_FLOAT16_VALUE(  -9.000),  SIMDE_FLOAT16_VALUE(   3.000),  SIMDE_FLOAT16_VALUE(   7.000) } },
    { {  SIMDE_FLOAT16_VALUE(  -9.100),  SIMDE_FLOAT16_VALUE(  -2.248),  SIMDE_FLOAT16_VALUE( -13.411),  SIMDE_FLOAT16_VALUE(   0.798) },
      {  SIMDE_FLOAT16_VALUE(  -9.000),  SIMDE_FLOAT16_VALUE(  -2.000),  SIMDE_FLOAT16_VALUE( -13.000),  SIMDE_FLOAT16_VALUE(   0.000) } },
    { {  SIMDE_FLOAT16_VALUE(  11.416),  SIMDE_FLOAT16_VALUE(  -6.437),  SIMDE_FLOAT16_VALUE(   8.753),  SIMDE_FLOAT16_VALUE(   7.841) },
      {  SIMDE_FLOAT16_VALUE(  11.000),  SIMDE_FLOAT16_VALUE(  -6.000),  SIMDE_FLOAT16_VALUE(   8.000),  SIMDE_FLOAT16_VALUE(   7.000) } },
    { {  SIMDE_FLOAT16_VALUE(   5.128),  SIMDE_FLOAT16_VALUE(  -2.616),  SIMDE_FLOAT16_VALUE(   5.873),  SIMDE_FLOAT16_VALUE(  14.800) },
      {  SIMDE_FLOAT16_VALUE(   5.000),  SIMDE_FLOAT16_VALUE(  -2.000),  SIMDE_FLOAT16_VALUE(   5.000),  SIMDE_FLOAT16_VALUE(  14.000) } },
    { {  SIMDE_FLOAT16_VALUE( -14.333),  SIMDE_FLOAT16_VALUE(  -1.856),  SIMDE_FLOAT16_VALUE(  10.297),  SIMDE_FLOAT16_VALUE(  -9.342) },
      {  SIMDE_FLOAT16_VALUE( -14.000),  SIMDE_FLOAT16_VALUE(  -1.000),  SIMDE_FLOAT16_VALUE(  10.000),  SIMDE_FLOAT16_VALUE(  -9.000) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x4_t a = simde_vld1_f16(test_vec[i].a);
    simde_float16x4_t r = simde_vrnd_f16(a);

    simde_test_arm_neon_assert_equal_f16x4(r, simde_vld1_f16(test_vec[i].r), 1);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16x4_t a = simde_test_arm_neon_random_f16x4(-100.0f, 100.0f);
    simde_float16x4_t r = simde_vrnd_f16(a);

    simde_test_arm_neon_write_f16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vrnd_f32 (SIMDE_MUNIT_TEST_ARGS) {
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
      { SIMDE_FLOAT32_C(    -1.00), SIMDE_FLOAT32_C(     1.00) } },
    { { SIMDE_FLOAT32_C(    -2.50), SIMDE_FLOAT32_C(     2.50) },
      { SIMDE_FLOAT32_C(    -2.00), SIMDE_FLOAT32_C(     2.00) } },
    { { SIMDE_FLOAT32_C(   782.33), SIMDE_FLOAT32_C(    23.83) },
      { SIMDE_FLOAT32_C(   782.00), SIMDE_FLOAT32_C(    23.00) } },
    { { SIMDE_FLOAT32_C(  -231.98), SIMDE_FLOAT32_C(  -121.26) },
      { SIMDE_FLOAT32_C(  -231.00), SIMDE_FLOAT32_C(  -121.00) } },
    { { SIMDE_FLOAT32_C(   524.61), SIMDE_FLOAT32_C(   500.02) },
      { SIMDE_FLOAT32_C(   524.00), SIMDE_FLOAT32_C(   500.00) } },
    { { SIMDE_FLOAT32_C(    80.15), SIMDE_FLOAT32_C(   517.44) },
      { SIMDE_FLOAT32_C(    80.00), SIMDE_FLOAT32_C(   517.00) } },
    { { SIMDE_FLOAT32_C(  -754.87), SIMDE_FLOAT32_C(   128.37) },
      { SIMDE_FLOAT32_C(  -754.00), SIMDE_FLOAT32_C(   128.00) } },
    { { SIMDE_FLOAT32_C(   182.53), SIMDE_FLOAT32_C(   136.96) },
      { SIMDE_FLOAT32_C(   182.00), SIMDE_FLOAT32_C(   136.00) } },
    { { SIMDE_FLOAT32_C(   605.41), SIMDE_FLOAT32_C(  -833.56) },
      { SIMDE_FLOAT32_C(   605.00), SIMDE_FLOAT32_C(  -833.00) } },
    { { SIMDE_FLOAT32_C(   774.26), SIMDE_FLOAT32_C(  -578.69) },
      { SIMDE_FLOAT32_C(   774.00), SIMDE_FLOAT32_C(  -578.00) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t a = simde_vld1_f32(test_vec[i].a);
    simde_float32x2_t r = simde_vrnd_f32(a);

    simde_test_arm_neon_assert_equal_f32x2(r, simde_vld1_f32(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x2_t a = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f);
    simde_float32x2_t r = simde_vrnd_f32(a);

    simde_test_arm_neon_write_f32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vrnd_f64 (SIMDE_MUNIT_TEST_ARGS) {
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
      { SIMDE_FLOAT64_C(    -1.00) } },
    { { SIMDE_FLOAT64_C(     1.50) },
      { SIMDE_FLOAT64_C(     1.00) } },
    { { SIMDE_FLOAT64_C(    -2.50) },
      { SIMDE_FLOAT64_C(    -2.00) } },
    { { SIMDE_FLOAT64_C(     2.50) },
      { SIMDE_FLOAT64_C(     2.00) } },
    { { SIMDE_FLOAT64_C(   667.17) },
      { SIMDE_FLOAT64_C(   667.00) } },
    { { SIMDE_FLOAT64_C(   472.88) },
      { SIMDE_FLOAT64_C(   472.00) } },
    { { SIMDE_FLOAT64_C(   161.95) },
      { SIMDE_FLOAT64_C(   161.00) } },
    { { SIMDE_FLOAT64_C(  -277.95) },
      { SIMDE_FLOAT64_C(  -277.00) } },
    { { SIMDE_FLOAT64_C(   876.07) },
      { SIMDE_FLOAT64_C(   876.00) } },
    { { SIMDE_FLOAT64_C(   151.96) },
      { SIMDE_FLOAT64_C(   151.00) } },
    { { SIMDE_FLOAT64_C(  -135.07) },
      { SIMDE_FLOAT64_C(  -135.00) } },
    { { SIMDE_FLOAT64_C(  -815.34) },
      { SIMDE_FLOAT64_C(  -815.00) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x1_t a = simde_vld1_f64(test_vec[i].a);
    simde_float64x1_t r = simde_vrnd_f64(a);

    simde_test_arm_neon_assert_equal_f64x1(r, simde_vld1_f64(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x1_t a = simde_test_arm_neon_random_f64x1(-1000.0, 1000.0);
    simde_float64x1_t r = simde_vrnd_f64(a);

    simde_test_arm_neon_write_f64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vrndq_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16 a[8];
    simde_float16 r[8];
  } test_vec[] = {
    { {  SIMDE_FLOAT16_VALUE(  13.437),  SIMDE_FLOAT16_VALUE(   9.082),  SIMDE_FLOAT16_VALUE(  -3.676),  SIMDE_FLOAT16_VALUE(  13.196),
         SIMDE_FLOAT16_VALUE( -12.234),  SIMDE_FLOAT16_VALUE(   6.022),  SIMDE_FLOAT16_VALUE(  -4.825),  SIMDE_FLOAT16_VALUE(   3.346) },
      {  SIMDE_FLOAT16_VALUE(  13.000),  SIMDE_FLOAT16_VALUE(   9.000),  SIMDE_FLOAT16_VALUE(  -3.000),  SIMDE_FLOAT16_VALUE(  13.000),
         SIMDE_FLOAT16_VALUE( -12.000),  SIMDE_FLOAT16_VALUE(   6.000),  SIMDE_FLOAT16_VALUE(  -4.000),  SIMDE_FLOAT16_VALUE(   3.000) } },
    { {  SIMDE_FLOAT16_VALUE( -11.146),  SIMDE_FLOAT16_VALUE(  -4.889),  SIMDE_FLOAT16_VALUE(  -2.848),  SIMDE_FLOAT16_VALUE(   9.379),
         SIMDE_FLOAT16_VALUE(   1.540),  SIMDE_FLOAT16_VALUE(   6.644),  SIMDE_FLOAT16_VALUE(  -0.849),  SIMDE_FLOAT16_VALUE( -12.635) },
      {  SIMDE_FLOAT16_VALUE( -11.000),  SIMDE_FLOAT16_VALUE(  -4.000),  SIMDE_FLOAT16_VALUE(  -2.000),  SIMDE_FLOAT16_VALUE(   9.000),
         SIMDE_FLOAT16_VALUE(   1.000),  SIMDE_FLOAT16_VALUE(   6.000),  SIMDE_FLOAT16_VALUE(  -0.000),  SIMDE_FLOAT16_VALUE( -12.000) } },
    { {  SIMDE_FLOAT16_VALUE(   9.172),  SIMDE_FLOAT16_VALUE(  -9.263),  SIMDE_FLOAT16_VALUE(  14.449),  SIMDE_FLOAT16_VALUE(  -6.927),
         SIMDE_FLOAT16_VALUE(   3.828),  SIMDE_FLOAT16_VALUE(  -7.774),  SIMDE_FLOAT16_VALUE(   8.167),  SIMDE_FLOAT16_VALUE( -10.535) },
      {  SIMDE_FLOAT16_VALUE(   9.000),  SIMDE_FLOAT16_VALUE(  -9.000),  SIMDE_FLOAT16_VALUE(  14.000),  SIMDE_FLOAT16_VALUE(  -6.000),
         SIMDE_FLOAT16_VALUE(   3.000),  SIMDE_FLOAT16_VALUE(  -7.000),  SIMDE_FLOAT16_VALUE(   8.000),  SIMDE_FLOAT16_VALUE( -10.000) } },
    { {  SIMDE_FLOAT16_VALUE( -10.830),  SIMDE_FLOAT16_VALUE(  -6.668),  SIMDE_FLOAT16_VALUE(  11.719),  SIMDE_FLOAT16_VALUE( -10.468),
         SIMDE_FLOAT16_VALUE( -14.566),  SIMDE_FLOAT16_VALUE(  -5.221),  SIMDE_FLOAT16_VALUE(  -0.440),  SIMDE_FLOAT16_VALUE(  10.387) },
      {  SIMDE_FLOAT16_VALUE( -10.000),  SIMDE_FLOAT16_VALUE(  -6.000),  SIMDE_FLOAT16_VALUE(  11.000),  SIMDE_FLOAT16_VALUE( -10.000),
         SIMDE_FLOAT16_VALUE( -14.000),  SIMDE_FLOAT16_VALUE(  -5.000),  SIMDE_FLOAT16_VALUE(  -0.000),  SIMDE_FLOAT16_VALUE(  10.000) } },
    { {  SIMDE_FLOAT16_VALUE(  -3.230),  SIMDE_FLOAT16_VALUE( -11.258),  SIMDE_FLOAT16_VALUE(  -7.571),  SIMDE_FLOAT16_VALUE(   1.131),
         SIMDE_FLOAT16_VALUE(  -6.249),  SIMDE_FLOAT16_VALUE(   1.441),  SIMDE_FLOAT16_VALUE( -11.714),  SIMDE_FLOAT16_VALUE(   4.947) },
      {  SIMDE_FLOAT16_VALUE(  -3.000),  SIMDE_FLOAT16_VALUE( -11.000),  SIMDE_FLOAT16_VALUE(  -7.000),  SIMDE_FLOAT16_VALUE(   1.000),
         SIMDE_FLOAT16_VALUE(  -6.000),  SIMDE_FLOAT16_VALUE(   1.000),  SIMDE_FLOAT16_VALUE( -11.000),  SIMDE_FLOAT16_VALUE(   4.000) } },
    { {  SIMDE_FLOAT16_VALUE(   5.647),  SIMDE_FLOAT16_VALUE(  11.152),  SIMDE_FLOAT16_VALUE(  14.197),  SIMDE_FLOAT16_VALUE(  14.850),
         SIMDE_FLOAT16_VALUE(  -9.118),  SIMDE_FLOAT16_VALUE(  14.401),  SIMDE_FLOAT16_VALUE(  -5.287),  SIMDE_FLOAT16_VALUE(  -6.947) },
      {  SIMDE_FLOAT16_VALUE(   5.000),  SIMDE_FLOAT16_VALUE(  11.000),  SIMDE_FLOAT16_VALUE(  14.000),  SIMDE_FLOAT16_VALUE(  14.000),
         SIMDE_FLOAT16_VALUE(  -9.000),  SIMDE_FLOAT16_VALUE(  14.000),  SIMDE_FLOAT16_VALUE(  -5.000),  SIMDE_FLOAT16_VALUE(  -6.000) } },
    { {  SIMDE_FLOAT16_VALUE(   9.249),  SIMDE_FLOAT16_VALUE( -12.980),  SIMDE_FLOAT16_VALUE(  -2.587),  SIMDE_FLOAT16_VALUE(   5.904),
         SIMDE_FLOAT16_VALUE(  -8.108),  SIMDE_FLOAT16_VALUE(  -6.401),  SIMDE_FLOAT16_VALUE( -10.969),  SIMDE_FLOAT16_VALUE(  13.376) },
      {  SIMDE_FLOAT16_VALUE(   9.000),  SIMDE_FLOAT16_VALUE( -12.000),  SIMDE_FLOAT16_VALUE(  -2.000),  SIMDE_FLOAT16_VALUE(   5.000),
         SIMDE_FLOAT16_VALUE(  -8.000),  SIMDE_FLOAT16_VALUE(  -6.000),  SIMDE_FLOAT16_VALUE( -10.000),  SIMDE_FLOAT16_VALUE(  13.000) } },
    { {  SIMDE_FLOAT16_VALUE(  -5.304),  SIMDE_FLOAT16_VALUE( -12.597),  SIMDE_FLOAT16_VALUE(  -0.612),  SIMDE_FLOAT16_VALUE(  -6.978),
         SIMDE_FLOAT16_VALUE(   5.831),  SIMDE_FLOAT16_VALUE(   4.090),  SIMDE_FLOAT16_VALUE(  -4.397),  SIMDE_FLOAT16_VALUE(  11.647) },
      {  SIMDE_FLOAT16_VALUE(  -5.000),  SIMDE_FLOAT16_VALUE( -12.000),  SIMDE_FLOAT16_VALUE(  -0.000),  SIMDE_FLOAT16_VALUE(  -6.000),
         SIMDE_FLOAT16_VALUE(   5.000),  SIMDE_FLOAT16_VALUE(   4.000),  SIMDE_FLOAT16_VALUE(  -4.000),  SIMDE_FLOAT16_VALUE(  11.000) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x8_t a = simde_vld1q_f16(test_vec[i].a);
    simde_float16x8_t r = simde_vrndq_f16(a);
    simde_test_arm_neon_assert_equal_f16x8(r, simde_vld1q_f16(test_vec[i].r), 1);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16x8_t a = simde_test_arm_neon_random_f16x8(-100.0f, 100.0f);
    simde_float16x8_t r = simde_vrndq_f16(a);

    simde_test_arm_neon_write_f16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vrndq_f32 (SIMDE_MUNIT_TEST_ARGS) {
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
      { SIMDE_FLOAT32_C(    -1.00), SIMDE_FLOAT32_C(     1.00), SIMDE_FLOAT32_C(    -2.00), SIMDE_FLOAT32_C(     2.00) } },
    { { SIMDE_FLOAT32_C(  -722.64), SIMDE_FLOAT32_C(   549.67), SIMDE_FLOAT32_C(   360.83), SIMDE_FLOAT32_C(   702.11) },
      { SIMDE_FLOAT32_C(  -722.00), SIMDE_FLOAT32_C(   549.00), SIMDE_FLOAT32_C(   360.00), SIMDE_FLOAT32_C(   702.00) } },
    { { SIMDE_FLOAT32_C(   923.48), SIMDE_FLOAT32_C(   285.32), SIMDE_FLOAT32_C(    55.43), SIMDE_FLOAT32_C(   705.81) },
      { SIMDE_FLOAT32_C(   923.00), SIMDE_FLOAT32_C(   285.00), SIMDE_FLOAT32_C(    55.00), SIMDE_FLOAT32_C(   705.00) } },
    { { SIMDE_FLOAT32_C(  -690.85), SIMDE_FLOAT32_C(   823.44), SIMDE_FLOAT32_C(  -415.44), SIMDE_FLOAT32_C(   833.76) },
      { SIMDE_FLOAT32_C(  -690.00), SIMDE_FLOAT32_C(   823.00), SIMDE_FLOAT32_C(  -415.00), SIMDE_FLOAT32_C(   833.00) } },
    { { SIMDE_FLOAT32_C(   323.46), SIMDE_FLOAT32_C(   664.70), SIMDE_FLOAT32_C(   351.21), SIMDE_FLOAT32_C(   568.59) },
      { SIMDE_FLOAT32_C(   323.00), SIMDE_FLOAT32_C(   664.00), SIMDE_FLOAT32_C(   351.00), SIMDE_FLOAT32_C(   568.00) } },
    { { SIMDE_FLOAT32_C(  -206.93), SIMDE_FLOAT32_C(  -466.27), SIMDE_FLOAT32_C(  -294.45), SIMDE_FLOAT32_C(  -601.52) },
      { SIMDE_FLOAT32_C(  -206.00), SIMDE_FLOAT32_C(  -466.00), SIMDE_FLOAT32_C(  -294.00), SIMDE_FLOAT32_C(  -601.00) } },
    { { SIMDE_FLOAT32_C(  -299.83), SIMDE_FLOAT32_C(  -520.19), SIMDE_FLOAT32_C(  -180.21), SIMDE_FLOAT32_C(  -632.66) },
      { SIMDE_FLOAT32_C(  -299.00), SIMDE_FLOAT32_C(  -520.00), SIMDE_FLOAT32_C(  -180.00), SIMDE_FLOAT32_C(  -632.00) } },
    { { SIMDE_FLOAT32_C(   952.69), SIMDE_FLOAT32_C(   981.74), SIMDE_FLOAT32_C(    89.39), SIMDE_FLOAT32_C(   828.76) },
      { SIMDE_FLOAT32_C(   952.00), SIMDE_FLOAT32_C(   981.00), SIMDE_FLOAT32_C(    89.00), SIMDE_FLOAT32_C(   828.00) } },
    { { SIMDE_FLOAT32_C(   133.70), SIMDE_FLOAT32_C(   954.32), SIMDE_FLOAT32_C(  -986.58), SIMDE_FLOAT32_C(   411.06) },
      { SIMDE_FLOAT32_C(   133.00), SIMDE_FLOAT32_C(   954.00), SIMDE_FLOAT32_C(  -986.00), SIMDE_FLOAT32_C(   411.00) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_float32x4_t r = simde_vrndq_f32(a);
    simde_test_arm_neon_assert_equal_f32x4(r, simde_vld1q_f32(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x4_t a = simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f);
    simde_float32x4_t r = simde_vrndq_f32(a);

    simde_test_arm_neon_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vrndq_f64 (SIMDE_MUNIT_TEST_ARGS) {
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
      { SIMDE_FLOAT64_C(    -1.00), SIMDE_FLOAT64_C(     1.00) } },
    { { SIMDE_FLOAT64_C(    -2.50), SIMDE_FLOAT64_C(     2.50) },
      { SIMDE_FLOAT64_C(    -2.00), SIMDE_FLOAT64_C(     2.00) } },
    { { SIMDE_FLOAT64_C(   503.99), SIMDE_FLOAT64_C(   374.26) },
      { SIMDE_FLOAT64_C(   503.00), SIMDE_FLOAT64_C(   374.00) } },
    { { SIMDE_FLOAT64_C(   113.17), SIMDE_FLOAT64_C(   427.47) },
      { SIMDE_FLOAT64_C(   113.00), SIMDE_FLOAT64_C(   427.00) } },
    { { SIMDE_FLOAT64_C(  -340.42), SIMDE_FLOAT64_C(  -831.40) },
      { SIMDE_FLOAT64_C(  -340.00), SIMDE_FLOAT64_C(  -831.00) } },
    { { SIMDE_FLOAT64_C(   133.28), SIMDE_FLOAT64_C(   -31.27) },
      { SIMDE_FLOAT64_C(   133.00), SIMDE_FLOAT64_C(   -31.00) } },
    { { SIMDE_FLOAT64_C(   992.04), SIMDE_FLOAT64_C(   717.84) },
      { SIMDE_FLOAT64_C(   992.00), SIMDE_FLOAT64_C(   717.00) } },
    { { SIMDE_FLOAT64_C(  -197.51), SIMDE_FLOAT64_C(   315.50) },
      { SIMDE_FLOAT64_C(  -197.00), SIMDE_FLOAT64_C(   315.00) } },
    { { SIMDE_FLOAT64_C(   382.54), SIMDE_FLOAT64_C(  -846.31) },
      { SIMDE_FLOAT64_C(   382.00), SIMDE_FLOAT64_C(  -846.00) } },
    { { SIMDE_FLOAT64_C(  -115.91), SIMDE_FLOAT64_C(  -824.39) },
      { SIMDE_FLOAT64_C(  -115.00), SIMDE_FLOAT64_C(  -824.00) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2_t a = simde_vld1q_f64(test_vec[i].a);
    simde_float64x2_t r = simde_vrndq_f64(a);

    simde_test_arm_neon_assert_equal_f64x2(r, simde_vld1q_f64(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x2_t a = simde_test_arm_neon_random_f64x2(-1000.0, 1000.0);
    simde_float64x2_t r = simde_vrndq_f64(a);

    simde_test_arm_neon_write_f64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vrndh_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vrnd_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vrnd_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vrnd_f64)

SIMDE_TEST_FUNC_LIST_ENTRY(vrndq_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vrndq_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vrndq_f64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
