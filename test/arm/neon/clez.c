#define SIMDE_TEST_ARM_NEON_INSN clez

#include "test-neon.h"

/* Check that both of these work */
#if defined(__cplusplus)
  #include "../../../simde/arm/neon/clez.h"
#else
  #include "../../../simde/arm/neon.h"
#endif

static int
test_simde_vclez_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a[2];
    uint32_t r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(    70.04), SIMDE_FLOAT32_C(  -657.90) },
      { UINT32_C(         0),           UINT32_MAX } },
    { { SIMDE_FLOAT32_C(  -994.42), SIMDE_FLOAT32_C(  -790.82) },
      {           UINT32_MAX,           UINT32_MAX } },
    { { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) },
      {           UINT32_MAX,           UINT32_MAX } },
    { { SIMDE_FLOAT32_C(  -581.92), SIMDE_FLOAT32_C(     0.00) },
      {           UINT32_MAX,           UINT32_MAX } },
    { { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) },
      {           UINT32_MAX,           UINT32_MAX } },
    { { SIMDE_FLOAT32_C(   327.30), SIMDE_FLOAT32_C(  -480.97) },
      { UINT32_C(         0),           UINT32_MAX } },
    { { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   126.99) },
      {           UINT32_MAX, UINT32_C(         0) } },
    { { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -661.81) },
      {           UINT32_MAX,           UINT32_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t a = simde_vld1_f32(test_vec[i].a);
    simde_uint32x2_t r = simde_vclez_f32(a);

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

    simde_uint32x2_t r = simde_vclez_f32(a);

    simde_test_arm_neon_write_f32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vclez_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 a[1];
    uint64_t r[1];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(  -670.22) },
      {                    UINT64_MAX } },
    { { SIMDE_FLOAT64_C(     0.00) },
      {                    UINT64_MAX } },
    { { SIMDE_FLOAT64_C(   680.93) },
      { UINT64_C(                   0) } },
    { { SIMDE_FLOAT64_C(   487.28) },
      { UINT64_C(                   0) } },
    { { SIMDE_FLOAT64_C(  -782.87) },
      {                    UINT64_MAX } },
    { { SIMDE_FLOAT64_C(     0.00) },
      {                    UINT64_MAX } },
    { { SIMDE_FLOAT64_C(   891.09) },
      { UINT64_C(                   0) } },
    { { SIMDE_FLOAT64_C(  -949.37) },
      {                    UINT64_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x1_t a = simde_vld1_f64(test_vec[i].a);
    simde_uint64x1_t r = simde_vclez_f64(a);

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

    simde_uint64x1_t r = simde_vclez_f64(a);

    simde_test_arm_neon_write_f64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vclez_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[8];
    uint8_t r[8];
  } test_vec[] = {
    { { -INT8_C( 120), -INT8_C( 118),  INT8_C(   0), -INT8_C( 103),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  81) },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0) } },
    { {  INT8_C(   0), -INT8_C( 109),  INT8_C(   0),  INT8_C(   1), -INT8_C(  61),  INT8_C(   0), -INT8_C(  50),  INT8_C(   0) },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX } },
    { {  INT8_C(   0), -INT8_C( 107), -INT8_C(  99),  INT8_C(   0), -INT8_C(  65), -INT8_C( 127),  INT8_C(  77), -INT8_C(  91) },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX } },
    { {  INT8_C(  32), -INT8_C(  41), -INT8_C(  90),  INT8_C(   0),  INT8_C(  64),  INT8_C(   0),  INT8_C( 107),  INT8_C(   0) },
      { UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX } },
    { {  INT8_C( 117),  INT8_C(   0),      INT8_MIN,  INT8_C(  53),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0) },
      { UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX } },
    { {  INT8_C(  76), -INT8_C(  31),  INT8_C(  28), -INT8_C( 116),  INT8_C(  86), -INT8_C( 121), -INT8_C(   6),  INT8_C(   0) },
      { UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX } },
    { {  INT8_C(  94),  INT8_C(   0), -INT8_C( 116),  INT8_C(   0),  INT8_C(   0),  INT8_C( 102),  INT8_C(   0),  INT8_C( 109) },
      { UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0) } },
    { {  INT8_C(   0),  INT8_C(  92),  INT8_C(   0),  INT8_C( 119), -INT8_C(  29),  INT8_C(  86),  INT8_C(   0),  INT8_C(  83) },
      {    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8_t a = simde_vld1_s8(test_vec[i].a);
    simde_uint8x8_t r = simde_vclez_s8(a);

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

    simde_uint8x8_t r = simde_vclez_s8(a);

    simde_test_arm_neon_write_i8x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vclez_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[4];
    uint16_t r[4];
  } test_vec[] = {
    { { -INT16_C( 19507), -INT16_C( 22607),  INT16_C(     0), -INT16_C( 18447) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX } },
    { {  INT16_C( 27590),  INT16_C(  6171),  INT16_C(   105),  INT16_C(     0) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX } },
    { { -INT16_C( 14201), -INT16_C( 23807), -INT16_C( 18034),  INT16_C(     0) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX } },
    { { -INT16_C(  2888), -INT16_C( 29360), -INT16_C( 26029),  INT16_C(  6831) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0) } },
    { {  INT16_C(  3019), -INT16_C( 15175),  INT16_C( 11615),  INT16_C(     0) },
      { UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX } },
    { {  INT16_C(     0),  INT16_C(     0), -INT16_C(  7376), -INT16_C(  6111) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX } },
    { {  INT16_C(  9483),  INT16_C(     0),  INT16_C( 30448),  INT16_C(     0) },
      { UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX } },
    { { -INT16_C(  8346),  INT16_C( 23751),  INT16_C( 20544),  INT16_C(     0) },
      {      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t a = simde_vld1_s16(test_vec[i].a);
    simde_uint16x4_t r = simde_vclez_s16(a);

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

    simde_uint16x4_t r = simde_vclez_s16(a);

    simde_test_arm_neon_write_i16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vclez_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[2];
    uint32_t r[2];
  } test_vec[] = {
    { { -INT32_C(  1560005487),  INT32_C(           0) },
      {           UINT32_MAX,           UINT32_MAX } },
    { {  INT32_C(           0),  INT32_C(           0) },
      {           UINT32_MAX,           UINT32_MAX } },
    { {  INT32_C(  1211310087), -INT32_C(  2032582295) },
      { UINT32_C(         0),           UINT32_MAX } },
    { {  INT32_C(           0), -INT32_C(  2036276554) },
      {           UINT32_MAX,           UINT32_MAX } },
    { {  INT32_C(           0),  INT32_C(           0) },
      {           UINT32_MAX,           UINT32_MAX } },
    { { -INT32_C(  1144024440), -INT32_C(  1258538534) },
      {           UINT32_MAX,           UINT32_MAX } },
    { { -INT32_C(   795864664),  INT32_C(   112346726) },
      {           UINT32_MAX, UINT32_C(         0) } },
    { {  INT32_C(  1496076036), -INT32_C(  1751501023) },
      { UINT32_C(         0),           UINT32_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t a = simde_vld1_s32(test_vec[i].a);
    simde_uint32x2_t r = simde_vclez_s32(a);

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

    simde_uint32x2_t r = simde_vclez_s32(a);

    simde_test_arm_neon_write_i32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vclez_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a[1];
    uint64_t r[1];
  } test_vec[] = {
    { { -INT64_C( 1608322800724244625) },
      {                    UINT64_MAX } },
    { {  INT64_C( 3916001074733946563) },
      { UINT64_C(                   0) } },
    { {  INT64_C(                   0) },
      {                    UINT64_MAX } },
    { {  INT64_C(                   0) },
      {                    UINT64_MAX } },
    { {  INT64_C( 8851094662317928534) },
      { UINT64_C(                   0) } },
    { {  INT64_C( 5705103693734990403) },
      { UINT64_C(                   0) } },
    { {  INT64_C( 1524843960183154149) },
      { UINT64_C(                   0) } },
    { { -INT64_C( 1091930860044790496) },
      {                    UINT64_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x1_t a = simde_vld1_s64(test_vec[i].a);
    simde_uint64x1_t r = simde_vclez_s64(a);

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

    simde_uint64x1_t r = simde_vclez_s64(a);

    simde_test_arm_neon_write_i64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vclezq_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a[4];
    uint32_t r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   221.89), SIMDE_FLOAT32_C(   155.65), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   633.13) },
      { UINT32_C(         0), UINT32_C(         0),           UINT32_MAX, UINT32_C(         0) } },
    { { SIMDE_FLOAT32_C(   746.23), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) },
      { UINT32_C(         0),           UINT32_MAX,           UINT32_MAX,           UINT32_MAX } },
    { { SIMDE_FLOAT32_C(  -515.28), SIMDE_FLOAT32_C(   795.42), SIMDE_FLOAT32_C(    99.50), SIMDE_FLOAT32_C(   505.39) },
      {           UINT32_MAX, UINT32_C(         0), UINT32_C(         0), UINT32_C(         0) } },
    { { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -866.96), SIMDE_FLOAT32_C(  -299.73), SIMDE_FLOAT32_C(   234.99) },
      {           UINT32_MAX,           UINT32_MAX,           UINT32_MAX, UINT32_C(         0) } },
    { { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -414.75), SIMDE_FLOAT32_C(   514.89), SIMDE_FLOAT32_C(     0.00) },
      {           UINT32_MAX,           UINT32_MAX, UINT32_C(         0),           UINT32_MAX } },
    { { SIMDE_FLOAT32_C(   730.51), SIMDE_FLOAT32_C(   656.06), SIMDE_FLOAT32_C(   193.33), SIMDE_FLOAT32_C(     0.00) },
      { UINT32_C(         0), UINT32_C(         0), UINT32_C(         0),           UINT32_MAX } },
    { { SIMDE_FLOAT32_C(   486.26), SIMDE_FLOAT32_C(   910.33), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   406.26) },
      { UINT32_C(         0), UINT32_C(         0),           UINT32_MAX, UINT32_C(         0) } },
    { { SIMDE_FLOAT32_C(   440.42), SIMDE_FLOAT32_C(   247.26), SIMDE_FLOAT32_C(   185.90), SIMDE_FLOAT32_C(  -899.71) },
      { UINT32_C(         0), UINT32_C(         0), UINT32_C(         0),           UINT32_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_uint32x4_t r = simde_vclezq_f32(a);

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

    simde_uint32x4_t r = simde_vclezq_f32(a);

    simde_test_arm_neon_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vclezq_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 a[2];
    uint64_t r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(  -407.08), SIMDE_FLOAT64_C(     0.00) },
      {                    UINT64_MAX,                    UINT64_MAX } },
    { { SIMDE_FLOAT64_C(   119.73), SIMDE_FLOAT64_C(    73.59) },
      { UINT64_C(                   0), UINT64_C(                   0) } },
    { { SIMDE_FLOAT64_C(   337.70), SIMDE_FLOAT64_C(     0.00) },
      { UINT64_C(                   0),                    UINT64_MAX } },
    { { SIMDE_FLOAT64_C(   629.77), SIMDE_FLOAT64_C(     0.00) },
      { UINT64_C(                   0),                    UINT64_MAX } },
    { { SIMDE_FLOAT64_C(   105.66), SIMDE_FLOAT64_C(  -580.38) },
      { UINT64_C(                   0),                    UINT64_MAX } },
    { { SIMDE_FLOAT64_C(   -14.53), SIMDE_FLOAT64_C(   483.80) },
      {                    UINT64_MAX, UINT64_C(                   0) } },
    { { SIMDE_FLOAT64_C(   424.55), SIMDE_FLOAT64_C(   -35.62) },
      { UINT64_C(                   0),                    UINT64_MAX } },
    { { SIMDE_FLOAT64_C(   -74.95), SIMDE_FLOAT64_C(   -62.26) },
      {                    UINT64_MAX,                    UINT64_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2_t a = simde_vld1q_f64(test_vec[i].a);
    simde_uint64x2_t r = simde_vclezq_f64(a);

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

    simde_uint64x2_t r = simde_vclezq_f64(a);

    simde_test_arm_neon_write_f64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vclezq_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[16];
    uint8_t r[16];
  } test_vec[] = {
    { {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  29), -INT8_C(  99), -INT8_C(  82), -INT8_C(  65),  INT8_C(   0),
         INT8_C(   0), -INT8_C( 122),  INT8_C(  15), -INT8_C(  10),  INT8_C(   3),  INT8_C(   0),  INT8_C(   0), -INT8_C(  56) },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX } },
    { { -INT8_C( 124), -INT8_C(  70), -INT8_C(   3),  INT8_C(  34),  INT8_C(   0),  INT8_C(   0), -INT8_C( 116),  INT8_C(   0),
         INT8_C(  67), -INT8_C( 101),  INT8_C( 102),  INT8_C(  70), -INT8_C( 115),  INT8_C(   0),  INT8_C(  14), -INT8_C(  54) },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
        UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX } },
    { {  INT8_C( 112),  INT8_C(   0),  INT8_C(  49),  INT8_C(   0),  INT8_C(   0), -INT8_C(  67),  INT8_C(   0),  INT8_C(  99),
         INT8_C(  88),  INT8_C(   0), -INT8_C(  86), -INT8_C(  26),  INT8_C( 114),  INT8_C(   0), -INT8_C(  80),  INT8_C(   0) },
      { UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),
        UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX } },
    { {  INT8_C(   0),  INT8_C(  89),  INT8_C(  95), -INT8_C(   3),  INT8_C(   0), -INT8_C(  89),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0),  INT8_C(  10),  INT8_C(  85), -INT8_C(  55), -INT8_C(  61),  INT8_C(   0),  INT8_C(  56),  INT8_C(  75) },
      {    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0) } },
    { {  INT8_C(   0),  INT8_C(  47),      INT8_MIN, -INT8_C(  52),  INT8_C(   0), -INT8_C(  32),  INT8_C(  59),  INT8_C(   0),
        -INT8_C(  21), -INT8_C( 112), -INT8_C(  10), -INT8_C(  82), -INT8_C( 107),  INT8_C(  46),  INT8_C(   0), -INT8_C(  37) },
      {    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX } },
    { {  INT8_C(  40),  INT8_C(  22),  INT8_C(  96), -INT8_C(   2), -INT8_C(  10), -INT8_C( 101),  INT8_C(   0),  INT8_C(   0),
         INT8_C(  44),  INT8_C(  33), -INT8_C( 113),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  99), -INT8_C(   9) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
        UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX } },
    { {  INT8_C(   0), -INT8_C(  56),  INT8_C(  53),  INT8_C(  42),  INT8_C(   0),  INT8_C(  96),  INT8_C(   0), -INT8_C( 112),
        -INT8_C( 126), -INT8_C( 101),  INT8_C(  81), -INT8_C(  46),  INT8_C(  36), -INT8_C(  18), -INT8_C(  55), -INT8_C( 123) },
      {    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX } },
    { {  INT8_C( 102),  INT8_C(  14),  INT8_C(  51), -INT8_C(  54),  INT8_C(   0),  INT8_C(  63),  INT8_C(   0), -INT8_C(  16),
        -INT8_C(  38), -INT8_C(  84), -INT8_C(  62), -INT8_C(   2),  INT8_C(   0),  INT8_C(   0), -INT8_C( 125),  INT8_C(  79) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16_t a = simde_vld1q_s8(test_vec[i].a);
    simde_uint8x16_t r = simde_vclezq_s8(a);

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

    simde_uint8x16_t r = simde_vclezq_s8(a);

    simde_test_arm_neon_write_i8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vclezq_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[8];
    uint16_t r[8];
  } test_vec[] = {
    { {  INT16_C(  1992), -INT16_C( 10455),  INT16_C( 15346),  INT16_C(  5013), -INT16_C( 17142), -INT16_C( 32561),  INT16_C( 21763),  INT16_C(  9992) },
      { UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0) } },
    { {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C( 12143), -INT16_C( 17788),  INT16_C( 30631),  INT16_C(     0),  INT16_C(   138) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0) } },
    { { -INT16_C( 29080),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C( 12857),  INT16_C(     0) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX } },
    { { -INT16_C(   346),  INT16_C(     0), -INT16_C(  7546), -INT16_C(  4393), -INT16_C(  7824), -INT16_C( 32420), -INT16_C( 22024),  INT16_C(  1181) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0) } },
    { { -INT16_C( 13690),  INT16_C( 20138),  INT16_C( 10263), -INT16_C( 16881),  INT16_C(     0), -INT16_C( 21485),  INT16_C(     0),  INT16_C(  8091) },
      {      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0) } },
    { { -INT16_C(  7914), -INT16_C( 17584),  INT16_C( 22748),  INT16_C( 25576), -INT16_C( 27870),  INT16_C( 15025),  INT16_C(     0),  INT16_C(     0) },
      {      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX } },
    { {  INT16_C(     0), -INT16_C( 15994),  INT16_C( 20281),  INT16_C( 20310),  INT16_C(     0),  INT16_C(  3082), -INT16_C(  3074),  INT16_C(  8559) },
      {      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0) } },
    { { -INT16_C( 20642),  INT16_C(     0),  INT16_C(  1240), -INT16_C(  2027), -INT16_C( 25856),  INT16_C( 14777),  INT16_C(     0),  INT16_C(  6792) },
      {      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_uint16x8_t r = simde_vclezq_s16(a);

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

    simde_uint16x8_t r = simde_vclezq_s16(a);

    simde_test_arm_neon_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vclezq_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[4];
    uint32_t r[4];
  } test_vec[] = {
    { { -INT32_C(   860221835),  INT32_C(  2143068941),  INT32_C(           0),  INT32_C(           0) },
      {           UINT32_MAX, UINT32_C(         0),           UINT32_MAX,           UINT32_MAX } },
    { {  INT32_C(   210922921),  INT32_C(           0), -INT32_C(  1389508553), -INT32_C(   478550058) },
      { UINT32_C(         0),           UINT32_MAX,           UINT32_MAX,           UINT32_MAX } },
    { {  INT32_C(           0),  INT32_C(  2045744066),  INT32_C(           0),  INT32_C(           0) },
      {           UINT32_MAX, UINT32_C(         0),           UINT32_MAX,           UINT32_MAX } },
    { {  INT32_C(   891287902),  INT32_C(  1796774112),  INT32_C(           0),  INT32_C(  1045017212) },
      { UINT32_C(         0), UINT32_C(         0),           UINT32_MAX, UINT32_C(         0) } },
    { { -INT32_C(   521356587), -INT32_C(  1985142705),  INT32_C(   368802230),  INT32_C(           0) },
      {           UINT32_MAX,           UINT32_MAX, UINT32_C(         0),           UINT32_MAX } },
    { {  INT32_C(           0), -INT32_C(   526840677),  INT32_C(   446976325),  INT32_C(  1526370315) },
      {           UINT32_MAX,           UINT32_MAX, UINT32_C(         0), UINT32_C(         0) } },
    { {  INT32_C(           0), -INT32_C(  1394227462),  INT32_C(   103588648),  INT32_C(   677506957) },
      {           UINT32_MAX,           UINT32_MAX, UINT32_C(         0), UINT32_C(         0) } },
    { {  INT32_C(           0), -INT32_C(   290367938),  INT32_C(           0),  INT32_C(           0) },
      {           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_uint32x4_t r = simde_vclezq_s32(a);

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

    simde_uint32x4_t r = simde_vclezq_s32(a);

    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vclezq_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a[2];
    uint64_t r[2];
  } test_vec[] = {
    { {  INT64_C( 3936110928391657468),  INT64_C( 3422569291316624941) },
      { UINT64_C(                   0), UINT64_C(                   0) } },
    { {  INT64_C(                   0),  INT64_C( 7752757755250222179) },
      {                    UINT64_MAX, UINT64_C(                   0) } },
    { {  INT64_C(  613874270280738635), -INT64_C( 5059614506910022572) },
      { UINT64_C(                   0),                    UINT64_MAX } },
    { { -INT64_C( 1735777232729757626), -INT64_C(  807660422876200805) },
      {                    UINT64_MAX,                    UINT64_MAX } },
    { {  INT64_C(                   0), -INT64_C( 2781527010755628526) },
      {                    UINT64_MAX,                    UINT64_MAX } },
    { {  INT64_C(                   0),  INT64_C(                   0) },
      {                    UINT64_MAX,                    UINT64_MAX } },
    { { -INT64_C( 4031249581053433282), -INT64_C( 4363211058523835097) },
      {                    UINT64_MAX,                    UINT64_MAX } },
    { {  INT64_C(                   0),  INT64_C(                   0) },
      {                    UINT64_MAX,                    UINT64_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);
    simde_uint64x2_t r = simde_vclezq_s64(a);

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

    simde_uint64x2_t r = simde_vclezq_s64(a);

    simde_test_arm_neon_write_i64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vclezd_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a;
    uint64_t r;
  } test_vec[] = {
    { -INT64_C( 6372801726486154762),
                         UINT64_MAX },
   {  INT64_C( 2498958616137907508),
     UINT64_C(                   0) },
   {  INT64_C( 1572062256963230121),
     UINT64_C(                   0) },
   {  INT64_C(  120974916005461340),
     UINT64_C(                   0) },
   { -INT64_C( 1154129063315081028),
                         UINT64_MAX },
   {  INT64_C(  555258176266455539),
     UINT64_C(                   0) },
   {  INT64_C( 4442239051251043142),
     UINT64_C(                   0) },
   {  INT64_C( 7568995907833488381),
     UINT64_C(                   0) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint64_t r = simde_vclezd_s64(test_vec[i].a);
    simde_assert_equal_u64(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    int64_t a = simde_test_codegen_random_i64();
    uint64_t r = simde_vclezd_s64(a);

    simde_test_codegen_write_i64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vclezd_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64_t a;
    uint64_t r;
  } test_vec[] = {
    { SIMDE_FLOAT64_C(  -339.74),
                         UINT64_MAX },
   { SIMDE_FLOAT64_C(   -68.07),
                         UINT64_MAX },
   { SIMDE_FLOAT64_C(  -628.28),
                         UINT64_MAX },
   { SIMDE_FLOAT64_C(   764.54),
     UINT64_C(                   0) },
   { SIMDE_FLOAT64_C(   552.63),
     UINT64_C(                   0) },
   { SIMDE_FLOAT64_C(  -265.81),
                         UINT64_MAX },
   { SIMDE_FLOAT64_C(  -985.62),
                         UINT64_MAX },
   { SIMDE_FLOAT64_C(    59.35),
     UINT64_C(                   0) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint64_t r = simde_vclezd_f64(test_vec[i].a);
    simde_assert_equal_u64(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64_t a = simde_test_codegen_random_f64(-1000, 1000);
    uint64_t r = simde_vclezd_f64(a);

    simde_test_codegen_write_f64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vclezs_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32_t a;
    uint32_t r;
  } test_vec[] = {
    { SIMDE_FLOAT32_C(   683.74),
     UINT32_C(         0) },
   { SIMDE_FLOAT32_C(  -775.03),
               UINT32_MAX },
   { SIMDE_FLOAT32_C(   360.39),
     UINT32_C(         0) },
   { SIMDE_FLOAT32_C(   691.68),
     UINT32_C(         0) },
   { SIMDE_FLOAT32_C(   549.89),
     UINT32_C(         0) },
   { SIMDE_FLOAT32_C(  -850.76),
               UINT32_MAX },
   { SIMDE_FLOAT32_C(   828.85),
     UINT32_C(         0) },
   { SIMDE_FLOAT32_C(   571.99),
     UINT32_C(         0) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint32_t r = simde_vclezs_f32(test_vec[i].a);
    simde_assert_equal_u32(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32_t a = simde_test_codegen_random_f32(-1000, 1000);
    uint32_t r = simde_vclezs_f32(a);

    simde_test_codegen_write_f32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vclez_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vclez_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vclez_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vclez_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vclez_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vclez_s64)

SIMDE_TEST_FUNC_LIST_ENTRY(vclezq_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vclezq_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vclezq_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vclezq_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vclezq_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vclezq_s64)

SIMDE_TEST_FUNC_LIST_ENTRY(vclezd_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vclezd_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vclezs_f32)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
