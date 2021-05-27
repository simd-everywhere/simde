#define SIMDE_TEST_ARM_NEON_INSN cgtz

#include "test-neon.h"

/* Check that both of these work */
#if defined(__cplusplus)
  #include "../../../simde/arm/neon/cgtz.h"
#else
  #include "../../../simde/arm/neon.h"
#endif

static int
test_simde_vcgtz_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a[2];
    uint32_t r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   857.35), SIMDE_FLOAT32_C(     0.00) },
      {           UINT32_MAX, UINT32_C(         0) } },
    { { SIMDE_FLOAT32_C(   563.25), SIMDE_FLOAT32_C(  -646.04) },
      {           UINT32_MAX, UINT32_C(         0) } },
    { { SIMDE_FLOAT32_C(  -282.49), SIMDE_FLOAT32_C(   166.97) },
      { UINT32_C(         0),           UINT32_MAX } },
    { { SIMDE_FLOAT32_C(   481.87), SIMDE_FLOAT32_C(   349.86) },
      {           UINT32_MAX,           UINT32_MAX } },
    { { SIMDE_FLOAT32_C(   616.03), SIMDE_FLOAT32_C(     0.00) },
      {           UINT32_MAX, UINT32_C(         0) } },
    { { SIMDE_FLOAT32_C(  -725.00), SIMDE_FLOAT32_C(     0.00) },
      { UINT32_C(         0), UINT32_C(         0) } },
    { { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) },
      { UINT32_C(         0), UINT32_C(         0) } },
    { { SIMDE_FLOAT32_C(   440.03), SIMDE_FLOAT32_C(   616.59) },
      {           UINT32_MAX,           UINT32_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t a = simde_vld1_f32(test_vec[i].a);
    simde_uint32x2_t r = simde_vcgtz_f32(a);

    simde_test_arm_neon_assert_equal_u32x2(r, simde_vld1_u32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x2_private a_ = simde_float32x2_to_private(simde_test_arm_neon_random_f32x2(-1000.0, 1000.0));

    /* Make some equal which is unlikely to happen by accident. */
    for (size_t j = 0 ; j < (sizeof(a_.values) / sizeof(a_.values[0])) ; j++) {
      if (rand() < (RAND_MAX / 3)) a_.values[j] = 0.0;
    }

    simde_float32x2_t a = simde_float32x2_from_private(a_);

    simde_uint32x2_t r = simde_vcgtz_f32(a);

    simde_test_arm_neon_write_f32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcgtz_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 a[1];
    uint64_t r[1];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(  -862.57) },
      { UINT64_C(                   0) } },
    { { SIMDE_FLOAT64_C(   383.63) },
      {                    UINT64_MAX } },
    { { SIMDE_FLOAT64_C(  -377.66) },
      { UINT64_C(                   0) } },
    { { SIMDE_FLOAT64_C(  -519.74) },
      { UINT64_C(                   0) } },
    { { SIMDE_FLOAT64_C(   357.37) },
      {                    UINT64_MAX } },
    { { SIMDE_FLOAT64_C(     0.00) },
      { UINT64_C(                   0) } },
    { { SIMDE_FLOAT64_C(  -484.99) },
      { UINT64_C(                   0) } },
    { { SIMDE_FLOAT64_C(  -884.47) },
      { UINT64_C(                   0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x1_t a = simde_vld1_f64(test_vec[i].a);
    simde_uint64x1_t r = simde_vcgtz_f64(a);

    simde_test_arm_neon_assert_equal_u64x1(r, simde_vld1_u64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x1_private a_ = simde_float64x1_to_private(simde_test_arm_neon_random_f64x1(-1000.0, 1000.0));

    /* Make some equal which is unlikely to happen by accident. */
    for (size_t j = 0 ; j < (sizeof(a_.values) / sizeof(a_.values[0])) ; j++) {
      if (rand() < (RAND_MAX / 3)) a_.values[j] = 0.0;
    }

    simde_float64x1_t a = simde_float64x1_from_private(a_);

    simde_uint64x1_t r = simde_vcgtz_f64(a);

    simde_test_arm_neon_write_f64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcgtz_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[8];
    uint8_t r[8];
  } test_vec[] = {
    { {  INT8_C(  15), -INT8_C(  54),  INT8_C(  73),  INT8_C(  90),  INT8_C(   0), -INT8_C( 125),  INT8_C(   0),  INT8_C(   0) },
      {    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) } },
    { { -INT8_C(  43),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  31) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) } },
    { {  INT8_C(   0), -INT8_C(   7),  INT8_C(   0), -INT8_C( 125),  INT8_C( 124), -INT8_C( 127),  INT8_C(  27), -INT8_C(  17) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0) } },
    { { -INT8_C(  25),  INT8_C( 116),  INT8_C(  39), -INT8_C(  32),  INT8_C(   0), -INT8_C( 124),  INT8_C(   0),  INT8_C(   0) },
      { UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) } },
    { {  INT8_C(  29),  INT8_C(   0),  INT8_C(  72),  INT8_C(   0), -INT8_C( 114),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0) },
      {    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) } },
    { { -INT8_C( 124), -INT8_C( 100),  INT8_C(  51),  INT8_C(  30),  INT8_C(   0), -INT8_C(  11),      INT8_MAX,  INT8_C(   0) },
      { UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0) } },
    { {  INT8_C(  32),  INT8_C(   0), -INT8_C(  50), -INT8_C(  82),  INT8_C(   0),  INT8_C(  86),  INT8_C( 106), -INT8_C(  97) },
      {    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0) } },
    { {  INT8_C(   0),  INT8_C(   0),  INT8_C(  17), -INT8_C(  29),  INT8_C(   0), -INT8_C( 112), -INT8_C(  84),  INT8_C(   0) },
      { UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8_t a = simde_vld1_s8(test_vec[i].a);
    simde_uint8x8_t r = simde_vcgtz_s8(a);

    simde_test_arm_neon_assert_equal_u8x8(r, simde_vld1_u8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x8_private a_ = simde_int8x8_to_private(simde_test_arm_neon_random_i8x8());

    /* Make some equal which is unlikely to happen by accident. */
    for (size_t j = 0 ; j < (sizeof(a_.values) / sizeof(a_.values[0])) ; j++) {
      if (rand() < (RAND_MAX / 3)) a_.values[j] = 0;
    }

    simde_int8x8_t a = simde_int8x8_from_private(a_);

    simde_uint8x8_t r = simde_vcgtz_s8(a);

    simde_test_arm_neon_write_i8x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcgtz_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[4];
    uint16_t r[4];
  } test_vec[] = {
    { {  INT16_C(     0),  INT16_C(  7845),  INT16_C(     0),  INT16_C(  5355) },
      { UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX } },
    { { -INT16_C( 19595),  INT16_C( 15250), -INT16_C( 24818),  INT16_C( 24104) },
      { UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX } },
    { {  INT16_C( 26221),  INT16_C(  6909),  INT16_C( 24749), -INT16_C( 16175) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0) } },
    { {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { {  INT16_C(  2518),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) },
      {      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { {  INT16_C( 23682), -INT16_C( 19310),  INT16_C( 29139),  INT16_C( 30817) },
      {      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX } },
    { {  INT16_C(  9010), -INT16_C(  3056),  INT16_C(     0),  INT16_C( 12741) },
      {      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX } },
    { { -INT16_C( 13646),  INT16_C(     0),  INT16_C(     0),  INT16_C( 28329) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t a = simde_vld1_s16(test_vec[i].a);
    simde_uint16x4_t r = simde_vcgtz_s16(a);

    simde_test_arm_neon_assert_equal_u16x4(r, simde_vld1_u16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x4_private a_ = simde_int16x4_to_private(simde_test_arm_neon_random_i16x4());

    /* Make some equal which is unlikely to happen by accident. */
    for (size_t j = 0 ; j < (sizeof(a_.values) / sizeof(a_.values[0])) ; j++) {
      if (rand() < (RAND_MAX / 3)) a_.values[j] = 0;
    }

    simde_int16x4_t a = simde_int16x4_from_private(a_);

    simde_uint16x4_t r = simde_vcgtz_s16(a);

    simde_test_arm_neon_write_i16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcgtz_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[2];
    uint32_t r[2];
  } test_vec[] = {
    { { -INT32_C(   435877116), -INT32_C(   718669983) },
      { UINT32_C(         0), UINT32_C(         0) } },
    { { -INT32_C(  1100467344),  INT32_C(           0) },
      { UINT32_C(         0), UINT32_C(         0) } },
    { {  INT32_C(           0),  INT32_C(   374803573) },
      { UINT32_C(         0),           UINT32_MAX } },
    { {  INT32_C(  1937880686), -INT32_C(   982850916) },
      {           UINT32_MAX, UINT32_C(         0) } },
    { {  INT32_C(   308225961),  INT32_C(   489722853) },
      {           UINT32_MAX,           UINT32_MAX } },
    { {  INT32_C(           0), -INT32_C(   621839229) },
      { UINT32_C(         0), UINT32_C(         0) } },
    { {  INT32_C(           0),  INT32_C(           0) },
      { UINT32_C(         0), UINT32_C(         0) } },
    { {  INT32_C(  1754358537), -INT32_C(  1493404043) },
      {           UINT32_MAX, UINT32_C(         0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t a = simde_vld1_s32(test_vec[i].a);
    simde_uint32x2_t r = simde_vcgtz_s32(a);

    simde_test_arm_neon_assert_equal_u32x2(r, simde_vld1_u32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x2_private a_ = simde_int32x2_to_private(simde_test_arm_neon_random_i32x2());

    /* Make some equal which is unlikely to happen by accident. */
    for (size_t j = 0 ; j < (sizeof(a_.values) / sizeof(a_.values[0])) ; j++) {
      if (rand() < (RAND_MAX / 3)) a_.values[j] = 0;
    }

    simde_int32x2_t a = simde_int32x2_from_private(a_);

    simde_uint32x2_t r = simde_vcgtz_s32(a);

    simde_test_arm_neon_write_i32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcgtz_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a[1];
    uint64_t r[1];
  } test_vec[] = {
    { {  INT64_C(  637165716263353288) },
      {                    UINT64_MAX } },
    { {  INT64_C(                   0) },
      { UINT64_C(                   0) } },
    { { -INT64_C( 2096199424180815067) },
      { UINT64_C(                   0) } },
    { {  INT64_C(                   0) },
      { UINT64_C(                   0) } },
    { {  INT64_C( 3839009869349841013) },
      {                    UINT64_MAX } },
    { { -INT64_C( 8324557890790649979) },
      { UINT64_C(                   0) } },
    { { -INT64_C( 3120066588333083577) },
      { UINT64_C(                   0) } },
    { {  INT64_C(                   0) },
      { UINT64_C(                   0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x1_t a = simde_vld1_s64(test_vec[i].a);
    simde_uint64x1_t r = simde_vcgtz_s64(a);

    simde_test_arm_neon_assert_equal_u64x1(r, simde_vld1_u64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int64x1_private a_ = simde_int64x1_to_private(simde_test_arm_neon_random_i64x1());

    /* Make some equal which is unlikely to happen by accident. */
    for (size_t j = 0 ; j < (sizeof(a_.values) / sizeof(a_.values[0])) ; j++) {
      if (rand() < (RAND_MAX / 3)) a_.values[j] = 0;
    }

    simde_int64x1_t a = simde_int64x1_from_private(a_);

    simde_uint64x1_t r = simde_vcgtz_s64(a);

    simde_test_arm_neon_write_i64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcgtzq_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a[4];
    uint32_t r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   610.80), SIMDE_FLOAT32_C(  -604.76), SIMDE_FLOAT32_C(   570.85), SIMDE_FLOAT32_C(   181.79) },
      {           UINT32_MAX, UINT32_C(         0),           UINT32_MAX,           UINT32_MAX } },
    { { SIMDE_FLOAT32_C(  -781.68), SIMDE_FLOAT32_C(   808.07), SIMDE_FLOAT32_C(  -280.25), SIMDE_FLOAT32_C(   389.37) },
      { UINT32_C(         0),           UINT32_MAX, UINT32_C(         0),           UINT32_MAX } },
    { { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -848.94) },
      { UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0) } },
    { { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   883.90), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -623.70) },
      { UINT32_C(         0),           UINT32_MAX, UINT32_C(         0), UINT32_C(         0) } },
    { { SIMDE_FLOAT32_C(  -968.78), SIMDE_FLOAT32_C(  -829.47), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    43.73) },
      { UINT32_C(         0), UINT32_C(         0), UINT32_C(         0),           UINT32_MAX } },
    { { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    64.92), SIMDE_FLOAT32_C(     0.00) },
      { UINT32_C(         0), UINT32_C(         0),           UINT32_MAX, UINT32_C(         0) } },
    { { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   931.44), SIMDE_FLOAT32_C(  -717.64), SIMDE_FLOAT32_C(   921.07) },
      { UINT32_C(         0),           UINT32_MAX, UINT32_C(         0),           UINT32_MAX } },
    { { SIMDE_FLOAT32_C(  -374.65), SIMDE_FLOAT32_C(   314.40), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -187.17) },
      { UINT32_C(         0),           UINT32_MAX, UINT32_C(         0), UINT32_C(         0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_uint32x4_t r = simde_vcgtzq_f32(a);

    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x4_private a_ = simde_float32x4_to_private(simde_test_arm_neon_random_f32x4(-1000.0, 1000.0));

    /* Make some equal which is unlikely to happen by accident. */
    for (size_t j = 0 ; j < (sizeof(a_.values) / sizeof(a_.values[0])) ; j++) {
      if (rand() < (RAND_MAX / 3)) a_.values[j] = 0.0;
    }

    simde_float32x4_t a = simde_float32x4_from_private(a_);

    simde_uint32x4_t r = simde_vcgtzq_f32(a);

    simde_test_arm_neon_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcgtzq_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 a[2];
    uint64_t r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(  -919.27), SIMDE_FLOAT64_C(   975.16) },
      { UINT64_C(                   0),                    UINT64_MAX } },
    { { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   -36.67) },
      { UINT64_C(                   0), UINT64_C(                   0) } },
    { { SIMDE_FLOAT64_C(   540.59), SIMDE_FLOAT64_C(     0.00) },
      {                    UINT64_MAX, UINT64_C(                   0) } },
    { { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   839.91) },
      { UINT64_C(                   0),                    UINT64_MAX } },
    { { SIMDE_FLOAT64_C(   293.38), SIMDE_FLOAT64_C(     0.00) },
      {                    UINT64_MAX, UINT64_C(                   0) } },
    { { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -105.76) },
      { UINT64_C(                   0), UINT64_C(                   0) } },
    { { SIMDE_FLOAT64_C(  -155.06), SIMDE_FLOAT64_C(     0.00) },
      { UINT64_C(                   0), UINT64_C(                   0) } },
    { { SIMDE_FLOAT64_C(  -532.89), SIMDE_FLOAT64_C(     0.00) },
      { UINT64_C(                   0), UINT64_C(                   0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2_t a = simde_vld1q_f64(test_vec[i].a);
    simde_uint64x2_t r = simde_vcgtzq_f64(a);

    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x2_private a_ = simde_float64x2_to_private(simde_test_arm_neon_random_f64x2(-1000.0, 1000.0));

    /* Make some equal which is unlikely to happen by accident. */
    for (size_t j = 0 ; j < (sizeof(a_.values) / sizeof(a_.values[0])) ; j++) {
      if (rand() < (RAND_MAX / 3)) a_.values[j] = 0.0;
    }

    simde_float64x2_t a = simde_float64x2_from_private(a_);

    simde_uint64x2_t r = simde_vcgtzq_f64(a);

    simde_test_arm_neon_write_f64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcgtzq_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[16];
    uint8_t r[16];
  } test_vec[] = {
    { { -INT8_C(  34), -INT8_C( 103),  INT8_C( 113),  INT8_C(  58),  INT8_C(  32), -INT8_C( 105),  INT8_C(  28), -INT8_C(  43),
         INT8_C(   0), -INT8_C(  67),  INT8_C(  24),  INT8_C(   0), -INT8_C(  15),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0) },
      { UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) } },
    { {  INT8_C(  85),  INT8_C(   0),  INT8_C(   0),  INT8_C( 118),  INT8_C(   0),  INT8_C(  99),  INT8_C(  75),  INT8_C(   0),
         INT8_C(  32),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C( 113), -INT8_C(  28),  INT8_C( 121),  INT8_C(   0) },
      {    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),
           UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0) } },
    { { -INT8_C(  72),  INT8_C(   0),  INT8_C(   0),  INT8_C(   9),  INT8_C(   0),  INT8_C(   0), -INT8_C( 122), -INT8_C(  64),
         INT8_C( 122),  INT8_C(   0), -INT8_C(  46),  INT8_C(  10),  INT8_C(  62),  INT8_C(  75),  INT8_C(   0), -INT8_C(   5) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
           UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0) } },
    { {  INT8_C(  27),  INT8_C(  14),  INT8_C(   0), -INT8_C(  69),  INT8_C(  37),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0), -INT8_C(  87), -INT8_C( 112), -INT8_C( 104),  INT8_C(   0),  INT8_C(   0), -INT8_C( 106) },
      {    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) } },
    { {  INT8_C(  80),  INT8_C(   0),  INT8_C(   0),  INT8_C( 117),  INT8_C(   0), -INT8_C(  15),  INT8_C(  21),  INT8_C(   0),
         INT8_C(  62), -INT8_C(  66),  INT8_C(  88),  INT8_C(   0),  INT8_C(  82),  INT8_C(   0),  INT8_C( 108),  INT8_C(   0) },
      {    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),
           UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0) } },
    { {  INT8_C(   0),  INT8_C(  41),  INT8_C(   0), -INT8_C( 117),  INT8_C(  26), -INT8_C(  74),  INT8_C(  83),  INT8_C(  88),
         INT8_C(   0), -INT8_C(  85),  INT8_C(  46), -INT8_C(  57), -INT8_C( 114),  INT8_C(   0), -INT8_C(  81), -INT8_C(  18) },
      { UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,
        UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) } },
    { {  INT8_C(  52),  INT8_C(  79),  INT8_C(   0),  INT8_C(  78),  INT8_C(   5),  INT8_C(   0),  INT8_C(   0),  INT8_C( 122),
        -INT8_C(  17), -INT8_C(  44),  INT8_C(  65),  INT8_C( 125),  INT8_C(   0), -INT8_C(  16),  INT8_C(   0), -INT8_C(  67) },
      {    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,
        UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) } },
    { {  INT8_C(  16),  INT8_C(   0), -INT8_C(  84),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  61),
         INT8_C(  38), -INT8_C(  47),  INT8_C(  64), -INT8_C( 107),  INT8_C(   0), -INT8_C(  85),  INT8_C(  82),  INT8_C(  34) },
      {    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
           UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16_t a = simde_vld1q_s8(test_vec[i].a);
    simde_uint8x16_t r = simde_vcgtzq_s8(a);

    simde_test_arm_neon_assert_equal_u8x16(r, simde_vld1q_u8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x16_private a_ = simde_int8x16_to_private(simde_test_arm_neon_random_i8x16());

    /* Make some equal which is unlikely to happen by accident. */
    for (size_t j = 0 ; j < (sizeof(a_.values) / sizeof(a_.values[0])) ; j++) {
      if (rand() < (RAND_MAX / 3)) a_.values[j] = 0;
    }

    simde_int8x16_t a = simde_int8x16_from_private(a_);

    simde_uint8x16_t r = simde_vcgtzq_s8(a);

    simde_test_arm_neon_write_i8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcgtzq_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[8];
    uint16_t r[8];
  } test_vec[] = {
    { { -INT16_C( 13787),  INT16_C( 10471),  INT16_C( 31422),  INT16_C( 25101),  INT16_C(  7709),  INT16_C( 12583),  INT16_C(     0),  INT16_C(  5018) },
      { UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX } },
    { {  INT16_C( 13969), -INT16_C( 22918),  INT16_C( 14574),  INT16_C(  4890),  INT16_C(   258), -INT16_C( 16325),  INT16_C( 18812),  INT16_C(     0) },
      {      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0) } },
    { {  INT16_C( 14880),  INT16_C(     0),  INT16_C(     0), -INT16_C( 28010),  INT16_C(  4584), -INT16_C( 10696),  INT16_C( 21321),  INT16_C( 19433) },
      {      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX } },
    { {  INT16_C( 13433),  INT16_C(     0), -INT16_C( 18791),  INT16_C(     0), -INT16_C( 24592), -INT16_C(  3774), -INT16_C( 10159),  INT16_C( 14724) },
      {      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX } },
    { {  INT16_C(     0), -INT16_C( 29900),  INT16_C(     0),  INT16_C( 12896),  INT16_C(     0),  INT16_C( 27757), -INT16_C( 18989),  INT16_C(     0) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    0) } },
    { {  INT16_C(     0),  INT16_C(  1371),  INT16_C(     0),  INT16_C(   873), -INT16_C( 25245),  INT16_C(     0), -INT16_C(  4292),  INT16_C(  3919) },
      { UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX } },
    { {  INT16_C( 22279),  INT16_C( 18026),  INT16_C(     0), -INT16_C( 31377), -INT16_C( 13515),  INT16_C(  6794), -INT16_C(  3164),  INT16_C(  2077) },
      {      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX } },
    { {  INT16_C( 22319), -INT16_C( 24443),  INT16_C( 10231), -INT16_C(   411), -INT16_C( 12418),  INT16_C(     0), -INT16_C( 19433),  INT16_C(     0) },
      {      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_uint16x8_t r = simde_vcgtzq_s16(a);

    simde_test_arm_neon_assert_equal_u16x8(r, simde_vld1q_u16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x8_private a_ = simde_int16x8_to_private(simde_test_arm_neon_random_i16x8());

    /* Make some equal which is unlikely to happen by accident. */
    for (size_t j = 0 ; j < (sizeof(a_.values) / sizeof(a_.values[0])) ; j++) {
      if (rand() < (RAND_MAX / 3)) a_.values[j] = 0;
    }

    simde_int16x8_t a = simde_int16x8_from_private(a_);

    simde_uint16x8_t r = simde_vcgtzq_s16(a);

    simde_test_arm_neon_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcgtzq_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[4];
    uint32_t r[4];
  } test_vec[] = {
    { {  INT32_C(           0),  INT32_C(   551830307),  INT32_C(           0),  INT32_C(           0) },
      { UINT32_C(         0),           UINT32_MAX, UINT32_C(         0), UINT32_C(         0) } },
    { {  INT32_C(           0), -INT32_C(  2099009646), -INT32_C(   383656512),  INT32_C(           0) },
      { UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0) } },
    { {  INT32_C(           0), -INT32_C(  1902038387),  INT32_C(  2002197176),  INT32_C(           0) },
      { UINT32_C(         0), UINT32_C(         0),           UINT32_MAX, UINT32_C(         0) } },
    { {  INT32_C(           0), -INT32_C(  1228072830),  INT32_C(  1882166330),  INT32_C(           0) },
      { UINT32_C(         0), UINT32_C(         0),           UINT32_MAX, UINT32_C(         0) } },
    { {  INT32_C(   678303692),  INT32_C(           0),  INT32_C(           0), -INT32_C(  1645960934) },
      {           UINT32_MAX, UINT32_C(         0), UINT32_C(         0), UINT32_C(         0) } },
    { { -INT32_C(   362511803), -INT32_C(   836995953), -INT32_C(   238691291),  INT32_C(           0) },
      { UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0) } },
    { {  INT32_C(           0), -INT32_C(  1972289328),  INT32_C(   931055089), -INT32_C(   702422457) },
      { UINT32_C(         0), UINT32_C(         0),           UINT32_MAX, UINT32_C(         0) } },
    { {  INT32_C(   242051610),  INT32_C(   614696862),  INT32_C(  1925385656),  INT32_C(   222764860) },
      {           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_uint32x4_t r = simde_vcgtzq_s32(a);

    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x4_private a_ = simde_int32x4_to_private(simde_test_arm_neon_random_i32x4());

    /* Make some equal which is unlikely to happen by accident. */
    for (size_t j = 0 ; j < (sizeof(a_.values) / sizeof(a_.values[0])) ; j++) {
      if (rand() < (RAND_MAX / 3)) a_.values[j] = 0;
    }

    simde_int32x4_t a = simde_int32x4_from_private(a_);

    simde_uint32x4_t r = simde_vcgtzq_s32(a);

    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcgtzq_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a[2];
    uint64_t r[2];
  } test_vec[] = {
    { { -INT64_C( 2722594793879081836), -INT64_C( 7336936062086546730) },
      { UINT64_C(                   0), UINT64_C(                   0) } },
    { { -INT64_C( 5132795313325816595),  INT64_C( 1914458200832322093) },
      { UINT64_C(                   0),                    UINT64_MAX } },
    { { -INT64_C(  464587147821614976),  INT64_C(                   0) },
      { UINT64_C(                   0), UINT64_C(                   0) } },
    { { -INT64_C(  356795487879775814), -INT64_C( 8887970811507008019) },
      { UINT64_C(                   0), UINT64_C(                   0) } },
    { { -INT64_C( 2556735944492090887),  INT64_C(                   0) },
      { UINT64_C(                   0), UINT64_C(                   0) } },
    { { -INT64_C( 2440868277195989500),  INT64_C(                   0) },
      { UINT64_C(                   0), UINT64_C(                   0) } },
    { {  INT64_C(                   0),  INT64_C( 2747886199500617458) },
      { UINT64_C(                   0),                    UINT64_MAX } },
    { {  INT64_C( 3323549104968795506),  INT64_C( 3818980872865146362) },
      {                    UINT64_MAX,                    UINT64_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);
    simde_uint64x2_t r = simde_vcgtzq_s64(a);

    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int64x2_private a_ = simde_int64x2_to_private(simde_test_arm_neon_random_i64x2());

    /* Make some equal which is unlikely to happen by accident. */
    for (size_t j = 0 ; j < (sizeof(a_.values) / sizeof(a_.values[0])) ; j++) {
      if (rand() < (RAND_MAX / 3)) a_.values[j] = 0;
    }

    simde_int64x2_t a = simde_int64x2_from_private(a_);

    simde_uint64x2_t r = simde_vcgtzq_s64(a);

    simde_test_arm_neon_write_i64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcgtzd_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a;
    uint64_t r;
  } test_vec[] = {
    { -INT64_C( 7092078020180908211),
      UINT64_C(                   0) },
    { -INT64_C( 2081468342488495496),
      UINT64_C(                   0) },
    {  INT64_C( 4158752479517361129),
                          UINT64_MAX },
    { -INT64_C( 4468962310629773370),
      UINT64_C(                   0) },
    {  INT64_C( 1598791738623311349),
                          UINT64_MAX },
    { -INT64_C(  285058202827427690),
      UINT64_C(                   0) },
    {  INT64_C( 1448273756347069320),
                          UINT64_MAX },
    {  INT64_C( 7580350321362560764),
                          UINT64_MAX }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint64_t r = simde_vcgtzd_s64(test_vec[i].a);
    simde_assert_equal_u64(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    int64_t a = simde_test_codegen_random_i64();
    uint64_t r = simde_vcgtzd_s64(a);

    simde_test_codegen_write_i64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcgtzd_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64_t a;
    uint64_t r;
  } test_vec[] = {
    { SIMDE_FLOAT64_C(  -807.76),
      UINT64_C(                   0) },
    { SIMDE_FLOAT64_C(   173.20),
                          UINT64_MAX },
    { SIMDE_FLOAT64_C(   642.73),
                          UINT64_MAX },
    { SIMDE_FLOAT64_C(   628.29),
                          UINT64_MAX },
    { SIMDE_FLOAT64_C(  -508.17),
      UINT64_C(                   0) },
    { SIMDE_FLOAT64_C(   480.29),
                          UINT64_MAX },
    { SIMDE_FLOAT64_C(  -490.40),
      UINT64_C(                   0) },
    { SIMDE_FLOAT64_C(   174.42),
                          UINT64_MAX }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint64_t r = simde_vcgtzd_f64(test_vec[i].a);
    simde_assert_equal_u64(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64_t a = simde_test_codegen_random_f64(-1000, 1000);
    uint64_t r = simde_vcgtzd_f64(a);

    simde_test_codegen_write_f64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcgtzs_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32_t a;
    uint32_t r;
  } test_vec[] = {
    { SIMDE_FLOAT32_C(   278.45),
                UINT32_MAX },
    { SIMDE_FLOAT32_C(  -325.45),
      UINT32_C(         0) },
    { SIMDE_FLOAT32_C(  -203.78),
      UINT32_C(         0) },
    { SIMDE_FLOAT32_C(  -992.26),
      UINT32_C(         0) },
    { SIMDE_FLOAT32_C(   215.89),
                UINT32_MAX },
    { SIMDE_FLOAT32_C(   908.52),
                UINT32_MAX },
    { SIMDE_FLOAT32_C(  -860.21),
      UINT32_C(         0) },
    { SIMDE_FLOAT32_C(  -813.65),
      UINT32_C(         0) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint32_t r = simde_vcgtzs_f32(test_vec[i].a);
    simde_assert_equal_u32(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32_t a = simde_test_codegen_random_f32(-1000, 1000);
    uint32_t r = simde_vcgtzs_f32(a);

    simde_test_codegen_write_f32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vcgtz_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcgtz_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vcgtz_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vcgtz_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcgtz_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcgtz_s64)

SIMDE_TEST_FUNC_LIST_ENTRY(vcgtzq_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcgtzq_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vcgtzq_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vcgtzq_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcgtzq_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcgtzq_s64)

SIMDE_TEST_FUNC_LIST_ENTRY(vcgtzd_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vcgtzd_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vcgtzs_f32)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
