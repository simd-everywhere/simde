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
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
      {            SIMDE_MATH_NANF,
        INT32_C(           0) },
      { HEDLEY_STATIC_CAST(simde_float32, INT32_MAX) + SIMDE_FLOAT32_C(1000.0),
                    INT32_MAX },
      { HEDLEY_STATIC_CAST(simde_float32, INT32_MIN) - SIMDE_FLOAT32_C(1000.0),
                    INT32_MIN },
    #endif
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
       INT32_C(         784) }
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
    simde_float32 a = simde_test_codegen_random_f32(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
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
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
      {             SIMDE_MATH_NAN,
        INT64_C(           0) },
      { HEDLEY_STATIC_CAST(simde_float64, INT64_MAX) + SIMDE_FLOAT64_C(10000.0),
                    INT64_MAX },
      { HEDLEY_STATIC_CAST(simde_float64, INT64_MIN) - SIMDE_FLOAT64_C(10000.0),
                    INT64_MIN },
    #endif
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
       INT64_C(                 774) }
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
    simde_float64 a = simde_test_codegen_random_f64(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
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
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
      {            SIMDE_MATH_NANF,
        INT32_C(           0) },
      { HEDLEY_STATIC_CAST(simde_float32, UINT32_MAX) + SIMDE_FLOAT32_C(1000.0),
                  UINT32_MAX },
      { SIMDE_FLOAT32_C(-1000.0),
        UINT32_C(         0) },
    #endif
    { SIMDE_FLOAT32_C(   738.60),
      UINT32_C(       738) },
    { SIMDE_FLOAT32_C(   205.64),
      UINT32_C(       205) },
    { SIMDE_FLOAT32_C(   570.91),
      UINT32_C(       570) },
    { SIMDE_FLOAT32_C(   812.89),
      UINT32_C(       812) },
    { SIMDE_FLOAT32_C(   660.14),
      UINT32_C(       660) },
    { SIMDE_FLOAT32_C(   129.55),
      UINT32_C(       129) },
    { SIMDE_FLOAT32_C(   382.62),
      UINT32_C(       382) },
    { SIMDE_FLOAT32_C(   355.17),
      UINT32_C(       355) }

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
    simde_float32 a = simde_test_codegen_random_f32(SIMDE_FLOAT32_C(0.0), SIMDE_FLOAT32_C(1000.0));
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
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
      {             SIMDE_MATH_NAN,
        INT64_C(           0) },
      { HEDLEY_STATIC_CAST(simde_float64, UINT64_MAX) + SIMDE_FLOAT64_C(10000.0),
                  UINT64_MAX },
      { SIMDE_FLOAT64_C(-1000.0),
        UINT64_C(         0) },
    #endif
    { SIMDE_FLOAT64_C(   428.71),
      UINT64_C(                 428) },
    { SIMDE_FLOAT64_C(   662.47),
      UINT64_C(                 662) },
    { SIMDE_FLOAT64_C(   262.53),
      UINT64_C(                 262) },
    { SIMDE_FLOAT64_C(   313.97),
      UINT64_C(                 313) },
    { SIMDE_FLOAT64_C(   730.17),
      UINT64_C(                 730) },
    { SIMDE_FLOAT64_C(    13.75),
      UINT64_C(                  13) },
    { SIMDE_FLOAT64_C(   587.80),
      UINT64_C(                 587) },
    { SIMDE_FLOAT64_C(   889.77),
      UINT64_C(                 889) }
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
    simde_float64 a = simde_test_codegen_random_f64(SIMDE_FLOAT64_C(0.0), SIMDE_FLOAT64_C(1000.0));
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
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
      { { HEDLEY_STATIC_CAST(simde_float32, INT32_MAX) + SIMDE_FLOAT32_C(1000.0),
          HEDLEY_STATIC_CAST(simde_float32, INT32_MIN) - SIMDE_FLOAT32_C(1000.0) },
        {              INT32_MAX,              INT32_MIN } },
      { {        SIMDE_MATH_NANF,   SIMDE_MATH_INFINITYF },
        {  INT32_C(           0),              INT32_MAX } },
    #endif
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
      { -INT32_C(         998), -INT32_C(         409) } }
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
    simde_float32x2_t a = simde_test_arm_neon_random_f32x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
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
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
      { { HEDLEY_STATIC_CAST(simde_float64, INT64_MAX) + SIMDE_FLOAT64_C(10000.0) },
        { INT64_MAX } },
      { { HEDLEY_STATIC_CAST(simde_float64, INT64_MIN) - SIMDE_FLOAT64_C(10000.0) },
        { INT64_MIN } },
      { { SIMDE_MATH_NAN },
        {  INT64_C(0) } },
    #endif
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
      {  INT64_C(                  35) } }
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
    simde_float64x1_t a = simde_test_arm_neon_random_f64x1(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
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
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
      { { HEDLEY_STATIC_CAST(simde_float32, UINT32_MAX) + SIMDE_FLOAT32_C(1000.0) },
        { UINT32_MAX } },
      { { -SIMDE_FLOAT32_C(1000.0) },
        { INT32_C(0) } },
      { { SIMDE_MATH_NAN },
        { INT32_C(0) } },
    #endif
    { { SIMDE_FLOAT32_C(   308.77), SIMDE_FLOAT32_C(   269.80) },
      { UINT32_C(       308), UINT32_C(       269) } },
    { { SIMDE_FLOAT32_C(   859.81), SIMDE_FLOAT32_C(    64.54) },
      { UINT32_C(       859), UINT32_C(        64) } },
    { { SIMDE_FLOAT32_C(     2.07), SIMDE_FLOAT32_C(   232.20) },
      { UINT32_C(         2), UINT32_C(       232) } },
    { { SIMDE_FLOAT32_C(   601.91), SIMDE_FLOAT32_C(   749.29) },
      { UINT32_C(       601), UINT32_C(       749) } },
    { { SIMDE_FLOAT32_C(   306.06), SIMDE_FLOAT32_C(   837.28) },
      { UINT32_C(       306), UINT32_C(       837) } },
    { { SIMDE_FLOAT32_C(   751.87), SIMDE_FLOAT32_C(   543.72) },
      { UINT32_C(       751), UINT32_C(       543) } },
    { { SIMDE_FLOAT32_C(   269.87), SIMDE_FLOAT32_C(   829.47) },
      { UINT32_C(       269), UINT32_C(       829) } },
    { { SIMDE_FLOAT32_C(    14.26), SIMDE_FLOAT32_C(   782.29) },
      { UINT32_C(        14), UINT32_C(       782) } }

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
    simde_float32x2_t a = simde_test_arm_neon_random_f32x2(0.0, 1000.0);
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
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
      { { HEDLEY_STATIC_CAST(simde_float64, UINT64_MAX) + SIMDE_FLOAT64_C(10000.0) },
        { UINT64_MAX } },
      { { -SIMDE_FLOAT64_C(1000.0) },
        { INT64_C(0) } },
      { { SIMDE_MATH_NAN },
        { INT64_C(0) } },
    #endif
    { { SIMDE_FLOAT64_C(   344.30) },
      { UINT64_C(                 344) } },
    { { SIMDE_FLOAT64_C(   669.70) },
      { UINT64_C(                 669) } },
    { { SIMDE_FLOAT64_C(   628.84) },
      { UINT64_C(                 628) } },
    { { SIMDE_FLOAT64_C(   358.76) },
      { UINT64_C(                 358) } },
    { { SIMDE_FLOAT64_C(    85.06) },
      { UINT64_C(                  85) } },
    { { SIMDE_FLOAT64_C(   302.20) },
      { UINT64_C(                 302) } },
    { { SIMDE_FLOAT64_C(   709.75) },
      { UINT64_C(                 709) } },
    { { SIMDE_FLOAT64_C(   502.24) },
      { UINT64_C(                 502) } }

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
    simde_float64x1_t a = simde_test_arm_neon_random_f64x1(SIMDE_FLOAT64_C(0.0), SIMDE_FLOAT64_C(1000.0));
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
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
      { { HEDLEY_STATIC_CAST(simde_float32, INT32_MAX) + SIMDE_FLOAT32_C(10000.0), HEDLEY_STATIC_CAST(simde_float32, INT32_MIN) - SIMDE_FLOAT32_C(10000.0), SIMDE_MATH_NANF, SIMDE_MATH_INFINITYF },
        {              INT32_MAX,              INT32_MIN,  INT32_C(           0),              INT32_MAX } },
    #endif
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
      { -INT32_C(         193),  INT32_C(          71),  INT32_C(         342), -INT32_C(         390) } }
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
    simde_float32x4_t a = simde_test_arm_neon_random_f32x4(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
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
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
      { { HEDLEY_STATIC_CAST(simde_float64, INT64_MAX) + SIMDE_FLOAT64_C(10000.0), HEDLEY_STATIC_CAST(simde_float64, INT64_MIN) - SIMDE_FLOAT64_C(10000.0) },
        {                      INT64_MAX,                      INT64_MIN } },
      { {             SIMDE_MATH_NAN,        SIMDE_MATH_INFINITY },
        { INT64_C(                   0),                       INT64_MAX } },
    #endif
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
      { -INT64_C(                 735),  INT64_C(                  55) } }
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
    simde_float64x2_t a = simde_test_arm_neon_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
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
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
      { { HEDLEY_STATIC_CAST(simde_float32, UINT32_MAX) + SIMDE_FLOAT32_C(10000.0), SIMDE_MATH_NANF, -SIMDE_MATH_NANF, SIMDE_MATH_INFINITYF },
        {           UINT32_MAX, UINT32_C(         0), UINT32_C(         0),           UINT32_MAX } },
    #endif
    { { SIMDE_FLOAT32_C(   169.27), SIMDE_FLOAT32_C(   616.25), SIMDE_FLOAT32_C(   454.93), SIMDE_FLOAT32_C(   561.26) },
      { UINT32_C(       169), UINT32_C(       616), UINT32_C(       454), UINT32_C(       561) } },
    { { SIMDE_FLOAT32_C(   148.72), SIMDE_FLOAT32_C(   602.28), SIMDE_FLOAT32_C(   959.49), SIMDE_FLOAT32_C(   218.41) },
      { UINT32_C(       148), UINT32_C(       602), UINT32_C(       959), UINT32_C(       218) } },
    { { SIMDE_FLOAT32_C(   325.37), SIMDE_FLOAT32_C(   686.32), SIMDE_FLOAT32_C(   690.28), SIMDE_FLOAT32_C(    28.98) },
      { UINT32_C(       325), UINT32_C(       686), UINT32_C(       690), UINT32_C(        28) } },
    { { SIMDE_FLOAT32_C(   498.79), SIMDE_FLOAT32_C(   175.99), SIMDE_FLOAT32_C(   426.50), SIMDE_FLOAT32_C(   983.51) },
      { UINT32_C(       498), UINT32_C(       175), UINT32_C(       426), UINT32_C(       983) } },
    { { SIMDE_FLOAT32_C(   813.92), SIMDE_FLOAT32_C(   911.70), SIMDE_FLOAT32_C(   467.12), SIMDE_FLOAT32_C(   500.14) },
      { UINT32_C(       813), UINT32_C(       911), UINT32_C(       467), UINT32_C(       500) } },
    { { SIMDE_FLOAT32_C(   289.14), SIMDE_FLOAT32_C(   483.56), SIMDE_FLOAT32_C(   831.86), SIMDE_FLOAT32_C(   688.26) },
      { UINT32_C(       289), UINT32_C(       483), UINT32_C(       831), UINT32_C(       688) } },
    { { SIMDE_FLOAT32_C(   803.86), SIMDE_FLOAT32_C(   762.17), SIMDE_FLOAT32_C(   408.81), SIMDE_FLOAT32_C(   246.10) },
      { UINT32_C(       803), UINT32_C(       762), UINT32_C(       408), UINT32_C(       246) } },
    { { SIMDE_FLOAT32_C(   985.02), SIMDE_FLOAT32_C(    92.20), SIMDE_FLOAT32_C(   515.77), SIMDE_FLOAT32_C(   154.29) },
      { UINT32_C(       985), UINT32_C(        92), UINT32_C(       515), UINT32_C(       154) } }

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
    simde_float32x4_t a = simde_test_arm_neon_random_f32x4(SIMDE_FLOAT32_C(0.0), SIMDE_FLOAT32_C(1000.0));
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
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
      { { HEDLEY_STATIC_CAST(simde_float64, UINT64_MAX) + SIMDE_FLOAT64_C(10000.0) },
        {           UINT64_MAX, UINT64_C(         0) } },
      { {  -SIMDE_MATH_NAN, -SIMDE_FLOAT64_C(10000.0) },
        { UINT64_C(         0), UINT64_C(         0) } },
    #endif
    { { SIMDE_FLOAT64_C(   182.67), SIMDE_FLOAT64_C(   140.69) },
      { UINT64_C(                 182), UINT64_C(                 140) } },
    { { SIMDE_FLOAT64_C(   326.15), SIMDE_FLOAT64_C(   465.87) },
      { UINT64_C(                 326), UINT64_C(                 465) } },
    { { SIMDE_FLOAT64_C(    24.33), SIMDE_FLOAT64_C(   507.60) },
      { UINT64_C(                  24), UINT64_C(                 507) } },
    { { SIMDE_FLOAT64_C(   765.94), SIMDE_FLOAT64_C(   196.40) },
      { UINT64_C(                 765), UINT64_C(                 196) } },
    { { SIMDE_FLOAT64_C(   933.89), SIMDE_FLOAT64_C(   836.65) },
      { UINT64_C(                 933), UINT64_C(                 836) } },
    { { SIMDE_FLOAT64_C(   256.48), SIMDE_FLOAT64_C(   100.64) },
      { UINT64_C(                 256), UINT64_C(                 100) } },
    { { SIMDE_FLOAT64_C(    95.90), SIMDE_FLOAT64_C(   653.31) },
      { UINT64_C(                  95), UINT64_C(                 653) } },
    { { SIMDE_FLOAT64_C(   555.78), SIMDE_FLOAT64_C(   417.32) },
      { UINT64_C(                 555), UINT64_C(                 417) } },
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
    simde_float64x2_t a = simde_test_arm_neon_random_f64x2(SIMDE_FLOAT64_C(0.0), SIMDE_FLOAT64_C(1000.0));
    simde_uint64x2_t r = simde_vcvtq_u64_f64(a);

    simde_test_arm_neon_write_f64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvt_f32_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[2];
    simde_float32 r[2];
  } test_vec[] = {
    { { -INT32_C(  1490815448),  INT32_C(   440787632) },
      { SIMDE_FLOAT32_C(-1490815488.00), SIMDE_FLOAT32_C(440787648.00) } },
    { {  INT32_C(  1033660046),  INT32_C(   730210234) },
      { SIMDE_FLOAT32_C(1033660032.00), SIMDE_FLOAT32_C(730210240.00) } },
    { { -INT32_C(   389361289),  INT32_C(  1176472002) },
      { SIMDE_FLOAT32_C(-389361280.00), SIMDE_FLOAT32_C(1176472064.00) } },
    { { -INT32_C(  1920118894), -INT32_C(   230240567) },
      { SIMDE_FLOAT32_C(-1920118912.00), SIMDE_FLOAT32_C(-230240560.00) } },
    { {  INT32_C(  1956211140), -INT32_C(   644948405) },
      { SIMDE_FLOAT32_C(1956211200.00), SIMDE_FLOAT32_C(-644948416.00) } },
    { { -INT32_C(    32036028), -INT32_C(  1054237366) },
      { SIMDE_FLOAT32_C(-32036028.00), SIMDE_FLOAT32_C(-1054237376.00) } },
    { {  INT32_C(   816444270),  INT32_C(   242665596) },
      { SIMDE_FLOAT32_C(816444288.00), SIMDE_FLOAT32_C(242665600.00) } },
    { { -INT32_C(   509869032), -INT32_C(  1764498734) },
      { SIMDE_FLOAT32_C(-509869024.00), SIMDE_FLOAT32_C(-1764498688.00) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t a = simde_vld1_s32(test_vec[i].a);
    simde_float32x2_t r = simde_vcvt_f32_s32(a);

    simde_test_arm_neon_assert_equal_f32x2(r, simde_vld1_f32(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x2_t a = simde_test_arm_neon_random_i32x2();
    simde_float32x2_t r = simde_vcvt_f32_s32(a);

    simde_test_arm_neon_write_i32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvt_f64_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a[1];
    simde_float64 r[1];
  } test_vec[] = {
    { { -INT64_C( 5637188979182257959) },
      { SIMDE_FLOAT64_C(-5637188979182258176.00) } },
    { { -INT64_C( 1615765083744039100) },
      { SIMDE_FLOAT64_C(-1615765083744039168.00) } },
    { { -INT64_C( 3391338634861752101) },
      { SIMDE_FLOAT64_C(-3391338634861752320.00) } },
    { { -INT64_C( 5913301266420841191) },
      { SIMDE_FLOAT64_C(-5913301266420841472.00) } },
    { { -INT64_C(  494825632698398733) },
      { SIMDE_FLOAT64_C(-494825632698398720.00) } },
    { { -INT64_C( 7406702033022478571) },
      { SIMDE_FLOAT64_C(-7406702033022478336.00) } },
    { { -INT64_C( 2579062017698220053) },
      { SIMDE_FLOAT64_C(-2579062017698220032.00) } },
    { {  INT64_C(  151943772838646681) },
      { SIMDE_FLOAT64_C(151943772838646688.00) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x1_t a = simde_vld1_s64(test_vec[i].a);
    simde_float64x1_t r = simde_vcvt_f64_s64(a);

    simde_test_arm_neon_assert_equal_f64x1(r, simde_vld1_f64(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int64x1_t a = simde_test_arm_neon_random_i64x1();
    simde_float64x1_t r = simde_vcvt_f64_s64(a);

    simde_test_arm_neon_write_i64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}


static int
test_simde_vcvt_f32_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[2];
    simde_float32 r[2];
  } test_vec[] = {
    { { UINT32_C(2587932456), UINT32_C( 295281173) },
      { SIMDE_FLOAT32_C(2587932416.00), SIMDE_FLOAT32_C(295281184.00) } },
    { { UINT32_C(3545609472), UINT32_C(2675448399) },
      { SIMDE_FLOAT32_C(3545609472.00), SIMDE_FLOAT32_C(2675448320.00) } },
    { { UINT32_C(2886471787), UINT32_C(3487249558) },
      { SIMDE_FLOAT32_C(2886471680.00), SIMDE_FLOAT32_C(3487249664.00) } },
    { { UINT32_C(4010341369), UINT32_C(2972864136) },
      { SIMDE_FLOAT32_C(4010341376.00), SIMDE_FLOAT32_C(2972864256.00) } },
    { { UINT32_C( 441152005), UINT32_C( 338486292) },
      { SIMDE_FLOAT32_C(441152000.00), SIMDE_FLOAT32_C(338486304.00) } },
    { { UINT32_C(3924328857), UINT32_C( 126378139) },
      { SIMDE_FLOAT32_C(3924328960.00), SIMDE_FLOAT32_C(126378136.00) } },
    { { UINT32_C( 129209456), UINT32_C(3252063944) },
      { SIMDE_FLOAT32_C(129209456.00), SIMDE_FLOAT32_C(3252064000.00) } },
    { { UINT32_C( 179363457), UINT32_C( 851173932) },
      { SIMDE_FLOAT32_C(179363456.00), SIMDE_FLOAT32_C(851173952.00) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2_t a = simde_vld1_u32(test_vec[i].a);
    simde_float32x2_t r = simde_vcvt_f32_u32(a);
    simde_test_arm_neon_assert_equal_f32x2(r, simde_vld1_f32(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x2_t a = simde_test_arm_neon_random_u32x2();
    simde_float32x2_t r = simde_vcvt_f32_u32(a);

    simde_test_arm_neon_write_u32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvt_f64_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a[1];
    simde_float64 r[1];
  } test_vec[] = {
    { { UINT64_C( 8225907245979072970) },
      { SIMDE_FLOAT64_C(8225907245979072512.00) } },
    { { UINT64_C(16476598577281444883) },
      { SIMDE_FLOAT64_C(16476598577281445888.00) } },
    { { UINT64_C( 4343902165234378246) },
      { SIMDE_FLOAT64_C(4343902165234378240.00) } },
    { { UINT64_C(15500192606257303370) },
      { SIMDE_FLOAT64_C(15500192606257303552.00) } },
    { { UINT64_C( 6717319276498190264) },
      { SIMDE_FLOAT64_C(6717319276498190336.00) } },
    { { UINT64_C( 8350517506981939683) },
      { SIMDE_FLOAT64_C(8350517506981939200.00) } },
    { { UINT64_C(12151509346023160421) },
      { SIMDE_FLOAT64_C(12151509346023159808.00) } },
    { { UINT64_C( 3677480995464854564) },
      { SIMDE_FLOAT64_C(3677480995464854528.00) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x1_t a = simde_vld1_u64(test_vec[i].a);
    simde_float64x1_t r = simde_vcvt_f64_u64(a);
    simde_test_arm_neon_assert_equal_f64x1(r, simde_vld1_f64(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint64x1_t a = simde_test_arm_neon_random_u64x1();
    simde_float64x1_t r = simde_vcvt_f64_u64(a);

    simde_test_arm_neon_write_u64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvtq_f32_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[4];
    simde_float32 r[4];
  } test_vec[] = {
    { { -INT32_C(   932389316), -INT32_C(  1088008327), -INT32_C(  1969616841), -INT32_C(  1510957523) },
      { SIMDE_FLOAT32_C(-932389312.00), SIMDE_FLOAT32_C(-1088008320.00), SIMDE_FLOAT32_C(-1969616896.00), SIMDE_FLOAT32_C(-1510957568.00) } },
    { { -INT32_C(    55262820),  INT32_C(   574170805),  INT32_C(  1250738434),  INT32_C(  1268545039) },
      { SIMDE_FLOAT32_C(-55262820.00), SIMDE_FLOAT32_C(574170816.00), SIMDE_FLOAT32_C(1250738432.00), SIMDE_FLOAT32_C(1268545024.00) } },
    { { -INT32_C(   854325164), -INT32_C(  1886569896),  INT32_C(  1880762178),  INT32_C(  1645546181) },
      { SIMDE_FLOAT32_C(-854325184.00), SIMDE_FLOAT32_C(-1886569856.00), SIMDE_FLOAT32_C(1880762240.00), SIMDE_FLOAT32_C(1645546240.00) } },
    { { -INT32_C(  2141271605), -INT32_C(   224225040),  INT32_C(  1748774489), -INT32_C(   122431324) },
      { SIMDE_FLOAT32_C(-2141271552.00), SIMDE_FLOAT32_C(-224225040.00), SIMDE_FLOAT32_C(1748774528.00), SIMDE_FLOAT32_C(-122431328.00) } },
    { {  INT32_C(   969328609),  INT32_C(  1153979138),  INT32_C(  1085596282), -INT32_C(  1214068244) },
      { SIMDE_FLOAT32_C(969328640.00), SIMDE_FLOAT32_C(1153979136.00), SIMDE_FLOAT32_C(1085596288.00), SIMDE_FLOAT32_C(-1214068224.00) } },
    { { -INT32_C(  2093481837), -INT32_C(   243934568), -INT32_C(  1386630647),  INT32_C(  1806044554) },
      { SIMDE_FLOAT32_C(-2093481856.00), SIMDE_FLOAT32_C(-243934560.00), SIMDE_FLOAT32_C(-1386630656.00), SIMDE_FLOAT32_C(1806044544.00) } },
    { { -INT32_C(   693867308),  INT32_C(   958098879),  INT32_C(  1014615887),  INT32_C(   754129817) },
      { SIMDE_FLOAT32_C(-693867328.00), SIMDE_FLOAT32_C(958098880.00), SIMDE_FLOAT32_C(1014615872.00), SIMDE_FLOAT32_C(754129792.00) } },
    { { -INT32_C(  1263588580),  INT32_C(   262546438),  INT32_C(  1639776214), -INT32_C(   506699252) },
      { SIMDE_FLOAT32_C(-1263588608.00), SIMDE_FLOAT32_C(262546432.00), SIMDE_FLOAT32_C(1639776256.00), SIMDE_FLOAT32_C(-506699264.00) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_float32x4_t r = simde_vcvtq_f32_s32(a);

    simde_test_arm_neon_assert_equal_f32x4(r, simde_vld1q_f32(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x4_t a = simde_test_arm_neon_random_i32x4();
    simde_float32x4_t r = simde_vcvtq_f32_s32(a);

    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvtq_f64_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a[2];
    simde_float64 r[2];
  } test_vec[] = {
    { { -INT64_C( 5437369519729810865),  INT64_C( 7901797256341896009) },
      { SIMDE_FLOAT64_C(-5437369519729810432.00), SIMDE_FLOAT64_C(7901797256341896192.00) } },
    { { -INT64_C( 7839088714326884250),  INT64_C(  640569667726039958) },
      { SIMDE_FLOAT64_C(-7839088714326884352.00), SIMDE_FLOAT64_C(640569667726039936.00) } },
    { { -INT64_C( 5074851512610989404),  INT64_C( 3884241220501831100) },
      { SIMDE_FLOAT64_C(-5074851512610989056.00), SIMDE_FLOAT64_C(3884241220501831168.00) } },
    { {  INT64_C( 4054477313972153432),  INT64_C( 6809766693901170880) },
      { SIMDE_FLOAT64_C(4054477313972153344.00), SIMDE_FLOAT64_C(6809766693901170688.00) } },
    { { -INT64_C( 5392550408562575359),  INT64_C(  779428067380435404) },
      { SIMDE_FLOAT64_C(-5392550408562575360.00), SIMDE_FLOAT64_C(779428067380435456.00) } },
    { {  INT64_C( 2926214301938811585),  INT64_C(  436886571722072056) },
      { SIMDE_FLOAT64_C(2926214301938811392.00), SIMDE_FLOAT64_C(436886571722072064.00) } },
    { { -INT64_C( 1636882415660610150),  INT64_C( 5581745048800032442) },
      { SIMDE_FLOAT64_C(-1636882415660610048.00), SIMDE_FLOAT64_C(5581745048800032768.00) } },
    { {  INT64_C( 3091806024566387289),  INT64_C( 4987996807332923692) },
      { SIMDE_FLOAT64_C(3091806024566387200.00), SIMDE_FLOAT64_C(4987996807332923392.00) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);
    simde_float64x2_t r = simde_vcvtq_f64_s64(a);

    simde_test_arm_neon_assert_equal_f64x2(r, simde_vld1q_f64(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int64x2_t a = simde_test_arm_neon_random_i64x2();
    simde_float64x2_t r = simde_vcvtq_f64_s64(a);

    simde_test_arm_neon_write_i64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvtq_f32_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[4];
    simde_float32 r[4];
  } test_vec[] = {
    { { UINT32_C(2742190227), UINT32_C(1279879163), UINT32_C(1560757930), UINT32_C(2555284292) },
      { SIMDE_FLOAT32_C(2742190336.00), SIMDE_FLOAT32_C(1279879168.00), SIMDE_FLOAT32_C(1560757888.00), SIMDE_FLOAT32_C(2555284224.00) } },
    { { UINT32_C( 314328964), UINT32_C(1716492923), UINT32_C(2449736314), UINT32_C(4182169446) },
      { SIMDE_FLOAT32_C(314328960.00), SIMDE_FLOAT32_C(1716492928.00), SIMDE_FLOAT32_C(2449736192.00), SIMDE_FLOAT32_C(4182169344.00) } },
    { { UINT32_C(1386068055), UINT32_C(3382634015), UINT32_C(1881646636), UINT32_C(3037230385) },
      { SIMDE_FLOAT32_C(1386068096.00), SIMDE_FLOAT32_C(3382633984.00), SIMDE_FLOAT32_C(1881646592.00), SIMDE_FLOAT32_C(3037230336.00) } },
    { { UINT32_C( 952681917), UINT32_C(3667793759), UINT32_C(2137826073), UINT32_C(3514348154) },
      { SIMDE_FLOAT32_C(952681920.00), SIMDE_FLOAT32_C(3667793664.00), SIMDE_FLOAT32_C(2137826048.00), SIMDE_FLOAT32_C(3514348032.00) } },
    { { UINT32_C(2317620586), UINT32_C( 676578043), UINT32_C(2593684072), UINT32_C(2907677168) },
      { SIMDE_FLOAT32_C(2317620480.00), SIMDE_FLOAT32_C(676578048.00), SIMDE_FLOAT32_C(2593683968.00), SIMDE_FLOAT32_C(2907677184.00) } },
    { { UINT32_C(3320125286), UINT32_C(1201636142), UINT32_C(2697333798), UINT32_C( 695353278) },
      { SIMDE_FLOAT32_C(3320125184.00), SIMDE_FLOAT32_C(1201636096.00), SIMDE_FLOAT32_C(2697333760.00), SIMDE_FLOAT32_C(695353280.00) } },
    { { UINT32_C(1353946708), UINT32_C(3245868632), UINT32_C(1901793409), UINT32_C( 387885745) },
      { SIMDE_FLOAT32_C(1353946752.00), SIMDE_FLOAT32_C(3245868544.00), SIMDE_FLOAT32_C(1901793408.00), SIMDE_FLOAT32_C(387885760.00) } },
    { { UINT32_C(4041016258), UINT32_C(2906160262), UINT32_C(1196293768), UINT32_C(2456862525) },
      { SIMDE_FLOAT32_C(4041016320.00), SIMDE_FLOAT32_C(2906160384.00), SIMDE_FLOAT32_C(1196293760.00), SIMDE_FLOAT32_C(2456862464.00) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_float32x4_t r = simde_vcvtq_f32_u32(a);

    simde_test_arm_neon_assert_equal_f32x4(r, simde_vld1q_f32(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x4_t a = simde_test_arm_neon_random_u32x4();
    simde_float32x4_t r = simde_vcvtq_f32_u32(a);

    simde_test_arm_neon_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvtq_f64_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a[2];
    simde_float64 r[2];
  } test_vec[] = {
    { { UINT64_C(13683682593130234659), UINT64_C(11559544905560819710) },
      { SIMDE_FLOAT64_C(13683682593130233856.00), SIMDE_FLOAT64_C(11559544905560819712.00) } },
    { { UINT64_C( 8936905941469911567), UINT64_C( 3558395723382130100) },
      { SIMDE_FLOAT64_C(8936905941469912064.00), SIMDE_FLOAT64_C(3558395723382130176.00) } },
    { { UINT64_C( 5604675100166593081), UINT64_C(13208615328365603029) },
      { SIMDE_FLOAT64_C(5604675100166593536.00), SIMDE_FLOAT64_C(13208615328365602816.00) } },
    { { UINT64_C(12384439342403662536), UINT64_C( 9485622372482503779) },
      { SIMDE_FLOAT64_C(12384439342403661824.00), SIMDE_FLOAT64_C(9485622372482504704.00) } },
    { { UINT64_C( 3344579514495568845), UINT64_C(11717851499640679486) },
      { SIMDE_FLOAT64_C(3344579514495568896.00), SIMDE_FLOAT64_C(11717851499640680448.00) } },
    { { UINT64_C(13150759761589106141), UINT64_C( 5909789806474809654) },
      { SIMDE_FLOAT64_C(13150759761589106688.00), SIMDE_FLOAT64_C(5909789806474809344.00) } },
    { { UINT64_C( 2728575438831915349), UINT64_C(14033684711101675845) },
      { SIMDE_FLOAT64_C(2728575438831915520.00), SIMDE_FLOAT64_C(14033684711101675520.00) } },
    { { UINT64_C(15972040989054780831), UINT64_C(17275351436999118824) },
      { SIMDE_FLOAT64_C(15972040989054781440.00), SIMDE_FLOAT64_C(17275351436999118848.00) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x2_t a = simde_vld1q_u64(test_vec[i].a);
    simde_float64x2_t r = simde_vcvtq_f64_u64(a);
    simde_test_arm_neon_assert_equal_f64x2(r, simde_vld1q_f64(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint64x2_t a = simde_test_arm_neon_random_u64x2();
    simde_float64x2_t r = simde_vcvtq_f64_u64(a);

    simde_test_arm_neon_write_u64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
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

SIMDE_TEST_FUNC_LIST_ENTRY(vcvt_f32_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvt_f64_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvt_f32_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvt_f64_u64)

SIMDE_TEST_FUNC_LIST_ENTRY(vcvtq_f32_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtq_f64_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtq_f32_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtq_f64_u64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
