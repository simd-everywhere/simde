#define SIMDE_TEST_ARM_NEON_INSN max

#include "test-neon.h"
#include "../../../simde/arm/neon/max.h"

static int
test_simde_vmax_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a[2];
    simde_float32 b[2];
    simde_float32 r[2];
  } test_vec[] = {
    #if !defined(SIMDE_FAST_NANS)
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -464.60) },
      { SIMDE_FLOAT32_C(   866.05),            SIMDE_MATH_NANF },
      {            SIMDE_MATH_NANF,            SIMDE_MATH_NANF } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   861.67) },
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   861.67) },
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   861.67) } },
    #endif
    { { SIMDE_FLOAT32_C(   378.04), SIMDE_FLOAT32_C(  -897.72) },
      { SIMDE_FLOAT32_C(  -584.86), SIMDE_FLOAT32_C(   922.34) },
      { SIMDE_FLOAT32_C(   378.04), SIMDE_FLOAT32_C(   922.34) } },
    { { SIMDE_FLOAT32_C(   169.18), SIMDE_FLOAT32_C(   164.66) },
      { SIMDE_FLOAT32_C(   295.66), SIMDE_FLOAT32_C(  -857.49) },
      { SIMDE_FLOAT32_C(   295.66), SIMDE_FLOAT32_C(   164.66) } },
    { { SIMDE_FLOAT32_C(  -597.22), SIMDE_FLOAT32_C(  -740.42) },
      { SIMDE_FLOAT32_C(  -439.12), SIMDE_FLOAT32_C(  -673.24) },
      { SIMDE_FLOAT32_C(  -439.12), SIMDE_FLOAT32_C(  -673.24) } },
    { { SIMDE_FLOAT32_C(   693.53), SIMDE_FLOAT32_C(  -114.27) },
      { SIMDE_FLOAT32_C(   599.27), SIMDE_FLOAT32_C(   359.67) },
      { SIMDE_FLOAT32_C(   693.53), SIMDE_FLOAT32_C(   359.67) } },
    { { SIMDE_FLOAT32_C(  -598.01), SIMDE_FLOAT32_C(   -64.73) },
      { SIMDE_FLOAT32_C(   384.43), SIMDE_FLOAT32_C(   446.35) },
      { SIMDE_FLOAT32_C(   384.43), SIMDE_FLOAT32_C(   446.35) } },
    { { SIMDE_FLOAT32_C(   449.76), SIMDE_FLOAT32_C(   326.28) },
      { SIMDE_FLOAT32_C(   146.92), SIMDE_FLOAT32_C(  -725.29) },
      { SIMDE_FLOAT32_C(   449.76), SIMDE_FLOAT32_C(   326.28) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t a = simde_vld1_f32(test_vec[i].a);
    simde_float32x2_t b = simde_vld1_f32(test_vec[i].b);
    simde_float32x2_t r = simde_vmax_f32(a, b);

    simde_test_arm_neon_assert_equal_f32x2(r, simde_vld1_f32(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  simde_float32_t values[8 * 2 * sizeof(simde_float32x2_t)];
  simde_test_arm_neon_random_f32x2_full(8, 2, values, -1000.0f, 1000.0f, SIMDE_TEST_VEC_FLOAT_NAN | SIMDE_TEST_VEC_FLOAT_EQUAL);

  for (size_t i = 0 ; i < 8 ; i++) {
    simde_float32x2_t a = simde_test_arm_neon_random_extract_f32x2(i, 2, 0, values);
    simde_float32x2_t b = simde_test_arm_neon_random_extract_f32x2(i, 2, 1, values);
    simde_float32x2_t r = simde_vmax_f32(a, b);

    simde_test_arm_neon_write_f32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmax_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 a[1];
    simde_float64 b[1];
    simde_float64 r[1];
  } test_vec[] = {
    #if !defined(SIMDE_FAST_NANS)
    { {             SIMDE_MATH_NAN },
      { SIMDE_FLOAT64_C(   170.12) },
      {             SIMDE_MATH_NAN } },
    { { SIMDE_FLOAT64_C(   -24.73) },
      {             SIMDE_MATH_NAN },
      {             SIMDE_MATH_NAN } },
    { {             SIMDE_MATH_NAN },
      {             SIMDE_MATH_NAN },
      {             SIMDE_MATH_NAN } },
    #endif
    { { SIMDE_FLOAT64_C(  -928.88) },
      { SIMDE_FLOAT64_C(  -928.88) },
      { SIMDE_FLOAT64_C(  -928.88) } },
    { { SIMDE_FLOAT64_C(   148.48) },
      { SIMDE_FLOAT64_C(  -665.54) },
      { SIMDE_FLOAT64_C(   148.48) } },
    { { SIMDE_FLOAT64_C(   367.73) },
      { SIMDE_FLOAT64_C(  -686.85) },
      { SIMDE_FLOAT64_C(   367.73) } },
    { { SIMDE_FLOAT64_C(   630.12) },
      { SIMDE_FLOAT64_C(   510.24) },
      { SIMDE_FLOAT64_C(   630.12) } },
    { { SIMDE_FLOAT64_C(  -284.08) },
      { SIMDE_FLOAT64_C(   889.70) },
      { SIMDE_FLOAT64_C(   889.70) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x1_t a = simde_vld1_f64(test_vec[i].a);
    simde_float64x1_t b = simde_vld1_f64(test_vec[i].b);
    simde_float64x1_t r = simde_vmax_f64(a, b);

    simde_test_arm_neon_assert_equal_f64x1(r, simde_vld1_f64(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  simde_float64_t values[8 * 2 * sizeof(simde_float64x1_t)];
  simde_test_arm_neon_random_f64x1_full(8, 2, values, -1000.0, 1000.0, SIMDE_TEST_VEC_FLOAT_NAN | SIMDE_TEST_VEC_FLOAT_EQUAL);

  for (size_t i = 0 ; i < 8 ; i++) {
    simde_float64x1_t a = simde_test_arm_neon_random_extract_f64x1(i, 2, 0, values);
    simde_float64x1_t b = simde_test_arm_neon_random_extract_f64x1(i, 2, 1, values);
    simde_float64x1_t r = simde_vmax_f64(a, b);

    simde_test_arm_neon_write_f64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x1(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmax_s8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int8_t a[8];
    int8_t b[8];
    int8_t r[8];
  } test_vec[] = {
    { { -INT8_C(  87),  INT8_C(  87),  INT8_C(  74), -INT8_C( 102), -INT8_C(  19), -INT8_C(  31),  INT8_C( 113),  INT8_C(  38) },
      {  INT8_C(  75), -INT8_C(  62),  INT8_C(  18), -INT8_C(  21), -INT8_C( 114), -INT8_C(  14),  INT8_C(  47), -INT8_C(  51) },
      {  INT8_C(  75),  INT8_C(  87),  INT8_C(  74), -INT8_C(  21), -INT8_C(  19), -INT8_C(  14),  INT8_C( 113),  INT8_C(  38) } },
    { {  INT8_C(  14),  INT8_C( 106),  INT8_C(  19), -INT8_C(  11), -INT8_C(  35), -INT8_C(  42),  INT8_C(  78),  INT8_C( 120) },
      { -INT8_C(  88), -INT8_C( 117),  INT8_C( 125),  INT8_C( 123),  INT8_C(  11),  INT8_C(  49),  INT8_C(  16), -INT8_C(  75) },
      {  INT8_C(  14),  INT8_C( 106),  INT8_C( 125),  INT8_C( 123),  INT8_C(  11),  INT8_C(  49),  INT8_C(  78),  INT8_C( 120) } },
    { { -INT8_C( 120),  INT8_C(  90),  INT8_C(  79),  INT8_C( 118),  INT8_C(  59), -INT8_C(  63), -INT8_C( 100), -INT8_C( 122) },
      { -INT8_C( 125), -INT8_C(  82),  INT8_C( 113),  INT8_C(  17), -INT8_C(  95), -INT8_C(  95), -INT8_C(  34), -INT8_C(  81) },
      { -INT8_C( 120),  INT8_C(  90),  INT8_C( 113),  INT8_C( 118),  INT8_C(  59), -INT8_C(  63), -INT8_C(  34), -INT8_C(  81) } },
    { {  INT8_C(  11), -INT8_C(  15), -INT8_C(  91), -INT8_C(  24), -INT8_C(  56), -INT8_C(  13),  INT8_C(  97),  INT8_C( 112) },
      {  INT8_C( 126), -INT8_C(  34), -INT8_C(  20), -INT8_C( 119),  INT8_C(  15), -INT8_C(   4),  INT8_C(  62), -INT8_C( 104) },
      {  INT8_C( 126), -INT8_C(  15), -INT8_C(  20), -INT8_C(  24),  INT8_C(  15), -INT8_C(   4),  INT8_C(  97),  INT8_C( 112) } },
    { {  INT8_C(  86), -INT8_C( 114),  INT8_C(  14), -INT8_C( 110),  INT8_C(  79), -INT8_C(  86),  INT8_C(  24), -INT8_C(  46) },
      {  INT8_C(  88), -INT8_C( 118), -INT8_C(  29), -INT8_C(   7),  INT8_C(  43), -INT8_C(  63), -INT8_C(  87),  INT8_C(  54) },
      {  INT8_C(  88), -INT8_C( 114),  INT8_C(  14), -INT8_C(   7),  INT8_C(  79), -INT8_C(  63),  INT8_C(  24),  INT8_C(  54) } },
    { { -INT8_C(  77),  INT8_C(  78),  INT8_C(  30),  INT8_C( 123),  INT8_C(  65),      INT8_MAX, -INT8_C(  21), -INT8_C(  65) },
      {  INT8_C(  94), -INT8_C(  41),  INT8_C(  72),  INT8_C( 109), -INT8_C(  45), -INT8_C( 121),  INT8_C(   5),  INT8_C(  42) },
      {  INT8_C(  94),  INT8_C(  78),  INT8_C(  72),  INT8_C( 123),  INT8_C(  65),      INT8_MAX,  INT8_C(   5),  INT8_C(  42) } },
    { {  INT8_C(  21),  INT8_C(  19), -INT8_C(  68),  INT8_C( 100), -INT8_C(  67), -INT8_C(  44),  INT8_C(  54),  INT8_C(  22) },
      {  INT8_C(  94),  INT8_C(  25),  INT8_C(  15), -INT8_C( 119), -INT8_C(  38), -INT8_C(  72), -INT8_C(  65), -INT8_C( 115) },
      {  INT8_C(  94),  INT8_C(  25),  INT8_C(  15),  INT8_C( 100), -INT8_C(  38), -INT8_C(  44),  INT8_C(  54),  INT8_C(  22) } },
    { {  INT8_C(   6), -INT8_C(  34),  INT8_C(   8),  INT8_C(  71),  INT8_C(  93), -INT8_C(  12),  INT8_C(   6), -INT8_C(  69) },
      { -INT8_C(  53),  INT8_C(  79),  INT8_C(  41), -INT8_C(  97), -INT8_C(  42),  INT8_C(  46), -INT8_C(  55), -INT8_C(  21) },
      {  INT8_C(   6),  INT8_C(  79),  INT8_C(  41),  INT8_C(  71),  INT8_C(  93),  INT8_C(  46),  INT8_C(   6), -INT8_C(  21) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8_t a = simde_vld1_s8(test_vec[i].a);
    simde_int8x8_t b = simde_vld1_s8(test_vec[i].b);
    simde_int8x8_t r = simde_vmax_s8(a, b);

    simde_test_arm_neon_assert_equal_i8x8(r, simde_vld1_s8(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vmax_s16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int16_t a[4];
    int16_t b[4];
    int16_t r[4];
  } test_vec[] = {
    { {  INT16_C( 32420),  INT16_C( 25491),  INT16_C(  4717),  INT16_C( 28329) },
      { -INT16_C(  3837), -INT16_C( 16305), -INT16_C( 29343),  INT16_C( 25906) },
      {  INT16_C( 32420),  INT16_C( 25491),  INT16_C(  4717),  INT16_C( 28329) } },
    { { -INT16_C( 16284), -INT16_C( 26374), -INT16_C( 27696), -INT16_C( 10953) },
      {  INT16_C(  8018),  INT16_C( 12726),  INT16_C( 25845), -INT16_C( 25884) },
      {  INT16_C(  8018),  INT16_C( 12726),  INT16_C( 25845), -INT16_C( 10953) } },
    { {  INT16_C( 30946),  INT16_C( 20477), -INT16_C( 22646), -INT16_C( 29251) },
      {  INT16_C(  3480), -INT16_C(  1715),  INT16_C( 32666), -INT16_C(   418) },
      {  INT16_C( 30946),  INT16_C( 20477),  INT16_C( 32666), -INT16_C(   418) } },
    { {  INT16_C( 22591),  INT16_C(  3990), -INT16_C( 12820),  INT16_C( 16100) },
      { -INT16_C( 25875), -INT16_C(  7568),  INT16_C( 21758), -INT16_C(  8068) },
      {  INT16_C( 22591),  INT16_C(  3990),  INT16_C( 21758),  INT16_C( 16100) } },
    { {  INT16_C( 31436),  INT16_C( 22063), -INT16_C(  4831), -INT16_C( 17949) },
      {  INT16_C( 12538), -INT16_C( 27469),  INT16_C(  4527), -INT16_C(  4462) },
      {  INT16_C( 31436),  INT16_C( 22063),  INT16_C(  4527), -INT16_C(  4462) } },
    { {  INT16_C( 10602),  INT16_C( 22269), -INT16_C(  7434), -INT16_C(  7276) },
      {  INT16_C(  1148),  INT16_C( 31686),  INT16_C( 16985),  INT16_C(  9563) },
      {  INT16_C( 10602),  INT16_C( 31686),  INT16_C( 16985),  INT16_C(  9563) } },
    { { -INT16_C( 29764), -INT16_C(  8836),  INT16_C( 24440),  INT16_C( 29335) },
      {  INT16_C( 19088),  INT16_C( 16134), -INT16_C( 26533), -INT16_C( 15058) },
      {  INT16_C( 19088),  INT16_C( 16134),  INT16_C( 24440),  INT16_C( 29335) } },
    { {  INT16_C( 11201), -INT16_C( 18405), -INT16_C( 20467), -INT16_C( 30053) },
      {  INT16_C( 25012),  INT16_C(  3333),  INT16_C( 24740),  INT16_C( 24627) },
      {  INT16_C( 25012),  INT16_C(  3333),  INT16_C( 24740),  INT16_C( 24627) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t a = simde_vld1_s16(test_vec[i].a);
    simde_int16x4_t b = simde_vld1_s16(test_vec[i].b);
    simde_int16x4_t r = simde_vmax_s16(a, b);

    simde_test_arm_neon_assert_equal_i16x4(r, simde_vld1_s16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vmax_s32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int32_t a[2];
    int32_t b[2];
    int32_t r[2];
  } test_vec[] = {
    { { -INT32_C(  2127505976), -INT32_C(  1129472258) },
      {  INT32_C(  1899583289), -INT32_C(  1846142889) },
      {  INT32_C(  1899583289), -INT32_C(  1129472258) } },
    { { -INT32_C(   157896609),  INT32_C(   175452357) },
      { -INT32_C(  1933110609), -INT32_C(   339752413) },
      { -INT32_C(   157896609),  INT32_C(   175452357) } },
    { { -INT32_C(  1637027936), -INT32_C(   950330994) },
      { -INT32_C(   935816080),  INT32_C(   190394028) },
      { -INT32_C(   935816080),  INT32_C(   190394028) } },
    { { -INT32_C(  1543376929), -INT32_C(   810649825) },
      { -INT32_C(  1386515063), -INT32_C(   526902720) },
      { -INT32_C(  1386515063), -INT32_C(   526902720) } },
    { { -INT32_C(  1736571638), -INT32_C(  1889543906) },
      {  INT32_C(   425171053), -INT32_C(  1524322106) },
      {  INT32_C(   425171053), -INT32_C(  1524322106) } },
    { { -INT32_C(  1102436705),  INT32_C(   646838429) },
      { -INT32_C(  1361844114),  INT32_C(   227437571) },
      { -INT32_C(  1102436705),  INT32_C(   646838429) } },
    { { -INT32_C(  1885008783),  INT32_C(  1394476262) },
      {  INT32_C(  1668117916), -INT32_C(  1006071515) },
      {  INT32_C(  1668117916),  INT32_C(  1394476262) } },
    { {  INT32_C(  1417892535), -INT32_C(  1183117237) },
      { -INT32_C(    60338439),  INT32_C(   722073018) },
      {  INT32_C(  1417892535),  INT32_C(   722073018) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t a = simde_vld1_s32(test_vec[i].a);
    simde_int32x2_t b = simde_vld1_s32(test_vec[i].b);
    simde_int32x2_t r = simde_vmax_s32(a, b);

    simde_test_arm_neon_assert_equal_i32x2(r, simde_vld1_s32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_x_vmax_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a[1];
    int64_t b[1];
    int64_t r[1];
  } test_vec[] = {
    { {  INT64_C( 5432915600686277344) },
      { -INT64_C( 1302158069541595515) },
      {  INT64_C( 5432915600686277344) } },
    { { -INT64_C( 8056204626967572500) },
      { -INT64_C(  512464674649944311) },
      { -INT64_C(  512464674649944311) } },
    { { -INT64_C( 7638502919520552514) },
      {  INT64_C( 5205046660914056749) },
      {  INT64_C( 5205046660914056749) } },
    { { -INT64_C( 6954184997585290663) },
      {  INT64_C( 2640365464899947157) },
      {  INT64_C( 2640365464899947157) } },
    { { -INT64_C( 7380040324739574033) },
      {  INT64_C( 1515221292220461410) },
      {  INT64_C( 1515221292220461410) } },
    { { -INT64_C(  768568108066366945) },
      {  INT64_C( 5481802540706293641) },
      {  INT64_C( 5481802540706293641) } },
    { {  INT64_C( 2315660267356940572) },
      {  INT64_C( 5648611448497048209) },
      {  INT64_C( 5648611448497048209) } },
    { {  INT64_C( 7914330759719314816) },
      { -INT64_C( 2744258162732533952) },
      {  INT64_C( 7914330759719314816) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x1_t a = simde_vld1_s64(test_vec[i].a);
    simde_int64x1_t b = simde_vld1_s64(test_vec[i].b);
    simde_int64x1_t r = simde_x_vmax_s64(a, b);

    simde_test_arm_neon_assert_equal_i64x1(r, simde_vld1_s64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int64x1_t a = simde_test_arm_neon_random_i64x1();
    simde_int64x1_t b = simde_test_arm_neon_random_i64x1();
    simde_int64x1_t r = simde_x_vmax_s64(a, b);

    simde_test_arm_neon_write_i64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x1(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmax_u8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint8_t a[8];
    uint8_t b[8];
    uint8_t r[8];
  } test_vec[] = {
    { { UINT8_C( 34), UINT8_C(239), UINT8_C(244), UINT8_C(249), UINT8_C( 28), UINT8_C(126), UINT8_C( 40), UINT8_C(103) },
      { UINT8_C(  7), UINT8_C(201), UINT8_C( 66), UINT8_C(199), UINT8_C(156), UINT8_C( 23), UINT8_C(126), UINT8_C(154) },
      { UINT8_C( 34), UINT8_C(239), UINT8_C(244), UINT8_C(249), UINT8_C(156), UINT8_C(126), UINT8_C(126), UINT8_C(154) } },
    { { UINT8_C(161), UINT8_C(235), UINT8_C(175), UINT8_C( 89), UINT8_C( 96), UINT8_C(166), UINT8_C( 15), UINT8_C( 57) },
      { UINT8_C( 24), UINT8_C(173), UINT8_C(182), UINT8_C(141), UINT8_C(121), UINT8_C(  9), UINT8_C(153), UINT8_C(156) },
      { UINT8_C(161), UINT8_C(235), UINT8_C(182), UINT8_C(141), UINT8_C(121), UINT8_C(166), UINT8_C(153), UINT8_C(156) } },
    { { UINT8_C(248), UINT8_C(142), UINT8_C(149), UINT8_C( 21), UINT8_C( 12), UINT8_C(189), UINT8_C(124), UINT8_C( 19) },
      { UINT8_C(134), UINT8_C(190), UINT8_C(218), UINT8_C( 35), UINT8_C(213), UINT8_C( 88), UINT8_C(189), UINT8_C(118) },
      { UINT8_C(248), UINT8_C(190), UINT8_C(218), UINT8_C( 35), UINT8_C(213), UINT8_C(189), UINT8_C(189), UINT8_C(118) } },
    { { UINT8_C( 67), UINT8_C(108), UINT8_C(207), UINT8_C(164), UINT8_C( 19), UINT8_C(222), UINT8_C(221), UINT8_C( 43) },
      { UINT8_C(139), UINT8_C(147), UINT8_C(185), UINT8_C(  5), UINT8_C(156), UINT8_C( 82), UINT8_C(161), UINT8_C(148) },
      { UINT8_C(139), UINT8_C(147), UINT8_C(207), UINT8_C(164), UINT8_C(156), UINT8_C(222), UINT8_C(221), UINT8_C(148) } },
    { { UINT8_C(224), UINT8_C( 54), UINT8_C(169), UINT8_C(237), UINT8_C(243), UINT8_C( 37), UINT8_C(  0), UINT8_C(122) },
      { UINT8_C(227), UINT8_C(219), UINT8_C(157), UINT8_C(184), UINT8_C( 51), UINT8_C( 90), UINT8_C( 47), UINT8_C(119) },
      { UINT8_C(227), UINT8_C(219), UINT8_C(169), UINT8_C(237), UINT8_C(243), UINT8_C( 90), UINT8_C( 47), UINT8_C(122) } },
    { { UINT8_C(199), UINT8_C(254), UINT8_C( 27), UINT8_C(218), UINT8_C(221), UINT8_C(248), UINT8_C(  5), UINT8_C(104) },
      { UINT8_C(139), UINT8_C(190), UINT8_C(109), UINT8_C( 39), UINT8_C( 17), UINT8_C( 14), UINT8_C(187), UINT8_C(241) },
      { UINT8_C(199), UINT8_C(254), UINT8_C(109), UINT8_C(218), UINT8_C(221), UINT8_C(248), UINT8_C(187), UINT8_C(241) } },
    { { UINT8_C( 68), UINT8_C(101), UINT8_C(222), UINT8_C( 56), UINT8_C(138), UINT8_C(223), UINT8_C(178), UINT8_C(110) },
      { UINT8_C(186), UINT8_C( 79), UINT8_C( 38), UINT8_C(237), UINT8_C(169), UINT8_C( 85), UINT8_C(100), UINT8_C(112) },
      { UINT8_C(186), UINT8_C(101), UINT8_C(222), UINT8_C(237), UINT8_C(169), UINT8_C(223), UINT8_C(178), UINT8_C(112) } },
    { { UINT8_C( 84), UINT8_C(127), UINT8_C( 74), UINT8_C( 49), UINT8_C(119), UINT8_C( 80), UINT8_C(153), UINT8_C(  2) },
      { UINT8_C( 14), UINT8_C(  7), UINT8_C( 41), UINT8_C( 31), UINT8_C( 21), UINT8_C(229), UINT8_C( 17), UINT8_C( 90) },
      { UINT8_C( 84), UINT8_C(127), UINT8_C( 74), UINT8_C( 49), UINT8_C(119), UINT8_C(229), UINT8_C(153), UINT8_C( 90) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x8_t a = simde_vld1_u8(test_vec[i].a);
    simde_uint8x8_t b = simde_vld1_u8(test_vec[i].b);
    simde_uint8x8_t r = simde_vmax_u8(a, b);

    simde_test_arm_neon_assert_equal_u8x8(r, simde_vld1_u8(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vmax_u16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint16_t a[4];
    uint16_t b[4];
    uint16_t r[4];
  } test_vec[] = {
    { { UINT16_C(24011), UINT16_C(62465), UINT16_C(60258), UINT16_C(57428) },
      { UINT16_C(26316), UINT16_C(33072), UINT16_C(26869), UINT16_C(59293) },
      { UINT16_C(26316), UINT16_C(62465), UINT16_C(60258), UINT16_C(59293) } },
    { { UINT16_C(20007), UINT16_C(36086), UINT16_C( 9334), UINT16_C(55614) },
      { UINT16_C(12969), UINT16_C(14745), UINT16_C(22678), UINT16_C(24990) },
      { UINT16_C(20007), UINT16_C(36086), UINT16_C(22678), UINT16_C(55614) } },
    { { UINT16_C(40885), UINT16_C( 5974), UINT16_C(43658), UINT16_C(22263) },
      { UINT16_C(10000), UINT16_C( 1495), UINT16_C(30096), UINT16_C(47084) },
      { UINT16_C(40885), UINT16_C( 5974), UINT16_C(43658), UINT16_C(47084) } },
    { { UINT16_C(58051), UINT16_C(14660), UINT16_C(33286), UINT16_C(45074) },
      { UINT16_C(44213), UINT16_C(19433), UINT16_C(34564), UINT16_C(47533) },
      { UINT16_C(58051), UINT16_C(19433), UINT16_C(34564), UINT16_C(47533) } },
    { { UINT16_C(  806), UINT16_C(45265), UINT16_C(51373), UINT16_C(48390) },
      { UINT16_C(57072), UINT16_C(32962), UINT16_C(44883), UINT16_C( 5687) },
      { UINT16_C(57072), UINT16_C(45265), UINT16_C(51373), UINT16_C(48390) } },
    { { UINT16_C(31633), UINT16_C(38991), UINT16_C(25086), UINT16_C(45896) },
      { UINT16_C(12557), UINT16_C( 4606), UINT16_C(43961), UINT16_C(57291) },
      { UINT16_C(31633), UINT16_C(38991), UINT16_C(43961), UINT16_C(57291) } },
    { { UINT16_C(40110), UINT16_C(23440), UINT16_C(38500), UINT16_C(21528) },
      { UINT16_C(56180), UINT16_C(51156), UINT16_C( 3210), UINT16_C( 7133) },
      { UINT16_C(56180), UINT16_C(51156), UINT16_C(38500), UINT16_C(21528) } },
    { { UINT16_C(11399), UINT16_C(34227), UINT16_C(64398), UINT16_C(39736) },
      { UINT16_C(14125), UINT16_C(59053), UINT16_C(30946), UINT16_C(37317) },
      { UINT16_C(14125), UINT16_C(59053), UINT16_C(64398), UINT16_C(39736) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4_t a = simde_vld1_u16(test_vec[i].a);
    simde_uint16x4_t b = simde_vld1_u16(test_vec[i].b);
    simde_uint16x4_t r = simde_vmax_u16(a, b);
    simde_test_arm_neon_assert_equal_u16x4(r, simde_vld1_u16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vmax_u32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint32_t a[2];
    uint32_t b[2];
    uint32_t r[2];
  } test_vec[] = {
    { { UINT32_C(1870064833), UINT32_C( 854381305) },
      { UINT32_C(3121368286), UINT32_C(1157781054) },
      { UINT32_C(3121368286), UINT32_C(1157781054) } },
    { { UINT32_C( 440216721), UINT32_C(2807037766) },
      { UINT32_C(4141240393), UINT32_C(1858046637) },
      { UINT32_C(4141240393), UINT32_C(2807037766) } },
    { { UINT32_C(1893611126), UINT32_C(3886205448) },
      { UINT32_C(1419882006), UINT32_C(2526716676) },
      { UINT32_C(1893611126), UINT32_C(3886205448) } },
    { { UINT32_C( 363911119), UINT32_C( 549257175) },
      { UINT32_C(4229403471), UINT32_C(2473252381) },
      { UINT32_C(4229403471), UINT32_C(2473252381) } },
    { { UINT32_C( 352536588), UINT32_C( 704423187) },
      { UINT32_C(1484692819), UINT32_C( 284039233) },
      { UINT32_C(1484692819), UINT32_C( 704423187) } },
    { { UINT32_C(3324419823), UINT32_C(3974619805) },
      { UINT32_C(2464743029), UINT32_C(3777385172) },
      { UINT32_C(3324419823), UINT32_C(3974619805) } },
    { { UINT32_C(2935368091), UINT32_C( 584577743) },
      { UINT32_C(3497678223), UINT32_C(1575053421) },
      { UINT32_C(3497678223), UINT32_C(1575053421) } },
    { { UINT32_C(2736981766), UINT32_C(1603209961) },
      { UINT32_C(3723589384), UINT32_C(1706956746) },
      { UINT32_C(3723589384), UINT32_C(1706956746) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2_t a = simde_vld1_u32(test_vec[i].a);
    simde_uint32x2_t b = simde_vld1_u32(test_vec[i].b);
    simde_uint32x2_t r = simde_vmax_u32(a, b);
    simde_test_arm_neon_assert_equal_u32x2(r, simde_vld1_u32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_x_vmax_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a[1];
    uint64_t b[1];
    uint64_t r[1];
  } test_vec[] = {
    { { UINT64_C(10652172966900850920) },
      { UINT64_C(17457258446329908764) },
      { UINT64_C(17457258446329908764) } },
    { { UINT64_C(  277750937440637858) },
      { UINT64_C( 8434053037527416126) },
      { UINT64_C( 8434053037527416126) } },
    { { UINT64_C( 7645278514851557286) },
      { UINT64_C( 1012231759559378954) },
      { UINT64_C( 7645278514851557286) } },
    { { UINT64_C( 4432513999474080383) },
      { UINT64_C(10354795792364217264) },
      { UINT64_C(10354795792364217264) } },
    { { UINT64_C(16178671308015753934) },
      { UINT64_C( 1689420061799509495) },
      { UINT64_C(16178671308015753934) } },
    { { UINT64_C( 3350145401873763137) },
      { UINT64_C( 9203139584767758911) },
      { UINT64_C( 9203139584767758911) } },
    { { UINT64_C(17523543517649685881) },
      { UINT64_C( 8232238381830449806) },
      { UINT64_C(17523543517649685881) } },
    { { UINT64_C( 3566904722205103828) },
      { UINT64_C( 9471933180020386626) },
      { UINT64_C( 9471933180020386626) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x1_t a = simde_vld1_u64(test_vec[i].a);
    simde_uint64x1_t b = simde_vld1_u64(test_vec[i].b);
    simde_uint64x1_t r = simde_x_vmax_u64(a, b);
    simde_test_arm_neon_assert_equal_u64x1(r, simde_vld1_u64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint64x1_t a = simde_test_arm_neon_random_u64x1();
    simde_uint64x1_t b = simde_test_arm_neon_random_u64x1();
    simde_uint64x1_t r = simde_x_vmax_u64(a, b);

    simde_test_arm_neon_write_u64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x1(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmaxq_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a[4];
    simde_float32 b[4];
    simde_float32 r[4];
  } test_vec[] = {
    #if !defined(SIMDE_FAST_NANS)
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -785.97),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -762.23) },
      { SIMDE_FLOAT32_C(    56.78),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -762.23) },
      {            SIMDE_MATH_NANF,            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -762.23) } },
    #endif
    { { SIMDE_FLOAT32_C(  -535.38), SIMDE_FLOAT32_C(   845.15), SIMDE_FLOAT32_C(   396.86), SIMDE_FLOAT32_C(   355.47) },
      { SIMDE_FLOAT32_C(   -18.38), SIMDE_FLOAT32_C(   855.51), SIMDE_FLOAT32_C(   739.43), SIMDE_FLOAT32_C(  -523.81) },
      { SIMDE_FLOAT32_C(   -18.38), SIMDE_FLOAT32_C(   855.51), SIMDE_FLOAT32_C(   739.43), SIMDE_FLOAT32_C(   355.47) } },
    { { SIMDE_FLOAT32_C(  -446.27), SIMDE_FLOAT32_C(  -422.02), SIMDE_FLOAT32_C(   105.64), SIMDE_FLOAT32_C(  -885.46) },
      { SIMDE_FLOAT32_C(  -799.73), SIMDE_FLOAT32_C(  -894.49), SIMDE_FLOAT32_C(   406.48), SIMDE_FLOAT32_C(   471.13) },
      { SIMDE_FLOAT32_C(  -446.27), SIMDE_FLOAT32_C(  -422.02), SIMDE_FLOAT32_C(   406.48), SIMDE_FLOAT32_C(   471.13) } },
    { { SIMDE_FLOAT32_C(  -440.41), SIMDE_FLOAT32_C(  -725.47), SIMDE_FLOAT32_C(  -111.15), SIMDE_FLOAT32_C(   220.63) },
      { SIMDE_FLOAT32_C(   187.92), SIMDE_FLOAT32_C(    -3.17), SIMDE_FLOAT32_C(  -134.93), SIMDE_FLOAT32_C(   247.43) },
      { SIMDE_FLOAT32_C(   187.92), SIMDE_FLOAT32_C(    -3.17), SIMDE_FLOAT32_C(  -111.15), SIMDE_FLOAT32_C(   247.43) } },
    { { SIMDE_FLOAT32_C(   210.87), SIMDE_FLOAT32_C(  -846.16), SIMDE_FLOAT32_C(   468.46), SIMDE_FLOAT32_C(  -732.35) },
      { SIMDE_FLOAT32_C(  -405.02), SIMDE_FLOAT32_C(   -75.46), SIMDE_FLOAT32_C(   125.81), SIMDE_FLOAT32_C(    59.60) },
      { SIMDE_FLOAT32_C(   210.87), SIMDE_FLOAT32_C(   -75.46), SIMDE_FLOAT32_C(   468.46), SIMDE_FLOAT32_C(    59.60) } },
    { { SIMDE_FLOAT32_C(  -230.31), SIMDE_FLOAT32_C(  -477.34), SIMDE_FLOAT32_C(  -584.93), SIMDE_FLOAT32_C(   751.31) },
      { SIMDE_FLOAT32_C(  -621.83), SIMDE_FLOAT32_C(  -845.50), SIMDE_FLOAT32_C(  -772.50), SIMDE_FLOAT32_C(   -68.10) },
      { SIMDE_FLOAT32_C(  -230.31), SIMDE_FLOAT32_C(  -477.34), SIMDE_FLOAT32_C(  -584.93), SIMDE_FLOAT32_C(   751.31) } },
    { { SIMDE_FLOAT32_C(  -267.52), SIMDE_FLOAT32_C(   333.13), SIMDE_FLOAT32_C(    46.43), SIMDE_FLOAT32_C(   -67.25) },
      { SIMDE_FLOAT32_C(   438.64), SIMDE_FLOAT32_C(  -547.09), SIMDE_FLOAT32_C(  -596.12), SIMDE_FLOAT32_C(   998.23) },
      { SIMDE_FLOAT32_C(   438.64), SIMDE_FLOAT32_C(   333.13), SIMDE_FLOAT32_C(    46.43), SIMDE_FLOAT32_C(   998.23) } },
    { { SIMDE_FLOAT32_C(  -272.56), SIMDE_FLOAT32_C(   292.73), SIMDE_FLOAT32_C(   218.86), SIMDE_FLOAT32_C(   915.36) },
      { SIMDE_FLOAT32_C(  -710.44), SIMDE_FLOAT32_C(  -916.07), SIMDE_FLOAT32_C(   162.80), SIMDE_FLOAT32_C(   500.43) },
      { SIMDE_FLOAT32_C(  -272.56), SIMDE_FLOAT32_C(   292.73), SIMDE_FLOAT32_C(   218.86), SIMDE_FLOAT32_C(   915.36) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_float32x4_t b = simde_vld1q_f32(test_vec[i].b);
    simde_float32x4_t r = simde_vmaxq_f32(a, b);

    simde_test_arm_neon_assert_equal_f32x4(r, simde_vld1q_f32(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  simde_float32_t values[8 * 2 * sizeof(simde_float32x4_t)];
  simde_test_arm_neon_random_f32x4_full(8, 2, values, -1000.0f, 1000.0f, SIMDE_TEST_VEC_FLOAT_NAN | SIMDE_TEST_VEC_FLOAT_EQUAL);

  for (size_t i = 0 ; i < 8 ; i++) {
    simde_float32x4_t a = simde_test_arm_neon_random_extract_f32x4(i, 2, 0, values);
    simde_float32x4_t b = simde_test_arm_neon_random_extract_f32x4(i, 2, 1, values);
    simde_float32x4_t r = simde_vmaxq_f32(a, b);

    simde_test_arm_neon_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmaxq_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 a[2];
    simde_float64 b[2];
    simde_float64 r[2];
  } test_vec[] = {
    #if !defined(SIMDE_FAST_NANS)
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   768.08) },
      { SIMDE_FLOAT64_C(  -167.25),             SIMDE_MATH_NAN },
      {             SIMDE_MATH_NAN,             SIMDE_MATH_NAN } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   381.84) },
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   381.84) },
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   381.84) } },
    #endif
    { { SIMDE_FLOAT64_C(  -692.58), SIMDE_FLOAT64_C(  -923.20) },
      { SIMDE_FLOAT64_C(   794.72), SIMDE_FLOAT64_C(  -538.08) },
      { SIMDE_FLOAT64_C(   794.72), SIMDE_FLOAT64_C(  -538.08) } },
    { { SIMDE_FLOAT64_C(  -695.71), SIMDE_FLOAT64_C(  -273.38) },
      { SIMDE_FLOAT64_C(   194.40), SIMDE_FLOAT64_C(   637.43) },
      { SIMDE_FLOAT64_C(   194.40), SIMDE_FLOAT64_C(   637.43) } },
    { { SIMDE_FLOAT64_C(   773.05), SIMDE_FLOAT64_C(  -872.85) },
      { SIMDE_FLOAT64_C(    76.07), SIMDE_FLOAT64_C(  -774.04) },
      { SIMDE_FLOAT64_C(   773.05), SIMDE_FLOAT64_C(  -774.04) } },
    { { SIMDE_FLOAT64_C(  -468.97), SIMDE_FLOAT64_C(    74.30) },
      { SIMDE_FLOAT64_C(   -46.60), SIMDE_FLOAT64_C(   823.76) },
      { SIMDE_FLOAT64_C(   -46.60), SIMDE_FLOAT64_C(   823.76) } },
    { { SIMDE_FLOAT64_C(  -706.84), SIMDE_FLOAT64_C(  -131.24) },
      { SIMDE_FLOAT64_C(  -886.68), SIMDE_FLOAT64_C(  -622.90) },
      { SIMDE_FLOAT64_C(  -706.84), SIMDE_FLOAT64_C(  -131.24) } },
    { { SIMDE_FLOAT64_C(  -968.44), SIMDE_FLOAT64_C(   613.76) },
      { SIMDE_FLOAT64_C(  -385.13), SIMDE_FLOAT64_C(  -337.18) },
      { SIMDE_FLOAT64_C(  -385.13), SIMDE_FLOAT64_C(   613.76) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2_t a = simde_vld1q_f64(test_vec[i].a);
    simde_float64x2_t b = simde_vld1q_f64(test_vec[i].b);
    simde_float64x2_t r = simde_vmaxq_f64(a, b);

    simde_test_arm_neon_assert_equal_f64x2(r, simde_vld1q_f64(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  simde_float64_t values[8 * 2 * sizeof(simde_float64x2_t)];
  simde_test_arm_neon_random_f64x2_full(8, 2, values, -1000.0, 1000.0, SIMDE_TEST_VEC_FLOAT_NAN | SIMDE_TEST_VEC_FLOAT_EQUAL);

  for (size_t i = 0 ; i < 8 ; i++) {
    simde_float64x2_t a = simde_test_arm_neon_random_extract_f64x2(i, 2, 0, values);
    simde_float64x2_t b = simde_test_arm_neon_random_extract_f64x2(i, 2, 1, values);
    simde_float64x2_t r = simde_vmaxq_f64(a, b);

    simde_test_arm_neon_write_f64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmaxq_s8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int8_t a[16];
    int8_t b[16];
    int8_t r[16];
  } test_vec[] = {
    { {  INT8_C(  97), -INT8_C(  30),      INT8_MAX,  INT8_C(  21),  INT8_C(  44),  INT8_C( 108),  INT8_C(  50),  INT8_C(   2),
         INT8_C(  55), -INT8_C(  33), -INT8_C( 124),  INT8_C(   5), -INT8_C(  27), -INT8_C( 127), -INT8_C(  60),  INT8_C( 103) },
      { -INT8_C(  19),  INT8_C(  86), -INT8_C(   5),  INT8_C(  21),  INT8_C( 117),  INT8_C(  89), -INT8_C(  90), -INT8_C( 125),
         INT8_C(  56),  INT8_C(  10),  INT8_C(  98), -INT8_C(  72), -INT8_C(  16), -INT8_C(  97),  INT8_C(  26),  INT8_C(  81) },
      {  INT8_C(  97),  INT8_C(  86),      INT8_MAX,  INT8_C(  21),  INT8_C( 117),  INT8_C( 108),  INT8_C(  50),  INT8_C(   2),
         INT8_C(  56),  INT8_C(  10),  INT8_C(  98),  INT8_C(   5), -INT8_C(  16), -INT8_C(  97),  INT8_C(  26),  INT8_C( 103) } },
    { { -INT8_C( 126), -INT8_C( 103),  INT8_C( 103), -INT8_C(  82),  INT8_C(   5), -INT8_C( 103), -INT8_C(  80),  INT8_C(  61),
         INT8_C( 121),  INT8_C(  52),  INT8_C(  66),  INT8_C(  94), -INT8_C(  74),  INT8_C(   7), -INT8_C(  58), -INT8_C(  93) },
      {  INT8_C(  93), -INT8_C(  63), -INT8_C(  72), -INT8_C(  46),  INT8_C(  26),  INT8_C(  94),  INT8_C(  86),  INT8_C(  83),
         INT8_C( 105), -INT8_C(  72),  INT8_C(  11),  INT8_C(  89),  INT8_C(  88),  INT8_C(  37), -INT8_C(  86), -INT8_C(  38) },
      {  INT8_C(  93), -INT8_C(  63),  INT8_C( 103), -INT8_C(  46),  INT8_C(  26),  INT8_C(  94),  INT8_C(  86),  INT8_C(  83),
         INT8_C( 121),  INT8_C(  52),  INT8_C(  66),  INT8_C(  94),  INT8_C(  88),  INT8_C(  37), -INT8_C(  58), -INT8_C(  38) } },
    { { -INT8_C(  65),  INT8_C(  17), -INT8_C( 120), -INT8_C(  60), -INT8_C(  85),  INT8_C(  56),  INT8_C(   1),  INT8_C(  36),
         INT8_C( 108),  INT8_C(  68), -INT8_C( 126),  INT8_C(  34),  INT8_C(  75),  INT8_C(  72), -INT8_C(  59), -INT8_C(  88) },
      {  INT8_C(  10),  INT8_C( 125),  INT8_C( 123),  INT8_C(  36), -INT8_C(  36), -INT8_C(  47),  INT8_C( 119),  INT8_C(  69),
        -INT8_C( 119), -INT8_C( 126), -INT8_C(  98), -INT8_C(  31), -INT8_C(  88),  INT8_C(  72), -INT8_C(  69),  INT8_C( 103) },
      {  INT8_C(  10),  INT8_C( 125),  INT8_C( 123),  INT8_C(  36), -INT8_C(  36),  INT8_C(  56),  INT8_C( 119),  INT8_C(  69),
         INT8_C( 108),  INT8_C(  68), -INT8_C(  98),  INT8_C(  34),  INT8_C(  75),  INT8_C(  72), -INT8_C(  59),  INT8_C( 103) } },
    { {  INT8_C(  90),  INT8_C(  67),  INT8_C(  43),  INT8_C(   5),  INT8_C( 123),  INT8_C(  45),  INT8_C(  41), -INT8_C(  24),
         INT8_C( 113), -INT8_C(  85),  INT8_C(  10), -INT8_C(  68), -INT8_C(  12), -INT8_C(  48),  INT8_C( 100), -INT8_C(   2) },
      {  INT8_C(  77), -INT8_C(  33),  INT8_C(  34),  INT8_C(  41), -INT8_C(  80), -INT8_C( 102),  INT8_C( 110),  INT8_C(  58),
         INT8_C(  28),  INT8_C(  12),  INT8_C(  27), -INT8_C(  60),  INT8_C(  85), -INT8_C(  41),  INT8_C(  43), -INT8_C(  81) },
      {  INT8_C(  90),  INT8_C(  67),  INT8_C(  43),  INT8_C(  41),  INT8_C( 123),  INT8_C(  45),  INT8_C( 110),  INT8_C(  58),
         INT8_C( 113),  INT8_C(  12),  INT8_C(  27), -INT8_C(  60),  INT8_C(  85), -INT8_C(  41),  INT8_C( 100), -INT8_C(   2) } },
    { {  INT8_C(  26),  INT8_C(  87), -INT8_C(  76), -INT8_C( 106), -INT8_C( 124), -INT8_C(  35),  INT8_C( 126), -INT8_C(  11),
        -INT8_C( 120), -INT8_C( 120), -INT8_C(  79),  INT8_C( 124),  INT8_C(  88),  INT8_C(  21),  INT8_C( 122), -INT8_C(  90) },
      { -INT8_C(  11), -INT8_C(  99), -INT8_C(  49), -INT8_C(  91),  INT8_C(  55),  INT8_C(  62), -INT8_C(  33),  INT8_C(  83),
         INT8_C(  74), -INT8_C(   5),  INT8_C(  24), -INT8_C(  97), -INT8_C(  46),  INT8_C(  67),  INT8_C(  78), -INT8_C(  20) },
      {  INT8_C(  26),  INT8_C(  87), -INT8_C(  49), -INT8_C(  91),  INT8_C(  55),  INT8_C(  62),  INT8_C( 126),  INT8_C(  83),
         INT8_C(  74), -INT8_C(   5),  INT8_C(  24),  INT8_C( 124),  INT8_C(  88),  INT8_C(  67),  INT8_C( 122), -INT8_C(  20) } },
    { { -INT8_C( 102),  INT8_C(   2), -INT8_C( 126),  INT8_C(  30), -INT8_C(  33),  INT8_C(   0),  INT8_C(  19),  INT8_C( 104),
        -INT8_C( 119), -INT8_C(  60), -INT8_C(  28), -INT8_C(  31), -INT8_C(  38),  INT8_C(  95), -INT8_C( 121), -INT8_C(  49) },
      { -INT8_C(   4),  INT8_C(  87),  INT8_C( 116),  INT8_C(  51), -INT8_C( 107),  INT8_C(  84), -INT8_C( 122), -INT8_C(  33),
         INT8_C(  79), -INT8_C(  98),      INT8_MAX,  INT8_C(  33), -INT8_C(  30), -INT8_C(  51),  INT8_C(  13),  INT8_C( 124) },
      { -INT8_C(   4),  INT8_C(  87),  INT8_C( 116),  INT8_C(  51), -INT8_C(  33),  INT8_C(  84),  INT8_C(  19),  INT8_C( 104),
         INT8_C(  79), -INT8_C(  60),      INT8_MAX,  INT8_C(  33), -INT8_C(  30),  INT8_C(  95),  INT8_C(  13),  INT8_C( 124) } },
    { { -INT8_C(  48), -INT8_C( 112), -INT8_C( 101), -INT8_C(  81), -INT8_C( 112), -INT8_C(  82),  INT8_C(  23),  INT8_C(  25),
         INT8_C( 115), -INT8_C(   4), -INT8_C(   5),  INT8_C(  77),  INT8_C(  91), -INT8_C( 126),  INT8_C(  28),  INT8_C(  87) },
      { -INT8_C(  39), -INT8_C( 112), -INT8_C( 118),  INT8_C( 110), -INT8_C(  28),  INT8_C(  16),  INT8_C(  78),  INT8_C(  51),
        -INT8_C(  81), -INT8_C(  51),  INT8_C(  84), -INT8_C( 111), -INT8_C( 102),  INT8_C(  98),  INT8_C(  13),  INT8_C( 106) },
      { -INT8_C(  39), -INT8_C( 112), -INT8_C( 101),  INT8_C( 110), -INT8_C(  28),  INT8_C(  16),  INT8_C(  78),  INT8_C(  51),
         INT8_C( 115), -INT8_C(   4),  INT8_C(  84),  INT8_C(  77),  INT8_C(  91),  INT8_C(  98),  INT8_C(  28),  INT8_C( 106) } },
    { { -INT8_C(  14), -INT8_C(  88),  INT8_C(  26), -INT8_C( 126),  INT8_C(  87),  INT8_C(  49), -INT8_C( 100), -INT8_C(  54),
         INT8_C(  45), -INT8_C( 105),  INT8_C(  23), -INT8_C( 120),  INT8_C(  25),  INT8_C(  51), -INT8_C(  33), -INT8_C(  13) },
      { -INT8_C(  61),  INT8_C( 105),  INT8_C(  97), -INT8_C(  88),  INT8_C( 122), -INT8_C(  81), -INT8_C(  37),  INT8_C(  41),
         INT8_C( 124),  INT8_C(  48), -INT8_C(  70),  INT8_C(  23), -INT8_C( 110), -INT8_C(  57), -INT8_C( 127), -INT8_C( 124) },
      { -INT8_C(  14),  INT8_C( 105),  INT8_C(  97), -INT8_C(  88),  INT8_C( 122),  INT8_C(  49), -INT8_C(  37),  INT8_C(  41),
         INT8_C( 124),  INT8_C(  48),  INT8_C(  23),  INT8_C(  23),  INT8_C(  25),  INT8_C(  51), -INT8_C(  33), -INT8_C(  13) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16_t a = simde_vld1q_s8(test_vec[i].a);
    simde_int8x16_t b = simde_vld1q_s8(test_vec[i].b);
    simde_int8x16_t r = simde_vmaxq_s8(a, b);

    simde_test_arm_neon_assert_equal_i8x16(r, simde_vld1q_s8(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vmaxq_s16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int16_t a[8];
    int16_t b[8];
    int16_t r[8];
  } test_vec[] = {
    { {  INT16_C(  1220), -INT16_C( 22125), -INT16_C( 32646), -INT16_C( 13267), -INT16_C( 32228), -INT16_C( 13457), -INT16_C( 19765),  INT16_C( 29048) },
      {  INT16_C(  6582),  INT16_C( 20054),  INT16_C( 14723),  INT16_C(   901), -INT16_C( 14824), -INT16_C( 28104), -INT16_C( 12360),  INT16_C( 31915) },
      {  INT16_C(  6582),  INT16_C( 20054),  INT16_C( 14723),  INT16_C(   901), -INT16_C( 14824), -INT16_C( 13457), -INT16_C( 12360),  INT16_C( 31915) } },
    { {  INT16_C( 16083),  INT16_C( 20005),  INT16_C( 21182), -INT16_C(  9446), -INT16_C( 30251), -INT16_C( 24410),  INT16_C(  7740), -INT16_C(  3566) },
      {  INT16_C( 26679), -INT16_C( 17856), -INT16_C( 14942), -INT16_C( 17731), -INT16_C(  2677),  INT16_C( 17229), -INT16_C(  1852), -INT16_C( 26689) },
      {  INT16_C( 26679),  INT16_C( 20005),  INT16_C( 21182), -INT16_C(  9446), -INT16_C(  2677),  INT16_C( 17229),  INT16_C(  7740), -INT16_C(  3566) } },
    { { -INT16_C(  6858), -INT16_C(  2587), -INT16_C(   201),  INT16_C(  3280),  INT16_C( 30345), -INT16_C( 14931), -INT16_C( 16492), -INT16_C( 13385) },
      { -INT16_C(  2265), -INT16_C( 13947),  INT16_C( 17084),  INT16_C( 18308), -INT16_C( 11977), -INT16_C(  1141),  INT16_C( 19145), -INT16_C(   110) },
      { -INT16_C(  2265), -INT16_C(  2587),  INT16_C( 17084),  INT16_C( 18308),  INT16_C( 30345), -INT16_C(  1141),  INT16_C( 19145), -INT16_C(   110) } },
    { {  INT16_C( 30767),  INT16_C( 26612), -INT16_C( 15241),  INT16_C(   115),  INT16_C(  8250), -INT16_C( 12603),  INT16_C( 31967),  INT16_C(  1945) },
      {  INT16_C(  7795),  INT16_C( 12240),  INT16_C( 21600), -INT16_C( 26761),  INT16_C(   549), -INT16_C(  4462),  INT16_C(  9548),  INT16_C( 31982) },
      {  INT16_C( 30767),  INT16_C( 26612),  INT16_C( 21600),  INT16_C(   115),  INT16_C(  8250), -INT16_C(  4462),  INT16_C( 31967),  INT16_C( 31982) } },
    { { -INT16_C(  7523),  INT16_C(  5347),  INT16_C( 22183), -INT16_C(  7915), -INT16_C(  9609),  INT16_C( 22192),  INT16_C( 18775), -INT16_C( 13731) },
      {  INT16_C( 11880), -INT16_C( 14086),  INT16_C( 29058), -INT16_C( 22432), -INT16_C(  3469), -INT16_C( 16490), -INT16_C( 31721), -INT16_C( 19397) },
      {  INT16_C( 11880),  INT16_C(  5347),  INT16_C( 29058), -INT16_C(  7915), -INT16_C(  3469),  INT16_C( 22192),  INT16_C( 18775), -INT16_C( 13731) } },
    { {  INT16_C(  7783),  INT16_C(  3785), -INT16_C(  8587), -INT16_C(  4881), -INT16_C( 24648),  INT16_C(  3906), -INT16_C( 24343),  INT16_C( 20954) },
      { -INT16_C( 11058),  INT16_C( 20505),  INT16_C( 31045), -INT16_C( 18184), -INT16_C( 28820), -INT16_C( 31881), -INT16_C( 19693),  INT16_C( 31288) },
      {  INT16_C(  7783),  INT16_C( 20505),  INT16_C( 31045), -INT16_C(  4881), -INT16_C( 24648),  INT16_C(  3906), -INT16_C( 19693),  INT16_C( 31288) } },
    { {  INT16_C(   465),  INT16_C( 18056),  INT16_C( 30943), -INT16_C( 26830),  INT16_C( 29975),  INT16_C(   167), -INT16_C( 32491), -INT16_C(  7343) },
      {  INT16_C( 27477), -INT16_C( 26061),  INT16_C( 11492),  INT16_C( 20562), -INT16_C( 13893), -INT16_C( 12588),  INT16_C(  3196),  INT16_C( 20041) },
      {  INT16_C( 27477),  INT16_C( 18056),  INT16_C( 30943),  INT16_C( 20562),  INT16_C( 29975),  INT16_C(   167),  INT16_C(  3196),  INT16_C( 20041) } },
    { { -INT16_C( 12019), -INT16_C(  4972), -INT16_C( 14519),  INT16_C( 24963),  INT16_C( 10812),  INT16_C( 20833), -INT16_C( 19541),  INT16_C(    52) },
      {  INT16_C( 26398),  INT16_C(   666), -INT16_C(  4973),  INT16_C( 20051),  INT16_C( 10166),  INT16_C( 12829),  INT16_C( 26163),  INT16_C( 16512) },
      {  INT16_C( 26398),  INT16_C(   666), -INT16_C(  4973),  INT16_C( 24963),  INT16_C( 10812),  INT16_C( 20833),  INT16_C( 26163),  INT16_C( 16512) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_int16x8_t b = simde_vld1q_s16(test_vec[i].b);
    simde_int16x8_t r = simde_vmaxq_s16(a, b);

    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vmaxq_s32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int32_t a[4];
    int32_t b[4];
    int32_t r[4];
  } test_vec[] = {
    { {  INT32_C(   956970151),  INT32_C(  1495061858), -INT32_C(  1638694273), -INT32_C(   799373422) },
      { -INT32_C(  2022589331),  INT32_C(  1145242929), -INT32_C(   126744559),  INT32_C(   490486389) },
      {  INT32_C(   956970151),  INT32_C(  1495061858), -INT32_C(   126744559),  INT32_C(   490486389) } },
    { { -INT32_C(   799652242), -INT32_C(  1691782628), -INT32_C(  2026275339),  INT32_C(  1901630212) },
      { -INT32_C(  2131113649), -INT32_C(   523944753), -INT32_C(  1160235196), -INT32_C(   539552399) },
      { -INT32_C(   799652242), -INT32_C(   523944753), -INT32_C(  1160235196),  INT32_C(  1901630212) } },
    { {  INT32_C(  2007969115), -INT32_C(  1810703969),  INT32_C(  1511803734),  INT32_C(   785151198) },
      {  INT32_C(   212780349),  INT32_C(  1189966593),  INT32_C(   453035434),  INT32_C(   922408922) },
      {  INT32_C(  2007969115),  INT32_C(  1189966593),  INT32_C(  1511803734),  INT32_C(   922408922) } },
    { { -INT32_C(  1548899836), -INT32_C(   650592125), -INT32_C(   365734901),  INT32_C(    85524424) },
      { -INT32_C(   971847996), -INT32_C(   468910278), -INT32_C(  1627386684), -INT32_C(   405407005) },
      { -INT32_C(   971847996), -INT32_C(   468910278), -INT32_C(   365734901),  INT32_C(    85524424) } },
    { {  INT32_C(   663388836),  INT32_C(  1308672578), -INT32_C(   566741994), -INT32_C(   119254989) },
      {  INT32_C(  1354692118), -INT32_C(  1187656971), -INT32_C(  1185401386), -INT32_C(   727700177) },
      {  INT32_C(  1354692118),  INT32_C(  1308672578), -INT32_C(   566741994), -INT32_C(   119254989) } },
    { { -INT32_C(   218420560),  INT32_C(    54590701),  INT32_C(  1675786288), -INT32_C(   547633464) },
      { -INT32_C(  1322313284), -INT32_C(  1184209693), -INT32_C(   915225703), -INT32_C(  1600318736) },
      { -INT32_C(   218420560),  INT32_C(    54590701),  INT32_C(  1675786288), -INT32_C(   547633464) } },
    { {  INT32_C(   714315837), -INT32_C(  1003629676),  INT32_C(   338169676), -INT32_C(  1846311979) },
      { -INT32_C(  2143149155),  INT32_C(   557493639),  INT32_C(  1625992304), -INT32_C(    67008577) },
      {  INT32_C(   714315837),  INT32_C(   557493639),  INT32_C(  1625992304), -INT32_C(    67008577) } },
    { { -INT32_C(  1272540129), -INT32_C(  1283959961),  INT32_C(   952672355), -INT32_C(  1043678428) },
      {  INT32_C(  1715539166),  INT32_C(   696744889), -INT32_C(   410357464),  INT32_C(   400788472) },
      {  INT32_C(  1715539166),  INT32_C(   696744889),  INT32_C(   952672355),  INT32_C(   400788472) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int32x4_t b = simde_vld1q_s32(test_vec[i].b);
    simde_int32x4_t r = simde_vmaxq_s32(a, b);
    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_x_vmaxq_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a[2];
    int64_t b[2];
    int64_t r[2];
  } test_vec[] = {
    { { -INT64_C(   33951692342820127), -INT64_C( 7720064575400108197) },
      {  INT64_C( 6220286073678636896),  INT64_C( 8039000713994285934) },
      {  INT64_C( 6220286073678636896),  INT64_C( 8039000713994285934) } },
    { { -INT64_C( 5880692503022210489), -INT64_C( 4002460468684024139) },
      { -INT64_C( 5503582065510686705), -INT64_C( 1726331517560005364) },
      { -INT64_C( 5503582065510686705), -INT64_C( 1726331517560005364) } },
    { {  INT64_C( 7191034392361048265), -INT64_C( 3713860292413532603) },
      { -INT64_C( 2229363362547467241), -INT64_C(  748574811973987054) },
      {  INT64_C( 7191034392361048265), -INT64_C(  748574811973987054) } },
    { { -INT64_C( 2400176054702315105), -INT64_C( 4486709295076084942) },
      { -INT64_C( 7335469304539917699), -INT64_C( 2980279904009015166) },
      { -INT64_C( 2400176054702315105), -INT64_C( 2980279904009015166) } },
    { { -INT64_C( 4302392772949396012),  INT64_C( 6067598668619634376) },
      {  INT64_C(  100725705291485507),  INT64_C( 8329217981442667657) },
      {  INT64_C(  100725705291485507),  INT64_C( 8329217981442667657) } },
    { {  INT64_C( 6295234650384087816), -INT64_C( 4239014786319642368) },
      {  INT64_C( 3805530324110201167), -INT64_C( 2757456615845888343) },
      {  INT64_C( 6295234650384087816), -INT64_C( 2757456615845888343) } },
    { { -INT64_C( 4238502126160733370),  INT64_C( 4983734319431088098) },
      {  INT64_C( 6374531560650291608),  INT64_C( 4398711673538505568) },
      {  INT64_C( 6374531560650291608),  INT64_C( 4983734319431088098) } },
    { {  INT64_C( 3567203091056131831),  INT64_C( 8967439695274646840) },
      { -INT64_C( 3999982176903985801),  INT64_C( 8201905370448928416) },
      {  INT64_C( 3567203091056131831),  INT64_C( 8967439695274646840) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);
    simde_int64x2_t b = simde_vld1q_s64(test_vec[i].b);
    simde_int64x2_t r = simde_x_vmaxq_s64(a, b);
    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int64x2_t a = simde_test_arm_neon_random_i64x2();
    simde_int64x2_t b = simde_test_arm_neon_random_i64x2();
    simde_int64x2_t r = simde_x_vmaxq_s64(a, b);

    simde_test_arm_neon_write_i64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmaxq_u8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint8_t a[16];
    uint8_t b[16];
    uint8_t r[16];
  } test_vec[] = {
    { { UINT8_C(193), UINT8_C(134), UINT8_C(245), UINT8_C(103), UINT8_C( 63), UINT8_C(110), UINT8_C(101), UINT8_C(105),
        UINT8_C(153), UINT8_C(168), UINT8_C(252), UINT8_C( 55), UINT8_C(169), UINT8_C( 51), UINT8_C( 20), UINT8_C(236) },
      { UINT8_C(108), UINT8_C(201), UINT8_C(165), UINT8_C( 52), UINT8_C( 23), UINT8_C(179), UINT8_C( 17), UINT8_C(122),
        UINT8_C( 19), UINT8_C(  8), UINT8_C(137), UINT8_C(214), UINT8_C(156), UINT8_C(140), UINT8_C( 45), UINT8_C( 93) },
      { UINT8_C(193), UINT8_C(201), UINT8_C(245), UINT8_C(103), UINT8_C( 63), UINT8_C(179), UINT8_C(101), UINT8_C(122),
        UINT8_C(153), UINT8_C(168), UINT8_C(252), UINT8_C(214), UINT8_C(169), UINT8_C(140), UINT8_C( 45), UINT8_C(236) } },
    { { UINT8_C( 19), UINT8_C( 34), UINT8_C(197), UINT8_C( 82), UINT8_C(144), UINT8_C( 42), UINT8_C(187), UINT8_C( 42),
        UINT8_C(210), UINT8_C(183), UINT8_C( 97), UINT8_C(124), UINT8_C(235), UINT8_C(117), UINT8_C(104), UINT8_C( 87) },
      { UINT8_C( 63), UINT8_C( 13), UINT8_C(140), UINT8_C( 86), UINT8_C(192), UINT8_C(157), UINT8_C(208), UINT8_C(211),
        UINT8_C(165), UINT8_C( 89), UINT8_C(169), UINT8_C( 66), UINT8_C(230), UINT8_C(215), UINT8_C(159), UINT8_C(249) },
      { UINT8_C( 63), UINT8_C( 34), UINT8_C(197), UINT8_C( 86), UINT8_C(192), UINT8_C(157), UINT8_C(208), UINT8_C(211),
        UINT8_C(210), UINT8_C(183), UINT8_C(169), UINT8_C(124), UINT8_C(235), UINT8_C(215), UINT8_C(159), UINT8_C(249) } },
    { { UINT8_C(249), UINT8_C(100), UINT8_C( 75), UINT8_C(138), UINT8_C(143), UINT8_C(  6), UINT8_C(180), UINT8_C( 97),
        UINT8_C(189), UINT8_C( 21), UINT8_C(221), UINT8_C(168), UINT8_C(139), UINT8_C( 70), UINT8_C(  0), UINT8_C(202) },
      { UINT8_C( 83), UINT8_C(140), UINT8_C( 32), UINT8_C( 20), UINT8_C( 41), UINT8_C(240), UINT8_C(231), UINT8_C(206),
        UINT8_C( 73), UINT8_C(145), UINT8_C( 16), UINT8_C( 47), UINT8_C(104), UINT8_C(176), UINT8_C( 40), UINT8_C( 97) },
      { UINT8_C(249), UINT8_C(140), UINT8_C( 75), UINT8_C(138), UINT8_C(143), UINT8_C(240), UINT8_C(231), UINT8_C(206),
        UINT8_C(189), UINT8_C(145), UINT8_C(221), UINT8_C(168), UINT8_C(139), UINT8_C(176), UINT8_C( 40), UINT8_C(202) } },
    { { UINT8_C( 20), UINT8_C(115), UINT8_C(235), UINT8_C(163), UINT8_C(121), UINT8_C(159), UINT8_C(  5), UINT8_C( 55),
        UINT8_C(181), UINT8_C(226), UINT8_C(223), UINT8_C( 64), UINT8_C( 40), UINT8_C(223), UINT8_C( 10), UINT8_C(124) },
      { UINT8_C(107), UINT8_C( 42), UINT8_C(144), UINT8_C(148), UINT8_C( 26), UINT8_C(119), UINT8_C( 99), UINT8_C( 99),
        UINT8_C(  8), UINT8_C(115), UINT8_C(147), UINT8_C(112), UINT8_C( 35), UINT8_C(187), UINT8_C(210), UINT8_C( 56) },
      { UINT8_C(107), UINT8_C(115), UINT8_C(235), UINT8_C(163), UINT8_C(121), UINT8_C(159), UINT8_C( 99), UINT8_C( 99),
        UINT8_C(181), UINT8_C(226), UINT8_C(223), UINT8_C(112), UINT8_C( 40), UINT8_C(223), UINT8_C(210), UINT8_C(124) } },
    { { UINT8_C( 47), UINT8_C(189), UINT8_C(219), UINT8_C(168), UINT8_C( 93), UINT8_C(224), UINT8_C(223), UINT8_C( 18),
        UINT8_C(195), UINT8_C(191), UINT8_C( 82), UINT8_C(235), UINT8_C(158), UINT8_C( 92), UINT8_C(103), UINT8_C( 10) },
      { UINT8_C(134), UINT8_C(247), UINT8_C(158), UINT8_C(160), UINT8_C(111), UINT8_C(  1), UINT8_C(  3), UINT8_C(119),
        UINT8_C(117), UINT8_C(150), UINT8_C(232), UINT8_C(152), UINT8_C( 82), UINT8_C(186), UINT8_C(208), UINT8_C(129) },
      { UINT8_C(134), UINT8_C(247), UINT8_C(219), UINT8_C(168), UINT8_C(111), UINT8_C(224), UINT8_C(223), UINT8_C(119),
        UINT8_C(195), UINT8_C(191), UINT8_C(232), UINT8_C(235), UINT8_C(158), UINT8_C(186), UINT8_C(208), UINT8_C(129) } },
    { { UINT8_C(119), UINT8_C(172), UINT8_C( 41), UINT8_C(212), UINT8_C(140), UINT8_C(  9), UINT8_C(230), UINT8_C( 79),
        UINT8_C(200), UINT8_C( 56), UINT8_C( 59), UINT8_C(102), UINT8_C(148), UINT8_C(162), UINT8_C(112), UINT8_C( 26) },
      { UINT8_C(154), UINT8_C( 15), UINT8_C(186), UINT8_C(  9), UINT8_C( 16), UINT8_C(190), UINT8_C(128), UINT8_C(133),
        UINT8_C( 84), UINT8_C(104), UINT8_C( 30), UINT8_C(166), UINT8_C( 34), UINT8_C(238), UINT8_C( 39), UINT8_C(154) },
      { UINT8_C(154), UINT8_C(172), UINT8_C(186), UINT8_C(212), UINT8_C(140), UINT8_C(190), UINT8_C(230), UINT8_C(133),
        UINT8_C(200), UINT8_C(104), UINT8_C( 59), UINT8_C(166), UINT8_C(148), UINT8_C(238), UINT8_C(112), UINT8_C(154) } },
    { { UINT8_C(154), UINT8_C( 81), UINT8_C(110), UINT8_C( 39), UINT8_C( 90), UINT8_C( 85), UINT8_C(118), UINT8_C( 34),
        UINT8_C(141), UINT8_C(177), UINT8_C(136), UINT8_C( 34), UINT8_C( 84), UINT8_C(249), UINT8_C( 60), UINT8_C(238) },
      { UINT8_C(  8), UINT8_C(247), UINT8_C(247), UINT8_C( 24), UINT8_C(181), UINT8_C(119), UINT8_C(158), UINT8_C(  9),
        UINT8_C(224), UINT8_C(188), UINT8_C(176), UINT8_C(  2), UINT8_C(170), UINT8_C(215), UINT8_C(156), UINT8_C( 69) },
      { UINT8_C(154), UINT8_C(247), UINT8_C(247), UINT8_C( 39), UINT8_C(181), UINT8_C(119), UINT8_C(158), UINT8_C( 34),
        UINT8_C(224), UINT8_C(188), UINT8_C(176), UINT8_C( 34), UINT8_C(170), UINT8_C(249), UINT8_C(156), UINT8_C(238) } },
    { { UINT8_C( 40), UINT8_C( 11), UINT8_C(108), UINT8_C(130), UINT8_C( 96), UINT8_C(226), UINT8_C(164), UINT8_C(237),
        UINT8_C(148), UINT8_C( 45), UINT8_C( 15), UINT8_C(232), UINT8_C( 38), UINT8_C( 76), UINT8_C(214), UINT8_C( 46) },
      { UINT8_C( 67), UINT8_C(205), UINT8_C( 70), UINT8_C(248), UINT8_C( 68), UINT8_C(228), UINT8_C(  1), UINT8_C( 36),
        UINT8_C(160), UINT8_C(177), UINT8_C( 39), UINT8_C( 75), UINT8_C(137), UINT8_C(195), UINT8_C(144), UINT8_C(177) },
      { UINT8_C( 67), UINT8_C(205), UINT8_C(108), UINT8_C(248), UINT8_C( 96), UINT8_C(228), UINT8_C(164), UINT8_C(237),
        UINT8_C(160), UINT8_C(177), UINT8_C( 39), UINT8_C(232), UINT8_C(137), UINT8_C(195), UINT8_C(214), UINT8_C(177) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x16_t a = simde_vld1q_u8(test_vec[i].a);
    simde_uint8x16_t b = simde_vld1q_u8(test_vec[i].b);
    simde_uint8x16_t r = simde_vmaxq_u8(a, b);

    simde_test_arm_neon_assert_equal_u8x16(r, simde_vld1q_u8(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vmaxq_u16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint16_t a[8];
    uint16_t b[8];
    uint16_t r[8];
  } test_vec[] = {
    { { UINT16_C(50452), UINT16_C( 9264), UINT16_C(54520), UINT16_C(64366), UINT16_C(34356), UINT16_C(54346), UINT16_C(24327), UINT16_C(47384) },
      { UINT16_C( 3239), UINT16_C(45245), UINT16_C(36184), UINT16_C(56734), UINT16_C(55033), UINT16_C(39946), UINT16_C(26299), UINT16_C(53086) },
      { UINT16_C(50452), UINT16_C(45245), UINT16_C(54520), UINT16_C(64366), UINT16_C(55033), UINT16_C(54346), UINT16_C(26299), UINT16_C(53086) } },
    { { UINT16_C(36651), UINT16_C( 9203), UINT16_C(24931), UINT16_C(38687), UINT16_C(27111), UINT16_C(61035), UINT16_C(33736), UINT16_C(28584) },
      { UINT16_C(26000), UINT16_C(59423), UINT16_C(48626), UINT16_C(60357), UINT16_C(53395), UINT16_C(20103), UINT16_C(58934), UINT16_C(24862) },
      { UINT16_C(36651), UINT16_C(59423), UINT16_C(48626), UINT16_C(60357), UINT16_C(53395), UINT16_C(61035), UINT16_C(58934), UINT16_C(28584) } },
    { { UINT16_C( 4469), UINT16_C(55429), UINT16_C(42099), UINT16_C(23151), UINT16_C(55821), UINT16_C(54601), UINT16_C(61790), UINT16_C(60996) },
      { UINT16_C(25686), UINT16_C(18902), UINT16_C(39713), UINT16_C(46388), UINT16_C(48235), UINT16_C(41219), UINT16_C( 8610), UINT16_C( 5891) },
      { UINT16_C(25686), UINT16_C(55429), UINT16_C(42099), UINT16_C(46388), UINT16_C(55821), UINT16_C(54601), UINT16_C(61790), UINT16_C(60996) } },
    { { UINT16_C(34867), UINT16_C(42735), UINT16_C(24108), UINT16_C(14592), UINT16_C(18744), UINT16_C(38414), UINT16_C(21050), UINT16_C(37252) },
      { UINT16_C(23222), UINT16_C(55514), UINT16_C( 3830), UINT16_C(24973), UINT16_C(37066), UINT16_C(27651), UINT16_C( 1714), UINT16_C(58755) },
      { UINT16_C(34867), UINT16_C(55514), UINT16_C(24108), UINT16_C(24973), UINT16_C(37066), UINT16_C(38414), UINT16_C(21050), UINT16_C(58755) } },
    { { UINT16_C(29326), UINT16_C(47755), UINT16_C(35792), UINT16_C( 2547), UINT16_C(  469), UINT16_C( 3999), UINT16_C( 9299), UINT16_C( 2720) },
      { UINT16_C(31358), UINT16_C(29922), UINT16_C(28553), UINT16_C(21462), UINT16_C(55807), UINT16_C(45504), UINT16_C(17375), UINT16_C(28054) },
      { UINT16_C(31358), UINT16_C(47755), UINT16_C(35792), UINT16_C(21462), UINT16_C(55807), UINT16_C(45504), UINT16_C(17375), UINT16_C(28054) } },
    { { UINT16_C( 8630), UINT16_C(34343), UINT16_C( 6829), UINT16_C(33423), UINT16_C(12059), UINT16_C(28305), UINT16_C(12883), UINT16_C(53624) },
      { UINT16_C(23212), UINT16_C(13638), UINT16_C( 7369), UINT16_C(51593), UINT16_C(18933), UINT16_C(54394), UINT16_C( 4492), UINT16_C(16961) },
      { UINT16_C(23212), UINT16_C(34343), UINT16_C( 7369), UINT16_C(51593), UINT16_C(18933), UINT16_C(54394), UINT16_C(12883), UINT16_C(53624) } },
    { { UINT16_C(26674), UINT16_C(57289), UINT16_C(22658), UINT16_C(40289), UINT16_C(62343), UINT16_C(55819), UINT16_C(33829), UINT16_C(53676) },
      { UINT16_C(62174), UINT16_C(43015), UINT16_C(36878), UINT16_C(  881), UINT16_C(60377), UINT16_C(26071), UINT16_C( 6396), UINT16_C(12200) },
      { UINT16_C(62174), UINT16_C(57289), UINT16_C(36878), UINT16_C(40289), UINT16_C(62343), UINT16_C(55819), UINT16_C(33829), UINT16_C(53676) } },
    { { UINT16_C(29056), UINT16_C(  526), UINT16_C(28873), UINT16_C(20895), UINT16_C(43619), UINT16_C(34859), UINT16_C(55086), UINT16_C( 3417) },
      { UINT16_C(24777), UINT16_C(55221), UINT16_C( 9968), UINT16_C(51674), UINT16_C(45329), UINT16_C( 3631), UINT16_C(55241), UINT16_C(18749) },
      { UINT16_C(29056), UINT16_C(55221), UINT16_C(28873), UINT16_C(51674), UINT16_C(45329), UINT16_C(34859), UINT16_C(55241), UINT16_C(18749) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);
    simde_uint16x8_t b = simde_vld1q_u16(test_vec[i].b);
    simde_uint16x8_t r = simde_vmaxq_u16(a, b);
    simde_test_arm_neon_assert_equal_u16x8(r, simde_vld1q_u16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vmaxq_u32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint32_t a[4];
    uint32_t b[4];
    uint32_t r[4];
  } test_vec[] = {
    { { UINT32_C(3972880476), UINT32_C(3349222332), UINT32_C(1208741539), UINT32_C(2054709649) },
      { UINT32_C(1463202863), UINT32_C( 122068155), UINT32_C(1032132178), UINT32_C(1387139574) },
      { UINT32_C(3972880476), UINT32_C(3349222332), UINT32_C(1208741539), UINT32_C(2054709649) } },
    { { UINT32_C( 641629290), UINT32_C( 854515599), UINT32_C(1585117645), UINT32_C(2329473627) },
      { UINT32_C(1658916775), UINT32_C(4268304555), UINT32_C( 876342846), UINT32_C(1787226624) },
      { UINT32_C(1658916775), UINT32_C(4268304555), UINT32_C(1585117645), UINT32_C(2329473627) } },
    { { UINT32_C(4119905382), UINT32_C(1881636515), UINT32_C(3553534328), UINT32_C( 995993236) },
      { UINT32_C(1637695157), UINT32_C(2757690982), UINT32_C(4124613365), UINT32_C(3932118660) },
      { UINT32_C(4119905382), UINT32_C(2757690982), UINT32_C(4124613365), UINT32_C(3932118660) } },
    { { UINT32_C(3319787298), UINT32_C(3862234734), UINT32_C(1018758056), UINT32_C(1601640106) },
      { UINT32_C(3149927508), UINT32_C( 257892122), UINT32_C(1040464058), UINT32_C(3106497430) },
      { UINT32_C(3319787298), UINT32_C(3862234734), UINT32_C(1040464058), UINT32_C(3106497430) } },
    { { UINT32_C(3246262355), UINT32_C(3081221135), UINT32_C(1643339959), UINT32_C(3401673334) },
      { UINT32_C(2558886270), UINT32_C(1537795489), UINT32_C(3013192733), UINT32_C(1668071952) },
      { UINT32_C(3246262355), UINT32_C(3081221135), UINT32_C(3013192733), UINT32_C(3401673334) } },
    { { UINT32_C(3659852747), UINT32_C(1452395423), UINT32_C(2713224235), UINT32_C(1818982894) },
      { UINT32_C(2600792570), UINT32_C(4093029590), UINT32_C(1772523609), UINT32_C( 499913554) },
      { UINT32_C(3659852747), UINT32_C(4093029590), UINT32_C(2713224235), UINT32_C(1818982894) } },
    { { UINT32_C(2650271998), UINT32_C(3874719931), UINT32_C(4203195148), UINT32_C( 526840356) },
      { UINT32_C(3116002275), UINT32_C(1890365719), UINT32_C(2480493377), UINT32_C(1689363814) },
      { UINT32_C(3116002275), UINT32_C(3874719931), UINT32_C(4203195148), UINT32_C(1689363814) } },
    { { UINT32_C(1342285973), UINT32_C(1027011633), UINT32_C(3292052896), UINT32_C(2481168048) },
      { UINT32_C( 558734857), UINT32_C(2425485647), UINT32_C(2988665676), UINT32_C(2786513936) },
      { UINT32_C(1342285973), UINT32_C(2425485647), UINT32_C(3292052896), UINT32_C(2786513936) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint32x4_t b = simde_vld1q_u32(test_vec[i].b);
    simde_uint32x4_t r = simde_vmaxq_u32(a, b);

    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_x_vmaxq_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a[2];
    uint64_t b[2];
    uint64_t r[2];
  } test_vec[] = {
    { { UINT64_C(15158458638266685330), UINT64_C(11373162734640344784) },
      { UINT64_C(11254475624222272126), UINT64_C(13246677659206409250) },
      { UINT64_C(15158458638266685330), UINT64_C(13246677659206409250) } },
    { { UINT64_C(11935278802667777023), UINT64_C(12261996856397501519) },
      { UINT64_C( 5374603228077767431), UINT64_C( 6207871613249367881) },
      { UINT64_C(11935278802667777023), UINT64_C(12261996856397501519) } },
    { { UINT64_C( 6444871015450700278), UINT64_C( 6643674033896814685) },
      { UINT64_C( 2936325922264346957), UINT64_C( 8451493433471055004) },
      { UINT64_C( 6444871015450700278), UINT64_C( 8451493433471055004) } },
    { { UINT64_C(10703279740501913382), UINT64_C(15013120455850422440) },
      { UINT64_C( 4091807906721542082), UINT64_C( 4804624042024460217) },
      { UINT64_C(10703279740501913382), UINT64_C(15013120455850422440) } },
    { { UINT64_C( 5093566360046464483), UINT64_C(16194272586954493035) },
      { UINT64_C(13916485725689283405), UINT64_C(11747542599416302761) },
      { UINT64_C(13916485725689283405), UINT64_C(16194272586954493035) } },
    { { UINT64_C(16103021188979980693), UINT64_C(12121027572017249593) },
      { UINT64_C(12346532623333570445), UINT64_C(10187556841831027198) },
      { UINT64_C(16103021188979980693), UINT64_C(12121027572017249593) } },
    { { UINT64_C(14142774575225642737), UINT64_C( 3096877429899793143) },
      { UINT64_C( 4302370569963211528), UINT64_C(10371326623864137064) },
      { UINT64_C(14142774575225642737), UINT64_C(10371326623864137064) } },
    { { UINT64_C(16197260828028022393), UINT64_C( 4329134842805674573) },
      { UINT64_C( 5994849569874564280), UINT64_C(18324481154154244896) },
      { UINT64_C(16197260828028022393), UINT64_C(18324481154154244896) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x2_t a = simde_vld1q_u64(test_vec[i].a);
    simde_uint64x2_t b = simde_vld1q_u64(test_vec[i].b);
    simde_uint64x2_t r = simde_x_vmaxq_u64(a, b);
    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint64x2_t a = simde_test_arm_neon_random_u64x2();
    simde_uint64x2_t b = simde_test_arm_neon_random_u64x2();
    simde_uint64x2_t r = simde_x_vmaxq_u64(a, b);

    simde_test_arm_neon_write_u64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vmax_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vmax_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vmax_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vmax_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmax_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(x_vmax_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vmax_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vmax_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmax_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(x_vmax_u64)

SIMDE_TEST_FUNC_LIST_ENTRY(vmaxq_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vmaxq_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vmaxq_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vmaxq_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmaxq_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(x_vmaxq_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vmaxq_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vmaxq_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmaxq_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(x_vmaxq_u64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
