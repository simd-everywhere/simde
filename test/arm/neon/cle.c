#define SIMDE_TEST_ARM_NEON_INSN cle

#include "test-neon.h"

/* Check that both of these work */
#if defined(__cplusplus)
  #include "../../../simde/arm/neon/cle.h"
#else
  #include "../../../simde/arm/neon.h"
#endif

static int
test_simde_vcle_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a[2];
    simde_float32 b[2];
    uint32_t r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   791.10), SIMDE_FLOAT32_C(   796.86) },
      { SIMDE_FLOAT32_C(   791.10), SIMDE_FLOAT32_C(   796.86) },
      {           UINT32_MAX,           UINT32_MAX } },
    { { SIMDE_FLOAT32_C(  -191.39), SIMDE_FLOAT32_C(  -320.84) },
      { SIMDE_FLOAT32_C(   186.39), SIMDE_FLOAT32_C(  -320.84) },
      {           UINT32_MAX,           UINT32_MAX } },
    { { SIMDE_FLOAT32_C(   401.94), SIMDE_FLOAT32_C(  -653.44) },
      { SIMDE_FLOAT32_C(  -526.24), SIMDE_FLOAT32_C(   298.37) },
      { UINT32_C(         0),           UINT32_MAX } },
    { { SIMDE_FLOAT32_C(   452.25), SIMDE_FLOAT32_C(   434.09) },
      { SIMDE_FLOAT32_C(   -83.69), SIMDE_FLOAT32_C(   224.54) },
      { UINT32_C(         0), UINT32_C(         0) } },
    { { SIMDE_FLOAT32_C(   828.36), SIMDE_FLOAT32_C(   113.27) },
      { SIMDE_FLOAT32_C(  -845.96), SIMDE_FLOAT32_C(   459.19) },
      { UINT32_C(         0),           UINT32_MAX } },
    { { SIMDE_FLOAT32_C(   705.27), SIMDE_FLOAT32_C(  -712.20) },
      { SIMDE_FLOAT32_C(   705.27), SIMDE_FLOAT32_C(   140.77) },
      {           UINT32_MAX,           UINT32_MAX } },
    { { SIMDE_FLOAT32_C(   640.57), SIMDE_FLOAT32_C(  -173.03) },
      { SIMDE_FLOAT32_C(   839.60), SIMDE_FLOAT32_C(  -173.03) },
      {           UINT32_MAX,           UINT32_MAX } },
    { { SIMDE_FLOAT32_C(   -38.70), SIMDE_FLOAT32_C(   -25.63) },
      { SIMDE_FLOAT32_C(   -38.70), SIMDE_FLOAT32_C(   357.76) },
      {           UINT32_MAX,           UINT32_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t a = simde_vld1_f32(test_vec[i].a);
    simde_float32x2_t b = simde_vld1_f32(test_vec[i].b);
    simde_uint32x2_t r = simde_vcle_f32(a, b);

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

    simde_uint32x2_t r = simde_vcle_f32(a, b);

    simde_test_arm_neon_write_f32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcle_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 a[1];
    simde_float64 b[1];
    uint64_t r[1];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(  -975.50) },
      { SIMDE_FLOAT64_C(   222.47) },
      {                    UINT64_MAX } },
    { { SIMDE_FLOAT64_C(   986.68) },
      { SIMDE_FLOAT64_C(   986.68) },
      {                    UINT64_MAX } },
    { { SIMDE_FLOAT64_C(   852.29) },
      { SIMDE_FLOAT64_C(   445.48) },
      { UINT64_C(                   0) } },
    { { SIMDE_FLOAT64_C(  -413.29) },
      { SIMDE_FLOAT64_C(   220.80) },
      {                    UINT64_MAX } },
    { { SIMDE_FLOAT64_C(    33.63) },
      { SIMDE_FLOAT64_C(  -513.00) },
      { UINT64_C(                   0) } },
    { { SIMDE_FLOAT64_C(  -232.79) },
      { SIMDE_FLOAT64_C(  -316.14) },
      { UINT64_C(                   0) } },
    { { SIMDE_FLOAT64_C(  -848.20) },
      { SIMDE_FLOAT64_C(  -848.20) },
      {                    UINT64_MAX } },
    { { SIMDE_FLOAT64_C(   855.66) },
      { SIMDE_FLOAT64_C(   630.93) },
      { UINT64_C(                   0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x1_t a = simde_vld1_f64(test_vec[i].a);
    simde_float64x1_t b = simde_vld1_f64(test_vec[i].b);
    simde_uint64x1_t r = simde_vcle_f64(a, b);

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

    simde_uint64x1_t r = simde_vcle_f64(a, b);

    simde_test_arm_neon_write_f64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x1(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcle_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[8];
    int8_t b[8];
    uint8_t r[8];
  } test_vec[] = {
    { { -INT8_C( 100),  INT8_C(  76),  INT8_C( 123), -INT8_C(  90),  INT8_C(  77),  INT8_C(   7),  INT8_C(  31), -INT8_C(   9) },
      { -INT8_C( 100),  INT8_C(  76), -INT8_C( 104), -INT8_C( 125),  INT8_C(  74),  INT8_C(   7),  INT8_C(  62), -INT8_C(  74) },
      {    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0) } },
    { {  INT8_C(  48), -INT8_C(  56), -INT8_C(   4),  INT8_C(  49),  INT8_C(  88),  INT8_C(  74),  INT8_C( 116), -INT8_C(  12) },
      {  INT8_C(  48), -INT8_C(  14), -INT8_C( 107),  INT8_C( 125),  INT8_C(  88), -INT8_C(  76),  INT8_C( 116), -INT8_C(  12) },
      {    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX } },
    { {  INT8_C(  84),  INT8_C(  26), -INT8_C(  64),  INT8_C(  55),  INT8_C(  61),  INT8_C(  40), -INT8_C(  96),  INT8_C( 111) },
      { -INT8_C(  15),  INT8_C(  26), -INT8_C(  96), -INT8_C(  79),  INT8_C( 100),  INT8_C(  23), -INT8_C(  96), -INT8_C( 107) },
      { UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0) } },
    { { -INT8_C( 108), -INT8_C(  49),  INT8_C(  52), -INT8_C(  88), -INT8_C(  94),  INT8_C(  47), -INT8_C(  71), -INT8_C(  38) },
      {  INT8_C(  55),  INT8_C( 121),  INT8_C(  17),  INT8_C( 117), -INT8_C(  94),  INT8_C(  47), -INT8_C(  28), -INT8_C( 109) },
      {    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0) } },
    { {  INT8_C(  46),  INT8_C(  32),  INT8_C(   8),  INT8_C(   2), -INT8_C(  36), -INT8_C(  46), -INT8_C(  20), -INT8_C( 115) },
      {  INT8_C(  46),  INT8_C(  32),  INT8_C(  25), -INT8_C(  76),  INT8_C(  86), -INT8_C(  46), -INT8_C( 114), -INT8_C( 115) },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX } },
    { {  INT8_C(  95), -INT8_C(  59), -INT8_C(  58),  INT8_C(  59), -INT8_C(  87), -INT8_C(  79), -INT8_C(  83), -INT8_C(  61) },
      {  INT8_C(  95), -INT8_C(  75), -INT8_C(  59),  INT8_C(  59),  INT8_C(  21), -INT8_C(  79), -INT8_C(  84),  INT8_C(  67) },
      {    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX } },
    { {  INT8_C(  21), -INT8_C(  45),  INT8_C(  16), -INT8_C(  12), -INT8_C(  98), -INT8_C(  67), -INT8_C( 126),  INT8_C(  59) },
      {  INT8_C(  21), -INT8_C(  45),  INT8_C(  16), -INT8_C(  65), -INT8_C(  36), -INT8_C(  67), -INT8_C( 126),  INT8_C(  59) },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX } },
    { { -INT8_C(  24), -INT8_C(  61),  INT8_C(  97), -INT8_C(   1), -INT8_C( 126),  INT8_C( 110),  INT8_C(   8),  INT8_C( 109) },
      {  INT8_C(  96),  INT8_C(  49),  INT8_C(  97), -INT8_C(   1), -INT8_C( 126),  INT8_C( 110),  INT8_C(   8), -INT8_C( 105) },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8_t a = simde_vld1_s8(test_vec[i].a);
    simde_int8x8_t b = simde_vld1_s8(test_vec[i].b);
    simde_uint8x8_t r = simde_vcle_s8(a, b);

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

    simde_uint8x8_t r = simde_vcle_s8(a, b);

    simde_test_arm_neon_write_i8x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcle_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[4];
    int16_t b[4];
    uint16_t r[4];
  } test_vec[] = {
    { { -INT16_C( 28046),  INT16_C( 20567), -INT16_C(  9917),  INT16_C( 11469) },
      { -INT16_C( 19367),  INT16_C( 18908),  INT16_C( 10036), -INT16_C(  3500) },
      {      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0) } },
    { {  INT16_C(  6763),  INT16_C( 15162), -INT16_C( 26685), -INT16_C( 10020) },
      {  INT16_C(   794), -INT16_C( 29559), -INT16_C(  8043), -INT16_C( 10020) },
      { UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX } },
    { {  INT16_C( 31190), -INT16_C( 28069), -INT16_C( 20728),  INT16_C( 22148) },
      {  INT16_C( 31190),  INT16_C( 16835), -INT16_C(   621),  INT16_C( 22141) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0) } },
    { {  INT16_C( 25501),  INT16_C( 12858),  INT16_C(  5699), -INT16_C(  1014) },
      {  INT16_C(  3775),  INT16_C(  7438),  INT16_C( 27375), -INT16_C(  2129) },
      { UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0) } },
    { {  INT16_C( 28744),  INT16_C( 16177), -INT16_C( 20978), -INT16_C( 23914) },
      {  INT16_C( 28744), -INT16_C(  6831), -INT16_C( 29741),  INT16_C(  5655) },
      {      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX } },
    { {  INT16_C(  8239),  INT16_C(  8062), -INT16_C( 15244), -INT16_C( 23530) },
      {  INT16_C( 25696),  INT16_C(  3219), -INT16_C( 15244), -INT16_C( 32180) },
      {      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0) } },
    { {  INT16_C( 19927),  INT16_C(  1797), -INT16_C( 31891), -INT16_C( 23749) },
      {  INT16_C( 19927),  INT16_C(  1797), -INT16_C( 31891), -INT16_C(  2010) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX } },
    { {  INT16_C( 12192), -INT16_C( 25055), -INT16_C( 16334),  INT16_C( 26263) },
      { -INT16_C( 17332), -INT16_C( 25055), -INT16_C( 16334),  INT16_C( 13507) },
      { UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t a = simde_vld1_s16(test_vec[i].a);
    simde_int16x4_t b = simde_vld1_s16(test_vec[i].b);
    simde_uint16x4_t r = simde_vcle_s16(a, b);

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

    simde_uint16x4_t r = simde_vcle_s16(a, b);

    simde_test_arm_neon_write_i16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcle_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[2];
    int32_t b[2];
    uint32_t r[2];
  } test_vec[] = {
    { { -INT32_C(  1899112561), -INT32_C(  2083733649) },
      { -INT32_C(  1426571674), -INT32_C(     8485340) },
      {           UINT32_MAX,           UINT32_MAX } },
    { { -INT32_C(   860232052),  INT32_C(  1455351675) },
      {  INT32_C(    62249150), -INT32_C(  2099558987) },
      {           UINT32_MAX, UINT32_C(         0) } },
    { { -INT32_C(  1462919358),  INT32_C(  2113244612) },
      {  INT32_C(   251777099),  INT32_C(  2113244612) },
      {           UINT32_MAX,           UINT32_MAX } },
    { {  INT32_C(   583472996),  INT32_C(   422865227) },
      { -INT32_C(  1792605758),  INT32_C(   422865227) },
      { UINT32_C(         0),           UINT32_MAX } },
    { {  INT32_C(   705979358), -INT32_C(   147253965) },
      { -INT32_C(    59494494),  INT32_C(  1729353888) },
      { UINT32_C(         0),           UINT32_MAX } },
    { {  INT32_C(  1267101753),  INT32_C(  1832636450) },
      {  INT32_C(  1267101753), -INT32_C(  1766955646) },
      {           UINT32_MAX, UINT32_C(         0) } },
    { {  INT32_C(  1306118315), -INT32_C(  1756803337) },
      {  INT32_C(   570383654),  INT32_C(   155378528) },
      { UINT32_C(         0),           UINT32_MAX } },
    { {  INT32_C(   315803097), -INT32_C(   954861330) },
      {  INT32_C(  1280117949), -INT32_C(   954861330) },
      {           UINT32_MAX,           UINT32_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t a = simde_vld1_s32(test_vec[i].a);
    simde_int32x2_t b = simde_vld1_s32(test_vec[i].b);
    simde_uint32x2_t r = simde_vcle_s32(a, b);

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

    simde_uint32x2_t r = simde_vcle_s32(a, b);

    simde_test_arm_neon_write_i32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcle_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a[1];
    int64_t b[1];
    uint64_t r[1];
  } test_vec[] = {
    { {  INT64_C( 8637217986458171406) },
      {  INT64_C( 7326912451601565845) },
      { UINT64_C(                   0) } },
    { {  INT64_C( 6706107946540577436) },
      {  INT64_C( 8712933937820291348) },
      {                    UINT64_MAX } },
    { {  INT64_C(  646593032519645204) },
      {  INT64_C( 2273665174117615427) },
      {                    UINT64_MAX } },
    { {  INT64_C( 6595974795757143079) },
      { -INT64_C( 5082613164841186952) },
      { UINT64_C(                   0) } },
    { { -INT64_C( 5146632559931370274) },
      { -INT64_C( 5146632559931370274) },
      {                    UINT64_MAX } },
    { {  INT64_C( 2241975906344229579) },
      { -INT64_C( 4514700189641056645) },
      { UINT64_C(                   0) } },
    { {  INT64_C( 7922964899174052536) },
      {  INT64_C( 8849835638844418162) },
      {                    UINT64_MAX } },
    { { -INT64_C( 2477221896963707100) },
      { -INT64_C( 1502892239977859308) },
      {                    UINT64_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x1_t a = simde_vld1_s64(test_vec[i].a);
    simde_int64x1_t b = simde_vld1_s64(test_vec[i].b);
    simde_uint64x1_t r = simde_vcle_s64(a, b);

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

    simde_uint64x1_t r = simde_vcle_s64(a, b);

    simde_test_arm_neon_write_i64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x1(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcle_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t a[8];
    uint8_t b[8];
    uint8_t r[8];
  } test_vec[] = {
    { { UINT8_C(192), UINT8_C( 53), UINT8_C(203), UINT8_C( 45), UINT8_C( 48), UINT8_C(108), UINT8_C(220), UINT8_C( 89) },
      { UINT8_C(196),    UINT8_MAX, UINT8_C(126), UINT8_C(235), UINT8_C(101), UINT8_C( 94), UINT8_C( 93), UINT8_C(247) },
      {    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX } },
    { { UINT8_C(249), UINT8_C( 38), UINT8_C(221), UINT8_C(  5), UINT8_C(109), UINT8_C(160), UINT8_C( 54), UINT8_C(211) },
      { UINT8_C(213), UINT8_C(  1), UINT8_C(  0), UINT8_C(  5), UINT8_C(109), UINT8_C(221), UINT8_C( 94), UINT8_C( 50) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0) } },
    { { UINT8_C( 11), UINT8_C(179), UINT8_C( 44), UINT8_C( 80), UINT8_C( 92), UINT8_C(169), UINT8_C( 45), UINT8_C( 85) },
      { UINT8_C(178), UINT8_C( 10), UINT8_C(115), UINT8_C(197), UINT8_C(170), UINT8_C(169), UINT8_C(153), UINT8_C(127) },
      {    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX } },
    { { UINT8_C(191), UINT8_C(103), UINT8_C( 62), UINT8_C(250), UINT8_C(226), UINT8_C(203), UINT8_C( 48), UINT8_C(189) },
      { UINT8_C(127), UINT8_C(126), UINT8_C( 62), UINT8_C(219), UINT8_C( 10), UINT8_C(107), UINT8_C( 48), UINT8_C(189) },
      { UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX } },
    { { UINT8_C(192), UINT8_C( 36), UINT8_C( 15), UINT8_C( 43), UINT8_C(221), UINT8_C( 89), UINT8_C(126), UINT8_C(199) },
      { UINT8_C(192), UINT8_C( 17), UINT8_C(193), UINT8_C(163), UINT8_C(221), UINT8_C( 19), UINT8_C(144), UINT8_C( 92) },
      {    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0) } },
    { { UINT8_C( 11), UINT8_C( 93), UINT8_C(208), UINT8_C( 87), UINT8_C(182), UINT8_C( 85), UINT8_C( 78), UINT8_C(171) },
      { UINT8_C(149), UINT8_C( 93), UINT8_C(215), UINT8_C(156), UINT8_C(182), UINT8_C( 85), UINT8_C( 99), UINT8_C(119) },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0) } },
    { { UINT8_C(121), UINT8_C( 51), UINT8_C(100), UINT8_C(179), UINT8_C(164), UINT8_C(189), UINT8_C( 99), UINT8_C( 73) },
      { UINT8_C(152), UINT8_C( 51), UINT8_C(160), UINT8_C(142), UINT8_C(164), UINT8_C(239), UINT8_C( 58), UINT8_C( 57) },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0) } },
    { { UINT8_C( 94), UINT8_C(148), UINT8_C( 16), UINT8_C(150), UINT8_C( 62), UINT8_C(205), UINT8_C( 13), UINT8_C(183) },
      { UINT8_C(134), UINT8_C(195), UINT8_C(106), UINT8_C(196), UINT8_C(128), UINT8_C(205), UINT8_C( 13), UINT8_C( 24) },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x8_t a = simde_vld1_u8(test_vec[i].a);
    simde_uint8x8_t b = simde_vld1_u8(test_vec[i].b);
    simde_uint8x8_t r = simde_vcle_u8(a, b);

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

    simde_uint8x8_t r = simde_vcle_u8(a, b);

    simde_test_arm_neon_write_u8x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcle_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[4];
    uint16_t b[4];
    uint16_t r[4];
  } test_vec[] = {
    { { UINT16_C(15609), UINT16_C(41202), UINT16_C(28612), UINT16_C(11885) },
      { UINT16_C(38027), UINT16_C(32348), UINT16_C(58641), UINT16_C(31115) },
      {      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX } },
    { { UINT16_C(25440), UINT16_C(54415), UINT16_C(51022), UINT16_C(25593) },
      { UINT16_C(25440), UINT16_C(22787), UINT16_C(62879), UINT16_C(25593) },
      {      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX } },
    { { UINT16_C(61179), UINT16_C(35880), UINT16_C(46853), UINT16_C(13190) },
      { UINT16_C(35022), UINT16_C(35880), UINT16_C(46853), UINT16_C(21600) },
      { UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX } },
    { { UINT16_C( 7833), UINT16_C(38000), UINT16_C(12828), UINT16_C(57248) },
      { UINT16_C( 7833), UINT16_C(38000), UINT16_C(56844), UINT16_C(57248) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX } },
    { { UINT16_C(15022), UINT16_C(46130), UINT16_C(37618), UINT16_C(28936) },
      { UINT16_C(11192), UINT16_C(16976), UINT16_C(35154), UINT16_C(28523) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { { UINT16_C( 5040), UINT16_C( 8681), UINT16_C(35135), UINT16_C( 5888) },
      { UINT16_C( 5040), UINT16_C(24253), UINT16_C(61261), UINT16_C(16146) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX } },
    { { UINT16_C(63454), UINT16_C(62619), UINT16_C(59274), UINT16_C(17927) },
      { UINT16_C(63454), UINT16_C(62619), UINT16_C(33880), UINT16_C(38677) },
      {      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX } },
    { { UINT16_C(26185), UINT16_C(30236), UINT16_C(12122), UINT16_C(56246) },
      { UINT16_C(26185), UINT16_C(36629), UINT16_C(37223), UINT16_C(61992) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4_t a = simde_vld1_u16(test_vec[i].a);
    simde_uint16x4_t b = simde_vld1_u16(test_vec[i].b);
    simde_uint16x4_t r = simde_vcle_u16(a, b);

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

    simde_uint16x4_t r = simde_vcle_u16(a, b);

    simde_test_arm_neon_write_u16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcle_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[2];
    uint32_t b[2];
    uint32_t r[2];
  } test_vec[] = {
    { { UINT32_C(3076618288), UINT32_C( 170876675) },
      { UINT32_C(1243736868), UINT32_C(3393524517) },
      { UINT32_C(         0),           UINT32_MAX } },
    { { UINT32_C( 403272314), UINT32_C(3921604021) },
      { UINT32_C( 403272314), UINT32_C(1704016132) },
      {           UINT32_MAX, UINT32_C(         0) } },
    { { UINT32_C(3919454404), UINT32_C( 808697611) },
      { UINT32_C(4277828050), UINT32_C(1259427829) },
      {           UINT32_MAX,           UINT32_MAX } },
    { { UINT32_C(3014666041), UINT32_C(2399389937) },
      { UINT32_C(3808648435), UINT32_C(2399389937) },
      {           UINT32_MAX,           UINT32_MAX } },
    { { UINT32_C( 557769807), UINT32_C(1394620765) },
      { UINT32_C(4187894160), UINT32_C(2820724728) },
      {           UINT32_MAX,           UINT32_MAX } },
    { { UINT32_C(1415009889), UINT32_C(2738379698) },
      { UINT32_C(3560127267), UINT32_C(2293793354) },
      {           UINT32_MAX, UINT32_C(         0) } },
    { { UINT32_C(1382663105), UINT32_C(3981117429) },
      { UINT32_C(1771400159), UINT32_C(2092955172) },
      {           UINT32_MAX, UINT32_C(         0) } },
    { { UINT32_C(4195714007), UINT32_C(  87118492) },
      { UINT32_C(1855030986), UINT32_C(  87118492) },
      { UINT32_C(         0),           UINT32_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2_t a = simde_vld1_u32(test_vec[i].a);
    simde_uint32x2_t b = simde_vld1_u32(test_vec[i].b);
    simde_uint32x2_t r = simde_vcle_u32(a, b);

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

    simde_uint32x2_t r = simde_vcle_u32(a, b);

    simde_test_arm_neon_write_u32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcle_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a[1];
    uint64_t b[1];
    uint64_t r[1];
  } test_vec[] = {
    { { UINT64_C(17342515446514902425) },
      { UINT64_C(17342515446514902425) },
      {                    UINT64_MAX } },
    { { UINT64_C( 3327773999065374941) },
      { UINT64_C(  300137521445377989) },
      { UINT64_C(                   0) } },
    { { UINT64_C( 7235656385619221034) },
      { UINT64_C(16482773610270905397) },
      {                    UINT64_MAX } },
    { { UINT64_C( 7613065674013128417) },
      { UINT64_C(  120471459712082775) },
      { UINT64_C(                   0) } },
    { { UINT64_C(14955085576460449004) },
      { UINT64_C(14955085576460449004) },
      {                    UINT64_MAX } },
    { { UINT64_C(15304861135706240155) },
      { UINT64_C(12909976860436499532) },
      { UINT64_C(                   0) } },
    { { UINT64_C(12171332214848831173) },
      { UINT64_C( 9589066105881297644) },
      { UINT64_C(                   0) } },
    { { UINT64_C(14169459702986888117) },
      { UINT64_C(14169459702986888117) },
      {                    UINT64_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x1_t a = simde_vld1_u64(test_vec[i].a);
    simde_uint64x1_t b = simde_vld1_u64(test_vec[i].b);
    simde_uint64x1_t r = simde_vcle_u64(a, b);

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

    simde_uint64x1_t r = simde_vcle_u64(a, b);

    simde_test_arm_neon_write_u64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x1(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcleq_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a[4];
    simde_float32 b[4];
    uint32_t r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -668.90), SIMDE_FLOAT32_C(   928.96), SIMDE_FLOAT32_C(   525.27), SIMDE_FLOAT32_C(   244.82) },
      { SIMDE_FLOAT32_C(   811.79), SIMDE_FLOAT32_C(   687.37), SIMDE_FLOAT32_C(   277.72), SIMDE_FLOAT32_C(   244.82) },
      {           UINT32_MAX, UINT32_C(         0), UINT32_C(         0),           UINT32_MAX } },
    { { SIMDE_FLOAT32_C(   696.43), SIMDE_FLOAT32_C(  -857.84), SIMDE_FLOAT32_C(   965.32), SIMDE_FLOAT32_C(   876.96) },
      { SIMDE_FLOAT32_C(  -631.72), SIMDE_FLOAT32_C(  -857.84), SIMDE_FLOAT32_C(  -893.87), SIMDE_FLOAT32_C(   876.96) },
      { UINT32_C(         0),           UINT32_MAX, UINT32_C(         0),           UINT32_MAX } },
    { { SIMDE_FLOAT32_C(  -771.07), SIMDE_FLOAT32_C(   967.77), SIMDE_FLOAT32_C(   429.01), SIMDE_FLOAT32_C(   260.39) },
      { SIMDE_FLOAT32_C(   702.86), SIMDE_FLOAT32_C(   636.28), SIMDE_FLOAT32_C(   429.01), SIMDE_FLOAT32_C(  -966.04) },
      {           UINT32_MAX, UINT32_C(         0),           UINT32_MAX, UINT32_C(         0) } },
    { { SIMDE_FLOAT32_C(  -358.35), SIMDE_FLOAT32_C(   497.18), SIMDE_FLOAT32_C(  -378.16), SIMDE_FLOAT32_C(   420.17) },
      { SIMDE_FLOAT32_C(  -508.71), SIMDE_FLOAT32_C(  -602.79), SIMDE_FLOAT32_C(   676.13), SIMDE_FLOAT32_C(  -812.29) },
      { UINT32_C(         0), UINT32_C(         0),           UINT32_MAX, UINT32_C(         0) } },
    { { SIMDE_FLOAT32_C(  -521.08), SIMDE_FLOAT32_C(  -618.79), SIMDE_FLOAT32_C(   530.55), SIMDE_FLOAT32_C(  -292.15) },
      { SIMDE_FLOAT32_C(  -521.08), SIMDE_FLOAT32_C(  -618.79), SIMDE_FLOAT32_C(   223.55), SIMDE_FLOAT32_C(  -292.15) },
      {           UINT32_MAX,           UINT32_MAX, UINT32_C(         0),           UINT32_MAX } },
    { { SIMDE_FLOAT32_C(  -808.90), SIMDE_FLOAT32_C(   397.25), SIMDE_FLOAT32_C(   133.37), SIMDE_FLOAT32_C(    -6.83) },
      { SIMDE_FLOAT32_C(  -648.47), SIMDE_FLOAT32_C(  -694.75), SIMDE_FLOAT32_C(   133.37), SIMDE_FLOAT32_C(    -6.83) },
      {           UINT32_MAX, UINT32_C(         0),           UINT32_MAX,           UINT32_MAX } },
    { { SIMDE_FLOAT32_C(   730.94), SIMDE_FLOAT32_C(  -785.96), SIMDE_FLOAT32_C(    91.33), SIMDE_FLOAT32_C(   514.55) },
      { SIMDE_FLOAT32_C(   730.94), SIMDE_FLOAT32_C(  -785.96), SIMDE_FLOAT32_C(    91.33), SIMDE_FLOAT32_C(   514.55) },
      {           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX } },
    { { SIMDE_FLOAT32_C(  -626.37), SIMDE_FLOAT32_C(   818.81), SIMDE_FLOAT32_C(   403.89), SIMDE_FLOAT32_C(   352.06) },
      { SIMDE_FLOAT32_C(  -626.37), SIMDE_FLOAT32_C(   207.79), SIMDE_FLOAT32_C(   403.89), SIMDE_FLOAT32_C(  -435.27) },
      {           UINT32_MAX, UINT32_C(         0),           UINT32_MAX, UINT32_C(         0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_float32x4_t b = simde_vld1q_f32(test_vec[i].b);
    simde_uint32x4_t r = simde_vcleq_f32(a, b);

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

    simde_uint32x4_t r = simde_vcleq_f32(a, b);

    simde_test_arm_neon_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcleq_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 a[2];
    simde_float64 b[2];
    uint64_t r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(   680.17), SIMDE_FLOAT64_C(  -515.06) },
      { SIMDE_FLOAT64_C(   718.41), SIMDE_FLOAT64_C(  -515.06) },
      {                    UINT64_MAX,                    UINT64_MAX } },
    { { SIMDE_FLOAT64_C(   113.48), SIMDE_FLOAT64_C(  -153.24) },
      { SIMDE_FLOAT64_C(  -711.61), SIMDE_FLOAT64_C(  -153.24) },
      { UINT64_C(                   0),                    UINT64_MAX } },
    { { SIMDE_FLOAT64_C(  -988.69), SIMDE_FLOAT64_C(   305.46) },
      { SIMDE_FLOAT64_C(   833.43), SIMDE_FLOAT64_C(   305.46) },
      {                    UINT64_MAX,                    UINT64_MAX } },
    { { SIMDE_FLOAT64_C(   993.85), SIMDE_FLOAT64_C(  -613.57) },
      { SIMDE_FLOAT64_C(   -18.63), SIMDE_FLOAT64_C(  -132.48) },
      { UINT64_C(                   0),                    UINT64_MAX } },
    { { SIMDE_FLOAT64_C(   720.10), SIMDE_FLOAT64_C(  -120.39) },
      { SIMDE_FLOAT64_C(   800.59), SIMDE_FLOAT64_C(  -120.39) },
      {                    UINT64_MAX,                    UINT64_MAX } },
    { { SIMDE_FLOAT64_C(   850.21), SIMDE_FLOAT64_C(   642.71) },
      { SIMDE_FLOAT64_C(   850.21), SIMDE_FLOAT64_C(  -236.33) },
      {                    UINT64_MAX, UINT64_C(                   0) } },
    { { SIMDE_FLOAT64_C(  -275.07), SIMDE_FLOAT64_C(   271.93) },
      { SIMDE_FLOAT64_C(  -275.07), SIMDE_FLOAT64_C(   271.93) },
      {                    UINT64_MAX,                    UINT64_MAX } },
    { { SIMDE_FLOAT64_C(   897.28), SIMDE_FLOAT64_C(  -900.81) },
      { SIMDE_FLOAT64_C(    83.69), SIMDE_FLOAT64_C(   730.71) },
      { UINT64_C(                   0),                    UINT64_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2_t a = simde_vld1q_f64(test_vec[i].a);
    simde_float64x2_t b = simde_vld1q_f64(test_vec[i].b);
    simde_uint64x2_t r = simde_vcleq_f64(a, b);

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

    simde_uint64x2_t r = simde_vcleq_f64(a, b);

    simde_test_arm_neon_write_f64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcleq_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[16];
    int8_t b[16];
    uint8_t r[16];
  } test_vec[] = {
    { {  INT8_C( 121),  INT8_C(  94),  INT8_C( 116),  INT8_C(  97), -INT8_C(  79), -INT8_C(  19), -INT8_C( 113),  INT8_C( 103),
        -INT8_C(  39),  INT8_C(   1),  INT8_C( 117),  INT8_C(   6),  INT8_C( 123),  INT8_C(  85),  INT8_C(  36), -INT8_C(  83) },
      { -INT8_C(  14),  INT8_C(  94), -INT8_C(  68),  INT8_C(  97), -INT8_C(  79), -INT8_C(  19), -INT8_C(  34),  INT8_C( 103),
        -INT8_C( 112), -INT8_C(  52),  INT8_C( 117),  INT8_C(   6), -INT8_C(  40), -INT8_C( 119),  INT8_C(  36),  INT8_C(  81) },
      { UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
        UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX } },
    { { -INT8_C(  19), -INT8_C( 104),  INT8_C(  93), -INT8_C(  98), -INT8_C( 123),  INT8_C(  59),  INT8_C(  52),  INT8_C(  21),
         INT8_C(   7),  INT8_C( 123),  INT8_C(  27), -INT8_C(  33), -INT8_C(  84),  INT8_C(  63), -INT8_C( 105),  INT8_C(  93) },
      { -INT8_C(  40),  INT8_C(  83), -INT8_C( 118), -INT8_C( 103),  INT8_C(   4), -INT8_C(  33),  INT8_C(  52), -INT8_C(  73),
        -INT8_C( 109),  INT8_C(  29), -INT8_C(  26), -INT8_C( 100), -INT8_C(  84), -INT8_C(  62), -INT8_C( 105), -INT8_C( 102) },
      { UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0) } },
    { { -INT8_C( 101), -INT8_C(  92),  INT8_C(  56), -INT8_C(  97), -INT8_C( 124), -INT8_C(  11), -INT8_C(  90), -INT8_C( 120),
         INT8_C(  18),  INT8_C(  61), -INT8_C(  77), -INT8_C(  65), -INT8_C(   1),  INT8_C(  74),  INT8_C(  89), -INT8_C(  96) },
      {  INT8_C(  63), -INT8_C( 111),  INT8_C(  56),  INT8_C( 111), -INT8_C(  49),  INT8_C(  44), -INT8_C(  90), -INT8_C( 120),
         INT8_C(  59), -INT8_C(  67),  INT8_C(  69), -INT8_C( 118),  INT8_C(   5),  INT8_C(  95), -INT8_C(  79), -INT8_C(  96) },
      {    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX } },
    { {  INT8_C(  35),  INT8_C( 100),  INT8_C(  74), -INT8_C(  14), -INT8_C( 112), -INT8_C(  15),  INT8_C(  90), -INT8_C(  53),
        -INT8_C(  82), -INT8_C(  64), -INT8_C(  46), -INT8_C(  76),  INT8_C(  32), -INT8_C(   2),  INT8_C(  21),  INT8_C(  36) },
      {  INT8_C( 121), -INT8_C( 108), -INT8_C(  84), -INT8_C(  32),  INT8_C(  43),  INT8_C(  75),  INT8_C(  90), -INT8_C(   1),
        -INT8_C(  99), -INT8_C( 110), -INT8_C(  46),  INT8_C(  57),  INT8_C(  36), -INT8_C(   2),  INT8_C(  21),  INT8_C(  71) },
      {    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
        UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX } },
    { { -INT8_C(   5),  INT8_C( 101), -INT8_C(  19), -INT8_C(  57), -INT8_C(  69), -INT8_C(  49),  INT8_C(  74),  INT8_C(  77),
         INT8_C(  98), -INT8_C( 103), -INT8_C( 122), -INT8_C( 122),  INT8_C(   5), -INT8_C( 101),  INT8_C( 111), -INT8_C(   6) },
      { -INT8_C(   5),  INT8_C(   6), -INT8_C(  19),  INT8_C(  75), -INT8_C(  69), -INT8_C(  85),  INT8_C(  74),  INT8_C(  48),
        -INT8_C(  65), -INT8_C(   3), -INT8_C(  59), -INT8_C(  38),  INT8_C(   5),  INT8_C( 126),  INT8_C( 111), -INT8_C(  95) },
      {    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),
        UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0) } },
    { { -INT8_C(  31), -INT8_C(  97),  INT8_C(  20),  INT8_C(  43), -INT8_C(  13), -INT8_C( 109),  INT8_C(  91), -INT8_C(  78),
        -INT8_C( 112),  INT8_C(  73), -INT8_C(   8),  INT8_C(  92), -INT8_C(  98), -INT8_C(   4),  INT8_C(  54),  INT8_C(  34) },
      { -INT8_C(  31), -INT8_C(  97),  INT8_C(  20), -INT8_C( 106), -INT8_C(  50), -INT8_C(  12), -INT8_C(  84), -INT8_C( 105),
         INT8_C(  90),  INT8_C(  73), -INT8_C(   8),  INT8_C(  92), -INT8_C(  78),  INT8_C(  84),  INT8_C(  89),  INT8_C(  34) },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX } },
    { {  INT8_C(  48),  INT8_C(  91),  INT8_C(  15), -INT8_C(   1), -INT8_C(  17), -INT8_C(  16), -INT8_C( 106), -INT8_C(  52),
         INT8_C(  57), -INT8_C(   9), -INT8_C(  90), -INT8_C(  19), -INT8_C( 119),  INT8_C(  26),  INT8_C(  14), -INT8_C(  71) },
      { -INT8_C(  94),  INT8_C(  91),  INT8_C(  15), -INT8_C(  41),  INT8_C(   4),  INT8_C(  82), -INT8_C( 100), -INT8_C(  52),
         INT8_C(  33), -INT8_C(   9),  INT8_C(  51), -INT8_C(  19), -INT8_C( 119),  INT8_C(  26), -INT8_C( 101), -INT8_C(  71) },
      { UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
        UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX } },
    { {  INT8_C(  92),  INT8_C(  80), -INT8_C( 106), -INT8_C(   7), -INT8_C(  94), -INT8_C(  27),  INT8_C(  45),  INT8_C(  43),
        -INT8_C(  37),  INT8_C(  96), -INT8_C(  20), -INT8_C( 116),  INT8_C( 122),  INT8_C(  76),  INT8_C(  69), -INT8_C( 112) },
      {  INT8_C(  42), -INT8_C(   2), -INT8_C( 106), -INT8_C(   7),  INT8_C(  77), -INT8_C(  27),  INT8_C(   0),  INT8_C(  43),
        -INT8_C(  37), -INT8_C(  13), -INT8_C(  20), -INT8_C(  47), -INT8_C(  12),  INT8_C(  44),  INT8_C( 105),  INT8_C(  81) },
      { UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,
           UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16_t a = simde_vld1q_s8(test_vec[i].a);
    simde_int8x16_t b = simde_vld1q_s8(test_vec[i].b);
    simde_uint8x16_t r = simde_vcleq_s8(a, b);

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

    simde_uint8x16_t r = simde_vcleq_s8(a, b);

    simde_test_arm_neon_write_i8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcleq_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[8];
    int16_t b[8];
    uint16_t r[8];
  } test_vec[] = {
    { { -INT16_C( 12376),  INT16_C(   989), -INT16_C(  1994), -INT16_C( 15026),  INT16_C(  5482),  INT16_C( 30632),  INT16_C( 13645),  INT16_C( 30025) },
      { -INT16_C( 30204), -INT16_C( 16382), -INT16_C(  1994),  INT16_C( 28933),  INT16_C(  5482), -INT16_C( 13335), -INT16_C( 23603),  INT16_C( 30025) },
      { UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX } },
    { { -INT16_C( 21413), -INT16_C( 29059), -INT16_C( 17695), -INT16_C(  6579),  INT16_C( 20292),  INT16_C( 31398), -INT16_C( 21689), -INT16_C( 19733) },
      { -INT16_C( 10815), -INT16_C( 29059), -INT16_C( 14728), -INT16_C(  5373),  INT16_C( 31725),  INT16_C(    41),  INT16_C( 11585), -INT16_C( 25430) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0) } },
    { {  INT16_C( 18145),  INT16_C(    12), -INT16_C( 18753), -INT16_C( 26467),  INT16_C( 22277),  INT16_C(  2131),  INT16_C( 17438),  INT16_C(  2921) },
      { -INT16_C( 27969),  INT16_C(    12), -INT16_C( 18753), -INT16_C( 26467), -INT16_C(  7550),  INT16_C(  2131), -INT16_C(  3212),  INT16_C( 21970) },
      { UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX } },
    { {  INT16_C(  8367),  INT16_C(  5669), -INT16_C(  1947),  INT16_C(  9177), -INT16_C(  6713), -INT16_C( 31197), -INT16_C( 16229), -INT16_C(  3931) },
      {  INT16_C( 29346),  INT16_C(  5669), -INT16_C(  1947), -INT16_C( 24725), -INT16_C(  5873),  INT16_C( 22475), -INT16_C( 21951), -INT16_C(  3931) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX } },
    { {  INT16_C( 30076), -INT16_C( 31559),  INT16_C(  4405), -INT16_C( 10187),  INT16_C( 23171),  INT16_C( 29943),  INT16_C( 18889),  INT16_C( 25224) },
      {  INT16_C( 21571), -INT16_C( 31559),  INT16_C( 24318), -INT16_C( 13964),  INT16_C( 13007),  INT16_C( 29943),  INT16_C( 18889),  INT16_C( 17888) },
      { UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0) } },
    { { -INT16_C( 17684),  INT16_C( 19452), -INT16_C(  9964), -INT16_C(  3183),  INT16_C( 23085), -INT16_C( 27930),  INT16_C( 20409),  INT16_C( 27898) },
      { -INT16_C(  4990),  INT16_C( 19452), -INT16_C(  9163), -INT16_C(  3183), -INT16_C(  4434), -INT16_C( 27930), -INT16_C( 19840),  INT16_C( 27898) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX } },
    { { -INT16_C( 19801),  INT16_C( 24700),  INT16_C( 28673), -INT16_C( 31768), -INT16_C(  7076), -INT16_C( 28209), -INT16_C(  8142),  INT16_C( 28292) },
      {  INT16_C( 27470), -INT16_C( 12799), -INT16_C(  1251), -INT16_C( 30406), -INT16_C(  6587),  INT16_C( 26889), -INT16_C(  8142), -INT16_C(  9799) },
      {      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0) } },
    { {  INT16_C( 12930), -INT16_C( 18978),  INT16_C(  6214), -INT16_C( 27596), -INT16_C( 14131),  INT16_C( 29496), -INT16_C( 25552),  INT16_C( 29993) },
      {  INT16_C( 12930), -INT16_C( 18978), -INT16_C( 26606), -INT16_C( 23410), -INT16_C( 14131),  INT16_C( 29496),  INT16_C( 20457), -INT16_C(  4234) },
      {      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_int16x8_t b = simde_vld1q_s16(test_vec[i].b);
    simde_uint16x8_t r = simde_vcleq_s16(a, b);

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

    simde_uint16x8_t r = simde_vcleq_s16(a, b);

    simde_test_arm_neon_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcleq_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[4];
    int32_t b[4];
    uint32_t r[4];
  } test_vec[] = {
    { { -INT32_C(  1229097861), -INT32_C(  1438720539), -INT32_C(  1267867935), -INT32_C(   898897228) },
      { -INT32_C(  1887772614), -INT32_C(   833866438), -INT32_C(   565620803),  INT32_C(   653947819) },
      { UINT32_C(         0),           UINT32_MAX,           UINT32_MAX,           UINT32_MAX } },
    { {  INT32_C(  1987517076), -INT32_C(  1389697799),  INT32_C(   142054862), -INT32_C(  1348996491) },
      { -INT32_C(   461446361), -INT32_C(   574437582),  INT32_C(   570670138),  INT32_C(   149938292) },
      { UINT32_C(         0),           UINT32_MAX,           UINT32_MAX,           UINT32_MAX } },
    { { -INT32_C(   508897369), -INT32_C(  1306519491),  INT32_C(   828552970), -INT32_C(   854204262) },
      { -INT32_C(   508897369),  INT32_C(   134459028), -INT32_C(  2012155250), -INT32_C(  1568895144) },
      {           UINT32_MAX,           UINT32_MAX, UINT32_C(         0), UINT32_C(         0) } },
    { {  INT32_C(  1076353589),  INT32_C(   745638289),  INT32_C(   284788585), -INT32_C(   218979490) },
      { -INT32_C(   537201327),  INT32_C(  1080560616), -INT32_C(   773593958),  INT32_C(   910597377) },
      { UINT32_C(         0),           UINT32_MAX, UINT32_C(         0),           UINT32_MAX } },
    { {  INT32_C(  1630922999), -INT32_C(   848220561),  INT32_C(   599811026), -INT32_C(   578552347) },
      {  INT32_C(  1602317253),  INT32_C(  1345414223),  INT32_C(  2055632642), -INT32_C(   578552347) },
      { UINT32_C(         0),           UINT32_MAX,           UINT32_MAX,           UINT32_MAX } },
    { { -INT32_C(  1779764589),  INT32_C(  1826480403),  INT32_C(  1638785180), -INT32_C(  1698615733) },
      { -INT32_C(  1779764589),  INT32_C(  1326411881),  INT32_C(  1378652781),  INT32_C(   866544203) },
      {           UINT32_MAX, UINT32_C(         0), UINT32_C(         0),           UINT32_MAX } },
    { {  INT32_C(  1444064233), -INT32_C(   190364247),  INT32_C(   126773364), -INT32_C(  1013155750) },
      {  INT32_C(  1444064233), -INT32_C(  1985397187), -INT32_C(  1027846232), -INT32_C(  1041324009) },
      {           UINT32_MAX, UINT32_C(         0), UINT32_C(         0), UINT32_C(         0) } },
    { {  INT32_C(  1074834892),  INT32_C(  1726878031),  INT32_C(   724032953), -INT32_C(   866761330) },
      {  INT32_C(   743833476),  INT32_C(  1726878031),  INT32_C(   724032953),  INT32_C(   809971300) },
      { UINT32_C(         0),           UINT32_MAX,           UINT32_MAX,           UINT32_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int32x4_t b = simde_vld1q_s32(test_vec[i].b);
    simde_uint32x4_t r = simde_vcleq_s32(a, b);

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

    simde_uint32x4_t r = simde_vcleq_s32(a, b);

    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcleq_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a[2];
    int64_t b[2];
    uint64_t r[2];
  } test_vec[] = {
    { {  INT64_C( 1875168629702030407), -INT64_C( 1585750502122760845) },
      {  INT64_C( 1154389533265603449), -INT64_C( 5056224679567743638) },
      { UINT64_C(                   0), UINT64_C(                   0) } },
    { { -INT64_C( 4677112269914828356),  INT64_C(  802626250274728057) },
      {  INT64_C( 3150738932241681806), -INT64_C( 6912465892998042863) },
      {                    UINT64_MAX, UINT64_C(                   0) } },
    { { -INT64_C(    8666382967555742), -INT64_C( 9215193599598120020) },
      {  INT64_C( 9189381345098103458),  INT64_C( 7881448929588112162) },
      {                    UINT64_MAX,                    UINT64_MAX } },
    { {  INT64_C( 4178212053687777766), -INT64_C( 7496719103440436358) },
      {  INT64_C(  232014033692395846), -INT64_C( 7496719103440436358) },
      { UINT64_C(                   0),                    UINT64_MAX } },
    { {  INT64_C( 4653644453121343583),  INT64_C( 6586356358846238713) },
      {  INT64_C( 9203419145484562237),  INT64_C( 7004173850729278199) },
      {                    UINT64_MAX,                    UINT64_MAX } },
    { {  INT64_C( 8304329466640869147),  INT64_C( 6665286354400067540) },
      {  INT64_C( 8304329466640869147),  INT64_C( 6665286354400067540) },
      {                    UINT64_MAX,                    UINT64_MAX } },
    { {  INT64_C( 7324496898826677287),  INT64_C( 1947053861784541097) },
      {  INT64_C( 7324496898826677287),  INT64_C( 5720880642963490271) },
      {                    UINT64_MAX,                    UINT64_MAX } },
    { { -INT64_C( 3451453209207438179),  INT64_C( 7172065285969757399) },
      {  INT64_C( 5520034412839479216),  INT64_C( 3082938850326232440) },
      {                    UINT64_MAX, UINT64_C(                   0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);
    simde_int64x2_t b = simde_vld1q_s64(test_vec[i].b);
    simde_uint64x2_t r = simde_vcleq_s64(a, b);

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

    simde_uint64x2_t r = simde_vcleq_s64(a, b);

    simde_test_arm_neon_write_i64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcleq_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t a[16];
    uint8_t b[16];
    uint8_t r[16];
  } test_vec[] = {
    { { UINT8_C(235), UINT8_C(181), UINT8_C(209), UINT8_C( 50), UINT8_C(176), UINT8_C( 16), UINT8_C(247), UINT8_C(  5),
        UINT8_C(145), UINT8_C( 67), UINT8_C( 27), UINT8_C(161), UINT8_C( 21), UINT8_C( 85), UINT8_C(225), UINT8_C(136) },
      { UINT8_C(235), UINT8_C(141), UINT8_C(202), UINT8_C(238), UINT8_C(250), UINT8_C( 16), UINT8_C(247), UINT8_C(  5),
        UINT8_C( 85), UINT8_C(166), UINT8_C( 27), UINT8_C(128), UINT8_C( 21), UINT8_C(188), UINT8_C(228), UINT8_C(202) },
      {    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
        UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX } },
    { { UINT8_C(217), UINT8_C( 62), UINT8_C(221), UINT8_C(211), UINT8_C( 78), UINT8_C(212), UINT8_C(189), UINT8_C(163),
        UINT8_C(123), UINT8_C(244), UINT8_C( 35), UINT8_C(144), UINT8_C(176), UINT8_C( 46), UINT8_C( 15), UINT8_C( 34) },
      { UINT8_C(189), UINT8_C( 87), UINT8_C( 67), UINT8_C(244), UINT8_C(241), UINT8_C(109), UINT8_C(189), UINT8_C(205),
        UINT8_C( 28), UINT8_C( 40), UINT8_C(185), UINT8_C( 32), UINT8_C(115), UINT8_C( 46), UINT8_C( 15), UINT8_C( 76) },
      { UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,
        UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX } },
    { { UINT8_C(125), UINT8_C(  0), UINT8_C( 59), UINT8_C(110), UINT8_C(111), UINT8_C(248), UINT8_C(162), UINT8_C(139),
        UINT8_C( 43), UINT8_C(110), UINT8_C(130), UINT8_C(181), UINT8_C( 35), UINT8_C(186), UINT8_C(224), UINT8_C( 17) },
      { UINT8_C(166), UINT8_C(  0), UINT8_C( 75), UINT8_C(103), UINT8_C(249), UINT8_C(169), UINT8_C(162), UINT8_C(229),
        UINT8_C( 43), UINT8_C(110), UINT8_C(130), UINT8_C(181), UINT8_C(148), UINT8_C( 65), UINT8_C(251), UINT8_C( 17) },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX } },
    { { UINT8_C(196), UINT8_C(176), UINT8_C( 94), UINT8_C(155), UINT8_C( 89), UINT8_C(157), UINT8_C(163), UINT8_C(133),
        UINT8_C(136), UINT8_C( 37), UINT8_C( 58), UINT8_C( 45), UINT8_C(103), UINT8_C( 53), UINT8_C(104), UINT8_C(171) },
      { UINT8_C(108), UINT8_C(232), UINT8_C( 94), UINT8_C(155), UINT8_C(164), UINT8_C(157), UINT8_C(234), UINT8_C( 86),
        UINT8_C(136), UINT8_C(206), UINT8_C( 43), UINT8_C( 45), UINT8_C(146), UINT8_C(144), UINT8_C(120), UINT8_C( 86) },
      { UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),
           UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0) } },
    { { UINT8_C(235), UINT8_C( 74), UINT8_C(122), UINT8_C(143), UINT8_C(234), UINT8_C(127), UINT8_C(  6), UINT8_C(114),
        UINT8_C( 77), UINT8_C( 16), UINT8_C(159), UINT8_C(223), UINT8_C(162), UINT8_C( 15), UINT8_C(121), UINT8_C(224) },
      { UINT8_C( 67), UINT8_C( 74), UINT8_C(122), UINT8_C(195), UINT8_C(  1), UINT8_C(152), UINT8_C(  6), UINT8_C(221),
        UINT8_C(241), UINT8_C(160), UINT8_C( 33), UINT8_C(127), UINT8_C(162), UINT8_C( 15), UINT8_C(121), UINT8_C(141) },
      { UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0) } },
    { { UINT8_C( 58), UINT8_C( 14), UINT8_C(119), UINT8_C( 59), UINT8_C(108), UINT8_C(125), UINT8_C(  6), UINT8_C(127),
           UINT8_MAX, UINT8_C( 58), UINT8_C( 22), UINT8_C(191), UINT8_C( 73), UINT8_C(143), UINT8_C( 77), UINT8_C(166) },
      { UINT8_C(157), UINT8_C(106), UINT8_C(237), UINT8_C( 43), UINT8_C(108), UINT8_C(166), UINT8_C(  6), UINT8_C(127),
           UINT8_MAX, UINT8_C(192), UINT8_C( 51), UINT8_C(112), UINT8_C(177), UINT8_C(199), UINT8_C( 36), UINT8_C(235) },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX } },
    { { UINT8_C(172), UINT8_C( 86), UINT8_C(129), UINT8_C( 24), UINT8_C( 75), UINT8_C(245), UINT8_C(152), UINT8_C(197),
        UINT8_C( 72), UINT8_C(112), UINT8_C(137), UINT8_C(249), UINT8_C(146), UINT8_C(145), UINT8_C(228), UINT8_C(103) },
      { UINT8_C( 45), UINT8_C( 11), UINT8_C(226), UINT8_C( 69), UINT8_C( 75), UINT8_C(245), UINT8_C(123), UINT8_C(197),
        UINT8_C( 31), UINT8_C(112), UINT8_C(137), UINT8_C(216), UINT8_C(178), UINT8_C(242), UINT8_C( 46), UINT8_C( 94) },
      { UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,
        UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0) } },
    { { UINT8_C(104), UINT8_C( 37), UINT8_C(179), UINT8_C(183), UINT8_C(170), UINT8_C( 46), UINT8_C( 55), UINT8_C( 13),
        UINT8_C(158), UINT8_C(  2), UINT8_C(120), UINT8_C( 80), UINT8_C(245), UINT8_C(208), UINT8_C(174), UINT8_C( 62) },
      { UINT8_C(128), UINT8_C( 37), UINT8_C(132), UINT8_C(183), UINT8_C( 51), UINT8_C(198), UINT8_C( 55), UINT8_C( 13),
        UINT8_C(118), UINT8_C(175), UINT8_C(120), UINT8_C(183), UINT8_C( 12), UINT8_C( 75), UINT8_C( 37), UINT8_C(117) },
      {    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
        UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x16_t a = simde_vld1q_u8(test_vec[i].a);
    simde_uint8x16_t b = simde_vld1q_u8(test_vec[i].b);
    simde_uint8x16_t r = simde_vcleq_u8(a, b);

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

    simde_uint8x16_t r = simde_vcleq_u8(a, b);

    simde_test_arm_neon_write_u8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcleq_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[8];
    uint16_t b[8];
    uint16_t r[8];
  } test_vec[] = {
    { { UINT16_C(22479), UINT16_C(48311), UINT16_C(59303), UINT16_C( 1712), UINT16_C(52292), UINT16_C( 1671), UINT16_C(39280), UINT16_C(38684) },
      { UINT16_C(21616), UINT16_C( 4985), UINT16_C(42330), UINT16_C( 1712), UINT16_C(52292), UINT16_C(22407), UINT16_C(  945), UINT16_C(33083) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0) } },
    { { UINT16_C(18980), UINT16_C(38204), UINT16_C(23011), UINT16_C(21292), UINT16_C(42669), UINT16_C( 1895), UINT16_C( 5963), UINT16_C( 7461) },
      { UINT16_C(38371), UINT16_C(38375), UINT16_C( 9113), UINT16_C(62230), UINT16_C(21269), UINT16_C(61429), UINT16_C(47352), UINT16_C( 7461) },
      {      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX } },
    { { UINT16_C(41348), UINT16_C(53359), UINT16_C(37965), UINT16_C(39776), UINT16_C(25077), UINT16_C(44080), UINT16_C(18026), UINT16_C(32927) },
      { UINT16_C(38041), UINT16_C(37487), UINT16_C(37965), UINT16_C(20655), UINT16_C(25077), UINT16_C(45110), UINT16_C(28735), UINT16_C(50200) },
      { UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX } },
    { { UINT16_C(38203), UINT16_C(42692), UINT16_C(25564), UINT16_C(29990), UINT16_C(38392), UINT16_C(17671), UINT16_C(46633), UINT16_C(56971) },
      { UINT16_C(51991), UINT16_C(22478), UINT16_C(58940), UINT16_C(19739), UINT16_C(44910), UINT16_C(29463), UINT16_C(31907), UINT16_C(56971) },
      {      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX } },
    { { UINT16_C(27199), UINT16_C(26863), UINT16_C(43116), UINT16_C(32475), UINT16_C(21840), UINT16_C(35983), UINT16_C(52746), UINT16_C(43737) },
      { UINT16_C(61529), UINT16_C(64541), UINT16_C(43116), UINT16_C(32475), UINT16_C(24567), UINT16_C(43371), UINT16_C(52746), UINT16_C(18772) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0) } },
    { { UINT16_C( 8846), UINT16_C(51876), UINT16_C(32204), UINT16_C(52144), UINT16_C(37230), UINT16_C(55842), UINT16_C(47259), UINT16_C(10833) },
      { UINT16_C(50269), UINT16_C(26586), UINT16_C(11922), UINT16_C(52144), UINT16_C(25201), UINT16_C(14629), UINT16_C(47259), UINT16_C(10833) },
      {      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX } },
    { { UINT16_C(61434), UINT16_C(13499), UINT16_C( 5356), UINT16_C(18788), UINT16_C(16088), UINT16_C(27312), UINT16_C(24806), UINT16_C(57778) },
      { UINT16_C(23491), UINT16_C(24343), UINT16_C(26899), UINT16_C(60809), UINT16_C(32094), UINT16_C(53652), UINT16_C(24806), UINT16_C(57778) },
      { UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX } },
    { { UINT16_C(14008), UINT16_C(42675), UINT16_C(64151), UINT16_C(23042), UINT16_C(40147), UINT16_C(27065), UINT16_C(17027), UINT16_C(57687) },
      { UINT16_C(60352), UINT16_C(42675), UINT16_C(25931), UINT16_C(39815), UINT16_C(40147), UINT16_C(21975), UINT16_C(23574), UINT16_C(52911) },
      {      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);
    simde_uint16x8_t b = simde_vld1q_u16(test_vec[i].b);
    simde_uint16x8_t r = simde_vcleq_u16(a, b);

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

    simde_uint16x8_t r = simde_vcleq_u16(a, b);

    simde_test_arm_neon_write_u16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcleq_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[4];
    uint32_t b[4];
    uint32_t r[4];
  } test_vec[] = {
    { { UINT32_C(2381386769), UINT32_C(3176466564), UINT32_C( 571499645), UINT32_C(2801129909) },
      { UINT32_C( 974744019), UINT32_C(3176466564), UINT32_C(2645856096), UINT32_C(3366276535) },
      { UINT32_C(         0),           UINT32_MAX,           UINT32_MAX,           UINT32_MAX } },
    { { UINT32_C(2953658930), UINT32_C(1557274022), UINT32_C(3389179895), UINT32_C(3036945201) },
      { UINT32_C(2205374755), UINT32_C(2669684712), UINT32_C(3597190772), UINT32_C(2406333788) },
      { UINT32_C(         0),           UINT32_MAX,           UINT32_MAX, UINT32_C(         0) } },
    { { UINT32_C(2382500247), UINT32_C( 161785772), UINT32_C(1687687524), UINT32_C(2680566455) },
      { UINT32_C(3460294233), UINT32_C( 161785772), UINT32_C(1687687524), UINT32_C( 571201419) },
      {           UINT32_MAX,           UINT32_MAX,           UINT32_MAX, UINT32_C(         0) } },
    { { UINT32_C( 835324434), UINT32_C( 577597079), UINT32_C( 348011195), UINT32_C(3454205216) },
      { UINT32_C( 148276900), UINT32_C( 577597079), UINT32_C( 759527493), UINT32_C(2548954757) },
      { UINT32_C(         0),           UINT32_MAX,           UINT32_MAX, UINT32_C(         0) } },
    { { UINT32_C(3979565736), UINT32_C(1478129874), UINT32_C(3848598081), UINT32_C( 283982457) },
      { UINT32_C(3979565736), UINT32_C(1478129874), UINT32_C(1861159022), UINT32_C(  14006463) },
      {           UINT32_MAX,           UINT32_MAX, UINT32_C(         0), UINT32_C(         0) } },
    { { UINT32_C(2688045874), UINT32_C(2009426174), UINT32_C(1267184547), UINT32_C(3745650239) },
      { UINT32_C(2688045874), UINT32_C( 453912411), UINT32_C(3575375072), UINT32_C(3745650239) },
      {           UINT32_MAX, UINT32_C(         0),           UINT32_MAX,           UINT32_MAX } },
    { { UINT32_C(1368884654), UINT32_C(1167924792), UINT32_C( 187029209), UINT32_C(2242665769) },
      { UINT32_C(1705032325), UINT32_C(3728391070), UINT32_C(4089281745), UINT32_C(1897102530) },
      {           UINT32_MAX,           UINT32_MAX,           UINT32_MAX, UINT32_C(         0) } },
    { { UINT32_C( 277882431), UINT32_C(1605215285), UINT32_C(3419805642), UINT32_C(3001844756) },
      { UINT32_C( 277882431), UINT32_C(1694780835), UINT32_C(3419805642), UINT32_C(2332400066) },
      {           UINT32_MAX,           UINT32_MAX,           UINT32_MAX, UINT32_C(         0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint32x4_t b = simde_vld1q_u32(test_vec[i].b);
    simde_uint32x4_t r = simde_vcleq_u32(a, b);

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

    simde_uint32x4_t r = simde_vcleq_u32(a, b);

    simde_test_arm_neon_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcleq_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a[2];
    uint64_t b[2];
    uint64_t r[2];
  } test_vec[] = {
    { { UINT64_C( 7031255301956804898), UINT64_C( 1474450428294761441) },
      { UINT64_C(14583465103520464217), UINT64_C(12298299828163413800) },
      {                    UINT64_MAX,                    UINT64_MAX } },
    { { UINT64_C( 3994920236002142288), UINT64_C(  216978030592215567) },
      { UINT64_C(17908294585149505949), UINT64_C(  752740750983040994) },
      {                    UINT64_MAX,                    UINT64_MAX } },
    { { UINT64_C( 6431661480201425578), UINT64_C(17079525600081545155) },
      { UINT64_C( 6431661480201425578), UINT64_C(17526685962885593961) },
      {                    UINT64_MAX,                    UINT64_MAX } },
    { { UINT64_C( 5292068948174131764), UINT64_C(17385868151557196591) },
      { UINT64_C( 5292068948174131764), UINT64_C(13525532790163338768) },
      {                    UINT64_MAX, UINT64_C(                   0) } },
    { { UINT64_C( 7981490243528583350), UINT64_C(15931039649777347335) },
      { UINT64_C( 5477147589066124571), UINT64_C(15931039649777347335) },
      { UINT64_C(                   0),                    UINT64_MAX } },
    { { UINT64_C( 4288175162100042517), UINT64_C(16470940607178522469) },
      { UINT64_C( 4288175162100042517), UINT64_C( 1969053279587903843) },
      {                    UINT64_MAX, UINT64_C(                   0) } },
    { { UINT64_C(17673668134669041266), UINT64_C(  108811382467493027) },
      { UINT64_C(18146705304218835370), UINT64_C(16932089260167093638) },
      {                    UINT64_MAX,                    UINT64_MAX } },
    { { UINT64_C(10894539657245827952), UINT64_C( 4324253423461110374) },
      { UINT64_C(14498721430600439298), UINT64_C(  626635421977587112) },
      {                    UINT64_MAX, UINT64_C(                   0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x2_t a = simde_vld1q_u64(test_vec[i].a);
    simde_uint64x2_t b = simde_vld1q_u64(test_vec[i].b);
    simde_uint64x2_t r = simde_vcleq_u64(a, b);

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

    simde_uint64x2_t r = simde_vcleq_u64(a, b);

    simde_test_arm_neon_write_u64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcled_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64_t a;
    simde_float64_t b;
    uint64_t r;
  } test_vec[] = {
    { SIMDE_FLOAT64_C(  -305.11),
      SIMDE_FLOAT64_C(  -236.09),
                          UINT64_MAX },
    { SIMDE_FLOAT64_C(   921.92),
      SIMDE_FLOAT64_C(   733.85),
      UINT64_C(                   0) },
    { SIMDE_FLOAT64_C(  -486.91),
      SIMDE_FLOAT64_C(   623.76),
                          UINT64_MAX },
    { SIMDE_FLOAT64_C(  -463.48),
      SIMDE_FLOAT64_C(  -725.12),
      UINT64_C(                   0) },
    { SIMDE_FLOAT64_C(  -340.50),
      SIMDE_FLOAT64_C(   856.54),
                          UINT64_MAX },
    { SIMDE_FLOAT64_C(  -716.95),
      SIMDE_FLOAT64_C(    55.73),
                          UINT64_MAX },
    { SIMDE_FLOAT64_C(  -230.29),
      SIMDE_FLOAT64_C(  -777.07),
      UINT64_C(                   0) },
    { SIMDE_FLOAT64_C(  -322.84),
      SIMDE_FLOAT64_C(   432.77),
                          UINT64_MAX }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint64_t r = simde_vcled_f64(test_vec[i].a, test_vec[i].b);
    simde_assert_equal_u64(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64_t a = simde_test_codegen_random_f64(-1000, 1000);
    simde_float64_t b = simde_test_codegen_random_f64(-1000, 1000);
    uint64_t r = simde_vcled_f64(a, b);

    simde_test_codegen_write_f64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_f64(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcled_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a;
    int64_t b;
    uint64_t r;
  } test_vec[] = {
    {  INT64_C( 1693521115750436170),
      -INT64_C( 3888653578582840719),
      UINT64_C(                   0) },
    {  INT64_C( 5257715414734765947),
       INT64_C( 2276217586990052365),
      UINT64_C(                   0) },
    { -INT64_C( 8223843280110320820),
       INT64_C( 1849835537639662773),
                          UINT64_MAX },
    {  INT64_C( 4397546442680567662),
       INT64_C( 2027099013263462701),
      UINT64_C(                   0) },
    {  INT64_C( 7773147769218575158),
       INT64_C( 2549028272055568040),
      UINT64_C(                   0) },
    {  INT64_C(  679175870948221695),
       INT64_C( 8351693777404660219),
                          UINT64_MAX },
    {  INT64_C( 4105493476102491352),
       INT64_C( 4342557720306402666),
                          UINT64_MAX },
    {  INT64_C(  748959899008574847),
       INT64_C( 8435732057402208096),
                          UINT64_MAX }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint64_t r = simde_vcled_s64(test_vec[i].a, test_vec[i].b);
    simde_assert_equal_u64(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    int64_t a = simde_test_codegen_random_i64();
    int64_t b = simde_test_codegen_random_i64();
    uint64_t r = simde_vcled_s64(a, b);

    simde_test_codegen_write_i64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i64(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcled_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a;
    uint64_t b;
    uint64_t r;
  } test_vec[] = {
    { UINT64_C(16524267212941547145),
      UINT64_C( 3223249864016383810),
      UINT64_C(                   0) },
    { UINT64_C( 6811672435386426989),
      UINT64_C(11775800435636133210),
                          UINT64_MAX },
    { UINT64_C(12628952539174039523),
      UINT64_C(18353552287922538716),
                          UINT64_MAX },
    { UINT64_C( 9325831290852424464),
      UINT64_C( 6277143169552901983),
      UINT64_C(                   0) },
    { UINT64_C(13938633037399316563),
      UINT64_C(11011299473229520193),
      UINT64_C(                   0) },
    { UINT64_C(12457258167826795066),
      UINT64_C(10467564267655027065),
      UINT64_C(                   0) },
    { UINT64_C( 3729755587036182811),
      UINT64_C( 4935333909924940893),
                          UINT64_MAX },
    { UINT64_C(12544924326037889822),
      UINT64_C(11218150562683698912),
      UINT64_C(                   0) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint64_t r = simde_vcled_u64(test_vec[i].a, test_vec[i].b);
    simde_assert_equal_u64(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    uint64_t a = simde_test_codegen_random_u64();
    uint64_t b = simde_test_codegen_random_u64();
    uint64_t r = simde_vcled_u64(a, b);

    simde_test_codegen_write_u64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u64(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcles_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32_t a;
    simde_float32_t b;
    uint32_t r;
  } test_vec[] = {
    { SIMDE_FLOAT32_C(  -462.77),
      SIMDE_FLOAT32_C(  -563.18),
      UINT32_C(         0) },
    { SIMDE_FLOAT32_C(  -590.17),
      SIMDE_FLOAT32_C(   687.19),
                UINT32_MAX },
    { SIMDE_FLOAT32_C(   198.94),
      SIMDE_FLOAT32_C(  -270.32),
      UINT32_C(         0) },
    { SIMDE_FLOAT32_C(   -57.87),
      SIMDE_FLOAT32_C(  -211.45),
      UINT32_C(         0) },
    { SIMDE_FLOAT32_C(  -623.27),
      SIMDE_FLOAT32_C(   512.37),
                UINT32_MAX },
    { SIMDE_FLOAT32_C(  -869.47),
      SIMDE_FLOAT32_C(    30.49),
                UINT32_MAX },
    { SIMDE_FLOAT32_C(   837.56),
      SIMDE_FLOAT32_C(   837.84),
                UINT32_MAX },
    { SIMDE_FLOAT32_C(    98.31),
      SIMDE_FLOAT32_C(  -717.52),
      UINT32_C(         0) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint32_t r = simde_vcles_f32(test_vec[i].a, test_vec[i].b);
    simde_assert_equal_u32(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32_t a = simde_test_codegen_random_f32(-1000, 1000);
    simde_float32_t b = simde_test_codegen_random_f32(-1000, 1000);
    uint32_t r = simde_vcles_f32(a, b);

    simde_test_codegen_write_f32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_f32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vcle_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcle_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vcle_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vcle_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcle_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcle_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vcle_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vcle_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcle_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcle_u64)

SIMDE_TEST_FUNC_LIST_ENTRY(vcleq_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcleq_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vcleq_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vcleq_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcleq_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcleq_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vcleq_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vcleq_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcleq_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcleq_u64)

SIMDE_TEST_FUNC_LIST_ENTRY(vcled_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vcled_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vcled_u64)
SIMDE_TEST_FUNC_LIST_ENTRY(vcles_f32)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
