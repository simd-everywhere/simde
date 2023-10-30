#define SIMDE_TEST_ARM_NEON_INSN minnmv

#include "test-neon.h"
#include "../../../simde/arm/neon/minnmv.h"

static int
test_simde_vminnmv_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16_t a[4];
    simde_float16_t r;
  } test_vec[] = {
    { {  SIMDE_FLOAT16_VALUE(    20.218),  SIMDE_FLOAT16_VALUE(    -6.853),  SIMDE_FLOAT16_VALUE(    -5.794),  SIMDE_FLOAT16_VALUE(     8.347) },
         SIMDE_FLOAT16_VALUE(    -6.853) },
    { {  SIMDE_FLOAT16_VALUE(    -2.093),  SIMDE_FLOAT16_VALUE(    -3.578),  SIMDE_FLOAT16_VALUE(   -25.522),  SIMDE_FLOAT16_VALUE(   -21.689) },
         SIMDE_FLOAT16_VALUE(   -25.522) },
    { {  SIMDE_FLOAT16_VALUE(    13.305),  SIMDE_FLOAT16_VALUE(    15.886),  SIMDE_FLOAT16_VALUE(   -16.955),  SIMDE_FLOAT16_VALUE(    14.481) },
         SIMDE_FLOAT16_VALUE(   -16.955) },
    { {  SIMDE_FLOAT16_VALUE(   -18.484),  SIMDE_FLOAT16_VALUE(    29.793),  SIMDE_FLOAT16_VALUE(    -0.842),  SIMDE_FLOAT16_VALUE(    19.516) },
         SIMDE_FLOAT16_VALUE(   -18.484) },
    { {  SIMDE_FLOAT16_VALUE(   -22.777),  SIMDE_FLOAT16_VALUE(     4.641),  SIMDE_FLOAT16_VALUE(   -20.779),  SIMDE_FLOAT16_VALUE(   -21.506) },
         SIMDE_FLOAT16_VALUE(   -22.777) },
    { {  SIMDE_FLOAT16_VALUE(   -28.388),  SIMDE_FLOAT16_VALUE(   -10.209),  SIMDE_FLOAT16_VALUE(    17.384),  SIMDE_FLOAT16_VALUE(    29.067) },
         SIMDE_FLOAT16_VALUE(   -28.388) },
    { {  SIMDE_FLOAT16_VALUE(    -3.619),  SIMDE_FLOAT16_VALUE(   -13.964),  SIMDE_FLOAT16_VALUE(    10.205),  SIMDE_FLOAT16_VALUE(    26.305) },
         SIMDE_FLOAT16_VALUE(   -13.964) },
    { {  SIMDE_FLOAT16_VALUE(    15.202),  SIMDE_FLOAT16_VALUE(    15.144),  SIMDE_FLOAT16_VALUE(    25.308),  SIMDE_FLOAT16_VALUE(   -28.303) },
         SIMDE_FLOAT16_VALUE(   -28.303) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x4_t a = simde_vld1_f16(test_vec[i].a);
    simde_float16_t r = simde_vminnmv_f16(a);

    simde_assert_equal_f16(r, test_vec[i].r, 1);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16x4_t a = simde_test_arm_neon_random_f16x4(-100.0f, 100.0f);
    simde_float16_t r = simde_vminnmv_f16(a);

    simde_test_arm_neon_write_f16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_f16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vminnmv_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32_t a[2];
    simde_float32_t r;
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   453.38), SIMDE_FLOAT32_C(   453.38) },
      SIMDE_FLOAT32_C(   453.38) },
    { { SIMDE_FLOAT32_C(  -282.45), SIMDE_FLOAT32_C(  -125.43) },
      SIMDE_FLOAT32_C(  -282.45) },
    { { SIMDE_FLOAT32_C(   -15.54), SIMDE_FLOAT32_C(  -221.82) },
      SIMDE_FLOAT32_C(  -221.82) },
    { { SIMDE_FLOAT32_C(  -502.94), SIMDE_FLOAT32_C(  -155.47) },
      SIMDE_FLOAT32_C(  -502.94) },
    { { SIMDE_FLOAT32_C(  -806.84), SIMDE_FLOAT32_C(   615.87) },
      SIMDE_FLOAT32_C(  -806.84) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t a = simde_vld1_f32(test_vec[i].a);
    simde_float32_t r = simde_vminnmv_f32(a);

    simde_assert_equal_f32(r, test_vec[i].r, 1);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x2_t a = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f);
    simde_float32_t r = simde_vminnmv_f32(a);

    simde_test_arm_neon_write_f32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_f32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vminnmvq_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16_t a[8];
    simde_float16_t r;
  } test_vec[] = {
    { {  SIMDE_FLOAT16_VALUE(   -11.968),  SIMDE_FLOAT16_VALUE(     0.700),  SIMDE_FLOAT16_VALUE(     1.342),  SIMDE_FLOAT16_VALUE(     5.319),
         SIMDE_FLOAT16_VALUE(     1.058),  SIMDE_FLOAT16_VALUE(    -3.121),  SIMDE_FLOAT16_VALUE(     9.615),  SIMDE_FLOAT16_VALUE(   -29.989) },
         SIMDE_FLOAT16_VALUE(   -29.989) },
    { {  SIMDE_FLOAT16_VALUE(    18.972),  SIMDE_FLOAT16_VALUE(   -13.189),  SIMDE_FLOAT16_VALUE(   -24.616),  SIMDE_FLOAT16_VALUE(   -11.420),
         SIMDE_FLOAT16_VALUE(    29.006),  SIMDE_FLOAT16_VALUE(    18.310),  SIMDE_FLOAT16_VALUE(    -2.603),  SIMDE_FLOAT16_VALUE(     5.305) },
         SIMDE_FLOAT16_VALUE(   -24.616) },
    { {  SIMDE_FLOAT16_VALUE(    25.793),  SIMDE_FLOAT16_VALUE(   -25.154),  SIMDE_FLOAT16_VALUE(    16.638),  SIMDE_FLOAT16_VALUE(   -16.495),
         SIMDE_FLOAT16_VALUE(   -26.285),  SIMDE_FLOAT16_VALUE(     8.955),  SIMDE_FLOAT16_VALUE(   -23.971),  SIMDE_FLOAT16_VALUE(   -28.845) },
         SIMDE_FLOAT16_VALUE(   -28.845) },
    { {  SIMDE_FLOAT16_VALUE(     9.945),  SIMDE_FLOAT16_VALUE(     9.819),  SIMDE_FLOAT16_VALUE(     7.833),  SIMDE_FLOAT16_VALUE(   -12.584),
         SIMDE_FLOAT16_VALUE(     2.684),  SIMDE_FLOAT16_VALUE(   -25.996),  SIMDE_FLOAT16_VALUE(   -12.605),  SIMDE_FLOAT16_VALUE(    18.119) },
         SIMDE_FLOAT16_VALUE(   -25.996) },
    { {  SIMDE_FLOAT16_VALUE(    -7.772),  SIMDE_FLOAT16_VALUE(    22.902),  SIMDE_FLOAT16_VALUE(    26.436),  SIMDE_FLOAT16_VALUE(   -20.216),
         SIMDE_FLOAT16_VALUE(    16.707),  SIMDE_FLOAT16_VALUE(     5.188),  SIMDE_FLOAT16_VALUE(    -9.754),  SIMDE_FLOAT16_VALUE(   -28.714) },
         SIMDE_FLOAT16_VALUE(   -28.714) },
    { {  SIMDE_FLOAT16_VALUE(   -19.900),  SIMDE_FLOAT16_VALUE(     6.812),  SIMDE_FLOAT16_VALUE(    18.439),  SIMDE_FLOAT16_VALUE(    23.239),
         SIMDE_FLOAT16_VALUE(   -21.049),  SIMDE_FLOAT16_VALUE(   -21.265),  SIMDE_FLOAT16_VALUE(     7.079),  SIMDE_FLOAT16_VALUE(    29.200) },
         SIMDE_FLOAT16_VALUE(   -21.265) },
    { {  SIMDE_FLOAT16_VALUE(    19.055),  SIMDE_FLOAT16_VALUE(   -11.939),  SIMDE_FLOAT16_VALUE(    22.429),  SIMDE_FLOAT16_VALUE(    27.392),
         SIMDE_FLOAT16_VALUE(     0.849),  SIMDE_FLOAT16_VALUE(     8.276),  SIMDE_FLOAT16_VALUE(    15.737),  SIMDE_FLOAT16_VALUE(     2.775) },
         SIMDE_FLOAT16_VALUE(   -11.939) },
    { {  SIMDE_FLOAT16_VALUE(   -25.103),  SIMDE_FLOAT16_VALUE(    -1.612),  SIMDE_FLOAT16_VALUE(   -16.030),  SIMDE_FLOAT16_VALUE(   -16.356),
         SIMDE_FLOAT16_VALUE(    15.013),  SIMDE_FLOAT16_VALUE(   -18.179),  SIMDE_FLOAT16_VALUE(    11.449),  SIMDE_FLOAT16_VALUE(    -3.686) },
         SIMDE_FLOAT16_VALUE(   -25.103) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x8_t a = simde_vld1q_f16(test_vec[i].a);
    simde_float16_t r = simde_vminnmvq_f16(a);

    simde_assert_equal_f16(r, test_vec[i].r, 1);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16x8_t a = simde_test_arm_neon_random_f16x8(-100.0f, 100.0f);
    simde_float16_t r = simde_vminnmvq_f16(a);

    simde_test_arm_neon_write_f16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_f16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vminnmvq_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32_t a[4];
    simde_float32_t r;
  } test_vec[] = {
    { {  SIMDE_FLOAT32_C(   947.343), -SIMDE_FLOAT32_C(   492.866),  SIMDE_FLOAT32_C(   657.629), -SIMDE_FLOAT32_C(   369.464) },
        -SIMDE_FLOAT32_C(   492.866) },
    { { -SIMDE_FLOAT32_C(   607.062),  SIMDE_FLOAT32_C(   762.490), -SIMDE_FLOAT32_C(   503.820),  SIMDE_FLOAT32_C(   757.954) },
        -SIMDE_FLOAT32_C(   607.062) },
    { {  SIMDE_FLOAT32_C(   504.835), -SIMDE_FLOAT32_C(   244.010),  SIMDE_FLOAT32_C(    80.655),  SIMDE_FLOAT32_C(    75.272) },
        -SIMDE_FLOAT32_C(   244.010) },
    { {  SIMDE_FLOAT32_C(   781.694), -SIMDE_FLOAT32_C(   539.025),  SIMDE_FLOAT32_C(   704.302), -SIMDE_FLOAT32_C(   260.335) },
        -SIMDE_FLOAT32_C(   539.025) },
    { {  SIMDE_FLOAT32_C(   402.321),  SIMDE_FLOAT32_C(   437.528),  SIMDE_FLOAT32_C(   797.358),  SIMDE_FLOAT32_C(   905.556) },
         SIMDE_FLOAT32_C(   402.321) },
    { { -SIMDE_FLOAT32_C(   169.841),  SIMDE_FLOAT32_C(   153.516), -SIMDE_FLOAT32_C(   589.051),  SIMDE_FLOAT32_C(    82.098) },
        -SIMDE_FLOAT32_C(   589.051) },
    { { -SIMDE_FLOAT32_C(   547.491), -SIMDE_FLOAT32_C(   621.393),  SIMDE_FLOAT32_C(   732.052), -SIMDE_FLOAT32_C(   116.706) },
        -SIMDE_FLOAT32_C(   621.393) },
    { { -SIMDE_FLOAT32_C(   511.376),  SIMDE_FLOAT32_C(   429.828),  SIMDE_FLOAT32_C(   694.590), -SIMDE_FLOAT32_C(   183.004) },
        -SIMDE_FLOAT32_C(   511.376) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_float32_t r = simde_vminnmvq_f32(a);

    simde_assert_equal_f32(r, test_vec[i].r, 1);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x4_t a = simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f);
    simde_float32_t r = simde_vminnmvq_f32(a);

    simde_test_arm_neon_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_f32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vminnmvq_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64_t a[2];
    simde_float64_t r;
  } test_vec[] = {
    { {  SIMDE_FLOAT64_C(   901.508), -SIMDE_FLOAT64_C(   897.632) },
        -SIMDE_FLOAT64_C(   897.632) },
    { {  SIMDE_FLOAT64_C(   404.184),  SIMDE_FLOAT64_C(   271.741) },
         SIMDE_FLOAT64_C(   271.741) },
    { {  SIMDE_FLOAT64_C(    10.848),  SIMDE_FLOAT64_C(   877.595) },
         SIMDE_FLOAT64_C(    10.848) },
    { { -SIMDE_FLOAT64_C(   253.723), -SIMDE_FLOAT64_C(   399.728) },
        -SIMDE_FLOAT64_C(   399.728) },
    { { -SIMDE_FLOAT64_C(    45.876), -SIMDE_FLOAT64_C(   859.553) },
        -SIMDE_FLOAT64_C(   859.553) },
    { { -SIMDE_FLOAT64_C(   676.066),  SIMDE_FLOAT64_C(   259.907) },
        -SIMDE_FLOAT64_C(   676.066) },
    { { -SIMDE_FLOAT64_C(   677.086), -SIMDE_FLOAT64_C(   656.352) },
        -SIMDE_FLOAT64_C(   677.086) },
    { { -SIMDE_FLOAT64_C(   372.201), -SIMDE_FLOAT64_C(   499.493) },
        -SIMDE_FLOAT64_C(   499.493) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2_t a = simde_vld1q_f64(test_vec[i].a);
    simde_float64_t r = simde_vminnmvq_f64(a);

    simde_assert_equal_f64(r, test_vec[i].r, 1);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x2_t a = simde_test_arm_neon_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde_float64_t r = simde_vminnmvq_f64(a);

    simde_test_arm_neon_write_f64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_f64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vminnmv_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vminnmv_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vminnmvq_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vminnmvq_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vminnmvq_f64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
