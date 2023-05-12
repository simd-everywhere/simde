#define SIMDE_TEST_ARM_NEON_INSN cvtn

#include "test-neon.h"
#include "../../../simde/arm/neon/cvtn.h"

static int
test_simde_vcvtnq_s32_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a[4];
    int32_t r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   937.55), SIMDE_FLOAT32_C(  -442.23), SIMDE_FLOAT32_C(   896.44), SIMDE_FLOAT32_C(   930.01) },
      {  INT32_C(         938), -INT32_C(         442),  INT32_C(         896),  INT32_C(         930) } },
    { { SIMDE_FLOAT32_C(  -319.80), SIMDE_FLOAT32_C(   252.60), SIMDE_FLOAT32_C(   205.86), SIMDE_FLOAT32_C(  -559.77) },
      { -INT32_C(         320),  INT32_C(         253),  INT32_C(         206), -INT32_C(         560) } },
    { { SIMDE_FLOAT32_C(   914.86), SIMDE_FLOAT32_C(   699.22), SIMDE_FLOAT32_C(  -173.52), SIMDE_FLOAT32_C(   391.53) },
      {  INT32_C(         915),  INT32_C(         699), -INT32_C(         174),  INT32_C(         392) } },
    { { SIMDE_FLOAT32_C(    58.81), SIMDE_FLOAT32_C(   718.73), SIMDE_FLOAT32_C(   230.97), SIMDE_FLOAT32_C(  -719.34) },
      {  INT32_C(          59),  INT32_C(         719),  INT32_C(         231), -INT32_C(         719) } },
    { { SIMDE_FLOAT32_C(  -812.93), SIMDE_FLOAT32_C(   906.35), SIMDE_FLOAT32_C(  -780.82), SIMDE_FLOAT32_C(  -473.14) },
      { -INT32_C(         813),  INT32_C(         906), -INT32_C(         781), -INT32_C(         473) } },
    { { SIMDE_FLOAT32_C(  -831.98), SIMDE_FLOAT32_C(  -663.52), SIMDE_FLOAT32_C(   192.11), SIMDE_FLOAT32_C(   -75.32) },
      { -INT32_C(         832), -INT32_C(         664),  INT32_C(         192), -INT32_C(          75) } },
    { { SIMDE_FLOAT32_C(  -554.55), SIMDE_FLOAT32_C(  -828.63), SIMDE_FLOAT32_C(   271.31), SIMDE_FLOAT32_C(   441.14) },
      { -INT32_C(         555), -INT32_C(         829),  INT32_C(         271),  INT32_C(         441) } },
    { { SIMDE_FLOAT32_C(  -457.34), SIMDE_FLOAT32_C(  -854.46), SIMDE_FLOAT32_C(  -408.99), SIMDE_FLOAT32_C(  -519.79) },
      { -INT32_C(         457), -INT32_C(         854), -INT32_C(         409), -INT32_C(         520) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_int32x4_t r = simde_vcvtnq_s32_f32(a);
    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x4_t a = simde_test_arm_neon_random_f32x4(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    simde_int32x4_t r = simde_vcvtnq_s32_f32(a);

    simde_test_arm_neon_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvtnq_s64_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 a[2];
    int64_t r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(   556.37), SIMDE_FLOAT64_C(   732.68) },
      {  INT64_C(                 556),  INT64_C(                 733) } },
    { { SIMDE_FLOAT64_C(    87.88), SIMDE_FLOAT64_C(   506.11) },
      {  INT64_C(                  88),  INT64_C(                 506) } },
    { { SIMDE_FLOAT64_C(   301.57), SIMDE_FLOAT64_C(   915.90) },
      {  INT64_C(                 302),  INT64_C(                 916) } },
    { { SIMDE_FLOAT64_C(  -242.49), SIMDE_FLOAT64_C(   395.94) },
      { -INT64_C(                 242),  INT64_C(                 396) } },
    { { SIMDE_FLOAT64_C(   692.53), SIMDE_FLOAT64_C(   222.49) },
      {  INT64_C(                 693),  INT64_C(                 222) } },
    { { SIMDE_FLOAT64_C(  -324.37), SIMDE_FLOAT64_C(   -14.55) },
      { -INT64_C(                 324), -INT64_C(                  15) } },
    { { SIMDE_FLOAT64_C(  -130.00), SIMDE_FLOAT64_C(   932.49) },
      { -INT64_C(                 130),  INT64_C(                 932) } },
    { { SIMDE_FLOAT64_C(   874.57), SIMDE_FLOAT64_C(   139.39) },
      {  INT64_C(                 875),  INT64_C(                 139) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2_t a = simde_vld1q_f64(test_vec[i].a);
    simde_int64x2_t r = simde_vcvtnq_s64_f64(a);
    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x2_t a = simde_test_arm_neon_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde_int64x2_t r = simde_vcvtnq_s64_f64(a);

    simde_test_arm_neon_write_f64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvtns_u32_f32 (SIMDE_MUNIT_TEST_ARGS) {
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
    { SIMDE_FLOAT32_C(   192.44),
      UINT32_C(       192) },
    { SIMDE_FLOAT32_C(   350.46),
      UINT32_C(       350) },
    { SIMDE_FLOAT32_C(   163.51),
      UINT32_C(       164) },
    { SIMDE_FLOAT32_C(   974.89),
      UINT32_C(       975) },
    { SIMDE_FLOAT32_C(   254.05),
      UINT32_C(       254) },
    { SIMDE_FLOAT32_C(   707.75),
      UINT32_C(       708) },
    { SIMDE_FLOAT32_C(   957.31),
      UINT32_C(       957) },
    { SIMDE_FLOAT32_C(   144.65),
      UINT32_C(       145) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32 a = test_vec[i].a;
    uint32_t r = simde_vcvtns_u32_f32(a);
    simde_assert_equal_u32(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32 a = simde_test_codegen_random_f32(SIMDE_FLOAT32_C(0.0), SIMDE_FLOAT32_C(1000.0));
    uint32_t r = simde_vcvtns_u32_f32(a);

    simde_test_codegen_write_f32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvtnq_u32_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a[4];
    uint32_t r[4];
  } test_vec[] = {
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
      { { HEDLEY_STATIC_CAST(simde_float32, UINT32_MAX) + SIMDE_FLOAT32_C(10000.0), SIMDE_MATH_NANF, -SIMDE_MATH_NANF, SIMDE_MATH_INFINITYF },
        {           UINT32_MAX, UINT32_C(         0), UINT32_C(         0),           UINT32_MAX } },
    #endif
    { { SIMDE_FLOAT32_C(   863.25), SIMDE_FLOAT32_C(   521.75), SIMDE_FLOAT32_C(   132.00), SIMDE_FLOAT32_C(   927.12) },
      { UINT32_C(       863), UINT32_C(       522), UINT32_C(       132), UINT32_C(       927) } },
    { { SIMDE_FLOAT32_C(   690.64), SIMDE_FLOAT32_C(   333.83), SIMDE_FLOAT32_C(   575.75), SIMDE_FLOAT32_C(   983.60) },
      { UINT32_C(       691), UINT32_C(       334), UINT32_C(       576), UINT32_C(       984) } },
    { { SIMDE_FLOAT32_C(   831.08), SIMDE_FLOAT32_C(   205.29), SIMDE_FLOAT32_C(   684.06), SIMDE_FLOAT32_C(   736.89) },
      { UINT32_C(       831), UINT32_C(       205), UINT32_C(       684), UINT32_C(       737) } },
    { { SIMDE_FLOAT32_C(   661.06), SIMDE_FLOAT32_C(   884.25), SIMDE_FLOAT32_C(   430.96), SIMDE_FLOAT32_C(   106.96) },
      { UINT32_C(       661), UINT32_C(       884), UINT32_C(       431), UINT32_C(       107) } },
    { { SIMDE_FLOAT32_C(   357.41), SIMDE_FLOAT32_C(   783.43), SIMDE_FLOAT32_C(   343.44), SIMDE_FLOAT32_C(   955.87) },
      { UINT32_C(       357), UINT32_C(       783), UINT32_C(       343), UINT32_C(       956) } },
    { { SIMDE_FLOAT32_C(   228.77), SIMDE_FLOAT32_C(   941.05), SIMDE_FLOAT32_C(   191.46), SIMDE_FLOAT32_C(   570.38) },
      { UINT32_C(       229), UINT32_C(       941), UINT32_C(       191), UINT32_C(       570) } },
    { { SIMDE_FLOAT32_C(    43.44), SIMDE_FLOAT32_C(   915.55), SIMDE_FLOAT32_C(   889.23), SIMDE_FLOAT32_C(   920.11) },
      { UINT32_C(        43), UINT32_C(       916), UINT32_C(       889), UINT32_C(       920) } },
    { { SIMDE_FLOAT32_C(   757.09), SIMDE_FLOAT32_C(   518.32), SIMDE_FLOAT32_C(   144.42), SIMDE_FLOAT32_C(   620.34) },
      { UINT32_C(       757), UINT32_C(       518), UINT32_C(       144), UINT32_C(       620) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_uint32x4_t r = simde_vcvtnq_u32_f32(a);

    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x4_t a = simde_test_arm_neon_random_f32x4(SIMDE_FLOAT32_C(0.0), SIMDE_FLOAT32_C(1000.0));
    simde_uint32x4_t r = simde_vcvtnq_u32_f32(a);

    simde_test_arm_neon_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvtnd_u64_f64 (SIMDE_MUNIT_TEST_ARGS) {
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
    { SIMDE_FLOAT64_C(   755.50),
      UINT64_C(                 756) },
    { SIMDE_FLOAT64_C(   719.56),
      UINT64_C(                 720) },
    { SIMDE_FLOAT64_C(   939.13),
      UINT64_C(                 939) },
    { SIMDE_FLOAT64_C(   742.14),
      UINT64_C(                 742) },
    { SIMDE_FLOAT64_C(   916.64),
      UINT64_C(                 917) },
    { SIMDE_FLOAT64_C(    55.73),
      UINT64_C(                  56) },
    { SIMDE_FLOAT64_C(   511.47),
      UINT64_C(                 511) },
    { SIMDE_FLOAT64_C(   399.92),
      UINT64_C(                 400) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64 a = test_vec[i].a;
    uint64_t r = simde_vcvtnd_u64_f64(a);
    simde_assert_equal_u64(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64 a = simde_test_codegen_random_f64(SIMDE_FLOAT64_C(0.0), SIMDE_FLOAT64_C(1000.0));
    uint64_t r = simde_vcvtnd_u64_f64(a);

    simde_test_codegen_write_f64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvtnq_u64_f64 (SIMDE_MUNIT_TEST_ARGS) {
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
    { { SIMDE_FLOAT64_C(   336.84), SIMDE_FLOAT64_C(     2.42) },
      { UINT64_C(                 337), UINT64_C(                   2) } },
    { { SIMDE_FLOAT64_C(   310.98), SIMDE_FLOAT64_C(    24.59) },
      { UINT64_C(                 311), UINT64_C(                  25) } },
    { { SIMDE_FLOAT64_C(   126.05), SIMDE_FLOAT64_C(   370.97) },
      { UINT64_C(                 126), UINT64_C(                 371) } },
    { { SIMDE_FLOAT64_C(   735.41), SIMDE_FLOAT64_C(   717.89) },
      { UINT64_C(                 735), UINT64_C(                 718) } },
    { { SIMDE_FLOAT64_C(   230.06), SIMDE_FLOAT64_C(   361.94) },
      { UINT64_C(                 230), UINT64_C(                 362) } },
    { { SIMDE_FLOAT64_C(   764.21), SIMDE_FLOAT64_C(   876.68) },
      { UINT64_C(                 764), UINT64_C(                 877) } },
    { { SIMDE_FLOAT64_C(   160.32), SIMDE_FLOAT64_C(   429.74) },
      { UINT64_C(                 160), UINT64_C(                 430) } },
    { { SIMDE_FLOAT64_C(   412.40), SIMDE_FLOAT64_C(   528.57) },
      { UINT64_C(                 412), UINT64_C(                 529) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2_t a = simde_vld1q_f64(test_vec[i].a);
    simde_uint64x2_t r = simde_vcvtnq_u64_f64(a);
    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x2_t a = simde_test_arm_neon_random_f64x2(SIMDE_FLOAT64_C(0.0), SIMDE_FLOAT64_C(1000.0));
    simde_uint64x2_t r = simde_vcvtnq_u64_f64(a);

    simde_test_arm_neon_write_f64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtnq_s32_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtnq_s64_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtns_u32_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtnq_u32_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtnd_u64_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtnq_u64_f64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
