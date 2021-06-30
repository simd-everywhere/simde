
#define SIMDE_TEST_ARM_NEON_INSN rsqrte

#include "test-neon.h"
#include "../../../simde/arm/neon/rsqrte.h"

static int
test_simde_vrsqrtes_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a;
    simde_float32 r;
  } test_vec[] = {
    { SIMDE_FLOAT32_C(    33.60),
      SIMDE_FLOAT32_C(     0.17) },
    { SIMDE_FLOAT32_C(    85.84),
      SIMDE_FLOAT32_C(     0.11) },
    { SIMDE_FLOAT32_C(     3.60),
      SIMDE_FLOAT32_C(     0.53) },
    { SIMDE_FLOAT32_C(    82.23),
      SIMDE_FLOAT32_C(     0.11) },
    { SIMDE_FLOAT32_C(    13.21),
      SIMDE_FLOAT32_C(     0.28) },
    { SIMDE_FLOAT32_C(    98.57),
      SIMDE_FLOAT32_C(     0.10) },
    { SIMDE_FLOAT32_C(    20.89),
      SIMDE_FLOAT32_C(     0.22) },
    { SIMDE_FLOAT32_C(    58.72),
      SIMDE_FLOAT32_C(     0.13) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32_t a = test_vec[i].a;
    simde_float32_t r = simde_vrsqrtes_f32(a);

    simde_assert_equal_f32(r, test_vec[i].r, 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32_t a = simde_test_codegen_random_f32(0.0f, 100.0f);
    simde_float32_t r = simde_vrsqrtes_f32(a);

    simde_test_codegen_write_f32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_f32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vrsqrted_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 a;
    simde_float64 r;
  } test_vec[] = {
    { SIMDE_FLOAT64_C(    74.41),
      SIMDE_FLOAT64_C(     0.12) },
    { SIMDE_FLOAT64_C(    17.90),
      SIMDE_FLOAT64_C(     0.24) },
    { SIMDE_FLOAT64_C(     3.86),
      SIMDE_FLOAT64_C(     0.51) },
    { SIMDE_FLOAT64_C(    93.39),
      SIMDE_FLOAT64_C(     0.10) },
    { SIMDE_FLOAT64_C(    27.68),
      SIMDE_FLOAT64_C(     0.19) },
    { SIMDE_FLOAT64_C(    38.04),
      SIMDE_FLOAT64_C(     0.16) },
    { SIMDE_FLOAT64_C(     8.09),
      SIMDE_FLOAT64_C(     0.35) },
    { SIMDE_FLOAT64_C(     2.91),
      SIMDE_FLOAT64_C(     0.59) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64_t a = test_vec[i].a;
    simde_float64_t r = simde_vrsqrted_f64(a);

    simde_assert_equal_f64(r, test_vec[i].r, 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64_t a = simde_test_codegen_random_f64(0.0, 100.0);
    simde_float64_t r = simde_vrsqrted_f64(a);

    simde_test_codegen_write_f64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_f64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

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
test_simde_vrsqrte_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 a[1];
    simde_float64 r[1];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(    45.08) },
      { SIMDE_FLOAT64_C(     0.15) } },
    { { SIMDE_FLOAT64_C(    22.53) },
      { SIMDE_FLOAT64_C(     0.21) } },
    { { SIMDE_FLOAT64_C(    77.74) },
      { SIMDE_FLOAT64_C(     0.11) } },
    { { SIMDE_FLOAT64_C(    86.85) },
      { SIMDE_FLOAT64_C(     0.11) } },
    { { SIMDE_FLOAT64_C(    42.05) },
      { SIMDE_FLOAT64_C(     0.15) } },
    { { SIMDE_FLOAT64_C(    56.86) },
      { SIMDE_FLOAT64_C(     0.13) } },
    { { SIMDE_FLOAT64_C(    29.17) },
      { SIMDE_FLOAT64_C(     0.19) } },
    { { SIMDE_FLOAT64_C(    24.93) },
      { SIMDE_FLOAT64_C(     0.20) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x1_t a = simde_vld1_f64(test_vec[i].a);
    simde_float64x1_t r = simde_vrsqrte_f64(a);

    simde_test_arm_neon_assert_equal_f64x1(r, simde_vld1_f64(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x1_t a = simde_test_arm_neon_random_f64x1(0.0, 100.0);
    simde_float64x1_t r = simde_vrsqrte_f64(a);

    simde_test_arm_neon_write_f64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vrsqrte_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[2];
    uint32_t r[2];
  } test_vec[] = {
    { { UINT32_C( 124792316), UINT32_C( 707972624) },
      {           UINT32_MAX,           UINT32_MAX } },
    { { UINT32_C(2075341289), UINT32_C(3964530840) },
      { UINT32_C(3087007744), UINT32_C(2231369728) } },
    { { UINT32_C(3739131242), UINT32_C(1536833269) },
      { UINT32_C(2306867200), UINT32_C(3590324224) } },
    { { UINT32_C(3047417575), UINT32_C( 907668538) },
      { UINT32_C(2550136832),           UINT32_MAX } },
    { { UINT32_C( 708675865), UINT32_C(1096052568) },
      {           UINT32_MAX, UINT32_C(4253024256) } },
    { { UINT32_C( 951846816), UINT32_C(1629752055) },
      {           UINT32_MAX, UINT32_C(3481272320) } },
    { { UINT32_C(2638217895), UINT32_C( 553179705) },
      { UINT32_C(2734686208),           UINT32_MAX } },
    { { UINT32_C(4208303040), UINT32_C(2704338568) },
      { UINT32_C(2172649472), UINT32_C(2701131776) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2_t a = simde_vld1_u32(test_vec[i].a);
    simde_uint32x2_t r = simde_vrsqrte_u32(a);

    simde_test_arm_neon_assert_equal_u32x2(r, simde_vld1_u32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x2_t a = simde_test_arm_neon_random_u32x2();
    simde_uint32x2_t r = simde_vrsqrte_u32(a);

    simde_test_arm_neon_write_u32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
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

static int
test_simde_vrsqrteq_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[4];
    uint32_t r[4];
  } test_vec[] = {
    { { UINT32_C(2479621035), UINT32_C(3682523218), UINT32_C(1969086320), UINT32_C(3328336721) },
      { UINT32_C(2826960896), UINT32_C(2315255808), UINT32_C(3170893824), UINT32_C(2441084928) } },
    { { UINT32_C(1171993373), UINT32_C( 360332709), UINT32_C( 965093525), UINT32_C(4206131278) },
      { UINT32_C(4110417920),           UINT32_MAX,           UINT32_MAX, UINT32_C(2172649472) } },
    { { UINT32_C(3448603003), UINT32_C(3383233369), UINT32_C( 993920746), UINT32_C(2265096553) },
      { UINT32_C(2399141888), UINT32_C(2424307712),           UINT32_MAX, UINT32_C(2952790016) } },
    { { UINT32_C(2043469268), UINT32_C(2962114074), UINT32_C(3186168943), UINT32_C( 129474188) },
      { UINT32_C(3112173568), UINT32_C(2583691264), UINT32_C(2499805184),           UINT32_MAX } },
    { { UINT32_C(2027176991), UINT32_C( 977435983), UINT32_C(3967123587), UINT32_C(4117985057) },
      { UINT32_C(3128950784),           UINT32_MAX, UINT32_C(2231369728), UINT32_C(2189426688) } },
    { { UINT32_C(1869496148), UINT32_C(4112514182), UINT32_C(2628913168), UINT32_C(3315821222) },
      { UINT32_C(3254779904), UINT32_C(2189426688), UINT32_C(2743074816), UINT32_C(2441084928) } },
    { { UINT32_C(4265506990), UINT32_C(2016968949), UINT32_C( 577023232), UINT32_C(2031605797) },
      { UINT32_C(2155872256), UINT32_C(3137339392),           UINT32_MAX, UINT32_C(3120562176) } },
    { { UINT32_C(2649261591), UINT32_C(2475820930), UINT32_C(3056551184), UINT32_C(1568461743) },
      { UINT32_C(2734686208), UINT32_C(2826960896), UINT32_C(2541748224), UINT32_C(3556769792) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint32x4_t r = simde_vrsqrteq_u32(a);

    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x4_t a = simde_test_arm_neon_random_u32x4();
    simde_uint32x4_t r = simde_vrsqrteq_u32(a);

    simde_test_arm_neon_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vrsqrteq_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 a[2];
    simde_float64 r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(    23.63), SIMDE_FLOAT64_C(    16.02) },
      { SIMDE_FLOAT64_C(     0.21), SIMDE_FLOAT64_C(     0.25) } },
    { { SIMDE_FLOAT64_C(    58.09), SIMDE_FLOAT64_C(    45.27) },
      { SIMDE_FLOAT64_C(     0.13), SIMDE_FLOAT64_C(     0.15) } },
    { { SIMDE_FLOAT64_C(    10.31), SIMDE_FLOAT64_C(    45.18) },
      { SIMDE_FLOAT64_C(     0.31), SIMDE_FLOAT64_C(     0.15) } },
    { { SIMDE_FLOAT64_C(    34.52), SIMDE_FLOAT64_C(    70.06) },
      { SIMDE_FLOAT64_C(     0.17), SIMDE_FLOAT64_C(     0.12) } },
    { { SIMDE_FLOAT64_C(    49.78), SIMDE_FLOAT64_C(    54.92) },
      { SIMDE_FLOAT64_C(     0.14), SIMDE_FLOAT64_C(     0.13) } },
    { { SIMDE_FLOAT64_C(    90.00), SIMDE_FLOAT64_C(    65.66) },
      { SIMDE_FLOAT64_C(     0.11), SIMDE_FLOAT64_C(     0.12) } },
    { { SIMDE_FLOAT64_C(    30.85), SIMDE_FLOAT64_C(    79.17) },
      { SIMDE_FLOAT64_C(     0.18), SIMDE_FLOAT64_C(     0.11) } },
    { { SIMDE_FLOAT64_C(    71.16), SIMDE_FLOAT64_C(    24.47) },
      { SIMDE_FLOAT64_C(     0.12), SIMDE_FLOAT64_C(     0.20) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2_t a = simde_vld1q_f64(test_vec[i].a);
    simde_float64x2_t r = simde_vrsqrteq_f64(a);

    simde_test_arm_neon_assert_equal_f64x2(r, simde_vld1q_f64(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x2_t a = simde_test_arm_neon_random_f64x2(0.0, 100.0);
    simde_float64x2_t r = simde_vrsqrteq_f64(a);

    simde_test_arm_neon_write_f64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vrsqrtes_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vrsqrted_f64)

SIMDE_TEST_FUNC_LIST_ENTRY(vrsqrte_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vrsqrte_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vrsqrte_u32)

SIMDE_TEST_FUNC_LIST_ENTRY(vrsqrteq_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vrsqrteq_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vrsqrteq_f64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
