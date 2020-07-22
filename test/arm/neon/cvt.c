#define SIMDE_TEST_ARM_NEON_INSN cvt

#include "test-neon.h"
#include "../../../simde/arm/neon/cvt.h"

static int
test_simde_vcvts_s32_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a;
    int32_t r;
  } test_vec[] = {
    { SIMDE_FLOAT32_C(   550.19),
       INT32_C(         550) },
    { SIMDE_FLOAT32_C(   -14.71),
      -INT32_C(          14) },
    { SIMDE_FLOAT32_C(   735.91),
       INT32_C(         735) },
    { SIMDE_FLOAT32_C(   355.60),
       INT32_C(         355) },
    { SIMDE_FLOAT32_C(  -850.41),
      -INT32_C(         850) },
    { SIMDE_FLOAT32_C(  -934.68),
      -INT32_C(         934) },
    { SIMDE_FLOAT32_C(  -125.28),
      -INT32_C(         125) },
    { SIMDE_FLOAT32_C(   784.80),
       INT32_C(         784) },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32 a = test_vec[i].a;
    int32_t r = simde_vcvts_s32_f32(a);

    simde_assert_equal_i32(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32 a = simde_test_codegen_random_f32(-1000.0, 1000.0);
    int32_t r = simde_vcvts_s32_f32(a);

    simde_test_codegen_write_f32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvtd_s64_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 a;
    int64_t r;
  } test_vec[] = {
    { SIMDE_FLOAT64_C(  -881.66),
      -INT64_C(                 881) },
    { SIMDE_FLOAT64_C(  -469.33),
      -INT64_C(                 469) },
    { SIMDE_FLOAT64_C(   808.92),
       INT64_C(                 808) },
    { SIMDE_FLOAT64_C(   567.01),
       INT64_C(                 567) },
    { SIMDE_FLOAT64_C(  -252.92),
      -INT64_C(                 252) },
    { SIMDE_FLOAT64_C(   379.60),
       INT64_C(                 379) },
    { SIMDE_FLOAT64_C(  -471.75),
      -INT64_C(                 471) },
    { SIMDE_FLOAT64_C(   774.04),
       INT64_C(                 774) },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64 a = test_vec[i].a;
    int64_t r = simde_vcvtd_s64_f64(a);

    simde_assert_equal_i64(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64 a = simde_test_codegen_random_f64(-1000.0, 1000.0);
    int64_t r = simde_vcvtd_s64_f64(a);

    simde_test_codegen_write_f64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}


static int
test_simde_vcvts_u32_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a;
    uint32_t r;
  } test_vec[] = {
    { SIMDE_FLOAT32_C(   843.42),
      UINT32_C(       843) },
    { SIMDE_FLOAT32_C(   336.45),
      UINT32_C(       336) },
    { SIMDE_FLOAT32_C(  -150.13),
      UINT32_C(         0) },
    { SIMDE_FLOAT32_C(   222.99),
      UINT32_C(       222) },
    { SIMDE_FLOAT32_C(  -200.28),
      UINT32_C(         0) },
    { SIMDE_FLOAT32_C(   509.93),
      UINT32_C(       509) },
    { SIMDE_FLOAT32_C(   630.54),
      UINT32_C(       630) },
    { SIMDE_FLOAT32_C(   781.84),
      UINT32_C(       781) },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32 a = test_vec[i].a;
    uint32_t r = simde_vcvts_u32_f32(a);
    simde_assert_equal_u32(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32 a = simde_test_codegen_random_f32(-1000.0, 1000.0);
    uint32_t r = simde_vcvts_u32_f32(a);

    simde_test_codegen_write_f32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvtd_u64_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 a;
    uint64_t r;
  } test_vec[] = {
    { SIMDE_FLOAT64_C(  -497.11),
      UINT64_C(                   0) },
    { SIMDE_FLOAT64_C(  -710.38),
      UINT64_C(                   0) },
    { SIMDE_FLOAT64_C(  -292.39),
      UINT64_C(                   0) },
    { SIMDE_FLOAT64_C(  -747.52),
      UINT64_C(                   0) },
    { SIMDE_FLOAT64_C(  -697.16),
      UINT64_C(                   0) },
    { SIMDE_FLOAT64_C(   134.76),
      UINT64_C(                 134) },
    { SIMDE_FLOAT64_C(   291.75),
      UINT64_C(                 291) },
    { SIMDE_FLOAT64_C(  -298.90),
      UINT64_C(                   0) },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64 a = test_vec[i].a;
    uint64_t r = simde_vcvtd_u64_f64(a);
    simde_assert_equal_u64(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64 a = simde_test_codegen_random_f64(-1000.0, 1000.0);
    uint64_t r = simde_vcvtd_u64_f64(a);

    simde_test_codegen_write_f64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvt_s32_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a[2];
    int32_t r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   396.15), SIMDE_FLOAT32_C(  -246.90) },
      {  INT32_C(         396), -INT32_C(         246) } },
    { { SIMDE_FLOAT32_C(   241.51), SIMDE_FLOAT32_C(   602.56) },
      {  INT32_C(         241),  INT32_C(         602) } },
    { { SIMDE_FLOAT32_C(  -106.85), SIMDE_FLOAT32_C(  -566.67) },
      { -INT32_C(         106), -INT32_C(         566) } },
    { { SIMDE_FLOAT32_C(   463.44), SIMDE_FLOAT32_C(   539.86) },
      {  INT32_C(         463),  INT32_C(         539) } },
    { { SIMDE_FLOAT32_C(  -550.41), SIMDE_FLOAT32_C(   982.91) },
      { -INT32_C(         550),  INT32_C(         982) } },
    { { SIMDE_FLOAT32_C(   499.92), SIMDE_FLOAT32_C(  -727.55) },
      {  INT32_C(         499), -INT32_C(         727) } },
    { { SIMDE_FLOAT32_C(  -713.41), SIMDE_FLOAT32_C(   713.10) },
      { -INT32_C(         713),  INT32_C(         713) } },
    { { SIMDE_FLOAT32_C(  -998.69), SIMDE_FLOAT32_C(  -409.99) },
      { -INT32_C(         998), -INT32_C(         409) } },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t a = simde_vld1_f32(test_vec[i].a);
    simde_int32x2_t r = simde_vcvt_s32_f32(a);

    simde_test_arm_neon_assert_equal_i32x2(r, simde_vld1_s32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x2_t a = simde_test_arm_neon_random_f32x2(-1000.0, 1000.0);
    simde_int32x2_t r = simde_vcvt_s32_f32(a);

    simde_test_arm_neon_write_f32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvt_s64_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 a[1];
    int64_t r[1];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(  -824.03) },
      { -INT64_C(                 824) } },
    { { SIMDE_FLOAT64_C(  -841.94) },
      { -INT64_C(                 841) } },
    { { SIMDE_FLOAT64_C(  -786.92) },
      { -INT64_C(                 786) } },
    { { SIMDE_FLOAT64_C(     5.30) },
      {  INT64_C(                   5) } },
    { { SIMDE_FLOAT64_C(   -36.80) },
      { -INT64_C(                  36) } },
    { { SIMDE_FLOAT64_C(   375.47) },
      {  INT64_C(                 375) } },
    { { SIMDE_FLOAT64_C(   -12.40) },
      { -INT64_C(                  12) } },
    { { SIMDE_FLOAT64_C(    35.70) },
      {  INT64_C(                  35) } },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x1_t a = simde_vld1_f64(test_vec[i].a);
    simde_int64x1_t r = simde_vcvt_s64_f64(a);

    simde_test_arm_neon_assert_equal_i64x1(r, simde_vld1_s64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x1_t a = simde_test_arm_neon_random_f64x1(-1000.0, 1000.0);
    simde_int64x1_t r = simde_vcvt_s64_f64(a);

    simde_test_arm_neon_write_f64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}


static int
test_simde_vcvt_u32_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a[2];
    uint32_t r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   769.38), SIMDE_FLOAT32_C(  -948.10) },
      { UINT32_C(       769), UINT32_C(         0) } },
    { { SIMDE_FLOAT32_C(   -50.28), SIMDE_FLOAT32_C(  -280.11) },
      { UINT32_C(         0), UINT32_C(         0) } },
    { { SIMDE_FLOAT32_C(  -758.47), SIMDE_FLOAT32_C(    -0.89) },
      { UINT32_C(         0), UINT32_C(         0) } },
    { { SIMDE_FLOAT32_C(  -929.81), SIMDE_FLOAT32_C(   722.65) },
      { UINT32_C(         0), UINT32_C(       722) } },
    { { SIMDE_FLOAT32_C(   920.72), SIMDE_FLOAT32_C(   126.70) },
      { UINT32_C(       920), UINT32_C(       126) } },
    { { SIMDE_FLOAT32_C(  -812.69), SIMDE_FLOAT32_C(  -253.03) },
      { UINT32_C(         0), UINT32_C(         0) } },
    { { SIMDE_FLOAT32_C(  -104.04), SIMDE_FLOAT32_C(  -971.51) },
      { UINT32_C(         0), UINT32_C(         0) } },
    { { SIMDE_FLOAT32_C(   953.10), SIMDE_FLOAT32_C(  -600.37) },
      { UINT32_C(       953), UINT32_C(         0) } },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t a = simde_vld1_f32(test_vec[i].a);
    simde_uint32x2_t r = simde_vcvt_u32_f32(a);
    simde_test_arm_neon_assert_equal_u32x2(r, simde_vld1_u32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x2_t a = simde_test_arm_neon_random_f32x2(-1000.0, 1000.0);
    simde_uint32x2_t r = simde_vcvt_u32_f32(a);

    simde_test_arm_neon_write_f32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvt_u64_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 a[1];
    uint64_t r[1];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(   382.15) },
      { UINT64_C(                 382) } },
    { { SIMDE_FLOAT64_C(   800.28) },
      { UINT64_C(                 800) } },
    { { SIMDE_FLOAT64_C(   154.09) },
      { UINT64_C(                 154) } },
    { { SIMDE_FLOAT64_C(  -615.70) },
      { UINT64_C(                   0) } },
    { { SIMDE_FLOAT64_C(   874.69) },
      { UINT64_C(                 874) } },
    { { SIMDE_FLOAT64_C(   628.68) },
      { UINT64_C(                 628) } },
    { { SIMDE_FLOAT64_C(  -866.55) },
      { UINT64_C(                   0) } },
    { { SIMDE_FLOAT64_C(   -27.95) },
      { UINT64_C(                   0) } },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x1_t a = simde_vld1_f64(test_vec[i].a);
    simde_uint64x1_t r = simde_vcvt_u64_f64(a);
    simde_test_arm_neon_assert_equal_u64x1(r, simde_vld1_u64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x1_t a = simde_test_arm_neon_random_f64x1(-1000.0, 1000.0);
    simde_uint64x1_t r = simde_vcvt_u64_f64(a);

    simde_test_arm_neon_write_f64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvtq_s32_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a[4];
    int32_t r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   803.18), SIMDE_FLOAT32_C(  -587.37), SIMDE_FLOAT32_C(   500.83), SIMDE_FLOAT32_C(  -606.29) },
      {  INT32_C(         803), -INT32_C(         587),  INT32_C(         500), -INT32_C(         606) } },
    { { SIMDE_FLOAT32_C(   553.19), SIMDE_FLOAT32_C(   -89.37), SIMDE_FLOAT32_C(  -751.51), SIMDE_FLOAT32_C(    39.67) },
      {  INT32_C(         553), -INT32_C(          89), -INT32_C(         751),  INT32_C(          39) } },
    { { SIMDE_FLOAT32_C(   324.39), SIMDE_FLOAT32_C(    39.90), SIMDE_FLOAT32_C(   154.38), SIMDE_FLOAT32_C(  -782.06) },
      {  INT32_C(         324),  INT32_C(          39),  INT32_C(         154), -INT32_C(         782) } },
    { { SIMDE_FLOAT32_C(   683.78), SIMDE_FLOAT32_C(   860.43), SIMDE_FLOAT32_C(   258.08), SIMDE_FLOAT32_C(  -431.46) },
      {  INT32_C(         683),  INT32_C(         860),  INT32_C(         258), -INT32_C(         431) } },
    { { SIMDE_FLOAT32_C(     4.94), SIMDE_FLOAT32_C(  -752.53), SIMDE_FLOAT32_C(   343.30), SIMDE_FLOAT32_C(  -618.07) },
      {  INT32_C(           4), -INT32_C(         752),  INT32_C(         343), -INT32_C(         618) } },
    { { SIMDE_FLOAT32_C(  -508.63), SIMDE_FLOAT32_C(   933.29), SIMDE_FLOAT32_C(    48.92), SIMDE_FLOAT32_C(   220.74) },
      { -INT32_C(         508),  INT32_C(         933),  INT32_C(          48),  INT32_C(         220) } },
    { { SIMDE_FLOAT32_C(  -447.64), SIMDE_FLOAT32_C(  -181.80), SIMDE_FLOAT32_C(  -962.01), SIMDE_FLOAT32_C(   914.94) },
      { -INT32_C(         447), -INT32_C(         181), -INT32_C(         962),  INT32_C(         914) } },
    { { SIMDE_FLOAT32_C(  -193.26), SIMDE_FLOAT32_C(    71.12), SIMDE_FLOAT32_C(   342.76), SIMDE_FLOAT32_C(  -390.07) },
      { -INT32_C(         193),  INT32_C(          71),  INT32_C(         342), -INT32_C(         390) } },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_int32x4_t r = simde_vcvtq_s32_f32(a);
    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x4_t a = simde_test_arm_neon_random_f32x4(-1000.0, 1000.0);
    simde_int32x4_t r = simde_vcvtq_s32_f32(a);

    simde_test_arm_neon_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvtq_s64_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 a[2];
    int64_t r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(     7.90), SIMDE_FLOAT64_C(  -570.72) },
      {  INT64_C(                   7), -INT64_C(                 570) } },
    { { SIMDE_FLOAT64_C(  -808.38), SIMDE_FLOAT64_C(   530.98) },
      { -INT64_C(                 808),  INT64_C(                 530) } },
    { { SIMDE_FLOAT64_C(   801.81), SIMDE_FLOAT64_C(  -148.95) },
      {  INT64_C(                 801), -INT64_C(                 148) } },
    { { SIMDE_FLOAT64_C(   837.17), SIMDE_FLOAT64_C(   387.04) },
      {  INT64_C(                 837),  INT64_C(                 387) } },
    { { SIMDE_FLOAT64_C(   553.61), SIMDE_FLOAT64_C(     6.86) },
      {  INT64_C(                 553),  INT64_C(                   6) } },
    { { SIMDE_FLOAT64_C(  -828.64), SIMDE_FLOAT64_C(  -734.97) },
      { -INT64_C(                 828), -INT64_C(                 734) } },
    { { SIMDE_FLOAT64_C(   315.20), SIMDE_FLOAT64_C(  -666.72) },
      {  INT64_C(                 315), -INT64_C(                 666) } },
    { { SIMDE_FLOAT64_C(  -735.89), SIMDE_FLOAT64_C(    55.10) },
      { -INT64_C(                 735),  INT64_C(                  55) } },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2_t a = simde_vld1q_f64(test_vec[i].a);
    simde_int64x2_t r = simde_vcvtq_s64_f64(a);
    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x2_t a = simde_test_arm_neon_random_f64x2(-1000.0, 1000.0);
    simde_int64x2_t r = simde_vcvtq_s64_f64(a);

    simde_test_arm_neon_write_f64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvtq_u32_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a[4];
    uint32_t r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   101.83), SIMDE_FLOAT32_C(   359.10), SIMDE_FLOAT32_C(   718.19), SIMDE_FLOAT32_C(  -635.43) },
      { UINT32_C(       101), UINT32_C(       359), UINT32_C(       718), UINT32_C(         0) } },
    { { SIMDE_FLOAT32_C(   426.17), SIMDE_FLOAT32_C(  -916.71), SIMDE_FLOAT32_C(   598.15), SIMDE_FLOAT32_C(  -323.30) },
      { UINT32_C(       426), UINT32_C(         0), UINT32_C(       598), UINT32_C(         0) } },
    { { SIMDE_FLOAT32_C(   835.20), SIMDE_FLOAT32_C(   302.52), SIMDE_FLOAT32_C(  -672.10), SIMDE_FLOAT32_C(  -672.13) },
      { UINT32_C(       835), UINT32_C(       302), UINT32_C(         0), UINT32_C(         0) } },
    { { SIMDE_FLOAT32_C(  -675.16), SIMDE_FLOAT32_C(  -201.16), SIMDE_FLOAT32_C(   670.23), SIMDE_FLOAT32_C(   715.02) },
      { UINT32_C(         0), UINT32_C(         0), UINT32_C(       670), UINT32_C(       715) } },
    { { SIMDE_FLOAT32_C(   135.28), SIMDE_FLOAT32_C(   243.93), SIMDE_FLOAT32_C(   -51.68), SIMDE_FLOAT32_C(  -899.58) },
      { UINT32_C(       135), UINT32_C(       243), UINT32_C(         0), UINT32_C(         0) } },
    { { SIMDE_FLOAT32_C(   681.80), SIMDE_FLOAT32_C(  -157.71), SIMDE_FLOAT32_C(   547.10), SIMDE_FLOAT32_C(   626.30) },
      { UINT32_C(       681), UINT32_C(         0), UINT32_C(       547), UINT32_C(       626) } },
    { { SIMDE_FLOAT32_C(   588.25), SIMDE_FLOAT32_C(   -67.67), SIMDE_FLOAT32_C(  -423.03), SIMDE_FLOAT32_C(  -927.65) },
      { UINT32_C(       588), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0) } },
    { { SIMDE_FLOAT32_C(  -830.78), SIMDE_FLOAT32_C(   270.29), SIMDE_FLOAT32_C(   703.79), SIMDE_FLOAT32_C(   271.05) },
      { UINT32_C(         0), UINT32_C(       270), UINT32_C(       703), UINT32_C(       271) } },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_uint32x4_t r = simde_vcvtq_u32_f32(a);

    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x4_t a = simde_test_arm_neon_random_f32x4(-1000.0, 1000.0);
    simde_uint32x4_t r = simde_vcvtq_u32_f32(a);

    simde_test_arm_neon_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvtq_u64_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 a[2];
    uint64_t r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(   770.83), SIMDE_FLOAT64_C(   372.43) },
      { UINT64_C(                 770), UINT64_C(                 372) } },
    { { SIMDE_FLOAT64_C(    28.55), SIMDE_FLOAT64_C(   399.88) },
      { UINT64_C(                  28), UINT64_C(                 399) } },
    { { SIMDE_FLOAT64_C(  -588.00), SIMDE_FLOAT64_C(   915.76) },
      { UINT64_C(                   0), UINT64_C(                 915) } },
    { { SIMDE_FLOAT64_C(  -114.69), SIMDE_FLOAT64_C(    92.85) },
      { UINT64_C(                   0), UINT64_C(                  92) } },
    { { SIMDE_FLOAT64_C(   423.51), SIMDE_FLOAT64_C(   -79.29) },
      { UINT64_C(                 423), UINT64_C(                   0) } },
    { { SIMDE_FLOAT64_C(  -159.38), SIMDE_FLOAT64_C(   303.14) },
      { UINT64_C(                   0), UINT64_C(                 303) } },
    { { SIMDE_FLOAT64_C(   981.64), SIMDE_FLOAT64_C(  -989.30) },
      { UINT64_C(                 981), UINT64_C(                   0) } },
    { { SIMDE_FLOAT64_C(  -536.33), SIMDE_FLOAT64_C(   469.05) },
      { UINT64_C(                   0), UINT64_C(                 469) } },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2_t a = simde_vld1q_f64(test_vec[i].a);
    simde_uint64x2_t r = simde_vcvtq_u64_f64(a);
    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x2_t a = simde_test_arm_neon_random_f64x2(-1000.0, 1000.0);
    simde_uint64x2_t r = simde_vcvtq_u64_f64(a);

    simde_test_arm_neon_write_f64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vcvts_s32_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtd_s64_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvts_u32_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtd_u64_f64)

SIMDE_TEST_FUNC_LIST_ENTRY(vcvt_s32_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvt_s64_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvt_u32_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvt_u64_f64)

SIMDE_TEST_FUNC_LIST_ENTRY(vcvtq_s32_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtq_s64_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtq_u32_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtq_u64_f64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
