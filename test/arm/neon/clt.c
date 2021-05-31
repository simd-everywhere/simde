#define SIMDE_TEST_ARM_NEON_INSN clt

#include "test-neon.h"

/* Check that both of these work */
#if defined(__cplusplus)
  #include "../../../simde/arm/neon/clt.h"
#else
  #include "../../../simde/arm/neon.h"
#endif

static int
test_simde_vclt_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a[2];
    simde_float32 b[2];
    uint32_t r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -878.13), SIMDE_FLOAT32_C(   253.04) },
      { SIMDE_FLOAT32_C(  -138.52), SIMDE_FLOAT32_C(   520.27) },
      {           UINT32_MAX,           UINT32_MAX } },
    { { SIMDE_FLOAT32_C(   216.41), SIMDE_FLOAT32_C(  -277.45) },
      { SIMDE_FLOAT32_C(   216.41), SIMDE_FLOAT32_C(  -277.45) },
      { UINT32_C(         0), UINT32_C(         0) } },
    { { SIMDE_FLOAT32_C(  -520.65), SIMDE_FLOAT32_C(    69.98) },
      { SIMDE_FLOAT32_C(  -520.65), SIMDE_FLOAT32_C(  -666.76) },
      { UINT32_C(         0), UINT32_C(         0) } },
    { { SIMDE_FLOAT32_C(  -131.97), SIMDE_FLOAT32_C(  -253.40) },
      { SIMDE_FLOAT32_C(  -131.97), SIMDE_FLOAT32_C(  -253.40) },
      { UINT32_C(         0), UINT32_C(         0) } },
    { { SIMDE_FLOAT32_C(  -732.59), SIMDE_FLOAT32_C(    16.82) },
      { SIMDE_FLOAT32_C(  -576.18), SIMDE_FLOAT32_C(  -841.89) },
      {           UINT32_MAX, UINT32_C(         0) } },
    { { SIMDE_FLOAT32_C(    59.37), SIMDE_FLOAT32_C(  -991.99) },
      { SIMDE_FLOAT32_C(    59.37), SIMDE_FLOAT32_C(  -991.99) },
      { UINT32_C(         0), UINT32_C(         0) } },
    { { SIMDE_FLOAT32_C(  -436.42), SIMDE_FLOAT32_C(   163.54) },
      { SIMDE_FLOAT32_C(  -436.42), SIMDE_FLOAT32_C(   163.54) },
      { UINT32_C(         0), UINT32_C(         0) } },
    { { SIMDE_FLOAT32_C(   442.39), SIMDE_FLOAT32_C(   921.75) },
      { SIMDE_FLOAT32_C(   696.88), SIMDE_FLOAT32_C(   921.75) },
      {           UINT32_MAX, UINT32_C(         0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t a = simde_vld1_f32(test_vec[i].a);
    simde_float32x2_t b = simde_vld1_f32(test_vec[i].b);
    simde_uint32x2_t r = simde_vclt_f32(a, b);

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

    simde_uint32x2_t r = simde_vclt_f32(a, b);

    simde_test_arm_neon_write_f32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vclt_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 a[1];
    simde_float64 b[1];
    uint64_t r[1];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(   904.65) },
      { SIMDE_FLOAT64_C(  -973.46) },
      { UINT64_C(                   0) } },
    { { SIMDE_FLOAT64_C(  -826.64) },
      { SIMDE_FLOAT64_C(   314.00) },
      {                    UINT64_MAX } },
    { { SIMDE_FLOAT64_C(   685.96) },
      { SIMDE_FLOAT64_C(   685.96) },
      { UINT64_C(                   0) } },
    { { SIMDE_FLOAT64_C(  -419.20) },
      { SIMDE_FLOAT64_C(   659.33) },
      {                    UINT64_MAX } },
    { { SIMDE_FLOAT64_C(   424.09) },
      { SIMDE_FLOAT64_C(   -15.82) },
      { UINT64_C(                   0) } },
    { { SIMDE_FLOAT64_C(   280.79) },
      { SIMDE_FLOAT64_C(  -594.35) },
      { UINT64_C(                   0) } },
    { { SIMDE_FLOAT64_C(  -595.16) },
      { SIMDE_FLOAT64_C(   567.93) },
      {                    UINT64_MAX } },
    { { SIMDE_FLOAT64_C(   -45.66) },
      { SIMDE_FLOAT64_C(   -45.66) },
      { UINT64_C(                   0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x1_t a = simde_vld1_f64(test_vec[i].a);
    simde_float64x1_t b = simde_vld1_f64(test_vec[i].b);
    simde_uint64x1_t r = simde_vclt_f64(a, b);

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

    simde_uint64x1_t r = simde_vclt_f64(a, b);

    simde_test_arm_neon_write_f64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x1(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vclt_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[8];
    int8_t b[8];
    uint8_t r[8];
  } test_vec[] = {
    { { -INT8_C(  75),  INT8_C(  17), -INT8_C(  55), -INT8_C(  95), -INT8_C(  17), -INT8_C(  75), -INT8_C(  40), -INT8_C(   6) },
      { -INT8_C( 105), -INT8_C(  44),  INT8_C(  60), -INT8_C(  63),  INT8_C(  11), -INT8_C(  25), -INT8_C(  41),  INT8_C( 126) },
      { UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX } },
    { {  INT8_C(  70),  INT8_C( 102),  INT8_C(  48), -INT8_C(   1),  INT8_C(  28),  INT8_C(  37),  INT8_C(  32), -INT8_C(  25) },
      {  INT8_C(  54),  INT8_C( 102), -INT8_C( 120),  INT8_C(  38),  INT8_C(  28),  INT8_C(  96),  INT8_C(  32), -INT8_C(  77) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0) } },
    { { -INT8_C( 125),  INT8_C(  42), -INT8_C(  56),  INT8_C(  89), -INT8_C( 126),  INT8_C( 101), -INT8_C(   6), -INT8_C( 122) },
      { -INT8_C(  41),  INT8_C(  42), -INT8_C(  56),  INT8_C(   9),  INT8_C(  79),  INT8_C( 101), -INT8_C(  16), -INT8_C( 122) },
      {    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) } },
    { {  INT8_C(  40),  INT8_C(  16),  INT8_C(  78),  INT8_C( 107),  INT8_C(  42),  INT8_C(  12), -INT8_C(  62), -INT8_C(  32) },
      {  INT8_C( 119), -INT8_C(  44),  INT8_C(  57), -INT8_C(   7),  INT8_C(  42),  INT8_C(  51), -INT8_C(  62),  INT8_C(   2) },
      {    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX } },
    { {  INT8_C( 115), -INT8_C(  33), -INT8_C(  92),  INT8_C(  76), -INT8_C(  85),  INT8_C( 109),  INT8_C(  90), -INT8_C(  45) },
      {  INT8_C(  80), -INT8_C(  88),  INT8_C(  62), -INT8_C(  83), -INT8_C(  75),  INT8_C( 109), -INT8_C( 115),  INT8_C(  44) },
      { UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX } },
    { {  INT8_C( 115),  INT8_C( 121),  INT8_C(  52), -INT8_C(  63),  INT8_C(   4), -INT8_C( 114),  INT8_C(  32), -INT8_C(  25) },
      {  INT8_C(  22), -INT8_C(  60),  INT8_C(  52), -INT8_C(  63),  INT8_C(   4), -INT8_C( 114), -INT8_C( 108),  INT8_C(  85) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX } },
    { { -INT8_C(  43),  INT8_C(  61), -INT8_C(  18),  INT8_C(  73), -INT8_C(  29),  INT8_C(  92),  INT8_C(  48), -INT8_C( 104) },
      { -INT8_C(  43), -INT8_C(  85), -INT8_C(   4),  INT8_C(  73), -INT8_C(  29),  INT8_C(  28),  INT8_C(  48), -INT8_C(   7) },
      { UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX } },
    { {  INT8_C( 107),  INT8_C(  60),  INT8_C(  22),  INT8_C(  99),  INT8_C(  47),  INT8_C(  23),  INT8_C(  41),  INT8_C(  32) },
      {  INT8_C( 107), -INT8_C(  45),  INT8_C( 112), -INT8_C( 111),  INT8_C(  47),  INT8_C(  23),  INT8_C(  41),  INT8_C(   4) },
      { UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8_t a = simde_vld1_s8(test_vec[i].a);
    simde_int8x8_t b = simde_vld1_s8(test_vec[i].b);
    simde_uint8x8_t r = simde_vclt_s8(a, b);

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

    simde_uint8x8_t r = simde_vclt_s8(a, b);

    simde_test_arm_neon_write_i8x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vclt_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[4];
    int16_t b[4];
    uint16_t r[4];
  } test_vec[] = {
    { {  INT16_C( 17736), -INT16_C( 24384), -INT16_C(  8064), -INT16_C(  5581) },
      {  INT16_C( 11197),  INT16_C(  2549),  INT16_C( 17328), -INT16_C(  5581) },
      { UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0) } },
    { {  INT16_C( 27109), -INT16_C(  3589), -INT16_C(  1655), -INT16_C( 10712) },
      {  INT16_C( 17454),  INT16_C( 30265), -INT16_C(  1655),  INT16_C(  2327) },
      { UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX } },
    { { -INT16_C( 24584), -INT16_C( 22112), -INT16_C( 11038),  INT16_C(  7571) },
      { -INT16_C( 11601), -INT16_C( 27576),  INT16_C( 17212),  INT16_C( 18053) },
      {      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX } },
    { {  INT16_C( 11994),  INT16_C( 31734),  INT16_C(  3407),  INT16_C( 10628) },
      {  INT16_C( 11994), -INT16_C( 11328),  INT16_C( 24781), -INT16_C( 20356) },
      { UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0) } },
    { { -INT16_C( 32596), -INT16_C( 25046), -INT16_C(   423), -INT16_C( 21917) },
      { -INT16_C( 32596), -INT16_C( 25046),  INT16_C(  8406),  INT16_C(  9497) },
      { UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX } },
    { {  INT16_C(  3788), -INT16_C( 26150),  INT16_C( 22127), -INT16_C( 23735) },
      {  INT16_C(  5989),  INT16_C( 18311),  INT16_C(    45), -INT16_C( 31132) },
      {      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0) } },
    { {  INT16_C( 23368),  INT16_C(  7752),  INT16_C( 24955),  INT16_C(  3940) },
      { -INT16_C( 27906), -INT16_C( 13649), -INT16_C( 30048),  INT16_C(  3940) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { { -INT16_C( 22087), -INT16_C(  3699), -INT16_C(  3782),  INT16_C( 14456) },
      { -INT16_C( 22087),  INT16_C(   482),  INT16_C( 10756),  INT16_C( 32543) },
      { UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t a = simde_vld1_s16(test_vec[i].a);
    simde_int16x4_t b = simde_vld1_s16(test_vec[i].b);
    simde_uint16x4_t r = simde_vclt_s16(a, b);

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

    simde_uint16x4_t r = simde_vclt_s16(a, b);

    simde_test_arm_neon_write_i16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vclt_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[2];
    int32_t b[2];
    uint32_t r[2];
  } test_vec[] = {
    { {  INT32_C(    14356390),  INT32_C(  2091570202) },
      { -INT32_C(   800985278),  INT32_C(  1231471845) },
      { UINT32_C(         0), UINT32_C(         0) } },
    { { -INT32_C(  1191761604), -INT32_C(    40964062) },
      {  INT32_C(  2118768955), -INT32_C(    40964062) },
      {           UINT32_MAX, UINT32_C(         0) } },
    { { -INT32_C(  1984411094),  INT32_C(  1860396681) },
      { -INT32_C(  1984411094), -INT32_C(  1028459317) },
      { UINT32_C(         0), UINT32_C(         0) } },
    { { -INT32_C(  1856319914), -INT32_C(   921721689) },
      { -INT32_C(  2067358316),  INT32_C(  1780389702) },
      { UINT32_C(         0),           UINT32_MAX } },
    { { -INT32_C(    99250480), -INT32_C(  1551577640) },
      {  INT32_C(  1835415233),  INT32_C(   876330201) },
      {           UINT32_MAX,           UINT32_MAX } },
    { {  INT32_C(  1823235288), -INT32_C(   901481547) },
      { -INT32_C(  1247146486), -INT32_C(   901481547) },
      { UINT32_C(         0), UINT32_C(         0) } },
    { {  INT32_C(  1505819032),  INT32_C(   164046384) },
      {  INT32_C(   792527586), -INT32_C(  1836378651) },
      { UINT32_C(         0), UINT32_C(         0) } },
    { {  INT32_C(   264597765), -INT32_C(   447047899) },
      {  INT32_C(  1627326955), -INT32_C(   447047899) },
      {           UINT32_MAX, UINT32_C(         0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t a = simde_vld1_s32(test_vec[i].a);
    simde_int32x2_t b = simde_vld1_s32(test_vec[i].b);
    simde_uint32x2_t r = simde_vclt_s32(a, b);

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

    simde_uint32x2_t r = simde_vclt_s32(a, b);

    simde_test_arm_neon_write_i32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vclt_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a[1];
    int64_t b[1];
    uint64_t r[1];
  } test_vec[] = {
    { { -INT64_C( 5127036871807353823) },
      { -INT64_C( 5127036871807353823) },
      { UINT64_C(                   0) } },
    { { -INT64_C( 2830046651551003050) },
      {  INT64_C( 1306622463292470730) },
      {                    UINT64_MAX } },
    { {  INT64_C( 1880994240672666602) },
      {  INT64_C( 1880994240672666602) },
      { UINT64_C(                   0) } },
    { {  INT64_C(    2101844766198716) },
      {  INT64_C(    2101844766198716) },
      { UINT64_C(                   0) } },
    { { -INT64_C( 3213452295226323034) },
      { -INT64_C( 3213452295226323034) },
      { UINT64_C(                   0) } },
    { { -INT64_C( 7302683616743827769) },
      {  INT64_C( 7731053581688718469) },
      {                    UINT64_MAX } },
    { {  INT64_C( 7803816816053276538) },
      { -INT64_C( 6942222641965927046) },
      { UINT64_C(                   0) } },
    { { -INT64_C( 5643674020643342615) },
      { -INT64_C( 5643674020643342615) },
      { UINT64_C(                   0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x1_t a = simde_vld1_s64(test_vec[i].a);
    simde_int64x1_t b = simde_vld1_s64(test_vec[i].b);
    simde_uint64x1_t r = simde_vclt_s64(a, b);

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

    simde_uint64x1_t r = simde_vclt_s64(a, b);

    simde_test_arm_neon_write_i64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x1(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vclt_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t a[8];
    uint8_t b[8];
    uint8_t r[8];
  } test_vec[] = {
    { { UINT8_C(150), UINT8_C(209), UINT8_C(111), UINT8_C(161), UINT8_C(192), UINT8_C( 67), UINT8_C(170), UINT8_C(177) },
      { UINT8_C(137), UINT8_C(209), UINT8_C(233), UINT8_C(129), UINT8_C( 30), UINT8_C(216), UINT8_C( 20), UINT8_C(179) },
      { UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX } },
    { { UINT8_C(220), UINT8_C( 94), UINT8_C( 34), UINT8_C(120), UINT8_C(106), UINT8_C( 75), UINT8_C(238), UINT8_C(  0) },
      { UINT8_C(192), UINT8_C( 94), UINT8_C(161), UINT8_C(129), UINT8_C(161), UINT8_C( 75), UINT8_C( 50), UINT8_C( 43) },
      { UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX } },
    { { UINT8_C( 37), UINT8_C( 19), UINT8_C(197), UINT8_C( 59), UINT8_C(139), UINT8_C(245), UINT8_C(241), UINT8_C(177) },
      { UINT8_C( 16), UINT8_C( 19), UINT8_C( 41), UINT8_C(122), UINT8_C(139), UINT8_C( 24), UINT8_C(123), UINT8_C( 76) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) } },
    { { UINT8_C(234), UINT8_C(238), UINT8_C(191), UINT8_C( 13), UINT8_C(174), UINT8_C(174), UINT8_C(112), UINT8_C(211) },
      { UINT8_C(234), UINT8_C(189), UINT8_C( 15), UINT8_C(191), UINT8_C(178), UINT8_C(  0), UINT8_C(112), UINT8_C(194) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) } },
    { { UINT8_C(212), UINT8_C(128), UINT8_C( 63), UINT8_C( 60), UINT8_C(182), UINT8_C(214), UINT8_C(242), UINT8_C(208) },
      { UINT8_C(112), UINT8_C(128), UINT8_C(222), UINT8_C( 31), UINT8_C( 46), UINT8_C(214), UINT8_C(242), UINT8_C( 24) },
      { UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) } },
    { { UINT8_C( 85), UINT8_C( 67), UINT8_C(179), UINT8_C(148), UINT8_C(251), UINT8_C(157), UINT8_C(188), UINT8_C(238) },
      { UINT8_C( 85), UINT8_C(252), UINT8_C( 11), UINT8_C( 11), UINT8_C(126), UINT8_C(203), UINT8_C(220), UINT8_C(238) },
      { UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0) } },
    { { UINT8_C(  1), UINT8_C(106), UINT8_C(104), UINT8_C(  3), UINT8_C(178), UINT8_C(230), UINT8_C(124), UINT8_C(149) },
      { UINT8_C(178), UINT8_C(202), UINT8_C( 41), UINT8_C(173), UINT8_C(104), UINT8_C(230), UINT8_C(124), UINT8_C(189) },
      {    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX } },
    { { UINT8_C( 94), UINT8_C(121), UINT8_C( 24), UINT8_C(238), UINT8_C(232), UINT8_C(170), UINT8_C( 91), UINT8_C( 93) },
      { UINT8_C( 20), UINT8_C(121), UINT8_C( 96), UINT8_C(198), UINT8_C(232), UINT8_C(120), UINT8_C( 91), UINT8_C(155) },
      { UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x8_t a = simde_vld1_u8(test_vec[i].a);
    simde_uint8x8_t b = simde_vld1_u8(test_vec[i].b);
    simde_uint8x8_t r = simde_vclt_u8(a, b);

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

    simde_uint8x8_t r = simde_vclt_u8(a, b);

    simde_test_arm_neon_write_u8x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vclt_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[4];
    uint16_t b[4];
    uint16_t r[4];
  } test_vec[] = {
    { { UINT16_C(32822), UINT16_C(20124), UINT16_C(15649), UINT16_C(53596) },
      { UINT16_C(33867), UINT16_C(46145), UINT16_C(15649), UINT16_C(53596) },
      {      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0) } },
    { { UINT16_C(29074), UINT16_C(23284), UINT16_C( 3098), UINT16_C(26002) },
      { UINT16_C(30500), UINT16_C(23284), UINT16_C(37367), UINT16_C(44200) },
      {      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX } },
    { { UINT16_C(62210), UINT16_C(63235), UINT16_C(13360), UINT16_C(65013) },
      { UINT16_C(10596), UINT16_C(63235), UINT16_C( 1435), UINT16_C(46573) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { { UINT16_C(19383), UINT16_C(47515), UINT16_C(14496), UINT16_C(28637) },
      { UINT16_C(19383), UINT16_C(47515), UINT16_C(29503), UINT16_C(28637) },
      { UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0) } },
    { { UINT16_C(28668), UINT16_C(26043), UINT16_C(61556), UINT16_C(34381) },
      { UINT16_C(26479), UINT16_C(26043), UINT16_C(19318), UINT16_C( 5714) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { { UINT16_C(10807), UINT16_C(30452), UINT16_C(53917), UINT16_C(17894) },
      { UINT16_C(21157), UINT16_C(41298), UINT16_C(21954), UINT16_C(13881) },
      {      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0) } },
    { { UINT16_C(30957), UINT16_C(25627), UINT16_C(30515), UINT16_C(18298) },
      { UINT16_C( 2393), UINT16_C(37250), UINT16_C(30515), UINT16_C(53255) },
      { UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX } },
    { { UINT16_C(26688), UINT16_C(  655), UINT16_C(54381), UINT16_C(  824) },
      { UINT16_C(62798), UINT16_C(15545), UINT16_C(54381), UINT16_C(12448) },
      {      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4_t a = simde_vld1_u16(test_vec[i].a);
    simde_uint16x4_t b = simde_vld1_u16(test_vec[i].b);
    simde_uint16x4_t r = simde_vclt_u16(a, b);

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

    simde_uint16x4_t r = simde_vclt_u16(a, b);

    simde_test_arm_neon_write_u16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vclt_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[2];
    uint32_t b[2];
    uint32_t r[2];
  } test_vec[] = {
    { { UINT32_C(1006538243), UINT32_C(3270930982) },
      { UINT32_C(1006538243), UINT32_C(3849160586) },
      { UINT32_C(         0),           UINT32_MAX } },
    { { UINT32_C(1689880060), UINT32_C(2592713952) },
      { UINT32_C(1689880060), UINT32_C(2005775138) },
      { UINT32_C(         0), UINT32_C(         0) } },
    { { UINT32_C( 896308987), UINT32_C(2267575548) },
      { UINT32_C( 896308987), UINT32_C( 425907012) },
      { UINT32_C(         0), UINT32_C(         0) } },
    { { UINT32_C(3252436165), UINT32_C(3677308005) },
      { UINT32_C(3243946568), UINT32_C(3677308005) },
      { UINT32_C(         0), UINT32_C(         0) } },
    { { UINT32_C(2773410290), UINT32_C( 897523696) },
      { UINT32_C(2773410290), UINT32_C(4292940579) },
      { UINT32_C(         0),           UINT32_MAX } },
    { { UINT32_C(3716545173), UINT32_C(2914073850) },
      { UINT32_C(1458425380), UINT32_C(2914073850) },
      { UINT32_C(         0), UINT32_C(         0) } },
    { { UINT32_C(3201697484), UINT32_C( 191112424) },
      { UINT32_C( 218842424), UINT32_C(1829216488) },
      { UINT32_C(         0),           UINT32_MAX } },
    { { UINT32_C(2022799857), UINT32_C(4051590427) },
      { UINT32_C(2022799857), UINT32_C(4051590427) },
      { UINT32_C(         0), UINT32_C(         0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2_t a = simde_vld1_u32(test_vec[i].a);
    simde_uint32x2_t b = simde_vld1_u32(test_vec[i].b);
    simde_uint32x2_t r = simde_vclt_u32(a, b);

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

    simde_uint32x2_t r = simde_vclt_u32(a, b);

    simde_test_arm_neon_write_u32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vclt_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a[1];
    uint64_t b[1];
    uint64_t r[1];
  } test_vec[] = {
    { { UINT64_C(10070407729176073235) },
      { UINT64_C( 7732343939302363799) },
      { UINT64_C(                   0) } },
    { { UINT64_C(12628703139761999735) },
      { UINT64_C(12329520246920030529) },
      { UINT64_C(                   0) } },
    { { UINT64_C(17536455851440219275) },
      { UINT64_C( 8151027840960181848) },
      { UINT64_C(                   0) } },
    { { UINT64_C( 6959487189882112425) },
      { UINT64_C(13600525177902459928) },
      {                    UINT64_MAX } },
    { { UINT64_C( 2278690975057472266) },
      { UINT64_C(13616360460761907503) },
      {                    UINT64_MAX } },
    { { UINT64_C( 2520162804715748145) },
      { UINT64_C( 2520162804715748145) },
      { UINT64_C(                   0) } },
    { { UINT64_C(  235123552249151842) },
      { UINT64_C( 2844834271792461472) },
      {                    UINT64_MAX } },
    { { UINT64_C(12488752737624128753) },
      { UINT64_C(12268281653311768549) },
      { UINT64_C(                   0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x1_t a = simde_vld1_u64(test_vec[i].a);
    simde_uint64x1_t b = simde_vld1_u64(test_vec[i].b);
    simde_uint64x1_t r = simde_vclt_u64(a, b);

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

    simde_uint64x1_t r = simde_vclt_u64(a, b);

    simde_test_arm_neon_write_u64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x1(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcltq_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a[4];
    simde_float32 b[4];
    uint32_t r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   371.77), SIMDE_FLOAT32_C(  -175.93), SIMDE_FLOAT32_C(    59.24), SIMDE_FLOAT32_C(   306.18) },
      { SIMDE_FLOAT32_C(   371.77), SIMDE_FLOAT32_C(   169.92), SIMDE_FLOAT32_C(   324.63), SIMDE_FLOAT32_C(   -35.16) },
      { UINT32_C(         0),           UINT32_MAX,           UINT32_MAX, UINT32_C(         0) } },
    { { SIMDE_FLOAT32_C(  -350.88), SIMDE_FLOAT32_C(  -974.36), SIMDE_FLOAT32_C(   869.28), SIMDE_FLOAT32_C(   571.35) },
      { SIMDE_FLOAT32_C(  -726.73), SIMDE_FLOAT32_C(  -430.55), SIMDE_FLOAT32_C(   869.28), SIMDE_FLOAT32_C(   -89.77) },
      { UINT32_C(         0),           UINT32_MAX, UINT32_C(         0), UINT32_C(         0) } },
    { { SIMDE_FLOAT32_C(   348.81), SIMDE_FLOAT32_C(  -407.57), SIMDE_FLOAT32_C(   461.12), SIMDE_FLOAT32_C(  -973.57) },
      { SIMDE_FLOAT32_C(  -318.44), SIMDE_FLOAT32_C(  -380.83), SIMDE_FLOAT32_C(  -918.31), SIMDE_FLOAT32_C(  -593.83) },
      { UINT32_C(         0),           UINT32_MAX, UINT32_C(         0),           UINT32_MAX } },
    { { SIMDE_FLOAT32_C(  -689.15), SIMDE_FLOAT32_C(    36.98), SIMDE_FLOAT32_C(   779.85), SIMDE_FLOAT32_C(  -534.89) },
      { SIMDE_FLOAT32_C(  -173.57), SIMDE_FLOAT32_C(     1.89), SIMDE_FLOAT32_C(   942.20), SIMDE_FLOAT32_C(   475.55) },
      {           UINT32_MAX, UINT32_C(         0),           UINT32_MAX,           UINT32_MAX } },
    { { SIMDE_FLOAT32_C(   705.44), SIMDE_FLOAT32_C(   -83.83), SIMDE_FLOAT32_C(   878.57), SIMDE_FLOAT32_C(  -104.10) },
      { SIMDE_FLOAT32_C(  -306.85), SIMDE_FLOAT32_C(  -435.11), SIMDE_FLOAT32_C(   878.57), SIMDE_FLOAT32_C(  -958.04) },
      { UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0) } },
    { { SIMDE_FLOAT32_C(   958.86), SIMDE_FLOAT32_C(  -849.92), SIMDE_FLOAT32_C(  -782.88), SIMDE_FLOAT32_C(   402.11) },
      { SIMDE_FLOAT32_C(   291.01), SIMDE_FLOAT32_C(   957.42), SIMDE_FLOAT32_C(  -782.88), SIMDE_FLOAT32_C(   601.87) },
      { UINT32_C(         0),           UINT32_MAX, UINT32_C(         0),           UINT32_MAX } },
    { { SIMDE_FLOAT32_C(    -1.14), SIMDE_FLOAT32_C(  -990.83), SIMDE_FLOAT32_C(   296.38), SIMDE_FLOAT32_C(  -973.62) },
      { SIMDE_FLOAT32_C(   145.16), SIMDE_FLOAT32_C(  -656.73), SIMDE_FLOAT32_C(   327.18), SIMDE_FLOAT32_C(  -149.41) },
      {           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX } },
    { { SIMDE_FLOAT32_C(   -35.24), SIMDE_FLOAT32_C(   625.06), SIMDE_FLOAT32_C(    99.32), SIMDE_FLOAT32_C(   260.43) },
      { SIMDE_FLOAT32_C(   -35.24), SIMDE_FLOAT32_C(  -937.06), SIMDE_FLOAT32_C(    99.32), SIMDE_FLOAT32_C(   -76.38) },
      { UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_float32x4_t b = simde_vld1q_f32(test_vec[i].b);
    simde_uint32x4_t r = simde_vcltq_f32(a, b);

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

    simde_uint32x4_t r = simde_vcltq_f32(a, b);

    simde_test_arm_neon_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcltq_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 a[2];
    simde_float64 b[2];
    uint64_t r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(  -541.42), SIMDE_FLOAT64_C(   483.82) },
      { SIMDE_FLOAT64_C(   242.04), SIMDE_FLOAT64_C(  -298.53) },
      {                    UINT64_MAX, UINT64_C(                   0) } },
    { { SIMDE_FLOAT64_C(   586.91), SIMDE_FLOAT64_C(  -140.81) },
      { SIMDE_FLOAT64_C(  -913.70), SIMDE_FLOAT64_C(  -140.81) },
      { UINT64_C(                   0), UINT64_C(                   0) } },
    { { SIMDE_FLOAT64_C(   257.61), SIMDE_FLOAT64_C(   978.00) },
      { SIMDE_FLOAT64_C(   491.76), SIMDE_FLOAT64_C(  -666.72) },
      {                    UINT64_MAX, UINT64_C(                   0) } },
    { { SIMDE_FLOAT64_C(   302.40), SIMDE_FLOAT64_C(  -658.81) },
      { SIMDE_FLOAT64_C(  -712.21), SIMDE_FLOAT64_C(  -658.81) },
      { UINT64_C(                   0), UINT64_C(                   0) } },
    { { SIMDE_FLOAT64_C(   285.48), SIMDE_FLOAT64_C(   825.49) },
      { SIMDE_FLOAT64_C(  -902.92), SIMDE_FLOAT64_C(   825.49) },
      { UINT64_C(                   0), UINT64_C(                   0) } },
    { { SIMDE_FLOAT64_C(  -855.34), SIMDE_FLOAT64_C(   506.60) },
      { SIMDE_FLOAT64_C(  -855.34), SIMDE_FLOAT64_C(  -668.79) },
      { UINT64_C(                   0), UINT64_C(                   0) } },
    { { SIMDE_FLOAT64_C(   494.95), SIMDE_FLOAT64_C(   794.97) },
      { SIMDE_FLOAT64_C(   494.95), SIMDE_FLOAT64_C(  -961.51) },
      { UINT64_C(                   0), UINT64_C(                   0) } },
    { { SIMDE_FLOAT64_C(    17.44), SIMDE_FLOAT64_C(   697.82) },
      { SIMDE_FLOAT64_C(    17.44), SIMDE_FLOAT64_C(   697.82) },
      { UINT64_C(                   0), UINT64_C(                   0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2_t a = simde_vld1q_f64(test_vec[i].a);
    simde_float64x2_t b = simde_vld1q_f64(test_vec[i].b);
    simde_uint64x2_t r = simde_vcltq_f64(a, b);

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

    simde_uint64x2_t r = simde_vcltq_f64(a, b);

    simde_test_arm_neon_write_f64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcltq_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[16];
    int8_t b[16];
    uint8_t r[16];
  } test_vec[] = {
    { {  INT8_C(  62),  INT8_C( 110),  INT8_C(  77), -INT8_C( 106),  INT8_C(  45), -INT8_C(  95),  INT8_C(  68),  INT8_C(  99),
        -INT8_C( 107), -INT8_C(  48), -INT8_C(  91), -INT8_C(  79),  INT8_C(   1), -INT8_C(  16), -INT8_C(  83),  INT8_C(  10) },
      {  INT8_C(  94),  INT8_C(  12),  INT8_C(  68), -INT8_C(  59), -INT8_C(  39), -INT8_C(  89),  INT8_C(  68),  INT8_C(  99),
        -INT8_C(  69), -INT8_C(  48), -INT8_C(  33), -INT8_C(  79), -INT8_C(  53), -INT8_C(  16), -INT8_C(  88),  INT8_C(  10) },
      {    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),
           UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) } },
    { { -INT8_C(  61), -INT8_C(  83), -INT8_C( 102), -INT8_C( 100),  INT8_C(  84), -INT8_C(  33),  INT8_C(  33),  INT8_C(  15),
        -INT8_C(  81), -INT8_C(  33), -INT8_C(  63),  INT8_C( 122), -INT8_C(  30),  INT8_C( 105), -INT8_C( 124),  INT8_C(  45) },
      {  INT8_C(  95),  INT8_C(  37), -INT8_C(  72), -INT8_C(  11), -INT8_C(  33), -INT8_C(  89),  INT8_C(  33),  INT8_C(   7),
         INT8_C(  59),  INT8_C(  43),  INT8_C(  48), -INT8_C(  79), -INT8_C(  30), -INT8_C( 103), -INT8_C( 122), -INT8_C(  91) },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0) } },
    { { -INT8_C(  45),  INT8_C(  65),  INT8_C( 101), -INT8_C(  78),  INT8_C( 126),  INT8_C(  16), -INT8_C(  71), -INT8_C(  92),
         INT8_C( 119), -INT8_C(  23),  INT8_C( 106),  INT8_C(  89), -INT8_C( 126), -INT8_C(  15), -INT8_C(   1), -INT8_C(  55) },
      {  INT8_C(  18),  INT8_C(  65),  INT8_C( 101),  INT8_C(  18), -INT8_C( 125),  INT8_C(  16), -INT8_C(  63), -INT8_C(  92),
         INT8_C( 124), -INT8_C(  22), -INT8_C( 107),  INT8_C(  81), -INT8_C( 104), -INT8_C(  76), -INT8_C( 122),  INT8_C( 107) },
      {    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),
           UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX } },
    { {  INT8_C(  12),  INT8_C( 112),  INT8_C(  65),      INT8_MAX,      INT8_MIN,  INT8_C(   2),  INT8_C(  51), -INT8_C(   4),
        -INT8_C(  19), -INT8_C(  66), -INT8_C(  26), -INT8_C( 123),  INT8_C( 125), -INT8_C(  44), -INT8_C(  15),  INT8_C(   8) },
      { -INT8_C( 124),  INT8_C(  14),  INT8_C(  17),      INT8_MAX, -INT8_C(  27), -INT8_C(  45), -INT8_C(  14), -INT8_C(  92),
        -INT8_C(   1), -INT8_C(  66), -INT8_C(  26),  INT8_C(  29), -INT8_C( 119), -INT8_C(  14),  INT8_C(  76), -INT8_C( 107) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
           UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0) } },
    { {      INT8_MIN, -INT8_C(  74),  INT8_C(   5), -INT8_C(  25), -INT8_C( 119), -INT8_C( 119), -INT8_C( 114),  INT8_C( 111),
        -INT8_C(  73),  INT8_C( 114),  INT8_C(  12), -INT8_C(  72),  INT8_C( 100), -INT8_C(  14),  INT8_C(  62), -INT8_C(  57) },
      {      INT8_MIN, -INT8_C(   9), -INT8_C(  86),  INT8_C(  17),  INT8_C(  78), -INT8_C( 119), -INT8_C( 114),  INT8_C( 111),
        -INT8_C(  73), -INT8_C( 111),  INT8_C(  12), -INT8_C(  72), -INT8_C( 123), -INT8_C(  78),  INT8_C(  62), -INT8_C( 120) },
      { UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) } },
    { { -INT8_C(   9),  INT8_C(  66), -INT8_C(  91),  INT8_C(  69), -INT8_C(  51),  INT8_C(  72), -INT8_C(  76), -INT8_C( 124),
         INT8_C( 105), -INT8_C(  63),  INT8_C( 126),  INT8_C( 125),  INT8_C( 115),  INT8_C( 122),  INT8_C(  17), -INT8_C(  37) },
      { -INT8_C(  67),  INT8_C(  66), -INT8_C(  51), -INT8_C(   9),  INT8_C(  61),  INT8_C(  72), -INT8_C(  26), -INT8_C(  85),
         INT8_C( 105),  INT8_C(  19),  INT8_C( 126),  INT8_C( 125),  INT8_C(  19),  INT8_C(  23),  INT8_C(  17),  INT8_C(  10) },
      { UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,
        UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX } },
    { {  INT8_C(  13), -INT8_C(  31),  INT8_C(  15),  INT8_C(  75), -INT8_C( 124), -INT8_C(   2), -INT8_C(  10),  INT8_C(  74),
        -INT8_C(  93),  INT8_C( 116),  INT8_C(  16),  INT8_C(  37), -INT8_C( 116),  INT8_C(  33),  INT8_C(  39),  INT8_C(  65) },
      { -INT8_C(  41),      INT8_MIN,  INT8_C(  15), -INT8_C(  63), -INT8_C( 124), -INT8_C(  69),  INT8_C( 111),  INT8_C(  74),
        -INT8_C(  93),  INT8_C( 104), -INT8_C( 126),  INT8_C(   6),  INT8_C(  52), -INT8_C( 106),  INT8_C(  39),  INT8_C(  65) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) } },
    { {  INT8_C(  68),  INT8_C( 121),  INT8_C(   0), -INT8_C(  87),  INT8_C(  52),  INT8_C( 111), -INT8_C(  13),  INT8_C(  84),
        -INT8_C(  94),  INT8_C(  70), -INT8_C(  34),  INT8_C(  12),  INT8_C(  12),  INT8_C(   5),  INT8_C(  77), -INT8_C( 124) },
      {  INT8_C(  68), -INT8_C(  38),  INT8_C(  38), -INT8_C( 126),  INT8_C(  93),  INT8_C(  92), -INT8_C(  47),  INT8_C(  84),
        -INT8_C(  94),  INT8_C(  70), -INT8_C(  40),  INT8_C(   9), -INT8_C(  21),  INT8_C(  66),  INT8_C(  72),  INT8_C(  16) },
      { UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16_t a = simde_vld1q_s8(test_vec[i].a);
    simde_int8x16_t b = simde_vld1q_s8(test_vec[i].b);
    simde_uint8x16_t r = simde_vcltq_s8(a, b);

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

    simde_uint8x16_t r = simde_vcltq_s8(a, b);

    simde_test_arm_neon_write_i8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcltq_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[8];
    int16_t b[8];
    uint16_t r[8];
  } test_vec[] = {
    { {  INT16_C(  7364), -INT16_C( 12784), -INT16_C(  5799),  INT16_C(  3417),  INT16_C(  4291),  INT16_C(  2542), -INT16_C( 15910),  INT16_C(  9015) },
      { -INT16_C( 27981),  INT16_C( 29466), -INT16_C( 32414),  INT16_C(  3417), -INT16_C( 30798),  INT16_C(  2542),  INT16_C( 21087),  INT16_C(  9015) },
      { UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0) } },
    { { -INT16_C( 18337), -INT16_C(  8153),  INT16_C( 14202),  INT16_C( 11729), -INT16_C(  5175),  INT16_C( 11169), -INT16_C( 28861),  INT16_C(  7736) },
      {  INT16_C(  9857), -INT16_C(  8153),  INT16_C( 24441), -INT16_C(  6141), -INT16_C(  2650), -INT16_C( 10320), -INT16_C( 28861), -INT16_C( 23861) },
      {      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { { -INT16_C( 28521),  INT16_C(   898), -INT16_C(  3711), -INT16_C( 13879),  INT16_C( 18913),  INT16_C( 23275),  INT16_C( 31057),  INT16_C( 20290) },
      { -INT16_C(  3357),  INT16_C( 10022), -INT16_C(  3711), -INT16_C( 13879), -INT16_C( 23224), -INT16_C( 10614),  INT16_C( 31057), -INT16_C(  5843) },
      {      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { { -INT16_C( 30376),  INT16_C(   166), -INT16_C(  5768),  INT16_C( 23375),  INT16_C( 30171),  INT16_C( 23938),  INT16_C( 25894), -INT16_C( 20954) },
      { -INT16_C( 20239),  INT16_C( 17028), -INT16_C( 20182),  INT16_C( 13099),  INT16_C(  6241), -INT16_C( 13369),  INT16_C( 25894),  INT16_C( 32279) },
      {      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX } },
    { {  INT16_C( 17732), -INT16_C( 21793),  INT16_C(  1425), -INT16_C( 32167), -INT16_C(  8778), -INT16_C(  7996),  INT16_C( 22778), -INT16_C(  4077) },
      { -INT16_C(  9720),  INT16_C( 11963), -INT16_C( 11456),  INT16_C( 12205),  INT16_C( 11409),  INT16_C( 14486),  INT16_C( 22778),  INT16_C( 16058) },
      { UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX } },
    { {  INT16_C( 10356),  INT16_C( 28662), -INT16_C( 20351),  INT16_C(  7853),  INT16_C( 23075),  INT16_C( 25499), -INT16_C(   552), -INT16_C(  1985) },
      {  INT16_C( 10356),  INT16_C( 28662), -INT16_C( 20351),  INT16_C(  7853), -INT16_C( 27062), -INT16_C(  5555), -INT16_C(   552), -INT16_C(  1985) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { { -INT16_C(  8033),  INT16_C( 10341), -INT16_C( 10456), -INT16_C( 25206),       INT16_MIN, -INT16_C( 32500), -INT16_C( 18128),  INT16_C( 31647) },
      { -INT16_C(  5040),  INT16_C( 10341), -INT16_C( 23318),  INT16_C( 23584), -INT16_C( 14567), -INT16_C( 10444),  INT16_C( 30732), -INT16_C( 21575) },
      {      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0) } },
    { {  INT16_C( 23875), -INT16_C( 20138), -INT16_C(  2333),  INT16_C( 12026), -INT16_C( 28190), -INT16_C( 19537),  INT16_C( 31798), -INT16_C(  3191) },
      {  INT16_C( 23875),  INT16_C( 20263), -INT16_C(  7979),  INT16_C( 12026),  INT16_C( 29150), -INT16_C( 19537), -INT16_C( 12942), -INT16_C(  3191) },
      { UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_int16x8_t b = simde_vld1q_s16(test_vec[i].b);
    simde_uint16x8_t r = simde_vcltq_s16(a, b);

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

    simde_uint16x8_t r = simde_vcltq_s16(a, b);

    simde_test_arm_neon_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcltq_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[4];
    int32_t b[4];
    uint32_t r[4];
  } test_vec[] = {
    { { -INT32_C(    50670728),  INT32_C(  1362797516),  INT32_C(  1200625608), -INT32_C(   361853940) },
      { -INT32_C(    50670728),  INT32_C(  1362797516), -INT32_C(  1506030104),  INT32_C(   386108489) },
      { UINT32_C(         0), UINT32_C(         0), UINT32_C(         0),           UINT32_MAX } },
    { {  INT32_C(   674165600),  INT32_C(   393264650), -INT32_C(  1040064950),  INT32_C(  2126445489) },
      { -INT32_C(  2016413281),  INT32_C(   254675654), -INT32_C(  1373228650), -INT32_C(  1479440313) },
      { UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0) } },
    { {  INT32_C(   127746237),  INT32_C(  1735163167),  INT32_C(   944670617),  INT32_C(  1203772800) },
      { -INT32_C(  1101599193),  INT32_C(  1735163167), -INT32_C(  2129773307), -INT32_C(   116924868) },
      { UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0) } },
    { { -INT32_C(   619853502), -INT32_C(   787195055), -INT32_C(  1625762696), -INT32_C(   513970238) },
      { -INT32_C(   246887700),  INT32_C(  1148344071),  INT32_C(  1413314869),  INT32_C(  1603354141) },
      {           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX } },
    { {  INT32_C(  1898598393), -INT32_C(   451919325),  INT32_C(   116949247),  INT32_C(  1066340152) },
      { -INT32_C(  1685913242), -INT32_C(  1729117829),  INT32_C(   116949247),  INT32_C(   392114974) },
      { UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0) } },
    { {  INT32_C(  2106235339),  INT32_C(  1058689031),  INT32_C(  1795631081),  INT32_C(   643891883) },
      { -INT32_C(  1027714877), -INT32_C(   272058671),  INT32_C(  1795631081),  INT32_C(  2081460144) },
      { UINT32_C(         0), UINT32_C(         0), UINT32_C(         0),           UINT32_MAX } },
    { {  INT32_C(  1248728043),  INT32_C(  1745939901), -INT32_C(  1299287569), -INT32_C(   294614781) },
      { -INT32_C(   327009277),  INT32_C(   341346660),  INT32_C(  1099982872), -INT32_C(   294614781) },
      { UINT32_C(         0), UINT32_C(         0),           UINT32_MAX, UINT32_C(         0) } },
    { { -INT32_C(  1144895284),  INT32_C(  1332880972), -INT32_C(  1626480228), -INT32_C(  2121494755) },
      {  INT32_C(   831972376),  INT32_C(  1332880972),  INT32_C(  1295901360), -INT32_C(  1918404927) },
      {           UINT32_MAX, UINT32_C(         0),           UINT32_MAX,           UINT32_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int32x4_t b = simde_vld1q_s32(test_vec[i].b);
    simde_uint32x4_t r = simde_vcltq_s32(a, b);

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

    simde_uint32x4_t r = simde_vcltq_s32(a, b);

    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcltq_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a[2];
    int64_t b[2];
    uint64_t r[2];
  } test_vec[] = {
    { { -INT64_C( 3211926684988837804), -INT64_C( 8421230730182920338) },
      { -INT64_C( 6076564325867935792), -INT64_C( 8398288375644386122) },
      { UINT64_C(                   0),                    UINT64_MAX } },
    { {  INT64_C( 1621145505625566236),  INT64_C( 2592856562407949106) },
      {  INT64_C(  266431008299543418), -INT64_C( 7998385834714928779) },
      { UINT64_C(                   0), UINT64_C(                   0) } },
    { { -INT64_C( 6531430259948998375), -INT64_C( 5865573933921008497) },
      { -INT64_C( 3202157712809819149), -INT64_C( 5865573933921008497) },
      {                    UINT64_MAX, UINT64_C(                   0) } },
    { { -INT64_C( 4806800495864986554),  INT64_C( 4567700026947357617) },
      {  INT64_C( 8265831110094800419),  INT64_C( 4567700026947357617) },
      {                    UINT64_MAX, UINT64_C(                   0) } },
    { {  INT64_C( 3477571270109817056),  INT64_C( 8832634092017089677) },
      {  INT64_C( 6739159238684913028), -INT64_C( 6977881495849959529) },
      {                    UINT64_MAX, UINT64_C(                   0) } },
    { {  INT64_C(   74737460574692298),  INT64_C(  437789709730836818) },
      {  INT64_C( 2780949744972968593), -INT64_C( 4595858595526191386) },
      {                    UINT64_MAX, UINT64_C(                   0) } },
    { { -INT64_C( 8807342457093705268), -INT64_C( 8379951819801218578) },
      { -INT64_C( 6452993155498851451), -INT64_C(  804951188618319764) },
      {                    UINT64_MAX,                    UINT64_MAX } },
    { {  INT64_C(  270920930229985738), -INT64_C(  217590579952747901) },
      {  INT64_C( 7705030636722512915), -INT64_C( 3114355646575143576) },
      {                    UINT64_MAX, UINT64_C(                   0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);
    simde_int64x2_t b = simde_vld1q_s64(test_vec[i].b);
    simde_uint64x2_t r = simde_vcltq_s64(a, b);

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

    simde_uint64x2_t r = simde_vcltq_s64(a, b);

    simde_test_arm_neon_write_i64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcltq_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t a[16];
    uint8_t b[16];
    uint8_t r[16];
  } test_vec[] = {
    { { UINT8_C(150), UINT8_C( 53), UINT8_C(140), UINT8_C( 98), UINT8_C(179), UINT8_C(153), UINT8_C( 56), UINT8_C( 98),
        UINT8_C(170), UINT8_C(230), UINT8_C(115), UINT8_C(204), UINT8_C(248), UINT8_C(  8), UINT8_C(101), UINT8_C( 51) },
      { UINT8_C( 67), UINT8_C( 35), UINT8_C(126), UINT8_C(122), UINT8_C(205), UINT8_C(161), UINT8_C(164), UINT8_C( 98),
        UINT8_C( 20), UINT8_C(230), UINT8_C(115), UINT8_C(204), UINT8_C(231), UINT8_C(118), UINT8_C(137), UINT8_C(126) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX } },
    { { UINT8_C(186), UINT8_C(154), UINT8_C(112), UINT8_C(225), UINT8_C( 59), UINT8_C( 20), UINT8_C(193), UINT8_C( 79),
        UINT8_C(203), UINT8_C(182), UINT8_C( 48), UINT8_C(226), UINT8_C( 44), UINT8_C(165), UINT8_C(115), UINT8_C(215) },
      { UINT8_C(186), UINT8_C( 64), UINT8_C( 53), UINT8_C(104), UINT8_C( 88), UINT8_C( 34), UINT8_C(193), UINT8_C( 72),
        UINT8_C(203), UINT8_C( 76), UINT8_C( 48), UINT8_C(125), UINT8_C( 60), UINT8_C( 76), UINT8_C(115), UINT8_C( 80) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) } },
    { { UINT8_C( 37), UINT8_C( 32), UINT8_C( 84), UINT8_C( 28), UINT8_C(134), UINT8_C( 22), UINT8_C( 20), UINT8_C(190),
        UINT8_C( 98), UINT8_C( 68), UINT8_C( 21), UINT8_C(201), UINT8_C( 22), UINT8_C( 66), UINT8_C(239), UINT8_C(138) },
      { UINT8_C( 37), UINT8_C( 32), UINT8_C(153), UINT8_C( 28), UINT8_C(148), UINT8_C( 10), UINT8_C( 14), UINT8_C(190),
        UINT8_C(151), UINT8_C(226), UINT8_C( 21), UINT8_C(201), UINT8_C( 22), UINT8_C( 68), UINT8_C(181), UINT8_C(138) },
      { UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
           UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0) } },
    { { UINT8_C( 48), UINT8_C( 80), UINT8_C(210), UINT8_C(196), UINT8_C( 90), UINT8_C(224), UINT8_C(130), UINT8_C(241),
        UINT8_C(195), UINT8_C( 59), UINT8_C(186), UINT8_C(217), UINT8_C(220), UINT8_C(111), UINT8_C(100), UINT8_C(132) },
      { UINT8_C(121), UINT8_C(186), UINT8_C(178), UINT8_C(152), UINT8_C( 37), UINT8_C( 49), UINT8_C( 26), UINT8_C(212),
        UINT8_C(128), UINT8_C( 59), UINT8_C( 20), UINT8_C( 16), UINT8_C( 75), UINT8_C(203), UINT8_C(198), UINT8_C(123) },
      {    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0) } },
    { { UINT8_C( 51), UINT8_C(108), UINT8_C(158), UINT8_C( 88), UINT8_C(157), UINT8_C(190), UINT8_C( 44), UINT8_C( 29),
        UINT8_C(249), UINT8_C( 64), UINT8_C( 46), UINT8_C(187), UINT8_C( 12), UINT8_C(244), UINT8_C(198), UINT8_C(  1) },
      { UINT8_C(140), UINT8_C(  0), UINT8_C(158), UINT8_C(  4), UINT8_C(194), UINT8_C(  6), UINT8_C( 64), UINT8_C( 28),
        UINT8_C( 41), UINT8_C( 85), UINT8_C( 82), UINT8_C(187), UINT8_C(206), UINT8_C( 12), UINT8_C(198), UINT8_C(  1) },
      {    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),
        UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) } },
    { { UINT8_C( 38), UINT8_C(153), UINT8_C(240), UINT8_C(232), UINT8_C(160), UINT8_C( 35), UINT8_C(252), UINT8_C(201),
        UINT8_C(122), UINT8_C( 98), UINT8_C(132), UINT8_C( 72), UINT8_C( 98), UINT8_C( 74), UINT8_C( 74), UINT8_C(175) },
      { UINT8_C(179), UINT8_C(164), UINT8_C(240), UINT8_C(219), UINT8_C( 42), UINT8_C( 35), UINT8_C(252), UINT8_C(241),
        UINT8_C(132), UINT8_C( 98), UINT8_C(196), UINT8_C(217), UINT8_C(136), UINT8_C(191), UINT8_C(186), UINT8_C(175) },
      {    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,
           UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0) } },
    { { UINT8_C(118), UINT8_C( 75), UINT8_C( 30), UINT8_C(190), UINT8_C( 66), UINT8_C( 26), UINT8_C(146), UINT8_C(198),
        UINT8_C(124), UINT8_C( 86), UINT8_C(159), UINT8_C(  0), UINT8_C( 87), UINT8_C( 94), UINT8_C( 67), UINT8_C(111) },
      { UINT8_C(249), UINT8_C( 75), UINT8_C(104), UINT8_C(190), UINT8_C(231), UINT8_C( 42), UINT8_C(253), UINT8_C(218),
        UINT8_C(112), UINT8_C(133), UINT8_C( 47), UINT8_C(  0), UINT8_C( 87), UINT8_C( 94), UINT8_C( 67), UINT8_C(205) },
      {    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
        UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX } },
    { { UINT8_C(253), UINT8_C( 67), UINT8_C(139), UINT8_C(229), UINT8_C(109), UINT8_C( 52), UINT8_C(191), UINT8_C(163),
        UINT8_C( 56), UINT8_C(238), UINT8_C(221), UINT8_C( 17), UINT8_C( 76), UINT8_C( 33), UINT8_C(223), UINT8_C(166) },
      { UINT8_C(131), UINT8_C( 77), UINT8_C(139),    UINT8_MAX, UINT8_C( 77), UINT8_C( 18), UINT8_C(248), UINT8_C(163),
        UINT8_C( 56), UINT8_C(246), UINT8_C( 16), UINT8_C(184), UINT8_C(168), UINT8_C(235), UINT8_C( 49), UINT8_C(166) },
      { UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),
        UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x16_t a = simde_vld1q_u8(test_vec[i].a);
    simde_uint8x16_t b = simde_vld1q_u8(test_vec[i].b);
    simde_uint8x16_t r = simde_vcltq_u8(a, b);

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

    simde_uint8x16_t r = simde_vcltq_u8(a, b);

    simde_test_arm_neon_write_u8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcltq_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[8];
    uint16_t b[8];
    uint16_t r[8];
  } test_vec[] = {
    { { UINT16_C(12035), UINT16_C(  296), UINT16_C( 6322), UINT16_C(36251), UINT16_C(38592), UINT16_C( 2034), UINT16_C(31190), UINT16_C(45710) },
      { UINT16_C(53605), UINT16_C(  296), UINT16_C(50084), UINT16_C(36251), UINT16_C(43731), UINT16_C(27102), UINT16_C( 2753), UINT16_C(50261) },
      {      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX } },
    { { UINT16_C(25811), UINT16_C(38065), UINT16_C( 1647), UINT16_C(43353), UINT16_C(45652), UINT16_C(18837), UINT16_C(10613), UINT16_C(18566) },
      { UINT16_C(25811), UINT16_C(38065), UINT16_C( 1647), UINT16_C(43353), UINT16_C(14620), UINT16_C(18837), UINT16_C(20900), UINT16_C(42295) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX } },
    { { UINT16_C(16824), UINT16_C(11772), UINT16_C(51684), UINT16_C(58541), UINT16_C( 9958), UINT16_C(41739), UINT16_C(48688), UINT16_C(18942) },
      { UINT16_C(37732), UINT16_C( 2194), UINT16_C(51684), UINT16_C(58541), UINT16_C(10741), UINT16_C(41739), UINT16_C(48688), UINT16_C(59558) },
      {      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX } },
    { { UINT16_C(31154), UINT16_C(57184), UINT16_C(24484), UINT16_C( 2088), UINT16_C(47858), UINT16_C(55056), UINT16_C(48516), UINT16_C(31163) },
      { UINT16_C(50918), UINT16_C( 5660), UINT16_C(50052), UINT16_C(34047), UINT16_C( 5477), UINT16_C(35565), UINT16_C(38048), UINT16_C(21141) },
      {      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { { UINT16_C(51476), UINT16_C(14560), UINT16_C(55686), UINT16_C(14218), UINT16_C(48234), UINT16_C(49128), UINT16_C(33520), UINT16_C(22183) },
      { UINT16_C(38295), UINT16_C(14560), UINT16_C(29993), UINT16_C(14218), UINT16_C(48234), UINT16_C(49128), UINT16_C(41493), UINT16_C(10502) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0) } },
    { { UINT16_C(57856), UINT16_C(61631), UINT16_C(52199), UINT16_C(21178), UINT16_C( 9980), UINT16_C( 9524), UINT16_C(41806), UINT16_C( 1628) },
      { UINT16_C(17787), UINT16_C(37061), UINT16_C(52199), UINT16_C(21178), UINT16_C(31727), UINT16_C(60484), UINT16_C(41806), UINT16_C(20104) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX } },
    { { UINT16_C(61212), UINT16_C(27320), UINT16_C(11483), UINT16_C(22093), UINT16_C(63111), UINT16_C(22758), UINT16_C(41181), UINT16_C(10208) },
      { UINT16_C(61212), UINT16_C(27320), UINT16_C(16531), UINT16_C( 6584), UINT16_C(63111), UINT16_C(13828), UINT16_C(60283), UINT16_C(10208) },
      { UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0) } },
    { { UINT16_C( 8141), UINT16_C(28459), UINT16_C( 3293), UINT16_C(56182), UINT16_C(11841), UINT16_C(39367), UINT16_C(65471), UINT16_C(36072) },
      { UINT16_C(61940), UINT16_C(28459), UINT16_C( 3293), UINT16_C(58518), UINT16_C( 1212), UINT16_C(39367), UINT16_C(65471), UINT16_C(36072) },
      {      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);
    simde_uint16x8_t b = simde_vld1q_u16(test_vec[i].b);
    simde_uint16x8_t r = simde_vcltq_u16(a, b);

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

    simde_uint16x8_t r = simde_vcltq_u16(a, b);

    simde_test_arm_neon_write_u16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcltq_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[4];
    uint32_t b[4];
    uint32_t r[4];
  } test_vec[] = {
    { { UINT32_C(3571304076), UINT32_C(2472274095), UINT32_C(3889123896), UINT32_C(2667893652) },
      { UINT32_C( 599103569), UINT32_C(3098582936), UINT32_C(2104870284), UINT32_C(2098284017) },
      { UINT32_C(         0),           UINT32_MAX, UINT32_C(         0), UINT32_C(         0) } },
    { { UINT32_C( 240037334), UINT32_C(2482380287), UINT32_C(1110637297), UINT32_C(1717869711) },
      { UINT32_C( 333584006), UINT32_C(3432011739), UINT32_C(2840240541), UINT32_C(1717869711) },
      {           UINT32_MAX,           UINT32_MAX,           UINT32_MAX, UINT32_C(         0) } },
    { { UINT32_C(3252382416), UINT32_C(4144172389), UINT32_C(2065852917), UINT32_C(1519256703) },
      { UINT32_C(4180090460), UINT32_C(1336046015), UINT32_C(1454704141), UINT32_C(2292066744) },
      {           UINT32_MAX, UINT32_C(         0), UINT32_C(         0),           UINT32_MAX } },
    { { UINT32_C(2079346054), UINT32_C( 905384630), UINT32_C(1938785559), UINT32_C(1668069028) },
      { UINT32_C( 884084263), UINT32_C(3431622420), UINT32_C( 626337937), UINT32_C( 673095329) },
      { UINT32_C(         0),           UINT32_MAX, UINT32_C(         0), UINT32_C(         0) } },
    { { UINT32_C( 953588257), UINT32_C(3299567136), UINT32_C(3841267193), UINT32_C(1166448676) },
      { UINT32_C(3523543873), UINT32_C(3455539755), UINT32_C(3841267193), UINT32_C(1166448676) },
      {           UINT32_MAX,           UINT32_MAX, UINT32_C(         0), UINT32_C(         0) } },
    { { UINT32_C(4137100541), UINT32_C(1574603833), UINT32_C(1520278296), UINT32_C(2141855677) },
      { UINT32_C(4137100541), UINT32_C(1574603833), UINT32_C(1470259236), UINT32_C(2141855677) },
      { UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0) } },
    { { UINT32_C( 418021632), UINT32_C( 354745432), UINT32_C( 663068458), UINT32_C(2431316880) },
      { UINT32_C(3445290920), UINT32_C( 354745432), UINT32_C(1670696732), UINT32_C(2431316880) },
      {           UINT32_MAX, UINT32_C(         0),           UINT32_MAX, UINT32_C(         0) } },
    { { UINT32_C(2253200220), UINT32_C(2108543674), UINT32_C(2541406959), UINT32_C( 426038465) },
      { UINT32_C(3962472912), UINT32_C(3897607000), UINT32_C( 712587958), UINT32_C(1790714382) },
      {           UINT32_MAX,           UINT32_MAX, UINT32_C(         0),           UINT32_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint32x4_t b = simde_vld1q_u32(test_vec[i].b);
    simde_uint32x4_t r = simde_vcltq_u32(a, b);

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

    simde_uint32x4_t r = simde_vcltq_u32(a, b);

    simde_test_arm_neon_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcltq_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a[2];
    uint64_t b[2];
    uint64_t r[2];
  } test_vec[] = {
    { { UINT64_C( 5951566415767268674), UINT64_C(14751997874589376704) },
      { UINT64_C( 3314177480145134518), UINT64_C( 7678354966161073507) },
      { UINT64_C(                   0), UINT64_C(                   0) } },
    { { UINT64_C(10733899104166349758), UINT64_C( 4544198551152891648) },
      { UINT64_C( 5903945259160945099), UINT64_C( 4544198551152891648) },
      { UINT64_C(                   0), UINT64_C(                   0) } },
    { { UINT64_C(14335256087741015275), UINT64_C( 5077609231872586398) },
      { UINT64_C(14335256087741015275), UINT64_C( 5077609231872586398) },
      { UINT64_C(                   0), UINT64_C(                   0) } },
    { { UINT64_C(16884082501088323537), UINT64_C(18183726781811778603) },
      { UINT64_C( 6571733001915241168), UINT64_C(18183726781811778603) },
      { UINT64_C(                   0), UINT64_C(                   0) } },
    { { UINT64_C( 4917418667771907895), UINT64_C( 4857833735103647733) },
      { UINT64_C( 3451256541622579149), UINT64_C( 4857833735103647733) },
      { UINT64_C(                   0), UINT64_C(                   0) } },
    { { UINT64_C( 9585677928860157643), UINT64_C(12138993750656537711) },
      { UINT64_C(17533621864373092446), UINT64_C( 7817473392221707838) },
      {                    UINT64_MAX, UINT64_C(                   0) } },
    { { UINT64_C( 7806607306692823205), UINT64_C(15729646765192443980) },
      { UINT64_C( 7806607306692823205), UINT64_C(15729646765192443980) },
      { UINT64_C(                   0), UINT64_C(                   0) } },
    { { UINT64_C( 4142313535404413272), UINT64_C(15000715663249176140) },
      { UINT64_C( 4577556720329631799), UINT64_C( 2146717038535436937) },
      {                    UINT64_MAX, UINT64_C(                   0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x2_t a = simde_vld1q_u64(test_vec[i].a);
    simde_uint64x2_t b = simde_vld1q_u64(test_vec[i].b);
    simde_uint64x2_t r = simde_vcltq_u64(a, b);

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

    simde_uint64x2_t r = simde_vcltq_u64(a, b);

    simde_test_arm_neon_write_u64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcltd_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64_t a;
    simde_float64_t b;
    uint64_t r;
  } test_vec[] = {
    { SIMDE_FLOAT64_C(   533.95),
      SIMDE_FLOAT64_C(   746.90),
                          UINT64_MAX },
    { SIMDE_FLOAT64_C(   573.36),
      SIMDE_FLOAT64_C(   889.97),
                          UINT64_MAX },
    { SIMDE_FLOAT64_C(  -468.38),
      SIMDE_FLOAT64_C(  -287.97),
                          UINT64_MAX },
    { SIMDE_FLOAT64_C(  -620.98),
      SIMDE_FLOAT64_C(   535.88),
                          UINT64_MAX },
    { SIMDE_FLOAT64_C(   425.47),
      SIMDE_FLOAT64_C(    98.32),
      UINT64_C(                   0) },
    { SIMDE_FLOAT64_C(  -160.48),
      SIMDE_FLOAT64_C(   423.53),
                          UINT64_MAX },
    { SIMDE_FLOAT64_C(  -851.46),
      SIMDE_FLOAT64_C(  -635.13),
                          UINT64_MAX },
    { SIMDE_FLOAT64_C(   951.90),
      SIMDE_FLOAT64_C(  -927.56),
      UINT64_C(                   0) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint64_t r = simde_vcltd_f64(test_vec[i].a, test_vec[i].b);
    simde_assert_equal_u64(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64_t a = simde_test_codegen_random_f64(-1000, 1000);
    simde_float64_t b = simde_test_codegen_random_f64(-1000, 1000);
    uint64_t r = simde_vcltd_f64(a, b);

    simde_test_codegen_write_f64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_f64(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcltd_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a;
    int64_t b;
    uint64_t r;
  } test_vec[] = {
    {  INT64_C(  255893999981097058),
      INT64_C( 4825350567398967245),
                         UINT64_MAX },
   {  INT64_C( 6007846673558272820),
     -INT64_C( 2265888410887594764),
     UINT64_C(                   0) },
   {  INT64_C( 9160927138501202914),
     -INT64_C(  524970878510387539),
     UINT64_C(                   0) },
   {  INT64_C( 5040462918486993384),
      INT64_C( 2705724683769958702),
     UINT64_C(                   0) },
   { -INT64_C(  473045855704439490),
      INT64_C( 4238208662586090773),
                         UINT64_MAX },
   {  INT64_C( 4892260587991122765),
     -INT64_C( 1547412342135848418),
     UINT64_C(                   0) },
   {  INT64_C( 5181191478929181602),
     -INT64_C( 4162186453568170577),
     UINT64_C(                   0) },
   {  INT64_C(   75517635955332788),
      INT64_C( 2009706568804924492),
                         UINT64_MAX }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint64_t r = simde_vcltd_s64(test_vec[i].a, test_vec[i].b);
    simde_assert_equal_u64(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    int64_t a = simde_test_codegen_random_i64();
    int64_t b = simde_test_codegen_random_i64();
    uint64_t r = simde_vcltd_s64(a, b);

    simde_test_codegen_write_i64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i64(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcltd_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a;
    uint64_t b;
    uint64_t r;
  } test_vec[] = {
    { UINT64_C(13199469999607627188),
      UINT64_C(17475643578917670213),
                          UINT64_MAX },
    { UINT64_C( 9291426536416340492),
      UINT64_C(17318693780852396996),
                          UINT64_MAX },
    { UINT64_C(10941498941691552025),
      UINT64_C(10556677798004887888),
      UINT64_C(                   0) },
    { UINT64_C(14373927621614517189),
      UINT64_C( 7562489693708022726),
      UINT64_C(                   0) },
    { UINT64_C( 2208278725635197629),
      UINT64_C(11100016101477383154),
                          UINT64_MAX },
    { UINT64_C(14353550357350878568),
      UINT64_C( 5744549760829371905),
      UINT64_C(                   0) },
    { UINT64_C(10841012728057709191),
      UINT64_C(13073415685580726270),
                          UINT64_MAX },
    { UINT64_C( 1256314152064909992),
      UINT64_C( 9109404319922338185),
                          UINT64_MAX }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint64_t r = simde_vcltd_u64(test_vec[i].a, test_vec[i].b);
    simde_assert_equal_u64(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    uint64_t a = simde_test_codegen_random_u64();
    uint64_t b = simde_test_codegen_random_u64();
    uint64_t r = simde_vcltd_u64(a, b);

    simde_test_codegen_write_u64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u64(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vclts_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32_t a;
    simde_float32_t b;
    uint32_t r;
  } test_vec[] = {
    { SIMDE_FLOAT32_C(  -190.08),
      SIMDE_FLOAT32_C(   833.00),
                UINT32_MAX },
    { SIMDE_FLOAT32_C(   896.69),
      SIMDE_FLOAT32_C(   900.72),
                UINT32_MAX },
    { SIMDE_FLOAT32_C(  -980.09),
      SIMDE_FLOAT32_C(  -878.50),
                UINT32_MAX },
    { SIMDE_FLOAT32_C(  -545.23),
      SIMDE_FLOAT32_C(  -846.74),
      UINT32_C(         0) },
    { SIMDE_FLOAT32_C(  -227.24),
      SIMDE_FLOAT32_C(  -583.33),
      UINT32_C(         0) },
    { SIMDE_FLOAT32_C(  -329.70),
      SIMDE_FLOAT32_C(   600.18),
                UINT32_MAX },
    { SIMDE_FLOAT32_C(  -438.24),
      SIMDE_FLOAT32_C(   847.23),
                UINT32_MAX },
    { SIMDE_FLOAT32_C(   716.84),
      SIMDE_FLOAT32_C(  -704.38),
      UINT32_C(         0) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint32_t r = simde_vclts_f32(test_vec[i].a, test_vec[i].b);
    simde_assert_equal_u32(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32_t a = simde_test_codegen_random_f32(-1000, 1000);
    simde_float32_t b = simde_test_codegen_random_f32(-1000, 1000);
    uint32_t r = simde_vclts_f32(a, b);

    simde_test_codegen_write_f32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_f32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vclt_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vclt_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vclt_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vclt_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vclt_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vclt_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vclt_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vclt_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vclt_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vclt_u64)

SIMDE_TEST_FUNC_LIST_ENTRY(vcltq_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcltq_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vcltq_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vcltq_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcltq_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcltq_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vcltq_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vcltq_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcltq_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcltq_u64)

SIMDE_TEST_FUNC_LIST_ENTRY(vcltd_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vcltd_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vcltd_u64)
SIMDE_TEST_FUNC_LIST_ENTRY(vclts_f32)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
