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
test_simde_vcvtnh_s64_f16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float16_t a;
    int64_t r;
  } test_vec[] = {
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
      {            SIMDE_NANHF,
        INT64_C(           0) },
      { simde_float16_from_float32(HEDLEY_STATIC_CAST(simde_float32, INT64_MAX)),
                  INT64_MAX },
      { simde_float16_from_float32(HEDLEY_STATIC_CAST(simde_float32, INT64_MIN)),
                  INT64_MIN },
    #endif
    { SIMDE_FLOAT16_VALUE(   12.44),
      INT64_C(       12) },
    { SIMDE_FLOAT16_VALUE(   30.46),
      INT64_C(       30) },
    { SIMDE_FLOAT16_VALUE(   16.51),
      INT64_C(       17) },
    { SIMDE_FLOAT16_VALUE(   74.89),
      INT64_C(       75) },
    { SIMDE_FLOAT16_VALUE(   -24.05),
      -INT64_C(       24) },
    { SIMDE_FLOAT16_VALUE(   -7.75),
      -INT64_C(       8) },
    { SIMDE_FLOAT16_VALUE(   -57.31),
      -INT64_C(       57) },
    { SIMDE_FLOAT16_VALUE(   -14.65),
      -INT64_C(       15) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16_t a = test_vec[i].a;
    int64_t r = simde_vcvtnh_s64_f16(a);
    simde_assert_equal_i64(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_vcvtnh_s32_f16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float16_t a;
    int32_t r;
  } test_vec[] = {
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
      {            SIMDE_NANHF,
        INT32_C(           0) },
      { simde_float16_from_float32(HEDLEY_STATIC_CAST(simde_float32, INT32_MAX)),
                  INT32_MAX },
      { simde_float16_from_float32(HEDLEY_STATIC_CAST(simde_float32, INT32_MIN)),
                  INT32_MIN },
    #endif
    { SIMDE_FLOAT16_VALUE(   12.44),
      INT32_C(       12) },
    { SIMDE_FLOAT16_VALUE(   30.46),
      INT32_C(       30) },
    { SIMDE_FLOAT16_VALUE(   16.51),
      INT32_C(       17) },
    { SIMDE_FLOAT16_VALUE(   74.89),
      INT32_C(       75) },
    { SIMDE_FLOAT16_VALUE(   -24.05),
      -INT32_C(       24) },
    { SIMDE_FLOAT16_VALUE(   -7.75),
      -INT32_C(       8) },
    { SIMDE_FLOAT16_VALUE(   -57.31),
      -INT32_C(       57) },
    { SIMDE_FLOAT16_VALUE(   -14.65),
      -INT32_C(       15) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16_t a = test_vec[i].a;
    int32_t r = simde_vcvtnh_s32_f16(a);
    simde_assert_equal_i32(r, test_vec[i].r);
  }

  return 0;
}

/* Disabled until we fix the FCVTZS/FCVTMS/FCVTPS/FCVTNS family intrinsics
 * https://github.com/simd-everywhere/simde/issues/1099
static int
test_simde_vcvtnh_s16_f16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float16_t a;
    int16_t r;
  } test_vec[] = {
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
      {            SIMDE_NANHF,
        INT16_C(           0) },
      { simde_float16_from_float32(HEDLEY_STATIC_CAST(simde_float32, INT16_MAX)),
                  INT16_MAX },
      { simde_float16_from_float32(HEDLEY_STATIC_CAST(simde_float32, INT16_MIN)),
                  INT16_MIN },
    #endif
    { SIMDE_FLOAT16_VALUE(   12.44),
      INT16_C(       12) },
    { SIMDE_FLOAT16_VALUE(   30.46),
      INT16_C(       30) },
    { SIMDE_FLOAT16_VALUE(   16.51),
      INT16_C(       17) },
    { SIMDE_FLOAT16_VALUE(   74.89),
      INT16_C(       75) },
    { SIMDE_FLOAT16_VALUE(   -24.05),
      -INT16_C(       24) },
    { SIMDE_FLOAT16_VALUE(   -7.75),
      -INT16_C(       8) },
    { SIMDE_FLOAT16_VALUE(   -57.31),
      -INT16_C(       57) },
    { SIMDE_FLOAT16_VALUE(   -14.65),
      -INT16_C(       15) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16_t a = test_vec[i].a;
    int16_t r = simde_vcvtnh_s16_f16(a);
    simde_assert_equal_i16(r, test_vec[i].r);
  }

  return 0;
}
*/

static int
test_simde_vcvtns_s32_f32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    simde_float32 a;
    int32_t r;
  } test_vec[] = {
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
      {            SIMDE_MATH_NANF,
        INT32_C(           0) },
      { HEDLEY_STATIC_CAST(simde_float32, INT32_MAX) + SIMDE_FLOAT32_C(1000.0),
                  INT32_MAX },
      { HEDLEY_STATIC_CAST(simde_float32, INT32_MIN) + SIMDE_FLOAT32_C(-1000.0),
                  INT32_MIN },
    #endif
    { SIMDE_FLOAT32_C(   192.44),
      INT32_C(       192) },
    { SIMDE_FLOAT32_C(   350.46),
      INT32_C(       350) },
    { SIMDE_FLOAT32_C(   163.51),
      INT32_C(       164) },
    { SIMDE_FLOAT32_C(   974.89),
      INT32_C(       975) },
    { SIMDE_FLOAT32_C(   -254.05),
      -INT32_C(       254) },
    { SIMDE_FLOAT32_C(   -707.75),
      -INT32_C(       708) },
    { SIMDE_FLOAT32_C(   -957.31),
      -INT32_C(       957) },
    { SIMDE_FLOAT32_C(   -144.65),
      -INT32_C(       145) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32 a = test_vec[i].a;
    int32_t r = simde_vcvtns_s32_f32(a);
    simde_assert_equal_i32(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_vcvtnh_u64_f16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float16_t a;
    uint64_t r;
  } test_vec[] = {
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
      {            SIMDE_NANHF,
        UINT64_C(           0) },
      { simde_float16_from_float32(HEDLEY_STATIC_CAST(simde_float32, UINT64_MAX)),
                 UINT64_MAX },
      { SIMDE_FLOAT16_VALUE(  -192.44),
        UINT64_C(           0) },
    #endif
    { SIMDE_FLOAT16_VALUE(   192.44),
      UINT64_C(       192) },
    { SIMDE_FLOAT16_VALUE(   350.46),
      UINT64_C(       350) },
    { SIMDE_FLOAT16_VALUE(   163.51),
      UINT64_C(       164) },
    { SIMDE_FLOAT16_VALUE(   974.89),
      UINT64_C(       975) },
    { SIMDE_FLOAT16_VALUE(   254.05),
      UINT64_C(       254) },
    { SIMDE_FLOAT16_VALUE(   707.75),
      UINT64_C(       708) },
    { SIMDE_FLOAT16_VALUE(   57.31),
      UINT64_C(       57) },
    { SIMDE_FLOAT16_VALUE(   144.65),
      UINT64_C(       145) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16_t a = test_vec[i].a;
    uint64_t r = simde_vcvtnh_u64_f16(a);
    simde_assert_equal_u64(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_vcvtnh_u32_f16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float16_t a;
    uint32_t r;
  } test_vec[] = {
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
      {            SIMDE_NANHF,
        INT32_C(           0) },
      { simde_float16_from_float32(HEDLEY_STATIC_CAST(simde_float32, UINT32_MAX)),
                 UINT32_MAX },
      { SIMDE_FLOAT16_VALUE(  -192.44),
        UINT32_C(           0) },
    #endif
    { SIMDE_FLOAT16_VALUE(   192.44),
      UINT32_C(       192) },
    { SIMDE_FLOAT16_VALUE(   350.46),
      UINT32_C(       350) },
    { SIMDE_FLOAT16_VALUE(   163.51),
      UINT32_C(       164) },
    { SIMDE_FLOAT16_VALUE(   974.89),
      UINT32_C(       975) },
    { SIMDE_FLOAT16_VALUE(   254.05),
      UINT32_C(       254) },
    { SIMDE_FLOAT16_VALUE(   707.75),
      UINT32_C(       708) },
    { SIMDE_FLOAT16_VALUE(   57.31),
      UINT32_C(       57) },
    { SIMDE_FLOAT16_VALUE(   144.65),
      UINT32_C(       145) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16_t a = test_vec[i].a;
    uint32_t r = simde_vcvtnh_u32_f16(a);
    simde_assert_equal_u32(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_vcvtnh_u16_f16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float16_t a;
    uint16_t r;
  } test_vec[] = {
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
      {            SIMDE_NANHF,
        INT16_C(           0) },
      { simde_float16_from_float32(HEDLEY_STATIC_CAST(simde_float32, UINT16_MAX)),
                 UINT16_MAX },
      { SIMDE_FLOAT16_VALUE(  -192.44),
        UINT16_C(           0) },
    #endif
    { SIMDE_FLOAT16_VALUE(   192.44),
      UINT16_C(       192) },
    { SIMDE_FLOAT16_VALUE(   350.46),
      UINT16_C(       350) },
    { SIMDE_FLOAT16_VALUE(   163.51),
      UINT16_C(       164) },
    { SIMDE_FLOAT16_VALUE(   974.89),
      UINT16_C(       975) },
    { SIMDE_FLOAT16_VALUE(   254.05),
      UINT16_C(       254) },
    { SIMDE_FLOAT16_VALUE(   707.75),
      UINT16_C(       708) },
    { SIMDE_FLOAT16_VALUE(   57.31),
      UINT16_C(       57) },
    { SIMDE_FLOAT16_VALUE(   144.65),
      UINT16_C(       145) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16_t a = test_vec[i].a;
    uint16_t r = simde_vcvtnh_u16_f16(a);
    simde_assert_equal_u16(r, test_vec[i].r);
  }

  return 0;
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
test_simde_vcvtnd_s64_f64 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    simde_float64 a;
    int64_t r;
  } test_vec[] = {
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
      {             SIMDE_MATH_NAN,
        INT64_C(           0) },
      { HEDLEY_STATIC_CAST(simde_float64, INT64_MAX) + SIMDE_FLOAT64_C(10000.0),
                  INT64_MAX },
      { HEDLEY_STATIC_CAST(simde_float64, INT64_MIN) + SIMDE_FLOAT64_C(-10000.0),
                  INT64_MIN },
    #endif
    { SIMDE_FLOAT64_C(   755.50),
      INT64_C(                 756) },
    { SIMDE_FLOAT64_C(   719.56),
      INT64_C(                 720) },
    { SIMDE_FLOAT64_C(   939.13),
      INT64_C(                 939) },
    { SIMDE_FLOAT64_C(   742.14),
      INT64_C(                 742) },
    { SIMDE_FLOAT64_C(   -916.64),
      -INT64_C(                 917) },
    { SIMDE_FLOAT64_C(    -55.73),
      -INT64_C(                  56) },
    { SIMDE_FLOAT64_C(   -511.47),
      -INT64_C(                 511) },
    { SIMDE_FLOAT64_C(   -399.92),
      -INT64_C(                 400) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64 a = test_vec[i].a;
    int64_t r = simde_vcvtnd_s64_f64(a);
    simde_assert_equal_i64(r, test_vec[i].r);
  }

  return 0;
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

/* Disabled until we fix the FCVTZS/FCVTMS/FCVTPS/FCVTNS family intrinsics
 * https://github.com/simd-everywhere/simde/issues/1099
static int
test_simde_vcvtnq_s16_f16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float16_t a[8];
    int16_t r[8];
  } test_vec[] = {
    { { SIMDE_FLOAT16_VALUE(8.5), SIMDE_FLOAT16_VALUE(-2.4), SIMDE_FLOAT16_VALUE(6.5), SIMDE_FLOAT16_VALUE(3.3), SIMDE_FLOAT16_VALUE(-8.9), SIMDE_FLOAT16_VALUE(4.2), SIMDE_FLOAT16_VALUE(11.5), SIMDE_FLOAT16_VALUE(10.2) },
      { INT16_C(8), -INT16_C(2), INT16_C(6), INT16_C(3), -INT16_C(9), INT16_C(4), INT16_C(12), INT16_C(10) } },
    { { SIMDE_FLOAT16_VALUE(13.1), SIMDE_FLOAT16_VALUE(-12.9), SIMDE_FLOAT16_VALUE(-3.1), SIMDE_FLOAT16_VALUE(8.9), SIMDE_FLOAT16_VALUE(1.1), SIMDE_FLOAT16_VALUE(7.2), SIMDE_FLOAT16_VALUE(-3.1), SIMDE_FLOAT16_VALUE(-12.3) },
      { INT16_C(13), -INT16_C(13), -INT16_C(3), INT16_C(9), INT16_C(1), INT16_C(7), -INT16_C(3), -INT16_C(12) } },
    { { SIMDE_FLOAT16_VALUE(-12.0), SIMDE_FLOAT16_VALUE(9.1), SIMDE_FLOAT16_VALUE(8.7), SIMDE_FLOAT16_VALUE(-2.3), SIMDE_FLOAT16_VALUE(-1.0), SIMDE_FLOAT16_VALUE(1.9), SIMDE_FLOAT16_VALUE(-4.8), SIMDE_FLOAT16_VALUE(3.1) },
      { -INT16_C(12), INT16_C(9), INT16_C(9), -INT16_C(2), -INT16_C(1), INT16_C(2), -INT16_C(5), INT16_C(3) } },
    { { SIMDE_FLOAT16_VALUE(8.2), SIMDE_FLOAT16_VALUE(-14.2), SIMDE_FLOAT16_VALUE(9.1), SIMDE_FLOAT16_VALUE(1.3), SIMDE_FLOAT16_VALUE(-12.8), SIMDE_FLOAT16_VALUE(13.9), SIMDE_FLOAT16_VALUE(4.3), SIMDE_FLOAT16_VALUE(-14.8) },
      { INT16_C(8), -INT16_C(14), INT16_C(9), INT16_C(1), -INT16_C(13), INT16_C(14), INT16_C(4), -INT16_C(15) } },
    { { SIMDE_FLOAT16_VALUE(-15.0), SIMDE_FLOAT16_VALUE(14.7), SIMDE_FLOAT16_VALUE(9.9), SIMDE_FLOAT16_VALUE(3.4), SIMDE_FLOAT16_VALUE(5.3), SIMDE_FLOAT16_VALUE(9.0), SIMDE_FLOAT16_VALUE(2.0), SIMDE_FLOAT16_VALUE(0.4) },
      { -INT16_C(15), INT16_C(15), INT16_C(10), INT16_C(3), INT16_C(5), INT16_C(9), INT16_C(2), INT16_C(0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x8_t a = simde_vld1q_f16(test_vec[i].a);
    simde_int16x8_t r = simde_vcvtnq_s16_f16(a);
    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vcvtn_s16_f16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float16_t a[4];
    int16_t r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT16_VALUE(8.5), SIMDE_FLOAT16_VALUE(-2.4), SIMDE_FLOAT16_VALUE(6.5), SIMDE_FLOAT16_VALUE(3.3) },
      { INT16_C(8), -INT16_C(2), INT16_C(6), INT16_C(3) } },
    { { SIMDE_FLOAT16_VALUE(-8.9), SIMDE_FLOAT16_VALUE(4.2), SIMDE_FLOAT16_VALUE(11.5), SIMDE_FLOAT16_VALUE(10.2) },
      { -INT16_C(9), INT16_C(4), INT16_C(12), INT16_C(10) } },
    { { SIMDE_FLOAT16_VALUE(13.1), SIMDE_FLOAT16_VALUE(-12.9), SIMDE_FLOAT16_VALUE(-3.1), SIMDE_FLOAT16_VALUE(8.9) },
      { INT16_C(13), -INT16_C(13), -INT16_C(3), INT16_C(9) } },
    { { SIMDE_FLOAT16_VALUE(1.1), SIMDE_FLOAT16_VALUE(7.2), SIMDE_FLOAT16_VALUE(-3.1), SIMDE_FLOAT16_VALUE(-12.3) },
      { INT16_C(1), INT16_C(7), -INT16_C(3), -INT16_C(12) } },
    { { SIMDE_FLOAT16_VALUE(-12.0), SIMDE_FLOAT16_VALUE(9.1), SIMDE_FLOAT16_VALUE(8.7), SIMDE_FLOAT16_VALUE(-2.3) },
      { -INT16_C(12), INT16_C(9), INT16_C(9), -INT16_C(2) } },
    { { SIMDE_FLOAT16_VALUE(-1.0), SIMDE_FLOAT16_VALUE(1.9), SIMDE_FLOAT16_VALUE(-4.8), SIMDE_FLOAT16_VALUE(3.1) },
      { -INT16_C(1), INT16_C(2), -INT16_C(5), INT16_C(3) } },
    { { SIMDE_FLOAT16_VALUE(8.2), SIMDE_FLOAT16_VALUE(-14.2), SIMDE_FLOAT16_VALUE(9.1), SIMDE_FLOAT16_VALUE(1.3) },
      { INT16_C(8), -INT16_C(14), INT16_C(9), INT16_C(1) } },
    { { SIMDE_FLOAT16_VALUE(-12.8), SIMDE_FLOAT16_VALUE(13.9), SIMDE_FLOAT16_VALUE(4.3), SIMDE_FLOAT16_VALUE(-14.8) },
      { -INT16_C(13), INT16_C(14), INT16_C(4), -INT16_C(15) } },
    { { SIMDE_FLOAT16_VALUE(-15.0), SIMDE_FLOAT16_VALUE(14.7), SIMDE_FLOAT16_VALUE(9.9), SIMDE_FLOAT16_VALUE(3.4) },
      { -INT16_C(15), INT16_C(15), INT16_C(10), INT16_C(3) } },
    { { SIMDE_FLOAT16_VALUE(5.3), SIMDE_FLOAT16_VALUE(9.0), SIMDE_FLOAT16_VALUE(2.0), SIMDE_FLOAT16_VALUE(0.4) },
      { INT16_C(5), INT16_C(9), INT16_C(2), INT16_C(0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x4_t a = simde_vld1_f16(test_vec[i].a);
    simde_int16x4_t r = simde_vcvtn_s16_f16(a);
    simde_test_arm_neon_assert_equal_i16x4(r, simde_vld1_s16(test_vec[i].r));
  }

  return 0;
}
*/

static int
test_simde_vcvtnq_u16_f16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float16_t a[8];
    uint16_t r[8];
  } test_vec[] = {
    { { SIMDE_FLOAT16_VALUE(4.9), SIMDE_FLOAT16_VALUE(0.5), SIMDE_FLOAT16_VALUE(12.8), SIMDE_FLOAT16_VALUE(11.3), SIMDE_FLOAT16_VALUE(13.5), SIMDE_FLOAT16_VALUE(10.0), SIMDE_FLOAT16_VALUE(13.6), SIMDE_FLOAT16_VALUE(11.1) },
      { UINT16_C(5), UINT16_C(0), UINT16_C(13), UINT16_C(11), UINT16_C(14), UINT16_C(10), UINT16_C(14), UINT16_C(11) } },
    { { SIMDE_FLOAT16_VALUE(9.3), SIMDE_FLOAT16_VALUE(8.3), SIMDE_FLOAT16_VALUE(0.2), SIMDE_FLOAT16_VALUE(0.2), SIMDE_FLOAT16_VALUE(0.0), SIMDE_FLOAT16_VALUE(4.6), SIMDE_FLOAT16_VALUE(11.9), SIMDE_FLOAT16_VALUE(5.0) },
      { UINT16_C(9), UINT16_C(8), UINT16_C(0), UINT16_C(0), UINT16_C(0), UINT16_C(5), UINT16_C(12), UINT16_C(5) } },
    { { SIMDE_FLOAT16_VALUE(1.5), SIMDE_FLOAT16_VALUE(2.7), SIMDE_FLOAT16_VALUE(10.9), SIMDE_FLOAT16_VALUE(4.1), SIMDE_FLOAT16_VALUE(9.0), SIMDE_FLOAT16_VALUE(6.3), SIMDE_FLOAT16_VALUE(13.4), SIMDE_FLOAT16_VALUE(13.1) },
      { UINT16_C(2), UINT16_C(3), UINT16_C(11), UINT16_C(4), UINT16_C(9), UINT16_C(6), UINT16_C(13), UINT16_C(13) } },
    { { SIMDE_FLOAT16_VALUE(13.1), SIMDE_FLOAT16_VALUE(6.2), SIMDE_FLOAT16_VALUE(6.5), SIMDE_FLOAT16_VALUE(1.0), SIMDE_FLOAT16_VALUE(2.5), SIMDE_FLOAT16_VALUE(2.5), SIMDE_FLOAT16_VALUE(6.8), SIMDE_FLOAT16_VALUE(1.9) },
      { UINT16_C(13), UINT16_C(6), UINT16_C(6), UINT16_C(1), UINT16_C(2), UINT16_C(2), UINT16_C(7), UINT16_C(2) } },
    { { SIMDE_FLOAT16_VALUE(5.1), SIMDE_FLOAT16_VALUE(0.3), SIMDE_FLOAT16_VALUE(4.8), SIMDE_FLOAT16_VALUE(7.2), SIMDE_FLOAT16_VALUE(10.0), SIMDE_FLOAT16_VALUE(9.9), SIMDE_FLOAT16_VALUE(14.6), SIMDE_FLOAT16_VALUE(4.0) },
      { UINT16_C(5), UINT16_C(0), UINT16_C(5), UINT16_C(7), UINT16_C(10), UINT16_C(10), UINT16_C(15), UINT16_C(4) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x8_t a = simde_vld1q_f16(test_vec[i].a);
    simde_uint16x8_t r = simde_vcvtnq_u16_f16(a);
    simde_test_arm_neon_assert_equal_u16x8(r, simde_vld1q_u16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vcvtn_u16_f16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float16_t a[4];
    uint16_t r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT16_VALUE(4.9), SIMDE_FLOAT16_VALUE(0.5), SIMDE_FLOAT16_VALUE(12.8), SIMDE_FLOAT16_VALUE(11.3) },
      { UINT16_C(5), UINT16_C(0), UINT16_C(13), UINT16_C(11) } },
    { { SIMDE_FLOAT16_VALUE(13.5), SIMDE_FLOAT16_VALUE(10.0), SIMDE_FLOAT16_VALUE(13.6), SIMDE_FLOAT16_VALUE(11.1) },
      { UINT16_C(14), UINT16_C(10), UINT16_C(14), UINT16_C(11) } },
    { { SIMDE_FLOAT16_VALUE(9.3), SIMDE_FLOAT16_VALUE(8.3), SIMDE_FLOAT16_VALUE(0.2), SIMDE_FLOAT16_VALUE(0.2) },
      { UINT16_C(9), UINT16_C(8), UINT16_C(0), UINT16_C(0) } },
    { { SIMDE_FLOAT16_VALUE(0.0), SIMDE_FLOAT16_VALUE(4.6), SIMDE_FLOAT16_VALUE(11.9), SIMDE_FLOAT16_VALUE(5.0) },
      { UINT16_C(0), UINT16_C(5), UINT16_C(12), UINT16_C(5) } },
    { { SIMDE_FLOAT16_VALUE(1.5), SIMDE_FLOAT16_VALUE(2.7), SIMDE_FLOAT16_VALUE(10.9), SIMDE_FLOAT16_VALUE(4.1) },
      { UINT16_C(2), UINT16_C(3), UINT16_C(11), UINT16_C(4) } },
    { { SIMDE_FLOAT16_VALUE(9.0), SIMDE_FLOAT16_VALUE(6.3), SIMDE_FLOAT16_VALUE(13.4), SIMDE_FLOAT16_VALUE(13.1) },
      { UINT16_C(9), UINT16_C(6), UINT16_C(13), UINT16_C(13) } },
    { { SIMDE_FLOAT16_VALUE(13.1), SIMDE_FLOAT16_VALUE(6.2), SIMDE_FLOAT16_VALUE(6.5), SIMDE_FLOAT16_VALUE(1.0) },
      { UINT16_C(13), UINT16_C(6), UINT16_C(6), UINT16_C(1) } },
    { { SIMDE_FLOAT16_VALUE(2.5), SIMDE_FLOAT16_VALUE(2.5), SIMDE_FLOAT16_VALUE(6.8), SIMDE_FLOAT16_VALUE(1.9) },
      { UINT16_C(2), UINT16_C(2), UINT16_C(7), UINT16_C(2) } },
    { { SIMDE_FLOAT16_VALUE(5.1), SIMDE_FLOAT16_VALUE(0.3), SIMDE_FLOAT16_VALUE(4.8), SIMDE_FLOAT16_VALUE(7.2) },
      { UINT16_C(5), UINT16_C(0), UINT16_C(5), UINT16_C(7) } },
    { { SIMDE_FLOAT16_VALUE(10.0), SIMDE_FLOAT16_VALUE(9.9), SIMDE_FLOAT16_VALUE(14.6), SIMDE_FLOAT16_VALUE(4.0) },
      { UINT16_C(10), UINT16_C(10), UINT16_C(15), UINT16_C(4) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x4_t a = simde_vld1_f16(test_vec[i].a);
    simde_uint16x4_t r = simde_vcvtn_u16_f16(a);
    simde_test_arm_neon_assert_equal_u16x4(r, simde_vld1_u16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vcvtn_u32_f32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float32 a[2];
    uint32_t r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(31.72), SIMDE_FLOAT32_C(82.77) },
      { UINT32_C(32), UINT32_C(83) } },
    { { SIMDE_FLOAT32_C(17.70), SIMDE_FLOAT32_C(39.19) },
      { UINT32_C(18), UINT32_C(39) } },
    { { SIMDE_FLOAT32_C(86.63), SIMDE_FLOAT32_C(69.32) },
      { UINT32_C(87), UINT32_C(69) } },
    { { SIMDE_FLOAT32_C(9.24), SIMDE_FLOAT32_C(42.24) },
      { UINT32_C(9), UINT32_C(42) } },
    { { SIMDE_FLOAT32_C(5.52), SIMDE_FLOAT32_C(32.96) },
      { UINT32_C(6), UINT32_C(33) } },
    { { SIMDE_FLOAT32_C(59.77), SIMDE_FLOAT32_C(16.79) },
      { UINT32_C(60), UINT32_C(17) } },
    { { SIMDE_FLOAT32_C(20.26), SIMDE_FLOAT32_C(74.48) },
      { UINT32_C(20), UINT32_C(74) } },
    { { SIMDE_FLOAT32_C(76.43), SIMDE_FLOAT32_C(66.05) },
      { UINT32_C(76), UINT32_C(66) } },
    { { SIMDE_FLOAT32_C(78.67), SIMDE_FLOAT32_C(64.95) },
      { UINT32_C(79), UINT32_C(65) } },
    { { SIMDE_FLOAT32_C(96.96), SIMDE_FLOAT32_C(24.41) },
      { UINT32_C(97), UINT32_C(24) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t a = simde_vld1_f32(test_vec[i].a);
    simde_uint32x2_t r = simde_vcvtn_u32_f32(a);
    simde_test_arm_neon_assert_equal_u32x2(r, simde_vld1_u32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vcvtn_s32_f32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float32 a[2];
    int32_t r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(25.79), SIMDE_FLOAT32_C(49.90) },
      { INT32_C(26), INT32_C(50) } },
    { { SIMDE_FLOAT32_C(-94.73), SIMDE_FLOAT32_C(-49.75) },
      { -INT32_C(95), -INT32_C(50) } },
    { { SIMDE_FLOAT32_C(56.53), SIMDE_FLOAT32_C(-28.89) },
      { INT32_C(57), -INT32_C(29) } },
    { { SIMDE_FLOAT32_C(-2.63), SIMDE_FLOAT32_C(54.36) },
      { -INT32_C(3), INT32_C(54) } },
    { { SIMDE_FLOAT32_C(60.53), SIMDE_FLOAT32_C(15.86) },
      { INT32_C(61), INT32_C(16) } },
    { { SIMDE_FLOAT32_C(-83.28), SIMDE_FLOAT32_C(-5.22) },
      { -INT32_C(83), -INT32_C(5) } },
    { { SIMDE_FLOAT32_C(44.28), SIMDE_FLOAT32_C(-14.52) },
      { INT32_C(44), -INT32_C(15) } },
    { { SIMDE_FLOAT32_C(-15.99), SIMDE_FLOAT32_C(80.84) },
      { -INT32_C(16), INT32_C(81) } },
    { { SIMDE_FLOAT32_C(14.60), SIMDE_FLOAT32_C(12.56) },
      { INT32_C(15), INT32_C(13) } },
    { { SIMDE_FLOAT32_C(9.86), SIMDE_FLOAT32_C(3.40) },
      { INT32_C(10), INT32_C(3) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t a = simde_vld1_f32(test_vec[i].a);
    simde_int32x2_t r = simde_vcvtn_s32_f32(a);
    simde_test_arm_neon_assert_equal_i32x2(r, simde_vld1_s32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vcvtn_s64_f64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float64 a[1];
    int64_t r[1];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(9081.35) },
      { INT64_C(9081) } },
    { { SIMDE_FLOAT64_C(6727.25) },
      { INT64_C(6727) } },
    { { SIMDE_FLOAT64_C(-6846.21) },
      { -INT64_C(6846) } },
    { { SIMDE_FLOAT64_C(199.59) },
      { INT64_C(200) } },
    { { SIMDE_FLOAT64_C(8615.31) },
      { INT64_C(8615) } },
    { { SIMDE_FLOAT64_C(-4053.97) },
      { -INT64_C(4054) } },
    { { SIMDE_FLOAT64_C(-7297.52) },
      { -INT64_C(7298) } },
    { { SIMDE_FLOAT64_C(6497.22) },
      { INT64_C(6497) } },
    { { SIMDE_FLOAT64_C(7123.83) },
      { INT64_C(7124) } },
    { { SIMDE_FLOAT64_C(2924.27) },
      { INT64_C(2924) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x1_t a = simde_vld1_f64(test_vec[i].a);
    simde_int64x1_t r = simde_vcvtn_s64_f64(a);
    simde_test_arm_neon_assert_equal_i64x1(r, simde_vld1_s64(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vcvtn_u64_f64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float64 a[1];
    uint64_t r[1];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(8228.53) },
      { UINT64_C(8229) } },
    { { SIMDE_FLOAT64_C(2885.15) },
      { UINT64_C(2885) } },
    { { SIMDE_FLOAT64_C(5510.71) },
      { UINT64_C(5511) } },
    { { SIMDE_FLOAT64_C(6587.73) },
      { UINT64_C(6588) } },
    { { SIMDE_FLOAT64_C(2334.53) },
      { UINT64_C(2335) } },
    { { SIMDE_FLOAT64_C(8071.59) },
      { UINT64_C(8072) } },
    { { SIMDE_FLOAT64_C(1644.38) },
      { UINT64_C(1644) } },
    { { SIMDE_FLOAT64_C(9170.38) },
      { UINT64_C(9170) } },
    { { SIMDE_FLOAT64_C(1001.61) },
      { UINT64_C(1002) } },
    { { SIMDE_FLOAT64_C(2770.35) },
      { UINT64_C(2770) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x1_t a = simde_vld1_f64(test_vec[i].a);
    simde_uint64x1_t r = simde_vcvtn_u64_f64(a);
    simde_test_arm_neon_assert_equal_u64x1(r, simde_vld1_u64(test_vec[i].r));
  }

  return 0;
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtns_s32_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtnd_s64_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtns_u32_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtnd_u64_f64)

//SIMDE_TEST_FUNC_LIST_ENTRY(vcvtnh_s16_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtnh_s32_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtnh_s64_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtnh_u16_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtnh_u32_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtnh_u64_f16)

//SIMDE_TEST_FUNC_LIST_ENTRY(vcvtn_s16_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtn_u16_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtn_u32_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtn_s32_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtn_s64_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtn_u64_f64)

//SIMDE_TEST_FUNC_LIST_ENTRY(vcvtnq_s16_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtnq_s32_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtnq_s64_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtnq_u16_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtnq_u32_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtnq_u64_f64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
