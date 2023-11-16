#define SIMDE_TEST_ARM_NEON_INSN rnd32z

#include "test-neon.h"
#include "../../../simde/arm/neon/rnd32z.h"

static int
test_simde_vrnd32z_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a[2];
    simde_float32 r[2];
  } test_vec[] = {
    #if !defined(SIMDE_FAST_NANS)
    { {            SIMDE_MATH_NANF,           -SIMDE_MATH_NANF },
      {  SIMDE_FLOAT32_C(-2147483648.000),  SIMDE_FLOAT32_C(-2147483648.000) } },
    #endif
    { { -SIMDE_FLOAT32_C(   850.727),  SIMDE_FLOAT32_C(   447.055) },
      { -SIMDE_FLOAT32_C(   850.000),  SIMDE_FLOAT32_C(   447.000) } },
    { { -SIMDE_FLOAT32_C(   764.631),  SIMDE_FLOAT32_C(   221.957) },
      { -SIMDE_FLOAT32_C(   764.000),  SIMDE_FLOAT32_C(   221.000) } },
    { {  SIMDE_FLOAT32_C(    94.435), -SIMDE_FLOAT32_C(   613.213) },
      {  SIMDE_FLOAT32_C(    94.000), -SIMDE_FLOAT32_C(   613.000) } },
    { {  SIMDE_FLOAT32_C(   765.335), -SIMDE_FLOAT32_C(   698.137) },
      {  SIMDE_FLOAT32_C(   765.000), -SIMDE_FLOAT32_C(   698.000) } },
    { { -SIMDE_FLOAT32_C(   328.747), -SIMDE_FLOAT32_C(   576.773) },
      { -SIMDE_FLOAT32_C(   328.000), -SIMDE_FLOAT32_C(   576.000) } },
    { {  SIMDE_FLOAT32_C(   634.583), -SIMDE_FLOAT32_C(   435.299) },
      {  SIMDE_FLOAT32_C(   634.000), -SIMDE_FLOAT32_C(   435.000) } },
    { {  SIMDE_FLOAT32_C(   689.485), -SIMDE_FLOAT32_C(   125.431) },
      {  SIMDE_FLOAT32_C(   689.000), -SIMDE_FLOAT32_C(   125.000) } },
    { {  SIMDE_FLOAT32_C(   998.872), -SIMDE_FLOAT32_C(   419.873) },
      {  SIMDE_FLOAT32_C(   998.000), -SIMDE_FLOAT32_C(   419.000) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t a = simde_vld1_f32(test_vec[i].a);
    simde_float32x2_t r = simde_vrnd32z_f32(a);

    simde_test_arm_neon_assert_equal_f32x2(r, simde_vld1_f32(test_vec[i].r), 1);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x2_t a = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f);
    simde_float32x2_t r = simde_vrnd32z_f32(a);

    simde_test_arm_neon_write_f32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vrnd32z_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 a[1];
    simde_float64 r[1];
  } test_vec[] = {
    #if !defined(SIMDE_FAST_NANS)
    { {             SIMDE_MATH_NAN },
      {  SIMDE_FLOAT64_C(-2147483648.000) } },
    { {            -SIMDE_MATH_NAN },
      {  SIMDE_FLOAT64_C(-2147483648.000) } },
    #endif
    { {  SIMDE_FLOAT64_C( 27018.883) },
      {  SIMDE_FLOAT64_C( 27018.000) } },
    { { -SIMDE_FLOAT64_C( 44767.594) },
      { -SIMDE_FLOAT64_C( 44767.000) } },
    { {  SIMDE_FLOAT64_C( 75924.641) },
      {  SIMDE_FLOAT64_C( 75924.000) } },
    { { -SIMDE_FLOAT64_C( 83934.977) },
      { -SIMDE_FLOAT64_C( 83934.000) } },
    { { -SIMDE_FLOAT64_C( 16411.211) },
      { -SIMDE_FLOAT64_C( 16411.000) } },
    { {  SIMDE_FLOAT64_C( 50540.750) },
      {  SIMDE_FLOAT64_C( 50540.000) } },
    { {  SIMDE_FLOAT64_C( 76206.297) },
      {  SIMDE_FLOAT64_C( 76206.000) } },
    { { -SIMDE_FLOAT64_C( 45957.027) },
      { -SIMDE_FLOAT64_C( 45957.000) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x1_t a = simde_vld1_f64(test_vec[i].a);
    simde_float64x1_t r = simde_vrnd32z_f64(a);

    simde_test_arm_neon_assert_equal_f64x1(r, simde_vld1_f64(test_vec[i].r), 1);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x1_t a = simde_test_arm_neon_random_f64x1(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde_float64x1_t r = simde_vrnd32z_f64(a);

    simde_test_arm_neon_write_f64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vrnd32zq_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a[4];
    simde_float32 r[4];
  } test_vec[] = {
    #if !defined(SIMDE_FAST_NANS)
    { {            SIMDE_MATH_INFINITYF,          -SIMDE_MATH_INFINITYF,            SIMDE_MATH_NANF,           -SIMDE_MATH_NANF },
      {  SIMDE_FLOAT32_C(-2147483648.000), SIMDE_FLOAT32_C(-2147483648.000), SIMDE_FLOAT32_C(-2147483648.000), SIMDE_FLOAT32_C(-2147483648.000) } },
    { {  SIMDE_FLOAT32_C( 340282346638528859811704183484516925440.000), -SIMDE_FLOAT32_C(  35.482),  SIMDE_FLOAT32_C( 836.224),  SIMDE_FLOAT32_C(   7.087) },
      {  SIMDE_FLOAT32_C(-2147483648.000), -SIMDE_FLOAT32_C(  35.000),  SIMDE_FLOAT32_C( 836.000),  SIMDE_FLOAT32_C(   7.000) } },
    #endif
    { {  SIMDE_FLOAT32_C(   315.615), -SIMDE_FLOAT32_C(   631.025), -SIMDE_FLOAT32_C(   386.125),  SIMDE_FLOAT32_C(     5.255) },
      {  SIMDE_FLOAT32_C(   315.000), -SIMDE_FLOAT32_C(   631.000), -SIMDE_FLOAT32_C(   386.000),  SIMDE_FLOAT32_C(     5.000) } },
    { {  SIMDE_FLOAT32_C(   429.743),  SIMDE_FLOAT32_C(   945.516),  SIMDE_FLOAT32_C(   546.519),  SIMDE_FLOAT32_C(   121.416) },
      {  SIMDE_FLOAT32_C(   429.000),  SIMDE_FLOAT32_C(   945.000),  SIMDE_FLOAT32_C(   546.000),  SIMDE_FLOAT32_C(   121.000) } },
    { { -SIMDE_FLOAT32_C(   118.331),  SIMDE_FLOAT32_C(   127.397), -SIMDE_FLOAT32_C(   862.398),  SIMDE_FLOAT32_C(   923.627) },
      { -SIMDE_FLOAT32_C(   118.000),  SIMDE_FLOAT32_C(   127.000), -SIMDE_FLOAT32_C(   862.000),  SIMDE_FLOAT32_C(   923.000) } },
    { { -SIMDE_FLOAT32_C(    16.593), -SIMDE_FLOAT32_C(   173.744), -SIMDE_FLOAT32_C(   658.086),  SIMDE_FLOAT32_C(   597.515) },
      { -SIMDE_FLOAT32_C(    16.000), -SIMDE_FLOAT32_C(   173.000), -SIMDE_FLOAT32_C(   658.000),  SIMDE_FLOAT32_C(   597.000) } },
    { { -SIMDE_FLOAT32_C(   645.023),  SIMDE_FLOAT32_C(   268.793),  SIMDE_FLOAT32_C(   739.836), -SIMDE_FLOAT32_C(   823.731) },
      { -SIMDE_FLOAT32_C(   645.000),  SIMDE_FLOAT32_C(   268.000),  SIMDE_FLOAT32_C(   739.000), -SIMDE_FLOAT32_C(   823.000) } },
    { {  SIMDE_FLOAT32_C(   877.731), -SIMDE_FLOAT32_C(   916.856),  SIMDE_FLOAT32_C(   602.785), -SIMDE_FLOAT32_C(     2.260) },
      {  SIMDE_FLOAT32_C(   877.000), -SIMDE_FLOAT32_C(   916.000),  SIMDE_FLOAT32_C(   602.000), -SIMDE_FLOAT32_C(     2.000) } },
    { {  SIMDE_FLOAT32_C(   798.556), -SIMDE_FLOAT32_C(   339.945), -SIMDE_FLOAT32_C(   257.445),  SIMDE_FLOAT32_C(   234.567) },
      {  SIMDE_FLOAT32_C(   798.000), -SIMDE_FLOAT32_C(   339.000), -SIMDE_FLOAT32_C(   257.000),  SIMDE_FLOAT32_C(   234.000) } },
    { { -SIMDE_FLOAT32_C(   166.583),  SIMDE_FLOAT32_C(    49.182),  SIMDE_FLOAT32_C(   490.178),  SIMDE_FLOAT32_C(   671.715) },
      { -SIMDE_FLOAT32_C(   166.000),  SIMDE_FLOAT32_C(    49.000),  SIMDE_FLOAT32_C(   490.000),  SIMDE_FLOAT32_C(   671.000) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_float32x4_t r = simde_vrnd32zq_f32(a);
    simde_test_arm_neon_assert_equal_f32x4(r, simde_vld1q_f32(test_vec[i].r), 1);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x4_t a = simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f);
    simde_float32x4_t r = simde_vrnd32zq_f32(a);

    simde_test_arm_neon_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vrnd32zq_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 a[2];
    simde_float64 r[2];
  } test_vec[] = {
    #if !defined(SIMDE_FAST_NANS)
    { {            SIMDE_MATH_INFINITY,           -SIMDE_MATH_NAN },
      {  SIMDE_FLOAT64_C(-2147483648.000),  SIMDE_FLOAT64_C(-2147483648.000) } },
    { {           -SIMDE_MATH_INFINITY,            SIMDE_MATH_NAN },
      {  SIMDE_FLOAT64_C(-2147483648.000),  SIMDE_FLOAT64_C(-2147483648.000) } },
    #endif
    { {  SIMDE_FLOAT64_C( 26233.062),  SIMDE_FLOAT64_C( 79444.672) },
      {  SIMDE_FLOAT64_C( 26233.000),  SIMDE_FLOAT64_C( 79444.000) } },
    { {  SIMDE_FLOAT64_C( 74475.266), -SIMDE_FLOAT64_C(  2055.633) },
      {  SIMDE_FLOAT64_C( 74475.000), -SIMDE_FLOAT64_C(  2055.000) } },
    { {  SIMDE_FLOAT64_C( 22662.508),  SIMDE_FLOAT64_C( 79471.922) },
      {  SIMDE_FLOAT64_C( 22662.000),  SIMDE_FLOAT64_C( 79471.000) } },
    { {  SIMDE_FLOAT64_C(  5649.922), -SIMDE_FLOAT64_C( 38132.812) },
      {  SIMDE_FLOAT64_C(  5649.000), -SIMDE_FLOAT64_C( 38132.000) } },
    { { -SIMDE_FLOAT64_C( 95776.891), -SIMDE_FLOAT64_C(  3680.125) },
      { -SIMDE_FLOAT64_C( 95776.000), -SIMDE_FLOAT64_C(  3680.000) } },
    { { -SIMDE_FLOAT64_C( 90119.031), -SIMDE_FLOAT64_C( 90929.344) },
      { -SIMDE_FLOAT64_C( 90119.000), -SIMDE_FLOAT64_C( 90929.000) } },
    { {  SIMDE_FLOAT64_C( 72943.641),  SIMDE_FLOAT64_C( 54295.453) },
      {  SIMDE_FLOAT64_C( 72943.000),  SIMDE_FLOAT64_C( 54295.000) } },
    { { -SIMDE_FLOAT64_C( 50009.988),  SIMDE_FLOAT64_C( 57488.578) },
      { -SIMDE_FLOAT64_C( 50009.000),  SIMDE_FLOAT64_C( 57488.000) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2_t a = simde_vld1q_f64(test_vec[i].a);
    simde_float64x2_t r = simde_vrnd32zq_f64(a);

    simde_test_arm_neon_assert_equal_f64x2(r, simde_vld1q_f64(test_vec[i].r), 1);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x2_t a = simde_test_arm_neon_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde_float64x2_t r = simde_vrnd32zq_f64(a);

    simde_test_arm_neon_write_f64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vrnd32z_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vrnd32z_f64)

SIMDE_TEST_FUNC_LIST_ENTRY(vrnd32zq_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vrnd32zq_f64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
