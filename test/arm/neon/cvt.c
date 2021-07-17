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
test_simde_vcvt_s16_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16 a[4];
    int16_t r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT16_VALUE(  -567.00), SIMDE_FLOAT16_VALUE(   429.00), SIMDE_FLOAT16_VALUE(   629.50), SIMDE_FLOAT16_VALUE(  -509.25) },
      { -INT16_C(   567),  INT16_C(   429),  INT16_C(   629), -INT16_C(   509) } },
    { { SIMDE_FLOAT16_VALUE(  -128.50), SIMDE_FLOAT16_VALUE(  -750.00), SIMDE_FLOAT16_VALUE(   953.00), SIMDE_FLOAT16_VALUE(  -576.50) },
      { -INT16_C(   128), -INT16_C(   750),  INT16_C(   953), -INT16_C(   576) } },
    { { SIMDE_FLOAT16_VALUE(   999.00), SIMDE_FLOAT16_VALUE(  -727.50), SIMDE_FLOAT16_VALUE(  -893.00), SIMDE_FLOAT16_VALUE(  -542.50) },
      {  INT16_C(   999), -INT16_C(   727), -INT16_C(   893), -INT16_C(   542) } },
    { { SIMDE_FLOAT16_VALUE(  -866.00), SIMDE_FLOAT16_VALUE(  -895.50), SIMDE_FLOAT16_VALUE(   283.25), SIMDE_FLOAT16_VALUE(   857.50) },
      { -INT16_C(   866), -INT16_C(   895),  INT16_C(   283),  INT16_C(   857) } },
    { { SIMDE_FLOAT16_VALUE(    32.12), SIMDE_FLOAT16_VALUE(   794.00), SIMDE_FLOAT16_VALUE(  -495.75), SIMDE_FLOAT16_VALUE(  -708.50) },
      {  INT16_C(    32),  INT16_C(   794), -INT16_C(   495), -INT16_C(   708) } },
    { { SIMDE_FLOAT16_VALUE(   322.25), SIMDE_FLOAT16_VALUE(   821.50), SIMDE_FLOAT16_VALUE(   844.50), SIMDE_FLOAT16_VALUE(   952.50) },
      {  INT16_C(   322),  INT16_C(   821),  INT16_C(   844),  INT16_C(   952) } },
    { { SIMDE_FLOAT16_VALUE(   502.50), SIMDE_FLOAT16_VALUE(  -996.50), SIMDE_FLOAT16_VALUE(  -817.50), SIMDE_FLOAT16_VALUE(  -562.50) },
      {  INT16_C(   502), -INT16_C(   996), -INT16_C(   817), -INT16_C(   562) } },
    { { SIMDE_FLOAT16_VALUE(  -805.50), SIMDE_FLOAT16_VALUE(   461.50), SIMDE_FLOAT16_VALUE(   550.50), SIMDE_FLOAT16_VALUE(  -372.75) },
      { -INT16_C(   805),  INT16_C(   461),  INT16_C(   550), -INT16_C(   372) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x4_t a = simde_vld1_f16(test_vec[i].a);
    simde_int16x4_t r = simde_vcvt_s16_f16(a);

    simde_test_arm_neon_assert_equal_i16x4(r, simde_vld1_s16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16x4_t a = simde_test_arm_neon_random_f16x4(-1000.0f, 1000.0f);
    simde_int16x4_t r = simde_vcvt_s16_f16(a);

    simde_test_arm_neon_write_f16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
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
test_simde_vcvt_u16_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16 a[4];
    uint16_t r[4];
  } test_vec[] = {
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
      { { SIMDE_FLOAT16_VALUE(  -611.50), SIMDE_FLOAT16_VALUE(  -588.50), SIMDE_FLOAT16_VALUE(   839.00), SIMDE_FLOAT16_VALUE(   440.50) },
        { UINT16_C(    0), UINT16_C(    0), UINT16_C(  839), UINT16_C(  440) } },
      { { SIMDE_FLOAT16_VALUE(   -43.19), SIMDE_FLOAT16_VALUE(  -115.88), SIMDE_FLOAT16_VALUE(   160.50), SIMDE_FLOAT16_VALUE(   744.50) },
        { UINT16_C(    0), UINT16_C(    0), UINT16_C(  160), UINT16_C(  744) } },
    #endif
    { { SIMDE_FLOAT16_VALUE(   231.75), SIMDE_FLOAT16_VALUE(   971.00), SIMDE_FLOAT16_VALUE(   897.00), SIMDE_FLOAT16_VALUE(   241.25) },
      { UINT16_C(  231), UINT16_C(  971), UINT16_C(  897), UINT16_C(  241) } },
    { { SIMDE_FLOAT16_VALUE(   648.00), SIMDE_FLOAT16_VALUE(   268.25), SIMDE_FLOAT16_VALUE(    91.31), SIMDE_FLOAT16_VALUE(   371.50) },
      { UINT16_C(  648), UINT16_C(  268), UINT16_C(   91), UINT16_C(  371) } },
    { { SIMDE_FLOAT16_VALUE(   526.50), SIMDE_FLOAT16_VALUE(   148.12), SIMDE_FLOAT16_VALUE(   325.00), SIMDE_FLOAT16_VALUE(    28.55) },
      { UINT16_C(  526), UINT16_C(  148), UINT16_C(  325), UINT16_C(   28) } },
    { { SIMDE_FLOAT16_VALUE(   947.50), SIMDE_FLOAT16_VALUE(   371.75), SIMDE_FLOAT16_VALUE(   814.50), SIMDE_FLOAT16_VALUE(   417.00) },
      { UINT16_C(  947), UINT16_C(  371), UINT16_C(  814), UINT16_C(  417) } },
    { { SIMDE_FLOAT16_VALUE(   645.50), SIMDE_FLOAT16_VALUE(   735.50), SIMDE_FLOAT16_VALUE(   809.00), SIMDE_FLOAT16_VALUE(    30.17) },
      { UINT16_C(  645), UINT16_C(  735), UINT16_C(  809), UINT16_C(   30) } },
    { { SIMDE_FLOAT16_VALUE(   688.00), SIMDE_FLOAT16_VALUE(    22.16), SIMDE_FLOAT16_VALUE(   276.50), SIMDE_FLOAT16_VALUE(   148.62) },
      { UINT16_C(  688), UINT16_C(   22), UINT16_C(  276), UINT16_C(  148) } },
    { { SIMDE_FLOAT16_VALUE(   478.50), SIMDE_FLOAT16_VALUE(   456.50), SIMDE_FLOAT16_VALUE(   974.00), SIMDE_FLOAT16_VALUE(   416.50) },
      { UINT16_C(  478), UINT16_C(  456), UINT16_C(  974), UINT16_C(  416) } },
    { { SIMDE_FLOAT16_VALUE(   282.75), SIMDE_FLOAT16_VALUE(   147.88), SIMDE_FLOAT16_VALUE(   541.00), SIMDE_FLOAT16_VALUE(   514.50) },
      { UINT16_C(  282), UINT16_C(  147), UINT16_C(  541), UINT16_C(  514) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x4_t a = simde_vld1_f16(test_vec[i].a);
    simde_uint16x4_t r = simde_vcvt_u16_f16(a);

    simde_test_arm_neon_assert_equal_u16x4(r, simde_vld1_u16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16x4_t a = simde_test_arm_neon_random_f16x4(0.0f, 1000.0f);
    simde_uint16x4_t r = simde_vcvt_u16_f16(a);

    simde_test_arm_neon_write_f16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
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
test_simde_vcvtq_s16_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16 a[8];
    int16_t r[8];
  } test_vec[] = {
    { { SIMDE_FLOAT16_VALUE(   309.00), SIMDE_FLOAT16_VALUE(   886.50), SIMDE_FLOAT16_VALUE(  -319.25), SIMDE_FLOAT16_VALUE(   953.50),
        SIMDE_FLOAT16_VALUE(   259.50), SIMDE_FLOAT16_VALUE(  -722.00), SIMDE_FLOAT16_VALUE(   772.50), SIMDE_FLOAT16_VALUE(    99.88) },
      {  INT16_C(   309),  INT16_C(   886), -INT16_C(   319),  INT16_C(   953),  INT16_C(   259), -INT16_C(   722),  INT16_C(   772),  INT16_C(    99) } },
    { { SIMDE_FLOAT16_VALUE(  -622.00), SIMDE_FLOAT16_VALUE(   731.00), SIMDE_FLOAT16_VALUE(  -240.38), SIMDE_FLOAT16_VALUE(  -888.00),
        SIMDE_FLOAT16_VALUE(   144.38), SIMDE_FLOAT16_VALUE(  -188.75), SIMDE_FLOAT16_VALUE(   374.50), SIMDE_FLOAT16_VALUE(    58.06) },
      { -INT16_C(   622),  INT16_C(   731), -INT16_C(   240), -INT16_C(   888),  INT16_C(   144), -INT16_C(   188),  INT16_C(   374),  INT16_C(    58) } },
    { { SIMDE_FLOAT16_VALUE(   631.50), SIMDE_FLOAT16_VALUE(   798.00), SIMDE_FLOAT16_VALUE(  -243.75), SIMDE_FLOAT16_VALUE(   144.88),
        SIMDE_FLOAT16_VALUE(  -847.50), SIMDE_FLOAT16_VALUE(  -395.50), SIMDE_FLOAT16_VALUE(  -145.88), SIMDE_FLOAT16_VALUE(   916.50) },
      {  INT16_C(   631),  INT16_C(   798), -INT16_C(   243),  INT16_C(   144), -INT16_C(   847), -INT16_C(   395), -INT16_C(   145),  INT16_C(   916) } },
    { { SIMDE_FLOAT16_VALUE(   875.00), SIMDE_FLOAT16_VALUE(  -104.69), SIMDE_FLOAT16_VALUE(   135.25), SIMDE_FLOAT16_VALUE(   727.50),
        SIMDE_FLOAT16_VALUE(   698.50), SIMDE_FLOAT16_VALUE(   839.00), SIMDE_FLOAT16_VALUE(   435.75), SIMDE_FLOAT16_VALUE(     7.73) },
      {  INT16_C(   875), -INT16_C(   104),  INT16_C(   135),  INT16_C(   727),  INT16_C(   698),  INT16_C(   839),  INT16_C(   435),  INT16_C(     7) } },
    { { SIMDE_FLOAT16_VALUE(   725.50), SIMDE_FLOAT16_VALUE(  -883.50), SIMDE_FLOAT16_VALUE(   -38.53), SIMDE_FLOAT16_VALUE(   -14.96),
        SIMDE_FLOAT16_VALUE(  -605.50), SIMDE_FLOAT16_VALUE(  -266.00), SIMDE_FLOAT16_VALUE(  -915.00), SIMDE_FLOAT16_VALUE(  -227.38) },
      {  INT16_C(   725), -INT16_C(   883), -INT16_C(    38), -INT16_C(    14), -INT16_C(   605), -INT16_C(   266), -INT16_C(   915), -INT16_C(   227) } },
    { { SIMDE_FLOAT16_VALUE(  -535.00), SIMDE_FLOAT16_VALUE(  -155.38), SIMDE_FLOAT16_VALUE(  -115.19), SIMDE_FLOAT16_VALUE(   609.50),
        SIMDE_FLOAT16_VALUE(   656.00), SIMDE_FLOAT16_VALUE(  -740.50), SIMDE_FLOAT16_VALUE(  -332.50), SIMDE_FLOAT16_VALUE(   287.50) },
      { -INT16_C(   535), -INT16_C(   155), -INT16_C(   115),  INT16_C(   609),  INT16_C(   656), -INT16_C(   740), -INT16_C(   332),  INT16_C(   287) } },
    { { SIMDE_FLOAT16_VALUE(  -943.00), SIMDE_FLOAT16_VALUE(   423.75), SIMDE_FLOAT16_VALUE(  -567.50), SIMDE_FLOAT16_VALUE(  -790.50),
        SIMDE_FLOAT16_VALUE(  -972.00), SIMDE_FLOAT16_VALUE(   286.50), SIMDE_FLOAT16_VALUE(  -874.00), SIMDE_FLOAT16_VALUE(   903.00) },
      { -INT16_C(   943),  INT16_C(   423), -INT16_C(   567), -INT16_C(   790), -INT16_C(   972),  INT16_C(   286), -INT16_C(   874),  INT16_C(   903) } },
    { { SIMDE_FLOAT16_VALUE(  -818.00), SIMDE_FLOAT16_VALUE(   261.25), SIMDE_FLOAT16_VALUE(   630.50), SIMDE_FLOAT16_VALUE(   880.50),
        SIMDE_FLOAT16_VALUE(   100.44), SIMDE_FLOAT16_VALUE(    66.19), SIMDE_FLOAT16_VALUE(  -111.75), SIMDE_FLOAT16_VALUE(  -173.88) },
      { -INT16_C(   818),  INT16_C(   261),  INT16_C(   630),  INT16_C(   880),  INT16_C(   100),  INT16_C(    66), -INT16_C(   111), -INT16_C(   173) } }    
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x8_t a = simde_vld1q_f16(test_vec[i].a);
    simde_int16x8_t r = simde_vcvtq_s16_f16(a);
    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16x8_t a = simde_test_arm_neon_random_f16x8(-1000.0f, 1000.0f);
    simde_int16x8_t r = simde_vcvtq_s16_f16(a);

    simde_test_arm_neon_write_f16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
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
test_simde_vcvtq_u16_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16 a[8];
    uint16_t r[8];
  } test_vec[] = {
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
      { { SIMDE_FLOAT16_VALUE(   -30.81), SIMDE_FLOAT16_VALUE(    29.19), SIMDE_FLOAT16_VALUE(  -867.50), SIMDE_FLOAT16_VALUE(   968.50),
          SIMDE_FLOAT16_VALUE(   624.50), SIMDE_FLOAT16_VALUE(  -223.62), SIMDE_FLOAT16_VALUE(   875.00), SIMDE_FLOAT16_VALUE(  -341.00) },
        { UINT16_C(    0), UINT16_C(   29), UINT16_C(    0), UINT16_C(  968), UINT16_C(  624), UINT16_C(    0), UINT16_C(  875), UINT16_C(    0) } },
      { { SIMDE_FLOAT16_VALUE(   -88.00), SIMDE_FLOAT16_VALUE(   -72.25), SIMDE_FLOAT16_VALUE(   860.00), SIMDE_FLOAT16_VALUE(  -702.00),
          SIMDE_FLOAT16_VALUE(   153.12), SIMDE_FLOAT16_VALUE(  -930.00), SIMDE_FLOAT16_VALUE(  -692.50), SIMDE_FLOAT16_VALUE(   928.50) },
        { UINT16_C(    0), UINT16_C(    0), UINT16_C(  860), UINT16_C(    0), UINT16_C(  153), UINT16_C(    0), UINT16_C(    0), UINT16_C(  928) } },
    #endif
    { { SIMDE_FLOAT16_VALUE(   821.00), SIMDE_FLOAT16_VALUE(   969.00), SIMDE_FLOAT16_VALUE(   726.00), SIMDE_FLOAT16_VALUE(   631.50),
        SIMDE_FLOAT16_VALUE(   153.75), SIMDE_FLOAT16_VALUE(   778.00), SIMDE_FLOAT16_VALUE(    77.06), SIMDE_FLOAT16_VALUE(   815.00) },
      { UINT16_C(  821), UINT16_C(  969), UINT16_C(  726), UINT16_C(  631), UINT16_C(  153), UINT16_C(  778), UINT16_C(   77), UINT16_C(  815) } },
    { { SIMDE_FLOAT16_VALUE(   625.00), SIMDE_FLOAT16_VALUE(   984.00), SIMDE_FLOAT16_VALUE(   298.00), SIMDE_FLOAT16_VALUE(   493.00),
        SIMDE_FLOAT16_VALUE(   926.50), SIMDE_FLOAT16_VALUE(   626.50), SIMDE_FLOAT16_VALUE(   730.50), SIMDE_FLOAT16_VALUE(   913.00) },
      { UINT16_C(  625), UINT16_C(  984), UINT16_C(  298), UINT16_C(  493), UINT16_C(  926), UINT16_C(  626), UINT16_C(  730), UINT16_C(  913) } },
    { { SIMDE_FLOAT16_VALUE(    29.12), SIMDE_FLOAT16_VALUE(   162.00), SIMDE_FLOAT16_VALUE(   816.00), SIMDE_FLOAT16_VALUE(    81.75),
        SIMDE_FLOAT16_VALUE(   954.50), SIMDE_FLOAT16_VALUE(   541.50), SIMDE_FLOAT16_VALUE(   425.50), SIMDE_FLOAT16_VALUE(    54.72) },
      { UINT16_C(   29), UINT16_C(  162), UINT16_C(  816), UINT16_C(   81), UINT16_C(  954), UINT16_C(  541), UINT16_C(  425), UINT16_C(   54) } },
    { { SIMDE_FLOAT16_VALUE(   252.62), SIMDE_FLOAT16_VALUE(   320.75), SIMDE_FLOAT16_VALUE(   262.50), SIMDE_FLOAT16_VALUE(   497.25),
        SIMDE_FLOAT16_VALUE(    23.61), SIMDE_FLOAT16_VALUE(   752.00), SIMDE_FLOAT16_VALUE(   131.12), SIMDE_FLOAT16_VALUE(   844.50) },
      { UINT16_C(  252), UINT16_C(  320), UINT16_C(  262), UINT16_C(  497), UINT16_C(   23), UINT16_C(  752), UINT16_C(  131), UINT16_C(  844) } },
    { { SIMDE_FLOAT16_VALUE(   721.00), SIMDE_FLOAT16_VALUE(   857.00), SIMDE_FLOAT16_VALUE(   476.25), SIMDE_FLOAT16_VALUE(   874.50),
        SIMDE_FLOAT16_VALUE(   635.00), SIMDE_FLOAT16_VALUE(   553.50), SIMDE_FLOAT16_VALUE(   690.00), SIMDE_FLOAT16_VALUE(   260.00) },
      { UINT16_C(  721), UINT16_C(  857), UINT16_C(  476), UINT16_C(  874), UINT16_C(  635), UINT16_C(  553), UINT16_C(  690), UINT16_C(  260) } },
    { { SIMDE_FLOAT16_VALUE(   537.00), SIMDE_FLOAT16_VALUE(   988.00), SIMDE_FLOAT16_VALUE(   753.00), SIMDE_FLOAT16_VALUE(   463.75),
        SIMDE_FLOAT16_VALUE(   614.50), SIMDE_FLOAT16_VALUE(   483.25), SIMDE_FLOAT16_VALUE(   376.50), SIMDE_FLOAT16_VALUE(   643.50) },
      { UINT16_C(  537), UINT16_C(  988), UINT16_C(  753), UINT16_C(  463), UINT16_C(  614), UINT16_C(  483), UINT16_C(  376), UINT16_C(  643) } },
    { { SIMDE_FLOAT16_VALUE(   645.50), SIMDE_FLOAT16_VALUE(   192.38), SIMDE_FLOAT16_VALUE(   725.50), SIMDE_FLOAT16_VALUE(   599.50),
        SIMDE_FLOAT16_VALUE(   734.00), SIMDE_FLOAT16_VALUE(   150.88), SIMDE_FLOAT16_VALUE(   654.50), SIMDE_FLOAT16_VALUE(   987.00) },
      { UINT16_C(  645), UINT16_C(  192), UINT16_C(  725), UINT16_C(  599), UINT16_C(  734), UINT16_C(  150), UINT16_C(  654), UINT16_C(  987) } },
    { { SIMDE_FLOAT16_VALUE(   471.75), SIMDE_FLOAT16_VALUE(   917.00), SIMDE_FLOAT16_VALUE(   484.00), SIMDE_FLOAT16_VALUE(   495.25),
        SIMDE_FLOAT16_VALUE(   669.00), SIMDE_FLOAT16_VALUE(   615.00), SIMDE_FLOAT16_VALUE(   340.00), SIMDE_FLOAT16_VALUE(   389.75) },
      { UINT16_C(  471), UINT16_C(  917), UINT16_C(  484), UINT16_C(  495), UINT16_C(  669), UINT16_C(  615), UINT16_C(  340), UINT16_C(  389) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x8_t a = simde_vld1q_f16(test_vec[i].a);
    simde_uint16x8_t r = simde_vcvtq_u16_f16(a);
    simde_test_arm_neon_assert_equal_u16x8(r, simde_vld1q_u16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16x8_t a = simde_test_arm_neon_random_f16x8(0.0f, 1000.0f);
    simde_uint16x8_t r = simde_vcvtq_u16_f16(a);

    simde_test_arm_neon_write_f16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
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
test_simde_vcvt_f16_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int16_t a[4];
    simde_float16 r[4];
  } test_vec[] = {
    { { -INT16_C( 31359), -INT16_C(  6060), -INT16_C(  9227),  INT16_C(  4133) },
      { SIMDE_FLOAT16_VALUE(-31360.00), SIMDE_FLOAT16_VALUE( -6060.00), SIMDE_FLOAT16_VALUE( -9224.00), SIMDE_FLOAT16_VALUE(  4132.00) } },
    { { -INT16_C( 17421),  INT16_C( 21634),  INT16_C( 18391), -INT16_C(  9695) },
      { SIMDE_FLOAT16_VALUE(-17424.00), SIMDE_FLOAT16_VALUE( 21632.00), SIMDE_FLOAT16_VALUE( 18384.00), SIMDE_FLOAT16_VALUE( -9696.00) } },
    { { -INT16_C( 18311), -INT16_C( 27399),  INT16_C(   497),  INT16_C( 25119) },
      { SIMDE_FLOAT16_VALUE(-18304.00), SIMDE_FLOAT16_VALUE(-27392.00), SIMDE_FLOAT16_VALUE(   497.00), SIMDE_FLOAT16_VALUE( 25120.00) } },
    { {  INT16_C( 16007), -INT16_C(  5610),  INT16_C( 21305), -INT16_C( 17667) },
      { SIMDE_FLOAT16_VALUE( 16008.00), SIMDE_FLOAT16_VALUE( -5608.00), SIMDE_FLOAT16_VALUE( 21312.00), SIMDE_FLOAT16_VALUE(-17664.00) } },
    { {  INT16_C( 20952), -INT16_C( 12638), -INT16_C( 14292),  INT16_C(  8414) },
      { SIMDE_FLOAT16_VALUE( 20960.00), SIMDE_FLOAT16_VALUE(-12640.00), SIMDE_FLOAT16_VALUE(-14288.00), SIMDE_FLOAT16_VALUE(  8416.00) } },
    { {  INT16_C( 24707),  INT16_C( 23156), -INT16_C( 27225),  INT16_C(  8500) },
      { SIMDE_FLOAT16_VALUE( 24704.00), SIMDE_FLOAT16_VALUE( 23152.00), SIMDE_FLOAT16_VALUE(-27232.00), SIMDE_FLOAT16_VALUE(  8496.00) } },
    { {  INT16_C( 11597),  INT16_C( 16053), -INT16_C( 11218), -INT16_C( 18784) },
      { SIMDE_FLOAT16_VALUE( 11600.00), SIMDE_FLOAT16_VALUE( 16056.00), SIMDE_FLOAT16_VALUE(-11216.00), SIMDE_FLOAT16_VALUE(-18784.00) } },
    { { -INT16_C( 18926),  INT16_C( 19360), -INT16_C( 25335), -INT16_C(  7674) },
      { SIMDE_FLOAT16_VALUE(-18928.00), SIMDE_FLOAT16_VALUE( 19360.00), SIMDE_FLOAT16_VALUE(-25328.00), SIMDE_FLOAT16_VALUE( -7672.00) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t a = simde_vld1_s16(test_vec[i].a);
    simde_float16x4_t r = simde_vcvt_f16_s16(a);

    simde_test_arm_neon_assert_equal_f16x4(r, simde_vld1_f16(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x4_t a = simde_test_arm_neon_random_i16x4();
    simde_float16x4_t r = simde_vcvt_f16_s16(a);

    simde_test_arm_neon_write_i16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
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
test_simde_vcvt_f16_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint16_t a[4];
    simde_float16 r[4];
  } test_vec[] = {
    { { UINT16_C(62438), UINT16_C(34514), UINT16_C(11502), UINT16_C(61024) },
      { SIMDE_FLOAT16_VALUE( 62432.00), SIMDE_FLOAT16_VALUE( 34528.00), SIMDE_FLOAT16_VALUE( 11504.00), SIMDE_FLOAT16_VALUE( 61024.00) } },
    { { UINT16_C(12845), UINT16_C(46535), UINT16_C(26251), UINT16_C(44421) },
      { SIMDE_FLOAT16_VALUE( 12848.00), SIMDE_FLOAT16_VALUE( 46528.00), SIMDE_FLOAT16_VALUE( 26256.00), SIMDE_FLOAT16_VALUE( 44416.00) } },
    { { UINT16_C(34839), UINT16_C(13721), UINT16_C(21960), UINT16_C(60620) },
      { SIMDE_FLOAT16_VALUE( 34848.00), SIMDE_FLOAT16_VALUE( 13720.00), SIMDE_FLOAT16_VALUE( 21952.00), SIMDE_FLOAT16_VALUE( 60608.00) } },
    { { UINT16_C(12061), UINT16_C(53316), UINT16_C(51121), UINT16_C(38694) },
      { SIMDE_FLOAT16_VALUE( 12064.00), SIMDE_FLOAT16_VALUE( 53312.00), SIMDE_FLOAT16_VALUE( 51136.00), SIMDE_FLOAT16_VALUE( 38688.00) } },
    { { UINT16_C(63674), UINT16_C(43038), UINT16_C(32293), UINT16_C(21142) },
      { SIMDE_FLOAT16_VALUE( 63680.00), SIMDE_FLOAT16_VALUE( 43040.00), SIMDE_FLOAT16_VALUE( 32288.00), SIMDE_FLOAT16_VALUE( 21136.00) } },
    { { UINT16_C(24240), UINT16_C(15111), UINT16_C(36292), UINT16_C(56297) },
      { SIMDE_FLOAT16_VALUE( 24240.00), SIMDE_FLOAT16_VALUE( 15112.00), SIMDE_FLOAT16_VALUE( 36288.00), SIMDE_FLOAT16_VALUE( 56288.00) } },
    { { UINT16_C(33301), UINT16_C(56593), UINT16_C(56792), UINT16_C(62922) },
      { SIMDE_FLOAT16_VALUE( 33312.00), SIMDE_FLOAT16_VALUE( 56608.00), SIMDE_FLOAT16_VALUE( 56800.00), SIMDE_FLOAT16_VALUE( 62912.00) } },
    { { UINT16_C( 3596), UINT16_C(48838), UINT16_C(60629), UINT16_C(36949) },
      { SIMDE_FLOAT16_VALUE(  3596.00), SIMDE_FLOAT16_VALUE( 48832.00), SIMDE_FLOAT16_VALUE( 60640.00), SIMDE_FLOAT16_VALUE( 36960.00) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4_t a = simde_vld1_u16(test_vec[i].a);
    simde_float16x4_t r = simde_vcvt_f16_u16(a);

    simde_test_arm_neon_assert_equal_f16x4(r, simde_vld1_f16(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x4_t a = simde_test_arm_neon_random_u16x4();
    simde_float16x4_t r = simde_vcvt_f16_u16(a);

    simde_test_arm_neon_write_u16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
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
test_simde_vcvtq_f16_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int16_t a[8];
    simde_float16 r[8];
  } test_vec[] = {
     { {  INT16_C( 30695),  INT16_C(  2044), -INT16_C( 17659), -INT16_C( 13466), -INT16_C(  7782), -INT16_C( 26595),  INT16_C( 28844),  INT16_C(  8813) },
      { SIMDE_FLOAT16_VALUE( 30688.00), SIMDE_FLOAT16_VALUE(  2044.00), SIMDE_FLOAT16_VALUE(-17664.00), SIMDE_FLOAT16_VALUE(-13464.00),
        SIMDE_FLOAT16_VALUE( -7784.00), SIMDE_FLOAT16_VALUE(-26592.00), SIMDE_FLOAT16_VALUE( 28848.00), SIMDE_FLOAT16_VALUE(  8816.00) } },
    { { -INT16_C( 23007),  INT16_C( 14781), -INT16_C( 26182), -INT16_C( 15014),  INT16_C( 16220),  INT16_C( 16254), -INT16_C(  2052), -INT16_C(  7328) },
      { SIMDE_FLOAT16_VALUE(-23008.00), SIMDE_FLOAT16_VALUE( 14784.00), SIMDE_FLOAT16_VALUE(-26176.00), SIMDE_FLOAT16_VALUE(-15016.00),
        SIMDE_FLOAT16_VALUE( 16224.00), SIMDE_FLOAT16_VALUE( 16256.00), SIMDE_FLOAT16_VALUE( -2052.00), SIMDE_FLOAT16_VALUE( -7328.00) } },
    { {  INT16_C( 23919),  INT16_C( 29930),  INT16_C( 20504), -INT16_C( 19904),  INT16_C( 23857), -INT16_C(  8886), -INT16_C( 18483), -INT16_C(  4608) },
      { SIMDE_FLOAT16_VALUE( 23920.00), SIMDE_FLOAT16_VALUE( 29936.00), SIMDE_FLOAT16_VALUE( 20512.00), SIMDE_FLOAT16_VALUE(-19904.00),
        SIMDE_FLOAT16_VALUE( 23856.00), SIMDE_FLOAT16_VALUE( -8888.00), SIMDE_FLOAT16_VALUE(-18480.00), SIMDE_FLOAT16_VALUE( -4608.00) } },
    { { -INT16_C( 17058),  INT16_C(  6184), -INT16_C( 32170), -INT16_C( 19491),  INT16_C( 23745), -INT16_C( 16910),  INT16_C( 21075), -INT16_C( 15712) },
      { SIMDE_FLOAT16_VALUE(-17056.00), SIMDE_FLOAT16_VALUE(  6184.00), SIMDE_FLOAT16_VALUE(-32176.00), SIMDE_FLOAT16_VALUE(-19488.00),
        SIMDE_FLOAT16_VALUE( 23744.00), SIMDE_FLOAT16_VALUE(-16912.00), SIMDE_FLOAT16_VALUE( 21072.00), SIMDE_FLOAT16_VALUE(-15712.00) } },
    { { -INT16_C( 30033), -INT16_C( 14537),  INT16_C( 30683),  INT16_C(  3194), -INT16_C( 15148), -INT16_C( 24086), -INT16_C(  5508), -INT16_C(  9585) },
      { SIMDE_FLOAT16_VALUE(-30032.00), SIMDE_FLOAT16_VALUE(-14536.00), SIMDE_FLOAT16_VALUE( 30688.00), SIMDE_FLOAT16_VALUE(  3194.00),
        SIMDE_FLOAT16_VALUE(-15152.00), SIMDE_FLOAT16_VALUE(-24080.00), SIMDE_FLOAT16_VALUE( -5508.00), SIMDE_FLOAT16_VALUE( -9584.00) } },
    { { -INT16_C( 18521), -INT16_C(   526), -INT16_C( 12231), -INT16_C(  1360), -INT16_C( 24020),  INT16_C( 32695),  INT16_C( 22517), -INT16_C( 23486) },
      { SIMDE_FLOAT16_VALUE(-18528.00), SIMDE_FLOAT16_VALUE(  -526.00), SIMDE_FLOAT16_VALUE(-12232.00), SIMDE_FLOAT16_VALUE( -1360.00),
        SIMDE_FLOAT16_VALUE(-24016.00), SIMDE_FLOAT16_VALUE( 32688.00), SIMDE_FLOAT16_VALUE( 22512.00), SIMDE_FLOAT16_VALUE(-23488.00) } },
    { {  INT16_C( 31202), -INT16_C( 17044), -INT16_C(  6416), -INT16_C( 15159), -INT16_C( 19542),  INT16_C(  9829), -INT16_C(  2915),  INT16_C( 17408) },
      { SIMDE_FLOAT16_VALUE( 31200.00), SIMDE_FLOAT16_VALUE(-17040.00), SIMDE_FLOAT16_VALUE( -6416.00), SIMDE_FLOAT16_VALUE(-15160.00),
        SIMDE_FLOAT16_VALUE(-19536.00), SIMDE_FLOAT16_VALUE(  9832.00), SIMDE_FLOAT16_VALUE( -2916.00), SIMDE_FLOAT16_VALUE( 17408.00) } },
    { { -INT16_C(  3156), -INT16_C(  6846), -INT16_C(  3389), -INT16_C(  4128), -INT16_C( 26731), -INT16_C( 30098), -INT16_C( 20241), -INT16_C( 11986) },
      { SIMDE_FLOAT16_VALUE( -3156.00), SIMDE_FLOAT16_VALUE( -6848.00), SIMDE_FLOAT16_VALUE( -3388.00), SIMDE_FLOAT16_VALUE( -4128.00),
        SIMDE_FLOAT16_VALUE(-26736.00), SIMDE_FLOAT16_VALUE(-30096.00), SIMDE_FLOAT16_VALUE(-20240.00), SIMDE_FLOAT16_VALUE(-11984.00) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_float16x8_t r = simde_vcvtq_f16_s16(a);

    simde_test_arm_neon_assert_equal_f16x8(r, simde_vld1q_f16(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x8_t a = simde_test_arm_neon_random_i16x8();
    simde_float16x8_t r = simde_vcvtq_f16_s16(a);

    simde_test_arm_neon_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
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
test_simde_vcvtq_f16_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint16_t a[8];
    simde_float16 r[8];
  } test_vec[] = {
    { { UINT16_C(31719), UINT16_C(40615), UINT16_C(25989), UINT16_C(34272), UINT16_C(12352), UINT16_C(55680), UINT16_C(60433), UINT16_C(10783) },
      { SIMDE_FLOAT16_VALUE( 31712.00), SIMDE_FLOAT16_VALUE( 40608.00), SIMDE_FLOAT16_VALUE( 25984.00), SIMDE_FLOAT16_VALUE( 34272.00),
        SIMDE_FLOAT16_VALUE( 12352.00), SIMDE_FLOAT16_VALUE( 55680.00), SIMDE_FLOAT16_VALUE( 60448.00), SIMDE_FLOAT16_VALUE( 10784.00) } },
    { { UINT16_C( 5224), UINT16_C(60599), UINT16_C(11648), UINT16_C(19599), UINT16_C( 3068), UINT16_C(27332), UINT16_C(15393), UINT16_C( 2080) },
      { SIMDE_FLOAT16_VALUE(  5224.00), SIMDE_FLOAT16_VALUE( 60608.00), SIMDE_FLOAT16_VALUE( 11648.00), SIMDE_FLOAT16_VALUE( 19600.00),
        SIMDE_FLOAT16_VALUE(  3068.00), SIMDE_FLOAT16_VALUE( 27328.00), SIMDE_FLOAT16_VALUE( 15392.00), SIMDE_FLOAT16_VALUE(  2080.00) } },
    { { UINT16_C(51383), UINT16_C(15782), UINT16_C(34605), UINT16_C(28354), UINT16_C(17079), UINT16_C(51271), UINT16_C(26158), UINT16_C(38642) },
      { SIMDE_FLOAT16_VALUE( 51392.00), SIMDE_FLOAT16_VALUE( 15784.00), SIMDE_FLOAT16_VALUE( 34592.00), SIMDE_FLOAT16_VALUE( 28352.00),
        SIMDE_FLOAT16_VALUE( 17072.00), SIMDE_FLOAT16_VALUE( 51264.00), SIMDE_FLOAT16_VALUE( 26160.00), SIMDE_FLOAT16_VALUE( 38656.00) } },
    { { UINT16_C(43387), UINT16_C(64386), UINT16_C( 4822), UINT16_C(53831), UINT16_C( 2845), UINT16_C(15932), UINT16_C(23623), UINT16_C(65351) },
      { SIMDE_FLOAT16_VALUE( 43392.00), SIMDE_FLOAT16_VALUE( 64384.00), SIMDE_FLOAT16_VALUE(  4824.00), SIMDE_FLOAT16_VALUE( 53824.00),
        SIMDE_FLOAT16_VALUE(  2844.00), SIMDE_FLOAT16_VALUE( 15936.00), SIMDE_FLOAT16_VALUE( 23616.00), SIMDE_FLOAT16_VALUE( 65344.00) } },
    { { UINT16_C(60708), UINT16_C(21052), UINT16_C(65140), UINT16_C(11200), UINT16_C( 1856), UINT16_C(28659), UINT16_C(58734), UINT16_C(59653) },
      { SIMDE_FLOAT16_VALUE( 60704.00), SIMDE_FLOAT16_VALUE( 21056.00), SIMDE_FLOAT16_VALUE( 65152.00), SIMDE_FLOAT16_VALUE( 11200.00),
        SIMDE_FLOAT16_VALUE(  1856.00), SIMDE_FLOAT16_VALUE( 28656.00), SIMDE_FLOAT16_VALUE( 58720.00), SIMDE_FLOAT16_VALUE( 59648.00) } },
    { { UINT16_C(34958), UINT16_C(25828), UINT16_C(11162), UINT16_C(46902), UINT16_C(29238), UINT16_C(32245), UINT16_C(15567), UINT16_C(62332) },
      { SIMDE_FLOAT16_VALUE( 34944.00), SIMDE_FLOAT16_VALUE( 25824.00), SIMDE_FLOAT16_VALUE( 11160.00), SIMDE_FLOAT16_VALUE( 46912.00),
        SIMDE_FLOAT16_VALUE( 29232.00), SIMDE_FLOAT16_VALUE( 32240.00), SIMDE_FLOAT16_VALUE( 15568.00), SIMDE_FLOAT16_VALUE( 62336.00) } },
    { { UINT16_C(47146), UINT16_C(40517), UINT16_C( 1462), UINT16_C(63434), UINT16_C(48397), UINT16_C(31590), UINT16_C(27555), UINT16_C(12644) },
      { SIMDE_FLOAT16_VALUE( 47136.00), SIMDE_FLOAT16_VALUE( 40512.00), SIMDE_FLOAT16_VALUE(  1462.00), SIMDE_FLOAT16_VALUE( 63424.00),
        SIMDE_FLOAT16_VALUE( 48384.00), SIMDE_FLOAT16_VALUE( 31584.00), SIMDE_FLOAT16_VALUE( 27552.00), SIMDE_FLOAT16_VALUE( 12640.00) } },
    { { UINT16_C(18675), UINT16_C(36246), UINT16_C(52339), UINT16_C(43332), UINT16_C(14911), UINT16_C( 3622), UINT16_C(41846), UINT16_C(40961) },
      { SIMDE_FLOAT16_VALUE( 18672.00), SIMDE_FLOAT16_VALUE( 36256.00), SIMDE_FLOAT16_VALUE( 52352.00), SIMDE_FLOAT16_VALUE( 43328.00),
        SIMDE_FLOAT16_VALUE( 14912.00), SIMDE_FLOAT16_VALUE(  3622.00), SIMDE_FLOAT16_VALUE( 41856.00), SIMDE_FLOAT16_VALUE( 40960.00) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);
    simde_float16x8_t r = simde_vcvtq_f16_u16(a);

    simde_test_arm_neon_assert_equal_f16x8(r, simde_vld1q_f16(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x8_t a = simde_test_arm_neon_random_u16x8();
    simde_float16x8_t r = simde_vcvtq_f16_u16(a);

    simde_test_arm_neon_write_u16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
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


static int
test_simde_vcvt_f16_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float32 a[4];
    simde_float16 r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -746.01), SIMDE_FLOAT32_C(    46.71), SIMDE_FLOAT32_C(   209.49), SIMDE_FLOAT32_C(  -407.21) },
      { SIMDE_FLOAT16_VALUE(  -746.00), SIMDE_FLOAT16_VALUE(    46.72), SIMDE_FLOAT16_VALUE(   209.50), SIMDE_FLOAT16_VALUE(  -407.25) } },
    { { SIMDE_FLOAT32_C(  -250.56), SIMDE_FLOAT32_C(  -515.50), SIMDE_FLOAT32_C(  -893.59), SIMDE_FLOAT32_C(  -958.74) },
      { SIMDE_FLOAT16_VALUE(  -250.50), SIMDE_FLOAT16_VALUE(  -515.50), SIMDE_FLOAT16_VALUE(  -893.50), SIMDE_FLOAT16_VALUE(  -958.50) } },
    { { SIMDE_FLOAT32_C(   290.93), SIMDE_FLOAT32_C(  -154.97), SIMDE_FLOAT32_C(  -692.78), SIMDE_FLOAT32_C(   121.78) },
      { SIMDE_FLOAT16_VALUE(   291.00), SIMDE_FLOAT16_VALUE(  -155.00), SIMDE_FLOAT16_VALUE(  -693.00), SIMDE_FLOAT16_VALUE(   121.75) } },
    { { SIMDE_FLOAT32_C(   544.06), SIMDE_FLOAT32_C(  -720.37), SIMDE_FLOAT32_C(   529.59), SIMDE_FLOAT32_C(   595.99) },
      { SIMDE_FLOAT16_VALUE(   544.00), SIMDE_FLOAT16_VALUE(  -720.50), SIMDE_FLOAT16_VALUE(   529.50), SIMDE_FLOAT16_VALUE(   596.00) } },
    { { SIMDE_FLOAT32_C(   724.87), SIMDE_FLOAT32_C(  -105.71), SIMDE_FLOAT32_C(   -64.08), SIMDE_FLOAT32_C(   347.70) },
      { SIMDE_FLOAT16_VALUE(   725.00), SIMDE_FLOAT16_VALUE(  -105.69), SIMDE_FLOAT16_VALUE(   -64.06), SIMDE_FLOAT16_VALUE(   347.75) } },
    { { SIMDE_FLOAT32_C(  -299.90), SIMDE_FLOAT32_C(   477.20), SIMDE_FLOAT32_C(   358.42), SIMDE_FLOAT32_C(  -777.66) },
      { SIMDE_FLOAT16_VALUE(  -300.00), SIMDE_FLOAT16_VALUE(   477.25), SIMDE_FLOAT16_VALUE(   358.50), SIMDE_FLOAT16_VALUE(  -777.50) } },
    { { SIMDE_FLOAT32_C(  -829.48), SIMDE_FLOAT32_C(  -168.37), SIMDE_FLOAT32_C(  -205.50), SIMDE_FLOAT32_C(  -615.00) },
      { SIMDE_FLOAT16_VALUE(  -829.50), SIMDE_FLOAT16_VALUE(  -168.38), SIMDE_FLOAT16_VALUE(  -205.50), SIMDE_FLOAT16_VALUE(  -615.00) } },
    { { SIMDE_FLOAT32_C(  -491.32), SIMDE_FLOAT32_C(   717.47), SIMDE_FLOAT32_C(  -341.53), SIMDE_FLOAT32_C(  -237.33) },
      { SIMDE_FLOAT16_VALUE(  -491.25), SIMDE_FLOAT16_VALUE(   717.50), SIMDE_FLOAT16_VALUE(  -341.50), SIMDE_FLOAT16_VALUE(  -237.38) } }    
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_float16x4_t r = simde_vcvt_f16_f32(a);

    simde_test_arm_neon_assert_equal_f16x4(r, simde_vld1_f16(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x4_t a = simde_test_arm_neon_random_f32x4(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde_float16x4_t r = simde_vcvt_f16_f32(a);

    simde_test_arm_neon_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvt_f32_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 a[2];
    simde_float32 r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(  -475.38), SIMDE_FLOAT64_C(   886.87) },
      { SIMDE_FLOAT32_C(  -475.38), SIMDE_FLOAT32_C(   886.87) } },
    { { SIMDE_FLOAT64_C(  -793.59), SIMDE_FLOAT64_C(   367.52) },
      { SIMDE_FLOAT32_C(  -793.59), SIMDE_FLOAT32_C(   367.52) } },
    { { SIMDE_FLOAT64_C(   983.13), SIMDE_FLOAT64_C(   575.97) },
      { SIMDE_FLOAT32_C(   983.13), SIMDE_FLOAT32_C(   575.97) } },
    { { SIMDE_FLOAT64_C(   956.07), SIMDE_FLOAT64_C(   657.42) },
      { SIMDE_FLOAT32_C(   956.07), SIMDE_FLOAT32_C(   657.42) } },
    { { SIMDE_FLOAT64_C(  -938.85), SIMDE_FLOAT64_C(  -480.84) },
      { SIMDE_FLOAT32_C(  -938.85), SIMDE_FLOAT32_C(  -480.84) } },
    { { SIMDE_FLOAT64_C(  -623.90), SIMDE_FLOAT64_C(   584.54) },
      { SIMDE_FLOAT32_C(  -623.90), SIMDE_FLOAT32_C(   584.54) } },
    { { SIMDE_FLOAT64_C(   337.24), SIMDE_FLOAT64_C(   283.98) },
      { SIMDE_FLOAT32_C(   337.24), SIMDE_FLOAT32_C(   283.98) } },
    { { SIMDE_FLOAT64_C(  -235.16), SIMDE_FLOAT64_C(  -429.01) },
      { SIMDE_FLOAT32_C(  -235.16), SIMDE_FLOAT32_C(  -429.01) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2_t a = simde_vld1q_f64(test_vec[i].a);
    simde_float32x2_t r = simde_vcvt_f32_f64(a);
    simde_test_arm_neon_assert_equal_f32x2(r, simde_vld1_f32(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x2_t a = simde_test_arm_neon_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde_float32x2_t r = simde_vcvt_f32_f64(a);

    simde_test_arm_neon_write_f64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvt_f64_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a[2];
    simde_float64 r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   -80.80), SIMDE_FLOAT32_C(   420.29) },
      { SIMDE_FLOAT64_C(   -80.80), SIMDE_FLOAT64_C(   420.29) } },
    { { SIMDE_FLOAT32_C(  -189.50), SIMDE_FLOAT32_C(   938.42) },
      { SIMDE_FLOAT64_C(  -189.50), SIMDE_FLOAT64_C(   938.42) } },
    { { SIMDE_FLOAT32_C(   592.79), SIMDE_FLOAT32_C(   535.92) },
      { SIMDE_FLOAT64_C(   592.79), SIMDE_FLOAT64_C(   535.92) } },
    { { SIMDE_FLOAT32_C(  -923.38), SIMDE_FLOAT32_C(    26.50) },
      { SIMDE_FLOAT64_C(  -923.38), SIMDE_FLOAT64_C(    26.50) } },
    { { SIMDE_FLOAT32_C(   809.92), SIMDE_FLOAT32_C(   305.32) },
      { SIMDE_FLOAT64_C(   809.92), SIMDE_FLOAT64_C(   305.32) } },
    { { SIMDE_FLOAT32_C(  -969.35), SIMDE_FLOAT32_C(  -734.75) },
      { SIMDE_FLOAT64_C(  -969.35), SIMDE_FLOAT64_C(  -734.75) } },
    { { SIMDE_FLOAT32_C(  -796.75), SIMDE_FLOAT32_C(  -433.35) },
      { SIMDE_FLOAT64_C(  -796.75), SIMDE_FLOAT64_C(  -433.35) } },
    { { SIMDE_FLOAT32_C(  -940.41), SIMDE_FLOAT32_C(  -742.37) },
      { SIMDE_FLOAT64_C(  -940.41), SIMDE_FLOAT64_C(  -742.37) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t a = simde_vld1_f32(test_vec[i].a);
    simde_float64x2_t r = simde_vcvt_f64_f32(a);
    simde_test_arm_neon_assert_equal_f64x2(r, simde_vld1q_f64(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x2_t a = simde_test_arm_neon_random_f32x2(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    simde_float64x2_t r = simde_vcvt_f64_f32(a);

    simde_test_arm_neon_write_f32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
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

SIMDE_TEST_FUNC_LIST_ENTRY(vcvt_s16_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvt_s32_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvt_s64_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvt_u16_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvt_u32_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvt_u64_f64)

SIMDE_TEST_FUNC_LIST_ENTRY(vcvtq_s16_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtq_s32_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtq_s64_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtq_u16_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtq_u32_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtq_u64_f64)

SIMDE_TEST_FUNC_LIST_ENTRY(vcvt_f16_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvt_f32_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvt_f64_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvt_f16_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvt_f32_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvt_f64_u64)

SIMDE_TEST_FUNC_LIST_ENTRY(vcvtq_f16_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtq_f32_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtq_f64_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtq_f16_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtq_f32_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtq_f64_u64)

SIMDE_TEST_FUNC_LIST_ENTRY(vcvt_f16_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvt_f32_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvt_f64_f32)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
