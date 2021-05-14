
#define SIMDE_TEST_ARM_NEON_INSN rsqrte

#include "test-neon.h"
#include "../../../simde/arm/neon/rsqrte.h"

static int
test_simde_vrsqrte_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a[2];
    simde_float32 r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(    63.71), SIMDE_FLOAT32_C(    90.61) },
      { SIMDE_FLOAT32_C(     0.13), SIMDE_FLOAT32_C(     0.11) } },
    { { SIMDE_FLOAT32_C(     6.73), SIMDE_FLOAT32_C(     1.48) },
      { SIMDE_FLOAT32_C(     0.39), SIMDE_FLOAT32_C(     0.82) } },
    { { SIMDE_FLOAT32_C(    25.93), SIMDE_FLOAT32_C(     0.58) },
      { SIMDE_FLOAT32_C(     0.20), SIMDE_FLOAT32_C(     1.31) } },
    { { SIMDE_FLOAT32_C(    61.27), SIMDE_FLOAT32_C(    46.52) },
      { SIMDE_FLOAT32_C(     0.13), SIMDE_FLOAT32_C(     0.15) } },
    { { SIMDE_FLOAT32_C(    51.18), SIMDE_FLOAT32_C(    61.62) },
      { SIMDE_FLOAT32_C(     0.14), SIMDE_FLOAT32_C(     0.13) } },
    { { SIMDE_FLOAT32_C(    14.31), SIMDE_FLOAT32_C(    66.58) },
      { SIMDE_FLOAT32_C(     0.26), SIMDE_FLOAT32_C(     0.12) } },
    { { SIMDE_FLOAT32_C(    73.91), SIMDE_FLOAT32_C(    16.73) },
      { SIMDE_FLOAT32_C(     0.12), SIMDE_FLOAT32_C(     0.24) } },
    { { SIMDE_FLOAT32_C(    86.97), SIMDE_FLOAT32_C(    33.51) },
      { SIMDE_FLOAT32_C(     0.11), SIMDE_FLOAT32_C(     0.17) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t a = simde_vld1_f32(test_vec[i].a);
    simde_float32x2_t r = simde_vrsqrte_f32(a);

    simde_test_arm_neon_assert_equal_f32x2(r, simde_vld1_f32(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x2_t a = simde_test_arm_neon_random_f32x2(0.0f, 100.0f);
    simde_float32x2_t r = simde_vrsqrte_f32(a);

    simde_test_arm_neon_write_f32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vrsqrteq_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a[4];
    simde_float32 r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(    54.34), SIMDE_FLOAT32_C(    78.91), SIMDE_FLOAT32_C(    73.82), SIMDE_FLOAT32_C(     9.39) },
      { SIMDE_FLOAT32_C(     0.14), SIMDE_FLOAT32_C(     0.11), SIMDE_FLOAT32_C(     0.12), SIMDE_FLOAT32_C(     0.33) } },
    { { SIMDE_FLOAT32_C(    73.60), SIMDE_FLOAT32_C(    67.42), SIMDE_FLOAT32_C(    10.95), SIMDE_FLOAT32_C(     2.53) },
      { SIMDE_FLOAT32_C(     0.12), SIMDE_FLOAT32_C(     0.12), SIMDE_FLOAT32_C(     0.30), SIMDE_FLOAT32_C(     0.63) } },
    { { SIMDE_FLOAT32_C(    57.12), SIMDE_FLOAT32_C(    47.91), SIMDE_FLOAT32_C(    10.51), SIMDE_FLOAT32_C(    90.53) },
      { SIMDE_FLOAT32_C(     0.13), SIMDE_FLOAT32_C(     0.14), SIMDE_FLOAT32_C(     0.31), SIMDE_FLOAT32_C(     0.11) } },
    { { SIMDE_FLOAT32_C(    74.61), SIMDE_FLOAT32_C(    29.21), SIMDE_FLOAT32_C(    26.44), SIMDE_FLOAT32_C(    38.33) },
      { SIMDE_FLOAT32_C(     0.12), SIMDE_FLOAT32_C(     0.19), SIMDE_FLOAT32_C(     0.19), SIMDE_FLOAT32_C(     0.16) } },
    { { SIMDE_FLOAT32_C(    19.82), SIMDE_FLOAT32_C(    33.17), SIMDE_FLOAT32_C(    39.80), SIMDE_FLOAT32_C(    45.75) },
      { SIMDE_FLOAT32_C(     0.22), SIMDE_FLOAT32_C(     0.17), SIMDE_FLOAT32_C(     0.16), SIMDE_FLOAT32_C(     0.15) } },
    { { SIMDE_FLOAT32_C(    33.74), SIMDE_FLOAT32_C(     1.07), SIMDE_FLOAT32_C(    92.27), SIMDE_FLOAT32_C(    84.92) },
      { SIMDE_FLOAT32_C(     0.17), SIMDE_FLOAT32_C(     0.97), SIMDE_FLOAT32_C(     0.10), SIMDE_FLOAT32_C(     0.11) } },
    { { SIMDE_FLOAT32_C(    62.69), SIMDE_FLOAT32_C(     6.57), SIMDE_FLOAT32_C(    51.50), SIMDE_FLOAT32_C(    36.60) },
      { SIMDE_FLOAT32_C(     0.13), SIMDE_FLOAT32_C(     0.39), SIMDE_FLOAT32_C(     0.14), SIMDE_FLOAT32_C(     0.17) } },
    { { SIMDE_FLOAT32_C(    23.31), SIMDE_FLOAT32_C(    38.48), SIMDE_FLOAT32_C(    70.11), SIMDE_FLOAT32_C(    77.65) },
      { SIMDE_FLOAT32_C(     0.21), SIMDE_FLOAT32_C(     0.16), SIMDE_FLOAT32_C(     0.12), SIMDE_FLOAT32_C(     0.11) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_float32x4_t r = simde_vrsqrteq_f32(a);
    simde_test_arm_neon_assert_equal_f32x4(r, simde_vld1q_f32(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x4_t a = simde_test_arm_neon_random_f32x4(0.0f, 100.0f);
    simde_float32x4_t r = simde_vrsqrteq_f32(a);

    simde_test_arm_neon_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vrsqrte_f32)

SIMDE_TEST_FUNC_LIST_ENTRY(vrsqrteq_f32)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
