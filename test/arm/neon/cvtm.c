#define SIMDE_TEST_ARM_NEON_INSN cvtm

#include "test-neon.h"
#include "../../../simde/arm/neon/cvtm.h"

/* Disabled until we fix the FCVTZS/FCVTMS/FCVTPS/FCVTNS family intrinsics
 * https://github.com/simd-everywhere/simde/issues/1099
static int
test_simde_vcvtmq_s32_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a[4];
    int32_t r[4];
  } test_vec[] = {
    { {  SIMDE_FLOAT32_C(   404.944),  SIMDE_FLOAT32_C(   424.355),  SIMDE_FLOAT32_C(   955.709), -SIMDE_FLOAT32_C(   841.813) },
      {  INT32_C(       404),  INT32_C(       424),  INT32_C(       955), -INT32_C(       842) } },
    { {  SIMDE_FLOAT32_C(    34.258), -SIMDE_FLOAT32_C(   239.332), -SIMDE_FLOAT32_C(   971.203), -SIMDE_FLOAT32_C(   672.986) },
      {  INT32_C(        34), -INT32_C(       240), -INT32_C(       972), -INT32_C(       673) } },
    { {  SIMDE_FLOAT32_C(   604.428),  SIMDE_FLOAT32_C(   472.493),  SIMDE_FLOAT32_C(   491.446),  SIMDE_FLOAT32_C(   510.090) },
      {  INT32_C(       604),  INT32_C(       472),  INT32_C(       491),  INT32_C(       510) } },
    { {  SIMDE_FLOAT32_C(   883.445), -SIMDE_FLOAT32_C(   876.070),  SIMDE_FLOAT32_C(   620.121), -SIMDE_FLOAT32_C(    97.364) },
      {  INT32_C(       883), -INT32_C(       877),  INT32_C(       620), -INT32_C(        98) } },
    { { -SIMDE_FLOAT32_C(   696.852),  SIMDE_FLOAT32_C(   176.132), -SIMDE_FLOAT32_C(    84.301),  SIMDE_FLOAT32_C(   639.894) },
      { -INT32_C(       697),  INT32_C(       176), -INT32_C(        85),  INT32_C(       639) } },
    { { -SIMDE_FLOAT32_C(   630.062),  SIMDE_FLOAT32_C(   393.803),  SIMDE_FLOAT32_C(   853.109),  SIMDE_FLOAT32_C(   346.168) },
      { -INT32_C(       631),  INT32_C(       393),  INT32_C(       853),  INT32_C(       346) } },
    { {  SIMDE_FLOAT32_C(   720.840), -SIMDE_FLOAT32_C(   629.362), -SIMDE_FLOAT32_C(   168.845), -SIMDE_FLOAT32_C(   790.098) },
      {  INT32_C(       720), -INT32_C(       630), -INT32_C(       169), -INT32_C(       791) } },
    { { -SIMDE_FLOAT32_C(   617.821), -SIMDE_FLOAT32_C(   162.686),  SIMDE_FLOAT32_C(    19.353),  SIMDE_FLOAT32_C(   212.584) },
      { -INT32_C(       618), -INT32_C(       163),  INT32_C(        19),  INT32_C(       212) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_int32x4_t r = simde_vcvtmq_s32_f32(a);
    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x4_t a = simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f);
    simde_int32x4_t r = simde_vcvtmq_s32_f32(a);

    simde_test_arm_neon_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvtmq_s64_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 a[2];
    int64_t r[2];
  } test_vec[] = {
    { { -SIMDE_FLOAT64_C( 94430.055), -SIMDE_FLOAT64_C(  3762.398) },
      { -INT64_C(     94431), -INT64_C(      3763) } },
    { {  SIMDE_FLOAT64_C(  6248.047),  SIMDE_FLOAT64_C(  7172.813) },
      {  INT64_C(      6248),  INT64_C(      7172) } },
    { {  SIMDE_FLOAT64_C( 27462.281),  SIMDE_FLOAT64_C( 80763.266) },
      {  INT64_C(     27462),  INT64_C(     80763) } },
    { {  SIMDE_FLOAT64_C( 43674.109),  SIMDE_FLOAT64_C( 69458.109) },
      {  INT64_C(     43674),  INT64_C(     69458) } },
    { {  SIMDE_FLOAT64_C( 90122.016), -SIMDE_FLOAT64_C( 67679.383) },
      {  INT64_C(     90122), -INT64_C(     67680) } },
    { { -SIMDE_FLOAT64_C( 65745.375), -SIMDE_FLOAT64_C( 79947.688) },
      { -INT64_C(     65746), -INT64_C(     79948) } },
    { {  SIMDE_FLOAT64_C( 93151.797), -SIMDE_FLOAT64_C( 13928.320) },
      {  INT64_C(     93151), -INT64_C(     13929) } },
    { {  SIMDE_FLOAT64_C( 35406.250), -SIMDE_FLOAT64_C( 43005.527) },
      {  INT64_C(     35406), -INT64_C(     43006) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2_t a = simde_vld1q_f64(test_vec[i].a);
    simde_int64x2_t r = simde_vcvtmq_s64_f64(a);
    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x2_t a = simde_test_arm_neon_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde_int64x2_t r = simde_vcvtmq_s64_f64(a);

    simde_test_arm_neon_write_f64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}
*/

static int
test_simde_vcvtmh_s64_f16 (SIMDE_MUNIT_TEST_ARGS) {
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
    {   SIMDE_FLOAT16_VALUE( 0.0),
        INT64_C(        0) },
    #endif
    {   SIMDE_FLOAT16_VALUE( -    29.102),
        -INT64_C(        30) },
    {   SIMDE_FLOAT16_VALUE( -    15.400),
        -INT64_C(        16) },
    {   SIMDE_FLOAT16_VALUE( -     5.887),
        -INT64_C(         6) },
    {    SIMDE_FLOAT16_VALUE(    16.529),
         INT64_C(        16) },
    {    SIMDE_FLOAT16_VALUE(    17.641),
         INT64_C(        17) },
    {    SIMDE_FLOAT16_VALUE(    16.624),
         INT64_C(        16) },
    {    SIMDE_FLOAT16_VALUE(    14.373),
         INT64_C(        14) },
    {   SIMDE_FLOAT16_VALUE( -    16.813),
        -INT64_C(        17) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16_t a = test_vec[i].a;
    int64_t r = simde_vcvtmh_s64_f16(a);
    simde_assert_equal_i64(r, test_vec[i].r);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16_t a = simde_test_arm_neon_random_f16(-100.0f, 100.0f);
    simde_int64_t r = simde_vcvtmh_s64_f16(a);

    simde_test_arm_neon_write_f16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvtmh_s32_f16 (SIMDE_MUNIT_TEST_ARGS) {
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
    { SIMDE_FLOAT16_VALUE(   0.0),
      INT32_C(       0) },
    #endif
    { SIMDE_FLOAT16_VALUE(   12.44),
      INT32_C(       12) },
    { SIMDE_FLOAT16_VALUE(   30.46),
      INT32_C(       30) },
    { SIMDE_FLOAT16_VALUE(   16.51),
      INT32_C(       16) },
    { SIMDE_FLOAT16_VALUE(   74.89),
      INT32_C(       74) },
    { SIMDE_FLOAT16_VALUE(   -24.05),
      -INT32_C(       25) },
    { SIMDE_FLOAT16_VALUE(   -7.75),
      -INT32_C(       8) },
    { SIMDE_FLOAT16_VALUE(   -57.31),
      -INT32_C(       58) },
    { SIMDE_FLOAT16_VALUE(   -14.65),
      -INT32_C(       15) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16_t a = test_vec[i].a;
    int32_t r = simde_vcvtmh_s32_f16(a);
    simde_assert_equal_i32(r, test_vec[i].r);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16_t a = simde_test_arm_neon_random_f16(-100.0f, 100.0f);
    simde_int32_t r = simde_vcvtmh_s32_f16(a);

    simde_test_arm_neon_write_f16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

/* Disabled until we fix the FCVTZS/FCVTMS/FCVTPS/FCVTNS family intrinsics
 * https://github.com/simd-everywhere/simde/issues/1099
static int
test_simde_vcvtmh_s16_f16 (SIMDE_MUNIT_TEST_ARGS) {
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
    {   SIMDE_FLOAT16_VALUE(     0.0),
        INT16_C(        0) },
    #endif
    {   SIMDE_FLOAT16_VALUE( -    15.279),
        -INT16_C(        16) },
    {   SIMDE_FLOAT16_VALUE( -    15.541),
        -INT16_C(        16) },
    {    SIMDE_FLOAT16_VALUE(    24.266),
         INT16_C(        24) },
    {    SIMDE_FLOAT16_VALUE(    28.626),
         INT16_C(        28) },
    {   SIMDE_FLOAT16_VALUE( -    17.731),
        -INT16_C(        18) },
    {   SIMDE_FLOAT16_VALUE( -    14.985),
        -INT16_C(        15) },
    {   SIMDE_FLOAT16_VALUE( -    26.154),
        -INT16_C(        27) },
    {    SIMDE_FLOAT16_VALUE(     5.330),
         INT16_C(         5) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16_t a = test_vec[i].a;
    int16_t r = simde_vcvtmh_s16_f16(a);
    simde_assert_equal_i16(r, test_vec[i].r);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16_t a = simde_test_arm_neon_random_f16(-100.0f, 100.0f);
    simde_int16_t r = simde_vcvtmh_s16_f16(a);

    simde_test_arm_neon_write_f16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvtms_s32_f32 (SIMDE_MUNIT_TEST_ARGS) {
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
      { SIMDE_FLOAT32_C(   0.0),
        INT32_C(       0) },
    #endif
    {   -SIMDE_FLOAT32_C(   842.300),
        -INT32_C(       843) },
    {   -SIMDE_FLOAT32_C(   649.091),
        -INT32_C(       650) },
    {    SIMDE_FLOAT32_C(   310.002),
         INT32_C(       310) },
    {   -SIMDE_FLOAT32_C(   803.887),
        -INT32_C(       804) },
    {   -SIMDE_FLOAT32_C(   527.652),
        -INT32_C(       528) },
    {   -SIMDE_FLOAT32_C(   327.117),
        -INT32_C(       328) },
    {    SIMDE_FLOAT32_C(   198.410),
         INT32_C(       198) },
    {   -SIMDE_FLOAT32_C(    75.376),
        -INT32_C(        76) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32 a = test_vec[i].a;
    int32_t r = simde_vcvtms_s32_f32(a);
    simde_assert_equal_i32(r, test_vec[i].r);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32_t a = simde_test_arm_neon_random_f32(-1000.0f, 1000.0f);
    simde_int32_t r = simde_vcvtms_s32_f32(a);

    simde_test_arm_neon_write_f32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}
*/

static int
test_simde_vcvtmh_u64_f16 (SIMDE_MUNIT_TEST_ARGS) {
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
      { SIMDE_FLOAT16_VALUE( 0.0),
        UINT64_C(         0) },
    #endif
    {    SIMDE_FLOAT16_VALUE(    10.401),
         UINT64_C(        10) },
    {    SIMDE_FLOAT16_VALUE(    11.014),
         UINT64_C(        11) },
    {    SIMDE_FLOAT16_VALUE(    20.952),
         UINT64_C(        20) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16_t a = test_vec[i].a;
    uint64_t r = simde_vcvtmh_u64_f16(a);
    simde_assert_equal_u64(r, test_vec[i].r);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16_t a = simde_test_arm_neon_random_f16(-100.0f, 100.0f);
    simde_uint64_t r = simde_vcvtmh_u64_f16(a);

    simde_test_arm_neon_write_f16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvtmh_u32_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16_t a;
    uint32_t r;
  } test_vec[] = {
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
      {            SIMDE_NANHF,
        UINT32_C(           0) },
      { simde_float16_from_float32(HEDLEY_STATIC_CAST(simde_float32, UINT32_MAX)),
                  UINT32_MAX },
      { simde_float16_from_float32(HEDLEY_STATIC_CAST(simde_float32, UINT32_MAX+1000ll)),
                  UINT32_MAX },
      { SIMDE_FLOAT16_VALUE(-1000.0),
        UINT32_C(         0) },
      { SIMDE_FLOAT16_VALUE(     0.0),
        UINT32_C(         0) },
    #endif
    {    SIMDE_FLOAT16_VALUE(     0.691),
         UINT32_C(         0) },
    {    SIMDE_FLOAT16_VALUE(    24.104),
         UINT32_C(        24) },
    {    SIMDE_FLOAT16_VALUE(     5.841),
         UINT32_C(         5) },
    {    SIMDE_FLOAT16_VALUE(    23.950),
         UINT32_C(        23) },
    {    SIMDE_FLOAT16_VALUE(     1.348),
         UINT32_C(         1) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16_t a = test_vec[i].a;
    uint32_t r = simde_vcvtmh_u32_f16(a);
    simde_assert_equal_u32(r, test_vec[i].r);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16_t a = simde_test_arm_neon_random_f16(-100.0f, 100.0f);
    simde_uint32_t r = simde_vcvtmh_u32_f16(a);

    simde_test_arm_neon_write_f16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvtmh_u16_f16 (SIMDE_MUNIT_TEST_ARGS) {
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
      { SIMDE_FLOAT16_VALUE( 0.0),
        UINT16_C(         0) },
    #endif
    {    SIMDE_FLOAT16_VALUE(    28.461),
         UINT16_C(        28) },
    {    SIMDE_FLOAT16_VALUE(    16.044),
         UINT16_C(        16) },
    {    SIMDE_FLOAT16_VALUE(     5.757),
         UINT16_C(         5) },
    {    SIMDE_FLOAT16_VALUE(     4.509),
         UINT16_C(         4) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16_t a = test_vec[i].a;
    uint16_t r = simde_vcvtmh_u16_f16(a);
    simde_assert_equal_u16(r, test_vec[i].r);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16_t a = simde_test_arm_neon_random_f16(-100.0f, 100.0f);
    simde_uint16_t r = simde_vcvtmh_u16_f16(a);

    simde_test_arm_neon_write_f16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvtms_u32_f32 (SIMDE_MUNIT_TEST_ARGS) {
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
      { SIMDE_FLOAT32_C(   0.0),
        UINT32_C(         0) },
    #endif
    {    SIMDE_FLOAT32_C(   550.582),
         UINT32_C(       550) },
    {    SIMDE_FLOAT32_C(   378.414),
         UINT32_C(       378) },
    {    SIMDE_FLOAT32_C(   903.633),
         UINT32_C(       903) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32 a = test_vec[i].a;
    uint32_t r = simde_vcvtms_u32_f32(a);
    simde_assert_equal_u32(r, test_vec[i].r);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32_t a = simde_test_arm_neon_random_f32(-1000.0f, 1000.0f);
    simde_uint32_t r = simde_vcvtms_u32_f32(a);

    simde_test_arm_neon_write_f32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvtmq_u32_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a[4];
    uint32_t r[4];
  } test_vec[] = {
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
      { { HEDLEY_STATIC_CAST(simde_float32, UINT32_MAX) + SIMDE_FLOAT32_C(10000.0), SIMDE_MATH_NANF, -SIMDE_MATH_NANF, SIMDE_MATH_INFINITYF },
        {           UINT32_MAX, UINT32_C(         0), UINT32_C(         0),           UINT32_MAX } },
    #endif
      { { SIMDE_FLOAT32_C(   683.92), SIMDE_FLOAT32_C(   226.88), SIMDE_FLOAT32_C(   659.62), SIMDE_FLOAT32_C(   439.27) },
      { UINT32_C(       683), UINT32_C(       226), UINT32_C(       659), UINT32_C(       439) } },
    { { SIMDE_FLOAT32_C(   917.53), SIMDE_FLOAT32_C(   947.14), SIMDE_FLOAT32_C(   341.17), SIMDE_FLOAT32_C(   418.62) },
      { UINT32_C(       917), UINT32_C(       947), UINT32_C(       341), UINT32_C(       418) } },
    { { SIMDE_FLOAT32_C(   513.08), SIMDE_FLOAT32_C(   844.72), SIMDE_FLOAT32_C(   576.00), SIMDE_FLOAT32_C(   196.76) },
      { UINT32_C(       513), UINT32_C(       844), UINT32_C(       576), UINT32_C(       196) } },
    { { SIMDE_FLOAT32_C(   586.32), SIMDE_FLOAT32_C(   651.30), SIMDE_FLOAT32_C(    99.84), SIMDE_FLOAT32_C(   666.55) },
      { UINT32_C(       586), UINT32_C(       651), UINT32_C(        99), UINT32_C(       666) } },
    { { SIMDE_FLOAT32_C(   483.00), SIMDE_FLOAT32_C(   100.67), SIMDE_FLOAT32_C(   797.45), SIMDE_FLOAT32_C(   735.83) },
      { UINT32_C(       483), UINT32_C(       100), UINT32_C(       797), UINT32_C(       735) } },
    { { SIMDE_FLOAT32_C(   418.68), SIMDE_FLOAT32_C(   118.54), SIMDE_FLOAT32_C(   312.65), SIMDE_FLOAT32_C(    13.40) },
      { UINT32_C(       418), UINT32_C(       118), UINT32_C(       312), UINT32_C(        13) } },
    { { SIMDE_FLOAT32_C(     0.63), SIMDE_FLOAT32_C(   108.62), SIMDE_FLOAT32_C(   377.25), SIMDE_FLOAT32_C(   439.53) },
      { UINT32_C(         0), UINT32_C(       108), UINT32_C(       377), UINT32_C(       439) } },
    { { SIMDE_FLOAT32_C(   569.79), SIMDE_FLOAT32_C(   110.84), SIMDE_FLOAT32_C(   287.33), SIMDE_FLOAT32_C(   253.70) },
      { UINT32_C(       569), UINT32_C(       110), UINT32_C(       287), UINT32_C(       253) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_uint32x4_t r = simde_vcvtmq_u32_f32(a);

    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x4_t a = simde_test_arm_neon_random_f32x4(SIMDE_FLOAT32_C(0.0), SIMDE_FLOAT32_C(1000.0));
    simde_uint32x4_t r = simde_vcvtmq_u32_f32(a);

    simde_test_arm_neon_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

/* Disabled until we fix the FCVTZS/FCVTMS/FCVTPS/FCVTNS family intrinsics
 * https://github.com/simd-everywhere/simde/issues/1099
static int
test_simde_vcvtmd_s64_f64 (SIMDE_MUNIT_TEST_ARGS) {
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
      { SIMDE_FLOAT64_C( 0.0),
        INT64_C(     0) },
    #endif
    {   -SIMDE_FLOAT64_C( 70876.391),
        -INT64_C(     70877) },
    {   -SIMDE_FLOAT64_C( 75147.281),
        -INT64_C(     75148) },
    {    SIMDE_FLOAT64_C( 60409.406),
         INT64_C(     60409) },
    {    SIMDE_FLOAT64_C( 42836.578),
         INT64_C(     42836) },
    {    SIMDE_FLOAT64_C( 42453.047),
         INT64_C(     42453) },
    {    SIMDE_FLOAT64_C( 17095.617),
         INT64_C(     17095) },
    {   -SIMDE_FLOAT64_C( 65433.555),
        -INT64_C(     65434) },
    {   -SIMDE_FLOAT64_C( 72962.914),
        -INT64_C(     72963) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64 a = test_vec[i].a;
    int64_t r = simde_vcvtmd_s64_f64(a);
    simde_assert_equal_i64(r, test_vec[i].r);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64_t a = simde_test_arm_neon_random_f64(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde_int64_t r = simde_vcvtmd_s64_f64(a);

    simde_test_arm_neon_write_f64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}
*/

static int
test_simde_vcvtmd_u64_f64 (SIMDE_MUNIT_TEST_ARGS) {
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
      { SIMDE_FLOAT64_C( 0.0),
        UINT64_C(         0) },
    #endif
    {    SIMDE_FLOAT64_C( 24923.992),
         UINT64_C(     24923) },
    {    SIMDE_FLOAT64_C( 18610.977),
         UINT64_C(     18610) },
    {    SIMDE_FLOAT64_C( 31085.938),
         UINT64_C(     31085) },
    {    SIMDE_FLOAT64_C( 81679.125),
         UINT64_C(     81679) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64 a = test_vec[i].a;
    uint64_t r = simde_vcvtmd_u64_f64(a);
    simde_assert_equal_u64(r, test_vec[i].r);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64_t a = simde_test_arm_neon_random_f64(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde_uint64_t r = simde_vcvtmd_u64_f64(a);

    simde_test_arm_neon_write_f64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvtmq_u64_f64 (SIMDE_MUNIT_TEST_ARGS) {
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
    { { SIMDE_FLOAT64_C(   337.71), SIMDE_FLOAT64_C(   946.94) },
      { UINT64_C(                 337), UINT64_C(                 946) } },
    { { SIMDE_FLOAT64_C(   692.98), SIMDE_FLOAT64_C(   255.25) },
      { UINT64_C(                 692), UINT64_C(                 255) } },
    { { SIMDE_FLOAT64_C(   894.09), SIMDE_FLOAT64_C(    34.15) },
      { UINT64_C(                 894), UINT64_C(                  34) } },
    { { SIMDE_FLOAT64_C(   673.86), SIMDE_FLOAT64_C(   407.16) },
      { UINT64_C(                 673), UINT64_C(                 407) } },
    { { SIMDE_FLOAT64_C(   878.87), SIMDE_FLOAT64_C(   249.86) },
      { UINT64_C(                 878), UINT64_C(                 249) } },
    { { SIMDE_FLOAT64_C(   603.92), SIMDE_FLOAT64_C(   465.18) },
      { UINT64_C(                 603), UINT64_C(                 465) } },
    { { SIMDE_FLOAT64_C(   901.16), SIMDE_FLOAT64_C(   703.76) },
      { UINT64_C(                 901), UINT64_C(                 703) } },
    { { SIMDE_FLOAT64_C(   131.73), SIMDE_FLOAT64_C(   384.16) },
      { UINT64_C(                 131), UINT64_C(                 384) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2_t a = simde_vld1q_f64(test_vec[i].a);
    simde_uint64x2_t r = simde_vcvtmq_u64_f64(a);
    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x2_t a = simde_test_arm_neon_random_f64x2(SIMDE_FLOAT64_C(0.0), SIMDE_FLOAT64_C(1000.0));
    simde_uint64x2_t r = simde_vcvtmq_u64_f64(a);

    simde_test_arm_neon_write_f64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

/* Disabled until we fix the FCVTZS/FCVTMS/FCVTPS/FCVTNS family intrinsics
 * https://github.com/simd-everywhere/simde/issues/1099
static int
test_simde_vcvtmq_s16_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16_t a[8];
    int16_t r[8];
  } test_vec[] = {
    { { SIMDE_FLOAT16_VALUE( -     8.496),  SIMDE_FLOAT16_VALUE(    18.975), SIMDE_FLOAT16_VALUE( -     2.199), SIMDE_FLOAT16_VALUE( -    20.493),
        SIMDE_FLOAT16_VALUE( -    29.500),  SIMDE_FLOAT16_VALUE(     4.372), SIMDE_FLOAT16_VALUE( -     0.571),  SIMDE_FLOAT16_VALUE(    15.297) },
      { -INT16_C(         9),  INT16_C(        18), -INT16_C(         3), -INT16_C(        21),
        -INT16_C(        30),  INT16_C(         4), -INT16_C(         1),  INT16_C(        15) } },
    { { SIMDE_FLOAT16_VALUE( -     6.416), SIMDE_FLOAT16_VALUE( -    28.037),  SIMDE_FLOAT16_VALUE(     0.233), SIMDE_FLOAT16_VALUE( -     2.340),
         SIMDE_FLOAT16_VALUE(    21.686),  SIMDE_FLOAT16_VALUE(    15.884),  SIMDE_FLOAT16_VALUE(     5.613), SIMDE_FLOAT16_VALUE( -     3.479) },
      { -INT16_C(         7), -INT16_C(        29),  INT16_C(         0), -INT16_C(         3),
         INT16_C(        21),  INT16_C(        15),  INT16_C(         5), -INT16_C(         4) } },
    { {  SIMDE_FLOAT16_VALUE(    29.801),  SIMDE_FLOAT16_VALUE(     5.407), SIMDE_FLOAT16_VALUE( -     0.666),  SIMDE_FLOAT16_VALUE(    24.410),
        SIMDE_FLOAT16_VALUE( -    29.209), SIMDE_FLOAT16_VALUE( -     5.956), SIMDE_FLOAT16_VALUE( -    18.351), SIMDE_FLOAT16_VALUE( -    24.316) },
      {  INT16_C(        29),  INT16_C(         5), -INT16_C(         1),  INT16_C(        24),
        -INT16_C(        30), -INT16_C(         6), -INT16_C(        19), -INT16_C(        25) } },
    { { SIMDE_FLOAT16_VALUE( -    20.572), SIMDE_FLOAT16_VALUE( -    24.745), SIMDE_FLOAT16_VALUE( -    22.219),  SIMDE_FLOAT16_VALUE(    20.375),
        SIMDE_FLOAT16_VALUE( -    22.035), SIMDE_FLOAT16_VALUE( -    19.171), SIMDE_FLOAT16_VALUE( -    26.111), SIMDE_FLOAT16_VALUE( -    19.992) },
      { -INT16_C(        21), -INT16_C(        25), -INT16_C(        23),  INT16_C(        20),
        -INT16_C(        23), -INT16_C(        20), -INT16_C(        27), -INT16_C(        20) } },
    { {  SIMDE_FLOAT16_VALUE(    17.446), SIMDE_FLOAT16_VALUE( -    21.229), SIMDE_FLOAT16_VALUE( -    23.525),  SIMDE_FLOAT16_VALUE(    21.821),
         SIMDE_FLOAT16_VALUE(    19.282), SIMDE_FLOAT16_VALUE( -    25.940),  SIMDE_FLOAT16_VALUE(    17.691),  SIMDE_FLOAT16_VALUE(     1.353) },
      {  INT16_C(        17), -INT16_C(        22), -INT16_C(        24),  INT16_C(        21),
         INT16_C(        19), -INT16_C(        26),  INT16_C(        17),  INT16_C(         1) } },
    { {  SIMDE_FLOAT16_VALUE(    17.782),  SIMDE_FLOAT16_VALUE(    22.188), SIMDE_FLOAT16_VALUE( -    14.281),  SIMDE_FLOAT16_VALUE(    10.450),
        SIMDE_FLOAT16_VALUE( -    20.900),  SIMDE_FLOAT16_VALUE(     7.321), SIMDE_FLOAT16_VALUE( -     3.231),  SIMDE_FLOAT16_VALUE(    16.327) },
      {  INT16_C(        17),  INT16_C(        22), -INT16_C(        15),  INT16_C(        10),
        -INT16_C(        21),  INT16_C(         7), -INT16_C(         4),  INT16_C(        16) } },
    { {  SIMDE_FLOAT16_VALUE(    24.787), SIMDE_FLOAT16_VALUE( -    17.192), SIMDE_FLOAT16_VALUE( -    22.870), SIMDE_FLOAT16_VALUE( -    24.778),
         SIMDE_FLOAT16_VALUE(     4.885), SIMDE_FLOAT16_VALUE( -    23.686), SIMDE_FLOAT16_VALUE( -     5.354), SIMDE_FLOAT16_VALUE( -    25.350) },
      {  INT16_C(        24), -INT16_C(        18), -INT16_C(        23), -INT16_C(        25),
         INT16_C(         4), -INT16_C(        24), -INT16_C(         6), -INT16_C(        26) } },
    { { SIMDE_FLOAT16_VALUE( -    25.796),  SIMDE_FLOAT16_VALUE(     0.055), SIMDE_FLOAT16_VALUE( -    23.812), SIMDE_FLOAT16_VALUE( -     7.248),
         SIMDE_FLOAT16_VALUE(     2.304),  SIMDE_FLOAT16_VALUE(    21.545), SIMDE_FLOAT16_VALUE( -    11.785), SIMDE_FLOAT16_VALUE( -    21.974) },
      { -INT16_C(        26),  INT16_C(         0), -INT16_C(        24), -INT16_C(         8),
         INT16_C(         2),  INT16_C(        21), -INT16_C(        12), -INT16_C(        22) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x8_t a = simde_vld1q_f16(test_vec[i].a);
    simde_int16x8_t r = simde_vcvtmq_s16_f16(a);
    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16x8_t a = simde_test_arm_neon_random_f16x8(-100.0f, 100.0f);
    simde_int16x8_t r = simde_vcvtmq_s16_f16(a);

    simde_test_arm_neon_write_f16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvtm_s16_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16_t a[4];
    int16_t r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT16_VALUE( -    14.252), SIMDE_FLOAT16_VALUE( -     8.932), SIMDE_FLOAT16_VALUE( -    10.075),  SIMDE_FLOAT16_VALUE(     2.645) },
      { -INT16_C(        15), -INT16_C(         9), -INT16_C(        11),  INT16_C(         2) } },
    { { SIMDE_FLOAT16_VALUE( -    27.688),  SIMDE_FLOAT16_VALUE(    12.692), SIMDE_FLOAT16_VALUE( -    13.616), SIMDE_FLOAT16_VALUE( -    25.644) },
      { -INT16_C(        28),  INT16_C(        12), -INT16_C(        14), -INT16_C(        26) } },
    { { SIMDE_FLOAT16_VALUE( -    21.882),  SIMDE_FLOAT16_VALUE(    23.002), SIMDE_FLOAT16_VALUE( -     0.430),  SIMDE_FLOAT16_VALUE(    26.610) },
      { -INT16_C(        22),  INT16_C(        23), -INT16_C(         1),  INT16_C(        26) } },
    { { SIMDE_FLOAT16_VALUE( -     6.937), SIMDE_FLOAT16_VALUE( -    11.037), SIMDE_FLOAT16_VALUE( -    19.775),  SIMDE_FLOAT16_VALUE(    18.979) },
      { -INT16_C(         7), -INT16_C(        12), -INT16_C(        20),  INT16_C(        18) } },
    { {  SIMDE_FLOAT16_VALUE(     8.040),  SIMDE_FLOAT16_VALUE(    25.591),  SIMDE_FLOAT16_VALUE(     4.751),  SIMDE_FLOAT16_VALUE(    24.284) },
      {  INT16_C(         8),  INT16_C(        25),  INT16_C(         4),  INT16_C(        24) } },
    { {  SIMDE_FLOAT16_VALUE(    18.155), SIMDE_FLOAT16_VALUE( -    26.878),  SIMDE_FLOAT16_VALUE(    18.196),  SIMDE_FLOAT16_VALUE(    24.029) },
      {  INT16_C(        18), -INT16_C(        27),  INT16_C(        18),  INT16_C(        24) } },
    { { SIMDE_FLOAT16_VALUE( -    16.286),  SIMDE_FLOAT16_VALUE(    10.157), SIMDE_FLOAT16_VALUE( -     1.975),  SIMDE_FLOAT16_VALUE(     8.093) },
      { -INT16_C(        17),  INT16_C(        10), -INT16_C(         2),  INT16_C(         8) } },
    { { SIMDE_FLOAT16_VALUE( -    26.246), SIMDE_FLOAT16_VALUE( -    10.909), SIMDE_FLOAT16_VALUE( -    28.955),  SIMDE_FLOAT16_VALUE(     6.701) },
      { -INT16_C(        27), -INT16_C(        11), -INT16_C(        29),  INT16_C(         6) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x4_t a = simde_vld1_f16(test_vec[i].a);
    simde_int16x4_t r = simde_vcvtm_s16_f16(a);
    simde_test_arm_neon_assert_equal_i16x4(r, simde_vld1_s16(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16x4_t a = simde_test_arm_neon_random_f16x4(-100.0f, 100.0f);
    simde_int16x4_t r = simde_vcvtm_s16_f16(a);

    simde_test_arm_neon_write_f16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}
*/

static int
test_simde_vcvtmq_u16_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16_t a[8];
    uint16_t r[8];
  } test_vec[] = {
    { { SIMDE_FLOAT16_VALUE(   348.25), SIMDE_FLOAT16_VALUE(   859.50), SIMDE_FLOAT16_VALUE(   629.50), SIMDE_FLOAT16_VALUE(   746.50),
        SIMDE_FLOAT16_VALUE(   510.25), SIMDE_FLOAT16_VALUE(   957.00), SIMDE_FLOAT16_VALUE(   485.50), SIMDE_FLOAT16_VALUE(   650.50) },
      { UINT16_C(  348), UINT16_C(  859), UINT16_C(  629), UINT16_C(  746), UINT16_C(  510), UINT16_C(  957), UINT16_C(  485), UINT16_C(  650) } },
    { { SIMDE_FLOAT16_VALUE(   280.00), SIMDE_FLOAT16_VALUE(   624.00), SIMDE_FLOAT16_VALUE(   758.00), SIMDE_FLOAT16_VALUE(   938.50),
        SIMDE_FLOAT16_VALUE(   605.00), SIMDE_FLOAT16_VALUE(   770.00), SIMDE_FLOAT16_VALUE(   547.00), SIMDE_FLOAT16_VALUE(   943.50) },
      { UINT16_C(  280), UINT16_C(  624), UINT16_C(  758), UINT16_C(  938), UINT16_C(  605), UINT16_C(  770), UINT16_C(  547), UINT16_C(  943) } },
    { { SIMDE_FLOAT16_VALUE(   321.25), SIMDE_FLOAT16_VALUE(   963.50), SIMDE_FLOAT16_VALUE(   557.50), SIMDE_FLOAT16_VALUE(   467.25),
        SIMDE_FLOAT16_VALUE(   201.00), SIMDE_FLOAT16_VALUE(   597.00), SIMDE_FLOAT16_VALUE(   497.25), SIMDE_FLOAT16_VALUE(   937.00) },
      { UINT16_C(  321), UINT16_C(  963), UINT16_C(  557), UINT16_C(  467), UINT16_C(  201), UINT16_C(  597), UINT16_C(  497), UINT16_C(  937) } },
    { { SIMDE_FLOAT16_VALUE(   542.50), SIMDE_FLOAT16_VALUE(    71.12), SIMDE_FLOAT16_VALUE(   842.50), SIMDE_FLOAT16_VALUE(   218.75),
        SIMDE_FLOAT16_VALUE(   507.25), SIMDE_FLOAT16_VALUE(   363.25), SIMDE_FLOAT16_VALUE(   462.50), SIMDE_FLOAT16_VALUE(   855.50) },
      { UINT16_C(  542), UINT16_C(   71), UINT16_C(  842), UINT16_C(  218), UINT16_C(  507), UINT16_C(  363), UINT16_C(  462), UINT16_C(  855) } },
    { { SIMDE_FLOAT16_VALUE(   222.38), SIMDE_FLOAT16_VALUE(    92.12), SIMDE_FLOAT16_VALUE(   602.00), SIMDE_FLOAT16_VALUE(   733.00),
        SIMDE_FLOAT16_VALUE(    48.91), SIMDE_FLOAT16_VALUE(    87.31), SIMDE_FLOAT16_VALUE(   383.25), SIMDE_FLOAT16_VALUE(   329.00) },
      { UINT16_C(  222), UINT16_C(   92), UINT16_C(  602), UINT16_C(  733), UINT16_C(   48), UINT16_C(   87), UINT16_C(  383), UINT16_C(  329) } },
    { { SIMDE_FLOAT16_VALUE(   711.50), SIMDE_FLOAT16_VALUE(   141.12), SIMDE_FLOAT16_VALUE(   267.50), SIMDE_FLOAT16_VALUE(   316.50),
        SIMDE_FLOAT16_VALUE(   911.00), SIMDE_FLOAT16_VALUE(   814.00), SIMDE_FLOAT16_VALUE(   260.25), SIMDE_FLOAT16_VALUE(   232.38) },
      { UINT16_C(  711), UINT16_C(  141), UINT16_C(  267), UINT16_C(  316), UINT16_C(  911), UINT16_C(  814), UINT16_C(  260), UINT16_C(  232) } },
    { { SIMDE_FLOAT16_VALUE(   778.00), SIMDE_FLOAT16_VALUE(   818.00), SIMDE_FLOAT16_VALUE(   699.50), SIMDE_FLOAT16_VALUE(   979.00),
        SIMDE_FLOAT16_VALUE(   415.00), SIMDE_FLOAT16_VALUE(   196.88), SIMDE_FLOAT16_VALUE(   916.00), SIMDE_FLOAT16_VALUE(   957.50) },
      { UINT16_C(  778), UINT16_C(  818), UINT16_C(  699), UINT16_C(  979), UINT16_C(  415), UINT16_C(  196), UINT16_C(  916), UINT16_C(  957) } },
    { { SIMDE_FLOAT16_VALUE(   268.00), SIMDE_FLOAT16_VALUE(   758.50), SIMDE_FLOAT16_VALUE(   176.25), SIMDE_FLOAT16_VALUE(   775.00),
        SIMDE_FLOAT16_VALUE(   121.62), SIMDE_FLOAT16_VALUE(   638.50), SIMDE_FLOAT16_VALUE(   630.50), SIMDE_FLOAT16_VALUE(   344.00) },
      { UINT16_C(  268), UINT16_C(  758), UINT16_C(  176), UINT16_C(  775), UINT16_C(  121), UINT16_C(  638), UINT16_C(  630), UINT16_C(  344) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x8_t a = simde_vld1q_f16(test_vec[i].a);
    simde_uint16x8_t r = simde_vcvtmq_u16_f16(a);
    simde_test_arm_neon_assert_equal_u16x8(r, simde_vld1q_u16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16x8_t a = simde_test_arm_neon_random_f16x8(0.0f, 1000.0f);
    simde_uint16x8_t r = simde_vcvtmq_u16_f16(a);

    simde_test_arm_neon_write_f16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvtm_u16_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16_t a[4];
    uint16_t r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT16_VALUE(   340.75), SIMDE_FLOAT16_VALUE(   489.00), SIMDE_FLOAT16_VALUE(   996.00), SIMDE_FLOAT16_VALUE(   399.75) },
      { UINT16_C(  340), UINT16_C(  489), UINT16_C(  996), UINT16_C(  399) } },
    { { SIMDE_FLOAT16_VALUE(   967.00), SIMDE_FLOAT16_VALUE(   335.00), SIMDE_FLOAT16_VALUE(   842.00), SIMDE_FLOAT16_VALUE(   905.00) },
      { UINT16_C(  967), UINT16_C(  335), UINT16_C(  842), UINT16_C(  905) } },
    { { SIMDE_FLOAT16_VALUE(   950.00), SIMDE_FLOAT16_VALUE(   357.75), SIMDE_FLOAT16_VALUE(   539.00), SIMDE_FLOAT16_VALUE(   808.50) },
      { UINT16_C(  950), UINT16_C(  357), UINT16_C(  539), UINT16_C(  808) } },
    { { SIMDE_FLOAT16_VALUE(   275.25), SIMDE_FLOAT16_VALUE(   595.00), SIMDE_FLOAT16_VALUE(   820.50), SIMDE_FLOAT16_VALUE(   425.75) },
      { UINT16_C(  275), UINT16_C(  595), UINT16_C(  820), UINT16_C(  425) } },
    { { SIMDE_FLOAT16_VALUE(   884.00), SIMDE_FLOAT16_VALUE(   498.50), SIMDE_FLOAT16_VALUE(   906.00), SIMDE_FLOAT16_VALUE(   544.00) },
      { UINT16_C(  884), UINT16_C(  498), UINT16_C(  906), UINT16_C(  544) } },
    { { SIMDE_FLOAT16_VALUE(   169.62), SIMDE_FLOAT16_VALUE(   730.50), SIMDE_FLOAT16_VALUE(   862.50), SIMDE_FLOAT16_VALUE(   615.00) },
      { UINT16_C(  169), UINT16_C(  730), UINT16_C(  862), UINT16_C(  615) } },
    { { SIMDE_FLOAT16_VALUE(   567.50), SIMDE_FLOAT16_VALUE(   912.00), SIMDE_FLOAT16_VALUE(   338.75), SIMDE_FLOAT16_VALUE(   386.00) },
      { UINT16_C(  567), UINT16_C(  912), UINT16_C(  338), UINT16_C(  386) } },
    { { SIMDE_FLOAT16_VALUE(   398.25), SIMDE_FLOAT16_VALUE(   651.00), SIMDE_FLOAT16_VALUE(   327.25), SIMDE_FLOAT16_VALUE(   739.00) },
      { UINT16_C(  398), UINT16_C(  651), UINT16_C(  327), UINT16_C(  739) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x4_t a = simde_vld1_f16(test_vec[i].a);
    simde_uint16x4_t r = simde_vcvtm_u16_f16(a);
    simde_test_arm_neon_assert_equal_u16x4(r, simde_vld1_u16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16x4_t a = simde_test_arm_neon_random_f16x4(0.0f, 1000.0f);
    simde_uint16x4_t r = simde_vcvtm_u16_f16(a);

    simde_test_arm_neon_write_f16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvtm_u32_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float32 a[2];
    uint32_t r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   140.16), SIMDE_FLOAT32_C(   323.30) },
      { UINT32_C(       140), UINT32_C(       323) } },
    { { SIMDE_FLOAT32_C(   138.76), SIMDE_FLOAT32_C(   107.22) },
      { UINT32_C(       138), UINT32_C(       107) } },
    { { SIMDE_FLOAT32_C(   658.27), SIMDE_FLOAT32_C(   980.79) },
      { UINT32_C(       658), UINT32_C(       980) } },
    { { SIMDE_FLOAT32_C(    12.33), SIMDE_FLOAT32_C(   608.38) },
      { UINT32_C(        12), UINT32_C(       608) } },
    { { SIMDE_FLOAT32_C(   338.66), SIMDE_FLOAT32_C(   551.13) },
      { UINT32_C(       338), UINT32_C(       551) } },
    { { SIMDE_FLOAT32_C(   416.88), SIMDE_FLOAT32_C(   613.87) },
      { UINT32_C(       416), UINT32_C(       613) } },
    { { SIMDE_FLOAT32_C(   146.09), SIMDE_FLOAT32_C(   237.40) },
      { UINT32_C(       146), UINT32_C(       237) } },
    { { SIMDE_FLOAT32_C(    39.56), SIMDE_FLOAT32_C(    29.88) },
      { UINT32_C(        39), UINT32_C(        29) } },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t a = simde_vld1_f32(test_vec[i].a);
    simde_uint32x2_t r = simde_vcvtm_u32_f32(a);
    simde_test_arm_neon_assert_equal_u32x2(r, simde_vld1_u32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x2_t a = simde_test_arm_neon_random_f32x2(0.0, 1000.0);
    simde_uint32x2_t r = simde_vcvtm_u32_f32(a);

    simde_test_arm_neon_write_f32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

/* Disabled until we fix the FCVTZS/FCVTMS/FCVTPS/FCVTNS family intrinsics
 * https://github.com/simd-everywhere/simde/issues/1099
static int
test_simde_vcvtm_s32_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float32 a[2];
    int32_t r[2];
  } test_vec[] = {
    { { -SIMDE_FLOAT32_C(   981.216), -SIMDE_FLOAT32_C(   118.443) },
      { -INT32_C(       982), -INT32_C(       119) } },
    { {  SIMDE_FLOAT32_C(   870.692), -SIMDE_FLOAT32_C(   444.879) },
      {  INT32_C(       870), -INT32_C(       445) } },
    { {  SIMDE_FLOAT32_C(   872.875),  SIMDE_FLOAT32_C(    78.257) },
      {  INT32_C(       872),  INT32_C(        78) } },
    { { -SIMDE_FLOAT32_C(   350.761),  SIMDE_FLOAT32_C(   708.457) },
      { -INT32_C(       351),  INT32_C(       708) } },
    { { -SIMDE_FLOAT32_C(   489.035),  SIMDE_FLOAT32_C(   327.625) },
      { -INT32_C(       490),  INT32_C(       327) } },
    { { -SIMDE_FLOAT32_C(   447.613), -SIMDE_FLOAT32_C(   519.467) },
      { -INT32_C(       448), -INT32_C(       520) } },
    { { -SIMDE_FLOAT32_C(    65.217),  SIMDE_FLOAT32_C(   843.023) },
      { -INT32_C(        66),  INT32_C(       843) } },
    { { -SIMDE_FLOAT32_C(   398.463), -SIMDE_FLOAT32_C(   388.678) },
      { -INT32_C(       399), -INT32_C(       389) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t a = simde_vld1_f32(test_vec[i].a);
    simde_int32x2_t r = simde_vcvtm_s32_f32(a);
    simde_test_arm_neon_assert_equal_i32x2(r, simde_vld1_s32(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x2_t a = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f);
    simde_int32x2_t r = simde_vcvtm_s32_f32(a);

    simde_test_arm_neon_write_f32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvtm_s64_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float64 a[1];
    int64_t r[1];
  } test_vec[] = {
    { {  SIMDE_FLOAT64_C( 27073.289) },
      {  INT64_C(     27073) } },
    { {  SIMDE_FLOAT64_C( 26717.773) },
      {  INT64_C(     26717) } },
    { { -SIMDE_FLOAT64_C(  1977.039) },
      { -INT64_C(      1978) } },
    { { -SIMDE_FLOAT64_C( 10158.797) },
      { -INT64_C(     10159) } },
    { { -SIMDE_FLOAT64_C( 14198.961) },
      { -INT64_C(     14199) } },
    { {  SIMDE_FLOAT64_C(   526.211) },
      {  INT64_C(       526) } },
    { {  SIMDE_FLOAT64_C( 76952.719) },
      {  INT64_C(     76952) } },
    { {  SIMDE_FLOAT64_C( 11393.563) },
      {  INT64_C(     11393) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x1_t a = simde_vld1_f64(test_vec[i].a);
    simde_int64x1_t r = simde_vcvtm_s64_f64(a);
    simde_test_arm_neon_assert_equal_i64x1(r, simde_vld1_s64(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x1_t a = simde_test_arm_neon_random_f64x1(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde_int64x1_t r = simde_vcvtm_s64_f64(a);

    simde_test_arm_neon_write_f64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}
*/

static int
test_simde_vcvtm_u64_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float64 a[1];
    uint64_t r[1];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(   735.97) },
      { UINT64_C(                 735) } },
    { { SIMDE_FLOAT64_C(   945.51) },
      { UINT64_C(                 945) } },
    { { SIMDE_FLOAT64_C(   573.91) },
      { UINT64_C(                 573) } },
    { { SIMDE_FLOAT64_C(   905.61) },
      { UINT64_C(                 905) } },
    { { SIMDE_FLOAT64_C(   676.10) },
      { UINT64_C(                 676) } },
    { { SIMDE_FLOAT64_C(   436.17) },
      { UINT64_C(                 436) } },
    { { SIMDE_FLOAT64_C(   520.52) },
      { UINT64_C(                 520) } },
    { { SIMDE_FLOAT64_C(   243.72) },
      { UINT64_C(                 243) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x1_t a = simde_vld1_f64(test_vec[i].a);
    simde_uint64x1_t r = simde_vcvtm_u64_f64(a);
    simde_test_arm_neon_assert_equal_u64x1(r, simde_vld1_u64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x1_t a = simde_test_arm_neon_random_f64x1(SIMDE_FLOAT64_C(0.0), SIMDE_FLOAT64_C(1000.0));
    simde_uint64x1_t r = simde_vcvtm_u64_f64(a);

    simde_test_arm_neon_write_f64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
//SIMDE_TEST_FUNC_LIST_ENTRY(vcvtms_s32_f32)
//SIMDE_TEST_FUNC_LIST_ENTRY(vcvtmd_s64_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtms_u32_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtmd_u64_f64)

//SIMDE_TEST_FUNC_LIST_ENTRY(vcvtmh_s16_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtmh_s32_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtmh_s64_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtmh_u16_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtmh_u32_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtmh_u64_f16)

//SIMDE_TEST_FUNC_LIST_ENTRY(vcvtm_s16_f16)
//SIMDE_TEST_FUNC_LIST_ENTRY(vcvtm_s32_f32)
//SIMDE_TEST_FUNC_LIST_ENTRY(vcvtm_s64_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtm_u16_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtm_u32_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtm_u64_f64)

//SIMDE_TEST_FUNC_LIST_ENTRY(vcvtmq_s16_f16)
//SIMDE_TEST_FUNC_LIST_ENTRY(vcvtmq_s32_f32)
//SIMDE_TEST_FUNC_LIST_ENTRY(vcvtmq_s64_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtmq_u16_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtmq_u32_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtmq_u64_f64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
