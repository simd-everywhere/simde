#define SIMDE_TEST_ARM_NEON_INSN ld1_dup

#include "test-neon.h"
#include "../../../simde/arm/neon/ld1_dup.h"

#if !defined(SIMDE_BUG_INTEL_857088)

static int
test_simde_vld1q_dup_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    float a;
    float unused;
    float r[16];
  } test_vec[] = {
    { SIMDE_FLOAT32_C(  -275.48),
      SIMDE_FLOAT32_C(   563.30),
      { SIMDE_FLOAT32_C(  -275.48), SIMDE_FLOAT32_C(  -275.48), SIMDE_FLOAT32_C(  -275.48), SIMDE_FLOAT32_C(  -275.48) } },
    { SIMDE_FLOAT32_C(  -478.65),
      SIMDE_FLOAT32_C(   688.84),
      { SIMDE_FLOAT32_C(  -478.65), SIMDE_FLOAT32_C(  -478.65), SIMDE_FLOAT32_C(  -478.65), SIMDE_FLOAT32_C(  -478.65) } },
    { SIMDE_FLOAT32_C(   810.78),
      SIMDE_FLOAT32_C(  -456.08),
      { SIMDE_FLOAT32_C(   810.78), SIMDE_FLOAT32_C(   810.78), SIMDE_FLOAT32_C(   810.78), SIMDE_FLOAT32_C(   810.78) } },
    { SIMDE_FLOAT32_C(  -139.83),
      SIMDE_FLOAT32_C(  -302.96),
      { SIMDE_FLOAT32_C(  -139.83), SIMDE_FLOAT32_C(  -139.83), SIMDE_FLOAT32_C(  -139.83), SIMDE_FLOAT32_C(  -139.83) } },
    { SIMDE_FLOAT32_C(    16.91),
      SIMDE_FLOAT32_C(  -128.20),
      { SIMDE_FLOAT32_C(    16.91), SIMDE_FLOAT32_C(    16.91), SIMDE_FLOAT32_C(    16.91), SIMDE_FLOAT32_C(    16.91) } },
    { SIMDE_FLOAT32_C(   315.19),
      SIMDE_FLOAT32_C(  -659.25),
      { SIMDE_FLOAT32_C(   315.19), SIMDE_FLOAT32_C(   315.19), SIMDE_FLOAT32_C(   315.19), SIMDE_FLOAT32_C(   315.19) } },
    { SIMDE_FLOAT32_C(  -303.00),
      SIMDE_FLOAT32_C(  -865.13),
      { SIMDE_FLOAT32_C(  -303.00), SIMDE_FLOAT32_C(  -303.00), SIMDE_FLOAT32_C(  -303.00), SIMDE_FLOAT32_C(  -303.00) } },
    { SIMDE_FLOAT32_C(   391.93),
      SIMDE_FLOAT32_C(  -958.40),
      { SIMDE_FLOAT32_C(   391.93), SIMDE_FLOAT32_C(   391.93), SIMDE_FLOAT32_C(   391.93), SIMDE_FLOAT32_C(   391.93) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t r = simde_vld1q_dup_f32(&test_vec[i].a);

    simde_test_arm_neon_assert_equal_f32x4(r, simde_vld1q_f32(test_vec[i].r),
                                           INT_MAX);
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32 a = simde_test_codegen_random_f32(-1000.0f, 1000.0f);
    simde_float32x4_t r = simde_vld1q_dup_f32(&a);
    // Random buffer between pointer to load and expected results to check for
    // loading out of bounds.
    simde_float32 unused = simde_test_codegen_random_f32(-1000.0f, 1000.0f);

    simde_test_codegen_write_f32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_f32(2, unused, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld1q_dup_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a;
    int8_t unused;
    int8_t r[16];
  } test_vec[] = {
    { -INT8_C(   6),
      -INT8_C(  98),
      { -INT8_C(   6), -INT8_C(   6), -INT8_C(   6), -INT8_C(   6), -INT8_C(   6), -INT8_C(   6), -INT8_C(   6), -INT8_C(   6),
        -INT8_C(   6), -INT8_C(   6), -INT8_C(   6), -INT8_C(   6), -INT8_C(   6), -INT8_C(   6), -INT8_C(   6), -INT8_C(   6) } },
    {  INT8_C(  10),
      -INT8_C(  19),
      {  INT8_C(  10),  INT8_C(  10),  INT8_C(  10),  INT8_C(  10),  INT8_C(  10),  INT8_C(  10),  INT8_C(  10),  INT8_C(  10),
         INT8_C(  10),  INT8_C(  10),  INT8_C(  10),  INT8_C(  10),  INT8_C(  10),  INT8_C(  10),  INT8_C(  10),  INT8_C(  10) } },
    {  INT8_C(  51),
      -INT8_C(  99),
      {  INT8_C(  51),  INT8_C(  51),  INT8_C(  51),  INT8_C(  51),  INT8_C(  51),  INT8_C(  51),  INT8_C(  51),  INT8_C(  51),
         INT8_C(  51),  INT8_C(  51),  INT8_C(  51),  INT8_C(  51),  INT8_C(  51),  INT8_C(  51),  INT8_C(  51),  INT8_C(  51) } },
    { -INT8_C(  62),
       INT8_C(  75),
      { -INT8_C(  62), -INT8_C(  62), -INT8_C(  62), -INT8_C(  62), -INT8_C(  62), -INT8_C(  62), -INT8_C(  62), -INT8_C(  62),
        -INT8_C(  62), -INT8_C(  62), -INT8_C(  62), -INT8_C(  62), -INT8_C(  62), -INT8_C(  62), -INT8_C(  62), -INT8_C(  62) } },
    { -INT8_C(  38),
      -INT8_C( 112),
      { -INT8_C(  38), -INT8_C(  38), -INT8_C(  38), -INT8_C(  38), -INT8_C(  38), -INT8_C(  38), -INT8_C(  38), -INT8_C(  38),
        -INT8_C(  38), -INT8_C(  38), -INT8_C(  38), -INT8_C(  38), -INT8_C(  38), -INT8_C(  38), -INT8_C(  38), -INT8_C(  38) } },
    { -INT8_C(  94),
      -INT8_C(  52),
      { -INT8_C(  94), -INT8_C(  94), -INT8_C(  94), -INT8_C(  94), -INT8_C(  94), -INT8_C(  94), -INT8_C(  94), -INT8_C(  94),
        -INT8_C(  94), -INT8_C(  94), -INT8_C(  94), -INT8_C(  94), -INT8_C(  94), -INT8_C(  94), -INT8_C(  94), -INT8_C(  94) } },
    { -INT8_C(  74),
       INT8_C( 103),
      { -INT8_C(  74), -INT8_C(  74), -INT8_C(  74), -INT8_C(  74), -INT8_C(  74), -INT8_C(  74), -INT8_C(  74), -INT8_C(  74),
        -INT8_C(  74), -INT8_C(  74), -INT8_C(  74), -INT8_C(  74), -INT8_C(  74), -INT8_C(  74), -INT8_C(  74), -INT8_C(  74) } },
    { -INT8_C(  77),
      -INT8_C(  89),
      { -INT8_C(  77), -INT8_C(  77), -INT8_C(  77), -INT8_C(  77), -INT8_C(  77), -INT8_C(  77), -INT8_C(  77), -INT8_C(  77),
        -INT8_C(  77), -INT8_C(  77), -INT8_C(  77), -INT8_C(  77), -INT8_C(  77), -INT8_C(  77), -INT8_C(  77), -INT8_C(  77) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16_t r = simde_vld1q_dup_s8(&test_vec[i].a);

    simde_test_arm_neon_assert_equal_i8x16(r,
                                           simde_vld1q_s8(test_vec[i].r));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    int8_t a = simde_test_codegen_random_i8();
    simde_int8x16_t r = simde_vld1q_dup_s8(&a);
    // Random buffer between pointer to load and expected results to check for
    // loading out of bounds.
    int8_t unused = simde_test_codegen_random_i8();

    simde_test_codegen_write_i8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i8(2, unused, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld1q_dup_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a;
    int16_t unused;
    int16_t r[16];
  } test_vec[] = {
    {  INT16_C( 25140),
       INT16_C( 27159),
      {  INT16_C( 25140),  INT16_C( 25140),  INT16_C( 25140),  INT16_C( 25140),  INT16_C( 25140),  INT16_C( 25140),  INT16_C( 25140),  INT16_C( 25140) } },
    {  INT16_C( 17366),
       INT16_C(  7763),
      {  INT16_C( 17366),  INT16_C( 17366),  INT16_C( 17366),  INT16_C( 17366),  INT16_C( 17366),  INT16_C( 17366),  INT16_C( 17366),  INT16_C( 17366) } },
    {  INT16_C( 28655),
       INT16_C( 17684),
      {  INT16_C( 28655),  INT16_C( 28655),  INT16_C( 28655),  INT16_C( 28655),  INT16_C( 28655),  INT16_C( 28655),  INT16_C( 28655),  INT16_C( 28655) } },
    { -INT16_C( 24572),
       INT16_C( 23778),
      { -INT16_C( 24572), -INT16_C( 24572), -INT16_C( 24572), -INT16_C( 24572), -INT16_C( 24572), -INT16_C( 24572), -INT16_C( 24572), -INT16_C( 24572) } },
    {  INT16_C( 11818),
       INT16_C( 21424),
      {  INT16_C( 11818),  INT16_C( 11818),  INT16_C( 11818),  INT16_C( 11818),  INT16_C( 11818),  INT16_C( 11818),  INT16_C( 11818),  INT16_C( 11818) } },
    {  INT16_C( 11802),
       INT16_C( 23800),
      {  INT16_C( 11802),  INT16_C( 11802),  INT16_C( 11802),  INT16_C( 11802),  INT16_C( 11802),  INT16_C( 11802),  INT16_C( 11802),  INT16_C( 11802) } },
    {  INT16_C( 15325),
       INT16_C( 30593),
      {  INT16_C( 15325),  INT16_C( 15325),  INT16_C( 15325),  INT16_C( 15325),  INT16_C( 15325),  INT16_C( 15325),  INT16_C( 15325),  INT16_C( 15325) } },
    { -INT16_C(  1781),
       INT16_C( 16340),
      { -INT16_C(  1781), -INT16_C(  1781), -INT16_C(  1781), -INT16_C(  1781), -INT16_C(  1781), -INT16_C(  1781), -INT16_C(  1781), -INT16_C(  1781) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t r = simde_vld1q_dup_s16(&test_vec[i].a);

    simde_test_arm_neon_assert_equal_i16x8(r,
                                           simde_vld1q_s16(test_vec[i].r));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    int16_t a = simde_test_codegen_random_i16();
    simde_int16x8_t r = simde_vld1q_dup_s16(&a);
    // Random buffer between pointer to load and expected results to check for
    // loading out of bounds.
    int16_t unused = simde_test_codegen_random_i16();

    simde_test_codegen_write_i16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i16(2, unused, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld1q_dup_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a;
    int32_t unused;
    int32_t r[16];
  } test_vec[] = {
    { -INT32_C(   184150047),
       INT32_C(   616751798),
      { -INT32_C(   184150047), -INT32_C(   184150047), -INT32_C(   184150047), -INT32_C(   184150047) } },
    {  INT32_C(  2117210528),
       INT32_C(  1709426408),
      {  INT32_C(  2117210528),  INT32_C(  2117210528),  INT32_C(  2117210528),  INT32_C(  2117210528) } },
    { -INT32_C(   300479163),
       INT32_C(   569423300),
      { -INT32_C(   300479163), -INT32_C(   300479163), -INT32_C(   300479163), -INT32_C(   300479163) } },
    { -INT32_C(   818696462),
       INT32_C(  1251895145),
      { -INT32_C(   818696462), -INT32_C(   818696462), -INT32_C(   818696462), -INT32_C(   818696462) } },
    {  INT32_C(   876651646),
       INT32_C(   643302022),
      {  INT32_C(   876651646),  INT32_C(   876651646),  INT32_C(   876651646),  INT32_C(   876651646) } },
    { -INT32_C(    56259820),
      -INT32_C(  1755215791),
      { -INT32_C(    56259820), -INT32_C(    56259820), -INT32_C(    56259820), -INT32_C(    56259820) } },
    {  INT32_C(  1518696597),
       INT32_C(   544961838),
      {  INT32_C(  1518696597),  INT32_C(  1518696597),  INT32_C(  1518696597),  INT32_C(  1518696597) } },
    { -INT32_C(  1913672157),
      -INT32_C(  1814590187),
      { -INT32_C(  1913672157), -INT32_C(  1913672157), -INT32_C(  1913672157), -INT32_C(  1913672157) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t r = simde_vld1q_dup_s32(&test_vec[i].a);

    simde_test_arm_neon_assert_equal_i32x4(r,
                                           simde_vld1q_s32(test_vec[i].r));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    int32_t a = simde_test_codegen_random_i32();
    simde_int32x4_t r = simde_vld1q_dup_s32(&a);
    // Random buffer between pointer to load and expected results to check for
    // loading out of bounds.
    int32_t unused = simde_test_codegen_random_i32();

    simde_test_codegen_write_i32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i32(2, unused, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld1q_dup_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a;
    int64_t unused;
    int64_t r[16];
  } test_vec[] = {
    {  INT64_C( 8263121084250523414),
      -INT64_C(  133247727922472292),
      {  INT64_C( 8263121084250523414),  INT64_C( 8263121084250523414) } },
    { -INT64_C( 6063255998107405179),
       INT64_C( 2810408970900099590),
      { -INT64_C( 6063255998107405179), -INT64_C( 6063255998107405179) } },
    { -INT64_C( 1592455347479851877),
       INT64_C( 1510058888478061328),
      { -INT64_C( 1592455347479851877), -INT64_C( 1592455347479851877) } },
    { -INT64_C( 8901012275148193534),
      -INT64_C( 4915075221215212654),
      { -INT64_C( 8901012275148193534), -INT64_C( 8901012275148193534) } },
    {  INT64_C( 1884216627821516017),
      -INT64_C( 7013506924103545335),
      {  INT64_C( 1884216627821516017),  INT64_C( 1884216627821516017) } },
    { -INT64_C( 2051417869619818107),
      -INT64_C( 4445807296613274511),
      { -INT64_C( 2051417869619818107), -INT64_C( 2051417869619818107) } },
    { -INT64_C( 7274959835513258779),
      -INT64_C( 6616106579711091980),
      { -INT64_C( 7274959835513258779), -INT64_C( 7274959835513258779) } },
    { -INT64_C(  998620985170617361),
      -INT64_C( 2202592284581254181),
      { -INT64_C(  998620985170617361), -INT64_C(  998620985170617361) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t r = simde_vld1q_dup_s64(&test_vec[i].a);

    simde_test_arm_neon_assert_equal_i64x2(r,
                                           simde_vld1q_s64(test_vec[i].r));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    int64_t a = simde_test_codegen_random_i64();
    simde_int64x2_t r = simde_vld1q_dup_s64(&a);
    // Random buffer between pointer to load and expected results to check for
    // loading out of bounds.
    int64_t unused = simde_test_codegen_random_i64();

    simde_test_codegen_write_i64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i64(2, unused, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld1q_dup_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t a;
    uint8_t unused;
    uint8_t r[16];
  } test_vec[] = {
    { UINT8_C( 49),
      UINT8_C(147),
      { UINT8_C( 49), UINT8_C( 49), UINT8_C( 49), UINT8_C( 49), UINT8_C( 49), UINT8_C( 49), UINT8_C( 49), UINT8_C( 49),
        UINT8_C( 49), UINT8_C( 49), UINT8_C( 49), UINT8_C( 49), UINT8_C( 49), UINT8_C( 49), UINT8_C( 49), UINT8_C( 49) } },
    { UINT8_C(153),
      UINT8_C(198),
      { UINT8_C(153), UINT8_C(153), UINT8_C(153), UINT8_C(153), UINT8_C(153), UINT8_C(153), UINT8_C(153), UINT8_C(153),
        UINT8_C(153), UINT8_C(153), UINT8_C(153), UINT8_C(153), UINT8_C(153), UINT8_C(153), UINT8_C(153), UINT8_C(153) } },
    { UINT8_C(159),
      UINT8_C(134),
      { UINT8_C(159), UINT8_C(159), UINT8_C(159), UINT8_C(159), UINT8_C(159), UINT8_C(159), UINT8_C(159), UINT8_C(159),
        UINT8_C(159), UINT8_C(159), UINT8_C(159), UINT8_C(159), UINT8_C(159), UINT8_C(159), UINT8_C(159), UINT8_C(159) } },
    { UINT8_C( 72),
      UINT8_C(166),
      { UINT8_C( 72), UINT8_C( 72), UINT8_C( 72), UINT8_C( 72), UINT8_C( 72), UINT8_C( 72), UINT8_C( 72), UINT8_C( 72),
        UINT8_C( 72), UINT8_C( 72), UINT8_C( 72), UINT8_C( 72), UINT8_C( 72), UINT8_C( 72), UINT8_C( 72), UINT8_C( 72) } },
    { UINT8_C(102),
      UINT8_C( 68),
      { UINT8_C(102), UINT8_C(102), UINT8_C(102), UINT8_C(102), UINT8_C(102), UINT8_C(102), UINT8_C(102), UINT8_C(102),
        UINT8_C(102), UINT8_C(102), UINT8_C(102), UINT8_C(102), UINT8_C(102), UINT8_C(102), UINT8_C(102), UINT8_C(102) } },
    { UINT8_C(112),
      UINT8_C(230),
      { UINT8_C(112), UINT8_C(112), UINT8_C(112), UINT8_C(112), UINT8_C(112), UINT8_C(112), UINT8_C(112), UINT8_C(112),
        UINT8_C(112), UINT8_C(112), UINT8_C(112), UINT8_C(112), UINT8_C(112), UINT8_C(112), UINT8_C(112), UINT8_C(112) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x16_t r = simde_vld1q_dup_u8(&test_vec[i].a);

    simde_test_arm_neon_assert_equal_u8x16(r,
                                           simde_vld1q_u8(test_vec[i].r));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    uint8_t a = simde_test_codegen_random_u8();
    simde_uint8x16_t r = simde_vld1q_dup_u8(&a);
    // Random buffer between pointer to load and expected results to check for
    // loading out of bounds.
    uint8_t unused = simde_test_codegen_random_u8();

    simde_test_codegen_write_u8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u8(2, unused, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld1q_dup_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a;
    uint16_t unused;
    uint16_t r[16];
  } test_vec[] = {
    { UINT16_C( 4043),
      UINT16_C(61235),
      { UINT16_C( 4043), UINT16_C( 4043), UINT16_C( 4043), UINT16_C( 4043), UINT16_C( 4043), UINT16_C( 4043), UINT16_C( 4043), UINT16_C( 4043) } },
    { UINT16_C(48168),
      UINT16_C(22282),
      { UINT16_C(48168), UINT16_C(48168), UINT16_C(48168), UINT16_C(48168), UINT16_C(48168), UINT16_C(48168), UINT16_C(48168), UINT16_C(48168) } },
    { UINT16_C( 4777),
      UINT16_C( 5331),
      { UINT16_C( 4777), UINT16_C( 4777), UINT16_C( 4777), UINT16_C( 4777), UINT16_C( 4777), UINT16_C( 4777), UINT16_C( 4777), UINT16_C( 4777) } },
    { UINT16_C(45057),
      UINT16_C(39588),
      { UINT16_C(45057), UINT16_C(45057), UINT16_C(45057), UINT16_C(45057), UINT16_C(45057), UINT16_C(45057), UINT16_C(45057), UINT16_C(45057) } },
    { UINT16_C( 6709),
      UINT16_C(26419),
      { UINT16_C( 6709), UINT16_C( 6709), UINT16_C( 6709), UINT16_C( 6709), UINT16_C( 6709), UINT16_C( 6709), UINT16_C( 6709), UINT16_C( 6709) } },
    { UINT16_C(52397),
      UINT16_C(19757),
      { UINT16_C(52397), UINT16_C(52397), UINT16_C(52397), UINT16_C(52397), UINT16_C(52397), UINT16_C(52397), UINT16_C(52397), UINT16_C(52397) } },
    { UINT16_C(30290),
      UINT16_C(47603),
      { UINT16_C(30290), UINT16_C(30290), UINT16_C(30290), UINT16_C(30290), UINT16_C(30290), UINT16_C(30290), UINT16_C(30290), UINT16_C(30290) } },
    { UINT16_C(25530),
      UINT16_C(34207),
      { UINT16_C(25530), UINT16_C(25530), UINT16_C(25530), UINT16_C(25530), UINT16_C(25530), UINT16_C(25530), UINT16_C(25530), UINT16_C(25530) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t r = simde_vld1q_dup_u16(&test_vec[i].a);

    simde_test_arm_neon_assert_equal_u16x8(r,
                                           simde_vld1q_u16(test_vec[i].r));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    uint16_t a = simde_test_codegen_random_u16();
    simde_uint16x8_t r = simde_vld1q_dup_u16(&a);
    // Random buffer between pointer to load and expected results to check for
    // loading out of bounds.
    uint16_t unused = simde_test_codegen_random_u16();

    simde_test_codegen_write_u16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u16(2, unused, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld1q_dup_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a;
    uint32_t unused;
    uint32_t r[16];
  } test_vec[] = {
    { UINT32_C(2591347570),
      UINT32_C( 955416207),
      { UINT32_C(2591347570), UINT32_C(2591347570), UINT32_C(2591347570), UINT32_C(2591347570) } },
    { UINT32_C(2454570385),
      UINT32_C(2871849333),
      { UINT32_C(2454570385), UINT32_C(2454570385), UINT32_C(2454570385), UINT32_C(2454570385) } },
    { UINT32_C(3104988939),
      UINT32_C(2114338603),
      { UINT32_C(3104988939), UINT32_C(3104988939), UINT32_C(3104988939), UINT32_C(3104988939) } },
    { UINT32_C(1865939381),
      UINT32_C(3472217692),
      { UINT32_C(1865939381), UINT32_C(1865939381), UINT32_C(1865939381), UINT32_C(1865939381) } },
    { UINT32_C( 963144105),
      UINT32_C(2037471976),
      { UINT32_C( 963144105), UINT32_C( 963144105), UINT32_C( 963144105), UINT32_C( 963144105) } },
    { UINT32_C(2500574751),
      UINT32_C(3141547951),
      { UINT32_C(2500574751), UINT32_C(2500574751), UINT32_C(2500574751), UINT32_C(2500574751) } },
    { UINT32_C(3245626006),
      UINT32_C(1195342481),
      { UINT32_C(3245626006), UINT32_C(3245626006), UINT32_C(3245626006), UINT32_C(3245626006) } },
    { UINT32_C(3484841587),
      UINT32_C(4137528141),
      { UINT32_C(3484841587), UINT32_C(3484841587), UINT32_C(3484841587), UINT32_C(3484841587) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t r = simde_vld1q_dup_u32(&test_vec[i].a);

    simde_test_arm_neon_assert_equal_u32x4(r,
                                           simde_vld1q_u32(test_vec[i].r));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    uint32_t a = simde_test_codegen_random_u32();
    simde_uint32x4_t r = simde_vld1q_dup_u32(&a);
    // Random buffer between pointer to load and expected results to check for
    // loading out of bounds.
    uint32_t unused = simde_test_codegen_random_u32();

    simde_test_codegen_write_u32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u32(2, unused, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld1q_dup_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a;
    uint64_t unused;
    uint64_t r[16];
  } test_vec[] = {
    { UINT64_C( 9184705928005354773),
      UINT64_C( 5677443429757649247),
      { UINT64_C( 9184705928005354773), UINT64_C( 9184705928005354773) } },
    { UINT64_C( 3134311518306254502),
      UINT64_C(17728868401062491589),
      { UINT64_C( 3134311518306254502), UINT64_C( 3134311518306254502) } },
    { UINT64_C( 4142302142246631580),
      UINT64_C(10083580343162015978),
      { UINT64_C( 4142302142246631580), UINT64_C( 4142302142246631580) } },
    { UINT64_C( 1455580007492747088),
      UINT64_C( 6939818071156993400),
      { UINT64_C( 1455580007492747088), UINT64_C( 1455580007492747088) } },
    { UINT64_C(10771160788369228392),
      UINT64_C( 2655478723087155817),
      { UINT64_C(10771160788369228392), UINT64_C(10771160788369228392) } },
    { UINT64_C( 6379735764790189350),
      UINT64_C( 5165911206702198668),
      { UINT64_C( 6379735764790189350), UINT64_C( 6379735764790189350) } },
    { UINT64_C( 5801203564664065602),
      UINT64_C(  485959815376386501),
      { UINT64_C( 5801203564664065602), UINT64_C( 5801203564664065602) } },
    { UINT64_C(15514342486347344662),
      UINT64_C( 4745343749585371060),
      { UINT64_C(15514342486347344662), UINT64_C(15514342486347344662) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x2_t r = simde_vld1q_dup_u64(&test_vec[i].a);

    simde_test_arm_neon_assert_equal_u64x2(r,
                                           simde_vld1q_u64(test_vec[i].r));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    uint64_t a = simde_test_codegen_random_u64();
    simde_uint64x2_t r = simde_vld1q_dup_u64(&a);
    // Random buffer between pointer to load and expected results to check for
    // loading out of bounds.
    uint64_t unused = simde_test_codegen_random_u64();

    simde_test_codegen_write_u64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u64(2, unused, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

#endif /* !defined(SIMDE_BUG_INTEL_857088) */

SIMDE_TEST_FUNC_LIST_BEGIN
#if !defined(SIMDE_BUG_INTEL_857088)
SIMDE_TEST_FUNC_LIST_ENTRY(vld1q_dup_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vld1q_dup_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vld1q_dup_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vld1q_dup_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vld1q_dup_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vld1q_dup_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vld1q_dup_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vld1q_dup_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vld1q_dup_u64)
#endif /* !defined(SIMDE_BUG_INTEL_857088) */
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
