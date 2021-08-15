#define SIMDE_TEST_ARM_NEON_INSN cge

#include "test-neon.h"

/* Check that both of these work */
#if defined(__cplusplus)
  #include "../../../simde/arm/neon/cge.h"
#else
  #include "../../../simde/arm/neon.h"
#endif

static int
test_simde_vcge_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16 a[4];
    simde_float16 b[4];
    uint16_t r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT16_VALUE(  -632.50), SIMDE_FLOAT16_VALUE(   581.50), SIMDE_FLOAT16_VALUE(  -412.25), SIMDE_FLOAT16_VALUE(  -375.00) },
      { SIMDE_FLOAT16_VALUE(  -320.00), SIMDE_FLOAT16_VALUE(   581.50), SIMDE_FLOAT16_VALUE(  -412.25), SIMDE_FLOAT16_VALUE(  -252.00) },
      { UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0) } },
    { { SIMDE_FLOAT16_VALUE(   498.25), SIMDE_FLOAT16_VALUE(   -49.16), SIMDE_FLOAT16_VALUE(   377.00), SIMDE_FLOAT16_VALUE(  -585.50) },
      { SIMDE_FLOAT16_VALUE(   818.00), SIMDE_FLOAT16_VALUE(   -49.16), SIMDE_FLOAT16_VALUE(   377.00), SIMDE_FLOAT16_VALUE(  -206.25) },
      { UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0) } },
    { { SIMDE_FLOAT16_VALUE(  -391.50), SIMDE_FLOAT16_VALUE(  -258.50), SIMDE_FLOAT16_VALUE(   -94.44), SIMDE_FLOAT16_VALUE(   439.25) },
      { SIMDE_FLOAT16_VALUE(  -122.81), SIMDE_FLOAT16_VALUE(  -113.81), SIMDE_FLOAT16_VALUE(  -782.00), SIMDE_FLOAT16_VALUE(   244.50) },
      { UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX } },
    { { SIMDE_FLOAT16_VALUE(  -363.50), SIMDE_FLOAT16_VALUE(  -600.00), SIMDE_FLOAT16_VALUE(  -807.00), SIMDE_FLOAT16_VALUE(   732.00) },
      { SIMDE_FLOAT16_VALUE(   -32.78), SIMDE_FLOAT16_VALUE(  -600.00), SIMDE_FLOAT16_VALUE(   -52.06), SIMDE_FLOAT16_VALUE(  -534.50) },
      { UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX } },
    { { SIMDE_FLOAT16_VALUE(   177.00), SIMDE_FLOAT16_VALUE(  -742.50), SIMDE_FLOAT16_VALUE(   795.50), SIMDE_FLOAT16_VALUE(   171.12) },
      { SIMDE_FLOAT16_VALUE(  -437.50), SIMDE_FLOAT16_VALUE(  -183.50), SIMDE_FLOAT16_VALUE(   795.50), SIMDE_FLOAT16_VALUE(   171.12) },
      {      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX } },
    { { SIMDE_FLOAT16_VALUE(   884.00), SIMDE_FLOAT16_VALUE(  -171.25), SIMDE_FLOAT16_VALUE(   797.00), SIMDE_FLOAT16_VALUE(  -648.00) },
      { SIMDE_FLOAT16_VALUE(   884.00), SIMDE_FLOAT16_VALUE(   549.00), SIMDE_FLOAT16_VALUE(   797.00), SIMDE_FLOAT16_VALUE(  -479.50) },
      {      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0) } },
    { { SIMDE_FLOAT16_VALUE(   426.25), SIMDE_FLOAT16_VALUE(  -681.00), SIMDE_FLOAT16_VALUE(   439.00), SIMDE_FLOAT16_VALUE(  -738.00) },
      { SIMDE_FLOAT16_VALUE(   426.25), SIMDE_FLOAT16_VALUE(  -681.00), SIMDE_FLOAT16_VALUE(   951.50), SIMDE_FLOAT16_VALUE(  -396.50) },
      {      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0) } },
    { { SIMDE_FLOAT16_VALUE(   251.25), SIMDE_FLOAT16_VALUE(   324.75), SIMDE_FLOAT16_VALUE(  -690.00), SIMDE_FLOAT16_VALUE(  -190.88) },
      { SIMDE_FLOAT16_VALUE(  -974.50), SIMDE_FLOAT16_VALUE(   -79.31), SIMDE_FLOAT16_VALUE(   244.25), SIMDE_FLOAT16_VALUE(   612.50) },
      {      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x4_t a = simde_vld1_f16(test_vec[i].a);
    simde_float16x4_t b = simde_vld1_f16(test_vec[i].b);
    simde_uint16x4_t r = simde_vcge_f16(a, b);

    simde_test_arm_neon_assert_equal_u16x4(r, simde_vld1_u16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16x4_private a_ = simde_float16x4_to_private(simde_test_arm_neon_random_f16x4(-1000.0, 1000.0));
    simde_float16x4_private b_ = simde_float16x4_to_private(simde_test_arm_neon_random_f16x4(-1000.0, 1000.0));

    /* Make some equal which is unlikely to happen by accident. */
    for (size_t j = 0 ; j < (sizeof(a_.values) / sizeof(a_.values[0])) ; j++) {
      if (rand() < (RAND_MAX / 3)) a_.values[j] = b_.values[j];
    }

    simde_float16x4_t a = simde_float16x4_from_private(a_);
    simde_float16x4_t b = simde_float16x4_from_private(b_);

    simde_uint16x4_t r = simde_vcge_f16(a, b);

    simde_test_arm_neon_write_f16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcge_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a[2];
    simde_float32 b[2];
    uint32_t r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -762.79), SIMDE_FLOAT32_C(   278.49) },
      { SIMDE_FLOAT32_C(   573.76), SIMDE_FLOAT32_C(   673.25) },
      { UINT32_C(         0), UINT32_C(         0) } },
    { { SIMDE_FLOAT32_C(   768.48), SIMDE_FLOAT32_C(   971.82) },
      { SIMDE_FLOAT32_C(   811.98), SIMDE_FLOAT32_C(  -395.22) },
      { UINT32_C(         0),           UINT32_MAX } },
    { { SIMDE_FLOAT32_C(  -590.44), SIMDE_FLOAT32_C(   152.23) },
      { SIMDE_FLOAT32_C(  -590.44), SIMDE_FLOAT32_C(   152.23) },
      {           UINT32_MAX,           UINT32_MAX } },
    { { SIMDE_FLOAT32_C(   824.17), SIMDE_FLOAT32_C(   743.68) },
      { SIMDE_FLOAT32_C(  -356.79), SIMDE_FLOAT32_C(   242.15) },
      {           UINT32_MAX,           UINT32_MAX } },
    { { SIMDE_FLOAT32_C(   141.44), SIMDE_FLOAT32_C(  -148.44) },
      { SIMDE_FLOAT32_C(   -47.53), SIMDE_FLOAT32_C(  -906.36) },
      {           UINT32_MAX,           UINT32_MAX } },
    { { SIMDE_FLOAT32_C(  -221.36), SIMDE_FLOAT32_C(  -647.60) },
      { SIMDE_FLOAT32_C(   150.33), SIMDE_FLOAT32_C(  -647.60) },
      { UINT32_C(         0),           UINT32_MAX } },
    { { SIMDE_FLOAT32_C(  -973.68), SIMDE_FLOAT32_C(   554.40) },
      { SIMDE_FLOAT32_C(  -973.68), SIMDE_FLOAT32_C(  -148.92) },
      {           UINT32_MAX,           UINT32_MAX } },
    { { SIMDE_FLOAT32_C(   829.76), SIMDE_FLOAT32_C(  -725.20) },
      { SIMDE_FLOAT32_C(   365.78), SIMDE_FLOAT32_C(  -760.67) },
      {           UINT32_MAX,           UINT32_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t a = simde_vld1_f32(test_vec[i].a);
    simde_float32x2_t b = simde_vld1_f32(test_vec[i].b);
    simde_uint32x2_t r = simde_vcge_f32(a, b);

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

    simde_uint32x2_t r = simde_vcge_f32(a, b);

    simde_test_arm_neon_write_f32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcge_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 a[1];
    simde_float64 b[1];
    uint64_t r[1];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(   130.39) },
      { SIMDE_FLOAT64_C(   996.42) },
      { UINT64_C(                   0) } },
    { { SIMDE_FLOAT64_C(    35.94) },
      { SIMDE_FLOAT64_C(    35.94) },
      {                    UINT64_MAX } },
    { { SIMDE_FLOAT64_C(  -578.02) },
      { SIMDE_FLOAT64_C(   669.25) },
      { UINT64_C(                   0) } },
    { { SIMDE_FLOAT64_C(   105.77) },
      { SIMDE_FLOAT64_C(   591.27) },
      { UINT64_C(                   0) } },
    { { SIMDE_FLOAT64_C(  -682.67) },
      { SIMDE_FLOAT64_C(  -705.46) },
      {                    UINT64_MAX } },
    { { SIMDE_FLOAT64_C(   880.87) },
      { SIMDE_FLOAT64_C(   -97.20) },
      {                    UINT64_MAX } },
    { { SIMDE_FLOAT64_C(   338.18) },
      { SIMDE_FLOAT64_C(   925.14) },
      { UINT64_C(                   0) } },
    { { SIMDE_FLOAT64_C(   626.85) },
      { SIMDE_FLOAT64_C(  -403.18) },
      {                    UINT64_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x1_t a = simde_vld1_f64(test_vec[i].a);
    simde_float64x1_t b = simde_vld1_f64(test_vec[i].b);
    simde_uint64x1_t r = simde_vcge_f64(a, b);

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

    simde_uint64x1_t r = simde_vcge_f64(a, b);

    simde_test_arm_neon_write_f64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x1(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcge_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[8];
    int8_t b[8];
    uint8_t r[8];
  } test_vec[] = {
    { {      INT8_MIN, -INT8_C(  59), -INT8_C(  67),  INT8_C(  75),  INT8_C(  83), -INT8_C(  69),  INT8_C(  29), -INT8_C(  34) },
      { -INT8_C(  98),  INT8_C(  50),  INT8_C( 122),  INT8_C(  18), -INT8_C(  65), -INT8_C(  69),  INT8_C(  29), -INT8_C( 121) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX } },
    { { -INT8_C(  51), -INT8_C(  84),  INT8_C( 110),  INT8_C( 104), -INT8_C(  93), -INT8_C( 118),  INT8_C(  26),  INT8_C(  35) },
      { -INT8_C(  24), -INT8_C( 115),  INT8_C( 110),  INT8_C(  59),  INT8_C(  65), -INT8_C( 118),  INT8_C(  26), -INT8_C(  33) },
      { UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX } },
    { { -INT8_C(  41),  INT8_C(  95),  INT8_C(  90),  INT8_C(  86),  INT8_C( 120), -INT8_C( 126), -INT8_C(  11),  INT8_C(  69) },
      {  INT8_C(  46), -INT8_C(  60), -INT8_C(  82), -INT8_C(  46), -INT8_C(  25),  INT8_C( 126), -INT8_C(  11), -INT8_C(  48) },
      { UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX } },
    { { -INT8_C(  70),  INT8_C(  29),  INT8_C(  37),  INT8_C(   0),  INT8_C(  44),  INT8_C(  40), -INT8_C(   1),  INT8_C(   3) },
      { -INT8_C( 120),  INT8_C(  89),  INT8_C(  90),  INT8_C(   0), -INT8_C(  36), -INT8_C(  92),  INT8_C(  69),  INT8_C(  10) },
      {    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0) } },
    { {  INT8_C(  54),  INT8_C(  43), -INT8_C(  56),  INT8_C(  36),  INT8_C(  81), -INT8_C(  12), -INT8_C(  50),  INT8_C(  11) },
      {  INT8_C(  17), -INT8_C(  13),  INT8_C(  20),  INT8_C(  62),  INT8_C(  28),  INT8_C(  19),  INT8_C(  65), -INT8_C(  92) },
      {    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX } },
    { { -INT8_C(  35),  INT8_C(  48), -INT8_C(   8),  INT8_C(  78),  INT8_C(   2),  INT8_C(  24), -INT8_C(  53), -INT8_C( 103) },
      {  INT8_C(  68), -INT8_C( 109),  INT8_C(  92), -INT8_C( 107), -INT8_C( 121),  INT8_C(  42), -INT8_C(  96), -INT8_C( 103) },
      { UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX } },
    { { -INT8_C(  76), -INT8_C( 127), -INT8_C( 106),  INT8_C(   3),  INT8_C( 107), -INT8_C(  47),  INT8_C(  59), -INT8_C(  15) },
      {  INT8_C(   1), -INT8_C( 107), -INT8_C( 106),  INT8_C(   3), -INT8_C(  83),  INT8_C(  97),  INT8_C(  59), -INT8_C(  15) },
      { UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX } },
    { { -INT8_C(  37), -INT8_C(  20),  INT8_C(  24), -INT8_C(  30),  INT8_C(   5), -INT8_C(  10), -INT8_C(  40),  INT8_C(  41) },
      {  INT8_C( 119),  INT8_C(  86), -INT8_C(  83), -INT8_C(  30),  INT8_C(  39),  INT8_C(  73),  INT8_C(  42),  INT8_C(  41) },
      { UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8_t a = simde_vld1_s8(test_vec[i].a);
    simde_int8x8_t b = simde_vld1_s8(test_vec[i].b);
    simde_uint8x8_t r = simde_vcge_s8(a, b);

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

    simde_uint8x8_t r = simde_vcge_s8(a, b);

    simde_test_arm_neon_write_i8x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcge_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[4];
    int16_t b[4];
    uint16_t r[4];
  } test_vec[] = {
    { {  INT16_C( 19213), -INT16_C( 23976), -INT16_C( 13884),  INT16_C(  9880) },
      {  INT16_C( 19213), -INT16_C( 22464), -INT16_C( 32203),  INT16_C(  9880) },
      {      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX } },
    { {  INT16_C( 18524),  INT16_C( 14362),  INT16_C(  2421), -INT16_C( 13240) },
      { -INT16_C( 29395), -INT16_C( 31403), -INT16_C( 21161),  INT16_C(  6951) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0) } },
    { { -INT16_C( 29148),  INT16_C( 27173), -INT16_C( 15344),  INT16_C( 20607) },
      { -INT16_C(  8434),  INT16_C( 27173),  INT16_C( 16167), -INT16_C( 25182) },
      { UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX } },
    { { -INT16_C( 16776), -INT16_C( 12037), -INT16_C( 27961), -INT16_C(  7445) },
      {  INT16_C( 14843),  INT16_C(  8038), -INT16_C( 27961), -INT16_C( 10376) },
      { UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX } },
    { {  INT16_C( 19927), -INT16_C(   305),  INT16_C( 29324), -INT16_C( 10853) },
      {  INT16_C(  1117), -INT16_C( 10932),  INT16_C( 18370),  INT16_C( 11941) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0) } },
    { { -INT16_C( 28427), -INT16_C( 28283), -INT16_C(   760),  INT16_C( 24424) },
      { -INT16_C( 28427), -INT16_C( 13116), -INT16_C( 27427),  INT16_C( 27083) },
      {      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0) } },
    { { -INT16_C( 29845),  INT16_C( 11576),  INT16_C( 10209), -INT16_C(  5430) },
      {  INT16_C( 27503),  INT16_C( 14754),  INT16_C( 10209), -INT16_C(  5430) },
      { UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX } },
    { {  INT16_C(  3778), -INT16_C( 31989), -INT16_C( 20062), -INT16_C( 22519) },
      {  INT16_C( 18456), -INT16_C( 31989),  INT16_C( 17363), -INT16_C( 23120) },
      { UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t a = simde_vld1_s16(test_vec[i].a);
    simde_int16x4_t b = simde_vld1_s16(test_vec[i].b);
    simde_uint16x4_t r = simde_vcge_s16(a, b);

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

    simde_uint16x4_t r = simde_vcge_s16(a, b);

    simde_test_arm_neon_write_i16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcge_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[2];
    int32_t b[2];
    uint32_t r[2];
  } test_vec[] = {
    { { -INT32_C(   829143814),  INT32_C(  1777284011) },
      { -INT32_C(   829143814),  INT32_C(  1777284011) },
      {           UINT32_MAX,           UINT32_MAX } },
    { {  INT32_C(  1630841126), -INT32_C(  1815256670) },
      {  INT32_C(  1763409610), -INT32_C(  1815256670) },
      { UINT32_C(         0),           UINT32_MAX } },
    { {  INT32_C(   951596606),  INT32_C(   621169786) },
      { -INT32_C(   561056129),  INT32_C(   797488379) },
      {           UINT32_MAX, UINT32_C(         0) } },
    { { -INT32_C(  1092706572), -INT32_C(  1087899363) },
      { -INT32_C(  1705839269),  INT32_C(  1473286559) },
      {           UINT32_MAX, UINT32_C(         0) } },
    { { -INT32_C(   957249103), -INT32_C(  1056834106) },
      { -INT32_C(   957249103),  INT32_C(   694543690) },
      {           UINT32_MAX, UINT32_C(         0) } },
    { { -INT32_C(   289937627),  INT32_C(  1595380928) },
      { -INT32_C(   289937627), -INT32_C(  1598137807) },
      {           UINT32_MAX,           UINT32_MAX } },
    { {  INT32_C(  1313243037),  INT32_C(  1393899272) },
      { -INT32_C(  1082361316),  INT32_C(  1032494844) },
      {           UINT32_MAX,           UINT32_MAX } },
    { {  INT32_C(   971875259),  INT32_C(  1290101019) },
      {  INT32_C(   971875259),  INT32_C(  1857587752) },
      {           UINT32_MAX, UINT32_C(         0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t a = simde_vld1_s32(test_vec[i].a);
    simde_int32x2_t b = simde_vld1_s32(test_vec[i].b);
    simde_uint32x2_t r = simde_vcge_s32(a, b);

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

    simde_uint32x2_t r = simde_vcge_s32(a, b);

    simde_test_arm_neon_write_i32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcge_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a[1];
    int64_t b[1];
    uint64_t r[1];
  } test_vec[] = {
    { {  INT64_C( 8640190357508052970) },
      {  INT64_C( 5528585362751356760) },
      {                    UINT64_MAX } },
    { { -INT64_C( 3033591299633767839) },
      { -INT64_C( 7667411631510427440) },
      {                    UINT64_MAX } },
    { {  INT64_C( 4177766084966535903) },
      {  INT64_C( 4177766084966535903) },
      {                    UINT64_MAX } },
    { { -INT64_C( 6092879107822443257) },
      { -INT64_C( 6092879107822443257) },
      {                    UINT64_MAX } },
    { { -INT64_C( 3695200531164032468) },
      {  INT64_C( 1346358656504223643) },
      { UINT64_C(                   0) } },
    { { -INT64_C( 5449008510585538877) },
      { -INT64_C( 5449008510585538877) },
      {                    UINT64_MAX } },
    { {  INT64_C( 7410667899739727175) },
      { -INT64_C( 2022569260477257840) },
      {                    UINT64_MAX } },
    { { -INT64_C(  921434190897626108) },
      { -INT64_C( 1061286504771364963) },
      {                    UINT64_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x1_t a = simde_vld1_s64(test_vec[i].a);
    simde_int64x1_t b = simde_vld1_s64(test_vec[i].b);
    simde_uint64x1_t r = simde_vcge_s64(a, b);

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

    simde_uint64x1_t r = simde_vcge_s64(a, b);

    simde_test_arm_neon_write_i64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x1(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcge_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t a[8];
    uint8_t b[8];
    uint8_t r[8];
  } test_vec[] = {
    { { UINT8_C( 62), UINT8_C(185), UINT8_C(176), UINT8_C(170), UINT8_C(140), UINT8_C( 91), UINT8_C( 69), UINT8_C(245) },
      { UINT8_C(115), UINT8_C(185), UINT8_C(176), UINT8_C(170), UINT8_C(140), UINT8_C(156), UINT8_C( 73), UINT8_C(113) },
      { UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX } },
    { { UINT8_C(127), UINT8_C( 90), UINT8_C( 82), UINT8_C( 94), UINT8_C(181), UINT8_C(116), UINT8_C(134), UINT8_C( 40) },
      { UINT8_C(162), UINT8_C( 90), UINT8_C( 82), UINT8_C( 35), UINT8_C(181), UINT8_C(151), UINT8_C( 24), UINT8_C( 40) },
      { UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX } },
    { { UINT8_C( 49), UINT8_C( 25), UINT8_C( 97), UINT8_C( 73), UINT8_C(132), UINT8_C( 28), UINT8_C( 96), UINT8_C( 23) },
      { UINT8_C(112), UINT8_C(  1), UINT8_C( 97), UINT8_C( 73), UINT8_C(117), UINT8_C(231), UINT8_C( 96), UINT8_C( 23) },
      { UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX } },
    { { UINT8_C( 27), UINT8_C(240), UINT8_C(119), UINT8_C(128), UINT8_C( 11), UINT8_C(198), UINT8_C(249), UINT8_C( 61) },
      { UINT8_C(223), UINT8_C(171), UINT8_C(141), UINT8_C( 99), UINT8_C(200), UINT8_C(221), UINT8_C(103), UINT8_C( 56) },
      { UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX } },
    { { UINT8_C(247), UINT8_C(165), UINT8_C(232), UINT8_C(  2), UINT8_C(181), UINT8_C(141), UINT8_C(120), UINT8_C( 20) },
      { UINT8_C(247), UINT8_C(239), UINT8_C(148), UINT8_C(  2), UINT8_C(181), UINT8_C(141), UINT8_C( 63), UINT8_C(149) },
      {    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0) } },
    { { UINT8_C( 40), UINT8_C(177), UINT8_C(220), UINT8_C(216), UINT8_C(155), UINT8_C(132), UINT8_C(201), UINT8_C( 46) },
      { UINT8_C(236), UINT8_C(177), UINT8_C( 12), UINT8_C(229), UINT8_C(184), UINT8_C(132), UINT8_C(249), UINT8_C(175) },
      { UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0) } },
    { { UINT8_C(189), UINT8_C(182), UINT8_C( 84), UINT8_C(226), UINT8_C( 22), UINT8_C(141), UINT8_C( 17),    UINT8_MAX },
      { UINT8_C( 71), UINT8_C(204), UINT8_C( 22), UINT8_C(226), UINT8_C( 19), UINT8_C(223), UINT8_C( 17),    UINT8_MAX },
      {    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX } },
    { { UINT8_C(178), UINT8_C( 45), UINT8_C( 61), UINT8_C(200), UINT8_C(154), UINT8_C(175), UINT8_C(216), UINT8_C( 88) },
      { UINT8_C(178), UINT8_C( 45), UINT8_C(191), UINT8_C(200), UINT8_C(186), UINT8_C(175), UINT8_C(  6), UINT8_C(  2) },
      {    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x8_t a = simde_vld1_u8(test_vec[i].a);
    simde_uint8x8_t b = simde_vld1_u8(test_vec[i].b);
    simde_uint8x8_t r = simde_vcge_u8(a, b);

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

    simde_uint8x8_t r = simde_vcge_u8(a, b);

    simde_test_arm_neon_write_u8x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcge_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[4];
    uint16_t b[4];
    uint16_t r[4];
  } test_vec[] = {
    { { UINT16_C( 2642), UINT16_C(12638), UINT16_C( 2321), UINT16_C(53075) },
      { UINT16_C(13907), UINT16_C(49252), UINT16_C(65171), UINT16_C(14608) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX } },
    { { UINT16_C(36937), UINT16_C(10202), UINT16_C( 4220), UINT16_C(12453) },
      { UINT16_C(56533), UINT16_C(10202), UINT16_C(14822), UINT16_C(63321) },
      { UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    0) } },
    { { UINT16_C(11234), UINT16_C(30038), UINT16_C(26153), UINT16_C(21423) },
      { UINT16_C(12745), UINT16_C( 4854), UINT16_C(26049), UINT16_C(15992) },
      { UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX } },
    { { UINT16_C(18682), UINT16_C(57458), UINT16_C(45002), UINT16_C(50136) },
      { UINT16_C(40823), UINT16_C(22873), UINT16_C(45002), UINT16_C(62671) },
      { UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0) } },
    { { UINT16_C(15791), UINT16_C(28913), UINT16_C(27298), UINT16_C( 6062) },
      { UINT16_C( 7303), UINT16_C(33122), UINT16_C(54373), UINT16_C(58978) },
      {      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { { UINT16_C(  985), UINT16_C(41839), UINT16_C(16050), UINT16_C(49116) },
      { UINT16_C(57276), UINT16_C(27558), UINT16_C(38940), UINT16_C(49116) },
      { UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX } },
    { { UINT16_C(14503), UINT16_C(32961), UINT16_C(12703), UINT16_C(20771) },
      { UINT16_C(40103), UINT16_C(32961), UINT16_C(12703), UINT16_C(20771) },
      { UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX } },
    { { UINT16_C(49050), UINT16_C(42467), UINT16_C(29527), UINT16_C(22901) },
      { UINT16_C(19710), UINT16_C(42467), UINT16_C(61060), UINT16_C(37297) },
      {      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4_t a = simde_vld1_u16(test_vec[i].a);
    simde_uint16x4_t b = simde_vld1_u16(test_vec[i].b);
    simde_uint16x4_t r = simde_vcge_u16(a, b);

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

    simde_uint16x4_t r = simde_vcge_u16(a, b);

    simde_test_arm_neon_write_u16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcge_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[2];
    uint32_t b[2];
    uint32_t r[2];
  } test_vec[] = {
    { { UINT32_C( 569449259), UINT32_C( 284840429) },
      { UINT32_C( 862297363), UINT32_C( 984793204) },
      { UINT32_C(         0), UINT32_C(         0) } },
    { { UINT32_C(3508313849), UINT32_C(4018812414) },
      { UINT32_C(1862940867), UINT32_C(4018812414) },
      {           UINT32_MAX,           UINT32_MAX } },
    { { UINT32_C(1401376832), UINT32_C(1653009646) },
      { UINT32_C( 312228012), UINT32_C( 733058575) },
      {           UINT32_MAX,           UINT32_MAX } },
    { { UINT32_C(1156147693), UINT32_C(4192123131) },
      { UINT32_C(1156147693), UINT32_C(1754540512) },
      {           UINT32_MAX,           UINT32_MAX } },
    { { UINT32_C(2138489879), UINT32_C(1259569468) },
      { UINT32_C(2138489879), UINT32_C( 490807918) },
      {           UINT32_MAX,           UINT32_MAX } },
    { { UINT32_C(3307313992), UINT32_C(3104251864) },
      { UINT32_C(3307313992), UINT32_C(  63534366) },
      {           UINT32_MAX,           UINT32_MAX } },
    { { UINT32_C(2622524036), UINT32_C(3488133017) },
      { UINT32_C(2044353768), UINT32_C(3488133017) },
      {           UINT32_MAX,           UINT32_MAX } },
    { { UINT32_C( 913996270), UINT32_C( 437369546) },
      { UINT32_C(2268513552), UINT32_C( 437369546) },
      { UINT32_C(         0),           UINT32_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2_t a = simde_vld1_u32(test_vec[i].a);
    simde_uint32x2_t b = simde_vld1_u32(test_vec[i].b);
    simde_uint32x2_t r = simde_vcge_u32(a, b);

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

    simde_uint32x2_t r = simde_vcge_u32(a, b);

    simde_test_arm_neon_write_u32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcge_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a[1];
    uint64_t b[1];
    uint64_t r[1];
  } test_vec[] = {
    { { UINT64_C(15188592653948299680) },
      { UINT64_C(15188592653948299680) },
      {                    UINT64_MAX } },
    { { UINT64_C( 6204103708661670688) },
      { UINT64_C( 6536367965351154177) },
      { UINT64_C(                   0) } },
    { { UINT64_C( 1365467413574693313) },
      { UINT64_C(13030847014366772973) },
      { UINT64_C(                   0) } },
    { { UINT64_C( 8955896582142371742) },
      { UINT64_C( 6753901549624578627) },
      {                    UINT64_MAX } },
    { { UINT64_C( 2548699820776245226) },
      { UINT64_C( 2548699820776245226) },
      {                    UINT64_MAX } },
    { { UINT64_C( 8700755168802594176) },
      { UINT64_C( 8700755168802594176) },
      {                    UINT64_MAX } },
    { { UINT64_C( 3667811991632179057) },
      { UINT64_C( 3667811991632179057) },
      {                    UINT64_MAX } },
    { { UINT64_C(16236877168053407557) },
      { UINT64_C(14927669731982511924) },
      {                    UINT64_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x1_t a = simde_vld1_u64(test_vec[i].a);
    simde_uint64x1_t b = simde_vld1_u64(test_vec[i].b);
    simde_uint64x1_t r = simde_vcge_u64(a, b);

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

    simde_uint64x1_t r = simde_vcge_u64(a, b);

    simde_test_arm_neon_write_u64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x1(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcgeq_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16 a[8];
    simde_float16 b[8];
    uint16_t r[8];
  } test_vec[] = {
    { { SIMDE_FLOAT16_VALUE(   489.75), SIMDE_FLOAT16_VALUE(  -920.50), SIMDE_FLOAT16_VALUE(   574.50), SIMDE_FLOAT16_VALUE(  -427.25),
        SIMDE_FLOAT16_VALUE(   798.50), SIMDE_FLOAT16_VALUE(   208.00), SIMDE_FLOAT16_VALUE(  -401.00), SIMDE_FLOAT16_VALUE(   154.25) },
      { SIMDE_FLOAT16_VALUE(   489.75), SIMDE_FLOAT16_VALUE(  -920.50), SIMDE_FLOAT16_VALUE(  -251.88), SIMDE_FLOAT16_VALUE(  -511.75),
        SIMDE_FLOAT16_VALUE(   825.00), SIMDE_FLOAT16_VALUE(  -212.00), SIMDE_FLOAT16_VALUE(   433.00), SIMDE_FLOAT16_VALUE(   154.25) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX } },
    { { SIMDE_FLOAT16_VALUE(  -312.25), SIMDE_FLOAT16_VALUE(  -493.75), SIMDE_FLOAT16_VALUE(   637.50), SIMDE_FLOAT16_VALUE(   377.75),
        SIMDE_FLOAT16_VALUE(  -880.50), SIMDE_FLOAT16_VALUE(  -229.50), SIMDE_FLOAT16_VALUE(   -68.12), SIMDE_FLOAT16_VALUE(  -443.75) },
      { SIMDE_FLOAT16_VALUE(  -837.00), SIMDE_FLOAT16_VALUE(  -493.75), SIMDE_FLOAT16_VALUE(   128.88), SIMDE_FLOAT16_VALUE(   961.50),
        SIMDE_FLOAT16_VALUE(   714.00), SIMDE_FLOAT16_VALUE(   728.00), SIMDE_FLOAT16_VALUE(   310.50), SIMDE_FLOAT16_VALUE(   203.88) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { { SIMDE_FLOAT16_VALUE(   -36.62), SIMDE_FLOAT16_VALUE(   773.50), SIMDE_FLOAT16_VALUE(  -561.50), SIMDE_FLOAT16_VALUE(    82.81),
        SIMDE_FLOAT16_VALUE(   553.50), SIMDE_FLOAT16_VALUE(   871.00), SIMDE_FLOAT16_VALUE(   145.50), SIMDE_FLOAT16_VALUE(   716.50) },
      { SIMDE_FLOAT16_VALUE(   -36.62), SIMDE_FLOAT16_VALUE(  -216.75), SIMDE_FLOAT16_VALUE(   191.00), SIMDE_FLOAT16_VALUE(    82.81),
        SIMDE_FLOAT16_VALUE(   553.50), SIMDE_FLOAT16_VALUE(  -877.00), SIMDE_FLOAT16_VALUE(   639.00), SIMDE_FLOAT16_VALUE(   716.50) },
      {      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX } },
    { { SIMDE_FLOAT16_VALUE(  -504.00), SIMDE_FLOAT16_VALUE(   844.00), SIMDE_FLOAT16_VALUE(   936.00), SIMDE_FLOAT16_VALUE(   621.50),
        SIMDE_FLOAT16_VALUE(  -635.50), SIMDE_FLOAT16_VALUE(  -277.50), SIMDE_FLOAT16_VALUE(   405.25), SIMDE_FLOAT16_VALUE(   543.00) },
      { SIMDE_FLOAT16_VALUE(  -504.00), SIMDE_FLOAT16_VALUE(   844.00), SIMDE_FLOAT16_VALUE(  -463.25), SIMDE_FLOAT16_VALUE(   621.50),
        SIMDE_FLOAT16_VALUE(   715.50), SIMDE_FLOAT16_VALUE(   682.00), SIMDE_FLOAT16_VALUE(   434.75), SIMDE_FLOAT16_VALUE(  -321.25) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX } },
    { { SIMDE_FLOAT16_VALUE(  -492.50), SIMDE_FLOAT16_VALUE(   414.25), SIMDE_FLOAT16_VALUE(   721.00), SIMDE_FLOAT16_VALUE(  -128.12),
        SIMDE_FLOAT16_VALUE(   626.00), SIMDE_FLOAT16_VALUE(   268.25), SIMDE_FLOAT16_VALUE(   -32.38), SIMDE_FLOAT16_VALUE(   450.75) },
      { SIMDE_FLOAT16_VALUE(  -492.50), SIMDE_FLOAT16_VALUE(   -96.62), SIMDE_FLOAT16_VALUE(   345.25), SIMDE_FLOAT16_VALUE(  -128.12),
        SIMDE_FLOAT16_VALUE(   626.00), SIMDE_FLOAT16_VALUE(  -249.50), SIMDE_FLOAT16_VALUE(  -585.00), SIMDE_FLOAT16_VALUE(  -878.00) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX } },
    { { SIMDE_FLOAT16_VALUE(   804.00), SIMDE_FLOAT16_VALUE(  -249.88), SIMDE_FLOAT16_VALUE(   -16.62), SIMDE_FLOAT16_VALUE(  -328.50),
        SIMDE_FLOAT16_VALUE(   -79.88), SIMDE_FLOAT16_VALUE(  -145.62), SIMDE_FLOAT16_VALUE(  -877.50), SIMDE_FLOAT16_VALUE(  -681.00) },
      { SIMDE_FLOAT16_VALUE(  -731.50), SIMDE_FLOAT16_VALUE(   652.00), SIMDE_FLOAT16_VALUE(   -16.62), SIMDE_FLOAT16_VALUE(  -328.50),
        SIMDE_FLOAT16_VALUE(   -79.88), SIMDE_FLOAT16_VALUE(   951.00), SIMDE_FLOAT16_VALUE(  -877.50), SIMDE_FLOAT16_VALUE(   427.75) },
      {      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0) } },
    { { SIMDE_FLOAT16_VALUE(   666.50), SIMDE_FLOAT16_VALUE(  -481.25), SIMDE_FLOAT16_VALUE(   881.00), SIMDE_FLOAT16_VALUE(    11.91),
        SIMDE_FLOAT16_VALUE(   373.00), SIMDE_FLOAT16_VALUE(   811.50), SIMDE_FLOAT16_VALUE(   400.00), SIMDE_FLOAT16_VALUE(   328.25) },
      { SIMDE_FLOAT16_VALUE(  -138.75), SIMDE_FLOAT16_VALUE(  -481.25), SIMDE_FLOAT16_VALUE(   881.00), SIMDE_FLOAT16_VALUE(    11.91),
        SIMDE_FLOAT16_VALUE(   373.00), SIMDE_FLOAT16_VALUE(   811.50), SIMDE_FLOAT16_VALUE(   331.00), SIMDE_FLOAT16_VALUE(   641.50) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0) } },
    { { SIMDE_FLOAT16_VALUE(   903.00), SIMDE_FLOAT16_VALUE(  -889.00), SIMDE_FLOAT16_VALUE(  -207.12), SIMDE_FLOAT16_VALUE(  -928.00),
        SIMDE_FLOAT16_VALUE(  -174.38), SIMDE_FLOAT16_VALUE(  -798.00), SIMDE_FLOAT16_VALUE(   -66.38), SIMDE_FLOAT16_VALUE(    28.64) },
      { SIMDE_FLOAT16_VALUE(  -452.25), SIMDE_FLOAT16_VALUE(  -944.00), SIMDE_FLOAT16_VALUE(  -207.12), SIMDE_FLOAT16_VALUE(  -928.00),
        SIMDE_FLOAT16_VALUE(  -832.50), SIMDE_FLOAT16_VALUE(  -807.00), SIMDE_FLOAT16_VALUE(   400.00), SIMDE_FLOAT16_VALUE(    28.64) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x8_t a = simde_vld1q_f16(test_vec[i].a);
    simde_float16x8_t b = simde_vld1q_f16(test_vec[i].b);
    simde_uint16x8_t r = simde_vcgeq_f16(a, b);

    simde_test_arm_neon_assert_equal_u16x8(r, simde_vld1q_u16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16x8_private a_ = simde_float16x8_to_private(simde_test_arm_neon_random_f16x8(-1000.0, 1000.0));
    simde_float16x8_private b_ = simde_float16x8_to_private(simde_test_arm_neon_random_f16x8(-1000.0, 1000.0));

    /* Make some equal which is unlikely to happen by accident. */
    for (size_t j = 0 ; j < (sizeof(a_.values) / sizeof(a_.values[0])) ; j++) {
      if (rand() < (RAND_MAX / 3)) a_.values[j] = b_.values[j];
    }

    simde_float16x8_t a = simde_float16x8_from_private(a_);
    simde_float16x8_t b = simde_float16x8_from_private(b_);

    simde_uint16x8_t r = simde_vcgeq_f16(a, b);

    simde_test_arm_neon_write_f16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcgeq_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a[4];
    simde_float32 b[4];
    uint32_t r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -645.35), SIMDE_FLOAT32_C(   906.68), SIMDE_FLOAT32_C(   619.69), SIMDE_FLOAT32_C(   579.13) },
      { SIMDE_FLOAT32_C(  -888.20), SIMDE_FLOAT32_C(   906.68), SIMDE_FLOAT32_C(  -502.35), SIMDE_FLOAT32_C(   579.13) },
      {           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX } },
    { { SIMDE_FLOAT32_C(   247.32), SIMDE_FLOAT32_C(   296.45), SIMDE_FLOAT32_C(   752.07), SIMDE_FLOAT32_C(   130.33) },
      { SIMDE_FLOAT32_C(    35.16), SIMDE_FLOAT32_C(     1.82), SIMDE_FLOAT32_C(   752.07), SIMDE_FLOAT32_C(  -668.20) },
      {           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX } },
    { { SIMDE_FLOAT32_C(   180.85), SIMDE_FLOAT32_C(   267.89), SIMDE_FLOAT32_C(   986.47), SIMDE_FLOAT32_C(   541.82) },
      { SIMDE_FLOAT32_C(   880.72), SIMDE_FLOAT32_C(  -827.97), SIMDE_FLOAT32_C(   567.27), SIMDE_FLOAT32_C(  -764.64) },
      { UINT32_C(         0),           UINT32_MAX,           UINT32_MAX,           UINT32_MAX } },
    { { SIMDE_FLOAT32_C(    93.64), SIMDE_FLOAT32_C(   529.98), SIMDE_FLOAT32_C(   399.13), SIMDE_FLOAT32_C(   278.11) },
      { SIMDE_FLOAT32_C(  -969.21), SIMDE_FLOAT32_C(  -931.35), SIMDE_FLOAT32_C(   399.13), SIMDE_FLOAT32_C(   278.11) },
      {           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX } },
    { { SIMDE_FLOAT32_C(   175.35), SIMDE_FLOAT32_C(  -839.50), SIMDE_FLOAT32_C(  -267.94), SIMDE_FLOAT32_C(  -643.81) },
      { SIMDE_FLOAT32_C(   175.35), SIMDE_FLOAT32_C(    52.39), SIMDE_FLOAT32_C(   966.24), SIMDE_FLOAT32_C(  -643.81) },
      {           UINT32_MAX, UINT32_C(         0), UINT32_C(         0),           UINT32_MAX } },
    { { SIMDE_FLOAT32_C(  -875.26), SIMDE_FLOAT32_C(   465.28), SIMDE_FLOAT32_C(  -563.64), SIMDE_FLOAT32_C(  -189.26) },
      { SIMDE_FLOAT32_C(  -347.77), SIMDE_FLOAT32_C(   468.68), SIMDE_FLOAT32_C(   608.55), SIMDE_FLOAT32_C(   745.87) },
      { UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0) } },
    { { SIMDE_FLOAT32_C(  -945.88), SIMDE_FLOAT32_C(  -284.00), SIMDE_FLOAT32_C(  -692.44), SIMDE_FLOAT32_C(    92.60) },
      { SIMDE_FLOAT32_C(  -840.71), SIMDE_FLOAT32_C(  -284.00), SIMDE_FLOAT32_C(   819.48), SIMDE_FLOAT32_C(    92.60) },
      { UINT32_C(         0),           UINT32_MAX, UINT32_C(         0),           UINT32_MAX } },
    { { SIMDE_FLOAT32_C(   603.93), SIMDE_FLOAT32_C(  -693.95), SIMDE_FLOAT32_C(  -874.81), SIMDE_FLOAT32_C(   462.62) },
      { SIMDE_FLOAT32_C(   337.88), SIMDE_FLOAT32_C(  -693.95), SIMDE_FLOAT32_C(  -874.81), SIMDE_FLOAT32_C(   462.62) },
      {           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_float32x4_t b = simde_vld1q_f32(test_vec[i].b);
    simde_uint32x4_t r = simde_vcgeq_f32(a, b);

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

    simde_uint32x4_t r = simde_vcgeq_f32(a, b);

    simde_test_arm_neon_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcgeq_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 a[2];
    simde_float64 b[2];
    uint64_t r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(   109.93), SIMDE_FLOAT64_C(  -385.27) },
      { SIMDE_FLOAT64_C(   133.89), SIMDE_FLOAT64_C(   181.08) },
      { UINT64_C(                   0), UINT64_C(                   0) } },
    { { SIMDE_FLOAT64_C(   530.41), SIMDE_FLOAT64_C(  -444.63) },
      { SIMDE_FLOAT64_C(   530.41), SIMDE_FLOAT64_C(  -444.63) },
      {                    UINT64_MAX,                    UINT64_MAX } },
    { { SIMDE_FLOAT64_C(  -131.75), SIMDE_FLOAT64_C(   898.49) },
      { SIMDE_FLOAT64_C(   524.05), SIMDE_FLOAT64_C(   898.49) },
      { UINT64_C(                   0),                    UINT64_MAX } },
    { { SIMDE_FLOAT64_C(    -9.19), SIMDE_FLOAT64_C(   -76.59) },
      { SIMDE_FLOAT64_C(    -9.19), SIMDE_FLOAT64_C(   -76.59) },
      {                    UINT64_MAX,                    UINT64_MAX } },
    { { SIMDE_FLOAT64_C(   751.31), SIMDE_FLOAT64_C(    63.65) },
      { SIMDE_FLOAT64_C(   403.25), SIMDE_FLOAT64_C(  -261.55) },
      {                    UINT64_MAX,                    UINT64_MAX } },
    { { SIMDE_FLOAT64_C(  -195.23), SIMDE_FLOAT64_C(   820.28) },
      { SIMDE_FLOAT64_C(   857.78), SIMDE_FLOAT64_C(   938.65) },
      { UINT64_C(                   0), UINT64_C(                   0) } },
    { { SIMDE_FLOAT64_C(   569.69), SIMDE_FLOAT64_C(   100.11) },
      { SIMDE_FLOAT64_C(   861.54), SIMDE_FLOAT64_C(   100.11) },
      { UINT64_C(                   0),                    UINT64_MAX } },
    { { SIMDE_FLOAT64_C(    58.64), SIMDE_FLOAT64_C(  -798.26) },
      { SIMDE_FLOAT64_C(    58.64), SIMDE_FLOAT64_C(  -185.24) },
      {                    UINT64_MAX, UINT64_C(                   0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2_t a = simde_vld1q_f64(test_vec[i].a);
    simde_float64x2_t b = simde_vld1q_f64(test_vec[i].b);
    simde_uint64x2_t r = simde_vcgeq_f64(a, b);

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

    simde_uint64x2_t r = simde_vcgeq_f64(a, b);

    simde_test_arm_neon_write_f64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcgeq_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[16];
    int8_t b[16];
    uint8_t r[16];
  } test_vec[] = {
    { { -INT8_C( 109), -INT8_C(  41), -INT8_C(  32),  INT8_C(  96), -INT8_C(   7), -INT8_C(  37), -INT8_C(   8), -INT8_C( 122),
         INT8_C(  44),  INT8_C(  13), -INT8_C( 104),  INT8_C(   3), -INT8_C(  92), -INT8_C(  42), -INT8_C(  53),  INT8_C(  65) },
      { -INT8_C( 109),  INT8_C(  22), -INT8_C(  32),  INT8_C(  96), -INT8_C(  11), -INT8_C(  37), -INT8_C(   8), -INT8_C( 122),
        -INT8_C(  26), -INT8_C(  67), -INT8_C(  74),  INT8_C(   3), -INT8_C(  92), -INT8_C(  31), -INT8_C(  53),  INT8_C(  65) },
      {    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX } },
    { {  INT8_C(  49), -INT8_C(  72),  INT8_C(  57), -INT8_C(  82), -INT8_C( 109),  INT8_C(  49), -INT8_C(  84),  INT8_C( 121),
        -INT8_C(   9),  INT8_C(  98),  INT8_C(  12), -INT8_C( 110), -INT8_C(   8), -INT8_C(  29), -INT8_C(  44),  INT8_C(  41) },
      {  INT8_C(  69), -INT8_C( 104), -INT8_C(  82), -INT8_C(  82), -INT8_C(  73), -INT8_C( 122),  INT8_C(  67), -INT8_C(  28),
        -INT8_C(   9), -INT8_C(  34),  INT8_C(  12),  INT8_C(  61), -INT8_C(   8), -INT8_C(  29),  INT8_C(  23),  INT8_C(  41) },
      { UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX } },
    { {  INT8_C( 111),  INT8_C(  76),  INT8_C(  96),  INT8_C(  39), -INT8_C(  46), -INT8_C(  93),  INT8_C(  11), -INT8_C(  55),
        -INT8_C( 127),  INT8_C( 100),  INT8_C(   7), -INT8_C(   2), -INT8_C(   6),  INT8_C(  30), -INT8_C(  93), -INT8_C( 106) },
      {  INT8_C( 110), -INT8_C(  14), -INT8_C(  60), -INT8_C(  16), -INT8_C(  18),  INT8_C( 108),  INT8_C(  97),  INT8_C(  77),
        -INT8_C( 111),  INT8_C( 100), -INT8_C(  17), -INT8_C(   2),  INT8_C(  59), -INT8_C( 115), -INT8_C(  80), -INT8_C(  86) },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
        UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0) } },
    { {  INT8_C(  67),  INT8_C(  72), -INT8_C(   7), -INT8_C(  71), -INT8_C(  75),  INT8_C(  90), -INT8_C(  18),  INT8_C(  70),
        -INT8_C(  66),  INT8_C( 110),  INT8_C(  69), -INT8_C(   7), -INT8_C(   5), -INT8_C(  11),  INT8_C(  19), -INT8_C(  44) },
      {  INT8_C(   6),  INT8_C( 117),      INT8_MAX, -INT8_C(  71),  INT8_C(  81), -INT8_C(  12), -INT8_C(  18),  INT8_C(  69),
         INT8_C( 112), -INT8_C( 100),  INT8_C(  51),  INT8_C(  10), -INT8_C(  19), -INT8_C(  73),  INT8_C(  19),  INT8_C(  48) },
      {    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
        UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0) } },
    { {  INT8_C(  53), -INT8_C(  98), -INT8_C(  11), -INT8_C( 121), -INT8_C( 110),  INT8_C( 101), -INT8_C(  52),  INT8_C(  48),
        -INT8_C(  91), -INT8_C(   1),  INT8_C( 122), -INT8_C(  38), -INT8_C(  74),  INT8_C(  32),  INT8_C(  22), -INT8_C(  55) },
      {  INT8_C(  44), -INT8_C(   1),  INT8_C( 106), -INT8_C( 110), -INT8_C(  32),  INT8_C( 101), -INT8_C(  74),  INT8_C(  48),
        -INT8_C(  91), -INT8_C(  45),  INT8_C( 122), -INT8_C(  38), -INT8_C( 108), -INT8_C( 103),  INT8_C(  22), -INT8_C(  55) },
      {    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX } },
    { { -INT8_C(  10), -INT8_C(  15), -INT8_C(  71),  INT8_C(  85),  INT8_C(  86),  INT8_C( 101), -INT8_C( 123),  INT8_C(  41),
         INT8_C(  63), -INT8_C(   1), -INT8_C(  43), -INT8_C(  41), -INT8_C( 104), -INT8_C( 126),  INT8_C(  97),  INT8_C(  20) },
      { -INT8_C(  10), -INT8_C(  15), -INT8_C( 103), -INT8_C(  28),  INT8_C(  14),  INT8_C( 101),  INT8_C(  81),  INT8_C(  41),
         INT8_C(  63),  INT8_C(  42), -INT8_C(   5),  INT8_C(  58), -INT8_C(  96), -INT8_C( 126),  INT8_C(  97),  INT8_C(  20) },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,
           UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX } },
    { {  INT8_C(  56), -INT8_C(  17),  INT8_C(  96),  INT8_C(  70),  INT8_C(  84), -INT8_C(  79), -INT8_C(  94), -INT8_C( 108),
        -INT8_C(  36),  INT8_C( 106),  INT8_C(  93),  INT8_C(  11), -INT8_C(  20),  INT8_C(  47), -INT8_C( 112), -INT8_C(  58) },
      {  INT8_C(  73), -INT8_C(   6),  INT8_C(  40), -INT8_C(  44), -INT8_C(  24), -INT8_C(  20), -INT8_C(  94), -INT8_C(  42),
        -INT8_C( 122),  INT8_C(  71),  INT8_C(  93),  INT8_C(  11), -INT8_C( 114), -INT8_C(  77), -INT8_C( 122), -INT8_C(  58) },
      { UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX } },
    { {  INT8_C( 122), -INT8_C(  18), -INT8_C(  91),  INT8_C(  99),  INT8_C(  71),  INT8_C(  71),  INT8_C(  57), -INT8_C(  51),
        -INT8_C(  59), -INT8_C( 106), -INT8_C(  40),  INT8_C(  76),  INT8_C(  73),  INT8_C(  84),  INT8_C(  29), -INT8_C(  21) },
      {  INT8_C(  69), -INT8_C(  18), -INT8_C(  30), -INT8_C(  35),  INT8_C( 106),  INT8_C( 108),  INT8_C(  81),  INT8_C(  80),
        -INT8_C(  59),  INT8_C(  65),  INT8_C(  34),  INT8_C(  76), -INT8_C(  63),  INT8_C(  84),  INT8_C(  29),  INT8_C(  60) },
      {    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
           UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16_t a = simde_vld1q_s8(test_vec[i].a);
    simde_int8x16_t b = simde_vld1q_s8(test_vec[i].b);
    simde_uint8x16_t r = simde_vcgeq_s8(a, b);

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

    simde_uint8x16_t r = simde_vcgeq_s8(a, b);

    simde_test_arm_neon_write_i8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcgeq_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[8];
    int16_t b[8];
    uint16_t r[8];
  } test_vec[] = {
    { {  INT16_C( 17214), -INT16_C( 27485), -INT16_C(  3533),  INT16_C( 14277),  INT16_C( 16736), -INT16_C( 26586),  INT16_C( 16877), -INT16_C(  1335) },
      {  INT16_C( 17214),  INT16_C( 27925),  INT16_C( 25546),  INT16_C( 15187),  INT16_C(  6524),  INT16_C( 24375),  INT16_C( 21212), -INT16_C(  1335) },
      {      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX } },
    { { -INT16_C( 26219), -INT16_C( 32169),  INT16_C(  6874),  INT16_C(  6484),  INT16_C( 27230),  INT16_C( 10374), -INT16_C( 22869),  INT16_C( 18787) },
      { -INT16_C( 25869), -INT16_C( 12376),  INT16_C( 29421), -INT16_C(  2359),  INT16_C( 22494),  INT16_C( 15667), -INT16_C( 22869),  INT16_C( 16892) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX } },
    { { -INT16_C( 18046),  INT16_C( 20469),  INT16_C( 22675), -INT16_C( 31080),  INT16_C( 16627), -INT16_C(  8107),  INT16_C( 15933), -INT16_C( 28202) },
      {  INT16_C(  2421),  INT16_C(  8654), -INT16_C( 13392), -INT16_C(  3998),  INT16_C(  9503), -INT16_C( 29430),  INT16_C( 15933), -INT16_C( 16550) },
      { UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0) } },
    { {  INT16_C( 26087), -INT16_C(  8336), -INT16_C( 13757),  INT16_C( 15006), -INT16_C(  1702), -INT16_C( 15931), -INT16_C( 10925), -INT16_C(  7174) },
      {  INT16_C(  1441), -INT16_C(  8336), -INT16_C( 13757),  INT16_C( 15006), -INT16_C( 21223), -INT16_C( 15931), -INT16_C( 10925),  INT16_C( 14939) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0) } },
    { { -INT16_C( 11785), -INT16_C( 17524), -INT16_C( 31155), -INT16_C(  4194),  INT16_C(  3979), -INT16_C( 12594),  INT16_C( 21626), -INT16_C(  3319) },
      { -INT16_C( 12775),  INT16_C( 28084),  INT16_C(  4003), -INT16_C(  8537),  INT16_C( 31717),  INT16_C(  3229),  INT16_C( 21626),  INT16_C( 29070) },
      {      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0) } },
    { {  INT16_C( 12506), -INT16_C( 19206),  INT16_C(   925), -INT16_C( 18777),  INT16_C( 24324), -INT16_C( 23074),  INT16_C( 16682),  INT16_C(  1489) },
      { -INT16_C(  4026), -INT16_C( 16292), -INT16_C(  5563),  INT16_C( 27442),  INT16_C( 24324), -INT16_C( 23074),  INT16_C( 16682),  INT16_C(  1489) },
      {      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX } },
    { { -INT16_C(  5957),  INT16_C( 30310),  INT16_C( 27059), -INT16_C( 25989), -INT16_C( 11687), -INT16_C( 24902),  INT16_C( 28308), -INT16_C( 16119) },
      { -INT16_C(  6069),  INT16_C( 30310),  INT16_C( 14121), -INT16_C( 25989),  INT16_C( 13314), -INT16_C( 11863),  INT16_C( 28308),  INT16_C( 20338) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0) } },
    { {  INT16_C( 17947),  INT16_C( 30952),  INT16_C(  7348), -INT16_C(  2503), -INT16_C( 24614), -INT16_C( 27627), -INT16_C(  6186), -INT16_C(  9827) },
      {  INT16_C( 17947), -INT16_C( 20566),  INT16_C(  7348),  INT16_C(  3070),  INT16_C( 29604), -INT16_C( 27627),  INT16_C(  6493),  INT16_C(  6622) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_int16x8_t b = simde_vld1q_s16(test_vec[i].b);
    simde_uint16x8_t r = simde_vcgeq_s16(a, b);

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

    simde_uint16x8_t r = simde_vcgeq_s16(a, b);

    simde_test_arm_neon_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcgeq_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[4];
    int32_t b[4];
    uint32_t r[4];
  } test_vec[] = {
    { { -INT32_C(  1532700866),  INT32_C(   326959941), -INT32_C(  1401836417), -INT32_C(   433567921) },
      { -INT32_C(    98180169),  INT32_C(   326959941), -INT32_C(  1401836417), -INT32_C(   643440230) },
      { UINT32_C(         0),           UINT32_MAX,           UINT32_MAX,           UINT32_MAX } },
    { { -INT32_C(  1473525636), -INT32_C(  1025524110),  INT32_C(  1314168982),  INT32_C(   817286634) },
      {  INT32_C(  1329804496),  INT32_C(  2080093408),  INT32_C(  1314168982),  INT32_C(  1714475498) },
      { UINT32_C(         0), UINT32_C(         0),           UINT32_MAX, UINT32_C(         0) } },
    { {  INT32_C(   533589530), -INT32_C(   522422794),  INT32_C(   319853123), -INT32_C(  1486662714) },
      { -INT32_C(  1641914872), -INT32_C(   370379009), -INT32_C(   531686073), -INT32_C(  1830068616) },
      {           UINT32_MAX, UINT32_C(         0),           UINT32_MAX,           UINT32_MAX } },
    { {  INT32_C(  1831737894), -INT32_C(   410700768),  INT32_C(   692205788),  INT32_C(  1160622150) },
      {  INT32_C(  1831737894), -INT32_C(  1353875913),  INT32_C(   692205788),  INT32_C(   544011505) },
      {           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX } },
    { {  INT32_C(  1267275460),  INT32_C(  1171986430), -INT32_C(   309720889), -INT32_C(    43809991) },
      {  INT32_C(   319399735), -INT32_C(   784512032), -INT32_C(  1041127105), -INT32_C(    43809991) },
      {           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX } },
    { { -INT32_C(   857922556), -INT32_C(  1946395055),  INT32_C(  1470632992),  INT32_C(  1360253261) },
      {  INT32_C(   997042428), -INT32_C(  1946395055),  INT32_C(  2072535265),  INT32_C(  1360253261) },
      { UINT32_C(         0),           UINT32_MAX, UINT32_C(         0),           UINT32_MAX } },
    { {  INT32_C(  2020726615), -INT32_C(  1496376853), -INT32_C(   951960885), -INT32_C(  1003480211) },
      { -INT32_C(   272630003), -INT32_C(  1402321057),  INT32_C(   251559193), -INT32_C(  1003480211) },
      {           UINT32_MAX, UINT32_C(         0), UINT32_C(         0),           UINT32_MAX } },
    { { -INT32_C(  2038166341), -INT32_C(   980723112),  INT32_C(  1753922421), -INT32_C(  1351541680) },
      {  INT32_C(  2086460259), -INT32_C(   980723112),  INT32_C(  1753922421),  INT32_C(   407225949) },
      { UINT32_C(         0),           UINT32_MAX,           UINT32_MAX, UINT32_C(         0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int32x4_t b = simde_vld1q_s32(test_vec[i].b);
    simde_uint32x4_t r = simde_vcgeq_s32(a, b);

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

    simde_uint32x4_t r = simde_vcgeq_s32(a, b);

    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcgeq_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a[2];
    int64_t b[2];
    uint64_t r[2];
  } test_vec[] = {
    { { -INT64_C( 6749822669995771752), -INT64_C( 3818101802221279798) },
      { -INT64_C( 6305717332762332197),  INT64_C( 7175660046940033834) },
      { UINT64_C(                   0), UINT64_C(                   0) } },
    { {  INT64_C( 9028077517965231098),  INT64_C( 7747673213297553935) },
      {  INT64_C( 9028077517965231098),  INT64_C( 1061606484645582218) },
      {                    UINT64_MAX,                    UINT64_MAX } },
    { { -INT64_C( 5052448151738273918),  INT64_C( 6997175910299228985) },
      { -INT64_C( 5052448151738273918),  INT64_C( 6997175910299228985) },
      {                    UINT64_MAX,                    UINT64_MAX } },
    { {  INT64_C( 4769728672330431475),  INT64_C( 2814510728028042588) },
      {  INT64_C( 4769728672330431475), -INT64_C( 6557647891631334546) },
      {                    UINT64_MAX,                    UINT64_MAX } },
    { {  INT64_C(  832768351716102019), -INT64_C( 8268287527640553738) },
      { -INT64_C( 5636969100111038727), -INT64_C( 1595533866079108353) },
      {                    UINT64_MAX, UINT64_C(                   0) } },
    { { -INT64_C( 8590531313175455935),  INT64_C( 6501900541919899210) },
      { -INT64_C( 8590531313175455935),  INT64_C( 6501900541919899210) },
      {                    UINT64_MAX,                    UINT64_MAX } },
    { { -INT64_C(   44138923088680662),  INT64_C( 6471204320746746648) },
      { -INT64_C( 5884813147232659619), -INT64_C( 1137101979037570025) },
      {                    UINT64_MAX,                    UINT64_MAX } },
    { {  INT64_C( 1343769224458206736),  INT64_C( 8143583866422456588) },
      { -INT64_C( 8958862038161701909),  INT64_C( 8143583866422456588) },
      {                    UINT64_MAX,                    UINT64_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);
    simde_int64x2_t b = simde_vld1q_s64(test_vec[i].b);
    simde_uint64x2_t r = simde_vcgeq_s64(a, b);

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

    simde_uint64x2_t r = simde_vcgeq_s64(a, b);

    simde_test_arm_neon_write_i64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcgeq_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t a[16];
    uint8_t b[16];
    uint8_t r[16];
  } test_vec[] = {
    { { UINT8_C( 98), UINT8_C( 69), UINT8_C(  0), UINT8_C(252), UINT8_C( 36), UINT8_C(131), UINT8_C( 30), UINT8_C(216),
        UINT8_C( 60), UINT8_C( 12), UINT8_C(190), UINT8_C(154), UINT8_C(230), UINT8_C(105), UINT8_C(205), UINT8_C(119) },
      { UINT8_C( 98), UINT8_C(214), UINT8_C( 49), UINT8_C( 72), UINT8_C( 36), UINT8_C( 54), UINT8_C(211), UINT8_C(157),
        UINT8_C(199), UINT8_C( 12), UINT8_C(178), UINT8_C(154), UINT8_C(160), UINT8_C(105), UINT8_C(205), UINT8_C( 70) },
      {    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,
        UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX } },
    { { UINT8_C(193), UINT8_C(217), UINT8_C(110), UINT8_C(114), UINT8_C( 36), UINT8_C(103),    UINT8_MAX, UINT8_C(235),
        UINT8_C(176), UINT8_C(  8), UINT8_C(134), UINT8_C( 80), UINT8_C(159), UINT8_C( 83), UINT8_C(150), UINT8_C(180) },
      { UINT8_C( 33), UINT8_C(217), UINT8_C(110), UINT8_C(114), UINT8_C( 58), UINT8_C(103),    UINT8_MAX, UINT8_C(153),
        UINT8_C( 30), UINT8_C(  8), UINT8_C(223), UINT8_C( 68), UINT8_C(243), UINT8_C(156), UINT8_C(205), UINT8_C(180) },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX } },
    { { UINT8_C(224), UINT8_C(172), UINT8_C(  6), UINT8_C(236), UINT8_C( 19), UINT8_C(  5), UINT8_C(133), UINT8_C( 49),
        UINT8_C( 14), UINT8_C(101), UINT8_C(118), UINT8_C(  1), UINT8_C(  1), UINT8_C(236), UINT8_C(252), UINT8_C(140) },
      { UINT8_C(224), UINT8_C( 78), UINT8_C( 58), UINT8_C( 34), UINT8_C(107), UINT8_C(212), UINT8_C( 20), UINT8_C(189),
        UINT8_C(244), UINT8_C( 86), UINT8_C(174), UINT8_C(104), UINT8_C( 47), UINT8_C(236), UINT8_C(252), UINT8_C(225) },
      {    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),
        UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0) } },
    { { UINT8_C( 27), UINT8_C(226), UINT8_C(153), UINT8_C(185), UINT8_C( 53), UINT8_C(  1), UINT8_C(207), UINT8_C( 73),
        UINT8_C(  4), UINT8_C(231), UINT8_C(167), UINT8_C( 51), UINT8_C(221), UINT8_C(173), UINT8_C( 21), UINT8_C(118) },
      { UINT8_C(176), UINT8_C(226), UINT8_C( 35), UINT8_C(185), UINT8_C( 53), UINT8_C(  1), UINT8_C(207), UINT8_C(237),
        UINT8_C( 85), UINT8_C(231), UINT8_C(167), UINT8_C(236), UINT8_C(179), UINT8_C(236), UINT8_C( 99), UINT8_C(206) },
      { UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),
        UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) } },
    { { UINT8_C(217), UINT8_C( 95), UINT8_C(210), UINT8_C( 15), UINT8_C(246), UINT8_C(161), UINT8_C(251), UINT8_C( 85),
        UINT8_C(130), UINT8_C(163), UINT8_C( 65), UINT8_C(235), UINT8_C(144), UINT8_C(165), UINT8_C( 10), UINT8_C(252) },
      { UINT8_C(162), UINT8_C( 95), UINT8_C(189), UINT8_C( 76), UINT8_C(246), UINT8_C(199), UINT8_C(251), UINT8_C(127),
        UINT8_C(130), UINT8_C(221), UINT8_C(229), UINT8_C(235), UINT8_C(212), UINT8_C(193), UINT8_C(  4), UINT8_C(173) },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),
           UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX } },
    { { UINT8_C(181), UINT8_C(  2), UINT8_C( 68), UINT8_C(156), UINT8_C(110), UINT8_C( 91), UINT8_C( 27), UINT8_C(240),
        UINT8_C(179), UINT8_C(  0), UINT8_C(219), UINT8_C(152), UINT8_C(193), UINT8_C(223), UINT8_C( 80), UINT8_C(130) },
      { UINT8_C(181), UINT8_C(  2), UINT8_C( 68), UINT8_C( 45), UINT8_C(187), UINT8_C( 91), UINT8_C( 45), UINT8_C( 23),
        UINT8_C(179), UINT8_C(105), UINT8_C(  4), UINT8_C(177), UINT8_C(175), UINT8_C(237), UINT8_C( 80), UINT8_C( 85) },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,
           UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX } },
    { { UINT8_C(224), UINT8_C(148), UINT8_C( 31), UINT8_C(130), UINT8_C(239), UINT8_C(188), UINT8_C(153), UINT8_C( 51),
        UINT8_C( 37), UINT8_C(107), UINT8_C( 83), UINT8_C(140), UINT8_C(138), UINT8_C(164), UINT8_C(238), UINT8_C( 30) },
      { UINT8_C(224), UINT8_C( 27), UINT8_C( 31), UINT8_C(  4), UINT8_C( 39), UINT8_C( 17), UINT8_C(235), UINT8_C( 51),
        UINT8_C(223), UINT8_C(107), UINT8_C(  0), UINT8_C(140), UINT8_C( 48), UINT8_C( 80), UINT8_C(238), UINT8_C(247) },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,
        UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0) } },
    { { UINT8_C(122), UINT8_C(120), UINT8_C(221), UINT8_C(161), UINT8_C( 91), UINT8_C( 83), UINT8_C(212), UINT8_C(104),
        UINT8_C( 28), UINT8_C(212), UINT8_C( 69), UINT8_C(216), UINT8_C( 37), UINT8_C(227), UINT8_C(216), UINT8_C(  9) },
      { UINT8_C( 97), UINT8_C( 72), UINT8_C(221), UINT8_C(155), UINT8_C( 91), UINT8_C( 83), UINT8_C(251), UINT8_C( 11),
        UINT8_C( 28), UINT8_C( 48), UINT8_C( 69), UINT8_C(138), UINT8_C(143), UINT8_C(158), UINT8_C(216), UINT8_C(  9) },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x16_t a = simde_vld1q_u8(test_vec[i].a);
    simde_uint8x16_t b = simde_vld1q_u8(test_vec[i].b);
    simde_uint8x16_t r = simde_vcgeq_u8(a, b);

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

    simde_uint8x16_t r = simde_vcgeq_u8(a, b);

    simde_test_arm_neon_write_u8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcgeq_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[8];
    uint16_t b[8];
    uint16_t r[8];
  } test_vec[] = {
    { { UINT16_C(45482), UINT16_C(64499), UINT16_C(25037), UINT16_C(12580), UINT16_C(59654), UINT16_C(35892), UINT16_C( 2294), UINT16_C(31274) },
      { UINT16_C(64286), UINT16_C(46359), UINT16_C(19027), UINT16_C(18590), UINT16_C( 9601), UINT16_C(44740), UINT16_C(52996), UINT16_C(44680) },
      { UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { { UINT16_C(46007), UINT16_C(22200), UINT16_C(39355), UINT16_C(17668), UINT16_C(16277), UINT16_C(59534), UINT16_C( 4732), UINT16_C( 2608) },
      { UINT16_C(62802), UINT16_C(22200), UINT16_C(16836), UINT16_C(17668), UINT16_C(44732), UINT16_C(39315), UINT16_C( 4732), UINT16_C(13435) },
      { UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0) } },
    { { UINT16_C(59721), UINT16_C(54017), UINT16_C(12565), UINT16_C(39969), UINT16_C(38438), UINT16_C( 5661), UINT16_C(49879), UINT16_C(37680) },
      { UINT16_C(50288), UINT16_C(60716), UINT16_C(43222), UINT16_C(39969), UINT16_C(  914), UINT16_C( 5661), UINT16_C(30477), UINT16_C(22063) },
      {      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX } },
    { { UINT16_C(39837), UINT16_C(29811), UINT16_C(46191), UINT16_C(52487), UINT16_C(13416), UINT16_C(18245), UINT16_C(56284), UINT16_C( 4047) },
      { UINT16_C(63454), UINT16_C(60293), UINT16_C(46191), UINT16_C(53058), UINT16_C(27621), UINT16_C(18245), UINT16_C( 9074), UINT16_C( 4047) },
      { UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX } },
    { { UINT16_C(41919), UINT16_C(39821), UINT16_C(15878), UINT16_C(23817), UINT16_C(64385), UINT16_C(52808), UINT16_C(35395), UINT16_C(10398) },
      { UINT16_C(58358), UINT16_C(26735), UINT16_C(15878), UINT16_C(50296), UINT16_C(64385), UINT16_C(26847), UINT16_C(51334), UINT16_C(17847) },
      { UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0) } },
    { { UINT16_C(36728), UINT16_C(48091), UINT16_C(31001), UINT16_C(15031), UINT16_C(21084), UINT16_C(25464), UINT16_C(61585), UINT16_C( 4647) },
      { UINT16_C( 2027), UINT16_C(29307), UINT16_C(13007), UINT16_C(15031), UINT16_C(39031), UINT16_C( 9251), UINT16_C(27266), UINT16_C(64049) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0) } },
    { { UINT16_C(39660), UINT16_C(32068), UINT16_C(27786), UINT16_C(30095), UINT16_C( 2675), UINT16_C(17127), UINT16_C(14083), UINT16_C(46204) },
      { UINT16_C(40759), UINT16_C(47577), UINT16_C( 2569), UINT16_C(  691), UINT16_C(26902), UINT16_C(39701), UINT16_C(14083), UINT16_C(61308) },
      { UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0) } },
    { { UINT16_C(47110), UINT16_C(17378), UINT16_C( 2133), UINT16_C(36599), UINT16_C(53501), UINT16_C( 1863), UINT16_C(21181), UINT16_C(50070) },
      { UINT16_C( 7780), UINT16_C(26507), UINT16_C( 2133), UINT16_C( 9814), UINT16_C(49865), UINT16_C(63105), UINT16_C(21181), UINT16_C(50070) },
      {      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);
    simde_uint16x8_t b = simde_vld1q_u16(test_vec[i].b);
    simde_uint16x8_t r = simde_vcgeq_u16(a, b);

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

    simde_uint16x8_t r = simde_vcgeq_u16(a, b);

    simde_test_arm_neon_write_u16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcgeq_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[4];
    uint32_t b[4];
    uint32_t r[4];
  } test_vec[] = {
    { { UINT32_C(2162069647), UINT32_C(3754241403), UINT32_C(3789104306), UINT32_C(2344517141) },
      { UINT32_C(1058982851), UINT32_C(1223602262), UINT32_C(3789104306), UINT32_C(3709876814) },
      {           UINT32_MAX,           UINT32_MAX,           UINT32_MAX, UINT32_C(         0) } },
    { { UINT32_C( 858071851), UINT32_C(1863283233), UINT32_C(3484233484), UINT32_C(1488824877) },
      { UINT32_C( 765066619), UINT32_C(1863283233), UINT32_C(2001547181), UINT32_C(1488824877) },
      {           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX } },
    { { UINT32_C( 803876226), UINT32_C( 625846571), UINT32_C(4034288757), UINT32_C(2048790361) },
      { UINT32_C( 803876226), UINT32_C(2309371740), UINT32_C(2950784225), UINT32_C(3096013895) },
      {           UINT32_MAX, UINT32_C(         0),           UINT32_MAX, UINT32_C(         0) } },
    { { UINT32_C(2763555887), UINT32_C( 966078432), UINT32_C(2063199762), UINT32_C(1022336480) },
      { UINT32_C(3066402516), UINT32_C(1097180922), UINT32_C(2063199762), UINT32_C(2752327796) },
      { UINT32_C(         0), UINT32_C(         0),           UINT32_MAX, UINT32_C(         0) } },
    { { UINT32_C( 699665687), UINT32_C(1895006352), UINT32_C(4071416606), UINT32_C(1940418937) },
      { UINT32_C( 699665687), UINT32_C(1889775100), UINT32_C(2434052317), UINT32_C(1780833654) },
      {           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX } },
    { { UINT32_C(2436600179), UINT32_C(1680915182), UINT32_C(1389319703), UINT32_C(3139267656) },
      { UINT32_C(2678472385), UINT32_C(1680915182), UINT32_C(1389319703), UINT32_C(3139267656) },
      { UINT32_C(         0),           UINT32_MAX,           UINT32_MAX,           UINT32_MAX } },
    { { UINT32_C(2589904960), UINT32_C( 889962236), UINT32_C(2490082770), UINT32_C(3526562275) },
      { UINT32_C(3811992523), UINT32_C(  37029305), UINT32_C(1874678386), UINT32_C(3957394090) },
      { UINT32_C(         0),           UINT32_MAX,           UINT32_MAX, UINT32_C(         0) } },
    { { UINT32_C(2578869031), UINT32_C( 426014261), UINT32_C(1407948679), UINT32_C(3023446523) },
      { UINT32_C(2578869031), UINT32_C(1728607421), UINT32_C(1481828734), UINT32_C( 657381161) },
      {           UINT32_MAX, UINT32_C(         0), UINT32_C(         0),           UINT32_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint32x4_t b = simde_vld1q_u32(test_vec[i].b);
    simde_uint32x4_t r = simde_vcgeq_u32(a, b);

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

    simde_uint32x4_t r = simde_vcgeq_u32(a, b);

    simde_test_arm_neon_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcgeq_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a[2];
    uint64_t b[2];
    uint64_t r[2];
  } test_vec[] = {
    { { UINT64_C(14562937709581382826), UINT64_C(14699337621818676983) },
      { UINT64_C(14562937709581382826), UINT64_C(14699337621818676983) },
      {                    UINT64_MAX,                    UINT64_MAX } },
    { { UINT64_C( 5459681504497828234), UINT64_C(14236187640464043906) },
      { UINT64_C( 2432150606451133712), UINT64_C(14236187640464043906) },
      {                    UINT64_MAX,                    UINT64_MAX } },
    { { UINT64_C(14476163272494907547), UINT64_C(10735033187440786193) },
      { UINT64_C(15985759095115223721), UINT64_C( 8346033058204750676) },
      { UINT64_C(                   0),                    UINT64_MAX } },
    { { UINT64_C(10714954279935368403), UINT64_C( 7414258787975201239) },
      { UINT64_C(16866699637832619814), UINT64_C( 3581921216148728434) },
      { UINT64_C(                   0),                    UINT64_MAX } },
    { { UINT64_C( 8400006579740446870), UINT64_C(15176171529956307873) },
      { UINT64_C( 8400006579740446870), UINT64_C(  763894644646866966) },
      {                    UINT64_MAX,                    UINT64_MAX } },
    { { UINT64_C(13328124129486869158), UINT64_C(16401399820575060595) },
      { UINT64_C(11678300727327993742), UINT64_C(16401399820575060595) },
      {                    UINT64_MAX,                    UINT64_MAX } },
    { { UINT64_C( 6642394988694951079), UINT64_C(16397272341211680939) },
      { UINT64_C( 6716273130845450993), UINT64_C(18205208125254365450) },
      { UINT64_C(                   0), UINT64_C(                   0) } },
    { { UINT64_C(16454700178904663451), UINT64_C( 1942922326156028726) },
      { UINT64_C(18396398711276686247), UINT64_C( 4185001424853443275) },
      { UINT64_C(                   0), UINT64_C(                   0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x2_t a = simde_vld1q_u64(test_vec[i].a);
    simde_uint64x2_t b = simde_vld1q_u64(test_vec[i].b);
    simde_uint64x2_t r = simde_vcgeq_u64(a, b);

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

    simde_uint64x2_t r = simde_vcgeq_u64(a, b);

    simde_test_arm_neon_write_u64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcged_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64_t a;
    simde_float64_t b;
    uint64_t r;
  } test_vec[] = {
    { SIMDE_FLOAT64_C(  -955.88),
      SIMDE_FLOAT64_C(  -521.65),
      UINT64_C(                   0) },
    { SIMDE_FLOAT64_C(  -897.79),
      SIMDE_FLOAT64_C(   470.54),
      UINT64_C(                   0) },
    { SIMDE_FLOAT64_C(  -745.84),
      SIMDE_FLOAT64_C(   428.02),
      UINT64_C(                   0) },
    { SIMDE_FLOAT64_C(   -40.46),
      SIMDE_FLOAT64_C(  -507.83),
                          UINT64_MAX },
    { SIMDE_FLOAT64_C(  -316.79),
      SIMDE_FLOAT64_C(  -212.59),
      UINT64_C(                   0) },
    { SIMDE_FLOAT64_C(   310.98),
      SIMDE_FLOAT64_C(   416.70),
      UINT64_C(                   0) },
    { SIMDE_FLOAT64_C(  -618.79),
      SIMDE_FLOAT64_C(  -147.59),
      UINT64_C(                   0) },
    { SIMDE_FLOAT64_C(   -21.02),
      SIMDE_FLOAT64_C(   -49.79),
                          UINT64_MAX }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint64_t r = simde_vcged_f64(test_vec[i].a, test_vec[i].b);
    simde_assert_equal_u64(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64_t a = simde_test_codegen_random_f64(-1000, 1000);
    simde_float64_t b = simde_test_codegen_random_f64(-1000, 1000);
    uint64_t r = simde_vcged_f64(a, b);

    simde_test_codegen_write_f64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_f64(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcged_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a;
    int64_t b;
    uint64_t r;
  } test_vec[] = {
    {  INT64_C( 4930038757313646244),
      -INT64_C(  691649397293164882),
                          UINT64_MAX },
    { -INT64_C( 5574423576483514706),
       INT64_C( 3390369991706064937),
      UINT64_C(                   0) },
    {  INT64_C( 6266676038853043089),
      -INT64_C( 6590347393013960438),
                          UINT64_MAX },
    { -INT64_C( 9037326586804392552),
      -INT64_C( 1050478493413515856),
      UINT64_C(                   0) },
    {  INT64_C( 8328451387728049303),
      -INT64_C( 8545982775360516148),
                          UINT64_MAX },
    {  INT64_C( 7068963332172790335),
      -INT64_C( 8381752009243688867),
                          UINT64_MAX },
    { -INT64_C( 5144976730938060355),
       INT64_C( 8171746557972619757),
      UINT64_C(                   0) },
    {  INT64_C( 3507780550188979098),
       INT64_C( 1271030305346374692),
                          UINT64_MAX }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint64_t r = simde_vcged_s64(test_vec[i].a, test_vec[i].b);
    simde_assert_equal_u64(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    int64_t a = simde_test_codegen_random_i64();
    int64_t b = simde_test_codegen_random_i64();
    uint64_t r = simde_vcged_s64(a, b);

    simde_test_codegen_write_i64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i64(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcged_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a;
    uint64_t b;
    uint64_t r;
  } test_vec[] = {
    { UINT64_C(13299360368766184684),
      UINT64_C( 9590132740269148786),
                          UINT64_MAX },
    { UINT64_C( 7481745908985569233),
      UINT64_C( 5202258298643923404),
                          UINT64_MAX },
    { UINT64_C(12398886113289267598),
      UINT64_C( 8515013481631688636),
                          UINT64_MAX },
    { UINT64_C( 5273977387663162758),
      UINT64_C( 6941344247826722735),
      UINT64_C(                   0) },
    { UINT64_C(16351666612702115077),
      UINT64_C( 3066305538171682161),
                          UINT64_MAX },
    { UINT64_C( 5077567332335003825),
      UINT64_C( 9297018960544391636),
      UINT64_C(                   0) },
    { UINT64_C(18024440934397230618),
      UINT64_C( 1349002230230002922),
                          UINT64_MAX },
    { UINT64_C(11899557851942726726),
      UINT64_C( 3789585684428911769),
                          UINT64_MAX }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint64_t r = simde_vcged_u64(test_vec[i].a, test_vec[i].b);
    simde_assert_equal_u64(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    uint64_t a = simde_test_codegen_random_u64();
    uint64_t b = simde_test_codegen_random_u64();
    uint64_t r = simde_vcged_u64(a, b);

    simde_test_codegen_write_u64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u64(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcgeh_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16_t a;
    simde_float16_t b;
    uint16_t r;
  } test_vec[] = {
    { SIMDE_FLOAT16_VALUE(   897.00),
      SIMDE_FLOAT16_VALUE(   715.00),
           UINT16_MAX },
    { SIMDE_FLOAT16_VALUE(   564.50),
      SIMDE_FLOAT16_VALUE(   345.75),
           UINT16_MAX },
    { SIMDE_FLOAT16_VALUE(  -134.25),
      SIMDE_FLOAT16_VALUE(   360.75),
      UINT16_C(    0) },
    { SIMDE_FLOAT16_VALUE(  -867.00),
      SIMDE_FLOAT16_VALUE(  -405.75),
      UINT16_C(    0) },
    { SIMDE_FLOAT16_VALUE(  -559.50),
      SIMDE_FLOAT16_VALUE(   946.50),
      UINT16_C(    0) },
    { SIMDE_FLOAT16_VALUE(   518.50),
      SIMDE_FLOAT16_VALUE(  -917.00),
           UINT16_MAX },
    { SIMDE_FLOAT16_VALUE(  -144.12),
      SIMDE_FLOAT16_VALUE(   -37.66),
      UINT16_C(    0) },
    { SIMDE_FLOAT16_VALUE(  -184.62),
      SIMDE_FLOAT16_VALUE(    14.89),
      UINT16_C(    0) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint16_t r = simde_vcgeh_f16(test_vec[i].a, test_vec[i].b);
    simde_assert_equal_u16(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16_t a = simde_test_codegen_random_f16(-1000, 1000);
    simde_float16_t b = simde_test_codegen_random_f16(-1000, 1000);
    uint16_t r = simde_vcgeh_f16(a, b);

    simde_test_codegen_write_f16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_f16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcges_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32_t a;
    simde_float32_t b;
    uint32_t r;
  } test_vec[] = {
    { SIMDE_FLOAT32_C(   -21.21),
      SIMDE_FLOAT32_C(   300.24),
      UINT32_C(         0) },
    { SIMDE_FLOAT32_C(   438.56),
      SIMDE_FLOAT32_C(   495.77),
      UINT32_C(         0) },
    { SIMDE_FLOAT32_C(   -26.88),
      SIMDE_FLOAT32_C(  -737.02),
                UINT32_MAX },
    { SIMDE_FLOAT32_C(  -990.02),
      SIMDE_FLOAT32_C(  -429.89),
      UINT32_C(         0) },
    { SIMDE_FLOAT32_C(  -168.07),
      SIMDE_FLOAT32_C(   593.84),
      UINT32_C(         0) },
    { SIMDE_FLOAT32_C(  -467.82),
      SIMDE_FLOAT32_C(  -348.61),
      UINT32_C(         0) },
    { SIMDE_FLOAT32_C(   492.16),
      SIMDE_FLOAT32_C(   -45.04),
                UINT32_MAX },
    { SIMDE_FLOAT32_C(   -31.77),
      SIMDE_FLOAT32_C(  -566.37),
                UINT32_MAX }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint32_t r = simde_vcges_f32(test_vec[i].a, test_vec[i].b);
    simde_assert_equal_u32(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32_t a = simde_test_codegen_random_f32(-1000, 1000);
    simde_float32_t b = simde_test_codegen_random_f32(-1000, 1000);
    uint32_t r = simde_vcges_f32(a, b);

    simde_test_codegen_write_f32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_f32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vcge_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcge_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcge_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vcge_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vcge_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcge_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcge_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vcge_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vcge_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcge_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcge_u64)

SIMDE_TEST_FUNC_LIST_ENTRY(vcgeq_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcgeq_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcgeq_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vcgeq_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vcgeq_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcgeq_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcgeq_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vcgeq_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vcgeq_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcgeq_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcgeq_u64)

SIMDE_TEST_FUNC_LIST_ENTRY(vcged_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vcged_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vcged_u64)
SIMDE_TEST_FUNC_LIST_ENTRY(vcgeh_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcges_f32)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
