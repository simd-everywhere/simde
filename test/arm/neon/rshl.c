#define SIMDE_TEST_ARM_NEON_INSN rshl

#include "test-neon.h"

/* Check that both of these work */
#if defined(__cplusplus)
  #include "../../../simde/arm/neon/rshl.h"
#else
  #include "../../../simde/arm/neon.h"
#endif

#if 0
#define PROBABILITY 80
#define probability(p) (rand() < (((int64_t) RAND_MAX * (p)) / 100))
#endif

static int
test_simde_vrshl_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int8_t a[8];
    int8_t b[8];
    int8_t r[8];
  } test_vec[] = {
    { { -INT8_C(   1), -INT8_C(  80),  INT8_C( 102),  INT8_C(  17),  INT8_C(  10),  INT8_C(  22),  INT8_C(  87), -INT8_C( 121) },
      {  INT8_C(   8),  INT8_C(   6),  INT8_C(   0),  INT8_C(   7), -INT8_C(   8),  INT8_C(   7),  INT8_C(  49), -INT8_C(   7) },
      {  INT8_C(   0),  INT8_C(   0),  INT8_C( 102),      INT8_MIN,  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1) } },
    { { -INT8_C(   1),  INT8_C(  26),  INT8_C(  68),  INT8_C(  57),  INT8_C(  29),  INT8_C(  19), -INT8_C(  63), -INT8_C( 107) },
      { -INT8_C(   8),  INT8_C(   5), -INT8_C(   6), -INT8_C(   7),  INT8_C(  62), -INT8_C(   2),  INT8_C(   5),  INT8_C(   5) },
      {  INT8_C(   0),  INT8_C(  64),  INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   5),  INT8_C(  32), -INT8_C(  96) } },
    { { -INT8_C(  31), -INT8_C(  21), -INT8_C( 103),  INT8_C(  75),  INT8_C( 114),  INT8_C(  33), -INT8_C(  81), -INT8_C(  75) },
      {  INT8_C(   7), -INT8_C(   7), -INT8_C(  17),  INT8_C(   5),  INT8_C(   6), -INT8_C(   5), -INT8_C(   5), -INT8_C(   7) },
      {      INT8_MIN,  INT8_C(   0),  INT8_C(   0),  INT8_C(  96),      INT8_MIN,  INT8_C(   1), -INT8_C(   3), -INT8_C(   1) } },
    { {  INT8_C(  65), -INT8_C(  49), -INT8_C(  12), -INT8_C(  43),  INT8_C(  99),  INT8_C(  26),  INT8_C(  31),  INT8_C(  68) },
      {  INT8_C(   6), -INT8_C(   5), -INT8_C(   7),  INT8_C(   7), -INT8_C(   5),  INT8_C(   7),  INT8_C(   5),  INT8_C(  21) },
      {  INT8_C(  64), -INT8_C(   2),  INT8_C(   0),      INT8_MIN,  INT8_C(   3),  INT8_C(   0), -INT8_C(  32),  INT8_C(   0) } },
    { { -INT8_C(  16), -INT8_C( 102), -INT8_C(  68), -INT8_C( 125), -INT8_C( 121),  INT8_C(  39),  INT8_C(  74), -INT8_C(  56) },
      { -INT8_C(  10),  INT8_C(  62), -INT8_C(  98),  INT8_C(  90),  INT8_C(   5), -INT8_C(   5), -INT8_C(   7),  INT8_C(  94) },
      {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  32),  INT8_C(   1),  INT8_C(   1),  INT8_C(   0) } },
    { {  INT8_C(  32), -INT8_C(  46), -INT8_C(  39), -INT8_C(  19),  INT8_C(  46), -INT8_C(  36), -INT8_C( 109),  INT8_C(  30) },
      {  INT8_C( 118),  INT8_C(  79), -INT8_C(   6), -INT8_C(   3),  INT8_C(   7), -INT8_C(   6), -INT8_C(   8),  INT8_C(   6) },
      {  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   2),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),      INT8_MIN } },
    { { -INT8_C( 108), -INT8_C(  73), -INT8_C(  27),  INT8_C(   1), -INT8_C(  69),  INT8_C(  73), -INT8_C(  95), -INT8_C(  37) },
      {  INT8_C(  27),  INT8_C( 122), -INT8_C(   7),  INT8_C(   4),  INT8_C(   5),  INT8_C(   5),  INT8_C(   6), -INT8_C(   7) },
      {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  16),  INT8_C(  96),  INT8_C(  32),  INT8_C(  64),  INT8_C(   0) } },
    { { -INT8_C(  12),  INT8_C(  85), -INT8_C(  96),  INT8_C(  21), -INT8_C(  69), -INT8_C( 127), -INT8_C(  84),  INT8_C(  79) },
      {  INT8_C(   7), -INT8_C(   7),  INT8_C(   5), -INT8_C(   7), -INT8_C(  37), -INT8_C(   7), -INT8_C(   7), -INT8_C(  10) },
      {  INT8_C(   0),  INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8_t a = simde_vld1_s8(test_vec[i].a);
    simde_int8x8_t b = simde_vld1_s8(test_vec[i].b);
    simde_int8x8_t r = simde_vrshl_s8(a, b);

    simde_test_arm_neon_assert_equal_i8x8(r, simde_vld1_s8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);

  int8_t a_patch[] = { -INT8_C(1), -INT8_C(1) };
  int8_t b_patch[] = {          8,         -8 };

  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x8_private a_ = simde_int8x8_to_private(simde_test_arm_neon_random_i8x8());
    simde_int8x8_private b_ = simde_int8x8_to_private(simde_test_arm_neon_random_i8x8());

    for (size_t j = 0 ; j < (sizeof(b_.values) / sizeof(b_.values[0])) ; j++) {
      if (probability(PROBABILITY)) {
        while (simde_math_abs(b_.values[j]) > 8) {
          b_.values[j] >>= 1;
        }
      }
    }

    if ((size_t) i < (sizeof(a_patch) / sizeof(a_patch[0]))) {
      a_.values[0] = a_patch[i];
      b_.values[0] = b_patch[i];
    }

    simde_int8x8_t a = simde_int8x8_from_private(a_);
    simde_int8x8_t b = simde_int8x8_from_private(b_);

    simde_int8x8_t r = simde_vrshl_s8(a, b);
    simde_test_arm_neon_write_i8x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vrshl_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int16_t a[4];
    int16_t b[4];
    int16_t r[4];
  } test_vec[] = {
    { { -INT16_C(     1),  INT16_C( 16127),  INT16_C(  7767),  INT16_C( 21548) },
      {  INT16_C(    16),  INT16_C(    11),  INT16_C(    15), -INT16_C(    16) },
      {  INT16_C(     0), -INT16_C(  2048),       INT16_MIN,  INT16_C(     0) } },
    { { -INT16_C(     1),  INT16_C(   155),  INT16_C( 26190), -INT16_C( 23334) },
      { -INT16_C(    16),  INT16_C(    14),  INT16_C(    14), -INT16_C(    12) },
      {  INT16_C(     0), -INT16_C( 16384),       INT16_MIN, -INT16_C(     6) } },
    { { -INT16_C( 12578),  INT16_C( 28010), -INT16_C( 16565),  INT16_C( 31821) },
      {  INT16_C(    11),  INT16_C(    12),  INT16_C(    11),  INT16_C(  7269) },
      { -INT16_C(  4096), -INT16_C( 24576),  INT16_C( 22528),  INT16_C(     0) } },
    { { -INT16_C(  1065),  INT16_C( 21373),  INT16_C( 12341), -INT16_C( 29402) },
      {  INT16_C(     9), -INT16_C(     9),  INT16_C(    13),  INT16_C(    12) },
      { -INT16_C( 20992),  INT16_C(    42), -INT16_C( 24576),  INT16_C( 24576) } },
    { { -INT16_C( 22525), -INT16_C( 11632), -INT16_C(  2809), -INT16_C( 12818) },
      { -INT16_C( 20684),  INT16_C(    11),  INT16_C(    10), -INT16_C(    16) },
      {  INT16_C(     0),       INT16_MIN,  INT16_C(  7168),  INT16_C(     0) } },
    { {  INT16_C( 14547), -INT16_C(  4223), -INT16_C(  9107),  INT16_C( 25175) },
      {  INT16_C(    14), -INT16_C(    15),  INT16_C(    14), -INT16_C(    11) },
      { -INT16_C( 16384),  INT16_C(     0),  INT16_C( 16384),  INT16_C(    12) } },
    { { -INT16_C( 29192), -INT16_C( 23726), -INT16_C( 20257),  INT16_C( 24964) },
      { -INT16_C(    14),  INT16_C(     8),  INT16_C(    14), -INT16_C( 26376) },
      { -INT16_C(     2),  INT16_C( 20992), -INT16_C( 16384),  INT16_C(    98) } },
    { { -INT16_C( 30838),  INT16_C( 27999), -INT16_C( 18012), -INT16_C( 18857) },
      {  INT16_C(    15), -INT16_C(     9),  INT16_C(     9),  INT16_C( 31646) },
      {  INT16_C(     0),  INT16_C(    55),  INT16_C( 18432),  INT16_C(     0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t a = simde_vld1_s16(test_vec[i].a);
    simde_int16x4_t b = simde_vld1_s16(test_vec[i].b);
    simde_int16x4_t r = simde_vrshl_s16(a, b);

    simde_test_arm_neon_assert_equal_i16x4(r, simde_vld1_s16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);

  int16_t a_patch[] = { -INT16_C(1), -INT16_C(1) };
  int16_t b_patch[] = {          16,         -16 };

  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x4_private a_ = simde_int16x4_to_private(simde_test_arm_neon_random_i16x4());
    simde_int16x4_private b_ = simde_int16x4_to_private(simde_test_arm_neon_random_i16x4());

    for (size_t j = 0 ; j < (sizeof(b_.values) / sizeof(b_.values[0])) ; j++) {
      if (probability(PROBABILITY)) {
        while (simde_math_abs(b_.values[j]) > 16) {
          b_.values[j] >>= 1;
        }
      }
    }

    if ((size_t) i < (sizeof(a_patch) / sizeof(a_patch[0]))) {
      a_.values[0] = a_patch[i];
      b_.values[0] = b_patch[i];
    }

    simde_int16x4_t a = simde_int16x4_from_private(a_);
    simde_int16x4_t b = simde_int16x4_from_private(b_);

    simde_int16x4_t r = simde_vrshl_s16(a, b);

    simde_test_arm_neon_write_i16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vrshl_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int32_t a[2];
    int32_t b[2];
    int32_t r[2];
  } test_vec[] = {
    { { -INT32_C(           1), -INT32_C(  1425395738) },
      {  INT32_C(          32), -INT32_C(          32) },
      {  INT32_C(           0),  INT32_C(           0) } },
    { { -INT32_C(           1),  INT32_C(  1217089360) },
      { -INT32_C(          32),  INT32_C(          20) },
      {  INT32_C(           0), -INT32_C(   184549376) } },
    { { -INT32_C(  1741455487), -INT32_C(   478087585) },
      { -INT32_C(  1033648548),  INT32_C(          25) },
      {  INT32_C(           0), -INT32_C(  1107296256) } },
    { { -INT32_C(  1102370122),  INT32_C(  1878396110) },
      { -INT32_C(          32),  INT32_C(          20) },
      {  INT32_C(           0), -INT32_C(   857735168) } },
    { { -INT32_C(  1522312632), -INT32_C(   915953887) },
      {  INT32_C(          26),  INT32_C(  1737811484) },
      {  INT32_C(   536870912),  INT32_C(   268435456) } },
    { {  INT32_C(  2144508531),  INT32_C(  1342214961) },
      { -INT32_C(          21), -INT32_C(          23) },
      {  INT32_C(        1023),  INT32_C(         160) } },
    { {  INT32_C(   385152843),  INT32_C(   746660880) },
      { -INT32_C(          21),  INT32_C(  1246234488) },
      {  INT32_C(         184),  INT32_C(           0) } },
    { { -INT32_C(  1295350051), -INT32_C(   413045626) },
      { -INT32_C(          25), -INT32_C(          30) },
      { -INT32_C(          39),  INT32_C(           0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t a = simde_vld1_s32(test_vec[i].a);
    simde_int32x2_t b = simde_vld1_s32(test_vec[i].b);
    simde_int32x2_t r = simde_vrshl_s32(a, b);

    simde_test_arm_neon_assert_equal_i32x2(r, simde_vld1_s32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);

  int32_t a_patch[] = { -INT32_C(1), -INT32_C(1) };
  int32_t b_patch[] = {          32,         -32 };


  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x2_private a_ = simde_int32x2_to_private(simde_test_arm_neon_random_i32x2());
    simde_int32x2_private b_ = simde_int32x2_to_private(simde_test_arm_neon_random_i32x2());

    for (size_t j = 0 ; j < (sizeof(b_.values) / sizeof(b_.values[0])) ; j++) {
      if (probability(PROBABILITY)) {
        while (simde_math_abs(b_.values[j]) > 32) {
          b_.values[j] >>= 1;
        }
      }
    }

    if ((size_t) i < (sizeof(a_patch) / sizeof(a_patch[0]))) {
      a_.values[0] = a_patch[i];
      b_.values[0] = b_patch[i];
    }

    simde_int32x2_t a = simde_int32x2_from_private(a_);
    simde_int32x2_t b = simde_int32x2_from_private(b_);

    simde_int32x2_t r = simde_vrshl_s32(a, b);

    simde_test_arm_neon_write_i32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vrshl_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int64_t a[1];
    int64_t b[1];
    int64_t r[1];
  } test_vec[] = {
    { { -INT64_C(                   1) },
      {  INT64_C(                  64) },
      {  INT64_C(                   0) } },
    { { -INT64_C(                   1) },
      { -INT64_C(                  64) },
      {  INT64_C(                   0) } },
    { { -INT64_C( 5783365166398861937) },
      { -INT64_C( 1682183429783586356) },
      { -INT64_C(                1284) } },
    { {  INT64_C( 1136283642200280026) },
      { -INT64_C(                  57) },
      {  INT64_C(                   8) } },
    { {  INT64_C( 3453319167247895989) },
      {  INT64_C(                  53) },
      { -INT64_C( 5287225962532962304) } },
    { { -INT64_C( 3754790191149012930) },
      { -INT64_C(                  39) },
      { -INT64_C(             6829924) } },
    { {  INT64_C( 4367597038114582190) },
      { -INT64_C(                  56) },
      {  INT64_C(                  61) } },
    { { -INT64_C( 4313522761509692639) },
      { -INT64_C(                  43) },
      { -INT64_C(              490391) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x1_t a = simde_vld1_s64(test_vec[i].a);
    simde_int64x1_t b = simde_vld1_s64(test_vec[i].b);
    simde_int64x1_t r = simde_vrshl_s64(a, b);

    simde_test_arm_neon_assert_equal_i64x1(r, simde_vld1_s64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);

  int64_t a_patch[] = { -INT64_C(1), -INT64_C(1) };
  int64_t b_patch[] = {          64,         -64 };


  for (int i = 0 ; i < 8 ; i++) {
    simde_int64x1_private a_ = simde_int64x1_to_private(simde_test_arm_neon_random_i64x1());
    simde_int64x1_private b_ = simde_int64x1_to_private(simde_test_arm_neon_random_i64x1());

    for (size_t j = 0 ; j < (sizeof(b_.values) / sizeof(b_.values[0])) ; j++) {
      if (probability(PROBABILITY)) {
        while (simde_math_llabs(b_.values[j]) > 64) {
          b_.values[j] >>= 1;
        }
      }
    }

    if ((size_t) i < (sizeof(a_patch) / sizeof(a_patch[0]))) {
      a_.values[0] = a_patch[i];
      b_.values[0] = b_patch[i];
    }

    simde_int64x1_t a = simde_int64x1_from_private(a_);
    simde_int64x1_t b = simde_int64x1_from_private(b_);

    simde_int64x1_t r = simde_vrshl_s64(a, b);

    simde_test_arm_neon_write_i64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x1(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vrshl_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint8_t a[8];
    int8_t b[8];
    uint8_t r[8];
  } test_vec[] = {
    { {    UINT8_MAX, UINT8_C( 91), UINT8_C(231), UINT8_C(221), UINT8_C( 49), UINT8_C(217), UINT8_C(178), UINT8_C(160) },
      {  INT8_C(   8), -INT8_C( 123), -INT8_C(  39),  INT8_C(   6), -INT8_C(   5), -INT8_C(   8), -INT8_C(   7),  INT8_C(   6) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C( 64), UINT8_C(  2), UINT8_C(  1), UINT8_C(  1), UINT8_C(  0) } },
    { { UINT8_C(128), UINT8_C( 86), UINT8_C( 67), UINT8_C( 16), UINT8_C(186), UINT8_C(233), UINT8_C(204), UINT8_C( 62) },
      { -INT8_C(   8), -INT8_C(   5),  INT8_C(  28),  INT8_C(   7), -INT8_C(   8), -INT8_C(   7),  INT8_C(  22), -INT8_C(  82) },
      { UINT8_C(  1), UINT8_C(  3), UINT8_C(  0), UINT8_C(  0), UINT8_C(  1), UINT8_C(  2), UINT8_C(  0), UINT8_C(  0) } },
    { {    UINT8_MAX, UINT8_C(141), UINT8_C( 43), UINT8_C(127), UINT8_C( 75), UINT8_C(120), UINT8_C( 48), UINT8_C(178) },
      { -INT8_C(   9),  INT8_C(   7), -INT8_C(  62), -INT8_C(   8),  INT8_C(   5), -INT8_C(   8), -INT8_C(   8), -INT8_C(   6) },
      { UINT8_C(  0), UINT8_C(128), UINT8_C(  0), UINT8_C(  0), UINT8_C( 96), UINT8_C(  0), UINT8_C(  0), UINT8_C(  3) } },
    { { UINT8_C( 28), UINT8_C(141), UINT8_C( 24), UINT8_C(204), UINT8_C( 54), UINT8_C( 93), UINT8_C(123), UINT8_C(187) },
      { -INT8_C(   6), -INT8_C(  89),  INT8_C(   7),  INT8_C(   6),  INT8_C(   7),  INT8_C(   6), -INT8_C(   6), -INT8_C(   5) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C( 64), UINT8_C(  2), UINT8_C(  6) } },
    { { UINT8_C( 30), UINT8_C(244), UINT8_C( 74), UINT8_C(207), UINT8_C( 33), UINT8_C(200), UINT8_C(212), UINT8_C( 62) },
      {  INT8_C(   5), -INT8_C(   5),  INT8_C(   5), -INT8_C(   8),  INT8_C(  73), -INT8_C(   8),  INT8_C(   8),  INT8_C(  51) },
      { UINT8_C(192), UINT8_C(  8), UINT8_C( 64), UINT8_C(  1), UINT8_C(  0), UINT8_C(  1), UINT8_C(  0), UINT8_C(  0) } },
    { { UINT8_C(251), UINT8_C(173), UINT8_C(  4), UINT8_C( 52), UINT8_C(233), UINT8_C(224), UINT8_C(175), UINT8_C(  7) },
      { -INT8_C(   6), -INT8_C(   7), -INT8_C(   6), -INT8_C(   5), -INT8_C(   8), -INT8_C(   6),  INT8_C(  52),  INT8_C(  22) },
      { UINT8_C(  4), UINT8_C(  1), UINT8_C(  0), UINT8_C(  2), UINT8_C(  1), UINT8_C(  4), UINT8_C(  0), UINT8_C(  0) } },
    { { UINT8_C(104), UINT8_C(124), UINT8_C( 59), UINT8_C( 83), UINT8_C(205), UINT8_C(116), UINT8_C( 28), UINT8_C(201) },
      {  INT8_C(   8),  INT8_C(   8), -INT8_C(   3),  INT8_C(   5),  INT8_C(   0), -INT8_C(   6),  INT8_C(   8), -INT8_C(   6) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  7), UINT8_C( 96), UINT8_C(205), UINT8_C(  2), UINT8_C(  0), UINT8_C(  3) } },
    { { UINT8_C( 61), UINT8_C( 31), UINT8_C(  6), UINT8_C(  0), UINT8_C(  6), UINT8_C( 25), UINT8_C(240), UINT8_C(110) },
      { -INT8_C(   7),  INT8_C(   5), -INT8_C(   8),  INT8_C(   6), -INT8_C(  96), -INT8_C(  35),  INT8_C(  43), -INT8_C(   8) },
      { UINT8_C(  0), UINT8_C(224), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x8_t a = simde_vld1_u8(test_vec[i].a);
    simde_int8x8_t b = simde_vld1_s8(test_vec[i].b);
    simde_uint8x8_t r = simde_vrshl_u8(a, b);

    simde_test_arm_neon_assert_equal_u8x8(r, simde_vld1_u8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);

  uint8_t a_patch[] = { UINT8_MAX, UINT8_C(1) << (8 - 1), UINT8_MAX };
  int8_t  b_patch[] = {         8,                    -8,    -8 - 1 };

  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8x8_private a_ = simde_uint8x8_to_private(simde_test_arm_neon_random_u8x8());
    simde_int8x8_private b_ = simde_int8x8_to_private(simde_test_arm_neon_random_i8x8());

    for (size_t j = 0 ; j < (sizeof(b_.values) / sizeof(b_.values[0])) ; j++) {
      if (probability(PROBABILITY)) {
        while (simde_math_abs(b_.values[j]) > 8) {
          b_.values[j] >>= 1;
        }
      }
    }

    if ((size_t) i < (sizeof(a_patch) / sizeof(a_patch[0]))) {
      a_.values[0] = a_patch[i];
      b_.values[0] = b_patch[i];
    }

    simde_uint8x8_t a = simde_uint8x8_from_private(a_);
    simde_int8x8_t b = simde_int8x8_from_private(b_);

    simde_uint8x8_t r = simde_vrshl_u8(a, b);

    simde_test_arm_neon_write_u8x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vrshl_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint16_t a[4];
    int16_t b[4];
    uint16_t r[4];
  } test_vec[] = {
    { {      UINT16_MAX, UINT16_C(44116), UINT16_C(39019), UINT16_C(40834) },
      {  INT16_C(    16), -INT16_C(     9), -INT16_C(     9), -INT16_C(    16) },
      { UINT16_C(    0), UINT16_C(   86), UINT16_C(   76), UINT16_C(    1) } },
    { { UINT16_C(32768), UINT16_C(25689), UINT16_C(49174), UINT16_C(56283) },
      { -INT16_C(    16), -INT16_C(    13), -INT16_C(     9), -INT16_C(    16) },
      { UINT16_C(    1), UINT16_C(    3), UINT16_C(   96), UINT16_C(    1) } },
    { {      UINT16_MAX, UINT16_C(61016), UINT16_C(54701), UINT16_C(28590) },
      { -INT16_C(    17), -INT16_C(    14), -INT16_C(    12), -INT16_C(  5560) },
      { UINT16_C(    0), UINT16_C(    4), UINT16_C(   13), UINT16_C(    0) } },
    { { UINT16_C(12257), UINT16_C(64032), UINT16_C(39150), UINT16_C(17534) },
      { -INT16_C(    12),  INT16_C(     9),  INT16_C(    13),  INT16_C(    16) },
      { UINT16_C(    3), UINT16_C(16384), UINT16_C(49152), UINT16_C(    0) } },
    { { UINT16_C(10277), UINT16_C(63613), UINT16_C(50682), UINT16_C(36066) },
      { -INT16_C(    12), -INT16_C(    14),  INT16_C(    13), -INT16_C(    15) },
      { UINT16_C(    3), UINT16_C(    4), UINT16_C(16384), UINT16_C(    1) } },
    { { UINT16_C(59108), UINT16_C(30269), UINT16_C(15643), UINT16_C( 9910) },
      {  INT16_C(    12),  INT16_C(     8),  INT16_C(    14), -INT16_C(    15) },
      { UINT16_C(16384), UINT16_C(15616), UINT16_C(49152), UINT16_C(    0) } },
    { { UINT16_C(62868), UINT16_C(27572), UINT16_C(31221), UINT16_C(36400) },
      {  INT16_C(    14), -INT16_C( 24647), -INT16_C(    10),  INT16_C(    14) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(   30), UINT16_C(    0) } },
    { { UINT16_C( 8242), UINT16_C(49201), UINT16_C(15195), UINT16_C(23624) },
      {  INT16_C(    11), -INT16_C( 17338), -INT16_C(    10),  INT16_C( 18215) },
      { UINT16_C(36864), UINT16_C(    0), UINT16_C(   15), UINT16_C(    0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4_t a = simde_vld1_u16(test_vec[i].a);
    simde_int16x4_t b = simde_vld1_s16(test_vec[i].b);
    simde_uint16x4_t r = simde_vrshl_u16(a, b);
    simde_test_arm_neon_assert_equal_u16x4(r, simde_vld1_u16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);

  uint16_t a_patch[] = { UINT16_MAX, UINT16_C(1) << (16 - 1), UINT16_MAX };
  int16_t  b_patch[] = {         16,                     -16,    -16 - 1 };

  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x4_private a_ = simde_uint16x4_to_private(simde_test_arm_neon_random_u16x4());
    simde_int16x4_private b_ = simde_int16x4_to_private(simde_test_arm_neon_random_i16x4());

    for (size_t j = 0 ; j < (sizeof(b_.values) / sizeof(b_.values[0])) ; j++) {
      if (probability(PROBABILITY)) {
        while (simde_math_abs(b_.values[j]) > 16) {
          b_.values[j] >>= 1;
        }
      }
    }

    if ((size_t) i < (sizeof(a_patch) / sizeof(a_patch[0]))) {
      a_.values[0] = a_patch[i];
      b_.values[0] = b_patch[i];
    }

    simde_uint16x4_t a = simde_uint16x4_from_private(a_);
    simde_int16x4_t b = simde_int16x4_from_private(b_);

    simde_uint16x4_t r = simde_vrshl_u16(a, b);

    simde_test_arm_neon_write_u16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vrshl_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint32_t a[2];
    int32_t b[2];
    uint32_t r[2];
  } test_vec[] = {
    { {           UINT32_MAX, UINT32_C(4251222520) },
      {  INT32_C(          32),  INT32_C(          19) },
      { UINT32_C(         0), UINT32_C( 264241152) } },
    { { UINT32_C(2147483648), UINT32_C(1560478732) },
      { -INT32_C(          32), -INT32_C(   947062820) },
      { UINT32_C(         1), UINT32_C(         0) } },
    { {           UINT32_MAX, UINT32_C(2957451979) },
      { -INT32_C(          33),  INT32_C(  1240703795) },
      { UINT32_C(         0), UINT32_C(         0) } },
    { { UINT32_C(2136813645), UINT32_C(3441609201) },
      {  INT32_C(          25), -INT32_C(          20) },
      { UINT32_C(2583691264), UINT32_C(      3282) } },
    { { UINT32_C(  49107157), UINT32_C( 877904641) },
      { -INT32_C(          28), -INT32_C(          24) },
      { UINT32_C(         0), UINT32_C(        52) } },
    { { UINT32_C( 763522156), UINT32_C(1284773402) },
      { -INT32_C(    33618445),  INT32_C(          23) },
      { UINT32_C(     93203), UINT32_C( 218103808) } },
    { { UINT32_C(1501702642), UINT32_C(3052142703) },
      {  INT32_C(   358068427), -INT32_C(          26) },
      { UINT32_C(         0), UINT32_C(        45) } },
    { { UINT32_C(4041704701), UINT32_C(3421365897) },
      { -INT32_C(          28),  INT32_C(          25) },
      { UINT32_C(        15), UINT32_C( 301989888) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2_t a = simde_vld1_u32(test_vec[i].a);
    simde_int32x2_t b = simde_vld1_s32(test_vec[i].b);
    simde_uint32x2_t r = simde_vrshl_u32(a, b);
    simde_test_arm_neon_assert_equal_u32x2(r, simde_vld1_u32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);

  uint32_t a_patch[] = { UINT32_MAX, UINT32_C(1) << (32 - 1), UINT32_MAX };
  int32_t  b_patch[] = {         32,                     -32,    -32 - 1 };

  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x2_private a_ = simde_uint32x2_to_private(simde_test_arm_neon_random_u32x2());
    simde_int32x2_private b_ = simde_int32x2_to_private(simde_test_arm_neon_random_i32x2());

    for (size_t j = 0 ; j < (sizeof(b_.values) / sizeof(b_.values[0])) ; j++) {
      if (probability(PROBABILITY)) {
        while (simde_math_abs(b_.values[j]) > 32) {
          b_.values[j] >>= 1;
        }
      }
    }

    if ((size_t) i < (sizeof(a_patch) / sizeof(a_patch[0]))) {
      a_.values[0] = a_patch[i];
      b_.values[0] = b_patch[i];
    }

    simde_uint32x2_t a = simde_uint32x2_from_private(a_);
    simde_int32x2_t b = simde_int32x2_from_private(b_);

    simde_uint32x2_t r = simde_vrshl_u32(a, b);

    simde_test_arm_neon_write_u32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vrshl_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint64_t a[1];
    int64_t b[1];
    uint64_t r[1];
  } test_vec[] = {
    { {                    UINT64_MAX },
      {  INT64_C(                  64) },
      { UINT64_C(                   0) } },
    { { UINT64_C( 9223372036854775808) },
      { -INT64_C(                  64) },
      { UINT64_C(                   1) } },
    { {                    UINT64_MAX },
      { -INT64_C(                  65) },
      { UINT64_C(                   0) } },
    { { UINT64_C(10532064071281456190) },
      { -INT64_C(                  62) },
      { UINT64_C(                   2) } },
    { { UINT64_C(  199871928094595380) },
      { -INT64_C(                  34) },
      { UINT64_C(            11634077) } },
    { { UINT64_C( 4091501470598780608) },
      {  INT64_C(                  61) },
      { UINT64_C(                   0) } },
    { { UINT64_C(17991294013086143349) },
      {  INT64_C(                  53) },
      { UINT64_C( 7971371340445777920) } },
    { { UINT64_C(11884907251678901604) },
      {  INT64_C(                  38) },
      { UINT64_C( 3620147532010618880) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x1_t a = simde_vld1_u64(test_vec[i].a);
    simde_int64x1_t b = simde_vld1_s64(test_vec[i].b);
    simde_uint64x1_t r = simde_vrshl_u64(a, b);
    simde_test_arm_neon_assert_equal_u64x1(r, simde_vld1_u64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);

  uint64_t a_patch[] = { UINT64_MAX, UINT64_C(1) << (64 - 1), UINT64_MAX };
  int64_t  b_patch[] = {         64,                     -64,    -64 - 1 };

  for (int i = 0 ; i < 8 ; i++) {
    simde_uint64x1_private a_ = simde_uint64x1_to_private(simde_test_arm_neon_random_u64x1());
    simde_int64x1_private b_ = simde_int64x1_to_private(simde_test_arm_neon_random_i64x1());

    for (size_t j = 0 ; j < (sizeof(b_.values) / sizeof(b_.values[0])) ; j++) {
      if (probability(PROBABILITY)) {
        while (simde_math_llabs(b_.values[j]) > 64) {
          b_.values[j] >>= 1;
        }
      }
    }

    if ((size_t) i < (sizeof(a_patch) / sizeof(a_patch[0]))) {
      a_.values[0] = a_patch[i];
      b_.values[0] = b_patch[i];
    }

    simde_uint64x1_t a = simde_uint64x1_from_private(a_);
    simde_int64x1_t b = simde_int64x1_from_private(b_);

    simde_uint64x1_t r = simde_vrshl_u64(a, b);

    simde_test_arm_neon_write_u64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x1(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vrshlq_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int8_t a[16];
    int8_t b[16];
    int8_t r[16];
  } test_vec[] = {
    { { -INT8_C(   1),  INT8_C(  67), -INT8_C(  65), -INT8_C(  26), -INT8_C(  36), -INT8_C(  38), -INT8_C(  38),  INT8_C(   6),
        -INT8_C(  85),  INT8_C(  72),  INT8_C(  19), -INT8_C( 102),  INT8_C(  13), -INT8_C( 105), -INT8_C(  35), -INT8_C(  22) },
      {  INT8_C(   8), -INT8_C( 127), -INT8_C(   7),  INT8_C(  51),  INT8_C(   5), -INT8_C(   6), -INT8_C(   6),  INT8_C(   6),
         INT8_C(  79), -INT8_C(   8),  INT8_C(   7), -INT8_C(   6), -INT8_C(   7), -INT8_C(   5),  INT8_C(   5),  INT8_C(   8) },
      {  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),      INT8_MIN, -INT8_C(   1), -INT8_C(   1),      INT8_MIN,
         INT8_C(   0),  INT8_C(   0),      INT8_MIN, -INT8_C(   2),  INT8_C(   0), -INT8_C(   3), -INT8_C(  96),  INT8_C(   0) } },
    { { -INT8_C(   1), -INT8_C(  99),  INT8_C(  23), -INT8_C(  95), -INT8_C( 121), -INT8_C(  57), -INT8_C(  71), -INT8_C(  42),
         INT8_C(  73),  INT8_C(  42), -INT8_C(  63), -INT8_C(  30),  INT8_C(   6), -INT8_C(  58), -INT8_C(  22),  INT8_C(  37) },
      { -INT8_C(   8), -INT8_C(   5),  INT8_C(   8),  INT8_C(   5), -INT8_C(   6),  INT8_C(   8),  INT8_C( 115), -INT8_C(   5),
         INT8_C(   6),  INT8_C(   5), -INT8_C(   6), -INT8_C(  28),  INT8_C(   6), -INT8_C(   5), -INT8_C(   7),  INT8_C(   5) },
      {  INT8_C(   0), -INT8_C(   3),  INT8_C(   0),  INT8_C(  32), -INT8_C(   2),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
         INT8_C(  64),  INT8_C(  64), -INT8_C(   1),  INT8_C(   0),      INT8_MIN, -INT8_C(   2),  INT8_C(   0), -INT8_C(  96) } },
    { { -INT8_C( 108),  INT8_C(  45),  INT8_C(  16),  INT8_C(  53),  INT8_C(  79), -INT8_C( 125), -INT8_C(  25), -INT8_C( 121),
        -INT8_C(  37), -INT8_C(  73),  INT8_C( 107), -INT8_C(  11), -INT8_C( 111),  INT8_C(  51),  INT8_C(  83),  INT8_C(   7) },
      {  INT8_C(   4),  INT8_C(   5),  INT8_C(   5), -INT8_C(   5),  INT8_C(   4), -INT8_C(   5), -INT8_C(   6), -INT8_C(  22),
         INT8_C(   6),  INT8_C(   7), -INT8_C(  46), -INT8_C(   7),  INT8_C(   6), -INT8_C(  34), -INT8_C(   5), -INT8_C(   7) },
      {  INT8_C(  64), -INT8_C(  96),  INT8_C(   0),  INT8_C(   2), -INT8_C(  16), -INT8_C(   4),  INT8_C(   0),  INT8_C(   0),
        -INT8_C(  64),      INT8_MIN,  INT8_C(   0),  INT8_C(   0),  INT8_C(  64),  INT8_C(   0),  INT8_C(   3),  INT8_C(   0) } },
    { { -INT8_C(  71),  INT8_C(  58),  INT8_C(  75), -INT8_C(  62),  INT8_C(  19), -INT8_C(  12), -INT8_C(  84), -INT8_C( 127),
         INT8_C( 110),  INT8_C( 126),  INT8_C(  75), -INT8_C(  93),  INT8_C(  93), -INT8_C(   5),  INT8_C( 109),  INT8_C( 104) },
      { -INT8_C(   5),  INT8_C(   6), -INT8_C(   8), -INT8_C(   2),  INT8_C(   5), -INT8_C(   6),  INT8_C(   7), -INT8_C(   5),
        -INT8_C(  14),  INT8_C(  50),  INT8_C(   7),  INT8_C( 114), -INT8_C(   7),  INT8_C(   5),  INT8_C(   5),  INT8_C(   5) },
      { -INT8_C(   2),      INT8_MIN,  INT8_C(   0), -INT8_C(  15),  INT8_C(  96),  INT8_C(   0),  INT8_C(   0), -INT8_C(   4),
         INT8_C(   0),  INT8_C(   0),      INT8_MIN,  INT8_C(   0),  INT8_C(   1),  INT8_C(  96), -INT8_C(  96),  INT8_C(   0) } },
    { {  INT8_C(  46), -INT8_C(  56),  INT8_C(  32),      INT8_MAX,  INT8_C( 110),  INT8_C(  62),  INT8_C( 109),  INT8_C(  96),
         INT8_C( 112), -INT8_C( 119), -INT8_C(  45),  INT8_C(   9), -INT8_C(  37), -INT8_C(  40),  INT8_C(  92),  INT8_C( 103) },
      {  INT8_C(  40),  INT8_C(   7),  INT8_C(   6),  INT8_C( 109),  INT8_C(   6),  INT8_C(  39),  INT8_C(   7),  INT8_C(   7),
        -INT8_C( 109),  INT8_C(   7),  INT8_C(   6), -INT8_C(   6),  INT8_C(   7),  INT8_C(  18),  INT8_C(  28),  INT8_C(   6) },
      {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),      INT8_MIN,  INT8_C(   0),      INT8_MIN,  INT8_C(   0),
         INT8_C(   0),      INT8_MIN, -INT8_C(  64),  INT8_C(   0),      INT8_MIN,  INT8_C(   0),  INT8_C(   0), -INT8_C(  64) } },
    { { -INT8_C(  63),  INT8_C(  38), -INT8_C(  22), -INT8_C(  14),  INT8_C(  77),  INT8_C(   9),  INT8_C(  99), -INT8_C(  31),
             INT8_MAX,  INT8_C( 113), -INT8_C(  37), -INT8_C(  73), -INT8_C( 125), -INT8_C(   8),  INT8_C(  30),  INT8_C(  94) },
      {  INT8_C(  53),  INT8_C(   5), -INT8_C(   6), -INT8_C(   5),  INT8_C(  89),  INT8_C(   5), -INT8_C(   7),  INT8_C(   6),
        -INT8_C(   7), -INT8_C(   8), -INT8_C(  17),  INT8_C(   8), -INT8_C(  32),  INT8_C(   7), -INT8_C(   7), -INT8_C(   6) },
      {  INT8_C(   0), -INT8_C(  64),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  32),  INT8_C(   1),  INT8_C(  64),
         INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   1) } },
    { { -INT8_C(  20), -INT8_C(  15),  INT8_C(  27),  INT8_C(  69),  INT8_C(  66), -INT8_C(  74),  INT8_C( 124),  INT8_C(  16),
         INT8_C(  70),  INT8_C( 107),  INT8_C(  50),  INT8_C(  38),  INT8_C( 121), -INT8_C(  47), -INT8_C(  57), -INT8_C(  82) },
      {  INT8_C(   5),  INT8_C(   5),  INT8_C(   6), -INT8_C(   5),  INT8_C(   5), -INT8_C(   7), -INT8_C(   2), -INT8_C(   5),
        -INT8_C(  47), -INT8_C(   8), -INT8_C(   6),  INT8_C(   8), -INT8_C(   6), -INT8_C(  17),  INT8_C( 115), -INT8_C( 101) },
      {      INT8_MIN,  INT8_C(  32), -INT8_C(  64),  INT8_C(   2),  INT8_C(  64), -INT8_C(   1),  INT8_C(  31),  INT8_C(   1),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   1),  INT8_C(   0),  INT8_C(   2),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0) } },
    { { -INT8_C(  45),  INT8_C(  31),  INT8_C( 124),  INT8_C(  36), -INT8_C(  78),  INT8_C( 122), -INT8_C(  34), -INT8_C( 125),
         INT8_C(  65), -INT8_C( 125), -INT8_C( 117), -INT8_C(  16),  INT8_C( 114), -INT8_C(   1), -INT8_C( 117),  INT8_C(  82) },
      { -INT8_C(   8),  INT8_C(   6),  INT8_C( 117), -INT8_C(  45), -INT8_C(   7), -INT8_C(   6),  INT8_C(   5), -INT8_C(   8),
         INT8_C(   6),  INT8_C(   8), -INT8_C(   6),  INT8_C(   8), -INT8_C(   8), -INT8_C(   5), -INT8_C(   6),  INT8_C(   5) },
      {  INT8_C(   0), -INT8_C(  64),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   2), -INT8_C(  64),  INT8_C(   0),
         INT8_C(  64),  INT8_C(   0), -INT8_C(   2),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   2),  INT8_C(  64) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16_t a = simde_vld1q_s8(test_vec[i].a);
    simde_int8x16_t b = simde_vld1q_s8(test_vec[i].b);
    simde_int8x16_t r = simde_vrshlq_s8(a, b);

    simde_test_arm_neon_assert_equal_i8x16(r, simde_vld1q_s8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);

  int8_t a_patch[] = { -INT8_C(1), -INT8_C(1) };
  int8_t b_patch[] = {          8,         -8 };


  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x16_private a_ = simde_int8x16_to_private(simde_test_arm_neon_random_i8x16());
    simde_int8x16_private b_ = simde_int8x16_to_private(simde_test_arm_neon_random_i8x16());

    for (size_t j = 0 ; j < (sizeof(b_.values) / sizeof(b_.values[0])) ; j++) {
      if (probability(PROBABILITY)) {
        while (simde_math_abs(b_.values[j]) > 8) {
          b_.values[j] >>= 1;
        }
      }
    }

    if ((size_t) i < (sizeof(a_patch) / sizeof(a_patch[0]))) {
      a_.values[0] = a_patch[i];
      b_.values[0] = b_patch[i];
    }

    simde_int8x16_t a = simde_int8x16_from_private(a_);
    simde_int8x16_t b = simde_int8x16_from_private(b_);

    simde_int8x16_t r = simde_vrshlq_s8(a, b);

    simde_test_arm_neon_write_i8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vrshlq_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int16_t a[8];
    int16_t b[8];
    int16_t r[8];
  } test_vec[] = {
    { { -INT16_C(     1), -INT16_C( 24733), -INT16_C( 31663), -INT16_C( 14535), -INT16_C( 12245), -INT16_C( 20602), -INT16_C( 20992), -INT16_C( 32646) },
      {  INT16_C(    16), -INT16_C(  5416),  INT16_C(    15), -INT16_C(    16), -INT16_C(    13),  INT16_C(    13),  INT16_C(    15), -INT16_C(    15) },
      {  INT16_C(     0),  INT16_C(     0),       INT16_MIN,  INT16_C(     0), -INT16_C(     1), -INT16_C( 16384),  INT16_C(     0), -INT16_C(     1) } },
    { { -INT16_C(     1),  INT16_C( 28375),  INT16_C( 21093),  INT16_C( 11758), -INT16_C( 14819),  INT16_C( 23319), -INT16_C(  3519),  INT16_C(  5852) },
      { -INT16_C(    16), -INT16_C(    14), -INT16_C(    13), -INT16_C(    14), -INT16_C(  3822),  INT16_C(  4095),  INT16_C(    12), -INT16_C(    12) },
      {  INT16_C(     0),  INT16_C(     2),  INT16_C(     3),  INT16_C(     1),  INT16_C(     0),  INT16_C( 11660),  INT16_C(  4096),  INT16_C(     1) } },
    { { -INT16_C( 28383),  INT16_C( 25305), -INT16_C( 18813),  INT16_C(  5240), -INT16_C(  1004), -INT16_C( 28452),  INT16_C( 27030), -INT16_C( 22491) },
      {  INT16_C(     9), -INT16_C(    11), -INT16_C(     9),  INT16_C(    15),  INT16_C(    10),  INT16_C(    11),  INT16_C(    11), -INT16_C(    13) },
      {  INT16_C( 16896),  INT16_C(    12), -INT16_C(    37),  INT16_C(     0),  INT16_C( 20480), -INT16_C(  8192), -INT16_C( 20480), -INT16_C(     3) } },
    { {  INT16_C(  2726),  INT16_C( 15377),  INT16_C( 14195), -INT16_C( 12827), -INT16_C( 25253), -INT16_C( 20297), -INT16_C( 24692), -INT16_C( 29715) },
      {  INT16_C(    15), -INT16_C(    12), -INT16_C( 14211),  INT16_C(     9), -INT16_C(    12), -INT16_C(    10),  INT16_C(    11), -INT16_C(    15) },
      {  INT16_C(     0),  INT16_C(     4),  INT16_C(     0), -INT16_C( 13824), -INT16_C(     6), -INT16_C(    20),  INT16_C( 24576), -INT16_C(     1) } },
    { {  INT16_C( 23984),  INT16_C( 15553), -INT16_C( 20484), -INT16_C(  4153), -INT16_C( 19929), -INT16_C( 23409), -INT16_C(   134), -INT16_C(  1609) },
      { -INT16_C(    14), -INT16_C(  5147),  INT16_C(    10), -INT16_C(    12),  INT16_C(    10), -INT16_C( 31106),  INT16_C(     9), -INT16_C(    13) },
      {  INT16_C(     1),  INT16_C(     0), -INT16_C(  4096), -INT16_C(     1), -INT16_C( 25600),  INT16_C(     0), -INT16_C(  3072),  INT16_C(     0) } },
    { { -INT16_C(   637), -INT16_C(   558), -INT16_C( 29956), -INT16_C( 25354), -INT16_C(  9361), -INT16_C( 20601),  INT16_C( 25389), -INT16_C(   427) },
      { -INT16_C( 11154), -INT16_C(    15),  INT16_C(    13),  INT16_C( 31321),  INT16_C( 25459),  INT16_C( 31737),  INT16_C(    12), -INT16_C( 18263) },
      {  INT16_C(     0),  INT16_C(     0),       INT16_MIN,  INT16_C(     0),  INT16_C(     0), -INT16_C(   161), -INT16_C( 12288),  INT16_C(     0) } },
    { { -INT16_C( 32121), -INT16_C( 19164),  INT16_C( 31462),  INT16_C( 21683),  INT16_C( 14158),  INT16_C( 18143),  INT16_C( 14418), -INT16_C( 14911) },
      { -INT16_C(     9), -INT16_C(    12), -INT16_C(  5600), -INT16_C(    16),  INT16_C( 15718),  INT16_C(    13), -INT16_C(  8215),  INT16_C(    14) },
      { -INT16_C(    63), -INT16_C(     5),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(  8192),  INT16_C(     0),  INT16_C( 16384) } },
    { {  INT16_C( 31504),  INT16_C( 25108), -INT16_C( 10829),  INT16_C( 20263),  INT16_C( 26767), -INT16_C( 20705), -INT16_C( 22702), -INT16_C( 18381) },
      {  INT16_C(    11), -INT16_C(    13),  INT16_C(    11),  INT16_C(    10),  INT16_C(    12), -INT16_C(    15),  INT16_C(    14),  INT16_C( 20055) },
      {       INT16_MIN,  INT16_C(     3), -INT16_C( 26624), -INT16_C( 25600), -INT16_C(  4096), -INT16_C(     1),       INT16_MIN,  INT16_C(     0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_int16x8_t b = simde_vld1q_s16(test_vec[i].b);
    simde_int16x8_t r = simde_vrshlq_s16(a, b);

    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);

  int16_t a_patch[] = { -INT16_C(1), -INT16_C(1) };
  int16_t b_patch[] = {          16,         -16 };


  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x8_private a_ = simde_int16x8_to_private(simde_test_arm_neon_random_i16x8());
    simde_int16x8_private b_ = simde_int16x8_to_private(simde_test_arm_neon_random_i16x8());

    for (size_t j = 0 ; j < (sizeof(b_.values) / sizeof(b_.values[0])) ; j++) {
      if (probability(PROBABILITY)) {
        while (simde_math_abs(b_.values[j]) > 16) {
          b_.values[j] >>= 1;
        }
      }
    }

    if ((size_t) i < (sizeof(a_patch) / sizeof(a_patch[0]))) {
      a_.values[0] = a_patch[i];
      b_.values[0] = b_patch[i];
    }

    simde_int16x8_t a = simde_int16x8_from_private(a_);
    simde_int16x8_t b = simde_int16x8_from_private(b_);

    simde_int16x8_t r = simde_vrshlq_s16(a, b);

    simde_test_arm_neon_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vrshlq_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int32_t a[4];
    int32_t b[4];
    int32_t r[4];
  } test_vec[] = {
    { { -INT32_C(           1),  INT32_C(   261209098),  INT32_C(   688353192), -INT32_C(  1311148258) },
      {  INT32_C(          32),  INT32_C(   794913842),  INT32_C(          18), -INT32_C(  1422236320) },
      {  INT32_C(           0),  INT32_C(           0), -INT32_C(  1096810496),  INT32_C(           0) } },
    { { -INT32_C(           1),  INT32_C(   796745233), -INT32_C(   924821802),  INT32_C(  1238788374) },
      { -INT32_C(          32),  INT32_C(  1787446282), -INT32_C(          24),  INT32_C(          24) },
      {  INT32_C(           0), -INT32_C(   176667648), -INT32_C(          55),  INT32_C(   369098752) } },
    { { -INT32_C(  1140379162), -INT32_C(  1652234361),  INT32_C(   652630864), -INT32_C(  1654235245) },
      {  INT32_C(  1292431523),  INT32_C(          26),  INT32_C(          21), -INT32_C(          23) },
      {  INT32_C(           0),  INT32_C(   469762048),  INT32_C(  1778384896), -INT32_C(         197) } },
    { {  INT32_C(   567415760),  INT32_C(    21477742), -INT32_C(  1147163368),  INT32_C(  1393141662) },
      {  INT32_C(          30), -INT32_C(          28), -INT32_C(          20), -INT32_C(  1377438756) },
      {  INT32_C(           0),  INT32_C(           0), -INT32_C(        1094),  INT32_C(           0) } },
    { { -INT32_C(  2005527184),  INT32_C(  1615074754), -INT32_C(  2118955588),  INT32_C(   797470603) },
      { -INT32_C(          19),  INT32_C(  1789273229),  INT32_C(          30), -INT32_C(  1282153149) },
      { -INT32_C(        3825),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { { -INT32_C(   618823649),  INT32_C(  1482477773),  INT32_C(   881386816),  INT32_C(   204163199) },
      { -INT32_C(  2072587923), -INT32_C(          24),  INT32_C(          27),  INT32_C(          23) },
      {  INT32_C(           0),  INT32_C(          88),  INT32_C(           0),  INT32_C(  1065353216) } },
    { {  INT32_C(  1446352406), -INT32_C(    91505285),  INT32_C(  1913042437), -INT32_C(   453542521) },
      {  INT32_C(          31),  INT32_C(          29),  INT32_C(          29),  INT32_C(          27) },
      {  INT32_C(           0),  INT32_C(  1610612736), -INT32_C(  1610612736),  INT32_C(   939524096) } },
    { {  INT32_C(  1269846085), -INT32_C(  1900169466),  INT32_C(  1047704628),  INT32_C(   498857806) },
      {  INT32_C(          27),  INT32_C(          16),  INT32_C(          30), -INT32_C(          25) },
      {  INT32_C(   671088640), -INT32_C(  1224343552),  INT32_C(           0),  INT32_C(          15) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int32x4_t b = simde_vld1q_s32(test_vec[i].b);
    simde_int32x4_t r = simde_vrshlq_s32(a, b);
    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);

  int32_t a_patch[] = { -INT32_C(1), -INT32_C(1) };
  int32_t b_patch[] = {          32,         -32 };


  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x4_private a_ = simde_int32x4_to_private(simde_test_arm_neon_random_i32x4());
    simde_int32x4_private b_ = simde_int32x4_to_private(simde_test_arm_neon_random_i32x4());

    for (size_t j = 0 ; j < (sizeof(b_.values) / sizeof(b_.values[0])) ; j++) {
      if (probability(PROBABILITY)) {
        while (simde_math_abs(b_.values[j]) > 32) {
          b_.values[j] >>= 1;
        }
      }
    }

    if ((size_t) i < (sizeof(a_patch) / sizeof(a_patch[0]))) {
      a_.values[0] = a_patch[i];
      b_.values[0] = b_patch[i];
    }

    simde_int32x4_t a = simde_int32x4_from_private(a_);
    simde_int32x4_t b = simde_int32x4_from_private(b_);

    simde_int32x4_t r = simde_vrshlq_s32(a, b);

    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vrshlq_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int64_t a[2];
    int64_t b[2];
    int64_t r[2];
  } test_vec[] = {
    { { -INT64_C(                   1),  INT64_C( 8313170098058778935) },
      {  INT64_C(                  64), -INT64_C(                  58) },
      {  INT64_C(                   0),  INT64_C(                  29) } },
    { { -INT64_C(                   1),  INT64_C( 7179860541365923026) },
      { -INT64_C(                  64),  INT64_C( 5674951681768987017) },
      {  INT64_C(                   0),  INT64_C(                   0) } },
    { { -INT64_C( 5284824899776078983),  INT64_C( 2324443633642883256) },
      {  INT64_C(                  59), -INT64_C( 3278735591420720609) },
      { -INT64_C( 4035225266123964416), -INT64_C( 5919449151413682176) } },
    { { -INT64_C( 2576212740381314098),  INT64_C( 6562733711055481552) },
      { -INT64_C(                  52),  INT64_C(                  41) },
      { -INT64_C(                 572), -INT64_C( 2101597729238024192) } },
    { {  INT64_C( 5416257340365700737), -INT64_C( 4269616889089575813) },
      {  INT64_C( 3370466030787258188), -INT64_C(                  58) },
      {  INT64_C(                   0), -INT64_C(                  15) } },
    { {  INT64_C( 6209211028984577356), -INT64_C( 7547495314914264550) },
      {  INT64_C(                  63), -INT64_C(                  60) },
      {  INT64_C(                   0), -INT64_C(                   7) } },
    { { -INT64_C( 9093408780739309977),  INT64_C( 5121628945022307474) },
      { -INT64_C(                  53), -INT64_C(                  37) },
      { -INT64_C(                1010),  INT64_C(            37264755) } },
    { {  INT64_C( 1082637037262742893),  INT64_C( 6751871869302762015) },
      {  INT64_C( 5088688905005675581),  INT64_C(                  45) },
      { -INT64_C( 6917529027641081856), -INT64_C( 3655832181890088960) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);
    simde_int64x2_t b = simde_vld1q_s64(test_vec[i].b);
    simde_int64x2_t r = simde_vrshlq_s64(a, b);
    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);

  int64_t a_patch[] = { -INT64_C(1), -INT64_C(1) };
  int64_t b_patch[] = {          64,         -64 };


  for (int i = 0 ; i < 8 ; i++) {
    simde_int64x2_private a_ = simde_int64x2_to_private(simde_test_arm_neon_random_i64x2());
    simde_int64x2_private b_ = simde_int64x2_to_private(simde_test_arm_neon_random_i64x2());

    for (size_t j = 0 ; j < (sizeof(b_.values) / sizeof(b_.values[0])) ; j++) {
      if (probability(PROBABILITY)) {
        while (simde_math_llabs(b_.values[j]) > 64) {
          b_.values[j] >>= 1;
        }
      }
    }

    if ((size_t) i < (sizeof(a_patch) / sizeof(a_patch[0]))) {
      a_.values[0] = a_patch[i];
      b_.values[0] = b_patch[i];
    }

    simde_int64x2_t a = simde_int64x2_from_private(a_);
    simde_int64x2_t b = simde_int64x2_from_private(b_);

    simde_int64x2_t r = simde_vrshlq_s64(a, b);

    simde_test_arm_neon_write_i64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vrshlq_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint8_t a[16];
    int8_t b[16];
    uint8_t r[16];
  } test_vec[] = {
    { {    UINT8_MAX, UINT8_C( 26), UINT8_C( 19), UINT8_C(248), UINT8_C(135), UINT8_C( 38), UINT8_C( 72), UINT8_C(139),
        UINT8_C(117), UINT8_C( 87), UINT8_C(157), UINT8_C(107), UINT8_C(117), UINT8_C( 60), UINT8_C(214), UINT8_C( 38) },
      {  INT8_C(   8), -INT8_C(  24), -INT8_C(   5), -INT8_C(   5),  INT8_C(  32),  INT8_C(  48),  INT8_C(  95), -INT8_C(   5),
         INT8_C(   6),  INT8_C(   7),  INT8_C(   4), -INT8_C(  95), -INT8_C(  53),  INT8_C(   7),  INT8_C(   6),  INT8_C(   5) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  1), UINT8_C(  8), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  4),
        UINT8_C( 64), UINT8_C(128), UINT8_C(208), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(128), UINT8_C(192) } },
    { { UINT8_C(128), UINT8_C(251), UINT8_C(187), UINT8_C(102), UINT8_C( 43), UINT8_C( 26), UINT8_C( 66), UINT8_C( 92),
        UINT8_C(138), UINT8_C( 75), UINT8_C(253), UINT8_C( 86), UINT8_C(135), UINT8_C(105), UINT8_C( 97), UINT8_C(222) },
      { -INT8_C(   8),  INT8_C(   6), -INT8_C(   5), -INT8_C(   8), -INT8_C(   5),  INT8_C(   4), -INT8_C(   6),  INT8_C(  84),
         INT8_C(  41),  INT8_C(   6),  INT8_C(   6),  INT8_C(   6), -INT8_C(   8), -INT8_C(   6),  INT8_C(   8), -INT8_C(   6) },
      { UINT8_C(  1), UINT8_C(192), UINT8_C(  6), UINT8_C(  0), UINT8_C(  1), UINT8_C(160), UINT8_C(  1), UINT8_C(  0),
        UINT8_C(  0), UINT8_C(192), UINT8_C( 64), UINT8_C(128), UINT8_C(  1), UINT8_C(  2), UINT8_C(  0), UINT8_C(  3) } },
    { {    UINT8_MAX, UINT8_C(233), UINT8_C( 14), UINT8_C(114), UINT8_C( 13), UINT8_C(185), UINT8_C(198), UINT8_C( 54),
        UINT8_C(234), UINT8_C( 51), UINT8_C(161), UINT8_C(121), UINT8_C(223), UINT8_C(232), UINT8_C( 78), UINT8_C(135) },
      { -INT8_C(   9), -INT8_C(   8),  INT8_C(   5),  INT8_C(   5),  INT8_C(   6), -INT8_C(   8), -INT8_C(   6), -INT8_C(   7),
        -INT8_C(   5), -INT8_C(   6),  INT8_C(  30),  INT8_C(   4),  INT8_C(   4),  INT8_C(   4), -INT8_C(   7), -INT8_C(  59) },
      { UINT8_C(  0), UINT8_C(  1), UINT8_C(192), UINT8_C( 64), UINT8_C( 64), UINT8_C(  1), UINT8_C(  3), UINT8_C(  0),
        UINT8_C(  7), UINT8_C(  1), UINT8_C(  0), UINT8_C(144), UINT8_C(240), UINT8_C(128), UINT8_C(  1), UINT8_C(  0) } },
    { { UINT8_C(209), UINT8_C(242), UINT8_C(240), UINT8_C(215), UINT8_C(125), UINT8_C(155), UINT8_C(166), UINT8_C( 52),
        UINT8_C( 66), UINT8_C(196), UINT8_C(130), UINT8_C( 70), UINT8_C( 15), UINT8_C( 80), UINT8_C( 11), UINT8_C( 68) },
      {  INT8_C(  44),  INT8_C(   8), -INT8_C(   8), -INT8_C(  63),  INT8_C(   8), -INT8_C(   3),  INT8_C(   8),  INT8_C(   7),
         INT8_C(  23),  INT8_C(  57), -INT8_C(   8),  INT8_C(   6), -INT8_C(   8),  INT8_C(   6),  INT8_C(   3),  INT8_C(   5) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  1), UINT8_C(  0), UINT8_C(  0), UINT8_C( 19), UINT8_C(  0), UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  1), UINT8_C(128), UINT8_C(  0), UINT8_C(  0), UINT8_C( 88), UINT8_C(128) } },
    { { UINT8_C(101), UINT8_C(108), UINT8_C(124), UINT8_C(165), UINT8_C(106), UINT8_C(188), UINT8_C( 22), UINT8_C(129),
        UINT8_C(246), UINT8_C(151), UINT8_C(153), UINT8_C(119), UINT8_C(176), UINT8_C(157), UINT8_C(201), UINT8_C(187) },
      { -INT8_C(   7), -INT8_C(   7),  INT8_C(   8),  INT8_C(   7), -INT8_C(   8), -INT8_C(   1), -INT8_C(   5),  INT8_C(   5),
         INT8_C(  62),  INT8_C(   6), -INT8_C(   8), -INT8_C(   7),  INT8_C(   5), -INT8_C(   5), -INT8_C(   8), -INT8_C(   8) },
      { UINT8_C(  1), UINT8_C(  1), UINT8_C(  0), UINT8_C(128), UINT8_C(  0), UINT8_C( 94), UINT8_C(  1), UINT8_C( 32),
        UINT8_C(  0), UINT8_C(192), UINT8_C(  1), UINT8_C(  1), UINT8_C(  0), UINT8_C(  5), UINT8_C(  1), UINT8_C(  1) } },
    { { UINT8_C(233), UINT8_C(142), UINT8_C( 29), UINT8_C(171), UINT8_C(142), UINT8_C( 12), UINT8_C(  1), UINT8_C(204),
        UINT8_C( 18), UINT8_C(249), UINT8_C(154), UINT8_C( 58), UINT8_C(217), UINT8_C( 34), UINT8_C(199), UINT8_C( 37) },
      {  INT8_C(   4), -INT8_C(   6), -INT8_C(   5), -INT8_C(   6),  INT8_C(   8),  INT8_C(   4), -INT8_C(   7),  INT8_C(  35),
        -INT8_C(  30), -INT8_C(   7), -INT8_C(   5),  INT8_C(  80), -INT8_C(   8), -INT8_C(   1),  INT8_C(   4), -INT8_C(   6) },
      { UINT8_C(144), UINT8_C(  2), UINT8_C(  1), UINT8_C(  3), UINT8_C(  0), UINT8_C(192), UINT8_C(  0), UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  2), UINT8_C(  5), UINT8_C(  0), UINT8_C(  1), UINT8_C( 17), UINT8_C(112), UINT8_C(  1) } },
    { { UINT8_C(134), UINT8_C( 44), UINT8_C(180), UINT8_C(201), UINT8_C( 62), UINT8_C( 83), UINT8_C(236), UINT8_C( 33),
        UINT8_C( 32), UINT8_C(160), UINT8_C(113), UINT8_C(228), UINT8_C(160), UINT8_C(191), UINT8_C(145), UINT8_C( 46) },
      {  INT8_C(   5), -INT8_C(   6),  INT8_C(  74), -INT8_C(   6),  INT8_C(   8),  INT8_C(   6),  INT8_C(   5), -INT8_C(   7),
        -INT8_C(   5), -INT8_C(  16), -INT8_C(   8),  INT8_C(  90),  INT8_C(   7),  INT8_C(   5),  INT8_C(  38),  INT8_C(   2) },
      { UINT8_C(192), UINT8_C(  1), UINT8_C(  0), UINT8_C(  3), UINT8_C(  0), UINT8_C(192), UINT8_C(128), UINT8_C(  0),
        UINT8_C(  1), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(224), UINT8_C(  0), UINT8_C(184) } },
    { { UINT8_C(173), UINT8_C(112), UINT8_C(157), UINT8_C(241), UINT8_C(162), UINT8_C(201), UINT8_C(137), UINT8_C( 87),
        UINT8_C(185), UINT8_C( 78), UINT8_C(177), UINT8_C( 53), UINT8_C(100), UINT8_C(215), UINT8_C( 55), UINT8_C(166) },
      { -INT8_C(   5),  INT8_C(   2),  INT8_C(   4), -INT8_C(   5), -INT8_C(  71), -INT8_C(   7),  INT8_C(   5),  INT8_C(  17),
        -INT8_C(   5),  INT8_C(   5),  INT8_C(   4), -INT8_C(   6),  INT8_C(   7),  INT8_C(   5), -INT8_C(   6), -INT8_C(   7) },
      { UINT8_C(  5), UINT8_C(192), UINT8_C(208), UINT8_C(  8), UINT8_C(  0), UINT8_C(  2), UINT8_C( 32), UINT8_C(  0),
        UINT8_C(  6), UINT8_C(192), UINT8_C( 16), UINT8_C(  1), UINT8_C(  0), UINT8_C(224), UINT8_C(  1), UINT8_C(  1) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x16_t a = simde_vld1q_u8(test_vec[i].a);
    simde_int8x16_t b = simde_vld1q_s8(test_vec[i].b);
    simde_uint8x16_t r = simde_vrshlq_u8(a, b);

    simde_test_arm_neon_assert_equal_u8x16(r, simde_vld1q_u8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);

  uint8_t a_patch[] = { UINT8_MAX, UINT8_C(1) << (8 - 1), UINT8_MAX };
  int8_t  b_patch[] = {         8,                    -8,    -8 - 1 };

  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8x16_private a_ = simde_uint8x16_to_private(simde_test_arm_neon_random_u8x16());
    simde_int8x16_private b_ = simde_int8x16_to_private(simde_test_arm_neon_random_i8x16());

    for (size_t j = 0 ; j < (sizeof(b_.values) / sizeof(b_.values[0])) ; j++) {
      if (probability(PROBABILITY)) {
        while (simde_math_abs(b_.values[j]) > 8) {
          b_.values[j] >>= 1;
        }
      }
    }

    if ((size_t) i < (sizeof(a_patch) / sizeof(a_patch[0]))) {
      a_.values[0] = a_patch[i];
      b_.values[0] = b_patch[i];
    }

    simde_uint8x16_t a = simde_uint8x16_from_private(a_);
    simde_int8x16_t b = simde_int8x16_from_private(b_);

    simde_uint8x16_t r = simde_vrshlq_u8(a, b);

    simde_test_arm_neon_write_u8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vrshlq_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint16_t a[8];
    int16_t b[8];
    uint16_t r[8];
  } test_vec[] = {
    { {      UINT16_MAX, UINT16_C(58570), UINT16_C(15575), UINT16_C( 8935), UINT16_C( 7529), UINT16_C(51329), UINT16_C(30589), UINT16_C(20900) },
      {  INT16_C(    16),  INT16_C(    13),  INT16_C(    14),  INT16_C(    14),  INT16_C(    11),  INT16_C(    12), -INT16_C(  6158),  INT16_C(    14) },
      { UINT16_C(    0), UINT16_C(16384), UINT16_C(49152), UINT16_C(49152), UINT16_C(18432), UINT16_C( 4096), UINT16_C(    2), UINT16_C(    0) } },
    { { UINT16_C(32768), UINT16_C(40539), UINT16_C(  126), UINT16_C(43759), UINT16_C(13621), UINT16_C(32734), UINT16_C(33340), UINT16_C(61827) },
      { -INT16_C(    16),  INT16_C(    14),  INT16_C( 31151),  INT16_C( 15277), -INT16_C(    14), -INT16_C( 28257),  INT16_C(     9), -INT16_C(  4060) },
      { UINT16_C(    1), UINT16_C(49152), UINT16_C(    0), UINT16_C(    0), UINT16_C(    1), UINT16_C(    0), UINT16_C(30720), UINT16_C(    0) } },
    { {      UINT16_MAX, UINT16_C(61493), UINT16_C(47284), UINT16_C(14305), UINT16_C(14208), UINT16_C(12203), UINT16_C(22704), UINT16_C( 5995) },
      { -INT16_C(    17), -INT16_C(    15), -INT16_C(    13),  INT16_C(    11),  INT16_C(    13), -INT16_C( 13308),  INT16_C( 22765), -INT16_C( 24190) },
      { UINT16_C(    0), UINT16_C(    2), UINT16_C(    6), UINT16_C( 2048), UINT16_C(    0), UINT16_C(64176), UINT16_C(    0), UINT16_C(    0) } },
    { { UINT16_C( 8617), UINT16_C(22814), UINT16_C(35193), UINT16_C(40048), UINT16_C( 6291), UINT16_C(49805), UINT16_C(28389), UINT16_C(12572) },
      {  INT16_C(    16), -INT16_C(    14), -INT16_C(    16),  INT16_C(     9), -INT16_C(    12), -INT16_C(    12), -INT16_C(    10),  INT16_C(    12) },
      { UINT16_C(    0), UINT16_C(    1), UINT16_C(    1), UINT16_C(57344), UINT16_C(    2), UINT16_C(   12), UINT16_C(   28), UINT16_C(49152) } },
    { { UINT16_C(31227), UINT16_C(57490), UINT16_C(44775), UINT16_C(50450), UINT16_C( 4302), UINT16_C(18064), UINT16_C(64656), UINT16_C(51016) },
      { -INT16_C(    15),  INT16_C(    13),  INT16_C(     8),  INT16_C(    11), -INT16_C(    12), -INT16_C(    14),  INT16_C(    10), -INT16_C(    12) },
      { UINT16_C(    1), UINT16_C(16384), UINT16_C(59136), UINT16_C(36864), UINT16_C(    1), UINT16_C(    1), UINT16_C(16384), UINT16_C(   12) } },
    { { UINT16_C( 2517), UINT16_C(25881), UINT16_C(24837), UINT16_C(65068), UINT16_C(39402), UINT16_C(10598), UINT16_C(59547), UINT16_C(20543) },
      { -INT16_C( 22820), -INT16_C(    10),  INT16_C(    13), -INT16_C(    15),  INT16_C(    14),  INT16_C(    11), -INT16_C(  3331), -INT16_C( 11726) },
      { UINT16_C(    0), UINT16_C(   25), UINT16_C(40960), UINT16_C(    2), UINT16_C(32768), UINT16_C(12288), UINT16_C( 7443), UINT16_C(    0) } },
    { { UINT16_C(26108), UINT16_C(38848), UINT16_C(   77), UINT16_C(10728), UINT16_C(11174), UINT16_C(40924), UINT16_C(24881), UINT16_C(35940) },
      { -INT16_C(     9), -INT16_C( 26644),  INT16_C(    15), -INT16_C(    13), -INT16_C( 24215),  INT16_C(    10), -INT16_C(    14),  INT16_C(   428) },
      { UINT16_C(   51), UINT16_C(    0), UINT16_C(32768), UINT16_C(    1), UINT16_C(    0), UINT16_C(28672), UINT16_C(    2), UINT16_C(    0) } },
    { { UINT16_C(33452), UINT16_C(56754), UINT16_C( 5859), UINT16_C(32105), UINT16_C(22004), UINT16_C(50453), UINT16_C(32627), UINT16_C(56465) },
      {  INT16_C(    11),  INT16_C(     9), -INT16_C(    13),  INT16_C(    11), -INT16_C(    16),  INT16_C(    15),  INT16_C(    15), -INT16_C(    10) },
      { UINT16_C(24576), UINT16_C(25600), UINT16_C(    1), UINT16_C(18432), UINT16_C(    0), UINT16_C(32768), UINT16_C(32768), UINT16_C(   55) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);
    simde_int16x8_t b = simde_vld1q_s16(test_vec[i].b);
    simde_uint16x8_t r = simde_vrshlq_u16(a, b);
    simde_test_arm_neon_assert_equal_u16x8(r, simde_vld1q_u16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);

  uint16_t a_patch[] = { UINT16_MAX, UINT16_C(1) << (16 - 1), UINT16_MAX };
  int16_t  b_patch[] = {         16,                     -16,    -16 - 1 };

  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x8_private a_ = simde_uint16x8_to_private(simde_test_arm_neon_random_u16x8());
    simde_int16x8_private b_ = simde_int16x8_to_private(simde_test_arm_neon_random_i16x8());

    for (size_t j = 0 ; j < (sizeof(b_.values) / sizeof(b_.values[0])) ; j++) {
      if (probability(PROBABILITY)) {
        while (simde_math_abs(b_.values[j]) > 16) {
          b_.values[j] >>= 1;
        }
      }
    }

    if ((size_t) i < (sizeof(a_patch) / sizeof(a_patch[0]))) {
      a_.values[0] = a_patch[i];
      b_.values[0] = b_patch[i];
    }

    simde_uint16x8_t a = simde_uint16x8_from_private(a_);
    simde_int16x8_t b = simde_int16x8_from_private(b_);

    simde_uint16x8_t r = simde_vrshlq_u16(a, b);

    simde_test_arm_neon_write_u16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vrshlq_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint32_t a[4];
    int32_t b[4];
    uint32_t r[4];
  } test_vec[] = {
    { {           UINT32_MAX, UINT32_C(3316255323), UINT32_C( 187098578), UINT32_C(3195457013) },
      {  INT32_C(          32), -INT32_C(          29), -INT32_C(          22),  INT32_C(          27) },
      { UINT32_C(         0), UINT32_C(         6), UINT32_C(        45), UINT32_C(2818572288) } },
    { { UINT32_C(2147483648), UINT32_C(2776245168), UINT32_C( 425980144), UINT32_C(1793817973) },
      { -INT32_C(          32), -INT32_C(   894871393),  INT32_C(          19),  INT32_C(          20) },
      { UINT32_C(         1), UINT32_C(         0), UINT32_C(2273312768), UINT32_C(3612344320) } },
    { {           UINT32_MAX, UINT32_C(2662521640), UINT32_C(2131271000), UINT32_C( 612199301) },
      { -INT32_C(          33), -INT32_C(          18), -INT32_C(          24),  INT32_C(          28) },
      { UINT32_C(         0), UINT32_C(     10157), UINT32_C(       127), UINT32_C(1342177280) } },
    { { UINT32_C( 503939782), UINT32_C(2778534176), UINT32_C(1086921341), UINT32_C(2306259009) },
      {  INT32_C(          23), -INT32_C(  1778331642),  INT32_C(          28),  INT32_C(          19) },
      { UINT32_C(1660944384), UINT32_C(1732528128), UINT32_C(3489660928), UINT32_C(3255304192) } },
    { { UINT32_C( 535224994), UINT32_C(1029681148), UINT32_C(1204213096), UINT32_C(3601222608) },
      { -INT32_C(          22),  INT32_C(          30), -INT32_C(          26), -INT32_C(          27) },
      { UINT32_C(       128), UINT32_C(         0), UINT32_C(        18), UINT32_C(        27) } },
    { { UINT32_C( 939543248), UINT32_C(4018128415), UINT32_C( 751117585), UINT32_C(3844157899) },
      {  INT32_C(          17), -INT32_C(          22), -INT32_C(          22),  INT32_C(  1751886744) },
      { UINT32_C(2510290944), UINT32_C(       958), UINT32_C(       179), UINT32_C(         0) } },
    { { UINT32_C(1124343857), UINT32_C( 292538949), UINT32_C(1744212475), UINT32_C(2427147716) },
      {  INT32_C(          27), -INT32_C(          25), -INT32_C(          25), -INT32_C(   419691851) },
      { UINT32_C(2281701376), UINT32_C(         9), UINT32_C(        52), UINT32_C(         0) } },
    { { UINT32_C(3329792459), UINT32_C(3995954986), UINT32_C( 410966212), UINT32_C( 558826433) },
      {  INT32_C(          30),  INT32_C(          22), -INT32_C(          24), -INT32_C(   335069919) },
      { UINT32_C(3221225472), UINT32_C(3397386240), UINT32_C(        24), UINT32_C(         0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_int32x4_t b = simde_vld1q_s32(test_vec[i].b);
    simde_uint32x4_t r = simde_vrshlq_u32(a, b);

    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);

  uint32_t a_patch[] = { UINT32_MAX, UINT32_C(1) << (32 - 1), UINT32_MAX };
  int32_t  b_patch[] = {         32,                     -32,    -32 - 1 };

  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x4_private a_ = simde_uint32x4_to_private(simde_test_arm_neon_random_u32x4());
    simde_int32x4_private b_ = simde_int32x4_to_private(simde_test_arm_neon_random_i32x4());

    for (size_t j = 0 ; j < (sizeof(b_.values) / sizeof(b_.values[0])) ; j++) {
      if (probability(PROBABILITY)) {
        while (simde_math_abs(b_.values[j]) > 32) {
          b_.values[j] >>= 1;
        }
      }
    }

    if ((size_t) i < (sizeof(a_patch) / sizeof(a_patch[0]))) {
      a_.values[0] = a_patch[i];
      b_.values[0] = b_patch[i];
    }

    simde_uint32x4_t a = simde_uint32x4_from_private(a_);
    simde_int32x4_t b = simde_int32x4_from_private(b_);

    simde_uint32x4_t r = simde_vrshlq_u32(a, b);

    simde_test_arm_neon_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vrshlq_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint64_t a[2];
    int64_t b[2];
    uint64_t r[2];
  } test_vec[] = {
    { {                    UINT64_MAX, UINT64_C(16294151362500260038) },
      {  INT64_C(                  64),  INT64_C(                  58) },
      { UINT64_C(                   0), UINT64_C( 1729382256910270464) } },
    { { UINT64_C( 9223372036854775808), UINT64_C(16863135901910622191) },
      { -INT64_C(                  64), -INT64_C(                  47) },
      { UINT64_C(                   1), UINT64_C(              119820) } },
    { {                    UINT64_MAX, UINT64_C( 2005102394293229065) },
      { -INT64_C(                  65), -INT64_C(                  47) },
      { UINT64_C(                   0), UINT64_C(               14247) } },
    { { UINT64_C( 1572984371782268265), UINT64_C(10542706757663446378) },
      { -INT64_C(                  47), -INT64_C(                  59) },
      { UINT64_C(               11177), UINT64_C(                  18) } },
    { { UINT64_C( 9387779671739714207), UINT64_C(14053309784719439957) },
      {  INT64_C(                  44), -INT64_C(                  47) },
      { UINT64_C(15900503842198913024), UINT64_C(               99855) } },
    { { UINT64_C( 3933560557134412309), UINT64_C(10367074293171904885) },
      { -INT64_C(                  54), -INT64_C( 2073254729651704801) },
      { UINT64_C(                 218), UINT64_C( 4489016506151075840) } },
    { { UINT64_C(10824960247039706945), UINT64_C( 4497186091603156343) },
      { -INT64_C(                  33), -INT64_C(                  60) },
      { UINT64_C(          1260191231), UINT64_C(                   4) } },
    { { UINT64_C(13544247016243875936), UINT64_C( 1686370601464357418) },
      {  INT64_C( 5733672828602753178), -INT64_C(                  64) },
      { UINT64_C(                   0), UINT64_C(                   0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x2_t a = simde_vld1q_u64(test_vec[i].a);
    simde_int64x2_t b = simde_vld1q_s64(test_vec[i].b);
    simde_uint64x2_t r = simde_vrshlq_u64(a, b);
    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);

  uint64_t a_patch[] = { UINT64_MAX, UINT64_C(1) << (64 - 1), UINT64_MAX };
  int64_t  b_patch[] = {         64,                     -64,    -64 - 1 };

  for (int i = 0 ; i < 8 ; i++) {
    simde_uint64x2_private a_ = simde_uint64x2_to_private(simde_test_arm_neon_random_u64x2());
    simde_int64x2_private b_ = simde_int64x2_to_private(simde_test_arm_neon_random_i64x2());

    for (size_t j = 0 ; j < (sizeof(b_.values) / sizeof(b_.values[0])) ; j++) {
      if (probability(PROBABILITY)) {
        while (simde_math_llabs(b_.values[j]) > 64) {
          b_.values[j] >>= 1;
        }
      }
    }

    if ((size_t) i < (sizeof(a_patch) / sizeof(a_patch[0]))) {
      a_.values[0] = a_patch[i];
      b_.values[0] = b_patch[i];
    }

    simde_uint64x2_t a = simde_uint64x2_from_private(a_);
    simde_int64x2_t b = simde_int64x2_from_private(b_);

    simde_uint64x2_t r = simde_vrshlq_u64(a, b);

    simde_test_arm_neon_write_u64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vrshld_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int64_t a;
    int64_t b;
    int64_t r;
  } test_vec[] = {
    {  INT64_C( 7235246673386222188),
      -INT64_C( 6802743124129050522),
       INT64_C(                   0) },
    {  INT64_C( 2374865386728665409),
      -INT64_C( 5279494975934354335),
       INT64_C(                   0) },
    {  INT64_C( 7462768052823343018),
      -INT64_C( 5876693465748496476),
       INT64_C(                   0) },
    {  INT64_C( 6888037920171935739),
      -INT64_C( 5591869810952335003),
       INT64_C(                   0) },
    { -INT64_C( 3938554941343329809),
       INT64_C( 5704947285483948560),
       INT64_C( 8153187541293400064) },
    {  INT64_C( 1022139723881607378),
      -INT64_C( 4347624192171236113),
       INT64_C(       7798307219556) },
    {  INT64_C(  802215758266599987),
      -INT64_C( 7478308790315926636),
       INT64_C(                   0) },
    {  INT64_C( 5538469170421235237),
      -INT64_C( 1201353086719452740),
       INT64_C(                   0) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    int64_t r = simde_vrshld_s64(test_vec[i].a, test_vec[i].b);
    simde_assert_equal_i64(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    int64_t a = simde_test_codegen_random_i64();
    int64_t b = simde_test_codegen_random_i64();
    int64_t r = simde_vrshld_s64(a, b);

    simde_test_codegen_write_i64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i64(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vrshl_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vrshl_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vrshl_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vrshl_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vrshl_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vrshl_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vrshl_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vrshl_u64)

SIMDE_TEST_FUNC_LIST_ENTRY(vrshlq_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vrshlq_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vrshlq_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vrshlq_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vrshlq_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vrshlq_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vrshlq_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vrshlq_u64)

SIMDE_TEST_FUNC_LIST_ENTRY(vrshld_s64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
