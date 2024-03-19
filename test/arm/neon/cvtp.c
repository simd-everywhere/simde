#define SIMDE_TEST_ARM_NEON_INSN cvtp

#include "test-neon.h"
#include "../../../simde/arm/neon/cvtp.h"

/* Disabled until we fix the FCVTZS/FCVTMS/FCVTPS/FCVTNS family intrinsics
 * https://github.com/simd-everywhere/simde/issues/1099
static int
test_simde_vcvtpq_s32_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a[4];
    int32_t r[4];
  } test_vec[] = {
    { { -SIMDE_FLOAT32_C(   607.741),  SIMDE_FLOAT32_C(   403.453),  SIMDE_FLOAT32_C(    97.739), -SIMDE_FLOAT32_C(     2.667) },
      { -INT32_C(       607),  INT32_C(       404),  INT32_C(        98), -INT32_C(         2) } },
    { { -SIMDE_FLOAT32_C(   438.220), -SIMDE_FLOAT32_C(   356.632), -SIMDE_FLOAT32_C(   355.499),  SIMDE_FLOAT32_C(    12.256) },
      { -INT32_C(       438), -INT32_C(       356), -INT32_C(       355),  INT32_C(        13) } },
    { { -SIMDE_FLOAT32_C(   712.986),  SIMDE_FLOAT32_C(   505.464), -SIMDE_FLOAT32_C(   103.452), -SIMDE_FLOAT32_C(   725.220) },
      { -INT32_C(       712),  INT32_C(       506), -INT32_C(       103), -INT32_C(       725) } },
    { {  SIMDE_FLOAT32_C(   824.850),  SIMDE_FLOAT32_C(    62.658), -SIMDE_FLOAT32_C(   644.643),  SIMDE_FLOAT32_C(   510.005) },
      {  INT32_C(       825),  INT32_C(        63), -INT32_C(       644),  INT32_C(       511) } },
    { { -SIMDE_FLOAT32_C(     2.843), -SIMDE_FLOAT32_C(   710.183), -SIMDE_FLOAT32_C(   382.143), -SIMDE_FLOAT32_C(   280.409) },
      { -INT32_C(         2), -INT32_C(       710), -INT32_C(       382), -INT32_C(       280) } },
    { {  SIMDE_FLOAT32_C(   209.258), -SIMDE_FLOAT32_C(    68.390),  SIMDE_FLOAT32_C(   737.373),  SIMDE_FLOAT32_C(   383.386) },
      {  INT32_C(       210), -INT32_C(        68),  INT32_C(       738),  INT32_C(       384) } },
    { {  SIMDE_FLOAT32_C(   411.326), -SIMDE_FLOAT32_C(   427.964), -SIMDE_FLOAT32_C(    38.293), -SIMDE_FLOAT32_C(    18.446) },
      {  INT32_C(       412), -INT32_C(       427), -INT32_C(        38), -INT32_C(        18) } },
    { { -SIMDE_FLOAT32_C(   375.151), -SIMDE_FLOAT32_C(   477.988), -SIMDE_FLOAT32_C(   879.299),  SIMDE_FLOAT32_C(   967.790) },
      { -INT32_C(       375), -INT32_C(       477), -INT32_C(       879),  INT32_C(       968) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_int32x4_t r = simde_vcvtpq_s32_f32(a);
    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x4_t a = simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f);
    simde_int32x4_t r = simde_vcvtpq_s32_f32(a);

    simde_test_arm_neon_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvtpq_s64_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 a[2];
    int64_t r[2];
  } test_vec[] = {
    { {  SIMDE_FLOAT64_C( 99237.141), -SIMDE_FLOAT64_C( 50717.117) },
      {  INT64_C(     99238), -INT64_C(     50717) } },
    { { -SIMDE_FLOAT64_C( 74116.766),  SIMDE_FLOAT64_C( 66114.500) },
      { -INT64_C(     74116),  INT64_C(     66115) } },
    { { -SIMDE_FLOAT64_C( 88666.844),  SIMDE_FLOAT64_C( 79431.297) },
      { -INT64_C(     88666),  INT64_C(     79432) } },
    { {  SIMDE_FLOAT64_C( 18760.219), -SIMDE_FLOAT64_C( 76336.250) },
      {  INT64_C(     18761), -INT64_C(     76336) } },
    { { -SIMDE_FLOAT64_C( 86460.719),  SIMDE_FLOAT64_C( 56061.813) },
      { -INT64_C(     86460),  INT64_C(     56062) } },
    { { -SIMDE_FLOAT64_C( 52624.641),  SIMDE_FLOAT64_C( 76414.109) },
      { -INT64_C(     52624),  INT64_C(     76415) } },
    { {  SIMDE_FLOAT64_C( 87426.969), -SIMDE_FLOAT64_C( 65214.336) },
      {  INT64_C(     87427), -INT64_C(     65214) } },
    { {  SIMDE_FLOAT64_C( 94206.609), -SIMDE_FLOAT64_C( 63892.445) },
      {  INT64_C(     94207), -INT64_C(     63892) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2_t a = simde_vld1q_f64(test_vec[i].a);
    simde_int64x2_t r = simde_vcvtpq_s64_f64(a);
    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x2_t a = simde_test_arm_neon_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde_int64x2_t r = simde_vcvtpq_s64_f64(a);

    simde_test_arm_neon_write_f64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}
*/

static int
test_simde_vcvtph_s64_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
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
    {    SIMDE_FLOAT16_VALUE(     0.0),
         INT64_C(         0) },
    #endif
    {    SIMDE_FLOAT16_VALUE(     3.188),
         INT64_C(         4) },
    {    SIMDE_FLOAT16_VALUE(     6.484),
         INT64_C(         7) },
    {   SIMDE_FLOAT16_VALUE( -    18.336),
        -INT64_C(        18) },
    {    SIMDE_FLOAT16_VALUE(    27.028),
         INT64_C(        28) },
    {   SIMDE_FLOAT16_VALUE( -    22.919),
        -INT64_C(        22) },
    {    SIMDE_FLOAT16_VALUE(    13.598),
         INT64_C(        14) },
    {    SIMDE_FLOAT16_VALUE(    27.711),
         INT64_C(        28) },
    {   SIMDE_FLOAT16_VALUE( -     1.019),
        -INT64_C(         1) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16_t a = test_vec[i].a;
    int64_t r = simde_vcvtph_s64_f16(a);
    simde_assert_equal_i64(r, test_vec[i].r);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16_t a = simde_test_arm_neon_random_f16(-100.0f, 100.0f);
    simde_int64_t r = simde_vcvtph_s64_f16(a);

    simde_test_arm_neon_write_f16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvtph_s32_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16_t a;
    int32_t r;
  } test_vec[] = {
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
      {            SIMDE_NANHF,
        INT32_C(           0) },
      { simde_float16_from_float32(HEDLEY_STATIC_CAST(simde_float32, INT32_MAX)),
                  INT32_MAX },
      { simde_float16_from_float32(HEDLEY_STATIC_CAST(simde_float32, INT32_MAX+1000ll)),
                  INT32_MAX },
      { simde_float16_from_float32(HEDLEY_STATIC_CAST(simde_float32, INT32_MIN)),
                  INT32_MIN },
      { simde_float16_from_float32(HEDLEY_STATIC_CAST(simde_float32, INT32_MIN-1000ll)),
                  INT32_MIN },
    {    SIMDE_FLOAT16_VALUE(     0.0),
         INT32_C(         0) },
    #endif
    {   SIMDE_FLOAT16_VALUE( -    13.547),
        -INT32_C(        13) },
    {   SIMDE_FLOAT16_VALUE( -    28.627),
        -INT32_C(        28) },
    {   SIMDE_FLOAT16_VALUE( -    26.702),
        -INT32_C(        26) },
    {   SIMDE_FLOAT16_VALUE( -     8.158),
        -INT32_C(         8) },
    {   SIMDE_FLOAT16_VALUE( -    10.661),
        -INT32_C(        10) },
    {   SIMDE_FLOAT16_VALUE( -    14.185),
        -INT32_C(        14) },
    {    SIMDE_FLOAT16_VALUE(    10.164),
         INT32_C(        11) },
    {   SIMDE_FLOAT16_VALUE( -    14.690),
        -INT32_C(        14) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16_t a = test_vec[i].a;
    int32_t r = simde_vcvtph_s32_f16(a);
    simde_assert_equal_i32(r, test_vec[i].r);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16_t a = simde_test_arm_neon_random_f16(-100.0f, 100.0f);
    simde_int32_t r = simde_vcvtph_s32_f16(a);

    simde_test_arm_neon_write_f16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

/* Disabled until we fix the FCVTZS/FCVTMS/FCVTPS/FCVTNS family intrinsics
 * https://github.com/simd-everywhere/simde/issues/1099
static int
test_simde_vcvtph_s16_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16_t a;
    int16_t r;
  } test_vec[] = {
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
      {            SIMDE_NANHF,
        INT16_C(           0) },
      { simde_float16_from_float32(HEDLEY_STATIC_CAST(simde_float32, INT16_MAX)),
                  INT16_MAX },
      { simde_float16_from_float32(HEDLEY_STATIC_CAST(simde_float32, INT16_MAX) + SIMDE_FLOAT32_C(100.0)),
                  INT16_MAX },
      { simde_float16_from_float32(HEDLEY_STATIC_CAST(simde_float32, INT16_MIN)),
                  INT16_MIN },
      { simde_float16_from_float32(HEDLEY_STATIC_CAST(simde_float32, INT16_MIN) + SIMDE_FLOAT32_C(-100.0)),
                  INT16_MIN },
    {    SIMDE_FLOAT16_VALUE(     0.0),
         INT16_C(         0) },
    #endif
    {    SIMDE_FLOAT16_VALUE(    26.840),
         INT16_C(        27) },
    {    SIMDE_FLOAT16_VALUE(    28.316),
         INT16_C(        29) },
    {    SIMDE_FLOAT16_VALUE(    11.363),
         INT16_C(        12) },
    {   SIMDE_FLOAT16_VALUE( -     9.731),
        -INT16_C(         9) },
    {    SIMDE_FLOAT16_VALUE(     7.723),
         INT16_C(         8) },
    {   SIMDE_FLOAT16_VALUE( -    22.898),
        -INT16_C(        22) },
    {   SIMDE_FLOAT16_VALUE( -    19.354),
        -INT16_C(        19) },
    {    SIMDE_FLOAT16_VALUE(    24.613),
         INT16_C(        25) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16_t a = test_vec[i].a;
    int16_t r = simde_vcvtph_s16_f16(a);
    simde_assert_equal_i16(r, test_vec[i].r);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16_t a = simde_test_arm_neon_random_f16(-100.0f, 100.0f);
    simde_int16_t r = simde_vcvtph_s16_f16(a);

    simde_test_arm_neon_write_f16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvtps_s32_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a;
    int32_t r;
  } test_vec[] = {
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
      {            SIMDE_MATH_NANF,
        INT32_C(           0) },
      { HEDLEY_STATIC_CAST(simde_float32, INT32_MAX),
                  INT32_MAX },
      { HEDLEY_STATIC_CAST(simde_float32, INT32_MAX) + SIMDE_FLOAT32_C(1000.0),
                  INT32_MAX },
      { HEDLEY_STATIC_CAST(simde_float32, INT32_MIN),
                  INT32_MIN },
      { HEDLEY_STATIC_CAST(simde_float32, INT32_MIN) + SIMDE_FLOAT32_C(-1000.0),
                  INT32_MIN },
    {    SIMDE_FLOAT32_C(    0.000),
         INT32_C(        0) },
    #endif
    {    SIMDE_FLOAT32_C(    14.178),
         INT32_C(        15) },
    {   -SIMDE_FLOAT32_C(   607.139),
        -INT32_C(       607) },
    {   -SIMDE_FLOAT32_C(   414.899),
        -INT32_C(       414) },
    {   -SIMDE_FLOAT32_C(   887.709),
        -INT32_C(       887) },
    {   -SIMDE_FLOAT32_C(   746.822),
        -INT32_C(       746) },
    {    SIMDE_FLOAT32_C(   170.845),
         INT32_C(       171) },
    {    SIMDE_FLOAT32_C(   991.922),
         INT32_C(       992) },
    {   -SIMDE_FLOAT32_C(   557.800),
        -INT32_C(       557) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32 a = test_vec[i].a;
    int32_t r = simde_vcvtps_s32_f32(a);
    simde_assert_equal_i32(r, test_vec[i].r);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32_t a = simde_test_arm_neon_random_f32(-1000.0f, 1000.0f);
    simde_int32_t r = simde_vcvtps_s32_f32(a);

    simde_test_arm_neon_write_f32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}
*/

static int
test_simde_vcvtph_u64_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16_t a;
    uint64_t r;
  } test_vec[] = {
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
      {            SIMDE_NANHF,
        INT64_C(           0) },
      { simde_float16_from_float32(HEDLEY_STATIC_CAST(simde_float32, UINT64_MAX)),
                  UINT64_MAX },
      { SIMDE_FLOAT16_VALUE(-1000.0),
        UINT64_C(         0) },
      {   SIMDE_FLOAT16_VALUE( 0.000),
           UINT64_C(         0) },
    #endif
    {    SIMDE_FLOAT16_VALUE(     9.136),
         UINT64_C(        10) },
    {    SIMDE_FLOAT16_VALUE(     8.945),
         UINT64_C(         9) },
    {    SIMDE_FLOAT16_VALUE(     4.916),
         UINT64_C(         5) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16_t a = test_vec[i].a;
    uint64_t r = simde_vcvtph_u64_f16(a);
    simde_assert_equal_u64(r, test_vec[i].r);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16_t a = simde_test_arm_neon_random_f16(-100.0f, 100.0f);
    simde_uint64_t r = simde_vcvtph_u64_f16(a);

    simde_test_arm_neon_write_f16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvtph_u32_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16_t a;
    uint32_t r;
  } test_vec[] = {
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
      {            SIMDE_NANHF,
        INT32_C(           0) },
      { simde_float16_from_float32(HEDLEY_STATIC_CAST(simde_float32, UINT32_MAX)),
                  UINT32_MAX },
      { simde_float16_from_float32(HEDLEY_STATIC_CAST(simde_float32, UINT32_MAX+1000ll)),
                  UINT32_MAX },
      { SIMDE_FLOAT16_VALUE(-1000.0),
        UINT32_C(         0) },
      { SIMDE_FLOAT16_VALUE( 0.000),
        UINT32_C(         0) },
    #endif
    {    SIMDE_FLOAT16_VALUE(    14.954),
         UINT32_C(        15) },
    {    SIMDE_FLOAT16_VALUE(    17.106),
         UINT32_C(        18) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16_t a = test_vec[i].a;
    uint32_t r = simde_vcvtph_u32_f16(a);
    simde_assert_equal_u32(r, test_vec[i].r);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16_t a = simde_test_arm_neon_random_f16(-100.0f, 100.0f);
    simde_uint32_t r = simde_vcvtph_u32_f16(a);

    simde_test_arm_neon_write_f16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvtph_u16_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16_t a;
    uint16_t r;
  } test_vec[] = {
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
      {            SIMDE_NANHF,
        INT16_C(           0) },
      { simde_float16_from_float32(HEDLEY_STATIC_CAST(simde_float32, UINT16_MAX)),
                  UINT16_MAX },
      { simde_float16_from_float32(HEDLEY_STATIC_CAST(simde_float32, UINT16_MAX+1000)),
                  UINT16_MAX },
      { SIMDE_FLOAT16_VALUE(-1000.0),
        UINT16_C(         0) },
      { SIMDE_FLOAT16_VALUE( 0.000),
        UINT16_C(         0) },
    #endif
    {    SIMDE_FLOAT16_VALUE(    17.766),
         UINT16_C(        18) },
    {    SIMDE_FLOAT16_VALUE(    22.378),
         UINT16_C(        23) },
    {    SIMDE_FLOAT16_VALUE(     2.456),
         UINT16_C(         3) },
    {    SIMDE_FLOAT16_VALUE(    25.255),
         UINT16_C(        26) },
    {    SIMDE_FLOAT16_VALUE(     5.504),
         UINT16_C(         6) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16_t a = test_vec[i].a;
    uint16_t r = simde_vcvtph_u16_f16(a);
    simde_assert_equal_u16(r, test_vec[i].r);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16_t a = simde_test_arm_neon_random_f16(-100.0f, 100.0f);
    simde_uint16_t r = simde_vcvtph_u16_f16(a);

    simde_test_arm_neon_write_f16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvtps_u32_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a;
    uint32_t r;
  } test_vec[] = {
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
      {            SIMDE_MATH_NANF,
        INT32_C(           0) },
      { HEDLEY_STATIC_CAST(simde_float32, UINT32_MAX),
                  UINT32_MAX },
      { HEDLEY_STATIC_CAST(simde_float32, UINT32_MAX) + SIMDE_FLOAT32_C(1000.0),
                  UINT32_MAX },
      { SIMDE_FLOAT32_C(-1000.0),
        UINT32_C(         0) },
      { SIMDE_FLOAT32_C(   0.000),
        UINT32_C(         0) },
    #endif
    {    SIMDE_FLOAT32_C(   517.893),
         UINT32_C(       518) },
    {    SIMDE_FLOAT32_C(   288.716),
         UINT32_C(       289) },
    {    SIMDE_FLOAT32_C(   197.506),
         UINT32_C(       198) },
    {    SIMDE_FLOAT32_C(   973.600),
         UINT32_C(       974) },
    {    SIMDE_FLOAT32_C(   976.840),
         UINT32_C(       977) },
    {    SIMDE_FLOAT32_C(   920.392),
         UINT32_C(       921) },
    {    SIMDE_FLOAT32_C(    70.544),
         UINT32_C(        71) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32 a = test_vec[i].a;
    uint32_t r = simde_vcvtps_u32_f32(a);
    simde_assert_equal_u32(r, test_vec[i].r);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32_t a = simde_test_arm_neon_random_f32(-1000.0f, 1000.0f);
    simde_uint32_t r = simde_vcvtps_u32_f32(a);

    simde_test_arm_neon_write_f32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvtpq_u32_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a[4];
    uint32_t r[4];
  } test_vec[] = {
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
      { { HEDLEY_STATIC_CAST(simde_float32, UINT32_MAX) + SIMDE_FLOAT32_C(10000.0), SIMDE_MATH_NANF, -SIMDE_MATH_NANF, SIMDE_MATH_INFINITYF },
        {           UINT32_MAX, UINT32_C(         0), UINT32_C(         0),           UINT32_MAX } },
    #endif
    { { SIMDE_FLOAT32_C(   619.63), SIMDE_FLOAT32_C(   364.48), SIMDE_FLOAT32_C(   938.24), SIMDE_FLOAT32_C(   444.69) },
      { UINT32_C(       620), UINT32_C(       365), UINT32_C(       939), UINT32_C(       445) } },
    { { SIMDE_FLOAT32_C(   955.05), SIMDE_FLOAT32_C(   217.80), SIMDE_FLOAT32_C(   439.91), SIMDE_FLOAT32_C(    55.17) },
      { UINT32_C(       956), UINT32_C(       218), UINT32_C(       440), UINT32_C(        56) } },
    { { SIMDE_FLOAT32_C(   859.62), SIMDE_FLOAT32_C(   349.38), SIMDE_FLOAT32_C(   956.45), SIMDE_FLOAT32_C(   249.96) },
      { UINT32_C(       860), UINT32_C(       350), UINT32_C(       957), UINT32_C(       250) } },
    { { SIMDE_FLOAT32_C(   511.78), SIMDE_FLOAT32_C(   571.90), SIMDE_FLOAT32_C(   930.47), SIMDE_FLOAT32_C(   688.88) },
      { UINT32_C(       512), UINT32_C(       572), UINT32_C(       931), UINT32_C(       689) } },
    { { SIMDE_FLOAT32_C(   637.73), SIMDE_FLOAT32_C(   370.86), SIMDE_FLOAT32_C(   732.69), SIMDE_FLOAT32_C(   402.84) },
      { UINT32_C(       638), UINT32_C(       371), UINT32_C(       733), UINT32_C(       403) } },
    { { SIMDE_FLOAT32_C(   328.28), SIMDE_FLOAT32_C(   536.20), SIMDE_FLOAT32_C(   378.54), SIMDE_FLOAT32_C(   375.08) },
      { UINT32_C(       329), UINT32_C(       537), UINT32_C(       379), UINT32_C(       376) } },
    { { SIMDE_FLOAT32_C(   709.63), SIMDE_FLOAT32_C(   671.54), SIMDE_FLOAT32_C(   418.37), SIMDE_FLOAT32_C(   407.44) },
      { UINT32_C(       710), UINT32_C(       672), UINT32_C(       419), UINT32_C(       408) } },
    { { SIMDE_FLOAT32_C(   782.97), SIMDE_FLOAT32_C(   601.77), SIMDE_FLOAT32_C(   970.47), SIMDE_FLOAT32_C(   402.60) },
      { UINT32_C(       783), UINT32_C(       602), UINT32_C(       971), UINT32_C(       403) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_uint32x4_t r = simde_vcvtpq_u32_f32(a);

    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x4_t a = simde_test_arm_neon_random_f32x4(0.0f, 1000.0f);
    simde_uint32x4_t r = simde_vcvtpq_u32_f32(a);

    simde_test_arm_neon_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

/* Disabled until we fix the FCVTZS/FCVTMS/FCVTPS family intrinsics
 * https://github.com/simd-everywhere/simde/issues/1099
static int
test_simde_vcvtpd_s64_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 a;
    int64_t r;
  } test_vec[] = {
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
      {             SIMDE_MATH_NAN,
        INT64_C(           0) },
      { HEDLEY_STATIC_CAST(simde_float64, INT64_MAX),
                  INT64_MAX },
      { HEDLEY_STATIC_CAST(simde_float64, INT64_MAX) + SIMDE_FLOAT64_C(10000.0),
                  INT64_MAX },
      { HEDLEY_STATIC_CAST(simde_float64, INT64_MIN),
                  INT64_MIN },
      { HEDLEY_STATIC_CAST(simde_float64, INT64_MIN) + SIMDE_FLOAT64_C(-10000.0),
                  INT64_MIN },
    #endif
    {   -SIMDE_FLOAT64_C( 79202.922),
        -INT64_C(     79202) },
    {   -SIMDE_FLOAT64_C( 89537.219),
        -INT64_C(     89537) },
    {   -SIMDE_FLOAT64_C( 12001.297),
        -INT64_C(     12001) },
    {   -SIMDE_FLOAT64_C(  9055.063),
        -INT64_C(      9055) },
    {    SIMDE_FLOAT64_C( 17832.305),
         INT64_C(     17833) },
    {    SIMDE_FLOAT64_C( 96832.719),
         INT64_C(     96833) },
    {    SIMDE_FLOAT64_C(  1258.672),
         INT64_C(      1259) },
    {   -SIMDE_FLOAT64_C( 68830.148),
        -INT64_C(     68830) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64 a = test_vec[i].a;
    int64_t r = simde_vcvtpd_s64_f64(a);
    simde_assert_equal_i64(r, test_vec[i].r);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64_t a = simde_test_arm_neon_random_f64(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde_int64_t r = simde_vcvtpd_s64_f64(a);

    simde_test_arm_neon_write_f64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}
*/

static int
test_simde_vcvtpd_u64_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 a;
    uint64_t r;
  } test_vec[] = {
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
      {             SIMDE_MATH_NAN,
        INT64_C(           0) },
      { HEDLEY_STATIC_CAST(simde_float64, UINT64_MAX),
                  UINT64_MAX },
      { HEDLEY_STATIC_CAST(simde_float64, UINT64_MAX) + SIMDE_FLOAT64_C(10000.0),
                  UINT64_MAX },
      { SIMDE_FLOAT64_C(-1000.0),
        UINT64_C(         0) },
      { SIMDE_FLOAT64_C( -84790.281),
        UINT64_C(         0) },
      { SIMDE_FLOAT64_C( 0.0),
        UINT64_C(     0) },
    #endif
    {    SIMDE_FLOAT64_C( 60286.391),
         UINT64_C(     60287) },
    {    SIMDE_FLOAT64_C( 75317.063),
         UINT64_C(     75318) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64 a = test_vec[i].a;
    uint64_t r = simde_vcvtpd_u64_f64(a);
    simde_assert_equal_u64(r, test_vec[i].r);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64_t a = simde_test_arm_neon_random_f64(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde_uint64_t r = simde_vcvtpd_u64_f64(a);

    simde_test_arm_neon_write_f64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvtpq_u64_f64 (SIMDE_MUNIT_TEST_ARGS) {
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
    { { SIMDE_FLOAT64_C(   966.26), SIMDE_FLOAT64_C(   908.71) },
      { UINT64_C(                 967), UINT64_C(                 909) } },
    { { SIMDE_FLOAT64_C(   847.29), SIMDE_FLOAT64_C(   921.31) },
      { UINT64_C(                 848), UINT64_C(                 922) } },
    { { SIMDE_FLOAT64_C(   126.50), SIMDE_FLOAT64_C(   287.19) },
      { UINT64_C(                 127), UINT64_C(                 288) } },
    { { SIMDE_FLOAT64_C(   976.48), SIMDE_FLOAT64_C(   986.12) },
      { UINT64_C(                 977), UINT64_C(                 987) } },
    { { SIMDE_FLOAT64_C(   636.57), SIMDE_FLOAT64_C(   932.93) },
      { UINT64_C(                 637), UINT64_C(                 933) } },
    { { SIMDE_FLOAT64_C(   236.08), SIMDE_FLOAT64_C(   148.35) },
      { UINT64_C(                 237), UINT64_C(                 149) } },
    { { SIMDE_FLOAT64_C(   504.84), SIMDE_FLOAT64_C(   166.55) },
      { UINT64_C(                 505), UINT64_C(                 167) } },
    { { SIMDE_FLOAT64_C(   837.23), SIMDE_FLOAT64_C(   142.57) },
      { UINT64_C(                 838), UINT64_C(                 143) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2_t a = simde_vld1q_f64(test_vec[i].a);
    simde_uint64x2_t r = simde_vcvtpq_u64_f64(a);
    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x2_t a = simde_test_arm_neon_random_f64x2(SIMDE_FLOAT64_C(0.0), SIMDE_FLOAT64_C(1000.0));
    simde_uint64x2_t r = simde_vcvtpq_u64_f64(a);

    simde_test_arm_neon_write_f64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

/* Disabled until we fix the FCVTZS/FCVTMS/FCVTPS/FCVTNS family intrinsics
 * https://github.com/simd-everywhere/simde/issues/1099
static int
test_simde_vcvtpq_s16_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16_t a[8];
    int16_t r[8];
  } test_vec[] = {
    { { SIMDE_FLOAT16_VALUE( -    17.482),  SIMDE_FLOAT16_VALUE(    25.249), SIMDE_FLOAT16_VALUE( -    23.786),  SIMDE_FLOAT16_VALUE(    26.713),
        SIMDE_FLOAT16_VALUE( -    27.250), SIMDE_FLOAT16_VALUE( -    25.132),  SIMDE_FLOAT16_VALUE(    16.970),  SIMDE_FLOAT16_VALUE(     1.147) },
      { -INT16_C(        17),  INT16_C(        26), -INT16_C(        23),  INT16_C(        27),
        -INT16_C(        27), -INT16_C(        25),  INT16_C(        17),  INT16_C(         2) } },
    { { SIMDE_FLOAT16_VALUE( -    22.099), SIMDE_FLOAT16_VALUE( -    21.667), SIMDE_FLOAT16_VALUE( -     8.017), SIMDE_FLOAT16_VALUE( -     2.271),
        SIMDE_FLOAT16_VALUE( -    12.312),  SIMDE_FLOAT16_VALUE(    22.849),  SIMDE_FLOAT16_VALUE(    15.892), SIMDE_FLOAT16_VALUE( -     8.588) },
      { -INT16_C(        22), -INT16_C(        21), -INT16_C(         8), -INT16_C(         2),
        -INT16_C(        12),  INT16_C(        23),  INT16_C(        16), -INT16_C(         8) } },
    { {  SIMDE_FLOAT16_VALUE(     2.094), SIMDE_FLOAT16_VALUE( -     2.744), SIMDE_FLOAT16_VALUE( -    25.968), SIMDE_FLOAT16_VALUE( -    21.280),
         SIMDE_FLOAT16_VALUE(    19.739),  SIMDE_FLOAT16_VALUE(    20.780), SIMDE_FLOAT16_VALUE( -     3.155),  SIMDE_FLOAT16_VALUE(    19.892) },
      {  INT16_C(         3), -INT16_C(         2), -INT16_C(        25), -INT16_C(        21),
         INT16_C(        20),  INT16_C(        21), -INT16_C(         3),  INT16_C(        20) } },
    { { SIMDE_FLOAT16_VALUE( -    17.802), SIMDE_FLOAT16_VALUE( -     7.956), SIMDE_FLOAT16_VALUE( -    25.547),  SIMDE_FLOAT16_VALUE(    29.976),
        SIMDE_FLOAT16_VALUE( -    16.109), SIMDE_FLOAT16_VALUE( -     0.241), SIMDE_FLOAT16_VALUE( -    17.325),  SIMDE_FLOAT16_VALUE(     2.343) },
      { -INT16_C(        17), -INT16_C(         7), -INT16_C(        25),  INT16_C(        30),
        -INT16_C(        16),  INT16_C(         0), -INT16_C(        17),  INT16_C(         3) } },
    { { SIMDE_FLOAT16_VALUE( -     2.318),  SIMDE_FLOAT16_VALUE(    27.885),  SIMDE_FLOAT16_VALUE(    10.828),  SIMDE_FLOAT16_VALUE(    16.530),
         SIMDE_FLOAT16_VALUE(    19.659), SIMDE_FLOAT16_VALUE( -    11.861), SIMDE_FLOAT16_VALUE( -    15.435), SIMDE_FLOAT16_VALUE( -    22.972) },
      { -INT16_C(         2),  INT16_C(        28),  INT16_C(        11),  INT16_C(        17),
         INT16_C(        20), -INT16_C(        11), -INT16_C(        15), -INT16_C(        22) } },
    { { SIMDE_FLOAT16_VALUE( -    26.398),  SIMDE_FLOAT16_VALUE(    12.636),  SIMDE_FLOAT16_VALUE(    23.632),  SIMDE_FLOAT16_VALUE(    22.209),
         SIMDE_FLOAT16_VALUE(    16.480), SIMDE_FLOAT16_VALUE( -     8.479), SIMDE_FLOAT16_VALUE( -    11.944), SIMDE_FLOAT16_VALUE( -    10.576) },
      { -INT16_C(        26),  INT16_C(        13),  INT16_C(        24),  INT16_C(        23),
         INT16_C(        17), -INT16_C(         8), -INT16_C(        11), -INT16_C(        10) } },
    { {  SIMDE_FLOAT16_VALUE(    10.556),  SIMDE_FLOAT16_VALUE(    14.462),  SIMDE_FLOAT16_VALUE(     4.323),  SIMDE_FLOAT16_VALUE(    29.542),
        SIMDE_FLOAT16_VALUE( -    13.708), SIMDE_FLOAT16_VALUE( -    11.548),  SIMDE_FLOAT16_VALUE(    13.467),  SIMDE_FLOAT16_VALUE(     4.887) },
      {  INT16_C(        11),  INT16_C(        15),  INT16_C(         5),  INT16_C(        30),
        -INT16_C(        13), -INT16_C(        11),  INT16_C(        14),  INT16_C(         5) } },
    { { SIMDE_FLOAT16_VALUE( -    28.249),  SIMDE_FLOAT16_VALUE(    10.669),  SIMDE_FLOAT16_VALUE(    15.634), SIMDE_FLOAT16_VALUE( -    29.024),
        SIMDE_FLOAT16_VALUE( -     5.544),  SIMDE_FLOAT16_VALUE(     5.271),  SIMDE_FLOAT16_VALUE(     7.326),  SIMDE_FLOAT16_VALUE(    22.421) },
      { -INT16_C(        28),  INT16_C(        11),  INT16_C(        16), -INT16_C(        29),
        -INT16_C(         5),  INT16_C(         6),  INT16_C(         8),  INT16_C(        23) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x8_t a = simde_vld1q_f16(test_vec[i].a);
    simde_int16x8_t r = simde_vcvtpq_s16_f16(a);
    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16x8_t a = simde_test_arm_neon_random_f16x8(-100.0f, 100.0f);
    simde_int16x8_t r = simde_vcvtpq_s16_f16(a);

    simde_test_arm_neon_write_f16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvtp_s16_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16_t a[4];
    int16_t r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT16_VALUE( -    24.451), SIMDE_FLOAT16_VALUE( -    26.951),  SIMDE_FLOAT16_VALUE(     4.545), SIMDE_FLOAT16_VALUE( -    16.203) },
      { -INT16_C(        24), -INT16_C(        26),  INT16_C(         5), -INT16_C(        16) } },
    { { SIMDE_FLOAT16_VALUE( -     6.971), SIMDE_FLOAT16_VALUE( -     0.372), SIMDE_FLOAT16_VALUE( -    23.985), SIMDE_FLOAT16_VALUE( -     5.566) },
      { -INT16_C(         6),  INT16_C(         0), -INT16_C(        23), -INT16_C(         5) } },
    { { SIMDE_FLOAT16_VALUE( -    17.684), SIMDE_FLOAT16_VALUE( -    12.522), SIMDE_FLOAT16_VALUE( -    26.196), SIMDE_FLOAT16_VALUE( -    17.907) },
      { -INT16_C(        17), -INT16_C(        12), -INT16_C(        26), -INT16_C(        17) } },
    { { SIMDE_FLOAT16_VALUE( -    15.913),  SIMDE_FLOAT16_VALUE(    11.327), SIMDE_FLOAT16_VALUE( -    20.331),  SIMDE_FLOAT16_VALUE(     6.990) },
      { -INT16_C(        15),  INT16_C(        12), -INT16_C(        20),  INT16_C(         7) } },
    { { SIMDE_FLOAT16_VALUE( -     7.259),  SIMDE_FLOAT16_VALUE(    10.857), SIMDE_FLOAT16_VALUE( -    14.002),  SIMDE_FLOAT16_VALUE(    16.367) },
      { -INT16_C(         7),  INT16_C(        11), -INT16_C(        14),  INT16_C(        17) } },
    { { SIMDE_FLOAT16_VALUE( -    14.487),  SIMDE_FLOAT16_VALUE(    25.818),  SIMDE_FLOAT16_VALUE(    25.545), SIMDE_FLOAT16_VALUE( -     9.464) },
      { -INT16_C(        14),  INT16_C(        26),  INT16_C(        26), -INT16_C(         9) } },
    { {  SIMDE_FLOAT16_VALUE(    10.801), SIMDE_FLOAT16_VALUE( -    16.889),  SIMDE_FLOAT16_VALUE(    15.712), SIMDE_FLOAT16_VALUE( -    26.668) },
      {  INT16_C(        11), -INT16_C(        16),  INT16_C(        16), -INT16_C(        26) } },
    { {  SIMDE_FLOAT16_VALUE(    16.707), SIMDE_FLOAT16_VALUE( -     6.907), SIMDE_FLOAT16_VALUE( -    16.125),  SIMDE_FLOAT16_VALUE(    16.581) },
      {  INT16_C(        17), -INT16_C(         6), -INT16_C(        16),  INT16_C(        17) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x4_t a = simde_vld1_f16(test_vec[i].a);
    simde_int16x4_t r = simde_vcvtp_s16_f16(a);
    simde_test_arm_neon_assert_equal_i16x4(r, simde_vld1_s16(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16x4_t a = simde_test_arm_neon_random_f16x4(-100.0f, 100.0f);
    simde_int16x4_t r = simde_vcvtp_s16_f16(a);

    simde_test_arm_neon_write_f16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}
*/

static int
test_simde_vcvtpq_u16_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16_t a[8];
    uint16_t r[8];
  } test_vec[] = {
    { { SIMDE_FLOAT16_VALUE(    14.36), SIMDE_FLOAT16_VALUE(    34.09), SIMDE_FLOAT16_VALUE(    69.00), SIMDE_FLOAT16_VALUE(     4.10),
        SIMDE_FLOAT16_VALUE(    51.00), SIMDE_FLOAT16_VALUE(    31.69), SIMDE_FLOAT16_VALUE(    40.94), SIMDE_FLOAT16_VALUE(    90.44) },
      { UINT16_C(   15), UINT16_C(   35), UINT16_C(   69), UINT16_C(    5), UINT16_C(   51), UINT16_C(   32), UINT16_C(   41), UINT16_C(   91) } },
    { { SIMDE_FLOAT16_VALUE(    17.02), SIMDE_FLOAT16_VALUE(    50.97), SIMDE_FLOAT16_VALUE(    36.22), SIMDE_FLOAT16_VALUE(    91.44),
        SIMDE_FLOAT16_VALUE(    80.12), SIMDE_FLOAT16_VALUE(    74.88), SIMDE_FLOAT16_VALUE(    25.30), SIMDE_FLOAT16_VALUE(    71.44) },
      { UINT16_C(   18), UINT16_C(   51), UINT16_C(   37), UINT16_C(   92), UINT16_C(   81), UINT16_C(   75), UINT16_C(   26), UINT16_C(   72) } },
    { { SIMDE_FLOAT16_VALUE(    29.02), SIMDE_FLOAT16_VALUE(     1.47), SIMDE_FLOAT16_VALUE(    45.03), SIMDE_FLOAT16_VALUE(    76.00),
        SIMDE_FLOAT16_VALUE(    86.69), SIMDE_FLOAT16_VALUE(    69.94), SIMDE_FLOAT16_VALUE(    51.69), SIMDE_FLOAT16_VALUE(    76.00) },
      { UINT16_C(   30), UINT16_C(    2), UINT16_C(   46), UINT16_C(   76), UINT16_C(   87), UINT16_C(   70), UINT16_C(   52), UINT16_C(   76) } },
    { { SIMDE_FLOAT16_VALUE(    21.06), SIMDE_FLOAT16_VALUE(     8.94), SIMDE_FLOAT16_VALUE(    37.00), SIMDE_FLOAT16_VALUE(    31.73),
        SIMDE_FLOAT16_VALUE(    99.62), SIMDE_FLOAT16_VALUE(    52.44), SIMDE_FLOAT16_VALUE(    81.81), SIMDE_FLOAT16_VALUE(    14.01) },
      { UINT16_C(   22), UINT16_C(    9), UINT16_C(   37), UINT16_C(   32), UINT16_C(  100), UINT16_C(   53), UINT16_C(   82), UINT16_C(   15) } },
    { { SIMDE_FLOAT16_VALUE(    86.50), SIMDE_FLOAT16_VALUE(    50.81), SIMDE_FLOAT16_VALUE(    18.11), SIMDE_FLOAT16_VALUE(    37.53),
        SIMDE_FLOAT16_VALUE(    82.50), SIMDE_FLOAT16_VALUE(    59.06), SIMDE_FLOAT16_VALUE(    27.95), SIMDE_FLOAT16_VALUE(    99.50) },
      { UINT16_C(   87), UINT16_C(   51), UINT16_C(   19), UINT16_C(   38), UINT16_C(   83), UINT16_C(   60), UINT16_C(   28), UINT16_C(  100) } },
    { { SIMDE_FLOAT16_VALUE(    10.01), SIMDE_FLOAT16_VALUE(    64.19), SIMDE_FLOAT16_VALUE(    90.94), SIMDE_FLOAT16_VALUE(    90.12),
        SIMDE_FLOAT16_VALUE(    39.03), SIMDE_FLOAT16_VALUE(    16.23), SIMDE_FLOAT16_VALUE(    61.53), SIMDE_FLOAT16_VALUE(    68.06) },
      { UINT16_C(   11), UINT16_C(   65), UINT16_C(   91), UINT16_C(   91), UINT16_C(   40), UINT16_C(   17), UINT16_C(   62), UINT16_C(   69) } },
    { { SIMDE_FLOAT16_VALUE(    17.70), SIMDE_FLOAT16_VALUE(     6.58), SIMDE_FLOAT16_VALUE(    44.03), SIMDE_FLOAT16_VALUE(     4.38),
        SIMDE_FLOAT16_VALUE(    76.50), SIMDE_FLOAT16_VALUE(    95.75), SIMDE_FLOAT16_VALUE(    80.38), SIMDE_FLOAT16_VALUE(    97.56) },
      { UINT16_C(   18), UINT16_C(    7), UINT16_C(   45), UINT16_C(    5), UINT16_C(   77), UINT16_C(   96), UINT16_C(   81), UINT16_C(   98) } },
    { { SIMDE_FLOAT16_VALUE(     4.68), SIMDE_FLOAT16_VALUE(    17.34), SIMDE_FLOAT16_VALUE(    29.30), SIMDE_FLOAT16_VALUE(     4.33),
        SIMDE_FLOAT16_VALUE(    69.75), SIMDE_FLOAT16_VALUE(    11.14), SIMDE_FLOAT16_VALUE(    18.34), SIMDE_FLOAT16_VALUE(    56.31) },
      { UINT16_C(    5), UINT16_C(   18), UINT16_C(   30), UINT16_C(    5), UINT16_C(   70), UINT16_C(   12), UINT16_C(   19), UINT16_C(   57) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x8_t a = simde_vld1q_f16(test_vec[i].a);
    simde_uint16x8_t r = simde_vcvtpq_u16_f16(a);
    simde_test_arm_neon_assert_equal_u16x8(r, simde_vld1q_u16(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16x8_t a = simde_test_arm_neon_random_f16x8(0.0f, 100.0f);
    simde_uint16x8_t r = simde_vcvtpq_u16_f16(a);

    simde_test_arm_neon_write_f16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvtp_u16_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16_t a[4];
    uint16_t r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT16_VALUE(    92.38), SIMDE_FLOAT16_VALUE(    41.81), SIMDE_FLOAT16_VALUE(    12.00), SIMDE_FLOAT16_VALUE(    86.38) },
      { UINT16_C(   93), UINT16_C(   42), UINT16_C(   12), UINT16_C(   87) } },
    { { SIMDE_FLOAT16_VALUE(    83.69), SIMDE_FLOAT16_VALUE(    72.44), SIMDE_FLOAT16_VALUE(    21.73), SIMDE_FLOAT16_VALUE(    51.94) },
      { UINT16_C(   84), UINT16_C(   73), UINT16_C(   22), UINT16_C(   52) } },
    { { SIMDE_FLOAT16_VALUE(    73.50), SIMDE_FLOAT16_VALUE(    84.75), SIMDE_FLOAT16_VALUE(    27.58), SIMDE_FLOAT16_VALUE(    35.84) },
      { UINT16_C(   74), UINT16_C(   85), UINT16_C(   28), UINT16_C(   36) } },
    { { SIMDE_FLOAT16_VALUE(    77.38), SIMDE_FLOAT16_VALUE(    63.91), SIMDE_FLOAT16_VALUE(    92.06), SIMDE_FLOAT16_VALUE(    92.00) },
      { UINT16_C(   78), UINT16_C(   64), UINT16_C(   93), UINT16_C(   92) } },
    { { SIMDE_FLOAT16_VALUE(    60.22), SIMDE_FLOAT16_VALUE(     3.73), SIMDE_FLOAT16_VALUE(    84.62), SIMDE_FLOAT16_VALUE(    88.56) },
      { UINT16_C(   61), UINT16_C(    4), UINT16_C(   85), UINT16_C(   89) } },
    { { SIMDE_FLOAT16_VALUE(     5.28), SIMDE_FLOAT16_VALUE(    54.75), SIMDE_FLOAT16_VALUE(     2.63), SIMDE_FLOAT16_VALUE(    30.70) },
      { UINT16_C(    6), UINT16_C(   55), UINT16_C(    3), UINT16_C(   31) } },
    { { SIMDE_FLOAT16_VALUE(    41.84), SIMDE_FLOAT16_VALUE(     2.31), SIMDE_FLOAT16_VALUE(    86.88), SIMDE_FLOAT16_VALUE(    82.25) },
      { UINT16_C(   42), UINT16_C(    3), UINT16_C(   87), UINT16_C(   83) } },
    { { SIMDE_FLOAT16_VALUE(    83.00), SIMDE_FLOAT16_VALUE(    78.25), SIMDE_FLOAT16_VALUE(     9.41), SIMDE_FLOAT16_VALUE(    75.31) },
      { UINT16_C(   83), UINT16_C(   79), UINT16_C(   10), UINT16_C(   76) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x4_t a = simde_vld1_f16(test_vec[i].a);
    simde_uint16x4_t r = simde_vcvtp_u16_f16(a);
    simde_test_arm_neon_assert_equal_u16x4(r, simde_vld1_u16(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16x4_t a = simde_test_arm_neon_random_f16x4(0.0f, 100.0f);
    simde_uint16x4_t r = simde_vcvtp_u16_f16(a);

    simde_test_arm_neon_write_f16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvtp_u32_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float32 a[2];
    uint32_t r[2];
  } test_vec[] = {
    { {  SIMDE_FLOAT32_C(   610.058),  SIMDE_FLOAT32_C(   408.327) },
      {  UINT32_C(       611),  UINT32_C(       409) } },
    { {  SIMDE_FLOAT32_C(   683.218),  SIMDE_FLOAT32_C(   523.587) },
      {  UINT32_C(       684),  UINT32_C(       524) } },
    { {  SIMDE_FLOAT32_C(   840.155),  SIMDE_FLOAT32_C(   535.544) },
      {  UINT32_C(       841),  UINT32_C(       536) } },
    { {  SIMDE_FLOAT32_C(   878.489),  SIMDE_FLOAT32_C(   177.802) },
      {  UINT32_C(       879),  UINT32_C(       178) } },
    { {  SIMDE_FLOAT32_C(   160.684),  SIMDE_FLOAT32_C(   430.784) },
      {  UINT32_C(       161),  UINT32_C(       431) } },
    { {  SIMDE_FLOAT32_C(   816.827),  SIMDE_FLOAT32_C(   582.145) },
      {  UINT32_C(       817),  UINT32_C(       583) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t a = simde_vld1_f32(test_vec[i].a);
    simde_uint32x2_t r = simde_vcvtp_u32_f32(a);
    simde_test_arm_neon_assert_equal_u32x2(r, simde_vld1_u32(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x2_t a = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f);
    simde_uint32x2_t r = simde_vcvtp_u32_f32(a);

    simde_test_arm_neon_write_f32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

/* Disabled until we fix the FCVTZS/FCVTMS/FCVTPS/FCVTNS family intrinsics
 * https://github.com/simd-everywhere/simde/issues/1099
static int
test_simde_vcvtp_s32_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float32 a[2];
    int32_t r[2];
  } test_vec[] = {
    { { -SIMDE_FLOAT32_C(   308.681),  SIMDE_FLOAT32_C(   253.856) },
      { -INT32_C(       308),  INT32_C(       254) } },
    { {  SIMDE_FLOAT32_C(   415.847), -SIMDE_FLOAT32_C(   667.662) },
      {  INT32_C(       416), -INT32_C(       667) } },
    { {  SIMDE_FLOAT32_C(   225.278), -SIMDE_FLOAT32_C(   604.949) },
      {  INT32_C(       226), -INT32_C(       604) } },
    { {  SIMDE_FLOAT32_C(   924.365),  SIMDE_FLOAT32_C(   945.477) },
      {  INT32_C(       925),  INT32_C(       946) } },
    { {  SIMDE_FLOAT32_C(   895.563),  SIMDE_FLOAT32_C(    45.311) },
      {  INT32_C(       896),  INT32_C(        46) } },
    { { -SIMDE_FLOAT32_C(   317.703), -SIMDE_FLOAT32_C(   868.310) },
      { -INT32_C(       317), -INT32_C(       868) } },
    { {  SIMDE_FLOAT32_C(   541.485), -SIMDE_FLOAT32_C(   504.698) },
      {  INT32_C(       542), -INT32_C(       504) } },
    { { -SIMDE_FLOAT32_C(   653.810), -SIMDE_FLOAT32_C(   265.026) },
      { -INT32_C(       653), -INT32_C(       265) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t a = simde_vld1_f32(test_vec[i].a);
    simde_int32x2_t r = simde_vcvtp_s32_f32(a);
    simde_test_arm_neon_assert_equal_i32x2(r, simde_vld1_s32(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x2_t a = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f);
    simde_int32x2_t r = simde_vcvtp_s32_f32(a);

    simde_test_arm_neon_write_f32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvtp_s64_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float64 a[1];
    int64_t r[1];
  } test_vec[] = {
    { {  SIMDE_FLOAT64_C( 24965.766) },
      {  INT64_C(     24966) } },
    { { -SIMDE_FLOAT64_C( 30984.422) },
      { -INT64_C(     30984) } },
    { { -SIMDE_FLOAT64_C( 16724.391) },
      { -INT64_C(     16724) } },
    { {  SIMDE_FLOAT64_C( 31802.109) },
      {  INT64_C(     31803) } },
    { {  SIMDE_FLOAT64_C( 46616.438) },
      {  INT64_C(     46617) } },
    { {  SIMDE_FLOAT64_C( 57103.266) },
      {  INT64_C(     57104) } },
    { { -SIMDE_FLOAT64_C( 21279.477) },
      { -INT64_C(     21279) } },
    { { -SIMDE_FLOAT64_C( 18106.797) },
      { -INT64_C(     18106) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x1_t a = simde_vld1_f64(test_vec[i].a);
    simde_int64x1_t r = simde_vcvtp_s64_f64(a);
    simde_test_arm_neon_assert_equal_i64x1(r, simde_vld1_s64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x1_t a = simde_test_arm_neon_random_f64x1(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde_int64x1_t r = simde_vcvtp_s64_f64(a);

    simde_test_arm_neon_write_f64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}
*/

static int
test_simde_vcvtp_u64_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float64 a[1];
    uint64_t r[1];
  } test_vec[] = {
    { {  SIMDE_FLOAT64_C( 20147.570) },
      {  UINT64_C(     20148) } },
    { {  SIMDE_FLOAT64_C( 83020.297) },
      {  UINT64_C(     83021) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x1_t a = simde_vld1_f64(test_vec[i].a);
    simde_uint64x1_t r = simde_vcvtp_u64_f64(a);
    simde_test_arm_neon_assert_equal_u64x1(r, simde_vld1_u64(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x1_t a = simde_test_arm_neon_random_f64x1(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde_uint64x1_t r = simde_vcvtp_u64_f64(a);

    simde_test_arm_neon_write_f64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
//SIMDE_TEST_FUNC_LIST_ENTRY(vcvtps_s32_f32)
//SIMDE_TEST_FUNC_LIST_ENTRY(vcvtpd_s64_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtps_u32_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtpd_u64_f64)

//SIMDE_TEST_FUNC_LIST_ENTRY(vcvtph_s16_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtph_s32_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtph_s64_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtph_u16_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtph_u32_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtph_u64_f16)

//SIMDE_TEST_FUNC_LIST_ENTRY(vcvtp_s16_f16)
//SIMDE_TEST_FUNC_LIST_ENTRY(vcvtp_s32_f32)
//SIMDE_TEST_FUNC_LIST_ENTRY(vcvtp_s64_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtp_u16_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtp_u32_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtp_u64_f64)

//SIMDE_TEST_FUNC_LIST_ENTRY(vcvtpq_s16_f16)
//SIMDE_TEST_FUNC_LIST_ENTRY(vcvtpq_s32_f32)
//SIMDE_TEST_FUNC_LIST_ENTRY(vcvtpq_s64_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtpq_u16_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtpq_u32_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtpq_u64_f64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
