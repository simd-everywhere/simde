#define SIMDE_TEST_ARM_NEON_INSN cgez

#include "test-neon.h"

/* Check that both of these work */
#if defined(__cplusplus)
  #include "../../../simde/arm/neon/cgez.h"
#else
  #include "../../../simde/arm/neon.h"
#endif

static int
test_simde_vcgez_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a[2];
    uint32_t r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -133.39), SIMDE_FLOAT32_C(   805.67) },
      { UINT32_C(         0),           UINT32_MAX } },
    { { SIMDE_FLOAT32_C(  -910.74), SIMDE_FLOAT32_C(   710.63) },
      { UINT32_C(         0),           UINT32_MAX } },
    { { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   230.14) },
      {           UINT32_MAX,           UINT32_MAX } },
    { { SIMDE_FLOAT32_C(   994.82), SIMDE_FLOAT32_C(  -639.98) },
      {           UINT32_MAX, UINT32_C(         0) } },
    { { SIMDE_FLOAT32_C(   -48.27), SIMDE_FLOAT32_C(     0.00) },
      { UINT32_C(         0),           UINT32_MAX } },
    { { SIMDE_FLOAT32_C(    98.24), SIMDE_FLOAT32_C(     0.00) },
      {           UINT32_MAX,           UINT32_MAX } },
    { { SIMDE_FLOAT32_C(   -63.24), SIMDE_FLOAT32_C(   224.59) },
      { UINT32_C(         0),           UINT32_MAX } },
    { { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    43.88) },
      {           UINT32_MAX,           UINT32_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t a = simde_vld1_f32(test_vec[i].a);
    simde_uint32x2_t r = simde_vcgez_f32(a);

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

    simde_uint32x2_t r = simde_vcgez_f32(a);

    simde_test_arm_neon_write_f32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcgez_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 a[1];
    uint64_t r[1];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(   625.39) },
      {                    UINT64_MAX } },
    { { SIMDE_FLOAT64_C(   786.84) },
      {                    UINT64_MAX } },
    { { SIMDE_FLOAT64_C(   381.01) },
      {                    UINT64_MAX } },
    { { SIMDE_FLOAT64_C(     0.00) },
      {                    UINT64_MAX } },
    { { SIMDE_FLOAT64_C(  -664.71) },
      { UINT64_C(                   0) } },
    { { SIMDE_FLOAT64_C(   389.46) },
      {                    UINT64_MAX } },
    { { SIMDE_FLOAT64_C(  -675.33) },
      { UINT64_C(                   0) } },
    { { SIMDE_FLOAT64_C(   539.16) },
      {                    UINT64_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x1_t a = simde_vld1_f64(test_vec[i].a);
    simde_uint64x1_t r = simde_vcgez_f64(a);

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

    simde_uint64x1_t r = simde_vcgez_f64(a);

    simde_test_arm_neon_write_f64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcgez_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[8];
    uint8_t r[8];
  } test_vec[] = {
    { {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  64),  INT8_C(   0), -INT8_C( 105), -INT8_C(  79) },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0) } },
    { {  INT8_C(  55),  INT8_C( 117), -INT8_C( 108), -INT8_C(  70),  INT8_C( 111),  INT8_C(   3),  INT8_C(   0), -INT8_C(   7) },
      {    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0) } },
    { {  INT8_C(  98), -INT8_C( 116),  INT8_C(   0),  INT8_C(  34),  INT8_C( 115),  INT8_C(   0), -INT8_C(  45),  INT8_C(  47) },
      {    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX } },
    { { -INT8_C(  28),  INT8_C(   5),  INT8_C(  22),  INT8_C(  84),  INT8_C(   0), -INT8_C(  92),  INT8_C(   0),  INT8_C(  77) },
      { UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX } },
    { {  INT8_C(   0), -INT8_C( 123), -INT8_C(  85), -INT8_C(   5),  INT8_C(  15),  INT8_C( 126),  INT8_C(  42), -INT8_C(  63) },
      {    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0) } },
    { {  INT8_C( 118),  INT8_C(   0),  INT8_C(   0),      INT8_MAX,  INT8_C( 115),  INT8_C(   3), -INT8_C(  52),  INT8_C(   0) },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX } },
    { { -INT8_C(  21),  INT8_C(   0),  INT8_C(  89),  INT8_C(   0), -INT8_C(  91), -INT8_C( 125),  INT8_C(   0),  INT8_C(   0) },
      { UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX } },
    { {  INT8_C(   0),  INT8_C(  41),  INT8_C(   0),  INT8_C(   0),  INT8_C(  45), -INT8_C(  17),  INT8_C(   0),  INT8_C(   0) },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8_t a = simde_vld1_s8(test_vec[i].a);
    simde_uint8x8_t r = simde_vcgez_s8(a);

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

    simde_uint8x8_t r = simde_vcgez_s8(a);

    simde_test_arm_neon_write_i8x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcgez_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[4];
    uint16_t r[4];
  } test_vec[] = {
    { {  INT16_C(     0), -INT16_C(  6705),  INT16_C( 23697), -INT16_C( 17451) },
      {      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0) } },
    { {  INT16_C( 23201), -INT16_C( 17829),  INT16_C(     0), -INT16_C(  7222) },
      {      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0) } },
    { {  INT16_C(     0), -INT16_C( 30718), -INT16_C( 29104),  INT16_C(     0) },
      {      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX } },
    { { -INT16_C( 13514), -INT16_C( 26536),  INT16_C( 11746), -INT16_C( 31865) },
      { UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0) } },
    { {  INT16_C(  2133),  INT16_C(     0), -INT16_C( 19825),  INT16_C(  7246) },
      {      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX } },
    { {  INT16_C(     0), -INT16_C(  5394), -INT16_C(  6774), -INT16_C( 16249) },
      {      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { { -INT16_C(  8180), -INT16_C( 27882),  INT16_C( 21699),  INT16_C(  6165) },
      { UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX } },
    { {  INT16_C(     0), -INT16_C( 17912),  INT16_C(     0), -INT16_C(  1385) },
      {      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t a = simde_vld1_s16(test_vec[i].a);
    simde_uint16x4_t r = simde_vcgez_s16(a);

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

    simde_uint16x4_t r = simde_vcgez_s16(a);

    simde_test_arm_neon_write_i16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcgez_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[2];
    uint32_t r[2];
  } test_vec[] = {
    { {  INT32_C(           0), -INT32_C(   190514591) },
      {           UINT32_MAX, UINT32_C(         0) } },
    { {  INT32_C(           0), -INT32_C(  1205804542) },
      {           UINT32_MAX, UINT32_C(         0) } },
    { {  INT32_C(  2075374757),  INT32_C(           0) },
      {           UINT32_MAX,           UINT32_MAX } },
    { {  INT32_C(   434605318),  INT32_C(  1427327409) },
      {           UINT32_MAX,           UINT32_MAX } },
    { {  INT32_C(           0),  INT32_C(  1377343026) },
      {           UINT32_MAX,           UINT32_MAX } },
    { {  INT32_C(  1046803595),  INT32_C(  1317271152) },
      {           UINT32_MAX,           UINT32_MAX } },
    { { -INT32_C(   135390449),  INT32_C(           0) },
      { UINT32_C(         0),           UINT32_MAX } },
    { {  INT32_C(           0),  INT32_C(           0) },
      {           UINT32_MAX,           UINT32_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t a = simde_vld1_s32(test_vec[i].a);
    simde_uint32x2_t r = simde_vcgez_s32(a);

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

    simde_uint32x2_t r = simde_vcgez_s32(a);

    simde_test_arm_neon_write_i32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcgez_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a[1];
    uint64_t r[1];
  } test_vec[] = {
    { {  INT64_C(                   0) },
      {                    UINT64_MAX } },
    { {  INT64_C( 7153887103871360744) },
      {                    UINT64_MAX } },
    { { -INT64_C(  264543239347917471) },
      { UINT64_C(                   0) } },
    { {  INT64_C(                   0) },
      {                    UINT64_MAX } },
    { { -INT64_C( 3851070515776987902) },
      { UINT64_C(                   0) } },
    { { -INT64_C( 4491853047625019068) },
      { UINT64_C(                   0) } },
    { {  INT64_C(                   0) },
      {                    UINT64_MAX } },
    { { -INT64_C( 3025692413433232025) },
      { UINT64_C(                   0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x1_t a = simde_vld1_s64(test_vec[i].a);
    simde_uint64x1_t r = simde_vcgez_s64(a);

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

    simde_uint64x1_t r = simde_vcgez_s64(a);

    simde_test_arm_neon_write_i64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcgezq_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a[4];
    uint32_t r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -369.77), SIMDE_FLOAT32_C(     0.00) },
      {           UINT32_MAX,           UINT32_MAX, UINT32_C(         0),           UINT32_MAX } },
    { { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   -41.03), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) },
      {           UINT32_MAX, UINT32_C(         0),           UINT32_MAX,           UINT32_MAX } },
    { { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   522.70), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) },
      {           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX } },
    { { SIMDE_FLOAT32_C(    98.50), SIMDE_FLOAT32_C(   454.13), SIMDE_FLOAT32_C(   842.39), SIMDE_FLOAT32_C(    35.69) },
      {           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX } },
    { { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   843.79), SIMDE_FLOAT32_C(  -966.00), SIMDE_FLOAT32_C(    39.60) },
      {           UINT32_MAX,           UINT32_MAX, UINT32_C(         0),           UINT32_MAX } },
    { { SIMDE_FLOAT32_C(   717.22), SIMDE_FLOAT32_C(   165.47), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   907.07) },
      {           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX } },
    { { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -252.33), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   684.67) },
      {           UINT32_MAX, UINT32_C(         0),           UINT32_MAX,           UINT32_MAX } },
    { { SIMDE_FLOAT32_C(    57.60), SIMDE_FLOAT32_C(   844.67), SIMDE_FLOAT32_C(  -357.97), SIMDE_FLOAT32_C(  -478.05) },
      {           UINT32_MAX,           UINT32_MAX, UINT32_C(         0), UINT32_C(         0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_uint32x4_t r = simde_vcgezq_f32(a);

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

    simde_uint32x4_t r = simde_vcgezq_f32(a);

    simde_test_arm_neon_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcgezq_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 a[2];
    uint64_t r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(   254.72), SIMDE_FLOAT64_C(   721.02) },
      {                    UINT64_MAX,                    UINT64_MAX } },
    { { SIMDE_FLOAT64_C(  -171.93), SIMDE_FLOAT64_C(     0.00) },
      { UINT64_C(                   0),                    UINT64_MAX } },
    { { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   341.16) },
      {                    UINT64_MAX,                    UINT64_MAX } },
    { { SIMDE_FLOAT64_C(    18.66), SIMDE_FLOAT64_C(     0.00) },
      {                    UINT64_MAX,                    UINT64_MAX } },
    { { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00) },
      {                    UINT64_MAX,                    UINT64_MAX } },
    { { SIMDE_FLOAT64_C(  -339.50), SIMDE_FLOAT64_C(    60.07) },
      { UINT64_C(                   0),                    UINT64_MAX } },
    { { SIMDE_FLOAT64_C(   298.41), SIMDE_FLOAT64_C(  -244.46) },
      {                    UINT64_MAX, UINT64_C(                   0) } },
    { { SIMDE_FLOAT64_C(  -617.84), SIMDE_FLOAT64_C(  -233.87) },
      { UINT64_C(                   0), UINT64_C(                   0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2_t a = simde_vld1q_f64(test_vec[i].a);
    simde_uint64x2_t r = simde_vcgezq_f64(a);

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

    simde_uint64x2_t r = simde_vcgezq_f64(a);

    simde_test_arm_neon_write_f64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcgezq_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[16];
    uint8_t r[16];
  } test_vec[] = {
    { { -INT8_C( 124),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  29),  INT8_C(  49),  INT8_C(   0), -INT8_C( 127),
        -INT8_C(  73),  INT8_C(  45), -INT8_C( 117),  INT8_C(  37), -INT8_C( 101),  INT8_C(  10),  INT8_C(  23),  INT8_C(  93) },
      { UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),
        UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX } },
    { { -INT8_C( 106),  INT8_C(   0), -INT8_C(  86),  INT8_C(   0), -INT8_C(   5),  INT8_C(   0),  INT8_C(  53), -INT8_C(  78),
         INT8_C(   0), -INT8_C(  64), -INT8_C(  40),  INT8_C(  95), -INT8_C(  54), -INT8_C(  17), -INT8_C(  68),  INT8_C(   0) },
      { UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),
           UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX } },
    { {  INT8_C(  36), -INT8_C(  86), -INT8_C(  57),  INT8_C(  31),  INT8_C(  64),  INT8_C(   0), -INT8_C(  46),  INT8_C(   0),
         INT8_C(   0), -INT8_C(  86),  INT8_C( 100), -INT8_C( 122), -INT8_C( 103),  INT8_C(  32),  INT8_C(  93), -INT8_C( 121) },
      {    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,
           UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0) } },
    { { -INT8_C(  70), -INT8_C( 108),  INT8_C(  60), -INT8_C(   5), -INT8_C( 112),  INT8_C(  14), -INT8_C(   1),  INT8_C(  76),
         INT8_C(   0),  INT8_C(   0), -INT8_C(  46),  INT8_C(   0), -INT8_C( 124),  INT8_C(  47),  INT8_C(   0),  INT8_C(   1) },
      { UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX } },
    { {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  58), -INT8_C(  64), -INT8_C(  34),  INT8_C(   0),
         INT8_C(  35), -INT8_C(  80),  INT8_C(   0), -INT8_C(  89),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  72) },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,
           UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0) } },
    { {  INT8_C(   0),  INT8_C(  40), -INT8_C(  91),  INT8_C(   0), -INT8_C(  24), -INT8_C( 125),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0), -INT8_C(  32), -INT8_C(  77),  INT8_C(   0), -INT8_C(   3),  INT8_C(  92),  INT8_C(   0),  INT8_C(   0) },
      {    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX } },
    { { -INT8_C(  26), -INT8_C(   5),  INT8_C(   0), -INT8_C(  50),  INT8_C( 126),  INT8_C(  71),  INT8_C(   0), -INT8_C(  78),
         INT8_C(  39), -INT8_C( 114), -INT8_C(  59),  INT8_C(  36), -INT8_C(  22), -INT8_C( 112), -INT8_C( 109),  INT8_C(   0) },
      { UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),
           UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX } },
    { {  INT8_C(   0), -INT8_C(  75), -INT8_C(  92), -INT8_C(  20), -INT8_C(   4),      INT8_MAX,  INT8_C(   0),  INT8_C(  36),
         INT8_C(  13),  INT8_C(  99),  INT8_C(   0),  INT8_C(   0), -INT8_C(  13),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0) },
      {    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16_t a = simde_vld1q_s8(test_vec[i].a);
    simde_uint8x16_t r = simde_vcgezq_s8(a);

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

    simde_uint8x16_t r = simde_vcgezq_s8(a);

    simde_test_arm_neon_write_i8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcgezq_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[8];
    uint16_t r[8];
  } test_vec[] = {
    { { -INT16_C( 15226),  INT16_C(     0), -INT16_C(  1431),  INT16_C(     0),  INT16_C(  6849),  INT16_C(     0), -INT16_C(  8036), -INT16_C( 15990) },
      { UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0) } },
    { {  INT16_C(     0),  INT16_C(  1445),  INT16_C(     0),  INT16_C(     0), -INT16_C(  3775), -INT16_C( 21848),  INT16_C( 14315), -INT16_C( 21071) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0) } },
    { {  INT16_C(   892), -INT16_C( 26999), -INT16_C( 21484),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C( 12800) },
      {      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX } },
    { { -INT16_C( 19489),  INT16_C(  4382), -INT16_C( 13092),  INT16_C(     0),  INT16_C( 29391), -INT16_C(  7185),  INT16_C(     0),  INT16_C(     0) },
      { UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX } },
    { {  INT16_C( 12686),  INT16_C( 28368), -INT16_C(  6977),  INT16_C(     0),  INT16_C(     0),  INT16_C( 29616),  INT16_C(     0),  INT16_C( 22732) },
      {      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX } },
    { {  INT16_C(     0),  INT16_C( 11980),  INT16_C(     0), -INT16_C( 21865),  INT16_C( 26450),  INT16_C(  4376), -INT16_C( 18613), -INT16_C(  7504) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0) } },
    { {  INT16_C(     0),  INT16_C( 22064), -INT16_C( 32658),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C( 16253) },
      {      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX } },
    { {  INT16_C( 23905),  INT16_C( 23484),  INT16_C(     0),  INT16_C( 23649), -INT16_C( 27998),  INT16_C(  4275), -INT16_C( 19694),  INT16_C(     0) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_uint16x8_t r = simde_vcgezq_s16(a);

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

    simde_uint16x8_t r = simde_vcgezq_s16(a);

    simde_test_arm_neon_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcgezq_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[4];
    uint32_t r[4];
  } test_vec[] = {
    { {  INT32_C(           0),  INT32_C(  1643825484),  INT32_C(   612391850),  INT32_C(           0) },
      {           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX } },
    { {  INT32_C(           0),  INT32_C(  1593239142),  INT32_C(  2135441628), -INT32_C(  1324263067) },
      {           UINT32_MAX,           UINT32_MAX,           UINT32_MAX, UINT32_C(         0) } },
    { {  INT32_C(  1676776038),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) },
      {           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX } },
    { { -INT32_C(  1927125720), -INT32_C(   532794434), -INT32_C(  1532145602), -INT32_C(  2146984222) },
      { UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0) } },
    { {  INT32_C(  1817723155), -INT32_C(   399816415),  INT32_C(  1502300209),  INT32_C(           0) },
      {           UINT32_MAX, UINT32_C(         0),           UINT32_MAX,           UINT32_MAX } },
    { {  INT32_C(           0),  INT32_C(    81185431), -INT32_C(  1086427221),  INT32_C(           0) },
      {           UINT32_MAX,           UINT32_MAX, UINT32_C(         0),           UINT32_MAX } },
    { {  INT32_C(  1298875807),  INT32_C(           0), -INT32_C(   353237898),  INT32_C(           0) },
      {           UINT32_MAX,           UINT32_MAX, UINT32_C(         0),           UINT32_MAX } },
    { {  INT32_C(   921360262),  INT32_C(  1292375405),  INT32_C(   207602284), -INT32_C(    94778873) },
      {           UINT32_MAX,           UINT32_MAX,           UINT32_MAX, UINT32_C(         0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_uint32x4_t r = simde_vcgezq_s32(a);

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

    simde_uint32x4_t r = simde_vcgezq_s32(a);

    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcgezq_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a[2];
    uint64_t r[2];
  } test_vec[] = {
    { {  INT64_C(                   0),  INT64_C(                   0) },
      {                    UINT64_MAX,                    UINT64_MAX } },
    { { -INT64_C( 6109154277218944666), -INT64_C( 7057256154138836602) },
      { UINT64_C(                   0), UINT64_C(                   0) } },
    { {  INT64_C( 5359920317727548829),  INT64_C( 5134123335401800481) },
      {                    UINT64_MAX,                    UINT64_MAX } },
    { {  INT64_C( 3092872602263862579), -INT64_C( 2393269223996982099) },
      {                    UINT64_MAX, UINT64_C(                   0) } },
    { {  INT64_C(                   0), -INT64_C( 7911487429770654735) },
      {                    UINT64_MAX, UINT64_C(                   0) } },
    { { -INT64_C( 5369868132634761559),  INT64_C( 7133338072004117451) },
      { UINT64_C(                   0),                    UINT64_MAX } },
    { {  INT64_C( 7397759754347610690), -INT64_C( 1242815026868658465) },
      {                    UINT64_MAX, UINT64_C(                   0) } },
    { {  INT64_C(                   0), -INT64_C( 5757137311778680288) },
      {                    UINT64_MAX, UINT64_C(                   0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);
    simde_uint64x2_t r = simde_vcgezq_s64(a);

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

    simde_uint64x2_t r = simde_vcgezq_s64(a);

    simde_test_arm_neon_write_i64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcgezd_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64_t a;
    uint64_t r;
  } test_vec[] = {
    { SIMDE_FLOAT64_C(   126.90),
                          UINT64_MAX },
    { SIMDE_FLOAT64_C(  -382.51),
      UINT64_C(                   0) },
    { SIMDE_FLOAT64_C(   304.15),
                          UINT64_MAX },
    { SIMDE_FLOAT64_C(  -202.88),
      UINT64_C(                   0) },
    { SIMDE_FLOAT64_C(   860.05),
                          UINT64_MAX },
    { SIMDE_FLOAT64_C(   642.60),
                          UINT64_MAX },
    { SIMDE_FLOAT64_C(   832.24),
                          UINT64_MAX },
    { SIMDE_FLOAT64_C(   684.01),
                          UINT64_MAX }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint64_t r = simde_vcgezd_f64(test_vec[i].a);
    simde_assert_equal_u64(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64_t a = simde_test_codegen_random_f64(-1000, 1000);
    uint64_t r = simde_vcgezd_f64(a);

    simde_test_codegen_write_f64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcgezd_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a;
    uint64_t r;
  } test_vec[] = {
    { -INT64_C(  602441637630545910),
      UINT64_C(                   0) },
    {  INT64_C(  353414294715869654),
                          UINT64_MAX },
    { -INT64_C( 8415886167722681144),
      UINT64_C(                   0) },
    {  INT64_C( 2974326418029801381),
                          UINT64_MAX },
    { -INT64_C( 1163464610407750050),
      UINT64_C(                   0) },
    {  INT64_C( 5522976118827053108),
                          UINT64_MAX },
    { -INT64_C( 3219186226763175511),
      UINT64_C(                   0) },
    {  INT64_C( 6367652242596236310),
                          UINT64_MAX }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint64_t r = simde_vcgezd_s64(test_vec[i].a);
    simde_assert_equal_u64(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    int64_t a = simde_test_codegen_random_i64();
    uint64_t r = simde_vcgezd_s64(a);

    simde_test_codegen_write_i64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcgezs_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32_t a;
    uint32_t r;
  } test_vec[] = {
    { SIMDE_FLOAT32_C(   176.04),
                UINT32_MAX },
    { SIMDE_FLOAT32_C(  -536.84),
      UINT32_C(         0) },
    { SIMDE_FLOAT32_C(  -169.81),
      UINT32_C(         0) },
    { SIMDE_FLOAT32_C(   537.49),
                UINT32_MAX },
    { SIMDE_FLOAT32_C(  -441.18),
      UINT32_C(         0) },
    { SIMDE_FLOAT32_C(  -995.79),
      UINT32_C(         0) },
    { SIMDE_FLOAT32_C(  -666.46),
      UINT32_C(         0) },
    { SIMDE_FLOAT32_C(   219.53),
                UINT32_MAX }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint32_t r = simde_vcgezs_f32(test_vec[i].a);
    simde_assert_equal_u32(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32_t a = simde_test_codegen_random_f32(-1000, 1000);
    uint32_t r = simde_vcgezs_f32(a);

    simde_test_codegen_write_f32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vcgez_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcgez_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vcgez_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vcgez_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcgez_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcgez_s64)

SIMDE_TEST_FUNC_LIST_ENTRY(vcgezq_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcgezq_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vcgezq_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vcgezq_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcgezq_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcgezq_s64)

SIMDE_TEST_FUNC_LIST_ENTRY(vcgezd_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vcgezd_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vcgezs_f32)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
