#define SIMDE_TEST_ARM_NEON_INSN recpe

#include "test-neon.h"
#include "../../../simde/arm/neon/recpe.h"

static int
test_simde_vrecpes_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a;
    simde_float32 r;
  } test_vec[] = {
    { SIMDE_FLOAT32_C(    -1.18),
      SIMDE_FLOAT32_C(    -0.85) },
    { SIMDE_FLOAT32_C(    -7.49),
      SIMDE_FLOAT32_C(    -0.13) },
    { SIMDE_FLOAT32_C(     4.04),
      SIMDE_FLOAT32_C(     0.25) },
    { SIMDE_FLOAT32_C(     1.26),
      SIMDE_FLOAT32_C(     0.79) },
    { SIMDE_FLOAT32_C(     8.86),
      SIMDE_FLOAT32_C(     0.11) },
    { SIMDE_FLOAT32_C(    -2.49),
      SIMDE_FLOAT32_C(    -0.40) },
    { SIMDE_FLOAT32_C(     2.79),
      SIMDE_FLOAT32_C(     0.36) },
    { SIMDE_FLOAT32_C(    -2.20),
      SIMDE_FLOAT32_C(    -0.46) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32_t a = test_vec[i].a;
    simde_float32_t r = simde_vrecpes_f32(a);

    simde_assert_equal_f32(r, test_vec[i].r, 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    // Keep the numbers small otherwise taking the reciprocal just gives 0.
    simde_float32_t a = simde_test_codegen_random_f32(-10.0f, 10.0f);
    simde_float32_t r = simde_vrecpes_f32(a);

    simde_test_codegen_write_f32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_f32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vrecped_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 a;
    simde_float64 r;
  } test_vec[] = {
    { SIMDE_FLOAT64_C(     3.83),
      SIMDE_FLOAT64_C(     0.26) },
    { SIMDE_FLOAT64_C(     8.43),
      SIMDE_FLOAT64_C(     0.12) },
    { SIMDE_FLOAT64_C(    -8.88),
      SIMDE_FLOAT64_C(    -0.11) },
    { SIMDE_FLOAT64_C(     0.81),
      SIMDE_FLOAT64_C(     1.23) },
    { SIMDE_FLOAT64_C(     7.00),
      SIMDE_FLOAT64_C(     0.14) },
    { SIMDE_FLOAT64_C(     5.50),
      SIMDE_FLOAT64_C(     0.18) },
    { SIMDE_FLOAT64_C(     9.65),
      SIMDE_FLOAT64_C(     0.10) },
    { SIMDE_FLOAT64_C(    -1.78),
      SIMDE_FLOAT64_C(    -0.56) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64_t a = test_vec[i].a;
    simde_float64_t r = simde_vrecped_f64(a);

    simde_assert_equal_f64(r, test_vec[i].r, 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    // Keep the numbers small otherwise taking the reciprocal just gives 0.
    simde_float64_t a = simde_test_codegen_random_f64(-10.0, 10.0);
    simde_float64_t r = simde_vrecped_f64(a);

    simde_test_codegen_write_f64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_f64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

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
test_simde_vrecpe_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64_t a[1];
    simde_float64_t r[1];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(     0.29) },
      { SIMDE_FLOAT64_C(     3.45) } },
    { { SIMDE_FLOAT64_C(    -6.80) },
      { SIMDE_FLOAT64_C(    -0.15) } },
    { { SIMDE_FLOAT64_C(     4.19) },
      { SIMDE_FLOAT64_C(     0.24) } },
    { { SIMDE_FLOAT64_C(    -7.19) },
      { SIMDE_FLOAT64_C(    -0.14) } },
    { { SIMDE_FLOAT64_C(     7.23) },
      { SIMDE_FLOAT64_C(     0.14) } },
    { { SIMDE_FLOAT64_C(     9.23) },
      { SIMDE_FLOAT64_C(     0.11) } },
    { { SIMDE_FLOAT64_C(     8.28) },
      { SIMDE_FLOAT64_C(     0.12) } },
    { { SIMDE_FLOAT64_C(    -5.16) },
      { SIMDE_FLOAT64_C(    -0.19) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x1_t a = simde_vld1_f64(test_vec[i].a);
    simde_float64x1_t r = simde_vrecpe_f64(a);

    simde_test_arm_neon_assert_equal_f64x1(r, simde_vld1_f64(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    // Keep the numbers small otherwise taking the reciprocal just gives 0.
    simde_float64x1_t a = simde_test_arm_neon_random_f64x1(-10.0, 10.0);
    simde_float64x1_t r = simde_vrecpe_f64(a);

    simde_test_arm_neon_write_f64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vrecpeq_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64_t a[2];
    simde_float64_t r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(    -7.14), SIMDE_FLOAT64_C(     8.22) },
      { SIMDE_FLOAT64_C(    -0.14), SIMDE_FLOAT64_C(     0.12) } },
    { { SIMDE_FLOAT64_C(     5.72), SIMDE_FLOAT64_C(     4.54) },
      { SIMDE_FLOAT64_C(     0.17), SIMDE_FLOAT64_C(     0.22) } },
    { { SIMDE_FLOAT64_C(    -8.03), SIMDE_FLOAT64_C(    -1.08) },
      { SIMDE_FLOAT64_C(    -0.12), SIMDE_FLOAT64_C(    -0.93) } },
    { { SIMDE_FLOAT64_C(    -1.87), SIMDE_FLOAT64_C(     9.58) },
      { SIMDE_FLOAT64_C(    -0.54), SIMDE_FLOAT64_C(     0.10) } },
    { { SIMDE_FLOAT64_C(    -5.75), SIMDE_FLOAT64_C(     8.95) },
      { SIMDE_FLOAT64_C(    -0.17), SIMDE_FLOAT64_C(     0.11) } },
    { { SIMDE_FLOAT64_C(    -1.22), SIMDE_FLOAT64_C(     7.75) },
      { SIMDE_FLOAT64_C(    -0.82), SIMDE_FLOAT64_C(     0.13) } },
    { { SIMDE_FLOAT64_C(     3.96), SIMDE_FLOAT64_C(    -9.77) },
      { SIMDE_FLOAT64_C(     0.25), SIMDE_FLOAT64_C(    -0.10) } },
    { { SIMDE_FLOAT64_C(     3.77), SIMDE_FLOAT64_C(    -3.60) },
      { SIMDE_FLOAT64_C(     0.27), SIMDE_FLOAT64_C(    -0.28) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2_t a = simde_vld1q_f64(test_vec[i].a);
    simde_float64x2_t r = simde_vrecpeq_f64(a);

    simde_test_arm_neon_assert_equal_f64x2(r, simde_vld1q_f64(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    // Keep the numbers small otherwise taking the reciprocal just gives 0.
    simde_float64x2_t a = simde_test_arm_neon_random_f64x2(-10.0, 10.0);
    simde_float64x2_t r = simde_vrecpeq_f64(a);

    simde_test_arm_neon_write_f64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
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

static int
test_simde_vrecpe_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[2];
    uint32_t r[2];
  } test_vec[] = {
    { { UINT32_C(3564426969), UINT32_C( 462037507) },
     { UINT32_C(2592079872),           UINT32_MAX } },
   { { UINT32_C(3406220423), UINT32_C(1732561961) },
     { UINT32_C(2701131776),           UINT32_MAX } },
   { { UINT32_C(3184077464), UINT32_C(2948966078) },
     { UINT32_C(2894069760), UINT32_C(3128950784) } },
   { { UINT32_C(1649294201), UINT32_C(4149110557) },
     {           UINT32_MAX, UINT32_C(2222981120) } },
   { { UINT32_C(1103872574), UINT32_C(1818056164) },
     {           UINT32_MAX,           UINT32_MAX } },
   { { UINT32_C(1261921057), UINT32_C(3367140144) },
     {           UINT32_MAX, UINT32_C(2734686208) } },
   { { UINT32_C(1669692325), UINT32_C(2584889889) },
     {           UINT32_MAX, UINT32_C(3565158400) } },
   { { UINT32_C(2734449029), UINT32_C( 110709448) },
     { UINT32_C(3380609024),           UINT32_MAX } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2_t a = simde_vld1_u32(test_vec[i].a);
    simde_uint32x2_t r = simde_vrecpe_u32(a);

    simde_test_arm_neon_assert_equal_u32x2(r, simde_vld1_u32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    // Keep the numbers small otherwise taking the reciprocal just gives 0.
    simde_uint32x2_t a = simde_test_arm_neon_random_u32x2();
    simde_uint32x2_t r = simde_vrecpe_u32(a);

    simde_test_arm_neon_write_u32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vrecpeq_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[4];
    uint32_t r[4];
  } test_vec[] = {
    { { UINT32_C(1460138119), UINT32_C(2503456530), UINT32_C(1265957790), UINT32_C(3090174878) },
      {           UINT32_MAX, UINT32_C(3682598912),           UINT32_MAX, UINT32_C(2986344448) } },
    { { UINT32_C( 620841409), UINT32_C(3775439020), UINT32_C(1866396079), UINT32_C(2739570204) },
      {           UINT32_MAX, UINT32_C(2441084928),           UINT32_MAX, UINT32_C(3363831808) } },
    { { UINT32_C(2298106486), UINT32_C(2820551177), UINT32_C(3438514733), UINT32_C(2810455013) },
      { UINT32_C(4018143232), UINT32_C(3271557120), UINT32_C(2684354560), UINT32_C(3279945728) } },
    { { UINT32_C( 416056684), UINT32_C(3573142565), UINT32_C(3779344325), UINT32_C( 881102526) },
      {           UINT32_MAX, UINT32_C(2583691264), UINT32_C(2441084928),           UINT32_MAX } },
    { { UINT32_C(3938287584), UINT32_C(3734166449), UINT32_C(1403684205), UINT32_C( 351940520) },
      { UINT32_C(2340421632), UINT32_C(2466250752),           UINT32_MAX,           UINT32_MAX } },
    { { UINT32_C(3660433076), UINT32_C(1622025883), UINT32_C( 474149470), UINT32_C(1632683649) },
      { UINT32_C(2516582400),           UINT32_MAX,           UINT32_MAX,           UINT32_MAX } },
    { { UINT32_C(4132113733), UINT32_C(1456856552), UINT32_C( 178880354), UINT32_C(1663017902) },
      { UINT32_C(2231369728),           UINT32_MAX,           UINT32_MAX,           UINT32_MAX } },
    { { UINT32_C(  71126121), UINT32_C(3496340338), UINT32_C(1609344990), UINT32_C(3015720301) },
      {           UINT32_MAX, UINT32_C(2642411520),           UINT32_MAX, UINT32_C(3061841920) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint32x4_t r = simde_vrecpeq_u32(a);

    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    // Keep the numbers small otherwise taking the reciprocal just gives 0.
    simde_uint32x4_t a = simde_test_arm_neon_random_u32x4();
    simde_uint32x4_t r = simde_vrecpeq_u32(a);

    simde_test_arm_neon_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vrecpes_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vrecped_f64)

SIMDE_TEST_FUNC_LIST_ENTRY(vrecpe_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vrecpe_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vrecpeq_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vrecpe_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vrecpeq_u32)

SIMDE_TEST_FUNC_LIST_ENTRY(vrecpeq_f32)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
