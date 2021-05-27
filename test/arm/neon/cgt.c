#define SIMDE_TEST_ARM_NEON_INSN cgt

#include "test-neon.h"

/* Check that both of these work */
#if defined(__cplusplus)
  #include "../../../simde/arm/neon/cgt.h"
#else
  #include "../../../simde/arm/neon.h"
#endif

static int
test_simde_vcgt_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a[2];
    simde_float32 b[2];
    uint32_t r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -594.36), SIMDE_FLOAT32_C(  -430.71) },
      { SIMDE_FLOAT32_C(    66.10), SIMDE_FLOAT32_C(   318.22) },
      { UINT32_C(         0), UINT32_C(         0) } },
    { { SIMDE_FLOAT32_C(   895.57), SIMDE_FLOAT32_C(   -28.91) },
      { SIMDE_FLOAT32_C(   945.51), SIMDE_FLOAT32_C(   -28.91) },
      { UINT32_C(         0), UINT32_C(         0) } },
    { { SIMDE_FLOAT32_C(  -484.25), SIMDE_FLOAT32_C(  -208.16) },
      { SIMDE_FLOAT32_C(   869.60), SIMDE_FLOAT32_C(  -208.16) },
      { UINT32_C(         0), UINT32_C(         0) } },
    { { SIMDE_FLOAT32_C(  -169.59), SIMDE_FLOAT32_C(   957.55) },
      { SIMDE_FLOAT32_C(  -169.59), SIMDE_FLOAT32_C(   126.36) },
      { UINT32_C(         0),           UINT32_MAX } },
    { { SIMDE_FLOAT32_C(   853.75), SIMDE_FLOAT32_C(  -413.58) },
      { SIMDE_FLOAT32_C(   784.06), SIMDE_FLOAT32_C(  -413.58) },
      {           UINT32_MAX, UINT32_C(         0) } },
    { { SIMDE_FLOAT32_C(  -413.85), SIMDE_FLOAT32_C(   334.07) },
      { SIMDE_FLOAT32_C(  -413.85), SIMDE_FLOAT32_C(  -621.67) },
      { UINT32_C(         0),           UINT32_MAX } },
    { { SIMDE_FLOAT32_C(  -664.52), SIMDE_FLOAT32_C(  -452.14) },
      { SIMDE_FLOAT32_C(  -360.16), SIMDE_FLOAT32_C(  -719.02) },
      { UINT32_C(         0),           UINT32_MAX } },
    { { SIMDE_FLOAT32_C(  -452.99), SIMDE_FLOAT32_C(  -583.39) },
      { SIMDE_FLOAT32_C(    29.10), SIMDE_FLOAT32_C(  -583.39) },
      { UINT32_C(         0), UINT32_C(         0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t a = simde_vld1_f32(test_vec[i].a);
    simde_float32x2_t b = simde_vld1_f32(test_vec[i].b);
    simde_uint32x2_t r = simde_vcgt_f32(a, b);

    simde_test_arm_neon_assert_equal_u32x2(r, simde_vld1_u32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x2_private a_ = simde_float32x2_to_private(simde_test_arm_neon_random_f32x2(-1000.0, 1000.0));
    simde_float32x2_private b_ = simde_float32x2_to_private(simde_test_arm_neon_random_f32x2(-1000.0, 1000.0));

    /* Make some equal which is unlikely to happen by accident. */
    for (size_t j = 0 ; j < (sizeof(a_.values) / sizeof(a_.values[0])) ; j++) {
      if (rand() < (RAND_MAX / 3)) a_.values[j] = b_.values[j];
    }

    simde_float32x2_t a = simde_float32x2_from_private(a_);
    simde_float32x2_t b = simde_float32x2_from_private(b_);

    simde_uint32x2_t r = simde_vcgt_f32(a, b);

    simde_test_arm_neon_write_f32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcgt_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 a[1];
    simde_float64 b[1];
    uint64_t r[1];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(   -24.01) },
      { SIMDE_FLOAT64_C(   -24.01) },
      { UINT64_C(                   0) } },
    { { SIMDE_FLOAT64_C(  -765.41) },
      { SIMDE_FLOAT64_C(  -856.24) },
      {                    UINT64_MAX } },
    { { SIMDE_FLOAT64_C(  -723.94) },
      { SIMDE_FLOAT64_C(   639.04) },
      { UINT64_C(                   0) } },
    { { SIMDE_FLOAT64_C(  -780.40) },
      { SIMDE_FLOAT64_C(  -780.40) },
      { UINT64_C(                   0) } },
    { { SIMDE_FLOAT64_C(   140.87) },
      { SIMDE_FLOAT64_C(   140.87) },
      { UINT64_C(                   0) } },
    { { SIMDE_FLOAT64_C(   -29.24) },
      { SIMDE_FLOAT64_C(   -30.09) },
      {                    UINT64_MAX } },
    { { SIMDE_FLOAT64_C(  -911.69) },
      { SIMDE_FLOAT64_C(  -396.28) },
      { UINT64_C(                   0) } },
    { { SIMDE_FLOAT64_C(    20.33) },
      { SIMDE_FLOAT64_C(    20.33) },
      { UINT64_C(                   0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x1_t a = simde_vld1_f64(test_vec[i].a);
    simde_float64x1_t b = simde_vld1_f64(test_vec[i].b);
    simde_uint64x1_t r = simde_vcgt_f64(a, b);

    simde_test_arm_neon_assert_equal_u64x1(r, simde_vld1_u64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x1_private a_ = simde_float64x1_to_private(simde_test_arm_neon_random_f64x1(-1000.0, 1000.0));
    simde_float64x1_private b_ = simde_float64x1_to_private(simde_test_arm_neon_random_f64x1(-1000.0, 1000.0));

    /* Make some equal which is unlikely to happen by accident. */
    for (size_t j = 0 ; j < (sizeof(a_.values) / sizeof(a_.values[0])) ; j++) {
      if (rand() < (RAND_MAX / 3)) a_.values[j] = b_.values[j];
    }

    simde_float64x1_t a = simde_float64x1_from_private(a_);
    simde_float64x1_t b = simde_float64x1_from_private(b_);

    simde_uint64x1_t r = simde_vcgt_f64(a, b);

    simde_test_arm_neon_write_f64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x1(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcgt_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[8];
    int8_t b[8];
    uint8_t r[8];
  } test_vec[] = {
    { { -INT8_C(  20),  INT8_C(  80), -INT8_C( 110),      INT8_MIN, -INT8_C( 123), -INT8_C(  56), -INT8_C(  33),  INT8_C(  11) },
      { -INT8_C(  39),  INT8_C(  19), -INT8_C(  53), -INT8_C(  86), -INT8_C( 123), -INT8_C(  23), -INT8_C(  33), -INT8_C(  82) },
      {    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX } },
    { { -INT8_C(   2),  INT8_C(  61), -INT8_C(  85),  INT8_C(  50),  INT8_C(   5), -INT8_C(  19), -INT8_C(  85), -INT8_C(  79) },
      { -INT8_C(  38),  INT8_C(  61),  INT8_C(  49),  INT8_C(   2),  INT8_C(   5), -INT8_C(  19),  INT8_C(  13), -INT8_C(  34) },
      {    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) } },
    { {  INT8_C(  59), -INT8_C( 118),  INT8_C( 122),  INT8_C(  54),  INT8_C(  74), -INT8_C(  67), -INT8_C(  34),  INT8_C(  72) },
      {  INT8_C( 113), -INT8_C( 118),  INT8_C( 122),  INT8_C(  54),  INT8_C(  19),  INT8_C(  37), -INT8_C(  25), -INT8_C(  19) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX } },
    { {      INT8_MIN, -INT8_C(  49), -INT8_C( 115), -INT8_C( 103),  INT8_C(  40), -INT8_C(  62),  INT8_C(  17), -INT8_C( 103) },
      {      INT8_MIN,  INT8_C( 107),  INT8_C(  97), -INT8_C(  54),  INT8_C(  40),  INT8_C(  64),  INT8_C(  19), -INT8_C( 103) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) } },
    { { -INT8_C(  50), -INT8_C(  69),  INT8_C( 125), -INT8_C(  55), -INT8_C(  72), -INT8_C(  61),  INT8_C(  59), -INT8_C( 113) },
      { -INT8_C( 110),  INT8_C( 105),  INT8_C(  40), -INT8_C(  55),  INT8_C(  43),  INT8_C(  57),  INT8_C(  59), -INT8_C(  85) },
      {    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) } },
    { {  INT8_C(  22),  INT8_C(  52), -INT8_C( 124), -INT8_C(  55), -INT8_C(  22),  INT8_C( 105), -INT8_C(  33), -INT8_C(  79) },
      {  INT8_C(  10),  INT8_C(  92), -INT8_C( 115), -INT8_C(  61),  INT8_C(  31),  INT8_C( 105),  INT8_C(  82), -INT8_C(  79) },
      {    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) } },
    { {  INT8_C(  82),  INT8_C(  30), -INT8_C( 121), -INT8_C(  87), -INT8_C(  89), -INT8_C( 118), -INT8_C(  42), -INT8_C(  75) },
      { -INT8_C(  66),  INT8_C(  91), -INT8_C( 121), -INT8_C(  87), -INT8_C(  86),  INT8_C( 102),  INT8_C(  98), -INT8_C(  75) },
      {    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) } },
    { { -INT8_C(  18),  INT8_C( 116),  INT8_C(  39), -INT8_C(   9), -INT8_C(   2),  INT8_C(  26),  INT8_C(  84),  INT8_C(  20) },
      { -INT8_C(  18),  INT8_C( 116),  INT8_C(  68), -INT8_C( 106), -INT8_C(   2),  INT8_C(  26),  INT8_C(  84), -INT8_C(  68) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8_t a = simde_vld1_s8(test_vec[i].a);
    simde_int8x8_t b = simde_vld1_s8(test_vec[i].b);
    simde_uint8x8_t r = simde_vcgt_s8(a, b);

    simde_test_arm_neon_assert_equal_u8x8(r, simde_vld1_u8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x8_private a_ = simde_int8x8_to_private(simde_test_arm_neon_random_i8x8());
    simde_int8x8_private b_ = simde_int8x8_to_private(simde_test_arm_neon_random_i8x8());

    /* Make some equal which is unlikely to happen by accident. */
    for (size_t j = 0 ; j < (sizeof(a_.values) / sizeof(a_.values[0])) ; j++) {
      if (rand() < (RAND_MAX / 3)) a_.values[j] = b_.values[j];
    }

    simde_int8x8_t a = simde_int8x8_from_private(a_);
    simde_int8x8_t b = simde_int8x8_from_private(b_);

    simde_uint8x8_t r = simde_vcgt_s8(a, b);

    simde_test_arm_neon_write_i8x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcgt_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[4];
    int16_t b[4];
    uint16_t r[4];
  } test_vec[] = {
    { { -INT16_C( 28683),  INT16_C( 18521),  INT16_C( 16553), -INT16_C(  1209) },
      {  INT16_C( 26074),  INT16_C( 26696),  INT16_C( 16553), -INT16_C(  1209) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { {  INT16_C( 31423),  INT16_C(  8947),  INT16_C( 30730), -INT16_C( 18190) },
      {  INT16_C( 31423), -INT16_C( 19425),  INT16_C( 30730),  INT16_C(   765) },
      { UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    0) } },
    { {  INT16_C( 12592), -INT16_C(  9732), -INT16_C(  5087),  INT16_C( 12500) },
      {  INT16_C( 32559), -INT16_C( 15368), -INT16_C(  5087),  INT16_C( 12517) },
      { UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    0) } },
    { {  INT16_C( 18406),  INT16_C( 23582), -INT16_C( 13959), -INT16_C(  5393) },
      {  INT16_C( 18406),  INT16_C(  5837), -INT16_C( 13959), -INT16_C(  5393) },
      { UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    0) } },
    { {  INT16_C(  4930),  INT16_C( 25599), -INT16_C(  6913), -INT16_C( 21868) },
      {  INT16_C( 31932),  INT16_C(  3860),  INT16_C( 12932),  INT16_C(  1387) },
      { UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    0) } },
    { { -INT16_C( 28676),  INT16_C( 15901),  INT16_C( 14804), -INT16_C(  7819) },
      { -INT16_C( 28676),  INT16_C( 15901),  INT16_C(  7330), -INT16_C( 24158) },
      { UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX } },
    { {  INT16_C( 31233),  INT16_C(  4884),  INT16_C( 24198), -INT16_C(  8132) },
      {  INT16_C( 31233),  INT16_C(  4884),  INT16_C( 24198),  INT16_C( 23197) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { {  INT16_C( 22690),  INT16_C( 23602),  INT16_C( 29556),  INT16_C(  9107) },
      {  INT16_C( 12713),  INT16_C( 23602), -INT16_C(   367),  INT16_C(  9107) },
      {      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t a = simde_vld1_s16(test_vec[i].a);
    simde_int16x4_t b = simde_vld1_s16(test_vec[i].b);
    simde_uint16x4_t r = simde_vcgt_s16(a, b);

    simde_test_arm_neon_assert_equal_u16x4(r, simde_vld1_u16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x4_private a_ = simde_int16x4_to_private(simde_test_arm_neon_random_i16x4());
    simde_int16x4_private b_ = simde_int16x4_to_private(simde_test_arm_neon_random_i16x4());

    /* Make some equal which is unlikely to happen by accident. */
    for (size_t j = 0 ; j < (sizeof(a_.values) / sizeof(a_.values[0])) ; j++) {
      if (rand() < (RAND_MAX / 3)) a_.values[j] = b_.values[j];
    }

    simde_int16x4_t a = simde_int16x4_from_private(a_);
    simde_int16x4_t b = simde_int16x4_from_private(b_);

    simde_uint16x4_t r = simde_vcgt_s16(a, b);

    simde_test_arm_neon_write_i16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcgt_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[2];
    int32_t b[2];
    uint32_t r[2];
  } test_vec[] = {
    { {  INT32_C(  1272032729),  INT32_C(  1940613686) },
      { -INT32_C(  1339384298), -INT32_C(    71380318) },
      {           UINT32_MAX,           UINT32_MAX } },
    { { -INT32_C(   510544776),  INT32_C(    47620657) },
      {  INT32_C(   701037432),  INT32_C(    47620657) },
      { UINT32_C(         0), UINT32_C(         0) } },
    { { -INT32_C(  2105501588), -INT32_C(  1020376014) },
      {  INT32_C(  2060775804), -INT32_C(  1020376014) },
      { UINT32_C(         0), UINT32_C(         0) } },
    { {  INT32_C(   541360295), -INT32_C(  1405936852) },
      { -INT32_C(  1683021906), -INT32_C(  1405936852) },
      {           UINT32_MAX, UINT32_C(         0) } },
    { { -INT32_C(   750530473),  INT32_C(  1846632234) },
      { -INT32_C(  1850246045),  INT32_C(  1846632234) },
      {           UINT32_MAX, UINT32_C(         0) } },
    { {  INT32_C(   691652730), -INT32_C(  1519249566) },
      { -INT32_C(  1581189117), -INT32_C(  1519249566) },
      {           UINT32_MAX, UINT32_C(         0) } },
    { {  INT32_C(   522664124), -INT32_C(   558833740) },
      { -INT32_C(  1119043266), -INT32_C(  2021275826) },
      {           UINT32_MAX,           UINT32_MAX } },
    { {  INT32_C(  1921037423), -INT32_C(   511938631) },
      {  INT32_C(  1135838808), -INT32_C(   511938631) },
      {           UINT32_MAX, UINT32_C(         0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t a = simde_vld1_s32(test_vec[i].a);
    simde_int32x2_t b = simde_vld1_s32(test_vec[i].b);
    simde_uint32x2_t r = simde_vcgt_s32(a, b);

    simde_test_arm_neon_assert_equal_u32x2(r, simde_vld1_u32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x2_private a_ = simde_int32x2_to_private(simde_test_arm_neon_random_i32x2());
    simde_int32x2_private b_ = simde_int32x2_to_private(simde_test_arm_neon_random_i32x2());

    /* Make some equal which is unlikely to happen by accident. */
    for (size_t j = 0 ; j < (sizeof(a_.values) / sizeof(a_.values[0])) ; j++) {
      if (rand() < (RAND_MAX / 3)) a_.values[j] = b_.values[j];
    }

    simde_int32x2_t a = simde_int32x2_from_private(a_);
    simde_int32x2_t b = simde_int32x2_from_private(b_);

    simde_uint32x2_t r = simde_vcgt_s32(a, b);

    simde_test_arm_neon_write_i32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcgt_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a[1];
    int64_t b[1];
    uint64_t r[1];
  } test_vec[] = {
    { { -INT64_C( 3823520135268495771) },
      { -INT64_C( 2454514891205621436) },
      { UINT64_C(                   0) } },
    { { -INT64_C( 1386457369042881231) },
      { -INT64_C( 1386457369042881231) },
      { UINT64_C(                   0) } },
    { {  INT64_C( 3521105073255325347) },
      {  INT64_C( 6733137012515181439) },
      { UINT64_C(                   0) } },
    { {  INT64_C( 4316921532226472852) },
      { -INT64_C( 3347124278221125850) },
      {                    UINT64_MAX } },
    { {  INT64_C( 7678865423090072096) },
      {  INT64_C( 7513120585129590846) },
      {                    UINT64_MAX } },
    { {  INT64_C( 8171360295472179766) },
      { -INT64_C( 6550794157104719511) },
      {                    UINT64_MAX } },
    { { -INT64_C( 3628699006713524461) },
      {  INT64_C( 1544264537413518068) },
      { UINT64_C(                   0) } },
    { { -INT64_C( 6001437256871250036) },
      { -INT64_C( 6001437256871250036) },
      { UINT64_C(                   0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x1_t a = simde_vld1_s64(test_vec[i].a);
    simde_int64x1_t b = simde_vld1_s64(test_vec[i].b);
    simde_uint64x1_t r = simde_vcgt_s64(a, b);

    simde_test_arm_neon_assert_equal_u64x1(r, simde_vld1_u64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int64x1_private a_ = simde_int64x1_to_private(simde_test_arm_neon_random_i64x1());
    simde_int64x1_private b_ = simde_int64x1_to_private(simde_test_arm_neon_random_i64x1());

    /* Make some equal which is unlikely to happen by accident. */
    for (size_t j = 0 ; j < (sizeof(a_.values) / sizeof(a_.values[0])) ; j++) {
      if (rand() < (RAND_MAX / 3)) a_.values[j] = b_.values[j];
    }

    simde_int64x1_t a = simde_int64x1_from_private(a_);
    simde_int64x1_t b = simde_int64x1_from_private(b_);

    simde_uint64x1_t r = simde_vcgt_s64(a, b);

    simde_test_arm_neon_write_i64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x1(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcgt_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t a[8];
    uint8_t b[8];
    uint8_t r[8];
  } test_vec[] = {
    { { UINT8_C( 61), UINT8_C(241), UINT8_C(132), UINT8_C(244), UINT8_C(134), UINT8_C(100), UINT8_C(175), UINT8_C( 82) },
      { UINT8_C( 61), UINT8_C(241), UINT8_C(132), UINT8_C(186), UINT8_C(143), UINT8_C(100), UINT8_C(114), UINT8_C( 93) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0) } },
    { { UINT8_C(246), UINT8_C(181), UINT8_C(  4), UINT8_C(125), UINT8_C(193), UINT8_C( 76), UINT8_C(189), UINT8_C(157) },
      { UINT8_C(246), UINT8_C(  2), UINT8_C(252), UINT8_C(125), UINT8_C( 95), UINT8_C(171), UINT8_C(207), UINT8_C(157) },
      { UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) } },
    { { UINT8_C(166), UINT8_C(170), UINT8_C(110), UINT8_C(218), UINT8_C(246), UINT8_C(100), UINT8_C(165), UINT8_C(236) },
      { UINT8_C( 25), UINT8_C(170), UINT8_C(110), UINT8_C(218), UINT8_C(246), UINT8_C( 43), UINT8_C(226), UINT8_C(236) },
      {    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0) } },
    { { UINT8_C(140), UINT8_C(130), UINT8_C(113), UINT8_C( 67), UINT8_C( 95), UINT8_C( 22), UINT8_C(217), UINT8_C(242) },
      { UINT8_C( 68), UINT8_C(251), UINT8_C(113), UINT8_C(195), UINT8_C( 95), UINT8_C( 22), UINT8_C(250), UINT8_C(121) },
      {    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX } },
    { { UINT8_C( 20), UINT8_C( 12), UINT8_C( 20), UINT8_C( 71), UINT8_C( 69), UINT8_C(121), UINT8_C( 57), UINT8_C(209) },
      { UINT8_C(251), UINT8_C( 20), UINT8_C( 20), UINT8_C( 71), UINT8_C(238), UINT8_C(237), UINT8_C( 57), UINT8_C( 50) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX } },
    { { UINT8_C( 88), UINT8_C(252), UINT8_C( 56), UINT8_C(235), UINT8_C( 74), UINT8_C(219), UINT8_C(253), UINT8_C(113) },
      { UINT8_C(231), UINT8_C(252), UINT8_C(253), UINT8_C( 44), UINT8_C(117), UINT8_C(192), UINT8_C(253), UINT8_C(113) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0) } },
    { { UINT8_C(156), UINT8_C(235), UINT8_C( 31), UINT8_C( 93), UINT8_C(242), UINT8_C(241), UINT8_C(223), UINT8_C(217) },
      { UINT8_C(  5), UINT8_C( 23), UINT8_C( 31), UINT8_C( 80), UINT8_C(242), UINT8_C(204), UINT8_C(175), UINT8_C(217) },
      {    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0) } },
    { { UINT8_C( 21), UINT8_C(103), UINT8_C(  4), UINT8_C( 21), UINT8_C( 30), UINT8_C(250), UINT8_C(253), UINT8_C(245) },
      { UINT8_C(229), UINT8_C( 45), UINT8_C( 83), UINT8_C(193), UINT8_C( 30), UINT8_C( 50), UINT8_C(244), UINT8_C( 35) },
      { UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x8_t a = simde_vld1_u8(test_vec[i].a);
    simde_uint8x8_t b = simde_vld1_u8(test_vec[i].b);
    simde_uint8x8_t r = simde_vcgt_u8(a, b);

    simde_test_arm_neon_assert_equal_u8x8(r, simde_vld1_u8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8x8_private a_ = simde_uint8x8_to_private(simde_test_arm_neon_random_u8x8());
    simde_uint8x8_private b_ = simde_uint8x8_to_private(simde_test_arm_neon_random_u8x8());

    /* Make some equal which is unlikely to happen by accident. */
    for (size_t j = 0 ; j < (sizeof(a_.values) / sizeof(a_.values[0])) ; j++) {
      if (rand() < (RAND_MAX / 3)) a_.values[j] = b_.values[j];
    }

    simde_uint8x8_t a = simde_uint8x8_from_private(a_);
    simde_uint8x8_t b = simde_uint8x8_from_private(b_);

    simde_uint8x8_t r = simde_vcgt_u8(a, b);

    simde_test_arm_neon_write_u8x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcgt_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[4];
    uint16_t b[4];
    uint16_t r[4];
  } test_vec[] = {
    { { UINT16_C(62314), UINT16_C(34517), UINT16_C(26000), UINT16_C(17193) },
      { UINT16_C(62314), UINT16_C(17113), UINT16_C(63969), UINT16_C(44359) },
      { UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    0) } },
    { { UINT16_C(49883), UINT16_C(62505), UINT16_C(16661), UINT16_C(46714) },
      { UINT16_C( 8635), UINT16_C(62505), UINT16_C(65062), UINT16_C(46714) },
      {      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { { UINT16_C(11660), UINT16_C(26765), UINT16_C(22731), UINT16_C(   37) },
      { UINT16_C(11660), UINT16_C(26765), UINT16_C(62959), UINT16_C( 1070) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { { UINT16_C(16643), UINT16_C(39505), UINT16_C(24608), UINT16_C(33608) },
      { UINT16_C(16643), UINT16_C(39505), UINT16_C(25108), UINT16_C(57106) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { { UINT16_C(20518), UINT16_C(21678), UINT16_C(56418), UINT16_C(39000) },
      { UINT16_C(20518), UINT16_C(37257), UINT16_C(28529), UINT16_C(37154) },
      { UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX } },
    { { UINT16_C(26284), UINT16_C( 7369), UINT16_C(30701), UINT16_C(33439) },
      { UINT16_C(32695), UINT16_C( 7369), UINT16_C(30701), UINT16_C(20336) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX } },
    { { UINT16_C(28952), UINT16_C(35339), UINT16_C(11744), UINT16_C(24324) },
      { UINT16_C(12440), UINT16_C(17538), UINT16_C(61335), UINT16_C(24324) },
      {      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0) } },
    { { UINT16_C(43811), UINT16_C(38128), UINT16_C(45858), UINT16_C(39198) },
      { UINT16_C(18299), UINT16_C(38128), UINT16_C(64441), UINT16_C(39198) },
      {      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4_t a = simde_vld1_u16(test_vec[i].a);
    simde_uint16x4_t b = simde_vld1_u16(test_vec[i].b);
    simde_uint16x4_t r = simde_vcgt_u16(a, b);

    simde_test_arm_neon_assert_equal_u16x4(r, simde_vld1_u16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x4_private a_ = simde_uint16x4_to_private(simde_test_arm_neon_random_u16x4());
    simde_uint16x4_private b_ = simde_uint16x4_to_private(simde_test_arm_neon_random_u16x4());

    /* Make some equal which is unlikely to happen by accident. */
    for (size_t j = 0 ; j < (sizeof(a_.values) / sizeof(a_.values[0])) ; j++) {
      if (rand() < (RAND_MAX / 3)) a_.values[j] = b_.values[j];
    }

    simde_uint16x4_t a = simde_uint16x4_from_private(a_);
    simde_uint16x4_t b = simde_uint16x4_from_private(b_);

    simde_uint16x4_t r = simde_vcgt_u16(a, b);

    simde_test_arm_neon_write_u16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcgt_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[2];
    uint32_t b[2];
    uint32_t r[2];
  } test_vec[] = {
    { { UINT32_C( 508093940), UINT32_C(3751220310) },
      { UINT32_C(3608123784), UINT32_C(3751220310) },
      { UINT32_C(         0), UINT32_C(         0) } },
    { { UINT32_C(1058673663), UINT32_C( 337578444) },
      { UINT32_C( 974431602), UINT32_C( 337578444) },
      {           UINT32_MAX, UINT32_C(         0) } },
    { { UINT32_C(2494528012), UINT32_C(1768668691) },
      { UINT32_C(1313342162), UINT32_C(3026274202) },
      {           UINT32_MAX, UINT32_C(         0) } },
    { { UINT32_C(3432578980), UINT32_C(2229246904) },
      { UINT32_C(3432578980), UINT32_C(1598465200) },
      { UINT32_C(         0),           UINT32_MAX } },
    { { UINT32_C(3656687698), UINT32_C(1077807782) },
      { UINT32_C(3656687698), UINT32_C(3219859256) },
      { UINT32_C(         0), UINT32_C(         0) } },
    { { UINT32_C(2612728163), UINT32_C( 742381674) },
      { UINT32_C(2612728163), UINT32_C( 742381674) },
      { UINT32_C(         0), UINT32_C(         0) } },
    { { UINT32_C( 228543809), UINT32_C( 414841585) },
      { UINT32_C( 228543809), UINT32_C( 414841585) },
      { UINT32_C(         0), UINT32_C(         0) } },
    { { UINT32_C( 476911187), UINT32_C(1104640982) },
      { UINT32_C( 476911187), UINT32_C( 539206907) },
      { UINT32_C(         0),           UINT32_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2_t a = simde_vld1_u32(test_vec[i].a);
    simde_uint32x2_t b = simde_vld1_u32(test_vec[i].b);
    simde_uint32x2_t r = simde_vcgt_u32(a, b);

    simde_test_arm_neon_assert_equal_u32x2(r, simde_vld1_u32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x2_private a_ = simde_uint32x2_to_private(simde_test_arm_neon_random_u32x2());
    simde_uint32x2_private b_ = simde_uint32x2_to_private(simde_test_arm_neon_random_u32x2());

    /* Make some equal which is unlikely to happen by accident. */
    for (size_t j = 0 ; j < (sizeof(a_.values) / sizeof(a_.values[0])) ; j++) {
      if (rand() < (RAND_MAX / 3)) a_.values[j] = b_.values[j];
    }

    simde_uint32x2_t a = simde_uint32x2_from_private(a_);
    simde_uint32x2_t b = simde_uint32x2_from_private(b_);

    simde_uint32x2_t r = simde_vcgt_u32(a, b);

    simde_test_arm_neon_write_u32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcgt_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a[1];
    uint64_t b[1];
    uint64_t r[1];
  } test_vec[] = {
    { { UINT64_C(10149447861172126575) },
      { UINT64_C(14973029270786375072) },
      { UINT64_C(                   0) } },
    { { UINT64_C(  188873460352155308) },
      { UINT64_C(15677533420196890137) },
      { UINT64_C(                   0) } },
    { { UINT64_C( 3685917520124110800) },
      { UINT64_C(13765571949920383634) },
      { UINT64_C(                   0) } },
    { { UINT64_C( 5874391744743614816) },
      { UINT64_C(15891911110410574633) },
      { UINT64_C(                   0) } },
    { { UINT64_C(17952937805671436476) },
      { UINT64_C(17952937805671436476) },
      { UINT64_C(                   0) } },
    { { UINT64_C(10504581769340920869) },
      { UINT64_C(16663533674779229056) },
      { UINT64_C(                   0) } },
    { { UINT64_C(13618227777779952285) },
      { UINT64_C(16914102683313556847) },
      { UINT64_C(                   0) } },
    { { UINT64_C(16927016630319800422) },
      { UINT64_C(15186205456682811618) },
      {                    UINT64_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x1_t a = simde_vld1_u64(test_vec[i].a);
    simde_uint64x1_t b = simde_vld1_u64(test_vec[i].b);
    simde_uint64x1_t r = simde_vcgt_u64(a, b);

    simde_test_arm_neon_assert_equal_u64x1(r, simde_vld1_u64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint64x1_private a_ = simde_uint64x1_to_private(simde_test_arm_neon_random_u64x1());
    simde_uint64x1_private b_ = simde_uint64x1_to_private(simde_test_arm_neon_random_u64x1());

    /* Make some equal which is unlikely to happen by accident. */
    for (size_t j = 0 ; j < (sizeof(a_.values) / sizeof(a_.values[0])) ; j++) {
      if (rand() < (RAND_MAX / 3)) a_.values[j] = b_.values[j];
    }

    simde_uint64x1_t a = simde_uint64x1_from_private(a_);
    simde_uint64x1_t b = simde_uint64x1_from_private(b_);

    simde_uint64x1_t r = simde_vcgt_u64(a, b);

    simde_test_arm_neon_write_u64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x1(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcgtq_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a[4];
    simde_float32 b[4];
    uint32_t r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -259.46), SIMDE_FLOAT32_C(  -774.65), SIMDE_FLOAT32_C(   628.16), SIMDE_FLOAT32_C(  -992.75) },
      { SIMDE_FLOAT32_C(  -259.46), SIMDE_FLOAT32_C(  -774.65), SIMDE_FLOAT32_C(   628.16), SIMDE_FLOAT32_C(  -707.60) },
      { UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0) } },
    { { SIMDE_FLOAT32_C(   127.08), SIMDE_FLOAT32_C(    51.79), SIMDE_FLOAT32_C(   966.55), SIMDE_FLOAT32_C(   -31.51) },
      { SIMDE_FLOAT32_C(    36.37), SIMDE_FLOAT32_C(    73.30), SIMDE_FLOAT32_C(   646.26), SIMDE_FLOAT32_C(   -31.51) },
      {           UINT32_MAX, UINT32_C(         0),           UINT32_MAX, UINT32_C(         0) } },
    { { SIMDE_FLOAT32_C(   466.70), SIMDE_FLOAT32_C(   282.12), SIMDE_FLOAT32_C(  -570.04), SIMDE_FLOAT32_C(  -866.16) },
      { SIMDE_FLOAT32_C(  -215.26), SIMDE_FLOAT32_C(  -475.25), SIMDE_FLOAT32_C(  -570.04), SIMDE_FLOAT32_C(  -866.16) },
      {           UINT32_MAX,           UINT32_MAX, UINT32_C(         0), UINT32_C(         0) } },
    { { SIMDE_FLOAT32_C(  -574.22), SIMDE_FLOAT32_C(    -2.51), SIMDE_FLOAT32_C(  -310.68), SIMDE_FLOAT32_C(  -504.85) },
      { SIMDE_FLOAT32_C(  -574.22), SIMDE_FLOAT32_C(    -2.51), SIMDE_FLOAT32_C(  -697.28), SIMDE_FLOAT32_C(   552.86) },
      { UINT32_C(         0), UINT32_C(         0),           UINT32_MAX, UINT32_C(         0) } },
    { { SIMDE_FLOAT32_C(   342.57), SIMDE_FLOAT32_C(   504.54), SIMDE_FLOAT32_C(   219.24), SIMDE_FLOAT32_C(  -326.34) },
      { SIMDE_FLOAT32_C(  -190.21), SIMDE_FLOAT32_C(   504.54), SIMDE_FLOAT32_C(   219.24), SIMDE_FLOAT32_C(  -723.52) },
      {           UINT32_MAX, UINT32_C(         0), UINT32_C(         0),           UINT32_MAX } },
    { { SIMDE_FLOAT32_C(  -280.95), SIMDE_FLOAT32_C(   -30.91), SIMDE_FLOAT32_C(   705.25), SIMDE_FLOAT32_C(  -225.48) },
      { SIMDE_FLOAT32_C(  -240.87), SIMDE_FLOAT32_C(   846.33), SIMDE_FLOAT32_C(  -227.65), SIMDE_FLOAT32_C(  -225.48) },
      { UINT32_C(         0), UINT32_C(         0),           UINT32_MAX, UINT32_C(         0) } },
    { { SIMDE_FLOAT32_C(   841.66), SIMDE_FLOAT32_C(   572.39), SIMDE_FLOAT32_C(   594.22), SIMDE_FLOAT32_C(  -491.55) },
      { SIMDE_FLOAT32_C(   841.66), SIMDE_FLOAT32_C(   110.40), SIMDE_FLOAT32_C(   594.11), SIMDE_FLOAT32_C(   184.23) },
      { UINT32_C(         0),           UINT32_MAX,           UINT32_MAX, UINT32_C(         0) } },
    { { SIMDE_FLOAT32_C(   152.78), SIMDE_FLOAT32_C(    77.13), SIMDE_FLOAT32_C(   510.85), SIMDE_FLOAT32_C(   939.45) },
      { SIMDE_FLOAT32_C(   271.42), SIMDE_FLOAT32_C(   898.23), SIMDE_FLOAT32_C(   510.85), SIMDE_FLOAT32_C(   990.47) },
      { UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_float32x4_t b = simde_vld1q_f32(test_vec[i].b);
    simde_uint32x4_t r = simde_vcgtq_f32(a, b);

    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x4_private a_ = simde_float32x4_to_private(simde_test_arm_neon_random_f32x4(-1000.0, 1000.0));
    simde_float32x4_private b_ = simde_float32x4_to_private(simde_test_arm_neon_random_f32x4(-1000.0, 1000.0));

    /* Make some equal which is unlikely to happen by accident. */
    for (size_t j = 0 ; j < (sizeof(a_.values) / sizeof(a_.values[0])) ; j++) {
      if (rand() < (RAND_MAX / 3)) a_.values[j] = b_.values[j];
    }

    simde_float32x4_t a = simde_float32x4_from_private(a_);
    simde_float32x4_t b = simde_float32x4_from_private(b_);

    simde_uint32x4_t r = simde_vcgtq_f32(a, b);

    simde_test_arm_neon_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcgtq_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 a[2];
    simde_float64 b[2];
    uint64_t r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(  -768.50), SIMDE_FLOAT64_C(   422.43) },
      { SIMDE_FLOAT64_C(  -768.50), SIMDE_FLOAT64_C(   422.43) },
      { UINT64_C(                   0), UINT64_C(                   0) } },
    { { SIMDE_FLOAT64_C(  -374.33), SIMDE_FLOAT64_C(   705.75) },
      { SIMDE_FLOAT64_C(  -374.33), SIMDE_FLOAT64_C(   418.62) },
      { UINT64_C(                   0),                    UINT64_MAX } },
    { { SIMDE_FLOAT64_C(   918.51), SIMDE_FLOAT64_C(   204.70) },
      { SIMDE_FLOAT64_C(   951.02), SIMDE_FLOAT64_C(   727.05) },
      { UINT64_C(                   0), UINT64_C(                   0) } },
    { { SIMDE_FLOAT64_C(   838.32), SIMDE_FLOAT64_C(   700.06) },
      { SIMDE_FLOAT64_C(   987.36), SIMDE_FLOAT64_C(  -654.73) },
      { UINT64_C(                   0),                    UINT64_MAX } },
    { { SIMDE_FLOAT64_C(   461.26), SIMDE_FLOAT64_C(  -727.20) },
      { SIMDE_FLOAT64_C(   461.26), SIMDE_FLOAT64_C(  -199.48) },
      { UINT64_C(                   0), UINT64_C(                   0) } },
    { { SIMDE_FLOAT64_C(   305.36), SIMDE_FLOAT64_C(   231.22) },
      { SIMDE_FLOAT64_C(   305.36), SIMDE_FLOAT64_C(  -216.90) },
      { UINT64_C(                   0),                    UINT64_MAX } },
    { { SIMDE_FLOAT64_C(   305.13), SIMDE_FLOAT64_C(  -986.91) },
      { SIMDE_FLOAT64_C(   240.23), SIMDE_FLOAT64_C(   930.80) },
      {                    UINT64_MAX, UINT64_C(                   0) } },
    { { SIMDE_FLOAT64_C(   601.87), SIMDE_FLOAT64_C(   350.21) },
      { SIMDE_FLOAT64_C(  -113.14), SIMDE_FLOAT64_C(   552.89) },
      {                    UINT64_MAX, UINT64_C(                   0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2_t a = simde_vld1q_f64(test_vec[i].a);
    simde_float64x2_t b = simde_vld1q_f64(test_vec[i].b);
    simde_uint64x2_t r = simde_vcgtq_f64(a, b);

    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x2_private a_ = simde_float64x2_to_private(simde_test_arm_neon_random_f64x2(-1000.0, 1000.0));
    simde_float64x2_private b_ = simde_float64x2_to_private(simde_test_arm_neon_random_f64x2(-1000.0, 1000.0));

    /* Make some equal which is unlikely to happen by accident. */
    for (size_t j = 0 ; j < (sizeof(a_.values) / sizeof(a_.values[0])) ; j++) {
      if (rand() < (RAND_MAX / 3)) a_.values[j] = b_.values[j];
    }

    simde_float64x2_t a = simde_float64x2_from_private(a_);
    simde_float64x2_t b = simde_float64x2_from_private(b_);

    simde_uint64x2_t r = simde_vcgtq_f64(a, b);

    simde_test_arm_neon_write_f64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcgtq_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[16];
    int8_t b[16];
    uint8_t r[16];
  } test_vec[] = {
    { { -INT8_C(   5),  INT8_C(  60), -INT8_C(  67), -INT8_C(  35),  INT8_C(  16), -INT8_C(  24),  INT8_C(  30),  INT8_C(  95),
        -INT8_C(  46), -INT8_C(  88), -INT8_C(  97), -INT8_C( 108), -INT8_C(  22), -INT8_C( 109), -INT8_C(  32),  INT8_C(  19) },
      { -INT8_C(   5),  INT8_C(  98), -INT8_C( 119), -INT8_C(  49),  INT8_C(  63),  INT8_C( 120),  INT8_C(  30), -INT8_C( 127),
         INT8_C(  47),  INT8_C(   6), -INT8_C(  30), -INT8_C( 108), -INT8_C(  42),  INT8_C(  17),  INT8_C( 101), -INT8_C(  63) },
      { UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX } },
    { {  INT8_C(  39),  INT8_C(  20), -INT8_C(  63), -INT8_C(  95), -INT8_C(  37), -INT8_C(  40),  INT8_C(  34),  INT8_C(  11),
        -INT8_C(  34),  INT8_C(   5), -INT8_C(  97), -INT8_C(  76),  INT8_C(  22),  INT8_C(   5),  INT8_C( 118),  INT8_C(  99) },
      {  INT8_C(  39),  INT8_C(  20), -INT8_C(  63),  INT8_C(  50),  INT8_C(  73),  INT8_C( 126),  INT8_C(  15),  INT8_C(  38),
        -INT8_C(  38),  INT8_C(  47), -INT8_C(  19), -INT8_C(  54),  INT8_C(  47), -INT8_C(  57), -INT8_C(  75), -INT8_C( 110) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),
           UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX } },
    { { -INT8_C(  35), -INT8_C( 107),  INT8_C(  16),  INT8_C(  37),  INT8_C(  19),  INT8_C(  31), -INT8_C(  44), -INT8_C(  18),
         INT8_C(  79),  INT8_C(  36), -INT8_C(  72),  INT8_C(  51), -INT8_C( 119),  INT8_C(  58),  INT8_C(  16), -INT8_C(  76) },
      { -INT8_C(  35),  INT8_C(  68), -INT8_C(  69),  INT8_C(  37), -INT8_C( 102), -INT8_C(  52),  INT8_C(  74), -INT8_C(  11),
         INT8_C( 125),  INT8_C(  36),  INT8_C( 102),  INT8_C(  51),  INT8_C( 116),  INT8_C(  58),  INT8_C(  17), -INT8_C(  39) },
      { UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) } },
    { {  INT8_C(  98),  INT8_C(  62), -INT8_C(   6), -INT8_C(   4), -INT8_C(  29),  INT8_C(  69), -INT8_C(  15),  INT8_C(  96),
        -INT8_C(  95), -INT8_C(  92), -INT8_C( 108), -INT8_C( 103), -INT8_C( 110), -INT8_C(  91),  INT8_C( 110),  INT8_C(  37) },
      { -INT8_C(  58),  INT8_C(  62),  INT8_C(  69),  INT8_C(   6), -INT8_C( 103),  INT8_C(  23), -INT8_C( 106), -INT8_C(  73),
        -INT8_C(  95), -INT8_C(  92),  INT8_C(  94), -INT8_C( 103), -INT8_C(  62), -INT8_C(  71),  INT8_C( 110),  INT8_C(  37) },
      {    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) } },
    { { -INT8_C(  22),  INT8_C(  92),  INT8_C(  25), -INT8_C( 124), -INT8_C(  69), -INT8_C(  81), -INT8_C( 110),  INT8_C(  92),
         INT8_C(  83), -INT8_C( 103), -INT8_C(  11),  INT8_C(  21),  INT8_C(  52),  INT8_C(  52), -INT8_C(  17),  INT8_C(  34) },
      { -INT8_C(  52),  INT8_C(  92), -INT8_C(  43),  INT8_C( 122),  INT8_C( 111), -INT8_C(  23), -INT8_C( 110), -INT8_C(  39),
        -INT8_C( 112), -INT8_C( 121), -INT8_C(  42), -INT8_C(  35),  INT8_C(  52),  INT8_C(  52), -INT8_C(  17),  INT8_C(  30) },
      {    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX } },
    { {  INT8_C(  15), -INT8_C(  99),  INT8_C( 117),  INT8_C(  37), -INT8_C(  86),  INT8_C(  33), -INT8_C(   1), -INT8_C(  15),
         INT8_C(  73), -INT8_C(  43),  INT8_C(  23), -INT8_C( 111),  INT8_C(   9),  INT8_C(   7), -INT8_C(   5),  INT8_C(   2) },
      {  INT8_C(  15), -INT8_C(  99),  INT8_C( 117), -INT8_C(  57),  INT8_C( 123),  INT8_C( 101), -INT8_C(  47), -INT8_C(  15),
         INT8_C(  73), -INT8_C(  15), -INT8_C(  70), -INT8_C( 111),  INT8_C(  76), -INT8_C(  90), -INT8_C(  90),  INT8_C(   2) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0) } },
    { {  INT8_C( 120),  INT8_C(  93),  INT8_C(  64), -INT8_C(  50), -INT8_C(  62),  INT8_C(   4), -INT8_C(  52), -INT8_C(  99),
         INT8_C(   3), -INT8_C(  89), -INT8_C(  94),  INT8_C(  79),  INT8_C(  64),  INT8_C(  67),  INT8_C(  74), -INT8_C(  89) },
      {  INT8_C( 120),  INT8_C( 122), -INT8_C(  72), -INT8_C(  50), -INT8_C(  95),  INT8_C(   4), -INT8_C(  52), -INT8_C(  99),
         INT8_C( 103), -INT8_C(  89), -INT8_C(  94), -INT8_C(  47),  INT8_C( 125), -INT8_C( 118),  INT8_C(  74), -INT8_C(  15) },
      { UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0) } },
    { { -INT8_C(  68), -INT8_C(   6), -INT8_C(  38),  INT8_C(  93), -INT8_C(   2), -INT8_C(  89), -INT8_C(   6),  INT8_C( 101),
         INT8_C(  78), -INT8_C( 100),  INT8_C(  54), -INT8_C(  52),  INT8_C(  38), -INT8_C( 127), -INT8_C(  67),  INT8_C(  13) },
      {  INT8_C(  12), -INT8_C( 100), -INT8_C(  74), -INT8_C(  87),  INT8_C(  92),  INT8_C( 107),  INT8_C(  73), -INT8_C(  74),
        -INT8_C(  68),  INT8_C(  57),  INT8_C(  80),  INT8_C(  81),  INT8_C( 123), -INT8_C( 110),  INT8_C(  93),  INT8_C(  55) },
      { UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,
           UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16_t a = simde_vld1q_s8(test_vec[i].a);
    simde_int8x16_t b = simde_vld1q_s8(test_vec[i].b);
    simde_uint8x16_t r = simde_vcgtq_s8(a, b);

    simde_test_arm_neon_assert_equal_u8x16(r, simde_vld1q_u8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x16_private a_ = simde_int8x16_to_private(simde_test_arm_neon_random_i8x16());
    simde_int8x16_private b_ = simde_int8x16_to_private(simde_test_arm_neon_random_i8x16());

    /* Make some equal which is unlikely to happen by accident. */
    for (size_t j = 0 ; j < (sizeof(a_.values) / sizeof(a_.values[0])) ; j++) {
      if (rand() < (RAND_MAX / 3)) a_.values[j] = b_.values[j];
    }

    simde_int8x16_t a = simde_int8x16_from_private(a_);
    simde_int8x16_t b = simde_int8x16_from_private(b_);

    simde_uint8x16_t r = simde_vcgtq_s8(a, b);

    simde_test_arm_neon_write_i8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcgtq_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[8];
    int16_t b[8];
    uint16_t r[8];
  } test_vec[] = {
    { {  INT16_C( 31254), -INT16_C(  3947),  INT16_C( 22993), -INT16_C(   590),  INT16_C( 14528), -INT16_C( 28835),  INT16_C( 23061), -INT16_C(  6038) },
      {  INT16_C( 23834), -INT16_C(  3947), -INT16_C( 11322), -INT16_C( 18532),  INT16_C( 14528),  INT16_C(  5233),  INT16_C( 23061),  INT16_C( 11175) },
      {      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { {  INT16_C(   391), -INT16_C( 19446), -INT16_C( 32485), -INT16_C(  3867),  INT16_C( 12754), -INT16_C( 26416),  INT16_C( 14703), -INT16_C(  2305) },
      { -INT16_C( 15964), -INT16_C( 17703), -INT16_C( 32485), -INT16_C(  3867),  INT16_C( 20950), -INT16_C( 31594),  INT16_C( 14703), -INT16_C(  2305) },
      {      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    0) } },
    { { -INT16_C( 20615),  INT16_C( 32232),  INT16_C( 14363), -INT16_C( 16574),  INT16_C(  7417),  INT16_C(  5497),  INT16_C( 24477), -INT16_C( 32306) },
      { -INT16_C( 25680),  INT16_C(  8183), -INT16_C(  2092),  INT16_C(  3861), -INT16_C( 16384),  INT16_C( 32270), -INT16_C(  4856), -INT16_C( 32306) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0) } },
    { { -INT16_C(  4003), -INT16_C(   806),  INT16_C(   847), -INT16_C(   147),  INT16_C( 25758),  INT16_C( 29214),  INT16_C( 13403),  INT16_C(  6712) },
      { -INT16_C( 28428), -INT16_C(   806), -INT16_C( 22147),  INT16_C(  6781),  INT16_C( 31840),  INT16_C( 20433),  INT16_C( 18621),  INT16_C(  6712) },
      {      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    0) } },
    { { -INT16_C( 22811), -INT16_C( 32048), -INT16_C( 13350),  INT16_C( 18076),  INT16_C( 30555),  INT16_C( 30926),  INT16_C( 22065), -INT16_C( 32525) },
      { -INT16_C( 15163), -INT16_C( 32048),  INT16_C(  2061),  INT16_C( 18076), -INT16_C( 20417),  INT16_C( 30926),  INT16_C( 22065),  INT16_C(  5712) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { {  INT16_C( 29292), -INT16_C( 29542), -INT16_C( 29253), -INT16_C( 14699), -INT16_C(  8879), -INT16_C(  4962), -INT16_C( 24859),  INT16_C(  9380) },
      {  INT16_C( 29518),  INT16_C( 32669), -INT16_C(  4663), -INT16_C( 14699), -INT16_C(  4729), -INT16_C(  4962),  INT16_C( 17633),  INT16_C( 19885) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { { -INT16_C( 13599), -INT16_C( 15669),  INT16_C( 30990), -INT16_C( 15088),  INT16_C( 27548), -INT16_C( 27338), -INT16_C(  2984), -INT16_C(  8404) },
      { -INT16_C( 13599), -INT16_C( 15669),  INT16_C( 30990), -INT16_C( 15088), -INT16_C(  5440), -INT16_C( 27338),  INT16_C( 10449), -INT16_C( 27205) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX } },
    { { -INT16_C(  5257), -INT16_C( 12438), -INT16_C( 26913), -INT16_C( 16210),  INT16_C(  8515),  INT16_C( 28290), -INT16_C( 27917), -INT16_C( 19661) },
      {  INT16_C( 27260),  INT16_C( 19784),  INT16_C(   914), -INT16_C( 21022),  INT16_C(  8515), -INT16_C( 21670), -INT16_C(  6355), -INT16_C( 23120) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_int16x8_t b = simde_vld1q_s16(test_vec[i].b);
    simde_uint16x8_t r = simde_vcgtq_s16(a, b);

    simde_test_arm_neon_assert_equal_u16x8(r, simde_vld1q_u16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x8_private a_ = simde_int16x8_to_private(simde_test_arm_neon_random_i16x8());
    simde_int16x8_private b_ = simde_int16x8_to_private(simde_test_arm_neon_random_i16x8());

    /* Make some equal which is unlikely to happen by accident. */
    for (size_t j = 0 ; j < (sizeof(a_.values) / sizeof(a_.values[0])) ; j++) {
      if (rand() < (RAND_MAX / 3)) a_.values[j] = b_.values[j];
    }

    simde_int16x8_t a = simde_int16x8_from_private(a_);
    simde_int16x8_t b = simde_int16x8_from_private(b_);

    simde_uint16x8_t r = simde_vcgtq_s16(a, b);

    simde_test_arm_neon_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcgtq_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[4];
    int32_t b[4];
    uint32_t r[4];
  } test_vec[] = {
    { {  INT32_C(   492300188), -INT32_C(  1956120182), -INT32_C(  1955357078), -INT32_C(  1876357680) },
      {  INT32_C(  2138637092),  INT32_C(   976653345),  INT32_C(  1546898711), -INT32_C(   908456404) },
      { UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0) } },
    { { -INT32_C(  1777644245),  INT32_C(  1606736946), -INT32_C(  1353954677),  INT32_C(  1865336142) },
      {  INT32_C(  1755931985),  INT32_C(  1606736946), -INT32_C(   550985750), -INT32_C(    60879151) },
      { UINT32_C(         0), UINT32_C(         0), UINT32_C(         0),           UINT32_MAX } },
    { {  INT32_C(  1946465512),  INT32_C(  1277382910),  INT32_C(  1723552277), -INT32_C(   372284233) },
      {  INT32_C(   726176577),  INT32_C(    51081266), -INT32_C(   620729729), -INT32_C(  1138519340) },
      {           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX } },
    { {  INT32_C(  2123049471),  INT32_C(  1576160678),  INT32_C(  1680047133), -INT32_C(  2028040363) },
      {  INT32_C(  2123049471),  INT32_C(  1733921683),  INT32_C(  1680047133),  INT32_C(   447304867) },
      { UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0) } },
    { {  INT32_C(  1785485389), -INT32_C(  1356074662), -INT32_C(  2143860352),  INT32_C(   100582002) },
      {  INT32_C(  1785485389),  INT32_C(  2026803412), -INT32_C(  1936558108),  INT32_C(   970602930) },
      { UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0) } },
    { {  INT32_C(  1075469148), -INT32_C(  2066961198), -INT32_C(  1212242203), -INT32_C(  1567830835) },
      {  INT32_C(  1075469148), -INT32_C(  2066961198), -INT32_C(  1212242203), -INT32_C(  1578880981) },
      { UINT32_C(         0), UINT32_C(         0), UINT32_C(         0),           UINT32_MAX } },
    { { -INT32_C(  1475342381),  INT32_C(  1388998533), -INT32_C(  1745594821), -INT32_C(   813977860) },
      { -INT32_C(  1610046533),  INT32_C(  1951974985), -INT32_C(   988398345), -INT32_C(   813977860) },
      {           UINT32_MAX, UINT32_C(         0), UINT32_C(         0), UINT32_C(         0) } },
    { {  INT32_C(   915751419),  INT32_C(  1238272663),  INT32_C(  1405986200), -INT32_C(  1829448375) },
      { -INT32_C(  1828238180), -INT32_C(  2074600056), -INT32_C(  1990994741),  INT32_C(  1523370591) },
      {           UINT32_MAX,           UINT32_MAX,           UINT32_MAX, UINT32_C(         0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int32x4_t b = simde_vld1q_s32(test_vec[i].b);
    simde_uint32x4_t r = simde_vcgtq_s32(a, b);

    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x4_private a_ = simde_int32x4_to_private(simde_test_arm_neon_random_i32x4());
    simde_int32x4_private b_ = simde_int32x4_to_private(simde_test_arm_neon_random_i32x4());

    /* Make some equal which is unlikely to happen by accident. */
    for (size_t j = 0 ; j < (sizeof(a_.values) / sizeof(a_.values[0])) ; j++) {
      if (rand() < (RAND_MAX / 3)) a_.values[j] = b_.values[j];
    }

    simde_int32x4_t a = simde_int32x4_from_private(a_);
    simde_int32x4_t b = simde_int32x4_from_private(b_);

    simde_uint32x4_t r = simde_vcgtq_s32(a, b);

    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcgtq_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a[2];
    int64_t b[2];
    uint64_t r[2];
  } test_vec[] = {
    { { -INT64_C(  502189528637050139),  INT64_C( 4939785098016854380) },
      {  INT64_C( 4830541158354021746),  INT64_C( 4939785098016854380) },
      { UINT64_C(                   0), UINT64_C(                   0) } },
    { {  INT64_C( 7537734782517829395),  INT64_C( 4887792816035170112) },
      { -INT64_C( 4674675188186846458), -INT64_C( 2819539494663585767) },
      {                    UINT64_MAX,                    UINT64_MAX } },
    { {  INT64_C( 1601627469969290137), -INT64_C( 3511530056025063164) },
      {  INT64_C( 1601627469969290137), -INT64_C( 3920686018976416059) },
      { UINT64_C(                   0),                    UINT64_MAX } },
    { { -INT64_C( 2941252623903311016),  INT64_C(  622335687481439083) },
      {  INT64_C( 9002111178501477557), -INT64_C( 1938790237255187312) },
      { UINT64_C(                   0),                    UINT64_MAX } },
    { {  INT64_C( 5671339170748503635), -INT64_C( 1924727269611686317) },
      { -INT64_C( 7377069698328644371),  INT64_C( 7297631376879201416) },
      {                    UINT64_MAX, UINT64_C(                   0) } },
    { {  INT64_C(   22929999772477670), -INT64_C( 4077467447542804373) },
      { -INT64_C( 3057186358420727097), -INT64_C( 1146248527329188783) },
      {                    UINT64_MAX, UINT64_C(                   0) } },
    { {  INT64_C( 1883303849582922475), -INT64_C( 3182209124792343854) },
      {  INT64_C( 1883303849582922475), -INT64_C( 6358821967087326098) },
      { UINT64_C(                   0),                    UINT64_MAX } },
    { {  INT64_C( 2761376618429519235), -INT64_C( 6174449215856279780) },
      {  INT64_C( 5000006545298775061), -INT64_C( 6174449215856279780) },
      { UINT64_C(                   0), UINT64_C(                   0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);
    simde_int64x2_t b = simde_vld1q_s64(test_vec[i].b);
    simde_uint64x2_t r = simde_vcgtq_s64(a, b);

    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int64x2_private a_ = simde_int64x2_to_private(simde_test_arm_neon_random_i64x2());
    simde_int64x2_private b_ = simde_int64x2_to_private(simde_test_arm_neon_random_i64x2());

    /* Make some equal which is unlikely to happen by accident. */
    for (size_t j = 0 ; j < (sizeof(a_.values) / sizeof(a_.values[0])) ; j++) {
      if (rand() < (RAND_MAX / 3)) a_.values[j] = b_.values[j];
    }

    simde_int64x2_t a = simde_int64x2_from_private(a_);
    simde_int64x2_t b = simde_int64x2_from_private(b_);

    simde_uint64x2_t r = simde_vcgtq_s64(a, b);

    simde_test_arm_neon_write_i64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcgtq_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t a[16];
    uint8_t b[16];
    uint8_t r[16];
  } test_vec[] = {
    { { UINT8_C(254), UINT8_C(227), UINT8_C(203), UINT8_C(182), UINT8_C( 87), UINT8_C( 85), UINT8_C( 43), UINT8_C( 21),
        UINT8_C( 50), UINT8_C(171), UINT8_C(226), UINT8_C( 87), UINT8_C( 42), UINT8_C( 18), UINT8_C(241), UINT8_C( 41) },
      {    UINT8_MAX, UINT8_C( 57), UINT8_C(226), UINT8_C(182), UINT8_C(191), UINT8_C(155), UINT8_C( 33), UINT8_C(147),
        UINT8_C( 44), UINT8_C(101), UINT8_C(226), UINT8_C(119), UINT8_C( 42), UINT8_C( 18), UINT8_C(156), UINT8_C( 41) },
      { UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),
           UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0) } },
    { { UINT8_C(113), UINT8_C( 73), UINT8_C(  0), UINT8_C( 74), UINT8_C(228), UINT8_C( 94), UINT8_C(196), UINT8_C( 17),
        UINT8_C(135), UINT8_C(129), UINT8_C(136), UINT8_C( 80), UINT8_C(185), UINT8_C( 37), UINT8_C(218), UINT8_C(174) },
      { UINT8_C(141), UINT8_C(100), UINT8_C(251), UINT8_C( 74), UINT8_C( 26), UINT8_C( 94), UINT8_C( 58), UINT8_C(123),
        UINT8_C(  6), UINT8_C(129), UINT8_C(134), UINT8_C( 80), UINT8_C(186), UINT8_C(237), UINT8_C(154), UINT8_C( 43) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),
           UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX } },
    { { UINT8_C( 51), UINT8_C( 42), UINT8_C(140), UINT8_C(206), UINT8_C(207), UINT8_C(235), UINT8_C(200), UINT8_C(142),
        UINT8_C(107), UINT8_C(  4), UINT8_C( 22), UINT8_C( 38), UINT8_C(211), UINT8_C(120), UINT8_C( 82), UINT8_C(113) },
      { UINT8_C( 18), UINT8_C(174), UINT8_C(140), UINT8_C(206), UINT8_C(207), UINT8_C(183), UINT8_C( 16), UINT8_C(150),
        UINT8_C(107), UINT8_C(  4), UINT8_C( 22), UINT8_C( 68), UINT8_C(211), UINT8_C( 68), UINT8_C(170), UINT8_C(  6) },
      {    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX } },
    { { UINT8_C(217), UINT8_C(162), UINT8_C(188), UINT8_C(168), UINT8_C( 90), UINT8_C(130), UINT8_C( 62), UINT8_C(197),
        UINT8_C(209), UINT8_C(225), UINT8_C( 10), UINT8_C(164), UINT8_C(153), UINT8_C( 61), UINT8_C(175), UINT8_C(229) },
      { UINT8_C( 15), UINT8_C(253), UINT8_C(254), UINT8_C( 85), UINT8_C( 24), UINT8_C(130), UINT8_C(  8), UINT8_C(129),
        UINT8_C(229), UINT8_C(225), UINT8_C( 38), UINT8_C(193), UINT8_C( 12), UINT8_C( 61), UINT8_C(175), UINT8_C(229) },
      {    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) } },
    { { UINT8_C( 83), UINT8_C(191), UINT8_C(105), UINT8_C( 58), UINT8_C( 87), UINT8_C( 42), UINT8_C(237), UINT8_C( 39),
        UINT8_C(113), UINT8_C( 19), UINT8_C(232), UINT8_C( 47), UINT8_C( 69), UINT8_C(151), UINT8_C(253), UINT8_C(153) },
      { UINT8_C(  2), UINT8_C(139), UINT8_C(105), UINT8_C( 58), UINT8_C( 87), UINT8_C(104), UINT8_C( 66), UINT8_C(120),
        UINT8_C(113), UINT8_C(239), UINT8_C( 50), UINT8_C( 47), UINT8_C( 69), UINT8_C(244), UINT8_C(252), UINT8_C(153) },
      {    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0) } },
    { { UINT8_C(244), UINT8_C(239), UINT8_C(217), UINT8_C( 75), UINT8_C( 87), UINT8_C( 28), UINT8_C(176), UINT8_C(228),
        UINT8_C(182), UINT8_C( 28), UINT8_C(248), UINT8_C( 80), UINT8_C(234), UINT8_C(244), UINT8_C(242), UINT8_C(121) },
      { UINT8_C( 18), UINT8_C(238), UINT8_C(147), UINT8_C( 91), UINT8_C(223), UINT8_C(176), UINT8_C(176), UINT8_C(228),
        UINT8_C(182), UINT8_C( 28), UINT8_C( 58), UINT8_C( 83), UINT8_C(133), UINT8_C(191), UINT8_C(242), UINT8_C(121) },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0) } },
    { { UINT8_C( 19), UINT8_C(155), UINT8_C(141), UINT8_C(250), UINT8_C( 75), UINT8_C(217), UINT8_C(223), UINT8_C(191),
        UINT8_C(245), UINT8_C( 25), UINT8_C( 84), UINT8_C(122), UINT8_C(216), UINT8_C( 48), UINT8_C(243), UINT8_C(135) },
      { UINT8_C( 19), UINT8_C(183), UINT8_C(141), UINT8_C(251), UINT8_C( 64), UINT8_C( 92), UINT8_C(238), UINT8_C(191),
        UINT8_C( 35), UINT8_C( 49), UINT8_C( 40), UINT8_C(222), UINT8_C( 94), UINT8_C( 48), UINT8_C(171), UINT8_C(121) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),
           UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX } },
    { { UINT8_C(199), UINT8_C( 88), UINT8_C(193), UINT8_C(227), UINT8_C(180), UINT8_C(175), UINT8_C(133), UINT8_C(215),
        UINT8_C(225), UINT8_C(238), UINT8_C(181), UINT8_C( 56), UINT8_C( 30), UINT8_C( 97), UINT8_C(254), UINT8_C(233) },
      { UINT8_C( 53), UINT8_C( 45), UINT8_C(  0), UINT8_C(227), UINT8_C(128), UINT8_C( 24), UINT8_C(133), UINT8_C(236),
        UINT8_C(132), UINT8_C(162), UINT8_C( 48), UINT8_C( 56), UINT8_C(177), UINT8_C(252), UINT8_C(254), UINT8_C(120) },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x16_t a = simde_vld1q_u8(test_vec[i].a);
    simde_uint8x16_t b = simde_vld1q_u8(test_vec[i].b);
    simde_uint8x16_t r = simde_vcgtq_u8(a, b);

    simde_test_arm_neon_assert_equal_u8x16(r, simde_vld1q_u8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8x16_private a_ = simde_uint8x16_to_private(simde_test_arm_neon_random_u8x16());
    simde_uint8x16_private b_ = simde_uint8x16_to_private(simde_test_arm_neon_random_u8x16());

    /* Make some equal which is unlikely to happen by accident. */
    for (size_t j = 0 ; j < (sizeof(a_.values) / sizeof(a_.values[0])) ; j++) {
      if (rand() < (RAND_MAX / 3)) a_.values[j] = b_.values[j];
    }

    simde_uint8x16_t a = simde_uint8x16_from_private(a_);
    simde_uint8x16_t b = simde_uint8x16_from_private(b_);

    simde_uint8x16_t r = simde_vcgtq_u8(a, b);

    simde_test_arm_neon_write_u8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcgtq_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[8];
    uint16_t b[8];
    uint16_t r[8];
  } test_vec[] = {
    { { UINT16_C( 2446), UINT16_C(26386), UINT16_C( 2990), UINT16_C(37360), UINT16_C(47703), UINT16_C(  533), UINT16_C(57400), UINT16_C( 4735) },
      { UINT16_C( 4132), UINT16_C(20851), UINT16_C(42315), UINT16_C(35847), UINT16_C(47703), UINT16_C(31280), UINT16_C(57400), UINT16_C(50806) },
      { UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { { UINT16_C(15989), UINT16_C(12681), UINT16_C(22979), UINT16_C(15095), UINT16_C( 9352), UINT16_C(46392), UINT16_C(16311), UINT16_C( 3649) },
      { UINT16_C(29177), UINT16_C(12681), UINT16_C(65361), UINT16_C(15095), UINT16_C( 9352), UINT16_C( 7377), UINT16_C(63810), UINT16_C(47091) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    0) } },
    { { UINT16_C( 6642), UINT16_C(43334), UINT16_C(55117), UINT16_C(21175), UINT16_C(16632), UINT16_C(18820), UINT16_C(25020), UINT16_C(51331) },
      { UINT16_C(21664), UINT16_C(58084), UINT16_C(55117), UINT16_C(34201), UINT16_C(56229), UINT16_C(52351), UINT16_C(25020), UINT16_C(44637) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX } },
    { { UINT16_C(43599), UINT16_C(55427), UINT16_C(57589), UINT16_C(50519), UINT16_C(15170), UINT16_C(36775), UINT16_C(16402), UINT16_C(15055) },
      { UINT16_C(37916), UINT16_C(55427), UINT16_C(57589), UINT16_C(28550), UINT16_C(56707), UINT16_C(44355), UINT16_C(27115), UINT16_C(15055) },
      {      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { { UINT16_C(42331), UINT16_C(28410), UINT16_C( 3814), UINT16_C(  549), UINT16_C(43426), UINT16_C(38874), UINT16_C(24713), UINT16_C( 3335) },
      { UINT16_C(19005), UINT16_C(10426), UINT16_C(35507), UINT16_C(50787), UINT16_C(11460), UINT16_C(60926), UINT16_C(64589), UINT16_C(43095) },
      {      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { { UINT16_C(25273), UINT16_C(28314), UINT16_C(51551), UINT16_C(  379), UINT16_C(14059), UINT16_C(31369), UINT16_C(36032), UINT16_C(33892) },
      { UINT16_C(25273), UINT16_C( 1649), UINT16_C(51551), UINT16_C(  430), UINT16_C(50458), UINT16_C(31369), UINT16_C( 4865), UINT16_C(59005) },
      { UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0) } },
    { { UINT16_C(25862), UINT16_C(50753), UINT16_C(42482), UINT16_C(31243), UINT16_C(48135), UINT16_C(26289), UINT16_C(24453), UINT16_C(40807) },
      { UINT16_C(61476), UINT16_C( 9498), UINT16_C(38659), UINT16_C(31243), UINT16_C(24750), UINT16_C(26293), UINT16_C(61744), UINT16_C(13833) },
      { UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX } },
    { { UINT16_C(42242), UINT16_C(60140), UINT16_C(50180), UINT16_C(10535), UINT16_C(16821), UINT16_C(47182), UINT16_C(23256), UINT16_C(25892) },
      { UINT16_C(59578), UINT16_C(60140), UINT16_C(62938), UINT16_C(12576), UINT16_C( 7231), UINT16_C(11898), UINT16_C(28258), UINT16_C(25892) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);
    simde_uint16x8_t b = simde_vld1q_u16(test_vec[i].b);
    simde_uint16x8_t r = simde_vcgtq_u16(a, b);

    simde_test_arm_neon_assert_equal_u16x8(r, simde_vld1q_u16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x8_private a_ = simde_uint16x8_to_private(simde_test_arm_neon_random_u16x8());
    simde_uint16x8_private b_ = simde_uint16x8_to_private(simde_test_arm_neon_random_u16x8());

    /* Make some equal which is unlikely to happen by accident. */
    for (size_t j = 0 ; j < (sizeof(a_.values) / sizeof(a_.values[0])) ; j++) {
      if (rand() < (RAND_MAX / 3)) a_.values[j] = b_.values[j];
    }

    simde_uint16x8_t a = simde_uint16x8_from_private(a_);
    simde_uint16x8_t b = simde_uint16x8_from_private(b_);

    simde_uint16x8_t r = simde_vcgtq_u16(a, b);

    simde_test_arm_neon_write_u16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcgtq_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[4];
    uint32_t b[4];
    uint32_t r[4];
  } test_vec[] = {
    { { UINT32_C( 473723137), UINT32_C(3865908623), UINT32_C(2105010025), UINT32_C(1194363102) },
      { UINT32_C( 473723137), UINT32_C(3865908623), UINT32_C(1956114873), UINT32_C( 411778070) },
      { UINT32_C(         0), UINT32_C(         0),           UINT32_MAX,           UINT32_MAX } },
    { { UINT32_C(2827839550), UINT32_C( 519361544), UINT32_C(2373277068), UINT32_C(1453961671) },
      { UINT32_C(2151421638), UINT32_C( 519361544), UINT32_C(3325460240), UINT32_C( 779632623) },
      {           UINT32_MAX, UINT32_C(         0), UINT32_C(         0),           UINT32_MAX } },
    { { UINT32_C(2519071497), UINT32_C( 388209232), UINT32_C( 309185868), UINT32_C(3952257763) },
      { UINT32_C(2383054462), UINT32_C(4115939334), UINT32_C( 656657535), UINT32_C(3659463121) },
      {           UINT32_MAX, UINT32_C(         0), UINT32_C(         0),           UINT32_MAX } },
    { { UINT32_C( 693933277), UINT32_C(1144834657), UINT32_C(4063284852), UINT32_C(1535130197) },
      { UINT32_C(4199601274), UINT32_C(1898017952), UINT32_C(1649098605), UINT32_C(1604828290) },
      { UINT32_C(         0), UINT32_C(         0),           UINT32_MAX, UINT32_C(         0) } },
    { { UINT32_C(1106625997), UINT32_C(3895666067), UINT32_C(4027940512), UINT32_C(1335991938) },
      { UINT32_C(1972958472), UINT32_C(3067601972), UINT32_C(4027940512), UINT32_C(1335991938) },
      { UINT32_C(         0),           UINT32_MAX, UINT32_C(         0), UINT32_C(         0) } },
    { { UINT32_C( 467649724), UINT32_C(4294255480), UINT32_C(3227309148), UINT32_C(4063543230) },
      { UINT32_C(1135086755), UINT32_C( 204717706), UINT32_C(3227309148), UINT32_C( 666365291) },
      { UINT32_C(         0),           UINT32_MAX, UINT32_C(         0),           UINT32_MAX } },
    { { UINT32_C(1881749689), UINT32_C(1765106686), UINT32_C(3014812687), UINT32_C(4210449264) },
      { UINT32_C(1963403801), UINT32_C(1765106686), UINT32_C(  26274896), UINT32_C(1009505155) },
      { UINT32_C(         0), UINT32_C(         0),           UINT32_MAX,           UINT32_MAX } },
    { { UINT32_C(3016547492), UINT32_C( 224821130), UINT32_C(4088094170), UINT32_C(2305488869) },
      { UINT32_C(1710202389), UINT32_C( 224821130), UINT32_C(1565167954), UINT32_C(2305488869) },
      {           UINT32_MAX, UINT32_C(         0),           UINT32_MAX, UINT32_C(         0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint32x4_t b = simde_vld1q_u32(test_vec[i].b);
    simde_uint32x4_t r = simde_vcgtq_u32(a, b);

    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x4_private a_ = simde_uint32x4_to_private(simde_test_arm_neon_random_u32x4());
    simde_uint32x4_private b_ = simde_uint32x4_to_private(simde_test_arm_neon_random_u32x4());

    /* Make some equal which is unlikely to happen by accident. */
    for (size_t j = 0 ; j < (sizeof(a_.values) / sizeof(a_.values[0])) ; j++) {
      if (rand() < (RAND_MAX / 3)) a_.values[j] = b_.values[j];
    }

    simde_uint32x4_t a = simde_uint32x4_from_private(a_);
    simde_uint32x4_t b = simde_uint32x4_from_private(b_);

    simde_uint32x4_t r = simde_vcgtq_u32(a, b);

    simde_test_arm_neon_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcgtq_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a[2];
    uint64_t b[2];
    uint64_t r[2];
  } test_vec[] = {
    { { UINT64_C( 4984667592699295586), UINT64_C(15811667397857361308) },
      { UINT64_C( 2339370879973895867), UINT64_C(15914396696525011477) },
      {                    UINT64_MAX, UINT64_C(                   0) } },
    { { UINT64_C(17703454356444598334), UINT64_C( 1902071959979066185) },
      { UINT64_C(17703454356444598334), UINT64_C(16535179364514408836) },
      { UINT64_C(                   0), UINT64_C(                   0) } },
    { { UINT64_C(15213933129178520905), UINT64_C(17198566065116191608) },
      { UINT64_C(15213933129178520905), UINT64_C(18321098540334786591) },
      { UINT64_C(                   0), UINT64_C(                   0) } },
    { { UINT64_C( 7391236093137010105), UINT64_C( 8149620001519388879) },
      { UINT64_C( 1479519886084451389), UINT64_C( 5612301609669465831) },
      {                    UINT64_MAX,                    UINT64_MAX } },
    { { UINT64_C(10745059411321893956), UINT64_C(17681158274966770843) },
      { UINT64_C(12075888877328785271), UINT64_C(13588399630576331348) },
      { UINT64_C(                   0),                    UINT64_MAX } },
    { { UINT64_C(17223061392421060754), UINT64_C(  256844536222304592) },
      { UINT64_C(13276475547068630142), UINT64_C(  373604650733713338) },
      {                    UINT64_MAX, UINT64_C(                   0) } },
    { { UINT64_C(15817235441742767541), UINT64_C( 8349911497263694028) },
      { UINT64_C( 3306683102762830829), UINT64_C( 1179745581916837631) },
      {                    UINT64_MAX,                    UINT64_MAX } },
    { { UINT64_C( 4290543828840351433), UINT64_C( 4204393115711491950) },
      { UINT64_C(14368431464027790381), UINT64_C(11143108144020046107) },
      { UINT64_C(                   0), UINT64_C(                   0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x2_t a = simde_vld1q_u64(test_vec[i].a);
    simde_uint64x2_t b = simde_vld1q_u64(test_vec[i].b);
    simde_uint64x2_t r = simde_vcgtq_u64(a, b);

    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint64x2_private a_ = simde_uint64x2_to_private(simde_test_arm_neon_random_u64x2());
    simde_uint64x2_private b_ = simde_uint64x2_to_private(simde_test_arm_neon_random_u64x2());

    /* Make some equal which is unlikely to happen by accident. */
    for (size_t j = 0 ; j < (sizeof(a_.values) / sizeof(a_.values[0])) ; j++) {
      if (rand() < (RAND_MAX / 3)) a_.values[j] = b_.values[j];
    }

    simde_uint64x2_t a = simde_uint64x2_from_private(a_);
    simde_uint64x2_t b = simde_uint64x2_from_private(b_);

    simde_uint64x2_t r = simde_vcgtq_u64(a, b);

    simde_test_arm_neon_write_u64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcgtd_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64_t a;
    simde_float64_t b;
    uint64_t r;
  } test_vec[] = {
    { SIMDE_FLOAT64_C(  -338.51),
      SIMDE_FLOAT64_C(  -290.63),
      UINT64_C(                   0) },
    { SIMDE_FLOAT64_C(   378.78),
      SIMDE_FLOAT64_C(   968.82),
      UINT64_C(                   0) },
    { SIMDE_FLOAT64_C(   400.89),
      SIMDE_FLOAT64_C(  -741.17),
                          UINT64_MAX },
    { SIMDE_FLOAT64_C(   390.78),
      SIMDE_FLOAT64_C(   851.36),
      UINT64_C(                   0) },
    { SIMDE_FLOAT64_C(   468.59),
      SIMDE_FLOAT64_C(   825.38),
      UINT64_C(                   0) },
    { SIMDE_FLOAT64_C(  -711.58),
      SIMDE_FLOAT64_C(  -597.70),
      UINT64_C(                   0) },
    { SIMDE_FLOAT64_C(   820.67),
      SIMDE_FLOAT64_C(    66.72),
                          UINT64_MAX },
    { SIMDE_FLOAT64_C(   998.60),
      SIMDE_FLOAT64_C(  -553.87),
                          UINT64_MAX }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint64_t r = simde_vcgtd_f64(test_vec[i].a, test_vec[i].b);
    simde_assert_equal_u64(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64_t a = simde_test_codegen_random_f64(-1000, 1000);
    simde_float64_t b = simde_test_codegen_random_f64(-1000, 1000);
    uint64_t r = simde_vcgtd_f64(a, b);

    simde_test_codegen_write_f64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_f64(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcgtd_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a;
    int64_t b;
    uint64_t r;
  } test_vec[] = {
    { -INT64_C( 6203671323508070102),
      INT64_C( 5334757952141022186),
     UINT64_C(                   0) },
   { -INT64_C(  697941797546617661),
      INT64_C(  681051657537595514),
     UINT64_C(                   0) },
   { -INT64_C( 8920596657137747523),
     -INT64_C( 2062568227174530561),
     UINT64_C(                   0) },
   { -INT64_C( 7280563440422308259),
     -INT64_C( 9200898284290036121),
                         UINT64_MAX },
   { -INT64_C( 4724489589597007024),
      INT64_C( 6305660679283323006),
     UINT64_C(                   0) },
   {  INT64_C( 1631795854179791082),
      INT64_C( 3512433739002808699),
     UINT64_C(                   0) },
   { -INT64_C( 8990439375424993090),
      INT64_C( 3282460311984148283),
     UINT64_C(                   0) },
   { -INT64_C( 5919457025108417516),
     -INT64_C( 6992214588571044378),
                         UINT64_MAX }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint64_t r = simde_vcgtd_s64(test_vec[i].a, test_vec[i].b);
    simde_assert_equal_u64(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    int64_t a = simde_test_codegen_random_i64();
    int64_t b = simde_test_codegen_random_i64();
    uint64_t r = simde_vcgtd_s64(a, b);

    simde_test_codegen_write_i64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i64(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcgtd_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a;
    uint64_t b;
    uint64_t r;
  } test_vec[] = {
    { UINT64_C( 9859209852987004596),
      UINT64_C( 2208579676437409383),
                          UINT64_MAX },
    { UINT64_C(15415404935339740100),
      UINT64_C(17742834816836742470),
      UINT64_C(                   0) },
    { UINT64_C(16731934201337843084),
      UINT64_C(11337020246961251764),
                          UINT64_MAX },
    { UINT64_C(15829539806291169210),
      UINT64_C( 7762160527488362879),
                          UINT64_MAX },
    { UINT64_C( 2716314278328446025),
      UINT64_C( 2604402655134235566),
                          UINT64_MAX },
    { UINT64_C( 6571501565809265089),
      UINT64_C(13230684474554823250),
      UINT64_C(                   0) },
    { UINT64_C(12184545949066048129),
      UINT64_C(16788950090519770479),
      UINT64_C(                   0) },
    { UINT64_C(17696175256693111390),
      UINT64_C(  668998432176124451),
                          UINT64_MAX }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint64_t r = simde_vcgtd_u64(test_vec[i].a, test_vec[i].b);
    simde_assert_equal_u64(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    uint64_t a = simde_test_codegen_random_u64();
    uint64_t b = simde_test_codegen_random_u64();
    uint64_t r = simde_vcgtd_u64(a, b);

    simde_test_codegen_write_u64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u64(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcgts_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32_t a;
    simde_float32_t b;
    uint32_t r;
  } test_vec[] = {
    { SIMDE_FLOAT32_C(    42.41),
      SIMDE_FLOAT32_C(  -519.18),
                UINT32_MAX },
    { SIMDE_FLOAT32_C(   512.73),
      SIMDE_FLOAT32_C(  -533.01),
                UINT32_MAX },
    { SIMDE_FLOAT32_C(   642.14),
      SIMDE_FLOAT32_C(  -632.93),
                UINT32_MAX },
    { SIMDE_FLOAT32_C(  -879.36),
      SIMDE_FLOAT32_C(  -755.01),
      UINT32_C(         0) },
    { SIMDE_FLOAT32_C(   239.01),
      SIMDE_FLOAT32_C(  -834.06),
                UINT32_MAX },
    { SIMDE_FLOAT32_C(   801.80),
      SIMDE_FLOAT32_C(   819.51),
      UINT32_C(         0) },
    { SIMDE_FLOAT32_C(   937.03),
      SIMDE_FLOAT32_C(   232.56),
                UINT32_MAX },
    { SIMDE_FLOAT32_C(  -334.43),
      SIMDE_FLOAT32_C(   174.66),
      UINT32_C(         0) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint32_t r = simde_vcgts_f32(test_vec[i].a, test_vec[i].b);
    simde_assert_equal_u32(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32_t a = simde_test_codegen_random_f32(-1000, 1000);
    simde_float32_t b = simde_test_codegen_random_f32(-1000, 1000);
    uint32_t r = simde_vcgts_f32(a, b);

    simde_test_codegen_write_f32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_f32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vcgt_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcgt_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vcgt_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vcgt_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcgt_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcgt_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vcgt_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vcgt_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcgt_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcgt_u64)

SIMDE_TEST_FUNC_LIST_ENTRY(vcgtq_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcgtq_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vcgtq_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vcgtq_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcgtq_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcgtq_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vcgtq_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vcgtq_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcgtq_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcgtq_u64)

SIMDE_TEST_FUNC_LIST_ENTRY(vcgtd_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vcgtd_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vcgtd_u64)
SIMDE_TEST_FUNC_LIST_ENTRY(vcgts_f32)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
