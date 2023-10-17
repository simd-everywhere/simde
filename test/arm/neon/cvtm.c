#define SIMDE_TEST_ARM_NEON_INSN cvtm

#include "test-neon.h"
#include "../../../simde/arm/neon/cvtm.h"

static int
test_simde_vcvtmq_s32_f32 (SIMDE_MUNIT_TEST_ARGS) {
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
}

static int
test_simde_vcvtmq_s64_f64 (SIMDE_MUNIT_TEST_ARGS) {
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
}

static int
test_simde_vcvtmh_s64_f16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    simde_float16 a;
    int64_t r;
  } test_vec[] = {
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
    #if !defined(SIMDE_RISCV_RVV_NATIVE)
      {            SIMDE_MATH_NANF,
        INT64_C(           0) },
    #endif
      { HEDLEY_STATIC_CAST(simde_float16, INT64_MAX),
                  INT64_MAX },
      { HEDLEY_STATIC_CAST(simde_float16, INT64_MIN),
                  INT64_MIN },
    #endif
    {   SIMDE_FLOAT16_VALUE( -29.102),
        -INT64_C(        30) },
    {   SIMDE_FLOAT16_VALUE( -15.400),
        -INT64_C(        16) },
    {   SIMDE_FLOAT16_VALUE( -5.887),
        -INT64_C(         6) },
    {    SIMDE_FLOAT16_VALUE(    16.529),
         INT64_C(        16) },
    {    SIMDE_FLOAT16_VALUE(    17.641),
         INT64_C(        17) },
    {    SIMDE_FLOAT16_VALUE(    16.624),
         INT64_C(        16) },
    {    SIMDE_FLOAT16_VALUE(    14.373),
         INT64_C(        14) },
    {   SIMDE_FLOAT16_VALUE( -16.813),
        -INT64_C(        17) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16 a = test_vec[i].a;
    int64_t r = simde_vcvtmh_s64_f16(a);
    simde_assert_equal_i64(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_vcvtmh_s32_f16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    simde_float16 a;
    int32_t r;
  } test_vec[] = {
    {            SIMDE_MATH_NANF,
      INT32_C(           0) },
    { HEDLEY_STATIC_CAST(simde_float16, INT32_MAX),
                INT32_MAX },
    { HEDLEY_STATIC_CAST(simde_float16, INT32_MIN),
                INT32_MIN },
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
    simde_float16 a = test_vec[i].a;
    int32_t r = simde_vcvtmh_s32_f16(a);
    simde_assert_equal_i32(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_vcvtmh_s16_f16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    simde_float16 a;
    int16_t r;
  } test_vec[] = {
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
    #if !defined(SIMDE_RISCV_RVV_NATIVE)
      {            SIMDE_MATH_NANF,
        INT16_C(           0) },
    #endif
      { HEDLEY_STATIC_CAST(simde_float16, INT16_MAX) + SIMDE_FLOAT16_VALUE(100.0),
                  INT16_MAX },
      { HEDLEY_STATIC_CAST(simde_float16, INT16_MIN) + SIMDE_FLOAT16_VALUE(-100.0),
                  INT16_MIN },
    #endif
    {   SIMDE_FLOAT16_VALUE( -15.279),
        -INT16_C(        16) },
    {   SIMDE_FLOAT16_VALUE( -15.541),
        -INT16_C(        16) },
    {    SIMDE_FLOAT16_VALUE(    24.266),
         INT16_C(        24) },
    {    SIMDE_FLOAT16_VALUE(    28.626),
         INT16_C(        28) },
    {   SIMDE_FLOAT16_VALUE( -17.731),
        -INT16_C(        18) },
    {   SIMDE_FLOAT16_VALUE( -14.985),
        -INT16_C(        15) },
    {   SIMDE_FLOAT16_VALUE( -26.154),
        -INT16_C(        27) },
    {    SIMDE_FLOAT16_VALUE(     5.330),
         INT16_C(         5) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16 a = test_vec[i].a;
    int16_t r = simde_vcvtmh_s16_f16(a);
    simde_assert_equal_i16(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_vcvtms_s32_f32 (SIMDE_MUNIT_TEST_ARGS) {
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
}

static int
test_simde_vcvtmh_u64_f16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    simde_float16 a;
    uint64_t r;
  } test_vec[] = {
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
    #if !defined(SIMDE_RISCV_RVV_NATIVE)
      {            SIMDE_MATH_NANF,
        INT64_C(           0) },
    #endif
      { HEDLEY_STATIC_CAST(simde_float16, UINT64_MAX),
                  UINT64_MAX },
      { SIMDE_FLOAT16_VALUE(-1000.0),
        UINT64_C(         0) },
    #endif
    {   SIMDE_FLOAT16_VALUE( -4.094),
         UINT64_C(         0) },
    {   SIMDE_FLOAT16_VALUE( -25.902),
         UINT64_C(         0) },
    {   SIMDE_FLOAT16_VALUE( -20.066),
         UINT64_C(         0) },
    {    SIMDE_FLOAT16_VALUE(    10.401),
         UINT64_C(        10) },
    {    SIMDE_FLOAT16_VALUE(    11.014),
         UINT64_C(        11) },
    {    SIMDE_FLOAT16_VALUE(    20.952),
         UINT64_C(        20) },
    {   SIMDE_FLOAT16_VALUE( -18.162),
         UINT64_C(         0) },
    {   SIMDE_FLOAT16_VALUE( -7.537),
         UINT64_C(         0) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16 a = test_vec[i].a;
    uint64_t r = simde_vcvtmh_u64_f16(a);
    simde_assert_equal_u64(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_vcvtmh_u32_f16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    simde_float16 a;
    uint32_t r;
  } test_vec[] = {
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
    #if !defined(SIMDE_RISCV_RVV_NATIVE)
      {            SIMDE_MATH_NANF,
        INT32_C(           0) },
    #endif
      { HEDLEY_STATIC_CAST(simde_float16, UINT32_MAX),
                  UINT32_MAX },
      { SIMDE_FLOAT16_VALUE(-1000.0),
        UINT32_C(         0) },
    #endif
    {   SIMDE_FLOAT16_VALUE( -24.108),
         UINT32_C(         0) },
    {    SIMDE_FLOAT16_VALUE(     0.691),
         UINT32_C(         0) },
    {    SIMDE_FLOAT16_VALUE(    24.104),
         UINT32_C(        24) },
    {    SIMDE_FLOAT16_VALUE(     5.841),
         UINT32_C(         5) },
    {    SIMDE_FLOAT16_VALUE(    23.950),
         UINT32_C(        23) },
    {   SIMDE_FLOAT16_VALUE( -11.130),
         UINT32_C(         0) },
    {   SIMDE_FLOAT16_VALUE( -24.900),
         UINT32_C(         0) },
    {    SIMDE_FLOAT16_VALUE(     1.348),
         UINT32_C(         1) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16 a = test_vec[i].a;
    uint32_t r = simde_vcvtmh_u32_f16(a);
    simde_assert_equal_u32(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_vcvtmh_u16_f16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    simde_float16 a;
    uint16_t r;
  } test_vec[] = {
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
    #if !defined(SIMDE_RISCV_RVV_NATIVE)
      {            SIMDE_MATH_NANF,
        INT16_C(           0) },
    #endif
      { HEDLEY_STATIC_CAST(simde_float16, UINT16_MAX),
                  UINT16_MAX },
      { SIMDE_FLOAT16_VALUE(-1000.0),
        UINT16_C(         0) },
    #endif
    {   SIMDE_FLOAT16_VALUE( -16.076),
         UINT16_C(         0) },
    {    SIMDE_FLOAT16_VALUE(    28.461),
         UINT16_C(        28) },
    {   SIMDE_FLOAT16_VALUE( -24.751),
         UINT16_C(         0) },
    {    SIMDE_FLOAT16_VALUE(    16.044),
         UINT16_C(        16) },
    {   SIMDE_FLOAT16_VALUE( -24.805),
         UINT16_C(         0) },
    {    SIMDE_FLOAT16_VALUE(     5.757),
         UINT16_C(         5) },
    {   SIMDE_FLOAT16_VALUE( -7.533),
         UINT16_C(         0) },
    {    SIMDE_FLOAT16_VALUE(     4.509),
         UINT16_C(         4) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16 a = test_vec[i].a;
    uint16_t r = simde_vcvtmh_u16_f16(a);
    simde_assert_equal_u16(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_vcvtms_u32_f32 (SIMDE_MUNIT_TEST_ARGS) {
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
    {    SIMDE_FLOAT32_C(   550.582),
         UINT32_C(       550) },
    {   -SIMDE_FLOAT32_C(   561.636),
         UINT32_C(         0) },
    {   -SIMDE_FLOAT32_C(   494.548),
         UINT32_C(         0) },
    {   -SIMDE_FLOAT32_C(   293.647),
         UINT32_C(         0) },
    {    SIMDE_FLOAT32_C(   378.414),
         UINT32_C(       378) },
    {    SIMDE_FLOAT32_C(   903.633),
         UINT32_C(       903) },
    {   -SIMDE_FLOAT32_C(   377.778),
         UINT32_C(         0) },
    {   -SIMDE_FLOAT32_C(   578.417),
         UINT32_C(         0) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32 a = test_vec[i].a;
    uint32_t r = simde_vcvtms_u32_f32(a);
    simde_assert_equal_u32(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_vcvtmq_u32_f32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    simde_float32 a[4];
    uint32_t r[4];
  } test_vec[] = {
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
      { { HEDLEY_STATIC_CAST(simde_float32, UINT32_MAX) + SIMDE_FLOAT32_C(10000.0), SIMDE_MATH_NANF, -SIMDE_MATH_NANF, SIMDE_MATH_INFINITYF },
        {           UINT32_MAX, UINT32_C(         0), UINT32_C(         0),           UINT32_MAX } },
    #endif
    { { -SIMDE_FLOAT32_C(   991.592),  SIMDE_FLOAT32_C(   429.813),  SIMDE_FLOAT32_C(   432.940), -SIMDE_FLOAT32_C(   500.921) },
      {  UINT32_C(         0),  UINT32_C(       429),  UINT32_C(       432),  UINT32_C(         0) } },
    { { -SIMDE_FLOAT32_C(   457.623), -SIMDE_FLOAT32_C(   914.591),  SIMDE_FLOAT32_C(   879.450), -SIMDE_FLOAT32_C(   179.351) },
      {  UINT32_C(         0),  UINT32_C(         0),  UINT32_C(       879),  UINT32_C(         0) } },
    { {  SIMDE_FLOAT32_C(   777.878), -SIMDE_FLOAT32_C(   729.050), -SIMDE_FLOAT32_C(    65.868),  SIMDE_FLOAT32_C(   390.763) },
      {  UINT32_C(       777),  UINT32_C(         0),  UINT32_C(         0),  UINT32_C(       390) } },
    { {  SIMDE_FLOAT32_C(   570.038),  SIMDE_FLOAT32_C(   560.736), -SIMDE_FLOAT32_C(   994.571),  SIMDE_FLOAT32_C(   973.468) },
      {  UINT32_C(       570),  UINT32_C(       560),  UINT32_C(         0),  UINT32_C(       973) } },
    { { -SIMDE_FLOAT32_C(   110.161), -SIMDE_FLOAT32_C(   624.444),  SIMDE_FLOAT32_C(   408.883), -SIMDE_FLOAT32_C(   631.364) },
      {  UINT32_C(         0),  UINT32_C(         0),  UINT32_C(       408),  UINT32_C(         0) } },
    { {  SIMDE_FLOAT32_C(   159.954), -SIMDE_FLOAT32_C(   552.148), -SIMDE_FLOAT32_C(   978.320), -SIMDE_FLOAT32_C(   301.923) },
      {  UINT32_C(       159),  UINT32_C(         0),  UINT32_C(         0),  UINT32_C(         0) } },
    { {  SIMDE_FLOAT32_C(   760.761), -SIMDE_FLOAT32_C(   904.894), -SIMDE_FLOAT32_C(   973.175),  SIMDE_FLOAT32_C(   208.081) },
      {  UINT32_C(       760),  UINT32_C(         0),  UINT32_C(         0),  UINT32_C(       208) } },
    { { -SIMDE_FLOAT32_C(   383.713), -SIMDE_FLOAT32_C(   317.626),  SIMDE_FLOAT32_C(   649.201),  SIMDE_FLOAT32_C(   553.894) },
      {  UINT32_C(         0),  UINT32_C(         0),  UINT32_C(       649),  UINT32_C(       553) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_uint32x4_t r = simde_vcvtmq_u32_f32(a);

    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vcvtmd_s64_f64 (SIMDE_MUNIT_TEST_ARGS) {
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
}

static int
test_simde_vcvtmd_u64_f64 (SIMDE_MUNIT_TEST_ARGS) {
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
    {   -SIMDE_FLOAT64_C( 25475.531),
         UINT64_C(         0) },
    {   -SIMDE_FLOAT64_C( 96381.000),
         UINT64_C(         0) },
    {   -SIMDE_FLOAT64_C( 35414.762),
         UINT64_C(         0) },
    {    SIMDE_FLOAT64_C( 24923.992),
         UINT64_C(     24923) },
    {    SIMDE_FLOAT64_C( 18610.977),
         UINT64_C(     18610) },
    {    SIMDE_FLOAT64_C( 31085.938),
         UINT64_C(     31085) },
    {    SIMDE_FLOAT64_C( 81679.125),
         UINT64_C(     81679) },
    {   -SIMDE_FLOAT64_C( 95960.555),
         UINT64_C(         0) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64 a = test_vec[i].a;
    uint64_t r = simde_vcvtmd_u64_f64(a);
    simde_assert_equal_u64(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_vcvtmq_u64_f64 (SIMDE_MUNIT_TEST_ARGS) {
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
    { { -SIMDE_FLOAT64_C( 57529.828),  SIMDE_FLOAT64_C( 81425.422) },
      {  UINT64_C(         0),  UINT64_C(     81425) } },
    { { -SIMDE_FLOAT64_C( 39094.500),  SIMDE_FLOAT64_C( 21765.445) },
      {  UINT64_C(         0),  UINT64_C(     21765) } },
    { {  SIMDE_FLOAT64_C(  7112.727), -SIMDE_FLOAT64_C( 86853.281) },
      {  UINT64_C(      7112),  UINT64_C(         0) } },
    { { -SIMDE_FLOAT64_C( 69616.906), -SIMDE_FLOAT64_C( 94539.125) },
      {  UINT64_C(         0),  UINT64_C(         0) } },
    { {  SIMDE_FLOAT64_C(  1518.367),  SIMDE_FLOAT64_C( 79938.344) },
      {  UINT64_C(      1518),  UINT64_C(     79938) } },
    { {  SIMDE_FLOAT64_C( 35153.594), -SIMDE_FLOAT64_C( 69671.547) },
      {  UINT64_C(     35153),  UINT64_C(         0) } },
    { { -SIMDE_FLOAT64_C(  7075.828), -SIMDE_FLOAT64_C( 96435.742) },
      {  UINT64_C(         0),  UINT64_C(         0) } },
    { {  SIMDE_FLOAT64_C( 60090.234),  SIMDE_FLOAT64_C( 78921.219) },
      {  UINT64_C(     60090),  UINT64_C(     78921) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2_t a = simde_vld1q_f64(test_vec[i].a);
    simde_uint64x2_t r = simde_vcvtmq_u64_f64(a);
    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vcvtmq_s16_f16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float16 a[8];
    int16_t r[8];
  } test_vec[] = {
    { { SIMDE_FLOAT16_VALUE( -8.496),  SIMDE_FLOAT16_VALUE(    18.975), SIMDE_FLOAT16_VALUE( -2.199), SIMDE_FLOAT16_VALUE( -20.493),
        SIMDE_FLOAT16_VALUE( -29.500),  SIMDE_FLOAT16_VALUE(     4.372), SIMDE_FLOAT16_VALUE( -0.571),  SIMDE_FLOAT16_VALUE(    15.297) },
      { -INT16_C(         9),  INT16_C(        18), -INT16_C(         3), -INT16_C(        21),
        -INT16_C(        30),  INT16_C(         4), -INT16_C(         1),  INT16_C(        15) } },
    { { SIMDE_FLOAT16_VALUE( -6.416), SIMDE_FLOAT16_VALUE( -28.037),  SIMDE_FLOAT16_VALUE(     0.233), SIMDE_FLOAT16_VALUE( -2.340),
         SIMDE_FLOAT16_VALUE(    21.686),  SIMDE_FLOAT16_VALUE(    15.884),  SIMDE_FLOAT16_VALUE(     5.613), SIMDE_FLOAT16_VALUE( -3.479) },
      { -INT16_C(         7), -INT16_C(        29),  INT16_C(         0), -INT16_C(         3),
         INT16_C(        21),  INT16_C(        15),  INT16_C(         5), -INT16_C(         4) } },
    { {  SIMDE_FLOAT16_VALUE(    29.801),  SIMDE_FLOAT16_VALUE(     5.407), SIMDE_FLOAT16_VALUE( -0.666),  SIMDE_FLOAT16_VALUE(    24.410),
        SIMDE_FLOAT16_VALUE( -29.209), SIMDE_FLOAT16_VALUE( -5.956), SIMDE_FLOAT16_VALUE( -18.351), SIMDE_FLOAT16_VALUE( -24.316) },
      {  INT16_C(        29),  INT16_C(         5), -INT16_C(         1),  INT16_C(        24),
        -INT16_C(        30), -INT16_C(         6), -INT16_C(        19), -INT16_C(        25) } },
    { { SIMDE_FLOAT16_VALUE( -20.572), SIMDE_FLOAT16_VALUE( -24.745), SIMDE_FLOAT16_VALUE( -22.219),  SIMDE_FLOAT16_VALUE(    20.375),
        SIMDE_FLOAT16_VALUE( -22.035), SIMDE_FLOAT16_VALUE( -19.171), SIMDE_FLOAT16_VALUE( -26.111), SIMDE_FLOAT16_VALUE( -19.992) },
      { -INT16_C(        21), -INT16_C(        25), -INT16_C(        23),  INT16_C(        20),
        -INT16_C(        23), -INT16_C(        20), -INT16_C(        27), -INT16_C(        20) } },
    { {  SIMDE_FLOAT16_VALUE(    17.446), SIMDE_FLOAT16_VALUE( -21.229), SIMDE_FLOAT16_VALUE( -23.525),  SIMDE_FLOAT16_VALUE(    21.821),
         SIMDE_FLOAT16_VALUE(    19.282), SIMDE_FLOAT16_VALUE( -25.940),  SIMDE_FLOAT16_VALUE(    17.691),  SIMDE_FLOAT16_VALUE(     1.353) },
      {  INT16_C(        17), -INT16_C(        22), -INT16_C(        24),  INT16_C(        21),
         INT16_C(        19), -INT16_C(        26),  INT16_C(        17),  INT16_C(         1) } },
    { {  SIMDE_FLOAT16_VALUE(    17.782),  SIMDE_FLOAT16_VALUE(    22.188), SIMDE_FLOAT16_VALUE( -14.281),  SIMDE_FLOAT16_VALUE(    10.450),
        SIMDE_FLOAT16_VALUE( -20.900),  SIMDE_FLOAT16_VALUE(     7.321), SIMDE_FLOAT16_VALUE( -3.231),  SIMDE_FLOAT16_VALUE(    16.327) },
      {  INT16_C(        17),  INT16_C(        22), -INT16_C(        15),  INT16_C(        10),
        -INT16_C(        21),  INT16_C(         7), -INT16_C(         4),  INT16_C(        16) } },
    { {  SIMDE_FLOAT16_VALUE(    24.787), SIMDE_FLOAT16_VALUE( -17.192), SIMDE_FLOAT16_VALUE( -22.870), SIMDE_FLOAT16_VALUE( -24.778),
         SIMDE_FLOAT16_VALUE(     4.885), SIMDE_FLOAT16_VALUE( -23.686), SIMDE_FLOAT16_VALUE( -5.354), SIMDE_FLOAT16_VALUE( -25.350) },
      {  INT16_C(        24), -INT16_C(        18), -INT16_C(        23), -INT16_C(        25),
         INT16_C(         4), -INT16_C(        24), -INT16_C(         6), -INT16_C(        26) } },
    { { SIMDE_FLOAT16_VALUE( -25.796),  SIMDE_FLOAT16_VALUE(     0.055), SIMDE_FLOAT16_VALUE( -23.812), SIMDE_FLOAT16_VALUE( -7.248),
         SIMDE_FLOAT16_VALUE(     2.304),  SIMDE_FLOAT16_VALUE(    21.545), SIMDE_FLOAT16_VALUE( -11.785), SIMDE_FLOAT16_VALUE( -21.974) },
      { -INT16_C(        26),  INT16_C(         0), -INT16_C(        24), -INT16_C(         8),
         INT16_C(         2),  INT16_C(        21), -INT16_C(        12), -INT16_C(        22) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x8_t a = simde_vld1q_f16(test_vec[i].a);
    simde_int16x8_t r = simde_vcvtmq_s16_f16(a);
    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vcvtm_s16_f16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float16 a[4];
    int16_t r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT16_VALUE( -14.252), SIMDE_FLOAT16_VALUE( -8.932), SIMDE_FLOAT16_VALUE( -10.075),  SIMDE_FLOAT16_VALUE(     2.645) },
      { -INT16_C(        15), -INT16_C(         9), -INT16_C(        11),  INT16_C(         2) } },
    { { SIMDE_FLOAT16_VALUE( -27.688),  SIMDE_FLOAT16_VALUE(    12.692), SIMDE_FLOAT16_VALUE( -13.616), SIMDE_FLOAT16_VALUE( -25.644) },
      { -INT16_C(        28),  INT16_C(        12), -INT16_C(        14), -INT16_C(        26) } },
    { { SIMDE_FLOAT16_VALUE( -21.882),  SIMDE_FLOAT16_VALUE(    23.002), SIMDE_FLOAT16_VALUE( -0.430),  SIMDE_FLOAT16_VALUE(    26.610) },
      { -INT16_C(        22),  INT16_C(        23), -INT16_C(         1),  INT16_C(        26) } },
    { { SIMDE_FLOAT16_VALUE( -6.937), SIMDE_FLOAT16_VALUE( -11.037), SIMDE_FLOAT16_VALUE( -19.775),  SIMDE_FLOAT16_VALUE(    18.979) },
      { -INT16_C(         7), -INT16_C(        12), -INT16_C(        20),  INT16_C(        18) } },
    { {  SIMDE_FLOAT16_VALUE(     8.040),  SIMDE_FLOAT16_VALUE(    25.591),  SIMDE_FLOAT16_VALUE(     4.751),  SIMDE_FLOAT16_VALUE(    24.284) },
      {  INT16_C(         8),  INT16_C(        25),  INT16_C(         4),  INT16_C(        24) } },
    { {  SIMDE_FLOAT16_VALUE(    18.155), SIMDE_FLOAT16_VALUE( -26.878),  SIMDE_FLOAT16_VALUE(    18.196),  SIMDE_FLOAT16_VALUE(    24.029) },
      {  INT16_C(        18), -INT16_C(        27),  INT16_C(        18),  INT16_C(        24) } },
    { { SIMDE_FLOAT16_VALUE( -16.286),  SIMDE_FLOAT16_VALUE(    10.157), SIMDE_FLOAT16_VALUE( -1.975),  SIMDE_FLOAT16_VALUE(     8.093) },
      { -INT16_C(        17),  INT16_C(        10), -INT16_C(         2),  INT16_C(         8) } },
    { { SIMDE_FLOAT16_VALUE( -26.246), SIMDE_FLOAT16_VALUE( -10.909), SIMDE_FLOAT16_VALUE( -28.955),  SIMDE_FLOAT16_VALUE(     6.701) },
      { -INT16_C(        27), -INT16_C(        11), -INT16_C(        29),  INT16_C(         6) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x4_t a = simde_vld1_f16(test_vec[i].a);
    simde_int16x4_t r = simde_vcvtm_s16_f16(a);
    simde_test_arm_neon_assert_equal_i16x4(r, simde_vld1_s16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vcvtmq_u16_f16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float16 a[8];
    uint16_t r[8];
  } test_vec[] = {
    { {  SIMDE_FLOAT16_VALUE(     5.937),  SIMDE_FLOAT16_VALUE(    23.914), SIMDE_FLOAT16_VALUE( -8.349), SIMDE_FLOAT16_VALUE( -29.604),
        SIMDE_FLOAT16_VALUE( -12.952),  SIMDE_FLOAT16_VALUE(    20.911), SIMDE_FLOAT16_VALUE( -27.876), SIMDE_FLOAT16_VALUE( -4.654) },
      {  UINT16_C(         5),  UINT16_C(        23),  UINT16_C(         0),  UINT16_C(         0),
         UINT16_C(         0),  UINT16_C(        20),  UINT16_C(         0),  UINT16_C(         0) } },
    { {  SIMDE_FLOAT16_VALUE(    23.250), SIMDE_FLOAT16_VALUE( -10.879),  SIMDE_FLOAT16_VALUE(    23.029),  SIMDE_FLOAT16_VALUE(     5.727),
         SIMDE_FLOAT16_VALUE(     0.365),  SIMDE_FLOAT16_VALUE(    27.426), SIMDE_FLOAT16_VALUE( -0.411),  SIMDE_FLOAT16_VALUE(    25.368) },
      {  UINT16_C(        23),  UINT16_C(         0),  UINT16_C(        23),  UINT16_C(         5),
         UINT16_C(         0),  UINT16_C(        27),  UINT16_C(         0),  UINT16_C(        25) } },
    { {  SIMDE_FLOAT16_VALUE(    26.607), SIMDE_FLOAT16_VALUE( -27.109),  SIMDE_FLOAT16_VALUE(    27.786),  SIMDE_FLOAT16_VALUE(     5.282),
        SIMDE_FLOAT16_VALUE( -22.829), SIMDE_FLOAT16_VALUE( -14.811), SIMDE_FLOAT16_VALUE( -27.888), SIMDE_FLOAT16_VALUE( -2.514) },
      {  UINT16_C(        26),  UINT16_C(         0),  UINT16_C(        27),  UINT16_C(         5),
         UINT16_C(         0),  UINT16_C(         0),  UINT16_C(         0),  UINT16_C(         0) } },
    { { SIMDE_FLOAT16_VALUE( -0.461),  SIMDE_FLOAT16_VALUE(    21.653), SIMDE_FLOAT16_VALUE( -19.722), SIMDE_FLOAT16_VALUE( -4.920),
        SIMDE_FLOAT16_VALUE( -24.654),  SIMDE_FLOAT16_VALUE(    22.378), SIMDE_FLOAT16_VALUE( -12.561), SIMDE_FLOAT16_VALUE( -25.610) },
      {  UINT16_C(         0),  UINT16_C(        21),  UINT16_C(         0),  UINT16_C(         0),
         UINT16_C(         0),  UINT16_C(        22),  UINT16_C(         0),  UINT16_C(         0) } },
    { { SIMDE_FLOAT16_VALUE( -10.683), SIMDE_FLOAT16_VALUE( -0.472), SIMDE_FLOAT16_VALUE( -23.365), SIMDE_FLOAT16_VALUE( -13.328),
         SIMDE_FLOAT16_VALUE(     8.726),  SIMDE_FLOAT16_VALUE(    11.500),  SIMDE_FLOAT16_VALUE(    17.492),  SIMDE_FLOAT16_VALUE(     1.449) },
      {  UINT16_C(         0),  UINT16_C(         0),  UINT16_C(         0),  UINT16_C(         0),
         UINT16_C(         8),  UINT16_C(        11),  UINT16_C(        17),  UINT16_C(         1) } },
    { { SIMDE_FLOAT16_VALUE( -20.210),  SIMDE_FLOAT16_VALUE(     7.023),  SIMDE_FLOAT16_VALUE(     9.448), SIMDE_FLOAT16_VALUE( -5.905),
        SIMDE_FLOAT16_VALUE( -24.943),  SIMDE_FLOAT16_VALUE(    10.812),  SIMDE_FLOAT16_VALUE(    26.843),  SIMDE_FLOAT16_VALUE(    14.904) },
      {  UINT16_C(         0),  UINT16_C(         7),  UINT16_C(         9),  UINT16_C(         0),
         UINT16_C(         0),  UINT16_C(        10),  UINT16_C(        26),  UINT16_C(        14) } },
    { {  SIMDE_FLOAT16_VALUE(     9.740),  SIMDE_FLOAT16_VALUE(    29.346),  SIMDE_FLOAT16_VALUE(    25.155),  SIMDE_FLOAT16_VALUE(    29.824),
        SIMDE_FLOAT16_VALUE( -28.546), SIMDE_FLOAT16_VALUE( -27.940),  SIMDE_FLOAT16_VALUE(    11.032), SIMDE_FLOAT16_VALUE( -13.490) },
      {  UINT16_C(         9),  UINT16_C(        29),  UINT16_C(        25),  UINT16_C(        29),
         UINT16_C(         0),  UINT16_C(         0),  UINT16_C(        11),  UINT16_C(         0) } },
    { { SIMDE_FLOAT16_VALUE( -22.172),  SIMDE_FLOAT16_VALUE(     0.397),  SIMDE_FLOAT16_VALUE(     8.424),  SIMDE_FLOAT16_VALUE(     7.644),
        SIMDE_FLOAT16_VALUE( -5.523), SIMDE_FLOAT16_VALUE( -13.197),  SIMDE_FLOAT16_VALUE(    15.611), SIMDE_FLOAT16_VALUE( -0.097) },
      {  UINT16_C(         0),  UINT16_C(         0),  UINT16_C(         8),  UINT16_C(         7),
         UINT16_C(         0),  UINT16_C(         0),  UINT16_C(        15),  UINT16_C(         0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x8_t a = simde_vld1q_f16(test_vec[i].a);
    simde_uint16x8_t r = simde_vcvtmq_u16_f16(a);
    simde_test_arm_neon_assert_equal_u16x8(r, simde_vld1q_u16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vcvtm_u16_f16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float16 a[4];
    uint16_t r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT16_VALUE( -7.554),  SIMDE_FLOAT16_VALUE(    12.499),  SIMDE_FLOAT16_VALUE(    11.710),  SIMDE_FLOAT16_VALUE(    17.107) },
      {  UINT16_C(         0),  UINT16_C(        12),  UINT16_C(        11),  UINT16_C(        17) } },
    { {  SIMDE_FLOAT16_VALUE(    23.989), SIMDE_FLOAT16_VALUE( -6.183), SIMDE_FLOAT16_VALUE( -20.293),  SIMDE_FLOAT16_VALUE(    23.741) },
      {  UINT16_C(        23),  UINT16_C(         0),  UINT16_C(         0),  UINT16_C(        23) } },
    { { SIMDE_FLOAT16_VALUE( -26.994), SIMDE_FLOAT16_VALUE( -20.235),  SIMDE_FLOAT16_VALUE(     1.138),  SIMDE_FLOAT16_VALUE(     7.304) },
      {  UINT16_C(         0),  UINT16_C(         0),  UINT16_C(         1),  UINT16_C(         7) } },
    { { SIMDE_FLOAT16_VALUE( -15.929),  SIMDE_FLOAT16_VALUE(    25.035),  SIMDE_FLOAT16_VALUE(    21.848), SIMDE_FLOAT16_VALUE( -5.458) },
      {  UINT16_C(         0),  UINT16_C(        25),  UINT16_C(        21),  UINT16_C(         0) } },
    { { SIMDE_FLOAT16_VALUE( -14.677),  SIMDE_FLOAT16_VALUE(     6.064),  SIMDE_FLOAT16_VALUE(    23.437),  SIMDE_FLOAT16_VALUE(     7.868) },
      {  UINT16_C(         0),  UINT16_C(         6),  UINT16_C(        23),  UINT16_C(         7) } },
    { {  SIMDE_FLOAT16_VALUE(     1.168),  SIMDE_FLOAT16_VALUE(     1.806),  SIMDE_FLOAT16_VALUE(     5.880), SIMDE_FLOAT16_VALUE( -24.614) },
      {  UINT16_C(         1),  UINT16_C(         1),  UINT16_C(         5),  UINT16_C(         0) } },
    { { SIMDE_FLOAT16_VALUE( -1.777),  SIMDE_FLOAT16_VALUE(     9.222), SIMDE_FLOAT16_VALUE( -24.729),  SIMDE_FLOAT16_VALUE(    21.150) },
      {  UINT16_C(         0),  UINT16_C(         9),  UINT16_C(         0),  UINT16_C(        21) } },
    { {  SIMDE_FLOAT16_VALUE(     2.919), SIMDE_FLOAT16_VALUE( -26.070), SIMDE_FLOAT16_VALUE( -19.134), SIMDE_FLOAT16_VALUE( -5.082) },
      {  UINT16_C(         2),  UINT16_C(         0),  UINT16_C(         0),  UINT16_C(         0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x4_t a = simde_vld1_f16(test_vec[i].a);
    simde_uint16x4_t r = simde_vcvtm_u16_f16(a);
    simde_test_arm_neon_assert_equal_u16x4(r, simde_vld1_u16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vcvtm_u32_f32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float32 a[2];
    uint32_t r[2];
  } test_vec[] = {
    { {  SIMDE_FLOAT32_C(   594.107), -SIMDE_FLOAT32_C(   285.820) },
      {  UINT32_C(       594),  UINT32_C(         0) } },
    { {  SIMDE_FLOAT32_C(   829.159), -SIMDE_FLOAT32_C(   787.785) },
      {  UINT32_C(       829),  UINT32_C(         0) } },
    { {  SIMDE_FLOAT32_C(   573.783), -SIMDE_FLOAT32_C(   597.192) },
      {  UINT32_C(       573),  UINT32_C(         0) } },
    { { -SIMDE_FLOAT32_C(    75.398),  SIMDE_FLOAT32_C(   243.062) },
      {  UINT32_C(         0),  UINT32_C(       243) } },
    { {  SIMDE_FLOAT32_C(   759.492),  SIMDE_FLOAT32_C(   515.804) },
      {  UINT32_C(       759),  UINT32_C(       515) } },
    { {  SIMDE_FLOAT32_C(   887.603), -SIMDE_FLOAT32_C(   104.547) },
      {  UINT32_C(       887),  UINT32_C(         0) } },
    { { -SIMDE_FLOAT32_C(   431.950), -SIMDE_FLOAT32_C(   610.039) },
      {  UINT32_C(         0),  UINT32_C(         0) } },
    { {  SIMDE_FLOAT32_C(   646.903),  SIMDE_FLOAT32_C(    28.109) },
      {  UINT32_C(       646),  UINT32_C(        28) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t a = simde_vld1_f32(test_vec[i].a);
    simde_uint32x2_t r = simde_vcvtm_u32_f32(a);
    simde_test_arm_neon_assert_equal_u32x2(r, simde_vld1_u32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vcvtm_s32_f32 (SIMDE_MUNIT_TEST_ARGS) {
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
}

static int
test_simde_vcvtm_s64_f64 (SIMDE_MUNIT_TEST_ARGS) {
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
}

static int
test_simde_vcvtm_u64_f64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float64 a[1];
    uint64_t r[1];
  } test_vec[] = {
    { { -SIMDE_FLOAT64_C( 64898.938) },
      {  UINT64_C(         0) } },
    { {  SIMDE_FLOAT64_C( 45090.750) },
      {  UINT64_C(     45090) } },
    { { -SIMDE_FLOAT64_C( 79406.664) },
      {  UINT64_C(         0) } },
    { {  SIMDE_FLOAT64_C( 35254.516) },
      {  UINT64_C(     35254) } },
    { { -SIMDE_FLOAT64_C( 33355.578) },
      {  UINT64_C(         0) } },
    { {  SIMDE_FLOAT64_C( 90902.766) },
      {  UINT64_C(     90902) } },
    { { -SIMDE_FLOAT64_C( 93056.258) },
      {  UINT64_C(         0) } },
    { { -SIMDE_FLOAT64_C( 34309.086) },
      {  UINT64_C(         0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x1_t a = simde_vld1_f64(test_vec[i].a);
    simde_uint64x1_t r = simde_vcvtm_u64_f64(a);
    simde_test_arm_neon_assert_equal_u64x1(r, simde_vld1_u64(test_vec[i].r));
  }

  return 0;
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtms_s32_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtmd_s64_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtms_u32_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtmd_u64_f64)

SIMDE_TEST_FUNC_LIST_ENTRY(vcvtmh_s16_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtmh_s32_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtmh_s64_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtmh_u16_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtmh_u32_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtmh_u64_f16)

SIMDE_TEST_FUNC_LIST_ENTRY(vcvtm_s16_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtm_u16_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtm_u32_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtm_s32_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtm_s64_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtm_u64_f64)

SIMDE_TEST_FUNC_LIST_ENTRY(vcvtmq_s16_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtmq_s32_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtmq_s64_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtmq_u16_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtmq_u32_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtmq_u64_f64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
