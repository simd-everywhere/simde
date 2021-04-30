#define SIMDE_TEST_ARM_NEON_INSN recpe

#include "test-neon.h"
#include "../../../simde/arm/neon/recpe.h"

static int
test_simde_vrecpe_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a[2];
    simde_float32 r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(    -3.61), SIMDE_FLOAT32_C(    -8.68) },
      { SIMDE_FLOAT32_C(    -0.28), SIMDE_FLOAT32_C(    -0.12) } },
    { { SIMDE_FLOAT32_C(    -6.51), SIMDE_FLOAT32_C(    -7.63) },
      { SIMDE_FLOAT32_C(    -0.15), SIMDE_FLOAT32_C(    -0.13) } },
    { { SIMDE_FLOAT32_C(    -2.80), SIMDE_FLOAT32_C(    -7.27) },
      { SIMDE_FLOAT32_C(    -0.36), SIMDE_FLOAT32_C(    -0.14) } },
    { { SIMDE_FLOAT32_C(    -6.49), SIMDE_FLOAT32_C(    -7.56) },
      { SIMDE_FLOAT32_C(    -0.15), SIMDE_FLOAT32_C(    -0.13) } },
    { { SIMDE_FLOAT32_C(    -5.41), SIMDE_FLOAT32_C(    -0.72) },
      { SIMDE_FLOAT32_C(    -0.18), SIMDE_FLOAT32_C(    -1.39) } },
    { { SIMDE_FLOAT32_C(     8.89), SIMDE_FLOAT32_C(     2.37) },
      { SIMDE_FLOAT32_C(     0.11), SIMDE_FLOAT32_C(     0.42) } },
    { { SIMDE_FLOAT32_C(    -6.54), SIMDE_FLOAT32_C(     4.78) },
      { SIMDE_FLOAT32_C(    -0.15), SIMDE_FLOAT32_C(     0.21) } },
    { { SIMDE_FLOAT32_C(     7.48), SIMDE_FLOAT32_C(     5.64) },
      { SIMDE_FLOAT32_C(     0.13), SIMDE_FLOAT32_C(     0.18) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t a = simde_vld1_f32(test_vec[i].a);
    simde_float32x2_t r = simde_vrecpe_f32(a);

    simde_test_arm_neon_assert_equal_f32x2(r, simde_vld1_f32(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    // Keep the numbers small otherwise taking the reciprocal just gives 0.
    simde_float32x2_t a = simde_test_arm_neon_random_f32x2(-10.0f, 10.0f);
    simde_float32x2_t r = simde_vrecpe_f32(a);

    simde_test_arm_neon_write_f32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vrecpeq_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a[4];
    simde_float32 r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(    -9.52), SIMDE_FLOAT32_C(     2.49), SIMDE_FLOAT32_C(     4.41), SIMDE_FLOAT32_C(     9.23) },
      { SIMDE_FLOAT32_C(    -0.10), SIMDE_FLOAT32_C(     0.40), SIMDE_FLOAT32_C(     0.23), SIMDE_FLOAT32_C(     0.11) } },
    { { SIMDE_FLOAT32_C(    -5.40), SIMDE_FLOAT32_C(    -6.01), SIMDE_FLOAT32_C(     4.48), SIMDE_FLOAT32_C(    -0.45) },
      { SIMDE_FLOAT32_C(    -0.19), SIMDE_FLOAT32_C(    -0.17), SIMDE_FLOAT32_C(     0.22), SIMDE_FLOAT32_C(    -2.23) } },
    { { SIMDE_FLOAT32_C(    -4.27), SIMDE_FLOAT32_C(    -5.87), SIMDE_FLOAT32_C(     4.11), SIMDE_FLOAT32_C(     0.21) },
      { SIMDE_FLOAT32_C(    -0.23), SIMDE_FLOAT32_C(    -0.17), SIMDE_FLOAT32_C(     0.24), SIMDE_FLOAT32_C(     4.75) } },
    { { SIMDE_FLOAT32_C(     6.69), SIMDE_FLOAT32_C(     7.78), SIMDE_FLOAT32_C(     8.38), SIMDE_FLOAT32_C(    -6.92) },
      { SIMDE_FLOAT32_C(     0.15), SIMDE_FLOAT32_C(     0.13), SIMDE_FLOAT32_C(     0.12), SIMDE_FLOAT32_C(    -0.14) } },
    { { SIMDE_FLOAT32_C(     9.10), SIMDE_FLOAT32_C(    -8.13), SIMDE_FLOAT32_C(    -4.56), SIMDE_FLOAT32_C(    -3.69) },
      { SIMDE_FLOAT32_C(     0.11), SIMDE_FLOAT32_C(    -0.12), SIMDE_FLOAT32_C(    -0.22), SIMDE_FLOAT32_C(    -0.27) } },
    { { SIMDE_FLOAT32_C(    -5.40), SIMDE_FLOAT32_C(    -1.04), SIMDE_FLOAT32_C(    -1.25), SIMDE_FLOAT32_C(    -0.81) },
      { SIMDE_FLOAT32_C(    -0.19), SIMDE_FLOAT32_C(    -0.96), SIMDE_FLOAT32_C(    -0.80), SIMDE_FLOAT32_C(    -1.23) } },
    { { SIMDE_FLOAT32_C(     8.23), SIMDE_FLOAT32_C(    -2.36), SIMDE_FLOAT32_C(    -8.44), SIMDE_FLOAT32_C(    -8.31) },
      { SIMDE_FLOAT32_C(     0.12), SIMDE_FLOAT32_C(    -0.42), SIMDE_FLOAT32_C(    -0.12), SIMDE_FLOAT32_C(    -0.12) } },
    { { SIMDE_FLOAT32_C(    -7.58), SIMDE_FLOAT32_C(     9.03), SIMDE_FLOAT32_C(     7.33), SIMDE_FLOAT32_C(    -7.10) },
      { SIMDE_FLOAT32_C(    -0.13), SIMDE_FLOAT32_C(     0.11), SIMDE_FLOAT32_C(     0.14), SIMDE_FLOAT32_C(    -0.14) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_float32x4_t r = simde_vrecpeq_f32(a);
    simde_test_arm_neon_assert_equal_f32x4(r, simde_vld1q_f32(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    // Keep the numbers small otherwise taking the reciprocal just gives 0.
    simde_float32x4_t a = simde_test_arm_neon_random_f32x4(-10.0f, 10.0f);
    simde_float32x4_t r = simde_vrecpeq_f32(a);

    simde_test_arm_neon_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vrecpe_f32)

SIMDE_TEST_FUNC_LIST_ENTRY(vrecpeq_f32)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
